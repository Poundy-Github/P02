/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      ComEx_Type.h
 * @author:    Nobo
 * @date:      2021-2-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-2-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _COMEX_TYPE_H_
#define _COMEX_TYPE_H_

#include "Std_Types.h"
#include "Rte.h"
#include "ComStack_Types.h"

#define COMEX_ERROR_PARAM                                   (0x01u)
#define COMEX_MAX_AGE_EXCEEDED                              (0x02u)
#define COMEX_NEVER_RECEIVED                                (0x04u)
#define COMEX_UPDATE_RECEIVED                               (0x08u)
#define COMEX_COM_E_STOPPED                                 (0x80u)

#define COMEX_RX_STATUS_NEVER_RECEIVED                      (0x01u)
#define COMEX_RX_STATUS_UPDATE_RECEIVED                     (0x02u)

#define COMEX_UINT8_APPLTYPEOFRXACCESSINFO                  0u
#define COMEX_SINT8_APPLTYPEOFRXACCESSINFO                  1u
#define COMEX_UINT16_APPLTYPEOFRXACCESSINFO                 2u
#define COMEX_SINT16_APPLTYPEOFRXACCESSINFO                 3u
#define COMEX_UINT32_APPLTYPEOFRXACCESSINFO                 4u
#define COMEX_SINT32_APPLTYPEOFRXACCESSINFO                 5u
#define COMEX_UINT64_APPLTYPEOFRXACCESSINFO                 6u
#define COMEX_SINT64_APPLTYPEOFRXACCESSINFO                 7u
#define COMEX_FLOAT32_APPLTYPEOFRXACCESSINFO                8u
#define COMEX_FLOAT64_APPLTYPEOFRXACCESSINFO                9u
#define COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO                10u
#define COMEX_ZEROBIT_APPLTYPEOFRXACCESSINFO                11u

#define COMEX_NBIT_BUSACCOFRXACCESSINFO                     0u
#define COMEX_BYTE_BUSACCOFRXACCESSINFO                     1u
#define COMEX_NBYTE_BUSACCOFRXACCESSINFO                    2u
#define COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO                 3u
#define COMEX_NBITNBYTE_BUSACCOFRXACCESSINFO                4u
#define COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO             5u


#define COMEX_NBIT_BUSACCOFTXSIGINFO                        0u
#define COMEX_BYTE_BUSACCOFTXSIGINFO                        1u
#define COMEX_NBYTE_BUSACCOFTXSIGINFO                       2u
#define COMEX_NBYTE_SW_BUSACCOFTXSIGINFO                    3u
#define COMEX_NBITNBYTE_BUSACCOFTXSIGINFO                   4u
#define COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO                5u

#define COMEX_TxSIGNAL_CYCLICTYPE                           0u
#define COMEX_TxSIGNAL_EVENTTYPE                            1u

/* For Cna */
#define       COMEX_TX_PDU_STATUS_START_SEND                   (1)
#define       COMEX_TX_PDU_STATUS_CONFIRMED                    (0)

/* */
#define Com_LINKAGE_AREA_NUMBER (30U)
#define Com_LINKAGE_Group_NUMBER (10U)

/** COMEX signal object identifier. */
#ifndef Rte_TypeDef_ComEx_SignalIdType
typedef uint16 ComEx_SignalIdType;
#endif

/** COMEX signal group object identifier. */
#ifndef Rte_TypeDef_ComEx_SignalGroupIdType
typedef uint16 ComEx_SignalGroupIdType;
#endif

/** COMEX PDU group object identifier. */
typedef uint16 ComEx_IpduGroupIdType;


typedef struct
{
    uint16 BitLength;
    uint16 BitPosition;    
    uint16 ByteLength;
    uint16 BytePosition;
    uint16 PduIdx;
    uint8  ApplType;
    uint8  BusAccType;
    uint16 TimeoutIdx;
    uint16 InitValueIdx;
    uint16 AppAccBtyeLength;
    uint16 AppAccBytePosition;
}ComEx_RxSigInfoType;

typedef struct
{
    uint16 PduIdx;    
    uint16 ByteLength;
    uint16 BytePosition;
    uint16 E2eIdx;
}ComEx_RxGroupInfoType;

typedef struct
{
    uint16 SignalStartIdx;
    uint16 SignalEndIdx;
    uint16 GroupStartIdx;
    uint16 GroupEndIdx;
    uint16 BufferPosition;
    uint16 BufferLength;
    uint8  CalloutNum;
    uint8  CalloutStartIdx;
}ComEx_RxPduInfoType;

