/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3_rx.h
 ** Tue, 02-Mar-2021, 15:16:57
 **/

#ifndef E2EPW_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3_RX_H
#define E2EPW_SocDtcProcess_rpSR_SG_ABS3_SG_ABS3_RX_H
#include "Rte_Type.h"
#include "E2E_P01.h"

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
extern FUNC (void, SocDtcProcess_CODE) E2EPW_ReadInit_rpSR_SG_ABS3_SG_ABS3 (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_rpSR_SG_ABS3_SG_ABS3 ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , SocDtcProcess_VAR_NOINIT
             , SocDtcProcess_CODE
             )
    E2EPW_Get_CheckState_rpSR_SG_ABS3_SG_ABS3 (void);

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
extern FUNC (uint32, SocDtcProcess_CODE) E2EPW_Read_rpSR_SG_ABS3_SG_ABS3
    ( P2VAR (SG_ABS3, AUTOMATIC, SocDtcProcess_VAR_INIT) AppData);

#define SocDtcProcess_STOP_SEC_CODE
#include "SocDtcProcess_MemMap.h"

#endif
/*  << EOF >>  */
