/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of ADC Driver Component                       */
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
/* Implements AR_PN0076_FR_0027, AR_PN0076_NR_0010 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  12-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAAGA-72,
 *                              New APIs, Adc_CusSetSamplingClock,
 *                              Adc_CusGetPWSAnPVCRx_y_16bit,
 *                              Adc_CusGetPWSAnPVCRx_y_32bit and
 *                              Adc_GetVersionInfo are added.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              DET checks added in APIs Adc_SetThreshold and
 *                              Adc_SelectChannelThreshold
 *                           3. Misra justifications added.
 *                           4. Include section updated.
 *                           5. As a part of JIRA ticket ARDAAGA-72,
 *                              API Adc_GetVersionInfo is added.
 * V2.0.0:  8-Aug-2016     : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_CheckHWConsistency() API is added,
 *                              Adc_GaaRamMirrorDmaReg fields are updated
 *                              and Adc_CheckHWConsistency() Service ID is
 *                              updated from NA to 0x20.
 *                           2. As a part of JIRA ticket ARDAABC-745,
 *                              Fixed Adc_GpHwUnitConfig max index from
 *                              ADCSGREG_INSTANCES to ADC_MAX_HW_UNITS
 *                              Removed redundant code.
 *                           3. As a part of JIRA ticket ARDAABC-361,
 *                              Added call to Adc_StateTransition() for the
 *                              ADC_POLLING_MODE mode.
 *                           4. As part of JIRA ticket ARDAABC-810,
 *                              add traces in code for WV, HWCC and Endless Loop
 *                              FUSA requirements.
 * V2.0.1:  06-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-361,
 *                              Only Adc_StateTransition() requires critical
 *                              section protection.
 * V2.1.0:  28-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.1.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE
 * V2.1.2:  03-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-361,
 *                              rolled back the solution from V2.0.0
 * V2.1.3:  18-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                           In Adc_CheckHWConsistency() moved device specific
 *                           part to Adc_Private.c in Adc_HwCheckHWConsistency()
 * V2.1.4:  19-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Det check added in Adc_CheckHWConsistency().
 * V2.2.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.2.1:  27-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Input value check is added in
 *                              Adc_CheckHWConsistency(), input variable
 *                              renamed.
 * V2.2.2:  05-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              The condition check updated to keep constant
 *                              part on the left hand side of the check
 * V2.2.3:  16-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                           updated Adc_CheckHWConsistency Service ID to 0x1A
 * V2.2.4:  27-Jan-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-912,
 *                              Updated Global variables in Adc_Init()
 *                              function header.
 * V2.2.5:  15-Mar-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Added DET error ADC_E_PARAM_VALUE for
 *                              Adc_CheckHWConsistency().
 * V2.2.6:  28-June-2017    : The following changes are made:
 *                            1. MISRA message tags are corrected
 * V2.3.0:  07-Jul-2017     : Following changes are made:
 *                            1. As part of ARDAABD-1725 ,
 *                             a. Added support for mux hardware stabilisation
 *                                time is implemented.
 *                             b. Added support for Enhanced limit check
 *                                functionality.
 *                             c. Software minor version updated.
 *                            2. As part of ARDAABD-2323 , major version check
 *                               is added
 * V2.3.1:  15-Sep-2017     : Following changes are made:
 *                            1. As part of ARDAABD-2387,
 *                             a. Naming of Local variables is corrected
 *                                throughout as per requirement MCAL052.
 *                            2. As part of ARDAABD-2568,
 *                             a. space is added between 'if' and parenthesis,
 *                                spelling mistakes are corrected and comments
 *                                are updated properly.
 * V2.3.2:  27-Jun-2018     : Following changes are made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Heading for MISRA rule violations is
 *                                corrected.
 *                              b.Copyright updated.
 *                            2.As part of ARDAABD-2996,
 *                              a. DET check for GroupStatus is made serial
 *                                 in Adc_StopGroupConversion API.
 *                            3.As part of ARDAABD-3813,
 *                              the loop for filling
 *                              Adc_GpFlexibleLimitCheckRange is updated for
 *                              multiconfigset support.
 *                            4.As part of ARDAABD-1605, Adc_SetThreshold API
 *                              updated.
 *                            5.As part of ARDAABD-2763,
 *                              Adc_DeInit function is updated to add the
 *                              Adc_GblDriverStatus update.
 *                            6.As part of ARDAABD-3638, the function banners
 *                              are updated with the list registers and
 *                              functions invoked.
 *                            7.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids
 *                              are added.
 * V2.3.3:  13-Aug-2018     : Following change is made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                              a.Heading for MISRA rule violations is
 *                                corrected.
 *                              b.Copyright updated.
 *                            2.As part of ARDAABD-2996,
 *                              a. DET check for GroupStatus is made serial
 *                                 in Adc_StopGroupConversion API.
 *                            3.As part of ARDAABD-3707,
 *                              a.Add RH850_DUMMY_READ_SYNCP(16, ICP0)
 *                                 to fix the fault synchronization at the
 *                                  timing when control
 *                                shifts from MCAL to application.
 *                            4.As part of ARDAABD-3949,
 *                              a.Added invoking ADC_ENTER_CRITICAL_SECTION and
 *                                ADC_EXIT_CRITICAL_SECTION while the execution
 *                                of Adc_CheckHWConsistency.
 * V2.3.4: 05-Oct-2018     : Following changes are done : 
 *                            1. As part of ARDAABD-3707, ICP0 usage error
 *                               modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to 
 *                               RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 * V2.3.5: 18-Oct-2018     : Following change is made:
 *                            1.As part of ARDAABD-3707,
 *                              Remove the RH850_DUMMY_READ_SYNCP Marco.
 * V2.3.6: 07-Nov-2019     : Following change is made:
 *                            1.As part of ARDAABD-4074,
 *                             a.Added check for argument 'LucADCAnULLMTBRx';
 *                             b.Added check for member ucMaxLimitcheck of
 *                               Adc_GpGroupConfig
 *                             c.Added judgment that to prevent array access
 *                               from crossing bounds
 *                            2.As part of ARDAABD-4069,
 *                               funtion:Adc_GetStreamLastPointer
 *                               Modified "the pointer PtrToSamplePtr currently
 *                               points to the last result of last channel " to
 *                               "the pointer PtrToSamplePtr shall point to the
 *                               last result of first channel".
 *                            3.As part of ARDAABD-4639,
 *                              a.Initialized automatic variables for QAC check.
 *                              b.Corrected format issue.
 *                            4.As part of ARDAABD-2787,
 *                              a.Added ADCAnSGSTR register
 *                                in Registers Used of Adc_Init API.
 *                              b.Removed Adc_GblDriverStatus variable
 *                                assignment in Adc_DeInit().
 *                              c.Removed the space before the blank line.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0065 */
/* Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0007 */
/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0020, EAAR_PN0034_NR_0069 */
/* Implements: ADC267, SWS_Adc_00267, EAAR_PN0034_FR_0021 */
/* Included for macro definitions and type definitions */
#include "Adc.h"
/* Included for the declaration of internal function prototypes */
#include "Adc_Private.h"
/* Included for macro definitions and structure declarations */
#include "Adc_PBTypes.h"
#include "Adc_Ram.h"
/* Implements ADC_ESDD_UD_003 */
/* Implements EAAR_PN0034_FR_0064 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
/* Implements ADC_ESDD_UD_034 */
#if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Adc.h"
#endif
/* Included for Write Verify and Hardware Consistency Check mechanisms */
#include "Adc_RegWrite.h"
/* Included for the macro declaration of Synchronous processing with dummy *
 *  read and SYNCP.                                                        */
#include "Iocommon_Defines.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ADC_C_AR_RELEASE_MAJOR_VERSION     ADC_AR_RELEASE_MAJOR_VERSION_VALUE
#define ADC_C_AR_RELEASE_MINOR_VERSION     ADC_AR_RELEASE_MINOR_VERSION_VALUE
#define ADC_C_AR_RELEASE_REVISION_VERSION  ADC_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ADC_C_SW_MAJOR_VERSION    1
#define ADC_C_SW_MINOR_VERSION    1

