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
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2022-04-12 19:43:19
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define OsApplication_NonTrust_OsCore0 OsApplication_NonTrust_OsCore0
#define OsApplication_Trust_OsCore0 OsApplication_Trust_OsCore0
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */
#define Os_ServiceCallee_Csm_Decrypt Os_ServiceCallee_Csm_Decrypt
#define Os_ServiceCallee_Csm_Encrypt Os_ServiceCallee_Csm_Encrypt
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
#define Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
#define Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
#define Os_ServiceCallee_Rte_TrustedCom_SendSignal Os_ServiceCallee_Rte_TrustedCom_SendSignal

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define BSW_COMM BSW_COMM
#define BSW_DIAGNOSE BSW_DIAGNOSE
#define DRIVERS_SAFE DRIVERS_SAFE
#define Default_BSW Default_BSW
#define Default_Init_Task Default_Init_Task
#define Default_Init_Task_Trusted Default_Init_Task_Trusted
#define FUEL_TC_ODO FUEL_TC_ODO
#define GateWay GateWay
#define IPC IPC
#define IdleTask_OsCore0 IdleTask_OsCore0
#define SWC_LOW SWC_LOW
#define SYS SYS
#define TT_GEAR TT_GEAR

/* Category 2 ISR identifiers. */
#define ADC0_SG1_CAT2_ISR ADC0_SG1_CAT2_ISR
#define ADC1_SG1_CAT2_ISR ADC1_SG1_CAT2_ISR
#define CanIsrGlobalStatus CanIsrGlobalStatus
#define CanIsrStatus_0 CanIsrStatus_0
#define CanIsrStatus_1 CanIsrStatus_1
#define CanIsrStatus_3 CanIsrStatus_3
#define CanIsrWakeup_0 CanIsrWakeup_0
#define CanIsrWakeup_1 CanIsrWakeup_1
#define CanIsrWakeup_3 CanIsrWakeup_3
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define EXT_INTP_CH00_CAT2_ISR EXT_INTP_CH00_CAT2_ISR
#define EXT_INTP_CH01_CAT2_ISR EXT_INTP_CH01_CAT2_ISR
#define EXT_INTP_CH03_CAT2_ISR EXT_INTP_CH03_CAT2_ISR
#define EXT_INTP_CH04_CAT2_ISR EXT_INTP_CH04_CAT2_ISR
#define EXT_INTP_CH05_CAT2_ISR EXT_INTP_CH05_CAT2_ISR
#define EXT_INTP_CH09_CAT2_ISR EXT_INTP_CH09_CAT2_ISR
#define EXT_INTP_CH11_CAT2_ISR EXT_INTP_CH11_CAT2_ISR
#define EXT_INTP_CH12_CAT2_ISR EXT_INTP_CH12_CAT2_ISR
#define EXT_INTP_CH13_CAT2_ISR EXT_INTP_CH13_CAT2_ISR
#define EXT_INTP_CH18_CAT2_ISR EXT_INTP_CH18_CAT2_ISR
#define EXT_INTP_CH19_CAT2_ISR EXT_INTP_CH19_CAT2_ISR
#define EXT_INTP_CH20_CAT2_ISR EXT_INTP_CH20_CAT2_ISR
#define EXT_INTP_CH21_CAT2_ISR EXT_INTP_CH21_CAT2_ISR
#define INTFICUIF0DFRQPE INTFICUIF0DFRQPE
#define INTRIIC0EE_interrupt INTRIIC0EE_interrupt
#define INTRIIC0RI_interrupt INTRIIC0RI_interrupt
#define INTRIIC0TEI_interrupt INTRIIC0TEI_interrupt
#define INTRIIC0TI_interrupt INTRIIC0TI_interrupt
#define INTRIIC1EE_interrupt INTRIIC1EE_interrupt
#define INTRIIC1RI_interrupt INTRIIC1RI_interrupt
#define INTRIIC1TEI_interrupt INTRIIC1TEI_interrupt
#define INTRIIC1TI_interrupt INTRIIC1TI_interrupt
#define Lin_RLIN_31_INTRLIN31 Lin_RLIN_31_INTRLIN31
#define Lin_RLIN_32_INTRLIN32 Lin_RLIN_32_INTRLIN32
#define SPI_CSIH3_TIR_CAT2_ISR SPI_CSIH3_TIR_CAT2_ISR
#define TAUD0_CH13_CAT2_ISR TAUD0_CH13_CAT2_ISR
#define TAUD0_CH15_CAT2_ISR TAUD0_CH15_CAT2_ISR
#define Uart_IntErr4 Uart_IntErr4
#define Uart_IntErr5 Uart_IntErr5
#define Uart_IntRx4 Uart_IntRx4
#define Uart_IntRx5 Uart_IntRx5
#define Uart_IntTx4 Uart_IntTx4
#define Uart_IntTx5 Uart_IntTx5
#define vHsmResponseIsr vHsmResponseIsr

/* Alarm identifiers. */
#define Rte_Al_TE2_BSW_COMM_0_10ms Rte_Al_TE2_BSW_COMM_0_10ms
#define Rte_Al_TE2_BSW_COMM_0_2ms Rte_Al_TE2_BSW_COMM_0_2ms
#define Rte_Al_TE2_BSW_COMM_0_5ms Rte_Al_TE2_BSW_COMM_0_5ms
#define Rte_Al_TE2_BSW_DIAGNOSE_0_10ms Rte_Al_TE2_BSW_DIAGNOSE_0_10ms
#define Rte_Al_TE2_Default_BSW_0_10ms Rte_Al_TE2_Default_BSW_0_10ms
#define Rte_Al_TE2_Default_BSW_0_5ms Rte_Al_TE2_Default_BSW_0_5ms
#define Rte_Al_TE2_Default_BSW_1_5ms Rte_Al_TE2_Default_BSW_1_5ms
#define Rte_Al_TE_CConfig_CConfig_MainFunction Rte_Al_TE_CConfig_CConfig_MainFunction
#define Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction
#define Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction
#define Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction
#define Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_ Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_
#define Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction
#define Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_ Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_
#define Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction
#define Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_ Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_
#define Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A
#define Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B
#define Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction
#define Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction
#define Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction
#define Rte_Al_TE_DCM_Server_DCM_Server_MainFunction Rte_Al_TE_DCM_Server_DCM_Server_MainFunction
#define Rte_Al_TE_DRIVERS_SAFE_0_100ms Rte_Al_TE_DRIVERS_SAFE_0_100ms
#define Rte_Al_TE_DRIVERS_SAFE_0_50ms Rte_Al_TE_DRIVERS_SAFE_0_50ms
#define Rte_Al_TE_DRIVERS_SAFE_0_5ms Rte_Al_TE_DRIVERS_SAFE_0_5ms
#define Rte_Al_TE_EOL_EOL_MainFunction Rte_Al_TE_EOL_EOL_MainFunction
#define Rte_Al_TE_FvM_FvM_MainFunction Rte_Al_TE_FvM_FvM_MainFunction
#define Rte_Al_TE_Gyro_Gyro_MainFunction Rte_Al_TE_Gyro_Gyro_MainFunction
#define Rte_Al_TE_HSM_Hsm_MainFunction Rte_Al_TE_HSM_Hsm_MainFunction
#define Rte_Al_TE_IPC_IPC_MainFunction Rte_Al_TE_IPC_IPC_MainFunction
#define Rte_Al_TE_IPC_IPC_STB_MainFunction Rte_Al_TE_IPC_IPC_STB_MainFunction
#define Rte_Al_TE_Misc_Misc_MainFunction_500ms Rte_Al_TE_Misc_Misc_MainFunction_500ms
#define Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable
#define Rte_Al_TE_SWC_LOW_0_10ms Rte_Al_TE_SWC_LOW_0_10ms
#define Rte_Al_TE_SYS_0_100ms Rte_Al_TE_SYS_0_100ms
#define Rte_Al_TE_SYS_0_10ms Rte_Al_TE_SYS_0_10ms
#define Rte_Al_TE_SYS_0_50ms Rte_Al_TE_SYS_0_50ms
#define Rte_Al_TE_SYS_0_5ms Rte_Al_TE_SYS_0_5ms
#define Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction

/* Counter identifiers. */
#define SystemTimer SystemTimer

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource OsResource

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  OsApplication_NonTrust_OsCore0 = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsApplication_Trust_OsCore0 = 1, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore0 = 2, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 3,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  Os_ServiceCallee_Csm_Decrypt = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Csm_Encrypt = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key = 25,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key = 26,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate = 27,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis = 28,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar = 29,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin = 30,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage = 31,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock = 32,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock = 33,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock = 34,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock = 35,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock = 36,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock = 37,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock = 38,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock = 39,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue = 40,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue = 41,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig = 42,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick = 43,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus = 44,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal = 45,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Rte_TrustedCom_SendSignal = 46,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TRUSTEDFUNCTIONID_COUNT = 47
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  BSW_COMM = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BSW_DIAGNOSE = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DRIVERS_SAFE = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_BSW = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Trusted = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  FUEL_TC_ODO = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GateWay = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IPC = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SWC_LOW = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SYS = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TT_GEAR = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 13,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  ADC0_SG1_CAT2_ISR = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC1_SG1_CAT2_ISR = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrGlobalStatus = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrStatus_0 = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrStatus_1 = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrStatus_3 = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrWakeup_0 = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrWakeup_1 = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrWakeup_3 = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH00_CAT2_ISR = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH01_CAT2_ISR = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH03_CAT2_ISR = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH04_CAT2_ISR = 13,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH05_CAT2_ISR = 14,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH09_CAT2_ISR = 15,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH11_CAT2_ISR = 16,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH12_CAT2_ISR = 17,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH13_CAT2_ISR = 18,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH18_CAT2_ISR = 19,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH19_CAT2_ISR = 20,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH20_CAT2_ISR = 21,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH21_CAT2_ISR = 22,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTFICUIF0DFRQPE = 23,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC0EE_interrupt = 24,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC0RI_interrupt = 25,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC0TEI_interrupt = 26,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC0TI_interrupt = 27,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC1EE_interrupt = 28,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC1RI_interrupt = 29,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC1TEI_interrupt = 30,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTRIIC1TI_interrupt = 31,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Lin_RLIN_31_INTRLIN31 = 32,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Lin_RLIN_32_INTRLIN32 = 33,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SPI_CSIH3_TIR_CAT2_ISR = 34,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH13_CAT2_ISR = 35,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH15_CAT2_ISR = 36,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntErr4 = 37,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntErr5 = 38,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntRx4 = 39,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntRx5 = 40,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntTx4 = 41,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Uart_IntTx5 = 42,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  vHsmResponseIsr = 43,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 44,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_BSW_COMM_0_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_COMM_0_2ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_COMM_0_5ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BSW_DIAGNOSE_0_10ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Default_BSW_0_10ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Default_BSW_0_5ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Default_BSW_1_5ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CConfig_CConfig_MainFunction = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_ = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_ = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_ = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DCM_Server_DCM_Server_MainFunction = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DRIVERS_SAFE_0_100ms = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DRIVERS_SAFE_0_50ms = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DRIVERS_SAFE_0_5ms = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_EOL_EOL_MainFunction = 25,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_FvM_FvM_MainFunction = 26,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Gyro_Gyro_MainFunction = 27,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_HSM_Hsm_MainFunction = 28,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_IPC_IPC_MainFunction = 29,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_IPC_IPC_STB_MainFunction = 30,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Misc_Misc_MainFunction_500ms = 31,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable = 32,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SWC_LOW_0_10ms = 33,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SYS_0_100ms = 34,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SYS_0_10ms = 35,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SYS_0_50ms = 36,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SYS_0_5ms = 37,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction = 38,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 39
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0u,  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
