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
 * @file:      DcmEx_Diag.h
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

#ifndef _DCMEX_DIAG_H_
#define _DCMEX_DIAG_H_

#include "DcmEx_Switch.h"

#if (DIAG_USE_DCMEX == TRUE)

#include "RTE_Type.h"
#include "IPC_Diagnose.h"

#if (defined GWM_V35_PROJECT_TYPE_EC24) || (defined GWM_V35_PROJECT_TYPE_D01) || (defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) || \
    (defined GWM_V35_PROJECT_TYPE_ES24) || (defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_B16) || (defined GWM_V35_PROJECT_TYPE_P01) || (defined GWM_V35_PROJECT_TYPE_P09)
    #define CLUSTER_OFFSET_ADJUSTMENT_ENABLE TRUE
#else 
    #define CLUSTER_OFFSET_ADJUSTMENT_ENABLE FALSE
#endif


extern IPC_M2S_DiagnoseQNXRoutineControlRequest_t routineCtrlRequest;

void DiagInit(void);
Std_ReturnType DiagWriteDataToIvi(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagWriteDataToQnx(uint16 Did, const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 DataLength);
Std_ReturnType DiagReadFixDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DiagReadFlexibleDataFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);
Std_ReturnType DiagReadDataLengthFromIvi(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType DiagReadDataCheckFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, uint16 Length);
Std_ReturnType DiagReadDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 Length);
Std_ReturnType ReadIVIDidDataFixLengthProcess(uint16 DataId,uint8 OpStatus,uint8 *Data,uint16 Length);
Std_ReturnType WriteQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus, const uint8 *Data,uint16 dataLen,uint8* ErrorCode);
Std_ReturnType CopyQnxDidRspData(uint16 DataId,uint8 *Data,uint16 Length);
Std_ReturnType ReadQnxDidDataRequestProcess(uint16 DataId,uint8 OpStatus,uint8* ErrorCode);
#if (CLUSTER_OFFSET_ADJUSTMENT_ENABLE == TRUE)
Std_ReturnType ReadQnxDidDataRequestProcessAndSave(uint16 DataId,uint8 OpStatus,uint8* ErrorCode);
#endif
void IPC_Call_Diagnose_ReceiveData(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen);

void RequestQnxRoutineControl(uint16 RoutineId, uint8 Type, const uint8* Option, uint8 OptionLen);
Std_ReturnType QnxResponseRoutineControl(uint8* Status, uint8 StatusLen, uint8* ErrorCode);
Std_ReturnType SocRspTimeOutHandle(uint8 OpStatus);
Std_ReturnType DiagReadDataLengthFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType DiagReadFlexibleDataFromQnx(uint16 Did, Dcm_OpStatusType OpStatus, uint8 *Data, uint16 DataLength);



#endif // (DIAG_USE_DCMEX == TRUE)

#endif
