/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and structure data types for post build          */
/* parameters of GPT Driver                                                   */
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
 * V1.0.1:  11-Nov-2015    : As per ARDAAGA-76 following changes has been done:
 *                           1. The declaration of variables
 *                              Gpt_GstTAUUnitConfig and Gpt_GstChannelConfig
 *                              are updated.
 *                           2. MISRA comments are added in the file for
 *                              critical section
 *                           3. Updated justification for the MISRA rule
 *                              violation Message (4:3412)
 *
 * V2.0.0:  27-Sep-2016    : Several changes for solving tickets
 *                           1. ARDAABC-751 Change type of ddWakeupSource from
 *                           uint8 to EcuM_WakeupSourceType
 *                           2. ARDAABC-769 Add new macros for Write Verify and
 *                           Ram Mirroring configuration
 *                           3.Removed old macros for read back states
 *                           4.Define the data types of the ram mirrors used for
 *                           dynamic registers.
 *
 * V2.0.1:  27-Oct-2016    : As part of ticket ARDAABC-937, changed storage
 *                           specifier from AUTOMATIC to TYPEDEF where was the
 *                           case.
 *
 * V2.1.0:  28-Oct-2016    : As part of ARDAABC-875 the type of timers
 *                           was extended with GPT_HW_OSTM_FEINT for handling
 *                           OSTM channels which have FE interrupt.Several
 *                           macros for writing to FEINT registers were defined
 *
 * V2.2.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Add several new macros for identifying the enable
 *                           state  and HW unit used by Predef Timer as part
 *                           of ARDAABC-564
 *
 * V2.3.0:  13-Feb-2017   :  Following changes are made:
 *                           1. As part of ARDAABC-978, critical section names
 *                              updated
 *
 * V2.3.1:  20-Jun-2017   :  As part of JIRA ARDAABD-1848, inclusion of
 *                           'EcuM_Types.h' is replaced with 'EcuM.h'.
 *
 * V2.3.2:  07-Jul-2017   :  Following changes are made:
 *                           1. As part of JIRA ARDAABD-1883,
 *                              'STag_Gpt_WakeupFactorType' is updated to add
 *                              'ulWUF1MaskValue' for WUF1 support .
 *                           2. As part of JIRA ARDAABD-1516, new macros added.
 *
 * V2.3.3:  18-Aug-2017    : As part of JIRA ARDAABD-2305, Macros for new OSTM
 *                           Predef timers and macros for distinguishing predef
 *                           channel interrupt types are added.
 *
 * V2.3.4:  18-Oct-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. As part of Jira #ARDAABD-2471,
 *                              naming convention for variables and macros
 *                              updated.
 *                           3. As per ARDAABD-2570, typo errors corrected.
 *
 * V2.3.5:  18-Jun-2018    : As per merging activity #ARDAABD-3489,
 *                           following changes were made:
 *                           1. As per ARDAABD-2158,
 *                              a. GPT_INTERRUPT_MASK_DIS and
 *                              GPT_INTERRUPT_MASK_EN are added to access the
 *                              MKxxx bit of ICxxx register.
 *                              b. pImrIntrCntlAddress is removed from
 *                              STag_Gpt_ChannelConfigType for denying access
 *                              to IMR register.
 *                              c. usImrMaskValue is renamed to usFeIntMaskValue
 *                              for updating FE Interrupt mask register.
 *                           2. Copyright information updated.
 *                           3. As per ARDAABD-3841, traceability updated.
 */
/******************************************************************************/

#ifndef GPT_PBTYPES_H
#define GPT_PBTYPES_H
/* GPT_PBTYPES_H_014: EAAR_PN0034_FR_0001 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Included for Macro definitions */
#include "Gpt.h"
#include "Gpt_Hardware.h"
/* Included for data type integer declaration */
#include "rh850_Types.h"

/* Included for EcuM_WakeupSource type, needed for reporting wakeup only if   **
 * the functionality is present                                               */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM.h"
