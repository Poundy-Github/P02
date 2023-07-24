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

/**********************************************************************************************************
*File Name   : SWC_TC_Data.c                                                                             *
*                                                                                                         *
*Description : TripComputer module application source file.                                        *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_TC_DATE_C
#define SWC_TC_DATE_C 
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

#include "SWC_TC_Pkg_Cfg.h"
#include "SWC_TC_Date.h"

/**********************************************************************************************************
*																										  *
*																										  *
*				  Type Definition																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#define SWC_TC_START_SEC_CONST_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (TC_MAX_NUM_OF_DTE != 0) 	

#if (TC_DTE_RATE_OF_CHANGE_ENABLE != 0)
	#if (TC_RATE_OF_CHANGE_TABLE_NVM != 0)
		const uint8 TC_DTE_CALC_BOUND_NVM[TC_NO_OF_DTE_CALC_RANGE_PTS] = TC_DTE_CALC_RANGE_PTS;
		const TC_DTE_RATE_LUT TC_DTE_RATE_LUTS_NVM[TC_NO_OF_DTE_RATE_OF_CHANGE] = TC_DTE_RATE_OF_CHANGE;
  	#else
		const uint8 TC_DTE_CALC_BOUND_NVM[TC_NO_OF_DTE_CALC_RANGE_PTS] = TC_DTE_CALC_RANGE_PTS;
		const TC_DTE_RATE_LUT TC_DTE_RATE_LUTS_NVM[TC_NO_OF_DTE_RATE_OF_CHANGE] = TC_DTE_RATE_OF_CHANGE;
  	#endif
#endif

#endif
 
#if (TC_WEIGHTED_AFE_OPTION != 0) && (TC_MAX_NUM_OF_AFE != 0)
	const uint16 TC_WEIGHT_AFE_NVM      = TC_AFE_WEIGHT_AFE;
	const uint16 TC_WEIGHT_RAFE_NVM     = TC_AFE_WEIGHT_RAFE;
	const uint16 TC_WEIGHT_DIFF_NVM     = TC_AFE_WEIGHT_DIFF;
#endif/* End of TC_AFE_OPTION == 1 */

#define SWC_TC_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif 

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

