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
**  Description:        The intent of this code is to provide a configurable fuel filter
** 						algorithm for use in a variety of instrument cluster applications.
** 						Requirements for this code package are detailed in the
** 						Fuel Algorithm Bookshelf Design Specification 
**
**  Organization:       
**
**********************************************************************************************************/

#ifndef FUEL_PKG_DUAL_DATE_H
#define FUEL_PKG_DUAL_DATE_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Pkg_Dual_Cfg.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/


/**********************************************************************************************************
** Added check for '==1' and undefine if TRUE 
** This allows the previous functionality to be maintained.  
** Note that this is performed before the .h file is         
** included so it can take advantage of it also.             
**********************************************************************************************************/
#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
	//MODIFY BY FCHAO IN 20200609
    //#error FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS must be defined !
#else
    #if (FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS == 1)
        #undef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
    #endif
#endif

/**********************************************************************************************************
** Backward compatibility - previously, always had 5 fuel tables 
** independent of FUEL02_SCEM_NUMBER_OF_TANKS                    
** Now possible to override to only define the tables required              
**********************************************************************************************************/

#ifndef FUEL_DUAL_NUM_FUEL_TABLES
 #define FUEL_DUAL_NUM_FUEL_TABLES    1
#else
 #if FUEL_DUAL_NUM_FUEL_TABLES<1
  #error FUEL_DUAL_NUM_FUEL_TABLES must be greater than zero !
 #endif
#endif

#ifndef FUEL_DUAL_LOG_FAULT_RECORD_SIZE
  #define FUEL_DUAL_LOG_FAULT_RECORD_SIZE 0
#endif

#ifndef FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE
   #define FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE 0
#endif


#if FUEL_DUAL_LOG_FAULT_RECORD_SIZE != 0
  #if (FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE == 0)
    #error FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE must be defined when FUEL_DUAL_LOG_FAULT_RECORD_SIZE macro enabled!
  #elif (FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE < FUEL_DUAL_LOG_FAULT_RECORD_SIZE)
     #error FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE greater than or equal to FUEL_DUAL_LOG_FAULT_RECORD_SIZE!
  #endif
#endif

/**********************************************************************************************************
** The following 'defines' were initially a configuration items for the application
** to decide which fuel values to save since the team wasn't able to decide which
** ones to save. Since this has been defined in the BDS now, the following was cut
** from the .cfg file and placed here to preserve the elegance of the implementation.
**
** Set to 1 to enable storage, 0 to disable storage.
**********************************************************************************************************/
#ifndef FUEL_DUAL_DATA_TO_FAULT_RECORD

#if FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE > 0
#define FUEL_DUAL_LOG_FDELTA                                    (0u)
#define FUEL_DUAL_LOG_FDELTA_BASE                               (0u)
#define FUEL_DUAL_LOG_FDELTA_ADJUST_BASE                        (0u)
#define FUEL_DUAL_LOG_FILTER_FLAGS                              (1u)
#define FUEL_DUAL_LOG_FLPS                                      (1u)
#define FUEL_DUAL_LOG_INIT_REF                                  (1u)
#define FUEL_DUAL_LOG_INIT_PID                                  (1u)
#define FUEL_DUAL_LOG_IGNOFF_REF                                (1u)
#define FUEL_DUAL_LOG_IGNON_RADSUM                              (1u)
#define FUEL_DUAL_LOG_IGNON_GOOD_SAMPLE                         (1u)
#define FUEL_DUAL_LOG_IGNON_AVG_FLPS                            (1u)
#define FUEL_DUAL_LOG_AVG_FLPS_SADDLE                           (0u)
#define FUEL_DUAL_LOG_MORE_FILTER_FLAGS                         (1u)
#define FUEL_DUAL_LOG_FAULT_COUNTER                             (0u)
#define FUEL_DUAL_LOG_FAULT_RECOVERY_COUNTER                    (0u)
#define FUEL_DUAL_LOG_RAD                                       (1u)
#define FUEL_DUAL_LOG_AVG_RAD                                   (0u)
#define FUEL_DUAL_LOG_OLD_RAD                                   (0u)
#define FUEL_DUAL_LOG_SAMPLE_ARRAY                              (0u)
#define FUEL_DUAL_LOG_RC_FILL_THRESHOLD                         (0u)
#define FUEL_DUAL_LOG_RC_FILL_DELTA                             (0u)
#define FUEL_DUAL_LOG_RFLPS                                     (0u)
#define FUEL_DUAL_LOG_RFUEL                                     (0u)
#define FUEL_DUAL_LOG_SLOSH_FILTER                              (1u)
#define FUEL_DUAL_LOG_SLOSH_FILTER_HYS                          (1u)
#define FUEL_DUAL_LOG_ZSS_REF                                   (1u)
#define FUEL_DUAL_LOG_RATE_CHECK_PASSED                         (0u)
#define FUEL_DUAL_LOG_RATE_CHECK_TIMER                          (0u)
#define FUEL_DUAL_LOG_FFRC_DELTA_REF                            (0u)
#define FUEL_DUAL_LOG_SAMPLE_COUNTER                            (0u)
#define FUEL_DUAL_LOG_RATE_CHECK_SAMPLE                         (0u)
#define FUEL_DUAL_LOG_CONVCYCLE_COUNTER                         (0u)
#define FUEL_DUAL_LOG_CONVSAMPLE                                (0u)
#define FUEL_DUAL_LOG_SAMPLE_COUNTER                            (0u)
#define FUEL_DUAL_LOG_MIN_VX                                    (0u)
#define FUEL_DUAL_LOG_MAX_VX                                    (0u)
#define FUEL_DUAL_LOG_SUM_VX                                    (0u)
#define FUEL_DUAL_LOG_KOC_CONVERGED                             (1u)
#define FUEL_DUAL_LOG_KOC_FAULT_FLAG                            (0u)
#define FUEL_DUAL_LOG_ZS_CONVERGED                              (1u)
#define FUEL_DUAL_LOG_MOVING_SAMPLE_COUNTER                     (0u)
#define FUEL_DUAL_LOG_USE_AVG_FLAG                              (0u)
#define FUEL_DUAL_LOG_USE_MOVE_AVG                              (0u)
#define FUEL_DUAL_LOG_ERR_COUNTER                               (0u)
#define FUEL_DUAL_LOG_KO_CONVSAMPLE                             (0u)
#define FUEL_DUAL_LOG_ZS_CONVSAMPLE                             (0u)

