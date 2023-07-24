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
#ifndef SWC_ODO_PKG_H
#define SWC_ODO_PKG_H


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_Odo_math.h"
#include "SWC_Odo_Pkg_Cfg.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/ 
typedef struct
{
	uint16 Value_u16;
	uint8 Crc_u8;    				/* 4 bit crc in bottom nibble 							*/
}s_OdoValueCrc_t;

typedef struct
{
	uint16 NvmCnt_u16;				/* count value for the data set							*/
	uint8 NvmIncr_u8;				/* increment value for the data set			   			*/
	uint8 NvmSet_u8[2];				/* indices of the two data sets found by Odo_PkgOdoRead */
									/* index 0 is second most recent						*/
									/* index 1 is most recent								*/
	uint32 NvmValue_u32;			/* integer odo value for the set						*/
	u_OdoUnionWithOver_t OdoMath_s; /* temp work area										*/
}s_CurrentOdoStruct_t;

typedef struct 
{
	uint16 HoldCnt_u16;
	uint8 HoldIncr_u8;  			/* note 0 this is an invalid incr value 				*/
	uint8 Nset_u8;
	uint8 passCntr_u8;
}s_OdoRedStruct_t;

typedef struct
{
	uint16 Count_u16;					/* 4 bits of crc and 12 of count						*/
	uint8 ExtCnt_u8;				/* top four bits are extension of count 				*/
	uint8 Increments_u8; 			/* 104 bits of increment stick							*/
}s_OdoDataSetStruct_t;


typedef enum
{
	e_OdoBackUpNuaa = 0,
	e_OdoBackUpVinMsgMis,
	e_OdoBackUpVinSuccess,
	e_OdoBackUpVinError,
	e_OdoBackUpSuccess,
	e_OdoBackUpError,	
}s_OdoBackUpStruct_t;
/**********************************************************************************************************
* define of parament                                                                                      *
**********************************************************************************************************/
#define ODO_PKG_STARTED_CALLBACK_PROCESSING 	((uint8)1u)		/* set true at start of callback 						*/
                                                   				/* processing and FALSE at end   						*/
#define ODO_PKG_RETRY_UPDATE_REQUEST 			((uint8)2u) 	/* True if another update request attempt should be		*/
                                         						/* made, FALSE otherwise                              	*/
#define ODO_PKG_UPDATE_FAILED 					((uint8)4u)    	/* True if an update operation fails, this will cause 	*/
                                         						/* an attempt to update another(if any) data set      	*/
#define ODO_PKG_READ_FAILED 					((uint8)8u)     /* this flag is set when there has been a failure by 	*/
                                         						/* Odo_PkgOdoRead to find two valid data sets 			*/
#define ODO_PKG_COUNTS_LOST 					((uint8)0x10u)  /* this is set when Odo_PkgOdoWrite has not been able to*/
                                         						/* perform updates and Odo_PkgAddCounts detects that   	*/
                                         						/* Odo_PkgOdoRamWholeCnt_s is about to roll over       	*/
#define ODO_PKG_FINISH_CSC_PROCESSING 			((uint8)0x20u) 	/*a secure update has finished 							*/   
#define ODO_PKG_CSC_PROCESSING 					((uint8)0x40u) 	/* secure update in progress 							*/   
#define ODO_PKG_TRIP_CHK_RR 					((uint8)127u)   /* max rrobin executions between checks of trip odo  	*/
                                         						/* base values in e2                                 	*/
/* secure odo request return values */
#define ODO_PKG_CSC_REQ_OK          			((uint8)0u)                                        
#define ODO_PKG_CSC_REQ_BAD_VAL     			((uint8)1u)                                        
#define ODO_PKG_CSC_REQ_ODO_BAD     			((uint8)2u)                                         
#define ODO_PKG_CSC_REQ_TO_MANY     			((uint8)3u)                                         
#define ODO_PKG_CSC_REQ_NOT_DIAG    			((uint8)4u)                                         
#define ODO_PKG_CSC_REQ_NOT_SECURE  			((uint8)5u)                                         
#define ODO_PKG_CSC_REQ_IN_UPDATE   			((uint8)6u)   

