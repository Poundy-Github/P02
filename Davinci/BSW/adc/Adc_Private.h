/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Private.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Private functions declarations.                                            */
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
 *                              Declaration for APIs Adc_HwCusSetSamplingClock
 *                              and Adc_IntCusGetPWSAnPVCRx_y are added.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              'extern' keyword is removed from function
 *                              declarations.
 * V2.0.0:  19-Aug-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_InitRamMirror() is added.
 * V2.0.1:  3-Oct-2016     : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-780,
 *                           Declaration of Adc_ConfigureGroupForConversion
 *                           appears twice, one is removed.
 * V2.1.0:  28-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                           Autosar version 3.2.2. was removed and
 *                           4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE
 * V2.1.2:  18-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                           Adc_HwCheckHWConsistency() function was added.
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.2.1:  27-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Input variable renamed for function
 *                              Adc_HwCheckHWConsistency().
 * V2.3.0:  07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725 ,
 *                            a. Support for mux hardware stabilisation time
 *                               is implemented.
 *                            b. Support for ADC group Hard stop is implemented.
 * V2.3.1:  15-Sep-2017    : Following changes are made:
 *                            1. As part of ARDAABD-2387,
 *                             a. Data type of input parameter LddGroup of the
 *                                function Adc_IntDisableHwTrigger is changed to
 *                                Adc_GroupType.
 * V2.3.2:  27-Jun-2018    : Following changes are made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Adc_ImrInterruptBit renamed to
 *                                Adc_IcrInterruptBit.Ref: ARDAABD-2158
 *                              b.Copyright information is updated.
 *                            2.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 * V2.3.3:  13-Nov-2019    : Following changes are made:
 *                            1.As part of ticket ARDAABD-2787,
 *                              a.Added Adc_HaltADConversion function
 *                                declaration.
 *                              b.Added Adc_SaveRegAndHaltADConversion 
 *                                Adc_WriteBackRegforADConversion declaration.
 */
/******************************************************************************/
/* ADC_PRIVATE_H_001: EAAR_PN0034_FR_0001 */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Macro definitions */
#include "Adc.h"
/* Included for macro definitions and structure declarations */
#include "Adc_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_PRIVATE_AR_RELEASE_MAJOR_VERSION  ADC_AR_RELEASE_MAJOR_VERSION
#define ADC_PRIVATE_AR_RELEASE_MINOR_VERSION  ADC_AR_RELEASE_MINOR_VERSION
#define ADC_PRIVATE_AR_RELEASE_REVISION_VERSION  ADC_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ADC_PRIVATE_SW_MAJOR_VERSION  ADC_SW_MAJOR_VERSION
#define ADC_PRIVATE_SW_MINOR_VERSION  ADC_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Declaration of API "Adc_HwInit". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwInit(void);
FUNC(void, ADC_PRIVATE_CODE) Adc_HwCusSetSamplingClock(Adc_HardwareIndexType
                                 HwIndex, Adc_SamplingClockType SamplingClock);

#if (ADC_DEINIT_API == STD_ON)
/* Declaration of API "Adc_HwDeInit". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwDeInit(void);
#endif
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/* Declaration of API "Adc_HwStartGroupConversion". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwStartGroupConversion(Adc_GroupType Group);
/* Declaration of API "Adc_HwStopGroupConversion". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwStopGroupConversion(Adc_GroupType Group);
#endif
#if (ADC_HW_TRIGGER_API == STD_ON)
/* Declaration of API "Adc_HwEnableHardwareTrigger". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwEnableHardwareTrigger(Adc_GroupType Group);
/* Declaration of API "Adc_HwDisableHardwareTrigger". */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwDisableHardwareTrigger(Adc_GroupType Group);
/* Declaration of API "Adc_EnableHWGroup". */
FUNC(void, ADC_PRIVATE_CODE) Adc_EnableHWGroup(Adc_GroupType LddGroup);
/* Declaration of API "Adc_DisableHWGroup". */
FUNC(void, ADC_PRIVATE_CODE) Adc_DisableHWGroup(Adc_GroupType LddGroup);
#endif

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
           ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
/* Declaration of API "Adc_PushToQueue". */
FUNC(void, ADC_PRIVATE_CODE) Adc_PushToQueue(Adc_GroupType LddGroup);

/* Declaration of API "Adc_SearchnDelete". */
FUNC(void, ADC_PRIVATE_CODE) Adc_SearchnDelete(Adc_GroupType LddGroup);

#endif
/* Declaration of API "Adc_ConfigureGroupForConversion". */
FUNC(void, ADC_PRIVATE_CODE) Adc_ConfigureGroupForConversion
                                                   (Adc_GroupType LddGroup);

/* Declaration of API "Adc_StateTransition". */
FUNC(void, ADC_PRIVATE_CODE) Adc_StateTransition(Adc_GroupType LddGroup);