typedef struct {

#if FUEL_DUAL_LOG_FDELTA==1
 uint32 fuel_dual_log_fdelta;
#endif
#if FUEL_DUAL_LOG_FDELTA_BASE==1
 uint32 fuel_dual_log_fdelta_base;
#endif
#if FUEL_DUAL_LOG_FDELTA_ADJUST_BASE==1
 uint16 fuel_dual_log_fdelta_adjust_base;
#endif
#if FUEL_DUAL_LOG_FILTER_FLAGS==1
 uint8  fuel_dual_log_FilterFlags;
#endif
#if FUEL_DUAL_LOG_FLPS==1
 uint8  fuel_dual_log_flps;
#endif
#if FUEL_DUAL_LOG_INIT_REF==1
 uint8  fuel_dual_log_init_ref;
#endif
#if FUEL_DUAL_LOG_INIT_PID==1
 uint16 fuel_dual_log_init_pid;
#endif
#if FUEL_DUAL_LOG_IGNOFF_REF==1
 uint8  fuel_dual_log_KeyOffRef;
#endif
#if FUEL_DUAL_LOG_IGNON_RADSUM==1
 uint32 fuel_dual_log_keyon_radsum;
#endif
#if FUEL_DUAL_LOG_IGNON_GOOD_SAMPLE==1
 uint8  fuel_dual_log_keyon_good_samples;
#endif
#if FUEL_DUAL_LOG_IGNON_AVG_FLPS==1
 uint8  fuel_dual_log_keyon_avgflps;
#endif
#if FUEL_DUAL_LOG_AVG_FLPS_SADDLE==1
 uint8  fuel_dual_log_avgflps_saddle;
#endif
#if FUEL_DUAL_LOG_MORE_FILTER_FLAGS==1
 uint8  fuel_dual_log_MoreFilterFlags;
#endif
#if FUEL_DUAL_LOG_FAULT_COUNTER==1
 uint16 fuel_dual_log_FuelFaultCounter;
#endif
#if FUEL_DUAL_LOG_FAULT_RECOVERY_COUNTER==1
 uint16 fuel_dual_log_FuelFaultRecoveryCounter;
#endif
#if FUEL_DUAL_LOG_RAD==1
 uint16 fuel_dual_log_rad;
#endif
#if FUEL_DUAL_LOG_AVG_RAD==1
 uint16 fuel_dual_log_avg_rad;
#endif
#if FUEL_DUAL_LOG_OLD_RAD==1
 uint16 fuel_dual_log_old_rad;
#endif
#if FUEL_DUAL_LOG_SAMPLE_ARRAY==1
 uint16 fuel_dual_log_sample_array[FUEL_DUAL_SMPLS_2_AVG];
#endif
#if FUEL_DUAL_LOG_RC_FILL_THRESHOLD==1
 uint8  fuel_dual_log_rc_fill_threshold;
#endif
#if FUEL_DUAL_LOG_RC_FILL_DELTA==1
 uint8  fuel_dual_log_rc_fill_delta;
#endif
#if FUEL_DUAL_LOG_RFLPS==1
 uint8  fuel_dual_log_rflps;
#endif
#if FUEL_DUAL_LOG_RFUEL==1
 uint8  fuel_dual_log_rfuel;
#endif
#if FUEL_DUAL_LOG_SLOSH_FILTER==1
 uint32 fuel_dual_log_slosh_filter;
#endif
#if FUEL_DUAL_LOG_SLOSH_FILTER_HYS==1
 uint32 fuel_dual_log_slosh_filter_hys;
#endif
#if FUEL_DUAL_LOG_ZSS_REF==1
 uint8  fuel_dual_log_zss_ref;
#endif
#ifdef FUEL_DUAL_FFRC_ENABLE
#if FUEL_DUAL_LOG_RATE_CHECK_PASSED==1
 boolean fuel_dual_log_rate_check_passed;
#endif
#if FUEL_DUAL_LOG_RATE_CHECK_TIMER==1
 uint16  fuel_dual_log_rate_check_timer;
#endif
#if FUEL_DUAL_LOG_FFRC_DELTA_REF==1
 uint8   fuel_dual_log_ffrc_delta_ref;
#endif
#if FUEL_DUAL_LOG_SAMPLE_COUNTER==1
 uint8   fuel_dual_log_sample_counter;
#endif
#if FUEL_DUAL_LOG_RATE_CHECK_SAMPLE==1
 uint8   fuel_dual_log_rate_check_sample[FUEL_DUAL_MAX_RATE_CHECK_SAMPLES+1];
#endif
#endif
#if (FUEL_DUAL_REF_AVG_TYPE==4)
#if FUEL_DUAL_LOG_CONVCYCLE_COUNTER==1
 uint8   fuel_dual_log_ConvCycleCounter;
#endif
#if FUEL_DUAL_LOG_CONVSAMPLE==1
 uint8   fuel_dual_log_ConvSample;
#endif
#if FUEL_DUAL_LOG_SAMPLE_COUNTER==1
 uint8   fuel_dual_log_SmplCounter;
#endif
#if FUEL_DUAL_LOG_MIN_VX==1
 uint8   fuel_dual_log_min_vx;
#endif
#if FUEL_DUAL_LOG_MAX_VX==1
 uint8   fuel_dual_log_max_vx;
#endif
#if FUEL_DUAL_LOG_SUM_VX==1
 uint16  fuel_dual_log_sum_vx;
#endif
#if FUEL_DUAL_LOG_KOC_CONVERGED==1
 boolean fuel_dual_log_koc_converged;
#endif
#if FUEL_DUAL_LOG_KOC_FAULT_FLAG==1
 boolean fuel_dual_log_koc_fault_flag;
#endif
#if FUEL_DUAL_LOG_ZS_CONVERGED==1
 boolean fuel_dual_log_zs_converged;
#endif
#endif
#if FUEL_DUAL_LOG_MOVING_SAMPLE_COUNTER==1
 uint8   fuel_dual_log_moving_sample_counter;
#endif
#if FUEL_DUAL_LOG_USE_AVG_FLAG==1
 uint8   fuel_dual_log_use_avg_flag;
#endif
#if FUEL_DUAL_LOG_USE_MOVE_AVG==1
 uint8   fuel_dual_log_use_mov_avg;
#endif
#if FUEL_DUAL_LOG_ERR_COUNTER==1
 uint16  fuel_dual_log_err_counter;
#endif

} FUEL02_FAULT_SNAPSHOT_STRUCT;
#endif
#else  /*FUEL_DUAL_DATA_TO_FAULT_RECORD*/
#if FUEL_DUAL_RAM_LOG_FAULT_RECORD_SIZE > 0
#define FUEL_DUAL_LOG_FDELTA                                    (0u)
#define FUEL_DUAL_LOG_FDELTA_BASE                               (0u)
#define FUEL_DUAL_LOG_IGNON_RADSUM                              (1u)
#define FUEL_DUAL_LOG_SLOSH_FILTER                              (1u)
#define FUEL_DUAL_LOG_SLOSH_FILTER_HYS                          (1u)
#define FUEL_DUAL_LOG_FDELTA_ADJUST_BASE                        (0u)
#define FUEL_DUAL_LOG_INIT_PID                                  (1u)
#define FUEL_DUAL_LOG_FAULT_COUNTER                             (0u)
#define FUEL_DUAL_LOG_FAULT_RECOVERY_COUNTER                    (0u)
#define FUEL_DUAL_LOG_RAD                                       (1u)
#define FUEL_DUAL_LOG_AVG_RAD                                   (0u)
#define FUEL_DUAL_LOG_OLD_RAD                                   (0u)
#define FUEL_DUAL_LOG_SAMPLE_ARRAY                              (0u)
#define FUEL_DUAL_LOG_ERR_COUNTER                               (0u)
#define FUEL_DUAL_LOG_RATE_CHECK_TIMER                          (0u)
#define FUEL_DUAL_LOG_SUM_VX                                    (1u)
#define FUEL_DUAL_LOG_CONVCYCLE_COUNTER                         (1u)
#define FUEL_DUAL_LOG_KO_CONVSAMPLE                             (1u)
#define FUEL_DUAL_LOG_ZS_CONVSAMPLE                             (0u)
#define FUEL_DUAL_LOG_SAMPLE_COUNTER                            (1u)
#define FUEL_DUAL_LOG_MIN_VX                                    (1u)
#define FUEL_DUAL_LOG_MAX_VX                                    (1u)
#define FUEL_DUAL_LOG_KOC_CONVERGED                             (1u)
#define FUEL_DUAL_LOG_KOC_FAULT_FLAG                            (0u)
#define FUEL_DUAL_LOG_ZS_CONVERGED                              (1u)
#define FUEL_DUAL_LOG_RATE_CHECK_PASSED                         (0u)
#define FUEL_DUAL_LOG_FFRC_DELTA_REF                            (0u)
#define FUEL_DUAL_LOG_SAMPLE_COUNTER                            (0u)
#define FUEL_DUAL_LOG_RATE_CHECK_SAMPLE                         (0u)
#define FUEL_DUAL_LOG_FILTER_FLAGS                              (1u)
#define FUEL_DUAL_LOG_FLPS                                      (1u)
#define FUEL_DUAL_LOG_INIT_REF                                  (1u)
#define FUEL_DUAL_LOG_IGNOFF_REF                                (1u)
#define FUEL_DUAL_LOG_IGNON_GOOD_SAMPLE                         (1u)
#define FUEL_DUAL_LOG_IGNON_AVG_FLPS                            (1u)
#define FUEL_DUAL_LOG_AVG_FLPS_SADDLE                           (0u)
#define FUEL_DUAL_LOG_MORE_FILTER_FLAGS                         (1u)
#define FUEL_DUAL_LOG_RC_FILL_THRESHOLD                         (0u)
#define FUEL_DUAL_LOG_RC_FILL_DELTA                             (0u)
#define FUEL_DUAL_LOG_RFLPS                                     (0u)
#define FUEL_DUAL_LOG_RFUEL                                     (0u)
#define FUEL_DUAL_LOG_ZSS_REF                                   (1u)
#define FUEL_DUAL_LOG_MOVING_SAMPLE_COUNTER                     (0u)
#define FUEL_DUAL_LOG_USE_AVG_FLAG                              (0u)
#define FUEL_DUAL_LOG_USE_MOVE_AVG                              (0u)
#define FUEL02_LOG_invalid_condition                                (1u)
#define FUEL02_LOG_ignition_cycle_counter                           (1u)


