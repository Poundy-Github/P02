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

/**********************************************************************************************************
*File Name   : SWC_DrvMod_Interface.h                                                                     *
*                                                                                                         *
*Description : Driving mode module interface function head file.                                          *
*                                                                                                         *
*Author      : Li Jian                                                                                    *
*                                                                                                         *
*Platform    : MICROSAR OS                                                    						      *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef DM_API_H
#define DM_API_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_DM_Config.h"

#define Common_Normal_START_SEC_CODE
#include  "Common_Normal_MemMap.h"

void DM_API_vKSColdInit(void);

void DM_API_vKSWarmInit(void);

void DM_API_vDrvModeAppTimeTask(void);

Std_ReturnType DM_API_vSetDrvModWarningStatus(DM_CFG_enWarningId enDrvModWarningID);

Std_ReturnType DM_API_vClrDrvModWarningStatus(uint8 u8DrvModWarningID);

Std_ReturnType DM_API_vSetDrvModTTStatus(DM_CFG_enTelltaleId enDrvModTelltaleID);

void DM_API_vClrAllDrvModWarningStatus(void);

void DM_API_vClrDrvModTTStatus(void);

void DM_API_vSetDrvModAuxStatus(uint8 u8DrvModConfigid);

Std_ReturnType DM_API_vSetHybridModTTStatus(DM_HMCFG_enTelltaleId enHybModTelltaleID);

void DM_API_vClrHybridModTTStatus(void);

void DM_API_vSetDrvModVehType(uint8 u8VehType);

void DM_API_vSetDrvModSwitchSignal(uint8 u8DrvMod, uint8 u8IMCActv);

#define Common_Normal_STOP_SEC_CODE
#include  "Common_Normal_MemMap.h"

#endif

