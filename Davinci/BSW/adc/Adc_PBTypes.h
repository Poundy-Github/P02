/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  12-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAAGA-72,
 *                              The macros ADC_EIGHTEEN_CYCLES,
 *                              ADC_TWENTYFOUR_CYCLES, ADC_PWSA_ODD_MASK,
 *                              ADC_PWSA_EVEN_MASK and ADC_PDM_DIAG_RESULT_MASK
 *                              are added.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              Elements ucProtLength and
 *                              pPwmDiagDoubleResultRam are added in structure
 *                              Adc_HwUnitConfigType.
 *                           3. As a part of JIRA ticket ARDAAGA-72,
 *                              Declaration for arrays
 *                              'Adc_GaaResultGroupRamData' and
 *                              'Adc_GstPwmDiagDoubleResultData' are added.
 *                           4. As a part of JIRA ticket ARDAAGA-72,
 *                              Element ucDmaDoubleBuffer is added in structure,
 *                              Adc_DmaUnitConfig.
 *                           5. As a part of JIRA ticket ARDAAGA-72,
 *                              The compiler switch ADC_DMA_TYPE_USED is
 *                              removed.
 *                           6. As a part of JIRA ticket ARDAAGA-164,
 *                              Renamed 'ucMaxDiagRunTime' to
 *                              'usMaxDiagRunTime'.
 * V2.0.0:  28-Sep-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-765,
 *                              Macro ADC_TIMEOUT is replaced by a
 *                              configuration parameter.
 *                           2. As a part of JIRA ticket ARDAABC-745,
 *                              AdcConfRegRam, AdcVirChRegRam, AdcSGRegRam,
 *                              PWGARegRam, PWSARegRam, DmaRegRam structure
 *                              types are added.
 *                           3. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_WVErrorInterface function pointer is added.
 *                           4. As a part of JIRA ticket ARDAABC-745,
 *                              DmaRegRam structure is updated.
 *                           5. As a part of JIRA ticket ARDAABC-743,
 *                              Readback register values are added.
 *                           6. As a part of JIRA ticket ARDAABC-516
 *                              Values of ADC_CMVC_VALUE and
 *                              DCST_REGISTER_VALUE are updated.
 *                           7. As part of JIRA ticket ARDAABC-810,
 *                              add traces in code for WV, HWCC and Endless
 *                              Loop FUSA requirements
 *                           8. As a part of JIRA ticket ARDAABC-824,
 *                              ADC_PWM_DIAGGRP_CH_MASK is changed to include
 *                              MUX settings.
 *                           9. Minor QAC warnings have been eliminated.
 * V2.0.1:  03-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-780,
 *                              arrays Adc_GaaFlexiableChannelToGroup[]
 *                              and Adc_GaaFlexiableLimitCheckRange[] have been
 *                              removed as well as Adc_GaaResultGroupRamData
 *                              declaration.
 *                              Adc_GaaHwUnitIndex and Adc_GaaSgUnitIndex
 *                              have been moved to SEC_CONFIG_DATA_UNSPECIFIED.
 * V2.1.0:  28-Oct-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE, removed Pointer to
 *                              callback Error Interface for Write-Verify
 *                              (macro is used instead)
 * V2.2.0:  15-Nov-2016      : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-912,
 *                              ADC_CMVC_VALUE was removed, as it was useless.
 * V2.3.0:  15-Nov-2016      : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-913,
 *                              Prefix all macro definitions with <ADC_>.
 *                              Add ADC_DISABLE_SELF_DIAG macro.
 * V2.3.1:  16-Nov-2016      : The following changes are made:
 *                           1. Review finding in JIRA ticket ARDAABC-824:
 *                              ADC_PWM_DIAGGRP_CH_MASK is fixed
 * V2.3.2:  18-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Macro ADC_DTFRRQ_DRQ_MAKS is replaced by
 *                              ADC_DTFRRQ_DRQ_CLEAR_VALUE with updated value
 *                              from 0x01 to 0x00.
 * V2.3.3:  19-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              use uint16 and uint32 instead of unsigned short
 *                              and unsigned long.
 * V2.3.4:  20-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-929,
 *                              TYPEDEFS are used instead of AUTOMATIC
 * V2.3.5:  21-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              added write verify masks ADC_WV_MASK_ALL_32BIT,
 *                              ADC_WV_MASK_ALL_16BIT and ADC_WV_MASK_ALL_8BIT.
 * V2.3.6:  21-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              added WV mask for ADCAnVCRj register.
 * V2.3.7:  23-Nov-2016      : The following changes are made:
 *                           1. As a part of review for JIRA ticket ARDAABC-905,
 *                              ADC_CURRENT_CONV_GROUP_INIT was defined.
 * V2.4.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.5.0:  26-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-602,
 *                              removed limit check range ADC_RANGE_NOT_BETWEEN.
 * V2.6.0:  16-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              added mask for DCSTC write verify check.
 * V2.6.1:  10-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-516,
 *                              removed unused ADC_DCST_REGISTER_VALUE macro.
 * V2.6.2:  27-Jan-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-912,
 *                              Removed unused macros ADC_INIT_ZER0,
 *                              ADC_FOURTY and ADC_TWENTY.
 * V2.7.0:  09-Feb-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-586,
 *                              Updated ADC_WV_MASK_ALL_32BIT macro to
 *                              0xFFFFFFFFuL to avoid MISRA violations
 * V2.8.0:  13-Feb-2017    : Following changes are made:
 *                           1. As part of ARDAABC-978, critical section names
 *                              updated
 * V2.8.1:  15-Mar-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Added register masks for Write Verify.
 * V2.8.2:  17-Mar-2017    : Following changes are made:
 *                           2. As part of ARDAABC-858, ADC_ERROR_ULER and
 *                              ADC_ERROR_OWER definitions added
 * V2.9.0:  07-Jul-2017    : Following changes are made:
 *                           As part of ARDAABD-1725:
 *                           a. support for mux hardware stabilisation time is
 *                              implemented
 *                           b. Structure for mux configuration of each channel
 *                              STag_MuxDelayVal is added
 *                           c. Added pre compile switch for ulDelayCount.
 *                           d. Added MACRO's for Enhanced limit check
 *                              functionality.
 * V2.9.1:  15-Sep-2017     : Following changes are made:
 *                            1. As part of ARDAABD-2387,
 *                             a. Variable names are corrected based on the data
 *                                type names as per requirement MCAL052.
 *                             b. Array names are corrected based on the data
 *                                type names as per requirement MCAL052.
 *                             c. Meaningful macro definitions are added.
 *                            1. As part of ARDAABD-2448,
 *                             a. Adc_GstPwmDiagResultData,
 *                                Adc_GaaResultGroupRamData,
 *                                Adc_GstPwmDiagDoubleResultData are declared in
 *                                DMA specific memory sections.
 *                            2. As part of ARDAABD-2568,
 *                             a. unused macros ADC_FIVE, ADC_CONTINUOUS,
 *                                ADC_ONCE, ADC_DIAG_GRP_DISABLED,
 *                                ADC_SET_DIAGOUT_VOLTAGE
 *                                are removed
 * V2.9.2:  27-Jun-2018    : Following changes are made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                             a.Added macros ADC_INTERRUPT_MASK_EN ,
 *                               ADC_INTERRUPT_MASK_DIS. pImrIntpAddress and
 *                               usImrMask are removed from and element
 *                               pIcrIntpAddress is added to structure
 *                               Adc_HwSgUnitType. Elements pDmaImrIntCntlReg,
 *                               usDmaImrMask removed from structure
 *                               Adc_DmaUnitConfig. Elements pImrErrIntAddress
 *                               and usImrErrMask removed from structure
 *                               Adc_HwUnitConfigType. Macros
 *                               ADC_DMA_INT_CLEAR_VALUE,
 *                               ADC_DMA_INT_ENABLE_VALUE removed.
 *                               Ref: ARDAABD-2158.
 *                             b.Arrays Adc_GaaHwUnitIndex, Adc_GaaSgUnitIndex
 *                               Adc_GaaHwUnit , Adc_GaaSGUnit are mapped to
 *                               memory section CONFIG_DATA_8,
 *                               Adc_GaaChannelToGroup is mapped to
 *                               memory section CONFIG_DATA_16 and
 *                               Adc_GaaHWGroupTrigg , Adc_GaaLimitCheckRange
 *                               are mapped to memory section CONFIG_DATA_32.
 *                               Ref: ARDAABD-908.
 *                             c.Copyright updated.
 *                            2.As part of ARDAABD-2996,
 *                              a.Mask for write verification of DCSTCm
 *                                register, ADC_WV_MASK_DCST_CLEAR, is updated.
 *                            3.As part of ARDAABD-3112, modified the
 *                              declaration of
 *                              Adc_GpQueueFullNotificationPointer.
 *                            4.As part of ARDAABD-3390, global arrays
 *                              Adc_GstPwmDiagResultData and
 *                              Adc_GstPwmDiagDoubleResultData are renamed as
 *                              Adc_GaaPwmDiagResultData and
 *                              Adc_GaaPwmDiagDoubleResultData respectively.
 *                            5.As part of ARDAABD-3273, unused macros,
 *                              ADC_NEXT_SG and ADC_NEXT_SG3 have been removed.
 *                            6.As part of ARDAABD-2740,
 *                              ADC_WV_MASK_MPXSTBTR, ADC_WV_MASK_MPXSTBT_SELR
 *                              are added for write verification of MPX
 *                              Stabilization setting registers ADCAnMPXSTBTR,
 *                              ADCAnMPXSTBTSELR.
 *                            7.As part of ARDAABD-1605, definition of macro
 *                              ADC_10BIT_MASK_VALUE updated. Macro ADC_TEN is
 *                              changed to ADC_SIXTEEN.
 *                            8.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 * V2.9.3:  30-Oct-2019    : Following changes are made:
 *                            1. As a part of JIRA ticket ARDAABC-4074,
 *                              added ADC_INVALID_MAXLIMITCHECK for
 *                              Invalid maximum limit check.
 *                            2.As part of ARDAABD-4639,
 *                              a.Added macros for invalid value check.
 *                                ADC_INVALID_PVCR_VALUE_32BIT
 *                                ADC_INVALID_PVCR_VALUE_16BIT
 *                            3.As part of ARDAABD-2787,
 *                              a.Modified macros for invalid value check.
 *                                ADC_INVALID_MAXLIMITCHECK
 *                                ADC_CLEAR_TRGMD
 *                                ADC_SGACT_VALUE
 */
