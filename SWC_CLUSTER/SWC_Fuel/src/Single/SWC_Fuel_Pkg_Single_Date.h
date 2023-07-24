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

#ifndef FUEL_PKG_SINGLE_DATE_H
#define FUEL_PKG_SINGLE_DATE_H
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Pkg_Single_Cfg.h"


/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

extern uint16 Fuel_Sinngle_Fuel_Tank_Size;

#ifndef FUEL_SINGLE_NUM_FUEL_TABLES
 #define FUEL_SINGLE_NUM_FUEL_TABLES                                (5)
#else
 #if FUEL_SINGLE_NUM_FUEL_TABLES<1
  #error FUEL_SINGLE_NUM_FUEL_TABLES must be greater than zero !
 #endif
#endif

#ifndef FUEL_SINGLE_LOG_FAULT_RECORD_SIZE
  #define FUEL_SINGLE_LOG_FAULT_RECORD_SIZE                         (0)
#endif

#ifndef FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE
   #define FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE                    (0)
#endif


#if FUEL_SINGLE_LOG_FAULT_RECORD_SIZE != 0
  #if (FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE == 0)
    #error FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE must be defined when FUEL_SINGLE_LOG_FAULT_RECORD_SIZE macro enabled!
  #elif (FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE < FUEL_SINGLE_LOG_FAULT_RECORD_SIZE)
     #error FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE greater than or equal toFUEL03_LOG_FAULT_RECORD_SIZE!
  #endif
#endif


#ifndef FUEL_SINGLE_ADD_CONVERGENCE_DATA_TO_FAULT_RECORD
#if FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE > 0
#define FUEL_SINGLE_LOG_fdelta                                      (0u)
#define FUEL_SINGLE_LOG_fdelta_base                                 (0u)
#define FUEL_SINGLE_LOG_fdelta_adjust_base                          (0u)
#define FUEL_SINGLE_LOG_FilterFlags                                 (1u)
#define FUEL_SINGLE_LOG_flps                                        (1u)
#define FUEL_SINGLE_LOG_init_ref                                    (1u)
#define FUEL_SINGLE_LOG_init_pid                                    (1u)
#define FUEL_SINGLE_LOG_KeyOffRef                                   (1u)
#define FUEL_SINGLE_LOG_keyon_radsum                                (1u)
#define FUEL_SINGLE_LOG_keyon_good_samples                          (1u)
#define FUEL_SINGLE_LOG_keyon_avgflps                               (1u)
#define FUEL_SINGLE_LOG_avgflps_saddle                              (0u)
#define FUEL_SINGLE_LOG_MoreFilterFlags                             (1u)
#define FUEL_SINGLE_LOG_FuelFaultCounter                            (0u)
#define FUEL_SINGLE_LOG_FuelFaultRecoveryCounter                    (0u)
#define FUEL_SINGLE_LOG_rad                                         (1u)
#define FUEL_SINGLE_LOG_avg_rad                                     (0u)
#define FUEL_SINGLE_LOG_old_rad                                     (0u)
#define FUEL_SINGLE_LOG_sample_array                                (0u)
#define FUEL_SINGLE_LOG_rc_fill_threshold                           (0u)
#define FUEL_SINGLE_LOG_rc_fill_delta                               (0u)
#define FUEL_SINGLE_LOG_rflps                                       (0u)
#define FUEL_SINGLE_LOG_rfuel                                       (0u)
#define FUEL_SINGLE_LOG_slosh_filter                                (1u)
#define FUEL_SINGLE_LOG_slosh_filter_hys                            (1u)
#define FUEL_SINGLE_LOG_zss_ref                                     (1u)
#define FUEL_SINGLE_LOG_rate_check_passed                           (0u)
#define FUEL_SINGLE_LOG_rate_check_timer                            (0u)
#define FUEL_SINGLE_LOG_ffrc_delta_ref                              (0u)
#define FUEL_SINGLE_LOG_sample_counter                              (0u)
#define FUEL_SINGLE_LOG_rate_check_sample                           (0u)
#define FUEL_SINGLE_LOG_ConvCycleCounter                            (0u)
#define FUEL_SINGLE_LOG_ConvSample                                  (0u)
#define FUEL_SINGLE_LOG_SmplCounter                                 (0u)
#define FUEL_SINGLE_LOG_min_vx                                      (0u)
#define FUEL_SINGLE_LOG_max_vx                                      (0u)
#define FUEL_SINGLE_LOG_sum_vx                                      (0u)
#define FUEL_SINGLE_LOG_koc_converged                               (1u)
#define FUEL_SINGLE_LOG_koc_fault_flag                              (0u)
#define FUEL_SINGLE_LOG_zs_converged                                (1u)
#define FUEL_SINGLE_LOG_moving_sample_counter                       (0u)
#define FUEL_SINGLE_LOG_use_avg_flag                                (0u)
#define FUEL_SINGLE_LOG_use_mov_avg                                 (0u)
#define FUEL_SINGLE_LOG_err_counter                                 (0u)