/* Implements EAAR_PN0034_FR_0055 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_AR_RELEASE_MAJOR_VERSION != ADC_C_AR_RELEASE_MAJOR_VERSION)
  #error "Adc.c : Mismatch in Release Major Version"
#endif

#if (ADC_AR_RELEASE_MINOR_VERSION != ADC_C_AR_RELEASE_MINOR_VERSION)
  #error "Adc.c : Mismatch in Release Minor Version"
#endif

#if (ADC_AR_RELEASE_REVISION_VERSION != ADC_C_AR_RELEASE_REVISION_VERSION)
  #error "Adc.c : Mismatch in Release Revision Version"
#endif

#if (ADC_SW_MAJOR_VERSION != ADC_C_SW_MAJOR_VERSION)
  #error "Adc.c : Mismatch in Software Major Version"
#endif

#if (ADC_SW_MINOR_VERSION != ADC_C_SW_MINOR_VERSION)
  #error "Adc.c : Mismatch in Software Minor Version"
#endif

/* Implements EAAR_PN0034_NR_0026, AR_PN0076_NR_0005 */
/*******************************************************************************
**                         MISRA C Rule Violations                            **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Pointer to the configuration array is used and verified    */
/*                 when accessing the boolean parameter value.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0492) Array subscripting applied to a function          */
/*                 parameter declared as a pointer                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Function parameter as a pointer is passed by user          */
/*                 when accessing converted result.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0492)-2 and                           */
/*                 END Msg(4:0492)-2 tags in the code.                        */
/******************************************************************************/
/* 3.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2984)This operation is redundant. The value of the      */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configured more number of SG units then this error */
/*                 message shall not come. when comparing the SG units and HW */
/*                 units in loop then the loop execution depends on how many  */
/*                 SG units or HW units user configured.                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-3 and                           */
/*                 END Msg(4:2984)-3 tags in the code.                        */
/******************************************************************************/
/* 4.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982)This assignment appears to be redundant because the*/
/*                 value of the object is not used before it is modified      */
/*                 again.                                                     */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable is return type if any error occurs it will   */
/*                 return the default assigned value.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-4 and                           */
/*                 END Msg(4:2982)-4 tags in the code.                        */
/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) Bitwise operations on signed data will give       */
/*                 implementation defined results.                            */
/* Rule          : MISRA-C:2004 Rule 12.7                                     */
/* Justification : Though the bitwise operation is performed on unsigned,     */
/*                 data, this warning is generated by the QAC tool V6.2.1 as  */
/*                 an indirect result of integral promotion in complex        */
/*                 bitwise operations.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-6 and                           */
/*                 END Msg(4:4397)-6 tags in the code.                        */
/******************************************************************************/
/* 7.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0317)Cast from a pointer to void to a pointer to object */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Void type pointer is taken in order not to publish the type*/
/*                 to the upper layer.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-7 and                           */
/*                 END Msg(4:0317)-7 tags in the code.                        */
/******************************************************************************/
/* 9. MISRA C RULE VIOLATION::                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-9 and                           */
/*                 END Msg(4:0303)-9 tags in the code.                        */
/******************************************************************************/
/* 10. MISRA C RULE VIOLATION::                                               */
/* Message       : (4:2983) This assignment is redundant. The value of this   */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value changes according to the number of limitcheck    */
/*                 chanal configured,value will be used in next iterations    */
/*                 when more than one limitcheck chanal are configured        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-10 and                          */
/*                 END Msg(4:2983)-10 tags in the code.                       */
/******************************************************************************/
/* 11. MISRA C RULE VIOLATION::                                               */
/* Message       : (4:2991) The value of this 'if' controlling expression is  */
/*                 always 'true'.                                             */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is always true   */
/*                 since variable updating in pre-compile ON condition.       */
/*                 However, when ADC_FLEX_LIMITCHECK_RANGE is not 0 is        */
/*                 configured, this warning ceases to exist.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-11 and                          */
/*                 END Msg(4:2991)-11 tags in the code.                       */
/******************************************************************************/
/* 12. MISRA C RULE VIOLATION::                                               */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is always true   */
/*                 since variable updating in pre-compile ON condition.       */
/*                 However, when ADC_FLEX_LIMITCHECK_RANGE is not 0 is        */
/*                 configured, this warning ceases to exist.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-12 and                          */
/*                 END Msg(4:2995)-12 tags in the code.                       */
/******************************************************************************/
/* 13. MISRA C RULE VIOLATION::                                               */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : If the number configuration is not zero for                */
/*                 ADC_FLEX_LIMITCHECK_RANGE, the code can be accessed.       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-13 and                          */
/*                 END Msg(4:2880)-13 tags in the code.                       */
/******************************************************************************/
/* 14. MISRA C RULE VIOLATION::                                               */
/* Message       : (5:3206) The parameter 'TriggerSource' is not used in this */
/*                 function.                                                  */
/* Rule          : MISRA-C:2012 Rule 2.7                                      */
/* Justification : The paramenter is configuration dependant                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(5:3206)-14 and                          */
/*                 END Msg(5:3206)-14 tags in the code.                       */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Adc_Init
**
** Service ID           : 0x00
**
** Description          : This API performs the initialization of the ADC Driver
**                        component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : ConfigPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GpGroupConfig,
**                        Adc_GpHWGroupTrigg, Adc_GpChannelToGroup,
**                        Adc_GpLimitCheckRange, Adc_GpGroupRamData,
**                        Adc_GpSgUnitRamData, Adc_GpRunTimeData,
**                        Adc_GucMaxSwTriggGroups, Adc_GpDmaHWUnitMapping,
**                        Adc_GpDmaSGUnitMapping, Adc_GucMaxDmaChannels,
**                        Adc_GpDmaUnitConfig, Adc_GblDriverStatus,
**                        Adc_GpSGGroupTrigg, Adc_GpChannelToDisableEnable
**                        Adc_GpResultGroupRamData, Adc_GpSgUnitConfig,
**                        Adc_GpHwUnitIndex, Adc_GpPwmDiagGroupConfig,
**                        Adc_GpPwmDiagIds, Adc_GpPwmGroupData,
**                        Adc_GpPwmChannelCTDRVal, Adc_GpSgUnitIndex,
**                        Adc_GucNoOfGroups, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfPwmDiagDmaChannels,
**                        Adc_GpFlexibleChannelToGroup,
**                        Adc_GpFlexibleLimitCheckRange
**
** Functions invoked    : Det_ReportError, Adc_HwInit
**
** Registers Used       : DCENm, DCSTCm, DTFRRQm, DTFRRQCm, DTFRm, ICQFULL,
**                        DTCTm, ADCAnPWDDIR, DSAm, DDAm, DRDAm, DRSAm, DTCm,
**                        DRTCm, ADCAnSFTCR, ADCAnADHALTR,DCSTm, ADCAnADCR,
**                        ADCAnSMPCR, ADCAnSGMCYCRx, ADCAnPWDSGCR, PWSAnCTL,
**                        ICADCAnIm, ICDMAm, ICADCAnERR, ADCAnECR,
**                        ADCAnMPXSTBTSELR[0-4], ADCAnTHCR, ADCAnTHACR,
**                        PWGAnCTDR, ADCAnTHBCR, ADCAnTHER, PWSAnPVCRx_y,
**                        ADCAnTHGSR, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnPDCTL1,
**                        ADCAnPDCTL2, ADCAnULLMTBRx, ADCAnVCRj, ADCAnSGCRx,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnSGTSELx,
**                        ADCAnMPXSTBTR[0-7], ADCAnSGSTR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC365, ADC342 */
/* Implements ADC054, SWS_Adc_00342 */
/* Implements SWS_Adc_00365, EAAR_PN0034_FR_0063 */
/* Implements SWS_Adc_00054, AR_PN0076_NR_0006 */
/* Implements SWS_Adc_00056 */
/* Implements ADC_ESDD_UD_061 */
/* Implements ADC_ESDD_UD_161 */
/* Implements ADC_ESDD_UD_033 */
/* Implements ADC_ESDD_UD_114 */
/* Implements EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_Init (P2CONST(Adc_ConfigType, AUTOMATIC,
                             ADC_APPL_CONST) ConfigPtr)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  #if ((ADC_ENABLE_DISABLE_CHANNEL == STD_ON) || \
               ((ADC_FLEXIBLE_THRESHOLD == STD_ON) &&  \
                                            (ADC_ENABLE_LIMIT_CHECK == STD_ON)))
  uint8 LucNoChannelInGroup;
  uint8 LucLoopCount;
  #endif
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && \
                                            (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  uint8 LucNoThresholds;
  uint8 LucThresholdOffset;
  #endif
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  #if (ADC_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the ADC Driver is already Initialized */
  if (ADC_INITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00107, ADC107 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID,
                  ADC_INSTANCE_ID, ADC_INIT_SID, ADC_E_ALREADY_INITIALIZED);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (ADC_ALREADY_INIT_DET_CHECK == STD_ON) */
  /* Check if the Configuration pointer is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00343, ADC343 */
    /* Implements SWS_Adc_00344, ADC344 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                            ADC_INIT_SID, ADC_E_PARAM_CONFIG);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Initialize the module only if Database is present */
    /* MISRA Violation: START Msg(4:4397)-6 */
    if ((uint32)(ADC_DBTOC_VALUE) == ConfigPtr->ulStartOfDbToc)
    /* END Msg(4:4397)-6 */
    {
      /* Implements ADC056 */
      /* MISRA Violation: START Msg(4:0317)-7*/
      /* Initialize all the global pointers */
      Adc_GpHwUnitConfig = ConfigPtr->pHWUnitConfig;
      Adc_GpSgUnitConfig = ConfigPtr->pSgUnitConfig;
      Adc_GpGroupConfig = ConfigPtr->pGroupConfig;
      #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
      Adc_GpPwmDiagGroupConfig = ConfigPtr->pPwmDiagGroupConfig;
      Adc_GpPwmDiagIds = ConfigPtr->pPwmDiagIds;
      Adc_GpPwmGroupData = ConfigPtr->pPwmDiagGroupRamData;
      Adc_GpPwmChannelCTDRVal = ConfigPtr->pPwmChannelCTDRVal;
      #endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
      #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
      Adc_GpResultGroupRamData = ConfigPtr->pResultGroupRamData;
      #endif
      #if (ADC_HW_TRIGGER_API == STD_ON)
      Adc_GpHWGroupTrigg = ConfigPtr->pGroupHWTrigg;
      #endif
      Adc_GpChannelToGroup = ConfigPtr->pChannelToGroup;
      Adc_GpHwUnitIndex = ConfigPtr->pHwUnitIndex;
      Adc_GpSgUnitIndex = ConfigPtr->pSgUnitIndex;
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      Adc_GpLimitCheckRange = ConfigPtr->pLimitCheckRange;
      #endif
      Adc_GpGroupRamData = ConfigPtr->pGroupRamData;
      Adc_GpSgUnitRamData = ConfigPtr->pSgUnitRamData;
      Adc_GpRunTimeData = ConfigPtr->pRunTimeData;
      Adc_GucMaxSwTriggGroups = ConfigPtr->ucMaxSwTriggGroups;
      Adc_GucNoOfGroups = ConfigPtr->ucNoOfGroups;
      #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
      Adc_GucNoOfPwmDiagGroups = ConfigPtr->ucNoOfPwmDiagGroups;
      #endif
      #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                          (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
      Adc_GpMuxDelayVal = ConfigPtr->pMuxDelayVal;
      Adc_GucMuxChnlCnt  = ConfigPtr->ucMuxChnlCnt;
      Adc_GucMuxStartChannel  = ConfigPtr->ucMuxStartChannel;
      #endif
      #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
      Adc_GpChannelToDisableEnable = ConfigPtr->pChannelToDisableEnable;
      /* END Msg(4:0317)-7 */
      LucNoChannelInGroup = ConfigPtr->ucNoOfChannels;
      /* Make all the channel enable for conversion */
      for (LucLoopCount = ADC_ZERO; LucLoopCount < LucNoChannelInGroup;
                                                    LucLoopCount++)
      {
        /* set all the channels to enable for conversion */
        /* MISRA Violation: START Msg(4:0491)-1 */
        Adc_GpChannelToDisableEnable[LucLoopCount] = ADC_TRUE;
        /* END Msg(4:0491)-1 */
      }
      #endif /* #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON) */

      #if (ADC_DMA_MODE_ENABLE == STD_ON)
      /* MISRA Violation: START Msg(4:0317)-7*/
      /* Initialize the global pointer for DMA channel and HW unit mapping */
      Adc_GpDmaHWUnitMapping = ConfigPtr->pDmaHWUnitMapping;
      /* Pointer to DMA channel configuration */
      Adc_GpDmaUnitConfig = ConfigPtr->pDmaUnitConfig;
      /* Initialize the global pointer for DMA channel and SG unit mapping */
      Adc_GpDmaSGUnitMapping = ConfigPtr->pDmaSGUnitMapping;
      /* END Msg(4:0317)-7 */
      Adc_GucMaxDmaChannels = ConfigPtr->ucMaxDmaChannels;
      #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
      Adc_GucNoOfPwmDiagDmaChannels = ConfigPtr->ucNoOfPwmDiagDmaChannels;
      #endif
      #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
      #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) &&  \
                                             (ADC_ENABLE_LIMIT_CHECK == STD_ON))
      /* MISRA Violation: START Msg(4:0317)-7*/
      Adc_GpFlexibleChannelToGroup = ConfigPtr->pFlexibleChannelToGroup;
      /* END Msg(4:0317)-7 */
      /* get the no of channels configured in the config set */
      LucNoChannelInGroup = ConfigPtr->ucNoOfChannels;
      for (LucLoopCount = ADC_ZERO; LucLoopCount < LucNoChannelInGroup;
                                                                 LucLoopCount++)
      {
        /* storing the image of all the channels configured */
        /* MISRA Violation: START Msg(4:0491)-1 */
        Adc_GpFlexibleChannelToGroup[LucLoopCount] =
                                             Adc_GpChannelToGroup[LucLoopCount];
        /* END Msg(4:0491)-1 */
      }
      /* set the no of thresholds configured  */
      LucNoThresholds = ConfigPtr->ucNoThresholds;
      LucThresholdOffset = ConfigPtr->ucThresholdOffset;
      /* MISRA Violation: START Msg(4:0317)-7 */
      Adc_GpFlexibleLimitCheckRange = ConfigPtr->pFlexibleLimitCheckRange;
      /* END Msg(4:0317)-7 */
      for (LucLoopCount = LucThresholdOffset; LucLoopCount < (LucNoThresholds+
                                     LucThresholdOffset);LucLoopCount++)
      {
        /* storing the image of all the limit check ranges configured */
        /* MISRA Violation: START Msg(4:0491)-1 */
       Adc_GpFlexibleLimitCheckRange[LucLoopCount+LucThresholdOffset] =
                      Adc_GpLimitCheckRange[LucLoopCount+LucThresholdOffset];
        /* END Msg(4:0491)-1 */
      }
      #endif
      /* Invoke internal initialization function for ADC HW initialization */
      Adc_HwInit();
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Implements ADC269 */
      /* Set ADC driver as Initialized */
      Adc_GblDriverStatus = ADC_INITIALIZED;
      #endif
    }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Implements ADC269 */
    /* Implements EAAR_PN0034_FR_0016 */
    else
    {
      /* Implements ADC067*/
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_INIT_SID, ADC_E_INVALID_DATABASE);
    }
    #endif
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_DeInit
**
** Service ID           : 0x01
**
** Description          : This API performs the De-Initialization of the
**                        ADC Driver component by making all the registers to
**                        the power on reset state.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_HwDeInit
**
** Registers Used       : ADCAnSGSTR, ADCAnSFTCR, ADCAnADHALTR, ADCAnSGMCYCRx,
**                        ADCAnPWDSGCR, ADCAnVCRj, DCENm, DCSTCm, DTCTm,
**                        PWSAnCTL, ICADCAnIm, ICADCAnERR, ADCAnECR,
**                        ADCAnMPXSTBTR[0-7], ADCAnMPXSTBTSELR[0-4], DCSTm
*******************************************************************************/
/* Implements SWS_Adc_00228, ADC228 */
#if (ADC_DEINIT_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_063 */
/* Implements ADC_ESDD_UD_005 */
/* Implements SWS_Adc_00366, ADC366 */
/* Implements SWS_Adc_00110, ADC110, AR_PN0076_NR_0006 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DeInit(void)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Implements SWS_Adc_00154, ADC154 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_DEINIT_SID,
                                                                 ADC_E_UNINIT);
  }
  else
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke internal deinitialization function to deinitialize the ADC HW
       unit */
    Adc_HwDeInit();
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_DEINIT_API == STD_ON */