/******************************************************************************/
/* ADC_PBTYPES_H_023: EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0001 */
#ifndef ADC_PBTYPES_H
#define ADC_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Adc type declarations */
#include "Adc_Types.h"
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* include the Diagnostic trigger source file */
#include "Pwm_Diagnostic.h"
#endif

/* ADC_PBTYPES_H_001: ADC_ESDD_UD_148 */
/* ADC_PBTYPES_H_027: ADC_ESDD_UD_149 */
/*  Included for the macro declaration of supervisor mode(SV) write enabled
    Registers  ICxxx */
#include "rh850_Types.h"
#include "Adc_Hardware.h"

#if ( ADC_USE_WV_ERROR_INTERFACE == STD_ON )
#include "Dem.h"
#endif

/* Included for Write Verify and Hardware Consistency Check mechanisms */
#include "Adc_RegWrite.h"

/* Implements EAAR_PN0034_NR_0026 */
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

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750)  A union type specifier has been define           */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access the lower and higher order byte individually and */
/*                 read/write the values to register.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-2 and                           */
/*                 END Msg(4:0750)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : The semi-colon is added at the end of macro to avoid       */
/*                 static analysis warning.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-3 and                           */
/*                 END Msg(4:3412)-3 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define ADC_PBTYPES_AR_RELEASE_MAJOR_VERSION  ADC_TYPES_AR_RELEASE_MAJOR_VERSION
#define ADC_PBTYPES_AR_RELEASE_MINOR_VERSION  ADC_TYPES_AR_RELEASE_MINOR_VERSION
#define ADC_PBTYPES_AR_RELEASE_REVISION_VERSION  \
                                           ADC_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ADC_PBTYPES_SW_MAJOR_VERSION   ADC_TYPES_SW_MAJOR_VERSION
#define ADC_PBTYPES_SW_MINOR_VERSION   ADC_TYPES_SW_MINOR_VERSION

#define ADC_DBTOC_VALUE  ((ADC_VENDOR_ID_VALUE << 22) | \
                         (ADC_MODULE_ID_VALUE << 14) | \
                         (ADC_SW_MAJOR_VERSION_VALUE << 8) | \
                         (ADC_SW_MINOR_VERSION_VALUE << 3))

/* ADC_PBTYPES_H_014: ADC_ESDD_UD_002 */
/* ADC_PBTYPES_H_018: AR_PN0076_NR_0001 */
/* Adc Driver initialization status */
#define ADC_UNINITIALIZED                   (boolean)0
#define ADC_INITIALIZED                     (boolean)1

/*
 * Macros to indicate if the function Adc_IcrInterruptBit() should enable or
 * disable the interrupt
 */
#if(ADC_DMA_MODE_ENABLE == STD_ON)
#define  ADC_DTCT_REGISTER_VALUE            (uint32)0x04004005
#define  ADC_DTFRRQC_REGISTER_VALUE         (uint32)0x1u
#define  ADC_DTFRRQ_DRQ_CLEAR_VALUE         (uint32)0x00u

#endif
#define ADC_ENABLE_INTERRUPT                (boolean)0
#define ADC_DISABLE_INTERRUPT               (boolean)1

#define ADC_FALSE                           (boolean)0
#define ADC_TRUE                            (boolean)1
#define ADC_ZERO                            (uint8)0
#define ADC_ONE                             (uint8)1
#define ADC_TWO                             (uint8)2
#define ADC_THREE                           (uint8)3
#define ADC_FOUR                            (uint8)4
#define ADC_SIX                             (uint8)6
#define ADC_SEVEN                           (uint8)7
#define ADC_EIGHT                           (uint8)8
#define ADC_SIXTEEN                         (uint8)0x10

#define ADC_EIGHTEEN_CYCLES                 (uint32)0x00000012uL
#define ADC_TWENTYFOUR_CYCLES               (uint32)0x00000018uL

