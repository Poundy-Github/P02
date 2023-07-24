/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the global RAM variable of MCU Driver                   */
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
* V1.0.0:  07-Sep-2015 : Initial Version                                       *
* V2.0.0:  14-Oct-2016 : As part of JIRA ARDAABD-473:                          *
*                           - AUTOSAR 3.2.2 is not supported anymore           *
*                           - MCU_AR_HIGHER_VERSION is changed to 4.2.2        *
*                           - MCU_AR_LOWER_VERSION is changed to 4.0.3         *
*                           - Removed code related to AUTOSAR 3.2.2            *
*                        As part of JIRA ARDAABD-838 - All boolean variables   *
*                           are grouped under one START/STOP memory section.   *
* V2.0.1:  28-Oct-2016 : As part of JIRA ARDAABD-473 - History numbering       *
*                           changed according to projects requirements         *
* V2.1.0:  01-Nov-2016 : As part of JIRA ARDAABD-569 - Variables used as       *
*                           Ram Mirror for Hardware ConsistencyCheck added     *
* V2.2.0:  31-Jan-2017 : As part of JIRA ARDAABD-989 - Included macro          *
*                           MCU_MEMMAP_FILE instead Memmap.h file              *
* V2.3.0:  22-Jun-2017 : As part of JIRA ARDAABD-1960 Added RAM mirror support *
*                           for wake up factor 1                               *
* V2.4.0:  05-Jul-2017 : As part of JIRA ARDAABD-1959 Added RAM mirror support *
*                           for CLMA 3 monitoring                              *
* V2.5.0: 29-Aug-2017 :  As part of JIRA ARDAABD-2150 -Added QAC/MISRA         *
*                           warnings justification.Corrected QAC/MISRA Warning.*
* V2.6.0: 19-Sep-2017 :  As part of JIRA ARDAABD-2346 Rename global variables  *
* V2.7.0: 01-Oct-2017 :  As part of JIRA ARDAABD-1359 Mcu_GddFeintRegRamMirror *
*                           was removed.                                       *
* V2.7.1: 11-Jul-2018 :  Following changes are done                            *
*                        1.As part of merging activities ARDAABD-3490,         *
*                         a. Changed memory section name from                  *
*                            MCU_<START/STOP>_SEC_VAR_NOINIT_UNSPECIFIED to    *
*                            MCU_<START/STOP>_SEC_VAR_NO_INIT_UNSPECIFIED.     *
*                         b. Mapped variable under MCU_STOP_SEC_VAR_BOOLEAN    *
*                            to MCU_STOP_SEC_VAR_INIT_BOOLEAN.                 *
*                        2.As part of #ARDAABD-3850, traceability              *
*                          inconsistencies are corrected and requirement       *
*                          mapping is done.                                   */
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3408) Has external linkage and is being defined without */
/*                 any previous declaration.                                  */
/* Rule          : MISRA-C:2004 Rule 8.8                                      */
/* Justification : This sub structure is accessed as a member in main         */
/*                 structure and hence declaration is not required.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3408)-1 and                           */
/*                 END Msg(4:3408)-1 tags in the code.                        */
/******************************************************************************/
/* 2.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-2 and               */
/*                 END Msg(2:0832)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:2022) A tentative definition is being used. Is it       */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Global Variable is not initialized because is kept in      */
/*                 No init area. Will be initialized at runtime with user     */
/*                 configuration values                                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:2022)-3 and               */
/*                 END Msg(2:2022)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SW to   */
/*                 generate global variables and array for MCU driver.        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3211)-4 and               */
/*                 END Msg(2:3211)-4 tags in the code.                        */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*Implements:  MCU130, SWS_Mcu_00130 */
/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Header file inclusion */
#include "Mcu_Ram.h"

