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
 *             File:  Rte_Common_GateWay.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Common_GateWay>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_GATEWAY_H
# define RTE_COMMON_GATEWAY_H

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

# include "Rte_Common_GateWay_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AWakeHold_DVRRemtCnSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_AwakeHlod_Heartbeat_counter;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_SocReadyFlag_Element;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit;
extern VAR(uint32, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AWakeHold_DVRRemtCnSts (0U)
#  define Rte_InitValue_AwakeHlod_Heartbeat_counter (0U)
#  define Rte_InitValue_IP_AvgFuelCons_IP_AvgFuelCons (0U)
#  define Rte_InitValue_IP_CurrTheme_IP_CurrTheme (0U)
#  define Rte_InitValue_IP_FuelAuxTankR_IP_FuelAuxTankR (0U)
#  define Rte_InitValue_IP_FuelMainTankR_IP_FuelMainTankR (0U)
#  define Rte_InitValue_IP_InstFuelCons_IP_InstFuelCons (0U)
#  define Rte_InitValue_IP_InstFuelConsUnit_IP_InstFuelConsUnit (FALSE)
#  define Rte_InitValue_IP_LagueSet_IP_LagueSet (0U)
#  define Rte_InitValue_IP_RemainDistance_IP_RemainDistance (0U)
#  define Rte_InitValue_IP_VehSpdDisp_IP_VehSpdDisp (0U)
#  define Rte_InitValue_IP_VelSpdDisp_Mile_IP_VelSpdDisp_Mile (0U)
#  define Rte_InitValue_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_CheckSum_IP2 (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_ABMWarnLmpFailrSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_ACCErr (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_AvgFuelCons (4095U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_BattChrgLmpSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_CurrTheme (4U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_EBDFailSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_Err (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_FuelAuxTankR (10U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_FuelLvlInfo (255U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_FuelMainTankR (10U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_InstFuelCons (16383U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_InstFuelConsUnit (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_LagueSet (15U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_RemainDistance (4095U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VINcompr (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VehSpdDisp (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VehSpdUnit (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VehTotDistance (16777215U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VehTotDistanceValid (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_RollingCounter_IP2 (0U)
#  define Rte_InitValue_Rc_CanOutputViaGateway_dummy_HUT_IP2_0 (0U)
#  define Rte_InitValue_SocReadyFlag_Element (0U)
#  define Rte_InitValue_piSR_E2ESwitchChangeTrigger_Element (0U)
#  define Rte_InitValue_ppSR_SWCGateWay_S2M_Information_SpeedValue (0U)
#  define Rte_InitValue_ppSR_SWCGateWay_S2M_Information_TachoValue (0U)
#  define Rte_InitValue_rpSR_SWCGateWay_CanOutput_IP_ABMWarnLmpFailrSts_Element (0U)
#  define Rte_InitValue_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element (0U)
#  define Rte_InitValue_rpSR_SWCGateWay_ReceiveRTCTime_SleepDateTime (-1LL)
#  define Rte_InitValue_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime (-1LL)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_tsGateWay, RTE_VAR_NOINIT) Rte_GateWay; /* PRQA S 0759 */ /* MD_MSR_Union */

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS1_0x231_ABS1_0x231(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS1_0x231_ABS1_0x231(P2VAR(ABS1_0x231, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS2_0x246_ABS2_0x246(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ABS2_0x246_ABS2_0x246(P2VAR(ABS2_0x246, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC1_0x29D_AC1_0x29D(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC1_0x29D_AC1_0x29D(P2VAR(AC1_0x29D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC2_0x385_AC2_0x385(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AC2_0x385_AC2_0x385(P2VAR(AC2_0x385, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB(P2VAR(ACC_FD2_0x2AB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4(P2VAR(ACC_FD3_0x2B4, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227(P2VAR(AEB_FD2_0x227, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3(P2VAR(AMP2_0x3E3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5(P2VAR(AMP3_0x3E5, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM12_0x238_BCM12_0x238(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM12_0x238_BCM12_0x238(P2VAR(BCM12_0x238, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM1_0x319_BCM1_0x319(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM1_0x319_BCM1_0x319(P2VAR(BCM1_0x319, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM3_0x345_BCM3_0x345(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM3_0x345_BCM3_0x345(P2VAR(BCM3_0x345, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM8_0x29F_BCM8_0x29F(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BCM8_0x29F_BCM8_0x29F(P2VAR(BCM8_0x29F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BMS4_0xF1_BMS4_0xF1(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_BMS4_0xF1_BMS4_0xF1(P2VAR(BMS4_0xF1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA1_0x165_CSA1_0x165(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA1_0x165_CSA1_0x165(P2VAR(CSA1_0x165, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA2_0xA1_CSA2_0xA1(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA2_0xA1_CSA2_0xA1(P2VAR(CSA2_0xA1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA3_0x244_CSA3_0x244(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_CSA3_0x244_CSA3_0x244(P2VAR(CSA3_0x244, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT3_0xA6_DCT3_0xA6(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT3_0xA6_DCT3_0xA6(P2VAR(DCT3_0xA6, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT5_0x221_DCT5_0x221(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DCT5_0x221_DCT5_0x221(P2VAR(DCT5_0x221, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA(P2VAR(DDCM1_0x2CA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1(P2VAR(DSM1_0x2C1, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3(P2VAR(ECM11_0x2D3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM1_0x111_ECM1_0x111(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM1_0x111_ECM1_0x111(P2VAR(ECM1_0x111, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM2_0x271_ECM2_0x271(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM2_0x271_ECM2_0x271(P2VAR(ECM2_0x271, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM3_0x371_ECM3_0x371(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ECM3_0x371_ECM3_0x371(P2VAR(ECM3_0x371, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8(P2VAR(EEM1_0x2A8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_PartNumber_0xF187_PartNumber_0xF187(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_PartNumber_0xF187_PartNumber_0xF187(P2VAR(EOL13Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2VAR(EOL_15Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2VAR(A_20Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2VAR(EOL4Bytes, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPB1_0x16B_EPB1_0x16B(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPB1_0x16B_EPB1_0x16B(P2VAR(EPB1_0x16B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147(P2VAR(EPS_FD1_0x147, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP11_0xC8_ESP11_0xC8(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP11_0xC8_ESP11_0xC8(P2VAR(ESP11_0xC8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP8_0x170_ESP8_0x170(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP8_0x170_ESP8_0x170(P2VAR(ESP8_0x170, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137(P2VAR(ESP_FD2_0x137, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB(P2VAR(GW_FD1_0x2BB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B(P2VAR(HAP_FD1_0x15B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274(P2VAR(HAP_FD2_0x274, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298(P2VAR(HAP_FD3_0x298, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2(P2VAR(HCU_HC7_0x3C2, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA(P2VAR(HCU_PT4_0x2FA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248(P2VAR(HCU_PT7_0x248, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HUD1_0x325_HUD1_0x325(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_HUD1_0x325_HUD1_0x325(P2VAR(HUD1_0x325, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D(P2VAR(IFC_FD2_0x23D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF(P2VAR(IFC_FD3_0x2CF, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD(P2VAR(PDCM1_0x2CD, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS2_0x295_PEPS2_0x295(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS2_0x295_PEPS2_0x295(P2VAR(PEPS2_0x295, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS4_0x302_PEPS4_0x302(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_PEPS4_0x302_PEPS4_0x302(P2VAR(PEPS4_0x302, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F(P2VAR(RSDS_FD1_0x16F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A(P2VAR(RSDS_FD2_0x30A, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS1_0x341_TPMS1_0x341(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS1_0x341_TPMS1_0x341(P2VAR(TPMS1_0x341, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS2_0x395_TPMS2_0x395(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_TPMS2_0x395_TPMS2_0x395(P2VAR(TPMS2_0x395, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Vconfig_GetKindBuffers_AllKinds(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA(P2VAR(WPC1_0x2BA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_GateWay_rpSR_SWCGateWay_MenuSetData_Element(P2VAR(MenuSetData_t, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT10_0x331_HUT10_0x331(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT10_0x331_HUT10_0x331(P2CONST(HUT10_0x331, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT13_0x31C_HUT13_0x31C(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT13_0x31C_HUT13_0x31C(P2CONST(HUT13_0x31C, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT15_0x1EE_HUT15_0x1EE(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT15_0x1EE_HUT15_0x1EE(P2CONST(HUT15_0x1EE, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT16_0x348_HUT16_0x348(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT16_0x348_HUT16_0x348(P2CONST(HUT16_0x348, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT17_0x33B_HUT17_0x33B(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT17_0x33B_HUT17_0x33B(P2CONST(HUT17_0x33B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT19_0x415_HUT19_0x415(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT19_0x415_HUT19_0x415(P2CONST(HUT19_0x415, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT1_0x367_HUT1_0x367(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT1_0x367_HUT1_0x367(P2CONST(HUT1_0x367, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT20_0x2DE_HUT20_0x2DE(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT20_0x2DE_HUT20_0x2DE(P2CONST(HUT20_0x2DE, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT21_0x2DD_HUT21_0x2DD(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT21_0x2DD_HUT21_0x2DD(P2CONST(HUT21_0x2DD, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT22_0x2DA_HUT22_0x2DA(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT22_0x2DA_HUT22_0x2DA(P2CONST(HUT22_0x2DA, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT23_0x2D8_HUT23_0x2D8(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT23_0x2D8_HUT23_0x2D8(P2CONST(HUT23_0x2D8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT25_0x339_HUT25_0x339(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT25_0x339_HUT25_0x339(P2CONST(HUT25_0x339, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT2_0x369_HUT2_0x369(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT2_0x369_HUT2_0x369(P2CONST(HUT2_0x369, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT30_0x1E9_HUT30_0x1E9(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT30_0x1E9_HUT30_0x1E9(P2CONST(HUT30_0x1E9, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT32_0x26F_HUT32_0x26F(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT32_0x26F_HUT32_0x26F(P2CONST(HUT32_0x26F, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT33_0x1ED_HUT33_0x1ED(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT33_0x1ED_HUT33_0x1ED(P2CONST(HUT33_0x1ED, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT34_0x370_HUT34_0x370(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT34_0x370_HUT34_0x370(P2CONST(HUT34_0x370, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT35_0x1E5_HUT35_0x1E5(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT35_0x1E5_HUT35_0x1E5(P2CONST(HUT35_0x1E5, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT39_0x1EB_HUT39_0x1EB(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT39_0x1EB_HUT39_0x1EB(P2CONST(HUT39_0x1EB, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT3_0x36B_HUT3_0x36B(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT3_0x36B_HUT3_0x36B(P2CONST(HUT3_0x36B, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT4_0x36D_HUT4_0x36D(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT4_0x36D_HUT4_0x36D(P2CONST(HUT4_0x36D, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT6_0x4A_HUT6_0x4A(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT6_0x4A_HUT6_0x4A(P2CONST(HUT6_0x4A, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT_FD1_0x2C3_HUT_FD1_0x2C3(P2CONST(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_HUT_FD1_0x2C3_HUT_FD1_0x2C3(P2CONST(HUT_FD1_0x2C3, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data(P2CONST(EnergyInfoIdDataType, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_CNA_SignalGroupSet_Operation(P2CONST(EventSignalInfo_Type, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_DATA) event_signal_info); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_CNA_SignalSet_Operation(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_IPC_DataSend_If_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) p_msg, uint16 len, uint8 priority); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, P2VAR(EventSignalType, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) date); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rcCS_SWCNormal_ReceiveOffroadInfo_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_AdasStatus_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveMenuTheme_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_rpCS_SWCGateWay_TtToChime_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


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
#  define Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Fuel_Set_Module_Data_Element() \
  (&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Fuel_Set_Module_Data_Element.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut() \
  (&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IStatus_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut() \
  (Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_Power_Out_SystemStateOut.status)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_ReceiveRTCTime_SleepDateTime() \
  (Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_ReceiveRTCTime_SleepDateTime.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime() \
  (Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_TC_Module_Output_Data_Element() \
  (&Rte_GateWay.Rte_RB.Rte_Common_GateWay_Common_GateWay_5msMainFunction.Rte_rpSR_SWCGateWay_TC_Module_Output_Data_Element.value)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ABM1_0x351_ABM1_0x351 Rte_Read_Common_GateWay_ABM1_0x351_ABM1_0x351
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ABM1_0x351_ABM1_0x351(data) ( \
    Rte_MemCpy32(data, Rte_C_ABM1_0x351_0, sizeof(ABM1_0x351)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ABS1_0x231_ABS1_0x231 Rte_Read_Common_GateWay_ABS1_0x231_ABS1_0x231
#  define Rte_Read_ABS2_0x246_ABS2_0x246 Rte_Read_Common_GateWay_ABS2_0x246_ABS2_0x246
#  define Rte_Read_ABS3_0x265_ABS3_0x265 Rte_Read_Common_GateWay_ABS3_0x265_ABS3_0x265
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ABS3_0x265_ABS3_0x265(data) ( \
    Rte_MemCpy32(data, Rte_C_ABS3_0x265_0, sizeof(ABS3_0x265)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AC1_0x29D_AC1_0x29D Rte_Read_Common_GateWay_AC1_0x29D_AC1_0x29D
#  define Rte_Read_AC2_0x385_AC2_0x385 Rte_Read_Common_GateWay_AC2_0x385_AC2_0x385
#  define Rte_Read_ACC_FD2_0x2AB_ACC_FD2_0x2AB Rte_Read_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB
#  define Rte_Read_ACC_FD3_0x2B4_ACC_FD3_0x2B4 Rte_Read_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4
#  define Rte_Read_ACC_FD4_0x2B8_ACC_FD4_0x2B8 Rte_Read_Common_GateWay_ACC_FD4_0x2B8_ACC_FD4_0x2B8
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ACC_FD4_0x2B8_ACC_FD4_0x2B8(data) ( \
    Rte_MemCpy32(data, Rte_C_ACC_FD4_0x2B8_0, sizeof(ACC_FD4_0x2B8)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AEB_FD2_0x227_AEB_FD2_0x227 Rte_Read_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227
#  define Rte_Read_AMP2_0x3E3_AMP2_0x3E3 Rte_Read_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3
#  define Rte_Read_AMP3_0x3E5_AMP3_0x3E5 Rte_Read_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5
#  define Rte_Read_BCM12_0x238_BCM12_0x238 Rte_Read_Common_GateWay_BCM12_0x238_BCM12_0x238
#  define Rte_Read_BCM1_0x319_BCM1_0x319 Rte_Read_Common_GateWay_BCM1_0x319_BCM1_0x319
#  define Rte_Read_BCM3_0x345_BCM3_0x345 Rte_Read_Common_GateWay_BCM3_0x345_BCM3_0x345
#  define Rte_Read_BCM6_0x28C_BCM6_0x28C Rte_Read_Common_GateWay_BCM6_0x28C_BCM6_0x28C
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BCM6_0x28C_BCM6_0x28C(data) ( \
    Rte_MemCpy(data, Rte_C_BCM6_0x28C_0, sizeof(BCM6_0x28C)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BCM8_0x29F_BCM8_0x29F Rte_Read_Common_GateWay_BCM8_0x29F_BCM8_0x29F
#  define Rte_Read_BMS19_0x352_BMS19_0x352 Rte_Read_Common_GateWay_BMS19_0x352_BMS19_0x352
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS19_0x352_BMS19_0x352(data) ( \
    Rte_MemCpy(data, Rte_C_BMS19_0x352_0, sizeof(BMS19_0x352)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS22_0x3BF_BMS22_0x3BF Rte_Read_Common_GateWay_BMS22_0x3BF_BMS22_0x3BF
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS22_0x3BF_BMS22_0x3BF(data) ( \
    Rte_MemCpy(data, Rte_C_BMS22_0x3BF_0, sizeof(BMS22_0x3BF)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS30_0x3F1_BMS30_0x3F1 Rte_Read_Common_GateWay_BMS30_0x3F1_BMS30_0x3F1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS30_0x3F1_BMS30_0x3F1(data) ( \
    Rte_MemCpy(data, Rte_C_BMS30_0x3F1_0, sizeof(BMS30_0x3F1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS35_0x2C4_BMS35_0x2C4 Rte_Read_Common_GateWay_BMS35_0x2C4_BMS35_0x2C4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS35_0x2C4_BMS35_0x2C4(data) ( \
    Rte_MemCpy(data, Rte_C_BMS35_0x2C4_0, sizeof(BMS35_0x2C4)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS4_0xF1_BMS4_0xF1 Rte_Read_Common_GateWay_BMS4_0xF1_BMS4_0xF1
#  define Rte_Read_BMS8_0x285_BMS8_0x285 Rte_Read_Common_GateWay_BMS8_0x285_BMS8_0x285
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS8_0x285_BMS8_0x285(data) ( \
    Rte_MemCpy(data, Rte_C_BMS8_0x285_0, sizeof(BMS8_0x285)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_FD14_0x1E3_BMS_FD14_0x1E3 Rte_Read_Common_GateWay_BMS_FD14_0x1E3_BMS_FD14_0x1E3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_BMS_FD14_0x1E3_BMS_FD14_0x1E3(data) ( \
    Rte_MemCpy(data, Rte_C_BMS_FD14_0x1E3_0, sizeof(BMS_FD14_0x1E3)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CP1_0x35E_CP1_0x35E Rte_Read_Common_GateWay_CP1_0x35E_CP1_0x35E
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_CP1_0x35E_CP1_0x35E(data) ( \
    Rte_MemCpy(data, Rte_C_CP1_0x35E_0, sizeof(CP1_0x35E)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CR_FD1_0x15E_CR_FD1_0x15E Rte_Read_Common_GateWay_CR_FD1_0x15E_CR_FD1_0x15E
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_CR_FD1_0x15E_CR_FD1_0x15E(data) ( \
    Rte_MemCpy32(data, Rte_C_CR_FD1_0x15E_0, sizeof(CR_FD1_0x15E)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CSA1_0x165_CSA1_0x165 Rte_Read_Common_GateWay_CSA1_0x165_CSA1_0x165
#  define Rte_Read_CSA2_0xA1_CSA2_0xA1 Rte_Read_Common_GateWay_CSA2_0xA1_CSA2_0xA1
#  define Rte_Read_CSA3_0x244_CSA3_0x244 Rte_Read_Common_GateWay_CSA3_0x244_CSA3_0x244
#  define Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes Rte_Read_Common_GateWay_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
#  define Rte_Read_DCT3_0xA6_DCT3_0xA6 Rte_Read_Common_GateWay_DCT3_0xA6_DCT3_0xA6
#  define Rte_Read_DCT5_0x221_DCT5_0x221 Rte_Read_Common_GateWay_DCT5_0x221_DCT5_0x221
#  define Rte_Read_DCT7_0x235_DCT7_0x235 Rte_Read_Common_GateWay_DCT7_0x235_DCT7_0x235
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_DCT7_0x235_DCT7_0x235(data) ( \
    Rte_MemCpy32(data, Rte_C_DCT7_0x235_0, sizeof(DCT7_0x235)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DDCM1_0x2CA_DDCM1_0x2CA Rte_Read_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA
#  define Rte_Read_DHT_FD1_0xC1_DHT_FD1_0xC1 Rte_Read_Common_GateWay_DHT_FD1_0xC1_DHT_FD1_0xC1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_DHT_FD1_0xC1_DHT_FD1_0xC1(data) ( \
    Rte_MemCpy32(data, Rte_C_DHT_FD1_0xC1_0, sizeof(DHT_FD1_0xC1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DMS_FD1_0x24D_DMS_FD1_0x24D Rte_Read_Common_GateWay_DMS_FD1_0x24D_DMS_FD1_0x24D
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_DMS_FD1_0x24D_DMS_FD1_0x24D(data) ( \
    Rte_MemCpy32(data, Rte_C_DMS_FD1_0x24D_0, sizeof(DMS_FD1_0x24D)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DSM1_0x2C1_DSM1_0x2C1 Rte_Read_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1
#  define Rte_Read_ECM11_0x2D3_ECM11_0x2D3 Rte_Read_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3
#  define Rte_Read_ECM19_0x3B5_ECM19_0x3B5 Rte_Read_Common_GateWay_ECM19_0x3B5_ECM19_0x3B5
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ECM19_0x3B5_ECM19_0x3B5(data) ( \
    Rte_MemCpy(data, Rte_C_ECM_VIN_0, sizeof(ECM_VIN)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ECM1_0x111_ECM1_0x111 Rte_Read_Common_GateWay_ECM1_0x111_ECM1_0x111
#  define Rte_Read_ECM2_0x271_ECM2_0x271 Rte_Read_Common_GateWay_ECM2_0x271_ECM2_0x271
#  define Rte_Read_ECM3_0x371_ECM3_0x371 Rte_Read_Common_GateWay_ECM3_0x371_ECM3_0x371
#  define Rte_Read_ECM_PT7_0x117_ECM_PT7_0x117 Rte_Read_Common_GateWay_ECM_PT7_0x117_ECM_PT7_0x117
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ECM_PT7_0x117_ECM_PT7_0x117(data) ( \
    Rte_MemCpy(data, Rte_C_ECM_PT7_0x117_0, sizeof(ECM_PT7_0x117)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EEM1_0x2A8_EEM1_0x2A8 Rte_Read_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8
#  define Rte_Read_ELD1_0x152_ELD1_0x152 Rte_Read_Common_GateWay_ELD1_0x152_ELD1_0x152
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ELD1_0x152_ELD1_0x152(data) ( \
    Rte_MemCpy(data, Rte_C_ELD1_0x152_0, sizeof(ELD1_0x152)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EOL_PartNumber_0xF187_PartNumber_0xF187 Rte_Read_Common_GateWay_EOL_PartNumber_0xF187_PartNumber_0xF187
#  define Rte_Read_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193 Rte_Read_Common_GateWay_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193
#  define Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C Rte_Read_Common_GateWay_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C
#  define Rte_Read_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01 Rte_Read_Common_GateWay_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01
#  define Rte_Read_EPB1_0x16B_EPB1_0x16B Rte_Read_Common_GateWay_EPB1_0x16B_EPB1_0x16B
#  define Rte_Read_EPS1_0x168_EPS1_0x168 Rte_Read_Common_GateWay_EPS1_0x168_EPS1_0x168
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_EPS1_0x168_EPS1_0x168(data) ( \
    Rte_MemCpy(data, Rte_C_EPS1_0x168_0, sizeof(EPS1_0x168)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EPS_FD1_0x147_EPS_FD1_0x147 Rte_Read_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147
#  define Rte_Read_ESCL2_0x303_ESCL2_0x303 Rte_Read_Common_GateWay_ESCL2_0x303_ESCL2_0x303
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ESCL2_0x303_ESCL2_0x303(data) ( \
    Rte_MemCpy(data, Rte_C_ESCL2_0x303_0, sizeof(ESCL2_0x303)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ESP10_0xD8_ESP10_0xD8 Rte_Read_Common_GateWay_ESP10_0xD8_ESP10_0xD8
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ESP10_0xD8_ESP10_0xD8(data) ( \
    Rte_MemCpy(data, Rte_C_ESP10_0xD8_0, sizeof(ESP10_0xD8)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ESP11_0xC8_ESP11_0xC8 Rte_Read_Common_GateWay_ESP11_0xC8_ESP11_0xC8
#  define Rte_Read_ESP1_0x149_ESP1_0x149 Rte_Read_Common_GateWay_ESP1_0x149_ESP1_0x149
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ESP1_0x149_ESP1_0x149(data) ( \
    Rte_MemCpy32(data, Rte_C_ESP1_0x149_0, sizeof(ESP1_0x149)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ESP2_0x145_ESP2_0x145 Rte_Read_Common_GateWay_ESP2_0x145_ESP2_0x145
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_ESP2_0x145_ESP2_0x145(data) ( \
    Rte_MemCpy32(data, Rte_C_ESP2_0x145_0, sizeof(ESP2_0x145)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ESP8_0x170_ESP8_0x170 Rte_Read_Common_GateWay_ESP8_0x170_ESP8_0x170
#  define Rte_Read_ESP_FD2_0x137_ESP_FD2_0x137 Rte_Read_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137
#  define Rte_Read_FPAS1_0x26D_FPAS1_0x26D Rte_Read_Common_GateWay_FPAS1_0x26D_FPAS1_0x26D
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_FPAS1_0x26D_FPAS1_0x26D(data) ( \
    Rte_MemCpy(data, Rte_C_FPAS1_0x26D_0, sizeof(FPAS1_0x26D)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_F_PBox1_0x19B_F_PBox1_0x19B Rte_Read_Common_GateWay_F_PBox1_0x19B_F_PBox1_0x19B
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_F_PBox1_0x19B_F_PBox1_0x19B(data) ( \
    Rte_MemCpy(data, Rte_C_F_PBox1_0x19B_0, sizeof(F_PBox1_0x19B)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_GW_FD1_0x2BB_GW_FD1_0x2BB Rte_Read_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB
#  define Rte_Read_HAP_FD1_0x15B_HAP_FD1_0x15B Rte_Read_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B
#  define Rte_Read_HAP_FD2_0x274_HAP_FD2_0x274 Rte_Read_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274
#  define Rte_Read_HAP_FD3_0x298_HAP_FD3_0x298 Rte_Read_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298
#  define Rte_Read_HAP_FD6_0x289_HAP_FD6_0x289 Rte_Read_Common_GateWay_HAP_FD6_0x289_HAP_FD6_0x289
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HAP_FD6_0x289_HAP_FD6_0x289(data) ( \
    Rte_MemCpy32(data, Rte_C_HAP_FD6_0x289_0, sizeof(HAP_FD6_0x289)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HAP_FD7_0x29B_HAP_FD7_0x29B Rte_Read_Common_GateWay_HAP_FD7_0x29B_HAP_FD7_0x29B
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HAP_FD7_0x29B_HAP_FD7_0x29B(data) ( \
    Rte_MemCpy32(data, Rte_C_HAP_FD7_0x29B_0, sizeof(HAP_FD7_0x29B)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HC1_0x287_HC1_0x287 Rte_Read_Common_GateWay_HC1_0x287_HC1_0x287
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HC1_0x287_HC1_0x287(data) ( \
    Rte_MemCpy(data, Rte_C_HC1_0x287_0, sizeof(HC1_0x287)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCM_L1_0x308_HCM_L1_0x308 Rte_Read_Common_GateWay_HCM_L1_0x308_HCM_L1_0x308
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCM_L1_0x308_HCM_L1_0x308(data) ( \
    Rte_MemCpy(data, Rte_C_HCM_L1_0x308_0, sizeof(HCM_L1_0x308)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCM_R1_0x30D_HCM_R1_0x30D Rte_Read_Common_GateWay_HCM_R1_0x30D_HCM_R1_0x30D
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCM_R1_0x30D_HCM_R1_0x30D(data) ( \
    Rte_MemCpy(data, Rte_C_HCM_R1_0x30D_0, sizeof(HCM_R1_0x30D)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_FD1_0x60_HCU_FD1_0x60 Rte_Read_Common_GateWay_HCU_FD1_0x60_HCU_FD1_0x60
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_FD1_0x60_HCU_FD1_0x60(data) ( \
    Rte_MemCpy32(data, Rte_C_HCU_FD1_0x60_0, sizeof(HCU_FD1_0x60)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_HC3_0x268_HCU_HC3_0x268 Rte_Read_Common_GateWay_HCU_HC3_0x268_HCU_HC3_0x268
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_HC3_0x268_HCU_HC3_0x268(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_HC3_0x268_0, sizeof(HCU_HC3_0x268)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_HC6_0x314_HCU_HC6_0x314 Rte_Read_Common_GateWay_HCU_HC6_0x314_HCU_HC6_0x314
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_HC6_0x314_HCU_HC6_0x314(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_HC6_0x314_0, sizeof(HCU_HC6_0x314)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_HC7_0x3C2_HCU_HC7_0x3C2 Rte_Read_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2
#  define Rte_Read_HCU_HC8_0x1E2_HCU_HC8_0x1E2 Rte_Read_Common_GateWay_HCU_HC8_0x1E2_HCU_HC8_0x1E2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_HC8_0x1E2_HCU_HC8_0x1E2(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_HC8_0x1E2_0, sizeof(HCU_HC8_0x1E2)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_HP5_0x201_HCU_HP5_0x201 Rte_Read_Common_GateWay_HCU_HP5_0x201_HCU_HP5_0x201
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_HP5_0x201_HCU_HP5_0x201(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_HP5_0x201_0, sizeof(HCU_HP5_0x201)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_HP6_0x11A_HCU_HP6_0x11A Rte_Read_Common_GateWay_HCU_HP6_0x11A_HCU_HP6_0x11A
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_HP6_0x11A_HCU_HP6_0x11A(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_HP6_0x11A_0, sizeof(HCU_HP6_0x11A)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_PT4_0x2FA_HCU_PT4_0x2FA Rte_Read_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA
#  define Rte_Read_HCU_PT5_0x14A_HCU_PT5_0x14A Rte_Read_Common_GateWay_HCU_PT5_0x14A_HCU_PT5_0x14A
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_PT5_0x14A_HCU_PT5_0x14A(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_PT5_0x14A_0, sizeof(HCU_PT5_0x14A)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_PT7_0x248_HCU_PT7_0x248 Rte_Read_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248
#  define Rte_Read_HCU_PT8_0x1C0_HCU_PT8_0x1C0 Rte_Read_Common_GateWay_HCU_PT8_0x1C0_HCU_PT8_0x1C0
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_HCU_PT8_0x1C0_HCU_PT8_0x1C0(data) ( \
    Rte_MemCpy(data, Rte_C_HCU_PT8_0x1C0_0, sizeof(HCU_PT8_0x1C0)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HUD1_0x325_HUD1_0x325 Rte_Read_Common_GateWay_HUD1_0x325_HUD1_0x325
#  define Rte_Read_Haldex1_0x251_Haldex1_0x251 Rte_Read_Common_GateWay_Haldex1_0x251_Haldex1_0x251
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_Haldex1_0x251_Haldex1_0x251(data) ( \
    Rte_MemCpy(data, Rte_C_Haldex1_0x251_0, sizeof(Haldex1_0x251)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_IFC_FD2_0x23D_IFC_FD2_0x23D Rte_Read_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D
#  define Rte_Read_IFC_FD3_0x2CF_IFC_FD3_0x2CF Rte_Read_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF
#  define Rte_Read_IFC_FD5_0x19F_IFC_FD5_0x19F Rte_Read_Common_GateWay_IFC_FD5_0x19F_IFC_FD5_0x19F
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_IFC_FD5_0x19F_IFC_FD5_0x19F(data) ( \
    Rte_MemCpy32(data, Rte_C_IFC_FD5_0x19F_0, sizeof(IFC_FD5_0x19F)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_IFC_FD6_0x222_IFC_FD6_0x222 Rte_Read_Common_GateWay_IFC_FD6_0x222_IFC_FD6_0x222
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_IFC_FD6_0x222_IFC_FD6_0x222(data) ( \
    Rte_MemCpy32(data, Rte_C_IFC_FD6_0x222_0, sizeof(IFC_FD6_0x222)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_OBC1_0x316_OBC1_0x316 Rte_Read_Common_GateWay_OBC1_0x316_OBC1_0x316
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_OBC1_0x316_OBC1_0x316(data) ( \
    Rte_MemCpy(data, Rte_C_OBC1_0x316_0, sizeof(OBC1_0x316)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_OBC2_0x317_OBC2_0x317 Rte_Read_Common_GateWay_OBC2_0x317_OBC2_0x317
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_OBC2_0x317_OBC2_0x317(data) ( \
    Rte_MemCpy(data, Rte_C_OBC2_0x317_0, sizeof(OBC2_0x317)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PDCM1_0x2CD_PDCM1_0x2CD Rte_Read_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD
#  define Rte_Read_PEPS2_0x295_PEPS2_0x295 Rte_Read_Common_GateWay_PEPS2_0x295_PEPS2_0x295
#  define Rte_Read_PEPS4_0x302_PEPS4_0x302 Rte_Read_Common_GateWay_PEPS4_0x302_PEPS4_0x302
#  define Rte_Read_PLG_1_0x2FE_PLG_1_0x2FE Rte_Read_Common_GateWay_PLG_1_0x2FE_PLG_1_0x2FE
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_PLG_1_0x2FE_PLG_1_0x2FE(data) ( \
    Rte_MemCpy(data, Rte_C_PLG_1_0x2FE_0, sizeof(PLG_1_0x2FE)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS1_0x26E_RPAS1_0x26E Rte_Read_Common_GateWay_RPAS1_0x26E_RPAS1_0x26E
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_RPAS1_0x26E_RPAS1_0x26E(data) ( \
    Rte_MemCpy(data, Rte_C_RPAS1_0x26E_0, sizeof(RPAS1_0x26E)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS2_0x2ED_RPAS2_0x2ED Rte_Read_Common_GateWay_RPAS2_0x2ED_RPAS2_0x2ED
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_RPAS2_0x2ED_RPAS2_0x2ED(data) ( \
    Rte_MemCpy(data, Rte_C_RPAS2_0x2ED_0, sizeof(RPAS2_0x2ED)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_FD1_0x16F_RSDS_FD1_0x16F Rte_Read_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F
#  define Rte_Read_RSDS_FD2_0x30A_RSDS_FD2_0x30A Rte_Read_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A
#  define Rte_Read_R_PBox1_0x19C_R_PBox1_0x19C Rte_Read_Common_GateWay_R_PBox1_0x19C_R_PBox1_0x19C
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_R_PBox1_0x19C_R_PBox1_0x19C(data) ( \
    Rte_MemCpy32(data, Rte_C_R_PBox1_0x19C_0, sizeof(R_PBox1_0x19C)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts Rte_Read_Common_GateWay_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts
#  define Rte_Read_Common_GateWay_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts(data) (*(data) = Rte_Common_Safety_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_CheckSum_IP2 Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_CheckSum_IP2
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_CheckSum_IP2(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_ABMWarnLmpFailrSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_ABMWarnLmpFailrSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_ABMWarnLmpFailrSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_ACCErr Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_ACCErr
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_ACCErr(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_AvgFuelCons Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_AvgFuelCons
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_AvgFuelCons(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_BattChrgLmpSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_BattChrgLmpSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_BattChrgLmpSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_CurrTheme Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_CurrTheme
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_CurrTheme(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_EBDFailSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_EBDFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_EBDFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
/* PRQA L:L1 */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_Err Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_Err
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_Err(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_FuelAuxTankR Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelAuxTankR
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelAuxTankR(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_FuelLvlInfo Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelLvlInfo
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelLvlInfo(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_FuelMainTankR Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelMainTankR
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelMainTankR(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelCons Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_InstFuelCons
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_InstFuelCons(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelConsUnit Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_InstFuelConsUnit
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_InstFuelConsUnit(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_LagueSet Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_LagueSet
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_LagueSet(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_RemainDistance Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_RemainDistance
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_RemainDistance(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VINcompr Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VINcompr
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VINcompr(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdDisp Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehSpdDisp
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehSpdDisp(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdUnit Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehSpdUnit
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehSpdUnit(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VehTotDistance Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehTotDistance
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehTotDistance(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VehTotDistanceValid Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehTotDistanceValid
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehTotDistanceValid(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_RollingCounter_IP2 Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_RollingCounter_IP2
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_RollingCounter_IP2(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_CanOutputViaGateway_dummy_HUT_IP2_0 Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_dummy_HUT_IP2_0
#  define Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_dummy_HUT_IP2_0(data) (*(data) = Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SCM1_0x2D1_SCM1_0x2D1 Rte_Read_Common_GateWay_SCM1_0x2D1_SCM1_0x2D1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SCM1_0x2D1_SCM1_0x2D1(data) ( \
    Rte_MemCpy(data, Rte_C_SCM1_0x2D1_0, sizeof(SCM1_0x2D1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2 Rte_Read_Common_GateWay_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(data) (*(data) = Rte_C_SG_ACC3_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2 Rte_Read_Common_GateWay_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(data) (*(data) = Rte_C_SG_ACC4_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2 Rte_Read_Common_GateWay_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2(data) (*(data) = Rte_C_SG_ACC6_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2 Rte_Read_Common_GateWay_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(data) (*(data) = Rte_C_SG_ACC7_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2 Rte_Read_Common_GateWay_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(data) (*(data) = Rte_C_SG_ACC8_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9 Rte_Read_Common_GateWay_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9(data) ( \
    Rte_MemCpy(data, Rte_C_TMCU_FD3_0x3C9_0, sizeof(TMCU_FD3_0x3C9)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TPMS1_0x341_TPMS1_0x341 Rte_Read_Common_GateWay_TPMS1_0x341_TPMS1_0x341
#  define Rte_Read_TPMS2_0x395_TPMS2_0x395 Rte_Read_Common_GateWay_TPMS2_0x395_TPMS2_0x395
#  define Rte_Read_T_Box_FD1_0x33_T_Box_FD1_0x33 Rte_Read_Common_GateWay_T_Box_FD1_0x33_T_Box_FD1_0x33
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_T_Box_FD1_0x33_T_Box_FD1_0x33(data) ( \
    Rte_MemCpy32(data, Rte_C_T_Box_FD1_0x33_0, sizeof(T_Box_FD1_0x33)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_T_Box_FD3_0x3E9_T_Box_FD3_0x3E9 Rte_Read_Common_GateWay_T_Box_FD3_0x3E9_T_Box_FD3_0x3E9
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_T_Box_FD3_0x3E9_T_Box_FD3_0x3E9(data) ( \
    Rte_MemCpy32(data, Rte_C_T_Box_FD3_0x3E9_0, sizeof(T_Box_FD3_0x3E9)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Trailer1_0x273_Trailer1_0x273 Rte_Read_Common_GateWay_Trailer1_0x273_Trailer1_0x273
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_Trailer1_0x273_Trailer1_0x273(data) ( \
    Rte_MemCpy(data, Rte_C_Trailer1_0x273_0, sizeof(Trailer1_0x273)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_VSG1_0x2E1_VSG1_0x2E1 Rte_Read_Common_GateWay_VSG1_0x2E1_VSG1_0x2E1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_GateWay_VSG1_0x2E1_VSG1_0x2E1(data) ( \
    Rte_MemCpy(data, Rte_C_VSG1_0x2E1_0, sizeof(VSG1_0x2E1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Vconfig_GetKindBuffers_AllKinds Rte_Read_Common_GateWay_Vconfig_GetKindBuffers_AllKinds
#  define Rte_Read_WPC1_0x2BA_WPC1_0x2BA Rte_Read_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA
#  define Rte_Read_piSR_E2ESwitchChangeTrigger_Element Rte_Read_Common_GateWay_piSR_E2ESwitchChangeTrigger_Element
#  define Rte_Read_Common_GateWay_piSR_E2ESwitchChangeTrigger_Element(data) (*(data) = Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCGateWay_CanOutput_IP_ABMWarnLmpFailrSts_Element Rte_Read_Common_GateWay_rpSR_SWCGateWay_CanOutput_IP_ABMWarnLmpFailrSts_Element
#  define Rte_Read_Common_GateWay_rpSR_SWCGateWay_CanOutput_IP_ABMWarnLmpFailrSts_Element(data) (*(data) = Rte_Common_Safety_ppSR_SWCSafety_CanOutput_IP_ABMWarnLmpFailrSts_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element Rte_Read_Common_GateWay_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element
#  define Rte_Read_Common_GateWay_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element(data) (*(data) = Rte_SocDtcProcess_ppSR_DtcInfoForIPErrorStatus_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCGateWay_MenuSetData_Element Rte_Read_Common_GateWay_rpSR_SWCGateWay_MenuSetData_Element


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_ABM1_0x351_ABM1_0x351 Rte_IsUpdated_Common_GateWay_ABM1_0x351_ABM1_0x351
#  define Rte_IsUpdated_Common_GateWay_ABM1_0x351_ABM1_0x351() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ABS1_0x231_ABS1_0x231 Rte_IsUpdated_Common_GateWay_ABS1_0x231_ABS1_0x231
#  define Rte_IsUpdated_Common_GateWay_ABS1_0x231_ABS1_0x231() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS1_0x231_ABS1_0x231_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ABS2_0x246_ABS2_0x246 Rte_IsUpdated_Common_GateWay_ABS2_0x246_ABS2_0x246
#  define Rte_IsUpdated_Common_GateWay_ABS2_0x246_ABS2_0x246() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ABS2_0x246_ABS2_0x246_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ABS3_0x265_ABS3_0x265 Rte_IsUpdated_Common_GateWay_ABS3_0x265_ABS3_0x265
#  define Rte_IsUpdated_Common_GateWay_ABS3_0x265_ABS3_0x265() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_AC1_0x29D_AC1_0x29D Rte_IsUpdated_Common_GateWay_AC1_0x29D_AC1_0x29D
#  define Rte_IsUpdated_Common_GateWay_AC1_0x29D_AC1_0x29D() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AC1_0x29D_AC1_0x29D_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ACC_FD2_0x2AB_ACC_FD2_0x2AB Rte_IsUpdated_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB
#  define Rte_IsUpdated_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD2_0x2AB_ACC_FD2_0x2AB_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ACC_FD3_0x2B4_ACC_FD3_0x2B4 Rte_IsUpdated_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4
#  define Rte_IsUpdated_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ACC_FD3_0x2B4_ACC_FD3_0x2B4_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ACC_FD4_0x2B8_ACC_FD4_0x2B8 Rte_IsUpdated_Common_GateWay_ACC_FD4_0x2B8_ACC_FD4_0x2B8
#  define Rte_IsUpdated_Common_GateWay_ACC_FD4_0x2B8_ACC_FD4_0x2B8() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_AEB_FD2_0x227_AEB_FD2_0x227 Rte_IsUpdated_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227
#  define Rte_IsUpdated_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AEB_FD2_0x227_AEB_FD2_0x227_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_AMP2_0x3E3_AMP2_0x3E3 Rte_IsUpdated_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3
#  define Rte_IsUpdated_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP2_0x3E3_AMP2_0x3E3_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_AMP3_0x3E5_AMP3_0x3E5 Rte_IsUpdated_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5
#  define Rte_IsUpdated_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_AMP3_0x3E5_AMP3_0x3E5_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BCM12_0x238_BCM12_0x238 Rte_IsUpdated_Common_GateWay_BCM12_0x238_BCM12_0x238
#  define Rte_IsUpdated_Common_GateWay_BCM12_0x238_BCM12_0x238() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM12_0x238_BCM12_0x238_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BCM1_0x319_BCM1_0x319 Rte_IsUpdated_Common_GateWay_BCM1_0x319_BCM1_0x319
#  define Rte_IsUpdated_Common_GateWay_BCM1_0x319_BCM1_0x319() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM1_0x319_BCM1_0x319_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BCM3_0x345_BCM3_0x345 Rte_IsUpdated_Common_GateWay_BCM3_0x345_BCM3_0x345
#  define Rte_IsUpdated_Common_GateWay_BCM3_0x345_BCM3_0x345() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM3_0x345_BCM3_0x345_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BCM6_0x28C_BCM6_0x28C Rte_IsUpdated_Common_GateWay_BCM6_0x28C_BCM6_0x28C
#  define Rte_IsUpdated_Common_GateWay_BCM6_0x28C_BCM6_0x28C() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BCM8_0x29F_BCM8_0x29F Rte_IsUpdated_Common_GateWay_BCM8_0x29F_BCM8_0x29F
#  define Rte_IsUpdated_Common_GateWay_BCM8_0x29F_BCM8_0x29F() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BCM8_0x29F_BCM8_0x29F_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS19_0x352_BMS19_0x352 Rte_IsUpdated_Common_GateWay_BMS19_0x352_BMS19_0x352
#  define Rte_IsUpdated_Common_GateWay_BMS19_0x352_BMS19_0x352() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS22_0x3BF_BMS22_0x3BF Rte_IsUpdated_Common_GateWay_BMS22_0x3BF_BMS22_0x3BF
#  define Rte_IsUpdated_Common_GateWay_BMS22_0x3BF_BMS22_0x3BF() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS30_0x3F1_BMS30_0x3F1 Rte_IsUpdated_Common_GateWay_BMS30_0x3F1_BMS30_0x3F1
#  define Rte_IsUpdated_Common_GateWay_BMS30_0x3F1_BMS30_0x3F1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS35_0x2C4_BMS35_0x2C4 Rte_IsUpdated_Common_GateWay_BMS35_0x2C4_BMS35_0x2C4
#  define Rte_IsUpdated_Common_GateWay_BMS35_0x2C4_BMS35_0x2C4() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS4_0xF1_BMS4_0xF1 Rte_IsUpdated_Common_GateWay_BMS4_0xF1_BMS4_0xF1
#  define Rte_IsUpdated_Common_GateWay_BMS4_0xF1_BMS4_0xF1() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_BMS4_0xF1_BMS4_0xF1_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS8_0x285_BMS8_0x285 Rte_IsUpdated_Common_GateWay_BMS8_0x285_BMS8_0x285
#  define Rte_IsUpdated_Common_GateWay_BMS8_0x285_BMS8_0x285() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CP1_0x35E_CP1_0x35E Rte_IsUpdated_Common_GateWay_CP1_0x35E_CP1_0x35E
#  define Rte_IsUpdated_Common_GateWay_CP1_0x35E_CP1_0x35E() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CR_FD1_0x15E_CR_FD1_0x15E Rte_IsUpdated_Common_GateWay_CR_FD1_0x15E_CR_FD1_0x15E
#  define Rte_IsUpdated_Common_GateWay_CR_FD1_0x15E_CR_FD1_0x15E() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CSA1_0x165_CSA1_0x165 Rte_IsUpdated_Common_GateWay_CSA1_0x165_CSA1_0x165
#  define Rte_IsUpdated_Common_GateWay_CSA1_0x165_CSA1_0x165() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA1_0x165_CSA1_0x165_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CSA2_0xA1_CSA2_0xA1 Rte_IsUpdated_Common_GateWay_CSA2_0xA1_CSA2_0xA1
#  define Rte_IsUpdated_Common_GateWay_CSA2_0xA1_CSA2_0xA1() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA2_0xA1_CSA2_0xA1_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CSA3_0x244_CSA3_0x244 Rte_IsUpdated_Common_GateWay_CSA3_0x244_CSA3_0x244
#  define Rte_IsUpdated_Common_GateWay_CSA3_0x244_CSA3_0x244() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_CSA3_0x244_CSA3_0x244_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT3_0xA6_DCT3_0xA6 Rte_IsUpdated_Common_GateWay_DCT3_0xA6_DCT3_0xA6
#  define Rte_IsUpdated_Common_GateWay_DCT3_0xA6_DCT3_0xA6() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT3_0xA6_DCT3_0xA6_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT5_0x221_DCT5_0x221 Rte_IsUpdated_Common_GateWay_DCT5_0x221_DCT5_0x221
#  define Rte_IsUpdated_Common_GateWay_DCT5_0x221_DCT5_0x221() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DCT5_0x221_DCT5_0x221_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT7_0x235_DCT7_0x235 Rte_IsUpdated_Common_GateWay_DCT7_0x235_DCT7_0x235
#  define Rte_IsUpdated_Common_GateWay_DCT7_0x235_DCT7_0x235() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DDCM1_0x2CA_DDCM1_0x2CA Rte_IsUpdated_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA
#  define Rte_IsUpdated_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DDCM1_0x2CA_DDCM1_0x2CA_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DHT_FD1_0xC1_DHT_FD1_0xC1 Rte_IsUpdated_Common_GateWay_DHT_FD1_0xC1_DHT_FD1_0xC1
#  define Rte_IsUpdated_Common_GateWay_DHT_FD1_0xC1_DHT_FD1_0xC1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DMS_FD1_0x24D_DMS_FD1_0x24D Rte_IsUpdated_Common_GateWay_DMS_FD1_0x24D_DMS_FD1_0x24D
#  define Rte_IsUpdated_Common_GateWay_DMS_FD1_0x24D_DMS_FD1_0x24D() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DSM1_0x2C1_DSM1_0x2C1 Rte_IsUpdated_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1
#  define Rte_IsUpdated_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_DSM1_0x2C1_DSM1_0x2C1_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM11_0x2D3_ECM11_0x2D3 Rte_IsUpdated_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3
#  define Rte_IsUpdated_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM11_0x2D3_ECM11_0x2D3_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM1_0x111_ECM1_0x111 Rte_IsUpdated_Common_GateWay_ECM1_0x111_ECM1_0x111
#  define Rte_IsUpdated_Common_GateWay_ECM1_0x111_ECM1_0x111() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM1_0x111_ECM1_0x111_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM2_0x271_ECM2_0x271 Rte_IsUpdated_Common_GateWay_ECM2_0x271_ECM2_0x271
#  define Rte_IsUpdated_Common_GateWay_ECM2_0x271_ECM2_0x271() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM2_0x271_ECM2_0x271_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM3_0x371_ECM3_0x371 Rte_IsUpdated_Common_GateWay_ECM3_0x371_ECM3_0x371
#  define Rte_IsUpdated_Common_GateWay_ECM3_0x371_ECM3_0x371() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ECM3_0x371_ECM3_0x371_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM_PT7_0x117_ECM_PT7_0x117 Rte_IsUpdated_Common_GateWay_ECM_PT7_0x117_ECM_PT7_0x117
#  define Rte_IsUpdated_Common_GateWay_ECM_PT7_0x117_ECM_PT7_0x117() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EEM1_0x2A8_EEM1_0x2A8 Rte_IsUpdated_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8
#  define Rte_IsUpdated_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EEM1_0x2A8_EEM1_0x2A8_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ELD1_0x152_ELD1_0x152 Rte_IsUpdated_Common_GateWay_ELD1_0x152_ELD1_0x152
#  define Rte_IsUpdated_Common_GateWay_ELD1_0x152_ELD1_0x152() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EPB1_0x16B_EPB1_0x16B Rte_IsUpdated_Common_GateWay_EPB1_0x16B_EPB1_0x16B
#  define Rte_IsUpdated_Common_GateWay_EPB1_0x16B_EPB1_0x16B() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPB1_0x16B_EPB1_0x16B_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EPS1_0x168_EPS1_0x168 Rte_IsUpdated_Common_GateWay_EPS1_0x168_EPS1_0x168
#  define Rte_IsUpdated_Common_GateWay_EPS1_0x168_EPS1_0x168() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EPS_FD1_0x147_EPS_FD1_0x147 Rte_IsUpdated_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147
#  define Rte_IsUpdated_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_EPS_FD1_0x147_EPS_FD1_0x147_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESCL2_0x303_ESCL2_0x303 Rte_IsUpdated_Common_GateWay_ESCL2_0x303_ESCL2_0x303
#  define Rte_IsUpdated_Common_GateWay_ESCL2_0x303_ESCL2_0x303() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP10_0xD8_ESP10_0xD8 Rte_IsUpdated_Common_GateWay_ESP10_0xD8_ESP10_0xD8
#  define Rte_IsUpdated_Common_GateWay_ESP10_0xD8_ESP10_0xD8() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP11_0xC8_ESP11_0xC8 Rte_IsUpdated_Common_GateWay_ESP11_0xC8_ESP11_0xC8
#  define Rte_IsUpdated_Common_GateWay_ESP11_0xC8_ESP11_0xC8() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP11_0xC8_ESP11_0xC8_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP1_0x149_ESP1_0x149 Rte_IsUpdated_Common_GateWay_ESP1_0x149_ESP1_0x149
#  define Rte_IsUpdated_Common_GateWay_ESP1_0x149_ESP1_0x149() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP2_0x145_ESP2_0x145 Rte_IsUpdated_Common_GateWay_ESP2_0x145_ESP2_0x145
#  define Rte_IsUpdated_Common_GateWay_ESP2_0x145_ESP2_0x145() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP8_0x170_ESP8_0x170 Rte_IsUpdated_Common_GateWay_ESP8_0x170_ESP8_0x170
#  define Rte_IsUpdated_Common_GateWay_ESP8_0x170_ESP8_0x170() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP8_0x170_ESP8_0x170_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP_FD2_0x137_ESP_FD2_0x137 Rte_IsUpdated_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137
#  define Rte_IsUpdated_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_ESP_FD2_0x137_ESP_FD2_0x137_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FPAS1_0x26D_FPAS1_0x26D Rte_IsUpdated_Common_GateWay_FPAS1_0x26D_FPAS1_0x26D
#  define Rte_IsUpdated_Common_GateWay_FPAS1_0x26D_FPAS1_0x26D() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_F_PBox1_0x19B_F_PBox1_0x19B Rte_IsUpdated_Common_GateWay_F_PBox1_0x19B_F_PBox1_0x19B
#  define Rte_IsUpdated_Common_GateWay_F_PBox1_0x19B_F_PBox1_0x19B() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_GW_FD1_0x2BB_GW_FD1_0x2BB Rte_IsUpdated_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB
#  define Rte_IsUpdated_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_GW_FD1_0x2BB_GW_FD1_0x2BB_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HAP_FD1_0x15B_HAP_FD1_0x15B Rte_IsUpdated_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B
#  define Rte_IsUpdated_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD1_0x15B_HAP_FD1_0x15B_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HAP_FD2_0x274_HAP_FD2_0x274 Rte_IsUpdated_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274
#  define Rte_IsUpdated_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD2_0x274_HAP_FD2_0x274_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HAP_FD3_0x298_HAP_FD3_0x298 Rte_IsUpdated_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298
#  define Rte_IsUpdated_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HAP_FD3_0x298_HAP_FD3_0x298_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HAP_FD6_0x289_HAP_FD6_0x289 Rte_IsUpdated_Common_GateWay_HAP_FD6_0x289_HAP_FD6_0x289
#  define Rte_IsUpdated_Common_GateWay_HAP_FD6_0x289_HAP_FD6_0x289() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HAP_FD7_0x29B_HAP_FD7_0x29B Rte_IsUpdated_Common_GateWay_HAP_FD7_0x29B_HAP_FD7_0x29B
#  define Rte_IsUpdated_Common_GateWay_HAP_FD7_0x29B_HAP_FD7_0x29B() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HC1_0x287_HC1_0x287 Rte_IsUpdated_Common_GateWay_HC1_0x287_HC1_0x287
#  define Rte_IsUpdated_Common_GateWay_HC1_0x287_HC1_0x287() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCM_L1_0x308_HCM_L1_0x308 Rte_IsUpdated_Common_GateWay_HCM_L1_0x308_HCM_L1_0x308
#  define Rte_IsUpdated_Common_GateWay_HCM_L1_0x308_HCM_L1_0x308() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCM_R1_0x30D_HCM_R1_0x30D Rte_IsUpdated_Common_GateWay_HCM_R1_0x30D_HCM_R1_0x30D
#  define Rte_IsUpdated_Common_GateWay_HCM_R1_0x30D_HCM_R1_0x30D() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_FD1_0x60_HCU_FD1_0x60 Rte_IsUpdated_Common_GateWay_HCU_FD1_0x60_HCU_FD1_0x60
#  define Rte_IsUpdated_Common_GateWay_HCU_FD1_0x60_HCU_FD1_0x60() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_HC3_0x268_HCU_HC3_0x268 Rte_IsUpdated_Common_GateWay_HCU_HC3_0x268_HCU_HC3_0x268
#  define Rte_IsUpdated_Common_GateWay_HCU_HC3_0x268_HCU_HC3_0x268() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_HC6_0x314_HCU_HC6_0x314 Rte_IsUpdated_Common_GateWay_HCU_HC6_0x314_HCU_HC6_0x314
#  define Rte_IsUpdated_Common_GateWay_HCU_HC6_0x314_HCU_HC6_0x314() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_HC7_0x3C2_HCU_HC7_0x3C2 Rte_IsUpdated_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2
#  define Rte_IsUpdated_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_HC7_0x3C2_HCU_HC7_0x3C2_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_HP5_0x201_HCU_HP5_0x201 Rte_IsUpdated_Common_GateWay_HCU_HP5_0x201_HCU_HP5_0x201
#  define Rte_IsUpdated_Common_GateWay_HCU_HP5_0x201_HCU_HP5_0x201() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_HP6_0x11A_HCU_HP6_0x11A Rte_IsUpdated_Common_GateWay_HCU_HP6_0x11A_HCU_HP6_0x11A
#  define Rte_IsUpdated_Common_GateWay_HCU_HP6_0x11A_HCU_HP6_0x11A() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_PT4_0x2FA_HCU_PT4_0x2FA Rte_IsUpdated_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA
#  define Rte_IsUpdated_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT4_0x2FA_HCU_PT4_0x2FA_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_PT5_0x14A_HCU_PT5_0x14A Rte_IsUpdated_Common_GateWay_HCU_PT5_0x14A_HCU_PT5_0x14A
#  define Rte_IsUpdated_Common_GateWay_HCU_PT5_0x14A_HCU_PT5_0x14A() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_PT7_0x248_HCU_PT7_0x248 Rte_IsUpdated_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248
#  define Rte_IsUpdated_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HCU_PT7_0x248_HCU_PT7_0x248_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_PT8_0x1C0_HCU_PT8_0x1C0 Rte_IsUpdated_Common_GateWay_HCU_PT8_0x1C0_HCU_PT8_0x1C0
#  define Rte_IsUpdated_Common_GateWay_HCU_PT8_0x1C0_HCU_PT8_0x1C0() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HUD1_0x325_HUD1_0x325 Rte_IsUpdated_Common_GateWay_HUD1_0x325_HUD1_0x325
#  define Rte_IsUpdated_Common_GateWay_HUD1_0x325_HUD1_0x325() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_HUD1_0x325_HUD1_0x325_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Haldex1_0x251_Haldex1_0x251 Rte_IsUpdated_Common_GateWay_Haldex1_0x251_Haldex1_0x251
#  define Rte_IsUpdated_Common_GateWay_Haldex1_0x251_Haldex1_0x251() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_IFC_FD2_0x23D_IFC_FD2_0x23D Rte_IsUpdated_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D
#  define Rte_IsUpdated_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD2_0x23D_IFC_FD2_0x23D_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_IFC_FD3_0x2CF_IFC_FD3_0x2CF Rte_IsUpdated_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF
#  define Rte_IsUpdated_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_IFC_FD3_0x2CF_IFC_FD3_0x2CF_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_IFC_FD5_0x19F_IFC_FD5_0x19F Rte_IsUpdated_Common_GateWay_IFC_FD5_0x19F_IFC_FD5_0x19F
#  define Rte_IsUpdated_Common_GateWay_IFC_FD5_0x19F_IFC_FD5_0x19F() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_IFC_FD6_0x222_IFC_FD6_0x222 Rte_IsUpdated_Common_GateWay_IFC_FD6_0x222_IFC_FD6_0x222
#  define Rte_IsUpdated_Common_GateWay_IFC_FD6_0x222_IFC_FD6_0x222() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_OBC1_0x316_OBC1_0x316 Rte_IsUpdated_Common_GateWay_OBC1_0x316_OBC1_0x316
#  define Rte_IsUpdated_Common_GateWay_OBC1_0x316_OBC1_0x316() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_OBC2_0x317_OBC2_0x317 Rte_IsUpdated_Common_GateWay_OBC2_0x317_OBC2_0x317
#  define Rte_IsUpdated_Common_GateWay_OBC2_0x317_OBC2_0x317() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PDCM1_0x2CD_PDCM1_0x2CD Rte_IsUpdated_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD
#  define Rte_IsUpdated_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PDCM1_0x2CD_PDCM1_0x2CD_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PEPS2_0x295_PEPS2_0x295 Rte_IsUpdated_Common_GateWay_PEPS2_0x295_PEPS2_0x295
#  define Rte_IsUpdated_Common_GateWay_PEPS2_0x295_PEPS2_0x295() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS2_0x295_PEPS2_0x295_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PEPS4_0x302_PEPS4_0x302 Rte_IsUpdated_Common_GateWay_PEPS4_0x302_PEPS4_0x302
#  define Rte_IsUpdated_Common_GateWay_PEPS4_0x302_PEPS4_0x302() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_PEPS4_0x302_PEPS4_0x302_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PLG_1_0x2FE_PLG_1_0x2FE Rte_IsUpdated_Common_GateWay_PLG_1_0x2FE_PLG_1_0x2FE
#  define Rte_IsUpdated_Common_GateWay_PLG_1_0x2FE_PLG_1_0x2FE() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS1_0x26E_RPAS1_0x26E Rte_IsUpdated_Common_GateWay_RPAS1_0x26E_RPAS1_0x26E
#  define Rte_IsUpdated_Common_GateWay_RPAS1_0x26E_RPAS1_0x26E() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS2_0x2ED_RPAS2_0x2ED Rte_IsUpdated_Common_GateWay_RPAS2_0x2ED_RPAS2_0x2ED
#  define Rte_IsUpdated_Common_GateWay_RPAS2_0x2ED_RPAS2_0x2ED() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RSDS_FD1_0x16F_RSDS_FD1_0x16F Rte_IsUpdated_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F
#  define Rte_IsUpdated_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD1_0x16F_RSDS_FD1_0x16F_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RSDS_FD2_0x30A_RSDS_FD2_0x30A Rte_IsUpdated_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A
#  define Rte_IsUpdated_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_RSDS_FD2_0x30A_RSDS_FD2_0x30A_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_R_PBox1_0x19C_R_PBox1_0x19C Rte_IsUpdated_Common_GateWay_R_PBox1_0x19C_R_PBox1_0x19C
#  define Rte_IsUpdated_Common_GateWay_R_PBox1_0x19C_R_PBox1_0x19C() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SCM1_0x2D1_SCM1_0x2D1 Rte_IsUpdated_Common_GateWay_SCM1_0x2D1_SCM1_0x2D1
#  define Rte_IsUpdated_Common_GateWay_SCM1_0x2D1_SCM1_0x2D1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2 Rte_IsUpdated_Common_GateWay_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2
#  define Rte_IsUpdated_Common_GateWay_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2 Rte_IsUpdated_Common_GateWay_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2
#  define Rte_IsUpdated_Common_GateWay_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2 Rte_IsUpdated_Common_GateWay_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2
#  define Rte_IsUpdated_Common_GateWay_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2 Rte_IsUpdated_Common_GateWay_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2
#  define Rte_IsUpdated_Common_GateWay_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2 Rte_IsUpdated_Common_GateWay_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2
#  define Rte_IsUpdated_Common_GateWay_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9 Rte_IsUpdated_Common_GateWay_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9
#  define Rte_IsUpdated_Common_GateWay_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TPMS2_0x395_TPMS2_0x395 Rte_IsUpdated_Common_GateWay_TPMS2_0x395_TPMS2_0x395
#  define Rte_IsUpdated_Common_GateWay_TPMS2_0x395_TPMS2_0x395() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395 != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_TPMS2_0x395_TPMS2_0x395_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_T_Box_FD1_0x33_T_Box_FD1_0x33 Rte_IsUpdated_Common_GateWay_T_Box_FD1_0x33_T_Box_FD1_0x33
#  define Rte_IsUpdated_Common_GateWay_T_Box_FD1_0x33_T_Box_FD1_0x33() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_VSG1_0x2E1_VSG1_0x2E1 Rte_IsUpdated_Common_GateWay_VSG1_0x2E1_VSG1_0x2E1
#  define Rte_IsUpdated_Common_GateWay_VSG1_0x2E1_VSG1_0x2E1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_WPC1_0x2BA_WPC1_0x2BA Rte_IsUpdated_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA
#  define Rte_IsUpdated_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA != Rte_OsApplication_Trust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_GateWay_WPC1_0x2BA_WPC1_0x2BA_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AWakeHold_DVRRemtCnSts Rte_Write_Common_GateWay_AWakeHold_DVRRemtCnSts
#  define Rte_Write_Common_GateWay_AWakeHold_DVRRemtCnSts(data) (Rte_Common_GateWay_AWakeHold_DVRRemtCnSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_AwakeHlod_Heartbeat_counter Rte_Write_Common_GateWay_AwakeHlod_Heartbeat_counter
#  define Rte_Write_Common_GateWay_AwakeHlod_Heartbeat_counter(data) (Rte_Common_GateWay_AwakeHlod_Heartbeat_counter = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT10_0x331_HUT10_0x331 Rte_Write_Common_GateWay_HUT10_0x331_HUT10_0x331
#  define Rte_Write_HUT13_0x31C_HUT13_0x31C Rte_Write_Common_GateWay_HUT13_0x31C_HUT13_0x31C
#  define Rte_Write_HUT15_0x1EE_HUT15_0x1EE Rte_Write_Common_GateWay_HUT15_0x1EE_HUT15_0x1EE
#  define Rte_Write_HUT16_0x348_HUT16_0x348 Rte_Write_Common_GateWay_HUT16_0x348_HUT16_0x348
#  define Rte_Write_HUT17_0x33B_HUT17_0x33B Rte_Write_Common_GateWay_HUT17_0x33B_HUT17_0x33B
#  define Rte_Write_HUT19_0x415_HUT19_0x415 Rte_Write_Common_GateWay_HUT19_0x415_HUT19_0x415
#  define Rte_Write_HUT1_0x367_HUT1_0x367 Rte_Write_Common_GateWay_HUT1_0x367_HUT1_0x367
#  define Rte_Write_HUT20_0x2DE_HUT20_0x2DE Rte_Write_Common_GateWay_HUT20_0x2DE_HUT20_0x2DE
#  define Rte_Write_HUT21_0x2DD_HUT21_0x2DD Rte_Write_Common_GateWay_HUT21_0x2DD_HUT21_0x2DD
#  define Rte_Write_HUT22_0x2DA_HUT22_0x2DA Rte_Write_Common_GateWay_HUT22_0x2DA_HUT22_0x2DA
#  define Rte_Write_HUT23_0x2D8_HUT23_0x2D8 Rte_Write_Common_GateWay_HUT23_0x2D8_HUT23_0x2D8
#  define Rte_Write_HUT25_0x339_HUT25_0x339 Rte_Write_Common_GateWay_HUT25_0x339_HUT25_0x339
#  define Rte_Write_HUT26_0x2B6_HUT26_0x2B6 Rte_Write_Common_GateWay_HUT26_0x2B6_HUT26_0x2B6
#  define Rte_Write_Common_GateWay_HUT26_0x2B6_HUT26_0x2B6(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT2_0x369_HUT2_0x369 Rte_Write_Common_GateWay_HUT2_0x369_HUT2_0x369
#  define Rte_Write_HUT30_0x1E9_HUT30_0x1E9 Rte_Write_Common_GateWay_HUT30_0x1E9_HUT30_0x1E9
#  define Rte_Write_HUT32_0x26F_HUT32_0x26F Rte_Write_Common_GateWay_HUT32_0x26F_HUT32_0x26F
#  define Rte_Write_HUT33_0x1ED_HUT33_0x1ED Rte_Write_Common_GateWay_HUT33_0x1ED_HUT33_0x1ED
#  define Rte_Write_HUT34_0x370_HUT34_0x370 Rte_Write_Common_GateWay_HUT34_0x370_HUT34_0x370
#  define Rte_Write_HUT35_0x1E5_HUT35_0x1E5 Rte_Write_Common_GateWay_HUT35_0x1E5_HUT35_0x1E5
#  define Rte_Write_HUT39_0x1EB_HUT39_0x1EB Rte_Write_Common_GateWay_HUT39_0x1EB_HUT39_0x1EB
#  define Rte_Write_HUT3_0x36B_HUT3_0x36B Rte_Write_Common_GateWay_HUT3_0x36B_HUT3_0x36B
#  define Rte_Write_HUT40_0x2CE_HUT40_0x2CE Rte_Write_Common_GateWay_HUT40_0x2CE_HUT40_0x2CE
#  define Rte_Write_Common_GateWay_HUT40_0x2CE_HUT40_0x2CE(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT4_0x36D_HUT4_0x36D Rte_Write_Common_GateWay_HUT4_0x36D_HUT4_0x36D
#  define Rte_Write_HUT6_0x4A_HUT6_0x4A Rte_Write_Common_GateWay_HUT6_0x4A_HUT6_0x4A
#  define Rte_Write_HUT_FD1_0x2C3_HUT_FD1_0x2C3 Rte_Write_Common_GateWay_HUT_FD1_0x2C3_HUT_FD1_0x2C3
#  define Rte_Write_HUT_FD4_0x1DA_HUT_FD4_0x1DA Rte_Write_Common_GateWay_HUT_FD4_0x1DA_HUT_FD4_0x1DA
#  define Rte_Write_Common_GateWay_HUT_FD4_0x1DA_HUT_FD4_0x1DA(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT_IP1_0x293_HUT_IP1_0x293 Rte_Write_Common_GateWay_HUT_IP1_0x293_HUT_IP1_0x293
#  define Rte_Write_Common_GateWay_HUT_IP1_0x293_HUT_IP1_0x293(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT_IP2_0x27F_HUT_IP2_0x27F Rte_Write_Common_GateWay_HUT_IP2_0x27F_HUT_IP2_0x27F
#  define Rte_Write_Common_GateWay_HUT_IP2_0x27F_HUT_IP2_0x27F(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_HUT_IP3_0x34A_HUT_IP3_0x34A Rte_Write_Common_GateWay_HUT_IP3_0x34A_HUT_IP3_0x34A
#  define Rte_Write_Common_GateWay_HUT_IP3_0x34A_HUT_IP3_0x34A(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_AvgFuelCons_IP_AvgFuelCons Rte_Write_Common_GateWay_IP_AvgFuelCons_IP_AvgFuelCons
#  define Rte_Write_Common_GateWay_IP_AvgFuelCons_IP_AvgFuelCons(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_CurrTheme_IP_CurrTheme Rte_Write_Common_GateWay_IP_CurrTheme_IP_CurrTheme
#  define Rte_Write_Common_GateWay_IP_CurrTheme_IP_CurrTheme(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_FuelAuxTankR_IP_FuelAuxTankR Rte_Write_Common_GateWay_IP_FuelAuxTankR_IP_FuelAuxTankR
#  define Rte_Write_Common_GateWay_IP_FuelAuxTankR_IP_FuelAuxTankR(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_FuelMainTankR_IP_FuelMainTankR Rte_Write_Common_GateWay_IP_FuelMainTankR_IP_FuelMainTankR
#  define Rte_Write_Common_GateWay_IP_FuelMainTankR_IP_FuelMainTankR(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_InstFuelCons_IP_InstFuelCons Rte_Write_Common_GateWay_IP_InstFuelCons_IP_InstFuelCons
#  define Rte_Write_Common_GateWay_IP_InstFuelCons_IP_InstFuelCons(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_InstFuelConsUnit_IP_InstFuelConsUnit Rte_Write_Common_GateWay_IP_InstFuelConsUnit_IP_InstFuelConsUnit
#  define Rte_Write_Common_GateWay_IP_InstFuelConsUnit_IP_InstFuelConsUnit(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_LagueSet_IP_LagueSet Rte_Write_Common_GateWay_IP_LagueSet_IP_LagueSet
#  define Rte_Write_Common_GateWay_IP_LagueSet_IP_LagueSet(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_RemainDistance_IP_RemainDistance Rte_Write_Common_GateWay_IP_RemainDistance_IP_RemainDistance
#  define Rte_Write_Common_GateWay_IP_RemainDistance_IP_RemainDistance(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_VehSpdDisp_IP_VehSpdDisp Rte_Write_Common_GateWay_IP_VehSpdDisp_IP_VehSpdDisp
#  define Rte_Write_Common_GateWay_IP_VehSpdDisp_IP_VehSpdDisp(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_IP_VelSpdDisp_Mile_IP_VelSpdDisp_Mile Rte_Write_Common_GateWay_IP_VelSpdDisp_Mile_IP_VelSpdDisp_Mile
#  define Rte_Write_Common_GateWay_IP_VelSpdDisp_Mile_IP_VelSpdDisp_Mile(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SG_HUT32_SG_HUT32 Rte_Write_Common_GateWay_SG_HUT32_SG_HUT32
#  define Rte_Write_Common_GateWay_SG_HUT32_SG_HUT32(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SG_HUT_IP2_SG_HUT_IP2 Rte_Write_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2
#  define Rte_Write_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_SocReadyFlag_Element Rte_Write_Common_GateWay_SocReadyFlag_Element
#  define Rte_Write_Common_GateWay_SocReadyFlag_Element(data) (Rte_Common_GateWay_SocReadyFlag_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCGateWay_EnergyInfoId_Data Rte_Write_Common_GateWay_ppSR_SWCGateWay_EnergyInfoId_Data
#  define Rte_Write_ppSR_SWCGateWay_S2M_Information_SpeedValue Rte_Write_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue
#  define Rte_Write_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue(data) (Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCGateWay_S2M_Information_TachoValue Rte_Write_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue
#  define Rte_Write_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue(data) (Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CNA_SignalGroupSet_Operation Rte_Call_Common_GateWay_CNA_SignalGroupSet_Operation
#  define Rte_Call_CNA_SignalSet_Operation Rte_Call_Common_GateWay_CNA_SignalSet_Operation
#  define Rte_Call_IPC_DataSend_If_Operation Rte_Call_Common_GateWay_IPC_DataSend_If_Operation
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock Rte_Call_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define Rte_Call_rpCS_AppClearDTCInfo_AppClearDTCInfo Rte_Call_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
#  define Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
#  define Rte_Call_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
#  define Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal Rte_Call_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
#  define Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
#  define Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
#  define Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
#  define Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation Rte_Call_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
#  define Rte_Call_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar Rte_Call_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetMaxComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetMaxComMode(arg1) (ComM_GetMaxComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetRequestedComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_GetRequestedComMode(arg1) (ComM_GetRequestedComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComM_UserRequest_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)48)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)48, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)48)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)48, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)48, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)47)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)47, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)47)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)47, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)47, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_SAFETY_APPL_CODE) svCS_SWCSafety_ReceiveSafetyGearCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCGateWay_ReceiveSafetyGearCRC_Callback(arg1) (svCS_SWCSafety_ReceiveSafetyGearCRC_Callback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_SAFETY_APPL_CODE) svCS_SWCSafety_ReceiveSafetyTTCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCGateWay_ReceiveSafetyTTCRC_Callback(arg1) (svCS_SWCSafety_ReceiveSafetyTTCRC_Callback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_ChimeCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCNormal_ChimeCallback_Operation(arg1) (svCS_SWCNormal_ChimeCallback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_HMIResetTC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCNormal_HMIResetTC_Callback(arg1) (svCS_SWCNormal_HMIResetTC_Callback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_ReceiveMenuSetting_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCNormal_ReceiveMenuSetting_Callback(arg1) (svCS_SWCNormal_ReceiveMenuSetting_Callback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_rcCS_SWCNormal_ReceiveOffroadInfo_Callback Rte_Call_Common_GateWay_rcCS_SWCNormal_ReceiveOffroadInfo_Callback
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCNormal_TTCallback_Operation(arg1) (svCS_SWCNormal_TTCallback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_WrnCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_SWCNormal_WrnCallback_Operation(arg1) (svCS_SWCNormal_WrnCallback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_SOCDTCPROCESS_APPL_CODE) PpCS_AppReadDtcInfomation_AppReadDtcInformation(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) DtcInfo); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_AppReadDtcInfomation_AppReadDtcInformation(arg1) (PpCS_AppReadDtcInfomation_AppReadDtcInformation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_DIDDATAPROCESS_APPL_CODE) GetCANMatrixVersionInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_GetCANMatrixVersionInfo_Data(arg1) (GetCANMatrixVersionInfo_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_DIDDATAPROCESS_APPL_CODE) GetVehicleModeInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_GetVehicleModeInfo_Data(arg1) (GetVehicleModeInfo_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_rpCS_SWCGateWay_AdasStatus_Callback Rte_Call_Common_GateWay_rpCS_SWCGateWay_AdasStatus_Callback
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_DIDDATAPROCESS_APPL_CODE) AppGetVinNumberFunction(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_GetVinNumber_Operation(arg1) (AppGetVinNumberFunction(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback
#  define Rte_Call_rpCS_SWCGateWay_ReceiveMenuTheme_Callback Rte_Call_Common_GateWay_rpCS_SWCGateWay_ReceiveMenuTheme_Callback
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_ReceiveSafetyGearCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_ReceiveSafetyGearCRC_Callback(arg1) (svCS_SWCNormal_ReceiveSafetyGearCRCCallback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_SWCNormal_ReceiveSafetyTTCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_ReceiveSafetyTTCRC_Callback(arg1) (svCS_SWCNormal_ReceiveSafetyTTCRCCallback(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) TC_EnergyInfo(EnergyInfoDataType Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_TC_EnergyInfo_Operation(arg1, arg2) (TC_EnergyInfo(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) TC_EnergyInfoResp(EnergyInfoDataType Id, boolean Resp); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCGateWay_TC_EnergyInfoResp_Operation(arg1, arg2) (TC_EnergyInfoResp(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_rpCS_SWCGateWay_TtToChime_Callback Rte_Call_Common_GateWay_rpCS_SWCGateWay_TtToChime_Callback
#  define RTE_START_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_SAFETY_APPL_CODE) svCS_SWCSafety_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_SAFETY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCSafety_TTCallback_Operation(arg1) (svCS_SWCSafety_TTCallback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(NVM_IPC_CAN_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue;
extern CONST(IPC_Config_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue() (&(Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue() (&Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_IPC_Config_Data_DefaultValue() (&(Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_IPC_Config_Data_DefaultValue() (&Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(NVM_IPC_CAN_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock;
extern VAR(IPC_Config_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock() RtePim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock() \
  (&Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock() RtePim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock() \
  (&Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Common_GateWay_START_SEC_CODE
# include "Common_GateWay_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Common_GW_List_Deinit Common_GW_List_Deinit
#  define RTE_RUNNABLE_Common_GW_List_Int Common_GW_List_Int
#  define RTE_RUNNABLE_Common_GateWay_10msMainFunction Common_GateWay_10msMainFunction
#  define RTE_RUNNABLE_Common_GateWay_5msMainFunction Common_GateWay_5msMainFunction
#  define RTE_RUNNABLE_Common_GateWay_Init Common_GateWay_Init
#  define RTE_RUNNABLE_Common_GateWay_Nomal2Standby_Callbcak Common_GateWay_Nomal2Standby_Callbcak
#  define RTE_RUNNABLE_Common_GateWay_Standby2Nomal_Callbcak Common_GateWay_Standby2Nomal_Callbcak
#  define RTE_RUNNABLE_IPC_API_SetEventTxSignalBuffer_Operation IPC_API_SetEventTxSignalBuffer_Operation
#  define RTE_RUNNABLE_IPC_Send_IPC_Send IPC_Send_IPC_Send
#  define RTE_RUNNABLE_IPC_TransmitSignal_Callback IPC_TransmitSignal_Callback
#  define RTE_RUNNABLE_IPC_Tx_E2E_CanMsg_HUT32_CallBack IPC_Tx_E2E_CanMsg_HUT32_CallBack
#  define RTE_RUNNABLE_IPC_Tx_E2E_CanMsg_HUT_IP2_Callback IPC_Tx_E2E_CanMsg_HUT_IP2_Callback
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished
#  define RTE_RUNNABLE_ppCS_SWCNormal_Callback_Operation ppCS_SWCNormal_Callback_Operation
# endif

FUNC(void, Common_GateWay_CODE) Common_GW_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) Common_GW_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) Common_GateWay_10msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_GateWay_CODE) Common_GateWay_5msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_GateWay_CODE) Common_GateWay_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_GateWay_CODE) Common_GateWay_Nomal2Standby_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) Common_GateWay_Standby2Nomal_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_GateWay_CODE) IPC_Send_IPC_Send(uint8 Id_u8, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data_s, uint16 len_u16, boolean Imm_bool); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) IPC_TransmitSignal_Callback(uint32 SignalIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) IPC_Tx_E2E_CanMsg_HUT32_CallBack(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_GateWay_CODE) ppCS_SWCNormal_Callback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Common_GateWay_STOP_SEC_CODE
# include "Common_GateWay_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CNA_SignalGroupSet_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSet_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSetNoTrigger_Std_ReturnType (1U)

#  define RTE_E_CNA_SignalSet_U8N_Std_ReturnType (1U)

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_IPC_DataSend_If_E_N_OK (1U)

#  define RTE_E_IPC_Send_Std_ReturnType (1U)

#  define RTE_E_IRTC_Service_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_Defs_E_NOT_OK (1U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_GATEWAY_H */

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
