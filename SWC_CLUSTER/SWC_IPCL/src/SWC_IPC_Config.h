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

/***********************************************************************************************************
**
**  Name:               SWC_IPC_Config.h
**
**  Description:        SWC module ipc message send and received com.h
**
**  Organization:
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_CFG_H
#define SWC_IPC_CFG_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* Vehicle platform configuration macro                                                                    *
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define SWC_IPC_PROJECT_TYPE_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define SWC_IPC_PROJECT_TYPE_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define SWC_IPC_PROJECT_TYPE_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define SWC_IPC_PROJECT_TYPE_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define SWC_IPC_PROJECT_TYPE_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define SWC_IPC_PROJECT_TYPE_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define SWC_IPC_PROJECT_TYPE_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define SWC_IPC_PROJECT_TYPE_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define SWC_IPC_PROJECT_TYPE_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define SWC_IPC_PROJECT_TYPE_P01
#else
	#error project type is invalid !!
#endif

#ifndef SWC_IPC_PROJECT_TYPE_B03
#include "ComEx_Cfg.h"
#endif

/**********************************************************************************************************
* IPC Object Check Switch                                                                                 *
**********************************************************************************************************/

//#define SWC_IPC_OBJECT_CHECK

#ifdef SWC_IPC_OBJECT_CHECK

#define SWC_IPC_CHECKSUM_INIT_VALUE        (0xA5u)



#endif

/**********************************************************************************************************
* IPC Debug Switch                                                                                        *
**********************************************************************************************************/

#define SWC_IPC_DEBUG

/*********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
/**********************************************************************************************************
* Log Head File Include                                                                                   *
**********************************************************************************************************/
#include "logger.h"
#include <stdio.h>

/**********************************************************************************************************
* Debug Define                                                                                            *
**********************************************************************************************************/

/*Buffer pile init value*/
#define SWC_IPC_DEBUG_PILE                 (0xA5u)

/**********************************************************************************************************
* IPC Error Code Definenation                                                                             *
**********************************************************************************************************/
typedef enum
{
	SWC_IPC_NO_ERROR = 0 ,
	SWC_IPC_ERROR_TICK_COUNTER_OVERFLOW ,
	SWC_IPC_ERROR_BUFFER_PILE_MODIFYED ,
	SWC_IPC_ERROR_NVM_SIZE_DEFINE_WRONG ,
	SWC_IPC_ERROR_NVM_USED_SPACE_OVERFLOW ,
	SWC_IPC_ERROR_OBJECT_NUMBER_VALUE_MODIFYED ,
	SWC_IPC_ERROR_OBJECT_ATTRIBUTE_TABLE_POINTER_MODIFYED ,



    SWC_IPC_ERROR_RESERVED_INDEX ,
}SWC_IPC_ErrorCodeList;

#define SWC_IPC_TOTAL_ERROR_CODE_NUMBER    (SWC_IPC_ERROR_RESERVED_INDEX - 1)
#define SWC_IPC_CAN_BUFFER_VERBOSE_PRINT_SWITCH
/**********************************************************************************************************
* IPC Log Switch Definenation                                                                             *
**********************************************************************************************************/

//#define SWC_IPC_CAN_BUFFER_PRINT_SWITCH

//#define SWC_IPC_APP_BUFFER_PRINT_SWITCH

//#define SWC_IPC_CYCLIC_MSG_PRINT_SWITCH

/**********************************************************************************************************
* IPC Log Interface Definenation                                                                          *
**********************************************************************************************************/

//#define SWC_IPC_PRINT_INFO                 gw_info

//#define SWC_IPC_PRINT_WARNING              gw_warn

#define SWC_IPC_PRINT_DEBUG              	gw_warn

#define SWC_IPC_PRINT_INFO(...)

#define SWC_IPC_PRINT_WARNING(...)

#define SWC_IPC_PRINT_ERROR(...)

#define SWC_IPC_PRINT_VERBOSE             gw_verbose

#else

#define SWC_IPC_PRINT_INFO(...)

#define SWC_IPC_PRINT_WARNING(...)

#define SWC_IPC_PRINT_ERROR(...)

#define SWC_IPC_PRINT_VERBOSE(...)          

#endif
/**********************************************************************************************************
* IPC NVM Version Definenation                                                                            *
**********************************************************************************************************/

#define SWC_IPC_APP_CONFIG_NVM_VERSION     (2)

#define SWC_IPC_CAN_DATA_NVM_VERSION       (12)

/**********************************************************************************************************
* IPC Common Definenation                                                                                 *
**********************************************************************************************************/

#define SWC_IPC_NONE                       (0u)

#define SWC_IPC_NULL                       (NULL)

#define SWC_IPC_SET_BIT(OBJECT,BIT)        ((OBJECT) |= ( (1u) << (BIT)))

#define SWC_IPC_CLEAR_BIT(OBJECT,BIT)      ((OBJECT) &= ~((1u) << (BIT)))

#define SWC_IPC_GET_BIT(OBJECT,BIT)        (((OBJECT) >> (BIT)) & (1u))

#define SWC_IPC_TEST_BIT(OBJECT,BIT)       SWC_IPC_GET_BIT(OBJECT,BIT) ? TRUE:FALSE

#define SWC_IPC_MIN(A,B)       			   (((A)>(B))?(B):(A))

#define SWC_IPC_MAX(A,B)       			   (((A)>(B))?(A):(B))

/**********************************************************************************************************
* IPC Process Phase Definenation                                                                          *
**********************************************************************************************************/

#define SWC_IPC_CLEAR                      (0u)
#define SWC_IPC_TRIGGERED                  (1u)
#define SWC_IPC_RUNNING                    (2u)
#define SWC_IPC_DONE                       (3u)

/**********************************************************************************************************
* IPC Nvm Block Size Definenation                                                                         *
**********************************************************************************************************/

#define SWC_IPC_CONFIG_NVM_SIZE            (60u)

#define SWC_IPC_CAN_REPEATER_NVM_SIZE      (120u)

/**********************************************************************************************************
* IPC Direction Macro Definenation                                                                        *
**********************************************************************************************************/

#define SWC_IPC_MCU2SOC                    1u

#define SWC_IPC_SOC2MCU                    2u

/**********************************************************************************************************
* IPC Application Message Type Macro Definenation                                                         *
**********************************************************************************************************/

#define SWC_IPC_APP_MSG_TYPE_EVENT         1u

#define SWC_IPC_APP_MSG_TYPE_PERIODIC      2u

/**********************************************************************************************************
* IPC Task Cycle Configuration																			  *
**********************************************************************************************************/
/*Config in Vector Davinci tool , unit : ms*/

#define SWC_IPC_SWC_TASK_CYCLE             5u

#define SWC_IPC_MANAGER_TASK_CYCLE         SWC_IPC_SWC_TASK_CYCLE

#define SWC_IPC_CAN_REPEATER_TASK_CYCLE    SWC_IPC_SWC_TASK_CYCLE

#define SWC_IPC_APPLICATION_TASK_CYCLE     SWC_IPC_SWC_TASK_CYCLE

/**********************************************************************************************************
* WHUD Configuration																			          *
**********************************************************************************************************/

#define SWC_WHUD_DEFAULT_HIGHT_LEVEL         11

#define SWC_WHUD_DEFAULT_BACKLIGHT_LEVEL     5

#define SWC_WHUD_DEFAULT_ROTATION_LEVEL      6  /*Lv6*/

/**********************************************************************************************************
* Generate by Python Script																				  *
**********************************************************************************************************/
/*
 * Copyright (C) 2020 NOCH Group
 * File Name : SWC_IPC_APP_MSG_GEN
 * Author : Chen Yuanheng
 * Generate Date : 2022.01.18
*/

