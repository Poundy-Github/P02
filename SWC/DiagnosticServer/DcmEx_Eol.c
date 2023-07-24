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
 * @file:      DcmEx_Eol.c
 * @author:    Nobo
 * @date:      2020-5-24
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-24
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Rte_EOL.h"
#include "Dcm.h"
#include "DcmEx_Eol.h"

#define EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER     (50u)
#define EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA          ((uint8)47u)

static MutiPackageSendDataInfo *EOL_MutiPackageSendPreFunction(void);
static void EOL_MutiPackageSendPostFunction(void);

MutiPackageSendInfo MutiPackageSend = 
{
    {0x00},
    {0x00},
    EOL_MutiPackageSendPreFunction,
    EOL_MutiPackageSendPostFunction,
    EOL_MutiPackageSendFunc,
    NULL_PTR,
    SPI_MutiPackageSend_IDEL,
};

static MutiPackageSendDataInfo SendDataRecord = {0x00};

/* EOL */
Std_ReturnType EolWriteDataToIvi(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
  return EOL_DiagTransferWriteDIDHandle_0x2E(Did, Data, (uint8)DataLength, IPC_M2S_EOL_MSGMAJOR_IVI_ID, ErrorCode);
}

Std_ReturnType EolWriteDataToQnx(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
  return EOL_DiagTransferWriteDIDHandle_0x2E(Did, Data, (uint8)DataLength, IPC_M2S_EOL_MSGMAJOR_QNX_ID, ErrorCode);
}

Std_ReturnType EolReadDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    return EOL_DiagTransferReadDIDHandle_0x22(Did, Data, DataLength, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
}

Std_ReturnType EolReadDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    return EOL_DiagTransferReadDIDHandle_0x22(Did, Data, DataLength, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
}

Std_ReturnType EolReadFlexibleDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 index = 0x00;
    IPC_S2M_EOLQNXDidReadResponse_t *QNXReaddidResponseInfo = EOL_GetQNXResponseDIDFlexibleData_Service_0x22();

    while(index < QNXReaddidResponseInfo->DataLength)
    {
        Data[index] = QNXReaddidResponseInfo->Data[index];
        index++;
    }
    
    return RTE_E_OK;
}

Std_ReturnType EolReadDataLengthFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength)
{
    Std_ReturnType ret = DCM_E_PENDING;
    IPC_S2M_EOLQNXDidReadResponse_t* QNXReaddidResponseInfo = EOL_GetQNXResponseDIDFlexibleData_Service_0x22();

    switch(OpStatus)
    {
        case DCM_INITIAL:
            EOL_DiagTransferReadDIDHandle_0x22(Did, &(QNXReaddidResponseInfo->Data[0]), 0, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(QNXReaddidResponseInfo->DataLength != 0x00)
            {
                *DataLength = QNXReaddidResponseInfo->DataLength;
                ret = RTE_E_OK;
            }
            
            break;
        default:
            /*do nothing*/
            break;
    }

    return ret;
}

Std_ReturnType EolReadFlexibleDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 index = 0x00;
    IPC_S2M_EOLIVIDidReadResponse_t  *IVIReaddidResponseInfo = EOL_GetIVIResponseDIDFlexibleData_Service_0x22();

    while(index < IVIReaddidResponseInfo->DataLength)
    {
        Data[index] = IVIReaddidResponseInfo->Data[index];
        index++;
    }
    
    return RTE_E_OK;
}

Std_ReturnType EolReadDataLengthFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength)
{
    Std_ReturnType ret = DCM_E_PENDING;
    IPC_S2M_EOLIVIDidReadResponse_t  *IVIReaddidResponseInfo = EOL_GetIVIResponseDIDFlexibleData_Service_0x22();;
    
    switch(OpStatus)
    {
        case DCM_INITIAL:
            EOL_DiagTransferReadDIDHandle_0x22(Did, &(IVIReaddidResponseInfo->Data[0]), 0, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(IVIReaddidResponseInfo->DataLength != 0x00)
            {
                *DataLength = IVIReaddidResponseInfo->DataLength;
                ret = RTE_E_OK;
            }
            
            break;
        default:
            /*do nothing*/
            break;
    }
    
    return ret;
}

Std_ReturnType EolMixReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 Length)
{
    uint8 SessionMode;
    Std_ReturnType  ret = DCM_E_PENDING;

    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();

    if ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode)|| (RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == SessionMode))
    {
        ret = Rte_Call_ppCS_Diag_ReadDidData_Operation(Did, OpStatus, Data, Length);
    }
    else if(RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode) 
    {
        ret = EOL_DiagTransferReadDIDHandle_0x22(Did, Data, Length, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
    }
    else
    {
        ret = RTE_E_INVALID;
    }

    return ret;
}


