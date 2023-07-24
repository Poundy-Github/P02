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
 *             File:  Can_Server.c
 *           Config:  D:/Code_Project/Vector35_02_07/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Can_Server
 *  Generation Time:  2021-02-07 09:47:45
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Can_Server>
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
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DebounceResetStatusType
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
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * KL30BRelaySts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RemoteModSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * wakeup_type
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *********************************************************************************************************************/

#include "Rte_Can_Server.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Com_Types.h"
#include "Compiler_Cfg.h"
#include "Compiler.h"
#include "Com_Cfg.h"
#include "ComM.h"
#include "CanIf.h"
#include "ComNoAction.h"
#include "ComStack_Types.h"
#include "logger.h"
#include "CanSM.h"
#include "CanNm.h"
#include "VConfig_Cfg.h"
#include "CanSM_BswM.h"
#include "CanSM_ComM.h"
#include "SystemState_IVI_Condition.h"


#define  DISABLE_PDU_NUMBER                            ((uint8)(1u))
#define  DISABLE_RX_PDU_NUMBER                         ((uint8)(4u))
#define  CanServer_Disable_Rx_PDU_Number()             ((uint8)(4u))
#define  Com_IPduEnable_VarPtr()                       (Com_Disable_CurrentRxPdu_Record)
#define  Com_IPduEnable_VarCfgPtr()                    (Com_Disable_RxPdu_Receive_Cfg)
#define  Com_SetRxPduEnableFlag(index,value)           ((Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index]) = (value))
#define  Com_GetRxPduEnableFlag(index)                 (Com_Disable_CurrentRxPdu_Record.RxPduEnableFlag[index])
#define  BUSOFF_CONTROLLER_0                                     ((uint8)(0u))
#define  Busoff_GetDelayTime(controller)                         (BusOffRecord[controller].delayTimer)
#define  Busoff_SetDelayTime(controller, value)                  ((BusOffRecord[controller].delayTimer) = (value))
#define  Busoff_DelayTimeDecrease(controller)                    (BusOffRecord[controller].delayTimer--)
#define  Busoff_GetFastBoCnt(controller)                         (BusOffRecord[controller].recyCnt)
#define  Busoff_SetFastBoCnt(controller, value)                  ((BusOffRecord[controller].recyCnt) = (value))
#define  Busoff_FastBoCnt(controller, value)                     ((BusOffRecord[controller].recyCnt) = (value))
#define  Busoff_FastBoCntIncrease(controller)                    (BusOffRecord[controller].recyCnt++)
#define  Busoff_GetPassedTime(controller)                        (BusOffRecord[controller].passedTime)
#define  Busoff_SetPassedTime(controller, value)                 ((BusOffRecord[controller].passedTime) = (value))
#define  Busoff_PassedTimeDecrease(controller)                   (BusOffRecord[controller].passedTime--)
#define  Busoff_SetBorFlag(controller, value)                    ((BusOffRecord[controller].busoffFlag) = (value))
#define  Busoff_GetBorFlag(controller)                           (BusOffRecord[controller].busoffFlag)

#define  KL15_SetDelayTimeFlag(value)                  (KL15SwitchStatusRecord.DelayTimeFlag = (value))
#define  KL15_GetDelayTimeFlag()                       (KL15SwitchStatusRecord.DelayTimeFlag)
#define  Get_Pre_KL15_State()                          (KL15SwitchStatusRecord.PreKL15State)
#define  Set_Pre_KL15_State(value)                     (KL15SwitchStatusRecord.PreKL15State = (value))

extern CanFrameCounterType ABS3_counter;
extern CanFrameCounterType ESP_FD2_counter;
extern CanFrameCounterType ECM2_counter;

typedef P2FUNC(void, CANSERVER_CBK_CODE, DTCStoreFuncPtr) (VAR(uint8, AUTOMATIC) EventStatus,VAR(uint8, AUTOMATIC) index);
typedef P2FUNC(boolean, CANSERVER_CBK_CODE, VCfgFunc) (VAR(void, AUTOMATIC));
typedef uint16        Com_RxPduId_Type;
typedef uint16        Com_RxPduId_Map_CanId_Type;
typedef boolean       Com_RxPduId_EnableType;
typedef uint16        Com_RxPdu_SizeOfType;

typedef struct Com_Disable_Pdu_SendorReceive_Tag
{
    uint16     TxPduId[DISABLE_PDU_NUMBER];
}Com_Disable_Pdu_SendorReceive_Info;

typedef struct Com_Disable_RxPdu_Receive_Tag
{
    Com_RxPduId_Type            RxPduId[DISABLE_RX_PDU_NUMBER];
    Com_RxPduId_EnableType      RxPduEnableFlag[DISABLE_RX_PDU_NUMBER];
    Com_RxPduId_Map_CanId_Type  RxPduMapCanId[DISABLE_RX_PDU_NUMBER];
}Com_Disable_RxPdu_Receive_Info;

typedef struct DTC_Status_Tag
{
    uint8     DTC_currStatus[43];
    boolean   DTC_initStatus[43];
    boolean   Service0x14_Execution_Status[43];
    uint16    ReportTimeoutCounter;
    uint8     ReportDTCState[43];
}DTC_Status;

typedef struct RxPdu_DTC_Passed_Mask_Info_Tag
{
    uint8   DTC_MaskValue[3][20];
}RxPdu_DTC_Passed_Mask_Info;

typedef struct RxPdu_DTC_StoreInfo_Tag
{
    uint16      validCnt[43];
    /* Rx Pdu DTC number is 43 */
    boolean    validStatus[43];
    /* Frist Passed Flag */
    boolean    firstPassedFlag[43];
}RxPdu_DTC_StoreInfo;

typedef struct BusOffInfo_Tag
{
    uint16   delayTimer;
    uint8    passedTime;
    uint8    recyCnt;
    boolean  busoffFlag;
}BusOffInfo;

typedef struct VoltageMonitorInfo_Tag
{
    uint16   wakeupDelayMaxTime;
    uint16   T_RestartDelayTime;
    boolean  wakeupFlag;
    boolean  OverORLowVoltageFlag;
    boolean  T_RestartFlag;
    boolean  StartWakeupTimerFlag;
}VoltageMonitorInfo;

typedef struct RxPDUTimeoutInfo_Tag
{
    uint16     rxPduID;
    uint16     timeoutMaxValue;
    uint16     timeoutPassedCntCycTimer;
    uint16     waitMaxTime;
    /* report Passed must grater than the threshold Time */
    uint16     passedCumulativeTime;
    VCfgFunc   VCfgFncPtr;
    uint8      validRecCnt;
    uint8      DTCRefIndex[2];
    boolean    passedFlag;
}RxPDUTimeoutInfo;

typedef struct NoAckingInfo_Tag
{
    uint16 TTimeoutTime;
    uint16 RecoveryTime;
    uint8 NoAckingMaxNumber;
    uint8 CANChannel3ComMUser;
    boolean RecoveryFlag;
    boolean TTimeoutFlag;
}NoAckingInfo;


typedef struct DTCMaskInfo_Tag
{
   uint8  DTCMask[20];
   boolean DTCsMaskFlag;
   DTCStoreFuncPtr  DTCStoreFunc;
}DTCMaskInfo;

typedef struct KL15SwitchStatusInfo_Tag
{
   boolean DelayTimeFlag;
   uint8   PreKL15State;
}KL15SwitchStatus;

typedef struct SecOCBusOffInfo_Tag
{
   boolean BusOffStatusFlag;
}SecOCBusOff;

typedef struct CANFormatErrCfgInfo_Tag
{
   uint32  CANChanErrFlagRegisterAddr;
   uint32  CANChanFormatErrMask;
   uint8   CANChanNum;
   boolean CAN3FormatErrFlag;
}CANFormatErrCfgInfo;

static SecOCBusOff SecOCBusOffReocrd = 
{
   (boolean)FALSE,
};

static KL15SwitchStatus KL15SwitchStatusRecord = 
{
    FALSE, FALSE,
};

static RxPdu_DTC_StoreInfo RxPdu_DTC_StoreRecord[1] = 
{
    {{0x00}, {0x00}, {0x00}},
};

static DTC_Status DTC_Status_Record = 
{
    {0x00},
    {0x00},
    {0x00},
    0,
    {0x00},
};

static uint8 DTC_0xC24387_CfgVehInfo[3] = { 0 };
static uint32 ChangeCounter_0x14 = 0;
static const Com_Disable_Pdu_SendorReceive_Info Com_Disable_Pdu_SendorReceive_Cfg = 
{
    {0x19}, //HUT40
};

static const Com_Disable_RxPdu_Receive_Info Com_Disable_RxPdu_Receive_Cfg = 
{
    /*CSA1  CSA3   BCM6   BCM11*/
    {
        ComConf_ComIPdu_CSA1_oB30_for_SC_CAN_V3_2_bec912dc_Rx,    
        ComConf_ComIPdu_CSA3_oB30_for_SC_CAN_V3_2_9099db5c_Rx,
        ComConf_ComIPdu_BCM6_oB30_for_SC_CAN_V3_2_0115211a_Rx,
        0xFFFF
    }, //PduId in Com Layer
    {FALSE, FALSE, FALSE, FALSE},  //Pdu receive status
    {0x165, 0x244, 0x28C, 0x305},  //CanId
};

Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Record = {{0x0, 0x0, 0x0, 0x0},{FALSE, FALSE, FALSE, FALSE},{0x0, 0x0, 0x0, 0x0}};

#define       CANSERVER_PASSIVE_SWITCH_STATUS              STD_OFF
#define       CAN_CONTROLLER_SWITCH_STATUS                 STD_OFF
#define       COMMUNICATIONMISSINGDTCSTORESWITCH           STD_ON
#define       BUSOFFDTCSTORESWITCH                         STD_OFF
#define       RXMONITORCONDITIONENABLE                     STD_OFF
#define       MONITORRXPUDNUMBER                           ((uint8)(123u))
#define       MONITORRXPUDVALIDMAXNUMBER                   ((uint8)(10u))
#define       MONITORUSER                                  ((uint8)(0x00u))
#define       VEHICLEINFOMATIONCONFIGURATIONNUMBER         ((uint8)200u)
#define       NOACKINGREPETITIONNUMBER                     ((uint8)15u)
#define       NOACKINGADERRMASK                            ((uint8)0x04)
#define       ERR_PASSIVE_MASK                             ((uint8)0x04)

#define       CanServer_SetRxPDUPassedFlag(n,arrRow)              ((PassedFlagRecord[(arrRow)][(n) >> (uint8)3]) |= ((uint8)1 << ((n) & (uint8)0x07)))
#define       CanServer_ResetRxPDUPassedFlag(n,arrRow)            ((PassedFlagRecord[(arrRow)][(n) >> (uint8)3]) &= ~((uint8)1 << ((n) & (uint8)0x07)))
#define       CanServer_SetEventMaskFlag(n,arrRow)                ((MaskValueRecord[(arrRow)][(n) >>   (uint8)3]) |= ((uint8)1 << ((n) & (uint8)0x07)))
#define       CanServer_ResetEventMaskFlag(n,arrRow)              ((MaskValueRecord[(arrRow)][(n) >>   (uint8)3]) &= ~((uint8)1 << ((n) & (uint8)0x07)))
#define       CanServer_SetService0x14executionStatus(value,index)     ((DTC_Status_Record.Service0x14_Execution_Status[index]) = (value))
#define       CanServer_GetService0x14executionStatus(index)           (DTC_Status_Record.Service0x14_Execution_Status[index])

#define       COMDTCNUMBER                                 ((uint8)(43u))
#define       DTCMASKBYTES                                 ((uint8)(20u))
#define       DTC0xC24387POSITION                          ((uint8)(18u))
#define       DTC0xD00487POSITION                          ((uint8)(27u))
#define       RXPDU_DTC_NUM                                ((uint8)(2u))
#define       DTCPASSEDDELAYCNT                            ((uint16)(0u))
#define       DTC_0xC24387_PASSEDDELAYCNT                  ((uint8)(10u))
#define       DTC_MASK_ROW_NUM                             ((uint8)(3u))
#define       BUSOFF_REPORT_MAX_NUM                        ((uint8)(4u))
#define       BUSOFFPASSEDTIMES                            ((uint8)(20u))
#define       BUSOFF_DELAY_RESET_TIME                      ((uint8)(40u))
#define       BUSOFFEND_DELAYTIME                          ((uint8)(100u))
#define       CAN_FORMATERR_NUMBER                         ((uint8)(1u))
#define       DIAG_SYSTEM_POWER_MODE                       ((uint8)(2u))
/*! Avoid warnings of unused API parameters */
#define       CAN_SERVER_IGNORE_UNREF_PARAM(param)         ((void)(param))


#define       CANSERVER_CBK_CODE


#define  	  OVER_VOLTAGE_VALUE							((float64)(16.0f))
#define  	  OVER_VOLTAGE_RECOVER_VALUE					((float64)(15.0f))
#define  	  UNDER_VOLTAGE_VALUE							((float64)(9.0f))
#define  	  UNDER_VOLTAGE_RECOVER_VALUE					((float64)(10.0f))
#define		  NM_RMS_FLAG_INDEX								((uint8)(0u))
#define		  NM_WAKEUP_REASON_INDEX						((uint8)(1u))
#define	      NM_STAY_AWAKE_REASON_INDEX					((uint8)(2u))
#define		  NM_SYSTEM_INFORMATION_INDEX					((uint8)(3u))

#define 	  NM_WKSOURCE_CAN 								((uint8)(32uL)) 
#define 	  NM_WKSOURCE_POWER 							((uint8)(1uL)) 
#define	 	  NM_EcuMWakeupSource_POWER_OFFSET				((uint8)(0u))
#define	 	  NM_EcuMWakeupSource_CAN_OFFSET				((uint8)(5u))

#define		  NM_BIT0										((uint8)(0x01))
#define		  NM_BIT1										((uint8)(0x02))
#define		  NM_BIT2										((uint8)(0x04))
#define		  NM_CLEAR_BITS									((uint8)(0x00))

#define 	  ECUM_WKSOURCE_POWER_MASK						((uint8)((uint8)0x01<<NM_EcuMWakeupSource_POWER_OFFSET))
#define 	  ECUM_WKSOURCE_CAN_WAKEUP_MASK					((uint8)((uint8)0x01<<NM_EcuMWakeupSource_CAN_OFFSET))

