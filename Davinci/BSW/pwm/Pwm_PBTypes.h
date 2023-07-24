/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and structure data types for post build          */
/* parameters of PWM Driver                                                   */
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
 * V1.0.1:  09-Aug-2016  : As part of F1K V42.00.00 development activity,
 *                         the following changes are made:
 *                         1. As part of JIRA #ARDAABD-438,
 *                            PWM_SYNCH_TAUDB_MASK was defined.
 * V1.0.2:  26-Aug-2016  : As part of F1K V42.00.00 development activity,
 *                         the following changes are made:
 *                         1. As part of JIRA #ARDAABD-438,
 *                            PWM_SYNCH_TAUDB_MASK was removed.
 * V2.0.0:  01-Nov-2016  : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                            ASR 4.0.3.
 *                         2. JIRA #ARDAABD-708 - Illegal pointer access when
 *                            pending interrupts are cleared.
 *                         3. JIRA #ARDAABD-671 - Channels configured for
 *                            complex driver start during Pwm_Init.
 *                         4. JIRA #ARDAABD-850 - SchM stubs not compliant
 *                            with SWS_Rte_07250
 *                         5. JIRA #ARDAABD-926 - Since Config Data is
 *                            allocated in ROM, Config Data might not be allowed
 *                            to have variables whose Storage Specifier
 *                            is AUTOMATIC.
 * V3.0.0:  23-Nov-2016  : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                            for ASIL-B.
 * V4.0.0:  06-Dec-2016  : Schm interface format changed according to
 *                           SWS_Rte_07250, as part of ticket ARDAABD-850
 * V4.0.1:  19-Dec-2016  : Ensure acceptance point regarding Coding Requirements
 * V4.0.2:  17-Mar-2017  : Update for ARDAABD-827 Tracebility ticket
 * V4.0.3:  19-Jun-2017  : MISRA violations are handled.
 * V4.1.0:  10-Jul-2017  : As per JIRA ticket #ARDAABD-1726, following changes
 *                         are made:
 *                         1. New structure element 'usDiagPeriod' is added in
 *                            the structure 'Pwm_DiagUnitConfigType'.
 *                         2. Macros 'PWM_TCUT_LOW', 'PWM_TCUT_HIGH',
 *                            'PWM_TIMEOUT_COUNT', 'PWM_PRD_RESET' and
 *                            'PWM_PRDSL_RESET' are added.
 *                         3. Added macros PWM_DIAG_GROUP1 and PWM_DIAG_GROUP2
 *                         4. New structure element 'ucTCR' is added in the
 *                            structure 'Pwm_PwgaRegsMirrorType'.
 *                         5. Added structure 'Pwm_PwgaINTFMaskMirrorType'
 *                         6. Handled QAC warnings.
 * V4.1.1:  21-Sep-2017  : Following changes are made:
 *                         1. As part of ARDAABD-2476,
 *                            a. Structure member Type-prefix is corrected
 *                               based on the data type names as per
 *                               requirement MCAL052.
 *                            b. Structure name is corrected based on data type
 *                               names as per requirement MCAL052.
 *                            c. Meaningful macro definitions are added.
 *                            d. Removed unused macros.
 * V4.1.2:  18-Jun-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3454
 *                            a. Macros PWM_DIAG_MAX_GROUP1_ID,
 *                               PWM_DIAG_MAX_GROUP2_ID and
 *                               PWM_DIAG_MAX_GROUP3_ID are removed.
 *                               Ref: ARDAABD-883.
 *                            b. Macros PWM_INTERRUPT_MASK_DIS and
 *                               PWM_INTERRUPT_MASK_EN are added to access the
 *                               MKxxx bit of ICxxx register.
 *                               Ref: ARDAABD-2158.
 *                            c. Parameters pImrIntrCntlRegs and usImrMaskValue
 *                               are removed from STag_Pwm_ChannelConfigType
 *                               structure.
 *                               Ref: ARDAABD-2158.
 *                            d. Parameters pDiagImrIntrCntlRegs and
 *                               usDiagImrMaskValue are removed from
 *                               STag_Pwm_DiagChannelConfigType structure.
 *                               Ref: ARDAABD-2158.
 *                            e. Memory section
 *                               PWM_<START/STOP>_SEC_CONFIG_DATA_32 is added
 *                               for arrays Pwm_GaaDiagSyncInitMask and
 *                               Pwm_GaaDiagComplexInitMask.
 *                               Ref: ARDAABD-908.
 *                            f. Updated Copyright information.
 *                         2. As per JIRA ticket ARDAABD-2659, macros
 *                            PWM_TAUDB_SIMUL_REWRITE_COMPLETE and
 *                            PWM_TAUJ_SIMUL_REWRITE_COMPLETED are added.
 *                         3. As per JIRA ticket ARDAABD-880, following
 *                            changes are made:
 *                            a. Macros PWM_PWGA_RESETCNT_VALUE and
 *                               PWM_PWGA_RESET_VALUE are added.
 *                            b. Parameter usDiagTimeOutValue is added in the
 *                               Pwm_DiagChannelConfigType structure.
 *                         4. As per JIRA ticket ARDAABD-2492, macros
 *                            PWM_TAUDB_MIN_PERIOD and PWM_TAUJ_MIN_PERIOD are
 *                            added.
 *                         5. As per JIRA ticket ARDAABD-3839, updated
 *                            traceability tags.
 * V4.1.3:  23-Jul-2019  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-2938,
 *                            macros PWM_CKS_MASK is added.
 */
