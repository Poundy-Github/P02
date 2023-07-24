/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_IFC4_IFC_FD2.c
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
#include "E2EPW_Marshal_SG_IFC4_IFC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_IFC4_IFC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_IFC4_IFC_FD2
    ( P2CONST (SG_IFC4_IFC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal CameraBlockageSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CameraBlockageSts);
    ppa[3]  = src[0] & 0x01;

    /* packing signal ELKMainState */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ELKMainState);
    ppa[2]  = (src[0] << 5) & 0xe0;

    /* packing signal IFC_Handsoffwarn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFC_Handsoffwarn);
    ppa[3] |= (src[0] << 3) & 0x38;

    /* packing signal IFCCalibrationSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IFCCalibrationSts);
    ppa[3] |= (src[0] << 1) & 0x06;

    /* packing signal LaneAvailability */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LaneAvailability);
    ppa[2] |= (src[0] << 3) & 0x18;

    /* packing signal LDW_LKAWarn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LDW_LKAWarn);
    ppa[1]  = (src[0] << 6) & 0xc0;

    /* packing signal LSSErrSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LSSErrSts);
    ppa[2] |= (src[0] >> 2) & 0x01;
    ppa[3] |= (src[0] << 6) & 0xc0;

    /* packing signal LSSFuncSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LSSFuncSts);
    ppa[1] |= src[0] & 0x07;

    /* packing signal LSSIntervention */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LSSIntervention);
    ppa[1] |= (src[0] << 3) & 0x38;

    /* packing signal TJA_FollowSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TJA_FollowSts);
    ppa[2] |= (src[0] << 1) & 0x06;

    /* packing signal AESintervention */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AESintervention);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 6) & 0xc0;

    /* packing signal ESSintervention */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESSintervention);
    ppa[7] |= (src[0] << 4) & 0x30;

    /* packing signal dummy_IFC_FD2_13 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_13);
    ppa[4]  = src[0] & 0x03;

    /* packing signal dummy_IFC_FD2_14 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_14);
    ppa[5]  = src[0];

    /* packing signal dummy_IFC_FD2_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_IFC_FD2_15);
    ppa[6]  = src[0];

    /* packing signal ELKActSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ELKActSts);
    ppa[4] |= (src[0] << 6) & 0xc0;

    /* packing signal IntelligentEvaActSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IntelligentEvaActSts);
    ppa[4] |= (src[0] << 4) & 0x30;

    /* packing signal LCKStsIndcr */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->LCKStsIndcr);
    ppa[4] |= (src[0] << 2) & 0x0c;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
