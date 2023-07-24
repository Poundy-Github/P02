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
#include "SWC_Fuel_Dual_Process.h"
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
#define FUEL_DUAL_GET_FUEL_SCEM()                            (1u)

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
#define FUEL_DUAL_TANK_SELECTION_MACRO()                     (0u)

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
//#define FUEL_DUAL_POWER_MODE_MACRO()                         (FALSE)

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
#define FUEL_DUAL_VALID_CONDITION()                          (TRUE)

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
#define FUEL_DUAL_LOW_VOLTAGE()                              (FALSE)

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
** NOTE:  If FUEL_DUAL_LOG_INIT_ERRORS_TO_NVM is enabled, the following
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

/* #define FUEL_DUAL_NEED_DTC_LOGGING */

/**********************************************************************************************************
** Define the following if you would like to control when the DTC logging
** is active.  Set to TRUE if it's always valid.  This can be used to
** disable DTC logging in CRANK or other modes.
**
** When to log DTCs can be found by reviewing the product specific CRS/CDS
** and/or the DTC section of the product specific Part II diagnostic spec.
**********************************************************************************************************/

#define FUEL_DUAL_DTC_LOGGING_ACTIVE()                       (FALSE) //MODIFY BY FCHAO IN 202006002 (KernelInDiagnosticsMode() == FALSE) 

/**********************************************************************************************************
** If you defined FUEL_DUAL_NEED_DTC_LOGGING or FUEL02_NEED_DIAG_SELF_TEST,
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
** If FUEL_DUAL_NEED_DIAG_EPILOG is defined, the fuel02_KSDiagStartSelfTest()
** function is included when fuel02.c is compiled and it is the
** responsibility of the application to call it by adding it to
** the appropriate diagnostic function list.
**********************************************************************************************************/

#define FUEL_DUAL_GET_LEVEL_SENDER_A()                       ((Fuel_Dual_Get_SenderA_PF()>>2)*(uint16)256)
#define FUEL_DUAL_GET_LEVEL_SENDER_B()                       ((Fuel_Dual_Get_SenderB_PFH()>>2)*(uint16)256)

/**********************************************************************************************************
** Define the following if you require a diagnostic epilog function in your
** system.  This function will restart fuel init when exiting diagnostic mode.
**
** If FUEL_DUAL_NEED_DIAG_EPILOG is defined, the fuel02_KSDiagEpilog() function
** is included when fuel02.c is compiled and it is the responsibility of the
** application to call it by adding it to the appropriate diagnostic function
** list.
**********************************************************************************************************/
//#define FUEL_DUAL_NEED_DIAG_EPILOG

/**********************************************************************************************************
** Define the following macro if you require 
** 1. To add following variables to fault record
**    a. FUEL_DUAL_LOG_CONVCYCLE_COUNTER
**    b. FUEL_DUAL_LOG_CONVSAMPLE
**    c. FUEL_DUAL_LOG_SAMPLE_COUNTER
**    d. FUEL_DUAL_LOG_MIN_VX
**    e. FUEL_DUAL_LOG_MAX_VX
**    f. FUEL_DUAL_LOG_SUM_VX
**    g. FUEL02_LOG_invalid_condition
**    i. FUEL02_LOG_ignition_cycle_counter
** and 
** 2. To to have allocated memory for FUEL_DUAL_SENDER_A_TABLE_NVM,FUEL_DUAL_SENDER_B_TABLE_NVM
**    only for the SCEM number of size.
**    (Earlier the it was allocated for size of 5 array irrespective of SCEM size)
**    So if a particular project is using only one SCEM market configuration, with
**    enabling this macro would save 128 bytes for each sender 
**********************************************************************************************************/

/* #define FUEL_DUAL_DATA_TO_FAULT_RECORD */

/**********************************************************************************************************
** Define the following macro is you require to put FUEL_DUAL_SENDER_A_AD_TO_PF_TBL & 
** FUEL_DUAL_SENDER_B_AD_TO_PF_TBL in FUEL02_NVM_SEGMENT. Otherwise they would be allocated in 
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

#define FUEL_DUAL_INDEX_TABLE  \
 1,0

/**********************************************************************************************************
** Define the following macro for the number of tanks, or tank
** combinations used.  The only valid values are from 1 to 5.
**********************************************************************************************************/

#define FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS                 (2u) //2 :FUEL_DUAL_INDEX_MAX

/**********************************************************************************************************
** Define the type of average to use when sampling the fuel A/D input.
** The valid choices are:
** 0 = No average, i.e. single sample
** 1 = Moving average, average of X samples
** 2 = Set with faults, average of X samples, include fault in average
** 3 = Set without faults, average of X samples, ignore faults
**********************************************************************************************************/
#define FUEL_DUAL_AVG_TYPE                                   (4u)

/**********************************************************************************************************
** Define the number of fuel samples to average if the FUEL_DUAL_AVG_TYPE is
** greater than 0. If you set FUEL_DUAL_AVG_TYPE to 0 for no average, then
** set this to 1.
**********************************************************************************************************/
#define FUEL_DUAL_SMPLS_2_AVG                                (1u)