Std_ReturnType EolPassThroughAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Service22ResponseInfo responseService22InfoGlobal;
    Std_ReturnType retVal = DCM_E_PENDING;

    responseService22InfoGlobal = EOL_GetService_ResponseInfo_For_NRC();

    if((0x00 == responseService22InfoGlobal.ResponseServiceId) && (responseService22InfoGlobal.ResponseFlag == FALSE))
    {
        EOL_DiagTransferReadDIDHandle_0x22(Did, responseService22InfoGlobal.ResponseData, DataLength, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
    }
    else if((responseService22InfoGlobal.ResponseServiceId != SERVICE_DIDREADBYIDENTIFIER_POSRES) && (responseService22InfoGlobal.ResponseFlag == TRUE))
    {
        EOL_ResetService22_ResponseInfo_For_NRC();
        EOL_Reset();
        *ErrorCode = responseService22InfoGlobal.ResponseServiceId;
        retVal = RTE_E_INVALID;
    }
    else if((responseService22InfoGlobal.ResponseServiceId == SERVICE_DIDREADBYIDENTIFIER_POSRES) && (responseService22InfoGlobal.ResponseFlag == TRUE))
    {
        retVal = RTE_E_OK;
    }

    return retVal;
}

Std_ReturnType EolPassThroughAvaiableCheckToIVI(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Service22ResponseInfo responseService22InfoGlobal;
    Std_ReturnType retVal = DCM_E_PENDING;

    responseService22InfoGlobal = EOL_GetService_ResponseInfo_For_NRC();

    if((0x00 == responseService22InfoGlobal.ResponseServiceId) && (responseService22InfoGlobal.ResponseFlag == FALSE))
    {
        EOL_DiagTransferReadDIDHandle_0x22(Did, responseService22InfoGlobal.ResponseData, DataLength, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
    }
    else if((responseService22InfoGlobal.ResponseServiceId != SERVICE_DIDREADBYIDENTIFIER_POSRES) && (responseService22InfoGlobal.ResponseFlag == TRUE))
    {
        EOL_ResetService22_ResponseInfo_For_NRC();
        EOL_Reset();
        *ErrorCode = responseService22InfoGlobal.ResponseServiceId;
        retVal = RTE_E_INVALID;
    }
    else if((responseService22InfoGlobal.ResponseServiceId == SERVICE_DIDREADBYIDENTIFIER_POSRES) && (responseService22InfoGlobal.ResponseFlag == TRUE))
    {
        retVal = RTE_E_OK;
    }

    return retVal;
}


Std_ReturnType EolPassThroughAvaiableReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 index = 0x00;
    Std_ReturnType retValue = E_NOT_OK;
    Service22ResponseInfo responseService22InfoGlobal;

    responseService22InfoGlobal = EOL_GetService_ResponseInfo_For_NRC();

    if((responseService22InfoGlobal.ResponseServiceId == SERVICE_DIDREADBYIDENTIFIER_POSRES) && (responseService22InfoGlobal.ResponseFlag == TRUE))
    {
        for(index = 0;index < responseService22InfoGlobal.ResponsePayloadLen;index++)
        {
            Data[index] = responseService22InfoGlobal.ResponseData[index];
        }
        retValue = RTE_E_OK;
    }
    else
    {
        retValue = RTE_E_INVALID;
    }

    EOL_ResetService22_ResponseInfo_For_NRC();
    EOL_Reset();

    return retValue;
}

void EOL_MutiPackageSendHandler(void)
{
   switch(MutiPackageSend.sendStatus)
   {
       case SPI_MutiPackageSend_SENDING:
           EOL_MutiPackageSendFunc();
           break;
       case SPI_MutiPackageSend_FINSHED:
           EOL_SetMutiPackageStatus((uint8)SPI_MutiPackageSend_WAITRESPONSE);
           break;
       default:
        /*do nothing*/
           break;
   }
}

static void EOL_MutiPackageSendInit(void)
{
    SendDataRecord.CRCCalValue = 0x00;
    SendDataRecord.currentSendCnt = 0x00;
    SendDataRecord.lastPackageFlag = 0x00;
    SendDataRecord.initCRCValue = 0xFFFF;
    SendDataRecord.totalSendCnt = 0x00;
    SendDataRecord.totalSendLength = 0x00;
    memset((uint8*)SendDataRecord.sendData, 0, EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER);
    memset((uint8*)MutiPackageSend.sendData, 0, EOL_MUTIPACKAGESENDMAXDATANUMBER);
    MutiPackageSend.sendStatus = SPI_MutiPackageSend_IDEL;
    MutiPackageSend.IPCSendStatus = FALSE;
    MutiPackageSend.sendDid = 0x00;
}

