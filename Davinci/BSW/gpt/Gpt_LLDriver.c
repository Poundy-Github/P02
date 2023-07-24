/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Gpt_LLDriver.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Low level Driver code of the GPT Driver Component                          */
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
 * V1.0.1:  08-Dec-2015    : As per ARDAAGA-76 following changes has been done:
 *                           1. EcuM_CheckWakeup() is called inside Critical
 *                           Section protection.
 *                           2. Changed the register accessing. Used local
 *                           pointers to remove the repeated use of indexing
 *
 * V2.0.0:  27-Sep-2016    : Updated were done as part of several tickets:
 *                           1. ARDAABC-512 Only the output enable
 *                           bits(TOE registers) of the channels which are used
 *                           in the configuration are updated by Gpt_Init
 *                           function
 *                           2. ARDAABC-346 Add initialized for several
 *                           registers(RDE, RDS, RDM, RDC, CMUR) and re-arranged
 *                           several of compiler flags to avoid duplication.
 *                           3.ARDAABC-347 Removed extra check
 *                           (GPT_RESET_LONG_WORD == LulTimeOutCount) for
 *                           reporting DEM in in case of timeout.
 *                           4.ARDAABC-344 When disabling the notification
 *                           interrupt for the ONE_SHOT timer channel, the
 *                           interrupt request flag was not being cleared,
 *                           leading to an extra interrupt trigger.
 *                           Added interrupt request flag clear.
 *                           5.ARDAABC-751 Eliminated runtime conversion
 *                           (bitshift) of the wakeup source in the embedded
 *                           code.
 *                           6. ARDAABC-483 Gpt_Deinit and Gpt_Stop Timer where
 *                           not disabling interrupt for ONE_SHOT timers in case
 *                           a certain configuration was present.Change was done
 *                           that in case of ONE_SHOT timer the interrupt of
 *                           that channel shall be disabled all the time.
 *                           7. ARDAABC-518 Added a low-level interrupt handling
 *                           function and replaced code portion used to handle
 *                           interrupts with this function in several places.
 *                           8. ARDAABC-769 Added Write-Verify and Hardware
 *                           Consistency check for GPT registers.
 *                           Removed old registers readback implementation.
 *                           Replaced all register writes with macros which
 *                           perform the Write Verification or set the
 *                           corresponding RAM mirror of each register if
 *                           available.One new API was added
 *                           Gpt_LLDriverHWCheckConsistency for performing the
 *                           register consistency check.
 *                           9. ARDAABC-772 Wait loop was implemented for TE
 *                           registers update in all places where TT and TS
 *                           registers are written. An DEM error is reported if
 *                           TE register is not updated in the expected time.
 *
 * V2.1.0:  05-Oct-2016    : Fixed issue ARDAABC-876 regarding initialisation of
 *                           timer channels configured in a specific order.
 *                           Replaced some register channel loops with one loop
 *                           and  a switch in methods: Gpt_HW_Init,
 *                           Gpt_HW_DeInit,Gpt_LLDriverHWCheckConsistency.
 *
 * V2.2.0:  28-Oct-2016    : Based on ticket ARDAABC-875 updated the handling of
 *                           interrupts in GPT_HW_EnableInterrupt and
 *                           GPT_HW_DisableInterrupt by adding support for FE
 *                           level interrupts, used by OSTM1-OSTM4 timers. Added
 *                           GPT_HW_OSTM_FEINT timer type in all places where
 *                           GPT_HW_OSTM timer type was present.
 *
 * V2.3.0:  28-Oct-2016    : Based on ticket ARDAABC-865 changed used macro
 *                           in compile switch from GPT_HW_Deinit to avoid
 *                           compilation error.
 *
 * V2.4.0:  31-Sep-2016    : Remove old code related to Autosar version 3.2.2
 *                           and use GPT_AR_LOWER_VERSION to map Autosar version
 *                           4.0.3 and GPT_AR_HIGHER_VERSION to map Autosar
 *                           version 4.2.2 specific code
 *
 * V2.5.0:  15-Oct-2016    : Add several new functions for handling Predef
 *                           timers as part of ARDAABC-564:
 *                           1. Gpt_HW_GetPredefTimerValue for reading the
 *                           value of a Predef Timer
 *                           2.Gpt_HW_StartPredefTimer for starting the HW
 *                           channel of Predef timers
 *                           3.Gpt_HW_StopPredefTimer for stopping the HW
 *                           channel of Predef timers
 *                           4.Gpt_HW_PredefTimerCallbackNotification
 *                           notification in case of interrupt
 *
 * V2.5.1:  06-Dec-2016    : Added compile switch GPT_PREDEF_TIMER_ENABLED to
 *                           exclude from compilation Predef Timer related code
 *                           when function is disabled.
 *                           Several changes done on Gpt_HW_GetPredefTimerValue
 *                           in order to avoid overflow
 *
 * V2.5.2:  23-Dec-2016    : Update preprocessor condition for local variables
 *                           declaration in Gpt_HW_GetPredefTimerValue
 *
 * V2.5.3:  03-Feb-2017    : The access to RDE, RDS, RDM, RDC registers was
 *                           masked because these registers are shared between
 *                           different timer channels as part of ARDAABC-346.
 *
 * V2.5.4:  26-Jun-2017    : MISRA Justifications are added.
 *
 * V2.5.5:  07-Jul-2017    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-1883, support for
 *                              clearing WUF1 Factor flags added.
 *                           2. As part of JIRA ARDAABD-1516, Gpt_Hw_Init(),
 *                              Gpt_Hw_DeInit() APIs are modified to remove the
 *                              Critical section protection and
 *                              Gpt_HW_DisableInterrupt is updated with new
 *                              argument.
 *
 * V2.5.6:  18-Aug-2017    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-2305, Predef timer
 *                              macros updated to support all OSTM EI
 *                              interrupts.
 *                           2. Traceability added.
 *
 * V2.5.7:  21-Nov-2017    : Following changes are made:
 *                           1. As per ARDAABD-2425, QAC level 2 warning
 *                              Justification tags are added.
 *                           2. As part of JIRA ARDAABD-2472, SV mode writable
 *                              register access with SYNCP has been replaced
 *                              with RH850_SV_CLEAR_ICR_SYNCP.
 *                           3. As part of Jira #ARDAABD-2471,
 *                              naming convention for variables and macros
 *                              updated.
 *                           4. As per ARDAABD-2570, typo errors corrected.
 *                           5. MISRA tags corrected.
 *
 * V2.5.8:  18-Jun-2018    : Following changes were made:
 *                           1.As per merging activity #ARDAABD-3489,
 *                              a.Replaced all interrupt related IMR_OR and
 *                                IMR_AND operations with ICR register.
 *                              b.pImrIntrCntlAddress is removed from
 *                                STag_Gpt_ChannelConfigType for denying access
 *                                to IMR register.(Ref: ARDAABD-2158)
 *                              c.usImrMaskValue is renamed to usFeIntMaskValue
 *                                for updating FE Interrupt mask register.
 *                              d.As per ARDAABD-2461,'Iocommon_Defines.h' is
 *                                added.
 *                              e.MISRA tags updated.
 *                           2.Copyright information updated.
 *                           3.As per ARDAABD-3627, registers used in
 *                             functions were updated in function banner.
 *                           4.As per ARDAABD-3664, nested critical sections
 *                              were removed.
 *                           5.MISRA Justification messages added.
 *                           6. As per ARDAABD-3841, traceability updated.
 * 
 * V2.5.9:  27-July-2018    : Following changes are made:
 *                           1. As part of JIRA ARDAABD-3948, TAUB BRS
 *                              registers that do not exist are not accessed
 *                              in the function Gpt_HW_DeInit()
 *
 * V2.5.10: 30-Aug-2018     :Following changes are made:
 *                           1. As part of JIRA ARDAABD-3970, macros
 *                              GPT_FEINT_WRITE_OR were changed to
 *                              GPT_FEINT_WRITE_ONLY when writing register
 *                              GPT_FEINT_FACTOR_CLEAR_REGISTER.
 * V2.5.11: 09-Jul-2019     :As part of jira ticket ARDAABD-3664, following 
 *                           change are made:
 *                           1.Delete GPT_EXIT_CRITICAL_SECTION in the 
 *                             middle of a function Gpt_HW_StartTimer.
 *                           2.Update the copyright from 2018 to 2019.
 */
/******************************************************************************/
/*Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0056 */
/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

/* Included for module version information and other types declarations */
#include "Gpt.h"
/* Included for the Declarations of I/O Registers */
#include "Iocommon_Defines.h"
/* Included for Header file inclusion */
#include "Gpt_LLDriver.h"
/* Included for declaration of the Callback functions Configuration */
/* Implements GPT_ESDD_UD_115 */
#include "Gpt_PBTypes.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Gpt.h"
#endif

#include "Gpt_RegWrite.h"

/* Included for declaration of the function Dem_ReportErrorStatus() */
/* Implements GPT172, GPT179 */
#include "Dem.h"
/* Included for the inclusion of macro defined for OS SFR Registers */
#include "rh850_Types.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
/* AUTOSAR Release version information */
#define GPT_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
    GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_LLDRIVER_C_SW_MAJOR_VERSION  GPT_SW_MAJOR_VERSION_VALUE
#define GPT_LLDRIVER_C_SW_MINOR_VERSION  GPT_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
#if (GPT_LLDRIVER_AR_RELEASE_MAJOR_VERSION != \
    GPT_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (GPT_LLDRIVER_AR_RELEASE_MINOR_VERSION != \
    GPT_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (GPT_LLDRIVER_AR_RELEASE_REVISION_VERSION != \
    GPT_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Gpt_LLDriver.c : Mismatch in Release Patch Version"
#endif

#if (GPT_LLDRIVER_SW_MAJOR_VERSION != GPT_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Gpt_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (GPT_LLDRIVER_SW_MINOR_VERSION != GPT_LLDRIVER_C_SW_MINOR_VERSION)
#error "Gpt_LLDriver.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                         Global Data                                       **
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
/* 2. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Rule          : None                                                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:2016)-2 and               */
/*                 END Msg(2:2016)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning :                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-3 and                           */
/*                 END Msg(2:2814)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.Also this is not a MISRA violation             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning  START Msg(2:2824)-4 and              */
/*                 END Msg(2:2824)-4  tags in the code.                       */
/******************************************************************************/
/* 5. QAC WARNING:                                                            */
/* Message       : Msg(2:3892) Suffixed integer constant implicitly converted */
/*                 to different integer type.                                 */
/* Rule          : MISRA-C:2004 Rule NA                                       */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-5 and END Msg(2:3892)-5 tags    */
/*                 in the code.                                               */
/******************************************************************************/
/* 6. QAC Warning :                                                           */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-6 and                           */
/*                 END Msg(2:3227)-6 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) [I] Increment or decrement operation performed on */
/*                 pointer.                                                   */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Increment operator is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-1 and                           */
/*                 END Msg(4:0489)-1 tags in the code.                        */
/******************************************************************************/

/* 2.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983)This assignment is redundant. The value of this    */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This initialization is required as there is a scope for    */
/*                 this variable to be used with initialization  in some      */
/*                 scenarios of Precompile option                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-2 and                           */
/*                 END Msg(4:2983)-2 tags in the code.                        */
/******************************************************************************/

/* 3.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-3 and                           */
/*                 END Msg(4:0491)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2877) This loop will only be executed once and so the   */
/*                 loop mechanism is redundant.                               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-4 and                           */
/*                 END Msg(4:2877)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation appears to be redundant because a  */
/*                 given constant value can always be used instead.           */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-5 and                           */
/*                 END Msg(4:2984)-5 tags in the code.                        */
/******************************************************************************/

/* 6.  MISRA C RULE VIOLATION:                                                */
/* Message       : Msg(4:2880) This code is unreachable.                      */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : This part is unreachable for the configuration used, code  */
/*                 will be reachable based on the configuration.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-6 and                           */
/*                 END Msg(4:2880)-6 tags in the code.                        */
/******************************************************************************/

/* 7.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982)This assignment is redundant. The value of this    */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This initialization is required as there is a scope for    */
/*                 this variable to not be initialized in some                */
/*                 scenarios of Precompile option                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-7 and                           */
/*                 END Msg(4:2982)-7 tags in the code.                        */
/******************************************************************************/

/* 8.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0303)[I] Cast between a pointer to volatile object and  */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : This cast is necessary for memory mapped register access   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-8 and                           */
/*                 END Msg(4:0303)-8 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 ** Function Name         : Gpt_HW_Init
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function sets the clock pre scalar, timer mode.
 **                         This function also disables the interrupts and
 **                         resets the interrupt request pending flags.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : None
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Parameter      : None
 **
 ** Pre-condition         : None
 **
 ** Global Variables used : Gpt_GpChannelConfig, Gpt_GpTAUUnitConfig,
 **                         Gpt_GpChannelRamData
 **
 ** Functions invoked     : Gpt_HW_DisableInterrupt
 **
 ** Registers Used        : TAUDnCMORm, TAUBnCMORm, TAUDnTPS, TAUDnCDRm,
 **                         TAUBnTPS, TAUDnBRS, TAUJnTPS, TAUJnBRS,TAUJnCMORm,
 **                         ICTAUDmIn, ICTAUBmIn, ICTAUJmIn, ICOSTMn, OSTMnCMP,
 **                         TAUBnCDRm, TAUJnCDRm, TAUDnTOE, TAUBnTOE, TAUJnTOE,
 **                         TAUBnRDC, TAUBnRDC, TAUBnRDM, TAUBnRDS,TAUBnRDE,
 **                         TAUDnRDC,TAUDnRDE, TAUDnRDM, TAUDnRDS, TAUJnRDM,
 **                         TAUJnRDE,TAUBnCMURm,TAUDnCMURm,TAUJnCMURm,OSTMnCTL
 **
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087 */
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_096 */
/* Implements GPT_ESDD_UD_051 */
/* Implements GPT_ESDD_UD_107, GPT_ESDD_UD_108, GPT_ESDD_UD_109 */
/* Implements GPT_ESDD_UD_110 */
/* Implements GPT_ESDD_UD_036, GPT_ESDD_UD_037, GPT_ESDD_UD_038 */
/* Implements GPT_ESDD_UD_041, GPT_ESDD_UD_042, GPT_ESDD_UD_043 */
/* Implements GPT_ESDD_UD_044, GPT_ESDD_UD_045, GPT_ESDD_UD_046 */
/* Implements GPT_ESDD_UD_047, GPT_ESDD_UD_049, GPT_ESDD_UD_039 */
/* Implements GPT_ESDD_UD_130 */
/* Implements GPT068, SWS_Gpt_00068, EAAR_PN0080_FR_0014, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FR_0025, EAAR_PN0080_FR_0041 */
FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Init(void)
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpChannelConfig;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
#if ((GPT_TAUD_UNIT_CONFIG == STD_ON) || (GPT_TAUB_UNIT_CONFIG == STD_ON))
#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif /* End of (GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* End of (GPT_TAUD_UNIT_CONFIG == STD_ON) ||
                 (GPT_TAUB_UNIT_CONFIG == STD_ON) */
#endif /* End of (GPT_TAUD_UNIT_USED == STD_ON) ||
                 (GPT_TAUB_UNIT_USED == STD_ON) */

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAU Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_CONST)
  LpTAUUnitConfig;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Offset Index of OSTM Unit control registers */
  uint8 LucOSTMUnitIndex;
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

#if ((GPT_TAUD_UNIT_CONFIG == STD_ON) || (GPT_TAUB_UNIT_CONFIG == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit os control registers */
  P2VAR(volatile TAUDBOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitOsReg;
#endif

#if (GPT_TAUJ_UNIT_CONFIG == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitOsReg;

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
#endif
  uint8 LucCount;
  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Gpt_GpChannelConfig;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_CHANNELS_CONFIG; LucCount++)
  {
    /* Start of Block - 1 */
    /* QAC Warning START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    if (
        (GPT_HW_OSTM == (LpChannelConfig[LucCount].uiTimerType))||
        (GPT_HW_OSTM_FEINT == (LpChannelConfig[LucCount].uiTimerType))
       )
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      LucOSTMUnitIndex = LpChannelConfig[LucCount].ucBaseCtlRegIndex;
      /* END Msg(4:0491)-3 */
      LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LucOSTMUnitIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Reset the CMP register of the configured channel */
      GPT_OSTM_WRITE_REG_AND_MIRROR(&LpOSTMUnitReg->ulCMP,
          GPT_OSTM_CMP_RESET_VAL,
          &Gpt_GaaGptOSTMRegMirror[LucOSTMUnitIndex].ulCMP)
      /* END Msg(2:2814)-3 */
      GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&LpOSTMUnitReg->ulCMP,
          GPT_OSTM_CMP_RESET_VAL, GPT_OSTM_CMP_32BIT_MASK, GPT_HWINIT_API_ID)
    }
    else
    {
      /* No action required */
    }

  } /* End of Block - 1 */
#endif

#if (GPT_TAUD_UNIT_USED == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUD_UNITS_CONFIG; LucCount++)
  /* END Msg(4:2877)-4 */
  {
  /* Start of Block - 2 */
#if (GPT_TAUD_UNIT_CONFIG == STD_ON)
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Initialize the pointer to os register base address */
    LpTAUDBUnitOsReg = Gpt_GaaTAUDBOsReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
    /* Load the reset register values - assurance against pre-init usage  */
    /* Implements EAAR_PN0080_FR_0026 */
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDE, LpTAUDBUnitOsReg->usRDE &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    /* END Msg(2:2814)-3 */
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDE,
        GPT_TAUDB_RDE_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDS, LpTAUDBUnitOsReg->usRDS &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDS,
        GPT_TAUDB_RDS_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDM, LpTAUDBUnitOsReg->usRDM &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDM,
        GPT_TAUDB_RDM_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDC, LpTAUDBUnitOsReg->usRDC &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDC,
        GPT_TAUDB_RDC_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Initialize the pointer to os register base address */
    /* Check for Pre scalar setting by the GPT module for TAUDn Unit */
    if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
      /* Load the configured pre scalar value */
      GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usTPS, LpTAUUnitConfig->usPrescaler)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usTPS,
          LpTAUUnitConfig->usPrescaler,
          GPT_TAU_TPS_16BIT_MASK, GPT_HWINIT_API_ID)
      /* Load the configured baud rate value */
      GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->ucBRS,
          LpTAUUnitConfig->ucBaudRate)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->ucBRS,
          LpTAUUnitConfig->ucBaudRate,
          GPT_TAU_BRS_8BIT_MASK, GPT_HWINIT_API_ID)
    } /* End of LpTAUUnitConfig->blConfigurePrescaler == GPT_TRUE*/
    else
    {
      /* No action required */
    }
#endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
    LpTAUDBUnitUserReg =
    Gpt_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
    /* QAC Warning: START Msg(2:2814)-3 */
    /* enables the independent channel output mode */
    /* Implements EAAR_PN0080_FR_0026, EAAR_PN0080_FR_0061 */
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTOE,
        LpTAUDBUnitUserReg->usTOE | LpTAUUnitConfig->usTAUChannelMaskValue)
    /* END Msg(2:2814)-3 */
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitUserReg->usTOE,
        LpTAUUnitConfig->usTAUChannelMaskValue,
        LpTAUUnitConfig->usTAUChannelMaskValue,
        GPT_HWINIT_API_ID)
