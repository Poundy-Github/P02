/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and structure data types for post build          */
/* parameters of ICU Driver                                                   */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V1.0.1:  10-Nov-2015  : As part of F1K V4.00.01 development activity,
 *                         following changes are made,
 *                         1. Removed unused type definition for
 *                            Icu_WakeupFactorRegs .
 * V1.0.2:  02-Jun-2016  : #ARDAABD-426
 *                         1. Modified wakeup source types to
 *                            EcuM_WakeupSourceType
 *                         2. Modified ICU_NOWAKEUP to
 *                            (EcuM_WakeupSourceType) 0x00000000 as per
 *                            ECUM04040
 * V1.0.3:  13-Jun-2016  : #ARDAABD-413
 *                         1. Removed blChannelEdgeDetectStatus from
 *                            Icu_ChannelRamDataType , added
 *                            uiChannelMeasurementRunning in its place
 * V1.0.4:  12-Sep-2016  : #ARDAABD-666
 *                         1. Corrected copyright information
 *                         2. Modified ICU_CLEAR_PENDING_INTR_MASK to 16 bit
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  07-Oct-2016  : #ARDAABD-853
 *                         1. Added SchM functions compliant w. SWS_Rte_07250
 * V2.0.2:  26-Nov-2016  : #ARDAABD-841
 *                         1. Added volatile keyword to pPreviousInputCntlRegs
 * V2.0.3:  05-Dec-2016  : #ARDAABD-853
 *                         1. Added precompile switch for Critical Section
 *                            macros
 * V2.0.4:  06-Dec-2016  : #ARDAABD-583
 *                         1. Added DET_ICU_E_PARAM_VALUE
 *                         2. Removed usMirrorTAUDBnCDRm register from
 *                            Icu_TAUDBChannelRegMirror
 * V2.0.5:  12-Dec-2016  : #ARDAABD-583
 *                         1. Replaced macros for Mask the bypass bits to have
 *                            the suffix FILTER (ex: ICU_BYPASS_FILTER)
 * V2.0.6:  16-Mar-2017  : #ARDAABD-1206
 *                         1. Added traceability
  * V2.0.7: 11-Jul-2017  : 1. As part of Jira #ARDAABD-1373,
 *                            ulWUF1MaskValue is added in structure
 *                            Icu_WakeupFactorType
 *                         2. As part of Jira #ARDAABD-1921,
 *                            uiResultComplete is added in structure
 *                            Icu_ChannelRamDataType.
 * V2.0.8:  16-Oct-2017  : 1. As part of Jira #ARDAABD-2444,
 *                            naming convention for variables and macros
 *                            updated.
 *                         2. As part of Jira #ARDAABD-2571,
 *                            Removed unused macros ICU_TIMER_RESET_VAL and
 *                            ICU_ENABLE_INTR_MASK.
 *                         3. As part of Jira #ARDAABD-2571, array size defined
 *                            for Icu_GaaReg_8bit and Icu_GaaRegMirror_8bit
 * V2.0.9:  05-Jul-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Mapping of memory section for global or static
 *                               variables are updated as per the AUTOSAR
 *                               memory mapping requirement MEMMAP022.
 *                               Ref:ARDAABD-908
 *                            b. Added macros ICU_INTERRUPT_MASK_EN and
 *                               ICU_INTERRUPT_MASK_DIS and removed structure
 *                               elements pImrIntrCntlAdress and usImrMaskValue
 *                               from Icu_ChannelConfigType.Ref:ARDAABD-2158
 *                            c. Copyright information is updated.
 *                         2. Storage specifier for configuration data
 *                            variables is changed from AUTOMATIC to TYPEDEF,
 *                            since it is allocated in ROM. Ref:ARDAABD-894
 *                         3. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 * V2.0.10:  27-Sep-2018  : Following changes are made:
 *                         1. Add traceability tags in the corresponding place
 *                            for reqtify improvement.
 * V2.0.11:  12-Aug-2019  : Following changes are made:
 *                         1. "uiConfigurePrescaler" is changed to
 *                            "blConfigurePrescaler", and data type is changed
 *                            to boolean.
 *                            Ref:ARDAABD-3442
 */