typedef struct {

#if FUEL_SINGLE_LOG_fdelta==1
 uint32 fuel_single_log_fdelta;
#endif
#if FUEL_SINGLE_LOG_fdelta_base==1
 uint32 fuel_single_log_fdelta_base;
#endif
#if FUEL_SINGLE_LOG_fdelta_adjust_base==1
 uint16 fuel_single_log_fdelta_adjust_base;
#endif
#if FUEL_SINGLE_LOG_FilterFlags==1
 uint8  fuel_single_log_FilterFlags;
#endif
#if FUEL_SINGLE_LOG_flps==1
 uint8  fuel_single_log_flps;
#endif
#if FUEL_SINGLE_LOG_init_ref==1
 uint8  fuel_single_log_init_ref;
#endif
#if FUEL_SINGLE_LOG_init_pid==1
 uint16 fuel_single_log_init_pid;
#endif
#if FUEL_SINGLE_LOG_KeyOffRef==1
 uint8  fuel_single_log_KeyOffRef;
#endif
#if FUEL_SINGLE_LOG_keyon_radsum==1
 uint32 fuel_single_log_keyon_radsum;
#endif
#if FUEL_SINGLE_LOG_keyon_good_samples==1
 uint8  fuel_single_log_keyon_good_samples;
#endif
#if FUEL_SINGLE_LOG_keyon_avgflps==1
 uint8  fuel_single_log_keyon_avgflps;
#endif
#if FUEL_SINGLE_LOG_avgflps_saddle==1
 uint8  fuel_single_log_avgflps_saddle;
#endif
#if FUEL_SINGLE_LOG_MoreFilterFlags==1
 uint8  fuel_single_log_MoreFilterFlags;
#endif
#if FUEL_SINGLE_LOG_FuelFaultCounter==1
 uint16 fuel_single_log_FuelFaultCounter;
#endif
#if FUEL_SINGLE_LOG_FuelFaultRecoveryCounter==1
 uint16 vFuelFaultRecoveryCounter;
#endif
#if FUEL_SINGLE_LOG_rad==1
 uint16 fuel_single_log_rad;
#endif
#if FUEL_SINGLE_LOG_avg_rad==1
 uint16 fuel_single_log_avg_rad;
#endif
#if FUEL_SINGLE_LOG_old_rad==1
 uint16 fuel_single_log_old_rad;
#endif
#if FUEL_SINGLE_LOG_sample_array==1
 uint16 fuel_single_log_sample_array[FUEL_SINGLE_SMPLS_2_AVG];
#endif
#if FUEL_SINGLE_LOG_rc_fill_threshold==1
 uint8  fuel_single_log_rc_fill_threshold;
#endif
#if FUEL_SINGLE_LOG_rc_fill_delta==1
 uint8  fuel_single_log_rc_fill_delta;
#endif
#if FUEL_SINGLE_LOG_rflps==1
 uint8  fuel_single_log_rflps;
#endif
#if FUEL_SINGLE_LOG_rfuel==1
 uint8  fuel_single_log_rfuel;
#endif
#if FUEL_SINGLE_LOG_slosh_filter==1
 uint32 fuel_single_log_slosh_filter;
#endif
#if FUEL_SINGLE_LOG_slosh_filter_hys==1
 uint32 fuel_single_log_slosh_filter_hys;
#endif
#if FUEL_SINGLE_LOG_zss_ref==1
 uint8  fuel_single_log_zss_ref;
#endif
#ifdef FUEL_SINGLE_FFRC_ENABLE
#if FUEL_SINGLE_LOG_rate_check_passed==1
 boolean fuel_single_log_rate_check_passed;
#endif
#if FUEL_SINGLE_LOG_rate_check_timer==1
 uint16  fuel_single_log_rate_check_timer;
#endif
#if FUEL_SINGLE_LOG_ffrc_delta_ref==1
 uint8   fuel_single_log_ffrc_delta_ref;
#endif
#if FUEL_SINGLE_LOG_sample_counter==1
 uint8   fuel_single_log_sample_counter;
#endif
#if FUEL_SINGLE_LOG_rate_check_sample==1
 uint8   fuel_single_log_rate_check_sample[FUEL_SINGLE_MAX_RATE_CHECK_SAMPLES+1];
#endif
#endif
#if (FUEL_SINGLE_REF_AVG_TYPE==4)
#if FUEL_SINGLE_LOG_ConvCycleCounter==1
 uint8   fuel_single_log_ConvCycleCounter;
#endif
#if FUEL_SINGLE_LOG_ConvSample==1
 uint8   fuel_single_log_ConvSample;
#endif
#if FUEL_SINGLE_LOG_SmplCounter==1
 uint8   fuel_single_log_SmplCounter;
#endif
#if FUEL_SINGLE_LOG_min_vx==1
 uint8   fuel_single_log_min_vx;
#endif
#if FUEL_SINGLE_LOG_max_vx==1
 uint8   fuel_single_log_max_vx;
#endif
#if FUEL_SINGLE_LOG_sum_vx==1
 uint16  fuel_single_log_sum_vx;
#endif
#if FUEL_SINGLE_LOG_koc_converged==1
 boolean fuel_single_log_koc_converged;
#endif
#if FUEL_SINGLE_LOG_koc_fault_flag==1
 boolean fuel_single_log_koc_fault_flag;
#endif
#if FUEL_SINGLE_LOG_zs_converged==1
 boolean fuel_single_log_zs_converged;
#endif
#endif
#if FUEL_SINGLE_LOG_moving_sample_counter==1
 uint8   fuel_single_log_moving_sample_counter;
#endif
#if FUEL_SINGLE_LOG_use_avg_flag==1
 uint8   fuel_single_log_use_avg_flag;
#endif
#if FUEL_SINGLE_LOG_use_mov_avg==1
 uint8   fuel_single_log_use_mov_avg;
#endif
#if FUEL_SINGLE_LOG_err_counter==1
 uint16  fuel_single_log_err_counter;
#endif

} FUEL_SINGLE_FAULT_SNAPSHOT_STRUCT;
#endif
#else
 /* ----------------------------------------------------------------------------------
** The following configuration items allow the application to decide which fuel
** values to save.
** Set to 1 to enable storage, 0 to disable storage.
** ----------------------------------------------------------------------------------
*/
#if FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE > 0
#define FUEL_SINGLE_LOG_fdelta                                      (0u)
#define FUEL_SINGLE_LOG_fdelta_base                                 (0u)
#define FUEL_SINGLE_LOG_keyon_radsum                                (1u)
#define FUEL_SINGLE_LOG_slosh_filter                                (1u)
#define FUEL_SINGLE_LOG_slosh_filter_hys                            (1u)
#define FUEL_SINGLE_LOG_fdelta_adjust_base                          (0u)
#define FUEL_SINGLE_LOG_init_pid                                    (1u)
#define FUEL_SINGLE_LOG_FuelFaultCounter                            (0u)
#define FUEL_SINGLE_LOG_FuelFaultRecoveryCounter                    (0u)
#define FUEL_SINGLE_LOG_rad                                         (1u)
#define FUEL_SINGLE_LOG_avg_rad                                     (0u)
#define FUEL_SINGLE_LOG_old_rad                                     (0u)
#define FUEL_SINGLE_LOG_sample_array                                (0u)
#define FUEL_SINGLE_LOG_err_counter                                 (0u)
#define FUEL_SINGLE_LOG_rate_check_timer                            (0u)
#define FUEL_SINGLE_LOG_sum_vx                                      (1u)
#define FUEL_SINGLE_LOG_ConvCycleCounter                            (1u)
#define FUEL_SINGLE_LOG_ConvSample                                  (1u)
#define FUEL_SINGLE_LOG_SmplCounter                                 (1u)
#define FUEL_SINGLE_LOG_min_vx                                      (1u)
#define FUEL_SINGLE_LOG_max_vx                                      (1u)
#define FUEL_SINGLE_LOG_koc_converged                               (1u)
#define FUEL_SINGLE_LOG_koc_fault_flag                              (0u)
#define FUEL_SINGLE_LOG_zs_converged                                (1u)
#define FUEL_SINGLE_LOG_rate_check_passed                           (0u)
#define FUEL_SINGLE_LOG_ffrc_delta_ref                              (0u)
#define FUEL_SINGLE_LOG_sample_counter                              (0u)
#define FUEL_SINGLE_LOG_rate_check_sample                           (0u)
#define FUEL_SINGLE_LOG_FilterFlags                                 (1u)
#define FUEL_SINGLE_LOG_flps                                        (1u)
#define FUEL_SINGLE_LOG_init_ref                                    (1u)
#define FUEL_SINGLE_LOG_KeyOffRef                                   (1u)
#define FUEL_SINGLE_LOG_keyon_good_samples                          (1u)
#define FUEL_SINGLE_LOG_keyon_avgflps                               (1u)
#define FUEL_SINGLE_LOG_avgflps_saddle                              (0u)
#define FUEL_SINGLE_LOG_MoreFilterFlags                             (1u)
#define FUEL_SINGLE_LOG_rc_fill_threshold                           (0u)
#define FUEL_SINGLE_LOG_rc_fill_delta                               (0u)
#define FUEL_SINGLE_LOG_rflps                                       (0u)
#define FUEL_SINGLE_LOG_rfuel                                       (0u)
#define FUEL_SINGLE_LOG_zss_ref                                     (1u)
#define FUEL_SINGLE_LOG_moving_sample_counter                       (0u)
#define FUEL_SINGLE_LOG_use_avg_flag                                (0u)
#define FUEL_SINGLE_LOG_use_mov_avg                                 (0u)
#define FUEL_SINGLE_LOG_invalid_condition                           (1u)
#define FUEL_SINGLE_LOG_ignition_cycle_counter                      (1u)


