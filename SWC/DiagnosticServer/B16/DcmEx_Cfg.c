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
 * @file:      DcmEx_Cfg.c
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

#include "DcmEx.h"
#include "DcmEx_DiagCfg.h"
#include "DcmEx_EolCfg.h"
#include "DcmEx_DtcCfg.h"
#include "DcmEx_Cfg.h"
#include "DcmEx_Type.h"
#include "EOL_Diag.h"
#include "ComEx_Cfg.h"
#include "ComEx.h"
#include "Dem_Lcfg.h"

#define DCMEX_SS_NONE                       0u, 0u
#define DCMEX_SS_DIAG22                     0u, 1u
#define DCMEX_SS_DIAG2E                     2u, 1u
#define DCMEX_SS_EOL22                      3u, 1u
#define DCMEX_SS_EOL2E                      3u, 1u
#define DCMEX_SS_MIX22                      0u, 2u
#define DCMEX_SS_MIX2E                      2u, 2u

#define DCMEX_DID_CFG_READ_NONE             {DCMEX_SS_NONE, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR}
#define DCMEX_DID_CFG_WRITE_NONE            {DCMEX_SS_NONE, NULL_PTR, NULL_PTR, NULL_PTR}

#define DCMEX_DID_NUMBER                    (240u)
#define DCMEX_DTC_NUMBER                    (207u)
#define DCMEX_SS_NUMBER                     (4u)

