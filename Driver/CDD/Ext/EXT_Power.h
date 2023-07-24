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
 * @file:      EXT_Power.h
 * @author:    Nobo
 * @date:      2020-6-5
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-5
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _EXT_POWER_H_
#define _EXT_POWER_H_

#include "Std_Types.h"

/* Power state type define*/
typedef enum
{
    ePOWER_STATE_INITIAL=0,
    ePOWER_STATE_IDLE,
    ePOWER_STATE_POWER_UP,
    ePOWER_STATE_POWER_DOWN,
    ePOWER_STATE_RESET,
    ePOWER_INTERIOR_STATE,
}POWER_STATE_t;

#define EXT_POWER_RESET                 (0)
#define EXT_POWER_RESET2BOOT_SYS         (1)

#define DIAG_REQ_COLD_RESET 				0xA0A00A0Au	
#define SOC_REQ_COLD_RESET					0xB0B00B0Bu
#define UPGRADE_COLD_RESET					0xC0C00C0Cu
#define SYS_ERR_COLD_RESET					0xA1A1A1A1u
#define DIAG_REQ_WARM_RESET 				0xD0D00D0Du	
#define UPGRADE_WARM_RESET					0xE0E00E0Eu	
#define HARDKEY_WARM_RESET					0xF0F00F0Fu	
#define COLD_RESET_CLEARED					0u

#define INIT_PROCESS_FINISHED				0xA5A55A5Au
#define INIT_PROCESS_NOT_FINISHED			0u

#define SOC_RESET_USB_UPDATE				0X50500505
#define SOC_RESET_FOTA_CHECK_MIN			0X60600606
#define SOC_RESET_SYSTEM_REC				0X70700707
#define SOC_RESET_SOC_MINI					0X80800808
#define SOC_RESET_HANDSHAKE					0X90900909
#define SOC_RESET_HEALTH					0X91911919


#pragma ghs section bss = ".rram_reset_flag" 

extern uint32 soc_cold_reset_type;
extern uint32 cold_reset_req;
extern uint32 init_process_finish;

#pragma ghs section bss = default 

void EXT_Power_Management(void);
void EXT_Power_BasicPowerDown(void);
void EXT_Power_GotoSleep(void);
void EXT_Power_BasicPowerUp(void);
Std_ReturnType EXT_Power_ReqSocReset(uint8 minSystem);
void EXT_Power_ReadPmicState(POWER_STATE_t * state);
Std_ReturnType EXT_Power_ReqSocPowerState(POWER_STATE_t state);
extern boolean EXT_USBWasFastCharge(void);
extern boolean EXT_USBWasLowCharge(void);


#endif /* ifndef _EXT_POWER_H_.2020-6-5 15:24:29 GW00188879 */