#endif /*((GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* End of (GPT_TAUD_UNIT_CONFIG == STD_ON) */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer for the next TAUD Unit */
    LpTAUUnitConfig++;
    /* END Msg (4:0489)-1 */
    } /* End of Block - 2 */
#endif /* End of (GPT_TAUD_UNIT_USED == STD_ON) */

#if ((GPT_TAUB_UNIT_USED == STD_ON))
    /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUB_UNITS_CONFIG; LucCount++)
  /* END Msg(4:2877)-4 */
  {
    /* Start of Block - 3 */
#if (GPT_TAUB_UNIT_CONFIG == STD_ON)
    /* Initialize the pointer to os register base address */
    LpTAUDBUnitOsReg = Gpt_GaaTAUDBOsReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
    /* Load the reset register values - assurance against pre-init usage  */
    /* Implements EAAR_PN0080_FR_0026 */
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDE, LpTAUDBUnitOsReg->usRDE &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDE,
        GPT_TAUDB_RDE_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDS, LpTAUDBUnitOsReg->usRDS &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDS,
        GPT_TAUDB_RDS_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDM, LpTAUDBUnitOsReg->usRDM &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDM,
        GPT_TAUDB_RDM_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usRDC, LpTAUDBUnitOsReg->usRDC &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usRDC,
        GPT_TAUDB_RDC_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)

    /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Check for Pre scalar setting by the GPT module for TAUBn Unit */
    if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
      /* Load the configured pre scalar value */
      GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usTPS, LpTAUUnitConfig->usPrescaler)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usTPS,
          LpTAUUnitConfig->usPrescaler,
          GPT_TAU_TPS_16BIT_MASK, GPT_HWINIT_API_ID)
    } /* End of LpTAUUnitConfig->blConfigurePrescaler == GPT_TRUE */
    else
    {
      /* No action required */
    }
#endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
    LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
    /* QAC Warning: START Msg(2:2814)-3 */
    /* enables the independent channel output mode */
    /* Implements EAAR_PN0080_FR_0026, EAAR_PN0080_FR_0061*/
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTOE,
        LpTAUDBUnitUserReg->usTOE | LpTAUUnitConfig->usTAUChannelMaskValue)
    /* END Msg(2:2814)-3 */
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitUserReg->usTOE,
        LpTAUUnitConfig->usTAUChannelMaskValue,
        LpTAUUnitConfig->usTAUChannelMaskValue,
        GPT_HWINIT_API_ID)
#endif /* (GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* (GPT_TAUB_UNIT_CONFIG == STD_ON) */
    /* Increment the pointer for the next TAUB Unit */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-2 */
    /* Increment the pointer for the next TAUB Unit */
    LpTAUUnitConfig++;
    /* END Msg(4:2983)-2 */
    /* END Msg(4:0489)-1 */
  } /* End of Block - 3 */
#endif /* * End of (GPT_TAUB_UNIT_USED == STD_ON) */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(4:2877)-4  */
  {
    /* Start of Block - 4 */
#if (GPT_TAUJ_UNIT_CONFIG == STD_ON)
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Initialize the pointer to OS register base address */
    LpTAUJUnitOsReg = Gpt_GaaTAUJOsReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
    /* END Msg(2:2814)-3 */
    /* Load the reset register values - assurance against pre-init usage  */
    /* Implements EAAR_PN0080_FR_0026*/
    /* QAC Warning: START Msg(2:2814)-3 */
    GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->ucRDE, LpTAUJUnitOsReg->ucRDE &
        ((uint8)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    /* END Msg(2:2814)-3 */
    GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->ucRDE,
        GPT_RESET_TAU_RDE_BYTE,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->ucRDM, LpTAUJUnitOsReg->ucRDM &
        ((uint8)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->ucRDM,
        GPT_RESET_TAU_RDM_BYTE,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWINIT_API_ID)
    /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Check for Pre-scalar setting by the GPT module for TAUJn Unit */
    if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
      /* Load the configured pre-scalar value */
      GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->usTPS, LpTAUUnitConfig->usPrescaler)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->usTPS,
          LpTAUUnitConfig->usPrescaler,
          GPT_TAU_TPS_16BIT_MASK, GPT_HWINIT_API_ID)
      /* Load the configured baud rate value */
      GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->ucBRS,
          LpTAUUnitConfig->ucBaudRate)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->ucBRS,
          LpTAUUnitConfig->ucBaudRate,
          GPT_TAU_BRS_8BIT_MASK, GPT_HWINIT_API_ID)
    } /* End of LpTAUUnitConfig->blConfigurePrescaler == GPT_TRUE */
    else
    {
      /* No action required */
    }
#endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)*/

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
    LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
    /* enables the independent channel output mode */
    /* Implements EAAR_PN0080_FR_0026, EAAR_PN0080_FR_0061*/
    GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTOE,
        (uint8)(((uint16)LpTAUJUnitUserReg->ucTOE) |
            LpTAUUnitConfig->usTAUChannelMaskValue))
    GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitUserReg->ucTOE,
        (uint8)(LpTAUUnitConfig->usTAUChannelMaskValue),
        (uint8)(LpTAUUnitConfig->usTAUChannelMaskValue),
        GPT_HWINIT_API_ID)
#endif /*(GPT_TIMER_OUTPUT_ENABLE == STD_ON) */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to the next TAUJ Unit */
    /* MISRA Violation: START Msg(4:2983)-2 */
    LpTAUUnitConfig++;
    /* END Msg(4:2983)-2 */
    /* END Msg(4:0489)-1 */
#endif/* End of (GPT_TAUJ_UNIT_CONFIG == STD_ON)*/
  } /* End of Block - 4 */
#endif /* End of  (GPT_TAUJ_UNIT_USED == STD_ON) */
  /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_CHANNELS_CONFIG; LucCount++)
  /* END Msg(4:2877)-4 */
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Start of Block - 5 */
    switch (LpChannelConfig->uiTimerType)
    {
      /* Start of Bock - 6 */
      /* END Msg(2:2814)-3 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
    case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
    case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
      LpTAUDBChannelRegs = Gpt_GaaTAUDBChReg_BaseAddress
      [LpChannelConfig->ucBaseCtlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Set the mode of TAUD/TAUB timer by writing to CMOR register */
      GPT_WRITE_REG_ONLY(&LpTAUDBChannelRegs->usCMOR,
          LpChannelConfig->usModeSettingsMask)
      /* END Msg(2:2814)-3 */
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelRegs->usCMOR,
          LpChannelConfig->usModeSettingsMask, GPT_TAU_CMOR_16BIT_MASK,
          GPT_HWINIT_API_ID)

      /* Disable the interrupt on the channel. Has to happen even if the
       * notification support and wakeup support is off in order to account for
       * one-shot timers.Protects against previous usage of interrupts.
       */
      /* Implements GPT107, SWS_Gpt_00107 */
      Gpt_HW_DisableInterrupt(LucCount, GPT_EXCLUDE_CRITICAL_SECTION);
      /* Check the Notification is configured for the current channel */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* QAC Warning START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Set the Notification status as GPT_FALSE */
      Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the Wakeup status to the Channel */
      Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the timer status to the Channel */
      Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
      /* END Msg(4:0491)-3 */
      /* Load the initial value into the channel mode user register */
      GPT_WRITE_REG_ONLY(&LpTAUDBChannelRegs->ucCMUR, GPT_RESET_TAU_CMUR_BYTE)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelRegs->ucCMUR,
          GPT_RESET_TAU_CMUR_BYTE, GPT_TAU_CMUR_MASK, GPT_HWINIT_API_ID)
      /* Load the initial value into the Data register */
      GPT_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelRegs->usCDR,
          GPT_TAUDB_CDR_RESET_VAL,
          &Gpt_GaaGptTAUDBChRegMirror[LpChannelConfig->ucBaseCtlRegIndex].usCDR)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelRegs->usCDR,
          GPT_TAUDB_CDR_RESET_VAL, GPT_TAU_CDR_16BIT_MASK, GPT_HWINIT_API_ID)

      break;
#endif /* End of((GPT_TAUD_UNIT_USED == STD_ON)||
               (GPT_TAUB_UNIT_USED == STD_ON)) */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    case GPT_HW_TAUJ:
      /* QAC Warning: START Msg(2:2814)-3 */
      LpTAUJChannelReg = Gpt_GaaTAUJChReg_BaseAddress
      [LpChannelConfig->ucBaseCtlRegIndex];
      /* Set the mode of TAUJ timer by writing to CMOR register */
      GPT_WRITE_REG_ONLY(&LpTAUJChannelReg->usCMOR,
          LpChannelConfig->usModeSettingsMask)
      /* END Msg(2:2814)-3 */
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->usCMOR,
          LpChannelConfig->usModeSettingsMask, GPT_TAU_CMOR_16BIT_MASK,
          GPT_HWINIT_API_ID)
      /* Load the initial value into the channel mode user register */
      GPT_WRITE_REG_ONLY(&LpTAUJChannelReg->ucCMUR, GPT_RESET_TAU_CMUR_BYTE)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ucCMUR,
          GPT_RESET_TAU_CMUR_BYTE, GPT_TAU_CMUR_MASK, GPT_HWINIT_API_ID)
      /* Reset the CDRm register of the configured channel */
      GPT_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ulCDR,
          GPT_TAUJ_CDR_RESET_VAL,
          &Gpt_GaaGptTAUJChRegMirror[LpChannelConfig->ucBaseCtlRegIndex].ulCDR)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ulCDR,
          GPT_TAUJ_CDR_RESET_VAL, GPT_TAU_CDR_32BIT_MASK, GPT_HWINIT_API_ID)

      /* Disable the interrupt on the channel. Has to happen even if the
       * notification support and wakeup support is off in order to account for
       * one-shot timers.Protects against previous usage of interrupts.
       */
      /* Implements GPT107, GPT258, SWS_Gpt_00107, SWS_Gpt_00258 */
      Gpt_HW_DisableInterrupt(LucCount, GPT_EXCLUDE_CRITICAL_SECTION);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* QAC Warning START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Set the Notification status as GPT_FALSE */
      Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the Wakeup status to the Channel */
      Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the timer status to the Channel */
      Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
      /* END Msg(4:0491)-3 */
      break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
    case GPT_HW_OSTM:
    case GPT_HW_OSTM_FEINT:

        LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress
        [LpChannelConfig->ucBaseCtlRegIndex];
        /* Set the mode of OSTM timer by writing to CTL register */
        /* Implements EAAR_PN0080_FR_0021 */
        GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucCTL, GPT_CH_MODE_OSTM_CONTINUOUS)
        GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&LpOSTMUnitReg->ucCTL,
            GPT_CH_MODE_OSTM_CONTINUOUS, GPT_OSTM_CTL_MASK, GPT_HWINIT_API_ID)

        /* Disable the interrupt on the channel. Has to happen even if the
         * for notification support and wakeup support is off in order to
         * account one-shot timers.Protects against previous usage of
         * interrupts.
         */
        /* Implements GPT107, SWS_Gpt_00107 */
        Gpt_HW_DisableInterrupt((Gpt_ChannelType) LucCount,
                                                GPT_EXCLUDE_CRITICAL_SECTION);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        /* MISRA Violation: START Msg(4:0491)-3 */
        /* Set the Notification status as GPT_FALSE */
        Gpt_GpChannelRamData[LucCount].uiNotifyStatus =
                                                    GPT_NOTIFICATION_DISABLED;
        /* END Msg(4:0491)-3 */
#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        /* MISRA Violation: START Msg(4:0491)-3 */
        /* Assign the Wakeup status to the Channel */
        Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
        GPT_WAKEUP_NOTIFICATION_DISABLED;
        /* END Msg(4:0491)-3 */
#endif
        /* MISRA Violation: START Msg(4:0491)-3 */
        /* Assign the timer status to the Channel */
        Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
        /* END Msg(4:0491)-3 */
        break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
        /* QAC Warning: START Msg(2:2016)-2 */
    default:
        break;
    } /* End of Bock - 6 */
    /* END Msg(2:2016)-2 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-2 */
    /* Increment the pointer to the next channel */
    LpChannelConfig++;
    /* END Msg(4:2983)-2 */
    /* END Msg(4:0489)-1 */

  } /* End of Block - 5 */
  /* If Predef Timer function is enabled ,initialise specific registers of
   * the used OSTM HW channel also
   */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)

  /* Reset the CMP register of the configured channel */
  GPT_OSTM_WRITE_REG_AND_MIRROR(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ulCMP,
      GPT_OSTM_CMP_RESET_VAL,
      &Gpt_GstGptPredefTimerOSTMRegMirror.ulCMP)
  GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ulCMP,
      GPT_OSTM_CMP_RESET_VAL, GPT_OSTM_CMP_32BIT_MASK, GPT_HWINIT_API_ID)

  /* Set the mode of OSTM timer by writing to CTL register */
  /* Implements EAAR_PN0080_FR_0021 */
  GPT_WRITE_REG_ONLY(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ucCTL,
      GPT_CH_MODE_OSTM_CONTINUOUS)
  GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ucCTL,
      GPT_CH_MODE_OSTM_CONTINUOUS, GPT_OSTM_CTL_MASK, GPT_HWINIT_API_ID)
#endif
#endif /* End of (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION) */

  /* Initialise with default values also RAM mirrors for dynamic
   * registers which are not initialised in Gpt_HW_Init
   */
  /* MISRA Violation: START Msg(4:2877)-4 */
#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUB_UNIT_USED == STD_ON) \
   || (GPT_TAUD_UNIT_USED == STD_ON)))
  for (LucCount = GPT_ZERO; LucCount < GPT_NUM_OF_TAUDB_REG; LucCount++)
  /* END Msg(4:2877)-4 */
  {
    Gpt_GaaGptTAUDBUserRegMirror[LucCount].usTE =
    Gpt_GaaTAUDBUserReg_BaseAddress[LucCount]->usTE;
  }
#endif

#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_TAUJ_UNIT_USED == STD_ON))
  /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_NUM_OF_TAUJ_REG; LucCount++)
  /* END Msg(4:2877)-4 */
  {
    Gpt_GaaGptTAUJUserRegMirror[LucCount].ucTE =
    Gpt_GaaTAUJUserReg_BaseAddress[LucCount]->ucTE;
  }
#endif

#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_OSTM_UNIT_USED == STD_ON))
  for (LucCount = GPT_ZERO; LucCount < GPT_NUM_OF_OSTM_REG; LucCount++)
  {
    Gpt_GaaGptOSTMRegMirror[LucCount].ucTE =
    Gpt_GaaOSTMReg_BaseAddress[LucCount]->ucTE;
  }
#endif

} /* End of API Gpt_HW_Init */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_HW_DeInit
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function resets all the HW Registers.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Non Reentrant
 **
 ** Input Parameters      : None
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
 **                         Gpt_GpTAUUnitConfig
 **
 ** Functions invoked     : Dem_ReportErrorStatus, Gpt_HW_DisableInterrupt
 **
 ** Registers used        : TAUDnTT, TAUBnTT, TAUJnTT, TAUDBnTE, TAUJnTE,
 **                         ICTAUDnIm, TAUDnCMORm, TAUBnCMORm, TAUJnCMORm,
 **                         TAUDnCDRm, TAUBnCDRm, TAUJnCDRm, OSTMnTT, OSTMnCTL,
 **                         ICTAUBmIn, ICTAUJnIm, ICOSTMn, OSTMnCMP, TAUDnTOE,
 **                         TAUBnTOE, TAUJnTOE, TAUDnTPS, TAUBnTPS, TAUJnTPS,
 **                         TAUDnBRS, TAUJnBRS, TAUBnBRS, OSTMnTE
 **
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT162, GPT308, SWS_Gpt_00162, SWS_Gpt_00308 */
/* Implements GPT_ESDD_UD_097, EAAR_PN0080_FR_0014 */
/* Implements GPT_ESDD_UD_107, GPT_ESDD_UD_108, GPT_ESDD_UD_109 */
/* Implements GPT_ESDD_UD_110 */
/* Implements GPT_ESDD_UD_036, GPT_ESDD_UD_037, GPT_ESDD_UD_038 */
/* Implements GPT_ESDD_UD_041, GPT_ESDD_UD_042, GPT_ESDD_UD_043 */
/* Implements GPT_ESDD_UD_044, GPT_ESDD_UD_045, GPT_ESDD_UD_046 */
/* Implements GPT_ESDD_UD_047, GPT_ESDD_UD_049, GPT_ESDD_UD_039 */
/* Implements EAAR_PN0034_FR_0058 */
FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DeInit(void)
{
  /* Pointer pointing to the channel structure */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannelConfig;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB/TAUJ Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpTAUUnitConfig;
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
#if ((GPT_TAUD_UNIT_CONFIG == STD_ON) || (GPT_TAUB_UNIT_CONFIG == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit os control registers */
  P2VAR(volatile TAUDBOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitOsReg;
#endif

#if (GPT_TAUJ_UNIT_CONFIG == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitOsReg;
#endif
#endif

  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /*local variable to take channel mask*/
  uint16 LusTAUChannelMaskValue;
#endif

#if ((GPT_TAUJ_UNIT_USED == STD_ON)  || (GPT_OSTM_UNIT_USED == STD_ON))
  uint8 LucTAUChannelMaskValue;
#endif

  uint8 LucCount;

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Gpt_GpChannelConfig;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) || \
    (GPT_TAUJ_UNIT_USED == STD_ON))
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;
#endif

  /* Check for TAUD/TAUB Units Used */
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  { /* Start of Block - 1 */
    /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
#if ((GPT_TAUD_UNIT_CONFIG == STD_ON) || (GPT_TAUB_UNIT_CONFIG == STD_ON))
    /* Check for Pre scalar setting by the GPT module for TAUDn Unit */
    if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
      /* Initialize the pointer to os register base address */
      LpTAUDBUnitOsReg = Gpt_GaaTAUDBOsReg_BaseAddress
      [LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
      /* Reset the pre scalar value (Reset value is 0xFFFF) */
      GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usTPS, GPT_TAUD_TPS_SET_VAL)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usTPS,
          GPT_TAUD_TPS_SET_VAL, GPT_TAU_TPS_16BIT_MASK, GPT_HWDEINIT_API_ID)
      /* Check for TAUDn Unit Used */
#if (GPT_TAUD_UNIT_CONFIG == STD_ON)
      if(LucCount < GPT_TOTAL_TAUD_UNITS_CONFIG)
      {
        /* Reset the baud rate value */
        GPT_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->ucBRS, GPT_RESET_TAU_BRS_BYTE)
        /* QAC Warning: START Msg(2:3892)-5 */
        GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->ucBRS,
            GPT_RESET_TAU_BRS_BYTE, GPT_TAU_BRS_8BIT_MASK, GPT_HWDEINIT_API_ID)
        /* END Msg(2:3892)-5 */
      }
      else
      {
        /* No action required */
      }
#endif
    } /* End of LpTAUUnitConfig->blConfigurePrescaler == GPT_TRUE*/
    else
    {
      /* No action required */
    }

