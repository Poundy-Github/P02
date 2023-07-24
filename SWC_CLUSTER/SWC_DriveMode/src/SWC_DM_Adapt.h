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
*File Name   : SWC_DM_Adapt.h                                                                             *
*                                                                                                         *
*Description : Driving mode module adaptation head file.                                                  *
*                                                                                                         *
*Author      : Li Jian                                                                                    *
*                                                                                                         *
*Platform    : MICROSAR OS                                                                                *
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
#ifndef DM_ADAPT_H
#define DM_ADAPT_H
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

#define TASK_DRVMOD_DUTY    (20u)    //ms
#define TIME_3_SEC          (3000u/TASK_DRVMOD_DUTY)
#define	TIME_100_MS         (100u/TASK_DRVMOD_DUTY)

#define	TIME_25_SEC         (25000u/TASK_DRVMOD_DUTY)
#define	TIME_22_SEC         (22000u/TASK_DRVMOD_DUTY)

#define DM_PRIORITY_1    (0u)
#define DM_PRIORITY_2    (1u)

//#define DM_CFG_POWER_STATE	(0x08)		// need IGN RTE interface

#define DM_CFG_POWER_STATE_IS_OFF(powerStatus)                  (0x00 == (powerStatus))
#define DM_CFG_POWER_STATE_IS_RUN(powerStatus)                  (0x01 == (powerStatus))
//#define DM_CFG_POWER_STATE_IS_ABNORMAL_VOLTAGE     (0x20 == DM_CFG_POWER_STATE)
#define Common_Normal_START_SEC_CODE

typedef enum
{
  DM_NO_SIGNAL,
  DM_CAN_SIGNAL,
  DM_CANFD_SIGNAL
}DM_SIGNAL_SOURCE;

#include  "Common_Normal_MemMap.h"

boolean DM_Adapt_FuelModeIdCheck(uint8 u8ModeId);
uint8 DM_Adapt_GetMessage_DrivingMod(uint8 *data_s,uint8 *data_t);
uint8 DM_Adapt_GetMessage_HCU_DrvMod(uint8 *data);
uint8 DM_Adapt_GetMessage_HCU_DrvModDisp(uint8 *data);
uint8 DM_Adapt_GetVconfig(uint16 id_u8);
//uint8 DM_Adapt_GetSelfChecksts(uint8 *data);
DM_SIGNAL_SOURCE DM_Adapt_Signal_Source(void);
uint8 DM_Adapt_FuelLogicPriority(void);
uint8 DM_Adapt_GetMessage_IMC_Actv(uint8 *data);
uint8 DM_Adapt_GetMessage_SystemOperMod(uint8 *data);
uint8 DM_Adapt_GetMessage_HCU_HybMod(uint8 *data);

#define Common_Normal_STOP_SEC_CODE
#include  "Common_Normal_MemMap.h"

#endif