void EOL_MutiPackageSendFunc(void)
{
    MutiPackageSendDataInfo *localMutiPackageSendDataRecord;
    IPC_M2S_EOLQNXDidWriteRequest_t  sendData = {0x00};
    uint8 index = 0;
    sint8 ret = -1;

    if(MutiPackageSend.mutiPackageSendPreFunc != NULL_PTR)
    {
        localMutiPackageSendDataRecord = MutiPackageSend.mutiPackageSendPreFunc();
        
        sendData.Did = MutiPackageSend.sendDid;
        sendData.ServiceId = SERVICE_DIDWRITEBYIDENTIFIER;
        sendData.PayloadLength = EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER;
        for(index = 0; index < EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER; index++)
        {
            sendData.Payload[index] = localMutiPackageSendDataRecord->sendData[index];
        }
        
        ret = (uint8)IPC_M2S_EOLQNXDidWriteRequest_Transmit(&sendData);
        
        if(ret != 0)
        {
            MutiPackageSend.IPCSendStatus = TRUE;
        }
        else if((localMutiPackageSendDataRecord->lastPackageFlag == TRUE) && (ret == 0))
        {
            MutiPackageSend.sendStatus = SPI_MutiPackageSend_FINSHED;

            MutiPackageSend.IPCSendStatus = FALSE;
            SendDataRecord.lastPackageFlag = (uint8)FALSE;
        }
    }
}

static MutiPackageSendDataInfo *EOL_MutiPackageSendPreFunction(void)
{
    uint16 leftSendDataLength = 0;
    uint16 currentSendDataLength = 0;
    uint16 index = 0;
    
    if((SendDataRecord.currentSendCnt <= SendDataRecord.totalSendCnt) && (MutiPackageSend.IPCSendStatus == FALSE))
    {
        leftSendDataLength = SendDataRecord.totalSendLength - (SendDataRecord.currentSendCnt * EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA);

        /*index*/
        SendDataRecord.sendData[0] = (uint8)SendDataRecord.currentSendCnt;

        /*last package Flag*/
        if(leftSendDataLength <= EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA)
        {
            SendDataRecord.sendData[1] = 0x01;
            SendDataRecord.sendData[2] = (uint8)leftSendDataLength;
            currentSendDataLength = leftSendDataLength;
            SendDataRecord.lastPackageFlag = (uint8)TRUE;
        }
        else
        {
            SendDataRecord.sendData[1] = 0x00;
            SendDataRecord.sendData[2] = EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA;
            currentSendDataLength = EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA;
        }

        for(index = 3; index < (currentSendDataLength + 3); index++)
        {
            SendDataRecord.sendData[index] = MutiPackageSend.sendData[(SendDataRecord.currentSendCnt)*EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA + index - 3];
        }

        SendDataRecord.currentSendCnt++;
    }
    
    return &SendDataRecord;
}

static void EOL_MutiPackageSendPostFunction(void)
{
    SendDataRecord.CRCCalValue = 0x00;
    SendDataRecord.currentSendCnt = 0x00;
    SendDataRecord.lastPackageFlag = 0x00;
    SendDataRecord.initCRCValue = 0xFFFF;
    SendDataRecord.totalSendCnt = 0x00;
    SendDataRecord.totalSendLength = 0x00;
    
    memset((uint8*)SendDataRecord.sendData, 0, EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER);
    memset((uint8*)MutiPackageSend.sendData, 0, EOL_MUTIPACKAGESENDMAXDATANUMBER);
    MutiPackageSend.sendStatus = SPI_MutiPackageSend_IDEL;

    MutiPackageSend.IPCSendStatus = FALSE;
    MutiPackageSend.sendDid = 0x00;
}

void EOL_MutiPackageSendDataInfoFunc(uint16 DataLength, uint16 crcResult)
{
    if(DataLength != 0)
    {
        /*add 2 CRC Value*/
        SendDataRecord.totalSendLength = DataLength;
        SendDataRecord.totalSendCnt = (uint16)((SendDataRecord.totalSendLength + 46) / EOL_MUTIPACKAGE_DEND_MAX_VALID_DATA);
        
        memset((uint8*)SendDataRecord.sendData, 0, EOL_MUTIPACKAGE_SIGNALSEND_MAXDATANUMBER);
        SendDataRecord.CRCCalValue = crcResult;
        SendDataRecord.lastPackageFlag = 0x00;
        SendDataRecord.currentSendCnt = 0x00;
        MutiPackageSend.IPCSendStatus = FALSE;
    }
}

void EOL_SetMutiPackageStatus(uint8 status)
{
    MutiPackageSend.sendStatus = (SPI_MutiPackageHandleStatusType)status;

}

uint8 EOL_GetMutiPackageStatus(void)
{
    return (uint8)MutiPackageSend.sendStatus;
}