typedef struct {

#if FUEL_DUAL_LOG_FDELTA==1
 uint32 fuel_single_fdelta;
#endif

#if FUEL_DUAL_LOG_FDELTA_BASE==1
 uint32 fuel_single_fdelta_base;
#endif

#if FUEL_DUAL_LOG_IGNON_RADSUM==1
 uint32 fuel_single_ignon_radsum;
#endif

#if FUEL_DUAL_LOG_SLOSH_FILTER==1
 uint32 fuel_single_slosh_filter;
#endif

#if FUEL_DUAL_LOG_SLOSH_FILTER_HYS==1
 uint32 fuel_single_slosh_filter_hys;
#endif

#if FUEL_DUAL_LOG_FDELTA_ADJUST_BASE==1
 uint16 fuel_single_fdelta_adjust_base;
#endif

#if FUEL_DUAL_LOG_INIT_PID==1
 uint32 fuel_single_init_pid;
#endif

#if FUEL_DUAL_LOG_FAULT_COUNTER==1
 uint16 fuel_single_fault_counter;
#endif

#if FUEL_DUAL_LOG_FAULT_RECOVERY_COUNTER==1
 uint16 fuel_single_fault_recovery_counter;
#endif

#if FUEL_DUAL_LOG_RAD==1
 uint16 fuel_single_rad;
#endif

#if FUEL_DUAL_LOG_AVG_RAD==1
 uint16 fuel_single_avg_rad;
#endif

#if FUEL_DUAL_LOG_OLD_RAD==1
 uint16 fuel_single_old_rad;
#endif

#if FUEL_DUAL_LOG_SAMPLE_ARRAY==1
 uint16 fuel_single_sample_array[FUEL_DUAL_SMPLS_2_AVG];
#endif

#if FUEL_DUAL_LOG_ERR_COUNTER==1
 uint16  fuel_single_err_counter;
#endif

#ifdef FUEL_DUAL_FFRC_ENABLE
#if FUEL_DUAL_LOG_RATE_CHECK_TIMER==1
 uint16  fuel_single_rate_check_timer;
#endif
#endif

#if (FUEL_DUAL_REF_AVG_TYPE==4)
#if FUEL_DUAL_LOG_SUM_VX==1
 uint16  fuel_single_sum_vx;
#endif
#if FUEL_DUAL_LOG_CONVCYCLE_COUNTER==1
 uint8   fuel_single_convcycle_counter;
#endif
#if FUEL_DUAL_LOG_KO_CONVSAMPLE==1
 uint8   KO_ConvSample;
#endif
#if FUEL_DUAL_LOG_ZS_CONVSAMPLE==1
 uint8   ZS_ConvSample;
#endif
#if FUEL_DUAL_LOG_SAMPLE_COUNTER==1
 uint8   fuel_single_sample_counter;
#endif
#if FUEL_DUAL_LOG_MIN_VX==1
 uint8   fuel_single_min_vx;
#endif
#if FUEL_DUAL_LOG_MAX_VX==1
 uint8   fuel_single_max_vx;
#endif
#if FUEL_DUAL_LOG_KOC_CONVERGED==1
 boolean fuel_single_koc_converged;
#endif
#if FUEL_DUAL_LOG_KOC_FAULT_FLAG==1
 boolean fuel_single_koc_fault_flag;
#endif
#if FUEL_DUAL_LOG_ZS_CONVERGED==1
 boolean fuel_single_zs_converged;
#endif
#endif

#ifdef FUEL_DUAL_FFRC_ENABLE
#if FUEL_DUAL_LOG_RATE_CHECK_PASSED==1
 boolean fuel_single_rate_check_passed;
#endif
#if FUEL_DUAL_LOG_FFRC_DELTA_REF==1
 uint8   fuel_single_ffrc_delta_ref;
#endif
#if FUEL_DUAL_LOG_SAMPLE_COUNTER==1
 uint8   fuel_single_sample_counter;
#endif
#if FUEL_DUAL_LOG_RATE_CHECK_SAMPLE==1
 uint8   fuel_single_rate_check_sample[FUEL_DUAL_MAX_RATE_CHECK_SAMPLES+1];
#endif
#endif

#if FUEL_DUAL_LOG_FILTER_FLAGS==1
 uint8  fuel_single_filter_flags;
#endif

#if FUEL_DUAL_LOG_FLPS==1
 uint16  fuel_single_flps;
#endif

#if FUEL_DUAL_LOG_INIT_REF==1
 uint16  fuel_single_init_ref;
#endif

#if FUEL_DUAL_LOG_IGNOFF_REF==1
 uint16  fuel_single_ignoff_ref;
#endif

#if FUEL_DUAL_LOG_IGNON_GOOD_SAMPLE==1
 uint8  fuel_single_ignon_good_samples;
#endif

#if FUEL_DUAL_LOG_IGNON_AVG_FLPS==1
 uint16  fuel_single_ignon_avgflps;
#endif

#if FUEL_DUAL_LOG_AVG_FLPS_SADDLE==1
 uint8  fuel_single_avgflps_saddle;
#endif

#if FUEL_DUAL_LOG_MORE_FILTER_FLAGS==1
 uint8  fuel_single_more_filter_flags;
#endif

#if FUEL_DUAL_LOG_RC_FILL_THRESHOLD==1
 uint8  fuel_single_rc_fill_threshold;
#endif

#if FUEL_DUAL_LOG_RC_FILL_DELTA==1
 uint8  fuel_single_rc_fill_delta;
#endif

#if FUEL_DUAL_LOG_RFLPS==1
 uint16  fuel_single_rflps;
#endif

#if FUEL_DUAL_LOG_RFUEL==1
 uint8  fuel_single_rfuel;
#endif

#if FUEL_DUAL_LOG_ZSS_REF==1
 uint8  fuel_single_zss_ref;
#endif

#if FUEL_DUAL_LOG_MOVING_SAMPLE_COUNTER==1
 uint8   fuel_single_moving_sample_counter;
#endif

#if FUEL_DUAL_LOG_USE_AVG_FLAG==1
 uint8   fuel_single_use_avg_flag;
#endif

#if FUEL_DUAL_LOG_USE_MOVE_AVG==1
 uint8   fuel_single_use_mov_avg;
#endif

#if FUEL02_LOG_invalid_condition==1
 uint8   fuel02_invalid_condition;
#endif

#if FUEL02_LOG_ignition_cycle_counter==1
 uint8   fuel02_ignition_cycle_counter;
#endif
/**********************************************************************************************************
** As of now totally 23 elements have been enabled resulting 35 bytes   
** memory occupation. So in order to have duals of 4 bytes one byte 
** padding is done here. In future if any bytes are enabled here this   
** has to be taken care accordingly                                     
*********************************************************************************************************/
 uint8   padded_byte;
} FUEL02_FAULT_SNAPSHOT_STRUCT;

