/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_LLDriver.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of prototypes for internal functions.                            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/******************************************************************************
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 *
 * V2.0.0:  27-Sep-2016    : Several changes for solving tickets
 *                           1. ARDAABC-518 Renamed functions
 *                           Gpt_HW_EnableWakeup and Gpt_HW_DisableWakeup to
 *                           Gpt_HW_EnableInterrupt and Gpt_HW_DisableInterrupt
 *                           to better describe their purpose
 *                           2. ARDAABC-769 Added declaration for
 *                           Gpt_LLDriverHWCheckConsistency function
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Add several new functions for handling Predef
 *                           timers as part of ARDAABC-564:
 *                           1.Gpt_HW_GetPredefTimerValue for reading the value
 *                           of a Predef Timer
 *                           2.Gpt_HW_StartPredefTimer for starting the HW
 *                           channel of Predef timers
 *                           3.Gpt_HW_StopPredefTimer for stopping the HW
 *                           channel of Predef timers
 *                           4.Gpt_HW_PredefTimerCallbackNotification
 *                           notification in case of interrupt
 *                           5.Added references to FEINT and EI interrupt
 *                           registers used to enable/disable the interrupt of
 *                           the OSTM channel used by Predef Timer functions
 *
 * V2.2.1:  06-Dec-2016    : Added macro GPT_PREDEF_100US_TIMER_RESOLUTION
 *                           and added compile switch GPT_PREDEF_TIMER_ENABLED
 *                           to exclude from compilation Predef Timer related
 *                           code when function is disabled.
 *
 * V2.2.2:  25-Jul-2017    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-1516,
 *                              Gpt_HW_DisableInterrupt is updated with new
 *                              argument.
 *                           2. Copyright year updated.
 *
 * V2.2.3:  18-Aug-2017    : As part of JIRA ARDAABD-2305, FEINT Masks for OSTM
 *                           timer units are added and Predef interrupt
 *                           Macros removed.
 *
 * V2.2.4:  26-Sep-2017    : Following changes are made:
 *                           1.As per ARDAABD-2425, QAC level 2 warning
 *                           Justification tags are added.
 *                           2.As per ARDAABD-2461,'Iocommon_Defines.h' is added
 *
 * V2.2.5:  13-Apr-2018    : Following changes were made as per merging
 *                            activity,#ARDAABD-3489:
 *                            1.'Iocommon_Defines.h' is removed from header file
 *                            and added in source file. (Ref: ARDAABD-2461)
 *                            2. Copyright information updated.
 */
/******************************************************************************/

#ifndef GPT_LLDRIVER_H
#define GPT_LLDRIVER_H
/* GPT_LLDRIVER_H_001: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for Gpt.h inclusion and macro definitions */
/* GPT_LLDRIVER_H_002: GPT_ESDD_UD_114*/
#include "Gpt_PBTypes.h"
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_LLDRIVER_H_003: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_LLDRIVER_AR_RELEASE_MAJOR_VERSION GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_LLDRIVER_AR_RELEASE_MINOR_VERSION GPT_AR_RELEASE_MINOR_VERSION
#define GPT_LLDRIVER_AR_RELEASE_REVISION_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION

/*  File version information */
#define GPT_LLDRIVER_SW_MAJOR_VERSION   GPT_SW_MAJOR_VERSION
#define GPT_LLDRIVER_SW_MINOR_VERSION   GPT_SW_MINOR_VERSION

/*******************************************************************************
 **                         QAC Warning                                       **
 ******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : None                                                       */
