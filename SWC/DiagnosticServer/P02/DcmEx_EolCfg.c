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
 * @file:      DcmEx_EolCfg.c
 * @author:    Nobo
 * @date:      2020-5-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Rte_EOL.h"
#include "DcmEx_Eol.h"
#include "DcmEx_EolCfg.h"
#include "EOL_Diag.h"
#include "ComEx_Cfg.h"
#include "IoHwAb_Cfg_RI.h"
#include "Crc.h"

extern Std_ReturnType IoHwAb_GetPin(uint8 Id, boolean *Pin);
extern uint8 Power_IVIResponse(void);
extern void PM_EOL_FastSleep(void);


Std_ReturnType DataServices_Battery_Voltage_Battery_Voltage_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    SystemState_RecordType SysValue;
    Std_ReturnType         ret;
    Std_ReturnType         resultRet = RTE_E_INVALID;
    uint16                 voltageValue;
    
    ret = Rte_Read_EOL_BatteryVoltage_0xFD10_SystemStateOut(&SysValue);
    
    if(ret == RTE_E_OK)
    {
        voltageValue = (uint16)((SysValue.s_PowerVoltage.value) * 100);
        Data[0] = (uint8)(voltageValue >> 8);
        Data[1] = (uint8)(voltageValue);
        resultRet = RTE_E_OK;
    }
    else
    {
        resultRet = DCM_E_PENDING;
    }

    return resultRet;
}

Std_ReturnType DataServices_ChipsTemperature_ChipsTemperature_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 QNXData[1];
    EOL_Struct_3Element AMPData;
    Std_ReturnType AMPRet = RTE_E_INVALID;
    Std_ReturnType QNXRet = SPI_DIAG_IDEL;
    boolean  AMPRetFlag = FALSE;
    Std_ReturnType ret = DCM_E_PENDING;

    if(((uint8)SPI_DIAG_IDEL) == QNXRet)
    {
        AMPRet = Rte_Call_EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(&AMPData);
        if(RTE_E_OK == AMPRet)
        {
            AMPRetFlag = TRUE;
        }
    }

    if(TRUE == AMPRetFlag)
    {
        QNXRet = EOL_DiagTransferReadDIDHandle_0x22(0xBE02, QNXData, 1, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
        if(RTE_E_OK == QNXRet)
        {
            AMPRetFlag = FALSE;
            QNXRet = SPI_DIAG_IDEL;
            Data[0] = QNXData[0];
            Data[1] = AMPData.MCUTemperature;
            Data[2] = AMPData.AMP1Temperature;
            Data[3] = AMPData.AMP2Temperature;
            return RTE_E_OK;
        }
    }
    
    return ret;
}

Std_ReturnType DataServices_ClusterHardwareInput_ClusterHardwareInput_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret;
    Std_ReturnType resultRet = E_NOT_OK;

    resultRet = Rte_Call_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(Data);

    if(resultRet == E_OK)
    {
        ret = E_OK;
    }
    else
    {
        ret = DCM_E_PENDING;
    }
        
    return ret;
}

Std_ReturnType DataServices_Data_ReadAmpCalibrationValue_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    EOL9Bytes receData;
    uint8 index = 0x00;

    Rte_Read_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(receData);

    if(receData != NULL_PTR)
    {
        while(index < sizeof(EOL9Bytes))
        {
            *(Data++) = receData[index];
            index++;
        }
    }

  return RTE_E_OK;
}

Std_ReturnType DataServices_Display_enablingValues_Display_enablingValues_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{

    uint8 sendData[2] = {0};
    Std_ReturnType ret = DCM_E_PENDING;

    if(((Data[0] == 0x00) || (Data[0] == 0x01) || (Data[0] == 0x10)|| (Data[0] == 0x11))
        && ((Data[1] == 0x00) || (Data[1] == 0x01) || (Data[1] == 0x10)|| (Data[1] == 0x11)))
    {
        sendData[0] = Data[0];
        sendData[1] = Data[1];
        (void)Rte_Call_EOL_0xFDD9_EOL_WriteValueForDispalyEnable((uint8 *)&sendData);
        ret = RTE_E_OK;
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = RTE_E_INVALID;
    }
    
    return ret;
}

Std_ReturnType DataServices_ECUSerialNumber_ECUSerialNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
   Std_ReturnType ret = RTE_E_OK;

   (void)memcpy((uint8 *)Data,(uint8*)RtePim_NvBlockNeed_0xF18C_MirrorBlock(),sizeof(A_20Bytes));

   return ret;
}

