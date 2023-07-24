/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_PBTypes.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
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
 * V1.0.0:  20-Nov-2013    : Initial Version
 *
 * V1.0.1:  03-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. Macro values added.
 *
 * V1.0.2:  06-Jun-2014    : As per CR524 and mantis #21020 inclusion of header
 *                           file "FlsTst.h" is removed.
 *
 * V1.0.3:  17-Sep-2014    : As per CR12, following changes are made:
 *                           1. MISRA C Rule Violations section is added.
 *                           2. MISRA rules violation messages are added.
 * V2.0.0:  28-Oct-2016    : Changed exclusive area handling according to
 *                           ASR4.2.2.
 * V2.0.1:  03-Nov-2016    : As Part of JIRA ARDAABD-714 : Removed unused macro
 *                           (FLSTST_DISABLE_ADDRESS_PARITY)
 * V2.0.2:  04-Nov-2016    : As Part of JIRA ARDAABD-713 : Add default values
 *                           for VCI registers
 *                           As Part of JIRA ARDAABD-848 : Change the check
 *                           method for ASR version
 * V2.0.3:  31-Jan-2017    : As Part of JIRA ARDAABD-566 : Updated definition
 *                           FLSTST_ECC_ENABLE_NOTIFICATION
 * V2.0.4:  13-Mar-2017    : As Part of JIRA ARDAABD-933:
 *                           1. Corrected computation of FLSTST_DBTOC_VALUE
 *                           As Part of JIRA ARDAABD-1211:
 *                           1. Added traceability information
 * V2.0.5:  05-Jul-2017    : Implemented 2-bit test pattern for FlsTst_TestEcc
 * V2.0.6:  21-Aug-2017    : Justification added for QAC warning which cannot
 *                           be removed. Changed suffix for constants.
 * V2.0.7:  12-Jul-2018    : 1. As part of #ARDAABD-3842, Removed duplicate
 *                              Requirement id's and mapped the required
 *                              Requirements for traceability
 *                           2. Updated copy-rights information
 */
/******************************************************************************/
/* FLSTST_PBTYPES_H_003:  EAAR_PN0034_FR_0001                                 */
#ifndef FLSTST_PBTYPES_H
#define FLSTST_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for FlsTst type declarations */
#include "FlsTst_Types.h"
/* Included for call-back functions declarations */
#include "FlsTst_Cbk.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Release version information */
#define FLSTST_PBTYPES_AR_RELEASE_MAJOR_VERSION  FLSTST_AR_RELEASE_MAJOR_VERSION
#define FLSTST_PBTYPES_AR_RELEASE_MINOR_VERSION  FLSTST_AR_RELEASE_MINOR_VERSION
#define FLSTST_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                              FLSTST_AR_RELEASE_REVISION_VERSION

/* FLSTST_PBTYPES_H_004:  EAAR_PN0034_FR_0055                                 */
/* Module Software version information */
#define FLSTST_PBTYPES_SW_MAJOR_VERSION   FLSTST_SW_MAJOR_VERSION
#define FLSTST_PBTYPES_SW_MINOR_VERSION   FLSTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* General defines */

#define FLSTST_DBTOC_VALUE      ((FLSTST_VENDOR_ID_VALUE << 22U) | \
                                (FLSTST_MODULE_ID_VALUE << 14U) | \
                                (FLSTST_SW_MAJOR_VERSION_VALUE << 8U) | \
                                (FLSTST_SW_MINOR_VERSION_VALUE << 3U))

/* Macro to avoid direct numbers */
#define FLSTST_LONG_WORD_ZERO              (uint32)0x00000000UL
/* Macro to avoid direct numbers */
#define FLSTST_SHORT_WORD_ZERO             (uint16)0x0000
/* Macro for default values for DCRA unit */
#define FLSTST_DCRACOUT_RESET_VAL          (uint32)0xFFFFFFFFUL
#define CF1STEADR0_VCI_DEFAULT             (uint32)0x00000000UL
#define CFECCCTL_VCI_DEFAULT               (uint16)0x00000000UL
#define CFERRINT_VCI_DEFAULT               (uint8)0x00000003UL
#define CF1STERSTR_VCI_DEFAULT             (uint32)0x00000000UL
#define CFSTSTCTL_VCI_DEFAULT              (uint32)0x00000000UL

