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
 * @file:      AMP_DTC.h
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

#ifndef __AMP_DTC_H
#define __AMP_DTC_H

#include "Rte_AMP.h"
#include "AMP_Cfg.h"


#define AMP8532_CHANNEL_NUM                             (4u)
#define CHANNEL_FL                                      (0u)
#define CHANNEL_FR                                      (1u)
#define CHANNEL_RL                                      (2u)
#define CHANNEL_RR                                      (3u)
#define CHANNEL_SW1                                     (0u)
#define CHANNEL_SW2                                     (1u)
#define CHANNEL_CENTER                                  (2u)
#define CHANNEL_AVAS                                    (3u)

#define AMPSELFCHECKSTS_PENDING                        (0u)
#define AMPSELFCHECKSTS_DONE                           (1u)

#define AMPSELFCHECKTYPE_NONE                          (0u)
#define AMPSELFCHECKTYPE_DCLOAD                        (1u)
#define AMPSELFCHECKTYPE_ACLOAD                        (2u)
#define AMPSELFCHECKTYPE_NUM                           (3u)

#define AMPMONITOR_NONE                                (0u)
#define AMPMONITOR_DEVICE                              (1u)
#define AMPMONITOR_CHANNEL                             (2u)
#define AMPMONITOR_NUM                                 (3u)

#define AMPMONITORN2_DEVICE                            (1u)
#define AMPMONITOR_FAULT                               (2u)
#define AMPMONITOR_AUDIO                               (3u)
#define AMPMONITORN2_NUM                               (4u)


#define AMPMONITOR_RESULT_NOERR                         (0u)
#define AMPMONITOR_RESULT_DEVICEINDEXERR                (1u)
#define AMPMONITOR_RESULT_DIAGPINERR                    (2u)

#define AMP_IPCSENDSUCCESS                              (0u)
#define AMP_IPCSENDRETRY                                (1u)
#define AMP_IPCWAITINIT                                 (0u)
#define AMP_IPCTIMEPENDING                              (1u)
#define AMP_IPCTIMEOUT                                  (2u)
#define AMP_IPCTIMEDONE                                 (3u)


#define AMPDCLOADUNKNOW                                     (0u)
#define AMPDCLOADSHORTACROSS                                (1u)
#define AMPDCLOADSHORTBAT                                   (2u)
#define AMPDCLOADGND                                        (4u)
#define AMPDCLOADNORMAL                                     (5u)
#define AMPDCLOADOPEN                                       (6u)

#define AMP_DTCLOG(...)       (void)Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_VERBOSE, __VA_ARGS__)



typedef struct
{
    uint8 AMP_Sts;
    uint8 DCDiagResult[AMP8532_CHANNEL_NUM];
    uint8 ACDiagResult[AMP8532_CHANNEL_NUM];
}e_AMP_SelfCheckResult_t;

typedef struct
{
    s_DeviceSts_Type    DeviceSts;
    u_ChannelErr_Type   ChannelSts[AMP8532_CHANNEL_NUM];
}s_AMP_MonitorResult_t;


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern void AMP_DTCInit(uint8 dev_id);
extern void AMP_EOLSpeakerSts(uint8 *ptr, uint8 length);
extern uint8 AMP8532_SelfCheckResult(uint8 dev_id, uint8 CheckType,const I2C_AMPReq_t * I2C_Data);
extern uint8 AMP8532_MonitorResult(uint8 dev_id, uint8 MonitorType,const I2C_AMPReq_t * I2C_Data);
extern uint8 AMP8532N2_MonitorResult(uint8 dev_id, uint8 MonitorType,const I2C_AMPReq_t * I2C_Data);
extern uint8 AMP8532_SelfCheckStsSet(uint8 dev_id,uint8 StsResult);
extern void AMPSendAudioStartupResult(void);
extern void AMPIPCReceiveACK(uint8 dev_id);
extern void AMP_NormalIPCLogic(uint8 dev_id);
extern void AMPDTC_MainFunc(uint8 dev_id);
extern void AMPClearDiag2Result(uint8 dev_id);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"





#endif

