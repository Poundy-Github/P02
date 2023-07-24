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
 * @file:      AMP_LCCalib.h
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

#ifndef AMP_LCCALIB_H
#define AMP_LCCALIB_H

#include "AMP_Cfg.h"
#include <stdio.h>

#define AMPCALIBINIT                                                        (0u)
#define AMPCALIBSUCCESS                                                     (1u)
#define AMPCALIBERR                                                         (2u)
#define AMPCALIBPENGDING                                                    (3u)

#define AMPDIAGCALIB_SUCCESS                                                (0u)
#define AMPDIAGCALIB_VOLTAGEOUTOFRANGE                                      (1u)
#define AMPDIAGCALIB_TEMPOUTOFRANGE                                         (2u)
#define AMPDIAGCALIB_KDELTAOUTOFRANGE                                       (3u)
#define AMPDIAGCALIB_CALIBINPROCESS                                         (4u)
#define AMODIAGCALIB_NOTCALIB			                                    (5u)
#define AMODIAGCALIB_NOTSUPPORT                                             (6u)
#define AMPDIAGCALIB_CHANNELERR                                             (7u)
#define AMPDIAGCALIB_FILTERERR                                              (8u)
#define AMPDIAGCALIB_KVALERR                                                (9u)
#define AMODIAGCALIB_IICERR                                                 (10u)

#define AMP_CALIBLOG(...)        do{\
    (void)Logger_String(LOGGER_MODULE_AMP, LOGGER_LEVEL_INFO, __VA_ARGS__);\
} while(0);


#define P(x) {AMP_CALIBLOG("%s 0x%x", #x, x)}

typedef struct
{
    uint8 Kvalue;
    uint8 Kmin;
    uint8 Kmax;
}s_FilterDiagResult_Type;

typedef struct
{
    boolean LCNVMPending;
    boolean LCCalibRequest;
    uint16 voltage;/*can use temp var*/
    sint16 tempeture;/*can use temp var*/
}s_LCCalib_Info_Type;


typedef union {
    uint8 Data;
    struct{
        uint8 voltagehigh   :1;
        uint8 voltagelow    :1;
        uint8 tempeturehigh :1;
        uint8 tempeturelow  :1;
        uint8 devicestateerr:1;
        uint8 DeviceFault   :1;
        uint8 reserved      :2;
    }Alarm;
}u_AMPCalibDeviceErr_t;

typedef union{
    uint8 Data;
    struct{
        uint8 ChannelErr    :1;
        uint8 FilterErr     :1;
        uint8 KminErr       :1;
        uint8 KmaxErr       :1;
        uint8 KvalErr       :1;
        uint8 KOutofRange   :1;
        uint8 Supported     :2;
    }Alarm;
}u_AMPCalibChannelErr_t;

typedef struct
{
    uint8                   KSet[CHANNEL_NUM];
    s_FilterDiagResult_Type FilterDiagResult[CHANNEL_NUM];
    e_LCCalibEnum_t         LCCalibStep;
    u_AMPCalibDeviceErr_t   DeviceAlarm;
    u_AMPCalibChannelErr_t  ChannelAlarm[CHANNEL_NUM];
    uint8                   LCCalibRet;
}s_LCCalib_Type;



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


extern Std_ReturnType LCCalib_MainLogic(uint8 dev_id);
extern void LCCalib_Init(uint8 dev_id);
extern void LCCalibNVMWriteDone(uint8 dev_id);
extern void AMPDiag_LCCalibLogic(void);
extern void EOLDataReport(A_U8_10 *ptr);
extern void DIDDataReport(void);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#endif