/******************************************************************************/
#ifndef ICU_PBTYPES_H
#define ICU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ICU_PBTYPES_H_025:   ICU254, SWS_Icu_00254, ICU253, SWS_Icu_00253   */
/* Included for Macro definitions */
#include "Icu.h"
/* Included for data type uinteger declaration */
#include "rh850_Types.h"
#include "Icu_Hardware.h"
#include "Icu_RegWrite.h"


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Since the size of the array can vary depending on the      */
/*                 configuration, its exact size cannot be stated.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */

/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 - program*/
/*                 does not conform strictly to ISO:C99.                      */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-2 and                           */
/*                 END Msg(4:0857)-2 tags in the code.                        */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_PBTYPES_AR_RELEASE_MAJOR_VERSION  ICU_AR_RELEASE_MAJOR_VERSION
#define ICU_PBTYPES_AR_RELEASE_MINOR_VERSION  ICU_AR_RELEASE_MINOR_VERSION
#define ICU_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                              ICU_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ICU_PBTYPES_SW_MAJOR_VERSION  ICU_SW_MAJOR_VERSION
#define ICU_PBTYPES_SW_MINOR_VERSION  ICU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Macro for ICU_TRUE */
#define ICU_TRUE                            (boolean)0x01
/* Macro for ICU_FALSE */
#define ICU_FALSE                           (boolean)0x00
/* Macro for ICU_INITIALIZED */
#define ICU_INITIALIZED                     (boolean)0x01
/* Macro for ICU_UNINITIALIZED */
#define ICU_UNINITIALIZED                   (boolean)0x00
#define ICU_SYNC_STARTED                    (boolean)0x01
#define ICU_SYNC_NOTSTARTED                 (boolean)0x00

/* Macro to avoid Magic numbers */
/* Macro for ICU_DBTOC_VALUE */
#define ICU_DBTOC_VALUE (uint32)(((uint32)ICU_VENDOR_ID_VALUE << 22U) | \
                                  ((uint32)ICU_MODULE_ID_VALUE << 14U) | \
                                  ((uint32)ICU_SW_MAJOR_VERSION_VALUE << 8U) | \
                                  ((uint32)ICU_SW_MINOR_VERSION_VALUE << 3U))

/* ICU_PBTYPES_H_052:  ICU_ESDD_UD_139 */
/* Macro for external interrput */
#define ICU_HW_EXT_INTP                     (uint8)0x00
/* Macro for TAUD timer unit */
#define ICU_HW_TAUD                         (uint8)0x01
/* Macro for TAUB timer unit */
#define ICU_HW_TAUB                         (uint8)0x02
/* Macro for TAUJ timer unit */
#define ICU_HW_TAUJ                         (uint8)0x03

/* Macro for Normal port type */
#define ICU_NORMAL_PORT                     (uint8)0x00
/* Macro for Jtag port type */
#define ICU_JTAG_PORT                       (uint8)0x01

/* Macro for Zero */
#define ICU_ZERO                            (uint8)0x00
/* Macro for One */
#define ICU_ONE                             (uint8)0x01
/* Macro for Two */
#define ICU_TWO                             (uint8)0x02

/* Macro for 32bit Zero*/
#define ICU_DOUBLE_ZERO                     (uint32)0x00000000

/* Macro for down count value to CDR register */
#define ICU_TAUDB_START_DWNCNT_VAL          (uint16)0xFFFF
/* Macro for Edge count value to CDR register */
#define ICU_TAUDB_EDGE_CNT_VAL              (uint16)0x0000

/*Macro for  Mask the bypass bits of filter control register */
#define ICU_BYPASS_FILTER                   (uint8)0x00
/* Macro  for Set the both edge detection bits in the filter control register */
#define ICU_BOTH_EDGES_FILTER               (uint8)0x03
/*Macro for Set the falling edge detection bits in the filter control register*/
#define ICU_FALLING_EDGE_FILTER             (uint8)0x02
/*Macro for Set the rising edge detection bits in the filter control register */
#define ICU_RISING_EDGE_FILTER              (uint8)0x01