Std_ReturnType DataServices_ECUSerialNumber_ECUSerialNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 ipcResp;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_0xF18C_GetErrorStatus(&nvmStatus);    
            if(NVM_REQ_PENDING != nvmStatus)
            {
                (void)memcpy((uint8*)RtePim_NvBlockNeed_0xF18C_MirrorBlock(),(uint8 *)Data,sizeof(A_20Bytes));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_0xF18C_WriteBlock(NULL_PTR);
            Rte_Write_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(Data);

            
            ret  = DCM_E_PENDING;
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_0xF18C_GetErrorStatus(&nvmStatus);  
        
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                }
            }
            else
            {
                ret  = DCM_E_PENDING;
            }
            break;
        default:
            break;
    
    }

    return ret;
}

Std_ReturnType DataServices_FactoryReset_FactoryReset_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    uint8 IVIReturnStatus = 0xFF;
    uint8 IVIReturnServiceId = 0xFF;
    boolean SocResetStatus = FALSE;
    Std_ReturnType ret = DCM_E_PENDING;
    
    if (*Data != 0x01)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = RTE_E_INVALID;
    }
    else
    {
        switch(OpStatus)
        { 
            case DCM_INITIAL:
                EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
                EOL_DiagTransferWriteDIDHandle_0x2E(0xBE01, Data, 1, IPC_M2S_EOL_MSGMAJOR_IVI_ID, ErrorCode);
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                EOL_GetService2E_ResponseServiceId(&IVIReturnServiceId);
                Rte_Read_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady(&SocResetStatus);
    
                if((SocResetStatus == TRUE) && (IVIReturnServiceId == SERVICE_DIDWRITEBYIDENTIFIER_POSRES))
                {
                    EOL_StatusReset();
                    EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
                    EOL_SetTimerValue_StatusChange(0);
                    ret = RTE_E_OK;
                }
                else if((IVIReturnServiceId != 0xFF) && (IVIReturnServiceId != 0x00) && (IVIReturnServiceId != SERVICE_DIDWRITEBYIDENTIFIER_POSRES))
                {
                    EOL_StatusReset();
                    EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
                    EOL_SetTimerValue_StatusChange(0);
                    *ErrorCode = IVIReturnServiceId;
                    ret = RTE_E_INVALID;
                }
                break;
            default:
                break;
        }
    }

    return ret;
}

Std_ReturnType DataServices_IPAddress_IP_Address_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = DCM_E_PENDING;
    static uint8 IPAddressData[48] = {0x00};
    static boolean  QNXRetFlag = FALSE;
    static uint8  IVISendStatus = SPI_DIAG_IDEL;
    Std_ReturnType retQNX;
    uint8 index;

    if(SPI_DIAG_IDEL == IVISendStatus)
    {
        retQNX = EOL_DiagTransferReadDIDHandle_0x22(0xBE67, &IPAddressData[24], 24, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
        if(RTE_E_OK == retQNX)
        {
            QNXRetFlag = TRUE;
        }
    }
    
    if(TRUE == QNXRetFlag)
    {
        IVISendStatus = EOL_DiagTransferReadDIDHandle_0x22(0xBE67, &IPAddressData[0], 24, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
        if(IVISendStatus == RTE_E_OK) 
        {
            QNXRetFlag = FALSE;
            IVISendStatus = SPI_DIAG_IDEL;
            for(index = 0; index < 48;index++)
            {
                Data[index] = IPAddressData[index];
            }
            return RTE_E_OK;
        }
        else if(RTE_E_INVALID == IVISendStatus)
        {
            QNXRetFlag = FALSE;
            IVISendStatus = SPI_DIAG_IDEL;
        }
    }

    return ret;
}

Std_ReturnType DataServices_KL15Status_KL15Status_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType          resultRet = RTE_E_INVALID;
    uint8                   SysPowerMod = 0;
    uint8                   retSysPowerMod = RTE_E_INVALID;
    
    retSysPowerMod = Rte_Call_EOL_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &SysPowerMod, sizeof(SysPowerMod));
    if((E_OK == retSysPowerMod) || (COMEX_UPDATE_RECEIVED == retSysPowerMod))
    {
        if(0u == SysPowerMod)
        {
            *Data = 0u;
        }
        else if(1u == SysPowerMod)
        {
            *Data = 2u;
        }
        else if(2u == SysPowerMod)
        {
            *Data = 1u;
        }
        else if(3u == SysPowerMod)
        {
            *Data = 3u;
        }
        else
        {
            *Data = 0u;
        }

        resultRet = RTE_E_OK;
    }
    else
    {
        resultRet = DCM_E_PENDING;
    }

    return resultRet;
}

