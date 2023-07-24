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
*File Name   : SWC_TC_Pkg_Cfg.h                                                                             *
*                                                                                                         *
*Description : TripComputer module pakage configuration interface head file.                                        *
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

#ifndef TC3_PKG_CFG
#define TC3_PKG_CFG   (1)

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

#define TC_DEBUG    							(0)

#define TC_TESTBIT( operand, bit_mask )        	(((operand) & (bit_mask)) != 0u)
#define TC_SETBIT( operand, bit_mask )         	((operand) |= (bit_mask))
#define TC_CLEARBIT( operand, bit_mask )       	((operand) &= (~(bit_mask)))
#define TC_TOGGLEBIT( operand, bit_mask )      	((operand) ^= (bit_mask))


#define TC_TRI_OPTION		  					(1)
//#define TC_DTE_OPTION         				(1)
//#define TC_AFE_OPTION         				(1)
//#define TC_AVS_OPTION         				(1)
#define TC_IFE_OPTION         					(0)		/* non zero only if TC_MAX_NUM_OF_IFE is zero */
#define TC_IFF_OPTION         					(0)		/* non zero only if TC_MAX_NUM_OF_IFE is zero */
#define TC_WEIGHTED_AFE_OPTION 					(0)		/* NOTE::This macro is to be configured only if TC_AFE_OPTION is configured*/
#define TC_FLEX_FUEL_OPTION   					(0)


//#define TC_IFE_INPUT_OPTION   				(1)
//#define TC_MAXIMUM_NUMBER_OF_INSTANCES		(1)
#define TC_CURRENT_KEY_INSTANCE() 				(1u)

#define TC_MAX_NUM_OF_TRIP						(2u)
#define TC_MAX_NUM_OF_AVS						(2u)

#define TC_MAX_NUM_OF_AFE						(3u)
#define AFE_FUEL_BOUND_MAX  					(25167785234uL)	//1500L*1000/0.0000596
#define AFE_DISTANCE_BOUND_MAX					(99999*TC_ODO_1KM_PER_COUNTER/10)	//1000km*PPK
	
#define TC_MAX_NUM_OF_IFE						(1)
#define TC_IFE_DIST_MAXRES      	    		(8000uL)
#define TC_IFE_DIST_MINRES      				(5000uL)
#define TC_IFE_FUEL_MINRES      				(5000uL)
#define TC_IFE_FUEL_MAXRES      				(80000uL)
#define TC_MAX_NUM_OF_DTE						(1)	
#define TC_MAX_RAFE             				(20000uL) /* unit: mL/100KM */
#define TC_MIN_RAFE             				(2000uL)  /* no use */

#define TC_AFE_DISPLAY_DASHES       			(0xFFFFuL)

#define TC_DISTANCE_UNITS_OPTION            	(1)
#define TC_DISTANCE_RESOLUTION              	(uint32)(10000uL) /*TC_ODO_1KM_PER_COUNTER*/

#define TC_FUEL_FLOW_UNITS_OPTION           	(1)
#define TC_FUELFLOW_RESOLUTION              	(uint32)(1000000uL)
#define TC_ODO_1KM_PER_COUNTER  				((uint32)TC_DISTANCE_RESOLUTION)
#define TC_FOR_ODO_100KM_FACTOR					(100uL)
#define TC_FOR_FUEL_1ML_PER_COUNTER  			(16778uL) /* 1L = TC_FOR_FUEL_1ML_PER_COUNTER * fuelConsumption signal counter raw data */
#define TC_FOR_FUEL_1L_FACTOR 					(1000uL)

#define TC_FUEL_LEVEL_UNITS_OPTION          	(1)
#define TC_TIME_RESOLUTION                  	(3600000uL) 

#define TC_IFE_FILTER_SIZE                  	(0uL)
#define TC_IFE_FUEL_FLOW_TIME_THRESHOLD     	(1000uL)

#define TC_AFE_RESET_DISTANCE_UPPER()   		(0)
#define TC_AFE_RESET_DISTANCE_LOWER()   		(0)
#define TC_AFE_RESET_FUEL_UPPER()       		(0)
#define TC_AFE_RESET_FUEL_LOWER()       		(0)

#define TC_AVS_RESET_DISTANCE_UPPER()   		(0)
#define TC_AVS_RESET_DISTANCE_LOWER()   		(0)
#define TC_AVS_RESET_TIME_UPPER()       		(0)
#define TC_AVS_RESET_TIME_LOWER()       		(0)

#define TC_DATA_INPUT_ERROR						(0xFFFFFFFFuL)

