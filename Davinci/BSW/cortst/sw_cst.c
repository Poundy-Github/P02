/*
---------------------------------------------------------------------------------
--                                                                             --
--  Project         : SW G3K/G3M                                               --
--                                                                             --
--  Module Name     : sw_cst.c                                                 --
--  Language        : Green Hills Software Inc. assembler 3.5.1                --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--  created at      : 22.10.2012  by: Yogitech                                 --
--                                                                             --
--  last modified   :  Date: 2016/03/02                                        --
--  by              :  Author: YT                                              --
--  Version         :  Revision: 1.8                                           --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--  Description     : single module run file of SW G3K/G3M                     --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--                                                                             --
--  Revision History:                                                          --
--  -----------------                                                          --
--  1.0 initial version                                                        --
--  1.1 add comments                                                           --
--  1.2 included config.h file                                                 --
--  1.3 0022688 added new API function to call modules subsets                 --
--      0023806 removed INTERRUPT_TEST macro                                   --
--  1.4 0024057 multiple modifications for MISRA and AUTOSAR compliance        --
--      0024478 robustness improvement for test_id errors                      --
--  1.5 Changed NO_MOD_SIGNATURE to MOD_SIGNATURE_VALUE for the verific. env.  --
--  1.6 0024229 removed F1LVERS switches and R1L code                          --
--  1.7 File renamed from sw_g3k.c to sw_cst.c                                 --
--  1.8 ARDAAAC-606 #define TEST_ID_ERROR is removed from G3M core.            --
--      Project name and Description is updated with G3M.                      --
---------------------------------------------------------------------------------
*/


/* Included to get the pre-compile macros */
#include "CorTst_Cfg.h"

#if (CORE_G3K == CORTST_SWCST)
#include "st_glob.h"
#include "config.h"
#else
#include "CST_if.h"
#endif
#include "SW_G3K_Types.h"


#if (CORE_G3K == CORTST_SWCST)

/* The correct signature depends on the individual configuration of the core
   selftest do a test run on an emulation system to find out the signature for
   your individual settings  */
