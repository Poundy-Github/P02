/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3_rx.c
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
/**********************************************************
 * MISRA VIOLATION: 'Metrics VOCF<=4' VIOLATION:
 * Code-structure based on by AUTOSAR 'Spec.of EndtoEnd
 * Communication Protection', R3.2.1 V1.2.0./
 * and '893.061.D_End-to-End Kommunikationsabsicherung_v1.5'
 **********************************************************/
#include "Rte_SocDtcProcess.h"
#include "E2EPW_Marshal_SG_ABS3.h"
#include "E2EPW_CheckDeserial_SG_ABS3.h"
#include "E2EPW_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3_rx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define SocDtcProcess_START_SEC_VAR_INIT_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"

STATIC VAR (E2E_P01CheckStateType, SocDtcProcess_VAR_INIT)
    StateVal_rpSR_SG_ABS3_SG_ABS3 =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
    , 0                        /* SyncCounter */
    , 0                        /* NoNewOrRepeatedCounter */
};

STATIC P2VAR ( E2E_P01CheckStateType
             , SocDtcProcess_VAR_INIT
             , SocDtcProcess_VAR_INIT
             )
    State_rpSR_SG_ABS3_SG_ABS3 =
        &StateVal_rpSR_SG_ABS3_SG_ABS3;

#define SocDtcProcess_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"

#define SocDtcProcess_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, SocDtcProcess_VAR_NOINIT)
    ppa_rpSR_SG_ABS3_SG_ABS3_au8 [8];

#define SocDtcProcess_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"

#define SocDtcProcess_START_SEC_CONST_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, SocDtcProcess_CONST)
    ConfigVal_rpSR_SG_ABS3_SG_ABS3 =
{
      56
    , 0
    , 40
    , 12
    , E2E_P01_DATAID_BOTH
    , 64
    , 2
    , 14
    , 1
};

#define SocDtcProcess_STOP_SEC_CONST_UNSPECIFIED
#include "SocDtcProcess_MemMap.h"

#define SocDtcProcess_START_SEC_CODE
#include "SocDtcProcess_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_rpSR_SG_ABS3_SG_ABS3_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
FUNC (void, SocDtcProcess_CODE) E2EPW_ReadInit_rpSR_SG_ABS3_SG_ABS3 (void)
{
    State_rpSR_SG_ABS3_SG_ABS3 = &StateVal_rpSR_SG_ABS3_SG_ABS3;
    State_rpSR_SG_ABS3_SG_ABS3->LastValidCounter = 0;
    State_rpSR_SG_ABS3_SG_ABS3->MaxDeltaCounter  = 0;
    State_rpSR_SG_ABS3_SG_ABS3->WaitForFirstData = TRUE;
    State_rpSR_SG_ABS3_SG_ABS3->NewDataAvailable = FALSE;
    State_rpSR_SG_ABS3_SG_ABS3->LostData         = 0;
    State_rpSR_SG_ABS3_SG_ABS3->Status           = E2E_P01STATUS_NONEWDATA;
    State_rpSR_SG_ABS3_SG_ABS3->SyncCounter      = 0;
    State_rpSR_SG_ABS3_SG_ABS3->NoNewOrRepeatedDataCounter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_rpSR_SG_ABS3_SG_ABS3 ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01CheckStateType
           , SocDtcProcess_VAR_NOINIT
           , SocDtcProcess_CODE
           )
    E2EPW_Get_CheckState_rpSR_SG_ABS3_SG_ABS3 (void)
{
    return State_rpSR_SG_ABS3_SG_ABS3;
}

/**********************************************************
 * Function name: E2EPW_Read_rpSR_SG_ABS3_SG_ABS3 (SG_ABS3 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, SocDtcProcess_CODE) E2EPW_Read_rpSR_SG_ABS3_SG_ABS3
    ( P2VAR (SG_ABS3, AUTOMATIC, SocDtcProcess_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;
    VAR (uint8, AUTOMATIC) ret_rte_u8 = RTE_E_OK;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
           (0<<31)                         /* Deserial-Check */
        |  ((E2E_P01STATUS_OK & 0x7F)<<24) /* ReceiverStatus */
        |  (E2E_E_OK<<16)                  /* Protection Wrapper */
        |  (RTE_E_OK<<8)                   /* Rte_Read */
        |  (E2E_E_OK);                     /* E2E_...Check */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, SocDtcProcess_CONST)
        Config_rpSR_SG_ABS3_SG_ABS3 = &ConfigVal_rpSR_SG_ABS3_SG_ABS3;

    State_rpSR_SG_ABS3_SG_ABS3->NewDataAvailable =
        Rte_IsUpdated_rpSR_SG_ABS3_SG_ABS3 ();

    if ((State_rpSR_SG_ABS3_SG_ABS3->NewDataAvailable != FALSE))
    {
        if (AppData == NULL_PTR)
        {
            ret_u8 = E2E_E_INPUTERR_NULL;
            status_u32 &= 0xFF00FFFFU;
            status_u32 |= (((uint32)ret_u8)<<16);
        }

        if (status_u32 == status_ok_u32)
        {
            /* Return-value of Rte_Read does not affect
               following workflow.
            */
            ret_rte_u8 = Rte_Read_rpSR_SG_ABS3_SG_ABS3 (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_SG_ABS3 (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_rpSR_SG_ABS3_SG_ABS3->CRCOffset >> 3u;
            uint16 cntoffset_u16 = Config_rpSR_SG_ABS3_SG_ABS3->CounterOffset >> 3u;
            E2EPW_Marshal_SG_ABS3 ( AppData, ppa_rpSR_SG_ABS3_SG_ABS3_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
            ppa_rpSR_SG_ABS3_SG_ABS3_au8[crcoffset_u16]  = AppData->CheckSum_ABS3_0x265;
            ppa_rpSR_SG_ABS3_SG_ABS3_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_rpSR_SG_ABS3_SG_ABS3_au8[cntoffset_u16] |= AppData->RollingCounter_ABS3_0x265;
        }
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_rpSR_SG_ABS3_SG_ABS3
                     , State_rpSR_SG_ABS3_SG_ABS3
                     , ppa_rpSR_SG_ABS3_SG_ABS3_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_rpSR_SG_ABS3_SG_ABS3->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define SocDtcProcess_STOP_SEC_CODE
#include "SocDtcProcess_MemMap.h"
/*  << EOF >>  */
