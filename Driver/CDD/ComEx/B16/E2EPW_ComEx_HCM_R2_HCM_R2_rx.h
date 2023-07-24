/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_ComEx_HCM_R2_HCM_R2_rx.h
 ** Tue, 01-Mar-2022, 18:31:10
 **/

#ifndef E2EPW_ComEx_HCM_R2_HCM_R2_RX_H
#define E2EPW_ComEx_HCM_R2_HCM_R2_RX_H
#include "ComEx_Type.h"
#include "E2E_P01.h"

#define ComEx_START_SEC_CODE
#include "ComEx_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_HCM_R2_E2E_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, ComEx_CODE) E2EPW_ReadInit_HCM_R2_E2E (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_HCM_R2_E2E ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , ComEx_VAR_NOINIT
             , ComEx_CODE
             )
    E2EPW_Get_CheckState_HCM_R2_E2E (void);

/**********************************************************
 * Function name: E2EPW_Read_HCM_R2_E2E (ComEx_E2ETYPE * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, ComEx_CODE) E2EPW_Read_HCM_R2_E2E
    ( P2VAR (ComEx_E2ETYPE, AUTOMATIC, ComEx_VAR_INIT) AppData);

#define ComEx_STOP_SEC_CODE
#include "ComEx_MemMap.h"

#endif
/*  << EOF >>  */