#endif
#endif 


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
** Define the 'secondary' up and down fill checks
*********************************************************************************************************/

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

    extern uint16 fuel_dual_a_sec_pos_init_fill_delta_nvm;
    extern uint16 fuel_dual_a_sec_neg_init_fill_delta_nvm;
    extern uint16 fuel_dual_b_sec_pos_init_fill_delta_nvm;
    extern uint16 fuel_dual_b_sec_neg_init_fill_delta_nvm;

#else
    extern uint16 fuel_dual_a_sec_pos_init_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
    extern uint16 fuel_dual_a_sec_neg_init_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
    extern uint16 fuel_dual_b_sec_pos_init_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
    extern uint16 fuel_dual_b_sec_neg_init_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern uint8  fuel_dual_ignon_delay_time_nvm;
extern uint8  fuel_dual_init_delay_count_time_nvm;
extern uint16 fuel_dual_fault_counter_nvm;
extern uint16 fuel_dual_fault_recovery_counter_nvm;
extern uint8  fuel_dual_fastfill_time_counter_nvm;

extern uint32 fuel_dual_a_normal_base_delta_nvm;
extern uint32 fuel_dual_a_idle_base_delta_normal_nvm;
extern uint32 fuel_dual_b_idle_base_delta_normal_nvm;

