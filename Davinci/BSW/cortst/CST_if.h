/*-----------------------------------------------------------------------------*/
/* Project      = G3KH SW CST                                                  */
/* Module       = CST_if.h                                                     */
/* Version      = 1.2.4                                                        */
/* Date         = 10-11-2017                                                   */
/*-----------------------------------------------------------------------------*/
/*                                  COPYRIGHT                                  */
/*-----------------------------------------------------------------------------*/
/* Copyright (c) 2014-2017 by Renesas Electronics Corporation                  */
/*-----------------------------------------------------------------------------*/
/* Purpose:                                                                    */
/*   RH850G3KH CORE SELF TEST                                                  */
/*   infterface definitions                                                    */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* Unless otherwise agreed upon in writing between your company and            */
/* Renesas Electronics Corporation the following shall apply!                  */
/*                                                                             */
/* Warranty Disclaimer                                                         */
/*                                                                             */
/* There is no warranty of any kind whatsoever granted by Renesas. Any         */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed  */
/* or implied, including but not limited to those for non-infringement of      */
/* intellectual property, merchantability and/or fitness for the particular    */
/* purpose.                                                                    */
/*                                                                             */
/* Renesas shall not have any obligation to maintain, service or provide bug   */
/* fixes for the supplied Product(s) and/or the Application.                   */
/*                                                                             */
/* Each User is solely responsible for determining the appropriateness of      */
/* using the Product(s) and assumes all risks associated with its exercise     */
/* of rights under this Agreement, including, but not limited to the risks     */
/* and costs of program errors, compliance with applicable laws, damage to     */
/* or loss of data, programs or equipment, and unavailability or               */
/* interruption of operations.                                                 */
/*                                                                             */
/* Limitation of Liability                                                     */
/*                                                                             */
/* In no event shall Renesas be liable to the User for any incidental,         */
/* consequential, indirect, or punitive damage (including but not limited      */
/* to lost profits) regardless of whether such liability is based on breach    */
/* of contract, tort, strict liability, breach of warranties, failure of       */
/* essential purpose or otherwise and even if advised of the possibility of    */
/* such damages. Renesas shall not be liable for any services or products      */
/* provided by third party vendors, developers or consultants identified or    */
/* referred to the User by Renesas in connection with the Product(s) and/or    */
/* the Application.                                                            */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/* Environment:                                                                */
/*              Devices:  G3KH                                                 */
/*              Language: Green Hills Software, Compiler v2015.1.7             */
/*-----------------------------------------------------------------------------*/

#ifndef CST_IF_H
#define CST_IF_H

#include        "CST_cfg.h"

