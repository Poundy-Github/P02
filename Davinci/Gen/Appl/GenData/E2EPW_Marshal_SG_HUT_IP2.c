/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_HUT_IP2.c
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
#include "E2EPW_Marshal_SG_HUT_IP2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_HUT_IP2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_HUT_IP2
    ( P2CONST (SG_HUT_IP2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal IP_ABMWarnLmpFailrSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_ABMWarnLmpFailrSts);
    ppa[6]  = (src[0] << 6) & 0xc0;

    /* packing signal IP_ACCErr */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_ACCErr);
    ppa[5]  = (src[0] << 7) & 0x80;

    /* packing signal IP_BattChrgLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_BattChrgLmpSts);
    ppa[5] |= (src[0] << 2) & 0x0c;

    /* packing signal IP_DrvSeatBeltWarnLmpFailSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_DrvSeatBeltWarnLmpFailSts);
    ppa[6] |= (src[0] << 2) & 0x0c;

    /* packing signal IP_EngOilPressLowLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_EngOilPressLowLmpSts);
    ppa[5] |= src[0] & 0x03;

    /* packing signal IP_Err */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_Err);
    ppa[6] |= (src[0] << 4) & 0x10;

    /* packing signal IP_FuelLvlInfo */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_FuelLvlInfo);
    ppa[4]  = src[0];

    /* packing signal IP_FuelLvlLowLmpSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_FuelLvlLowLmpSts);
    ppa[5] |= (src[0] << 4) & 0x30;

    /* packing signal IP_PassSeatBeltWarnLmpFailSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_PassSeatBeltWarnLmpFailSts);
    ppa[6] |= src[0] & 0x03;

    /* packing signal IP_VehSpdUnit */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_VehSpdUnit);
    ppa[6] |= (src[0] << 5) & 0x20;

    /* packing signal IP_VehTotDistance */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_VehTotDistance);
    ppa[1]  = src[2];
    ppa[2]  = src[1];
    ppa[3]  = src[0];

    /* packing signal IP_VehTotDistanceValid */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_VehTotDistanceValid);
    ppa[5] |= (src[0] << 6) & 0x40;

    /* packing signal IP_VINcompr */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->IP_VINcompr);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 7) & 0x80;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