/* Declaration of API "Adc_IntCusGetADCAnDRmAddr". */
FUNC(Adc_AddressType, ADC_PRIVATE_CODE) Adc_IntCusGetADCAnDRmAddr
                                                      (Adc_GroupType LddGroup);

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Declaration of API "Adc_IntEnableHwTrigger". */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntEnableHwTrigger(Adc_GroupType LddGroup);
/* Declaration of API "Adc_IntDisableHwTrigger". */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntDisableHwTrigger(Adc_GroupType LddGroup);
/* Declaration of API "Adc_IntHwResultReadGroup". */
FUNC(Std_ReturnType, ADC_PRIVATE_CODE) Adc_IntHwResultReadGroup
(Adc_GroupType LddGroup,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) pDataBuffer);
FUNC(Adc_PWSARegisterType, ADC_PRIVATE_CODE)Adc_IntCusGetPWSAnPVCRx_y
(uint8 PwmDiagChannelID);
#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */

#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Declaration of API "Adc_IntDisableEnableChannel". */
extern FUNC(void, ADC_PRIVATE_CODE) Adc_IntDisableEnableChannel
(Adc_GroupType LddGroup, Adc_ChannelType LddChannelId, boolean LblApiType);
#endif
#if (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT)
/* Declaration of API "Adc_PollingReadGroup". */
extern FUNC(void, ADC_PRIVATE_CODE) Adc_PollingReadGroup
                               (Adc_GroupType LddGroup, uint8 LucChannelCount);
#endif

#if ( ADC_ERROR_SUPPORT == STD_ON)
/* Declaration of API "Adc_IntEnableDisableAdcErr". */
extern FUNC(void, ADC_PRIVATE_CODE) Adc_IntEnableDisableAdcErr(uint8 LucHwUnit,
boolean LblApiType);
#endif
#if (ADC_HARD_STOP == STD_OFF)
/* Function to perform ADHALT operation */
FUNC(void, ADC_PRIVATE_CODE) Adc_HaltScanGroup(Adc_GroupType Group);
#elif(ADC_HARD_STOP == STD_ON)
/* Function Stop conversion of all SG unit using ADCAnSGSTPCRx Register. */
FUNC(void, ADC_PRIVATE_CODE) Adc_StopScanGroup(Adc_GroupType LddGroup);
#endif

/* Function to perform halt AD conversion operation */
FUNC(void, ADC_PRIVATE_CODE) Adc_HaltADConversion(const uint8 LucHwUnitIndex);

FUNC(void, ADC_PRIVATE_CODE) Adc_SaveRegAndHaltADConversion(
  const uint8 LucHwUnit,
  P2VAR(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGCR,
  P2VAR(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGSTR,
  const uint8 LucApiId);

FUNC(void, ADC_PRIVATE_CODE) Adc_WriteBackRegforADConversion(
  const uint8 LucHwUnit,
  P2CONST(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGCR,
  const uint32 LulRegSGSTR,
  const uint8 LucApiId);

#if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
FUNC(void, ADC_PRIVATE_CODE) Adc_InitRamMirror(void);
#endif  /*((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))*/

#if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_HwCheckHWConsistency
                   (Adc_HWConsistencyCheckType LddCheckType);
#endif  /*((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))*/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
/* Declaration of API "Adc_PopFromQueue". */
FUNC(Adc_GroupType, ADC_FAST_CODE) Adc_PopFromQueue(uint8 LucSgUnitIndex);
/* Declaration of API "Adc_IsrConfigureGroupForConversion". */
FUNC(void, ADC_FAST_CODE) Adc_IsrConfigureGroupForConversion
                                                       (Adc_GroupType LddGroup);
#endif

#if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
/* Declaration of API "Adc_Isr". */
FUNC(void, ADC_FAST_CODE) Adc_Isr(uint8 LucHwUnit, uint8 LucSGUnit);
/* Declaration of API "Adc_IcrInterruptBit". */
FUNC(void, ADC_FAST_CODE) Adc_IcrInterruptBit(uint8 LucSgUnitIndex,
boolean LblEnableOrDisableInterrupt);
/* Declaration of API "Adc_ClearPendingInterrupt". */
FUNC(void, ADC_FAST_CODE) Adc_ClearPendingInterrupt(uint8 LucHwUnit,
uint8 LucSgUnitId);
#endif

#if (ADC_ERROR_SUPPORT == STD_ON)
/* Declaration of API "Adc_ErrIsr". */
FUNC(void, ADC_FAST_CODE) Adc_ErrIsr(uint8 LucHwUnit);
#endif

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Declaration of API "Adc_DmaIsr". */
FUNC(void, ADC_FAST_CODE) Adc_DmaIsr(uint8 LucHwUnit, uint8 LucSGUnit);
#endif

/* Declaration of API "Adc_GroupCompleteMode". */
FUNC(void, ADC_FAST_CODE) Adc_GroupCompleteMode(Adc_GroupType LddGroup,
                                                   uint8 LucHwUnit);

#if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
            (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                         (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
/* Declaration of API "Adc_ChannelCompleteMode". */
FUNC(void, ADC_FAST_CODE) Adc_ChannelCompleteMode(Adc_GroupType LddGroup,
                                                    uint8 LucHwUnit);
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_PRIVATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
