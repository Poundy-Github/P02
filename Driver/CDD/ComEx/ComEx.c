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
 *             File:  ComEx.c
 *           Config:  E:/Project/V3_5_VIP/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  ComEx
 *  Generation Time:  2021-03-15 10:46:21
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <ComEx>
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
 * ComEx_SignalGroupIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * ComEx_SignalIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_ComEx.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "ComEx.h"
#include "vstdlib.h"
#include "E2E_P01.h"
extern const uint8 ComEx_TxInitValueBuffer[ComEx_TxInitValueBufferSize];
#define COMEX_CAST2UINT8(argument)                          ((uint8) (argument))
#define ComEx_Signal_BitOffsetFromBitPos(pos)               (COMEX_CAST2UINT8((pos) & 7u))
#define ComEx_NBITNBYTE_GetEndiannesIndex(bufferIndex, isBusBigEndian) (((isBusBigEndian) == TRUE) ? (-(bufferIndex)) : (bufferIndex))

#define COMEX_INITIAL_ID_INVALID                            (65535u)
#define COMEX_TIMEOUT_ID_INVALID                            (65535u)
#define COMEX_E2E_ID_INVALID                                (65535u)

#define ComEx_GetRxSigConfig()                              ComEx_RxSigInfo
#define ComEx_GetRxGroupConfig()                            ComEx_RxGroupInfo
#define ComEx_GetRxPduConfig()                              ComEx_RxPduInfo
#define ComEx_GetRxE2eConig()                               ComEx_RxE2eInfo
#define ComEx_GetRxInitValueConfig()                        ComEx_RxSigInitValueInfo
#define ComEx_GetRxTimeoutConfig()                          ComEx_RxSigTimeoutInfo
#define ComEx_GetPduAttribute()                             ComEx_RxPduAttribute
#define ComEx_GetSigAttribute()                             ComEx_RxSigAttribute
#define ComEx_GetRxE2eAttribute()                           ComEx_RxE2eAttribute
#define ComEx_GetRxPduBuffer()                              ComEx_RxPduBuffer
#define ComEx_GetRxInitValueBuffer()                        ComEx_RxInitValueBuffer
#define ComEx_GetTimeoutBuffer()                            ComEx_RxTimeoutBuffer
#define ComEx_GetRxSignalBuffer()                           ComEx_RxSignalBuffer
#define ComEx_GetRxPduCalloutConfig()                       ComEx_RxPduCalloutIdx

#define ComEx_GetTxSigConfig()                              ComEx_TxSigInfo
#define ComEx_GetTxBufferConfig()                           ComEx_TxBuffer
#define ComEx_GetTxPduConfig()                              ComEx_TxPduInfo
#define ComEx_GetTxGroupConfig()                            ComEx_TxGroupInfo
#define ComEx_GetTxE2eConig()                               ComEx_TxE2eInfo
#define ComEx_GetTxPduCalloutConfig()                       ComEx_TxPduCalloutIdx
#define ComEx_GetTxInitValueBuffer()                        ComEx_TxInitValueBuffer

#define ComEx_PduCalloutFunPtrConfig()                      ComEx_PduCalloutFunPtrTable

/*Rx Signal MACRO DEFINE*/
#define ComEx_GetSizeOfRxSig()                              ComEx_RxSignalSize
#define ComEx_GetAddrRxSignalBuffer(Index)                  (&(ComEx_GetRxSignalBuffer()[(Index)]))
#define ComEx_GetRxSigInfoBitLength(Index)                  (ComEx_GetRxSigConfig()[(Index)].BitLength)
#define ComEx_GetRxSigInfoBitPosition(Index)                (ComEx_GetRxSigConfig()[(Index)].BitPosition)
#define ComEx_GetRxSigInfoByteLength(Index)                 (ComEx_GetRxSigConfig()[(Index)].ByteLength)
#define ComEx_GetRxSigInfoBytePosition(Index)               (ComEx_GetRxSigConfig()[(Index)].BytePosition)
#define ComEx_GetRxSigInfoPduIdx(Index)                     (ComEx_GetRxSigConfig()[(Index)].PduIdx)
#define ComEx_GetRxSigTimeoutIdx(Index)                     (ComEx_GetRxSigConfig()[(Index)].TimeoutIdx)   
#define ComEx_GetRxSigInitValueIdx(Index)                   (ComEx_GetRxSigConfig()[(Index)].InitValueIdx)   
#define ComEx_GetRxSigInfoApplType(Index)                   (ComEx_GetRxSigConfig()[(Index)].ApplType) 
#define ComEx_GetRxSigInfoBusAccType(Index)                 (ComEx_GetRxSigConfig()[(Index)].BusAccType)
#define ComEx_GetRxSigInfoAppAccByteLength(Index)           (ComEx_GetRxSigConfig()[(Index)].AppAccBtyeLength)
#define ComEx_GetRxSigInfoAppAccBytePosition(Index)         (ComEx_GetRxSigConfig()[(Index)].AppAccBytePosition)

#define ComEx_GetRxSigStatus(Index)                         (ComEx_GetSigAttribute()[(Index)].Status)
#define ComEx_ClearRxSigStatus(Index, Value)                ((ComEx_GetSigAttribute()[(Index)].Status) &= (~(Value)))
#define ComEx_SetRxSigStatus(Index, Value)                  ((ComEx_GetSigAttribute()[(Index)].Status) |= (Value))
#define ComEx_IsRxSigTimeoutActive(Index)                   (ComEx_GetRxSigTimeoutIdx(Index) != COMEX_TIMEOUT_ID_INVALID)
#define ComEx_IsRxSigInitValueActive(Index)                 (ComEx_GetRxSigInitValueIdx(Index) != COMEX_INITIAL_ID_INVALID)


/*Rx GROUP MACRO DEFINE*/
#define ComEx_GetSizeOfRxGroup()                            ComEx_RxGroupSize
#define ComEx_GetRxGroupE2eIdx(Index)                       (ComEx_GetRxGroupConfig()[(Index)].E2eIdx)
#define ComEx_GetRxGroupInfoPduIdx(Index)                   (ComEx_GetRxGroupConfig()[(Index)].PduIdx)
#define ComEx_GetRxGroupInfoBytePosition(Index)             (ComEx_GetRxGroupConfig()[(Index)].BytePosition)
#define ComEx_IsRxGroupE2eActive(Index)                     (ComEx_GetRxGroupE2eIdx(Index) != COMEX_E2E_ID_INVALID)

/*Rx PDU MACRO DEFINE*/
#define ComEx_GetSizeOfRxPdu()                              ComEx_RxPduSize
#define ComEx_GetAddrRxPduBuffer(Index)                     (&(ComEx_GetRxPduBuffer()[(Index)]))
#define ComEx_GetRxPduCalloutIdx(Index)                     (ComEx_GetRxPduCalloutConfig()[(Index)])
#define ComEx_GetRxPduInfoTimer(Index)                      (ComEx_GetPduAttribute()[(Index)].Timer)
#define ComEx_GetRxPduInfoGroupStartIdx(Index)              (ComEx_GetRxPduConfig()[(Index)].GroupStartIdx)  
#define ComEx_GetRxPduInfoGroupEndIdx(Index)                (ComEx_GetRxPduConfig()[(Index)].GroupEndIdx)
#define ComEx_GetRxPduInfoSignalStartIdx(Index)             (ComEx_GetRxPduConfig()[(Index)].SignalStartIdx)  
#define ComEx_GetRxPduInfoSignalEndIdx(Index)               (ComEx_GetRxPduConfig()[(Index)].SignalEndIdx)  
#define ComEx_GetRxPduInfoBufferPosition(Index)             (ComEx_GetRxPduConfig()[(Index)].BufferPosition)
#define ComEx_GetRxPduInfoBufferLength(Index)               (ComEx_GetRxPduConfig()[(Index)].BufferLength)
#define ComEx_GetRxPduInfoCalloutNum(Index)                 (ComEx_GetRxPduConfig()[(Index)].CalloutNum)
#define ComEx_GetRxPduInfoCalloutStartIdx(Index)            (ComEx_GetRxPduConfig()[(Index)].CalloutStartIdx)
#define ComEx_SetRxPduInfoTimer(Index, Value)               (ComEx_GetPduAttribute()[(Index)].Timer = (Value))    
#define ComEx_IsRxPduGroupActive(Index)                     (ComEx_GetRxPduInfoGroupStartIdx(Index) != ComEx_GetRxPduInfoGroupEndIdx(Index))  


/* Rx Signal MACRO DEFINE */
#define ComEx_SpecInfoBufferSize                            2u
#define ComEx_GetSpecInfoConfig()                           ComEx_SpecInfoBuffer
#define ComEx_GetSpecSignalIdOfSpecInfo(Index)              (ComEx_GetSpecInfoConfig()[Index].SpecSignalId)
#define ComEx_GetSpecSignalValueOfSpecInfo(Index)           (ComEx_GetSpecInfoConfig()[Index].SpecSignalValue)

/*Rx E2E MACRO DEFINE*/
#define ComEx_GetRxE2EInfoInitFunptr(Index)                 (ComEx_GetRxE2eConig()[Index].InitFunPtr)
#define ComEx_GetRxE2EInfoReadFunptr(Index)                 (ComEx_GetRxE2eConig()[Index].ReadFunPtr)
#define ComEx_GetRxE2eStatus(Index)                         (ComEx_GetRxE2eAttribute()[(Index)].Status)
#define ComEx_SetRxE2eStatus(Index, Value)                  (ComEx_GetRxE2eAttribute()[(Index)].Status = (Value))

