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
*File Name   : SWC_TT_Safety_Adaptor.h                                                                    *
*                                                                                                         *
*Description : Telltale module Adaptor module source file.                                                *
*                                                                                                         *
*Author      : li yafei                                                                                   *
*                                                                                                         *
*Platform    : Free Rtos System                                                                           *
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
#ifndef SWC_TT_SAFETY_ADAPTOR_H
#define SWC_TT_SAFETY_ADAPTOR_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "E2EPW_Common_Safety_SG_ABS3_SG_ABS3_rx.h"
#include "E2EPW_Common_Safety_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2_rx.h"
#include "E2EPW_Common_Safety_SG_ESP1_SG_ESP1_rx.h"
#include "E2EPW_Common_Safety_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2_rx.h"
#include "E2EPW_Common_Safety_SG_EPB1_SG_EPB1_rx.h"
#include "E2EPW_Common_Safety_SG_EPS1_SG_EPS1_rx.h"
#include "E2EPW_Common_Safety_SG_EPS1_FD1_SG_EPS1_FD1_rx.h"
#include "E2EPW_Common_Safety_SG_ABM1_SG_ABM1_rx.h"
#include "E2EPW_Common_Safety_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2_rx.h"
/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/



#ifdef GWM_V35_PROJECT_TYPE_B02
	#define SWC_TT_SAFETY_PROJECT_TYPE_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define SWC_TT_SAFETY_PROJECT_TYPE_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define SWC_TT_SAFETY_PROJECT_TYPE_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define SWC_TT_SAFETY_PROJECT_TYPE_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define SWC_TT_SAFETY_PROJECT_TYPE_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define SWC_TT_SAFETY_PROJECT_TYPE_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define SWC_TT_SAFETY_PROJECT_TYPE_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define SWC_TT_SAFETY_PROJECT_TYPE_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define SWC_TT_SAFETY_PROJECT_TYPE_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define SWC_TT_SAFETY_PROJECT_TYPE_P01
#else
	#error  project type is invalid !!
#endif

//tips: 'E2EPW_ReadInit_SG_XXX' is no longer used by the module.
#ifdef SWC_TT_SAFETY_PROJECT_TYPE_B03
	#include "E2EPW_Common_Safety_SG_BMS4_SG_BMS4_rx.h"
	#include "E2EPW_Common_Safety_SG_HCU_PT7_SG_HCU_PT7_rx.h"
#else
	#include "ComEx_Cfg.h"
#endif


#define E2E_OK    (((uint32)0<<31)|(((uint32)E2E_P01STATUS_OK & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

#define E2E_NONEWDATA   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_NONEWDATA & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

#define E2E_SYNC   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_SYNC & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

#define E2E_INITIAL   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_INITIAL & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

#define E2E_OK_SOMELOST   (((uint32)0<<31)|(((uint32)E2E_P01STATUS_OKSOMELOST & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))


typedef uint8 TT_ADAPT_TYPE;
typedef uint32 TT_E2E_ADAPT_TYPE;

typedef enum
{
  ATT_NO_DOMAIN,
  ATT_DOMAIN_CH,
  ATT_DOMAIN_US
}ATT_DOMAIN_INFO;
/*此枚举定义用于表示Byte4决定的地域划分配置,不同数据对应的意义如下:
  1.TT_NO_DOMAIN        地域错误
  2.TT_DOMAIN_CH        国内（地域划分目前只有两种，一种是国内，欧洲等，另外一种是北美，只有北美和其他地域不同，因此非北美的统称为国内）
  3.TT_DOMAIN_US        北美*/

typedef enum
{
  ATT_NO_SIGNAL,
  ATT_CAN_SIGNAL,
  ATT_CANFD_SIGNAL
}ATT_SIGNAL_SOURCE;
/*此枚举定义用于表示Byte3决定的信号来源,不同数据对应的意义如下:
  1.TT_NO_SIGNAL         不调用信号
  2.TT_CAN_SIGNAL        信号来源CAN
  3.TT_CANFD_SIGNAL      信号来源CANFD*/

typedef struct
{
	uint8 ABSActv_0x265;
	uint8 ABSFailSts_0x265;
	uint8 CheckSum_ABS3_0x265;
	uint8 EBDActv_0x265;
	uint8 EBDFailSts_0x265;
	uint8 RollingCounter_ABS3_0x265;
	uint16 VehOdoInfo_0x265;
	uint8 VehOdoInfoSts_0x265;
	uint16 VehSpd_0x265;
	uint8 VehSpdVld_0x265;
	uint8 ABS_Sts;
} ADAPT_SG_ABS3;

typedef struct
{
	uint8 ABSActv_0x137;
	uint8 ABSFailSts_0x137;
	uint8 CheckSum_ABS3_0x137;
	uint8 EBDActv_0x137;
	uint8 EBDFailSts_0x137;
	uint8 RollingCounter_ABS3_0x137;
	uint16 VehOdoInfo_0x137;
	uint8 VehOdoInfoSts_0x137;
	uint16 VehSpd_0x137;
	uint8 VehSpdVld_0x137;
	uint8 ABS3_ESP_FD2_Sts;
} ADAPT_SG_ABS3_ESP_FD2;