extern uint32 fuel_dual_a_normal_low_base_delta_nvm;
extern uint32 fuel_dual_b_normal_low_base_delta_nvm;

extern uint32 fuel_dual_b_normal_base_delta_nvm;
extern uint32 fuel_dual_a_fast_base_delta_nvm;
extern uint32 fuel_dual_b_fast_base_delta_nvm;

extern uint16 fuel_dual_a_pos_init_fill_delta_nvm;
extern uint16 fuel_dual_b_pos_init_fill_delta_nvm;
extern uint16 fuel_dual_a_neg_init_fill_delta_nvm;
extern uint16 fuel_dual_b_neg_init_fill_delta_nvm;

extern uint16 fuel_dual_a_pos_fast_fill_delta_nvm;
extern uint16 fuel_dual_a_neg_fast_fill_delta_nvm;
extern uint16 fuel_dual_a_neg_leak_fast_fill_delta_nvm;

extern uint16 fuel_dual_b_pos_fast_fill_delta_nvm;
extern uint16 fuel_dual_b_neg_fast_fill_delta_nvm;

extern uint16 fuel_dual_a_ad_short_lim_nvm;
extern uint16 fuel_dual_b_ad_short_lim_nvm;

extern uint16 fuel_dual_a_ad_open_lim_nvm;
extern uint16 fuel_dual_b_ad_open_lim_nvm;
extern uint32 fuel_dual_a_up_base_delta_nvm;
extern uint32 fuel_dual_b_up_base_delta_nvm;
extern uint32 fuel_dual_a_down_base_delta_nvm;
extern uint32 fuel_dual_b_down_base_delta_nvm;

#else

extern uint8  fuel_dual_ignon_delay_time_nvm[];
extern uint8  fuel_dual_init_delay_count_time_nvm[];
extern uint16 fuel_dual_fault_counter_nvm[];
extern uint16 fuel_dual_fault_recovery_counter_nvm[];
extern uint8  fuel_dual_fastfill_time_counter_nvm[];

extern uint32 fuel_dual_a_normal_base_delta_nvm[];
extern uint32 fuel_dual_a_idle_base_delta_normal_nvm[];
extern uint32 fuel_dual_b_idle_base_delta_normal_nvm[];

extern uint32 fuel_dual_a_normal_low_base_delta_nvm[];
extern uint32 fuel_dual_b_normal_low_base_delta_nvm[];

extern uint32 fuel_dual_b_normal_base_delta_nvm[];
extern uint32 fuel_dual_a_fast_base_delta_nvm[];
extern uint32 fuel_dual_b_fast_base_delta_nvm[];

extern uint16 fuel_dual_a_pos_init_fill_delta_nvm[];
extern uint16 fuel_dual_b_pos_init_fill_delta_nvm[];
extern uint16 fuel_dual_a_neg_init_fill_delta_nvm[];
extern uint16 fuel_dual_b_neg_init_fill_delta_nvm[];

extern uint16 fuel_dual_a_pos_fast_fill_delta_nvm[];
extern uint16 fuel_dual_a_neg_fast_fill_delta_nvm[];
extern uint16 fuel_dual_a_neg_leak_fast_fill_delta_nvm[];

extern uint16 fuel_dual_b_pos_fast_fill_delta_nvm[];
extern uint16 fuel_dual_b_neg_fast_fill_delta_nvm[];

extern uint16 fuel_dual_a_ad_short_lim_nvm[];
extern uint16 fuel_dual_b_ad_short_lim_nvm[];

extern uint16 fuel_dual_a_ad_open_lim_nvm[];
extern uint16 fuel_dual_b_ad_open_lim_nvm[];


extern uint32 fuel_dual_a_up_base_delta_nvm[];
extern uint32 fuel_dual_b_up_base_delta_nvm[];
extern uint32 fuel_dual_a_down_base_delta_nvm[];
extern uint32 fuel_dual_b_down_base_delta_nvm[];

#endif

#define SWC_FUEL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
** Define times for power stabilization delay, fuel samples to be taken,
** and open/short detect time, and number of good samples required
*********************************************************************************************************/


