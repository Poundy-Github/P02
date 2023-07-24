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
 *              File: Os_Lcfg.h
 *   Generation Time: 2022-04-12 19:43:18
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */
#include "usrostyp.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Backward compatibility API defines for trusted function stubs. */
# define Call_Csm_Decrypt     Os_Call_Csm_Decrypt
# define Call_Csm_Encrypt     Os_Call_Csm_Encrypt
# define Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
# define Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
# define Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
# define Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock     Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
# define Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock     Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
# define Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig     Os_Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
# define Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar     Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
# define Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter     Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
# define Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter     Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
# define Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter     Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
# define Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus     Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
# define Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus     Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
# define Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus     Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
# define Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus     Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
# define Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key     Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
# define Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key     Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
# define Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate     Os_Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
# define Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis     Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
# define Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar     Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
# define Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin     Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
# define Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage     Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock     Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
# define Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue     Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
# define Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue     Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
# define Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig     Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
# define Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick     Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
# define Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus     Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
# define Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal     Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
# define Call_Rte_TrustedCom_SendSignal     Os_Call_Rte_TrustedCom_SendSignal


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_BSW_COMM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BSW_COMM()
 *********************************************************************************************************************/
extern FUNC(void, OS_BSW_COMM_CODE) Os_Task_BSW_COMM(void);

# define OS_STOP_SEC_BSW_COMM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_BSW_DIAGNOSE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BSW_DIAGNOSE()
 *********************************************************************************************************************/
extern FUNC(void, OS_BSW_DIAGNOSE_CODE) Os_Task_BSW_DIAGNOSE(void);

# define OS_STOP_SEC_BSW_DIAGNOSE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DRIVERS_SAFE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DRIVERS_SAFE()
 *********************************************************************************************************************/
extern FUNC(void, OS_DRIVERS_SAFE_CODE) Os_Task_DRIVERS_SAFE(void);

# define OS_STOP_SEC_DRIVERS_SAFE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_BSW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_BSW()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_BSW_CODE) Os_Task_Default_BSW(void);

# define OS_STOP_SEC_Default_BSW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_Trusted_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task_Trusted()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_TRUSTED_CODE) Os_Task_Default_Init_Task_Trusted(void);

# define OS_STOP_SEC_Default_Init_Task_Trusted_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_FUEL_TC_ODO_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUEL_TC_ODO()
 *********************************************************************************************************************/
extern FUNC(void, OS_FUEL_TC_ODO_CODE) Os_Task_FUEL_TC_ODO(void);

# define OS_STOP_SEC_FUEL_TC_ODO_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GateWay_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GateWay()
 *********************************************************************************************************************/
extern FUNC(void, OS_GATEWAY_CODE) Os_Task_GateWay(void);

# define OS_STOP_SEC_GateWay_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_IPC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IPC()
 *********************************************************************************************************************/
extern FUNC(void, OS_IPC_CODE) Os_Task_IPC(void);

# define OS_STOP_SEC_IPC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SWC_LOW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SWC_LOW()
 *********************************************************************************************************************/
extern FUNC(void, OS_SWC_LOW_CODE) Os_Task_SWC_LOW(void);

# define OS_STOP_SEC_SWC_LOW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SYS_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SYS()
 *********************************************************************************************************************/
extern FUNC(void, OS_SYS_CODE) Os_Task_SYS(void);

# define OS_STOP_SEC_SYS_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TT_GEAR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TT_GEAR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TT_GEAR_CODE) Os_Task_TT_GEAR(void);

# define OS_STOP_SEC_TT_GEAR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC0_SG1_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC0_SG1_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC0_SG1_CAT2_ISR_CODE) Os_Isr_ADC0_SG1_CAT2_ISR(void);

# define OS_STOP_SEC_ADC0_SG1_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC1_SG1_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC1_SG1_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC1_SG1_CAT2_ISR_CODE) Os_Isr_ADC1_SG1_CAT2_ISR(void);

# define OS_STOP_SEC_ADC1_SG1_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrGlobalStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrGlobalStatus()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRGLOBALSTATUS_CODE) Os_Isr_CanIsrGlobalStatus(void);

# define OS_STOP_SEC_CanIsrGlobalStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrStatus_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrStatus_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRSTATUS_0_CODE) Os_Isr_CanIsrStatus_0(void);

