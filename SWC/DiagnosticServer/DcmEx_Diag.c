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
 * @file:      DcmEx_Diag.c
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

#include "Rte_DidDataProcess.h"
#include "DcmEx_Diag.h"
#include "logger.h"

/* Diag part */
#define DCM_E_OK                            ((Std_ReturnType)E_OK)       /*!< Successful operation */
#define DCM_E_NOT_OK                        ((Std_ReturnType)E_NOT_OK)   /*!< Failed operation with no specific reason (except when NRC is returned in addition) */
#define DCM_E_PENDING                       ((Std_ReturnType)10)         /*!< Invoked callout (operation) needs to be called again */
#define DCM_E_FORCE_RCRRP                   ((Std_ReturnType)12)         /*!< Invoked callout (operation) requests an immediate RCR-RP response transmission and needs to be called again once it is (successfully or not) sent */

#define READ_SOC_DATA_MAX_TIME              (950u)
#define WRITE_SOC_DATA_MAX_TIME             (950u)

#define IVI_DATA_MAX_SIZE                   (500u)
#define IPC_MAX_BUF_SIZE                    (4000u)

#define NRC_5C                              (92u)

typedef struct LargeDataTransmitManger{
    uint16 dataLen;
    uint16 dataIndx;
    uint16 waitIviRspTime;
    uint16 remainingDataLen;
    uint8 sequenceCount;
}LargeDataTransmitManger_t;

static LargeDataTransmitManger_t  writeIviDataManger;
static LargeDataTransmitManger_t  readIviDataManger;

static IPC_M2S_DiagnoseIVIDidWriteRequest_t iviWriteDataRequest;
static IPC_S2M_DiagnoseIVIDidWriteResponse_t iviWriteDataResponse;
static IPC_M2S_DiagnoseIVIDidReadRequest_t iviReadDataRequest;
static IPC_S2M_DiagnoseIVIDidReadResponse_t iviReadDataResponse;
static uint8 ipcDataBuf[IPC_MAX_BUF_SIZE] = {0};

static IPC_M2S_DiagnoseQNXDidReadRequest_t didReadRequest;
static IPC_S2M_DiagnoseQNXDidReadResponse_t didReadRsp;
static IPC_M2S_DiagnoseQNXDidWriteRequest_t didWriteRequest;
static IPC_S2M_DiagnoseQNXDidWriteResponse_t didWriteRsp;

IPC_M2S_DiagnoseQNXRoutineControlRequest_t routineCtrlRequest;
static IPC_S2M_DiagnoseQNXRoutineControlResponse_t routineCtrlRsp;

static uint16 diagWaitSocRspTime = 0;

static Std_ReturnType WriteIVIDidDataProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen, uint8* ErrorCode);
static Std_ReturnType ReadIVIDidDataRepeate(uint8 OpStatus, uint8 *Data);
static Std_ReturnType ReadIVIDidDataStart(uint16 DataId, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength);
static void ReceiveIVIResponseData(void);
static void RequestPrintForData(const uint8 *data,uint16 datalength);
static void ResponsePrintForData(const uint8 *data,uint16 datalength, uint8 modetype);

