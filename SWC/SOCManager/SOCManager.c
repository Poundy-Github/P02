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
 *             File:  SOCManager.c
 *           Config:  D:/workspace/nubo/VIP/B03/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  SOCManager
 *  Generation Time:  2021-06-15 11:19:44
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <SOCManager>
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
 * NvM_RequestResultType
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
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SOCManager.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <string.h>
#include "SOCManager.h"
#include "SOCManager_RI.h"
#include "SOCManager_Alg.h"
#include "SOCManager_IPC_Service.h"
#include "MagicNum.h"
#include "Ext_Power.h"
#ifndef GWM_V35_PROJECT_TYPE_B03
#include "ComEx_Cfg.h"
#endif
#define SOCManager_START_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

uint8 RTE_SocManagerSystemState = 0;
#define SOCManager_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


enum
{
    eKEY_AdjVolDwnSwtSts,
    eKEY_AdjVolUpSwtSts,
    eKEY_CustomSwtSts,
    eKEY_CustomSwtSts_Mmed,
    eKEY_EnterSwtSts,
    eKEY_EnterSwtSts_Mmed,
    eKEY_HomeSwtSts,
    eKEY_MenuReturnSwtSts,
    eKEY_MuteSwtSts,
    eKEY_PageDwnSwtSts,
    eKEY_PageLSwtSts,
    eKEY_PageRSwtSts,
    eKEY_PageUpSwtSts,
    eKEY_SeekDwnSwtSts,
    eKEY_SeekUpSwtSts,
    eKEY_VRSwtSts,
    eKEY_NUM,
};


#define KEY_Released (0U)
#define KEY_Pressed (1U)
#define KEY_error (2U)
#define KEY_invalidation (3U)


#ifndef GWM_V35_PROJECT_TYPE_B03
#define SIGNAL_NORMAL(X)    ((X == COMEX_UPDATE_RECEIVED)||(X == E_OK))
#else
#define SIGNAL_NORMAL(X)    (((X & RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED) && ((X & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && ((X & RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
#endif


typedef struct
{
    SOCManager_KEY_Mask_t mask;
#ifdef GWM_V35_PROJECT_TYPE_B03
    Std_ReturnType (*p_fun)(uint8 * key);
#else
    ComEx_SignalIdType SignalId;
#endif
}SOCManager_Key_t;


#pragma ghs startdata
#pragma ghs section bss=".reset_flag" 
uint8 SOC_Req_Reset_Flag;
#pragma ghs section bss=default
#pragma ghs enddata