typedef struct {

#if FUEL_SINGLE_LOG_fdelta==1
 uint32 fuel_single_log_fdelta;
#endif

#if FUEL_SINGLE_LOG_fdelta_base==1
 uint32 fuel_single_log_fdelta_base;
#endif

#if FUEL_SINGLE_LOG_keyon_radsum==1
 uint32 fuel_single_log_keyon_radsum;
#endif

#if FUEL_SINGLE_LOG_slosh_filter==1
 uint32 fuel_single_log_slosh_filter;
#endif

#if FUEL_SINGLE_LOG_slosh_filter_hys==1
 uint32 fuel_single_log_slosh_filter_hys;
#endif

#if FUEL_SINGLE_LOG_fdelta_adjust_base==1
 uint16 fuel_single_log_fdelta_adjust_base;
#endif

#if FUEL_SINGLE_LOG_init_pid==1
 uint16 fuel_single_log_init_pid;
#endif

#if FUEL_SINGLE_LOG_FuelFaultCounter==1
 uint16 fuel_single_log_FuelFaultCounter;
#endif

#if FUEL_SINGLE_LOG_FuelFaultRecoveryCounter==1
 uint16 fuel_single_log_FuelFaultRecoveryCounter;
#endif

#if FUEL_SINGLE_LOG_rad==1
 uint16 fuel_single_log_rad;
#endif

#if FUEL_SINGLE_LOG_avg_rad==1
 uint16 fuel_single_log_avg_rad;
#endif

#if FUEL_SINGLE_LOG_old_rad==1
 uint16 fuel_single_log_old_rad;
#endif

#if FUEL_SINGLE_LOG_sample_array==1
 uint16 fuel_single_log_sample_array[FUEL_SINGLE_SMPLS_2_AVG];
#endif

#if FUEL_SINGLE_LOG_err_counter==1
 uint16  fuel_single_log_err_counter;
#endif

#ifdef FUEL_SINGLE_FFRC_ENABLE
#if FUEL_SINGLE_LOG_rate_check_timer==1
 uint16  fuel_single_log_rate_check_timer;
#endif
#endif

#if (FUEL_SINGLE_REF_AVG_TYPE==4)
#if FUEL_SINGLE_LOG_sum_vx==1
 uint16  fuel_single_log_sum_vx;
#endif
#if FUEL_SINGLE_LOG_ConvCycleCounter==1
 uint8   fuel_single_log_ConvCycleCounter;
#endif
#if FUEL_SINGLE_LOG_ConvSample==1
 uint8   fuel_single_log_ConvSample;
#endif
#if FUEL_SINGLE_LOG_SmplCounter==1
 uint8   fuel_single_log_SmplCounter;
#endif
#if FUEL_SINGLE_LOG_min_vx==1
 uint8   fuel_single_log_min_vx;
#endif
#if FUEL_SINGLE_LOG_max_vx==1
 uint8   fuel_single_log_max_vx;
#endif
#if FUEL_SINGLE_LOG_koc_converged==1
 boolean fuel_single_log_koc_converged;
#endif
#if FUEL_SINGLE_LOG_koc_fault_flag==1
 boolean fuel_single_log_koc_fault_flag;
#endif
#if FUEL_SINGLE_LOG_zs_converged==1
 boolean fuel_single_log_zs_converged;
#endif
#endif

#ifdef FUEL_SINGLE_FFRC_ENABLE
#if FUEL_SINGLE_LOG_rate_check_passed==1
 boolean fuel_single_log_rate_check_passed;
#endif
#if FUEL_SINGLE_LOG_ffrc_delta_ref==1
 uint8   fuel_single_log_ffrc_delta_ref;
#endif
#if FUEL_SINGLE_LOG_sample_counter==1
 uint8   fuel_single_log_sample_counter;
#endif
#if FUEL_SINGLE_LOG_rate_check_sample==1
 uint8   fuel_single_log_rate_check_sample[FUEL_SINGLE_MAX_RATE_CHECK_SAMPLES+1];
#endif
#endif

#if FUEL_SINGLE_LOG_FilterFlags==1
 uint8  fuel_single_log_FilterFlags;
#endif

#if FUEL_SINGLE_LOG_flps==1
 uint8  fuel_single_log_flps;
#endif

#if FUEL_SINGLE_LOG_init_ref==1
 uint8  fuel_single_log_init_ref;
#endif

#if FUEL_SINGLE_LOG_KeyOffRef==1
 uint8  fuel_single_log_KeyOffRef;
#endif

#if FUEL_SINGLE_LOG_keyon_good_samples==1
 uint8  fuel_single_log_keyon_good_samples;
#endif

#if FUEL_SINGLE_LOG_keyon_avgflps==1
 uint8  fuel_single_log_keyon_avgflps;
#endif

#if FUEL_SINGLE_LOG_avgflps_saddle==1
 uint8  fuel_single_log_avgflps_saddle;
#endif

#if FUEL_SINGLE_LOG_MoreFilterFlags==1
 uint8  fuel_single_log_MoreFilterFlags;
#endif

#if FUEL_SINGLE_LOG_rc_fill_threshold==1
 uint8  fuel_single_log_rc_fill_threshold;
#endif

#if FUEL_SINGLE_LOG_rc_fill_delta==1
 uint8  fuel_single_log_rc_fill_delta;
#endif

#if FUEL_SINGLE_LOG_rflps==1
 uint8  fuel_single_log_rflps;
#endif

#if FUEL_SINGLE_LOG_rfuel==1
 uint8  fuel_single_log_rfuel;
#endif

#if FUEL_SINGLE_LOG_zss_ref==1
 uint8  fuel_single_log_zss_ref;
#endif

#if FUEL_SINGLE_LOG_moving_sample_counter==1
 uint8   fuel_single_log_moving_sample_counter;
#endif

#if FUEL_SINGLE_LOG_use_avg_flag==1
 uint8   fuel_single_log_use_avg_flag;
#endif

#if FUEL_SINGLE_LOG_use_mov_avg==1
 uint8   fuel_single_log_use_mov_avg;
#endif

#if FUEL_SINGLE_LOG_invalid_condition==1
 uint8   fuel_single_log_fuel03_invalid_condition;
#endif

#if FUEL_SINGLE_LOG_ignition_cycle_counter==1
 uint8   fuel_single_log_fuel03_ignition_cycle_counter;
#endif

/* As of now totally 23 elements have been enabled resulting 35 bytes   */
/* memory occupation. So in order to have multiples of 4 bytes one byte */
/* padding is done here. In future if any bytes are enabled here this   */
/* has to be taken care accordingly                                     */
 uint8   fuel_single_log_padded_byte;

} FUEL_SINGLE_FAULT_SNAPSHOT_STRUCT;
#endif
#endif
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
   extern uint16 FUEL_SINGLE_KO_DELTA_A_NVM;
