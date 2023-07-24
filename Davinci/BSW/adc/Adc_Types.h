/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 *                              New enumerations 'Adc_HardwareIndexType' and
 *                              'Adc_SamplingClockType' are added.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              New types Adc_PWSAReturnType and
 *                              Adc_PWSARegisterType are added.
 *                           3. Include section is updated.
 *                           4. As a part of JIRA ticket ARDAAGA-72,
 *                              Structure 'STag_Adc_ConfigType' is added.
 *                           5. Definition for macros ADC_DMA_TYPE_ONE and
 *                              ADC_DMA_TYPE_TWO are removed.
 * V2.0.0:  19-Aug-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Functional safety types and macros are added.
 *                           2. As part of JIRA ticket ARDAABC-810,
 *                              add traces in code for WV, HWCC and Endless Loop
 *                              FUSA requirements.
 * V2.1.0:  28-Oct-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE.
 * V2.1.2:  20-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-929,
 *                              TYPEDEFS are used instead of AUTOMATIC
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              moved AUTOSAR release macros before includes
 * V2.3.0:  07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725,
 *                            a. support for mux hardware stabilisation time
 *                               is implemented.
 *                            b. Elements pMuxDelayVal, ucMuxStartChannel and
 *                               ucMuxChnlCnt are added.
 *                               in STag_Adc_ConfigType structure.
 *                            c. Module Software minor version updated.
 * V2.3.1:  27-Jun-2018    : Following changes are made:
 *                           1. As part of ARDAABD-3813,
 *                              The element ucThresholdOffset is added in
 *                              Adc_GstConfiguration structure.
 *                           2. As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 */
/******************************************************************************/
/* ADC_TYPES_H_042: EAAR_PN0034_FR_0001 */
#ifndef ADC_TYPES_H
#define ADC_TYPES_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define ADC_AR_FOUR_TWO_TWO       422
#define ADC_AR_FOUR_ZERO_THREE    403

#define ADC_AR_HIGHER_VERSION     ADC_AR_FOUR_TWO_TWO
#define ADC_AR_LOWER_VERSION      ADC_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* ADC_TYPES_H_044: ADC267, SWS_Adc_00267, ADC364, SWS_Adc_00364 */
/* Included for pre-compile options */
#include "Adc_Cfg.h"
/* AUTOSAR standard types */
#include "Std_Types.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* ADC_TYPES_H_018: ADC_ESDD_UD_038 */
#if (ADC_AR_VERSION  == ADC_AR_HIGHER_VERSION)
/* AUTOSAR Release version information */
#define ADC_TYPES_AR_RELEASE_MAJOR_VERSION       4U
#define ADC_TYPES_AR_RELEASE_MINOR_VERSION       2U
#define ADC_TYPES_AR_RELEASE_REVISION_VERSION    2U
#elif (ADC_AR_VERSION  == ADC_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define ADC_TYPES_AR_RELEASE_MAJOR_VERSION       4U
#define ADC_TYPES_AR_RELEASE_MINOR_VERSION       0U
#define ADC_TYPES_AR_RELEASE_REVISION_VERSION    3U
#endif
/* Module Software version information */
#define ADC_TYPES_SW_MAJOR_VERSION   1
#define ADC_TYPES_SW_MINOR_VERSION   1

/******************************************************************************/

/* ADC_TYPES_H_043: EAAR_PN0034_FR_0019 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* ADC_TYPES_H_032: ADC_ESDD_UD_141 */
/* ADC_TYPES_H_045: SWS_Adc_00522 */
/* Priority Implementation values */
#define ADC_PRIORITY_NONE            0
#define ADC_PRIORITY_HW              1
#define ADC_PRIORITY_HW_SW           2

/* Macros of ADC processing Mode */
#define ADC_INTERRUPT                0
#define ADC_POLLING                  1
#define ADC_POLLING_INTERRUPT        2

/* ADC_TYPES_H_001: EAAR_PN0034_FSR_0002 */
/* Macros of Write-Verify mechanism */
#define ADC_WV_DISABLE               0
#define ADC_WV_INIT_ONLY             1
#define ADC_WV_INIT_RUNTIME          2

/* Macros of Hardware Consistency Check using RAM Mirror mechanism */
#define ADC_MIRROR_DISABLE           0
#define ADC_MIRROR_ENABLE            1

/* ADC_TYPES_H_020: SWS_Adc_00506 */
/* ADC_TYPES_H_021: ADC_ESDD_UD_129 */
/* Numeric identifier of an ADC channel */
typedef uint8 Adc_ChannelType;

 /* ADC_TYPES_H_002: SWS_Adc_00512 */
/* Numeric identifier of channel resolution in number of bits */
typedef uint8 Adc_ResolutionType;

/* ADC_TYPES_H_003: SWS_Adc_00507, ADC090, SWS_Adc_00090 */
/* ADC_TYPES_H_017: ADC_ESDD_UD_032, ADC_ESDD_UD_130 */
/* ADC_TYPES_H_022: ADC091, SWS_Adc_00091 */
/* Numeric identifier of an ADC channel group */
typedef uint8 Adc_GroupType;

