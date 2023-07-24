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
 * @file:      DcmEx_DiagCfg.c
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

#include "Rte_DidDataProcess.h"
#include "DcmEx_DiagCfg.h"
#include "DcmEx.h"
#include "Version.h"
#include "Vconfig_cfg.h"
#include "SecOC.h"
#include "IPC_EOL.h"
#include "EOL_Diag.h"
#include <string.h>

extern uint8 diagVConfigDataBuf[400];

static uint8 WriteVconfigRequestCounter = 0;
static uint8 WriteCconfigRequestCounter = 0;


/* Diag */
Std_ReturnType ReadVipDidDataReqProcess(uint16 DID, uint8 OpStatus, uint8 *Data, uint16 Length)
{
   Std_ReturnType ret = RTE_E_OK;
    switch(DID)
    {
        case 0xF18A:
            Version_GetSystemSupplierIdentifier(Data,Length);
        break;
        case 0xF1A2:
            Version_GetCANMatrixVersion(Data,Length);
            break;
        case 0xF1C0:
            Version_GetGwmEcuCalibrationSoftwareVersionn(Data,Length);
            break;
        case 0xF1C1:
            Version_GetGwmEcuBootSoftwareVersion(Data,Length);
            break;
        default:
            break;
    }

    return (ret);
}

/* get connector status from vconfig */
ConnectorStatus_t DidGetConnectorStatus(void)
{
    ConnectorStatus_t returnStatus = CONNECTOR_INVAILD;

    if((diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x03)
     ||(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x05))
    {
        returnStatus = CONNECTOR_EX_AVM;
    }
    else if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
    {
        returnStatus = CONNECTOR_IN_AVM;
    }
    else if((diagVConfigDataBuf[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM] == 0x1)
        &&((diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x1)
            ||(diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x2)
            ||(diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x3)))
    {
        returnStatus = CONNECTOR_SVC_RVC;
    }
    else if(diagVConfigDataBuf[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM] == 0x1)
    {
        returnStatus = CONNECTOR_SVC;
    }
    else if((diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x1)
            ||(diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x2)
            ||(diagVConfigDataBuf[VCONFIG_KIND_REVERSE_VIDEO] == 0x3))
    {
        returnStatus = CONNECTOR_RVC;
    }
    else
    {
        /* do nothing */
    }

    return returnStatus;
}

Std_ReturnType DiagAvmAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = E_NOT_OK;
    if(diagVConfigDataBuf[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION] == 0x2)
    {
        ret = ReadQnxDidDataRequestProcess(Did, OpStatus, ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
}

Std_ReturnType DiagBardAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = E_NOT_OK;
    if(((diagVConfigDataBuf[VCONFIG_KIND_PROJECT_CODE] == VCONFIG_PROJECT_P03_1)
        ||(diagVConfigDataBuf[VCONFIG_KIND_PROJECT_CODE] == VCONFIG_PROJECT_P03_1G)
        ||(diagVConfigDataBuf[VCONFIG_KIND_PROJECT_CODE] == VCONFIG_PROJECT_P03_YY)
        ||(diagVConfigDataBuf[VCONFIG_KIND_PROJECT_CODE] == VCONFIG_PROJECT_P03_XDL))
        &&(diagVConfigDataBuf[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST] == 0x1))
    {
        ret = ReadQnxDidDataRequestProcess(Did,OpStatus,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
}

Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    (void)memcpy((uint8 *)Data, (uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(), 300u);
    return RTE_E_OK;
}

Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    uint8 tConfigRsp = 0;
    uint8 fctRet = E_NOT_OK;
    switch(OpStatus)
    {
        case DCM_INITIAL:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(),(uint8 *)Data,sizeof(Dcm_Data300ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_WriteBlock(NULL_PTR);
                Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(Data);
                
                WriteCconfigRequestCounter += 1;
                Rte_Write_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(WriteCconfigRequestCounter);
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;                
            }
            break;
        
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(&nvmStatus);
            Rte_Read_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(&tConfigRsp);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus)&&(TRUE == tConfigRsp))
            {
              if(NVM_REQ_OK != nvmStatus)
              {
                  memset((uint8*)Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock(),0,sizeof(Dcm_Data300ByteType));
                  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                  ret = E_NOT_OK;
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
    return (ret);
}

Std_ReturnType DataServices_Data_E2ESwitch_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    if((0 == Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0])||( 1 == Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0]))
    {
        (void)memcpy((uint8 *)Data, (uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(), 1u);
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

Std_ReturnType DataServices_Data_E2ESwitch_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 mirrorDataBackup;

        switch(OpStatus)
        { 
        case DCM_INITIAL:
            if ((0x00 != Data[0]) && (0x01 != Data[0]))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            else
            {
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus);
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    mirrorDataBackup = Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0];
                    (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(), Data, 1u);
                    if(Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(NULL_PTR) == RTE_E_OK)
                    {
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock()[0] = mirrorDataBackup;
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        ret = E_NOT_OK;
                    }
                }
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(&nvmStatus); 
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK == nvmStatus)
                { 
                    Rte_Write_piSR_E2ESwitchChangeTrigger_Element(Data[0]);
                }
                else
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock(), 0, 1u);
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
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

    return (ret);
}

