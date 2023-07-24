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
 * @file:      DcmEx.h
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

#ifndef _DCMEX_H_
#define _DCMEX_H_

#include "DcmEx_Switch.h"

#if (DIAG_USE_DCMEX == TRUE)

#include "RTE_Type.h"
#include "DcmEx_Diag.h"
#include "DcmEx_Eol.h"

#define DCMEX_SESSION_OTHER                 (0u)
#define DCMEX_SESSION_DEFAULT               (1u)
#define DCMEX_SESSION_EXTEND                (2u)
#define DCMEX_SESSION_EOL                   (4u)
#define DCMEX_SESSION_EOL_PROGRAMMING       (8u)

#define DCMEX_SECURITY_OTHER                (0u)
#define DCMEX_SECURITY_NONE                 (1u)
#define DCMEX_SECURITY_L1                   (2u)
#define DCMEX_SECURITY_EOL                  (4u)

Std_ReturnType DcmEx_IsAvailableDid(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported);
Std_ReturnType DcmEx_DidRead(uint16 DID, uint8 *Data, Dcm_OpStatusType OpStatus, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType DcmEx_DidWrite(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode);
void DcmEx_SetCurrentSid(uint8 sid);

boolean DcmEx_DtcAvaiableCheckAlwaysTrue(uint32 dtc);
boolean DcmEx_DtcAvaiableCheckAlwaysFalse(uint32 dtc);

void DcmEx_DtcRetryAvailable(void);
void DcmEx_AvailableCheck(void);

#endif // (DIAG_USE_DCMEX == TRUE)

#endif

