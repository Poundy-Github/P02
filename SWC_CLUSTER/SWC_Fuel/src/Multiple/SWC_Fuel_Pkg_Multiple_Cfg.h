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
**  Description:      This file contains a description of the macros that
**                    are used to configure the fuel filter algorithm
**
**  Organization:       
**
**********************************************************************************************************/
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
#include "SWC_Fuel_Multiple_Process.h"
#include "SWC_Fuel_Api_Process.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/


/**********************************************************************************************************
** Fuel algorithm configuration parameters
**********************************************************************************************************/
#define FUEL_MULTIPLE_GET_FUEL_SCEM()                            (1u)

/**********************************************************************************************************
** Populate the following with a function that returns 1 when the fast fill
** conditions have been met, 0 otherwise.  Set to 1 if not used.
**
** Typically, this will be a check for zero speed and/or the transmission
** in PARK.  Check your product specific CRS/CDS for requirements for
** this item.
**
** The definition of this macro will be determined by the software engineer,
** and will typically be a function from the source code file FFUEL.C.
**********************************************************************************************************/


/**********************************************************************************************************
** In dual tank systems, populate the following with a function that returns
** 0 when tank A is selected or 1 for tank B.  Set to 0 for a single sender
** or saddle tank system.
**
** The definition of this macro will be determined by the software engineer,
** and will typically be a function from the source code file that is used
** to monitor the switch that is used to select the active tank.
**********************************************************************************************************/
#define FUEL_MULTIPLE_TANK_SELECTION_MACRO()                     (0u)

/**********************************************************************************************************
** Populate the following with a function that returns TRUE when the
** 'Power Mode = Start' condition exists, i.e. ignition switch is in
** CRANK.  Set to FALSE if not used.  If this macro returns TRUE, the
** fuel filter algorithm will not be iterated after fuel init completes.
**
** Check your product specific CRS/CDS for requirements for this item.
**
** The definition of this macro will be determined by the software engineer,
** and will typically be a function from the source code file FIGSW.C.
**********************************************************************************************************/
#define FUEL_MULTIPLE_POWER_MODE_MACRO()                         (FALSE)

/**********************************************************************************************************
** Populate the following with a function that returns 1 when
** "valid conditions" exist for executing the fuel algorithm.
** Set to 1 if not used.
**
** Typical invalid conditions are voltage out of range, or missing
** network messages for systems that provide the fuel A/D via the
** vehicle network.
**
** The definition of this macro will be determined by the product
** specific CRS, and will typically be a function from the source
** code file FFUEL.C.
**********************************************************************************************************/
#define FUEL_MULTIPLE_VALID_CONDITION()                          (TRUE)

/**********************************************************************************************************
** Define the following with a function that returns TRUE when a low
** voltage condition exists. Note that this is only used by the
** "fuel02_keyoff processing_done()" function to allow sleep to occur.
** If you don't need this, then set it to FALSE.
**
** The definition of this macro will be determined by the software engineer,
** and will typically be a function from the source code file IDD01.C.
**
** NOTE:  This should always be set to FALSE unless your product specific
**        CRS indicates otherwise.
**********************************************************************************************************/
#define FUEL_MULTIPLE_LOW_VOLTAGE()                              (FALSE)

/**********************************************************************************************************
** Define the following macros if you require these PIDs in your system.
** Whether or not to enable these PIDs can be determined by reviewing
** the PID section of the product specific Part II diagnostic spec.
**
** IMPORTANT:  Don't define the PIDs associated with the second sender
**             if you only have a single sender system!  If you do,
**             the code will not compile.
**
** C903: fuel sender 1 -- number of good samples taken at init
** C904: fuel sender x -- number of good samples required (NVM)
** C909: fuel sender 1 -- average of all good init samples
** C90A: fuel init ref -- reference used at init and value
** C90B: fuel sender 2 -- number of good samples taken at init
** C90C: fuel sender 2 -- average of all good init samples
** C90D: fuel init ref 2 -- reference used at init and value
** 6185: Fuel Level Analog Input Status #1
** 6187: Fuel Level Analog Input Status #2
**
**
** NOTE:  If FUEL_MULTIPLE_LOG_INIT_ERRORS_TO_NVM is enabled, the following
**        PIDs will automatically be supported and must be added to
**        your diagnostic config file:
**
** PID C90E: 4 byte pointer to RAM buffer containing fuel init information
**           (will only need 2 bytes for Mako micros, but will need more for
**           other micros)
** PID C90F: 2 byte size of RAM buffer in PID C90E
** PID C910: 4 byte pointer to NVM buffer containing fuel init information
**           (will only need 2 bytes for Mako micros, but will need more for
**           other micros)
** PID C911: 2 byte size of NVM buffer in PID C910
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you would like the DTC logging to be active in
** the key on periodic processing.  Comment it out if you want to log
** DTCs yourself (not recommended).
**
** Whether or not you require DTCs to be logged can be determined by
** reviewing the DTC section of the product specific Part II diagnostic
** spec.
**********************************************************************************************************/

/* #define FUEL_MULTIPLE_NEED_DTC_LOGGING */

/**********************************************************************************************************
** Define the following if you would like to control when the DTC logging
** is active.  Set to TRUE if it's always valid.  This can be used to
** disable DTC logging in CRANK or other modes.
**
** When to log DTCs can be found by reviewing the product specific CRS/CDS
** and/or the DTC section of the product specific Part II diagnostic spec.
**********************************************************************************************************/

