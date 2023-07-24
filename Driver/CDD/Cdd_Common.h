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
/**
 **********************************************************************************************************************
 * @file:      Cdd_Common.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %head of header file guard%
 */
#ifndef __CDD_COMMON_H
#define __CDD_COMMON_H

/*
 *  %header file in this project/library%
 */
#include "Platform_Types.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
/* Critical type related to caller context */
typedef uint8 CriticalType_t;

/* interrupt service routine type I */
#define CRITICAL_TYPE_ISR_I     0U
/* interrupt service routine type II */
#define CRITICAL_TYPE_ISR_II    1U
/* task type */
#define CRITICAL_TYPE_TASK      2U
/*number of critical type */
#define CRITICAL_TYPE_NUMBER    3U

/* Write protected macro definition */
#define _WRITE_PROTECT_COMMAND              (0x000000A5UL)  /* Write protected */
#define protected_write(reg_p, status_p, reg, value)    \
    do{                                                 \
        (reg_p) = 0xa5u;                                \
        (reg) = (value);                                \
        (reg) =~ (value);                               \
        (reg) = (value);                                \
    }while((status_p) == 1u)

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define ARRAY_OFFSET(arr, member) (((uint32_t)(member) - (uint32_t)(arr))/sizeof((arr)[0]))

#define __IO volatile

#define BIT(value, start) ((value) << (start))
#define BIT_SET(value, start) ((value) | BIT(1u, start))
#define BIT_CLR(value, start) ((value) & (~ BIT(1u, start)))
#define BIT_GET(value, start) (((value) >> (start)) & 1u)

#define BIT_SET_SELF(value, start) ((value) = BIT_SET(value, start))
#define BIT_CLR_SELF(value, start) ((value) = BIT_CLR(value, start))

#define BITS_LIMIT(value, len) ((value) & (BIT(1u, len) - 1u))
#define BITS(value, start, len) (BITS_LIMIT(value, len) << (start))
#define BITS_CLR(value, start, len) ((value) & (~ BITS(value, start, len)))
#define BITS_SET(value, start, len, n)                                                  \
    (BITS_CLR(value, start, len) | BITS(n, start, len))                                 \

#define BITS_GET(value, start, len) (BITS_LIMIT(((value) >> (start)), len))

#define BITS_SET_SELF(value, start, len, n) ((value) = BITS_SET(value, start, len, n))


#define REG_BIT_SET(value, start) BIT_SET_SELF(value, start)
#define REG_BIT_CLR(value, start) BIT_CLR_SELF(value, start)

#define REG_BITS_SET(value, start, len, tgt, temp)              \
    (temp) = (tgt);                                             \
    BITS_SET_SELF(start, len, value, temp)                      \
    (tgt) = (temp)                                              \


#ifndef BITDEF
#define BITDEF
#define BIT0		0x01u
#define BIT1		0x02u
#define BIT2		0x04u
#define BIT3		0x08u
#define BIT4		0x10u
#define BIT5		0x20u
#define BIT6		0x40u
#define BIT7		0x80u
#define BIT8		0x0100u
#define BIT9		0x0200u
#define BIT10	0x0400u
#define BIT11	0x0800u
#define BIT12	0x1000u
#define BIT13	0x2000u
#define BIT14	0x4000u
#define BIT15	0x8000u

#define BIT16       0x00010000u
#define BIT17       0x00020000u
#define BIT18       0x00040000u
#define BIT19       0x00080000u
#define BIT20       0x00100000u
#define BIT21       0x00200000u
#define BIT22       0x00400000u
#define BIT23       0x00800000u
#define BIT24       0x01000000u
#define BIT25       0x02000000u
#define BIT26       0x04000000u
#define BIT27       0x08000000u
#define BIT28       0x10000000u
#define BIT29       0x20000000u
#define BIT30       0x40000000u
#define BIT31       0x80000000u
#endif

/*
 *  %function declaration%
 */



/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif
