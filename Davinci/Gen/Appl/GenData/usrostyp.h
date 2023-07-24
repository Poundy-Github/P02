/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  usrostyp.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  User Types header file (osCAN specific)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef USROSTYP_H
# define USROSTYP_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

# include "Com.h"
# include "Rte_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation(const EventSignalInfo_Type *event_signal_info);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation(uint16 signalId, uint32 *value);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation(uint8 *p_msg, uint16 len, uint8 priority);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, uint8 *Result);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(uint16 signalId, uint8 *value);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, EventSignalType *value);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter(CanFrameCounterType *counter);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter(CanFrameCounterType *counter);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter(CanFrameCounterType *counter);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key(A_17Bytes *IV, A_16Bytes *KEY, uint32 *key_len);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key(const A_16Bytes *IV, const A_16Bytes *KEY, uint32 key_len);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate(A_16Bytes *Trng, uint32 *len);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis(uint64 *arg);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(dtRef_const_VOID SrcPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
FUNC(uint8, RTE_CODE) Rte_TrustedCom_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* USROSTYP_H */
