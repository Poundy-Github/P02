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
 * @file:      MissingDTC.h
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _MISSING_DTC_H_
#define _MISSING_DTC_H_

#include "Std_Types.h"

#define MD_MESSAGE_STATUS(id)                               (md_cfg.messages[id].status)
#define MD_MESSAGE_STATUS_IS_MISSING(id)                    (MD_MESSAGE_STATUS(id) == MD_MESSAGE_STATUS_MISSING_CONFIRM)
#define MD_MESSAGE_STATUS_IS_OK(id)                         (MD_MESSAGE_STATUS(id) == MD_MESSAGE_STATUS_OK_CONFIRM)
#define MD_MESSAGE_MISSING_JUDGE1(id1)                      (MD_MESSAGE_STATUS_IS_MISSING(id1))
#define MD_MESSAGE_MISSING_JUDGE2(id1, id2)                 (MD_MESSAGE_MISSING_JUDGE1(id1) || MD_MESSAGE_MISSING_JUDGE1(id2))
#define MD_MESSAGE_MISSING_JUDGE3(id1, id2, id3)            (MD_MESSAGE_MISSING_JUDGE2(id1, id2) || MD_MESSAGE_MISSING_JUDGE1(id3))
#define MD_MESSAGE_MISSING_JUDGE4(id1, id2, id3, id4)       (MD_MESSAGE_MISSING_JUDGE3(id1, id2, id3) || MD_MESSAGE_MISSING_JUDGE1(id4))
#define MD_MESSAGE_MISSING_JUDGE5(id1, id2, id3, id4, id5)  (MD_MESSAGE_MISSING_JUDGE4(id1, id2, id3, id4) || MD_MESSAGE_MISSING_JUDGE1(id5))
#define MD_MESSAGE_MISSING_JUDGE6(id1, id2, id3, id4, id5, id6)  (MD_MESSAGE_MISSING_JUDGE5(id1, id2, id3, id4, id5) || MD_MESSAGE_MISSING_JUDGE1(id6))
#define MD_MESSAGE_MISSING_JUDGE7(id1, id2, id3, id4, id5, id6, id7)  (MD_MESSAGE_MISSING_JUDGE6(id1, id2, id3, id4, id5, id6) || MD_MESSAGE_MISSING_JUDGE1(id7))
#define MD_MESSAGE_MISSING_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8)  (MD_MESSAGE_MISSING_JUDGE7(id1, id2, id3, id4, id5, id6, id7) || MD_MESSAGE_MISSING_JUDGE1(id8))
#define MD_MESSAGE_MISSING_JUDGE9(id1, id2, id3, id4, id5, id6, id7, id8, id9)  (MD_MESSAGE_MISSING_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8) || MD_MESSAGE_MISSING_JUDGE1(id9))
#define MD_MESSAGE_OK_JUDGE1(id1)                           (MD_MESSAGE_STATUS_IS_OK(id1))
#define MD_MESSAGE_OK_JUDGE2(id1, id2)                      (MD_MESSAGE_OK_JUDGE1(id1) && MD_MESSAGE_OK_JUDGE1(id2))
#define MD_MESSAGE_OK_JUDGE3(id1, id2, id3)                 (MD_MESSAGE_OK_JUDGE2(id1, id2) && MD_MESSAGE_OK_JUDGE1(id3))
#define MD_MESSAGE_OK_JUDGE4(id1, id2, id3, id4)            (MD_MESSAGE_OK_JUDGE3(id1, id2, id3) && MD_MESSAGE_OK_JUDGE1(id4))
#define MD_MESSAGE_OK_JUDGE5(id1, id2, id3, id4, id5)       (MD_MESSAGE_OK_JUDGE4(id1, id2, id3, id4) && MD_MESSAGE_OK_JUDGE1(id5))
#define MD_MESSAGE_OK_JUDGE6(id1, id2, id3, id4, id5, id6)  (MD_MESSAGE_OK_JUDGE5(id1, id2, id3, id4, id5) && MD_MESSAGE_OK_JUDGE1(id6))
#define MD_MESSAGE_OK_JUDGE7(id1, id2, id3, id4, id5, id6, id7) (MD_MESSAGE_OK_JUDGE6(id1, id2, id3, id4, id5, id6) && MD_MESSAGE_OK_JUDGE1(id7))
#define MD_MESSAGE_OK_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8)    (MD_MESSAGE_OK_JUDGE7(id1, id2, id3, id4, id5, id6, id7) && MD_MESSAGE_OK_JUDGE1(id8))
#define MD_MESSAGE_OK_JUDGE9(id1, id2, id3, id4, id5, id6, id7, id8, id9)   (MD_MESSAGE_OK_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8) && MD_MESSAGE_OK_JUDGE1(id9))

