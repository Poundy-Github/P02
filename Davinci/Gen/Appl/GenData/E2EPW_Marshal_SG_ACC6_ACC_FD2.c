/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ACC6_ACC_FD2.c
 ** Tue, 02-Mar-2021, 15:16:58
 **/

/******************************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a file
 *   should only be preceded by other preprocessor directives or
 *   comments.
 * Justification : Inclusion of MemMap.h is AUTOSAR specific.
 ******************************************************************/
/* PRQA S 5087 EOF */
/******************************************************************
 * MISRA RULE 11.4 VIOLATION:
 * Error Message : Msg(4:0310) Casting to different object pointer
 *   type.
 * Justification : Marshal code works on direct byte access for
 *   different application types.
 ******************************************************************/
/* PRQA S 0310 EOF */
/******************************************************************
 * MISRA RULE 10.1 VIOLATION:
 * Error Message : Msg(4:3757) Implicit conversion: int to unsigned
 *   char.
 * Justification : Marshal code generator ensures no loss of data
 *   during endianness conversion.
 ******************************************************************/
/* PRQA S 3757 EOF */

#include "Rte_Common_GateWay.h"
#include "E2EPW_Marshal_SG_ACC6_ACC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ACC6_ACC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ACC6_ACC_FD2
    ( P2CONST (SG_ACC6_ACC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ACC_EgoStatus */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_EgoStatus);
    ppa[3]  = (src[0] << 3) & 0x18;

    /* packing signal ACC_PotentialTgtDetn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_PotentialTgtDetn);
    ppa[6]  = (src[0] << 4) & 0x30;

    /* packing signal ACC_PotentialTgtDx */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_PotentialTgtDx);
    ppa[2]  = (src[1] << 7) & 0x80;
    ppa[2] |= (src[0] >> 1) & 0x7f;
    ppa[3] |= (src[0] << 7) & 0x80;

    /* packing signal ACC_PotentialTgtDy */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_PotentialTgtDy);
    ppa[1]  = src[0];

    /* packing signal ACC_PotentialTgtTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_PotentialTgtTyp);
    ppa[6] |= (src[0] << 1) & 0x0e;

    /* packing signal ACC_RlvTgtDetn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_RlvTgtDetn);
    ppa[3] |= (src[0] << 5) & 0x60;

    /* packing signal ACC_RlvTgtDx */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_RlvTgtDx);
    ppa[5]  = (src[1] << 7) & 0x80;
    ppa[5] |= (src[0] >> 1) & 0x7f;
    ppa[6] |= (src[0] << 7) & 0x80;

    /* packing signal ACC_RlvTgtDy */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_RlvTgtDy);
    ppa[4]  = src[0];

    /* packing signal ACC_RlvTgtTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_RlvTgtTyp);
    ppa[3] |= src[0] & 0x07;

    /* packing signal dummy_ACC_FD2_16 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_16);
    ppa[6] |= (src[0] << 6) & 0x40;

    /* packing signal dummy_ACC_FD2_17 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_17);
    ppa[6] |= src[0] & 0x01;

    /* packing signal dummy_ACC_FD2_18 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_18);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