#endif
/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* GPT_PBTYPES_H_015: EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION  GPT_AR_RELEASE_MAJOR_VERSION
#define GPT_PBTYPES_AR_RELEASE_MINOR_VERSION  GPT_AR_RELEASE_MINOR_VERSION
#define GPT_PBTYPES_AR_RELEASE_REVISION_VERSION  GPT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define GPT_PBTYPES_SW_MAJOR_VERSION    GPT_SW_MAJOR_VERSION
#define GPT_PBTYPES_SW_MINOR_VERSION    GPT_SW_MINOR_VERSION
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
/* 2. QAC Warning:                                                            */
/* Message       : (2:3131) An integer constant has been used to define the   */
/*                 size of a bit-field                                        */
/* Rule          : None                                                       */
/* Justification : These values are used to define the size of structure      */
/*                 address                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3131)-2 and               */
/*                 END Msg(2:3131)-2 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro is being used to adapt the exclusive area API names  */
/*                 of AUTOSAR 4.0 and 3.2 versions                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and END Msg(4:3412)-2 tags in */
/*                 the code.                                                  */

/******************************************************************************/

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
/* Macros for Hardware Timer type */
/* GPT_PBTYPES_H_001: GPT_ESDD_UD_114*/
#define GPT_HW_TAUD                         0u
#define GPT_HW_TAUB                         1u
#define GPT_HW_TAUJ                         2u
#define GPT_HW_OSTM                         3u
#define GPT_HW_OSTM_FEINT                   4u

/* Macros for channel modes */
#define GPT_CH_MODE_ONESHOT                 0u
#define GPT_CH_MODE_CONTINUOUS              1u
#define GPT_CH_MODE_OSTM_CONTINUOUS         0u

/* Macros used for the Global OSTM timer mask value */
#define GPT_OSTM_GLOBAL_MASK                (uint8)0x03

#define GPT_TRUE                            1u
#define GPT_FALSE                           0u
#define GPT_ZERO                            (uint8)0x00
#define GPT_CHANNELID_INIT_VAL              (uint8)0x00
#define GPT_TIMER_INIT_VAL_ZERO             (uint8)0x00
#define GPT_TIMER_RESET_VAL_ZERO            (uint8)0x00
#define GPT_RET_VAL_ZERO                    (uint8)0x00
#define GPT_ONE                             (uint16)0x0001
#define GPT_INITIALIZED                     (boolean)0x01
#define GPT_UNINITIALIZED                   (boolean)0x00

/* Reset values */
#define GPT_RESET_BYTE                      (uint8)0x00
#define GPT_RESET_TAU_RDE_BYTE              (uint8)0x00
#define GPT_RESET_TAU_RDM_BYTE              (uint8)0x00
#define GPT_RESET_TAU_CMUR_BYTE             (uint8)0x00
#define GPT_RESET_TAU_BRS_BYTE              (uint8)0x00
#define GPT_RESET_TAU_TOE_BYTE              (uint8)0x00
#define GPT_RESET_TAU_TE_BYTE               (uint8)0x00
#define GPT_RESET_OSTM_CTL_BYTE             (uint8)0x00
#define GPT_RESET_OSTM_TE_BYTE              (uint8)0x00
#define GPT_RESET_WORD                      (uint16)0x0000
#define GPT_TAUDB_RDE_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_RDS_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_RDM_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_RDC_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_CDR_RESET_VAL             (uint16)0x0000
#define GPT_TAUJ_CMOR_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_TOE_RESET_VAL             (uint16)0x0000
#define GPT_TAUDB_TE_RESET_VAL              (uint16)0x0000
#define GPT_TAUDB_CMOR_RESET_VAL            (uint16)0x0000
#define GPT_RESET_LONG_WORD                 0x00000000uL
#define GPT_WUF0_RESET_VAL                  0x00000000uL
#define GPT_OSTM_CMP_RESET_VAL              0x00000000uL
#define GPT_TAUJ_CDR_RESET_VAL              0x00000000uL

/* Macros for WUF clearing */
#define GPT_DOUBLE_ZERO                     (uint32)0x00000000uL
#define GPT_DOUBLE_ONE                      (uint32)0x00000001uL

/* set values */
#define GPT_SET_WORD                        (uint16)0xFFFF
#define GPT_TAUD_TPS_SET_VAL                (uint16)0xFFFF
#define GPT_TAUJ_TPS_SET_VAL                (uint16)0xFFFF
#define GPT_MAX_OSTM_VAL                    0xFFFFFFFFuL

