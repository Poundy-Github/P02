/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_HUT32.c
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
#include "E2EPW_Marshal_SG_HUT32.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_HUT32
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_HUT32
    ( P2CONST (SG_HUT32, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ContnPrkgReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ContnPrkgReq);
    ppa[1]  = (src[0] << 6) & 0xc0;

    /* packing signal ContnPrkgReqValid */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ContnPrkgReqValid);
    ppa[1] |= src[0] & 0x01;

    /* packing signal DetVideoLost */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DetVideoLost);
    ppa[1] |= (src[0] << 1) & 0x02;

    /* packing signal PrkgCtrlModReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkgCtrlModReq);
    ppa[1] |= (src[0] << 4) & 0x30;

    /* packing signal PrkgCtrlModReqValid */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkgCtrlModReqValid);
    ppa[1] |= (src[0] << 2) & 0x04;

    /* packing signal PrkStraightContinueReq_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightContinueReq_HUT);
    ppa[6]  = (src[0] << 7) & 0x80;

    /* packing signal PrkStraightModSel_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightModSel_HUT);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 5) & 0xe0;

    /* packing signal PrkStraightStrtReq_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightStrtReq_HUT);
    ppa[5]  = (src[0] << 5) & 0x20;

    /* packing signal PrkStraightSts_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightSts_HUT);
    ppa[7] |= (src[0] << 4) & 0x10;

    /* packing signal PrkStraightSuspendOrFinishReq_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightSuspendOrFinishReq_HUT);
    ppa[3]  = (src[0] << 3) & 0x18;

    /* packing signal PrkStraightSwtReq_HUT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightSwtReq_HUT);
    ppa[1] |= (src[0] << 3) & 0x08;

    /* packing signal PrkStraightVehStrtReq_HUT_Valid */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PrkStraightVehStrtReq_HUT_Valid);
    ppa[5] |= (src[0] << 4) & 0x10;

    /* packing signal ScrnOpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ScrnOpSts);
    ppa[5] |= (src[0] << 6) & 0xc0;

    /* packing signal VolLampDispSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->VolLampDispSts);
    ppa[5] |= src[0] & 0x0f;

    /* packing signal XLvl */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->XLvl);
    ppa[2]  = (src[1] << 5) & 0xe0;
    ppa[2] |= (src[0] >> 3) & 0x1f;
    ppa[3] |= (src[0] << 5) & 0xe0;

    /* packing signal YLvl */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->YLvl);
    ppa[3] |= src[1] & 0x07;
    ppa[4]  = src[0];
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
