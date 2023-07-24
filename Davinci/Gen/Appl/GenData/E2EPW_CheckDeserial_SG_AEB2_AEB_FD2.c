/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_CheckDeserial_SG_AEB2_AEB_FD2.c
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

#include "Rte_Common_Safety.h"
#include "E2EPW_CheckDeserial_SG_AEB2_AEB_FD2.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_CheckDeserial_SG_AEB2_AEB_FD2
 * Description        : Checks if the signals in the de-serialized
 *                      protected data element are in a valid
 *                      range, considering their bit length in the
 *                      protected pdu area.
 * Parameter pde (in) : pointer to protected data element
 * Return value       : 0                    deserial check passed
 *                      E2EPW_DESERIAL_ERR   deserial check failed
 * Remarks            : none
 ******************************************************************/
FUNC (uint8, E2EPW_CODE) E2EPW_CheckDeserial_SG_AEB2_AEB_FD2
    ( P2CONST (SG_AEB2_AEB_FD2, AUTOMATIC, E2EPW_APPL_DATA) pde )
{
    VAR (uint8, AUTOMATIC) ret = 0;

    if ((pde->AEB_JA_Resp & 0xfeu) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->AEB_PedResp & 0xfeu) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->AEB_VehResp & 0xfeu) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->FCW_Snvty & 0xfcu) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->RollingCounter_AEB2 & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->dummy_AEB_FD2_8 & 0xf8u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->dummy_AEB_FD2_14 & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    return ret;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
