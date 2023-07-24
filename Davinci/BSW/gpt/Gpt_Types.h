/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  17-Sep-2015    : Initial Version
 *
 * V2.0.0:  27-Sep-2016    : As part of ticket ARDAABC-769, added one new type
 *                           definition Gpt_HWConsistencyModeType for selecting
 *                           the type of consistency check: Static or Dynamic
 *                           registers.
 *
 * V2.0.1:  27-Oct-2016    : As part of ticket ARDAABC-937, changed storage
 *                           specifier from AUTOMATIC to TYPEDEF where was the
 *                           case.
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Defined new type for identifying Predef
 *                           timers as part of ARDAABC-564:
 *
 * V2.2.1:  20-Oct-2017    : As per ARDAABD-2570, typo errors corrected
 *                           and copyright year updated.
 */
/******************************************************************************/

#ifndef GPT_TYPES_H
#define GPT_TYPES_H
/* GPT_TYPES_H_007: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/

/* Included for pre-compile options */
/* GPT_TYPES_H_006: GPT369 */
#include "Gpt_Cfg.h"
/* Included for ConfigType structure types */
#include "Gpt_PBTypes.h"

/*******************************************************************************
 **                        Version Information                                **
 ******************************************************************************/
/* GPT_TYPES_H_008: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_TYPES_AR_RELEASE_MAJOR_VERSION       GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_TYPES_AR_RELEASE_MINOR_VERSION       GPT_AR_RELEASE_MINOR_VERSION
#define GPT_TYPES_AR_RELEASE_REVISION_VERSION    GPT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define GPT_TYPES_SW_MAJOR_VERSION   GPT_SW_MAJOR_VERSION
#define GPT_TYPES_SW_MINOR_VERSION   GPT_SW_MINOR_VERSION
/* GPT_TYPES_H_001: GPT357, GPT183_Conf */
/* GPT_TYPES_H_002: SWS_Gpt_00357, ECUC_Gpt_00183 */
/* Data Structure for GPT required for Initializing the GPT timer unit */
typedef struct STag_Gpt_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
  /* Pointer to GPT driver channel configuration */
  P2CONST(Gpt_TAUUnitConfigType, TYPEDEF, GPT_CONFIG_CONST) pTAUUnitConfig;
#endif
  /* Pointer to GPT driver channel configuration */
  P2CONST(Gpt_ChannelConfigType, TYPEDEF, GPT_CONFIG_CONST) pChannelConfig;
  /* Pointer to address of internal RAM data */
  P2VAR(Gpt_ChannelRamData, TYPEDEF, GPT_CONFIG_DATA) pChannelRamAddress;
#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* Pointer to the address of WUF register */
  P2CONST(Gpt_WakeupFactorType, TYPEDEF, GPT_CONFIG_DATA)
    pWakeUpFactorRamAddress;
#endif

} Gpt_ConfigType;
/* GPT_TYPES_H_003: GPT360 */
/* GPT_TYPES_H_004: SWS_Gpt_00360 */
/* Type describing the functioning state of the GPT driver */
typedef enum ETag_GptModeType
{
  GPT_MODE_NORMAL,
  GPT_MODE_SLEEP
} Gpt_ModeType;


/* Type describing the GPT registry consistency check modes */
typedef enum ETag_Gpt_HWConsistencyModeType
{
  GPT_STATIC = 0,
  GPT_DYNAMIC
} Gpt_HWConsistencyModeType;

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
/* GPT_TYPES_H_005: SWS_Gpt_00383, SWS_Gpt_00389 */
typedef enum ETag_Gpt_PredefTimerType
{
  GPT_PREDEF_TIMER_1US_16BIT,
  GPT_PREDEF_TIMER_1US_24BIT,
  GPT_PREDEF_TIMER_1US_32BIT,
  GPT_PREDEF_TIMER_100US_32BIT
} Gpt_PredefTimerType;

#endif /* #if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#endif /* GPT_TYPES_H */


/*******************************************************************************
 **                          End Of File                                      **
 ******************************************************************************/