# define OS_STOP_SEC_CanIsrStatus_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrStatus_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrStatus_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRSTATUS_1_CODE) Os_Isr_CanIsrStatus_1(void);

# define OS_STOP_SEC_CanIsrStatus_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrStatus_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrStatus_3()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRSTATUS_3_CODE) Os_Isr_CanIsrStatus_3(void);

# define OS_STOP_SEC_CanIsrStatus_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrWakeup_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrWakeup_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRWAKEUP_0_CODE) Os_Isr_CanIsrWakeup_0(void);

# define OS_STOP_SEC_CanIsrWakeup_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrWakeup_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrWakeup_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRWAKEUP_1_CODE) Os_Isr_CanIsrWakeup_1(void);

# define OS_STOP_SEC_CanIsrWakeup_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrWakeup_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrWakeup_3()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRWAKEUP_3_CODE) Os_Isr_CanIsrWakeup_3(void);

# define OS_STOP_SEC_CanIsrWakeup_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH00_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH00_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH00_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH00_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH00_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH01_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH01_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH01_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH01_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH01_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH03_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH03_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH03_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH03_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH03_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH04_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH04_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH04_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH04_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH04_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH05_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH05_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH05_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH05_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH05_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH09_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH09_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH09_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH09_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH09_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH11_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH11_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH11_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH11_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH11_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH12_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH12_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH12_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH12_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH12_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH13_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH13_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH13_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH13_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH13_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH18_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH18_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH18_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH18_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH18_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH19_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH19_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH19_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH19_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH19_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH20_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH20_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH20_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH20_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH20_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH21_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH21_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH21_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH21_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH21_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTFICUIF0DFRQPE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTFICUIF0DFRQPE()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTFICUIF0DFRQPE_CODE) Os_Isr_INTFICUIF0DFRQPE(void);

# define OS_STOP_SEC_INTFICUIF0DFRQPE_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC0EE_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC0EE_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC0EE_INTERRUPT_CODE) Os_Isr_INTRIIC0EE_interrupt(void);

# define OS_STOP_SEC_INTRIIC0EE_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC0RI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC0RI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC0RI_INTERRUPT_CODE) Os_Isr_INTRIIC0RI_interrupt(void);

# define OS_STOP_SEC_INTRIIC0RI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC0TEI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC0TEI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC0TEI_INTERRUPT_CODE) Os_Isr_INTRIIC0TEI_interrupt(void);

# define OS_STOP_SEC_INTRIIC0TEI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC0TI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC0TI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC0TI_INTERRUPT_CODE) Os_Isr_INTRIIC0TI_interrupt(void);

# define OS_STOP_SEC_INTRIIC0TI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC1EE_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC1EE_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC1EE_INTERRUPT_CODE) Os_Isr_INTRIIC1EE_interrupt(void);

# define OS_STOP_SEC_INTRIIC1EE_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC1RI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC1RI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC1RI_INTERRUPT_CODE) Os_Isr_INTRIIC1RI_interrupt(void);

# define OS_STOP_SEC_INTRIIC1RI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC1TEI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC1TEI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC1TEI_INTERRUPT_CODE) Os_Isr_INTRIIC1TEI_interrupt(void);

# define OS_STOP_SEC_INTRIIC1TEI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTRIIC1TI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTRIIC1TI_interrupt()
 *********************************************************************************************************************/
extern FUNC(void, OS_INTRIIC1TI_INTERRUPT_CODE) Os_Isr_INTRIIC1TI_interrupt(void);

# define OS_STOP_SEC_INTRIIC1TI_interrupt_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_LinIsr_30_Rh850Rlin_31_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LinIsr_30_Rh850Rlin_31_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_LINISR_30_RH850RLIN_31_0_CODE) Os_Isr_LinIsr_30_Rh850Rlin_31_0(void);

# define OS_STOP_SEC_LinIsr_30_Rh850Rlin_31_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_LinIsr_30_Rh850Rlin_32_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LinIsr_30_Rh850Rlin_32_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_LINISR_30_RH850RLIN_32_0_CODE) Os_Isr_LinIsr_30_Rh850Rlin_32_0(void);

