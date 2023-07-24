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
 *              File: Os_ServiceFunction_Lcfg.h
 *   Generation Time: 2022-04-12 19:43:18
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_SERVICEFUNCTION_LCFG_H
# define OS_SERVICEFUNCTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ServiceFunction_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Service function configuration data: Csm_Decrypt */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Csm_Decrypt;

/*! Service function configuration data: Csm_Encrypt */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Csm_Encrypt;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation;

/*! Service function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus;

/*! Service function configuration data: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal;

/*! Service function configuration data: Rte_TrustedCom_SendSignal */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCom_SendSignal;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for trusted functions. */
extern CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1];                                /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for non-trusted functions. */
extern CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1];                            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for fast trusted functions. */
extern CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1];                          /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_SERVICEFUNCTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.h
 *********************************************************************************************************************/