#define FUEL_MULTIPLE_DTC_LOGGING_ACTIVE()                       (FALSE) //MODIFY BY FCHAO IN 202006002 (KernelInDiagnosticsMode() == FALSE) 

/**********************************************************************************************************
** If you defined FUEL_MULTIPLE_NEED_DTC_LOGGING or FUEL02_NEED_DIAG_SELF_TEST,
** then populate the following with your product specific functions for
** logging sender open or short DTCs.
**
** NOTE:  The CLR macro should always be set to the "KernelErrorNotPresent"
**        function.
**
** NOTE:  The JPM macros are not required unless you have a saddle tank
**        system.
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you require a diagnostic self test function
** in your system.  If so, you must define the "GET..." macros that will
** return the current raw fuel A/D for Sender A and/or B.  The "GET..."
** macro for sender 2 is not needed in single sender systems.
**
** If FUEL_MULTIPLE_NEED_DIAG_EPILOG is defined, the fuel02_KSDiagStartSelfTest()
** function is included when fuel02.c is compiled and it is the
** responsibility of the application to call it by adding it to
** the appropriate diagnostic function list.
**********************************************************************************************************/

#define FUEL_MULTIPLE_GET_LEVEL_SENDER_A()                       ((Fuel_Multiple_Get_SenderA_PF()>>2)*(uint16)256)
#define FUEL_MULTIPLE_GET_LEVEL_SENDER_B()                       ((Fuel_Multiple_Get_SenderB_PFH()>>2)*(uint16)256)

/**********************************************************************************************************
** Define the following if you require a diagnostic epilog function in your
** system.  This function will restart fuel init when exiting diagnostic mode.
**
** If FUEL_MULTIPLE_NEED_DIAG_EPILOG is defined, the fuel02_KSDiagEpilog() function
** is included when fuel02.c is compiled and it is the responsibility of the
** application to call it by adding it to the appropriate diagnostic function
** list.
**********************************************************************************************************/
//#define FUEL_MULTIPLE_NEED_DIAG_EPILOG

/**********************************************************************************************************
** Define the following macro if you require 
** 1. To add following variables to fault record
**    a. FUEL_MULTIPLE_LOG_CONVCYCLE_COUNTER
**    b. FUEL_MULTIPLE_LOG_CONVSAMPLE
**    c. FUEL_MULTIPLE_LOG_SAMPLE_COUNTER
**    d. FUEL_MULTIPLE_LOG_MIN_VX
**    e. FUEL_MULTIPLE_LOG_MAX_VX
**    f. FUEL_MULTIPLE_LOG_SUM_VX
**    g. FUEL02_LOG_invalid_condition
**    i. FUEL02_LOG_ignition_cycle_counter
** and 
** 2. To to have allocated memory for FUEL_MULTIPLE_SENDER_A_TABLE_NVM,FUEL_MULTIPLE_SENDER_B_TABLE_NVM
**    only for the SCEM number of size.
**    (Earlier the it was allocated for size of 5 array irrespective of SCEM size)
**    So if a particular project is using only one SCEM market configuration, with
**    enabling this macro would save 128 bytes for each sender 
**********************************************************************************************************/

/* #define FUEL_MULTIPLE_DATA_TO_FAULT_RECORD */

/**********************************************************************************************************
** Define the following macro is you require to put FUEL_MULTIPLE_SENDER_A_AD_TO_PF_TBL & 
** FUEL_MULTIPLE_SENDER_B_AD_TO_PF_TBL in FUEL02_NVM_SEGMENT. Otherwise they would be allocated in 
** FUEL02_CONSTANT_SEGMENT segment.
**********************************************************************************************************/

/* #define FUEL02_AD_TO_PF_TBL_IN_NVM */

/**********************************************************************************************************
** Define the table to convert from the 5 bits of the B&A SCEM byte into an
** index that is used by FUEL02 to determine which entry in the various
** configuration parameter arrays are active.
**
** The table is a 1 byte input SCEM byte with a 1 byte output index value.
**********************************************************************************************************/

#define FUEL_MULTIPLE_INDEX_TABLE  \
 1,0

/**********************************************************************************************************
** Define the following macro for the number of tanks, or tank
** combinations used.  The only valid values are from 1 to 5.
**********************************************************************************************************/
//MODIFY BY FCHAO IN 20200609
/*#define FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS                (1u)*/

/**********************************************************************************************************
** Define the type of average to use when sampling the fuel A/D input.
** The valid choices are:
** 0 = No average, i.e. single sample
** 1 = Moving average, average of X samples
** 2 = Set with faults, average of X samples, include fault in average
** 3 = Set without faults, average of X samples, ignore faults
**********************************************************************************************************/
#define FUEL_MULTIPLE_AVG_TYPE                                   (4u)

/**********************************************************************************************************
** Define the number of fuel samples to average if the FUEL_MULTIPLE_AVG_TYPE is
** greater than 0. If you set FUEL_MULTIPLE_AVG_TYPE to 0 for no average, then
** set this to 1.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SMPLS_2_AVG                                (1u)

/**********************************************************************************************************
** Define the type of averaging to use to calculate the ZSS and KO
** reference samples.  The valid choices are:
** 0 = No average, i.e. single sample
** 1 = Moving average, average of X samples
** 2 = Set with faults, average of X samples, include fault in average
** 3 = Set without faults, average of X samples, ignore faults
** 4 = Convergence, Ford convergence algorithm only
**********************************************************************************************************/
#define FUEL_MULTIPLE_REF_AVG_TYPE                               (4u)

