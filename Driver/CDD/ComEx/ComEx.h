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
 * @file:      ComEx.h
 * @author:    Nobo
 * @date:      2021-1-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-1-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _COMEX_H_
#define _COMEX_H_

#include "ComEx_Cfg.h"
#include "ComEx_Type.h"

extern void ComEx_TxConfiratmion(ComEx_IpduGroupIdType PduId);
extern boolean ComEx_TransmitPduProcessing(ComEx_IpduGroupIdType PduId, PduInfoType* PduInfoPtr);
extern boolean ComEx_ReceivePduProcessing(ComEx_IpduGroupIdType PduId, const PduInfoType* PduInfoPtr);
extern uint8 ComEx_ReadSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata);
extern Std_ReturnType ComEx_WriteSigGroupE2eData(ComEx_SignalGroupIdType SignalGroupId, ComEx_E2ETYPE* E2epdata);
extern Std_ReturnType ComEx_SendSignalBuffer(ComEx_SignalIdType SignalId, const void * SignalDataPtr, uint8 Length);

extern uint8 ComEx_SignalGetSendStatus(uint16 signalId);

#endif /* ifndef _COMEX_H_.2021-1-26 13:25:05 GW00191223 */