Std_ReturnType DataServices_MACAddress_MACAddress_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 index = 0;
    uint8 QNXData[6];
    static uint8 IVIData[6];
    Std_ReturnType IVIRet = RTE_E_INVALID;
    Std_ReturnType QNXRet = RTE_E_INVALID;
    static uint8 readStep = 0;
    Std_ReturnType  ret = DCM_E_PENDING;

    if(0 == readStep)
    {
        memset(IVIData, 0x00, sizeof(IVIData));
        IVIRet = EOL_DiagTransferReadDIDHandle_0x22(0xF1EC, IVIData, 6, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
        if(RTE_E_OK == IVIRet)
        {
            readStep = 1;
        }
        else if(RTE_E_INVALID == IVIRet)
        {
            ret = RTE_E_INVALID;
        }
        else
        {

        }
    }

    if(1 == readStep)
    {
        QNXRet = EOL_DiagTransferReadDIDHandle_0x22(0xF1EC, QNXData, 6, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
        if(RTE_E_OK == QNXRet)
        {
            readStep = 0;
            for(index = 0; index < 6; index++)
            {
                Data[index] = QNXData[index];
                Data[index + 6] = IVIData[index];
            }
            return RTE_E_OK;
        }
        else if(RTE_E_INVALID == QNXRet)
        {
            readStep = 0;
            ret = RTE_E_INVALID;
        }
        else
        {

        }
    }

    return ret;
}

Std_ReturnType DataServices_MICStatus_MICStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType returnRet;
    uint8 index;
    uint8 MICValueArr[2]={0};
    Std_ReturnType ret = RTE_E_INVALID;
    
    returnRet = Rte_Call_EOL_0xFDD1_EOL_ReadMICStatus(MICValueArr);

    if(returnRet == RTE_E_OK)
    {
        for(index =0; index < 2;index++)
        {
            Data[index] = MICValueArr[index];
        }
        ret = RTE_E_OK;
    }

    return ret;
}

Std_ReturnType DataServices_PHYMaster_SlaveMode_Master_Slave_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
  uint8 SessionMode;
  Std_ReturnType  ret = DCM_E_PENDING;
  
  SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
  
  if ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode)|| (RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == SessionMode))
  {
      ret = Rte_Call_ppCS_Diag_ReadDidData_Operation(0xf1d7, OpStatus, Data, 8);
  }
  
  return ret;
}

Std_ReturnType DataServices_Radio_Antenna_Status_RadioAntennaStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 index;
    uint8 receiveData[3] = {0};
    Std_ReturnType ret = DCM_E_PENDING;
    Std_ReturnType returnRet = RTE_E_INVALID;

    returnRet = Rte_Read_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(receiveData);

    if((returnRet == RTE_E_OK) && (receiveData[0] != 0xFF))
    {
        for(index = 0;index < 3;index++)
        {
            Data[index] = receiveData[index];
        }
        ret = RTE_E_OK;
    }
    
    return ret;
}

Std_ReturnType DataServices_ReadGPSSatelliteCount_ReadGPSSatelliteCount_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = DCM_E_PENDING;
    Std_ReturnType retGPSCNT = RTE_E_INVALID;
    
    retGPSCNT = Rte_Read_EOL_ReadGPSSatelliteCount_GPSSatelliteCount(Data);

    if (RTE_E_OK == retGPSCNT)
    {
        return RTE_E_OK;
    }

    return ret;
}

Std_ReturnType DataServices_ResetInformation_ResetInformation_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{

    Std_ReturnType returnRet;
    uint8 index;
    uint8 ResetInfoValueArr[64]={0};
    Std_ReturnType ret = RTE_E_INVALID;
    
    returnRet = Rte_Call_EOL_0xFDE2_EOL_ReadResetInformation(ResetInfoValueArr);

    if(returnRet == RTE_E_OK)
    {
        for(index = 0u; index < 64u; index++)
        {
            Data[index] = ResetInfoValueArr[index];
        }
        ret = RTE_E_OK;
    }
    
    return ret;
}