#ifndef SWC_IPC_APP_MSG_GEN
#define SWC_IPC_APP_MSG_GEN
/*
  Enum : IPC Application Node Message Configuration
*/
typedef enum
{
    SWC_IPC_APP_MSG_START_INDEX = -1 ,
    M2S_CLUSTER_POWER = 0 ,
    S2M_SET_MENU_REQ = 1 ,
    M2S_SET_MENU_RESP = 2 ,
    M2S_TELLTALE = 3 ,
    M2S_SAFTY_TELLTALE = 4 ,
    S2M_TELLTALE = 5 ,
    S2M_SELF_CHECK = 6 ,
    M2S_WARNING = 7 ,
    S2M_WARNING = 8 ,
    M2S_ODOMETER = 9 ,
    M2S_SIA = 10 ,
    M2S_GEAR = 11 ,
    M2S_TPMS = 12 ,
    M2S_CHIME = 13 ,
    S2M_CHIME = 14 ,
    M2S_FUEL = 15 ,
    M2S_TRIP_COMPUTER = 16 ,
    M2S_SPEEDOMETER = 17 ,
    M2S_TACHOMETER = 18 ,
    M2S_COOLANT = 19 ,
    M2S_IPC_LINK_TEST = 20 ,
    M2S_INTERNAL_CONFIG_UPLOAD = 21 ,
    M2S_SAFETY_TT_ACK = 22 ,
    S2M_SAFETY_TT_CRC = 23 ,
    M2S_SAFETY_GEAR_ACK = 24 ,
    S2M_SAFETY_GEAR_CRC = 25 ,
    M2S_SAFETY_APP_MSG_UPLOADED = 26 ,
    M2S_SAFETY_APP_RC = 27 ,
    S2M_SAFETY_APP_ALIVE = 28 ,
    M2S_COMMON_APP_MSG_UPLOADED = 29 ,
    S2M_COMMON_APP_ALIVE = 30 ,
    S2M_TC_CLEAR_REQ = 31 ,
    M2S_TC_CLEAR_RESP = 32 ,
    S2M_GAUGES_VALUE = 33 ,
    S2M_READ_ENGINEER_INFO_REQ = 34 ,
    M2S_READ_ENGINEER_INFO_RESP = 35 ,
    S2M_SET_ENGINEER_PARA_REQ = 36 ,
    M2S_SET_ENGINEER_PARA_RESP = 37 ,
    S2M_READ_SETTING_REQ = 38 ,
    M2S_READ_SETTING_RESP = 39 ,
    S2M_SET_SETTING_REQ = 40 ,
    M2S_SET_SETTING_RESP = 41 ,
    M2S_WHUD_MSG_UPLOADED = 42 ,
    S2M_WHUD_APP_ALIVE = 43 ,
    S2M_WHUD_NVM_CONFIG_REQ = 44 ,
    M2S_WHUD_NVM_CONFIG_RESP = 45 ,
    S2M_WHUD_SET_NVM_CONFIG = 46 ,
    S2M_RESTORE_FACTORY_REQ = 47 ,
    M2S_RESTORE_FACTORY_RESP = 48 ,
    S2M_READ_SERIAL_NUMBER_REQ = 49 ,
    M2S_READ_SERIAL_NUMBER_RESP = 50 ,
    M2S_INTERFACE_UPLOADED = 51 ,
    S2M_INTERFACE_ALIVE = 52 ,
    S2M_ADAS_STATUS = 53 ,
    S2M_HMI_POWER_MODE = 54 ,
    M2S_GAUGES_UPLOADED = 55 ,
    S2M_GAUGES_ALIVE = 56 ,
    S2M_READ_VIN_NUMBER_REQ = 57 ,
    M2S_READ_VIN_NUMBER_RESP = 58 ,
    S2M_CHIME_CLIENT_ALIVE = 59 ,
    M2S_APP_VCONFIG = 60 ,
    S2M_MENU_THEME_REQ = 61 ,
    M2S_MENU_THEME_RESP = 62 ,
    M2S_DRIVE_MODE_RESP = 63 ,
    M2S_ReadBeanID_RESP = 64 ,
    S2M_ReadBeanID_REQ = 65 ,
    M2S_WN_DATA = 66 ,
    M2S_NEWENERGY = 67 ,
    M2S_NEWENERGY_EV = 68 ,
    M2S_CA_CSA3_244_RESP = 69 ,
    M2S_CA_EEM1_2A8_RESP = 70 ,
    M2S_CA_ESP2_145_RESP = 71 ,
    M2S_CA_ESP2_137_RESP = 72 ,
    M2S_CA_HUD1_325_RESP = 73 ,
    M2S_CA_ECM3_371_RESP = 74 ,
    M2S_CA_CSA2_A1_RESP = 75 ,
    M2S_CA_ECM16_2D4_RESP = 76 ,
    M2S_CA_AC2_385_RESP = 77 ,
    M2S_CA_ECM_PT6_290_RESP = 78 ,
    M2S_CA_ABM2_245_RESP = 79 ,
    M2S_CA_RSDS_FD1_16F_RESP = 80 ,
    M2S_CA_IFC_FD5_19F_RESP = 81 ,
    M2S_CA_IFC_FD6_222_RESP = 82 ,
    M2S_CA_ACC_FD2_2AB_RESP = 83 ,
    M2S_CA_IFC_FD2_23D_RESP = 84 ,
    M2S_CA_AEB_FD2_227_RESP = 85 ,
    M2S_CA_CR_FD1_15E_RESP = 86 ,
    M2S_CA_IFC_FD3_2CF_RESP = 87 ,
    M2S_CA_ACC_FD3_2B4_RESP = 88 ,
    M2S_CA_BCM1_319_RESP = 89 ,
    M2S_CA_BCM3_345_RESP = 90 ,
    M2S_CA_T_Box_FD10_2F0_RESP = 91 ,
    S2M_WHUD_NVM_SET = 92 ,
    M2S_CA_ECM24_350_RESP = 93 ,
    M2S_CA_BCM12_238_RESP = 94 ,
    S2M_HMI_SAFETY_ALIVE = 95 ,
    S2M_SETAVASSWTST_REQ = 96 ,
    S2M_TtToChime_REQ = 97 ,
    M2S_CA_F_PBOX1_19B_RESP = 98 ,
    S2M_SET_OffroadInfo_REQ = 99 ,
    M2S_SET_OffroadInfo_RESP = 100 ,
    M2S_CA_HCM_L2_304_RESP = 101 ,
    M2S_CA_ESP1_149_RESP = 102 ,
    SWC_IPC_APP_MSG_TOTAL_NUMBER = 103 ,
}SWC_IPC_AppMsgList;