/**********************************************************************************************************
** Define the type of averaging to use to calculate the ZSS and KO
** reference samples.  The valid choices are:
** 0 = No average, i.e. single sample
** 1 = Moving average, average of X samples
** 2 = Set with faults, average of X samples, include fault in average
** 3 = Set without faults, average of X samples, ignore faults
** 4 = Convergence, Ford convergence algorithm only
**********************************************************************************************************/
#define FUEL_DUAL_REF_AVG_TYPE                               (4u)

/**********************************************************************************************************
** Define the table to convert the Sender A fuel_single_rad value to CAN FLPS A
**********************************************************************************************************/
#if 0
#define FUEL_DUAL_CANFLPS_SIZE_A (13)
#define FUEL_DUAL_CANFLPS_A   \
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
#define FUEL_DUAL_CANFLPS_SIZE_B (13)
#define FUEL_DUAL_CANFLPS_B   \
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
/*#define FUEL_DUAL_ZSS_REF_ONLY*/

/**********************************************************************************************************
** Define the following to select the resolution to use when
** comparing the input FLPS value versus the slosh filter.
** If set to 1, the 1 byte input FLPS will be compared
** to the 1 byte MSB of the slosh filter to see if the filter
** should be incremented or decremented.  If set to 0,
** the comparison will be 2 bytes.
**********************************************************************************************************/
#define FUEL_DUAL_FILTER_RES                                 (1u)

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel initialization configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you want hill hold enabled.  Otherwise, comment
** it out.
**********************************************************************************************************/
#define FUEL_DUAL_HILL_HOLD_ENABLE

/**********************************************************************************************************
** Set the following to 1 if you require a filter jam with no good fuel
** init reference samples and hill hold is enabled.  Comment it out
** or set to 0 to disable.
**********************************************************************************************************/
#define FUEL_DUAL_FORCE_FILT_JAM                             (0u)

/**********************************************************************************************************
** Define the time period after the ignition switch has transitioned into
** RUN before fuel init samples are to be taken.  The time base for this
** counter will be the same as that chosen for the filter rate, and
** the counter should be long enough to ensure that any power fluctuations
** have stabilized enough to get good samples.
**********************************************************************************************************/
#define FUEL_DUAL_IGNON_DELAY_TIME                           Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 3 / 10 //(6u)  20*3/10= 0.6s

/**********************************************************************************************************
** Define the time period after power stabilization during which to take
** fuel init samples.  Once this time period has expired, a one-time
** fuel init will take place.  The time base for this counter will be the
** same as that chosen for the filter rate, and the counter should be long
** enough to ensure that a good quantity of init samples will be taken.
**********************************************************************************************************/
#define FUEL_DUAL_INIT_DELAY_COUNTTIME             		 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 7 / 10) //(14u)  20*7/10= 1.4s

/**********************************************************************************************************
** Define the number of good samples required at fuel init in order to
** test for a filter jam.
**********************************************************************************************************/
#define FUEL_DUAL_INIT_GOOD_SAMPLESREQUIRED        		 (10u)



/*
Define the reference value of Fuel to judge the speed
*/
#define FUEL_DUAL_ZSS_HALT_SPEED                             Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)  


/**********************************************************************************************************
** Define the secondary delta init fill positive and negative values.

**********************************************************************************************************/
#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUALA_SEC_POS_INIT_FILLDELTA_P03        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Exception_Volume_a)) 
#define FUEL_DUALB_SEC_POS_INIT_FILLDELTA_P03        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Exception_Volume_a)) 
#define FUEL_DUALA_SEC_NEG_INIT_FILLDELTA_P03        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Exception_Volume_a)) 
#define FUEL_DUALB_SEC_NEG_INIT_FILLDELTA_P03        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Exception_Volume_a)) 

//#define FUEL_DUAL_SEC_POS_INIT_FILL_DELTA_A_P05        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
//#define FUEL_DUAL_SEC_POS_INIT_FILL_DELTA_B_P05        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
//#define FUEL_DUAL_SEC_NEG_INIT_FILL_DELTA_A_P05        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
//#define FUEL_DUAL_SEC_NEG_INIT_FILL_DELTA_B_P05        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))


/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
*/
#define FUEL_DUAL_A_P03_POSITIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_a))
#define FUEL_DUAL_B_P03_POSITIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_b))

//#define FUEL_DUAL_A_P05_POSITIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17))//(7461u)  	/* 7L */
//#define FUEL_DUAL_B_P05_POSITIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17))//(7461u)	/* 7L */

/**********************************************************************************************************
** Define the minimum delta decrease ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
**********************************************************************************************************/
#define FUEL_DUAL_A_P03_NEGATIVE_INIT_FILL_DELTA               (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_a))
#define FUEL_DUAL_B_P03_NEGATIVE_INIT_FILL_DELTA               (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_b))

//#define FUEL_DUAL_A_P05_NEGATIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17))//(42638u)
//#define FUEL_DUAL_B_P05_NEGATIVE_INIT_FILL_DELTA                 (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17))//(42638u)


#else
#define FUEL_DUAL_SEC_POS_INIT_FILL_DELTA_A                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
#define FUEL_DUAL_SEC_POS_INIT_FILL_DELTA_B                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
 
