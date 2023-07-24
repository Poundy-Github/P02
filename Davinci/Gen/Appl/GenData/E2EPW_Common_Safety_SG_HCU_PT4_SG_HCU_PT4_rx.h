/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Common_Safety_SG_HCU_PT4_SG_HCU_PT4_rx.h
 ** Tue, 02-Mar-2021, 15:16:58
 **/

#ifndef E2EPW_Common_Safety_SG_HCU_PT4_SG_HCU_PT4_RX_H
#define E2EPW_Common_Safety_SG_HCU_PT4_SG_HCU_PT4_RX_H
#include "Rte_Type.h"
#include "E2E_P01.h"

#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_SG_HCU_PT4_SG_HCU_PT4_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, Common_Safety_CODE) E2EPW_ReadInit_SG_HCU_PT4_SG_HCU_PT4 (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SG_HCU_PT4_SG_HCU_PT4 ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , Common_Safety_VAR_NOINIT
             , Common_Safety_CODE
             )
    E2EPW_Get_CheckState_SG_HCU_PT4_SG_HCU_PT4 (void);

/**********************************************************
 * Function name: E2EPW_Read_SG_HCU_PT4_SG_HCU_PT4 (SG_HCU_PT4 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, Common_Safety_CODE) E2EPW_Read_SG_HCU_PT4_SG_HCU_PT4
    ( P2VAR (SG_HCU_PT4, AUTOMATIC, Common_Safety_VAR_INIT) AppData);

#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

#endif
/*  << EOF >>  */