/**********************************************************************************************************
** Define the table to convert the Sender A fuel_single_rad value to CAN FLPS A
**********************************************************************************************************/
#if 0
#define FUEL_MULTIPLE_CANFLPS_SIZE_A (13)
#define FUEL_MULTIPLE_CANFLPS_A   \
  { (uint16)(12u*256u), (uint16)(254u*256u) }, /*                  */ \
  { (uint16)(12u*256u), (uint16)(254u*256u) }, /* Short            */ \
  { (uint16)(24u*256u), (uint16)(251u*256u) }, /* F Stop           */ \
  { (uint16)(35u*256u), (uint16)(242u*256u) }, /* F                */ \
  { (uint16)(66u*256u), (uint16)(185u*256u) }, /* 3/4              */ \
  { (uint16)(110u*256u), (uint16)(127u*256u) }, /* 1/2              */ \
  { (uint16)(158u*256u), (uint16)(70u*256u) }, /* 1/4              */ \
  { (uint16)(226u*256u), (uint16)(12u*256u) }, /* E                */ \
  { (uint16)(235u*256u), (uint16)(6u*256u) }, /*                  */ \
  { (uint16)(241u*256u), (uint16)(3u*256u) }, /* E Stop           */ \
  { (uint16)(255u*256u), (uint16)(0u*256u) }, /* Open             */ \
  { (uint16)(0xffffu),    (uint16)(0xffffu) }, /* Currently unused */ \
  { (uint16)(0xffffu),    (uint16)(0xffffu) }, /* Currently unused */ \

/*
** Define the table to convert the Sender B fuel_single_rad value to CAN FLPS B
*/
#define FUEL_MULTIPLE_CANFLPS_SIZE_B (13)
#define FUEL_MULTIPLE_CANFLPS_B   \
  { (uint16)(12u*256u), (uint16)(254u*256u) }, /*                  */ \
  { (uint16)(12u*256u), (uint16)(254u*256u) }, /* Short            */ \
  { (uint16)(24u*256u), (uint16)(251u*256u) }, /* F Stop           */ \
  { (uint16)(35u*256u), (uint16)(242u*256u) }, /* F                */ \
  { (uint16)(66u*256u), (uint16)(185u*256u) }, /* 3/4              */ \
  { (uint16)(110u*256u), (uint16)(127u*256u) }, /* 1/2              */ \
  { (uint16)(158u*256u), (uint16)(70u*256u) }, /* 1/4              */ \
  { (uint16)(226u*256u), (uint16)(12u*256u) }, /* E                */ \
  { (uint16)(235u*256u), (uint16)(6u*256u) }, /*                  */ \
  { (uint16)(241u*256u), (uint16)(3u*256u) }, /* E Stop           */ \
  { (uint16)(255u*256u), (uint16)(0u*256u) }, /* Open             */ \
  { (uint16)(0xffffu),    (uint16)(0xffffu) }, /* Currently unused */ \
  { (uint16)(0xffffu),    (uint16)(0xffffu) }, /* Currently unused */ \
#else

#endif
/**********************************************************************************************************
** Define the following to take a single reference fuel sample (ZSS) that
** is taken regardless of the ignition switch position.
**
** Comment it out if you don't need it.
**********************************************************************************************************/
/*#define FUEL_MULTIPLE_ZSS_REF_ONLY*/

/**********************************************************************************************************
** Define the following to select the resolution to use when
** comparing the input FLPS value versus the slosh filter.
** If set to 1, the 1 byte input FLPS will be compared
** to the 1 byte MSB of the slosh filter to see if the filter
** should be incremented or decremented.  If set to 0,
** the comparison will be 2 bytes.
**********************************************************************************************************/
#define FUEL_MULTIPLE_FILTER_RES                                 (1u)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel initialization configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you want hill hold enabled.  Otherwise, comment
** it out.
**********************************************************************************************************/
#define FUEL_MULTIPLE_HILL_HOLD_ENABLE

/**********************************************************************************************************
** Set the following to 1 if you require a filter jam with no good fuel
** init reference samples and hill hold is enabled.  Comment it out
** or set to 0 to disable.
**********************************************************************************************************/
#define FUEL_MULTIPLE_FORCE_FILT_JAM                             (0u)

/**********************************************************************************************************
** Define the time period after the ignition switch has transitioned into
** RUN before fuel init samples are to be taken.  The time base for this
** counter will be the same as that chosen for the filter rate, and
** the counter should be long enough to ensure that any power fluctuations
** have stabilized enough to get good samples.
**********************************************************************************************************/
#define FUEL_MULTIPLE_IGNON_DELAY_TIME                           Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 3 / 10 //(6u)  20*3/10= 0.6s

/**********************************************************************************************************
** Define the time period after power stabilization during which to take
** fuel init samples.  Once this time period has expired, a one-time
** fuel init will take place.  The time base for this counter will be the
** same as that chosen for the filter rate, and the counter should be long
** enough to ensure that a good quantity of init samples will be taken.
**********************************************************************************************************/
#define FUEL_MULTIPLE_INIT_DELAY_COUNT_TIME             		 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 7 / 10 //(14u)  20*7/10= 1.4s