/******************************************************************************/
/* PWM_PBTYPES_H_032:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045               */
/* PWM_PBTYPES_H_028:  EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0018               */
#ifndef PWM_PBTYPES_H
#define PWM_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Macro definitions */
#include "Pwm.h"
#include "Pwm_RegWrite.h"
/* Included for data type uinteger declaration */
#include "rh850_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* PWM_PBTYPES_H_013:  PWM_ESDD_UD_128, EAAR_PN0066_FR_0045                   */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_PBTYPES_AR_RELEASE_MAJOR_VERSION   PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_PBTYPES_AR_RELEASE_MINOR_VERSION   PWM_AR_RELEASE_MINOR_VERSION
#define PWM_PBTYPES_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION

/* PWM_PBTYPES_H_014:  PWM_ESDD_UD_129, EAAR_PN0066_FR_0045                   */
#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_PBTYPES_AR_RELEASE_MAJOR_VERSION   PWM_AR_RELEASE_MAJOR_VERSION
#define PWM_PBTYPES_AR_RELEASE_MINOR_VERSION   PWM_AR_RELEASE_MINOR_VERSION
#define PWM_PBTYPES_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION
#endif

/* Software module version information */
#define PWM_PBTYPES_SW_MAJOR_VERSION       PWM_SW_MAJOR_VERSION
#define PWM_PBTYPES_SW_MINOR_VERSION       PWM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PWM_PBTYPES_H_001:  PWM_ESDD_UD_174                                        */
/* PWM_PBTYPES_H_002:  EAAR_PN0034_FR_0052                                    */
/* MISRA Violation: START Msg(4:0857)-2 */
#define PWM_ZERO                           (uint8)0x00
#define PWM_ONE                            (uint8)0x01
#define PWM_TWO                            (uint8)0x02
#define PWM_THREE                          (uint8)0x03
#define PWM_TCUT_LOW                       (uint8)0x10
#define PWM_TCUT_HIGH                      (uint8)0x20
#define PWM_DIAG_GROUP1                    (uint8)32
#define PWM_DIAG_GROUP2                    (uint8)64
#define PWM_MAX_DIAG_CHANNELS              (uint8)96
#define PWM_DIAG_ONE                       (uint32)0x00000001
#define PWM_TIMEOUT_COUNT                  (uint32)0xFFF