/* TS 1 */
sint64 _ST_MODULE_1(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 2 */
sint64 _ST_MODULE_2(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 3 -- used to exclude this test segment */
#if REGISTER_BANK_TEST
   sint64 _ST_MODULE_3(sint32 norm, sint32 *tbl, sint32 tst_id) ;
#endif

/* TS 4 */
sint64 _ST_MODULE_4(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 6 */
sint64 _ST_MODULE_6(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 7 -- used to exclude this test segment */
#if REGISTER_BANK_TEST
   sint64 _ST_MODULE_7(sint32 norm, sint32 *tbl, sint32 tst_id) ;
#endif

/* TS 9 */
sint64 _ST_MODULE_9(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 10 */
sint64 _ST_MODULE_10(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 11 */
sint64 _ST_MODULE_11(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 12 */
sint64 _ST_MODULE_12(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 14 */
sint64 _ST_MODULE_14(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 15 */
sint64 _ST_MODULE_15(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 16 */
sint64 _ST_MODULE_16(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 17 -- used to exclude this test segment */
#if MPU_TEST
   sint64 _ST_MODULE_17(sint32 norm, sint32 *tbl, sint32 tst_id) ;
#endif

/* TS 18 -- used to exclude this test segment */
#if RAM_TEST
   sint64 _ST_MODULE_18(sint32 norm, sint32 *tbl, sint32 tst_id) ;
#endif

/* TS 19 */
sint64 _ST_MODULE_19(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 20  */
sint64 _ST_MODULE_20(sint32 norm, sint32 *tbl, sint32 tst_id) ;

/* TS 21 -- used to exclude this test segment */
#if SPECIAL_REGISTER_BANK_TEST
   sint64 _ST_MODULE_21(sint32 norm, sint32 *tbl, sint32 tst_id) ;
#endif

sint32 Swg3k_TestRam[12] ; /* 12 words of internal (!) RAM required for various tests */
sint32 Swg3k_ModSignature; /* used for request to modify signature */

#else
/* TS 1 */
extern uint32 CST_CPU_arithmetic_1(void) ;

/* TS 2 */
extern uint32 CST_CPU_arithmetic_2(void) ;

/* TS 3 */
extern uint32 CST_CPU_arithmetic_3(void) ;

/* TS 4 */
extern uint32 CST_CPU_arithmetic_4(void) ;

/* TS 5 */
extern uint32 CST_CPU_bit_1(void) ;

/* TS 6 */
extern uint32 CST_CPU_bit_2(void) ;

/* TS 7 */
extern uint32 CST_CPU_bitinsert_1(void) ;

/* TS 8 */
extern uint32 CST_CPU_bitsearch_1(void) ;

/* TS 9 */
extern uint32 CST_CPU_boolean_1(void) ;

/* TS 10 */
extern uint32 CST_CPU_branch_1(void) ;

/* TS 11 */
extern uint32 CST_CPU_cond_br_1(void) ;

/* TS 12 */
extern uint32 CST_CPU_cond_data_1(void) ;

/* TS 13 */
extern uint32 CST_CPU_cond_data_2(void) ;

/* TS 14 */
extern uint32 CST_CPU_cond_data_3(void) ;

/* TS 15 */
extern uint32 CST_CPU_condition_1(void) ;

/* TS 16 */
extern uint32 CST_CPU_condition_2(void) ;

/* TS 17 */
extern uint32 CST_CPU_data_1(void) ;

/* TS 18 */
extern uint32 CST_CPU_data_2(void) ;

/* TS 19 */
extern uint32 CST_CPU_div_1(void) ;

/* TS 20 */
extern uint32 CST_CPU_div_2(void) ;

/* TS 21 */
extern uint32 CST_CPU_hsdiv_1(void) ;

/* TS 22 */
extern uint32 CST_CPU_ifu_1(void) ;

/* TS 23 */
extern uint32 CST_CPU_ipu_1(void) ;

/* TS 24 */
extern uint32 CST_CPU_jump_1(void) ;

/* TS 25 */
extern uint32 CST_CPU_load_1(void) ;

/* TS 26 */
extern uint32 CST_CPU_load_2(void) ;

/* TS 27 */
extern uint32 CST_CPU_loadlink_1(void) ;

/* TS 28 */
extern uint32 CST_CPU_loadstore_1(void) ;

/* TS 29 */
extern uint32 CST_CPU_loop_1(void) ;

/* TS 30 */
extern uint32 CST_CPU_lsu_1(void) ;

/* TS 31 */
extern uint32 CST_CPU_lsu_2(void) ;

/* TS 32 */
extern uint32 CST_CPU_mac_1(void) ;

/* TS 33 */
extern uint32 CST_CPU_memory_1(void) ;

/* TS 34 */
extern uint32 CST_CPU_memory_2(void) ;

/* TS 35 */
extern uint32 CST_CPU_mul_1(void) ;

/* TS 36 */
extern uint32 CST_CPU_mul_2(void) ;

/* TS 37 */
extern uint32 CST_CPU_mul_3(void) ;

/* TS 38 */
extern uint32 CST_CPU_mul_4(void) ;

/* TS 39 */
extern uint32 CST_CPU_saturated_1(void) ;

/* TS 40 */
extern uint32 CST_CPU_saturated_2(void) ;

/* TS 41 */
extern uint32 CST_CPU_saturated_3(void) ;

/* TS 42 */
extern uint32 CST_CPU_saturated_4(void) ;

/* TS 43 */
extern uint32 CST_CPU_shift_1(void) ;

/* TS 44 */
extern uint32 CST_CPU_shift_2(void) ;

/* TS 45 */
extern uint32 CST_CPU_shift_3(void) ;

/* TS 46 */
extern uint32 CST_CPU_shift_4(void) ;

/* TS 47 */
extern uint32 CST_CPU_special_1(void) ;

/* TS 48 */
extern uint32 CST_CPU_special_2(void) ;

/* TS 49 */
extern uint32 CST_CPU_special_3(void) ;

/* TS 50 */
extern uint32 CST_CPU_special_4(void) ;

/* TS 51 */
extern uint32 CST_CPU_special_5(void) ;

/* TS 52 */
extern uint32 CST_CPU_special_6(void) ;

/* TS 53 */
extern uint32 CST_CPU_special_7(void) ;

/* TS 54 */
extern uint32 CST_CPU_store_1(void) ;

/* TS 55 */
extern uint32 CST_CPU_store_2(void) ;

/* TS 56 */
extern uint32 CST_CPU_syscall_1(void) ;

/* TS 57 */
extern uint32 CST_CPU_trap_1(void) ;

/* TS 58 */
extern uint32 CST_CPU_trap_2(void) ;

/* TS 59 */
extern uint32 CST_FPU_calc_1(void) ;

/* TS 60 */
extern uint32 CST_FPU_calc_2(void) ;

/* TS 61 */
extern uint32 CST_FPU_calc_3(void) ;

/* TS 62 */
extern uint32 CST_FPU_calc_4(void) ;

/* TS 63 */
extern uint32 CST_FPU_calc_5(void) ;

/* TS 64 */
extern uint32 CST_FPU_calc_6(void) ;

/* TS 65 */
extern uint32 CST_FPU_cmov_1(void) ;

/* TS 66 */
extern uint32 CST_FPU_cmov_2(void) ;

/* TS 67 */
extern uint32 CST_FPU_cmp_1(void) ;

/* TS 68 */
extern uint32 CST_FPU_cmp_2(void) ;

/* TS 69 */
extern uint32 CST_FPU_cvt_1(void) ;

/* TS 70 */
extern uint32 CST_FPU_cvt_2(void) ;

/* TS 71 */
extern uint32 CST_FPU_cvt_3(void) ;

/* TS 72 */
extern uint32 CST_FPU_fmul_1(void) ;

/* TS 73 */
extern uint32 CST_FPU_fmul_2(void) ;

/* TS 74 */
extern uint32 CST_FPU_fmul_3(void) ;

/* TS 75 */
extern uint32 CST_FPU_fmul_4(void) ;

/* TS 76 */
extern uint32 CST_FPU_roundoff_1(void) ;

/* TS 77 */
extern uint32 CST_FPU_roundoff_2(void) ;

/* TS 78 */
extern uint32 CST_FPU_roundoff_3(void);

/* TS 79 */
extern uint32 CST_SRU_exc_1(void) ;

/* TS 80 */
extern uint32 CST_SRU_fpu_1(void) ;

/* TS 81 */
extern uint32 CST_SRU_fpu_2(void) ;

/* TS 82 */
extern uint32 CST_SRU_loadstore_1(void) ;

/* TS 83 */
extern uint32 CST_SRU_loadstore_2(void) ;

/* TS 84 */
extern uint32 CST_SRU_loadstore_3(void) ;

/* TS 85 */
extern uint32 CST_SRU_loadstore_4(void) ;

/* TS 86 */
extern uint32 CST_SRU_loadstore_5(void) ;

/* TS 87 */
extern uint32 CST_SRU_loadstore_6(void) ;

/* TS 88 */
extern uint32 CST_SRU_loadstore_7(void) ;

/* TS 89 */
extern uint32 CST_SRU_loadstore_8(void) ;

/* TS 90 */
extern uint32 CST_SRU_mpu_1(void) ;

sint32 Swg3k_TestRam[12] ; /* 12 words of internal (!) RAM required for various tests */

#endif


#if (CORE_G3K == CORTST_SWCST)
void CheckSignature (sint32 test_id,
                     sint32 *p_Result,
                     sint32 *p_NotResult,
                     sint32 *p_Signature,
                     sint32 *p_NotSignature,
                     volatile sint32 *resl ,
                     sint32  gold_sig);

/* 0024057 swCST & sw_g3k_subset prototypes for MISRA compliance */
void sw_cst (sint32 st_test_id,
             sint32 st_norm_val,
             sint32 *st_p_Result,
             sint32 *st_p_NotResult,
             sint32 *st_p_Signature,
             sint32 *st_p_NotSignature );

void sw_cst_subset(
             sint32  sb_test_id,
             sint32  sb_subset,
             sint32  sb_norm_val,
             sint32 *sb_p_Result,
             sint32 *sb_p_NotResult,
             sint32 *sb_p_Signature,
             sint32 *sb_p_NotSignature );

/*********************************************************************************
** Function that, for the selected test module (st_test_id), calls the single test **
** assembler procedure, calculates the normal (if norm_val=0) or inverted       **
** (if norm_val=1) signature and store the results values in memory addresses   **
** passed as param.                                                             **
**                                                                              **
**                                                                              **
**                                                                              **
**                                                                              **
*********************************************************************************/

void sw_cst (sint32 st_test_id,
             sint32 st_norm_val,
             sint32 *st_p_Result,
             sint32 *st_p_NotResult,
             sint32 *st_p_Signature,
             sint32 *st_p_NotSignature )
{
   sint8 st_i;
   static volatile sint64 st_result;
   /* MISRA VIOLATION TAG: 11.4.4 */
   volatile sint32 *st_resl = (volatile sint32 *) &st_result;

   /* 0024478 */
   if ( (0 < st_test_id) && (st_test_id < 22) ){
       /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
       /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
       st_p_Result[st_test_id - 1] = FAILED;
       st_p_NotResult[st_test_id - 1] = ~(st_p_Result[st_test_id - 1]);

       /* select the test id to perform. */
       switch (st_test_id)
       {
          case 1:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_1 expecting normal signature */
                st_result = _ST_MODULE_1(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE1);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_1 expecting inverted signature*/
                st_result = _ST_MODULE_1(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE1));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 2:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif
             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                 /* Call of the ST_MODULE_2 expecting normal signature*/
                 st_result = _ST_MODULE_2(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                 /* Check of the Signature and write of results in memory*/
                 CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE2);
             }
             else if (st_norm_val == 1){
                 /* Call of the ST_MODULE_2 expecting inverted signature*/
                 st_result = _ST_MODULE_2(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                 /* Check of the NOT Signature and write of results in memory*/
                 CheckSignature(st_test_id, st_p_Result, st_p_NotResult,st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE2));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 3:

    #if REGISTER_BANK_TEST

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_3 expecting normal signature*/
                st_result = _ST_MODULE_3(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE3);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_3 expecting inverted signature*/
                st_result = _ST_MODULE_3(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */

                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE3));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
    #else
          /* For global check: this TS is not called*/
          st_p_Result[st_test_id - 1] = PASSED;
    #endif

          break;

          case 4:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_4 expecting normal signature*/
                st_result = _ST_MODULE_4(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE4);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_4 expecting inverted signature*/
                st_result = _ST_MODULE_4(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */

                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE4));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 5:

              /* For global check: this TS is not called*/
              st_p_Result[st_test_id - 1] = PASSED;

          break;

          case 6:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_6 expecting normal signature*/
                st_result = _ST_MODULE_6(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE6);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_6 expecting inverted signature*/
                st_result = _ST_MODULE_6(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */

                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE6));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 7:

    #if REGISTER_BANK_TEST

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_7 expecting normal signature*/
                st_result = _ST_MODULE_7(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE7);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_7 expecting inverted signature*/
                st_result = _ST_MODULE_7(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE7));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
    #else
          /* For global check: this TS is not called*/
          st_p_Result[st_test_id - 1] = PASSED;
    #endif

          break;

          case 8:

              /* For global check: this TS is not called*/
              st_p_Result[st_test_id - 1] = PASSED;

          break;

          case 9:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_9 expecting normal signature*/
                st_result = _ST_MODULE_9(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE9);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_9 expecting inverted signature*/
                st_result = _ST_MODULE_9(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE9));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 10:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_10 expecting normal signature*/
                st_result = _ST_MODULE_10(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE10);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_10 expecting inverted signature*/
                st_result = _ST_MODULE_10(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE10));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 11:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_11 expecting normal signature*/
                st_result = _ST_MODULE_11(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE11);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_11 expecting inverted signature*/
                st_result = _ST_MODULE_11(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE11));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 12:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_12 expecting normal signature*/
                st_result = _ST_MODULE_12(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE12);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_12 expecting inverted signature*/
                st_result = _ST_MODULE_12(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE12));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 13:

              /* For global check: this TS is not called */
              st_p_Result[st_test_id - 1] = PASSED;

          break;

          case 14:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_14 expecting normal signature*/
                st_result = _ST_MODULE_14(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE14);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_14 expecting inverted signature*/
                st_result = _ST_MODULE_14(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE14));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 15:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_15 expecting normal signature*/
                st_result = _ST_MODULE_15(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE15);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_15 expecting inverted signature*/
                st_result = _ST_MODULE_15(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE15));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 16:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_16 expecting normal signature*/
                st_result = _ST_MODULE_16(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE16);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_16 expecting inverted signature*/
                st_result = _ST_MODULE_16(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE16));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 17:

    #if MPU_TEST

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_17 expecting normal signature*/
                st_result = _ST_MODULE_17(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE17);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_17 expecting inverted signature*/
                st_result = _ST_MODULE_17(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE17));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
    #else
          /* For global check: this TS is not called*/
          st_p_Result[st_test_id - 1] = PASSED;
    #endif

          break;

          case 18:

    #if RAM_TEST

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_18 expecting normal signature*/
                st_result = _ST_MODULE_18(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE18);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_18 expecting inverted signature*/
                st_result = _ST_MODULE_18(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE18));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
    #else
          /* For global check: this TS is not called*/
          st_p_Result[st_test_id - 1] = PASSED;
    #endif

          break;

          case 19:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_19 expecting normal signature*/
                st_result = _ST_MODULE_19(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE19);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_19 expecting inverted signature*/
                st_result = _ST_MODULE_19(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE19));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 20:

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_20 expecting normal signature*/
                st_result = _ST_MODULE_20(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE20);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_20 expecting inverted signature*/
                st_result = _ST_MODULE_20(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE20));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }

          break;

          case 21:

    #if SPECIAL_REGISTER_BANK_TEST

             /* Checks if an error must be simulated. */
             #if TEST_ID_ERROR
                /* Simulate st_test_id error. */
                st_test_id = st_test_id + 1;
             #endif

             /* Signature must not be modified. Set with a different value if the signature must be modified. */
             Swg3k_ModSignature = MOD_SIGNATURE_VALUE;

             if (st_norm_val == 0){
                /* Call of the ST_MODULE_21 expecting normal signature*/
                st_result = _ST_MODULE_21(0, Swg3k_TestRam, st_test_id) ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)SIGNATURE21);
             }
             else if (st_norm_val == 1){
                /* Call of the ST_MODULE_21 expecting inverted signature*/
                st_result = _ST_MODULE_21(1, Swg3k_TestRam, st_test_id) ; /* reversed sequence: inverted signature in low order word */
                /* Check of the NOT Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_NotResult, st_p_Signature, st_p_NotSignature, st_resl, (sint32)(~SIGNATURE21));
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
    #else
          /* For global check: this TS is not called*/
          st_p_Result[st_test_id - 1] = PASSED;
    #endif

          break;

          default:
             /* Do nothing, FAILED value already set */
             break;
       }
    }
    else{
       /* st_test_id error, clear the st_result stucture */
       for(st_i = 0; st_i < 21; st_i++){
            /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
            /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
            st_p_Result[st_i] = FAILED;
            st_p_NotResult[st_i] = ~(st_p_Result[st_i]);
        }
    }
}