/*******************************************************************************
** Function Name        : Adc_StartGroupConversion
**
** Service ID           : 0x02
**
** Description          : This API service shall start the conversion of
**                        all channels of the requested ADC Channel group.
**                        Depending on the group configuration single-shot or
**                        continuous conversion is started.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GucMaxSwTriggGroups,
**                        Adc_GpGroupRamData, Adc_GucNoOfGroups,
**                        Adc_GucNoOfPwmDiagGroups
**
** Functions invoked    : Det_ReportError, Adc_HwStartGroupConversion
**
** Registers Used       : ADCAnSGCRx, ADCAnSGTSELx, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnADCR, ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR,
**                        ADCAnTHACR, ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER,
**                        ADCAnTHCR, ICADCAnIm, ADCAnSGSTPCRx, ADCAnSGVCEPx,
**                        ADCAnSGSTR, ADCAnADHALTR, ADCAnSGSTCRx, ADCAnECR,
**                        ADCAnULLMTBRx, DCENm, DCSTCm, DRSAm, DDAm, DTCm,
**                        DRDAm, DRTCm, DSAm, DTCTm, ICDMAm, ADCAnSGVCSPx,
**                        ADCAnVCRj
*******************************************************************************/
/* Implements SWS_Adc_00259, ADC259, ADC356 */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_064 */
/* Implements ADC_ESDD_UD_007 */
/* Implements ADC_ESDD_UD_011 */
/* Implements SWS_Adc_00367, ADC367 */
/* Implements SWS_Adc_00061, ADC061 */
/* Implements SWS_Adc_00431, ADC431, AR_PN0076_NR_0006 */
/* Implements SWS_Adc_00156, ADC156 EAAR_PN0034_FR_0049 */
/* Implements AR_PN0076_FR_0202, AR_PN0076_NR_0220 */
FUNC(void, ADC_PUBLIC_CODE) Adc_StartGroupConversion(Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Implements SWS_Adc_00424 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Implements AR_PN0076_FR_0225 */
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00125, ADC125 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_START_GROUP_CONVERSION_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* Check if the requested group is HW triggered */
    if (Adc_GucMaxSwTriggGroups <= Group)
    {
      /* Implements ADC065 */
      /* Implements ADC067 */
      /* Implements SWS_Adc_00133, ADC133 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_START_GROUP_CONVERSION_SID, ADC_E_WRONG_TRIGG_SRC);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF)
    /* Implements AR_PN0076_FR_0216 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_FALSE == Adc_GpGroupRamData[Group].ucBufferStatus)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC065 */
      /* Implements ADC067, AR_PN0076_FR_0223 */
      /* Implements SWS_Adc_00424, ADC424, SWS_Adc_00294, ADC294*/
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_START_GROUP_CONVERSION_SID, ADC_E_BUFFER_UNINIT);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    #endif
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                  ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                            (ADC_ENABLE_QUEUING == STD_ON)))
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_TRUE == Adc_GpGroupRamData[Group].ucGrpPresent)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC065 */
      /* Implements ADC067, ADC351 */
      /* Implements SWS_Adc_00346, ADC346 */
      /* Implements SWS_Adc_00426, ADC426 */
      /* Implements SWS_Adc_00348, ADC348 */
      /* Implements SWS_Adc_00427, ADC427 */
      /* Implements SWS_Adc_00351, ADC351 */
      /* Implements SWS_Adc_00428, ADC428 */

      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    #endif
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    Adc_HwStartGroupConversion(Group);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_StopGroupConversion
**
** Service ID           : 0x03
**
** Description          : This API service shall stop conversion of the
**                        requested ADC Channel group.
**                        Depending on the group configuration single-shot or
**                        continuous conversion is stopped.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GucNoOfGroups,
**                        Adc_GucNoOfPwmDiagGroups
**
** Functions invoked    : Det_ReportError, Adc_HwStopGroupConversion
**
** Registers Used       : ADCAnSGCRx, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnADCR,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER, ADCAnTHCR
**                        ADCAnECR, ADCAnULLMTBRx, DCENm, DCSTCm, DDAm, DTCm,
**                        DRSAm, DRDAm, DRTCm, DSAm, DTCTm, ICDMAm,
**                        ADCAnSGVCSPx, ADCAnVCRj, ADCAnSGVCEPx, ADCAnTHER,
**                        ADCAnSGSTCRx, ICADCAnIm, ADCAnSGSTR, ADCAnADHALTR,
**                        ADCAnSGSTPCRx, DCSTm
*******************************************************************************/
/* Implements ADC356 */
/* Implements SWS_Adc_00368, ADC368 */
/* Implements SWS_Adc_00260, ADC260 */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

/* Implements AR_PN0076_FR_0221, ADC_ESDD_UD_065 */
/* Implements ADC_ESDD_UD_007 */
/* Implements AR_PN0076_NR_0220, EAAR_PN0034_FR_0049, AR_PN0076_NR_0006 */
FUNC(void, ADC_PUBLIC_CODE) Adc_StopGroupConversion(Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065, SWS_Adc_00486 */
    /* Implements SWS_Adc_00295, ADC295 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_STOP_GROUP_CONVERSION_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00126, ADC126 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_STOP_GROUP_CONVERSION_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    if (Adc_GucMaxSwTriggGroups <= Group)
    {
      /* Implements ADC065 */
      /* Implements ADC067 */
      /* Implements SWS_Adc_00164, ADC164 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_STOP_GROUP_CONVERSION_SID, ADC_E_WRONG_TRIGG_SRC);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /*Implements AR_PN0076_FR_0008 */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
               ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                               (ADC_ENABLE_QUEUING == STD_ON)))
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Implements SWS_Adc_00335 */
      if ((ADC_IDLE == Adc_GpGroupRamData[Group].enGroupStatus) &&
                        (ADC_FALSE == Adc_GpGroupRamData[Group].ucGrpPresent))
      /* END Msg(4:0491)-1 */
      #else
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (ADC_IDLE == Adc_GpGroupRamData[Group].enGroupStatus)
      /* END Msg(4:0491)-1 */
      #endif
      {
        /* Implements ADC065 */
        /* Implements ADC067 */
        /* Implements SWS_Adc_00241, ADC241 */
        /* Report Error to DET */
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                     ADC_STOP_GROUP_CONVERSION_SID, ADC_E_IDLE);
        /* Set the error status flag to E_OK */
        LenDetErrFlag = E_OK;
      }
      else
      {
        /* No action required */
      }
    }

  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements SWS_Adc_00385, ADC385 */
    /* Implements SWS_Adc_00437 */
    /* Implements SWS_Adc_00386 */
    /* Implements SWS_Adc_00438 */
    /* Implements SWS_Adc_00155, ADC155 */
    Adc_HwStopGroupConversion(Group);

    /* Set the group status as idle */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements SWS_Adc_00360, ADC360 */
    Adc_GpGroupRamData[Group].enGroupStatus = ADC_IDLE;
    /* END Msg(4:0491)-1 */
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Store disabled notification into RAM */
    /* MISRA Violation: START Msg(4:0491)-1 */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_FALSE;
    /* END Msg(4:0491)-1 */
    #endif
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_ReadGroup
**
** Service ID           : 0x04
**
** Description          : This API service shall read the group conversion
**                        result of the last completed conversion round of
**                        requested group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and DataBufferPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GpGroupConfig, Adc_GpRunTimeData,
**                        Adc_GpSgUnitConfig, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_StateTransition,
**                        ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION, Adc_PollingReadGroup
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx, ADCAnULER, ADCAnDRj,
**                        ADCAnSGCRx, DCENm, DCSTCm, DDAm, DTCm, DRSAm, DRDAm,
**                        DRTCm, DSAm, DTCTm, ADCAnADCR, ADCAnDGCTL0, ICDMAm,
**                        ADCAnDGCTL1, ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx,
**                        ADCAnVCRj, ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR,
**                        ADCAnSGSTCRx, ICADCAnIm, DCSTm, ADCAnDIRj, ADCAnOWER,
**                        WUF0, WUFC0
*******************************************************************************/
/* Implements ADC383 */
/* Implements SWS_Adc_00503 */
/* Implements SWS_Adc_00359, ADC359 */
#if (ADC_READ_GROUP_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_066 */
/* Implements ADC_ESDD_UD_009 */
/* Implements SWS_Adc_00369, ADC369 */
/* Implements ADC_ESDD_UD_162 */
/* Implements ADC_ESDD_UD_128 */
/* Implements AR_PN0076_NR_0220 */

FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_ReadGroup (Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_CONFIG_DATA) LpChannelBuffer;
  #if (ADC_ENABLE_STREAMING == STD_ON)
  Adc_StreamNumSampleType LucNoOfSamples;
  #endif
  uint8 LucHwSGUnit;
  Std_ReturnType LenReadStatus;
  uint8 LucLoopCount;
  uint8 LucAvailChannelCount;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  /* MISRA Violation: START Msg(4:2982)-4 */
  /* Initialize the return value */
  /* Implements SWS_Adc_00384 */
  LenReadStatus = E_NOT_OK;
  /* END Msg (4:2982)-4 */

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Implements SWS_Adc_00296, ADC296 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                      ADC_READ_GROUP_SID, ADC_E_UNINIT);
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00152, ADC152 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_READ_GROUP_SID, ADC_E_PARAM_GROUP);
  }
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if ((ADC_IDLE == Adc_GpGroupRamData[Group].enGroupStatus) &&
          (ADC_TRUE == Adc_GpGroupRamData[Group].blResultRead))
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00388, ADC388 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_READ_GROUP_SID, ADC_E_IDLE);
  }
  else
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Assuming the API will be called for single access mode */
    LucLoopCount = ADC_ONE;
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Get the pointer to requested group configuration */
    LpGroup = &Adc_GpGroupConfig[Group];
    /* END Msg(4:0491)-1 */
    /* Get the SGm unit to which the channel group is mapped */
    LucHwSGUnit = LpGroup->ucSgUnitIndex;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Implements ADC269 */
    /* Implements ADC384 */
    /* Initialize error status flag to E_NOT_OK */
    LenDetErrFlag = E_NOT_OK;
    /* MISRA Violation: START Msg(4:0491)-1 */
    if ((ADC_BUSY == Adc_GpGroupRamData[Group].enGroupStatus) &&
                   (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucHwSGUnit].
                                                   enFunctionalityModeType))
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC067 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_READ_GROUP_SID, ADC_E_IDLE);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action Required */
    }
    /* Check if any DET was reported */
    if (E_NOT_OK == LenDetErrFlag)
    #endif
    {
      #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
      /* Get the no of channels available for the requested group */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LucAvailChannelCount = (LpGroup->ucChannelCount -
                                  Adc_GpGroupRamData[Group].ucNoofChDisabled);
      /* END Msg(4:0491)-1 */
      #else
      /* Get the no of channels available for the requested group */
      LucAvailChannelCount = LpGroup->ucChannelCount;
      #endif
      /* Implements AR_PN0076_FR_0217 */
      /* Implements ADC113, SWS_Adc_00113 */
      #if (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT)
      /* Check if the Scan Group is mapped for polling mode */
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (ADC_POLLING_MODE == Adc_GpSgUnitConfig[LucHwSGUnit]
                                                      .enFunctionalityModeType)
      /* END Msg(4:0491)-1 */
      {
        /* Implements AR_PN0076_FR_0218 */
        /* Call the internal read group function */
        Adc_PollingReadGroup(Group, LucAvailChannelCount);
      }
      else
      {
        /* No action Required */
      }
      #endif
      /* Get the base address of the Group buffer */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpChannelBuffer = Adc_GpGroupRamData[Group].pChannelBuffer;
      /* END Msg(4:0491)-1 */
      /* Implements SWS_Adc_00330, ADC330 */
      /* Implements SWS_Adc_00329, ADC329 */
      /* Implements SWS_Adc_00331, ADC331 */
      #if (ADC_ENABLE_STREAMING == STD_ON)
      /* Get the number of samples configured for the group */
      LucNoOfSamples = LpGroup->ddNumberofSamples;
      if (ADC_GROUP_ACCESS_STREAMING == (LpGroup->ucGroupSettings &
                                                  ADC_GROUP_ACCESS_MASK))
      {
        /* Get the number of samples completed in the requested group */
        /* MISRA Violation: START Msg(4:0491)-1 */
        LucLoopCount = Adc_GpRunTimeData[LucHwSGUnit].ucSamplesCompleted;
        /* END Msg(4:0491)-1 */
        /*
         * Check if Read group was called for a continuous conversion and
         * samples completed might be reset in ISR.
         */
        if (ADC_ZERO == LucLoopCount)
        {
          /*
           * Set the no of samples completed to previously completed valid
           * number if samples.
           */
          LucLoopCount = LucNoOfSamples;
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
      #endif /* #if (ADC_ENABLE_STREAMING == STD_ON) */
      /* Initialize the pointer to the latest sample of the first channel */
      /* MISRA Violation: START Msg(4:2984)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Implements SWS_Adc_00311 */
      /* Implements SWS_Adc_00122 */
      LpChannelBuffer = &LpChannelBuffer[LucLoopCount - ADC_ONE];
      /* END Msg(4:0491)-1 */
      /* END Msg(4:2984)-3 */
      /* Initialize the loop count to zero */
      LucLoopCount = ADC_ZERO;
      /* Implements AR_PN0076_FR_0054 */
      /* Implements SWS_Adc_00075, ADC075 */
      do
      {
        #if (ADC_ENABLE_STREAMING == STD_ON)
        /* Load the converted values to the application buffer */
        /* MISRA Violation: START Msg(4:0492)-2 */
        /* MISRA Violation: START Msg(4:0491)-1 */
      /* Implements SWS_Adc_00122, ADC122 */
        DataBufferPtr[LucLoopCount] =
                      LpChannelBuffer[LucLoopCount * LucNoOfSamples];
        #else
        /* Load the converted values to the application buffer */
        DataBufferPtr[LucLoopCount] = LpChannelBuffer[LucLoopCount];
        /* END Msg(4:0491)-1 */
        /* END Msg(4:0492)-2 */
        #endif
        /* Increment to the next buffer index */
        LucLoopCount++;
      } while (LucAvailChannelCount > LucLoopCount);

      #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)

      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter the critical section protection */
      ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif
      /* Check if the Scan Group is mapped for interrupt mode */
      /* Implements AR_PN0076_FR_0217 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucHwSGUnit]
                                                       .enFunctionalityModeType)
      /* END Msg(4:0491)-1 */
      {
        /* Change the group status of the group whose values are read */
        Adc_StateTransition(Group);
      }
      else
      {
        /* No action Required */
      }
      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit the critical section protection */
      ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif
      #endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */
      /* Set the flag indicating result data is read */
      /* MISRA Violation: START Msg(4:0491)-1 */
      Adc_GpGroupRamData[Group].blResultRead = ADC_TRUE;
      /* END Msg(4:0491)-1 */
      /* Update the return value */
      LenReadStatus = E_OK;
    }

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Implements ADC269 */
    else
    {
      /* No action required */
    }
    #endif
  }
  return(LenReadStatus);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_READ_GROUP_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_EnableHardwareTrigger
**
** Service ID           : 0x05
**
** Description          : This API service will enable the hardware trigger
**                        for the requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_HwEnableHardwareTrigger
**
** Registers Used       : ADCAnSGSTR, ADCAnSGTSEL, ADCAnECR, ADCAnULLMTBRx,
**                        ADCAnSGCRx, DCENm, DCSTCm, DRSAm, DDAm, DTCm, DRSAm,
**                        DRDAm, DRTCm, DSAm, DTCTm, ADCAnADCR, ADCAnDGCTL0,
**                        ADCAnDGCTL1, ICDMAm, ADCAnPDCTL1, ADCAnPDCTL2,
**                        ADCAnSGVCSPx, ADCAnVCRj, ADCAnSGVCEPx, ADCAnTHCR,
**                        ADCAnTHACR, ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR,
**                        ADCAnTHSMPSTCR, ADCAnSGSTCRx, ICADCAnIm, ADCAnSGTSELx,
**                        ADCAnSGSTPCRx, ADCAnADHALTR, DCSTm
*******************************************************************************/
/* Implements ADC357 */
/* Implements SWS_Adc_00370, ADC370 */
/* Implements SWS_Adc_00265, ADC265 */
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_067 */
/* Implements ADC_ESDD_UD_008 */
/* Implements AR_PN0076_NR_0220, EAAR_PN0034_FR_0049 */
/* Implements SWS_Adc_00114, ADC114 */
/* Implements SWS_Adc_00144, ADC144 */
/* Implements ADC237 */
FUNC(void, ADC_PUBLIC_CODE) Adc_EnableHardwareTrigger (Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00336, ADC336 */
    /* Implements SWS_Adc_00128, ADC128 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* Check if requested group is SW triggered group */
    if (Group < Adc_GucMaxSwTriggGroups)
    {
      /* Implements ADC065 */
      /* Implements ADC067 */
      /* Implements SWS_Adc_00333, ADC333 */
      /* Implements SWS_Adc_00136, ADC136 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                       ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_WRONG_TRIGG_SRC);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    /* Check if the group is already enabled */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_TRUE == Adc_GpGroupRamData[Group].ucHwTriggStatus)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC065 */
      /* Implements ADC067 */
      /* Report Error to DET */
     /* Implements SWS_Adc_00321, ADC321 */
     /* Implements SWS_Adc_00349, ADC349 */
     /* Implements SWS_Adc_00353, ADC353 */
     /* Implements SWS_Adc_00281, ADC281 */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_BUSY);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF)
    /* Implements AR_PN0076_FR_0216 */
    /* Implements SWS_Adc_00432, ADC432 */
    /* Check if result buffer is initialized for requested group */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_FALSE == Adc_GpGroupRamData[Group].ucBufferStatus)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC065 */
      /* Implements ADC067 */

      /* Report Error to DET */
      /* Implements SWS_Adc_00297, ADC297 */
      /* Implements SWS_Adc_00425, ADC425 */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_BUFFER_UNINIT);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    #endif
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    Adc_HwEnableHardwareTrigger(Group);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_DisableHardwareTrigger
**
** Service ID           : 0x06
**
** Description          : This API service will disables the hardware trigger
**                        for the requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_HwDisableHardwareTrigger
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm,
**                        DDAm, DTCm, DRSAm, DRDAm, DRTCm, DSAm, DTCTm,
**                        ADCAnADCR, ADCAnDGCTL0, ADCAnDGCTL1, ICDMAm, DCSTm
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx, ADCAnVCRj,
**                        ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR, ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR, ADCAnSGSTCRx,
**                        ICADCAnIm, ADCAnSGTSELx, ADCAnSGSTPCRx, ADCAnSGSTR
*******************************************************************************/
/* Implements SWS_Adc_00413, ADC413 */
/* Implements SWS_Adc_00371, ADC371 */
/* Implements SWS_Adc_00116, ADC116 */
/* Implements SWS_Adc_00266, ADC266 */
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_068 */
/* Implements ADC_ESDD_UD_008 */
/* Implements AR_PN0076_NR_0220, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00298, ADC298 */
    /* Implements SWS_Adc_00425, ADC425 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                               ADC_DISABLE_HARDWARE_TRIGGER_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00129, ADC129 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_DISABLE_HARDWARE_TRIGGER_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if requested group is SW triggered group */
  else if (Group < Adc_GucMaxSwTriggGroups)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00137, ADC137 */
    /* Implements SWS_Adc_00282, ADC282 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_DISABLE_HARDWARE_TRIGGER_SID, ADC_E_WRONG_TRIGG_SRC);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if HW trigger was not enabled for requested group */
  else
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_FALSE == Adc_GpGroupRamData[Group].ucHwTriggStatus)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC065 */
      /* Implements ADC067 */
      /* Implements SWS_Adc_00304, ADC304 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_DISABLE_HARDWARE_TRIGGER_SID, ADC_E_IDLE);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if HW trigger was enabled for requested group */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (ADC_TRUE == Adc_GpGroupRamData[Group].ucHwTriggStatus)
    /* END Msg(4:0491)-1 */
    {
      Adc_HwDisableHardwareTrigger(Group);
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Set the status of HW triggered group to disabled */
      /* Implements SWS_Adc_00157, ADC157 */
      /* Implements SWS_Adc_00429, ADC429 */
      /* Implements SWS_Adc_00121, ADC121 */
      Adc_GpGroupRamData[Group].ucHwTriggStatus = ADC_FALSE;
      /* END Msg(4:0491)-1 */
    }
    else
    {
      /* No action required */
    }
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_EnableGroupNotification
**
** Service ID           : 0x07
**
** Description          : This API service will enable the ADC Driver
**                        notification of the requested channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GpGroupConfig, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/
/* Implements SWS_Adc_00413, ADC413 */
/* Implements SWS_Adc_00372, ADC372 */
/* Implements SWS_Adc_00130, ADC130 */
/* Implements SWS_Adc_00100, ADC100 */
/* Implements ADC_ESDD_UD_010 */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_069 */
/* Implements EAAR_PN0034_FR_0049 */
/* Implements ADC416, SWS_Adc_00416 */
FUNC(void, ADC_PUBLIC_CODE) Adc_EnableGroupNotification(Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00299, ADC299 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                             ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_UNINIT);
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00130, ADC130 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                        ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_PARAM_GROUP);
  }
  /* Implements SWS_Adc_00084, ADC084 */
  /* Implements ADC080, SWS_Adc_00080 */
  /* Check if no valid notification function is configured */
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (NULL_PTR == Adc_GpGroupConfig[Group].pGroupNotificationPointer)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00165, ADC165 */
    /* Implements SWS_Adc_00166, ADC165 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                   ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_NOTIF_CAPABILITY);
  }
  else
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Store the enabled notification into RAM */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements SWS_Adc_00057, ADC057 */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_TRUE;
    /* END Msg(4:0491)-1 */
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_DisableGroupNotification
**
** Service ID           : 0x08
**
** Description          : This API service will disable the ADC Driver
**                        notification of the requested channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GpGroupConfig, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/
/* Implements SWS_Adc_00413, ADC413, EAAR_PN0034_FR_0049 */
/* Implements SWS_Adc_00373, ADC373 */
/* Implements SWS_Adc_00101, ADC101 */
/* Implements ADC_ESDD_UD_010 */
/* Implements ADC_ESDD_UD_095 */
/* Implements ADC_ESDD_UD_154 */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_070 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DisableGroupNotification(Adc_GroupType Group)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00300, ADC300 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_UNINIT);
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00131, ADC131 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                       ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_PARAM_GROUP);
  }
  /* Check if no valid notification function is configured */
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (NULL_PTR == Adc_GpGroupConfig[Group].pGroupNotificationPointer)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00166, ADC166 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                  ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_NOTIF_CAPABILITY);
  }
  else
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Store the disabled notification into RAM */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements SWS_Adc_00058, ADC058 */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_FALSE;
    /* END Msg(4:0491)-1 */
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_GetGroupStatus
**
** Service ID           : 0x09
**
** Description          : This API service shall return the conversion status of
**                        requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Adc_StatusType
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucNoOfGroups, Adc_GucNoOfPwmDiagGroups,
**
** Functions invoked    : Det_ReportError, ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION
**
** Registers Used       : None
*******************************************************************************/
/* Implements SWS_Adc_00413, ADC413 */
/* Implements SWS_Adc_00374, ADC374 */
/* Implements SWS_Adc_00220, ADC220 */
/* Implements SWS_Adc_00226, ADC226 */
/* Implements SWS_Adc_00436, ADC436, AR_PN0076_NR_0006 */
/* Implements SWS_Adc_00305, ADC305, EAAR_PN0034_FR_0049 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_071 */
FUNC(Adc_StatusType, ADC_PUBLIC_CODE) Adc_GetGroupStatus(Adc_GroupType Group)
{
  /* Local variable to store the group status */
  Adc_StatusType LenGroupStatus;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif

  /* MISRA Violation: START Msg(4:2982)-4 */
  /* Default value that to be returned in case of error */
  /* Implements SWS_Adc_00221, ADC221 */
  LenGroupStatus = ADC_IDLE;
  /* END Msg (4:2982)-4 */

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
     /* Implements SWS_Adc_00301, ADC301 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                      ADC_GET_GROUP_STATUS_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00140, ADC140 */
    /* Implements SWS_Adc_00225, ADC225 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_GET_GROUP_STATUS_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Read the group status */
    /* Implements SWS_Adc_00222, ADC222 */
    LenGroupStatus = Adc_GpGroupRamData[Group].enGroupStatus;
    /* END Msg(4:0491)-1 */
    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
  return(LenGroupStatus);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_GetStreamLastPointer
**
** Service ID           : 0x0B
**
** Description          : This API service shall return the pointer to the last
**                        converted value for the group configured in streaming
**                        access mode.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : PtrToSamplePtr (pointer of Adc_ValueGroupType)
**
** Return parameter     : Adc_StreamNumSampleType
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupConfig,
**                        Adc_GpGroupRamData, Adc_GpRunTimeData,
**                        Adc_GpHwUnitConfig, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_StateTransition,
**                        ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm,
**                        DDAm, DTCm, DRSAm, DRDAm, DRTCm, DSAm, DTCTm,
**                        ADCAnADCR, ADCAnDGCTL0, ADCAnDGCTL1, ICDMAm,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx, ADCAnVCRj,
**                        ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR, ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR, ADCAnSGSTCRx,
**                        ICADCAnIm
*******************************************************************************/
/* Implements ADC382 */
/* Implements SWS_Adc_00375, ADC375 */
#if (ADC_GETSTREAMLASTPOINTER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_072 */
/* Implements ADC_ESDD_UD_022 */
/* Implements EAAR_PN0034_FR_0049 */

FUNC(Adc_StreamNumSampleType, ADC_PUBLIC_CODE) Adc_GetStreamLastPointer
(Adc_GroupType Group, P2VAR(P2VAR(Adc_ValueGroupType,
  /* Implements SWS_Adc_00214, ADC214 */
  /* Implements SWS_Adc_00418, ADC418 */
AUTOMATIC, ADC_CONFIG_DATA), AUTOMATIC, ADC_CONFIG_DATA) PtrToSamplePtr)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpBuffer;
  Adc_StreamNumSampleType LddSampleCount;
  uint8 LucHwSGUnit;

  /* Default value to be returned in case of error */
  LddSampleCount = ADC_ZERO;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00302, ADC302 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_UNINIT);
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
   /* Implements SWS_Adc_00218, ADC218 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_PARAM_GROUP);
  }
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (ADC_IDLE == Adc_GpGroupRamData[Group].enGroupStatus)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC069 */
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00215, ADC215 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                               ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_IDLE);
  }
  else if (NULL_PTR == PtrToSamplePtr)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_PARAM_POINTER);
  }
  else
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements SWS_Adc_00216, ADC216 */
    *PtrToSamplePtr = NULL_PTR;
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements SWS_Adc_00219, ADC219 */
    /* Implements SWS_Adc_00326, ADC326 */
    /* Implements SWS_Adc_00327, ADC327 */
    /* Implements SWS_Adc_00328, ADC328 */
    if ((ADC_COMPLETED == Adc_GpGroupRamData[Group].enGroupStatus) ||
      (ADC_STREAM_COMPLETED == Adc_GpGroupRamData[Group].enGroupStatus))
    /* END Msg(4:0491)-1 */
    {
      /* Get the pointer to requested group's configuration */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpGroup = &Adc_GpGroupConfig[Group];
      /* END Msg(4:0491)-1 */
      /* Get the SGm unit to which the channel group is mapped */
      LucHwSGUnit = LpGroup->ucSgUnitIndex;

      /* Implements SWS_Adc_00387, ADC387 */
      /* Get the number of samples completed for the requested group */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LddSampleCount = Adc_GpRunTimeData[LucHwSGUnit].ucSamplesCompleted;
      /* END Msg(4:0491)-1 */

      /* Read the base pointer of the streaming group */
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpBuffer = Adc_GpGroupRamData[Group].pChannelBuffer;
      /* END Msg(4:0491)-1 */

      /* Judging the value of LddSampleCount to prevent array crossing */
      if(LddSampleCount > ADC_ZERO)
      {
        /* Load the pointer of the last converted value */
        /* MISRA Violation: START Msg(4:0491)-1 */
        *PtrToSamplePtr = &LpBuffer[LddSampleCount - ADC_ONE];
        /* END Msg(4:0491)-1 */
      }
      else
      {
        /* No action required */
      }
      /* Check if the group is configured for DMA access */
      if (ADC_GROUP_DMA_ACCESS == (LpGroup->ucGroupSettings &
                                                  ADC_GROUP_RESULT_ACCESS_MASK))
      {
        /* Update the return value to one */
        LddSampleCount = ADC_ONE;
      }
      else
      {
        /* No action required */
      }
      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter the critical section protection */
      ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif

      /* Change the group status of the group whose values are read */
      Adc_StateTransition(Group);

      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit the critical section protection */
      ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif
      /* Set the flag indicating result data is read */
      /* MISRA Violation: START Msg(4:0491)-1 */
      Adc_GpGroupRamData[Group].blResultRead = ADC_TRUE;
      /* END Msg(4:0491)-1 */
    }
    else
    {
      /* No action required */
    }
  }
  /* Return the number of samples */
  return(LddSampleCount);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_GETSTREAMLASTPOINTER_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_SetupResultBuffer
