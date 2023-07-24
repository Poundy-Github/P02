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
 * @file:      Misc_Diag.h
 * @author:    Nobo
 * @date:      2020-9-2
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-2
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _MISC_DIAG_MIC_H_
#define _MISC_DIAG_MIC_H_

#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"

#if ((!(defined GWM_V35_PROJECT_TYPE_B03)) && (!(defined GWM_V35_PROJECT_TYPE_B02)))
#ifndef PLT_DFCT_MISC_DTC_OF_GPS
#define PLT_DFCT_MISC_DTC_OF_GPS
#endif
#endif


#define MISC_DIDPOSITIVE_RESPONSE_OPEN      (1)
#define MISC_DIDPOSITIVE_RESPONSE_GND       (2)
#define MISC_DIDPOSITIVE_RESPONSE_BAT       (3)
#define MISC_DIDPOSITIVE_RESPONSE_CONNECTED (4)

#define Mic_P_PorteVolStateSize             4
#define Mic_P_PorteVolStateList                         \
        {0u,   60u,   MIC_POSITIVE_LOWVOLTAGE_MASK},    \
        {900u, 1200u, MIC_POSITIVE_NORMAL_MASK},        \
        {1500, 2750u, MIC_POSITIVE_OVERVOLTAGE_MASK},   \
        {1300u,1450u, MIC_POSITIVE_OPEN_MASK}

#define Mic_N_PorteVolStateSize             4
#define Mic_N_PorteVolStateList                         \
        {0u,   60u,   MIC_NEGATIVE_LOWVOLTAGE_MASK},    \
        {243u, 340u,  MIC_NEGATIVE_NORMAL_MASK},        \
        {1040u, 2200u,  MIC_NEGATIVE_OVERVOLTAGE_MASK},   \
        {0u,   60u,   MIC_NEGATIVE_OPEN_MASK}

#define MISC_DIAG_TUNER_POWEROFF_DELAY_CNT	(100)//when error occur , power off 10s(=10s/100ms) , then restart diag
#define MISC_DIAG_RVC_POWEROFF_DELAY_CNT	(100)//when error occur , power off 10s(=10s/100ms) , then restart diag
#define MISC_DIAG_GNSS_POWEROFF_DELAY_CNT	(100)//when error occur , power off 10s(=10s/100ms) , then restart diag
#define MISC_DIAG_TUNER_POWERON_DELAY_CNT	(100)//when sys power up 10s(cause error need 5s to checkout) , stop TUNER diag

#define MIC_BAT_ALL_OCCURE_MAX_MINUS_VLU	(150)//when both BAT DTC occure , recheck it , lager and lag than 150 was the ready DTC

void Misc_Diag_Init(void);
void Misc_Diag_Task(void);
void Misc_Diag_EOL_0xFDD1_EOL_ReadMICStatus(uint8 * arg);
void Misc_Diag_EOL_0xFDD9_EOL_WriteValueForDispalyEnable(uint8 *arg);
void Misc_Diag_EOL_0xFDE2_EOL_ReadResetInformation(uint8 * arg);
void Misc_Diag_EOL_0xFDE1_EOL_ReadWatchDogCnt(uint8 * arg);
void Misc_AdcPrintfTriger(boolean setVlu);
extern boolean Misc_PowerWasMPQ2022(void);
extern boolean MISC_SYSRVCWasUsed(void);
extern boolean MISC_SYSGNSSWasUsed(void);

#endif /* ifndef _MISC_DIAG_MIC_H_.2020-9-2 11:44:38 GW00188879 */

