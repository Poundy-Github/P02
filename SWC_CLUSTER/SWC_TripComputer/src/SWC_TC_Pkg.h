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
*File Name   : SWC_TC_Pkg.h                                                                             *
*                                                                                                         *
*Description : TripComputer module pakage interface head file.                                        *
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
#ifndef SWC_TC_PKG_H
#define SWC_TC_PKG_H  
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Process.h" 

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

#define TC_AFE_US_MPG_DISPLAY          			(0)
#define TC_AFE_KMPL_DISPLAY          			(1)
#define TC_AFE_L_PER_100KM_DISPLAY          	(2)
#define TC_AFE_UK_MPG_DISPLAY					(3)

#define TC_AVS_MPH_DISPLAY                     	(0)
#define TC_AVS_KMPH_DISPLAY					   	(1)
												
#define TC_DTE_MILES_DISPLAY                   	(0)
#define TC_DTE_KM_DISPLAY					   	(1)

#define TC_IFF_US_GPH_DISPLAY                  	(0)
#define TC_IFF_LPH_DISPLAY                     	(1)
#define TC_IFF_UK_GPH_DISPLAY				   	(2)

#if (TC_MAX_NUM_OF_AFE != 0) && (TC_WEIGHTED_AFE_OPTION != 0)
#define     TC_AFE_DIST_LIMIT              		((uint32)( (((uint32)TC_MIN_MILEAGE_NVM)*TC_ODO_1KM_PER_COUNTER) / 10 )) 
#define     TC_TIME_COUNT_AFE_RESET	       		((uint16)( ((uint32)TC_MIN_MILEAGE_TIME_NVM)*(1000/500) )) 
#define     TC_AFE_WEIGHT_MAX_BOUNDARY     		(100000uL)
#define     TC_AFE_WEIGHT_MIN_BOUNDARY     		(10uL)
#define		TC_MAX_COUNT 						((uint8)255uL)
#endif

#define 	TC_AFE_OVERFLOW_BOUNDARY        	(64000uL)
#define 	TC_AVS_OVERFLOW_BOUNDARY        	(6400000uL)

#define TC_AFE_US_MPG_CONST_0      				(2352uL)
#define TC_AFE_UK_MPG_CONST_0					(2825uL)
#define TC_AFE_KMPL_CONST_0      				(1000uL)
#define TC_AFE_L_PER_100KM_CONST_0          	(100000uL)
#define TC_AFE_LARGEST_CONST                	(TC_AFE_L_PER_100KM_CONST_0)


/******	AFE = FUELSOUM/DISTACE	DISTANCE:uint 0.1m	FUELSOUM:uint uL  AFE:uint L/100km*1000 *********/
#define TC_AFE_L_PER_100KM_CONST_1     			((TC_DISTANCE_RESOLUTION * TC_AFE_L_PER_100KM_CONST_0) / TC_FUELFLOW_RESOLUTION )
/******	AFE = FUELSOUM/DISTACE	DISTANCE:uint 0.1m	FUELSOUM:uint uL  AFE:uint L/100km*1000 *********/

#define TC_AFE_US_MPG_CONST_1           		((TC_FUELFLOW_RESOLUTION*TC_AFE_US_MPG_CONST_0) /TC_DISTANCE_RESOLUTION )
#define TC_AFE_UK_MPG_CONST_1					((TC_FUELFLOW_RESOLUTION*TC_AFE_UK_MPG_CONST_0) /TC_DISTANCE_RESOLUTION )
#define TC_AFE_KMPL_CONST_1         			((TC_FUELFLOW_RESOLUTION*TC_AFE_KMPL_CONST_0) /TC_DISTANCE_RESOLUTION )


#define TC_AVS_KMPH_CONST_0             		(1000uL)
#define TC_AVS_MPH_CONST_0              		(1609uL)
#define TC_AVS_KMPH_DENOMINATOR         		(1uL)
#define TC_AVS_MPH_DENOMINATOR          		(10000uL)
#define TC_AVS_LARGEST_CONST            		(TC_AVS_MPH_CONST_0)