extern const uint8  fuel_dual_init_good_samples_required_nvm;



/**********************************************************************************************************
** Define the fuel filter base delta and adjustment factor for use when
** in "normal" filter mode.
*********************************************************************************************************/


#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 fuel_dual_a_normal_adjust_delta_nvm;
extern const uint32 FUEL_DUAL_DELTA_NORMAL_CLAMP_A_NVM;
extern const uint16 fuel_dual_b_normal_adjust_delta_nvm;
extern const uint32 FUEL_DUAL_DELTA_NORMAL_CLAMP_B_NVM;

#else

extern const uint16 fuel_dual_a_normal_adjust_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint32 FUEL_DUAL_DELTA_NORMAL_CLAMP_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 fuel_dual_b_normal_adjust_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint32 FUEL_DUAL_DELTA_NORMAL_CLAMP_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

/**********************************************************************************************************
** Define the fuel filter base delta and ajustment factor for use when
** in "fast fill" filter mode.
*********************************************************************************************************/

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 fuel_dual_a_fast_adjust_delta_nvm;

extern const uint32 FUEL_DUAL_DELTA_FAST_CLAMP_A_NVM;

extern const uint16 fuel_dual_b_fast_adjust_delta_nvm;

extern const uint32 FUEL_DUAL_DELTA_FAST_CLAMP_B_NVM;

#else

extern const uint16 fuel_dual_a_fast_adjust_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

extern const uint32 FUEL_DUAL_DELTA_FAST_CLAMP_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

extern const uint16 fuel_dual_b_fast_adjust_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

extern const uint32 FUEL_DUAL_DELTA_FAST_CLAMP_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_DUAL_KO_DELTA_A_NVM;
extern const uint16 FUEL_DUAL_KO_DELTA_B_NVM;

#else

extern const uint16 FUEL_DUAL_KO_DELTA_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_DUAL_KO_DELTA_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif




/**********************************************************************************************************
** Define the up and down check limits used for percent full hysteresis.
*********************************************************************************************************/

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_DUAL_PERCENT_FULLPOSHYS_NVM_A;
extern const uint16 FUEL_DUAL_PERCENT_FULLNEGHYS_NVM_A;
extern const uint16 FUEL_DUAL_PERCENT_FULLPOSHYS_NVM_B;
extern const uint16 FUEL_DUAL_PERCENT_FULLNEGHYS_NVM_B;

#else

