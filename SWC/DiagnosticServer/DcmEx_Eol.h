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
 * @file:      DcmEx_Eol.h
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

#ifndef _DCMEX_EOL_H_
#define _DCMEX_EOL_H_

#include "DcmEx_Switch.h"

#if (DIAG_USE_DCMEX == TRUE)

#include "RTE_Type.h"
#include "EOL_Diag.h"

#define EOL_MUTIPACKAGESENDMAXDATANUMBER             ((uint16)4000u)

typedef struct MutiPackageSendDataInfo_Tag
{
    uint8  sendData[50];
    uint16 totalSendLength;
    uint16 totalSendCnt;
    uint16 currentSendCnt;
    uint16 CRCCalValue;
    uint16 initCRCValue;
    uint8  lastPackageFlag;
} MutiPackageSendDataInfo;

typedef MutiPackageSendDataInfo * (*MutiPackageSendFuncPtr_Pre)(void);
typedef void (*MutiPackageSendFuncPtr_Post)(void);
typedef void (*MutiPackageSendFuncPtr_Send)(void);
typedef void (*MutiPackageSendFuncPtr_Receive)(uint8 Major_msg_id, uint8 Sub_msg_id, uint8 *param, uint16 param_len);
typedef struct MutiPackageSendInfo_Tag
{
    uint8 sendData[EOL_MUTIPACKAGESENDMAXDATANUMBER];
    uint16 sendDid;
    MutiPackageSendFuncPtr_Pre mutiPackageSendPreFunc;
    MutiPackageSendFuncPtr_Post mutiPackageSendPostFunc;
    MutiPackageSendFuncPtr_Send mutiPackageSendFunc;
    MutiPackageSendFuncPtr_Receive mutiPackageReceiveFunc;
    SPI_MutiPackageHandleStatusType sendStatus;
    boolean IPCSendStatus;
} MutiPackageSendInfo;

extern MutiPackageSendInfo MutiPackageSend;

Std_ReturnType EolWriteDataToIvi(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType EolWriteDataToQnx(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType EolReadDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType EolReadDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType EolReadFlexibleDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType EolReadDataLengthFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType EolReadFlexibleDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType EolReadDataLengthFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType EolMixReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 Length);
Std_ReturnType EolPassThroughAvaiableCheck(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType EolPassThroughAvaiableCheckToIVI(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType EolPassThroughAvaiableReadData(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);

void EOL_MutiPackageSendHandler(void);
void EOL_MutiPackageSendFunc(void);
void EOL_SetMutiPackageStatus(uint8 status);
void EOL_MutiPackageSendDataInfoFunc(uint16 DataLength, uint16 crcResult);

#endif // (DIAG_USE_DCMEX == TRUE)

#endif
