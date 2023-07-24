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
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Power.c
 *           Config:  D:/Code_Project/Vector35_09_23/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Power
 *  Generation Time:  2020-09-23 11:24:01
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Power>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * AntitheftSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BswM_BswMRteShutdownReqMode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CURRENT_GEAR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ComM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DrvDoorLockSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * DrvDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * HUD_SwtSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LvPwrSysErr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Stat_PwrSv_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SysPowerMod
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SysPowerModVld
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TranPMode_Sts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * wakeup_type
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *
 * Operation Prototypes:
 * =====================
 * GetCounterValue of Port Interface Os_Service
 *   This service reads the current count value of a counter (returning either the hardware timer ticks if counter is driven by hardware or the software ticks when user drives counter).
 *
 * GetElapsedValue of Port Interface Os_Service
 *   This service gets the number of ticks between the current tick value and a previously read tick value.
 *
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 *********************************************************************************************************************/

#include "Rte_Power.h"



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "StateMachine.h"
#include "SystemState_SP_Condition.h"
#include "SystemState_Conditon_Element.h"
#include "logger_cfg.h"
#include "logger.h"
#include "Power.h"
#include "Rte_Power.h"
#include "Power_Temp_Monitor.h"
#include "Power_Volt_Monitor.h"
#include "Power_OutMgr.h"
#include "Icu.h"
#include "IoHwAb_Cfg_RI.h"
#include "Rte_Dcm_Type.h"
#include "AMP_ShutDown.h"
#include "Ext_Power.h"
#include "Rte_Type.h"
#include "CanIf.h"
#include "CanSM.h"

#include "Misc_Board.h"
#include "Mcu_Types.h"
#define POWER_DTCRESTMCU_WAITTIMER                      (20u)/*100ms*/
#define POWER_DTCOVERTEMP_WAITTIMER                     (20u)/*100ms*/

#define POWER_DTCOVERTEMP_TRIG_CNT                      (30)
#define POWER_DTCOVERTEMP_RECOVER_CNT                   (10)

#define POWER_DTCTEMPFAULT_TRIG_CNT                      (30)
#define POWER_DTCTEMPFAULT_RECOVER_CNT                   (10)


