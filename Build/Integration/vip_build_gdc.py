# -*- coding: utf-8 -*-
import argparse
import os
import sys
def upload_to_linux_path(project, vip_dbg_path, vip_rls_path, linux_path, workspace, linux_user, linux_ip):
    vip_pac_path = linux_path + "/work/vip_package/packages/"
    vip_bac_path = linux_path  + "/work/vip_package/backups/"
    dbg_package_name = str(vip_dbg_path).split("packages/")[1]
    rls_package_name = str(vip_rls_path).split("packages/")[1]
    os.chdir(workspace + "\work\VIP\Build\Integration")
    os.system("copy %s_upgrade_debug.mcu upgrade.mcu" % project)
    os.system("zip -r %s %s_MCU_debug.hex upgrade_ms.mcu upgrade.mcu" % (dbg_package_name, project))
    os.remove("upgrade.mcu")
    os.system("copy %s_upgrade_release.mcu upgrade.mcu" % project)
    os.system("zip -r %s %s_MCU_release.hex upgrade_ms.mcu upgrade.mcu" % (rls_package_name, project))
    
    map_name = "MCU_map.zip"
    os.system("copy .\..\..\BootManage\Build\output\BootManager\\f1km_sk_v3_bm.map f1km_sk_v3_bm.map")
    os.system("copy .\..\..\HSM\DemoHsm\Appl\\vHsm.map vHsm.map")
    os.system("copy .\..\output\FirmwareA\\f1km_sk_v3_ghs.map FirmwareA_f1km_sk_v3_ghs.map")
    os.system("copy .\..\output\FirmwareB\\f1km_sk_v3_ghs.map FirmwareB_f1km_sk_v3_ghs.map")
    os.system("zip -r %s f1km_sk_v3_bm.map vHsm.map FirmwareA_f1km_sk_v3_ghs.map  FirmwareB_f1km_sk_v3_ghs.map" % map_name)
    os.system("scp %s %s %s@%s:%s" % (dbg_package_name, rls_package_name, linux_user, linux_ip, vip_pac_path))
    os.system("scp %s %s@%s:%s" % (map_name, linux_user, linux_ip, vip_bac_path))
 
def build_mcu(project, build_path):
    os.chdir(build_path)
    cmd = "call build_GDC.bat %s %s" % (project, project)
    if not os.system(cmd):
        print("Build vip sucess!")
    else:
        print("Build vip failed!" )
        sys.exit(1)
        
    os.system('python pack_boot.py Release')

if __name__ == "__main__":
    cwd = sys.path[0]
    parser = argparse.ArgumentParser(description="Debug on/off, build and upload hex to ftp")
    parser.add_argument("--project", type=str, default=None)
    parser.add_argument("--vip_debug_path", type=str, default=None)
    parser.add_argument("--vip_release_path", type=str, default=None)
    parser.add_argument("--build", action='store_true', help="whether build")
    parser.add_argument("--upload", action='store_true', help="whether upload")
    parser.add_argument("--linux_workspace", type=str, default=None)
    parser.add_argument("--linux_user", type=str, default=None)
    parser.add_argument("--linux_ip", type=str, default=None)
    args = parser.parse_args()

    if args.build:
        build_mcu(args.project, cwd)

    if args.upload:
        if args.linux_workspace is None:
            print("Please input linux_workspace args to upload!")
            exit(1)
        upload_to_linux_path(args.project, args.vip_debug_path, args.vip_release_path, args.linux_workspace, sys.path[0] + "\..\..\..\..\\", args.linux_user, args.linux_ip)