#define FUEL_DUAL_SEC_NEG_INIT_FILL_DELTA_A                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))
#define FUEL_DUAL_SEC_NEG_INIT_FILL_DELTA_B                  (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18))

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
*/
#define FUEL_DUAL_POSITIVE_INIT_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)  	/* 7L */
#define FUEL_DUAL_POSITIVE_INIT_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)	/* 7L */

/**********************************************************************************************************
** Define the minimum delta decrease ( >= ) in percent full terms that must
** be detected during fuel init to jam the fuel filter.
**********************************************************************************************************/
#define FUEL_DUAL_NEGATIVE_INIT_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)
#define FUEL_DUAL_NEGATIVE_INIT_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)


#endif

/**********************************************************************************************************
** Define the threshold at which to check for rental car topoff.   The
** MSB of the fuel filter must exceed this threshold before a check will
** take place.
**
** By setting this value to 0xFF, rental car topoff will be disabled.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_A_SENDER_RC_FILL_THRESHOLD                {(65024u),(65024u)}  
#define FUEL_DUAL_B_SENDER_RC_FILL_THRESHOLD                {(65024u) ,(65024u)}  
#else
#define FUEL_DUAL_A_SENDER_RC_FILL_THRESHOLD                  (65024u)
#define FUEL_DUAL_B_SENDER_RC_FILL_THRESHOLD                  (65024u)

#endif

/**********************************************************************************************************
** Define the fill check to use for rental car topoff.  If the MSB of
** the fuel filter exceeds the above threshold by this amount, the
** fuel filter will be jammed.
**
** By setting this value to 0xFF, rental car topoff will be disabled.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_A_SENDER_RC_FILL_DELTA                     {(3198u),(3198u)} 
#define FUEL_DUAL_B_SENDER_RC_FILL_DELTA                     {(65024u),(65024u)}
#else
#define FUEL_DUAL_A_SENDER_RC_FILL_DELTA                      (3198u)
#define FUEL_DUAL_B_SENDER_RC_FILL_DELTA                      (65024u)

#endif

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel open/short configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Ratioed A/D values GREATER than the following are considered open.
** Setting this value to "0xFFFF" will effectively stop open detect.
**********************************************************************************************************/
#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

#define FUEL_DUAL_OPEN_SENDER_LIMIT_A_P03    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)
#define FUEL_DUAL_OPEN_SENDER_LIMIT_B_P03    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)  

#define FUEL_DUAL_OPEN_SENDER_LIMIT_A_P05    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)
#define FUEL_DUAL_OPEN_SENDER_LIMIT_B_P05    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)  

#define FUEL_DUAL_SHORTED_SENDER_LIMIT_A_P03                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
#define FUEL_DUAL_SHORTED_SENDER_LIMIT_B_P03                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
#define FUEL_DUAL_SHORTED_SENDER_LIMIT_A_P05                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
#define FUEL_DUAL_SHORTED_SENDER_LIMIT_B_P05                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)

/**********************************************************************************************************
** Define the time period for recovering from an open/short sender.  The time
** base for these counters will be the same as that chosen for the filter
** rate.
**********************************************************************************************************/
#define FUEL_DUAL_OPEN_SHORT_RECOVERY_TIME_P03                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(3)//(100u)
#define FUEL_DUAL_OPEN_SHORT_RECOVERY_TIME_P05                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(3)//(100u)

/**********************************************************************************************************
** Define the time period for debouncing an open/short sender.  The time base
** for these counters will be the same as that chosen for the filter rate.
**********************************************************************************************************/
#define FUEL_DUAL_OPEN_SHORT_FAULT_TIME_P03                      Fuel_Api_Config_Data_NVM_Pkg_Get_Data(2)//(100u)
#define FUEL_DUAL_OPEN_SHORT_FAULT_TIME_P05                      Fuel_Api_Config_Data_NVM_Pkg_Get_Data(2)//(100u)


/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "normal" mode of
** operation.
**********************************************************************************************************/
/*#define FUEL_DUAL_DELTA_NORMAL_BASE_A                        (0x1156FuL)
#define FUEL_DUAL_DELTA_NORMAL_BASE_B                        (0x1156FuL)*/
//#define FUEL_DUAL_DELTA_NORMAL_BASE_A_P03                        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9)) //(139718ul)//100min
//#define FUEL_DUAL_DELTA_NORMAL_BASE_B_P03                        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9))//(139718ul)
/*Damping parameters for rising oil*/
#define FUEL_DUAL_DELTA_UP_BASE_A                       (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_run_fuelup_a)) //(139718ul)//100min
#define FUEL_DUAL_DELTA_UP_BASE_B                       (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_run_fuelup_b))//(139718ul)
/*Damping parameters for oil drop*/
#define FUEL_DUAL_DELTA_DOWN_BASE_A                     (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_run_fueldown_a)) //(139718ul)//100min
#define FUEL_DUAL_DELTA_DOWN_BASE_B                     (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_run_fueldown_b))//(139718ul)

#define FUEL_DUAL_A_P03_DELTA_NORMAL_IDLE_BASE          (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_idle_a))//(8732ul)
#define FUEL_DUAL_B_P03_DELTA_NORMAL_IDLE_BASE          (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_idle_b))//(8732ul)