# define OS_STOP_SEC_LinIsr_30_Rh850Rlin_32_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SPI_CSIH3_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SPI_CSIH3_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH3_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIH3_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH3_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH13_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH13_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH13_CAT2_ISR_CODE) Os_Isr_TAUD0_CH13_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH13_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH15_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH15_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH15_CAT2_ISR_CODE) Os_Isr_TAUD0_CH15_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH15_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntErr4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntErr4()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTERR4_CODE) Os_Isr_Uart_IntErr4(void);

# define OS_STOP_SEC_Uart_IntErr4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntErr5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntErr5()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTERR5_CODE) Os_Isr_Uart_IntErr5(void);

# define OS_STOP_SEC_Uart_IntErr5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntRx4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntRx4()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTRX4_CODE) Os_Isr_Uart_IntRx4(void);

# define OS_STOP_SEC_Uart_IntRx4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntRx5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntRx5()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTRX5_CODE) Os_Isr_Uart_IntRx5(void);

# define OS_STOP_SEC_Uart_IntRx5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntTx4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntTx4()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTTX4_CODE) Os_Isr_Uart_IntTx4(void);

# define OS_STOP_SEC_Uart_IntTx4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Uart_IntTx5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Uart_IntTx5()
 *********************************************************************************************************************/
extern FUNC(void, OS_UART_INTTX5_CODE) Os_Isr_Uart_IntTx5(void);

# define OS_STOP_SEC_Uart_IntTx5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_vHsmResponseIsr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmResponseIsr()
 *********************************************************************************************************************/
extern FUNC(void, OS_VHSMRESPONSEISR_CODE) Os_Isr_vHsmResponseIsr(void);

# define OS_STOP_SEC_vHsmResponseIsr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Csm_Decrypt
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Csm_Decrypt
(
  uint32 Arg1,
  Crypto_OperationModeType Arg2,
  uint8* Arg3,
  uint32 Arg4,
  uint8* Arg5,
  uint32* Arg6
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Csm_Encrypt
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Csm_Encrypt
(
  uint32 Arg1,
  Crypto_OperationModeType Arg2,
  uint8* Arg3,
  uint32 Arg4,
  uint8* Arg5,
  uint32* Arg6
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
(
  const EventSignalInfo_Type* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
(
  uint16 Arg1,
  uint32* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
(
  uint8* Arg1,
  uint16 Arg2,
  uint8 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  uint16 Arg1,
  uint8* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
(
  uint8 Arg1,
  uint8* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
(
  uint16 Arg1,
  uint8* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
(
  uint16 Arg1,
  EventSignalType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
(
  ComEx_SignalGroupIdType Arg1,
  uint32* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
(
  ComEx_SignalIdType Arg1,
  ComEx_ConstSignalDataType Arg2,
  uint8 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
(
  sint64 Arg1,
  DateTimeType_t* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
(
  CanFrameCounterType* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
(
  CanFrameCounterType* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
(
  CanFrameCounterType* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
(
  Dem_EventStatusType Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
(
  Dem_EventStatusType Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
(
  Dem_EventStatusType Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
(
  Dem_EventStatusType Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
(
  A_17Bytes* Arg1,
  A_16Bytes* Arg2,
  uint32* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
(
  const A_16Bytes* Arg1,
  const A_16Bytes* Arg2,
  uint32 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
(
  A_16Bytes* Arg1,
  uint32* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
(
  uint64* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
(
  sint64 Arg1,
  DateTimeType_t* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
(
  uint8 Arg1,
  boolean* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
(
  uint8 Arg1,
  uint32* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
(
  dtRef_const_VOID Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
(
  TimeInMicrosecondsType* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
(
  TimeInMicrosecondsType* Arg1,
  TimeInMicrosecondsType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  uint16 Arg1,
  uint8* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
(
  TimeInMicrosecondsType* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
(
  ComEx_SignalGroupIdType Arg1,
  uint32* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
(
  ComEx_SignalIdType Arg1,
  ComEx_ConstSignalDataType Arg2,
  uint8 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCom_SendSignal
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_Rte_TrustedCom_SendSignal
(
  Com_SignalIdType Arg1,
  const void* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
