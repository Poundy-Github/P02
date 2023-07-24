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
 * @file:      DcmEx_EolCfg.h
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

#ifndef _DCMEX_EOLCFG_H_
#define _DCMEX_EOLCFG_H_

#include "DcmEx_Cfg.h"

Std_ReturnType EolScreenAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 Length);
Std_ReturnType EolScreenAvaiableReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, Dcm_NegativeResponseCodeType *ErrorCode, uint16 Length);

Std_ReturnType DataServices_Battery_Voltage_Battery_Voltage_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ChipsTemperature_ChipsTemperature_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ClusterHardwareInput_ClusterHardwareInput_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Data_ReadAmpCalibrationValue_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Display_enablingValues_Display_enablingValues_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_ECUSerialNumber_ECUSerialNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ECUSerialNumber_ECUSerialNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_FactoryReset_FactoryReset_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_IPAddress_IP_Address_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_KL15Status_KL15Status_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_MACAddress_MACAddress_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_MICStatus_MICStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_PHYMaster_SlaveMode_Master_Slave_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_Radio_Antenna_Status_RadioAntennaStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ReadGPSSatelliteCount_ReadGPSSatelliteCount_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_ResetInformation_ResetInformation_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_SpeakerStatus_SpeakerStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_SystemSupplierECUSoftwareVersionNumber_ECUSoftwareVersionNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_TBOXMuteValue_Mute_value_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_UIN_UIN_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_VIPBootloaderVersion_VIPBootloaderVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_VIPSoftwareVersion_VIPSoftwareVersion_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_PHYMaster_SlaveMode_Master_Slave_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_WriteRootCA_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DataServices_Data_AndriodReadyStatus_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);




#endif