#endif /* End of ((GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) && \
                      (GPT_TAUD_UNIT_CONFIG == STD_ON)) */
#endif

    /* Update pointer for the user base address of the TAUD/TAUB unit
     * registers*/
    LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
    /* Reset the TOE register of the configured channel */
    /* Implements EAAR_PN0080_FR_0026, EAAR_PN0080_FR_0061*/
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTOE, LpTAUDBUnitUserReg->usTOE &
        ((uint16)(~(LpTAUUnitConfig->usTAUChannelMaskValue))))
    GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitUserReg->usTOE,
        GPT_TAUDB_TOE_RESET_VAL,
        LpTAUUnitConfig->usTAUChannelMaskValue,
        GPT_HWDEINIT_API_ID)
#endif

    /* Set the configured channel bits to disable the count operation */
    /* Take the channel mask to a local variable */
    /* Implements EAAR_PN0080_FR_0026*/
    LusTAUChannelMaskValue = LpTAUUnitConfig->usTAUChannelMaskValue;
    GPT_WRITE_TAUDB_MIRROR_ONLY(
        &Gpt_GaaGptTAUDBUserRegMirror
        [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex].usTE,
        LpTAUDBUnitUserReg->usTE & (uint16)(~LusTAUChannelMaskValue))
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT, LusTAUChannelMaskValue)

    /* TE register is updated after one clock cycle.
     * A Wait loop implementations is required instead of WRITE-VERIFY*/
    /* Implements GPT_ESDD_UD_132 */
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_WORD !=
            (uint16)((uint16)LpTAUDBUnitUserReg->usTE & LusTAUChannelMaskValue))
    )
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (GPT_TAUDB_TE_RESET_VAL !=
        (uint16)((LpTAUDBUnitUserReg->usTE) & LusTAUChannelMaskValue))
    {
      /* Implements GPT177, GPT_ESDD_UD_074, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:2983)-2 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to the next TAUD/TAUB unit */
    LpTAUUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-2 */

  } /* End of Block - 1 */
#endif

  /* Check for TAUJ Units Used */
#if (GPT_TAUJ_UNIT_USED == STD_ON)

  /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(4:2877)-4 */
  { /* Start of Block - 3 */
    /* Implements EAAR_PN0080_FR_0030 */
#if ((GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) && \
    (GPT_TAUJ_UNIT_CONFIG == STD_ON))
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check for Pre-scalar setting by the GPT module for TAUJn Unit */
    if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
      /* END Msg(2:2814)-3 */
      /* Initialize the pointer to OS register base address */
      LpTAUJUnitOsReg = Gpt_GaaTAUJOsReg_BaseAddress
      [LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Reset the pre-scalar value (Reset value is 0xFFFF) */
      GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->usTPS, GPT_TAUJ_TPS_SET_VAL)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->usTPS,
          GPT_TAUJ_TPS_SET_VAL, GPT_TAU_TPS_16BIT_MASK, GPT_HWDEINIT_API_ID)
      /* END Msg(2:2814)-3 */
      /* Reset the baud rate value */
      GPT_WRITE_REG_ONLY(&LpTAUJUnitOsReg->ucBRS, GPT_RESET_TAU_BRS_BYTE)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->ucBRS,
          GPT_RESET_TAU_BRS_BYTE,
          GPT_TAU_BRS_8BIT_MASK, GPT_HWDEINIT_API_ID)
    } /* End of LpTAUUnitConfig->blConfigurePrescaler == GPT_TRUE */
    else
    {
      /* No action required */
    }
#endif /* End of ((GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) &&
                                 (GPT_TAUJ_UNIT_CONFIG == STD_ON)) */

    LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress
    [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Reset the TOE register of the configured channel */
    /* Implements EAAR_PN0080_FR_0026, EAAR_PN0080_FR_0061*/
    GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTOE,
        ((LpTAUJUnitUserReg->ucTOE) &
            ((uint8)(~LpTAUUnitConfig->usTAUChannelMaskValue))))
    /* END Msg(2:2814)-3 */
    GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitUserReg->ucTOE,
        GPT_RESET_TAU_TOE_BYTE,
        LpTAUUnitConfig->usTAUChannelMaskValue, GPT_HWDEINIT_API_ID)
#endif

    /* Set the configured channel bits to disable the count operation */
    /* Take the channel mask to a local var */
    /* Implements EAAR_PN0080_FR_0026*/
    LucTAUChannelMaskValue = (uint8)LpTAUUnitConfig->usTAUChannelMaskValue;
    GPT_WRITE_TAUJ_MIRROR_ONLY(&Gpt_GaaGptTAUJUserRegMirror
        [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex].ucTE,
        LpTAUJUnitUserReg->ucTE & (uint8)(~(LucTAUChannelMaskValue)))
    /* QAC Warning: START Msg(2:2814)-3 */
    GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT, (uint8)LucTAUChannelMaskValue)
    /* END Msg(2:2814)-3 */
    /* TE register is updated after one clock cycle. An Wait loop implementation
     * is required instead of WriteVerify*/
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_BYTE !=
            (uint8)(LpTAUJUnitUserReg->ucTE & LucTAUChannelMaskValue)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (GPT_RESET_TAU_TE_BYTE != ((uint8)((LpTAUJUnitUserReg->ucTE) &
                LucTAUChannelMaskValue)))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-2 */
    /* Increment the pointer to next TAUJ unit */
    LpTAUUnitConfig++;
    /* END Msg(4:2983)-2 */
    /* END Msg(4:0489)-1 */
  } /* End of Block - 3 */

#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    /* MISRA Violation: START Msg(4:2877)-4 */
  for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_CHANNELS_CONFIG; LucCount++)
    /* END Msg(4:2877)-4 */
  { /* Start of Block - 3 */
    /* QAC Warning: START Msg(2:2814)-3 */
    switch (LpChannelConfig->uiTimerType)
    { /* Start of Bock - 4 */
      /* END Msg(2:2814)-3 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
    case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
    case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
      LpTAUDBChannelRegs = Gpt_GaaTAUDBChReg_BaseAddress
      [LpChannelConfig->ucBaseCtlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Reset the CMORm register of the configured channel */
      GPT_WRITE_REG_ONLY(&LpTAUDBChannelRegs->usCMOR, GPT_TAUDB_CMOR_RESET_VAL)
      /* END Msg(2:2814)-3 */
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelRegs->usCMOR,
         GPT_TAUDB_CMOR_RESET_VAL, GPT_TAU_CMOR_16BIT_MASK, GPT_HWDEINIT_API_ID)
      /* Reset the CDRm register of the configured channel */
      GPT_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelRegs->usCDR,
         GPT_TAUDB_CDR_RESET_VAL,
         &Gpt_GaaGptTAUDBChRegMirror[LpChannelConfig->ucBaseCtlRegIndex].usCDR)
      GPT_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelRegs->usCDR,
         GPT_TAUDB_CDR_RESET_VAL, GPT_TAU_CDR_16BIT_MASK, GPT_HWDEINIT_API_ID)

      /* In case of ONE SHOT timer interrupt is enabled by default in order to
       * be able to stop the timer when the target timer is reached. Because of
       * this the interrupt has to disabled when Stop Timer is called
       * independent of the fact that the user configures a user notification
       * callback.
       */
      /* Implements GPT105, SWS_Gpt_00105 */
      Gpt_HW_DisableInterrupt(LucCount, GPT_EXCLUDE_CRITICAL_SECTION);

      /* MISRA Violation: START Msg(4:0491)-3 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* QAC Warning START Msg(2:2824)-4 */
      /* Set the Notification status as GPT_FALSE */
      Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0491)-3 */
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the Wakeup status to the Channel */
      Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the timer status to the Channel */
      Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
      /* END Msg(4:0491)-3 */

      break;
#endif /* End of((GPT_TAUD_UNIT_USED == STD_ON)||
                       (GPT_TAUB_UNIT_USED == STD_ON)) */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    case GPT_HW_TAUJ:

      LpTAUJChannelReg = Gpt_GaaTAUJChReg_BaseAddress
      [LpChannelConfig->ucBaseCtlRegIndex];
      /* Reset the CMORm register of the configured channel */
      /* QAC Warning: START Msg(2:2814)-3 */
      GPT_WRITE_REG_ONLY(&LpTAUJChannelReg->usCMOR, GPT_TAUJ_CMOR_RESET_VAL)
      /* END Msg(2:2814)-3 */
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->usCMOR,
          GPT_TAUJ_CMOR_RESET_VAL, GPT_TAU_CMOR_16BIT_MASK, GPT_HWDEINIT_API_ID)

      /* Reset the CDRm register of the configured channel */
      GPT_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ulCDR,
          GPT_TAUJ_CDR_RESET_VAL,
          &Gpt_GaaGptTAUJChRegMirror[LpChannelConfig->ucBaseCtlRegIndex].ulCDR)
      GPT_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ulCDR,
          GPT_TAUJ_CDR_RESET_VAL, GPT_TAU_CDR_32BIT_MASK, GPT_HWDEINIT_API_ID)

      /* In case of ONE SHOT timer interrupt is enabled by default in order to
       * be able to stop the timer when the target timer is reached. Because of
       * this the interrupt has to disabled when Stop Timer is called
       * independent of the fact that the user configures a user notification
       * callback.
       */
      /* Implements GPT105, SWS_Gpt_00105 */
      Gpt_HW_DisableInterrupt(LucCount, GPT_EXCLUDE_CRITICAL_SECTION);

      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* Set the Notification status as GPT_FALSE */
      Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the Wakeup status to the Channel */
      Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the timer status to the Channel */
      Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
      /* END Msg(4:0491)-3 */

      break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
    case GPT_HW_OSTM:
    case GPT_HW_OSTM_FEINT:

      LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress
      [LpChannelConfig->ucBaseCtlRegIndex];
      /* Stop the timer OSTM */
      /* Take the channel mask to a local var */
      /* Implements EAAR_PN0080_FR_0026*/
      /* QAC Warning: START Msg(2:2814)-3 */
      LucTAUChannelMaskValue = GPT_OSTM_STOP_MASK;
      GPT_WRITE_OSTM_MIRROR_ONLY(
          &Gpt_GaaGptOSTMRegMirror[LpChannelConfig->ucBaseCtlRegIndex].ucTE,
          (LpOSTMUnitReg->ucTE & (uint8)(~LucTAUChannelMaskValue)))
      /* END Msg(2:2814)-3 */
      GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTT, LucTAUChannelMaskValue)

      /* TE register is updated after one clock cycle. An Wait loop
       * implementation is required instead of WriteVerify */
      /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
      LulTimeOutCount = GPT_TIMEOUT_COUNT;
      /* MISRA Violation: START Msg(4:2877)-4 */
      while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
          (GPT_RESET_BYTE != (uint8)(LpOSTMUnitReg->ucTE &
                  LucTAUChannelMaskValue)))
      /* END Msg(4:2877)-4 */
      {
        /* MISRA Violation: START Msg(4:2984)-5 */
        /* MISRA Violation: START Msg(4:2880)-6 */
        LulTimeOutCount--;
        /* END Msg(4:2880)-6 */
        /* END Msg(4:2984)-5 */
      }
      if (GPT_RESET_OSTM_TE_BYTE != (uint8)((LpOSTMUnitReg->ucTE) &
              LucTAUChannelMaskValue))
      /* In case the register is not updated in the expected time,
       * report a DEM error */
      {
        /* Implements GPT177, EAAR_PN0034_FR_0084 */
        Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
            ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
      }
      else
      {
        /* No action required */
      }

      /* Reset the CMP register of the configured channel */
      GPT_OSTM_WRITE_REG_AND_MIRROR(&LpOSTMUnitReg->ulCMP,
          GPT_OSTM_CMP_RESET_VAL,
          &Gpt_GaaGptOSTMRegMirror[LpChannelConfig->ucBaseCtlRegIndex].ulCMP)
      GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&LpOSTMUnitReg->ulCMP,
          GPT_OSTM_CMP_RESET_VAL, GPT_OSTM_CMP_32BIT_MASK, GPT_HWDEINIT_API_ID)

      GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucCTL, GPT_RESET_OSTM_CTL_BYTE)
      GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&LpOSTMUnitReg->ucCTL,
          GPT_RESET_OSTM_CTL_BYTE, GPT_OSTM_CTL_MASK, GPT_HWDEINIT_API_ID)

      /* In case of ONE SHOT timer interrupt is enabled by default in order to
       * be able to stop the timer when the target timer is reached.
       * Because of this the interrupt has to disabled when Stop Timer
       * is called independent of the fact that the user configures a user
       * notification callback.
       */
      /* Implements GPT105, SWS_Gpt_00105 */
      Gpt_HW_DisableInterrupt(LucCount, GPT_EXCLUDE_CRITICAL_SECTION);

      /* MISRA Violation: START Msg(4:0491)-3 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* Set the Notification status as GPT_FALSE */
      Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the Wakeup status to the Channel */
      Gpt_GpChannelRamData[LucCount].uiWakeupStatus =
      GPT_WAKEUP_NOTIFICATION_DISABLED;
      /* END Msg(4:0491)-3 */
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Assign the timer status to the Channel */
      Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTSTARTED;
      /* END Msg(4:0491)-3 */

      break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    /* QAC Warning: START Msg(2:2016)-2 */
    default:
      break;
    } /* End of Bock - 4 */
    /* END Msg(2:2016)-2 */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-2 */
    /* Increment the pointer to the next channel */
    LpChannelConfig++;
    /* END Msg(4:2983)-2 */
    /* END Msg(4:0489)-1 */

  } /* End of Block - 3 */
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
  /* Reset the CMP register of the Predef Timer OSTM channel */
  GPT_OSTM_WRITE_REG_AND_MIRROR(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ulCMP,
      GPT_OSTM_CMP_RESET_VAL,
      &Gpt_GstGptPredefTimerOSTMRegMirror.ulCMP)
  GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ulCMP,
      GPT_OSTM_CMP_RESET_VAL, GPT_OSTM_CMP_32BIT_MASK, GPT_HWDEINIT_API_ID)

  GPT_WRITE_REG_ONLY(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ucCTL,
      GPT_RESET_OSTM_CTL_BYTE)
  GPT_OSTM_CHECK_WRITE_VERIFY_INIT(&Gpt_GpOSTMRegPredefTimer_BaseAddress->ucCTL,
      GPT_RESET_OSTM_CTL_BYTE, GPT_OSTM_CTL_MASK, GPT_HWDEINIT_API_ID)
#endif
#endif /* End of (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION) */
} /* End of API Gpt_HW_DeInit */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_HW_GetTimeElapsed
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function returns the time elapsed for a channel
 **                         by accessing the respective timer registers.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : LddTimeElapsed
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData
 **
 ** Functions invoked     : GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers used        : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm,TAUDnCNTm,
 **                         TAUBnCNTm,OSTMnCMP,OSTMnCNT,TAUJnCNTm,
 **                         ICOSTMn,ICTAUDmIn,ICTAUBmIn,ICTAUJmIn
 **
 ******************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_098,  */
