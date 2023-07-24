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
 * @file:      EOL_Diag.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _EOL_DIAG_H_
#define _EOL_DIAG_H_

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"
#include "IPC_EOL.h"
#include "Rte.h"
#include "Std_Types.h"
#include "logger.h"
#include "Version.h"



/*
 *  %third-party header file%
 */



/*
 *  %system/C-run-time header file%
 */


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

#define   EOL_CANINFO_SPIPRINT_SWICTH_FLAG      STD_ON
#define   EOL_NRC_0x78_SWICTH_FLAG              STD_OFF
#define   STATUSCHANGEMAXTIME                   (3000u)
#define   EOL_SERVICE_2E_SOCNRCIMPLEMENT_RESPONSE_SWICTH    STD_ON

#define   Set_DIDDataLen_0x22(value)            (DIDReadDataLength = ((uint16)value))
#define   Get_DIDDataLen_0x22()                 (DIDReadDataLength)
#define   Set_RoutineDataLen_0x31(value)        (RoutineDataLength = ((uint16)value))
#define   Get_RoutineDataLen_0x31()             (RoutineDataLength)
#define   EOL_StatusChangeTimerDecrease()       (StatusChangeTimer--)
#define   EOL_SetStatusChangeTimer(value)       (StatusChangeTimer = (value))
#define   EOL_GetStatusChangeTimer()             (StatusChangeTimer)



#if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
    #define   EOL_CurrentPendingCnt()               (EOLPendingCnt)
    #define   EOL_ClearPendingCnt()                 ((EOLPendingCnt) = (0))
    #define   EOL_EnterMainCnt()                    (EnterMainCnt)
    #define   EOL_SetEnterMainCnt(value)            ((EnterMainCnt) = (value))
    #define   EOL_GENERALPROGRAMMINGFAILURE         ((uint8)0x72u)
    #define   EOL_PENDINGMAXNUM                     ((uint8)0x05u)
    #define   EOL_ENTERMAINFUNCMAXNUM               (450u)
#endif

#define   DIAG_PDURRESPONSE_PDUID               ((uint8)0x1Au)
#define   DIAG_IVI_PENDING                      ((uint8)0x0Au)
#define   DIAG_SERVICE22_DATA_LENGTH            (50u)

#define   SERVICE_SESSIONCONTROL                ((uint8)0x10u)
#define   SERVICE_SESSIONCONTROL_POSRES         ((uint8)0x50u)
#define   SERVICE_DIDREADBYIDENTIFIER           ((uint8)0x22u)
#define   SERVICE_DIDREADBYIDENTIFIER_POSRES    ((uint8)0x62u)
#define   SERVICE_DIDWRITEBYIDENTIFIER          ((uint8)0x2Eu)
#define   SERVICE_DIDWRITEBYIDENTIFIER_POSRES   ((uint8)0x6Eu)
#define   SERVICE_ROUTINECONTROL                ((uint8)0x31u)
#define   SERVICE_ROUTINECONTROL_POSRES         ((uint8)0x71u)
#define   SERVICE_NEGATIVERESPONSE_NRC          ((uint8)0x7Fu)
#define   DID_WRITEROOTCA                       ((uint16)0xBE3Bu)
#define   DID_WRITESECURITYDATA                 ((uint16)0xBE3Du)


/*
 *  %type definition%
 */
typedef enum
{
  SPI_DIAG_IDEL = 0,
  SPI_DIAG_WAITING_DIDREAD_RESPONSE = 1,
  SPI_DIAG_DIDREAD_RESPONSE_CHECK = 2,
  SPI_DIAG_DIDREAD_RESPONSE_OK = 3,
  SPI_DIAG_WAITING_DIDWRITE_RESPONSE = 4,
  SPI_DIAG_DIDWRITE_RESPONSE_CHECK = 5,
  SPI_DIAG_DIDWRITE_RESPONSE_OK = 6,
  SPI_DIAG_WAITING_SESSION_RESPONSE = 7,
  SPI_DIAG_SESSION_RESPONSE_CHECK = 8,
  SPI_DIAG_SESSION_RESPONSE_OK = 9,
  SPI_DIAG_WAITING_ROUTINE_RESPONSE = 10,
  SPI_DIAG_ROUTINE_RESPONSE_CHECK = 11,
  SPI_DIAG_ROUTINE_RESPONSE_OK = 12,
  SPI_DIAG_ERR = 13
}SPI_DiagStatusType;

typedef enum
{
  SPI_MutiPackageSend_IDEL = 0,
  SPI_MutiPackageSend_SENDING = 1,
  SPI_MutiPackageSend_FINSHED = 2,
  SPI_MutiPackageSend_WAITRESPONSE = 3,
  SPI_MutiPackageSend_RESPONSECHECK_OK = 4,
  SPI_MutiPackageSend_ERR = 5,
}SPI_MutiPackageHandleStatusType;

typedef struct
{
    uint8   ResponseData[50];
    uint8   ResponseServiceId;
    uint8   ResponsePayloadLen;
}Service2EResponseInfo;

typedef struct
{
    uint8   ResponseData[50];
    uint8   ResponseServiceId;
    uint8   ResponsePayloadLen;
    boolean    ResponseFlag;
}Service22ResponseInfo;


typedef struct
{
    boolean  QNXSendFlag;
    boolean  IVISendFlag;
}ServiceSendInfo;


/*
 *  %function declaration%
 */
extern void EOL_DiagTransferHandler(void);
extern uint8 EOL_DiagTransferStatusGet(void);
extern void EOL_DiagTransferStatusSet(SPI_DiagStatusType EOL_DiagStatus);
extern void EOL_DiagTransferSessionControl_TransmitIVI_0x10(uint8 Type);
extern void EOL_DiagTransferSessionControl_TransmitQNX_0x10(uint8 Type);
extern void EOL_DiagTransferReceiveResponseData(uint8 Major_msg_id, uint8 Sub_msg_id, uint8* param, uint16 param_len);
extern void EOL_DiagTransferDidReadResponseCheck(void);
extern void EOL_DiagTransferDidWriteResponseCheck(void);
extern void EOL_DiagTransferSessionControlResponseCheck(void);
extern void EOL_DiagTransferRoutineControlResponseCheck(void);
extern uint8 EOL_DiagTransferReadDIDHandle_0x22(uint16 DID, uint8* Data,uint16 DataLen, uint8 ModuleID);
extern uint8 EOL_DiagTransferWriteDIDHandle_0x2E(uint16 DID, const uint8* Data, uint8 DataLength, uint8 ModuleID, uint8* ErrorCode);
extern uint8 EOL_DiagTransferRoutineControlHandle_0x31(uint16 RID, uint8* Data,uint16 DataLen, uint8 SubId,uint8 ModuleID,uint8* ErrorCode);
extern IPC_S2M_EOLIVIDidReadResponse_t * EOL_GetIVIResponseDIDFlexibleData_Service_0x22(void);
extern IPC_S2M_EOLQNXDidReadResponse_t * EOL_GetQNXResponseDIDFlexibleData_Service_0x22(void);
extern void EOL_SetTimerValue_StatusChange(uint16 value);
extern void EOL_StatusReset(void);
extern uint8 EOL_DiagService_0x2E_ResponseStatusGet(void);
extern Service22ResponseInfo EOL_GetService_ResponseInfo_For_NRC(void);
extern void EOL_ResetService22_ResponseInfo_For_NRC(void);
extern void EOL_GetService2E_ResponseServiceId(uint8* ServiceId);
extern void EOL_Reset(void);
/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif

