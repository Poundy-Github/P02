/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_HCU_PT4.c
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
#include "E2EPW_Marshal_SG_HCU_PT4.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_HCU_PT4
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_HCU_PT4
    ( P2CONST (SG_HCU_PT4, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal CarWashMode_Sts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CarWashMode_Sts);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 7) & 0x80;

    /* packing signal CarWashMode_StsDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CarWashMode_StsDisp);
    ppa[7] |= (src[0] << 4) & 0x70;

    /* packing signal dummy_HCU_PT4_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_0);
    ppa[1]  = src[0];

    /* packing signal dummy_HCU_PT4_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_1);
    ppa[2]  = (src[0] << 2) & 0x1c;

    /* packing signal dummy_HCU_PT4_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_2);
    ppa[3]  = (src[0] << 2) & 0x04;

    /* packing signal dummy_HCU_PT4_3 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_3);
    ppa[4]  = (src[0] << 6) & 0xc0;

    /* packing signal dummy_HCU_PT4_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_4);
    ppa[4] |= src[0] & 0x07;

    /* packing signal dummy_HCU_PT4_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_5);
    ppa[5]  = src[0] & 0x0f;

    /* packing signal dummy_HCU_PT4_6 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_6);
    ppa[6]  = (src[0] << 3) & 0xf8;

    /* packing signal dummy_HCU_PT4_7 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_HCU_PT4_7);
    ppa[6] |= src[0] & 0x01;

    /* packing signal HCU_ACStsReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_ACStsReq);
    ppa[6] |= (src[0] << 1) & 0x06;

    /* packing signal HCU_BattPowerRedWarn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_BattPowerRedWarn);
    ppa[2] |= src[0] & 0x03;

    /* packing signal HCU_ConnectChrgLine_Indcn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_ConnectChrgLine_Indcn);
    ppa[4] |= (src[0] << 3) & 0x08;

    /* packing signal HCU_EgyRecFB */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_EgyRecFB);
    ppa[5] |= (src[0] << 6) & 0xc0;

    /* packing signal HCU_EnerSavePowerMod */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_EnerSavePowerMod);
    ppa[3] |= (src[0] << 4) & 0x30;

    /* packing signal HCU_InhbChrgInfo */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_InhbChrgInfo);
    ppa[5] |= (src[0] << 4) & 0x10;

    /* packing signal HCU_OilTankCoverSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_OilTankCoverSts);
    ppa[5] |= (src[0] << 5) & 0x20;

    /* packing signal HCU_OPDFail */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_OPDFail);
    ppa[3] |= (src[0] << 6) & 0xc0;

    /* packing signal HCU_RefuReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_RefuReq);
    ppa[2] |= (src[0] << 5) & 0xe0;

    /* packing signal HCU_RemoveChrgLine_Indcn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_RemoveChrgLine_Indcn);
    ppa[3] |= src[0] & 0x01;

    /* packing signal HCU_Shift_P_Indcn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_Shift_P_Indcn);
    ppa[4] |= (src[0] << 4) & 0x10;

    /* packing signal HCU_SOCLow_Indcn */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_SOCLow_Indcn);
    ppa[3] |= (src[0] << 1) & 0x02;

    /* packing signal HCU_WadeModeSetSts */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HCU_WadeModeSetSts);
    ppa[4] |= (src[0] << 5) & 0x20;

    /* packing signal OPDParkWarnReq */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->OPDParkWarnReq);
    ppa[3] |= (src[0] << 3) & 0x08;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
