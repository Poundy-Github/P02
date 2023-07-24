/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ESP2_ESP_FD2.c
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
#include "E2EPW_Marshal_SG_ESP2_ESP_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ESP2_ESP_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ESP2_ESP_FD2
    ( P2CONST (SG_ESP2_ESP_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ABAActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ABAActv_0x137);
    ppa[2]  = (src[0] << 7) & 0x80;

    /* packing signal ABAavailable_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ABAavailable_0x137);
    ppa[2] |= (src[0] << 6) & 0x40;

    /* packing signal ABPActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ABPActv_0x137);
    ppa[2] |= (src[0] << 5) & 0x20;

    /* packing signal ABPAvailable_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ABPAvailable_0x137);
    ppa[2] |= (src[0] << 4) & 0x10;

    /* packing signal AEBAvailable_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AEBAvailable_0x137);
    ppa[2] |= (src[0] << 3) & 0x08;

    /* packing signal AEBBAActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AEBBAActv_0x137);
    ppa[2] |= (src[0] << 2) & 0x04;

    /* packing signal AEBIBActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AEBIBActv_0x137);
    ppa[2] |= (src[0] << 1) & 0x02;

    /* packing signal AVHErrSts_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AVHErrSts_0x137);
    ppa[4]  = (src[0] << 2) & 0x0c;

    /* packing signal AVHSts_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AVHSts_0x137);
    ppa[4] |= (src[0] << 4) & 0x30;

    /* packing signal AWBActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AWBActv_0x137);
    ppa[3]  = (src[0] << 7) & 0x80;

    /* packing signal AWBAvailable_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AWBAvailable_0x137);
    ppa[3] |= (src[0] << 6) & 0x40;

    /* packing signal BrkDskOvrheatd_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->BrkDskOvrheatd_0x137);
    ppa[1]  = (src[0] << 3) & 0x08;

    /* packing signal CDDActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CDDActv_0x137);
    ppa[3] |= (src[0] << 4) & 0x10;

    /* packing signal CDDAvailable_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CDDAvailable_0x137);
    ppa[3] |= (src[0] << 5) & 0x20;

    /* packing signal CDPActv_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CDPActv_0x137);
    ppa[4] |= (src[0] << 7) & 0x80;

    /* packing signal dummy_ESP_FD2_8 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_8);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal dummy_ESP_FD2_9 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_9);
    ppa[1] |= src[0] & 0x07;

    /* packing signal dummy_ESP_FD2_10 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_10);
    ppa[2] |= src[0] & 0x01;

    /* packing signal dummy_ESP_FD2_11 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_11);
    ppa[4] |= (src[0] << 6) & 0x40;

    /* packing signal dummy_ESP_FD2_12 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_12);
    ppa[4] |= src[0] & 0x03;

    /* packing signal dummy_ESP_FD2_13 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_13);
    ppa[5]  = src[0];

    /* packing signal dummy_ESP_FD2_14 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_14);
    ppa[6]  = src[0];

    /* packing signal dummy_ESP_FD2_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ESP_FD2_15);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal HDCCtrl_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HDCCtrl_0x137);
    ppa[3] |= (src[0] << 2) & 0x0c;

    /* packing signal HDCFault_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HDCFault_0x137);
    ppa[3] |= src[0] & 0x03;

    /* packing signal NoBrkForce_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->NoBrkForce_0x137);
    ppa[1] |= (src[0] << 4) & 0x10;

    /* packing signal VehStandstill_0x137 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->VehStandstill_0x137);
    ppa[1] |= (src[0] << 5) & 0x60;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