**
** Service ID           : 0x0C
**
** Description          : Initializes the group specific ADC result buffer
**                        pointer as configured to point to the DataBufferPtr.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and DataBufferPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucNoOfPwmDiagGroups, Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/

#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Implements AR_PN0076_FR_0215, ADC_ESDD_UD_062 */
/* Implements SWS_Adc_00419, ADC419 EAAR_PN0034_FR_0049 */
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SetupResultBuffer
(Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr)
{
  Std_ReturnType LenSetupStatus;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  /* MISRA Violation: START Msg(4:2982)-4 */
  /* Initialize the return value */
  LenSetupStatus = E_NOT_OK;
  /* END Msg (4:2982)-4 */

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  if (NULL_PTR == DataBufferPtr)
  {
    /* Implements ADC457 */
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00457 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_SETUP_RESULT_BUFFER_SID, ADC_E_PARAM_POINTER);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC434 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00434 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_SETUP_RESULT_BUFFER_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    /* Implements SWS_Adc_00423, ADC423 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_SETUP_RESULT_BUFFER_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (ADC_IDLE != Adc_GpGroupRamData[Group].enGroupStatus)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC433 */
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00433 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                       ADC_SETUP_RESULT_BUFFER_SID, ADC_E_BUSY);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements ADC318 */
    /* Implements ADC319 */
    /* Implements SWS_Adc_00420, ADC420 */
    /* Initialize the group result buffer pointer with the address passed */
    /* MISRA Violation: START Msg(4:0491)-1 */
    Adc_GpGroupRamData[Group].pChannelBuffer = DataBufferPtr;
    /* END Msg(4:0491)-1 */
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Set the buffer initialization status */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Implements SWS_Adc_00421, ADC421 */
    /* Implements SWS_Adc_00422, ADC422  */
    Adc_GpGroupRamData[Group].ucBufferStatus = ADC_TRUE;
    /* END Msg(4:0491)-1 */
    #endif
    /* Update the return value */
    LenSetupStatus = E_OK;
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  return(LenSetupStatus);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
** Function Name        : Adc_EnableHwTrigger
**
** Service ID           : 0x0D
**
** Description          : Initializes the PWM diagnostic group's trigger event.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and TriggerSource
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GpPwmGroupData, Adc_GucNoOfGroups,
**
** Functions invoked    : Det_ReportError, Adc_IntEnableHwTrigger
**
** Registers Used       : ADCAnULLMTBRx, PWGAnCTDR, PWGAnRDT, ICQFULL
**                        PWSAnPVCRx_y, PWSAnSTR
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Implements AR_PN0076_FR_0205, ADC_ESDD_UD_111 */
/* Implements AR_PN0076_FR_0207 */
/* Implements ADC_ESDD_UD_031 */
/* Implements ADC_ESDD_UD_041 */
/* Implements ADC_ESDD_UD_110 */
/* Implements AR_PN0076_FR_0228, AR_PN0076_FR_0226 */
/* Implements AR_PN0076_FR_0227, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_EnableHwTrigger
(Adc_GroupType Group, Adc_HwTriggerTimerType TriggerSource)
{
  Adc_GroupType LddDiagGroup;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize the error flag */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_ENABLE_HW_TRIGGER_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /*
   * Check if the Group requested is valid and group is enabled for
   * PWM diagnostic.
   */
  else if ((Group >= Adc_GucNoOfGroups) ||
           (Group < (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups)))
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements SWS_Adc_00423, ADC423 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_ENABLE_HW_TRIGGER_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the index of the requested group Id in the PWM diagnostic array */
    if ( Adc_GucNoOfGroups > Adc_GucNoOfPwmDiagGroups )
    {
        LddDiagGroup = (Group - (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups));
    }
    else
    {
        LddDiagGroup = Group;
    }
    /* Set the index of the group with trigger index */
    /* MISRA Violation: START Msg(4:0491)-1 */
    Adc_GpPwmGroupData[LddDiagGroup].ucTriggSrcIndex = TriggerSource;
    /* END Msg(4:0491)-1 */
    /*
     * Invoke the internal function to set the PVCR value to corresponding
     * PWM Diagnostic channel.
     */
    Adc_IntEnableHwTrigger(LddDiagGroup);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_DisableHwTrigger
