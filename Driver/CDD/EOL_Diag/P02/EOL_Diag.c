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
 * @file:      EOL_Diag.c
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

/*
 *  %header file in this project/library%
 */
#include "EOL_Diag.h"
#include "Rte_EOL_Type.h"

/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */


/*
 *  %forward declaration%
 */



/*
 *  %global definition%
 */
static uint8  SPI_DiagStatus;
static uint8 EOLPendingCnt;
static uint16 DIDReadDataLength;
static uint16 RoutineDataLength;
static uint16 EnterMainCnt;
static uint16 StatusChangeTimer;

static IPC_S2M_EOLIVIDidWriteResponse_t IVIDidWriteResponseInfo;
static IPC_S2M_EOLQNXDidWriteResponse_t QNXDidWriteResponseInfo;

static IPC_S2M_EOLIVISessionControlResponse_t IVISessionResponseInfo;
static IPC_S2M_EOLQNXSessionControlResponse_t QNXSessionResponseInfo;

static IPC_S2M_EOLIVIRoutineControlResponse_t IVIRoutineResponseInfo;
static IPC_S2M_EOLQNXRoutineControlResponse_t QNXRoutineResponseInfo;

static IPC_M2S_EOLIVIRoutineControlRequest_t IVIRoutineRequestInfo;
static IPC_M2S_EOLQNXRoutineControlRequest_t QNXRoutineRequestInfo;


static IPC_M2S_EOLIVIDidReadRequest_t IVIDidReadRequestInfo;
static IPC_M2S_EOLQNXDidReadRequest_t QNXDidReadRequestInfo;

static IPC_M2S_EOLIVIDidWriteRequest_t IVIDidWriteRequestInfo;
static IPC_M2S_EOLQNXDidWriteRequest_t QNXDidWriteRequestInfo;

static IPC_M2S_EOLIVISessionControlRequest_t IVISessionRequestInfo;
static IPC_M2S_EOLQNXSessionControlRequest_t QNXSessionRequestInfo;

static IPC_S2M_EOLIVIDidReadResponse_t IVIDidReadResponseInfo;
static IPC_S2M_EOLQNXDidReadResponse_t QNXDidReadResponseInfo;

static void EOL_DiagTransferDidRead_TransmitIVI_0x22(const uint16 Did);
static void EOL_DiagTransferDidRead_TransmitQNX_0x22(const uint16 Did);
static void EOL_DiagTransferDidWrite_TransmitQNX_0x2E(const uint16 Did,const uint8* Data, const uint16 DataLen);
static void EOL_DiagTransferDidWrite_TransmitIVI_0x2E(const uint16 Did,const uint8* Data, const uint16 DataLen);
static IPC_S2M_EOLQNXDidReadResponse_t EOL_DiagTransferGetQNX_DidReadResponseInfo(void);
static IPC_S2M_EOLIVIDidReadResponse_t EOL_DiagTransferGetIVI_DidReadResponseInfo(void);
static void EOL_DiagTransferRoutineControl_TransmitIVI_0x31(const uint16 Rid, const uint8 SubId, uint8* Data,uint16 DataLen);
static void EOL_DiagTransferRoutineControl_TransmitQNX_0x31(const uint16 Rid, const uint8 SubId, uint8* Data,uint16 DataLen);
static IPC_S2M_EOLIVIRoutineControlResponse_t EOL_DiagTransferGetIVI_RoutineResponseInfo(void);
static IPC_S2M_EOLQNXRoutineControlResponse_t EOL_DiagTransferGetQNX_RoutineResponseInfo(void);

extern void EOL_SetMutiPackageStatus(uint8 status);
extern uint8 EOL_GetMutiPackageStatus(void);

static Service2EResponseInfo Service2EResponseRecord = {{0x00}, 0x00, 0x00};
static ServiceSendInfo ServiceSendRecord = {FALSE, FALSE};
static uint8  Service31_NRC = {0x00};
static Service22ResponseInfo  Service22_NRC = {{0x00}, 0x00, 0x00,FALSE};

/******************************************************************************/
/**
* @brief               <EOL_DiagInit>
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
void EOL_DiagTransferInit(void)
{
  uint8 index = 0x00;

  while(index < 50)
  {
    Service2EResponseRecord.ResponseData[index] = 0x00;
    Service22_NRC.ResponseData[index] = 0x00;
    index++;
  }
  Service2EResponseRecord.ResponseServiceId = 0x00;
  Service2EResponseRecord.ResponsePayloadLen = 0x00;
  Service31_NRC = 0x00;
  Service22_NRC.ResponsePayloadLen = 0x00;
  Service22_NRC.ResponseServiceId = 0x00;
  Service22_NRC.ResponseFlag = FALSE;
  EOL_StatusReset();
  EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferGetQNX_DidReadResponseInfo>
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
static IPC_S2M_EOLQNXDidReadResponse_t EOL_DiagTransferGetQNX_DidReadResponseInfo(void)
{
    return QNXDidReadResponseInfo;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferGetQNX_DidReadResponseInfo>
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
static IPC_S2M_EOLQNXRoutineControlResponse_t EOL_DiagTransferGetQNX_RoutineResponseInfo(void)
{
    return QNXRoutineResponseInfo;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferGetIVI_RoutineResponseInfo>
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
static IPC_S2M_EOLIVIRoutineControlResponse_t EOL_DiagTransferGetIVI_RoutineResponseInfo(void)
{
    return IVIRoutineResponseInfo;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferGetIVI_DidReadResponseInfo>
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
static IPC_S2M_EOLIVIDidReadResponse_t EOL_DiagTransferGetIVI_DidReadResponseInfo(void)
{
    return IVIDidReadResponseInfo;
}



/******************************************************************************/
/**
* @brief               <EOL_DiagHandler>
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
void EOL_DiagTransferHandler(void)
 {
    switch(EOL_DiagTransferStatusGet())
    {
        case ((uint8)SPI_DIAG_IDEL):
        case ((uint8)SPI_DIAG_WAITING_DIDREAD_RESPONSE):
            break;
        case ((uint8)SPI_DIAG_DIDREAD_RESPONSE_CHECK):
            EOL_DiagTransferDidReadResponseCheck();
            break;
        case ((uint8)SPI_DIAG_DIDREAD_RESPONSE_OK):
            break;
        case ((uint8)SPI_DIAG_WAITING_DIDWRITE_RESPONSE):
            break;
        case ((uint8)SPI_DIAG_DIDWRITE_RESPONSE_CHECK):
            EOL_DiagTransferDidWriteResponseCheck();
            break;
        case ((uint8)SPI_DIAG_DIDWRITE_RESPONSE_OK):
            break;
        case ((uint8)SPI_DIAG_WAITING_SESSION_RESPONSE):
            break;
        case ((uint8)SPI_DIAG_SESSION_RESPONSE_CHECK):
            EOL_DiagTransferSessionControlResponseCheck();
            break;
        case ((uint8)SPI_DIAG_SESSION_RESPONSE_OK):
            break;
        case ((uint8)SPI_DIAG_WAITING_ROUTINE_RESPONSE):
            break;
        case ((uint8)SPI_DIAG_ROUTINE_RESPONSE_CHECK):
            EOL_DiagTransferRoutineControlResponseCheck();
            break;
        case ((uint8)SPI_DIAG_ROUTINE_RESPONSE_OK):
            break;
        default:
            break;
    }

    if (EOL_GetStatusChangeTimer() > 0)
    {
        EOL_StatusChangeTimerDecrease();
        if(EOL_GetStatusChangeTimer() == 0)
        {
            EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
            EOL_SetStatusChangeTimer(0);
        }
    }
 }


/******************************************************************************/
/**
* @brief               <EOL_DiagTransferDidRead_TransmitIVI_0x22>
* 
* <DID Read Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferDidRead_TransmitIVI_0x22(const uint16 Did)
{
    /*Fill service header information*/
    IVIDidReadRequestInfo.ServiceId = SERVICE_DIDREADBYIDENTIFIER;
    IVIDidReadRequestInfo.Did = Did;
    
    memset(&IVIDidReadResponseInfo,0x00,sizeof(IPC_S2M_EOLIVIDidReadResponse_t));
    memset(&Service22_NRC,0x00,sizeof(Service22ResponseInfo));

    IPC_M2S_EOLIVIDidReadRequest_Transmit(&IVIDidReadRequestInfo);
    EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_DIDREAD_RESPONSE);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferRoutineControl_TransmitIVI_0x31>
* 
* <DID Read Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferRoutineControl_TransmitIVI_0x31(const uint16 Rid, const uint8 SubId, uint8* Data,uint16 DataLen)
{
    /*Fill service header information*/
    uint8 index;
    
    IVIRoutineRequestInfo.ServiceId = SERVICE_ROUTINECONTROL;
    IVIRoutineRequestInfo.Type = SubId;
    IVIRoutineRequestInfo.RoutineId = Rid;
    IVIRoutineRequestInfo.OptionLength = DataLen;

    for(index = 0; index < DataLen;index++)
    {
        IVIRoutineRequestInfo.Option[index] = Data[index];
    }

    IPC_M2S_EOLIVIRoutineControlRequest_Transmit(&IVIRoutineRequestInfo);
    EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_ROUTINE_RESPONSE);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferRoutineControl_TransmitQNX_0x31>