#define PWM_TAUDB_CH_STOPPED               (uint8)0x00
#define PWM_TAUJ_CH_STOPPED                (uint8)0x00
#define PWM_TAUDB_CH_IDLE_STATE            (uint8)0x00
#define PWM_TAUJ_CH_IDLE_STATE             (uint8)0x00
#define PWM_PWGAINTMSK_RESET               (uint32)0xFFFFFFFFU
#define PWM_DIAG_CH_STARTED                (uint8)0x01
#define PWM_DIAG_SIMUL_REWRITE_COMPLETED   (uint8)0x00
#define PWM_PWGA_TRGOUT_DISABLE            (uint8)0x00
#define PWM_PWGA_TRGOUT_ENABLE             (uint8)0x01
#define PWM_RESET_CMOR_REG                 (uint16)0x0000
#define PWM_RESET_TAUDBCDR_REG             (uint16)0x0000
#define PWM_RESET_TAUJCDR_REG              (uint32)0x00000000
#define PWM_CKS_BITS_POSITION              (uint8)14
#define PWM_PWGA_TCBR_REWRITE_COMPLETED    (uint8)0x00
#define PWM_TAUDB_MASK_TPS                 (uint16)0xFFFF
#define PWM_TAUD_MASK_BRS                  (uint8)0xFF
#define PWM_TAUJ_MASK_TPS                  (uint16)0xFFFF
#define PWM_TAUJ_MASK_BRS                  (uint8)0xFF
#define PWM_PWBA_MASK_BRS                  (uint16)0xFFFF
#define PWM_SLPWG_MASK_PWGAPRDSL           (uint32)0xFFFFFFFFUL
#define PWM_PWGA_MASK_CSDR                 (uint16)0xFFFF
#define PWM_PWGA_MASK_CRDR                 (uint16)0xFFFF
#define PWM_PWGA_MASK_CTL                  (uint8)0xFF
#define PWM_PWGA_MASK_TCR                  (uint8)0x01
#define PWM_PWBA_MASK_TE                   (uint8)0xFF
#define PWM_TAUDB_MASK_CDR                 (uint16)0xFFFF
#define PWM_TAUDB_MASK_CMOR                (uint16)0xFFFF
#define PWM_TAUDB_MASK_TE                  (uint16)0xFFFF
#define PWM_TAUJ_MASK_CDR                  (uint32)0xFFFFFFFFUL
#define PWM_TAUJ_MASK_CMOR                 (uint16)0xFFFF
#define PWM_TAUJ_MASK_TE_LOW_NIBBLE        (uint8)0x0F
#define PWM_TAUDB_MASK_TOE                 (uint16)0xFFFF
#define PWM_TAUDB_MASK_TO                  (uint16)0xFFFF
#define PWM_TAUDB_MASK_TOM                 (uint16)0xFFFF
#define PWM_TAUDB_MASK_TOC                 (uint16)0xFFFF
#define PWM_TAUDB_MASK_TOL                 (uint16)0xFFFF
#define PWM_TAUDB_MASK_RDE                 (uint16)0xFFFF
#define PWM_TAUJ_MASK_TOE_LOW_NIBBLE       (uint8)0x0F
#define PWM_TAUJ_MASK_TO_LOW_NIBBLE        (uint8)0x0F
#define PWM_TAUJ_MASK_TOM_LOW_NIBBLE       (uint8)0x0F
#define PWM_TAUJ_MASK_TOC_LOW_NIBBLE       (uint8)0x0F
#define PWM_TAUJ_MASK_TOL_LOW_NIBBLE       (uint8)0x0F
#define PWM_TAUJ_MASK_RDE_LOW_NIBBLE       (uint8)0x0F
#define PWM_PWBA_MASK_TE_LOW_NIBBLE        (uint8)0x0F
#define PWM_TAUJ_MASK_CMOR_LOW_NIBBLE      (uint8)0x0F
#define PWM_PWBA_CLEAR_TE                  (uint8)0x00
#define PWM_PWGA_SIMUL_REWRITE_TRIGGER     (uint8)0x01
#define PWM_PWGA_MASK_PWGAINTMSK           (uint32)0xFFFFFFFFUL
#define PWM_PWGA_MASK_SLPWGA               (uint32)0xFFFFFFFFUL
#define PWM_PWGA_TCBR_REWRITE_TRIGGER      (uint8)0x02
#define PWM_TAUDB_SIMUL_REWRITE_COMPLETE   (uint16)0x0000
#define PWM_TAUJ_SIMUL_REWRITE_COMPLETED   (uint8)0x00
#define PWM_PWGA_RESETCNT_VALUE            (uint16)0x0FFE
#define PWM_PWGA_RESET_VALUE               (uint16)0x0FFF
#define PWM_TAUDB_MIN_PERIOD               (uint16)0x0000
#define PWM_TAUJ_MIN_PERIOD                (uint32)0x00000000

/* Macro for disabling interrupts */
#define PWM_INTERRUPT_MASK_DIS               (uint16)0x0080

/* Macro for enabling interrupts */
#define PWM_INTERRUPT_MASK_EN                (uint16)0xFF7F

#define PWM_TRUE                           (uint8)0x01
#define PWM_FALSE                          (uint8)0x00

#define PWM_INITIALIZED                    1U
#define PWM_UNINITIALIZED                  0U
#define PWM_SYNC_STARTED                   1U
#define PWM_SYNC_NOTSTARTED                0U

/* Macros to avoid Magic numbers */
#define PWM_DBTOC_VALUE             ((((uint32)PWM_VENDOR_ID_VALUE) << 22U) | \
                                     (((uint32)PWM_MODULE_ID_VALUE) << 14U) | \
                                     (((uint32)PWM_SW_MAJOR_VERSION) << 8U) | \
                                     (((uint32)PWM_SW_MINOR_VERSION) << 3U))

/* Macros for Hardware Timer type */
#define PWM_HW_TAUD                        0U
#define PWM_HW_TAUB                        1U
#define PWM_HW_TAUJ                        2U