#define       WAKEUPDELAYMAXTIME                           ((uint8)(150u))
#define       T_RESTARTDELAYMAXTIME                        ((uint8)(50u))
#define       DelayTimeDecreasing()                        (volMonitInfo[0].wakeupDelayMaxTime)
#define       Set_T_RestartDelayTime(value)                ((volMonitInfo[0].T_RestartDelayTime) = (value))
#define       Get_T_RestartDelayTime()                     (volMonitInfo[0].T_RestartDelayTime)
#define       Set_OverORLowVoltageFlag(value)              ((volMonitInfo[0].OverORLowVoltageFlag) = (value))
#define       Get_OverORLowVoltageFlag()                   (volMonitInfo[0].OverORLowVoltageFlag)
#define       Get_T_RestartFlag()                          (volMonitInfo[0].T_RestartFlag)
#define       Set_T_RestartFlag(value)                     ((volMonitInfo[0].T_RestartFlag) = (value))
#define       Get_ActiveFlag()                             (DiagActiveFlag)
#define       Set_ActiveFlag(value)                        ((DiagActiveFlag) = ((boolean)value))


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10087(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12287(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10187(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00087(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24187(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24287(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10B87(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD02687(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00287(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC16487(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14687(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC13187(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12887(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC20887(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC19987(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC20087(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24687(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24787(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24387(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC2B387(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC19887(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12787(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC29387(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11187(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC1BB87(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10887(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10987(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00487(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10487(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14387(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00987(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC23087(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC15C87(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11587(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD01587(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14187(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD02987(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11487(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC15887(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC23387(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC2B587(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10687(uint8 EventStatus, uint8 index);
static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC25E87(uint8 EventStatus, uint8 index);

static FUNC(boolean, Can_Server_CODE) ABM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ABS3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) AC1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) AC2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ACC_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ACC_FD3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ACC_FD4_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) AEB_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) AEB_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BCM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BCM3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BCM8_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BMS4_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BMS8_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BMS22_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BMS30_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) BMS35_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) CP1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) CR_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) CSA3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DCT3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DCT5_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DCT7_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DDCM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DMS_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) DSM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ECM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ECM2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ECM3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ECM11_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ECM19_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ELD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) EPB1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) EPS1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) EPS_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ESP1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ESP2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ESP8_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) ESP_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) FPAS1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) F_PBox1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) GW_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HAP_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HAP_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HAP_FD3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HC1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_HC3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_HC6_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_HC7_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_PT4_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_PT5_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_PT7_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCU_PT8_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HUD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) Haldex1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) IFC_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) IFC_FD3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) IFC_FD5_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) IFC_FD6_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) Ibooster_FD2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) OBC2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) PDCM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) PEPS2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) PEPS4_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) PLG_1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) RPAS1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) RSDS_FD1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) R_PBox1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) SCM1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) STBS1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) TPMS1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) TPMS2_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) T_Box_FD3_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) Trailer1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) VSG1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) WPC1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCM_R1_VCfgCheck(void);
static FUNC(boolean, Can_Server_CODE) HCM_L1_VCfgCheck(void);

static const DTCMaskInfo DTCMaskRecord[COMDTCNUMBER] = {
    {{0x0 , 0x0 , 0x8 , 0x0 , 0x40 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC10087},//0xC10087_@_0x00
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0xa8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC12287},//0xC12287_@_0x01
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC10187},//0xC10187_@_0x02
    {{0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD00087},//0xD00087_@_0x03
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC24187},//0xC24187_@_0x04
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC24287},//0xC24287_@_0x05
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD10B87},//0xD10B87_@_0x06
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x10 , 0x0 , 0x4 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD02687},//0xD02687_@_0x07
    {{0x0 , 0x0 , 0x80 , 0x4 , 0x1 , 0x0 , 0x90 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD00287},//0xD00287_@_0x08
    {{0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC16487},//0xC16487_@_0x09
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC14687},//0xC14687_@_0x0A
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC13187},//0xC13187_@_0x0B
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC12887},//0xC12887_@_0x0C
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC20887},//0xC20887_@_0x0D
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC19987},//0xC19987_@_0x0E
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC20087},//0xC20087_@_0x0F
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC24687},//0xC24687_@_0x10
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC24787},//0xC24787_@_0x11
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x20 , 0x3 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC24387},//0xC24387_@_0x12
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC2B387},//0xC2B387_@_0x13
    {{0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC19887},//0xC19887_@_0x14
    {{0x0 , 0x0 , 0x2 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC12787},//0xC12787_@_0x15
    {{0x0 , 0x10 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC29387},//0xC29387_@_0x16
    {{0x40 , 0x20 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC11187},//0xC11187_@_0x17
    {{0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC1BB87},//0xC1BB87_@_0x18
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD10887},//0xD10887_@_0x19
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD10987},//0xD10987_@_0x1a
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD00487},//0xD00487_@_0x1B
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x7 , 0x0 , 0x0 , 0x20 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC10487},//0xC10487_@_0x1c
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x42 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC14387},//0xC14387_@_0x1D
    {{0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD00987},//0xD00987_@_0x1E
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC23087},//0xC23087_@_0x1f
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x7 , 0x0 , 0x0 , 0x62 , 0x20 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC15C87},//0xC15C87_@_0x20
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC11587},//0xC11587_@_0x21
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD01587},//0xD01587_@_0x22
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC14187},//0xC14187_@_0x23
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD02987},//0xD02987_@_0x24
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC11487},//0xC11487_@_0x25
    {{0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC15887},//0xC15887_@_0x26
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC23387},//0xC23387_@_0x27
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC2B587},//0xC2B587_@_0x28
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xD10687},//0xD10687_@_0x29
    {{0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, FALSE, DTCStoreFunc_0xC25E87},//0xC25E87_@_0x2A
};

