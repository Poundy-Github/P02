/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version.
 * V1.0.1:  11-Jan-2016  : As part of F1K V4.00.01 development activity,
 *                         following changes are made,
 *                         1. As part of the AR_PN0066_FR_0092 and JIRA
 *                            #ARDAAGA-187 PWM_VARIABLE_PERIOD_SHIFTED is added
 *                            in Pwm_ChannelClassType.
 * V2.0.0:  09-Nov-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 *                         2. JIRA #ARDAABD-926 - Since Config Data is
 *                            allocated in ROM, Config Data might not be allowed
 *                            to have variables whose Storage Specifier
 *                            is AUTOMATIC.
 *                         3. JIRA #ARDAABD-675 - Clk is not changed correctly
 *                            for synchronous channels.
 * V3.0.0: 23-Nov-2016  :  1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                            for ASIL-B.
 * V3.0.1: 17-Mar-2017  : Update for ARDAABD-827 Traceability ticket
 * V3.1.0: 10-Jul-2017  : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Structure elements 'ulGroup0', 'ulGroup1' and
 *                           'ulGroup2' are added in structure 'Pwm_ConfigType'.
 *                        2. Enumerated type 'Pwm_TriggerControlType' is
 *                           added.
 * V3.1.1: 18-Jun-2018  : Following changes are made:
 *                        1. As per JIRA ticket ARDAABD-1627, pre-compile
 *                           switch PWM_SELB_INTC2_SUPPORT is added for
 *                           usIntSelRegMask variable.
 *                        2. Updated copyright information.
 *                        3. As per JIRA ticket ARDAABD-3839, following changes
 *                           are made:
 *                           a. Added PWM_TYPES_H_016 to PWM_TYPES_H_020.
 *                           b. Updated existing traceability tags.
 */
/******************************************************************************/
/* PWM_TYPES_H_020:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045                 */
/* PWM_TYPES_H_019:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018                 */
#ifndef PWM_TYPES_H
#define PWM_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for pre-compile options */
#include "Pwm_Cfg.h"
#include "Pwm_Hardware.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* PWM_TYPES_H_017:  PWM_ESDD_UD_128, EAAR_PN0066_FR_0045                     */
#if (PWM_AR_VERSION == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_TYPES_AR_RELEASE_MAJOR_VERSION       PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_TYPES_AR_RELEASE_MINOR_VERSION       PWM_AR_RELEASE_MINOR_VERSION
#define PWM_TYPES_AR_RELEASE_REVISION_VERSION    PWM_AR_RELEASE_REVISION_VERSION

/* PWM_TYPES_H_018:  PWM_ESDD_UD_129, EAAR_PN0066_FR_0045                     */
#elif (PWM_AR_VERSION == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_TYPES_AR_RELEASE_MAJOR_VERSION       PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_TYPES_AR_RELEASE_MINOR_VERSION       PWM_AR_RELEASE_MINOR_VERSION
#define PWM_TYPES_AR_RELEASE_REVISION_VERSION    PWM_AR_RELEASE_REVISION_VERSION
#endif

/* Software module version information */
#define PWM_TYPES_SW_MAJOR_VERSION       PWM_SW_MAJOR_VERSION
#define PWM_TYPES_SW_MINOR_VERSION       PWM_SW_MINOR_VERSION

/******************************************************************************/
/* PWM_TYPES_H_016:  PWM_ESDD_UD_202                                          */
/* PWM_TYPES_H_001:  PWM_ESDD_UD_091                                          */
/* PWM_TYPES_H_002:  PWM106                                                   */
/* PWM_TYPES_H_003:  SWS_Pwm_00106                                            */
/* Type definition for Pwm_ChannelType */
typedef uint8  Pwm_ChannelType;
typedef uint16  Pwm_DiagPeriodType;

