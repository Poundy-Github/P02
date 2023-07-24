/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_ComEx_DMS3_DMS_FD1_DMS3_DMS_FD1_tx.c
 ** Wed, 01-Sep-2021, 16:01:39
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
#include "ComEx.h"
#include "E2EPW_Marshal_DMS3_DMS_FD1.h"
#include "E2EPW_ComEx_DMS3_DMS_FD1_DMS3_DMS_FD1_tx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define ComEx_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComEx_MemMap.h"

STATIC VAR (E2E_P01ProtectStateType, ComEx_VAR_INIT)
    StateVal_DMS3_DMS_FD1_E2E =
{
    0  /* Counter */
};

STATIC P2VAR ( E2E_P01ProtectStateType
             , ComEx_VAR_INIT
             , ComEx_VAR_INIT
             )
    State_DMS3_DMS_FD1_E2E =
        &StateVal_DMS3_DMS_FD1_E2E;

#define ComEx_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComEx_MemMap.h"

#define ComEx_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ComEx_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, ComEx_VAR_NOINIT)
    ppa_DMS3_DMS_FD1_E2E_au8 [8];

#define ComEx_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "ComEx_MemMap.h"

#define ComEx_START_SEC_CONST_UNSPECIFIED
#include "ComEx_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, ComEx_CONST)
    ConfigVal_DMS3_DMS_FD1_E2E =
{
      56
    , 0
    , 67
    , 12
    , E2E_P01_DATAID_BOTH
    , 64
    , 2
    , 14
    , 1
};

#define ComEx_STOP_SEC_CONST_UNSPECIFIED
#include "ComEx_MemMap.h"

#define ComEx_START_SEC_CODE
#include "ComEx_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_DMS3_DMS_FD1_E2E_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
FUNC (void, ComEx_CODE) E2EPW_WriteInit_DMS3_DMS_FD1_E2E (void)
{
    State_DMS3_DMS_FD1_E2E = &StateVal_DMS3_DMS_FD1_E2E;
    State_DMS3_DMS_FD1_E2E->Counter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_SenderState_DMS3_DMS_FD1_E2E ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01ProtectStateType
           , ComEx_VAR_NOINIT
           , ComEx_CODE
           )
    E2EPW_Get_ProtectState_DMS3_DMS_FD1_E2E (void)
{
    return State_DMS3_DMS_FD1_E2E;
}

/**********************************************************
 * Function name: E2EPW_Write_DMS3_DMS_FD1_E2E (ComEx_E2ETYPE *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, ComEx_CODE) E2EPW_Write_DMS3_DMS_FD1_E2E
    (P2VAR (ComEx_E2ETYPE, AUTOMATIC, ComEx_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
          (0       <<24)  /* unused */
        | (E2E_E_OK<<16)  /* Protection Wrapper */
        | (RTE_E_OK<<8)   /* Rte_Write */
        | (E2E_E_OK);     /* E2E_..Protect */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, ComEx_CONST)
        Config_DMS3_DMS_FD1_E2E = &ConfigVal_DMS3_DMS_FD1_E2E;

    if (AppData == NULL_PTR)
    {
        ret_u8 = E2E_E_INPUTERR_NULL;
        status_u32 &= 0xFF00FFFFU;
        status_u32 |= (((uint32)ret_u8)<<16);
    }

    if (status_u32 == status_ok_u32)
    {
        E2EPW_Marshal_DMS3_DMS_FD1 ( AppData, ppa_DMS3_DMS_FD1_E2E_au8 );
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Protect
                     ( Config_DMS3_DMS_FD1_E2E
                     , State_DMS3_DMS_FD1_E2E
                     , ppa_DMS3_DMS_FD1_E2E_au8
                     );
        status_u32 &= 0xFFFFFF00U;
        status_u32 |= (ret_u8);
    }

    if (status_u32 == status_ok_u32)
    {
        uint16 crcoffset_u16 = Config_DMS3_DMS_FD1_E2E->CRCOffset/8;
        uint16 cntoffset_u16 = Config_DMS3_DMS_FD1_E2E->CounterOffset/8;
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
        AppData->Checksum = ppa_DMS3_DMS_FD1_E2E_au8[crcoffset_u16];
        AppData->RollingCounter = (ppa_DMS3_DMS_FD1_E2E_au8[cntoffset_u16] & 0x0F);
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = Rte_Write_DMS3_DMS_FD1_E2E ( AppData );
        status_u32 &= 0xFFFF00FFU;
        status_u32 |= (((uint32)ret_u8)<<8);
    }

    return status_u32;
}

#define ComEx_STOP_SEC_CODE
#include "ComEx_MemMap.h"
/*  << EOF >>  */