/* Macros for Timer Mode type */
#define PWM_MASTER_CHANNEL                 0U
#define PWM_SLAVE_CHANNEL                  1U

/* PWM_PBTYPES_H_035: PWM138_Conf, ECUC_Pwm_00138                             */
/* Macro for setting the PWM mode in Control registers */
#define MIN_DUTY_CYCLE                     (uint16)0x0000
#define MAX_DUTY_CYCLE                     (uint16)0x8000
#define PWM_PERIOD_LIMIT                   (uint16)0xFFFF
#define PWM_DUTY_CALC_DIV                  (uint8)0x0F

/* set values */
#define PWM_CORRECTION_MASK                (uint32)0x00007FFF
#define PWM_DIAG_MAX_RESETTRIGGER_MASK     (uint16)0x1FFF
#define PWM_DIAG_MAX_TRIGGER_DELAY         (uint16)0x0FFF
#define PWM_DIAG_MAX_COUNT                 (uint16)0x0FFF

#define PWM_CTDR_DEFAULT_VALUE             (uint16)0x1000
#define PWM_CMOR_MASK                      (uint16)0x3FFF
#define PWM_CKS_MASK                       (uint8)0x03

/* Macro for register masks */
#define PWM_MASK_WORD                   (uint16)0xFFFF
#define PWM_MASK_LOW_NIBBLE             (uint8) 0x0F
#define PWM_MASK_FIRST_BIT              (uint8) 0x01

/* Macro for clearing pending interrupts */
#define PWM_CLEAR_PENDING_INTR_MASK        (uint16)0xEFFF
/* END Msg(4:0857)-2 */

/* PWM_PBTYPES_H_011:  PWM_ESDD_UD_042, EAAR_PN0066_FR_0043                   */
/* PWM_PBTYPES_H_029:  EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030               */
/* PWM_PBTYPES_H_031:  EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066               */

#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
/* MISRA Violation: START Msg(4:3412)-1 */
/* Functionality related to R4.2 and R4.0 */
#define PWM_ENTER_CRITICAL_SECTION(Exclusive_Area) \
SchM_Enter_Pwm_##Exclusive_Area();

#define PWM_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Pwm_##Exclusive_Area();
/* END Msg(4:3412)-1 */
#endif

/* PWM_PBTYPES_H_033:  EAAR_PN0034_NR_0026                                    */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro defined as a multi line operation hence does not     */
/*                 appear to expand to a conventional expression or a         */
/*                 recognized code construct.                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-2 and                           */
/*                 END Msg(4:0857)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Since the size of the array can vary depending on the      */
/*                 configuration, its exact size cannot be stated.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-3 and                           */
/*                 END Msg(4:3684)-3 tags in the code.                        */

/******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* PWM_PBTYPES_H_003:  PWM_ESDD_UD_071                                        */
/* PWM_PBTYPES_H_025:  EAAR_PN0066_FR_0038, EAAR_PN0034_FR_0019               */
/* PWM_PBTYPES_H_030:  EAAR_PN0034_FR_0020, PWM077, SWS_Pwm_00077             */
/*******************************************************************************
**         Data Structure for TAUD/TAUB Unit configuration type               **
*******************************************************************************/
#if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
typedef struct STag_Pwm_TAUDBUnitConfigType
{
  uint8 ucOsCntlRegsIndx;
  uint8 ucUserCntlRegsIndx;
  /* Mask value for all channels in a TAUD/TAUB */
  uint16 usTAUChannelMask;
  /* Mask value for the TOM register based on configuration of channels */
  uint16 usTOMMask;
  /* Mask value for the TOC register based on configuration of channels */
  uint16 usTOCMask;
  /* Mask value for the TOL register based on configuration of channels */
  uint16 usTOLMask;
  /* Mask value for the TO register based on configuration of channels */
  uint16 usTOMask;
  /* Mask value for the TOE register based on configuration of channels */
  uint16 usTOEMask;
  /* TAU Unit prescaler for clock sources CK0, CK1, CK3 and CK4 */
  #if (PWM_TAUD_PRESCALER == STD_ON) || (PWM_TAUB_PRESCALER == STD_ON)
  uint16 usPrescaler;
  #if(PWM_TAUD_PRESCALER == STD_ON)
  /* TAU Unit baudrate value */
  uint8  ucBaudRate;
  /*
   * Prescaler shared between ICU/GPT module
   * blConfigurePrescaler = TRUE Prescaler for CK0-CK3 has to be set by PWM
   * blConfigurePrescaler = FALSE Prescaler for CK0-CK3 need not be set by PWM
   */
  #endif
  /* PWM_PBTYPES_H_017:  EAAR_PN0066_FR_0033, EAAR_PN0066_FR_0034             */
  /* PWM_PBTYPES_H_019:  EAAR_PN0066_FR_0035, EAAR_PN0066_FR_0036             */
  boolean blConfigurePrescaler;
  #endif
  /* PWM_PBTYPES_H_037:  EAAR_PN0066_FR_0031                                  */
  /* PWM Unit type, the channel belongs to TAUD or TAUB or TAUJ */
  uinteger uiPwmTAUType:2;

  #if (PWM_SYNC_START_SUPPORT == STD_ON)
  /* Mask value for all channels in TAUD/TAUB configured to support
     synchronous start/stop of timers */
  uint16 usSyncInitMask;
  /* Mask value for all channels in TAUD/TAUB configured to support complex
     device drivers */
  uint16 usComplexInitMask;
  #endif
} Pwm_TAUDBUnitConfigType;
#endif

