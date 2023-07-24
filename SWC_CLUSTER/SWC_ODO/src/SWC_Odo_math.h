/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/
/**
**  Name:               SWC_Odo_Interface.c
**
**  Description:        Odo moudle interface file to oher.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_ODO_MATH_H
#define SWC_ODO_MATH_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
typedef union
{
	uint8 Byte_u8[4];
	uint32 LongValue_u32;
	struct
	{
		uint16 IntLow_u16;
		uint16 Inthigh_u16;
	}s_IhigInt_t;
}u_OdoUnion_t;

typedef union
{
	uint8 Byte_u8[5];
	struct
	{
		uint32 LongValue_u32;
		uint8 OverFlow_u8;
	}s_Parament_t;
	struct
	{
		uint16 IntLow_u16;
		uint16 Inthigh_u16;
		uint8 Dummy_u8;
	}s_IhigInt_t;
}u_OdoUnionWithOver_t;
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*Function   : ODO_MulUlongbyUbyte                                                                         *
*                                                                                                         *
*Description: Date amplification function                                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void ODO_MulUlongbyUbyte(u_OdoUnion_t *UlValue_u,u_OdoUnionWithOver_t *RsltValue_u,uint8 BValue_u8);

/**********************************************************************************************************
*Function   : Odo_DivUlongByByte                                                                          *
*                                                                                                         *
*Description: Date Zoom out function                                                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_DivUlongByByte(u_OdoUnionWithOver_t *UlValue_u, u_OdoUnion_t *RsltValue_u, uint8 BValue_u8);
#define SWC_ODO_STOP_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*#endif   Section End                                                                                     *
**********************************************************************************************************/

#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/