#define POWER_NETWORK_INIT                              (0u)
#define POWER_NETWORK_FULLCOM                           (1u)
#define POWER_NETWORK_NOCOMLESS1S                       (2u)
#define POWER_NETWORK_NOCOM1S                           (3u)
#define POWER_NETWORKDEBOUNCETIME                       (200u)/*1s*/
#define POWER_LOWPOWERLIMITDEBOUNCETIME                 (100u)/*0.5s*/
#define POWER_LOWPOWERLIMIT_VOLT                        (600) /* 6v */
#define POWER_LOWPOWERRECOVER_VOLT                      (620) /* 6.2v */


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void Power_StartupLogicDebounceNM(void);
static uint8 Power_NetWorkDebounce(void);
static void Power_LVI_Monitor(void);
static Std_ReturnType Power_DTCReqRestMCU(const uint8 *DTCReset);
static void Power_GateWay(void);
static void PowerGateWay_WakeupSource(void);
static void PowerGateWay_ResetType(void);
//static void Power_StartupFullComLogic(void);
static void Power_LowPowerLimitMain(void);
static void Power_USBCtrl(void);
static void Power_RVCCtrl(void);
static void Power_DTCOverTemperature(void);
static void Power_CommunicationEnable_Check(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


#define POWER_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Power_MemMap.h"


//uint32 SystemStateAPPOffRequestTimer = 0u;

extern s_PowerOut_t Power_OutDataCurrent;
static uint8 PowerStartupVoltageBackup = POWER_VOLTAGE_NORMAL;
//static uint8 PowerStartupTempBackup = POWER_TEMP_NORMAL;

static uint8 Power_DTCRestMCU;
static boolean EcumRunBackup;
static uint16 Power_NMDebounceTimer = 0u;
static wakeup_type WakeupSourcePre;
static reset_type  ResetReasonPre;

// V35-14250 
static boolean bLowPowerLimitState = FALSE;
static uint16  u16LowPowerLimitCnt = 0u;
static boolean bLowPowerLimitExe   = FALSE;
//static boolean bLowPowerLimitBackup = FALSE;

static uint16  u16OverTemperaturePeriod = 0;
static uint16  u16OverTemperatureCnt = 0;
static boolean bOverTemperaturetrigger = 0;
static boolean bOverTemperatureIsReady = FALSE;


static uint16  u16TemperatureFaultCnt = 0;
static boolean bTemperatureFaultTrigger = 0;
static boolean bTemperatureFaultIsReady = FALSE;
static uint8   PowerVolEnablePre = POWER_VOLTAGE_NORMAL;

typedef struct
{
  Mcu_ResetType resetType;
  char * logPrintf;
}POWER_OutputResetResonPrintf_t;
static const POWER_OutputResetResonPrintf_t tPOWER_OutputResetResonPrintf_Table[MCU_RESET_UNKNOWN]=
{
	{MCU_SW_RESET,					"MCU_SW_RESET"},
	{MCU_WATCHDOG0_RESET,			"MCU_WATCHDOG0_RESET"},
	{MCU_WATCHDOG1_RESET,			"MCU_WATCHDOG1_RESET"},
	{MCU_CLM0_RESET,				"MCU_CLM0_RESET"},
	{MCU_CLM1_RESET,				"MCU_CLM1_RESET"},
	/*MCU_CLM2_RESET for F1K and F1KM_S4, MCU_CLM3_RESET for F1KM_S1*/
	{MCU_CLM2_RESET,				"MCU_CLM2_RESET"},
	{MCU_LVI_RESET,					"MCU_LVI_RESET"},
	{MCU_CVM_RESET,					"MCU_CVM_RESET"},
	{MCU_TERMINAL_RESET,			"MCU_TERMINAL_RESET"},
	{MCU_POWER_ON_RESET,			"MCU_POWER_ON_RESET"},
	{MCU_ISO_RESET,					"MCU_ISO_RESET"},
#ifdef MCU_WDG2_RESET_ENABLE
	{MCU_WATCHDOG2_RESET,			"MCU_WATCHDOG2_RESET"},
#endif /* MCU_WDG2_RESET_ENABLE */
	{MCU_RESF11_RESET,				"MCU_RESF11_RESET"},
	{MCU_RESF12_RESET,				"MCU_RESF12_RESET"},
	{MCU_RESF13_RESET,				"MCU_RESF13_RESET"},
	{MCU_CLM3_RESET,				"MCU_CLM3_RESET"},
	{MCU_RESET_UNDEFINED,			"MCU_RESET_UNDEFINED"},
	{MCU_MULTIPLE_RESETS_OCCURED,	"MCU_MULTIPLE_RESETS_OCCURED"},
	{MCU_RESET_UNKNOWN,				"MCU_RESET_UNKNOWN"},
};
	

#define POWER_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Power_MemMap.h"



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_s_PowerOut_t_0: Integer in interval [0...255]
 * Rte_DT_s_PowerOut_t_1: Integer in interval [0...65535]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AntitheftSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disarmed (0U)
 *   Cx1_Armed (1U)
 *   Cx2_Prearmed (2U)
 *   Cx3_Alarmed (3U)
 * BswM_BswMRteShutdownReqMode: Enumeration of integer in interval [0...255] with enumerators
 *   BswMReqSleep (1U)
 *   BswMReqShutdown (3U)
 *   BswMReqShutdownEmergency (4U)
 *   BswMReqNone (0U)
 *   BswMReqSleepEmergency (5U)
 * CURRENT_GEAR: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Current_gear_N_or_P_ (0U)
 *   Cx1_Current_gear_1_ (1U)
 *   Cx2_Current_gear_2_ (2U)
 *   Cx3_Current_gear_3_ (3U)
 *   Cx4_Current_gear_4_ (4U)
 *   Cx5_Current_gear_5_ (5U)
 *   Cx6_Current_gear_6_ (6U)
 *   Cx7_Current_gear_7_ (7U)
 *   Cx8_Current_gear_R_ (8U)
 *   Cx9_Reserved (9U)
 *   CxF_Reserved (15U)
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 *   DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
 *   DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
 *   DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
 *   DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
 * DrvDoorLockSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Lock (0U)
 *   Cx1_Unlock (1U)
 * DrvDoorSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * HUD_SwtSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 * LvPwrSysErr: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_error (0U)
 *   Cx1_error (1U)
 *   Cx2_Reservrd (2U)
 *   Cx3_Reservrd (3U)
 * Rte_DT_SystemState_RecordType_0: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_Cluster_OFF (0U)
 *   SYSTEMSTATE_Cluster_STANDBY (1U)
 *   SYSTEMSTATE_Cluster_ON (2U)
 *   SYSTEMSTATE_Cluster_STARTUP (3U)
 *   SYSTEMSTATE_Cluster_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_1: Enumeration of integer in interval [0.0...255] with enumerators
 *   SYSTEMSTATE_IVI_OFF (0U)
 *   SYSTEMSTATE_IVI_STANDBY (1U)
 *   SYSTEMSTATE_IVI_ON (2U)
 *   SYSTEMSTATE_IVI_SHUTDOWN (3U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (4U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (7U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (8U)
 * Rte_DT_SystemState_RecordType_2: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_HUD_OFF (0U)
 *   SYSTEMSTATE_HUD_STANDBY (1U)
 *   SYSTEMSTATE_HUD_ON (2U)
 *   SYSTEMSTATE_HUD_STARTUP (3U)
 *   SYSTEMSTATE_HUD_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_3: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_CONSOLE_OFF (0U)
 *   SYSTEMSTATE_CONSOLE_STANDBY (1U)
 *   SYSTEMSTATE_CONSOLE_ON (2U)
 *   SYSTEMSTATE_CONSOLE_STARTUP (3U)
 *   SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_4: Enumeration of integer in interval [0...255] with enumerators
 *   KL15OFF (0U)
 *   KL15ON (1U)
 * Rte_DT_SystemState_RecordType_5_0: Enumeration of integer in interval [0...255] with enumerators
 *   VOLTAGE_OUT_LOWSLEEP (0U)
 *   VOLTAGE_OUT_NORMAL (1U)
 *   VOLTAGE_OUT_HIGHALARM (2U)
 *   VOLTAGE_OUT_HIGHSLEEP (3U)
 *   VOLTAGE_OUT_LOWALARM (4U)
 *   VOLTAGE_OUT_NUM (5U)
 * Rte_DT_SystemState_RecordType_6: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_SP_OFF (0U)
 *   SYSTEMSTATE_SP_SHUTDOWN (1U)
 *   SYSTEMSTATE_SP_STANDBY (2U)
 *   SYSTEMSTATE_SP_SOCOFF (3U)
 * Stat_PwrSv_Lvl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Level_1 (1U)
 *   Cx2_Level_2 (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * SysPowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ACC_reserved_ (1U)
 *   Cx2_ON (2U)
 *   Cx3_Crank (3U)
 * SysPowerModVld: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 * TranPMode_Sts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_Mode (0U)
 *   Cx1_Transport_Mode (1U)
 * reset_type: Enumeration of integer in interval [0...255] with enumerators
 *   McuRstRsnConfClm0 (4U)
 *   McuRstRsnConfClm1 (5U)
 *   McuRstRsnConfClm2 (6U)
 *   McuRstRsnConfClm3 (15U)
 *   McuRstRsnConfCvm (8U)
 *   McuRstRsnConfIso (11U)
 *   McuRstRsnConfLvi (7U)
 *   McuRstRsnConfMultipleResets (17U)
 *   McuRstRsnConfPOR (10U)
 *   McuRstRsnConfResf11 (12U)
 *   McuRstRsnConfResf12 (13U)
 *   McuRstRsnConfResf13 (14U)
 *   McuRstRsnConfSwRst (1U)
 *   McuRstRsnConfTer (9U)
 *   McuRstRsnConfUndef (16U)
 *   McuRstRsnConfUnknown (18U)
 *   McuRstRsnConfWdta0 (2U)
 *   McuRstRsnConfWdta1 (3U)
 *   init (0U)
 * wakeup_type: Enumeration of integer in interval [0...18446744073709551615] with enumerators
 *   value0 (0U)
 *   bit1 (1U)
 *   bit2 (2U)
 *
 * Record Types:
 * =============
 * EOL_Struct_3Element: Record with elements
 *   MCUTemperature of type uint8
 *   AMP1Temperature of type uint8
 *   AMP2Temperature of type uint8
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 * s_PowerOut_t: Record with elements
 *   state of type Rte_DT_s_PowerOut_t_0
 *   value of type Rte_DT_s_PowerOut_t_1
 *
 *********************************************************************************************************************/


#define Power_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Power_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AntitheftSts_AntitheftSts(AntitheftSts *data)
 *   Std_ReturnType Rte_Read_CURRENT_GEAR_CURRENT_GEAR(CURRENT_GEAR *data)
 *   Std_ReturnType Rte_Read_DrvDoorLockSts_DrvDoorLockSts(DrvDoorLockSts *data)
 *   Std_ReturnType Rte_Read_DrvDoorSts_DrvDoorSts(DrvDoorSts *data)
 *   Std_ReturnType Rte_Read_Ecum_Set_SystemState_Run_Element(boolean *data)
 *   Std_ReturnType Rte_Read_HUD_SwtSts_HUD_SwtSts(HUD_SwtSts *data)
 *   Std_ReturnType Rte_Read_LvPwrSysErr_LvPwrSysErr(LvPwrSysErr *data)
 *   Std_ReturnType Rte_Read_Rc_BswM_Warm_Reset_Element(boolean *data)
 *   Std_ReturnType Rte_Read_Rc_Cluster_Shutdown_Status_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_ResetReason_ResetSource(reset_type *data)
 *   Std_ReturnType Rte_Read_Rc_Wakeup_Reason_WakeupSource(wakeup_type *data)
 *   Std_ReturnType Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(Stat_PwrSv_Lvl *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_SysPowerModVld_SysPowerModVld(SysPowerModVld *data)
 *   Std_ReturnType Rte_Read_TranPMode_Sts_TranPMode_Sts(TranPMode_Sts *data)
 *   Std_ReturnType Rte_Read_rpSR_AMPDeInitFinished_State(boolean *data)
 *   Std_ReturnType Rte_Read_rpSR_GyroDeInitFinished_State(boolean *data)
 *   Std_ReturnType Rte_Read_rpSR_RtcDeInitFinished_State(boolean *data)
 *   Std_ReturnType Rte_Read_rpSR_SocManager_SystemState(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Ecum_Set_SystemState_Run_Element(boolean data)
 *   Std_ReturnType Rte_Write_IVI_10MIN_Backup_flag_Element(uint8 data)
 *   Std_ReturnType Rte_Write_Request_PowerModeEmergencySleep_requestedMode(BswM_BswMRteShutdownReqMode data)
 *   Std_ReturnType Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswM_BswMRteShutdownReqMode data)
 *   Std_ReturnType Rte_Write_Sd_BswM_Warm_Reset_Element(boolean data)
 *   Std_ReturnType Rte_Write_Sd_Cluster_Shutdown_Status_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_Power_Out_SystemStateOut(const SystemState_RecordType *data)
 *   Std_ReturnType Rte_Write_ppSR_WakeupReason_data(wakeup_type data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_DcmEcuReset_DcmEcuReset(void)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Common_GW_List_Deinit(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Common_GW_List_Int(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Common_Normal_List_Deinit(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Common_Normal_List_Int(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Common_SF_List_Deinit(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Common_SF_List_Int(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Gyro_Init_server_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IPC_Init_Server_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rtc_Init_server_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetCurrentComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetMaxComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetRequestedComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTCD10016_UnderVoltage_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTCD10016_UnderVoltage_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTCD10017_OverVoltage_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTCD10017_OverVoltage_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_SystemState_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Power_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


FUNC(void, AMP_CODE) EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(P2VAR(EOL_Struct_3Element, AUTOMATIC, RTE_AMP_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17
 *********************************************************************************************************************/
    Power_TempEOL_Get_MCUAMP_Temperature(arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


FUNC(void, Power_CODE) Power_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Power_MainFunction
 *********************************************************************************************************************/
    Std_ReturnType DCMReqRestRet;
    uint8 DCMReset;

    Rte_Call_WdgM_AliveSupervision_SystemState_CheckpointReached(0);

    Power_LVI_Monitor();

    DCMReset = Rte_Mode_Power_DcmEcuReset_DcmEcuReset();

    DCMReqRestRet = Power_DTCReqRestMCU(&DCMReset);
    if(E_OK == DCMReqRestRet)
    {
        AMP_Emergency_Shutdown();
        Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0);
        (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqShutdown);
        power_warn("DCM Request MCU Reset  \r\n");
    }
    else
    {
        Power_Volt_Mgr();
        Power_TempMonitor();
        SystemState_ElementFunc();
        Power_CommunicationEnable_Check();
        
        if(FALSE == Sm_SP.enabled)
        {
            boolean EcumRun = (boolean)0;
            uint32 AD_data = 0u;
            Std_ReturnType Volt_Ret = E_NOT_OK;
            //Std_ReturnType Temp_Ret = E_NOT_OK;
            Rte_Read_Power_Ecum_Set_SystemState_Run_Element(&EcumRun);
            Volt_Ret = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VBATT_VIP_DET_ADC, &AD_data);
            //Temp_Ret = Power_TempColltect();
            if((EcumRunBackup != EcumRun) && ((boolean)0 != EcumRun))
            {
                (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqNone);
            }
            EcumRunBackup = EcumRun;
            if((E_OK == Volt_Ret) && ((boolean)0 != EcumRun))
            {
                Power_StartupLogicDebounceNM();
            }
        }
        SystemState_SP_MainFunc();
        SystemState_OutMain();
    }

    Power_GateWay();
    Power_LowPowerLimitMain();
    Power_USBCtrl();
    Power_RVCCtrl();
    Power_DTCOverTemperature();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: power_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: power_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Power_CODE) power_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: power_Init
 *********************************************************************************************************************/
    Power_DTCRestMCU = 0u;
    EcumRunBackup = (boolean)0u;
    WakeupSourcePre = ECUM_WKSOURCE_NONE;
    ResetReasonPre = 0;

    Power_TempInit();
    Power_Volt_Init();
    SystemState_ElementInit();

    SystemState_SPInit();
    SystemState_OutInit();
    //PowerGateWay_ResetType();

    u16OverTemperaturePeriod = 0;
    u16OverTemperatureCnt = 0;
    bOverTemperaturetrigger = (boolean)0;

    power_warn("Power_Init finished\r\n");


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Power_STOP_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    static void Power_LVI_Monitor(void)
    {
        if (/*level low,lvi happens*/ ICU_LOW == Icu_GetInputLevel(IcuConf_IcuChannel_VIP_LVI_IDL))
        {
            (void)Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode(BswMReqSleepEmergency);
            power_err("Power Request Emency Sleep as LVI happen");
        }
    }


    static uint8 Power_NetWorkDebounce(void)
    {
        uint8 ret = POWER_NETWORK_INIT;
        Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
        
        if(SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState)
        {
            ret = POWER_NETWORK_FULLCOM;
        }
        else
        {
            if(Power_NMDebounceTimer <= POWER_NETWORKDEBOUNCETIME)
            {
                ret = POWER_NETWORK_NOCOMLESS1S;
            }
            else
            {
                ret =  POWER_NETWORK_NOCOM1S;
            }
        }
        return ret;
    }
    
static void Power_StartupLogicDebounceNM(void)
{
    uint8 NMSts = POWER_NETWORK_INIT;
    NMSts = Power_NetWorkDebounce();

    if(POWER_NETWORK_NOCOM1S == NMSts)
    {
        Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0);
        (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqSleep);
        power_warn("Power Startup NOCom>1S,Sleep");
        Power_NMDebounceTimer = 0u;
    }
    else if(POWER_NETWORK_FULLCOM == NMSts)
    {
        uint8 Power_VoltageFlg = Power_VoltageStateFlg();
        if(POWER_VOLTAGE_NORMAL == Power_VoltageFlg)
        {   
            if(POWER_VOLTAGE_NORMAL == PowerStartupVoltageBackup)
            {
                SM_EnabledSet(&Sm_SP, TRUE);
                PowerStartupVoltageBackup = POWER_VOLTAGE_NORMAL;
                
                (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( 0x00 ), CANIF_SET_TX_ONLINE );
                power_warn("Power SP RUN");
            }
            else
            {
                Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0);
                (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqShutdown);

                power_err("fullcom&vol->normal,shutdown");
                PowerStartupVoltageBackup = POWER_VOLTAGE_NORMAL;
            }
        }
        else
        {
            PowerStartupVoltageBackup = POWER_VOLTAGE_ABNORMAL;
            if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER1S))
            {
                power_debug("fulcom&volabnormal,wait normal");
            }
        }
        
        Power_NMDebounceTimer = 0u;
    }
    else
    {
        Power_NMDebounceTimer ++;

        if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER200MS))
        {
            power_warn("got BSW Req,Wait fullcom");
        }
    }
}


static Std_ReturnType Power_DTCReqRestMCU(const uint8 *DTCReset)
{
    Std_ReturnType ret = E_OK;
    if(Power_DTCRestMCU > 0u)
    {
        Power_DTCRestMCU ++;
        if(POWER_DTCRESTMCU_WAITTIMER == Power_DTCRestMCU)
        {
            
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        if((RTE_MODE_Dcm_DcmEcuReset_SOFT == *DTCReset) ||\
            (RTE_MODE_Dcm_DcmEcuReset_HARD == *DTCReset))
        {
            Power_DTCRestMCU ++;
			
			if(RTE_MODE_Dcm_DcmEcuReset_HARD == *DTCReset)
			{
				cold_reset_req = DIAG_REQ_COLD_RESET;
				init_process_finish = INIT_PROCESS_NOT_FINISHED;
			}
			else
			{
				cold_reset_req = DIAG_REQ_WARM_RESET;
			}

        }
        else
        {
            Power_DTCRestMCU = 0u;
        }
        ret = E_NOT_OK;
    }
    return ret;
}



static void Power_GateWay(void)
{
    PowerGateWay_WakeupSource();
}


static void PowerGateWay_WakeupSource(void)
{
    
    wakeup_type WakeupSource = ECUM_WKSOURCE_NONE;
    reset_type ResetReason = 0,i=0;
    /*detail define in EcuM_Generated_Types.h*/
    (void)Rte_Read_Rc_ResetReason_ResetSource(&ResetReason);
    (void)Rte_Read_Rc_Wakeup_Reason_WakeupSource(&WakeupSource);
    (void)Rte_Write_Power_ppSR_WakeupReason_data(WakeupSource);
    
    if(WakeupSourcePre != WakeupSource)
    {
        power_warn("Wakeup resouce:%ld",(uint32)WakeupSource);
    }

    if (ResetReasonPre != ResetReason)
    {
		for(i=0;i<MCU_RESET_UNKNOWN;i++)
		{
			if(ResetReason == tPOWER_OutputResetResonPrintf_Table[i].resetType)
			{
				power_warn("Reset Reason:%d=%s",ResetReason,tPOWER_OutputResetResonPrintf_Table[i].logPrintf);
				break;
			}
		}
    }

    ResetReasonPre = ResetReason;
    WakeupSourcePre = WakeupSource;
}

/*
static void Power_StartupFullComLogic(void)
{
    uint8 Power_VoltageFlg      = Power_VoltageStateFlg();
    uint8 Power_TempetureFlg    = Power_TempStateRTUFlg();
    if((POWER_VOLTAGE_NORMAL == Power_VoltageFlg) &&(POWER_TEMP_NORMAL == Power_TempetureFlg))
    {   
        if((POWER_VOLTAGE_NORMAL == PowerStartupVoltageBackup) && (POWER_TEMP_NORMAL == PowerStartupTempBackup))
        {
            SM_EnabledSet(&Sm_SP, TRUE);
            PowerStartupVoltageBackup = POWER_VOLTAGE_NORMAL;
            PowerStartupTempBackup    = POWER_TEMP_NORMAL;
            power_info("Power Fill MCU RUN comdition, MCU statemachine RUN!!");
        }
        else
        {
            Rte_Write_Power_Ecum_Set_SystemState_Run_Element((boolean)0);
            (void)Rte_Write_Request_PowerModeShutdownReq_requestedMode(BswMReqShutdown);

            if(POWER_VOLTAGE_NORMAL != PowerStartupVoltageBackup)
            {
                power_warn("MCU StateMachine now Not Run as voltage not fill SRD, Now Voltage recover so requeset shutdown");
            }
            if(POWER_TEMP_NORMAL != PowerStartupTempBackup)
            {
                power_warn("MCU StateMachine now Not Run as voltage not fill SRD, Now Temp recover so requeset shutdown");
            }
            PowerStartupVoltageBackup = POWER_VOLTAGE_NORMAL;
            PowerStartupTempBackup = POWER_TEMP_NORMAL;
        }
    }
    else
    {
        PowerStartupVoltageBackup = Power_VoltageFlg;
        PowerStartupTempBackup = Power_TempetureFlg;
        if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER1S))
        {
            if(POWER_VOLTAGE_ABNORMAL == Power_VoltageFlg)
            {
                power_warn("Fullcommunication, but voltage not satisfied, wait no communication or voltage recover");
            }
            if(POWER_TEMP_ABNORMAL == Power_TempetureFlg)
            {
                power_warn("Fullcommunication, but tempeture not satisfied, wait no communication or tempeture recover");
            }
        }
    }
}
*/
/***********************************************************************
 * @brief       : SRS:V35-14250
 * @param       : 
 * @retval      : 
 ***********************************************************************/




static void Power_LowPowerLimitMain(void)
{
    boolean limit_state;


    limit_state = bLowPowerLimitState;

    if (bLowPowerLimitState != 0)
    {
        if (Power_OutDataCurrent.value >= POWER_LOWPOWERRECOVER_VOLT)
        {
            limit_state = FALSE;
        }
    }
    else
    {
        if (Power_OutDataCurrent.value <= POWER_LOWPOWERLIMIT_VOLT)
        {
            limit_state = TRUE;
        }
    }

    // Power Limit Debounce
    if (limit_state != bLowPowerLimitState)
    {
        u16LowPowerLimitCnt++;
        if (u16LowPowerLimitCnt > POWER_LOWPOWERLIMITDEBOUNCETIME)
        {
            bLowPowerLimitState = limit_state;
            u16LowPowerLimitCnt = 0u;
        }
    }
    else
    {
        u16LowPowerLimitCnt = 0u;
    }

    if (bLowPowerLimitState == FALSE)
    {

        if (bLowPowerLimitExe != bLowPowerLimitState)
        {
            power_warn("Low Power Limit:OFF");
        }
        bLowPowerLimitExe = FALSE;
    }
    else if (Power_OutDataCurrent.state == VOLTAGE_OUT_LOWALARM)
    {
        
        if (bLowPowerLimitExe != bLowPowerLimitState)
        {
            power_warn("Low Power Limit:ON");
        }
        bLowPowerLimitExe = TRUE;
    }

    
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_USBCtrl(void)
{
    s_TempOut_t Temp_PA;
    uint8   s_VIP_HW_Version;
    (void)Power_TempOut(&Temp_PA);
	Misc_Board_GetHwVersion(&s_VIP_HW_Version);
	//eMiscBoard_Version_C2 support fast charge:Power IC Was MPQ4228GRE-C-AEC1-Z
	if(TRUE == EXT_USBWasFastCharge())
	{
		//refs old logic and discussion with nisuo(GW00241699)
		//VIP_USB1_CTRL1 was set higt at sys power up
		if ((bLowPowerLimitExe == TRUE) || (Temp_PA.State == TEMP_HIGH_SLEEP) || (Temp_PA.State == TEMP_LOW_SLEEP))//low BAT or TEMP up 108??
		{
			POWER_OFF_MPQ4228GRE();//set VIP_USB1_EN -> low
			POWER_OFF_MPQ4228GRE_CTRL1();////set VIP_USB1_CTRL1 -> low
			POWER_OFF_MPQ4228GRE_CTRL2();////set VIP_USB1_CTRL2 -> low
		}
		else if (Temp_PA.State == TEMP_HIGH_PROTECT)//93??~110??  MPQ4228GRE not support SDP , use CDP 
		{
			POWER_ON_MPQ4228GRE();//set VIP_USB1_EN -> high
			POWER_ON_MPQ4228GRE_CTRL1();////set VIP_USB1_CTRL1 -> high
			POWER_OFF_MPQ4228GRE_CTRL2();////set VIP_USB1_CTRL2 -> low
		}
		else//CDP
		{
			POWER_ON_MPQ4228GRE();//set VIP_USB1_EN -> high
			POWER_ON_MPQ4228GRE_CTRL1();////set VIP_USB1_CTRL1 -> high
			POWER_OFF_MPQ4228GRE_CTRL2();////set VIP_USB1_CTRL2 -> low
		}
	}
	//eMiscBoard_Version_C3 don't support fast charge:Power IC Was	MPQ9841GLE-AEC1-Z + MPQ5073GG-AEC1-Z + MAX25400GTC/V
	else if(TRUE == EXT_USBWasLowCharge())
	{
		//refs old logic and discussion with nisuo(GW00241699)
		if ((bLowPowerLimitExe == TRUE) || (Temp_PA.State == TEMP_HIGH_SLEEP) || (Temp_PA.State == TEMP_LOW_SLEEP))//low BAT or TEMP up 108??
		{
			POWER_OFF_MPQ5073GG();//set VIP_USB1_CTRL2 -> low
			POWER_OFF_MPQ9841GLE();//set VIP_USB1_EN -> low
		}
		else if (Temp_PA.State == TEMP_HIGH_PROTECT)//93??~110??
		{
			//at C3 this case not need care , no SDP mode , hold as normal
			POWER_ON_MPQ9841GLE();//set VIP_USB1_EN -> high
			POWER_ON_MPQ5073GG();//set VIP_USB1_CTRL2 -> high
		}
		else//CDP
		{
			POWER_ON_MPQ9841GLE();//set VIP_USB1_EN -> high
			POWER_ON_MPQ5073GG();//set VIP_USB1_CTRL2 -> high
		}
	}
	else
	{
	    if ((bLowPowerLimitExe == TRUE) || (Temp_PA.State == TEMP_HIGH_SLEEP) || (Temp_PA.State == TEMP_LOW_SLEEP))//low BAT or TEMP up 108??
	    {
	        POWER_SET_USB_DIS();//set VIP_USB1_EN -> low
	    }
	    else if (Temp_PA.State == TEMP_HIGH_PROTECT)//93??~110??
	    {
	        POWER_SET_USB_SDP();//set VIP_USB1_CTRL2 -> low , slow charge
	        POWER_SET_USB_EN();//set VIP_USB1_EN -> high
	    }
	    else
	    {
	        POWER_SET_USB_CDP();//set VIP_USB1_CTRL2 -> high , fast charge
	        POWER_SET_USB_EN();//set VIP_USB1_EN -> high
	    }
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_RVCCtrl(void)
{
    if (bLowPowerLimitExe == TRUE)
    {
        POWER_SET_RVC_DIS();
    }
    else
    {
        POWER_SET_RVC_EN();
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/



static void Power_DTCOverTemperature(void)
{
    s_TempOut_t Temp_PA;
    Std_ReturnType ret;
    boolean overTemp = FALSE;

    if (u16OverTemperaturePeriod >= POWER_DTCOVERTEMP_WAITTIMER)
    {
        u16OverTemperaturePeriod = 0;

        ret = Power_TempOut(&Temp_PA);

        // Over temp 
        if (ret == E_OK)
        {
            if (Temp_PA.State == TEMP_HIGH_SLEEP)
            {
                overTemp = TRUE;
            }
            
            if ((bOverTemperaturetrigger != overTemp)||(bOverTemperatureIsReady == FALSE))
            {
                u16OverTemperatureCnt++;
                

                if ((bOverTemperatureIsReady == FALSE)&&(bOverTemperaturetrigger != overTemp))
                {
                    bOverTemperaturetrigger = overTemp;
                    u16OverTemperatureCnt = 0;
                }
                else if ((overTemp == TRUE) && (u16OverTemperatureCnt >= POWER_DTCOVERTEMP_TRIG_CNT))
                {
                    bOverTemperaturetrigger = TRUE;
                    u16OverTemperatureCnt = 0;
                    bOverTemperatureIsReady = TRUE;
                    dtc_err("B12764B-Over Temperature.");
                }
                else if ((overTemp == FALSE) && (u16OverTemperatureCnt >= POWER_DTCOVERTEMP_RECOVER_CNT))
                {
                    bOverTemperaturetrigger = FALSE;
                    u16OverTemperatureCnt = 0;
                    bOverTemperatureIsReady = TRUE;
                }
            }
            else 
            {
                u16OverTemperatureCnt = 0;
            }
        }
        else 
        {
            bOverTemperaturetrigger = FALSE;
            u16OverTemperatureCnt = 0;
        }

        // temp fault
        if (ret == E_OK)
        {
            if ((bTemperatureFaultTrigger != Temp_PA.bTempFault) || (bTemperatureFaultIsReady == FALSE))
            {
                u16TemperatureFaultCnt++;

                if ((bTemperatureFaultIsReady == FALSE)&&(bTemperatureFaultTrigger != Temp_PA.bTempFault))
                {
                    u16TemperatureFaultCnt = 0;
                    bTemperatureFaultTrigger = Temp_PA.bTempFault;
                }
                else if ((Temp_PA.bTempFault == TRUE) && (u16TemperatureFaultCnt >= POWER_DTCTEMPFAULT_TRIG_CNT))
                {
                    bTemperatureFaultTrigger = TRUE;
                    u16TemperatureFaultCnt = 0;
                    bTemperatureFaultIsReady = TRUE;
                   
                }
                else if ((Temp_PA.bTempFault == FALSE) && (u16TemperatureFaultCnt >= POWER_DTCTEMPFAULT_RECOVER_CNT))
                {
                    bTemperatureFaultTrigger = FALSE;
                    u16TemperatureFaultCnt = 0;
                    bTemperatureFaultIsReady = TRUE;
                }
            }
            else 
            {
                u16TemperatureFaultCnt = 0;
            }
        }
        else 
        {
            bTemperatureFaultTrigger = FALSE;
            u16TemperatureFaultCnt = 0;
        }

        if (bOverTemperatureIsReady == TRUE)
        {
            if (bOverTemperaturetrigger == FALSE)
            {
                Rte_Call_DTCB12764B_OverTemperature_SetEventStatus(DEM_EVENT_STATUS_PASSED);
            }
            else 
            {
                Rte_Call_DTCB12764B_OverTemperature_SetEventStatus(DEM_EVENT_STATUS_FAILED);
            }
        }

        if (bTemperatureFaultIsReady == TRUE)
        {
            if (bTemperatureFaultTrigger == FALSE)
            {
                Rte_Call_DiagnosticMonitor_Temperature_SensorError_SetEventStatus(DEM_EVENT_STATUS_PASSED);
            }
            else 
            {
                Rte_Call_DiagnosticMonitor_Temperature_SensorError_SetEventStatus(DEM_EVENT_STATUS_FAILED);
            }
        }



    }
    else 
    {
        u16OverTemperaturePeriod++;
    }
}


static void PowerGateWay_ResetType(void)
{
    boolean WramRest;
    (void)Rte_Read_Rc_BswM_Warm_Reset_Element(&WramRest);
    (void)Rte_Write_Sd_BswM_Warm_Reset_Element(WramRest);

	if(TRUE == WramRest)
	{
		power_warn("System Warm Reset!");
	}
	else
	{
		power_warn("System Cold Reset!");
	}
}

void PowerPre_Init(void)
{

	PowerGateWay_ResetType();

}

static void Power_CommunicationEnable_Check(void)
{
    uint8 Power_VoltageFlg = Power_VoltageStateFlg();
    
    if(POWER_VOLTAGE_NORMAL == Power_VoltageFlg)
    {   
        if(POWER_VOLTAGE_NORMAL == PowerVolEnablePre)
        {
            Rte_Write_Request_PowerVolEnable_requestedMode(Vol_Enable);
        }
        else
        {
            PowerVolEnablePre = POWER_VOLTAGE_NORMAL;
        }
    }

}



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
