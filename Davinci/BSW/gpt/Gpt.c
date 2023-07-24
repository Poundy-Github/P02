/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of GPT Driver              */
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
 *                           1. Gpt_GetVersionInfo is implemented as function.
 *
 * V2.0.0:  27-Sep-2016    : Several changes for solving tickets
 *                           1.ARDAABC-353 Protected section was added in
 *                           Gpt_StopTimer() function to avoid unwanted state
 *                           transitions for timers before the reading of the
 *                           timer status occurs. ARDAABC-751 Eliminated runtime
 *                           conversion (bitshift) of the wakeup source in the
 *                           embedded code.
 *                           2.ARDAABC-518 Updated GPT state transition handling
 *                           for interrupts in Gpt_SetMode. Modified
 *                           Gpt_EnableNotification and Gpt_DisableNotification
 *                           functions to enable/disable interrupts in case GPT
 *                           is in Normal Mode. Modified Gpt_DisableWakeup and
 *                           functions to enable/disable interrupts in case GPT
 *                           is in Sleep Mode.
 *                           3.ARDAABC-769 Added a public wrapper:
 *                           Gpt_HWCheckConsistency as part of the Hardware
 *                           Consistency Check safety mechanism implementation.
 *
 * V2.1.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.2.0:  15-Oct-2016    : Implement Predef Timer functionality as part of
 *                           ARDAABC-564
 *                           1.Start HW channel of Predef timer during Gpt_Init
 *                           orGpt_SetMode(NORMAL)
 *                           2.Stop HW channel of Predef timer during Gpt_Init
 *                           or Gpt_SetMode(NORMAL)
 *                           3.Add one new API: Gpt_GetPredefTimerValue to read
 *                           the value of a Predef timer
 *
 * V2.2.1:  16-Oct-2016    : Implement setting of DET errors in
 *                           Gpt_GetPredefTimerValue API as part of ARDAABC-570
 *
 * V2.2.2:  06-Dec-2016    : Added compile switch GPT_PREDEF_TIMER_ENABLED to
 *                           exclude from compilation Predef Timer related code
 *                           when function is disabled.
 *
 * V2.2.3:  08-Feb-2017    : Added comments for MISRA warnings
 *
 * V2.2.4:  26-Jun-2017    : MISRA Justification tags added.
 *
 * V2.2.5:  25-Jul-2017    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-1516,
 *                              Gpt_HW_DisableInterrupt is updated with new
 *                              argument.
 *                           2. MISRA Justification tags corrected in Reference.
 *
 * V2.2.6:  18-Sep-2017    : Following Changes were made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. As part of Jira #ARDAABD-2471,
 *                              naming convention for variables and macros
 *                              updated.
 *                           3. As per ARDAABD-2570, typo errors corrected.
 * V2.2.7:  22-May-2018    : As part of ARDAABD-3707,following changes are made:
 *                           1. Add RH850_DUMMY_READ_SYNCP(16, ICP0) to fix the
 *                              fault synchronization at the timing when control
 *                              shifts from MCAL to application
 * V2.2.8:  02-July-2018    : Following changes were made:
 *                           1. As per ARDAABD-3627, registers used in
 *                              functions were updated in function banner.
 *                           2. Copyright information updated.
 *                           3. As per ARDAABD-3664, nested critical sections
 *                              were removed.
 *                           4. MISRA Justification messages and tags added.
 *                           5. As per ARDAABD-3841, traceability updated.
 *                           6. As per ARDAABD-2763, the status of GPT driver is
 *                              set at the beginning of Gpt_DeInit API.
 * V2.2.9:  05-Oct-2018     : Following changes are done : 
 *                           1. As part of ARDAABD-3707, ICP0 usage error
 *                              modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to 
 *                              RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 * V2.2.10: 19-Oct-2018 : As part of ARDAABD-3707, Following changes are made:
 *                           1.Remove the RH850_DUMMY_READ_SYNCP Marco.
 * V2.2.11: 25-Oct-2019 : As part of JIRA ticket ARDAABD-4020, following change
 *                        are made:
 *                           1. Add TAUDnTE,TAUBnTE,TAUJnTE registers in the
 *                              comment of Gpt_Init API.
 *                           2. Update the copyright.
 *                           3. Corrected the format issue.
 *                        Added information for QAC warnings(5:3206).
 */
/******************************************************************************/
/*Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
/* Implements GPT293, GPT367 */
/* Implements SWS_Gpt_00293 */
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0065, EAAR_PN0034_NR_0018 */
/* Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0012 */
/* Implements EAAR_PN0034_NR_0020, EAAR_PN0034_NR_0069 */
/* Included for Gpt.h inclusion and macro definitions */
#include "Gpt.h"
/* Included for declaration of the Low Level Driver function */
#include "Gpt_LLDriver.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"
/* Implements GPT278, GPT321, GPT175, GPT321_Conf, GPT375 */
/* Implements GPT_ESDD_UD_026 */
/* Implements SWS_Gpt_00278, SWS_Gpt_00375, ECUC_Gpt_00321 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
/* Implements GPT373 */
/* Implements SWS_Gpt_00373 */
/* Implements GPT_ESDD_UD_034 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Gpt.h"
#endif
/* Included for the macro declaration of Synchronous processing */
/* with dummy read and SYNCP. */
#include "Iocommon_Defines.h"
/* Implements GPT374 */
/* Implements SWS_Gpt_00374 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include GPT_MEMMAP_FILE
/* Implements GPT178, GPT175 */
/* Implements SWS_Gpt_00178 */
/* Implements GPT_ESDD_UD_075 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_CheckDetErrors
(const Gpt_ChannelType channel, const uint8 Api_SID);
#endif

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_C_AR_RELEASE_REVISION_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_C_SW_MAJOR_VERSION    1
#define GPT_C_SW_MINOR_VERSION    0

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
/* Implements GPT256 */
/* Implements SWS_Gpt_00256 */
/* Functionality related to R4.0 */
#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt.c : Mismatch in Release Major Version"
#endif

#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt.c : Mismatch in Release Minor Version"
#endif

#if (GPT_AR_RELEASE_REVISION_VERSION != GPT_C_AR_RELEASE_REVISION_VERSION)
#error "Gpt.c : Mismatch in Release Revision Version"
#endif

#if (GPT_SW_MAJOR_VERSION != GPT_C_SW_MAJOR_VERSION)
#error "Gpt.c : Mismatch in Software Major Version"
#endif