static const RxPDUTimeoutInfo MonitorPduIdTimeoutValue[MONITORRXPUDNUMBER] = 
{
    {CanIfConf_CanIfRxPduCfg_NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx ,1000, 200, 500, 0, BMS30_VCfgCheck, 0, { 0x17, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_T_Box_FD3_Sc_oB30_for_SC_CAN_V3_2_be0a3640_Rx ,1000, 200, 500, 0, T_Box_FD3_VCfgCheck, 0, { 0x14, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_TMCU_FD3_oB30_for_SC_CAN_V3_2_481b1f14_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx ,1000, 200, 500, 0, HCU_HC7_VCfgCheck, 0, { 0x16, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx ,1000, 200, 500, 0, BMS22_VCfgCheck, 0, { 0x17, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AMP5_IESS1_oB30_for_SC_CAN_V3_2_6a7e89d2_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx ,500, 100, 500, 0, TPMS2_VCfgCheck, 0, { 0x15, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx ,100, 20, 500, 0, AC2_VCfgCheck, 0, { 0x09, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx ,100, 20, 500, 0, ECM3_VCfgCheck, 0, { 0x00, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx ,500, 100, 500, 0, CP1_VCfgCheck, 0, { 0x1E, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx ,500, 100, 500, 0, ABM1_VCfgCheck, 0, { 0x03, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx ,50, 10, 500, 0, BCM3_VCfgCheck, 0, { 0x08, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx ,500, 100, 500, 0, TPMS1_VCfgCheck, 0, { 0x15, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx ,200, 40, 500, 0, HUD1_VCfgCheck, 0, { 0x26, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx ,50, 10, 500, 0, BCM1_VCfgCheck, 0, { 0x08, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx ,200, 40, 500, 0, OBC2_VCfgCheck, 0, { 0x18, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx ,200, 40, 500, 0, HCU_HC6_VCfgCheck, 0, { 0x16, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx ,200, 40, 500, 0, PEPS4_VCfgCheck, 0, { 0x08, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_PLG_1_oB30_for_SC_CAN_V3_2_9256d283_Rx ,100, 20, 500, 0, PLG_1_VCfgCheck, 0, { 0x1f, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx ,100, 20, 500, 0, HCU_PT4_VCfgCheck, 0, { 0x07, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_RPAS2_oB30_for_SC_CAN_V3_2_9ad6b778_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_VSG1_oB30_for_SC_CAN_V3_2_ef738777_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx ,100, 20, 500, 0, ECM11_VCfgCheck, 0, { 0x00, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx ,100, 20, 500, 0, SCM1_VCfgCheck, 0, { 0x10, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx ,100, 20, 500, 0, IFC_FD3_VCfgCheck, 0, { 0x1D, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx ,100, 20, 500, 0, PDCM1_VCfgCheck, 0, { 0x0F, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx ,100, 20, 500, 0, DDCM1_VCfgCheck, 0, { 0x0E, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx ,100, 20, 500, 0, BMS35_VCfgCheck, 0, { 0x17, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx ,100, 20, 500, 0, DSM1_VCfgCheck, 0, { 0x0D, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx ,100, 20, 500, 0, GW_FD1_VCfgCheck, 0, { 0x0A, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx ,100, 20, 500, 0, WPC1_VCfgCheck, 0, { 0x24, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx ,100, 20, 500, 0, ACC_FD4_VCfgCheck, 0, { 0x1c, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx ,100, 20, 500, 0, ACC_FD3_VCfgCheck, 0, { 0x1c, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx ,100, 20, 500, 0, ACC_FD2_VCfgCheck, 0, { 0x1c, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx ,100, 20, 500, 0, BCM8_VCfgCheck, 0, { 0x08, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx ,100, 20, 500, 0, AC1_VCfgCheck, 0, { 0x09, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx ,100, 20, 500, 0, HAP_FD3_VCfgCheck, 0, { 0x12, 0x1B}, FALSE},
    {CanIfConf_CanIfRxPduCfg_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx ,50, 10, 500, 0, PEPS2_VCfgCheck, 0, { 0x08, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BCM6_oB30_for_SC_CAN_V3_2_f11643ac_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HC1_oB30_for_SC_CAN_V3_2_f63a95a4_Rx ,100, 20, 500, 0, HC1_VCfgCheck, 0, { 0x04, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx ,100, 20, 500, 0, BMS8_VCfgCheck, 0, { 0x17, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx ,50, 10, 500, 0, HAP_FD2_VCfgCheck, 0, { 0x12, 0x1B}, FALSE},
    {CanIfConf_CanIfRxPduCfg_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx ,50, 10, 500, 0, Trailer1_VCfgCheck, 0, { 0x23, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx ,20, 4, 500, 0, ECM2_VCfgCheck, 0, { 0x00, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx ,100, 20, 500, 0, RPAS1_VCfgCheck, 0, { 0x12, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx ,100, 20, 500, 0, FPAS1_VCfgCheck, 0, { 0x12, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx ,50, 10, 500, 0, HCU_HC3_VCfgCheck, 0, { 0x16, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ABS3_oB30_for_SC_CAN_V3_2_961138dc_Rx ,20, 4, 500, 0, ABS3_VCfgCheck, 0, { 0x01, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_Haldex1_oB30_for_SC_CAN_V3_2_bbae6b8e_Rx ,20, 4, 500, 0, Haldex1_VCfgCheck, 0, { 0x25, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx ,50, 10, 500, 0, HCU_PT7_VCfgCheck, 0, { 0x07, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx ,50, 10, 500, 0, CSA3_VCfgCheck, 0, { 0x29, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx ,50, 10, 500, 0, IFC_FD2_VCfgCheck, 0, { 0x1D, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DCT7_Sc_oB30_for_SC_CAN_V3_2_5c786cc5_Rx ,50, 10, 500, 0, DCT7_VCfgCheck, 0, { 0x02, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx ,50, 10, 500, 0, AEB_FD2_VCfgCheck, 0, { 0x1c, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx ,50, 10, 500, 0, IFC_FD6_VCfgCheck, 0, { 0x1D, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_STBS1_oB30_for_SC_CAN_V3_2_3fe5270b_Rx ,50, 10, 500, 0, STBS1_VCfgCheck, 0, { 0x22, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_T_Box_FD4_oB30_for_SC_CAN_V3_2_f496a4b1_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx ,50, 10, 500, 0, HCU_PT8_VCfgCheck, 0, { 0x07, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx ,50, 10, 500, 0, IFC_FD5_VCfgCheck, 0, { 0x1D, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_R_PBox1_Sc_oB30_for_SC_CAN_V3_2_79c76dd7_Rx ,50, 10, 500, 0, R_PBox1_VCfgCheck, 0, { 0x1a, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_F_PBox1_oB30_for_SC_CAN_V3_2_cb257250_Rx ,50, 10, 500, 0, F_PBox1_VCfgCheck, 0, { 0x19, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx ,20, 4, 500, 0, AEB_FD1_VCfgCheck, 0, { 0x1c, 0x20}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx ,20, 4, 500, 0, RSDS_FD1_VCfgCheck, 0, { 0x27, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx ,20, 4, 500, 0, EPB1_VCfgCheck, 0, { 0x0C, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_EPS1_oB30_for_SC_CAN_V3_2_a33fe139_Rx ,20, 4, 500, 0, EPS1_VCfgCheck, 0, { 0x0B, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_EPS2_oB30_for_SC_CAN_V3_2_7018c07d_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx ,20, 4, 500, 0, CR_FD1_VCfgCheck, 0, { 0x28, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx ,20, 4, 500, 0, HAP_FD1_VCfgCheck, 0, { 0x12, 0x1B}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx ,20, 4, 500, 0, ELD1_VCfgCheck, 0, { 0x21, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx ,20, 4, 500, 0, HCU_PT5_VCfgCheck, 0, { 0x07, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP1_Sc_oB30_for_SC_CAN_V3_2_c7573a5b_Rx ,20, 4, 500, 0, ESP1_VCfgCheck, 0, { 0x01, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx ,20, 4, 500, 0, EPS_FD1_VCfgCheck, 0, { 0x0B, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP2_Sc_oB30_for_SC_CAN_V3_2_12ed4148_Rx ,20, 4, 500, 0, ESP2_VCfgCheck, 0, { 0x01, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM10_oB30_for_SC_CAN_V3_2_6dcbec2b_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP_FD2_oB30_for_SC_CAN_V3_2_9a8b8a42_Rx ,20, 4, 500, 0, ESP_FD2_VCfgCheck, 0, { 0x01, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx ,20, 4, 500, 0, Ibooster_FD2_VCfgCheck, 0, { 0x2A, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx ,10, 2, 500, 0, ECM1_VCfgCheck, 0, { 0x00, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx ,10, 2, 500, 0, BMS4_VCfgCheck, 0, { 0x17, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP10_oB30_for_SC_CAN_V3_2_119f3682_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DHT_FD1_oB30_for_SC_CAN_V3_2_e564e605_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx ,10, 2, 500, 0, DCT3_VCfgCheck, 0, { 0x02, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_TMCU6_oB30_for_SC_CAN_V3_2_e6ceb015_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM8_oB30_for_SC_CAN_V3_2_a98d7fca_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx ,10, 2, 500, 0, HCU_FD1_VCfgCheck, 0, { 0x07, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
    {CanIfConf_CanIfRxPduCfg_T_Box_FD1_Sc_oB30_for_SC_CAN_V3_2_d763f605_Rx , 0, 0, 0, 0, NULL_PTR, 0, { 0xFF, 0xFF}, FALSE},
};

static const RxPdu_DTC_Passed_Mask_Info RxPdu_DTC_Passed_MaskRecord[COMDTCNUMBER] = 
{
    /* 0xC10087  index:0x00 */
    {{    	
         {0x0 , 0x0 , 0x8 , 0x0 , 0x40 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
		 {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC12287  index:0x01 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x28 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
      
    /* 0xC10187  index:0x02 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
  
    /* 0xD00087  index:0x03 */
    {{
         {0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC24187  index:0x04 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC24287  index:0x05 */
    {{
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD10B87  index:0x06 */
    {{
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD02687  index:0x07 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x10 , 0x0 , 0x4 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD00287  index:0x08 */
    {{
         {0x0 , 0x0 , 0x80 , 0x4 , 0x1 , 0x0 , 0x90 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC16487  index:0x09 */
    {{
         {0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC14687  index:0x0A */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC13187  index:0x0B */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC12887  index:0x0C */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC20887  index:0x0D */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC19987  index:0x0E */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC20087  index:0x0F */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC24687  index:0x10 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC24787  index:0x11 */
    {{
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC24387  index:0x12 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x20 , 0x3 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x3 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 } 
    }},
    /* 0xC2B387  index:0x13 */
    {{
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC19887  index:0x14 */
    {{
         {0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC12787  index:0x15 */
    {{
         {0x0 , 0x0 , 0x2 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC29387  index:0x16 */
    {{
         {0x0 , 0x10 , 0x0 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC11187  index:0x17 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0x40 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC1BB87  index:0x18 */
    {{
         {0x0 , 0x0 , 0x0 , 0x8 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD10887  index:0x19 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD10987  index:0x1a */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD00487  index:0x1B */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC10487  index:0x1c */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x7 , 0x0 , 0x0 , 0x20 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC14387  index:0x1D */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x42 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD00987  index:0x1E */
    {{
         {0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC23087  index:0x1f */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC15C87  index:0x20 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x7 , 0x0 , 0x0 , 0x62 , 0x20 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC11587  index:0x21 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD01587  index:0x22 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC14187  index:0x23 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD02987  index:0x24 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC11487  index:0x25 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x10 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC15887  index:0x26 */
    {{
         {0x0 , 0x0 , 0x0 , 0x2 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC23387  index:0x27 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x4 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC2B587  index:0x28 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xD10687  index:0x29 */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
    /* 0xC25E87  index:0x2A */
    {{
         {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 }, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 
         {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} 
    }},
};

static uint8 VConfigInfo[400] = {0x00};
static RxPDUTimeoutInfo MonitorPduIdTimeoutCurrentValue[MONITORRXPUDNUMBER] = {0};
static VoltageMonitorInfo volMonitInfo[1] = {{0x00,0x00,FALSE,FALSE,FALSE,FALSE}};
static uint8*  Chn3TECAddr = ((uint8*)(0xFFD0003B));
static uint8*  Chn3ADERRAddr = ((uint8*)(0xFFD0003D));
static uint8*  Chn3PASSIVEERRAddr = ((uint8*)(0xFFD0003C));
static NoAckingInfo NoAckingRecordInfo[1] = {{15u, 15u, 0x80, 0u, FALSE, FALSE}};
static uint8  MaskValueRecord[RXPDU_DTC_NUM][DTCMASKBYTES] = {0x00};
static boolean  DTCFlagRecord[COMDTCNUMBER] = {0x00};
static uint8  PassedFlagRecord[RXPDU_DTC_NUM][DTCMASKBYTES] = {0x00};
static uint8  MaskValueRecordDTC0xC24387_2[DTCMASKBYTES] = {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x3 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0};
static uint8  MaskValueRecordDTC0xC24387_3[DTCMASKBYTES] = {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x40 , 0x0 , 0x1 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0};
static BusOffInfo BusOffRecord[1] = {{0x00,BUSOFFPASSEDTIMES, 0x00,FALSE}};
static boolean DiagActiveFlag = FALSE;
static boolean CANFormatErrFlg[CAN_FORMATERR_NUMBER] = {FALSE}; /* use for CAN format err print log*/
static boolean preMTCndtFlag = TRUE; /* use for recording previous monitor condition status */
static uint8 PrestatusBusOff = 0u;


/* can format error cfg information*/
const static CANFormatErrCfgInfo CANFormatErrCfgInfoRecord[CAN_FORMATERR_NUMBER] = 
{
    /* Channel Error Flag Register Address, Format Error mask, Can Cannel Num, format error flag */
    {  0xFFD0003C,                          0x00000200,        3,              FALSE}, //CAN3
};

static boolean DTCMaskCurrentFlagRecord[COMDTCNUMBER] = {0x00};
static FUNC(void, CANSM_CODE) CanServer_SetEcuPassive( boolean CanSM_TxOfflineActive );
extern FUNC(void, COM_APPL_CODE) SECOC_PDU_Message_ReqSet(boolean flag);
extern VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NOINIT) CanSM_ChannelVarRecord[1];

static FUNC(void , Can_Server_CODE) CanServer_RxPDUTimeoutInit(void);
static FUNC(void , Can_Server_CODE) CanServer_RxPDUTimeoutHandler(void);
static FUNC(boolean , Can_Server_CODE) CanServer_MonitorConditionCheck(void);
static FUNC(void , Can_Server_CODE) CanServer_SetWakeupFlag(boolean wakeupSts);
static FUNC(boolean , Can_Server_CODE) CanServer_GetWakeupFlag(void);
static FUNC(void , Can_Server_CODE) CanServer_SetDelayMonitorTime(uint16 delayTime);
static FUNC(void , Can_Server_CODE) CanServer_DelayMonitorTimeHandler(void);
static FUNC(void , Can_Server_CODE) CanServer_NoAckingHandle(void);
static FUNC(uint8* , Can_Server_CODE) CanServer_GetVIfnoPtr(void);
static FUNC(void , Can_Server_CODE) CanServer_DTCStoreHandler(void);
static FUNC(void , Can_Server_CODE) CanServer_DTC0xC24387Handler(uint8 index);
static FUNC(void , Can_Server_CODE) CanServer_DTC0xC24387PassedHandler(void);
static FUNC(void , Can_Server_CODE) CanServer_BusOffDTCStoreHandler(void);
static FUNC(void , Can_Server_CODE) CanServer_DTCPasssedHandler(void);
static FUNC(boolean , Can_Server_CODE) CanServer_DiagVoltageConditionCheck(void);
static FUNC(void , Can_Server_CODE) CanServer_DiagVoltageHandler(void);
static FUNC(void, Can_Server_CODE) CanServer_FormatErrorHandle(void);
static FUNC(void , Can_Server_CODE) CanServer_DTCMonitorReset(void);
static FUNC(void , Can_Server_CODE) CanServer_Service0x14_Discovery(void);
static FUNC(void , Can_Server_CODE) CanServer_KL15Off_Handler(void);
static FUNC(void, Can_Server_CODE) Com_IPduReceiveCallout_Init(void);
static FUNC(void , Can_Server_CODE) CanServer_BusOffInit(void);
FUNC(boolean, Can_Server_CODE) Com_IPduEnableHandle(uint16 CanId, boolean EnableFlag);

FUNC(void , Can_Server_CODE) CanServer_SecOCBusOffEndStatusSet(boolean busoffEndFlag);
FUNC(boolean , Can_Server_CODE) CanServer_SecOCBusOffEndStatusGet(void);
static FUNC(void, Can_Server_CODE) CanServer_FormatErrorInit(void);
static FUNC(void , Can_Server_CODE) CanServer_ReportDTCStateCycle(void);
FUNC(void , Can_Server_CODE) CanServer_CanIfRxPDUTimeoutMonitor(PduIdType CanIfRxPduId, uint8 CanDlc);
FUNC(boolean, COM_APPL_CODE) Com_IPduTransmitCallout(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
static FUNC(void , Can_Server_CODE) CanServer_BusOffForSecocMainFunction(void);


static CNA_Type cna = {0};

static Std_ReturnType CNA_Init(const CNA_ConfigType *config);
static Std_ReturnType CNA_DeInit(void);
static void CNA_BehaviorNoneHandle(uint16 signalId);
static void CNA_BehaviorUnsendHandle(uint16 signalId);
static void CNA_BehaviorSendHandle(uint16 signalId);
static void CNA_BehaviorCycleHandle(uint16 signalId);

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
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DebounceResetStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DEBOUNCE_STATUS_FREEZE (0U)
 *   DEM_DEBOUNCE_STATUS_RESET (1U)
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
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_UDS_STATUS_TF (1U)
 *   DEM_UDS_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_UDS_STATUS_TF_BflPn 0
 *   DEM_UDS_STATUS_TF_BflLn 1
 *   DEM_UDS_STATUS_TFTOC (2U)
 *   DEM_UDS_STATUS_TFTOC_BflMask 2U (0b00000010)
 *   DEM_UDS_STATUS_TFTOC_BflPn 1
 *   DEM_UDS_STATUS_TFTOC_BflLn 1
 *   DEM_UDS_STATUS_PDTC (4U)
 *   DEM_UDS_STATUS_PDTC_BflMask 4U (0b00000100)
 *   DEM_UDS_STATUS_PDTC_BflPn 2
 *   DEM_UDS_STATUS_PDTC_BflLn 1
 *   DEM_UDS_STATUS_CDTC (8U)
 *   DEM_UDS_STATUS_CDTC_BflMask 8U (0b00001000)
 *   DEM_UDS_STATUS_CDTC_BflPn 3
 *   DEM_UDS_STATUS_CDTC_BflLn 1
 *   DEM_UDS_STATUS_TNCSLC (16U)
 *   DEM_UDS_STATUS_TNCSLC_BflMask 16U (0b00010000)
 *   DEM_UDS_STATUS_TNCSLC_BflPn 4
 *   DEM_UDS_STATUS_TNCSLC_BflLn 1
 *   DEM_UDS_STATUS_TFSLC (32U)
 *   DEM_UDS_STATUS_TFSLC_BflMask 32U (0b00100000)
 *   DEM_UDS_STATUS_TFSLC_BflPn 5
 *   DEM_UDS_STATUS_TFSLC_BflLn 1
 *   DEM_UDS_STATUS_TNCTOC (64U)
 *   DEM_UDS_STATUS_TNCTOC_BflMask 64U (0b01000000)
 *   DEM_UDS_STATUS_TNCTOC_BflPn 6
 *   DEM_UDS_STATUS_TNCTOC_BflLn 1
 *   DEM_UDS_STATUS_WIR (128U)
 *   DEM_UDS_STATUS_WIR_BflMask 128U (0b10000000)
 *   DEM_UDS_STATUS_WIR_BflPn 7
 *   DEM_UDS_STATUS_WIR_BflLn 1
 * KL30BRelaySts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * RemoteModSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_mode (0U)
 *   Cx1_Remote_mode (1U)
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
 * Rte_DT_SystemState_RecordType_7_0: Enumeration of integer in interval [0...255] with enumerators
 *   TEMP_LOW_SLEEP (0U)
 *   TEMP_NORMAL (1U)
 *   TEMP_HIGH_PROTECT (2U)
 *   TEMP_HIGH_SLEEP (3U)
 *   TEMP_STATE_NUM (4U)
 *   TEMP_STATE_INIT (255U)
 * SysPowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ACC_reserved_ (1U)
 *   Cx2_ON (2U)
 *   Cx3_Crank (3U)
 * SysPowerModVld: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 * wakeup_type: Enumeration of integer in interval [0...18446744073709551615] with enumerators
 *   value0 (0U)
 *   bit1 (1U)
 *   bit2 (2U)
 *
 * Array Types:
 * ============
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CanFrameCounterType: Record with elements
 *   Counter of type uint16
 *   Data of type uint16
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


#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CNA_SignalSet
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CNA_SignalSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CNA_SignalSet(uint16 signalId, uint8 *value)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CNA_SignalSet_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSet (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if((signalId >= cna.config->signalNumber) || (NULL_PTR == value))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
        uint16 index; 

        can_warn("CNA ID=%d",signalId);

        /* set counter */
        if(CNA_BEHAVIOR_SEND == signalCfg->actiontype)
        {
            cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u;
        }
        else
        {
            cna.config->signalDatas[signalId].counter = signalCfg->repetition;
        }

        for(index = 0u; index < cna.config->signalConfigs[signalId].currentSize; index++)
        {
            cna.config->currentBuffer[signalCfg->currentStart + index] = ((uint8 *)value)[index];
        }

        if(CNA_BEHAVIOR_CYCLE == signalCfg->actiontype)
        {
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, value);
        }
        /* trigger transmit */
        (void)Com_SendSignal(signalCfg->comSignalId, (void*)value);
        if(CNA_BEHAVIOR_CYCLE != signalCfg->actiontype)
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSetNoTrigger(uint16 signalId, P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CNA_SignalSetNoTrigger (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = RTE_E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if((signalId >= cna.config->signalNumber) || (NULL_PTR == value))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
        uint16 index; 

        /* set counter */
        if(CNA_BEHAVIOR_SEND == signalCfg->actiontype)
        {
            cna.config->signalDatas[signalId].counter = (signalCfg->repetition << 1) - 1u;
        }
        else
        {
            cna.config->signalDatas[signalId].counter = signalCfg->repetition;
        }

        for(index = 0u; index < cna.config->signalConfigs[signalId].currentSize; index++)
        {
            cna.config->currentBuffer[signalCfg->currentStart + index] = ((uint8 *)value)[index];
        }

        if(CNA_BEHAVIOR_CYCLE == signalCfg->actiontype)
        {
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, value);
        }
        
        (void)Com_SendSignal(signalCfg->comSignalId, (void*)value);
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ABS3_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ABS3_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ABS3_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ABS3_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ABS3_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
	counter->Counter = ABS3_counter.Counter;
	counter->Data = ABS3_counter.Data;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ECM2_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ECM2_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ECM2_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ECM2_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ECM2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
    counter->Counter = ECM2_counter.Counter;
	counter->Data = ECM2_counter.Data;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanFrameCounter_Can_ESP_FD2_Counter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Can_ESP_FD2_Counter> of PortPrototype <CanFrameCounter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CanFrameCounter_Can_ESP_FD2_Counter(CanFrameCounterType *counter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ESP_FD2_Counter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanFrameCounter_Can_ESP_FD2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) counter) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
	counter->Counter = ESP_FD2_counter.Counter;
	counter->Data = ESP_FD2_counter.Data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanServer_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_Init
 *********************************************************************************************************************/
    Std_ReturnType ret_cna = E_OK;
    
    CanServer_RxPDUTimeoutInit();
    CanServer_SecOCBusOffEndStatusSet(FALSE);
    ret_cna = CNA_Init(&cna_config);
    Com_IPduReceiveCallout_Init();
    CanServer_BusOffInit();
    CanServer_FormatErrorInit();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30BRelaySts *data)
 *   Std_ReturnType Rte_Read_RemoteModSts_RemoteModSts(RemoteModSts *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_SysPowerModVld_SysPowerModVld(SysPowerModVld *data)
 *   Std_ReturnType Rte_Read_rpSR_WakeupReason_data(wakeup_type *data)
 *   Std_ReturnType Rte_Read_tiSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_TransmitSignal_Callback(uint32 SignalIndex, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT32_CallBack(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventExtendedDataRecordEx(uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFailed(boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventFreezeFrameDataEx(uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL, RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventTested(boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetEventUdsStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_GetFaultDetectionCounter(sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE, RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventDebounceStatus(Dem_DebounceResetStatusType DebounceResetStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_ResetEventStatus(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, Can_Server_CODE) CanServer_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction
 *********************************************************************************************************************/
    CanServer_RxPDUTimeoutHandler();
    CanServer_DTCStoreHandler();
    CanServer_DelayMonitorTimeHandler();
    CanServer_NoAckingHandle();
    CanServer_ReportDTCStateCycle();
    CanServer_BusOffForSecocMainFunction();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanServer_MainFunction_5ms
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
 *   Std_ReturnType Rte_Read_ClearDTC_Service0x14_StatusFlag(uint8 *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_5ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Can_Server_CODE) CanServer_MainFunction_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanServer_MainFunction_5ms
 *********************************************************************************************************************/
    CanServer_BusOffDTCStoreHandler();
    CanServer_DiagVoltageHandler();
    CanServer_FormatErrorHandle();
    CanServer_Service0x14_Discovery();
    CanServer_KL15Off_Handler();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Can_Server_STOP_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static FUNC(void , Can_Server_CODE) CanServer_BusOffDTCStoreHandler(void)
{
    const static NetworkHandleType  NetworkHandle = 0x00;
    Std_ReturnType ret = E_NOT_OK;
    Std_ReturnType failedRet = E_NOT_OK;
    Std_ReturnType passRet   = E_NOT_OK;
    CanSM_BorStateType CanSM_BorStatePtr[1] = {0};
    static uint8 BusOffReportedState = DEM_EVENT_STATUS_PASSED;

    ret = CanSM_CheckBorLevel (NetworkHandle, CanSM_BorStatePtr);
    if((E_OK == ret) && (CANSM_BOR_NONE == CanSM_BorStatePtr[0]) && Get_ActiveFlag())
    {
        if(Busoff_GetPassedTime(BUSOFF_CONTROLLER_0) > 0)
        {
            Busoff_PassedTimeDecrease(BUSOFF_CONTROLLER_0);
            
            if(Busoff_GetPassedTime(BUSOFF_CONTROLLER_0) == 0x00)
            {
                /*Passed*/
                Busoff_SetPassedTime(BUSOFF_CONTROLLER_0, BUSOFFPASSEDTIMES);
                Busoff_SetBorFlag(BUSOFF_CONTROLLER_0, FALSE);
                passRet = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_PASSED);
                if(DEM_EVENT_STATUS_FAILED == BusOffReportedState)
                {
                    BusOffReportedState = DEM_EVENT_STATUS_PASSED;
                    can_warn("BusOff DTC report pass!");
                }
            }
        }
    }
    else
    {
        Busoff_SetPassedTime(BUSOFF_CONTROLLER_0, BUSOFFPASSEDTIMES);
    }
    
    if((Busoff_GetFastBoCnt(BUSOFF_CONTROLLER_0) >= BUSOFF_REPORT_MAX_NUM) && Get_ActiveFlag())
    {
       failedRet = Rte_Call_DiagnosticMonitor_BusOff_0xC07388_SetEventStatus(DEM_EVENT_STATUS_FAILED);
       if(E_OK == failedRet)
       {
           Busoff_SetPassedTime(BUSOFF_CONTROLLER_0, BUSOFFPASSEDTIMES);
           Busoff_SetFastBoCnt(BUSOFF_CONTROLLER_0, 0x00);
           if(DEM_EVENT_STATUS_PASSED == BusOffReportedState)
           {
               BusOffReportedState = DEM_EVENT_STATUS_FAILED;
               can_warn("BusOff DTC report fail!");
           }
       }
    }

    if(Busoff_GetDelayTime(BUSOFF_CONTROLLER_0) > 0)
    {
        Busoff_DelayTimeDecrease(BUSOFF_CONTROLLER_0);
        if(Busoff_GetDelayTime(BUSOFF_CONTROLLER_0) == 0)
        {
            Busoff_SetFastBoCnt(BUSOFF_CONTROLLER_0, 0x00);
            Busoff_SetBorFlag(BUSOFF_CONTROLLER_0, FALSE);
        }
    }
}


FUNC(void, CANSM_APPL_CODE) CanServer_BusOffEnd( NetworkHandleType  NetworkHandle )
{
    NetworkHandle = NetworkHandle;
    
    Busoff_SetBorFlag(BUSOFF_CONTROLLER_0, FALSE);
}

FUNC(void, CANSM_APPL_CODE) CanServer_BusOffBegin( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr )
{
    CanSM_BorStateType       CanSM_BorStatePtr[1] = {0};
    Std_ReturnType           ret = E_NOT_OK;

    OnlineDelayCyclesPtr = OnlineDelayCyclesPtr;
    
    ret = CanSM_CheckBorLevel (NetworkHandle, CanSM_BorStatePtr);
    Busoff_SetDelayTime(BUSOFF_CONTROLLER_0, BUSOFF_DELAY_RESET_TIME);

    if ((E_OK == ret) && (0x00 == NetworkHandle) && (CANSM_BOR_LEVEL1 == (CanSM_BorStatePtr[0])))
    {
         Busoff_FastBoCntIncrease(BUSOFF_CONTROLLER_0);
    }

    Busoff_SetBorFlag(BUSOFF_CONTROLLER_0, TRUE);
}

static FUNC(void , Can_Server_CODE) CanServer_BusOffInit(void)
{
    Busoff_SetPassedTime(BUSOFF_CONTROLLER_0, BUSOFFPASSEDTIMES);
    Busoff_SetDelayTime(BUSOFF_CONTROLLER_0, 0x00);
    Busoff_SetBorFlag(BUSOFF_CONTROLLER_0, FALSE);
    Busoff_SetFastBoCnt(BUSOFF_CONTROLLER_0, 0x00);
}

static FUNC(void , Can_Server_CODE) CanServer_BusOffForSecocMainFunction(void)
{
    Std_ReturnType     retBor = E_NOT_OK;
    CanSM_BorStateType bor    = CANSM_BOR_NONE;
    uint8   KL15RetValue = 0xFF;
    uint8   KL15Data  = 0x00;
        
    KL15RetValue = Rte_Read_SysPowerMod_SysPowerMod(&KL15Data);

    retBor = CanSM_CheckBorLevel(0u, &bor);

    if((E_OK == retBor) && (KL15RetValue == RTE_E_OK) && (KL15Data == DIAG_SYSTEM_POWER_MODE))
    {
        if((CANSM_BOR_NONE == bor) && (CANSM_BOR_NONE != PrestatusBusOff))
        {
            CanServer_SecOCBusOffEndStatusSet(TRUE);
        }
        
        PrestatusBusOff = bor;
    }
}


static FUNC(void , Can_Server_CODE) CanServer_NoAckingHandle(void)
{
    boolean         diagSts = FALSE;
    Std_ReturnType  retval = E_NOT_OK;

    diagSts = CanServer_DiagVoltageConditionCheck();

    if (
       ((*Chn3TECAddr) >= NoAckingRecordInfo[0].NoAckingMaxNumber) 
    && (NoAckingRecordInfo[0].TTimeoutFlag == FALSE)
    && (NoAckingRecordInfo[0].RecoveryFlag == FALSE)
    && (((*Chn3ADERRAddr) & NOACKINGADERRMASK) != FALSE) 
    && (((*Chn3PASSIVEERRAddr) & ERR_PASSIVE_MASK) != FALSE)
    && ((boolean)TRUE == diagSts)
    )
    {
        NoAckingRecordInfo[0].TTimeoutFlag = TRUE;
        NoAckingRecordInfo[0].TTimeoutTime = NOACKINGREPETITIONNUMBER;
    }
        
    if((NoAckingRecordInfo[0].TTimeoutFlag == TRUE) && (NoAckingRecordInfo[0].TTimeoutTime > 0))
    {
        NoAckingRecordInfo[0].TTimeoutTime--;
        if( 0x00 == NoAckingRecordInfo[0].TTimeoutTime)
        {
            NoAckingRecordInfo[0].TTimeoutFlag = FALSE;
            NoAckingRecordInfo[0].RecoveryFlag = TRUE;
            NoAckingRecordInfo[0].RecoveryTime = NOACKINGREPETITIONNUMBER;
            CanServer_SetEcuPassive(TRUE);
            retval = CanIf_SetControllerMode(NoAckingRecordInfo[0].CANChannel3ComMUser, CANIF_CS_STOPPED);
            #if (CAN_CONTROLLER_SWITCH_STATUS == STD_ON)
                can_info("CANChannel3ComMUser: CanIf Set Controller Mode to CANIF_CS_STOPPED");
            #endif
        }
    }
        
    if((NoAckingRecordInfo[0].RecoveryFlag == TRUE) && (NoAckingRecordInfo[0].RecoveryTime > 0))
    {
        NoAckingRecordInfo[0].RecoveryTime--;
        if( 0x00 == NoAckingRecordInfo[0].RecoveryTime)
        {
            NoAckingRecordInfo[0].RecoveryFlag = FALSE;
            CanServer_SetEcuPassive(FALSE);
            retval = CanIf_SetControllerMode(NoAckingRecordInfo[0].CANChannel3ComMUser, CANIF_CS_STARTED);
            #if (CAN_CONTROLLER_SWITCH_STATUS == STD_ON)
                can_info("CANChannel3ComMUser: CanIf Set Controller Mode to CANIF_CS_STARTED");
            #endif
        }
    }
}

static FUNC(uint8* , Can_Server_CODE) CanServer_GetVIfnoPtr(void)
{
    return VConfigInfo;
}
/******************************************************************************/
/**
* @brief               <Com_IPduReceiveCallout>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <PduIdType PduId,PduInfoType PduInfoPtr>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <retValue:type boolean,call the function successful will return TRUE>    
*/
/******************************************************************************/
FUNC(boolean , Can_Server_CODE) CanServer_RxPDUTimeoutMonitor(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;
    Com_RxPdu_SizeOfType   CanIdMapIndex = 0xFF;
    boolean                retValue = (boolean)TRUE;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Cfg;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Local;
    
    Com_Disable_CurrentRxPdu_Cfg = Com_IPduEnable_VarCfgPtr();
    Com_Disable_CurrentRxPdu_Local = Com_IPduEnable_VarPtr();

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        if((Com_Disable_CurrentRxPdu_Cfg.RxPduId[PduIdIndex]) == PduId)
        {
            CanIdMapIndex = PduIdIndex;
        }
    }

    if(CanIdMapIndex != 0xFF)
    {
        if(Com_Disable_CurrentRxPdu_Local.RxPduEnableFlag[CanIdMapIndex])
        {
            /* disable notify Up Layer*/
            retValue = FALSE;
        }
    }
    
    CAN_SERVER_IGNORE_UNREF_PARAM(PduInfoPtr);
    
    return retValue;
}

FUNC(void , Can_Server_CODE) CanServer_CanIfRxPDUTimeoutMonitor(PduIdType CanIfRxPduId, uint8 CanDlc)
{
    boolean vcfgCheckRet = (boolean)FALSE;

    if(CanIfRxPduId < MONITORRXPUDNUMBER)
    {
        /* CanIfRxPduId check to avoid trap*/
        if (NULL_PTR != MonitorPduIdTimeoutValue[CanIfRxPduId].VCfgFncPtr)
        {
            vcfgCheckRet = MonitorPduIdTimeoutValue[CanIfRxPduId].VCfgFncPtr();
        }

        if(
           (MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].timeoutMaxValue > 0)
        && (TRUE == vcfgCheckRet) 
        && (TRUE == CanIf_RxPduConfig[CanIfRxPduId].IsDataChecksumRxPduOfRxPduConfig) 
        && (CanDlc == CanIf_RxPduConfig[CanIfRxPduId].RxPduDlcOfRxPduConfig) 
        )
        {
            MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].timeoutPassedCntCycTimer = MonitorPduIdTimeoutValue[CanIfRxPduId].timeoutPassedCntCycTimer;
            MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].timeoutMaxValue = MonitorPduIdTimeoutValue[CanIfRxPduId].timeoutMaxValue;
            MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].waitMaxTime = MonitorPduIdTimeoutValue[CanIfRxPduId].waitMaxTime;
            MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].validRecCnt++;
        }
        else
        {
            MonitorPduIdTimeoutCurrentValue[CanIfRxPduId].validRecCnt = 0;
        }
    }
    
}


FUNC(boolean , Can_Server_CODE) SECOC_PDU_Message_Received_Callout(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduId = PduId;
    PduInfoPtr = PduInfoPtr;
    /*monitor Secoc Message,set Flag*/
    SECOC_PDU_Message_ReqSet(TRUE);
    
    return TRUE;
}


static FUNC(void , Can_Server_CODE) CanServer_DiagVoltageHandler(void)
{
    boolean  diagSts = FALSE;
    
    diagSts = CanServer_DiagVoltageConditionCheck();
    Set_ActiveFlag(diagSts);
}

static FUNC(void , Can_Server_CODE) CanServer_KL15Off_Handler(void)
{
    uint16  DtcNumIndex = 0x00;
    uint8   KL15RetValue = 0xFF;
    uint8   KL15Data  = 0x00;
        
    KL15RetValue = Rte_Read_SysPowerMod_SysPowerMod(&KL15Data);

    if((KL15RetValue == RTE_E_OK) && (KL15Data != DIAG_SYSTEM_POWER_MODE))
    {
        for(DtcNumIndex = 0; DtcNumIndex < COMDTCNUMBER; DtcNumIndex++)
        {
            DTC_Status_Record.DTC_initStatus[DtcNumIndex] = FALSE;
        }
    }
}

static FUNC(void , Can_Server_CODE) CanServer_Service0x14_Discovery(void)
{
    uint32 localDtcCnt = 0x00;
    Std_ReturnType ret = RTE_E_INVALID;

    ret = Rte_Read_Can_Server_piDiagMonitorReInitFlag_ChangeCounter(&localDtcCnt);

    if((ret == RTE_E_OK) && (localDtcCnt != ChangeCounter_0x14))
    {
        CanServer_DTCMonitorReset();
    }

    ChangeCounter_0x14 = localDtcCnt;
}

static FUNC(boolean , Can_Server_CODE) CanServer_DiagVoltageConditionCheck(void)
{
    SystemState_RecordType data = {0x00};
    Std_ReturnType  volRetSts = RTE_E_INVALID;
    boolean         diagSts = FALSE;

    volRetSts = Rte_Read_tiSR_Power_Out_SystemStateOut(&data);

    if(RTE_E_OK == volRetSts)
    {
        /*T_restart Flag*/
        if ((TRUE == Get_OverORLowVoltageFlag()) && (0x00 == Get_T_RestartDelayTime()) && (Get_T_RestartFlag() == FALSE))
        {
            if ((((float64)10.0) < data.s_PowerVoltage.value) && (((float64)15.0) > data.s_PowerVoltage.value))
            {
                Set_OverORLowVoltageFlag(FALSE);
                diagSts = TRUE;
                CanServer_SetEcuPassive(FALSE);
                #if (CANSERVER_PASSIVE_SWITCH_STATUS == STD_ON)
                    can_info("CanServer Set Ecu Passive Mode to CANIF_SET_TX_ONLINE");
                #endif
                
            }
        }

        if (((((float64)9.0) > data.s_PowerVoltage.value) || (((float64)16.0) < data.s_PowerVoltage.value))
            && (FALSE == CanServer_GetWakeupFlag()) && (((float64)24.0) > data.s_PowerVoltage.value))
        {
            Set_OverORLowVoltageFlag(TRUE);
            Set_T_RestartFlag(TRUE);
            Set_T_RestartDelayTime((uint16)T_RESTARTDELAYMAXTIME);
            CanServer_SetEcuPassive(FALSE);
            #if (CANSERVER_PASSIVE_SWITCH_STATUS == STD_ON)
                can_info("CanServer Set Ecu Passive Mode to CANIF_SET_TX_ONLINE");
            #endif
        }
        else if (((((float64)9.0) > data.s_PowerVoltage.value) || (((float64)16.0) < data.s_PowerVoltage.value))
            && (TRUE == CanServer_GetWakeupFlag()) && (((float64)24.0) > data.s_PowerVoltage.value))
        {
            CanServer_SetEcuPassive(FALSE);
            #if (CANSERVER_PASSIVE_SWITCH_STATUS == STD_ON)
                can_info("CanServer Set Ecu Passive Mode to CANIF_SET_TX_ONLINE");
            #endif
            
        }
        else if((((float64)9.0) < data.s_PowerVoltage.value) && (((float64)16.0) > data.s_PowerVoltage.value)
            && (FALSE == CanServer_GetWakeupFlag()) && (FALSE == Get_OverORLowVoltageFlag()))
        {
            diagSts = TRUE;
            CanServer_SetEcuPassive(FALSE);
            #if (CANSERVER_PASSIVE_SWITCH_STATUS == STD_ON)
                can_info("CanServer Set Ecu Passive Mode to CANIF_SET_TX_ONLINE");
            #endif
        }
        else if(((float64)24.0) < data.s_PowerVoltage.value)
        {
            CanServer_SetEcuPassive(TRUE);
            #if (CANSERVER_PASSIVE_SWITCH_STATUS == STD_ON)
                can_info("CanServer Set Ecu Passive Mode to CANIF_SET_TX_OFFLINE_ACTIVE");
            #endif
        }
        
        if(((((float64)9.0) < data.s_PowerVoltage.value) && (((float64)16.0) > data.s_PowerVoltage.value)) && (TRUE == CanServer_GetWakeupFlag()) 
            && (volMonitInfo[0].StartWakeupTimerFlag == FALSE))
        {
            volMonitInfo[0].StartWakeupTimerFlag = TRUE;
            CanServer_SetDelayMonitorTime(WAKEUPDELAYMAXTIME);
        }
    }
    
    return diagSts;
}

static FUNC(void , Can_Server_CODE) CanServer_SetWakeupFlag(boolean wakeupSts)
{
    volMonitInfo[0].wakeupFlag = wakeupSts;
}

static FUNC(boolean , Can_Server_CODE) CanServer_GetWakeupFlag(void)
{
    return (volMonitInfo[0].wakeupFlag);
}


static FUNC(void , Can_Server_CODE) CanServer_SetDelayMonitorTime(uint16 delayTime)
{
    volMonitInfo[0].wakeupDelayMaxTime = delayTime;
}

static FUNC(void , Can_Server_CODE) CanServer_DelayMonitorTimeHandler(void)
{
    uint8   KL15RetStatus = 0xFF;
    uint8   comRetSts = 0xFF;
    SysPowerMod KL15Value = 0;
    SysPowerMod KL15Data  = 0;
    ComM_ModeType curComSts = 0xFF;

    KL15RetStatus = Rte_Read_SysPowerMod_SysPowerMod(&KL15Data);
    if(KL15RetStatus == RTE_E_OK)
    {
        KL15Value = KL15Data;
    }

    comRetSts = ComM_GetCurrentComMode(0, &curComSts);

    if(E_OK == comRetSts)
    {
         switch(curComSts)
         {
            case COMM_FULL_COMMUNICATION:
            case COMM_SILENT_COMMUNICATION:
                if((Get_Pre_KL15_State() != DIAG_SYSTEM_POWER_MODE) && (KL15Value == DIAG_SYSTEM_POWER_MODE) && (0x00 == Get_T_RestartDelayTime())) 
                {
                    KL15_SetDelayTimeFlag(TRUE);
                    Set_T_RestartDelayTime((uint16)T_RESTARTDELAYMAXTIME);
                }
                break;
            case COMM_NO_COMMUNICATION:
                KL15_SetDelayTimeFlag(TRUE);
                Set_T_RestartDelayTime((uint16)WAKEUPDELAYMAXTIME);
                break;
            default:
                break;
         }
    }

    Set_Pre_KL15_State(KL15Value);

    if((DelayTimeDecreasing() > 0) && (volMonitInfo[0].StartWakeupTimerFlag == TRUE))
    {
        DelayTimeDecreasing()--;
        if( 0 == DelayTimeDecreasing())
        {
            CanServer_SetWakeupFlag(FALSE);
        }
    }

    if((Get_T_RestartDelayTime() > 0) && (TRUE == Get_OverORLowVoltageFlag()) && (FALSE == KL15_GetDelayTimeFlag()))
    {
        Get_T_RestartDelayTime()--;
        if (0 == Get_T_RestartDelayTime())
        {
            Set_T_RestartFlag(FALSE);
        }
    }
        
    /*KL15 Off -> On,delay 500ms to monitor Rx PDU*/
    if((Get_T_RestartDelayTime() > 0) && KL15_GetDelayTimeFlag())
    {
        Get_T_RestartDelayTime()--;
        if (0 == Get_T_RestartDelayTime())
        {
            KL15_SetDelayTimeFlag(FALSE);

            /* Defect : V35-55356 */ 
            /* 上电1.5s内调到高压，1.5s内这个CanServer_SetWakeupFlag会变成0，会不断重置Get_T_RestartDelayTime的值，
               导致KL15_GetDelayTimeFlag不能变成0
            */
            if(TRUE == Get_OverORLowVoltageFlag())
            {
                Set_T_RestartFlag(FALSE);
            }
        }
    }
}


static FUNC(boolean , Can_Server_CODE) CanServer_MonitorConditionCheck(void)
{
    uint8   KL15RetStatus = 0xFF;
    uint8   index = 0x00;
    uint8   comSts = COMM_FULL_COMMUNICATION;
    uint8   busoffStatus = CANSM_BSWM_NO_COMMUNICATION;
    KL30BRelaySts KL30data[1] = FALSE;
    RemoteModSts RemoteModStsdata[1] = FALSE;
    SysPowerMod KL15Value = 0;
    SysPowerMod KL15Data  = 0;
    Std_ReturnType  busoffRet = RTE_E_INVALID;
    Std_ReturnType  comRet = RTE_E_INVALID;
    boolean         checkRet = TRUE;
    boolean         diagSts = FALSE;
    uint8  KL30Ret = RTE_E_INVALID;
    uint8  RemoteModStsRet = RTE_E_INVALID;

    diagSts = CanServer_DiagVoltageConditionCheck();
    busoffRet = CanSM_GetCurrentComMode(0, &busoffStatus);

    KL15RetStatus = Rte_Read_SysPowerMod_SysPowerMod(&KL15Data);

    if(KL15RetStatus == RTE_E_OK)
    {
        KL15Value = KL15Data;
    }
    
    comRet = ComM_GetCurrentComMode(MONITORUSER, &comSts);
    KL30Ret = Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30data);
    RemoteModStsRet = Rte_Read_RemoteModSts_RemoteModSts(RemoteModStsdata);

    if((RTE_E_OK == KL30Ret) && (RTE_E_OK == RemoteModStsRet))
    {
        if((comSts != COMM_FULL_COMMUNICATION) || (KL15Value != DIAG_SYSTEM_POWER_MODE) || (busoffStatus != CANSM_BSWM_FULL_COMMUNICATION) 
            || (diagSts != TRUE) || ((RemoteModStsdata[0] ==0x01) && (KL30data[0] == FALSE)))
        {
            for(index = 0; index < MONITORRXPUDNUMBER; index++)
            {
                MonitorPduIdTimeoutCurrentValue[index].waitMaxTime = MonitorPduIdTimeoutValue[index].waitMaxTime;
                MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue = MonitorPduIdTimeoutValue[index].timeoutMaxValue;
                MonitorPduIdTimeoutCurrentValue[index].validRecCnt = MonitorPduIdTimeoutValue[index].validRecCnt;
            }
            checkRet = FALSE;
        }
    }
        
     /* KL15 from off->on must delay 500ms or 1500ms*/
     if(KL15_GetDelayTimeFlag())
     {
        checkRet = FALSE;
     }
    
    /* Monitor condition changed, print log */
    if(preMTCndtFlag != checkRet)
    {
        can_warn("Com Sts=%d, Ign Sts=%d, Diag Sts=%d", comSts, KL15Value, diagSts);
    }
    preMTCndtFlag = checkRet;

    return checkRet;
}


static FUNC(void , Can_Server_CODE) CanServer_RxPDUTimeoutInit(void)
{
    uint16 index = 0x00;
    uint16 indexRxPduDTC = 0x00;
    Std_ReturnType ret = RTE_E_OK;
    
    CanServer_SetWakeupFlag(TRUE);
    CanServer_SetDelayMonitorTime(0);
    Set_T_RestartDelayTime(0);
    Set_OverORLowVoltageFlag(FALSE);
    Set_T_RestartFlag(FALSE);
    volMonitInfo[0].StartWakeupTimerFlag = FALSE;
    /*KL15 = Off by default*/
    KL15_SetDelayTimeFlag(FALSE);

    /*Get VConfig info*/
    ret = Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(VConfigInfo);
    
    for(index = 0; index < MONITORRXPUDNUMBER; index++)
    {
        boolean vcfgCheckRet = FALSE;
        
        if (NULL_PTR != MonitorPduIdTimeoutValue[index].VCfgFncPtr)
        {
            vcfgCheckRet = MonitorPduIdTimeoutValue[index].VCfgFncPtr();
        }

        if(TRUE == vcfgCheckRet)
        {
            MonitorPduIdTimeoutCurrentValue[index].waitMaxTime = MonitorPduIdTimeoutValue[index].waitMaxTime;
            MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue = MonitorPduIdTimeoutValue[index].timeoutMaxValue;
            MonitorPduIdTimeoutCurrentValue[index].validRecCnt = MonitorPduIdTimeoutValue[index].validRecCnt;
            MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime = MonitorPduIdTimeoutValue[index].passedCumulativeTime;
        }
        MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer = 0x00;
    }

    for(index = 0; index < COMDTCNUMBER; index++)
    {
        /* Reset DTC Failed Status */
        DTCMaskCurrentFlagRecord[index] = FALSE;
        /* init DTC Flag to False */
        DTCFlagRecord[index] = FALSE;
        
        /* init DTC valid status to False */
        RxPdu_DTC_StoreRecord[0].validStatus[index] = FALSE;
        RxPdu_DTC_StoreRecord[0].validCnt[index] = 0;
        RxPdu_DTC_StoreRecord[0].firstPassedFlag[index] = TRUE;

        DTC_Status_Record.DTC_initStatus[index] = FALSE;
        DTC_Status_Record.DTC_currStatus[index] = 0;
        DTC_Status_Record.ReportDTCState[index] = DEM_EVENT_STATUS_PASSED;
    }
    
    for(indexRxPduDTC = 0; indexRxPduDTC < RXPDU_DTC_NUM; indexRxPduDTC++)
    {
        for(index = 0; index < DTCMASKBYTES; index++)
        {
            /* init Passed Flag Record */
            PassedFlagRecord[indexRxPduDTC][index] = 0x00;
            /* init Mask Value Record */
            MaskValueRecord[indexRxPduDTC][index] = 0x00;
        }
    }

    /* init 0xC24387 Cfg Veh info*/
    if((VConfigInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM] >= 0x02) && (VConfigInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM] <= 0x06))
    {
        DTC_0xC24387_CfgVehInfo[0] = 0x01;
    }
    else
    {
        DTC_0xC24387_CfgVehInfo[0] = 0x00;
    }

    if(VConfigInfo[VCONFIG_KIND_FRONT_SENSOR] != 0x00)
    {
        DTC_0xC24387_CfgVehInfo[1] = 0x01;
    }
    else
    {
        DTC_0xC24387_CfgVehInfo[1] = 0x00;
    }

    if((VConfigInfo[VCONFIG_KIND_REAR_PAS_SENSOR] != 0x00) && (VConfigInfo[VCONFIG_KIND_FRONT_SENSOR] == 0x00))
    {
        DTC_0xC24387_CfgVehInfo[2] = 0x01;
    }
    else
    {
        DTC_0xC24387_CfgVehInfo[2] = 0x00;
    }

    DTC_Status_Record.ReportTimeoutCounter = 0;
}

static FUNC(void , Can_Server_CODE) CanServer_RxPDUTimeoutHandler(void)
{
    uint8 index = 0x00;
    uint8 indexRxPduDTC = 0x00;
    boolean vcfgCheckRet = FALSE;
    boolean condCheckRet = FALSE;
    
    /*condition check*/
    condCheckRet = CanServer_MonitorConditionCheck();

    if((condCheckRet == TRUE) && (Busoff_GetBorFlag(BUSOFF_CONTROLLER_0) == FALSE))
    {
        for(index = 0; index < MONITORRXPUDNUMBER; index++)
        {
            vcfgCheckRet = FALSE;
            
            if (NULL_PTR != MonitorPduIdTimeoutValue[index].VCfgFncPtr)
            {
                vcfgCheckRet = MonitorPduIdTimeoutValue[index].VCfgFncPtr();
            }
            /* send to PDUR ,index start at NO 5*/
            if((CanIf_RxPduConfig[index].IsDataChecksumRxPduOfRxPduConfig == TRUE) && vcfgCheckRet)
            {
                /* Cumulative Passed Time*/
                MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime++;
                
                if(MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue > 0)
                {
                    MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue--;
                }

                if(MonitorPduIdTimeoutCurrentValue[index].waitMaxTime > 0)
                {
                    MonitorPduIdTimeoutCurrentValue[index].waitMaxTime--;
                }

                if(MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer > 0)
                {
                    MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer--;
                    if(MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer == 0)
                    {
                        MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer = MonitorPduIdTimeoutValue[index].timeoutPassedCntCycTimer;
                        MonitorPduIdTimeoutCurrentValue[index].validRecCnt = 0;
                        MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime = 0;
                    }
                }
            }
            /*if timeoutMaxValue = 0,10 times reached*/
            if(((MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue == 0) || (MonitorPduIdTimeoutCurrentValue[index].waitMaxTime == 0))\
                && vcfgCheckRet && (MonitorPduIdTimeoutValue[index].timeoutMaxValue > 0)
                && (CanIf_RxPduConfig[index].IsDataChecksumRxPduOfRxPduConfig == TRUE))
            {
                for(indexRxPduDTC = 0; indexRxPduDTC < RXPDU_DTC_NUM; indexRxPduDTC++)
                {
                    CanServer_SetEventMaskFlag(index,indexRxPduDTC);
                    CanServer_ResetRxPDUPassedFlag(index,indexRxPduDTC);
                }
                MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime = 0;
                MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue = MonitorPduIdTimeoutValue[index].timeoutMaxValue;
                MonitorPduIdTimeoutCurrentValue[index].waitMaxTime = MonitorPduIdTimeoutValue[index].waitMaxTime;
                MonitorPduIdTimeoutCurrentValue[index].validRecCnt = MonitorPduIdTimeoutValue[index].validRecCnt;
            }
                
            /*Passed condition*/
            if((MonitorPduIdTimeoutCurrentValue[index].validRecCnt >= MONITORRXPUDVALIDMAXNUMBER) && vcfgCheckRet
            && (MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime >= (MonitorPduIdTimeoutValue[index].timeoutMaxValue - 1))
            && (MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer != 0))
            {
                MonitorPduIdTimeoutCurrentValue[index].passedCumulativeTime = MonitorPduIdTimeoutValue[index].timeoutMaxValue;
                
                for(indexRxPduDTC = 0; indexRxPduDTC < RXPDU_DTC_NUM; indexRxPduDTC++)
                {
                    CanServer_ResetEventMaskFlag(index,indexRxPduDTC);
                    CanServer_SetRxPDUPassedFlag(index,indexRxPduDTC);
                }
                MonitorPduIdTimeoutCurrentValue[index].validRecCnt = MONITORRXPUDVALIDMAXNUMBER;
            }
        }
    }
    else
    {
        CanServer_DTCMonitorReset();
    }
}

static FUNC(void , Can_Server_CODE) CanServer_DTCStoreHandler(void)
{
    uint8 index = 0x00;
    uint8 indexDTCNum = 0x00;

    /* Set Failed Flag */ 
    for(index = 0; index < COMDTCNUMBER;index++)
    {
        if (DTC0xC24387POSITION == index)
        {
            CanServer_DTC0xC24387Handler(index);
        }
        else
        {
            for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES; indexDTCNum++)
            {
                if (0x00 != (DTCMaskRecord[index].DTCMask[indexDTCNum] & MaskValueRecord[1][indexDTCNum]))
                {
                    DTCMaskCurrentFlagRecord[index] = TRUE;
                }
            }
        }
    }

    /* reset Rx PDU bit */ 
    for(index = 0; index < COMDTCNUMBER;index++)
    {
        if (DTC0xC24387POSITION == index)
        {
        }
        else
        {
            for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES; indexDTCNum++)
            {
                if (0x00 != (DTCMaskRecord[index].DTCMask[indexDTCNum] & MaskValueRecord[1][indexDTCNum]))
                {
                    /* reset Rx PDU bit */
                    MaskValueRecord[1][indexDTCNum] = (MaskValueRecord[1][indexDTCNum] & (~DTCMaskRecord[index].DTCMask[indexDTCNum]));
                }
            }
        }
    }
    
    for(index = 0; index < COMDTCNUMBER;index++)
    {
        if ((TRUE == DTCMaskCurrentFlagRecord[index]) && (index != DTC0xC24387POSITION))
        {
            DTCMaskCurrentFlagRecord[index] = DTCMaskRecord[index].DTCsMaskFlag;
            DTCMaskRecord[index].DTCStoreFunc(DEM_EVENT_STATUS_FAILED, index);
            if(DEM_EVENT_STATUS_PASSED == DTC_Status_Record.ReportDTCState[index])
            {
                can_verbose("TimeoutDTC %X report fail!", index);
            }
            
            DTC_Status_Record.ReportDTCState[index] = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
            
        }
    }
    
    CanServer_DTCPasssedHandler();
}


static FUNC(void , Can_Server_CODE) CanServer_DTCMonitorReset(void)
{
    uint16 index = 0x00;
    uint16 indexRxPduDTC = 0x00;
    
    for(index = 0; index < MONITORRXPUDNUMBER; index++)
    {
        for(indexRxPduDTC = 0; indexRxPduDTC < RXPDU_DTC_NUM; indexRxPduDTC++)
        {
            CanServer_ResetEventMaskFlag(index,indexRxPduDTC);
            CanServer_ResetRxPDUPassedFlag(index,indexRxPduDTC);
        }
        MonitorPduIdTimeoutCurrentValue[index].waitMaxTime = MonitorPduIdTimeoutValue[index].waitMaxTime;
        MonitorPduIdTimeoutCurrentValue[index].timeoutMaxValue = MonitorPduIdTimeoutValue[index].timeoutMaxValue;
        MonitorPduIdTimeoutCurrentValue[index].validRecCnt = MonitorPduIdTimeoutValue[index].validRecCnt;
        MonitorPduIdTimeoutCurrentValue[index].timeoutPassedCntCycTimer = 0x00;
    }
    /*clear store Bit Value*/
    index = 0;
    while(index < DTCMASKBYTES)
    {
        DTCFlagRecord[index] = FALSE;
        index++;
    }

    /* change for KL15 Lost*/
    for(index = 0; index < COMDTCNUMBER; index++)
    {
        DTC_Status_Record.DTC_initStatus[index] = FALSE;
    }
}

static FUNC(void , Can_Server_CODE) CanServer_DTCPasssedHandler(void)
{
    uint8 indexArr = 0x00;
    uint8 indexPdu = 0x00;
    uint8 indexDTCNum = 0x00;
    uint8 DTCRefIndexA = 0xFF;
    uint8 DTCRefIndexB = 0xFF;
    
    /* check 0xC24387 Passsed condition */
    CanServer_DTC0xC24387PassedHandler();

    for (indexPdu = (uint8)0x00; indexPdu < MONITORRXPUDNUMBER;indexPdu++)
    {
        if (
           ((uint8)0xFF != MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[0])
        && (COMDTCNUMBER > MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[0])
        )
        {
            indexArr = 0x00;
            DTCRefIndexA = MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[0];
            DTCRefIndexB = MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[1];

            while((indexArr < DTC_MASK_ROW_NUM) && (DTCRefIndexA < COMDTCNUMBER) && (DTCRefIndexA != DTC0xC24387POSITION))
            {
                DTCFlagRecord[DTCRefIndexA] = TRUE;
                
                for(indexDTCNum = (uint8)0x00; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
                {
                    if(( RxPdu_DTC_Passed_MaskRecord[DTCRefIndexA].DTC_MaskValue[indexArr][indexDTCNum] & PassedFlagRecord[1][indexDTCNum]) != 
                        RxPdu_DTC_Passed_MaskRecord[DTCRefIndexA].DTC_MaskValue[indexArr][indexDTCNum])
                    {
                        /* Not all Rx Pdu in the DTC is OK*/
                        DTCFlagRecord[DTCRefIndexA] = FALSE;
                        break;
                    }
                }

                if(DTCFlagRecord[DTCRefIndexA] == TRUE)
                {
                    break;
                }
                
                indexArr++;
            }

            if ((DTCFlagRecord[DTCRefIndexA] == TRUE) && (0xFF != MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[0])
                && (DTCRefIndexA != 0xFF) && (DTCRefIndexA != DTC0xC24387POSITION) && (DTCRefIndexA < COMDTCNUMBER))
            {
                if(((RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexA] == FALSE) && (RxPdu_DTC_StoreRecord[0].firstPassedFlag[DTCRefIndexA] == TRUE))|| 
                    ((RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexA] == TRUE) && (RxPdu_DTC_StoreRecord[0].validCnt[DTCRefIndexA] >= DTCPASSEDDELAYCNT)))
                {
                    /* report Passed time must grater to 100ms,set Flag*/
                    RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexA] = TRUE;
                    RxPdu_DTC_StoreRecord[0].firstPassedFlag[DTCRefIndexA] = FALSE;
                    RxPdu_DTC_StoreRecord[0].validCnt[DTCRefIndexA] = 0;
                    DTCMaskRecord[DTCRefIndexA].DTCStoreFunc(DEM_EVENT_STATUS_PASSED, DTCRefIndexA);
                    if(DEM_EVENT_STATUS_FAILED == DTC_Status_Record.ReportDTCState[DTCRefIndexA])
                    {
                        can_verbose("TimeoutDTC %X report pass!", DTCRefIndexA);
                    }
                    
                    DTC_Status_Record.ReportDTCState[DTCRefIndexA] = DEM_EVENT_STATUS_PASSED;
                }
                
            }

            if (( 0xFF != MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[1]) && (DTCRefIndexB != DTC0xC24387POSITION) && (DTCRefIndexB < COMDTCNUMBER))
            {
                indexArr = 0x00;
                
                while((indexArr < DTC_MASK_ROW_NUM) && (DTCRefIndexB < COMDTCNUMBER))
                {
                    DTCFlagRecord[DTCRefIndexB] = TRUE;
                    
                    for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
                    {
                        if(( RxPdu_DTC_Passed_MaskRecord[DTCRefIndexB].DTC_MaskValue[indexArr][indexDTCNum] & PassedFlagRecord[1][indexDTCNum]) != 
                            RxPdu_DTC_Passed_MaskRecord[DTCRefIndexB].DTC_MaskValue[indexArr][indexDTCNum])
                        {
                            /* Not all Rx Pdu in the DTC is OK*/
                            DTCFlagRecord[DTCRefIndexB] = FALSE;
                            break;
                        }
                    }

                    if(DTCFlagRecord[DTCRefIndexB] == TRUE)
                    {
                        break;
                    }
                    
                    indexArr++;
                }
            }
            

            if ((DTCFlagRecord[DTCRefIndexB] == TRUE) && (0xFF != MonitorPduIdTimeoutValue[indexPdu].DTCRefIndex[1]) 
                && (DTCRefIndexB != 0xFF) && (DTCRefIndexB != DTC0xC24387POSITION) && (DTCRefIndexB < COMDTCNUMBER))
            {
                if(((RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexB] == FALSE) && (RxPdu_DTC_StoreRecord[0].firstPassedFlag[DTCRefIndexB] == TRUE))|| 
                    ((RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexB] == TRUE) && (RxPdu_DTC_StoreRecord[0].validCnt[DTCRefIndexB] == DTCPASSEDDELAYCNT)))
                {
                    /* report Passed time must grater to 100ms,set Flag*/
                    RxPdu_DTC_StoreRecord[0].validStatus[DTCRefIndexB] = TRUE;
                    RxPdu_DTC_StoreRecord[0].firstPassedFlag[DTCRefIndexB] = FALSE;
                    RxPdu_DTC_StoreRecord[0].validCnt[DTCRefIndexB] = 0;
                    DTCMaskRecord[DTCRefIndexB].DTCStoreFunc(DEM_EVENT_STATUS_PASSED, DTCRefIndexB);
                    if(DEM_EVENT_STATUS_FAILED == DTC_Status_Record.ReportDTCState[DTCRefIndexB])
                    {
                        can_verbose("TimeoutDTC %X report pass!", DTCRefIndexB);
                    }
                    
                    DTC_Status_Record.ReportDTCState[DTCRefIndexB] = DEM_EVENT_STATUS_PASSED;
                }
            }
        }
    }
    
}

static FUNC(void , Can_Server_CODE) CanServer_ReportDTCStateCycle(void)
{
    if((DTC_Status_Record.ReportTimeoutCounter < COMDTCNUMBER) && (DTC_Status_Record.DTC_initStatus[DTC_Status_Record.ReportTimeoutCounter] == TRUE))
    {
        DTC_Status_Record.DTC_initStatus[DTC_Status_Record.ReportTimeoutCounter] = FALSE;
        DTCMaskRecord[DTC_Status_Record.ReportTimeoutCounter].DTCStoreFunc(DTC_Status_Record.ReportDTCState[DTC_Status_Record.ReportTimeoutCounter], DTC_Status_Record.ReportTimeoutCounter);
    }

    DTC_Status_Record.ReportTimeoutCounter++;
    if(DTC_Status_Record.ReportTimeoutCounter >= 100u)
    {
        DTC_Status_Record.ReportTimeoutCounter = 0u;
    }
}


static FUNC(void , Can_Server_CODE) CanServer_DTC0xC24387Handler(uint8 index)
{
    uint8 indexDTCNum = 0x00;
    uint16 recordValue[3] = {0};
    uint16 maskValue[3] = {0};

    DTCMaskCurrentFlagRecord[index] = FALSE;
    
    for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
    {
        maskValue[0] += DTCMaskRecord[index].DTCMask[indexDTCNum];
        maskValue[1] += MaskValueRecordDTC0xC24387_2[indexDTCNum];
        maskValue[2] += MaskValueRecordDTC0xC24387_3[indexDTCNum];
        recordValue[0] += (DTCMaskRecord[index].DTCMask[indexDTCNum] & MaskValueRecord[0][indexDTCNum]);
        recordValue[1] += (MaskValueRecordDTC0xC24387_2[indexDTCNum] & MaskValueRecord[0][indexDTCNum]);
        recordValue[2] += (MaskValueRecordDTC0xC24387_3[indexDTCNum] & MaskValueRecord[0][indexDTCNum]);
    }
    
    if(DTC_0xC24387_CfgVehInfo[0])
    {
        if(maskValue[0] == recordValue[0])
        {
            for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
            {
                MaskValueRecord[0][indexDTCNum] = (MaskValueRecord[0][indexDTCNum] & (~DTCMaskRecord[index].DTCMask[indexDTCNum]));
            }

            /* reset Passed Flag */
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx,  (uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx,  (uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx,(uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx,(uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx,(uint8)0u);
            /* reset valid cnt */
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx].validRecCnt = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx].validRecCnt = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx].validRecCnt = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx].validRecCnt = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx].validRecCnt = (uint8)0u;
            
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
    }
    else if(DTC_0xC24387_CfgVehInfo[1])
    {
        if(maskValue[1] == recordValue[1])
        {
            for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
            {
                MaskValueRecord[0][indexDTCNum] = (MaskValueRecord[0][indexDTCNum] & (~MaskValueRecordDTC0xC24387_2[indexDTCNum]));
            }

            /* reset Passed Flag */
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx,  (uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx,  (uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx,(uint8)0u);

            /* reset valid cnt */
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx].validRecCnt   = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx].validRecCnt   = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx].validRecCnt = (uint8)0u;
            
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
    }
    else if(DTC_0xC24387_CfgVehInfo[2])
    {
        if(maskValue[2] == recordValue[2])
        {
            for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES;indexDTCNum++)
            {
                MaskValueRecord[0][indexDTCNum] = (MaskValueRecord[0][indexDTCNum] & (~MaskValueRecordDTC0xC24387_3[indexDTCNum]));
            }

            /* reset Passed Flag */
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx,   (uint8)0u);
            CanServer_ResetRxPDUPassedFlag((uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx, (uint8)0u);

            /* reset valid cnt */
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx].validRecCnt   = (uint8)0u;
            MonitorPduIdTimeoutCurrentValue[(uint8)CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx].validRecCnt = (uint8)0u;

            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
    }

    if(DTCMaskCurrentFlagRecord[index] == TRUE)
    {
        DTCMaskRecord[index].DTCStoreFunc(DEM_EVENT_STATUS_FAILED, index);

        if(DEM_EVENT_STATUS_PASSED == DTC_Status_Record.ReportDTCState[index])
        {
            can_warn("0xC24387 is report fail!");
        }
        
        DTC_Status_Record.ReportDTCState[index] = DEM_EVENT_STATUS_FAILED;
    }
}

static FUNC(void , Can_Server_CODE) CanServer_DTC0xC24387PassedHandler(void)
{
    uint8 indexDTCNum = 0x00;
    
    DTCFlagRecord[DTC0xC24387POSITION] = FALSE;

        for(indexDTCNum = 0; indexDTCNum < DTCMASKBYTES; indexDTCNum++)
        {
            if((RxPdu_DTC_Passed_MaskRecord[DTC0xC24387POSITION].DTC_MaskValue[0][indexDTCNum] & PassedFlagRecord[0][indexDTCNum]) != 0x00)
            {
                DTCFlagRecord[DTC0xC24387POSITION] = TRUE;
                PassedFlagRecord[0][indexDTCNum] = ((~RxPdu_DTC_Passed_MaskRecord[DTC0xC24387POSITION].DTC_MaskValue[0][indexDTCNum]) & PassedFlagRecord[0][indexDTCNum]);
            }
        }

    if(DTCFlagRecord[DTC0xC24387POSITION] == TRUE)
    {
        DTCMaskRecord[DTC0xC24387POSITION].DTCStoreFunc(DEM_EVENT_STATUS_PASSED,DTC0xC24387POSITION);
        if(DEM_EVENT_STATUS_FAILED == DTC_Status_Record.ReportDTCState[DTC0xC24387POSITION])
        {
            can_warn("0xC24387 is report pass!");
        }
        
        DTC_Status_Record.ReportDTCState[DTC0xC24387POSITION] = DEM_EVENT_STATUS_PASSED;
    }

}

static FUNC(void, CANSM_CODE) CanServer_SetEcuPassive( boolean CanSM_TxOfflineActive )
{
    if ( ( ( CanSM_ChannelVarRecord[0].CanSM_CurrentState == 0x10u ) || ( CanSM_ChannelVarRecord[0].CanSM_CurrentState == 0x11u ) ) )
    { /* BOR SM not running a recovery, State IS ONLINE */

      if ( CanSM_TxOfflineActive == TRUE )
      { /* Activate ECU passive mode immediately */
        (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig((uint8)0x00), CANIF_SET_TX_OFFLINE_ACTIVE );
        /* \trace..SPEC-2181273 */

      }
      else
      { /* DeActivate ECU passive mode immediately */
        (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig((uint8)0x00), CANIF_SET_TX_ONLINE );
        /* \trace..SPEC-2181274 */

      }

    } /* end if full Com && BOR SM not running a recovery */

    
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC16487(uint8 EventStatus, uint8 index)
{

    Std_ReturnType ret = E_NOT_OK;
    
    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
      ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_SetEventStatus(EventStatus);
        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00087(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
      ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xD00087_SetEventStatus(EventStatus);
        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}

static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00487(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
      ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11187(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10687(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;

        ret = Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}

static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24187(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00987(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC19987(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC2B387(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC20887(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD00287(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xD00287_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12887(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC13187(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12287(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11587(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}

static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10887(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14687(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC15887(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC29387(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD02687(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC25E87(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC15C87(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean vconfigcheck = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    vconfigcheck = (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01);

    if(((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus))) 
    && (TRUE == vconfigcheck))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14387(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean vconfigcheck = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    vconfigcheck = ((VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01) && (VInfo[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA] == 0x01));

    if(((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    && (TRUE == vconfigcheck))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC11487(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}

static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC1BB87(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24387(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }

}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC20087(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC23087(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10B87(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24787(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingRearHeatVentSeatModule_0xC24787_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD10987(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24287(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC23387(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD01587(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC19887(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC14187(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10187(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC12787(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xD02987(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


 static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10087(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC10487(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean vconfigcheck = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    vconfigcheck = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)));

     if(((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
     ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus))) 
     && (TRUE == vconfigcheck))
     {
         DTC_Status_Record.DTC_initStatus[index] = TRUE;
         DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
     }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC2B587(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}


static FUNC(void , Can_Server_CODE) DTCStoreFunc_0xC24687(uint8 EventStatus, uint8 index)
{
    Std_ReturnType ret = E_NOT_OK;

    if((DTC_Status_Record.DTC_initStatus[index] == FALSE) || 
    ((DTC_Status_Record.DTC_initStatus[index] == TRUE) && (DTC_Status_Record.DTC_currStatus[index] != EventStatus)))
    {
        DTC_Status_Record.DTC_initStatus[index] = TRUE;
        DTC_Status_Record.DTC_currStatus[index] = EventStatus;
        ret = Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_SetEventStatus(EventStatus);

        if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_FAILED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCMaskCurrentFlagRecord[index] = TRUE;
        }
        else if((ret != E_OK) && (EventStatus == DEM_EVENT_STATUS_PASSED))
        {
            DTC_Status_Record.DTC_initStatus[index] = FALSE;
            DTCFlagRecord[index] = TRUE;
        }
    }
    else
    {

    }
}

 static FUNC(boolean, Can_Server_CODE) ABM1_VCfgCheck(void)
{
    return TRUE;
}




static FUNC(boolean, Can_Server_CODE) ABS3_VCfgCheck(void)
{
    uint8* VInfo;
    boolean ret = FALSE;
    
    VInfo = CanServer_GetVIfnoPtr();

    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_SERVICE_BRAKE]  == 0x02) && 
              (((VInfo[VCONFIG_KIND_TRANSMISSION] >= 0x01) && (VInfo[VCONFIG_KIND_TRANSMISSION] <= 0x0E) ) || 
              ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x25) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x11))));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) AC1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x02) ||
            (VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x03) ||
            (VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x04));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) AC2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x02) ||
            (VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x03) ||
            (VInfo[VCONFIG_KIND_AIR_CONDITIONER]  == 0x04));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) ACC_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)) || 
            (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ACC_FD3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)) || 
            (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ACC_FD4_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)) || 
            (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) AEB_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)) || 
        (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) AEB_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE] == 0x01) && (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01)) || 
            (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) BCM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x02) ||
               (VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) BCM3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x02) ||
               (VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x01));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) BCM8_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x02) ||
               (VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x01));
    }


    return ret;
}

static FUNC(boolean, Can_Server_CODE) BMS4_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x02) || 
        (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x04) || 
        (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x05)|| 
        (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) BMS8_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x02) || 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x04) || 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x05)|| 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x01));
    }


    return ret;
}

static FUNC(boolean, Can_Server_CODE) BMS22_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04) || 
        (VInfo[VCONFIG_KIND_FUEL]  == 0x0A));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) BMS30_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04) || 
            (VInfo[VCONFIG_KIND_FUEL]  == 0x0A));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) BMS35_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x02) || 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x04) || 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x05)|| 
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]  ==  0x01));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) CP1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_SIDE_STEP] == 0x06);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) CR_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK] ==  0x01) || 
            (VInfo[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK] ==  0x02));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) CSA3_VCfgCheck(void)
{

    return TRUE;
}


static FUNC(boolean, Can_Server_CODE) DCT3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x07) || 
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26) || 
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x0F) || 
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x10));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) DCT5_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();

    return ret;
}


static FUNC(boolean, Can_Server_CODE) DCT7_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x07) || 
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) DDCM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = (((VInfo[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]== 0x02) ||
             (VInfo[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]== 0x03)) && (
             (VInfo[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING] == 0x03) ||
             (VInfo[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING] == 0x04)) && (
             (VInfo[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING] == 0x03) ||
             (VInfo[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING] == 0x04)));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) DMS_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_DMS_TYPE] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) DSM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x01) ||
           (VInfo[VCONFIG_KIND_DRIVER_SEAT]== 0x02) ||
           (VInfo[VCONFIG_KIND_DRIVER_SEAT]== 0x03) ||
           (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x04) ||
           (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x05) ||
           (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x06));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ECM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]== 0x01)|| 
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x02) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT] == 0x03) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x04) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x05) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x06) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x07));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ECM2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]== 0x01)|| 
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x02) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT] == 0x03) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x04) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x05) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x06) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x07));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ECM3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]== 0x01)|| 
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x02) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT] == 0x03) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x04) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x05) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x06) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x07));
    }


    return ret;
}




static FUNC(boolean, Can_Server_CODE) ECM11_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]== 0x01)|| 
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x02) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT] == 0x03) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x04) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x05) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x06) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x07));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) ECM19_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]== 0x01)|| 
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x02) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT] == 0x03) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x04) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x05) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x06) ||
            (VInfo[VCONFIG_KIND_ENGINE_CONTROL_UNIT]  == 0x07));
    }


    return ret;
}

static FUNC(boolean, Can_Server_CODE) ELD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_CRUISE_CONTROL]  == 0x02 ) ||
           (VInfo[VCONFIG_KIND_CRUISE_CONTROL]  == 0x03 ) ||
           (VInfo[VCONFIG_KIND_CRUISE_CONTROL]  == 0x04 ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) EPB1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_PARKING_BRAKE] == 0x02);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) EPS1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STEERING_SYSTEM] == 0x01) && (((VInfo[VCONFIG_KIND_TRANSMISSION] >= (0x01)) && (VInfo[VCONFIG_KIND_TRANSMISSION] <= (0x0E))) || 
            ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x25) ||(VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x11))));
    }
    
    return ret;
}


