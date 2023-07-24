/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_IFC5_IFC_FD2.c
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

#include "Rte_Common_Normal.h"
#include "E2EPW_Marshal_SG_IFC5_IFC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_IFC5_IFC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_IFC5_IFC_FD2
    ( P2CONST (SG_IFC5_IFC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal IFC_LaneCurve */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_LaneCurve);
    ppa[1]  = (src[1] << 4) & 0xf0;
    ppa[1] |= (src[0] >> 4) & 0x0f;
    ppa[2]  = (src[0] << 4) & 0xf0;

    /* packing signal IFC_LeLane_dy */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_LeLane_dy);
    ppa[4]  = (src[1] << 4) & 0xf0;
    ppa[4] |= (src[0] >> 4) & 0x0f;
    ppa[5]  = (src[0] << 4) & 0xf0;

    /* packing signal IFC_LeLaneTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_LeLaneTyp);
    ppa[2] |= (src[0] << 1) & 0x0e;

    /* packing signal IFC_NextLeLaneTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_NextLeLaneTyp);
    ppa[3]  = (src[0] << 3) & 0x38;

    /* packing signal IFC_NextRiLaneTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_NextRiLaneTyp);
    ppa[3] |= src[0] & 0x07;

    /* packing signal IFC_RiLane_dy */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_RiLane_dy);
    ppa[5] |= src[1] & 0x0f;
    ppa[6]  = src[0];

    /* packing signal IFC_RiLaneTyp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_RiLaneTyp);
    ppa[2] |= (src[0] >> 2) & 0x01;
    ppa[3] |= (src[0] << 6) & 0xc0;

    /* packing signal dummy_IFC_FD2_16 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_16);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
