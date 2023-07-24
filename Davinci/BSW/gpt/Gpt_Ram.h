/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable declarations.                                              */
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

/*******************************************************************************
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 *
 * V2.0.0:  27-Sep-2016    : As part of ARDAABC-769:Added declaration of RAM
 *                           mirrors used for implemented Hardware Consistency
 *                           Check safety mechanisms
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 * V2.2.0:  15-Oct-2016    : Add one new RAM mirror for OSTM channel used by
 *                           Predef timer function and  one global variable
 *                           Gpt_GusPredefTimerNrOverflows used to count the
 *                           number of overflows of the OSTM Hw channel as part
 *                           of ARDAABC-564
 * V2.2.1:  06-Dec-2016    : Added compile switch GPT_PREDEF_TIMER_ENABLED to
 *                           exclude from compilation Predef Timer related code
 *                           when function is disabled.
 *
 * V2.2.2:  18-Sep-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. As per ARDAABD-2570, typo errors corrected.
 *                           3. Copyright year updated.
 *
 * V2.2.3:  18-Jun-2018    : Following changes are made:
 *                           1. As per ARDAABD-3841, traceability updated.
 *                           2. Copyright information updated.
 */
/******************************************************************************/

#ifndef GPT_RAM_H
#define GPT_RAM_H
/* GPT_RAM_H_001: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_RAM_H_002: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_RAM_AR_RELEASE_MAJOR_VERSION      GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_RAM_AR_RELEASE_MINOR_VERSION      GPT_AR_RELEASE_MINOR_VERSION
#define GPT_RAM_AR_RELEASE_REVISION_VERSION   GPT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define GPT_RAM_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION
#define GPT_RAM_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
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
 **                      Global Data Types                                    **
 ******************************************************************************/
/* GPT_RAM_H_001: GPT_ESDD_UD_084, GPT_ESDD_UD_126 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON) )
/* Global pointer variable for TAU Unit configuration */
extern P2CONST(Gpt_TAUUnitConfigType, GPT_VAR, GPT_CONFIG_CONST)
Gpt_GpTAUUnitConfig;
#endif

/* Global pointer variable for channel configuration */
extern P2CONST(Gpt_ChannelConfigType, GPT_VAR, GPT_CONFIG_CONST)
    Gpt_GpChannelConfig;

#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* Global pointer variable for Wakeup Factor configuration */
extern P2CONST(Gpt_WakeupFactorType, GPT_VAR, GPT_CONFIG_CONST)
    Gpt_GpWakeUpFactorRamAddress;
#endif

/* Global pointer variable for channel data */
extern P2VAR(Gpt_ChannelRamData, GPT_NOINIT_DATA, GPT_CONFIG_DATA)
      Gpt_GpChannelRamData;

/* Indicates the Ram Mirror for HWCC */
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_OSTM_UNIT_USED == STD_ON))
extern VAR(OSTMRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptOSTMRegMirror[GPT_NUM_OF_OSTM_REG];
#endif
#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUB_UNIT_USED == STD_ON) || (GPT_TAUD_UNIT_USED == STD_ON)))
extern VAR(TAUDBUserRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUDBUserRegMirror[GPT_NUM_OF_TAUDB_REG];
extern VAR(TAUDBChRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUDBChRegMirror[GPT_NUM_OF_TAUDB_CH_REG];
#endif
#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_TAUJ_UNIT_USED == STD_ON))
extern VAR(TAUJChRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUJChRegMirror[GPT_NUM_OF_TAUJ_CH_REG];
extern VAR(TAUJUserRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUJUserRegMirror[GPT_NUM_OF_TAUJ_REG];
#endif

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)

#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_PREDEF_TIMER_ENABLED == STD_ON) \
    )
extern VAR(OSTMRegMirror, GPT_NOINIT_DATA) Gpt_GstGptPredefTimerOSTMRegMirror;

#endif
    /*End of ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) &&
              (GPT_PREDEF_TIMER_ENABLED == STD_ON)) */
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define GPT_START_SEC_VAR_NO_INIT_8
#endif
#include GPT_MEMMAP_FILE

/* Holds the status of GPT Driver Component */
extern VAR(Gpt_ModeType, GPT_NOINIT_DATA) Gpt_GucDriverMode;
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_8
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_16
#else
  #define GPT_START_SEC_VAR_NO_INIT_16
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)

extern VAR(volatile uint16, GPT_NOINIT_DATA) Gpt_GusPredefTimerNrOverflows;

#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_16
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_16
#endif
#include GPT_MEMMAP_FILE
/* Functionality related to R4.0 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define GPT_START_SEC_VAR_INIT_BOOLEAN
#endif
#include GPT_MEMMAP_FILE

/* Holds the status of Initialization */
extern VAR(boolean, GPT_INIT_DATA) Gpt_GblDriverStatus;

/* Functionality related to R4.0 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define GPT_STOP_SEC_VAR_INIT_BOOLEAN
#endif
#include GPT_MEMMAP_FILE


/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#endif  /* GPT_RAM_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