static Std_ReturnType WriteIVIDidDataProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen, uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    uint8 reqIpcTx = 0;
    
    switch(OpStatus)
    {
        case DCM_INITIAL:
            memcpy(ipcDataBuf,Data,dataLen);
            
            writeIviDataManger.dataLen = dataLen;
            writeIviDataManger.dataIndx = 0;
            writeIviDataManger.remainingDataLen = dataLen;
            
            iviWriteDataRequest.ServiceId = 0x2E;
            iviWriteDataRequest.Did  = DataId;
            iviWriteDataRequest.TotalLenth = dataLen;
            iviWriteDataRequest.number = 0;
            
            if(writeIviDataManger.remainingDataLen  > IVI_DATA_MAX_SIZE)
            {
                memcpy((uint8*)iviWriteDataRequest.Payload,(uint8*)(&ipcDataBuf[writeIviDataManger.dataIndx]),IVI_DATA_MAX_SIZE);
                writeIviDataManger.dataIndx += IVI_DATA_MAX_SIZE;
                writeIviDataManger.remainingDataLen -= IVI_DATA_MAX_SIZE;
                iviWriteDataRequest.PayloadLength = IVI_DATA_MAX_SIZE;
                writeIviDataManger.waitIviRspTime = 15;
            
                reqIpcTx = 1;
            }
            else
            {
                if(writeIviDataManger.remainingDataLen > 0)
                {
                    memcpy((uint8*)iviWriteDataRequest.Payload,(uint8*)(&ipcDataBuf[writeIviDataManger.dataIndx]),writeIviDataManger.remainingDataLen);
                    iviWriteDataRequest.PayloadLength = writeIviDataManger.remainingDataLen;
                    writeIviDataManger.remainingDataLen = 0;
                    writeIviDataManger.waitIviRspTime = 950;/*wait 9.5s */
                    reqIpcTx = 1;
                }
            }
            if(0 != reqIpcTx)
            {
                iviWriteDataRequest.number += 1;
                IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(&iviWriteDataRequest); 

                RequestPrintForData(iviWriteDataRequest.Payload, iviWriteDataRequest.PayloadLength);
            }
         
            ret  = DCM_E_PENDING;
           
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            
            if(writeIviDataManger.remainingDataLen > 0)
            {
                if(writeIviDataManger.waitIviRspTime > 0)
                {
                    writeIviDataManger.waitIviRspTime--;
                }
                else
                {
                    if(writeIviDataManger.remainingDataLen  > IVI_DATA_MAX_SIZE)
                    {
                        memcpy((uint8*)iviWriteDataRequest.Payload,(const uint8*)(&Data[writeIviDataManger.dataIndx]),IVI_DATA_MAX_SIZE);
                        writeIviDataManger.dataIndx += IVI_DATA_MAX_SIZE;
                        writeIviDataManger.remainingDataLen -= IVI_DATA_MAX_SIZE;
                        iviWriteDataRequest.PayloadLength = IVI_DATA_MAX_SIZE;
                        writeIviDataManger.waitIviRspTime = 15;
                        reqIpcTx = 1;

                    }
                    else
                    {
                        memcpy((uint8*)iviWriteDataRequest.Payload,(const uint8*)(&Data[writeIviDataManger.dataIndx]),writeIviDataManger.remainingDataLen);
                        iviWriteDataRequest.PayloadLength = writeIviDataManger.remainingDataLen;
                        writeIviDataManger.remainingDataLen = 0;
                        writeIviDataManger.waitIviRspTime = 950;/*wait 9.5s */
                        reqIpcTx = 1;
                    }
                    
                    if(reqIpcTx)
                    {
                        iviWriteDataRequest.number += 1;
                        IPC_M2S_DiagnoseIVIDidWriteRequest_Transmit(&iviWriteDataRequest); 
                        
                        RequestPrintForData(iviWriteDataRequest.Payload, iviWriteDataRequest.PayloadLength);
                    }
                }
                ret = DCM_E_PENDING;
            }
            else
            {
                if((iviWriteDataRequest.Did != 0) && (iviWriteDataResponse.Did == iviWriteDataRequest.Did)&&
                        (iviWriteDataResponse.ServiceId == (iviWriteDataRequest.ServiceId + 0x40)))
                {
                    iviWriteDataRequest.Did = 0;
                    iviWriteDataResponse.Did = 0;
                    ret = DCM_E_OK; 
                }
                else if((iviWriteDataRequest.Did != 0) && (iviWriteDataResponse.Did == iviWriteDataRequest.Did)&&
                        (0x7F == iviWriteDataResponse.ServiceId))
                {
                    iviWriteDataRequest.Did = 0;
                    iviWriteDataResponse.Did = 0;
                    * ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
                else
                {
                    if(writeIviDataManger.waitIviRspTime > 0)
                    {
                        writeIviDataManger.waitIviRspTime--;
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        * ErrorCode = DCM_E_GENERALREJECT;
                        ret = E_NOT_OK;
                    }

                }
            }
           
        break;
        default:
            * ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        break;
    }

    return (ret);
}

