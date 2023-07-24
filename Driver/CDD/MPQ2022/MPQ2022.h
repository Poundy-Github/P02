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
 * @file:      MPQ2022.h
 * @author:    Nobo
 * @date:      2021-11-18
 * @brief:
 **********************************************************************************************************************
 * @attention:
	 *    1. date    : 2021-11-18
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/
#ifndef MPQ2022_H
#define MPQ2022_H

#include "MPQ2022_reg.h"

#include "IIC_Type.h"

typedef enum 
{
    eMPS2022_MIC_GNSS = 0,//address 0x21
    eMPS2022_ANT1_2= 1,//address 0x22
    eMPS2022_RVC = 2,//address 0x27
    eMPS2022_MAX
}eMPQ2022DeviceIndex_t;

#define MPQ2022_MIC_DEVICE_ID			(eMPS2022_MIC_GNSS)
#define MPQ2022_MIC_DEVICE_CHANEL_ID	(0)

#define MPQ2022_GNSS_DEVICE_ID			(eMPS2022_MIC_GNSS)
#define MPQ2022_GNSS_DEVICE_CHANEL_ID	(1)

#define MPQ2022_ANT1_DEVICE_ID			(eMPS2022_ANT1_2)
#define MPQ2022_ANT1_DEVICE_CHANEL_ID	(1)

#define MPQ2022_ANT2_DEVICE_ID			(eMPS2022_ANT1_2)
#define MPQ2022_ANT2_DEVICE_CHANEL_ID	(0)

#define MPQ2022_RVC_DEVICE_ID			(eMPS2022_RVC)
#define MPQ2022_RVC_DEVICE_CHANEL_ID	(0)


//MIC_GNSS : IIC RX/TX callback
extern void MPQ2022_MIC_GNSS_I2CTx_Callback(IIC_ResultStatus_t state);
extern void MPQ2022_MIC_GNSS_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size);
//ANT1_2 : IIC RX/TX callback
extern void MPQ2022_ANT1_2_I2CTx_Callback(IIC_ResultStatus_t state);
extern void MPQ2022_ANT1_2_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size);
//RVC : IIC RX/TX callback
extern void MPQ2022_RVC_I2CTx_Callback(IIC_ResultStatus_t state);
extern void MPQ2022_RVC_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size);


extern void TM_Timer1msStartStamp(uint32 * StartStamp);
#define MPQ2022_GET_OSTick(X)		TM_Timer1msStartStamp(X)


extern uint16 MPQ22022_MIC_V_GET(void);//mv
extern uint16 MPQ22022_MIC_I_GET(void);//mA

extern uint16 MPQ22022_GNSS_V_GET(void);//mv
extern uint16 MPQ22022_GNSS_I_GET(void);//mA

extern uint16 MPQ22022_ANT1_V_GET(void);//mv
extern uint16 MPQ22022_ANT1_I_GET(void);//mA

extern uint16 MPQ22022_ANT2_V_GET(void);//mv
extern uint16 MPQ22022_ANT2_I_GET(void);//mA

extern uint16 MPQ22022_RVC_V_GET(void);//mv
extern uint16 MPQ22022_RVC_I_GET(void);//mA



extern void MPQ2022_MICPowerSet(boolean set);
extern boolean MPQ2022_MICDTC_Check(uint8 stsId);

extern void MPQ2022_GNSSPowerSet(boolean set);
extern boolean MPQ2022_GNSSDTC_Check(uint8 stsId);

extern void MPQ2022_ANT1PowerSet(boolean set);
extern void MPQ2022_ANT2PowerSet(boolean set);
extern boolean MPQ2022_ANTDTC_Check(uint8 sen,uint8 stsId);

extern void MPQ2022_RVCPowerSet(boolean set);
extern boolean MPQ2022_RVCDTC_Check(uint8 stsId);

extern void MPQ2022_MainFunction(eMPQ2022DeviceIndex_t deviceIdx);

extern boolean MPQ2022_AllStartUpDone(void);

extern boolean MPQ2022_AllEventDealDone(void);

#endif