/*DMA transfer source selection Enable*/
#define ADC_DMA_TRNSFR_SRC_SEL_ENBL         (uint8)1

/* Adc undefined conversion group initializer*/
#define ADC_CURRENT_CONV_GROUP_INIT         (uint8)0xFF


/* Start/Stop ADC Conversion macros */
#define ADC_START_CONVERSION                (uint32)0x00000001
#define ADC_STOP_HW_CONVERSION              (uint32)0x00000001
#define ADC_STOP_HW_CONVERSION_READBACK     (uint32)0x00007E00
#define ADC_STOP_SG_CONVERSION              (uint32)0x00000001
#define ADC_STOP_SG_CONVERSION_READBACK     (uint32)0x00007E00
#define ADC_RESULT_FLAG_MASK                (uint8)0x00


/* Limit check Channel is not configured mask */
#define ADC_LIMIT_CHKCH_NOT_CONFIG          (uint8)0xFF
/* 10-Bit Maximum Value  */
#define ADC_10BIT_MAXVALUE                  (uint16)0x03FF
/* 12-Bit Maximum Value  */
#define ADC_12BIT_MAXVALUE                  (uint16)0x0FFF
/* Macros to that defines 10-Bit Resolution of HW uint */
#define ADC_10BIT_RESOLUTION                (uint32)0x00000010
/* Macros to that defines 10-Bit Resolution Mask Value */
#define ADC_10BIT_MASK_VALUE                (uint32)0x00300000UL
/* Macros to that defines Threshold Mask Value */
#define ADC_THRESHOLD_MASK_VALUE            (uint16)0xFF3F
/* Macros to that defines Threshold Mask Value for Enhanced limit check. */
#define ADC_ENHANCED_LC_THRESHOLD_MASK_VALUE (uint16)0xF33F
/* Reset PWSAnSTR and PWSAnQUEj mask */
#define ADC_PWM_RST_PWSA                    (uint8)0x00
/* Start PWSA Operation mask */
#define ADC_PWM_START_PWSA                  (uint8)0x01

/* PWM Diag group channel mask */
#define ADC_PWM_DIAGGRP_CH_MASK             (uint16)0x823F

/* Disable Enable Channel mask Macro */
#define ADC_MASK_CHANNEL                    (uint16)0x003F

/* Error in limit check  */
#define ADC_UE_LE_LIMIT_CHK_ERROR           (uint32)0x0000C000uL
/* Clear Error flags */
#define ADC_CLR_ERROR_FLAG                  (uint32)0x0000000CuL
/* To clear the HW trigger selected bits */
#define ADC_CLEAR_TRIGGER_LIST              (uint32)0x00000000uL
/* Macro to set the bit ASMPMSK */
#define ADC_SET_ASMPMSK                     (uint32)0x00000001uL
/* Macro to set the bit SMPST */
#define ADC_SET_SMPST                       (uint32)0x00000001uL
/* Macro to check the bit WFLG */
#define ADC_RESULT_AVAILABLE                (uint32)0x02000000uL
/* Macro to set the bit HLDCTE and HLDTE */
#define ADC_SET_HLDCTE_HLDTE                (uint8)0x30
/* Macro to Reset the bit HLDTE*/
#define ADC_CLR_HLDTE                      (uint32)0xFFFFFFEFuL
/* Macro to clear TRGMD bit in ADCAnSGCRx register */
#define ADC_CLEAR_TRGMD                     (uint32)0x0000003CuL
/* Queue status macros */
#define ADC_QUEUE_EMPTY                     (uint8)0
#define ADC_QUEUE_FILLED                    (uint8)1
#define ADC_QUEUE_FULL                      (uint8)2

/* Enable/disable of Upper/Lower limits */
#define ADC_ERROR_ULER                      (uint8)0x08
#define ADC_ERROR_OWER                      (uint8)0x04

/* Mask value for ENHANCED LIMIT CHECK feature.*/
#define ADC_ENHANCED_LC_MSB_MASK            (uint8)0x0C
#define ADC_ENHANCED_LC_LSB_MASK            (uint8)0x03
#define ADC_ENHANCED_LC_MSB_POS             (uint8)0x0A
#define ADC_ENHANCED_LC_LSB_POS             (uint8)0x06

#if(ADC_DMA_MODE_ENABLE == STD_ON)
/* DMA disable DTE bit */
#define ADC_DMA_DISABLE                     (uint32)0xFFFFFFFEul
/* DMA enable DTE bit */
#define ADC_DMA_ENABLE                      (uint32)0x00000001ul
#define ADC_DMA_TRANSFER_COMPLETED          (uint32)0x00000010
/* Clear the DTSmTC bit mask */
#define ADC_DMA_CLR_DTSTC                   (uint32)0xFFFFFFEFUL
/* Single transfer DMA setting */
#define ADC_DMA_SETTINGS                    (uint32)0x04004004
/* To make DMA continuous transfer to single Transfer*/
#define ADC_DMA_ONCE                        (uint32)0xFFFFD9FFul
/* Setting for PWM Diag */
#define ADC_PWM_DMA_SETTINGS                (uint32)0x04002448
/* DMA MLE bit set mask value */
#define ADC_DMA_CONTINUOUS                  (uint32)0x04002605
#endif


/* DMA channel not configured */
#define ADC_NO_DMA_CHANNEL_INDEX            (uint8)0xFF

/* SGACT Value Mask */
#define ADC_SGACT_VALUE                     (uint32)0x00003E00
/* Word Clear mask */
#define ADC_WORD_ZERO                       (uint16)0x0000
/* Clear Virtual Channel Registers */
#define ADC_CLEAR_VIRTUAL_CHNL              (uint16)0x0000
/* Clear DMA transfer control register */
#define ADC_DMA_CTL_REG_CLEAR               (uint16)0x0000
/* ADC conversion status is not Busy */
#define ADC_NOT_BUSY                        (uint16)0x0000

/* Macro to enable the interrupt request bit MKxxx in ICR */
#define ADC_INTERRUPT_MASK_EN               (uint16)0xFF7FU
/* Macro to disable the interrupt request bit MKxxx in ICR */
#define ADC_INTERRUPT_MASK_DIS              (uint16)0x0080U