static FUNC(boolean, Can_Server_CODE) EPS_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STEERING_SYSTEM]== 0x01) && 
            ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x0F ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x10 ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x27 ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x28 ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x12 ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x13 ) ||
            (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x14 )));
    }
    return ret;
}

static FUNC(boolean, Can_Server_CODE) ESP1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_SERVICE_BRAKE]  == 0x02) && 
              (((VInfo[VCONFIG_KIND_TRANSMISSION] >= 0x01) && (VInfo[VCONFIG_KIND_TRANSMISSION] <= 0x0E) ) || 
              ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x25) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x11))));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) ESP2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_SERVICE_BRAKE] == 0x02) && 
              (((VInfo[VCONFIG_KIND_TRANSMISSION] >= 0x01) && (VInfo[VCONFIG_KIND_TRANSMISSION] <= 0x0E) ) || 
              ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x25) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x26) || (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x11))));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) ESP8_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();

    return ret;
}

static FUNC(boolean, Can_Server_CODE) ESP_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_SERVICE_BRAKE] == 0x02) && 
               ((VInfo[VCONFIG_KIND_TRANSMISSION] == 0x0F) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x10) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x27) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x28) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x12) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x13) ||
               (VInfo[VCONFIG_KIND_TRANSMISSION] == 0x14)));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) FPAS1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x02 ) ||
        (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x03 ) ||
        (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x04 ) ||
        (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x05 ) ||
        (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x06 ) ||
        (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x01 ) ||
        (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x02 ) ||
        (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x03 ) ||
        (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x04 ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) F_PBox1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_SMART_JUNCTION_BOX]  == 0x01);
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) GW_FD1_VCfgCheck(void)
{

    return TRUE;
}