/* Included for version check macro definitions and type definitions */
#include "Mcu.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_RAM_C_AR_RELEASE_MAJOR_VERSION    \
                                           MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_MINOR_VERSION    \
                                           MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_REVISION_VERSION  \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define MCU_RAM_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_RAM_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (MCU_RAM_AR_RELEASE_MAJOR_VERSION != MCU_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Major Version"
#endif /* (MCU_RAM_AR_RELEASE_MAJOR_VERSION !=
                                       MCU_RAM_C_AR_RELEASE_MAJOR_VERSION) */

#if (MCU_RAM_AR_RELEASE_MINOR_VERSION != MCU_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Minor Version"
#endif /* (MCU_RAM_AR_RELEASE_MINOR_VERSION !=
                                         MCU_RAM_C_AR_RELEASE_MINOR_VERSION) */

#if (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
                                   MCU_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Revision Version"
#endif /* (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
                                   MCU_RAM_C_AR_RELEASE_REVISION_VERSION) */


#if (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Major Version"
#endif /* (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION) */

#if (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Minor Version"
#endif /* (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION) */

/******************************************************************************
**                         Global Data                                       **
******************************************************************************/
/* Implements: MCU_ESDD_UD_071                                                */
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */
/* QAC Warning: START Msg(2:2022)-3 */
/* QAC Warning: START Msg(2:3211)-4 */
/* Global variable to store the config pointer */
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpClockSetting;

/* Global pointer variable for MCU CKSC clock Setting configuration */
P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpCkscSetting;

/* Implements: MCU_ESDD_UD_105                                                */
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpSeqSetting;
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

/* Implements: MCU_ESDD_UD_172, MCU_ESDD_UD_113                              */
/* Ram Mirror variables used for HWCC */
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
VAR(Mcu_LVIRegMirror, MCU_NOINIT_DATA)Mcu_GddLviRegRamMirror;
VAR(Mcu_RESFRegMirror, MCU_NOINIT_DATA)Mcu_GddResfRegRamMirror;
VAR(Mcu_LPSRegMirror, MCU_NOINIT_DATA)Mcu_GddLpsRegRamMirror;
VAR(Mcu_ClkMntrReg0Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg0RamMirror;
VAR(Mcu_ClkMntrReg1Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg1RamMirror;
VAR(Mcu_ClkMntrReg2Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg2RamMirror;
VAR(Mcu_ClkMntrReg3Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg3RamMirror;
VAR(Mcu_TAUJOsRegMirror, MCU_NOINIT_DATA)Mcu_GddTaujOsRegRamMirror;
VAR(Mcu_TAUJChRegMirror, MCU_NOINIT_DATA)Mcu_GddTaujChRegRamMirror;
VAR(Mcu_ClkCntlRegMirror, MCU_NOINIT_DATA)Mcu_GddClkCntlRegRamMirror;
VAR(Mcu_WUFReg0Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg0RamMirror;
VAR(Mcu_WUFReg20Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg20RamMirror;
VAR(Mcu_WUFRegISOMirror, MCU_NOINIT_DATA)Mcu_GddWufRegIsoRamMirror;
#if (MCU_WUF1_ENABLED == STD_ON)
VAR(Mcu_WUFReg10Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg10RamMirror;
#endif

/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */
/* QAC Warning: START Msg(2:3211)-4 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus = MCU_UNINITIALIZED;
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/* Global variable to store PLL ACT check status */
VAR(boolean, MCU_INIT_DATA) Mcu_GblPllActCheck = MCU_TRUE;

VAR(boolean, MCU_INIT_DATA) Mcu_GblResetFlag = E_NOT_OK;
/* Global variable to check WakeUp status of MCU Driver  */
/* MISRA Violation: START Msg(4:3408)-1 */
VAR(boolean, MCU_INIT_DATA) Mcu_GblWakeUpPreparation = MCU_ONE;
/* END Msg(4:3408)-1*/

/*Implements:  MCU_ESDD_UD_018 */
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
VAR(boolean, MCU_INIT_DATA) Mcu_GblSeqDriverStatus = MCU_UNINITIALIZED;
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
#endif /* MCU_LOW_POWER_SEQUENCER == STD_ON */
/* END Msg(2:3211)-4 */
/* QAC Warning: START Msg(2:0832)-2 */
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