* 
* <DID Read Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferRoutineControl_TransmitQNX_0x31(const uint16 Rid, const uint8 SubId, uint8* Data,uint16 DataLen)
{
    uint8 index;
    /*Fill service header information*/
    QNXRoutineRequestInfo.ServiceId = SERVICE_ROUTINECONTROL;
    QNXRoutineRequestInfo.Type = SubId;
    QNXRoutineRequestInfo.RoutineId = Rid;
    QNXRoutineRequestInfo.OptionLength = DataLen;

    for(index = 0; index < DataLen;index++)
    {
        QNXRoutineRequestInfo.Option[index] = Data[index];
    }
    IPC_M2S_EOLQNXRoutineControlRequest_Transmit(&QNXRoutineRequestInfo);
    EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_ROUTINE_RESPONSE);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferDidRead_TransmitQNX_0x22>
* 
* <DID Read Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferDidRead_TransmitQNX_0x22(const uint16 Did)
{
    /*Fill service header information*/
    QNXDidReadRequestInfo.ServiceId = SERVICE_DIDREADBYIDENTIFIER;
    QNXDidReadRequestInfo.Did = Did;
    
    memset(&QNXDidReadResponseInfo,0x00,sizeof(IPC_S2M_EOLQNXDidReadResponse_t));
    memset(&Service22_NRC,0x00,sizeof(Service22ResponseInfo));

    IPC_M2S_EOLQNXDidReadRequest_Transmit(&QNXDidReadRequestInfo);
    EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_DIDREAD_RESPONSE);
}



/******************************************************************************/
/**
* @brief               <EOL_DiagDIDWrite_Transmit_0x2E>
* 
* <DID Write Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferDidWrite_TransmitIVI_0x2E(const uint16 Did,const uint8* Data, const uint16 DataLen)
{
     uint8  Index;
     
     /*Fill service header information*/
     IVIDidWriteRequestInfo.Did = Did;
     IVIDidWriteRequestInfo.PayloadLength = DataLen;
     IVIDidWriteRequestInfo.ServiceId = SERVICE_DIDWRITEBYIDENTIFIER;

     for(Index = 0; Index < IVIDidWriteRequestInfo.PayloadLength; Index++)
     {
         IVIDidWriteRequestInfo.Payload[Index] = Data[Index];
     }

     IVIDidWriteResponseInfo.Did = 0x00;
     IVIDidWriteResponseInfo.ServiceId = 0x00;
     IPC_M2S_EOLIVIDidWriteRequest_Transmit(&IVIDidWriteRequestInfo);
     EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_DIDWRITE_RESPONSE);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferDidWrite_TransmitQNX_0x2E>
* 
* <DID Write Abstract interface> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
static void EOL_DiagTransferDidWrite_TransmitQNX_0x2E(const uint16 Did,const uint8* Data, const uint16 DataLen)
{
     uint8  Index;
     
     /*Fill service header information*/
     QNXDidWriteRequestInfo.Did = Did;
     QNXDidWriteRequestInfo.PayloadLength = DataLen;
     QNXDidWriteRequestInfo.ServiceId = SERVICE_DIDWRITEBYIDENTIFIER;

     for(Index = 0; Index < QNXDidWriteRequestInfo.PayloadLength; Index++)
     {
         QNXDidWriteRequestInfo.Payload[Index] = Data[Index];
     }

     QNXDidWriteResponseInfo.Did = 0x00;
     QNXDidWriteResponseInfo.ServiceId = 0x00;
     IPC_M2S_EOLQNXDidWriteRequest_Transmit(&QNXDidWriteRequestInfo);
     EOL_DiagTransferStatusSet(SPI_DIAG_WAITING_DIDWRITE_RESPONSE);
}


