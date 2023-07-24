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
 * @file:      Version.h
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

#ifndef _VERSION_H_
#define _VERSION_H_

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h"

void Version_GetSoftVersion(uint32 *softVer);
void Version_GetSystemSupplierIdentifier(uint8 *buf,uint16 length);
void Version_GetCANMatrixVersion(uint8 *buf,uint16 length);
#if (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_D01) || (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) \
    ||(defined GWM_V35_PROJECT_TYPE_P02)|| (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)
void Version_GetCANMatrixVersion_2(uint8 *buf,uint16 length);
#endif
void Version_GetGwmEcuSoftwareVersion(uint8 *buf,uint16 length);
void Version_GetGwmEcuCalibrationSoftwareVersionn(uint8 * buf, uint16 length);
void Version_GetGwmEcuBootSoftwareVersion(uint8 *buf,uint16 length);
//void Version_GetUin(uint8 *buf,uint16 length);
void Version_GetSoftwareVersionVIP(uint8 *buf,uint16 length);
void Version_GetBootloaderVersionVIP(uint8 *buf,uint16 length);
void Version_GetSystemSupplierECUSoftwareVersionNumber(uint8 *buf,uint16 length);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h"

#endif