/* Double word Clear mask */
#define ADC_DOUBLE_WORD_ZERO                (uint32)0x00000000
/*Disable DMA transfer*/
#define ADC_DISABLE_DMA_TRANSFER            (uint32)0x00000000
/*Reset SFTCR register*/
#define ADC_SFTCR_REG_RESET                 (uint32)0x00000000
/*Set the Number of scans in multi-cycle scan mode to 1*/
#define ADC_SINGLE_CYCLE_SCAN               (uint32)0x00000000
/*Reset SGCR */
#define ADC_CLR_SCAN_GRP_CTL_REG            (uint32)0x00000000
/*Disable Self diag voltage selection */
#define ADC_SELF_DIAG_VLTG_DISABLE          (uint32)0x00000000
/*Disable On-chip pull down resistor connection */
#define ADC_DISABLE_PULL_DOWN_RESISTOR      (uint32)0x00000000
/*Clear track and hold registers*/
#define ADC_TRACK_AND_HOLD_REG_CLEAR        (uint32)0x00000000
/*No wake up factor is generated*/
#define ADC_NO_WAKEUP_FACTOR                (uint32)0x00000000
/*No Limit check error has occurred*/
#define ADC_NO_LIMIT_ERROR                  (uint32)0x00000000
/*No Overwrite error has occurred*/
#define ADC_NO_OVERWRITE_ERROR              (uint32)0x00000000
/*Clear DMA Transfer flag*/
#define ADC_TRANSFER_FLAG_CLEAR             (uint32)0x091
/* Macro to enable PWM Diagnostic trigger group */
#define ADC_ENABLE_PWM_DIAG_TRIGG           (uint32)0x00000001
/* Macro to disable PWM Diagnostic trigger group */
#define ADC_DISABLE_PWM_DIAG_TRIGG          (uint32)0x00000000
/* Macro to check WFLG bit */
#define ADC_WFLG_BIT_SET                    (uint32)0x02000000
/* Macro to enable reload trigger value */
#define ADC_EN_PWM_DIAG_RELOAD_TRIGG        (uint8)0x01
/* Macro to read status of enable reload trigger value */
#define ADC_EN_PWM_DIAG_RELOAD_TRIGG_READBACK (uint8)0x01
/* Macro to Stop PWM Diagnostic trigger group */
#define ADC_STOP_PWM_DIAG_SCAN_GRP            (uint8)0x01

/* ADC_PBTYPES_H_026: SWS_Adc_00510 */
/* Macro's for Streaming number of samples mask */
#define ADC_DUMMY                           (uint32)0x00000000
#define ADC_ONE_TIME_CONVERSION             (uint32)0x00000000
#define ADC_TWO_TIME_CONVERSION             (uint32)0x00000001
#define ADC_THREE_TIME_CONVERSION           (uint32)0x00000002
#define ADC_FOUR_TIME_CONVERSION            (uint32)0x00000003

/* Macro to clear the interrupt request flag EIRFn */
#define ADC_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF
/* Macro to set the interrupt vector address method to Reference to a table */
#define ADC_SET_TABLE_REF_METHOD            (uint16)0x0040

/* Operation mode enable mask */
#define ADC_SG1_CONV_ONCE                   (uint32)0x00000010uL
#define ADC_SG1_CONV_CONTINUOUS             (uint32)0x00000020uL

/* Macro for INT after SG conversion ends */
#define ADC_INT_SG_END                      (uint32)0x00000010uL

/* ADC SGm unit Macros */
#define ADC_SG1                             (uint8)0x00
#define ADC_SG2                             (uint8)0x01
#define ADC_SG3                             (uint8)0x02
#define ADC_SG4                             (uint8)0x03
#define ADC_NO_OF_SG_UNITS                  (uint8)0x03
#define ADC_NOT_CONFIGURED                  (uint8)0x00

/* ADC SGm unit conversion status Macros */
#define ADC_SG1_CONV_STATUS_MASK            (uint32)0x00000200
#define ADC_SG2_CONV_STATUS_MASK            (uint32)0x00000400
#define ADC_SG3_CONV_STATUS_MASK            (uint32)0x00000800

/* Macro to Check the HW unit Status */
#define ADC_HW_UNIT_STATUS                  (uint32)0x00000E00
/* Macro to Start the HW triggered Group */
#define ADC_SG_HW_TRIGGER                   (uint32)0x00000001
/* Macro of PWM Register Maximum Value */
#define ADC_PWM_REG_MAX_COUNT               (uint16)0xFFF
/* Macro of PWM Register Minimum Value */
#define ADC_PWM_REG_MIN_COUNT               (uint16)0x000
/* Macro to Clear ADC Wakeup factors */
#define ADC_WUF_CLEAR_MASK_VALUE            (uint32)0x00000007

/* Macros of ADC Result access in a Group */
#define ADC_DMA_ACCESS                      (uint8)0x00
#define ADC_ISR_ACCESS                      (uint8)0x01

/* Macros of ADC Group Conversion Mode */
#define ADC_GROUP_CONV_MASK                 (uint8)0x01
#define ADC_GROUP_CONTINUOUS                (uint8)0x00
#define ADC_GROUP_ONCE                      (uint8)0x01

/* Macros of ADC Group Replacement mask */
#define ADC_GROUP_REPLACEMENT_MASK          (uint8)0x02
#define ADC_GROUP_ABORT_RESTART             (uint8)0x00
#define ADC_GROUP_SUSPEND_RESUME            (uint8)0x02

/* Macros for ADC HW triggered Group in Streaming Mode */
#define ADC_HW_TRIG_DISABLE                 (uint32)0x00000010uL

/* Macro used to enable the self diagnostic functionality  */
#define ADC_ENABLE_SELF_DIAG                (uint32)0x00000080uL
#define ADC_DISABLE_SELF_DIAG               (uint32)0xFFFFFF7FuL

/* Macros of ADC Group Result access Mode */
#define ADC_GROUP_RESULT_ACCESS_MASK        (uint8)0x04
#define ADC_GROUP_DMA_ACCESS                (uint8)0x00

/* Macros of ADC Group Access mode mask */
#define ADC_GROUP_ACCESS_MASK               (uint8)0x08
#define ADC_GROUP_ACCESS_SINGLE             (uint8)0x00
#define ADC_GROUP_ACCESS_STREAMING          (uint8)0x08

/* Macro to Fetch the Channel Id */
#define ADC_CHANNEL_ISR                     (uint32)0x0000003FuL
/* Macro to start a HW triggered MUX Group */
#define ADC_MUX_GROUP                       (uint32)0xFFFFFFDFuL
/* Macro to check PWSAnQFL bit */
#define ADC_PWSAQFL_SET                     (uint8)0x02
/* Macro to check PWSAnQNE bit */
#define ADC_PWSAQNE_SET                     (uint8)0x00
/* Macro to check Diag trigger source valid or not */
#define ADC_PWM_TRIGG_SRC_INVALID           (uint16)0x1000
/* Macro to check PWM Diag converted result is already read */
#define ADC_PWM_RESULT_READ               (uint32)0x00800000
#define ADC_ADCAPWDDIR_CH_MASK            (uint32)0x0000FFFF
#define ADC_SHIFT_16                      (uint8)0x10
#define ADC_PWSA_ODD_MASK                  (uint32)0xFFFF0000uL
#define ADC_PWSA_EVEN_MASK                 (uint32)0x0000FFFF
#define ADC_PDM_DIAG_RESULT_MASK          (uint32)0x3FFFFF

/* Macro to check the SG units not equal to zero */
#define ADC_SG_ZERO                         0
/* PWSAnPVCR mask to clear the channel setting */
#define ADC_PWSAPVCR_MASK                 (uint16)0xFFFF

/* Of set for ulULLMTBR2 register.*/
#define ADC_ULLMTBR2_OFSET                 (uint8)0x03

/* Macros for Write Verify and Hardware Consistency Check */
#define ADC_WV_MASK_ALL_32BIT            (uint32) 0xFFFFFFFFuL
#define ADC_WV_MASK_ALL_16BIT            (uint16) 0xFFFF
#define ADC_WV_MASK_ALL_8BIT             (uint8)  0xFF