**
** Service ID           : 0x0E
**
** Description          : Disables the PWM diagnostic group's trigger event.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and TriggerSource
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GucNoOfPwmDiagGroups and
**                        Adc_GpPwmGroupData, Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_IntDisableHwTrigger
**
** Registers Used       : PWGAnCSDR, PWGAnCRDR, PWGAnCTDR, PWGAnRDT
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements AR_PN0076_FR_0206, ADC_ESDD_UD_111, EAAR_PN0034_FR_0049 */
/* MISRA Violation: START Msg(5:3206)-14 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DisableHwTrigger
(Adc_GroupType Group, Adc_HwTriggerTimerType TriggerSource)
{
/* END Msg(5:3206)-14 */
  Adc_GroupType LddDiagGroup;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;

  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_DISABLE_HW_TRIGGER_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /*
   * Check if the Group requested is valid and group is enabled for
   * PWM diagnostic.
   */
  else if ((Group >= Adc_GucNoOfGroups) ||
           (Group < (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups)))
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_DISABLE_HW_TRIGGER_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  #endif
  {
    /* Get the index of the requested group Id in the PWM diagnostic array */
    if ( Adc_GucNoOfGroups > Adc_GucNoOfPwmDiagGroups )
    {
        LddDiagGroup = (Group - (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups));
    }
    else
    {
        LddDiagGroup = Group;
    }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Check if the TriggerSource is not current trigger source */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (TriggerSource != Adc_GpPwmGroupData[LddDiagGroup].ucTriggSrcIndex)
    /* END Msg(4:0491)-1 */
    {
      /* Implements ADC069 */
      /* Implements ADC067 */
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_DISABLE_HW_TRIGGER_SID, ADC_E_PARAM_TRIGGSRC);
      /* Set the error status flag to E_OK */
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  #endif
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Call the internal function to reset the CTDR register */
    Adc_IntDisableHwTrigger(LddDiagGroup);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_HwResultReadGroup
**
** Service ID           : 0x0F
**
** Description          : This API reads the converted result for the PWM diag
**                        Channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and pDataBuffer
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_IntHwResultReadGroup
**
** Registers Used       : DTCm, ADCAnPWDDIR, ADCAnECR, PWSAnPVCRx_y, ADCAnOWER,
**                        ADCAnULER, WUF0, WUFC0
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_104 */
/* Implements AR_PN0076_FR_0103, EAAR_PN0034_FR_0049 */
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_HwResultReadGroup
(Adc_GroupType Group,
            P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) pDataBuffer)
{
  Adc_GroupType LddDiagGroup;
  Std_ReturnType LddRetValue;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  #endif

  /* MISRA Violation: START Msg(4:2982)-4 */
  LddRetValue = E_NOT_OK;
  /* END Msg (4:2982)-4 */
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Initialize the error flag */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_HW_RESULT_READ_GROUP_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /*
   * Check if the Group requested is valid and group is enabled for
   * PWM diagnostic.
   */
  else if ((Group >= Adc_GucNoOfGroups) ||
           (Group < (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups)))
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_HW_RESULT_READ_GROUP_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the index of the requested group Id in the PWM diagnostic array */
    if ( Adc_GucNoOfGroups > Adc_GucNoOfPwmDiagGroups )
    {
        LddDiagGroup = (Group - (Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups));
    }
    else
    {
        LddDiagGroup = Group;
    }
    /*
     * Invoke the internal function to read the digital value of
     * PWM Diagnostic group.
     */
    LddRetValue = Adc_IntHwResultReadGroup(LddDiagGroup, pDataBuffer);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
  return(LddRetValue);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_DisableChannel
**
** Service ID           : 0x10
**
** Description          : Disable the specified channel from group at the run
**                        time.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and ChannelId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucNoOfGroups, Adc_GucNoOfPwmDiagGroups
**
** Functions invoked    : Det_ReportError, Adc_IntDisableEnableChannel
**
** Registers Used       : None
*******************************************************************************/
/* Implements AR_PN0076_FR_0212 */
#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Implements AR_PN0076_FR_0200, ADC_ESDD_UD_104, EAAR_PN0034_FR_0049 */
/* Implements ADC_ESDD_UD_012 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DisableChannel (Adc_GroupType Group,
Adc_ChannelType ChannelId)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize the error flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_DISABLE_CHANNEL_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_DISABLE_CHANNEL_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if the group is already enabled */
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (ADC_IDLE != Adc_GpGroupRamData[Group].enGroupStatus)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC065 */
    /* Implements SWS_Adc_00433 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_DISABLE_CHANNEL_SID, ADC_E_BUSY);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Set the channel to be disabled from conversion after start group
     * conversion.
     */
    Adc_IntDisableEnableChannel(Group, ChannelId, ADC_FALSE);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_EnableChannel
**
** Service ID           : 0x11
**
** Description          : Enable the specified channel from group at the run
**                        time.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and ChannelId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GucNoOfPwmDiagGroups, Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_IntDisableEnableChannel
**
** Registers Used       : None
*******************************************************************************/
/* Implements AR_PN0076_FR_0212 */
/* Implements ADC_ESDD_UD_013 */
#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/* Implements AR_PN0076_FR_0201, ADC_ESDD_UD_104, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_EnableChannel (Adc_GroupType Group,
Adc_ChannelType ChannelId)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize the error flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_ENABLE_CHANNEL_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_ENABLE_CHANNEL_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if the group is already enabled */
  /* MISRA Violation: START Msg(4:0491)-1 */
  else if (ADC_IDLE != Adc_GpGroupRamData[Group].enGroupStatus)
  /* END Msg(4:0491)-1 */
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_ENABLE_CHANNEL_SID, ADC_E_BUSY);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Set the channel to be enabled for conversion after start group
     * conversion.
     */
    Adc_IntDisableEnableChannel(Group, ChannelId, ADC_TRUE);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_SetThreshold