/* macros to identify trip odos */
#define ODO_PKG_TRIP_1 							((uint8)0u)
#define ODO_PKG_TRIP_2 							((uint8)1u)
#define ODO_PKG_TRIP_3 							((uint8)2u)
#define ODO_PKG_TRIP_4 							((uint8)3u)
#define ODO_PKG_TRIP_5 							((uint8)4u)
#define ODO_PKG_TRIP_6 							((uint8)5u)

#ifdef ODO_PKG_MYKEY_OPTION
#define ODO_MK_NVM_WRITE_PENDING        		((uint8)0x01u)
#define ODO_MK_NVM_WRITE_NOT_PENDING    		((uint8)0x00u)
#define ODO_MK_NVM_ODO_MASK_VALUE       		(0x0FFFFFFFuL)
#define ODO_STD_NVM_ODO_MASK_VALUE      		(0xF0000000uL)
#define ODO_MK_NVM_ERASED_VALUE         		(0xFFFFFFFFuL)
#define ODO_MY_KEY_INIT_DIST_THLD      			(20uL)
#endif

#define BAD_ODO_VALUE_B 						((uint8)0xFF)

#define ODO_PKG_ABSOLUTE 						(0u)
#define ODO_PKG_RELATIVE 						(1u)

#define ODO_PKG_MOTOROLA						(0u)
#define ODO_PKG_MOTOROLA_EPM					(1u)
#define ODO_PKG_STAR12_EPM 						(2u)     
#define ODO_PKG_STAR12_EPM_2					(4u)   
#define ODO_PKG_OFB_EPM 						(3u)
#define ODO_PKG_MILES 							(0u)
#define ODO_PKG_KM 								(1u)
#define ODO_PKG_HALF_MILES 						(2u)
#define ODO_PKG_TENTH_KM 						(3u)
#define ODO_PKG_FORD							(0u)
#define ODO_PKG_GM 								(1u)

/*define how far must move before storing new trip odo base
with scaling at 100 these units are 1/100 ths of a mile or Km*/
#define ODO_PKG_TRIP_ODO_MIN_DELTA 				(5uL)

/*define how long we will wait for a trip odo update callback
before retrying the request.  Units are in .1 seconds.*/
#define ODO_TRIP_CB_COUNTER  					(20u)

/*define a mask to allow stripping the CRC from the top nibble of a uint32*/
#define ODO_PKG_LWR7_NIBBLES_FF 				(0x0FFFFFFFuL)

/*define a bad data set index*/
#define ODO_PKG_INVALID_SET 					(0xFFu)
  
/*define a bad CRC return for a long crc*/
#define ODO_PKG_BAD_CRCL 						(0x80u)

#define GET_SET_ADDR(Nset_u8) 					(Odo_OdoNvmAddr_Get(Nset_u8))

#define ODO_PKG_TRIP_ADDR_GET(Nset_u8) 			(Odo_TripNvmAddr_Get(Nset_u8))

/*checks of CRC for longs in EEPROM
these macros use less space than converting to a function call*/
#define NVM_CHECK_CRCL_IS_BAD(p1) 				((Odo_PkgCrcL(p1)&ODO_PKG_BAD_CRCL) == ODO_PKG_BAD_CRCL)
#define NVM_CHECK_CRCL_IS_OK(p1) 				((Odo_PkgCrcL(p1)&ODO_PKG_BAD_CRCL) != ODO_PKG_BAD_CRCL)

#ifdef SWC_ODO_PKG_H
#define ODO_SPEC_ODO_STORAGE_FORMAT 			ODO_PKG_OFB_EPM

#define PROD_SPEC_ODO_STORAGE_UNITS 			ODO_PKG_KM

#define PROD_SPEC_CUSTOMER 						ODO_PKG_FORD

#if (PROD_SPEC_CUSTOMER == ODO_PKG_GM)
#define ODO_JUMP_LIMIT 							(800u) 
#else
#define PROD_SPEC_TRIP_ODO_IN_E2  

