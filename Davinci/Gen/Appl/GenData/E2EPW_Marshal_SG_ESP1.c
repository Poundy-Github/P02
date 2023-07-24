/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ESP1.c
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

#include "Rte_Common_Safety.h"
#include "E2EPW_Marshal_SG_ESP1.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ESP1
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ESP1
    ( P2CONST (SG_ESP1, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal BTCActv_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->BTCActv_0x149);
    ppa[2]  = (src[0] << 7) & 0x80;

    /* packing signal dummy_ESP1_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP1_0);
    ppa[1]  = src[0] & 0x0f;

    /* packing signal dummy_ESP1_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP1_1);
    ppa[2] |= (src[0] << 1) & 0x0e;

    /* packing signal dummy_ESP1_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP1_2);
    ppa[5]  = src[0];

    /* packing signal dummy_ESP1_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP1_3);
    ppa[6]  = src[0];

    /* packing signal dummy_ESP1_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP1_4);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal ESP_MasterCylBrkPress_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESP_MasterCylBrkPress_0x149);
    ppa[3]  = src[1];
    ppa[4]  = src[0];

    /* packing signal ESP_MasterCylBrkPressVld_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESP_MasterCylBrkPressVld_0x149);
    ppa[2] |= src[0] & 0x01;

    /* packing signal ESPActvInfoLmp_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESPActvInfoLmp_0x149);
    ppa[1] |= (src[0] << 5) & 0x20;

    /* packing signal ESPBrkLmpCtrl_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESPBrkLmpCtrl_0x149);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal ESPFailSts_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESPFailSts_0x149);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal ESPFuncOffSts_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ESPFuncOffSts_0x149);
    ppa[1] |= (src[0] << 4) & 0x10;

    /* packing signal MSRActv_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->MSRActv_0x149);
    ppa[2] |= (src[0] << 5) & 0x20;

    /* packing signal PTCActv_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->PTCActv_0x149);
    ppa[2] |= (src[0] << 6) & 0x40;

    /* packing signal VDCActv_0x149 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->VDCActv_0x149);
    ppa[2] |= (src[0] << 4) & 0x10;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