static FUNC(boolean, Can_Server_CODE) HAP_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x02 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x03 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x04 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x05 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x06 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x01 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x02 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x03 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x04 ) ||
            (VInfo[VCONFIG_KIND_OMNIVIEW_SYSTEM]  == 0x03 ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) HAP_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x02 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x03 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x04 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x05 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x06 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x01 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x02 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x03 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x04 ) ||
                (VInfo[VCONFIG_KIND_OMNIVIEW_SYSTEM]  == 0x03 ));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) HAP_FD3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x02 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x03 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x04 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x05 ) ||
                (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x06 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x01 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x02 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x03 ) ||
                (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x04 ) ||
                (VInfo[VCONFIG_KIND_OMNIVIEW_SYSTEM]  == 0x03) ||
                (((VInfo[VCONFIG_KIND_REAR_PAS_SENSOR] == 0x01) ||(VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x02) ||
                (VInfo[VCONFIG_KIND_REAR_PAS_SENSOR] == 0x03) || (VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x04)) && (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x00)));
     }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) HC1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
       ret = (VInfo[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x02 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x04 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x05 ));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_HC3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04) ||
           (VInfo[VCONFIG_KIND_FUEL]  == 0x0A));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_HC6_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04) ||
               (VInfo[VCONFIG_KIND_FUEL]  == 0x0A));
    }


    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_HC7_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04) ||
               (VInfo[VCONFIG_KIND_FUEL]  == 0x0A));
    }


    return ret;
}