#define ADC_WV_MASK_DCST_CLEAR           (uint32) 0x00000001uL
#define ADC_WV_MASK_VCR                  (uint32) 0x000001FFuL
#define ADC_WV_ENHANCED_LC_MASK_VCR      (uint32) 0x00000DFFuL
#define ADC_WV_MASK_DTFR                 (uint32) 0x000000FFuL
#define ADC_WV_MASK_DTCT                 (uint32) 0x0C1F7FFFuL
#define ADC_WV_MASK_SMPCR                (uint32) 0x000000FFuL
#define ADC_WV_MASK_PWDSGCR              (uint32) 0x00000001uL
#define ADC_WV_MASK_PWSA_CTL             (uint8)  0x01
#define ADC_WV_MASK_PWSA_PVCR            (uint32) 0x1FFF1FFFuL
#define ADC_WV_ENH_LC_MASK_PWSA_PVCR     (uint32) 0x7FFF7FFFuL
#define ADC_WV_MASK_PWGA_CTDR            (uint16) 0x0FFF
#define ADC_WV_MASK_SFTCR                (uint32) 0x0000001CuL
#define ADC_WV_MASK_ADCR                 (uint32) 0x000000B3uL
#define ADC_WV_MASK_SGMCYCR              (uint32) 0x00000002uL
#define ADC_WV_MASK_SGCR                 (uint32) 0x0000003DuL
#define ADC_WV_MASK_DGCTL0               (uint32) 0x00000007uL
#define ADC_WV_MASK_DGCTL1               (uint32) 0x0000FFFFuL
#define ADC_WV_MASK_PDCTL1               (uint32) 0x0000FFFFuL
#define ADC_WV_MASK_PDCTL2               (uint32) 0x000FFFFFuL
#define ADC_WV_MASK_THACR                (uint32) 0x00000033uL
#define ADC_WV_MASK_THBCR                (uint32) 0x00000033uL
#define ADC_WV_MASK_THGSR                (uint32) 0x0000003FuL
#define ADC_WV_MASK_THER                 (uint32) 0x0000003FuL
#define ADC_WV_MASK_THCR                 (uint32) 0x00000001uL
#define ADC_WV_MASK_ULER                 (uint32) 0x0000FF3FuL
#define ADC_WV_MASK_OWER                 (uint32) 0x000000BFuL
#define ADC_WV_MASK_SGVCSP               (uint32) 0x0000003FuL
#define ADC_WV_MASK_SGVCEP               (uint32) 0x0000003FuL
#define ADC_WV_MASK_ULLMTBR              (uint32) 0xFFF0FFF0uL
#define ADC_WV_MASK_SGTSEL               (uint32) 0x000001FFuL
#define ADC_WV_MASK_DCEN                 (uint32) 0x00000001uL
#define ADC_WV_MASK_DTFRRQ               (uint32) 0x00000001uL
#define ADC_WV_MASK_MPXSTBTR             (uint32) 0x00003FFFuL
#define ADC_WV_MASK_MPXSTBT_SELR         (uint32) 0x77777777uL

/*Macros for Mux selection registers*/
#define ADC_MUXSEL0                      0x00U
#define ADC_MUXSEL1                      0x01U
#define ADC_MUXSEL2                      0x02U
#define ADC_MUXSEL3                      0x03U
#define ADC_MUXSEL4                      0x04U

/* Macro for Invalid maximum limit check */
#define ADC_INVALID_MAXLIMITCHECK        (uint8) 0xFF

/* Macro for Invalid PVCR check */
#define ADC_INVALID_PVCR_VALUE_32BIT     (uint32) 0xFFFFFFFFuL
#define ADC_INVALID_PVCR_VALUE_16BIT     (uint16) 0xFFFF

/* ADC_PBTYPES_H_019: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0066 */
/* ADC_PBTYPES_H_025: EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061 */
/* Functionality related to AR4.0.3 and AR4.2.2 */
/* MISRA Violation: START Msg(4:3412)-3 */
#define ADC_ENTER_CRITICAL_SECTION(Exclusive_Area) \
SchM_Enter_Adc_##Exclusive_Area();

#define ADC_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Adc_##Exclusive_Area();
/* END Msg(4:3412)-3 */
/* ADC_PBTYPES_H_020: EAAR_PN0034_FR_0019 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Union for accessing the 16-bit converted digital values from 32-bit        **
** register. This Union is also used for reading 32-bit address and writing   **
** into two 16-bit registers in case of DMA.                                  **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0750)-2 */
typedef union
{
  uint32 ulValue;
  struct
  {
    uint16 usLoWord;
    uint16 usHiWord;
  }DWord;
}Adc_ConvertedVal;
/* END Msg(4:0750)-2 */

/* ADC_PBTYPES_H_022: EAAR_PN0034_FR_0020 */
/*******************************************************************************
** Structure for DMA channel configuration for SGm unit                       **
*******************************************************************************/
/* ADC_PBTYPES_H_010: ADC_ESDD_UD_060 */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
typedef struct STag_Adc_DmaUnitConfig
{
  /* Address for DMA control registers index */
  uint8 ucDmaRegIndex;
  /* Address for Interrupt control registers */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA)pIntCntlReg;
  /* DMA channel Id mask */
  uint16 usDmaChannelMask;
  /* DTFR register value */
  uint16 usDmaDtfrRegValue;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * Index of the HW unit in the array Adc_GstHWUnitConfig[] to which DMA
   * channel is configured
   */
  uint8 ucHwUnitIndex;
  #if(ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  uint8 ucDmaDoubleBuffer;
  #endif
  #endif
} Adc_DmaUnitConfig;
#endif

/*******************************************************************************
** Structure for HW Unit configuration                                        **
*******************************************************************************/
/* ADC_PBTYPES_H_002: ADC_ESDD_UD_053 */
typedef struct STag_Adc_HwUnitConfigType
{
  /* Hardware unit index */
  uint8 ucHwUnit;
  /* Scan group offset */
  uint8 ucSGOffset;
  /* Pointer to ADC HW unit SG1 interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pIntpAddress;

  #if (ADC_ERROR_SUPPORT == STD_ON)
  /* Pointer to Error callback notification */
  P2FUNC(void, ADC_APPL_CODE, pErrorNotificationPointer)(uint8 LucChannel);
  /* Pointer to ADC HW unit Error interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pIntErrAddress;
  #endif
  #if ((ADC_DMA_MODE_ENABLE == STD_ON) && \
                                    (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON))
  /* Pointer to RAM of PWM Diagnostic result data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagResultRam;
  #if(ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  /* Pointer to RAM of PWM Diagnostic double result data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagDoubleResultRam;
  #endif
  /* Source address for the PWM DMA channel mapped to the HW unit */
  uint32 ulPwmDmaAdcResult;
  #endif
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /* Self-Diagnostic reference voltage setting */
  uint32 ulErrorEnableValue;
  #endif
  /*
   * Bit 7 = 0: Self-diagnostic is enabled
   *       = 1: Self-diagnostic is disabled
   * Bit 5 = 0: Result Data is right aligned
   *       = 1: Result Data is left aligned
   * Bit 4 = 0: 12-bit resolution is configured
   *       = 1: 10-bit resolution is configured
   *
   * Bit [1:0] = 00: Synchronous suspend
   *           = 10: Asynchronous suspend
   */
  uint32 ulHwUnitSettings;
  /*
   * HW Unit sampling time
   * Bit [7:0] = 0x12: ADC_SAMPLING_12H
   *           = 0x18: ADC_SAMPLING_18H
   */
   /* ADC_PBTYPES_H_021: SWS_Adc_00511 */
  uint32 ulHwSamplingTime;
  #if (ADC_ERROR_SUPPORT == STD_ON)
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* ADC limit check SG uint */
  uint8 ucLimitCheckSgUnit;
  #endif
  #endif
  /* Stores the count of number of SG units configured for this HW unit */
  uint8 ucSgUnitCount;
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  /* Track and Hold enabled channel mask */
  uint8 ucTrackHoldMask;
  /* Track and Hold group select mask */
  uint8 ucGroupSelectMask;
  #endif
  #if ((ADC_DMA_MODE_ENABLE == STD_ON) && \
                                    (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON))
  uint16 usMaxDiagRunTime;
  uint8 ucProtLength;
  #endif
  /* total no of channels configured for this HW unit */
  uint8 ucVirChannelCount;
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /*
   * blInterruptErr = ADC_TRUE, AdcEnableInterruptError = true
   *                = ADC_FALSE, AdcEnableInterruptError = false
   */
  boolean blInterruptErr;
  #endif
} Adc_HwUnitConfigType;

