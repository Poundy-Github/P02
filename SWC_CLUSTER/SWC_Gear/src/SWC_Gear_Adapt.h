/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_DM_Adapt.h                                                                             *
*                                                                                                         *
*Description : Driving mode module adaptation head file.                                                  *
*                                                                                                         *
*Author      : Li Jian                                                                                    *
*                                                                                                         *
*Platform    : MICROSAR OS                                                   						  	  *
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
#ifndef GEAR_ADAPT_H
#define GEAR_ADAPT_H
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "Rte_Common_Safety.h"


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Std_Types.h"
#include "Vconfig.h"
#include "IPC_ClusterApp.h"
#include "SWC_Gear_config.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_GEAR_ADAPT_B02
/* 7DCT: DCT_FD4 0x236
*  PHEVHEVPS: HCU_HP5 0x201
*/
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SWC_GEAR_ADAPT_B03
/* 7DCT: DCT7 0x235
*  PHEVHEVPS: HCU_HP5 0x201
*/
#elif defined GWM_V35_PROJECT_TYPE_B06
#define SWC_GEAR_ADAPT_B06
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_GEAR_ADAPT_P05
/* 8AT: DCT9 0x0c6
*  MT:  ECM10 0x139
*  9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_GEAR_ADAPT_P03
/* 9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SWC_GEAR_ADAPT_A07
/* 7DCT: DCT7 0x235
*  PHEVHEVPS: HCU_HP5 0x201
*/
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SWC_GEAR_ADAPT_D01
/* 9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SWC_GEAR_ADAPT_D02
/* 9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SWC_GEAR_ADAPT_D03
/* 9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SWC_GEAR_ADAPT_P02
/* 9AT: DCT_FD4 0x236
*/
#elif defined GWM_V35_PROJECT_TYPE_P01
#define SWC_GEAR_ADAPT_P01
/* 9AT: DCT_FD4 0x236
*/
#else
#define SWC_GEAR_ADAPT_NULL
/* EV: VCU_FD3 0x219
*/

#endif
/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

//tips: ComEx does not need to initialize E2E status in the module
#if (defined(SWC_GEAR_ADAPT_B03))
	#include "E2EPW_Common_Safety_SG_DCT7_SG_DCT7_rx.h"
	#include "E2EPW_Common_Safety_SG_HCU_HP5_SG_HCU_HP5_rx.h"
#else
	#include "ComEx.h"
#endif

/*****************************************************************************
*                                E2E function                                *
******************************************************************************/
#define E2E_SWITCH_OFF	(0U)
#define E2E_SWITCH_ON	(1U)

#define E2E_OK    (((uint32)0<<31)|(((uint32)E2E_P01STATUS_OK & 0x7FU)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define E2E_NONEWDATA   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_NONEWDATA & 0x7FU)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define E2E_SYNC   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_SYNC & 0x7FU)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define E2E_INITIAL   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_INITIAL & 0x7FU)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define E2E_OK_SOMELOST   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_OKSOMELOST & 0x7FU)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

// Gear CRC Table
#if ((defined(SWC_GEAR_ADAPT_B03)))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE1
#elif (defined(SWC_GEAR_ADAPT_B02))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE1
#elif (defined(SWC_GEAR_ADAPT_P05))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE2
#elif (defined(SWC_GEAR_ADAPT_P03))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE4
#elif (defined(SWC_GEAR_ADAPT_A07))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE3
#elif (defined(SWC_GEAR_ADAPT_D01))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE2
#elif (defined(SWC_GEAR_ADAPT_D02))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE2
#elif (defined(SWC_GEAR_ADAPT_D03))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE5
#elif (defined(SWC_GEAR_ADAPT_P02))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE2
#elif (defined(SWC_GEAR_ADAPT_P01))
	#define GEAR_CFG_CRC_TABLE		GEAR_CFG_CRC_TABLE2
#endif


/*****************************************************************************
*                                E2E function                                *
******************************************************************************/

#define GearMdl_Adapt_GetCconfig(x) Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(x)
#define GearMdl_Adapt_GetE2ESwitchChangeTrigger(x) Rte_Read_piSR_E2ESwitchChangeTrigger_Element(x)

#define Common_GateWay_START_SEC_CODE
#include "Common_Safety_MemMap.h"

SystemState_RecordType *GearMdl_Adapt_GetPowerMode(void);
// gear signal adapt
uint8 GearMdl_Adapt_GetCANMessage_7DCT(GR_CFG_SG_DCT7* const MESS_SG_7DCT);			// 7DCT/9DCT/9AT: CAN
uint8 GearMdl_Adapt_GetCANMessage_DCT_FD4(GR_CFG_SG_DCT_FD4* const MESS_SG_DCTFD4);	// 7DCT/9DCT/9AT: CANFD
uint8 GearMdl_Adapt_GetCANMessage_9DCT(GR_CFG_DCT9* const MESS_SG_DCT9);			// 8AT
uint8 GearMdl_Adapt_GetCANMessage_HCU_HP5(GR_CFG_SG_HCU_HP5* const MESS_SG_HP5);	// PEHVHEVPS
uint8 GearMdl_Adapt_GetCANMessaage_ECM10(GR_CFG_ECM10* const MESS_SG_ECM10);		// MT: (gear up or down)not judge E2E

// E2E init & get E2E status
void GearMdl_Adapt_E2EPW_AllReadInit(void);
uint32 GearMdl_Adapt_GetE2EPW_DCT7(void);
uint32 GearMdl_Adapt_GetE2EPW_DCT_FD4(void);
uint32 GearMdl_Adapt_GetE2EPW_HCU_HP5(void);
uint32 GearMdl_Adapt_GetE2EPW_DCT9(void);

#define Common_GateWay_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

#endif