#define GPT_8BIT_MASK                       0xFFu
#define GPT_TAU_BRS_8BIT_MASK               0xFFu
#define GPT_16BIT_MASK                      0xFFFFu
#define GPT_TAU_TPS_16BIT_MASK              0xFFFFu
#define GPT_TAU_CMOR_16BIT_MASK             0xFFFFu
#define GPT_TAU_CDR_16BIT_MASK              0xFFFFu
#define GPT_24BIT_MASK                      0xFFFFFFu
#define GPT_32BIT_MASK                      0xFFFFFFFFuL
#define GPT_OSTM_CMP_32BIT_MASK             0xFFFFFFFFuL
#define GPT_TAU_CDR_32BIT_MASK              0xFFFFFFFFuL

/* Register specific masks */

/* GPT_OSTM_CTL_MASK
 * 0 OSTMnMD0
 * 1 OSTMnMD1
 * 2-7 Reserved*/
#define GPT_OSTM_CTL_MASK                   0x3u

/* GPT_TAU_CMUR_MASK
 * 0-1 TAUxnTIS
 * 2-7 Reserved*/
#define GPT_TAU_CMUR_MASK                   0x3u

/* Macros to avoid Magic numbers */
#define GPT_DBTOC_VALUE \
    (uint32)((((uint32)GPT_VENDOR_ID_VALUE << 22U)) | \
        (((uint32)GPT_MODULE_ID_VALUE << 14U)) | \
        (((uint32)GPT_SW_MAJOR_VERSION << 8U)) | \
        (((uint32)GPT_SW_MINOR_VERSION << 3U)))

/* Macros for masks */
#define GPT_OSTM_START_MASK                  (uint8)0x01
#define GPT_OSTM_STOP_MASK                   (uint8)0x01

#define GPT_NOTIFICATION_ENABLED             1u
#define GPT_NOTIFICATION_DISABLED            0u

#define GPT_WAKEUP_NOTIFICATION_ENABLED      1u
#define GPT_WAKEUP_NOTIFICATION_DISABLED     0u

/* Macros to hold timer status */
#define GPT_CH_NOTSTARTED                    (uint8)0x00
#define GPT_CH_RUNNING                       (uint8)0x01
#define GPT_CH_STOPPED                       (uint8)0x02
#define GPT_CH_EXPIRED                       (uint8)0x03

#define GPT_CHANNEL_UNCONFIGURED             (uint8)0xFF

/* Macro for clearing pending interrupts */
#define GPT_CLEAR_PENDING_INTR_MASK          (uint16)0xEFFF

/* Macro to check interrupt request flag */
#define GPT_CHECK_INTR_REQUEST_MASK          (uint16)0x1000

/* Macro for disabling interrupts */
#define GPT_INTERRUPT_MASK_DIS               (uint16)0x0080

/* Macro for enabling interrupts */
#define GPT_INTERRUPT_MASK_EN                (uint16)0x007F

/* Macros used to define register size  used by enable/disable/clear interrupt
 * function*/
#define GPT_REG_SIZE_8BIT                   8u
#define GPT_REG_SIZE_16BIT                  16u
#define GPT_REG_SIZE_32BIT                  32u

/* Macro for which wakeup not configured */
#define GPT_NOWAKEUP                         (EcuM_WakeupSourceType)0x00000000

/* GPT WriteVerify Configuration */
#define GPT_WV_DISABLE           0u
#define GPT_WV_INIT_ONLY         1u
#define GPT_WV_INIT_RUNTIME      2u

/* GPT RamMirroring Configuration */
#define GPT_MIRROR_DISABLE           0u
#define GPT_MIRROR_ENABLE            1u

/* Macros for distinguishing predef channel interrupt type */
#define GPT_PREDEF_TIMER_EI_INTR     0u
#define GPT_PREDEF_TIMER_FE_INTR     1u

/* Macros for distinguishing critical protection usage.*/
#define GPT_INCLUDE_CRITICAL_SECTION  (boolean)1
#define GPT_EXCLUDE_CRITICAL_SECTION  (boolean)0

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)

/* GPT Predefined Timers Configuration */
/* GPT_PBTYPES_H_013: SWS_Gpt_00385, ECUC_Gpt_00334 */
#define GPT_PREDEF_TIMER_1US_DISABLED                 0u
#define GPT_PREDEF_TIMER_1US_16BIT_ENABLED            1u
#define GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED         2u
#define GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED      3u

