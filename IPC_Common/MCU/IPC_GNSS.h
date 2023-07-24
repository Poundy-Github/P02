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
*                 File:  IPC_GNSS.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_MCU.h.tem
*          Description:  IPC group GNSS  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef _IPC_GNSS_H_
#define _IPC_GNSS_H_

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_GNSS_ID                                                        (129u)

/* MCU to SOC Message major id */
#define IPC_M2S_GNSS_MSGMAJOR_SERIANET_ID                                        (0u)
#define IPC_M2S_GNSS_MSGMAJOR_NMEA_ID                                            (1u)
#define IPC_M2S_GNSS_MSGMAJOR_NAV_ID                                             (2u)
#define IPC_M2S_GNSS_MSGMAJOR_FRAMELOSS_ID                                       (3u)
#define IPC_M2S_GNSS_MSGMAJOR_CONFIG_ID                                          (4u)
/* MCU to SOC Message sub id */
#define IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_ID                                     (0u)
#define IPC_M2S_GNSS_NMEA_MSGSUB_DATA_ID                                         (0u)
#define IPC_M2S_GNSS_NAV_MSGSUB_DATA_ID                                          (0u)
#define IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_ID                                    (0u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_ID                                  (0u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_ID                                   (1u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_ID                             (2u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_ID                               (3u)
/* MCU to SOC Message sub length */
#define IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH                                 (130u)
#define IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_LENGTH_MIN                             (2u)
#define IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_FLEX_NUMBER                            (128u)
#define IPC_M2S_GNSS_NMEA_MSGSUB_DATA_LENGTH                                     (1u)
#define IPC_M2S_GNSS_NAV_MSGSUB_DATA_LENGTH                                      (1u)
#define IPC_M2S_GNSS_FRAMELOSS_MSGSUB_DATA_LENGTH                                (2u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_NMEA_DATA_LENGTH                              (1u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_NAV_DATA_LENGTH                               (1u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_FRAMELOSS_DATA_LENGTH                         (2u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH                           (130u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_LENGTH_MIN                       (2u)
#define IPC_M2S_GNSS_CONFIG_MSGSUB_PDTINFO_DATA_FLEX_NUMBER                      (128u)


/* SOC to MCU Message major id */
#define IPC_S2M_GNSS_MSGMAJOR_RESERVED_ID                                        (0u)
#define IPC_S2M_GNSS_MSGMAJOR_NMEA_ID                                            (1u)
#define IPC_S2M_GNSS_MSGMAJOR_NAV_ID                                             (2u)
#define IPC_S2M_GNSS_MSGMAJOR_FRAMELOSS_ID                                       (3u)
#define IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID                                          (4u)
/* SOC to MCU Message sub id */
#define IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_ID                                 (0u)
#define IPC_S2M_GNSS_NMEA_MSGSUB_READ_ID                                         (0u)
#define IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_ID                                        (1u)
#define IPC_S2M_GNSS_NAV_MSGSUB_READ_ID                                          (0u)
#define IPC_S2M_GNSS_NAV_MSGSUB_WRITE_ID                                         (1u)
#define IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_ID                                    (0u)
#define IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_ID                                   (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_ID                                  (0u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_ID                                 (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_ID                                   (2u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_ID                                  (3u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_ID                             (4u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_ID                            (5u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_ID                               (6u)
/* SOC to MCU Message sub length */
#define IPC_S2M_GNSS_RESERVED_MSGSUB_RESERVED_LENGTH                             (1u)
#define IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH                                     (1u)
#define IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH                                    (1u)
#define IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH                                      (1u)
#define IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH                                     (1u)
#define IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH                                (2u)
#define IPC_S2M_GNSS_FRAMELOSS_MSGSUB_WRITE_LENGTH                               (2u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH                              (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH                             (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH                               (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH                              (1u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH                         (2u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH                        (2u)
#define IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH                           (1u)
/* Group: : GNSS */
/* Message Major: SeriaNet */
/* Message Sub: Data */
typedef struct
{
    uint16_t BufferLength;
    uint8_t Buffer[128];
}IPC_M2S_GNSSSeriaNetData_t;

/* Transmit function of sub message Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSSeriaNetData_Transmit(IPC_M2S_GNSSSeriaNetData_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: NMEA */
/* Message Sub: Data */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_M2S_GNSSNMEAData_t;

/* Transmit function of sub message Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSNMEAData_Transmit(IPC_M2S_GNSSNMEAData_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: NAV */
/* Message Sub: Data */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_M2S_GNSSNAVData_t;

/* Transmit function of sub message Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSNAVData_Transmit(IPC_M2S_GNSSNAVData_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: FrameLoss */
/* Message Sub: Data */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_M2S_GNSSFrameLossData_t;

