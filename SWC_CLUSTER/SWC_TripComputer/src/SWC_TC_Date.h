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
*File Name   : SWC_TC_Data.h                                                                             *
*                                                                                                         *
*Description : TripComputer module application interface head file.                                        *
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
#ifndef SWC_TC_DATE_H
#define SWC_TC_DATE_H 
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Pkg_Cfg.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TC_START_SEC_CONST_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (TC_MAX_NUM_OF_DTE != 0) 

	#if (TC_DTE_RATE_OF_CHANGE_ENABLE == 1)
		typedef struct
		{
		  uint8 TC_Delta_Rate;
		  uint8 TC_Rate_Of_Change[TC_NO_OF_DTE_CALC_RANGE_PTS + 1];
		}TC_DTE_RATE_LUT;
	#endif

	#if (TC_DTE_RATE_OF_CHANGE_ENABLE == 1)
		#if (TC_RATE_OF_CHANGE_TABLE_NVM == 1)
			extern const uint8 TC_DTE_CALC_BOUND_NVM[TC_NO_OF_DTE_CALC_RANGE_PTS];
			extern const TC_DTE_RATE_LUT TC_DTE_RATE_LUTS_NVM[TC_NO_OF_DTE_RATE_OF_CHANGE];
		#else
			extern const uint8 TC_DTE_CALC_BOUND_NVM[TC_NO_OF_DTE_CALC_RANGE_PTS];
			extern const TC_DTE_RATE_LUT TC_DTE_RATE_LUTS_NVM[TC_NO_OF_DTE_RATE_OF_CHANGE];
		#endif
	#endif

#endif 

#if (TC_WEIGHTED_AFE_OPTION != 0) && (TC_MAX_NUM_OF_AFE != 0)
	extern const uint16 TC_WEIGHT_AFE_NVM;
	extern const uint16 TC_WEIGHT_RAFE_NVM;
	extern const uint16 TC_WEIGHT_DIFF_NVM;
#endif

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