#define MD_MESSAGE_STATUS_IS_DETERMINED(id)                 (MD_MESSAGE_STATUS_IS_MISSING(id) || MD_MESSAGE_STATUS_IS_OK(id))

#define MD_DTC_JUDGE(passFunc, failFunc, ret)               \
do                                                          \
{                                                           \
    if(failFunc)                                            \
    {                                                       \
        ret = MD_DTC_JUDGE_RESULT_FAILED;                   \
    }                                                       \
    else if(passFunc)                                       \
    {                                                       \
        ret = MD_DTC_JUDGE_RESULT_PASSED;                   \
    }                                                       \
    else                                                    \
    {                                                       \
        ret = MD_DTC_JUDGE_RESULT_NOT_READY;                \
    }                                                       \
} while(0)

#define MD_DTC_JUDGE_GENERAL1(id1, ret)                     MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE1(id1), MD_MESSAGE_MISSING_JUDGE1(id1), ret)
#define MD_DTC_JUDGE_GENERAL2(id1, id2, ret)                MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE2(id1, id2), MD_MESSAGE_MISSING_JUDGE2(id1, id2), ret)
#define MD_DTC_JUDGE_GENERAL3(id1, id2, id3, ret)           MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE3(id1, id2, id3), MD_MESSAGE_MISSING_JUDGE3(id1, id2, id3), ret)
#define MD_DTC_JUDGE_GENERAL4(id1, id2, id3, id4, ret)      MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE4(id1, id2, id3, id4), MD_MESSAGE_MISSING_JUDGE4(id1, id2, id3, id4), ret)
#define MD_DTC_JUDGE_GENERAL5(id1, id2, id3, id4, id5, ret) MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE5(id1, id2, id3, id4, id5), MD_MESSAGE_MISSING_JUDGE5(id1, id2, id3, id4, id5), ret)
#define MD_DTC_JUDGE_GENERAL6(id1, id2, id3, id4, id5, id6, ret)    MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE6(id1, id2, id3, id4, id5, id6), MD_MESSAGE_MISSING_JUDGE6(id1, id2, id3, id4, id5, id6), ret)
#define MD_DTC_JUDGE_GENERAL7(id1, id2, id3, id4, id5, id6, id7, ret)   MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE7(id1, id2, id3, id4, id5, id6, id7), MD_MESSAGE_MISSING_JUDGE7(id1, id2, id3, id4, id5, id6, id7), ret)
#define MD_DTC_JUDGE_GENERAL8(id1, id2, id3, id4, id5, id6, id7, id8, ret)  MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8), MD_MESSAGE_MISSING_JUDGE8(id1, id2, id3, id4, id5, id6, id7, id8), ret)
#define MD_DTC_JUDGE_GENERAL9(id1, id2, id3, id4, id5, id6, id7, id8, id9, ret) MD_DTC_JUDGE(MD_MESSAGE_OK_JUDGE9(id1, id2, id3, id4, id5, id6, id7, id8, id9), MD_MESSAGE_MISSING_JUDGE9(id1, id2, id3, id4, id5, id6, id7, id8, id9), ret)

#define MD_VCONFIG_EQUAL1(cfg, v1)                          (md_cfg.vconfig[cfg] == v1)
#define MD_VCONFIG_EQUAL2(cfg, v1, v2)                      (MD_VCONFIG_EQUAL1(cfg, v1) || MD_VCONFIG_EQUAL1(cfg, v2))
#define MD_VCONFIG_EQUAL3(cfg, v1, v2, v3)                  (MD_VCONFIG_EQUAL2(cfg, v1, v2) || MD_VCONFIG_EQUAL1(cfg, v3))
#define MD_VCONFIG_EQUAL4(cfg, v1, v2, v3, v4)              (MD_VCONFIG_EQUAL3(cfg, v1, v2, v3) || MD_VCONFIG_EQUAL1(cfg, v4))
#define MD_VCONFIG_EQUAL5(cfg, v1, v2, v3, v4, v5)          (MD_VCONFIG_EQUAL4(cfg, v1, v2, v3, v4) || MD_VCONFIG_EQUAL1(cfg, v5))

