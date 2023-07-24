/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable declarations                                               */
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
 * V2.0.0:  27-Sep-2016    : Updated were done as part of several tickets:
 *                           1. ARDAABC-769  Added write verification and RAM
 *                           mirroring  safety mechanisms for GPT registers.
 *                           2. Removed old registers readback/mirroring code.
 *                           3.Defined the ram mirrors for several Dynamic
 *                           registers used in GPT.
 *                           4.ARDAABC-518  Changed type of Gpt_GucDriverMode
 *                           from uint8 to Gpt_ModeType.
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar
 *                           version 4.0.3 and GPT_AR_HIGHER_VERSION to map
 *                           Autosar version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Add one new RAM mirror for OSTM channel used by
 *                           Predef timer function and  one global variable
 *                           Gpt_GusPredefTimerNrOverflows
 *                           used to count the number of overflows of the OSTM
 *                           Hw channel as part of ARDAABC-564
 *
 * V2.2.1:  06-Dec-2016    : Added compile switch GPT_PREDEF_TIMER_ENABLED to
 *                           exclude from compilation Predef Timer related code
 *                           when function is disabled.
 *
 * V2.2.2:  18-Sep-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. Copyright year updated.
 *                           3. As per ARDAABD-2570, typo errors corrected.
 *
 * V2.2.3:  18-Jun-2018    : Following changes are made:
 *                           1. As per ARDAABD-3841, traceability updated.
 *                           2. Copyright information updated.
 */
/******************************************************************************/
/*Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for module version information and other types declarations */
#include "Gpt.h"
/* Included for macro definitions */
#include "Gpt_PBTypes.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_RAM_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_RAM_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_RAM_C_AR_RELEASE_PATCH_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_RAM_C_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION_VALUE
#define GPT_RAM_C_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
/* Functionality related to R4.0 */
#if (GPT_RAM_AR_RELEASE_MAJOR_VERSION != GPT_RAM_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt.c : Mismatch in Release Major Version"
#endif

#if (GPT_RAM_AR_RELEASE_MINOR_VERSION != GPT_RAM_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt_Ram.c : Mismatch in Release Minor Version"
#endif

#if (GPT_RAM_AR_RELEASE_REVISION_VERSION != GPT_RAM_C_AR_RELEASE_PATCH_VERSION)
#error "Gpt_Ram.c : Mismatch in Release Patch Version"
#endif

#if (GPT_RAM_SW_MAJOR_VERSION != GPT_RAM_C_SW_MAJOR_VERSION)
#error "Gpt_Ram.c : Mismatch in Software Major Version"
#endif

#if (GPT_RAM_SW_MINOR_VERSION != GPT_RAM_C_SW_MINOR_VERSION)
#error "Gpt_Ram.c : Mismatch in Software Minor Version"
#endif

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
/* 2. QAC WARNING:                                                            */
/* Message       : Msg(2:2022) A tentative definition is being used. Is it    */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : Initialization of all members is ensured in Gpt_Init() API.*/
/*                 So explicit initialization during definition is not        */
/*                 required.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-2 and                           */
/*                 END Msg(2:2022)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC WARNING:                                                            */
/* Message      : (2:3211) The global identifier 'Gpt_GpTAUUnitConfig',       */
/*                'Gpt_GpChannelConfig ','Gpt_GpWakeUpFactorRamAddress',      */
/*                'Gpt_GpChannelRamData','Gpt_GucDriverMode',                 */
/*                'Gpt_GblDriverStatus' are defined here but is not used in   */
/*                this translation unit.                                      */
/* Justification: As per AUTOSAR, all global variables extern declaration     */
/*                shall be given in Gpt_Ram.h                                 */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-3 and                            */
/*                END Msg(2:3211)-3 tags in the code.                         */
/******************************************************************************/
/*******************************************************************************
 **                         Global Data                                       **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0019 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include GPT_MEMMAP_FILE

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
/* Qac Warning: START Msg(2:2022)-2 */
/* Qac Warning: START Msg(2:3211)-3 */
/* Global pointer variable for TAU Unit configuration */
P2CONST(Gpt_TAUUnitConfigType, GPT_VAR, GPT_CONFIG_CONST)
Gpt_GpTAUUnitConfig;
#endif