#else
   extern uint8 FUEL_SINGLE_KO_DELTA_A_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
#endif
   
#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
   extern uint16 FUEL_SINGLE_ZSS_DELTA_A_NVM;
#else
	   extern uint8 FUEL_SINGLE_ZSS_DELTA_A_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
#endif


#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

extern uint16 fuel_single_postive_init_fill_delta_a_nvm;
extern uint16 fuel_single_negtive_init_fill_delta_a_nvm;

#else

extern const uint8 fuel_single_postive_init_fill_delta_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint8 fuel_single_negtive_init_fill_delta_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
extern uint32 fuel_single_delta_normalup_base_a_nvm;
extern uint32 fuel_single_delta_normaldown_base_a_nvm;

extern uint32 fuel_single_delta_normal_base_a_nvm;
extern uint32 fuel_single_delta_normal_idle_base_a_nvm;
extern uint32 fuel_single_delta_negtive_low_base_a_nvm;
extern uint32 fuel_single_delta_postive_low_base_a_nvm;

extern uint32 fuel_single_delta_fast_base_a_nvm;
extern uint32 fuel_single_delta_fast_base_a_neg_nvm;

extern uint16 fuel_single_postive_init_fill_a_nvm;
extern uint16 fuel_single_negtive_init_fill_a_nvm;