/* Implements GPT113, SWS_Gpt_00113 */
FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeElapsed(
    const Gpt_ChannelType channel)
{
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamData, AUTOMATIC, GPT_CONFIG_DATA)LpRamData;
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannel;
  /* Return Value */
  Gpt_ValueType LddTimeElapsed;
  uint8 LucTimerType;

  LddTimeElapsed = (Gpt_ValueType)GPT_TIMER_INIT_VAL_ZERO;

  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  /* END Msg(2:2814)-3 */
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpRamData = &Gpt_GpChannelRamData[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* Implements GPT295, SWS_Gpt_00295 */
  /* QAC Warning: START Msg(2:2814)-3 */
  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)
  {
  /* END Msg(2:2814)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area  */
    GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
    switch (LucTimerType)
    { /* Start of Bock - 12 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
    case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
    case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
      LpTAUDBChannelRegs = Gpt_GaaTAUDBChReg_BaseAddress
      [LpChannel->ucBaseCtlRegIndex];
      /* Implements GPT361 */
      /* Implements SWS_Gpt_00361 */
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function.
       */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddTimeElapsed = ( ((Gpt_ValueType)LpTAUDBChannelRegs->usCDR -
              (Gpt_ValueType)LpTAUDBChannelRegs->usCNT) +
          (Gpt_ValueType)GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* Channel is configured in one-shot mode in state expired, function
       * shall return target time in AUTOSAR higher version */
      if (NULL_PTR != LpChannel->pIntrCntlAddress)
      {
        if ((GPT_CHECK_INTR_REQUEST_MASK ==
                /*Increment the pointer to next byte address of
                 *Interrupt control register */
                (uint16)(*(LpChannel->pIntrCntlAddress) &
                    GPT_CHECK_INTR_REQUEST_MASK))
            /* Implements GPT010 */
            /* Implements SWS_Gpt_00010 */
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /*
           * Returns target time value when channel is expired in
           * one-shot mode and it is incremented by one to compensate the
           * decrement done in start timer function.
           */
          LddTimeElapsed = ((Gpt_ValueType)LpTAUDBChannelRegs->usCDR +
              (Gpt_ValueType)GPT_ONE);
        }
        else if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus)
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /*
           * Returns target time value when channel is expired in
           * one-shot mode and it is incremented by one to compensate the
           * decrement done in start timer function.
           */
          LddTimeElapsed = (Gpt_ValueType)
          ((Gpt_ValueType)LpTAUDBChannelRegs->usCDR +
              (Gpt_ValueType)GPT_ONE);
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
      break;
#endif
      /*
       * End of((GPT_TAUD_UNIT_USED == STD_ON)||
       * (GPT_TAUB_UNIT_USED == STD_ON))
       */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    case GPT_HW_TAUJ:
      LpTAUJChannelReg = Gpt_GaaTAUJChReg_BaseAddress
      [LpChannel->ucBaseCtlRegIndex];
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function.
       */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddTimeElapsed = ((LpTAUJChannelReg->ulCDR -
              LpTAUJChannelReg->ulCNT) + (uint32)GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* Channel is configured in one-shot mode in state expired function
       * shall return target time*/
      if (NULL_PTR != LpChannel->pIntrCntlAddress)
      {
        if ((GPT_CHECK_INTR_REQUEST_MASK ==
                /* Increment the pointer to next byte address of
                 * Interrupt control register */
                (uint16)(*(LpChannel->pIntrCntlAddress) &
                    GPT_CHECK_INTR_REQUEST_MASK))
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /*
           * Returns target time value when channel is expired in
           * one-shot mode and it is incremented by one to
           * compensate the decrement done in start timer function.
           */
          LddTimeElapsed = (LpTAUJChannelReg->ulCDR + (uint32) GPT_ONE);
        }
        /* Implements GPT299 */
        /* Implements SWS_Gpt_00299 */
        else if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus)
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /*
           * Returns target time value when channel is expired in
           * one-shot mode and it is incremented by one to
           * compensate the decrement done in start timer function.
           */
          /* Implements GPT297 */
          /* Implements SWS_Gpt_00297 */
          LddTimeElapsed = (LpTAUJChannelReg->ulCDR + (uint32) GPT_ONE);
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
      break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
    case GPT_HW_OSTM:
    case GPT_HW_OSTM_FEINT:
      LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function. */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddTimeElapsed = ((LpOSTMUnitReg->ulCMP -
              LpOSTMUnitReg->ulCNT) + (uint32) GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* In case of one shot timer check for timer expired, or interrupt
       * pending flags to see if timer has elapsed in the meantime.
       * For GPT_HW_OSTM_FEINT timer type, pending interrupt flag check is not
       * needed because interrupt is not masked, so if the interrupt occurs then
       * the channel status will change to EXPIRED
       */

      if (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode)
      {
        if ((GPT_HW_OSTM == LucTimerType) &&
            (NULL_PTR != LpChannel->pIntrCntlAddress))
        {
          if ((GPT_CHECK_INTR_REQUEST_MASK ==
                  (uint16)(*(LpChannel->pIntrCntlAddress) &
                      GPT_CHECK_INTR_REQUEST_MASK))
          )
          {
            /*
             * Returns target time value when channel is expired in
             * one-shot mode and it is incremented by one to
             * compensate the decrement done in start timer function.
             */
            LddTimeElapsed = (LpOSTMUnitReg->ulCMP + (uint32) GPT_ONE);
          }
          else
          {
            /* No pending interrupt */
          }
        }
        else
        {
          /* timer used FE interrupt or Null pIntrCntlAddress */
        }
        /* Implements GPT299 */
        /* Implements SWS_Gpt_00299 */
        if (GPT_CH_EXPIRED == LpRamData->ucChannelStatus)
        {
          /*
           * Returns target time value when channel is expired in
           * one-shot mode and it is incremented by one to
           * compensate the decrement done in start timer function.
           */
          /* Implements GPT297 */
          /* Implements SWS_Gpt_00297 */
          LddTimeElapsed = (LpOSTMUnitReg->ulCMP + (uint32) GPT_ONE);
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
      break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    /* QAC Warning: START Msg(2:2016)-2 */
    default:
      break;
    } /* End of Bock - 12 */
    /* END Msg(2:2016)-2 */
  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
  #endif
  } /* End of LpRamData->ucChannelStatus != GPT_CH_NOTSTARTED */
  else
  {
    /* No action required */
  }
  return(LddTimeElapsed);
} /* End of API Gpt_HW_GetTimeElapsed */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/*******************************************************************************
 ** Function Name         : Gpt_HW_GetTimeRemaining
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function returns the time remaining for
 **                         the channel's next time-out by
 **                         accessing the respective timer registers.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : LddTimeRemaining
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
 **                         Gpt_GpTAUUnitConfig
 **
 ** Functions invoked     : GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers used        : TAUDnCNTm, TAUBnCNTm, TAUJnCNTm, TAUJnTT, TAUBnTT,
 **                         TAUDnTT,OSTMnTT, OSTMnTE, OSTMnCNT,TAUBnTE,TAUDnTE,
 **                         TAUJnTE,ICTAUDmIn,ICTAUBmIn,ICTAUJmIn,ICOSTMn
 **
 ******************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_099 */
/* Implements GPT303, GPT303, SWS_Gpt_00303, SWS_Gpt_00114*/
FUNC (Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeRemaining(
    const Gpt_ChannelType channel)
{
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Offset index of the TAUD registers */
  uint8 LucTAUDBUnitUserIndex;
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Offset index of the TAUJ registers */
  uint8 LucTAUJUnitUserIndex;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

#if ((GPT_TAUJ_UNIT_USED == STD_ON)  || (GPT_OSTM_UNIT_USED == STD_ON))
  uint8 LucTAUChannelMaskValue;
#endif

  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamData, AUTOMATIC, GPT_CONFIG_DATA)LpRamData;
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannel;
  Gpt_ValueType LddTimeRemaining;
  uint8 LucTimerType;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /*local variable to take channel mask*/
  uint16 LusTAUChannelMaskValue;
#endif

  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

  /* Initialize Return Value to zero */
  LddTimeRemaining = (Gpt_ValueType) GPT_TIMER_INIT_VAL_ZERO;
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  /* END Msg(2:2814)-3 */
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpRamData = &Gpt_GpChannelRamData[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* Implements GPT301 */
  /* Implements SWS_Gpt_00301 */
  /* QAC Warning: START Msg(2:2814)-3 */
  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)
  {
    /* END Msg(2:2814)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
    switch (LucTimerType)
    { /* Start of Block - 1 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
    case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
    case GPT_HW_TAUB:
#endif
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
      LpTAUDBChannelRegs = Gpt_GaaTAUDBChReg_BaseAddress
      [LpChannel->ucBaseCtlRegIndex]
      /* Implements GPT083 */;
      /* Implements SWS_Gpt_00083 */
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function. */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddTimeRemaining = ((Gpt_ValueType)LpTAUDBChannelRegs->usCNT +
          (Gpt_ValueType)GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* Implements GPT305 */
      /* Implements SWS_Gpt_00305, EAAR_PN0080_FR_0018 */
      /* Channel is expired and is configured for one-shot mode will return
       * zero value */
      if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus) &&
          (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
      {
        /* Return ZERO */
        LddTimeRemaining = (Gpt_ValueType) GPT_RET_VAL_ZERO;
      }
      else
      {
        /* No action required */
      }

      /* GPT channel in one-shot mode shall return a value of 0 if timer
       * expires */
      if (NULL_PTR != LpChannel->pIntrCntlAddress)
      {
        if ((GPT_CHECK_INTR_REQUEST_MASK ==
                /* Increment the pointer to next byte address of
                 * Interrupt control register */
                (uint16)(*(LpChannel->pIntrCntlAddress) &
                    GPT_CHECK_INTR_REQUEST_MASK))
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /* Return ZERO */
          LddTimeRemaining = (Gpt_ValueType) GPT_RET_VAL_ZERO;

          /* Initialize pointer to the base address of the current timer
           * user control registers */
          /* QAC Warning START Msg(2:2824)-4 */
          /* MISRA Violation: START Msg(4:0491)-3 */
          LucTAUDBUnitUserIndex = Gpt_GpTAUUnitConfig
          [LpChannel->ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;
          /* END Msg(4:0491)-3 */
          /* END Msg(2:2824)-4 */
          LpTAUDBUnitUserReg =
          Gpt_GaaTAUDBUserReg_BaseAddress[LucTAUDBUnitUserIndex];
          /* Take the channel mask to a local var */
          LusTAUChannelMaskValue = LpChannel->usChannelMask;
          /* Stop the timer TAUD/TAUB */
          /* QAC Warning: START Msg(2:2814)-3 */
          GPT_WRITE_TAUDB_MIRROR_ONLY(&Gpt_GaaGptTAUDBUserRegMirror
              [LucTAUDBUnitUserIndex].usTE,
              LpTAUDBUnitUserReg->usTE & (uint16)(~LusTAUChannelMaskValue))
          /* END Msg(2:2814)-3 */
          GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
              LusTAUChannelMaskValue)

          /* TE register is updated after one clock cycle.
           * A Wait loop implementations is required instead of WRITE-VERIFY*/
          /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
          LulTimeOutCount = GPT_TIMEOUT_COUNT;
          /* MISRA Violation: START Msg(4:2877)-4 */
          while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
              (GPT_RESET_WORD != (uint16)((uint16)LpTAUDBUnitUserReg->usTE &
                      LusTAUChannelMaskValue)))
          /* END Msg(4:2877)-4 */
          {
            /* MISRA Violation: START Msg(4:2880)-6 */
            /* MISRA Violation: START Msg(4:2984)-5 */
            LulTimeOutCount--;
            /* END Msg(4:2880)-6 */
            /* END Msg(4:2984)-5 */
          }
          /* In case the register is not updated in the expected time,
           * report and DEM error */
          if (GPT_TAUDB_TE_RESET_VAL != (uint16)((LpTAUDBUnitUserReg->usTE) &
                  LusTAUChannelMaskValue))
          {
            /* Implements GPT177, EAAR_PN0034_FR_0084 */
            Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
                ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
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
      }
      else
      {
        /* No action required */
      }
      break;
#endif
      /* End of
       * ((GPT_TAUD_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON))
       */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    case GPT_HW_TAUJ:

      LpTAUJChannelReg = Gpt_GaaTAUJChReg_BaseAddress
      [LpChannel->ucBaseCtlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function. */
      LddTimeRemaining = (LpTAUJChannelReg->ulCNT +(uint32) GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* Channel is expired and is configured for one-shot mode will return
       * zero value */
      /* Implements EAAR_PN0080_FR_0018 */
      if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus) &&
          (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
      {
        /* Return ZERO */
        LddTimeRemaining =(Gpt_ValueType) GPT_RET_VAL_ZERO;
      }
      else
      {
        /* No action required */
      }

      /* GPT channel in one-shot mode shall return a value of 0 if timer
       * expires */
      if (NULL_PTR != LpChannel->pIntrCntlAddress)
      {
        if ((GPT_CHECK_INTR_REQUEST_MASK ==
                /* Increment the pointer to next byte address of
                 * Interrupt control register */
                (uint16) (*(LpChannel->pIntrCntlAddress) &
                    GPT_CHECK_INTR_REQUEST_MASK))
            && (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
        {
          /* Return ZERO */
          LddTimeRemaining =(Gpt_ValueType) GPT_RET_VAL_ZERO;
          /* QAC Warning START Msg(2:2824)-4 */
          /* MISRA Violation: START Msg(4:0491)-3 */
          /* Initialize pointer to the base address of the current timer
           * user control registers */
          LucTAUJUnitUserIndex =
          Gpt_GpTAUUnitConfig[LpChannel->
          ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;
          /* END Msg(4:0491)-3 */
          /* END Msg(2:2824)-4 */
          LpTAUJUnitUserReg =
             Gpt_GaaTAUJUserReg_BaseAddress[LucTAUJUnitUserIndex];
          /* Take the channel mask to a local var */
          LucTAUChannelMaskValue = (uint8)LpChannel->usChannelMask;
          /* QAC Warning: START Msg(2:2814)-3 */
          /* Stop the timer TAUJ */
          GPT_WRITE_TAUJ_MIRROR_ONLY(&Gpt_GaaGptTAUJUserRegMirror
              [LucTAUJUnitUserIndex].ucTE,
              LpTAUJUnitUserReg->ucTE & (uint8)(~LucTAUChannelMaskValue))
          GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT, LucTAUChannelMaskValue)
          /* END Msg(2:2814)-3 */
          /* TE register is updated after one clock cycle.
           * A Wait loop implementation is required instead of WriteVerify*/
          /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
          LulTimeOutCount = GPT_TIMEOUT_COUNT;
          /* MISRA Violation: START Msg(4:2877)-4 */
          while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
              (GPT_RESET_BYTE != (uint8)(LpTAUJUnitUserReg->ucTE &
                      LucTAUChannelMaskValue)))
          /* END Msg(4:2877)-4 */
          {
            /* MISRA Violation: START Msg(4:2984)-5 */
            /* MISRA Violation: START Msg(4:2880)-6 */
            LulTimeOutCount--;
            /* END Msg(4:2880)-6 */
            /* END Msg(4:2984)-5 */
          }
          /* In case the register is not updated in the expected time,
           * report and DEM error */
          if (GPT_RESET_TAU_TE_BYTE != (uint8)((LpTAUJUnitUserReg->ucTE) &
                  LucTAUChannelMaskValue))
          {
            /* Implements GPT177, EAAR_PN0034_FR_0084 */
            Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
                ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
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
      }
      else
      {
        /* No action required */
      }
      break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
    case GPT_HW_OSTM:
    case GPT_HW_OSTM_FEINT:
      LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
      /* Assign the final return value and it is incremented by one to
       * compensate the decrement done in start timer function. */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddTimeRemaining = (LpOSTMUnitReg->ulCNT + (uint32)GPT_ONE);
      /* END Msg(2:2814)-3 */
      /* Channel is expired and is configured for one-shot mode will return
       * zero value */
      /* Implements EAAR_PN0080_FR_0018 */
      if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus) &&
          (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode))
      {
        /* Return ZERO */
        LddTimeRemaining =(Gpt_ValueType) GPT_RET_VAL_ZERO;
      }
      else
      {
        /* No action required */
      }

      /* GPT channel in one-shot mode shall return a value of 0 if timer
       * expires, check for pending EI or FE interrupt of OSTM channel */
      if ((GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode) &&
          (GPT_HW_OSTM == LucTimerType) &&
          (NULL_PTR != LpChannel->pIntrCntlAddress) &&
          ((GPT_CHECK_INTR_REQUEST_MASK ==
             (uint16)(*(LpChannel->pIntrCntlAddress) &
                 GPT_CHECK_INTR_REQUEST_MASK)
            ))
          )
      {
        /* Return ZERO */
        LddTimeRemaining =(Gpt_ValueType) GPT_RET_VAL_ZERO;

        /* Initialize pointer to the base address of the
         * current timer user control registers */
        LpOSTMUnitReg =
           Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
        /* Take the channel mask to a local var */
        LucTAUChannelMaskValue = GPT_OSTM_STOP_MASK;
        /* Stop the timer OSTM */
        GPT_WRITE_OSTM_MIRROR_ONLY(&Gpt_GaaGptOSTMRegMirror
            [LpChannel->ucBaseCtlRegIndex].ucTE,
            (LpOSTMUnitReg->ucTE & (uint8)(~LucTAUChannelMaskValue)))
        /* QAC Warning: START Msg(2:2814)-3 */
        GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTT, LucTAUChannelMaskValue)
        /* END Msg(2:2814)-3 */
        /* TE register is updated after one clock cycle.
         * An Wait loop implementation is required instead of WriteVerify*/
        /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
        LulTimeOutCount = GPT_TIMEOUT_COUNT;
        /* MISRA Violation: START Msg(4:2877)-4 */
        while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
            (GPT_RESET_BYTE != (uint8)(LpOSTMUnitReg->ucTE &
                    LucTAUChannelMaskValue)))
        /* END Msg(4:2877)-4 */
        {
          /* MISRA Violation: START Msg(4:2984)-5 */
          /* MISRA Violation: START Msg(4:2880)-6 */
          LulTimeOutCount--;
          /* END Msg(4:2880)-6 */
          /* END Msg(4:2984)-5 */
        }
        if (GPT_RESET_OSTM_TE_BYTE != (uint8)((LpOSTMUnitReg->ucTE) &
                LucTAUChannelMaskValue))
        /* In case the register is not updated in the expected time,
         * report and DEM error */
        {
          /* Implements GPT177, EAAR_PN0034_FR_0084 */
          Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
              ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
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
      break;
#endif /* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    /* QAC Warning: START Msg(2:2016)-2 */
    default:
      break;

    } /* End of Block - 1 */
    /* END Msg(2:2016)-2 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
  } /* End of LpRamData->ucChannelStatus != GPT_CH_NOTSTARTED */
  else
  {
    /* No action required */
  }
  return(LddTimeRemaining);
} /* End of API Gpt_HW_GetTimeRemaining */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

#endif /* End of (GPT_TIME_REMAINING_API == STD_ON) */

/*******************************************************************************
 ** Function Name         : Gpt_HW_StartTimer
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function starts the timer channel by loading
 **                         the compare registers and enabling the clock.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel, value
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
 **                         Gpt_GpTAUUnitConfig
 **
 ** Functions invoked     : Gpt_HW_DisableInterrupt, GPT_EXIT_CRITICAL_SECTION
 **                         GPT_ENTER_CRITICAL_SECTION, Gpt_HW_EnableInterrupt
 **
 **Registers used         : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm, OSTMnCMP,
 **                         ICTAUDmIn, ICTAUBmIn, ICTAUJmIn, ICOSTMn,
 **                         TAUDnTS, TAUBnTS, TAUJnTS, OSTMnTS,OSTMnTE,
 **                         TAUBnTE,TAUDnTE,TAUJnTE
 **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_100, EAAR_PN0080_FR_0027, EAAR_PN0080_FR_0028 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StartTimer(const Gpt_ChannelType channel,
    const Gpt_ValueType value)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannel;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Offset index of the TAUD/TAUB registers */
  uint8 LucTAUDBUnitUserIndex;
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Offset index of the TAUJ registers */
  uint8 LucTAUJUnitUserIndex;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamData, AUTOMATIC, GPT_CONFIG_DATA)LpRamData;

#if ((GPT_OSTM_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON))
  uint8 LucTAUChannelMaskValue;
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /*local variable to take channel mask*/
  uint16 LusTAUChannelMaskValue;
#endif
  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

  uint8 LucTimerType;
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel configure parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  /* END Msg(2:2814)-3 */
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpRamData = &Gpt_GpChannelRamData[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* Timer channel configured for One-shot mode and no call back function
   * configured will stop after 1conversion implicitly without having to invoke
   * stop conversion. */
  /* QAC Warning: START Msg(2:2814)-3 */
  if ((GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode)
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      || ((GPT_MODE_NORMAL == Gpt_GucDriverMode) && (GPT_NOTIFICATION_ENABLED
              == LpRamData->uiNotifyStatus))
  /* END Msg(2:2814)-3 */
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
      || ((GPT_MODE_SLEEP == Gpt_GucDriverMode) &&
          (GPT_WAKEUP_NOTIFICATION_ENABLED == LpRamData->uiWakeupStatus))
#endif
  )
  {
    Gpt_HW_EnableInterrupt(channel);
  }
  else
  {
    Gpt_HW_DisableInterrupt(channel, GPT_INCLUDE_CRITICAL_SECTION);
  }
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
  switch (LucTimerType)
  { /* Start of Block - 1 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
  case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
  case GPT_HW_TAUB:
#endif


#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
    /* QAC Warning START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LucTAUDBUnitUserIndex =
    Gpt_GpTAUUnitConfig[LpChannel->
    ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;

    LpTAUDBChannelRegs = Gpt_GaaTAUDBChReg_BaseAddress
    [LpChannel->ucBaseCtlRegIndex];
    /* Implements GPT186, GPT274, GPT329 */
    /* Implements GPT274 */
    /* Implements SWS_Gpt_00186, SWS_Gpt_00329, SWS_Gpt_00274 */
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress[LucTAUDBUnitUserIndex];
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Load the value into the Data register */
    GPT_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelRegs->usCDR,
        (uint16)(value - GPT_ONE),
        &Gpt_GaaGptTAUDBChRegMirror[LpChannel->ucBaseCtlRegIndex].usCDR)
    /* END Msg(2:2814)-3 */
    GPT_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBChannelRegs->usCDR,
       (uint16)(value - GPT_ONE), GPT_TAU_CDR_16BIT_MASK, GPT_STARTTIMER_API_ID)

    /* Take the channel mask to a local var */
    LusTAUChannelMaskValue = LpChannel->usChannelMask;
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Start the timer TAUD/TAUB */
    GPT_WRITE_TAUDB_MIRROR_ONLY(&Gpt_GaaGptTAUDBUserRegMirror
        [LucTAUDBUnitUserIndex].usTE,
        LpTAUDBUnitUserReg->usTE | LusTAUChannelMaskValue)
    /* END Msg(2:2814)-3 */
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS, LusTAUChannelMaskValue)
    /* TE register is updated after one clock cycle.
     * A Wait loop implementations is required instead of WRITE-VERIFY*/
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
            (LusTAUChannelMaskValue !=(LpTAUDBUnitUserReg->usTE &
              LusTAUChannelMaskValue)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (LusTAUChannelMaskValue != ((LpTAUDBUnitUserReg->usTE) &
            LusTAUChannelMaskValue))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif /* End of
    ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))*/

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  case GPT_HW_TAUJ:
    /* QAC Warning START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LucTAUJUnitUserIndex =
    Gpt_GpTAUUnitConfig[LpChannel->
    ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    LpTAUJChannelReg =
       Gpt_GaaTAUJChReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
    LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress[LucTAUJUnitUserIndex];
    /* QAC Warning: START Msg(2:3892)-5 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Load the value into the Data register */
    GPT_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ulCDR,
        (uint32)(value - GPT_ONE),
        &Gpt_GaaGptTAUJChRegMirror[LpChannel->ucBaseCtlRegIndex].ulCDR)
    /* END Msg(2:2814)-3 */
    /* END Msg(2:3892)-5 */
    GPT_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJChannelReg->ulCDR,
       (uint32)(value - GPT_ONE), GPT_TAU_CDR_32BIT_MASK, GPT_STARTTIMER_API_ID)

    /* Take the channel mask to a local var */
    LucTAUChannelMaskValue = (uint8)LpChannel->usChannelMask;
/* QAC Warning: START Msg(2:2814)-3 */
    /* Start the timer TAUJ */
    GPT_WRITE_TAUJ_MIRROR_ONLY(&Gpt_GaaGptTAUJUserRegMirror
        [LucTAUJUnitUserIndex].ucTE,
        (LpTAUJUnitUserReg->ucTE | LucTAUChannelMaskValue))
    GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTS, LucTAUChannelMaskValue)
    /* END Msg(2:2814)-3 */
    /* TE register is updated after one clock cycle.
     * A Wait loop implementation is required instead of WriteVerify*/
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
      (LucTAUChannelMaskValue !=
            (LpTAUJUnitUserReg->ucTE & LucTAUChannelMaskValue)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (LucTAUChannelMaskValue != ((LpTAUJUnitUserReg->ucTE) &
            LucTAUChannelMaskValue))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
  case GPT_HW_OSTM:
  case GPT_HW_OSTM_FEINT:
    LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Load the value into the Compare register */
    GPT_OSTM_WRITE_REG_AND_MIRROR(&LpOSTMUnitReg->ulCMP,
        (uint32)(value - GPT_ONE),
        &Gpt_GaaGptOSTMRegMirror[LpChannel->ucBaseCtlRegIndex].ulCMP)
    /* END Msg(2:2814)-3 */
    GPT_OSTM_CHECK_WRITE_VERIFY_RUNTIME(&LpOSTMUnitReg->ulCMP,
        (uint32)(value - GPT_ONE),
        GPT_OSTM_CMP_32BIT_MASK, GPT_STARTTIMER_API_ID)
    /* Take the channel mask to a local var */
    LucTAUChannelMaskValue = GPT_OSTM_START_MASK;
    /* Start the timer OSTM */
    GPT_WRITE_OSTM_MIRROR_ONLY(&Gpt_GaaGptOSTMRegMirror
        [LpChannel->ucBaseCtlRegIndex].ucTE,
        LpOSTMUnitReg->ucTE | LucTAUChannelMaskValue)
    GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTS, LucTAUChannelMaskValue)
    /* TE register is updated after one clock cycle.
     * A Wait loop implementation is required instead of WriteVerify*/
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
        (LucTAUChannelMaskValue !=
            (LpOSTMUnitReg->ucTE & LucTAUChannelMaskValue)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    if (LucTAUChannelMaskValue != ((LpOSTMUnitReg->ucTE) &
            LucTAUChannelMaskValue))
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
  /* QAC Warning: START Msg(2:2016)-2 */
  default:
    break;
  } /* End of Block - 14 */
  /* END Msg(2:2016)-2 */
  /* Implements GPT364 */
  /* Implements SWS_Gpt_00364 */
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_RUNNING;
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif

} /* End of API Gpt_HW_StartTimer */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_HW_StopTimer
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.
 **                         This function stops the channel
 **                         by disabling the interrupt and/or the clock.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
 **                         Gpt_GpTAUUnitConfig
 **
 ** Functions invoked     : Gpt_HW_DisableInterrupt, GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION, Dem_ReportErrorStatus
 **
 ** Registers used        : TAUDnTT, TAUBnTT,TAUJnTT, OSTMnTT,TAUDBnTE,TAUJnTE,
 **                         OSTMnTE,ICOSTMn,ICTAUJmIn,ICTAUBmIn,ICTAUDmIn
 **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_101 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StopTimer(const Gpt_ChannelType channel)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannel;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Offset index of the TAUD registers */
  uint8 LucTAUDBUnitUserIndex;
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif
#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Offset index of the TAUJ registers */
  uint8 LucTAUJUnitUserIndex;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif
#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamData, AUTOMATIC, GPT_CONFIG_DATA)LpRamData;

  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /*local variable to take channel mask*/
  uint16 LusChannelMask;
#endif

#if ((GPT_TAUJ_UNIT_USED == STD_ON)  || (GPT_OSTM_UNIT_USED == STD_ON))
  uint8 LucChannelMask;
#endif

  uint8 LucTimerType;
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  /* END Msg(2:2814)-3 */
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpRamData = &Gpt_GpChannelRamData[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif

  switch (LucTimerType)
  { /* Start of Block - 1 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
  case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
  case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
    /* QAC Warning START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LucTAUDBUnitUserIndex =
    Gpt_GpTAUUnitConfig[LpChannel->
    ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress[LucTAUDBUnitUserIndex];
    /* Take the channel mask to a local variable */
    LusChannelMask = LpChannel->usChannelMask;
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Stop the timer TAUD/TAUB */
    GPT_WRITE_TAUDB_MIRROR_ONLY(&Gpt_GaaGptTAUDBUserRegMirror
        [LucTAUDBUnitUserIndex].usTE, LpTAUDBUnitUserReg->usTE &
        (uint16)(~LusChannelMask))
    /* END Msg(2:2814)-3 */
    GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT, LusChannelMask)
    /* load loop count from configuration */
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_WORD !=
            (uint16)(LpTAUDBUnitUserReg->usTE & LusChannelMask)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (GPT_TAUDB_TE_RESET_VAL != (uint16)((LpTAUDBUnitUserReg->usTE) &
            LusChannelMask))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif
    /*
     * End of
     * ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )
     */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  case GPT_HW_TAUJ:
    /* QAC Warning START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LucTAUJUnitUserIndex =
    Gpt_GpTAUUnitConfig[LpChannel->
    ucTimerUnitIndex].ucTAUUnitUserCntlRegIndex;
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress[LucTAUJUnitUserIndex];
    /* Take the channel mask to a local var */
    LucChannelMask = (uint8)LpChannel->usChannelMask;
    /* Implements GPT013 */
    /* Implements SWS_Gpt_00013 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Stop the timer TAUJ */
    GPT_WRITE_TAUJ_MIRROR_ONLY(&Gpt_GaaGptTAUJUserRegMirror
        [LucTAUJUnitUserIndex].ucTE, (LpTAUJUnitUserReg->ucTE &
            (uint8)(~LucChannelMask)))
    GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT, LucChannelMask)
    /* END Msg(2:2814)-3 */
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    /* load loop count from configuration */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_BYTE !=
            (uint8)(LpTAUJUnitUserReg->ucTE & LucChannelMask)))
     /* END Msg(4:2877)-4 */
    {
      /* Decrement the loop count */
      /* MISRA Violation: START Msg(4:2880)-6 */
      /* MISRA Violation: START Msg(4:2984)-5 */
      LulTimeOutCount--;
      /* END Msg(4:2984)-5 */
      /* END Msg(4:2880)-6 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (GPT_RESET_TAU_TE_BYTE != (uint8)((LpTAUJUnitUserReg->ucTE) &
            LucChannelMask))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
  case GPT_HW_OSTM:
  case GPT_HW_OSTM_FEINT:
    LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
    /* Take the channel mask to a local variable */
    LucChannelMask = GPT_OSTM_STOP_MASK;
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Stop the timer OSTM */
    GPT_WRITE_OSTM_MIRROR_ONLY(&Gpt_GaaGptOSTMRegMirror
        [LpChannel->ucBaseCtlRegIndex].ucTE,
        (LpOSTMUnitReg->ucTE & (uint8)(~LucChannelMask)))
    /* END Msg(2:2814)-3 */
    GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTT, LucChannelMask)
    /* Load loop count from configuration */
    /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
    LulTimeOutCount = GPT_TIMEOUT_COUNT;
    /* MISRA Violation: START Msg(4:2877)-4 */
    while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_BYTE !=
            (uint8)(LpOSTMUnitReg->ucTE & LucChannelMask)))
    /* END Msg(4:2877)-4 */
    {
      /* MISRA Violation: START Msg(4:2984)-5 */
      /* Decrement the loop count */
      /* MISRA Violation: START Msg(4:2880)-6 */
      LulTimeOutCount--;
      /* END Msg(4:2880)-6 */
      /* END Msg(4:2984)-5 */
    }
    /* In case the register is not updated in the expected time,
     * report and DEM error */
    if (GPT_RESET_OSTM_TE_BYTE != (uint8)((LpOSTMUnitReg->ucTE)
        & LucChannelMask))
    {
      /* Implements GPT177, EAAR_PN0034_FR_0084 */
      Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
          ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
    }
    else
    {
      /* No action required */
    }
    break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
  /* QAC Warning: START Msg(2:2016)-2 */
  default:
    break;
  }
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
  /* End of Block - 1 */
  /* END Msg(2:2016)-2 */
  /* We stop the timer interrupts no matter what,
   * unconfigured channels will be ignored at the
   * Gpt_HW_DisableInterrupt function level.
   */
  /* Implements EAAR_PN0080_FR_0013 */
  Gpt_HW_DisableInterrupt(channel, GPT_INCLUDE_CRITICAL_SECTION);
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
  /* Implements GPT343 */
  /* Implements SWS_Gpt_00343 */
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_STOPPED;
  /* END Msg(2:2814)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
} /* End of API Gpt_HW_StopTimer */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_HW_DisableInterrupt
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function. This
 **                         function disables the interrupt for one channel.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel, LblCriticalSectionFlag
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variables      : Gpt_GpChannelConfig
 **
 ** Functions invoked     : GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers used        : ICTAUDmIn,ICTAUBmIn,ICTAUJmIn,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Qac Warning: START Msg(2:3227)-6 */
