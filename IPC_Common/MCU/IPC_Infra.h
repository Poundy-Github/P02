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
*                 File:  IPC_Infra.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group Infra  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_INFRA_H_
#define _IPC_INFRA_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_INFRA_ID                                                       (17u)

/* MCU to SOC Message major id */
#define IPC_M2S_INFRA_MSGMAJOR_MISC_ID                                           (0u)
/* MCU to SOC Message sub id */
#define IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_ID               (0u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_ID                    (1u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_ID                       (2u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_ID                          (3u)
/* MCU to SOC Message sub length */
#define IPC_M2S_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGRESPONSE_LENGTH           (1u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH                (52u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_LENGTH_MIN            (2u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READSERIALNUMBERRESPONSE_FLEX_NUMBER           (50u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH                   (52u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_LENGTH_MIN               (2u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READVINNUMBERRESPONSE_FLEX_NUMBER              (50u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH                      (53u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_LENGTH_MIN                  (3u)
#define IPC_M2S_INFRA_MISC_MSGSUB_READBEANIDRESPONSE_FLEX_NUMBER                 (50u)


/* SOC to MCU Message major id */
#define IPC_S2M_INFRA_MSGMAJOR_MISC_ID                                           (0u)
/* SOC to MCU Message sub id */
#define IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_ID                (0u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_ID                     (1u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_ID                        (2u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_ID                           (3u)
#define IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_ID                         (4u)
/* SOC to MCU Message sub length */
#define IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_LENGTH            (1u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_LENGTH                 (1u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_LENGTH                    (1u)
#define IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_LENGTH                       (1u)
#define IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_LENGTH                     (1u)
/* Group: : Infra */
/* Message Major: Misc */
/* Message Sub: RestoreFactorySettingResponse */
typedef struct
{
    /*0x01 : Finish restore factory setting £¬other £ºreserved*/
    uint8_t Response;
}IPC_M2S_InfraMiscRestoreFactorySettingResponse_t;

/* Transmit function of sub message RestoreFactorySettingResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_InfraMiscRestoreFactorySettingResponse_Transmit(IPC_M2S_InfraMiscRestoreFactorySettingResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadSerialNumberResponse */
typedef struct
{
    uint16_t DataLength;
    /*serial number data, max length 50 byte*/
    uint8_t Data[50];
}IPC_M2S_InfraMiscReadSerialNumberResponse_t;

/* Transmit function of sub message ReadSerialNumberResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_InfraMiscReadSerialNumberResponse_Transmit(IPC_M2S_InfraMiscReadSerialNumberResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadVINNumberResponse */
typedef struct
{
    uint16_t DataLength;
    /*VIN number data, max length 50 byte*/
    uint8_t Data[50];
}IPC_M2S_InfraMiscReadVINNumberResponse_t;

/* Transmit function of sub message ReadVINNumberResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_InfraMiscReadVINNumberResponse_Transmit(IPC_M2S_InfraMiscReadVINNumberResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadBeanIDResponse */
typedef struct
{
    uint16_t DataLength;
    /*0x0-Vaild,0x1-Inxaild;*/
    uint8_t Status;
    /*Data[0]-Data[22]:Bean ID;other : reserved
    */
    uint8_t Data[50];
}IPC_M2S_InfraMiscReadBeanIDResponse_t;

/* Transmit function of sub message ReadBeanIDResponse */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_InfraMiscReadBeanIDResponse_Transmit(IPC_M2S_InfraMiscReadBeanIDResponse_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Infra */
/* Group: : Infra */
/* Message Major: Misc */
/* Message Sub: RestoreFactorySettingRequset */
typedef struct
{
    /*0x01 : Start restore factory setting £¬other £ºreserved*/
    uint8_t Request;
}IPC_S2M_InfraMiscRestoreFactorySettingRequset_t;

/* Receive function of sub message RestoreFactorySettingRequset */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_InfraMiscRestoreFactorySettingRequset_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadSerialNumberRequest */
typedef struct
{
    /*0x01:request read serial number, other : reserved*/
    uint8_t Request;
}IPC_S2M_InfraMiscReadSerialNumberRequest_t;

/* Receive function of sub message ReadSerialNumberRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_InfraMiscReadSerialNumberRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadSerialNumberRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadVINNumberRequest */
typedef struct
{
    /*0x01:request read VIN number, other : reserved*/
    uint8_t Request;
}IPC_S2M_InfraMiscReadVINNumberRequest_t;

/* Receive function of sub message ReadVINNumberRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_InfraMiscReadVINNumberRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadVINNumberRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ReadBeanIDRequest */
typedef struct
{
    /*0x0:No action,0x1:Request,0x2:Clear Data,other : reserved*/
    uint8_t Request;
}IPC_S2M_InfraMiscReadBeanIDRequest_t;

/* Receive function of sub message ReadBeanIDRequest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_InfraMiscReadBeanIDRequest_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscReadBeanIDRequest_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetAVASSwitchStatus */
typedef struct
{
    /*0x01:ON,0x0:OFF,other : reserved*/
    uint8_t Switch;
}IPC_S2M_InfraMiscSetAVASSwitchStatus_t;

/* Receive function of sub message SetAVASSwitchStatus */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_InfraMiscSetAVASSwitchStatus_Receive(uint8_t *receiveData, IPC_S2M_InfraMiscSetAVASSwitchStatus_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : Infra */
#ifdef __cplusplus
}
#endif

#endif