**
** Service ID           : 0x12
**
** Description          : Sets the Upperlimit and Low limit check values in
**                        ADCAnULLMTBRx register.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group, ADCAnULLMTBRx, UpperLimit, LowerLimit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GblDriverStatus,
**                        Adc_GpFlexibleLimitCheckRange
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/
#if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_FLEXIBLE_THRESHOLD == STD_ON))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_155 */
/* Implements ADC_ESDD_UD_161 */
/* Implements AR_PN0076_FR_0260, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_SetThreshold(Adc_GroupType Group,
uint8 LucADCAnULLMTBRx, uint16 UpperLimit, uint16 LowerLimit)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Local variable to store the Maximum value of HW unit */
  uint32 LulMaxValue;
  #endif
  /* Local variable to store the Resolution of HW unit  */
  uint32 LulResolution;
  /* Local variable to get the ULLMTRB */
  uint32 LulULLMTRBxValue;
  /* Local variable to store Value of UpperLimit */
  uint16 LusUpperLimit;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store Value of LowerLimit */
  uint16 LusLowerLimit;
  #endif
  /* Local variable to store Value of ULLMTBR Index */
  uint8 LucIndex;
  /* Local variable to store shift value of High Limit */
  uint8 LucHighShiftValue;
  /* Local variable to store shift value of Low Limit */
  uint8 LucLowShiftValue;
  /* Local variable to get the HW unit */
  uint8 LucHwUnit;
  /* Local variable to get the ULLMTRB */
  uint8 LucULLMTRB;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Local variable for the Maximum limit check registers for the given group */
  uint8 LucMaxLmitcheckReg;
  #endif
  /* Read the Value of UpperLimit Index */
  LusUpperLimit = UpperLimit;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Read the Value of LowerLimit Index */
  LusLowerLimit = LowerLimit;
  #endif
  /* Read the Value of ULLMTBRx Index */
  LucIndex = LucADCAnULLMTBRx;
  /* Get Hardware unit Index */
  LucHwUnit = LucIndex / ADC_SIXTEEN;
  /* Get Hardware unit ULLMTBR */
  LucULLMTRB = LucIndex % ADC_SIXTEEN;
  /* Get the Resolution of HW unit  */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LulResolution = ADC_10BIT_RESOLUTION &
                                 Adc_GpHwUnitConfig[LucHwUnit].ulHwUnitSettings;
  /* END Msg(4:0491)-1 */
  LucHighShiftValue = ADC_SIXTEEN;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Maximum limit check registers that can be used for the given group */
  LucMaxLmitcheckReg = Adc_GpGroupConfig[Group].ucMaxLimitcheck;
  #endif
  /* Implements AR_PN0076_FR_0219 */
  /* Check if Resolution is 10-Bit */
  if (ADC_10BIT_RESOLUTION != LulResolution)
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Get the Maximum Limit Check Value */
    LulMaxValue = ADC_12BIT_MAXVALUE;
    #endif
    LucLowShiftValue = ADC_FOUR;
  }
  else
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Get the Maximum Limit Check Value */
    LulMaxValue = ADC_10BIT_MAXVALUE;
    #endif
    LucLowShiftValue = ADC_SIX;
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_SET_THRESHOLD_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }

  /*If ENHANCED LIMIT CHECK feature is enabled.*/
  #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
  /* Check if the HW unit is invalid */
  else if ((ADC_ONE < LucHwUnit) || (ADC_SEVEN < LucULLMTRB)||
           (LucULLMTRB >= LucMaxLmitcheckReg)||
           (ADC_INVALID_MAXLIMITCHECK == LucMaxLmitcheckReg))
  #else
  /* Check if the HW unit is invalid */
  else if ((ADC_ONE < LucHwUnit) || (ADC_TWO < LucULLMTRB)||
           (LucULLMTRB >= LucMaxLmitcheckReg)||
           (ADC_INVALID_MAXLIMITCHECK == LucMaxLmitcheckReg))
  #endif
  {
    /* Implements ADC069 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_SET_THRESHOLD_SID, ADC_E_PARAM_INDEX);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if the limit check values are Invalid */
  else if ((LulMaxValue < LusUpperLimit) || (LusUpperLimit < LusLowerLimit))
  {
    /* Implements ADC069 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_SET_THRESHOLD_SID, ADC_E_PARAM_LIMIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_SET_THRESHOLD_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /* Set High Limit value and Low Limit value in RAM allocation */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LucULLMTRB = LucULLMTRB + (Adc_GpGroupConfig[Group].ucLimitCheckIndex);
    /* END Msg(4:0491)-1 */
    /* Check if 10-Bit resolution or not */
    if (ADC_10BIT_RESOLUTION == LulResolution)
    {
      /* MISRA Violation: START Msg(4:2983)-10 */
      /* Set High and Low Limit value for 10-Bit Resolution */
      LulULLMTRBxValue = (((uint32)LusUpperLimit) << LucHighShiftValue);
      LulULLMTRBxValue = (LulULLMTRBxValue << (uint32)ADC_SIX);
      LulULLMTRBxValue = (LulULLMTRBxValue | ADC_10BIT_MASK_VALUE);
      LulULLMTRBxValue = (LulULLMTRBxValue | (((uint32)LowerLimit) <<
                                                      LucLowShiftValue));
      /* END Msg(4:2983)-10 */
    }
    else
    {
      /* MISRA Violation: START Msg(4:2983)-10 */
      /* Set High and Low Limit value for 12-Bit Resolution */
      LulULLMTRBxValue = (((uint32)LusUpperLimit) << LucHighShiftValue);
      LulULLMTRBxValue = (LulULLMTRBxValue << (uint32)ADC_FOUR);
      LulULLMTRBxValue = (LulULLMTRBxValue | (((uint32)LowerLimit) <<
                                                      LucLowShiftValue));
      /* END Msg(4:2983)-10 */
    }
    /* MISRA Violation: START Msg(4:2991)-11 */
    /* MISRA Violation: START Msg(4:2995)-12 */
    /* Check flexible limit check index is within the range*/
    if((ADC_FLEX_LIMITCHECK_RANGE < LucULLMTRB) ||
                               (ADC_FLEX_LIMITCHECK_RANGE == LucULLMTRB))
    {
        /* END Msg(4:2991)-11 */
        /* END Msg(4:2995)-12 */
        /*No action required*/
    }
    else
    {
        /* Load the upper and low limit for error check */
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* MISRA Violation: START Msg(4:2880)-13 */
        Adc_GpFlexibleLimitCheckRange[LucULLMTRB] = LulULLMTRBxValue;
        /* END Msg(4:0491)-1 */
        /* END Msg(4:2880)-13 */
    }
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) &&
                                           (ADC_FLEXIBLE_THRESHOLD == STD_ON))*/

/*******************************************************************************
** Function Name        : Adc_SelectChannelThreshold
**
** Service ID           : 0x13
**
** Description          : Enables or Disables the channel limit check of
**                        Particular channel in a Group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : AdcChannelId and Threshold.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**
** Global Variables     : Adc_GblDriverStatus, Adc_GpFlexibleChannelToGroup
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/
/* Implements AR_PN0076_FR_0261 */
#if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_FLEXIBLE_THRESHOLD == STD_ON))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_156 */
/* Implements ADC_ESDD_UD_161 */
/* Implements AR_PN0076_FR_0259, EAAR_PN0034_FR_0049 */
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SelectChannelThreshold(
Adc_GroupType Group, Adc_ChannelType AdcChannelId, Adc_ThresholdType Threshold)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  #endif
  Std_ReturnType LddRetValue;
  /* Defining a pointer to the Group */
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  /* Local variable to get the ThresholdShortName */
  Adc_ThresholdType LucThresholdShortName;
  /* Defining a local variable to Threshold */
  uint16 LusThreshold;
  /* Defining a local variable to channel */
  uint16 LusChannelValue;
  /* Defining a local variable to Channel Index */
  uint8 LucChannelToGroupIndex;
  /* Defining a local variable to Channel count */
  uint8 LucChannelCount;
  /* Defining a local variable to Loop count */
  uint8 LucLoopCount;
  /* Defining a local variable to Channel ID */
  uint8 LucChannelId;

  /* Initialize Return to E_NOT_OK */
  LddRetValue = E_NOT_OK;
  /* Get the Adc_ThresholdType */
  LucThresholdShortName = Threshold;
  /* Defining a pointer to the Group */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpGroup = &Adc_GpGroupConfig[Group];
  /* END Msg(4:0491)-1 */
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_SET_CHANNEL_THRESHOLD_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }

  /*If ENHANCED LIMIT CHECK feature is enabled.*/
  #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
  /* Check if the Limit check threshold value is invalid. */
  else if (ADC_EIGHT < LucThresholdShortName)
  #else
  /* Check if the Limit check threshold value is invalid. */
  else if (ADC_THREE < LucThresholdShortName)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_SET_CHANNEL_THRESHOLD_SID, ADC_E_PARAM_THRESHOLD);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /* Check if the Group is invalid */
  else if (ADC_TRUE != LpGroup->blLimitCheckEnabled)
  {
    /* Implements ADC069 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_SET_CHANNEL_THRESHOLD_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                             ADC_SET_CHANNEL_THRESHOLD_SID, ADC_E_PARAM_GROUP);

    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No Actions required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /*If ENHANCED LIMIT CHECK feature is enabled.*/
    #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
    /* place the Threshold to the ULS[3:2] bit[11,10] for ADCAnVCR register.*/
    LusThreshold = (((uint16)LucThresholdShortName &
               (uint16)ADC_ENHANCED_LC_MSB_MASK)  << ADC_ENHANCED_LC_MSB_POS);
    /* place the Threshold to the ULS[1:0] bit[7,6] for ADCAnVCR register. */
    /* MISRA Violation: START Msg(4:4397)-6 */
    LusThreshold |=
    (((uint16)LucThresholdShortName & (uint16)ADC_ENHANCED_LC_LSB_MASK)
                                                   << ADC_ENHANCED_LC_LSB_POS);
    /* END Msg(4:4397)-6 */
    #else
    /* Set Threshold Value to correct position */
    LusThreshold = ((uint16)LucThresholdShortName << ADC_SIX);
    #endif

    /* Get group index of 1st channel, configured for the requested group */
    LucChannelToGroupIndex = LpGroup->ucChannelToGroupIndex;
    /* Re-Initialize the channel count to actual configured no of channels */
    LucChannelCount = LpGroup->ucChannelCount;
    /* Map the Threshold to the virtual channels */
    for (LucLoopCount = ADC_ZERO; (uint8_least)LucChannelCount >
                                 LucLoopCount; LucLoopCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      LucChannelId = (uint8)(Adc_GpFlexibleChannelToGroup
                    [LucChannelToGroupIndex + LucLoopCount] & ADC_MASK_CHANNEL);
      /*If Enhanced limit check feature is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      LusChannelValue = (uint8)(Adc_GpFlexibleChannelToGroup
             [LucChannelToGroupIndex + LucLoopCount] &
                                         ADC_ENHANCED_LC_THRESHOLD_MASK_VALUE);
      #else
      LusChannelValue = (uint8)(Adc_GpFlexibleChannelToGroup
            [LucChannelToGroupIndex + LucLoopCount] & ADC_THRESHOLD_MASK_VALUE);
      #endif
      /* END Msg(4:0491)-1 */

      if (AdcChannelId == LucChannelId)
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        Adc_GpFlexibleChannelToGroup[LucChannelToGroupIndex + LucLoopCount] =
                                               (LusChannelValue | LusThreshold);
        /* END Msg(4:0491)-1 */
        LddRetValue = E_OK;
      }
      else
      {
        /* No action required */
      }
    }
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  if ((E_NOT_OK == LddRetValue) && (E_NOT_OK == LenDetErrFlag))
  {
    /* Implements ADC067 */
    /* Report Error to DET for Invalid Channel ID */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_SET_CHANNEL_THRESHOLD_SID, ADC_E_PARAM_CHANNEL);
  }
  else
  {
    /* No Actions required */
  }
  #endif
  return(LddRetValue);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) &&
                                         (ADC_FLEXIBLE_THRESHOLD == STD_ON))  */

/*******************************************************************************
** Function Name        : Adc_CusGetADCAnDRmAddr
**
** Service ID           : 0x14
**
** Description          : This is internal function, used to return the  ADC
**                        Data register address of the first virtual channel
**                        assigned to the ADC channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GucNoOfGroups
**
** Functions invoked    : Det_ReportError, Adc_IntCusGetADCAnDRmAddr
**
** Registers Used       : ADCAnDRj
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_157 */
/* Implements AR_PN0076_FR_0303, EAAR_PN0034_FR_0049 */
FUNC(Adc_AddressType, ADC_PUBLIC_CODE) Adc_CusGetADCAnDRmAddr
                                                        (Adc_GroupType Group)
{
  Adc_AddressType LddRetValue;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  #endif
  /* MISRA Violation: START Msg(4:2982)-4 */
  /* Initialize the return value to zero*/
  LddRetValue = ADC_ZERO;
  /* END Msg (4:2982)-4 */
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                     ADC_CUS_GET_ADCADRADDR_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Check if the Group Id is invalid */
  else if (Group >= (Adc_GucNoOfGroups-Adc_GucNoOfPwmDiagGroups))
  #else
  else if (Group >= Adc_GucNoOfGroups)
  #endif
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_CUS_GET_ADCADRADDR_SID, ADC_E_PARAM_GROUP);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * get the DR register address
     */
    LddRetValue = Adc_IntCusGetADCAnDRmAddr(Group);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  return(LddRetValue);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements AR_PN0076_FR_0256*/