static FUNC(boolean, Can_Server_CODE) HCU_PT4_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x02 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION]== 0x04 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x05 ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_PT5_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;
    
    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x02 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x04 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x05 ));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_PT7_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x02 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x04 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x05 ));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) HCU_PT8_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x02 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x04 ) ||
            (VInfo[VCONFIG_KIND_ELECTROMOTOR_POSITION] == 0x05 ));
    }
    
    return ret;
}


static FUNC(boolean, Can_Server_CODE) HUD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = (VInfo[VCONFIG_KIND_HEAD_UP_DISPLAY] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) Haldex1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_TRANSFER_CASE]  == 0x01 )||
        (VInfo[VCONFIG_KIND_TRANSFER_CASE]  == 0x02 )||
        (VInfo[VCONFIG_KIND_TRANSFER_CASE]  == 0x03 )||
        (VInfo[VCONFIG_KIND_TRANSFER_CASE]  == 0x05 ));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) IFC_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01) && (VInfo[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA] == 0x01))
        || (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) IFC_FD3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01) && (VInfo[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA] == 0x01))
        || (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) IFC_FD5_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01) && (VInfo[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA] == 0x01))
        || (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) IFC_FD6_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (((VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] != 0x01) && (VInfo[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA] == 0x01))
        || (VInfo[VCONFIG_KIND_HIGHWAY_ASSIST] == 0x01));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) Ibooster_FD2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP] == 0x01);
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) OBC2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_FUEL]  == 0x04 )||
           (VInfo[VCONFIG_KIND_FUEL]  == 0x0A ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) PDCM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = (((VInfo[VCONFIG_KIND_DRIVER_WINDOW_OPERATING] == 0x02) ||
             (VInfo[VCONFIG_KIND_DRIVER_WINDOW_OPERATING] == 0x03)) && (
             (VInfo[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING] == 0x03) ||
             (VInfo[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING] == 0x04)) && (
             (VInfo[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING] == 0x03) ||
             (VInfo[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING] == 0x04)));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) PEPS2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x02) ||
               (VInfo[VCONFIG_KIND_STARTING_SYSTEM]  == 0x01));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) PEPS4_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_STARTING_SYSTEM] == 0x02) ||
               (VInfo[VCONFIG_KIND_STARTING_SYSTEM] == 0x01));
    }



    return ret;
}