Std_ReturnType WriteQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    uint16 i;
    
    switch(OpStatus)
    {
        case DCM_INITIAL:
            didWriteRequest.ServiceId = 0x2E;
            didWriteRequest.Did  = DataId;
            didWriteRequest.PayloadLength = dataLen;

            for(i = 0;i < didWriteRequest.PayloadLength;i++)
            {
                didWriteRequest.Payload[i] = Data[i]; 
            }
            IPC_M2S_DiagnoseQNXDidWriteRequest_Transmit(&didWriteRequest);
            
            RequestPrintForData(didWriteRequest.Payload, didWriteRequest.PayloadLength);
            diagWaitSocRspTime = WRITE_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( didWriteRequest.Did != 0 )&&(didWriteRequest.Did == didWriteRsp.Did))
            {
                if(didWriteRsp.ServiceId == (didWriteRequest.ServiceId + 0x40))
                {
                    ret = DCM_E_OK;
                }
                else if((DCM_E_GENERALPROGRAMMINGFAILURE == didWriteRsp.ServiceId)||(DCM_E_CONDITIONSNOTCORRECT == didWriteRsp.ServiceId)||
                        (DCM_E_REQUESTOUTOFRANGE == didWriteRsp.ServiceId))
                {
                    *ErrorCode = didWriteRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                else
                {
                    *ErrorCode = didWriteRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                didWriteRequest.Did = 0;
                didWriteRsp.Did  = 0;
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    didWriteRequest.Did = 0;
                    didWriteRsp.Did  = 0;
                    
                    *ErrorCode = DCM_E_GENERALREJECT;
                    ret = E_NOT_OK;
                }
            }
           
        break;
        default:
            /*do nothing*/
        break;
    }

    return (ret);
}

Std_ReturnType ReadIVIDidDataFixLengthProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length)
{    
    Std_ReturnType ret = DCM_E_OK;
    uint16 i;

    switch(OpStatus)
    {
        case DCM_INITIAL:
            iviReadDataRequest.ServiceId = 0x22;
            iviReadDataRequest.Did = DataId;
            IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(&iviReadDataRequest);
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( iviReadDataRequest.Did != 0 )&&(iviReadDataRequest.Did == iviReadDataResponse.Did)&&(iviReadDataResponse.ServiceId == (iviReadDataRequest.ServiceId + 0x40)))
            {
                if(iviReadDataResponse.DataLength < Length)
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    for(i = 0; i < Length; i++)
                    {
                        Data[i] = iviReadDataResponse.Data[i];
                    }               
                    ret = DCM_E_OK;
                }
                iviReadDataResponse.ServiceId = 0;
                iviReadDataResponse.Did = 0;
                iviReadDataRequest.Did = 0;
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                    
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
             
        break;
        default:
            /* do nothing */
        break;
    }

    return (ret); 
}