extern Std_ReturnType DataServices_SecOCKey_WriteData(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
extern Std_ReturnType DataServices_SecOCVersionNumber_ReadData(uint16 DID, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);

static const DcmEx_SessionSecurityCfgType dcmEx_ssCfgs[DCMEX_SS_NUMBER] =
{
    {3u, 3u},
    {4u, 5u},
    {2u, 2u},
    {4u, 4u}
};

static const DcmEx_DidCfgType dcmEx_didCfgs[DCMEX_DID_NUMBER] = 
{
    /* did   isFlexible length ssStart ssNumber checkAvailable checkCondition checkLength read */
    {
        0xF187u, FALSE, 13u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_ReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_VehicleManufacturerSparePartNumber_SparePartNumber_WriteData}
    },
    {
        0xF18Au, FALSE, 5u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadDataFromVip},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF18Cu, FALSE, 20u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ECUSerialNumber_ECUSerialNumber_ReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_ECUSerialNumber_ECUSerialNumber_WriteData}
    },
    {
        0xF193u, FALSE, 15u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_ReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_SystemSupplierECUHardwareVersionNumber_ECUHardwareVersionNumber_WriteData}
    },
    {
        0xF195u, TRUE, 30u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, DiagReadDataLengthFromQnx, DiagReadFlexibleDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1A2u, FALSE, 19u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadDataFromVip},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1A3u, FALSE, 80u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_AbnormalWakeupSleepRecords_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF190u, FALSE, 17u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_VehicleIdentificationNumber_VIN_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_VehicleIdentificationNumber_VIN_WriteData}
    },
    {
        0xF1B1u, FALSE, 200u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_ReadData},
        {DCMEX_SS_MIX2E, NULL_PTR, NULL_PTR, DataServices_ECUlevelNetworkConfigurationDataIdentifier_NetworkConfigurationDataIdentifier_WriteData}
    },
    {
        0xF189u, FALSE, 15u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1C0u, FALSE, 15u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadDataFromVip},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1C1u, FALSE, 15u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadDataFromVip},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1C5u, FALSE, 20u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_UIN_UIN_ReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xF1C7u, FALSE, 16u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_SecOCKey_WriteData}
    },
    {
        0xF1CBu, TRUE, 4000u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DiagWriteDataToIvi}
    },
    {
        0xF1E5u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1E6u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1E7u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1E8u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1E9u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1ECu, FALSE, 12u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_MACAddress_MACAddress_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1D3u, FALSE, 20u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1D5u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1D6u, FALSE, 28u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DiagWriteDataToQnx}
    },
    {
        0xF1D7u, FALSE, 8u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_PHYMaster_SlaveMode_Master_Slave_ReadData},
        {DCMEX_SS_MIX2E, NULL_PTR, NULL_PTR, DataServices_PHYMaster_SlaveMode_Master_Slave_WriteData}
    },
    {
        0xF1D8u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1B2u, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1B3u, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1B4u, FALSE, 32u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1B5u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1B6u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1C2u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_WorkingMode_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_WorkingMode_WriteData}
    },
    {
        0xF1C8u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_SecOCVersionNumber_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1C9u, TRUE, 2000u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, DiagReadDataLengthFromIvi, DiagReadFlexibleDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1CAu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadFixDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1CCu, FALSE, 40u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DiagReadFixDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xF1ABu, TRUE, 30u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, DataServices_Data_VehicleSoftwareVersion_ReadDataLength, DataServices_Data_VehicleSoftwareVersion_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_VehicleSoftwareVersion_WriteData}
    },
    {
        0xFEFFu, FALSE, 5u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEFEu, FALSE, 11u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEFDu, FALSE, 13u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEFCu, FALSE, 4u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEFBu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF9u, FALSE, 2u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEF8u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF7u, FALSE, 13u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEF6u, FALSE, 4u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_MIX22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xFEF5u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF4u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF3u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF2u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF1u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEF0u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEEFu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, NULL_PTR, NULL_PTR, NULL_PTR, EolMixReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEDBu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEDAu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED9u, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED8u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED7u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED6u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED5u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED4u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED3u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED2u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFED1u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_MIX22, DiagBardAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECFu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagRvcAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECEu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagRvcAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECDu, FALSE, 10u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagAvmAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECCu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagAvmAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECBu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagAvmAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFECAu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagAvmAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEC9u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagAvmAvaiableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFDC7u, FALSE, 4u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_ODO_MaintenanceOdometer_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_ODO_MaintenanceOdometer_WriteData}
    },
    {
        0xFDA2u, FALSE, 39u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_Odo_BackupDistanceHistory_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFDC5u, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_Fuel_FuelStatus_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFDC4u, FALSE, 7u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_Fuel_EnduranceMileage_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFDC3u, FALSE, 5u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_Odo_RealisticOdo_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFDA0u, FALSE, 300u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_DID_0XFDA0_ClusterConfiguration_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_DID_0XFDA0_ClusterConfiguration_WriteData}
    },
    {
        0xFDA7u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_SecOcSwitch_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_SecOcSwitch_WriteData}
    },
    {
        0xFDA8u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_E2ESwitch_ReadData},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_E2ESwitch_WriteData}
    },
    {
        0xB001u, FALSE, 17u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DiagWriteDataToQnx}
    },
    {
        0xB006u, FALSE, 8u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_DIAG22, DiagOffSetAvailableCheck, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DiagWriteDataToQnx}
    },
    {
        0xB007u, FALSE, 8u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DiagWriteDataToQnx}
    },
    {
        0xBE00u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_KL15Status_KL15Status_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE02u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ChipsTemperature_ChipsTemperature_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE10u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Battery_Voltage_Battery_Voltage_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE11u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Battery_Voltage_Battery_Voltage_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE19u, TRUE, 50u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, EolReadDataLengthFromQnx, EolReadFlexibleDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE20u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_VIPSoftwareVersion_VIPSoftwareVersion_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE21u, TRUE, 50u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, EolReadDataLengthFromIvi, EolReadFlexibleDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE22u, TRUE, 50u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, EolReadDataLengthFromQnx, EolReadFlexibleDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE23u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_VIPBootloaderVersion_VIPBootloaderVersion_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE3Au, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_ReadAmpCalibrationValue_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF5Eu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF5Fu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE3Bu, TRUE, 3000u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_Data_WriteRootCA_WriteData}
    },
    {
        0xBE3Cu, FALSE, 32u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE3Eu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE39u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBE3Fu, FALSE, 5u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE5Du, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE32u, FALSE, 49u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ResetInformation_ResetInformation_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE37u, FALSE, 7u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE41u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE42u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE43u, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE45u, FALSE, 33u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE4Fu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE5Fu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE51u, FALSE, 33u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE56u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE58u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE59u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE5Bu, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE61u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE67u, FALSE, 48u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_IPAddress_IP_Address_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE70u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE71u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE72u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE73u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE74u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE75u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE76u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE77u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE78u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE79u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE7Au, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE7Bu, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE7Cu, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE80u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE81u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE82u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE83u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE84u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE85u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEB0u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEB7u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC0u, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC1u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC6u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC7u, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC8u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEC9u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheckToIVI, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBED7u, FALSE, 27u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBED9u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ReadGPSSatelliteCount_ReadGPSSatelliteCount_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEE1u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEE4u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEE9u, FALSE, 20u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEEAu, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEEBu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEECu, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEEDu, FALSE, 32u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEEEu, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEEFu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF60u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF61u, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE60u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEF2u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEF5u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEF8u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEF9u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEFAu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEFBu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBEFFu, FALSE, 20u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF0Fu, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF0Eu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF0Du, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF0Cu, FALSE, 32u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF0Bu, FALSE, 8u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF0Au, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF09u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF08u, FALSE, 9u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF17u, FALSE, 5u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF20u, FALSE, 1u, DCMEX_DID_SUPPORT_READ_WRIRE,
        {DCMEX_SS_EOL22, EolPassThroughAvaiableCheck, NULL_PTR, NULL_PTR, EolPassThroughAvaiableReadData},
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF40u, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Radio_Antenna_Status_RadioAntennaStatus_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF41u, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_MICStatus_MICStatus_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF42u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_SpeakerStatus_SpeakerStatus_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF43u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF4Au, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF4Bu, FALSE, 5u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF53u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF54u, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_ClusterHardwareInput_ClusterHardwareInput_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF56u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_TBOXMuteValue_Mute_value_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF59u, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF5Au, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBF5Du, FALSE, 6u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE01u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_FactoryReset_FactoryReset_WriteData}
    },
    {
        0xBE40u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE46u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE47u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE49u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE4Au, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE4Bu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE4Du, FALSE, 6u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE50u, FALSE, 6u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE52u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE5Au, TRUE, 33u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE5Cu, FALSE, 50u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE7Du, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE90u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE91u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE93u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBE97u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEB3u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEB5u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEB6u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEC2u, FALSE, 4u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEC3u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEC4u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEC5u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBECAu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEE5u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToIvi}
    },
    {
        0xBEE6u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEE7u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEE8u, FALSE, 4u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEF6u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEFCu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEFDu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBEFEu, FALSE, 4u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF07u, FALSE, 3u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF00u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF52u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF55u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_Display_enablingValues_Display_enablingValues_WriteData}
    },
    {
        0xBF57u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF58u, FALSE, 2u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBF5Cu, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, EolWriteDataToQnx}
    },
    {
        0xBE5Eu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, DataServices_Data_AndriodReadyStatus_ReadData},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xBE6Fu, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_EOL22, NULL_PTR, NULL_PTR, NULL_PTR, EolReadDataFromIvi},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBFu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBEu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBDu, FALSE, 13u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBCu, FALSE, 4u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBBu, FALSE, 2u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEBAu, FALSE, 3u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEB9u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEB8u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEB7u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEB6u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
    {
        0xFEB5u, FALSE, 1u, DCMEX_DID_SUPPORT_READ,
        {DCMEX_SS_DIAG22, DiagReadDataCheckFromQnx, NULL_PTR, NULL_PTR, DiagReadDataFromQnx},
        DCMEX_DID_CFG_WRITE_NONE
    },
	{
		0xFDFFu, FALSE, 4u, DCMEX_DID_SUPPORT_WRITE,
		DCMEX_DID_CFG_READ_NONE,
		{DCMEX_SS_DIAG2E, NULL_PTR, NULL_PTR, DataServices_Data_TotalDistanceRewrite_WriteData}
	},
    {
        0xBE12u, FALSE, 1u, DCMEX_DID_SUPPORT_WRITE,
        DCMEX_DID_CFG_READ_NONE,
        {DCMEX_SS_EOL2E, NULL_PTR, NULL_PTR, DataServices_Data_EnterSleep_WriteData}
    }
};