/* ADC_TYPES_H_004: SWS_Adc_00508 */
/* ADC_TYPES_H_023: ADC_ESDD_UD_131 */
/* Adc converted value type */
typedef uint16 Adc_ValueGroupType;

/* ADC_TYPES_H_005: SWS_Adc_00521 */
/* ADC_TYPES_H_035: ADC_ESDD_UD_144 */
/* Adc HW Trigger Timer type */
typedef uint8 Adc_HwTriggerTimerType;

/* ADC_TYPES_H_006: SWS_Adc_00518 */
/* ADC_TYPES_H_028: ADC_ESDD_UD_137 */
/* Number of samples of the streaming buffer group */
typedef uint8 Adc_StreamNumSampleType;

/* ADC Virtual Channel Register type for F1x and R1x*/
typedef uint16 AdcVirChRegisters;

/* Adc Threshold Category type */
typedef uint8 Adc_ThresholdType;
/* Adc Threshold Category type */
typedef uint32 Adc_AddressType;

#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
typedef uint32 Adc_PWSARegisterType;
typedef uint16 Adc_PWSAReturnType;
#endif

/* ADC_TYPES_H_007: SWS_Adc_00513 */
/* ADC_TYPES_H_024: ADC_ESDD_UD_133 */
/* Current status of the conversion of the requested ADC Channel group */
typedef enum ETag_Adc_StatusType
{
  ADC_IDLE,
  ADC_BUSY,
  ADC_COMPLETED,
  ADC_STREAM_COMPLETED
} Adc_StatusType;

/* ADC_TYPES_H_008: SWS_Adc_00514 */
/* ADC_TYPES_H_025: ADC_ESDD_UD_134 */
/* Type for configuring the trigger source for an ADC Channel group */
typedef enum ETag_Adc_TriggerSourceType
{
  ADC_TRIGG_SRC_SW,
  ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/* ADC_TYPES_H_009: SWS_Adc_00515 */
/* ADC_TYPES_H_026: ADC_ESDD_UD_135 */
/* Type for configuring the conversion mode of an ADC Channel group */
typedef enum ETag_Adc_GroupConvModeType
{
  ADC_CONV_MODE_ONESHOT,
  ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* ADC_TYPES_H_010: SWS_Adc_00519 */
/* ADC_TYPES_H_029: ADC_ESDD_UD_138 */
/* Type for configuring the streaming access mode buffer type. */
typedef enum ETag_Adc_StreamBufferModeType
{
  ADC_STREAM_BUFFER_LINEAR,
  ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/* ADC_TYPES_H_011: SWS_Adc_00528 */
/* ADC_TYPES_H_030: ADC_ESDD_UD_139 */
/* Type for configuring the access mode to group conversion results */
typedef enum ETag_Adc_GroupAccessModeType
{
  ADC_ACCESS_MODE_SINGLE,
  ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;

/* ADC_TYPES_H_012: SWS_Adc_00523 */
/* ADC_TYPES_H_033: ADC_ESDD_UD_142 */
/* Type for replacement mechanism, which is used on ADC group level */
typedef enum ETag_Adc_GroupReplacementType
{
  ADC_GROUP_REPL_ABORT_RESTART,
  ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;

/* ADC_TYPES_H_013: SWS_Adc_00520 */
/* ADC_TYPES_H_031: ADC_ESDD_UD_140 */
/* Type for configuring on which edge of the hardware trigger signal the
 * driver should reach, i.e. start the conversion
 */
typedef enum ETag_Adc_HwTriggerSignalType
{
  ADC_HW_TRIG_RISING_EDGE,
  ADC_HW_TRIG_FALLING_EDGE,
  ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;

/* ADC_TYPES_H_014: SWS_Adc_00525 */
/* ADC_TYPES_H_034: ADC_ESDD_UD_143 */
/* Type for configuring the result data alignment */
typedef enum ETag_Adc_ResultAlignmentType
{
  ADC_ALIGN_LEFT,
  ADC_ALIGN_RIGHT
} Adc_ResultAlignmentType;

/* ADC_TYPES_H_036: ADC_ESDD_UD_145 */
/* Type of processing mode of the HW unit */
typedef enum ETag_Adc_FunctionalityModeType
{
  ADC_INTERRUPT_MODE,
  ADC_POLLING_MODE,
  ADC_POLLING_INTERRUPT_MODE
} Adc_FunctionalityModeType;

/* ADC_TYPES_H_041: ADC_ESDD_UD_146 */
/* ADC_TYPES_H_038: AR_PN0076_FSR_0001 */
/* ADC_TYPES_H_039: AR_PN0076_FSR_0005 */
/* ADC_TYPES_H_040: AR_PN0076_FSR_0006 */
/* Type for configuring the Self Diag for F1x and R1x. */
typedef enum ETag_Adc_SelfDiagMode
{
  ADC_SELF_DIAG_OFF,
  ADC_SELF_DIAG_CONV_CKT,
  ADC_SELF_DIAG_CH_MUX,
  ADC_SELF_DIAG_OPEN_PIN
} Adc_SelfDiagMode;

/* Priority level of the channel. Lowest priority is 0 */
/* ADC_TYPES_H_015: SWS_Adc_00516 */
/* ADC_TYPES_H_027: ADC_ESDD_UD_136 */
typedef uint8 Adc_GroupPriorityType;

/* Type of the hardware unit */
typedef enum ETag_Adc_HardwareIndexType
{
  ADC_HW_ADCA0,
  ADC_HW_ADCA1
} Adc_HardwareIndexType;

/* Data Structure required for initializing the ADC unit */
/* ADC_TYPES_H_016: SWS_Adc_00505, AR_PN0076_FR_0029 */
/* ADC_TYPES_H_019: ADC_ESDD_UD_052 */
typedef struct STag_Adc_ConfigType
{
  /* Database start value - ADC_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  /* Pointer to ADC hardware unit configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pHWUnitConfig;
  /* Pointer to ADC SG unit configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pSgUnitConfig;
  /* Pointer to ADC group configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pGroupConfig;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Pointer to ADC PWM diagnostic group configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pPwmDiagGroupConfig;
  /* Pointer to ADC PWM diagnostic group Trigger Source Ids */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pPwmDiagIds;
  #endif
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Pointer to ADC HW trigger values */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pGroupHWTrigg;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Pointer to Limit check range values */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pLimitCheckRange;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Pointer to DMA  data */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaUnitConfig;
  /* Pointer to DMA HW unit array mapping */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaHWUnitMapping;
  /* Pointer to DMA SGm unit array mapping */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaSGUnitMapping;
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  /* Pointer to Adc_GaaChannelToGroup[] array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pChannelToGroup;
  /* Pointer to Hardware Index Mapping array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pHwUnitIndex;
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                        (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  /* Pointer to Adc_GstMuxDelayVal structure */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pMuxDelayVal;
  #endif
  /* Pointer to SG unit Index Mapping array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pSgUnitIndex;
  /* Pointer to channel group ram data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pGroupRamData;
  /* Pointer to SG Unit ram data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pSgUnitRamData;
  /* Pointer to Runtime data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pRunTimeData;
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Pointer to Adc_GaaChannelToDisableEnable[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pChannelToDisableEnable;
  #endif
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Pointer to PWM Diagnostic group Runtime data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagGroupRamData;
  /* Pointer to RAM of CTDR array */
  P2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA) pPwmChannelCTDRVal;
  #endif
  #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
  /* Pointer to the RAM allocation for result data*/
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pResultGroupRamData;
  #endif
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Pointer to Adc_GaaFlexibleChannelToGroup[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pFlexibleChannelToGroup;
  #endif
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Pointer to Adc_GaaLimitCheckRange[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pFlexibleLimitCheckRange;
  #endif
  /*
   * Max number of SW triggered groups configured in corresponding
   * configuration
   */
  uint8 ucMaxSwTriggGroups;
  uint8 ucNoOfGroups;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * Generate the group Id of the least PWM diagnostic group configured in this
   * configuration set. In case if there are no PWM diagnostic group then the
   * value of this parameter should be equal to ADC_MAX_GROUPS
   */
  uint8 ucNoOfPwmDiagGroups;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /*
   * Max number of DMA channel Ids configured in corresponding
   * configuration
   */
  uint8 ucMaxDmaChannels;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * No of DMA channel Ids configured for PWM Diagnostic.
   */
  uint8 ucNoOfPwmDiagDmaChannels;
  #endif
  #endif
  #if ((ADC_ENABLE_DISABLE_CHANNEL == STD_ON) || \
                 ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && \
                                            (ADC_ENABLE_LIMIT_CHECK == STD_ON)))
  /* No of channels configured in this configuration */
  uint8 ucNoOfChannels;
  #endif
  /* No of channels configured with limit check enabled in a configset */
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  uint8 ucNoThresholds;
  #endif
  /*Offset for limit check enabled channels in a configset w.r.t first */
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  uint8 ucThresholdOffset;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                         (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  /* First mux channel in a configest */
  uint8 ucMuxStartChannel;
  /* No of Mux enabled channels in a configset */
  uint8 ucMuxChnlCnt;
  #endif
} Adc_ConfigType;

/* ADC_TYPES_H_046: ADC_ESDD_UD_147 */
/* Type of sampling clock */
typedef enum ETag_Adc_SamplingClockType
{
  ADC_SCLK_18,
  ADC_SCLK_24
} Adc_SamplingClockType;

#if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
/* ADC_TYPES_H_037: ADC_ESDD_UD_147 */
/* Type of Hardware Consistency check */
typedef enum ETag_Adc_HWConsistencyCheckType
{
  ADC_HW_CONSISTENCY_STATIC,
  ADC_HW_CONSISTENCY_DYNAMIC
} Adc_HWConsistencyCheckType;
#endif

#endif /* ADC_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
