/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_tx.h
 ** Tue, 02-Mar-2021, 15:16:57
 **/

#ifndef E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_TX_H
#define E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_TX_H

#include "Rte_Type.h"
#include "E2E_P01.h"

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
extern FUNC (void, Common_GateWay_CODE) E2EPW_WriteInit_SG_HUT_IP2_SG_HUT_IP2 (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SG_HUT_IP2_SG_HUT_IP2 ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01ProtectStateType
                  , Common_GateWay_VAR_NOINIT
                  , Common_GateWay_CODE
                  )
    E2EPW_Get_ProtectState_SG_HUT_IP2_SG_HUT_IP2 (void);

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
extern FUNC (uint32, Common_GateWay_CODE) E2EPW_Write_SG_HUT_IP2_SG_HUT_IP2
    (P2VAR (SG_HUT_IP2, AUTOMATIC, Common_GateWay_VAR_INIT) AppData);

#define Common_GateWay_STOP_SEC_CODE
#include "Common_GateWay_MemMap.h"

#endif
/*  << EOF >>  */