#define TC_MAX_NUM_OF_TDT						(2u)		/*trip driving time*/
#define TC_DRV_SECOND_COUNTER 					1000uL  /* 1s */

#define TC_DTE_STAGE_AFE_INIT_VALUE				((uint32)TC_Ftrip_T.tTC_Config_NVM.SFCDefault_NvmInit * 100)
#define TC_DTE_STAGE_AFE_MIN_VALUE				((uint32)TC_Ftrip_T.tTC_Config_NVM.SFCMin_NvmInit * 100 ) 
#define TC_DTE_STAGE_AFE_MAX_VALUE				((uint32)TC_Ftrip_T.tTC_Config_NVM.SFCMax_NvmInit * 100)
#define TC_DTE_STAGE_AFE_INIT_DISTANCE		    (10000ULL*TC_Ftrip_T.tTC_Config_NVM.STripAgeInitTripBileage) 	//(uint64)100 * 1000 * 10 /4
#define TC_DTE_STAGE_AFE_INIT_FUEL  			((uint64)TC_Ftrip_T.tTC_Config_NVM.SFCDefault_NvmInit *TC_Ftrip_T.tTC_Config_NVM.STripAgeInitTripBileage* 1000)


/****************************************************************************************************************************

    DTE CONFIGURATION ITEMS:
    Important note:


    The following is an example configuration for the distance and fuel pulses
    being in km and L respectively.

            ITEM                UNIT            DEFAULT     MIN     MAX
    1.  TC_DTE_RAFE_DEFAULT     MPG             23522       2000    50000
    2.  TC_DTE_DISTANCE         Kilometers*     100         10      10000
    3.  TC_DTE_FUEL             Liters*         100         10      10000
    4.  TC_DTE_SCALE_NUMERATOR  CONST           15          8       15
    5.  TC_DTE_SCALE_DENOM      CONST           16          1       16

    TC_DTE_RAFE_DEFAULT will ALWAYS be in 1/1000 MPG units - regardless of
    any other settings.

    * TC_DTE_DISTANCE and TC_DTE_FUEL need to be entered in the same units the
    distance and fuel pulses are in.

    * TC_DTE_RATE_OF_CHANGE_ENABLE -


 ***************************************************************************************************************************/
 
#define TC_DTE_RAFE_DEFAULT         			(10000uL) /* 8.63L/100KM */
#define TC_DTE_DISTANCE             			(100uL) /* 100km */
#define TC_DTE_FUEL                 			(100uL) /* 100L */
#define TC_DTE_SCALE_NUMERATOR      			(15uL)
#define TC_DTE_SCALE_DENOM          			(16uL)

/****************************************************************************************************************************

    WEIGHTED AFE  CONFIGURATION ITEMS:
    Important note:


    The following is an example configuration for the WEIGHTED AFE parameters.


            ITEM                         UNIT               DEFAULT     MIN     MAX        RESOLUTION  VALUE(DEFAULT/RESOLTION)
    1.  TC_AFE_MINIMUM_MILEAGE           meter              100         0       1000       10          10
    2.  TC_AFE_DELAY_THRESHOLD           Seconds            20          0       60         0.5         40
    3.  TC_AFE_WEIGHT_AFE                CONST              0           0       100        0.1         0
    4.  TC_AFE_WEIGHT_RAFE               CONST              100         0       100        0.1         1000
    5.  TC_AFE_WEIGHT_DIFF               CONST              0.33        0       100        0.01        33
   
        TC_AFE_MINIMUM_MILEAGE   ::	Weighted AFE Distance Threshold.This is used to update 'min mileage' parameter.
                                    Unit: m
                                    Resolution: 10
                                    Valid Range: 0 to 100
                                    DATA TYPE  :uint8
        TC_AFE_DELAY_THRESHOLD   :: Weighted AFE Delay Threshold.This is used to update 'mileage timer' parameter.
                                    Unit: Secs
                                    Resolution: 0.5s
                                    Valid Range: 0 to 120
                                    DATA TYPE  :uint8
        TC_AFE_WEIGHT_AFE        ::	Weight_afe  (This parameter shall impact the AFE calculated).This is used to update 
                                    'weight AFE' parameter.
                                    Unit: none
                                    Resolution: 1/10
                                    Valid Range: 0 to 1000
                                    DATA TYPE  :uint16

        TC_AFE_WEIGHT_RAFE       ::	Weight_Rafe (This parameter shall impact the weight RAFE calculated).This is used to update 
                                    'weight RAFE' parameter.
                                    Unit: none
                                    Resolution: 1/10
                                    Valid Range: 0 to 1000
                                    DATA TYPE  :uint16 
        TC_AFE_WEIGHT_DIFF  	 ::  Weight Difference (This parameter shall impact the weight AFE & RAFE)..This is used to update 
                                    'weight Diff' parameter.
                                    Unit: none
                                    Resolution: 1/100
                                    Valid Range: 0 to 10000
                                    DATA TYPE  :uint16

 ***************************************************************************************************************************/