typedef struct
{
	uint8 BTCActv_0x149;
	uint8 CheckSum_ESP1_0x149;
	uint16 ESP_MasterCylBrkPress_0x149;
	uint8 ESP_MasterCylBrkPressVld_0x149;
	uint8 ESPActvInfoLmp_0x149;
	uint8 ESPBrkLmpCtrl_0x149;
	uint8 ESPFailSts_0x149;
	uint8 ESPFuncOffSts_0x149;
	uint8 MSRActv_0x149;
	uint8 PTCActv_0x149;
	uint8 RollingCounter_ESP1_0x149;
	uint8 VDCActv_0x149;
	uint8 ESP1_Sts;
} ADAPT_SG_ESP1;

typedef struct
{
	uint8 BTCActv_0x137;
	uint8 CheckSum_ESP1_0x137;
	uint16 ESP_MasterCylBrkPress_0x137;
	uint8 ESP_MasterCylBrkPressVld_0x137;
	uint8 ESPActvInfoLmp_0x137;
	uint8 ESPBrkLmpCtrl_0x137;
	uint8 ESPFailSts_0x137;
	uint8 ESPFuncOffSts_0x137;
	uint8 MSRActv_0x137;
	uint8 PTCActv_0x137;
	uint8 RollingCounter_ESP1_0x137;
	uint8 VDCActv_0x137;
	uint8 ESP1_ESP_FD2_Sts;
} ADAPT_SG_ESP1_ESP_FD2;

typedef struct
{
	uint8 CheckSum_EPB1;
	uint8 EPBErrSts;
	uint8 EPBRedLmpSts;
	uint8 EPBSts;
	uint8 EPBTextDisp;
	uint8 PressBrakePedalPointOut;
	uint8 RollingCounter_EPB1;
	uint8 EPB1_Sts;
} ADAPT_SG_EPB1;

typedef struct
{
	uint8 CheckSum_EPS1_0x147;
	uint8 EPS_FailSts_0x147;
	uint8 EPS_SteerMod_0x147;
	uint8 EPS_TrqSnsrSts_0x147;
	uint8 RollingCounter_EPS1_0x147;
	uint8 EPS1_FD1_Sts;
} ADAPT_SG_EPS1_FD1;

typedef struct
{
  uint8 CheckSum_EPS1_0x168;
  uint8 EPS_FailSts_0x168;
  uint8 EPS_SteerMod_0x168;
  uint8 EPS_TrqSnsrSts_0x168;
  uint8 RollingCounter_EPS1_0x168;
  uint8 EPS1_Sts;
} ADAPT_SG_EPS1;

typedef struct
{
  uint8 AirbFailLmpCmd;
  uint8 CheckSum_ABM1;
  uint8 DrvSBR;
  uint8 DrvSBR_Visual;
  uint8 PassSBR;
  uint8 PassSBR_Visual;
  uint8 RollingCounter_ABM1;
  uint8 SecRowLSBR;
  uint8 SecRowLSBR_Visual;
  uint8 SecRowMidSBR;
  uint8 SecRowMidSBR_Visual;
  uint8 SecRowRSBR;
  uint8 SecRowRSBR_Visual;
  uint8 CrashOutputSts;
  uint8 ABM1_Sts;
} ADAPT_SG_ABM1;

typedef struct
{
	uint8 AEB_JA_Warn;
	uint8 AEB_JABrkTrig;
	uint8 AEB_JAFuncSts;
	uint8 AEB_PedTrig;
	uint8 AEB_VehTrig;
	uint8 Checksum_AEB3;
	uint8 FCW_AEB_PedFctSts;
	uint8 FCW_AEB_VehFctSts;
	uint8 FCW_Warn;
	uint8 RollingCounter_AEB3;
	uint8 AEB_FD2_Sts;
} ADAPT_SG_AEB_FD2;


#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h"

TT_ADAPT_TYPE ATT_GetMessage_ABS_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_ESP_Enable_Sts(uint8 *data_f, uint8 *data_s);
TT_ADAPT_TYPE ATT_GetMessage_ESP_Disable_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_EPB_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_Break_Erro_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_EPS_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_ABM_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_FCW_Sts(uint8 *data_f, uint8 *data_s, uint8 *data_d, uint8 *data_l);
TT_ADAPT_TYPE ATT_GetMessage_PBF_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_HEV_Sts(uint8 *data);
TT_ADAPT_TYPE ATT_GetMessage_TPF_Sts(uint8 *data);

TT_ADAPT_TYPE ATT_GetMessage_E2E_ABS_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_ESP_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_EPB_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_EPS_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_ABM_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_AEB3_FD_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_SG_BMS4_Sts(uint32 *E2Ests);
TT_ADAPT_TYPE ATT_GetMessage_E2E_HCU_PT7_Sts(uint32 *E2Ests);

void ATT_vE2E_Message_init(void);
ATT_DOMAIN_INFO ATT_vDomain_Logic_Process(void);
ATT_SIGNAL_SOURCE ATT_vSignal_Source_Process(void);
TT_ADAPT_TYPE ATT_Adapt_GetVconfig(uint16 id_u8);
extern boolean STT_boSendSelfcheckReportsts(void);

#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"


#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