/*******************************************************************************
** Function Name        : Adc_EnableIntAdcErr
**
** Service ID           : 0x15
**
** Description          : This is internal function, used to Enable the Error
**                        Interrupt.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : LucHwunit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_IntEnableDisableAdcErr
**
** Registers Used       : ICADCAnERR
*******************************************************************************/
#if (ADC_ERROR_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_169 */
/* Implements ADC_ESDD_UD_150 */
/* Implements ADC_ESDD_UD_025 */
/* Implements AR_PN0076_FR_0257, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_EnableIntAdcErr(uint8 LucHwunit)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                          ADC_ENABLE_ERR_INT_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else if ((uint8_least)ADC_MAX_HW_UNITS < LucHwunit )
  {
    /* Implements ADC069 */
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_ENABLE_ERR_INT_SID, ADC_E_PARAM_HWUNIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /*
     * Call Internal Function to Enable
     */
    Adc_IntEnableDisableAdcErr(LucHwunit, ADC_TRUE);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if( ADC_ERROR_SUPPORT == STD_ON ) */

/*******************************************************************************
** Function Name        : Adc_DisableIntAdcErr
**
** Service ID           : 0x16
**
** Description          : This is internal function, used to Disable the Error
**                        Interrupt.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : LucHwunit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_IntEnableDisableAdcErr
**
** Registers Used       : ICADCAnERR
*******************************************************************************/
#if (ADC_ERROR_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_170 */
/* Implements ADC_ESDD_UD_150 */
/* Implements ADC_ESDD_UD_025 */
/* Implements EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_DisableIntAdcErr(uint8 LucHwunit)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067 */
    /* Implements AR_PN0076_FR_0257 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                         ADC_DISABLE_ERR_INT_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else if ((uint8_least)ADC_MAX_HW_UNITS < LucHwunit)
  {
    /* Implements ADC067 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_DISABLE_ERR_INT_SID, ADC_E_PARAM_HWUNIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /*
     * Call Internal Function to Enable
     */
    Adc_IntEnableDisableAdcErr(LucHwunit, ADC_FALSE);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if ( ADC_ERROR_SUPPORT == STD_ON )*/

/*******************************************************************************
** Function Name        : Adc_CusSetSamplingClock
**
** Service ID           : 0x17
**
** Description          : This is a Vendor specific API to configure during run
**                        time ADCAnSMPCR register of the corresponding HW unit
**                        with 18 cycle or 24 cycle settings.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : HwIndex, SamplingClock
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_HwCusSetSamplingClock
**
** Registers Used       : ADCAnSMPCR
*******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_177 */
/* Implements ADC_ESDD_UD_025 */
/* Implements AR_PN0076_FR_0314, EAAR_PN0034_FR_0049 */
FUNC(void, ADC_PUBLIC_CODE) Adc_CusSetSamplingClock(Adc_HardwareIndexType
                                   HwIndex, Adc_SamplingClockType SamplingClock)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Implements ADC269 */
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Implements ADC065 */
    /* Implements ADC067, SWS_Adc_00486 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_CUS_SET_SAMPLING_CLK_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }

  /* Implements AR_PN0076_FR_0257 */
  else if (ADC_MAX_HW_UNITS <= (uint16)HwIndex)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_CUS_SET_SAMPLING_CLK_SID, ADC_E_PARAM_HWUNIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else if (ADC_SCLK_24 < SamplingClock)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_CUS_SET_SAMPLING_CLK_SID, ADC_E_PARAM_SAMPLE_CLK);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /*
     * Call Internal Function to set the sampling time
     */
    Adc_HwCusSetSamplingClock(HwIndex, SamplingClock);
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_CusGetPWSAnPVCRx_y_16bit
**
** Service ID           : 0x18
**
** Description          : This  function is used to get the value of
**                        PWSAnPVCRx_y based on channel number as 16 bit value.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : PwmDiagChannelID
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_IntCusGetPWSAnPVCRx_y
**
** Registers Used       : PWSAnPVCRx_y
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, AR_PN0076_FR_0101 */
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_180, EAAR_PN0034_FR_0049 */
FUNC(uint16, ADC_PUBLIC_CODE) Adc_CusGetPWSAnPVCRx_y_16bit (uint8
                                                               PwmDiagChannelID)
{
  Adc_PWSARegisterType LulRegisterValue;
  Adc_PWSAReturnType LusReturnValue;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  LusReturnValue = ADC_INVALID_PVCR_VALUE_16BIT;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                         ADC_GET_PWS_REG16_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /*No action required*/
  }
  /*if PwmDiagChannelID > maximum diag channel*/
  if (ADC_MAX_DIAG_CHANNEL < PwmDiagChannelID)
  {
     /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_GET_PWS_REG16_SID, ADC_E_PARAM_CHANNEL);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
     /*No action required*/
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  {
    /*Read register value as 32 bit based on channel Id*/
    LulRegisterValue = Adc_IntCusGetPWSAnPVCRx_y(PwmDiagChannelID);
    if (ADC_ONE == (PwmDiagChannelID & ADC_ONE))
    {
     /*If diag channel Id is Odd then take upper 16 bit and return*/
      LusReturnValue = (Adc_PWSAReturnType)((LulRegisterValue &
                                          ADC_PWSA_ODD_MASK) >>  ADC_SHIFT_16);
    }
    else
    {
       /*Diag channel Id is even. Return lower 16 bit*/
       LusReturnValue = (Adc_PWSAReturnType)(LulRegisterValue &
                                                            ADC_PWSA_EVEN_MASK);
    }
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No Action */
  }
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  /*Return the 16 bit value*/
  return (LusReturnValue);
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
** Function Name        : Adc_CusGetPWSAnPVCRx_y_32bit
**
** Service ID           : 0x19
**
** Description          : This function is used to get the value of PWSAnPVCRx_y
**                         based on channel number as 32 bit value.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : PwmDiagChannelID
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GblDriverStatus
**
** Functions invoked    : Adc_IntCusGetPWSAnPVCRx_y, Det_ReportError
**
** Registers Used       : PWSAnPVCRx_y
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_181 */
/* Implements AR_PN0076_FR_0225, EAAR_PN0034_FR_0049 */
FUNC(uint32, ADC_PUBLIC_CODE) Adc_CusGetPWSAnPVCRx_y_32bit (uint8
                                                               PwmDiagChannelID)
{
  Adc_PWSARegisterType LulRegisterValue;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  LulRegisterValue = ADC_INVALID_PVCR_VALUE_32BIT;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not Initialized */
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                         ADC_GET_PWS_REG32_SID, ADC_E_UNINIT);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /*No action required*/
  }
  /*if PwmDiagChannelID > maximum diag channel*/
  if (ADC_MAX_DIAG_CHANNEL < PwmDiagChannelID)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_GET_PWS_REG32_SID, ADC_E_PARAM_CHANNEL);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  /*If the requested channel Id is ODD*/
  else if (ADC_ONE == (PwmDiagChannelID & ADC_ONE))
  {
     /* Report Error to DET */
     (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_GET_PWS_REG32_SID, ADC_E_PARAM_CHANNEL);
    /* Set the error status flag to E_OK */
     LenDetErrFlag = E_OK;
  }
  else
  {
    /*No action required*/
  }
  if (E_NOT_OK == LenDetErrFlag)
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  {
    /*Read and return 32 bit diag channel register value*/
    LulRegisterValue = Adc_IntCusGetPWSAnPVCRx_y(PwmDiagChannelID);

  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No Action */
  }
  #endif/*ADC_DEV_ERROR_DETECT == STD_ON*/
  return (LulRegisterValue);
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
** Function Name      : Adc_GetVersionInfo
**
** Service ID         : 0x0A
**
** Description        : This service returns the version information of this
**                      module.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : versioninfo
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
** Functions invoked  : Det_ReportError
**
*******************************************************************************/
#if (ADC_VERSION_INFO_API == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_073 */
/* Implements ADC_ESDD_UD_004 */
/* Implements SWS_Adc_00376, ADC376, EAAR_PN0034_FR_0051 */
/* Implements SWS_Adc_00458, ADC458, EAAR_PN0034_FR_0049, ADC236 */
/* Implements EAAR_PN0034_FR_0092 */
FUNC(void, ADC_PUBLIC_CODE) Adc_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, ADC_APPL_CONST) versioninfo)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
 /* Report to DET, if versioninfo pointer is equal to Null */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_GET_VERSION_INFO_SID, ADC_E_PARAM_POINTER);
  }
  else
  #endif /*#if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)ADC_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)ADC_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = ADC_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = ADC_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = ADC_SW_PATCH_VERSION;
  }
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif  /*(ADC_VERSION_INFO_API == STD_ON)*/

/*******************************************************************************
** Function Name        : Adc_CheckHWConsistency
**
** Service ID           : 0x1A
**
** Description          : This service returns the status of hardware
**                        consistency check.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non Re-entrant
**
** Input Parameters     : LddCheckType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : The ADC Driver must be Initialized first by invoking
**                        API Adc_Init().
**                        This API is available only if the pre-compile
**                        option AdcADCARamMirror or AdcPwmDiagRamMirror or
**                        AdcDMACRamMirror is ENABLE.
**
** Global Variables     : None
**
** Functions invoked    : Adc_HwCheckHWConsistency(), Det_ReportError
**                        ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION.
**
** Registers Used       : ADCAnVCRj, ADCAnADCR, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnSMPCR,
**                        ADCAnULLMTBRx, ADCAnSGCRx, ADCAnSGVCSPx, ADCAnSGVCEPx,
**                        ADCAnSGTSELx, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnPDCTL1,
**                        ADCAnPDCTL2, DTCTm, DRSAm, DRDAm, DRTCm, DTFRm,
**                        PWGAnCTDR, PWSAnPVCRx_y, ADCAnSFTCR, ADCAnSGMCYCRx,
**                        PWSAnCTL, ADCAnPWDSGCR, DTCm
*******************************************************************************/
#if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements EAAR_PN0034_FSR_0007, ADC_ESDD_UD_195 */
/* Implements EAAR_PN0034_FR_0049 */
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_CheckHWConsistency
                   (Adc_HWConsistencyCheckType LddCheckType)
{
  Std_ReturnType LucCheckStatus;

  /* MISRA Violation: START Msg(4:2982)-4 */
  LucCheckStatus = E_OK;
  /* END Msg(4:2982)-4 */
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if (ADC_UNINITIALIZED == Adc_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_CHECK_HW_CONSISTENCY_SID, ADC_E_UNINIT);
    LucCheckStatus = E_NOT_OK;
  }
  else
  #endif
  if ((ADC_HW_CONSISTENCY_STATIC != LddCheckType) &&
        (ADC_HW_CONSISTENCY_DYNAMIC != LddCheckType))
  {
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_CHECK_HW_CONSISTENCY_SID, ADC_E_PARAM_VALUE);
    LucCheckStatus = E_NOT_OK;
  #endif
  }
  else
  {
    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif

    LucCheckStatus = Adc_HwCheckHWConsistency(LddCheckType);

    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif
    }
  return LucCheckStatus;
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif  /*((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) ||
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))*/
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