extern const uint16 FUEL_DUAL_PERCENT_FULLPOSHYS_NVM_A[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_DUAL_PERCENT_FULLNEGHYS_NVM_A[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_DUAL_PERCENT_FULLPOSHYS_NVM_B[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_DUAL_PERCENT_FULLNEGHYS_NVM_B[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

/**********************************************************************************************************
** Define the threshold at which to check for rental car topoff.
*********************************************************************************************************/

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 fuel_dual_a_rc_fill_threshold_nvm;
extern const uint16 fuel_dual_b_rc_fill_threshold_nvm;

#else

extern const uint16 fuel_dual_a_rc_fill_threshold_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 fuel_dual_b_rc_fill_threshold_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

/**********************************************************************************************************
** Define the fill check to use for rental car topoff.
*********************************************************************************************************/

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 fuel_dual_a_rc_fill_delta_nvm;
extern const uint16 fuel_dual_b_rc_fill_delta_nvm;

#else

  extern const uint16 fuel_dual_a_rc_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint16 fuel_dual_b_rc_fill_delta_nvm[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifdef FUEL_DUAL_FFRC_ENABLE
 #ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
  extern const uint8 FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_A_NVM;
  extern const uint8 FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_B_NVM;
  extern const uint8 FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_A_NVM;
  extern const uint8 FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_B_NVM;
 #else
  extern const uint8 FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint8 FUEL_DUAL_UPPER_RATE_CHECK_LIMIT_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint8 FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint8 FUEL_DUAL_LOWER_RATE_CHECK_LIMIT_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
 #endif
#endif


#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_DUAL_ZS_DELTA_A_NVM;
extern const uint16 FUEL_DUAL_ZS_DELTA_B_NVM;

#else

extern const uint16 FUEL_DUAL_ZS_DELTA_A_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_DUAL_ZS_DELTA_B_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

/* --------------------------------------------------------------------------
** Counter value used to determine when to take the zero speed sample
** used for gage init and fast fill.
*********************************************************************************************************/

extern const uint16 FUEL_DUAL_ZERO_SPEED_COUNTER_NVM;

/* --------------------------------------------------------------------------
** Flags to enable/disable tank B, dual sender, zss ref only, hill hold,
** and fast fill.
*********************************************************************************************************/

#ifdef FUEL_DUAL_ZSS_REF_ONLY
  #define FUEL_DUAL_TEMPZ FUEL_DUAL_ZSS_REF_ONLY_BIT
#else
  #define FUEL_DUAL_TEMPZ 0
#endif

#ifdef FUEL_DUAL_HILL_HOLD_ENABLE
  #define FUEL_DUAL_TEMP1 FUEL_DUAL_HILL_HOLD_ENABLE_BIT
#else
  #define FUEL_DUAL_TEMP1 0
#endif

#ifdef FUEL_DUAL_FAST_FILL_ENABLE
  #define FUEL_DUAL_TEMP2 FUEL_DUAL_FAST_FILL_ENABLE_BIT
#else
  #define FUEL_DUAL_TEMP2  0
#endif

extern const uint8 FUEL_DUAL_OPTIONS_NVM;

#ifdef FUEL02_AD_TO_PF_TBL_IN_NVM
/* If AD_TO_PF_TBL is required to be put in NVM, then allocate NVM segment here */

#else
/* If AD_TO_PF_TBL is not required to be put in NVM, then do not anything here
** it means it compiler continue to put AD_TO_PF_TBL in FUEL02_CONSTANT_SEGMENT segment */

#endif

#if FUEL_DUAL_NUM_FUEL_TABLES==1
//    extern const uint16 FUEL_DUAL_SENDER_A_TABLE_NVM[FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_SIZE][2];
//    extern const uint16 FUEL_DUAL_SENDER_B_TABLE_NVM[FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_SIZE][2];
#else

#endif


/*-----------------------------------------------------------
** Optional definitions of CANFLPS tables
** -----------------------------------------------------------
*/
#ifdef FUEL_DUAL_CANFLPS_A
extern const uint16 FUEL_DUAL_CANFLPS_A_TABLE_NVM[FUEL_DUAL_CANFLPS_SIZE_A][2];
#endif

#ifdef FUEL_DUAL_CANFLPS_B
extern const uint16 FUEL_DUAL_CANFLPS_B_TABLE_NVM[FUEL_DUAL_CANFLPS_SIZE_B][2];
#endif


#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
    /*
    ** Define weighting for dual senders.  Note that (w1+w2)/256 must be 1
    ** or they are invalid.
    */
    //#if ((FUEL_DUAL_SENDERA_WEIGHT + FUEL_DUAL_SENDERB_WEIGHT) != 256)
    //  #error FUEL_DUAL.CFG: FUEL_DUAL_SENDERA_WEIGHT + FUEL_DUAL_SENDERB_WEIGHT must sum to 256.
    //#endif

    extern const uint16 FUEL_DUAL_SENDERA_WEIGHT_NVM;
    extern const uint16 FUEL_DUAL_SENDERB_WEIGHT_NVM;

    /*
    ** Define failure percent full values for the dual senders.
    */
    extern const uint16 FUEL_DUAL_SENDERA_ERROR_NVM;
    extern const uint16 FUEL_DUAL_SENDERB_ERROR_NVM;

#else

    /*
    ** Define weighting for dual senders.  Note that (w1+w2)/256 must be 1
    ** or they are invalid.
    */
    extern const uint32 FUEL_DUAL_SENDERA_WEIGHT_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
    extern const uint32 FUEL_DUAL_SENDERB_WEIGHT_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

    /*
    ** Define failure percent full values for the dual senders.
    */
    extern const uint16 FUEL_DUAL_SENDERA_ERROR_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
    extern const uint16 FUEL_DUAL_SENDERB_ERROR_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

/*
** Define the maximum allowed key-off sampling time.
*/
extern const uint16 FUEL_DUAL_IGNOFF_SAMPLE_TIME_NVM;

#ifndef FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS
  extern const uint8 FUEL_DUAL_SENDER_B_ENABLE_NVM;
  extern const uint8 FUEL_DUAL_SADDLE_TANK_SYSTEM_NVM;
#else
  extern const uint8 FUEL_DUAL_TANK_ARRAY_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS][2];
  extern const uint8 FUEL_DUAL_SENDER_B_ENABLE_NVM[FUEL_DUAL_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint8 FUEL_DUAL_SADDLE_TANK_SYSTEM_NVM;
#endif

#if FUEL_DUAL_LOG_FAULT_RECORD_SIZE > 0

/**********************************************************************************************************
** Create a storage location that the fault log will be written to. This is
** initialized to an invalid number (0xff).
*********************************************************************************************************/

extern const uint8 FUEL_DUAL_NEXT_FAULT_LOG_WRITE_NVM;

extern const FUEL02_FAULT_SNAPSHOT_STRUCT FUEL_DUAL_FAULT_SNAPSHOT_A_NVM[FUEL_DUAL_LOG_FAULT_RECORD_SIZE];
extern const FUEL02_FAULT_SNAPSHOT_STRUCT FUEL_DUAL_FAULT_SNAPSHOT_B_NVM[FUEL_DUAL_LOG_FAULT_RECORD_SIZE];

#endif
#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

void Fuel_Dual_Pkg_Date_Init(void);

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*#endif //Section End                                                                                     *
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