Std_ReturnType DataServices_SpeakerStatus_SpeakerStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret;
    Std_ReturnType resultRet = RTE_E_INVALID;
    
    ret = Rte_Call_EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(Data);

    if(ret == RTE_E_OK)
    {
        resultRet = RTE_E_OK;
    }
    else
    {
        resultRet = DCM_E_PENDING;
    }
    
    return resultRet;
}

Std_ReturnType DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;

    (void)memcpy((uint8 *)Data,(uint8*)RtePim_NvBlockNeed_0xF193_MirrorBlock(),sizeof(Rte_EOL_NvBlockNeed_0xF193_MirrorBlock));

    return ret;
}

Std_ReturnType DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 ipcResp;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_0xF193_GetErrorStatus(&nvmStatus);    
            if(NVM_REQ_PENDING != nvmStatus)
            {
                (void)memcpy((uint8*)RtePim_NvBlockNeed_0xF193_MirrorBlock(),(uint8 *)Data,sizeof(Rte_EOL_NvBlockNeed_0xF193_MirrorBlock));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_0xF193_WriteBlock(NULL_PTR);
            Rte_Write_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(Data);

            
            ret  = DCM_E_PENDING;
            break;

        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_0xF193_GetErrorStatus(&nvmStatus);  
        
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                }
            }
            else
            {
                ret  = DCM_E_PENDING;
            }
            break;

        default:
            break;
    
    }

    return ret;
}

Std_ReturnType DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Version_GetSystemSupplierECUSoftwareVersionNumber(Data, 0x12);
    return RTE_E_OK;
}

Std_ReturnType DataServices_TBOXMuteValue_Mute_value_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    boolean PinStatus;
    Std_ReturnType ret = RTE_E_INVALID;
    Std_ReturnType returnRet = RTE_E_INVALID;

    returnRet = IoHwAb_GetPin(RI_IoHwAb_DOut_PinOutCfg_VIP_TM_IDL, &PinStatus);

    if(returnRet == RTE_E_OK)
    {
        *Data = PinStatus;
        ret = RTE_E_OK;
    }

    return ret;
}

Std_ReturnType DataServices_UIN_UIN_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    uint8 SessionMode;
    Std_ReturnType  ret = DCM_E_PENDING;

    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();

    if ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode)|| (RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == SessionMode))
    {
        ret = Rte_Call_ppCS_Diag_ReadDidData_Operation(0xf1c5, OpStatus, Data, 20);
    }
    else if(RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode)
    {
        ret = EOL_DiagTransferReadDIDHandle_0x22(0xF1C5, Data, 20, IPC_M2S_EOL_MSGMAJOR_IVI_ID);
    }
    else
    {
        ret = RTE_E_INVALID;
    }

    return ret;
}

Std_ReturnType DataServices_VIPBootloaderVersion_VIPBootloaderVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength) 
{
    Version_GetBootloaderVersionVIP(Data,4);

    return RTE_E_OK;
}

Std_ReturnType DataServices_VIPSoftwareVersion_VIPSoftwareVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Version_GetSoftwareVersionVIP(Data,4);
    Rte_Write_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(Data);

    return RTE_E_OK;
}

Std_ReturnType DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;

    (void)memcpy((uint8 *)Data,(uint8*)RtePim_NvBlockNeed_0xF187_MirrorBlock(), sizeof(EOL_13Bytes));

    return ret;
}

Std_ReturnType DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 ipcResp;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            Rte_Call_NvMService_AC2_SRBS_0xF187_GetErrorStatus(&nvmStatus);    
            if(NVM_REQ_PENDING != nvmStatus)
            {
                (void)memcpy((uint8*)RtePim_NvBlockNeed_0xF187_MirrorBlock(),(uint8 *)Data,sizeof(EOL_13Bytes));
            } 
            (void)Rte_Call_NvMService_AC2_SRBS_0xF187_WriteBlock(NULL_PTR);
            Rte_Write_EOL_PartNumber_0xF187_PartNumber_0xF187(Data);
            Rte_Write_EOL_SRpVehSparePartNumber_SparePartNumber(Data);

            
            ret  = DCM_E_PENDING;
            break;

        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_0xF187_GetErrorStatus(&nvmStatus);  
        
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                }
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;

        default:
            break;
    }

    return ret;
}

