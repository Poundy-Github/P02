/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ABM1.c
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

#include "Rte_Common_Safety.h"
#include "E2EPW_Marshal_SG_ABM1.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ABM1
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ABM1
    ( P2CONST (SG_ABM1, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal AirbFailLmpCmd */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AirbFailLmpCmd);
    ppa[1]  = (src[0] << 5) & 0x20;

    /* packing signal DrvSBR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvSBR);
    ppa[1] |= (src[0] << 3) & 0x08;

    /* packing signal DrvSBR_Visual */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvSBR_Visual);
    ppa[3]  = src[0] & 0x03;

    /* packing signal PassSBR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PassSBR);
    ppa[1] |= (src[0] << 1) & 0x02;

    /* packing signal PassSBR_Visual */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PassSBR_Visual);
    ppa[3] |= (src[0] << 2) & 0x0c;

    /* packing signal SecRowLSBR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowLSBR);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal SecRowLSBR_Visual */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowLSBR_Visual);
    ppa[3] |= (src[0] << 4) & 0x30;

    /* packing signal SecRowMidSBR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowMidSBR);
    ppa[1] |= (src[0] << 4) & 0x10;

    /* packing signal SecRowMidSBR_Visual */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowMidSBR_Visual);
    ppa[3] |= (src[0] << 6) & 0xc0;

    /* packing signal SecRowRSBR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowRSBR);
    ppa[1] |= (src[0] << 2) & 0x04;

    /* packing signal SecRowRSBR_Visual */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->SecRowRSBR_Visual);
    ppa[4]  = src[0] & 0x03;

    /* packing signal CrashOutputSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CrashOutputSts);
    ppa[2]  = src[0];

    /* packing signal dummy_ABM1_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_0);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal dummy_ABM1_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_1);
    ppa[1] |= src[0] & 0x01;

    /* packing signal dummy_ABM1_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_2);
    ppa[4] |= (src[0] << 2) & 0xfc;

    /* packing signal dummy_ABM1_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_3);
    ppa[5]  = src[0];

    /* packing signal dummy_ABM1_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_4);
    ppa[6]  = src[0];

    /* packing signal dummy_ABM1_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ABM1_5);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