#if (GPT_SW_MINOR_VERSION != GPT_C_SW_MINOR_VERSION)
#error "Gpt.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                      Global Data                                          **
 ******************************************************************************/
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
/* 2.QAC Warning :                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-2 and                           */
/*                 END Msg(2:3227)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.Also this is not a MISRA violation            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning  START Msg(2:2824)-3 and              */
/*                 END Msg(2:2824)-3  tags in the code.                       */
/******************************************************************************/
/* 4.QAC Warning :                                                            */
/* Message       : (5:3206) The parameter is not used in this function.       */
/* Rule          : NA                                                         */
/* Justification : API implemented based on AUTOSAR requirements              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(5:3206)-4 and                           */
/*                 END Msg(5:3206)-4 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/
/*Implements EAAR_PN0034_NR_0026 */
/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1   and                         */
/*                 END Msg(4:0491)-1   tags in the code.                      */
/*                                                                            */
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2991) The value of this 'if' controlling expression is  */
/*                 always 'true'.                                             */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Certain configurations exclude the checks that make the    */
/*                 expression always true. That leads to this violation being */
/*                 present on certain configurations only                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-2   and                         */
/*                 END Msg(4:2991)-2   tags in the code.                      */
/*                                                                            */
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is           */
/*                 always 'true'.                                             */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Certain configurations exclude the checks that make the    */
/*                 expression always true. That leads to this violation being */
/*                 present on certain configurations only                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-3   and                         */
/*                 END Msg(4:2995)-3   tags in the code.                      */
/*                                                                            */
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2004) No concluding 'else' exists in this               */
/*                 'if'-'else'-'if' statement..                               */
/* Rule          : MISRA-C:2004 Rule 14.10                                    */
/* Justification : Certain configurations exclude certain 'if' branches       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2004)-4   and                         */
/*                 END Msg(4:2004)-4   tags in the code.                      */
/*                                                                            */
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.7                                     */
/* Justification : Certain configurations use the value before modifying it   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-5   and                         */
/*                 END Msg(4:2982)-5   tags in the code.                      */
/*                                                                            */
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is           */
/*                 always 'false'.                                            */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Certain configurations exclude the checks that make the    */
/*                 expression always false. That leads to this violation being*/
/*                 present on certain configurations only.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-6   and                         */
/*                 END Msg(4:2996)-6   tags in the code.                      */
/*                                                                            */
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation appears to be redundant because a  */
/*                 given constant value can always be used instead.           */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-7 and                           */
/*                 END Msg(4:2984)-7 tags in the code.                        */
/*                                                                            */
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2877) This loop will only be executed once and so the   */
/*                 loop mechanism is redundant.                               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-8 and                           */
/*                 END Msg(4:2877)-8 tags in the code.                        */
/*                                                                            */
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2993) The value of this 'do - while' control expression */
/*                 is always 'false'. The loop will only be executed once.    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one controller is configured.                         */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2993)-9 and                           */
/*                 END Msg(4:2993)-9 tags in the code.                        */
/*                                                                            */
/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-10 and                          */
/*                 END Msg(4:0303)-10 tags in the code.                       */
/*                                                                            */
/******************************************************************************/


/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 ** Function Name         : Gpt_GetVersionInfo
 **
 ** Service ID            : 0x00
 **
 ** Description           : This API returns the version information of GPT
 **                         driver component.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : None
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : versioninfo
 **
 ** Return parameter      : None
 **
 ** Preconditions         : None
 **
 ** Global Variables      : None
 **
 ** Functions invoked     : Det_ReportError
 **
 ** Registers Used        : None
 **
 ******************************************************************************/
/* Implements GPT182, GPT319_Conf */
/* Implements GPT_ESDD_UD_028 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0092 */
#if (GPT_VERSION_INFO_API == STD_ON)
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_START_SEC_CODE_ASIL_B
#else
#define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT279, GPT338, GPT181, SWS_Gpt_00279, GPT_ESDD_UD_125, GPT175 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_GetVersionInfo(
     P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA)versioninfo
     )
/* END Msg(2:3227)-2 */
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    /* Implements GPT338, SWS_Gpt_00338 */
    /* Implements GPT_ESDD_UD_025, GPT_ESDD_UD_072, GPT_ESDD_UD_073 */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
    GPT_GET_VERSION_INFO_SID, GPT_E_PARAM_POINTER);
  }
  else
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)GPT_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)GPT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = GPT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = GPT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = GPT_SW_PATCH_VERSION;
  }
}
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_STOP_SEC_CODE_ASIL_B
#else
#define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
#endif /* (GPT_VERSION_INFO_API == STD_ON) */
/*******************************************************************************
 ** Function Name         : Gpt_Init
 **
 ** Service ID            : 0x01
 **
 ** Description           : This API performs the initialization of GPT Driver
 **                         component.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Non Reentrant
 **
 ** Input Parameters      : configPtr
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : None
 **
 ** Global Variables      : Gpt_GblDriverStatus, Gpt_GpChannelConfig,
 **                         Gpt_GpChannelRamData, Gpt_GucDriverMode,
 **                         Gpt_GpTAUUnitConfig, Gpt_GpWakeUpFactorRamAddress
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_Init,
 **                         Gpt_HW_StartPredefTimer(4.2.2)
 **
 ** Registers Used        : TAUDnCMORm, TAUBnCMORm, TAUDnTPS, TAUDnCDRm,
 **                         TAUBnTPS, TAUDnBRS, TAUJnTPS, TAUJnBRS,TAUJnCMORm,
 **                         ICTAUDnIm, ICTAUBnIm, ICTAUJnIm, ICOSTMn, OSTMnCMP,
 **                         TAUBnCDRm, TAUJnCDRm, TAUDnTOE, TAUBnTOE, TAUJnTOE,
 **                         TAUBnRDC, TAUBnRDM, TAUBnRDS, TAUDnRDC, TAUDnRDE,
 **                         TAUDnRDM, TAUDnRDS, TAUJnRDM, TAUJnRDE, TAUBnCMURm,
 **                         TAUDnCMURm, TAUJnCMURm, OSTMnCTL, TAUBnRDE, FEINTFC,
 **                         FEINTFMSK, OSTMnTS, OSTMnTE, TAUBnBRS, TAUDnTE,
 **                         TAUBnTE, TAUJnTE.
 **
 ******************************************************************************/
/* Implements GPT_ESDD_UD_035 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0080_FR_0041 */
/* Implements EAAR_PN0080_FR_0041 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT280, GPT342, GPT340, GPT257 */
/* Implements SWS_Gpt_00280, SWS_Gpt_00342, SWS_Gpt_00257 */
/* Implements GPT_ESDD_UD_085, GPT_ESDD_UD_025, GPT_ESDD_UD_001 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_Init(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST)configPtr
    )
/* END Msg(2:3227)-2 */
{
/* Implements GPT_ESDD_UD_027 */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  uint8 LucChannelID;
#endif
/* Implements EAAR_PN0034_FR_0021 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;

  /* Check if configure pointer is NULL pointer */
  if ((NULL_PTR == configPtr) ||
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
     (GPT_TAUB_UNIT_USED == STD_ON))
     (NULL_PTR == configPtr->pTAUUnitConfig) ||
#endif
    /* Implements GPT_ESDD_UD_123 */
#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
     (NULL_PTR == configPtr->pWakeUpFactorRamAddress) ||
#endif
     (NULL_PTR == configPtr->pChannelConfig) ||
     (NULL_PTR == configPtr->pChannelRamAddress))
  {
    /* Implements SWS_BSW_00050*/
    /* Implements GPT_ESDD_UD_073 */
    /* Report to DET */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
    (void)Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
    GPT_INIT_SID, GPT_E_INIT_FAILED );
#else
    /* Implements GPT294 */
    /* Implements SWS_Gpt_00294 */
    (void)Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
    GPT_INIT_SID, GPT_E_PARAM_POINTER );
#endif /* End of GPT_AR_VERSION == GPT_AR_HIGHER_VERSION */
    LddReturnValue = E_NOT_OK;
  } /* End of configPtr == NULL_PTR */
  else
  {
    /* No action required */
  }
  /* Implements GPT_ESDD_UD_111 */
  /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Implements GPT307, GPT309 */
  /* Implements SWS_Gpt_00307, SWS_Gpt_00309, EAAR_PN0034_FR_0063 */
  /* Implements GPT_ESDD_UD_071 */
  /* Check if the GPT Driver is already Initialized */
  if (GPT_INITIALIZED == Gpt_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
    GPT_INIT_SID, GPT_E_ALREADY_INITIALIZED);
    LddReturnValue = E_NOT_OK;
  } /* End of Gpt_GblDriverStatus == GPT_INITIALIZED */
  else
  {
    /* No action required */
  }
#endif
  /* Implements GPT332 */
  /* Implements SWS_Gpt_00332 */
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)