/******  AVS = DISTACE/TIME  DISTANCE:uint 0.1m  TIME:uint ms  AVS:uint km/h*100 *********/
#define TC_AVS_KMPH_CONST_1   					( (TC_TIME_RESOLUTION * TC_AVS_KMPH_CONST_0) / TC_DISTANCE_RESOLUTION  ) 
/******  AVS = DISTACE/TIME  DISTANCE:uint 0.1m  TIME:uint ms  AVS:uint km/h*100 *********/


#define TC_DTE_KILOMETRES_CONST_0         		(1609uL)
#define TC_DTE_MILES_CONST_0              		(1000uL)


/******	RAFE = FUELSOUM/DISTACE	DISTANCE:uint 0.1m	FUELSOUM:uint uL  RAFE:uint L/100km*1000 *********/
#define TC_DTE_RAFE_L_PER_100KM_CONST_1     	TC_AFE_L_PER_100KM_CONST_1
/******	RAFE = FUELSOUM/DISTACE	DISTANCE:uint 0.1m	FUELSOUM:uint uL  RAFE:uint L/100km*1000 *********/ 

#define TC_DTE_MILES_CONST_1            		(TC_DTE_MILES_CONST_0)
#define TC_DTE_KILOMETRES_CONST_1       		(TC_DTE_KILOMETRES_CONST_0)

/* Resolution of Calculated DTE */
#define TC_DTE_RESOLUTION               		(1000uL)


#define TC_FUEL_LEVEL_GALLONS_CONST_0     		(2642uL)
#define TC_FUEL_LEVEL_DENOM             		(10000uL)
#define TC_FUEL_LEVEL_BOUNDARY          		(37500uL)

#define TC_RAFE_BOUNDARY                 		(99900uL)

#define TC_IFF_LPH_CONSTANT_0      	  			(uint32)(100uL)
#define TC_IFF_US_GPH_CONSTANT_0      			(10000uL)
#define TC_IFF_UK_GPH_CONSTANT_0	  			(10000uL)
#define TC_IFF_LPH_DENOMINATOR     	  			(1uL)
#define TC_IFF_US_GPH_DENOMINATOR     			(2641uL)
#define TC_IFF_UK_GPH_DENOMINATOR	  			(2199uL)
#define TC_IFF_KMPH_CONST_0    	  	  			(uint32)(1000uL)

#define TC_IFE_US_MPG_CONST_0      				(2352uL)
#define TC_IFE_UK_MPG_CONST_0					(2825uL)
#define TC_IFE_KMPL_CONST_0      				(1000uL)
#define TC_IFE_L_PER_100KM_CONST_0          	(100000uL)


/******	IFE = FUELSOUM/DISTACE	DISTANCE:uint 0.1m	FUELSOUM:uint uL  IFE:uint L/100km*100 *********/
#define TC_IFF_LPKM_CONSTANT_1     				((TC_DISTANCE_RESOLUTION * TC_IFF_LPH_CONSTANT_0 * TC_IFF_KMPH_CONST_0) / TC_FUELFLOW_RESOLUTION  )
/******  IFE = FUELSOUM/DISTACE  DISTANCE:uint 0.1m  FUELSOUM:uint uL  IFE:uint L/100km*100 *********/


/******	IFE = FUELSOUM/TIME		TIME:uint ms	FUELSOUM:uint uL  IFE:uint L/h *100 	***********/
#define TC_IFF_LPH_CONSTANT_1       			((TC_TIME_RESOLUTION * TC_IFF_KMPH_CONST_0) / TC_FUELFLOW_RESOLUTION  )
/******	IFE = FUELSOUM/TIME 	TIME:uint ms	FUELSOUM:uint uL  IFE:uint L/h *100     **********/


#define TC_RIGHT_SHIFT							(0)
#define TC_LEFT_SHIFT							(255)

typedef struct
{
	uint16 DistanceBuffer;
	uint32 FuelBuffer;
	uint16 fuelLevel;
	uint16 TimeBuffer;
}TC_INPUT_DATA;