static Std_ReturnType ReadIVIDidDataRepeate(uint8 OpStatus, uint8 *Data)
{
    Std_ReturnType ret = DCM_E_OK;
    
    if(DCM_INITIAL == OpStatus)
    {
        readIviDataManger.waitIviRspTime = READ_SOC_DATA_MAX_TIME;
    }
    
    if((readIviDataManger.dataLen > 0)&&(readIviDataManger.dataIndx >= readIviDataManger.dataLen))
    {
        memcpy(Data,ipcDataBuf,readIviDataManger.dataLen);
    }
    else
    {
        if(readIviDataManger.waitIviRspTime > 0)
        {
            readIviDataManger.waitIviRspTime--;
            ret = DCM_E_PENDING;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }

    return (ret);
}

static Std_ReturnType ReadIVIDidDataStart(uint16 DataId,Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength)
{
    Std_ReturnType ret = DCM_E_OK;

    switch(OpStatus)
    {
        case DCM_INITIAL:
            iviReadDataRequest.ServiceId = 0x22;
            iviReadDataRequest.Did = DataId;
            readIviDataManger.waitIviRspTime = READ_SOC_DATA_MAX_TIME;
            readIviDataManger.sequenceCount = 0;
            readIviDataManger.dataLen = 0;
            IPC_M2S_DiagnoseIVIDidReadRequest_Transmit(&iviReadDataRequest);            

            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:

            if((0 != readIviDataManger.sequenceCount) && (0 != readIviDataManger.dataLen))
            {
                *DataLength = readIviDataManger.dataLen; 
            }
            else
            { 
                if(readIviDataManger.waitIviRspTime > 0)
                {
                    readIviDataManger.waitIviRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }             
        break;
            /*do nothing*/
        default:
        break;
    }

    return (ret);
}

Std_ReturnType ReadQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;


    switch(OpStatus)
    {
        case DCM_INITIAL:
            didReadRequest.ServiceId = 0x22;
            didReadRequest.Did = DataId;
            IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(&didReadRequest);
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( didReadRequest.Did != 0 )&&(didReadRequest.Did == didReadRsp.Did))
            {
                if(didReadRsp.ServiceId == (didReadRequest.ServiceId + 0x40))
                {
                    ret = DCM_E_OK;
                }
                else if((DCM_E_CONDITIONSNOTCORRECT == didReadRsp.ServiceId)||(DCM_E_REQUESTOUTOFRANGE == didReadRsp.ServiceId))
                {
                    *ErrorCode = didReadRsp.ServiceId;
                    ret = E_NOT_OK;
                }
                else
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
        break;
            /*do nothing*/
        default:
        break;
    }
    if(E_NOT_OK == ret)
    {
        didReadRequest.Did = 0;
        didReadRsp.Did = 0;
    }
    return (ret);
}

#if (CLUSTER_OFFSET_ADJUSTMENT_ENABLE == TRUE)
Std_ReturnType ReadQnxDidDataRequestProcessAndSave(uint16 DataId, uint8 OpStatus, uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    uint8 fctRet = E_NOT_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    static boolean Write_Offset_Flag = FALSE;

    switch(OpStatus)
    {
        case DCM_INITIAL:
            didReadRequest.ServiceId = 0x22;
            didReadRequest.Did = DataId;
            IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(&didReadRequest);
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(( didReadRequest.Did != 0 )&&(didReadRequest.Did == didReadRsp.Did))
            {
                if(didReadRsp.ServiceId == (didReadRequest.ServiceId + 0x40))
                {
                    if(Write_Offset_Flag == FALSE)
                    {
                        fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_GetErrorStatus(&nvmStatus);
                        if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
                        {
                            (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock(), &(didReadRsp.Data[0]), sizeof(Dcm_Data8ByteType));
                            (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_WriteBlock(NULL_PTR);
                            can_warn("S2M OffSetData: %X,%X,%X,%X,%X,%X,%X,%X", didReadRsp.Data[0],didReadRsp.Data[1],didReadRsp.Data[2],didReadRsp.Data[3],
                                                                                didReadRsp.Data[4],didReadRsp.Data[5],didReadRsp.Data[6],didReadRsp.Data[7]);
                            Write_Offset_Flag = TRUE;
                            ret = DCM_E_PENDING;
                        }
                        else
                        {
                            *ErrorCode = NRC_5C; 
                            ret = E_NOT_OK;
                        }
                    }
                    if(Write_Offset_Flag == TRUE)
                    {
                        fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_GetErrorStatus(&nvmStatus);
                        if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
                        {
                            if(NVM_REQ_OK != nvmStatus)
                            {
                                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock(), 0, sizeof(Dcm_Data8ByteType));
                                *ErrorCode = NRC_5C;
                                ret = E_NOT_OK;
                            }
                            else
                            {
                                Write_Offset_Flag =FALSE;
                            }
                        }
                        else
                        {
                            ret  = DCM_E_PENDING;
                        }
                    }
                }
                else
                {
                    *ErrorCode = didReadRsp.ServiceId;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            break;
            /*do nothing*/
        default:
            break;
    }
    if(E_NOT_OK == ret)
    {
        didReadRequest.Did = 0;
        didReadRsp.Did = 0;
    }
    return (ret);
}
#endif // (CLUSTER_OFFSET_ADJUSTMENT_ENABLE == TRUE)

Std_ReturnType CopyQnxDidRspData(uint16 DataId,uint8 *Data,uint16 Length)
{
    Std_ReturnType ret = E_NOT_OK;
    if((didReadRequest.Did == DataId )&&(didReadRequest.Did == didReadRsp.Did) && (didReadRsp.ServiceId == (didReadRequest.ServiceId + 0x40)))
    {
        memcpy(Data,&(didReadRsp.Data[0]),Length);
        ret = DCM_E_OK;
    }
    didReadRequest.Did = 0;
    didReadRsp.Did  = 0;
    return ret;
}

void DiagInit(void)
{
    didReadRequest.Did = 0;
    didReadRsp.Did = 0;
    didWriteRequest.Did = 0;
    didWriteRsp.Did  = 0;
}

Std_ReturnType DiagWriteDataToIvi(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    ret = WriteIVIDidDataProcess(Did, OpStatus, Data, DataLength, ErrorCode);

    return ret;
}

Std_ReturnType DiagWriteDataToQnx(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType  retVal = RTE_E_OK;
    retVal = WriteQnxDidDataRequestProcess(Did, OpStatus, Data, DataLength, ErrorCode);

    return retVal;
}

Std_ReturnType DiagReadFixDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    ret = ReadIVIDidDataFixLengthProcess(Did, OpStatus, Data, DataLength);
    return ret;
}

Std_ReturnType DiagReadFlexibleDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
    ret = ReadIVIDidDataRepeate(OpStatus, Data);
    return ret;
}

Std_ReturnType DiagReadDataLengthFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
    ret = ReadIVIDidDataStart(Did, OpStatus, DataLength);
    return ret;
}