/**********************************************************************************************************
** Define the number of good samples required at fuel init in order to
** test for a filter jam.
**********************************************************************************************************/
#define FUEL_MULTIPLE_INIT_GOOD_SAMPLES_REQUIRED        		 (10u)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
*/
#define FUEL_MULTIPLE_POSITIVE_INIT_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(7461u)  	/* 7L */
#define FUEL_MULTIPLE_POSITIVE_INIT_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(7461u)	/* 7L */

/**********************************************************************************************************
** Define the minimum delta decrease ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
**********************************************************************************************************/
#define FUEL_MULTIPLE_NEGATIVE_INIT_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(42638u)
#define FUEL_MULTIPLE_NEGATIVE_INIT_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(42638u)

/*
Define the reference value of Fuel to judge the speed
*/
#define FUEL_MULTIPLE_ZSS_HALT_SPEED                             Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)  


/**********************************************************************************************************
** Define the secondary delta init fill positive and negative values.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SEC_POS_INIT_FILL_DELTA_A                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(30))
#define FUEL_MULTIPLE_SEC_POS_INIT_FILL_DELTA_B                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(30))

#define FUEL_MULTIPLE_SEC_NEG_INIT_FILL_DELTA_A                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(30))
#define FUEL_MULTIPLE_SEC_NEG_INIT_FILL_DELTA_B                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(30))

/**********************************************************************************************************
** Define the threshold at which to check for rental car topoff.   The
** MSB of the fuel filter must exceed this threshold before a check will
** take place.
**
** By setting this value to 0xFF, rental car topoff will be disabled.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SENDERA_RC_FILL_THRESHOLD                  (65024u)
#define FUEL_MULTIPLE_SENDERB_RC_FILL_THRESHOLD                  (65024u)

/**********************************************************************************************************
** Define the fill check to use for rental car topoff.  If the MSB of
** the fuel filter exceeds the above threshold by this amount, the
** fuel filter will be jammed.
**
** By setting this value to 0xFF, rental car topoff will be disabled.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SENDERA_RC_FILL_DELTA                      (3198u)
#define FUEL_MULTIPLE_SENDERB_RC_FILL_DELTA                      (65024u)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel open/short configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Ratioed A/D values GREATER than the following are considered open.
** Setting this value to "0xFFFF" will effectively stop open detect.
**********************************************************************************************************/
#define FUEL_MULTIPLE_OPEN_SENDER_LIMIT_A                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)
#define FUEL_MULTIPLE_OPEN_SENDER_LIMIT_B                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)

/**********************************************************************************************************
** Ratioed A/D values LESS than the following are considered shorted.
** Setting this value to "0" will effectively stop short detect.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SHORTED_SENDER_LIMIT_A                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
#define FUEL_MULTIPLE_SHORTED_SENDER_LIMIT_B                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
/**********************************************************************************************************
** Define the time period for debouncing an open/short sender.  The time base
** for these counters will be the same as that chosen for the filter rate.
**********************************************************************************************************/
#define FUEL_MULTIPLE_OPEN_SHORT_FAULT_TIME                      Fuel_Api_Config_Data_NVM_Pkg_Get_Data(2)//(100u)

/**********************************************************************************************************
** Define the time period for recovering from an open/short sender.  The time
** base for these counters will be the same as that chosen for the filter
** rate.
**********************************************************************************************************/
#define FUEL_MULTIPLE_OPEN_SHORT_RECOVERY_TIME                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(3)//(100u)

/**********************************************************************************************************
** Define the following if you want the Honda open/short recovery filter jam
** feature enabled.  Otherwise, comment it out.
**********************************************************************************************************/
#define FUEL_MULTIPLE_FF_RECOV_FLTR_JAM_ENABLE

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel fast fill configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you want fast fill enabled.  Otherwise, comment
** it out.
**********************************************************************************************************/
#define FUEL_MULTIPLE_FAST_FILL_ENABLE

/**********************************************************************************************************
** Define the rate at which the zero speed counter is to be incremented.
** This constant times the rate of the fuel filter algorithm will define
** the time after zero speed at which to store the A/D sample for init
** and fast fill purposes.
**********************************************************************************************************/
#define FUEL_MULTIPLE_ZERO_SPEED_COUNTER                         (73u)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_MULTIPLE_POSITIVE_FAST_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(7461u)
#define FUEL_MULTIPLE_POSITIVE_FAST_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(7461u)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_MULTIPLE_NEGATIVE_FAST_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(42638u)
#define FUEL_MULTIPLE_NEGATIVE_LEAK_FAST_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(28)//(42638u)

#define FUEL_MULTIPLE_NEGATIVE_FAST_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(27)//(42638u)

