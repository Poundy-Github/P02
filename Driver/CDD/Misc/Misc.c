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
 *             File:  Misc.c
 *           Config:  D:/tanjinyi/working/WorkSpace_V35Platform/WorkSpace_Dev/VIP_P05/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Misc
 *  Generation Time:  2021-08-23 10:35:34
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Misc>
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
 * ComEx_SignalIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * WdgM_GlobalStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WdgM_LocalStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * GlobalStatusCallback of Port Interface WdgM_GlobalStatusCallback
 *   Callback function that will be invoked if the global supervision status has changed.
 *
 * LocalStatusCallback of Port Interface WdgM_LocalStatusCallback
 *   Callback function that will be invoked if the local supervision status has changed.
 *
 *********************************************************************************************************************/

#include "Rte_Misc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Ext_Power.h"
#include "CDD_Test.h"
#include "IPC_Misc.h"

#include "Misc_IPC_Service.h"
#include "Misc_IPC_IVIInfo.h"
#include "RTC.h"
#include "CPULoadMeasure.h"
#include "StackMeasure.h"
#include "Misc_Diag.h"
#include "Misc_Board.h"
#include "fls.h"
#include "nvm.h"
#include "fee_30_smallsector.h"
#include "VersionCfg.h"
#include "MPQ2022.h"

#if (defined(GWM_V35_PROJECT_TYPE_B03))
#else
#include "ComEx_Cfg.h"
#endif

//#define NVM_WRITE_DEFAULT

#ifdef NVM_WRITE_DEFAULT
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

uint8 nvm_write_default;
extern CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS];

#endif 

#define LOG_CYCLE_PERIOD  (5U)
#define LOG_TIMER_COUNT_100MS     (100U/LOG_CYCLE_PERIOD)

//gear value
#define GearMdl_GEAR_P                  (0U)
#define GearMdl_GEAR_R                  (1U)
#define GearMdl_GEAR_N                  (2U)
#define GearMdl_GEAR_D                  (3U)

//gear status
#define GearMdl_GEAR_NO_SHOW            (0U)
#define GearMdl_GEAR_NO_FLASH           (1U)
#define GearMdl_GEAR_1HZ_FLASH          (2U)
#define GearMdl_GEAR_0_5HZ_FLASH        (3U)

#define SYS_POWER_MOD_ON                    (2U)
#define SYS_POWER_MOD_VLD                   (1U)

#define IVI_12MINS                          (uint32)((60000/5)*12)
#define TIMER_NOT_START                     (0xFFFFFFFFul)
#define TRANSPORT_3S                        (uint16)((1000/5)*3)

#define PIN_LOW  ((boolean)0)
#define PIN_HIGH ((boolean)1)

static uint8 IVI_10mins_Pre = 0;
static uint32 IVI_10mins_Counter = TIMER_NOT_START;
static uint16 Transport_Mode_Counter = 0;




void MISC_IVI_10mins_Backup(void);