/*Rx Initial Value MACRO DEFINE*/
#define ComEx_GetAddrRxInitValueBuffer(Index)               (&(ComEx_GetRxInitValueBuffer()[(Index)]))
#define ComEx_GetRxInitValueInfoByteLength(Index)           (ComEx_GetRxInitValueConfig()[(Index)].BtyeLength)
#define ComEx_GetRxInitValueBufferBtyePosition(Index)       (ComEx_GetRxInitValueConfig()[(Index)].BtyePosition)


/*Rx Timeout MACRO DEFINE*/
#define ComEx_GetAddrRxTimeoutBuffer(Index)                 (&(ComEx_GetTimeoutBuffer()[(Index)]))
#define ComEx_GetRxTimeoutMax(Index)                        (ComEx_GetRxTimeoutConfig()[(Index)].TimeoutMax)   
#define ComEx_GetRxTimeoutInfoByteLength(Index)             (ComEx_GetRxTimeoutConfig()[(Index)].BtyeLength)
#define ComEx_GetRxTimeoutBufferBtyePosition(Index)         (ComEx_GetRxTimeoutConfig()[(Index)].BtyePosition)
#define ComEx_IsRxTimeoutValueActive(Index)                 (ComEx_GetRxTimeoutInfoByteLength(Index) != COMEX_TIMEOUT_ID_INVALID)

/*Tx Signal MACRO DEFINE*/
#define ComEx_GetSizeOfTxSig()                              ComEx_TxSignalSize
#define ComEx_GetAddrTxBuffer(Index)                        (&(ComEx_GetTxBufferConfig()[(Index)]))
#define ComEx_GetTxSigInfoPduIdx(Index)                     (ComEx_GetTxSigConfig()[(Index)].PduIdx)
#define ComEx_GetTxSigInfoBitLength(Index)                  (ComEx_GetTxSigConfig()[(Index)].BitLength)
#define ComEx_GetTxSigInfoBitPosition(Index)                (ComEx_GetTxSigConfig()[(Index)].BitPosition)
#define ComEx_GetTxSigInfoByteLength(Index)                 (ComEx_GetTxSigConfig()[(Index)].ByteLength)
#define ComEx_GetTxSigInfoBytePosition(Index)               (ComEx_GetTxSigConfig()[(Index)].BytePosition)
#define ComEx_GetTxSigInfoBufferStartIdx(Index)             (ComEx_GetTxSigConfig()[(Index)].BufferStartIdx)
#define ComEx_GetTxSigInfoBufferEndIdx(Index)               (ComEx_GetTxSigConfig()[(Index)].BufferEndIdx)
#define ComEx_GetTxSigInfoBusAccType(Index)                 (ComEx_GetTxSigConfig()[(Index)].BusAccType)
#define ComEx_GetTxSigInfoBusAccByteLength(Index)           (ComEx_GetTxSigConfig()[(Index)].BusAccBtyeLength)
#define ComEx_GetTxSigInfoSendType(Index)                   (ComEx_GetTxSigConfig()[(Index)].SendType)
#define ComEx_GetTxSigInfoTxAckFuncPtr(Index)               (ComEx_GetTxSigConfig()[(Index)].TxAckFuncPtr)
#define ComEx_GetTxBufferLengthOfTxSigInfo(Index)           ((uint8)((ComEx_GetTxSigInfoBufferEndIdx(Index) - ComEx_GetTxSigInfoBufferStartIdx(Index))))  /**< the number of relations pointing to Com_TxBuffer */

#define ComEx_GetTxBuffer(Index)                            ComEx_GetTxBufferConfig()[(Index)]
#define ComEx_SetTxBuffer(Index, Value)                     ComEx_GetTxBufferConfig()[(Index)] = (Value)

/*Tx PDU MACRO DEFINE*/
#define ComEx_GetSizeOfTxPdu()                              ComEx_TxPduSize
#define ComEx_GetAddrTxPduBuffer(Index)                     (&(ComEx_GetTxBufferConfig()[(Index)]))
#define ComEx_GetAddrTxInitValueBuffer(Index)               (&(ComEx_GetTxInitValueBuffer()[(Index)]))
#define ComEx_GetTxPduCalloutIdx(Index)                     (ComEx_GetTxPduCalloutConfig()[(Index)])
#define ComEx_GetTxPduInfoGroupStartIdx(Index)              (ComEx_GetTxPduConfig()[(Index)].GroupStartIdx)  
#define ComEx_GetTxPduInfoGroupEndIdx(Index)                (ComEx_GetTxPduConfig()[(Index)].GroupEndIdx)
#define ComEx_GetTxPduInfoBufferPosition(Index)             (ComEx_GetTxPduConfig()[(Index)].BufferPosition)
#define ComEx_GetTxPduInfoBufferLength(Index)               (ComEx_GetTxPduConfig()[(Index)].BufferLength)
#define ComEx_GetTxPduInfoSignalStartIdx(Index)             (ComEx_GetTxPduConfig()[(Index)].SignalStartIdx)  
#define ComEx_GetTxPduInfoSignalEndIdx(Index)               (ComEx_GetTxPduConfig()[(Index)].SignalEndIdx)  
#define ComEx_GetTxPduInfoCalloutNum(Index)                 (ComEx_GetTxPduConfig()[(Index)].CalloutNum)
#define ComEx_GetTxPduInfoCalloutStartIdx(Index)            (ComEx_GetTxPduConfig()[(Index)].CalloutStartIdx)
#define ComEx_IsTxPduGroupActive(Index)                     (ComEx_GetTxPduInfoGroupStartIdx(Index) != ComEx_GetTxPduInfoGroupEndIdx(Index))  

/*Tx GROUP MACRO DEFINE*/
#define ComEx_GetSizeOfTxGroup()                            ComEx_TxGroupSize
#define ComEx_GetTxGroupE2eIdx(Index)                       (ComEx_GetTxGroupConfig()[(Index)].E2eIdx)
#define ComEx_GetTxGroupInfoPduIdx(Index)                   (ComEx_GetTxGroupConfig()[(Index)].PduIdx)
#define ComEx_GetTxGroupInfoBytePosition(Index)             (ComEx_GetTxGroupConfig()[(Index)].BytePosition)
#define ComEx_IsTxGroupE2eActive(Index)                     (ComEx_GetTxGroupE2eIdx(Index) != COMEX_E2E_ID_INVALID)

/*Tx E2E MACRO DEFINE*/
#define ComEx_GetTxE2EInfoInitFunptr(Index)                 (ComEx_GetTxE2eConig()[(Index)].InitFunPtr)
#define ComEx_GetTxE2EInfoWriteFunptr(Index)                (ComEx_GetTxE2eConig()[(Index)].WriteFunPtr)

#define ComEx_GetRxPduCalloutFunPtr(Index)                   ComEx_PduCalloutFunPtrConfig()[(Index)].PduRxCalloutFunPtr    
#define ComEx_GetTxPduCalloutFunPtr(Index)                   ComEx_PduCalloutFunPtrConfig()[(Index)].PduTxCalloutFunPtr    

#define ComEx_IncreaseTick()      (ComEx_ReceiverTimer++)
#define ComEx_IsRxTimeoutActive()  (ComEx_RxTimeoutActive != FALSE)

#define ComEx_SetRxSigBufferUInt8(Pdata, Value)     ((*(uint8*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferSInt8(Pdata, Value)     ((*(sint8*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferUInt16(Pdata, Value)    ((*(uint16*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferSInt16(Pdata, Value)    ((*(sint16*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferUInt32(Pdata, Value)    ((*(uint32*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferSInt32(Pdata, Value)    ((*(sint32*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferUInt64(Pdata, Value)    VStdMemCpyRamToRam((uint8 *)Pdata, (const uint8 *)&Value, 8)
#define ComEx_SetRxSigBufferSInt64(Pdata, Value)    VStdMemCpyRamToRam((uint8 *)Pdata, (const uint8 *)&Value, 8)
#define ComEx_SetRxSigBufferFloat32(Pdata, Value)   ((*(float*)(Pdata)) = (Value))
#define ComEx_SetRxSigBufferFloat64(Pdata, Value)   ((*(double*)(Pdata)) = (Value))


#define       COMEX_GET_TXPDU_STS(signalId)                         (ComSendSignalStatus[signalId])
#define       COMEX_SET_TXPDU_STS(signalId,sts)                     (ComSendSignalStatus[signalId] = (sts))

#define ComEx_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static uint8 ComEx_RxTimeoutActive = 0u; 
static uint64 ComEx_ReceiverTimer = 0u;

static uint8 ComEx_TxBuffer[ComEx_TxPduBufferSize] = {0u};

static uint8 ComEx_RxPduBuffer[ComEx_RxPduBufferSize] = {0u};
static uint8 ComEx_RxSignalBuffer[ComEx_RxSignalBufferSize] = {0u};
static const ComEx_SepcInfoType ComEx_SpecInfoBuffer[ComEx_SpecInfoBufferSize] = 
{
    { COMEX_SIGNAL_RX_SYSPOWERMOD, 0 },
    { COMEX_SIGNAL_RX_DRVDOORSTS, 0},
};

static uint8 ComSendSignalStatus[ComEx_TxSignalSize] = {0};

#define ComEx_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 

static ComEx_RxE2eAttributeType ComEx_RxE2eAttribute[ComEx_RxE2eSize] = {0u};
static ComEx_RxPduAttributeType ComEx_RxPduAttribute[ComEx_RxPduSize] = {0u};
static ComEx_RxSigAttributeType ComEx_RxSigAttribute[ComEx_RxSignalSize] = {0u};

#pragma ghs section bss = default 
#pragma ghs section data = default 

