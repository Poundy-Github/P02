/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_HCU_PT7.c
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
#include "E2EPW_Marshal_SG_HCU_PT7.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_HCU_PT7
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_HCU_PT7
    ( P2CONST (SG_HCU_PT7, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal dummy_HCU_PT7_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_0);
    ppa[2]  = src[0];

    /* packing signal dummy_HCU_PT7_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_1);
    ppa[3]  = (src[0] << 4) & 0xf0;

    /* packing signal dummy_HCU_PT7_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_2);
    ppa[4]  = (src[0] << 6) & 0x40;

    /* packing signal dummy_HCU_PT7_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_3);
    ppa[4] |= src[0] & 0x0f;

    /* packing signal dummy_HCU_PT7_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_4);
    ppa[5]  = (src[0] << 4) & 0xf0;

    /* packing signal dummy_HCU_PT7_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_5);
    ppa[5] |= src[0] & 0x01;

    /* packing signal dummy_HCU_PT7_6 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT7_6);
    ppa[6]  = src[0] & 0x07;

    /* packing signal HCU_12VSysErr_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_12VSysErr_1);
    ppa[3] |= src[0] & 0x01;

    /* packing signal HCU_12VSysErr_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_12VSysErr_2);
    ppa[4] |= (src[0] << 7) & 0x80;

    /* packing signal HCU_12VSysErrLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_12VSysErrLmpSts);
    ppa[1]  = src[0] & 0x01;

    /* packing signal HCU_EnrgFlowInd */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_EnrgFlowInd);
    ppa[6] |= (src[0] << 3) & 0xf8;

    /* packing signal HCU_HybSysErr_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_1);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal HCU_HybSysErr_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_2);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal HCU_HybSysErr_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_3);
    ppa[1] |= (src[0] << 5) & 0x20;

    /* packing signal HCU_HybSysErr_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_4);
    ppa[1] |= (src[0] << 4) & 0x10;

    /* packing signal HCU_HybSysErr_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_5);
    ppa[1] |= (src[0] << 3) & 0x08;

    /* packing signal HCU_HybSysErr_6 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_6);
    ppa[1] |= (src[0] << 2) & 0x04;

    /* packing signal HCU_HybSysErr_7 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErr_7);
    ppa[1] |= (src[0] << 1) & 0x02;

    /* packing signal HCU_HybSysErrLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_HybSysErrLmpSts);
    ppa[3] |= (src[0] << 2) & 0x0c;

    /* packing signal HCU_ModSwtFail */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_ModSwtFail);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal HCU_OPDLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_OPDLmpSts);
    ppa[4] |= (src[0] << 4) & 0x10;

    /* packing signal HCU_OPDSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_OPDSts);
    ppa[5] |= (src[0] << 1) & 0x0e;

    /* packing signal HCU_PowerRedWarnLmpCmd */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_PowerRedWarnLmpCmd);
    ppa[3] |= (src[0] << 1) & 0x02;

    /* packing signal HCU_RdyLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_RdyLmpSts);
    ppa[4] |= (src[0] << 5) & 0x20;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