/* PWM_PBTYPES_H_004:  PWM_ESDD_UD_072                                        */
/* PWM_PBTYPES_H_020:  EAAR_PN0066_FR_0037                                    */
/*******************************************************************************
**          Data structure for TAUJ Unit configuration type                   **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STag_Pwm_TAUJUnitConfigType
{
  /* Index to base address of TAUJ Os control registers */
  uint8 ucOsCntlRegsIndx;
  /* pointer to base address of TAUJ Unit user control registers */
  uint8 ucUserCntlRegsIndx;
  /* TAU Unit prescaler for clock sources CK0, CK1, CK3 and CK4 */
  #if(PWM_TAUJ_PRESCALER == STD_ON)
  uint16 usPrescaler;
  /* TAU Unit baudrate value */
  uint8  ucBaudRate;
  /*
   * Prescaler shared between ICU/GPT module
   * blConfigurePrescaler = TRUE Prescaler for CK0-CK3 has to be set by PWM
   * blConfigurePrescaler = FALSE Prescaler for CK0-CK3 need not be set by PWM
   */

  /* PWM_PBTYPES_H_018:  EAAR_PN0066_FR_0034, EAAR_PN0066_FR_0035             */
  /* PWM_PBTYPES_H_036:  EAAR_PN0066_FR_0033, EAAR_PN0066_FR_0036             */
  boolean blConfigurePrescaler;
  #endif
  /* Mask value for all channels in a TAUJ*/
  uint8 ucTAUChannelMask;
  /* Mask value for the TOM register based on configuration of channels */
  uint8 ucTOMMask;
  /* Mask value for the TOL register based on configuration of channels */
  uint8 ucTOLMask;
  /* Mask value for the TO register based on configuration of channels */
  uint8 ucTOMask;
  /* Mask value for the TOE register based on configuration of channels */
  uint8 ucTOEMask;
  #if (PWM_SYNC_START_SUPPORT == STD_ON)
  /* Mask value for all channels in TAUJ configured to support synchronous
     start/stop of timers */
  uint8 ucSyncInitMask;
  /* Mask value for all channels in TAUJ configured to support complex
     device drivers */
  uint8 ucComplexInitMask;
  #endif
} Pwm_TAUJUnitConfigType;
#endif

/* PWM_PBTYPES_H_005:  PWM_ESDD_UD_134                                        */
/*******************************************************************************
**          The data structure design will be using separate unit             **
**       STag_Pwm_DiagUnitConfigType which will be defined with following     **
*******************************************************************************/
#if (PWM_DIAG_UNIT_USED  == STD_ON)
typedef struct STag_Pwm_DiagUnitConfigType
{
  /* pointer to base address of PWGA Unit with Start and Stop for multiple
   * channels simultaneously registers
   */
  P2VAR(volatile SLPWGAReg, TYPEDEF, PWM_CONFIG_DATA)  pDiagSyncStartCntlRegs;
  #if (PWM_SYNC_START_SUPPORT == STD_ON)
  /* Mask value of channels to be started synchronously in PWGA unit */
  P2CONST(uint32, TYPEDEF, PWM_CONFIG_DATA)  pDiagSyncStart;
  /* Mask value of channels configured as Complex Device Drivers
     in PWGA unit */
  P2CONST(uint32, TYPEDEF, PWM_CONFIG_DATA)  pDiagComplexInitMask;
  #endif
  /* PWGA Unit prescaler for clock source CK0 */
  uint16 usDiagPrescalerCk0;
  /* PWGA Unit prescaler for clock source CK1 */
  uint16 usDiagPrescalerCk1;
  /* PWGA Unit prescaler for clock source CK2 */
  uint16 usDiagPrescalerCk2;
  /* PWGA Unit prescaler for clock source CK3 */
  uint16 usDiagPrescalerCk3;
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  /* PWM_PBTYPES_H_023:  EAAR_PN0066_FR_0116, EAAR_PN0066_FR_0117             */
  /* PWGA Unit period selection value*/
  uint16 usDiagPeriod;
  #endif
  /* PWGA Unit start trigger for clock sources */
  uint8 ucDiagStartTrgPrescaler;
} Pwm_DiagUnitConfigType;
#endif