static FUNC(boolean, Can_Server_CODE) PLG_1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_RR_DOOR_OPENING]  == 0x02 )||
           (VInfo[VCONFIG_KIND_RR_DOOR_OPENING]  == 0x03 ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) RPAS1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x02 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x03 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x04 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x05 ) ||
            (VInfo[VCONFIG_KIND_AUTO_PARKING_SYSTEM]  == 0x06 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x01 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x02 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR]  == 0x03 ) ||
            (VInfo[VCONFIG_KIND_FRONT_SENSOR] == 0x04 ) ||
            (((VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x01) ||(VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x02) ||
            (VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x03) || (VInfo[VCONFIG_KIND_REAR_PAS_SENSOR]  == 0x04)) && (VInfo[VCONFIG_KIND_FRONT_SENSOR] == 0x00)));
    }
    return ret;
}


static FUNC(boolean, Can_Server_CODE) RSDS_FD1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_LANE_CHANGE_ASSIST] == 0x01);
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) R_PBox1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_SMART_JUNCTION_BOX] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) SCM1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x01) ||
            (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x02) ||
            (VInfo[VCONFIG_KIND_DRIVER_SEAT]== 0x03) ||
            (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x04) ||
            (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x05) ||
            (VInfo[VCONFIG_KIND_DRIVER_SEAT] == 0x06));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) STBS1_VCfgCheck(void)
{
    boolean ret = FALSE;

    return ret;
}

static FUNC(boolean, Can_Server_CODE) TPMS1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_TPMS] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) TPMS2_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = (VInfo[VCONFIG_KIND_TPMS] == 0x01);
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) T_Box_FD3_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE]  == 0x01 ) ||
           (VInfo[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE]  == 0x0A ));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) Trailer1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
    ret = ((VInfo[VCONFIG_KIND_TRAILING_HOOK] == 0x02) ||
            (VInfo[VCONFIG_KIND_TRAILING_HOOK] == 0x04) ||
            (VInfo[VCONFIG_KIND_TRAILING_HOOK] == 0x05) ||
            (VInfo[VCONFIG_KIND_TRAILING_HOOK] == 0x06));
    }

    return ret;
}


static FUNC(boolean, Can_Server_CODE) VSG1_VCfgCheck(void)
{
    boolean ret = FALSE;

    return ret;
}


static FUNC(boolean, Can_Server_CODE) WPC1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
        ret = ((VInfo[VCONFIG_KIND_WIRELESS_POWER_CHARGER] == 0x01)||
               (VInfo[VCONFIG_KIND_WIRELESS_POWER_CHARGER] == 0x02));
    }

    return ret;
}

static FUNC(boolean, Can_Server_CODE) HCM_R1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
       ret = (VInfo[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION] == 0x02);
    }

    return ret;

}

static FUNC(boolean, Can_Server_CODE) HCM_L1_VCfgCheck(void)
{
    boolean ret = FALSE;
    uint8* VInfo;

    VInfo = CanServer_GetVIfnoPtr();
    if(VInfo != NULL_PTR)
    {
       ret = (VInfo[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION] == 0x02);
    }

    return ret;

}