extern uint16  fuel_single_postive_fastfill_a_nvm;
extern uint16  fuel_single_negtive_fastfill_a_nvm;
extern uint16  fuel_single_negtive_leakiing_fastfill_a_nvm;


extern uint16 fuel_single_ad_short_limit_nvm;
extern uint16 fuel_single_ad_open_limit_nvm;

extern uint8  fuel_single_ignon_delay_counter_nvm;
extern uint8  fuel_single_init_delay_counter_nvm;
extern uint16 fuel_single_fault_counter_nvm;
extern uint16 fuel_single_fault_recovery_counter_nvm;
extern uint8  fuel_single_fastfill_time_counter_nvm;

#else

extern uint32 fuel_single_delta_normal_base_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

extern uint32 fuel_single_delta_fast_base_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

extern uint8 fuel_single_postive_init_fill_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern uint8 fuel_single_negtive_init_fill_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

extern uint8 fuel_single_postive_fastfill_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern uint8 fuel_single_negtive_fastfill_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

extern uint16 fuel_single_ad_short_limit_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern uint16 fuel_single_ad_open_limit_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif
#define SWC_FUEL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS


extern const uint16 fuel_single_delta_normal_adjust_a_nvm;
extern const uint32 fuel_single_delta_normal_clamp_a_nvm;

