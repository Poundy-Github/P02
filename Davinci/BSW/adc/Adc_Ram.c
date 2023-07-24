/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable definitions                                                */
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
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056   */
/* Implements AR_PN0076_FR_0027 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  12-Jan-2016    : The following changes are made:
 *                           1. Include section updated.
 * V2.0.0:  19-Aug-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_GaaRamMirrorAdcConfReg,
 *                              Adc_GaaRamMirrorAdcVirChReg,
 *                              Adc_GaaRamMirrorAdcSGReg,
 *                              Adc_GaaRamMirrorPWGAReg,
 *                              Adc_GaaRamMirrorPWSAReg,
 *                              Adc_GaaRamMirrorDmaReg
 *                              Ram Mirrors are added
 *                           2. As part of JIRA ticket ARDAABC-810,
 *                              add traces in code for WV, HWCC and Endless Loop
 *                              FUSA requirements.
 * V2.1.0:  28-Oct-2016     : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE, moved HWCC RAM
 *                              Mirrors to UNSPECIFIED memory map.
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.2.1:  06-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-913,
 *                              Added <ADC_> prefix to remained macro
 *                              definitions.
 * V2.3.0:  07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725 , global variable
 *                           Adc_GucMuxChnlCnt and Adc_GucMuxStartChannel are
 *                           added.
 * V2.3.1:  27-Jun-2018    : Following change made:
 *                            As part of traceability improvement activity
 *                            ticket ARDAABD-2101, requirements and UD Ids are
 *                            added.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements: ADC267, SWS_Adc_00267 */
/* Included for version check macro definitions and type definitions */
#include "Adc.h"
/* Included for macro definitions and structure declarations */
#include "Adc_PBTypes.h"
/* Included for extern declarations of global variables */
#include "Adc_Ram.h"
/* Included for macro definitions and structure declaration */
#include"Adc_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define ADC_RAM_C_AR_RELEASE_MAJOR_VERSION    ADC_AR_RELEASE_MAJOR_VERSION_VALUE
#define ADC_RAM_C_AR_RELEASE_MINOR_VERSION    ADC_AR_RELEASE_MINOR_VERSION_VALUE
#define ADC_RAM_C_AR_RELEASE_REVISION_VERSION \
                                           ADC_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ADC_RAM_C_SW_MAJOR_VERSION    ADC_SW_MAJOR_VERSION_VALUE
#define ADC_RAM_C_SW_MINOR_VERSION    ADC_SW_MINOR_VERSION_VALUE
/* Implements EAAR_PN0034_FR_0055, ADC124 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_RAM_AR_RELEASE_MAJOR_VERSION != ADC_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Adc_Ram.c : Mismatch in Release Major Version"
#endif

#if (ADC_RAM_AR_RELEASE_MINOR_VERSION != ADC_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Adc_Ram.c : Mismatch in Release Minor Version"
#endif

#if (ADC_RAM_AR_RELEASE_REVISION_VERSION != \
                                          ADC_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Adc_Ram.c : Mismatch in Release Revision Version"
#endif

#if (ADC_RAM_SW_MAJOR_VERSION != ADC_RAM_C_SW_MAJOR_VERSION)
  #error "Adc_Ram.c : Mismatch in Software Major Version"
#endif

#if (ADC_RAM_SW_MINOR_VERSION != ADC_RAM_C_SW_MINOR_VERSION)
  #error "Adc_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* Implements ADC_ESDD_UD_126 */
/* Implements ADC439 */
/* Global pointer variable for hardware unit configuration */
P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST)Adc_GpHwUnitConfig;

/* Global pointer variable for Scan group unit configuration */
P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST)Adc_GpSgUnitConfig;

/* Global pointer variable for group configuration */
P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_CONFIG_CONST)Adc_GpGroupConfig;

#if (ADC_HW_TRIGGER_API == STD_ON)
/* Global pointer variable for HW group configuration */
P2CONST(uint32, ADC_VAR, ADC_CONFIG_CONST)Adc_GpHWGroupTrigg;
#endif

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Global pointer variable for PWM Diagnostic group configuration */
P2CONST(Adc_PwmDiagGroupConfigType, ADC_VAR, ADC_CONFIG_CONST)
Adc_GpPwmDiagGroupConfig;
/* Global pointer variable for PWM diagnostic group Trigger Source Ids */
P2CONST(Adc_PwmDiagIds, ADC_VAR, ADC_CONFIG_CONST) Adc_GpPwmDiagIds;
/* Global pointer for PWM Diagnostic group RAM data */
P2VAR(Adc_PwmGroupRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA) Adc_GpPwmGroupData;
/* Global pointer to RAM array which hold the CDTR value */
P2VAR(uint16, ADC_NOINIT_DATA, ADC_CONFIG_DATA) Adc_GpPwmChannelCTDRVal;
#endif

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Global pointer variable for HW group configuration */
P2CONST(Adc_DmaUnitConfig, ADC_VAR, ADC_CONFIG_CONST)Adc_GpDmaUnitConfig;
/* Global pointer to DMA HW unit array mapping */
P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpDmaHWUnitMapping;
/* Global pointer to DMA SG unit array mapping */
P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpDmaSGUnitMapping;
#endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

