/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Ram.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Global variable declarations for FlashTest driver Component.  */
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
 * V1.0.0: 20-Nov-2013    : Initial Version
 *
 * V1.0.1: 03-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. Global variable FlsTst_GenExeState is changed to
 *                              volatile.
 *
 * V1.0.2: 18-Jun-2014    : As per CR524 and mantis #21575, memory mapping
 *                          sections of variables are updated.
 *
 * V1.0.3: 17-Sep-2014    : As per CR12, Comments are added before global
 *                          variables declaration.
 *
 * V1.0.4: 21-Nov-2014    : As per CR74, Trailing Space are removed.
 *
 * V2.0.0: 21-Nov-2014    : Changed memmap file handling according to ASR4.2.2.
 * V2.0.1: 21-Jan-2017    : Macros added for write verify feature
 *                          Removed mask macrodefinitions for Write / Verify
 *                          from under compiler switch
 *                          Replaced FLSTST_MIRROR_ENABLE with FLSTST_ENABLE
 * V2.0.2: 31-Jan-2017    : As per ARDAABD-566, removed unused masks.
 * V2.0.3: 03-Feb-2017    : As part of JIRA ARDAABD-496:
 *                          1. Updated FLSTST_RAM_CFECCCTL_MASK_16BIT mask
 *                          value because PROT0 and PROT1 bits are always read
 *                          as 0
 *                          2. Removed RAM mirror indexes for DCRACINBGND
 *                          and DCRACINFGND registers
 *                          3. Updated number of mirrored registers
 * V2.0.4: 01-Mar-2017    : 1. As part of JIRA ARDAABD-714: Updated mask for
 *                          FLSTST_CF1STERSTR_VCILL register
 *                          2. As part of JIRA ARDAABD-408: Updated memclass and
 *                          memory selector for FlsTst_RamMirror,
 *                          FlsTst_GenLastFgndResult and
 *                          FlsTst_GenOverallBgndResult
 *                          3. FlsTst_GblTestComplete added
 * V2.0.5: 21-Aug-2017    : Justification added for QAC warning which cannot
 *                          be removed.
 * V2.0.6: 16-Apr-2018    : Following changes are made:
 *                         1. As part of merging activity #ARDAABD-3468
 *                           a. The memory sections,
 *                              FLSTST_<START/STOP>_SEC_VAR_32 and
 *                              FLSTST_<START/STOP>_SEC_VAR_UNSPECIFIED
 *                              removed and replaced with
 *                              FLSTST_<START/STOP>_SEC_VAR_INIT_32,
 *                              and FLSTST_<START/STOP>_SEC_VAR_INIT_UNSPECIFIED
 *                              respectively. Added new memory section
 *                              FLSTST_<START/STOP>_SEC_VAR_NO_INIT_BOOLEAN for
 *                              FlsTst_GblTestComplete variable.
 *                              Ref: ARDAABD-908
 *                            b.Copyright information is updated.
 * V2.0.7: 21-Jun-2018    : As part of #ARDAABD-3842, Removed duplicate
 *                          Requirement id's and mapped the required
 *                          Requirements for traceability
 */
/******************************************************************************/
/* FLSTST_RAM_H_001:  EAAR_PN0034_FR_0001                                     */
#ifndef FLSTST_RAM_H
#define FLSTST_RAM_H

/* Included for macro definitions */
#include "FlsTst_PBTypes.h"
/* Included for macro definitions for RAM MIRRORING*/
#include "FlsTst_Cfg.h"
#include "FlsTst_RegWrite.h"
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                             QAC Warnings                                   **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLSTST_RAM_AR_RELEASE_MAJOR_VERSION   FLSTST_AR_RELEASE_MAJOR_VERSION
#define FLSTST_RAM_AR_RELEASE_MINOR_VERSION   FLSTST_AR_RELEASE_MINOR_VERSION
#define FLSTST_RAM_AR_RELEASE_REVISION_VERSION  \
                                              FLSTST_AR_RELEASE_REVISION_VERSION

/* FLSTST_RAM_H_002:  EAAR_PN0034_FR_0055                                     */
/* File version information */
#define FLSTST_RAM_SW_MAJOR_VERSION    FLSTST_SW_MAJOR_VERSION
#define FLSTST_RAM_SW_MINOR_VERSION    FLSTST_SW_MINOR_VERSION

