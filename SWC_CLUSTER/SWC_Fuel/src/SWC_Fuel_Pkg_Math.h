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
/***********************************************************************************************************
**
**  Name:               SWC_Fuel_Pkg_Math.c
**
**  Description:        Implentation module for linear interpolation software.
**                     See comments below for more details.
**
** Organization:       
**
**********************************************************************************************************/

#ifndef LINEWORD_H
#define LINEWORD_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define FUEL_TESTBIT( operand, bit_mask )        	(((operand) & (bit_mask)) != 0u)
#define FUEL_SETBIT( operand, bit_mask )         	((operand) |= (bit_mask))
#define FUEL_CLEARBIT( operand, bit_mask )       	((operand) &= (~(bit_mask)))
#define FUEL_TOGGLEBIT( operand, bit_mask )      	((operand) ^= (bit_mask))

#define FUEL_NOTTESTBIT( operand, bit_mask ) 		(((operand) &  (bit_mask)) == ((bit_mask) - (bit_mask)))

#define FUEL_MS_8_BITS( w )                      	((uint8)((w) >> (8)))
#define FUEL_MS_16_BITS( l )                     	((uint16)((l) >> (16)))
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint16 LinearInterpolateWord(uint16 *table, uint16 lookupVal);

/**********************************************************************************************************
*Function   : FILTER_2B_AVERAGE                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 * queue,uint16 new,uint8 sum)												          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint16 FILTER_2B_AVERAGE(uint16 * queue,uint16 new,uint8 sum);

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
#endif
