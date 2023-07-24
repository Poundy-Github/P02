/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Types.h                                                 */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0: 07-Sep-2015 : Initial Version                                        *
* V1.0.1: 08-Jan-2016 : As part of the JIRA #ARDAAGA-42, Name and type         *
*                       changed for the structure member pSequencerSetting     *
*                       in Mcu_ConfigType Now it is uint8                      *
*                       ucSequencerSettingOffset                               *
* V2.0.0: 10-Jun-2016 : As part of JIRA #ARDAABD-455                           *
*                       MCU_MULTIPLE_RESETS_OCCURED  identifier was added      *
* V2.0.1: 14-Jun-2016 : Review points from 1.0.2  Implemented : history updated*
* V2.1.0: 09-Sep-2016 : ARDAABD-398 Acceptance points implemented:             *
*                       1. History comments made more relevant                 *
* V2.2.0: 14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore   *
*                           - MCU_AR_HIGHER_VERSION is changed to 4.2.2        *
*                           - MCU_AR_LOWER_VERSION is changed to 4.0.3         *
*                           - Removed code related to AUTOSAR 3.2.2            *
* V2.2.1: 28-Oct-2016 : ARDAABD-473 - History numbering changed according to   *
*                        projects requirements                                 *
* V2.3.0: 11-Nov-2016 : ARDAABD-710 -Add new attribute "ulSubOscClockStabCount"*
*                        in Mcu_ClockSetting structure for the SubOsc          *
*                        stabilization waiting time                            *
*                       ARDAABD-947 - Revision history updated with acceptance *
*                        points                                                *
*                       ARDAABD-918 - Memory class for pPortRamArea            *
*                        changed to TYPEDEF                                    *
* V2.4.0: 05-Dec-2016 : ARDAABD-918 - Memory class for pClockDomainOffset and  *
*                        pPortGroupSetting changed to TYPEDEF                  *
* V2.5.0: 13-Jan-2017 : ARDAABD-415 - Attribute ulSubOscClockStabCount removed *
*                        from Mcu_ConfigType structure                         *
* V2.6.0: 10-Mar-2017 : ARDAABD-1210 - Add Traceability                        *
* V2.7.0: 05-Jul-2017 : ARDAABD-1959 - Add new attributes usCLMA3CMPL and      *
*                        usCLMA3CMPH in Mcu_ConfigType structure               *
* V2.8.0: 20-Jul-2017 : ARDAABD-2083 - Update Mcu_ResetType for supporting     *
*                        F1KM CLMA3 reset reason                               *
* V2.9.0: 05-Oct-2017 : ARDAABD-2588 - Added changes after FuSa checklist      *
* V2.9.1: 28-Jun-2018 : The following changes are made:                        *
*                       1. As part of JIRA ARDAABD-3831, ucINTCWEND is added   *
*                          STag_Mcu_ConfigType.                                *
*                       2. As part of JIRA ARDAABD-3850, traceability          *
*                          inconsistencies are corrected and requirement       *
*                          mapping is done.                                    *
*                       3. As part of JIRA ARDAABD-3695, removed threshold     *
*                          value generation of CLMA0/1/2/3 from                *
*                          STag_Mcu_ConfigType.                               */
/******************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
/* macros to differentiate the Autosar R4.0 and R4.2 versions */
#define MCU_AR_FOUR_TWO_TWO       422
#define MCU_AR_FOUR_ZERO_THREE    403

#define MCU_AR_HIGHER_VERSION     MCU_AR_FOUR_TWO_TWO
#define MCU_AR_LOWER_VERSION      MCU_AR_FOUR_ZERO_THREE
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Standard AUTOSAR types */
#include "Std_Types.h"

/* Included for pre-compile options */
#include "Mcu_Cfg.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/


#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define MCU_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define MCU_TYPES_AR_RELEASE_MINOR_VERSION    2
#define MCU_TYPES_AR_RELEASE_REVISION_VERSION 2



#elif (MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
/* AUTOSAR release version information */
#define MCU_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define MCU_TYPES_AR_RELEASE_MINOR_VERSION    0
#define MCU_TYPES_AR_RELEASE_REVISION_VERSION 3

#endif

/* File version information */
#define MCU_TYPES_SW_MAJOR_VERSION  MCU_SW_MAJOR_VERSION
#define MCU_TYPES_SW_MINOR_VERSION  MCU_SW_MINOR_VERSION
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Handles for Mode setting */

/* MCUTYPES_H_001: MCU_ESDD_UD_041                                          */
/* MCUTYPES_H_002: EAAR_PN0075_FR_0010                                      */
/* MCUTYPES_H_003: MCU_ESDD_UD_015                                          */
/* Mode setting: RUN_MODE */
#define MCU_RUN_MODE                                (Mcu_ModeType)0x00
/* MCUTYPES_H_004: MCU_ESDD_UD_042                                          */
/* MCUTYPES_H_005: EAAR_PN0075_FR_0010                                      */
/* Mode setting: STOP_MODE */
#define MCU_STOP_MODE                               (Mcu_ModeType)0x01
/* MCUTYPES_H_006: MCU_ESDD_UD_043                                          */
/* MCUTYPES_H_007: EAAR_PN0075_FR_0010                                      */
/* Mode Setting: DEEPSTOP_MODE */
#define MCU_DEEPSTOP_MODE                           (Mcu_ModeType)0x02
/* MCUTYPES_H_008: MCU_ESDD_UD_044                                          */
/* MCUTYPES_H_009: EAAR_PN0075_FR_0010                                      */
/* Mode setting: HALT */
#define MCU_HALT_MODE                               (Mcu_ModeType)0x03
/* Mode setting: MCU_CYCLIC_RUN_MODE */
#define MCU_CYCLIC_RUN_MODE                         (Mcu_ModeType)0x04
/* Mode setting: MCU_CYCLIC_STOP_MODE */
#define MCU_CYCLIC_STOP_MODE                        (Mcu_ModeType)0x05

/* MCUTYPES_H_010: MCU_ESDD_UD_073                                          */
/* MCUTYPES_H_011: MCU232, MCU233                                           */
/* MCUTYPES_H_012: SWS_Mcu_00232, SWS_Mcu_00233, SWS_Mcu_00251              */
/* Type definition for Mcu_ClockType used by the API Mcu_InitClock */
typedef uint8 Mcu_ClockType;

/* MCUTYPES_H_013: MCU_ESDD_UD_074                                          */
/* MCUTYPES_H_014: MCU235, MCU236                                           */
/* MCUTYPES_H_015: SWS_Mcu_00235, SWS_Mcu_00236, SWS_Mcu_00253              */
/* Type definition for Mcu_RawResetType used by the API Mcu_GetResetRawValue */
typedef uint32 Mcu_RawResetType;

/* MCUTYPES_H_016: MCU_ESDD_UD_075                                          */
/* MCUTYPES_H_017: MCU237, MCU238                                           */
/* MCUTYPES_H_018: SWS_Mcu_00237, SWS_Mcu_00254, SWS_Mcu_00238              */
/* Type definition for Mcu_ModeType used by the API Mcu_SetMode */
typedef uint8 Mcu_ModeType;

/* MCUTYPES_H_040: MCU_ESDD_UD_108                                         */
/* Type definition for Mcu_ModeType used by the API Mcu_SetMode */
typedef uint8 Mcu_SeqType;

/* MCUTYPES_H_019: MCU_ESDD_UD_076                                          */
/* MCUTYPES_H_020: MCU239, MCU240                                           */
/* MCUTYPES_H_021: SWS_Mcu_00239, SWS_Mcu_00240, SWS_Mcu_00255              */
/* Type definition for Mcu_RamSectionType used by the API Mcu_InitRamSection */
typedef uint8 Mcu_RamSectionType;

/* MCUTYPES_H_022: MCU_ESDD_UD_054, MCU_ESDD_UD_024, MCU_ESDD_UD_025        */
/* MCUTYPES_H_023: SWS_Mcu_00131, SWS_Mcu_00053, SWS_Mcu_00054              */
/* MCUTYPES_H_024: SWS_Mcu_00035, SWS_Mcu_00031, SWS_Mcu_00030              */
/* MCUTYPES_H_025: EAAR_PN0075_FR_0001, EAAR_PN0075_FR_0005                 */
/* MCUTYPES_H_027: EAAR_PN0075_FR_0006                                      */
/* MCUTYPES_H_038: MCU131, MCU035, MCU031, MCU030                           */
/* MCUTYPES_H_039: MCU_ESDD_UD_026, MCU_ESDD_UD_186                         */

