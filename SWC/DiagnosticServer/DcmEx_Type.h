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
 * @file:      DcmEx_Type.h
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

#ifndef _DCMEX_TYPE_H_
#define _DCMEX_TYPE_H_

#include "DcmEx_Switch.h"

#if (DIAG_USE_DCMEX == TRUE)

#include "Std_Types.h"
#include "ComStack_Types.h"

typedef struct
{
    uint8 sessionMap;
    uint8 securityMap;
} DcmEx_SessionSecurityCfgType;

typedef Std_ReturnType (*DcmEx_CheckAvailableHandlerType)(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
typedef Std_ReturnType (*DcmEx_CheckConditionHandlerType)(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
typedef Std_ReturnType (*DcmEx_CheckLengthHandlerType)(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
typedef Std_ReturnType (*DcmEx_ReadDataHandlerType)(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);

typedef struct 
{
    uint8 ssStart;
    uint8 ssNumber;
    DcmEx_CheckAvailableHandlerType checkAvailable;
    DcmEx_CheckConditionHandlerType checkCondition;
    DcmEx_CheckLengthHandlerType checkLength;
    DcmEx_ReadDataHandlerType read;
} DcmEx_DidReadCfgType;

typedef Std_ReturnType (*DcmEx_WriteDataHandlerType)(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);

typedef struct
{
    uint8 ssStart;
    uint8 ssNumber;
    DcmEx_CheckAvailableHandlerType checkAvailable;
    DcmEx_CheckConditionHandlerType checkCondition;
    DcmEx_WriteDataHandlerType write;
} DcmEx_DidWriteCfgType;

#define DCMEX_DID_SUPPORT_NONE          (0u)
#define DCMEX_DID_SUPPORT_READ          (1u)
#define DCMEX_DID_SUPPORT_WRITE         (2u)
#define DCMEX_DID_SUPPORT_READ_WRIRE    (3u)
typedef struct
{
    uint16 did;
    boolean isFlexible;
    uint16 length;
    uint8 supportType;
    DcmEx_DidReadCfgType readCfg;
    DcmEx_DidWriteCfgType writeCfg;
} DcmEx_DidCfgType;

typedef boolean (*DcmEx_DtcAvaiableHandlerType)(uint32 dtc);
typedef struct
{
    uint32 dtc;
    uint16 dtcId;
    DcmEx_DtcAvaiableHandlerType avaiable;
} DcmEx_DtcCfgType;

typedef struct
{
    boolean avaiableExpect;
    boolean avaiableActual;
} DcmEx_DtcType;

typedef struct
{
    uint16 didNumber;
    const DcmEx_DidCfgType *didCfgs;
    uint8 ssNumber;
    const DcmEx_SessionSecurityCfgType *ssCfgs;
    uint16 dtcNumber;
    const DcmEx_DtcCfgType *dtcCfgs;
    DcmEx_DtcType *dtcs;
} DcmEx_CfgType;

typedef struct
{
    boolean isRead;
    uint16 didCurrent;
    uint16 indexCurrent;
    uint8 sidCurrent;
    Dcm_NegativeResponseCodeType error;
    uint8 state;
    uint16 lengthCurrent;
    Dcm_OpStatusType opStatus;
} DcmEx_DidType;

typedef struct
{
    DcmEx_DidType did;
} DcmEx_Type;

#endif // (DIAG_USE_DCMEX == TRUE)

#endif