/* Justification : These Macro substitution is required to optimize MemMap    */
/*                 inclusion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-1 and                           */
/*                 END Msg(4:0857)-1 tags in the code.                        */
/*                                                                            */
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (Msg(4:3453) A function could probably be used instead of  */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Necessary for the practical extension of functionality to  */
/*                 multiple registers                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-2 and                           */
/*                 END Msg(4:3453)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/

/* Masking values of OSTM1-OSTM4 FE interrupts */
#define GPT_OSTM1FEINT_MASK              0x00040000uL
#define GPT_OSTM2FEINT_MASK              0x00080000uL
#define GPT_OSTM3FEINT_MASK              0x00100000uL
#define GPT_OSTM4FEINT_MASK              0x00200000uL
#define GPT_OSTM6FEINT_MASK              0x02000000uL
#define GPT_OSTM7FEINT_MASK              0x04000000uL
#define GPT_OSTM8FEINT_MASK              0x08000000uL
#define GPT_OSTM9FEINT_MASK              0x10000000uL
/*Offset used to compute the position of a certain channel.
 * OSTM1 corresponds to position 18
 * Value 1 is subtracted for 18 to compensate for the channel index
 * */
#define GPT_OSTMFEINT_OFFSET                 17u

/* Specifies how much slower is the 100us timer compared to the 1us timer */
#define GPT_PREDEF_100US_TIMER_RESOLUTION    100u

/* Define references to FEINT registers */
#define GPT_FEINT_FACTOR_REGISTER        (IO_COMMON_FEINTF)
#define GPT_FEINT_FACTOR_MASK_REGISTER   (FEINTFMSK)
#define GPT_FEINT_FACTOR_CLEAR_REGISTER  (IO_COMMON_FEINTFC)

#define GPT_PREDEF_TIMER_RESET_LIMIT     \
  ((GPT_PREDEF_TIMER_DIVISION_FACTOR * 100u) - 1u)

/*******************************************************************************
** Macro Name            : GPT_FEINT_WRITE_OR
**
** Description           : This Macro performs writing which involves an
**                         OR operation.It is intended for updating FEINTFMSK
**                         and FEINTFC registers. Registers can be set in both
**                         user and supervisor modes.
**
**
** Input Parameters      : ADDR, VAL
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* GPT_LLDRIVER_H_004: EAAR_PN0034_FR_0081 */
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_FEINT_WRITE_OR(ADDR, VAL) (*((volatile uint32*)(ADDR)) = \
                                        ((*((volatile uint32*)(ADDR)))| \
                                        (uint32)(VAL)))
/* END Msg(4:3453)-2 */
/*******************************************************************************
** Macro Name            : GPT_FEINT_WRITE_AND
**
** Description           : This Macro performs writing which involves an
**                         AND operation.It is intended for updating FEINTFMSK
**                         and FEINTFC registers. Registers can be set in both
**                         user and supervisor modes.
**
** Input Parameters      : ADDR, VAL
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* GPT_LLDRIVER_H_005: EAAR_PN0034_FR_0081 */
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_FEINT_WRITE_AND(ADDR, VAL) (*((volatile uint32*)(ADDR)) = \
                                         ((*((volatile uint32*)(ADDR)))& \
                                         (uint32)(VAL)))
/* END Msg(4:3453)-2 */
/*******************************************************************************
** Macro Name            : GPT_FEINT_WRITE_ONLY
**
** Description           : This Macro performs direct writing .
**                         It is intended for updating FEINTFMSK
**                         and FEINTFC registers. Registers can be set in both
**                         user and supervisor modes.
**
** Input Parameters      : ADDR, VAL
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* GPT_LLDRIVER_H_006: EAAR_PN0034_FR_0081 */
/* MISRA Violation: START Msg(4:3453)-2 */
#define GPT_FEINT_WRITE_ONLY(ADDR, VAL)  (*((volatile uint32*)(ADDR)) = \
                                           (uint32)(VAL))
/* END Msg(4:3453)-2 */
/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Init(void);

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DeInit(void);

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StopTimer
    (const Gpt_ChannelType channel);

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StartTimer
    (const Gpt_ChannelType channel, const Gpt_ValueType value);


#if (GPT_TIME_ELAPSED_API == STD_ON)
FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeElapsed
    (const Gpt_ChannelType channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeRemaining
    (const Gpt_ChannelType channel);
#endif

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_EnableInterrupt
    (const Gpt_ChannelType channel);

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DisableInterrupt
    (const Gpt_ChannelType channel, boolean LblCriticalSectionFlag);



#if ( (GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))

FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_LLDriverHWCheckConsistency
    (const Gpt_HWConsistencyModeType HWConsistencyMode);

#endif  /* End of ((GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
                   (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE )|| \
                   (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))*/
/*Predef Timers only available on Autosar version 4.2.2 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
FUNC(Gpt_ValueType, GPT_PRIVATE_CODE)Gpt_HW_GetPredefTimerValue (
    Gpt_PredefTimerType LddPredefTimer);

FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StartPredefTimer(void);

FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StopPredefTimer(void);
#endif
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */


#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_START_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE

extern FUNC(void, GPT_FAST_CODE) Gpt_CbkNotification(const uint8 LucChannelIdx);

/*Predef Timers only available on Autosar version 4.2.2 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
FUNC (void, GPT_FAST_CODE) Gpt_HW_PredefTimerCallbackNotification(void);
#endif /* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON) */
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

/* MISRA Violation: START Msg(4:0857)-1 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_STOP_SEC_CODE_FAST
#endif
/* END Msg(4:0857)-1 */
#include GPT_MEMMAP_FILE

#endif  /* GPT_LLDRIVER_H */
/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
