/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Cfg.h
 *   Generation Time: 2022-03-04 14:02:09
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (44u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_RH850     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_RH850F1KM     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_RH850_1651     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_GREENHILLS     (STD_ON)

/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_ON)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_ON)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_ON)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_OFF)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_ON)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_ON)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_BSW_COMM_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_BSW_COMM_0_2ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic2_BSW_COMM_0_5ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic2_BSW_DIAGNOSE_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_Default_BSW_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_Default_BSW_0_5ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic2_Default_BSW_1_5ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic_DRIVERS_SAFE_0_100ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_DRIVERS_SAFE_0_50ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic_SWC_LOW_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_SYS_0_100ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_SYS_0_10ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_SYS_0_50ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic_SYS_0_5ms     ((EventMaskType)16uLL)
# define Rte_Ev_Run_AMP_AMP_Event_MainFunction     ((EventMaskType)16uLL)
# define Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq     ((EventMaskType)16uLL)
# define Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq_EmergencySleep     ((EventMaskType)32uLL)
# define Rte_Ev_Run_CConfig_CConfig_MainFunction     ((EventMaskType)16uLL)
# define Rte_Ev_Run_Can_Server_CNA_SignalGroupSet     ((EventMaskType)32uLL)
# define Rte_Ev_Run_Can_Server_CNA_SignalSet     ((EventMaskType)64uLL)
# define Rte_Ev_Run_Can_Server_CNA_SignalSetNoTrigger     ((EventMaskType)128uLL)
# define Rte_Ev_Run_Can_Server_CNA_SignalSet_U8N     ((EventMaskType)256uLL)
# define Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ABS3_Counter     ((EventMaskType)32uLL)
# define Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ECM2_Counter     ((EventMaskType)64uLL)
# define Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter     ((EventMaskType)128uLL)
# define Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus     ((EventMaskType)32uLL)
# define Rte_Ev_Run_ComEx_ComEx_SendSignal     ((EventMaskType)64uLL)
# define Rte_Ev_Run_Common_GateWay_Common_GateWay_10msMainFunction     ((EventMaskType)1uLL)
# define Rte_Ev_Run_Common_GateWay_Common_GateWay_5msMainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction     ((EventMaskType)1uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction_     ((EventMaskType)4uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction     ((EventMaskType)8uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction_     ((EventMaskType)16uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction     ((EventMaskType)32uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_     ((EventMaskType)64uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_A     ((EventMaskType)128uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_B     ((EventMaskType)256uLL)
# define Rte_Ev_Run_Common_Normal_Common_Normal_5msMainFunction     ((EventMaskType)512uLL)
# define Rte_Ev_Run_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_Common_Normal_Fuel_Api_ParamentGetCsPort_Operation     ((EventMaskType)2048uLL)
# define Rte_Ev_Run_Common_Safety_Common_Safety_10msMainFunction     ((EventMaskType)1uLL)
# define Rte_Ev_Run_Common_Safety_Common_Safety_50msMainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run_DCM_Server_DCM_Server_MainFunction     ((EventMaskType)64uLL)
# define Rte_Ev_Run_DemSatellite_0_SetEventStatus     ((EventMaskType)4uLL)
# define Rte_Ev_Run_DidDataProcess_E2ESwitchStatusRead     ((EventMaskType)4uLL)
# define Rte_Ev_Run_DidDataProcess_E2ESwitchStatusWrite     ((EventMaskType)8uLL)
# define Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusRead     ((EventMaskType)16uLL)
# define Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusWrite     ((EventMaskType)32uLL)
# define Rte_Ev_Run_EOL_EOL_MainFunction     ((EventMaskType)64uLL)
# define Rte_Ev_Run_FvM_FvM_MainFunction     ((EventMaskType)512uLL)
# define Rte_Ev_Run_Gyro_Gyro_MainFunction     ((EventMaskType)128uLL)
# define Rte_Ev_Run_HSM_HsmGetAes128Key     ((EventMaskType)128uLL)
# define Rte_Ev_Run_HSM_HsmSetAes128Key     ((EventMaskType)256uLL)
# define Rte_Ev_Run_HSM_HsmTrngGenerate     ((EventMaskType)512uLL)
# define Rte_Ev_Run_HSM_Hsm_MainFunction     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_IIC_IIC0_MainFunction     ((EventMaskType)256uLL)
# define Rte_Ev_Run_IIC_IIC1_MainFunction     ((EventMaskType)512uLL)
# define Rte_Ev_Run_IPC_IPC_DataSend_If_Operation     ((EventMaskType)1uLL)
# define Rte_Ev_Run_IPC_IPC_MainFunction     ((EventMaskType)2uLL)
# define Rte_Ev_Run_IPC_IPC_STB_MainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_GetPin     ((EventMaskType)256uLL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_GetVoltage     ((EventMaskType)512uLL)
# define Rte_Ev_Run_Misc_Misc_MainFunction_500ms     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_Misc_NVM_Read_Speedup_Runnable     ((EventMaskType)2048uLL)
# define Rte_Ev_Run_NvM_WriteBlock     ((EventMaskType)4096uLL)
# define Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue     ((EventMaskType)8192uLL)
# define Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue     ((EventMaskType)16384uLL)
# define Rte_Ev_Run_RTC_GetUTCTimeInMillis     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_RTC_RTC_MainFunction     ((EventMaskType)2048uLL)
# define Rte_Ev_Run_RTC_UTC2PerpetualCalendar     ((EventMaskType)4096uLL)
# define Rte_Ev_Run_SecOc_Server_SecOc_Server_MainFunction     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo     ((EventMaskType)128uLL)
# define Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig     ((EventMaskType)2048uLL)
# define Rte_Ev_Run_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick     ((EventMaskType)4096uLL)
# define Rte_Ev_WP_BSW_COMM     ((EventMaskType)2uLL)
# define Rte_Ev_WP_BSW_DIAGNOSE     ((EventMaskType)2uLL)
# define Rte_Ev_WP_DRIVERS_SAFE     ((EventMaskType)2uLL)
# define Rte_Ev_WP_Default_BSW     ((EventMaskType)2uLL)
# define Rte_Ev_WP_FUEL_TC_ODO     ((EventMaskType)2uLL)
# define Rte_Ev_WP_GateWay     ((EventMaskType)2uLL)
# define Rte_Ev_WP_SWC_LOW     ((EventMaskType)2uLL)
# define Rte_Ev_WP_SYS     ((EventMaskType)2uLL)
# define Rte_Ev_WP_TT_GEAR     ((EventMaskType)2uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

