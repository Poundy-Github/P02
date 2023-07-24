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
 *             File:  RTC.c
 *           Config:  E:/WorkSpace/Git_WorkSpace/3_xCodeNewProject/20210414/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  RTC
 *  Generation Time:  2021-04-15 14:24:19
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <RTC>
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
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
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
 *********************************************************************************************************************/

#include "Rte_RTC.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "RTC.h"
#include "RTC_RI.h"
#include "RTC_Driver.h"
#include "RTC_cfg.h"
#include "Ipc_if.h"
#include "IPC_Misc.h"
#include "logger.h"

#include "CanIf.h"
#include "Lin.h"
#include "LinTrcv_30_Tle7259.h"
#include "ComM.h"

/* RTC CMD DEFINE */
typedef uint32 RTC_CMD_t;

#define cRTC_CMD_SYNC_TIME               (0x1)
#define cRTC_CMD_SET_TIME                (0x2)
#define cRTC_CMD_SET_TIME_FROM_IPC       (0x3)

/* RTC MODE STATE */
#define eRTC_UINIT                       (0x00)
#define eRTC_WAIT_SYNC                   (0x01)
#define eRTC_READY                       (0x02)

#define eINTERNAL_RTC_EMPTY              (0x00)
#define eINTERNAL_RTC_ACTIVATE           (0x01)

/* Sync type */
typedef uint8 SyncTypeDef_t;
#define eSyncType_Empty                 (0x00)
#define eSyncType_Auto                  (0x01)
#define eSyncType_Manual                (0x02)
/* define IPC Requst ID */
#define eIPC_REQ_EMPTY                  (0x00)
#define eIPC_REQ_GET_TIME               (0x01)
#define eIPC_REQ_SET_TIME               (0x02)

/* requeset type */
typedef struct
{
    RTC_CMD_t tCmd;
    time_t time;

}
RTC_Request_t;


/* RTC Handle type */
typedef struct
{
    RTC_Request_t Request;
    sint64 tSyncUTCTime;
    sint64 tSyncUTCBinTime;
    uint32 u32SyncSystemTime;
    uint8   state;
    uint8   u8InternalState; 
    boolean bRequesetExecute;
    sint64  tInternalUTCTime;

    boolean bLock;
    boolean bPending;
    uint32  u32SyncSystemTimeBack;
}
RTC_Handler_t;
/*  */
typedef struct
{
    uint8 req_id;
    time_t time;
}RTC_IPC_ReqDef_t;

typedef struct
{
    boolean bPending;
    boolean bExecute;
    uint32  u32ElapsedTime;
    union
    {
        IPC_M2S_MiscRTCACK_t tAck;
        IPC_M2S_MiscRTCTIME_t tTime;
    }data;
}RTC_IPC_SendBufferDef_t;

/* Static Variate */
STATIC RTC_Handler_t tRTC_Handler = {0};
STATIC RTC_IPC_ReqDef_t  tIPC_Req = {eIPC_REQ_EMPTY,0};
STATIC RTC_IPC_SendBufferDef_t tIPC_SendBuffer = {0};
uint32 u32Tick1ms = 0;

#pragma ghs startdata
#pragma ghs section bss=".rram_misc"

STATIC sint64 SleepDateTime;
STATIC sint32 RTC_timezone = 28800;
#pragma ghs section bss=default
#pragma ghs enddata

STATIC uint32 RTC_GetElapsedTime(void);
STATIC void RTC_SetState(uint8 state);

STATIC void RTC_WaitDrvInit(void);
STATIC void RTC_WaitFirstSYNC(void);
STATIC void RTC_SyncRequest(void);

STATIC void RTC_AnalysisCmd(void);
STATIC void RTC_AnalysisRequest(void);
STATIC void RTC_ProcessingSyncResult(uint8 impl_status,time_t time);
STATIC void RTC_ProcessingSetTimeResult(uint8 impl_status,time_t time);
STATIC void RTC_CheckResult(void);
STATIC void RTC_IPC_SetIdle(void);
STATIC void RTC_IPC_SetPending(void);
STATIC void RTC_IPC_CheckTimeout(void);
STATIC void RTC_IPC_GetTimeReq(void);
STATIC void RTC_IPC_SetTimeReq(void);
STATIC void RTC_IPC_Task(void);
STATIC void Emc_Output(void);
STATIC Std_ReturnType  RTC_GetSystemTick(uint32 * tick);
STATIC Std_ReturnType RTC_GetElapsedValue(uint32 * StartStamp, uint32 * TimeElapsed);
STATIC void RTC_ProcessingSync(void);