static SOCManager_Key_t SOCManager_Key_Table[eKEY_NUM] = 
#ifdef GWM_V35_PROJECT_TYPE_B03
{
    {SOCManager_KEY_AdjVolDwnSwtSts_Mask  ,RI_ReadAdjVolDwnSwtSts  },
    {SOCManager_KEY_AdjVolUpSwtSts_Mask   ,RI_ReadAdjVolUpSwtSts   },
    {SOCManager_KEY_CustomSwtSts_Mask     ,RI_ReadCustomSwtSts     },
    {SOCManager_KEY_CustomSwtSts_Mmed_Mask,RI_ReadCustomSwtSts_Mmed},
    {SOCManager_KEY_EnterSwtSts_Mask      ,RI_ReadEnterSwtSts      },
    {SOCManager_KEY_EnterSwtSts_Mmed_Mask ,RI_ReadEnterSwtSts_Mmed },
    {SOCManager_KEY_HomeSwtSts_Mask       ,RI_ReadHomeSwtSts       },
    {SOCManager_KEY_MenuReturnSwtSts_Mask ,RI_ReadMenuReturnSwtSts },
    {SOCManager_KEY_MuteSwtSts_Mask       ,RI_ReadMuteSwtSts       },
    {SOCManager_KEY_PageDwnSwtSts_Mask    ,RI_ReadPageDwnSwtSts    },
    {SOCManager_KEY_PageLSwtSts_Mask      ,RI_ReadPageLSwtSts      },
    {SOCManager_KEY_PageRSwtSts_Mask      ,RI_ReadPageRSwtSts      },
    {SOCManager_KEY_PageUpSwtSts_Mask     ,RI_ReadPageUpSwtSts     },
    {SOCManager_KEY_SeekDwnSwtSts_Mask    ,RI_ReadSeekDwnSwtSts    },
    {SOCManager_KEY_SeekUpSwtSts_Mask     ,RI_ReadSeekUpSwtSts     },
    {SOCManager_KEY_VRSwtSts_Mask         ,RI_ReadVRSwtSts         },

};
#else
{
    {SOCManager_KEY_AdjVolDwnSwtSts_Mask  ,COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS},
    {SOCManager_KEY_AdjVolUpSwtSts_Mask   ,COMEX_SIGNAL_RX_ADJVOLUPSWTSTS},
    #if(!defined GWM_V35_PROJECT_TYPE_ES13)
    {SOCManager_KEY_CustomSwtSts_Mask     ,COMEX_SIGNAL_RX_CUSTOMSWTSTS},
    #endif
    {SOCManager_KEY_CustomSwtSts_Mmed_Mask,COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED},
    {SOCManager_KEY_EnterSwtSts_Mask      ,COMEX_SIGNAL_RX_ENTERSWTSTS},
    {SOCManager_KEY_EnterSwtSts_Mmed_Mask ,COMEX_SIGNAL_RX_ENTERSWTSTS_MMED},
#if (!defined GWM_V35_PROJECT_TYPE_P09)
    {SOCManager_KEY_HomeSwtSts_Mask       ,COMEX_SIGNAL_RX_HOMESWTSTS},
    {SOCManager_KEY_MenuReturnSwtSts_Mask ,COMEX_SIGNAL_RX_MENURETURNSWTSTS},
#endif
    {SOCManager_KEY_MuteSwtSts_Mask       ,COMEX_SIGNAL_RX_MUTESWTSTS},
#if (!defined GWM_V35_PROJECT_TYPE_P09)
    {SOCManager_KEY_PageDwnSwtSts_Mask    ,COMEX_SIGNAL_RX_PAGEDWNSWTSTS},
#endif
    {SOCManager_KEY_PageLSwtSts_Mask      ,COMEX_SIGNAL_RX_PAGELSWTSTS},
    {SOCManager_KEY_PageRSwtSts_Mask      ,COMEX_SIGNAL_RX_PAGERSWTSTS},
    {SOCManager_KEY_PageUpSwtSts_Mask     ,COMEX_SIGNAL_RX_PAGEUPSWTSTS},
    {SOCManager_KEY_SeekDwnSwtSts_Mask    ,COMEX_SIGNAL_RX_SEEKDWNSWTSTS},
    {SOCManager_KEY_SeekUpSwtSts_Mask     ,COMEX_SIGNAL_RX_SEEKUPSWTSTS},
    {SOCManager_KEY_VRSwtSts_Mask         ,COMEX_SIGNAL_RX_VRSWTSTS},
};
#endif


#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern void IPC_Init(void);

static void SOCManager_Task(void);
static void SOCManager_Input(sSOCManagerIO_t *io);
static void SOCManager_Calculate(sSOCManagerIO_t *io);
static void SOCManager_Output(sSOCManagerIO_t *io);
static void SOCManager_ScanKey(sSOCManagerIO_t *io);

static void RI_Read_Requset2MiniSystem(boolean *data);