/* Macro for circular Buffer Mask */
#define ICU_TS_CIRCULAR_BUFFER_MASK         (uint8)0x08
/* Macro for duty cycle measurement */
#define ICU_DUTY_PERIOD_ENABLED_MASK        (uint8)0x04
/* Macro for High measurement */
#define ICU_HIGH_TIME_MASK                  (uint8)0x01
/* Macro for Low measurement */
#define ICU_LOW_TIME_MASK                   (uint8)0x00
/* Macro for clearing pending interrupts */
#define ICU_CLEAR_PENDING_INTR_MASK         (uint16)0xEFFF

/* Macro to enable the interrupt request bit MKxxx in ICR */
#define ICU_INTERRUPT_MASK_EN               (uint16)0xFF7FU
/* Macro to disable the interrupt request bit MKxxx in ICR */
#define ICU_INTERRUPT_MASK_DIS              (uint16)0x0080U

/* Macro for High or Low measurement */
#define ICU_HIGH_LOW_TIME_MASK              (uint8)0x03

/* Macro for which wakeup not configured */
/* EcuM04040 */
#define ICU_NOWAKEUP                        (EcuM_WakeupSourceType) 0x00000000

/* Macro for minimum value of notify interval input */
#define ICU_NOTIFY_INTERVAL_MIN_VAL         (uint8)0x01

/* Macro for start value of buffer index */
#define ICU_BUFFER_IDX_INIT_VAL             (uint8)0x00

/* Macro for Reset value of timestamp events captured */
#define ICU_TIMESTAMP_RESET_CNT_VAL         (uint8)0x00

/* Macro for Init counter value of channel configured edge count mode */
#define ICU_EDGE_CNT_INIT_VAL               (uint8)0x00

/* Macro for Write reset value of time captured */
#define ICU_SIGNAL_TIME_INIT_VAL            (uint32)0x00

/* Macro for Write reset value of active time captured */
#define ICU_ACTIVE_TIME_RESET_VAL           (uint8)0x00

/* Macro for Write reset value of period time captured */
#define ICU_PERIOD_TIME_RESET_VAL           (uint8)0x00

/* Macro for reset value of register TAUDBnCMORm */
#define ICU_TAUDB_CMOR_RESET_VAL            (uint16)0x0000

/* Macro for reset value of register TAUJnCMORm */
#define ICU_TAUJ_CMOR_RESET_VAL            (uint16)0x0000

/* Macro for reset value of register TAUDBnCMURm */
#define ICU_TAUDB_CMUR_RESET_VAL            (uint8)0x00

/* Macro for reset value of register TAUJnCMURm */
#define ICU_TAUJ_CMUR_RESET_VAL            (uint8)0x00

/* Macro for start up counter value of register TAUDBnCDRm */
#define ICU_TAUDB_CDR_RESET_VAL             (uint16)0x0000

/* Macro for reset value of register TAUDBnTE */
#define ICU_TAUDB_TE_RESET_VAL             (uint16)0x0000

/* Macro for reset value of register TAUJnTE */
#define ICU_TAUJ_TE_RESET_VAL              (uint8)0x00

/* Macro for reset Channel Status Clear Trigger Register TAUDBnCSCm */
#define ICU_TAUDB_CSC_RESET_VAL            (uint8)0x01

/* Macro for reset Channel Status Clear Trigger Register TAUDBnCSRm */
#define ICU_TAUDB_CSR_RESET_VAL            (uint8)0x00

/* Macro for reset Channel Status Clear Trigger Register TAUJnCSRm */
#define ICU_TAUJ_CSR_RESET_VAL            (uint8)0x00

/* Macro for reset Channel Status Clear Trigger Register TAUJnCSCm */
#define ICU_TAUJ_CSC_RESET_VAL             (uint8)0x01

/* Macro for start up counter value of register TAUJnCDRm */
#define ICU_TAUJ_CDR_RESET_VAL             (uint32)0x00000000