extern unsigned int __ghs_applrramstart;
extern unsigned int __ghs_applrramend;

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
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * sint64: Integer in interval [-9223372036854775808...9223372036854775807] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 *
 * Record Types:
 * =============
 * DateTimeType_t: Record with elements
 *   u16Year of type uint16
 *   u8Month of type uint8
 *   u8Day of type uint8
 *   u8Hour of type uint8
 *   u8Minutes of type uint8
 *   u8Seconds of type uint8
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


#define RTC_START_SEC_CODE
#include "RTC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetUTCTimeInMillis
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetUTCTimeInMillis> of PortPrototype <Sv_RTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RTC_GetUTCTimeInMillis(uint64 *arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IRTC_Service_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetUTCTimeInMillis_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTC_CODE) RTC_GetUTCTimeInMillis(P2VAR(uint64, AUTOMATIC, RTE_RTC_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_GetUTCTimeInMillis (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = RTE_E_INVALID;
  uint32 tick = 0;
  uint32 elapsed = 0;
  if (NULL_PTR != arg)
  {
      if (eRTC_READY == tRTC_Handler.state)
      {
      
          
          tRTC_Handler.bLock = TRUE;
          {
            (void)RTC_GetElapsedValue(&tRTC_Handler.u32SyncSystemTimeBack,&elapsed);
            *arg =(uint64) (tRTC_Handler.tSyncUTCBinTime + elapsed);
          }
          tRTC_Handler.bLock = FALSE;
          ret = RTE_E_OK;
      }
      else
      {
          (void)RTC_GetSystemTick(&tick);
          *arg = tick;
      }
  }

  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RTC_CycleTask
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Sd_RTC_SleepDateTime(sint64 data)
 *   Std_ReturnType Rte_Write_Sd_RTC_UtcTime(sint64 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_CycleTask_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, RTC_CODE) RTC_CycleTask(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_CycleTask
 *********************************************************************************************************************/
	uint32 u32_ElapsedTime = 0;
	if (eRTC_READY == tRTC_Handler.state)
	{
		u32_ElapsedTime = RTC_GetElapsedTime();
		tRTC_Handler.tInternalUTCTime = tRTC_Handler.tSyncUTCTime + (sint64)u32_ElapsedTime/1000;
		(void)RI_Write_UtcTime(tRTC_Handler.tInternalUTCTime);
		if (u32_ElapsedTime > SYNC_TIMEOUT)
		{ 
			RTC_SyncRequest();
		}
	}
	else
	{
	    (void)RI_Write_UtcTime(Rte_InitValue_Sd_RTC_UtcTime);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RTC_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Rtc_Init_server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RTC_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, RTC_CODE) RTC_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_Init
 *********************************************************************************************************************/

	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RTC_MainFunction
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
 *   Std_ReturnType Rte_Read_RcSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Sd_IIC1_Notify_Message_Message(uint16 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_RTC(void)
 *   void Rte_Exit_ExclusiveArea_RTC(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, RTC_CODE) RTC_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_MainFunction
 *********************************************************************************************************************/
    RTC_ProcessingSync();
    RTC_IPC_Task();
    RTC_AnalysisRequest();
    RTC_Driver_Impl_MainFunction();
    RTC_CheckResult();
    //Emc_Output();
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: UTC2PerpetualCalendar
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <UTC2PerpetualCalendar> of PortPrototype <Sv_RTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RTC_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IRTC_Service_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: UTC2PerpetualCalendar_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTC_CODE) RTC_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_RTC_APPL_VAR) date) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTC_UTC2PerpetualCalendar (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType ret = E_NOT_OK;
  if (date == NULL_PTR)
  {
      ret = E_NOT_OK;
  }
  else
  {
      struct tm * tLocal;
      utc = RTC_timezone + utc;
      tLocal = gmtime(&utc);
      date->u8Seconds =   (uint8) tLocal->tm_sec;
      date->u8Minutes =  (uint8) tLocal->tm_min;
      date->u8Hour =     (uint8) tLocal->tm_hour;
      date->u8Day =      (uint8) tLocal->tm_mday;
      date->u8Month =    (uint8) tLocal->tm_mon;
      date->u16Year =    (uint16) (tLocal->tm_year + 1900);
      ret = E_OK;
  }
  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTC_STOP_SEC_CODE
#include "RTC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*******************************************************************************
 * Function:    backup_ram_init
 * Description: initial backup ram
 * Invocation:  
 * Parameter:   void    
 * Return:  void
 *******************************************************************************/
void Backup_ram_init( void )
{
    uint32* backup_ram_addr = (uint32*)&__ghs_applrramstart;/*iRAM_R_SecureBoot & iRAM_R_NVM_Mirror reserved*/

	while(((uint32*)&__ghs_applrramend ) > backup_ram_addr)
	{
		*backup_ram_addr=0x00000000;
		backup_ram_addr++;
	}

}


 void RTC_ColdResetCallout(void)
 {
    Backup_ram_init();
    RTC_Driver_Impl_Init();
    SleepDateTime = -1;
 }

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
 void RTC_PreInit(void)
 {
    tRTC_Handler.state = eRTC_UINIT;
 }
 /***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC uint32 RTC_GetElapsedTime(void)
{
    uint32 tElapsedTime = 0;
    (void)RTC_GetElapsedValue(&tRTC_Handler.u32SyncSystemTime,&tElapsedTime);
    
    return (uint32)tElapsedTime;

}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
RTC_Return_t RTC_GetTime(sint64 * time)
{
    RTC_Return_t ret = eRTC_Return_E_Error;
    if (NULL_PTR != time)
    {
        if (eRTC_READY == tRTC_Handler.state)
        {
            *time = tRTC_Handler.tInternalUTCTime;
            ret = eRTC_Return_Seccess;
        }
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
RTC_Return_t RTC_GetBinTime(sint64 * time)
{
    RTC_Return_t ret = eRTC_Return_E_Error;
    uint32 tick = 0;
    uint32 elapsed = 0;
    if (NULL_PTR != time)
    {
        if (eRTC_READY == tRTC_Handler.state)
        {
            (void)RTC_GetElapsedValue(&tRTC_Handler.u32SyncSystemTime,&elapsed);
            *time = tRTC_Handler.tSyncUTCBinTime + elapsed;
            ret = eRTC_Return_Seccess;
        }
        else
        {
            (void)RTC_GetSystemTick(&tick);
            *time = (sint64)tick;
        }
    }
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
RTC_Return_t RTC_SetTime(const sint64  time)
{
    RTC_Return_t ret = eRTC_Return_E_Error;

    if (eRTC_READY == tRTC_Handler.state)
    {
        if (TRUE != tRTC_Handler.bRequesetExecute)
        {
            RTC_ENTER_CRITICAL_SECTION();
            tRTC_Handler.bRequesetExecute = TRUE;
            tRTC_Handler.Request.tCmd = cRTC_CMD_SET_TIME;
            tRTC_Handler.u8InternalState = eINTERNAL_RTC_EMPTY;
            tRTC_Handler.Request.time = time;
            RTC_EXIT_CRITICAL_SECTION();
            RTC_TraceMainFunction();
            ret = eRTC_Return_Seccess;
        }
        
    }
    return ret;
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_SetState(uint8 state)
{
    tRTC_Handler.state = state;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_WaitDrvInit(void)
{
     if (RTC_Driver_Impl_IsInit() == TRUE)
     {
        (void)RTC_Impl_SynchronizationTime();
        RTC_SetState(eRTC_WAIT_SYNC);
     }
     
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_WaitFirstSYNC(void)
{
    Rtc_Status_t impl_status = eRTC_STATUS_ERROR;
    time_t time;
    sint64 SleepTime =0;
    sint64 FirstSyncTime =0;

    impl_status = RTC_Impl_ReadResult(&time);

    if (eRTC_STATUS_OK == impl_status)
    {
        (void)RI_GetSystemTimer(&tRTC_Handler.u32SyncSystemTime);
        if (SleepDateTime == -1)
        {
            SleepTime = 0; 
        }
        else
        {
            SleepTime = time - SleepDateTime;
			RI_Write_SleepDateTime(SleepTime);
        }
        
        RTC_DEBUG("Sleep time:%d",SleepTime);
        
        RTC_ENTER_CRITICAL_SECTION();
        {
            tRTC_Handler.tSyncUTCTime = (sint64)time;
            FirstSyncTime = tRTC_Handler.tSyncUTCTime;
            tRTC_Handler.tSyncUTCBinTime = (sint64)time * 1000;
            tRTC_Handler.u32SyncSystemTimeBack = tRTC_Handler.u32SyncSystemTime;
        }
        RTC_EXIT_CRITICAL_SECTION();
        rtc_info("First SYNC Time %04x%08x\n",(uint32)(FirstSyncTime >> 32),(uint32)FirstSyncTime);
        RTC_SetState(eRTC_READY);
    }
    else if (eRTC_STATUS_ERROR == impl_status)
    {
        RTC_DEBUG("%s:RTC Init Error!\n",__FUNCTION__);
        RTC_SetState(eRTC_UINIT);
        tRTC_Handler.state = eRTC_UINIT;
    }

}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_SyncRequest(void)
{
    if (TRUE != tRTC_Handler.bRequesetExecute)
    {
        RTC_ENTER_CRITICAL_SECTION();
        tRTC_Handler.bRequesetExecute = TRUE;
        tRTC_Handler.Request.tCmd = cRTC_CMD_SYNC_TIME;
        tRTC_Handler.u8InternalState = eINTERNAL_RTC_EMPTY;
        RTC_EXIT_CRITICAL_SECTION();
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_AnalysisCmd(void)
{
    RTC_Return_t ret = eRTC_Return_E_Error;
    
    if (TRUE == tRTC_Handler.bRequesetExecute)
    {
        switch(tRTC_Handler.Request.tCmd)
        {
            case cRTC_CMD_SYNC_TIME:
                ret =  RTC_Impl_SynchronizationTime();
                if (eRTC_Return_Seccess == ret)
                {
                    tRTC_Handler.u8InternalState = eINTERNAL_RTC_ACTIVATE;
                }
                break;
            case cRTC_CMD_SET_TIME:
            case cRTC_CMD_SET_TIME_FROM_IPC:
                ret = RTC_Impl_SetTime(tRTC_Handler.Request.time);
                if (eRTC_Return_Seccess == ret)
                {
                    tRTC_Handler.u8InternalState = eINTERNAL_RTC_ACTIVATE;
                }
                break;
            default:
                /* Nothing to do*/
                break;
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_AnalysisRequest(void)
{

    switch (tRTC_Handler.state)
    {
        case eRTC_UINIT:
            RTC_WaitDrvInit();
            break;
        case eRTC_WAIT_SYNC:
            RTC_WaitFirstSYNC();
            break;
        case eRTC_READY:
            RTC_AnalysisCmd();
            break;
        default:
            /* Nothing to do*/
            break;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_ProcessingSyncResult(uint8 impl_status,time_t time)
{
    sint64 s64InternalTime = 0;
    
    if (eRTC_STATUS_OK == impl_status)
    {
        
        RTC_ENTER_CRITICAL_SECTION();
        {
            s64InternalTime = tRTC_Handler.tInternalUTCTime;
            
            (void)RI_GetSystemTimer(&tRTC_Handler.u32SyncSystemTime);
            tRTC_Handler.tSyncUTCTime = (sint64)time;
            if (tRTC_Handler.bLock == FALSE)
            {
                tRTC_Handler.bPending = FALSE;
                tRTC_Handler.tSyncUTCBinTime = (sint64)time * 1000;
                tRTC_Handler.u32SyncSystemTimeBack = tRTC_Handler.u32SyncSystemTime;
            }
            else
            {
                tRTC_Handler.bPending = TRUE;
            }
        }
        RTC_EXIT_CRITICAL_SECTION();
        
        (void)Rte_Call_rpCS_SWCRtc_OdoTimeSync_CallBack(s64InternalTime,time);
    }
    else
    {
        RTC_DEBUG("%s:RTC Sync Error!\n",__FUNCTION__);
    }
    tRTC_Handler.u8InternalState = eINTERNAL_RTC_EMPTY;
    tRTC_Handler.bRequesetExecute = FALSE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_ProcessingSetTimeResult(uint8 impl_status,time_t time)
{
    if (eRTC_STATUS_OK == impl_status)
    {
        tRTC_Handler.Request.tCmd = cRTC_CMD_SYNC_TIME;
        (void)RTC_Impl_SynchronizationTime();
        RTC_TraceMainFunction();
//        RTC_ResultNotification(eRTC_STATUS_ERROR);
        
    }
    else
    {
        RTC_DEBUG("%s:RTC Set Time Error!\n",__FUNCTION__);
//        RTC_ResultNotification(eRTC_STATUS_ERROR);
        tRTC_Handler.u8InternalState = eINTERNAL_RTC_EMPTY;
        tRTC_Handler.bRequesetExecute = FALSE;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_CheckResult(void)
{

    Rtc_Status_t impl_status = eRTC_STATUS_ERROR;
    time_t time;

    if ((eINTERNAL_RTC_ACTIVATE==tRTC_Handler.u8InternalState) && (eRTC_READY == tRTC_Handler.state))
    {
        impl_status  = RTC_Impl_ReadResult(&time);
        if (eRTC_STATUS_BUSY != impl_status)
        {
            switch(tRTC_Handler.Request.tCmd)
            {
                case cRTC_CMD_SYNC_TIME:
                    RTC_ProcessingSyncResult(impl_status,time);
                    break;
                case cRTC_CMD_SET_TIME:
                case cRTC_CMD_SET_TIME_FROM_IPC:
                    RTC_ProcessingSetTimeResult(impl_status,time);
                    break;
                default:
                    /* Nothing to do*/
                    break;
            }
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_IPC_RTC_Callback(uint8 sub_msg_id,uint8* param, uint16 param_len)
{
    if (eIPC_REQ_EMPTY == tIPC_Req.req_id)
    {
        switch(sub_msg_id)
        {
            case IPC_S2M_MISC_RTC_MSGSUB_GET_TIME_REQUEST_ID:
                tIPC_Req.req_id = eIPC_REQ_GET_TIME;
                break;
            case IPC_S2M_MISC_RTC_MSGSUB_SET_TIME_REQUEST_ID:
                {
                    IPC_S2M_MiscRTCSet_Time_Request_t data;
                    IPC_S2M_MiscRTCSet_Time_Request_Receive(param,&data,param_len);
                    
                    tIPC_Req.time = data.UTC_Time;
                    tIPC_Req.req_id = eIPC_REQ_SET_TIME;
                }
                break;
            default:
                /* Nothing to do*/
                break;
        }
        RTC_TraceMainFunction();
    }
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_SetIdle(void)
{
    tIPC_SendBuffer.bPending = FALSE;
    tIPC_SendBuffer.bExecute = FALSE;
    tIPC_Req.req_id = eIPC_REQ_EMPTY;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_SetPending(void)
{
    (void)RI_GetSystemTimer(&tIPC_SendBuffer.u32ElapsedTime);
    tIPC_SendBuffer.bPending = TRUE;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_CheckTimeout(void)
{
    uint32 Elapsed;

    (void)RI_GetElapsedValue(&tIPC_SendBuffer.u32ElapsedTime,&Elapsed);
    
    if (Elapsed>= RTC_SEND_TPC_TIMEOUT)
    {
        /* Send error */
        RTC_IPC_SetIdle();
    }

}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_GetTimeReq(void)
{
    int32_t ret = -1;
    sint64 IPCTransInternalTime = 0;
    if (eRTC_READY == tRTC_Handler.state)
    {
        tIPC_SendBuffer.data.tTime.UTC_Time = (uint64_t)tRTC_Handler.tInternalUTCTime;
        IPCTransInternalTime = (sint64)tIPC_SendBuffer.data.tTime.UTC_Time;
        rtc_info("IPC TX InternalTime %04x%08x\n",(uint32)(IPCTransInternalTime >> 32),(uint32)IPCTransInternalTime);

    }
    else
    {
        tIPC_SendBuffer.data.tTime.UTC_Time = (uint64_t)(-1l);
    }
    
    ret = IPC_M2S_MiscRTCTIME_Transmit(&tIPC_SendBuffer.data.tTime);
    
    if (IPC_ERR_NONE == ret)
    {
        RTC_IPC_SetIdle();
    }
    else if (FALSE == tIPC_SendBuffer.bPending)
    {
        RTC_IPC_SetPending();
    }
    else
    {
        RTC_IPC_CheckTimeout();
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_SetTimeReq(void)
{
    int32_t ret = -1;
    sint64 IpcSetTime = 0;
    if (eRTC_READY == tRTC_Handler.state)
    {
        if ((TRUE != tRTC_Handler.bRequesetExecute)&&(FALSE == tIPC_SendBuffer.bExecute))
        {
            RTC_ENTER_CRITICAL_SECTION();
            tRTC_Handler.bRequesetExecute = TRUE;
            tRTC_Handler.Request.tCmd = cRTC_CMD_SET_TIME;
            tRTC_Handler.u8InternalState = eINTERNAL_RTC_EMPTY;
            tRTC_Handler.Request.time = tIPC_Req.time;
            IpcSetTime = tRTC_Handler.Request.time;
            RTC_EXIT_CRITICAL_SECTION();
            rtc_info("Set Time from IPC %04x%08x\n",(uint32)(IpcSetTime >> 32),(uint32)IpcSetTime);
            tIPC_SendBuffer.bExecute = TRUE;
            
            tIPC_SendBuffer.bPending = FALSE;
        }
    }

    if (TRUE == tIPC_SendBuffer.bExecute)
    {
        tIPC_SendBuffer.data.tAck.States = RTC_IPC_ACK_OK;
    }
    else
    {
        tIPC_SendBuffer.data.tAck.States = RTC_IPC_ACK_NOK;
    }
    
    ret = IPC_M2S_MiscRTCACK_Transmit(&tIPC_SendBuffer.data.tAck);

    if (IPC_ERR_NONE == ret)
    {
        RTC_IPC_SetIdle();
    }
    else if (FALSE == tIPC_SendBuffer.bPending)
    {
        RTC_IPC_SetPending();
    }
    else
    {
        RTC_IPC_CheckTimeout();
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_IPC_Task(void)
{
    if (eIPC_REQ_EMPTY != tIPC_Req.req_id)
    {
        switch(tIPC_Req.req_id)
        {
            case eIPC_REQ_GET_TIME:
                RTC_IPC_GetTimeReq();
                break;
            case eIPC_REQ_SET_TIME:
                RTC_IPC_SetTimeReq();
                break;
            default:
                /*Nothing to do */
                break;
        }
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Rtc_SleepDateTimeRecord(void)
{

    if (eRTC_READY == tRTC_Handler.state)
    {
        RTC_ENTER_CRITICAL_SECTION();
        SleepDateTime = tRTC_Handler.tInternalUTCTime;
        Rte_Exit_ExclusiveArea_RTC();
    }

}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_ProcessingSync(void)
{
    if (tRTC_Handler.bPending == TRUE)
    {
        RTC_ENTER_CRITICAL_SECTION();
        {
            if (tRTC_Handler.bLock == FALSE)
            {
                tRTC_Handler.u32SyncSystemTimeBack = tRTC_Handler.u32SyncSystemTime;
                tRTC_Handler.tSyncUTCBinTime = tRTC_Handler.tSyncUTCTime * 1000;
                tRTC_Handler.bPending = FALSE;
            }
        }
        Rte_Exit_ExclusiveArea_RTC();
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/

#ifdef RTC_TST

time_t tLocalTime = 0;

void RTC_Test(void)
{
    RTC_Return_t ret;
    
    ret = RTC_GetTime(&tLocalTime);
    if (eRTC_Return_Seccess == ret)
    {
        RTC_DEBUG("[Local Time] [%ld]\n",tLocalTime);
    }
}

#endif


STATIC void Emc_Output(void)
{
    static ComM_ModeType mode = COMM_NO_COMMUNICATION;
    static ComM_ModeType modeLast = COMM_NO_COMMUNICATION;

    Can_PduType canPdu1;
    Can_PduType canPdu2;
    static uint8 canData[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    Lin_PduType linPdu1;
    Lin_PduType linPdu2;
    static uint8 linData[8] = {0x12, 0x34, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

    canPdu1.id = 0x7F0;
    canPdu1.length = 0x08;
    canPdu1.sdu = canData;
    canPdu1.swPduHandle = 24;

    canPdu2.id = 0x7F1;
    canPdu2.length = 0x08;
    canPdu2.sdu = canData;
    canPdu2.swPduHandle = 24;

    linPdu1.Pid = 0x85;
    linPdu1.Cs = LIN_ENHANCED_CS;
    linPdu1.Drc = LIN_FRAMERESPONSE_TX;
    linPdu1.Dl = 8;
    linPdu1.SduPtr = (uint8 *)&linData;

    linPdu2.Pid = 0x47;
    linPdu2.Cs = LIN_ENHANCED_CS;
    linPdu2.Drc = LIN_FRAMERESPONSE_TX;
    linPdu2.Dl = 8;
    linPdu2.SduPtr = (uint8 *)&linData;

    (void)ComM_GetCurrentComMode(ComMConf_ComMUser_CN_B30_for_SC_CAN_V3_2_9e267e6f, &mode);
    if(COMM_FULL_COMMUNICATION == mode)
    {
        if(mode != modeLast)
        {
            (void)CanIf_SetControllerMode(CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001, CANIF_CS_STARTED);
            (void)CanIf_SetControllerMode(CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002, CANIF_CS_STARTED);
            (void)LinTrcv_30_Tle7259_SetOpMode(LinConf_LinChannel_CN_LIN00_fd825f00, LINTRCV_TRCV_MODE_NORMAL);
	        (void)LinTrcv_30_Tle7259_SetOpMode(LinConf_LinChannel_CN_LIN00_fd825f00_001, LINTRCV_TRCV_MODE_NORMAL);
        }
        else
        {
            (void)Can_Write(CanConf_CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_001, &canPdu1);
            (void)Can_Write(CanConf_CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_002, &canPdu2);

            (void)Lin_SendFrame(LinConf_LinChannel_CN_LIN00_fd825f00, &linPdu1);
            (void)Lin_SendFrame(LinConf_LinChannel_CN_LIN00_fd825f00_001, &linPdu2);
        }
    }
    else if(COMM_NO_COMMUNICATION == mode)
    {
        if(mode != modeLast)
        {
            (void)CanIf_SetControllerMode(CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001, CANIF_CS_SLEEP);
            (void)CanIf_SetControllerMode(CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002, CANIF_CS_SLEEP);
            (void)LinTrcv_30_Tle7259_SetOpMode(LinConf_LinChannel_CN_LIN00_fd825f00, LINTRCV_TRCV_MODE_SLEEP);
	        (void)LinTrcv_30_Tle7259_SetOpMode(LinConf_LinChannel_CN_LIN00_fd825f00_001, LINTRCV_TRCV_MODE_SLEEP);
        }
    }

    modeLast = mode;
}

__interrupt void GptIsr_1ms_tick(void)
{
    u32Tick1ms++;
}

STATIC Std_ReturnType RTC_GetSystemTick(uint32 * tick)
{
    *tick = u32Tick1ms;
    return 0;
}

STATIC Std_ReturnType RTC_GetElapsedValue(uint32 * StartStamp, uint32 * TimeElapsed) 
{
	uint32 temp_time;
	uint32 result;
    uint32 time = *StartStamp;

	temp_time = u32Tick1ms;

	if(temp_time >= time)
	{
		result = temp_time - time;/*count down timer*/
	}
	else																								  
	{
	    result = 0xffffffff - time + temp_time + 1;
	}
	
	(*TimeElapsed) = result;                                              

    return 0;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:RTC_Init_doc)  ****************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RTC_Init)  ***************************************/

    tRTC_Handler.state = eRTC_UINIT;
    
/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:Rtc_Init)  ***************************************/
	tRTC_Handler.state = eRTC_UINIT;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Rtc_Init_doc)  ****************************************/


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
