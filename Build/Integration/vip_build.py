# -*- coding: utf-8 -*-
import argparse
import os
import sys


def upload_to_linux_path(project, vip_path, status, linux_path, workspace, linux_user, linux_ip):
    vip_pac_path = linux_path + "/work/vip_package/packages/"
    vip_bac_path = linux_path  + "/work/vip_package/backups/"
    package_name = str(vip_path).split("packages/")[1]
    os.chdir(workspace + "\work\VIP\Build\Integration")
    os.system("python pack.py %s" % status)
    os.system("python pack_boot.py %s" % status)
    os.system("copy Release\output\%s-Firmware.hex .\%s-Firmware.hex" % (status, status))
    os.system("zip -r %s upgrade.mcu %s-Firmware.hex upgrade_ms.mcu" % (package_name, status))

    map_name = "MCU_map.zip"
    os.system("copy .\..\..\BootManage\Build\output\BootManager\\f1km_sk_v3_bm.map f1km_sk_v3_bm.map")
    os.system("copy .\..\..\HSM\DemoHsm\Appl\\vHsm.map vHsm.map")
    os.system("copy .\..\output\FirmwareA\\f1km_sk_v3_ghs.map f1km_sk_v3_ghs_A.map")
    os.system("copy .\..\output\FirmwareB\\f1km_sk_v3_ghs.map f1km_sk_v3_ghs_B.map")
    os.system("zip -r %s f1km_sk_v3_bm.map vHsm.map f1km_sk_v3_ghs_A.map f1km_sk_v3_ghs_B.map" % map_name)
    os.system("scp %s %s@%s:%s" % (package_name, linux_user, linux_ip, vip_pac_path))
    os.system("scp %s %s@%s:%s" % (map_name, linux_user, linux_ip, vip_bac_path))

    os.chdir(workspace + "\work\VIP\Build\Integration\Release\output")
    vip_map_name = "VIP_Map.zip"
    os.system("zip -r %s map" % vip_map_name)
    os.system("scp %s %s@%s:%s" % (vip_map_name, linux_user, linux_ip, vip_pac_path))


def build_mcu(project, release_path, status, boot):
	os.chdir(release_path)
	if boot == "on":
		cmd = "call Release.bat -%s -%s" % (project, status)
	else:
		cmd = "call Release.bat -%s -%s -D" % (project, status)

	if not os.system(cmd):
		print("Build vip debug %s boot %s sucess!" % (status, boot))
	else:
		print("Build vip debug %s boot %s failed!" % (status, boot))
		sys.exit(1)


def update_config_file(status, config_file):
	with open(config_file, "r") as f:
		lines = f.readlines()

	for linenum in range(len(lines)):
		if "#define DEV_DEBUG_ON" in lines[linenum]:
			if status == "off":
				lines[linenum] = "//#define DEV_DEBUG_ON\n"
			else:
				lines[linenum] = "#define DEV_DEBUG_ON\n"

	with open(config_file, "w") as out:
		out.writelines(lines)


if __name__ == "__main__":
	cwd = sys.path[0]
	parser = argparse.ArgumentParser(description="Debug on/off, build and upload hex to ftp")
	parser.add_argument("--project", type=str, default=None)
	parser.add_argument("--debug", type=str, choices=["on", "off"])
	parser.add_argument("--config", type=str, default=sys.path[0] + "\..\Cfg\DevConfig.h")
	parser.add_argument("--release", type=str, default=sys.path[0] + "\Release")
	parser.add_argument("--vip_path", type=str, default=None)
	parser.add_argument("--boot", type=str, choices=["on", "off"], default="on")
	parser.add_argument("--build", action='store_true', help="whether build")
	parser.add_argument("--upload", action='store_true', help="whether upload")
	parser.add_argument("--linux_workspace", type=str, default=None)
	parser.add_argument("--linux_user", type=str, default=None)
	parser.add_argument("--linux_ip", type=str, default=None)
	args = parser.parse_args()
	update_config_file(args.debug, args.config)

	if args.debug == "on":
		build_type = 'Debug'
	else:
		build_type = 'Release'

	if args.build:
		build_mcu(args.project, args.release, build_type, args.boot)

	if args.upload:
		if args.linux_workspace is None:
			print("Please input linux_workspace args to upload!")
			exit(1)
		upload_to_linux_path(args.project, args.vip_path, build_type, args.linux_workspace, sys.path[0] + "\..\..\..\..\\", args.linux_user, args.linux_ip)