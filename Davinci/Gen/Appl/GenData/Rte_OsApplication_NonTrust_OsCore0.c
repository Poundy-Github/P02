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
 *             File:  Rte_OsApplication_NonTrust_OsCore0.c
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

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AWakeHold_DVRRemtCnSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AwakeHlod_Heartbeat_counter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_SocReadyFlag_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EnergyInfoIdDataType, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons = 4095U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme = 4U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR = 10U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo = 255U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR = 10U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons = 16383U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet = 15U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance = 4095U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint32, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance = 16777215U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_Fuel_Status_Fuel_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_Odo_RunCounter_RunCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_IndicateSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_RealSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_VehRunSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_TachoInfo_EngRunSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_TachoInfo_EngSpd = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_ChimeID_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DM_tstDrvModStatusRecord, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(MenuSetData_t, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_MenuSetData_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s_OdoRteGetParament_t, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element = {
  0U, 0U, {0U, 0U, 0U}, {0U, 0U, 0U}, 0, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s_SpeedoInfo_t, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TC_NE_ChargStsOutput, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s_TachoInfo_t, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WN_WarningStsOutput, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(NVM_IPC_CAN_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(IPC_Config_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(NVMBlockMaintain_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_1_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_2_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_3_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_4_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_5_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(NVMBlockTrip, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_Trip_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(NVMMenuData_A20, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_MENU_Data_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(NVMMenuData_A20, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Menu_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Never Received Flags for each external Rx Signal with handleNeverReceived != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags = {
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlagsInit() (Rte_MemClr(&Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags, sizeof(Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlagsType)))


/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags = {
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

#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags, sizeof(Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlagsType)))


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Rte_tsFUEL_TC_ODO, RTE_VAR_NOINIT) Rte_FUEL_TC_ODO; /* PRQA S 0759, 3408, 1514 */ /* MD_MSR_Union, MD_Rte_3408, MD_Rte_1514 */
#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Rte_tsGateWay, RTE_VAR_NOINIT) Rte_GateWay; /* PRQA S 0759, 3408, 1514 */ /* MD_MSR_Union, MD_Rte_3408, MD_Rte_1514 */
#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
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


#define Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b0)
#define Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b1)
#define Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b2)



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


FUNC(void, RTE_CODE) Rte_InitMemory_OsApplication_NonTrust_OsCore0(void)
{
  /* reset Rx Never Received Flags */
  Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* initialize flags for update handling */
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* set default values for internal data */
  Rte_Common_GateWay_AWakeHold_DVRRemtCnSts = 0U;
  Rte_Common_GateWay_AwakeHlod_Heartbeat_counter = 0U;
  Rte_Common_GateWay_SocReadyFlag_Element = 0U;
  Rte_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data = Rte_C_EnergyInfoIdDataType_0;
  Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue = 0U;
  Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2 = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons = 4095U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme = 4U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR = 10U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo = 255U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR = 10U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons = 16383U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet = 15U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance = 4095U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance = 16777215U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2 = 0U;
  Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0 = 0U;
  Rte_Common_Normal_Sd_Fuel_Status_Fuel_Status = 0U;
  Rte_Common_Normal_Sd_Odo_RunCounter_RunCounter = 0U;
  Rte_Common_Normal_Sd_SpeedoInfo_IndicateSpeed = 0U;
  Rte_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg = 0U;
  Rte_Common_Normal_Sd_SpeedoInfo_RealSpeed = 0U;
  Rte_Common_Normal_Sd_SpeedoInfo_VehRunSts = 0U;
  Rte_Common_Normal_Sd_TachoInfo_EngRunSts = 0U;
  Rte_Common_Normal_Sd_TachoInfo_EngSpd = 0U;
  Rte_Common_Normal_ppSR_SWCNormal_ChimeID_Element = 0U;
  Rte_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element = Rte_C_DM_tstDrvModStatusRecord_0;
  Rte_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element = Rte_C_FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE_0;
  Rte_Common_Normal_ppSR_SWCNormal_MenuSetData_Element = Rte_C_MenuSetData_t_0;
  Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element = 0U;
  Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element = 0U;
  Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element = Rte_SocRpOdoDataInit;
  Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element = Rte_C_s_SpeedoInfo_t_0;
  Rte_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element = Rte_C_TC_MODULE_OUTPUT_DATA_STRUCT_RTE_0;
  Rte_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element = Rte_C_TC_NE_ChargStsOutput_0;
  Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element = Rte_C_s_TachoInfo_t_0;
  Rte_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element = Rte_C_WN_WarningStsOutput_0;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT10_0x331_HUT10_0x331(P2CONST(HUT10_0x331, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT10_0x331_oHUT10_oB30_for_SC_CAN_V3_2_acd87eba_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT13_0x31C_HUT13_0x31C(P2CONST(HUT13_0x31C, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT13_0x31C_oHUT13_oB30_for_SC_CAN_V3_2_86243622_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT15_0x1EE_HUT15_0x1EE(P2CONST(HUT15_0x1EE, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT15_0x1EE_oHUT15_oB30_for_SC_CAN_V3_2_ccda2985_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT16_0x348_HUT16_0x348(P2CONST(HUT16_0x348, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT16_0x348_oHUT16_oB30_for_SC_CAN_V3_2_6a07ebf7_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT17_0x33B_HUT17_0x33B(P2CONST(HUT17_0x33B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT17_0x33B_oHUT17_oB30_for_SC_CAN_V3_2_49d9e9b4_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT19_0x415_HUT19_0x415(P2CONST(HUT19_0x415, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT19_0x415_oHUT19_oB30_for_SC_CAN_V3_2_0070b441_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT1_0x367_HUT1_0x367(P2CONST(HUT1_0x367, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT1_0x367_oHUT1_oB30_for_SC_CAN_V3_2_4cf1fae5_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT20_0x2DE_HUT20_0x2DE(P2CONST(HUT20_0x2DE, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT20_0x2DE_oHUT20_oB30_for_SC_CAN_V3_2_fd1a0297_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT21_0x2DD_HUT21_0x2DD(P2CONST(HUT21_0x2DD, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT21_0x2DD_oHUT21_oB30_for_SC_CAN_V3_2_46aba8bb_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT22_0x2DA_HUT22_0x2DA(P2CONST(HUT22_0x2DA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT22_0x2DA_oHUT22_oB30_for_SC_CAN_V3_2_c0698017_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT23_0x2D8_HUT23_0x2D8(P2CONST(HUT23_0x2D8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT23_0x2D8_oHUT23_oB30_for_SC_CAN_V3_2_f39d4000_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT25_0x339_HUT25_0x339(P2CONST(HUT25_0x339, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT25_0x339_oHUT25_oB30_for_SC_CAN_V3_2_1c8c4a71_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT2_0x369_HUT2_0x369(P2CONST(HUT2_0x369, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT2_0x369_oHUT2_oB30_for_SC_CAN_V3_2_101c4259_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT30_0x1E9_HUT30_0x1E9(P2CONST(HUT30_0x1E9, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT30_0x1E9_oHUT30_oB30_for_SC_CAN_V3_2_037aee47_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT32_0x26F_HUT32_0x26F(P2CONST(HUT32_0x26F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT32_0x26F_oHUT32_oB30_for_SC_CAN_V3_2_cd38c3b4_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT33_0x1ED_HUT33_0x1ED(P2CONST(HUT33_0x1ED, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT33_0x1ED_oHUT33_oB30_for_SC_CAN_V3_2_0dfdacd0_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT34_0x370_HUT34_0x370(P2CONST(HUT34_0x370, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT34_0x370_oHUT34_oB30_for_SC_CAN_V3_2_f661979e_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT35_0x1E5_HUT35_0x1E5(P2CONST(HUT35_0x1E5, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT35_0x1E5_oHUT35_oB30_for_SC_CAN_V3_2_f645fa9e_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT39_0x1EB_HUT39_0x1EB(P2CONST(HUT39_0x1EB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT39_0x1EB_oHUT39_oB30_for_SC_CAN_V3_2_85871b1d_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT3_0x36B_HUT3_0x36B(P2CONST(HUT3_0x36B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT3_0x36B_oHUT3_oB30_for_SC_CAN_V3_2_6c58ad50_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT4_0x36D_HUT4_0x36D(P2CONST(HUT4_0x36D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT4_0x36D_oHUT4_oB30_for_SC_CAN_V3_2_f3b22adc_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT6_0x4A_HUT6_0x4A(P2CONST(HUT6_0x4A, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT6_0x4A_oHUT6_oB30_for_SC_CAN_V3_2_d227f5be_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT_FD1_0x2C3_HUT_FD1_0x2C3(P2CONST(HUT_FD1_0x2C3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Call_Rte_TrustedCom_SendSignal(ComConf_ComSignal_HUT_FD1_0x2C3_oHUT_FD1_oB30_for_SC_CAN_V3_2_c297c003_Tx, *(data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data(P2CONST(EnergyInfoIdDataType, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_Sd_Cluster_Shutdown_Status_Element(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  (void)IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0(*(&data)); /* PRQA S 1339 */ /* MD_Rte_1339 */
  (void)IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0(*(&data)); /* PRQA S 1339 */ /* MD_Rte_1339 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_Sd_Fuel_Status_Fuel_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Common_Normal_Sd_Fuel_Status_Fuel_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Common_Normal_Sd_Fuel_Status_Fuel_Status = 1U; /* PRQA S 2982 */ /* MD_Rte_2982 */
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element(P2CONST(DM_tstDrvModStatusRecord, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(P2CONST(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSetData_Element(P2CONST(MenuSetData_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_MenuSetData_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_OdoParament_Element(P2CONST(s_OdoRteGetParament_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Common_Normal_ppSR_SWCNormal_OdoParament_Element = 1U; /* PRQA S 2982 */ /* MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element(P2CONST(s_SpeedoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element(P2CONST(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element(P2CONST(TC_NE_ChargStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TachoInfo_Element(P2CONST(s_TachoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element(P2CONST(WN_WarningStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS1_0x231_ABS1_0x231(P2VAR(ABS1_0x231, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS2_0x246_ABS2_0x246(P2VAR(ABS2_0x246, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC1_0x29D_AC1_0x29D(P2VAR(AC1_0x29D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC2_0x385_AC2_0x385(P2VAR(AC2_0x385, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB(P2VAR(ACC_FD2_0x2AB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4(P2VAR(ACC_FD3_0x2B4, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227(P2VAR(AEB_FD2_0x227, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3(P2VAR(AMP2_0x3E3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5(P2VAR(AMP3_0x3E5, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM12_0x238_BCM12_0x238(P2VAR(BCM12_0x238, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM1_0x319_BCM1_0x319(P2VAR(BCM1_0x319, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM3_0x345_BCM3_0x345(P2VAR(BCM3_0x345, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM8_0x29F_BCM8_0x29F(P2VAR(BCM8_0x29F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BMS4_0xF1_BMS4_0xF1(P2VAR(BMS4_0xF1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA1_0x165_CSA1_0x165(P2VAR(CSA1_0x165, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA2_0xA1_CSA2_0xA1(P2VAR(CSA2_0xA1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA3_0x244_CSA3_0x244(P2VAR(CSA3_0x244, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes, sizeof(CconfigKind_400Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT3_0xA6_DCT3_0xA6(P2VAR(DCT3_0xA6, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT5_0x221_DCT5_0x221(P2VAR(DCT5_0x221, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA(P2VAR(DDCM1_0x2CA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1(P2VAR(DSM1_0x2C1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3(P2VAR(ECM11_0x2D3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM1_0x111_ECM1_0x111(P2VAR(ECM1_0x111, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM2_0x271_ECM2_0x271(P2VAR(ECM2_0x271, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM3_0x371_ECM3_0x371(P2VAR(ECM3_0x371, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8(P2VAR(EEM1_0x2A8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_PartNumber_0xF187_PartNumber_0xF187(P2VAR(EOL13Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(*(data), Rte_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187, sizeof(EOL13Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2VAR(EOL_15Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(*(data), Rte_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193, sizeof(EOL_15Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2VAR(A_20Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(*(data), Rte_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C, sizeof(A_20Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2VAR(EOL4Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(*(data), Rte_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01, sizeof(EOL4Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPB1_0x16B_EPB1_0x16B(P2VAR(EPB1_0x16B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147(P2VAR(EPS_FD1_0x147, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP11_0xC8_ESP11_0xC8(P2VAR(ESP11_0xC8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP8_0x170_ESP8_0x170(P2VAR(ESP8_0x170, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137(P2VAR(ESP_FD2_0x137, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB(P2VAR(GW_FD1_0x2BB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B(P2VAR(HAP_FD1_0x15B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274(P2VAR(HAP_FD2_0x274, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298(P2VAR(HAP_FD3_0x298, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2(P2VAR(HCU_HC7_0x3C2, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA(P2VAR(HCU_PT4_0x2FA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248(P2VAR(HCU_PT7_0x248, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HUD1_0x325_HUD1_0x325(P2VAR(HUD1_0x325, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D(P2VAR(IFC_FD2_0x23D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF(P2VAR(IFC_FD3_0x2CF, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD(P2VAR(PDCM1_0x2CD, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS2_0x295_PEPS2_0x295(P2VAR(PEPS2_0x295, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS4_0x302_PEPS4_0x302(P2VAR(PEPS4_0x302, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F(P2VAR(RSDS_FD1_0x16F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A(P2VAR(RSDS_FD2_0x30A, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS1_0x341_TPMS1_0x341(P2VAR(TPMS1_0x341, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS2_0x395_TPMS2_0x395(P2VAR(TPMS2_0x395, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395 = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA(P2VAR(WPC1_0x2BA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  {
    ret = Com_ReceiveSignal(ComConf_ComSignal_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx, *(data)); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  }
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA = Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA_Sender;
  ResumeOSInterrupts();
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx == 0U)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_MSR_RetVal */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_rpSR_SWCGateWay_MenuSetData_Element(P2VAR(MenuSetData_t, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_MenuSetData_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_AVASDTCResults_AVASDTC(P2VAR(AVASDTCRet, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_AMP_AVASDTCResults_AVASDTC; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes, sizeof(CconfigKind_400Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Rc_Cluster_Shutdown_Status_Element(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  (void)IocRead_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element(data);
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Rc_Fuel_Status_Fuel_Status(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Common_Normal_Sd_Fuel_Status_Fuel_Status; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status = Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status_Sender;
  ResumeOSInterrupts();
  if (Rte_OsApplication_NonTrust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Common_Normal_Sd_Fuel_Status_Fuel_Status == 0U)
  {
    ret = RTE_E_NEVER_RECEIVED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_Vconfig_Vconfig_GetKindBuffers_AllKinds, sizeof(VconfigKind_Allbuffers)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_DrvModStatusRecord_Element(P2VAR(DM_tstDrvModStatusRecord, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_EnergyInfoId_Data(P2VAR(EnergyInfoIdDataType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(P2VAR(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSetData_Element(P2VAR(MenuSetData_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_MenuSetData_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_OdoParament_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TC_Module_Output_Data_Element(P2VAR(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element(P2VAR(TC_NE_ChargStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Common_Normal_ppSR_SWCNormal_TachoInfo_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_WarningStsOutput_Element(P2VAR(WN_WarningStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime(P2VAR(sint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_RTC_Sd_RTC_SleepDateTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_RTC_Sd_RTC_UtcTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_VIN_Element(P2VAR(A_17Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(*(data), Rte_DidDataProcess_tiSR_VIN_Element, sizeof(A_17Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rcCS_SWCNormal_ReceiveOffroadInfo_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  svCS_SWCNormal_ReceiveOffroadInfo_Callback(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_AdasStatus_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  svCS_SWCNormal_ReceiveAdasStatus_Callback(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  svCS_SWCNormal_ReceiveHMIPowerMode_Callback(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveMenuTheme_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ppCS_SWCNormal_ReceiveMenuTheme_Callback(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_TtToChime_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ppCS_TtToChime(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_CNA_SignalGroupSet_Operation(P2CONST(EventSignalInfo_Type, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) event_signal_info) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation(event_signal_info);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation(const EventSignalInfo_Type *event_signal_info) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalGroupSet_Operation.Rte_Active = 1;
  ResumeOSInterrupts();
  Rte_CS_ServerQueue_Can_Server_CNA_SignalGroupSet_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_CNA_SignalGroupSet_Operation;

  Rte_CS_ServerQueue_Can_Server_CNA_SignalGroupSet_Operation.event_signal_info = *event_signal_info;

  {

    /* scheduled trigger for runnables: CNA_SignalGroupSet */
    (void)SetEvent(BSW_COMM, Rte_Ev_Run_Can_Server_CNA_SignalGroupSet); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_CNA_SignalSet_Operation(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation(signalId, value);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation(uint16 signalId, uint32 *value) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Active = 1;
    Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_CNA_SignalSet_Operation;

    Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation.signalId = signalId;
    Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.value = *value;
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
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *value = Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.value;

      ret = Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_IPC_DataSend_If_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) p_msg, uint16 len, uint8 priority) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation(p_msg, len, priority);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation(uint8 *p_msg, uint16 len, uint8 priority) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_IPC_IPC_DataSend_If_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_IPC_DataSend_If_Operation;

  Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation.p_msg = *p_msg;
  Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.len = len;
  Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation.priority = priority;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: IPC_DataSend_If_Operation */
    (void)SetEvent(IPC, Rte_Ev_Run_IPC_IPC_DataSend_If_Operation); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      *p_msg = Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation.p_msg;

      ret = Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(kindId, kindConfig);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

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
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo(OpStatus, Result);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, uint8 *Result) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_Active = 1;
  Rte_CS_ServerQueue_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo;

  Rte_CS_ServerQueue_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.OpStatus = OpStatus;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: PpCS_AppClearDTCInfo_AppClearDTCInfo */
    (void)SetEvent(SWC_LOW, Rte_Ev_Run_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Result = Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo.Result;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(signalId, value);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(uint16 signalId, uint8 *value) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation;

  Rte_CS_ServerQueue_Can_Server_CNA_SignalSetNoTrigger_Operation.signalId = signalId;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.value = *value;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: CNA_SignalSetNoTrigger */
    (void)SetEvent(BSW_COMM, Rte_Ev_Run_Can_Server_CNA_SignalSetNoTrigger); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *value = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.value;

      ret = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, P2VAR(EventSignalType, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(signalId, value);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, EventSignalType *value) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_U8N_Operation.Rte_Active = 1;
  ResumeOSInterrupts();
  Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_U8N_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation;

  Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_U8N_Operation.signalId = signalId;
  Rte_MemCpy32(Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.value, *value, sizeof(EventSignalType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  {

    /* scheduled trigger for runnables: CNA_SignalSet_U8N */
    (void)SetEvent(BSW_COMM, Rte_Ev_Run_Can_Server_CNA_SignalSet_U8N); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      Rte_MemCpy32(*value, Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.value, sizeof(EventSignalType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

      ret = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(GroupId, E2eStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus;

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
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal(SignalId, SignalDataPtr, Length);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal;

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
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(Length, Data, Status);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation;

  Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Length = Length;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Data = *Data;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: E2ESwitchStatusRead */
    (void)SetEvent(SWC_LOW, Rte_Ev_Run_DidDataProcess_E2ESwitchStatusRead); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Data = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Data;
      *Status = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Status;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(Length, Data, Status);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation;

  Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Length = Length;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Data = *Data;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: E2ESwitchStatusWrite */
    (void)SetEvent(SWC_LOW, Rte_Ev_Run_DidDataProcess_E2ESwitchStatusWrite); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Data = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Data;
      *Status = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Status;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(Length, Data, Status);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation;

  Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Length = Length;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Data = *Data;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: SecOcSwitchStatusRead */
    (void)SetEvent(SWC_LOW, Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusRead); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Data = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Data;
      *Status = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Status;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(Length, Data, Status);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_Active = 1;
  Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation;

  Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Length = Length;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Data = *Data;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: SecOcSwitchStatusWrite */
    (void)SetEvent(SWC_LOW, Rte_Ev_Run_DidDataProcess_SecOcSwitchStatusWrite); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Data = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Data;
      *Status = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Status;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) date) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(utc, date);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 1;
    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar;

    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.utc = utc;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RTC_UTC2PerpetualCalendar */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_UTC2PerpetualCalendar); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_GateWay)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *date = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar.date;

      ret = Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)23);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)23, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)23);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)23, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)23, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)23, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)13);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)13, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)13);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)13, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)13, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)13, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)15);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)15, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)15);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)15, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)15, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)15, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)17);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)17, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)17);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)17, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)17, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)17, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)19);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)19, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)19);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)19, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)19, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)19, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)21);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)21, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)21);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)21, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)21, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)21, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_EraseNvBlock((NvM_BlockIdType)25);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)25, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_InvalidateNvBlock((NvM_BlockIdType)25);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_ReadBlock((NvM_BlockIdType)25, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults(dtRef_VOID DstPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_RestoreBlockDefaults((NvM_BlockIdType)25, DstPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)25, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ABS3_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter(counter);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter(CanFrameCounterType *counter) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_Active = 1;
  Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ABS3_Counter;

  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: CanFrameCounter_Can_ABS3_Counter */
    (void)SetEvent(SYS, Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ABS3_Counter); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *counter = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter.counter;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ECM2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter(counter);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter(CanFrameCounterType *counter) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_Active = 1;
  Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ECM2_Counter;

  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: CanFrameCounter_Can_ECM2_Counter */
    (void)SetEvent(SYS, Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ECM2_Counter); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *counter = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter.counter;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter(counter);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter(CanFrameCounterType *counter) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_Active = 1;
  Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter;

  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: CanFrameCounter_Can_ESP_FD2_Counter */
    (void)SetEvent(SYS, Rte_Ev_Run_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *counter = Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter.counter;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(EventStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 1;
  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus;

  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.EventStatus = EventStatus;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: Dem_SetEventStatus */
    (void)SetEvent(BSW_DIAGNOSE, Rte_Ev_Run_DemSatellite_0_SetEventStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(EventStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 1;
  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus;

  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.EventStatus = EventStatus;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: Dem_SetEventStatus */
    (void)SetEvent(BSW_DIAGNOSE, Rte_Ev_Run_DemSatellite_0_SetEventStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(EventStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 1;
  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus;

  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.EventStatus = EventStatus;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: Dem_SetEventStatus */
    (void)SetEvent(BSW_DIAGNOSE, Rte_Ev_Run_DemSatellite_0_SetEventStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(EventStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 1;
  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus;

  Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.EventStatus = EventStatus;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: Dem_SetEventStatus */
    (void)SetEvent(BSW_DIAGNOSE, Rte_Ev_Run_DemSatellite_0_SetEventStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_GetAes128Key(P2VAR(A_17Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) IV, P2VAR(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) KEY, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) key_len) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key(IV, KEY, key_len);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key(A_17Bytes *IV, A_16Bytes *KEY, uint32 *key_len) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_HSM_HsmKeyM_GetAes128Key.Rte_Active = 1;
  Rte_CS_ServerQueue_HSM_HsmKeyM_GetAes128Key.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_HsmKeyM_GetAes128Key;

  Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.key_len = *key_len;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: HsmGetAes128Key */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_HSM_HsmGetAes128Key); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      Rte_MemCpy32(*IV, Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.IV, sizeof(A_17Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
      Rte_MemCpy32(*KEY, Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.KEY, sizeof(A_16Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
      *key_len = Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.key_len;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_SetAes128Key(P2CONST(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) IV, P2CONST(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) KEY, uint32 key_len) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key(IV, KEY, key_len);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key(const A_16Bytes *IV, const A_16Bytes *KEY, uint32 key_len) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_HsmKeyM_SetAes128Key.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_HSM_HsmKeyM_SetAes128Key.Rte_Active = 1;
  ResumeOSInterrupts();
  Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_HsmKeyM_SetAes128Key;

  Rte_MemCpy32(Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.IV, *IV, sizeof(A_16Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.KEY, *KEY, sizeof(A_16Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key.key_len = key_len;

  {

    /* scheduled trigger for runnables: HsmSetAes128Key */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_HSM_HsmSetAes128Key); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_HsmKeyM_SetAes128Key.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Hsm_Port_TrngGenerate(P2VAR(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Trng, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) len) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate(Trng, len);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate(A_16Bytes *Trng, uint32 *len) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_HSM_Hsm_Port_TrngGenerate.Rte_Active = 1;
  Rte_CS_ServerQueue_HSM_Hsm_Port_TrngGenerate.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_Hsm_Port_TrngGenerate;

  Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.len = *len;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: HsmTrngGenerate */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_HSM_HsmTrngGenerate); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      Rte_MemCpy32(*Trng, Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.Trng, sizeof(A_16Bytes)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
      *len = Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.len;
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IRTC_Service_GetUTCTimeInMillis(P2VAR(uint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis(arg);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis(uint64 *arg) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_Active = 1;
  Rte_CS_ServerQueue_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_IRTC_Service_GetUTCTimeInMillis;

  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: RTC_GetUTCTimeInMillis */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_GetUTCTimeInMillis); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *arg = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis.arg;

      ret = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) date) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(utc, date);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 1;
    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_IRTC_Service_UTC2PerpetualCalendar;

    Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar.utc = utc;
  }
  else
  {
    ret = RTE_E_TIMEOUT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RTC_UTC2PerpetualCalendar */
    (void)SetEvent(DRIVERS_SAFE, Rte_Ev_Run_RTC_UTC2PerpetualCalendar); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *date = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar.date;

      ret = Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IoHwAb_Interface_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Pin) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin(Id, Pin);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Active = 1;
    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_IoHwAb_Interface_GetPin;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Pin = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin.Pin;

      ret = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IoHwAb_Interface_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Voltage) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage(Id, Voltage);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Active = 1;
    Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_IoHwAb_Interface_GetVoltage;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Voltage = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage.Voltage;

      ret = Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(SrcPtr);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_Active = 1;
  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock;

  Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.SrcPtr = SrcPtr;
  ResumeOSInterrupts();

  {

    /* scheduled trigger for runnables: NvM_WriteBlock */
    (void)SetEvent(Default_BSW, Rte_Ev_Run_NvM_WriteBlock); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do
      {
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Value) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue(Value);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_Os_Service_GetCounterValue;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue.Value;

      ret = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ElapsedValue) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue(Value, ElapsedValue);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 1;
    Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_Os_Service_GetElapsedValue;

    Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Value = *Value;
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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *Value = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Value;
      *ElapsedValue = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.ElapsedValue;

      ret = Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) kindConfig) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(kindId, kindConfig);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *kindConfig = Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.kindConfig;

      ret = Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) updateTick) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(updateTick);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Active = 1;
    Rte_CS_ServerQueue_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *updateTick = Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.updateTick;

      ret = Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) E2eStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus(GroupId, E2eStatus);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {
      *E2eStatus = Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus.E2eStatus;

      ret = Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  return Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal(SignalId, SignalDataPtr, Length);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 1505, 3673, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_Qac, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  if (Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free > 0U)
  {
    Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 0;
    Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 1;
    Rte_CS_ServerQueue_ComEx_ComEx_SendSignal.Rte_ClientId = Rte_CS_ClientConfigIndex_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal;

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
        (void)WaitEvent(Rte_Ev_WP_FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_FUEL_TC_ODO)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal.Rte_Result; /* PRQA S 2983 */ /* MD_MSR_RetVal */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     FUEL_TC_ODO
 * Priority: 5
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(FUEL_TC_ODO) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  Common_Normal_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_A | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_B | Rte_Ev_Run_Common_Normal_Common_Normal_5msMainFunction | Rte_Ev_Run_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster | Rte_Ev_Run_Common_Normal_Fuel_Api_ParamentGetCsPort_Operation); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(FUEL_TC_ODO, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_ | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_A | Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_B | Rte_Ev_Run_Common_Normal_Common_Normal_5msMainFunction | Rte_Ev_Run_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster | Rte_Ev_Run_Common_Normal_Fuel_Api_ParamentGetCsPort_Operation)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_5msMainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_5msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_Normal_10msMainFunction */
      /* read implicit data */
      Rte_DisableOSInterrupts(UM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_10msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(UM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_10msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_OK;
      if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Power_ppSR_Power_Out_SystemStateOut == 0U)
      {
         Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_10msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_NEVER_RECEIVED;
      }
      /* STOP PRE RUNNABLE Common_Normal_10msMainFunction */
      /* call runnable */
      Common_Normal_10msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_Normal_20msMainFunction */
      /* read implicit data */
      Rte_DisableOSInterrupts(UM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_20msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(UM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_20msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_OK;
      if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Power_ppSR_Power_Out_SystemStateOut == 0U)
      {
         Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_20msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_NEVER_RECEIVED;
      }
      /* STOP PRE RUNNABLE Common_Normal_20msMainFunction */
      /* call runnable */
      Common_Normal_20msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_A) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_20msMainFunction_A(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_Normal_100msMainFunction */
      /* read implicit data */
      Rte_DisableOSInterrupts(UM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_100msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(UM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_100msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_OK;
      if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Power_ppSR_Power_Out_SystemStateOut == 0U)
      {
         Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_100msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status = RTE_E_NEVER_RECEIVED;
      }
      /* STOP PRE RUNNABLE Common_Normal_100msMainFunction */
      /* call runnable */
      Common_Normal_100msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_10msMainFunction_) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_10msMainFunction_(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_20msMainFunction_(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_20msMainFunction_B) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_20msMainFunction_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Common_Normal_100msMainFunction_) != (EventMaskType)0)
    {
      /* call runnable */
      Common_Normal_100msMainFunction_(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster[clientId].Rte_ClientQueue;

        /* call runnable */
        EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(&ClientQueue->arg);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_Common_Normal_Fuel_Api_ParamentGetCsPort_Operation) != (EventMaskType)0)
    {
      while (Rte_CS_ServerQueueInfo_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_Active > 0U)
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation, TYPEDEF, RTE_VAR_NOINIT) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_ClientId;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation[clientId].Rte_ClientQueue;

        /* call runnable */
        Fuel_Api_ParamentGetCsPort_Operation(&ClientQueue->arg);

        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     GateWay
 * Priority: 5
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(GateWay) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;


  /* call runnable */
  Common_GateWay_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_Common_GateWay_Common_GateWay_10msMainFunction | Rte_Ev_Run_Common_GateWay_Common_GateWay_5msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(GateWay, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_Common_GateWay_Common_GateWay_10msMainFunction | Rte_Ev_Run_Common_GateWay_Common_GateWay_5msMainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Common_GateWay_Common_GateWay_5msMainFunction) != (EventMaskType)0)
    {
      /* START PRE RUNNABLE Common_GateWay_5msMainFunction */
      /* read implicit data */
      *(&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Fuel_Set_Module_Data_Element.value) = Rte_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      *(&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_TC_Module_Output_Data_Element.value) = Rte_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_DisableOSInterrupts(UM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Power_Out_SystemStateOut.value) = Rte_Power_ppSR_Power_Out_SystemStateOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(UM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Power_Out_SystemStateOut.status = RTE_E_OK;
      if (Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_Power_ppSR_Power_Out_SystemStateOut == 0U)
      {
         Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Power_Out_SystemStateOut.status = RTE_E_NEVER_RECEIVED;
      }
      Rte_DisableOSInterrupts(UM); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      *(&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_ReceiveRTCTime_SleepDateTime.value) = Rte_RTC_Sd_RTC_SleepDateTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      *(&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime.value) = Rte_RTC_Sd_RTC_UtcTime; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      Rte_EnableOSInterrupts(UM); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      /* STOP PRE RUNNABLE Common_GateWay_5msMainFunction */
      /* call runnable */
      Common_GateWay_5msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Common_GateWay_Common_GateWay_10msMainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      Common_GateWay_10msMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
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
