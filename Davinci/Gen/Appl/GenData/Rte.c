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
 *             File:  Rte.c
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

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ABM1_0x351, RTE_CONST) Rte_C_ABM1_0x351_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ABS1_0x231, RTE_CONST) Rte_C_ABS1_0x231_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ABS2_0x246, RTE_CONST) Rte_C_ABS2_0x246_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ABS3_0x265, RTE_CONST) Rte_C_ABS3_0x265_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AC1_0x29D, RTE_CONST) Rte_C_AC1_0x29D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AC2_0x385, RTE_CONST) Rte_C_AC2_0x385_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ACC_FD2_0x2AB, RTE_CONST) Rte_C_ACC_FD2_0x2AB_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ACC_FD3_0x2B4, RTE_CONST) Rte_C_ACC_FD3_0x2B4_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ACC_FD4_0x2B8, RTE_CONST) Rte_C_ACC_FD4_0x2B8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AEB_FD2_0x227, RTE_CONST) Rte_C_AEB_FD2_0x227_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AMP2_0x3E3, RTE_CONST) Rte_C_AMP2_0x3E3_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AMP3_0x3E5, RTE_CONST) Rte_C_AMP3_0x3E5_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(A_17Bytes, RTE_CONST) Rte_C_A_17Bytes_1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(A_20Bytes, RTE_CONST) Rte_C_A_20Bytes_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(A_U8_10, RTE_CONST) Rte_C_A_U8_10_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BCM12_0x238, RTE_CONST) Rte_C_BCM12_0x238_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BCM1_0x319, RTE_CONST) Rte_C_BCM1_0x319_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BCM3_0x345, RTE_CONST) Rte_C_BCM3_0x345_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BCM6_0x28C, RTE_CONST) Rte_C_BCM6_0x28C_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BCM8_0x29F, RTE_CONST) Rte_C_BCM8_0x29F_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS19_0x352, RTE_CONST) Rte_C_BMS19_0x352_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS22_0x3BF, RTE_CONST) Rte_C_BMS22_0x3BF_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS30_0x3F1, RTE_CONST) Rte_C_BMS30_0x3F1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS35_0x2C4, RTE_CONST) Rte_C_BMS35_0x2C4_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS4_0xF1, RTE_CONST) Rte_C_BMS4_0xF1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS8_0x285, RTE_CONST) Rte_C_BMS8_0x285_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(BMS_FD14_0x1E3, RTE_CONST) Rte_C_BMS_FD14_0x1E3_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CP1_0x35E, RTE_CONST) Rte_C_CP1_0x35E_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CR_FD1_0x15E, RTE_CONST) Rte_C_CR_FD1_0x15E_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CSA1_0x165, RTE_CONST) Rte_C_CSA1_0x165_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CSA2_0xA1, RTE_CONST) Rte_C_CSA2_0xA1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CSA3_0x244, RTE_CONST) Rte_C_CSA3_0x244_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CconfigKind_400Bytes, RTE_CONST) Rte_C_CconfigKind_400Bytes_0 = {
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
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DCT3_0xA6, RTE_CONST) Rte_C_DCT3_0xA6_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DCT5_0x221, RTE_CONST) Rte_C_DCT5_0x221_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DCT7_0x235, RTE_CONST) Rte_C_DCT7_0x235_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DDCM1_0x2CA, RTE_CONST) Rte_C_DDCM1_0x2CA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DHT_FD1_0xC1, RTE_CONST) Rte_C_DHT_FD1_0xC1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DMS_FD1_0x24D, RTE_CONST) Rte_C_DMS_FD1_0x24D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DSM1_0x2C1, RTE_CONST) Rte_C_DSM1_0x2C1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data200ByteType, RTE_CONST) Rte_C_Dcm_Data200ByteType_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data300ByteType, RTE_CONST) Rte_C_Dcm_Data300ByteType_0 = {
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
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM11_0x2D3, RTE_CONST) Rte_C_ECM11_0x2D3_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM1_0x111, RTE_CONST) Rte_C_ECM1_0x111_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM2_0x271, RTE_CONST) Rte_C_ECM2_0x271_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM3_0x371, RTE_CONST) Rte_C_ECM3_0x371_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM_PT7_0x117, RTE_CONST) Rte_C_ECM_PT7_0x117_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ECM_VIN, RTE_CONST) Rte_C_ECM_VIN_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EEM1_0x2A8, RTE_CONST) Rte_C_EEM1_0x2A8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ELD1_0x152, RTE_CONST) Rte_C_ELD1_0x152_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL13Bytes, RTE_CONST) Rte_C_EOL13Bytes_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL3Bytes, RTE_CONST) Rte_C_EOL3Bytes_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL4Bytes, RTE_CONST) Rte_C_EOL4Bytes_0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL9Bytes, RTE_CONST) Rte_C_EOL9Bytes_0 = {
  17U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_13Bytes, RTE_CONST) Rte_C_EOL_13Bytes_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_15Bytes, RTE_CONST) Rte_C_EOL_15Bytes_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EPB1_0x16B, RTE_CONST) Rte_C_EPB1_0x16B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EPS1_0x168, RTE_CONST) Rte_C_EPS1_0x168_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EPS_FD1_0x147, RTE_CONST) Rte_C_EPS_FD1_0x147_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESCL2_0x303, RTE_CONST) Rte_C_ESCL2_0x303_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP10_0xD8, RTE_CONST) Rte_C_ESP10_0xD8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP11_0xC8, RTE_CONST) Rte_C_ESP11_0xC8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP1_0x149, RTE_CONST) Rte_C_ESP1_0x149_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP2_0x145, RTE_CONST) Rte_C_ESP2_0x145_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP8_0x170, RTE_CONST) Rte_C_ESP8_0x170_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ESP_FD2_0x137, RTE_CONST) Rte_C_ESP_FD2_0x137_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FPAS1_0x26D, RTE_CONST) Rte_C_FPAS1_0x26D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(F_PBox1_0x19B, RTE_CONST) Rte_C_F_PBox1_0x19B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(GW_FD1_0x2BB, RTE_CONST) Rte_C_GW_FD1_0x2BB_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HAP_FD1_0x15B, RTE_CONST) Rte_C_HAP_FD1_0x15B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HAP_FD2_0x274, RTE_CONST) Rte_C_HAP_FD2_0x274_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HAP_FD3_0x298, RTE_CONST) Rte_C_HAP_FD3_0x298_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HAP_FD6_0x289, RTE_CONST) Rte_C_HAP_FD6_0x289_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HAP_FD7_0x29B, RTE_CONST) Rte_C_HAP_FD7_0x29B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HC1_0x287, RTE_CONST) Rte_C_HC1_0x287_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCM_L1_0x308, RTE_CONST) Rte_C_HCM_L1_0x308_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCM_R1_0x30D, RTE_CONST) Rte_C_HCM_R1_0x30D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_FD1_0x60, RTE_CONST) Rte_C_HCU_FD1_0x60_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HC3_0x268, RTE_CONST) Rte_C_HCU_HC3_0x268_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HC6_0x314, RTE_CONST) Rte_C_HCU_HC6_0x314_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HC7_0x3C2, RTE_CONST) Rte_C_HCU_HC7_0x3C2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HC8_0x1E2, RTE_CONST) Rte_C_HCU_HC8_0x1E2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HP5_0x201, RTE_CONST) Rte_C_HCU_HP5_0x201_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_HP6_0x11A, RTE_CONST) Rte_C_HCU_HP6_0x11A_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_PT4_0x2FA, RTE_CONST) Rte_C_HCU_PT4_0x2FA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_PT5_0x14A, RTE_CONST) Rte_C_HCU_PT5_0x14A_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_PT7_0x248, RTE_CONST) Rte_C_HCU_PT7_0x248_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HCU_PT8_0x1C0, RTE_CONST) Rte_C_HCU_PT8_0x1C0_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUD1_0x325, RTE_CONST) Rte_C_HUD1_0x325_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT10_0x331, RTE_CONST) Rte_C_HUT10_0x331_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT13_0x31C, RTE_CONST) Rte_C_HUT13_0x31C_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT15_0x1EE, RTE_CONST) Rte_C_HUT15_0x1EE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT16_0x348, RTE_CONST) Rte_C_HUT16_0x348_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT17_0x33B, RTE_CONST) Rte_C_HUT17_0x33B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT19_0x415, RTE_CONST) Rte_C_HUT19_0x415_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT1_0x367, RTE_CONST) Rte_C_HUT1_0x367_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT20_0x2DE, RTE_CONST) Rte_C_HUT20_0x2DE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT21_0x2DD, RTE_CONST) Rte_C_HUT21_0x2DD_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT22_0x2DA, RTE_CONST) Rte_C_HUT22_0x2DA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT23_0x2D8, RTE_CONST) Rte_C_HUT23_0x2D8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT25_0x339, RTE_CONST) Rte_C_HUT25_0x339_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT26_0x2B6, RTE_CONST) Rte_C_HUT26_0x2B6_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT2_0x369, RTE_CONST) Rte_C_HUT2_0x369_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT30_0x1E9, RTE_CONST) Rte_C_HUT30_0x1E9_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT32_0x26F, RTE_CONST) Rte_C_HUT32_0x26F_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT33_0x1ED, RTE_CONST) Rte_C_HUT33_0x1ED_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT34_0x370, RTE_CONST) Rte_C_HUT34_0x370_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT35_0x1E5, RTE_CONST) Rte_C_HUT35_0x1E5_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT39_0x1EB, RTE_CONST) Rte_C_HUT39_0x1EB_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT3_0x36B, RTE_CONST) Rte_C_HUT3_0x36B_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT40_0x2CE, RTE_CONST) Rte_C_HUT40_0x2CE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT4_0x36D, RTE_CONST) Rte_C_HUT4_0x36D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT6_0x4A, RTE_CONST) Rte_C_HUT6_0x4A_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT_FD1_0x2C3, RTE_CONST) Rte_C_HUT_FD1_0x2C3_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT_FD4_0x1DA, RTE_CONST) Rte_C_HUT_FD4_0x1DA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT_IP1_0x293, RTE_CONST) Rte_C_HUT_IP1_0x293_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT_IP2_0x27F, RTE_CONST) Rte_C_HUT_IP2_0x27F_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(HUT_IP3_0x34A, RTE_CONST) Rte_C_HUT_IP3_0x34A_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Haldex1_0x251, RTE_CONST) Rte_C_Haldex1_0x251_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFC_FD2_0x23D, RTE_CONST) Rte_C_IFC_FD2_0x23D_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFC_FD3_0x2CF, RTE_CONST) Rte_C_IFC_FD3_0x2CF_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFC_FD5_0x19F, RTE_CONST) Rte_C_IFC_FD5_0x19F_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFC_FD6_0x222, RTE_CONST) Rte_C_IFC_FD6_0x222_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(OBC1_0x316, RTE_CONST) Rte_C_OBC1_0x316_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(OBC2_0x317, RTE_CONST) Rte_C_OBC2_0x317_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(PDCM1_0x2CD, RTE_CONST) Rte_C_PDCM1_0x2CD_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(PEPS2_0x295, RTE_CONST) Rte_C_PEPS2_0x295_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(PEPS4_0x302, RTE_CONST) Rte_C_PEPS4_0x302_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(PLG_1_0x2FE, RTE_CONST) Rte_C_PLG_1_0x2FE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RPAS1_0x26E, RTE_CONST) Rte_C_RPAS1_0x26E_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RPAS2_0x2ED, RTE_CONST) Rte_C_RPAS2_0x2ED_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RSDS_FD1_0x16F, RTE_CONST) Rte_C_RSDS_FD1_0x16F_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RSDS_FD2_0x30A, RTE_CONST) Rte_C_RSDS_FD2_0x30A_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(R_PBox1_0x19C, RTE_CONST) Rte_C_R_PBox1_0x19C_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SCM1_0x2D1, RTE_CONST) Rte_C_SCM1_0x2D1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SyncRequstReseverData1, RTE_CONST) Rte_C_SyncRequstReseverData1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TMCU_FD3_0x3C9, RTE_CONST) Rte_C_TMCU_FD3_0x3C9_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TPMS1_0x341, RTE_CONST) Rte_C_TPMS1_0x341_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TPMS2_0x395, RTE_CONST) Rte_C_TPMS2_0x395_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(T_Box_FD1_0x33, RTE_CONST) Rte_C_T_Box_FD1_0x33_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(T_Box_FD3_0x3E9, RTE_CONST) Rte_C_T_Box_FD3_0x3E9_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Trailer1_0x273, RTE_CONST) Rte_C_Trailer1_0x273_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VSG1_0x2E1, RTE_CONST) Rte_C_VSG1_0x2E1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VconfigKind_Allbuffers, RTE_CONST) Rte_C_VconfigKind_Allbuffers_0 = {
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
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(WPC1_0x2BA, RTE_CONST) Rte_C_WPC1_0x2BA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AVASDTCRet, RTE_CONST) Rte_C_AVASDTCRet_0 = {
  2U, 2U, 2U, 2U, 2U, 2U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DM_tstDrvModStatusRecord, RTE_CONST) Rte_C_DM_tstDrvModStatusRecord_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(EnergyInfoIdDataType, RTE_CONST) Rte_C_EnergyInfoIdDataType_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, RTE_CONST) Rte_C_FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(MenuSetData_t, RTE_CONST) Rte_C_MenuSetData_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ABM1, RTE_CONST) Rte_C_SG_ABM1_0 = {
  FALSE, 0U, FALSE, 0U, FALSE, 0U, 0U, FALSE, 0U, FALSE, 0U, FALSE, 0U, 0U, FALSE, FALSE, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ABS3, RTE_CONST) Rte_C_SG_ABS3_0 = {
  FALSE, TRUE, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, 0U, 0U, TRUE, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ABS3_ESP_FD2, RTE_CONST) Rte_C_SG_ABS3_ESP_FD2_0 = {
  FALSE, TRUE, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, 0U, 0U, TRUE, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC3_ACC_FD2, RTE_CONST) Rte_C_SG_ACC3_ACC_FD2_0 = {
  0U, FALSE, 0U, FALSE, 0U, FALSE, FALSE, FALSE, 0U, FALSE, FALSE, 32767U, FALSE, FALSE, 0U, 0U, FALSE, 0U, FALSE, 
  FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC3_ACC_FD2, RTE_CONST) Rte_C_SG_ACC3_ACC_FD2_1 = {
  0U, FALSE, 0U, FALSE, 0U, FALSE, FALSE, FALSE, 0U, FALSE, FALSE, 0U, FALSE, FALSE, 0U, 0U, FALSE, 0U, FALSE, FALSE, 
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC4_ACC_FD2, RTE_CONST) Rte_C_SG_ACC4_ACC_FD2_0 = {
  0U, 0U, 0U, FALSE, 0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC6_ACC_FD2, RTE_CONST) Rte_C_SG_ACC6_ACC_FD2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC7_ACC_FD2, RTE_CONST) Rte_C_SG_ACC7_ACC_FD2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ACC8_ACC_FD2, RTE_CONST) Rte_C_SG_ACC8_ACC_FD2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_AEB2_AEB_FD2, RTE_CONST) Rte_C_SG_AEB2_AEB_FD2_0 = {
  TRUE, TRUE, TRUE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_AEB3_AEB_FD2, RTE_CONST) Rte_C_SG_AEB3_AEB_FD2_0 = {
  0U, 0U, 0U, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_BMS4, RTE_CONST) Rte_C_SG_BMS4_0 = {
  0U, 0U, 0U, 178U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_DCT7, RTE_CONST) Rte_C_SG_DCT7_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_DHT_FD1, RTE_CONST) Rte_C_SG_DHT_FD1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_EPB1, RTE_CONST) Rte_C_SG_EPB1_0 = {
  0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_EPS1, RTE_CONST) Rte_C_SG_EPS1_0 = {
  0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TRUE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_EPS1_FD1, RTE_CONST) Rte_C_SG_EPS1_FD1_0 = {
  0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ESP1, RTE_CONST) Rte_C_SG_ESP1_0 = {
  FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ESP1_ESP_FD2, RTE_CONST) Rte_C_SG_ESP1_ESP_FD2_0 = {
  FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ESP2, RTE_CONST) Rte_C_SG_ESP2_0 = {
  0U, 0U, FALSE, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  0U, FALSE, 0U, FALSE, FALSE, FALSE, 0U, FALSE, 0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_ESP2_ESP_FD2, RTE_CONST) Rte_C_SG_ESP2_ESP_FD2_0 = {
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, FALSE, 0U, 
  FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HC1, RTE_CONST) Rte_C_SG_HC1_0 = {
  0U, FALSE, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HCU_HP5, RTE_CONST) Rte_C_SG_HCU_HP5_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HCU_PT4, RTE_CONST) Rte_C_SG_HCU_PT4_0 = {
  FALSE, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, FALSE, 2U, 0U, FALSE, 0U, 0U, FALSE, FALSE, 0U, 0U, FALSE, FALSE, 
  FALSE, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HCU_PT7, RTE_CONST) Rte_C_SG_HCU_PT7_0 = {
  0U, 0U, 0U, FALSE, 0U, 0U, FALSE, 0U, FALSE, FALSE, FALSE, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 
  0U, FALSE, 0U, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HUT32, RTE_CONST) Rte_C_SG_HUT32_0 = {
  0U, 0U, FALSE, FALSE, 0U, FALSE, FALSE, 0U, FALSE, FALSE, 0U, FALSE, FALSE, 0U, 0U, 0U, 2047U, 2047U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_HUT_IP2, RTE_CONST) Rte_C_SG_HUT_IP2_0 = {
  0U, 0U, FALSE, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, FALSE, 0U, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_IFC3_IFC_FD2, RTE_CONST) Rte_C_SG_IFC3_IFC_FD2_0 = {
  FALSE, FALSE, 0U, 0U, FALSE, FALSE, FALSE, FALSE, 0U, FALSE, FALSE, FALSE, 0U, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_IFC4_IFC_FD2, RTE_CONST) Rte_C_SG_IFC4_IFC_FD2_0 = {
  FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_IFC5_IFC_FD2, RTE_CONST) Rte_C_SG_IFC5_IFC_FD2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_IFC6_IFC_FD2, RTE_CONST) Rte_C_SG_IFC6_IFC_FD2_0 = {
  0U, 0U, 0U, 0U, 0U, 2496U, 2496U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SecOC_VerificationStatusType, RTE_CONST) Rte_C_SecOC_VerificationStatusType_0 = {
  0U, 1U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SystemState_RecordType, RTE_CONST) Rte_C_SystemState_RecordType_0 = {
  0U, 0U, 0U, 0U, 0U, {0U, 0.0}, 0U, {0U, 0}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SystemState_RecordType, RTE_CONST) Rte_PowerOutInit = {
  0U, 0U, 0U, 0U, 0U, {0U, 0.0}, 0U, {255U, 0}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, RTE_CONST) Rte_C_TC_MODULE_OUTPUT_DATA_STRUCT_RTE_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TC_NE_ChargStsOutput, RTE_CONST) Rte_C_TC_NE_ChargStsOutput_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(WN_WarningStsOutput, RTE_CONST) Rte_C_WN_WarningStsOutput_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(s_OdoRteGetParament_t, RTE_CONST) Rte_C_s_OdoRteGetParament_t_0 = {
  0U, 0U, {0U, 0U, 0U}, {0U, 0U, 0U}, 0, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(s_OdoRteGetParament_t, RTE_CONST) Rte_SocRpOdoDataInit = {
  0U, 0U, {0U, 0U, 0U}, {0U, 0U, 0U}, 0, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(s_PowerOut_t, RTE_CONST) Rte_C_s_PowerOut_t_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(s_SpeedoInfo_t, RTE_CONST) Rte_C_s_SpeedoInfo_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(s_TachoInfo_t, RTE_CONST) Rte_C_s_TachoInfo_t_0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Upgrade_NvBlockNeed_UpgradeFlag_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Upgrade_NvBlockNeed_Upgrade_Flag_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Can_Server_NvBlockNeed_ActiveWUCounter_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SOCManager_NvBlockNeed_HealthSwitch_DefaultValue = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_u8_20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration2_DefaultValue = {
  64U, 64U, 64U, 64U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_u8_20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration_DefaultValue = {
  64U, 64U, 64U, 64U, 0U, 0U, 0U, 0U, 0U, 0U, 64U, 64U, 64U, 64U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_80Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVM_IPC_CAN_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(IPC_Config_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVMBlockMaintain_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_DefaultValue = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 0U, 136U, 19U, 0U, 0U, 136U, 19U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_1_DefaultValue = {
  6U, 0U, 255U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_2_DefaultValue = {
  6U, 0U, 255U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_3_DefaultValue = {
  6U, 0U, 255U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_4_DefaultValue = {
  6U, 0U, 255U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_5_DefaultValue = {
  6U, 0U, 255U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVMBlockTCConfig_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_TC_Config_Data_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVMBlockTC_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_TC_Data_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVMBlockTrip, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_Trip_DefaultValue = {
  128U, 0U, 0U, 0U, 128U, 0U, 0U, 0U, 128U, 0U, 0U, 0U, 128U, 0U, 0U, 0U, 128U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NVMMenuData_A20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_MENU_Data_DefaultValue = {
  3U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DCM_Server_NvBlockNeedSecAttemptCount_DefaultValue = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_DefaultValue = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_8Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_300Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_DefaultValue = {
  12U, 132U, 26U, 13U, 0U, 0U, 10U, 90U, 110U, 125U, 162U, 166U, 168U, 180U, 90U, 110U, 125U, 158U, 163U, 165U, 170U, 
  0U, 160U, 3U, 232U, 6U, 64U, 100U, 1U, 64U, 50U, 0U, 32U, 2U, 1U, 144U, 1U, 144U, 1U, 144U, 20U, 0U, 30U, 50U, 0U, 
  25U, 12U, 128U, 200U, 6U, 64U, 50U, 47U, 48U, 90U, 7U, 128U, 33U, 177U, 33U, 177U, 21U, 249U, 0U, 0U, 0U, 50U, 47U, 
  48U, 100U, 8U, 32U, 21U, 249U, 21U, 249U, 21U, 249U, 0U, 0U, 0U, 50U, 47U, 48U, 100U, 8U, 32U, 75U, 4U, 176U, 75U, 
  4U, 176U, 0U, 0U, 0U, 50U, 47U, 48U, 100U, 8U, 32U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 47U, 48U, 100U, 8U, 32U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 12U, 128U, 30U, 68U, 40U, 24U, 6U, 64U, 3U, 240U, 0U, 0U, 54U, 238U, 118U, 6U, 64U, 
  7U, 158U, 60U, 0U, 165U, 0U, 192U, 6U, 64U, 10U, 0U, 0U, 50U, 18U, 176U, 20U, 10U, 1U, 3U, 10U, 40U, 0U, 0U, 1U, 
  232U, 0U, 0U, 0U, 0U, 0U, 128U, 254U, 0U, 128U, 0U, 0U, 0U, 0U, 128U, 0U, 161U, 100U, 0U, 1U, 61U, 224U, 2U, 128U, 
  10U, 128U, 10U, 131U, 231U, 0U, 161U, 0U, 0U, 24U, 6U, 64U, 3U, 192U, 0U, 0U, 54U, 238U, 118U, 254U, 0U, 0U, 0U, 0U, 
  0U, 131U, 121U, 30U, 1U, 56U, 128U, 120U, 120U, 15U, 60U, 15U, 160U, 6U, 5U, 40U, 20U, 2U, 4U, 1U, 24U, 105U, 241U, 
  134U, 159U, 17U, 2U, 136U, 15U, 156U, 20U, 20U, 0U, 0U, 160U, 2U, 0U, 32U, 2U, 0U, 160U, 10U, 30U, 0U, 160U, 10U, 0U, 
  0U, 0U, 20U, 3U, 32U, 100U, 3U, 34U, 243U, 6U, 224U, 160U, 3U, 34U, 243U, 8U, 192U, 170U, 12U, 4U, 20U, 20U, 20U, 2U, 
  0U, 160U, 20U, 20U, 1U, 244U, 2U, 1U, 5U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_E2ESwitch_DefaultValue = {
  1U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_200Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue = {
  105U, 106U, 19U, 39U, 1U, 4U, 0U, 5U, 96U, 98U, 84U, 105U, 88U, 17U, 84U, 64U, 65U, 97U, 80U, 64U, 133U, 21U, 0U, 
  73U, 160U, 5U, 66U, 109U, 148U, 0U, 21U, 43U, 68U, 83U, 0U, 0U, 18U, 81U, 65U, 8U, 0U, 1U, 1U, 1U, 1U, 32U, 36U, 68U, 
  99U, 67U, 68U, 16U, 0U, 0U, 64U, 7U, 76U, 66U, 0U, 0U, 0U, 0U, 0U, 97U, 32U, 0U, 0U, 0U, 8U, 0U, 0U, 0U, 48U, 0U, 
  64U, 11U, 0U, 0U, 48U, 64U, 4U, 51U, 0U, 16U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_FactoryMode_DefaultValue = {
  1U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_8Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_MasterSlaveStatus_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_DefaultValue = {
  1U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_28Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_SwitchARLTable_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_17Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VIN_DefaultValue = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data20ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleMode_DefaultValue = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_30Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_DefaultValue = {
  86U, 49U, 46U, 48U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_13Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF187_DefaultValue = {
  70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF18C_DefaultValue = {
  70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF193_DefaultValue = {
  70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_17Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF195_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(RW_0xFD00, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFD00_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFD19_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFDD9_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE20_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE21_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE22_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE23_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE24_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE25_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_EOLUIN_DefaultValue = {
  70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(EOL4Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_EnterEOLSession_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_UIN_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(NvmResetInformation_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Misc_NvBlockNeed_ResetInfomation_DefaultValue;
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



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

/* Queue definitions for internal C/S connections */
#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CNA_SignalGroupSet_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CNA_SignalGroupSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CNA_SignalGroupSet_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalGroupSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalGroupSet_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CNA_SignalSet_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CNA_SignalSet_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSet_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSet_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CNA_SignalSetNoTrigger_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CNA_SignalSetNoTrigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CNA_SignalSetNoTrigger_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSetNoTrigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSetNoTrigger_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CNA_SignalSet_U8N_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CNA_SignalSet_U8N_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CNA_SignalSet_U8N_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_U8N_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CNA_SignalSet_U8N_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CanFrameCounter_Can_ABS3_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ABS3_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CanFrameCounter_Can_ABS3_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ABS3_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ABS3_Counter, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CanFrameCounter_Can_ECM2_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ECM2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CanFrameCounter_Can_ECM2_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ECM2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ECM2_Counter, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueue_ComEx_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_GetRxE2EStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ServerQueue_ComEx_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Power_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_ComEx_ComEx_SendSignal, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster, RTE_VAR_NOINIT) Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_HSM_HsmKeyM_GetAes128Key, RTE_VAR_NOINIT) Rte_CS_ServerQueue_HSM_HsmKeyM_GetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_HSM_HsmKeyM_GetAes128Key, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_HSM_HsmKeyM_GetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_HSM_HsmKeyM_GetAes128Key, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_HSM_HsmKeyM_SetAes128Key, RTE_VAR_NOINIT) Rte_CS_ServerQueue_HSM_HsmKeyM_SetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_HSM_HsmKeyM_SetAes128Key, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_HSM_HsmKeyM_SetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_HSM_HsmKeyM_SetAes128Key, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_HsmKeyM_SetAes128Key; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_HSM_Hsm_Port_TrngGenerate, RTE_VAR_NOINIT) Rte_CS_ServerQueue_HSM_Hsm_Port_TrngGenerate; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_HSM_Hsm_Port_TrngGenerate, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_HSM_Hsm_Port_TrngGenerate; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_HSM_Hsm_Port_TrngGenerate, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_IPC_IPC_DataSend_If_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueue_IPC_IPC_DataSend_If_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_IPC_IPC_DataSend_If_Operation, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_IPC_IPC_DataSend_If_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_IPC_IPC_DataSend_If_Operation, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_IoHwAb_IoHwAb_Interface_GetPin, RTE_VAR_NOINIT) Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetPin; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_IoHwAb_IoHwAb_Interface_GetPin, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetPin, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetPin, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_IoHwAb_IoHwAb_Interface_GetVoltage, RTE_VAR_NOINIT) Rte_CS_ServerQueue_IoHwAb_IoHwAb_Interface_GetVoltage; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_IoHwAb_IoHwAb_Interface_GetVoltage, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetVoltage, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_IoHwAb_IoHwAb_Interface_GetVoltage, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueue_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_VAR_NOINIT) Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_RTC_Sv_RTC_GetUTCTimeInMillis, RTE_VAR_NOINIT) Rte_CS_ServerQueue_RTC_Sv_RTC_GetUTCTimeInMillis; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_RTC_Sv_RTC_GetUTCTimeInMillis, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_RTC_Sv_RTC_GetUTCTimeInMillis; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_GetUTCTimeInMillis, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ServerQueue_RTC_Sv_RTC_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(TaskType, RTE_VAR_INIT) Rte_CS_WaitingTaskList_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar[1] = {
  INVALID_TASK
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo, RTE_VAR_NOINIT) Rte_CS_ServerQueue_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_VAR_NOINIT) Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_CNA_SignalGroupSet_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_Can_Server_CNA_SignalGroupSet_Operation, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CNA_SignalGroupSet_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_CNA_SignalGroupSet_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_ComEx_CNA_SignalSet_Operation[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_CNA_SignalSet_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_Can_Server_CNA_SignalSet_Operation, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_Operation[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_ComEx_CNA_SignalSet_Operation,
    &Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_CNA_SignalSet_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_Can_Server_CNA_SignalSetNoTrigger_Operation, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CNA_SignalSetNoTrigger_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_Can_Server_CNA_SignalSet_U8N_Operation, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CNA_SignalSet_U8N_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ABS3_Counter[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_Can_Server_CanFrameCounter_Can_ABS3_Counter, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ABS3_Counter[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ABS3_Counter,
    &Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ECM2_Counter[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_Can_Server_CanFrameCounter_Can_ECM2_Counter, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ECM2_Counter[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ECM2_Counter,
    &Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter, RTE_CONST) Rte_CS_ClientConfig_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter,
    &Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Can_Server_rpCS_ComEx_GetRxE2EStatus[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus[1] = {
  GateWay
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus[1] = {
  TT_GEAR
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DCM_Server_rpCS_ComEx_GetRxE2EStatus[1] = {
  Default_BSW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DidDataProcess_rpCS_ComEx_GetRxE2EStatus[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_EOL_EOL_ComEx_GetRxE2EStatus[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Power_ComEx_GetRxE2EStatus[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SOCManager_ComEx_GetRxE2EStatus[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Upgrade_rpCS_ComEx_GetRxE2EStatus[1] = {
  SYS
};

CONST(Rte_CS_ClientConfigType_ComEx_ComEx_GetRxE2EStatus, RTE_CONST) Rte_CS_ClientConfig_ComEx_ComEx_GetRxE2EStatus[11] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Can_Server_rpCS_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_DCM_Server_rpCS_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_DidDataProcess_rpCS_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_EOL_EOL_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_Power_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_SOCManager_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus
  },
  {
    1,
    Rte_CS_WaitingTaskList_Upgrade_rpCS_ComEx_GetRxE2EStatus,
    &Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Can_Server_rpCS_ComEx_SendSignal[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal[1] = {
  GateWay
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal[1] = {
  TT_GEAR
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DCM_Server_rpCS_ComEx_SendSignal[1] = {
  Default_BSW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DidDataProcess_rpCS_ComEx_SendSignal[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_EOL_EOL_ComEx_SendSignal[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Power_ComEx_SendSignal[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SOCManager_ComEx_SendSignal[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SecOc_Server_ComEx_SendSignal[1] = {
  BSW_COMM
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SocDtcProcess_rpCS_ComEx_SendSignal[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Upgrade_rpCS_ComEx_SendSignal[1] = {
  SYS
};

CONST(Rte_CS_ClientConfigType_ComEx_ComEx_SendSignal, RTE_CONST) Rte_CS_ClientConfig_ComEx_ComEx_SendSignal[12] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Can_Server_rpCS_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_DCM_Server_rpCS_ComEx_SendSignal,
    &Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_DidDataProcess_rpCS_ComEx_SendSignal,
    &Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_EOL_EOL_ComEx_SendSignal,
    &Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_Power_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Power_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_SOCManager_ComEx_SendSignal,
    &Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_SecOc_Server_ComEx_SendSignal,
    &Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_SocDtcProcess_rpCS_ComEx_SendSignal,
    &Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal
  },
  {
    1,
    Rte_CS_WaitingTaskList_Upgrade_rpCS_ComEx_SendSignal,
    &Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster[1] = {
  BSW_COMM
};

CONST(Rte_CS_ClientConfigType_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster, RTE_CONST) Rte_CS_ClientConfig_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster,
    &Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation[1] = {
  BSW_COMM
};

CONST(Rte_CS_ClientConfigType_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation, RTE_CONST) Rte_CS_ClientConfig_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation,
    &Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_CONST) Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus,
    &Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_CONST) Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus,
    &Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus, RTE_CONST) Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus,
    &Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus, RTE_CONST) Rte_CS_ClientConfig_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus,
    &Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation, RTE_CONST) Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation, RTE_CONST) Rte_CS_ClientConfig_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation, RTE_CONST) Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation, RTE_CONST) Rte_CS_ClientConfig_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_HsmKeyM_GetAes128Key[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_HSM_HsmKeyM_GetAes128Key, RTE_CONST) Rte_CS_ClientConfig_HSM_HsmKeyM_GetAes128Key[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_HsmKeyM_GetAes128Key,
    &Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_HsmKeyM_SetAes128Key[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_HSM_HsmKeyM_SetAes128Key, RTE_CONST) Rte_CS_ClientConfig_HSM_HsmKeyM_SetAes128Key[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_HsmKeyM_SetAes128Key,
    &Rte_CS_ClientQueue_Common_Normal_HsmKeyM_SetAes128Key
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_Hsm_Port_TrngGenerate[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_HSM_Hsm_Port_TrngGenerate, RTE_CONST) Rte_CS_ClientConfig_HSM_Hsm_Port_TrngGenerate[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_Hsm_Port_TrngGenerate,
    &Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate
  }
};

CONST(Rte_CS_ClientConfigType_IPC_IPC_DataSend_If_Operation, RTE_CONST) Rte_CS_ClientConfig_IPC_IPC_DataSend_If_Operation[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_IoHwAb_Interface_GetPin[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_IoHwAb_Interface_GetPin[1] = {
  TT_GEAR
};

CONST(Rte_CS_ClientConfigType_IoHwAb_IoHwAb_Interface_GetPin, RTE_CONST) Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetPin[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_IoHwAb_Interface_GetPin,
    &Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_IoHwAb_Interface_GetPin,
    &Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_IoHwAb_Interface_GetVoltage[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_IoHwAb_Interface_GetVoltage[1] = {
  TT_GEAR
};

CONST(Rte_CS_ClientConfigType_IoHwAb_IoHwAb_Interface_GetVoltage, RTE_CONST) Rte_CS_ClientConfig_IoHwAb_IoHwAb_Interface_GetVoltage[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_IoHwAb_Interface_GetVoltage,
    &Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_IoHwAb_Interface_GetVoltage,
    &Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock,
    &Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock,
    &Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock, RTE_CONST) Rte_CS_ClientConfig_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock,
    &Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_AMP_Os_Service_GetCounterValue[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_Os_Service_GetCounterValue[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_Os_Service_GetCounterValue[1] = {
  TT_GEAR
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_IIC_Os_Service_GetCounterValue[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Misc_Os_Service_GetCounterValue[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Power_Os_Service_GetCounterValue[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_RTC_Os_Service_GetCounterValue[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Vconfig_Os_Service_GetCounterValue[1] = {
  SYS
};

CONST(Rte_CS_ClientConfigType_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue, RTE_CONST) Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue[8] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_AMP_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_IIC_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Misc_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Power_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_RTC_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Vconfig_Os_Service_GetCounterValue,
    &Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_AMP_Os_Service_GetElapsedValue[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_Os_Service_GetElapsedValue[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_Os_Service_GetElapsedValue[1] = {
  TT_GEAR
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_IIC_Os_Service_GetElapsedValue[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Misc_Os_Service_GetElapsedValue[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Power_Os_Service_GetElapsedValue[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_RTC_Os_Service_GetElapsedValue[1] = {
  DRIVERS_SAFE
};

CONST(Rte_CS_ClientConfigType_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue, RTE_CONST) Rte_CS_ClientConfig_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue[7] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_AMP_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_IIC_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Misc_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_Power_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue
  },
  {
    1,
    Rte_CS_WaitingTaskList_RTC_Os_Service_GetElapsedValue,
    &Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_IRTC_Service_GetUTCTimeInMillis[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_RTC_Sv_RTC_GetUTCTimeInMillis, RTE_CONST) Rte_CS_ClientConfig_RTC_Sv_RTC_GetUTCTimeInMillis[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_IRTC_Service_GetUTCTimeInMillis,
    &Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar[1] = {
  SYS
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar[1] = {
  GateWay
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_IRTC_Service_UTC2PerpetualCalendar[1] = {
  FUEL_TC_ODO
};

CONST(Rte_CS_ClientConfigType_RTC_Sv_RTC_UTC2PerpetualCalendar, RTE_CONST) Rte_CS_ClientConfig_RTC_Sv_RTC_UTC2PerpetualCalendar[4] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar,
    &Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_IRTC_Service_UTC2PerpetualCalendar,
    &Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
  },
  {
    1,
    Rte_CS_WaitingTaskList_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar,
    &Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo[1] = {
  GateWay
};

CONST(Rte_CS_ClientConfigType_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo, RTE_CONST) Rte_CS_ClientConfig_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo,
    &Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  DRIVERS_SAFE
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  GateWay
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  TT_GEAR
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  Default_BSW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  SWC_LOW
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[1] = {
  SWC_LOW
};

CONST(Rte_CS_ClientConfigType_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, RTE_CONST) Rte_CS_ClientConfig_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig[7] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  },
  {
    1,
    Rte_CS_WaitingTaskList_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
    &Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick[1] = {
  FUEL_TC_ODO
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick[1] = {
  TT_GEAR
};

CONST(Rte_CS_ClientConfigType_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, RTE_CONST) Rte_CS_ClientConfig_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick,
    &Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
  },
  {
    1,
    Rte_CS_WaitingTaskList_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick,
    &Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
  }
};

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Queues for each Rte_Receive function
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(A_U8_10, RTE_VAR_NOINIT) Rte_Q_Gyro_Rc_IPC_Gyro_Message_Element[10]; /* PRQA S 1504, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
VAR(uint16, RTE_VAR_NOINIT) Rte_Q_IIC_Rc_IIC0_Notify_Message_Message[10]; /* PRQA S 1504, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
VAR(uint16, RTE_VAR_NOINIT) Rte_Q_IIC_Rc_IIC1_Notify_Message_Message[10]; /* PRQA S 1504, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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


#define Rte_QInit() (Rte_MemClr(Rte_QRamInfo, 3U * sizeof(Rte_QRamInfoType)))

#define Rte_QOverflow_Gyro_Rc_IPC_Gyro_Message_Element (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b0)
#define Rte_QOverflow_IIC_Rc_IIC0_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b1)
#define Rte_QOverflow_IIC_Rc_IIC1_Notify_Message_Message (Rte_OsApplication_Trust_OsCore0_QOverflow.Rte_b2)

#define Rte_OsApplication_Trust_OsCore0_QOverflowInit() (Rte_MemClr(&Rte_OsApplication_Trust_OsCore0_QOverflow, sizeof(Rte_OsApplication_Trust_OsCore0_QOverflow)))

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[3]; /* PRQA S 1504, 1514 */ /* MD_MSR_Rule8.7, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1504 L1 */ /* MD_MSR_Rule8.7 */
CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[3] =
{
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_Gyro_Rc_IPC_Gyro_Message_Element[0], /* Rte_BasePtr */ /* PRQA S 0314 */ /* MD_Rte_0314 */
    sizeof(A_U8_10),  /* Rte_BytesPerElement */
    10 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_IIC_Rc_IIC0_Notify_Message_Message[0], /* Rte_BasePtr */ /* PRQA S 0314 */ /* MD_Rte_0314 */
    sizeof(uint16),  /* Rte_BytesPerElement */
    10 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_IIC_Rc_IIC1_Notify_Message_Message[0], /* Rte_BasePtr */ /* PRQA S 0314 */ /* MD_Rte_0314 */
    sizeof(uint16),  /* Rte_BytesPerElement */
    10 /* Rte_MaxElements */
  }
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 4U;
  }
  else if (mode == 1U)
  {
    ret = 2U;
  }
  else if (mode == 2U)
  {
    ret = 1U;
  }
  else if (mode == 3U)
  {
    ret = 5U;
  }
  else if (mode == 4U)
  {
    ret = 3U;
  }
  else if (mode == 5U)
  {
    ret = 0U;
  }
  else
  {
    ret = 6U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 3U)
  {
    ret = 2U;
  }
  else if (mode == 96U)
  {
    ret = 1U;
  }
  else if (mode == 111U)
  {
    ret = 3U;
  }
  else
  {
    ret = 4U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 4U;
  }
  else if (mode == 3U)
  {
    ret = 6U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else if (mode == 5U)
  {
    ret = 3U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else
  {
    ret = 7U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

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

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1U)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i = 0;

  if (num >= 16U)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0U) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0U)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3U); i += 4U)
      {
        adst[i] = asrc[i];
        adst[i+1U] = asrc[i+1U];
        adst[i+2U] = asrc[i+2U];
        adst[i+3U] = asrc[i+3U];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15U) < num; i += 16U)
      {
        dst[i] = src[i];
        dst[i+1U] = src[i+1U];
        dst[i+2U] = src[i+2U];
        dst[i+3U] = src[i+3U];
        dst[i+4U] = src[i+4U];
        dst[i+5U] = src[i+5U];
        dst[i+6U] = src[i+6U];
        dst[i+7U] = src[i+7U];
        dst[i+8U] = src[i+8U];
        dst[i+9U] = src[i+9U];
        dst[i+10U] = src[i+10U];
        dst[i+11U] = src[i+11U];
        dst[i+12U] = src[i+12U];
        dst[i+13U] = src[i+13U];
        dst[i+14U] = src[i+14U];
        dst[i+15U] = src[i+15U];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(BSW_COMM); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(BSW_DIAGNOSE); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Default_BSW); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_COMM_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_COMM_0_2ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_COMM_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_FvM_FvM_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_1_5ms, RTE_MSEC_SystemTimer(1) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_DIAGNOSE_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* S/R queue initialization */
  Rte_QInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_OsApplication_Trust_OsCore0_QOverflowInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* C/S queue initialization */
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalGroupSet_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_CNA_SignalGroupSet_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_ComEx_CNA_SignalSet_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_GateWay_CNA_SignalSet_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSetNoTrigger_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CNA_SignalSet_U8N_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ABS3_Counter.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ABS3_Counter.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ECM2_Counter.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ECM2_Counter.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Can_Server_CanFrameCounter_Can_ESP_FD2_Counter.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_ComEx_ComEx_GetRxE2EStatus.Rte_Active = 0;
  Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_EOL_EOL_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Power_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SOCManager_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_GetRxE2EStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_ComEx_ComEx_SendSignal.Rte_Active = 0;
  Rte_CS_ClientQueue_Can_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_rpCS_SWCSafety_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_DCM_Server_rpCS_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_DidDataProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_EOL_EOL_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Power_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SOCManager_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SecOc_Server_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SocDtcProcess_rpCS_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Upgrade_rpCS_ComEx_SendSignal.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Common_Normal_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_Active = 0;
  Rte_CS_ClientQueue_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Common_Normal_ppCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery_SetEventStatus.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DemSatellite_0_Event_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground_SetEventStatus.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusRead_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_E2ESwitchStatusWrite_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusRead_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_DidDataProcess_ppCS_SecOcSwitchStatusWrite_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_HSM_HsmKeyM_GetAes128Key.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_HsmKeyM_GetAes128Key.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_HSM_HsmKeyM_SetAes128Key.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_HsmKeyM_SetAes128Key.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_HSM_Hsm_Port_TrngGenerate.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_Hsm_Port_TrngGenerate.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_IPC_IPC_DataSend_If_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_IPC_DataSend_If_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetPin.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetPin.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetPin.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_IoHwAb_IoHwAb_Interface_GetVoltage.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_IoHwAb_Interface_GetVoltage.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_IoHwAb_Interface_GetVoltage.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_1_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_2_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_3_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_4_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_ODO_5_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Block_Trip_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_NvM_PS_Common_NormalNvBlockNeed_Menu_WriteBlock.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetCounterValue.Rte_Active = 0;
  Rte_CS_ClientQueue_AMP_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_IIC_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Misc_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Power_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_RTC_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Vconfig_Os_Service_GetCounterValue.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_Os_OsCore0_swc_OsService_SystemTimer_GetElapsedValue.Rte_Active = 0;
  Rte_CS_ClientQueue_AMP_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_IIC_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Misc_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Power_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_RTC_Os_Service_GetElapsedValue.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_RTC_Sv_RTC_GetUTCTimeInMillis.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_IRTC_Service_GetUTCTimeInMillis.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_RTC_Sv_RTC_UTC2PerpetualCalendar.Rte_Active = 0;
  Rte_CS_ClientQueue_Can_Server_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SocDtcProcess_cpCS_IRTC_Service_UTC2PerpetualCalendar.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SocDtcProcess_PpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_Active = 0;
  Rte_CS_ClientQueue_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SocDtcProcess_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_Vconfig_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_Active = 0;
  Rte_CS_ClientQueue_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_Common_Safety_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick.Rte_CallCompleted = TRUE;

  /* activate the tasks */
  (void)ActivateTask(DRIVERS_SAFE); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(FUEL_TC_ODO); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(GateWay); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(IPC); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(SWC_LOW); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(SYS); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(TT_GEAR); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_CConfig_CConfig_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Misc_Misc_MainFunction_500ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(500)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SYS_0_100ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SYS_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SYS_0_50ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SYS_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DCM_Server_DCM_Server_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_HSM_Hsm_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable, RTE_MSEC_SystemTimer(10) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction, RTE_MSEC_SystemTimer(1) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction, RTE_MSEC_SystemTimer(1) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_IPC_IPC_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_IPC_IPC_STB_MainFunction, RTE_MSEC_SystemTimer(5) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_100ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_50ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Gyro_Gyro_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction, RTE_MSEC_SystemTimer(1) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction, RTE_MSEC_SystemTimer(9) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_, RTE_MSEC_SystemTimer(19) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction, RTE_MSEC_SystemTimer(2) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_, RTE_MSEC_SystemTimer(8) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction, RTE_MSEC_SystemTimer(4) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_, RTE_MSEC_SystemTimer(14) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A, RTE_MSEC_SystemTimer(7) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B, RTE_MSEC_SystemTimer(27) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_EOL_EOL_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_LOW_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

  Rte_StartTiming_InitState = RTE_STATE_INIT;
  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_CConfig_CConfig_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DRIVERS_SAFE_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Gyro_Gyro_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DCM_Server_DCM_Server_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_HSM_Hsm_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_IPC_IPC_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_IPC_IPC_STB_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_EOL_EOL_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_LOW_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Misc_Misc_MainFunction_500ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SYS_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SYS_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SYS_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SYS_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_BSW_COMM_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_COMM_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_COMM_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_FvM_FvM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_DIAGNOSE_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Default_BSW_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Default_BSW_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Default_BSW_1_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_OsApplication_NonTrust_OsCore0();
  Rte_InitMemory_OsApplication_Trust_OsCore0();
}


/**********************************************************************************************************************
 * Trusted Com wrapper functions
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_TrustedCom_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr)
{
  return Com_SendSignal(SignalId, SignalDataPtr);
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Adc_ADC_INT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_ADC_INT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Adc_ADC_RAMDATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_ADC_RAMDATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_FlsTst_FLSTST_DRIVERSTATE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, NONE) */
  /* disabled exclusive area */
}

FUNC(void, RTE_CODE) SchM_Exit_FlsTst_FLSTST_DRIVERSTATE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, NONE) */
  /* disabled exclusive area */
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_TIMERINT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_TIMERINT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_TIMERREG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_TIMERREG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_ICU_CHANNEL_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_ICU_CHANNEL_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_ICU_EDGECOUNT_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_ICU_EDGECOUNT_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_ICU_SIGNALMEASURE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_ICU_SIGNALMEASURE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_ICU_TIMESTAMP_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_ICU_TIMESTAMP_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_MCU_PWR_MODE_PSC_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_MCU_PWR_MODE_PSC_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_MCU_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_MCU_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_MCU_VARIABLE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_MCU_VARIABLE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_CHECK_HW_CONSISTENCY_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_CHECK_HW_CONSISTENCY_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_REFRESH_PORT_INTERNAL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_REFRESH_PORT_INTERNAL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_TO_DIO_ALT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_TO_DIO_ALT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Pwm_PWM_REGISTERS_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Pwm_PWM_REGISTERS_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_CHIP_SELECT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_CHIP_SELECT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_DMA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_DMA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_INTERRUPT_CONTROL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_INTERRUPT_CONTROL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_RAM_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_RAM_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_REG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_REG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_WDG_59_DRIVERA_MODE_SWITCH_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_WDG_59_DRIVERA_MODE_SWITCH_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_WDG_59_DRIVERA_TRIGG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_WDG_59_DRIVERA_TRIGG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}



/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx(void)
{
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxNeverReceivedFlags.Rte_RxNeverReceived_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA_Sender = !Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx = 0U;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */


/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx(void)
{

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_OsApplication_Trust_OsCore0_RxTimeoutFlags.Rte_RxTimeout_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx = 1U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
}


/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void)
{
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: Rule11.4
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

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

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
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

*/