/*
  Define : IPC Application Node Message Length Configuration
*/
#define M2S_CLUSTER_POWER_LENGTH    sizeof(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t)
#define S2M_SET_MENU_REQ_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocMenuSetting_t)
#define M2S_SET_MENU_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppAPPMenuSetting_t)
#define M2S_TELLTALE_LENGTH    sizeof(IPC_M2S_ClusterAppAPPTT_Module_t)
#define M2S_SAFTY_TELLTALE_LENGTH    sizeof(IPC_M2S_SAFETYAPPTT_Safety_t)
#define S2M_TELLTALE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocTTStatus_t)
#define S2M_SELF_CHECK_LENGTH    sizeof(IPC_S2M_SAFETYAPPTTSelfCheck_t)
#define M2S_WARNING_LENGTH    sizeof(IPC_M2S_ClusterAppAPPWN_Module_t)
#define S2M_WARNING_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocWrnId_t)
#define M2S_ODOMETER_LENGTH    sizeof(IPC_M2S_ClusterAppAPPOdo_t)
#define M2S_SIA_LENGTH    sizeof(IPC_M2S_ClusterAppAPPSIA_t)
#define M2S_GEAR_LENGTH    sizeof(IPC_M2S_SAFETYAPPGear_t)
#define M2S_TPMS_LENGTH    sizeof(IPC_M2S_ClusterAppAPPTPMS_t)
#define M2S_CHIME_LENGTH    sizeof(IPC_M2S_ClusterAppAPPChime_t)
#define S2M_CHIME_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocBackChime_t)
#define M2S_FUEL_LENGTH    sizeof(IPC_M2S_ClusterAppAPPFUEL_t)
#define M2S_TRIP_COMPUTER_LENGTH    sizeof(IPC_M2S_ClusterAppAPPTripComputer_t)
#define M2S_SPEEDOMETER_LENGTH    sizeof(IPC_M2S_ClusterAppAPPSpeedo_t)
#define M2S_TACHOMETER_LENGTH    sizeof(IPC_M2S_ClusterAppAPPTacho_t)
#define M2S_COOLANT_LENGTH    sizeof(IPC_M2S_ClusterAppAPPCoolant_t)
#define M2S_IPC_LINK_TEST_LENGTH    sizeof(IPC_M2S_ClusterAppSystemIPCDebugTest_t)
#define M2S_INTERNAL_CONFIG_UPLOAD_LENGTH    sizeof(IPC_M2S_ClusterAppAPPConfigData_t)
#define M2S_SAFETY_TT_ACK_LENGTH    sizeof(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t)
#define S2M_SAFETY_TT_CRC_LENGTH    sizeof(IPC_S2M_SAFETYAPPSafetyTTCRC_t)
#define M2S_SAFETY_GEAR_ACK_LENGTH    sizeof(IPC_M2S_SAFETYAPPSafetyGearCheck_t)
#define S2M_SAFETY_GEAR_CRC_LENGTH    sizeof(IPC_S2M_SAFETYAPPSafetyGearCRC_t)
#define M2S_SAFETY_APP_MSG_UPLOADED_LENGTH    sizeof(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t)
#define M2S_SAFETY_APP_RC_LENGTH    sizeof(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t)
#define S2M_SAFETY_APP_ALIVE_LENGTH    sizeof(IPC_S2M_SAFETYAPPSafetyAppAlive_t)
#define M2S_COMMON_APP_MSG_UPLOADED_LENGTH    sizeof(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t)
#define S2M_COMMON_APP_ALIVE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocCommonAppAlive_t)
#define S2M_TC_CLEAR_REQ_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocTCClear_t)
#define M2S_TC_CLEAR_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppAPPTCClearResult_t)
#define S2M_GAUGES_VALUE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocGauges_t)
#define S2M_READ_ENGINEER_INFO_REQ_LENGTH    sizeof(IPC_S2M_EngineerIVIReadInfoRequest_t)
#define M2S_READ_ENGINEER_INFO_RESP_LENGTH    sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t)
#define S2M_SET_ENGINEER_PARA_REQ_LENGTH    sizeof(IPC_S2M_EngineerIVISetParaRequest_t)
#define M2S_SET_ENGINEER_PARA_RESP_LENGTH    sizeof(IPC_M2S_EngineerIVISetParaResponse_t)
#define S2M_READ_SETTING_REQ_LENGTH    sizeof(IPC_S2M_IVIAppInfoReadSettingSignalReq_t)
#define M2S_READ_SETTING_RESP_LENGTH    sizeof(IPC_M2S_IVIAppInfoReadSettingSignalResp_t)
#define S2M_SET_SETTING_REQ_LENGTH    sizeof(IPC_S2M_IVIAppInfoSetSettingSignalReq_t)
#define M2S_SET_SETTING_RESP_LENGTH    sizeof(IPC_M2S_IVIAppInfoSetSettingSignalResp_t)
#define M2S_WHUD_MSG_UPLOADED_LENGTH    sizeof(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t)
#define S2M_WHUD_APP_ALIVE_LENGTH    sizeof(IPC_S2M_HUDCommonAliveMsg_t)
#define S2M_WHUD_NVM_CONFIG_REQ_LENGTH    sizeof(IPC_S2M_HUDCommonNvmConfigRequset_t)
#define M2S_WHUD_NVM_CONFIG_RESP_LENGTH    sizeof(IPC_M2S_HUDCommonNvmConfigResponse_t)
#define S2M_WHUD_SET_NVM_CONFIG_LENGTH    sizeof(IPC_S2M_HUDCommonSetNvmConfig_t)
#define S2M_RESTORE_FACTORY_REQ_LENGTH    sizeof(IPC_S2M_InfraMiscRestoreFactorySettingRequset_t)
#define M2S_RESTORE_FACTORY_RESP_LENGTH    sizeof(IPC_M2S_InfraMiscRestoreFactorySettingResponse_t)
#define S2M_READ_SERIAL_NUMBER_REQ_LENGTH    sizeof(IPC_S2M_InfraMiscReadSerialNumberRequest_t)
#define M2S_READ_SERIAL_NUMBER_RESP_LENGTH    sizeof(IPC_M2S_InfraMiscReadSerialNumberResponse_t)
#define M2S_INTERFACE_UPLOADED_LENGTH    sizeof(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t)
#define S2M_INTERFACE_ALIVE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t)
#define S2M_ADAS_STATUS_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocAdasStatus_t)
#define S2M_HMI_POWER_MODE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocHMIPowerMode_t)
#define M2S_GAUGES_UPLOADED_LENGTH    sizeof(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t)
#define S2M_GAUGES_ALIVE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocGaugesAlive_t)
#define S2M_READ_VIN_NUMBER_REQ_LENGTH    sizeof(IPC_S2M_InfraMiscReadVINNumberRequest_t)
#define M2S_READ_VIN_NUMBER_RESP_LENGTH    sizeof(IPC_M2S_InfraMiscReadVINNumberResponse_t)
#define S2M_CHIME_CLIENT_ALIVE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocChimeClientAlive_t)
#define M2S_APP_VCONFIG_LENGTH    sizeof(IPC_M2S_ClusterAppAPPVConfig_t)
#define S2M_MENU_THEME_REQ_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t)
#define M2S_MENU_THEME_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t)
#define M2S_DRIVE_MODE_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppAPPDriveMode_t)
#define M2S_ReadBeanID_RESP_LENGTH    sizeof(IPC_M2S_InfraMiscReadBeanIDResponse_t)
#define S2M_ReadBeanID_REQ_LENGTH    sizeof(IPC_S2M_InfraMiscReadBeanIDRequest_t)
#define M2S_WN_DATA_LENGTH    sizeof(IPC_M2S_ClusterAppAPPWN_Data_t)
#define M2S_NEWENERGY_LENGTH    sizeof(IPC_M2S_ClusterAppAPPNewEnergy_t)
#define M2S_NEWENERGY_EV_LENGTH    sizeof(IPC_M2S_ClusterAppAPPNewEnergy_EV_t)
#define M2S_CA_CSA3_244_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptCSA3_244_t)
#define M2S_CA_EEM1_2A8_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t)
#define M2S_CA_ESP2_145_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptESP2_145_t)
#define M2S_CA_ESP2_137_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptESP2_137_t)
#define M2S_CA_HUD1_325_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptHUD1_325_t)
#define M2S_CA_ECM3_371_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptECM3_371_t)
#define M2S_CA_CSA2_A1_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t)
#define M2S_CA_ECM16_2D4_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t)
#define M2S_CA_AC2_385_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptAC2_385_t)
#define M2S_CA_ECM_PT6_290_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t)
#define M2S_CA_ABM2_245_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptABM2_245_t)
#define M2S_CA_RSDS_FD1_16F_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t)
#define M2S_CA_IFC_FD5_19F_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t)
#define M2S_CA_IFC_FD6_222_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t)
#define M2S_CA_ACC_FD2_2AB_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t)
#define M2S_CA_IFC_FD2_23D_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t)
#define M2S_CA_AEB_FD2_227_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t)
#define M2S_CA_CR_FD1_15E_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t)
#define M2S_CA_IFC_FD3_2CF_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t)
#define M2S_CA_ACC_FD3_2B4_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t)
#define M2S_CA_BCM1_319_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptBCM1_319_t)
#define M2S_CA_BCM3_345_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptBCM3_345_t)
#define M2S_CA_T_Box_FD10_2F0_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t)
#define S2M_WHUD_NVM_SET_LENGTH    sizeof(IPC_S2M_HUDCommonWhudNvmSet_t)
#define M2S_CA_ECM24_350_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptECM24_350_t)
#define M2S_CA_BCM12_238_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptBCM12_238_t)
#define S2M_HMI_SAFETY_ALIVE_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocHMISafety_t)
#define S2M_SETAVASSWTST_REQ_LENGTH    sizeof(IPC_S2M_InfraMiscSetAVASSwitchStatus_t)
#define S2M_TtToChime_REQ_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocTtToChime_t)
#define M2S_CA_F_PBOX1_19B_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t)
#define S2M_SET_OffroadInfo_REQ_LENGTH    sizeof(IPC_S2M_ClusterAppClusterSocOffroadInfo_t)
#define M2S_SET_OffroadInfo_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppAPPOffroadInfo_t)
#define M2S_CA_HCM_L2_304_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t)
#define M2S_CA_ESP1_149_RESP_LENGTH    sizeof(IPC_M2S_ClusterAppCANAdaptESP1_149_t)

