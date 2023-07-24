/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable declarations.                                              */
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
/* ADC_RAM_H_002 EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0045,EAAR_PN0034_NR_0056  */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V2.0.0:  19-Aug-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_GaaRamMirrorAdcConfReg,
 *                              Adc_GaaRamMirrorAdcVirChReg,
 *                              Adc_GaaRamMirrorAdcSGReg,
 *                              Adc_GaaRamMirrorPWGAReg,
 *                              Adc_GaaRamMirrorPWSAReg,
 *                              Adc_GaaRamMirrorDmaReg
 *                              Ram Mirrors are added.
 * V2.1.0:  28-Oct-2016     : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE
 * V2.1.2:  19-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              The Ram Mirror variables are moved to the
 *                              correct memory section _UNSPECIFIED
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage and includes
 * V2.2.1:  06-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-913,
 *                              Added <ADC_> prefix to remained macro
 *                              definitions.
 * V2.3.0: 07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725 ,
 *                            a. Support for mux hardware stabilisation time
 *                               is implemented.
 *                            b. Declaration for Adc_GstMuxDelayVal is added.
 *                            c. Declaration for Adc_GpMuxDelayVal is added.
 * V2.3.1: 27-Jun-2018    : Following changes are made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Moved global variables Adc_GucMuxChnlCnt,
 *                                Adc_GucMuxStartChannel from
 *                                VAR_NO_INIT_UNSPECIFIED to VAR_NO_INIT_8.
 *                                Ref: ARDAABD-908.
 *                              b.Copyright updated.
 *                            2.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 */
/******************************************************************************/
/* ADC_RAM_H_001: EAAR_PN0034_FR_0001 */
#ifndef ADC_RAM_H
#define ADC_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for macro definitions and structure declarations */
#include "Adc_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_RAM_AR_RELEASE_MAJOR_VERSION     ADC_AR_RELEASE_MAJOR_VERSION
#define ADC_RAM_AR_RELEASE_MINOR_VERSION     ADC_AR_RELEASE_MINOR_VERSION
#define ADC_RAM_AR_RELEASE_REVISION_VERSION  ADC_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define ADC_RAM_SW_MAJOR_VERSION   ADC_SW_MAJOR_VERSION
/* MISRA Violation: START Msg(6:0857)-1 */
#define ADC_RAM_SW_MINOR_VERSION   ADC_SW_MINOR_VERSION
/* END Msg(6:0857)-1 */
/* ADC_RAM_H_003 EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:0857)Number of macro definitions exceeds 1024 - program */
/*                 does not conform strictly to ISO:C99.                      */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-1 and                           */
/*                 END Msg(6:0857)-1 tags in the code.                        */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* Global pointer variable for hardware unit configuration */
extern P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST)
Adc_GpHwUnitConfig;

/* Global pointer variable for Scan group unit configuration */
extern P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST)Adc_GpSgUnitConfig;

/* Global pointer variable for group configuration */
extern P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_CONFIG_CONST)
Adc_GpGroupConfig;