/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "fast" mode of
** operation.  It can be set to the same value as the "normal"
** mode base if "fast" mode is not desired.
**********************************************************************************************************/
/*#define FUEL_MULTIPLE_DELTA_FAST_BASE_A                        (0xC3126EAuL)
#define FUEL_MULTIPLE_DELTA_FAST_BASE_B                          (0xC3126EAuL)	
#define FUEL_MULTIPLE_DELTA_FAST_BASE_A                          (0x1381D7DuL)
#define FUEL_MULTIPLE_DELTA_FAST_BASE_B                          (0x1381D7DuL)*/
#define FUEL_MULTIPLE_DELTA_FAST_BASE_A                           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(21))// (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12))//(13971845uL)
#define FUEL_MULTIPLE_DELTA_FAST_BASE_B                           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(22)) //(13971845uL)
/**********************************************************************************************************
** Define the "adjustment" factor that is added to the least significant
** word of the 4 byte fuel filter whenever consecutive samples of the fuel
** A/D fall on the same side of the filter.  This value is used when the
** filter is running in "fast" mode, and can be set to "0" if no adjustment
** is desired.
**
** For example, if two samples in a row fall below the current filter value,
** this constant will be subtracted from the filter along with the delta
** value defined above.  Three samples mean that twice this value is
** subtracted, and so on.  Whenever a sample on the opposite side of the
** filter is encountered, the number of adjustment factors to be added
** is reset to zero.
**********************************************************************************************************/
#define FUEL_MULTIPLE_DELTA_FAST_ADJUST_A                        (0u)
#define FUEL_MULTIPLE_DELTA_FAST_ADJUST_B                        (0u)

/**********************************************************************************************************
** Define a max clamp value for the fuel delta when in fast mode.
**********************************************************************************************************/
#define FUEL_MULTIPLE_DELTA_FAST_CLAMP_A                         (0x00FFFFFFuL)
#define FUEL_MULTIPLE_DELTA_FAST_CLAMP_B                         (0x00FFFFFFuL)


/**********************************************************************************************************
** Define the following if you want the Honda fast fill rate check enabled.
** Otherwise, comment it out.
**********************************************************************************************************/
/*#define FUEL_MULTIPLE_FFRC_ENABLE*/

/**********************************************************************************************************
** Define the rate at which raw fuel samples are taken to create the moving
** fuel sample window.  This is needed if you enable FUEL_MULTIPLE_FFRC_ENABLE.
**********************************************************************************************************/
#define FUEL_MULTIPLE_RATE_CHECK_TIMER_START_VALUE               (10u)

/**********************************************************************************************************
** If you define FUEL_MULTIPLE_FFRC_ENABLE, then define the number of raw fuel
** samples to be taken at the fuel sample rate in the moving window.
**********************************************************************************************************/
#define FUEL_MULTIPLE_MAX_RATE_CHECK_SAMPLES                     (5u)

/**********************************************************************************************************
** If you define FUEL_MULTIPLE_FFRC_ENABLE, then set the lower rate check limit.
**********************************************************************************************************/
#define FUEL_MULTIPLE_LOWER_RATE_CHECK_LIMIT_A                   (570u)
#define FUEL_MULTIPLE_LOWER_RATE_CHECK_LIMIT_B                   (0u)

/**********************************************************************************************************
** If you define FUEL_MULTIPLE_FFRC_ENABLE, then set the upper rate check limit.
**********************************************************************************************************/
#define FUEL_MULTIPLE_UPPER_RATE_CHECK_LIMIT_A                   (8554u)
#define FUEL_MULTIPLE_UPPER_RATE_CHECK_LIMIT_B                   (0u)

/**********************************************************************************************************
** Define the time that the fast fill mode is enabled following a key on
** initialization that does not read the required number of good fuel
** samples.
**********************************************************************************************************/
#define FUEL_MULTIPLE_AVG_VOL_INVALID_TIME                       (0u) // modify by fchao in 20200919 (900u)

/**********************************************************************************************************
** Define the time that the fast fill mode determination is debounced
** before fast fill mode can be entered (due to sloshing present fuel
** level)
**********************************************************************************************************/
#define FUEL_MULTIPLE_MIN_FAST_FILL_TIME                         Fuel_Api_Config_Data_NVM_Pkg_Get_Data(11)//(30u)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel slosh filter configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the four byte slosh filter empty preload.  This value is stored
** in the slosh filter during a cold init, and is the filter value that will
** end up being used if the fuel init fails.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SLOSH_FILTER_EMPTY_PRELOAD_A               (0x00000000uL)
#define FUEL_MULTIPLE_SLOSH_FILTER_EMPTY_PRELOAD_B               (0x00000000uL)

/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "normal" mode of
** operation.
**********************************************************************************************************/
/*#define FUEL_MULTIPLE_DELTA_NORMAL_BASE_A                        (0x1156FuL)
#define FUEL_MULTIPLE_DELTA_NORMAL_BASE_B                        (0x1156FuL)*/
#define FUEL_MULTIPLE_DELTA_NORMAL_BASE_A                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(24)//(139718ul)//100min
#define FUEL_MULTIPLE_DELTA_NORMAL_BASE_B                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(24)//(139718ul)

#define FUEL_MULTIPLE_DELTA_NORMAL_IDLE_BASE_A                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(26)//(8732ul)
#define FUEL_MULTIPLE_DELTA_NORMAL_IDLE_BASE_B                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(26)//(8732ul)