#define FUEL_DUAL_A_P03_DELTA_NORMAL_LOW_BASE           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_lowfuel_a)) //(34929ul)
#define FUEL_DUAL_B_P03_DELTA_NORMAL_LOW_BASE           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Damp_lowfuel_b)) //(34929ul)

//#define FUEL_DUAL_DELTA_NORMAL_BASE_A_P05                        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9))//(139718ul)//100min
//#define FUEL_DUAL_DELTA_NORMAL_BASE_B_P05                        (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9))//(139718ul)
//
//#define FUEL_DUAL_DELTA_NORMAL_IDLE_BASE_A_P05                   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(13))//(8732ul)
//#define FUEL_DUAL_DELTA_NORMAL_IDLE_BASE_B_P05                   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(13))//(8732ul)
//
//#define FUEL_DUAL_DELTA_NORMAL_LOW_BASE_A_P05                    (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8))//(34929ul)
//#define FUEL_DUAL_DELTA_NORMAL_LOW_BASE_B_P05                    (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8))//(34929ul)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_DUAL_A_P03_POSITIVE_FAST_FILL_DELTA          (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_a))
#define FUEL_DUAL_B_P03_POSITIVE_FAST_FILL_DELTA          (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_b))

//#define FUEL_DUAL_A_P05_POSITIVE_FAST_FILL_DELTA                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)
//#define FUEL_DUAL_B_P05_POSITIVE_FAST_FILL_DELTA                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)
/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_DUAL_A_P03_NEGATIVE_FAST_FILL_DELTA           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_a))
#define FUEL_DUAL_B_P03_NEGATIVE_FAST_FILL_DELTA           (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Refuel_Trigger_b))
#define FUEL_DUAL_A_P03_NEGATIVE_LEAK_FAST_FILL_DELTA      (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Exception_Volume_a)) 

//#define FUEL_DUAL_A_P05_NEGATIVE_FAST_FILL_DELTA                  Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)
//#define FUEL_DUAL_NEGATIVE_LEAK_FAST_FILL_DELTA_A_P05             Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18)//(42638u)
//#define FUEL_DUAL_NEGATIVE_FAST_FILL_DELTA_B_P05                  Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)
/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "fast" mode of
** operation.  It can be set to the same value as the "normal"
** mode base if "fast" mode is not desired.
**********************************************************************************************************/
#define FUEL_DUAL_DELTA_FAST_BASE_A_P03                    (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_RefuelDamping2_a))//(13971845uL)
#define FUEL_DUAL_DELTA_FAST_BASE_B_P03                    (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_RefuelDamping2_b))//(13971845uL)

//#define FUEL_DUAL_DELTA_FAST_BASE_A_P05                          Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)
//#define FUEL_DUAL_DELTA_FAST_BASE_B_P05                          Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)

#else

#define FUEL_DUAL_OPEN_SENDER_LIMIT_A    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)
#define FUEL_DUAL_OPEN_SENDER_LIMIT_B    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)

/**********************************************************************************************************
** Ratioed A/D values LESS than the following are considered shorted.
** Setting this value to "0" will effectively stop short detect.
**********************************************************************************************************/
#define FUEL_DUAL_SHORTED_SENDER_LIMIT_A                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)
#define FUEL_DUAL_SHORTED_SENDER_LIMIT_B                     Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)

/**********************************************************************************************************
** Define the time period for recovering from an open/short sender.  The time
** base for these counters will be the same as that chosen for the filter
** rate.
**********************************************************************************************************/
#define FUEL_DUAL_OPEN_SHORT_RECOVERY_TIME                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(3)//(100u)
/**********************************************************************************************************
** Define the time period for debouncing an open/short sender.  The time base
** for these counters will be the same as that chosen for the filter rate.
**********************************************************************************************************/
#define FUEL_DUAL_OPEN_SHORT_FAULT_TIME                      Fuel_Api_Config_Data_NVM_Pkg_Get_Data(2)//(100u)

/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "normal" mode of
** operation.
**********************************************************************************************************/
/*#define FUEL_DUAL_DELTA_NORMAL_BASE_A                        (0x1156FuL)
#define FUEL_DUAL_DELTA_NORMAL_BASE_B                        (0x1156FuL)*/
#define FUEL_DUAL_DELTA_NORMAL_BASE_A                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9)//(139718ul)//100min
#define FUEL_DUAL_DELTA_NORMAL_BASE_B                        Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9)//(139718ul)

#define FUEL_DUAL_DELTA_NORMAL_IDLE_BASE_A                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(13)//(8732ul)
#define FUEL_DUAL_DELTA_NORMAL_IDLE_BASE_B                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(13)//(8732ul)

