/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_tx.c
 ** Tue, 02-Mar-2021, 15:16:57
 **/

/**********************************************************
 * MISRA RULE 14.1 VIOLATION:
 * Error Message : Msg(4:1503) The function '<name>' is
 *   defined but is not used within this project.
 * Justification : Library functions
 **********************************************************/
/* PRQA S 1503 EOF */
/**********************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a
 *   file should only be preceded by other preprocessor
 *   directives or comments.
 * Justification : Inclusion of MemMap file is AUTOSAR
 *   specific
 **********************************************************/
/* PRQA S 5087 EOF */
#include "Rte_Common_GateWay.h"
#include "E2EPW_Marshal_SG_HUT_IP2.h"
#include "E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_tx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define Common_GateWay_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_GateWay_MemMap.h"

STATIC VAR (E2E_P01ProtectStateType, Common_GateWay_VAR_INIT)
    StateVal_SG_HUT_IP2_SG_HUT_IP2 =
{
    0  /* Counter */
};

STATIC P2VAR ( E2E_P01ProtectStateType
             , Common_GateWay_VAR_INIT
             , Common_GateWay_VAR_INIT
             )
    State_SG_HUT_IP2_SG_HUT_IP2 =
        &StateVal_SG_HUT_IP2_SG_HUT_IP2;

#define Common_GateWay_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_GateWay_MemMap.h"

#define Common_GateWay_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_GateWay_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, Common_GateWay_VAR_NOINIT)
    ppa_SG_HUT_IP2_SG_HUT_IP2_au8 [8];

#define Common_GateWay_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_GateWay_MemMap.h"

#define Common_GateWay_START_SEC_CONST_UNSPECIFIED
#include "Common_GateWay_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, Common_GateWay_CONST)
    ConfigVal_SG_HUT_IP2_SG_HUT_IP2 =
{
      56
    , 0
    , 226
    , 12
    , E2E_P01_DATAID_BOTH
    , 64
    , 2
    , 14
    , 1
};

#define Common_GateWay_STOP_SEC_CONST_UNSPECIFIED
#include "Common_GateWay_MemMap.h"

#define Common_GateWay_START_SEC_CODE
#include "Common_GateWay_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_SG_HUT_IP2_SG_HUT_IP2_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
FUNC (void, Common_GateWay_CODE) E2EPW_WriteInit_SG_HUT_IP2_SG_HUT_IP2 (void)
{
    State_SG_HUT_IP2_SG_HUT_IP2 = &StateVal_SG_HUT_IP2_SG_HUT_IP2;
    State_SG_HUT_IP2_SG_HUT_IP2->Counter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SG_HUT_IP2_SG_HUT_IP2 ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01ProtectStateType
           , Common_GateWay_VAR_NOINIT
           , Common_GateWay_CODE
           )
    E2EPW_Get_ProtectState_SG_HUT_IP2_SG_HUT_IP2 (void)
{
    return State_SG_HUT_IP2_SG_HUT_IP2;
}

/**********************************************************
 * Function name: E2EPW_Write_SG_HUT_IP2_SG_HUT_IP2 (SG_HUT_IP2 *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, Common_GateWay_CODE) E2EPW_Write_SG_HUT_IP2_SG_HUT_IP2
    (P2VAR (SG_HUT_IP2, AUTOMATIC, Common_GateWay_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
          (0       <<24)  /* unused */
        | (E2E_E_OK<<16)  /* Protection Wrapper */
        | (RTE_E_OK<<8)   /* Rte_Write */
        | (E2E_E_OK);     /* E2E_..Protect */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, Common_GateWay_CONST)
        Config_SG_HUT_IP2_SG_HUT_IP2 = &ConfigVal_SG_HUT_IP2_SG_HUT_IP2;

    if (AppData == NULL_PTR)
    {
        ret_u8 = E2E_E_INPUTERR_NULL;
        status_u32 &= 0xFF00FFFFU;
        status_u32 |= (((uint32)ret_u8)<<16);
    }

    if (status_u32 == status_ok_u32)
    {
        E2EPW_Marshal_SG_HUT_IP2 ( AppData, ppa_SG_HUT_IP2_SG_HUT_IP2_au8 );
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Protect
                     ( Config_SG_HUT_IP2_SG_HUT_IP2
                     , State_SG_HUT_IP2_SG_HUT_IP2
                     , ppa_SG_HUT_IP2_SG_HUT_IP2_au8
                     );
        status_u32 &= 0xFFFFFF00U;
        status_u32 |= (ret_u8);
    }

    if (status_u32 == status_ok_u32)
    {
        uint16 crcoffset_u16 = Config_SG_HUT_IP2_SG_HUT_IP2->CRCOffset/8;
        uint16 cntoffset_u16 = Config_SG_HUT_IP2_SG_HUT_IP2->CounterOffset/8;
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
        AppData->CheckSum_IP2 = ppa_SG_HUT_IP2_SG_HUT_IP2_au8[crcoffset_u16];
        AppData->RollingCounter_IP2 = (ppa_SG_HUT_IP2_SG_HUT_IP2_au8[cntoffset_u16] & 0x0F);
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = Rte_Write_SG_HUT_IP2_SG_HUT_IP2 ( AppData );
        status_u32 &= 0xFFFF00FFU;
        status_u32 |= (((uint32)ret_u8)<<8);
    }

    return status_u32;
}

#define Common_GateWay_STOP_SEC_CODE
#include "Common_GateWay_MemMap.h"
/*  << EOF >>  */