/* Global pointer variable for channel configuration */
P2CONST(Gpt_ChannelConfigType, GPT_VAR, GPT_CONFIG_CONST)
Gpt_GpChannelConfig;

#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* Global pointer variable for Wakeup Factor configuration */
P2CONST(Gpt_WakeupFactorType, GPT_VAR, GPT_CONFIG_CONST)
Gpt_GpWakeUpFactorRamAddress;
#endif

/* Global pointer variable for channel data */
P2VAR(Gpt_ChannelRamData, GPT_NOINIT_DATA, GPT_CONFIG_DATA)
Gpt_GpChannelRamData;

/* Indicates the Ram Mirror for HWCC */
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_OSTM_UNIT_USED == STD_ON))
VAR(OSTMRegMirror, GPT_NOINIT_DATA)
      Gpt_GaaGptOSTMRegMirror[GPT_NUM_OF_OSTM_REG];
#endif
#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUB_UNIT_USED == STD_ON) || (GPT_TAUD_UNIT_USED == STD_ON)))
VAR(TAUDBUserRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUDBUserRegMirror[GPT_NUM_OF_TAUDB_REG];
VAR(TAUDBChRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUDBChRegMirror[GPT_NUM_OF_TAUDB_CH_REG];
#endif
#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_TAUJ_UNIT_USED == STD_ON))
VAR(TAUJChRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUJChRegMirror[GPT_NUM_OF_TAUJ_CH_REG];
VAR(TAUJUserRegMirror, GPT_NOINIT_DATA)
    Gpt_GaaGptTAUJUserRegMirror[GPT_NUM_OF_TAUJ_REG];
#endif
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
/* Implements GPT_ESDD_UD_126 */
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_PREDEF_TIMER_ENABLED == STD_ON)\
    )
VAR(OSTMRegMirror, GPT_NOINIT_DATA) Gpt_GstGptPredefTimerOSTMRegMirror;
#endif
    /*End of ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \\
       (GPT_PREDEF_TIMER_ENABLED == STD_ON)\
    ) */
#endif /* (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

/* Functionality related to R4.0 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define GPT_START_SEC_VAR_NO_INIT_8
#endif
#include GPT_MEMMAP_FILE
/* Qac Warning: START Msg(2:2022)-2 */
/* Qac Warning: START Msg(2:3211)-3 */
/* Holds the status of GPT Driver Component */
VAR(Gpt_ModeType, GPT_NOINIT_DATA) Gpt_GucDriverMode;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-3 */
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

/* This global variable is used to count the number of timer overflows
 * of the hardware channel used for Predefined Timer functionality.
 * Maximum possible timer speed is 120Mhz( maximum clock) divided by 2
 * ( OSTM timer divider) resulting in a maximum possible value of 6000 for
 * this variable( considering 100us Predef timer resolution).
 * After this maximum value the variable shall be reset back to 0
 */
VAR(volatile uint16, GPT_NOINIT_DATA) Gpt_GusPredefTimerNrOverflows;

#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON) */
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_16
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_16
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define GPT_START_SEC_VAR_INIT_BOOLEAN
#endif
#include GPT_MEMMAP_FILE
/* Qac Warning: START Msg(2:3211)-3 */
/* Holds the status of Initialization */
VAR(boolean, GPT_INIT_DATA) Gpt_GblDriverStatus = GPT_UNINITIALIZED;
/* END Msg(2:3211)-3 */
/* Functionality related to R4.0 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define GPT_STOP_SEC_VAR_INIT_BOOLEAN
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