#define FUEL_MULTIPLE_DELTA_NORMAL_LOW_BASE_A                    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(23)//(34929ul)
#define FUEL_MULTIPLE_DELTA_NORMAL_LOW_BASE_B                    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(23)//(34929ul)
/**********************************************************************************************************
** Define the "adjustment" factor that is added to the least significant
** word of the 4 byte fuel filter whenever consecutive samples of the fuel
** A/D fall on the same side of the filter.  This value is used when the
** filter is running in "normal" mode, and can be set to "0" if no adjustment
** is desired.
**
** For example, if two samples in a row fall below the current filter value,
** this constant will be subtracted from the filter along with the delta
** value defined above.  Three samples mean that twice this value is
** subtracted, and so on.  Whenever a sample on the opposite side of the
** filter is encountered, the number of adjustment factors to be added
** is reset to zero.
**********************************************************************************************************/
#define FUEL_MULTIPLE_DELTA_NORMAL_ADJUST_A                      (0u)
#define FUEL_MULTIPLE_DELTA_NORMAL_ADJUST_B                      (0u)

/**********************************************************************************************************
** Define a max clamp value for the fuel delta when in normal mode.
**********************************************************************************************************/
#define FUEL_MULTIPLE_DELTA_NORMAL_CLAMP_A                       (0x00400000uL)
#define FUEL_MULTIPLE_DELTA_NORMAL_CLAMP_B                       (0x00400000uL)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms that
** the percent full value must change by in response to a filter change.
**
** By setting this constant to 0 or 1, there will effectively be
** no hysteresis applied.
**********************************************************************************************************/
#define FUEL_MULTIPLE_PERCENT_FULL_POSITIVE_HYST_A               (325u)
#define FUEL_MULTIPLE_PERCENT_FULL_POSITIVE_HYST_B               (325u)

/**********************************************************************************************************
** Define the minimum delta decrease ( >= ) in percent full terms that
** the percent full value must change by in response to a filter change.
**
** By setting this constant to 0 or 1, there will effectively be
** no hysteresis applied.
**********************************************************************************************************/
#define FUEL_MULTIPLE_PERCENT_FULL_NEGATIVE_HYST_A               (325u)
#define FUEL_MULTIPLE_PERCENT_FULL_NEGATIVE_HYST_B               (325u)

/**********************************************************************************************************
** Define the table to convert sender A from A/D to FLPS.
**********************************************************************************************************/

#define FUEL_MULTIPLE_ALL_VOLUME                 ((uint64)Fuel_API_Muti_Get_Tank_Size())
#define FUEL_MULTIPLE_AUX_VOLUME                 ((uint64)Fuel_API_Muti_Aux_Get_Tank_Size())
#define FUEL_MULTIPLE_MAIN_VOLUME                ((uint64)(FUEL_MULTIPLE_ALL_VOLUME-FUEL_MULTIPLE_AUX_VOLUME))

/******* old parameter******************************************************************************************/

#define FUEL_MULTIPLE_SENDER_A_AD_TO_PF_TBL_SIZE (32)
#define FUEL_MULTIPLE_SENDER_A_AD_TO_PF_TBL	\
{(uint16)(876u), (uint16)(2678u)},\
{(uint16)(876u), (uint16)(254u*256u)},/*50ohm   34L*/\
{(uint16)(956u), (uint16)(55462u)},/*56ohm      29L*/\
{(uint16)(1044u),(uint16)(54505u)},/*63ohm      28.5L*/\
{(uint16)(1128u),(uint16)(52593u)},/*70ohm      27.5L*/\
{(uint16)(1185u),(uint16)(51637u)},/*75ohm      27L*/\
{(uint16)(1282u),(uint16)(49724u)},/*84ohm      26L*/\
{(uint16)(1372u),(uint16)(47812u)},/*93ohm      25L*/\
{(uint16)(1439u),(uint16)(45899u)},/*100ohm     24L*/\
{(uint16)(1538u),(uint16)(43987u)},/*111ohm     23L*/\
{(uint16)(1629u),(uint16)(42074u)},/*122ohm     22L*/\
{(uint16)(1786u),(uint16)(40162u)},/*143ohm     21L*/\
{(uint16)(1854u),(uint16)(38249u)},/*153ohm     20L*/\
{(uint16)(1918u),(uint16)(36337u)},/*163ohm     19L*/\
{(uint16)(1979u),(uint16)(34424u)},/*173ohm     18L*/\
{(uint16)(2091u),(uint16)(32512u)},/*193ohm     17L*/\
{(uint16)(2142u),(uint16)(30600u)},/*203ohm     16L*/\
{(uint16)(2182u),(uint16)(28687u)},/*211ohm     15L*/\
{(uint16)(2265u),(uint16)(26775u)},/*229ohm     14L*/\
{(uint16)(2299u),(uint16)(24862u)},/*237ohm     13L*/\
{(uint16)(2369u),(uint16)(22950u)},/*254ohm     12L*/\
{(uint16)(2430u),(uint16)(21037u)},/*270ohm     11L*/\
{(uint16)(2458u),(uint16)(19125u)},/*278ohm     10L*/\
{(uint16)(2489u),(uint16)(17212u)},/*287ohm     9L*/\
{(uint16)(2532u),(uint16)(15300u)},/*300ohm     8L*/\
{(uint16)(2560u),(uint16)(13387u)},/*309ohm     7L*/\
{(uint16)(2573u),(uint16)(11478u)},/*313ohm     6L*/\
{(uint16)(2603u),(uint16)(9562u)},/*323ohm      5L*/\
{(uint16)(2626u),(uint16)(7650u)},/*331ohm      4L*/\
{(uint16)(2651u),(uint16)(5737u)},/*340ohm      3L*/\
{(uint16)(2670u),(uint16)(3825u)},/*347ohm      2L*/\
{(uint16)(2678u),(uint16)(3825u)},/*350ohm      2L*/\
/*2021/01/29 Communicate with system about the change of dead oil area at point E*/
//{(uint16)(2678u),(uint16)(1912u)},/*350ohm      1L*/\