#endif
  {
    /* Implements GPT006 */
    /* Implements SWS_Gpt_00006 */
    /* Check whether the existing database is correct */
    if (GPT_DBTOC_VALUE == (configPtr->ulStartOfDbToc))
    {
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON) )
      /* Store the global pointer to first TAU Unit Configuration */
      Gpt_GpTAUUnitConfig = configPtr->pTAUUnitConfig;
#endif
      /* Store the global pointer to first Channel Configuration */
      Gpt_GpChannelConfig = configPtr->pChannelConfig;
      /* Store the global pointer to First Channel's Ram data */
      Gpt_GpChannelRamData = configPtr->pChannelRamAddress;
      /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      LucChannelID = GPT_CHANNELID_INIT_VAL;
      do
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* Clearing wakeup occurrence status for all configured channels */
        Gpt_GpChannelRamData[LucChannelID].uiGptWakeupOccurrence = GPT_FALSE;
        /* END Msg(4:0491)-1 */
        /* MISRA Violation: START Msg(4:2984)-7 */
        /* Increment the Channel ID count */
        LucChannelID++;
        /* END Msg(4:2984)-7 */
      } /* MISRA Violation: START Msg(4:2996)-6 */
        /* MISRA Violation: START Msg(4:2993)-9 */
        while (GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
        /* END Msg(4:2993)-9 */
        /* END Msg(4:2996)-6 */
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
#if (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
      /*
       * Update the global pointer with the first channel's address
       * of Wake up factor Register's
       */
      Gpt_GpWakeUpFactorRamAddress = configPtr->pWakeUpFactorRamAddress;
#endif
      /* Invoke low level driver for Initializing the GPT registers */
      Gpt_HW_Init();
      /* Implements GPT178 */
      /* Implements GPT176 */
      /* Implements SWS_Gpt_00178 */
      /* Implements SWS_Gpt_00176 */
      /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
      /* Implements SWS_Gpt_00386 */
      /* Implements SWS_Gpt_00390 */
      Gpt_HW_StartPredefTimer();
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

      /* Set Driver state to Initialized */
      Gpt_GblDriverStatus = GPT_INITIALIZED;

      /* Implements GPT339 */
      /* Implements SWS_Gpt_00339 */
      /* Set the Driver Mode to Normal */
      Gpt_GucDriverMode = GPT_MODE_NORMAL;
    } /* End of configPtr->ulStartOfDbToc) == GPT_DBTOC_VALUE */

    else
    {
      /* Implements GPT175, GPT176 */
      /* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0016 */
      /* Implements GPT_ESDD_UD_071 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
      GPT_E_INVALID_DATABASE);
#endif
    }
  } /* End of LddReturnValue == E_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_Init */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_STOP_SEC_CODE_ASIL_B
#else
#define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/******************************************************************************
 ** Function Name         : Gpt_DeInit
 **
 ** Service ID            : 0x02
 **
 ** Description           : This service performs de-initialization of the
 **                         GPT Driver component.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Non Reentrant
 **
 ** Input Parameters      : None
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function.
 **
 ** Global Variables      : Gpt_GblDriverStatus, Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_DeInit
 **
 ** Registers Used        : TAUDnTT,TAUBnTT,TAUJnTT,TAUDnTE,TAUJnTE,FEINTFC,
 **                         ICTAUDnIm, TAUDnCMORm, TAUBnCMORm, TAUJnCMORm,
 **                         TAUDnCDRm, TAUBnCDRm, TAUJnCDRm,OSTMnTT,OSTMnCTL,
 **                         ICTAUBnIm, ICTAUJnIm, ICOSTMn,OSTMnCMP, TAUDnTOE,
 **                         TAUBnTOE,TAUJnTOE, TAUDnTPS, TAUBnTPS,TAUJnTPS,
 **                         TAUDnBRS,TAUJnBRS,TAUBnBRS,OSTMnTE,FEINTFMSK,
 **                         TAUBnTE.
 *****************************************************************************/
/* Implements GPT194, GPT314_Conf */
/* Implements SWS_Gpt_00194 */
/* Implements GPT_ESDD_UD_086, GPT_ESDD_UD_029 */
/* Implements EAAR_PN0034_FR_0049 */
#if (GPT_DE_INIT_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT281 */
/* Implements SWS_Gpt_00281 */
/* Implements GPT_ESDD_UD_025, GPT_ESDD_UD_025 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_DeInit(void)
{
  /* Implements GPT175, GPT176 */
  /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Initialize local variable to first Channel */
  uint8 LucChannelID;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue ;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LucChannelID = GPT_CHANNELID_INIT_VAL;
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* Implements GPT220 */
  /* Implements SWS_Gpt_00220 */
  /* Implements GPT_ESDD_UD_071 */
  /* Check if the GPT Driver is Initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_DEINIT_SID, GPT_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  } /* End of Gpt_GblDriverStatus != GPT_INITIALIZED */
  else
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:2877)-8 */
    for (LucChannelID = GPT_ZERO; ((LucChannelID < GPT_TOTAL_CHANNELS_CONFIG)
            && (E_OK == LddReturnValue)); LucChannelID++)
    /* END Msg(4:2877)-8 */
    {
      /* QAC Warning START Msg(2:2824)-3 */
      if (GPT_CH_RUNNING
          == Gpt_GpChannelRamData[LucChannelID].ucChannelStatus)
      /* END Msg(2:2824)-3 */
      {
        LddReturnValue = E_NOT_OK;
      } /* End of  Gpt_GpChannelRamData[LucChannelID].ucChannelStatus
       == GPT_CH_RUNNING */
      else
      {
        /* No action required */
      }
      /* END Msg(4:0491)-1 */
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Clearing wakeup occurrence status for all configured channels */
      Gpt_GpChannelRamData[LucChannelID].uiGptWakeupOccurrence = GPT_FALSE;
      /* END Msg(4:0491)-1 */
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
    }
    /* Implements GPT234 */
    /* Implements SWS_Gpt_00234 */
    /* Implements GPT_ESDD_UD_071 */
    /* Check if the Channel is in Running State */
    if (E_NOT_OK == LddReturnValue)
    {
      /* Report to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID,
          GPT_E_BUSY);
    } /* End of LddReturnValue == E_NOT_OK */
    else
    {
      /* No action required */
    }
  }

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
    /* Implements SWS_Gpt_00386 */
    /* Implements SWS_Gpt_00391 */
    Gpt_HW_StopPredefTimer();
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
    /* Implements GPT363 */
    /* Implements SWS_Gpt_00363 */
    /* Set Driver state to uninitialized */
    Gpt_GblDriverStatus = GPT_UNINITIALIZED;
    /* Implements GPT008 */
    /* Implements SWS_Gpt_00008 */
    /* Invoke low level driver for de-initializing the hardware */
    Gpt_HW_DeInit();
  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_DeInit */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_STOP_SEC_CODE_ASIL_B
#else
#define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_DE_INIT_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_GetTimeElapsed
 **
 ** Service ID            : 0x03
 **
 ** Description           : This API is used to read the time elapsed for a
 **                         particular Channel from the start of Channel.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : LddTimeElapsed
 **
 ** Preconditions         : Gpt_Init must be called before this function.
 **
 ** Global Variables      :  Gpt_GpChannelRamData
 **
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_GetTimeElapsed
 **                         and Gpt_CheckDetErrors
 **
 ** Registers Used        : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm,OSTMnCNT,
 **                         TAUDnCNTm, TAUBnCNTm, TAUJnCNTm,OSTMnCMP,
 **                         ICOSTMn, ICTAUDnIm, ICTAUBnIm, ICTAUJnIm.
 **
 ******************************************************************************/