#if (ADC_HW_TRIGGER_API == STD_ON)
/* Global pointer variable for HW group configuration */
extern P2CONST(uint32, ADC_VAR, ADC_CONFIG_CONST)Adc_GpHWGroupTrigg;
#endif

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Global pointer variable for PWM Diagnostic group configuration */
extern P2CONST(Adc_PwmDiagGroupConfigType, ADC_VAR, ADC_CONFIG_CONST)
Adc_GpPwmDiagGroupConfig;
/* Global pointer variable for PWM diagnostic group Trigger Source Ids */
extern P2CONST(Adc_PwmDiagIds, ADC_VAR, ADC_CONFIG_CONST) Adc_GpPwmDiagIds;
/* Global pointer for PWM Diagnostic group RAM data */
extern P2VAR(Adc_PwmGroupRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpPwmGroupData;
/* Global pointer to RAM array which hold the CDTR value */
extern P2VAR(uint16, ADC_NOINIT_DATA, ADC_CONFIG_DATA) Adc_GpPwmChannelCTDRVal;
#endif

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Global pointer variable for HW group configuration */
extern P2CONST(Adc_DmaUnitConfig, ADC_VAR, ADC_CONFIG_CONST)
Adc_GpDmaUnitConfig;
/* Global pointer to DMA HW unit array mapping */
extern P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpDmaHWUnitMapping;
/* Global pointer to DMA SG unit array mapping */
extern P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpDmaSGUnitMapping;
#endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

/* Declaration for Hardware Index Mapping array */
extern P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpHwUnitIndex;

/* Declaration for SG unit Index Mapping array */
extern P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpSgUnitIndex;

/* Global pointer variable for channel to group data */
extern P2CONST(AdcVirChRegisters, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
                                                          Adc_GpChannelToGroup;

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Global pointer variable for limit check enabled configuration */
extern P2CONST(uint32, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpLimitCheckRange;
#if (ADC_FLEXIBLE_THRESHOLD == STD_ON)
/* Global pointer variable for limit check enabled configuration */
extern P2VAR(uint32, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpFlexibleLimitCheckRange;
#endif
#endif
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                          (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
/* Declaration for Mux Hardware stabilisation time  Mapping array */
extern P2CONST(MuxDelayVal, ADC_VAR, ADC_CONFIG_CONST)Adc_GpMuxDelayVal;

#endif

/* Global pointer variable for channel to group data */

#if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_FLEXIBLE_THRESHOLD == STD_ON))
/* Global pointer variable for channel to group data */
extern P2VAR(uint16, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpFlexibleChannelToGroup;
#endif

/* Global pointer variable for group RAM data */
extern P2VAR(Adc_ChannelGroupRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpGroupRamData;

#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Global pointer variable for channel to Disable Enable data */
extern P2VAR(boolean, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpChannelToDisableEnable;
#endif

/* Global pointer variable for hardware unit RAM data */
extern P2VAR(Adc_SgUnitRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpSgUnitRamData;

/* Global pointer variable for runtime RAM data */
extern P2VAR(Adc_RunTimeData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpRunTimeData;

#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
/* Global pointer variable for result data storage */
extern P2VAR(Adc_ValueGroupType, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
                                                      Adc_GpResultGroupRamData;
#endif

#if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Indicates the ADCA Registers Ram Mirror for Hardware Consistency Check */
extern VAR(AdcConfRegRam, ADC_NOINIT_DATA)
                    Adc_GaaRamMirrorAdcConfReg[ADC_CONFREG_INSTANCES];
extern VAR(AdcVirChRegRam, ADC_NOINIT_DATA)
                    Adc_GaaRamMirrorAdcVirChReg[ADC_VIRCHREG_INSTANCES];
extern VAR(AdcSGRegRam, ADC_NOINIT_DATA)
                    Adc_GaaRamMirrorAdcSGReg[ADC_SGREG_INSTANCES];
#endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

#if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Indicates the PWMDIAG Registers Ram Mirror for Hardware Consistency Check */
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
extern VAR(PWGARegRam, ADC_NOINIT_DATA)
                       Adc_GaaRamMirrorPWGAReg[ADC_PWGAREG_INSTANCES];
extern VAR(PWSARegRam, ADC_NOINIT_DATA) Adc_GaaRamMirrorPWSAReg;
#endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
#endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

#if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Indicates the DMAC Registers Ram Mirror for Hardware Consistency Check */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
extern VAR(DmaRegRam, ADC_NOINIT_DATA)
                      Adc_GaaRamMirrorDmaReg[ADC_DMAREG_INSTANCES];
#endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
#endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */

/* MISRA Violation: START Msg(6:0857)-1 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
/* END Msg(6:0857)-1 */
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define ADC_START_SEC_VAR_NO_INIT_8
#endif
#include ADC_MEMMAP_FILE

/* Indicates max no of SW triggered groups configured */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucMaxSwTriggGroups;
/* Indicates total no of groups configured in the configset */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfGroups;

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Indicates the maximum PWM diagnostic groups configured */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfPwmDiagGroups;
#endif
/*Structure for Mux configuration in each channel */
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                          (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
/* Indicates total no of Mux channel configured in the a configset */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucMuxChnlCnt;
/* Indicates starting index of Mux channel configured in the a configset. */
extern VAR(uint8, ADC_NOINIT_DATA)Adc_GucMuxStartChannel;
#endif
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Indicates no of DMA channel Ids configured */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucMaxDmaChannels;
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Indicates no of DMA channel Ids configured for PWM Diagnostic */
extern VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfPwmDiagDmaChannels;
#endif
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_8
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define ADC_START_SEC_VAR_INIT_BOOLEAN
#endif
#include ADC_MEMMAP_FILE

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Holds the status of Initialization */
extern VAR(boolean, ADC_INIT_DATA) Adc_GblDriverStatus;
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define ADC_STOP_SEC_VAR_INIT_BOOLEAN
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