/* EOL */
Std_ReturnType EolScreenAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 Length)
{
    Std_ReturnType retVal = DCM_E_PENDING;
    Service22ResponseInfo responseService22InfoGlobal;
    
    responseService22InfoGlobal = EOL_GetService_ResponseInfo_For_NRC();
    
    if((0x00 == responseService22InfoGlobal.ResponseServiceId) && (responseService22InfoGlobal.ResponseFlag == FALSE))
    {
        EOL_DiagTransferReadDIDHandle_0x22(Did, responseService22InfoGlobal.ResponseData, Length, IPC_M2S_EOL_MSGMAJOR_QNX_ID);
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

Std_ReturnType EolScreenAvaiableReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, Dcm_NegativeResponseCodeType *ErrorCode, uint16 Length)
{
    uint8 SessionMode;
    Std_ReturnType  ret = DCM_E_PENDING;

    uint8 index = 0x00;
    Std_ReturnType retValue = E_NOT_OK;
    Service22ResponseInfo responseService22InfoGlobal;
    
    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();

    if ((RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode) || (RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION == SessionMode))
    {
        ret = Rte_Call_ppCS_Diag_ReadDidData_Operation(Did, OpStatus, Data, Length);
    }
    else if(RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode)
    {
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
    else
    {
        ret = RTE_E_INVALID;
    }
    
    return ret;
}

Std_ReturnType DataServices_PHYMaster_SlaveMode_Master_Slave_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    uint8 SessionMode;
    Dcm_SecLevelType securityLvl;
    uint8 fctRet = DCM_E_PENDING;
    SessionMode = Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
    Rte_Call_DCMServices_GetSecurityLevel(&securityLvl);

    if(RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == SessionMode)
    {
         if(DCM_SEC_LEV_L1 == securityLvl)
         {
             fctRet = Rte_Call_ppCS_Diag_WriteDidData_Operation(0xf1d7, OpStatus,(uint8 *)Data, 8, ErrorCode);
         }
    }
    else if(RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession == SessionMode)
    {
        fctRet = EOL_DiagTransferWriteDIDHandle_0x2E(0xf1d7, Data, 8, IPC_M2S_EOL_MSGMAJOR_QNX_ID, ErrorCode);
    }
    return (fctRet);
}

Std_ReturnType DataServices_Data_WriteRootCA_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    uint16 index = 0;
    uint16 crcResult = 0;
    Std_ReturnType ret = DCM_E_PENDING;

    if((MutiPackageSend.sendStatus == SPI_MutiPackageSend_IDEL) && (DataLength != 0))
    {
        for(index = 0; index <DataLength; index++)
        {
            MutiPackageSend.sendData[index] = Data[index];
        }
        crcResult = Crc_CalculateCRC16(Data, DataLength, 0xFFFF, TRUE);
        
        MutiPackageSend.sendData[DataLength] = (uint8)(crcResult >> 8);
        MutiPackageSend.sendData[DataLength + 1] = (uint8)crcResult;
        
        MutiPackageSend.sendDid = 0xBE3B;
        EOL_MutiPackageSendDataInfoFunc(DataLength + 2,crcResult);
        MutiPackageSend.sendStatus = SPI_MutiPackageSend_SENDING;
    }
    else if(MutiPackageSend.sendStatus == SPI_MutiPackageSend_RESPONSECHECK_OK)
    {
        MutiPackageSend.sendStatus = SPI_MutiPackageSend_IDEL;
        if(MutiPackageSend.mutiPackageSendPostFunc != NULL_PTR)
        {
            MutiPackageSend.mutiPackageSendPostFunc();
        }
        ret = RTE_E_OK;
    }
    else if(MutiPackageSend.sendStatus == SPI_MutiPackageSend_ERR)
    {
        MutiPackageSend.sendStatus = SPI_MutiPackageSend_IDEL;
        if(MutiPackageSend.mutiPackageSendPostFunc != NULL_PTR)
        {
            MutiPackageSend.mutiPackageSendPostFunc();
        }
        
        *ErrorCode = EOL_DiagService_0x2E_ResponseStatusGet();
        ret = RTE_E_INVALID;
    }
    
    return ret;
}

Std_ReturnType DataServices_Data_AndriodReadyStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
  Std_ReturnType retVal = RTE_E_OK;
  uint8 ivistate = 0u;

  ivistate = Power_IVIResponse();
  *Data = ivistate;
  can_warn("AndriodStatus is %d",ivistate);
  
  return retVal;
}

Std_ReturnType DataServices_Data_EnterSleep_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    uint8 sleepData;

    sleepData = *Data;

    if(sleepData == 1u)
    {
        PM_EOL_FastSleep();
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = RTE_E_INVALID;
    }

  return ret;
}

