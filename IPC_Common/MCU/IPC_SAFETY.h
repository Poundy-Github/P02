/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*
*  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
*  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
*  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*                 File:  IPC_SAFETY.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group SAFETY  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_SAFETY_H_
#define _IPC_SAFETY_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_SAFETY_ID                                                      (18u)

/* MCU to SOC Message major id */
#define IPC_M2S_SAFETY_MSGMAJOR_APP_ID                                           (0u)
#define IPC_M2S_SAFETY_MSGMAJOR_MANAGEMENT_ID                                    (1u)
/* MCU to SOC Message sub id */
#define IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_ID                                   (0u)
#define IPC_M2S_SAFETY_APP_MSGSUB_GEAR_ID                                        (1u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_ID                         (2u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_ID                             (3u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_ID                        (4u)
#define IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_ID                          (0u)
/* MCU to SOC Message sub length */
#define IPC_M2S_SAFETY_APP_MSGSUB_TT_SAFETY_LENGTH                               (14u)
#define IPC_M2S_SAFETY_APP_MSGSUB_GEAR_LENGTH                                    (3u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH                     (42u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_LENGTH_MIN                 (2u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYTELLTALECHECK_FLEX_NUMBER                (40u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYGEARCHECK_LENGTH                         (1u)
#define IPC_M2S_SAFETY_APP_MSGSUB_SAFETYAPPMSGUPLOADED_LENGTH                    (1u)
#define IPC_M2S_SAFETY_MANAGEMENT_MSGSUB_SAFETYALIVE_LENGTH                      (1u)