#endif                                        

#if (PROD_SPEC_ODO_STORAGE_UNITS != ODO_PKG_TENTH_KM) 
#define CURRENT_ODO_UNITS_SCALING 				(100u)
#else
#define CURRENT_ODO_UNITS_SCALING 				(10u)
#endif
#if (PROD_SPEC_CUSTOMER == ODO_PKG_GM) && !defined(PROD_SPEC_TRIP_ODO_IN_E2)

/* ensure trip odo base values in E2 for GM */
#define PROD_SPEC_TRIP_ODO_IN_E2
#endif
#endif

/* not providing special visibility to odo_pkg.h ie private to odo_pkg  */
#define ODO_PKG_LITTLE_ENDIAN  					/* define this as necessary */

/*define EEPROM_WRITE (only required for the ODO-01 package, ignored by ODO-02 package)
either include an '.h' fileor define a macro*/
//#include "epm_pkg.h"
#define EEPROM_WRITE(p1,p2) 							epm_write_byte(p1,p2)

/*
define how often the storage units are written to NVM
if one then NVM written every storage unit, if two then
NVM written every two storage units, etc.
*/
#define PROD_SPEC_ODO_STORAGE_INCR 				(1u)

/*
define raw input counts per MILE or per KM
one or the other must be defined
*/
#define PROD_SPEC_COUNTS_PER_KM  				(10000u)   // FIX 1KM COUNT BY ZZA 

/*#define PROD_SPEC_COUNTS_PER_MILE 8000*/


/* define the EXPERIMENTAL_AND_TEST if building a version             */
/*   o - for a non-standard target                                    */
/*   o - with a non-standard compiler                                 */
/*   o - where the initial odo data is not to represent zero distance */
/*       (see odo_pkg.c for production intent initial data )          */


/*define macros for checking the (distance) relationship between odo data sets*/
#define ODO_PKG_ODORLCON 						((uint8) (2+2*PROD_SPEC_ODO_STORAGE_INCR))
#define ODO_PKG_ODORLCON2 						((uint8)(TOTAL_ODO_INCRS - ODO_PKG_ODORLCON))

#define ODO_PKG_NORMAL 							(0u)
#define ODO_PKG_RESTART 						(1u)
#define ODO_PKG_Q_BIT 							(2u)

#ifdef ODO_PKG_MYKEY_OPTION
#define ODO_PKG_MYKEY    						((uint8)0x00u)
#define ODO_PKG_STDKEY   						((uint8)0xF0u)
#endif

#if (ODO_SPEC_ODO_STORAGE_FORMAT==ODO_PKG_MOTOROLA) || (ODO_SPEC_ODO_STORAGE_FORMAT==ODO_PKG_MOTOROLA_EPM)

#define ODO_PKG_NUMBER_OF_ODO_SETS  			(5u)

#define ODO_OFFSET 								(1uL)

#define TOTAL_ODO_INCRS 						((uint8) (13*8)) 

#define NUM_OF_ODO_INCR_BYTES 					(TOTAL_ODO_INCRS/8)

#define BAD_ODO_VALUE_W 						(0xFFFFu)

#elif (ODO_SPEC_ODO_STORAGE_FORMAT==ODO_PKG_STAR12_EPM)
 
#if PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_MILES
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(20u)
#elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(40u)
#elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_KM
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(32u)
#endif

#define TOTAL_ODO_INCRS 						((uint8) 128)

#define ODO_OFFSET 								(1uL)
 
#define BAD_ODO_VALUE_W 						((uint16)0xFFFFu)

#elif (ODO_SPEC_ODO_STORAGE_FORMAT==ODO_PKG_STAR12_EPM_2)
 
#if PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_MILES
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(10u)
#elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(20u)
#elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_KM
#define ODO_PKG_NUMBER_OF_ODO_SETS  			(16u)
#endif

#define TOTAL_ODO_INCRS 						((uint8)128)

#define ODO_OFFSET 								(1uL)

#define BAD_ODO_VALUE_W 						((uint16)0xFFFFu)