/**********************************************************************************************************
** Define the table to convert sender B from A/D to FLPS.
**
** This is used if FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS is not defined.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SENDER_B_AD_TO_PF_TBL_SIZE (29)
#define FUEL_MULTIPLE_SENDER_B_AD_TO_PF_TBL	\
{(uint16)(875u), (uint16)(2678u)},\
{(uint16)(875u), (uint16)(254u*256u)},/*50ohm   27L*/\
{(uint16)(955u),(uint16)(63820u)},/*56ohm       26.5L*/\
{(uint16)(1043u),(uint16)(61412u)},/*63ohm      25.5L*/\
{(uint16)(1127u),(uint16)(60207u)},/*70ohm      25L*/\
{(uint16)(1195u),(uint16)(57799u)},/*76ohm      24L*/\
{(uint16)(1281u),(uint16)(55391u)},/*84ohm      23L*/\
{(uint16)(1372u),(uint16)(52983u)},/*93ohm      22L*/\
{(uint16)(1538u),(uint16)(50574u)},/*111ohm     21L*/\
{(uint16)(1629u),(uint16)(48166u)},/*122ohm     20L*/\
{(uint16)(1713u),(uint16)(45758u)},/*133ohm     19L*/\
{(uint16)(1854u),(uint16)(43349u)},/*153ohm     18L*/\
{(uint16)(1918u),(uint16)(40941u)},/*163ohm     17L*/\
{(uint16)(1979u),(uint16)(38533u)},/*173ohm     16L*/\
{(uint16)(2091u),(uint16)(36124u)},/*193ohm     15L*/\
{(uint16)(2142u),(uint16)(33716u)},/*203ohm     14L*/\
{(uint16)(2223u),(uint16)(31308u)},/*220ohm     13L*/\
{(uint16)(2299u),(uint16)(28900u)},/*237ohm     12L*/\
{(uint16)(2336u),(uint16)(26491u)},/*246ohm     11L*/\
{(uint16)(2399u),(uint16)(24083u)},/*262ohm     10L*/\
{(uint16)(2430u),(uint16)(21675u)},/*270ohm     9L*/\
{(uint16)(2489u),(uint16)(19266u)},/*287ohm     8L*/\
{(uint16)(2515u),(uint16)(16858u)},/*295ohm     7L*/\
{(uint16)(2544u),(uint16)(14450u)},/*304ohm     6L*/\
{(uint16)(2575u),(uint16)(12041u)},/*314ohm     5L*/\
{(uint16)(2602u),(uint16)(9633u)},/*323ohm      4L*/\
{(uint16)(2626u),(uint16)(7225u)},/*331ohm      3L*/\
{(uint16)(2651u),(uint16)(4817u)},/*340ohm      2L*/\
{(uint16)(2678u),(uint16)(0)},/*340ohm      2L*/\
//{(uint16)(2680u),(uint16)(2408u)},/*351ohm      1L*/\
/*2021/01/29 Communicate with system about the change of dead oil area at point E*/



/**********************************************************************************************************
** --------------------------------------------------------------------------
** Reference sample (ZSS, KO) convergence / sampling configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the maximum allowed key-off sampling time (in units of the
** filter iteration rate).
**********************************************************************************************************/
#define FUEL_MULTIPLE_IGNOFF_SAMPLE_TIME                         (400u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_MULTIPLE_REF_AVG_TYPE=4).
** This controls the number of raw samples taken in a convergence cycle.
** If you don't use KOC, then any value is OK since it won't be used.
**********************************************************************************************************/
#define FUEL_MULTIPLE_KOS_CYCLES                                 (4u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_MULTIPLE_REF_AVG_TYPE=4).
** This controls the maximum number of convergence cycles to take.
** If you don't use KOC, then any value is OK since it won't be used.
**********************************************************************************************************/
#define FUEL_MULTIPLE_KOS_COUNTS                                 (50u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_MULTIPLE_REF_AVG_TYPE=4).
** This controls the minimum number of unfaulted samples in a convergence
** cycle that is required.  If we don't get this many, then that cycle
** did not converge.  If you don't use KOC, then any value is OK since
** it won't be used.
**********************************************************************************************************/
#define FUEL_MULTIPLE_KOS_MIN_SMPLS                              (20u)

/**********************************************************************************************************
** Define the delta between the min and max sample in a key-off
** convergence window.  If the delta is less than this value, the
** samples are considered converged.
**********************************************************************************************************/
#define FUEL_MULTIPLE_KO_DELTA_A                                 (3198)
#define FUEL_MULTIPLE_KO_DELTA_B                                 (3198)

/**********************************************************************************************************
** Define the following 3 values for the fast fill convergence.
** These definitions are identical to the 3 defined above, except
** these are for fast fill.
**********************************************************************************************************/
#define FUEL_MULTIPLE_ZS_CYCLES                                  (4u)
#define FUEL_MULTIPLE_ZS_COUNTS                                  (50u)
#define FUEL_MULTIPLE_ZS_MIN_SMPLS                               (30u)