/* Implements GPT195, GPT317_Conf */
/* Implements SWS_Gpt_00195 */
/* Implements GPT_ESDD_UD_030 */
/* Implements EAAR_PN0034_FR_0049 */
#if (GPT_TIME_ELAPSED_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT282 */
/* Implements GPT113 */
/* Implements SWS_Gpt_00282 */
/* Implements SWS_Gpt_00113 */
/* Implements GPT_ESDD_UD_088 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeElapsed(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
#endif
  /* Implements GPT_ESDD_UD_076 */
  /* Declare the variable to store the return value */
  Gpt_ValueType LddTimeElapsed;
  /* Implements GPT175, GPT176 */
  /* Implements EAAR_PN0034_FR_0021 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is initialized properly */

  /* Implements GPT210 */
  /* Implements GPT222 */
  /* Implements SWS_Gpt_00210 */
  /* Implements SWS_Gpt_00222 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_GET_TIME_ELAPSED_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke low level driver for getting the Elapsed Time */
    LddTimeElapsed = Gpt_HW_GetTimeElapsed(channel);
  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Initialize the return value as zero */
    LddTimeElapsed = (Gpt_ValueType) (GPT_RET_VAL_ZERO);
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  /* Return the Elapsed Time */
  return (LddTimeElapsed);
} /* End of API Gpt_GetTimeElapsed */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_GetTimeRemaining
 **
 ** Service ID            : 0x04
 **
 ** Description           : This API is used to read the remaining time for the
 **                         Channel to reach time-out.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : LddTimeRemaining
 **
 ** Preconditions         : Gpt_Init must be called before this function.
 **
 ** Global Variables      :  Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_GetTimeRemaining
 **                         and Gpt_CheckDetErrors
 **
 ** Registers Used        : TAUDnCNTm, TAUBnCNTm, TAUJnCNTm, TAUJnTT, TAUBnTT,
 **                         TAUDnTT, OSTMnTT, OSTMnTE,OSTMnCNT,TAUBnTE,TAUDnTE,
 **                         TAUJnTE,ICTAUDnIm,ICTAUBnIm,ICTAUJnIm,ICOSTMn
 **
 ******************************************************************************/
/* Implements GPT196, GPT318_Conf */
/* Implements SWS_Gpt_00196, ECUC_Gpt_00318 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
/* Implements GPT_ESDD_UD_031 */
#if (GPT_TIME_REMAINING_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT114 */
/* Implements GPT283 */
/* Implements GPT330 */
/* Implements SWS_Gpt_00114 */
/* Implements SWS_Gpt_00283 */
/* Implements SWS_Gpt_00330 */
/* Implements GPT_ESDD_UD_087 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeRemaining(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
#endif

  /* Declare the variable to store the return value */
  Gpt_ValueType LddTimeRemaining;
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)

  /* Implements GPT211 */
  /* Implements GPT223 */
  /* Implements SWS_Gpt_00211 */
  /* Implements SWS_Gpt_00223 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_GET_TIME_REMAINING_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Invoke low level driver for getting Remaining Time */
    LddTimeRemaining = Gpt_HW_GetTimeRemaining(channel);
  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Initialize the return value as zero */
    LddTimeRemaining = (Gpt_ValueType) (GPT_RET_VAL_ZERO);
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  /* Return the Remaining Time */
  return (LddTimeRemaining);
} /* End of API Gpt_GetTimeRemaining */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_TIME_REMAINING_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_StartTimer
 **
 ** Service ID            : 0x05
 **
 ** Description           : This API starts the particular timer Channel.
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel, value
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function.
 **
 ** Global Variables      :  Gpt_GpChannelRamData, Gpt_GpChannelConfig
 **
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_StartTimer
 **                         and Gpt_CheckDetErrors
 **
 ** Registers Used        : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm, OSTMnCMP,
 **                         ICTAUDmIn, ICTAUBmIn, ICTAUJmIn, ICOSTMn,
 **                         TAUDnTS, TAUBnTS, TAUJnTS, OSTMnTS, OSTMnTE,
 **                         TAUBnTE, TAUDnTE, TAUJnTE
 **
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT115 */
/* Implements GPT284 */
/* Implements SWS_Gpt_00115 */
/* Implements SWS_Gpt_00284 */
/* Implements GPT_ESDD_UD_089 */
/* Implements EAAR_PN0034_FR_0049 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_StartTimer(
    Gpt_ChannelType channel,
    Gpt_ValueType value
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT224 */
  /* Implements GPT212 */
  /* Implements SWS_Gpt_00224 */
  /* Implements SWS_Gpt_00212 */
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_START_TIMER_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Implements GPT218 */
    /* Implements SWS_Gpt_00218 */
    /* Implements GPT_ESDD_UD_071 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning START Msg(2:2824)-3 */
    /* Check if the Channel value is more than MAX count value */
    if ((value > (Gpt_GpChannelConfig[channel].ulMaxTickVal)) ||
        ((Gpt_ValueType) (GPT_ZERO) == value))
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0491)-1 */
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_START_TIMER_SID, GPT_E_PARAM_VALUE);
      LddReturnValue = E_NOT_OK;
    } /* End of value > (Gpt_GpChannelConfig->ulMaxTickVal) */

    else
    {
      /* No action required */
    }
    /* Implements GPT084 */
    /* Implements SWS_Gpt_00084 */
    /* QAC Warning START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Check if the timer is already running */
    if (GPT_CH_RUNNING == Gpt_GpChannelRamData[channel].ucChannelStatus)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-3 */
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_START_TIMER_SID, GPT_E_BUSY);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No Action Required */
    }
    if (E_OK == LddReturnValue)
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Invoke low level driver for starting the Channel */
      Gpt_HW_StartTimer(channel, value);
    }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    else

    {
      /* No action required */
    }
#endif
  }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_StartTimer */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE


/*******************************************************************************
 ** Function Name         : Gpt_StopTimer
 **
 ** Service ID            : 0x06
 **
 ** Description           : This API stops the particular timer Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function.
 **
 ** Global Variables      : Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_StopTimer
 **                         and Gpt_CheckDetErrors
 **
 ** Registers Used        : TAUDnTT,TAUBnTT,TAUJnTT,OSTMnTT,TAUDnTE,TAUJnTE,
 **                         OSTMnTE,ICOSTMn,ICTAUJnIm,ICTAUBnIm,ICTAUDnIm,
 **                         TAUBnTE.
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT116 */
/* Implements GPT285 */
/* Implements SWS_Gpt_00116 */
/* Implements SWS_Gpt_00285 */
/* Implements GPT_ESDD_UD_090 */
/* Implements EAAR_PN0034_FR_0049 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_StopTimer(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements GPT213 */
  /* Implements GPT225 */
  /* Implements SWS_Gpt_00213 */
  /* Implements SWS_Gpt_00225 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_STOP_TIMER_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Implements GPT099 */
    /* Implements GPT344 */
    /* Implements SWS_Gpt_00099 */
    /* Implements SWS_Gpt_00344 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning START Msg(2:2824)-3 */
    /* Check if the timer is started */
    if (GPT_CH_RUNNING == Gpt_GpChannelRamData[channel].ucChannelStatus)
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0491)-1 */
    {
      /* Invoke low level driver to Stop the particular Channel */
      Gpt_HW_StopTimer(channel);
    }
    else
    {
      /* No action required */
    }
  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_StopTimer */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_EnableNotification
 **
 ** Service ID            : 0x07
 **
 ** Description           : This API enables the notification for particular
 **                         Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function and
 **                         GPT_ENABLE_DISABLE_NOTIFICATION_API must be STD_ON
 **
 ** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig
 **
 ** Functions invoked     : Det_ReportError and Gpt_CheckDetErrors
 **
 ** Registers Used        : ICTAUDnIm,ICTAUBnIm,ICTAUJnIm,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/
