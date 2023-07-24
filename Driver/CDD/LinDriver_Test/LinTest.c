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
 * @file:      LinTest.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "LinTest.h"
#include "Dio.h"
#include "Lin.h"
#include "Mcu.h"
#include "logger.h"

#define VIP_RLIN31      (0u)
#define VIP_RLIN32      (1u)

#define PIN_LOW_LVL     (0u)
#define PIN_HIGH_LVL    (1u)

#define LINTRCV_TRCV_MODE_SLEEP     (0u)
#define LINTRCV_TRCV_MODE_STANDBY   (1u)
#define LINTRCV_TRCV_MODE_NORMAL    (2u)


typedef struct LinChnlManager
{
    uint8 initSts;
    uint8 sendIndx;
    uint8 lastSendType;
    Lin_PduType *pduPtr;
}LinChnlManager_t;
LinChnlManager_t LinChnlManager[2];

static uint8 linTestPhase = 2;

static uint8 linRxData[8] = {0};
static uint8 linData1[] = {0x12,0x34,0x45,0x67,0x89,0xab,0xcd,0xef};
static uint8 linData2[] = {0x51,0xaa,0xbb,0xcc,0x11,0x05,0x06,0x07};
static uint8 lin2Data1[] = {0xAB,0xCD,0xEF,0x98,0x76,0x45,0x23,0x10};
static uint8 lin2Data2[] = {0x00,0x11,0x12,0x13,0x14,0x15,0x16,0x17};
static Lin_PduType lin1Pdu[] = 
{
    
    { 0x85, LIN_MASTER_RESPONSE, 8, LIN_CLASSIC_CS,linData2},
    { 0x47, LIN_MASTER_RESPONSE, 3, LIN_CLASSIC_CS,linData1},
    { 0xc1, LIN_SLAVE_RESPONSE, 5, LIN_ENHANCE_CS,linData1},
};

static Lin_PduType lin2Pdu[] = 
{
    { 0x06, LIN_SLAVE_RESPONSE, 4, LIN_CLASSIC_CS,lin2Data1},
    { 0x42, LIN_MASTER_RESPONSE, 7, LIN_CLASSIC_CS,lin2Data2},
    { 0x03, LIN_MASTER_RESPONSE, 6, LIN_CLASSIC_CS,lin2Data1}, 
};


void LinTrcv_SetOpMode(uint8 OpMode)
{
    switch(OpMode)
    {
        case LINTRCV_TRCV_MODE_NORMAL:
            Dio_WriteChannel(DioConf_DioChannel_VIP_RLIN31_SLP,1);
            Dio_WriteChannel(DioConf_DioChannel_VIP_RLIN32_SLP,1);
        break;
        case LINTRCV_TRCV_MODE_SLEEP:
            Dio_WriteChannel(DioConf_DioChannel_VIP_RLIN31_SLP,0);
            Dio_WriteChannel(DioConf_DioChannel_VIP_RLIN32_SLP,0);
        break;
        default:
        break;
    }
}


void LinTest_TxAndRx(uint8 LinNetwork)
{
    uint8 *dataPtr;
    uint8 i;
    LinChnlManager_t *chnlManagerPtr;
    Lin_PduType *tPduPtr;

    chnlManagerPtr = &(LinChnlManager[LinNetwork]);
    tPduPtr = &(chnlManagerPtr->pduPtr[chnlManagerPtr->sendIndx]);
    //if(LIN_SLAVE_RESPONSE == tPduPtr->Drc)
    if(chnlManagerPtr->lastSendType == LIN_SLAVE_RESPONSE)
    {
        chnlManagerPtr->lastSendType = 0;
        if(LIN_RX_OK == Lin_GetStatus(LinNetwork,&dataPtr))
        {
            for(i=0;i<tPduPtr->Dl;i++)
            {
                linRxData[i] = dataPtr[i];
                sys_info("%d\t",linRxData[i]);
            }
        }
        chnlManagerPtr->sendIndx++;
        if(chnlManagerPtr->sendIndx > 2)
        {
            chnlManagerPtr->sendIndx = 0;
        }
    }
    else
    {
        Lin_SendFrame(LinNetwork,tPduPtr);
        chnlManagerPtr->lastSendType = tPduPtr->Drc;
        if(LIN_SLAVE_RESPONSE != tPduPtr->Drc)
        {
            chnlManagerPtr->sendIndx++;
            if(chnlManagerPtr->sendIndx > 2)
            {
                chnlManagerPtr->sendIndx = 0;
            }
        }
    }

}

void LinTest_Sleep(void)
{
    uint8 i;
    for(i = 0; i < 2;i++)
    {
        Lin_GoToSleep(i);
    }
    LinTrcv_SetOpMode(LINTRCV_TRCV_MODE_SLEEP);
}

void LinTest_SetUp(void)
{
    uint8 i;
    uint8 tMode;
    Lin_Init(LinGlobalConfig0);
    LinTrcv_SetOpMode(LINTRCV_TRCV_MODE_NORMAL);
    for(i = 0; i < 2; i++)
    {
       LinChnlManager[i].initSts = 1;
       LinChnlManager[i].sendIndx = 0;
       LinChnlManager[i].lastSendType = 0;
    }
    LinChnlManager[0].pduPtr = &(lin1Pdu[0]);
    LinChnlManager[1].pduPtr = &(lin2Pdu[0]);
}




void LinTest_MainFunction(void)
{
    uint8 tMode;
    uint8 i;
    uint8 LinNetwork;
    switch(linTestPhase)
    {
        case LIN_TEST_SETUP:

        linTestPhase = LIN_TEST_TXRX;
        break;
        case LIN_TEST_TXRX:
        for(i = 0; i < 2; i++)
        {
            LinTest_TxAndRx(i);
        }
        break;
        case LIN_TEST_SLEEP:
        //LinTest_Sleep(LinNetwork);
        linTestPhase = LIN_TEST_IDLE; 
        break;
        default:
        break;
    }
}