Std_ReturnType DataServices_Data_Fuel_FuelStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Rte_Call_rpCS_Fuel_Api_ParamentGetCsPort_Operation(Data);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(2, Data);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    uint32 locData;
    uint8 fctRet;
    uint8 ret = RTE_E_OK;
    locData = Data[0];
    locData <<=8;
    locData |= Data[1];
    locData <<=8;
    locData |= Data[2];
    locData <<=8;
    locData |= Data[3];
    
    fctRet = Rte_Call_cpCS_OdoSetParament_Operation(5,&locData);
    if(FALSE == fctRet)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return ret;
}

Std_ReturnType DataServices_Data_Odo_BackupDistanceHistory_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(3, Data);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_Odo_RealisticOdo_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(1, Data);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_Fuel_EnduranceMileage_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Rte_Call_TC_Api_ParamentGetCsPort_Operation(Data);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_SecOcSwitch_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{

    Std_ReturnType ret = RTE_E_OK;
    if((0 == Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0])||(1 == Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0]))
    {
        (void)memcpy((uint8 *)Data, (uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(), 1u);
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

Std_ReturnType DataServices_Data_SecOcSwitch_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;
    uint8 mirrorDataBackup;

    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            if ((0x00 != Data[0]) && (0x01 != Data[0]))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            else
            {
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    mirrorDataBackup = Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0];
                    (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(), Data, 1u);
                    if(Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(NULL_PTR) == E_OK)
                    {
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock()[0] = mirrorDataBackup;
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        ret = DCM_E_NOT_OK;
                    }
                }
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(&nvmStatus);  
            if(NVM_REQ_PENDING != nvmStatus)
            {
                if(NVM_REQ_OK == nvmStatus)
                {   
                    if(Data[0] == 0x01)
                    {
                        SecOC_SetDevelopmentMode(FALSE);
                    }
                    else
                    {
                        SecOC_SetDevelopmentMode(TRUE);
                    }
                }
                else
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock(), 0, 1u);
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = DCM_E_NOT_OK;
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

    return (ret);
}

Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    uint8 i;
    uint8 datalen = 0;
    for(i = 0; i < sizeof(Dcm_Data30ByteType); i++)
    {
        if(Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] != 0xFF)
        {
            *Data = Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i];
            Data++;
        }
        else
        {
            break;
        }
    }
    return (ret);
}

Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadDataLength(uint16 DID, Dcm_OpStatusType OpStatus, uint16 *DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
    uint8 i;
    uint8 datalen = 0;
    for(i = 0; i < sizeof(Dcm_Data30ByteType); i++)
    {
        if(Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] != 0xFF)
        {
            datalen++;
        }
        else
        {
            break;
        }
    }
    *DataLength = datalen;
    return (ret);
}