/* Implements GPT199, GPT315_Conf */
/* Implements SWS_Gpt_00199 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0080_FR_0079 */
/* Implements GPT_ESDD_UD_032 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT286 */
/* Implements GPT117 */
/* Implements GPT331 */
/* Implements SWS_Gpt_00286 */
/* Implements SWS_Gpt_00117 */
/* Implements SWS_Gpt_00331 */
/* Implements GPT_ESDD_UD_091 */
/* Implements EAAR_PN0080_FR_0012, EAAR_PN0034_FR_0049 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableNotification(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Implements GPT226 */
  /* Implements SWS_Gpt_00226 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_ENABLE_NOTIFY_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Implements GPT377 */
    /* Implements SWS_Gpt_00377 */
    /* Implements GPT_ESDD_UD_071 */
    /* Check if the Notification Function is configured */
    /* QAC Warning START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (NULL_PTR == Gpt_GpChannelConfig[channel].pGptNotificationPointer)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-3 */
    {
      /* Report Error to Det */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_ENABLE_NOTIFY_SID, GPT_E_PARAM_CHANNEL);
    }
    /* Implements GPT214 */
    /* Implements SWS_Gpt_00214 */
    /* Implements GPT_ESDD_UD_071 */
    /* Check if the Notification Flag is already Enabled */
    /* QAC Warning START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    else if (GPT_NOTIFICATION_ENABLED
        == Gpt_GpChannelRamData[channel].uiNotifyStatus)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-3 */
    {
      /* Report Error to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_ENABLE_NOTIFY_SID, GPT_E_ALREADY_ENABLED);
    } /* End of (Gpt_GpChannelRamData + Channel)->uiNotifyStatus
     == GPT_NOTIFICATION_ENABLED */
    else
#endif
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* Check if the GPT driver is in normal mode */
      if (GPT_MODE_NORMAL == Gpt_GucDriverMode)
      {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
        /* Invoke low level driver to Enable interrupt notification
         * for the particular Channel */
        Gpt_HW_EnableInterrupt(channel);
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      }
      else
      {
        /* do nothing */
      }
      /* Implements GPT014 */
      /* Implements SWS_Gpt_00014 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Set the Notification Status Flag to GPT_TRUE */
      Gpt_GpChannelRamData[channel].uiNotifyStatus = GPT_NOTIFICATION_ENABLED;
      /* END Msg(4:0491)-1 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
    }
  } /* End of LddReturnValue == E_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_EnableNotification */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_DisableNotification
 **
 ** Service ID            : 0x08
 **
 ** Description           : This API disables the notification for particular
 **                         Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function and
 **                         GPT_ENABLE_DISABLE_NOTIFICATION_API must be STD_ON
 **
 ** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig
 **
 ** Functions invoked     : Det_ReportError and Gpt_CheckDetErrors
 **
 ** Registers Used        : ICTAUDnIm,ICTAUBnIm,ICTAUJnIm,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/
/* Implements GPT200, GPT315_Conf */
/* Implements SWS_Gpt_00200 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049, EAAR_PN0080_FR_0080 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT118 */
/* Implements GPT287 */
/* Implements SWS_Gpt_00118 */
/* Implements SWS_Gpt_00287 */
/* Implements GPT_ESDD_UD_092, EAAR_PN0080_FR_0012 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableNotification(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements GPT227 */
  /* Implements GPT217 */
  /* Implements SWS_Gpt_00227 */
  /* Implements SWS_Gpt_00217 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_DISABLE_NOTIFY_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Implements GPT379 */
    /* Implements SWS_Gpt_00379 */
    /* Implements GPT_ESDD_UD_071 */
    /* Check if the Notification Function is configured */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning START Msg(2:2824)-3 */
    if (NULL_PTR == Gpt_GpChannelConfig[channel].pGptNotificationPointer)
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0491)-1 */
    {
      /* Report Error to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_DISABLE_NOTIFY_SID, GPT_E_PARAM_CHANNEL);
    }
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning START Msg(2:2824)-3 */
    else if (GPT_NOTIFICATION_DISABLED
        == Gpt_GpChannelRamData[channel].uiNotifyStatus)
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0491)-1 */
    {
      /* Report Error to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_DISABLE_NOTIFY_SID, GPT_E_ALREADY_DISABLED);
    } /* End of (Gpt_GpChannelRamData + channel)->uiNotifyStatus
     == GPT_NOTIFICATION_DISABLED */
    else
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
    {
      /* Check if the GPT driver is in sleep mode  and not a one shot channel.
       * One shot channel needs to leave the interrupt enabled
       * so it is able to deactivate itself */

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* MISRA Violation: START Msg(4:0491)-1 */
      if ((GPT_MODE_NORMAL == Gpt_GucDriverMode)
          && (GPT_CH_MODE_ONESHOT
              != Gpt_GpChannelConfig[channel].uiGptChannelMode))
      /* END Msg(4:0491)-1 */
      {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
        /* Invoke low level driver to disable interrupt notification
         * for the particular Channel */
        Gpt_HW_DisableInterrupt(channel, GPT_INCLUDE_CRITICAL_SECTION);
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      } /* End of Gpt_GucDriverMode == GPT_MODE_SLEEP */
      else
      {
        /* no action */
      }
      /* Implements GPT015 */
      /* Implements SWS_Gpt_00015 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Set the Notification Status Flag to GPT_FALSE */
      Gpt_GpChannelRamData[channel].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-1 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
    }
  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_DisableNotification */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_SetMode
 **
 ** Service ID            : 0x09
 **
 ** Description           : This API is used to set the GPT Driver mode
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Non Reentrant
 **
 ** Input Parameters      : mode
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function,
 **                         GPT_REPORT_WAKEUP_SOURCE and
 **                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
 **
 ** Global Variables      : Gpt_GblDriverStatus, Gpt_GpChannelConfig,
 **                         Gpt_GucDriverMode, Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_StopTimer,
 **                         Gpt_HW_DisableWakeup, Gpt_HW_EnableWakeup
 **
 ** Registers Used        : TAUDnTT,TAUBnTT,TAUJnTT,OSTMnTT,TAUBnTE,TAUJnTE,
 **                         OSTMnTE,ICOSTMn,ICTAUJnIm,ICTAUBnIm,ICTAUDnIm
 **                         FEINTFMSK,FEINTFC,OSTMnTS,OSTMnCMP,TAUDnTE.
 **
 ******************************************************************************/
/* Implements GPT201 */
/* Implements GPT255, GPT320_Conf */
/* Implements SWS_Gpt_00201 */
/* Implements SWS_Gpt_00255 */
/* Implements GPT_ESDD_UD_093,GPT_ESDD_UD_033 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements SWS_Gpt_00288 */
/* Implements GPT288 */
/* Implements GPT_ESDD_UD_035, GPT_ESDD_UD_077 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_SetMode(
    Gpt_ModeType mode
    )
/* END Msg(2:3227)-2 */
{
  /* Declare a Local variable to store Channel Index */
  uint8 LucChannelID;
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;
  /* Implements GPT228 */
  /* Implements SWS_Gpt_00228 */
  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_SET_MODE_SID, GPT_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  } /* End of Gpt_GblDriverStatus != GPT_INITIALIZED */
  else
  {
    /* No action required */
  }
  /* Implements GPT231 */
  /* Implements SWS_Gpt_00231 */
  /* Implements GPT_ESDD_UD_071 */
  /* Check if the GPT mode is correct */
  if ((GPT_MODE_NORMAL != mode) && (GPT_MODE_SLEEP != mode))
  {

    /* Report to DET */
    (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_SET_MODE_SID, GPT_E_PARAM_MODE);
    LddReturnValue = E_NOT_OK;
  } /* End of (mode != GPT_MODE_NORMAL) && (mode != GPT_MODE_SLEEP) */
  else
  {
    /* No action required */
  }
  /* MISRA Violation: START Msg(4:2004)-4 */
  /* MISRA Violation: START Msg(4:2991)-2 */
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Implements GPT165 */
    /* Implements GPT341 */
    /* Implements SWS_Gpt_00165 */
    /* Implements SWS_Gpt_00341 */
    /* Check if the Mode is Sleep Mode */
    LucChannelID = GPT_CHANNELID_INIT_VAL;
    if (GPT_MODE_SLEEP == mode)
    {
      do
      {
        /* Check for disable wakeup status of a Channel */
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* QAC Warning START Msg(2:2824)-3 */
        if ((GPT_FALSE == Gpt_GpChannelConfig[LucChannelID].uiGptWakeupSupport)
            || (GPT_WAKEUP_NOTIFICATION_DISABLED
                == Gpt_GpChannelRamData[LucChannelID].uiWakeupStatus))
        /* END Msg(2:2824)-3 */
        /* END Msg(4:0491)-1 */
        { /* Invoke low level driver to Stop the Particular Channel */
          /* Implements GPT164 */
          /* Implements GPT153 */
          /* Implements SWS_Gpt_00164 */
          /* Implements SWS_Gpt_00153 */
          Gpt_HW_StopTimer(LucChannelID);
        }
        else
        {
          /* Enable interrupt notification for the channel */
          Gpt_HW_EnableInterrupt(LucChannelID);
          /* No action required */
        }
        /* MISRA Violation: START Msg(4:2984)-7 */
        /* Increment the Channel ID count */
        LucChannelID++;
        /* END Msg(4:2984)-7 */
      }/* MISRA Violation: START Msg(4:2996)-6 */
       /* MISRA Violation: START Msg(4:2993)-9 */
      while (GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
      /* END Msg(4:2993)-9 */
      /* END Msg(4:2996)-6 */
      /* Implements GPT151 */
      /* Implements SWS_Gpt_00151 */
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
      /* Implements SWS_Gpt_00386 */
      /* Implements SWS_Gpt_00393 */
      /*If the parameter Mode has the value GPT_MODE_SLEEP, the function
       *shall stop all enabled GPT Predef Timers
       */
      Gpt_HW_StopPredefTimer();
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
      /* Set the Mode to the Global variable */
      Gpt_GucDriverMode = mode;
    } /* End of mode == GPT_MODE_SLEEP */
    /* Implements GPT152 */
    /* Implements SWS_Gpt_00152 */
    /* MISRA Violation: START Msg(4:2995)-3 */
    else if (GPT_MODE_NORMAL == mode)
    /* END Msg(4:2995)-3 */
    {
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
      /* Implements SWS_Gpt_00386 */
      /* Implements SWS_Gpt_00392 */
      /* Only If the driver is in sleep mode, the function shall
       * restart all enabled GPT Predef Timers
       */
      if (GPT_MODE_SLEEP == Gpt_GucDriverMode)
      {
        Gpt_HW_StartPredefTimer();
      }
      else
      {
         /* No action required */
      }
#endif /*End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */
      do
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        if (GPT_CH_MODE_ONESHOT
            == Gpt_GpChannelConfig[LucChannelID].uiGptChannelMode)
        /* END Msg(4:0491)-1 */
        {
          /* We don't want to touch the one-shot channel.
           * The way the interrupt is handled previously is left alone. */
        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* Check the notification status of a Channel */
        else if ((NULL_PTR
            != Gpt_GpChannelConfig[LucChannelID].pGptNotificationPointer)
            && (GPT_NOTIFICATION_ENABLED
                == Gpt_GpChannelRamData[LucChannelID].uiNotifyStatus))
        /* END Msg(4:0491)-1 */
        {
          /* Invoke low level driver to enable notification for the
           * particular Channel. */
          Gpt_HW_EnableInterrupt(LucChannelID);
        }
#endif
        else
        {
          /* Disable interrupt notification for the channel */
          Gpt_HW_DisableInterrupt(LucChannelID, GPT_INCLUDE_CRITICAL_SECTION);
        }
        /* MISRA Violation: START Msg(4:2984)-7 */
        /* Increment the Channel ID count */
        LucChannelID++;
        /* END Msg(4:2984)-7 */
      }/* MISRA Violation: START Msg(4:2996)-6 */
       /* MISRA Violation: START Msg(4:2993)-9 */
      while (GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
      /* END Msg(4:2993)-9 */
      /* END Msg(4:2996)-6 */
      /* Implements GPT151 */
      /* Implements SWS_Gpt_00151 */
      /* Set the Mode to the Global variable */
      Gpt_GucDriverMode = mode;
    }
#if (GPT_DEV_ERROR_DETECT == STD_OFF)
    else
    {
      /*In case wrong mode is requested return without any change */
    }
#endif
    /* END Msg(4:2004)-4 */
    /* END Msg(4:2991)-2 */
  } /* End of LddReturnValue == E_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /*In case driver is not initialized or wrong mode is requested
     * return without any change */
  }
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */

} /* End of API Gpt_SetMode */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /*
 * End of (GPT_REPORT_WAKEUP_SOURCE == STD_ON) &&
 * (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
 */

