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
*                 File:  IPC_POWER.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group POWER  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_POWER_H_
#define _IPC_POWER_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_POWER_ID                                                       (2u)

/* MCU to SOC Message major id */
#define IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID                                     (0u)
#define IPC_M2S_POWER_MSGMAJOR_SYSTEMSTATE_ID                                    (1u)
#define IPC_M2S_POWER_MSGMAJOR_POWERINFO_ID                                      (2u)
/* MCU to SOC Message sub id */
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID                     (0u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_MCUREQUESTQNXSERVICE_ID                  (1u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_VERSION_ID                               (2u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_HEATHRESPONSE_ID                         (3u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_ID                            (0u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_HUDSTATE_ID                             (1u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CONSOLESTATE_ID                         (2u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CLUSTERSTATE_ID                         (3u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_MCUSTATE_ID                             (4u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_VOLTATEGEINFO_ID                          (0u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_TEMPERATURE_ID                            (1u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_KL15STATE_ID                              (2u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_MCUINFO_ID                                (3u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_FOTAACK_ID                                (4u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_APP_INFOMS_ID                             (5u)
/* MCU to SOC Message sub length */
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH                 (4u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_MCUREQUESTQNXSERVICE_LENGTH              (1u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_VERSION_LENGTH                           (1u)
#define IPC_M2S_POWER_SOCMANAGER_MSGSUB_HEATHRESPONSE_LENGTH                     (1u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH                        (2u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_HUDSTATE_LENGTH                         (1u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CONSOLESTATE_LENGTH                     (1u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_CLUSTERSTATE_LENGTH                     (1u)
#define IPC_M2S_POWER_SYSTEMSTATE_MSGSUB_MCUSTATE_LENGTH                         (1u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_VOLTATEGEINFO_LENGTH                      (5u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_TEMPERATURE_LENGTH                        (5u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_KL15STATE_LENGTH                          (1u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_MCUINFO_LENGTH                            (2u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_FOTAACK_LENGTH                            (1u)
#define IPC_M2S_POWER_POWERINFO_MSGSUB_APP_INFOMS_LENGTH                         (2u)


/* SOC to MCU Message major id */
#define IPC_S2M_POWER_MSGMAJOR_SOCMANAGER_ID                                     (0u)
#define IPC_S2M_POWER_MSGMAJOR_SYSTEMSTATE_ID                                    (1u)
/* SOC to MCU Message sub id */
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_ID                      (0u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEATH_ID                                 (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_RESET_ID                                 (2u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXRESPONSEMCUREQUEST_ID                 (3u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXINFOMCUSYSTEM_ID                      (4u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXQUERYVERSION_ID                       (5u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_POWEROFFREADY_ID                         (6u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEALTHSET_ID                             (7u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_ID                            (0u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_FOTASTS_ID                              (1u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_GETSMSTS_ID                             (2u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_APP_INFOSM_ID                           (3u)
/* SOC to MCU Message sub length */
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH                  (4u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEATH_LENGTH                             (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_RESET_LENGTH                             (2u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXRESPONSEMCUREQUEST_LENGTH             (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXINFOMCUSYSTEM_LENGTH                  (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXQUERYVERSION_LENGTH                   (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_POWEROFFREADY_LENGTH                     (1u)
#define IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEALTHSET_LENGTH                         (1u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH                        (1u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_FOTASTS_LENGTH                          (1u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_GETSMSTS_LENGTH                         (1u)
#define IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_APP_INFOSM_LENGTH                       (2u)
/* Group: : POWER */
/* Message Major: SocManager */
/* Message Sub: HandshakeResponse */
typedef struct
{
    uint8_t u8Reserved[4];
}IPC_M2S_POWERSocManagerHandshakeResponse_t;

/* Transmit function of sub message HandshakeResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSocManagerHandshakeResponse_Transmit(IPC_M2S_POWERSocManagerHandshakeResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MCURequestQnxService */
typedef struct
{
    /*0x1: close
    0x2: open*/
    uint8_t MCURequestQnxService;
}IPC_M2S_POWERSocManagerMCURequestQnxService_t;

/* Transmit function of sub message MCURequestQnxService */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSocManagerMCURequestQnxService_Transmit(IPC_M2S_POWERSocManagerMCURequestQnxService_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Version */
typedef struct
{
    /*
    0 : NON
    1 : A1
    2 : B0
    3 : B1*/
    uint8_t HwVersion;
}IPC_M2S_POWERSocManagerVersion_t;

/* Transmit function of sub message Version */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSocManagerVersion_Transmit(IPC_M2S_POWERSocManagerVersion_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HeathResponse */
typedef struct
{
    /*0-255:from soc send heath*/
    uint8_t u8Reserved;
}IPC_M2S_POWERSocManagerHeathResponse_t;

/* Transmit function of sub message HeathResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSocManagerHeathResponse_Transmit(IPC_M2S_POWERSocManagerHeathResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : POWER */
/* Message Major: SystemState */
/* Message Sub: IVI_State */
typedef struct
{
    /*0x0:IVI_OFF;
    0x1:IVI_Standby;
    0x3:IVI_Shutdown;
    0x4:IVI_Remote;
    0x5:IVI_Normal;
    0x6:IVI_Power_Err;
    0x7:IVI_PowerSave1;
    0x8:IVI_PowerSave2;
    0x9:IVI_Local;
    0x0A:IVI_Demo;
    0x0B:IVI_Awakehold;*/
    uint8_t IVI_State;
    /*0x0:None;0x1:TRUE*/
    uint8_t Force;
}IPC_M2S_POWERSystemStateIVI_State_t;

/* Transmit function of sub message IVI_State */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSystemStateIVI_State_Transmit(IPC_M2S_POWERSystemStateIVI_State_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HUDState */
typedef struct
{
    /*0x0:HUD off;0x1:HUD standby;0x2:HUD on*/
    uint8_t HUD_State;
}IPC_M2S_POWERSystemStateHUDState_t;

/* Transmit function of sub message HUDState */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSystemStateHUDState_Transmit(IPC_M2S_POWERSystemStateHUDState_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ConsoleState */
typedef struct
{
    /*0x0:console off;0x1:console standby;0x2:console on*/
    uint8_t Console_State;
}IPC_M2S_POWERSystemStateConsoleState_t;

/* Transmit function of sub message ConsoleState */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSystemStateConsoleState_Transmit(IPC_M2S_POWERSystemStateConsoleState_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ClusterState */
typedef struct
{
    /*0x0:cluster off;
    0x1:cluster standby;
    0x2:cluster on
    0x3:cluster startup
    0x4:cluster shutdown*/
    uint8_t ClusterState;
}IPC_M2S_POWERSystemStateClusterState_t;

/* Transmit function of sub message ClusterState */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSystemStateClusterState_Transmit(IPC_M2S_POWERSystemStateClusterState_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MCUState */
typedef struct
{
    /*0x0: OFF
    0x1: ShutDown
    0x2: ON
    0x3: SOC_OFF*/
    uint8_t MCUState;
}IPC_M2S_POWERSystemStateMCUState_t;

/* Transmit function of sub message MCUState */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERSystemStateMCUState_Transmit(IPC_M2S_POWERSystemStateMCUState_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : POWER */
/* Message Major: PowerInfo */
/* Message Sub: VoltategeInfo */
typedef struct
{
    float VoltageValue;
    /*0x0:low_sleep;
    0x1:normal;
    0x2:high_alarm;
    0x3:high_sleep;
    0x4:Low_alarm*/
    uint8_t VoltageState;
}IPC_M2S_POWERPowerInfoVoltategeInfo_t;

/* Transmit function of sub message VoltategeInfo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoVoltategeInfo_Transmit(IPC_M2S_POWERPowerInfoVoltategeInfo_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Temperature */
typedef struct
{
    float Temperature;
    /*0x00: Low Sleep
    0x01: Normal
    0x02: High protect
    0x03: High Sleep*/
    uint8_t TemperatureState;
}IPC_M2S_POWERPowerInfoTemperature_t;

/* Transmit function of sub message Temperature */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoTemperature_Transmit(IPC_M2S_POWERPowerInfoTemperature_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: KL15State */
typedef struct
{
    /*0x0:KL15 OFF ;
    0x1:KL15 ON*/
    uint8_t KL15State;
}IPC_M2S_POWERPowerInfoKL15State_t;

/* Transmit function of sub message KL15State */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoKL15State_Transmit(IPC_M2S_POWERPowerInfoKL15State_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MCUInfo */
typedef struct
{
    /*0x0: ColdReset
    0x1: WarmReset*/
    uint8_t ResetType;
    /*0x0: ECUM_WKSOURCE_NONE                            
    0xFF: ECUM_WKSOURCE_ALL_SOURCES                     
    0x01: ECUM_WKSOURCE_POWER                           
    0x02: ECUM_WKSOURCE_RESET                           
    0x04: ECUM_WKSOURCE_INTERNAL_RESET                  
    0x08: ECUM_WKSOURCE_INTERNAL_WDG                    
    0x10: ECUM_WKSOURCE_EXTERNAL_WDG                    
    0x20: ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b 
    0x40: ECUM_WKSOURCE_LVI                             
    0x80: ECUM_WKSOURCE_COMMON_WAKEUP          
    this is  a bit operator, one bit mean different reason    */
    uint8_t WakeupSource;
}IPC_M2S_POWERPowerInfoMCUInfo_t;

/* Transmit function of sub message MCUInfo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoMCUInfo_Transmit(IPC_M2S_POWERPowerInfoMCUInfo_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FOTAACK */
typedef struct
{
    /*0x0:NotReceive
    0x1:Receive*/
    uint8_t StsACK;
}IPC_M2S_POWERPowerInfoFOTAACK_t;

/* Transmit function of sub message FOTAACK */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoFOTAACK_Transmit(IPC_M2S_POWERPowerInfoFOTAACK_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: APP_INFOMS */
typedef struct
{
    /*0x01:local_timer
    0x02:nm_sts
    0x03:diagtomini
    0x04:DVRACK
    0x05:virtualevent*/
    uint8_t type;
    /*0x01:timeout9min50s(type:1)
    0x01:nm_prebussleep(type:2)
    0x02:nm_bussleep(type:2)
    0x03:nm_normal(type:2)
    0x00:diagtomini(type:3)
    0x00:usbshutdown(type:5)
    0x01:usbenable(type:5)
    0x02:camerashutdown(type:5)
    0x03:cameraenable(type:5)*/
    uint8_t value;
}IPC_M2S_POWERPowerInfoAPP_INFOMS_t;

/* Transmit function of sub message APP_INFOMS */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit(IPC_M2S_POWERPowerInfoAPP_INFOMS_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : POWER */
/* Group: : POWER */
/* Message Major: SocManager */
/* Message Sub: HandshakeRequest */
typedef struct
{
    uint8_t u8Reserved[4];
}IPC_S2M_POWERSocManagerHandshakeRequest_t;

/* Receive function of sub message HandshakeRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerHandshakeRequest_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHandshakeRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Heath */
typedef struct
{
    /*0-255:rolling counter*/
    uint8_t u8Reserved;
}IPC_S2M_POWERSocManagerHeath_t;

/* Receive function of sub message Heath */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerHeath_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHeath_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Reset */
typedef struct
{
    uint8_t u8Parameter;
    uint8_t u8Describe;
}IPC_S2M_POWERSocManagerReset_t;

/* Receive function of sub message Reset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerReset_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerReset_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: QnxResponseMCURequest */
typedef struct
{
    /*0x1: qnx close success
    0x2: receive mcu restartup qnx*/
    uint8_t QnxResponseMCURequest;
}IPC_S2M_POWERSocManagerQnxResponseMCURequest_t;

/* Receive function of sub message QnxResponseMCURequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerQnxResponseMCURequest_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxResponseMCURequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: QnxInfoMCUSystem */
typedef struct
{
    /*0x0:normal;0x1:minisys*/
    uint8_t u8Parameter;
}IPC_S2M_POWERSocManagerQnxInfoMCUSystem_t;

/* Receive function of sub message QnxInfoMCUSystem */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerQnxInfoMCUSystem_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxInfoMCUSystem_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: QnxQueryVersion */
typedef struct
{
    uint8_t u8Reserved;
}IPC_S2M_POWERSocManagerQnxQueryVersion_t;

/* Receive function of sub message QnxQueryVersion */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerQnxQueryVersion_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerQnxQueryVersion_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: PowerOFFReady */
typedef struct
{
    uint8_t u8Reserved;
}IPC_S2M_POWERSocManagerPowerOFFReady_t;

/* Receive function of sub message PowerOFFReady */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerPowerOFFReady_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerPowerOFFReady_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Healthset */
typedef struct
{
    /*0x0:off ; 0x1:on*/
    uint8_t u8Reserved;
}IPC_S2M_POWERSocManagerHealthset_t;

/* Receive function of sub message Healthset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSocManagerHealthset_Receive(uint8_t *receiveData, IPC_S2M_POWERSocManagerHealthset_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : POWER */
/* Message Major: SystemState */
/* Message Sub: IVI_State */
typedef struct
{
    /*0x0:not_ready;0x1:ready*/
    uint8_t TransferResponse;
}IPC_S2M_POWERSystemStateIVI_State_t;

/* Receive function of sub message IVI_State */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSystemStateIVI_State_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateIVI_State_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FOTASts */
typedef struct
{
    /*0x0:FOTAOFF;0x1:FOTAON*/
    uint8_t State;
}IPC_S2M_POWERSystemStateFOTASts_t;

/* Receive function of sub message FOTASts */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSystemStateFOTASts_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateFOTASts_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: GetSMSts */
typedef struct
{
    /*0x0:MCU;
    0x1:IVI;
    0x2:Cluster;
    0x3:HUD;
    0x4:Console£»
    0x5:KL15£»
    0x6:nm£»
    0x7:temp£»*/
    uint8_t State;
}IPC_S2M_POWERSystemStateGetSMSts_t;

/* Receive function of sub message GetSMSts */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSystemStateGetSMSts_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateGetSMSts_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: APP_INFOSM */
typedef struct
{
    /*0x01:local_timer
    0x02:nm_sts
    0x03:diagtomini
    0x04:DVRACK
    0x05:virtualevent*/
    uint8_t type;
    /*0x01:local_continue(type:1)
    0x01:nm_prebussleep_resp(type:2)
    0x02:nm_bussleep_resp(type:2)
    0x03:nm_normal_resp(type:2)
    0x00:diagtomini(type:3)£¨no callback msg£©
    0x00:usbshutdown(type:5)
    0x01:usbenable(type:5)
    0x02:camerashutdown(type:5)
    0x03:cameraenable(type:5)
    */
    uint8_t value;
}IPC_S2M_POWERSystemStateAPP_INFOSM_t;

/* Receive function of sub message APP_INFOSM */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_POWERSystemStateAPP_INFOSM_Receive(uint8_t *receiveData, IPC_S2M_POWERSystemStateAPP_INFOSM_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : POWER */
#ifdef __cplusplus
}
#endif

#endif
