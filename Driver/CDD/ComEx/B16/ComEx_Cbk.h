/**
 ********************************************************************************************************************
 * @file:      ComEx_Cbk.h
 * @author:    Noch
 * @date:      2021-2-6 
 * @brief:   
 ********************************************************************************************************************
 * @attention: 
 *    1. date    : 2021-2-6
 *       author  : Noch
 *       reviser : create
 ********************************************************************************************************************
 *  @copyright
 *  COPYRIGHT
 *  -----------------------------------------------------------------------------------------------------------------
 * 
 *  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
 *  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
 * 
 ********************************************************************************************************************
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
extern void ComEx_TransmitPdu_HUT30_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT32_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT33_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT34_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT35_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT39_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT40_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT44_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT45_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT48_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD1_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD2_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD3_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD4_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_FD5_Confiratmion(void);
extern void ComEx_TransmitPdu_HUT_Sync_Req_Confiratmion(void);
extern void ComEx_TransmitPdu_IP1_Confiratmion(void);
extern void ComEx_TransmitPdu_IP2_Confiratmion(void);
extern void ComEx_TransmitPdu_IP3_Confiratmion(void);

#endif /* ifndef _COMEX_CBK_H_ */