/*******************************************************************************
 ** Function Name         : Gpt_DisableWakeup
 **
 ** Service ID            : 0x0A
 **
 ** Description           : This API disables the wakeup notification for a
 **                         particular Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function,
 **                         GPT_REPORT_WAKEUP_SOURCE and
 **                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GucDriverMode
 **                         Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_DisableWakeup,
 **                         Gpt_CheckDetErrors, GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used        : ICTAUDnIm,ICTAUBnIm,ICTAUJnIm,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/
/* Implements GPT157 */
/* Implements GPT202, GPT320_Conf */
/* Implements SWS_Gpt_00157 */
/* Implements SWS_Gpt_00202 */
/* Implements GPT_ESDD_UD_094 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT289 */
/* Implements GPT115 */
/* Implements GPT155 */
/* Implements SWS_Gpt_00289 */
/* Implements SWS_Gpt_00155 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableWakeup(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements GPT229 */
  /* Implements SWS_Gpt_00229 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_DISABLE_WAKEUP_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Implements GPT215 */
    /* Implements SWS_Gpt_00215 */
    /* QAC Warning START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    if (GPT_FALSE == Gpt_GpChannelConfig[channel].uiGptWakeupSupport)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-3 */
    {
      /* Report to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_DISABLE_WAKEUP_SID, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Check if the GPT driver is in sleep mode and not a one shot channel
       * One shot channel needs to leave the interrupt enabled
       * so it is able to deactivate itself */
      if ((GPT_MODE_SLEEP == Gpt_GucDriverMode)
          && (GPT_CH_MODE_ONESHOT
              != Gpt_GpChannelConfig[channel].uiGptChannelMode))
      /* END Msg(4:0491)-1 */
      {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
        /*Invoke low level driver to Disable interrupt for the particular
         * Channel */
        Gpt_HW_DisableInterrupt(channel, GPT_INCLUDE_CRITICAL_SECTION);
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      } /* End of Gpt_GucDriverMode == GPT_MODE_SLEEP &&
       (GPT_CH_MODE_ONESHOT != Gpt_GpChannelConfig[channel].uiGptChannelMode)
       */
      else
      {
      }
      /* QAC Warning START Msg(2:2824)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Store Wakeup Notification status */
      Gpt_GpChannelRamData[channel].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
    }

  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_DisableWakeup */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /*
 * End of (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
 * (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
 */

