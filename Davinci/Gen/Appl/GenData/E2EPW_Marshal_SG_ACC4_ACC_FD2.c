/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ACC4_ACC_FD2.c
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
#include "E2EPW_Marshal_SG_ACC4_ACC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ACC4_ACC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ACC4_ACC_FD2
    ( P2CONST (SG_ACC4_ACC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ACC_FctSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_FctSts);
    ppa[2]  = (src[0] << 1) & 0x06;

    /* packing signal ACC_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_InterSysInfoDisp);
    ppa[1]  = (src[0] << 1) & 0x3e;

    /* packing signal ACC_ModDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_ModDisp);
    ppa[2] |= (src[0] << 3) & 0xf8;

    /* packing signal ACC_ObjDetecte */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_ObjDetecte);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal ACC_SpdSetValue */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_SpdSetValue);
    ppa[6]  = src[0];

    /* packing signal ACC_TakeOverReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_TakeOverReq);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal ACC_TgtObjBarDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_TgtObjBarDisp);
    ppa[3]  = (src[0] << 5) & 0xe0;

    /* packing signal ACC_TimeGapSet */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ACC_TimeGapSet);
    ppa[5]  = src[0] & 0x07;

    /* packing signal ISL_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ISL_InterSysInfoDisp);
    ppa[5] |= (src[0] << 3) & 0x18;

    /* packing signal TJA_ACC_SelSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TJA_ACC_SelSts);
    ppa[3] |= src[0] & 0x07;

    /* packing signal TJA_ICA_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TJA_ICA_InterSysInfoDisp);
    ppa[4]  = (src[0] << 1) & 0x0e;

    /* packing signal TJA_ICA_ModDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TJA_ICA_ModDisp);
    ppa[5] |= (src[0] << 5) & 0xe0;

    /* packing signal CruCha_ModDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CruCha_ModDisp);
    ppa[4] |= (src[0] << 4) & 0xf0;

    /* packing signal CruChar_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CruChar_InterSysInfoDisp);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal Longctrl_HazActv */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_HazActv);
    ppa[3] |= (src[0] << 3) & 0x18;

    /* packing signal dummy_ACC_FD2_8 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_8);
    ppa[1] |= src[0] & 0x01;

    /* packing signal dummy_ACC_FD2_9 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_9);
    ppa[2] |= src[0] & 0x01;

    /* packing signal dummy_ACC_FD2_10 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_10);
    ppa[4] |= src[0] & 0x01;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
