/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SchM_Gpt.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Header of BSW Scheduler for BSW Module <Gpt>
 *********************************************************************************************************************/
#ifndef SCHM_GPT_H
# define SCHM_GPT_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Gpt_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_TIMERINT_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_TIMERINT_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_TIMERREG_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_TIMERREG_PROTECTION(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_GPT_H */