/* Macro for reset FCLAnCTL register */
#define ICU_FCLA_CTL_RESET_VAL         (uint8)0x00

/*******************************************************************************
**               SchM Critical Section Protection Macros                      **
*******************************************************************************/
/* ICU_PBTYPES_H_024: ICU_ESDD_UD_045, EAAR_PN0034_FR_0061 */
#if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* R4.2: SWS_Rte_07250, R4: rte_sws_7250 */
  /*  SchM Critical Section Protection Macro for Higher Version */
  #define ICU_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                  SchM_Enter_Icu_##Exclusive_Area()
  #define ICU_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                  SchM_Exit_Icu_##Exclusive_Area()
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Data structures for Wake Up Factor registers                               **
*******************************************************************************/
#if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* ICU_PBTYPES_H_001: ICU_ESDD_UD_159                                         */
typedef struct STag_Icu_WakeupFactorType
{
  /* WUF0 Mask Value */
  uint32 ulWUF0MaskValue;
  /* WUF1 Mask Value */
  uint32 ulWUF1MaskValue;
  /* WUF20 Mask Value */
  uint32 ulWUF20MaskValue;
}Icu_WakeupFactorType;
#endif /* End of (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) */

/*******************************************************************************
** Structure for TAU Unit configuration type                                  **
*******************************************************************************/
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
    (ICU_TAUB_UNIT_USED == STD_ON))
/* ICU_PBTYPES_H_002: ICU_ESDD_UD_057                                         */
typedef struct STag_Icu_TAUUnitConfigType
{
  uint8 ucTAUUserCntlRegIndx;

  uint8 ucTAUOsCntlRegIndx;


  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
  /* TAU Unit prescaler for clock sources CK0, CK1, CK2, CK3 */
  uint16 usPrescaler;
  #endif
  /* TAUnit type
   * ICU_HW_TAUD - 0
   * ICU_HW_TAUB - 1
   * ICU_HW_TAUJ - 2
   */
  uint8  ucIcuUnitType;
  #if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)
  /* Mask value for all channels in a TAU for synchronous start*/
  uint16 usTAUSyncMaskValue;
  #endif
  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
  #if ((ICU_TAUD_UNIT_CONFIG == STD_ON) || (ICU_TAUJ_UNIT_CONFIG == STD_ON))
  /* TAU Unit baudrate value for CK3 */
  uint8 ucBaudRate;
  /* Prescaler shared between PWM/GPT/ICU modules
   * 1: Prescaler for CK0 - CK3 has to be set by ICU
   * 0: Prescaler for CK0 - CK3 need not be set by ICU
   */
  #endif
  boolean blConfigurePrescaler:1;
  #endif
} Icu_TAUUnitConfigType;
#endif
/*******************************************************************************
** Structure for using previous input(the spilt of one Port pin signal to two **
** TAU inputs): Applicable to TAUD0 only                                      **
*******************************************************************************/
/* ICU_PBTYPES_H_022: ICU_ESDD_UD_037 */
#if (ICU_PREVIOUS_INPUT_USED == STD_ON)
/* ICU_PBTYPES_H_003: ICU_ESDD_UD_058                                         */
typedef struct STag_Icu_PreviousInputUseType
{
  /* void pointer to base address of Previous Input control registers
   */
  P2VAR(volatile void, TYPEDEF, ICU_CONFIG_DATA) pPreviousInputCntlRegs;
  /* Registers SELB_TAUD0I:
   * Bit0: 1: Port TAUD0I1 pin signal is split into  TAUDTTIN0 & TAUDTTIN1
   * Bit1: 1: Port TAUD0I0 pin signal is split into  TAUDTTIN0 & TAUDTTIN1
   * Bit2: 1: Port TAUD0I3 pin signal is split into  TAUDTTIN2 & TAUDTTIN3
   * Bit3: 1: Port TAUD0I2 pin signal is split into  TAUDTTIN2 & TAUDTTIN3
   * Bit4: 1: Port TAUD0I5 pin signal is split into  TAUDTTIN4 & TAUDTTIN5
   * Bit5: 1: Port TAUD0I4 pin signal is split into  TAUDTTIN4 & TAUDTTIN5
   * Bit6: 1: Port TAUD0I7 pin signal is split into  TAUDTTIN6 & TAUDTTIN7
   * Bit7: 1: Port TAUD0I6 pin signal is split into  TAUDTTIN6 & TAUDTTIN7
   * Bit8: 1: Port TAUD0I9 pin signal is split into  TAUDTTIN8 & TAUDTTIN9
   * Bit9: 1: Port TAUD0I8 pin signal is split into  TAUDTTIN8 & TAUDTTIN9
   * Bit10: 1: Port TAUD0I11 pin signal is split into  TAUDTTIN10 & TAUDTTIN11
   * Bit11: 1: Port TAUD0I10 pin signal is split into  TAUDTTIN10 & TAUDTTIN11
   * Bit12: 1: Port TAUD0I13 pin signal is split into  TAUDTTIN12 & TAUDTTIN13
   * Bit13: 1: Port TAUD0I12 pin signal is split into  TAUDTTIN12 & TAUDTTIN13
   * Bit14: 1: Port TAUD0I15 pin signal is split into  TAUDTTIN14 & TAUDTTIN15
   * Bit15: 1: Port TAUD0I14 pin signal is split into  TAUDTTIN14 & TAUDTTIN15
   */
  uint16 usPreviousInputMask;
} Icu_PreviousInputUseType;
#endif