/**********************************************************************************************************
** Define the delta between the min and max sample in a fast fill
** convergence window.  If the delta is less than this value, the
** samples are considered converged.
**********************************************************************************************************/
#define FUEL_MULTIPLE_ZS_DELTA_A                                 (3198)
#define FUEL_MULTIPLE_ZS_DELTA_B                                 (3198)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Dual sender / saddle tank configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Set the JPM fault delay time.  This is the time after a cold init
** during which a JPM fault will not be declared, and is intended
** for use only at the B&A plant.
**********************************************************************************************************/
#define FUEL_MULTIPLE_JPM_FAULT_DELAY_TIME                       (0u)

/**********************************************************************************************************
** For dual sender systems, declare a fault if the filtered percent full
** of sender A is < FUEL_MULTIPLE_SENDERA_ERROR and that of the sender B is
** > FUEL_MULTIPLE_SENDERB_ERROR.  Ford requires <= and >= in the evaluations.
** To accommodate an equivalency of the requirement but still being able to 
** turn off the checks by using 0 and 255, respectively, we use actual values
** of TARGET + 1 and TARGET - 1, respectively, and leave the signs < and >.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SENDERA_ERROR                              (12 * 256u)
#define FUEL_MULTIPLE_SENDERB_ERROR                              (13 * 256u)

/**********************************************************************************************************
** For dual sender systems, define the weighting by percentage of the
** total tank volume for sender A and sender B.
**
** Note that (w1+w2)/256 must be 1 or the weights are invalid.
**********************************************************************************************************/


#define FUEL_MULTIPLE_SENDERB_WEIGHT   (65536ull*Fuel_API_Muti_Aux_Get_Tank_Size()/Fuel_API_Muti_Get_Tank_Size()) //Fuel_API_Muti_Aux_Get_Tank_Size()
#define FUEL_MULTIPLE_SENDERA_WEIGHT   (65536u-FUEL_MULTIPLE_SENDERB_WEIGHT) //Fuel_API_Muti_Get_Tank_Size 

/**********************************************************************************************************
** Define the following for enabling saddle tanks in your system.  Any index
** where there is a 1 indicates a saddle tank, otherwise a 0 indicates that
** it is not a saddle tank.
**
** This entry must be the same size as FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS,
** i.e. if FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS is set to 4, then this should
** be an array of 4 entries.  The value returned from the FUEL_MULTIPLE_INDEX_TABLE
** lookup function will indicate which index into this array that the
** software is to use.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SADDLE_TANK_SYSTEM                         (1u)

/**********************************************************************************************************
** Define the following for enabling a second sender in your system.  Any
** index where there is a 1 indicates a second sender is active, otherwise
** a 0 indicates that there is only one sender.  Please note that a second
** sender can mean either a dual tank system or saddle tank system,
** and FUEL_MULTIPLE_SADDLE_TANK_SYSTEM then decides which type.
**
** This entry must be the same size as FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS,
** i.e. if FUEL_MULTIPLE_SCEM_NUMBER_OF_FUEL_TANKS is set to 4, then this should
** be an array of 4 entries.  The value returned from the FUEL_MULTIPLE_INDEX_TABLE
** lookup function will indicate which index into this array that the
** software is to use.
**********************************************************************************************************/
#define FUEL_MULTIPLE_SENDER_B_ENABLE                            (1u)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** NVM fault logging configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you would like log the fuel init values to NVM.
** Comment it out if not used.
**
** Note: If you use this NVM logging, you need to make sure the queue size
**       in the eprom manager is big enough (EPM_Q_SIZE).
**********************************************************************************************************/
#define FUEL_MULTIPLE_LOG_INIT_ERRORS_TO_NVM

/**********************************************************************************************************
** Define the number of 'records' you want to store in RAM.
** Comment it out if not used.
**********************************************************************************************************/
#define FUEL_MULTIPLE_RAM_LOG_FAULT_RECORD_SIZE                  (0u)

/**********************************************************************************************************
** Define the number of 'records' you want to store in NVM.
** Comment it out if not used.
**********************************************************************************************************/
#define FUEL_MULTIPLE_LOG_FAULT_RECORD_SIZE                      (0u)

/**********************************************************************************************************
** Set the following to the number of samples on the same side of the
** filter that need to occur before the fuel data is declared faulted
** and logged to NVM.
**********************************************************************************************************/
#define FUEL_MULTIPLE_ERR_CNT                                    (3000u)

#define FUEL_MULTIPLE_FAST_FILL_MET_MACRO()                (Fuel_Multiple_Zero_Speed_Check())

#define FUEL_MULTIPLE_ZSS_MET_MACRO()                      (Fuel_Multiple_Zss_Speed_Check())

#define FUEL_MULTIPLE_FUEL_LOW_STATUS()                	   (Fuel_Multiple_Api_Get_Fuel_Low_Status())

#define FUEL_MULTIPLE_ENGINE_RUNNING_STATUS()              (Fuel_Api_Get_EngSpd_State())

#define FUEL_MULTIPLE_IFC_AVG_RATE()                       (Fuel_Rte_Api_Get_IFC_10S_Rate())


// TRUE:Enable fuel leaking fun; FALSE:Disable fuel leaking fun
#define FUEL_MULTIPLE_LEAKING_ENABLE  (1)


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