#elif ODO_SPEC_ODO_STORAGE_FORMAT==ODO_PKG_OFB_EPM
 
#if (PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_TENTH_KM)

#define ODO_PKG_NUMBER_OF_ODO_SETS  			(17u)

#define TOTAL_ODO_INCRS 						((uint8) 250)

#else

#define ODO_PKG_NUMBER_OF_ODO_SETS  			(5u)

#define TOTAL_ODO_INCRS 						((uint8)128)

#endif 
#define ODO_OFFSET 								(1uL)

#define BAD_ODO_VALUE_W 						((uint16)0xFFFFu)

#endif

/*check for motorola*/
#if (ODO_SPEC_ODO_STORAGE_FORMAT == ODO_PKG_MOTOROLA) || (ODO_SPEC_ODO_STORAGE_FORMAT == ODO_PKG_MOTOROLA_EPM)
/*if off board or star12 define how to get the increment value*/
#elif ((ODO_SPEC_ODO_STORAGE_FORMAT == ODO_PKG_OFB_EPM) \
  || (ODO_SPEC_ODO_STORAGE_FORMAT == ODO_PKG_STAR12_EPM) \
  || (ODO_SPEC_ODO_STORAGE_FORMAT == ODO_PKG_STAR12_EPM_2))
  
#if (PROD_SPEC_ODO_STORAGE_UNITS != ODO_PKG_TENTH_KM) 
  #define GET_INCR(Nset_u8) 					(* &(GET_SET_ADDR(Nset_u8)[3]))
#else
/*If PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_TENTH_KM, then take Least Significant two bytes from the ODO NVM Data*/
  #define GET_INCR(Nset_u8) 					(* (uint16 *)(&(GET_SET_ADDR(Nset_u8)[2])))
#endif

#else
  #error ODO_SPEC_ODO_STORAGE_FORMAT must be 1 of ODO_PKG_MOTOROLA_EPM, ODO_PKG_STAR12_EPM, \
         ODO_PKG_STAR12_EPM_2, ODO_PKG_MOTOROLA or ODO_PKG_OFB_EPM
#endif

/* needed to eliminate some QAC warnings */

typedef float FLOAT;  
/* if input counts are per mile then define things appropriatly*/

#if defined(PROD_SPEC_COUNTS_PER_MILE) && !defined(PROD_SPEC_COUNTS_PER_KM)

#define COUNTS_DELTA_COMP ((((uint32)PROD_SPEC_COUNTS_PER_MILE/(uint32)CURRENT_ODO_UNITS_SCALING)*62uL)/100uL)
 /*if storage units are miles then this is a simple case there are no fractional input counts per mile*/
 #if PROD_SPEC_ODO_STORAGE_UNITS==ODO_PKG_MILES
  #define WHOLE_COUNTS_PER_UNIT 				(PROD_SPEC_COUNTS_PER_MILE*PROD_SPEC_ODO_STORAGE_INCR)

/*if storage units are km then this is not a simple caseand there is a fractional input count per km*/
 #elif PROD_SPEC_ODO_STORAGE_UNITS==ODO_PKG_KM
   #define MILES_TO_KM 							(0.6213711922f)
   #define WHOLE_COUNTS_PER_UNIT 				((uint16)(1 + (MILES_TO_KM*(FLOAT)(PROD_SPEC_COUNTS_PER_MILE*PROD_SPEC_ODO_STORAGE_INCR))))
   #define FRAC_TOTAL 							((uint16)10000)	
   #define FRAC_COUNTS_PER_UNIT 				((uint16)( 0.5f + (FLOAT)FRAC_TOTAL * ((FLOAT)WHOLE_COUNTS_PER_UNIT - \
      											( MILES_TO_KM*(FLOAT)(PROD_SPEC_COUNTS_PER_MILE*PROD_SPEC_ODO_STORAGE_INCR ))) ))
          
 #elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
   #define WHOLE_COUNTS_PER_UNIT 				(PROD_SPEC_COUNTS_PER_MILE/2u)

 #else
 /*throw an error if no storage unit definition*/
    #error PROD_SPEC_ODO_STORAGE_UNITS is neither MILES or HALF_MILES or KM
 #endif