/* Transmit function of sub message Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSFrameLossData_Transmit(IPC_M2S_GNSSFrameLossData_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: Config */
/* Message Sub: NMEA_Data */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_M2S_GNSSConfigNMEA_Data_t;

/* Transmit function of sub message NMEA_Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSConfigNMEA_Data_Transmit(IPC_M2S_GNSSConfigNMEA_Data_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NAV_Data */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_M2S_GNSSConfigNAV_Data_t;

/* Transmit function of sub message NAV_Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSConfigNAV_Data_Transmit(IPC_M2S_GNSSConfigNAV_Data_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FrameLoss_Data */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_M2S_GNSSConfigFrameLoss_Data_t;

/* Transmit function of sub message FrameLoss_Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSConfigFrameLoss_Data_Transmit(IPC_M2S_GNSSConfigFrameLoss_Data_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: PDTINFO_Data */
typedef struct
{
    uint16_t PDTINFODataLength;
    /*the gnss PDTINFO*/
    uint8_t PDTINFOData[128];
}IPC_M2S_GNSSConfigPDTINFO_Data_t;

/* Transmit function of sub message PDTINFO_Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_GNSSConfigPDTINFO_Data_Transmit(IPC_M2S_GNSSConfigPDTINFO_Data_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Group: : GNSS */
/* Message Major: Reserved */
/* Message Sub: reserved */
typedef struct
{
    uint8_t reserved;
}IPC_S2M_GNSSReservedreserved_t;

/* Receive function of sub message reserved */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSReservedreserved_Receive(uint8_t *receiveData, IPC_S2M_GNSSReservedreserved_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: NMEA */
/* Message Sub: Read */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_S2M_GNSSNMEARead_t;

/* Receive function of sub message Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSNMEARead_Receive(uint8_t *receiveData, IPC_S2M_GNSSNMEARead_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Write */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_S2M_GNSSNMEAWrite_t;

/* Receive function of sub message Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSNMEAWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSNMEAWrite_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: NAV */
/* Message Sub: Read */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_S2M_GNSSNAVRead_t;

/* Receive function of sub message Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSNAVRead_Receive(uint8_t *receiveData, IPC_S2M_GNSSNAVRead_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Write */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_S2M_GNSSNAVWrite_t;

/* Receive function of sub message Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSNAVWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSNAVWrite_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: FrameLoss */
/* Message Sub: Read */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_S2M_GNSSFrameLossRead_t;

/* Receive function of sub message Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSFrameLossRead_Receive(uint8_t *receiveData, IPC_S2M_GNSSFrameLossRead_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Write */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_S2M_GNSSFrameLossWrite_t;

/* Receive function of sub message Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSFrameLossWrite_Receive(uint8_t *receiveData, IPC_S2M_GNSSFrameLossWrite_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
/* Message Major: Config */
/* Message Sub: NMEA_Read */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_S2M_GNSSConfigNMEA_Read_t;

/* Receive function of sub message NMEA_Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigNMEA_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNMEA_Read_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NMEA_Write */
typedef struct
{
    /*0x0:NMEA 3.0;
    0x1:NMEA 4.0;
    0x2:NMEA 4.1;*/
    uint8_t NmeaVersion;
}IPC_S2M_GNSSConfigNMEA_Write_t;

/* Receive function of sub message NMEA_Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigNMEA_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNMEA_Write_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NAV_Read */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_S2M_GNSSConfigNAV_Read_t;

/* Receive function of sub message NAV_Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigNAV_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNAV_Read_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NAV_Write */
typedef struct
{
    /*0x0:frequncy is 1HZ;
    0x1:frequncy is 2HZ;
    0x2:frequncy is 5HZ;*/
    uint8_t NAVData;
}IPC_S2M_GNSSConfigNAV_Write_t;

/* Receive function of sub message NAV_Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigNAV_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigNAV_Write_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FrameLoss_Read */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_S2M_GNSSConfigFrameLoss_Read_t;

/* Receive function of sub message FrameLoss_Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigFrameLoss_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigFrameLoss_Read_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FrameLoss_Write */
typedef struct
{
    /*the number of loss frame*/
    uint16_t FrameLossNum;
}IPC_S2M_GNSSConfigFrameLoss_Write_t;

/* Receive function of sub message FrameLoss_Write */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigFrameLoss_Write_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigFrameLoss_Write_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: PDTINFO_Read */
typedef struct
{
    /*the gnss PDTINFO*/
    uint8_t PDTINFORead;
}IPC_S2M_GNSSConfigPDTINFO_Read_t;

/* Receive function of sub message PDTINFO_Read */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_GNSSConfigPDTINFO_Read_Receive(uint8_t *receiveData, IPC_S2M_GNSSConfigPDTINFO_Read_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : GNSS */
#ifdef __cplusplus
}
#endif

#endif