#define FUEL_DUAL_DELTA_NORMAL_LOW_BASE_A                    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8)//(34929ul)
#define FUEL_DUAL_DELTA_NORMAL_LOW_BASE_B                    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8)//(34929ul)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_DUAL_POSITIVE_FAST_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)
#define FUEL_DUAL_POSITIVE_FAST_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(7461u)

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms used as one
** of the entrance conditions to "fast" fill mode.  This value could be
** set to a very large number as one method to inhibit fast fill mode.
**********************************************************************************************************/
#define FUEL_DUAL_NEGATIVE_FAST_FILL_DELTA_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)
#define FUEL_DUAL_NEGATIVE_LEAK_FAST_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18)//(42638u)
#define FUEL_DUAL_NEGATIVE_FAST_FILL_DELTA_B                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638u)

/**********************************************************************************************************
** Define the base delta value to be added/subtracted from the 4 byte
** fuel filter when it is appropriate to iterate it.  This value
** more or less determines the "rate" at which the filter moves, and
** is the value used when the filter is running in "fast" mode of
** operation.  It can be set to the same value as the "normal"
** mode base if "fast" mode is not desired.
**********************************************************************************************************/
#define FUEL_DUAL_DELTA_FAST_BASE_A                          Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)
#define FUEL_DUAL_DELTA_FAST_BASE_B                          Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)

#endif







/**********************************************************************************************************
** Define the following if you want the Honda open/short recovery filter jam
** feature enabled.  Otherwise, comment it out.
**********************************************************************************************************/
#define FUEL_DUAL_FF_RECOV_FLTR_JAM_ENABLE

/**********************************************************************************************************
** --------------------------------------------------------------------------
** Fuel fast fill configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/

/**********************************************************************************************************
** Define the following if you want fast fill enabled.  Otherwise, comment
** it out.
**********************************************************************************************************/
#define FUEL_DUAL_FAST_FILL_ENABLE

/**********************************************************************************************************
** Define the rate at which the zero speed counter is to be incremented.
** This constant times the rate of the fuel filter algorithm will define
** the time after zero speed at which to store the A/D sample for init
** and fast fill purposes.
**********************************************************************************************************/
#define FUEL_DUAL_ZERO_SPEED_COUNTER                         (73u)




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

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_DELTA_FAST_ADJUST_A                  { (0u), (0u)}     
#define FUEL_DUAL_DELTA_FAST_ADJUST_B                  { (0u), (0u)}    
#else
#define FUEL_DUAL_DELTA_FAST_ADJUST_A                        (0u)
#define FUEL_DUAL_DELTA_FAST_ADJUST_B                        (0u)
#endif

/**********************************************************************************************************
** Define a max clamp value for the fuel delta when in fast mode.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_DELTA_FAST_CLAMP_A                       {(0x00FFFFFFuL),(0x00FFFFFFuL)}  
#define FUEL_DUAL_DELTA_FAST_CLAMP_B                       {(0x00FFFFFFuL),(0x00FFFFFFuL)}  
#else
#define FUEL_DUAL_DELTA_FAST_CLAMP_A                         (0x00FFFFFFuL)
#define FUEL_DUAL_DELTA_FAST_CLAMP_B                         (0x00FFFFFFuL)

#endif


/**********************************************************************************************************
** Define the following if you want the Honda fast fill rate check enabled.
** Otherwise, comment it out.
**********************************************************************************************************/
/*#define FUEL_DUAL_FFRC_ENABLE*/

/**********************************************************************************************************
** Define the rate at which raw fuel samples are taken to create the moving
** fuel sample window.  This is needed if you enable FUEL_DUAL_FFRC_ENABLE.
**********************************************************************************************************/
#define FUEL_DUAL_RATE_CHECK_TIMER_START_VALUE               (10u)

/**********************************************************************************************************
** If you define FUEL_DUAL_FFRC_ENABLE, then define the number of raw fuel
** samples to be taken at the fuel sample rate in the moving window.
**********************************************************************************************************/
#define FUEL_DUAL_MAX_RATE_CHECK_SAMPLES                     (5u)

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
/**********************************************************************************************************
** If you define FUEL_DUAL_FFRC_ENABLE, then set the lower rate check limit.
**********************************************************************************************************/
#define FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_A                 {(570u),(570u)}  
#define FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_B                 {(0u),(0u)}  

/**********************************************************************************************************
** If you define FUEL_DUAL_FFRC_ENABLE, then set the upper rate check limit.
**********************************************************************************************************/
#define FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_A                   {(8554u),(8554u)} 
#define FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_B                  {(0u),(0u)}  
#else
/**********************************************************************************************************
** If you define FUEL_DUAL_FFRC_ENABLE, then set the lower rate check limit.
**********************************************************************************************************/
#define FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_A                   (570u)
#define FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_B                   (0u)

/**********************************************************************************************************
** If you define FUEL_DUAL_FFRC_ENABLE, then set the upper rate check limit.
**********************************************************************************************************/
#define FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_A                   (8554u)
#define FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_B                   (0u)

#endif



/**********************************************************************************************************
** Define the time that the fast fill mode is enabled following a key on
** initialization that does not read the required number of good fuel
** samples.
**********************************************************************************************************/
#define FUEL_DUAL_AVG_VOL_INVALID_TIME                       (0u) // modify by fchao in 20200919 (900u)

/**********************************************************************************************************
** Define the time that the fast fill mode determination is debounced
** before fast fill mode can be entered (due to sloshing present fuel
** level)
**********************************************************************************************************/
#define FUEL_DUAL_MIN_FAST_FILL_TIME                         Fuel_Api_Config_Data_NVM_Pkg_Get_Data(11)//(30u)

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


