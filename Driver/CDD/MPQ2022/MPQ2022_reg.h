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
 * @file:      MPQ2022_reg.h
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
#ifndef MPQ2022_REG_H
#define MPQ2022_REG_H

#include "Std_Types.h"

//address ： 0X00
typedef union{
    uint8 unionData;
    struct{
        uint8 RSV    		:8;
    }DEV_REV_BITS;
}u_DEV_REV_t;
//address ： 0X01  [Read only]
typedef union{
    uint8 unionData;
    struct{
		uint8 POR	 		:1;	
		uint8 I2C_ERR	 	:1;//1: I2C communication error occurred
		uint8 FT_ASSERT	 	:1;
		uint8 VOUT2_PG	 	:1;//1: LDO 2 output voltage is power good
		uint8 VOUT1_PG	 	:1;//1: LDO 1 output voltage is power good
		uint8 LDO_2_ACTIVE	:1;//1: LDO 2 is active
		uint8 LDO_1_ACTIVE	:1;//1: LDO 1 is active
		uint8 RSV			:1;	
    }DEV_STAT_BITS;
}u_DEV_STAT_t;
//address ： 0X02  [Read only]
typedef union{
    uint8 unionData;
    struct{
		uint8 LDO_2_StB		:1;	//1: Short-to-battery detected on LDO_2
		uint8 LDO_1_StB	 	:1;//1: Short-to-battery detected on LDO_1
		uint8 RSV2		 	:1;
		uint8 RSV1		 	:1;
		uint8 VOUT_2_UV	 	:1;//1: Under voltage detected on OUT2
		uint8 VOUT_2_OV		:1;//1: Over voltage detected on OUT2
		uint8 VOUT_1_UV		:1;//1: Under voltage detected on OUT1
		uint8 VOUT_1_OV 	:1;//1: Over voltage detected on OUT1
    }ERR_FLAG_1_BITS;
}u_ERR_FLAG_1_t;
//address ： 0X03  [Read only]
typedef union{
    uint8 unionData;
    struct{
		uint8 RSV2		 	:4;
		uint8 OT		 	:1;//1: Over temperature detected
		uint8 RSV1			:1;
		uint8 LDO_2_OC		:1;//1: Over current detected on OUT2
		uint8 LDO_1_OC		:1;//1: Over current detected on OUT1
    }ERR_FLAG_2_BITS;
}u_ERR_FLAG_2_t;
//address ： 0X04  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 FAULT_HANDLE	:1;	//0: Latch mode , 1: Hiccup with 100ms blanking time
		uint8 RSV2		 	:1;
		uint8 SOFT_RST		:1;
		uint8 ADC_EN	 	:1;//0: ADC is disable , 1: ADC is enable
		uint8 SHUTDOWN	 	:1;//0: Turn on device if EN pin = high , 1: Device is forced shutdown
		uint8 LDO_2_EN		:1;//0: LDO 2 is disabled , 1: LDO 2 is enabled
		uint8 LDO_1_EN		:1;//0: LDO 1 is disabled , 1: LDO 1 is enabled
		uint8 RSV1			:1;	
    }DEV_CTRL_BITS;
}u_DEV_CTRL_t;
//address ： 0X05  [Read only]
typedef union{
    uint8 unionData;
    struct{
        uint8 VOUT1_MON			:8;//Lsb=55mV; VOUT1_MON = D[7:0]*55mV
    }MON_VOUT_1_BITS;
}u_MON_VOUT_1_t;
//address ： 0X06  [Read only]
typedef union{
    uint8 unionData;
    struct{
        uint8 VOUT2_MON			:8;//Lsb=55mV; VOUT2_MON = D[7:0]*55mV
    }MON_VOUT_2_BITS;
}u_MON_VOUT_2_t;
//address ： 0X07  [Read only]
typedef union{
    uint8 unionData;
    struct{
        uint8 IOUT1_MON			:8;//Lsb=1.2mA; IOUT1_MON = D[7:0]*1.2mA.
    }MON_IOUT_1_BITS;
}u_MON_IOUT_1_t;
//address ： 0X08  [Read only]
typedef union{
    uint8 unionData;
    struct{
        uint8 IOUT2_MON			:8;//Lsb=1.2mA; IOUT2_MON = D[7:0]*1.2mA.
    }MON_IOUT_2_BITS;
}u_MON_IOUT_2_t;
//address ： 0X09  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 VOUT1_SET		:6;//Vout=1V+ D[5:0]*step
		uint8 VOUT1_STEP	:1;//step voltage : 0->100mV , 1->200mV
		uint8 FAULT_CLEAR	:1;//0:no action , 1:clear all fault flag
    }SET_VOUT_1_BITS;
}u_SET_VOUT_1_t;
//address ： 0X0A  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 VOUT2_SET		:6;//Vout=1V+ D[5:0]*step
		uint8 VOUT2_STEP	:1;//step voltage : 0->100mV , 1->200mV
		uint8 POWER_SEQ 	:1;	
    }SET_VOUT_2_BITS;
}u_SET_VOUT_2_t;

//address ： 0X0B  [Read and Write]   RSVD
//address ： 0X0C  [Read and Write]   RSVD