/*******************************************************************************
** Structure to channel data into RAM                                         **
*******************************************************************************/
/* ICU_PBTYPES_H_004: ICU_ESDD_UD_059                                         */
typedef struct STag_Icu_ChannelRamDataType
{
  uinteger uiChannelStatus:1;
  uinteger uiWakeupEnable:1;
  uinteger uiNotificationEnable:1;
  uinteger uiChannelMeasurementRunning:1;
  uinteger uiResultComplete:1;
} Icu_ChannelRamDataType;

/*******************************************************************************
** Structure to store Edge Counting channel data into RAM                     **
*******************************************************************************/
/* ICU_PBTYPES_H_005: ICU_ESDD_UD_060                                         */
typedef struct STag_Icu_EdgeCountChannelRamDataType
{
  uinteger uiTimerOvfFlag:1;
  uint16 usIcuEdgeCount;
} Icu_EdgeCountChannelRamDataType;

/*******************************************************************************
** Structure to store Timestamp channel data into RAM                        **
*******************************************************************************/
/* ICU_PBTYPES_H_006: ICU_ESDD_UD_061                                         */
/* ICU_PBTYPES_H_051: ICU216, SWS_Icu_00216                                   */
/* ICU_PBTYPES_H_053:  ICU_ESDD_UD_131 */
/* Implementation for Icu_TimestampNotification interval */
typedef struct STag_Icu_TimeStampChannelRamDataType
{
  P2VAR(uint32, TYPEDEF, ICU_CONFIG_DATA) pBufferPointer;
  uint16 usBufferSize;
  uint16 usTimestampIndex;
  uint16 usTimestampsCounter;
  uint16 usNotifyInterval;
} Icu_TimeStampChannelRamDataType;

/*******************************************************************************
** Structure to store Signal Measurement channel data into RAM                **
*******************************************************************************/
/* ICU_PBTYPES_H_007: ICU_ESDD_UD_062                                         */
typedef struct STag_Icu_SignalMeasureChannelRamDataType
{
  uint32 ulSignalActiveTime;
  uint32 ulSignalPeriodTime;
  uint32 ulPrevSignalActiveTime;
} Icu_SignalMeasureChannelRamDataType;

/*******************************************************************************
** Structure for ICU Timer Channel information                                **
*******************************************************************************/
/* ICU_PBTYPES_H_008: ICU_ESDD_UD_056                                         */
typedef struct STag_Icu_TimerChannelConfigType
{

  uint16 usChannelModeOSRegSettings;
  /*
   * Bit 1-0   :  (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_PERIOD_TIME),
   *              (ICU_MODE_EDGE_COUNTER), (ICU_MODE_TIMESTAMP)
   *              00: Selects falling edge detection
   *              01: Selects rising edge detection
   *              10: Selects rising and falling edge detection
   *              11: Setting prohibited (rising and falling edge detection)
   *
   *              (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_HIGH_TIME, ICU_LOW_TIME)
   *              10: Low width measurement
   *              11: High width measurement
   *
   */
  uint8 ucChannelModeUserRegSettings;
  /* Index of Timer Unit in the Array Icu_GstTAUUnitConfig */
  uint8 ucTimerUnitIndex;
  /* RAM variable index */
  uint8 ucRamDataIndex;
  /*
   *****************************************************************************
   *******************    Time Stamp Measurement channels **********************
   *****************************************************************************
   * Bit 3    :   1: If ICU_CIRCULAR_BUFFER is selected for time stamp
   *                measurement mode.
   *              0: If ICU_LINEAR_BUFFER is selected for time stamp
   *                measurement mode.
   *****************************************************************************
   *******************    Signal Measurement channels **************************
   *****************************************************************************
   * Bit 2    :   1: If the timer channel is configured for Duty cycle
   *                 measurement.
   *              0: If the timer channel is not configured for Duty cycle
   *                 measurement.
   *
   * Bits 1-0 :  10: ICU_PERIOD_TIME
   *             01: ICU_HIGH_TIME
   *             00: ICU_LOW_TIME
   *****************************************************************************
   *******************    Edge Counter Measurement    **************************
   *****************************************************************************
   * Bits 3-0 :    0000
   *****************************************************************************
   * For all the Above Measurements Bits 7-4 should be generated as 0000
   */
  /* ICU_PBTYPES_H_030: SWS_Icu_00285   */
  /* ICU_PBTYPES_H_031: ICU027_Conf     */
  /* ICU_PBTYPES_H_032: ICU227_Conf     */
  /* ICU_PBTYPES_H_033: ICU229_Conf     */
  /* ICU_PBTYPES_H_034: ECUC_Icu_00027  */
  /* ICU_PBTYPES_H_035: ECUC_Icu_00227  */
  /* ICU_PBTYPES_H_036: ECUC_Icu_00229  */

  uint8 ucChannelProperties;

} Icu_TimerChannelConfigType;

/*******************************************************************************
**        Structure for TAUD/TAUB channel control registers Mirror            **
*******************************************************************************/
#if ( ((ICU_TAUD_UNIT_USED  == STD_ON) || (ICU_TAUB_UNIT_USED  == STD_ON)) && \
       (ICU_MIRROR_ENABLE == ICU_TAUDB_RAM_MIRROR ) )
/* ICU_PBTYPES_H_019: ICU_ESDD_UD_234                                         */
typedef struct STag_Icu_TAUDBChannelRegMirror
{
  uint8 ucMirrorTAUDBnCMURm;
} Icu_TAUDBChannelRegMirror;
#endif /* End of \
#if ( ((ICU_TAUD_UNIT_USED  == STD_ON) || (ICU_TAUB_UNIT_USED  == STD_ON)) && \
       (ICU_MIRROR_ENABLE == ICU_TAUDB_RAM_MIRROR ) ) */


/*******************************************************************************
**             Structure for TAUJ channel control registers Mirror            **
*******************************************************************************/
#if ( (ICU_TAUJ_UNIT_USED  == STD_ON) && \
      (ICU_MIRROR_ENABLE == ICU_TAUJ_RAM_MIRROR) )
/* ICU_PBTYPES_H_020: ICU_ESDD_UD_235                                         */
typedef struct STag_Icu_TAUJChannelRegMirror
{
  uint8 ucMirrorTAUJnCMURm;
} Icu_TAUJChannelRegMirror;
#endif/* End of #if ( (ICU_TAUJ_UNIT_USED  == STD_ON) && \
                      (ICU_MIRROR_ENABLE == ICU_TAUJ_RAM_MIRROR) ) */


