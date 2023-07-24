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
 *             File:  Rte_Common_Safety.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Common_Safety>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_SAFETY_H
# define RTE_COMMON_SAFETY_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Os.h"
# include "Rte_Common_Safety_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit;
extern VAR(uint32, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element;
extern VAR(DrvGearDisp, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox (0U)
#  define Rte_InitValue_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_CheckSum_IP2 (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_ACCErr (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_AvgFuelCons (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_BattChrgLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_CurrTheme (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_EBDFailSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_Err (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelAuxTankR (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelLvlInfo (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelMainTankR (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_InstFuelCons (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_InstFuelConsUnit (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_LagueSet (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_RemainDistance (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VINcompr (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehSpdDisp (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehSpdUnit (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehTotDistance (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehTotDistanceValid (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VelSpdDisp_Mile (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_RollingCounter_IP2 (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 (0U)
#  define Rte_InitValue_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts (0U)
#  define Rte_InitValue_Tgtgear_Down_Tgtgear_Down (0U)
#  define Rte_InitValue_Tgtgear_Up_Tgtgear_Up (0U)
#  define Rte_InitValue_piSR_E2ESwitchChangeTrigger_Element (0U)
#  define Rte_InitValue_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element (0U)
#  define Rte_InitValue_ppSR_SWCSafety_DrvGearDisp_Element (0U)
#  define Rte_InitValue_ppSR_SWCSafety_GearMsgMiss_Element (0U)
#  define Rte_InitValue_tiSR_SWC_TT_SelfCheck_Element (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_tsTT_GEAR, RTE_VAR_NOINIT) Rte_TT_GEAR; /* PRQA S 0759 */ /* MD_MSR_Union */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Vconfig_GetKindBuffers_AllKinds(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_IoHwAb_Interface_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Pin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_IoHwAb_Interface_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) updateTick); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut() \
  (&Rte_TT_GEAR.Rte_RB.Rte_Common_Safety_Common_Safety_10msMainFunction.Rte_rpSR_SWCSafety_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_Safety_50msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut() \
  (&Rte_TT_GEAR.Rte_RB.Rte_Common_Safety_Common_Safety_50msMainFunction.Rte_rpSR_SWCSafety_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes Rte_Read_Common_Safety_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
#  define Rte_Read_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox Rte_Read_Common_Safety_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox Rte_Read_Common_Safety_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABM1_SG_ABM1 Rte_Read_Common_Safety_SG_ABM1_SG_ABM1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ABM1_SG_ABM1(data) (*(data) = Rte_C_SG_ABM1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABS3_SG_ABS3 Rte_Read_Common_Safety_SG_ABS3_SG_ABS3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ABS3_SG_ABS3(data) (*(data) = Rte_C_SG_ABS3_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2 Rte_Read_Common_Safety_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(data) (*(data) = Rte_C_SG_ABS3_ESP_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2 Rte_Read_Common_Safety_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(data) (*(data) = Rte_C_SG_AEB2_AEB_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2 Rte_Read_Common_Safety_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(data) (*(data) = Rte_C_SG_AEB3_AEB_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_BMS4_SG_BMS4 Rte_Read_Common_Safety_SG_BMS4_SG_BMS4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_BMS4_SG_BMS4(data) (*(data) = Rte_C_SG_BMS4_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_DCT7_SG_DCT7 Rte_Read_Common_Safety_SG_DCT7_SG_DCT7
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_DCT7_SG_DCT7(data) (*(data) = Rte_C_SG_DCT7_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_DHT_FD1_SG_DHT_FD1 Rte_Read_Common_Safety_SG_DHT_FD1_SG_DHT_FD1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_DHT_FD1_SG_DHT_FD1(data) (*(data) = Rte_C_SG_DHT_FD1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPB1_SG_EPB1 Rte_Read_Common_Safety_SG_EPB1_SG_EPB1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_EPB1_SG_EPB1(data) (*(data) = Rte_C_SG_EPB1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPS1_SG_EPS1 Rte_Read_Common_Safety_SG_EPS1_SG_EPS1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_EPS1_SG_EPS1(data) (*(data) = Rte_C_SG_EPS1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1 Rte_Read_Common_Safety_SG_EPS1_FD1_SG_EPS1_FD1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_EPS1_FD1_SG_EPS1_FD1(data) (*(data) = Rte_C_SG_EPS1_FD1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP1_SG_ESP1 Rte_Read_Common_Safety_SG_ESP1_SG_ESP1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ESP1_SG_ESP1(data) (*(data) = Rte_C_SG_ESP1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2 Rte_Read_Common_Safety_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(data) (*(data) = Rte_C_SG_ESP1_ESP_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP2_SG_ESP2 Rte_Read_Common_Safety_SG_ESP2_SG_ESP2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ESP2_SG_ESP2(data) (*(data) = Rte_C_SG_ESP2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2 Rte_Read_Common_Safety_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(data) (*(data) = Rte_C_SG_ESP2_ESP_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_HP5_SG_HCU_HP5 Rte_Read_Common_Safety_SG_HCU_HP5_SG_HCU_HP5
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_HCU_HP5_SG_HCU_HP5(data) (*(data) = Rte_C_SG_HCU_HP5_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_PT4_SG_HCU_PT4 Rte_Read_Common_Safety_SG_HCU_PT4_SG_HCU_PT4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_HCU_PT4_SG_HCU_PT4(data) (*(data) = Rte_C_SG_HCU_PT4_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_PT7_SG_HCU_PT7 Rte_Read_Common_Safety_SG_HCU_PT7_SG_HCU_PT7
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_HCU_PT7_SG_HCU_PT7(data) (*(data) = Rte_C_SG_HCU_PT7_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2 Rte_Read_Common_Safety_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(data) (*(data) = Rte_C_SG_IFC6_IFC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Tgtgear_Down_Tgtgear_Down Rte_Read_Common_Safety_Tgtgear_Down_Tgtgear_Down
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_Tgtgear_Down_Tgtgear_Down(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Tgtgear_Up_Tgtgear_Up Rte_Read_Common_Safety_Tgtgear_Up_Tgtgear_Up
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Safety_Tgtgear_Up_Tgtgear_Up(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Vconfig_GetKindBuffers_AllKinds Rte_Read_Common_Safety_Vconfig_GetKindBuffers_AllKinds
#  define Rte_Read_piSR_E2ESwitchChangeTrigger_Element Rte_Read_Common_Safety_piSR_E2ESwitchChangeTrigger_Element
#  define Rte_Read_Common_Safety_piSR_E2ESwitchChangeTrigger_Element(data) (*(data) = Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_SG_ABM1_SG_ABM1 Rte_IsUpdated_Common_Safety_SG_ABM1_SG_ABM1
#  define Rte_IsUpdated_Common_Safety_SG_ABM1_SG_ABM1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ABS3_SG_ABS3 Rte_IsUpdated_Common_Safety_SG_ABS3_SG_ABS3
#  define Rte_IsUpdated_Common_Safety_SG_ABS3_SG_ABS3() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2 Rte_IsUpdated_Common_Safety_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
#  define Rte_IsUpdated_Common_Safety_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2 Rte_IsUpdated_Common_Safety_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2
#  define Rte_IsUpdated_Common_Safety_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2 Rte_IsUpdated_Common_Safety_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2
#  define Rte_IsUpdated_Common_Safety_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_BMS4_SG_BMS4 Rte_IsUpdated_Common_Safety_SG_BMS4_SG_BMS4
#  define Rte_IsUpdated_Common_Safety_SG_BMS4_SG_BMS4() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_DCT7_SG_DCT7 Rte_IsUpdated_Common_Safety_SG_DCT7_SG_DCT7
#  define Rte_IsUpdated_Common_Safety_SG_DCT7_SG_DCT7() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_DHT_FD1_SG_DHT_FD1 Rte_IsUpdated_Common_Safety_SG_DHT_FD1_SG_DHT_FD1
#  define Rte_IsUpdated_Common_Safety_SG_DHT_FD1_SG_DHT_FD1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPB1_SG_EPB1 Rte_IsUpdated_Common_Safety_SG_EPB1_SG_EPB1
#  define Rte_IsUpdated_Common_Safety_SG_EPB1_SG_EPB1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPS1_SG_EPS1 Rte_IsUpdated_Common_Safety_SG_EPS1_SG_EPS1
#  define Rte_IsUpdated_Common_Safety_SG_EPS1_SG_EPS1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPS1_FD1_SG_EPS1_FD1 Rte_IsUpdated_Common_Safety_SG_EPS1_FD1_SG_EPS1_FD1
#  define Rte_IsUpdated_Common_Safety_SG_EPS1_FD1_SG_EPS1_FD1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP1_SG_ESP1 Rte_IsUpdated_Common_Safety_SG_ESP1_SG_ESP1
#  define Rte_IsUpdated_Common_Safety_SG_ESP1_SG_ESP1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2 Rte_IsUpdated_Common_Safety_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2
#  define Rte_IsUpdated_Common_Safety_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP2_SG_ESP2 Rte_IsUpdated_Common_Safety_SG_ESP2_SG_ESP2
#  define Rte_IsUpdated_Common_Safety_SG_ESP2_SG_ESP2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2 Rte_IsUpdated_Common_Safety_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2
#  define Rte_IsUpdated_Common_Safety_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_HP5_SG_HCU_HP5 Rte_IsUpdated_Common_Safety_SG_HCU_HP5_SG_HCU_HP5
#  define Rte_IsUpdated_Common_Safety_SG_HCU_HP5_SG_HCU_HP5() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_PT4_SG_HCU_PT4 Rte_IsUpdated_Common_Safety_SG_HCU_PT4_SG_HCU_PT4
#  define Rte_IsUpdated_Common_Safety_SG_HCU_PT4_SG_HCU_PT4() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_PT7_SG_HCU_PT7 Rte_IsUpdated_Common_Safety_SG_HCU_PT7_SG_HCU_PT7
#  define Rte_IsUpdated_Common_Safety_SG_HCU_PT7_SG_HCU_PT7() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2 Rte_IsUpdated_Common_Safety_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2
#  define Rte_IsUpdated_Common_Safety_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Tgtgear_Down_Tgtgear_Down Rte_IsUpdated_Common_Safety_Tgtgear_Down_Tgtgear_Down
#  define Rte_IsUpdated_Common_Safety_Tgtgear_Down_Tgtgear_Down() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Tgtgear_Up_Tgtgear_Up Rte_IsUpdated_Common_Safety_Tgtgear_Up_Tgtgear_Up
#  define Rte_IsUpdated_Common_Safety_Tgtgear_Up_Tgtgear_Up() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SafetyCanOutputViaNormal_CheckSum_IP2 Rte_Write_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_ACCErr Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_BattChrgLmpSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_Err Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_Err
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_Err(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_FuelLvlInfo Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_VINcompr Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_VehSpdUnit Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_VehTotDistance Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_IP_VehTotDistanceValid Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_RollingCounter_IP2 Rte_Write_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 Rte_Write_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0
#  define Rte_Write_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0(data) (Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts Rte_Write_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts
#  define Rte_Write_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts(data) (Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element Rte_Write_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element
#  define Rte_Write_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element(data) (Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCSafety_DrvGearDisp_Element Rte_Write_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element
#  define Rte_Write_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element(data) (Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCSafety_GearMsgMiss_Element Rte_Write_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element
#  define Rte_Write_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element(data) (Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_tiSR_SWC_TT_SelfCheck_Element Rte_Write_Common_Safety_tiSR_SWC_TT_SelfCheck_Element
#  define Rte_Write_Common_Safety_tiSR_SWC_TT_SelfCheck_Element(data) (Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_IoHwAb_Interface_GetPin Rte_Call_Common_Safety_IoHwAb_Interface_GetPin
#  define Rte_Call_IoHwAb_Interface_GetVoltage Rte_Call_Common_Safety_IoHwAb_Interface_GetVoltage
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_Common_Safety_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_Common_Safety_Os_Service_GetElapsedValue
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define Rte_Call_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick Rte_Call_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
#  define Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_SWCSafety_ComEx_SendSignal Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_GATEWAY_APPL_CODE) IPC_Send_IPC_Send(uint8 Id_u8, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data_s, uint16 len_u16, boolean Imm_bool); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IPC_Send_IPC_Send IPC_Send_IPC_Send
#  define RTE_START_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_WdgM_AliveSupervision_Gear_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_WdgM_AliveSupervision_TT_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)2, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal ComEx_ReceiveSignal


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_Safety() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_ExclusiveArea_Safety() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define Common_Safety_START_SEC_CODE
# include "Common_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Common_SF_List_Deinit Common_SF_List_Deinit
#  define RTE_RUNNABLE_Common_SF_List_Int Common_SF_List_Int
#  define RTE_RUNNABLE_Common_Safety_10msMainFunction Common_Safety_10msMainFunction
#  define RTE_RUNNABLE_Common_Safety_50msMainFunction Common_Safety_50msMainFunction
#  define RTE_RUNNABLE_Common_Safety_Init Common_Safety_Init
#  define RTE_RUNNABLE_Common_Safety_Nomal2Standby_Callbcak Common_Safety_Nomal2Standby_Callbcak
#  define RTE_RUNNABLE_Common_Safety_Standby2Nomal_Callbcak Common_Safety_Standby2Nomal_Callbcak
#  define RTE_RUNNABLE_SafetyMode_Operation SafetyMode_Operation
#  define RTE_RUNNABLE_svCS_SWCSafety_ReceiveSafetyGearCRC_Callback svCS_SWCSafety_ReceiveSafetyGearCRC_Callback
#  define RTE_RUNNABLE_svCS_SWCSafety_ReceiveSafetyTTCRC_Callback svCS_SWCSafety_ReceiveSafetyTTCRC_Callback
#  define RTE_RUNNABLE_svCS_SWCSafety_TTCallback_Operation svCS_SWCSafety_TTCallback_Operation
# endif

FUNC(void, Common_Safety_CODE) Common_SF_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) Common_SF_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) Common_Safety_10msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Safety_CODE) Common_Safety_50msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Safety_CODE) Common_Safety_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Safety_CODE) Common_Safety_Nomal2Standby_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) Common_Safety_Standby2Nomal_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) SafetyMode_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) svCS_SWCSafety_ReceiveSafetyGearCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) svCS_SWCSafety_ReceiveSafetyTTCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Safety_CODE) svCS_SWCSafety_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Common_Safety_STOP_SEC_CODE
# include "Common_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_IPC_Send_Std_ReturnType (1U)

#  define RTE_E_IoHwAb_Interface_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)

#  define RTE_E_VConfig_GetUpdateTick_Std_ReturnType (1U)

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_SAFETY_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
