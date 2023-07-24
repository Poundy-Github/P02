/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  ADAU1978.c
 *           Config:  E:/V3P5_VIP/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  ADAU1978
 *  Generation Time:  2020-12-01 14:50:32
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <ADAU1978>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_ADAU1978.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "ADAU1978.h"
#include "ADAU1978_reg.h"
#include "Misc_Board.h"

typedef enum
{
    ADAU1978_IDLE = 0u,
    ADAU1978_CHECK_BOARD,
    ADAU1978_SET_REG,
    ADAU1978_SET_REG_WAIT,
    ADAU1978_POWERUP,
    ADAU1978_POWERUP_WAIT,
    ADAU1978_CHECK_PLL,
    ADAU1978_CHECK_PLL_WAIT,
    ADAU1978_UNKNOWN
}ADAU1978_STATUS_t;

#define REG_ADDR_MAX    0x1A
#define IIC_RETRY_MAX   10

static uint8 adau_start = 0;
static ADAU1978_STATUS_t adau_status = ADAU1978_IDLE;
static uint8 reg_index = 0;
static uint8 iic_fail_count = 0;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define ADAU1978_START_SEC_CODE
#include "ADAU1978_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ADAU1978_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU1978_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ADAU1978_CODE) ADAU1978_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU1978_Init
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ADAU1978_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU1978_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ADAU1978_CODE) ADAU1978_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU1978_MainFunction
 *********************************************************************************************************************/
    if (adau_start == 1)
    {
        switch (adau_status)
        {
            case ADAU1978_CHECK_BOARD:
            {
                uint8 ver = eMiscBoard_Version_Non;

                if (E_OK  == Misc_Board_GetHwVersion(&ver))
                {
                    if (eMiscBoard_Version_B0 < ver)
                    {
                        adau_status = ADAU1978_SET_REG;
                        reg_index = 0;
                    }
                    else
                    {
                        adau1978_info("adau1978 not used for ver:%d\n", ver);
                        adau_status = ADAU1978_IDLE;
                    }
                }
                break;
            }
            case ADAU1978_SET_REG:
            {
                uint8 reg_addr, reg_value;
                if (TRUE == audu1978_get_default_reg(reg_index, &reg_addr, &reg_value))
                {
                    if (TRUE == audu1978_set_reg(reg_addr, reg_value))
                    {
                        adau_status = ADAU1978_SET_REG_WAIT;
                    }
                }
                else
                {
                    adau_status = ADAU1978_POWERUP;
                }
                break;
            }
            case ADAU1978_POWERUP:
            {
                if (TRUE == audu1978_pwup())
                {
                    adau_status = ADAU1978_POWERUP_WAIT;
                }
                break;
            }
            case ADAU1978_CHECK_PLL:
            {
                if (TRUE == audu1978_read_pll())
                {
                    adau_status = ADAU1978_CHECK_PLL_WAIT;
                }
                break;
            }
            default:
            {
                if (adau_status >= ADAU1978_UNKNOWN)
                {
                    adau_status = ADAU1978_IDLE;
                }
                break;
            }
        }
    }



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ADAU_StateToDeInit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StateToDeInit> of PortPrototype <ADAU_server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ADAU_StateToDeInit(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU_StateToDeInit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ADAU1978_CODE) ADAU_StateToDeInit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU_StateToDeInit
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ADAU_StateToInit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StateToInit> of PortPrototype <ADAU_server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ADAU_StateToInit(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU_StateToInit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ADAU1978_CODE) ADAU_StateToInit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ADAU_StateToInit
 *********************************************************************************************************************/
    adau_start = 1;
    adau_status = ADAU1978_CHECK_BOARD;
    reg_index = 0;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ADAU1978_STOP_SEC_CODE
#include "ADAU1978_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
extern void ADAU1978_set_next_status(IIC_ResultStatus_t state, const uint8 * p_data)
{
    if (eIIC_ResultStatus_Success ==  state)
    {
        iic_fail_count = 0;
    }
    else
    {
        iic_fail_count++;
    }
    if (IIC_RETRY_MAX <= iic_fail_count)
    {
        adau1978_warn("please check the HW.\n");
        adau_status = ADAU1978_IDLE;
    }
    else
    {
        switch(adau_status)
        {
            case ADAU1978_SET_REG_WAIT:
                if (eIIC_ResultStatus_Success == state)
                {
                    reg_index++;
                }
                adau_status = ADAU1978_SET_REG;
                break;
            case ADAU1978_POWERUP_WAIT:
                if (eIIC_ResultStatus_Success == state)
                {
                    adau_status = ADAU1978_CHECK_PLL;
                }
                else
                {
                    adau_status = ADAU1978_POWERUP;
                }
                break;
            case ADAU1978_CHECK_PLL_WAIT:
                if ((eIIC_ResultStatus_Success == state) && (NULL != p_data))
                {
                    if (*p_data & ADAU1978_PLL_LOCK_MASK)
                    {
                        adau_status = ADAU1978_IDLE;
                    }
                    else
                    {
                        adau_status = ADAU1978_CHECK_PLL;
                    }
                }
                else
                {
                    adau_status = ADAU1978_CHECK_PLL;
                }
                break;
            default:
                if (adau_status >= ADAU1978_UNKNOWN)
                {
                    adau_status = ADAU1978_IDLE;
                }
                break;
        }
    }
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