#endif

/*if input counts are per km then define things appropriatly*/
#if defined(PROD_SPEC_COUNTS_PER_KM) && !defined(PROD_SPEC_COUNTS_PER_MILE)
 #define COUNTS_DELTA_COMP 						((PROD_SPEC_COUNTS_PER_KM)/CURRENT_ODO_UNITS_SCALING) //50
  /*if storage units are km then this is a simple case there are no fractional input counts per km*/
 #if PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_KM
  #define WHOLE_COUNTS_PER_UNIT 				(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR)
  /*if storage units are miles then this is not a simple case and there is a fractional input count per mile*/
 #elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_MILES
  #define KM_TO_MILES 							(1.609344f)
  #define WHOLE_COUNTS_PER_UNIT 				((uint16)(1 + (KM_TO_MILES*(FLOAT)(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR))))
  #define FRAC_TOTAL 							((uint16)10000)
  #define FRAC_COUNTS_PER_UNIT 					((uint16)( 0.5f + (FLOAT)FRAC_TOTAL * ((FLOAT)WHOLE_COUNTS_PER_UNIT - \
      											( KM_TO_MILES*(FLOAT)(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR )))))
        	
  /*if storage units are half miles then this is not a simple case and there is a fractional input count per half mile*/
 #elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
  #define KM_TO_HALF_MILES 						(0.804672f)
  #define WHOLE_COUNTS_PER_UNIT 				((uint16)(1 + (KM_TO_HALF_MILES*(FLOAT)(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR))))
  #define FRAC_TOTAL 							((uint16)10000)
  #define FRAC_COUNTS_PER_UNIT 					((uint16)( 0.5f + (FLOAT)FRAC_TOTAL * ((FLOAT)WHOLE_COUNTS_PER_UNIT - \
      											( KM_TO_HALF_MILES*(FLOAT)(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR )))))
    
 #elif (PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_TENTH_KM)
   /*Definitions for 0.1 KM NVM Resolution*/
  #define KM_TO_TENTH_KM 						(0.1f)
  #define WHOLE_COUNTS_PER_UNIT 				((uint16)(1 + (KM_TO_TENTH_KM*(FLOAT)(PROD_SPEC_COUNTS_PER_KM*PROD_SPEC_ODO_STORAGE_INCR))))

  #define FRAC_TOTAL 							((uint16)10000)
  #define FRAC_COUNTS_PER_UNIT 					((uint16)((FLOAT)FRAC_TOTAL * ((FLOAT)WHOLE_COUNTS_PER_UNIT - \
  												((FLOAT)(PROD_SPEC_COUNTS_PER_KM*KM_TO_TENTH_KM ))) ))

  #else
  /*throw an error if no storage unit definition*/
    #error PROD_SPEC_ODO_STORAGE_UNITS is neither MILES or HALF_MILES or KM or TENTH_KM
  #endif
#endif

#define UPDATE_COUNT_THRESHOLD 					(WHOLE_COUNTS_PER_UNIT)
#define ODO_PKG_CSC_COUNT_INCR 					(WHOLE_COUNTS_PER_UNIT/(uint16)1000u)
#define ODO_PKG_CSC_SCALE 						(10uL)

#if !defined(PROD_SPEC_COUNTS_PER_KM) && !defined(PROD_SPEC_COUNTS_PER_MILE)
/*throw an error if no input counts definition*/
 #error neither PROD_SPEC_COUNTS_PER_KM  or PROD_SPEC_COUNTS_PER_MILE are defined
#endif