/* PWM_PBTYPES_H_006:  PWM_ESDD_UD_074                                        */
/*******************************************************************************
** Structure for configuring 16-bit period value for TAUD/TAUB timers         **
*******************************************************************************/
#if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
typedef struct STag_Pwm_TAUDBProperties
{
  /* Default Period of channel in timer ticks (0 - 2^16) */
  Pwm_PeriodType ddDefaultPeriodOrDuty;
  /* Individual channel mask value */
  uint16 usChannelMask;
} Pwm_TAUDBProperties;
#endif

/* PWM_PBTYPES_H_007:  PWM_ESDD_UD_075                                        */
/*******************************************************************************
**       Structure for configuring 32-bit period value for TAUJ timers        **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STag_Pwm_TAUJProperties
{
  /* Default Period of channel in timer ticks (0 - 2^32) */
  Pwm_PeriodType ddDefaultPeriodOrDuty;
  /* Individual channel mask value */
  uint8 ucChannelMask;
} Pwm_TAUJProperties;
#endif

/* PWM_PBTYPES_H_008:  PWM_ESDD_UD_076, PWM027_Conf, PWM136_Conf, PWM122_Conf */
/* PWM_PBTYPES_H_034:  ECUC_Pwm_00027, ECUC_Pwm_00136, ECUC_Pwm_00137         */
/*******************************************************************************
**            Data structure for PWM channel configuration                    **
*******************************************************************************/
/* PWM_PBTYPES_H_010:  PWM_ESDD_UD_038, EAAR_PN0066_FR_0038, ECUC_Pwm_00122   */
/* PWM_PBTYPES_H_012:  PWM_ESDD_UD_052, PWM137_Conf                           */
#if (PWM_TAU_UNIT_USED  == STD_ON)
typedef struct STag_Pwm_ChannelConfigType
{
  /* Pointer to the PWM Channel properties based on Timer Type */
  P2CONST(void, TYPEDEF, PWM_CONFIG_CONST)pChannelProp;

 /* Index to user base address of Timer control register */
  uint8 ucCntlRegsIndx;

  #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
  /* pointer to base address of Timer Interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)pIntrCntlAddress;
  #endif

  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* PWM_PBTYPES_H_026:  EAAR_PN0066_FR_0077, PWM123_Conf, ECUC_Pwm_00123     */
  /* Pointer to callback notification */
  P2FUNC (void, TYPEDEF, pPwmEdgeNotifPtr)(void);
  #endif

  /*
   * Bit 15-14:    00: This bits are already set during initialization for
   *                   clock source
   * Bit 13-12:    00: Selects the Operation Clock
   * Bit    11:     0: The channel operates as the slave channel in the
   *                   synchronous channel operation function.
   *                1: The channel operates as the master channel in the
   *                   synchronous channel operation function.
   * Bit 10- 8:   000: Valid only in software trigger start.
   *              100: Selects the INTn output signal of the master channel
   *              101: Selects the INTn output signal of the upper channel,
   *                   regardless of the setting of the master
   * Bit  7- 6:    00: Not Used, so set to 00
   * Bit  4- 0: 00001: Interval Timer mode *a
   *            01001: One Count mode *b
   *            10101: Pulse One Count mode *b
   *(Bit 0: *a: Outputs INTn (timer interrupt) at the start of count operation.
   *        *b: Enables start trigger detected during count operation)
   */
  uint16 usCMORegSettingsMask;

  /*
   * Offset with respect to base Timer control register of the master
   * channel of corresponding channel
   */
  uint8 ucMasterOffset;

  /*
   * Timer Unit Index in the Array Pwm_GstTAUDBUnitConfig /
   * Pwm_GstTAUJUnitConfig based on the channel belongs to
   * TAUD or TAUB or TAUJ
   */
  uint8 ucTimerUnitIndex;
  /* PWM_PBTYPES_H_038:  EAAR_PN0066_FR_0031                                  */
  /* PWM channel type, the channel belongs to TAUD or TAUB or TAUJ */
  uinteger uiPwmTAUType:2;
  /*
   * Class type of the PWM channel (Fixed Period /Fixed Period Shifted /
   * Variable period)
   */
  Pwm_ChannelClassType ddClassType;
  /* Idle state of the channel (HIGH/LOW) */
  uinteger uiIdleLevel:1;
  /*
   * uiTimerMode = true means channel acts as master channel
   * uiTimerMode = false means channel acts as slave channel
   */
  /* PWM_PBTYPES_H_039: EAAR_PN0066_FR_0048                                   */
  uinteger uiTimerMode:1;

  #if (PWM_SYNC_START_SUPPORT == STD_ON)
  /*
   * blSyncStartReq = true means channel will be initialized by
   * API Pwm_SynchronousInit
   * blSyncStartReq = false means channel will be initialized by
   * API Pwm_Init
   */
  boolean blSyncStartReq;
  /*
   * blComplexDriverInit = true means channel will be used by complex driver
   * blComplexDriverInit = false means channel will be used by PWM driver
   */
  boolean blComplexDriverInit;
  #endif

  /* Number of slave channels configured for a master channel */
  uint8 ucNumSlaveChannnel;
} Pwm_ChannelConfigType;
#endif