#else


extern const uint16 fuel_single_delta_normal_adjust_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint32 fuel_single_delta_normal_clamp_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 fuel_single_delta_fast_adjust_a_nvm;

extern const uint32 fuel_single_delta_fast_clamp_a_nvm;

#else

extern const uint16 fuel_single_delta_fast_adjust_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

extern const uint32 fuel_single_delta_fast_clamp_a_nvm[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifdef FUEL_SINGLE_CAN_FLPS
extern const uint16 FUEL_SINGLE_CANFLPS_TABLE_NVM[FUEL_SINGLE_CANFLPS_SIZE][2];
#endif


#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_SINGLE_PERCENT_FULL_POSTIVE_HYS_NVM;
extern const uint16 FUEL_SINGLE_PERCENT_FULL_NEGTIVE_HYS_NVM;

#else

extern const uint16 FUEL_SINGLE_PERCENT_FULL_POSTIVE_HYS_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
extern const uint16 FUEL_SINGLE_PERCENT_FULL_NEGTIVE_HYS_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif


#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_SINGLE_SENDERA_RCFILL_THERSHOLD_NVM;

#else

extern const uint8 FUEL_SINGLE_SENDERA_RCFILL_THERSHOLD_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif


#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

extern const uint16 FUEL_SINGLE_SENDERA_RCFILL_DELTA_NVM;

#else

extern const uint8 FUEL_SINGLE_SENDERA_RCFILL_DELTA_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];

#endif