/* take into account whether or not roll back is configured */
#ifdef ODO_PKG_PROD_SPEC_RB_MAX_TIMES
 #if PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_MILES
  #define NVM_ODO_VALUE_CLAMP 					(1000000uL + ODO_OFFSET + (uint32)PROD_SPEC_RB_MAX_UNITS)
 
 #elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_KM
  #ifdef PROD_SPEC_RB_DISPLAY_UNITS
   #define NVM_ODO_VALUE_CLAMP 					(1609344uL + ODO_OFFSET + (uint32)RB_MAX_UNITS_MILES)
  #else
   #define NVM_ODO_VALUE_CLAMP 					(1609344uL + ODO_OFFSET + (uint32)PROD_SPEC_RB_MAX_UNITS)
  #endif
 #elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
   #define NVM_ODO_VALUE_CLAMP 					(2000000uL + ODO_OFFSET + (uint32)PROD_SPEC_RB_MAX_UNITS)
 
 #endif
 #ifdef PROD_SPEC_RB_DISPLAY_UNITS

 #if PROD_SPEC_ODO_STORAGE_UNITS != ODO_PKG_KM
  #error storage units must be Km when rollback in display units
 #endif
  /* define the roll back parameters to use if the display is in miles */
 #if (103 * PROD_SPEC_RB_MAX_UNITS) > (64 * 255)
  #error PROD_SPEC_RB_MAX_UNITS is too big for rollback in display units
 #else  
  #define RB_MAX_UNITS_MILES 					((uint8)( 1.609344f * (FLOAT)PROD_SPEC_RB_MAX_UNITS))
 #endif  

 #if ( 103 * PROD_SPEC_RB_CEILING) > (64 * 255)
  #error PROD_SPEC_RB_CEILING is too big for rollback in display units
 #else
  #define RB_CEILING_MILES 						((uint8)( 1.609344f * (FLOAT)PROD_SPEC_RB_CEILING))
 #endif
  
 #if ( 103 * PROD_SPEC_RB_FLOOR) > (64 * 255)
  #error PROD_SPEC_RB_FLOOR is too big for rollback in display units
 #else
  #define RB_FLOOR_MILES 						((uint8)( 1.609344f * (FLOAT)PROD_SPEC_RB_FLOOR))
 #endif
  
 #if ( 103 * PROD_SPEC_RB_MAX_PER) > (64 * 255)
  #error PROD_SPEC_RB_MAX_PER is too big for rollback in display units
 #else
  #define RB_MAX_PER_MILES 						((uint8)( 1.609344f * (FLOAT)PROD_SPEC_RB_MAX_PER))
 #endif
#endif
#else
#if PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_MILES
 #define NVM_ODO_VALUE_CLAMP 					(1000000uL + ODO_OFFSET)

#elif (PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_KM)
 #define NVM_ODO_VALUE_CLAMP 					(1609344uL + ODO_OFFSET)

#elif (PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_TENTH_KM)
 #define NVM_ODO_VALUE_CLAMP 					(16093440uL + ODO_OFFSET)

#elif PROD_SPEC_ODO_STORAGE_UNITS == ODO_PKG_HALF_MILES
 #define NVM_ODO_VALUE_CLAMP 					(2000000uL + ODO_OFFSET)
#endif
#endif
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/

#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 

