/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*                 File:  IPC_HUD.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group HUD  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef IPC_HUD_H
#define IPC_HUD_H

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_HUD_ID                                                         (14u)

/* MCU to SOC Message major id */
#define IPC_M2S_HUD_MSGMAJOR_COMMON_ID                                           (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_ID                           (0u)
#define IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_ID                     (1u)
/* MCU to SOC Message sub length */
#define IPC_M2S_HUD_COMMON_MSGSUB_NVMCONFIGRESPONSE_LENGTH                       (12u)
#define IPC_M2S_HUD_COMMON_MSGSUB_ALIVEMONITORMSGUPLOADED_LENGTH                 (1u)


/* SOC to MCU Message major id */
#define IPC_S2M_HUD_MSGMAJOR_COMMON_ID                                           (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_ID                            (0u)
#define IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_ID                                (1u)
#define IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_ID                                    (2u)
#define IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_ID                                  (3u)
/* SOC to MCU Message sub length */
#define IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_LENGTH                        (1u)
#define IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_LENGTH                            (11u)
#define IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_LENGTH                                (1u)
#define IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_LENGTH                              (2u)
/* Group: : HUD */
/* Message Major: Common */
/* Message Sub: NvmConfigResponse */
typedef struct
{
    uint8_t WHUDSwitch;
    uint8_t DriverDisplaySwitch;
    uint8_t NaviDisplaySwitch;
    uint8_t PhoneDisplaySwitch;
    uint8_t DisplayRotationLevel;
    uint8_t DisplayHeightLevel;
    uint8_t DisplayBacklightSwitch;
    uint8_t DisplayBacklightLevel;
    uint8_t DisplayTheme;
    uint8_t DisplayFramework;
    uint8_t DisplayMode;
    uint8_t DriveMode;
}IPC_M2S_HUDCommonNvmConfigResponse_t;

/* Transmit function of sub message NvmConfigResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_HUDCommonNvmConfigResponse_Transmit(IPC_M2S_HUDCommonNvmConfigResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: AliveMonitorMsgUploaded */
typedef struct
{
    /*0xBB : Data send complete£¬other £ºreserved*/
    uint8_t Status;
}IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t;

/* Transmit function of sub message AliveMonitorMsgUploaded */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_HUDCommonAliveMonitorMsgUploaded_Transmit(IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : HUD */
/* Group: : HUD */
/* Message Major: Common */
/* Message Sub: NvmConfigRequset */
typedef struct
{
    uint8_t Request;
}IPC_S2M_HUDCommonNvmConfigRequset_t;

/* Receive function of sub message NvmConfigRequset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_HUDCommonNvmConfigRequset_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonNvmConfigRequset_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetNvmConfig */
typedef struct
{
    uint8_t WHUDSwitch;
    uint8_t DriverDisplaySwitch;
    uint8_t NaviDisplaySwitch;
    uint8_t PhoneDisplaySwitch;
    uint8_t DisplayRotationLevel;
    uint8_t DisplayHeightLevel;
    uint8_t DisplayBacklightSwitch;
    uint8_t DisplayBacklightLevel;
    uint8_t DisplayTheme;
    uint8_t DisplayFramework;
    uint8_t DisplayMode;
}IPC_S2M_HUDCommonSetNvmConfig_t;

/* Receive function of sub message SetNvmConfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_HUDCommonSetNvmConfig_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonSetNvmConfig_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: AliveMsg */
typedef struct
{
    /*0xAA : Service Alive£¬other £ºreserved*/
    uint8_t Tick;
}IPC_S2M_HUDCommonAliveMsg_t;

/* Receive function of sub message AliveMsg */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_HUDCommonAliveMsg_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonAliveMsg_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: WhudNvmSet */
typedef struct
{
    /*Enum_WHUDSwitch = 0;
    Enum_DriverDisplaySwitch = 1;
    Enum_NaviDisplaySwitch = 2;
    Enum_PhoneDisplaySwitch = 3;
    Enum_DisplayRotationLevel = 4;
    Enum_DisplayHeightLevel = 5;
    Enum_DisplayBacklightSwitch = 6;
    Enum_DisplayBacklightLevel = 7;
    Enum_DisplayTheme = 8;
    Enum_DisplayFramework = 9;
    Enum_DisplayMode = 10;
    Enum_DriveMode = 11;*/
    uint8_t Id;
    /*Whud Set data*/
    uint8_t Value;
}IPC_S2M_HUDCommonWhudNvmSet_t;

/* Receive function of sub message WhudNvmSet */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_HUDCommonWhudNvmSet_Receive(uint8_t *receiveData, IPC_S2M_HUDCommonWhudNvmSet_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : HUD */
#ifdef __cplusplus
}
#endif

#endif