#define GPT_PREDEF_TIMER_CHANNEL_OSTM0                0u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM1                1u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM2                2u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM3                3u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM4                4u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM5                7u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM6                8u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM7                9u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM8                10u
#define GPT_PREDEF_TIMER_CHANNEL_OSTM9                11u

#endif /*(GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
/* GPT_PBTYPES_H_016: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030 */
/* GPT_PBTYPES_H_017: EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
/* MISRA Violation: START Msg(4:3412)-2 */
#define GPT_ENTER_CRITICAL_SECTION(Exclusive_Area) \
    SchM_Enter_Gpt_##Exclusive_Area();

#define GPT_EXIT_CRITICAL_SECTION(Exclusive_Area) \
    SchM_Exit_Gpt_##Exclusive_Area();
/* END Msg(4:3412)-2 */

/*******************************************************************************
 *                        DEM TYPE CASTING                                     *
 ******************************************************************************/
/* Macros for DEM */
#define GPT_DEM_TYPE Dem_EventStatusType

/******************************************************************************/
/* GPT_PBTYPES_H_020: EAAR_PN0034_FR_0020 */
/*******************************************************************************
 ** Structure for TAU  Unit configuration type                                **
 ******************************************************************************/
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
typedef struct STag_Gpt_TAUUnitConfigType
{
  /* Pointer to base address of TAU Unit user control registers */
  uint8 ucTAUUnitUserCntlRegIndex;
  /* Pointer to base address of TAU Unit os control registers */
  uint8 ucTAUUnitOsCntlRegIndex;
  /* TAU Channels Mask value */
  uint16 usTAUChannelMaskValue;
  /* TAU Unit pre scalar for clock sources CK0, CK1, CK3 and CK4 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  uint16 usPrescaler;
#if ((GPT_TAUD_UNIT_CONFIG == STD_ON) || (GPT_TAUJ_UNIT_CONFIG == STD_ON))
  /* TAU Unit baud rate value */
  uint8 ucBaudRate;
  /* Pre scalar shared between ICU/GPT module
   * blConfigurePrescalar = TRUE Pre scalar for CK0-CK3 has to be set by GPT
   * blConfigurePrescalar = FALSE Pre scalar for CK0-CK3 need not be set by GPT
   */
#endif
  boolean blConfigurePrescaler;
#endif
} Gpt_TAUUnitConfigType;

#endif
/*******************************************************************************
 **                         Structure for GPT Channel RAM data                **
 ******************************************************************************/
typedef struct STag_Gpt_ChannelRamData
{
  /* RAM used to maintain timer status */
  uint8 ucChannelStatus;
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* RAM used to store Notification status */
  uinteger uiNotifyStatus:1;
#endif
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  /* RAM used to store Wakeup Notification status */
  uinteger uiWakeupStatus:1;
  /* RAM used to store Wakeup Occurrence status */
  volatile uinteger uiGptWakeupOccurrence:1;
#endif
} Gpt_ChannelRamData;


/*******************************************************************************
 ** Structure for channel information                                         **
 ******************************************************************************/