/*******************************************************************************
 ** Function Name         : Gpt_EnableWakeup
 **
 ** Service ID            : 0x0B
 **
 ** Description           : This API enables the wakeup notification for a
 **                         particular Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function,
 **                         GPT_REPORT_WAKEUP_SOURCE and
 **                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
 **
 ** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig,
 **                         Gpt_GucDriverMode
 **
 ** Functions invoked     : Det_ReportError, Gpt_HW_EnableWakeup,
 **                         Gpt_CheckDetErrors, GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used        : ICTAUDnIm,ICTAUBnIm,ICTAUJnIm,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/
/* Implements GPT203, GPT320_Conf */
/* Implements SWS_Gpt_00203 */
/* Implements GPT_ESDD_UD_095 */
/* Implements EAAR_PN0034_FR_0021 */
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT290 */
/* Implements GPT156, GPT322_Conf */
/* Implements SWS_Gpt_00290 */
/* Implements SWS_Gpt_00156, ECUC_Gpt_00322 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableWakeup(
    Gpt_ChannelType channel
    )
/* END Msg(2:3227)-2 */
{
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements GPT230 */
  /* Implements SWS_Gpt_00230 */
  LddReturnValue = Gpt_CheckDetErrors(channel, GPT_ENABLE_WAKEUP_SID);

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
#endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Implements GPT216 */
    /* Implements SWS_Gpt_00216 */
    /* QAC Warning START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Check if the wake up status if GPT_FALSE */
    if (GPT_FALSE == Gpt_GpChannelConfig[channel].uiGptWakeupSupport)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-3 */
    {
      /* Report to DET */
      (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
          GPT_ENABLE_WAKEUP_SID, GPT_E_PARAM_CHANNEL);
    }
    /* Implements GPT158 */
    /* Implements SWS_Gpt_00158 */
    else
#endif
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* Check if the GPT driver is in sleep mode */
      if (GPT_MODE_SLEEP == Gpt_GucDriverMode)
      {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
        /* Invoke low level driver to Enable wakeup
         * notification for the particular Channel */
        Gpt_HW_EnableInterrupt(channel);
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      }
      else
      {
      }
      /* QAC Warning START Msg(2:2824)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Store Wakeup Notification status */
      Gpt_GpChannelRamData[channel].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_ENABLED;
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif

    }

  } /* End of LddReturnValue == E_NOT_OK */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
#endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */

} /* End of API Gpt_EnableWakeup */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /*
 * End of (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
 * (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
 */

/*******************************************************************************
 ** Function Name         : Gpt_CheckWakeup
 **
 ** Service ID            : 0x0C
 **
 ** Description           : This API checks the wakeup notification for a
 **                         particular Channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Re-entrancy           : Reentrant
 **
 ** Input Parameters      : wakeupSource
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : Gpt_Init must be called before this function,
 **                         GPT_REPORT_WAKEUP_SOURCE and
 **                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
 **
 ** Global Variables      : Gpt_GblDriverStatus, Gpt_GpChannelConfig
 **                         Gpt_GpChannelRamData
 **
 ** Functions invoked     : Det_ReportError, EcuM_SetWakeupEvent,
 **                         GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used        : None
 **
 ******************************************************************************/
/* Implements GPT324 */
/* Implements GPT322, GPT320_Conf */
/* Implements SWS_Gpt_00324 */
/* Implements SWS_Gpt_00322 */
/* Implements GPT_ESDD_UD_104 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT328 */
/* Implements GPT323, GPT322_Conf */
/* Implements SWS_Gpt_00328 */
/* Implements SWS_Gpt_00323, ECUC_Gpt_00322 */
/* Implements GPT_ESDD_UD_035 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(void, GPT_PUBLIC_CODE) Gpt_CheckWakeup(
    EcuM_WakeupSourceType wakeupSource
    )
/* END Msg(2:3227)-2 */
{
  boolean LblWakeupFlag;
  uint8 LucChannelID;
  LucChannelID = GPT_CHANNELID_INIT_VAL;
  /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Implements GPT325 */
  /* Implements SWS_Gpt_00325 */
  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_CHECK_WAKEUP_SID, GPT_E_UNINIT);
  } /* End of Gpt_GblDriverStatus != GPT_INITIALIZED */

  else
#endif/* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    do
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* QAC Warning START Msg(2:2824)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Save the Wakeup occurrence into the local variable */
      LblWakeupFlag = Gpt_GpChannelRamData[LucChannelID].uiGptWakeupOccurrence;
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* QAC Warning START Msg(2:2824)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* Implements GPT321 */
      /* Implements SWS_Gpt_00321 */
      /* Check whether the notification is from the configured Channel */
      if (((Gpt_GpChannelConfig[LucChannelID].ddWakeupSource) == wakeupSource)
          && (GPT_TRUE == LblWakeupFlag))
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-3 */
      {
        /* Invoke the EcuM Set Wakeup API*/
        EcuM_SetWakeupEvent(wakeupSource);

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* Reset wakeup occurrence flag for Channel */
        Gpt_GpChannelRamData[LucChannelID].uiGptWakeupOccurrence = GPT_FALSE;
        /* END Msg(4:0491)-1 */

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif

        /* Update the Channel ID with maximum number of Channel configured */
        LucChannelID = GPT_TOTAL_CHANNELS_CONFIG;
      } /*
       * End of ((LpChannel->ddWakeupSource) == wakeupSource) &&
       * (LblWakeupFlag == GPT_TRUE))
       */
      else
      {
        /* Increment Channel ID count */
        LucChannelID++;
      }

    }
    while (GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
  }
} /* End of API Gpt_CheckWakeup */


#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /*
 * End of (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
 * (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
 */
/*******************************************************************************
 ** Function Name        : Gpt_CheckDetErrors
 **
 ** Service ID           : None
 **
 ** Description          : This API is used to report DET for invalid
 **                        initialization and invalid Channel in this file.
 **
 ** Sync/Async           : -
 **
 ** Re-entrancy          : -
 **
 ** Input Parameters     : channel, Api_SID
 **
 ** InOut Parameters     : None
 **
 ** Output Parameters    : None
 **
 ** Return parameter     : LddReturnValue
 **
 ** Preconditions        : NA
 **
 ** Global Variables     : Gpt_GblDriverStatus
 **
 ** Functions invoked    : Det_ReportError
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_052*/
/* Implements GPT_ESDD_UD_106 */
/* Implements GPT175, GPT176 */
STATIC FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_CheckDetErrors
(const Gpt_ChannelType channel, const uint8 Api_SID)
{
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;

  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET module */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        Api_SID, GPT_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check channel is in the valid range */
  /*Implements GPT_ESDD_UD_052*/
  if (GPT_MAX_CHANNEL_ID_CONFIGURED < channel)
  {
    /* Report to DET module */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        Api_SID, GPT_E_PARAM_CHANNEL);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  return(LddReturnValue);
}

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif
/*******************************************************************************
 ** Function Name        : Gpt_GetPredefTimerValue
 **
 ** Service ID           : 0x0D
 **
 ** Description          : This API is used to read the value of a Predef Timer
 **
 ** Sync/Async           : Synchronous
 **
 ** Re-entrancy          : Reentrant
 **
 ** Input Parameters     : PredefTimer
 **
 ** InOut Parameters     : None
 **
 ** Output Parameters    : *TimeValuePtr
 **
 ** Return parameter     : LddPredefTimerTime
 **
 ** Preconditions        : NA
 **
 ** Global Variables     : Gpt_GblDriverStatus
 **
 ** Functions invoked    : Det_ReportError, Gpt_HW_GetPredefTimerValue
 **
 ** Registers Used       : OSTMnCNT, ICOSTMn, FEINTF
 **
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_START_SEC_CODE_ASIL_B
#else
#define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*Implements GPT_ESDD_UD_059 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
/*Implements SWS_Gpt_00386 */
/*Implements SWS_Gpt_00394 */
/*Implements GPT_ESDD_UD_155, GPT_ESDD_UD_079 */
FUNC(Std_ReturnType, GPT_PUBLIC_CODE) Gpt_GetPredefTimerValue(
    /* QAC Warning START Msg(5:3206)-4 */
    Gpt_PredefTimerType PredefTimer,
    /* END Msg(5:3206)-4 */
    /* QAC Warning START Msg(5:3206)-4 */
    uint32* TimeValuePtr )
    /* END Msg(5:3206)-4 */
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
  Gpt_ValueType LddPredefTimerTime;

  LddReturnValue = E_OK;

  /* MISRA Violation: START Msg(4:2982)-5 */
  /* Declare the variable to store the time value */
  LddPredefTimerTime = (Gpt_ValueType) (GPT_TIMER_INIT_VAL_ZERO);
  /* END Msg(4:2982)-5 */
  /* Check if the GPT Driver is initialised properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET module */
    /* Implements SWS_Gpt_00398 */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_PREDEF_TIMER_VALUE_SID, GPT_E_UNINIT);
#endif
    /* Implements SWS_Gpt_00402 */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* check that driver is not in Sleep Mode */
  if (GPT_MODE_SLEEP == Gpt_GucDriverMode)
  {
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET module */
    /* Implements SWS_Gpt_00401 */
    /* Implements GPT_ESDD_UD_073 */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_PREDEF_TIMER_VALUE_SID, GPT_E_MODE);
#endif
    /* Implements SWS_Gpt_00402 */
    LddReturnValue = E_NOT_OK;
  }/* Check that a valid pointer is passed as a parameter */
  else
  {
    /* No action required */
  }
  if ( NULL_PTR == TimeValuePtr)
  {
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET module */
    /* Implements SWS_Gpt_00403 */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_PREDEF_TIMER_VALUE_SID, GPT_E_PARAM_POINTER);
