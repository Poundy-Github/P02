/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Private.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Internal functions implementation of ADC Driver Component                  */
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
/* Implements EAAR_PN0034_NR_0018, AR_PN0076_FR_0027, AR_PN0076_FR_0028 */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  08-Sep-2015    : Initial Version
 * V1.0.1:  23-Oct-2015    : The Following variable renamed to include Module
 *                           prefix in the variable name.
 *                           1. DmaReg_BaseAddress to AdcDmaReg_BaseAddress
 *                           2. PWGAReg_BaseAddress to AdcPWGAReg_BaseAddress
 *                           3. PWSAReg_BaseAddress to AdcPWSAReg_BaseAddress
 *                           4. WUFReg_BaseAddress to AdcWUFReg_BaseAddress
 * V1.0.2:  12-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAAGA-72,
 *                              New APIs Adc_HwCusSetSamplingClock and
 *                              Adc_IntCusGetPWSAnPVCRx_y are added.
 *                           2. As a part of JIRA ticket ARDAAGA-72,
 *                              Double buffer support is added for PWM
 *                              diagnostics.
 *                           3. As a part of JIRA ticket ARDAAGA-72,
 *                              API, Adc_IntHwResultReadGroup is updated to
 *                              avoid over write cases in DMA transfer.
 *                           4. As a part of JIRA ticket ARDAAGA-72,
 *                              Precompile switch added in API,
 *                              Adc_HaltScanGroup.
 *                           5. As a part of JIRA ticket ARDAAGA-58,
 *                              CMVC register access is corrected and unused
 *                              register declarations are removed.
 *                           6. As a part of JIRA ticket ARDAAGA-72,
 *                              The compiler switch ADC_DMA_TYPE_USED is
 *                              removed.
 *                           7. As a part of JIRA ticket ARDAAGA-171,
 *                              Register accesses are modified.
 *                           8. Compiler switches are added in APIs
 *                              Adc_HwStopGroupConversion, Adc_DisableHWGroup,
 *                              Adc_ConfigureGroupForConversion,
 *                              Adc_IsrConfigureGroupForConversion,
 *                              Adc_ChannelCompleteMode, Adc_GroupCompleteMode,
 *                              Adc_PollingReadGroup, Adc_IntEnableHwTrigger and
 *                              removed from API Adc_GroupCompleteMode and
 *                              Adc_ChannelCompleteMode.
 *                           9. As a part of JIRA ticket ARDAAGA-171,
 *                              Renamed 'ucMaxDiagRunTime' as
 *                              'usMaxDiagRunTime' and 'LucDiagLoopCount' as
 *                              'LusDiagLoopCount'.
 *                           10.As a part of JIRA ticket ARDAAGA-167,
 *                              Renamed ulDR[] as usDR[].
 *                           11.Misra justifications are added.
 *                           12.As a part of JIRA ticket ARDAAGA-168,
 *                              statements are added to update return value when
 *                              ADC_ENABLE_LIMIT_CHECK is STD_ON.
 *                           13.As a part of JIRA ticket ARDAAGA-170,
 *                              ADC_DEM_ERROR_DETECT switch added for
 *                              Dem_ReportErrorStatus call in
 *                              Adc_IntEnableHwTrigger().
 * V2.0.0:  12-Sep-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-515,
 *                              LpGroup->ulStartVirChPtr is considered
 *                              in ulVCR and ulDIR registers address usage.
 *                           2. As a part of JIRA ticket ARDAABC-765,
 *                              Macro ADC_TIMEOUT is replaced by a
 *                              configuration parameter ADC_LOOP_TIMEOUT,
 *                              ADC_E_TIME_OUT is renamed ADC_E_TIME_OUT,
 *                              ADC_ENABLE_DIAGNOSTIC_SUPPORT is removed
 *                              from loop timeout Dem error report condition.
 *                           3. As a part of JIRA ticket ARDAABC-745,
 *                              Adc_InitRamMirror() implementation and usage
 *                              are added and Adc_GaaRamMirrorDmaReg fields are
 *                              updated.
 *                           4. As a part of JIRA ticket ARDAABC-743,
 *                              A part of registers write are modified with
 *                              specific functional safety macros.
 *                           5. As a part of JIRA ticket ARDAABC-743,
 *                              All the write registers are modified with the
 *                              specific functional safety macros.
 *                           6. As a part of JIRA ticket ARDAABC-743,
 *                              Fixed wrong index for ulULLMTBR register.
 *                           7. As part of JIRA ticket ARDAABC-810,
 *                              add traces in code for WV, HWCC and Endless Loop
 *                              FUSA requirements.
 * V2.1.0:  27-Sep-2016    : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-838, removed
 *                           redundant code from Adc_IntHwResultReadGroup()
 * V2.1.1:  06-Oct-2016    : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-361,
 *                              ADCAnECR status is cleared in
 *                              Adc_ConfigureGroupForConversion()
 * V2.2.0:  28-Oct-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-572,
 *                              Autosar version 3.2.2. was removed and
 *                              4.0.3 and 4.2.2 Autosar versions were added.
 * V2.2.1:  01-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              ADC_RAM_MIRROR_ENABLE/DISABLE renamed to
 *                              ADC_MIRROR_ENABLE/DISABLE, used WV check with
 *                              only one DEM event.
 * V2.2.2:  03-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-361,
 *                              added implementation with the customer agreed
 *                              final solution.
 * V2.2.3:  10-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-361,
 *                              updated implementation in Adc_PollingReadGroup
 *                              function with new customer proposed solution
 * V2.2.4:  11-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-516,
 *                              transfer clear flag was used instead of write
 *                              operation performed on LpDmaRegisters->ulDCST
 *                              read only register.
 * V2.2.0:  11-Nov-2016       : The following changes are made:
 *                            1. As a part of JIRA ticket ARDAABC-905,
 *                             Initialize RAM data variable
 *                             'ddCurrentConvGroup' before utilization.
 * V2.3.0:  15-Nov-2016       : The following changes are made:
 *                            1. As a part of JIRA ticket ARDAABC-912,
 *                              Remove the part of code that configures
 *                              registers CMVC, DM0CMV, DM1CMV
 *                              in Adc_HwInit().
 *                              Remove the second write of DCSTC register in
 *                              Adc_HwInit() which is useless.
 *                              Swap the order of DTFRRQC, which shall be set
 *                              before setting DTFR register.
 *                              Set the PWDSGCR register to 0x00 in
 *                              Adc_DeInit().
 * V2.4.0:  15-Nov-2016       : The following changes are made:
 *                            1. As a part of JIRA ticket ARDAABC-913,
 *                            All macro definitions are prefixed with module
 *                            name <ADC_>.
 *                            ~(ADC_ENABLE_SELF_DIAG) has been replaced
 *                            with ADC_DISABLE_SELF_DIAG.
 *                            Update 'Registers Used' section of the function
 *                            headers of all functions.
 * V2.4.1:  18-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Adc_HwCheckHWConsistency() function was added.
 *                           2. In Adc_HwInit() DCST register compared with
 *                              zero and ADC_DTFRRQ_DRQ_MAKS was replaced with
 *                              ADC_DTFRRQ_DRQ_CLEAR_VALUE.
 *                           3. Clear performed on DCSTC register is verified
 *                              by comparing DCSTm register with zero.
 *                           4. Halt operation shall be verified by comparing
 *                              SGSTR register value against zero.
 *                           4. Fixed 80-line width limit.
 * V2.4.2:  19-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              The for loop for checking SGMCYCR register
 *                              compiled out by ADC_ENABLE_STREAMING
 * V2.4.3:  21-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              updated write registers to use WV and HWCC
 *                              macros based on new FUSA design proposal.
 * V2.4.4:  21-Nov-2016      : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Added mask to ADCAnVCRj register for WV and
 *                              HWCC.
 *                              Removed PWGAnRDT register Write Verify Check.
 * V2.4.5:  23-Nov-2016      : The following changes are made:
 *                           1. As a part of review for JIRA ticket ARDAABC-905,
 *                              LpSgUnitData->ddCurrentConvGroup was initialize
 *                              with ADC_CURRENT_CONV_GROUP_INIT.
 * V2.4.6:  23-Nov-2016      : The following changes are made:
 *                           1. As a part of review for JIRA ticket ARDAABC-913,
 *                              the register names in  the 'Registers Used'
 *                              section of the function headers should have been
 *                              changed.
 * V2.5.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-940,
 *                              updated memory sections usage
 * V2.6.0:  25-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-935, the
 *                              decrementing of LucLoopCount variable is moved
 *                              in do-while condition;
 * V2.6.0:  26-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-602,
 *                              removed limit check range ADC_RANGE_NOT_BETWEEN.
 * V2.6.1:  27-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Input variable renamed for function
 *                              Adc_HwCheckHWConsistency().
 * V2.6.2:  28-Nov-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-912,
 *                              remove the second ADC_CHECK_WRITE_VERIFY_INIT
 *                              for ulDCSTC.
 * V2.7.0:  02-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-858,
 *                              Adc_GroupCompleteMode() is removed
 *                           2. QAC warnings have been removed or justified
 * V2.7.1:  05-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-361,
 *                              fixed wrong the condition for checking error
 *                              in Adc_PollingReadGroup (OR replaced with AND).
 *                           2. Removed used TABS.
 * V2.7.2:  05-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-745,
 *                              Updated condition check to keep constant
 *                              part on the left hand side of the check,
 *                              fixed misplaced else into Adc_PushToQueue.
 * V2.7.3:  06-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-913,
 *                              Added <ADC_> prefix to remained macro
 *                              definitions.
 * V2.7.4:  06-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-858,
 *                              Unused variables have been removed
 * V2.8.0:  09-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-586,
 *                              fixed else branch to avoid MISRA warning.
 * V2.9.0:  16-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              removed ADCAnADHALTR write verify and added
 *                              mask for DCSTC write verify check.
 * V2.9.1:  14-Jan-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-913,
 *                              updated register in 'Registers Used' section.
 * V2.9.2:  27-Jan-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-912,
 *                              Fixed 80 line width.
 * V2.10.0: 09-Feb-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-586,
 *                              Added MISRA justifications, updated code to
 *                              avoid MISRA violations in Adc_PushToQueue and
 *                              Adc_IntDisableHwTrigger functions.
 * V2.10.1: 15-Mar-2017    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-743,
 *                              Updated register masks for Write Verify checks.
 * V2.10.2: 17-Mar-2017    : Following changes are made:
 *                           1. As part of ARDAABC-858, Adc_PollingReadGroup
 *                              function updated for error support case.
 * V2.10.3: 20-Mar-2017    : Following changes are made:
 *                           1. As part of ARDAABC-361, Adc_HwInit and
 *                           Adc_HwDeInit functions were updated. Clearing of
 *                           ADCAnECR register was added.
 * V2.10.4: 25-June-2017   : Following changes are made:
 *                           1. MISRA message tags are added
 * V2.11.0: 07-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1725 ,ARDAABD-2323
 *                            a. mux hardware stabilisation time is implemented.
 *                            b. Support for ADC group Hard stop is implemented.
 *                            c. Added new private API Adc_StopScanGroup().
 *                            d. Added support for Enhanced limit check
 *                               functionality.
 *                            f. Updated write verify check for ulWUFC0 Register
 * V2.11.1:  28-Sep-2017    : Following changes are made:
 *                            1. As part of ARDAABD-2387,
 *                             a. Naming of Local variables is corrected
 *                                throughout as per requirement MCAL052.
 *                             b. Data type of input parameter LddGroup of the
 *                                function Adc_IntDisableHwTrigger is changed to
 *                                Adc_GroupType.
 *                             c. Meaningful macro definitions are added.
 *                            2. As part of ARDAABD-2140,
 *                               Section dealing with 'Mapping of physical
 *                               channels to the virtual channels' is modified
 *                               in Adc_ConfigureGroupForConversion()API to
 *                               avoid VCR register pointer increment for
 *                               disabled channels.
 *                            3. As part of ARDAABD-2421,
 *                               Dummy read and SYNCP operations are performed
 *                               using macro RH850_SV_CLEAR_ICR_SYNCP in
 *                               API Adc_ClearPendingInterrupt.
 *                            4. As part of ARDAABD-2468,
 *                               Inclusion for Iocommon_Defines.h is added
 *                            5. As part of ARDAABD-2568,
 *                             a. comments are added for array declarations,
 *                                space is added between 'for', 'if'
 *                                and parenthesis
 *                            6. Unnecessary typecast of uint8_least is removed
 *                               to avoid MISRA warning from the function
 *                               Adc_ConfigureGroupForConversion.
 * V2.11.2:  26-Jul-2018    : Following changes are made:
 *                            1.As part of merging activity ticket ARDAABD-3452,
 *                               a.Macros RH850_SV_MODE_IMR_OR and
 *                                 RH850_SV_MODE_IMR_AND are replaced with
 *                                 RH850_SV_MODE_ICR_OR and
 *                                 RH850_SV_MODE_ICR_AND respectively. Macros
 *                                 ADC_INTERRUPT_MASK_EN, ADC_INTERRUPT_MASK_DIS
 *                                 are used instead of IMR mask. Function
 *                                 Adc_ImrInterruptBit renamed to
 *                                 Adc_IcrInterruptBit.Ref: ARDAABD-2158.
 *                               b.Copyright updated.
 *                            2.As part of ARDAABD-2996,
 *                              a.Write Verification for ADCAnECR register using
 *                                ADCAnULER, ADCAnOWER is removed.Function
 *                                banner is updated for the same.
 *                            3.As part of ARDAABD-1711, DET check for
 *                              ADC_E_INVALID_TRIGG_SOURCE has been modified in
 *                              functions Adc_IntEnableHwTrigger and
 *                              Adc_IntDisableHwTrigger.
 *                            4.As part of ARDAABD-1679, macro
 *                              ADC_ADCA_CHECK_WRITE_VERIFY_INIT is used for
 *                              write verification of ADCAnSFTCR, ADCAnSGMCYCRx,
 *                              ADCAnPWDSGCR registers.
 *                            5.As part of ARDAABD-3273, array index of
 *                              Adc_GaaSGmConvStatusMask[] has been changed to
 *                              'LucSgUnitId' and declaration statement of
 *                              unused variable 'LusNextHwSGUnit' has been
 *                              removed in Adc_HwStartGroupConversion.
 *                            6.As part of ARDAABD-2740,
 *                              Write verification is implemented for
 *                              ADCAnMPXSTBTR and ADCAnMPXSTBTSELR registers.
 *                            7.As part of ARDAABD-2763,
 *                              Adc_HwDeInit function is updated to remove the
 *                              Adc_GblDriverStatus update.
 *                            8.As part of ARDAABD-3638, the function banners
 *                              are updated with the list registers and
 *                              functions invoked.
 *                            9.As part of traceability improvement activity
 *                              ticket ARDAABD-2101, requirements and UD Ids are
 *                              added.
 * V2.11.3:  13-Aug-2018    : Following change is made:
 *                            1.As part of ARDAABD-2996,
 *                              a.Write Verification is removed for ADCAnECR
 *                                register.
 *                            2. As part of JIRA ARDAABD-3716 - Variable used to
 *                               Wait-loop shall be declared volatile.
 *                            3. As part of JIRA ARDAABD-3947,
 *                               a.Added invoking ADC_ENTER_CRITICAL_SECTION and
 *                                 ADC_EXIT_CRITICAL_SECTION while
 *                                 read-modify-write PWSAnPVCRx_y register.
 * V2.11.4:  15-Nov-2019    : Following change is made:
 *                            1.As part of ARDAABD-2787,
 *                              a.About Driver Used Registers
 *                                Added the implement for caution of HW user
 *                                manual.
 *                              b.Invoke Adc_HaltADConversion() processing
 *                                before write SFTCR registers in Adc_HwInit
 *                                function.
 *                              c.Added Adc_HaltADConversion function.
 *                              d.Added Adc_GblDriverStatus variable
 *                                assignment in Adc_HwDeInit().
 *                              e.Added Message 2986 and 2992.
 *                              f.Moved the Writing Back processing to the
 *                                front of notification.
 *                              g.Added CRITICAL SECTION for caution processing.
 *                              h.Deleted macro switch and added initialization 
 *                                for local variable
 *                            2.As part of ARDAABD-4639,
 *                              a.Moved variable setting for QAC check.
 *                            3.As part of ARDAABD-4639,
 *                              a.Moved variable setting for QAC check.
 *                            4.As part of ARDAABD-4677,
 *                              a.About Driver Used Registers
 *                                Modified the implement for caution of HW user
 *                                manual.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version check macro definitions and type definitions */
#include "Adc.h"
/* Included for the declaration of internal function prototypes */
#include "Adc_Private.h"
/* Included for RAM variable declarations */
#include "Adc_Ram.h"
/* Implements ADC_ESDD_UD_003 */
/* Implements EAAR_PN0034_FR_0064 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
#if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Adc.h"
#endif
/* Included for Write Verify and Hardware Consistency Check mechanisms */
#include "Adc_RegWrite.h"
/*Included for hardware register addresses*/
#include "Iocommon_Defines.h"
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) || (ADC_SOFT_STOP == STD_ON)
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define ADC_PRIVATE_C_AR_RELEASE_MAJOR_VERSION \
                                              ADC_AR_RELEASE_MAJOR_VERSION_VALUE
#define ADC_PRIVATE_C_AR_RELEASE_MINOR_VERSION \
                                              ADC_AR_RELEASE_MINOR_VERSION_VALUE
#define ADC_PRIVATE_C_AR_RELEASE_PATCH_VERSION \
                                           ADC_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ADC_PRIVATE_C_SW_MAJOR_VERSION    ADC_SW_MAJOR_VERSION_VALUE
#define ADC_PRIVATE_C_SW_MINOR_VERSION    ADC_SW_MINOR_VERSION_VALUE

/* Implements EAAR_PN0034_FR_0055, ADC124 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_PRIVATE_AR_RELEASE_MAJOR_VERSION != \
                                         ADC_PRIVATE_C_AR_RELEASE_MAJOR_VERSION)
  #error "Adc_Private.c : Mismatch in Release Major Version"
#endif

#if (ADC_PRIVATE_AR_RELEASE_MINOR_VERSION != \
                                         ADC_PRIVATE_C_AR_RELEASE_MINOR_VERSION)
  #error "Adc_Private.c : Mismatch in Release Minor Version"
#endif

#if (ADC_PRIVATE_AR_RELEASE_REVISION_VERSION != \
                                         ADC_PRIVATE_C_AR_RELEASE_PATCH_VERSION)
  #error "Adc_Private.c : Mismatch in Release Patch Version"
#endif

#if (ADC_PRIVATE_SW_MAJOR_VERSION != ADC_PRIVATE_C_SW_MAJOR_VERSION)
  #error "Adc_Private.c : Mismatch in Software Major Version"
#endif

#if (ADC_PRIVATE_SW_MINOR_VERSION != ADC_PRIVATE_C_SW_MINOR_VERSION)
  #error "Adc_Private.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To have a better readability of the code which will help   */
/*                 for debugging purpose array indexing is not performed.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-1 and                           */
/*                 END Msg(4:0488)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access only the lower byte of the converted values      */
/*                 from the conversion register.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-2 and                           */
/*                 END Msg(4:0759)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2469) Control variable, LucLoopCount, modified in body  */
/*                 of loop.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.6                                     */
/* Justification : This is to exit from the linear search loop when the       */
/*                 required channel Id is found.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2469)-3 and                           */
/*                 END Msg(4:2469)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION::                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-4 and                           */
/*                 END Msg(4:0303)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Pointer to the configuration array is used and verified    */
/*                 when accessing the boolean parameter value.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-5 and                           */
/*                 END Msg(4:0491)-5 tags in the code.                        */
/******************************************************************************/

/* 6.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2892)This loop will never be executed more than once.   */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : For hardware trigger groups the Group ID always be more    */
/*                 than the software trigger group so subtraction of Hardware */
/*                 trigger group to the software trigger group cannot be -ve  */
/*                 result.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2892)-6 and                           */
/*                 END Msg(4:2892)-6 tags in the code.                        */
/******************************************************************************/

/* 7.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2841)Definite: Dereference of an invalid pointer value. */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The array index is fixed for different SG unit. So value   */
/*                 accessing through an array with out of range, to maintain  */
/*                 easy accessibility Between hw scan groups                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2841)-7 and                           */
/*                 END Msg(4:2841)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) Bitwise operations on signed data will give       */
/*                 implementation defined results.                            */
/* Rule          : MISRA-C:2004 Rule 12.7                                     */
/* Justification : Though the bitwise operation is performed on unsigned,     */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex        */
/*                 bitwise operations.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-8 and                           */
/*                 END Msg(4:4397)-8 tags in the code.                        */
/******************************************************************************/

/* 9.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4461)This assignment is redundant. The value of this    */
/*                  object is never used before being modified.               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The Warning Occurs only if user configures one HW unit.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4461)-9 and                           */
/*                 END Msg(4:4461)-9 tags in the code.                        */
/******************************************************************************/

/*10. MISRA C RULE VIOLATION:                                                 */
/*Message       : (4:2985) This operation is redundant. The value of the      */
/*                result is always that of the left-hand operand.             */
/*Rule          : MISRA-C:2004 Rule 21.1                                      */
/*Justification : The value of the local variable accessed changes with       */
/*                configuration.                                              */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:2985)-10 and END Msg(4:2985)-10 tags   */
/*                in the code.                                                */
/*                                                                            */
/******************************************************************************/

/* 11.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2877)This loop will never be executed more than once.   */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The user can configures one or more instances for          */
/*                 ADC_MAX_HW_UNITS, ADC_CONFREG_INSTANCES,                   */
/*                 ADC_SGREG_INSTANCES, ADC_VIRCHREG_INSTANCES, etc. When one */
/*                 instance is configured the violation appears.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-11 and                          */
/*                 END Msg(4:2877)-11 tags in the code.                       */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0489) Increment or decrement operation performed on     */
/*               : pointer.                                                   */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To have a better readability of the code which will help   */
/*                 for debugging purpose array indexing is not performed.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-12 and                          */
/*                 END Msg(4:0489)-12 tags in the code.                       */
/******************************************************************************/

/* 13.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2995)The result of this logical operation is always     */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable 'LblPopGroupFrmQueue' is not necessary always */
/*                 TRUE. When the group is configured as streaming            */
/*                 'LblPopGroupFrmQueue' is false till all the samples not    */
/*                 completed.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-13 and                          */
/*                 END Msg(4:2995)-13 tags in the code.                       */
/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3218) File scope static, 'Adc_GaaOperationMask',        */
/*                 only accessed in one function.                             */
/* Rule          : MISRA-C:2004 Rule 8.7                                      */
/* Justification : By Moving the array into the function used the stack size  */
/*                 will be more, hence this is defined outside.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3218)-14 and                          */
/*                 END Msg(4:3218)-14 tags in the code.                       */
/******************************************************************************/

/* 15.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2984)This operation is redundant. The value of the      */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configured more number of SG units then this error */
/*                 mess not come. when comparing the SG units and HW units in */
/*                 loop then the loop execution depends on how many SG units  */
/*                 or HW units user configured                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-15 and                          */
/*                 END Msg(4:2984)-15 tags in the code.                       */
/******************************************************************************/

/* 16.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2996)This loop will never be executed more than once.   */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configured more number of SG units then this error */
/*                 mess not come. when comparing the SG units and HW units in */
/*                 loop then the loop execution depends on how many SG units  */
/*                 or HW units user configured                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-16 and                          */
/*                 END Msg(4:2996)-16 tags in the code.                       */
/******************************************************************************/

/* 17.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2993)This loop will never be executed more than once.   */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configured more number of SG units then this error */
/*                 mess not come. when comparing the SG units and HW units in */
/*                 loop then the loop execution depends on how many SG units  */
/*                 or HW units user configured                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2993)-17 and                          */
/*                 END Msg(4:2993)-17 tags in the code.                       */
/******************************************************************************/

/* 18.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2982)This assignment appears to be redundant because the*/
/*                 value of the object is not used before it is modified      */
/*                 again.                                                     */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable is assinged to false and then modified again  */
/*                 condition check is satisfied.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-18 and                          */
/*                 END Msg(4:2982)-18 tags in the code.                       */
/******************************************************************************/

/* 19.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:0317)Cast from a pointer to void to a pointer to object */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Void type pointer is taken in order not to publish the type*/
/*                 to the upper layer.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-19 and                          */
/*                 END Msg(4:0317)-19 tags in the code.                       */
/******************************************************************************/

/* 20. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : This is to access the hardware registers in the code.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-20 and                          */
/*                 END Msg(4:0306)-20 tags in the code.                       */
/******************************************************************************/

/* 21.  MISRA C RULE VIOLATION:                                               */
/* Message       :(4:0316) Cast from a pointer to void to a pointer to object */
/*                type.                                                       */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to access the hardware registers in the code.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-21 and                          */
/*                 END Msg(4:0316)-21 tags in the code.                       */
/******************************************************************************/

/* 22. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the FUSA macros to    */
/*                 avoid static analysis warning.                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-22 and                          */
/*                 END Msg(4:3138)-22 tags in the code.                       */
/******************************************************************************/

/* 23. QAC Warning:                                                           */
/* Message       : (2:3416) Logical operation performed on expression         */
/*                   with possible side effects.                              */
/* Rule          : Not Applicable                                             */
/* Justification : Wait-loop which may be deleted by optimization,            */
/*                 The Variable used toWait-loop shall be declared volatile.  */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3416)-23 and             */
/*                 END Msg(2:3416)-23 tags in the code.                       */
/******************************************************************************/

/* 24. QAC Warning:                                                           */
/* Message       : (2:3109) Null statement follows other code on the same     */
/*                 line. REFERENCE - ISO:C90-6.6.3 Expression and Null        */
/*                 Statements                                                 */
/* Rule          : Not Applicable                                             */
/* Justification : Warning triggered because of complex macro extended on     */
/*                 several lines, arranged for better readability             */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3109)-24 and             */
/*                 END Msg(2:3109)-24 tags in the code.                       */
/******************************************************************************/

/* 25. QAC Warning:                                                           */
/* Message       : (2:3139) Null statement is obscured by code or comment on  */
/*                 the same line.                                             */
/* Rule          : Not Applicable                                             */
/* Justification : Warning triggered because of complex macro extended on     */
/*                 several lines, because of 80 character limit.              */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3139)-25 and             */
/*                 END Msg(2:3139)-25 tags in the code.                       */
/******************************************************************************/

/* 26. QAC Warning:                                                           */
/* Message       : (2:3141) Null statement does not occur on a line by itself */
/* Rule          : Not Applicable                                             */
/* Justification : Warning triggered because of complex macro extended on     */
/*                 several lines, because of 80 character limit.              */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3141)-26 and             */
/*                 END Msg(2:3141)-26 tags in the code.                       */
/******************************************************************************/

/* 27. QAC Warning:                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : Not Applicable                                             */
/* Justification : Pointer is pointing to a statically defined array address  */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:2814)-27 and             */
/*                 END Msg(2:2814)-27 tags in the code.                       */
/******************************************************************************/

/* 28. QAC Warning:                                                           */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : Not Applicable                                             */
/* Justification : No impact generated for the casted value                   */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-28 and             */
/*                 END Msg(2:3892)-28 tags in the code.                       */
/******************************************************************************/

/* 29. QAC Warning:                                                           */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer    */
/* Rule          : Not Applicable                                             */
/* Justification : Pointer is pointing to a statically defined array address  */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:2824)-29 and             */
/*                 END Msg(2:2824)-29 tags in the code.                       */
/******************************************************************************/

/*30. MISRA C RULE VIOLATION:                                                 */
/*Message       : (4:2986) This operation is redundant. The value of the      */
/*                result is always that of the left-hand operand.             */
/*Rule          : MISRA-C:2004 Rule 21.1                                      */
/*Justification : The value of the local variable accessed changes with       */
/*                configuration.                                              */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:2986)-30 and END Msg(4:2986)-30 tags   */
/*                in the code.                                                */
/*                                                                            */
/******************************************************************************/

/*31. MISRA C RULE VIOLATION:                                                 */
/*Message       : (4:2992) The value of this 'if' controlling expression is   */
/*                always 'false'.                                             */
/*Rule          : MISRA-C:2004 Rule 14.3                                      */
/*Justification : The value of the local variable accessed changes with       */
/*                configuration.                                              */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:2992)-31 and END Msg(4:2992)-31 tags   */
/*                in the code.                                                */
/*                                                                            */
/******************************************************************************/

/* 32. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0492) Array subscripting applied to a function          */
/*                 parameter declared as a pointer                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Function parameter as a pointer is passed by user          */
/*                 when accessing converted result.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0492)-32 and                          */
/*                 END Msg(4:0492)-32 tags in the code.                       */
/******************************************************************************/

/* 33. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983) This assignment is redundant. The value of this   */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Deleted the macro switch for variables definition,         */
/*                 Avoid compilation errors(variables is not used).           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-33 and                          */
/*                 END Msg(4:2983)-33 tags in the code.                       */
/******************************************************************************/

/* 34. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3415) Right hand operand of '&&' or '||' is an          */
/*                 expression with possible side effects.                     */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 12.4                                     */
/*                 REFERENCE - ISO:C90-5,1,2,3 Program Execution              */
/* Justification : To prevent the compiler to deal with the optimization      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3415)-34 and                          */
/*                 END Msg(4:3415)-34 tags in the code.                       */
/******************************************************************************/

/******************************************************************************/
/**                               Static Data                                **/
/******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONST_ASIL_B_32
#else
  #define ADC_START_SEC_CONST_32
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE

/* MISRA Violation: START Msg(4:3218)-14 */
/*Array containing operation mode*/
STATIC CONST(uint32, ADC_CONST) Adc_GaaOperationMask[ADC_TWO] =
{
  ADC_SG1_CONV_CONTINUOUS,
  ADC_SG1_CONV_ONCE
};
/* END Msg(4:3218)-14 */
/*Array containing Scan group conversion status masks*/
STATIC CONST(uint32, ADC_CONST) Adc_GaaSGmConvStatusMask[ADC_THREE] =
{
  ADC_SG1_CONV_STATUS_MASK,
  ADC_SG2_CONV_STATUS_MASK,
  ADC_SG3_CONV_STATUS_MASK
};
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONST_ASIL_B_32
#else
  #define ADC_STOP_SEC_CONST_32
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Adc_HwInit
**
** Service ID           : NA
**
** Description          : This internal function performs the initialization
**                        of the ADC Driver hardware registers.
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
** Preconditions        : None
**
** Global Variables     : Adc_GpDmaUnitConfig, Adc_GucMaxDmaChannels,
**                        Adc_GpHwUnitConfig, Adc_GpLimitCheckRange,
**                        Adc_GpHwUnitRamData, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GpGroupConfig,
**                        Adc_GpHWGroupTrigg,
**                        Adc_GpSgUnitRamData, Adc_GucNoOfGroups,
**                        Adc_GucNoOfPwmDiagGroups.
**
** Functions invoked    : Adc_InitRamMirror, Adc_HaltADConversion
**
** Registers Used       : DCENm, DCSTCm, DTFRRQm, DTFRRQCm, DTFRm, ICQFULL,
**                        DTCTm, ADCAnPWDDIR, DSAm, DDAm, DRDAm, DRSAm,
**                        DTCm, DRTCm, ADCAnSFTCR, ADCAnADHALTR, DCSTm
**                        ADCAnADCR, ADCAnSMPCR, ADCAnSGMCYCRx, ADCAnPWDSGCR,
**                        PWSAnCTL, ICADCAnIm, ICDMAm, ICADCAnERR,
**                        ADCAnECR, ADCAnMPXSTBTSELR[0-4], PWSAnPVCRx_y,
**                        ADCAnTHACR, ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR,
**                        ADCAnDGCTL0, ADCAnDGCTL1, ADCAnPDCTL1, ADCAnPDCTL2,
**                        ADCAnULLMTBRx, ADCAnVCRj, ADCAnSGCRx, ADCAnSGVCSPx,
**                        ADCAnSGVCEPx, ADCAnSGTSELx, PWGAnCTDR, ADCAnTHCR,
**                        ADCAnMPXSTBTR[0-7], ADCAnSGSTR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_074 */
/* Implements ADC_ESDD_UD_001 */
/* Implements ADC_ESDD_UD_006 */
/* Implements ADC_ESDD_UD_011 */
/* Implements ADC_ESDD_UD_033 */
/* Implements ADC_ESDD_UD_035 */
/* Implements ADC_ESDD_UD_045 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwInit(void)
{
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  /* Defining a pointer to the SG Unit structure */
  /* Implements ADC_ESDD_UD_116 */
  P2CONST(Adc_HwSgUnitType, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitConfig;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  uint8_least LucDmaLoopCount;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA) LpPwmDiagResultRam;
  P2VAR(volatile uint16, AUTOMATIC, ADC_CONFIG_DATA) LpDmaIntpCntrlReg;
  #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA) LpPwmDiagDoubleResultRam;
  #endif
  uint16 LusMaxDiagRunTime;
  uint16 LusDiagLoopCount;
  #endif
  #endif
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  #if (ADC_NUMBER_OF_SG_UNITS != ADC_SG_ZERO)
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  #endif
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  #if (ADC_ENABLE_STREAMING == STD_ON)
  uint8 LucSGOffset;
  #endif
  #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  uint16 LusVariable;
  #endif
  #if ((ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) && \
                                            (ADC_DMA_MODE_ENABLE == STD_ON))
  uint8 LucHwUnit;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                         (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  uint8 LucMuxChnlCnt;
  uint8 LucMuxShiftVar;
  uint32 LulMuxShiftVal;
  uint8 LucTbrIndex;
  uint8 LucMuxSelReg;
  P2CONST(MuxDelayVal, ADC_VAR, ADC_CONFIG_CONST)LpMuxDelayVal;
  #endif
  uint8_least LucSgLoopCount;
  uint8_least LucNoOfHwSGUnit;
  uint8 LucNoHwTriggGroups;
  uint8_least LucLoopCount;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint32 LulRegWriteValue;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                           (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  uint32 LulMuxRegWriteValue;
  #endif
  #if (ADC_ENABLE_STREAMING == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;
  #endif

  #if ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
     (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE))
  Adc_InitRamMirror();
  #endif
  /*Initialise hardware mux stabilisation time*/
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  if (ADC_ZERO != Adc_GucMaxDmaChannels)
  {
    for (LucLoopCount = ADC_ZERO; (uint8_least)Adc_GucMaxDmaChannels >
                           LucLoopCount; LucLoopCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
      /* END Msg(4:0491)-5 */
      LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
      LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
      /* Clear the DTE bit to disable any ongoing DMA transfer and TC bit*/
      /* Clear DMA channel suspension */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DISABLE_DMA_TRANSFER);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDCEN,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCEN, ADC_HWINIT_API_ID);
      /* Clear Transfer Status flag */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCSTC, ADC_TRANSFER_FLAG_CLEAR);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDCST,
              ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCST_CLEAR, ADC_HWINIT_API_ID);
      /* Set transfer request clear register*/
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDTFRRQC,
                            ADC_DTFRRQC_REGISTER_VALUE);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTFRRQ,
                            ADC_DTFRRQ_DRQ_CLEAR_VALUE, ADC_WV_MASK_DTFRRQ,
                            ADC_HWINIT_API_ID);
      /* Load the trigger factor configured for the SGm unit */
      LulRegWriteValue =
                      (uint32)( LpSGmDmaConfig->usDmaDtfrRegValue) << ADC_ONE;
      /*Enable hardware trigger*/
      LulRegWriteValue |= ADC_DMA_TRNSFR_SRC_SEL_ENBL;
      /* Write value to the DTFR register */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDTFR, LulRegWriteValue);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTFR,
                    LulRegWriteValue, ADC_WV_MASK_DTFR, ADC_HWINIT_API_ID);
      /* END Msg(4:3138)-22 */
    }
    /* Implements AR_PN0076_FR_0103 */
    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    LucDmaLoopCount = ((uint8_least)Adc_GucMaxDmaChannels -
                                   (uint8_least)Adc_GucNoOfPwmDiagDmaChannels);
    #else
    LucDmaLoopCount = (uint8_least)Adc_GucMaxDmaChannels;
    #endif
    /* Initialize all the DMA channels */
    for (LucLoopCount = ADC_ZERO; LucDmaLoopCount > LucLoopCount;
                                                               LucLoopCount++)
    {
      /* Initialize the DMA channel pointer */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
      /* END Msg(4:0491)-5 */
      LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
      LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
      /* Load the transfer control register */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT, ADC_DMA_SETTINGS,
                    &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTCT,
                    ADC_DMA_SETTINGS, ADC_WV_MASK_DTCT, ADC_HWINIT_API_ID);
      /* END Msg(4:3138)-22 */
    }
    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    /* Initialize all the PWM Diagnostic DMA channels */
    for (LucLoopCount = LucDmaLoopCount; (uint8_least)Adc_GucMaxDmaChannels >
                           LucLoopCount; LucLoopCount++)
    {
      /* Initialize the DMA channel pointer */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
      /* END Msg(4:0491)-5 */
      /* Get the index of the HW unit to which this DMA channel is configured */
      LucHwUnit = LpSGmDmaConfig->ucHwUnitIndex;
      /* Initialize the local variable for HW unit configuration */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
      /* END Msg(4:0491)-5 */
      /* Get the HW unit index */
      LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
      LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
      /* Get the DMA channel index */
      LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
      LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
      /*
       * Disable the DMA interrupt for the DMA channel Id configured
       * for the SGm unit in which the group is mapped
       */
      /* MISRA Violation: START Msg(4:0317)-19 */
      LpDmaIntpCntrlReg = LpSGmDmaConfig->pIntCntlReg;
      /* END Msg(4:0317)-19 */
      /* MISRA Violation: START Msg(4:4397)-8 */
      /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0023 */
      /* Disable the DMA channel interrupt */
      RH850_SV_MODE_ICR_OR (16, (LpDmaIntpCntrlReg), ADC_INTERRUPT_MASK_DIS);
      /* END Msg(4:4397)-8 */
      /* Load the transfer control register */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT,
                        ADC_PWM_DMA_SETTINGS,
                        &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTCT,
                ADC_PWM_DMA_SETTINGS, ADC_WV_MASK_DTCT, ADC_HWINIT_API_ID);
      /*
       * Load the source address of ADCAnPWDDIR to the DMA channel
       * configured for SG4
       */
      /* MISRA Violation: START Msg(4:0303)-4 */
      LulRegWriteValue = (uint32)&(LpAdcRegisters->ulPWDDIR);
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDSA, LulRegWriteValue);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDSA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT, ADC_HWINIT_API_ID);
      /* END Msg(4:0303)-4 */
      /* END Msg(4:3138)-22 */
      /* Implements AR_PN0076_FR_0318 */
      #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
      /* If double buffering of DMA is enabled */
      if (ADC_TRUE == LpSGmDmaConfig->ucDmaDoubleBuffer)
      {
        /* MISRA Violation: START Msg(4:0306)-20 */
        /* Load the destination address (double buffer) */
        LulRegWriteValue = (uint32)LpHwUnitConfig->pPwmDiagDoubleResultRam;
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDDA, LulRegWriteValue);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT, ADC_HWINIT_API_ID);
        /* Load the destination address (double buffer) to reload register */
        LulRegWriteValue = (uint32)LpHwUnitConfig->pPwmDiagDoubleResultRam;
        ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRDA,
                            LulRegWriteValue,
                            &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRDA);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDRDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT, ADC_HWINIT_API_ID);
        /* END Msg(4:3138)-22 */
        /* END Msg(4:0306)-20 */
      }
      else
      #endif
      {
        /* MISRA Violation: START Msg(4:0306)-20 */
        /* Load the destination address */
        LulRegWriteValue = (uint32)LpHwUnitConfig->pPwmDiagResultRam;
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDDA, LulRegWriteValue);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT, ADC_HWINIT_API_ID);
        /* Load the destination address to reload register */
        LulRegWriteValue = (uint32)LpHwUnitConfig->pPwmDiagResultRam;
        ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRDA,
                            LulRegWriteValue,
                            &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRDA);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDRDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT, ADC_HWINIT_API_ID);
        /* END Msg(4:3138)-22 */
        /* END Msg(4:0306)-20 */
      }
      /* Load the transfer count value to the DMA register */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDTC,
                        LpHwUnitConfig->usMaxDiagRunTime);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTC,
                        LpHwUnitConfig->usMaxDiagRunTime, ADC_WV_MASK_ALL_32BIT,
                        ADC_HWINIT_API_ID);
      /* Load Reload transfer count register*/
      ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRTC,
                        LpHwUnitConfig->usMaxDiagRunTime,
                        &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRTC);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDRTC,
                        LpHwUnitConfig->usMaxDiagRunTime, ADC_WV_MASK_ALL_32BIT,
                        ADC_HWINIT_API_ID);
      /* DMA transfer enable */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DMA_ENABLE);
      ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDCEN,
                      ADC_DMA_ENABLE, ADC_WV_MASK_DCEN, ADC_HWINIT_API_ID);
      /* END Msg(4:3138)-22 */
    }
    #endif /* #if (ADC_DIAG_CHANNEL_SUPPORTED == STD_ON) */
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoopCount = ADC_ZERO; (uint8_least)ADC_MAX_HW_UNITS >
                           LucLoopCount; LucLoopCount++)
  /* END Msg(4:2877)-11 */
  {
    /* Initialize the local variable for HW unit configuration */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpHwUnitConfig = &Adc_GpHwUnitConfig[LucLoopCount];
    /* END Msg(4:0491)-5 */
    /* Read the hardware unit index */
    LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
    LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

    /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
    Adc_HaltADConversion(LucHwUnitIndex);
    /* Reset the registers to power on reset value */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulSFTCR, ADC_SFTCR_REG_RESET);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulSFTCR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SFTCR,
                        ADC_HWINIT_API_ID);
    /*
     * Set the HW unit register as per the configuration for self-diagnostic,
     * Alignment control, resolution and suspend mode.
     */
     /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                        LpHwUnitConfig->ulHwUnitSettings,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulADCR,
                        LpHwUnitConfig->ulHwUnitSettings, ADC_WV_MASK_ADCR,
                        ADC_HWINIT_API_ID);
    /* Implements AR_PN0076_FR_0219 */
    /* Set the configured sampling time for the HW unit */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulSMPCR,
                        LpHwUnitConfig->ulHwSamplingTime,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulSMPCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulSMPCR,
                        LpHwUnitConfig->ulHwSamplingTime, ADC_WV_MASK_SMPCR,
                        ADC_HWINIT_API_ID);
    /*
    * Update ADCAnECR register to clear the error flags
    */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

    /* END Msg(4:3138)-22 */
    /* Get the number of SG units configured for this HW unit */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LucNoOfHwSGUnit = Adc_GpHwUnitConfig[LucLoopCount].ucSgUnitCount;
    /* END Msg(4:0491)-5 */
    for (LucSgLoopCount = ADC_ZERO;
            (uint8_least)LucNoOfHwSGUnit > LucSgLoopCount; LucSgLoopCount++)
    {
      /* Disable the interrupt for SGm unit to which the group is mapped */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgLoopCount];
      /* END Msg(4:0491)-5 */
      /* MISRA Violation: START Msg(4:4397)-8 */
      RH850_SV_MODE_ICR_OR (16, (LpSgUnitConfig->pIcrIntpAddress),
                                                      ADC_INTERRUPT_MASK_DIS);
      /* END Msg(4:4397)-8 */
    }
    #if (ADC_ENABLE_STREAMING == STD_ON)
    /* Read the SG offset */
    LucSGOffset = LpHwUnitConfig->ucSGOffset;
    /* Set Streaming samples selection bits as zero */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGMCYCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR, ADC_HWINIT_API_ID);
    /* END Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGMCYCR;
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR, ADC_HWINIT_API_ID);
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGMCYCR;
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR, ADC_HWINIT_API_ID);
    /* END Msg(4:3138)-22 */
    #endif

    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    /* Enable the PWM diagnostic group */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulPWDSGCR, ADC_ENABLE_PWM_DIAG_TRIGG);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulPWDSGCR,
                               ADC_ENABLE_PWM_DIAG_TRIGG, ADC_WV_MASK_PWDSGCR,
                               ADC_HWINIT_API_ID);
    /* END Msg(4:3138)-22 */
    #endif

    #if ((ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) && \
                                            (ADC_DMA_MODE_ENABLE == STD_ON))
    /* MISRA Violation: START Msg(4:0317)-19 */
    LpPwmDiagResultRam = LpHwUnitConfig->pPwmDiagResultRam;
    /* END Msg(4:0317)-19 */
    LusMaxDiagRunTime = LpHwUnitConfig->usMaxDiagRunTime;
    /* Make all the PWM result array to zero */
    for (LusDiagLoopCount = ADC_ZERO; LusMaxDiagRunTime > LusDiagLoopCount;
                                                            LusDiagLoopCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpPwmDiagResultRam[LusDiagLoopCount] = ADC_DOUBLE_WORD_ZERO;
      /* END Msg(4:0491)-5 */
    }
    /* Implements AR_PN0076_FR_0318 */
    #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
    /* MISRA Violation: START Msg(4:0317)-19 */
    LpPwmDiagDoubleResultRam = LpHwUnitConfig->pPwmDiagDoubleResultRam;
    /* END Msg(4:0317)-19 */
     /* Make all the PWM result array to zero */
    for (LusDiagLoopCount = ADC_ZERO; LusMaxDiagRunTime > LusDiagLoopCount;
                                                            LusDiagLoopCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpPwmDiagDoubleResultRam[LusDiagLoopCount] = ADC_DOUBLE_WORD_ZERO;
      /* END Msg(4:0491)-5 */
    }
    #endif
    #endif /* #if ((ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) && \
                                           (ADC_DMA_MODE_ENABLE == STD_ON)) */
    #if (ADC_ERROR_SUPPORT == STD_ON)
    /* Enable the HW Unit Error interrupt in case enabled in configuration */
    if (ADC_TRUE == LpHwUnitConfig->blInterruptErr)
    {
      RH850_SV_MODE_ICR_AND (16, (LpHwUnitConfig->pIntErrAddress),
                                                      ADC_INTERRUPT_MASK_EN);
      /* Set the Safety control registers */
     /* Implements SWS_Adc_00281, AR_PN0076_FSR_0003 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulSFTCR,
                      LpHwUnitConfig->ulErrorEnableValue);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulSFTCR,
                      LpHwUnitConfig->ulErrorEnableValue, ADC_WV_MASK_SFTCR,
                      ADC_HWINIT_API_ID);
     /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No action required */
    }
    #endif/* #if (ADC_ERROR_SUPPORT == STD_ON) */
  }
  #if (ADC_NUMBER_OF_SG_UNITS != ADC_SG_ZERO)
  /* Make all the SG unit RAM variable reset */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoopCount = ADC_ZERO; (uint8_least)ADC_NUMBER_OF_SG_UNITS >
                  LucLoopCount; LucLoopCount++)
  /* END Msg(4:2877)-11 */
  {
    /* Get the pointer to SG unit RAM data */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpSgUnitData = &Adc_GpSgUnitRamData[LucLoopCount];
    /* END Msg(4:0491)-5 */
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
    ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                       (ADC_ENABLE_QUEUING == STD_ON)))
    /* Initialize queue */
    LpSgUnitData->ucQueueStatus = ADC_QUEUE_EMPTY;
    LpSgUnitData->ucQueueCounter = ADC_ZERO;
    #endif
    LpSgUnitData->blSgUnitStatus = ADC_FALSE;
    LpSgUnitData->ddCurrentConvGroup = ADC_CURRENT_CONV_GROUP_INIT;
  }
  #endif

  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  if ( Adc_GucNoOfGroups > Adc_GucNoOfPwmDiagGroups )
  {
    /* Get the number of SW and HW trigger groups configured in configuration */
    LucNoHwTriggGroups = Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups;
  }
  else
  {
    /* Get the number of SW and HW trigger groups configured in configuration */
    LucNoHwTriggGroups = Adc_GucNoOfGroups;
  }
  #else
  /* Get the number of SW and HW trigger groups configured in configuration */
  LucNoHwTriggGroups = Adc_GucNoOfGroups;
  #endif
  for (LucLoopCount = ADC_ZERO; (uint8_least)LucNoHwTriggGroups >
                               LucLoopCount; LucLoopCount++)
  {
    /* Get the pointer to Group configuration */
    /* Initialize the local pointer to group RAM data */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpGroupData = &Adc_GpGroupRamData[LucLoopCount];
    /* END Msg(4:0491)-5 */
    /* Implements SWS_Adc_00307, ADC307 */
    /* Initialize all the groups as idle */
    LpGroupData->enGroupStatus = ADC_IDLE;
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Disable notifications */
    LpGroupData->ucNotifyStatus = ADC_FALSE;
    #endif
    #if ((ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF) && \
                                      (ADC_DEV_ERROR_DETECT == STD_ON))
    /* Disable buffer address initialization */
    LpGroupData->ucBufferStatus = ADC_FALSE;
    #endif
    #if (ADC_HW_TRIGGER_API == STD_ON)
    /* Implements SWS_Adc_00077, ADC077 */
    /* Disable hardware trigger status */
    LpGroupData->ucHwTriggStatus = ADC_FALSE;
    #endif

    #if (((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) || \
                        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                              (ADC_ENABLE_QUEUING == STD_ON)))
    /* Initialize the channels completed to zero */
    LpGroupData->ucReChannelsCompleted = ADC_ZERO;
    /* Initialize the samples completed to zero */
    LpGroupData->ucReSamplesCompleted = ADC_ZERO;
    #endif

    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
         ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                         (ADC_ENABLE_QUEUING == STD_ON)))
    /* Clear the flag indicating no group is present in queue */
    LpGroupData->ucGrpPresent = ADC_FALSE;
    #endif
    /* Clear the flag indicating result data is not read */
    LpGroupData->blResultRead = ADC_FALSE;
    #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
    /* Set no of channels disabled during initialization as zero */
    LpGroupData->ucNoofChDisabled = ADC_ZERO;
    #endif
  }
  #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
  LusVariable = ADC_ZERO;
  /* Get the pointer to the first configured group */
  LpGroupData = &Adc_GpGroupRamData[ADC_ZERO];
  /* Get the pointer to the first RAM allocated Result buffer */
  LpGroupData->pChannelBuffer = &Adc_GpResultGroupRamData[ADC_ZERO];
  for (LucLoopCount = ADC_ONE; (uint8_least)LucNoHwTriggGroups > LucLoopCount;
                                                                 LucLoopCount++)
  {
    /* Get the pointer to the previous group configuration */
    LpGroup = &Adc_GpGroupConfig[LucLoopCount - ADC_ONE];
    /* Get the pointer to the next configured group index */
    LusVariable = LusVariable +
                         (LpGroup->ucChannelCount * LpGroup->ddNumberofSamples);
    /* Initialize the group result buffer pointer with the address passed */
    LpGroupData[LucLoopCount].pChannelBuffer =
                                         &Adc_GpResultGroupRamData[LusVariable];
  }
  #endif
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  if ( NULL_PTR != Adc_GpPwmGroupData)
  {
    /* Start PWSA Operation */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&Adc_GaaPWSAReg_BaseAddress->ucCTL, ADC_PWM_START_PWSA);
    ADC_PWMDIAG_CHECK_WRITE_VERIFY_INIT(&Adc_GaaPWSAReg_BaseAddress->ucCTL,
                  ADC_PWM_START_PWSA, ADC_WV_MASK_PWSA_CTL, ADC_HWINIT_API_ID);
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No action required */
  }
  /* Implements ADC_ESDD_UD_153 */
  /* Implements ADC_ESDD_UD_160 */
  #if (ADC_PWSA_INT_QFULL_ISR == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-4 */
  /* Enable PWSA queue full interrupt */
  RH850_SV_MODE_ICR_AND (16, ADC_ICREG_ADDRESS_QFULL, ADC_INTERRUPT_MASK_EN);
  /* END Msg(4:0303)-4 */
  #endif
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                           (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  /* Implements AR_PN0076_FR_0210, EAAR_PN0034_FR_0023  */
  /*Loop through the structure for mux enabled channels*/
  for (LucMuxChnlCnt = Adc_GucMuxStartChannel;
                            LucMuxChnlCnt < Adc_GucMuxChnlCnt; LucMuxChnlCnt++)
  {
    /* MISRA Violation: START Msg(4:0491)-5 */
    /*Initialise pointer to Mux delay structure*/
    LpMuxDelayVal = &Adc_GpMuxDelayVal[LucMuxChnlCnt];
    /* END Msg(4:0491)-5 */
    /*Only HW unit 1 supports Mux*/
    LpAdcRegisters = Adc_GaaConfReg_BaseAddress[ADC_ZERO];
    LucTbrIndex = LpMuxDelayVal->uctbrindex;
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulMPXSTBTR[LucTbrIndex],
                                        LpMuxDelayVal->usHWDelayCounter);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulMPXSTBTR[LucTbrIndex],
    LpMuxDelayVal->usHWDelayCounter, ADC_WV_MASK_MPXSTBTR, ADC_HWINIT_API_ID);
    /* END Msg(4:3138)-22 */
    LucMuxShiftVar = LpMuxDelayVal->ucMuxOffset;
    LulMuxShiftVal = (uint32)LucTbrIndex;
    LulMuxShiftVal = LulMuxShiftVal << LucMuxShiftVar;
    LucMuxSelReg   = LpMuxDelayVal->ucMuxSelReg;
    LulMuxRegWriteValue  = LpAdcRegisters->ulMPXSTBTSELR[LucMuxSelReg];
    LulMuxRegWriteValue |= (LulMuxShiftVal & LpMuxDelayVal->ulMuxSelMask);
    /*Choosing the mux stabilisation time Selection register*/
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulMPXSTBTSELR[LucMuxSelReg],
                                                          LulMuxRegWriteValue);
    ADC_ADCA_CHECK_WRITE_VERIFY_INIT(
    &LpAdcRegisters->ulMPXSTBTSELR[LucMuxSelReg],LulMuxRegWriteValue,
    ADC_WV_MASK_MPXSTBT_SELR, ADC_HWINIT_API_ID);
    /* END Msg(4:3138)-22 */
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
** Function Name        : Adc_HwDeInit
**
** Service ID           : NA
**
** Description          : This internal function performs the deinitialization
**                        of the ADC Driver global variables and registers.
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
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GpGroupRamData,
**                        Adc_GpDmaUnitConfig, Adc_GucNoOfGroups
**                        Adc_GucMaxDmaChannels, Adc_GucNoOfPwmDiagGroups,
**                        Adc_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Adc_HaltADConversion
**
** Registers Used       : ADCAnSGSTR, ADCAnSFTCR, ADCAnADHALTR, ADCAnSGMCYCRx,
**                        ADCAnPWDSGCR, ADCAnVCRj, DCENm, DCSTCm, DTCTm,
**                        PWSAnCTL, ICADCAnIm, ICADCAnERR, ADCAnECR,
**                        ADCAnMPXSTBTSELR[0-4], DCSTm, ADCAnMPXSTBTR[0-7]
*******************************************************************************/
#if (ADC_DEINIT_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_075 */
/* Implements ADC_ESDD_UD_001 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwDeInit(void)
{
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  /* Defining a pointer to the SG Unit structure */
  P2CONST(Adc_HwSgUnitType, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitConfig;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  #endif
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcVirChannel;
  uint8 LucSGOffset;
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                          (ADC_HW_MUX_STAB_SUPPORT == STD_ON))
  uint8 LucMuxChnlCnt;
  uint8 LucTbrIndex;
  uint8 LucMuxSelReg;
  P2CONST(MuxDelayVal, ADC_VAR, ADC_CONFIG_CONST)LpMuxDelayVal;
  #endif
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  uint8 LucNoHwTriggGroups;
  uint8 LucVirChannelCountLoop;
  uint8 LucVirChannelCount;
  /* Local variable for loop count */
  uint8_least LucLoopCount;
  uint8_least LucSgLoopCount;
  uint8_least LucNoOfHwSGUnit;
  uint32 LulRegWriteValue;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Initialize the loop count value to zero */
  LucLoopCount = ADC_ZERO;
  do
  {
    /* MISRA Violation: START Msg(4:0491)-5 */
    /* Read the hardware unit index */
    LucHwUnitIndex = Adc_GpHwUnitConfig[LucLoopCount].ucHwUnit;
    LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
    /* END Msg(4:0491)-5 */
    /* Check if the requested hardware unit is busy */
    if (ADC_NOT_BUSY != (LpAdcRegisters->ulSGSTR & ADC_HW_UNIT_STATUS))
    {
      /* Report Error to DET */
      /* Implements SWS_Adc_00112, ADC112 */

      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                                  ADC_DEINIT_SID, ADC_E_BUSY);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }

    /* Increment the loop count to next HW Unit */
    /* MISRA Violation: START Msg(4:2984)-15 */
    LucLoopCount++;
    /* END Msg(4:2984)-15 */
    /* MISRA Violation: START Msg(4:2996)-16 */
    /* MISRA Violation: START Msg(4:2993)-17 */
  }while (((uint8_least)ADC_MAX_HW_UNITS > LucLoopCount) &&
                                         (E_OK != LenDetErrFlag));
  /* END Msg(4:2996)-16 */
  /* END Msg(4:2993)-17 */

  if (E_NOT_OK == LenDetErrFlag)
  #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Set ADC driver as Uninitialized */
    Adc_GblDriverStatus = ADC_UNINITIALIZED;
    #endif

    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoopCount = ADC_ZERO; (uint8_least)ADC_MAX_HW_UNITS >
                             LucLoopCount; LucLoopCount++)
    /* END Msg(4:2877)-11 */
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpHwUnitConfig = &Adc_GpHwUnitConfig[LucLoopCount];
      /* END Msg(4:0491)-5 */
      /* Read the hardware unit index */
      /* MISRA Violation: START Msg(2:2814)-27 */
      LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
      /* END Msg(2:2814)-27 */
      LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

      /* Read the SG offset */
      LucSGOffset = LpHwUnitConfig->ucSGOffset;

      /* Set TRGMD of all scan groups to 0 */
      /* MISRA Violation: START Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:2814)-27 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
      /* END Msg(2:2814)-27 */
      /* END Msg(4:2985)-10 */
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                    LulRegWriteValue, ADC_WV_MASK_SGCR,
                    ADC_HWDEINIT_API_ID);

      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                    LulRegWriteValue, ADC_WV_MASK_SGCR,
                    ADC_HWDEINIT_API_ID);

      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                    LulRegWriteValue, ADC_WV_MASK_SGCR,
                    ADC_HWDEINIT_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
      /* 
       * Set SCACT of all scan grops to 0 by
       * writing the register ADCAnADHALTR
       */
      Adc_HaltADConversion(LucHwUnitIndex);

      /* Reset the registers to power on reset value */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulSFTCR, ADC_SFTCR_REG_RESET);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulSFTCR,
                                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SFTCR,
                                ADC_HWDEINIT_API_ID);
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
      /*
       * Update ADCAnECR register to clear the error flags
       */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);
      /* END Msg(2:3109)-24 */
      /* END Msg(4:3138)-22 */

      #if (ADC_ENABLE_STREAMING == STD_ON)
      /* Read the SG offset */
      LucSGOffset = LpHwUnitConfig->ucSGOffset;
      /* Set Streaming samples selection bits as zero */
      /* MISRA Violation: START Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGMCYCR;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                            ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR,
                            ADC_HWDEINIT_API_ID);
      /* END Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGMCYCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                            ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR,
                            ADC_HWDEINIT_API_ID);
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGMCYCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_SINGLE_CYCLE_SCAN);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(LpRegWrite,
                            ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGMCYCR,
                            ADC_HWDEINIT_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3109)-24 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
      #endif

      #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
      /* Disable the PWM diagnostic group */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulPWDSGCR,
                             ADC_DISABLE_PWM_DIAG_TRIGG);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulPWDSGCR,
                             ADC_DISABLE_PWM_DIAG_TRIGG, ADC_WV_MASK_PWDSGCR,
                             ADC_HWDEINIT_API_ID);
      /* END Msg(4:3138)-22 */
      #endif

      /* Get the number of SG units configured for this HW unit */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LucNoOfHwSGUnit = Adc_GpHwUnitConfig[LucLoopCount].ucSgUnitCount;
      /* END Msg(4:0491)-5 */
      for (LucSgLoopCount = ADC_ZERO;
              (uint8_least)LucNoOfHwSGUnit > LucSgLoopCount; LucSgLoopCount++)
      {
        /* Disable the interrupt for SGm unit to which the group is mapped */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgLoopCount];
        /* END Msg(4:0491)-10 */
        /* Implements SWS_Adc_00111, ADC111, EAAR_PN0034_FR_0067 */
        /* MISRA Violation: START Msg(4:4397)-8 */
        RH850_SV_MODE_ICR_OR (16, (LpSgUnitConfig->pIcrIntpAddress),
                                                       ADC_INTERRUPT_MASK_DIS);
        /* END Msg(4:4397)-8 */
      }
      #if (ADC_ERROR_SUPPORT == STD_ON)
      /* Disable the HW Unit Error interrupt in case enabled in configuration */
      if (ADC_TRUE == LpHwUnitConfig->blInterruptErr)
      {
        /* MISRA Violation: START Msg(4:4397)-8 */
        RH850_SV_MODE_ICR_OR (16, (LpHwUnitConfig->pIntErrAddress),
                                                     ADC_INTERRUPT_MASK_DIS);
        /* END Msg(4:4397)-8 */
      }
      else
      {
        /* No action required */
      }
      #endif/* #if (ADC_ERROR_SUPPORT == STD_ON) */

      /* Get the number of channels configured for this HW unit */
      LucVirChannelCount = LpHwUnitConfig->ucVirChannelCount;
      LpAdcVirChannel = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
      for (LucVirChannelCountLoop = ADC_ZERO; LucVirChannelCount >
                              LucVirChannelCountLoop; LucVirChannelCountLoop++)
      {
        /* Clear the virtual channels register */
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_ADCA_WRITE_REG_AND_MIRROR(
        &LpAdcVirChannel->ulVCR[LucVirChannelCountLoop], ADC_CLEAR_VIRTUAL_CHNL,
        &Adc_GaaRamMirrorAdcVirChReg[LucHwUnitIndex].
              ulVCR[LucVirChannelCountLoop]);
        ADC_ADCA_CHECK_WRITE_VERIFY_INIT(
              &LpAdcVirChannel->ulVCR[LucVirChannelCountLoop], ADC_WORD_ZERO,
              ADC_WV_MASK_VCR, ADC_HWDEINIT_API_ID);
        /* END Msg(4:3138)-22 */
      }
    }
    /* Implements AR_PN0076_FR_0103 */
    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    if ( Adc_GucNoOfGroups > Adc_GucNoOfPwmDiagGroups )
    {
     /* Get the number of SW and HW trigger groups configured in configuration*/
      LucNoHwTriggGroups = Adc_GucNoOfGroups - Adc_GucNoOfPwmDiagGroups;
    }
    else
    {
    /* Get the number of SW and HW trigger groups configured in configuration */
      LucNoHwTriggGroups = Adc_GucNoOfGroups;
    }
    #else
    /* Get the number of SW and HW trigger groups configured in configuration */
    LucNoHwTriggGroups = Adc_GucNoOfGroups;
    #endif
    for (LucLoopCount = ADC_ZERO; (uint8_least) LucNoHwTriggGroups >
                              LucLoopCount; LucLoopCount++)
    {
      /* Set group status as idle */
      /* MISRA Violation: START Msg(4:0491)-5 */
      Adc_GpGroupRamData[LucLoopCount].enGroupStatus = ADC_IDLE;
      /* END Msg(4:0491)-5 */
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Disable notifications */
      /* MISRA Violation: START Msg(4:0491)-5 */
      Adc_GpGroupRamData[LucLoopCount].ucNotifyStatus = ADC_FALSE;
      /* END Msg(4:0491)-5 */
      #endif
    }

    #if (ADC_DMA_MODE_ENABLE == STD_ON)
    if (ADC_ZERO != Adc_GucMaxDmaChannels)
    {
      for (LucLoopCount = ADC_ZERO; (uint8_least)Adc_GucMaxDmaChannels >
                           LucLoopCount; LucLoopCount++)
      {
        /* Get the pointer to DMA configuration */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
        /* END Msg(4:0491)-5 */
        LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
        LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
        /* Clear the TC and DTE bit */
        /* Clear DMA channel suspension */
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DISABLE_DMA_TRANSFER);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDCEN,
                                    ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCEN,
                                    ADC_HWDEINIT_API_ID);
        /* Clear Transfer Status flag */
        ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCSTC, ADC_TRANSFER_FLAG_CLEAR);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDCST,
                                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCST_CLEAR,
                                  ADC_HWDEINIT_API_ID);
        /* Clear the DMA transfer control register*/
        ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT,
        ADC_DMA_CTL_REG_CLEAR, &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
        ADC_DMAC_CHECK_WRITE_VERIFY_INIT(&LpDmaRegisters->ulDTCT,
                          ADC_WORD_ZERO, ADC_WV_MASK_DTCT,
                          ADC_HWDEINIT_API_ID);
        /* END Msg(4:3138)-22 */
      }
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    /* Stop PWSA Operation */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&Adc_GaaPWSAReg_BaseAddress->ucCTL, ADC_PWM_RST_PWSA);
    ADC_PWMDIAG_CHECK_WRITE_VERIFY_INIT(&Adc_GaaPWSAReg_BaseAddress->ucCTL,
                  ADC_PWM_RST_PWSA, ADC_WV_MASK_PWSA_CTL, ADC_HWDEINIT_API_ID);
    /* END Msg(4:3138)-22 */
    #endif
    /*Initialise hardware mux stabilisation time*/
    #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                           (ADC_HW_MUX_STAB_SUPPORT == STD_ON))

    /*Loop through the structure for mux enabled channels*/
    for (LucMuxChnlCnt = Adc_GucMuxStartChannel;
                           LucMuxChnlCnt < Adc_GucMuxChnlCnt;  LucMuxChnlCnt++)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      /*Initialise pointer to Mux delay structure*/
      LpMuxDelayVal = &Adc_GpMuxDelayVal[LucMuxChnlCnt];
      /* END Msg(4:0491)-5 */
      /*Only HW unit 1 supports Mux*/
      LpAdcRegisters = Adc_GaaConfReg_BaseAddress[ADC_ZERO];
      LucTbrIndex = LpMuxDelayVal->uctbrindex;
      LucMuxSelReg   = LpMuxDelayVal->ucMuxSelReg;
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulMPXSTBTR[LucTbrIndex],
                                          ADC_DOUBLE_WORD_ZERO);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(&LpAdcRegisters->ulMPXSTBTR[LucTbrIndex],
      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_MPXSTBTR, ADC_HWDEINIT_API_ID);

      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulMPXSTBTSELR[LucMuxSelReg],
                                                          ADC_DOUBLE_WORD_ZERO);
      ADC_ADCA_CHECK_WRITE_VERIFY_INIT(
      &LpAdcRegisters->ulMPXSTBTSELR[LucMuxSelReg], ADC_DOUBLE_WORD_ZERO,
      ADC_WV_MASK_MPXSTBT_SELR, ADC_HWDEINIT_API_ID);
      /* END Msg(4:3138)-22 */
    }
    #endif
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

#endif /* #if (ADC_DEINIT_API == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_HwStartGroupConversion
**
** Service ID           : NA
**
** Description          : This internal function shall start the conversion of
**                        all channels of the requested ADC Channel group.
**                        Depending on the group configuration single-shot or
**                        continuous conversion is started.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GaaSGmConvStatusMask
**                        Adc_GpGroupRamData, Adc_GpHwUnitRamData,
**                        Adc_GpGroupConfig, Adc_GpRunTimeData
**
** Functions invoked    : Det_ReportError, Adc_DisableHWGroup,
**                        Adc_ConfigureGroupForConversion, Adc_PushToQueue,
**                        ADC_ENTER_CRITICAL_SECTION,Adc_StopScanGroup
**                        ADC_EXIT_CRITICAL_SECTION, Adc_HaltScanGroup
**
** Registers Used       : ADCAnSGCRx, ADCAnSGTSELx, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnADCR, ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR,
**                        ADCAnTHACR, ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER,
**                        ADCAnTHCR, ICADCAnIm, ADCAnSGSTR, ADCAnSGSTPCRx,
**                        ADCAnSGSTR, ADCAnADHALTR, ADCAnSGSTCRx, ADCAnECR,
**                        ADCAnULLMTBRx,DCENm, DCSTCm, DRSAm, DDAm, DTCm,
**                        DRDAm, DRTCm, DSAm, DTCTm,  ICDMAm, ADCAnSGVCSPx,
**                        ADCAnVCRj, ADCAnSGVCEPx, DCSTm
*******************************************************************************/
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_076 */
/* Implements ADC_ESDD_UD_001 */
/* Implements AR_PN0076_FR_0228 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwStartGroupConversion(Adc_GroupType Group)
{
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  #endif
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #if (((ADC_DEV_ERROR_DETECT == STD_ON) || \
     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_ON)))
  /* Local variable to store the current conversion group ID */
  Adc_GroupType LddCurrentGroup;
  #endif
  /* Local variable to store the hardware unit number */
  uint8 LucHwUnit;

  uint8 LucSgUnitIndex;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  uint8 LucSgUnitId;

  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = Adc_GpGroupConfig[Group].ucSgUnitIndex;
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(4:0491)-5 */
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = Adc_GpGroupConfig[Group].ucHwUnitIndex;
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */

  #if (((ADC_DEV_ERROR_DETECT == STD_ON) || \
     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_ON)))
  /* Get the current group under conversion */
  LddCurrentGroup = LpSgUnitData->ddCurrentConvGroup;
  #endif
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((Group == LddCurrentGroup) &&
      (ADC_IDLE != Adc_GpGroupRamData[Group].enGroupStatus) &&
      (ADC_GROUP_CONTINUOUS ==(Adc_GpGroupConfig[Group].ucGroupSettings
                                                     & ADC_GROUP_CONV_MASK)))
  /* END Msg(4:0491)-5 */
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                               ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((Group == LddCurrentGroup) &&
      (ADC_IDLE != Adc_GpGroupRamData[Group].enGroupStatus) &&
      (ADC_STREAM_COMPLETED != Adc_GpGroupRamData[Group].enGroupStatus) &&
      (ADC_GROUP_ONCE == (Adc_GpGroupConfig[Group].ucGroupSettings
                                                  & ADC_GROUP_CONV_MASK)))
  /* END Msg(4:0491)-5 */
  {
    /* Report Error to DET */
    /* Implements AR_PN0076_FR_0014 */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
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
    /* MISRA Violation: START Msg(4:0491)-5 */
    /* Initialize the local variable for HW unit configuration */
    LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
    /* END Msg(4:0491)-5 */
    /* Read the hardware unit index */
    LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
    LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

    /* Check if Group Priority and queue are disabled */
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_OFF))
    /* Implements AR_PN0076_FR_0050, AR_PN0076_FR_0249 */
    /* Check if the requested SG1 of HW is busy */
    if ((ADC_NOT_BUSY != (LpAdcRegisters->ulSGSTR &
                        Adc_GaaSGmConvStatusMask[LucSgUnitId])) ||
                             (ADC_TRUE == LpSgUnitData->blSgUnitStatus))
    {
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
      #endif
    }
    else /* Hardware Unit is not busy. Conversion can be taken up */
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Group);
    }
    /* Group Priority is enabled */
    /* Implements AR_PN0076_FR_0008, AR_PN0076_FR_0249 */
    #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
    /* Implements AR_PN0076_FR_0044, AR_PN0076_FR_0045 */
    /* Check if the requested hardware unit is busy */
    if ((ADC_NOT_BUSY != (LpAdcRegisters->ulSGSTR &
                        Adc_GaaSGmConvStatusMask[LucSgUnitId])) ||
              (ADC_TRUE == LpSgUnitData->blSgUnitStatus))
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      /* IF the current group priority is less than requested */
      if (Adc_GpGroupConfig[Group].ddGroupPriority >
                                         LpSgUnitData->ddCurrentPriority)
      /* END Msg(4:0491)-5 */
      {
        /* Fetch the group id of the current conversion group */
        LddCurrentGroup = LpSgUnitData->ddCurrentConvGroup;
        #if ((ADC_HW_TRIGGER_API == STD_ON))
        /* Check if the ongoing lower priority group is HW triggered */
        if (ADC_TRIGG_SRC_HW == LpSgUnitData->enTrigSource)
        {
          /* Disable the lower ongoing HW triggered group */
          Adc_DisableHWGroup(LddCurrentGroup);
          /* Set the SG unit status to busy */
          LpSgUnitData->blSgUnitStatus = ADC_TRUE;
          /* Start conversion of requested higher SW triggered group */
          Adc_ConfigureGroupForConversion(Group);
        }
        else
        #endif
        {
          /* Check if the queue is full */
          if ((ADC_QUEUE_FULL != LpSgUnitData->ucQueueStatus) &&
                              (Group != LddCurrentGroup))
          {
            /* Get the SG register index */
            /* MISRA Violation: START Msg(4:0491)-5 */
            LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
            /* END Msg(4:0491)-5 */
            LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
            /*
             * Stop conversion of SG unit in which requested group is mapped
             * by changing mode to Multicycle scan mode and no of scan as one
             */
            /* Clear the operation mode configured previously */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR,
                    ADC_CLR_SCAN_GRP_CTL_REG,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                    ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGCR,
                    ADC_HWSTARTGROUPCONVERSION_API_ID);
            /* END Msg(4:3138)-22 */
           #if (ADC_HARD_STOP == STD_OFF)
            /* Stop the conversion of all the SG unit */
            Adc_HaltScanGroup(Group);
            #elif (ADC_HARD_STOP == STD_ON)
             /*
               Stop the conversion of all the SG unit using
               ADCAnSGSTPCRx register.
             */
            Adc_StopScanGroup(Group);
            #endif
            /* Push the current conversion group into queue */
            Adc_PushToQueue(LddCurrentGroup);
            /* Get the runtime data pointer */
            /* MISRA Violation: START Msg(4:0491)-5 */
            LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
            /*
             * Check if the group as to be resumed from where it had stopped
             * before
             */
            /* Load the number of channels converted before suspension */
            Adc_GpGroupRamData[LddCurrentGroup].ucReChannelsCompleted =
                       LpRunTimeData->ucChannelsCompleted;
            /*
             * Load the number of samples converted before aborting or
             * suspension
             */
            Adc_GpGroupRamData[LddCurrentGroup].ucReSamplesCompleted =
                                 LpRunTimeData->ucSamplesCompleted;
            /* END Msg(4:0491)-5 */
            /* Set the SG unit status to busy */
            LpSgUnitData->blSgUnitStatus = ADC_TRUE;
            /* Configure the requested group for conversion */
            Adc_ConfigureGroupForConversion(Group);
          }
          #if (ADC_DEV_ERROR_DETECT == STD_ON)
          else
          {
            /* Implements AR_PN0076_FR_0014 */
            /* Report Error to DET */
            (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
          }
          #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
        }
      }
      else if ((ADC_QUEUE_FULL != LpSgUnitData->ucQueueStatus) &&
                         (Group != LddCurrentGroup))
      {
        /*
         * Push the requested group to queue if its priority is less
         * than the current conversion group.
         */
        Adc_PushToQueue(Group);
      }
      else
      {
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Implements AR_PN0076_FR_0014 */
        /* Report Error to DET */
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);

        #endif /* #if (ADC_DEV_ERROR_DETECT == ON) */
      }
    }
    else /* First group requested for conversion */
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      /* Configure the requested group for conversion */
      Adc_ConfigureGroupForConversion(Group);
    }
    /* Implements AR_PN0076_FR_0008, AR_PN0076_FR_0059 */
    /* Implements AR_PN0076_FR_0249 */
    #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)
    /*
     * Check if the requested corresponding SGm unit to which group is mapped
     * is busy
     */
    if ((ADC_NOT_BUSY == (LpAdcRegisters->ulSGSTR &
                            Adc_GaaSGmConvStatusMask[LucSgUnitId])) &&
                                (ADC_FALSE == LpSgUnitData->blSgUnitStatus))
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      /* Configure the requested group for conversion */
      Adc_ConfigureGroupForConversion(Group);
    }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
    }
    #endif /* #if (ADC_DEV_ERROR_DETECT == ON) */

    #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_ON))
    /* Implements AR_PN0076_FR_0050, AR_PN0076_FR_0249 */
    /* Implements SWS_Adc_00338, ADC338 */
    /* Check if the requested hardware unit is busy */
    if ((ADC_NOT_BUSY != (LpAdcRegisters->ulSGSTR &
                            Adc_GaaSGmConvStatusMask[LucSgUnitId])) ||
                                 (ADC_TRUE == LpSgUnitData->blSgUnitStatus))
    {
      /*
       * Push the requested group into the first come first serve mechanism
       * queue
       */
      if ((ADC_QUEUE_FULL != LpSgUnitData->ucQueueStatus)  &&
                                            (Group != LddCurrentGroup))
      {
        Adc_PushToQueue(Group);
      }
      else
      {
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Report Error to DET */
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
        #endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
      }
    }
    else /* Hardware unit is not busy. Conversion can be taken up */
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Group);
    }
    #endif /*
            * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
            *                              (ADC_ENABLE_QUEUING == STD_OFF))
            */

  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
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
** Function Name        : Adc_HwStopGroupConversion
**
** Service ID           : NA
**
** Description          : This internal function shall stop conversion of the
**                        requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig,
**                        Adc_GpHwUnitConfig, Adc_GpGroupRamData,
**                        Adc_GpHwUnitRamData
**
** Functions invoked    : Adc_ConfigureGroupForConversion,
**                        Adc_SearchnDelete, Adc_PopFromQueue,
**                        Adc_HaltScanGroup, Adc_ClearPendingInterrupt,
**                        ADC_ENTER_CRITICAL_SECTION, ADC_EXIT_CRITICAL_SECTION,
**                        Adc_StopScanGroup, Adc_HaltADConversion
**
** Registers Used       : ADCAnSGCRx, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnADCR,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER, ADCAnTHCR
**                        ADCAnECR, ADCAnULLMTBRx, DCENm, DCSTCm, DDAm, DTCm,
**                        DRSAm, DRDAm, DRTCm, DSAm, DTCTm, ICDMAm
**                        ADCAnVCRj, ADCAnSGVCEPx, ADCAnSGVCSPx, ADCAnTHER,
**                        ADCAnSGSTCRx, ICADCAnIm, ADCAnSGSTR, ADCAnADHALTR,
**                        ADCAnSGSTPCRx, DCSTm
*******************************************************************************/

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_077 */
/* Implements ADC_ESDD_UD_001 */
/* Implements ADC_ESDD_UD_006 */
/* Implements ADC_ESDD_UD_036 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwStopGroupConversion(Adc_GroupType Group)
{

  #if (((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                   ((ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON) || \
                             (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)))  \
                                            || (ADC_TRACK_AND_HOLD == STD_ON))
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #endif
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint8 LucHwUnitIndex;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;

  uint8 LucSgUnitIndex;
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  uint8 LucSgUnitId;
  #endif
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  uint32 LulRegWriteValue;
  uint8 LucHwUnit;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  #if (((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                   ((ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON) || \
                             (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)))  \
                                            || (ADC_TRACK_AND_HOLD == STD_ON))
  /* Get the pointer to Group configuration */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[Group];
  /* END Msg(4:0491)-5 */
  #endif
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = Adc_GpGroupConfig[Group].ucSgUnitIndex;
   /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = Adc_GpGroupConfig[Group].ucHwUnitIndex;
  /* END Msg(4:0491)-5 */
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  /* Get the SGm unit to which the channel group is mapped */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(4:0491)-5 */
  #endif
  /* Get the SG register index */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
  /* END Msg(4:0491)-5 */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
   /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the hardware unit index */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the pointer to SG unit RAM data */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
/* Implements ADC386, SWS_Adc_00386 */
  if (Group == LpSgUnitData->ddCurrentConvGroup)
  {
    /*
     * Stop the conversion of the SG unit in which requested group is mapped
     * by changing mode to Multicycle scan mode and number of scan as one
     */
    /* Buffer the status of SGSTR */
    /* MISRA Violation: START Msg(2:2814)-27 */
    LulRegSGSTR = LpAdcRegisters->ulSGSTR;
    /* END Msg(2:2814)-27 */

    /* Read the SG offset */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
    /* END Msg(4:0491)-5 */
    /* Buffer the status of SGCR */
    /* MISRA Violation: START Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(2:3892)-28 */
    LulRegSGCR[ADC_SG1] =
                    Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
    LulRegSGCR[ADC_SG2] =
                    Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
    LulRegSGCR[ADC_SG3] =
                    Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
    /* END Msg(4:2985)-10 */
    /* END Msg(2:3892)-28 */
    /* Set TRGMD of all scan groups to 0 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
    LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                       & ADC_CLEAR_TRGMD;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:2814)-27 */
    /* MISRA Violation: START Msg(2:3139)-25 */
    /* MISRA Violation: START Msg(2:3141)-26 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
    /* END Msg(2:2814)-27 */
    /* END Msg(4:2985)-10 */
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);

    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
    LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                       & ADC_CLEAR_TRGMD;
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);

    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
    LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                       & ADC_CLEAR_TRGMD;
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* END Msg(2:3139)-25 */
    /* END Msg(2:3141)-26 */
    /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
    Adc_HaltADConversion(LucHwUnitIndex);

    /* Clear the operation mode configured previously */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:2814)-27 */
    /* MISRA Violation: START Msg(2:3139)-25 */
    /* MISRA Violation: START Msg(2:3141)-26 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR,
                    ADC_CLR_SCAN_GRP_CTL_REG,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                    ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGCR,
                    ADC_HWSTOPGROUPCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* END Msg(2:2814)-27 */
    /* END Msg(2:3139)-25 */
    /* END Msg(2:3141)-26 */

    /* Set applicable TRGMD of buffer to 0 */
    LulRegSGCR[LucSgRegIndex-LucSGOffset] =
                 LulRegSGCR[LucSgRegIndex-LucSGOffset] & ADC_CLEAR_TRGMD;

#if (ADC_HARD_STOP == STD_OFF)
    /* Stop the conversion of all the SG unit */
    Adc_HaltScanGroup(Group);
#elif (ADC_HARD_STOP == STD_ON)
    /* Stop the conversion of all the SG unit using ADCAnSGSTPCRx Resistor. */
    Adc_StopScanGroup(Group);
#endif
    /* Clear the status bit of actually stopped SG */
    LulRegSGSTR = (LulRegSGSTR &
                (uint32)(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
    /* Initialize SG RAM data to a local pointer */
    LpSgUnitData->blSgUnitStatus = ADC_FALSE;
    #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
    #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
    if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
          (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
    {
      /* Disable self-diag voltage level selection */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                     ADC_SELF_DIAG_VLTG_DISABLE,
                     &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                     ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                     ADC_HWSTOPGROUPCONVERSION_API_ID);
      if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
      {
        /* Disable self-diag voltage level selection */
        ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                       ADC_SELF_DIAG_VLTG_DISABLE,
                       &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
        ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                       ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                       ADC_HWSTOPGROUPCONVERSION_API_ID);
        /* END Msg(4:3138)-22 */
      }
      else
      {
         /* To avoid MISRA violation */
      }
      /* Disable the self diag functionality support */
      /* MISRA Violation: START Msg(4:3138)-22 */
      LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                 &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                 LulRegWriteValue, ADC_WV_MASK_ADCR,
                 ADC_HWSTOPGROUPCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
    }
    /* group is configured as normal group */
    else
    {
      /* No action required */
    }
    #endif

    #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
    /* check the group is configured in the open pin self diag support */
    if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
    {
      /* Implements AR_PN0076_FSR_0002 */
      /* Disable on-chip pull-down resistor */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                     ADC_DISABLE_PULL_DOWN_RESISTOR,
                     &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                     ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                     ADC_HWSTOPGROUPCONVERSION_API_ID);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                     ADC_DISABLE_PULL_DOWN_RESISTOR,
                     &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                     ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                     ADC_HWSTOPGROUPCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
    }
    /* group is configured as normal group */
    else
    {
      /* No action required */
    }
    #endif
    #endif
/* Implements AR_PN0076_FR_0100 */
    #if (ADC_TRACK_AND_HOLD == STD_ON)
    /* Check if group is configured with Track and Hold enabled channel */
    if (ADC_TRUE == LpGroup->blTandHEnable)
    {
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* Stop sampling of all the Track and Hold channels */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR);
      /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                      ADC_HWSTOPGROUPCONVERSION_API_ID);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                      ADC_HWSTOPGROUPCONVERSION_API_ID);
      /* Un Map the channels to group A or B */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                      ADC_HWSTOPGROUPCONVERSION_API_ID);
      /* Disable the channels configured for Track and Hold functionality */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                      ADC_HWSTOPGROUPCONVERSION_API_ID);
      /* Disable to perform automatic sampling */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                      ADC_HWSTOPGROUPCONVERSION_API_ID);
     /* END Msg(4:3138)-22 */
    }
    else
    {
      /* To avoid MISRA violation */
    }
    #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */

    /* Writing back the previously configured TRGMD bits */
    /* MISRA Violation: START Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(2:3892)-28 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
    LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                       | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
    /* END Msg(2:3892)-28 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3139)-25 */
    /* MISRA Violation: START Msg(2:3141)-26 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
    /* END Msg(4:2985)-10 */
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);

    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
    LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                       | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);

    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
    LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                       | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
    ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              ADC_HWSTOPGROUPCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* END Msg(2:3139)-25 */
    /* END Msg(2:3141)-26 */
    /* Writing back the previously Trigger conversion */
    /* If SG1 was in suspended state */
    /* MISRA Violation: START Msg(2:3892)-28 */
    /* MISRA Violation: START Msg(4:2992)-31 */
    if (ADC_NOT_BUSY != (LulRegSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ZERO]))
    /* END Msg(4:2992)-31 */
    /* END Msg(2:3892)-28 */
    {
      /* Trigger conversion of SG1 */
      /* MISRA Violation: START Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
      /* END Msg(4:2985)-10 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3109)-24 */
    }
    else
    {
      /* No Action */
    }
    /* If SG2 was in suspended state */
    /* MISRA Violation: START Msg(2:3892)-28 */
    /* MISRA Violation: START Msg(4:2992)-31 */
    if (ADC_NOT_BUSY != (LulRegSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ONE]))
    /* END Msg(4:2992)-31 */
    /* END Msg(2:3892)-28 */
    {
      /* Trigger conversion of SG2 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(2:3109)-24 */
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No Action */
    }
    /* If SG3 was in suspended state */
    /* MISRA Violation: START Msg(2:3892)-28 */
    /* MISRA Violation: START Msg(4:2992)-31 */
    if (ADC_NOT_BUSY != (LulRegSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_TWO]))
    /* END Msg(4:2992)-31 */
    /* END Msg(2:3892)-28 */
    {
      /* Trigger conversion of SG3 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(2:3109)-24 */
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No Action */
    }

    #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
    /* Check if the Group is mapped for HW configured for interrupt mode */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitId]
                                                      .enFunctionalityModeType)
    /* END Msg(4:0491)-5 */
    {
      /* Disable the interrupt for the SGm unit to which the group is mapped */
      Adc_IcrInterruptBit(LucSgUnitIndex, ADC_DISABLE_INTERRUPT);
      /* Clear pending interrupt for the SGm unit to which group is mapped */
      Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
    }
    else
    {
      /* No action required */
    }
    #endif
    /* Group Priority is enabled or queue is enabled */
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                            (ADC_ENABLE_QUEUING == STD_ON)))
    /* Fetch the next group for conversion if the queue is not empty */
    if (ADC_QUEUE_EMPTY != LpSgUnitData->ucQueueStatus)
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Adc_PopFromQueue(LucSgUnitIndex));
    }
    else
    {
      /* No action required */
    }
    #endif /*
            * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) ||
            * ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&
            *               (ADC_ENABLE_QUEUING == STD_ON)))
            */
  }
  #if (((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) || \
                       ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                           (ADC_ENABLE_QUEUING == STD_ON)))

  /* MISRA Violation: START Msg(4:0491)-5 */
  else if (ADC_TRUE == Adc_GpGroupRamData[Group].ucGrpPresent)
  /* END Msg(4:0491)-5 */
  {
    /* Implements ADC437, SWS_Adc_00437, SWS_Adc_00438, ADC438 */
    /* Search and delete the requested group from the queue */

    Adc_SearchnDelete(Group);
  }
  else
  {
    /* To avoid MISRA violation */
  }
  #endif /* (((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) ||
          * ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&
          * (ADC_ENABLE_QUEUING == STD_ON)))
          */
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
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
** Function Name        : Adc_HwEnableHardwareTrigger
**
** Service ID           : NA
**
** Description          : This internal function will enable the hardware
**                        trigger for the requested ADC Channel group.
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
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpHwUnitConfig,
**                        Adc_GpHwUnitRamData, Adc_GpRunTimeData
**                        Adc_GpGroupRamData, Adc_GpSgUnitConfig,
**                        Adc_GpSgUnitRamData, Adc_GaaSGmConvStatusMask
**
** Functions invoked    : Det_ReportError, ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION, Adc_EnableHWGroup,
**                        Adc_PushToQueue, Adc_DisableHWGroup,
**                        Adc_HaltScanGroup, Adc_StopScanGroup
**
** Registers Used       : ADCAnSGSTR, ADCAnSGTSEL, ADCAnECR, ADCAnULLMTBRx,
**                        ADCAnSGCRx, DCENm, DCSTCm, DRSAm, DDAm, DTCm, DRSAm,
**                        DRDAm, DRTCm, DSAm, DTCTm, ADCAnADCR, ADCAnDGCTL0,
**                        ADCAnDGCTL1, ICDMAm, ADCAnPDCTL1, ADCAnPDCTL2,
**                        ADCAnSGVCSPx, ADCAnVCRj, ADCAnSGVCEPx, ADCAnTHCR,
**                        ADCAnTHACR, ADCAnTHBCR,  ADCAnTHER, ADCAnTHGSR,
**                        ADCAnTHSMPSTCR, ADCAnSGSTCRx, ICADCAnIm, ADCAnSGTSELx,
**                        ADCAnSGSTPCRx, ADCAnADHALTR, DCSTm
*******************************************************************************/
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_078 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwEnableHardwareTrigger(Adc_GroupType Group)
{
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  #endif
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  /* Pointer to the hardware unit user base configuration address */
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  Adc_GroupType LddCurrentGroup;
  #endif
  /* Local variable to store the hardware unit number */
  uint8 LucHwUnit;
  /* Local variable to store the SGm unit number */
  uint8 LucSgUnitIndex;
  uint8 LucSgUnitId;

  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif

  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[Group];
  /* END Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = LpGroup->ucHwUnitIndex;
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Read the hardware unit index */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* END Msg(4:0491)-5 */
  if ((ADC_NOT_BUSY == (LpAdcRegisters->ulSGSTR &
                          Adc_GaaSGmConvStatusMask[LucSgUnitId]) ) &&
                              (ADC_FALSE == LpSgUnitData->blSgUnitStatus))
  {
    Adc_EnableHWGroup(Group);
  }
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* Implements AR_PN0076_FR_0046, AR_PN0076_FR_0047 */
  /* Implements AR_PN0076_FR_0048, AR_PN0076_FR_0049 */
  /* IF the requested group has higher priority than ongoing conversion AND */
  else if (LpGroup->ddGroupPriority > LpSgUnitData->ddCurrentPriority)
  {
    /* Fetch the group id of the current conversion group */
    LddCurrentGroup = LpSgUnitData->ddCurrentConvGroup;
    /* Check if the current ongoing conversion is of SW triggered group */
    if (ADC_TRIGG_SRC_SW == LpSgUnitData->enTrigSource)
    {
      /* Check if the queue is full */
      if (ADC_QUEUE_FULL != LpSgUnitData->ucQueueStatus)
      {
        #if (ADC_HARD_STOP == STD_OFF)
        /* Stop the conversion of all the SG unit */
        Adc_HaltScanGroup(Group);
        #elif (ADC_HARD_STOP == STD_ON)
        /*
           Stop the conversion of all the SG unit using ADCAnSGSTPCRx register.
         */
        Adc_StopScanGroup(Group);
        #endif
        /* Push the current conversion group into queue */
        Adc_PushToQueue(LddCurrentGroup);
        /* Read the group data pointer */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
        /* END Msg(4:0491)-5 */
        /*
         * Check if the group as to be resumed from where it had stopped
         * before
         */
        /* Implements ADC345, SWS_Adc_00345, ADC430, SWS_Adc_00430 */
        /* MISRA Violation: START Msg(4:0491)-5 */
        if (ADC_GROUP_SUSPEND_RESUME == (Adc_GpGroupConfig[LddCurrentGroup]
                 .ucGroupSettings & ADC_GROUP_REPLACEMENT_MASK))
        /* END Msg(4:0491)-5 */
        {
          /* MISRA Violation: START Msg(4:0491)-5 */
          /* Load the number of channels converted before suspension */
          Adc_GpGroupRamData[LddCurrentGroup].ucReChannelsCompleted =
                     LpRunTimeData->ucChannelsCompleted;
          /* END Msg(4:0491)-5 */
        }
        else
        {
          /* No action required */
        }
        /*
         * Load the number of samples converted before aborting or
         * suspension
         */

        /* MISRA Violation: START Msg(4:0491)-5 */
        Adc_GpGroupRamData[LddCurrentGroup].ucReSamplesCompleted =
                   LpRunTimeData->ucSamplesCompleted;
        /* END Msg(4:0491)-5 */

        /* Configure the requested group for conversion */
        Adc_EnableHWGroup(Group);
      }
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      else
      {
        /* Report Error to DET */
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_BUSY);
      }
      #endif
    }
    else
    {
      Adc_DisableHWGroup(LddCurrentGroup);
      Adc_EnableHWGroup(Group);
    }
  }
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
  else
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Implements AR_PN0076_FR_0051, AR_PN0076_FR_0015 */
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_ENABLE_HARDWARE_TRIGGER_SID, ADC_E_BUSY);
    #endif
  }
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
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
** Function Name        : Adc_HwDisableHardwareTrigger
**
** Service ID           : NA
**
** Description          : This internal function will disables the hardware
**                        trigger for the requested ADC Channel group.
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
** Global Variables     : Adc_GpGroupConfig, Adc_GpSgUnitRamData,
**                        Adc_GpSgUnitConfig.
**
** Functions invoked    : ADC_ENTER_CRITICAL_SECTION,
**                        Adc_ConfigureGroupForConversion,
**                        ADC_EXIT_CRITICAL_SECTION, Adc_PopFromQueue,
**                        Adc_DisableHWGroup
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm,
**                        DDAm, DTCm, DRSAm, DRDAm, DRTCm, DSAm, DTCTm,
**                        ADCAnADCR, ADCAnDGCTL0, ADCAnDGCTL1, ICDMAm, DCSTm
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx, ADCAnVCRj,
**                        ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR, ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR, ADCAnSGSTCRx,
**                        ICADCAnIm, ADCAnSGTSELx, ADCAnSGSTPCRx, ADCAnSGSTR
*******************************************************************************/
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_079 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwDisableHardwareTrigger(Adc_GroupType Group)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  Adc_GroupType LddCurrentGroup;
  /* Local variable to store the SGm unit number */
  uint8 LucSgUnitIndex;

  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* get the group */
  LpGroup = &Adc_GpGroupConfig[Group];
  /* END Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* Initialize SG RAM data to a local pointer */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Fetch the group id of the current conversion group */
  LddCurrentGroup = LpSgUnitData->ddCurrentConvGroup;
  /* If the request group and ongoing group are same */
  if (Group == LddCurrentGroup)
  {
    /* Disable the ongoing HW triggered group */
    Adc_DisableHWGroup(Group);
  }
  else
  {
     /* No action required */
  }

  #if (((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                         (ADC_ENABLE_QUEUING == STD_ON)))
  if (ADC_QUEUE_EMPTY != LpSgUnitData->ucQueueStatus)
  {
    /* Fetch the next group for conversion if the queue is not empty */
    LpSgUnitData->blSgUnitStatus = ADC_TRUE;
    Adc_ConfigureGroupForConversion(Adc_PopFromQueue(LucSgUnitIndex));
  }
  else
  {
    /* No action required */
  }
  #endif /*
          *   #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) ||
          *        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&
          *                              (ADC_ENABLE_QUEUING == STD_ON))))
          */
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
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
** Function Name        : Adc_PushToQueue
**
** Service ID           : NA
**
** Description          : This function add the requested group into Queue.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpHwUnitConfig,
**                        Adc_GpSgUnitRamData, Adc_GpGroupRamData,
**                        Adc_GpSgUnitConfig,
**
** Functions invoked    : None
**
** Registers Used       : None
*******************************************************************************/
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
           ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_080 */
/* Implements SWS_Adc_00311, ADC311, SWS_Adc_00312, ADC312 */
/* Implements SWS_Adc_00289, ADC289, SWS_Adc_00332, ADC332 */
/* Implements SWS_Adc_00417, ADC417, SWS_Adc_00333, ADC333 */
/* Implements SWS_Adc_00335, ADC335 */
FUNC(void, ADC_PRIVATE_CODE) Adc_PushToQueue(Adc_GroupType LddGroup)
{
  P2CONST(Adc_HwSgUnitType, AUTOMATIC, ADC_CONFIG_CONST) LpSgUnit;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  uint8 LucSgUnitIndex;
  uint8 LucLoopCount;
  uint8 LucQueueSize;
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  uint8 LucLoopCountCond;
  uint8 LucPriority;
  #endif

  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgUnitIndex = Adc_GpGroupConfig[LddGroup].ucSgUnitIndex;
  /* Read for SG unit and the Priority Queue */
  LpSgUnit = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  LpQueue = LpSgUnit->pQueue;
  /* Initialize SG RAM data to a local pointer */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */

  /* Read the configured priority queue size */
  LucQueueSize = LpSgUnit->ucAdcSgQueueSize;

  /* Read the queue counter */
  LucLoopCount = LpSgUnitData->ucQueueCounter;

  /* Set the flag indicating that group is present in the queue */
  /* MISRA Violation: START Msg(4:0491)-5 */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_TRUE;
  /* END Msg(4:0491)-5 */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Store the group into queue if queue is empty */
  if (ADC_QUEUE_EMPTY == LpSgUnitData->ucQueueStatus)
  #else
  /* Store the group into queue if queue is empty or not full */
  if ((ADC_QUEUE_EMPTY == LpSgUnitData->ucQueueStatus) ||
                       (ADC_QUEUE_FILLED == LpSgUnitData->ucQueueStatus))
  #endif
  {
    /* Store the group into queue */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpQueue[LucLoopCount] = LddGroup;
    /* END Msg(4:0491)-5 */
    /* Increment the queue counter */
    LpSgUnitData->ucQueueCounter++;
  }
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  else /* Queue not empty */
  {
    /* Read the priority of the requested group */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LucPriority = Adc_GpGroupConfig[LddGroup].ddGroupPriority;
    /* END Msg(4:0491)-5 */

    /* Place the requested group in the queue based on this priority */
    do
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      /* MISRA Violation: START Msg(4:0488)-1 */
      if (((ADC_ZERO != LucLoopCount) && ((Adc_GpGroupConfig +
            LpQueue[LucLoopCount - ADC_ONE])->ddGroupPriority >= LucPriority)))
      /* END Msg(4:0488)-1 */
      /* END Msg(4:0491)-5 */
      {
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpQueue[LucLoopCount] = LpQueue[LucLoopCount - ADC_ONE];
        /* END Msg(4:0491)-5 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpQueue[LucLoopCount] = LddGroup;
        /* END Msg(4:0491)-5 */
        LucLoopCount = ADC_ZERO;
      }
      LucLoopCountCond = LucLoopCount;
      if (ADC_ZERO < LucLoopCount)
      {
        LucLoopCount--;
      }
      else
      {
        /* avoid MISRA warning */
      }
    } while (ADC_ZERO < LucLoopCountCond);

    /* Increment the queue counter */
    LpSgUnitData->ucQueueCounter++;
  }
  #else
  else
  {
    /* avoid MISRA warning */
  }
  #endif /*
          * #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
          */

  /* Check whether the Queue is Full */
  if (LucQueueSize <= LpSgUnitData->ucQueueCounter)
  {
    /* Set queue status as full */
    LpSgUnitData->ucQueueStatus = ADC_QUEUE_FULL;
  }
  else
  {
    /* Set queue status as filled */
    LpSgUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) ||
        * ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&
        * (ADC_ENABLE_QUEUING == STD_ON)))
        */

/*******************************************************************************
** Function Name        : Adc_PopFromQueue
**
** Service ID           : NA
**
** Description          : This function returns the highest priority group that
**                        was pushed in the Queue.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Group
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GpSgUnitRamData,
**                        Adc_GpGroupRamData, Adc_GpSgUnitConfig
**
** Functions invoked    : None
**
** Registers Used       : None
*******************************************************************************/
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_081 */
/* Implements SWS_Adc_00311, ADC311, SWS_Adc_00312, ADC312 */
/* Implements SWS_Adc_00289, ADC289, SWS_Adc_00332, ADC332 */
/* Implements SWS_Adc_00417, ADC417, SWS_Adc_00333, ADC333 */
/* Implements SWS_Adc_00335, ADC335 */
FUNC(Adc_GroupType, ADC_FAST_CODE) Adc_PopFromQueue(uint8 LucSgUnitIndex)
{
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  Adc_GroupType LddGroup;
  uint8 LucQueueCounter;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON))
  uint8 LucLoopCount;
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Get the pointer to SG unit queue */
  LpQueue = Adc_GpSgUnitConfig[LucSgUnitIndex].pQueue;
  /* END Msg(4:0491)-5 */

  /* Read the highest priority task from the queue */
  LucQueueCounter = LpSgUnitData->ucQueueCounter;

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)  || \
                           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the Group which is of next priority level */
  LddGroup = LpQueue[LucQueueCounter - ADC_ONE];
  /* END Msg(4:0491)-5 */

  #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON))
  /* Initialize the loop counter to zero */
  LucLoopCount = ADC_ZERO;

  /* Decrement the queue counter value by one */
  LucQueueCounter--;
  /*
   * Get the group which was requested just after the immediate
   * conversion completed group
   */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LddGroup = LpQueue[ADC_ZERO];
  /* END Msg(4:0491)-5 */
  do
  {
    /* MISRA Violation: START Msg(4:0491)-5 */
    /* Re-arrange the queue based on which channel group was requested first */
    LpQueue[LucLoopCount] = LpQueue[LucLoopCount + ADC_ONE];
    /* END Msg(4:0491)-5 */
    /* Increment the loop count */
    LucLoopCount++;

  }while (LucLoopCount < LucQueueCounter);

  #endif /*
          * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
          * (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
          */

  /* Check whether the Queue is not empty */
  if (ADC_ZERO < LpSgUnitData->ucQueueCounter)
  {
    /* Update the queue counter */
    LpSgUnitData->ucQueueCounter--;
    if (ADC_ZERO == LpSgUnitData->ucQueueCounter)
    {
      /* Set queue status as empty */
      LpSgUnitData->ucQueueStatus = ADC_QUEUE_EMPTY;
    }
    else
    {
      /* Set queue status as filled */
      LpSgUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
    }
  }
  else
  {
    /* No action required */
  }
  /* Clear the flag indicating group is no longer in queue */
  /* MISRA Violation: START Msg(4:0491)-5 */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_FALSE;
  /* END Msg(4:0491)-5 */
  return(LddGroup);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) ||
        * ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&
        * (ADC_ENABLE_QUEUING == STD_ON)))
        */

/*******************************************************************************
** Function Name        : Adc_Isr
**
** Service ID           : NA
**
** Description          : This function is an interrupt service routine for ADC.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : LucHwUnit, LucSGUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpSgUnitRamData,
**                        Adc_GpGroupConfig, Adc_GpSgUnitIndex
**
** Functions invoked    : Adc_ChannelCompleteMode, Adc_GroupCompleteMode,
**
** Registers Used       : WUF0, WUFC0 ADCAnECR, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER, ADCAnTHCR,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnSGSTCRx, ADCAnDIRj
**                        ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnDRj, ADCAnVCRj,
**                        ICDMAm, ICADCAnIm, ADCAnADCR, ADCAnULER
*******************************************************************************/
#if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_082 */
/* Implements ADC_ESDD_UD_044 */
FUNC(void, ADC_FAST_CODE) Adc_Isr(uint8 LucHwUnit, uint8 LucSGUnit)
{
  /* Implements AR_PN0076_FR_0072 */
  /* Local variable to store the group number */
  uint8 LucCurrentGroup;
  uint8 LucHwUnitIndex;
  uint8 LucSgUnitIndex;
  #if (ADC_WAKEUPFACTOR_CLEAR_ISR == STD_ON)
  uint32 LulRegWriteValue;
  #endif

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the requested HW unit index */
  LucHwUnitIndex = Adc_GpHwUnitIndex[LucHwUnit];
  /* Get the requested SG unit index */
  LucSgUnitIndex =
             Adc_GpSgUnitIndex[((LucHwUnit * ADC_NO_OF_SG_UNITS) + LucSGUnit)];
  /* Read the current conversion group number */
  LucCurrentGroup = Adc_GpSgUnitRamData[LucSgUnitIndex].ddCurrentConvGroup;
  /* END Msg(4:0491)-5 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                         (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
  /* Implements ADC310, SWS_Adc_00310, ADC430, SWS_Adc_00430 */
  /* Check if group is configured in abort/restart mode */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((ADC_GROUP_ABORT_RESTART == (Adc_GpGroupConfig[LucCurrentGroup]
                            .ucGroupSettings & ADC_GROUP_REPLACEMENT_MASK))
                              || (Adc_GucMaxSwTriggGroups <= LucCurrentGroup))
  /* END Msg(4:0491)-5 */
  {
    /* Invoke group complete function */
    Adc_GroupCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  }
  else /* channel complete function */
  {
    /* Invoke channel complete function */
    Adc_ChannelCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  }
  #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                         (ADC_ENABLE_EXTERNAL_MUX == STD_OFF))
  /* Invoke group complete function */
  Adc_GroupCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  /* Implements: ADC337, SWS_Adc_00337 */
  #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)
  /* Invoke group complete function */
  Adc_GroupCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  #else /* if priority is ADC_PRIORITY_HW_SW */
  /* Check if group is configured in abort/restart mode */
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Implements ADC310, SWS_Adc_00310,  ADC430, SWS_Adc_00430 */
  if ((Adc_GucMaxSwTriggGroups <= LucCurrentGroup) ||
             (ADC_GROUP_ABORT_RESTART == (Adc_GpGroupConfig[LucCurrentGroup].
                     ucGroupSettings & ADC_GROUP_REPLACEMENT_MASK)))
  /* END Msg(4:0491)-5 */
  {
    /* Invoke group complete function */
    Adc_GroupCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  }
  else /* channel complete function */
  {
    /* Invoke channel complete function */
    Adc_ChannelCompleteMode(LucCurrentGroup, LucHwUnitIndex);
  }
  #endif

  #if (ADC_WAKEUPFACTOR_CLEAR_ISR == STD_ON)
  /* Check that ISR belong to the HW0 and wake up factor is occurred*/
  if ((ADC_ZERO == LucHwUnit) &&
                    (ADC_NO_WAKEUP_FACTOR !=
           ((Adc_GaaWUFReg_BaseAddress->ulWUF0) & ADC_WUF_CLEAR_MASK_VALUE)))
  {
    /* Implements AR_PN0076_FR_0304 */
    /* Set the wake up factor clear register to clear the wake up factor */
    LulRegWriteValue = (Adc_GaaWUFReg_BaseAddress->ulWUF0 &
                        ADC_WUF_CLEAR_MASK_VALUE);
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&Adc_GaaWUFReg_BaseAddress->ulWUFC0, LulRegWriteValue);
    ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(&Adc_GaaWUFReg_BaseAddress->ulWUF0,
                       ADC_ZERO, (ADC_WUF_CLEAR_MASK_VALUE),
                       ADC_ISR_API_ID);
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* Do nothing  */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING )*/

/*******************************************************************************
** Function Name        : Adc_DmaIsr
**
** Service ID           : NA
**
** Description          : This function is an DMA Completer interrupt service
**                        routine for ADC.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit, LucSGUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpSgUnitRamData,
**                        Adc_GpGroupRamData, Adc_GpGroupConfig,
**                        Adc_GpSgUnitIndex
**
** Functions invoked    : Adc_PopFromQueue, Adc_IsrConfigureGroupForConversion
**
** Registers Used       : ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm,  DRDAm, DRTCm, DTCTm, ADCAnADCR,
**                        ADCAnDGCTL0,  ADCAnDGCTL1, ADCAnPDCTL1, ADCAnPDCTL2,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR,
**                        ADCAnSGSTCRx, ADCAnDRj, ADCAnVCRj, ICDMAm, ICADCAnIm
*******************************************************************************/
#if (ADC_DMA_MODE_ENABLE == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_083 */
FUNC(void, ADC_FAST_CODE) Adc_DmaIsr(uint8 LucHwUnit, uint8 LucSGUnit)
{
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  /* Local variable to store the group number */
  Adc_GroupType LddGroup;
  uint8 LucSgUnitIndex;

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the requested HW unit's index */
  LucHwUnit = Adc_GpHwUnitIndex[LucHwUnit];
  /* Get the requested SG unit index */
  LucSgUnitIndex =
             Adc_GpSgUnitIndex[((LucHwUnit * ADC_NO_OF_SG_UNITS) + LucSGUnit)];
  /* Get the pointer the HW unit RAM data */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Read the current conversion group number */
  LddGroup = LpSgUnitData->ddCurrentConvGroup;

  /* Read the group data pointer */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Set group status as conversion completed */
  LpGroupData->enGroupStatus = ADC_STREAM_COMPLETED;

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Implements SWS_Adc_00060, ADC060 */
  /* Implements SWS_Adc_00104, ADC104 */
  /* Invoke notification function if enabled */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
      (NULL_PTR != Adc_GpGroupConfig[LddGroup].pGroupNotificationPointer))
  {
    Adc_GpGroupConfig[LddGroup].pGroupNotificationPointer();
  }
  /* END Msg(4:0491)-5 */
  /* Implements SWS_Adc_00083, ADC083 */
  else
  {
    /* No action required */
  }
  #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
  /* Check if the operation mode is continuous */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if (ADC_GROUP_ONCE == (Adc_GpGroupConfig[LddGroup].ucGroupSettings &
                                                       ADC_GROUP_CONV_MASK))
  /* END Msg(4:0491)-5 */
  {
    if (ADC_QUEUE_EMPTY != LpSgUnitData->ucQueueStatus)
    {
      /* Fetch the highest priority group from the queue */
      LddGroup = Adc_PopFromQueue(LucHwUnit);
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      /* Initiate the group conversion */
      Adc_IsrConfigureGroupForConversion(LddGroup);
    }
    else
    {
      /* Set the SG unit status to available */
      LpSgUnitData->blSgUnitStatus = ADC_FALSE;
    }
  }
  else
  {
    /* No action required */
  }
  #endif  /*
           * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
           *    ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
           *                  (ADC_ENABLE_QUEUING == STD_ON)))
           */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */


/*******************************************************************************
** Function Name        : Adc_ChannelCompleteMode
**
** Service ID           : NA
**
** Description          : This function is invoked from ADC ISR for servicing
**                        the groups configured in select operation mode.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LucHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GpRunTimeData, Adc_GucMaxSwTriggGroups
**                        Adc_GpSgUnitRamData, Adc_GpHwUnitConfig,
**                        Adc_GpChannelToGroup, Adc_GpSgUnitConfig
**
** Functions invoked    : Adc_PopFromQueue, Adc_IsrConfigureGroupForConversion
**
** Registers Used      : ADCAnECR, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnADCR,
**                       ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR,  ADCAnTHACR,
**                       ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER,  ADCAnTHCR,
**                       ADCAnSGVCSPx, ADCAnSGVCEPx,  ADCAnSGSTCRx, ADCAnDIRj
**                       ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm,
**                       DDAm, DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnDRj,
**                       ADCAnVCRj, ICDMAm, ICADCAnIm, ADCAnULER
*******************************************************************************/
#if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
            (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                         (ADC_ENABLE_EXTERNAL_MUX == STD_ON))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_084 */
/* Implements ADC_ESDD_UD_001 */
FUNC(void, ADC_FAST_CODE) Adc_ChannelCompleteMode(Adc_GroupType LddGroup,
                                                    uint8 LucHwUnit)
{
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitRamData;
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;

  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  #if ((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
              (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON))
  uint32 LulRegWriteValue;
  #endif
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpResultRegister;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  #if ((ADC_ERROR_SUPPORT == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                    (ADC_FUNCTIONALITY_MODE != ADC_POLLING)&&\
                             (ADC_HW_MUX_STAB_SUPPORT == STD_OFF))
  volatile uint32 LulVarValue;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT))
  uint32 LulVirtualChannel;
  #endif
  /* MISRA Violation: START Msg(4:0759)-2 */
  Adc_ConvertedVal LunConvertedValue;
  /* END Msg(4:0759)-2 */
  uint8 LucSgUnitIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  uint8 LucSgRegIndex;
  boolean LblPopGroupFrmQueue;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;

  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  boolean LblLimitCheckErrorFlag;
  LblLimitCheckErrorFlag = ADC_FALSE;
  #endif
  LblPopGroupFrmQueue = ADC_FALSE;
  LulRegSGSTR = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_ZERO] = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_ONE] = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_TWO] = ADC_DOUBLE_WORD_ZERO;
  /* Get the pointer to requested group's configuration */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */

  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* Get the SG unit which is configured for this group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Get the SG unit index */
  LucSgRegIndex = LpSgUnitConfig->ucSgRegIndex;
  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /* Read the hardware unit index */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
   /* END Msg(4:0491)-5 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  #if ((ADC_ERROR_SUPPORT == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
  /* END Msg(4:0491)-5 */
  #endif
  /* Get SG register pointer */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /*
   * Deleted the macro switch for variables definition,
   * Avoid compilation errors(variables is not used)
   * and add the following processing
   */
  /* MISRA Violation: START Msg(4:2983)-33 */
  LpAdcRegisters = LpAdcRegisters;
  LpAdcSGRegisters = LpAdcSGRegisters;
  /* END Msg(4:2983)-33 */

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the group's runtime data pointer */
  LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];

  /* Read the group data pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* END Msg(4:0491)-5 */
  LpResultRegister = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
  /* Read the channel's converted value */
  LunConvertedValue.ulValue = LpResultRegister->
        ulDIR[(LpGroup->ulStartVirChPtr + LpRunTimeData->ucChannelsCompleted)];

  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  #if (ADC_ERROR_SUPPORT == STD_ON)
  if (ADC_FALSE == LpHwUnitConfig->blInterruptErr)
  #endif
  {
    if (ADC_FALSE == LpGroup->blLimitCheckEnabled)
    {
      /* Load the buffer with 12-bit or 10-bit resolution value */
      *(LpRunTimeData->pBuffer) = LunConvertedValue.DWord.usLoWord;
    }
    else if (ADC_NO_LIMIT_ERROR == (LpAdcRegisters->ulULER &
                                              ADC_UE_LE_LIMIT_CHK_ERROR))
    {
      /* Load the buffer with 12-bit or 10-bit resolution value */
      /* Implements SWS_Adc_00447, ADC447 */
      *(LpRunTimeData->pBuffer) = LunConvertedValue.DWord.usLoWord;
    }
    else
    {
      /*
       * Since the digital value is not within the specified range for channel
       * configured for this group, the out of range digital values are not
       * not copied to application buffer.
       */
       /* Implements SWS_Adc_00446, ADC446 */
       /* Implements SWS_Adc_00448, ADC448 */
       /* Implements SWS_Adc_00449, ADC449 */
       /* Implements SWS_Adc_00450, ADC450 */
      LblLimitCheckErrorFlag = ADC_TRUE;
      /*
       * Update ADCAnECR register to clear the error flags,
       * so that on next iteration previous error is not reflected
       */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

      /* END Msg(4:3138)-22 */
    }
  }
  #if (ADC_ERROR_SUPPORT == STD_ON)
  else
  {
    /* Load the buffer with 12-bit or 10-bit resolution value */
    *(LpRunTimeData->pBuffer) = LunConvertedValue.DWord.usLoWord;
  }
  #endif
  #else
  /* Load the buffer with 12-bit or 10-bit resolution value */
  *(LpRunTimeData->pBuffer) = LunConvertedValue.DWord.usLoWord;
  #endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

  /* Update the number of channels that completed conversion */
  LpRunTimeData->ucChannelsCompleted++;
  #if (ADC_ENABLE_STREAMING == STD_ON)
  /* Increment buffer pointer for the next channel */
  LpRunTimeData->pBuffer = (LpRunTimeData->pBuffer +
                                             LpRunTimeData->ucStreamingSamples);
  #else
  /* Increment buffer pointer for the next channel */
  /* MISRA Violation: START Msg(4:0489)-12 */
  LpRunTimeData->pBuffer++;
  /* END Msg(4:0489)-12 */
  #endif

  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                                 (ADC_FUNCTIONALITY_MODE != ADC_POLLING) &&\
                             (ADC_HW_MUX_STAB_SUPPORT == STD_OFF))
  /* Check if external multiplexer is enabled for the group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((ADC_TRUE == LpGroup->blExtMuxEnabled) &&
                  (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex].
                                                     enFunctionalityModeType))
  /* END Msg(4:0491)-5 */
  {
    /* Get the delay count value for mux lines to stabilize */
    LulVarValue = LpGroup->ulDelayCount;
    /* QAC Warning: START Msg(2:3416)-23 */
    while (ADC_DOUBLE_WORD_ZERO != LulVarValue)
    /* END Msg(2:3416)-23 */
    {
      /* Decrement the count value */
      LulVarValue--;
    }
  }
  else
  {
     /* No action required */
  }
  #endif

  /* Check if the conversion of all the samples are completed */
  if (LpRunTimeData->ucStreamingSamples == LpRunTimeData->ucSamplesCompleted)
  {
    LpRunTimeData->ucSamplesCompleted = ADC_ZERO;

  }
  else
  {
    /* To avoid misra violation */
  }
  #if (ADC_ENABLE_STREAMING == STD_ON)
  /* Check if the result access mode is streaming */
  if (ADC_GROUP_ACCESS_STREAMING == (LpGroup->ucGroupSettings &
                                                  ADC_GROUP_ACCESS_MASK))
  {
    /* Check if the conversion of all the channels in the group is completed */
    if (LpRunTimeData->ucChannelCount == LpRunTimeData->ucChannelsCompleted)
    {
      /* Check if the last streaming values were read */
      if (ADC_TRUE == LpGroupData->blResultRead)
      {
        #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        if (ADC_FALSE == LblLimitCheckErrorFlag)
        #endif
        {
          /* Set group status as conversion completed */
        /* Implements SWS_Adc_00224, ADC224 */
          LpGroupData->enGroupStatus = ADC_COMPLETED;
        }
        #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
          /* No action required */
        }
        #endif
      }
      else
      {
        /* No action required */
      }
      /* Update the completed conversion samples */
      LpRunTimeData->ucSamplesCompleted++;
    }
    else
    {
      /* No action required */
    }
    /* Check if the conversion of all the samples is completed */
    if (LpRunTimeData->ucStreamingSamples == LpRunTimeData->ucSamplesCompleted)
    {
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      if (ADC_FALSE == LblLimitCheckErrorFlag)
      #endif
      {
         /* Implements SWS_Adc_00325, ADC325 */
        /* Set group status as conversion completed */
        LpGroupData->enGroupStatus = ADC_STREAM_COMPLETED;
        /* All the samples are completed */
        LpGroupData->blSampleComp = ADC_TRUE;
        /* Set the flag indicating Adc_ReadGroup or Adc_GetStreamLastPointer
           should be called */
        LpGroupData->blResultRead = ADC_FALSE;
        #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
        /* Check the group is configured as Continuous conversion mode */
        if ((ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
                                        && (Adc_GucMaxSwTriggGroups > LddGroup))
        {
          /* Check if critical section protection is required */
          #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter the critical section protection */
          ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
          #endif
          /* Buffer the status of SGSTR and halt AD conversion */
          Adc_SaveRegAndHaltADConversion(LucHwUnit, LulRegSGCR,
                                &LulRegSGSTR, ADC_CHANNELCOMPLETEMODE_API_ID);
          #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
          if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
                (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
          {
            /* Disable self-diag voltage level selection */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                         ADC_SELF_DIAG_VLTG_DISABLE,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                         ADC_CHANNELCOMPLETEMODE_API_ID);
            if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
            {
              /* Disable self-diag voltage level selection */
              ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                         ADC_SELF_DIAG_VLTG_DISABLE,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
              ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                         ADC_CHANNELCOMPLETEMODE_API_ID);
              /* END Msg(4:3138)-22 */
            }
            else
            {
               /* To avoid MISRA violation */
            }
            /* Disable the self diag functionality support */
            /* MISRA Violation: START Msg(4:3138)-22 */
            LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                          LulRegWriteValue,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                          LulRegWriteValue, ADC_WV_MASK_ADCR,
                          ADC_CHANNELCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          /* group is configured as normal group */
          else
          {
            /* No action required */
          }
          #endif

          #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
          /* check the group is configured in the open pin self diag support */
          if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
          {
            /* Implements AR_PN0076_FSR_0002 */
            /* Disable on-chip pull-down resistor */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                          ADC_DISABLE_PULL_DOWN_RESISTOR,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                          ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                          ADC_CHANNELCOMPLETEMODE_API_ID);
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                          ADC_DISABLE_PULL_DOWN_RESISTOR,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                          ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                          ADC_CHANNELCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          /* group is configured as normal group */
          else
          {
            /* No action required */
          }
          #endif
          #if (ADC_TRACK_AND_HOLD == STD_ON)
          /* Check if group is configured with Track and Hold enabled channel */
          if (ADC_TRUE == LpGroup->blTandHEnable)
          {
            /* Stop sampling of all the Track and Hold channels */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR);
            /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                        ADC_CHANNELCOMPLETEMODE_API_ID);
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                        ADC_CHANNELCOMPLETEMODE_API_ID);
            /* Un Map the channels to group A or B */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                        ADC_CHANNELCOMPLETEMODE_API_ID);
            /* Disable the channels configured for Track and Hold functionality
             */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                        ADC_TRACK_AND_HOLD_REG_CLEAR,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                        ADC_CHANNELCOMPLETEMODE_API_ID);
            /* Disable to perform automatic sampling */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                        ADC_TRACK_AND_HOLD_REG_CLEAR,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                        ADC_CHANNELCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          else
          {
            /* To avoid MISRA violation */
          }
          #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */
          /* Don't start conversion, if group status is ADC_STREAM_COMPLETED *
           * and not continuous conversion mode.                             */
          if((ADC_STREAM_COMPLETED == LpGroupData->enGroupStatus)
                     && (ADC_GROUP_CONTINUOUS != (LpGroup->ucGroupSettings
                                                 & ADC_GROUP_CONV_MASK)))
          {
            /* Set applicable SGACT of buffer to 0, Stop conversion */
            LulRegSGSTR = (LulRegSGSTR &
                (uint32)(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
          }
          else
          {
            /* No action */
          }
          /* Writing back the previously Trigger conversion */
          Adc_WriteBackRegforADConversion(LucHwUnit, LulRegSGCR,
                                  LulRegSGSTR, ADC_CHANNELCOMPLETEMODE_API_ID);
          /* Check if critical section protection is required */
          #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit the critical section protection */
          ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
          #endif
        }
        else
        {
          /* No action required */
        }
        #endif
      }
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      else
      {
        /* No action required */
      }
      #endif
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

  /* Implements AR_PN0076_FR_0054 */
  /* Check if the conversion of all the channels in the group is completed */
  if (LpRunTimeData->ucChannelCount == LpRunTimeData->ucChannelsCompleted)
  {
    /* Reset the number of conversion completed channel count */
    LpRunTimeData->ucChannelsCompleted = ADC_ZERO;

    #if (ADC_ENABLE_STREAMING == STD_ON)
    /* Check if the result access mode is Single */
    if (ADC_GROUP_ACCESS_SINGLE == (LpGroup->ucGroupSettings &
                                                        ADC_GROUP_ACCESS_MASK))
    #endif
    {
      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter the critical section protection */
      ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif
      /* Buffer the status of SGSTR and halt AD conversion */
      Adc_SaveRegAndHaltADConversion(LucHwUnit, LulRegSGCR,
                                  &LulRegSGSTR, ADC_CHANNELCOMPLETEMODE_API_ID);
      /* Update the completed conversion samples */
      LpRunTimeData->ucSamplesCompleted++;

      #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
      /* Check the group is configured as Continuous conversion mode */
      if ((ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
                                      && (Adc_GucMaxSwTriggGroups > LddGroup))
      {
        #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
        if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
              (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
        {
          /* Disable self-diag voltage level selection */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                       ADC_SELF_DIAG_VLTG_DISABLE,
                       &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                       ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                       ADC_CHANNELCOMPLETEMODE_API_ID);
          if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
          {
            /* Disable self-diag voltage level selection */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                       ADC_SELF_DIAG_VLTG_DISABLE,
                       &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                       ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                       ADC_CHANNELCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          else
          {
             /* To avoid MISRA violation */
          }

          /* Disable the self diag functionality support */
          /* MISRA Violation: START Msg(4:3138)-22 */
          LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                      LulRegWriteValue,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                      LulRegWriteValue, ADC_WV_MASK_ADCR,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        /* group is configured as normal group */
        else
        {
          /* No action required */
        }
        #endif

        #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
        /* check the group is configured in the open pin self diag support */
        if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
        {
          /* Implements AR_PN0076_FSR_0002 */
          /* Disable on-chip pull-down resistor */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                         ADC_DISABLE_PULL_DOWN_RESISTOR,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                         ADC_CHANNELCOMPLETEMODE_API_ID);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                         ADC_DISABLE_PULL_DOWN_RESISTOR,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                         ADC_CHANNELCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        /* group is configured as normal group */
        else
        {
          /* No action required */
        }
        #endif
      }
      else
      {
        /* No action required */
      }
      #endif

      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      if (ADC_FALSE == LblLimitCheckErrorFlag)
      #endif
      {
        /* Set group status as conversion completed */
        LpGroupData->enGroupStatus = ADC_STREAM_COMPLETED;
        /* Implements AR_PN0076_FR_0100 */
        #if (ADC_TRACK_AND_HOLD == STD_ON)
        /* Check if group is configured with Track and Hold enabled channel */
        if (ADC_TRUE == LpGroup->blTandHEnable)
        {
          /* Stop sampling of all the Track and Hold channels */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR);
          /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          /* Un Map the channels to group A or B */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          /* Disable the channels configured for Track and Hold functionality */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          /* Disable to perform automatic sampling */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        else
        {
          /* To avoid MISRA violation */
        }
        #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */
      }
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      else
      {
        /* No action required */
      }
      #endif
      /* Don't start conversion, if group status is ADC_STREAM_COMPLETED *
       * and not continuous conversion mode.                             */
      if(((ADC_STREAM_COMPLETED == LpGroupData->enGroupStatus)
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
             || (ADC_TRUE == LblLimitCheckErrorFlag)
      #endif
             )
           /* MISRA Violation: START Msg(2:3892)-28 */
           && (ADC_GROUP_CONTINUOUS != (LpGroup->ucGroupSettings
                                             & ADC_GROUP_CONV_MASK)))
           /* END Msg(2:3892)-28 */
      {
        /* Set applicable SGACT of buffer to 0, Stop conversion */
        LulRegSGSTR = (LulRegSGSTR &
              (uint32)(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
      }
      else
      {
        /* No action */
      }
      /* Writing back the previously Trigger conversion */
      Adc_WriteBackRegforADConversion(LucHwUnit, LulRegSGCR,
                                LulRegSGSTR, ADC_CHANNELCOMPLETEMODE_API_ID);
      /* Check if critical section protection is required */
      #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit the critical section protection */
      ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
      #endif
    }
    #if (ADC_ENABLE_STREAMING == STD_ON)
    else
    {
      /* No action required */
    }
    #endif

    /* Reload the the result buffer pointer */
    LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;

    /* Initialize SG unit RAM data to a local pointer */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpSgUnitRamData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
    /* END Msg(4:0491)-5 */

    /* Check if the operation mode is continuous */
    if (ADC_GROUP_CONTINUOUS == (LpGroup->ucGroupSettings
                                                      & ADC_GROUP_CONV_MASK))
    {
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      if (ADC_FALSE == LblLimitCheckErrorFlag)
      #endif
      {
        /* Invoke notification function if enabled */
        if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
                              (NULL_PTR != LpGroup->pGroupNotificationPointer))
        {
          LpGroup->pGroupNotificationPointer();
        }
        else
        {
          /* No action required */
        }
      }
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      else
      {
        /* No action required */
      }
      #endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
    else /* ADC_CONV_MODE_ONESHOT / ADC_STREAM_BUFFER_LINEAR */
    {
      /*
       * Reading of the next channel is not required as the conversion
       * of the group is completed. Hence set flag to true to pop any
       * aborted/suspended group from queue.
       */
      LblPopGroupFrmQueue = ADC_TRUE;

      #if (ADC_ENABLE_STREAMING == STD_ON)
       /*
        * Check if it is linear buffer conversion and all samples are
        *  not complete
        */
      if (((ADC_GROUP_ACCESS_STREAMING ==
            (LpGroup->ucGroupSettings & ADC_GROUP_ACCESS_MASK))) &&
                                   (ADC_FALSE == LpGroupData->blSampleComp))
      {
        /*
         * Clear the flag indicating no group should be popped from queue
         * since streaming is not complete
         */
        LblPopGroupFrmQueue = ADC_FALSE;
        #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
        if (Adc_GucMaxSwTriggGroups > LddGroup)
        {
          /* Initiate conversion */
          ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTCR,
                             ADC_START_CONVERSION);
        }
        else
        {
          /* No action required */
        }
        #endif
      }
      else
      {
        /* No action required */
      }
      #endif /* #if (ADC_ENABLE_STREAMING == STD_ON) */
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      if (ADC_FALSE == LblLimitCheckErrorFlag)
      #endif
      {
        /* Invoke notification function if enabled */
        if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
                       (NULL_PTR != LpGroup->pGroupNotificationPointer))
        {
          LpGroup->pGroupNotificationPointer();
        }
        else
        {
          /* No action required */
        }
      }
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      else
      {
        /* No action required */
      }
      #endif
      #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

      /* Is Group Priority Enabled */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
      /* MISRA Violation: START Msg(4:2995)-13 */
      if ((ADC_TRUE == LblPopGroupFrmQueue) &&
          (Adc_GucMaxSwTriggGroups > LddGroup) &&
          (ADC_QUEUE_EMPTY != LpSgUnitRamData->ucQueueStatus))
      /* END Msg(4:2995)-13 */
      {
        #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        if (ADC_FALSE == LblLimitCheckErrorFlag)
        #endif
        {
          LucSgUnitIndex = LpGroup->ucSgUnitIndex;
          /* Fetch the highest priority group from the queue */
          LddGroup = Adc_PopFromQueue(LucSgUnitIndex);
          /* Set the SG unit status to busy */
          LpSgUnitRamData->blSgUnitStatus = ADC_TRUE;
          /* Initiate the group conversion */
          Adc_IsrConfigureGroupForConversion(LddGroup);
        }
        #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
          /* Set the flag to false, now on status can be checked
                                             with HW register */
          LpSgUnitRamData->blSgUnitStatus = ADC_FALSE;
        }
        #endif
      }
      else
      {
          /* Set the flag to false, now on status can be checked
                                             with HW register */
          LpSgUnitRamData->blSgUnitStatus = ADC_FALSE;
      }
      #else
      /* Set the flag to false, now on status can be checked with HW register */
      LpSgUnitRamData->blSgUnitStatus = ADC_FALSE;
      #endif /*
              * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
              *    ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
              *               (ADC_ENABLE_QUEUING == STD_ON)))
              */
    }
    if ((ADC_FALSE == LblPopGroupFrmQueue) &&
        (ADC_GROUP_ACCESS_STREAMING ==
                    (LpGroup->ucGroupSettings & ADC_GROUP_ACCESS_MASK)))
    {
      /* Check if the conversion of all the samples are completed */
      if (LpRunTimeData->ucSamplesCompleted !=
                                             LpRunTimeData->ucStreamingSamples)
      {
        /* MISRA Violation: START Msg(4:0488)-1 */
        /* Increment the result buffer by number of samples completed */
        LpRunTimeData->pBuffer = (LpRunTimeData->pBuffer +
                                            LpRunTimeData->ucSamplesCompleted);
        /* END Msg(4:0488)-1 */
      }
      else
      {
        /* Set the flag to false, now on status can be checked with HW
          register */
         LpSgUnitRamData->blSgUnitStatus = ADC_FALSE;
      }
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                              (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT))
    /* Check if external multiplexer is enabled for the group */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if ((ADC_TRUE == LpGroup->blExtMuxEnabled) &&
        (ADC_POLLING_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex].
                                                    enFunctionalityModeType))
    /* END Msg(4:0491)-5 */
    {
      /* Get the index of the SGm unit */
      /* Get the current virtual channel converted */
      LulVirtualChannel = LpAdcSGRegisters->ulSGVCSP;
      /* Get the next channel to be converted */
      LulVirtualChannel = (LulVirtualChannel + ADC_ONE);
      /* Set the virtual channel start pointer */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCSP,
                      LulVirtualChannel,
                      &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCSP);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCSP,
                      LulVirtualChannel, ADC_WV_MASK_SGVCSP,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
      /*
       * Set the virtual channel end pointer same as start because the
       * next channel will be started after the previous is completed
       */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCEP,
                      LulVirtualChannel,
                      &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCEP);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCEP,
                      LulVirtualChannel, ADC_WV_MASK_SGVCEP,
                      ADC_CHANNELCOMPLETEMODE_API_ID);
      /* Initiate conversion */
      ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTCR, ADC_START_CONVERSION);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No action required */
    }
    #endif
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || \
                                         (ADC_ENABLE_EXTERNAL_MUX == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_GroupCompleteMode
**
** Service ID           : NA
**
** Description          : This function is invoked from ADC ISR for servicing
**                        the groups configured in scan operation mode.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LucHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GpChannelToGroup,
**                        Adc_GpSgUnitRamData, Adc_GpRunTimeData,
**                        Adc_GpHwUnitConfig, Adc_GpSgUnitConfig
**
** Functions invoked    : Adc_PopFromQueue, Adc_IsrConfigureGroupForConversion
**
** Registers Used       : ADCAnECR, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnADCR,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR,  ADCAnTHER, ADCAnTHCR,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnSGSTCRx, ADCAnDIRj,
**                        ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnDRj, ADCAnVCRj,
**                        ICDMAm, ICADCAnIm, ADCAnULER
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_085 */
/* Implements ADC_ESDD_UD_001 */
/* Implements ADC_ESDD_UD_006 */
/* Implements ADC_ESDD_UD_166 */
FUNC(void, ADC_FAST_CODE) Adc_GroupCompleteMode(Adc_GroupType LddGroup,
                                                   uint8 LucHwUnit)
{
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpResultRegister;
  #if ((ADC_ERROR_SUPPORT == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #endif
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpBuffer;
  uint8 LucSgUnitIndex;
  uint8 LucChannelCount;
  uint8_least LucLoop;

  /* MISRA Violation: START Msg(4:0759)-2 */
  Adc_ConvertedVal LunConvertedValue;
  /* END Msg(4:0759)-2 */
  uint8 LucBufferOffset;
  uint32 LulRegWriteValue;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                 ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON)))
  boolean LblPopGroupFrmQueue;
  #endif
  #if ((ADC_SELF_DIAG_SUPPORT == STD_ON) || \
       (ADC_ENABLE_STREAMING == STD_ON))
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  boolean LblLimitCheckErrorFlag;
  LblLimitCheckErrorFlag = ADC_FALSE;
  #endif
  /*
   * Deleted the macro switch for variables definition,
   * Avoid compilation errors(variables is not used)
   * and add the following processing
   */
  LulRegWriteValue = ADC_DOUBLE_WORD_ZERO;
  /* MISRA Violation: START Msg(4:2983)-33 */
  LulRegWriteValue = LulRegWriteValue;
  /* END Msg(4:2983)-33 */
  #if ((ADC_SELF_DIAG_SUPPORT == STD_ON) || \
      (ADC_ENABLE_STREAMING == STD_ON))
  LulRegSGSTR = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_ZERO] = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_ONE] = ADC_DOUBLE_WORD_ZERO;
  LulRegSGCR[ADC_TWO] = ADC_DOUBLE_WORD_ZERO;
  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the hardware unit of the group */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* Read the group data pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* END Msg(4:0491)-5 */

  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* Get the SG unit which is configured for this group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  LucSgRegIndex = LpSgUnitConfig->ucSgRegIndex;
  /* Initialize SG unit RAM data to a local pointer */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Get the SG register address */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /*
   * Deleted the macro switch for variables definition,
   * Avoid compilation errors(variables is not used)
   * and add the following processing
   */
  /* MISRA Violation: START Msg(4:2983)-33 */
  LpAdcSGRegisters = LpAdcSGRegisters;
  /* END Msg(4:2983)-33 */
  /* Read the group's runtime data pointer */
  LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */

  /* Load the current group's first channel buffer pointer */
  LpBuffer = LpRunTimeData->pBuffer;

  /* Implements AR_PN0076_NR_0011 */
  /* Load number of channels configured for group */
  LucChannelCount = LpRunTimeData->ucChannelCount;

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the hardware unit index */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  /* Get the ADC register address */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /*
   * Deleted the macro switch for variables definition,
   * Avoid compilation errors(variables is not used)
   * and add the following processing
   */
  /* MISRA Violation: START Msg(4:2983)-33 */
  LpAdcRegisters = LpAdcRegisters;
  /* END Msg(4:2983)-33 */
  #if ((ADC_ERROR_SUPPORT == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
  /* END Msg(4:0491)-5 */
  #endif
  LpResultRegister = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
  for (LucLoop = ADC_ZERO; LucChannelCount > LucLoop; LucLoop++)
  {
    /* Read the channel's converted value */
    LunConvertedValue.ulValue = LpResultRegister->
                                 ulDIR[(LpGroup->ulStartVirChPtr + LucLoop)];
    /* Read the offset of the buffer for normal mode */
    LucBufferOffset = (uint8)LucLoop;

    #if (ADC_ENABLE_STREAMING == STD_ON)
    /* Check if the group is configured in streaming access mode */
    if (ADC_GROUP_ACCESS_STREAMING == (LpGroup->ucGroupSettings &
                                                  ADC_GROUP_ACCESS_MASK))
    {
      /*
       * Read the offset for the buffer pointer based on
       * number of channels and completed samples.
       */
      LucBufferOffset = (LucBufferOffset * LpRunTimeData->ucStreamingSamples);
    }
    else
    {
      /* No action required */
    }
    #endif

    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    #if (ADC_ERROR_SUPPORT == STD_ON)
    if (ADC_FALSE == LpHwUnitConfig->blInterruptErr)
    #endif
    {
      if (ADC_FALSE == LpGroup->blLimitCheckEnabled)
      {
        /* Copy the converted value to the internal buffer */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpBuffer[LucBufferOffset] = LunConvertedValue.DWord.usLoWord;
        /* END Msg(4:0491)-5 */
      }
      else if (ADC_NO_LIMIT_ERROR == (LpAdcRegisters->ulULER &
                                             ADC_UE_LE_LIMIT_CHK_ERROR))
      {
        /* Copy the converted value to the internal buffer */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpBuffer[LucBufferOffset] = LunConvertedValue.DWord.usLoWord;
        /* END Msg(4:0491)-5 */
      }
      else
      {
        /*
         * Since the digital value is not within the specified range for channel
         * configured for this group, the out of range digital values are not
         * not copied to application buffer.
         */
        LblLimitCheckErrorFlag = ADC_TRUE;
        /*
         * Update ADCAnECR register to clear the error flags,
         * so that on next iteration previous error is not reflected
         */
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

        /* END Msg(4:3138)-22 */
      }
    }
    #if (ADC_ERROR_SUPPORT == STD_ON)
    else
    {
      /* Copy the converted value to the internal buffer */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpBuffer[LucBufferOffset] = LunConvertedValue.DWord.usLoWord;
      /* END Msg(4:0491)-5 */
    }
    #endif
    #else
    /* Copy the converted value to the internal buffer */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpBuffer[LucBufferOffset] = LunConvertedValue.DWord.usLoWord;
    /* END Msg(4:0491)-5 */
    #endif
  }
  /* Check if the conversion of all the samples are completed */
  if (LpRunTimeData->ucSamplesCompleted == LpRunTimeData->ucStreamingSamples)
  {
    LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
  }
  else
  {
     /* No action required */
  }
  /* Update the completed conversion samples */
  LpRunTimeData->ucSamplesCompleted++;
  #if (ADC_ENABLE_STREAMING == STD_ON)
  /* Check if the result access mode is Single */
  if (ADC_GROUP_ACCESS_SINGLE == (LpGroup->ucGroupSettings
                                                   & ADC_GROUP_ACCESS_MASK))
  #endif
  {
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if (ADC_FALSE == LblLimitCheckErrorFlag)
    #endif
    {
      /* Set group status as conversion completed */
      LpGroupData->enGroupStatus = ADC_STREAM_COMPLETED;
      #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
      /* Check the group is configured as Continuous conversion mode */
      if ((ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
                                      && (Adc_GucMaxSwTriggGroups > LddGroup))
      {
        /* Check if critical section protection is required */
        #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter the critical section protection */
        ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
        #endif
        /* Buffer the status of SGSTR and halt AD conversion */
        Adc_SaveRegAndHaltADConversion(LucHwUnit, LulRegSGCR,
                                   &LulRegSGSTR, ADC_GROUPCOMPLETEMODE_API_ID);
        #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
        if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
              (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
        {
          /* Disable self-diag voltage level selection */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                       ADC_SELF_DIAG_VLTG_DISABLE,
                       &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                       ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                       ADC_GROUPCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
          if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
          {
            /* Disable self-diag voltage level selection */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                       ADC_SELF_DIAG_VLTG_DISABLE,
                       &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                       ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                       ADC_GROUPCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          else
          {
             /* To avoid MISRA violation */
          }

          /* Disable the self diag functionality support */
          LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                        LulRegWriteValue,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                        LulRegWriteValue, ADC_WV_MASK_ADCR,
                        ADC_GROUPCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        /* group is configured as normal group */
        else
        {
          /* No action required */
        }
        #endif

        #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
        /* check the group is configured in the open pin self diag support */
        if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
        {
          /* Implements AR_PN0076_FSR_0002 */
          /* Disable on-chip pull-down resistor */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                         ADC_DISABLE_PULL_DOWN_RESISTOR,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                         ADC_GROUPCOMPLETEMODE_API_ID);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                         ADC_DISABLE_PULL_DOWN_RESISTOR,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                         ADC_GROUPCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        /* group is configured as normal group */
        else
        {
          /* No action required */
        }
        #endif
        #if (ADC_TRACK_AND_HOLD == STD_ON)
        /* Check if group is configured with Track and Hold enabled channel */
        if (ADC_TRUE == LpGroup->blTandHEnable)
        {
          /* Stop sampling of all the Track and Hold channels */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR);
          /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Un Map the channels to group A or B */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Disable the channels configured for Track and Hold functionality */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Disable to perform automatic sampling */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        else
        {
          /* To avoid MISRA violation */
        }
        #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */
        /* Don't start conversion, if group status is ADC_STREAM_COMPLETED *
         * and not continuous conversion mode.                             */
        if((ADC_STREAM_COMPLETED == LpGroupData->enGroupStatus)
                   && (ADC_GROUP_CONTINUOUS != (LpGroup->ucGroupSettings
                                               & ADC_GROUP_CONV_MASK)))
        {
          /* Set applicable SGACT of buffer to 0, Stop conversion */
          LulRegSGSTR = (LulRegSGSTR &
                (uint32)(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
        }
        else
        {
          /* No action */
        }
        /* Writing back the previously Trigger conversion */
        Adc_WriteBackRegforADConversion(LucHwUnit, LulRegSGCR,
                                    LulRegSGSTR, ADC_GROUPCOMPLETEMODE_API_ID);
        /* Check if critical section protection is required */
        #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit the critical section protection */
        ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
        #endif
      }
      else
      {
        /* No action required */
      }
      #endif
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Invoke notification function if enabled */
      if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
        (NULL_PTR != LpGroup->pGroupNotificationPointer))
      {
        LpGroup->pGroupNotificationPointer();
      }
      else
      {
        /* No action required */
      }
      #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
      /* No action required */
    }
    #endif
    /* Check if the conversion mode is continuous */
    if (ADC_GROUP_CONTINUOUS ==
                (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
    {
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                  ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                              (ADC_ENABLE_QUEUING == STD_ON)))
      LblPopGroupFrmQueue = ADC_FALSE;
      #endif
    }
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
    else /* ADC_CONV_MODE_ONESHOT */
    {
      LblPopGroupFrmQueue = ADC_TRUE;
    }
    #endif
  }
  #if (ADC_ENABLE_STREAMING == STD_ON)
  else /* ADC_ACCESS_MODE_STREAMING */
  {
    /* Update the buffer pointer to point to the next sample */
    /* MISRA Violation: START Msg(4:0489)-12 */
    (LpRunTimeData->pBuffer)++;
    /* END Msg(4:0489)-12 */
    /* Check if the conversion of all the samples are completed */
    if (LpRunTimeData->ucStreamingSamples == LpRunTimeData->ucSamplesCompleted)
    {
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      if (ADC_FALSE == LblLimitCheckErrorFlag)
      #endif
      {
        /* Set group status as conversion completed */
        LpGroupData->enGroupStatus = ADC_STREAM_COMPLETED;
        /*
         * Set the flag indicating Adc_ReadGroup or Adc_GetStreamLastPointer
         * should be called
         */
        LpGroupData->blResultRead = ADC_FALSE;
        /* Check if critical section protection is required */
        #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter the critical section protection */
        ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
        #endif
        /* Buffer the status of SGSTR and halt AD conversion */
        Adc_SaveRegAndHaltADConversion(LucHwUnit, LulRegSGCR,
                                  &LulRegSGSTR, ADC_GROUPCOMPLETEMODE_API_ID);
        #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
        /* Check the group is configured as Continuous conversion mode */
        if ((ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
                                        && (Adc_GucMaxSwTriggGroups > LddGroup))
        {
          #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
          if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
                (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
          {
            /* Disable self-diag voltage level selection */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                         ADC_SELF_DIAG_VLTG_DISABLE,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                         ADC_GROUPCOMPLETEMODE_API_ID);
            if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
            {
              /* Disable self-diag voltage level selection */
              ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                         ADC_SELF_DIAG_VLTG_DISABLE,
                         &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
              ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                         ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                         ADC_GROUPCOMPLETEMODE_API_ID);
              /* END Msg(4:3138)-22 */
            }
            else
            {
               /* To avoid MISRA violation */
            }

            /* Disable the self diag functionality support */
            LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                          LulRegWriteValue,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                          LulRegWriteValue, ADC_WV_MASK_ADCR,
                          ADC_GROUPCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          /* group is configured as normal group */
          else
          {
            /* No action required */
          }
          #endif

          #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
          /* check the group is configured in the open pin self diag support */
          if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
          {
            /* Implements AR_PN0076_FSR_0002 */
            /* Disable on-chip pull-down resistor */
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                          ADC_DISABLE_PULL_DOWN_RESISTOR,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                          ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                          ADC_GROUPCOMPLETEMODE_API_ID);
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                          ADC_DISABLE_PULL_DOWN_RESISTOR,
                          &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                          ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                          ADC_GROUPCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */

            /* Disable the self diag functionality support */
            LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
            /* MISRA Violation: START Msg(4:3138)-22 */
            ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR,
                        LulRegWriteValue,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
            ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                        LulRegWriteValue, ADC_WV_MASK_ADCR,
                        ADC_GROUPCOMPLETEMODE_API_ID);
            /* END Msg(4:3138)-22 */
          }
          /* group is configured as normal group */
          else
          {
            /* No action required */
          }
          #endif
        }
        else
        {
          /* No action required */
        }
        #endif
        #if (ADC_TRACK_AND_HOLD == STD_ON)
        /* Check if group is configured with Track and Hold enabled channel */
        if (ADC_TRUE == LpGroup->blTandHEnable)
        {
          /* Stop sampling of all the Track and Hold channels */
          ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR);
          /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
          /* MISRA Violation: START Msg(4:3138)-22 */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Un Map the channels to group A or B */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Disable the channels configured for Track and Hold functionality */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* Disable to perform automatic sampling */
          ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                      ADC_TRACK_AND_HOLD_REG_CLEAR,
                      &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
          ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                      ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                      ADC_GROUPCOMPLETEMODE_API_ID);
          /* END Msg(4:3138)-22 */
        }
        else
        {
          /* To avoid MISRA violation */
        }
        #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */
        /* Don't start conversion, if group status is ADC_STREAM_COMPLETED *
        * and not continuous conversion mode.                             */
        if((ADC_STREAM_COMPLETED == LpGroupData->enGroupStatus)
                   && (ADC_GROUP_CONTINUOUS != (LpGroup->ucGroupSettings
                                               & ADC_GROUP_CONV_MASK)))
        {
          /* Set applicable SGACT of buffer to 0, Stop conversion */
          LulRegSGSTR = (LulRegSGSTR &
                (uint32)(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
        }
        else
        {
          /* No action */
        }
        /* Writing back the previously Trigger conversion */
        Adc_WriteBackRegforADConversion(LucHwUnit, LulRegSGCR,
                                  LulRegSGSTR, ADC_GROUPCOMPLETEMODE_API_ID);
        /* Check if critical section protection is required */
        #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit the critical section protection */
        ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
        #endif
        #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        /* Invoke notification function if enabled */
        if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
          (NULL_PTR != LpGroup->pGroupNotificationPointer))
        {
          LpGroup->pGroupNotificationPointer();
        }
        else
        {
          /* No action required */
        }
        #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
      }
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      else
      {
        /* No action required */
      }
      #endif
      /* Check if the conversion mode is circular buffer */
      if (ADC_GROUP_CONTINUOUS ==
                (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
      {
        LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
        LblPopGroupFrmQueue = ADC_FALSE;
        #endif
      }
      else /* ADC_STREAM_BUFFER_LINEAR */
      {
        /* Check if the group is configured for hardware trigger */
        if (Adc_GucMaxSwTriggGroups <= LddGroup)
        {
          /* Reset the buffer pointer */
          LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
        }
        else
        {
          /* No action required */
        }
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
        LblPopGroupFrmQueue = ADC_TRUE;
        #endif
      }
    }
    else /* All samples not completed */
    {
      /* Check if the last streaming values were read */
      if (ADC_TRUE == LpGroupData->blResultRead)
      {
        /* Set group status as conversion completed */
        LpGroupData->enGroupStatus = ADC_COMPLETED;
      }
      else
      {
        /* No action required */
      }
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
      /* Conversion of the group is not completed */
      LblPopGroupFrmQueue = ADC_FALSE;
      #endif
      /* Check if the conversion mode is linear buffer */
      if ((ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
            && (Adc_GucMaxSwTriggGroups > LddGroup))
      {
        /* Initiate conversion */
        /* MISRA Violation: START Msg(4:3138)-22 */
        ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTCR, ADC_START_CONVERSION);
        /* END Msg(4:3138)-22 */
      }
      else
      {
        /* No action required */
      }
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      /* Invoke notification function if enabled */
      if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
          (NULL_PTR != LpGroup->pGroupNotificationPointer) &&
          (ADC_FALSE == LblLimitCheckErrorFlag))
      #else
      if ((ADC_TRUE == LpGroupData->ucNotifyStatus) &&
                     (NULL_PTR != LpGroup->pGroupNotificationPointer))
      #endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      {
        LpGroup->pGroupNotificationPointer();
      }
      else
      {
        /* No action required */
      }
      #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
  }
  #endif /* #if (ADC_ENABLE_STREAMING == STD_ON) */
  /*
   * If Group Priority Enabled or the first come first serve mechanism is
   * enabled
   */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Check if the completed group conversion mode is oneshot */
  if ((ADC_TRUE == LblPopGroupFrmQueue) &&
                                         (ADC_FALSE == LblLimitCheckErrorFlag))
  #else
  if (ADC_TRUE == LblPopGroupFrmQueue)
  #endif
  {
    /* Check if the queue is not empty */
    if (ADC_QUEUE_EMPTY != LpSgUnitData->ucQueueStatus)
    {
      /* Set the SG unit status to busy */
      LpSgUnitData->blSgUnitStatus = ADC_TRUE;
      /*
       * Fetch the highest priority group from the queue and
       * initiate the group conversion
       */
      Adc_IsrConfigureGroupForConversion
                                  (Adc_PopFromQueue(LpGroup->ucSgUnitIndex));
    }
    else
    {
      /* Set the flag to false, now on status can be checked with HW register */
      LpSgUnitData->blSgUnitStatus = ADC_FALSE;
    }
  }
  else
  {
    /* Set the flag to false, now on status can be checked with HW register */
    LpSgUnitData->blSgUnitStatus = ADC_FALSE;
  }
  #else
  /* Set the flag to false, now on status can be checked with HW register */
  LpSgUnitData->blSgUnitStatus = ADC_FALSE;
  #endif

  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON))
  /* Implements AR_PN0076_FR_0209 */
  /* Check if external multiplexer is enabled for the group */
  if ((ADC_TRUE == LpGroup->blExtMuxEnabled) &&
                (ADC_GROUP_CONTINUOUS == (LpGroup->ucGroupSettings &
                                              ADC_GROUP_CONV_MASK)))
  {
    /*  Set the flag to true */
    LpSgUnitData->blSgUnitStatus = ADC_TRUE;
    /* Set the virtual channel start pointer */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCSP,
                    LpGroup->ulStartVirChPtr,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCSP);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCSP,
                    LpGroup->ulStartVirChPtr, ADC_WV_MASK_SGVCSP,
                    ADC_GROUPCOMPLETEMODE_API_ID);
    /* END Msg(4:3138)-22 */
    /*
     * Set the virtual channel end pointer same as start because the
     * next channel will be started after the previous is completed
     */
    LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                         ((uint32)LucChannelCount - ADC_ONE));
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCEP,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCEP);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCEP,
                    LulRegWriteValue, ADC_WV_MASK_SGVCEP,
                    ADC_GROUPCOMPLETEMODE_API_ID);
    /* Initiate conversion */
    ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTCR, ADC_START_CONVERSION);
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No action required */
  }
  #endif/*
          * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
          *     ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
          *                   (ADC_ENABLE_QUEUING == STD_ON)))
          */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_ConfigureGroupForConversion
**
** Service ID           : NA
**
** Description          : This function configures the requested group for
**                        conversion.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpSgUnitRamData,
**                        Adc_GpGroupRamData, Adc_GpChannelToGroup,
**                        Adc_GpDmaUnitConfig, Adc_GucMaxSwTriggGroups,
**                        Adc_GpHwUnitConfig, Adc_GpLimitCheckRange,
**                        Adc_GpSgUnitConfig
**
** Functions invoked    : Adc_IcrInterruptBit, Adc_ClearPendingInterrupt,
**                        Adc_HaltADConversion
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx,ADCAnSGCRx, DCENm, DCSTCm,
**                        DDAm, DTCm, DRSAm, DRDAm, DRTCm, DSAm, DTCTm,
**                        ADCAnADCR, ADCAnDGCTL0,  ADCAnDGCTL1, ICDMAm,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx, ADCAnVCRj,
**                        ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR, ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR, ADCAnSGSTCRx,
**                        ICADCAnIm, DCSTm
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_086 */
/* Implements ADC_ESDD_UD_001 */
/* Implements ADC_ESDD_UD_214 */
FUNC(void, ADC_PRIVATE_CODE) Adc_ConfigureGroupForConversion(
                                                 Adc_GroupType LddGroup)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  #endif
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpVirChannel;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  uint8 LucChannelToGroupIndex;
  uint8 LucLoopCount;
  uint8 LucDisableChannelCount;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  uint8 LucDataRegisterIndex;
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ADC_CONFIG_DATA) LpDmaIntpCntrlReg;
  #endif
  #endif
  uint32 LulRegValues;
  uint8 LucHwUnit;
  #if (((ADC_DMA_MODE_ENABLE == STD_ON) && \
        (ADC_FUNCTIONALITY_MODE != ADC_POLLING)) || \
       (ADC_TRACK_AND_HOLD == STD_ON) || \
       (ADC_FUNCTIONALITY_MODE != ADC_POLLING))
  uint8 LucSgUnitId;
  #endif
  uint8 LucSgUnitIndex;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  uint8 LucChannelCount;
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  uint8 LucMaxLimitcheck;
  uint8 LucLimitCheckIndex;
  uint8 LucLimitLoopCount;
  #endif

  #if ((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                 (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON))

  volatile uint32 LusSelfDiagDelayCount;
  #endif

  uint32 LulRegWriteValue;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* Read the hardware unit of the group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  LucHwUnit = LpGroup->ucHwUnitIndex;
  /* Initialize HW RAM data to a local pointer */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Initialize Group RAM data to a local pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Read the group data pointer */
  LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Get the no of channels configured for the requested group */
  LucChannelCount = (LpGroup->ucChannelCount - LpGroupData->ucNoofChDisabled);
  #else
  /* Get the no of channels configured for the requested group */
  LucChannelCount = LpGroup->ucChannelCount;
  #endif
  /* Initialize the number of channels present in the group */
  LpRunTimeData->ucChannelCount = LucChannelCount;
  /* Read the number of samples configured for that group */
  LpRunTimeData->ucStreamingSamples = LpGroup->ddNumberofSamples;

  /* Initialize the number of converted channels to zero */
  LpRunTimeData->ucChannelsCompleted = ADC_ZERO;

  /* Initialize the streaming samples counter */
  LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
  /* Initialize the group's buffer pointer */
  LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
  /* Clear the flag indicating all the samples are not completed */
  LpGroupData->blSampleComp = ADC_FALSE;
  /* Set the flag indicating Group is not read so far */
  LpGroupData->blResultRead = ADC_TRUE;

  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Is the group HW triggered */
  if (Adc_GucMaxSwTriggGroups <= LddGroup)
  {
    /* Set the RAM variable indicating current group active in HW unit is HW */
    LpSgUnitData->enTrigSource = ADC_TRIGG_SRC_HW;
  }
  else
  {
    /* Set the RAM variable indicating current group active in HW unit is SW */
    LpSgUnitData->enTrigSource = ADC_TRIGG_SRC_SW;
  }
  #endif
  /* Read the user base configuration address of the hardware unit */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  #if (((ADC_DMA_MODE_ENABLE == STD_ON) && \
        (ADC_FUNCTIONALITY_MODE != ADC_POLLING)) || \
       (ADC_TRACK_AND_HOLD == STD_ON) || \
       (ADC_FUNCTIONALITY_MODE != ADC_POLLING))
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the SG unit Id to which this group is mapped */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(4:0491)-5 */
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get SG unit index */
  LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
  /* END Msg(4:0491)-5 */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];

  /* Buffer the status of SGSTR */
  /* MISRA Violation: START Msg(2:2814)-27 */
  LulRegSGSTR = LpAdcRegisters->ulSGSTR;
  /* END Msg(2:2814)-27 */
  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegSGCR[ADC_SG1] =
                 Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegSGCR[ADC_SG2] =
                 Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegSGCR[ADC_SG3] =
                 Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */

  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
  Adc_HaltADConversion(LucHwUnitIndex);

  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  if (ADC_TRUE == LpGroup->blLimitCheckEnabled)
  {
    /*
     * Update ADCAnECR register to clear the error flags,
     * so that on next iteration previous error is not reflected
     */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

    /* END Msg(4:3138)-22 */
    LucMaxLimitcheck = LpGroup->ucMaxLimitcheck;
    LucLimitCheckIndex = LpGroup->ucLimitCheckIndex;
    #if (ADC_FLEXIBLE_THRESHOLD == STD_ON)
    for (LucLimitLoopCount = ADC_ZERO; LucMaxLimitcheck > LucLimitLoopCount;
                                                        LucLimitLoopCount++)
    {
      /* Implements AR_PN0076_FR_0032 */
      /* Load the upper limit for error check */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      if (LucLimitLoopCount > ADC_TWO)
      {
        LpRegWrite = &LpAdcRegisters->ulULLMTBR2
                                      [LucLimitLoopCount - ADC_ULLMTBR2_OFSET];
      }
      else
      {
        LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      }
      #else
      LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      #endif
      LulRegWriteValue = Adc_GpFlexibleLimitCheckRange[LucLimitCheckIndex +
                                                       LucLimitLoopCount];
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].
                    ulULLMTBR[LucLimitLoopCount]);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                    LulRegWriteValue, ADC_WV_MASK_ULLMTBR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
    }
    #else
    for (LucLimitLoopCount = ADC_ZERO; LucMaxLimitcheck > LucLimitLoopCount;
                                                        LucLimitLoopCount++)
    {
      /* Implements AR_PN0076_FR_0032 */
      /* Load the upper limit for error check */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      if (LucLimitLoopCount > ADC_TWO)
      {
       LpRegWrite = &LpAdcRegisters->ulULLMTBR2
                                      [LucLimitLoopCount - ADC_ULLMTBR2_OFSET];
      }
      else
      {
        LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      }
      #else
      LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      #endif

      LulRegWriteValue = Adc_GpLimitCheckRange[LucLimitCheckIndex +
                                               LucLimitLoopCount];
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].
                    ulULLMTBR[LucLimitLoopCount]);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                    LulRegWriteValue, ADC_WV_MASK_ULLMTBR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
    }
    #endif
  }
  else
  {
    /* No actions Required */
  }
  #endif

  /* Configure the hardware unit with the group's operation mode */
  LulRegValues =
        Adc_GaaOperationMask[(LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK)];
  /* Update to generate output when the scan for SGx ends */
  LulRegValues = (LulRegValues | ADC_INT_SG_END);
  /* Load the SGCRx register */
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Implements AR_PN0076_FR_0209 */
  /* check weather the group is enabled for external mux */
  if (ADC_TRUE ==  LpGroup->blExtMuxEnabled)
  {
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* Set the end interrupt enable bit and Disable the continuous conversion */
    LulRegWriteValue = ((LulRegValues) & ((ADC_MUX_GROUP) |
                           (~(LpGroup->ucGroupSettings << ADC_THREE))));
    /* END Msg(4:4397)-8 */
  }
  else
  {
    LulRegWriteValue = LulRegValues;
  }
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                    LulRegWriteValue, ADC_WV_MASK_SGCR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  /* Set applicable TRGMD of SGCR */
  LulRegSGCR[LucSgRegIndex-LucSGOffset] = LulRegWriteValue;
  #else
    LulRegWriteValue = LulRegValues;
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                    LulRegWriteValue, ADC_WV_MASK_SGCR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* Set applicable TRGMD of SGCR */
    LulRegSGCR[LucSgRegIndex-LucSGOffset] = LulRegWriteValue;
  #endif

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  LpSgUnitData->ddCurrentPriority = LpGroup->ddGroupPriority;
  #endif
  /* Update the hardware unit ram data with the current group information */
  LpSgUnitData->ddCurrentConvGroup = LddGroup;

  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  if (ADC_GROUP_DMA_ACCESS == (LpGroup->ucGroupSettings &
                                                ADC_GROUP_RESULT_ACCESS_MASK))
  {
    /* Implements AR_PN0076_FR_0066 */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LpSgUnitConfig->ucDmaChannelIndex];
    /* END Msg(4:0491)-5 */
    LucDataRegisterIndex = LpSgUnitConfig->ucDataRegisterIndex;
    LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
    LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
    /* Clear DMA channel suspension */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DISABLE_DMA_TRANSFER);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCEN,
                              ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCEN,
                              ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* Clear Transfer Status flag */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCSTC, ADC_TRANSFER_FLAG_CLEAR);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCST,
                              ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCST_CLEAR,
                              ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* Load source register*/
    /* MISRA Violation: START Msg(4:0303)-4 */
    LulRegWriteValue = (uint32)&(Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex]->
                              usDR[LucDataRegisterIndex]);
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDSA, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDSA,
                              LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                              ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0303)-4 */
    /* MISRA Violation: START Msg(4:0306)-20 */
    /* Load destination register */
    LulRegWriteValue = (uint32)LpRunTimeData->pBuffer;
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDDA, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0306)-20 */
    /* Load the transfer count value to the DMA register */
    LulRegWriteValue = ((uint32)LucChannelCount -
                                 (uint32)LpRunTimeData->ucChannelsCompleted);
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDTC, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDTC,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

    /* Load Reload source register */
    /* MISRA Violation: START Msg(4:0303)-4 */
    LulRegWriteValue = (uint32)&(Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex]->
                                                usDR[LucDataRegisterIndex]);
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRSA, LulRegWriteValue,
                    &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRSA);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRSA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0303)-4 */
    /* Load Reload destination register*/
    /* MISRA Violation: START Msg(4:0306)-20 */
    LulRegWriteValue = (uint32)LpRunTimeData->pBuffer;
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRDA,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRDA);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRDA,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0306)-20 */
    /* Load the transfer count value to the DMA register */
    LulRegWriteValue = ((uint32)LucChannelCount -
                                     LpRunTimeData->ucChannelsCompleted);
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRTC,
                    LulRegWriteValue,
                    &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRTC);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRTC,
                    LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* Load the source address of data register which is allocated for the
    * SG unit
    */
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT,
                  ADC_DTCT_REGISTER_VALUE,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDTCT,
                  ADC_DTCT_REGISTER_VALUE, ADC_WV_MASK_DTCT,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* If the group is continuous or HW triggered group */
    if ((ADC_GROUP_CONTINUOUS ==
                             (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
    #if (ADC_HW_TRIGGER_API == STD_ON)
    || (LddGroup >= Adc_GucMaxSwTriggGroups)
    #endif
    )
    {
      /* Set the LE bit for continuous data transfer */
      LulRegWriteValue =
                 ((uint32)(LpDmaRegisters->ulDTCT | ADC_DMA_CONTINUOUS));
    }
    else
    {
      /* Clear the LE bit for continuous data transfer */
      LulRegWriteValue = ((uint32)(LpDmaRegisters->ulDTCT & ADC_DMA_ONCE));
    }
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT, LulRegWriteValue,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDTCT,
                  LulRegWriteValue, ADC_WV_MASK_DTCT,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
    /* Check if the Group is mapped for HW configured for interrupt mode */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                       .enFunctionalityModeType)
    /* END Msg(4:0491)-5 */
    {
      /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0023 */
      /* Enable the DMA interrupt control register */
      /* MISRA Violation: START Msg(4:0316)-21 */
      RH850_SV_MODE_ICR_AND (16, (LpSGmDmaConfig->pIntCntlReg),
                                         ADC_CLEAR_INT_REQUEST_FLAG);
      RH850_SV_MODE_ICR_AND (16, (LpSGmDmaConfig->pIntCntlReg),
                                         ADC_INTERRUPT_MASK_EN);
      /* END Msg(4:0316)-21 */
      /* Disable the interrupt for the SGm unit to which the group is mapped */
      Adc_IcrInterruptBit(LucSgUnitIndex, ADC_DISABLE_INTERRUPT);

      /*
       * Clear the pending interrupt for the SGm unit to which the
       * group is mapped
       */
      Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)*/
    /* DMA transfer enable */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DMA_ENABLE);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCEN,
                      ADC_DMA_ENABLE, ADC_WV_MASK_DCEN,
                      ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  else
  #endif   /*#if (ADC_DMA_MODE_ENABLE == STD_ON) */
  {
    #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
    /* Check if the Group is mapped for HW configured for interrupt mode */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                       .enFunctionalityModeType)
    /* END Msg(4:0491)-5 */
    {
      #if (ADC_DMA_MODE_ENABLE == STD_ON)
      if (ADC_NO_DMA_CHANNEL_INDEX != LpSgUnitConfig->ucDmaChannelIndex)
      {
        /* Get the pointer to the DMA configuration */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpSGmDmaConfig =
                        &Adc_GpDmaUnitConfig[LpSgUnitConfig->ucDmaChannelIndex];
        /* END Msg(4:0491)-5 */
        /*
         * Disable the DMA interrupt for the DMA channel Id configured
         * for the SGm unit in which the group is mapped
         */
        /* MISRA Violation: START Msg(4:0317)-19 */
        LpDmaIntpCntrlReg = LpSGmDmaConfig->pIntCntlReg;
        /* END Msg(4:0317)-19 */
        /* MISRA Violation: START Msg(4:4397)-8 */
        /* Disable the DMA channel interrupt */
        RH850_SV_MODE_ICR_OR (16, (LpDmaIntpCntrlReg), ADC_INTERRUPT_MASK_DIS);
        /* END Msg(4:4397)-8 */

      }
      else
      {
        /* No action required */
      }
      #endif
      /*
       * Clear the pending interrupt for the SGm unit to which the
       * group is mapped
       */
      Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
      /* Enable the interrupt for the SGm unit to which the group is mapped */
      Adc_IcrInterruptBit(LucSgUnitIndex, ADC_ENABLE_INTERRUPT);
    }
    else
    {
      /* To avoid misra violation */
    }
    #endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */
  }

  #if (ADC_SELF_DIAG_SUPPORT == STD_ON)

  #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
  /* Check the group is configured as self diag Circuit conversion
     or in self diag MUX conversion  */
  if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
                     (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
  {
    /* Turn ON self-diagnostic voltage circuit */
    /* MISRA Violation: START Msg(4:3138)-22 */
    LulRegWriteValue = (LpAdcRegisters->ulADCR | ADC_ENABLE_SELF_DIAG);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                    LulRegWriteValue, ADC_WV_MASK_ADCR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* initialize the delay loop count to zero */
    LusSelfDiagDelayCount = ADC_ZERO;
    /* wait for the specified time period */
    /* QAC Warning: START Msg(2:3416)-23 */
    while (ADC_SELF_DIAG_DELAY_COUNT != LusSelfDiagDelayCount)
    /* END Msg(2:3416)-23 */
    {
      LusSelfDiagDelayCount++;
    }

    /* Implements AR_PN0076_FSR_0004 */
    /* configure the reference voltage */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                  LpGroup->ulAdcSelfDiagVolLevSel,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                  LpGroup->ulAdcSelfDiagVolLevSel, ADC_WV_MASK_DGCTL0,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

    /* update the self diag voltage level */
    LulRegWriteValue = (LpAdcRegisters->ulADCR | ADC_ENABLE_SELF_DIAG);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                    LulRegWriteValue, ADC_WV_MASK_ADCR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* initialize the delay loop count to zero */
    LusSelfDiagDelayCount = ADC_ZERO;
    /* wait for the specified time period */
    /* QAC Warning: START Msg(2:3416)-23 */
    while (ADC_SELF_DIAG_DELAY_COUNT != LusSelfDiagDelayCount)
    /* END Msg(2:3416)-23 */
    {
      LusSelfDiagDelayCount++;
    }
    if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
    {
      /* configure the channel to be connected  */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                    LpGroup->ulAdcSelfDiagChannelSel,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                    LpGroup->ulAdcSelfDiagChannelSel, ADC_WV_MASK_DGCTL1,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No action required */
    }
  }
  /* group is configured as normal group */
  else
  {
    /* Turn OFF self-diagnostic voltage circuit */
    LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                    LulRegWriteValue, ADC_WV_MASK_ADCR,
                    ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* disconnect diag voltage selection */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                  ADC_SELF_DIAG_VLTG_DISABLE,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* Select ANInm as input */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                  ADC_SELF_DIAG_VLTG_DISABLE,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  #endif

  #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
  /* check the group is configured in the open pin self diag support */
  if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
  {
    /* Implements AR_PN0076_FSR_0002 */
    /*  configure the channels selected for open pin functionality support
        by setting 1 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                LpGroup->ulAdcSelfDiagOpenPin1,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                LpGroup->ulAdcSelfDiagOpenPin1, ADC_WV_MASK_PDCTL1,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                LpGroup->ulAdcSelfDiagOpenPin2,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                LpGroup->ulAdcSelfDiagOpenPin2, ADC_WV_MASK_PDCTL2,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  }
  /* group is configured as normal group */
  else
  {
    /* Implements AR_PN0076_FSR_0002 */
    /* Disconnect on-chip pull-down resistor */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  #endif
  #endif
  /* Set the virtual channel start pointer */
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCSP,
                LpGroup->ulStartVirChPtr,
                &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCSP);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCSP,
                LpGroup->ulStartVirChPtr, ADC_WV_MASK_SGVCSP,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  #if ((ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT) && \
                      (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
  /* MISRA Violation: START Msg(4:0491)-5 */
  if (ADC_POLLING_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                       .enFunctionalityModeType)
  /* END Msg(4:0491)-5 */
  {
    /* Check if group is configured with external multiplexed channel */
    if ((ADC_TRUE == LpGroup->blExtMuxEnabled) &&
               (ADC_ZERO != (LpGroup->ucGroupSettings &
                                 ADC_GROUP_REPLACEMENT_MASK)))
    {
      /*
       * Set the virtual channel end pointer value same as start because the
       * next channel will be started after the previous is completed
       */
      LulRegWriteValue = LpGroup->ulStartVirChPtr;
    }
    else
    {
      /* Set the virtual channel end pointer value */
      LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                           ((uint32)LucChannelCount - ADC_ONE));
    }
  }
  else
  #endif /*
          * #if ((ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT) && \
          *           (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
          */
  {
    /* Set the virtual channel end pointer value*/
    LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                          ((uint32)LucChannelCount - ADC_ONE));
  }
  /* Write the virtual channel end pointer value to register */
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCEP,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCEP);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCEP,
                LulRegWriteValue, ADC_WV_MASK_SGVCEP,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /*
   * Initialize the virtual channels with the channel groups configured for
   * requested group.
   */

  /* Get group index of 1st channel, configured for the requested group */
  LucChannelToGroupIndex = LpGroup->ucChannelToGroupIndex;
  /* Re-Initialize the channel count to actual configured no of channels */
  LucChannelCount = LpGroup->ucChannelCount;
  /* Map the physical channels to the virtual channels */
  LucLoopCount = ADC_ZERO;
  LucDisableChannelCount = ADC_ZERO;
  while ((LucLoopCount+LucDisableChannelCount) < LucChannelCount)
  {
    #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_TRUE == Adc_GpChannelToDisableEnable[LucChannelToGroupIndex])
    /* END Msg(4:0491)-5 */
    #endif /* #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON) */
    {
      LpVirChannel = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
      #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && \
                                             (ADC_FLEXIBLE_THRESHOLD == STD_ON))
      if (ADC_TRUE == LpGroup->blLimitCheckEnabled)
      {
        /* Map the physical channels to the virtual channels */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRegWrite = &LpVirChannel->ulVCR[LpGroup->ulStartVirChPtr +
                                         LucLoopCount];
        LulRegWriteValue = Adc_GpFlexibleChannelToGroup[LucChannelToGroupIndex];
        /* END Msg(4:0491)-5 */
      }
      else
      #endif
      {
        /* Map the physical channels to the virtual channels */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRegWrite = &LpVirChannel->ulVCR[LpGroup->ulStartVirChPtr +
                                         LucLoopCount];
        LulRegWriteValue = Adc_GpChannelToGroup[LucChannelToGroupIndex];
        /* END Msg(4:0491)-5 */
      }
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                              &Adc_GaaRamMirrorAdcVirChReg[LucHwUnitIndex].
                              ulVCR[LpGroup->ulStartVirChPtr + LucLoopCount]);
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                              (LulRegWriteValue & ADC_WV_ENHANCED_LC_MASK_VCR),
                              ADC_WV_ENHANCED_LC_MASK_VCR,
                              ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      #else
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                              (LulRegWriteValue & ADC_WV_MASK_VCR),
                              ADC_WV_MASK_VCR,
                              ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
     #endif
     /* Increment enabled channels */
      LucLoopCount++;
     /* END Msg(4:3138)-22 */
    }
    #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
    else
    {
      /* Increment disabled channels */
      LucDisableChannelCount++;
    }
    #endif
    LucChannelToGroupIndex++;
  }

  /* T & H FUNCTIONALITY INT */
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  /*
   * Check if the group is mapped to ADC0 HW unit, because Track and hold is
   * supported by ADC0 unit only.
   */
  if (ADC_ZERO == LpGroup->ucHwUnitIndex)
  {
    /* Initialize the local variable for HW unit configuration */
    LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
    /* Check if group is configured with Track and Hold enabled channel */
    if (ADC_TRUE == LpGroup->blTandHEnable)
    {
      /* Enable to perform automatic sampling */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR, ADC_SET_ASMPMSK,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                  ADC_SET_ASMPMSK, ADC_WV_MASK_THCR,
                  ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
      LulRegWriteValue = (ADC_SET_HLDCTE_HLDTE |
                              ((uint32)LucSgUnitId + ADC_ONE));
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                LulRegWriteValue, ADC_WV_MASK_THACR,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                LulRegWriteValue, ADC_WV_MASK_THBCR,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* Enable the channels configured for Track and Hold functionality */
      LulRegWriteValue = (uint32)LpHwUnitConfig->ucTrackHoldMask;
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                LulRegWriteValue, ADC_WV_MASK_THER,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* Map the channels to group A or B */
      LulRegWriteValue = (uint32)LpHwUnitConfig->ucGroupSelectMask;
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                LulRegWriteValue, ADC_WV_MASK_THGSR,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* Set the bit HLDCTE and Clear the bit HLDTE in respective T&H Group */
      /* ADC_CLR_HLDTE = 0XFFFFFFEF */
      LulRegWriteValue = (LpAdcRegisters->ulTHACR & ADC_CLR_HLDTE);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                LulRegWriteValue, ADC_WV_MASK_THACR,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      LulRegWriteValue = (LpAdcRegisters->ulTHBCR & ADC_CLR_HLDTE);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                LulRegWriteValue, ADC_WV_MASK_THBCR,
                ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
      /* Start sampling of all the Track and Hold channels */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR, ADC_SET_SMPST);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* To avoid MISRA violation */
    }
  }
  else
  {
    /* To avoid MISRA violation */
  }
  #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */

  /* Set the group status as busy */
  LpGroupData->enGroupStatus = ADC_BUSY;

  /* Check if the requested group is SW triggered */
  /* MISRA Violation: START Msg(4:3138)-22 */
  if (Adc_GucMaxSwTriggGroups > LddGroup)
  {
    /* MISRA Violation: START Msg(4:2986)-30 */
    /* Set applicable SGACT of buffer to 1, Start conversion */
    LulRegSGSTR = (LulRegSGSTR |
           (uint32)(Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));
    /* END Msg(4:2986)-30 */
  }
  else
  {
    /* Enable the SG unit to start the conversion on trigger */
    LulRegWriteValue = (LpAdcSGRegisters->ulSGCR | ADC_SG_HW_TRIGGER);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR, LulRegWriteValue,
                      &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                      LulRegWriteValue, ADC_WV_MASK_SGCR,
                      ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
    /* Set applicable TRGMD of SGCR */
    LulRegSGCR[LucSgRegIndex-LucSGOffset] = LulRegWriteValue;
  }
  /* END Msg(4:3138)-22 */

  /* Writing back the previously configured TRGMD bits */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_CONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously Trigger conversion */
  /* If SG1 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ZERO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG1 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
    /* END Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG2 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ONE]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG2 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG3 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_TWO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG3 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }

}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_StateTransition
**
** Service ID           : NA
**
** Description          : This function does the state transition of the Group
**                        after the call of the API Adc_ReadGroup or
**                        Adc_GetStreamLastPointer.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupRamData, Adc_GpGroupConfig,
**                        Adc_GucMaxSwTriggGroups, Adc_GpSgUnitRamData
**
** Functions invoked    : Adc_ConfigureGroupForConversion
**
** Registers Used       : ADCAnECR, ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm,
**                        DDAm, DTCm, DRSAm, RDAm, DRTCm, DSAm, DTCTm,
**                        DADCAnADCR, ADCAnDGCTL0, ADCAnDGCTL1, ICDMAm,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx, ADCAnVCRj,
**                        ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR, ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR,  ADCAnTHSMPSTCR, ADCAnSGSTCRx,
**                        ICADCAnIm, DCSTm
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_087 */
FUNC(void, ADC_PRIVATE_CODE) Adc_StateTransition(Adc_GroupType LddGroup)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  uint8 LucSgUnitIndex;

  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Check if the group status is stream completed */
  if (ADC_STREAM_COMPLETED == LpGroupData->enGroupStatus)
  {
    /* Get the pointer to the group configuration */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpGroup = &Adc_GpGroupConfig[LddGroup];
    /* END Msg(4:0491)-5 */
    if (ADC_GROUP_CONTINUOUS == (LpGroup->ucGroupSettings &
                                                        ADC_GROUP_CONV_MASK))
    {
      LpGroupData->enGroupStatus = ADC_BUSY;
    }
    else if (ADC_GROUP_ONCE == (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
    {
      /* Get the SGm unit index to which the channel group is mapped */
      LucSgUnitIndex = LpGroup->ucSgUnitIndex;
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
      /* END Msg(4:0491)-5 */
      if ((Adc_GucMaxSwTriggGroups <= LddGroup) &&
                       (ADC_FALSE == LpSgUnitData->blSgUnitStatus) &&
          (ADC_GROUP_ACCESS_SINGLE ==
                       (LpGroup->ucGroupSettings & ADC_GROUP_ACCESS_MASK)))
      {
        /* Set the SG unit status to busy */
        LpSgUnitData->blSgUnitStatus = ADC_TRUE;
        /*
         * Configure the group for conversion for the subsequent hardware
         * or timer trigger, within this function the group status will be
         * changed to ADC_BUSY
         */
        Adc_ConfigureGroupForConversion(LddGroup);
      }
      else
      {
        LpGroupData->enGroupStatus = ADC_IDLE;
      }
    }
    else
    {
      /* To avoid MISRA violation */
    }
  }
  else if (ADC_COMPLETED == LpGroupData->enGroupStatus)
  {
    LpGroupData->enGroupStatus = ADC_BUSY;
  }
  else
  {
    /* To avoid MISRA violation */
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_EnableHWGroup
**
** Service ID           : NA
**
** Description          : This function enables the ongoing HW triggered group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GucMaxSwTriggGroups, Adc_GpGroupConfig,
**                        Adc_GpHwUnitConfig, Adc_GpHWGroupTrigg,
**                        Adc_GpGroupRamData, Adc_GpSgUnitRamData,
**                        Adc_GpSgUnitConfig
**
** Functions invoked    : Adc_ConfigureGroupForConversion, Adc_HaltADConversion
**
** Registers Used       : ADCAnSGTSELx, ADCAnECR, ADCAnULLMTBRx, ADCAnSGCRx,
**                        DCENm, DCSTCm, DRSAm, DDAm, DTCm, DRSAm,DRDAm, DRTCm,
**                        DSAm, DTCTm, ADCAnADCR, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ICDMAm, ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSGVCSPx,
**                        ADCAnVCRj, ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR,  ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR,
**                        ADCAnSGSTCRx, ICADCAnIm, DCSTm
*******************************************************************************/
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_088 */
/* Implements ADC_ESDD_UD_001 */
FUNC(void, ADC_PRIVATE_CODE) Adc_EnableHWGroup(Adc_GroupType LddGroup)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  uint8 LucSgUnitIndex;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  Adc_GroupType LddVirGroup;

  uint8 LucHwUnit;
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegWriteValue;
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* Get the pointer to the group configuration */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */

  /* Get the SG Unit to which the group belongs */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* Get the index to HW trigger details of requested group */
  /* MISRA Violation: START Msg(4:2892)-6 */
  LddVirGroup = LddGroup - Adc_GucMaxSwTriggGroups;
  /* END Msg(4:2892)-6 */
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the SG unit index */
  LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
  /* END Msg(4:0491)-5 */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Configure for HW trigger values configured */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnitIndex;
  /* MISRA Violation: START Msg(2:2824)-29 */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(2:2824)-29 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Buffer the status of SGSTR */
  /* MISRA Violation: START Msg(2:2814)-27 */
  LulRegSGSTR = LpAdcRegisters->ulSGSTR;
  /* END Msg(2:2814)-27 */
  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegSGCR[ADC_SG1] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegSGCR[ADC_SG2] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegSGCR[ADC_SG3] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */

  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
  Adc_HaltADConversion(LucHwUnitIndex);

  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:2824)-29 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGTSEL,
                  Adc_GpHWGroupTrigg[LddVirGroup],
                  &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGTSEL);
  /* END Msg(2:2814)-27 */
  /* END Msg(2:2824)-29 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGTSEL,
                  Adc_GpHWGroupTrigg[LddVirGroup], ADC_WV_MASK_SGTSEL,
                  ADC_ENABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously configured TRGMD bits */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ENABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */

  /* Writing back the previously Trigger conversion */
  /* If SG1 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ZERO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG1 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
    /* END Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG2 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ONE]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG2 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG3 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_TWO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG3 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }

  /* Set the Trigger status for the group as true */
  Adc_GpGroupRamData[LddGroup].ucHwTriggStatus = ADC_TRUE;
  /* Set the SG unit status to busy */
  Adc_GpSgUnitRamData[LucSgUnitIndex].blSgUnitStatus = ADC_TRUE;
  /* END Msg(4:0491)-5 */
  /* Configure the group for conversion */
  Adc_ConfigureGroupForConversion(LddGroup);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_HW_TRIGGER_API == STD_ON */

/*******************************************************************************
** Function Name        : Adc_DisableHWGroup
**
** Service ID           : NA
**
** Description          : This function disables the ongoing HW triggered group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupRamData, Adc_GpGroupConfig,
**                        Adc_GpHwUnitConfig, Adc_GpSgUnitConfig
**
** Functions invoked    : Adc_IcrInterruptBit, Adc_ClearPendingInterrupt,
**                        Adc_StopScanGroup, Adc_HaltScanGroup,
**                        Adc_HaltADConversion
**
** Registers Used       : ADCAnSGCRx, ADCAnSGTSELx, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnADCR, ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR,
**                        ADCAnTHACR, ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER,
**                        ADCAnTHCR, ICADCAnIm, ADCAnSGSTPCRx, ADCAnSGSTR,
**                        ADCAnADHALTR, ADCAnSGSTCRx
*******************************************************************************/
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_089 */
/* Implements ADC_ESDD_UD_001 */
FUNC(void, ADC_PRIVATE_CODE) Adc_DisableHWGroup(Adc_GroupType LddGroup)
{
  #if (((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                   ((ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON) || \
                             (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)))  \
                                            || (ADC_TRACK_AND_HOLD == STD_ON))
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #endif
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint8 LucHwUnitIndex;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  uint8 LucSgUnitId;
  #endif
  uint8 LucHwUnit;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  uint8 LucSgUnitIndex;
  uint32 LulRegWriteValue;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  LucHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnitIndex;
  /* END Msg(4:0491)-5 */

  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

  /* Buffer the status of SGSTR */
  /* MISRA Violation: START Msg(2:2814)-27 */
  LulRegSGSTR = LpAdcRegisters->ulSGSTR;
  /* END Msg(2:2814)-27 */

  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegSGCR[ADC_SG1] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegSGCR[ADC_SG2] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegSGCR[ADC_SG3] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */

  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
  Adc_HaltADConversion(LucHwUnitIndex);

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = Adc_GpGroupConfig[LddGroup].ucSgUnitIndex;
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  /* Get the SG unit Id to which this group is mapped */
  /* MISRA Violation: START Msg(2:2824)-29 */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(2:2824)-29 */
  #endif
  /* Get the SG unit index */
  LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
  /* END Msg(4:0491)-5 */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /* Reset Scan control register to disable HW trigger */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR,
                        ADC_CLR_SCAN_GRP_CTL_REG,
                        &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
  /* END Msg(2:2814)-27 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                        ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_SGCR,
                        ADC_DISABLEHWGROUP_API_ID);
  /* Set applicable TRGMD of buffer to 0 */
  LulRegSGCR[LucSgRegIndex-LucSGOffset] =
               LulRegSGCR[LucSgRegIndex-LucSGOffset] & ADC_CLEAR_TRGMD;

  /* Clear the channel list to avoid conversion on next HW trigger */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGTSEL,
                        ADC_CLEAR_TRIGGER_LIST,
                        &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGTSEL);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGTSEL,
                        ADC_CLEAR_TRIGGER_LIST, ADC_WV_MASK_SGTSEL,
                        ADC_DISABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
/* Implements SWS_Adc_00145, ADC145 */
  #if (ADC_HARD_STOP == STD_OFF)
  /* Stop the conversion of all the SG unit */
  Adc_HaltScanGroup(LddGroup);
  #elif (ADC_HARD_STOP == STD_ON)
  /* Stop the conversion of all the SG unit using ADCAnSGSTPCRx register. */
  Adc_StopScanGroup(LddGroup);
  #endif
  /* Set applicable SGACT of buffer to 0 */
  LulRegSGSTR = (LulRegSGSTR
                &(~Adc_GaaSGmConvStatusMask[LucSgRegIndex-LucSGOffset]));

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* MISRA Violation: START Msg(2:2824)-29 */
  Adc_GpSgUnitRamData[LucSgUnitIndex].blSgUnitStatus = ADC_FALSE;
  /* END Msg(2:2824)-29 */
  /* END Msg(4:0491)-5 */

  #if (((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                   ((ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON) || \
                             (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)))  \
                                            || (ADC_TRACK_AND_HOLD == STD_ON))
  /* Get the pointer to Group configuration */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  #endif

  #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
  #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
  if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
        (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
  {
    /* Disable self-diag voltage level selection */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                  ADC_SELF_DIAG_VLTG_DISABLE,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                  ADC_DISABLEHWGROUP_API_ID);
    if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
    {
      /* Disable self-diag voltage level selection */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                    ADC_SELF_DIAG_VLTG_DISABLE,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                    ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                    ADC_DISABLEHWGROUP_API_ID);
      /* END Msg(4:3138)-22 */
    }
    else
    {
       /* To avoid MISRA violation */
    }

    /* Disable the self diag functionality support */
    /* MISRA Violation: START Msg(4:3138)-22 */
    LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                        &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                        LulRegWriteValue, ADC_WV_MASK_ADCR,
                        ADC_DISABLEHWGROUP_API_ID);
    /* END Msg(4:3138)-22 */
  }
  /* group is configured as normal group */
  else
  {
    /* No action required */
  }
  #endif

  #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
  /* check the group is configured in the open pin self diag support */
  if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
  {
    /* Implements AR_PN0076_FSR_0002 */
    /* Disable on-chip pull-down resistor */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                ADC_DISABLEHWGROUP_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                ADC_DISABLEHWGROUP_API_ID);
    /* END Msg(4:3138)-22 */
  }
  /* group is configured as normal group */
  else
  {
    /* No action required */
  }
  #endif
  #endif

  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  /* Check if the Group is mapped for HW configured for interrupt mode */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                      .enFunctionalityModeType)
  /* END Msg(4:0491)-5 */
  {
    /* Disable the interrupt for the SGm unit to which the group is mapped */
    Adc_IcrInterruptBit(LucSgUnitIndex, ADC_DISABLE_INTERRUPT);
    /*
     * Clear the pending interrupt for the SGm unit to which the
     * group is mapped
     */
    Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
  }
  else
  {
    /* No action required */
  }
  #endif

  #if (ADC_TRACK_AND_HOLD == STD_ON)
  /* Check if group is configured with Track and Hold enabled channel */
  if (ADC_TRUE == LpGroup->blTandHEnable)
  {
    /* Stop sampling of all the Track and Hold channels */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR,
                              ADC_TRACK_AND_HOLD_REG_CLEAR);
    /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                ADC_TRACK_AND_HOLD_REG_CLEAR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THACR,
                ADC_DISABLEHWGROUP_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                ADC_TRACK_AND_HOLD_REG_CLEAR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THBCR,
                ADC_DISABLEHWGROUP_API_ID);
    /* Un Map the channels to group A or B */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                ADC_TRACK_AND_HOLD_REG_CLEAR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THGSR,
                ADC_DISABLEHWGROUP_API_ID);
    /* Disable the channels configured for Track and Hold functionality */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                ADC_TRACK_AND_HOLD_REG_CLEAR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THER,
                ADC_DISABLEHWGROUP_API_ID);
    /* Disable to perform automatic sampling */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR,
                ADC_TRACK_AND_HOLD_REG_CLEAR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_THCR,
                ADC_DISABLEHWGROUP_API_ID);
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* To avoid MISRA violation */
  }
  #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */

  /* Writing back the previously configured TRGMD bits */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_DISABLEHWGROUP_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously Trigger conversion */
  /* If SG1 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ZERO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG1 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
    /* END Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG2 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ONE]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG2 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG3 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_TWO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG3 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Store disabled notification into RAM */
  LpGroupData->ucNotifyStatus = ADC_FALSE;
  #endif
/* Implements ADC361, SWS_Adc_00361 */
  /* Set the Group status to idle */
  LpGroupData->enGroupStatus = ADC_IDLE;

  /* Set the group enable hardware trigger status to false */
  LpGroupData->ucHwTriggStatus = ADC_FALSE;
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_HW_TRIGGER_API == STD_ON */

/*******************************************************************************
** Function Name        : Adc_SearchnDelete
**
** Service ID           : NA
**
** Description          : This function is called by the Adc_StopGroupConverion
**                        API to search if the requested group is in the queue
**                        and remove it from the queue.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LucHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpSgUnitRamData, Adc_GpHwUnitConfig,
**                        Adc_GpGroupRamData, Adc_GpGroupConfig,
**                        Adc_GpSgUnitConfig
**
** Functions invoked    : None
**
** Registers Used       : None
*******************************************************************************/
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_090 */
FUNC(void, ADC_PRIVATE_CODE) Adc_SearchnDelete(Adc_GroupType LddGroup)
{
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  uint8 LucQueueSize;
  uint8 LucSgUnitIndex;
  uint8_least LucLoopCount;

  /* Initialize the loop count to zero */
  LucLoopCount = ADC_ZERO;
  /* Get the SG unit index of the requested group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgUnitIndex = Adc_GpGroupConfig[LddGroup].ucSgUnitIndex;
  /* Initialize SG unit RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Get the base address of the Queue */
  LpQueue = Adc_GpSgUnitConfig[LucSgUnitIndex].pQueue;
  /* END Msg(4:0491)-5 */
  /* Read the configured priority queue size */
  LucQueueSize = LpSgUnitData->ucQueueCounter;

  /* Find the requested group in the queue and re-arrange the
     queue by deleting the requested group */
  while (LucLoopCount < LucQueueSize)
  {
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (LddGroup == LpQueue[LucLoopCount])
    /* END Msg(4:0491)-5 */
    {
      /* Decrement the queue size by one */
      LucQueueSize--;
      /* Update the queue counter value */
      LpSgUnitData->ucQueueCounter = LucQueueSize;
      /* Re-arrange the queue after deleting the requested group */
      while (LucLoopCount < LucQueueSize)
      {
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpQueue[LucLoopCount] = LpQueue[LucLoopCount + ADC_ONE];
        /* END Msg(4:0491)-5 */
        LucLoopCount++;
      }
      /* To exit from the while loop */
      LucLoopCount = LucQueueSize;
    }
    else
    {
      /* No action required */
    }
    LucLoopCount++;
  }
  /* Clear the flag indicating group removed from the queue */
  /* MISRA Violation: START Msg(4:0491)-5 */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_FALSE;
  /* END Msg(4:0491)-5 */
  /* Update the queue status */
  if (ADC_ZERO == LpSgUnitData->ucQueueCounter)
  {
    /* Set queue status as empty */
    LpSgUnitData->ucQueueStatus = ADC_QUEUE_EMPTY;
  }
  else
  {
    /* Set queue status as filled */
    LpSgUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /*
        * #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
        *          ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
        *                                   (ADC_ENABLE_QUEUING == STD_ON)))
        */

/*******************************************************************************
** Function Name        : Adc_IcrInterruptBit
**
** Service ID           : NA
**
** Description          : This function enables or disables the interrupt of
**                        the requested Adc HW and SG unit, using ICR register.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit, LucSgUnitIndex and
**                        LblEnableOrDisableInterrupt
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpSgUnitConfig
**
** Functions invoked    : None
**
** Registers Used       : ICADCAnIm
*******************************************************************************/
#if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_091 */
FUNC(void, ADC_FAST_CODE) Adc_IcrInterruptBit(uint8 LucSgUnitIndex,
boolean LblEnableOrDisableInterrupt)
{
  /* Defining a pointer to the SGm unit structure */
  P2CONST(Adc_HwSgUnitType, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitConfig;

  /* Disable the interrupt for the SGm unit to which the group is mapped */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */

  if (ADC_DISABLE_INTERRUPT == LblEnableOrDisableInterrupt)
  {
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* Disable the interrupt */
    RH850_SV_MODE_ICR_OR(16, (LpSgUnitConfig->pIcrIntpAddress),
                                        ADC_INTERRUPT_MASK_DIS);
    /* END Msg(4:4397)-8 */
  }
  else
  {
    /* Enable the interrupt */
    RH850_SV_MODE_ICR_AND (16, (LpSgUnitConfig->pIcrIntpAddress),
                                         ADC_INTERRUPT_MASK_EN);
  }

}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */

/*******************************************************************************
** Function Name        : Adc_ClearPendingInterrupt
**
** Service ID           : NA
**
** Description          : This function clears the pending interrupt of
**                        the requested Adc HW and SG unit, by clearing the
**                        interrupt flag.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit, LucSgUnitId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig
**
** Functions invoked    : None
**
** Registers Used       : ICADCAnIm
*******************************************************************************/
#if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_092 */
FUNC(void, ADC_FAST_CODE) Adc_ClearPendingInterrupt(uint8 LucHwUnit,
uint8 LucSgUnitId)
{
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ADC_CONFIG_DATA) LpIntpCntrlReg;
  /*
   * Clear the pending interrupt for the SGm unit to which the
   * group is mapped
   */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpIntpCntrlReg = Adc_GpHwUnitConfig[LucHwUnit].pIntpAddress;
  LpIntpCntrlReg = &LpIntpCntrlReg[LucSgUnitId];
  /* END Msg(4:0491)-5 */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Implements EAAR_PN0034_FR_0068 */
  /* Register write dummy read and SYNCP execution  */
  RH850_SV_CLEAR_ICR_SYNCP (16, (LpIntpCntrlReg),(ADC_CLEAR_INT_REQUEST_FLAG));
  #else
  /* Register writing alone  */
  RH850_SV_MODE_ICR_AND (16, (LpIntpCntrlReg), (ADC_CLEAR_INT_REQUEST_FLAG));
  #endif/* #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */

/*******************************************************************************
** Function Name        : Adc_IntEnableHwTrigger
**
** Service ID           : NA
**
** Description          : This is internal function to set the PVCR for
**                        PWM diagnostic channel mapped to PWM diagnostic
**                        group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpPwmDiagGroupConfig, Adc_GpPwmDiagIds,
**                        Adc_GpPwmGroupData, Adc_GpChannelToGroup,
**                        Adc_GpPwmChannelCTDRVal, Adc_GpHwUnitConfig
**
** Functions invoked    : Det_ReportError, Dem_ReportErrorStatus
**                        ADC_ENTER_CRITICAL_SECTION,
**                        ADC_EXIT_CRITICAL_SECTION, Adc_HaltADConversion
**
** Registers Used       : ADCAnULLMTBRx,PWGAnCTDR, PWGAnRDT, ICQFULL
**                        PWSAnPVCRx_y, PWSAnSTR
*******************************************************************************/
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_105 */
/* Implements ADC_ESDD_UD_031 */
/* Implements ADC_ESDD_UD_056 */
/* Implements ADC_ESDD_UD_215 */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntEnableHwTrigger(Adc_GroupType LddGroup)
{
  P2CONST(Adc_PwmDiagIds, ADC_VAR, ADC_CONFIG_CONST) LpPwmDiagIds;
  uint16 LusPwmDiagIndex;
  P2VAR(volatile PWGAReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcPwmRegisters;
  #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_DMA_MODE_ENABLE == STD_OFF))
  P2CONST(Adc_PwmDiagGroupConfigType, AUTOMATIC, ADC_CONFIG_CONST)
                                                                LpPwmDiagGroup;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint8 LucHwUnitIndex;
  uint8 LucLimitCheckIndex;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  #endif
  uint8 LucVariable;
  uint32 LulPwmReadVariable;
  uint32 LulRegWriteValue;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif

  /* Get the index of the trigger source of the PWM Diagnostic group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucVariable = Adc_GpPwmGroupData[LddGroup].ucTriggSrcIndex;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check for invalid trigger source index */
  if (ADC_MAX_DIAG_IDS <= LucVariable)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_ENABLE_HW_TRIGGER_SID, ADC_E_INVALID_TRIGG_SOURCE);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  #endif
  {
    /* Get the pointer to PWM Diagnostic trigger source */
    LpPwmDiagIds = &Adc_GpPwmDiagIds[LucVariable];
    /* END Msg(4:0491)-5 */
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Check for invalid trigger soure */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_PWM_TRIGG_SRC_INVALID == Adc_GpPwmChannelCTDRVal
                                            [LpPwmDiagIds->ucPwmTriggChIndex])
    /* END Msg(4:0491)-5 */
    {
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                        ADC_ENABLE_HW_TRIGGER_SID, ADC_E_INVALID_TRIGG_SOURCE);
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
  #endif
  {
    LusPwmDiagIndex = LpPwmDiagIds->usPwmDiagIndex;
    LpAdcPwmRegisters = Adc_GaaPWGAReg_BaseAddress[LusPwmDiagIndex];
    #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && \
                                            (ADC_DMA_MODE_ENABLE == STD_OFF))
    /* Get the pointer to PWM Diagnostic group */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpPwmDiagGroup = &Adc_GpPwmDiagGroupConfig[LddGroup];
    /* END Msg(4:0491)-5 */
    if (ADC_TRUE == LpPwmDiagGroup->blLimitCheckEnabled)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LucHwUnitIndex = Adc_GpHwUnitConfig[LpPwmDiagGroup->ucHwUnit].ucHwUnit;
      /* END Msg(4:0491)-5 */
      LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
      LucLimitCheckIndex = LpPwmDiagGroup->ucPwmLimitCheckIndex;

      /* Buffer the status of SGSTR */
      /* MISRA Violation: START Msg(2:2814)-27 */
      LulRegSGSTR = LpAdcRegisters->ulSGSTR;
      /* END Msg(2:2814)-27 */

      /* Read the SG offset */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LucSGOffset = Adc_GpHwUnitConfig[LpPwmDiagGroup->ucHwUnit].ucSGOffset;
      /* END Msg(4:0491)-5 */
      /* Buffer the status of SGCR */
      /* MISRA Violation: START Msg(4:2985)-10 */
      /* MISRA Violation: START Msg(2:3892)-28 */
      LulRegSGCR[ADC_SG1] =
                       Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
      LulRegSGCR[ADC_SG2] =
                       Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
      LulRegSGCR[ADC_SG3] =
                       Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
      /* END Msg(2:3892)-28 */
      /* END Msg(4:2985)-10 */

      /* Set TRGMD of all scan groups to 0 */
      /* MISRA Violation: START Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:2814)-27 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
      /* END Msg(2:2814)-27 */
      /* END Msg(4:2985)-10 */
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);

      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);

      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
      LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                         & ADC_CLEAR_TRGMD;
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
      /* 
       *Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR
       */
      Adc_HaltADConversion(LucHwUnitIndex);

      /* Implements EAAR_PN0076_FR_0032 */
      /* Load the upper limit for error check */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:2824)-29 */
      /* MISRA Violation: START Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulULLMTBR[ADC_ZERO],
              Adc_GpLimitCheckRange[LucLimitCheckIndex],
              &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulULLMTBR[ADC_ZERO]);
      /* END Msg(2:2824)-29 */
      /* END Msg(2:3892)-28 */
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulULLMTBR[ADC_ZERO],
              Adc_GpLimitCheckRange[LucLimitCheckIndex],
              ADC_WV_MASK_ULLMTBR, ADC_INTENABLEHWTRIGGER_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */

      /* Writing back the previously configured TRGMD bits */
      /* MISRA Violation: START Msg(4:2985)-10 */
      /* MISRA Violation: START Msg(2:3892)-28 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
      LulRegWriteValue =
                  (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                            | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
      /* END Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
      /* END Msg(4:2985)-10 */
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);
      /* MISRA Violation: START Msg(2:3892)-28 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
      LulRegWriteValue =
              (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                         | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
      /* END Msg(2:3892)-28 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);
      /* MISRA Violation: START Msg(2:3892)-28 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
      LulRegWriteValue =
               (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                         | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
      /* END Msg(2:3892)-28 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
                LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                LulRegWriteValue, ADC_WV_MASK_SGCR,
                ADC_INTENABLEHWTRIGGER_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
      /* Writing back the previously Trigger conversion */
      /* If SG1 was in suspended state */
      /* MISRA Violation: START Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(4:2992)-31 */
      if (ADC_NOT_BUSY != (LulRegSGSTR &
                                Adc_GaaSGmConvStatusMask[ADC_ZERO]))
      /* END Msg(4:2992)-31 */
      /* END Msg(2:3892)-28 */
      {
        /* Trigger conversion of SG1 */
        /* MISRA Violation: START Msg(4:2985)-10 */
        LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
        /* END Msg(4:2985)-10 */
        /* MISRA Violation: START Msg(4:3138)-22 */
        /* MISRA Violation: START Msg(2:3109)-24 */
        ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
        /* END Msg(2:3109)-24 */
        /* END Msg(4:3138)-22 */
      }
      else
      {
        /* No Action */
      }
      /* If SG2 was in suspended state */
      /* MISRA Violation: START Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(4:2992)-31 */
      if (ADC_NOT_BUSY != (LulRegSGSTR &
                                Adc_GaaSGmConvStatusMask[ADC_ONE]))
      /* END Msg(4:2992)-31 */
      /* END Msg(2:3892)-28 */
      {
        /* Trigger conversion of SG2 */
        LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
        /* MISRA Violation: START Msg(4:3138)-22 */
        /* MISRA Violation: START Msg(2:3109)-24 */
        ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
        /* END Msg(2:3109)-24 */
        /* END Msg(4:3138)-22 */
      }
      else
      {
        /* No Action */
      }
      /* If SG3 was in suspended state */
      /* MISRA Violation: START Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(4:2992)-31 */
      if (ADC_NOT_BUSY != (LulRegSGSTR &
                                Adc_GaaSGmConvStatusMask[ADC_TWO]))
      /* END Msg(4:2992)-31 */
      /* END Msg(2:3892)-28 */
      {
        /* Trigger conversion of SG3 */
        LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
        /* MISRA Violation: START Msg(4:3138)-22 */
        /* MISRA Violation: START Msg(2:3109)-24 */
        ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
        /* END Msg(2:3109)-24 */
        /* END Msg(4:3138)-22 */
      }
      else
      {
        /* No Action */
      }
    }
    else
    {
      /* No actions Required */
    }
    #endif

    /* Load the PWGAnCTDR value */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(4:0491)-5 */
    ADC_PWMDIAG_WRITE_REG_AND_MIRROR(&LpAdcPwmRegisters->usCTDR,
                    Adc_GpPwmChannelCTDRVal[LpPwmDiagIds->ucPwmTriggChIndex],
                    &Adc_GaaRamMirrorPWGAReg[LusPwmDiagIndex].usCTDR);
    ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcPwmRegisters->usCTDR,
                    Adc_GpPwmChannelCTDRVal[LpPwmDiagIds->ucPwmTriggChIndex],
                    ADC_WV_MASK_PWGA_CTDR, ADC_INTENABLEHWTRIGGER_API_ID);
    /* END Msg(4:0491)-5 */
    /* Load the PWGAnRDT value */
    ADC_WRITE_REG_ONLY(&LpAdcPwmRegisters->ucRDT, ADC_EN_PWM_DIAG_RELOAD_TRIGG);
    /* END Msg(4:3138)-22 */

    /* Get the index of PWM diagnostic channel configured for the group */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LucVariable = Adc_GpPwmDiagGroupConfig[LddGroup].ucChannelToGroupIndex;
    /* END Msg(4:0491)-5 */
    #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
    /* Get the index of first PWM diagnostic channel configured for the group */
    /* MISRA Violation: START Msg(4:0491)-5 */
    Adc_GpPwmGroupData[LddGroup].ucStartChannelIndex = LucVariable;
    /* END Msg(4:0491)-5 */
    #endif
    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif

    /* Read the PWM Diagnostic virtual channel register */
    LulPwmReadVariable =
                  Adc_GaaPWSAReg_BaseAddress->ulPVCR[LpPwmDiagIds->ucPVCRIndex];
    /* clear the part that will be rewritten */
    LulPwmReadVariable &=
                   (~((uint32)(ADC_PWSAPVCR_MASK) << LpPwmDiagIds->ucOffset));
    /* Load the PWM Diagnostic virtual channel */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LpRegWrite = &Adc_GaaPWSAReg_BaseAddress->ulPVCR[LpPwmDiagIds->ucPVCRIndex];
    LulRegWriteValue = (LulPwmReadVariable |
        ((uint32)Adc_GpChannelToGroup[LucVariable] << LpPwmDiagIds->ucOffset));
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_PWMDIAG_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                    &Adc_GaaRamMirrorPWSAReg.ulPVCR[LpPwmDiagIds->ucPVCRIndex]);
    /*If ENHANCED LIMIT CHECK feathure is enabled.*/
    #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
    ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
                  ADC_WV_ENH_LC_MASK_PWSA_PVCR, ADC_INTENABLEHWTRIGGER_API_ID);
    #else
    ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
                      ADC_WV_MASK_PWSA_PVCR, ADC_INTENABLEHWTRIGGER_API_ID);
    #endif
    /* Check if critical section protection is required */
    #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
    #endif
    /* END Msg(4:3138)-22 */
    /* END Msg(4:0491)-5 */
    /* Check if Adc Conversion trigger queue is filled */
    if (ADC_PWSAQFL_SET ==
                     (Adc_GaaPWSAReg_BaseAddress->ucSTR & ADC_PWSAQFL_SET))
    {
      #if (ADC_DEM_ERROR_DETECT == STD_ON)
      /* Implements ADC068, ADC377, SWS_Adc_00377 */
      /* Report Error to DEM */
      Dem_ReportErrorStatus(ADC_E_QUEUE_FULL,
                                         DEM_EVENT_STATUS_FAILED);
      #endif
      /* Implements ADC_ESDD_UD_160 */
      /* Implements ADC_ESDD_UD_153 */
      #if (ADC_PWSA_INT_QFULL_ISR == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-4 */
      /* Implements EAAR_PN0034_FR_0067 */
      /* Clear the interrupt request */
      RH850_SV_MODE_ICR_AND(16, ADC_ICREG_ADDRESS_QFULL,
                                         ADC_CLEAR_INT_REQUEST_FLAG);
      /* END Msg(4:0303)-4 */
      #endif
    }
    else
    {
      /* No action required */
    }
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

#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_IntDisableHwTrigger
**
** Service ID           : NA
**
** Description          : This is internal function clear the CTDR value
**                        of previously enabled PWM Diagnostic channel
**                        by disable value.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : LucTriggerIndex
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpPwmDiagIds, Adc_GpPwmTriggSrc,
**                        Adc_GpPwmGroupData, Adc_GpPwmChannelCTDRVal
**
** Functions invoked    : ADC_ENTER_CRITICAL_SECTION
**                        ADC_EXIT_CRITICAL_SECTION, Det_ReportError
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
/* Implements ADC_ESDD_UD_117 */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntDisableHwTrigger(Adc_GroupType LddGroup)
{
  P2CONST(Adc_PwmDiagIds, ADC_VAR, ADC_CONFIG_CONST) LpPwmDiagIds;
  P2VAR(volatile PWGAReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcPwmRegisters;
  uint16 LusPwmDiagIndex;
  uint8 LucVariable;
  uint16 LusRegWriteValue;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  ADC_ENTER_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Get the index of the trigger source of the PWM Diagnostic group */
  LucVariable = Adc_GpPwmGroupData[LddGroup].ucTriggSrcIndex;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to E_NOT_OK */
  LenDetErrFlag = E_NOT_OK;
  /* Check for invalid trigger source index */
  if (ADC_MAX_DIAG_IDS <= LucVariable)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_DISABLE_HW_TRIGGER_SID, ADC_E_INVALID_TRIGG_SOURCE);
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_OK;
  }
  else
  #endif
  {
    /* Initialize the local pointer */
    LpPwmDiagIds = &Adc_GpPwmDiagIds[LucVariable];
    /* Get the PWM DIAG index  */
    LusPwmDiagIndex = LpPwmDiagIds->usPwmDiagIndex;
    LpAdcPwmRegisters = Adc_GaaPWGAReg_BaseAddress[LusPwmDiagIndex];
    /* END Msg(4:0491)-5 */

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_PWM_TRIGG_SRC_INVALID == Adc_GpPwmChannelCTDRVal
                                            [LpPwmDiagIds->ucPwmTriggChIndex])
    /* END Msg(4:0491)-5 */
    {
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                        ADC_DISABLE_HW_TRIGGER_SID, ADC_E_INVALID_TRIGG_SOURCE);
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
  if ((E_NOT_OK == LenDetErrFlag) &&
                  ((LpAdcPwmRegisters->usCSDR) != (LpAdcPwmRegisters->usCRDR)))
  #else
  if ((LpAdcPwmRegisters->usCSDR) != (LpAdcPwmRegisters->usCRDR))
  #endif
  {
    if (ADC_PWM_REG_MAX_COUNT != (LpAdcPwmRegisters->usCRDR))
    {
      /* Disable the PWM trigger source by making its value greater than
         CRDR*/
      /* MISRA Violation: START Msg(4:3138)-22 */
      LusRegWriteValue = ((LpAdcPwmRegisters->usCRDR) + ADC_ONE);
      ADC_PWMDIAG_WRITE_REG_AND_MIRROR(&LpAdcPwmRegisters->usCTDR,
                      LusRegWriteValue,
                      &Adc_GaaRamMirrorPWGAReg[LusPwmDiagIndex].usCTDR);
      ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcPwmRegisters->usCTDR,
                      LusRegWriteValue, ADC_WV_MASK_PWGA_CTDR,
                      ADC_INTDISABLEHWTRIGGER_API_ID);
      /* Load the PWGAnRDT value */
      ADC_WRITE_REG_ONLY(&LpAdcPwmRegisters->ucRDT,
                                             ADC_EN_PWM_DIAG_RELOAD_TRIGG);
    }
    else if (ADC_PWM_REG_MIN_COUNT != (LpAdcPwmRegisters->usCSDR))
    {
      /* Disable the PWM trigger source by making its value lesser than
         CSDR*/
      LusRegWriteValue = ((LpAdcPwmRegisters->usCSDR) - ADC_ONE);
      ADC_PWMDIAG_WRITE_REG_AND_MIRROR(&LpAdcPwmRegisters->usCTDR,
                      LusRegWriteValue,
                      &Adc_GaaRamMirrorPWGAReg[LusPwmDiagIndex].usCTDR);
      ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcPwmRegisters->usCTDR,
                      LusRegWriteValue, ADC_WV_MASK_PWGA_CTDR,
                      ADC_INTDISABLEHWTRIGGER_API_ID);
      /* Load the PWGAnRDT value */
      ADC_WRITE_REG_ONLY(&LpAdcPwmRegisters->ucRDT,
                                             ADC_EN_PWM_DIAG_RELOAD_TRIGG);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_DISABLE_HW_TRIGGER_SID, ADC_E_INVALID_DUTY_CYCLE);
      #endif
    }
  }
  else
  {
    /* No action required */
  }
  /* Check if critical section protection is required */
  #if (ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  ADC_EXIT_CRITICAL_SECTION(ADC_RAMDATA_PROTECTION)
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
/* Implements AR_PN0076_FR_0208*/
/*******************************************************************************
** Function Name        : Adc_IntHwResultReadGroup
**
** Service ID           : NA
**
** Description          : This is internal function, used to read the digital
**                        value of the requested group and also this function
**                        returns the status of conversion of the group. In
**                        case the group is configured with external mux
**                        enabled then the next line is moved after
**                        stabilization delay.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpPwmDiagGroupConfig, Adc_GpHwUnitConfig,
**                        Adc_GpPwmGroupData, Adc_GpChannelToGroup,
**                        Adc_GpDmaUnitConfig, Adc_GpPwmDiagIds
**
** Functions invoked    : Adc_ErrIsr
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
/* Implements ADC_ESDD_UD_107 */
FUNC(Std_ReturnType, ADC_PRIVATE_CODE) Adc_IntHwResultReadGroup
(Adc_GroupType LddGroup,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) pDataBuffer)
{
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  P2CONST(Adc_PwmDiagIds, ADC_VAR, ADC_CONFIG_CONST) LpPwmDiagIds;
  uint32 LulRegWriteValue;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;
  #endif
  P2CONST(Adc_PwmDiagGroupConfigType, AUTOMATIC, ADC_CONFIG_CONST)
                                                                LpPwmDiagGroup;
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #if (ADC_DMA_MODE_ENABLE == STD_OFF)
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint16 LusChannelMask;
  #else
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA) LpPwmDiagResultRam;
  #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA) LpPwmDiagDoubleResultRam;
  #endif
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint16 LusMaxDiagRunTime;
  #endif
  Std_ReturnType LddRetValue;
  /* variable to buffer the converted result */
  uint32 LusConvertedValue;
  uint16 LusVarValue;
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  uint8 LucIndex;
  uint32 LulPwmReadVariable;
  #endif
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) || (ADC_DMA_MODE_ENABLE == STD_ON))
  /* Variable to indicate if the result is available */
  boolean LblResultAvailable = ADC_FALSE;
  #endif
  #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && (ADC_DMA_MODE_ENABLE == STD_OFF))
  boolean LblLimitCheckErrorFlag;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint8 LucSearchIndex;
  uint8 LucPwmDmaIndex;
  uint8 LucSearchCnt;
  uint8 LucProtLength;
  uint8 LucCurrentIndex;
  #endif
  uint8 LucVariable;

  /* Initialize the return value */
  LddRetValue = E_NOT_OK;
  /* Get the pointer to PWM Diagnostic group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpPwmDiagGroup = &Adc_GpPwmDiagGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Read the Hardware Unit to which the group belongs */
  LucVariable = LpPwmDiagGroup->ucHwUnit;
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucVariable];
  /* END Msg(4:0491)-5 */

  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Get the DMA channel index configured for the PWM Diag group */
  LucPwmDmaIndex = LpPwmDiagGroup->ucPwmDmaChannelIndex;
  /* MISRA Violation: START Msg(4:0317)-19 */
  /* get the pointer to the result ram data for PWM converted results */
  LpPwmDiagResultRam = LpHwUnitConfig->pPwmDiagResultRam;
  #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  /* get the pointer to the Double result ram data for PWM converted results */
  LpPwmDiagDoubleResultRam = LpHwUnitConfig->pPwmDiagDoubleResultRam;
  #endif
  /* END Msg(4:0317)-19 */
  LusMaxDiagRunTime = LpHwUnitConfig->usMaxDiagRunTime;
  /*Get the protection length for the PWM diag group*/
  LucProtLength = LpHwUnitConfig->ucProtLength;
  /* get the pointer to the DMA index for the PWM Diag group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucPwmDmaIndex];
  /* END Msg(4:0491)-5 */
  /* get the pointer to the DMA control register */
  LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
  LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
  /* initialize the index where the latest converted result is converted */
  LucSearchIndex = (uint8)(LusMaxDiagRunTime - LpDmaRegisters->ulDTC);
  /* MISRA Violation: START Msg(4:4461)-9 */
  /* initialize the index till the search will done to get the latest converted
     result  */
  LucSearchCnt = LusMaxDiagRunTime - LucProtLength;
  /* END Msg(4:4461)-9 */

  do
  {
    if (ADC_ZERO == LucSearchIndex)
    {
      /* MISRA Violation: START Msg(4:4461)-9 */
      LucSearchIndex = LusMaxDiagRunTime - ADC_ONE;
      /* END Msg(4:4461)-9 */
    }
    else
    {
      LucSearchIndex--;
    }
    /* Read the channel's converted value */
    /* MISRA Violation: START Msg(4:0491)-5 */
    LusConvertedValue = LpPwmDiagResultRam[LucSearchIndex];
    /* END Msg(4:0491)-5 */
    /* MISRA Violation: START Msg(4:4461)-9 */
    /* Get the Analog channel Id which is converted */
    LusVarValue = ((LusConvertedValue >> ADC_SHIFT_16) &
                              ADC_PWM_DIAGGRP_CH_MASK);
    /* END Msg(4:4461)-9 */
    /* Get the Analog channel Id which is converted */
    /*
     * Check if the digital result value is ready for the physical channel
     * configured for the requested group
     */
    if (LpPwmDiagGroup->usChannelMask == LusVarValue)
    {
      /* Set the flag indicating if the search was successful */
      LblResultAvailable = ADC_TRUE;
      /* If the latest value is not an already read value */
      if (ADC_PWM_RESULT_READ != (LusConvertedValue & ADC_PWM_RESULT_READ))
      {
        /* If Double buffer is enabled to do consistency check */
        #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
        /* MISRA Violation: START Msg(4:0491)-5 */
        if ((LpPwmDiagResultRam[LucSearchIndex] & ADC_PDM_DIAG_RESULT_MASK) ==
          (LpPwmDiagDoubleResultRam[LucSearchIndex] & ADC_PDM_DIAG_RESULT_MASK))
        /* END Msg(4:0491)-5 */
        #endif
        {
          /* initialize the index where the latest converted result is
             converted */
          LucCurrentIndex = \
                   (uint8)(LusMaxDiagRunTime - LpDmaRegisters->ulDTC);
          /* If the difference between current DMA transfer index and
             the location where the data is read is greater than
             'protection length' */

          /* Implements AR_PN0076_FR_0317 */
          if (LucCurrentIndex >= LucSearchIndex)
          {
            if ((LucSearchIndex + (LusMaxDiagRunTime - LucCurrentIndex))\
                                                        >= LucProtLength)
            {
              /* MISRA Violation: START Msg(4:0491)-5 */
              /* set the result as read */
              LpPwmDiagResultRam[LucSearchIndex] = (LusConvertedValue |
                                                ADC_PWM_RESULT_READ);
              /* END Msg(4:0491)-5 */
            }
            else
            {
              /* No action required */
            }
          }
          else if (LucProtLength <= ((LucSearchIndex - LucCurrentIndex) +
                                                                 ADC_ONE))
          {
            /* MISRA Violation: START Msg(4:0491)-5 */
            /* set the result as read */
            LpPwmDiagResultRam[LucSearchIndex] = (LusConvertedValue |
                                                ADC_PWM_RESULT_READ);
            /* END Msg(4:0491)-5 */
          }
          else
          {
            /* No action required */
          }
          /* MISRA Violation: START Msg(4:4461)-9 */
          /* read the converted result in the buffer */
          *pDataBuffer = LusConvertedValue & ADC_ADCAPWDDIR_CH_MASK;
          /* END Msg(4:4461)-9 */
          /* Set the return value to E_OK */
          LddRetValue = E_OK;
        }
      }
      else
      {
        /* Set the return value to E_OK */
        LddRetValue = E_NOT_OK;
      }
    }
    else
    {
      /* No action required */
    }
    /* Decrement search index */
    LucSearchCnt--;
  }
  while ((ADC_ZERO != LucSearchCnt) && (ADC_TRUE != LblResultAvailable));

  #else /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  /* Read the user base configuration register of the hardware unit */
  LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* Read the channel's converted value */
  LusConvertedValue = LpAdcRegisters->ulPWDDIR;
  /* MISRA Violation: START Msg(4:4461)-9 */
  /* Get the Analog channel Id which is converted */
  LusVarValue = ((LusConvertedValue >> ADC_SHIFT_16) &
                                                     ADC_PWM_DIAGGRP_CH_MASK);
  /* END Msg(4:4461)-9 */
  /* Read the actual physical channel with masking Range Between value */
  LusChannelMask = LpPwmDiagGroup->usChannelMask;
  /*
   * Check if the digital result value is ready for the physical channel
   * configured for the requested group and if Limit check error is occurred.
   */
  if (LusChannelMask == LusVarValue)
  {
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    LblLimitCheckErrorFlag = ADC_FALSE;
    if (ADC_FALSE == LpPwmDiagGroup->blLimitCheckEnabled)
    {
      /* MISRA Violation: START Msg(4:4461)-9 */
      /* Copy the converted value to the internal buffer */
      *pDataBuffer = LusConvertedValue & ADC_ADCAPWDDIR_CH_MASK;
      /* END Msg(4:4461)-9 */
      LddRetValue = E_OK;
    }
    else if ((ADC_NO_LIMIT_ERROR == (LpAdcRegisters->ulULER &
                                            ADC_UE_LE_LIMIT_CHK_ERROR)))
    {
      /* MISRA Violation: START Msg(4:4461)-9 */
      /* Copy the converted value to the internal buffer */
      *pDataBuffer = LusConvertedValue & ADC_ADCAPWDDIR_CH_MASK;
      /* END Msg(4:4461)-9 */
      LddRetValue = E_OK;
    }
    else
    {
      /*
       * Since the digital value is not within the specified range for channel
       * configured for this group, the out of range digital values are not
       * not copied to application buffer.
       */
      LblLimitCheckErrorFlag = ADC_TRUE;
      /*
       * Update ADCAnECR register to clear the error flags,
       * so that on next iteration previous error is not reflected
       */
      #if (ADC_ERROR_SUPPORT == STD_ON)
      Adc_ErrIsr(LucVariable);
      #endif
      #if (ADC_ERROR_SUPPORT == STD_OFF)
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

      /* END Msg(4:3138)-22 */
      #endif
    }
    #else
    /* MISRA Violation: START Msg(4:2982)-18 */
      #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
      LblResultAvailable = ADC_TRUE;
      #endif
    /* END Msg(4:2982)-18 */
    /* MISRA Violation: START Msg(4:4461)-9 */
    /* Copy the converted value to the internal buffer */
    *pDataBuffer = LusConvertedValue & ADC_ADCAPWDDIR_CH_MASK;
    /* END Msg(4:4461)-9 */
    /* Set the return value to E_OK */
    LddRetValue = E_OK;
    #endif /* #if ADC_ENABLE_LIMIT_CHECK == STD_ON */

    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if (ADC_FALSE == LblLimitCheckErrorFlag)
    #endif /* #if ADC_ENABLE_LIMIT_CHECK == STD_ON */
    {
      /* Set the flag indicating if the search was successful */
      #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
      LblResultAvailable = ADC_TRUE;
      #endif
    }
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
      /* No action required */
    }
    #endif /* #if ADC_ENABLE_LIMIT_CHECK == STD_ON */
  }
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Implements AR_PN0076_FR_0209 */
  if (ADC_TRUE == LblResultAvailable)
  {
    /* Set the return value to E_OK */
    LddRetValue = E_OK;
    /* Check if external multiplexer is enabled for the group */
    if (ADC_TRUE == LpPwmDiagGroup->blExtMuxEnabled)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      Adc_GpPwmGroupData[LddGroup].ucStartChannelIndex++;
      LucIndex = Adc_GpPwmGroupData[LddGroup].ucStartChannelIndex;
      /* END Msg(4:0491)-5 */
      LucVariable = LpPwmDiagGroup->ucChannelCount +
                                       LpPwmDiagGroup->ucChannelToGroupIndex;
      /* Check if the channel read is the last one in the group */
      if (LucVariable > LucIndex)
      {
        /* Increment the number of channels converted */
        /* MISRA Violation: START Msg(4:0491)-5 */
        Adc_GpPwmGroupData[LddGroup].ucStartChannelIndex++;
        /* Get the index of the trigger source of the PWM diagnostic group */
        LucVariable = Adc_GpPwmGroupData[LddGroup].ucTriggSrcIndex;
        /* Get the pointer to PWM Diagnostic trigger source */
        LpPwmDiagIds = &Adc_GpPwmDiagIds[LucVariable];
        /* END Msg(4:0491)-5 */
      }
      else
      {
        /* Reset to the first channel configured for the group */
        /* MISRA Violation: START Msg(4:0491)-5 */
        Adc_GpPwmGroupData[LddGroup].ucStartChannelIndex =
                                        LpPwmDiagGroup->ucChannelToGroupIndex;
        /* Get the pointer to PWM Diagnostic trigger source */
        LpPwmDiagIds = &Adc_GpPwmDiagIds[LucVariable];
        /* END Msg(4:0491)-5 */
      }
      /* Read the PWM Diagnostic virtual channel register */
      LulPwmReadVariable =
                 Adc_GaaPWSAReg_BaseAddress->ulPVCR[LpPwmDiagIds->ucPVCRIndex];
      /* clear the part that will be rewritten */
      LulPwmReadVariable &=
                   (~((uint32)(ADC_PWSAPVCR_MASK) << LpPwmDiagIds->ucOffset));
      /* Load the PWM Diagnostic virtual channel in local variable */
      /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpRegWrite =
         &Adc_GaaPWSAReg_BaseAddress->ulPVCR[LpPwmDiagIds->ucPVCRIndex];
      LulRegWriteValue = (LulPwmReadVariable |
         ((uint32)Adc_GpChannelToGroup[LucVariable] << LpPwmDiagIds->ucOffset));
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_PWMDIAG_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                    &Adc_GaaRamMirrorPWSAReg.ulPVCR[LpPwmDiagIds->ucPVCRIndex]);
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
                 ADC_WV_ENH_LC_MASK_PWSA_PVCR, ADC_INTHWRESULTREADGROUP_API_ID);
      #else
      ADC_PWMDIAG_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
                      ADC_WV_MASK_PWSA_PVCR, ADC_INTHWRESULTREADGROUP_API_ID);
      #endif
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
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
  #endif /* #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON) */
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
** Function Name        : Adc_IntDisableEnableChannel
**
** Service ID           : NA
**
** Description          : This is internal function, used to enable or disable
**                        a channel for conversion during runtime.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LddChannelId and LblApiType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpChannelToGroup,
**                        Adc_GpChannelToDisableEnable,
**                        Adc_GpGroupRamData
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
*******************************************************************************/
#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_112 */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntDisableEnableChannel
(Adc_GroupType LddGroup, Adc_ChannelType LddChannelId, boolean LblApiType)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  uint16 LusGroupChannel;
  uint16 LusRequestedChannel;
  uint8 LucChannelToGroupIndex;
  uint8 LucNumofChannels;
  uint8 LucLoopCount;
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Get the pointer to requested group configuration */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Get group index of 1st channel, configured for the requested group */
  LucChannelToGroupIndex = LpGroup->ucChannelToGroupIndex;
  /* Read the number of channels in the group */
  LucNumofChannels = LpGroup->ucChannelCount;
  /* Type cast the requested channel */
  LusRequestedChannel = (uint16)LddChannelId;
  /*make the Adc_GpChannelToDisableEnable[] true or false for conversion */
  for (LucLoopCount = ADC_ZERO; LucNumofChannels > LucLoopCount; LucLoopCount++)
  {
    /* MISRA Violation: START Msg(4:0491)-5 */
    LusGroupChannel =
    (Adc_GpChannelToGroup[LucChannelToGroupIndex] & ADC_MASK_CHANNEL);
    /* END Msg(4:0491)-5 */
    /* Check the channel to disable */
    if (LusRequestedChannel == LusGroupChannel)
    {
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      LenDetErrFlag = E_OK;
      #endif
      /* Set the flag indicating to enable or disable the channel Id */
      /* MISRA Violation: START Msg(4:0491)-5 */
      if (Adc_GpChannelToDisableEnable[LucChannelToGroupIndex] == LblApiType)
      {
        /* Set the flag indicating to enable or disable the channel Id */
        Adc_GpChannelToDisableEnable[LucChannelToGroupIndex] = LblApiType;
      }
      /* END Msg(4:0491)-5 */
      else
      {
        /* Set the flag indicating to enable or disable the channel Id */
        /* MISRA Violation: START Msg(4:0491)-5 */
        Adc_GpChannelToDisableEnable[LucChannelToGroupIndex] = LblApiType;
        /* END Msg(4:0491)-5 */
        /* Check if Adc_EnableChannel or Adc_DisableChannel was called */
        if (ADC_FALSE == LblApiType)
        {
          /* Increment the number of channels disabled */
          LpGroupData->ucNoofChDisabled++;
        }
        else
        {
          /* Decrement the number of channels disabled */
          LpGroupData->ucNoofChDisabled--;
        }
      }
      /* MISRA Violation: START Msg(4:2469)-3 */
      /* Exit the Loop */
      LucLoopCount = LucNumofChannels;
      /* END Msg(4:2469)-3 */
    }
    else
    {
      /* Increment the pointer to next channel configured in the group */
      LucChannelToGroupIndex++;
    }
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if (E_NOT_OK == LenDetErrFlag)
  {
    if (ADC_FALSE == LblApiType)
    {
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_DISABLE_CHANNEL_SID, ADC_E_PARAM_CHANNEL);
    }
    else
    {
      /* Report Error to DET */
      (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_ENABLE_CHANNEL_SID, ADC_E_PARAM_CHANNEL);
    }
  }
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
** Function Name        : Adc_PollingReadGroup
**
** Service ID           : NA
**
** Description          : This is internal function, used to update the
**                        group status, get the converted value from the
**                        peripheral registers, call the call-back function if
**                        enabled.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LucChannelCount
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GpSgUnitConfig,
**                        Adc_GpDmaUnitConfig, Adc_GpGroupConfig,
**                        Adc_GpRunTimeData
**
** Functions invoked    : Adc_DmaIsr, Adc_GroupCompleteMode,
**                        Adc_ChannelCompleteMode, Adc_ErrIsr
**
** Registers Used       : DCSTm, DCSTCm, ADCAnDIRj, ADCAnOWER, ADCAnULER
**                        ADCAnECR, ADCAnDGCTL0, ADCAnDGCTL1, ADCAnADCR,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnTHSMPSTCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHGSR, ADCAnTHER, ADCAnTHCR,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnSGSTCRx,
**                        ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DSAm, DDAm, DTCm,
**                        DRSAm, DRDAm, DRTCm, DTCTm, ADCAnDRj, ADCAnVCRj,
**                        ICDMAm, ICADCAnIm, WUF0, WUFC0
*******************************************************************************/
#if (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_122 */
FUNC(void, ADC_PRIVATE_CODE) Adc_PollingReadGroup (Adc_GroupType LddGroup,
                                                         uint8 LucChannelCount)
{
  uint8 LucHwUnit;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  #endif
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
          (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                       (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  #endif
  /* Hardware unit index */
  uint8 LucHwUnitIndex;
  #if (ADC_ERROR_SUPPORT == STD_ON)
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  #endif
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpResultRegister;
  /* Pointer to the hardware unit configuration address */
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
          (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                       (ADC_ENABLE_EXTERNAL_MUX == STD_ON) || \
                                       (ADC_DMA_MODE_ENABLE == STD_ON))
  uint8 LucSgUnitIndex;
  #endif
  Adc_StatusType LenGroupStatus;

  /* Get the pointer to requested group configuration */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = LpGroup->ucHwUnitIndex;
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize the local variable for HW unit configuration */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
  /* END Msg(4:0491)-5 */
  /* Read the hardware unit index*/
  LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
  #if (ADC_ERROR_SUPPORT == STD_ON)
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  if (ADC_GROUP_DMA_ACCESS == (LpGroup->ucGroupSettings &
                                                  ADC_GROUP_RESULT_ACCESS_MASK))
  {
    LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LpSgUnitConfig->ucDmaChannelIndex];
    LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
    LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
    /* Check of the transfer is completed */
    if (ADC_DMA_TRANSFER_COMPLETED ==
                        (LpDmaRegisters->ulDCST & ADC_DMA_TRANSFER_COMPLETED))
    {
      /* Implements AR_PN0076_FR_0066 */
      Adc_DmaIsr(LucHwUnit, (LpGroup->ucSgUnitIndex -
                                         (LucHwUnit * ADC_NO_OF_SG_UNITS)));
      /* Clear the DTSmTC which indicates transfer status */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCSTC, ADC_TRANSFER_FLAG_CLEAR);
      ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCST,
                            ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCST_CLEAR,
                            ADC_POLLINGREADGROUP_API_ID);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No action required */
    }
  }
  else
  #endif
  {
    LpResultRegister = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
    #if (ADC_ERROR_SUPPORT == STD_ON)
    /* Implements AR_PN0076_FR_0300 */
    /* Implements SWS_Adc_00281, AR_PN0076_FSR_0003 */
    /* Implements SWS_Adc_00281, AR_PN0076_FSR_0004 */
    /* Check if Error occurred or not */
    if (((ADC_ERROR_ULER ==
                       (ADC_ERROR_ULER & LpHwUnitConfig->ulErrorEnableValue)) &&
         (ADC_NO_LIMIT_ERROR !=
                       (LpAdcRegisters->ulULER & ADC_UE_LE_LIMIT_CHK_ERROR))) ||
         ((ADC_ERROR_OWER ==
                       (ADC_ERROR_OWER & LpHwUnitConfig->ulErrorEnableValue)) &&
          (ADC_NO_OVERWRITE_ERROR != LpAdcRegisters->ulOWER)))
    {
      Adc_ErrIsr(LucHwUnit);
      /* END Msg(4:0491)-10 */
      /* Check if the conversion is completed */
      if (ADC_RESULT_AVAILABLE == (LpResultRegister->
          ulDIR[(LpGroup->ulStartVirChPtr + LucChannelCount - ADC_ONE)] &
          ADC_RESULT_AVAILABLE))
      {
        /* Invoke group complete function */
        Adc_GroupCompleteMode(LddGroup, LucHwUnit);
      }
      else
      {
        /* No action required */
      }
    }
    else
    #endif
    {
      #if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
              (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                           (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
      /* Check if group is configured in abort/restart mode */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /* Implements ADC310, SWS_Adc_00310,  ADC430, SWS_Adc_00430 */
      if (((ADC_GROUP_ABORT_RESTART == (Adc_GpGroupConfig[LddGroup]
                     .ucGroupSettings & ADC_GROUP_REPLACEMENT_MASK)))
                                 ||  (Adc_GucMaxSwTriggGroups <= LddGroup))
      /* END Msg(4:0491)-5 */
      #endif
      {
        /* Buffer group status */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LenGroupStatus = Adc_GpGroupRamData[LddGroup].enGroupStatus;
        /* END Msg(4:0491)-5 */
        /* Check if the conversion is completed */
        if (ADC_RESULT_AVAILABLE == (LpResultRegister->
               ulDIR[((LpGroup->ulStartVirChPtr + LucChannelCount) - ADC_ONE)] &
               ADC_RESULT_AVAILABLE))
        {
          /* Invoke group complete function */
          Adc_GroupCompleteMode(LddGroup, LucHwUnit);
        }
        else
        {
          /* No action required */
        }
        /* Check if the conversion is completed */
        if (ADC_STREAM_COMPLETED == LenGroupStatus)
        {
          /* If the group is continuous group (SW) */
          if (ADC_GROUP_CONTINUOUS ==
             (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
          {
            /* Change the conversion status to ADC_BUSY */
            /* MISRA Violation: START Msg(4:0491)-5 */
            Adc_GpGroupRamData[LddGroup].enGroupStatus = ADC_BUSY;
            /* END Msg(4:0491)-5 */
          }
          /* If the group is one-shot HW triggered */
          else if ((ADC_GROUP_ONCE ==
          (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK)) &&
          (Adc_GucMaxSwTriggGroups <= LddGroup))
          {
            /* If the group is linear streaming */
            if (ADC_GROUP_ACCESS_STREAMING ==
            (LpGroup->ucGroupSettings & ADC_GROUP_ACCESS_MASK))
            {
              /* Change the conversion status to ADC_IDLE */
              /* MISRA Violation: START Msg(4:0491)-5 */
              Adc_GpGroupRamData[LddGroup].enGroupStatus = ADC_IDLE;
              /* END Msg(4:0491)-5 */
            }
            else
            {
              /* Change the conversion status to ADC_BUSY */
              /* MISRA Violation: START Msg(4:0491)-5 */
              Adc_GpGroupRamData[LddGroup].enGroupStatus = ADC_BUSY;
              /* END Msg(4:0491)-5 */
            }
          }
          else
          {
            /* Change the conversion status to ADC_IDLE */
            /* MISRA Violation: START Msg(4:0491)-5 */
            Adc_GpGroupRamData[LddGroup].enGroupStatus = ADC_IDLE;
            /* END Msg(4:0491)-5 */
          }
        }
        else if (ADC_COMPLETED == LenGroupStatus)
        {
          /* Change the conversion status to ADC_BUSY */
          /* MISRA Violation: START Msg(4:0491)-5 */
          Adc_GpGroupRamData[LddGroup].enGroupStatus = ADC_BUSY;
          /* END Msg(4:0491)-5 */
        }
        else
        {
          /* Do Nothing */
        }
      }
      #if (((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
              (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW)) || \
                                           (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
      else /* channel complete function */
      {
        LucSgUnitIndex = LpGroup->ucSgUnitIndex;
        /* Read the group data pointer */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
        /* END Msg(4:0491)-5 */
        /* Check if the conversion is completed */
        if (ADC_RESULT_AVAILABLE == (LpResultRegister->
                  ulDIR[(LpGroup->ulStartVirChPtr +
                  LpRunTimeData->ucChannelsCompleted)] & ADC_RESULT_AVAILABLE))
        {
          /* Invoke channel complete function */
          Adc_ChannelCompleteMode(LddGroup, LucHwUnit);
        }
        else
        {
          /* No action required */
        }
      }
      #endif
    }
  }
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT) */

/*******************************************************************************
** Function Name        : Adc_IsrConfigureGroupForConversion
**
** Service ID           : NA
**
** Description          : This function pop out and restart the group for
**                        conversion.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpGroupConfig, Adc_GpSgUnitRamData,
**                        Adc_GpGroupRamData, Adc_GpChannelToGroup,
**                        Adc_GpDmaUnitConfig, Adc_GucMaxSwTriggGroups,
**                        Adc_GpHwUnitConfig, Adc_GpLimitCheckRange,
**                        Adc_GpSgUnitConfig, Adc_GpRunTimeData
**
** Functions invoked    : Adc_IcrInterruptBit, Adc_ClearPendingInterrupt,
**                        Adc_HaltADConversion
**
** Registers Used       : ADCAnULLMTBRx, ADCAnSGCRx, DCENm, DCSTCm, DSAm, DDAm,
**                        DTCm, DRSAm, DRDAm, DRTCm, DTCTm, ADCAnADCR, DCSTm
**                        ADCAnDGCTL0, ADCAnDGCTL1, ADCAnPDCTL1, ADCAnPDCTL2,
**                        ADCAnSGVCSPx, ADCAnSGVCEPx, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnTHSMPSTCR,
**                        ADCAnSGSTCRx, ADCAnDRj, ADCAnVCRj, ICDMAm, ICADCAnIm
*******************************************************************************/
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                              (ADC_ENABLE_QUEUING == STD_ON)))

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_127 */
/* Implements ADC_ESDD_UD_165 */
/* Implements ADC_ESDD_UD_166 */
/* Implements ADC_ESDD_UD_214 */
FUNC(void, ADC_FAST_CODE) Adc_IsrConfigureGroupForConversion(
                                                 Adc_GroupType LddGroup)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  #endif
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpVirChannel;
  P2VAR(Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Adc_RunTimeData, AUTOMATIC, ADC_CONFIG_DATA) LpRunTimeData;
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #endif
  uint8 LucChannelToGroupIndex;
  uint8 LucLoopCount;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint8 LucDataRegisterIndex;
  #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ADC_CONFIG_DATA) LpDmaIntpCntrlReg;
  #endif
  #endif

  #if ((ADC_SELF_DIAG_SUPPORT == STD_ON) && \
                 (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON))
  volatile uint32 LusSelfDiagDelayCount;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  uint8 LucMaxLimitcheck;
  uint8 LucLimitCheckIndex;
  uint8 LucLimitLoopCount;
  #endif
  uint32 LulRegValues;
  uint8 LucHwUnit;
  uint8 LucSgUnitIndex;
  #if (((ADC_DMA_MODE_ENABLE == STD_ON) && \
        (ADC_FUNCTIONALITY_MODE != ADC_POLLING)) || \
       (ADC_FUNCTIONALITY_MODE != ADC_POLLING) || \
       (ADC_TRACK_AND_HOLD == STD_ON))
  uint8 LucSgUnitId;
  #endif
  uint8 LucChannelCount;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;

  uint32 LulRegWriteValue;
  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* Read the hardware unit of the group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  /* Get the SGm unit index to which the channel group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  LucHwUnit = LpGroup->ucHwUnitIndex;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LpSgUnitConfig->ucDmaChannelIndex];
  /* END Msg(4:0491)-5 */
  #endif
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* Initialize Group RAM data to a local pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Read the group data pointer */
  LpRunTimeData = &Adc_GpRunTimeData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Get the no of channels configured for the requested group */
  LucChannelCount = (LpGroup->ucChannelCount - LpGroupData->ucNoofChDisabled);
  #else
  /* Get the no of channels configured for the requested group */
  LucChannelCount = LpGroup->ucChannelCount;
  #endif
  /* Initialize the number of channels present in the group */
  LpRunTimeData->ucChannelCount = LucChannelCount;
  /* Read the number of samples configured for that group */
  LpRunTimeData->ucStreamingSamples = LpGroup->ddNumberofSamples;

  /* Initialize the number of converted channels to zero */
  LpRunTimeData->ucChannelsCompleted = ADC_ZERO;

  #if (ADC_ENABLE_STREAMING == STD_ON)
  /*
   * Initialize the number of conversion rounds completed before getting
   * aborted or suspended
   */
  LpRunTimeData->ucSamplesCompleted = LpGroupData->ucReSamplesCompleted;
  /* Clear the samples completed RAM variable */
  LpGroupData->ucReSamplesCompleted = ADC_ZERO;
  /*
   * Initialize the group's buffer pointer from the channel
   * which was suspended or aborted
   */
  LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer +
                                      LpRunTimeData->ucSamplesCompleted;
  #else
  /* Initialize the number of conversion rounds to zero */
  LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
  /*
   * Initialize the group's buffer pointer from the channel
   * which was suspended or aborted
   */
  LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
  #endif /* #if (ADC_ENABLE_STREAMING == STD_ON) */
  /*
   * Initialize the number of converted channels to previously
   * stopped channel count value
   */
  LpRunTimeData->ucChannelsCompleted = LpGroupData->ucReChannelsCompleted;
  /* Clear the channels completed RAM variable */
  LpGroupData->ucReChannelsCompleted = ADC_ZERO;
  /* MISRA Violation: START Msg(4:0488)-1 */
  /*
   * Initialize the group's buffer pointer from the channel
   * which was suspended
   */
  LpRunTimeData->pBuffer = LpRunTimeData->pBuffer +
                                        LpRunTimeData->ucChannelsCompleted;
  /* END Msg(4:0488)-1 */
  /* Set the RAM variable indicating current group active in HW unit is SW */
  LpSgUnitData->enTrigSource = ADC_TRIGG_SRC_SW;
  /* Read the user base configuration address of the hardware unit */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* END Msg(4:0491)-5 */

  /* Buffer the status of SGSTR */
  /* MISRA Violation: START Msg(2:2814)-27 */
  LulRegSGSTR = LpAdcRegisters->ulSGSTR;
  /* END Msg(2:2814)-27 */

  /* Read the SG offset */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegSGCR[ADC_SG1] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegSGCR[ADC_SG2] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegSGCR[ADC_SG3] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */

  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
  Adc_HaltADConversion(LucHwUnitIndex);

  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  if (ADC_TRUE == LpGroup->blLimitCheckEnabled)
  {
    LucMaxLimitcheck = LpGroup->ucMaxLimitcheck;
    LucLimitCheckIndex = LpGroup->ucLimitCheckIndex;
    #if (ADC_FLEXIBLE_THRESHOLD == STD_ON)
    for (LucLimitLoopCount = ADC_ZERO; LucMaxLimitcheck > LucLimitLoopCount;
                                                        LucLimitLoopCount++)
    {
      /* Implements AR_PN0076_FR_0032 */
      /* Load the upper limit for error check */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      if (LucLimitLoopCount > ADC_TWO)
      {
       LpRegWrite = &LpAdcRegisters->ulULLMTBR2
                                      [LucLimitLoopCount - ADC_ULLMTBR2_OFSET];
      }
      else
      {
        LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      }
      #else
      LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      #endif

      LulRegWriteValue = Adc_GpFlexibleLimitCheckRange[LucLimitCheckIndex +
                                                       LucLimitLoopCount];
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
              &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].
              ulULLMTBR[LucLimitLoopCount]);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
              ADC_WV_MASK_ULLMTBR, ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
    }
    #else
    for (LucLimitLoopCount = ADC_ZERO; LucMaxLimitcheck > LucLimitLoopCount;
                                                        LucLimitLoopCount++)
    {
      /* Implements AR_PN0076_FR_0032 */
      /* Load the upper limit for error check */
      /* MISRA Violation: START Msg(4:0491)-5 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      if (LucLimitLoopCount > ADC_TWO)
      {
       LpRegWrite = &LpAdcRegisters->ulULLMTBR2
                                      [LucLimitLoopCount - ADC_ULLMTBR2_OFSET];
      }
      else
      {
        LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      }
      #else
      LpRegWrite = &LpAdcRegisters->ulULLMTBR[LucLimitLoopCount];
      #endif


      LulRegWriteValue = Adc_GpLimitCheckRange[LucLimitCheckIndex +
                                               LucLimitLoopCount];
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
              &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].
              ulULLMTBR[LucLimitLoopCount]);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite, LulRegWriteValue,
              ADC_WV_MASK_ULLMTBR, ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
      /* END Msg(4:0491)-5 */
    }
    #endif
  }
  else
  {
    /* No actions Required */
  }
  #endif
  #if (((ADC_DMA_MODE_ENABLE == STD_ON) && \
        (ADC_FUNCTIONALITY_MODE != ADC_POLLING)) || \
       (ADC_FUNCTIONALITY_MODE != ADC_POLLING) || \
       (ADC_TRACK_AND_HOLD == STD_ON))
  /* Get the SG unit Id to which this group is mapped */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  #endif
  /* Get the register pointing to SG unit mapped */
  LucSgRegIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgRegIndex;
  /* END Msg(4:0491)-5 */
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /* Configure the hardware unit with the group's operation mode */
  LulRegValues =
        Adc_GaaOperationMask[(LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK)];
  /* Update to generate output when the scan for SGx ends */
  LulRegValues = (LulRegValues | ADC_INT_SG_END);
  /* Load the SGCRx register */
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Implements AR_PN0076_FR_0209 */
  /* Implements AR_PN0076_FR_0102 */
  /* check weather the group is enabled for external mux */
  if (ADC_TRUE ==  LpGroup->blExtMuxEnabled)
  {
    /* Set the end interrupt enable bit and Disable the continuous conversion */
    LulRegWriteValue = ((LulRegValues) & ((ADC_MUX_GROUP) |
                            (~(LpGroup->ucGroupSettings << ADC_THREE))));
  }
  else
  {
    LulRegWriteValue = LulRegValues;
  }
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR, LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                  LulRegWriteValue, ADC_WV_MASK_SGCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* Set applicable TRGMD of buffer to 0 */
  LulRegSGCR[LucSgRegIndex-LucSGOffset] = LulRegWriteValue;
  #else
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGCR, LulRegValues,
                  &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGCR,
                  LulRegValues, ADC_WV_MASK_SGCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* Set applicable TRGMD of buffer to 0 */
  LulRegSGCR[LucSgRegIndex-LucSGOffset] = LulRegValues;
  /* END Msg(4:3138)-22 */
  #endif

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  LpSgUnitData->ddCurrentPriority = LpGroup->ddGroupPriority;
  #endif
  /* Update the hardware unit ram data with the current group information */
  LpSgUnitData->ddCurrentConvGroup = LddGroup;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  if (ADC_GROUP_DMA_ACCESS == (LpGroup->ucGroupSettings &
                                                 ADC_GROUP_RESULT_ACCESS_MASK))
  {
    /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
    /* Implements AR_PN0076_FR_0066 */
    LucDataRegisterIndex = LpSgUnitConfig->ucDataRegisterIndex;
    LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
    LpDmaRegisters = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
    /* Clear DMA channel suspension */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DISABLE_DMA_TRANSFER);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCEN,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCEN,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* Clear Transfer Status flag */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCSTC, ADC_TRANSFER_FLAG_CLEAR);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCST,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DCST_CLEAR,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */

    /*
     * Load the source address of data register which is allocated for the
     * SG unit
     */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(4:0303)-4 */
    LulRegWriteValue = (uint32)&(Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex]->
                                      usDR[LucDataRegisterIndex]);
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDSA, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDSA,
                LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0303)-4 */
    /* MISRA Violation: START Msg(4:0306)-20 */
    /* Load the destination address register */
    LulRegWriteValue = (uint32)LpRunTimeData->pBuffer;
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDDA, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDDA,
                LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0306)-20 */
    /* Load the transfer count value to the DMA register */
    LulRegWriteValue = ((uint32)LucChannelCount -
                                LpRunTimeData->ucChannelsCompleted);
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDTC, LulRegWriteValue);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDTC,
                  LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* Clear the TC and DTE bit */

    /* MISRA Violation: START Msg(4:0303)-4 */
    LulRegWriteValue = (uint32)&(Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex]->
                                                 usDR[LucDataRegisterIndex]);
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRSA, LulRegWriteValue,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRSA);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRSA,
                  LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0303)-4 */
    /* MISRA Violation: START Msg(4:0306)-20 */
    /* Load the destination address register */
    LulRegWriteValue = (uint32)LpRunTimeData->pBuffer;
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRDA,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRDA);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRDA,
                  LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:0306)-20 */
    /* Load the transfer count value to the DMA register */
    LulRegWriteValue =
               ((uint32)LucChannelCount - LpRunTimeData->ucChannelsCompleted);
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDRTC,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDRTC);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDRTC,
                  LulRegWriteValue, ADC_WV_MASK_ALL_32BIT,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* If the group is continuous or HW triggered group */
    if ((ADC_GROUP_CONTINUOUS ==
                              (LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK))
    #if (ADC_HW_TRIGGER_API == STD_ON)
    || (LddGroup >= Adc_GucMaxSwTriggGroups)
    #endif
    )
    {
      /* Set the LE bit for continuous data transfer */
      LulRegWriteValue =
                 ((uint32)(LpDmaRegisters->ulDTCT | ADC_DMA_CONTINUOUS));
    }
    else
    {
      /* Clear the LE bit for continuous data transfer */
      LulRegWriteValue = ((uint32)(LpDmaRegisters->ulDTCT & ADC_DMA_ONCE));
    }
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_DMAC_WRITE_REG_AND_MIRROR(&LpDmaRegisters->ulDTCT, LulRegWriteValue,
                  &Adc_GaaRamMirrorDmaReg[LucDmaRegIndex].ulDTCT);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDTCT,
                  LulRegWriteValue, ADC_WV_MASK_DTCT,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
    /* Check if the Group is mapped for HW configured for interrupt mode */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                      .enFunctionalityModeType)
    /* END Msg(4:0491)-5 */
    {
      /* MISRA Violation: START Msg(4:0317)-19 */
      /* Enable the DMA interrupt control register */
      LpDmaIntpCntrlReg = LpSGmDmaConfig->pIntCntlReg;
      /* END Msg(4:0317)-19 */
      /* Implements EAAR_PN0034_FR_0067 */
      /* Enable the DMA channel interrupt */
      RH850_SV_MODE_ICR_AND (16, (LpDmaIntpCntrlReg), ADC_INTERRUPT_MASK_EN);
      /* Disable the interrupt for the SGm unit to which the group is mapped */
      Adc_IcrInterruptBit(LucSgUnitIndex, ADC_DISABLE_INTERRUPT);

      /*
       * Clear the pending interrupt for the SGm unit to which the
       * group is mapped
       */
      Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */
    /* DMA transfer enable */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpDmaRegisters->ulDCEN, ADC_DMA_ENABLE);
    ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(&LpDmaRegisters->ulDCEN,
                  ADC_DMA_ENABLE, ADC_WV_MASK_DCEN,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  else
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  {
    #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING)
    /* Check if the Group is mapped for HW configured for interrupt mode */
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_INTERRUPT_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                      .enFunctionalityModeType)
    /* END Msg(4:0491)-5 */
    {
      #if (ADC_DMA_MODE_ENABLE == STD_ON)
      if (ADC_NO_DMA_CHANNEL_INDEX != LpSgUnitConfig->ucDmaChannelIndex)
      {
        /* Get the pointer to the DMA configuration */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpSGmDmaConfig =
                        &Adc_GpDmaUnitConfig[LpSgUnitConfig->ucDmaChannelIndex];
        /* END Msg(4:0491)-5 */
        /*
         * Disable the DMA interrupt for the DMA channel Id configured
         * for the SGm unit in which the group is mapped
         */
         /* MISRA Violation: START Msg(4:0317)-19 */
        LpDmaIntpCntrlReg = LpSGmDmaConfig->pIntCntlReg;
        /* END Msg(4:0317)-19 */
        /* MISRA Violation: START Msg(4:4397)-8 */
        /* Implements EAAR_PN0034_FR_0067 */
        /* Disable the DMA channel interrupt */
        RH850_SV_MODE_ICR_OR(16, (LpDmaIntpCntrlReg), ADC_INTERRUPT_MASK_DIS);
        /* END Msg(4:4397)-8 */
      }
      else
      {
        /* No action required */
      }
      #endif
      /*
       * Clear the pending interrupt for the SGm unit to which the
       * group is mapped
       */
      Adc_ClearPendingInterrupt(LucHwUnit, LucSgUnitId);
      /* Enable the interrupt for the SGm unit to which the group is mapped */
      Adc_IcrInterruptBit(LucSgUnitIndex, ADC_ENABLE_INTERRUPT);
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (ADC_FUNCTIONALITY_MODE != ADC_POLLING) */
  }

  #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
  #if (ADC_ENABLE_SELF_DIAG_PIN_LVL == STD_ON)
  /* Check the group is configured as self diag Circuit conversion
     or in self diag MUX conversion  */
  if ((ADC_SELF_DIAG_CONV_CKT == LpGroup->enSelfDiagMode) ||
                     (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode))
  {
    /* Turn ON self-diagnostic voltage circuit */
    LulRegWriteValue = (LpAdcRegisters->ulADCR | ADC_ENABLE_SELF_DIAG);
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                LulRegWriteValue, ADC_WV_MASK_ADCR,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* initialize the delay loop count to zero */
    LusSelfDiagDelayCount = ADC_ZERO;
    /* wait for the specified time period */
    /* QAC Warning: START Msg(2:3416)-23 */
    while (ADC_SELF_DIAG_DELAY_COUNT != LusSelfDiagDelayCount)
    {
      LusSelfDiagDelayCount++;
    }
    /* END Msg(2:3416)-23 */
    /* Implements AR_PN0076_FSR_0004 */
    /* configure the reference voltage */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                  LpGroup->ulAdcSelfDiagVolLevSel,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                  LpGroup->ulAdcSelfDiagVolLevSel, ADC_WV_MASK_DGCTL0,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);

    /* update the self diag voltage level */
    LulRegWriteValue = (LpAdcRegisters->ulADCR | ADC_ENABLE_SELF_DIAG);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                LulRegWriteValue, ADC_WV_MASK_ADCR,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
    /* initialize the delay loop count to zero */
    LusSelfDiagDelayCount = ADC_ZERO;
    /* wait for the specified time period */
    while (ADC_SELF_DIAG_DELAY_COUNT != LusSelfDiagDelayCount)
    {
      LusSelfDiagDelayCount++;
    }
    if (ADC_SELF_DIAG_CH_MUX == LpGroup->enSelfDiagMode)
    {
      /* configure the channel to be connected  */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                    LpGroup->ulAdcSelfDiagChannelSel,
                    &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                    LpGroup->ulAdcSelfDiagChannelSel, ADC_WV_MASK_DGCTL1,
                    ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No action required */
    }
  }
  /* group is configured as normal group */
  else
  {
    /* Turn OFF self-diagnostic voltage circuit */
    /* MISRA Violation: START Msg(4:3138)-22 */
    LulRegWriteValue = (LpAdcRegisters->ulADCR & ADC_DISABLE_SELF_DIAG);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulADCR, LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulADCR);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulADCR,
                  LulRegWriteValue, ADC_WV_MASK_ADCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* disconnect diag voltage selection */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL0,
                  ADC_SELF_DIAG_VLTG_DISABLE,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL0);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL0,
                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL0,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* Select ANInm as input */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulDGCTL1,
                  ADC_SELF_DIAG_VLTG_DISABLE,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulDGCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulDGCTL1,
                  ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_DGCTL1,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  #endif

  #if (ADC_ENABLE_SELF_DIAG_WIRE_BRK == STD_ON)
  /* check the group is configured in the open pin self diag support */
  if (ADC_SELF_DIAG_OPEN_PIN == LpGroup->enSelfDiagMode)
  {
    /* Implements AR_PN0076_FSR_0002 */
    /*  configure the channels selected for open pin functionality support
        by setting 1 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                LpGroup->ulAdcSelfDiagOpenPin1,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                LpGroup->ulAdcSelfDiagOpenPin1, ADC_WV_MASK_PDCTL1,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                LpGroup->ulAdcSelfDiagOpenPin2,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                LpGroup->ulAdcSelfDiagOpenPin2, ADC_WV_MASK_PDCTL2,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  /* group is configured as normal group */
  else
  {
    /* Implements AR_PN0076_FSR_0002 */
    /* Disconnect on-chip pull-down resistor */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL1,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL1);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL1,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL1,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulPDCTL2,
                ADC_DISABLE_PULL_DOWN_RESISTOR,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulPDCTL2);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulPDCTL2,
                ADC_DOUBLE_WORD_ZERO, ADC_WV_MASK_PDCTL2,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
    /* END Msg(4:3138)-22 */
  }
  #endif
  #endif
  /* Set the virtual channel start pointer */
  /* MISRA Violation: START Msg(4:3138)-22 */
  LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                                  LpRunTimeData->ucChannelsCompleted);
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCSP, LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCSP);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCSP,
                LulRegWriteValue, ADC_WV_MASK_SGVCSP,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  #if ((ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT) && \
                      (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
  if (ADC_POLLING_MODE == Adc_GpSgUnitConfig[LucSgUnitIndex]
                                                       .enFunctionalityModeType)
  {
    /* Check if group is configured with external multiplexed channel */
    if (((ADC_TRUE == LpGroup->blExtMuxEnabled) && ((LpGroup->ucGroupSettings &
                                 ADC_GROUP_REPLACEMENT_MASK))))
    {
      /*
       * Set the virtual channel end pointer value same as start because the
       * next channel will be started after the previous is completed
       */
      LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                                    LpRunTimeData->ucChannelsCompleted);
    }
    else
    {
      /* Set the virtual channel end pointer value */
      LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                                    ((uint32)LucChannelCount - ADC_ONE));
    }
  }
  else
  #endif /*
          * #if ((ADC_FUNCTIONALITY_MODE != ADC_INTERRUPT) && \
          *           (ADC_ENABLE_EXTERNAL_MUX == STD_ON))
          */
  {
    /* Set the virtual channel end pointer value */
    LulRegWriteValue = (LpGroup->ulStartVirChPtr +
                                    ((uint32)LucChannelCount - ADC_ONE));
  }
  /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
  /* Write the virtual channel end pointer value to the register */
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCEP, LulRegWriteValue,
                &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCEP);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCEP,
                LulRegWriteValue, ADC_WV_MASK_SGVCEP,
                ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /*
   * Initialize the virtual channels with the channel groups configured for
   * requested group.
   */

  /* Get group index of 1st channel, configured for the requested group */
  LucChannelToGroupIndex = LpGroup->ucChannelToGroupIndex;
  /* Re-Initialize the channel count to actual configured no of channels */
  LucChannelCount = LpGroup->ucChannelCount;
  /* Map the physical channels to the virtual channels */
  for (LucLoopCount = ADC_ZERO; (uint8_least)LucChannelCount >
                               LucLoopCount; LucLoopCount++)
  {
    #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-5 */
    if (ADC_TRUE == Adc_GpChannelToDisableEnable[LucChannelToGroupIndex])
    /* END Msg(4:0491)-5 */
    #endif /* #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON) */
    {
      LpVirChannel = Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex];
      #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && \
                                             (ADC_FLEXIBLE_THRESHOLD == STD_ON))
      if (ADC_TRUE == LpGroup->blLimitCheckEnabled)
      {
        /* Map the physical channels to the virtual channels */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRegWrite = &LpVirChannel->ulVCR[LpGroup->ulStartVirChPtr +
                                         LucLoopCount];
        LulRegWriteValue = Adc_GpFlexibleChannelToGroup[LucChannelToGroupIndex];
        /* END Msg(4:0491)-5 */
      }
      else
      #endif
      {
        /* Map the physical channels to the virtual channels */
        /* MISRA Violation: START Msg(4:0491)-5 */
        LpRegWrite = &LpVirChannel->ulVCR[LpGroup->ulStartVirChPtr +
                                         LucLoopCount];
        LulRegWriteValue = Adc_GpChannelToGroup[LucChannelToGroupIndex];
        /* END Msg(4:0491)-5 */
      }
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite, LulRegWriteValue,
                              &Adc_GaaRamMirrorAdcVirChReg[LucHwUnitIndex].
                              ulVCR[LpGroup->ulStartVirChPtr + LucLoopCount]);

      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                              (LulRegWriteValue & ADC_WV_ENHANCED_LC_MASK_VCR),
                              ADC_WV_ENHANCED_LC_MASK_VCR,
                              ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      #else
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
                              (LulRegWriteValue & ADC_WV_MASK_VCR),
                              ADC_WV_MASK_VCR,
                              ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      #endif

    /* END Msg(4:3138)-22 */
    }
    #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
    else
    {
      /* Do nothing */
    }
    #endif
    LucChannelToGroupIndex++;
  }

  /* T & H FUNCTIONALITY INT */
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  /*
   * Check if the group is mapped to ADC0 HW unit, because Track and hold is
   * supported by ADC0 unit only.
   */
  if (ADC_ZERO == LpGroup->ucHwUnitIndex)
  {
    /* Initialize the local variable for HW unit configuration */
    LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnit];
    /* Check if group is configured with Track and Hold enabled channel */
    if (ADC_TRUE == LpGroup->blTandHEnable)
    {
      /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
      /* Enable to perform automatic sampling */
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHCR, ADC_SET_ASMPMSK,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHCR,
                  ADC_SET_ASMPMSK, ADC_WV_MASK_THCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* Set the bit HLDCTE and the bit HLDTE in respective T&H Group */
      LulRegWriteValue = (ADC_SET_HLDCTE_HLDTE |
                              ((uint32)LucSgUnitId + ADC_ONE));
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                  LulRegWriteValue, ADC_WV_MASK_THACR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                  LulRegWriteValue, ADC_WV_MASK_THBCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* Enable the channels configured for Track and Hold functionality */
      LulRegWriteValue = (uint32)LpHwUnitConfig->ucTrackHoldMask;
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHER,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHER);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHER,
                  LulRegWriteValue, ADC_WV_MASK_THER,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* Map the channels to group A or B */
      LulRegWriteValue = (uint32)LpHwUnitConfig->ucGroupSelectMask;
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHGSR,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHGSR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHGSR,
                  LulRegWriteValue, ADC_WV_MASK_THGSR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* Set the bit HLDCTE and Clear the bit HLDTE in respective T&H Group */
      /* ADC_CLR_HLDTE = 0XFFFFFFEF */
      LulRegWriteValue = (LpAdcRegisters->ulTHACR & ADC_CLR_HLDTE);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHACR,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHACR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHACR,
                  LulRegWriteValue, ADC_WV_MASK_THACR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      LulRegWriteValue = (LpAdcRegisters->ulTHBCR & ADC_CLR_HLDTE);
      ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulTHBCR,
                  LulRegWriteValue,
                  &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulTHBCR);
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulTHBCR,
                  LulRegWriteValue, ADC_WV_MASK_THBCR,
                  ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
      /* Start sampling of all the Track and Hold channels */
      ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulTHSMPSTCR, ADC_SET_SMPST);
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* To avoid MISRA violation */
    }
  }
  else
  {
    /* To avoid MISRA violation */
  }
  #endif /* #if (ADC_TRACK_AND_HOLD == STD_ON) */
  /* Is the group status idle */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if (ADC_IDLE == Adc_GpGroupRamData[LddGroup].enGroupStatus)
  /* END Msg(4:0491)-5 */
  {
    /* Set the group status as busy */
    LpGroupData->enGroupStatus = ADC_BUSY;
  }
  else
  {
    /* No action required */
  }

  /* Writing back the previously configured TRGMD bits */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously Trigger conversion */
  /* If SG1 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ZERO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG1 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
    /* END Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG2 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ONE]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG2 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG3 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_TWO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG3 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }

  /* Initiate conversion */
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTCR, ADC_START_CONVERSION);
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /*
   * Check if the Group is popped from the queue and configured for
   * continuous conversion
   */
  if (ADC_GROUP_CONTINUOUS ==
                    ((uint8)(LpGroup->ucGroupSettings & ADC_GROUP_CONV_MASK)))
  #endif
  {
    /* Set the virtual channel start pointer */
    ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcSGRegisters->ulSGVCSP,
                       LpGroup->ulStartVirChPtr,
                       &Adc_GaaRamMirrorAdcSGReg[LucSgRegIndex].ulSGVCSP);
    ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcSGRegisters->ulSGVCSP,
                       LpGroup->ulStartVirChPtr, ADC_WV_MASK_SGVCSP,
                       ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID);
  }
  /* END Msg(4:3138)-22 */
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  else
  {
    /* No action required */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
** Function Name        : Adc_ErrIsr
**
** Service ID           : NA
**
** Description          : This function is an error interrupt service routine
**                      : for ADC.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpHwUnitConfig
**                        Adc_GpSgUnitIndex, Adc_GpSgUnitRamData,
**                        Adc_GpGroupRamData.
**
** Functions invoked    : None
**
** Registers Used       : ADCAnOWER, ADCAnULER, ADCAnECR, WUF0, WUFC0
*******************************************************************************/
#if (ADC_ERROR_SUPPORT == STD_ON)
/* Implements AR_PN0076_FSR_0016 */
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_START_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_082 */
/* Implements ADC_ESDD_UD_152 */
FUNC(void, ADC_FAST_CODE) Adc_ErrIsr(uint8 LucHwUnit)
{
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  /* Pointer to the hardware unit Os base configuration address */
  uint8 LucAdcHwUnitIndex;
  /* Pointer to the hardware unit configuration address */
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Local variable to store for ADCAnULER*/
  uint32 LulADCAnULER;
  #endif
  /* Local pointer Index of HW unit */
  uint8 LucHwUnitIndex;
  /* Local variable to store for ADCAnOWER*/
  uint32 LulADCAnOWER;
  /* Local variable to store for channel*/
  uint8 LucChannel;

  #if (ADC_WAKEUPFACTOR_CLEAR_ISR == STD_ON)
  uint32 LulRegWriteValue;
  #endif

  /* Get the requested HW unit index */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitIndex[LucHwUnit];
  /* Initialize the local variable for HW unit configuration */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Read the hardware unit index */
  LucAdcHwUnitIndex = LpHwUnitConfig->ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucAdcHwUnitIndex];

  /* Implements AR_PN0076_FR_0258 */
  if (NULL_PTR != LpHwUnitConfig->pErrorNotificationPointer)
  {
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Implements AR_PN0076_FR_0092 */
    /* Get the Limit Check Error Information*/
    LulADCAnULER = LpAdcRegisters->ulULER;
    /* Check if Limit check error occurred or Over write error */
    if (ADC_NO_LIMIT_ERROR != (LulADCAnULER & ADC_UE_LE_LIMIT_CHK_ERROR))
    {
      /* Get the channel that caused error */
      LucChannel = (uint8)(LulADCAnULER & ADC_CHANNEL_ISR);
    }
    else
    #endif
    {
      /* Get the Over Limit Error Information*/
      LulADCAnOWER = LpAdcRegisters->ulOWER;
      /* Get the channel that caused error */
      LucChannel = (uint8)(LulADCAnOWER & ADC_CHANNEL_ISR);
    }
    /* Invoke the call-back function */
    LpHwUnitConfig->pErrorNotificationPointer(LucChannel);
  } /* if (LpHwUnitConfig.pErrNotificationPointer != NULL_PTR) */
  else
  {
    /* No actions required */
  }
  /*
   * Update ADCAnECR register so that on next iteration previous error is
   * not reflected
   */
  /* MISRA Violation: START Msg(4:3138)-22 */
  ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulECR, ADC_CLR_ERROR_FLAG);

  /* END Msg(4:3138)-22 */
  #if (ADC_WAKEUPFACTOR_CLEAR_ISR == STD_ON)
  /* Check that ISR belong to the HW0 and wake up factor is occurred*/
  if ((ADC_ZERO == LucHwUnit) &&
                   (ADC_NO_WAKEUP_FACTOR != Adc_GaaWUFReg_BaseAddress->ulWUF0))
  {
      /* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0001 */
      /* Implements AR_PN0076_FR_0304 */
      /* Set the wake up factor clear register to clear the wake up factor */
      LulRegWriteValue = (Adc_GaaWUFReg_BaseAddress->ulWUF0 &
                          ADC_WUF_CLEAR_MASK_VALUE);
      /* MISRA Violation: START Msg(4:3138)-22 */
      ADC_WRITE_REG_ONLY(&Adc_GaaWUFReg_BaseAddress->ulWUFC0, LulRegWriteValue);
      ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(&Adc_GaaWUFReg_BaseAddress->ulWUF0,
                          ADC_ZERO, (ADC_WUF_CLEAR_MASK_VALUE),
                          ADC_ERRISR_API_ID);
      /* END Msg(4:3138)-22 */
  }
  else
  {
    /* Do nothing  */
  }
  #endif
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define ADC_STOP_SEC_CODE_FAST
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ERROR_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Adc_IntCusGetADCAnDRmAddr
**
** Service ID           : NA
**
** Description          : This is internal function, used to return the  ADC
**                        Data register address of the first virtual channel
**                        assigned to the ADC channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpSgUnitConfig, Adc_GpGroupConfig
**
** Functions invoked    : None
**
** Registers Used       : ADCAnDRj
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

FUNC(Adc_AddressType, ADC_PRIVATE_CODE) Adc_IntCusGetADCAnDRmAddr
                                                      (Adc_GroupType LddGroup)
{
  P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  Adc_AddressType LddRetValue;
  uint8 LucSgUnitIndex;
  uint8 LucHwUnit;
  uint8 LucHwUnitIndex;
  uint8 LucDataRegisterIndex;

  /* Read the hardware unit of the group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* END Msg(4:0491)-5 */
  LucHwUnit = LpGroup->ucHwUnitIndex;
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  /* Get the SGm unit to which the group is mapped */
  LucSgUnitIndex = LpGroup->ucSgUnitIndex;
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucDataRegisterIndex = Adc_GpSgUnitConfig[LucSgUnitIndex].ucDataRegisterIndex;
  /* END Msg(4:0491)-5 */
  /* Get the starting address of ADCAnDRm for the configured group */
  /* START Msg(4:0303)-4 */
  LddRetValue =
  (uint32)&(Adc_GaaVirChReg_BaseAddress[LucHwUnitIndex]->
                                               usDR[LucDataRegisterIndex]);
  /* END Msg(4:0303)-4 */
  /* return the value */
  return(LddRetValue);
}

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_IntEnableDisableAdcErr
**
** Service ID           : NA
**
** Description          : This function is will Enable or Disable the ADC Error
**                        Interrupt.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit and LblApiType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpHwUnitConfig
**
** Functions invoked    : None
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
/* Implements ADC_ESDD_UD_171 */
FUNC(void, ADC_PRIVATE_CODE) Adc_IntEnableDisableAdcErr(uint8 LucHwUnit,
                                                            boolean LblApiType)
{
  /* Pointer to the hardware unit configuration address */
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  /* Local pointer Index of HW unit */
  uint8 LucHwUnitIndex;

  /* Get the requested HW unit index */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucHwUnitIndex = Adc_GpHwUnitIndex[LucHwUnit];
  /* Initialize the local variable for HW unit configuration */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[LucHwUnitIndex];
  /* END Msg(4:0491)-5 */
  /* Check whether the Function is called to Enable or Disable the Error
     Interrupt support */
  /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0023 */
  if (ADC_FALSE == LblApiType)
  {
    /* MISRA Violation: START Msg(4:4397)-8 */
    RH850_SV_MODE_ICR_OR (16, (LpHwUnitConfig->pIntErrAddress),
                                            ADC_INTERRUPT_MASK_DIS);
    /* END Msg(4:4397)-8 */
    RH850_SV_MODE_ICR_AND (16, (LpHwUnitConfig->pIntErrAddress),
                                                  (ADC_CLEAR_INT_REQUEST_FLAG));
  }
  else
  {
    RH850_SV_MODE_ICR_AND (16, (LpHwUnitConfig->pIntErrAddress),
                                                     ADC_INTERRUPT_MASK_EN);
  }
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* #if (ADC_ERROR_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name        : Adc_HaltScanGroup
**
** Service ID           : NA
**
** Description          : Function to stop ongoing conversion by setting
**                        ADHALT bit.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Adc_GroupType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpHwUnitConfig
**
** Functions invoked    : Dem_ReportErrorStatus
**
** Registers Used      : ADCAnSGSTR, ADCAnADHALTR, ADCAnSGSTCRx
*******************************************************************************/
#if (ADC_HARD_STOP == STD_OFF)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_173 */
/* Implements ADC_ESDD_UD_174 */
/* Implements ADC_ESDD_UD_176 */
/* Implements ADC_ESDD_UD_051 */
/* Implements ADC_ESDD_UD_124 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HaltScanGroup(Adc_GroupType Group)
{
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint8 LucSgUnitId;
  uint32 LulADCAnSGSTR;
  uint8 LucHwUnit;
  uint8 LucSgUnitIndex;
  uint8 LucSGOffset;
  #if (ADC_SOFT_STOP == STD_ON)
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  volatile uint32 LulTimeOut;
  #endif
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = Adc_GpGroupConfig[Group].ucHwUnitIndex;

  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = Adc_GpGroupConfig[Group].ucSgUnitIndex;
  /* Get the SG unit Id to which this group is mapped */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(4:0491)-5 */
  /* Implements AR_PN0076_FR_0321 */
  #if (ADC_SOFT_STOP == STD_ON)
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  #endif
  /* Implements AR_PN0076_FR_0321 */
  #if (ADC_SOFT_STOP == STD_OFF)
  /* If the SG group is active HALT the conversion */
  if (ADC_NOT_BUSY != (LpAdcRegisters->ulSGSTR &
     Adc_GaaSGmConvStatusMask[LucSgUnitId]))
  {
    /* Buffer the status of ADCAnSGSTR register */
    LulADCAnSGSTR = LpAdcRegisters->ulSGSTR;
    /* Stop the conversion of all the SG unit */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulADHALTR, ADC_STOP_SG_CONVERSION);
    /* END Msg(4:3138)-22 */
    /* Clear the status bit of actually stopped SG */
    LulADCAnSGSTR = LulADCAnSGSTR &
                           (uint32)(~(Adc_GaaSGmConvStatusMask[LucSgUnitId]));
    /* restart the conversion of groups which are in suspended state */
    /* If SG1 was in suspended state */
    /* MISRA Violation: START Msg(4:3138)-22 */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ZERO]))
    {
      /* Trigger conversion of SG1 */
      /* MISRA Violation: START Msg(4:2985)-10 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(4:2985)-10 */
    }
    /* If SG2 was in suspended state */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ONE]))
    {
      /* Trigger conversion of SG2 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    }
    /* If SG3 was in suspended state */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_TWO]))
    {
      /* Trigger conversion of SG3 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    }
    /* END Msg(4:3138)-22 */
  }
  #else
  /* If the ongoing group is continuous group apply ADHALT */
  /* MISRA Violation: START Msg(4:0491)-5 */
  if ((ADC_GROUP_CONTINUOUS ==
  (Adc_GpGroupConfig[LpSgUnitData->ddCurrentConvGroup].ucGroupSettings
                                        & ADC_GROUP_CONV_MASK)))
  /* END Msg(4:0491)-5 */
  {
    /* Buffer the status of ADCAnSGSTR register */
    LulADCAnSGSTR = LpAdcRegisters->ulSGSTR;
    /* Stop the conversion of all the SG unit */
    /* MISRA Violation: START Msg(4:3138)-22 */
    ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulADHALTR, ADC_STOP_SG_CONVERSION);
    /* END Msg(4:3138)-22 */
    /* Clear the status bit of actually stopped SG */
    LulADCAnSGSTR = LulADCAnSGSTR &
                   (uint32)(~(Adc_GaaSGmConvStatusMask[LucSgUnitId]));
    /* restart the conversion of groups which are in suspended state */
    /* If SG1 was in suspended state */
    /* MISRA Violation: START Msg(4:3138)-22 */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ZERO]))
    {
      /* MISRA Violation: START Msg(4:2985)-10 */
      /* Trigger conversion of SG1 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(4:2985)-10 */
    }
    /* If SG2 was in suspended state */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_ONE]))
    {
      /* Trigger conversion of SG2 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    }
    /* If SG3 was in suspended state */
    if (ADC_NOT_BUSY != (LulADCAnSGSTR &
                              Adc_GaaSGmConvStatusMask[ADC_TWO]))
    {
      /* MISRA Violation: START Msg(4:2841)-7 */
      /* Trigger conversion of SG3 */
      LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(4:2841)-7 */
    }
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* Implements EAAR_PN0034_FR_0085 */
    /* Implements EAAR_PN0034_FR_0086 */
    LulTimeOut = ADC_LOOP_TIMEOUT;
    /* Wait until the conversion of the HW SG group is completed */
    do{
      LulTimeOut--;
    /* QAC Warning: START Msg(4:3415)-34 */
    /* QAC Warning: START Msg(2:3416)-23 */
    }while ((ADC_WORD_ZERO != (LpAdcRegisters->ulSGSTR &
                        Adc_GaaSGmConvStatusMask[LucSgUnitId]))
                        && (ADC_ZERO != (uint32)LulTimeOut));
    /* END Msg(2:3416)-23 */
    /* END Msg(4:3415)-34 */

    #if (ADC_DEM_ERROR_DETECT == STD_ON)
    /* Implements EAAR_PN0034_FR_0084 */
    /* In case of time out report DEM */
    if (ADC_ZERO == LulTimeOut)
    {
      /* Implements ADC068, ADC377, SWS_Adc_00377 */
      /* Report TIME OUT Error to DEM */
       Dem_ReportErrorStatus(ADC_E_LOOP_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    }
    #endif
  }
#endif
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif
/*******************************************************************************
** Function Name        : Adc_StopScanGroup
**
** Service ID           : NA
**
** Description          : Function to stop the conversion of each Individual
**                        scan group using ADCAnSGSTPCRx register.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Adc_GroupType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitIndex, Adc_GpHwUnitConfig
**
** Functions invoked    : Dem_ReportErrorStatus
**
** Registers Used       : ADCAnSGSTR, ADCAnSGSTPCRx
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_173 , ADC_ESDD_UD_200 */
#if (ADC_HARD_STOP == STD_ON)
FUNC(void, ADC_PRIVATE_CODE) Adc_StopScanGroup(Adc_GroupType LddGroup)
{
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint8 LucSgUnitId;
  uint8 LucHwUnit;
  uint8 LucSgUnitIndex;
  P2VAR(Adc_SgUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpSgUnitData;
  volatile uint32 LulTimeOut;
  uint8 LucSgRegIndex;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegisters;
  P2CONST(Adc_HwSgUnitType, ADC_VAR, ADC_CONFIG_CONST) LpSgUnitConfig;
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Read the Hardware Unit to which the group belongs */
  LucHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnitIndex;

  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;

  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];
  /* Get the SGm unit to which the channel group is mapped */
  LucSgUnitIndex = Adc_GpGroupConfig[LddGroup].ucSgUnitIndex;
  /* Get the SG unit Id to which this group is mapped */
  LucSgUnitId = Adc_GpSgUnitConfig[LucSgUnitIndex].ucSgUnitId;
  /* END Msg(4:0491)-5 */
  /* Get the SG unit index */
  /* Get the SG unit which is configured for this group */
  /* MISRA Violation: START Msg(4:0491)-5 */
  LpSgUnitConfig = &Adc_GpSgUnitConfig[LucSgUnitIndex];
  /* END Msg(4:0491)-5 */
  LucSgRegIndex = LpSgUnitConfig->ucSgRegIndex;
  LpAdcSGRegisters = Adc_GaaSGReg_BaseAddress[LucSgRegIndex];
  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize SG RAM data to a local pointer */
  LpSgUnitData = &Adc_GpSgUnitRamData[LucSgUnitIndex];

  /* Buffer the status of ADCAnSGSTR register */
  if ((ADC_GROUP_CONTINUOUS ==
  (Adc_GpGroupConfig[LpSgUnitData->ddCurrentConvGroup].ucGroupSettings
                                        & ADC_GROUP_CONV_MASK)))
  /* END Msg(4:0491)-5 */
  {
    /* MISRA Violation: START Msg(4:3138)-22 */
    /*Stop the intended scan group*/
    ADC_WRITE_REG_ONLY(&LpAdcSGRegisters->ulSGSTPCR,
                             ADC_STOP_SG_CONVERSION);
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /*Wait for one shot conversion groups to complete*/
    /* Implements EAAR_PN0034_FR_0085 */
    /* Implements EAAR_PN0034_FR_0086 */
    LulTimeOut = ADC_LOOP_TIMEOUT;
    /* Wait until the conversion of the HW SG group is completed */
    do{
      LulTimeOut--;
    /* QAC Warning: START Msg(4:3415)-34 */
    /* QAC Warning: START Msg(2:3416)-23 */
    }while ((ADC_WORD_ZERO != (LpAdcRegisters->ulSGSTR &
                        Adc_GaaSGmConvStatusMask[LucSgUnitId]))
                        && (ADC_ZERO != (uint32)LulTimeOut));
    /* END Msg(2:3416)-23 */
    /* END Msg(4:3415)-34 */

    #if (ADC_DEM_ERROR_DETECT == STD_ON)
    /* Implements EAAR_PN0034_FR_0084 */
    /* In case of time out report DEM */
    if (ADC_ZERO == LulTimeOut)
    {
      /* Implements ADC068, ADC377, SWS_Adc_00377 */
      /* Report TIME OUT Error to DEM */
       Dem_ReportErrorStatus(ADC_E_LOOP_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    }
    #endif
  }
}
#endif
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include ADC_MEMMAP_FILE
/*******************************************************************************
** Function Name        : Adc_HwCusSetSamplingClock
**
** Service ID           : NA
**
** Description          : This is a Vendor specific API to configure during run
**                        time ADCAnSMPCR register of the corresponding HW unit
**                        with 18 cycle or 24 cycle settings.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
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
** Global Variables     : Adc_GpHwUnitConfig
**
** Functions invoked    : Adc_HaltADConversion
**
** Registers Used       : ADCAnSMPCR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_178 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HwCusSetSamplingClock(Adc_HardwareIndexType
                                   HwIndex, Adc_SamplingClockType SamplingClock)
{
  P2CONST(Adc_HwUnitConfigType, ADC_VAR, ADC_CONFIG_CONST) LpHwUnitConfig;
  /* Pointer to the hardware unit Os base configuration address */
  uint8 LucHwUnitIndex;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;
  uint32 LulRegWriteValue;

  uint32 LulRegSGCR[ADC_THREE];
  uint32 LulRegSGSTR;
  uint8 LucSGOffset;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;


  /* MISRA Violation: START Msg(4:0491)-5 */
  /* Initialize the local variable for HW unit configuration */
  LpHwUnitConfig = &Adc_GpHwUnitConfig[HwIndex];
  /* END Msg(4:0491)-5 */
  /* Read the hardware unit index */
  LucHwUnitIndex = LpHwUnitConfig->ucHwUnit;
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

  /* Buffer the status of SGSTR */
  LulRegSGSTR = LpAdcRegisters->ulSGSTR;

  /* Read the SG offset */
  LucSGOffset = LpHwUnitConfig->ucSGOffset;
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LulRegSGCR[ADC_SG1] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegSGCR[ADC_SG2] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegSGCR[ADC_SG3] = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */

  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SCACT of all scan grops to 0 by writing the register ADCAnADHALTR */
  Adc_HaltADConversion(LucHwUnitIndex);

  /* If the requested sampling time is 18 cycle */
  if (ADC_SCLK_18 == SamplingClock)
  {
    /* Set ADCAnSMPCR Register for sampling time of 18 cycle */
    LulRegWriteValue = ADC_EIGHTEEN_CYCLES;
  }
  /* If the requested sampling time is 24 cycle */
  else
  {
    /* Set ADCAnSMPCR Register for sampling time of 24 cycle */
    LulRegWriteValue = ADC_TWENTYFOUR_CYCLES;
  }
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(&LpAdcRegisters->ulSMPCR, LulRegWriteValue,
                &Adc_GaaRamMirrorAdcConfReg[LucHwUnitIndex].ulSMPCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(&LpAdcRegisters->ulSMPCR,
                LulRegWriteValue, ADC_WV_MASK_SMPCR,
                ADC_HWCUSSETSAMPLINGCLOCK_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously configured TRGMD bits */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     | (LulRegSGCR[ADC_SG1] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     | (LulRegSGCR[ADC_SG2] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);
  /* MISRA Violation: START Msg(2:3892)-28 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = (Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     | (LulRegSGCR[ADC_SG3] & (~ADC_CLEAR_TRGMD)));
  /* END Msg(2:3892)-28 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            ADC_HWCUSSETSAMPLINGCLOCK_API_ID);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Writing back the previously Trigger conversion */
  /* If SG1 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ZERO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG1 */
    /* MISRA Violation: START Msg(4:2985)-10 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGSTCR;
    /* END Msg(4:2985)-10 */
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG2 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_ONE]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG2 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
  /* If SG3 was in suspended state */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:2992)-31 */
  if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[ADC_TWO]))
  /* END Msg(4:2992)-31 */
  /* END Msg(2:3892)-28 */
  {
    /* Trigger conversion of SG3 */
    LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGSTCR;
    /* MISRA Violation: START Msg(4:3138)-22 */
    /* MISRA Violation: START Msg(2:3109)-24 */
    ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
    /* END Msg(2:3109)-24 */
    /* END Msg(4:3138)-22 */
  }
  else
  {
    /* No Action */
  }
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_IntCusGetPWSAnPVCRx_y
**
** Service ID           : NA
**
** Description          : This function will provide the PWSAnPVCRx register
**                        value.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
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
** Global Variables     : None
**
** Functions invoked    : None
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
/* Implements ADC_ESDD_UD_182 */
/* Implements AR_PN0076_FR_0315 */
/* Implements AR_PN0076_FR_0316 */
FUNC(Adc_PWSARegisterType, ADC_PRIVATE_CODE)Adc_IntCusGetPWSAnPVCRx_y
(uint8 PwmDiagChannelID)
{
  /*Local variable to hold the return value*/
  Adc_PWSARegisterType LulReturnValue;

  /*If the diag channel Id is odd*/
  if (ADC_ONE == (PwmDiagChannelID & ADC_ONE))
  {
    /* MISRA Violation: START Msg(4:0303)-4 */
    /* MISRA Violation: START Msg(4:0488)-1 */
    /*Read the value from the  even numbered register*/
    LulReturnValue =
     Adc_GaaPWSAReg_BaseAddress->ulPVCR[((PwmDiagChannelID - ADC_ONE)
                                                               >> ADC_ONE)];
    /* END Msg(4:0303)-4 */
    /* END Msg(4:0488)-1 */
  }
  else
  {
      /*If the channel Id is even*/
     /*Read the value from the register*/
    /* MISRA Violation: START Msg(4:0303)-4 */
    /* MISRA Violation: START Msg(4:0488)-1 */
    LulReturnValue =
            Adc_GaaPWSAReg_BaseAddress->ulPVCR[((PwmDiagChannelID) >> ADC_ONE)];
    /* END Msg(4:0303)-4 */
    /* END Msg(4:0488)-1 */
  }
  /*Return register value as 32 bit*/
  return(LulReturnValue);
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
#endif

/*******************************************************************************
** Function Name        : Adc_InitRamMirror
**
** Service ID           : NA
**
** Description          : This function will initialize the Ram Mirrors for
**                        Hardware Consistency Check with register values after
**                        MCU reset.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : None
**
** Functions invoked    : None
**
** Registers Used       : ADCAnADCR, ADCAnTHCR, ADCAnTHACR,  ADCAnTHBCR,
**                        ADCAnTHER, ADCAnTHGSR, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnPDCTL1, ADCAnPDCTL2, ADCAnSMPCR, ADCAnULLMTBRx,
**                        ADCAnVCRj, ADCAnSGCRx, ADCAnSGVCSPx, ADCAnSGVCEPx,
**                        ADCAnSGTSELx, PWGAnCTDR, PWSAnPVCRx_y, DTCTm, DRSAm,
**                        DRDAm, DRTCm, DTCm
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
/* Implements ADC_ESDD_UD_199 */
/* Implements ADC_ESDD_UD_175 */
FUNC(void, ADC_PRIVATE_CODE) Adc_InitRamMirror(void)
{
  uint8_least LucLoop;

  #if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
  uint8_least LucLoopAux;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcConfReg;
  P2VAR(volatile AdcConfRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcConfRegRam;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcVirChReg;
  P2VAR(volatile AdcVirChRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcVirChRegRam;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGReg;
  P2VAR(volatile AdcSGRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegRam;
  #endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaReg;
  P2VAR(volatile DmaRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegRam;
  #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
  #endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
  /* RAM Mirror initialization for AdcConfReg */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_CONFREG_INSTANCES; LucLoop++)
  /* END Msg(4:2877)-11 */
  {
    LpAdcConfReg = Adc_GaaConfReg_BaseAddress[LucLoop];
    LpAdcConfRegRam = &Adc_GaaRamMirrorAdcConfReg[LucLoop];
    LpAdcConfRegRam->ulADCR = LpAdcConfReg->ulADCR;
    LpAdcConfRegRam->ulTHCR = LpAdcConfReg->ulTHCR;
    LpAdcConfRegRam->ulTHACR = LpAdcConfReg->ulTHACR;
    LpAdcConfRegRam->ulTHBCR = LpAdcConfReg->ulTHBCR;
    LpAdcConfRegRam->ulTHER = LpAdcConfReg->ulTHER;
    LpAdcConfRegRam->ulTHGSR = LpAdcConfReg->ulTHGSR;
    LpAdcConfRegRam->ulDGCTL0 = LpAdcConfReg->ulDGCTL0;
    LpAdcConfRegRam->ulDGCTL1 = LpAdcConfReg->ulDGCTL1;
    LpAdcConfRegRam->ulPDCTL1 = LpAdcConfReg->ulPDCTL1;
    LpAdcConfRegRam->ulPDCTL2 = LpAdcConfReg->ulPDCTL2;
    LpAdcConfRegRam->ulSMPCR = LpAdcConfReg->ulSMPCR;
    for (LucLoopAux = ADC_ZERO; LucLoopAux < ADC_REG_ULLMTBR_ARRAY_SIZE;
                                LucLoopAux++)
    {
      /*If ENHANCED LIMIT CHECK feathure is enabled.*/
      #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
      if (LucLoopAux > ADC_TWO)
      {
        LpAdcConfRegRam->ulULLMTBR[LucLoopAux] =
                     LpAdcConfReg->ulULLMTBR2[LucLoopAux - ADC_ULLMTBR2_OFSET];
      }
      else
      {
        LpAdcConfRegRam->ulULLMTBR[LucLoopAux] =
                                           LpAdcConfReg->ulULLMTBR[LucLoopAux];
      }
      #else
      LpAdcConfRegRam->ulULLMTBR[LucLoopAux] =
                                           LpAdcConfReg->ulULLMTBR[LucLoopAux];
      #endif
    }
  }
  /* RAM Mirror initialization for AdcVirChReg */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_VIRCHREG_INSTANCES; LucLoop++)
  /* END Msg(4:2877)-11 */
  {
    LpAdcVirChReg = Adc_GaaVirChReg_BaseAddress[LucLoop];
    LpAdcVirChRegRam = &Adc_GaaRamMirrorAdcVirChReg[LucLoop];
    for (LucLoopAux = ADC_ZERO; LucLoopAux < ADC_REG_VCR_ARRAY_SIZE;
                                LucLoopAux++)
    {
      LpAdcVirChRegRam->ulVCR[LucLoopAux] = LpAdcVirChReg->ulVCR[LucLoopAux];
    }
  }
  /* RAM Mirror initialization for AdcSGReg */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_SGREG_INSTANCES; LucLoop++)
  /* END Msg(4:2877)-11 */
  {
    LpAdcSGReg = Adc_GaaSGReg_BaseAddress[LucLoop];
    LpAdcSGRegRam = &Adc_GaaRamMirrorAdcSGReg[LucLoop];
    LpAdcSGRegRam->ulSGCR = LpAdcSGReg->ulSGCR;
    LpAdcSGRegRam->ulSGVCSP = LpAdcSGReg->ulSGVCSP;
    LpAdcSGRegRam->ulSGVCEP = LpAdcSGReg->ulSGVCEP;
    LpAdcSGRegRam->ulSGTSEL = LpAdcSGReg->ulSGTSEL;
  }
  #endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* RAM Mirror initialization for PWGAReg */
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_PWGAREG_INSTANCES; LucLoop++)
  /* END Msg(4:2877)-11 */
  {
    Adc_GaaRamMirrorPWGAReg[LucLoop].usCTDR =
          Adc_GaaPWGAReg_BaseAddress[LucLoop]->usCTDR;
  }
  /* Hardware Consistency Check for PWSAReg */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_REG_PVCR_ARRAY_SIZE; LucLoop++)
  {
    Adc_GaaRamMirrorPWSAReg.ulPVCR[LucLoop] =
          Adc_GaaPWSAReg_BaseAddress->ulPVCR[LucLoop];
  }
  #endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
  #endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-11 */
  for (LucLoop = ADC_ZERO; LucLoop < ADC_DMAREG_INSTANCES; LucLoop++)
  /* END Msg(4:2877)-11 */
  {
    LpDmaReg = Adc_GaaDmaReg_BaseAddress[LucLoop];
    LpDmaRegRam = &Adc_GaaRamMirrorDmaReg[LucLoop];
    LpDmaRegRam->ulDTCT = LpDmaReg->ulDTCT;
    LpDmaRegRam->ulDRSA = LpDmaReg->ulDRSA;
    LpDmaRegRam->ulDRDA = LpDmaReg->ulDRDA;
    LpDmaRegRam->ulDRTC = LpDmaReg->ulDRTC;
  }
  #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
  #endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */
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
** Function Name        : Adc_HwCheckHWConsistency
**
** Service ID           : NA
**
** Description          : This private function returns the status of hardware
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
** Return parameter     : CheckStatus
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GaaRamMirrorAdcSGReg,
**                        Adc_GpPwmGroupData, Adc_GucMaxDmaChannels,
**                        Adc_GpDmaUnitConfig, Adc_GaaRamMirrorAdcConfReg,
**                        Adc_GaaRamMirrorAdcVirChReg, Adc_GaaRamMirrorPWGAReg
**
** Functions invoked    : None
**
** Registers Used       : ADCAnVCRj, ADCAnADCR, ADCAnTHCR, ADCAnTHACR,
**                        ADCAnTHBCR, ADCAnTHER, ADCAnTHGSR, ADCAnSMPCR,
**                        ADCAnULLMTBRx,  ADCAnSGCRx, ADCAnSGVCSPx,
**                        ADCAnSGVCEPx, ADCAnSGTSELx, ADCAnDGCTL0, ADCAnDGCTL1,
**                        ADCAnPDCTL1, ADCAnPDCTL2, DTCTm, DRSAm, DRDAm, DRTCm,
**                        DTFRm, PWGAnCTDR, PWSAnPVCRx_y, ADCAnSFTCR,
**                        ADCAnSGMCYCRx, PWSAnCTL, ADCAnPWDSGCR, DTCm
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
/* Implements EAAR_PN0034_FSR_0007, ADC_ESDD_UD_213 */
/* Implements ADC_ESDD_UD_175 */
FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_HwCheckHWConsistency
                   (Adc_HWConsistencyCheckType LddCheckType)
{
  Std_ReturnType LucCheckStatus = E_OK;
  uint8_least LucLoop;

  #if ( (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
        (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) )
  uint32 LulCompareValue;
  #endif /* ((ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) || \
        (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)) */

  #if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
  uint8_least LucLoopAux;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcConfReg;
  P2VAR(volatile AdcConfRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcConfRegRam;
  P2VAR(volatile AdcVirChReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcVirChReg;
  P2VAR(volatile AdcVirChRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcVirChRegRam;
  P2VAR(volatile AdcSGReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGReg;
  P2VAR(volatile AdcSGRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcSGRegRam;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;
  #if (ADC_ENABLE_STREAMING == STD_ON)
  uint8 LucSGOffset;
  #endif
  #endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  P2VAR(volatile PWGAReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcPWGAReg;
  P2VAR(volatile PWGARegRam, AUTOMATIC, ADC_CONFIG_DATA) LpAdcPWGARegRam;
  #endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
  #endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  #if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpSGmDmaConfig;
  uint8 LucDmaRegIndex;
  P2VAR(volatile DmaReg, AUTOMATIC, ADC_CONFIG_DATA) LpDmaReg;
  P2VAR(volatile DmaRegRam, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegRam;
  #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
  #endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */

  if (ADC_HW_CONSISTENCY_STATIC == LddCheckType)
  {
    #if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
    /* Hardware Consistency Check for AdcConfReg */
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_CONFREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpAdcConfReg = Adc_GaaConfReg_BaseAddress[LucLoop];
      /* Check Static register SFTCR */
      LulCompareValue = ADC_DOUBLE_WORD_ZERO;
      #if (ADC_ERROR_SUPPORT == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-5 */
      if (ADC_TRUE == Adc_GpHwUnitConfig[LucLoop].blInterruptErr)
      {
        LulCompareValue = Adc_GpHwUnitConfig[LucLoop].ulErrorEnableValue;
      }
      /* END Msg(4:0491)-5 */
      else
      {
        /* To avoid misra violation */
      }
      #endif /* (ADC_ERROR_SUPPORT == STD_ON) */
      if (LpAdcConfReg->ulSFTCR != LulCompareValue)
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
      /* Check Static register PWDSGCR */
      #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
      if (ADC_ENABLE_PWM_DIAG_TRIGG != LpAdcConfReg->ulPWDSGCR)
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
      #endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
    }
    /* Hardware Consistency Check for AdcSGReg */
    #if (ADC_ENABLE_STREAMING == STD_ON)
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_MAX_HW_UNITS); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      /* Check Static register SGMCYCR */
      /* MISRA Violation: START Msg(4:0491)-5 */
      LucSGOffset = Adc_GpHwUnitConfig[LucLoop].ucSGOffset;
      /* END Msg(4:0491)-5 */
      /* MISRA Violation: START Msg(4:2985)-10 */
      if ((ADC_SINGLE_CYCLE_SCAN !=
              Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGMCYCR) ||
          (ADC_SINGLE_CYCLE_SCAN !=
              Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGMCYCR) ||
          (ADC_SINGLE_CYCLE_SCAN !=
              Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGMCYCR))
      /* END Msg(4:2985)-10 */
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }
    #endif /* (ADC_ENABLE_STREAMING == STD_ON) */
    #endif /* (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE) */

    #if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    if (ADC_PWM_START_PWSA != Adc_GaaPWSAReg_BaseAddress->ucCTL)
    {
      LucCheckStatus = E_NOT_OK;
    }
    else
    {
      /* To avoid misra violation */
    }
    #endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
    #endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

    #if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
    #if (ADC_DMA_MODE_ENABLE == STD_ON)
    /* Check Static register DTFR */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                   (LucLoop < (uint8_least)Adc_GucMaxDmaChannels); LucLoop++)
    {
      /* MISRA Violation: START Msg(4:0491)-5 */
      LpSGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoop];
      /* END Msg(4:0491)-5 */
      LucDmaRegIndex = LpSGmDmaConfig->ucDmaRegIndex;
      LpDmaReg = Adc_GaaDmaReg_BaseAddress[LucDmaRegIndex];
      LulCompareValue = ((uint32)( LpSGmDmaConfig->usDmaDtfrRegValue) <<
                        ADC_ONE) | ADC_ONE;
      if (LpDmaReg->ulDTFR != LulCompareValue)
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }
    #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
    #endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */
  }
  else if (ADC_HW_CONSISTENCY_DYNAMIC == LddCheckType)
  {
    #if (ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE)
    /* Hardware Consistency Check for AdcConfReg */
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_CONFREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpAdcConfReg = Adc_GaaConfReg_BaseAddress[LucLoop];
      LpAdcConfRegRam = &Adc_GaaRamMirrorAdcConfReg[LucLoop];
      if ((LpAdcConfReg->ulADCR != LpAdcConfRegRam->ulADCR) ||
          (LpAdcConfReg->ulTHCR != LpAdcConfRegRam->ulTHCR) ||
          (LpAdcConfReg->ulTHACR != LpAdcConfRegRam->ulTHACR) ||
          (LpAdcConfReg->ulTHBCR != LpAdcConfRegRam->ulTHBCR) ||
          (LpAdcConfReg->ulTHER != LpAdcConfRegRam->ulTHER) ||
          (LpAdcConfReg->ulTHGSR != LpAdcConfRegRam->ulTHGSR) ||
          (LpAdcConfReg->ulDGCTL0 != LpAdcConfRegRam->ulDGCTL0) ||
          (LpAdcConfReg->ulDGCTL1 != LpAdcConfRegRam->ulDGCTL1) ||
          (LpAdcConfReg->ulPDCTL1 != LpAdcConfRegRam->ulPDCTL1) ||
          (LpAdcConfReg->ulPDCTL2 != LpAdcConfRegRam->ulPDCTL2) ||
          (LpAdcConfReg->ulSMPCR != LpAdcConfRegRam->ulSMPCR))
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
      for (LucLoopAux = ADC_ZERO; (LucCheckStatus == E_OK) &&
                       (LucLoopAux < ADC_REG_ULLMTBR_ARRAY_SIZE); LucLoopAux++)
      {
        /*If ENHANCED LIMIT CHECK feathure is enabled.*/
        #if (ADC_ENHANCED_LIMIT_CHECK == STD_ON)
        if (LucLoopAux > ADC_TWO)
        {
         LpRegWrite = &LpAdcConfReg->ulULLMTBR2
                                        [LucLoopAux - ADC_ULLMTBR2_OFSET];
        }
        else
        {
          LpRegWrite = &LpAdcConfReg->ulULLMTBR[LucLoopAux];
        }
        #else
        LpRegWrite = &LpAdcConfReg->ulULLMTBR[LucLoopAux];
        #endif
        if ((*(LpRegWrite)) != LpAdcConfRegRam->ulULLMTBR[LucLoopAux])
        {
          LucCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid misra violation */
        }
      }
    }
    /* Hardware Consistency Check for AdcVirChReg */
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_VIRCHREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpAdcVirChReg = Adc_GaaVirChReg_BaseAddress[LucLoop];
      LpAdcVirChRegRam = &Adc_GaaRamMirrorAdcVirChReg[LucLoop];
      for (LucLoopAux = ADC_ZERO; (LucCheckStatus == E_OK) &&
                           (LucLoopAux < ADC_REG_VCR_ARRAY_SIZE); LucLoopAux++)
      {
        if ((LpAdcVirChReg->ulVCR[LucLoopAux] & ADC_WV_MASK_VCR) !=
              (LpAdcVirChRegRam->ulVCR[LucLoopAux] & ADC_WV_MASK_VCR))
        {
          LucCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid misra violation */
        }
      }
    }

    /* Hardware Consistency Check for AdcSGReg */
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_SGREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpAdcSGReg = Adc_GaaSGReg_BaseAddress[LucLoop];
      LpAdcSGRegRam = &Adc_GaaRamMirrorAdcSGReg[LucLoop];
      if ((LpAdcSGReg->ulSGCR != LpAdcSGRegRam->ulSGCR) ||
          (LpAdcSGReg->ulSGVCSP != LpAdcSGRegRam->ulSGVCSP) ||
          (LpAdcSGReg->ulSGVCEP != LpAdcSGRegRam->ulSGVCEP) ||
          (LpAdcSGReg->ulSGTSEL != LpAdcSGRegRam->ulSGTSEL))
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }
    #endif /* ADC_ADCA_RAM_MIRROR == ADC_MIRROR_ENABLE */

    #if (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE)
    #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
    /* Hardware Consistency Check for PWGAReg */
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_PWGAREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpAdcPWGAReg = Adc_GaaPWGAReg_BaseAddress[LucLoop];
      LpAdcPWGARegRam = &Adc_GaaRamMirrorPWGAReg[LucLoop];
      if ((LpAdcPWGAReg->usCTDR != LpAdcPWGARegRam->usCTDR))
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }

    /* Hardware Consistency Check for PWSAReg */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_REG_PVCR_ARRAY_SIZE); LucLoop++)
    {
      if (Adc_GaaPWSAReg_BaseAddress->ulPVCR[LucLoop] !=
              Adc_GaaRamMirrorPWSAReg.ulPVCR[LucLoop])
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }
    #endif /* (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) */
    #endif /* (ADC_PWMDIAG_RAM_MIRROR == ADC_MIRROR_ENABLE) */

    #if (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE)
    #if (ADC_DMA_MODE_ENABLE == STD_ON)
    /* MISRA Violation: START Msg(4:2877)-11 */
    for (LucLoop = ADC_ZERO; (LucCheckStatus == E_OK) &&
                             (LucLoop < ADC_DMAREG_INSTANCES); LucLoop++)
    /* END Msg(4:2877)-11 */
    {
      LpDmaReg = Adc_GaaDmaReg_BaseAddress[LucLoop];
      LpDmaRegRam = &Adc_GaaRamMirrorDmaReg[LucLoop];
      if ((LpDmaReg->ulDTCT != LpDmaRegRam->ulDTCT) ||
          (LpDmaReg->ulDRSA != LpDmaRegRam->ulDRSA) ||
          (LpDmaReg->ulDRDA != LpDmaRegRam->ulDRDA) ||
          (LpDmaReg->ulDRTC != LpDmaRegRam->ulDRTC))
      {
        LucCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid misra violation */
      }
    }
    #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
    #endif /* (ADC_DMAC_RAM_MIRROR == ADC_MIRROR_ENABLE) */
  }
  else
  {
    /* To avoid misra violation */
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
** Function Name        : Adc_HaltADConversion
**
** Service ID           : NA
**
** Description          : This internal function shall force conversion halt of
**                        the request AD.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GaaConfReg_BaseAddress
**
** Functions invoked    : Dem_ReportErrorStatus
**
** Registers Used       : ADCAnADHALTR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_201 */
FUNC(void, ADC_PRIVATE_CODE) Adc_HaltADConversion(const uint8 LucHwUnitIndex)
{
  volatile uint32 LulTimeOut;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;

  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

  /* Set SGACT of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:3109)-24 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  ADC_WRITE_REG_ONLY(&LpAdcRegisters->ulADHALTR, ADC_STOP_HW_CONVERSION);
  /* END Msg(2:2814)-27 */
  /* END Msg(2:3109)-24 */
  /* END Msg(4:3138)-22 */

  LulTimeOut = ADC_LOOP_TIMEOUT;
  /* QAC Warning: START Msg(2:3416)-23 */
  /* QAC Warning: START Msg(4:3415)-34 */
  while((ADC_DOUBLE_WORD_ZERO != (LpAdcRegisters->ulSGSTR &
                         ADC_SGACT_VALUE))
                         && (ADC_DOUBLE_WORD_ZERO != (uint32)LulTimeOut))
  /* END Msg(4:3415)-34 */
  /* END Msg(2:3416)-23 */
  {
    LulTimeOut--;
  }
  #if (ADC_DEM_ERROR_DETECT == STD_ON)
  /* In case of time out report DEM */
  if (ADC_DOUBLE_WORD_ZERO == LulTimeOut)
  {
    /* Report TIME OUT Error to DEM */
    Dem_ReportErrorStatus(ADC_E_LOOP_TIMEOUT, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* Do Nothing */
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
** Function Name        : Adc_SaveRegAndHaltADConversion
**
** Service ID           : NA
**
** Description          : Buffer the status of SGSTR and halt AD conversion 
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit, LucApiId
**
** InOut Parameters     : None
**
** Output Parameters    : LpulRegSGCR, LpulRegSGSTR
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GaaConfReg_BaseAddress
**                        Adc_GaaRamMirrorAdcSGReg
**
** Functions invoked    : Dem_ReportErrorStatus, Adc_HaltADConversion
**
** Registers Used       : ADCAnADHALTR, ADCAnSGSTR, ADCAnSGCR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_202 */
FUNC(void, ADC_PRIVATE_CODE) Adc_SaveRegAndHaltADConversion(
       const uint8 LucHwUnit,
       P2VAR(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGCR,
       P2VAR(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGSTR,
       const uint8 LucApiId)
{
  uint8 LucSGOffset;
  uint32 LulRegWriteValue;
  uint8 LucHwUnitIndex;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;
  P2VAR(volatile AdcConfReg, AUTOMATIC, ADC_CONFIG_DATA) LpAdcRegisters;

  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  LucHwUnitIndex = Adc_GpHwUnitConfig[LucHwUnit].ucHwUnit;
  /* END Msg(4:0491)-5 */
  LpAdcRegisters = Adc_GaaConfReg_BaseAddress[LucHwUnitIndex];

  *LpulRegSGSTR = LpAdcRegisters->ulSGSTR;
  /* Buffer the status of SGCR */
  /* MISRA Violation: START Msg(4:2985)-10 */
  /* MISRA Violation: START Msg(2:3892)-28 */
  /* MISRA Violation: START Msg(4:0492)-32 */
  LpulRegSGCR[ADC_SG1] =
                  Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LpulRegSGCR[ADC_SG2] =
                  Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LpulRegSGCR[ADC_SG3] =
                  Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  /* END Msg(4:0492)-32 */
  /* END Msg(2:3892)-28 */
  /* END Msg(4:2985)-10 */
  /* Set TRGMD of all scan groups to 0 */
  /* MISRA Violation: START Msg(4:2985)-10 */
  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG1]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  /* MISRA Violation: START Msg(4:3138)-22 */
  /* MISRA Violation: START Msg(2:2814)-27 */
  /* MISRA Violation: START Msg(2:3139)-25 */
  /* MISRA Violation: START Msg(2:3141)-26 */
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG1].ulSGCR);
  /* END Msg(2:2814)-27 */
  /* END Msg(4:2985)-10 */
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            LucApiId);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG2]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG2].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            LucApiId);

  LpRegWrite = &Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR;
  LulRegWriteValue = Adc_GaaSGReg_BaseAddress[LucSGOffset + ADC_SG3]->ulSGCR
                     & ADC_CLEAR_TRGMD;
  ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
            LulRegWriteValue,
            &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + ADC_SG3].ulSGCR);
  ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
            LulRegWriteValue, ADC_WV_MASK_SGCR,
            LucApiId);
  /* END Msg(4:3138)-22 */
  /* END Msg(2:3139)-25 */
  /* END Msg(2:3141)-26 */
  /* Set SGACT of all scan groups to 0 */
  Adc_HaltADConversion(LucHwUnitIndex);
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
** Function Name        : Adc_WriteBackRegforADConversion
**
** Service ID           : NA
**
** Description          : Writing back the previously Trigger conversion 
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucHwUnit, LucApiId, LpulRegSGCR, LpulRegSGSTR
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Adc_GpHwUnitConfig, Adc_GaaConfReg_BaseAddress
**                        Adc_GaaRamMirrorAdcSGReg
**
** Functions invoked    : Dem_ReportErrorStatus
**
** Registers Used       : ADCAnSGSTCR, ADCAnSGCR
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CODE_ASIL_B
#else
  #define ADC_START_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/* Implements ADC_ESDD_UD_203 */
FUNC(void, ADC_PRIVATE_CODE) Adc_WriteBackRegforADConversion(
       const uint8 LucHwUnit,
       P2CONST(uint32, AUTOMATIC, ADC_PRIVATE_DATA) LpulRegSGCR,
       const uint32 LulRegSGSTR,
       const uint8 LucApiId)
{
  uint32 LulRegWriteValue;
  uint8 LucSGOffset;
  uint8 LucLoopCount;
  P2VAR(volatile uint32, AUTOMATIC, ADC_CONFIG_DATA) LpRegWrite;

  /* MISRA Violation: START Msg(4:0491)-5 */
  LucSGOffset = Adc_GpHwUnitConfig[LucHwUnit].ucSGOffset;
  /* END Msg(4:0491)-5 */
  /*
   * ADCAnSGCRx should be set when SGACT of all scan groups is 0 (before the
   * scan group is started) and TRGMD of all scan groups is 0.
   * So, The ADCAnSGSTCRx are set after ADCAnSGCRx are set.
   */
  /* Writing back the previously configured TRGMD bits */
  for( LucLoopCount = ADC_SG1; LucLoopCount <= ADC_SG3; LucLoopCount++)
  {
    /* MISRA Violation: START Msg(4:0492)-32 */
    if(ADC_DOUBLE_WORD_ZERO != LpulRegSGCR[LucLoopCount])
    /* END Msg(4:0492)-32 */
    {
      /* MISRA Violation: START Msg(4:2985)-10 */
      /* MISRA Violation: START Msg(2:3892)-28 */
      LpRegWrite =
                &Adc_GaaSGReg_BaseAddress[LucSGOffset + LucLoopCount]->ulSGCR;
      /* MISRA Violation: START Msg(4:0492)-32 */
      LulRegWriteValue =
                (Adc_GaaSGReg_BaseAddress[LucSGOffset + LucLoopCount]->ulSGCR
                 | (LpulRegSGCR[LucLoopCount] & (~ADC_CLEAR_TRGMD)));
      /* END Msg(4:0492)-32 */
      /* END Msg(2:3892)-28 */
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3139)-25 */
      /* MISRA Violation: START Msg(2:3141)-26 */
      ADC_ADCA_WRITE_REG_AND_MIRROR(LpRegWrite,
              LulRegWriteValue,
              &Adc_GaaRamMirrorAdcSGReg[LucSGOffset + LucLoopCount].ulSGCR);
      /* END Msg(4:2985)-10 */
      ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(LpRegWrite,
              LulRegWriteValue, ADC_WV_MASK_SGCR,
              LucApiId);
      /* END Msg(4:3138)-22 */
      /* END Msg(2:3139)-25 */
      /* END Msg(2:3141)-26 */
    }
    else
    {
      /* No Action */
    }
  }
  /* Writing back the previously Trigger conversion */
  for( LucLoopCount = ADC_SG1; LucLoopCount <= ADC_SG3; LucLoopCount++)
  {
    /* If SGx was in suspended state */
    /* MISRA Violation: START Msg(2:3892)-28 */
    /* MISRA Violation: START Msg(4:2992)-31 */
    if (ADC_NOT_BUSY != (LulRegSGSTR &
                            Adc_GaaSGmConvStatusMask[LucLoopCount]))
    /* END Msg(4:2992)-31 */
    /* END Msg(2:3892)-28 */
    {
      /* Trigger conversion of SG2 */
      LpRegWrite =
              &Adc_GaaSGReg_BaseAddress[LucSGOffset + LucLoopCount]->ulSGSTCR;
      /* MISRA Violation: START Msg(4:3138)-22 */
      /* MISRA Violation: START Msg(2:3109)-24 */
      ADC_WRITE_REG_ONLY(LpRegWrite, ADC_START_CONVERSION);
      /* END Msg(2:3109)-24 */
      /* END Msg(4:3138)-22 */
    }
    else
    {
      /* No Action */
    }
  }
}
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CODE
#endif
#include ADC_MEMMAP_FILE
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