/* else part of #if (CORE_G3K == CORTST_SWCST) */
#else

void CheckSignature (sint32 test_id,
                     sint32 *p_Result,
                     sint32 *p_Signature,
                     volatile sint32 *resl ,
                     sint32  gold_sig);

/* 0024057 sw_cst & sw_g3k_subset prototypes for MISRA compliance */
void sw_cst (sint32 st_test_id,
             sint32 st_norm_val,
             sint32 *st_p_Result,
             sint32 *st_p_Signature);

void sw_cst_subset(
             sint32  sb_test_id,
             sint32  sb_norm_val,
             sint32 *sb_p_Result,
             sint32 *sb_p_Signature);

/*******************************************************************************
** Function that, for the selected test module(st_test_id),calls the          **
** single test assembler procedure, calculates the normal (if norm_val=0) or  **
** inverted(if norm_val=1) signature and store the results values in          **
** memory addresses passed as param.                                          **
**                                                                            **
*******************************************************************************/

void sw_cst (sint32 st_test_id,
             sint32 st_norm_val,
             sint32 *st_p_Result,
             sint32 *st_p_Signature)
{
        sint8 st_i;
   static volatile sint64 st_result;
   /* MISRA VIOLATION TAG: 11.4.4 */
   volatile sint32 *st_resl = (volatile sint32 *) &st_result;

   /* passed st_test_id is used as human readable (starts from one) */
   /* intended usage is as index, subtract 1 */
   st_test_id = st_test_id - 1;

   /* 0024478 */
   if ( (0 <= st_test_id) && (st_test_id < CORTST_NUM_TEST_AVAILABLE) )
   {
       /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
       /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
       st_p_Result[st_test_id] = FAILED;

       /* select the test id to perform. */
       switch (st_test_id)
       {
          case 0:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_arithmetic_1 expecting normal signature */
                st_result = CST_CPU_arithmetic_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_ARITHMETIC_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 1:

             if (st_norm_val == 0){
                 /* Call of the CST_CPU_arithmetic_2 expecting normal signature*/
                 st_result = CST_CPU_arithmetic_2() ;
                 /* Check of the Signature and write of results in memory*/
                 CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_ARITHMETIC_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 2:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_arithmetic_3 expecting normal signature*/
                st_result = CST_CPU_arithmetic_3() ; /* normal sequence: inverted signature in high order word */
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_ARITHMETIC_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }

          break;

          case 3:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_arithmetic_4 expecting normal signature*/
                st_result = CST_CPU_arithmetic_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_ARITHMETIC_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 4:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_bit_1 expecting normal signature*/
                st_result = CST_CPU_bit_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BIT_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 5:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_bit_2 expecting normal signature*/
                st_result = CST_CPU_bit_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BIT_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 6:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_bitinsert_1 expecting normal signature*/
                st_result = CST_CPU_bitinsert_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BITINSERT_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }

          break;

          case 7:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_bitsearch_1 expecting normal signature*/
                st_result = CST_CPU_bitsearch_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BITSEARCH_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }

          break;

          case 8:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_boolean_1 expecting normal signature*/
                st_result = CST_CPU_boolean_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BOOLEAN_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 9:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_branch_1 expecting normal signature*/
                st_result = CST_CPU_branch_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_BRANCH_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 10:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_cond_br_1 expecting normal signature*/
                st_result = CST_CPU_cond_br_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_COND_BR_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 11:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_cond_data_1 expecting normal signature*/
                st_result = CST_CPU_cond_data_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_COND_DATA_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 12:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_cond_data_2 expecting normal signature*/
                st_result = CST_CPU_cond_data_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_COND_DATA_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 13:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_cond_data_3 expecting normal signature*/
                st_result = CST_CPU_cond_data_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_COND_DATA_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 14:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_condition_1 expecting normal signature*/
                st_result = CST_CPU_condition_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_CONDITION_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 15:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_condition_2 expecting normal signature*/
                st_result = CST_CPU_condition_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_CONDITION_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 16:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_data_1 expecting normal signature*/
                st_result = CST_CPU_data_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_DATA_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 17:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_data_2 expecting normal signature*/
                st_result = CST_CPU_data_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_DATA_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 18:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_div_1 expecting normal signature*/
                st_result = CST_CPU_div_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_DIV_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 19:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_div_2 expecting normal signature*/
                st_result = CST_CPU_div_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_DIV_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 20:

             if (st_norm_val == 0){
                /* Call of the  CST_CPU_hsdiv_1 expecting normal signature*/
                st_result = CST_CPU_hsdiv_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_HSDIV_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 21:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_ifu_1 expecting normal signature*/
                st_result = CST_CPU_ifu_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_IFU_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 22:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_ipu_1 expecting normal signature*/
                st_result = CST_CPU_ipu_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_IPU_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 23:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_jump_1 expecting normal signature*/
                st_result = CST_CPU_jump_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_JUMP_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 24:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_load_1 expecting normal signature*/
                st_result = CST_CPU_load_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LOAD_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 25:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_load_2 expecting normal signature*/
                st_result = CST_CPU_load_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LOAD_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 26:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_loadlink_1 expecting normal signature*/
                st_result = CST_CPU_loadlink_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LOADLINK_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 27:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_loadstore_1 expecting normal signature*/
                st_result = CST_CPU_loadstore_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LOADSTORE_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 28:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_loop_1 expecting normal signature*/
                st_result = CST_CPU_loop_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LOOP_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 29:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_lsu_1 expecting normal signature*/
                st_result = CST_CPU_lsu_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LSU_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 30:

             if (st_norm_val == 0){
                /* Call of the  CST_CPU_lsu_2 expecting normal signature*/
                st_result =CST_CPU_lsu_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_LSU_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 31:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_mac_1 expecting normal signature*/
                st_result = CST_CPU_mac_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MAC_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 32:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_memory_1 RAM expecting normal signature*/
                st_result = CST_CPU_memory_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MEMORY_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 33:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_memory_2 expecting normal signature*/
                st_result = CST_CPU_memory_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MEMORY_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 34:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_mul_1 expecting normal signature*/
                st_result = CST_CPU_mul_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MUL_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 35:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_mul_2 expecting normal signature*/
                st_result = CST_CPU_mul_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MUL_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 36:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_mul_3 expecting normal signature*/
                st_result = CST_CPU_mul_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MUL_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 37:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_mul_4 expecting normal signature*/
                st_result = CST_CPU_mul_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_MUL_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 38:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_saturated_1 expecting normal signature*/
                st_result = CST_CPU_saturated_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SATURATED_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 39:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_saturated_2 expecting normal signature*/
                st_result = CST_CPU_saturated_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SATURATED_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 40:

             if (st_norm_val == 0){
                /* Call of the  CST_CPU_saturated_3 expecting normal signature*/
                st_result =  CST_CPU_saturated_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SATURATED_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 41:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_saturated_4 expecting normal signature*/
                st_result = CST_CPU_saturated_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SATURATED_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 42:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_shift_1 expecting normal signature*/
                st_result = CST_CPU_shift_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SHIFT_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 43:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_shift_2 expecting normal signature*/
                st_result = CST_CPU_shift_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SHIFT_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 44:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_shift_3 expecting normal signature*/
                st_result = CST_CPU_shift_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SHIFT_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 45:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_shift_4 expecting normal signature*/
                st_result = CST_CPU_shift_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SHIFT_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 46:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_1 expecting normal signature*/
                st_result = CST_CPU_special_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 47:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_2 expecting normal signature*/
                st_result = CST_CPU_special_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 48:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_3 expecting normal signature*/
                st_result = CST_CPU_special_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 49:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_4 expecting normal signature*/
                st_result = CST_CPU_special_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 50:

             if (st_norm_val == 0){
                /* Call of the  CST_CPU_special_5 expecting normal signature*/
                st_result =  CST_CPU_special_5() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_5);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 51:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_6 expecting normal signature*/
                st_result = CST_CPU_special_6() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_6);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 52:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_special_7 expecting normal signature*/
                st_result = CST_CPU_special_7() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SPECIAL_7);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 53:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_store_1 expecting normal signature*/
                st_result = CST_CPU_store_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_STORE_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 54:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_store_2 expecting normal signature*/
                st_result = CST_CPU_store_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_STORE_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 55:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_syscall_1 expecting normal signature*/
                st_result = CST_CPU_syscall_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_SYSCALL_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 56:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_trap_1 expecting normal signature*/
                st_result = CST_CPU_trap_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_TRAP_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 57:

             if (st_norm_val == 0){
                /* Call of the CST_CPU_trap_2 expecting normal signature*/
                st_result = CST_CPU_trap_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_CPU_TRAP_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 58:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_calc_1 expecting normal signature*/
                st_result = CST_FPU_calc_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 59:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_calc_2 expecting normal signature*/
                st_result = CST_FPU_calc_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 60:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the  CST_FPU_calc_3 expecting normal signature*/
                st_result =  CST_FPU_calc_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;


          case 61:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_FPU_calc_4 expecting normal signature*/
                st_result = CST_FPU_calc_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 62:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_calc_5 expecting normal signature*/
                st_result = CST_FPU_calc_5() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_5);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 63:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_FPU_calc_6 expecting normal signature*/
                st_result = CST_FPU_calc_6() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CALC_6);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;


          case 64:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_cmov_1 expecting normal signature*/
                st_result = CST_FPU_cmov_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CMOV_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 65:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_FPU_cmov_2 expecting normal signature*/
                st_result = CST_FPU_cmov_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CMOV_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 66:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_cmp_1 expecting normal signature*/
                st_result = CST_FPU_cmp_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CMP_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 67:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_FPU_cmp_2 expecting normal signature*/
                st_result = CST_FPU_cmp_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CMP_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 68:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_cvt_1 expecting normal signature*/
                st_result = CST_FPU_cvt_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CVT_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 69:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_cvt_2 expecting normal signature*/
                st_result = CST_FPU_cvt_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CVT_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 70:

             if (st_norm_val == 0){
                /* Call of the  CST_FPU_cvt_3 expecting normal signature*/
                st_result =  CST_FPU_cvt_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_CVT_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 71:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_fmul_1 expecting normal signature*/
                st_result = CST_FPU_fmul_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_FMUL_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 72:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_fmul_2 expecting normal signature*/
                st_result = CST_FPU_fmul_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_FMUL_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 73:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_fmul_3 expecting normal signature*/
                st_result = CST_FPU_fmul_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_FMUL_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 74:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_fmul_4 expecting normal signature*/
                st_result = CST_FPU_fmul_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_FMUL_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 75:

             if (st_norm_val == 0){
                /* Call of the CST_FPU_roundoff_1 expecting normal signature*/
                st_result = CST_FPU_roundoff_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_ROUNDOFF_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 76:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_FPU_roundoff_2 expecting normal signature*/
                st_result = CST_FPU_roundoff_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_ROUNDOFF_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 77:

            if (st_norm_val == 0) {
              /* Call of the CST_FPU_roundoff_3 expecting normal signature*/
              st_result = CST_FPU_roundoff_3();
              /* Check of the Signature and write of results in memory*/
              CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_FPU_ROUNDOFF_3);
            }
            else {
              /* Do nothing, FAILED value already set */
              break;
            }
            break;
          case 78:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_exc_1 expecting normal signature*/
                st_result = CST_SRU_exc_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_EXC_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 79:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_fpu_1 expecting normal signature*/
                st_result = CST_SRU_fpu_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_FPU_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 80:
#if CST_FPU_SUPPORT_DOUBLE
             if (st_norm_val == 0){
                /* Call of the CST_SRU_fpu_2 expecting normal signature*/
                st_result = CST_SRU_fpu_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_FPU_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 81:

             if (st_norm_val == 0){
                /* Call of the  CST_SRU_loadstore_1 expecting normal signature*/
                st_result =  CST_SRU_loadstore_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 82:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_2 expecting normal signature*/
                st_result = CST_SRU_loadstore_2() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_2);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 83:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_3 expecting normal signature*/
                st_result = CST_SRU_loadstore_3() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_3);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 84:
#if CST_INST_CACHE_SUPPORT
             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_4 expecting normal signature*/
                st_result = CST_SRU_loadstore_4() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_4);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;


          case 85:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_5 expecting normal signature*/
                st_result = CST_SRU_loadstore_5() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_5);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 86:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_6 expecting normal signature*/
                st_result = CST_SRU_loadstore_6() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_6);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          case 87:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_7 expecting normal signature*/
                st_result = CST_SRU_loadstore_7() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_7);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;


          case 88:
#if CST_DBUF_OPE_REG_SUPPORT
             if (st_norm_val == 0){
                /* Call of the CST_SRU_loadstore_8 expecting normal signature*/
                st_result = CST_SRU_loadstore_8() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_LOADSTORE_8);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
#endif
          break;

          case 89:

             if (st_norm_val == 0){
                /* Call of the CST_SRU_mpu_1 expecting normal signature*/
                st_result = CST_SRU_mpu_1() ;
                /* Check of the Signature and write of results in memory*/
                CheckSignature(st_test_id, st_p_Result, st_p_Signature, st_resl, (sint32)CST_RESULT_SRU_MPU_1);
             }
             else{
                /* Do nothing, FAILED value already set */
                break;
             }
          break;

          default:
             /* Do nothing, FAILED value already set */
             break;
       }
    }
    else
    {
       /* st_test_id error, clear the st_result stucture */
       for(st_i = 0; st_i < CORTST_NUM_TEST_AVAILABLE; st_i++)
       {
            /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
            /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
            st_p_Result[st_i] = FAILED;
       }
    }
}
#endif