/* Implements GPT_ESDD_UD_102 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_DisableInterrupt(
    const Gpt_ChannelType channel, boolean LblCriticalSectionFlag)
{
  /* END Msg(2:3227)-6 */
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannelConfig;
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpChannelConfig = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Check whether Gpt_HW_DisableInterrupt is invoked from Init or DeInit
   * Apis */
  if (GPT_EXCLUDE_CRITICAL_SECTION != LblCriticalSectionFlag)
  {
    /* Disable relevant interrupts to protect this critical section */
     GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
  }
  else
  {
    /* No action Required */
  }
#endif
  /* QAC Warning: START Msg(2:2814)-3 */
  if ((NULL_PTR != LpChannelConfig->pIntrCntlAddress))
  {
    /* END Msg(2:2814)-3 */
    /* Implements GPT159 */
    /* Implements SWS_Gpt_00159, EAAR_PN0034_FR_0067 */
    if (GPT_HW_OSTM_FEINT != LpChannelConfig->uiTimerType)
    {
      /* Disabling the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_INTERRUPT_MASK_DIS);
    }
    else
    {
      /* QAC Warning: START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-8 */
      /* Set FEINT mask to disable FE interrupt */
      GPT_FEINT_WRITE_OR(&GPT_FEINT_FACTOR_MASK_REGISTER,
          (~((uint32)(((uint32)LpChannelConfig->usFeIntMaskValue) <<
              GPT_REG_SIZE_16BIT) | GPT_SET_WORD)));
      /* END Msg(4:0303)-8 */
      /* END Msg(2:3892)-5 */
    }
  }
  else
  {
    /* No action required */
  }
    /* Implements GPT_ESDD_UD_055 */
#if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  if ((NULL_PTR != LpChannelConfig->pIntrCntlAddress))
  {
    /* Clear pending interrupt flag */
    if (GPT_HW_OSTM_FEINT != LpChannelConfig->uiTimerType)
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Check whether Gpt_HW_DisableInterrupt is invoked from Init or DeInit
     * Apis */
    if (GPT_EXCLUDE_CRITICAL_SECTION != LblCriticalSectionFlag)
    {
      /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0068 */
      RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_CLEAR_PENDING_INTR_MASK);
    }
    else
    {
      /* Implements EAAR_PN0034_FR_0067 */
      RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_CLEAR_PENDING_INTR_MASK);
    }
#else
    /* Implements EAAR_PN0034_FR_0067 */
    RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_CLEAR_PENDING_INTR_MASK);
#endif
    }
    else
    {
      /* MISRA Violation: START Msg(4:0303)-8 */
      GPT_FEINT_WRITE_OR(&GPT_FEINT_FACTOR_MASK_REGISTER,
          (~((uint32)(((uint32)LpChannelConfig->usFeIntMaskValue) <<
              GPT_REG_SIZE_16BIT)| GPT_SET_WORD)));
      /* END Msg(4:0303)-8 */
    }
  }
  else
  {
    /* No action required */
  }
#endif
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Check whether Gpt_HW_DisableInterrupt is invoked from Init or DeInit
   * Apis */
  if (GPT_EXCLUDE_CRITICAL_SECTION != LblCriticalSectionFlag)
  {
    /* Enable relevant interrupts */
    GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
  }
  else
  {
    /* No action required */
  }
#endif

} /* End of API Gpt_HW_DisableWakeup */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name         : Gpt_HW_EnableInterrupt
 **
 ** Service ID            : NA
 **
 ** Description           : This is GPT Driver component support function.This
 **                         function enables the interrupt for one channel
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : channel
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variable(s)    : Gpt_GpChannelConfig
 **
 ** Function(s) invoked   : GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers used        : ICTAUDmIn,ICTAUBmIn,ICTAUJmIn,ICOSTMn,FEINTFMSK,
 **                         FEINTFC
 **
 ******************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_103 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_EnableInterrupt(
    const Gpt_ChannelType channel)
{
  /* Updating the channel configure parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannelConfig;
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  LpChannelConfig = &Gpt_GpChannelConfig[channel];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif

#if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  /* Check if the Interrupt register is present for particular channel */
  /* QAC Warning: START Msg(2:2814)-3 */
  if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
  {
  /* END Msg(2:2814)-3 */
  if (GPT_HW_OSTM_FEINT != LpChannelConfig->uiTimerType)
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Clear Interrupt control register */
    /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0068 */
    RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_CLEAR_PENDING_INTR_MASK);
#else
    /* Implements EAAR_PN0034_FR_0067 */
    RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
          GPT_CLEAR_PENDING_INTR_MASK);
#endif
    }
    else
    {
      /* QAC Warning: START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-8 */
      /* Set FEINTFC register to clear pending interrupt, 32bit write
       * Lower part of the register, first 16 bits must remain unchanged
       * */
      GPT_FEINT_WRITE_OR(&GPT_FEINT_FACTOR_MASK_REGISTER,
          (~((uint32)(((uint32)LpChannelConfig->usFeIntMaskValue) <<
              GPT_REG_SIZE_16BIT)| GPT_SET_WORD)));
      /* END Msg(4:0303)-8 */
      /* END Msg(2:3892)-5 */
    }
  } /* End of (LpChannelConfig->pIntrCntlAddress != NULL_PTR) */
  else
  {
    /* No action required */
  }
#endif
  /* QAC Warning: START Msg(2:2814)-3 */
  if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
  {
    /* END Msg(2:2814)-3 */
    /* Implements GPT160 */
    /* Implements SWS_Gpt_00160 */
    /* Enable the Interrupt processing of the current channel */
    if (GPT_HW_OSTM_FEINT != LpChannelConfig->uiTimerType)
    {
      /* Implements EAAR_PN0034_FR_0067 */
      RH850_SV_MODE_ICR_AND(16,(LpChannelConfig->pIntrCntlAddress),
          GPT_INTERRUPT_MASK_EN);
    }
    else
    {
      /* MISRA Violation: START Msg(4:0303)-8 */
      /* QAC Warning: START Msg(2:3892)-5 */
      /* Set FEINT mask to enable FE interrupt*/
      GPT_FEINT_WRITE_AND(&GPT_FEINT_FACTOR_MASK_REGISTER,
          ((uint32)(((uint32)LpChannelConfig->usFeIntMaskValue) <<
              GPT_REG_SIZE_16BIT) | GPT_SET_WORD));
      /* END Msg(4:0303)-8 */
      /* END Msg(2:3892)-5 */
    }
  } /* End of (NULL_PTR != LpChannelConfig->pIntrCntlAddress) */
  else
  {
    /* No action required */
  }

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif

} /* End of API Gpt_HW_EnableWakeup */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_ASIL_B
#else
  #define GPT_STOP_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/*
 * End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
 * (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
 */

/*******************************************************************************
 ** Function Name         : Gpt_CbkNotification
 **
 ** Service ID            : NA
 **
 ** Description           : This routine is used to invoke the callback
 **                         notification or wakeup notification based on timer
 **                         mode.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : LucChannelIdx
 **
 ** InOut Parameter       : None
 **
 ** Output Parameters     : None
 **
 ** Return Value          : None
 **
 ** Pre-condition         : None
 **
 ** Global Variable(s)    : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
 **                         Gpt_GucDriverMode, Gpt_GpTAUUnitConfig,
 **                         Gpt_GpWakeUpFactorRamAddress
 **
 ** Function(s) invoked   : EcuM_CheckWakeup, Gpt_HW_DisableInterrupt
 **                         GPT_ENTER_CRITICAL_SECTION,
 **                         GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used        : TAUDnTT, TAUBnTT, TAUJnTT, OSTMnTT, WUFC0, WUFC20,
 **                         ICTAUDmIn, ICTAUBmIn, ICTAUJmIn, ICOSTMn, TAUDBnTE
 **                         TAUJnTE, WUFC1, WUF0, WUF1, WUF20
 **
 ******************************************************************************/

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_START_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE
/* Implements GPT_ESDD_UD_105 */
/* Implements GPT275, SWS_Gpt_00275, EAAR_PN0080_FR_0016 */
FUNC (void, GPT_FAST_CODE) Gpt_CbkNotification(const uint8 LucChannelIdx)
{
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /* Offset index of the TAUD/TAUB Unit control registers */
  uint8 LucTAUDBUnitUserIndex;
  /* Pointer pointing to the TAUD/TAUB Unit control registers */
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif

#if (GPT_TAUJ_UNIT_USED == STD_ON)
  /* Offset index of the TAUJ Unit user control registers */
  uint8 LucTAUJUnitUserIndex;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif

#if (GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
#endif

  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST)LpChannel;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) || \
    (GPT_TAUJ_UNIT_USED == STD_ON) || (GPT_OSTM_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamData, AUTOMATIC, GPT_CONFIG_DATA)LpRamData;
  uint8 LucTimerType;
