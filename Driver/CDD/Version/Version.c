/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      Version.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Platform_Types.h"
#include "VersionCfg.h"
#include <string.h>
#include "Version.h"


#if 0
#pragma ghs startdata
#pragma ghs section rodata = ".app_version_check"

const unsigned char svw_version_checksum = VIP_VERSION_STATE + VIP_VERSION_MAJOR + VIP_VERSION_MID + VIP_VERSION_MINOR;

#pragma ghs section rodata = default
#pragma ghs enddata
#endif


#pragma ghs startdata
#pragma ghs section rodata = ".app_version_code"

const unsigned char app_version_value[16] = {APP_VERSION_VALUE};

#pragma ghs section rodata = default
#pragma ghs enddata


#define Misc_START_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h" 

static const char systemSupplierIdentifier[5] ={SYSTEM_SUPPLIER_ID};
static const char CANMatrixVersion[19] = {CAN_MATRIX_VERSION};

#if (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_D01) || (defined GWM_V35_PROJECT_TYPE_D02)\
    || (defined GWM_V35_PROJECT_TYPE_D03) || (defined GWM_V35_PROJECT_TYPE_P02)|| (defined GWM_V35_PROJECT_TYPE_A07)\
    || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)

static const char CANMatrixVersion_2[19] = {CAN_MATRIX_VERSION_2};
#endif

static const char GwmEcuSoftwareVersion[15]= {GWM_ECU_SOFT_VERSION};
static const char GwmEcuCalibrationSoftwareVersionn[15] = {GWM_ECU_CALIB_SOFT_VER};
static const char GwmEcuBootSoftwareVersion[15] = {GWM_ECU_BOOT_SOFT_VER};

static const uint8 SoftwareVersionVIP[4] = {SOFT_WARE_VERSION_VIP};
static const uint8 BootloaderVersionVIP[4] = {BOOT_LOADER_VERSION_VIP};
static const char * SysSupplierECUSoftVerNum = SYS_SUPPLIER_ECU_SOFT_VER_NUM;
#define Misc_STOP_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h"


#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" 

/******************************************************************************/
/**
* @brief               <Version_GetBootloaderVersionVIP>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <length>
* @param[out]          <buf>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void Version_GetBootloaderVersionVIP(uint8 *buf,uint16 length)
{
    uint8 index;

    if(4 == length)
    {
        for(index = 0;index < length;index++)
        {
            buf[index] = BootloaderVersionVIP[index];
        }
    }
}

/******************************************************************************/
/**
* @brief               <Version_GetSoftwareVersionVIP>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <length>
* @param[out]          <buf>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void Version_GetSoftwareVersionVIP(uint8 *buf,uint16 length)
{
    uint8 index;
    
    if(4 == length)
    {
        for(index = 0;index < length;index++)
        {
            buf[index] = app_version_value[index];
        }
    }

}

/******************************************************************************/
/**
* @brief               <Version_GetSystemSupplierECUSoftwareVersionNumber>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <length>
* @param[out]          <buf>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void Version_GetSystemSupplierECUSoftwareVersionNumber(uint8 *buf,uint16 length)
{
    uint8 index;
    
    if(18 == length)
    {
        for(index = 0;index < length;index++)
        {
            if(index < strlen(SysSupplierECUSoftVerNum))
            {
                buf[index] = (uint8)SysSupplierECUSoftVerNum[index];
            }
            else
            {
                buf[index] = 0x00;
            }
        }
    }

}



void Version_GetSystemSupplierIdentifier(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)systemSupplierIdentifier[i];
    }
}

void Version_GetCANMatrixVersion(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)CANMatrixVersion[i];
    }
}

#if (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_D01) || (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03)\
    ||(defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_P09) || (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_P01) 
void Version_GetCANMatrixVersion_2(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)CANMatrixVersion_2[i];
    }
}
#endif

void Version_GetGwmEcuSoftwareVersion(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)GwmEcuSoftwareVersion[i];
    }
}

void Version_GetGwmEcuCalibrationSoftwareVersionn(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)GwmEcuCalibrationSoftwareVersionn[i];
    }
}

void Version_GetGwmEcuBootSoftwareVersion(uint8 *buf,uint16 length)
{
    uint8 i;
    for(i = 0;i < length;i++)
    {
        buf[i] = (uint8)GwmEcuBootSoftwareVersion[i];
    }
}





void Version_GetSoftVersion(uint32 *softVer)
{
    *softVer = SOFTWARE_VERSION;
}


#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h"