/*******************************************************************************
**             Structure for ICU FCLA registers Mirror                        **
*******************************************************************************/
#if ( (ICU_EDGE_DETECT_API == STD_ON) && \
      (ICU_MIRROR_ENABLE == ICU_FCLA_RAM_MIRROR) )
/* ICU_PBTYPES_H_021: ICU_ESDD_UD_236                                         */
typedef struct STag_Icu_FclaRegsMirror
{
  uint8 ucMirrorFCLA0CTLm;
} Icu_FclaRegsMirror;
#endif /* End of #if ( (ICU_EDGE_DETECT_API == STD_ON) && \
                       (ICU_MIRROR_ENABLE == ICU_FCLA_RAM_MIRROR) ) */


/*******************************************************************************
** Structure for ICU Channel information                                      **
*******************************************************************************/
/* ICU_PBTYPES_H_008: ICU_ESDD_UD_055, ICU_ESDD_UD_034                        */
typedef struct STag_Icu_ChannelConfigType
{
  #if (ICU_NOTIFICATION_CONFIG == STD_ON)
  /* ICU_PBTYPES_H_037: ICU018, SWS_Icu_00018   */
  /* ICU_PBTYPES_H_038: ICU283, SWS_Icu_00283   */
  /* Pointer to callback notification function */
  P2FUNC (void, ICU_APPL_CODE, pIcuNotificationPointer)(void);
  #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */

  uint8 ucCntlRegsIndx;

  #if (ICU_GET_INPUT_LEVEL_API == STD_ON)
  /* Pointer to base address of channel PPR register */
  P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA) pLevelReadPprAddress;
  #endif

  /* Pointer to base address of channel Interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, ICU_CONFIG_DATA) pIntrCntlAdress;
  /* The wakeup value to be transmitted to EcuM */
  /* ICU_PBTYPES_H_039: ICU288, SWS_Icu_00288 */
  /* ICU_PBTYPES_H_040: ICU231_conf */
  /* ICU_PBTYPES_H_041: ICU126_conf */
  /* ICU_PBTYPES_H_042: ECUC_Icu_00126 */
  /* ICU_PBTYPES_H_043: ECUC_Icu_00231 */

  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType ddEcuMChannelWakeupInfo;
  #endif

  /* Individual channel mask value */
  uint16 usChannelMaskValue;

  #if (ICU_GET_INPUT_LEVEL_API == STD_ON)
  /* PPR mask value */
  uint16  usPortMaskValue;
  /* Port type used for ICU channel*/
  /* ICU_NORMAL_PORT - 0
   * ICU_JTAG_PORT - 1
   */
  uint8 ucIcuPortType;
  #endif

  /* The notification index that needs to be used.
   * If no notification is configured then NO_CBK_CONFIGURED
   * should be generated.
   */
  /* ICU_PBTYPES_H_044: ICU223_conf,    ECUC_Icu_00223  */
  /* ICU_PBTYPES_H_045: ICU226_conf,    ECUC_Icu_00226  */
  /* ICU_PBTYPES_H_046: ICU021_conf,    ECUC_Icu_00021  */
  /* ICU_PBTYPES_H_047: ICU228_conf,    ECUC_Icu_00228  */
  uinteger uiIcuMeasurementMode:2;
  /* Default Edge detection of the ICU channel */
  /* ICU_FALLING_EDGE - 0
   * ICU_RISING_EDGE - 1
   * ICU_BOTH_EDGES - 2
   */
   /* ICU_PBTYPES_H_048: ICU286,    SWS_Icu_00286   */
   /* ICU_PBTYPES_H_049: ICU222_conf,   ECUC_Icu_00222  */
  uinteger uiIcuDefaultStartEdge:2;
  /* Input capture channel type */
  /* ICU_HW_EXT_INTP - 0
   * ICU_HW_TAUD - 1
   * ICU_HW_TAUB - 2
   * ICU_HW_TAUJ - 3
   */
  uinteger uiIcuChannelType:2;
  /* Wakeup capability of the channel */
  /* ICU_PBTYPES_H_050: ICU224_conf,    ECUC_Icu_00224  */
  uinteger uiIcuWakeupCapability:1;
  /* Enable or disable EcuM notification of the channel */
  uinteger uiIcuDisableEcumWakeupNotification :1;
  uinteger uiIcuSyncStartReq:1;
} Icu_ChannelConfigType;

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/* ICU_PBTYPES_H_026:   ICU254, SWS_Icu_00254   */
#include ICU_MEMMAP_FILE