#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AdjVolDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * AdjVolUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * CustomSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * CustomSwtSts_Mmed: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * DrvGearDisp: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_0 (0U)
 *   Cx1_1 (1U)
 *   Cx2_2 (2U)
 *   Cx3_3 (3U)
 *   Cx4_4 (4U)
 *   Cx5_5 (5U)
 *   Cx6_6 (6U)
 *   Cx7_7 (7U)
 * EnterSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * EnterSwtSts_Mmed: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * HomeSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * MenuReturnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * MuteSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_Error (2U)
 *   Cx3_invalidation (3U)
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * PageDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageLSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageRSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * PageUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalid (3U)
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
 *   SYSTEMSTATE_IVI_ON_NORMAL (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (8U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (9U)
 *   SYSTEMSTATE_IVI_REMOTE (4U)
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
 * SeekDwnSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * SeekUpSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
 * VRSwtSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_error (2U)
 *   Cx3_invalidation (3U)
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
 * s_SpeedoInfo_t: Record with elements
 *   OverSpdWrnFlg of type uint8
 *   VehRunSts of type uint8
 *   IndicateSpeed of type uint16
 *   RealSpeed of type uint16
 *   IndicateSpeedMile of type uint16
 *   RealSpeedMile of type uint16
 *   RealSpeedBak of type uint16
 *   Msg_missingSts of type uint8
 *   VehSpdVld of type uint8
 * s_TachoInfo_t: Record with elements
 *   EngRunSts of type uint8
 *   EngSpd of type uint16
 *   TimeOutFlag of type uint8
 *   EngSpdBak of type uint16
 *   Msg_missingSts of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_HealthSwitch_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 Rte_CData_NvBlockNeed_HealthSwitch_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvBlockNeed_HealthSwitch_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_HealthSwitch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvBlockNeed_HealthSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_HealthSwitch_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SOCManager_CODE) NvBlockNeed_HealthSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockNeed_HealthSwitch_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SOCManager_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SOCManager_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SOCManager_CODE) SOCManager_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SOCManager_Init
 *********************************************************************************************************************/
    IPC_Init();
    SOCManager_AlgInit();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SOCManager_ManFunction
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
 *   Std_ReturnType Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts(AdjVolDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts(AdjVolUpSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_CustomSwtSts(CustomSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed(CustomSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_EOL_KeepDownload_keepDownloadRID(uint16 *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_EnterSwtSts(EnterSwtSts *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed(EnterSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_HomeSwtSts_HomeSwtSts(HomeSwtSts *data)
 *   Std_ReturnType Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts(MenuReturnSwtSts *data)
 *   Std_ReturnType Rte_Read_MuteSwtSts_MuteSwtSts(MuteSwtSts *data)
 *   Std_ReturnType Rte_Read_PageDwnSwtSts_PageDwnSwtSts(PageDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_PageLSwtSts_PageLSwtSts(PageLSwtSts *data)
 *   Std_ReturnType Rte_Read_PageRSwtSts_PageRSwtSts(PageRSwtSts *data)
 *   Std_ReturnType Rte_Read_PageUpSwtSts_PageUpSwtSts(PageUpSwtSts *data)
 *   Std_ReturnType Rte_Read_Rc_Upgrade_flag_Element(uint32 *data)
 *   Std_ReturnType Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts(SeekDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekUpSwtSts_SeekUpSwtSts(SeekUpSwtSts *data)
 *   Std_ReturnType Rte_Read_VRSwtSts_VRSwtSts(VRSwtSts *data)
 *   Std_ReturnType Rte_Read_rpSR_SOCManager_DrvGearDisp_Element(DrvGearDisp *data)
 *   Std_ReturnType Rte_Read_rpSR_SOCManager_GearMsgMiss_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SOCManager_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SOCManager_TachoInfo_Element(s_TachoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_System_Recovery_System_Recovery(boolean *data)
 *   Std_ReturnType Rte_Read_rpSR_Upgrade_System_Recovery_System_Recovery(boolean *data)
 *   boolean Rte_IsUpdated_AdjVolDwnSwtSts_AdjVolDwnSwtSts(void)
 *   boolean Rte_IsUpdated_AdjVolUpSwtSts_AdjVolUpSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_CustomSwtSts(void)
 *   boolean Rte_IsUpdated_CustomSwtSts_Mmed_CustomSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_EnterSwtSts(void)
 *   boolean Rte_IsUpdated_EnterSwtSts_Mmed_EnterSwtSts_Mmed(void)
 *   boolean Rte_IsUpdated_HomeSwtSts_HomeSwtSts(void)
 *   boolean Rte_IsUpdated_MenuReturnSwtSts_MenuReturnSwtSts(void)
 *   boolean Rte_IsUpdated_MuteSwtSts_MuteSwtSts(void)
 *   boolean Rte_IsUpdated_PageDwnSwtSts_PageDwnSwtSts(void)
 *   boolean Rte_IsUpdated_PageLSwtSts_PageLSwtSts(void)
 *   boolean Rte_IsUpdated_PageRSwtSts_PageRSwtSts(void)
 *   boolean Rte_IsUpdated_PageUpSwtSts_PageUpSwtSts(void)
 *   boolean Rte_IsUpdated_SeekDwnSwtSts_SeekDwnSwtSts(void)
 *   boolean Rte_IsUpdated_SeekUpSwtSts_SeekUpSwtSts(void)
 *   boolean Rte_IsUpdated_VRSwtSts_VRSwtSts(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSR_SocManager_SystemState(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady(boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_SOCManager(void)
 *   void Rte_Exit_ExclusiveArea_SOCManager(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SOCManager_ManFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SOCManager_CODE) SOCManager_ManFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SOCManager_ManFunction
 *********************************************************************************************************************/
    SOCManager_Task();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Task(void)
{
    sSOCManagerIO_t io;

    memset(&io,0,sizeof(io));

    SOCManager_Input(&io);
    SOCManager_ScanIPCMsg(&io);
    SOCManager_Calculate(&io);
    SOCManager_Output(&io);
    
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void RI_Read_Requset2MiniSystem(boolean *data)
{
    boolean DiagRecovery;
    boolean UpgradeRecovery;
    Rte_Read_rpSR_System_Recovery_System_Recovery(&DiagRecovery);
    Rte_Read_rpSR_Upgrade_System_Recovery_System_Recovery(&UpgradeRecovery);
    if((DiagRecovery==TRUE) || (UpgradeRecovery==TRUE))
    {
        *data = TRUE;
    }
    else
    {
        *data = FALSE;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Input(sSOCManagerIO_t *io)
{
    s_SpeedoInfo_t SpeedoInfo = {0};
    
    (void)RI_GetHwVersion(&io->u8HwVersion);
    (void)RI_ReadKeepDownloadRID(&io->u16keepDownloadRID);
    (void)RI_ReadPmicState(&io->tPmicState);
    (void)RI_ReadSystemState(&io->u8SystemState);
    (void)RI_Read_Upgrade_flag(&io->u32Upgrade_flag);
    (void)RI_Read_Requset2MiniSystem(&io->bRequset2MiniSystem);
    (void)RI_Read_Logger_IPC_ReadyStatus(&io->bReadLoggerIpcStatus);
    (void)RI_Read_HeathFromSoc(&io->u8heathResp);
	

    (void)RI_ReadSpeedoInfo(&SpeedoInfo);

    io->u16Speed = SpeedoInfo.RealSpeed;
	io->u8speedvld = SpeedoInfo.VehSpdVld;
    io->u8Msg_missingSts = SpeedoInfo.Msg_missingSts;
    SOCManager_ScanKey(io);
    
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Calculate(sSOCManagerIO_t *io)
{
    SOCManager_AlgCalculate(io);
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Output(sSOCManagerIO_t *io)
{
    (void)RI_WriteSOCManagerState(io->u8SOCManagerState);
    
    if (io->u8UpdataSOCReqResetFlag != 0)
    {
        (void)socmanager_Verbose("Updata flag : %X",io->u8UpdataSOCReqResetFlag);
        MAGIC_NUMBER_SET(app2bm,io->u8UpdataSOCReqResetFlag);
    }

    // power ctr
    if (io->bReqResetSoc == TRUE)
    {
        (void)RI_ReqSocReset(io->u8ResetSOCMode);
    }
    if ((io->tReqPowerState != ePOWER_STATE_IDLE) && (io->tReqPowerState != ePOWER_STATE_INITIAL))
    {
        (void)RI_ReqSocPowerState(io->tReqPowerState);
    }
    if (io->bReqResetMCU == TRUE)
    {
        if (SOCManager_ReqResetReason_Warm == io->u8ReqResetMcuReason)
        {
            cold_reset_req = HARDKEY_WARM_RESET;
        }
        else if(SOCManager_ReqResetReason_Other == io->u8ReqResetMcuReason)
        {
            cold_reset_req = SOC_REQ_COLD_RESET;
            init_process_finish = INIT_PROCESS_NOT_FINISHED;	

			if(0xBB == io->u8UpdataSOCReqResetFlag)
			{
				soc_cold_reset_type = SOC_RESET_SOC_MINI;
			}
			else if(0x55 == io->u8UpdataSOCReqResetFlag)
			{
				soc_cold_reset_type = SOC_RESET_FOTA_CHECK_MIN;
			}
			else if(0xAA == io->u8UpdataSOCReqResetFlag)
			{
				soc_cold_reset_type = SOC_RESET_USB_UPDATE;
			}			
			else if(0 != io->bSocFactoryResetReady)
			{
				soc_cold_reset_type = SOC_RESET_SYSTEM_REC;
			}
			else 
			{
				/*other case*/
			}
        }
        else if(SOCManager_ReqResetReason_SystemErr == io->u8ReqResetMcuReason)
        {
            cold_reset_req = SYS_ERR_COLD_RESET;
            init_process_finish = INIT_PROCESS_NOT_FINISHED;	
            
			if (io->tTimeroutEvent & eSOCManager_Timerout_Handshake)
			{
				soc_cold_reset_type = SOC_RESET_HANDSHAKE;
			}
			else if (io->tTimeroutEvent & eSOCManager_Timerout_Heath)
			{
				soc_cold_reset_type = SOC_RESET_HEALTH;
			}
			else 
			{
				/*do nothing*/
			}
        }
		else
		{
			/*do nothing*/
		}
        /*request VIP and SOC reset, BswMReqShutdown = 3*/
        (void)RI_Request_PowerModeShutdownReq_requestedMode(3);
    }
    
    if (io->bCloseDevice == TRUE)
    {
        RI_IPC_DeInit();	
		#ifdef PLATFORM_OF_STB_IPC_USED
		RI_IPC_STB_DeInit();
		#endif
    }
    else if (io->bOpenDevice == TRUE)
    {
        RI_IPC_Init();
		#ifdef PLATFORM_OF_STB_IPC_USED
		RI_IPC_STB_Init();
		#endif
    }

    if (io->tAMPDevCtrl == eSOCManager_AMPStateCtrl_Open)
    {
        RI_AMP_Init();
    }
    else if (io->tAMPDevCtrl == eSOCManager_AMPStateCtrl_Close)
    {
        RI_AMP_Emergency_Shutdown();
    }
    
    (void)RI_WriteSocFactoryResetReady(io->bSocFactoryResetReady);

    if (io->bResetLoggerIpcStatus)
    {
        RI_Write_Logger_IPC_ReadyStatus(FALSE);
    }
    SOCManager_IPCResponse(io);
#ifdef PLATFORM_OF_STB_IPC_USED
	SOCManager_STBIPCResponse(io);
#endif
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_ScanKey(sSOCManagerIO_t *io)
{
    uint8 i;
    uint8 key;
    Std_ReturnType rte = E_OK;
    
    for (i=0; i<eKEY_NUM; i++)
    {
        key = 0;
#ifdef GWM_V35_PROJECT_TYPE_B03
        if (SOCManager_Key_Table[i].p_fun != NULL_PTR)
        {
            rte = SOCManager_Key_Table[i].p_fun(&key);
        }
#else
        rte = RI_ReceiveSignal(SOCManager_Key_Table[i].SignalId,&key,sizeof(key));
        if (SIGNAL_NORMAL(rte) == TRUE)
        {
            rte = E_OK;
        }
        else
        {
            rte = E_NOT_OK;
        }
#endif
        if ((key == KEY_Pressed)&&(rte == E_OK))
        {
            io->tKeyMask |= SOCManager_Key_Table[i].mask;
        }
        
    }

}


#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