typedef struct STag_Gpt_ChannelConfigType
{
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* If the value is equal to GPT_NO_CBK_CONFIGURED then the callback
   * function is not configured. If the value is other than
   * GPT_NO_CBK_CONFIGURED, it indicates index to the configured
   * call back function in the array Gpt_GstChannelNotifFunc
   */
  /* GPT_PBTYPES_H_002: GPT086, GPT362 */
  /* GPT_PBTYPES_H_003: SWS_Gpt_00086, SWS_Gpt_00362 */
  /* Pointer to callback notification function */
  P2FUNC (void, GPT_APPL_CODE, pGptNotificationPointer)(void);
#endif
  /* Offset index of channel user control register */
  uint8 ucBaseCtlRegIndex;
  /* GPT_PBTYPES_H_018: EAAR_PN0034_FR_0081 */
  /* Pointer to Timer Interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, GPT_CONFIG_DATA)pIntrCntlAddress;
  /* GPT_PBTYPES_H_004: GPT332_Conf */
  /* GPT_PBTYPES_H_005: ECUC_Gpt_00332 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  uint32 ulMaxTickVal;
#endif

  /* Individual channel mask value */
  uint16 usChannelMask;
  /* GPT_PBTYPES_H_006: GPT330_Conf */
  /* GPT_PBTYPES_H_007: ECUC_Gpt_00330, EAAR_PN0080_FR_0019 */
  /* For channels belonging to TAUD/TAUB/TAUJ
   * Bit 3-0: 0001: if GPT_CH_MODE_CONTINUOUS/GPT_CH_MODE_ONESHOT
   */
  /* Other bits should be generated with 0 */
  uint16 usModeSettingsMask;
  /* Channel Wakeup Source */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType ddWakeupSource;
#endif

  /* FE Interrupt mask value */
  uint16 usFeIntMaskValue;

  /* Timer Unit Index in the array Gpt_GstTAUDUnitConfig or
   * Gpt_GstTAUJUnitConfig */
  uint8 ucTimerUnitIndex;

  /* Type of GPT timer (TAUD/TAUB/TAUJ/OSTM/OSTM_FEINT) */
  /* QAC Warning: START Msg(2:3131)-2 */
  uinteger uiTimerType:3;
  /* END Msg(2:3131)-2 */
  /* GPT_PBTYPES_H_008: GPT311_Conf */
  /* GPT_PBTYPES_H_009: ECUC_Gpt_00311 */
  /* Enabling wakeup capability of CPU for a channel when timeout occurs */
  uinteger uiGptWakeupSupport:1;
  /* GPT_PBTYPES_H_010: GPT309_Conf */
  /* GPT_PBTYPES_H_011: ECUC_Gpt_00309 */
  uinteger uiGptChannelMode:1;
} Gpt_ChannelConfigType;


/*******************************************************************************
 ** Data structures for Wake Up Factor registers                              **
 ******************************************************************************/
#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
typedef struct STag_Gpt_WakeupFactorType
{
  /* WUF0 Mask Value */
  uint32 ulWUF0MaskValue;
#if (GPT_WUF1_SUPPORTED == STD_ON)
  /* WUF1 Mask Value */
  uint32 ulWUF1MaskValue;
#endif
  /* WUF20 Mask Value */
  uint32 ulWUF20MaskValue;
}Gpt_WakeupFactorType;
#endif /* End of (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) */

/*******************************************************************************
 ** Structures for RAM mirroring of dynamic registers                         **
 ******************************************************************************/

typedef struct STag_OSTMUnitUserRegsMirror
{
  uint32 ulCMP;                                  /* CMP              */
  uint8 ucTE;                                   /* TE               */
}OSTMRegMirror;

typedef struct STag_TAUDBUnitUserRegMirror
{
  uint16 usTE;                                  /* TE               */
}TAUDBUserRegMirror;

typedef struct STag_TAUDBUserRegMirror
{
  uint16 usCDR;                                 /* CDR              */
}TAUDBChRegMirror;

typedef struct STag_TAUJUserRegMirror
{
  uint32 ulCDR;                                  /* CDR              */
}TAUJChRegMirror;

typedef struct STag_TAUJUnitUserRegMirror
{
  uint8 ucTE;                                   /* TE               */
}TAUJUserRegMirror;

/*******************************************************************************
 **                      Global configuration constants                       **
 ******************************************************************************/
/* GPT_PBTYPES_H_019: GPT_ESDD_UD_127 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of Wake up Factors */
extern CONST(Gpt_WakeupFactorType, GPT_CONST) Gpt_GstWakeUpFactor[];
/* END Msg(4:3684)-1 */

#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))

/* MISRA Violation: START Msg(4:3684)-1 */
/* Array of structures for TAU Unit Channel Configuration */
extern CONST(Gpt_TAUUnitConfigType, GPT_CONST) Gpt_GstTAUUnitConfig[];
/* END Msg(4:3684)-1 */

#endif

/* MISRA Violation: START Msg(4:3684)-1 */
/* Array of structures for Channel Configuration */
extern CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_GstChannelConfig[];
/* END Msg(4:3684)-1 */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of Channel data */
extern VAR(Gpt_ChannelRamData, GPT_NOINIT_DATA) Gpt_GstChannelRamData[];
/* END Msg(4:3684)-1 */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include GPT_MEMMAP_FILE
/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#endif /* GPT_PBTYPES_H */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