#endif

#if ((GPT_TAUJ_UNIT_USED == STD_ON) || (GPT_OSTM_UNIT_USED == STD_ON))
  uint8 LucTAUChannelMaskValue;
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
  /*local variable to take channel mask*/
  uint16 LusTAUChannelMaskValue;
#endif

  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON))
  /* Defining a pointer to point to the WUF0 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, GPT_CONFIG_DATA) LpWuf0Reg;
  /* Implements GPT_ESDD_UD_167 */
  /* Defining a pointer to point to the WUF1 registers */
#if (GPT_WUF1_SUPPORTED == STD_ON)
  P2VAR(volatile WUFReg, AUTOMATIC, GPT_CONFIG_DATA) LpWuf1Reg;
#endif
  /* Defining a pointer to point to the WUF20 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, GPT_CONFIG_DATA) LpWuf20Reg;
#endif
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LucChannelIdx];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) || \
    (GPT_TAUJ_UNIT_USED == STD_ON) || (GPT_OSTM_UNIT_USED == STD_ON))
  /* QAC Warning: START Msg(2:2814)-3 */
  /* Updating the TimerType of the current channel */
  LucTimerType = LpChannel->uiTimerType;
  /* END Msg(2:2814)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
  /* QAC Warning START Msg(2:2824)-4 */
  /* MISRA Violation: START Msg(4:0491)-3 */
  /* Updating the channel ram data to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LucChannelIdx];
  /* END Msg(4:0491)-3 */
  /* END Msg(2:2824)-4 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
  /* Implements GPT185 */
  /* Implements SWS_Gpt_00185, EAAR_PN0080_FR_0028 */
  if (GPT_CH_MODE_ONESHOT == LpChannel->uiGptChannelMode)
  {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    GPT_ENTER_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif
    switch (LucTimerType)
    { /* Start of Block - 1 */
#if (GPT_TAUD_UNIT_USED == STD_ON)
    case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
    case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))
      /* QAC Warning START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Initialize pointer to the base address of the current timer unit */
      LucTAUDBUnitUserIndex =
          Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].
            ucTAUUnitUserCntlRegIndex;
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
      LpTAUDBUnitUserReg =
         Gpt_GaaTAUDBUserReg_BaseAddress[LucTAUDBUnitUserIndex];
      /* Take the channel mask to a local var */
      LusTAUChannelMaskValue = LpChannel->usChannelMask;
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Stop the timer TAUD/TAUB */
      GPT_WRITE_TAUDB_MIRROR_ONLY(
          &Gpt_GaaGptTAUDBUserRegMirror[LucTAUDBUnitUserIndex].usTE,
          LpTAUDBUnitUserReg->usTE & (uint16 )(~LusTAUChannelMaskValue))
      GPT_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT, LusTAUChannelMaskValue)
      /* END Msg(2:2814)-3 */
      /* TE register is updated after one clock cycle.
       * A Wait loop implementations is required instead of WRITE-VERIFY*/
      /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
      LulTimeOutCount = GPT_TIMEOUT_COUNT;
      /* MISRA Violation: START Msg(4:2877)-4 */
      while ((GPT_RESET_LONG_WORD != LulTimeOutCount)
          && (GPT_RESET_WORD
              != (uint16) (LpTAUDBUnitUserReg->usTE & LusTAUChannelMaskValue)))
      /* END Msg(4:2877)-4 */
      {
        /* MISRA Violation: START Msg(4:2984)-5 */
        /* MISRA Violation: START Msg(4:2880)-6 */
        LulTimeOutCount--;
        /* END Msg(4:2880)-6 */
        /* END Msg(4:2984)-5 */
      }
      /* In case the register is not updated in the expected time,
       * report and DEM error */
      if (GPT_RESET_WORD
          != (uint16) ((LpTAUDBUnitUserReg->usTE) & LusTAUChannelMaskValue))
      {
        /* Implements GPT177, EAAR_PN0034_FR_0084 */
        Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
            ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED ));
      }
      else
      {
        /* No action required */
      }
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Assign the timer status to the Channel */
      LpRamData->ucChannelStatus = GPT_CH_EXPIRED;
      /* END Msg(2:2814)-3 */
      break;
#endif
      /* End of
       ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON) )*/

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    case GPT_HW_TAUJ:
      /* QAC Warning START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Initialize pointer to the base address of the current timer unit */
      LucTAUJUnitUserIndex =
          Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].
            ucTAUUnitUserCntlRegIndex;
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
      LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress[LucTAUJUnitUserIndex];
      /* Take the channel mask to a local var */
      LucTAUChannelMaskValue = (uint8) LpChannel->usChannelMask;
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Stop the timer TAUJ */
      GPT_WRITE_TAUJ_MIRROR_ONLY(
          &Gpt_GaaGptTAUJUserRegMirror[LucTAUJUnitUserIndex].ucTE,
          LpTAUJUnitUserReg->ucTE & (uint8 )(~LucTAUChannelMaskValue))
      GPT_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT, LucTAUChannelMaskValue)
      /* END Msg(2:2814)-3 */
      /* TE register is updated after one clock cycle.
       * A Wait loop implementation is required instead of WriteVerify*/
      /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
      LulTimeOutCount = GPT_TIMEOUT_COUNT;
      /* MISRA Violation: START Msg(4:2877)-4 */
      while ((GPT_RESET_LONG_WORD != LulTimeOutCount)
          && (GPT_RESET_BYTE
              != (uint8) (LpTAUJUnitUserReg->ucTE & LucTAUChannelMaskValue)))
      /* END Msg(4:2877)-4 */
      {
         /* MISRA Violation: START Msg(4:2984)-5 */
         /* MISRA Violation: START Msg(4:2880)-6 */
         LulTimeOutCount--;
         /* END Msg(4:2880)-6 */
         /* END Msg(4:2984)-5 */
      }
      /* In case the register is not updated in the expected time,
       * report and DEM error */
      if (GPT_RESET_TAU_TE_BYTE
          != (uint8) ((LpTAUJUnitUserReg->ucTE) & LucTAUChannelMaskValue))
      {
        /* Implements GPT177, EAAR_PN0034_FR_0084 */
        Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
            ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED ));
      }
      else
      {
        /* No action required */
      }
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Assign the timer status to the Channel */
      LpRamData->ucChannelStatus = GPT_CH_EXPIRED;
      /* END Msg(2:2814)-3 */
      break;
#endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    /*Implements EAAR_PN0080_FR_0019, EAAR_PN0080_FR_0022 */
#if (GPT_OSTM_UNIT_USED == STD_ON)
    case GPT_HW_OSTM:
    case GPT_HW_OSTM_FEINT:
      LpOSTMUnitReg = Gpt_GaaOSTMReg_BaseAddress[LpChannel->ucBaseCtlRegIndex];
      /* Take the channel mask to a local var */
      LucTAUChannelMaskValue = GPT_OSTM_STOP_MASK;
      /* Stop the timer OSTM */
      GPT_WRITE_OSTM_MIRROR_ONLY(
          &Gpt_GaaGptOSTMRegMirror[LpChannel->ucBaseCtlRegIndex].ucTE,
          LpOSTMUnitReg->ucTE & (uint8 )(~LucTAUChannelMaskValue))
      GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTT, LucTAUChannelMaskValue)
      /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
      /* TE register is updated after one clock cycle.
       * A Wait loop implementation is required instead of WriteVerify*/
      LulTimeOutCount = GPT_TIMEOUT_COUNT;
      /* MISRA Violation: START Msg(4:2877)-4 */
      while ((GPT_RESET_LONG_WORD != LulTimeOutCount)
          && (GPT_RESET_BYTE
              != (uint8) (LpOSTMUnitReg->ucTE & LucTAUChannelMaskValue)))
      /* END Msg(4:2877)-4 */
      {
        /* MISRA Violation: START Msg(4:2984)-5 */
        /* MISRA Violation: START Msg(4:2880)-6 */
        LulTimeOutCount--;
        /* END Msg(4:2880)-6 */
        /* END Msg(4:2984)-5 */
      }
      if (GPT_RESET_OSTM_TE_BYTE
          != (uint8) ((LpOSTMUnitReg->ucTE) & LucTAUChannelMaskValue))
      /* In case the register is not updated in the expected time,
       * report and DEM error */
      {
        /* Implements GPT177, EAAR_PN0034_FR_0084 */
        Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
            ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED ));
      }
      else
      {
        /* No action required */
      }
      /* Assign the timer status to the Channel */
      LpRamData->ucChannelStatus = GPT_CH_EXPIRED;
      break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    /* QAC Warning: START Msg(2:2016)-2 */
    default:
      break;
    } /* End of Block - 1 */
    /* END Msg(2:2016)-2 */
    /* We mask the interrupt for the channel once it expired
     * This also removes any remaining interrupt request flag that might exist
     * on really short timer duration.
     */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_TIMERINT_PROTECTION)
#endif

    Gpt_HW_DisableInterrupt(LucChannelIdx, GPT_INCLUDE_CRITICAL_SECTION);

  } /* End of LpChannel->uiGptChannelMode == GPT_CH_MODE_ONESHOT */
  else
  {
    /* No action required */
  }