/*--------------------------------------------------------------------------*/
/*  Expected value                           [ Function ID : CST_FN_174 ]   */
/*--------------------------------------------------------------------------*/
    #define CST_RESULT_CPU_LOAD_1           0x78766A52
    #define CST_RESULT_CPU_LOAD_2           0xFFFFFFE4
    #define CST_RESULT_CPU_STORE_1          0xFFFBF800
    #define CST_RESULT_CPU_STORE_2          0xFFFFFFF2
    #define CST_RESULT_CPU_MUL_1            0x8D97D514
    #define CST_RESULT_CPU_MUL_2            0x7AE4E592
    #define CST_RESULT_CPU_MUL_3            0x1838B0DB
    #define CST_RESULT_CPU_MUL_4            0xE6F62CF4
    #define CST_RESULT_CPU_MAC_1            0x895EBECA
    #define CST_RESULT_CPU_ARITHMETIC_1     0x00000014
    #define CST_RESULT_CPU_ARITHMETIC_2     0x00000026
    #define CST_RESULT_CPU_ARITHMETIC_3     0x55555573
    #define CST_RESULT_CPU_ARITHMETIC_4     0x5FFF6021
    #define CST_RESULT_CPU_CONDITION_1      0x55555560
    #define CST_RESULT_CPU_CONDITION_2      0x55555563
    #define CST_RESULT_CPU_SATURATED_1      0x00000034
    #define CST_RESULT_CPU_SATURATED_2      0x80000051
    #define CST_RESULT_CPU_SATURATED_3      0x00000063
    #define CST_RESULT_CPU_SATURATED_4      0x000000C9
    #define CST_RESULT_CPU_BOOLEAN_1        0x5557D78F
    #define CST_RESULT_CPU_COND_DATA_1      0x5FF63128
    #define CST_RESULT_CPU_COND_DATA_2      0x0000000A
    #define CST_RESULT_CPU_COND_DATA_3      0x00000002
    #define CST_RESULT_CPU_BITINSERT_1      0x01DFFFE4
    #define CST_RESULT_CPU_DATA_1           0x00FE0323
    #define CST_RESULT_CPU_DATA_2           0x000103F8
    #define CST_RESULT_CPU_SHIFT_1          0x02BE84EA
    #define CST_RESULT_CPU_SHIFT_2          0x3DA9EFAC
    #define CST_RESULT_CPU_SHIFT_3          0x8B3E84C6
    #define CST_RESULT_CPU_SHIFT_4          0x00000037
    #define CST_RESULT_CPU_BITSEARCH_1      0x00000864
    #define CST_RESULT_CPU_DIV_1            0xDAA5C349
    #define CST_RESULT_CPU_DIV_2            0xA5629A70
    #define CST_RESULT_CPU_HSDIV_1          0xAE6AD058
    #define CST_RESULT_CPU_COND_BR_1        0x00000010
    #define CST_RESULT_CPU_BIT_1            0x0000031D
    #define CST_RESULT_CPU_BIT_2            0x000007B8
    #define CST_RESULT_CPU_LOOP_1           0x00000018
    #define CST_RESULT_CPU_SPECIAL_1        0x9E9CCCE8
    #define CST_RESULT_CPU_SPECIAL_2        0x00070007
    #define CST_RESULT_CPU_SPECIAL_3        0xFFFFFFFC
    #define CST_RESULT_CPU_SPECIAL_4        0xFFFFFFF5
    #define CST_RESULT_CPU_SPECIAL_5        0x00000003
    #define CST_RESULT_CPU_SPECIAL_6        0x12103423
    #define CST_RESULT_CPU_BRANCH_1         0xFFFFFFFD
    #define CST_RESULT_CPU_LOADLINK_1       0x00000038
    #define CST_RESULT_CPU_JUMP_1           0x00000007
    #define CST_RESULT_CPU_SYSCALL_1        0x40028064
    #define CST_RESULT_CPU_TRAP_1           0x00030150
    #define CST_RESULT_CPU_TRAP_2           0x000400F1
    #define CST_RESULT_CPU_MEMORY_1         0xFFFFFFFF
    #define CST_RESULT_CPU_MEMORY_2         0xFFFFFFFA
    #define CST_RESULT_CPU_IPU_1            0xB3413285
    #define CST_RESULT_CPU_LSU_1            0x107084D8
    #define CST_RESULT_CPU_LSU_2            0xBB23B176
    #define CST_RESULT_CPU_IFU_1            0x00000020
    #define CST_RESULT_FPU_CALC_1           0x788948B8
    #define CST_RESULT_FPU_CALC_2           0x4349D619
    #define CST_RESULT_FPU_CALC_5           0x7414AF7D
    #define CST_RESULT_FPU_CMOV_1           0x01671115
    #define CST_RESULT_FPU_CMP_1            0x00000330
    #define CST_RESULT_FPU_CVT_1            0xBCC05B18
    #define CST_RESULT_FPU_CVT_2            0x52FD5B66
    #define CST_RESULT_FPU_CVT_3            0x7FB69FC2
    #define CST_RESULT_FPU_ROUNDOFF_1       0x81F14D9A
    #define CST_RESULT_FPU_FMUL_1           0xE8A49B63
    #define CST_RESULT_FPU_FMUL_2           0xEF0BBF5B
    #define CST_RESULT_FPU_FMUL_3           0xE582F616
    #define CST_RESULT_FPU_FMUL_4           0xE666DEA1
    #define CST_RESULT_SRU_FPU_1            0xFAAAAAAA
    #define CST_RESULT_SRU_MPU_1            0x000003F0
    #define CST_RESULT_SRU_EXC_1            0x00000005
    #define CST_RESULT_CPU_LOADSTORE_1      0x5FFF25C1
    #define CST_RESULT_CPU_SPECIAL_7        0x56543CBA
    #define CST_RESULT_SRU_LOADSTORE_1      0xFFEFC3E1
    #define CST_RESULT_SRU_LOADSTORE_2      0x050302BF
    #define CST_RESULT_SRU_LOADSTORE_3      0xFFE07B3E
    #define CST_RESULT_SRU_LOADSTORE_5      0x0000FED3
    #define CST_RESULT_SRU_LOADSTORE_6      0x07FE01FE
    #define CST_RESULT_SRU_LOADSTORE_7      0x07FE01FE
    #define CST_RESULT_FPU_ROUNDOFF_3       0x80A5C469
/*  [ Covers : CST_DD_014 ]                                                 */

/*--------------------------------------------------------------------------*/
/*  Build Switch (Device Depend)             [ Function ID : CST_FN_175 ]   */
/*--------------------------------------------------------------------------*/
    #define CST_MA_HW_OPERATION       1     /* Missalign Access (1:HW operates normally) */
    #define CST_MPU_TWELVE_CHANNELS   0     /* MPU channel number (0:16ch) */
    #define CST_FPU_SUPPORT_DOUBLE    0     /* FPU support precision (0:Single) */
    #define CST_INST_CACHE_SUPPORT    0     /* Instruction cache support (0:Not support) */
    #define CST_DBUF_OPE_REG_SUPPORT  0     /* Data buffer operation function register support (0:Not support) */
    #define CST_SPID_BIT_WIDTH_FIVE   0     /* SPID bit width (0:Not 5bits) */
    #define CST_ROUNDF_SINGLE_SUPPORT 1     /* Single ROUNDF instructions support (1:Support) */
/*  [ Covers : CST_DD_325 ] [ Covers : CST_DD_326 ] [ Covers : CST_DD_327 ] */
/*  [ Covers : CST_DD_328 ] [ Covers : CST_DD_329 ] [ Covers : CST_DD_333 ] */
/*  [ Covers : CST_DD_334 ]                                                 */

#endif /* CST_IF_H */

/* ============================================================================ */
/* =====        E n d   o f   F i l e   :   CST_if.h                      ===== */
/* ============================================================================ */