Std_ReturnType DiagReadDataCheckFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 Length)
{
    Std_ReturnType retVal = RTE_E_OK;
    retVal = ReadQnxDidDataRequestProcess(Did, OpStatus, ErrorCode);
    return retVal;
}

Std_ReturnType DiagReadDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 Length)
{
    Std_ReturnType  retVal = RTE_E_OK;;
    retVal = CopyQnxDidRspData(Did, Data, Length);
    return retVal;
}

void IPC_Call_Diagnose_ReceiveData(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen)
{
    uint8 *dataPtr;
    uint16 i;
    if((IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID == msgMajorId))
    {
        switch(msgSubId)
        {
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_SESSIONCONTROLRESPONSE_ID:
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_ID:
                IPC_S2M_DiagnoseQNXDidReadResponse_Receive(param, &didReadRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_ID:
                IPC_S2M_DiagnoseQNXDidWriteResponse_Receive(param,&didWriteRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_IOCONTROLRESPONSE_ID:
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID:
                IPC_S2M_DiagnoseQNXRoutineControlResponse_Receive(param,&routineCtrlRsp, paramLen);
                break;
            case IPC_S2M_DIAGNOSE_QNX_MSGSUB_REPORTEVENTREQUEST_ID:
                Rte_Call_IPCSocReportDtcStatus_IpcSocReportDtcStatus(param,paramLen);
                break;
            default:
                break;
        }

    }
    
    if(IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID == msgMajorId)
    {
        switch(msgSubId)
        {

            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_ID:
                IPC_S2M_DiagnoseIVIDidReadResponse_Receive(param, &iviReadDataResponse, paramLen);
                ReceiveIVIResponseData();
                break;
            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_ID:
                IPC_S2M_DiagnoseIVIDidWriteResponse_Receive(param, &iviWriteDataResponse, paramLen);
                break;

            case IPC_S2M_DIAGNOSE_IVI_MSGSUB_REPORTEVENTREQUEST_ID:
                Rte_Call_IPCIviReportDtcStatus_IpcIviReportDtcSts(param,(uint8)paramLen);
                break;
            default:
                break;
        }
    }

    /* 22 2E 31 Reponse Data*/
    if(IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID == msgMajorId)
    {
        if((IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDREADRESPONSE_ID        == msgSubId)
        || (IPC_S2M_DIAGNOSE_QNX_MSGSUB_DIDWRITERESPONSE_ID       == msgSubId)
        || (IPC_S2M_DIAGNOSE_QNX_MSGSUB_ROUTINECONTROLRESPONSE_ID == msgSubId)
        )
        {
            ResponsePrintForData(param, paramLen, IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID);
        }
    }
    else if(IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID == msgMajorId)
    {
        if((IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDREADRESPONSE_ID   == msgSubId)
        || (IPC_S2M_DIAGNOSE_IVI_MSGSUB_DIDWRITERESPONSE_ID  == msgSubId)
        )
        {
            ResponsePrintForData(param, paramLen, IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID);
        }
    }
    else
    {
    }
    
}

static void ReceiveIVIResponseData(void)
{
    uint16 tmpLen;
    if(( iviReadDataRequest.Did != 0 )&&(iviReadDataRequest.Did == iviReadDataResponse.Did)&&(iviReadDataResponse.ServiceId == (iviReadDataRequest.ServiceId + 0x40)))
    {
        if((readIviDataManger.sequenceCount + 1) == iviReadDataResponse.Number)
        {
            if(1 == iviReadDataResponse.Number)
            {
                readIviDataManger.dataLen = iviReadDataResponse.TotalLength;
                readIviDataManger.remainingDataLen = iviReadDataResponse.TotalLength;
                readIviDataManger.dataIndx = 0;
            }

            if(readIviDataManger.remainingDataLen > iviReadDataResponse.DataLength)
            {
              tmpLen = iviReadDataResponse.DataLength;  
            }
            else
            {
                tmpLen = readIviDataManger.remainingDataLen;
            }            
            memcpy((uint8*)&ipcDataBuf[readIviDataManger.dataIndx],(uint8*)&iviReadDataResponse.Data[0],tmpLen);
            readIviDataManger.dataIndx += tmpLen;
            readIviDataManger.remainingDataLen -= tmpLen; 
            if(readIviDataManger.dataIndx >= readIviDataManger.dataLen)
            {
                iviReadDataRequest.Did = 0;
                iviReadDataRequest.ServiceId = 0;
            }
            readIviDataManger.sequenceCount += 1;

            iviReadDataResponse.Did = 0;
            iviReadDataResponse.ServiceId = 0;   
        }
        else
        {

        }
    }
}

void RequestQnxRoutineControl(uint16 RoutineId,uint8 Type,const uint8* Option,uint8 OptionLen)
{
    uint16 i;
    sint32 ret;
    routineCtrlRequest.ServiceId = 0x31 ;
    routineCtrlRequest.RoutineId = RoutineId;
    routineCtrlRequest.Type = Type;
    if(OptionLen)
    {
        for(i = 0;i < OptionLen;i++)
        {
            routineCtrlRequest.Option[i] = *Option;
            Option++;
        }
    }
    
    routineCtrlRequest.OptionLength = OptionLen;
    ret = IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(&routineCtrlRequest);
    if(ret)
    {
        IPC_M2S_DiagnoseQNXRoutineControlRequest_Transmit(&routineCtrlRequest);
    }
    
    diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
    
    can_warn("Diag QNX 31 DID = 0x%x",routineCtrlRequest.RoutineId);
    RequestPrintForData(routineCtrlRequest.Option, routineCtrlRequest.OptionLength);
}

Std_ReturnType QnxResponseRoutineControl(uint8* Status,uint8 StatusLen,uint8* ErrorCode)
{
    Std_ReturnType ret = DCM_E_OK;
    uint16 i;
    uint8 tLen;
    if((routineCtrlRequest.RoutineId != 0)&&
        (routineCtrlRequest.RoutineId == routineCtrlRsp.RoutineId)&&
        (routineCtrlRequest.Type == routineCtrlRsp.Type))
    {
        if(routineCtrlRsp.ServiceId ==(routineCtrlRequest.ServiceId + 0x40))
        {
            if(StatusLen > 0)
            {
                memcpy(Status,&routineCtrlRsp.State[0],StatusLen);
            }
        }
        else if(0x7F == routineCtrlRsp.ServiceId)
        {
            *ErrorCode = routineCtrlRsp.State[0];
            ret = E_NOT_OK;
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        routineCtrlRsp.RoutineId = 0;
        routineCtrlRequest.RoutineId = 0;
    }
    else
    {
        if(diagWaitSocRspTime > 0)
        {
            diagWaitSocRspTime--;
            ret = DCM_E_PENDING;
        }
        else
        {
            routineCtrlRequest.RoutineId = 0;
            *ErrorCode = DCM_E_GENERALREJECT;
            ret = E_NOT_OK;
        }
    }
    return (ret);
}

Std_ReturnType SocRspTimeOutHandle(uint8 OpStatus)
{
    Std_ReturnType retValue = DCM_E_PENDING;
    if(DCM_INITIAL == OpStatus )
    {
        diagWaitSocRspTime = WRITE_SOC_DATA_MAX_TIME;
    }
    if(diagWaitSocRspTime > 0)
    {
        diagWaitSocRspTime--;
    }
    else
    {
         retValue = E_NOT_OK;
    }
    return (retValue);
}

static void RequestPrintForData(const uint8 *data,uint16 datalength)
{
    uint8 i = 0u;
    uint16 didlength = 0u;
    
    
    didlength = datalength;
    if(didlength > 20u)
    {
        didlength = 20u;
    }

    if(didlength >= 5)
    {
        for(i = 0;i < (didlength/5u);i++)
        {
            can_warn("Diag 2E Data:0x%x,0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3],data[5*i+4]);
        }
    }

    if(1 == (didlength%5u))
    {
        can_warn("Diag 2E Data:0x%x",data[5*i]);
    }
    else if(2 == (didlength%5u))
    {
        can_warn("Diag 2E Data:0x%x,0x%x,",data[5*i],data[5*i+1]);
    }
    else if(3 == (didlength%5u))
    {
        can_warn("Diag 2E Data:0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2]);
    }
    else if(4 == (didlength%5u))
    {
        can_warn("Diag 2E Data:0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3]);
    }
    else
    {
    }
    
}

static void ResponsePrintForData(const uint8 *data,uint16 datalength, uint8 modetype)
{
    uint8 i = 0u;
    uint16 didlength = 0u;


    didlength = datalength;
    if(didlength > 20u)
    {
        didlength = 20u;
    }

    if(IPC_S2M_DIAGNOSE_MSGMAJOR_QNX_ID == modetype)
    {
        if(didlength >= 5)
        {
            for(i = 0;i < (didlength/5u);i++)
            {
                
                can_warn("Diag Rec QNX Data:0x%x,0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3],data[5*i+4]);
            }
        }

        if(1 == (didlength%5u))
        {
            can_warn("Diag Rec QNX Data:0x%x",data[5*i]);
        }
        else if(2 == (didlength%5u))
        {
            can_warn("Diag Rec QNX Data:0x%x,0x%x,",data[5*i],data[5*i+1]);
        }
        else if(3 == (didlength%5u))
        {
            can_warn("Diag Rec QNX Data:0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2]);
        }
        else if(4 == (didlength%5u))
        {
            can_warn("Diag Rec QNX Data:0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3]);
        }
        else
        {
        }

    }
    else if(IPC_S2M_DIAGNOSE_MSGMAJOR_IVI_ID == modetype)
    {
        if(didlength >= 5)
        {
            for(i = 0;i < (didlength/5u);i++)
            {
                
                can_warn("Diag Rec IVI Data:0x%x,0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3],data[5*i+4]);
            }
        }

        if(1 == (didlength%5u))
        {
            can_warn("Diag Rec IVI Data:0x%x",data[5*i]);
        }
        else if(2 == (didlength%5u))
        {
            can_warn("Diag Rec IVI Data:0x%x,0x%x,",data[5*i],data[5*i+1]);
        }
        else if(3 == (didlength%5u))
        {
            can_warn("Diag Rec IVI Data:0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2]);
        }
        else if(4 == (didlength%5u))
        {
            can_warn("Diag Rec IVI Data:0x%x,0x%x,0x%x,0x%x",data[5*i],data[5*i+1],data[5*i+2],data[5*i+3]);
        }
        else
        {
        }

    }

}

Std_ReturnType DiagReadDataLengthFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength)
{
    Std_ReturnType ret = DCM_E_OK;

    switch(OpStatus)
    {
        case DCM_INITIAL:
            didReadRequest.ServiceId = 0x22;
            didReadRequest.Did = Did;
            memset(&didReadRsp,0x00,sizeof(IPC_S2M_DiagnoseQNXDidReadResponse_t));
            
            IPC_M2S_DiagnoseQNXDidReadRequest_Transmit(&didReadRequest);
            
            diagWaitSocRspTime = READ_SOC_DATA_MAX_TIME;
            ret  = DCM_E_PENDING;
        break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(didReadRequest.Did == didReadRsp.Did)
            {
                if(((didReadRequest.ServiceId + 0x40) == didReadRsp.ServiceId) && (didReadRsp.DataLength > 0))
                {
                    *DataLength = didReadRsp.DataLength;
                    can_warn("Read Q DID 0x%x Len:%d", didReadRequest.Did, *DataLength);
                    ret = DCM_E_OK;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                if(diagWaitSocRspTime > 0)
                {
                    diagWaitSocRspTime--;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
        break;
        default:
        break;
    }
    
    if(E_NOT_OK == ret)
    {
        didReadRequest.Did = 0u;
        didReadRsp.Did = 0u;
    }
    return (ret);
}



Std_ReturnType DiagReadFlexibleDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
    uint8 i = 0u;

    if(didReadRsp.DataLength > 0u)
    {
        for(i = 0u;i < didReadRsp.DataLength;i++)
        {
            Data[i] = didReadRsp.Data[i];
        }
        can_warn("Read Flex DID 0x%x, Data:%s", Did, Hex2Str(&Data[0], didReadRsp.DataLength));
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}