/* PWM_PBTYPES_H_009:  PWM_ESDD_UD_135, EAAR_PN0066_FR_0057                   */
/* PWM_PBTYPES_H_021:  EAAR_PN0066_FR_0064, EAAR_PN0066_FR_0066               */
/* PWM_PBTYPES_H_022:  PWM125_Conf, ECUC_Pwm_00125                            */
/*******************************************************************************
**        Data structure for PWM PWGA channel configuration                   **
*******************************************************************************/
#if (PWM_DIAG_UNIT_USED  == STD_ON)
typedef struct STag_Pwm_DiagChannelConfigType
{
  /* Index to the base address of PWGA Unit Generator control registers */
    uint8 ucDiagGeneratortCntlRegsIndx;
  /* To update PWGAnCSDR register for setting condition for PWGA_TOUTn output */

  #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
  /* pointer to base address of PWGA Interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, PWM_CONFIG_DATA)pDiagIntrCntlAddress;
  #endif

  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* PWM_PBTYPES_H_027:  EAAR_PN0066_FR_0077                                  */
  /* Pointer to callback notification */
  P2FUNC (void, TYPEDEF, pPwmEdgeNotifPtr)(void);
  #endif

  uint16 usOffset;
  /* To update PWGAnCTDR register for set condition of PWGA_TRGOUTn output */
  uint16 usTriggerDelay;
  /* To calculate and update PWGAnCRDR register for reset condition of
   * PWGA_TOUTn output
   */
  uint16 usDutyCycle;
  /* PWM_PBTYPES_H_024:  EAAR_PN0066_FR_0113, EAAR_PN0066_FR_0114             */
  /* To update PWGAnCTL register for selecting count clock from PWBA0 */
  uint8 ucDiagClockCtl;
  /* To represent PWM PWGA output channel selection */
  uint8 ucDiagChannel;

  #if (PWM_SYNC_START_SUPPORT == STD_ON)
  /*
   * blSyncStartReq = true means channel will be initialized by
   * API Pwm_SynchronousInit
   * blSyncStartReq = false means channel will be initialized by
   * API Pwm_Init
   */
  boolean blSyncStartReq;
  /*
   * blComplexDriverInit = true means channel will be used by complex driver
   * blComplexDriverInit = false means channel will be used by PWM driver
   */
  boolean blComplexDriverInit;
  #endif
  /* PWM_PBTYPES_H_040:  EAAR_PN0066_FR_0072                                  */
  /* To represent PWM PWGA channel polarity */
  uint8 ucPolarity;
  /* To update the Loop count value */
  uint16 usDiagTimeOutValue;
  /*
   * blOffsetDelayAdjust = true means offset delay is maintained
   * blOffsetDelayAdjust = false means offset delay is not maintained
   */
  boolean blOffsetDelayAdjust;
} Pwm_DiagChannelConfigType;
#endif

/*******************************************************************************
**        Data structure for PWM TAUDB channels Ram Mirroring                 **
*******************************************************************************/
#if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
#if (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE)
typedef struct STag_Pwm_TAUDBChannelRegMirrorType
{
  /* CDR */
  uint16 usCDR;
  /* CMOR */
  uint16 usCMOR;
} Pwm_TAUDBChannelRegMirrorType;

typedef struct STag_Pwm_TAUDBUserRegMirrorType
{
  /* TOE */
  uint16 usTOE;
  /* TE */
  uint16 usTE;
} Pwm_TAUDBUserRegMirrorType;
#endif
#endif

