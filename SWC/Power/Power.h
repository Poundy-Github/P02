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
 * @file:      Power.h
 * @author:    Nobo
 * @date:      2020-5-28
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-28
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef __POWER_H_
#define __POWER_H_

#include "IPC_Power.h"
#include "Rte_Power_Type.h"
#include "Rte_Power.h"

/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
#define POWER_START_SEC_CODE
#include "Power_MemMap.h"


extern FUNC(void, Power_CODE) Power_MainFunction(void);
extern FUNC(void, Power_CODE) power_Init(void);

#include "Dio.h"
#define POWER_SET_USB_EN()         do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_HIGH);}while(0)
#define POWER_SET_USB_DIS()        do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_LOW);}while(0)

// 0.5mA
#define POWER_SET_USB_SDP()         do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_LOW);}while(0)
// 1.5mA
#define POWER_SET_USB_CDP()        do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_HIGH);}while(0)

#define POWER_SET_RVC_EN()          do{Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN,STD_HIGH);}while(0)
#define POWER_SET_RVC_DIS()         do{Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN,STD_LOW);}while(0)
#define POWER_STOP_SEC_CODE

//SDP:suport USB protocol and IoutMax=500mA , used for such as nomal USB
//DCP:not support USB protocol , but IoutMax very large
//CDP:support USB protocol and IoutMax very large , used for IPad or telephone 
//Client:suport USB protocol , but IoutMax=0 

//=HW was C3
#define POWER_ON_MPQ9841GLE()      	do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_HIGH);}while(0)
#define POWER_OFF_MPQ9841GLE()     	do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_LOW);}while(0)

#define POWER_ON_MPQ5073GG()   		do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_HIGH);}while(0)
#define POWER_OFF_MPQ5073GG()  		do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_LOW);}while(0)

//==HW was C2
#define POWER_ON_MPQ4228GRE()      	do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_HIGH);}while(0)
#define POWER_OFF_MPQ4228GRE()     	do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN,STD_LOW);}while(0)

#define POWER_ON_MPQ4228GRE_CTRL1()  do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1,STD_HIGH);}while(0)
#define POWER_OFF_MPQ4228GRE_CTRL1() do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1,STD_LOW);}while(0)

#define POWER_ON_MPQ4228GRE_CTRL2()  do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_HIGH);}while(0)
#define POWER_OFF_MPQ4228GRE_CTRL2() do{Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2,STD_LOW);}while(0)

#include "Power_MemMap.h"


#endif
