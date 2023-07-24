/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_ACC3_ACC_FD2.c
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
#include "E2EPW_Marshal_SG_ACC3_ACC_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_ACC3_ACC_FD2
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_ACC3_ACC_FD2
    ( P2CONST (SG_ACC3_ACC_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ALC_InterSysInfoDisp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ALC_InterSysInfoDisp);
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 6) & 0xc0;

    /* packing signal ALC_Resp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ALC_Resp);
    ppa[1]  = (src[0] << 1) & 0x02;

    /* packing signal HWA_Resp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_Resp);
    ppa[1] |= (src[0] << 5) & 0x20;

    /* packing signal HWA_SnvtySet_Resp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->HWA_SnvtySet_Resp);
    ppa[1] |= (src[0] << 3) & 0x18;

    /* packing signal ICA_HandsOffResp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ICA_HandsOffResp);
    ppa[1] |= (src[0] << 6) & 0x40;

    /* packing signal ISL_Resp */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ISL_Resp);
    ppa[1] |= (src[0] << 7) & 0x80;

    /* packing signal Longctrl_Decel_Req_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_Decel_Req_DVR);
    ppa[2]  = (src[0] << 1) & 0x02;

    /* packing signal Longctrl_Decel_ReqValue_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_Decel_ReqValue_DVR);
    ppa[5]  = src[0];

    /* packing signal Longctrl_DecelToStopReq_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_DecelToStopReq_DVR);
    ppa[6]  = (src[0] << 7) & 0x80;

    /* packing signal Longctrl_DrvOFF_Req_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_DrvOFF_Req_DVR);
    ppa[2] |= (src[0] << 6) & 0x40;

    /* packing signal Longctrl_EngTrqReq_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_EngTrqReq_DVR);
    ppa[3]  = src[1];
    ppa[4]  = src[0];

    /* packing signal Longctrl_EngTrqReqActive_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_EngTrqReqActive_DVR);
    ppa[2] |= src[0] & 0x01;

    /* packing signal Longctrl_HCUTrqReqActive_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_HCUTrqReqActive_DVR);
    ppa[6] |= (src[0] << 4) & 0x10;

    /* packing signal Longctrl_ModSts_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_ModSts_DVR);
    ppa[2] |= (src[0] << 2) & 0x3c;

    /* packing signal Longctrl_ParkShiftReq_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_ParkShiftReq_DVR);
    ppa[6] |= (src[0] << 5) & 0x60;

    /* packing signal Longctrl_VehHldReq_DVR */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Longctrl_VehHldReq_DVR);
    ppa[2] |= (src[0] << 7) & 0x80;

    /* packing signal dummy_ACC_FD2_4 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_4);
    ppa[1] |= (src[0] << 2) & 0x04;

    /* packing signal dummy_ACC_FD2_5 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_5);
    ppa[1] |= src[0] & 0x01;

    /* packing signal dummy_ACC_FD2_6 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_6);
    ppa[6] |= src[0] & 0x0f;

    /* packing signal dummy_ACC_FD2_7 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->dummy_ACC_FD2_7);
    ppa[7] |= (src[0] << 4) & 0x30;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