/*******************************************************************************
** Structure for HW Scan Group unit                                           **
*******************************************************************************/
/* ADC_PBTYPES_H_005: ADC_ESDD_UD_151 */
/* ADC_PBTYPES_H_016: AR_PN0076_FR_0251, AR_PN0076_FR_0223 */
typedef struct STag_Adc_HwSgUnitType
{
  /* Scan Group Index */
  uint8 ucSgRegIndex;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Pointer to the Priority Queue */
  P2VAR(Adc_GroupType, TYPEDEF, ADC_CONFIG_DATA) pQueue;
  #endif
  /* ICxxx address of the corresponding SG unit */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pIcrIntpAddress;
  /* Indicates if the SGm unit is configured in interrupt or polling mode */
  Adc_FunctionalityModeType enFunctionalityModeType;
  /* Data Register Index */
  uint8 ucDataRegisterIndex;

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /*
   * Maximum Queue Size when software priority or
   * first come first serve mechanism is enabled
   */
  uint8 ucAdcSgQueueSize;
  #endif
   /* SGm unit to which Scan group is configured */
  uint8 ucSgUnitId;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Index of the DMA channel Id configured for this SGm in the array
     Adc_GstDmaUnitConfig[] */
  uint8 ucDmaChannelIndex;
  #endif
} Adc_HwSgUnitType;

/*******************************************************************************
** Structure for Group configuration                                          **
*******************************************************************************/
/* ADC_PBTYPES_H_003: ADC_ESDD_UD_054 */
/* ADC_PBTYPES_H_009: ADC_ESDD_UD_059 */
/* ADC_PBTYPES_H_015: ADC_ESDD_UD_164 */
/* ADC_PBTYPES_H_024: ADC082, SWS_Adc_00082 */
typedef struct STag_Adc_GroupConfigType
{
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Pointer to callback notification */
  P2FUNC (void, ADC_APPL_CODE, pGroupNotificationPointer)(void);
  #endif
  /* Start virtual channel pointer */
  uint32 ulStartVirChPtr;
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                             (ADC_FUNCTIONALITY_MODE != ADC_POLLING) && \
                             (ADC_HW_MUX_STAB_SUPPORT == STD_OFF))
  /* Stabilization delay required while changing external multiplexer lines */
  uint32 ulDelayCount;
  #endif
  /* Number of Samples in Streaming Access Mode */
  Adc_StreamNumSampleType ddNumberofSamples;
  #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  /* Software Priority configured for the group */
  Adc_GroupPriorityType ddGroupPriority;
  #endif
  #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
  /* enum parameter for group to know the group is configured as self
     Diag mode or not */
  Adc_SelfDiagMode enSelfDiagMode;
  /* mask value to configured the self diag channel */
  uint32 ulAdcSelfDiagOpenPin1;
  uint32 ulAdcSelfDiagOpenPin2;
  /* mask value to configured the self diag reference voltage */
  uint32 ulAdcSelfDiagVolLevSel;
  uint32 ulAdcSelfDiagChannelSel;
  #endif

  /* Index of the hardware unit to which the group belongs */
  uint8 ucHwUnitIndex;
  /*
   * Index of the SGm unit to which group is configured in the array
   * Adc_GstSgUnitConfig[]
   */
  uint8 ucSgUnitIndex;
  /*
   * Index to the start of the channels configured for this group in the array
   * Adc_GaaChannelToGroup[]
   */
  uint8 ucChannelToGroupIndex;
  /* Group attributes variable */
  /*
   * Bit 0 = 0 AdcGroupConversionMode configured for Continuous mode
   *         1 AdcGroupConversionMode configured for Oneshot mode
   * Bit 1 = 0 AdcGroupReplacement configured for Abort and Restart
   *         1 AdcGroupReplacement configured for Suspend and Resume
   * Bit 2 = 0 AdcResultAccessMode configured for DMA access
   *         1 AdcResultAccessMode configured for ISR access
   *         1 AdcResultAccessMode configured for Polling access
   * Bit 3 = 0 AdcGroupAccessMode configured for Single Access
   *         1 AdcGroupAccessMode configured for Streaming Access
   */
  uint8 ucGroupSettings;
  /* Number of channels configured in the group */
  uint8 ucChannelCount;
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /*
   * Index to the array Adc_GaaLimitCheckRange[] which will give the limit
   * check enabled channels index of this Group.
   */
  uint8 ucLimitCheckIndex;
  /*
   * Maximum number of Limit check enabled channels in an Group.
   */
  uint8 ucMaxLimitcheck;
  #endif
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Flag to indicate if group contains external multiplexed enabled channel */
  boolean blExtMuxEnabled;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Flag to indicate if group contains Limit check enabled channel */
  boolean blLimitCheckEnabled;
  #endif
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  boolean blTandHEnable;
  #endif
} Adc_GroupConfigType;

/*******************************************************************************
** Structure for PWM Diagnostic Group configuration                           **
*******************************************************************************/
/* ADC_PBTYPES_H_006: ADC_ESDD_UD_055 */
typedef struct STag_Adc_PwmDiagGroupConfigType
{
  /* PWM Diagnostic channel attributes variable */
  /*
   * Bit 15 = 1 if the group is enabled for external multiplex
   *          0 if the group is not enabled for external multiplex
   * Bit 9  = 1 Always fixed value
   * Bit 5-0 = physical channel number configured for this group
   * Other bits should be zero
   */
  uint16 usChannelMask;
  /* Index of the hardware unit to which the group belongs */
  uint8 ucHwUnit;
  /*
   * Index to the start of the channels configured for this group in the array
   * Adc_GaaChannelToGroup[]
   */
  uint8 ucChannelToGroupIndex;
  /*
   * Index to the start of PWM trigger sources configured for this
   * group in the array Adc_GstPwmDiagIds[]
   */
  uint8 ucDiagGroupTriggsIndex;
  /* Number of PWM Trigger source configured in the group */
  uint8 ucPwmTriggCount;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint8 ucPwmDmaChannelIndex;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /*
   * Index to the array Adc_GaaLimitCheckRange[] which will give the limit
   * check enabled channels index of this Group.
   */
  uint8 ucPwmLimitCheckIndex;
  #endif
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Number of channels configured in the group */
  uint8 ucChannelCount;
  /* Flag to indicate if group contains external multiplexed enabled channel */
  boolean blExtMuxEnabled;
  #endif
  #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && \
       (ADC_DMA_MODE_ENABLE == STD_OFF))
  /* Flag to indicate if group contains Limit check enabled channel */
  boolean blLimitCheckEnabled;
  #endif
} Adc_PwmDiagGroupConfigType;