static void RVC_Request(void);

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
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 * DrvGearDisp: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Neutral (0U)
 *   Cx1_E_Gear (1U)
 *   Cx2_L_Gear (2U)
 *   Cx3_M_Gear (3U)
 *   Cx4_H_Gear (4U)
 *   Cx5_S_Gear (5U)
 *   Cx6_X_Gear (6U)
 *   Cx7_Reserved (7U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
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
 *   SYSTEMSTATE_IVI_REMOTE (4U)
 *   SYSTEMSTATE_IVI_DEMO (5U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (8U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (9U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (10U)
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
 * Rte_DT_SystemState_RecordType_7_0: Enumeration of integer in interval [0...255] with enumerators
 *   TEMP_LOW_SLEEP (0U)
 *   TEMP_NORMAL (1U)
 *   TEMP_HIGH_PROTECT (2U)
 *   TEMP_HIGH_SLEEP (3U)
 *   TEMP_STATE_NUM (4U)
 *   TEMP_STATE_INIT (255U)
 * WdgM_GlobalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_GLOBAL_STATUS_OK (0U)
 *   WDGM_GLOBAL_STATUS_FAILED (1U)
 *   WDGM_GLOBAL_STATUS_EXPIRED (2U)
 *   WDGM_GLOBAL_STATUS_STOPPED (3U)
 *   WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_LOCAL_STATUS_OK (0U)
 *   WDGM_LOCAL_STATUS_FAILED (1U)
 *   WDGM_LOCAL_STATUS_EXPIRED (2U)
 *   WDGM_LOCAL_STATUS_DEACTIVATED (4U)
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
 *
 * Array Types:
 * ============
 * A_1Bytes: Array with 1 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * EOL3Bytes: Array with 3 element(s) of type uint8
 * EOL_2Bytes: Array with 2 element(s) of type Rte_DT_EOL_2Bytes_0
 * EOL_3Bytes: Array with 3 element(s) of type Rte_DT_EOL_3Bytes_0
 * EOL_4Bytes: Array with 4 element(s) of type Rte_DT_EOL_4Bytes_0
 * EOL_64Bytes: Array with 64 element(s) of type Rte_DT_EOL_64Bytes_0
 * NvmResetInformation_t: Array with 63 element(s) of type uint8
 * Rte_DT_EOL_2Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_3Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_4Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_EOL_64Bytes_0: Array with 1 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_ResetInfomation_MirrorBlock(void)
 *     Returnvalue: uint8* is of type NvmResetInformation_t
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_ResetInfomation_DefaultValue(void)
 *     Returnvalue: uint8* is of type NvmResetInformation_t
 *
 *********************************************************************************************************************/


#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_0xFD16_EOL_FactoryReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_FactoryReset> of PortPrototype <EOL_0xFD16>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rc_ResetReason_ResetSource(reset_type *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_0xFD16_EOL_FactoryReset(uint8 *arg)
 *     Argument arg: uint8* is of type A_1Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFD16_EOL_FactoryReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) EOL_0xFD16_EOL_FactoryReset(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFD16_EOL_FactoryReset
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_0xFDD1_EOL_ReadMICStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_ReadMICStatus> of PortPrototype <EOL_0xFDD1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_0xFDD1_EOL_ReadMICStatus(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_3Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDD1_EOL_ReadMICStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) EOL_0xFDD1_EOL_ReadMICStatus(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDD1_EOL_ReadMICStatus
 *********************************************************************************************************************/
    Misc_Diag_EOL_0xFDD1_EOL_ReadMICStatus(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_0xFDD9_EOL_WriteValueForDispalyEnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_WriteValueForDispalyEnable> of PortPrototype <EOL_0xFDD9>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_0xFDD9_EOL_WriteValueForDispalyEnable(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_2Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDD9_EOL_WriteValueForDispalyEnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) EOL_0xFDD9_EOL_WriteValueForDispalyEnable(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDD9_EOL_WriteValueForDispalyEnable
 *********************************************************************************************************************/

    Misc_Diag_EOL_0xFDD9_EOL_WriteValueForDispalyEnable(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_0xFDE1_EOL_ReadWatchDogCnt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_ReadWatchDogCnt> of PortPrototype <EOL_0xFDE1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_0xFDE1_EOL_ReadWatchDogCnt(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_4Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDE1_EOL_ReadWatchDogCnt_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) EOL_0xFDE1_EOL_ReadWatchDogCnt(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDE1_EOL_ReadWatchDogCnt
 *********************************************************************************************************************/

    Misc_Diag_EOL_0xFDE1_EOL_ReadWatchDogCnt(arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_0xFDE2_EOL_ReadResetInformation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_ReadResetInformation> of PortPrototype <EOL_0xFDE2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_0xFDE2_EOL_ReadResetInformation(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_64Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDE2_EOL_ReadResetInformation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) EOL_0xFDE2_EOL_ReadResetInformation(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_0xFDE2_EOL_ReadResetInformation
 *********************************************************************************************************************/
   Misc_Diag_EOL_0xFDE2_EOL_ReadResetInformation(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Misc_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) Misc_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_Init
 *********************************************************************************************************************/
	CDD_Test_Init();
	Misc_Diag_Init();
	MISC_OS_Task_Execution_Init();
	Misc_Board_Init();
    OS_Stack_Usage_Init();
#ifdef VIP_VERSION_STATE
    misc_warn("VIP version: %2x %d.%d.%d",VIP_VERSION_STATE,VIP_VERSION_MAJOR,VIP_VERSION_MID,VIP_VERSION_MINOR);
#endif
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Misc_MainFunction
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
 *   Std_ReturnType Rte_Read_IVI_10MIN_Backup_flag_Element(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(const uint8 *data)
 *     Argument data: uint8* is of type EOL3Bytes
 *   Std_ReturnType Rte_Write_EOL_ReadGPSSatelliteCount_GPSSatelliteCount(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Misc(void)
 *   void Rte_Exit_ExclusiveArea_Misc(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) Misc_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction
 *********************************************************************************************************************/
            
    EXT_Power_Management();
	if(TRUE == Misc_PowerWasMPQ2022())
	{
		MPQ2022_MainFunction(eMPS2022_MIC_GNSS);
		MPQ2022_MainFunction(eMPS2022_ANT1_2);
		if(TRUE == MISC_SYSRVCWasUsed())
		{
			MPQ2022_MainFunction(eMPS2022_RVC);
		}
	}
    
    MISC_IPC_Service_Task();
	Misc_Board_Task();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Misc_MainFunction_100ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter(uint32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rcCS_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM1_OpenCircuit_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM1_OverCurrent_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM1_ShortToBattary_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM1_ShortToGround_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM2_OpenCircuit_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM2_OverCurrent_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM2_ShortToBattary_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_FM2_ShortToGround_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_GNSS_OpenCircuit_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_GNSS_OverCurrent_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_GNSS_ShortToBattary_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_GNSS_ShortToGround_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_1_open_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_1_short_to_BAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_1_short_to_GND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_2_open_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_2_short_to_BAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Mic_2_short_to_GND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_RVC_CamerShortToBattery_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_RVC_CameraOpenCircuit_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_RVC_CameraShortToGround_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_100ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) Misc_MainFunction_100ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_100ms
 *********************************************************************************************************************/
    Misc_Diag_Task();
    CDD_Test_MainFunction();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Misc_MainFunction_500ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 500ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_Misc_DrvGearDisp_Element(DrvGearDisp *data)
 *   Std_ReturnType Rte_Read_rpSR_Misc_GearMsgMiss_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_tiSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_SetPin(uint8 Id, boolean Digital)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_Mics_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_500ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) Misc_MainFunction_500ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_500ms
 *********************************************************************************************************************/
#ifdef NVM_WRITE_DEFAULT
	uint8 nvm_index;

	if(1 == nvm_write_default)
	{
		for(nvm_index = 1; nvm_index < (NVM_TOTAL_NUM_OF_NVRAM_BLOCKS); nvm_index++)
		{
			if((NvM_BlockDescriptorTable_at[nvm_index].RomBlockDataAddr_pt != NULL_PTR) && (NvM_BlockDescriptorTable_at[nvm_index].RamBlockDataAddr_t!= NULL_PTR) )
			{
				memcpy(NvM_BlockDescriptorTable_at[nvm_index].RamBlockDataAddr_t,NvM_BlockDescriptorTable_at[nvm_index].RomBlockDataAddr_pt,NvM_BlockDescriptorTable_at[nvm_index].NvBlockNVRAMDataLength);
				(void)NvM_WriteBlock(nvm_index,NULL_PTR);	
			}
		}

		
		nvm_write_default = 0;
	}

#endif

	RVC_Request();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Misc_MainFunction_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_50ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) Misc_MainFunction_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Misc_MainFunction_50ms
 *********************************************************************************************************************/
    MISC_IPC_IVIInfo_Task();
    
	MISC_OS_Stack_Usage();

	Misc_CPULoad_MainFunction();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NVM_Read_Speedup_Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NVM_Read_Speedup_Runnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) NVM_Read_Speedup_Runnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NVM_Read_Speedup_Runnable
 *********************************************************************************************************************/
	NvM_MainFunction();

	Fee_30_SmallSector_MainFunction();

	Fls_MainFunction();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_GlobalStatusCallback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GlobalStatusCallback> of PortPrototype <WdgM_GlobalStatusCallback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void WdgM_GlobalStatusCallback(WdgM_GlobalStatusType Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GlobalStatusCallback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) WdgM_GlobalStatusCallback(WdgM_GlobalStatusType Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GlobalStatusCallback
 *********************************************************************************************************************/

	power_info("WdgM Global status change to  %d", Status);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_LocalStatusCallback_Gear
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <LocalStatusCallback> of PortPrototype <WdgM_LocalStatusCallback_Gear>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void WdgM_LocalStatusCallback_Gear(WdgM_LocalStatusType Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_Gear_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_Gear(WdgM_LocalStatusType Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_Gear
 *********************************************************************************************************************/
	power_info("Gear module WdgM local status change to  %d", Status);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_LocalStatusCallback_Power
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <LocalStatusCallback> of PortPrototype <WdgM_LocalStatusCallback_Power>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void WdgM_LocalStatusCallback_Power(WdgM_LocalStatusType Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_Power_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_Power(WdgM_LocalStatusType Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_Power
 *********************************************************************************************************************/
	
	power_info("Power module WdgM local status change to  %d", Status);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_LocalStatusCallback_TT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <LocalStatusCallback> of PortPrototype <WdgM_LocalStatusCallback_TT>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void WdgM_LocalStatusCallback_TT(WdgM_LocalStatusType Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_TT_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_TT(WdgM_LocalStatusType Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_LocalStatusCallback_TT
 *********************************************************************************************************************/

	power_info("TT module WdgM local status change to  %d", Status);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void IPC_MISC_Callback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{
        switch(major_msg_id)
        {
            case IPC_S2M_MISC_MSGMAJOR_RTC_ID:
                MISC_IPC_RTC_Callback(sub_msg_id,param,param_len);
                break;
            case IPC_S2M_MISC_MSGMAJOR_SERVICE_ID:
                MISC_IPC_Service_Callback(sub_msg_id,param,param_len);
                break;
            case IPC_S2M_MISC_MSGMAJOR_IVIINFO_ID:
                MISC_IPC_IVIInfo_Callback(sub_msg_id,param,param_len);
                break;
            default:
				/* nothing to do */
                break;
        }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_IVI_10mins_Backup(void)
{
	uint8 IVI_10min_flag;

	
	Rte_Read_Misc_IVI_10MIN_Backup_flag_Element(&IVI_10min_flag);
	if(0 == IVI_10mins_Pre)
	{
		if(IVI_10mins_Pre != IVI_10min_flag)
		{
			/*10mins counter start*/
			IVI_10mins_Counter = IVI_12MINS;
			IVI_10mins_Pre = IVI_10min_flag;
		}
		
 		Transport_Mode_Counter = 0;
	}
	else
	{
		if(IVI_10mins_Pre != IVI_10min_flag)
		{
			/*10mins counter stop*/
			IVI_10mins_Counter = TIMER_NOT_START;
			IVI_10mins_Pre = IVI_10min_flag;
			Transport_Mode_Counter = 0;
		}
		else
		{
			/*read KL_15 state here*/
			/*read driver door state & antitheft here*/
			/*read transport mode here*/

			if(0/*transport mode*/)
			{
				Transport_Mode_Counter++;
			}
			else
			{
				Transport_Mode_Counter = 0;
			}
			
			//if((Transport_Mode_Counter >= TRANSPORT_3S)||0/*KL_15 ON or door open or antithft*/)
			if(Transport_Mode_Counter >= TRANSPORT_3S)
			{
				IVI_10mins_Counter = TIMER_NOT_START;
				IVI_10mins_Pre = 0;
				Transport_Mode_Counter = 0;
				Rte_Power_IVI_10MIN_Backup_flag_Element = 0;
			}	
			else
			{
				/*do nothing*/
			}
		}
	}
	
	if((IVI_10mins_Counter != TIMER_NOT_START) && (IVI_10mins_Counter > 0))
	{
		IVI_10mins_Counter--;
	}
	else if(0 == IVI_10mins_Counter)
	{
		
		/* stop NM communication */
	}
	else
	{
		/*do nothing*/
	}
}

/**
 * @brief reset pin to intterrupt SOC to notify RVC request
 * @param None
 * @retval None
 */
static void RVC_Request(void)
{
	SysPowerMod sysPowerMod = 0;
	SysPowerModVld sysPowerModVld = FALSE;
	static uint8_t PASWorkCmd = 0;
	uint8_t PASWorkCmd_cur = 0;

	Std_ReturnType retval = E_NOT_OK;

#if (defined(GWM_V35_PROJECT_TYPE_B03))
	Rte_Read_SysPowerMod_SysPowerMod(&sysPowerMod);
	Rte_Read_SysPowerModVld_SysPowerModVld(&sysPowerModVld);
	Rte_Read_PASWorkCmd_PASWorkCmd(&PASWorkCmd_cur);
#else
    Rte_Call_rpCS_Mics_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &sysPowerMod, 1);
    Rte_Call_rpCS_Mics_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, &sysPowerModVld, 1);
	#if (!defined(GWM_V35_PROJECT_TYPE_P09))//cause P09 no have this single
    	Rte_Call_rpCS_Mics_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD, &PASWorkCmd_cur, 1);
	#endif
    
#endif
	if (PASWorkCmd != PASWorkCmd_cur)
	{
		PASWorkCmd = PASWorkCmd_cur;

		if ((PASWorkCmd == 1) && (sysPowerMod == SYS_POWER_MOD_ON) && (sysPowerModVld == SYS_POWER_MOD_VLD))
		{
			power_err("Gear shift in to R");
			retval = Rte_Call_IoHwAb_Interface_SetPin((uint8)RI_IoHwAb_DOut_PinOutCfg_VIP_REVERSE_IRQ, PIN_LOW);
			if (retval != E_OK)
			{
				power_err("Set pin: %d error!", RI_IoHwAb_DOut_PinOutCfg_VIP_REVERSE_IRQ);
			}
			else
			{
				/* MISRA rules */
			}
		}
		else if ((PASWorkCmd == 0) && (sysPowerMod == SYS_POWER_MOD_ON) && (sysPowerModVld == SYS_POWER_MOD_VLD))
		{
			power_err("Gear shift out to R");
			retval = Rte_Call_IoHwAb_Interface_SetPin(RI_IoHwAb_DOut_PinOutCfg_VIP_REVERSE_IRQ, PIN_HIGH);
			if (retval != E_OK)
			{
				power_err("Set pin: %d error!", RI_IoHwAb_DOut_PinOutCfg_VIP_REVERSE_IRQ);
			}
			else
			{
				/* MISRA rules */
			}
		}
		else
		{
			/* MISRA rules */
		}
	}
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:EOL_0xFDE0_EOL_ReadADCErrorLog_doc)  ******************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:EOL_0xFDE3_EOL_ReadEEPROMValue)  *****************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:EOL_0xFDE0_EOL_ReadADCErrorLog)  *****************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:EOL_0xFDE3_EOL_ReadEEPROMValue_doc)  ******************/


/***  End of saved code  ************************************************************************************/
#endif

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