/* SOC to MCU Message major id */
#define IPC_S2M_SAFETY_MSGMAJOR_APP_ID                                           (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_ID                              (0u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_ID                                 (1u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_ID                               (2u)
#define IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_ID                                 (3u)
/* SOC to MCU Message sub length */
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_LENGTH                          (1u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH                             (102u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_LENGTH_MIN                         (2u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_FLEX_NUMBER                        (100u)
#define IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_LENGTH                           (5u)
#define IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_LENGTH                             (1u)
/* Group: : SAFETY */
/* Message Major: APP */
/* Message Sub: TT_Safety */
typedef struct
{
    union
    {
        uint8_t u32Telltales_status[14];
        struct
        {
            /*self check: 0~no self check ;1~self check
            1.20 防抱死制动系统故障报警灯 - 非北美- 自检标志位*/
            uint8_t ABS_Fault_CH_Data_selfcheck             :1;
            /*Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve
            1.20 防抱死制动系统故障报警灯- 非北美 - 指示灯状态*/
            uint8_t ABS_Fault_CH_Data                       :3;
            /*1.20 防抱死制动系统故障报警灯- 北美 - 指示灯状态*/
            uint8_t ABS_Fault_US_Data_selfcheck             :1;
            /*1.20 防抱死制动系统故障报警灯- 北美 - 指示灯状态*/
            uint8_t ABS_Fault_US_Data                       :3;
            /*1.21 电子稳定系统报警灯 - 自检标志位*/
            uint8_t ESP_Enable_Data_selfcheck               :1;
            /*1.21 电子稳定系统报警灯 - 指示灯状态*/
            uint8_t ESP_Enable_Data                         :3;
            /*1.22 电子稳定系统关闭报警灯 - 自检标志位*/
            uint8_t ESP_Disable_Data_selfcheck              :1;
            /*1.22 电子稳定系统关闭报警灯 - 指示灯状态*/
            uint8_t ESP_Disable_Data                        :3;
            /*1.24 电动驻车制动报警灯- 非北美 - 自检标志位*/
            uint8_t EPB_Fault_CH_Data_selfcheck             :1;
            /*1.24 电动驻车制动报警灯- 非北美 - 指示灯状态*/
            uint8_t EPB_Fault_CH_Data                       :3;
            /*1.24 电动驻车制动报警灯- 北美 - 自检标志位*/
            uint8_t EPB_Fault_US_Data_selfcheck             :1;
            /*1.24 电动驻车制动报警灯- 北美 - 指示灯状态*/
            uint8_t EPB_Fault_US_Data                       :3;
            /*1.27 制动系统故障指示灯- 非北美 - 自检标志位*/
            uint8_t BreakError_CH_Data_selfcheck            :1;
            /*1.27 制动系统故障指示灯- 非北美 - 指示灯状态*/
            uint8_t BreakError_CH_Data                      :3;
            /*1.27 制动系统故障指示灯- 北美 - 自检标志位*/
            uint8_t BreakError_US_Data_selfcheck            :1;
            /*1.27 制动系统故障指示灯- 北美 - 指示灯状态*/
            uint8_t BreakError_US_Data                      :3;
            /*1.28 Ibooster 指示灯- 黄灯- 非北美 - 自检标志位*/
            uint8_t Ibooster_Yellow_CH_Data_selfcheck       :1;
            /*1.28 Ibooster 指示灯- 黄灯- 非北美 - 指示灯状态*/
            uint8_t Ibooster_Yellow_CH_Data                 :3;
            /*1.28 Ibooster 指示灯- 红灯- 非北美 - 自检标志位*/
            uint8_t Ibooster_Red_CH_Data_selfcheck          :1;
            /*1.28 Ibooster 指示灯- 红灯- 非北美 - 指示灯状态*/
            uint8_t Ibooster_Red_CH_Data                    :3;
            /*1.28 Ibooster 指示灯- 黄灯- 北美 - 自检标志位*/
            uint8_t Ibooster_Yellow_US_Data_selfcheck       :1;
            /*1.28 Ibooster 指示灯- 黄灯- 北美 - 指示灯状态*/
            uint8_t Ibooster_Yellow_US_Data                 :3;
            /*1.28 Ibooster 指示灯- 红灯- 北美 - 自检标志位*/
            uint8_t Ibooster_Red_US_Data_selfcheck          :1;
            /*1.28 Ibooster 指示灯- 红灯- 北美 - 指示灯状态*/
            uint8_t Ibooster_Red_US_Data                    :3;
            /*1.53 电动助力转向故障报警灯 - 红灯 - 自检标志位*/
            uint8_t EPS_Red_Error_Data_selfcheck            :1;
            /*1.53 电动助力转向故障报警灯 - 红灯 - 指示灯状态*/
            uint8_t EPS_Red_Error_Data                      :3;
            /*1.53 电动助力转向故障报警灯 - 黄灯 - 自检标志位*/
            uint8_t EPS_Yellow_Error_Data_selfcheck         :1;
            /*1.53 电动助力转向故障报警灯 - 黄灯 - 指示灯状态*/
            uint8_t EPS_Yellow_Error_Data                   :3;
            /*1.54 安全气囊故障报警灯 - 自检标志位*/
            uint8_t ABM_Error_Data_selfcheck                :1;
            /*1.54 安全气囊故障报警灯 - 指示灯状态*/
            uint8_t ABM_Error_Data                          :3;
            /*1.65 前方碰撞指示灯 - 故障 - 自检标志位 */
            uint8_t FCW_Error_Data_selfcheck                :1;
            /*1.65 前方碰撞指示灯 - 故障 - 指示灯状态*/
            uint8_t FCW_Error_Data                          :3;
            /*1.65 前方碰撞指示灯 - 工作 - 自检标志位 */
            uint8_t FCW_Enable_Data_selfcheck               :1;
            /*1.65 前方碰撞指示灯 - 工作 - 指示灯状态*/
            uint8_t FCW_Enable_Data                         :3;
            /*1.72\1.73 动力电池故障指示灯 - 红灯 - 自检标志位
            1.106 电池组故障指示灯(EV) - 自检标志位*/
            uint8_t PBF_Derating_Data_selfcheck             :1;
            /*1.72\1.73 动力电池故障指示灯 - 红灯 - 指示灯状态
            1.106 电池组故障指示灯(EV) - 指示灯状态*/
            uint8_t PBF_Derating_Data                       :3;
            /*1.72\1.73 动力电池故障指示灯 - 黄灯 - 自检标志位
            1.107 动力系统故障指示灯(EV) - 指示灯状态*/
            uint8_t PBF_Warning_Data_selfcheck              :1;
            /*1.72\1.73 动力电池故障指示灯 - 黄灯 - 指示灯状态*/
            uint8_t PBF_Warning_Data                        :3;
            /*1.74 混合动力系统故障报警灯 - 黄灯 - 自检标志位
            1.107 动力系统故障指示灯(EV) - 黄灯- 自检标志位*/
            uint8_t HEV_Yellow_Data_selfcheck               :1;
            /*1.74 混合动力系统故障报警灯 - 黄灯 - 指示灯状态
            1.107 动力系统故障指示灯(EV) - 黄灯- 指示灯状态*/
            uint8_t HEV_Yellow_Data                         :3;
            /*1.74 混合动力系统故障报警灯 - 红灯 - 自检标志位
            1.107 动力系统故障指示灯(EV) - 红灯- 自检标志位*/
            uint8_t HEV_Red_Data_selfcheck                  :1;
            /*1.74 混合动力系统故障报警灯 - 红灯 - 指示灯状态
            1.107 动力系统故障指示灯(EV) - 红灯- 指示灯状态*/
            uint8_t HEV_Red_Data                            :3;
            /*1.16 12V电源故障报警灯 - 自检标志位*/
            uint8_t TPF_Data_selfcheck                      :1;
            /*1.16 12V电源故障报警灯 - 指示灯状态*/
            uint8_t TPF_Data                                :3;
            uint8_t Power_Reduction_Data_selfcheck          :1;
            uint8_t Power_Reduction_Data                    :3;
            /*1.102 E park 指示灯 - 自检标志位*/
            uint8_t EPark_Data_selfcheck                    :1;
            /*1.102 E park 指示灯 - 指示灯状态*/
            uint8_t EPark_Data                              :3;
            /*1.17 DC/DC报警灯 - 自检标志位*/
            uint8_t DC_Alert_Data_selfcheck                 :1;
            /*1.17 DC/DC报警灯 - 指示灯状态*/
            uint8_t DC_Alert_Data                           :3;
            /*1.104 电机故障指示灯 - 自检标志位*/
            uint8_t Motor_Failure_Data_selfcheck            :1;
            /*1.104 电机故障指示灯 - 指示灯状态*/
            uint8_t Motor_Failure_Data                      :3;
            /*1.65 前方碰撞指示灯 - Off - 自检标志位 */
            uint8_t FCW_Off_Data_selfcheck                  :1;
            /*1.65 前方碰撞指示灯 - Off - 指示灯状态*/
            uint8_t FCW_Off_Data                            :3;
            /*预留*/
            uint8_t Reserve                                 :4;
        }s_u32Telltales_status_t;
    }u_TT_Safetyu32Telltales_status_t;
}IPC_M2S_SAFETYAPPTT_Safety_t;

/* Transmit function of sub message TT_Safety */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYAPPTT_Safety_Transmit(IPC_M2S_SAFETYAPPTT_Safety_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Gear */
typedef struct
{
    /*GEAR_P     (0U)
    GEAR_R     (1U)
    GEAR_N     (2U)
    GEAR_D     (3U)
    GEAR_D1     (4U)
    GEAR_D2     (5U)
    GEAR_D3     (6U)
    GEAR_D4     (7U)
    GEAR_D5     (8U)
    GEAR_D6     (9U)
    GEAR_D7     (10U)
    GEAR_D8     (11U)
    GEAR_D9     (12U)
    GEAR_M     (13u)
    GEAR_M1     (14U)
    GEAR_M2     (15U)
    GEAR_M3     (16U)
    GEAR_M4     (17U)
    GEAR_M5     (18U)
    GEAR_M6     (19U)
    GEAR_M7     (20U)
    GEAR_M8     (21U)
    GEAR_M9     (22U)
    GEAR_NO_DISPLAY   (255U)*/
    uint8_t gear_vlaue;
    /*GEAR_ON_SHOW (0U)
    GEAR_ON_FLASH (1U)
    GEAR_1HZ_FLASH (2U)
    GEAR_0_5HZ_FLASH (3U)*/
    uint8_t gear_status;
    /*GEAR_SHIFT_UP    (0U)
    GEAR_SHIFT_DOWN    (1U)
    GEAR_NO_DISPLAY    (255U)*/
    uint8_t gear_shift_value;
}IPC_M2S_SAFETYAPPGear_t;

/* Transmit function of sub message Gear */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYAPPGear_Transmit(IPC_M2S_SAFETYAPPGear_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SafetyTelltaleCheck */
typedef struct
{
    uint16_t TT_ACKLength;
    /*CRC Checking ACK data*/
    uint8_t TT_ACK[40];
}IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t;

/* Transmit function of sub message SafetyTelltaleCheck */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYAPPSafetyTelltaleCheck_Transmit(IPC_M2S_SAFETYAPPSafetyTelltaleCheck_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SafetyGearCheck */
typedef struct
{
    union
    {
        uint8_t Gear_ACK;
        struct
        {
            /*byte0:id0, byte1:ack0  byte2:id1, byte3:ack1  in turns*/
            uint8_t ACK_Value                               :1;
            /*0x00:P
            0x01:R
            0x02:N
            0x03:D
            0x04~0x0C:D1~D9
            0x0D~0x16:M1~M9
            0x17~0x1F:Reserved*/
            uint8_t Gear_ID                                 :5;
        }s_Gear_ACK_t;
    }u_SafetyGearCheckGear_ACK_t;
}IPC_M2S_SAFETYAPPSafetyGearCheck_t;

/* Transmit function of sub message SafetyGearCheck */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYAPPSafetyGearCheck_Transmit(IPC_M2S_SAFETYAPPSafetyGearCheck_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SafetyAppMsgUploaded */
typedef struct
{
    /*0xBB:Data send complete，other：reserved*/
    uint8_t Status;
}IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t;

/* Transmit function of sub message SafetyAppMsgUploaded */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_Transmit(IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : SAFETY */
/* Message Major: MANAGEMENT */
/* Message Sub: SafetyAlive */
typedef struct
{
    /*as long as data is received ,connected ok*/
    uint8_t RollingCounter;
}IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t;

/* Transmit function of sub message SafetyAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_SAFETYMANAGEMENTSafetyAlive_Transmit(IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : SAFETY */
/* Group: : SAFETY */
/* Message Major: APP */
/* Message Sub: SafetyAppAlive */
typedef struct
{
    /*0xAA:Service Alive，other：reserved*/
    uint8_t AliveTick;
}IPC_S2M_SAFETYAPPSafetyAppAlive_t;

/* Receive function of sub message SafetyAppAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SAFETYAPPSafetyAppAlive_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyAppAlive_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SafetyTTCRC */
typedef struct
{
    uint16_t TT_CRCLength;
    /*CRC Data byte0:id0, byte1~4:crc0   in turns*/
    uint8_t TT_CRC[100];
}IPC_S2M_SAFETYAPPSafetyTTCRC_t;

/* Receive function of sub message SafetyTTCRC */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SAFETYAPPSafetyTTCRC_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyTTCRC_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SafetyGearCRC */
typedef struct
{
    uint32_t CRC_Value;
    /*0x00:P
    0x01:R
    0x02:N
    0x03:D
    0x04~0x0C:D1~D9
    0x0D~0x16:M1~M9
    0x17~0x1F:Reserved
    0x20~0xFF:Invalid*/
    uint8_t Gear_ID;
}IPC_S2M_SAFETYAPPSafetyGearCRC_t;

/* Receive function of sub message SafetyGearCRC */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SAFETYAPPSafetyGearCRC_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPSafetyGearCRC_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TTSelfCheck */
typedef struct
{
    /*selfcheck status from soc*/
    uint8_t TT_SelfCheck_Sts;
}IPC_S2M_SAFETYAPPTTSelfCheck_t;

/* Receive function of sub message TTSelfCheck */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_SAFETYAPPTTSelfCheck_Receive(uint8_t *receiveData, IPC_S2M_SAFETYAPPTTSelfCheck_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : SAFETY */
#ifdef __cplusplus
}
#endif

#endif