/* Declaration for ICU Channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_010: ICU_ESDD_UD_182                                         */
extern CONST(Icu_ChannelConfigType, ICU_CONST) Icu_GstChannelConfig[];
/* END Msg(4:3684)-1 */

/* Declaration for ICU Channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_011: ICU_ESDD_UD_183                                         */
extern CONST(Icu_TimerChannelConfigType, ICU_CONST)
                                                Icu_GstTimerChannelConfig[];
/* END Msg(4:3684)-1 */
#if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
/* RAM Allocation of Wake up Factors */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_012: ICU_ESDD_UD_233                                         */
extern CONST(Icu_WakeupFactorType, ICU_CONST) Icu_GstWakeUpFactor[];
/* END Msg(4:3684)-1 */
#endif

#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
    (ICU_TAUB_UNIT_USED == STD_ON))
/* Array of structures for Hardware Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_013: ICU_ESDD_UD_184                                         */
extern CONST(Icu_TAUUnitConfigType, ICU_CONST) Icu_GstTAUUnitConfig[];
/* END Msg(4:3684)-1 */
#endif

/* ICU_PBTYPES_H_023: ICU_ESDD_UD_037 */
#if (ICU_PREVIOUS_INPUT_USED == STD_ON)
/* Array of structures for Previous Input Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_014: ICU_ESDD_UD_228                                         */
extern CONST(Icu_PreviousInputUseType, ICU_CONST) Icu_GstPreviousInputConfig[];
/* END Msg(4:3684)-1 */
#endif

#if ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
       (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
       (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ))
extern CONSTP2VAR(volatile uint8, TYPEDEF, ICU_CONFIG_DATA)
                                   Icu_GaaReg_8bit[ICU_MAX_8BIT_REGISTERS];
extern CONSTP2VAR(volatile uint8, TYPEDEF, ICU_CONFIG_DATA)
                             Icu_GaaRegMirror_8bit[ICU_MAX_8BIT_REGISTERS];
#endif

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* ICU_PBTYPES_H_027:   ICU254, SWS_Icu_00254   */
#include ICU_MEMMAP_FILE


#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* ICU_PBTYPES_H_028:   ICU254, SWS_Icu_00254   */
#include ICU_MEMMAP_FILE

/* RAM Allocation of Channel data */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_015: ICU_ESDD_UD_229                                         */
extern VAR(Icu_ChannelRamDataType, ICU_NOINIT_DATA) Icu_GstChannelRamData[];
/* END Msg(4:3684)-1 */

/* RAM Allocation of Timestamp channel data */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_016: ICU_ESDD_UD_230                                         */
extern VAR(Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA)
                                                     Icu_GstTimestampRamData[];
/* END Msg(4:3684)-1 */

/* RAM Allocation of Signal Measure Channel data */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_017: ICU_ESDD_UD_231                                         */
extern VAR(Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA)
                                                 Icu_GstSignalMeasureRamData[];
/* END Msg(4:3684)-1 */

/* RAM Allocation of Edge Counting Channel data */
/* MISRA Violation: START Msg(4:3684)-1 */
/* ICU_PBTYPES_H_018: ICU_ESDD_UD_232                                         */
extern VAR(Icu_EdgeCountChannelRamDataType, ICU_NOINIT_DATA)
                                                     Icu_GstEdgeCountRamData[];
/* END Msg(4:3684)-1 */

/* MISRA Violation: START Msg(4:0857)-2 */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/* END Msg(4:0857)-2 */

/* ICU_PBTYPES_H_029:   ICU254, SWS_Icu_00254   */
#include ICU_MEMMAP_FILE

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_PBTYPES_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