/*******************************************************************************
**        Data structure for PWM TAUJ channels Ram Mirroring                  **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
#if (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE)
typedef struct STag_Pwm_TAUJChannelRegMirrorType
{
  /* CDR */
  uint32 ulCDR;
  /* CMOR */
  uint16 usCMOR;
} Pwm_TAUJChannelRegMirrorType;

typedef struct STag_Pwm_TAUJUserRegMirrorType
{
  /* TOE */
  uint8 ucTOE;
  /* TE */
  uint8 ucTE;
} Pwm_TAUJUserRegMirrorType;

#endif
#endif

/*******************************************************************************
**        Data structure for PWM PWGA channels Ram Mirroring                  **
*******************************************************************************/
#if (PWM_DIAG_UNIT_USED  == STD_ON)
#if (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE)
typedef struct STag_Pwm_PwgaRegsMirrorType
{
  /* SLPWGA0 */
  uint32 ulSLPWGA0;
  /* SLPWGA1 */
  uint32 ulSLPWGA1;
  /* SLPWGA2 */
  uint32 ulSLPWGA2;
  /* CSDR */
  uint16 usCSDR;
  /* CRDR */
  uint16 usCRDR;
  /* CTL */
  uint8 ucCTL;
  #if (PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON)
  /* TCR */
  uint8 ucTCR;
  #endif
} Pwm_PwgaRegsMirrorType;

#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
typedef struct STag_Pwm_PwgaINTFMaskMirrorType
{
  /* PWGAINTMSK00 */
  uint32 ulPWGAINTMSK00;
  /* PWGAINTMSK01 */
  uint32 ulPWGAINTMSK01;
  /* PWGAINTMSK02 */
  uint32 ulPWGAINTMSK02;
} Pwm_PwgaINTFMaskMirrorType;
#endif
#endif
#endif
/*******************************************************************************
**                      Global configuration constants                        **
*******************************************************************************/

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* PWM_PBTYPES_H_016: PWM_ESDD_UD_137                                         */
#if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
/* MISRA Violation: START Msg(4:3684)-3 */
/* Array of structures for TAUD/B/C Unit Channel Configuration */
extern CONST(Pwm_TAUDBUnitConfigType, PWM_CONST) Pwm_GstTAUDBUnitConfig[];

/* Array of structures for Timer unit D/B channel Configuration */
extern CONST(Pwm_TAUDBProperties, PWM_CONST) Pwm_GstTAUDBChannelConfig[];
/* END Msg(4:3684)-3 */
#endif

#if (PWM_TAUJ_UNIT_USED  == STD_ON)
/* MISRA Violation: START Msg(4:3684)-3 */
/* Array of structures for TAUJ Unit Configuration */
extern CONST(Pwm_TAUJUnitConfigType, PWM_CONST) Pwm_GstTAUJUnitConfig[];

/* Array of structures for Timer unit J channel Configuration */
extern CONST(Pwm_TAUJProperties, PWM_CONST) Pwm_GstTAUJChannelConfig[];
/* END Msg(4:3684)-3 */
#endif

#if (PWM_DIAG_UNIT_USED  == STD_ON)
/* MISRA Violation: START Msg(4:3684)-3 */
/* Array of structures for PWM PWGA Unit Configuration */
extern CONST(Pwm_DiagUnitConfigType, PWM_CONST) Pwm_GstDiagUnitConfig[];

/* Array of structures for PWM PWGA channel Configuration */
extern CONST(Pwm_DiagChannelConfigType, PWM_CONST) Pwm_GstDiagChannelConfig[];
/* END Msg(4:3684)-3 */
#endif

#if (PWM_TAU_UNIT_USED  == STD_ON)
/* MISRA Violation: START Msg(4:3684)-3 */
/* Array of structures for Channel Configuration */
extern CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_GstTAUChannelConfig[];
/* END Msg(4:3684)-3 */
#endif

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#define PWM_START_SEC_CONFIG_DATA_32
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_SYNC_START_SUPPORT == STD_ON)
/* PWM_PBTYPES_H_015:  PWM_ESDD_UD_136                                        */
/* MISRA Violation: START Msg(4:3684)-3 */
/* Array for PWGA Sync start configuration settings  */
extern CONST(uint32, PWM_CONST) Pwm_GaaDiagSyncInitMask[];
/* END Msg(4:3684)-3 */

/* MISRA Violation: START Msg(4:3684)-3 */
/* Array for PWGA Complex Device Driver configuration settings  */
extern CONST(uint32, PWM_CONST) Pwm_GaaDiagComplexInitMask[];
/* END Msg(4:3684)-3 */
#endif

#define PWM_STOP_SEC_CONFIG_DATA_32
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