/*
  Define : IPC Application Node Message Buffer Offset Configuration
*/
#define SWC_IPC_APP_MSG_DATA_BUFFER_START    0u
#define M2S_CLUSTER_POWER_OFFSET    (SWC_IPC_APP_MSG_DATA_BUFFER_START)
#define S2M_SET_MENU_REQ_OFFSET    (M2S_CLUSTER_POWER_OFFSET + M2S_CLUSTER_POWER_LENGTH)
#define M2S_SET_MENU_RESP_OFFSET    (S2M_SET_MENU_REQ_OFFSET + S2M_SET_MENU_REQ_LENGTH)
#define M2S_TELLTALE_OFFSET    (M2S_SET_MENU_RESP_OFFSET + M2S_SET_MENU_RESP_LENGTH)
#define M2S_SAFTY_TELLTALE_OFFSET    (M2S_TELLTALE_OFFSET + M2S_TELLTALE_LENGTH)
#define S2M_TELLTALE_OFFSET    (M2S_SAFTY_TELLTALE_OFFSET + M2S_SAFTY_TELLTALE_LENGTH)
#define S2M_SELF_CHECK_OFFSET    (S2M_TELLTALE_OFFSET + S2M_TELLTALE_LENGTH)
#define M2S_WARNING_OFFSET    (S2M_SELF_CHECK_OFFSET + S2M_SELF_CHECK_LENGTH)
#define S2M_WARNING_OFFSET    (M2S_WARNING_OFFSET + M2S_WARNING_LENGTH)
#define M2S_ODOMETER_OFFSET    (S2M_WARNING_OFFSET + S2M_WARNING_LENGTH)
#define M2S_SIA_OFFSET    (M2S_ODOMETER_OFFSET + M2S_ODOMETER_LENGTH)
#define M2S_GEAR_OFFSET    (M2S_SIA_OFFSET + M2S_SIA_LENGTH)
#define M2S_TPMS_OFFSET    (M2S_GEAR_OFFSET + M2S_GEAR_LENGTH)
#define M2S_CHIME_OFFSET    (M2S_TPMS_OFFSET + M2S_TPMS_LENGTH)
#define S2M_CHIME_OFFSET    (M2S_CHIME_OFFSET + M2S_CHIME_LENGTH)
#define M2S_FUEL_OFFSET    (S2M_CHIME_OFFSET + S2M_CHIME_LENGTH)
#define M2S_TRIP_COMPUTER_OFFSET    (M2S_FUEL_OFFSET + M2S_FUEL_LENGTH)
#define M2S_SPEEDOMETER_OFFSET    (M2S_TRIP_COMPUTER_OFFSET + M2S_TRIP_COMPUTER_LENGTH)
#define M2S_TACHOMETER_OFFSET    (M2S_SPEEDOMETER_OFFSET + M2S_SPEEDOMETER_LENGTH)
#define M2S_COOLANT_OFFSET    (M2S_TACHOMETER_OFFSET + M2S_TACHOMETER_LENGTH)
#define M2S_IPC_LINK_TEST_OFFSET    (M2S_COOLANT_OFFSET + M2S_COOLANT_LENGTH)
#define M2S_INTERNAL_CONFIG_UPLOAD_OFFSET    (M2S_IPC_LINK_TEST_OFFSET + M2S_IPC_LINK_TEST_LENGTH)
#define M2S_SAFETY_TT_ACK_OFFSET    (M2S_INTERNAL_CONFIG_UPLOAD_OFFSET + M2S_INTERNAL_CONFIG_UPLOAD_LENGTH)
#define S2M_SAFETY_TT_CRC_OFFSET    (M2S_SAFETY_TT_ACK_OFFSET + M2S_SAFETY_TT_ACK_LENGTH)
#define M2S_SAFETY_GEAR_ACK_OFFSET    (S2M_SAFETY_TT_CRC_OFFSET + S2M_SAFETY_TT_CRC_LENGTH)
#define S2M_SAFETY_GEAR_CRC_OFFSET    (M2S_SAFETY_GEAR_ACK_OFFSET + M2S_SAFETY_GEAR_ACK_LENGTH)
#define M2S_SAFETY_APP_MSG_UPLOADED_OFFSET    (S2M_SAFETY_GEAR_CRC_OFFSET + S2M_SAFETY_GEAR_CRC_LENGTH)
#define M2S_SAFETY_APP_RC_OFFSET    (M2S_SAFETY_APP_MSG_UPLOADED_OFFSET + M2S_SAFETY_APP_MSG_UPLOADED_LENGTH)
#define S2M_SAFETY_APP_ALIVE_OFFSET    (M2S_SAFETY_APP_RC_OFFSET + M2S_SAFETY_APP_RC_LENGTH)
#define M2S_COMMON_APP_MSG_UPLOADED_OFFSET    (S2M_SAFETY_APP_ALIVE_OFFSET + S2M_SAFETY_APP_ALIVE_LENGTH)
#define S2M_COMMON_APP_ALIVE_OFFSET    (M2S_COMMON_APP_MSG_UPLOADED_OFFSET + M2S_COMMON_APP_MSG_UPLOADED_LENGTH)
#define S2M_TC_CLEAR_REQ_OFFSET    (S2M_COMMON_APP_ALIVE_OFFSET + S2M_COMMON_APP_ALIVE_LENGTH)
#define M2S_TC_CLEAR_RESP_OFFSET    (S2M_TC_CLEAR_REQ_OFFSET + S2M_TC_CLEAR_REQ_LENGTH)
#define S2M_GAUGES_VALUE_OFFSET    (M2S_TC_CLEAR_RESP_OFFSET + M2S_TC_CLEAR_RESP_LENGTH)
#define S2M_READ_ENGINEER_INFO_REQ_OFFSET    (S2M_GAUGES_VALUE_OFFSET + S2M_GAUGES_VALUE_LENGTH)
#define M2S_READ_ENGINEER_INFO_RESP_OFFSET    (S2M_READ_ENGINEER_INFO_REQ_OFFSET + S2M_READ_ENGINEER_INFO_REQ_LENGTH)
#define S2M_SET_ENGINEER_PARA_REQ_OFFSET    (M2S_READ_ENGINEER_INFO_RESP_OFFSET + M2S_READ_ENGINEER_INFO_RESP_LENGTH)
#define M2S_SET_ENGINEER_PARA_RESP_OFFSET    (S2M_SET_ENGINEER_PARA_REQ_OFFSET + S2M_SET_ENGINEER_PARA_REQ_LENGTH)
#define S2M_READ_SETTING_REQ_OFFSET    (M2S_SET_ENGINEER_PARA_RESP_OFFSET + M2S_SET_ENGINEER_PARA_RESP_LENGTH)
#define M2S_READ_SETTING_RESP_OFFSET    (S2M_READ_SETTING_REQ_OFFSET + S2M_READ_SETTING_REQ_LENGTH)
#define S2M_SET_SETTING_REQ_OFFSET    (M2S_READ_SETTING_RESP_OFFSET + M2S_READ_SETTING_RESP_LENGTH)
#define M2S_SET_SETTING_RESP_OFFSET    (S2M_SET_SETTING_REQ_OFFSET + S2M_SET_SETTING_REQ_LENGTH)
#define M2S_WHUD_MSG_UPLOADED_OFFSET    (M2S_SET_SETTING_RESP_OFFSET + M2S_SET_SETTING_RESP_LENGTH)
#define S2M_WHUD_APP_ALIVE_OFFSET    (M2S_WHUD_MSG_UPLOADED_OFFSET + M2S_WHUD_MSG_UPLOADED_LENGTH)
#define S2M_WHUD_NVM_CONFIG_REQ_OFFSET    (S2M_WHUD_APP_ALIVE_OFFSET + S2M_WHUD_APP_ALIVE_LENGTH)
#define M2S_WHUD_NVM_CONFIG_RESP_OFFSET    (S2M_WHUD_NVM_CONFIG_REQ_OFFSET + S2M_WHUD_NVM_CONFIG_REQ_LENGTH)
#define S2M_WHUD_SET_NVM_CONFIG_OFFSET    (M2S_WHUD_NVM_CONFIG_RESP_OFFSET + M2S_WHUD_NVM_CONFIG_RESP_LENGTH)
#define S2M_RESTORE_FACTORY_REQ_OFFSET    (S2M_WHUD_SET_NVM_CONFIG_OFFSET + S2M_WHUD_SET_NVM_CONFIG_LENGTH)
#define M2S_RESTORE_FACTORY_RESP_OFFSET    (S2M_RESTORE_FACTORY_REQ_OFFSET + S2M_RESTORE_FACTORY_REQ_LENGTH)
#define S2M_READ_SERIAL_NUMBER_REQ_OFFSET    (M2S_RESTORE_FACTORY_RESP_OFFSET + M2S_RESTORE_FACTORY_RESP_LENGTH)
#define M2S_READ_SERIAL_NUMBER_RESP_OFFSET    (S2M_READ_SERIAL_NUMBER_REQ_OFFSET + S2M_READ_SERIAL_NUMBER_REQ_LENGTH)
#define M2S_INTERFACE_UPLOADED_OFFSET    (M2S_READ_SERIAL_NUMBER_RESP_OFFSET + M2S_READ_SERIAL_NUMBER_RESP_LENGTH)
#define S2M_INTERFACE_ALIVE_OFFSET    (M2S_INTERFACE_UPLOADED_OFFSET + M2S_INTERFACE_UPLOADED_LENGTH)
#define S2M_ADAS_STATUS_OFFSET    (S2M_INTERFACE_ALIVE_OFFSET + S2M_INTERFACE_ALIVE_LENGTH)
#define S2M_HMI_POWER_MODE_OFFSET    (S2M_ADAS_STATUS_OFFSET + S2M_ADAS_STATUS_LENGTH)
#define M2S_GAUGES_UPLOADED_OFFSET    (S2M_HMI_POWER_MODE_OFFSET + S2M_HMI_POWER_MODE_LENGTH)
#define S2M_GAUGES_ALIVE_OFFSET    (M2S_GAUGES_UPLOADED_OFFSET + M2S_GAUGES_UPLOADED_LENGTH)
#define S2M_READ_VIN_NUMBER_REQ_OFFSET    (S2M_GAUGES_ALIVE_OFFSET + S2M_GAUGES_ALIVE_LENGTH)
#define M2S_READ_VIN_NUMBER_RESP_OFFSET    (S2M_READ_VIN_NUMBER_REQ_OFFSET + S2M_READ_VIN_NUMBER_REQ_LENGTH)
#define S2M_CHIME_CLIENT_ALIVE_OFFSET    (M2S_READ_VIN_NUMBER_RESP_OFFSET + M2S_READ_VIN_NUMBER_RESP_LENGTH)
#define M2S_APP_VCONFIG_OFFSET    (S2M_CHIME_CLIENT_ALIVE_OFFSET + S2M_CHIME_CLIENT_ALIVE_LENGTH)
#define S2M_MENU_THEME_REQ_OFFSET    (M2S_APP_VCONFIG_OFFSET + M2S_APP_VCONFIG_LENGTH)
#define M2S_MENU_THEME_RESP_OFFSET    (S2M_MENU_THEME_REQ_OFFSET + S2M_MENU_THEME_REQ_LENGTH)
#define M2S_DRIVE_MODE_RESP_OFFSET    (M2S_MENU_THEME_RESP_OFFSET + M2S_MENU_THEME_RESP_LENGTH)
#define M2S_ReadBeanID_RESP_OFFSET    (M2S_DRIVE_MODE_RESP_OFFSET + M2S_DRIVE_MODE_RESP_LENGTH)
#define S2M_ReadBeanID_REQ_OFFSET    (M2S_ReadBeanID_RESP_OFFSET + M2S_ReadBeanID_RESP_LENGTH)
#define M2S_WN_DATA_OFFSET    (S2M_ReadBeanID_REQ_OFFSET + S2M_ReadBeanID_REQ_LENGTH)
#define M2S_NEWENERGY_OFFSET    (M2S_WN_DATA_OFFSET + M2S_WN_DATA_LENGTH)
#define M2S_NEWENERGY_EV_OFFSET    (M2S_NEWENERGY_OFFSET + M2S_NEWENERGY_LENGTH)
#define M2S_CA_CSA3_244_RESP_OFFSET    (M2S_NEWENERGY_EV_OFFSET + M2S_NEWENERGY_EV_LENGTH)
#define M2S_CA_EEM1_2A8_RESP_OFFSET    (M2S_CA_CSA3_244_RESP_OFFSET + M2S_CA_CSA3_244_RESP_LENGTH)
#define M2S_CA_ESP2_145_RESP_OFFSET    (M2S_CA_EEM1_2A8_RESP_OFFSET + M2S_CA_EEM1_2A8_RESP_LENGTH)
#define M2S_CA_ESP2_137_RESP_OFFSET    (M2S_CA_ESP2_145_RESP_OFFSET + M2S_CA_ESP2_145_RESP_LENGTH)
#define M2S_CA_HUD1_325_RESP_OFFSET    (M2S_CA_ESP2_137_RESP_OFFSET + M2S_CA_ESP2_137_RESP_LENGTH)
#define M2S_CA_ECM3_371_RESP_OFFSET    (M2S_CA_HUD1_325_RESP_OFFSET + M2S_CA_HUD1_325_RESP_LENGTH)
#define M2S_CA_CSA2_A1_RESP_OFFSET    (M2S_CA_ECM3_371_RESP_OFFSET + M2S_CA_ECM3_371_RESP_LENGTH)
#define M2S_CA_ECM16_2D4_RESP_OFFSET    (M2S_CA_CSA2_A1_RESP_OFFSET + M2S_CA_CSA2_A1_RESP_LENGTH)
#define M2S_CA_AC2_385_RESP_OFFSET    (M2S_CA_ECM16_2D4_RESP_OFFSET + M2S_CA_ECM16_2D4_RESP_LENGTH)
#define M2S_CA_ECM_PT6_290_RESP_OFFSET    (M2S_CA_AC2_385_RESP_OFFSET + M2S_CA_AC2_385_RESP_LENGTH)
#define M2S_CA_ABM2_245_RESP_OFFSET    (M2S_CA_ECM_PT6_290_RESP_OFFSET + M2S_CA_ECM_PT6_290_RESP_LENGTH)
#define M2S_CA_RSDS_FD1_16F_RESP_OFFSET    (M2S_CA_ABM2_245_RESP_OFFSET + M2S_CA_ABM2_245_RESP_LENGTH)
#define M2S_CA_IFC_FD5_19F_RESP_OFFSET    (M2S_CA_RSDS_FD1_16F_RESP_OFFSET + M2S_CA_RSDS_FD1_16F_RESP_LENGTH)
#define M2S_CA_IFC_FD6_222_RESP_OFFSET    (M2S_CA_IFC_FD5_19F_RESP_OFFSET + M2S_CA_IFC_FD5_19F_RESP_LENGTH)
#define M2S_CA_ACC_FD2_2AB_RESP_OFFSET    (M2S_CA_IFC_FD6_222_RESP_OFFSET + M2S_CA_IFC_FD6_222_RESP_LENGTH)
#define M2S_CA_IFC_FD2_23D_RESP_OFFSET    (M2S_CA_ACC_FD2_2AB_RESP_OFFSET + M2S_CA_ACC_FD2_2AB_RESP_LENGTH)
#define M2S_CA_AEB_FD2_227_RESP_OFFSET    (M2S_CA_IFC_FD2_23D_RESP_OFFSET + M2S_CA_IFC_FD2_23D_RESP_LENGTH)
#define M2S_CA_CR_FD1_15E_RESP_OFFSET    (M2S_CA_AEB_FD2_227_RESP_OFFSET + M2S_CA_AEB_FD2_227_RESP_LENGTH)
#define M2S_CA_IFC_FD3_2CF_RESP_OFFSET    (M2S_CA_CR_FD1_15E_RESP_OFFSET + M2S_CA_CR_FD1_15E_RESP_LENGTH)
#define M2S_CA_ACC_FD3_2B4_RESP_OFFSET    (M2S_CA_IFC_FD3_2CF_RESP_OFFSET + M2S_CA_IFC_FD3_2CF_RESP_LENGTH)
#define M2S_CA_BCM1_319_RESP_OFFSET    (M2S_CA_ACC_FD3_2B4_RESP_OFFSET + M2S_CA_ACC_FD3_2B4_RESP_LENGTH)
#define M2S_CA_BCM3_345_RESP_OFFSET    (M2S_CA_BCM1_319_RESP_OFFSET + M2S_CA_BCM1_319_RESP_LENGTH)
#define M2S_CA_T_Box_FD10_2F0_RESP_OFFSET    (M2S_CA_BCM3_345_RESP_OFFSET + M2S_CA_BCM3_345_RESP_LENGTH)
#define S2M_WHUD_NVM_SET_OFFSET    (M2S_CA_T_Box_FD10_2F0_RESP_OFFSET + M2S_CA_T_Box_FD10_2F0_RESP_LENGTH)
#define M2S_CA_ECM24_350_RESP_OFFSET    (S2M_WHUD_NVM_SET_OFFSET + S2M_WHUD_NVM_SET_LENGTH)
#define M2S_CA_BCM12_238_RESP_OFFSET    (M2S_CA_ECM24_350_RESP_OFFSET + M2S_CA_ECM24_350_RESP_LENGTH)
#define S2M_HMI_SAFETY_ALIVE_OFFSET    (M2S_CA_BCM12_238_RESP_OFFSET + M2S_CA_BCM12_238_RESP_LENGTH)
#define S2M_SETAVASSWTST_REQ_OFFSET    (S2M_HMI_SAFETY_ALIVE_OFFSET + S2M_HMI_SAFETY_ALIVE_LENGTH)
#define S2M_TtToChime_REQ_OFFSET    (S2M_SETAVASSWTST_REQ_OFFSET + S2M_SETAVASSWTST_REQ_LENGTH)
#define M2S_CA_F_PBOX1_19B_RESP_OFFSET    (S2M_TtToChime_REQ_OFFSET + S2M_TtToChime_REQ_LENGTH)
#define S2M_SET_OffroadInfo_REQ_OFFSET    (M2S_CA_F_PBOX1_19B_RESP_OFFSET + M2S_CA_F_PBOX1_19B_RESP_LENGTH)
#define M2S_SET_OffroadInfo_RESP_OFFSET    (S2M_SET_OffroadInfo_REQ_OFFSET + S2M_SET_OffroadInfo_REQ_LENGTH)
#define M2S_CA_HCM_L2_304_RESP_OFFSET    (M2S_SET_OffroadInfo_RESP_OFFSET + M2S_SET_OffroadInfo_RESP_LENGTH)
#define M2S_CA_ESP1_149_RESP_OFFSET    (M2S_CA_HCM_L2_304_RESP_OFFSET + M2S_CA_HCM_L2_304_RESP_LENGTH)
#define SWC_IPC_APP_MSG_DATA_BUFFER_LENGTH    (uint32)(M2S_CA_ESP1_149_RESP_OFFSET + M2S_CA_ESP1_149_RESP_LENGTH)