Std_ReturnType DataServices_Data_VehicleSoftwareVersion_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    uint8 ipcResp;
    uint8 fctRet = E_NOT_OK;
    uint8 i;
    uint8 j;
    if(0xFF != Data[0])
    {
        switch(OpStatus)
        { 
            case DCM_INITIAL:
                fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(&nvmStatus);
                if((NVM_REQ_PENDING != nvmStatus)&&(E_OK == fctRet))
                {
                    for(i = 0;i < sizeof(Dcm_Data30ByteType); i++)
                    {
                        if((i < DataLength)&&(0xFF != Data[i]))
                        {
                            Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[i] = Data[i];
                        }
                        else
                        {
                            for(j = i; j < sizeof(Dcm_Data30ByteType); j++)
                            {
                                Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()[j] = 0xFF;
                            }
                            break;
                        }
                    }
                    (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_WriteBlock(NULL_PTR);
                    ret = DCM_E_PENDING;
                }
                else
                {
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
                break;
            case DCM_PENDING:
            case DCM_FORCE_RCRRP_OK:
                fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(&nvmStatus);
                if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
                {
                    if(NVM_REQ_OK != nvmStatus)
                    {
                        memset((uint8*)Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock(),0xFF,sizeof(Dcm_Data30ByteType));
                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        ret = E_NOT_OK;
                    }
                }
                else
                {
                    ret = DCM_E_PENDING;
                }
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return (ret);
}

Std_ReturnType DataServices_Data_WorkingMode_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    (void)memcpy((uint8 *)Data, (uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(), 1u);
    return RTE_E_OK;
}

Std_ReturnType DataServices_Data_WorkingMode_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    const uint8 *locData = Data;
    uint8 fctRet = E_NOT_OK;

    switch(OpStatus)
    {
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&nvmStatus);    
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(), (uint8*)locData, 1u);
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_WriteBlock(NULL_PTR);
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(&nvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus))
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock(), 0, 1u);
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
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
    return (ret);
}

Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = DCM_E_OK;
    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),sizeof(Dcm_Data200ByteType));
    return (ret);
}

Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType nvmStatus = NVM_REQ_NOT_OK;
    uint8 ipcResp;
    uint8 fctRet = E_NOT_OK;
    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            if((NVM_REQ_PENDING != nvmStatus)&&(E_OK == fctRet))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),(uint8 *)Data,sizeof(Dcm_Data200ByteType));
                (void)Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_WriteBlock(NULL_PTR);
                Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element(Data);
                WriteVconfigRequestCounter += 1;
                Rte_Write_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(WriteVconfigRequestCounter);
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(&nvmStatus);
            Rte_Read_DidDataProcess_VconfigResponseFlag_VconfigResponseFlag(&ipcResp);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != nvmStatus)&&(TRUE == ipcResp))
            {
                if(NVM_REQ_OK != nvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock(),0,sizeof(Dcm_Data200ByteType));
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;
        default:
            ret = E_NOT_OK;
            break;
    
    }
    return (ret);
}

Std_ReturnType DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    s_OdoRteGetParament_t OdoParament;
    Rte_Read_DidDataProcess_rpSR_OdoParament_Element(&OdoParament);

    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 24);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 16);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32 >> 8);
    Data++;
    *Data = (uint8)(OdoParament.FsrvKmValue_s32);
    
    return RTE_E_OK;
}

Std_ReturnType DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType  retVal = E_NOT_OK;
    uint16 dataId = 0xF1D6;
    if(diagVConfigDataBuf[VCONFIG_KIND_HUT_ETHERNET_PORT] == 0x03)
    {
        retVal = ReadQnxDidDataRequestProcess(dataId,OpStatus,ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return retVal;
}

Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    (void)memcpy((uint8 *)Data,(uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(), 17u);
    return RTE_E_OK;
}

Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = RTE_E_OK;
    NvM_RequestResultType vinNvmStatus = NVM_REQ_NOT_OK;
    uint8 fctRet = E_NOT_OK;

    switch(OpStatus)
    { 
        case DCM_INITIAL: 
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(&vinNvmStatus);
            if((NVM_REQ_PENDING != vinNvmStatus)&&(E_OK == fctRet))
            {
                (void)memcpy((uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(), (uint8 *)Data, 17u);
                Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_WriteBlock(NULL_PTR);
                ret  = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                ret = E_NOT_OK;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            fctRet = Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(&vinNvmStatus);
            if((E_OK == fctRet)&&(NVM_REQ_PENDING != vinNvmStatus))
            {
                if(NVM_REQ_OK != vinNvmStatus)
                {
                    memset((uint8*)Rte_Pim_NvBlockNeed_VIN_MirrorBlock(), 0, 17u);
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    ret = E_NOT_OK;
                }
                else
                {
                    
                    Rte_Call_cpCS_OdoSetParament_Operation(9,NULL_PTR);
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
    return (ret);
}

Std_ReturnType DiagReadDataFromVip(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType retVal;
    retVal = ReadVipDidDataReqProcess(DID, OpStatus, Data, DataLength);
    return retVal;
}

Std_ReturnType DiagRvcAvaiableCheck(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    Std_ReturnType ret = E_NOT_OK;
    ConnectorStatus_t connectorStatus;
    connectorStatus = DidGetConnectorStatus();
    if((CONNECTOR_SVC_RVC == connectorStatus) ||(CONNECTOR_RVC == connectorStatus))
    {
        ret = ReadQnxDidDataRequestProcess(DID, OpStatus, ErrorCode);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
}

Std_ReturnType DiagNotAvaiable(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}

Std_ReturnType DiagReadDataNotOk(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength)
{
    return E_NOT_OK;
}