static void ComEx_RxInit(void);
static void ComEx_TxInit(void);
static void ComEx_RxTimerTask(void);
static void ComEx_SetComStoppedSingalValue(void);
static void ComEx_UpdataRxPduTimer(ComEx_IpduGroupIdType PduId);
static boolean ComEx_IsReceiveTimeOut(ComEx_SignalIdType SignalId);
static void ComEx_EventSignalProcessing(ComEx_SignalIdType SignalId);
static void ComEx_UpdataRxPduSignalStatus(ComEx_IpduGroupIdType PduId);
static void ComEx_SetSignalBufferValue(ComEx_SignalIdType SignalId, uint32 Value);
static void ComEx_SetRxInitValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr);
static void ComEx_SetRxSignalValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr);
static void ComEx_SetRxTimeoutValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr);
static void ComEx_SetRxTimeoutValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr);
static void ComEx_RxSignalProcessing(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static Std_ReturnType ComEx_ReceiveSignalGroupProcessing(ComEx_SignalGroupIdType GroupId);
static Std_ReturnType ComEx_TransmitSignalGroupProcessing(ComEx_SignalGroupIdType GroupId);
static void ComEx_RxSignalProcessing_UINT8(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_UINT8(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_SINT8(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_UINT16(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_SINT16(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_UINT32(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_SINT32(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_UINT64(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_SINT64(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_FLOAT32(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_FLOAT64(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_RxSignalProcessing_UINT8_N(ComEx_SignalIdType SignalId, void* SignalDataPtr);
static void ComEx_SendSignal_Processing(ComEx_SignalIdType SignalId, const void* SignalDataPtr);
static void ComEx_GetSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata);
static uint8 ComEx_Signal_ReadSignal_UInt8(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static sint8 ComEx_Signal_ReadSignal_SInt8(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static uint16 ComEx_Signal_ReadSignal_UInt16(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static sint16 ComEx_Signal_ReadSignal_SInt16(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static uint32 ComEx_Signal_ReadSignal_UInt32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static sint32 ComEx_Signal_ReadSignal_SInt32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static uint64 ComEx_Signal_ReadSignal_UInt64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static sint64 ComEx_Signal_ReadSignal_SInt64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static float32 ComEx_Signal_ReadSignal_Float32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static float64 ComEx_Signal_ReadSignal_Float64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr);
static void ComEx_Signal_ReadSignalSignExtension_SINT8(ComEx_SignalIdType SignalId, ComEx_uSignExt8BitType* signExtValue);      
static void ComEx_Signal_ReadSignalSignExtension_SINT16(ComEx_SignalIdType SignalId, ComEx_uSignExt16BitType* signExtValue);    
static void ComEx_Signal_ReadSignalSignExtension_SINT32(ComEx_SignalIdType SignalId, ComEx_uSignExt32BitType* signExtValue);     
static void ComEx_Signal_ReadSignalSignExtension_SINT64(ComEx_SignalIdType SignalId, ComEx_uSignExt64BitType* signExtValue) ;   
static void ComEx_Signal_ReadSignalApplTypeSpecific(ComEx_SignalIdType SignalId,uint8* SignalApplDestPtr,uint8* SignalBusSourcePtr, uint32 destLength);
static void ComEx_Signal_ReadSignal_LB_NBITNBYTE(ComEx_SignalIdType SignalId, uint8* SignalApplDestPtr, uint8* SignalBusSourcePtr, uint16 signalStartBit, uint32 destLength);
static void ComEx_Signal_ReadSignal_LB_SW_NBITNBYTE(ComEx_SignalIdType SignalId, uint8* SignalApplDestPtr, uint8* SignalBusSourcePtr, uint16 signalStartBit, uint32 destLength);
static void ComEx_Signal_WriteSignal_NBITNBYTE(ComEx_SignalIdType SignalId, const uint8* SignalApplSourcePtr, uint16 signalStartBit, uint8* SignalBusDestPtr, boolean isBusBigEndian);


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
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define ComEx_START_SEC_CODE
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComEx_GetRxE2EStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetRxE2EStatus> of PortPrototype <ComEx>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ComEx_COMEX_ERROR_PARAM
 *   RTE_E_ComEx_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_GetRxE2EStatus_doc
 *********************************************************************************************************************/


uint8 ComEx_SignalGetSendStatus( uint16 signalId) 
{
  return  COMEX_GET_TXPDU_STS(signalId);
} 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ComEx_CODE) ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMEX_APPL_VAR) E2eStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_GetRxE2EStatus (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_OK; 

    uint32 E2eStatusOk =
           (0<<31)                         /* Deserial-Check */
        |  ((E2E_P01STATUS_OK & 0x7F)<<24) /* ReceiverStatus */
        |  (E2E_E_OK<<16)                  /* Protection Wrapper */
        |  (E_OK<<8)                       /* Rte_Read */
        |  (E2E_E_OK);                     /* E2E_...Check */
        
    *E2eStatus = E2eStatusOk;

    if( GroupId >= ComEx_GetSizeOfRxGroup())
    {
        ret = COMEX_ERROR_PARAM;

        *E2eStatus |= E2E_E_INPUTERR_WRONG;
    }
    else
    {
        if(ComEx_IsRxGroupE2eActive(GroupId))
        {
            *E2eStatus = ComEx_GetRxE2eStatus(ComEx_GetRxGroupE2eIdx(GroupId));
        }
        else
        {
            ret = COMEX_ERROR_PARAM;

            *E2eStatus |= E2E_E_INPUTERR_WRONG;
        }
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComEx_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ComEx_CODE) ComEx_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_Init
 *********************************************************************************************************************/
    ComEx_RxInit();
    ComEx_TxInit();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComEx_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ComEx_1_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_ComEx_1_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_ComEx_1_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_CNA_Signal_CallBack(uint16 signalId)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ComEx_CODE) ComEx_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_MainFunction
 *********************************************************************************************************************/
    ComEx_RxTimerTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComEx_ReceiveSignal
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReceiveSignal> of PortPrototype <ComEx>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_ComEx(void)
 *   void Rte_Exit_ExclusiveArea_ComEx(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ComEx_COMEX_ERROR_PARAM
 *   RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED
 *   RTE_E_ComEx_COMEX_NEVER_RECEIVED
 *   RTE_E_ComEx_COMEX_UPDATE_RECEIVED
 *   RTE_E_ComEx_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_ReceiveSignal_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ComEx_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_ReceiveSignal (returns application error)
 *********************************************************************************************************************/
    
    Std_ReturnType ret = E_OK; 

    if(SignalId >= ComEx_GetSizeOfRxSig())
    {
        ret = COMEX_ERROR_PARAM;
    }
    else if(Length != ComEx_GetRxSigInfoAppAccByteLength(SignalId))
    {
        ret = COMEX_ERROR_PARAM;
    }
    else if(SignalDataPtr == NULL_PTR)
    {
        ret = COMEX_ERROR_PARAM;
    }
    else 
    {
        Rte_Enter_ExclusiveArea_ComEx();

        ComEx_SetRxSignalValue(SignalId, SignalDataPtr);

        if (!Com_IsRxPduGrpActive(ComEx_GetRxSigInfoPduIdx(SignalId)))
        {
            ret = COMEX_COM_E_STOPPED;
        }
        else
        {
            if (ComEx_GetRxSigStatus(SignalId) & COMEX_RX_STATUS_NEVER_RECEIVED)
            {
                ret |= COMEX_NEVER_RECEIVED;
            }

            if (ComEx_IsReceiveTimeOut(SignalId))
            {
                ComEx_SetRxTimeoutValue(SignalId, SignalDataPtr);
                ret |= COMEX_MAX_AGE_EXCEEDED; 
            }

            if (ComEx_GetRxSigStatus(SignalId) & COMEX_RX_STATUS_UPDATE_RECEIVED)
            {   
                ComEx_ClearRxSigStatus(SignalId, COMEX_RX_STATUS_UPDATE_RECEIVED);
                ret |= COMEX_UPDATE_RECEIVED;
            }
        }

        Rte_Exit_ExclusiveArea_ComEx();
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComEx_SendSignal
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendSignal> of PortPrototype <ComEx>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CNA_SignalSet_Operation(uint16 signalId, uint8 *value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CNA_SignalSet_Std_ReturnType
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ComEx_COMEX_ERROR_PARAM
 *   RTE_E_ComEx_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_SendSignal_doc
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendGroup(ComTxCanPduValueInfor ComTxGroupValueInfor) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_SendSignal (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret_error_count = E_OK; 
    uint16 SignalId,SignalNum,SigIndex,PduIdSum;
    uint32 *SignalData;
    uint8 PduIndex;
    SignalNum = ComTxGroupValueInfor.AlcmSigSumNum;
    PduIdSum = ComTxGroupValueInfor.PduInfor.AlcmPduSumNum;
    Rte_Enter_ExclusiveArea_ComEx();

    for(SigIndex = 0; SigIndex < SignalNum; SigIndex++)
    {
        SignalId = ComTxGroupValueInfor.SigInfor[SigIndex].SigId;
        SignalData =  (&ComTxGroupValueInfor.SigInfor[SigIndex].SigValue);

        if(SignalId >= ComEx_GetSizeOfTxSig())
        {
            ret_error_count++;         
        }
        else 
        {                        
            ComEx_SendSignal_Processing(SignalId, SignalData);
        }
    }
    for(PduIndex = 0 ;PduIndex < PduIdSum; PduIndex++)
    {
       Com_TriggerIPDUSend(ComTxGroupValueInfor.PduInfor.AlcmPduIndex[PduIndex]);
    }      

    Rte_Exit_ExclusiveArea_ComEx();

    return ret_error_count;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComEx_SendSignal (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType ret = E_OK; 

    if(SignalId >= ComEx_GetSizeOfTxSig())
    {
        ret = COMEX_ERROR_PARAM;
    }
    else if(Length < ComEx_GetTxSigInfoBusAccByteLength(SignalId))
    {
        ret = COMEX_ERROR_PARAM;
    }
    else if(SignalDataPtr == NULL_PTR)
    {
        ret = COMEX_ERROR_PARAM;
    }
    else 
    {
        Rte_Enter_ExclusiveArea_ComEx();
        
        ComEx_SendSignal_Processing(SignalId, SignalDataPtr);

        ComEx_EventSignalProcessing(SignalId);

        Rte_Exit_ExclusiveArea_ComEx();
    }

    return ret;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ComEx_STOP_SEC_CODE
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define ComEx_START_SEC_CODE
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_RxInit(void)
{
    uint16 RxE2eIdx;
    uint16 SignalIdx;
    uint8* SignalRxVauleSrcPtr;
    
    for(RxE2eIdx = 0u; RxE2eIdx < ComEx_RxE2eSize; RxE2eIdx++)
    {
        ComEx_GetRxE2EInfoInitFunptr(RxE2eIdx)();
    }

    for(SignalIdx = 0u; SignalIdx < ComEx_RxSignalSize; SignalIdx++)
    {
        ComEx_SetRxSigStatus(SignalIdx ,COMEX_RX_STATUS_NEVER_RECEIVED);

        SignalRxVauleSrcPtr = ComEx_GetAddrRxSignalBuffer(ComEx_GetRxSigInfoAppAccBytePosition(SignalIdx));
        ComEx_SetRxInitValue(SignalIdx, SignalRxVauleSrcPtr); 
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_TxInit(void)
{
    uint16 TxE2eIdx;
    uint16 TxPduIdx;
    uint16 PduBufferPosition = 0;
    
    for(TxE2eIdx = 0u; TxE2eIdx < ComEx_TxE2eSize; TxE2eIdx++)
    {
        ComEx_GetTxE2EInfoInitFunptr(TxE2eIdx)();
    }
    
    for(TxPduIdx = 0u; TxPduIdx < ComEx_TxPduSize; TxPduIdx++)
    {
        uint16 SignalIdx;

        for(SignalIdx = ComEx_GetTxPduInfoSignalStartIdx(TxPduIdx); SignalIdx < ComEx_GetTxPduInfoSignalEndIdx(TxPduIdx); SignalIdx++)
        {
            COMEX_SET_TXPDU_STS(SignalIdx,COMEX_TX_PDU_STATUS_CONFIRMED);
        }
        PduBufferPosition = ComEx_GetTxPduInfoBufferPosition(TxPduIdx);
        VStdMemCpyRamToRam(ComEx_GetAddrTxPduBuffer(PduBufferPosition), ComEx_GetAddrTxInitValueBuffer(PduBufferPosition), ComEx_GetTxPduInfoBufferLength(TxPduIdx));        
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean ComEx_ReceivePduProcessing(ComEx_IpduGroupIdType PduId, const PduInfoType* PduInfoPtr)
{
    uint8 Idx;
    boolean ret = TRUE;
    uint8 CallOutFunPtridx;

    for(Idx = 0U; Idx < ComEx_GetRxPduInfoCalloutNum(PduId); Idx++)
    {
        CallOutFunPtridx = ComEx_GetRxPduCalloutIdx(Idx+ComEx_GetRxPduInfoCalloutStartIdx(PduId));
        
        ret &= ComEx_GetRxPduCalloutFunPtr(CallOutFunPtridx)(PduId, PduInfoPtr);
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean ComEx_TransmitPduProcessing(ComEx_IpduGroupIdType PduId, PduInfoType* PduInfoPtr)
{
    uint8 Idx;
    boolean ret = TRUE;
    uint8 CallOutFunPtridx;

    for(Idx = 0U; Idx < ComEx_GetTxPduInfoCalloutNum(PduId); Idx++)
    {
        uint16 SignalIdx;

        for(SignalIdx = ComEx_GetTxPduInfoSignalStartIdx(PduId); SignalIdx < ComEx_GetTxPduInfoSignalEndIdx(PduId); SignalIdx++)
        {
            COMEX_SET_TXPDU_STS(SignalIdx,COMEX_TX_PDU_STATUS_START_SEND);
        }

        CallOutFunPtridx = ComEx_GetTxPduCalloutIdx(Idx+ComEx_GetTxPduInfoCalloutStartIdx(PduId));
        
        ret &= ComEx_GetTxPduCalloutFunPtr(CallOutFunPtridx)(PduId, PduInfoPtr);
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean ComEx_ReceivePduSignalProcessing(ComEx_IpduGroupIdType PduId, const PduInfoType* PduInfoPtr)
{
    boolean ret = TRUE; 
    ComEx_SignalGroupIdType GroupId;
    uint16 PduBufferPosition;
    ComEx_SignalIdType SignalId;

    if(PduId >= ComEx_GetSizeOfRxPdu())
    {
        ret = FALSE;
    }
    else if(PduInfoPtr == NULL_PTR)
    {
        ret = FALSE;
    }
    else if(PduInfoPtr->SduDataPtr == NULL_PTR)
    {
        ret = FALSE;
    }
    else if(PduInfoPtr->SduLength != ComEx_GetRxPduInfoBufferLength(PduId))
    {
        ret = FALSE;
    }
    else
    {
        PduBufferPosition = ComEx_GetRxPduInfoBufferPosition(PduId);

        Rte_Enter_ExclusiveArea_ComEx();
        VStdMemCpyRamToRam(ComEx_GetAddrRxPduBuffer(PduBufferPosition), PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
        Rte_Exit_ExclusiveArea_ComEx();
        
        ComEx_UpdataRxPduTimer(PduId);
        
        ComEx_UpdataRxPduSignalStatus(PduId);

        if(ComEx_IsRxPduGroupActive(PduId))
        {            
            for(GroupId = ComEx_GetRxPduInfoGroupStartIdx(PduId); GroupId < ComEx_GetRxPduInfoGroupEndIdx(PduId); GroupId++)
            {
                ComEx_ReceiveSignalGroupProcessing(GroupId);
            }
        }

        for(SignalId = ComEx_GetRxPduInfoSignalStartIdx(PduId); SignalId < ComEx_GetRxPduInfoSignalEndIdx(PduId); SignalId++)
        {
    	    ComEx_RxSignalProcessing(SignalId, ComEx_GetAddrRxSignalBuffer(ComEx_GetRxSigInfoAppAccBytePosition(SignalId))); 
        }
    }
    
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType ComEx_ReceiveSignalGroupProcessing(ComEx_SignalGroupIdType GroupId)
{
    Std_ReturnType ret = E_OK; 
    ComEx_E2ETYPE E2edata;
    uint16 RxE2eIdx;
    
    if(GroupId >= ComEx_GetSizeOfRxGroup())
    {
        ret |= COMEX_ERROR_PARAM;
    }
    else
    {
        if(ComEx_IsRxGroupE2eActive(GroupId))
        {
            RxE2eIdx = ComEx_GetRxGroupE2eIdx(GroupId);
            ComEx_SetRxE2eStatus(RxE2eIdx, (ComEx_GetRxE2EInfoReadFunptr(RxE2eIdx))(&E2edata));
        }
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 ComEx_ReadSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata)
{
    uint16 PduIdx = ComEx_GetRxGroupInfoPduIdx(SignalGroupId);
    uint8* groupdata = ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxGroupInfoBytePosition(SignalGroupId));
    
    E2epdata->Checksum = groupdata[0];

    E2epdata->RollingCounter = 0x0F & groupdata[7];
    
    E2epdata->E2E_Data1[0] = groupdata[1];
    E2epdata->E2E_Data1[1] = groupdata[2];
    E2epdata->E2E_Data1[2] = groupdata[3];
    E2epdata->E2E_Data1[3] = groupdata[4];
    E2epdata->E2E_Data1[4] = groupdata[5];
    E2epdata->E2E_Data1[5] = groupdata[6];

    E2epdata->E2E_Data2 =  groupdata[7]>>4;

    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_RxSignalProcessing(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
      /* #10 process the passed signal signal type dependent */
    switch (ComEx_GetRxSigInfoApplType(SignalId))
    {
        case COMEX_UINT8_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_UINT8(SignalId, SignalDataPtr); /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_SINT8_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_SINT8(SignalId, SignalDataPtr); /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_UINT16_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_UINT16(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_SINT16_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_SINT16(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_UINT32_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_UINT32(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_SINT32_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_SINT32(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_UINT64_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_UINT64(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_SINT64_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_SINT64(SignalId, SignalDataPtr);        /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_FLOAT32_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_FLOAT32(SignalId, SignalDataPtr);       /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_FLOAT64_APPLTYPEOFRXACCESSINFO:
        {
            ComEx_RxSignalProcessing_FLOAT64(SignalId, SignalDataPtr);       /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO:   /* COV_COM_APPLTYPEOFRXACCESSINFO */
        {
            ComEx_RxSignalProcessing_UINT8_N(SignalId, SignalDataPtr);       /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */
            break;
        }
        case COMEX_ZEROBIT_APPLTYPEOFRXACCESSINFO:   /* COV_COM_APPLTYPEOFRXACCESSINFO */
        {
            break;    /* place holder for zeroBit Appl.Types. No signalProcessing shall be done */
        }
        default:   /* COV_COM_MISRA */
            break;
    }
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_UINT8
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_UINT8(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
  /* Check for buffer is not required as there is always a buffer configured. Removed check Com_IsBufferUsedOfRxAccessInfo */
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    uint8 tmpNewValue = ComEx_Signal_ReadSignal_UInt8(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));

    ComEx_SetRxSigBufferUInt8(SignalDataPtr, tmpNewValue);    /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_SINT8
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_SINT8(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
  /* Check for buffer is not required as there is always a buffer configured. Removed check Com_IsBufferUsedOfRxAccessInfo */
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    sint8 tmpNewValue = ComEx_Signal_ReadSignal_SInt8(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));      /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferSInt8(SignalDataPtr, tmpNewValue);    /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_UINT16
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_UINT16(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    uint16 tmpNewValue = ComEx_Signal_ReadSignal_UInt16(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferUInt16(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_SINT16
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_SINT16(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
  uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
  sint16 tmpNewValue = ComEx_Signal_ReadSignal_SInt16(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferSInt16(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_UINT32
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_UINT32(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    uint32 tmpNewValue = ComEx_Signal_ReadSignal_UInt32(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferUInt32(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_SINT32
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_SINT32(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    sint32 tmpNewValue = ComEx_Signal_ReadSignal_SInt32(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferSInt32(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_UINT64
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_UINT64(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    uint64 tmpNewValue = ComEx_Signal_ReadSignal_UInt64(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferUInt64(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_SINT64
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_SINT64(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    sint64 tmpNewValue = ComEx_Signal_ReadSignal_SInt64(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));    /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferSInt64(SignalDataPtr, tmpNewValue);   /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_FLOAT32
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_FLOAT32(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    float32 tmpNewValue = ComEx_Signal_ReadSignal_Float32(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));  /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferFloat32(SignalDataPtr, tmpNewValue);  /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_FLOAT64
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_FLOAT64(ComEx_SignalIdType SignalId, void* SignalDataPtr)
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    float64 tmpNewValue = ComEx_Signal_ReadSignal_Float64(SignalId, ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId)));  /* SBSW_COM_FCTCALL_WITH_P2CONST */

    ComEx_SetRxSigBufferFloat64(SignalDataPtr, tmpNewValue);  /* SBSW_COM_CSL03 */
}
/**********************************************************************************************************************
  Com_RxSignalProcessing_UINT8_N
**********************************************************************************************************************/
static void ComEx_RxSignalProcessing_UINT8_N(ComEx_SignalIdType SignalId, void* SignalDataPtr)  /* COV_COM_APPLTYPEOFRXACCESSINFO */
{
    uint16 PduIdx = ComEx_GetRxSigInfoPduIdx(SignalId);
    uint8* newValuePtr = ComEx_GetAddrRxPduBuffer(ComEx_GetRxPduInfoBufferPosition(PduIdx) + ComEx_GetRxSigInfoBytePosition(SignalId));

    VStdMemCpyRamToRam((uint8*)SignalDataPtr, newValuePtr, ComEx_GetRxSigInfoByteLength(SignalId));      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_COM_MEM_CPY_2RAM */

}       /* PRQA S 6030 */ /* MD_MSR_STCYC */
/**********************************************************************************************************************
  Com_Signal_ReadSignal_UInt8
**********************************************************************************************************************/
static uint8 ComEx_Signal_ReadSignal_UInt8(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  uint8 tmpNewValue = 0;

  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, &tmpNewValue, SignalBusSourcePtr, 1);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_SInt8
**********************************************************************************************************************/
static sint8 ComEx_Signal_ReadSignal_SInt8(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
    ComEx_uSignExt8BitType tmpNewValue; /* PRQA S 0759 */ /* MD_MSR_Union */

    tmpNewValue.signedAccess = 0;
    
    ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, &(tmpNewValue.unsignedAccess), SignalBusSourcePtr, 1); /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC */

    ComEx_Signal_ReadSignalSignExtension_SINT8(SignalId, &tmpNewValue);    /* SBSW_COM_FCTCALL_STACKPTR */

    return tmpNewValue.signedAccess;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_UInt16
**********************************************************************************************************************/
static uint16 ComEx_Signal_ReadSignal_UInt16(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  uint16 tmpNewValue = 0;
  uint8 *startBytePtr = &((uint8*) & tmpNewValue)[0];
  
  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, startBytePtr, SignalBusSourcePtr, 2);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_SInt16
**********************************************************************************************************************/
static sint16 ComEx_Signal_ReadSignal_SInt16(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
    ComEx_uSignExt16BitType tmpNewValue;        /* PRQA S 0759 */ /* MD_MSR_Union */

    tmpNewValue.signedAccess = 0;

    ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, &(tmpNewValue.unsignedAccess[0]), SignalBusSourcePtr, 2);      /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

    ComEx_Signal_ReadSignalSignExtension_SINT16(SignalId, &tmpNewValue);   /* SBSW_COM_FCTCALL_STACKPTR */

  return tmpNewValue.signedAccess;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_UInt32
**********************************************************************************************************************/
static uint32 ComEx_Signal_ReadSignal_UInt32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  uint32 tmpNewValue = 0;
  uint8 *startBytePtr = &((uint8*) & tmpNewValue)[0];

  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, startBytePtr, SignalBusSourcePtr, 4);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_SInt32
**********************************************************************************************************************/
static sint32 ComEx_Signal_ReadSignal_SInt32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
    ComEx_uSignExt32BitType tmpNewValue;        /* PRQA S 0759 */ /* MD_MSR_Union */

    tmpNewValue.signedAccess = 0;

    ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, &(tmpNewValue.unsignedAccess[0]), SignalBusSourcePtr, 4);      /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

    ComEx_Signal_ReadSignalSignExtension_SINT32(SignalId, &tmpNewValue);   /* SBSW_COM_FCTCALL_STACKPTR */

  return tmpNewValue.signedAccess;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_UInt64
**********************************************************************************************************************/
static uint64 ComEx_Signal_ReadSignal_UInt64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  uint64 tmpNewValue = 0;

  uint8 *startBytePtr = &((uint8*) & tmpNewValue)[0];

  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, startBytePtr, SignalBusSourcePtr, 8);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_SInt64
**********************************************************************************************************************/
static sint64 ComEx_Signal_ReadSignal_SInt64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
    ComEx_uSignExt64BitType tmpNewValue;        /* PRQA S 0759 */ /* MD_MSR_Union */

    tmpNewValue.signedAccess = 0;

    ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, &(tmpNewValue.unsignedAccess[0]), SignalBusSourcePtr, 8);      /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

    ComEx_Signal_ReadSignalSignExtension_SINT64(SignalId, &tmpNewValue);   /* SBSW_COM_FCTCALL_STACKPTR */

    return tmpNewValue.signedAccess;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_Float32
**********************************************************************************************************************/
static float32 ComEx_Signal_ReadSignal_Float32(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  float32 tmpNewValue = 0.0f;

  uint8 *startBytePtr = &((uint8*) & tmpNewValue)[0];

  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, startBytePtr, SignalBusSourcePtr, 4);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_Float64
**********************************************************************************************************************/
static float64 ComEx_Signal_ReadSignal_Float64(ComEx_SignalIdType SignalId, uint8* SignalBusSourcePtr)
{
  float64 tmpNewValue = 0.0;
  uint8 *startBytePtr = &((uint8*) & tmpNewValue)[0];
  ComEx_Signal_ReadSignalApplTypeSpecific(SignalId, startBytePtr, SignalBusSourcePtr, 8);  /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */

  return tmpNewValue;
}
/**********************************************************************************************************************
  Com_Signal_ReadSignalApplTypeSpecific
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignalApplTypeSpecific(ComEx_SignalIdType SignalId,uint8* SignalApplDestPtr,uint8* SignalBusSourcePtr, uint32 destLength)
{
  P2VAR(uint8, AUTOMATIC, COM_APPL_VAR) SignalApplDestPtrIntern = SignalApplDestPtr;
  uint16 signalStartBit = ComEx_Signal_BitOffsetFromBitPos(ComEx_GetRxSigInfoBitPosition(SignalId));

  switch (ComEx_GetRxSigInfoBusAccType(SignalId))
  {
    case (COMEX_NBIT_BUSACCOFRXACCESSINFO):
    {
      *SignalApplDestPtrIntern = COMEX_CAST2UINT8((*SignalBusSourcePtr) >> signalStartBit) & COMEX_CAST2UINT8(255u >> (8u - ComEx_GetRxSigInfoBitLength(SignalId)));       /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      break;
    }
    case (COMEX_BYTE_BUSACCOFRXACCESSINFO):
    {
      *SignalApplDestPtrIntern = COMEX_CAST2UINT8(*SignalBusSourcePtr);   /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      break;
    }
    case (COMEX_NBYTE_BUSACCOFRXACCESSINFO):
    {
      VStdLib_MemCpy_s(SignalApplDestPtrIntern, (VStdLib_CntType) destLength, SignalBusSourcePtr, (VStdLib_CntType) ComEx_GetRxSigInfoByteLength(SignalId));   /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_COM_VSTDLIB_SAFE */
      break;
    }
    case (COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO):
    {
      if(ComEx_GetRxSigInfoByteLength(SignalId) <= destLength) /* COV_COM_SILENT_TX */
      {
        sint16_least i;
        /* ------------------------------- Motorola (bus) to Intel (appl) -------------------------------------------- */
        for(i = (((sint16_least) ComEx_GetRxSigInfoByteLength(SignalId)) - 1); i >= 0; i--)
        {
          SignalApplDestPtrIntern[i] = COMEX_CAST2UINT8(SignalBusSourcePtr[-i]);  /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
        }
      }
      break;
    }
    case (COMEX_NBITNBYTE_BUSACCOFRXACCESSINFO):
    {
      ComEx_Signal_ReadSignal_LB_NBITNBYTE(SignalId, SignalApplDestPtrIntern, SignalBusSourcePtr, signalStartBit, destLength);      /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */
      break;
    }
    case (COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO):
    {
      ComEx_Signal_ReadSignal_LB_SW_NBITNBYTE(SignalId, SignalApplDestPtrIntern, SignalBusSourcePtr, signalStartBit, destLength);   /* SBSW_COM_VALID_PTR_ENSURED_BY_CALLING_FUNC_AND_STACKPTR */
      break;
    }

    default:   /* COV_COM_MISRA */
      break;
  }
}       /* PRQA S 6030 */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
 Com_Signal_ReadSignalSignExtension_SINT8
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignalSignExtension_SINT8(ComEx_SignalIdType SignalId, ComEx_uSignExt8BitType* signExtValue)       /* PRQA S 0750 */ /* MD_MSR_Union */
{
  uint8 signMask, msbMask;
  uint16 tmp = ComEx_GetRxSigInfoBitLength(SignalId) - 1u;
  uint8 signBitPos = ComEx_Signal_BitOffsetFromBitPos(tmp);

  signMask = COMEX_CAST2UINT8(1u << signBitPos);
  msbMask = COMEX_CAST2UINT8(255u << signBitPos);

  /* #10 if required, perform sign extension */
  if(0u != (signMask & signExtValue->unsignedAccess))
  {     /* negative value */
    signExtValue->unsignedAccess |= msbMask;    /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
  }
}
/**********************************************************************************************************************
 Com_Signal_ReadSignalSignExtension_SINT16
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignalSignExtension_SINT16(ComEx_SignalIdType SignalId, ComEx_uSignExt16BitType* signExtValue)     /* PRQA S 0750, 3673 */ /* MD_MSR_Union, MD_MSR_Rule8.13 */
{
  uint8 signMask, msbMask;
  uint16 tmp = ComEx_GetRxSigInfoBitLength(SignalId) - 1u;
  uint16 signMSBOffset = tmp >> 3u;
  uint8 signBitPos = ComEx_Signal_BitOffsetFromBitPos(tmp);
  uint8 *destPtr;
  
  destPtr = &(signExtValue->unsignedAccess[0]);

  signMask = COMEX_CAST2UINT8(1u << signBitPos);
  msbMask = COMEX_CAST2UINT8(255u << signBitPos);
  /* #10 if required, perform sign extension */

  /* Implementation for Intel Plattforms */
  if(0u != (signMask & destPtr[signMSBOffset]))
  {     /* negative value */
    if(0u == signMSBOffset)     /* COV_COM_SIGNMSBOFFSET */
    {   /* signal smaller or equal 8 bit */
      *destPtr |= msbMask;      /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      destPtr[1] = 255u;        /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
    }
    else
    {
      destPtr[1] |= msbMask;    /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
    }
  }

}
/**********************************************************************************************************************
 Com_Signal_ReadSignalSignExtension_SINT32
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignalSignExtension_SINT32(ComEx_SignalIdType SignalId, ComEx_uSignExt32BitType* signExtValue)     /* PRQA S 0750, 3673 */ /* MD_MSR_Union, MD_MSR_Rule8.13 */
{
  uint8 signMask, msbMask;
  uint16 tmp = ComEx_GetRxSigInfoBitLength(SignalId) - 1u;
  uint16 signMSBOffset = tmp >> 3u;
  uint8 signBitPos = ComEx_Signal_BitOffsetFromBitPos(tmp);
  uint8 *destPtr;

  destPtr = &(signExtValue->unsignedAccess[0]);


  signMask = COMEX_CAST2UINT8(1u << signBitPos);
  msbMask = COMEX_CAST2UINT8(255u << signBitPos);

  /* #10 if required, perform sign extension */

  /* Implementation for Intel Plattforms */
  {
    sint16_least i;
    if(0u != (signMask & destPtr[signMSBOffset]))
    {   /* negative value */
      destPtr[signMSBOffset] |= msbMask;        /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      for(i = (((sint16_least) signMSBOffset) + 1); i < 4; i++)
      {
        destPtr[i] = 255u;      /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      }
    }
  }

}
/**********************************************************************************************************************
 Com_Signal_ReadSignalSignExtension_SINT64
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignalSignExtension_SINT64(ComEx_SignalIdType SignalId, ComEx_uSignExt64BitType* signExtValue)     /* PRQA S 0750, 3673 */ /* MD_MSR_Union, MD_MSR_Rule8.13 */
{
  uint8 signMask, msbMask;
  uint16 tmp = ComEx_GetRxSigInfoBitLength(SignalId) - 1u;
  uint16 signMSBOffset = tmp >> 3u;
  uint8 signBitPos = ComEx_Signal_BitOffsetFromBitPos(tmp);
  uint8 *destPtr;
  
  destPtr = &(signExtValue->unsignedAccess[0]);


  signMask = COMEX_CAST2UINT8(1u << signBitPos);
  msbMask = COMEX_CAST2UINT8(255u << signBitPos);

  /* #10 if required, perform sign extension */
  /* Implementation for Intel Plattforms */
  {
    sint16_least i;
    if(0u != (signMask & destPtr[signMSBOffset]))
    {   /* negative value */
      destPtr[signMSBOffset] |= msbMask;        /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      for(i = ((sint16_least) signMSBOffset + 1); i < 8; i++)
      {
        destPtr[i] = 255u;      /* SBSW_COM_WRITEACCESS_STACKPTR_01 */
      }
    }
  }
}
/**********************************************************************************************************************
  Com_Signal_ReadSignal_LB_NBITNBYTE
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignal_LB_NBITNBYTE(ComEx_SignalIdType SignalId, uint8* SignalApplDestPtr, uint8* SignalBusSourcePtr, uint16 signalStartBit, uint32 destLength)
{
  /* #5 This function is used if the CPU byte order is LOW_BYTE_FIRST */
  uint16_least nFullBytes = 0u;
  uint16 nBitsToWrite;
  /* ------------------------------- Intel (bus) to Intel (appl) ----------------------------------------------- */
  nBitsToWrite = ComEx_GetRxSigInfoBitLength(SignalId);
  /* #10 If more than 8 bits have to be copied */
  if(ComEx_GetRxSigInfoBitLength(SignalId) > 8u)     /* COV_COM_NBITNBYTE */
  {
    sint16_least i;
    nFullBytes = (uint16_least) (nBitsToWrite >> 3u);   /* PRQA S 4391 */ /* MD_Com_4391 */
    if(((uint32) nFullBytes) <= destLength)     /* COV_COM_SILENT_TX */
    {
      /* #20 Copy all full bytes, byte align the source byte before it is copied */
      for(i = ((sint16_least) nFullBytes - 1); i >= 0; i--)
      {
        SignalApplDestPtr[i] = COMEX_CAST2UINT8(SignalBusSourcePtr[i] >> signalStartBit); /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
        SignalApplDestPtr[i] |= COMEX_CAST2UINT8(SignalBusSourcePtr[i + 1] << (8u - signalStartBit));     /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
        nBitsToWrite -= 8u;
      }
    }
    else
    {
      nFullBytes = 0u;
    }
  }

  /* #30 If the signal not only has full bytes, copy the remaining bits to the destination buffer */
  if(0u != nBitsToWrite)        /* COV_COM_NBITNBYTE_COPY_REMAININGBITS */
  {
    uint8 tmpByte = COMEX_CAST2UINT8(SignalBusSourcePtr[nFullBytes] >> signalStartBit);
    uint8 sourceEndByteIdx = COMEX_CAST2UINT8((signalStartBit + nBitsToWrite - 1u) >> 3u);

    if(sourceEndByteIdx > (uint8) 0)   /* COV_COM_NBITNBYTE_BY_UINT8_ONLY */
    {
      tmpByte |= COMEX_CAST2UINT8(SignalBusSourcePtr[nFullBytes + 1u] << (8u - signalStartBit));
    }

    SignalApplDestPtr[nFullBytes] = tmpByte & COMEX_CAST2UINT8(~(COMEX_CAST2UINT8(255u << nBitsToWrite)));  /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
  }
}

/**********************************************************************************************************************
  Com_Signal_ReadSignal_LB_SW_NBITNBYTE
**********************************************************************************************************************/
static void ComEx_Signal_ReadSignal_LB_SW_NBITNBYTE(ComEx_SignalIdType SignalId, uint8* SignalApplDestPtr, uint8* SignalBusSourcePtr, uint16 signalStartBit, uint32 destLength)
{
  /* #5 This function is used if the CPU byte order is LOW_BYTE_FIRST */
  sint16_least nFullBytes = 0;

  /* ------------------------------- Motorola (bus) to Intel (appl) -------------------------------------------- */
  uint16 nBitsToWrite = ComEx_GetRxSigInfoBitLength(SignalId);
  /* #10 If more than 8 bits have to be copied */
  if(nBitsToWrite > 8u) /* COV_COM_NBITNBYTE */
  {
    sint16_least i;
    nFullBytes = (sint16_least) (nBitsToWrite >> 3u);   /* PRQA S 4394 */ /* MD_Com_4394 */
    if(((uint32) nFullBytes) <= destLength)     /* COV_COM_SILENT_TX */
    {
      for(i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
      {
        /* #20 Copy all full bytes, byte align the source byte before it is copied and perform endianess conversion */
        SignalApplDestPtr[i] = COMEX_CAST2UINT8(SignalBusSourcePtr[-i] >> signalStartBit);        /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
        SignalApplDestPtr[i] |= COMEX_CAST2UINT8(SignalBusSourcePtr[-i - 1] << (8u - signalStartBit));    /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
        nBitsToWrite -= 8u;
      }
    }
    else
    {
      nFullBytes = 0;
    }
  }

  /* #30 If the signal not only has full bytes, copy the remaining bits to the destination buffer and perform endianess conversion */
  if(0u != nBitsToWrite)        /* COV_COM_NBITNBYTE_COPY_REMAININGBITS */
  {
    uint8 tmpByte = COMEX_CAST2UINT8(SignalBusSourcePtr[0 - nFullBytes] >> signalStartBit);       /* PRQA S 2986 */ /* MD_Com_2985_2986 */
    uint8 sourceEndByteIdx = COMEX_CAST2UINT8((signalStartBit + nBitsToWrite - 1u) >> 3u);

    if(sourceEndByteIdx > (uint8) 0)   /* COV_COM_NBITNBYTE_BY_UINT8_ONLY */
    {
      tmpByte |= COMEX_CAST2UINT8(SignalBusSourcePtr[-1 - nFullBytes] << (8u - signalStartBit));
    }

    SignalApplDestPtr[nFullBytes] = tmpByte & COMEX_CAST2UINT8(~(COMEX_CAST2UINT8(255u << nBitsToWrite)));  /* SBSW_COM_WRITEACCESS_STACKPTR_WITH_LENGTH */
  }
}
/**********************************************************************************************************************
  Com_Signal_WriteSignal
**********************************************************************************************************************/
static void ComEx_SendSignal_Processing(ComEx_SignalIdType SignalId, const void* SignalDataPtr)
{
  const uint8* SignalApplSourcePtrInternal = SignalDataPtr;   /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint16 signalStartBit = ComEx_Signal_BitOffsetFromBitPos(ComEx_GetTxSigInfoBitPosition(SignalId));

  switch (ComEx_GetTxSigInfoBusAccType(SignalId))
  {
    case (COMEX_NBIT_BUSACCOFTXSIGINFO): /* COV_COM_N_BIT_X */
    {
      /* #30 NBIT: copy the specific bits from the source pointer to the destination pointer */
      uint8 signalBusDest = ComEx_GetTxBuffer(ComEx_GetTxSigInfoBufferStartIdx(SignalId));
      uint8 mask = COMEX_CAST2UINT8((COMEX_CAST2UINT8(~(COMEX_CAST2UINT8(255u << ComEx_GetTxSigInfoBitLength(SignalId))))) << signalStartBit);
      signalBusDest &= COMEX_CAST2UINT8(~mask);
      signalBusDest |= COMEX_CAST2UINT8(*SignalApplSourcePtrInternal << signalStartBit) & mask;

      ComEx_SetTxBuffer(ComEx_GetTxSigInfoBufferStartIdx(SignalId), signalBusDest);     /* SBSW_COM_CSL03 */
      break;
    }
    case (COMEX_BYTE_BUSACCOFTXSIGINFO):
    {
      /* #40 BYTE: Set the source pointer to the destination pointer */
      ComEx_SetTxBuffer(ComEx_GetTxSigInfoBufferStartIdx(SignalId), *SignalApplSourcePtrInternal);      /* SBSW_COM_CSL03 */
      break;
    }
    case (COMEX_NBYTE_BUSACCOFTXSIGINFO):
    {
      uint16 i;
      /* Pointer points to LSB of little endian signal, therefore start index is used */
      uint8* SignalBusDestPtr = ComEx_GetAddrTxBuffer(ComEx_GetTxSigInfoBufferStartIdx(SignalId));
      /* #50 (NBYTE or ARRAY_BASED) and CPU byte order is LOW_BYTE_FIRST: Copy N source bytes from position I to destination bytes at position I */
      /* Use-case: UINT8_N or UINT8_DYN */
    /* *INDENT-OFF* */
    /* ------------------------------- Intel (appl) to Intel (bus) AND Byte Arrays (Intel Hw) -------------------------
       - Writing Intel Signals on Intel Hw.
       - Writing Byte Arrays (no swap):
       - Writing Intel Byte Arrays */
    /* *INDENT-ON* */
      for(i = 0; i < ComEx_GetTxBufferLengthOfTxSigInfo(SignalId); i++)
      {
        SignalBusDestPtr[i] = SignalApplSourcePtrInternal[i];   /* SBSW_COM_TXBUFFER_CSL03 */
      }
      break;
    }
    case (COMEX_NBYTE_SW_BUSACCOFTXSIGINFO):
    {
    /*------------------------------- Intel (appl) to Motorola (bus)------------------------------------------------*/
      /* Pointer points to LSB of big endian signal, therefore end index is used */
      uint8* SignalBusDestPtr = ComEx_GetAddrTxBuffer(ComEx_GetTxSigInfoBufferEndIdx(SignalId) - 1u);
      /* #60 NBYTE_SW and CPU byte order is LOW_BYTE_FIRST: Copy N source bytes from position I to destination bytes at position -I */
      sint16_least i;
      /* ------------------------------- Intel (appl) to Motorola (bus) ---------------------------------------------- */
      for(i = 0; i < ((sint16_least) ComEx_GetTxBufferLengthOfTxSigInfo(SignalId)); i++)
      {
        SignalBusDestPtr[-i] = SignalApplSourcePtrInternal[i];  /* SBSW_COM_TXBUFFER_CSL03 */
      }
      break;
    }
    case (COMEX_NBITNBYTE_BUSACCOFTXSIGINFO):    /* COV_COM_NBITNBYTE_X */
    {
      /* #70 NBITNBYTE and CPU byte order is LOW_BYTE_FIRST: Copy N bits and N bytes from the source pointer to the destination pointer */
      /* Pointer points to LSB of little endian signal, therefore start index is used */
      uint8* SignalBusDestPtr = ComEx_GetAddrTxBuffer(ComEx_GetTxSigInfoBufferStartIdx(SignalId));
      ComEx_Signal_WriteSignal_NBITNBYTE(SignalId, SignalApplSourcePtrInternal, signalStartBit, SignalBusDestPtr, FALSE); /* SBSW_COM_VALID_PTR_BY_COMSTACK_01 */
      break;
    }
    case (COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO): /* COV_COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO */
    {
      /* #80 NBITNBYTE_SW and CPU byte order is LOW_BYTE_FIRST: Copy N bits and N bytes from the source pointer to the destination pointer and perform endianness conversion */
      /* Pointer points to LSB of big endian signal, therefore end index is used */
      uint8* SignalBusDestPtr = ComEx_GetAddrTxBuffer(ComEx_GetTxSigInfoBufferEndIdx(SignalId) - 1u);
      ComEx_Signal_WriteSignal_NBITNBYTE(SignalId, SignalApplSourcePtrInternal, signalStartBit, SignalBusDestPtr, TRUE);  /* SBSW_COM_VALID_PTR_BY_COMSTACK_01 */
      break;
    }

    default:   /* COV_COM_MISRA */
      break;
  }
}
/**********************************************************************************************************************
  Com_Signal_WriteSignal_NBITNBYTE
**********************************************************************************************************************/
static void ComEx_Signal_WriteSignal_NBITNBYTE(ComEx_SignalIdType SignalId, const uint8* SignalApplSourcePtr, uint16 signalStartBit,
                                                                   uint8* SignalBusDestPtr, boolean isBusBigEndian)
{
    uint8 mask;
    uint8 tmpByte;
    sint16_least i;

    uint16 maskCounter = 8u - (uint16) signalStartBit;
    uint16 signalBitCount = ComEx_GetTxSigInfoBitLength(SignalId);

    /* #10 Write LSB of the passed signal */
    *SignalBusDestPtr &= COMEX_CAST2UINT8(~COMEX_CAST2UINT8(255u << signalStartBit)); /* SBSW_COM_VALID_PTR_BY_COMSTACK_01 */
    *SignalBusDestPtr |= COMEX_CAST2UINT8(*SignalApplSourcePtr << signalStartBit);  /* SBSW_COM_VALID_PTR_BY_COMSTACK_01 */

    /* #20 If more than 8 bits have to be copied */
    for(i = 1; i < ((sint16_least) ComEx_GetTxBufferLengthOfTxSigInfo(SignalId) - 1); i++)  /* COV_WRITESIGNAL_NBITNBYTE_XX */
    {
        /* #30 Copy all full bytes, byte align the source byte before it is copied */
        tmpByte = COMEX_CAST2UINT8(SignalApplSourcePtr[i - 1] >> (8u - signalStartBit));
        tmpByte |= COMEX_CAST2UINT8(SignalApplSourcePtr[i] << signalStartBit);

        /* If little endian and big endian signals exist */
        SignalBusDestPtr[ComEx_NBITNBYTE_GetEndiannesIndex(i, isBusBigEndian)] = tmpByte;     /* SBSW_COM_VALID_PTR_BY_COMSTACK_02 */ /* COV_COM_NBITNBYTE_ENDIANNESS */
        maskCounter += 8u;
    }

    tmpByte = COMEX_CAST2UINT8(SignalApplSourcePtr[i - 1] >> (8u - signalStartBit));

    if(COMEX_CAST2UINT8(i) <= (COMEX_CAST2UINT8(signalBitCount - 1u) >> 3u))
    {
        tmpByte |= COMEX_CAST2UINT8(SignalApplSourcePtr[i] << signalStartBit);
    }

    mask = COMEX_CAST2UINT8(255u >> (8u - (signalBitCount - maskCounter)));

    i = (sint16_least) ComEx_NBITNBYTE_GetEndiannesIndex(i, isBusBigEndian);        /* COV_COM_NBITNBYTE_ENDIANNESS */

    /* #60 Copy the remaining bits of last byte to the destination buffer */
    SignalBusDestPtr[i] = (SignalBusDestPtr[i] & COMEX_CAST2UINT8(~mask)) | (tmpByte & mask);       /* SBSW_COM_VALID_PTR_BY_COMSTACK_02 */

}

FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignalBuffer(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
* Symbol: ComEx_SendSignal (returns application error)
*********************************************************************************************************************/
   Std_ReturnType ret = E_OK; 

   if(SignalId >= ComEx_GetSizeOfTxSig())
   {
       ret = COMEX_ERROR_PARAM;
   }
   else if(Length < ComEx_GetTxSigInfoBusAccByteLength(SignalId))
   {
       ret = COMEX_ERROR_PARAM;
   }
   else if(SignalDataPtr == NULL_PTR)
   {
       ret = COMEX_ERROR_PARAM;
   }
   else 
   {
       Rte_Enter_ExclusiveArea_ComEx();
       
       ComEx_SendSignal_Processing(SignalId, SignalDataPtr);

       Rte_Exit_ExclusiveArea_ComEx();
   }

   return ret;


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean ComEx_TransmitPduSignalProcessing(ComEx_IpduGroupIdType PduId, PduInfoType* PduInfoPtr)
{
    boolean ret = TRUE; 
    uint16 PduBufferPosition = 0;
    ComEx_SignalGroupIdType GroupId;

    if(ComEx_IsTxPduGroupActive(PduId))
    {            
        for(GroupId = ComEx_GetTxPduInfoGroupStartIdx(PduId); GroupId < ComEx_GetTxPduInfoGroupEndIdx(PduId); GroupId++)
        {
            ComEx_TransmitSignalGroupProcessing(GroupId);
        }
    }

    /*Set Tx Buffer to Tx PDU Buffer*/
    PduBufferPosition = ComEx_GetTxPduInfoBufferPosition(PduId);

    Rte_Enter_ExclusiveArea_ComEx();
    VStdMemCpyRamToRam(PduInfoPtr->SduDataPtr, ComEx_GetAddrTxPduBuffer(PduBufferPosition), PduInfoPtr->SduLength);
    Rte_Exit_ExclusiveArea_ComEx();

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType ComEx_TransmitSignalGroupProcessing(ComEx_SignalGroupIdType GroupId)
{
    Std_ReturnType ret = E_OK; 
    ComEx_E2ETYPE E2edata;
    uint16 TxE2eIdx;
    
    if(GroupId >= ComEx_GetSizeOfTxGroup())
    {
        ret |= COMEX_ERROR_PARAM;
    }
    else
    {
        if(ComEx_IsTxGroupE2eActive(GroupId))
        {
            TxE2eIdx = ComEx_GetTxGroupE2eIdx(GroupId);

            ComEx_GetSigGroupE2eData(GroupId, &E2edata);
            ComEx_GetTxE2EInfoWriteFunptr(TxE2eIdx)(&E2edata);
        }
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_GetSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata)
{
    uint16 PduIdx = ComEx_GetTxGroupInfoPduIdx(SignalGroupId);
    uint8* groupdata = ComEx_GetAddrTxPduBuffer(ComEx_GetTxPduInfoBufferPosition(PduIdx) + ComEx_GetTxGroupInfoBytePosition(SignalGroupId));
    
    E2epdata->Checksum = groupdata[0];

    E2epdata->RollingCounter = 0x0F & groupdata[7];
    
    E2epdata->E2E_Data1[0] = groupdata[1];
    E2epdata->E2E_Data1[1] = groupdata[2];
    E2epdata->E2E_Data1[2] = groupdata[3];
    E2epdata->E2E_Data1[3] = groupdata[4];
    E2epdata->E2E_Data1[4] = groupdata[5];
    E2epdata->E2E_Data1[5] = groupdata[6];

    E2epdata->E2E_Data2 =  groupdata[7]>>4;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_EventSignalProcessing(ComEx_SignalIdType SignalId)
{
    uint16 PduIdx;

    if(ComEx_GetTxSigInfoSendType(SignalId) & COMEX_TxSIGNAL_EVENTTYPE)
    {        
        PduIdx = ComEx_GetTxSigInfoPduIdx(SignalId);
        
        Com_TriggerIPDUSend(PduIdx);
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType ComEx_WriteSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata)
{
    Std_ReturnType ret = RTE_E_OK; 

    uint16 PduIdx = ComEx_GetTxGroupInfoPduIdx(SignalGroupId);
    uint8* groupdata = ComEx_GetAddrTxPduBuffer(ComEx_GetTxPduInfoBufferPosition(PduIdx) + ComEx_GetTxGroupInfoBytePosition(SignalGroupId));
    
    groupdata[0] = E2epdata->Checksum;
    
    groupdata[7] = (E2epdata->E2E_Data2<<4)+ E2epdata->RollingCounter;

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void ComEx_TxConfiratmion(ComEx_IpduGroupIdType PduId)
{
    uint16 SignalIdx;

    for(SignalIdx = ComEx_GetTxPduInfoSignalStartIdx(PduId); SignalIdx < ComEx_GetTxPduInfoSignalEndIdx(PduId); SignalIdx++)
    {
        COMEX_SET_TXPDU_STS(SignalIdx,COMEX_TX_PDU_STATUS_CONFIRMED); 

        if(ComEx_GetTxSigInfoTxAckFuncPtr(SignalIdx) != NULL_PTR)
        {
            ComEx_GetTxSigInfoTxAckFuncPtr(SignalIdx)(SignalIdx);
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_UpdataRxPduTimer(ComEx_IpduGroupIdType PduId)
{
    ComEx_SetRxPduInfoTimer(PduId, ComEx_ReceiverTimer);
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_UpdataRxPduSignalStatus(ComEx_IpduGroupIdType PduId)
{
    ComEx_SignalIdType SignalId;

    for(SignalId = ComEx_GetRxPduInfoSignalStartIdx(PduId); SignalId < ComEx_GetRxPduInfoSignalEndIdx(PduId); SignalId++)
    {
        ComEx_SetRxSigStatus(SignalId, COMEX_RX_STATUS_UPDATE_RECEIVED);
        ComEx_ClearRxSigStatus(SignalId, COMEX_RX_STATUS_NEVER_RECEIVED);
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean ComEx_IsReceiveTimeOut(ComEx_SignalIdType SignalId)
{
    boolean ret = FALSE; 
    uint64 TimeGap;
    uint16 PduId;
    uint16 timeId;

    if(ComEx_IsRxSigTimeoutActive(SignalId))
    {
        PduId = ComEx_GetRxSigInfoPduIdx(SignalId);
        timeId = ComEx_GetRxSigTimeoutIdx(SignalId);
        
        TimeGap = ComEx_ReceiverTimer - ComEx_GetRxPduInfoTimer(PduId);
      
        if (TimeGap > ComEx_GetRxTimeoutMax(timeId))
        {
            ret = TRUE;
        }
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_SetRxInitValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr)
{
    uint16  SigRxInitValueLength;
    const uint8* SigRxInitValueSrcPtr;
    uint16 InitValueIdx;
    
    if(ComEx_IsRxSigInitValueActive(SignalId))
    {
        InitValueIdx = ComEx_GetRxSigInitValueIdx(SignalId);
        SigRxInitValueLength = ComEx_GetRxSigInfoAppAccByteLength(SignalId);
        SigRxInitValueSrcPtr = ComEx_GetAddrRxInitValueBuffer(ComEx_GetRxInitValueBufferBtyePosition(InitValueIdx));
        
        VStdMemCpyRamToRam(SignalDataPtr, SigRxInitValueSrcPtr, SigRxInitValueLength);        
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_SetRxTimeoutValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr)
{
     uint16 SignalRxTimeoutLength;
     const uint8* SignalRxTimeoutSrcPtr;
     uint16 TimeoutIdx;
     
    TimeoutIdx = ComEx_GetRxSigTimeoutIdx(SignalId);

    if(ComEx_IsRxTimeoutValueActive(TimeoutIdx))
    {
        SignalRxTimeoutLength = ComEx_GetRxSigInfoAppAccByteLength(SignalId);
        SignalRxTimeoutSrcPtr = ComEx_GetAddrRxTimeoutBuffer(ComEx_GetRxTimeoutBufferBtyePosition(SignalId));

        VStdMemCpyRamToRam(SignalDataPtr, SignalRxTimeoutSrcPtr, SignalRxTimeoutLength);        
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_SetRxSignalValue(ComEx_SignalIdType SignalId, uint8* SignalDataPtr)
{
     uint8 SignalRxVauleLength;
     const uint8* SignalRxVauleSrcPtr;

    SignalRxVauleLength = ComEx_GetRxSigInfoAppAccByteLength(SignalId);
    SignalRxVauleSrcPtr = ComEx_GetAddrRxSignalBuffer(ComEx_GetRxSigInfoAppAccBytePosition(SignalId));

    VStdMemCpyRamToRam(SignalDataPtr, SignalRxVauleSrcPtr, SignalRxVauleLength);      
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void ComEx_EnableRxTimeout(void)
{
    ComEx_RxTimeoutActive = TRUE;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void ComEx_DisableRxTimeout(void)
{
    ComEx_RxTimeoutActive = FALSE;

    /* Special signal values are processed when COM stops */
    ComEx_SetComStoppedSingalValue();
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_RxTimerTask(void)
{
    if(ComEx_IsRxTimeoutActive())
    {
        ComEx_IncreaseTick();
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_SetSignalBufferValue(ComEx_SignalIdType SignalId, uint32 Value)
{
    uint8 SignalRxVauleLength;
    uint8* SignalRxVauleSrcPtr;

    SignalRxVauleLength = ComEx_GetRxSigInfoAppAccByteLength(SignalId);
    if((SignalRxVauleLength <= (uint8)(sizeof(uint32))) && (SignalRxVauleLength > (uint8)0u))
    {
        SignalRxVauleSrcPtr = ComEx_GetAddrRxSignalBuffer(ComEx_GetRxSigInfoAppAccBytePosition(SignalId));
        VStdMemCpyRamToRam(SignalRxVauleSrcPtr, (uint8 *)&Value, SignalRxVauleLength);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void ComEx_SetComStoppedSingalValue(void)
{
    uint16 Index;
    uint16 RxPduId;
    for(Index = 0; Index < ComEx_SpecInfoBufferSize; Index++)
    {
        RxPduId = ComEx_GetRxSigInfoPduIdx(ComEx_GetSpecSignalIdOfSpecInfo(Index));
        if(Com_IsRxPduGrpActive(RxPduId))
        {
            ComEx_SetSignalBufferValue(ComEx_GetSpecSignalIdOfSpecInfo(Index), ComEx_GetSpecSignalValueOfSpecInfo(Index));
        }
    }
}

#define ComEx_STOP_SEC_CODE
#include "ComEx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
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