//address ： 0X0D  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 VOUT2_PG_L_THR	:1;	
		uint8 VOUT2_PG_H_THR	:1;
		uint8 VOUT1_PG_L_THR	:1;//lower boundary of OUT1 PG threshold: 0->90% , 1->95%
		uint8 VOUT1_PG_H_THR	:1;//upper boundary of OUT1 PG threshold: 0->105% , 1->110%
		uint8 VOUT2_UV_THR	 	:1;
		uint8 VOUT2_OV_THR		:1;
		uint8 VOUT1_UV_THR		:1;//under voltage threshold: 0->75% , 1->80%
		uint8 VOUT1_OV_THR		:1;//over voltage threshold: 0->115% , 1->120%
    }SET_PG_UVOV_BITS;
}u_SET_PG_UVOV_t;
//address ： 0X0E  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 IOUT_1_OC_THR	 	:5;//Lsb=6.25mA; Ilimit= D[4:0]*6.25mA+OC_MIN
		uint8 RSV1				:1;
		uint8 LDO2_TRC			:1;//LDO2 tracking mode : 0 -> dis enabled ,1 -> enabled
		uint8 LDO1_TRC			:1;//LDO1 tracking mode : 0 -> dis enabled ,1 -> enabled
    }SET_IOUT_LIM_1_BITS;
}u_SET_IOUT_LIM_1_t;
//address ： 0X0F  [Read and Write]
typedef union{
    uint8 unionData;
    struct{
		uint8 IOUT_2_OC_THR		:5;//Lsb=6.25mA; Ilimit= D[4:0]*6.25mA+OC_MIN
		uint8 OC_MIN			:1;//0:300mA 1:100mA
		uint8 RSV1				:2;
    }SET_IOUT_LIM_2_BITS;
}u_SET_IOUT_LIM_2_t;

typedef enum 
{
    eMPS2022_REG_ID_DEV_REV = 0,
    eMPS2022_REG_ID_DEV_STAT,
    eMPS2022_REG_ID_ERR_FLAG_1,
    eMPS2022_REG_ID_ERR_FLAG_2,
    eMPS2022_REG_ID_DEV_CTRL,
    eMPS2022_REG_ID_MON_VOUT_1,
    eMPS2022_REG_ID_MON_VOUT_2,
    eMPS2022_REG_ID_MON_IOUT_1,
    eMPS2022_REG_ID_MON_IOUT_2,
    eMPS2022_REG_ID_SET_VOUT_1,
    eMPS2022_REG_ID_SET_VOUT_2,
    eMPS2022_REG_ID_RSV1,
    eMPS2022_REG_ID_RSV2,
    eMPS2022_REG_ID_SET_PG_UVOV,
    eMPS2022_REG_ID_SET_IOUT_LIM_1,
    eMPS2022_REG_ID_SET_IOUT_LIM_2,
    eMPS2022_REG_DEV_REV_ID_MAX
}eMPQ2022RegId_t;

typedef struct
{
	//device register
    u_DEV_REV_t  DEV_REV;				//address 0x00 [R] default :00h
    u_DEV_STAT_t DEV_STAT;				//address 0x01 [R] default :00h
	u_ERR_FLAG_1_t ERR_FLAG_1;			//address 0x02 [R] default :00h
	u_ERR_FLAG_2_t ERR_FLAG_2;			//address 0x03 [R] default :00h
	u_DEV_CTRL_t   DEV_CTRL;			//address 0x04 [W/R] default :61h
	u_MON_VOUT_1_t	MON_VOUT_1;			//address 0x05 [R] default :00h
	u_MON_VOUT_2_t	MON_VOUT_2;			//address 0x06 [R] default :00h
	u_MON_IOUT_1_t  MON_IOUT_1;			//address 0x07 [R] default :00h
	u_MON_IOUT_2_t  MON_IOUT_2;			//address 0x08 [R] default :00h
	u_SET_VOUT_1_t	SET_VOUT_1;			//address 0x09 [W/R] default :68h
	u_SET_VOUT_2_t	SET_VOUT_2;			//address 0x0A [W/R] default :68h
	uint8			RSV[2];				//address 0x0B 0x0C [W/R] default :78h 4Ch
	u_SET_PG_UVOV_t	SET_PG_UVOV;		//address 0x0D [W/R] default :00h
	u_SET_IOUT_LIM_1_t	SET_IOUT_LIM_1;	//address 0x0E [W/R] default :10h
	u_SET_IOUT_LIM_2_t	SET_IOUT_LIM_2;	//address 0x0F [W/R] default :10h
	//app used variable
}s_MPQ2022DeviceRegs_t;

//at default value
//1.LDO_1 and LDO_2 are enabled
//2.LDO1 Step Was 200mV , Vo1 = 1+40*200 =9V , IoLim = 16*6.25 + 300 = 400mA
//3.LDO2 Step Was 200mV , Vo2 = 1+40*200 =9V , IoLim = 16*6.25 + 300 = 400mA
//4.FAULT_HANDLE Was 1: Hiccup with 100ms blanking time

#define MPQ2022_RegDefaultVlu  {\
0x00,\
0x00,\
0x00,\
0x00,\
0x61,\
0x00,\
0x00,\
0x00,\
0x00,\
0x68,\
0x68,\
0x78,\
0x4C,\
0x00,\
0x10,\
0x10,\
}

#endif
