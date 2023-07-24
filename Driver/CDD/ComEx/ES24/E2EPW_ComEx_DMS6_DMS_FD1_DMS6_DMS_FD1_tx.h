/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_ComEx_DMS6_DMS_FD1_DMS6_DMS_FD1_tx.h
 ** Mon, 21-Feb-2022, 11:34:35
 **/

#ifndef E2EPW_ComEx_DMS6_DMS_FD1_DMS6_DMS_FD1_TX_H
#define E2EPW_ComEx_DMS6_DMS_FD1_DMS6_DMS_FD1_TX_H

#include "ComEx_Type.h"
#include "E2E_P01.h"

#define ComEx_START_SEC_CODE
#include "ComEx_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_DMS6_DMS_FD1_E2E_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, ComEx_CODE) E2EPW_WriteInit_DMS6_DMS_FD1_E2E (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_DMS6_DMS_FD1_E2E ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01ProtectStateType
                  , ComEx_VAR_NOINIT
                  , ComEx_CODE
                  )
    E2EPW_Get_ProtectState_DMS6_DMS_FD1_E2E (void);

/**********************************************************
 * Function name: E2EPW_Write_DMS6_DMS_FD1_E2E (ComEx_E2ETYPE *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, ComEx_CODE) E2EPW_Write_DMS6_DMS_FD1_E2E
    (P2VAR (ComEx_E2ETYPE, AUTOMATIC, ComEx_VAR_INIT) AppData);

#define ComEx_STOP_SEC_CODE
#include "ComEx_MemMap.h"

#endif
/*  << EOF >>  */