FUNC(boolean, COM_APPL_CODE) ComIPdu_userData_Callback_tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
	Std_ReturnType         ret = RTE_E_INVALID;
	boolean                resultRet = TRUE;
	float64                voltageValue = (float64)0.0f;
	SystemState_RecordType SysValue;
	uint64 					WakeupReason = 0;
	uint8					Cannm_Status = 0;
	uint8					Cannm_Mode = 0;
    uint8                   IVIPowerMode = 0;
    
	uint8                   SysPowerModSig = 0;
	boolean                 SysPowerModVldSig = FALSE;
    uint8                   SessionMode;
    uint8                   retSysPowerMod = RTE_E_INVALID;
    uint8                   retSysPowerModVld = RTE_E_INVALID;
    Std_ReturnType          retVal = E_NOT_OK;

    PduId = PduId;
    
    if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        resultRet = FALSE;
    }
    else
	{
		/*CANNM REPEAT STATUS*/
		(void)CanNm_GetState(0,&Cannm_Status,&Cannm_Mode);
		if(Cannm_Status == NM_STATE_REPEAT_MESSAGE)
		{
			PduInfoPtr->SduDataPtr[NM_RMS_FLAG_INDEX] &= NM_CLEAR_BITS;
		}
		else
		{
			PduInfoPtr->SduDataPtr[NM_RMS_FLAG_INDEX] |= NM_BIT0;
		}
		/*Wake-Up Reason*/
		retVal = Rte_Read_rpSR_WakeupReason_data(&WakeupReason);
		if(retVal == RTE_E_OK)
		{
			/* if((WakeupReason & ECUM_WKSOURCE_CAN_WAKEUP_MASK) == NM_WKSOURCE_CAN) */
			{
				PduInfoPtr->SduDataPtr[NM_WAKEUP_REASON_INDEX] |= NM_BIT1;
			}
			
			
		}
		else
		{
		
		}
				
        /*Stay awake reason*/
        retSysPowerMod    = Rte_Read_SysPowerMod_SysPowerMod(&SysPowerModSig);
        retSysPowerModVld = Rte_Read_SysPowerModVld_SysPowerModVld(&SysPowerModVldSig);

        if(RTE_E_OK != retSysPowerMod)
        {
            SysPowerModSig = 0;
        }
        else
        {
            /* do nothing */
        }

        if(RTE_E_OK != retSysPowerModVld)
        {
            SysPowerModVldSig = FALSE;
        }
        else
        {
            /* do nothing */
        }
        
		ret = Rte_Read_tiSR_Power_Out_SystemStateOut(&SysValue);

        /* CR : V35-51706*/
        if(ret == RTE_E_OK)
        {
            IVIPowerMode = SysValue.IVIState;
        }
        
        SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
        if(
           ((IVIPowerMode >= SYSTEMSTATE_IVI_ON_NORMAL) && (IVIPowerMode <= SYSTEMSTATE_IVI_ON_LOCAL))
        || (1u == Power_FotaSts_Get())
        || ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode) || (RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode))
        )
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] |= NM_BIT0;
        }
        else
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] &= ~NM_BIT0;
        }

        if(
           (((1u == SysPowerModSig) || (2u == SysPowerModSig) || (3u == SysPowerModSig)) && (TRUE == SysPowerModVldSig)) 
        || (1u == Power_FotaSts_Get()) 
        )
        {
			PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] |= NM_BIT1;
        }
        else
        {
            PduInfoPtr->SduDataPtr[NM_STAY_AWAKE_REASON_INDEX] &= ~NM_BIT1;
        }
		
		if(ret == RTE_E_OK)
		{
			voltageValue = SysValue.s_PowerVoltage.value;

			/*System Infromation*/
			if(voltageValue >= OVER_VOLTAGE_VALUE)
			{
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= ~NM_BIT0;
				PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] |= NM_BIT1;
			}
			else if(voltageValue <= UNDER_VOLTAGE_VALUE)
			{
				PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] |= NM_BIT0;
                PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= ~NM_BIT1;
			}
			else
			{	if(((PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] & NM_BIT1) == NM_BIT1) && (voltageValue <= OVER_VOLTAGE_RECOVER_VALUE))
				{
					PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= NM_CLEAR_BITS;
				}
				if(((PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] & NM_BIT0) == NM_BIT0) && (voltageValue >= UNDER_VOLTAGE_RECOVER_VALUE))
				{
					PduInfoPtr->SduDataPtr[NM_SYSTEM_INFORMATION_INDEX] &= NM_CLEAR_BITS;
				}
				
				
			}		
			
		}
		else
		{
			
		}
	}
	return resultRet;
}

/*
 *  %function definition%
 */
/*
* @brief   :   init com no action module
* @param   :   config: config of no action module config
* @retval  :   E_OK: initialize success
* @retval  :   E_NOT_OK: parameter error
* @retval  :   E_NOT_OK: module is already initialized
* @retval  :   E_NOT_OK: config error
*/
static Std_ReturnType CNA_Init(const CNA_ConfigType *config)
{
    Std_ReturnType ret = E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(TRUE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if(NULL_PTR == config)
    {
        ret = E_NOT_OK;
    }
    else if((NULL_PTR == config->signalConfigs) || 
        (NULL_PTR == config->signalDatas) ||
        (NULL_PTR == config->noActionBuffer))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        cna.config = config;
        cna.isInit = TRUE;
    }

    return ret;
}

/*
* @brief   :   deinit com no action module
* @param   :   none
* @retval  :   E_OK: initialize success
* @retval  :   E_NOT_OK: module is not initialized
*/
static Std_ReturnType CNA_DeInit(void)
{
    Std_ReturnType ret = E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        cna.isInit = FALSE;
        cna.config = NULL_PTR;
    }

    return ret;
}

/*
* @brief   :   callback function used in signal confirmation
* @param   :   signalId: signal id to set
* @retval  :   none
*/
void CNA_SignalCallback(uint16 signalId)
{
    Std_ReturnType ret = E_OK;

    /* error check */
#if(CNA_DEV_ERROR_DETECT == STD_ON)
    if(FALSE == cna.isInit)
    {
        ret = E_NOT_OK;
    }
    else if(signalId >= cna.config->signalNumber)
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
        const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];

        switch(signalCfg->actiontype)
        {
            case CNA_BEHAVIOR_NONE:
            CNA_BehaviorNoneHandle(signalId);
            break;

            case CNA_BEHAVIOR_UNSEND:
            CNA_BehaviorUnsendHandle(signalId);
            break;

            case CNA_BEHAVIOR_SEND:
            CNA_BehaviorSendHandle(signalId);
            break;

            case CNA_BEHAVIOR_CYCLE:
            CNA_BehaviorCycleHandle(signalId);
            break;

            default:
            ret = E_NOT_OK;
            break;
        }
    }

    (void)ret;
}

/*
* @brief   :   behavior none handle
* @param   :   signalId: signal id to set
* @retval  :   none
*/
static void CNA_BehaviorNoneHandle(uint16 signalId)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
    uint8 count = cna.config->signalDatas[signalId].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(signalId, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",signalId,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        else
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
        cna.config->signalDatas[signalId].counter = count;
    }
}

/*
* @brief   :   behavior unsend handle
* @param   :   signalId: signal id to set
* @retval  :   none
*/
static void CNA_BehaviorUnsendHandle(uint16 signalId)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
    uint8 count = cna.config->signalDatas[signalId].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            (void)Com_SendSignal(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart]);
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(signalId, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",signalId,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        else
        {
            Com_TriggerIPDUSend(signalCfg->comIPduId);
        }
        cna.config->signalDatas[signalId].counter = count;
    }
}

/*
* @brief   :   behavior send handle
* @param   :   signalId: signal id to set
* @retval  :   none
*/
static void CNA_BehaviorSendHandle(uint16 signalId)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
    uint8 count = cna.config->signalDatas[signalId].counter;

    if(count > 0u)
    {
        count--;
        if((signalCfg->repetition - 1u) == count)
        {
            (void)Com_SendSignal(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart]);
            Rte_Call_rpCS_IPC_TransmitSignal_Callback(signalId, &cna.config->currentBuffer[signalCfg->currentStart]);
            can_warn("CNA ID=%d,value=%d",signalId,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        Com_TriggerIPDUSend(signalCfg->comIPduId);
        cna.config->signalDatas[signalId].counter = count;
    }
}

/*
* @brief   :   behavior cycle handle
* @param   :   signalId: signal id to set
* @retval  :   none
*/
static void CNA_BehaviorCycleHandle(uint16 signalId)
{
    const CNA_SignalConfigType *signalCfg = &cna.config->signalConfigs[signalId];
    uint8 count = cna.config->signalDatas[signalId].counter;

    if(count > 0u)
    {
        count--;
        if(0u == count)
        {
            (void)Com_SendSignal(signalCfg->comSignalId, &cna.config->noActionBuffer[signalCfg->noActionStart]);
            Rte_Call_rpCS_IPC_API_SetEventTxSignalBuffer_Operation(signalId, (uint8 *)&cna.config->noActionBuffer[signalCfg->noActionStart]);
            can_warn("CNA ID=%d,value=%d",signalId,cna.config->currentBuffer[signalCfg->currentStart]);
        }
        cna.config->signalDatas[signalId].counter = count;
    }
}

FUNC(boolean, COM_APPL_CODE) Com_IPduTransmitCallout(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint16   PduIdIndex = 0x00;
    boolean  retValue = TRUE;
    
    CAN_SERVER_IGNORE_UNREF_PARAM(PduInfoPtr);

    #ifdef GWM_V35_PROJECT_TYPE_B03
        for(PduIdIndex = 0; PduIdIndex < DISABLE_PDU_NUMBER; PduIdIndex++)
        {
            if(Com_Disable_Pdu_SendorReceive_Cfg.TxPduId[PduIdIndex] == PduId)
            {
                retValue = FALSE;
                break;
            }
        }
    #endif 
    
    return retValue;
}
/******************************************************************************/
/**
* @brief               <Com_IPduReceiveCallout_Init>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static FUNC(void, Can_Server_CODE) Com_IPduReceiveCallout_Init(void)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        /* Pdu notify up layer in default */
        Com_SetRxPduEnableFlag(PduIdIndex,FALSE);
    }
}

/******************************************************************************/
/**
* @brief               <Com_IPduEnableHandle>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <CanIdType CanId,boolean EnableFlag:TRUE will disable Pdu Receive,FALSE 
                        will receive the Pdu>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <retValue:type boolean,call the function successful will return TRUE>    
*/
/******************************************************************************/
FUNC(boolean, Can_Server_CODE) Com_IPduEnableHandle(uint16 CanId, boolean EnableFlag)
{
    Com_RxPdu_SizeOfType   PduIdIndex = 0x00;
    Com_RxPdu_SizeOfType   CanIdMapIndex = 0xFF;
    boolean                retValue = FALSE;
    Com_Disable_RxPdu_Receive_Info Com_Disable_CurrentRxPdu_Cfg;
    
    Com_Disable_CurrentRxPdu_Cfg = Com_IPduEnable_VarCfgPtr();

    /* get index CanId in arr*/
    for(PduIdIndex = 0x00; PduIdIndex < CanServer_Disable_Rx_PDU_Number();PduIdIndex++)
    {
        if((Com_Disable_CurrentRxPdu_Cfg.RxPduMapCanId[PduIdIndex]) == CanId)
        {
            CanIdMapIndex = PduIdIndex;
        }
    }

    if(CanIdMapIndex != 0xFF)
    {
        /* set target Pdu enable status */
        Com_SetRxPduEnableFlag(CanIdMapIndex,EnableFlag);

        if(Com_GetRxPduEnableFlag(CanIdMapIndex) == EnableFlag)
        {
            retValue = TRUE;
        }
    }

    return retValue;
}


FUNC(void, CANIF_CODE) CanIf_TransmitSubDataChecksumTxAppend(P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK) txPduInfoPtr, P2VAR(uint8, AUTOMATIC, CANIF_VAR_STACK) txPduDataWithChecksumPtr)
{
    uint8 index = 0;

    if(((uint16)0x7B3 & (txPduInfoPtr->id)) == (uint16)0x7B3) 
    {
        if((txPduInfoPtr->sdu[0] == 0x03)  && (txPduInfoPtr->sdu[1] == 0x7F) && (txPduInfoPtr->sdu[3] == 0x31))
        {
            can_info("Service=0x%x,NRC=0x%x",txPduInfoPtr->sdu[2],txPduInfoPtr->sdu[3]);
        }
        else if((txPduInfoPtr->sdu[0] == 0x03)  && (txPduInfoPtr->sdu[1] == 0x7F) && (txPduInfoPtr->sdu[2] == 0x27) && (txPduInfoPtr->sdu[3] == 0x35))
        {
            can_info("Service=0x%x,NRC=0x%x",txPduInfoPtr->sdu[2],txPduInfoPtr->sdu[3]);
        }
        
        for(index = 0; index < txPduInfoPtr->length;index++)
        {
            txPduDataWithChecksumPtr[index] = txPduInfoPtr->sdu[index];
        }
    }
}

static FUNC(void, Can_Server_CODE) CanServer_FormatErrorInit(void)
{
    uint8 formatErrIndex = 0x00;
    
    /* init  arguments */
    while(formatErrIndex < CAN_FORMATERR_NUMBER)
    {
        CANFormatErrFlg[formatErrIndex] = FALSE;
		formatErrIndex++;
    }

}


/* Can format error will report SOC*/
static FUNC(void, Can_Server_CODE) CanServer_FormatErrorHandle(void)
{
    uint8 formatErrIndex = 0x00;

    while(formatErrIndex < CAN_FORMATERR_NUMBER)
    {
        if((*((uint32*)(CANFormatErrCfgInfoRecord[formatErrIndex].CANChanErrFlagRegisterAddr))) & CANFormatErrCfgInfoRecord[formatErrIndex].CANChanFormatErrMask)
        {
            if(FALSE == CANFormatErrFlg[formatErrIndex])
            {
                CANFormatErrFlg[formatErrIndex] = TRUE;
                can_info("Can %d Format Error",CANFormatErrCfgInfoRecord[formatErrIndex].CANChanNum); /* test: CANH connect Ground*/
            }
        }
        formatErrIndex++;
    }
}



FUNC(void , Can_Server_CODE) CanServer_SecOCBusOffEndStatusSet(boolean busoffEndFlag)
{
    SecOCBusOffReocrd.BusOffStatusFlag = busoffEndFlag;
}

FUNC(boolean , Can_Server_CODE) CanServer_SecOCBusOffEndStatusGet(void)
{
    return SecOCBusOffReocrd.BusOffStatusFlag;
}

FUNC(boolean, COM_APPL_CODE) HUT_IP2_E2E_Handle(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduId = PduId;
    PduInfoPtr = PduInfoPtr;
    
    Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT_IP2_Callback();

    return TRUE;
}

FUNC(boolean, COM_APPL_CODE) HUT32_E2E_Handle(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduId = PduId;
    PduInfoPtr = PduInfoPtr;
    
    Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_HUT32_CallBack();

    return TRUE;
}

FUNC(boolean, COM_APPL_CODE) DMS_FD1_E2E_Handle(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduId = PduId;
    PduInfoPtr = PduInfoPtr;
    
    Rte_Call_rpCS_IPC_Tx_E2E_CanMsg_DMS_FD1_CallBack();

    return TRUE;
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
