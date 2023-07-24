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
 * @file:      ComEx_Cbk.h
 * @author:    Nobo
 * @date:      2021-2-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-2-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _COMEX_CBK_H_
#define _COMEX_CBK_H_

#include "ComEx_Type.h"

extern void ComEx_EnableRxTimeout(void);
extern void ComEx_DisableRxTimeout(void);
extern boolean ComEx_TransmitPduCallout(PduIdType PduId, PduInfoType* PduInfoPtr);
extern boolean ComEx_ReceivePduCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void ComEx_TransmitPdu_ComIPdu_userData_Confiratmion(void);
extern void ComEx_TransmitPdu_DMS_FD1_Confiratmion(void);
extern void ComEx_TransmitPdu_DVR_FD1_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT1_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT2_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT3_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT4_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT6_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT7_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT10_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT12_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT13_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT15_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT16_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT17_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT19_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT20_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT21_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT22_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT23_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT25_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT26_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT27_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT28_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT30_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT31_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT32_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT33_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT34_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT35_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT36_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT37_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT38_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT39_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT40_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT41_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT42_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT43_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT45_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT46_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD1_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD2_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD3_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD4_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD5_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_Sync_Req_Confiratmion(void);
extern void ComEx_TransmitPdu_IP1_Confiratmion(void);
extern void ComEx_TransmitPdu_IP2_Confiratmion(void);
extern void ComEx_TransmitPdu_IP3_Confiratmion(void);
extern void ComEx_TransmitPdu_IP4_Confiratmion(void);
extern void ComEx_TransmitPdu_IP7_Confiratmion(void);

#endif /* ifndef _COMEX_CBK_H_ */