/*******************************************************************************
** Structure for PWM Diagnostic Group Trigger Source Ids                      **
*******************************************************************************/
/* ADC_PBTYPES_H_007: ADC_ESDD_UD_057 */
typedef struct STag_Adc_PwmDiagIds
{
  /* PWM Diag index   */
  uint16 usPwmDiagIndex;
  /* PWSAnPVCRm index */
  uint8 ucPVCRIndex;
  /*
   * Indicate if trigger is even or odd
   * ucOffset = 0x00 if the trigger is even
   * ucOffset = 0x10 if the trigger is odd
   */
  uint8 ucOffset;
  /*
   * Index for the selected PWM trigger source channel in  array
   * Pwm_GaaChannelCTDRVal[] to which the channel trigger source is configured
   */
  uint8 ucPwmTriggChIndex;
} Adc_PwmDiagIds;

/*******************************************************************************
** Structure for channel group RAM data                                       **
*******************************************************************************/
/* ADC_PBTYPES_H_011: ADC_ESDD_UD_096 */
typedef struct STag_Adc_ChannelGroupRamData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(Adc_ValueGroupType, TYPEDEF, ADC_PUBLIC_CODE) pChannelBuffer;
  /* Stores the conversion status of the requested group */
  Adc_StatusType enGroupStatus;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Stores the Group Notification Status */
  uint8 ucNotifyStatus;
  #endif
  #if ((ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF) && \
                                      (ADC_DEV_ERROR_DETECT == STD_ON))
  /* Stores the buffer pointer initialization Status */
  uint8 ucBufferStatus;
  #endif
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Stores the enable hardware trigger status */
  uint8 ucHwTriggStatus;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                              (ADC_ENABLE_QUEUING == STD_ON)))
  /*
   * Stores the channel count converted before getting interrupted by
   * higher priority group
   */
  uint8 ucReChannelsCompleted;
  /*
   * Stores the count of conversion rounds completed before
   * getting interrupted by higher priority group
   */
  uint8 ucReSamplesCompleted;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stored the status if the group is present in queue */
  uint8 ucGrpPresent;
  #endif
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Stored the count of number of channel disabled */
  uint8 ucNoofChDisabled;
  #endif
  /* Indicates if the conversion of all the samples are completed */
  boolean blSampleComp;
  /*
   * Indicates if the ADC_COMPLETED status has to be prevented once the
   * Group reaches the status of ADC_STREAM_COMPLETED
   */
  boolean blResultRead;
} Adc_ChannelGroupRamData;

/*******************************************************************************
** Structure for channel group RAM data                                       **
*******************************************************************************/
/* ADC_PBTYPES_H_008: ADC_ESDD_UD_058 */
typedef struct STag_Adc_PwmGroupRamData
{
  /* Stores the Group Notification Status */
  uint8 ucTriggSrcIndex;
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Starting channel Index of the group */
  uint8 ucStartChannelIndex;
  #endif
} Adc_PwmGroupRamData;

/*******************************************************************************
** Structure for HW unit RAM data                                             **
*******************************************************************************/
/* ADC_PBTYPES_H_012: ADC_ESDD_UD_097 */
typedef struct STag_Adc_SgUnitRamData
{
  /* Stores Trigger source type of the current conversion group SW/HW */
  Adc_TriggerSourceType enTrigSource;
  /* Stores the current conversion group */
  Adc_GroupType ddCurrentConvGroup;
  /* Stores the current conversion group priority */
  Adc_GroupPriorityType ddCurrentPriority;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stores the queue status */
  uint8 ucQueueStatus;
  /* Stores the queue counter */
  uint8 ucQueueCounter;
  #endif
  /* Stores the current status of the SG unit */
  boolean blSgUnitStatus;
} Adc_SgUnitRamData;

/*******************************************************************************
** Structure for run time data                                                **
*******************************************************************************/
/* ADC_PBTYPES_H_017: ADC_ESDD_UD_050 */
typedef struct STag_Adc_RunTimeData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA) pBuffer;
  /* Stores the count of number of channels in the group */
  uint8 ucChannelCount;
  /* Stores the count of conversion completed channels */
  uint8 ucChannelsCompleted;
  /* Stores the count of streaming samples */
  uint8 ucStreamingSamples;
  /* Stores the count of conversion completed samples */
  uint8 ucSamplesCompleted;
} Adc_RunTimeData;

/*******************************************************************************
** Structure for Ram Mirror mechanism of ADCA Registers                       **
*******************************************************************************/
/* ADC_PBTYPES_H_004: ADC_ESDD_UD_098 */
#if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
typedef struct STag_AdcConfRegRam
{
  uint32 ulADCR;                                   /* ADCR             */
  uint32 ulTHCR;                                   /* THCR             */
  uint32 ulTHACR;                                  /* THACR            */
  uint32 ulTHBCR;                                  /* THBCR            */
  uint32 ulTHER;                                   /* THER             */
  uint32 ulTHGSR;                                  /* THGSR            */
  uint32 ulULLMTBR[ADC_REG_ULLMTBR_ARRAY_SIZE];    /* ULLMTBR          */
  uint32 ulDGCTL0;                                 /* DGCTL0           */
  uint32 ulDGCTL1;                                 /* DGCTL1           */
  uint32 ulPDCTL1;                                 /* PDCTL1           */
  uint32 ulPDCTL2;                                 /* PDCTL2           */
  uint32 ulSMPCR;                                  /* SMPCR            */
}AdcConfRegRam;

typedef struct STag_AdcVirChRegRam
{
  uint32 ulVCR[ADC_REG_VCR_ARRAY_SIZE];            /* VCR              */
}AdcVirChRegRam;

typedef struct STag_AdcSGRegRam
{
  uint32 ulSGCR;                                   /* SGCR;            */
  uint32 ulSGVCSP;                                 /* SGVCSP           */
  uint32 ulSGVCEP;                                 /* SGVCEP           */
  uint32 ulSGTSEL;                                 /* SGTSEL           */
}AdcSGRegRam;
#endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

/*******************************************************************************
** Structure for Ram Mirror mechanism of PWMDIAG Registers                    **
*******************************************************************************/
#if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
typedef struct STag_PWGARegRam
{
  uint16 usCTDR;                                /* CTDR             */
}PWGARegRam;