#endif
    LddReturnValue = E_NOT_OK;
  } /* Check that the Predef Timer passed as parameter is valid and enabled*/
  else
  {
    /* No action required */
  }
  /*Implements ECUC_Gpt_00335, ECUC_Gpt_00334 */
  /*Implements GPT_ESDD_UD_150 */
  if (( PredefTimer > GPT_PREDEF_TIMER_100US_32BIT) ||
#if (GPT_PREDEF_TIMER_100US_32BIT_ENABLE != STD_ON)
      (GPT_PREDEF_TIMER_100US_32BIT == PredefTimer) ||
#endif
      ((GPT_PREDEF_TIMER_100US_32BIT != PredefTimer) &&
   /* MISRA Violation: START Msg(4:2996)-6 */
   (PredefTimer >= (Gpt_PredefTimerType) GPT_PREDEF_TIMER_1US_ENABLING_GRADE ))
   /* END Msg(4:2996)-6 */
  )
  {
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET module */
    /* Implements SWS_Gpt_00399, SWS_Gpt_00400 */
    /* Implements GPT_ESDD_UD_073 */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_PREDEF_TIMER_VALUE_SID, GPT_E_PARAM_PREDEF_TIMER);
#endif
    /* Implements SWS_Gpt_00402 */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  {
    /* Implements SWS_Gpt_00395 */
    /* Invoke low level driver for getting Remaining Time */
    LddPredefTimerTime = Gpt_HW_GetPredefTimerValue(PredefTimer);
    /* Load timer value only when no error has previously occurred.*/
    (*TimeValuePtr) = LddPredefTimerTime;
  } /* End of LddReturnValue == E_NOT_OK */
  else
  {
    /* An error occurred. Time variable is not updated */
  }
#else
#if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET module */
  /* Implements SWS_Gpt_00399 */
  /* Implements SWS_Gpt_00400 */
  /* Implements GPT175, GPT176 */
  (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
      GPT_GET_PREDEF_TIMER_VALUE_SID, GPT_E_PARAM_PREDEF_TIMER);
#endif
  /* Implements SWS_Gpt_00402 */
  LddReturnValue = E_NOT_OK;
#endif /* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/

  /* Return the Status of the API*/
  return LddReturnValue;
}

#endif /* #if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#define GPT_STOP_SEC_CODE_ASIL_B
#else
#define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name        : Gpt_HWCheckConsistency
 **
 ** Service ID           : 0x0E
 **
 ** Description          : This function compares the control register values
 **                        with its corresponding RAM mirror
 **                        variable if GPT_OSTM_RAM_MIRROR or
 **                        GPT_TAUDB_RAM_MIRROR or GPT_TAUJ_RAM_MIRROR
 **                        is GPT_MIRROR_ENABLE and the driver is already
 **                        initialized.
 ** Sync/Async           : Synchronous
 **
 ** Re-entrancy          : Reentrant
 **
 ** Input Parameters     : HWConsistencyMode
 **
 ** InOut Parameters     : None
 **
 ** Output Parameters    : None
 **
 ** Return parameter     : LddRetConsistencyState
 **
 ** Preconditions        : This API is available only if the pre-compile
 **                        option GPT_OSTM_RAM_MIRROR or
 **                        GPT_TAUDB_RAM_MIRROR or GPT_TAUJ_RAM_MIRROR is STD_ON
 **
 ** Global Variables     : Gpt_GblDriverStatus
 **
 ** Functions invoked    : Gpt_LLDriverHWCheckConsistency, Det_ReportError
 **
 ** Registers Used       : OSTMnCMP, OSTMnCTL,OSTMnTE,TAUBnBRS, TAUBnCDRm,
 **                        TAUBnCMORm, TAUBnCMURm,TAUBnRDC, TAUBnRDE,TAUBnRDM,
 **                        TAUBnRDS,TAUBnTOE,TAUBnTPS,TAUBnTE,TAUDnBRS,TAUJnTE
 **                        TAUDnCDRm,TAUDnRDC, TAUDnRDE, TAUDnRDM, TAUDnRDS,
 **                        TAUDnCMORm, TAUDnCMURm,TAUDnTOE,TAUDnTPS,TAUDnTE,
 **                        TAUJnRDE, TAUJnRDM, TAUJnBRS, TAUJnCMURm, TAUJnTPS,
 **                        TAUJnTOE, TAUJnCMORm, TAUJnCDRm
 **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0049 */
/* Implements GPT_ESDD_UD_139, GPT_ESDD_UD_140, GPT_ESDD_UD_141 */
#if ( (GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_134 */
/* Implements GPT_ESDD_UD_025, GPT_ESDD_UD_078 */
/* Implements EAAR_PN0034_FSR_0007 */
/* Qac Warning: START Msg(2:3227)-2 */
FUNC(Std_ReturnType, GPT_PUBLIC_CODE) Gpt_HWCheckConsistency(
    Gpt_HWConsistencyModeType HWConsistencyMode)
{
  /* END Msg(2:3227)-2 */
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  if (GPT_INITIALIZED != Gpt_GblDriverStatus)
  {

    /* Report a DET if driver is not initialised */
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_HW_CHECK_CONSISTENCY_SID, GPT_E_UNINIT);
#endif
    LddReturnValue = E_NOT_OK;

  }
  else if ((GPT_STATIC != HWConsistencyMode)
      && (GPT_DYNAMIC != HWConsistencyMode))
  {
    /* Report a DET if an invalid parameter value is passed to the function */
    /* Implements GPT175, GPT176 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_HW_CHECK_CONSISTENCY_SID, GPT_E_PARAM_VALUE);
#endif
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    LddReturnValue = Gpt_LLDriverHWCheckConsistency(HWConsistencyMode);
  }

  return LddReturnValue;
}

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of ((GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
                   (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE )|| \
                   (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))*/

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