/*
  Define : IPC Application Message Attribute Configuration
*/
#define SWC_IPC_APP_MSG_ATTRIBUTE_TABLE     \
    { \
        {/*M2S_CLUSTER_POWER*/  \
        /*Offset    */(uint16)(M2S_CLUSTER_POWER_OFFSET), \
        /*Length    */(uint16)(M2S_CLUSTER_POWER_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppSystemCLUSTERPOWER_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SET_MENU_REQ*/  \
        /*Offset    */(uint16)(S2M_SET_MENU_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_SET_MENU_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocMenuSetting_Receive) , \
        /*Callback  */ svCS_SWCNormal_ReceiveMenuSetting_Callback , \
        }, \
        {/*M2S_SET_MENU_RESP*/  \
        /*Offset    */(uint16)(M2S_SET_MENU_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_SET_MENU_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPMenuSetting_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_TELLTALE*/  \
        /*Offset    */(uint16)(M2S_TELLTALE_OFFSET), \
        /*Length    */(uint16)(M2S_TELLTALE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPTT_Module_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_SAFTY_TELLTALE*/  \
        /*Offset    */(uint16)(M2S_SAFTY_TELLTALE_OFFSET), \
        /*Length    */(uint16)(M2S_SAFTY_TELLTALE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYAPPTT_Safety_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_TELLTALE*/  \
        /*Offset    */(uint16)(S2M_TELLTALE_OFFSET), \
        /*Length    */(uint16)(S2M_TELLTALE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocTTStatus_Receive) , \
        /*Callback  */ svCS_SWCNormal_TTCallback_Operation , \
        }, \
        {/*S2M_SELF_CHECK*/  \
        /*Offset    */(uint16)(S2M_SELF_CHECK_OFFSET), \
        /*Length    */(uint16)(S2M_SELF_CHECK_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_SAFETYAPPTTSelfCheck_Receive) , \
        /*Callback  */ svCS_SWCSafety_TTCallback_Operation , \
        }, \
        {/*M2S_WARNING*/  \
        /*Offset    */(uint16)(M2S_WARNING_OFFSET), \
        /*Length    */(uint16)(M2S_WARNING_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPWN_Module_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_WARNING*/  \
        /*Offset    */(uint16)(S2M_WARNING_OFFSET), \
        /*Length    */(uint16)(S2M_WARNING_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocWrnId_Receive) , \
        /*Callback  */ svCS_SWCNormal_WrnCallback_Operation , \
        }, \
        {/*M2S_ODOMETER*/  \
        /*Offset    */(uint16)(M2S_ODOMETER_OFFSET), \
        /*Length    */(uint16)(M2S_ODOMETER_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPOdo_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_SIA*/  \
        /*Offset    */(uint16)(M2S_SIA_OFFSET), \
        /*Length    */(uint16)(M2S_SIA_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPSIA_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_GEAR*/  \
        /*Offset    */(uint16)(M2S_GEAR_OFFSET), \
        /*Length    */(uint16)(M2S_GEAR_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYAPPGear_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_TPMS*/  \
        /*Offset    */(uint16)(M2S_TPMS_OFFSET), \
        /*Length    */(uint16)(M2S_TPMS_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPTPMS_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CHIME*/  \
        /*Offset    */(uint16)(M2S_CHIME_OFFSET), \
        /*Length    */(uint16)(M2S_CHIME_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPChime_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_CHIME*/  \
        /*Offset    */(uint16)(S2M_CHIME_OFFSET), \
        /*Length    */(uint16)(S2M_CHIME_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocBackChime_Receive) , \
        /*Callback  */ svCS_SWCNormal_ChimeCallback_Operation , \
        }, \
        {/*M2S_FUEL*/  \
        /*Offset    */(uint16)(M2S_FUEL_OFFSET), \
        /*Length    */(uint16)(M2S_FUEL_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPFUEL_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_TRIP_COMPUTER*/  \
        /*Offset    */(uint16)(M2S_TRIP_COMPUTER_OFFSET), \
        /*Length    */(uint16)(M2S_TRIP_COMPUTER_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPTripComputer_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_SPEEDOMETER*/  \
        /*Offset    */(uint16)(M2S_SPEEDOMETER_OFFSET), \
        /*Length    */(uint16)(M2S_SPEEDOMETER_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPSpeedo_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_TACHOMETER*/  \
        /*Offset    */(uint16)(M2S_TACHOMETER_OFFSET), \
        /*Length    */(uint16)(M2S_TACHOMETER_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPTacho_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_COOLANT*/  \
        /*Offset    */(uint16)(M2S_COOLANT_OFFSET), \
        /*Length    */(uint16)(M2S_COOLANT_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPCoolant_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_IPC_LINK_TEST*/  \
        /*Offset    */(uint16)(M2S_IPC_LINK_TEST_OFFSET), \
        /*Length    */(uint16)(M2S_IPC_LINK_TEST_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_PERIODIC) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppSystemIPCDebugTest_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_INTERNAL_CONFIG_UPLOAD*/  \
        /*Offset    */(uint16)(M2S_INTERNAL_CONFIG_UPLOAD_OFFSET), \
        /*Length    */(uint16)(M2S_INTERNAL_CONFIG_UPLOAD_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPConfigData_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_SAFETY_TT_ACK*/  \
        /*Offset    */(uint16)(M2S_SAFETY_TT_ACK_OFFSET), \
        /*Length    */(uint16)(M2S_SAFETY_TT_ACK_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SAFETY_TT_CRC*/  \
        /*Offset    */(uint16)(S2M_SAFETY_TT_CRC_OFFSET), \
        /*Length    */(uint16)(S2M_SAFETY_TT_CRC_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_SAFETYAPPSafetyTTCRC_Receive) , \
        /*Callback  */ svCS_SWCSafety_ReceiveSafetyTTCRC_Callback , \
        }, \
        {/*M2S_SAFETY_GEAR_ACK*/  \
        /*Offset    */(uint16)(M2S_SAFETY_GEAR_ACK_OFFSET), \
        /*Length    */(uint16)(M2S_SAFETY_GEAR_ACK_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYAPPSafetyGearCheck_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SAFETY_GEAR_CRC*/  \
        /*Offset    */(uint16)(S2M_SAFETY_GEAR_CRC_OFFSET), \
        /*Length    */(uint16)(S2M_SAFETY_GEAR_CRC_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_SAFETYAPPSafetyGearCRC_Receive) , \
        /*Callback  */ svCS_SWCSafety_ReceiveSafetyGearCRC_Callback , \
        }, \
        {/*M2S_SAFETY_APP_MSG_UPLOADED*/  \
        /*Offset    */(uint16)(M2S_SAFETY_APP_MSG_UPLOADED_OFFSET), \
        /*Length    */(uint16)(M2S_SAFETY_APP_MSG_UPLOADED_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_SAFETY_APP_RC*/  \
        /*Offset    */(uint16)(M2S_SAFETY_APP_RC_OFFSET), \
        /*Length    */(uint16)(M2S_SAFETY_APP_RC_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SAFETY_APP_ALIVE*/  \
        /*Offset    */(uint16)(S2M_SAFETY_APP_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_SAFETY_APP_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_SAFETYAPPSafetyAppAlive_Receive) , \
        /*Callback  */ IPC_API_GetSafetyAppAliveCallback , \
        }, \
        {/*M2S_COMMON_APP_MSG_UPLOADED*/  \
        /*Offset    */(uint16)(M2S_COMMON_APP_MSG_UPLOADED_OFFSET), \
        /*Length    */(uint16)(M2S_COMMON_APP_MSG_UPLOADED_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_COMMON_APP_ALIVE*/  \
        /*Offset    */(uint16)(S2M_COMMON_APP_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_COMMON_APP_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocCommonAppAlive_Receive) , \
        /*Callback  */ IPC_API_GetCommonAppAliveCallback , \
        }, \
        {/*S2M_TC_CLEAR_REQ*/  \
        /*Offset    */(uint16)(S2M_TC_CLEAR_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_TC_CLEAR_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocTCClear_Receive) , \
        /*Callback  */ svCS_SWCNormal_HMIResetTC_Callback , \
        }, \
        {/*M2S_TC_CLEAR_RESP*/  \
        /*Offset    */(uint16)(M2S_TC_CLEAR_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_TC_CLEAR_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPTCClearResult_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_GAUGES_VALUE*/  \
        /*Offset    */(uint16)(S2M_GAUGES_VALUE_OFFSET), \
        /*Length    */(uint16)(S2M_GAUGES_VALUE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocGauges_Receive) , \
        /*Callback  */ IPC_API_WriteGaugesValueCallback , \
        }, \
        {/*S2M_READ_ENGINEER_INFO_REQ*/  \
        /*Offset    */(uint16)(S2M_READ_ENGINEER_INFO_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_READ_ENGINEER_INFO_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_EngineerIVIReadInfoRequest_Receive) , \
        /*Callback  */ IPC_API_ReadEngineerInfoCallback , \
        }, \
        {/*M2S_READ_ENGINEER_INFO_RESP*/  \
        /*Offset    */(uint16)(M2S_READ_ENGINEER_INFO_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_READ_ENGINEER_INFO_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_EngineerIVIReadInfoResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SET_ENGINEER_PARA_REQ*/  \
        /*Offset    */(uint16)(S2M_SET_ENGINEER_PARA_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_SET_ENGINEER_PARA_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_EngineerIVISetParaRequest_Receive) , \
        /*Callback  */ IPC_API_WriteEngineerInfoCallback , \
        }, \
        {/*M2S_SET_ENGINEER_PARA_RESP*/  \
        /*Offset    */(uint16)(M2S_SET_ENGINEER_PARA_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_SET_ENGINEER_PARA_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_EngineerIVISetParaResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_READ_SETTING_REQ*/  \
        /*Offset    */(uint16)(S2M_READ_SETTING_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_READ_SETTING_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_IVIAppInfoReadSettingSignalReq_Receive) , \
        /*Callback  */ IPC_API_ReadCommonInfoCallback , \
        }, \
        {/*M2S_READ_SETTING_RESP*/  \
        /*Offset    */(uint16)(M2S_READ_SETTING_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_READ_SETTING_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_IVIAppInfoReadSettingSignalResp_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SET_SETTING_REQ*/  \
        /*Offset    */(uint16)(S2M_SET_SETTING_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_SET_SETTING_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_IVIAppInfoSetSettingSignalReq_Receive) , \
        /*Callback  */ IPC_API_WriteCommonInfoCallback , \
        }, \
        {/*M2S_SET_SETTING_RESP*/  \
        /*Offset    */(uint16)(M2S_SET_SETTING_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_SET_SETTING_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_IVIAppInfoSetSettingSignalResp_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_WHUD_MSG_UPLOADED*/  \
        /*Offset    */(uint16)(M2S_WHUD_MSG_UPLOADED_OFFSET), \
        /*Length    */(uint16)(M2S_WHUD_MSG_UPLOADED_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_WHUD_APP_ALIVE*/  \
        /*Offset    */(uint16)(S2M_WHUD_APP_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_WHUD_APP_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_HUDCommonAliveMsg_Receive) , \
        /*Callback  */ IPC_API_GetWhudAliveCallback , \
        }, \
        {/*S2M_WHUD_NVM_CONFIG_REQ*/  \
        /*Offset    */(uint16)(S2M_WHUD_NVM_CONFIG_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_WHUD_NVM_CONFIG_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_HUDCommonNvmConfigRequset_Receive) , \
        /*Callback  */ IPC_API_GetWhudNvmConfigCallback , \
        }, \
        {/*M2S_WHUD_NVM_CONFIG_RESP*/  \
        /*Offset    */(uint16)(M2S_WHUD_NVM_CONFIG_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_WHUD_NVM_CONFIG_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_HUDCommonNvmConfigResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_WHUD_SET_NVM_CONFIG*/  \
        /*Offset    */(uint16)(S2M_WHUD_SET_NVM_CONFIG_OFFSET), \
        /*Length    */(uint16)(S2M_WHUD_SET_NVM_CONFIG_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_HUDCommonSetNvmConfig_Receive) , \
        /*Callback  */ IPC_API_SetWhudNvmConfigCallback , \
        }, \
        {/*S2M_RESTORE_FACTORY_REQ*/  \
        /*Offset    */(uint16)(S2M_RESTORE_FACTORY_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_RESTORE_FACTORY_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_InfraMiscRestoreFactorySettingRequset_Receive) , \
        /*Callback  */ IPC_API_SetRestoreSettingCallback , \
        }, \
        {/*M2S_RESTORE_FACTORY_RESP*/  \
        /*Offset    */(uint16)(M2S_RESTORE_FACTORY_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_RESTORE_FACTORY_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_InfraMiscRestoreFactorySettingResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_READ_SERIAL_NUMBER_REQ*/  \
        /*Offset    */(uint16)(S2M_READ_SERIAL_NUMBER_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_READ_SERIAL_NUMBER_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_InfraMiscReadSerialNumberRequest_Receive) , \
        /*Callback  */ IPC_API_ReadSerialNumberCallback , \
        }, \
        {/*M2S_READ_SERIAL_NUMBER_RESP*/  \
        /*Offset    */(uint16)(M2S_READ_SERIAL_NUMBER_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_READ_SERIAL_NUMBER_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_InfraMiscReadSerialNumberResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_INTERFACE_UPLOADED*/  \
        /*Offset    */(uint16)(M2S_INTERFACE_UPLOADED_OFFSET), \
        /*Length    */(uint16)(M2S_INTERFACE_UPLOADED_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_INTERFACE_ALIVE*/  \
        /*Offset    */(uint16)(S2M_INTERFACE_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_INTERFACE_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Receive) , \
        /*Callback  */ IPC_API_GetInterfaceAppAliveCallback , \
        }, \
        {/*S2M_ADAS_STATUS*/  \
        /*Offset    */(uint16)(S2M_ADAS_STATUS_OFFSET), \
        /*Length    */(uint16)(S2M_ADAS_STATUS_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocAdasStatus_Receive) , \
        /*Callback  */ Rte_Call_rpCS_SWCGateWay_AdasStatus_Callback , \
        }, \
        {/*S2M_HMI_POWER_MODE*/  \
        /*Offset    */(uint16)(S2M_HMI_POWER_MODE_OFFSET), \
        /*Length    */(uint16)(S2M_HMI_POWER_MODE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocHMIPowerMode_Receive) , \
        /*Callback  */ Rte_Call_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback , \
        }, \
        {/*M2S_GAUGES_UPLOADED*/  \
        /*Offset    */(uint16)(M2S_GAUGES_UPLOADED_OFFSET), \
        /*Length    */(uint16)(M2S_GAUGES_UPLOADED_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_GAUGES_ALIVE*/  \
        /*Offset    */(uint16)(S2M_GAUGES_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_GAUGES_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocGaugesAlive_Receive) , \
        /*Callback  */ IPC_API_GaugesAliveCallback , \
        }, \
        {/*S2M_READ_VIN_NUMBER_REQ*/  \
        /*Offset    */(uint16)(S2M_READ_VIN_NUMBER_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_READ_VIN_NUMBER_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_InfraMiscReadVINNumberRequest_Receive) , \
        /*Callback  */ IPC_API_ReadVINNumberCallback , \
        }, \
        {/*M2S_READ_VIN_NUMBER_RESP*/  \
        /*Offset    */(uint16)(M2S_READ_VIN_NUMBER_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_READ_VIN_NUMBER_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_InfraMiscReadVINNumberResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_CHIME_CLIENT_ALIVE*/  \
        /*Offset    */(uint16)(S2M_CHIME_CLIENT_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_CHIME_CLIENT_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocChimeClientAlive_Receive) , \
        /*Callback  */ IPC_API_ChimeClientAliveCallback , \
        }, \
        {/*M2S_APP_VCONFIG*/  \
        /*Offset    */(uint16)(M2S_APP_VCONFIG_OFFSET), \
        /*Length    */(uint16)(M2S_APP_VCONFIG_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPVConfig_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_MENU_THEME_REQ*/  \
        /*Offset    */(uint16)(S2M_MENU_THEME_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_MENU_THEME_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocMenuTheme_Receive) , \
        /*Callback  */ Rte_Call_rpCS_SWCGateWay_ReceiveMenuTheme_Callback , \
        }, \
        {/*M2S_MENU_THEME_RESP*/  \
        /*Offset    */(uint16)(M2S_MENU_THEME_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_MENU_THEME_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPMenuTheme_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_DRIVE_MODE_RESP*/  \
        /*Offset    */(uint16)(M2S_DRIVE_MODE_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_DRIVE_MODE_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPDriveMode_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_ReadBeanID_RESP*/  \
        /*Offset    */(uint16)(M2S_ReadBeanID_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_ReadBeanID_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_InfraMiscReadBeanIDResponse_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_ReadBeanID_REQ*/  \
        /*Offset    */(uint16)(S2M_ReadBeanID_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_ReadBeanID_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_InfraMiscReadBeanIDRequest_Receive) , \
        /*Callback  */ IPC_API_SetBeanIDReqCallback , \
        }, \
        {/*M2S_WN_DATA*/  \
        /*Offset    */(uint16)(M2S_WN_DATA_OFFSET), \
        /*Length    */(uint16)(M2S_WN_DATA_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPWN_Data_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_NEWENERGY*/  \
        /*Offset    */(uint16)(M2S_NEWENERGY_OFFSET), \
        /*Length    */(uint16)(M2S_NEWENERGY_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPNewEnergy_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_NEWENERGY_EV*/  \
        /*Offset    */(uint16)(M2S_NEWENERGY_EV_OFFSET), \
        /*Length    */(uint16)(M2S_NEWENERGY_EV_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPNewEnergy_EV_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_CSA3_244_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_CSA3_244_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_CSA3_244_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptCSA3_244_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_EEM1_2A8_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_EEM1_2A8_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_EEM1_2A8_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ESP2_145_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ESP2_145_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ESP2_145_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptESP2_145_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ESP2_137_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ESP2_137_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ESP2_137_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptESP2_137_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_HUD1_325_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_HUD1_325_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_HUD1_325_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptHUD1_325_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ECM3_371_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ECM3_371_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ECM3_371_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptECM3_371_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_CSA2_A1_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_CSA2_A1_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_CSA2_A1_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptCSA2_A1_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ECM16_2D4_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ECM16_2D4_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ECM16_2D4_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptECM16_2D4_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_AC2_385_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_AC2_385_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_AC2_385_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptAC2_385_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ECM_PT6_290_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ECM_PT6_290_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ECM_PT6_290_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ABM2_245_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ABM2_245_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ABM2_245_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptABM2_245_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_RSDS_FD1_16F_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_RSDS_FD1_16F_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_RSDS_FD1_16F_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_IFC_FD5_19F_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_IFC_FD5_19F_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_IFC_FD5_19F_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_IFC_FD6_222_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_IFC_FD6_222_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_IFC_FD6_222_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ACC_FD2_2AB_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ACC_FD2_2AB_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ACC_FD2_2AB_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_IFC_FD2_23D_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_IFC_FD2_23D_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_IFC_FD2_23D_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_AEB_FD2_227_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_AEB_FD2_227_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_AEB_FD2_227_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_CR_FD1_15E_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_CR_FD1_15E_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_CR_FD1_15E_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_IFC_FD3_2CF_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_IFC_FD3_2CF_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_IFC_FD3_2CF_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ACC_FD3_2B4_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ACC_FD3_2B4_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ACC_FD3_2B4_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_BCM1_319_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_BCM1_319_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_BCM1_319_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptBCM1_319_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_BCM3_345_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_BCM3_345_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_BCM3_345_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptBCM3_345_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_T_Box_FD10_2F0_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_T_Box_FD10_2F0_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_T_Box_FD10_2F0_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_WHUD_NVM_SET*/  \
        /*Offset    */(uint16)(S2M_WHUD_NVM_SET_OFFSET), \
        /*Length    */(uint16)(S2M_WHUD_NVM_SET_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_HUDCommonWhudNvmSet_Receive) , \
        /*Callback  */ IPC_API_WhudNvmSetWithIdCallback , \
        }, \
        {/*M2S_CA_ECM24_350_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ECM24_350_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ECM24_350_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptECM24_350_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_BCM12_238_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_BCM12_238_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_BCM12_238_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptBCM12_238_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_HMI_SAFETY_ALIVE*/  \
        /*Offset    */(uint16)(S2M_HMI_SAFETY_ALIVE_OFFSET), \
        /*Length    */(uint16)(S2M_HMI_SAFETY_ALIVE_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocHMISafety_Receive) , \
        /*Callback  */ IPC_API_GetSocHMISafetyAliveCallback , \
        }, \
        {/*S2M_SETAVASSWTST_REQ*/  \
        /*Offset    */(uint16)(S2M_SETAVASSWTST_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_SETAVASSWTST_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_InfraMiscSetAVASSwitchStatus_Receive) , \
        /*Callback  */ IPC_API_SetAVASSwitchStatusCallback , \
        }, \
        {/*S2M_TtToChime_REQ*/  \
        /*Offset    */(uint16)(S2M_TtToChime_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_TtToChime_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocTtToChime_Receive) , \
        /*Callback  */ Rte_Call_rpCS_SWCGateWay_TtToChime_Callback , \
        }, \
        {/*M2S_CA_F_PBOX1_19B_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_F_PBOX1_19B_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_F_PBOX1_19B_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*S2M_SET_OffroadInfo_REQ*/  \
        /*Offset    */(uint16)(S2M_SET_OffroadInfo_REQ_OFFSET), \
        /*Length    */(uint16)(S2M_SET_OffroadInfo_REQ_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_SOC2MCU) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */ NULL , \
        /*Download  */(SWC_IPC_Download)(IPC_S2M_ClusterAppClusterSocOffroadInfo_Receive) , \
        /*Callback  */ Rte_Call_rcCS_SWCNormal_ReceiveOffroadInfo_Callback , \
        }, \
        {/*M2S_SET_OffroadInfo_RESP*/  \
        /*Offset    */(uint16)(M2S_SET_OffroadInfo_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_SET_OffroadInfo_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppAPPOffroadInfo_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_HCM_L2_304_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_HCM_L2_304_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_HCM_L2_304_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
        {/*M2S_CA_ESP1_149_RESP*/  \
        /*Offset    */(uint16)(M2S_CA_ESP1_149_RESP_OFFSET), \
        /*Length    */(uint16)(M2S_CA_ESP1_149_RESP_LENGTH), \
        /*Cycle     */(uint16)(5/SWC_IPC_MANAGER_TASK_CYCLE) , \
        /*Priority  */(uint8)(0) , \
        /*Direction */(uint8)(SWC_IPC_MCU2SOC) , \
        /*Type      */(uint8)(SWC_IPC_APP_MSG_TYPE_EVENT) , \
        /*Upload    */(SWC_IPC_Upload)(IPC_M2S_ClusterAppCANAdaptESP1_149_Transmit) , \
        /*Download  */ NULL , \
        /*Callback  */ NULL , \
        }, \
    }

#endif /*SWC_IPC_APP_MSG_GEN*/


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"


#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
#endif

/**********************************************************************************************************
**
**  Revision : 2.0
**
**  Author   : HenryChan
**
**  Date     : 2020/08/06  2.0    Firmwork Update.     HenryChan
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