typedef struct
{
    uint16 Status;
}ComEx_RxSigAttributeType;
typedef struct
{
    uint32 Status;

}ComEx_RxE2eAttributeType;
typedef struct
{
    uint64 Timer;
}ComEx_RxPduAttributeType;

typedef struct
{
    uint16 BtyeLength;
    uint16 BtyePosition;
}ComEx_RxSigInitValueInfoType;

typedef uint8 ComEx_TxSigInitValueInfoType;

typedef struct
{
    uint16 BtyeLength;
    uint16 BtyePosition;
    uint16 TimeoutMax;
}ComEx_RxSigTimeoutInfoType;

typedef struct
{
   uint8 RollingCounter;
   uint8 Checksum;
   uint8 E2E_Data1[6];
   uint8 E2E_Data2;
}ComEx_E2ETYPE;

typedef void (*E2eInitFunPtrType)(void);
typedef uint32 (*E2eReadFunPtrType)(ComEx_E2ETYPE*);
typedef boolean (*PduTxCalloutFunPtrType)(PduIdType , PduInfoType* );
typedef boolean (*PduRxCalloutFunPtrType)(PduIdType , const PduInfoType* );

typedef union
{
    PduTxCalloutFunPtrType PduTxCalloutFunPtr;
    PduRxCalloutFunPtrType PduRxCalloutFunPtr;
}PduCalloutFunPtrType;

typedef struct
{
    E2eInitFunPtrType InitFunPtr;
    E2eReadFunPtrType ReadFunPtr;
}ComEx_RxE2eInfoType;


typedef union ComEx_uSignExt8Bit
{
  uint8 unsignedAccess;
  sint8 signedAccess;
} ComEx_uSignExt8BitType;

typedef union ComEx_uSignExt16Bit
{
  uint8 unsignedAccess[2];
  sint16 signedAccess;
} ComEx_uSignExt16BitType;

typedef union ComEx_uSignExt32Bit
{
  uint8 unsignedAccess[4];
  sint32 signedAccess;
} ComEx_uSignExt32BitType;

typedef union ComEx_uSignExt64Bit
{
  uint8 unsignedAccess[8];
  sint64 signedAccess;
} ComEx_uSignExt64BitType;

typedef void(*ComEx_TxSigAckFuncPtrType)(ComEx_SignalIdType);
typedef struct
{
    uint16 BitLength;
    uint16 BitPosition;    
    uint16 PduIdx;
    uint8  BusAccType;
    uint16 BusAccBtyeLength;
    uint16 BufferStartIdx;
    uint16 BufferEndIdx;
    uint16 SendType;
    ComEx_TxSigAckFuncPtrType TxAckFuncPtr;
}ComEx_TxSigInfoType;

typedef struct
{
    uint16 SignalStartIdx;
    uint16 SignalEndIdx;
    uint16 GroupStartIdx;
    uint16 GroupEndIdx;
    uint16 BufferPosition;
    uint16 BufferLength;
    uint8  CalloutStartIdx;
    uint8  CalloutNum;
}ComEx_TxPduInfoType;

typedef struct
{
    uint16 PduIdx;    
    uint16 ByteLength;
    uint16 BytePosition;
    uint16 E2eIdx;
}ComEx_TxGroupInfoType;

typedef uint32 (*E2eWriteFunPtrType)(ComEx_E2ETYPE*);

typedef struct
{
    E2eInitFunPtrType InitFunPtr;
    E2eWriteFunPtrType WriteFunPtr;
}ComEx_TxE2eInfoType;


typedef struct
{
    uint16 SpecSignalId;
    uint32 SpecSignalValue;
}ComEx_SepcInfoType;

typedef struct 
{
	uint16  SigId;
	uint32  SigValue;
}ComAlcmCanSigAttribute_t;

typedef struct
{
    uint8 AlcmPduSumNum;
    uint16 AlcmPduIndex[Com_LINKAGE_Group_NUMBER];
}AlcmPduInfor;

typedef struct
{
	ComAlcmCanSigAttribute_t SigInfor[Com_LINKAGE_AREA_NUMBER];
    AlcmPduInfor PduInfor;
    uint8 AlcmSigSumNum;  
}ComTxCanPduValueInfor;

#endif /* ifndef _COMEX_TYPE_H_.2021-2-6 14:57:27 GW00191223 */

