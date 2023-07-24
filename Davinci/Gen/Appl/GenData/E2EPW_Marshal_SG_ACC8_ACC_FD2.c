/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ACC8_ACC_FD2.c
 ** Tue, 02-Mar-2021, 15:16:57
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
#include "E2EPW_Marshal_SG_ACC8_ACC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ACC8_ACC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ACC8_ACC_FD2
    ( P2CONST (SG_ACC8_ACC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ADAS_DriverInloop_Monitor */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ADAS_DriverInloop_Monitor);
    ppa[2]  = (src[0] << 1) & 0x0e;

    /* packing signal HWA_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_InterSysInfoDisp);
    ppa[1]  = src[0] & 0x0f;

    /* packing signal HWA_LaneChange */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_LaneChange);
    ppa[2] |= (src[0] << 4) & 0x30;

    /* packing signal HWA_LaneChangeReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_LaneChangeReq);
    ppa[3]  = (src[0] << 5) & 0xe0;

    /* packing signal HWA_ModDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_ModDisp);
    ppa[1] |= (src[0] << 4) & 0xf0;

    /* packing signal HWA_warning */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_warning);
    ppa[3] |= src[0] & 0x03;

    /* packing signal Longctrl_HCUTrqReq_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_HCUTrqReq_DVR);
    ppa[4]  = src[1];
    ppa[5]  = src[0];

    /* packing signal dummy_ACC_FD2_11 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_11);
    ppa[2] |= (src[0] << 6) & 0xc0;

    /* packing signal dummy_ACC_FD2_12 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_12);
    ppa[2] |= src[0] & 0x01;

    /* packing signal dummy_ACC_FD2_13 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_13);
    ppa[3] |= (src[0] << 2) & 0x1c;

    /* packing signal dummy_ACC_FD2_14 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_14);
    ppa[6]  = src[0];

    /* packing signal dummy_ACC_FD2_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_15);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
