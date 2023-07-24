/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_IFC3_IFC_FD2.c
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

#include "Rte_Common_Normal.h"
#include "E2EPW_Marshal_SG_IFC3_IFC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_IFC3_IFC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_IFC3_IFC_FD2
    ( P2CONST (SG_IFC3_IFC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal AESErrSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AESErrSts);
    ppa[3]  = (src[0] << 5) & 0x20;

    /* packing signal AESResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AESResp);
    ppa[1]  = (src[0] << 3) & 0x08;

    /* packing signal AESSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AESSts);
    ppa[2]  = src[0] & 0x03;

    /* packing signal ELKResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ELKResp);
    ppa[1] |= (src[0] << 4) & 0x10;

    /* packing signal ESS_Pedresp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESS_Pedresp);
    ppa[2] |= (src[0] << 7) & 0x80;

    /* packing signal ESS_Vehresp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESS_Vehresp);
    ppa[2] |= (src[0] << 6) & 0x40;

    /* packing signal ESSErrSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESSErrSts);
    ppa[3] |= (src[0] << 4) & 0x10;

    /* packing signal ESSSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESSSts);
    ppa[3] |= (src[0] << 6) & 0xc0;

    /* packing signal IFCHUTInterface */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFCHUTInterface);
    ppa[1] |= src[0] & 0x01;

    /* packing signal IntelligentEvaResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IntelligentEvaResp);
    ppa[2] |= (src[0] << 2) & 0x04;

    /* packing signal LCKResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LCKResp);
    ppa[1] |= (src[0] << 5) & 0x20;

    /* packing signal LDW_LKA_Snvty */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LDW_LKA_Snvty);
    ppa[1] |= (src[0] << 1) & 0x06;

    /* packing signal LDWResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LDWResp);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal LKAResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LKAResp);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal LSSResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LSSResp);
    ppa[2] |= (src[0] << 3) & 0x08;

    /* packing signal LSSWarnFormResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LSSWarnFormResp);
    ppa[2] |= (src[0] << 4) & 0x30;

    /* packing signal dummy_IFC_FD2_8 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_8);
    ppa[3] |= src[0] & 0x0f;

    /* packing signal dummy_IFC_FD2_9 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_9);
    ppa[4]  = src[0];

    /* packing signal dummy_IFC_FD2_10 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_10);
    ppa[5]  = src[0];

    /* packing signal dummy_IFC_FD2_11 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_11);
    ppa[6]  = src[0];

    /* packing signal dummy_IFC_FD2_12 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_12);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