#endif/*
 * End of ((GPT_TAUD_UNIT_USED == STD_ON) ||
 * (GPT_TAUB_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON))
 */
  /* Implements EAAR_PN0080_FR_0056 */
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (GPT_WAKEUP_FACTOR_CLEAR_ISR == STD_ON))
  LpWuf0Reg = Gpt_GpWUF0Reg_BaseAddress;
  LpWuf20Reg = Gpt_GpWUF20Reg_BaseAddress;
  /* Checking the timer channel belongs to which unit */
  if (GPT_HW_TAUJ == (LpChannel->uiTimerType))
  {
    /* checking for the wakeup capability of the channel */
    if (GPT_TRUE == (LpChannel->uiGptWakeupSupport))
    {
      if (NULL_PTR != LpWuf0Reg)
      {
        /* QAC Warning: START Msg(2:2814)-3 */
        /* Check the WUF Factor flags */
        if (GPT_DOUBLE_ZERO
            != ((LpWuf0Reg->ulWUF0)
                & (Gpt_GpWakeUpFactorRamAddress->ulWUF0MaskValue)))
        /* END Msg(2:2814)-3 */
        {
          /* Implements GPT327 */
          /* Implements SWS_Gpt_00327 */
          /* Clearing the WUF flag by setting the WUFC register */
          GPT_WRITE_REG_ONLY(&LpWuf0Reg->ulWUFC0,
              (LpWuf0Reg->ulWUF0 &
                  Gpt_GpWakeUpFactorRamAddress->ulWUF0MaskValue))
          GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf0Reg->ulWUF0,
              GPT_WUF0_RESET_VAL,
              Gpt_GpWakeUpFactorRamAddress->ulWUF0MaskValue,
              GPT_CBKNOTIFICATION_API_ID)
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
#if (GPT_WUF1_SUPPORTED == STD_ON)
      LpWuf1Reg = Gpt_GpWUF1Reg_BaseAddress;
      if (NULL_PTR != LpWuf1Reg)
      {
        /* Check the WUF Factor flags */
        if (GPT_DOUBLE_ZERO
            != ((LpWuf1Reg->ulWUF0)
                & (Gpt_GpWakeUpFactorRamAddress->ulWUF1MaskValue)))
        {
          /* Implements GPT327 */
          /* Implements SWS_Gpt_00327 */
          /* Clearing the WUF flag by setting the WUFC register */
          GPT_WRITE_REG_ONLY(&LpWuf1Reg->ulWUFC0,
              (LpWuf1Reg->ulWUF0 &
                  Gpt_GpWakeUpFactorRamAddress->ulWUF1MaskValue))
          GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf1Reg->ulWUF0,
              GPT_WUF0_RESET_VAL,
              Gpt_GpWakeUpFactorRamAddress->ulWUF1MaskValue,
              GPT_CBKNOTIFICATION_API_ID)
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
#endif
      if (NULL_PTR != LpWuf20Reg)
      {
        /* Check the WUF20 Factor flags */
        if (GPT_DOUBLE_ZERO
            != ((LpWuf20Reg->ulWUF0)
                & (Gpt_GpWakeUpFactorRamAddress->ulWUF20MaskValue)))
        {
          /* Clearing the WUF flag by setting the WUFC register */
          GPT_WRITE_REG_ONLY(&LpWuf20Reg->ulWUFC0,
              (LpWuf20Reg->ulWUF0
                  & Gpt_GpWakeUpFactorRamAddress->ulWUF20MaskValue))
          GPT_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf20Reg->ulWUF0,
              GPT_WUF0_RESET_VAL,
              Gpt_GpWakeUpFactorRamAddress->ulWUF20MaskValue,
              GPT_CBKNOTIFICATION_API_ID)
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
#endif
  /* copy the driver status */
  if (GPT_MODE_NORMAL == Gpt_GucDriverMode)
  {
    /* Implements GPT206 */
    /* Implements SWS_Gpt_00206 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

    /* Invoke callback notification if notification is enabled */
    /* Critical section is not added since corresponding step is not dealing
     * with changing a global variable */
    /* MISRA Violation: START Msg(4:0491)-3 */
    if (GPT_NOTIFICATION_ENABLED
        == Gpt_GpChannelRamData[LucChannelIdx].uiNotifyStatus)
    /* END Msg(4:0491)-3 */
    {
      if (NULL_PTR != LpChannel->pGptNotificationPointer)
      {
        /* Implements GPT233, GPT292 */
        /* Implements GPT209 */
        /* Implements SWS_Gpt_00233, SWS_Gpt_00292 */
        /* Implements SWS_Gpt_00209 */
        /* Implements GPT_ESDD_UD_115 */
        /* Invoke the callback function */
        LpChannel->pGptNotificationPointer();
      }
      else
      {
        /* No action required*/
      }
    } /* End of Gpt_GpChannelRamData[LucChannelIdx].uiNotifyStatus ==
     GPT_NOTIFICATION_ENABLED*/
    /* Implements GPT093 */
    /* Implements SWS_Gpt_00093 */
    else
    {
      /* No action required */
    }
#endif /* End of (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */
  } /* End of Gpt_GucDriverMode == GPT_MODE_NORMAL */
  else
  {
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Read wakeup source value from PB config and check if it is valid
     * Only report wakeup if driver is in Sleep mode and
     * wakeup notification is enabled, */
    /* MISRA Violation: START Msg(4:0491)-3 */
    if ((GPT_WAKEUP_NOTIFICATION_DISABLED
        != Gpt_GpChannelRamData[LucChannelIdx].uiWakeupStatus)
        && (GPT_NOWAKEUP != Gpt_GpChannelConfig[LucChannelIdx].ddWakeupSource)
        /* END Msg(4:0491)-3 */
        )
    {
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* Set the wakeup occurrence status to true */
      Gpt_GpChannelRamData[LucChannelIdx].uiGptWakeupOccurrence = GPT_TRUE;
      /* Implements GPT326 */
      /* Implements GPT127 */
      /* Implements SWS_Gpt_00326 */
      /* Implements SWS_Gpt_00127 */
      /* invoke ECU Wakeup function*/
      EcuM_CheckWakeup(Gpt_GpChannelConfig[LucChannelIdx].ddWakeupSource);
      /* END Msg(4:0491)-3 */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif
    }
    else
    {
      /* No action required, wakeup was not enabled for channel or
       * no wakeup source configured */
    }
#endif /* End of (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
  }

} /* End of API Gpt_CbkNotification */

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_STOP_SEC_CODE_FAST_ASIL_B
#else
  #define GPT_STOP_SEC_CODE_FAST
#endif
#include GPT_MEMMAP_FILE

/*******************************************************************************
 ** Function Name        : Gpt_LLDriverHWCheckConsistency
 **
 ** Service ID           : NA
 **
 ** Description          : This function compares the control register values
 **                        with its corresponding RAM mirror
 **                        variable if GPT_OSTM_RAM_MIRROR or
 **                        GPT_TAUDB_RAM_MIRROR or GPT_TAUJ_RAM_MIRROR
 **                        is GPT_MIRROR_ENABLE.
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
 **                        GPT_TAUDB_RAM_MIRROR GPT_TAUJ_RAM_MIRROR is STD_ON
 **
 ** Functions invoked    :
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
#if ( (GPT_OSTM_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUDB_RAM_MIRROR == GPT_MIRROR_ENABLE ) || \
    (GPT_TAUJ_RAM_MIRROR == GPT_MIRROR_ENABLE ))

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
  #define GPT_START_SEC_CODE_ASIL_B
#else
  #define GPT_START_SEC_CODE
#endif
#include GPT_MEMMAP_FILE

/* Implements GPT_ESDD_UD_135 */
/* Implements GPT_ESDD_UD_107, GPT_ESDD_UD_108, GPT_ESDD_UD_109 */
/* Implements GPT_ESDD_UD_110 */
/* Implements GPT_ESDD_UD_036, GPT_ESDD_UD_037, GPT_ESDD_UD_038 */
/* Implements GPT_ESDD_UD_041, GPT_ESDD_UD_042, GPT_ESDD_UD_043 */
/* Implements GPT_ESDD_UD_039, GPT_ESDD_UD_046 */
/* Implements GPT_ESDD_UD_044, GPT_ESDD_UD_045 */
/* Implements GPT_ESDD_UD_047, GPT_ESDD_UD_049 */
FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_LLDriverHWCheckConsistency(
    const Gpt_HWConsistencyModeType HWConsistencyMode)
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddRetConsistencyState;

  uint8 LucCount;

  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpChannelConfig;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAU Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpTAUUnitConfig;
#endif

#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
    ( ((GPT_TAUB_UNIT_USED == STD_ON) && (GPT_TAUB_UNIT_CONFIG == STD_ON))  || \
        ((GPT_TAUD_UNIT_USED == STD_ON) && (GPT_TAUD_UNIT_CONFIG == STD_ON)) \
    ))
  /* Pointer pointing to the TAUD/TAUB Unit os control registers */
  P2VAR(volatile TAUDBOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitOsReg;
#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
  P2VAR(volatile TAUDBUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBUnitUserReg;
#endif
#endif

#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUJ_UNIT_USED == STD_ON) && (GPT_TAUJ_UNIT_CONFIG == STD_ON)))
#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJUserReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitUserReg;
#endif
#endif

#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUB_UNIT_USED == STD_ON)|| (GPT_TAUD_UNIT_USED == STD_ON)))
  /* Defining a pointer to point to the TAUD\TAUB registers */
  P2VAR(volatile TAUDBChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUDBChannelRegs;
#endif

#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
    ((GPT_TAUJ_UNIT_USED == STD_ON) && (GPT_TAUJ_UNIT_CONFIG == STD_ON))\
)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(volatile TAUJOsReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJUnitOsReg;
#endif
#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
    (GPT_TAUJ_UNIT_USED == STD_ON)\
)
  /* Pointer used for TAUJ channel control registers */
  P2VAR(volatile TAUJChReg, AUTOMATIC, GPT_CONFIG_DATA) LpTAUJChannelReg;
#endif

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_OSTM_UNIT_USED == STD_ON) ||  \
      (GPT_PREDEF_TIMER_ENABLED == STD_ON)) \
     )

  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA) LpOSTMUnitReg;

#endif
#else
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_OSTM_UNIT_USED == STD_ON))
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA) LpOSTMUnitReg;
#endif
#endif /* End of (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION) */

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif

  LddRetConsistencyState = E_OK;

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUJ_UNIT_USED == STD_ON) || \
    (GPT_TAUB_UNIT_USED == STD_ON) )
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;
#endif

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Gpt_GpChannelConfig;

  /* Check Static registers */
  if (GPT_STATIC == HWConsistencyMode)
  {
#if (GPT_TAUD_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = (uint8) GPT_ZERO ;
        LucCount < (uint8) GPT_TOTAL_TAUD_UNITS_CONFIG; LucCount++)
    /* END Msg(4:2877)-4 */
    {
#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
      (GPT_TAUD_UNIT_CONFIG == STD_ON))
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Initialize the pointer to os register base address */
      LpTAUDBUnitOsReg =
        Gpt_GaaTAUDBOsReg_BaseAddress[LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];

      if (((LpTAUDBUnitOsReg->usRDE &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDE_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDM &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDM_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDS &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDS_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDC &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDC_RESET_VAL)
             )
      /* END Msg(2:2814)-3 */
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
      /* Check for Pre scalar setting by the GPT module for TAUDn Unit */
      if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
      {
        if ((LpTAUDBUnitOsReg->usTPS != LpTAUUnitConfig->usPrescaler)
            || (LpTAUDBUnitOsReg->ucBRS != LpTAUUnitConfig->ucBaudRate))
        {
          LddRetConsistencyState = E_NOT_OK;
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
#endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
      LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress
      [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
      if (LpTAUDBUnitUserReg->usTOE != (LpTAUDBUnitUserReg->usTOE |
              LpTAUUnitConfig->usTAUChannelMaskValue))
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
#endif /* End of (GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* End of ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE)
                      && (GPT_TAUD_UNIT_CONFIG == STD_ON)) */

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer for the next TAUD Unit */
      LpTAUUnitConfig++;
      /* END Msg(4:0489)-1 */
    }
#endif /* End of (GPT_TAUD_UNIT_USED == STD_ON) */

#if ((GPT_TAUB_UNIT_USED == STD_ON))
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUB_UNITS_CONFIG;
        LucCount++)
    /* END Msg(4:2877)-4 */
    {
#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
      (GPT_TAUB_UNIT_CONFIG == STD_ON))
      /* Initialize the pointer to os register base address */
      LpTAUDBUnitOsReg =
        Gpt_GaaTAUDBOsReg_BaseAddress[LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
      if (((LpTAUDBUnitOsReg->usRDE &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDE_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDM &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDM_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDS &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDS_RESET_VAL)
         || ((LpTAUDBUnitOsReg->usRDC &
             LpTAUUnitConfig->usTAUChannelMaskValue) != GPT_TAUDB_RDC_RESET_VAL)
             )
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
      /* Check for Pre scalar setting by the GPT module for TAUBn Unit */
      if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
      {
        if (LpTAUDBUnitOsReg->usTPS != LpTAUUnitConfig->usPrescaler)
        {
          LddRetConsistencyState = E_NOT_OK;
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
#endif /* End of ((GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
      LpTAUDBUnitUserReg = Gpt_GaaTAUDBUserReg_BaseAddress
      [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      if (LpTAUDBUnitUserReg->usTOE != (LpTAUDBUnitUserReg->usTOE |
              LpTAUUnitConfig->usTAUChannelMaskValue))
      /* END Msg(2:2814)-3 */
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
#endif /* End of (GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* End of ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE)
                        && (GPT_TAUB_UNIT_CONFIG == STD_ON)) */

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer for the next TAUB Unit */
      LpTAUUnitConfig++;
      /* END Msg(4:0489)-1 */
    }
#endif /* End of (GPT_TAUB_UNIT_USED == STD_ON) */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = GPT_ZERO;LucCount < GPT_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
      /* END Msg(4:2877)-4 */
    {
#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
      (GPT_TAUJ_UNIT_CONFIG == STD_ON))
      /* Initialize the pointer to OS register base address */
      LpTAUJUnitOsReg =
         Gpt_GaaTAUJOsReg_BaseAddress[LpTAUUnitConfig->ucTAUUnitOsCntlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      if ((GPT_RESET_TAU_RDE_BYTE != (LpTAUJUnitOsReg->ucRDE &
              ((uint8)(LpTAUUnitConfig->usTAUChannelMaskValue))))
          || (GPT_RESET_TAU_RDM_BYTE != (LpTAUJUnitOsReg->ucRDM &
              ((uint8)(LpTAUUnitConfig->usTAUChannelMaskValue)))))
      /* END Msg(2:2814)-3 */
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Implements EAAR_PN0080_FR_0030 */
#if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
      /* Check for Pre-scalar setting by the GPT module for TAUJn Unit */
      if (GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
      {
        if ((LpTAUJUnitOsReg->usTPS != LpTAUUnitConfig->usPrescaler)
            || (LpTAUJUnitOsReg->ucBRS != LpTAUUnitConfig->ucBaudRate))
        {
          LddRetConsistencyState = E_NOT_OK;
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
#endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)*/

#if (GPT_TIMER_OUTPUT_ENABLE == STD_ON)
      LpTAUJUnitUserReg = Gpt_GaaTAUJUserReg_BaseAddress
      [LpTAUUnitConfig->ucTAUUnitUserCntlRegIndex];
      /* QAC Warning: START Msg(2:2814)-3 */
      if (LpTAUJUnitUserReg->ucTOE !=
          (uint8)((((uint16)LpTAUJUnitUserReg->ucTOE) |
                  LpTAUUnitConfig->usTAUChannelMaskValue)))
      /* END Msg(2:2814)-3 */
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
#endif /* End of (GPT_TIMER_OUTPUT_ENABLE == STD_ON) */
#endif /* End of ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE)
                        && (GPT_TAUJ_UNIT_CONFIG == STD_ON)) */
      /* MISRA Violation: START Msg(4:0489)-1 */
      /* MISRA Violation: START Msg(4:2983)-2 */
      /* Increment the pointer to the next TAUJ Unit */
      LpTAUUnitConfig++;
      /* END Msg(4:0489)-1 */
      /* END Msg(4:2983)-2 */
    }
#endif /* End of  (GPT_TAUJ_UNIT_USED == STD_ON) */

    for (LucCount = GPT_ZERO; LucCount < GPT_TOTAL_CHANNELS_CONFIG; LucCount++)
    {
    /* QAC Warning: START Msg(2:2814)-3 */
      switch (LpChannelConfig->uiTimerType)
    /* END Msg(2:2814)-3 */
      {
#if (GPT_TAUD_UNIT_USED == STD_ON)
      case GPT_HW_TAUD:
#endif

#if (GPT_TAUB_UNIT_USED == STD_ON)
      case GPT_HW_TAUB:
#endif

#if ((GPT_TAUD_UNIT_USED == STD_ON) || (GPT_TAUB_UNIT_USED == STD_ON))

#if (GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE)
        LpTAUDBChannelRegs =
            Gpt_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucBaseCtlRegIndex];
        /* QAC Warning: START Msg(2:2814)-3 */
        if ((LpTAUDBChannelRegs->usCMOR != LpChannelConfig->usModeSettingsMask)
            || (LpTAUDBChannelRegs->ucCMUR != GPT_RESET_TAU_CMUR_BYTE ))
        /* END Msg(2:2814)-3 */
        {
          LddRetConsistencyState = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
#endif /* End of (GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) */

        break;
#endif /* End of((GPT_TAUD_UNIT_USED == STD_ON)||
                 (GPT_TAUB_UNIT_USED == STD_ON)) */

#if (GPT_TAUJ_UNIT_USED == STD_ON)
      case GPT_HW_TAUJ:
#if (GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE)
        LpTAUJChannelReg =
            Gpt_GaaTAUJChReg_BaseAddress[LpChannelConfig->ucBaseCtlRegIndex];
        /* QAC Warning: START Msg(2:2814)-3 */
        if ((LpTAUJChannelReg->usCMOR != LpChannelConfig->usModeSettingsMask)
            || (LpTAUJChannelReg->ucCMUR != GPT_RESET_TAU_CMUR_BYTE ))
        /* END Msg(2:2814)-3 */
        {
          LddRetConsistencyState = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
#endif /* End of (GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) */

        break;
#endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

#if (GPT_OSTM_UNIT_USED == STD_ON)
      case GPT_HW_OSTM:
      case GPT_HW_OSTM_FEINT:
#if (GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE)
        LpOSTMUnitReg =
            Gpt_GaaOSTMReg_BaseAddress[LpChannelConfig->ucBaseCtlRegIndex];
        /* QAC Warning: START Msg(2:2814)-3 */
        if (LpOSTMUnitReg->ucCTL != GPT_CH_MODE_OSTM_CONTINUOUS)
        /* END Msg(2:2814)-3 */
        {
          LddRetConsistencyState = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
#endif /* End of (GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) */

        break;
#endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
      /* QAC Warning: START Msg(2:2016)-2 */
      default:
        break;
      }
      /* END Msg(2:2016)-2 */
      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer to the next channel */
      LpChannelConfig++;
      /* END Msg(4:0489)-1 */
    }

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)

#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_PREDEF_TIMER_ENABLED == STD_ON)\
    )
    LpOSTMUnitReg = Gpt_GpOSTMRegPredefTimer_BaseAddress;
    if (LpOSTMUnitReg->ucCTL != GPT_CH_MODE_OSTM_CONTINUOUS)
    {
      LddRetConsistencyState = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
#endif

#endif /* End of (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION) */

  }
  /* Check Dynamic registers*/
  else if (GPT_DYNAMIC == HWConsistencyMode)
  {
#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_OSTM_UNIT_USED == STD_ON))
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = GPT_ZERO ;
        ((LucCount < (uint8) GPT_NUM_OF_OSTM_REG)
            && (E_NOT_OK != LddRetConsistencyState)); LucCount++)
    /* END Msg(4:2877)-4 */
    {
      if ((Gpt_GaaOSTMReg_BaseAddress[LucCount]->ulCMP
          != Gpt_GaaGptOSTMRegMirror[LucCount].ulCMP)
          || (Gpt_GaaOSTMReg_BaseAddress[LucCount]->ucTE
              != Gpt_GaaGptOSTMRegMirror[LucCount].ucTE))
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
    }
#endif

#if ((GPT_TAUDB_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     ((GPT_TAUB_UNIT_USED == STD_ON) || (GPT_TAUD_UNIT_USED == STD_ON)))
    for (LucCount = GPT_ZERO ;
        ((LucCount < (uint8) GPT_NUM_OF_TAUDB_REG)
            && (E_NOT_OK != LddRetConsistencyState)); LucCount++)
    {
      if (Gpt_GaaTAUDBUserReg_BaseAddress[LucCount]->usTE
          != Gpt_GaaGptTAUDBUserRegMirror[LucCount].usTE)
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
    }

    for (LucCount = GPT_ZERO ;
        ((LucCount < (uint8) GPT_NUM_OF_TAUDB_CH_REG)
            && (E_NOT_OK != LddRetConsistencyState)); LucCount++)
    {
      if (Gpt_GaaTAUDBChReg_BaseAddress[LucCount]->usCDR
          != Gpt_GaaGptTAUDBChRegMirror[LucCount].usCDR)
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
    }
#endif

#if ((GPT_TAUJ_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
    (GPT_TAUJ_UNIT_USED == STD_ON))
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = GPT_ZERO ;
        ((LucCount < (uint8) GPT_NUM_OF_TAUJ_REG)
            && (E_NOT_OK != LddRetConsistencyState)); LucCount++)
    /* END Msg(4:2877)-4 */
    {
      if (Gpt_GaaTAUJUserReg_BaseAddress[LucCount]->ucTE
          != Gpt_GaaGptTAUJUserRegMirror[LucCount].ucTE)
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
    }
    /* MISRA Violation: START Msg(4:2877)-4 */
    for (LucCount = GPT_ZERO ;
        ((LucCount < (uint8) GPT_NUM_OF_TAUJ_CH_REG)
            && (E_NOT_OK != LddRetConsistencyState)); LucCount++)
    /* END Msg(4:2877)-4 */
    {
      if (Gpt_GaaTAUJChReg_BaseAddress[LucCount]->ulCDR
          != Gpt_GaaGptTAUJChRegMirror[LucCount].ulCDR)
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

#if (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION)

#if ((GPT_OSTM_RAM_MIRROR != GPT_MIRROR_DISABLE) && \
     (GPT_PREDEF_TIMER_ENABLED == STD_ON)\
    )
      if ((Gpt_GpOSTMRegPredefTimer_BaseAddress->ulCMP !=
              Gpt_GstGptPredefTimerOSTMRegMirror.ulCMP) ||
          (Gpt_GpOSTMRegPredefTimer_BaseAddress->ucTE !=
              Gpt_GstGptPredefTimerOSTMRegMirror.ucTE)
      )
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
#endif
#endif /* End of (GPT_AR_VERSION == GPT_AR_HIGHER_VERSION) */
    }
#endif
  }
  else
  {
    /* No action required */
  }

#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#endif

  return (LddRetConsistencyState);
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

#if (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION)
#if (GPT_PREDEF_TIMER_ENABLED == STD_ON)
/*******************************************************************************
 ** Function Name        : Gpt_HW_GetPredefTimerValue
 **
 ** Service ID           : NA
 **
 ** Description          : This function computes and returns the value of the
 **                        requested Predefined Timer
 **
 ** Sync/Async           : Synchronous
 **
 ** Re-entrancy          : Reentrant
 **
 ** Input Parameters     : LddPredefTimer
 **
 ** InOut Parameters     : None
 **
 ** Output Parameters    : None
 **
 ** Return parameter     : LddElapsedTime
 **
 ** Preconditions        : This function is available only if the pre-compile
 **                        option GPT_PREDEF_TIMER_ENABLED is STD_ON
 **
 ** Global Variables used: Gpt_GusPredefTimerNrOverflows
 **
 ** Functions invoked    : GPT_ENTER_CRITICAL_SECTION,
 **                        GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used       : OSTMnCNT, ICOSTMn, FEINTF
 **
 ******************************************************************************/
#define GPT_START_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*Implements GPT_ESDD_UD_156 */
FUNC(Gpt_ValueType, GPT_PRIVATE_CODE)Gpt_HW_GetPredefTimerValue (
    Gpt_PredefTimerType LddPredefTimer)
{
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;
  /* Reading of current timer register value */
  uint32 LulHWTimerValue;

  /* Count the number of times the timer had an overflow */
  uint16 LusNrOfTimerOverflows;
#if ((GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE != GPT_PREDEF_TIMER_EI_INTR) ||\
     (GPT_CRITICAL_SECTION_PROTECTION == STD_OFF))
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE != GPT_PREDEF_TIMER_EI_INTR)
  uint32 LulFeOSTMChannelInterruptMask;
#endif
  uint32 LulHWTimerSecondValue;
  uint8 LucInterruptPendingFlagBefore;
  uint8 LucInterruptPendingFlagAfter;
#endif
  /* Elapsed time return value */
  Gpt_ValueType LddElapsedTime;
  /* Temporary variables used for calculations */
  uint32 LulDivisionReminder;
  uint32 LulPredefTimerMask;
  uint16 LusPredefTimerDivisionFactor; /* maximum possible value is 6000 */

  /* MISRA Violation: START Msg(4:2982)-7 */
  /*Initialise local variables */
  LulHWTimerValue = (Gpt_ValueType)GPT_TIMER_INIT_VAL_ZERO;
  LddElapsedTime = (Gpt_ValueType)GPT_TIMER_INIT_VAL_ZERO;
  LusNrOfTimerOverflows = (uint16)GPT_TIMER_INIT_VAL_ZERO;
  LulDivisionReminder = (uint32)GPT_TIMER_INIT_VAL_ZERO;
  LulPredefTimerMask = (uint32)GPT_TIMER_INIT_VAL_ZERO;
  LusPredefTimerDivisionFactor = (uint16)GPT_TIMER_INIT_VAL_ZERO;
  /* END Msg(4:2982)-7 */

  /* Get address of HW unit register */
  LpOSTMUnitReg = Gpt_GpOSTMRegPredefTimer_BaseAddress;

  /* In case of OSTM0 or OSTM5 which used EI interrupt, critical section shall
   * be used, if configured, to assure that interrupt cannot occur during
   * reading of the timer value. Pending interrupt flag shall be read to see
   * if the timer just had an overflow. If this is the case then a new reading
   * has to be done, and the number of timer overflows has to be compensated
   * with 1.
   */
#if ((GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE == GPT_PREDEF_TIMER_EI_INTR) &&\
     (GPT_CRITICAL_SECTION_PROTECTION == STD_ON))
  /* Enter Protected area.*/
  GPT_ENTER_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)

  /* Implements SWS_Gpt_00397 */
  /* Store time value and number of overflows in local variables
   * Because the timer is counting downwards, the elapsed time is obtained
   * by subtracting the value of the count register from the maximum timer value
   */

  LulHWTimerValue = (GPT_MAX_OSTM_VAL - LpOSTMUnitReg->ulCNT);

  /* In order to compensate for the fact that the hardware unit has a higher
   * resolution a counter is used to count the number of overflows of the timer
   */
  LusNrOfTimerOverflows = Gpt_GusPredefTimerNrOverflows;

  /* If an interrupt for Predefined timer is pending,
   * then simulate an additional overflow */
  /* MISRA Violation: START Msg(4:0303)-8 */
  if (GPT_CHECK_INTR_REQUEST_MASK ==
      ((uint16)(GPT_OSTM_INTR_REQ_REGISTER) & GPT_CHECK_INTR_REQUEST_MASK)
  /* END Msg(4:0303)-8 */
  )
  {
    /* Read again current value of the count register.
     * Because there was an overflow, the previously read time may be
     * inconsistent compared to the number of overflows*/
    LulHWTimerValue = (GPT_MAX_OSTM_VAL - LpOSTMUnitReg->ulCNT);
    /* consider the additional overflow when calculation the timer value */
    LusNrOfTimerOverflows = LusNrOfTimerOverflows + GPT_ONE;

  }
  else
  {
    /* No action required */
  }
  GPT_EXIT_CRITICAL_SECTION(GPT_TIMERREG_PROTECTION)
#else
  /* For the rest of the channels OSTM1-4 and OSTM5-9 or in case critical
   * sections are not enabled, instead of critical section, a double reading is
   * done to detect if an overflow occurred and interrupt was triggered.
   * The double reading relies on the fact that the interrupt function is
   * triggered and Gpt_GusPredefTimerNrOverflows is incremented inside the
   * interrupt function. The interrupt pending flag is also checked for the
   * purpose of deciding if the interrupt could be acknowledged, or
   * otherwise treat the case as overflow also.
   */
  do
  {
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE == GPT_PREDEF_TIMER_EI_INTR)
    if (GPT_CHECK_INTR_REQUEST_MASK ==
        ((uint16)(GPT_OSTM_INTR_REQ_REGISTER) & GPT_CHECK_INTR_REQUEST_MASK)
    )
    {
      LucInterruptPendingFlagBefore = GPT_TRUE;
    }
    else
    {
      LucInterruptPendingFlagBefore = GPT_FALSE;
    }
