/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_HCU_HP5.c
 ** Tue, 02-Mar-2021, 15:16:59
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
#include "E2EPW_Marshal_SG_HCU_HP5.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_HCU_HP5
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_HCU_HP5
    ( P2CONST (SG_HCU_HP5, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal DrvFaiMsg_0x201 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvFaiMsg_0x201);
    ppa[5]  = src[0] & 0x0f;

    /* packing signal DrvGearDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvGearDisp);
    ppa[4]  = src[0] & 0x07;

    /* packing signal DrvGearDispSts_0x201 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvGearDispSts_0x201);
    ppa[5] |= (src[0] << 6) & 0xc0;

    /* packing signal DrvModDisp_0x201 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvModDisp_0x201);
    ppa[4] |= (src[0] << 5) & 0xe0;

    /* packing signal DrvModDispSts_0x201 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DrvModDispSts_0x201);
    ppa[4] |= (src[0] << 3) & 0x18;

    /* packing signal dummy_HCU_HP5_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_HP5_0);
    ppa[1]  = src[0] & 0x03;

    /* packing signal dummy_HCU_HP5_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_HP5_1);
    ppa[2]  = src[0] & 0x3f;

    /* packing signal dummy_HCU_HP5_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_HP5_2);
    ppa[3]  = src[0];

    /* packing signal dummy_HCU_HP5_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_HP5_3);
    ppa[6]  = src[0];

    /* packing signal dummy_HCU_HP5_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_HP5_4);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal HCU_EnrgFlowInd_DHT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_EnrgFlowInd_DHT);
    ppa[1] |= (src[0] << 2) & 0xfc;

    /* packing signal HCU_PrsBrkWarn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_PrsBrkWarn);
    ppa[2] |= (src[0] << 6) & 0xc0;

    /* packing signal HCU_ShftNotAlwd_Warn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_ShftNotAlwd_Warn);
    ppa[5] |= (src[0] << 4) & 0x30;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