typedef struct
{
	uint16 DistanceBuffer;
	uint16 DistanceResolution;	
	uint32 FuelBuffer;
	uint16 FuelResolution;
  	uint16 TimeBuffer;       
}TC_INPUT_DATA_IFE;

typedef struct DATA_ACCUMULATOR_TAG
{
   uint64  UpperAccumulator;
   uint64  LowerAccumulator;
}DATA_ACCUMULATOR;


typedef struct
{   
	uint64  TC_Dte_Distance_u32[TC_MAX_NUM_OF_DTE];
	uint64  TC_Dte_Fuel_u32[TC_MAX_NUM_OF_DTE];
	uint32  TC_Internal_Running_Afe;
	uint32	TC_Fuel_Level;
	uint32	TC_Dte_Indicated;
	boolean	TC_Dte_Calc_Enable;
    boolean	TC_Dte_Idle_Update;
}TC_PKG_DTE_DATA;

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************
*Function   : TC_Pkg_ColdInit                                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void TC_Pkg_ColdInit(void);

/**********************************************************************************************************
*Function   : TC_Pkg_WarmInit                                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_WarmInit(void);


/**********************************************************************************************************
*Function   : TC_Pkg_Fast_Indicated_DTE                                                                   *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Fast_Indicated_DTE(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Weighted_Afe_Task                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Weighted_Afe_Task(void);

/**********************************************************************************************************
*Function   : TC_Weight_Afe_Factors                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Weight_Afe_Factors(uint8 afe_index);

/**********************************************************************************************************
*Function   : TC_Pkg_Init_Fuel_Stabilize                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Init_Fuel_Stabilize(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Input_IFE                                                                      	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Input_IFE(const TC_INPUT_DATA_IFE * InputData);

/**********************************************************************************************************
*Function   : TC_Pkg_Input_IFE_Fuel                                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Input_IFE_Fuel(uint32 fuel_accum);

/**********************************************************************************************************
*Function   : TC_Pkg_Input_IFE_Distance                                                               	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Input_IFE_Distance(uint32 distance_accum);


/**********************************************************************************************************
*Function   : TC_Pkg_Output_DTE                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Output_DTE(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Output_AFE                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Output_AFE(  uint8 afe_index);

/**********************************************************************************************************
*Function   : TC_Pkg_Output_IFE                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Output_IFE(void);
/**********************************************************************************************************
*Function   : TC_Pkg_Output_AVS                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/ 
uint32 TC_Pkg_Output_AVS(uint8 tc_key_index);
/**********************************************************************************************************
*Function   : TC_Pkg_Output_IFF                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/
#if 0
uint32 TC_Pkg_Output_IFF(uint8 EnglishMetric);
#endif 
/**********************************************************************************************************
*Function   : TC_Pkg_Output_IFE_LPH                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/
 uint32 TC_Pkg_Output_IFE_LPH(void);
/**********************************************************************************************************
*Function   : TC_Pkg_Output_RAFE                                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Output_RAFE(void);
/**********************************************************************************************************
*Function   : TC_Pkg_Output_AVS                                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Up_Min_Distance_AFE(uint8 afe_index);

/**********************************************************************************************************
*Function   : TC_Pkg_Output_RAFE                                                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Output_RAFE(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Out_Fuel_Consump                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint16 TC_Pkg_Out_Fuel_Consump(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Out_Fuel_Rest                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint32 TC_Pkg_Out_Fuel_Rest(void);
/**********************************************************************************************************
*Function   : TC_Pkg_Out_Set_Fuel_Level                                                                   *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Out_Set_Fuel_Level(uint32 fuel_level_value);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_Dte_Calc_Enable                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint16 TC_Pkg_Get_Dte_Calc_Enable(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Out_Set_Dte_Calc_Enable                                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_Out_Set_Dte_Calc_Enable(uint8 dte_calc_enable);

/**********************************************************************************************************
*Function   : TC_Pkg_Out_Distance                                                                         *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

uint16 TC_Pkg_Out_Distance(void);

/**********************************************************************************************************
*Function   : TC_Pkg_Get_Distance_AVS                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/ 

uint32 TC_Pkg_Get_Distance_AVS(uint8 tc_key_index);


/**********************************************************************************************************
*Function   : TC_Pkg_AFE_Reset                                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/ 

void TC_Pkg_AFE_Reset(uint8 AFE_Index);

/**********************************************************************************************************
*Function   : TC_Pkg_AVS_Reset                                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_AVS_Reset(uint8 tc_key_index);

/**********************************************************************************************************
*Function   : TC_Pkg_DTE_Reset                                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-16                                                                                  *
**********************************************************************************************************/