typedef struct STag_PWSARegRam
{
  uint32 ulPVCR[ADC_REG_PVCR_ARRAY_SIZE];        /* PVCR             */
}PWSARegRam;
#endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

/*******************************************************************************
** Structure for Ram Mirror mechanism of DMAC Registers                    **
*******************************************************************************/
#if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
typedef struct STag_DmaRegRam
{
  uint32 ulDTCT;                                   /* DTCT             */
  uint32 ulDRSA;                                   /* DRSA             */
  uint32 ulDRDA;                                   /* DRDA             */
  uint32 ulDRTC;                                   /* DRTC             */
}DmaRegRam;
#endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */
/*******************************************************************************
** Structure for Mux configuration in each channel                            **
*******************************************************************************/
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                          (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
typedef struct STag_MuxDelayVal
{
  /*Stores the HW delay value.*/
  uint16 usHWDelayCounter;
  /*Stores the index of Mux stabilisation time register.*/
  uint8  ucMuxSelReg;
  /*Stores the index of Mux stabilisation time selection register mask value.*/
  uint32 ulMuxSelMask;
  /*Stores the index of Mux stabilisation time selection register offset.*/
  uint8  ucMuxOffset;
   /*Stores the index of Mux stabilisation time selection register.*/
  uint8 uctbrindex;
}MuxDelayVal;
#endif
/*******************************************************************************
**             Extern declarations for Global Arrays Of Structures            **
*******************************************************************************/
#if (ADC_DMA_MODE_ENABLE == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_DMA_NO_INIT_ASIL_B_32
#else
  #define ADC_START_SEC_VAR_DMA_NO_INIT_32
#endif
#include ADC_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of PWM Group Result data */
extern VAR(uint32, ADC_NOINIT_DATA) Adc_GaaPwmDiagResultData[];
/* END Msg(4:3684)-1 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_DMA_NO_INIT_ASIL_B_32
#else
  #define ADC_STOP_SEC_VAR_DMA_NO_INIT_32
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of PWM Group Runtime data */
extern VAR(Adc_PwmGroupRamData, ADC_NOINIT_DATA) Adc_GstPwmDiagGroupRamData[];
/* END Msg(4:3684)-1 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE
#endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
/* Hardware Unit Queue Size */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(Adc_GroupType, ADC_NOINIT_DATA) Adc_GaaSgUnitPriorityQueue[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* ADC_PBTYPES_H_013: ADC_ESDD_UD_125 */
/* Declaration for SG Unit Configuration */
extern CONST(Adc_HwSgUnitType, ADC_CONST) Adc_GstSgUnitConfig[];
/* Declaration for Hardware unit Configuration */
extern CONST(Adc_HwUnitConfigType, ADC_CONST) Adc_GstHWUnitConfig[];
/* Declaration for Group Configuration */
extern CONST(Adc_GroupConfigType, ADC_CONST) Adc_GstGroupConfig[];
/* END Msg(4:3684)-1 */
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                         (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(MuxDelayVal, ADC_CONFIG_CONST) Adc_GstMuxDelayVal[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for PWM Diagnostic Group Configuration */
extern CONST(Adc_PwmDiagGroupConfigType, ADC_CONST) Adc_GstPwmDiagGroupConfig[];
/* Declaration for PWM Diagnostic Group Trigger Source Ids */
extern CONST(Adc_PwmDiagIds, ADC_CONST) Adc_GstPwmDiagIds[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for DMA Channel Configuration */
extern CONST(Adc_DmaUnitConfig, ADC_CONST) Adc_GstDmaUnitConfig[];
#endif
/* END Msg(4:3684)-1 */
#if (ADC_PWSA_INT_QFULL_ISR == STD_ON)
/* Pointer to callback notification */
extern CONSTP2FUNC (void, ADC_APPL_CODE,
                                    Adc_GpQueueFullNotificationPointer)(void);
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONFIG_DATA_ASIL_B_8
#else
  #define ADC_START_SEC_CONFIG_DATA_8
#endif
#include ADC_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Hardware Index Mapping array */
extern CONST(uint8, ADC_CONST) Adc_GaaHwUnitIndex[];
/* Declaration for SG Unit Index Mapping array */
extern CONST(uint8, ADC_CONST) Adc_GaaSgUnitIndex[];

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Declaration for DMA Channel to HW unit mapping Configuration */
extern CONST(uint8, ADC_CONFIG_CONST) Adc_GaaHwUnit[];
/* Declaration for DMA Channel to SGm unit mapping Configuration */
extern CONST(uint8, ADC_CONFIG_CONST) Adc_GaaSGUnit[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_8
#else
  #define ADC_STOP_SEC_CONFIG_DATA_8
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONFIG_DATA_ASIL_B_16
#else
  #define ADC_START_SEC_CONFIG_DATA_16
#endif
#include ADC_MEMMAP_FILE
/* Declaration for Channel to Group Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint16, ADC_CONFIG_CONST) Adc_GaaChannelToGroup[];
/* END Msg(4:3684)-1 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_16
#else
  #define ADC_STOP_SEC_CONFIG_DATA_16
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONFIG_DATA_ASIL_B_32
#else
  #define ADC_START_SEC_CONFIG_DATA_32
#endif
#include ADC_MEMMAP_FILE
#if (ADC_HW_TRIGGER_API == STD_ON)
/* Declaration for HW Group Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint32, ADC_CONST) Adc_GaaHWGroupTrigg[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Declaration for limit check enabled channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint32, ADC_CONST) Adc_GaaLimitCheckRange[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_32
#else
  #define ADC_STOP_SEC_CONFIG_DATA_32
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_DMA_NO_INIT_ASIL_B_16
#else
  #define ADC_START_SEC_VAR_DMA_NO_INIT_16
#endif
#include ADC_MEMMAP_FILE
#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
/* RAM Allocation of result data */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(Adc_ValueGroupType, ADC_NOINIT_DATA) Adc_GaaResultGroupRamData[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_DMA_NO_INIT_ASIL_B_16
#else
  #define ADC_STOP_SEC_VAR_DMA_NO_INIT_16
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of Group data */
extern VAR(Adc_ChannelGroupRamData, ADC_NOINIT_DATA) Adc_GstGroupRamData[];
/* RAM Allocation of hardware unit data */
extern VAR(Adc_SgUnitRamData, ADC_NOINIT_DATA) Adc_GstSgUnitRamData[];

/* RAM Allocation of Group Runtime data */
extern VAR(Adc_RunTimeData, ADC_NOINIT_DATA) Adc_GstRunTimeData[];
/* END Msg(4:3684)-1 */


#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Declaration for Disable Channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(boolean, ADC_NOINIT_DATA) Adc_GaaChannelToDisableEnable[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* RAM Allocation of PWM Group Result data */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_DMA_DB_NO_INIT_ASIL_B_32
#else
  #define ADC_START_SEC_VAR_DMA_DB_NO_INIT_32
#endif
#include ADC_MEMMAP_FILE
#if ((ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) &&\
     (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON))

/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(uint32, ADC_NOINIT_DATA) Adc_GaaPwmDiagDoubleResultData[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_DMA_DB_NO_INIT_ASIL_B_32
#else
  #define ADC_STOP_SEC_VAR_DMA_DB_NO_INIT_32
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