#define FLSTST_ZERO                        (uint8)0x00
#define FLSTST_ONE                         (uint8)0x01
#define FLSTST_TWO                         (uint8)0x02
#define FLSTST_THREE                       (uint8)0x03
#define FLSTST_FOUR                        (uint8)0x04
#define FLSTST_SIX                         (uint8)0x06
#define FLSTST_EIGHT                       (uint8)0x08
#define FLSTST_TEN                         (uint8)0x0A
/* Driver status Macros */
#define FLSTST_INITIALIZED                 (boolean)1
#define FLSTST_UNINITIALIZED               (boolean)0
#define FLSTST_TRUE                        (boolean)1
#define FLSTST_FALSE                       (boolean)0
/* CRC/Checksum Start Value */
#define FLSTST_CRC16_INITIAL_VALUE         (uint16)0xFFFF
#define FLSTST_CRC8_INITIAL_VALUE          (uint8)0xFF
#define FLSTST_CRC32_INITIAL_VALUE         (uint32)0xFFFFFFFFUL

#if (FLSTST_DEVICE_SPECIFIC == STD_ON)
/* crc32 , 8bit data input */
#define FLSTST_CRC32CNTL                   (uint8)0x20
/* crc16 , 8bit data input */
#define FLSTST_CRC16CNTL                   (uint8)0x21
/* crc8 , 8bit data input for SAEJ1850 */
#define FLSTST_CRC8CNTL_SAEJ1850           (uint8)0x22
/* crc8 , 8bit data input for 0x2F */
#define FLSTST_CRC8CNTL_2F                 (uint8)0x23
#else
/* crc32 , 8bit data input*/
#define FLSTST_CRC32CNTL                   (uint8)0x04
/* crc16 , 8bit data input*/
#define FLSTST_CRC16CNTL                   (uint8)0x05
#endif

#define FLSTST_ECC_TEST_DELAY              (uint8)0x1F
#define FLSTST_ALL1_VALUE                  (uint32)0xFFFFFFFFUL
#define FLSTST_2BIT_ERROR_VALUE            (uint32)0xC0000000UL
#define FLSTST_ECC_SEC_ACTIVATE            (uint16)0x4000
#define FLSTST_ECC_DISABLE_NOTIFICATION    (uint8)0x00
#define FLSTST_ECC_ENABLE_NOTIFICATION     (uint8)0x03
#define FLSTST_WALK1_END                   (uint8)0x8A
#define FLSTST_ALL1_END                    (uint8)0x8B
#define FLSTST_ECC_END_PATTERN             (uint8)0x8C

/* FLSTST_PBTYPES_H_005: EAAR_PN0034_NR_0026                                  */
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

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
**               SchM Critical Section Protection Macros                      **
*******************************************************************************/
/* Macros for Critical Section */
/* FLSTST_PBTYPES_H_001:  FLSTST_ESDD_UD_004                                  */
/* FLSTST_PBTYPES_H_002:  EAAR_PN0034_FR_0013                                 */
#define FLSTST_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                 SchM_Enter_FlsTst_##Exclusive_Area()

#define FLSTST_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                 SchM_Exit_FlsTst_##Exclusive_Area()

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for FLSTST bgnd test block  Configuration */
extern CONST (FlsTstBlock_ConfigType, FLSTST_CONST)
                                            FlsTst_GstFlsTstBlockBgndConfig[];
/* END Msg (4:3684)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for FLSTST fgnd test block   Configuration */
/* FLSTST_PBTYPES_H_006: FLSTST_ESDD_UD_072                                   */
extern CONST (FlsTstBlock_ConfigType, FLSTST_CONST)
                                            FlsTst_GstFlsTstBlockFgndConfig[];
/* END Msg (4:3684)-1 */
#define FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* FLSTST_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