/* Declaration for Hardware Index Mapping array */
P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpHwUnitIndex;
/* Declaration for SG unit Index Mapping array */
P2CONST(uint8, ADC_VAR, ADC_CONFIG_CONST)Adc_GpSgUnitIndex;
/* Global pointer variable for channel to group data */
P2CONST(AdcVirChRegisters, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
                                                        Adc_GpChannelToGroup;

/* Implements ADC_ESDD_UD_039 */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Global pointer variable for limit check enabled configuration */
P2CONST(uint32, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpLimitCheckRange;
#if (ADC_FLEXIBLE_THRESHOLD == STD_ON)
/* Global pointer variable for limit check enabled configuration */
P2VAR(uint32, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpFlexibleLimitCheckRange;
#endif
#endif
/* Implements ADC_ESDD_UD_040 */
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                         (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
/* Declaration for Mux Hardware stabilisation time  Mapping array */
P2CONST(MuxDelayVal, ADC_VAR, ADC_CONFIG_CONST)Adc_GpMuxDelayVal;

#endif

#if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
/* Global pointer variable for channel to group data */
P2VAR(uint16, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpFlexibleChannelToGroup;
#endif
/* Global pointer variable for group RAM data */
P2VAR(Adc_ChannelGroupRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
Adc_GpGroupRamData;

/* Implements ADC_ESDD_UD_042 */
#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Global pointer variable for channel to Disable Enable data */
P2VAR(boolean, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpChannelToDisableEnable;
#endif

/* Global pointer variable for hardware unit RAM data */
P2VAR(Adc_SgUnitRamData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpSgUnitRamData;

/* Global pointer variable for runtime RAM data */
P2VAR(Adc_RunTimeData, ADC_NOINIT_DATA, ADC_CONFIG_DATA)Adc_GpRunTimeData;

/* Implements ADC_ESDD_UD_043 */
#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
/* Global pointer variable for RAM allocation of result data */
P2VAR(Adc_ValueGroupType, ADC_NOINIT_DATA, ADC_CONFIG_DATA)
                                                      Adc_GpResultGroupRamData;
#endif
/* Implements ADC_ESDD_UD_049 */
#if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Implements EAAR_PN0034_FSR_0005 */
/* Indicates the ADCA Registers Ram Mirror for Hardware Consistency Check */
VAR(AdcConfRegRam, ADC_NOINIT_DATA)
                      Adc_GaaRamMirrorAdcConfReg[ADC_CONFREG_INSTANCES];
VAR(AdcVirChRegRam, ADC_NOINIT_DATA)
                      Adc_GaaRamMirrorAdcVirChReg[ADC_VIRCHREG_INSTANCES];
VAR(AdcSGRegRam, ADC_NOINIT_DATA)
                      Adc_GaaRamMirrorAdcSGReg[ADC_SGREG_INSTANCES];
#endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

#if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Implements EAAR_PN0034_FSR_0005 */
/* Indicates the PWMDIAG Registers Ram Mirror for Hardware Consistency Check */
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
VAR(PWGARegRam, ADC_NOINIT_DATA) Adc_GaaRamMirrorPWGAReg[ADC_PWGAREG_INSTANCES];
VAR(PWSARegRam, ADC_NOINIT_DATA) Adc_GaaRamMirrorPWSAReg;
#endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
#endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

#if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
/* Implements EAAR_PN0034_FSR_0005 */
/* Indicates the DMAC Registers Ram Mirror for Hardware Consistency Check */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
VAR(DmaRegRam, ADC_NOINIT_DATA) Adc_GaaRamMirrorDmaReg[ADC_DMAREG_INSTANCES];
#endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
#endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_VAR_NO_INIT_ASIL_B_8
#else
  #define ADC_START_SEC_VAR_NO_INIT_8
#endif
#include ADC_MEMMAP_FILE


/* Indicates max no of SW triggered groups configured */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucMaxSwTriggGroups;
/* Indicates total no of configured in configset */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfGroups;

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Indicates the least PWM diagnostic group configured in this configuration */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfPwmDiagGroups;

#endif
#if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                         (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
/* Indicates total no of groups configured in the configset */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucMuxChnlCnt;
VAR(uint8, ADC_NOINIT_DATA) Adc_GucMuxStartChannel;
#endif
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Indicates no of DMA channel Ids configured */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucMaxDmaChannels;
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* Indicates the maximum PWM diagnostic groups configured */
VAR(uint8, ADC_NOINIT_DATA) Adc_GucNoOfPwmDiagDmaChannels;
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
VAR(boolean, ADC_INIT_DATA) Adc_GblDriverStatus = ADC_UNINITIALIZED;
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#else
  #define ADC_STOP_SEC_VAR_INIT_BOOLEAN
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