/**********************************************************************************************************
* Internal function                                                                                       *
**********************************************************************************************************/
/**********************************************************************************************************
*Function   : Odo_PkgAddCounts                                                                            *
*                                                                                                         *
*Description: Odo process if need to updata                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#if (PROD_SPEC_CUSTOMER == ODO_PKG_GM)
uint16 Odo_PkgAddCounts(uint16 NewROdo_u16, uint8 Status_u8);
#elif (PROD_SPEC_CUSTOMER == ODO_PKG_FORD)
uint8 Odo_PkgAddCounts(uint8 NewROdo_u16, uint8 Status_u8);
#else
#endif
/**********************************************************************************************************
*Function   : Odo_PkgResetTrip                                                                            *
*                                                                                                         *
*Description: Reset trip interface                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#if ODO_PKG_NUM_TRIP > 0
 #if defined(PROD_SPEC_TRIP_ODO_IN_E2)
void Odo_PkgResetTrip(uint8 TripNum_u8);
/**********************************************************************************************************
*Function   : Odo_PkgSaveOdoRetroBase                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#if (PROD_SPEC_CUSTOMER == ODO_PKG_GM)
void Odo_PkgSaveOdoRetroBase(void);
#endif  
#else 
void Odo_PkgResetTrip(uint8 TripNum_u8);
#endif  
/**********************************************************************************************************
*Function   : Odo_PkgTripOdoValue_Get                                                                     *
*                                                                                                         *
*Description: Get current trip odo                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgTripOdoValue_Get(uint32 *TripOdoValue_u32, uint8 TripNum_u8, boolean TripIsMetric_bool);
#endif  
/**********************************************************************************************************
*Function   : Odo_PkgWarnInit                                                                             *
*                                                                                                         *
*Description: Warn init,for copy  data                                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgWarnInit(void);
/**********************************************************************************************************
*Function   : Odo_PkgRollBack                                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#ifdef ODO_PKG_PROD_SPEC_RB_MAX_TIMES
#ifdef PROD_SPEC_RB_DISPLAY_UNITS
boolean Odo_PkgRollBack(boolean metric_display);
/**********************************************************************************************************
*Function   : Odo_PkgRollBack                                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#else
boolean Odo_PkgRollBack(void);
#endif
/**********************************************************************************************************
*Function   : Odo_PkgChkRollBack                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgChkRollBack(void);
/**********************************************************************************************************
*Function   : Odo_PkgRollBackReport                                                                       *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint16 Odo_PkgRollBackReport(void);
#endif   
/**********************************************************************************************************
*Function   : Odo_PkgNvmRamCheck                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgNvmRamCheck(void);
/**********************************************************************************************************
*Function   : Odo_PkgColdInit                                                                             *
*                                                                                                         *
*Description: Read current odo from nvm                                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgColdInit(void);
#ifdef CSC_PKG_H  
/**********************************************************************************************************
*Function   : CSC_SecureProgrammingRequest                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 CSC_SecureProgrammingRequest( CSC_ODO_STRUCT  CSC_OdoBuffer);
#endif
#ifdef ODO_ALLOW_CHANGE
/**********************************************************************************************************
*Function   : Odo_PkgOdoChangeUp                                                                          *
*                                                                                                         *
*Description: Odo change interface                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgOdoChangeUp(uint32 NewValue_u16,uint8 OdoRetFlag_u8);
/**********************************************************************************************************
*Function   : Odo_PkgOdoChkChangeUp                                                                       *
*                                                                                                         *
*Description: Update last odo date after odo change by interfac                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgOdoChkChangeUp(void);
#endif
/**********************************************************************************************************
*Function   : Odo_PkgConvertMiToKm                                                                        *
*                                                                                                         *
*Description: Calculate uints form mile to km                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgConvertMiToKm(uint32 *CurOdoValue_u32);
/**********************************************************************************************************
*Function   : Odo_PkgConvertKmToMi                                                                        *
*                                                                                                         *
*Description: Calculate uints form km to mile                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgConvertKmToMi(uint32 *CurOdoValue_u32);
/**********************************************************************************************************
*Function   : Odo_PkgGetCurrentOdo                                                                        *
*                                                                                                         *
*Description: Get current odo by uints                                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgGetCurrentOdo(uint32 *CurOdoValue_u32, boolean CurrentOdoIsMetric);

/**********************************************************************************************************
*Function   : Odo_PkgGetCurrentOdo0_1M                                                                    *
*                                                                                                         *
*Description: Get current odo by 0.1m                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgGetCurrentOdo0_1M(uint16 *Cur0_1m);

#ifdef ODO_PKG_MYKEY_OPTION
/**********************************************************************************************************
*Function   : Odo_PkgMkSetKeyType                                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgMkSetKeyType(uint8 current_key_type_detected_U8);
/**********************************************************************************************************
*Function   : Odo_PkgCelarMykeyAccum                                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgCelarMykeyAccum(void);
/**********************************************************************************************************
*Function   : Odo_PkgMykeyAccum_Get                                                                       *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_PkgMykeyAccum_Get(uint32 *CurMyKeyOdoValue_u32, boolean CurMyKeyOdoIsMetric_bool);
#endif

#define SWC_ODO_STOP_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*#endif  Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/06/02     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