/*******************************************************************************
**                         Macro definition                                   **
*******************************************************************************/

/* masks for Write / Verify functionality */
#define FLSTST_RAM_DCRACTL_MASK_8BIT         (uint8)(0x07u)
#define FLSTST_RAM_CFECCCTL_MASK_16BIT       (uint16)(0x0003UL)
#define FLSTST_RAM_CFERRINT_MASK_8BIT        (uint8)(0x03u)
#define FLSTST_RAM_CF1STERSTR_MASK_8BIT      (uint8)(0x01u)


#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)


/* CRC control register for Background */
#define FLSTST_DCRACTLBGND_IDX                (0x00u)
/* CRC control register for Foreground */
#define FLSTST_DCRACTLFGND_IDX                (0x01u)
#if(FLSTST_TEST_ECC_API == STD_ON)
/* Code flash ECC control register */
#define FLSTST_CFECCCTL_VCI_IDX               (0x02u)
/* Code flash error information control register */
#define FLSTST_CFERRINT_VCI_IDX               (0x03u)
/* Total number of mirrored registers */
#define FLSTS_NB_OF_MIRRORED_REGS             (0x04u)
#else
/* Total number of mirrored registers */
#define FLSTS_NB_OF_MIRRORED_REGS             (0x02u)
#endif
#endif
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define FLSTST_START_SEC_VAR_NO_INIT_BOOLEAN
#include FLSTST_MEMMAP_FILE
/* Variable to store the test execution status*/
extern VAR(uint8, FLSTST_NOINIT_DATA)FlsTst_GblTestComplete;
#define FLSTST_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include FLSTST_MEMMAP_FILE

#define FLSTST_START_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable to store the interval id for bgnd test */
extern VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulTestIntervalId;
/* Variable to store the last signature for fgnd test */
extern VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulLastFgndSignature;
/* Variable to store the last signature for Bgnd test */
/* FLSTST_RAM_H_003:  FLSTST_ESDD_UD_081                                      */
extern VAR(uint32, FLSTST_NOINIT_DATA) FlsTst_GulLastBgndSignature;
/* Variable to store the Ecc test failed address  */
extern VAR(uint32, FLSTST_NOINIT_DATA)FlsTst_GulEccErrorAddress;

extern VAR(uint8, FLSTST_NOINIT_DATA)FlsTst_GblTestComplete;

#define FLSTST_STOP_SEC_VAR_NO_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
/* Variable to store the registers values in RAM  */
extern VAR(uint32, FLSTST_INIT_DATA)FlsTst_RamMirror
       [FLSTS_NB_OF_MIRRORED_REGS];
#endif

#define FLSTST_STOP_SEC_VAR_INIT_32
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Variable to store the Ecc test result  */
extern VAR(FlsTst_ErrorDetailsType, FLSTST_NOINIT_DATA)FlsTst_GddEccErrorDetail;
extern VAR(FlsTst_GVarProperties, FLSTST_NOINIT_DATA) FlsTst_GVar;
/* Variable FlsTst_GpConfigPtr to store data of FLSTST unit */
extern P2CONST(FlsTst_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                       FlsTst_GpConfigPtr;
/* variable FlsTst_GpBgndBlkConfig to store bgnd process data */
extern P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                   FlsTst_GpBgndBlkConfig;
/* variable FlsTst_GpFgndBlkConfig to store Fgnd process data */
extern P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                   FlsTst_GpFgndBlkConfig;

#define FLSTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* variable  to store  FlsTst execution  state  */
extern VAR(volatile FlsTst_StateType, FLSTST_INIT_DATA)FlsTst_GenExeState;
/* Variable to store the fgnd test result  */
/* FLSTST_RAM_H_005: FLSTST_ESDD_UD_069                                       */
extern VAR(FlsTst_TestResultFgndType, FLSTST_INIT_DATA)
                                                   FlsTst_GenLastFgndResult;
/* Variable to store the overall Bgnd test result  */
/* FLSTST_RAM_H_004: FLSTST_ESDD_UD_068                                       */
extern VAR(FlsTst_TestResultType, FLSTST_INIT_DATA)
                                                FlsTst_GenOverallBgndResult;

#define FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FLSTST_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