#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_SLOSH_FILTER_EMPTY_PRELOAD_A               (0x00000000uL)
#define FUEL_DUAL_SLOSH_FILTER_EMPTY_PRELOAD_B               (0x00000000uL)

#else
#define FUEL_DUAL_SLOSH_FILTER_EMPTY_PRELOAD_A {0x00000000uL, 0x00000000uL }
#define FUEL_DUAL_SLOSH_FILTER_EMPTY_PRELOAD_B {0x00000000uL, 0x00000000uL }
#endif



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

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_A_DELTA_NORMAL_ADJUST                      {(0u),(0u)}
#define FUEL_DUAL_B_DELTA_NORMAL_ADJUST                      {(0u),(0u)} 
#else
#define FUEL_DUAL_A_DELTA_NORMAL_ADJUST                      (0u)
#define FUEL_DUAL_B_DELTA_NORMAL_ADJUST                      (0u)

#endif

/**********************************************************************************************************
** Define a max clamp value for the fuel delta when in normal mode.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_DELTA_NORMAL_CLAMP_A                   {(0x00400000uL),(0x00400000uL)}    
#define FUEL_DUAL_DELTA_NORMAL_CLAMP_B                   {(0x00400000uL),(0x00400000uL)}    
#else
#define FUEL_DUAL_DELTA_NORMAL_CLAMP_A                       (0x00400000uL)
#define FUEL_DUAL_DELTA_NORMAL_CLAMP_B                       (0x00400000uL)
#endif

/**********************************************************************************************************
** Define the minimum delta increase ( >= ) in percent full terms that
** the percent full value must change by in response to a filter change.
**
** By setting this constant to 0 or 1, there will effectively be
** no hysteresis applied.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_PERCENT_FULL_POSITIVE_HYST_A               {(325u),(325u)}  
#define FUEL_DUAL_PERCENT_FULL_POSITIVE_HYST_B               {(325u),(325u)} 
#else
#define FUEL_DUAL_PERCENT_FULL_POSITIVE_HYST_A               (325u)
#define FUEL_DUAL_PERCENT_FULL_POSITIVE_HYST_B               (325u)
#endif

/**********************************************************************************************************
** Define the minimum delta decrease ( >= ) in percent full terms that
** the percent full value must change by in response to a filter change.
**
** By setting this constant to 0 or 1, there will effectively be
** no hysteresis applied.
**********************************************************************************************************/
#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_PERCENT_FULL_NEGATIVE_HYST_A               {(325u),(325u)} 
#define FUEL_DUAL_PERCENT_FULL_NEGATIVE_HYST_B               {(325u),(325u)} 

#else
#define FUEL_DUAL_PERCENT_FULL_NEGATIVE_HYST_A               (325u)
#define FUEL_DUAL_PERCENT_FULL_NEGATIVE_HYST_B               (325u)

#endif



/**********************************************************************************************************
** Define the table to convert sender A from A/D to FLPS.
**********************************************************************************************************/

#define FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_SIZE (32)
#define FUEL_DUAL_SENDER_A_AD_TO_PF_TBL	\
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