#define TC_AFE_MINIMUM_MILEAGE             		((uint8)10)
#define TC_AFE_WEIGHT_AFE                  		((uint16)0)
#define TC_AFE_WEIGHT_RAFE                 		((uint16)1000)
#define TC_AFE_WEIGHT_DIFF                 		((uint16)33)
#define TC_AFE_DELAY_THRESHOLD             		((uint8)40)


#define TC_DTE_RATE_OF_CHANGE_ENABLE  			(1)

#if (TC_DTE_RATE_OF_CHANGE_ENABLE == 1)
/***************************************************************************************************************************

    * TC_DTE_LOW_BOUND_THLD  - This configuration is to get the threshold value which is used to update 'Indicated DTE'.
                               The 'Indicated DTE' shall be updated with '0',
                               if the calculated DTE < TC_DTE_LOW_BOUND_THLD & DTE Updation Time > TC_DTE_UPDT_TIME_SEC.
                               Unit: Km
                               Resolution: 1/100000
                               Valid Range: 0x00000 to 0xFFFFF


    * TC_DTE_HIGH_BOUND_THLD - This configuration is to get the threshold value which is used to update Indicated DTE.
                               The 'Indicated DTE' shall be updated with 'calculated DTE',
                               if the calculated DTE > TC_DTE_HIGH_BOUND_THLD & DTE Updation Time > TC_DTE_UPDT_TIME_SEC.
                               The unit of this configuration should be in KM.
                               Unit: Km
                               Resolution: 1/100000
                               Valid Range: 0x00000 to 0xFFFFF

    * TC_DTE_UPDT_TIME_SEC   - This configuration is to get the 'TIME threshold' for the 'Indicated DTE' updation.
                               UNIT: Seconds
                               Resolution: 1
                               Valid Range: 0x00 to 0xFF

 REQUIRED   : If TC_DTE_RATE_OF_CHANGE_ENABLE = 1
***************************************************************************************************************************/
#define TC_DTE_LOW_BOUND_THLD        			(2500uL) /* 250000uL mean 2.5KM */
#define TC_DTE_HIGH_BOUND_THLD      			(10000uL)
#define TC_DTE_UPDT_TIME_SEC        			(10)

#define PID_AFE_BIAS_FACTOR 					(1000uL)
#define TC_RATE_OF_CHANGE_TABLE_NVM 			(1)

/********************************************************************************************
Configuration Items for the DTE Rate of Change Implementation
The configuration items below
1. TC_NO_OF_DTE_CALC_RANGE_PTS
2. TC_DTE_CALC_RANGE_PTS
3. TC_NO_OF_DTE_RATE_OF_CHANGE
4. TC_DTE_RATE_OF_CHANGE are  populated based on the example given below
-------------------------------------------------------------------------------------------
 |DTEind - DTEcalc| |            Rate of change (m/m driven)
-------------------------------------------------------------------------------------------
        Km          |       DTEcalc > 50 Km  |    DTEcalc > 20 Km    |  DTEcalc <= 20 Km
                    |                        |                       |
       < 1          |           0            |          0            |           0
       < 3          |           1            |          2            |           2
       < 6          |           1            |          2            |           4
       < 10         |           1            |          2            |           8
       < 20         |           2            |          4            |           16
       < 35         |           4            |          8            |           32
       < 50         |           8            |          16           |           64
       < 60         |           16           |          32           |           128
     > = 60         |    Immediate Update    |    Immediate Update   |   Immediate Update
-------------------------------------------------------------------------------------------
******************************************************************************************/

#define TC_NO_OF_DTE_CALC_RANGE_PTS 			2

#define TC_DTE_CALC_RANGE_PTS					{50,20}

#define TC_NO_OF_DTE_RATE_OF_CHANGE 			8

#define TC_DTE_RATE_OF_CHANGE \
{ \
{1,  {0,  0,  0}}, \
{3,  {1,  2,  2}}, \
{6,  {1,  2,  4}}, \
{10, {1,  2,  8}}, \
{20, {2,  4,  16}}, \
{35, {4,  8,  32}}, \
{50, {8,  16, 64}}, \
{60, {16, 32, 128}}, \
}

#endif
/* End of TC_DTE_RATE_OF_CHANGE_ENABLE = 1 */

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