void TC_Pkg_DTE_Reset(uint8 dte_index);

/**********************************************************************************************************
*Function   : TC_Pkg_Input_Collect_Task                                                               	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
extern void TC_Pkg_Input_Collect_Task(TC_TOTAL_STRUCT *ptTC);
/**********************************************************************************************************
*Function   : TC_Pkg_Output_Round_Up                                                                 	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Output_Round_Up(uint32 Numerator, uint32 Denominator);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_AFE_Fuel_Trip_Value                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint64 TC_Pkg_Get_AFE_Fuel_Trip_Value(uint8 index);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_AFE_Fuel_Consumption_Value                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint64 TC_Pkg_Get_AFE_Fuel_Consumption_Value(uint8 index);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_IFE_Fuel_Trip_Value                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Get_IFE_Fuel_Trip_Value(uint8 index);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_IFE_Fuel_Consumption_Value                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Get_IFE_Fuel_Consumption_Value(uint8 index);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_IFE_Fuel_Trip_Value                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Get_AVS_Fuel_Trip_Value(uint8 index);
/**********************************************************************************************************
*Function   : TC_Pkg_Get_IFE_Fuel_Consumption_Value                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 TC_Pkg_Get_AVS_Driving_Time_Value(uint8 index);
/** 
 * [TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value : Dte stage cosumption]
 * @Author   shujunhua
 * @DateTime 2021/5/27-19:52:17
 * @param    index                    [dafault :0 ]
 * @return   uint32                   [factor:1000,eg 7500=7.5L/100KM]
 */

uint32 TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(uint8 index);
/** 
 * [TC_Pkg_Get_DTE_1s_Distance : description]
 * @Author   shujunhua
 * @DateTime 2021/5/27-19:46:36
 * @param    void                     [description]
 * @return   uint32                   [unit :0.1m ,eg 250000=25KM]
 */
uint32 TC_Pkg_Get_DTE_1s_Distance(void);
/** 
 * [TC_Pkg_Clear_DTE_1s_Distance : clear 1s trip]
 * @Author   shujunhua
 * @DateTime 2021/5/27-19:47:57
 * @param    void                     [description]
 */
void TC_Pkg_Clear_DTE_1s_Distance (void);
/** 
 * [TC_Pkg_Get_DTE_Idle_Update : Idle FuelConsump accumulates to Fuel Consump100M]
 * @Author   shujunhua
 * @DateTime 2021/5/28-14:23:39
 * @param    void                     [description]
 * @return   boolean                  [True :Idle FuelConsump>=Fuel Consump100M]
 */
boolean TC_Pkg_Get_DTE_Idle_Update (void) ;
/** 
 * [TC_Pkg_Set_DTE_Idle_Update : dte idel update status update]
 * @Author   shujunhua
 * @DateTime 2021/5/28-14:24:49
 * @param    value                    [description]
 */
void TC_Pkg_Set_DTE_Idle_Update (boolean value); 



uint64 TC_Pkg_Get_Phev_Egyued_Value(void );
void   TC_Pkg_Phev_Egyued_Reset(void);
uint64 TC_Pkg_Get_Phev_RecupPwr_Value(void );
void   TC_Pkg_Phev_RecupPwr_Reset(void);
uint32 TC_Pkg_Accumulatior_Energy_Fuel_get(void);
void   TC_Pkg_Accumulatior_Energy_Fuel_Reset(void);
uint64 TC_Pkg_Get_Phev_Trip_Value(void);


#define SWC_TC_STOP_SEC_CODE
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