#define FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_N02	\
{{(uint16)(881), (uint16)(2679u)},\
{ /* 50.3   ohm*/ (uint16)(881	), (uint16)(65024 )},  /* 82  L */ \
{ /* 60.8   ohm*/ (uint16)(1018 ), (uint16)(63438 )},  /* 80  L */ \
{ /* 67     ohm*/ (uint16)(1104 ), (uint16)(62645 )},  /* 79  L */ \
{ /* 75.7   ohm*/ (uint16)(1194 ), (uint16)(61852 )},  /* 78  L */ \
{ /* 85.4   ohm*/ (uint16)(1298 ), (uint16)(61059 )},  /* 77  L */ \
{ /* 90.2   ohm*/ (uint16)(1346 ), (uint16)(60266 )},  /* 76  L */ \
{ /* 100.1  ohm*/ (uint16)(1442 ), (uint16)(59473 )},  /* 75  L */ \
{ /* 110.1  ohm*/ (uint16)(1532 ), (uint16)(57887 )},  /* 73  L */ \
{ /* 120    ohm*/ (uint16)(1613 ), (uint16)(57094 )},  /* 72  L */ \
{ /* 130    ohm*/ (uint16)(1691 ), (uint16)(54715 )},  /* 69  L */ \
{ /* 140    ohm*/ (uint16)(1766 ), (uint16)(53129 )},  /* 67  L */ \
{ /* 150    ohm*/ (uint16)(1835 ), (uint16)(51543 )},  /* 65  L */ \
{ /* 154.2  ohm*/ (uint16)(1864 ), (uint16)(49957 )},  /* 63  L */ \
{ /* 166.6  ohm*/ (uint16)(1942 ), (uint16)(46786 )},  /* 59  L */ \
{ /* 174.9  ohm*/ (uint16)(1992 ), (uint16)(44407 )},  /* 56  L */ \
{ /* 183.2  ohm*/ (uint16)(2039 ), (uint16)(42028 )},  /* 53  L */ \
{ /* 191.8  ohm*/ (uint16)(2086 ), (uint16)(39649 )},  /* 50  L */ \
{ /* 200.1  ohm*/ (uint16)(2133 ), (uint16)(37270 )},  /* 47  L */ \
{ /* 208.3  ohm*/ (uint16)(2171 ), (uint16)(34891 )},  /* 44  L */ \
{ /* 216.8  ohm*/ (uint16)(2211 ), (uint16)(32512 )},  /* 41  L */ \
{ /* 229.2  ohm*/ (uint16)(2268 ), (uint16)(29340 )},  /* 37  L */ \
{ /* 237.6  ohm*/ (uint16)(2303 ), (uint16)(26961 )},  /* 34  L */ \
{ /* 241.7  ohm*/ (uint16)(2321 ), (uint16)(26168 )},  /* 33  L */ \
{ /* 249.9  ohm*/ (uint16)(2354 ), (uint16)(23789 )},  /* 30  L */ \
{ /* 254.9  ohm*/ (uint16)(2374 ), (uint16)(22996 )},  /* 29  L */ \
{ /* 259.9  ohm*/ (uint16)(2393 ), (uint16)(21410 )},  /* 27  L */ \
{ /* 269.6  ohm*/ (uint16)(2431 ), (uint16)(19031 )},  /* 24  L */ \
{ /* 289.6  ohm*/ (uint16)(2500 ), (uint16)(15067 )},  /* 19  L */ \
{ /* 310    ohm*/ (uint16)(2566 ), (uint16)(11102 )},  /* 14  L */ \
{ /* 334.6  ohm*/ (uint16)(2638 ), (uint16)(6344  )},  /* 8  L */ \
{ /* 344.7  ohm*/ (uint16)(2666 ), (uint16)(4758  )},  /* 6  L */ \
{ /* 349.9  ohm*/ (uint16)(2679 ), (uint16)(3965  )}}  /* 5  L */



/*2021/01/29 Communicate with system about the change of dead oil area at point E*/
//{(uint16)(2678u),(uint16)(1912u)},/*350ohm      1L*/\

/**********************************************************************************************************
** Define the table to convert sender B from A/D to FLPS.
**
** This is used if FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS is not defined.
**********************************************************************************************************/
#define FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_SIZE (29)
#define FUEL_DUAL_SENDER_B_AD_TO_PF_TBL	\
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



#define FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_NO2	\
{{(uint16)(875u), (uint16)(2678u)},\
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
{(uint16)(2678u),(uint16)(0)}}/*340ohm      2L*/


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
#define FUEL_DUAL_IGNOFF_SAMPLE_TIME                         (400u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_DUAL_REF_AVG_TYPE=4).
** This controls the number of raw samples taken in a convergence cycle.
** If you don't use KOC, then any value is OK since it won't be used.
**********************************************************************************************************/
#define FUEL_DUAL_KOS_CYCLES                                 (4u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_DUAL_REF_AVG_TYPE=4).
** This controls the maximum number of convergence cycles to take.
** If you don't use KOC, then any value is OK since it won't be used.
**********************************************************************************************************/
#define FUEL_DUAL_KOS_COUNTS                                 (50u)

/**********************************************************************************************************
** Define the following for Key Off Convergence (FUEL_DUAL_REF_AVG_TYPE=4).
** This controls the minimum number of unfaulted samples in a convergence
** cycle that is required.  If we don't get this many, then that cycle
** did not converge.  If you don't use KOC, then any value is OK since
** it won't be used.
**********************************************************************************************************/
#define FUEL_DUAL_KOS_MIN_SMPLS                              (20u)

/**********************************************************************************************************
** Define the delta between the min and max sample in a key-off
** convergence window.  If the delta is less than this value, the
** samples are considered converged.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_KO_DELTA_A                               { (3198), (3198)} 
#define FUEL_DUAL_KO_DELTA_B                               { (3198), (3198)}   
#else
#define FUEL_DUAL_KO_DELTA_A                                 (3198)
#define FUEL_DUAL_KO_DELTA_B                                 (3198)

#endif

/**********************************************************************************************************
** Define the following 3 values for the fast fill convergence.
** These definitions are identical to the 3 defined above, except
** these are for fast fill.
**********************************************************************************************************/
#define FUEL_DUAL_ZS_CYCLES                                  (4u)
#define FUEL_DUAL_ZS_COUNTS                                  (50u)
#define FUEL_DUAL_ZS_MIN_SMPLS                               (30u)