/******************************************************************************/
/**
* @brief               <EOL_DiagTransferSessionControl_TransmitIVI_0x10>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void EOL_DiagTransferSessionControl_TransmitIVI_0x10(uint8 Type)
{
    /*Fill service header information*/
    IVISessionRequestInfo.ServiceId = SERVICE_SESSIONCONTROL;
    IVISessionRequestInfo.Type = Type;

    IPC_M2S_EOLIVISessionControlRequest_Transmit(&IVISessionRequestInfo);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferSessionControl_TransmitQNX_0x10>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <pServiceInfo (IN)>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void EOL_DiagTransferSessionControl_TransmitQNX_0x10(uint8 Type)
{
    /*Fill service header information*/
    QNXSessionRequestInfo.ServiceId = SERVICE_SESSIONCONTROL;
    QNXSessionRequestInfo.Type = Type;

    IPC_M2S_EOLQNXSessionControlRequest_Transmit(&QNXSessionRequestInfo);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagService_0x2E_ResponseStatusGet>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <uint8>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
uint8 EOL_DiagService_0x2E_ResponseStatusGet(void)
 {
    return Service2EResponseRecord.ResponseServiceId;
 }

/******************************************************************************/
/**
* @brief               <EOL_DiagStatusGet>
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
uint8 EOL_DiagTransferStatusGet(void)
 {
    return SPI_DiagStatus;
 }

 /******************************************************************************/
 /**
 * @brief               <EOL_DiagStatusGet>
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
 void EOL_DiagTransferStatusSet(SPI_DiagStatusType EOL_DiagStatus)
  {
     SPI_DiagStatus = EOL_DiagStatus;
  }


/******************************************************************************/
/**
* @brief               <EOL_DiagReceiveResponseData>
* 
* <SPI receiving function call> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
void EOL_DiagTransferReceiveResponseData(uint8 Major_msg_id, uint8 Sub_msg_id, uint8* param, uint16 param_len)
{
    uint16 index;

    switch(Major_msg_id)
    {
        case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
            switch(Sub_msg_id)
            {
                case IPC_S2M_EOL_QNX_MSGSUB_DIDREADRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_DIDREAD_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLQNXDidReadResponse_Receive(param, &QNXDidReadResponseInfo, param_len);
                        /* Set response data length */
                        Set_DIDDataLen_0x22(QNXDidReadResponseInfo.DataLength);
                        /* set Service22_NRC*/
                        Service22_NRC.ResponseServiceId = QNXDidReadResponseInfo.ServiceId;
                        Service22_NRC.ResponsePayloadLen = QNXDidReadResponseInfo.DataLength;
                        for(index = 0;index < QNXDidReadResponseInfo.DataLength;index++)
                        {
                            Service22_NRC.ResponseData[index] = QNXDidReadResponseInfo.Data[index];
                        }
                        Service22_NRC.ResponseFlag = TRUE;
                        EOL_DiagTransferStatusSet(SPI_DIAG_DIDREAD_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_QNX_MSGSUB_DIDWRITERESPONSE_ID:
                    IPC_S2M_EOLQNXDidWriteResponse_Receive(param, &QNXDidWriteResponseInfo, param_len);
                    Service2EResponseRecord.ResponseServiceId = param[0];
                    if((QNXDidWriteResponseInfo.ServiceId == SERVICE_DIDWRITEBYIDENTIFIER_POSRES) && 
                        ((QNXDidWriteResponseInfo.Did == DID_WRITEROOTCA) || (QNXDidWriteResponseInfo.Did == DID_WRITESECURITYDATA)))
                    {
                        EOL_SetMutiPackageStatus(SPI_MutiPackageSend_RESPONSECHECK_OK);
                    }
                    else if((QNXDidWriteResponseInfo.ServiceId != SERVICE_DIDWRITEBYIDENTIFIER_POSRES) &&
                        ((QNXDidWriteResponseInfo.Did == DID_WRITEROOTCA) || (QNXDidWriteResponseInfo.Did == DID_WRITESECURITYDATA)))
                    {
                        EOL_SetMutiPackageStatus(SPI_MutiPackageSend_ERR);
                    }
                    else if(((uint8)SPI_DIAG_WAITING_DIDWRITE_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        EOL_DiagTransferStatusSet(SPI_DIAG_DIDWRITE_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_SESSION_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLQNXSessionControlResponse_Receive(param, &QNXSessionResponseInfo, param_len);
                        EOL_DiagTransferStatusSet(SPI_DIAG_SESSION_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_ROUTINE_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLQNXRoutineControlResponse_Receive(param, &QNXRoutineResponseInfo, param_len);
                        Service31_NRC = QNXRoutineResponseInfo.ServiceId;
                        EOL_DiagTransferStatusSet(SPI_DIAG_ROUTINE_RESPONSE_CHECK);
                    }
                    break;
                default:
                    break;
            }
            break;
        case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
            switch(Sub_msg_id)
            {
                case IPC_S2M_EOL_IVI_MSGSUB_DIDREADRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_DIDREAD_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLIVIDidReadResponse_Receive(param, &IVIDidReadResponseInfo, param_len);
                        /* set Service22_NRC*/
                        Service22_NRC.ResponseServiceId = IVIDidReadResponseInfo.ServiceId;
                        Service22_NRC.ResponsePayloadLen = IVIDidReadResponseInfo.DataLength;
                        for(index = 0;index < IVIDidReadResponseInfo.DataLength;index++)
                        {
                            Service22_NRC.ResponseData[index] = IVIDidReadResponseInfo.Data[index];
                        }
                        Service22_NRC.ResponseFlag = TRUE;
                        Set_DIDDataLen_0x22(IVIDidReadResponseInfo.DataLength);
                        EOL_DiagTransferStatusSet(SPI_DIAG_DIDREAD_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_IVI_MSGSUB_DIDWRITERESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_DIDWRITE_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLIVIDidWriteResponse_Receive(param, &IVIDidWriteResponseInfo, param_len);
                        Service2EResponseRecord.ResponseServiceId = param[0];
                        EOL_DiagTransferStatusSet(SPI_DIAG_DIDWRITE_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_IVI_MSGSUB_SESSIONCONTROLRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_SESSION_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLIVISessionControlResponse_Receive(param, &IVISessionResponseInfo, param_len);
                        EOL_DiagTransferStatusSet(SPI_DIAG_SESSION_RESPONSE_CHECK);
                    }
                    break;
                case IPC_S2M_EOL_IVI_MSGSUB_ROUTINECONTROLRESPONSE_ID:
                    if(((uint8)SPI_DIAG_WAITING_ROUTINE_RESPONSE) == EOL_DiagTransferStatusGet())
                    {
                        IPC_S2M_EOLIVIRoutineControlResponse_Receive(param, &IVIRoutineResponseInfo, param_len);
                         Service31_NRC = IVIRoutineResponseInfo.ServiceId;
                        EOL_DiagTransferStatusSet(SPI_DIAG_ROUTINE_RESPONSE_CHECK);
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    
    #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
        for(index = 0; index < param_len;index++)
        {
            can_info("Received data:%x ",(uint8)param[index]);
        }
    #endif
}


/******************************************************************************/
/**
* @brief               <EOL_DiagReceiveResponseData>
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
void EOL_DiagTransferDidWriteResponseCheck(void)
{
    if((SERVICE_DIDWRITEBYIDENTIFIER_POSRES == IVIDidWriteResponseInfo.ServiceId) && 
        (IVIDidWriteResponseInfo.Did == IVIDidWriteRequestInfo.Did) && (ServiceSendRecord.IVISendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_DIDWRITE_RESPONSE_OK);
    }
    else if((SERVICE_DIDWRITEBYIDENTIFIER_POSRES == QNXDidWriteResponseInfo.ServiceId) && 
        (QNXDidWriteResponseInfo.Did == QNXDidWriteRequestInfo.Did) && (ServiceSendRecord.QNXSendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_DIDWRITE_RESPONSE_OK);
    }
    else
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ERR);
    }
    EOL_SetStatusChangeTimer(0);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagDidReadResponseCheck>
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
void EOL_DiagTransferDidReadResponseCheck(void)
{
    if((SERVICE_DIDREADBYIDENTIFIER_POSRES == IVIDidReadResponseInfo.ServiceId) && 
        (IVIDidReadResponseInfo.Did == IVIDidReadRequestInfo.Did) && (ServiceSendRecord.IVISendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_DIDREAD_RESPONSE_OK);
    }
    else if((SERVICE_DIDREADBYIDENTIFIER_POSRES == QNXDidReadResponseInfo.ServiceId) && 
    (QNXDidReadRequestInfo.Did == QNXDidReadResponseInfo.Did) && (ServiceSendRecord.QNXSendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_DIDREAD_RESPONSE_OK);
    }
    else
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ERR);
    }
    EOL_SetStatusChangeTimer(0);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagReceiveResponseData>
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
void EOL_DiagTransferSessionControlResponseCheck(void)
{
    if((SERVICE_SESSIONCONTROL_POSRES == IVISessionResponseInfo.ServiceId) && 
        (IVISessionResponseInfo.Type == IVISessionRequestInfo.Type))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_SESSION_RESPONSE_OK);
    }
    else if((SERVICE_SESSIONCONTROL_POSRES == QNXSessionResponseInfo.ServiceId) && 
        (QNXSessionResponseInfo.Type == QNXSessionRequestInfo.Type))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_SESSION_RESPONSE_OK);
    }
    else
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ERR);
    }
    EOL_SetStatusChangeTimer(0);
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferRoutineControlResponseCheck>
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
void EOL_DiagTransferRoutineControlResponseCheck(void)
{
    if((SERVICE_ROUTINECONTROL_POSRES == IVIRoutineResponseInfo.ServiceId) && 
        (IVIRoutineResponseInfo.Type == IVIRoutineRequestInfo.Type) && 
        (IVIRoutineResponseInfo.RoutineId == IVIRoutineRequestInfo.RoutineId) && 
        (ServiceSendRecord.IVISendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ROUTINE_RESPONSE_OK);
    }
    else if((SERVICE_ROUTINECONTROL_POSRES == QNXRoutineResponseInfo.ServiceId) && 
        (QNXRoutineResponseInfo.Type == QNXRoutineRequestInfo.Type) && 
        (QNXRoutineResponseInfo.RoutineId == QNXRoutineRequestInfo.RoutineId) && 
        (ServiceSendRecord.QNXSendFlag == TRUE))
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ROUTINE_RESPONSE_OK);
    }
    else
    {
        EOL_DiagTransferStatusSet(SPI_DIAG_ERR);
    }
    EOL_SetStatusChangeTimer(0);
}


/******************************************************************************/
/**
* @brief               <EOL_DiagTransferWriteDIDHandle_0x2E>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <DID��Data��DataLength��ModuleID>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
uint8 EOL_DiagTransferWriteDIDHandle_0x2E(uint16 DID, const uint8* Data, uint8 DataLength, uint8 ModuleID, uint8* ErrorCode)
{
    uint8 ret = DIAG_IVI_PENDING;
    uint8 index;
    
    #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
        EOL_EnterMainCnt()++;
        if(EOL_EnterMainCnt() == EOL_ENTERMAINFUNCMAXNUM)
        {
            EOL_SetEnterMainCnt(0);
            EOL_CurrentPendingCnt()++;
            if(EOL_CurrentPendingCnt() == EOL_PENDINGMAXNUM)
            {
                EOL_ClearPendingCnt();
                *ErrorCode = EOL_GENERALPROGRAMMINGFAILURE;
                return RTE_E_INVALID;
            }
        }
    #endif
    
    if(((uint8)SPI_DIAG_IDEL) == EOL_DiagTransferStatusGet())
    {
        /* Clear Response Service Id before send*/
        Service2EResponseRecord.ResponseServiceId = 0x00;
        
        EOL_SetStatusChangeTimer((uint16)STATUSCHANGEMAXTIME);
        switch(ModuleID)
        {
            case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
                ServiceSendRecord.QNXSendFlag = TRUE;
                EOL_DiagTransferDidWrite_TransmitQNX_0x2E(DID,Data,DataLength);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("QNX Req 0x2E,DID=0x%x,Data[0]=0x%x!",DID,Data[0]);
                #endif
                break;
            case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
                ServiceSendRecord.IVISendFlag = TRUE;
                EOL_DiagTransferDidWrite_TransmitIVI_0x2E(DID,Data,DataLength);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("IVI Req 0x2E,DID=0x%x,Data[0]=0x%x!",DID,Data[0]);
                #endif
                break;
            default:
                break;
        }
       #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
           can_info("Waiting for response!");
       #endif
    }
    else if(((uint8)SPI_DIAG_DIDWRITE_RESPONSE_OK) == EOL_DiagTransferStatusGet())
    {
        EOL_Reset();
        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Data has been received!");
        #endif
        ret = RTE_E_OK;
    }
    else if(((uint8)SPI_DIAG_ERR) == EOL_DiagTransferStatusGet())
    {
        EOL_Reset();
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Invalid received data!");
        #endif

        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif

        /* when SOC implement NRC ,start to STD_ON*/
        #if (EOL_SERVICE_2E_SOCNRCIMPLEMENT_RESPONSE_SWICTH == STD_ON)
            *ErrorCode = Service2EResponseRecord.ResponseServiceId;
        #else
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        #endif
        ret = RTE_E_INVALID;
    }

    return ret;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferReadDIDHandle_0x22>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <DID��Data��DataLength��ModuleID>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
uint8 EOL_DiagTransferReadDIDHandle_0x22(uint16 DID, uint8* Data,uint16 DataLen, uint8 ModuleID)
{
    uint8 ret = DIAG_IVI_PENDING;
    uint8 index;
    IPC_S2M_EOLQNXDidReadResponse_t DidReadResponseQNX;
    IPC_S2M_EOLIVIDidReadResponse_t DidReadResponseIVI;
    
    #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
        EOL_EnterMainCnt()++;
        if(EOL_EnterMainCnt() == EOL_ENTERMAINFUNCMAXNUM)
        {
            EOL_SetEnterMainCnt(0);
            EOL_CurrentPendingCnt()++;
            if(EOL_CurrentPendingCnt() == EOL_PENDINGMAXNUM)
            {
                EOL_ClearPendingCnt();
                return RTE_E_INVALID;
            }
        }
    #endif

    if(((uint8)SPI_DIAG_IDEL) == EOL_DiagTransferStatusGet())
    {
        EOL_SetStatusChangeTimer((uint16)STATUSCHANGEMAXTIME);
        Set_DIDDataLen_0x22(DataLen);
        switch(ModuleID)
        {
            case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
                ServiceSendRecord.QNXSendFlag = TRUE;
                EOL_DiagTransferDidRead_TransmitQNX_0x22(DID);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("QNX Req 0x22,DID=0x%x!",DID);
                #endif
                break;
            case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
                ServiceSendRecord.IVISendFlag = TRUE;
                EOL_DiagTransferDidRead_TransmitIVI_0x22(DID);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("IVI Req 0x22,DID=0x%x!",DID);
                #endif
                break;
            default:
                break;
        }
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Waiting for response!");
        #endif
    }
    else if(((uint8)SPI_DIAG_DIDREAD_RESPONSE_OK) == EOL_DiagTransferStatusGet()) 
    {
        switch(ModuleID)
        {
            case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
                DidReadResponseQNX = EOL_DiagTransferGetQNX_DidReadResponseInfo();
                for(index = 0; index < Get_DIDDataLen_0x22(); index++)
                {
                    Data[index] = DidReadResponseQNX.Data[index];
                }
                break;
            case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
                DidReadResponseIVI = EOL_DiagTransferGetIVI_DidReadResponseInfo();
                for(index = 0; index < Get_DIDDataLen_0x22(); index++)
                {
                    Data[index] = DidReadResponseIVI.Data[index];
                }
                break;
            default:
                break;
        }
        EOL_ResetService22_ResponseInfo_For_NRC();
        EOL_Reset();
        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Data has been received!");
        #endif
        ret = RTE_E_OK;
    }
    else if(((uint8)SPI_DIAG_ERR) == EOL_DiagTransferStatusGet())
    {
        EOL_Reset();
        EOL_ResetService22_ResponseInfo_For_NRC();
        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Invalid received data!");
        #endif
        ret = RTE_E_INVALID;
    }
    else
    {
        /*do nothing*/
    }

    return ret;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagTransferRoutineControlHandle_0x31>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <DID��Data��DataLength��ModuleID>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
uint8 EOL_DiagTransferRoutineControlHandle_0x31(uint16 RID, uint8* Data,uint16 DataLen, uint8 SubId,uint8 ModuleID,uint8* ErrorCode)
{
    uint8 ret = DIAG_IVI_PENDING;
    uint8 index;
    IPC_S2M_EOLIVIRoutineControlResponse_t RoutineResponseIVI;
    IPC_S2M_EOLQNXRoutineControlResponse_t RoutineResponseQNX;
    
    #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
        EOL_EnterMainCnt()++;
        if(EOL_EnterMainCnt() == EOL_ENTERMAINFUNCMAXNUM)
        {
            EOL_SetEnterMainCnt(0);
            EOL_CurrentPendingCnt()++;
            if(EOL_CurrentPendingCnt() == EOL_PENDINGMAXNUM)
            {
                EOL_ClearPendingCnt();
                return RTE_E_INVALID;
            }
        }
    #endif

    if(((uint8)SPI_DIAG_IDEL) == EOL_DiagTransferStatusGet())
    {
        Service31_NRC = 0x00;
        EOL_SetStatusChangeTimer((uint16)STATUSCHANGEMAXTIME);
        Set_RoutineDataLen_0x31(DataLen);
        switch(ModuleID)
        {
            case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
                ServiceSendRecord.QNXSendFlag = TRUE;
                EOL_DiagTransferRoutineControl_TransmitQNX_0x31(RID,SubId,Data,DataLen);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("QNX Req 0x31,RID=0x%x!,SubId=0x%d",RID,SubId);
                #endif
                break;
            case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
                ServiceSendRecord.IVISendFlag = TRUE;
                EOL_DiagTransferRoutineControl_TransmitIVI_0x31(RID,SubId,Data,DataLen);
                #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
                    can_info("IVI Req 0x31,RID=0x%x!,SubId=0x%d",RID,SubId);
                #endif
                break;
            default:
                break;
        }
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Waiting for response!");
        #endif
    }
    else if(((uint8)SPI_DIAG_ROUTINE_RESPONSE_OK) == EOL_DiagTransferStatusGet()) 
    {
        switch(ModuleID)
        {
            case IPC_M2S_EOL_MSGMAJOR_QNX_ID:
                RoutineResponseQNX = EOL_DiagTransferGetQNX_RoutineResponseInfo();
                for(index = 0; index < Get_RoutineDataLen_0x31(); index++)
                {
                    Data[index] = RoutineResponseQNX.State[index];
                }
                break;
            case IPC_M2S_EOL_MSGMAJOR_IVI_ID:
                RoutineResponseIVI = EOL_DiagTransferGetIVI_RoutineResponseInfo();
                for(index = 0; index < Get_RoutineDataLen_0x31(); index++)
                {
                    Data[index] = RoutineResponseIVI.State[index];
                }
                break;
            default:
                break;
        }
        
        EOL_Reset();
        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Data has been received!");
        #endif
        ret = RTE_E_OK;
    }
    else if(((uint8)SPI_DIAG_ERR) == EOL_DiagTransferStatusGet())
    {
        EOL_Reset();
        #if (EOL_NRC_0x78_SWICTH_FLAG == STD_ON)
            EOL_SetEnterMainCnt(0);
            EOL_ClearPendingCnt();
        #endif
        #if (EOL_CANINFO_SPIPRINT_SWICTH_FLAG == STD_ON)
            can_info("Invalid received data!");
        #endif
        *ErrorCode = Service31_NRC;
        ret = RTE_E_INVALID;
    }
    else
    {
        /*do nothing*/
    }

    return ret;
}


/******************************************************************************/
/**
* @brief               <EOL_GetIVIResponseDIDFlexibleData_Service_0x22>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <payloadLen>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <uint16>    
*/
/******************************************************************************/
IPC_S2M_EOLIVIDidReadResponse_t * EOL_GetIVIResponseDIDFlexibleData_Service_0x22(void)
{
    /* Service 0x22，DID BE22/BE21 */
    return (&IVIDidReadResponseInfo);
}


/******************************************************************************/
/**
* @brief               <EOL_GetQNXResponseDIDFlexibleData_Service_0x22>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <payloadLen>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <uint16>    
*/
/******************************************************************************/
IPC_S2M_EOLQNXDidReadResponse_t * EOL_GetQNXResponseDIDFlexibleData_Service_0x22(void)
{
    /* Service 0x22，DID BE22/BE21 */
     return (&QNXDidReadResponseInfo);
}


/******************************************************************************/
/**
* @brief               <EOL_SetStatusChangeTimer>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <value>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <uint16>    
*/
/******************************************************************************/
void EOL_SetTimerValue_StatusChange(uint16 value)
{
    StatusChangeTimer = value;
}

/******************************************************************************/
/**
* @brief               <EOL_StatusReset>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <value>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <uint16>    
*/
/******************************************************************************/
void EOL_StatusReset(void)
{
   ServiceSendRecord.IVISendFlag = FALSE;
   ServiceSendRecord.QNXSendFlag = FALSE;
}

/******************************************************************************/
/**
* @brief               <EOL_GetService_ResponseInfo_For_NRC>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <uint16>    
*/
/******************************************************************************/
Service22ResponseInfo EOL_GetService_ResponseInfo_For_NRC(void)
{
    return Service22_NRC;
}

/******************************************************************************/
/**
* @brief               <EOL_ResetService22_ResponseInfo_For_NRC>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <void>    
*/
/******************************************************************************/
void EOL_ResetService22_ResponseInfo_For_NRC(void)
{
    uint16 index = 0x00;
    
    Service22_NRC.ResponseFlag = FALSE;
    Service22_NRC.ResponsePayloadLen = 0x00;
    Service22_NRC.ResponseServiceId = 0x00;

    for(index = 0x00 ; index < DIAG_SERVICE22_DATA_LENGTH;index++)
    {
        Service22_NRC.ResponseData[index] = 0x00;
    }
    EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
}


/******************************************************************************/
/**
* @brief               <EOL_GetService2E_ResponseServiceId>
* 
* <> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <uint8* ServiceId>
* @return              <void>    
*/
/******************************************************************************/
void EOL_GetService2E_ResponseServiceId(uint8* ServiceId)
{
    if(ServiceId != NULL_PTR)
    {
        *ServiceId = IVIDidWriteResponseInfo.ServiceId;
    }
}


void EOL_Reset(void)
{
    EOL_StatusReset();
    EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
    EOL_SetStatusChangeTimer(0);
}