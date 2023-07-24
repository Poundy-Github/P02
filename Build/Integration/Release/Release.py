from cryptography.hazmat.primitives import cmac
from cryptography.hazmat.primitives.ciphers import algorithms
import os
import shutil
import time
import sys
import re

PRO_TYPE = sys.argv[1]
BUILT_TYPE = sys.argv[2]
OUTPUT_DIR = 'output'
print("Merge Project",PRO_TYPE, OUTPUT_DIR)

KEY = [167, 230, 68, 247, 185, 149, 201, 29,
       166, 13, 123, 62, 125, 250, 135, 232]
# KEY = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

fileList = [
    {
        "name": "BootManage",
        "path": "..\\..\\..\\BootManage\\Build\\output\\BootManager\\f1km_sk_v3_bm.hex",
        "Address": 0x00000000,
        "length": 0x00020000,
        "upgradeFile": False
    },
    {
        "name": "FirmwareA",
        "path": "..\\..\\output\\FirmwareA"+"\\f1km_sk_v3_ghs.hex",
        "Address": 0x00020000,
        "length": 0x001B0000,
        "upgradeFile": True
    },
    {
        "name": "FirmwareB",
        "path": "..\\..\\output\\FirmwareB"+"\\f1km_sk_v3_ghs.hex",
        "Address": 0x00200000,
        "length": 0x1B0000,
        "upgradeFile": True
    },
    {
        "name": "HSM",
        "path": "..\\..\\..\\HSM\\DemoHsm\\Appl\\vHsm.hex",
        "Address": 0x003B0000,
        "length": 0x40000,
        "upgradeFile": False
    }
]

# fqps = os.popen('qprocess|findstr /i hexview.exe')
# fqp = fqps.readlines()
# if len(fqp) > 0:
#     c = 'taskkill /f /t /im hexview.exe'
#     cmd = os.popen(c)
time.sleep(1)
if os.path.exists(OUTPUT_DIR+'\\data_'+BUILT_TYPE) == False:
    os.makedirs(OUTPUT_DIR+"\\data_"+BUILT_TYPE)
else:
    shutil.rmtree(OUTPUT_DIR+'\\data_'+BUILT_TYPE)
    os.makedirs(OUTPUT_DIR+"\\data_"+BUILT_TYPE)



def readFile(filepath):
    a = 25
    while a>0:
        try:
            with open(filepath, 'rb') as f:
                fr = f.read()
                return fr
        except IOError:
            time.sleep(1)
            a = a-1
            pass
    print("read file error :",filepath)
    sys.exit(1)

def HexViewFinish():
    a = 60
    while a>0:
        fqps = os.popen('qprocess|findstr /i hexview.exe')
        fqp = fqps.readlines()
        if len(fqp) == 0:
            return;
        a = a-1
        time.sleep(1)
    print("HexViewFinish Error")
    sys.exit(1)
    
def HexViewBusy():
    a = 60
    while a>0:
        fqps = os.popen('qprocess|findstr /i hexview.exe')
        fqp = fqps.readlines()
        if len(fqp) == 0:
            return;
        a = a-1
        time.sleep(1)
    print("HexViewBusy Timeout 60s")
    c = 'taskkill /f /t /im hexview.exe'
    cmd = os.popen(c)
    
HexViewBusy()
time.sleep(1)

# 创建 4M Hex 模板
outCmacHexFile = '.\\'+OUTPUT_DIR+'\\'+BUILT_TYPE+'-Firmware.hex'
# # os.mknod(outCmacHexFile)
fs = open(outCmacHexFile, 'wb')
fs.close()
f = os.popen('HexView\\hexview.exe '+outCmacHexFile +
             ' /FR:0x0000,0x400000 /FP:AAAAAAAA –o '+outCmacHexFile+'   /XI:32 /s')

# 填充数据
MergesFileList = []
upgradeFileList = []

for i, file in enumerate(fileList):
    mac = cmac.CMAC(algorithms.AES(bytes(KEY)))
    filepath, tmpfilename = os.path.split(file['path'])
    shotname, extension = os.path.splitext(tmpfilename)

    inFile = file['path']
    outHexFile = '.\\'+OUTPUT_DIR+'\\data_'+BUILT_TYPE+'\\'+file['name']+'.hex'
    outBinFile = '.\\'+OUTPUT_DIR+'\\data_'+BUILT_TYPE+'\\' + file['name']+'.bin'
    outCmacBinFile = '.\\'+OUTPUT_DIR+'\\data_'+BUILT_TYPE+'\\' + file['name']+'_Cmac.bin'
    addr = file['Address']
    length = file['length']
    if file['upgradeFile'] == True:
        upgradeFileList.append({
            'path': outCmacBinFile,
            'addr': addr,
            'len': length
        })

    # copy file
    c = 'copy '+file['path']+' '+outHexFile
    cmd = os.popen(c)
    readFile(outHexFile)
    # hex to bin
    c = 'HexView\\hexview.exe '+outHexFile+' /XP /s'
    bin = os.popen(c)
    # HexViewFinish()
    # 读取bin文件
    fr = readFile(outBinFile)
    infoAddr = file['length']-32

    fr_bytearray = bytearray(fr)
    fr_bytearray[infoAddr:infoAddr +
                 4] = bytearray(file['Address'].to_bytes(8, byteorder='big', signed=True))
    infoAddr = infoAddr + 8
    fr_bytearray[infoAddr:infoAddr + 4] = bytearray(
        (file['length']-16).to_bytes(8, byteorder='big', signed=True))

    infoAddr = infoAddr + 8

    mac.update(bytes(fr_bytearray[0:]))
    cmacV = mac.finalize()
    print(cmacV.hex())

    fr_bytearray[infoAddr:] = bytearray(cmacV)
    with open(outCmacBinFile, 'wb') as fw:
        fw.write(bytes(fr_bytearray))

    # bin to hex
    addr_str = str(file['Address'])
    len_str = str(file['length'])
    fileInfo = {
        "path": outCmacBinFile,
        "addr": addr_str,
        "len": len_str
    }
    MergesFileList.append(fileInfo)

HexViewFinish()
c = 'HexView\\hexview.exe /MT:'
for fileInfo in MergesFileList:
    c = c+fileInfo['path']+';+'+fileInfo['addr']+':0x00,'+fileInfo['len']+'+'
c = c+outCmacHexFile+' -o '+outCmacHexFile+' /XI:32 /s'
bin = os.popen(c)
HexViewFinish()
time.sleep(20)
# c = 'copy '+outCmacHexFile+' '+outCmacHexFile+'2.hex'
# cmd = os.popen(c)