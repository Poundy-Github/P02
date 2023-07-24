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
 *             File:  Rte_OsApplication_Trust_OsCore0.c
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Ioc.h"
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_ADAU1978.h"
#include "Rte_AMP.h"
#include "Rte_BswM.h"
#include "Rte_CConfig.h"
#include "Rte_Can_Server.h"
#include "Rte_ComEx.h"
#include "Rte_ComM.h"
#include "Rte_Common_GateWay.h"
#include "Rte_Common_Normal.h"
#include "Rte_Common_Safety.h"
#include "Rte_Csm.h"
#include "Rte_DCM_Server.h"
#include "Rte_Dcm.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_DidDataProcess.h"
#include "Rte_EOL.h"
#include "Rte_EcuM.h"
#include "Rte_GNSS.h"
#include "Rte_Gyro.h"
#include "Rte_HSM.h"
#include "Rte_IIC.h"
#include "Rte_IPC.h"
#include "Rte_IoHwAb.h"
#include "Rte_KeyReturn.h"
#include "Rte_Log.h"
#include "Rte_Misc.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_Power.h"
#include "Rte_RTC.h"
#include "Rte_SOCManager.h"
#include "Rte_SecOC.h"
#include "Rte_SecOc_Server.h"
#include "Rte_SocDtcProcess.h"
#include "Rte_SysSafety.h"
#include "Rte_TM.h"
#include "Rte_Upgrade.h"
#include "Rte_Vconfig.h"
#include "Rte_WdgM_SystemApplication_OsCore0.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_CanTrcv_30_Tja1040.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_CorTst.h"
#include "SchM_Crypto_30_vHsm.h"
#include "SchM_Csm.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Fee_30_SmallSector.h"
#include "SchM_Fls.h"
#include "SchM_FlsTst.h"
#include "SchM_FvM.h"
#include "SchM_Gpt.h"
#include "SchM_Icu.h"
#include "SchM_Lin.h"
#include "SchM_LinTrcv_30_Tle7259.h"
#include "SchM_Mcu.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm.h"
#include "SchM_RamTst.h"
#include "SchM_SecOC.h"
#include "SchM_Spi.h"
#include "SchM_WdgM.h"
#include "SchM_Wdg_59_DriverA.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#define Rte_DisableAllInterrupts(Mode) Rte_DisableAllInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsKM() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsKM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsUM() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsUM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableGlobalAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsAM() osDisableGlobalAM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsAM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#define Rte_EnableAllInterrupts(Mode) Rte_EnableAllInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsKM() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsKM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsUM() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsUM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsAM() osEnableGlobalAM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsAM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#define Rte_DisableOSInterrupts(Mode) Rte_DisableOSInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsKM() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsKM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsUM() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsUM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableLevelAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsAM() osDisableLevelAM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsAM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#define Rte_EnableOSInterrupts(Mode) Rte_EnableOSInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsKM() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsKM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsUM() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsUM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsAM() osEnableLevelAM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsAM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(AVASDTCRet, RTE_VAR_INIT) Rte_AMP_AVASDTCResults_AVASDTC = {
  2U, 2U, 2U, 2U, 2U, 2U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(A_U8_10, RTE_VAR_INIT) Rte_AMP_EOL_AMPCalibrationRece_EOLReceive = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL9Bytes, RTE_VAR_INIT) Rte_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue = {
  17U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_AMP_Sd_AMP_Notify_Message_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_AMP_ppSR_AMPDeInitFinished_State = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_Power_Ecum_Set_SystemState_Run_Element = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(reset_type, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_ResetType_Element = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(wakeup_type, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource = 0ULL;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CconfigKind_400Bytes, RTE_VAR_INIT) Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_BswMRteModeBusStateReq, RTE_VAR_INIT) Rte_Can_Server_Request_CanServerBusStateReq_requestedMode = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_BswMRteVehicleTypeOptionChoose, RTE_VAR_INIT) Rte_Can_Server_Request_VehicleTypeOptionChoose_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint32, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DrvGearDisp, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dcm_Data200ByteType, RTE_VAR_INIT) Rte_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dcm_Data300ByteType, RTE_VAR_INIT) Rte_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(A_17Bytes, RTE_VAR_INIT) Rte_DidDataProcess_tiSR_VIN_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_AMPCalibration_AMPCalibration = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_KeepDownload_keepDownloadRID = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL13Bytes, RTE_VAR_INIT) Rte_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL_15Bytes, RTE_VAR_INIT) Rte_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(A_20Bytes, RTE_VAR_INIT) Rte_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL_13Bytes, RTE_VAR_INIT) Rte_EOL_EOL_SRpVehSparePartNumber_SparePartNumber = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL4Bytes, RTE_VAR_INIT) Rte_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_Gyro_ppSR_GyroDeInitFinished_State = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL3Bytes, RTE_VAR_INIT) Rte_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Power_IVI_10MIN_Backup_flag_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_BswMRteShutdownReqMode, RTE_VAR_INIT) Rte_Power_Request_PowerModeEmergencySleep_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_BswMRteShutdownReqMode, RTE_VAR_INIT) Rte_Power_Request_PowerModeShutdownReq_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_BswMRteModeVolEnable, RTE_VAR_INIT) Rte_Power_Request_PowerVolEnable_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_Power_Sd_BswM_Warm_Reset_Element = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SystemState_RecordType, RTE_VAR_INIT) Rte_Power_ppSR_Power_Out_SystemStateOut = {
  0U, 0U, 0U, 0U, 0U, {0U, 0.0}, 0U, {255U, 0}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(wakeup_type, RTE_VAR_INIT) Rte_Power_ppSR_WakeupReason_data = 0ULL;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(sint64, RTE_VAR_INIT) Rte_RTC_Sd_RTC_SleepDateTime = -1LL;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(sint64, RTE_VAR_INIT) Rte_RTC_Sd_RTC_UtcTime = -1LL;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SystemState = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SecOC_VerificationStatusType, RTE_VAR_INIT) Rte_SecOC_VerificationStatus_verificationStatus = {
  0U, 1U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint32, RTE_VAR_INIT) Rte_Upgrade_Sd_Upgrade_flag_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_Upgrade_ppSR_Upgrade_System_Recovery_System_Recovery = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(VconfigKind_Allbuffers, RTE_VAR_INIT) Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Can_Server_NvBlockNeed_ActiveWUCounter_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_SOCManager_NvBlockNeed_HealthSwitch_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_u8_20, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration2_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_u8_20, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_80Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeedSecAttemptCount_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeedSecAttmptCount_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_200Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_Dcm_VIN_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_8Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_300Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_E2ESwitch_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_200Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data4ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VIN_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data20ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleMode_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_30Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(EOL_13Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF187_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_20Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(EOL_15Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF193_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF195_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(RW_0xFD00, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFD00_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFD19_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE20_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE21_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE22_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(EOL_2Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE23_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE24_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(EOL_2Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE25_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(NvmResetInformation_t, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Misc_NvBlockNeed_ResetInfomation_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_OsApplication_Trust_OsCore0_AckFlags = {
  1,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Trust_OsCore0_AckFlagsInit() (Rte_MemClr(&Rte_OsApplication_Trust_OsCore0_AckFlags, sizeof(Rte_OsApplication_Trust_OsCore0_AckFlagsType)))
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Timeout Flags for each external Rx Signals with aliveTimeout != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Trust_OsCore0_RxTimeoutFlagsInit() (Rte_MemClr(&Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags, sizeof(Rte_OsApplication_Trust_OsCore0_RxTimeoutFlagsType)))


/**********************************************************************************************************************
 * Never Received Flags for each external Rx Signal with handleNeverReceived != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlagsInit() (Rte_MemClr(&Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags, sizeof(Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlagsType)))


/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trust_OsCore0_RxUpdateFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Trust_OsCore0_RxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_Trust_OsCore0_RxUpdateFlags, sizeof(Rte_OsApplication_Trust_OsCore0_RxUpdateFlagsType)))


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Rte_tsTT_GEAR, RTE_VAR_NOINIT) Rte_TT_GEAR; /* PRQA S 0759, 3408, 1514 */ /* MD_MSR_Union, MD_Rte_3408, MD_Rte_1514 */
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/
#define Rte_CS_ClientConfigIndex_Common_GateWay_CNA_SignalGroupSet_Operation 0U
#define Rte_CS_ClientConfigIndex_ComEx_CNA_SignalSet_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_CNA_SignalSet_Operation 1U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ABS3_Counter 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ECM2_Counter 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter 0U
#define Rte_CS_ClientConfigIndex_Can_Server_rpCS_ComEx_GetRxE2EStatus 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus 1U
#define Rte_CS_ClientConfigIndex_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus 2U
#define Rte_CS_ClientConfigIndex_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus 3U
#define Rte_CS_ClientConfigIndex_DCM_Server_rpCS_ComEx_GetRxE2EStatus 4U
#define Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_ComEx_GetRxE2EStatus 5U
#define Rte_CS_ClientConfigIndex_EOL_EOL_ComEx_GetRxE2EStatus 6U
#define Rte_CS_ClientConfigIndex_Power_ComEx_GetRxE2EStatus 7U
#define Rte_CS_ClientConfigIndex_SOCManager_ComEx_GetRxE2EStatus 8U
#define Rte_CS_ClientConfigIndex_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus 9U
#define Rte_CS_ClientConfigIndex_Upgrade_rpCS_ComEx_GetRxE2EStatus 10U
#define Rte_CS_ClientConfigIndex_Can_Server_rpCS_ComEx_SendSignal 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal 1U
#define Rte_CS_ClientConfigIndex_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal 2U
#define Rte_CS_ClientConfigIndex_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal 3U
#define Rte_CS_ClientConfigIndex_DCM_Server_rpCS_ComEx_SendSignal 4U
#define Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_ComEx_SendSignal 5U
#define Rte_CS_ClientConfigIndex_EOL_EOL_ComEx_SendSignal 6U
#define Rte_CS_ClientConfigIndex_Power_ComEx_SendSignal 7U
#define Rte_CS_ClientConfigIndex_SOCManager_ComEx_SendSignal 8U
#define Rte_CS_ClientConfigIndex_SecOc_Server_ComEx_SendSignal 9U
#define Rte_CS_ClientConfigIndex_SocDtcProcess_rpCS_ComEx_SendSignal 10U
#define Rte_CS_ClientConfigIndex_Upgrade_rpCS_ComEx_SendSignal 11U
#define Rte_CS_ClientConfigIndex_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster 0U
#define Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_HsmKeyM_GetAes128Key 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_HsmKeyM_SetAes128Key 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_Hsm_Port_TrngGenerate 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_IPC_DataSend_If_Operation 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_IoHwAb_Interface_GetPin 0U
#define Rte_CS_ClientConfigIndex_Common_Safety_IoHwAb_Interface_GetPin 1U
#define Rte_CS_ClientConfigIndex_Common_Normal_IoHwAb_Interface_GetVoltage 0U
#define Rte_CS_ClientConfigIndex_Common_Safety_IoHwAb_Interface_GetVoltage 1U
#define Rte_CS_ClientConfigIndex_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock 0U
#define Rte_CS_ClientConfigIndex_AMP_Os_Service_GetCounterValue 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_Os_Service_GetCounterValue 1U
#define Rte_CS_ClientConfigIndex_Common_Safety_Os_Service_GetCounterValue 2U
#define Rte_CS_ClientConfigIndex_IIC_Os_Service_GetCounterValue 3U
#define Rte_CS_ClientConfigIndex_Misc_Os_Service_GetCounterValue 4U
#define Rte_CS_ClientConfigIndex_Power_Os_Service_GetCounterValue 5U
#define Rte_CS_ClientConfigIndex_RTC_Os_Service_GetCounterValue 6U
#define Rte_CS_ClientConfigIndex_Vconfig_Os_Service_GetCounterValue 7U
#define Rte_CS_ClientConfigIndex_AMP_Os_Service_GetElapsedValue 0U
#define Rte_CS_ClientConfigIndex_Common_Normal_Os_Service_GetElapsedValue 1U
#define Rte_CS_ClientConfigIndex_Common_Safety_Os_Service_GetElapsedValue 2U
#define Rte_CS_ClientConfigIndex_IIC_Os_Service_GetElapsedValue 3U
#define Rte_CS_ClientConfigIndex_Misc_Os_Service_GetElapsedValue 4U
#define Rte_CS_ClientConfigIndex_Power_Os_Service_GetElapsedValue 5U
#define Rte_CS_ClientConfigIndex_RTC_Os_Service_GetElapsedValue 6U
#define Rte_CS_ClientConfigIndex_Common_Normal_IRTC_Service_GetUTCTimeInMillis 0U
#define Rte_CS_ClientConfigIndex_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar 1U
#define Rte_CS_ClientConfigIndex_Common_Normal_IRTC_Service_UTC2PerpetualCalendar 2U
#define Rte_CS_ClientConfigIndex_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar 3U
#define Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo 0U
#define Rte_CS_ClientConfigIndex_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 0U
#define Rte_CS_ClientConfigIndex_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 1U
#define Rte_CS_ClientConfigIndex_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 2U
#define Rte_CS_ClientConfigIndex_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 3U
#define Rte_CS_ClientConfigIndex_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 4U
#define Rte_CS_ClientConfigIndex_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 5U
#define Rte_CS_ClientConfigIndex_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig 6U
#define Rte_CS_ClientConfigIndex_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick 0U
#define Rte_CS_ClientConfigIndex_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick 1U

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_ClientIdleFlagsType, RTE_VAR_INIT) Rte_OsApplication_Trust_OsCore0_ClientIdleFlags = {
   1U
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Data structures for queue handling
 *********************************************************************************************************************/

#define RTE_Q_OK     ((Rte_QReturnType)0)
#define RTE_Q_EMPTY  ((Rte_QReturnType)1)
#define RTE_Q_FULL   ((Rte_QReturnType)2)

#define RTE_Q_Gyro_Rc_IPC_Gyro_Message_Element (0)
#define RTE_Q_IIC_Rc_IIC0_Notify_Message_Message (1)
#define RTE_Q_IIC_Rc_IIC1_Notify_Message_Message (2)

typedef uint8 Rte_QReturnType;
typedef uint8 Rte_QIndexType;

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementOsApplication_Trust_OsCore0(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData);
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementOsApplication_Trust_OsCore0(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData);
#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b0)
#define Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b1)
#define Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b2)

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Trust_OsCore0_QOverflowType, RTE_VAR_NOINIT) Rte_OsApplication_Trust_OsCore0_QOverflow; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_DCM_Server_PiDcmUserCondition_Mode = RTE_MODE_DCM_Server_DcmUserConditionMode_DCM_USER_CONDITON_NOT_OK; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Dcm_ControlDtcSettingType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting = RTE_MODE_Dcm_DcmControlDtcSetting_ENABLEDTCSETTING; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Dcm_DiagnosticSessionControlType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Dcm_EcuResetType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_1 (1UL)
#define RTE_CONST_MSEC_SystemTimer_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_100 (100UL)
#define RTE_CONST_MSEC_SystemTimer_14 (14UL)
#define RTE_CONST_MSEC_SystemTimer_19 (19UL)
#define RTE_CONST_MSEC_SystemTimer_2 (2UL)
#define RTE_CONST_MSEC_SystemTimer_20 (20UL)
#define RTE_CONST_MSEC_SystemTimer_27 (27UL)
#define RTE_CONST_MSEC_SystemTimer_4 (4UL)
#define RTE_CONST_MSEC_SystemTimer_5 (5UL)
#define RTE_CONST_MSEC_SystemTimer_50 (50UL)
#define RTE_CONST_MSEC_SystemTimer_500 (500UL)
#define RTE_CONST_MSEC_SystemTimer_7 (7UL)
#define RTE_CONST_MSEC_SystemTimer_8 (8UL)
#define RTE_CONST_MSEC_SystemTimer_9 (9UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


FUNC(void, RTE_CODE) Rte_InitMemory_OsApplication_Trust_OsCore0(void)
{
  /* reset Rx Timeout Flags */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* reset Rx Never Received Flags */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* initialize flags for update handling */
  Rte_OsApplication_Trust_OsCore0_RxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* set default values for internal data */
  Rte_AMP_AVASDTCResults_AVASDTC = Rte_C_AVASDTCRet_0;
  Rte_MemCpy(Rte_AMP_EOL_AMPCalibrationRece_EOLReceive, Rte_C_A_U8_10_0, sizeof(A_U8_10)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue, Rte_C_EOL9Bytes_0, sizeof(EOL9Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_AMP_Sd_AMP_Notify_Message_Element = 0U;
  Rte_AMP_ppSR_AMPDeInitFinished_State = FALSE;
  Rte_Power_Ecum_Set_SystemState_Run_Element = FALSE;
  Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource = 0U;
  Rte_BswM_Provide_BswMRteModeRequestPort_ResetType_Element = FALSE;
  Rte_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource = 0ULL;
  Rte_MemCpy32(Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes, Rte_C_CconfigKind_400Bytes_0, sizeof(CconfigKind_400Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag = 0U;
  Rte_Can_Server_Request_CanServerBusStateReq_requestedMode = 1U;
  Rte_Can_Server_Request_VehicleTypeOptionChoose_requestedMode = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2 = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2 = 0U;
  Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 = 0U;
  Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts = 0U;
  Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element = 0U;
  Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element = 0U;
  Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element = 0U;
  Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element = 1U;
  Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag = 0U;
  Rte_MemCpy32(Rte_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element, Rte_C_Dcm_Data200ByteType_0, sizeof(Dcm_Data200ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag = 0U;
  Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element = 0U;
  Rte_MemCpy32(Rte_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element, Rte_C_Dcm_Data300ByteType_0, sizeof(Dcm_Data300ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery = FALSE;
  Rte_MemCpy32(Rte_DidDataProcess_tiSR_VIN_Element, Rte_C_A_17Bytes_1, sizeof(A_17Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EOL_EOL_AMPCalibration_AMPCalibration = 0U;
  Rte_EOL_EOL_KeepDownload_keepDownloadRID = 0U;
  Rte_MemCpy(Rte_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187, Rte_C_EOL13Bytes_0, sizeof(EOL13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193, Rte_C_EOL_15Bytes_0, sizeof(EOL_15Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C, Rte_C_A_20Bytes_0, sizeof(A_20Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_EOL_EOL_SRpVehSparePartNumber_SparePartNumber, Rte_C_EOL_13Bytes_0, sizeof(EOL_13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01, Rte_C_EOL4Bytes_0, sizeof(EOL4Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Gyro_ppSR_GyroDeInitFinished_State = FALSE;
  Rte_MemCpy(Rte_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0, Rte_C_EOL3Bytes_0, sizeof(EOL3Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount = 0U;
  Rte_Power_IVI_10MIN_Backup_flag_Element = 0U;
  Rte_Power_Request_PowerModeEmergencySleep_requestedMode = 0U;
  Rte_Power_Request_PowerModeShutdownReq_requestedMode = 0U;
  Rte_Power_Request_PowerVolEnable_requestedMode = 0U;
  Rte_Power_Sd_BswM_Warm_Reset_Element = FALSE;
  Rte_Power_ppSR_Power_Out_SystemStateOut = Rte_PowerOutInit;
  Rte_Power_ppSR_WakeupReason_data = 0ULL;
  Rte_RTC_Sd_RTC_SleepDateTime = -1LL;
  Rte_RTC_Sd_RTC_UtcTime = -1LL;
  Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element = FALSE;
  Rte_SOCManager_ppSR_SocManager_SystemState = 0U;
  Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady = FALSE;
  Rte_SecOC_VerificationStatus_verificationStatus = Rte_C_SecOC_VerificationStatusType_0;
  Rte_SocDtcProcess_ClearDTC_Service0x14_StatusFlag = 0U;
  Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter = 0U;
  Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element = 0U;
  Rte_Upgrade_Sd_Upgrade_flag_Element = 0U;
  Rte_Upgrade_ppSR_Upgrade_System_Recovery_System_Recovery = FALSE;
  Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag = 0U;
  Rte_MemCpy32(Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, Rte_C_VconfigKind_Allbuffers_0, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  /* reset Tx Ack Flags */
  Rte_OsApplication_Trust_OsCore0_AckFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_OsApplication_Trust_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP;

  Rte_ModeMachine_DCM_Server_PiDcmUserCondition_Mode = RTE_MODE_DCM_Server_DcmUserConditionMode_DCM_USER_CONDITON_NOT_OK;

  Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting = RTE_MODE_Dcm_DcmControlDtcSetting_ENABLEDTCSETTING;

  Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION;

  Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE;

  Rte_OsApplication_Trust_OsCore0_ClientIdleFlags.Rte_Idle_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar = 1U;

  Rte_CS_WaitingTaskList_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar[0] = INVALID_TASK;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_AMP_Sd_IIC0_Notify_Message_Message(uint16 data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC0_Notify_Message_Message, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(&data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: IIC0_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_IIC_IIC0_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_AVASDTCResults_AVASDTC(P2CONST(AVASDTCRet, AUTOMATIC, RTE_AMP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_AMP_AVASDTCResults_AVASDTC = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_AMPCalibrationRece_EOLReceive(P2CONST(A_U8_10, AUTOMATIC, RTE_AMP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_AMP_EOL_AMPCalibrationRece_EOLReceive, *(data), sizeof(A_U8_10)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2CONST(EOL9Bytes, AUTOMATIC, RTE_AMP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue, *(data), sizeof(EOL9Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_Sd_AMP_Notify_Message_Element(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AMP_Sd_AMP_Notify_Message_Element = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: AMP_Event_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_AMP_AMP_Event_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_Element(boolean data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Power_Ecum_Set_SystemState_Run_Element = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource(reset_type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetType_Element(boolean data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_BswM_Provide_BswMRteModeRequestPort_ResetType_Element = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource(wakeup_type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2CONST(CconfigKind_400Bytes, AUTOMATIC, RTE_CCONFIG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes, *(data), sizeof(CconfigKind_400Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element(P2CONST(Dcm_Data200ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element, *(data), sizeof(Dcm_Data200ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2CONST(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element, *(data), sizeof(Dcm_Data300ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_tiSR_VIN_Element(P2CONST(A_17Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_DidDataProcess_tiSR_VIN_Element, *(data), sizeof(A_17Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187(P2CONST(EOL13Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187, *(data), sizeof(EOL13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2CONST(EOL_15Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193, *(data), sizeof(EOL_15Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2CONST(A_20Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C, *(data), sizeof(A_20Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_SRpVehSparePartNumber_SparePartNumber(P2CONST(EOL_13Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(Rte_EOL_EOL_SRpVehSparePartNumber_SparePartNumber, *(data), sizeof(EOL_13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2CONST(EOL4Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01, *(data), sizeof(EOL4Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_Gyro_Sd_IIC1_Notify_Message_Message(uint16 data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC1_Notify_Message_Message, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(&data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: IIC1_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_IIC_IIC1_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_Gyro_Sd_IPC_Gyro_Message_Element(P2CONST(A_U8_10, AUTOMATIC, RTE_GYRO_APPL_DATA) data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_Gyro_Rc_IPC_Gyro_Message_Element, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_IIC_Sd_IIC0_Notify_Message_Message(uint16 data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC0_Notify_Message_Message, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(&data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: IIC0_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_IIC_IIC0_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_IIC_Sd_IIC1_Notify_Message_Message(uint16 data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC1_Notify_Message_Message, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(&data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: IIC1_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_IIC_IIC1_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2CONST(EOL3Bytes, AUTOMATIC, RTE_MISC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0, *(data), sizeof(EOL3Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode(BswM_BswMRteShutdownReqMode data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Power_Request_PowerModeEmergencySleep_requestedMode = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: BswM_Read_PowerModeShutdownReq_EmergencySleep */
  (void)SetEvent(Default_BSW, Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq_EmergencySleep); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(BswM_BswMRteShutdownReqMode data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Power_Request_PowerModeShutdownReq_requestedMode = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: BswM_Read_PowerModeShutdownReq */
  (void)SetEvent(Default_BSW, Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Sd_Cluster_Shutdown_Status_Element(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  (void)IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1(*(&data)); /* PRQA S 1339 */ /* MD_Rte_1339 */
  (void)IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1(*(&data)); /* PRQA S 1339 */ /* MD_Rte_1339 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_ppSR_Power_Out_SystemStateOut(P2CONST(SystemState_RecordType, AUTOMATIC, RTE_POWER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Power_ppSR_Power_Out_SystemStateOut = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Power_ppSR_Power_Out_SystemStateOut = 1U; /* PRQA S 2982 */ /* MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_RTC_Sd_IIC1_Notify_Message_Message(uint16 data) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_QAddElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC1_Notify_Message_Message, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(&data)) == RTE_Q_FULL) /* PRQA S 0314, 1340 */ /* MD_Rte_0314, MD_Rte_1340 */
  {
    SuspendOSInterrupts();
    Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message = 1U;
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: IIC1_MainFunction */
  (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_IIC_IIC1_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RTC_Sd_RTC_SleepDateTime(sint64 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_RTC_Sd_RTC_SleepDateTime = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RTC_Sd_RTC_UtcTime(sint64 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_RTC_Sd_RTC_UtcTime = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SecOC_VerificationStatus_verificationStatus(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SECOC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SecOC_VerificationStatus_verificationStatus = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter(uint32 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds(P2CONST(VconfigKind_Allbuffers, AUTOMATIC, RTE_VCONFIG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, *(data), sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AMP_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_AMP_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_CanCommunicationVolEnable_requestedMode(P2VAR(BswM_BswMRteModeVolEnable, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Power_Request_PowerVolEnable_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_CanServerBusStateReq_requestedMode(P2VAR(BswM_BswMRteModeBusStateReq, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Can_Server_Request_CanServerBusStateReq_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_PowerModeShutdownReq_requestedMode(P2VAR(BswM_BswMRteShutdownReqMode, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Power_Request_PowerModeShutdownReq_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_PowerModeShutdownReq_EmergencySleep_requestedMode(P2VAR(BswM_BswMRteShutdownReqMode, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Power_Request_PowerModeEmergencySleep_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_VehicleTypeOptionChoose_requestedMode(P2VAR(BswM_BswMRteVehicleTypeOptionChoose, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Can_Server_Request_VehicleTypeOptionChoose_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CConfig_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2VAR(Dcm_Data300ByteType, AUTOMATIC, RTE_CCONFIG_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(*(data), Rte_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element, sizeof(Dcm_Data300ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(*(data), Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_rpSR_RTCTimer_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_RTC_Sd_RTC_UtcTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Can_Server_tiSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes, sizeof(CconfigKind_400Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Safety_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DCM_Server_ppSR_DCMServer_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DCM_Server_ppSR_DCMServer_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_SR_RpVehSparePartNumber_SparePartNumber(P2VAR(EOL_13Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(*(data), Rte_EOL_EOL_SRpVehSparePartNumber_SparePartNumber, sizeof(EOL_13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(*(data), Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_ppSR_Diag_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_ppSR_Diag_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_rpSR_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_rpSR_Power_Out_DidProcess_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_AMPCalibrationRece_EOLReceive(P2VAR(A_U8_10, AUTOMATIC, RTE_EOL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(*(data), Rte_AMP_EOL_AMPCalibrationRece_EOLReceive, sizeof(A_U8_10)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_BatteryVoltage_0xFD10_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_EOL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_KL15Status_0xFD15_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_EOL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2VAR(EOL3Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(*(data), Rte_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0, sizeof(EOL3Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2VAR(EOL9Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(*(data), Rte_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue, sizeof(EOL9Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Gyro_Rc_IPC_Gyro_Message_Element(P2VAR(A_U8_10, AUTOMATIC, RTE_GYRO_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    Std_ReturnType lost_data = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    Rte_QReturnType retQueue;
    SuspendOSInterrupts();
    if (Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element == 1U)
    {
      /* reset errorflag */
      Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element = 0U;
      lost_data = RTE_E_LOST_DATA;
    }
    ResumeOSInterrupts();
    retQueue = Rte_QUnqueueElementOsApplication_Trust_OsCore0(RTE_Q_Gyro_Rc_IPC_Gyro_Message_Element, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data)); /* PRQA S 0314 */ /* MD_Rte_0314 */
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Gyro_RcSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_GYRO_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_IIC_Rc_IIC0_Notify_Message_Message(P2VAR(uint16, AUTOMATIC, RTE_IIC_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    Std_ReturnType lost_data = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    Rte_QReturnType retQueue;
    SuspendOSInterrupts();
    if (Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message == 1U)
    {
      /* reset errorflag */
      Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message = 0U;
      lost_data = RTE_E_LOST_DATA;
    }
    ResumeOSInterrupts();
    retQueue = Rte_QUnqueueElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC0_Notify_Message_Message, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data)); /* PRQA S 0314 */ /* MD_Rte_0314 */
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_IIC_Rc_IIC1_Notify_Message_Message(P2VAR(uint16, AUTOMATIC, RTE_IIC_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    Std_ReturnType lost_data = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    Rte_QReturnType retQueue;
    SuspendOSInterrupts();
    if (Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message == 1U)
    {
      /* reset errorflag */
      Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message = 0U;
      lost_data = RTE_E_LOST_DATA;
    }
    ResumeOSInterrupts();
    retQueue = Rte_QUnqueueElementOsApplication_Trust_OsCore0(RTE_Q_IIC_Rc_IIC1_Notify_Message_Message, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data)); /* PRQA S 0314 */ /* MD_Rte_0314 */
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Misc_tiSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_MISC_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Power_Rc_Cluster_Shutdown_Status_Element(P2VAR(uint8, AUTOMATIC, RTE_POWER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  (void)IocRead_Rte_Power_Rc_Cluster_Shutdown_Status_Element(data);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Power_Rc_Wakeup_Reason_WakeupSource(P2VAR(wakeup_type, AUTOMATIC, RTE_POWER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RTC_RcSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_RTC_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_SOCManager_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_SOCManager_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SecOc_Server_VerificationStatus_verificationStatus(P2VAR(SecOC_VerificationStatusType, AUTOMATIC, RTE_SECOC_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SecOC_VerificationStatus_verificationStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SecOc_Server_tiSR_VIN_Element(P2VAR(A_17Bytes, AUTOMATIC, RTE_SECOC_SERVER_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_DidDataProcess_tiSR_VIN_Element, sizeof(A_17Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_ppSR_DTC_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_ppSR_DTC_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  if (Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Common_Normal_ppSR_SWCNormal_OdoParament_Element == 0U)
  {
    ret = RTE_E_NEVER_RECEIVED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_RTCTimer_SleepDateTime(P2VAR(sint64, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_RTC_Sd_RTC_SleepDateTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SocDtcProcess_rpSR_RTCTimer_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_RTC_Sd_RTC_UtcTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Vconfig_ECUlevelNetworkConfigurationDataIdentifier_Element(P2VAR(Dcm_Data200ByteType, AUTOMATIC, RTE_VCONFIG_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(*(data), Rte_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element, sizeof(Dcm_Data200ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_AMP_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_AMP_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId = kindId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) date) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 1;
    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_ClientId = Rte_CS_ClientConfigIndex_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar;

    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.utc = utc;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RTC_UTC2PerpetualCalendar */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_UTC2PerpetualCalendar); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *date = Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar.date;

      ret = Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Can_Server_rpCS_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Can_Server_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Can_Server_rpCS_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ComEx_rpCS_CNA_Signal_CallBack(uint16 signalId) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  CNA_SignalCallBack(signalId);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ComEx_CNA_SignalSet_Operation(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_COMEX_APPL_VAR) value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Active = 1;
    Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_ComEx_CNA_SignalSet_Operation;

    Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.signalId = signalId;
    Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.value = *value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: CNA_SignalSet */
    (void)SetEvent(BSW_COMM, Rte_Ev_Run_Can_Server_CNA_SignalSet); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *value = Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.value;

      ret = Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_IoHwAb_Interface_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Pin) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Active = 1;
    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_IoHwAb_Interface_GetPin;

    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin.Id = Id;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: IoHwAb_GetPin */
    (void)SetEvent(SYS, Rte_Ev_Run_IoHwAb_IoHwAb_GetPin); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Pin = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin.Pin;

      ret = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_IoHwAb_Interface_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Voltage) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Active = 1;
    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_IoHwAb_Interface_GetVoltage;

    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage.Id = Id;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: IoHwAb_GetVoltage */
    (void)SetEvent(SYS, Rte_Ev_Run_IoHwAb_IoHwAb_GetVoltage); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Voltage = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage.Voltage;

      ret = Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId = kindId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) updateTick) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *updateTick = Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.updateTick;

      ret = Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_TT_GEAR)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Csm_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Csm_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId = kindId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_Default_BSW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(Default_BSW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_Default_BSW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_DCM_Server_rpCS_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_Default_BSW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(Default_BSW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_Default_BSW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_DCM_Server_rpCS_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_Default_BSW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(Default_BSW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_Default_BSW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_battery_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_ground_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_ControlModuleCANBus_off_Bus_off_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_BacklightModuleError_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_ForceInductionFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_LowVoltage_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_NotReceiveBacklightValue_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_OverVoltage_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TFT_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TouchPanelFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VibratorFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VideoSignalConnectFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ASIC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_TCP_communication_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_AVM_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_ConsoleDisplay_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DMS_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DVR_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IP_Display_Front_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IVI_Display_Front_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_InCarCamera_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_PassengerDisplay_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_RVC_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_W_HUD_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_GWSecOcFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_TBoxSecOcFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_software_module_running_error_Unexpected_Operation_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation(P2VAR(Diag_9Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) arg) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation;

  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  {

    /* scheduled trigger for runnables: Fuel_Api_ParamentGetCsPort_Operation */
    (void)SetEvent(FUEL_TC_ODO, Rte_Ev_Run_Common_Normal_Fuel_Api_ParamentGetCsPort_Operation); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_BSW_COMM); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(BSW_COMM, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_BSW_COMM)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      Rte_MemCpy(*arg, Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation.arg, sizeof(Diag_9Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_EOL_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_EOL_EOL_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_EOL_EOL_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(EOL_6Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) arg) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_Active = 1;
  Rte_CS_ServerQueue_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_ClientId = Rte_CS_ClientConfigIndex_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster;

  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  {

    /* scheduled trigger for runnables: EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster */
    (void)SetEvent(FUEL_TC_ODO, Rte_Ev_Run_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_BSW_COMM); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(BSW_COMM, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_BSW_COMM)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      Rte_MemCpy(*arg, Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.arg, sizeof(EOL_6Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId = kindId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IIC_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_IIC_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_IIC_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IIC_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_IIC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_IIC_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_IIC_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Misc_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Misc_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Misc_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Misc_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvBlockNeed_LC_Calibration_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvBlockNeed_LC_Calibration2_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_ActiveWUCounter_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_ActiveWUCounter_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Menu_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterInternalConfiguration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_E2ESwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_FactoryMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_SecOcSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleSoftwareVersion_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF187_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xF187_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF18C_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xF18C_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF193_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xF193_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF195_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xF195_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD00_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFD00_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD19_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFD19_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE20_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE20_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE21_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE21_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE22_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE22_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE23_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE23_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE24_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE24_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE25_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvMNotifyJobFinished_0xFE25_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_SOCManagerNvBlockNeed_HealthSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  NvBlockNeed_HealthSwitch_JobFinished(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ADAU_server_StateToDeInit(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ADAU_StateToDeInit();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ADAU_server_StateToInit(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ADAU_StateToInit();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_GW_List_Deinit(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_GW_List_Deinit();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_GW_List_Int(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_GW_List_Int();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_Normal_List_Deinit(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Normal_List_Deinit();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_Normal_List_Int(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Normal_List_Int();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_SF_List_Deinit(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_SF_List_Deinit();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Common_SF_List_Int(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_SF_List_Int();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Gyro_Init_server_Operation(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Gyro_Init();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_IPC_Init_Server_Operation(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  IPC_Init();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Rtc_Init_server_Operation(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  RTC_Init();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Nomal2StandbyCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_GateWay_Nomal2Standby_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_GateWay_PowerTransfer_Standby2NomalCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_GateWay_Standby2Nomal_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Nomal2StandbyCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Normal_Nomal2Standby_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Nomal_PowerTransfer_Standby2NomalCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Normal_Standby2Nomal_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Nomal2StandbyCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Safety_Nomal2Standby_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_rcCS_Common_Safety_PowerTransfer_Standby2NomalCallback(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Common_Safety_Standby2Nomal_Callbcak();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_POWER_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Power_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Power_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Power_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Power_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Power_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Power_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Power_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_POWER_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Power_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RTC_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_RTC_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_RTC_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RTC_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_RTC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_RTC_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_RTC_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Value = *Value;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetElapsedValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_DRIVERS_SAFE)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SOCManager_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_SOCManager_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SOCManager_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_SOCManager_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SecOc_Server_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_SecOc_Server_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_BSW_COMM); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(BSW_COMM, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_BSW_COMM)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId = kindId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
    (void)SetEvent(SYS, Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) date) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  TaskType task;
  EventMaskType ev;
  boolean callCompleted;

  (void)GetTaskID(&task); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_OsApplication_Trust_OsCore0_ClientIdleFlags.Rte_Idle_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar == 1U)
  {
    Rte_CS_WaitingTaskList_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar[0] = task;
    if (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free > 0U)
    {
      Rte_OsApplication_Trust_OsCore0_ClientIdleFlags.Rte_Idle_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar = 0U;
      Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 1;
      Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_ClientId = Rte_CS_ClientConfigIndex_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar;

      Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.utc = utc;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RTC_UTC2PerpetualCalendar */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_UTC2PerpetualCalendar); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (RTE_TASK_WAITPOINT_EVENT_MASK)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *date = Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar.date;

      ret = Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

    Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_ClientIdleFlags.Rte_Idle_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar = 1U;
    Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SocDtcProcess_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_SocDtcProcess_rpCS_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SWC_LOW)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Upgrade_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_UPGRADE_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Upgrade_rpCS_ComEx_GetRxE2EStatus;

    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId = GroupId;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_GetRxE2EStatus */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Upgrade_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Upgrade_rpCS_ComEx_SendSignal;

    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId = SignalId;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr = SignalDataPtr;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length = Length;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: ComEx_SendSignal */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_ComEx_ComEx_SendSignal); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Vconfig_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_VCONFIG_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Vconfig_Os_Service_GetCounterValue;

  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: GetCounterValue */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_SYS)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_globalStateChangeCbk_Core0_GlobalStatusCallback(WdgM_GlobalStatusType Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  WdgM_GlobalStatusCallback(Status);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_GEAR_LocalStatusCallback(WdgM_LocalStatusType Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  WdgM_LocalStatusCallback_Gear(Status);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_TT_LocalStatusCallback(WdgM_LocalStatusType Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  WdgM_LocalStatusCallback_TT(Status);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SystemApplication_OsCore0_localStateChangeCbk_WdgMSupervisedEntity_test_LocalStatusCallback(WdgM_LocalStatusType Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  WdgM_LocalStatusCallback_Power(Status);

  return ret;
}


/**********************************************************************************************************************
 * Queue handling functions
 *********************************************************************************************************************/

RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementOsApplication_Trust_OsCore0(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData)
{
  Rte_QReturnType ret = RTE_Q_FULL;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]);
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]);

  SuspendOSInterrupts();
  if (pRamI->Rte_ElementCtr < pRomI->Rte_MaxElements)
  {
    uint8_least writeCtr = pRamI->Rte_WriteCtr;
    if (writeCtr < (pRomI->Rte_MaxElements - 1U))
    {
      ++writeCtr;
    }
    else
    {
      writeCtr = 0U;
    }
    pRamI->Rte_WriteCtr = (uint8)writeCtr;
    pRamI->Rte_ElementCtr++;
    Rte_MemCpy((void *)&((uint8 *)pRomI->Rte_BasePtr)[writeCtr * pRomI->Rte_BytesPerElement], pData, pRomI->Rte_BytesPerElement); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    ret = RTE_Q_OK;
  }
  ResumeOSInterrupts();

  return(ret);
}


RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementOsApplication_Trust_OsCore0(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData)
{
  Rte_QReturnType ret = RTE_Q_EMPTY;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]);
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]);

  SuspendOSInterrupts();
  if (0U < pRamI->Rte_ElementCtr)
  {
    uint8_least readCtr = pRamI->Rte_ReadCtr;
    if (readCtr < (pRomI->Rte_MaxElements - 1U))
    {
      ++readCtr;
    }
    else
    {
      readCtr = 0U;
    }
    pRamI->Rte_ReadCtr = (uint8)readCtr;
    pRamI->Rte_ElementCtr--;
    Rte_MemCpy(pData, (void *)&((uint8 *)pRomI->Rte_BasePtr)[readCtr * pRomI->Rte_BytesPerElement], pRomI->Rte_BytesPerElement); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    ret = RTE_Q_OK;
  }
  ResumeOSInterrupts();

  return(ret);
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_ESH_Mode(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_ESH_Mode currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_ESH_Mode(currentMode);
  if (internalIndexNextMode >= 6U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 6U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  BswM_ESH_Mode curMode;
  curMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Can_Server_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  return curMode;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_DCM_Server_PiDcmUserCondition_Mode(uint8 nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 currentMode;
  Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  currentMode = Rte_ModeMachine_DCM_Server_PiDcmUserCondition_Mode;
  if (nextMode >= 2U)
  {
    Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 2U)
  {
    Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_DCM_Server_PiDcmUserCondition_Mode = nextMode;
    Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_ControlDtcSettingType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_DiagnosticSessionControlType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(currentMode);
  if (internalIndexNextMode >= 4U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 4U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_EcuResetType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(currentMode);
  if (internalIndexNextMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;
    Rte_OsApplication_Trust_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Dcm_Dcm_Read_Mode_Dcm_Read_Mode(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) nextMode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  SuspendOSInterrupts();
  curMode = Rte_ModeMachine_DCM_Server_PiDcmUserCondition_Mode;
  *(previousMode) = curMode;
  *(nextMode) = curMode;
  ResumeOSInterrupts();
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_DidDataProcess_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmControlDtcSetting_DcmControlDtcSetting(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmEcuReset_DcmEcuReset(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Power_DcmEcuReset_DcmEcuReset(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  return curMode;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     BSW_COMM
 * Priority: 8
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(BSW_COMM) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_BSW_COMM_0_10ms | Rte_Ev_Cyclic2_BSW_COMM_0_2ms | Rte_Ev_Cyclic2_BSW_COMM_0_5ms | Rte_Ev_Run_CConfig_CConfig_MainFunction | Rte_Ev_Run_Can_Server_CNA_SignalGroupSet | Rte_Ev_Run_Can_Server_CNA_SignalSet | Rte_Ev_Run_Can_Server_CNA_SignalSetNoTrigger | Rte_Ev_Run_Can_Server_CNA_SignalSet_U8N | Rte_Ev_Run_FvM_FvM_MainFunction | Rte_Ev_Run_SecOc_Server_SecOc_Server_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(BSW_COMM, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_BSW_COMM_0_10ms | Rte_Ev_Cyclic2_BSW_COMM_0_2ms | Rte_Ev_Cyclic2_BSW_COMM_0_5ms | Rte_Ev_Run_CConfig_CConfig_MainFunction | Rte_Ev_Run_Can_Server_CNA_SignalGroupSet | Rte_Ev_Run_Can_Server_CNA_SignalSet | Rte_Ev_Run_Can_Server_CNA_SignalSetNoTrigger | Rte_Ev_Run_Can_Server_CNA_SignalSet_U8N | Rte_Ev_Run_FvM_FvM_MainFunction | Rte_Ev_Run_SecOc_Server_SecOc_Server_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Can_MainFunction_Write();
    }

    if ((ev & Rte_Ev_Run_Can_Server_CNA_SignalSet) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSet_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.Rte_ClientId;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = CNA_SignalSet(Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.signalId, &ClientQueue->value);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Run_Can_Server_CNA_SignalSetNoTrigger) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSetNoTrigger_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CNA_SignalSetNoTrigger_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = CNA_SignalSetNoTrigger(Rte_CS_ServerQueue_Can_Server_CNA_SignalSetNoTrigger_Operation.signalId, &ClientQueue->value);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CNA_SignalSetNoTrigger_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Can_Server_CNA_SignalSet_U8N) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_U8N_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSet_U8N_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_U8N_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_U8N_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_U8N_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = CNA_SignalSet_U8N(Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_U8N_Operation.signalId, &ClientQueue->value);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_U8N_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Can_Server_CNA_SignalGroupSet) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalGroupSet_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalGroupSet_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalGroupSet_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CNA_SignalGroupSet_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CNA_SignalGroupSet_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = CNA_SignalGroupSet(&Rte_CS_ServerQueue_Can_Server_CNA_SignalGroupSet_Operation.event_signal_info);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CNA_SignalGroupSet_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionTx();

      /* call schedulable entity */
      Com_MainFunctionRx();

      /* call schedulable entity */
      CanNm_MainFunction();

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      CanTp_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_BusOff();
    }

    if ((ev & Rte_Ev_Run_FvM_FvM_MainFunction) != (EventMaskType)0)
    {
      /* call schedulable entity */
      FvM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      Csm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Crypto_30_vHsm_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      SecOC_MainFunctionRx(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SecOc_Server_SecOc_Server_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      SecOc_Server_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      SecOC_MainFunctionTx(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_CConfig_CConfig_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      CConfig_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();

      /* call schedulable entity */
      Rte_ComSendSignalProxyPeriodic();

      /* call schedulable entity */
      Can_MainFunction_Read();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_COMM_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTrcv_30_Tja1040_MainFunction();

      /* call runnable */
      Dcm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      WdgM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     BSW_DIAGNOSE
 * Priority: 4
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(BSW_DIAGNOSE) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_BSW_DIAGNOSE_0_10ms | Rte_Ev_Run_DemSatellite_0_SetEventStatus); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(BSW_DIAGNOSE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_BSW_DIAGNOSE_0_10ms | Rte_Ev_Run_DemSatellite_0_SetEventStatus)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_BSW_DIAGNOSE_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Dem_MasterMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_SatelliteMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DemSatellite_0_SetEventStatus) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = Dem_SetEventStatus((Dem_EventIdType)7, Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.EventStatus);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = Dem_SetEventStatus((Dem_EventIdType)8, Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.EventStatus);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = Dem_SetEventStatus((Dem_EventIdType)9, Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.EventStatus);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = Dem_SetEventStatus((Dem_EventIdType)10, Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.EventStatus);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     DRIVERS_SAFE
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(DRIVERS_SAFE) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  ADAU1978_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Logger_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  ComEx_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SysSafety_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  GNSS_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_DRIVERS_SAFE_0_100ms | Rte_Ev_Cyclic_DRIVERS_SAFE_0_50ms | Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms | Rte_Ev_Run_AMP_AMP_Event_MainFunction | Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus | Rte_Ev_Run_ComEx_ComEx_SendSignal | Rte_Ev_Run_Gyro_Gyro_MainFunction | Rte_Ev_Run_IIC_IIC0_MainFunction | Rte_Ev_Run_IIC_IIC1_MainFunction | Rte_Ev_Run_RTC_GetUTCTimeInMillis | Rte_Ev_Run_RTC_UTC2PerpetualCalendar); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(DRIVERS_SAFE, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_DRIVERS_SAFE_0_100ms | Rte_Ev_Cyclic_DRIVERS_SAFE_0_50ms | Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms | Rte_Ev_Run_AMP_AMP_Event_MainFunction | Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus | Rte_Ev_Run_ComEx_ComEx_SendSignal | Rte_Ev_Run_Gyro_Gyro_MainFunction | Rte_Ev_Run_IIC_IIC0_MainFunction | Rte_Ev_Run_IIC_IIC1_MainFunction | Rte_Ev_Run_RTC_GetUTCTimeInMillis | Rte_Ev_Run_RTC_UTC2PerpetualCalendar)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      RTC_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RTC_CycleTask(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if (((ev & Rte_Ev_Run_IIC_IIC1_MainFunction) != (EventMaskType)0) || ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0))
    {
      /* call runnable */
      IIC1_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if (((ev & Rte_Ev_Run_IIC_IIC0_MainFunction) != (EventMaskType)0) || ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0))
    {
      /* call runnable */
      IIC0_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Gyro_Gyro_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      Gyro_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      AMP_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      Logger_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_AMP_AMP_Event_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      AMP_Event_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      ADAU1978_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_RTC_UTC2PerpetualCalendar) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_ClientId;
        if (clientId >= 4U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_RTC_Sv_RTC_UTC2PerpetualCalendar[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = RTC_UTC2PerpetualCalendar(Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.utc, &ClientQueue->date);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_RTC_Sv_RTC_UTC2PerpetualCalendar[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      SysSafety_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_ComEx_ComEx_GetRxE2EStatus) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId;
        if (clientId >= 11U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_ComEx_ComEx_GetRxE2EStatus[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = ComEx_GetRxE2EStatus(Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.GroupId, &ClientQueue->E2eStatus);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_ComEx_ComEx_GetRxE2EStatus[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComEx_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_RTC_GetUTCTimeInMillis) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_GetUTCTimeInMillis, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_RTC_Sv_RTC_GetUTCTimeInMillis[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = RTC_GetUTCTimeInMillis(&ClientQueue->arg);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_RTC_Sv_RTC_GetUTCTimeInMillis[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_ComEx_ComEx_SendSignal) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId;
        if (clientId >= 12U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_ComEx_ComEx_SendSignal[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = ComEx_SendSignal(Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalId, Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.SignalDataPtr, Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Length);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_ComEx_ComEx_SendSignal[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Cyclic_DRIVERS_SAFE_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      GNSS_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Default_BSW
 * Priority: 7
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Default_BSW) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Default_BSW_0_10ms | Rte_Ev_Cyclic2_Default_BSW_0_5ms | Rte_Ev_Cyclic2_Default_BSW_1_5ms | Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq | Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq_EmergencySleep | Rte_Ev_Run_DCM_Server_DCM_Server_MainFunction | Rte_Ev_Run_HSM_HsmGetAes128Key | Rte_Ev_Run_HSM_HsmSetAes128Key | Rte_Ev_Run_HSM_HsmTrngGenerate | Rte_Ev_Run_HSM_Hsm_MainFunction | Rte_Ev_Run_Misc_NVM_Read_Speedup_Runnable | Rte_Ev_Run_NvM_WriteBlock | Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue | Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Default_BSW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Default_BSW_0_10ms | Rte_Ev_Cyclic2_Default_BSW_0_5ms | Rte_Ev_Cyclic2_Default_BSW_1_5ms | Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq | Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq_EmergencySleep | Rte_Ev_Run_DCM_Server_DCM_Server_MainFunction | Rte_Ev_Run_HSM_HsmGetAes128Key | Rte_Ev_Run_HSM_HsmSetAes128Key | Rte_Ev_Run_HSM_HsmTrngGenerate | Rte_Ev_Run_HSM_Hsm_MainFunction | Rte_Ev_Run_Misc_NVM_Read_Speedup_Runnable | Rte_Ev_Run_NvM_WriteBlock | Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue | Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Os_OsCore0_swc_GetCounterValue) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId;
        if (clientId >= 8U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = GetCounterValue((CounterType)SystemTimer, &ClientQueue->Value);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Run_Os_OsCore0_swc_GetElapsedValue) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId;
        if (clientId >= 7U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = GetElapsedValue((CounterType)SystemTimer, &ClientQueue->Value, &ClientQueue->ElapsedValue);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Run_DCM_Server_DCM_Server_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      DCM_Server_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_Read_PowerModeShutdownReq(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_BswM_BswM_Read_PowerModeShutdownReq_EmergencySleep) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_Read_PowerModeShutdownReq_EmergencySleep(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Spi_MainFunction_Handling();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_1_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      NvM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Fee_30_SmallSector_MainFunction();

      /* call schedulable entity */
      Fls_MainFunction();
    }

    if ((ev & Rte_Ev_Run_NvM_WriteBlock) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)48, Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)47, Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)23, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)13, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)15, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)17, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)19, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)21, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)25, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      while (Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = NvM_WriteBlock((NvM_BlockIdType)58, Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.SrcPtr);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Misc_NVM_Read_Speedup_Runnable) != (EventMaskType)0)
    {
      /* call runnable */
      NVM_Read_Speedup_Runnable(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CorTst_MainFunction();

      /* call schedulable entity */
      FlsTst_MainFunction();
    }

    if ((ev & Rte_Ev_Run_HSM_Hsm_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      Hsm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_HSM_HsmTrngGenerate) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_HSM_Hsm_Port_TrngGenerate.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_HSM_Hsm_Port_TrngGenerate, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_HSM_Hsm_Port_TrngGenerate.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_HSM_Hsm_Port_TrngGenerate.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_HSM_Hsm_Port_TrngGenerate[clientId].Rte_ClientQueue;

        /* call runnable */
        HsmTrngGenerate(&ClientQueue->Trng, &ClientQueue->len);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_HSM_Hsm_Port_TrngGenerate[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_HSM_HsmSetAes128Key) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_HSM_HsmKeyM_SetAes128Key.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_HSM_HsmKeyM_SetAes128Key, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_HSM_HsmKeyM_SetAes128Key.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_HSM_HsmKeyM_SetAes128Key[clientId].Rte_ClientQueue;

        /* call runnable */
        HsmSetAes128Key((P2CONST(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT))&Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.IV, (P2CONST(A_16Bytes, AUTOMATIC, RTE_VAR_NOINIT))&Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.KEY, Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.key_len);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_HSM_HsmKeyM_SetAes128Key[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_HSM_HsmGetAes128Key) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_HSM_HsmKeyM_GetAes128Key.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_HSM_HsmKeyM_GetAes128Key, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_HSM_HsmKeyM_GetAes128Key.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_HSM_HsmKeyM_GetAes128Key.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_HSM_HsmKeyM_GetAes128Key[clientId].Rte_ClientQueue;

        /* call runnable */
        HsmGetAes128Key(&ClientQueue->IV, &ClientQueue->KEY, &ClientQueue->key_len);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_HSM_HsmKeyM_GetAes128Key[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     IPC
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(IPC) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_IPC_IPC_DataSend_If_Operation | Rte_Ev_Run_IPC_IPC_MainFunction | Rte_Ev_Run_IPC_IPC_STB_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(IPC, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_IPC_IPC_DataSend_If_Operation | Rte_Ev_Run_IPC_IPC_MainFunction | Rte_Ev_Run_IPC_IPC_STB_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_IPC_IPC_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      IPC_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_IPC_IPC_DataSend_If_Operation) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_IPC_IPC_DataSend_If_Operation.Rte_Active > 0U)
      {
        P2VAR(Rte_CS_ClientQueueType_IPC_IPC_DataSend_If_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_IPC_IPC_DataSend_If_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_IPC_IPC_DataSend_If_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = IPC_DataSend_If_Operation(&ClientQueue->p_msg, Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.len, Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.priority);

        ClientQueue->Rte_CallCompleted = TRUE;
      }
    }

    if ((ev & Rte_Ev_Run_IPC_IPC_STB_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      IPC_STB_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SWC_LOW
 * Priority: 3
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(SWC_LOW) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  EOL_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  DidDataProcess_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SocDtcProcess_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_SWC_LOW_0_10ms | Rte_Ev_Run_DidDataProcess_E2ESwitchStatusRead | Rte_Ev_Run_DidDataProcess_E2ESwitchStatusWrite | Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusRead | Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusWrite | Rte_Ev_Run_EOL_EOL_MainFunction | Rte_Ev_Run_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(SWC_LOW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_SWC_LOW_0_10ms | Rte_Ev_Run_DidDataProcess_E2ESwitchStatusRead | Rte_Ev_Run_DidDataProcess_E2ESwitchStatusWrite | Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusRead | Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusWrite | Rte_Ev_Run_EOL_EOL_MainFunction | Rte_Ev_Run_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_EOL_EOL_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      EOL_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SWC_LOW_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      DidDataProcess_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      SocDtcProcess_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DidDataProcess_E2ESwitchStatusRead) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        E2ESwitchStatusRead(Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Length, &ClientQueue->Data, &ClientQueue->Status);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_DidDataProcess_E2ESwitchStatusWrite) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        E2ESwitchStatusWrite(Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Length, &ClientQueue->Data, &ClientQueue->Status);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusRead) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        SecOcSwitchStatusRead(Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Length, &ClientQueue->Data, &ClientQueue->Status);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusWrite) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        SecOcSwitchStatusWrite(Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Length, &ClientQueue->Data, &ClientQueue->Status);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo[clientId].Rte_ClientQueue;

        /* call runnable */
        PpCS_AppClearDTCInfo_AppClearDTCInfo(Rte_CS_ServerQueue_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.OpStatus, &ClientQueue->Result);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SYS
 * Priority: 7
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(SYS) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  Misc_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  power_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  DCM_Server_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Upgrade_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SOCManager_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  CConfig_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SecOc_Server_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  CanServer_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  KeyReturn_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_SYS_0_100ms | Rte_Ev_Cyclic_SYS_0_10ms | Rte_Ev_Cyclic_SYS_0_50ms | Rte_Ev_Cyclic_SYS_0_5ms | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ABS3_Counter | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ECM2_Counter | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter | Rte_Ev_Run_IoHwAb_IoHwAb_GetPin | Rte_Ev_Run_IoHwAb_IoHwAb_GetVoltage | Rte_Ev_Run_Misc_Misc_MainFunction_500ms | Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig | Rte_Ev_Run_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(SYS, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_SYS_0_100ms | Rte_Ev_Cyclic_SYS_0_10ms | Rte_Ev_Cyclic_SYS_0_50ms | Rte_Ev_Cyclic_SYS_0_5ms | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ABS3_Counter | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ECM2_Counter | Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter | Rte_Ev_Run_IoHwAb_IoHwAb_GetPin | Rte_Ev_Run_IoHwAb_IoHwAb_GetVoltage | Rte_Ev_Run_Misc_Misc_MainFunction_500ms | Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig | Rte_Ev_Run_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_SYS_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      IoHwAb_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Power_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_IoHwAb_IoHwAb_GetPin) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetPin, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin.Rte_ClientId;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetPin[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = IoHwAb_GetPin(Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin.Id, &ClientQueue->Pin);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetPin[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Upgrade_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      VConfig_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      SOCManager_ManFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_IoHwAb_IoHwAb_GetVoltage) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetVoltage, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_ClientId;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetVoltage[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = IoHwAb_GetVoltage(Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage.Id, &ClientQueue->Voltage);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetVoltage[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Run_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId;
        if (clientId >= 7U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindId, &ClientQueue->kindConfig);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Run_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_ClientId;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick[clientId].Rte_ClientQueue;

        /* call runnable */
        ClientQueue->Rte_Result = VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(&ClientQueue->updateTick);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */

        Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free = 1;
      }
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CanServer_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      CanServer_MainFunction_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      TM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      Misc_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      Misc_MainFunction_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      Misc_MainFunction_100ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Misc_Misc_MainFunction_500ms) != (EventMaskType)0)
    {
      /* call runnable */
      Misc_MainFunction_500ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter[clientId].Rte_ClientQueue;

        /* call runnable */
        CanFrameCounter_Can_ESP_FD2_Counter(&ClientQueue->counter);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ECM2_Counter) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ECM2_Counter, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ECM2_Counter[clientId].Rte_ClientQueue;

        /* call runnable */
        CanFrameCounter_Can_ECM2_Counter(&ClientQueue->counter);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ECM2_Counter[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ABS3_Counter) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ABS3_Counter, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ABS3_Counter[clientId].Rte_ClientQueue;

        /* call runnable */
        CanFrameCounter_Can_ABS3_Counter(&ClientQueue->counter);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ABS3_Counter[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Cyclic_SYS_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      KeyReturn_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     TT_GEAR
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(TT_GEAR) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  Common_Safety_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_Common_Safety_Common_Safety_10msMainFunction | Rte_Ev_Run_Common_Safety_Common_Safety_50msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(TT_GEAR, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_Common_Safety_Common_Safety_10msMainFunction | Rte_Ev_Run_Common_Safety_Common_Safety_50msMainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Common_Safety_Common_Safety_50msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_Safety_50msMainFunction */
      /* read implicit data */
      Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_TT_GEAR.Rte_RB.Rte_Common_Safety_Common_Safety_50msMainFunction.Rte_rpSR_SWCSafety_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      /* STOP PRE RUNNABLE Common_Safety_50msMainFunction */
      /* call runnable */
      Common_Safety_50msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Safety_Common_Safety_10msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_Safety_10msMainFunction */
      /* read implicit data */
      Rte_DisableOSInterrupts(KM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_TT_GEAR.Rte_RB.Rte_Common_Safety_Common_Safety_10msMainFunction.Rte_rpSR_SWCSafety_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(KM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      /* STOP PRE RUNNABLE Common_Safety_10msMainFunction */
      /* call runnable */
      Common_Safety_10msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0314:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to void is performed.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1339:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1340:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