#ifdef FUEL_SINGLE_FFRC_ENABLE
 #ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
  extern const uint8 FUEL_SINGLE_UPPER_RATE_LIMIT_NVM;
  extern const uint8 FUEL_SINGLE_LOWER_RATE_LIMIT_NVM;
 #else
  extern const uint8 FUEL_SINGLE_UPPER_RATE_LIMIT_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
  extern const uint8 FUEL_SINGLE_LOWER_RATE_LIMIT_NVM[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS];
 #endif
#endif



#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS

 #else

 #endif


#ifdef FUEL_SINGLE_ZSS_REF_ONLY
  #define FUEL_SINGLE_TEMPZ FUEL_SINGLE_ZSS_REF_ONLY_BIT
#else
  #define FUEL_SINGLE_TEMPZ 0
#endif

#ifdef FUEL_SINGLE_HILL_HOLD_ENABLE
  #define FUEL_SINGLE_TEMP1 FUEL_SINGLE_HILL_HOLD_ENABLE_BIT
#else
  #define FUEL_SINGLE_TEMP1 0
#endif

#ifdef FUEL_SINGLE_FAST_FILL_ENABLE
  #define FUEL_SINGLE_TEMP2 FUEL_SINGLE_FAST_FILL_ENABLE_BIT
#else
  #define FUEL_SINGLE_TEMP2  0
#endif

extern const uint8 FUEL_SINGLE_OPTIONS_NVM;
#ifndef FUEL_SINGLE_AD_TO_PF_TBL_IN_NVM
/* If AD_TO_PF_TBL is not required to be put in NVM, then do not anything here
** it means it compiler continue to put AD_TO_PF_TBL in FUEL03_CONSTANT_SEGMENT segment */
  #if FUEL_SINGLE_NUM_FUEL_TABLES==1
#if 0
    extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
#endif      
    extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_1[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE1][2];
  
  #else
    extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_NUM_FUEL_TABLES][FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
  #endif

  
#endif

#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
  extern const uint8 FUEL_SINGLE_TANK_ARRAY[2];
#else
  extern const uint8 FUEL_SINGLE_TANK_ARRAY[FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS][2];
#endif

/**********************************************************************************************************
** Counter value used to determine when to take the zero speed sample
** used for gage init and fast fill.
**********************************************************************************************************/

extern const uint16 FUEL_SINGLE_ZERO_SPEED_COUNTER_NVM;

/**********************************************************************************************************
* Define the maximum allowed key-off sampling time.                                                       *
**********************************************************************************************************/

extern const uint16 FUEL_SINGLE_IGNOFF_SAMPLE_TIME_NVM;
extern const uint8  FUEL_SINGLE_INIT_GOOD_SAMPLE_REQ_NVM;


#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
#if( defined( FUEL_SINGLE_AD_TO_PF_TBL_IN_NVM)||(FUEL_SINGLE_LOG_FAULT_RECORD_SIZE > 0))
  #ifdef FUEL_SINGLE_AD_TO_PF_TBL_IN_NVM
    #ifdef CWR_SPECTRUM_TYPE
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
     #if FUEL_SINGLE_NUM_FUEL_TABLES==1
       extern uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
     #else
       extern uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_NUM_FUEL_TABLES][FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
     #endif
#define SWC_FUEL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
   #else
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
     #if FUEL_SINGLE_NUM_FUEL_TABLES==1
       extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
     #else
       extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM[FUEL_SINGLE_NUM_FUEL_TABLES][FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE][2];
     #endif
#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
   #endif
 #endif
  #if FUEL_SINGLE_LOG_FAULT_RECORD_SIZE > 0
   #ifdef CWR_SPECTRUM_TYPE
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
    extern uint8 Fuel_Single_Next_Fault_Log_To_Write_Nvm;
    extern FUEL_SINGLE_FAULT_SNAPSHOT_STRUCT Fuel_Single_Fault_Snapshot_A_Nvm[FUEL_SINGLE_LOG_FAULT_RECORD_SIZE];
#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
   #else
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
    extern const uint8 Fuel_Single_Next_Fault_Log_To_Write_Nvm;
    extern const FUEL_SINGLE_FAULT_SNAPSHOT_STRUCT Fuel_Single_Fault_Snapshot_A_Nvm[FUEL_SINGLE_LOG_FAULT_RECORD_SIZE];
#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
   #endif
  #endif
#endif

#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

extern void Fuel_Single_Pkg_Date_Init(void);

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"


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
