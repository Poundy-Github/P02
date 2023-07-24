/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_DCT7.c
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
#include "E2EPW_Marshal_SG_DCT7.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_DCT7
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_DCT7
    ( P2CONST (SG_DCT7, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal DCT_PrsBrk_Warn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DCT_PrsBrk_Warn);
    ppa[3]  = (src[0] << 6) & 0xc0;

    /* packing signal DCT_RaceModeSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DCT_RaceModeSts);
    ppa[1]  = src[0] & 0x07;

    /* packing signal DCT_ShftNotAlwd_Warn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DCT_ShftNotAlwd_Warn);
    ppa[3] |= (src[0] << 4) & 0x30;

    /* packing signal DCT_ShftRecom_M */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DCT_ShftRecom_M);
    ppa[3] |= (src[0] << 2) & 0x0c;

    /* packing signal DrvAutoGearDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvAutoGearDisp);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal DrvWarnMsg */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvWarnMsg);
    ppa[4]  = (src[0] << 5) & 0xe0;

    /* packing signal DrvFaiMsg_0x235 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvFaiMsg_0x235);
    ppa[4] |= (src[0] << 1) & 0x1e;

    /* packing signal DrvGearDispSts_0x235 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvGearDispSts_0x235);
    ppa[6]  = (src[0] << 6) & 0xc0;

    /* packing signal DrvModDisp_0x235 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvModDisp_0x235);
    ppa[5]  = (src[0] << 5) & 0xe0;

    /* packing signal DrvModDispSts_0x235 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvModDispSts_0x235);
    ppa[5] |= (src[0] << 3) & 0x18;

    /* packing signal dummy_DCT7_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_0);
    ppa[1] |= (src[0] << 3) & 0xf8;

    /* packing signal dummy_DCT7_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_1);
    ppa[2]  = src[0];

    /* packing signal dummy_DCT7_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_2);
    ppa[3] |= src[0] & 0x03;

    /* packing signal dummy_DCT7_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_3);
    ppa[4] |= src[0] & 0x01;

    /* packing signal dummy_DCT7_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_4);
    ppa[5] |= src[0] & 0x07;

    /* packing signal dummy_DCT7_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_DCT7_5);
    ppa[6] |= src[0] & 0x3f;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