/* Structure for MCU Init Configuration */
typedef struct STag_Mcu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Count for stabilization at Main clock */
  uint32 ulMainClockStabCount;
  /* Element to handle the detection level of voltage */
  uint32 ulLVIindicationReg;
  #if (MCU_RETENTIONRAM_REQ == STD_ON)
  /* Element to start address of Retention Ram Area */
  uint32 ulRetentionRamAddr;
  uint32 ulCyclicRunModeBaseAddress;
  #endif
  /* Pointer to MCU Clock Setting configuration */
  P2CONST(void, TYPEDEF, MCU_CONFIG_CONST) pClockDomainOffset;
  uint8 ucClockSettingOffset;
  uint8 ucModeSettingOffset;
  #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
  /* Pointer to MCU Sequencer Configuration */
  uint8 ucSequencerSettingOffset;
  #endif
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer to array of port registers */
  P2CONST(void, TYPEDEF, MCU_CONFIG_CONST) pPortGroupSetting;
  uint8 ucPortGroupSettingOffset;
  /* Pointer to array of RAM area */
  P2VAR(uint32, TYPEDEF, MCU_CONFIG_CONST) pPortRamArea;
  uint8 pPortRamAreaNum;
  #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */

  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  uint8 ucNumOfPortGroup;
  #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */

  /* INTCWEND ISR enabled or disabled */
  #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
  uint8 ucINTCWEND;
  #endif

} Mcu_ConfigType;

/* MCUTYPES_H_028: MCU_ESDD_UD_077                                          */
/* MCUTYPES_H_029: MCU230, MCU231                                           */
/* MCUTYPES_H_030: SWS_Mcu_00230, SWS_Mcu_00231                             */
/* Status value returned by the API Mcu_GetPllStatus */
typedef enum ETag_Mcu_PllStatusType
{
  MCU_PLL_LOCKED = 0,
  MCU_PLL_UNLOCKED,
  MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/* MCUTYPES_H_031: MCU_ESDD_UD_078                                          */
/* MCUTYPES_H_032: MCU134, MCU234                                           */
/* MCUTYPES_H_033: SWS_Mcu_00134, SWS_Mcu_00234, SWS_Mcu_00252              */
/* MCUTYPES_H_034: EAAR_PN0075_FR_0018                                      */
/* Type of reset supported by the hardware */
typedef enum ETag_Mcu_ResetType
{
  MCU_SW_RESET = 1,
  MCU_WATCHDOG0_RESET,
  MCU_WATCHDOG1_RESET,
  MCU_CLM0_RESET,
  MCU_CLM1_RESET,
  /*MCU_CLM2_RESET for F1K and F1KM_S4, MCU_CLM3_RESET for F1KM_S1*/
  MCU_CLM2_RESET,
  MCU_LVI_RESET,
  MCU_CVM_RESET,
  MCU_TERMINAL_RESET,
  MCU_POWER_ON_RESET,
  MCU_ISO_RESET,
  #ifdef MCU_WDG2_RESET_ENABLE
  MCU_WATCHDOG2_RESET,
  #endif /* MCU_WDG2_RESET_ENABLE */
  MCU_RESF11_RESET,
  MCU_RESF12_RESET,
  MCU_RESF13_RESET,
  MCU_CLM3_RESET,
  MCU_RESET_UNDEFINED,
  MCU_MULTIPLE_RESETS_OCCURED,
  MCU_RESET_UNKNOWN
} Mcu_ResetType;


/* MCUTYPES_H_037: MCU_ESDD_UD_022                                          */
#if (MCU_GET_RAM_STATE_API == STD_ON)
/* MCUTYPES_H_035: MCU_ESDD_UD_079                                          */
/* MCUTYPES_H_036: SWS_Mcu_00256                                            */
/* Status value returned by the API Mcu_GetRamState */
typedef enum ETag_Mcu_RamStateType
{
  MCU_RAMSTATE_INVALID = 0,
  MCU_RAMSTATE_VALID
} Mcu_RamStateType;
#endif


/* MCUTYPES_H_041: MCU_ESDD_UD_109, MCU_ESDD_UD_121                         */
/* Sequencer operation type in Low power sequencer operation */
typedef enum ETag_Mcu_SeqOperationType
{
  MCU_DIGITAL_INPUT = 1,
  MCU_ANALOG_INPUT,
  MCU_MIXED_INPUT
} Mcu_SeqOperationType;


/* Ram write size type for ram initialization  */
typedef enum ETag_Mcu_RamWriteSizeType
{
  MCU_8BIT_SIZE = 1,
  MCU_16BIT_SIZE,
  MCU_32BIT_SIZE
} Mcu_RamWriteSizeType;

#endif /* MCU_TYPES_H */
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