#else
  /* MISRA Violation: START Msg(4:0303)-8 */
  LulFeOSTMChannelInterruptMask =((uint32)(GPT_DOUBLE_ONE <<
          (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)));

  if (LulFeOSTMChannelInterruptMask ==
      (GPT_FEINT_FACTOR_REGISTER & LulFeOSTMChannelInterruptMask))
  /* END Msg(4:0303)-8 */
  {
    LucInterruptPendingFlagBefore = GPT_TRUE;
  }
  else
  {
    LucInterruptPendingFlagBefore = GPT_FALSE;
  }
#endif

    /* Implements SWS_Gpt_00397 */
    /* Store time value and number of overflows in local variables */
    /* Because the timer is counting downwards, the elapsed time is obtained
     * by subtracting the value of the count register from the maximum timer
     * value*/
    LulHWTimerValue = (GPT_MAX_OSTM_VAL - LpOSTMUnitReg->ulCNT);
    LusNrOfTimerOverflows = Gpt_GusPredefTimerNrOverflows;

    /* Check if a second reading of time returns a value lower than the first
     * reading. If true it means an overflow occurred and timer was restarted
     */
    LulHWTimerSecondValue = (GPT_MAX_OSTM_VAL - LpOSTMUnitReg->ulCNT);
    if (LulHWTimerValue > LulHWTimerSecondValue)
    {
      /* Exception case, timer just had an overflow, interrupt was triggered so
       * a new reading has to be done to assure consistency between count
       * register value and number of overflows.*/
      LulHWTimerValue = LulHWTimerSecondValue;
      /* reread the number of overflows which was processed in the interrupt
       * routine to assure consistency. */
      LusNrOfTimerOverflows = Gpt_GusPredefTimerNrOverflows;
    }
    else
    {
      /* normal case, no additional reading is needed */
    }

#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE == GPT_PREDEF_TIMER_EI_INTR)
    if (GPT_CHECK_INTR_REQUEST_MASK ==
        ((uint16)(GPT_OSTM_INTR_REQ_REGISTER) & GPT_CHECK_INTR_REQUEST_MASK)
    )
    {
      LucInterruptPendingFlagAfter = GPT_TRUE;
    }
    else
    {
      LucInterruptPendingFlagAfter = GPT_FALSE;
    }
#else
  /* MISRA Violation: START Msg(4:0303)-8 */
  LulFeOSTMChannelInterruptMask =((uint32)(GPT_DOUBLE_ONE <<
          (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)));

  if (LulFeOSTMChannelInterruptMask ==
      (GPT_FEINT_FACTOR_REGISTER & LulFeOSTMChannelInterruptMask))
  /* END Msg(4:0303)-8 */
  {
    LucInterruptPendingFlagAfter = GPT_TRUE;
  }
  else
  {
    LucInterruptPendingFlagAfter = GPT_FALSE;
  }
#endif
  } while (LucInterruptPendingFlagBefore != LucInterruptPendingFlagAfter );

  if (GPT_TRUE == LucInterruptPendingFlagAfter)
  {
    LusNrOfTimerOverflows = LusNrOfTimerOverflows + GPT_ONE;
  }
  else
  {
    /* do nothing */
  }
#endif
  /* Based on the resolution of each timer, a mask is applied to keep only the
   * needed data. In order to compensate for the higher resolution of the
   * hardware unit a division factor is used equal to the division between
   * the frequency of the hardware unit and the frequency of the Predef timer
   */
  switch (LddPredefTimer)
  {
  case GPT_PREDEF_TIMER_1US_16BIT:
      /* Implements SWS_Gpt_00384 */
      LusPredefTimerDivisionFactor = GPT_PREDEF_TIMER_DIVISION_FACTOR;
      /* Implements SWS_Gpt_00383 */
      /* Implements SWS_Gpt_00396 */
      LulPredefTimerMask =(uint32) GPT_16BIT_MASK;
    break;

  case GPT_PREDEF_TIMER_1US_24BIT:
      /* Implements SWS_Gpt_00384 */
      LusPredefTimerDivisionFactor = GPT_PREDEF_TIMER_DIVISION_FACTOR;
      /* Implements SWS_Gpt_00383 */
      /* Implements SWS_Gpt_00396 */
      LulPredefTimerMask =(uint32) GPT_24BIT_MASK;
    break;

  case GPT_PREDEF_TIMER_1US_32BIT:
      /* Implements SWS_Gpt_00384 */
      LusPredefTimerDivisionFactor = GPT_PREDEF_TIMER_DIVISION_FACTOR;
      /* Implements SWS_Gpt_00383 */
      /* Implements SWS_Gpt_00396 */
      LulPredefTimerMask =(uint32) GPT_32BIT_MASK;
    break;

  case GPT_PREDEF_TIMER_100US_32BIT:
    /* To compensate for the fact that the 100us timer is 100 slower than the
     * 1us resolution resulting when GPT_PREDEF_TIMER_DIVISION_FACTOR is applied
     * the value of the division factor is multiplied with 100 for 100us timer.
     */
      /* Implements SWS_Gpt_00384 */
      LusPredefTimerDivisionFactor =
        GPT_PREDEF_TIMER_DIVISION_FACTOR * GPT_PREDEF_100US_TIMER_RESOLUTION;
      /* Implements SWS_Gpt_00383 */
      /* Implements SWS_Gpt_00396 */
      LulPredefTimerMask =(uint32) GPT_32BIT_MASK;
    break;

  default:
      LusPredefTimerDivisionFactor = GPT_PREDEF_TIMER_DIVISION_FACTOR;
      /* force return of value 0 */
      LulPredefTimerMask = (uint32) (GPT_RET_VAL_ZERO);
    break;
  }
  /* In order to assure that there is no overflow of the timer e.g
   * for the 1us timer because of counting number of interrupts needed for
   * the 100 us timer which is 100 times slower or in the rare case when the
   * number of overflows exceeds the maximum allow value by 1 a limiting of the
   * number of overflows used in calculations is done by the used division
   * factor */
  /*Implements SWS_Gpt_00382 */
  LusNrOfTimerOverflows = LusNrOfTimerOverflows % LusPredefTimerDivisionFactor;

  /* Calculate the time based on the formula:
   * time = (TimerValue + (NrOfOverflows * TimerOverflowTime))/TimerFactor
   * Division reminder is also computed to avoid losing useful data during
   * division. Another alternative would have been using bigger data types than
   * 32 bits, needed because of multiplication.
   */
  /* Compute any reminder from the division with
   * LusPredefTimerDivisionFactor to compensate when calculating timer value */
  LulDivisionReminder = ((LulHWTimerValue % LusPredefTimerDivisionFactor) +
      (LusNrOfTimerOverflows  *
          (GPT_MAX_OSTM_VAL % LusPredefTimerDivisionFactor))) /
            LusPredefTimerDivisionFactor;

  /*Compute the value of the Predef timer and apply the mask */
  /* Implements SWS_Gpt_00396 */
  LddElapsedTime = (
      (LulHWTimerValue / LusPredefTimerDivisionFactor) +
      (LusNrOfTimerOverflows *
          (GPT_MAX_OSTM_VAL / LusPredefTimerDivisionFactor)) +
      LulDivisionReminder) & LulPredefTimerMask;

  /* Implements SWS_Gpt_00395 */
  /* The calculated timer is returned */
  return LddElapsedTime;
}
#define GPT_STOP_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*******************************************************************************
 ** Function Name        : Gpt_HW_StartPredefTimer
 **
 ** Service ID           : NA
 **
 ** Description          : This function starts and enables the interrupt for
 **                        the hardware channel used by Predef Timer function
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
 ** Preconditions        : This function is available only if the pre-compile
 **                        option GPT_PREDEF_TIMER_ENABLED is STD_ON
 **
 ** Global Variables used: Gpt_GusPredefTimerNrOverflows
 **
 ** Functions invoked    : GPT_ENTER_CRITICAL_SECTION,
 **                        GPT_EXIT_CRITICAL_SECTION
 **
 ** Registers Used       : OSTMnTS,OSTMnTE,OSTMnCMP,FEINTFC,FEINTFMSK
 **
 ******************************************************************************/
#define GPT_START_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*Implements GPT_ESDD_UD_157 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StartPredefTimer(void)
{

  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;

  /* Get address of HW unit register */
  LpOSTMUnitReg = Gpt_GpOSTMRegPredefTimer_BaseAddress;

  /* OSMT0 and OSTM5 used EI level interrupt, set ICR registers */
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE == GPT_PREDEF_TIMER_EI_INTR)
  /* MISRA Violation: START Msg(4:0303)-8 */
  /* Clear Interrupt control register */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0068 */
  RH850_SV_CLEAR_ICR_SYNCP(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_CLEAR_PENDING_INTR_MASK);
#else
  /* Implements EAAR_PN0034_FR_0067 */
  RH850_SV_MODE_ICR_AND(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_CLEAR_PENDING_INTR_MASK);
#endif
  /*Enable OSTM channel Interrupt */
  /* Implements EAAR_PN0034_FR_0067 */
  RH850_SV_MODE_ICR_AND(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_INTERRUPT_MASK_EN);
#else
  /*OSTM1-4 use FE interrupt registers */
  /* Set FEINT Factor Clear register to clear pending interrupt, 32bit write */
  GPT_FEINT_WRITE_ONLY(&GPT_FEINT_FACTOR_CLEAR_REGISTER, (GPT_DOUBLE_ONE <<
          (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)));

  /* Set FEINT Factor Mask Register to enable FE interrupt*/
  GPT_FEINT_WRITE_AND(&GPT_FEINT_FACTOR_MASK_REGISTER,((uint32)
      (~(GPT_DOUBLE_ONE <<
                  (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)))
      ));
  /* END Msg(4:0303)-8 */
#endif

  /* Load the compare register with maximum timer value for OSTM channels
   * Decrement 1 because the interval between interrupts is CMP+1
   * When reading the timer value +1 will be added to compensate for this
   * decrement*/

  GPT_OSTM_WRITE_REG_AND_MIRROR(&LpOSTMUnitReg->ulCMP,
      (GPT_MAX_OSTM_VAL - GPT_ONE),
      &Gpt_GstGptPredefTimerOSTMRegMirror.ulCMP)
  GPT_OSTM_CHECK_WRITE_VERIFY_RUNTIME(&LpOSTMUnitReg->ulCMP,
      (GPT_MAX_OSTM_VAL - GPT_ONE),
      GPT_32BIT_MASK,
      GPT_STARTPREDEFTIMER_API_ID)
  /* Start the OSTM timer*/
  GPT_WRITE_OSTM_MIRROR_ONLY(&Gpt_GstGptPredefTimerOSTMRegMirror.ucTE,
      LpOSTMUnitReg->ucTE | GPT_OSTM_START_MASK)
  GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTS, GPT_OSTM_START_MASK)
  /* TE register is updated after one clock cycle.
   * A Wait loop implementation is required instead of WriteVerify*/
  /* Implements EAAR_PN0034_FR_0084, EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
  LulTimeOutCount = GPT_TIMEOUT_COUNT;
  /* MISRA Violation: START Msg(4:2877)-4 */
  while ((GPT_RESET_LONG_WORD != LulTimeOutCount) &&
      (GPT_OSTM_START_MASK != (LpOSTMUnitReg->ucTE & GPT_OSTM_START_MASK)))
  /* END Msg(4:2877)-4 */
  {
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* MISRA Violation: START Msg(4:2880)-6 */
    LulTimeOutCount--;
    /* END Msg(4:2880)-6 */
    /* END Msg(4:2984)-5 */
  }
  if (GPT_OSTM_START_MASK != ((LpOSTMUnitReg->ucTE) &
          GPT_OSTM_START_MASK))
  /* In case the register is not updated in the expected time,
   * report and DEM error */
  {
    /* Implements GPT177, EAAR_PN0034_FR_0084 */
    Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
        ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
  }
  else
  {
    /* No action required */
  }

  /* Reset number of timer overflows when timer is started */
  Gpt_GusPredefTimerNrOverflows = (uint16)GPT_TIMER_RESET_VAL_ZERO;
}
#define GPT_STOP_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*******************************************************************************
 ** Function Name        : Gpt_HW_StopPredefTimer
 **
 ** Service ID           : NA
 **
 ** Description          : This function stops and disables the interrupt for
 **                        the hadrware channel used by Predef Timer function
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
 ** Preconditions        : This function is available only if the pre-compile
 **                        option GPT_PREDEF_TIMER_ENABLED is STD_ON
 **
 ** Global Variables used: Gpt_GusPredefTimerNrOverflows
 **
 ** Functions invoked    :
 **
 ** Registers Used       : OSTMnTT, OSTMnTE, FEINTFC, FEINTFMSK, ICOSTMn
 **
 ******************************************************************************/
#define GPT_START_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*Implements GPT_ESDD_UD_158 */
FUNC (void, GPT_PRIVATE_CODE) Gpt_HW_StopPredefTimer(void)
{
  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(volatile OSTMReg , AUTOMATIC, GPT_CONFIG_DATA)LpOSTMUnitReg;

  /* Get address of HW unit register */
  LpOSTMUnitReg = Gpt_GpOSTMRegPredefTimer_BaseAddress;

  /* Stop the timer OSTM */
  GPT_WRITE_OSTM_MIRROR_ONLY(&Gpt_GstGptPredefTimerOSTMRegMirror.ucTE,
      (LpOSTMUnitReg->ucTE & (uint8)(~GPT_OSTM_STOP_MASK)))
  GPT_WRITE_REG_ONLY(&LpOSTMUnitReg->ucTT, GPT_OSTM_STOP_MASK)
  /* Implements EAAR_PN0034_FR_0085, EAAR_PN0034_FR_0086 */
  /* Load loop count from configuration */
  LulTimeOutCount = GPT_TIMEOUT_COUNT;
  /* MISRA Violation: START Msg(4:2877)-4 */
  while ((GPT_RESET_LONG_WORD != LulTimeOutCount) && (GPT_RESET_BYTE !=
          (uint8)(LpOSTMUnitReg->ucTE & GPT_OSTM_STOP_MASK)))
  /* END Msg(4:2877)-4 */
  {
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Decrement the loop count */
    /* MISRA Violation: START Msg(4:2880)-6 */
    LulTimeOutCount--;
    /* END Msg(4:2880)-6 */
    /* END Msg(4:2984)-5 */
  }
  /* In case the register is not updated in the expected time,
   * report and DEM error */
  if (GPT_RESET_OSTM_TE_BYTE != (uint8)((LpOSTMUnitReg->ucTE)
      & GPT_OSTM_STOP_MASK))
  {
    /* Implements GPT177, EAAR_PN0034_FR_0084 */
    Dem_ReportErrorStatus(GPT_E_TIMEOUT_FAILURE,
        ((GPT_DEM_TYPE) DEM_EVENT_STATUS_FAILED));
  }
  else
  {
    /* No action required */
  }

  /* OSTM0 and OSTM5 used EI interrupt registers */
#if (GPT_PREDEF_TIMER_OSTM_HW_UNIT_TYPE == GPT_PREDEF_TIMER_EI_INTR)
  /* MISRA Violation: START Msg(4:0303)-8 */
  /* Disabling the Interrupt processing of OSTM EI interrupt channel */
  /* Implements EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0068 */
  RH850_SV_MODE_ICR_OR(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_INTERRUPT_MASK_DIS);
  /* Clear Interrupt control register */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  RH850_SV_CLEAR_ICR_SYNCP(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_CLEAR_PENDING_INTR_MASK);
#else
  /* Implements EAAR_PN0034_FR_0067 */
  RH850_SV_MODE_ICR_AND(16, (&GPT_OSTM_INTR_REQ_REGISTER),
      GPT_CLEAR_PENDING_INTR_MASK);
#endif
#else
  /*OSTM1-4 use FE interrupt registers */
  /* Set FEINT Factor Clear register to clear pending interrupt, 32bit write */
  GPT_FEINT_WRITE_ONLY(&GPT_FEINT_FACTOR_CLEAR_REGISTER, (GPT_DOUBLE_ONE <<
          (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)));

  /* Set FEINT Factor Mask Register to enable FE interrupt*/
  GPT_FEINT_WRITE_OR(&GPT_FEINT_FACTOR_MASK_REGISTER, (GPT_DOUBLE_ONE <<
          (GPT_OSTMFEINT_OFFSET + GPT_PREDEF_TIMER_OSTM_HW_UNIT_INDEX)));
  /* END Msg(4:0303)-8 */
#endif
  /* Reset number of timer overflows when timer is stopped */
  Gpt_GusPredefTimerNrOverflows = (uint16)GPT_TIMER_RESET_VAL_ZERO;

}
#define GPT_STOP_SEC_CODE_ASIL_B
#include GPT_MEMMAP_FILE
/*******************************************************************************
 ** Function Name        : Gpt_HW_PredefTimerCallbackNotification
 **
 ** Service ID           : NA
 **
 ** Description          : This function is called when the hardware channel
 **                        associated with Predef Timer expires.
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
 ** Preconditions        : This function is available only if the pre-compile
 **                        option GPT_PREDEF_TIMER_ENABLED is STD_ON
 **
 ** Global Variables used: Gpt_GusPredefTimerNrOverflows
 **
 ** Functions invoked    : None
 **
 ** Registers Used       : None
 **
 ******************************************************************************/
#define GPT_START_SEC_CODE_FAST_ASIL_B
#include GPT_MEMMAP_FILE
/*Implements GPT_ESDD_UD_159, EAAR_PN0080_FR_0016 */
FUNC (void, GPT_FAST_CODE) Gpt_HW_PredefTimerCallbackNotification(void)
{
  /* The only purpose of the callback function for Predef timer is to count
   * the number of overflows the hardware unit had.
   */
  /* GPT_PREDEF_TIMER_RESET_LIMIT, limits the calculations done when computing
   * the values of the timer to 32 bits. The value is obtained from dividing
   * the frequency of the hardware unit with the frequency of the slowest Predef
   * timer( 100us) */
  if ( Gpt_GusPredefTimerNrOverflows < GPT_PREDEF_TIMER_RESET_LIMIT )
  {
    /* As long as overflow limit is not reached, increment the number of
     * occurred overflows
     */
    Gpt_GusPredefTimerNrOverflows++;
  }
  else
  {
    /* Implements SWS_Gpt_00382 */
    /* reset the number of overflows to avoid getting out of 32 bit range
     * during computation of the Predef timers values
     * */
    Gpt_GusPredefTimerNrOverflows = (uint16)GPT_TIMER_RESET_VAL_ZERO;
  }
}
#define GPT_STOP_SEC_CODE_FAST_ASIL_B
#include GPT_MEMMAP_FILE

#endif /* End of (GPT_PREDEF_TIMER_ENABLED == STD_ON)*/
#endif /* End of (GPT_AR_HIGHER_VERSION == GPT_AR_VERSION) */

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