/* PWM_TYPES_H_004:  PWM107, PWM070, SWS_Pwm_00070                            */
/* PWM_TYPES_H_005:  SWS_Pwm_00107, EAAR_PN0066_FR_0008                       */
#if (PWM_TAUJ_UNIT_USED == STD_ON)
/* Type definition for Pwm_PeriodType if TAUJ is used */
typedef uint32 Pwm_PeriodType;
#else
/* Type definition for Pwm_PeriodType if TAUD and TAUB is used */
typedef uint16 Pwm_PeriodType;
#endif

/* PWM_TYPES_H_006:  PWM108                                                   */
/* PWM_TYPES_H_007:  SWS_Pwm_00108                                            */
/* Type definition for Pwm_OutputStateType */
typedef enum ETag_Pwm_OutputStateType
{
  PWM_LOW,
  PWM_HIGH
}Pwm_OutputStateType;

/* PWM_TYPES_H_008:  PWM109                                                   */
/* PWM_TYPES_H_009:  SWS_Pwm_00109                                            */
typedef enum ETag_Pwm_EdgeNotificationType
{
  PWM_RISING_EDGE,
  PWM_FALLING_EDGE,
  PWM_BOTH_EDGES
}Pwm_EdgeNotificationType;

/* PWM_TYPES_H_010:  PWM110, EAAR_PN0066_FR_0068, EAAR_PN0066_FR_0092         */
/* PWM_TYPES_H_011:  SWS_Pwm_00110, EAAR_PN0066_FR_0019                       */
/* Type definition for Pwm_ChannelClassType */
typedef enum ETag_Pwm_ChannelClassType
{
  PWM_VARIABLE_PERIOD,
  PWM_FIXED_PERIOD,
  PWM_FIXED_PERIOD_SHIFTED,
  PWM_VARIABLE_PERIOD_SHIFTED
}Pwm_ChannelClassType;

/* Type definition for Pwm_ClockSourceType */
typedef enum ETag_Pwm_ClockSourceType
{
  PWM_CLOCK_SOURCE_0 = 0U,
  PWM_CLOCK_SOURCE_1,
  PWM_CLOCK_SOURCE_2,
  PWM_CLOCK_SOURCE_3,
  PWM_INVALID_CLOCK_SOURCE
}Pwm_ClockSourceType;

/* PWM_TYPES_H_012:  PWM_ESDD_UD_070, PWM_ESDD_UD_176                         */
/* PWM_TYPES_H_013:  PWM061, PWM111, EAAR_PN0066_FR_0117                      */
/* PWM_TYPES_H_014:  SWS_Pwm_00061, SWS_Pwm_00111                             */
/* PWM_TYPES_H_015:  EAAR_PN0066_FR_0030, EAAR_PN0066_FR_0049                 */
/* Structure for Pwm_Init configuration */
/* Overall module configuration data structure */
typedef struct STag_Pwm_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer to PWM Driver TAUD/TAUB Unit configuration */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pTAUDBUnitConfig;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to PWM Driver TAUJ Unit configuration */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pTAUJUnitConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED  == STD_ON)
  /* Pointer to PWM Driver PWGA Unit configuration */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pDiagUnitConfig;
  /* Pointer to PWM Driver channel configuration */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pDiagChannelConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer to PWM Driver channel configuration */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pChannelConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  #if (PWM_SELB_INTC2_SUPPORT == STD_ON)
  uint16 usIntSelRegMask;
  #endif
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  uint32 ulGroup0;
  uint32 ulGroup1;
  uint32 ulGroup2;
  #endif
  #endif
}Pwm_ConfigType;

/* Type definition for Pwm_HWConsistencyModeType */
typedef enum ETag_Pwm_HWConsistencyModeType
{
  PWM_STATIC = 0,
  PWM_DYNAMIC
}Pwm_HWConsistencyModeType;

#if ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&  \
                                        (PWM_DIAG_UNIT_USED == STD_ON))
/* Type definition for Pwm_TriggerControlType */
typedef enum ETag_Pwm_TriggerControlType
{
  PWM_DISABLE = 0,
  PWM_ENABLE
}Pwm_TriggerControlType;
#endif

#endif /* PWM_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
