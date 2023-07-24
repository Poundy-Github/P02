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
 * @file:      ComEx_Callout.c
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

 #include "ComEx.h"

boolean ComEx_ReceivePduCallout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    boolean ret = TRUE;

    ret = ComEx_ReceivePduProcessing(PduId, PduInfoPtr);

    return ret;
}

boolean ComEx_TransmitPduCallout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    boolean ret = TRUE;
    
    ret = ComEx_TransmitPduProcessing(PduId, PduInfoPtr);

    return ret;
}

void ComEx_TransmitPdu_ComIPdu_userData_Confiratmion(void)
{
    ComEx_TxConfiratmion(0u);
}

void ComEx_TransmitPdu_DMS_FD1_Confiratmion(void)
{
    ComEx_TxConfiratmion(1u);
}

void ComEx_TransmitPdu_DVR_FD1_Confiratmion(void)
{
    ComEx_TxConfiratmion(2u);
}

void ComEx_TransmitPdu_HUT1_Confiratmion(void)
{
    ComEx_TxConfiratmion(3u);
}

void ComEx_TransmitPdu_HUT2_Confiratmion(void)
{
    ComEx_TxConfiratmion(4u);
}

void ComEx_TransmitPdu_HUT3_Confiratmion(void)
{
    ComEx_TxConfiratmion(5u);
}

void ComEx_TransmitPdu_HUT4_Confiratmion(void)
{
    ComEx_TxConfiratmion(6u);
}

void ComEx_TransmitPdu_HUT7_Confiratmion(void)
{
    ComEx_TxConfiratmion(7u);
}

void ComEx_TransmitPdu_HUT10_Confiratmion(void)
{
    ComEx_TxConfiratmion(8u);
}

void ComEx_TransmitPdu_HUT12_Confiratmion(void)
{
    ComEx_TxConfiratmion(9u);
}

void ComEx_TransmitPdu_HUT13_Confiratmion(void)
{
    ComEx_TxConfiratmion(10u);
}

void ComEx_TransmitPdu_HUT15_Confiratmion(void)
{
    ComEx_TxConfiratmion(11u);
}

void ComEx_TransmitPdu_HUT16_Confiratmion(void)
{
    ComEx_TxConfiratmion(12u);
}

void ComEx_TransmitPdu_HUT17_Confiratmion(void)
{
    ComEx_TxConfiratmion(13u);
}

void ComEx_TransmitPdu_HUT19_Confiratmion(void)
{
    ComEx_TxConfiratmion(14u);
}

void ComEx_TransmitPdu_HUT20_Confiratmion(void)
{
    ComEx_TxConfiratmion(15u);
}

void ComEx_TransmitPdu_HUT21_Confiratmion(void)
{
    ComEx_TxConfiratmion(16u);
}

void ComEx_TransmitPdu_HUT22_Confiratmion(void)
{
    ComEx_TxConfiratmion(17u);
}

void ComEx_TransmitPdu_HUT23_Confiratmion(void)
{
    ComEx_TxConfiratmion(18u);
}

void ComEx_TransmitPdu_HUT25_Confiratmion(void)
{
    ComEx_TxConfiratmion(19u);
}

void ComEx_TransmitPdu_HUT26_Confiratmion(void)
{
    ComEx_TxConfiratmion(20u);
}

void ComEx_TransmitPdu_HUT33_Confiratmion(void)
{
    ComEx_TxConfiratmion(21u);
}

void ComEx_TransmitPdu_HUT34_Confiratmion(void)
{
    ComEx_TxConfiratmion(22u);
}

void ComEx_TransmitPdu_HUT35_Confiratmion(void)
{
    ComEx_TxConfiratmion(23u);
}

void ComEx_TransmitPdu_HUT39_Confiratmion(void)
{
    ComEx_TxConfiratmion(24u);
}

void ComEx_TransmitPdu_HUT45_Confiratmion(void)
{
    ComEx_TxConfiratmion(25u);
}

void ComEx_TransmitPdu_HUT_FD1_Confiratmion(void)
{
    ComEx_TxConfiratmion(26u);
}

void ComEx_TransmitPdu_HUT_FD5_Confiratmion(void)
{
    ComEx_TxConfiratmion(27u);
}

void ComEx_TransmitPdu_HUT_Sync_Req_Confiratmion(void)
{
    ComEx_TxConfiratmion(28u);
}

void ComEx_TransmitPdu_IP1_Confiratmion(void)
{
    ComEx_TxConfiratmion(29u);
}

void ComEx_TransmitPdu_IP2_Confiratmion(void)
{
    ComEx_TxConfiratmion(30u);
}

void ComEx_TransmitPdu_IP3_Confiratmion(void)
{
    ComEx_TxConfiratmion(31u);
}