/**********************************************************************************************************
** Define the delta between the min and max sample in a fast fill
** convergence window.  If the delta is less than this value, the
** samples are considered converged.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_ZS_DELTA_A                                  { (3198), (3198)} 
#define FUEL_DUAL_ZS_DELTA_B                                  { (3198), (3198)} 
#else
#define FUEL_DUAL_ZS_DELTA_A                                 (3198)
#define FUEL_DUAL_ZS_DELTA_B                                 (3198)

#endif

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
#define FUEL_DUAL_JPM_FAULT_DELAY_TIME                       (0u)

/**********************************************************************************************************
** For dual sender systems, declare a fault if the filtered percent full
** of sender A is < FUEL_DUAL_SENDERA_ERROR and that of the sender B is
** > FUEL_DUAL_SENDERB_ERROR.  Ford requires <= and >= in the evaluations.
** To accommodate an equivalency of the requirement but still being able to 
** turn off the checks by using 0 and 255, respectively, we use actual values
** of TARGET + 1 and TARGET - 1, respectively, and leave the signs < and >.
**********************************************************************************************************/
#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_SENDERA_ERROR                           {(12 * 256u),(12 * 256u)}
#define FUEL_DUAL_SENDERB_ERROR                           {(13 * 256u),(13 * 256u)}  
#else
#define FUEL_DUAL_SENDERA_ERROR                              (12 * 256u)
#define FUEL_DUAL_SENDERB_ERROR                              (13 * 256u)

#endif

/**********************************************************************************************************
** For dual sender systems, define the weighting by percentage of the
** total tank volume for sender A and sender B.
**
** Note that (w1+w2)/256 must be 1 or the weights are invalid.
**********************************************************************************************************/



#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
//#define FUEL_DUAL_SENDERA_WEIGHT_P03                             (254*256)
//#define FUEL_DUAL_SENDERB_WEIGHT_P03                             (0)  
//#define FUEL_DUAL_SENDERA_WEIGHT_P05                             (36528u)
//#define FUEL_DUAL_SENDERB_WEIGHT_P05                             (29008u)  
#define FUEL_DUAL_SENDERA_WEIGHT                            {(256ul*256ul),(36528ul)}
#define FUEL_DUAL_SENDERB_WEIGHT                            {(0ul),      (29008ul)}

#else
#define FUEL_DUAL_SENDERA_WEIGHT                             (36528u)
#define FUEL_DUAL_SENDERB_WEIGHT                             (29008u)

#endif


/**********************************************************************************************************
** Define the following for enabling saddle tanks in your system.  Any index
** where there is a 1 indicates a saddle tank, otherwise a 0 indicates that
** it is not a saddle tank.
**
** This entry must be the same size as FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS,
** i.e. if FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS is set to 4, then this should
** be an array of 4 entries.  The value returned from the FUEL_DUAL_INDEX_TABLE
** lookup function will indicate which index into this array that the
** software is to use.
**********************************************************************************************************/
#define FUEL_DUAL_SADDLE_TANK_SYSTEM                         (0u)


/**********************************************************************************************************
** Define the following for enabling a second sender in your system.  Any
** index where there is a 1 indicates a second sender is active, otherwise
** a 0 indicates that there is only one sender.  Please note that a second
** sender can mean either a dual tank system or saddle tank system,
** and FUEL_DUAL_SADDLE_TANK_SYSTEM then decides which type.
**
** This entry must be the same size as FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS,
** i.e. if FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS is set to 4, then this should
** be an array of 4 entries.  The value returned from the FUEL_DUAL_INDEX_TABLE
** lookup function will indicate which index into this array that the
** software is to use.
**********************************************************************************************************/

#ifdef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
#define FUEL_DUAL_SENDER_B_ENABLE                            {0,1}  
#else
#define FUEL_DUAL_SENDER_B_ENABLE                            (1u)

#endif

/**********************************************************************************************************
** --------------------------------------------------------------------------
** NVM fault logging configuration parameters
** --------------------------------------------------------------------------
**********************************************************************************************************/


#define FUEL_DUAL_TANK_SYSTEM_SPURE_NUM                                  (2)

/**********************************************************************************************************
** Define the following if you would like log the fuel init values to NVM.
** Comment it out if not used.
**
** Note: If you use this NVM logging, you need to make sure the queue size
**       in the eprom manager is big enough (EPM_Q_SIZE).
**********************************************************************************************************/
#define FUEL_DUAL_LOG_INIT_ERRORS_TO_NVM

/**********************************************************************************************************
** Define the number of 'records' you want to store in RAM.
** Comment it out if not used.
**********************************************************************************************************/
#define FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE                  (0u)

/**********************************************************************************************************
** Define the number of 'records' you want to store in NVM.
** Comment it out if not used.
**********************************************************************************************************/
#define FUEL_DUAL_LOG_FAULT_RECORD_SIZE                      (0u)

/**********************************************************************************************************
** Set the following to the number of samples on the same side of the
** filter that need to occur before the fuel data is declared faulted
** and logged to NVM.
**********************************************************************************************************/
#define FUEL_DUAL_ERR_CNT                                    (3000u)

#define FUEL_DUAL_FAST_FILL_MET_MACRO()                (Fuel_Dual_Zero_Speed_Check())

#define FUEL_DUAL_ZSS_MET_MACRO()                      (Fuel_Dual_Zss_Speed_Check())

#define FUEL_DUAL_FUEL_LOW_STATUS(x)                   (Fuel_Dual_Api_Get_Fuel_Low_Status(x))

#define FUEL_DUAL_ENGINE_RUNNING_STATUS()              (Fuel_Api_Get_EngSpd_State())

#define FUEL_DUAL_IFC_AVG_RATE()                       (Fuel_Rte_Api_Get_IFC_10S_Rate())
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

