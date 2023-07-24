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
 * @file:      DcmEx_DiagCfg.h
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

#ifndef _DCMEX_DIAGCFG_H_
#define _DCMEX_DIAGCFG_H_

#include "DcmEx_Cfg.h"

typedef enum ConnectorStatus{
    CONNECTOR_INVAILD  = 0u,/* not External */
    CONNECTOR_EX_AVM,    /* External avm */
    CONNECTOR_IN_AVM,    /* internal avm */
    CONNECTOR_SVC_RVC,  /* SVC and RVC */
    CONNECTOR_SVC,      /* SVC */
    CONNECTOR_RVC       /* RVC */
} ConnectorStatus_t;

Std_ReturnType ReadVipDidDataReqProcess(uint16 DID, uint8 OpStatus, uint8 *Data, uint16 Length);
ConnectorStatus_t DidGetConnectorStatus(void);
Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_DID_0XFDA0_ClusterConfiguration_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_E2ESwitch_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_E2ESwitch_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_Fuel_EnduranceMileage_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_Fuel_FuelStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_ODO_MaintenanceOdometer_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_Odo_BackupDistanceHistory_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_Odo_RealisticOdo_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_SecOcSwitch_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_SecOcSwitch_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_VehicleSoftwareVersion_ReadDataLength(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType DataServices_Data_VehicleSoftwareVersion_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_WorkingMode_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_WorkingMode_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_MaintenanceOdometer_Maintenance_odometer_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_SwitchARLTable_SwitchARLTable_ConditionCheckRead(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_VehicleIdentificationNumber_VIN_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_TotalDistanceRewrite_WriteData(uint16 DID,const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode,uint16 DataLength);
Std_ReturnType DataServices_AbnormalWakeupSleepRecords_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);

Std_ReturnType DiagAvmAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagReadDataFromVip(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DiagRvcAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagNotAvaiable(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagBardAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagOffSetAvailableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagA2BMICAvailableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);

#endif
