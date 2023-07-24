import sys

startAddressBoot = 0x00000000
BUILT_TYPE = sys.argv[1]
OUTPUT_DIR = 'output'
fileWrite = open("upgrade_ms.mcu", 'wb')
fileReadBoot = open("Release/"+OUTPUT_DIR+"/data_"+BUILT_TYPE+"/BootManage_Cmac.bin", 'rb')
bootContent = bytearray(fileReadBoot.read())

head = bytearray([0x55, 0xAA, 0x55, 0xAA])
fileWrite.write(head)

firmwareOffset = 116
firmwareLength = len(bootContent)
firmwareEcuAddress = startAddressBoot

firmwareHead = bytearray()
firmwareHead.append((firmwareOffset >> 24) & (0xFF))
firmwareHead.append((firmwareOffset >> 16) & (0xFF))
firmwareHead.append((firmwareOffset >> 8) & (0xFF))
firmwareHead.append(firmwareOffset & 0xFF)

firmwareHead.append((firmwareLength >> 24) & (0xFF))
firmwareHead.append((firmwareLength >> 16) & (0xFF))
firmwareHead.append((firmwareLength >> 8) & (0xFF))
firmwareHead.append(firmwareLength & 0xFF)

firmwareHead.append((firmwareEcuAddress >> 24) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 16) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 8) & (0xFF))
firmwareHead.append(firmwareEcuAddress & 0xFF)

fileWrite.write(firmwareHead)

firmwareSignature = bytearray([0x00, 0x02, 0x00, 0x44, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
fileWrite.write(firmwareSignature)

firmwareOffset = 0
firmwareLength = 0
firmwareEcuAddress = 0

firmwareHead = bytearray()
firmwareHead.append((firmwareOffset >> 24) & (0xFF))
firmwareHead.append((firmwareOffset >> 16) & (0xFF))
firmwareHead.append((firmwareOffset >> 8) & (0xFF))
firmwareHead.append(firmwareOffset & 0xFF)

firmwareHead.append((firmwareLength >> 24) & (0xFF))
firmwareHead.append((firmwareLength >> 16) & (0xFF))
firmwareHead.append((firmwareLength >> 8) & (0xFF))
firmwareHead.append(firmwareLength & 0xFF)

firmwareHead.append((firmwareEcuAddress >> 24) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 16) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 8) & (0xFF))
firmwareHead.append(firmwareEcuAddress & 0xFF)

fileWrite.write(firmwareHead)

firmwareSignature = bytearray([0x00, 0x3A, 0xFF, 0xD0, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
fileWrite.write(firmwareSignature)

firmwareOffset = 0
firmwareLength = 0
firmwareEcuAddress = 0

firmwareHead = bytearray()
firmwareHead.append((firmwareOffset >> 24) & (0xFF))
firmwareHead.append((firmwareOffset >> 16) & (0xFF))
firmwareHead.append((firmwareOffset >> 8) & (0xFF))
firmwareHead.append(firmwareOffset & 0xFF)

firmwareHead.append((firmwareLength >> 24) & (0xFF))
firmwareHead.append((firmwareLength >> 16) & (0xFF))
firmwareHead.append((firmwareLength >> 8) & (0xFF))
firmwareHead.append(firmwareLength & 0xFF)

firmwareHead.append((firmwareEcuAddress >> 24) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 16) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 8) & (0xFF))
firmwareHead.append(firmwareEcuAddress & 0xFF)

fileWrite.write(firmwareHead)

firmwareSignature = bytearray([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF])
fileWrite.write(firmwareSignature)

firmwareOffset = 0
firmwareLength = 0
firmwareEcuAddress = 0

firmwareHead = bytearray()
firmwareHead.append((firmwareOffset >> 24) & (0xFF))
firmwareHead.append((firmwareOffset >> 16) & (0xFF))
firmwareHead.append((firmwareOffset >> 8) & (0xFF))
firmwareHead.append(firmwareOffset & 0xFF)

firmwareHead.append((firmwareLength >> 24) & (0xFF))
firmwareHead.append((firmwareLength >> 16) & (0xFF))
firmwareHead.append((firmwareLength >> 8) & (0xFF))
firmwareHead.append(firmwareLength & 0xFF)

firmwareHead.append((firmwareEcuAddress >> 24) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 16) & (0xFF))
firmwareHead.append((firmwareEcuAddress >> 8) & (0xFF))
firmwareHead.append(firmwareEcuAddress & 0xFF)

fileWrite.write(firmwareHead)

firmwareSignature = bytearray([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF])
fileWrite.write(firmwareSignature)

fileWrite.write(bootContent)

fileWrite.close()
fileReadBoot.close()

fileRead = open("upgrade_ms.mcu", 'rb')
content = fileRead.read()
print(len(content))
fileRead.close()