#define MD_VCONFIG_NOT_EQUAL(cfg, v1)                       (md_cfg.vconfig[cfg] != v1)

#define MD_VCONFIG_BIGGER(cfg, v1)                          (md_cfg.vconfig[cfg] >= v1)
#define MD_VCONFIG_LITTER(cfg, v1)                          (md_cfg.vconfig[cfg] <= v1)

#define MD_VCONFIG_BETWEEN(cfg, v1, v2)                     (MD_VCONFIG_BIGGER(cfg, v1) && MD_VCONFIG_LITTER(cfg, v2))

#define MD_MESSAGE_SET_ENABLED(id)                          md_cfg.messages[id].status = MD_MESSAGE_STATUS_NOT_DETERMINED

#define MD_PDU_NO_ID                        (0xFFFFu)

typedef struct
{
    uint16 messageId;
    uint8 length;
} MD_PduCfg;

#define MD_MESSAGE_STATUS_NOT_ENABLED       (0u)
#define MD_MESSAGE_STATUS_NOT_DETERMINED    (1u)    
#define MD_MESSAGE_STATUS_MISSING_START     (2u)
#define MD_MESSAGE_STATUS_MISSING_CONFIRM   (3u)
#define MD_MESSAGE_STATUS_OK_START          (4u)
#define MD_MESSAGE_STATUS_OK_CONFIRM        (5u)

typedef struct
{
    uint16 cycle;
    uint16 okCounter;
    uint16 okCycle;
    uint16 missingCycle;
} MD_MessageCfg;

typedef struct
{
    uint8 status;
    uint8 discontinuosCount;
    uint16 receiveCount;
    uint16 receiveCountLastCycle;
    uint16 cycleCount;
    uint16 cycleConfirm;
} MD_Message;

#define MD_DTC_JUDGE_RESULT_NOT_READY       (0u)
#define MD_DTC_JUDGE_RESULT_PASSED          (1u)
#define MD_DTC_JUDGE_RESULT_FAILED          (2u)

#define MD_DTC_ENABLE_CFG0                  (0u)
#define MD_DTC_ENABLE_CFG1                  (1u)
#define MD_DTC_ENABLE_CFG2                  (2u)
#define MD_DTC_ENABLE_CFG3                  (3u)
#define MD_DTC_ENABLE_CFG4                  (4u)
#define MD_DTC_ENABLE_CFG5                  (5u)
#define MD_DTC_ENABLE_CFG6                  (6u)

#define MD_DTC_DISABLE                      (0xFFu)

typedef uint8 (*MD_DtcEnableFunc)(void);
typedef uint8 (*MD_DtcJudgeFunc)(uint8 cfgId);
typedef Std_ReturnType (*MD_DtcReportFunc)(uint8 status);
typedef struct
{
    MD_DtcEnableFunc enableFunc;
    MD_DtcJudgeFunc judgeFunc;
    MD_DtcReportFunc reportFunc;
    uint16 cycleReport;
} MD_DtcCfg;

#define MD_DTC_STATUS_NOT_ENABLED           (0u)
#define MD_DTC_STATUS_NOT_REPORTED          (1u)
#define MD_DTC_STATUS_PASSED_REPORTED       (2u)
#define MD_DTC_STATUS_FAILED_REPORTED       (3u)

typedef struct
{
    uint8 status;
    uint8 cfgId;
    uint16 cycleReport;
} MD_Dtc;

typedef boolean (*MD_GlobalFunc)(void);
typedef struct
{
    MD_GlobalFunc  globalFunc;
    uint16 discontinuosThreshold;
    uint16 dtcNumber;
    const MD_DtcCfg *dtcCfgs;
    MD_Dtc *dtcs;
    uint16 messageNumber;
    const MD_MessageCfg *messageCfgs;
    MD_Message *messages;
    uint16 pduNumber;
    const MD_PduCfg *pduCfgs;
    uint16 vconfigLength;
    uint8 *vconfig;
} MD_Cfg;

typedef struct
{
    boolean globalStatus;
} MD_Data;

void MD_PduCallback(uint16 pduId, uint8 length);
boolean MD_GlobalEnableFuncntion(void);

#endif