static const DcmEx_DtcCfgType dcmEx_dtcCfgs[DCMEX_DTC_NUMBER]=
{
    {0xD12006u, DemConf_DemEventParameter_FactoryModeNotClosed, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xD10017u, DemConf_DemEventParameter_Over_voltage_Circuit_Voltage_Above_Threshold,  DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xD10116u, DemConf_DemEventParameter_Under_voltage_Circuit_Voltage_Below_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC07388u, DemConf_DemEventParameter_ControlModuleCANBus_off_Bus_off, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A1012u, DemConf_DemEventParameter_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A1011u, DemConf_DemEventParameter_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A1013u, DemConf_DemEventParameter_TUNER_FM1_open_Circuit_Open, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A1019u, DemConf_DemEventParameter_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A1112u, DemConf_DemEventParameter_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x9A1111u, DemConf_DemEventParameter_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x9A1113u, DemConf_DemEventParameter_TUNER_FM2_open_Circuit_Open, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x9A1119u, DemConf_DemEventParameter_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x93F511u, DemConf_DemEventParameter_Mic_1_short_to_GND_Circuit_Short_To_Ground, Dtc_AvaialbleCheckMIC1},
    {0x93F512u, DemConf_DemEventParameter_Mic_1_short_to_BAT_Circuit_Short_To_Battery, Dtc_AvaialbleCheckMIC1},
    {0x93F513u, DemConf_DemEventParameter_Mic_1_open_Circuit_Open, Dtc_AvaialbleCheckMIC1},
    {0x93F611u, DemConf_DemEventParameter_Mic_2_short_to_GND_Circuit_Short_To_Ground, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x93F612u, DemConf_DemEventParameter_Mic_2_short_to_BAT_Circuit_Short_To_Battery, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x93F613u, DemConf_DemEventParameter_Mic_2_open_Circuit_Open, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x9A0101u, DemConf_DemEventParameter_Speaker_FL_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0111u, DemConf_DemEventParameter_Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0112u, DemConf_DemEventParameter_Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0113u, DemConf_DemEventParameter_Speaker_FL_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A011Eu, DemConf_DemEventParameter_Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0125u, DemConf_DemEventParameter_Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0201u, DemConf_DemEventParameter_Speaker_FR_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0211u, DemConf_DemEventParameter_Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0212u, DemConf_DemEventParameter_Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0213u, DemConf_DemEventParameter_Speaker_FR_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A021Eu, DemConf_DemEventParameter_Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0225u, DemConf_DemEventParameter_Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0301u, DemConf_DemEventParameter_Speaker_RL_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0311u, DemConf_DemEventParameter_Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0312u, DemConf_DemEventParameter_Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0313u, DemConf_DemEventParameter_Speaker_RL_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A031Eu, DemConf_DemEventParameter_Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0325u, DemConf_DemEventParameter_Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0401u, DemConf_DemEventParameter_Speaker_RR_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0411u, DemConf_DemEventParameter_Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0412u, DemConf_DemEventParameter_Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0413u, DemConf_DemEventParameter_Speaker_RR_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A041Eu, DemConf_DemEventParameter_Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0425u, DemConf_DemEventParameter_Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0501u, DemConf_DemEventParameter_Speaker_Center_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0511u, DemConf_DemEventParameter_Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0512u, DemConf_DemEventParameter_Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0513u, DemConf_DemEventParameter_Speaker_Center_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A051Eu, DemConf_DemEventParameter_Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0525u, DemConf_DemEventParameter_Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0601u, DemConf_DemEventParameter_Speaker_Woofer_short_across_General_Electrical_Failure, Dtc_AmpAvaiableCheck},
    {0x9A0611u, DemConf_DemEventParameter_Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x9A0612u, DemConf_DemEventParameter_Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x9A0613u, DemConf_DemEventParameter_Speaker_Woofer_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A061Eu, DemConf_DemEventParameter_Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Dtc_AmpAvaiableCheck},
    {0x9A0625u, DemConf_DemEventParameter_Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Dtc_AmpAvaiableCheck},
    {0x95F811u, DemConf_DemEventParameter_A2B_short_to_ground_Circuit_Short_To_Ground, Dtc_AmpAvaiableCheck},
    {0x95F812u, DemConf_DemEventParameter_A2B_short_to_battery_Circuit_Short_To_Battery, Dtc_AmpAvaiableCheck},
    {0x95F813u, DemConf_DemEventParameter_A2B_open_Circuit_Open, Dtc_AmpAvaiableCheck},
    {0x9A0701u, DemConf_DemEventParameter_Speaker_AVAS_ShortAcross, Dtc_AmpAvaiableCheck},
    {0x9A0711u, DemConf_DemEventParameter_Speaker_AVAS_ShortToGround, Dtc_AmpAvaiableCheck},
    {0x9A0712u, DemConf_DemEventParameter_Speaker_AVAS_ShortToBattery, Dtc_AmpAvaiableCheck},
    {0x9A0713u, DemConf_DemEventParameter_Speaker_AVAS_CircuitOpen, Dtc_AmpAvaiableCheck},
    {0x9A071Eu, DemConf_DemEventParameter_Speaker_AVAS_ResistanceOutOfRange, Dtc_AmpAvaiableCheck},
    {0x9A0725u, DemConf_DemEventParameter_Speaker_AVAS_WaveformLackFidelity, Dtc_AmpAvaiableCheck},
    {0xE00083u, DemConf_DemEventParameter_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xE00487u, DemConf_DemEventParameter_Lost_TCP_communication_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xE00208u, DemConf_DemEventParameter_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xE00784u, DemConf_DemEventParameter_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xE00C12u, DemConf_DemEventParameter_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xE01113u, DemConf_DemEventParameter_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA13011u, DemConf_DemEventParameter_Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Dtc_AvaialbleCheck0xA13011},
    {0x927312u, DemConf_DemEventParameter_Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Dtc_AvaialbleCheck0x927312},
    {0xA13111u, DemConf_DemEventParameter_Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, Dtc_AvaialbleCheck0xA13111},
    {0x927412u, DemConf_DemEventParameter_Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Dtc_AvaialbleCheck0x927412},
    {0x9A0813u, DemConf_DemEventParameter_GPS_AntennaOpen, Dtc_AvaialbleCheck0x9A0813},
    {0x9A0811u, DemConf_DemEventParameter_GPS_AntennaShortToGround, Dtc_AvaialbleCheck0x9A0811},
    {0x9A0812u, DemConf_DemEventParameter_GPS_AntennaShortToBattery, Dtc_AvaialbleCheck0x9A0812},
    {0x9A0819u, DemConf_DemEventParameter_GPS_OverCurrent, Dtc_AvaialbleCheck0x9A0819},
    {0x92764Bu, DemConf_DemEventParameter_INVALID_SHORTNAME_Over_Temperature_Over_Temperature, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x908E87u, DemConf_DemEventParameter_Lost_communication_with_IVI_Display_Front_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x908D87u, DemConf_DemEventParameter_Lost_communication_with_IP_Display_Front_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0x908B87u, DemConf_DemEventParameter_Lost_communication_with_W_HUD_Missing_Message, Dtc_AvaialbleCheck0x908B87},
    {0x908887u, DemConf_DemEventParameter_Lost_communication_with_ConsoleDisplay, Dtc_AvaialbleCheck0x908887},
    {0x908787u, DemConf_DemEventParameter_Lost_communication_with_PassengerDisplay, Dtc_CDDAvaialbleCheck},
    {0x908A87u, DemConf_DemEventParameter_Lost_communication_with_AVM_Missing_Message, Dtc_AvaialbleCheck0x908A87},
    {0x908687u, DemConf_DemEventParameter_Lost_communication_with_DMS, Dtc_AvaialbleCheck0x908687},
    {0x908587u, DemConf_DemEventParameter_Lost_communication_with_DVR, Dtc_AvaialbleCheck0x908587},
    {0x908487u, DemConf_DemEventParameter_Lost_communication_with_InCarCamera, Dtc_AvaialbleCheck0x908487},
    {0xC10087u, DemConf_DemEventParameter_Missing_Engine_Control_Module_Missing_Message, Dtc_AvaialbleCheck0xC10087},
    {0xC12287u, DemConf_DemEventParameter_Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Dtc_AvaialbleCheck0xC12287},
    {0xC10187u, DemConf_DemEventParameter_Missing_Transmission_Control_Until_PTCAN_Missing_Message, Dtc_AvaialbleCheck0xC10187},
    {0xC15187u, DemConf_DemEventParameter_Missing_Airbag_Module_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC24187u, DemConf_DemEventParameter_Missing_Controler_Headlamp_Missing_Message, Dtc_AvaialbleCheck0xC24187},
    {0xC24287u, DemConf_DemEventParameter_Missing_Right_Headlamp_Control_Module, Dtc_AvaialbleCheck0xC24287},
    {0xD10B87u, DemConf_DemEventParameter_Missing_PrePretensioner_Mechatronic_Integrated, Dtc_AvaialbleCheck0xD10B87},
    {0xD02687u, DemConf_DemEventParameter_Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Dtc_AvaialbleCheck0xD02687},
    {0xC14087u, DemConf_DemEventParameter_Missing_Elec_Region_Control_System_Body_Missing_Message, Dtc_AvaialbleCheck0xC14087},
    {0xC16487u, DemConf_DemEventParameter_Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Dtc_AvaialbleCheck0xC16487},
    {0xC14687u, DemConf_DemEventParameter_Missing_Gateway_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC13187u, DemConf_DemEventParameter_Missing_Electric_Power_Steering_system_Missing_Message, Dtc_AvaialbleCheck0xC13187},
    {0xC12887u, DemConf_DemEventParameter_Missing_Electric_Park_Brake_controller, Dtc_AvaialbleCheck0xC12887},
    {0xC20887u, DemConf_DemEventParameter_Missing_Driver_Seat_Memory_module, Dtc_AvaialbleCheck0xC20887},
    {0xC19987u, DemConf_DemEventParameter_Missing_Driver_Door_Control_Module_Missing_Message, Dtc_AvaialbleCheck0xC19987},
    {0xC20087u, DemConf_DemEventParameter_missing_Passenger_Door_Control_Module_Missing_Message, Dtc_AvaialbleCheck0xC20087},
    {0xC24687u, DemConf_DemEventParameter_Missing_Seat_Control_Module, Dtc_AvaialbleCheck0xC24687},
    {0xC24787u, DemConf_DemEventParameter_Missing_Rear_Heat_Vent_Seat_Module, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xC24387u, DemConf_DemEventParameter_missing_Parking_Assistance_System_Missing_Message, Dtc_AvaialbleCheck0xC24387},
    {0xC2B387u, DemConf_DemEventParameter_missing_Driver_Monitoring_System_Missing_Message, Dtc_AvaialbleCheck0xC2B387},
    {0xC19887u, DemConf_DemEventParameter_missing_Telematics_control_Box_Missing_Message, Dtc_AvaialbleCheck0xC19887},
    {0xC12787u, DemConf_DemEventParameter_missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Dtc_AvaialbleCheck0xC12787},
    {0xC29387u, DemConf_DemEventParameter_Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Dtc_AvaialbleCheck0xC29387},
    {0xC11187u, DemConf_DemEventParameter_MissingBattery_Management_System, Dtc_AvaialbleCheck0xC11187},
    {0xC1BB87u, DemConf_DemEventParameter_Missing_Onboard_charger, Dtc_AvaialbleCheck0xC1BB87},
    {0xD10887u, DemConf_DemEventParameter_Missing_Front_Power_Box_Missing_Message, Dtc_AvaialbleCheck0xD10887},
    {0xD10987u, DemConf_DemEventParameter_Missing_Rear_Power_Box_Missing_Message, Dtc_AvaialbleCheck0xD10987},
    {0xD00487u, DemConf_DemEventParameter_Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Dtc_AvaialbleCheck0xD00487},
    {0xC10487u, DemConf_DemEventParameter_missing_Adaptive_Cruise_Control_system_Radar_Control_Module, Dtc_AvaialbleCheck0xC10487},
    {0xC14387u, DemConf_DemEventParameter_missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, Dtc_AvaialbleCheck0xC14387},
    {0xD00987u, DemConf_DemEventParameter_Missing_Controller_Pedal_Missing_Message, Dtc_AvaialbleCheck0xD00987},
    {0xC23087u, DemConf_DemEventParameter_Missing_Power_Lift_Gate_module, Dtc_AvaialbleCheck0xC23087},
    {0xC15C87u, DemConf_DemEventParameter_Missing_Intelligent_Driving_Controller_Level2, Dtc_AvaialbleCheck0xC15C87},
    {0xC11587u, DemConf_DemEventParameter_Missing_Electronic_Gerodisc_Missing_Message, Dtc_AvaialbleCheck0xC11587},
    {0xD01587u, DemConf_DemEventParameter_Missing_Screen_touch_button_switch_controller_Missing_Message, Dtc_AvaialbleCheck0xD01587},
    {0xC14187u, DemConf_DemEventParameter_missing_Trailer_Missing_Message, Dtc_AvaialbleCheck0xC14187},
    {0xD02987u, DemConf_DemEventParameter_Missing_Wireless_Power_Charger_Missing_Message, Dtc_AvaialbleCheck0xD02987},
    {0xC11487u, DemConf_DemEventParameter_Missing_Nextrac_Torque_On_Demand_Missing_Message, Dtc_AvaialbleCheck0xC11487},
    {0xC15887u, DemConf_DemEventParameter_Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Dtc_AvaialbleCheck0xC15887},
    {0xC23387u, DemConf_DemEventParameter_missing_Right_Rear_Side_Detection_System_Missing_Message, Dtc_AvaialbleCheck0xC23387},
    {0xC2B587u, DemConf_DemEventParameter_missing_Right_Corner_Radar, Dtc_AvaialbleCheck0xC2B587},
    {0xD10687u, DemConf_DemEventParameter_Missing_Combination_Switch_Assembly_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC25E87u, DemConf_DemEventParameter_Missing_Ibooster, Dtc_AvaialbleCheck0xC25E87},
    {0xA10017u, DemConf_DemEventParameter_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10116u, DemConf_DemEventParameter_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10049u, DemConf_DemEventParameter_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10149u, DemConf_DemEventParameter_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10249u, DemConf_DemEventParameter_IP_Display_ASIC_failure_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10349u, DemConf_DemEventParameter_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Dtc_AvaialbleCheck0xA10349},
    {0xA10408u, DemConf_DemEventParameter_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20017u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20116u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20008u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20149u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20249u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20349u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20449u, DemConf_DemEventParameter_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA30017u, DemConf_DemEventParameter_HVAC_Display_OverVoltage, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30116u, DemConf_DemEventParameter_HVAC_Display_LowVoltage, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30008u, DemConf_DemEventParameter_HVAC_Display_NotReceiveBacklightValue, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30149u, DemConf_DemEventParameter_HVAC_Display_BacklightModuleError, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30249u, DemConf_DemEventParameter_HVAC_Display_TFT_Failure, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30349u, DemConf_DemEventParameter_HVAC_Display_VideoSignalConnectFailure, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30449u, DemConf_DemEventParameter_HVAC_Display_TouchPanelFailure, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30549u, DemConf_DemEventParameter_HVAC_Display_VibratorFailure, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA30649u, DemConf_DemEventParameter_HVAC_Display_ForceInductionFailure, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xD00A46u, DemConf_DemEventParameter_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xD00E40u, DemConf_DemEventParameter_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xD00F94u, DemConf_DemEventParameter_SecOC_software_module_running_error_Unexpected_Operation, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xD01046u, DemConf_DemEventParameter_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xEA0040u, DemConf_DemEventParameter_SecOC_TBoxSecOcFailure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xEA0240u, DemConf_DemEventParameter_SecOC_GWSecOcFailure, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10093u, DemConf_DemEventParameter_Read_ClusterScreenIDFailed, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA10157u, DemConf_DemEventParameter_ScreenClusterDriverErr, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20093u, DemConf_DemEventParameter_Read_IVIScreen_IDFailed, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA20157u, DemConf_DemEventParameter_ScreenIVIDriverErr, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA30093u, DemConf_DemEventParameter_Read_CPScreen_IDFailed, Dtc_AvaialbleCheck0xA30093},
    {0xA30157u, DemConf_DemEventParameter_ScreenCPDriverErr, Dtc_AvaialbleCheck0xA30157},
    {0xA40093u, DemConf_DemEventParameter_Read_CoDriverScreenIDFailed, Dtc_CDDAvaialbleCheck},
    {0xA40157u, DemConf_DemEventParameter_ScreenCoDriverErr, Dtc_CDDAvaialbleCheck},
    // {0xA50093u, DemConf_DemEventParameter_Read_HUDScreen_IDFailed, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0xA50157u, DemConf_DemEventParameter_ScreenHUDDriverErr, Dtc_AvaialbleCheck0xA50157},
    {0x910011u, DemConf_DemEventParameter_RVC_CameraShortToGround, Dtc_AvaialbleCheck0x910011},
    {0x910012u, DemConf_DemEventParameter_RVC_CamerShortToBattery, Dtc_AvaialbleCheck0x910012},
    {0x910013u, DemConf_DemEventParameter_RVC_CameraOpenCircuit, Dtc_AvaialbleCheck0x910013},
    {0x910087u, DemConf_DemEventParameter_Lost_communication_with_RVC_Missing_Message, Dtc_AvaialbleCheck0x910087},
    {0x910111u, DemConf_DemEventParameter_AVM_CamerShortToGround, Dtc_AvaialbleCheck0x910111},
    {0x910112u, DemConf_DemEventParameter_AVM_CamerShortToBattery, Dtc_AvaialbleCheck0x910112},
    {0x910113u, DemConf_DemEventParameter_AVM_CamerOpenCircuit, Dtc_AvaialbleCheck0x910113},
    {0x910187u, DemConf_DemEventParameter_LostComWithAVMFrontCamera, Dtc_AvaialbleCheck0x910187},
    {0x910287u, DemConf_DemEventParameter_LostComWithAVMRearCamera, Dtc_AvaialbleCheck0x910287},
    {0x910387u, DemConf_DemEventParameter_LostComWithAVMLeftCamera, Dtc_AvaialbleCheck0x910387},
    {0x910487u, DemConf_DemEventParameter_LostComWithAVMRightCamera, Dtc_AvaialbleCheck0x910487},
    {0x910811u, DemConf_DemEventParameter_SVC_CameraShortToGround, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x910812u, DemConf_DemEventParameter_SVC_CamerShortToBattery, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x910813u, DemConf_DemEventParameter_SVC_CameraOpenCircuit, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x910887u, DemConf_DemEventParameter_Lost_communication_with_SVC_Missing_Message, DcmEx_DtcAvaiableCheckAlwaysFalse},
    {0x910511u, DemConf_DemEventParameter_Internal_DMS_CameraShortToGround, Dtc_AvaialbleCheck0x910511},
    {0x910512u, DemConf_DemEventParameter_Internal_DMS_CameraShortToBattery, Dtc_AvaialbleCheck0x910512},
    {0x910513u, DemConf_DemEventParameter_Internal_DMS_CameraCircuitOpen, Dtc_AvaialbleCheck0x910513},
    {0x910611u, DemConf_DemEventParameter_Internal_DVR_CameraShortToGround, Dtc_AvaialbleCheck0x910611},
    {0x910612u, DemConf_DemEventParameter_Internal_DVR_CameraShortToBattery, Dtc_AvaialbleCheck0x910612},
    {0x910613u, DemConf_DemEventParameter_Internal_DVR_CameraCircuitOpen, Dtc_AvaialbleCheck0x910613},
    {0x910711u, DemConf_DemEventParameter_Internal_OMS_CameraShortToGround, Dtc_AvaialbleCheck0x910711},
    {0x910712u, DemConf_DemEventParameter_Internal_OMS_CameraShortToBattery, Dtc_AvaialbleCheck0x910712},
    {0x910713u, DemConf_DemEventParameter_Internal_OMS_CameraCircuitOpen, Dtc_AvaialbleCheck0x910713},
    {0x927649u, DemConf_DemEventParameter_Temperature_SensorError, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xA50116u, DemConf_DemEventParameter_Co_Driver_Display_Low_voltage, Dtc_CDDAvaialbleCheck},
    {0xA50017u, DemConf_DemEventParameter_Co_Driver_Display_Over_voltage, Dtc_CDDAvaialbleCheck},
    {0xA50249u, DemConf_DemEventParameter_Co_Driver_Display_TFT_failure, Dtc_CDDAvaialbleCheck},
    {0xA50449u, DemConf_DemEventParameter_Co_Driver_Display_Touch_Panel_failure, Dtc_CDDAvaialbleCheck},
    {0xA50149u, DemConf_DemEventParameter_Co_Driver_Display_backlight_module_status, Dtc_CDDAvaialbleCheck},
    {0xA50008u, DemConf_DemEventParameter_Co_Driver_Display_not_received_backlight_value, Dtc_CDDAvaialbleCheck},
    {0xA50349u, DemConf_DemEventParameter_Co_Driver_Display_video_signal_connect_failure, Dtc_CDDAvaialbleCheck},
    {0xD12387u, DemConf_DemEventParameter_Lost_Communication_With_Depth_Of_Water_Detection_Module, Dtc_AvaialbleCheck0xD12387},
    {0xC15C40u, DemConf_DemEventParameter_SecOC_Security_PDU_Verification_Failed_from_IDC_L2, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC14340u, DemConf_DemEventParameter_SecOC_Security_PDU_Verification_Failed_from_IDC_IFC, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC15D40u, DemConf_DemEventParameter_SecOC_Security_PDU_Verification_Failed_from_IDC_L3, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC10140u, DemConf_DemEventParameter_SecOC_Security_PDU_Verification_Failed_from_IDC_TCU, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xC41640u, DemConf_DemEventParameter_SecOC_Security_PDU_Verification_Failed_from_IDC_ESP, DcmEx_DtcAvaiableCheckAlwaysTrue},
    {0xF01200u, DemConf_DemEventParameter_AbnormalWakeupSleep, DcmEx_DtcAvaiableCheckAlwaysTrue}
};

DcmEx_DtcType dcmEx_dtcs[DCMEX_DTC_NUMBER];

DcmEx_CfgType dcmEx_cfg =
{
    DCMEX_DID_NUMBER,
    dcmEx_didCfgs,
    DCMEX_SS_NUMBER,
    dcmEx_ssCfgs,
    DCMEX_DTC_NUMBER,
    dcmEx_dtcCfgs,
    dcmEx_dtcs,
};

DcmEx_Type dcmEx_data;
