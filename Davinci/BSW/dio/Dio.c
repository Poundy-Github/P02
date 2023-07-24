/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Dio Driver Component.            */
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

/* Implements EAAR_PN0034_NR_0045 */
/*******************************************************************************
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version.
 *
 * V1.0.1:  03-Dec-2015  : As part of F1K_Ver_4.00.01 activity following changes
 *                         are made:
 *                        1) As per JIRA Ticket ARDAAGA-91, usPPR register name
 *                           is changed as usIPPR.
 *                        2) As per JIRA Ticket ARDAAGA-74, Version Info API
 *                           update from macro to function implementation.
 *                        3) As per JIRA Ticket ARDAAGA-89, DIO_ANALOGPORT
 *                           check is added in  Dio_WritePort, Dio_WriteChannel,
 *                           Dio_FlipChannel, Dio_WriteChannelGroup,
 *                           Dio_MaskedWritePort API's.
 *                        4) As per JIRA Ticket ARDAAGA-90, the type conversion
 *                           removed for the Flip channel API while loading the
 *                           value PNOT register.
 *                        5) Updates made to avoid few warning after the MISRA
 *                           analysis.
 * V1.0.2:  14-Sep-2016  : As part of ARDAABC-882 Jira Ticket, the following
 *                         changes are made:
 *                        1) Updated registers write to use the macros for
 *                           Write-Verify and RAM Mirror (ticket ARDAABC-754).
 *                        2) Added code to update the RAM Mirror if activated
 *                           and if PNOT registers are written.
 *                        3) Added Dio_CheckHWConsistency public function
 *                           and Dio_InitRamMirror private function, which are
 *                           enabled when RAM Mirror is used.
 * V2.0.0:  03-Oct-2016  : As part of ARDAABC-836 Jira Ticket,
 *                         the following changes are made:
 *                        1) Compiler switch introduced to prevent
 *                           compilation errors in case only analog or JTAG
 *                           or input ports had been configured.
 * V2.0.1:  24-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                            the following changes are made:
 *                        1) Removed AR 3.2.2 related functionality and
 *                           added AR 4.2.2 where applicable.
 *                        2) Static code analysis related code changes
 *                        3) Dio_MaskedWritePort() API removed
 * V2.0.2   03-Jan-2017  :  As part of ARDAABC-836 Jira ticket,
 *                          the following changes made
 *                        1) Compilation errors and warnings occurred
 *                           when only JTAG port or Analog port is configured
 *                        2) Removed precompile switch DIO_NUM_OF_PORTREG from
 *                           reading the port value from JPPR register of
 *                           JTAG Port in Dio_ReadPort API
 *                        3) Updated revision history
 * V2.0.3   04-Jan-2017  :  As part of ARDAABC-595 Jira ticket,
 *                          the following changes made:
 *                        1) Updated the traceability tags to the required
 *                           format.
 * V2.0.4   04-Jan-2017  : As part of ARDAABC-919 Jira ticket the following
 *                         changes made:
 *                        1) DIO_CHECK_HW_CONSISTENCY_SID has been added to
 *                           function's header comment
 * V2.0.5   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                        1) Removed outdated AUTOSAR version related comments
 *                        2) Updated copyright dates
 * V2.0.6   09-Jan-2017  : As part of ARDAABC-547 Jira ticket the following
 *                         changes made:
 *                        1) Updated traceability tags.
 * V2.0.7   10-Jan-2017  : As part of ARDAABC-626 and ARDAABC-882 Jira ticket
 *                         the following changes made:
 *                        1) Dio_InitRamMirror API has been defined as extern
 *                           function
 *                        2) Dio_Init API has been defined as a 4.0.3 related
 *                           API based on the AUTOSAR specification
 * V2.0.8   16-Jan-2017  : As part of ARDAABC-764 Jira ticket the following
 *                         changes made:
 *                        1) Ram mirroring functionality related compiler
 *                           switches introduced
 * V2.0.9   17-Jan-2017  : As part of ARDAABC-707 Jira ticket the following
 *                         changes made:
 *                        1) Ram mirroring DIO_CHECK_WRITE_VERIFY_RUNTIME
 *                           macro mask update for the respective register
 *                           writing actions
 *                        2) Compiler abstraction macros usage introduced
 * V2.0.10   18-Jan-2017  : As part of ARDAABC-778 Jira ticket the following
 *                         changes made:
 *                        1) DIO_RAM_MIRROR == DIO_RAM_MIRROR_ENABLE compiler
 *                           switch has been rearranged
 * V2.0.11  23-Jan-2017  : As part of ARDAABC-707 Jira ticket the following
 *                         changes made:
 *                        1) Compiler abstraction macros had been introduced
 *                           in a correct format.
 *                        2) RAM mirroring related compiler switches changed
 *                           due to bug found via functional testing
 * V2.0.12  24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                        1) Header comment updated due to acceptance team
 *                           comment
 * V2.0.13  25-Jan-2017  : As part of ARDAABC-707 Jira ticket the following
 *                         changes made:
 *                        1) In check write verify macros the API ID has been
 *                           replaced by the SID according to acceptance
 *                           finding.
 * V2.0.14  25-Jan-2017  : As part of ARDAABC-926 Jira ticket the following
 *                         changes made:
 *                        1) Revert the changes made in Jira ticket ARDAABC-707
 *                           because of the remark added in ticket 926 in
 *                           F1K_FUSA_ParameterNaming.xlsx.
 * V2.0.15: 27-Jan-2017  : Following changes are made:
 *                        1) As part ARDAABC-324, DIO related memmap changes
 *                           o support new code section location and to remove
 *                           sections with non conform names. Dio_InitRAMMirror
 *                           API related changes also done.
 * V2.0.16: 12-Feb-2017  : Following changes are made:
 *                        1) As part of ARDAABC-753, macro names were corrected
 *                        2) As part of ARDAABC-626, Dio_Init function added
 *                           for ASR 4.2.2
 *                        3) As part of ARDAABC-324, private code section
 *                           defined for Dio_InitRamMirror function
 *                        4) As part of ARDAABC-707, write verify mechanism
 *                           was corrected
 *                        5) Formatted code according to guidelines
 * V2.0.17: 13-Feb-2017  : Following changes are made:
 *                        1) As part of ARDAABC-753, RAM mirroring functionality
 *                           was updated
 *                        2) As part of ARDAABC-630, code was updated after QAC
 *                           analysis
 * V2.0.18: 15-Feb-2017  : Following changes are made:
 *                        1) As part of ARDAABC-947, if Dio_WriteChannelGroup
 *                           function is called with NULL_PTR, if DET is
 *                           enabled DIO_E_PARAM_POINTER error id is
 *                           generated
 * V2.0.19: 16-Feb-2017  : Following changes are made:
 *                        1) As part of ARDAABC-947, if Dio_ReadChannelGroup
 *                           function is called with NULL_PTR, if DET is
 *                           enabled DIO_E_PARAM_POINTER error id is
 *                           generated
 * V2.0.20: 16-Feb-2017  : Following changes are made:
 *                        1) As part of ARDAABC-753, Dio_CheckHWConsistency
 *                           updated according with coding guidelines
 * V2.0.21: 19-Feb-2017  : As part of ARDAABC-926 Jira ticket, code was
 *                         updated due to traceability
 * V2.0.22: 03-Mar-2017  : As part of ARDAABC-707 Jira ticket, FuSa
 *                         functionality was corrected.
 * V2.0.23: 13-Jun-2017  : As part of ARDAABD-1892 Jira ticket, code was
 *                         updated after QAC analysis
 * V2.0.24: 27-Jul-2017  : Following changes are made:
 *                         1) As part of ARDAABD-1352, variable LddPortLevel,
 *                            initialized outside the DIO_DEV_ERROR_DETECT
 *                            condition check.
 *                         2) As part of ARDAABD-1734, precompile switches
 *                            added for separating R4.0.3 and R4.2.2 codes
 *                         3) As part of ARDAABD-1353, variable
 *                            LusChGrpPtrValue initialized to DIO_ZERO
 *                            in API's Dio_WriteChannelGroup and
 *                            Dio_ReadChannelGroup .
 *                         4) As per JIRA ticket ARDAABD-1390,removed entry
 *                            and exit of critical sections from function
 *                            Dio_InitRamMirror.
 *                         5) MISRA justifications added after QAC Analysis.
 * V2.0.25: 07-Aug-2017  : Following changes are made:
 *                         1) As part of ARDAABD-2232, precompile switches
 *                            added for separating R4.0.3 and R4.2.2 codes
 *                            in Dio_InitRamMirror API and Updated Preconditions
 *                            in Function banner.
 *                         2) As part of ARDAABD-2198, Style_Format
 *                            corrected for comments and conditions.
 * V2.1.0: 31-Oct-2017   : Following changes are made:
 *                         1) As per ARDAABD-2380, macro DIO_ZERO
 *                            renamed to DIO_LOW_LEVEL_OUTPUT and
 *                            DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK in respective
 *                            places. DIO_ONE renamed to DIO_HIGH_LEVEL_OUTPUT.
 *                            DioPortReg_BaseAddress renamed to
 *                            Dio_GaaPortReg_BaseAddress.
 *                            DioJPortReg_BaseAddress renamed to
 *                            Dio_GaaJPortReg_BaseAddress.
 *                            DioAPortReg_BaseAddress renamed to
 *                            Dio_GaaAPortReg_BaseAddress.
 *                            DioIPortReg_BaseAddress renamed to
 *                            Dio_GaaIPortReg_BaseAddress,LusLevel renamed to
 *                            LddLevel and LusPortLevel renamed to LddPortLevel,
 *                            LenDetErrFlag renamed to LddDetErrFlag and
 *                            LucCheckStatus renamed to LddCheckStatus.
 *                         2) As per ARDAABD-2156, Dio_MaskedWritePort API
 *                            added.
 *                         3) As per ARDAABD-2273,Dio_ReadChannelOutputValue
 *                            and Dio_ReadChannelGroupOutputValue API's are
 *                            added.
 *                         4) As per ARDAABD-2507,Det Error check for invalid
 *                            database DIO_E_INVALID_DATABASE added.
 *                         5) As per ARDAABD-1845,modified Ram Mirroring
 *                            in Dio_WriteChannelGroup API.
 *                         6) As part of ARDAABD-2529, space is added between
 *                            'if' and parenthesis , updated function banner of
 *                            Dio_InitRamMirror API.
 *                         7) As part of QAC analysis , MISRA C rule violation
 *                            comment added for Msg(4:4397) and QAC warning
 *                            comment added for Msg(2:2922).
 *                         8) As part of ARDAABD-2667, modified Port group acess
 *                            in Dio_MaskedWritePort API.
 *                         9) As part of ARDAABD-2556, unwanted MISRA C rule
 *                            message tags have been removed.
 * V2.1.1: 25-May-2018   : Following changes are made:
 *                         1) As part of ARDAABD-3707,Following changes are made:
 *                            Add RH850_DUMMY_READ_SYNCP()to fix the fault
 *                            synchronization at the timing when control shifts
 *                            from MCAL to application.
 * V2.1.2: 24-Jul-2018   : Following changes are made:
 *                         1) As part of Merging activity,ARDAABD-3484
 *                            a.Removed complementation of variable 'Mask'in
 *                              Dio_MaskedWritePort API:Ref:ARDAABD-2891.
 *                            b.As part of QAC analysis , QAC warning comment
 *                              added for Msg(2:3892)and removed unwanted
 *                              QAC warning and MISRA justification.
 *                            c.Updated traceability.
 *                         2) As part of ARDAABD-3634, List of used registers
 *                            in function headers are made inline with
 *                            implementation.
 *                         3) As part of ARDAABD-2513, Write verification of
 *                            PNOT register is implemented in
 *                            Dio_FlipChannel API
 *                         4) As part of ARDAABD-2990,
 *                            a.Dio_InitRamMirror API API has been removed and
 *                              modified Dio_CheckHWConsistency API to check
 *                              status of hardware consistency check for
 *                              Dio module as E_OK.
 *                            b.Removed Dio_InitRamMirror from Dio_Init,
 *                              Dio_WritePort,Dio_WriteChannel,Dio_FlipChannel,
 *                              Dio_WriteChannelGroup,Dio_MaskedWritePort APIs.
 *                         5) As part of ARDAABD-3851 to improve traceability,
 *                            a.Removed all the redundant and obsolete
 *                              requirements.
 *                            b.Added missing requirements from requirement
 *                              documents.
 * V2.1.3: 15-Oct-2018   : Following changes are done : 
 *                         1) As part of ARDAABD-3707, ICP0 usage error
 *                            modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to 
 *                            RH850_DUMMY_READ_SYNCP(16, &(ICP0)) and change
 *                            the place of RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 *                            to the end of function.
 * V2.1.4:  18-Oct-2018 : As part of ARDAABD-3707
 *                        Remove the RH850_DUMMY_READ_SYNCP Marco
 * V2.1.5:  03-Jul-2019  : Following changes are done : 
 *                         1) As part of ARDAABD-2513
 *                            the PPR register associated with the write check 
 *                            operation of the PNOT register is changed to
 *                            register P in Dio_FlipChannel function.
 *                         2) Copyright updated.
 */
/******************************************************************************/

/* Suppress the memory mapping related messages because the inclusion of the
 * memory mapping header is necessary.
 */

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
/* Included for macro definitions and API prototypes */
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0065, EAAR_PN0034_NR_0018*/
/* Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0020*/
/* Implements EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_FR_0018*/
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0007*/
/* Implements EAAR_PN0061_FR_0021, EAAR_PN0061_FR_0015 */
/* Implements EAAR_PN0061_FR_0001, DIO117, DIO141_Conf, DIO152_Conf*/
/* Implements SWS_Dio_00117, ECUC_Dio_00141, ECUC_Dio_00152 */
#include "Dio.h"
/* Implements DIO179, DIO142_Conf, DIO194, ECUC_Dio_00142, DIO194*/
/* Implements DIO_ESDD_UD_006*/
#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Implements DIO066, DIO194, SWS_Dio_00194 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Det.h"
#endif

/* Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0066*/
/* Implements EAAR_PN0034_FR_0061*/
/* Implements DIO_ESDD_UD_017*/
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
/* Implements DIO117, SWS_Dio_00117, DIO171 */
#include "SchM_Dio.h"
#endif

#include "Dio_RegWrite.h"

/* Included for I/O Registers */
#include "Iocommon_Defines.h"
/* Included for the macro declaration of supervisor mode(SV) write enabled
    Registers ICxxx */
#include "rh850_Types.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* AUTOSAR release version information */
#define DIO_C_AR_RELEASE_MAJOR_VERSION     DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_MINOR_VERSION     DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_REVISION_VERSION  DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* Software version information */
#define DIO_C_SW_MAJOR_VERSION    2
#define DIO_C_SW_MINOR_VERSION    0

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
/* Implements DIO106 */
#if (DIO_AR_RELEASE_MAJOR_VERSION != DIO_C_AR_RELEASE_MAJOR_VERSION)
#error "Dio.c : Mismatch in Release Major Version"
#endif

/* Implements DIO106 */
#if (DIO_AR_RELEASE_MINOR_VERSION != DIO_C_AR_RELEASE_MINOR_VERSION)
#error "Dio.c : Mismatch in Release Minor Version"
#endif

#if (DIO_AR_RELEASE_REVISION_VERSION != DIO_C_AR_RELEASE_REVISION_VERSION)
#error "Dio.c : Mismatch in Release Revision Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION)
#error "Dio.c : Mismatch in Software Major Version"
#endif

#if (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION)
#error "Dio.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                      Global Data                                          **
 ******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-1 and                           */
/*                 END Msg(4:0306)-1 tags in the code.                        */
/******************************************************************************/
/* 2.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982)This assignment is redundant. The value of this    */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable needs to be initialized before using it.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-2 and                           */
/*                 END Msg(4:2982)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION::                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-3 and                           */
/*                 END Msg(4:0303)-3 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
 **                        QAC Warning                                        **
 ******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC WARNING:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is             */
/*                  redundant                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Inclusion of the Det.h and MemMap.h file                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/
/* 3.  QAC Warning:                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-3 and                           */
/*                 END Msg(2:2814)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter is never modified and so it could   */
/*                 be declared with the 'const' qualifier.                    */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Parameter is not declared with the 'const' qualifier in    */
/*                 order to respect AUTOSAR SWS and module requirements.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3227)-4 and               */
/*                 END Msg(2:3227)-4 tags in the code.                        */
/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                  to another type                                           */
/* Rule          : No MISRA-C:2004 Rule                                       */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                 the post build configuration                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-5 and                           */
/*                 END (2:3892)-5 tags in the code.                           */
/******************************************************************************/
/**                  Function Prototypes                                      **
 ******************************************************************************/
/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/
/*******************************************************************************
 ** Function Name         : Dio_GetVersionInfo
 **
 ** Service ID            : 0x12
 **
 ** Description           : This API returns the version information of DIO
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
 ** Output Parameters     : Versioninfo
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
/* Implements EAAR_PN0061_FR_0023, EAAR_PN0034_FR_0092, EAAR_PN0034_NR_0088 */
/* Implements DIO_ESDD_UD_007 */
/* Implements DIO126, DIO124, DIO143_Conf, ECUC_Dio_00143 */
#if (DIO_VERSION_INFO_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_FR_0051 */
/* Implements DIO139, SWS_Dio_00139 */
/* Implements DIO189, SWS_Dio_00189 */
/* Implements DIO_ESDD_UD_048 */
FUNC(void, DIO_PUBLIC_CODE) Dio_GetVersionInfo(
              CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DIO_CONST) versioninfo)
{
  /* Implements DIO123, SWS_Dio_00139 */
  /* Check if parameter passed is not equal to Null pointer */
  if (NULL_PTR != versioninfo)
  {
    /* Copy the vendor Id */
    versioninfo->vendorID             = (uint16)DIO_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID             = (uint16)DIO_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version     = DIO_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version     = DIO_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version     = DIO_SW_PATCH_VERSION;
  }
  else
  {
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET  */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_032 */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_GET_VERSION_INFO_SID,
                          DIO_E_PARAM_POINTER);
    #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  }
}
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* (DIO_VERSION_INFO_API == STD_ON) */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_Init
 **
 ** Service ID            : 0x10
 **
 ** Description           : This service initialize the DIO driver.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Non-Reentrant
 **
 ** Input Parameters      : ConfigPtr Pointer to the configuration
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return Parameter      : None
 **
 ** Preconditions         : None
 **
 ** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GusChannelOffset
 **                         Dio_GblDriverStatus(R4.0).
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : None
 ******************************************************************************/
/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements SWS_Dio_00061, DIO166, DIO165, DIO179, DIO066*/
/* Implements DIO001, SWS_Dio_00001, EAAR_PN0034_NR_0069, EAAR_PN0034_FR_0016 */
/* Implements EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0063, EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_NR_0088, DIO_ESDD_UD_049 */
/* Implementation Of Dio_Init API */
FUNC(void, DIO_PUBLIC_CODE) Dio_Init(
                   CONSTP2CONST(Dio_ConfigType, AUTOMATIC, DIO_CONST) ConfigPtr)
{
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements DIO140, DIO176, DIO167*/
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_030 */
    /* Report Error to DET, if the config pointer value is NULL */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_INIT_SID,
                          DIO_E_PARAM_CONFIG);
    #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Check whether the existing database is correct */
    if (DIO_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    {
      /* Initialize the Port group configuration global pointer */
      Dio_GusPortOffset = ConfigPtr->usPortOffset;

      /* Implements DIO_ESDD_UD_008 */
      #if (DIO_CHANNEL_CONFIGURED == STD_ON)
      /* Initialize the Port channel configuration global pointer */
      Dio_GusChannelOffset = ConfigPtr->usChannelOffset;
      #endif

      /* Implements DIO_ESDD_UD_009 */
      #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
      /* Implements DIO056, SWS_Dio_00056 */
      /* Initialize the config pointer value to global pointer */
      Dio_GusChannelGroupsOffset = ConfigPtr->usChannelGroupsOffset;
      #endif

      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Set the state of DIO Driver as initialized */
      Dio_GblDriverStatus  = DIO_INITIALIZED;
      #endif
    }
    else
    {
      /* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0016 */
       /* Implements DIO_ESDD_UD_037 */
      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_033 */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
                                                     DIO_E_INVALID_DATABASE);
       #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
    }
  }
}
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_CODE
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif/* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)  */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_ReadPort
 **
 ** Service ID            : 0x02
 **
 ** Description           : This service returns the level of all channels of
 **                         given Port.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : PortId
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Returns the value of physical level of the channels
 **                         that form the Port.
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GstPortGroup, Dio_GusPortOffset.
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : PPRn, JPPR0, APPRn, IPPR0
 ******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_NR_0020, EAAR_PN0034_FR_0081 */
/* Implements EAAR_PN0034_NR_0002, DIO051, DIO005, DIO127, DIO060, DIO142_Conf*/
/* Implements DIO012, DIO118, DIO013, DIO135, DIO031, DIO104, DIO144_Conf */
/* Implements SWS_Dio_00051, SWS_Dio_00005, SWS_Dio_00127, SWS_Dio_00104 */
/* Implements SWS_Dio_00060, SWS_Dio_00012, SWS_Dio_00031, SWS_Dio_00118 */
/* Implements SWS_Dio_00013, SWS_Dio_00135, ECUC_Dio_00142, ECUC_Dio_00144*/
/* Implements EAAR_PN0061_FR_0004, EAAR_PN0061_FR_0005, EAAR_PN0061_FR_0002 */
/* Implements DIO_ESDD_UD_044, DIO_ESDD_UD_011 */
/* Implementation Of Dio_ReadPort API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort(
                                          CONST(Dio_PortType, AUTOMATIC) PortId)
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0081, DIO066 */
/* Implements EAAR_PN0034_NR_0069 */
{
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST) LpPortGroup;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  Dio_PortLevelType LddPortLevel;
  uint16 LusPortId;
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddDetErrFlag;
  #endif
  /* Initialize the return value to 0 */
  /* MISRA Violation: START Msg(4:2982)-2 */
  LddPortLevel = DIO_LOW_LEVEL_OUTPUT;
  /* END Msg(4:2982)-2 */
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  LddDetErrFlag = E_NOT_OK;
  /*Check whether the Autosar version is R4.0.3*/
  #if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
   (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_READ_PORT_SID,
                          DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif /* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_014 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
    /* Implements DIO065, SWS_Dio_00065, DIO075, SWS_Dio_00075 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_028 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_READ_PORT_SID,
                          DIO_E_PARAM_INVALID_PORT_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO118, SWS_Dio_00118 */
  /* Check if no DET error was reported */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
     /* Implements EAAR_PN0061_FR_0004 */
    /* Get the pointer to the required Port */
    LusPortId = Dio_GusPortOffset + PortId;
    /* Implements DIO_ESDD_UD_035 */
    LpPortGroup = &Dio_GstPortGroup[LusPortId];

    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    /* Get the PSRn or JPSRn address for the required port */
    LusDioPortGroupIndex    = LpPortGroup->ucPortGroupIndex;
    #endif

    /* Check if the required port is Numeric/ AlphaNumeric port */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO104, SWS_Dio_00104 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /* Read the port value from PPR register of Numeric Port */
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usPPR);
      #endif
    }

    /* Check if the required port is JTAG port */
    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO104, SWS_Dio_00104 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Read the port value from JPPR register of JTAG Port */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJPPR);
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO104, SWS_Dio_00104 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /* Read the port value from APPR register of ANALOG Port */
      LddPortLevel = (Dio_PortLevelType)
                    (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAPPR);
    }
    #endif
    else
    {
      #if (DIO_INPUT_PORT_CONFIGURED == STD_ON)
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO104, SWS_Dio_00104 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /* Read the port value from IPPR register  */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaIPortReg_BaseAddress->usIPPR);
      /* END Msg(2:2814)-3 */
      #else
      LddPortLevel = (Dio_PortLevelType)DIO_LOW_LEVEL_OUTPUT;
      #endif
    }
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  /* Implements DIO031, SWS_Dio_00031 */
  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the Port Level */
  return(LddPortLevel);
}
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_WritePort
 **
 ** Service ID            : 0x03
 **
 ** Description           : This service writes the specified level to all the
 **                         channels in given Port.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : PortId and Level.
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GstPortGroup, Dio_GusPortOffset.
 **
 ** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
 **                         DIO_EXIT_CRITICAL_SECTION.
 **
 ** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, APMSRn ,JPMSR0.
 ******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0023, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0052*/
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0081, EAAR_PN0034_NR_0002 */
/* Implements EAAR_PN0034_FR_0049*/
/* Implements DIO051, DIO005, DIO127, DIO064, DIO060, DIO070, DIO109, DIO007*/
/* Implements DIO004, DIO136, DIO034, DIO035, DIO105, DIO108 */
/* Implements DIO142_Conf, DIO144_Conf, ECUC_Dio_00144, SWS_Dio_00108*/
/* Implements SWS_Dio_00051, SWS_Dio_00005, SWS_Dio_00127, SWS_Dio_00060 */
/* Implements SWS_Dio_00064, SWS_Dio_00070, SWS_Dio_00109, SWS_Dio_00007 */
/* Implements SWS_Dio_00104, SWS_Dio_00136, SWS_Dio_00034, SWS_Dio_00035 */
/* Implements ECUC_Dio_00142 */
/* Implements EAAR_PN0061_FR_0004, EAAR_PN0061_FR_0005 */
/* Implements DIO_ESDD_UD_045, DIO_ESDD_UD_011 */
/* Implementation of the Dio_WritePort API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort(
                                  CONST(Dio_PortType,         AUTOMATIC) PortId,
                                  CONST(Dio_PortLevelType,    AUTOMATIC) Level)
{
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST) LpPortGroup;
  uint16 LusDioPortGroupIndex;
  uint32 LulPortModeLevel;
  uint32 LulPSRContent;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  /*Check whether the Autosar version is R4.0.3*/
  #if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_PORT_SID,
                          DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif/* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_014 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
    /* Implements DIO075, SWS_Dio_00075 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_028 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_PORT_SID,
                          DIO_E_PARAM_INVALID_PORT_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO119, SWS_Dio_00119 */
  /* Check whether the PortType is INPUT port */
  if (E_NOT_OK == LddDetErrFlag)
  {
     /* Implements EAAR_PN0061_FR_0004 */
    /* Get the pointer to the required Port */
    LusDioPortGroupIndex = Dio_GusPortOffset + PortId;
    LpPortGroup = &Dio_GstPortGroup[LusDioPortGroupIndex];

    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
      /* Implements DIO075, SWS_Dio_00075 */
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_028 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_WRITE_PORT_SID,
                            DIO_E_PARAM_INVALID_PORT_ID);
      LddDetErrFlag = E_OK;
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

  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
    LusDioPortGroupIndex = Dio_GusPortOffset + PortId;
    /* Implements DIO_ESDD_UD_035 */
    LpPortGroup = &Dio_GstPortGroup[LusDioPortGroupIndex];
    #endif /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* Implements DIO070, SWS_Dio_00070 */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LulPortModeLevel =(uint32)
                ((Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPMSR)|
                                                 (LpPortGroup->ulModeMask));
      #endif
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* QAC Warning: START Msg(2:2814)-3 */
      LulPortModeLevel =(uint32)((Dio_GaaJPortReg_BaseAddress->ulJPMSR)|
                                 (LpPortGroup->ulModeMask));
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      LulPortModeLevel =(uint32)
            ((Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPMSR)|
                                         (LpPortGroup->ulModeMask));
    }
    #endif

    else
    {
      LulPortModeLevel = (uint32)DIO_LOW_LEVEL_OUTPUT;
    }

    LulPortModeLevel = LulPortModeLevel | DIO_SET_MASK_UPPER_SIXTEEN;
    /* Implements DIO035, SWS_Dio_00035 */
    /* Implements DIO004, SWS_Dio_00004 */
    /* Implements DIO108, SWS_Dio_00108 */
    /* If the requested channel is an output Channel */
    if ((uint32)DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK != (~LulPortModeLevel))
    {
      LulPSRContent = (((uint32)Level & (~(LulPortModeLevel))) |
                                  (~(LulPortModeLevel) * DIO_SHIFT_SIXTEEN));
      /* Implements DIO105, SWS_Dio_00105 */
      /* Implements EAAR_PN0061_FR_0001 */
      /*
       * Write the Port value using 32-bit PSR register
       * Enable upper 16-bits using mask to effectively
       * write to lower 16-bits
       */
      if (DIO_NORMALPORT == LpPortGroup->ucPortType)
      {
        #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
        DIO_WRITE_REG_ONLY(
                       &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                       LulPSRContent)
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                       &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                       (uint32)Level & (~(LulPortModeLevel)),
                        ~(LulPortModeLevel),
                        DIO_WRITEPORT_API_ID)
        #endif
      } /* DIO_NORMALPORT equals to LpPortGroup->ucPortType */

      #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
      else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        LulPSRContent)
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        (uint32)Level & (~(LulPortModeLevel)),
                        ~(LulPortModeLevel),
                        DIO_WRITEPORT_API_ID)
      }
      #endif

      #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
      else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     LulPSRContent)
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     (uint32)Level & (~(LulPortModeLevel)),~(LulPortModeLevel),
                      DIO_WRITEPORT_API_ID)
      }
      #endif
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* No action required */
    }
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif  
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_ReadChannel
 **
 ** Service ID            : 0x00
 **
 ** Description           : This service returns the value of the specified
 **                         DIO Channel.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelId
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
 **                         physical level of the Pin
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GblDriverStatus(R4.0), Dio_GstPortChannel,
 **                         Dio_GstPortGroup, Dio_GusPortOffset.
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : PPRn, JPPRn, APPRn, IPPRn.
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO012, SWS_Dio_00012, DIO011 */
/* Implements SWS_Dio_00011, DIO133, SWS_Dio_00133, EAAR_PN0061_FR_0007 */
/* Implements DIO027, SWS_Dio_00027, DIO060, SWS_Dio_00060, ECUC_Dio_00146 */
/* Implements DIO083, SWS_Dio_00083, DIO180, SWS_Dio_00180, DIO146_Conf */
/* Implements EAAR_PN0061_FR_0017, DIO_ESDD_UD_042, DIO_ESDD_UD_036 */
/* Implementation of the Dio_ReadChannel API */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel(
                                CONST(Dio_ChannelType, AUTOMATIC) ChannelId )
 /* Implements DIO171 ,DIO128, DIO060, DIO023, DIO182, DIO118, DIO013, DIO089 */
 /* Implements DIO011, DIO133, DIO185, DIO005, DIO026, DIO103, DIO015, DIO017 */
 /* Implements DIO027, DIO051, DIO083, DIO084, DIO074, DIO175, DIO140, DIO179 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0061_FR_0002, EAAR_PN0034_FR_0052 */
 /* Implements EAAR_PN0034_NR_0069, DIO066, SWS_Dio_00026 */
{
  Dio_LevelType LddLevel;

  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST)   LpPortGroup;
  P2CONST(Dio_PortChannel, AUTOMATIC, DIO_CONFIG_CONST) LpPortChannel;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  uint16 LusTempIndex;
  Dio_PortLevelType LddPortLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements DIO089, SWS_Dio_00089 */
  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /*start of (DIO_DEV_ERROR_DETECT == STD_ON) && \
             (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)*/
  #if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                     (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
     /* Implements DIO140, SWS_Dio_00140 */
     /* Implements DIO_ESDD_UD_010 */
     /* Report Error to DET */
     (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,
                           DIO_E_UNINIT);
     /* Implements DIO_ESDD_UD_008 */
     #if (DIO_CHANNEL_CONFIGURED == STD_ON)
     LddDetErrFlag = E_OK;
     #endif
  }
  else
  {
     /* No action required */
  }
  #endif/* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_015 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  {
    /* Implements DIO140, SWS_Dio_00140, DIO175, SWS_Dio_00065 */
    /* Implements DIO065, SWS_Dio_00065, DIO074, SWS_Dio_00074 */
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_READ_CHANNEL_SID,
                          DIO_E_PARAM_INVALID_CHANNEL_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO118, SWS_Dio_00118 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    /* Implements DIO_ESDD_UD_035 */
    LpPortGroup = &Dio_GstPortGroup[LusTempIndex];

    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif

    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from PPR register of Numeric Port
       */
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usPPR);
      #endif
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    /* Check if the required port is JTAG port */
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from JPPR register by adding offset to
       * PSR register address of JTAG Port
       */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJPPR);
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from APPR register of ANALOG Port
       */
      LddPortLevel = (Dio_PortLevelType)
                    (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAPPR);
    }
    #endif

    else
    {
      #if (DIO_INPUT_PORT_CONFIGURED == STD_ON)
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /* Read the port value from IPPR register */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaIPortReg_BaseAddress->usIPPR);
      /* END Msg(2:2814)-3 */
      #else
      LddPortLevel = (Dio_PortLevelType)DIO_LOW_LEVEL_OUTPUT;
      #endif
    }
    /* Implements EAAR_PN0061_FR_0006 */
    /*
     * Mask the port level value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    if (DIO_LOW_LEVEL_OUTPUT != LddPortLevel)
    {
      /* Implements DIO089, SWS_Dio_00089 */
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
  }

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO175, SWS_Dio_00065 */
  /* Implements DIO065, SWS_Dio_00065, DIO074, SWS_Dio_00074 */
  /* Report Error to DET */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
  (void)Det_ReportError(DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_SID,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements DIO027, SWS_Dio_00027 */
  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the Channel Level */
  return LddLevel;
}
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_WriteChannel
 **
 ** Service ID            : 0x01
 **
 ** Description           : This service writes the given value into the
 **                         specified DIO Channel.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelId and Level.
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GblDriverStatus(R4.0), Dio_GusChannelOffset,
 **                         Dio_GstPortGroup, Dio_GusPortOffset.
 **
 ** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
 **                         DIO_EXIT_CRITICAL_SECTION.
 **
 ** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, JPMSR0, APMSRn.
 ******************************************************************************/
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO064, SWS_Dio_00064 */
/* Implements DIO006, SWS_Dio_00006, DIO134, SWS_Dio_00134 */
/* Implements DIO028, SWS_Dio_00028, DIO029, SWS_Dio_00029 */
/* Implements DIO079, SWS_Dio_00079, DIO060, SWS_Dio_00060 */
/* Implements DIO006, SWS_Dio_00006, DIO113, SWS_Dio_00113 */
/* Implements EAAR_PN0061_FR_0007, EAAR_PN0061_FR_0017 */
/* Implements DIO180, SWS_Dio_00180, DIO146_Conf, ECUC_Dio_00146 */
/* Implements DIO_ESDD_UD_043 ,DIO_ESDD_UD_036 */
/* Implementation of the Dio_WriteChannel API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel(
                                  CONST(Dio_ChannelType,  AUTOMATIC)  ChannelId,
                                  CONST(Dio_LevelType,    AUTOMATIC)  Level )
 /* Implements DIO171, DIO128, DIO060, DIO006, DIO134, DIO182, DIO051*/
 /* Implements DIO023, DIO015, DIO017, DIO119, DIO079, DIO089,DIO066  */
 /* Implements DIO070, DIO074, DIO005, DIO026, DIO028, DIO029, DIO175, DIO067 */
 /* Implements EAAR_PN0061_FR_0006, EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001 */
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0013*/
 /* Implements SWS_Dio_00026, EAAR_PN0034_NR_0069 */
{
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST)   LpPortGroup;
  P2CONST(Dio_PortChannel, AUTOMATIC, DIO_CONFIG_CONST) LpPortChannel;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  uint32 LulPortModeLevel;
  uint16 LusTempIndex;
  uint32 LulPSRContent;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  /*Check whether the Autosar version is R4.0.3*/
  #if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                     (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_CHANNEL_SID,
                          DIO_E_UNINIT);

    /* Implements DIO_ESDD_UD_008 */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)
    LddDetErrFlag = E_OK;
    #endif  /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  else
  {
    /* No action required */
  }
  #endif /* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_015 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  {
    /* Implements DIO140, SWS_Dio_00140 , DIO074, SWS_Dio_00074 */
    /* Implements DIO074, SWS_Dio_00074 */
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_027 */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_CHANNEL_SID,
                          DIO_E_PARAM_INVALID_CHANNEL_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  {
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    LpPortGroup = &Dio_GstPortGroup[LusTempIndex];
    /* Check if the required port is INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
      /* Implements DIO_ESDD_UD_028 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_WRITE_CHANNEL_SID,
                            DIO_E_PARAM_INVALID_PORT_ID);
      LddDetErrFlag = E_OK;
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
  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    LpPortGroup  = &Dio_GstPortGroup[LusTempIndex];
    #endif /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    /* Implements EAAR_PN0061_FR_0006 */
    /*
     * Enable appropriate Channel position by writing
     * upper 16bits of PSR register
     */
    LulPSRContent = ((uint32)LpPortChannel->usMask) * (DIO_SHIFT_SIXTEEN);
    /* Check if the input level value is ZERO */
    if (STD_HIGH == Level)
    {
      /*
       * Make the Channel value as ONE by writing
       * lower 16-bits of PSR register
       */
      LulPSRContent = LulPSRContent + (LpPortChannel->usMask);
    }
    else
    {
      /* No action required since the lower bits are already zero */
    }

    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* Implements DIO070, SWS_Dio_00070 */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LulPortModeLevel =(uint32)
                  ((Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPMSR) &
                                              (LpPortChannel->usMask));
      #endif
    }
    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* QAC Warning: START Msg(2:2814)-3 */
      LulPortModeLevel =(uint32)
              ((Dio_GaaJPortReg_BaseAddress->ulJPMSR)&(LpPortChannel->usMask));
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      LulPortModeLevel =(uint32)
                 ((Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPMSR)&
                                              (LpPortChannel->usMask));
    }
    #endif
    else
    {
      LulPortModeLevel = (uint32)DIO_LOW_LEVEL_OUTPUT;
    }

    /* Implements DIO029, SWS_Dio_00029 */
    /* Implements DIO079, SWS_Dio_00079 */
    /* Implements DIO070, SWS_Dio_00070 */
    /* Implements DIO028, SWS_Dio_00028 */
    /* Implements EAAR_PN0061_FR_0001, EAAR_PN0061_FR_0006 */
    /* If the specified channel is configured as an output channel */
    if ((uint32)DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK  == LulPortModeLevel)
    {
      /* Load 32 bit value to PSR register */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      DIO_WRITE_REG_ONLY(
                    &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                    LulPSRContent)
      DIO_CHECK_WRITE_VERIFY_RUNTIME(
                    &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                    LulPSRContent & (uint32)LpPortChannel->usMask,
                    (uint32)LpPortChannel->usMask,DIO_WRITECHANNEL_API_ID)
      #endif
      } /* DIO_NORMALPORT equals to LpPortGroup->ucPortType */
      #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
      else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        LulPSRContent & (uint32)LpPortChannel->usMask,
                        (uint32)LpPortChannel->usMask,
                        DIO_WRITECHANNEL_API_ID)
      }
      #endif
      #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
      else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     LulPSRContent & (uint32)LpPortChannel->usMask,
                     (uint32)LpPortChannel->usMask,DIO_WRITECHANNEL_API_ID)
      }
      #endif
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* No action required */
    }
    /* Implements EAAR_PN0061_FR_0024 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO074, SWS_Dio_00074 */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_WRITE_CHANNEL_SID,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
}
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_FlipChannel
 **
 ** Service ID            : 0x11
 **
 ** Description           : This service flip the level of a channel and return
 **                         the level of the channel after flip.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelId
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
 **                         physical level of the Pin.
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GblDriverStatus(R4.0), Dio_GusChannelOffset,
 **                         Dio_GusPortOffset
 **
 ** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
 **                         DIO_EXIT_CRITICAL_SECTION.
 **
 ** Registers Used        : PNOTn, JPNOT0, APNOTn, PPRn, JPPR0, APPRn, PMSRn,
 **                         JPMSR0, APMSRn, PSRn, JPSR0, APSRn, Pn, APn, JP0 .
 ******************************************************************************/
/* Implements DIO_ESDD_UD_019 */
#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO190, SWS_Dio_00190, DIO191, SWS_Dio_00191 */
/* Implements DIO192, SWS_Dio_00192, DIO193, SWS_Dio_00193 */
/* Implements DIO060, SWS_Dio_00060 */
/* Implements DIO_ESDD_UD_050, DIO_ESDD_UD_012, DIO_ESDD_UD_036 */
/* Implementation Of Dio_FlipChannel API */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_FlipChannel(
                                    CONST(Dio_ChannelType, AUTOMATIC) ChannelId)
/* Implements DIO171, DIO128, DIO005, DIO119, DIO153_Conf, DIO026, DIO191 */
/* Implements DIO089, DIO193, DIO190, DIO192, DIO175,  DIO140, DIO066, DIO067 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0030 */
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0081, EAAR_PN0034_NR_0002 */
/* Implements SWS_Dio_00026, EAAR_PN0034_NR_0069, ECUC_Dio_00153 */
{
  Dio_LevelType LddLevel;
  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST)   LpPortGroup;
  P2CONST(Dio_PortChannel, AUTOMATIC, DIO_CONFIG_CONST) LpPortChannel;
  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  Dio_PortLevelType LddPortLevel;
  uint32 LulPortModeLevel;
  uint16 LusTempIndex;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  LddPortLevel = STD_LOW;
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements DIO089, SWS_Dio_00089 */
  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  /*Check whether the Autosar version is R4.0.3*/
  #if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                    (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_FLIP_CHANNEL_SID,
                          DIO_E_UNINIT);
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)
    LddDetErrFlag = E_OK;
    #endif
  }
  else
  {
    /* No action required */
  }
  #endif/* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

   /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_015 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  {
    /* Implements DIO140, SWS_Dio_00140, DIO074, SWS_Dio_00074*/
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_FLIP_CHANNEL_SID,
                          DIO_E_PARAM_INVALID_CHANNEL_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_NOT_OK == LddDetErrFlag)
  {
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    LpPortGroup = &Dio_GstPortGroup[LusTempIndex];

    /* Implements DIO192, SWS_Dio_00192 */
    /* Implements DIO193, SWS_Dio_00193 */
    /* Check if the required port is INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
      /* Implements DIO_ESDD_UD_010,  DIO_ESDD_UD_028*/
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_FLIP_CHANNEL_SID,
                            DIO_E_PARAM_INVALID_PORT_ID);
      LddDetErrFlag = E_OK;
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
  if (E_NOT_OK == LddDetErrFlag)
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    LpPortGroup = &Dio_GstPortGroup[LusTempIndex];
    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LulPortModeLevel =
           (uint32)(Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPMSR) &
                                                       LpPortChannel->usMask;

      /* Implements DIO191, SWS_Dio_00191 */
      /* Implements EAAR_PN0061_FR_0001 */
      /* To check channel is output channel*/
      if ((uint32)DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK == LulPortModeLevel)
      {
        /* Read the port value from P register of Numeric Port */
        LddPortLevel = (Dio_PortLevelType)
                      (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usP);
        /*
         * Write the PNOT register of Numeric Port
         */
        DIO_WRITE_REG_ONLY(
              &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usPNOT,
              LpPortChannel->usMask)
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
              &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usP,
              (uint16)LpPortChannel->usMask & (uint16)(~LddPortLevel),
              (uint16)LpPortChannel->usMask,
              DIO_FLIPCHANNEL_API_ID)
      }
      else
      {
        /* No action required */
      }
      /*
       * Read the port value from PPR register of Numeric Port
       */
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usPPR);
      #endif /* (DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) */
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    /* Check if the required port is JTAG port */
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* QAC Warning: START Msg(2:2814)-3 */
      LulPortModeLevel =(uint32)
               ((Dio_GaaJPortReg_BaseAddress->ulJPMSR)&(LpPortChannel->usMask));
      /* END Msg(2:2814)-3 */

      /* Implements DIO191, SWS_Dio_00191 */
      /* Check if the Direction of the Channel is output */
      if (DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK == (uint16)LulPortModeLevel)
      {
        /* Read the port value from JP register of JTAG Port */
        LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJP);
        /*
         * Write the PNOT register of JTAG Port
         */
        DIO_WRITE_REG_ONLY(
              &Dio_GaaJPortReg_BaseAddress->ucJPNOT,
              (uint8)(LpPortChannel->usMask))
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
              &Dio_GaaJPortReg_BaseAddress->ucJP,
              (uint32)LpPortChannel->usMask & (uint32)((uint16)(~LddPortLevel)),
              (uint32)LpPortChannel->usMask,
              DIO_FLIPCHANNEL_API_ID)
      }
      else
      {
        /* No action required */
      }

      /*
       * Read the port value from PPR register of JTAG Port
       */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJPPR);
    }
    #endif /* (DIO_JTAG_PORT_CONFIGURED == STD_ON) */

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    /* Check if the required port is Analog port */
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      LulPortModeLevel =(uint32)
                 ((Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPMSR)&
                                              (LpPortChannel->usMask));

      /* Implements DIO191, SWS_Dio_00191 */
      /* Check if the Direction of the Channel is output */
      if (DIO_LOW_LEVEL_OUTPUT  == (uint16)LulPortModeLevel)
      {
        /* Read the port value from AP register of Analog Port */
        LddPortLevel = (Dio_PortLevelType)
                    (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAP);
        /*
         * Write the PNOT register of Analog Port
         */
        DIO_WRITE_REG_ONLY(
              &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAPNOT,
              (LpPortChannel->usMask))
        DIO_CHECK_WRITE_VERIFY_RUNTIME(
              &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAP,
              (uint32)LpPortChannel->usMask & (uint32)((uint16)(~LddPortLevel)),
              (uint32)LpPortChannel->usMask,
              DIO_FLIPCHANNEL_API_ID)
      }
      else
      {
        /* No action required */
      }
      /*
       * Read the port value from PPR register of Analog Port
       */
      LddPortLevel = (Dio_PortLevelType)
                    (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAPPR);
    }
    #endif /* (DIO_ANALOG_PORT_CONFIGURED == STD_ON) */
    else
    {
      /* No Action Required */
    }

    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    /*
     * Mask the port value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Implements DIO191, SWS_Dio_00191 */
    /* Check whether value is not equal to zero */
    if (DIO_LOW_LEVEL_OUTPUT != LddPortLevel)
    {
      /* Implements DIO191, SWS_Dio_00191 */
      /* Implements DIO089, SWS_Dio_00089 */
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
  }

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO074, SWS_Dio_00074 */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_FLIP_CHANNEL_SID,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the Channel Level */
  return(LddLevel);
}
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /*(DIO_FLIP_CHANNEL_API == STD_ON) */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_ReadChannelGroup
 **
 ** Service ID            : 0x04
 **
 ** Description           : This service returns the value of the ChannelGroup
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelGroupIdPtr
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Returns the value of physical level of the Channels
 **                         that form the ChannelGroup
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GstPortGroup,
 **                         Dio_GblDriverStatus(R4.0), Dio_GusPortOffset
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : PPRn, JPPR0, APPRn, IPPR0.
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO012, SWS_Dio_00012, DIO083 */
/* Implements DIO014, SWS_Dio_00014, DIO037, SWS_Dio_00037, SWS_Dio_00083 */
/* Implements DIO137, SWS_Dio_00137, DIO092, SWS_Dio_00092, ECUC_Dio_00148 */
/* Implements DIO093, SWS_Dio_00093, DIO060, SWS_Dio_00060, DIO148_Conf */
/* Implements EAAR_PN0061_FR_0008, EAAR_PN0061_FR_0014, DIO_ESDD_UD_046 */
/* Implementation of the Dio_ReadChannelGroup API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup(
    CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr )
 /* Implements DIO171, DIO128, DIO056, DIO060, DIO021, DIO092, DIO093, DIO118 */
 /* Implements DIO137, DIO014, DIO024, DIO184, DIO022, DIO051, DIO084*/
 /* Implements DIO114, DIO005, DIO026, DIO037, DIO083, DIO186, DIO178, DIO188 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0061_FR_0002, EAAR_PN0034_FR_0081 */
 /* Implements EAAR_PN0034_NR_0069, DIO066, DIO067, SWS_Dio_00026 */
{
  Dio_PortLevelType LddPortLevel;

  /* Implements DIO_ESDD_UD_009 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST) LpPortGroup;
  /* Implements DIO_ESDD_UD_013 */
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONFIG_CONST) LpChannelGroupPtr;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddDetErrFlag;
  #endif

  uint16 LusDioChannelGroupId;
  uint16 LusChGrpPtrValue;
  uint16 LusDioTempIndex;
  uint16 LusDioIndex;
  /* MISRA Violation: START Msg(4:2982)-2 */
  LusChGrpPtrValue = DIO_LOW_LEVEL_OUTPUT;
  /* END Msg(4:2982)-2 */

  #endif

  /* Implements DIO_ESDD_UD_009 */
  #if ((DIO_CHANNELGROUP_CONFIGURED == STD_ON) && \
                                           (DIO_DEV_ERROR_DETECT == STD_ON))
  LddDetErrFlag = E_NOT_OK;
  LpChannelGroupPtr = NULL_PTR;
  #endif /* ((DIO_CHANNELGROUP_CONFIGURED == STD_ON) && \
          *  (DIO_DEV_ERROR_DETECT == STD_ON))
          */

  /* Implements DIO_ESDD_UD_009 */
  #if ((DIO_CHANNELGROUP_CONFIGURED == STD_OFF) || \
                                           (DIO_DEV_ERROR_DETECT == STD_ON))
  /* Set the return value to 0 */
  LddPortLevel = DIO_LOW_LEVEL_OUTPUT;
  #endif /* ((DIO_CHANNELGROUP_CONFIGURED == STD_OFF) || \
          *  (DIO_DEV_ERROR_DETECT == STD_ON))
          */

  /* Check if at least one ChannelGroup is configured */
  /* Implements DIO_ESDD_UD_009 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*Check whether the Autosar version is R4.0.3*/
  /* Implements EAAR_PN0034_FR_0055 */
  #if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_READ_CHANNEL_GROUP_SID,
                          DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  #endif /* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */
  /* Implements DIO188, SWS_Dio_00065 */
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_032 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_READ_CHANNEL_GROUP_SID,
                          DIO_E_PARAM_POINTER);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* Getting the channel group pointer value */

    /* MISRA Violation: START Msg(4:0306)-1 */
    /* MISRA Violation: START Msg(2:3892)-5 */
    LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
                       ((uint32)(&Dio_GstChannelGroupData
                       [DIO_LOW_LEVEL_OUTPUT])));
    /* END Msg(4:0306)-1 */
    /* END Msg(2:3892)-5 */

    LusDioChannelGroupId = LusChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT;

    /* Check if the channel group address is wrong or out-of-bound */
    /* MISRA Violation: START Msg(2:3892)-5 */
    if ((DIO_LOW_LEVEL_OUTPUT != (LusChGrpPtrValue &
                     ((uint32)(DIO_SIZE_OF_CHGRP_STRUCT -
                       DIO_HIGH_LEVEL_OUTPUT)))) ||
                      (DIO_NO_OF_CHGRP_PER_CFGSET <= (LusDioChannelGroupId)))
    {

      /* END Msg(2:3892)-5 */
      /* Implements DIO178, SWS_Dio_00065, DIO114, SWS_Dio_00114*/
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_READ_CHANNEL_GROUP_SID,
                            DIO_E_PARAM_INVALID_GROUP);
      LddDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    if (E_NOT_OK == LddDetErrFlag)
    {
      LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
      LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
    }
    else
    {
      /* No action required */
    }
  }
  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)

  /*
   * Get the pointer to corresponding index in the array
   * Dio_GstChannelGroupData
   */
  /* MISRA Violation: START Msg(4:0306)-1 */
  LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
                     ((uint32)(&Dio_GstChannelGroupData
                     [(uint32)DIO_LOW_LEVEL_OUTPUT])));
  /* END Msg(4:0306)-1 */
  LusDioChannelGroupId = LusChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT;
  LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
  /* Implements DIO_ESDD_UD_013 */
  LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
  #endif

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO118, SWS_Dio_00118 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the Port Address in which the Channel is configured */
    LusDioIndex = Dio_GusPortOffset + (uint16)LpChannelGroupPtr->ucPortIndex;

    LpPortGroup = &Dio_GstPortGroup[LusDioIndex];
    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif

    /* Implements DIO083, SWS_Dio_00083 */
    /* Implements DIO084, SWS_Dio_00084 */
    /* Implements DIO014, SWS_Dio_00014 */
    /* Implements EAAR_PN0061_FR_0002 */
    /* Check if the required port is JTAG port */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      /*
       * Read the port value from PPR register of Numeric/Alphabetic Port
       */
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usPPR);
      #endif
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      /*
       * Read the port value from PPR register of JTAG Port
       */
      /* QAC Warning: START Msg(2:2814)-3 */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJPPR);
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      /*
       * Read the port value from APPR register of ANALOG Port
       */
      LddPortLevel = (Dio_PortLevelType)
                    (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAPPR);
    }
    #endif

    else
    {
      /* Read the port value from IPPR register  */
      /* QAC Warning: START Msg(2:2814)-3 */
      #if (DIO_INPUT_PORT_CONFIGURED == STD_ON)
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaIPortReg_BaseAddress->usIPPR);
      /* END Msg(2:2814)-3 */
      #else
      LddPortLevel = (Dio_PortLevelType)DIO_LOW_LEVEL_OUTPUT;
      #endif
    }
    /* Implements DIO092, SWS_Dio_00092 */
    /*
     * Mask the port value for required ChannelGroup related bit positions
     * and clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpChannelGroupPtr->usMask);
    /* Implements DIO093, SWS_Dio_00093 */
    /* Rotate right to get the corresponding ChannelGroup value */
    LddPortLevel = LddPortLevel >> (LpChannelGroupPtr->ucOffset);
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO178, SWS_Dio_00065*/
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029 */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_GROUP_SID,
                        DIO_E_PARAM_INVALID_GROUP);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */

  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the ChannelGroup Level */
  return (LddPortLevel);
}
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_FR_0055 */
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_WriteChannelGroup
 **
 ** Service ID            : 0x05
 **
 ** Description           : This service writes specified level to the
 **                         ChannelGroup
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelGroupIdPtr and Level.
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : None
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **
 ** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GstPortGroup,
 **                         Dio_GblDriverStatus(R4.0), Dio_GusPortOffset
 **
 ** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
 **                         DIO_EXIT_CRITICAL_SECTION.
 **
 ** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, JPMSR0, APMSRn .
 ******************************************************************************/
/* Implements EAAR_PN0034_FR_0055 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO064, SWS_Dio_00064 */
/* Implements DIO039, SWS_Dio_00039, DIO040, SWS_Dio_00040 */
/* Implements DIO090, SWS_Dio_00090, DIO091, SWS_Dio_00091 */
/* Implements DIO008, SWS_Dio_00008, DIO138, SWS_Dio_00138, ECUC_Dio_00148 */
/* Implements DIO060, SWS_Dio_00060, DIO008, SWS_Dio_00008, DIO148_Conf */
/* Implements EAAR_PN0061_FR_0008, EAAR_PN0061_FR_0014, DIO_ESDD_UD_047 */
/* Implementation of the Dio_WriteChannelGroup API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup(
 CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004 */
 /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0030 */
 /* Implements EAAR_PN0034_NR_0069 */
                                                        Dio_PortLevelType Level)
{
  /* Implements DIO_ESDD_UD_009 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  uint16 LusDioTempIndex;
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST)   LpPortGroup;
  /* Implements DIO_ESDD_UD_013 */
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONFIG_CONST) LpChannelGroupPtr;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddDetErrFlag;
  #endif

  uint16 LusDioChannelGroupId;
  uint32 LulPortModeLevel;
  uint16 LusChGrpPtrValue;
  uint16 LusDioIndex;
  uint32 LulPSRContent;
  /* MISRA Violation: START Msg(4:2982)-2 */
  LusChGrpPtrValue = DIO_LOW_LEVEL_OUTPUT;
  /* END Msg(4:2982)-2 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  LddDetErrFlag = E_NOT_OK;
  LpChannelGroupPtr = NULL_PTR;
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*Check whether the Autosar version is R4.0.3*/
  #if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_CHANNEL_GROUP_SID,
                          DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif /* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

  /* Implements DIO188, SWS_Dio_00065 */
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_032 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID,
                          DIO_INSTANCE_ID,
                          DIO_WRITE_CHANNEL_GROUP_SID,
                          DIO_E_PARAM_POINTER);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* Getting the channel group pointer value */
    /* MISRA Violation: START Msg(4:0306)-1 */
    /* MISRA Violation: START Msg(2:3892)-5 */
    LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
                       ((uint32)(&Dio_GstChannelGroupData
                       [DIO_LOW_LEVEL_OUTPUT])));
    /* END Msg(4:0306)-1 */
    /* END Msg(2:3892)-5 */
    LusDioChannelGroupId = LusChGrpPtrValue/ DIO_SIZE_OF_CHGRP_STRUCT;

    /* Check if the channel group address is wrong or out-of-bound */
    /* MISRA Violation: START Msg(2:3892)-5 */
    if ((DIO_LOW_LEVEL_OUTPUT != (LusChGrpPtrValue &
                     ((uint32)(DIO_SIZE_OF_CHGRP_STRUCT -
                      DIO_HIGH_LEVEL_OUTPUT)))) ||
                     (DIO_NO_OF_CHGRP_PER_CFGSET <= (LusDioChannelGroupId)))
    {

      /* END Msg(2:3892)-5 */
      /* Implements DIO178, SWS_Dio_00065 */
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_WRITE_CHANNEL_GROUP_SID,
                            DIO_E_PARAM_INVALID_GROUP);
      LddDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    if (E_NOT_OK == LddDetErrFlag)
    {
      LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
      LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
    }
    else
    {
      /* No action required */
    }
  }
  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)
  /* Get the pointer to corresponding index in the
     array Dio_GstChannelGroupData */

  /* Getting the channel group pointer value */
  /* MISRA Violation: START Msg(4:0306)-1 */
  LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
                     ((uint32)(&Dio_GstChannelGroupData
                     [(uint32)DIO_LOW_LEVEL_OUTPUT])));
  /* END Msg(4:0306)-1 */
  LusDioChannelGroupId = LusChGrpPtrValue/ DIO_SIZE_OF_CHGRP_STRUCT;
  LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
  LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  {
    /* Get the Port Address in which the Channel group is configured */
    LusDioIndex = Dio_GusPortOffset + (uint16)LpChannelGroupPtr->ucPortIndex;
    LpPortGroup = &Dio_GstPortGroup[LusDioIndex];

    /* Implements DIO040, SWS_Dio_00040 */
    /* Check if the required port is not INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO140, SWS_Dio_00140, DIO177, SWS_Dio_00065 */
      /* Implements DIO114, SWS_Dio_00114 */
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_028 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID,
                            DIO_INSTANCE_ID,
                            DIO_WRITE_CHANNEL_GROUP_SID,
                            DIO_E_PARAM_INVALID_PORT_ID);
      LddDetErrFlag = E_OK;
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

  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to port group to which the channel belongs */
    LusDioIndex = Dio_GusPortOffset + (uint16)LpChannelGroupPtr->ucPortIndex;
    LpPortGroup = &Dio_GstPortGroup[LusDioIndex];
    #endif /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    /* Get the Port Address in which the Channel group is configured */
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif

    /* Implements DIO091, SWS_Dio_00091 */
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    /* Implements DIO040, SWS_Dio_00040 */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LulPortModeLevel =
         (uint32)(~(Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPMSR)) &
                   (~(LpPortGroup->ulModeMask) & LpChannelGroupPtr->usMask);
      #endif
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* QAC Warning: START Msg(2:2814)-3 */
      LulPortModeLevel =(uint32)(~(Dio_GaaJPortReg_BaseAddress->ulJPMSR)) &
                     (~(LpPortGroup->ulModeMask) & LpChannelGroupPtr->usMask);
      /* END Msg(2:2814)-3 */
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      LulPortModeLevel = (uint32)
              ((~(Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPMSR)) &
                     (~(LpPortGroup->ulModeMask) & LpChannelGroupPtr->usMask));
    }
    #endif

    else
    {
      LulPortModeLevel = (uint32)DIO_LOW_LEVEL_OUTPUT;
    }

    /* Rotate left the input level to get the value to be written to port */
    Level = Level << (LpChannelGroupPtr->ucOffset);

    /* To check channel is output channel*/
    if ((uint32)DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK  != LulPortModeLevel)
    {
      /* Implements EAAR_PN0061_FR_0001 */
      LulPSRContent =(Level |
                    ((uint32)(((LulPortModeLevel)) & LpChannelGroupPtr->usMask)
                                                          * DIO_SHIFT_SIXTEEN));
      if (DIO_NORMALPORT == LpPortGroup->ucPortType)
      {
        #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
        DIO_WRITE_REG_ONLY(
                       &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                       LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                       &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                       ((uint32)Level & (uint32)LpChannelGroupPtr->usMask)
                                                         & LulPortModeLevel,
                       (uint32)LpChannelGroupPtr->usMask & LulPortModeLevel,
                        DIO_WRITECHANNELGROUP_API_ID)
        #endif
      } /* DIO_NORMALPORT equals LpPortGroup->ucPortType */

      #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
      else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                        &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                        ((uint32)Level & (uint32)LpChannelGroupPtr->usMask)
                                                          & LulPortModeLevel,
                        (uint32)LpChannelGroupPtr->usMask & LulPortModeLevel,
                        DIO_WRITECHANNELGROUP_API_ID)
      }
      #endif

      #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
      else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                     &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                     ((uint32)Level & (uint32)LpChannelGroupPtr->usMask)
                                                       & LulPortModeLevel,
                     (uint32)LpChannelGroupPtr->usMask & LulPortModeLevel,
                     DIO_WRITECHANNELGROUP_API_ID)
      }
      #endif
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* No action required */
    }
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO178, SWS_Dio_00065 */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029 */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_WRITE_CHANNEL_GROUP_SID,
                        DIO_E_PARAM_INVALID_GROUP);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */

}

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name      : Dio_CheckHWConsistency
 **
 ** Service ID         : 0x13
 **
 ** Description        : This service returns the status of hardware
 **                      consistency check for Dio module.
 **
 ** Sync/Async         : Synchronous
 **
 ** Re-entrancy        : Non Re-entrant
 **
 ** Input Parameters   : CheckType
 **
 ** InOut Parameters   : None
 **
 ** Output Parameters  : None
 **
 ** Return parameter   : CheckStatus
 **
 ** Preconditions      : None
 **
 ** Global Variables   : None
 **
 ** Function(s) invoked: None
 **
 ******************************************************************************/
#if (DIO_RAM_MIRROR == DIO_RAM_MIRROR_ENABLE)

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
FUNC(Std_ReturnType,DIO_PUBLIC_CODE) Dio_CheckHWConsistency(
                     CONST(Dio_HWConsistencyCheckType, AUTOMATIC) CheckType)
{
  Std_ReturnType LddCheckStatus;
  LddCheckStatus = E_OK;
  return LddCheckStatus;
}
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* (DIO_RAM_MIRROR == DIO_RAM_MIRROR_ENABLE) */

/*******************************************************************************
** Function Name         : Dio_MaskedWritePort
**
** Service ID            : 0x17
**
** Description           : This service writes the specified level to all the
**                         channels that are Masked in given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId, Mask and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : DIO Driver must be initialized(Autosar 403).
**                         DIO_MASKED_WRITE_PORT_API switch must be ON.
**
** Global Variables Used : Dio_GstPortGroup, Dio_GblDriverStatus(R4.0)
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, JPMSR0, APMSRn.
*******************************************************************************/
/* Implements EAAR_PN0061_FR_0015, EAAR_PN0061_FR_0022, DIO195 */
/* Implements DIO150_Conf, ECUC_Dio_00150, DIO151_Conf, ECUC_Dio_00151 */
/* Implements DIO_ESDD_UD_022 */
/* Implementation of the Dio_MaskedWritePort interface */
#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:3227)-4 */
/* Implements DIO_ESDD_UD_053 */
FUNC(void, DIO_PUBLIC_CODE) Dio_MaskedWritePort(Dio_PortType PortId,
                               Dio_PortLevelType Level, Dio_PortLevelType Mask)
/* END Msg(2:3227)-4 */
{
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  uint16 LusDioPortGroupIndex ;
  uint32 LulPSRContent;
  uint32 LulPortModeLevel;

  /* Implements DIO066  */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  #endif
  /*start of (DIO_DEV_ERROR_DETECT == STD_ON) && \
             (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)*/
  #if  ((DIO_DEV_ERROR_DETECT == STD_ON))
  #if  ((DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_031 */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_MASKED_WRITE_PORT_SID, DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_014 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Implements DIO140, DIO177, SWS_Dio_00140, SWS_Dio_00065 */
    /* Implements DIO_ESDD_UD_028 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
     /* Implements EAAR_PN0061_FR_0004 */
    /* Get the pointer to the required Port */
    LusDioPortGroupIndex = Dio_GusPortOffset + PortId;
    LpPortGroup = &Dio_GstPortGroup[LusDioPortGroupIndex];

    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO140, DIO177, SWS_Dio_00140, SWS_Dio_00065 */
      /* Implements DIO_ESDD_UD_028 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                     DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LddDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  /* Implements DIO119, SWS_Dio_00119 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
     LusDioPortGroupIndex = Dio_GusPortOffset + PortId;
     /* Implements DIO_ESDD_UD_035 */
     LpPortGroup = &Dio_GstPortGroup[LusDioPortGroupIndex];
    #endif

    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
          (uint32)(Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPMSR) |
                                             (LpPortGroup->ulModeMask);
    }
    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =(uint32)((Dio_GaaJPortReg_BaseAddress->ulJPMSR)|
                                 (LpPortGroup->ulModeMask));
    }
    #endif
    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =(uint32)
                ((Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPMSR)|
                                                  (LpPortGroup->ulModeMask));
    }
    #endif
    else
    {
      LulPortModeLevel = (uint32)DIO_LOW_LEVEL_OUTPUT;
    }

    /* Check if the channels which are configured as output */
    if ((uint32)DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK  != (~LulPortModeLevel))
    {
        LulPSRContent = (Level |
        ((uint32)((~LulPortModeLevel) & (Mask)) << DIO_LEFT_SHIFT_SIXTEEN));

      /*Load 32 bit value to PSR register*/
      if (DIO_NORMALPORT == LpPortGroup->ucPortType)
      {
       #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)

       DIO_WRITE_REG_ONLY(
                 &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                  LulPSRContent)
       DIO_CHECK_WRITE_VERIFY_RUNTIME(
                 &Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->ulPSR,
                  ((uint32)(Level & (((~LulPortModeLevel) & Mask)))),
       ((uint32)((~LulPortModeLevel) & Mask)), DIO_MASKED_WRITE_PORT_SID)
       #endif
      }
      #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
      else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                   &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                   LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                   &Dio_GaaJPortReg_BaseAddress->ulJPSR,
                   ((uint32)(Level & (((~LulPortModeLevel) & Mask)))),
           ((uint32)((~LulPortModeLevel) & Mask)), DIO_MASKED_WRITE_PORT_SID)
      }
      #endif
      #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
      else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
      {
        DIO_WRITE_REG_ONLY(
                   &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                   LulPSRContent)

        DIO_CHECK_WRITE_VERIFY_RUNTIME(
                  &Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->ulAPSR,
                  ((uint32)(Level & (((~LulPortModeLevel) & Mask)))),
           ((uint32)((~LulPortModeLevel) & Mask)), DIO_MASKED_WRITE_PORT_SID)
      }
      #endif
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* No action required */
    }
    /* Implements EAAR_PN0061_FR_0024 */
    /* Implements DIO_ESDD_UD_017 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif
/* STD_ON == DIO_MASKED_WRITE_PORT_API */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_ReadChannelOutputValue
 **
 ** Service ID            : 0x15
 **
 ** Description           : This service returns the value of the specified
 **                         DIO Channel in Pn Register.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelId
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
 **                         physical level of the Pin
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **                         DIO_READ_CHANNEL_OUTPUT_VALUE_API switch must be ON.
 **
 ** Global Variables Used : Dio_GblDriverStatus(R4.0), Dio_GstPortChannel,
 **                         Dio_GstPortGroup, Dio_GusPortOffset.
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : Pn, JP0, APn.
 ******************************************************************************/
/* Implements DIO_ESDD_UD_020 */
#if (DIO_READ_CHANNEL_OUTPUT_VALUE_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO012, SWS_Dio_00012 */
/* Implements DIO011, SWS_Dio_00011, DIO133, SWS_Dio_00133 */
/* Implements DIO027, SWS_Dio_00027, DIO060, SWS_Dio_00060 */
/* Implements DIO180, SWS_Dio_00180 */
/* Implements DIO083, SWS_Dio_00083, EAAR_PN0061_FR_0018 */
/* Implements DIO_ESDD_UD_051, DIO_ESDD_UD_036 */
/* Implements DIO_ESDD_UD_034, DIO_ESDD_UD_031 */

/* Implementation of the Dio_ReadChannelOutPutValue API */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannelOutputValue(
                                CONST(Dio_ChannelType, AUTOMATIC) ChannelId )
{
  Dio_LevelType LddLevel;
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST)   LpPortGroup;
  P2CONST(Dio_PortChannel, AUTOMATIC, DIO_CONFIG_CONST) LpPortChannel;

  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif
  uint16 LusTempIndex;
  Dio_PortLevelType LddPortLevel;
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddDetErrFlag;
  LddDetErrFlag = E_NOT_OK;
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements DIO089, SWS_Dio_00089 */
  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /*start of (DIO_DEV_ERROR_DETECT == STD_ON) && \
             (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)*/
  #if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                     (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
     /* Implements DIO140, SWS_Dio_00140 */
     /* Implements DIO_ESDD_UD_031 */
     /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_READ_CHANNEL_OUTPUT_VALUE_SID, DIO_E_UNINIT);

     /* Implements DIO_ESDD_UD_008 */
     #if (DIO_CHANNEL_CONFIGURED == STD_ON)
     LddDetErrFlag = E_OK;
     #endif
  }
  else
  {
     /* No action required */
  }
  #endif/* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_015 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  {
    /* Implements DIO140, SWS_Dio_00140, DIO175, SWS_Dio_00065 */
    /* Implements DIO065, SWS_Dio_00065, DIO074, SWS_Dio_00074*/
    /* Implements  DIO_ESDD_UD_027 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
             DIO_READ_CHANNEL_OUTPUT_VALUE_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO118, SWS_Dio_00118 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the pointer to the required Channel */
    /* Get the Port Address from Port to which the Channel belongs */
    LusTempIndex = Dio_GusChannelOffset + ((uint16)ChannelId);
    LpPortChannel = &Dio_GstPortChannel[LusTempIndex];
    LusTempIndex = Dio_GusPortOffset + ((uint16)(LpPortChannel->ucPortIndex));
    /* Implements DIO_ESDD_UD_035 */
    LpPortGroup = &Dio_GstPortGroup[LusTempIndex];
    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from P register of Numeric Port
       */
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usP);
      #endif
    }
    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    /* Check if the required port is JTAG port */
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from JP register by adding offset to
       * PSR register address of JTAG Port
       */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJP);
    }
    #endif
    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /* Implements DIO083, SWS_Dio_00083 */
      /* Implements DIO084, SWS_Dio_00084 */
      /* Implements EAAR_PN0061_FR_0002 */
      /*
       * Read the port value from AP register of ANALOG Port
       */
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAP);
    }
    #endif
    else
    {
     LddPortLevel = (Dio_PortLevelType)DIO_LOW_LEVEL_OUTPUT;
    }
    /* Implements EAAR_PN0061_FR_0006 */
    /*
     * Mask the port level value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    if (DIO_LOW_LEVEL_OUTPUT != LddPortLevel)
    {
      /* Implements DIO089, SWS_Dio_00089 */
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
  }

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO175, SWS_Dio_00065 */
  /* Implements DIO065, SWS_Dio_00065, DIO074, SWS_Dio_00074 */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_027 */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
             DIO_READ_CHANNEL_OUTPUT_VALUE_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Implements DIO027, SWS_Dio_00027 */
  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the Channel Level */
  return LddLevel;
}

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /*(DIO_READ_CHANNEL_OUTPUT_VALUE_API == STD_ON) */

/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
 ** Function Name         : Dio_ReadChannelGroupOutputValue
 **
 ** Service ID            : 0x16
 **
 ** Description           : This service returns the value of the specified
 **                         DIO Channel Group in Pn Register.
 **
 ** Sync/Async            : Synchronous
 **
 ** Reentrancy            : Reentrant
 **
 ** Input Parameters      : ChannelGroupIdPtr
 **
 ** InOut Parameters      : None
 **
 ** Output Parameters     : None
 **
 ** Return parameter      : Returns the value of physical level of the Channels
 **                         that form the ChannelGroup
 **
 ** Preconditions         : DIO Driver must be initialized(Autosar 403).
 **                         DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_API switch must
 **                         be ON.
 **
 ** Global Variables Used : Dio_GusChannelGroupsOffset,Dio_GstPortGroup
 **                         Dio_GblDriverStatus(R4.0), Dio_GusPortOffset
 **
 ** Functions Invoked     : Det_ReportError
 **
 ** Registers Used        : Pn, JP0, APn.
 ******************************************************************************/
/* Implements DIO_ESDD_UD_021 */
#if (DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-1 */
 #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implements DIO051, SWS_Dio_00051, DIO012, SWS_Dio_00012 */
/* Implements DIO014, SWS_Dio_00014, DIO037, SWS_Dio_00037 */
/* Implements DIO137, SWS_Dio_00137, DIO092, SWS_Dio_00092 */
/* Implements DIO093, SWS_Dio_00093, DIO060, SWS_Dio_00060 */
/* Implements DIO083, SWS_Dio_00083, EAAR_PN0061_FR_0018 */
/* Implements DIO_ESDD_UD_052 */
/* Implementation of the Dio_ReadChannelGroup API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroupOutputValue(
    CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr )
{
  Dio_PortLevelType LddPortLevel;
  /* Implements DIO_ESDD_UD_009 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, AUTOMATIC, DIO_CONFIG_CONST) LpPortGroup;
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONFIG_CONST) LpChannelGroupPtr;
  #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
      (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
  uint16 LusDioPortGroupIndex;
  #endif
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddDetErrFlag;
  #endif
  uint16 LusDioChannelGroupId;
  uint16 LusChGrpPtrValue;
  uint16 LusDioTempIndex;
  uint16 LusDioIndex;
  /* MISRA Violation: START Msg(4:2982)-2 */
  LusChGrpPtrValue = DIO_LOW_LEVEL_OUTPUT;
  /* END Msg(4:2982)-2 */
  #endif

  /* Implements DIO_ESDD_UD_009 */
  #if ((DIO_CHANNELGROUP_CONFIGURED == STD_ON) && \
                                           (DIO_DEV_ERROR_DETECT == STD_ON))
  LddDetErrFlag = E_NOT_OK;
  LpChannelGroupPtr = NULL_PTR;
  #endif /* ((DIO_CHANNELGROUP_CONFIGURED == STD_ON) && \
          *  (DIO_DEV_ERROR_DETECT == STD_ON))
          */
  /* Implements DIO_ESDD_UD_009 */
  #if ((DIO_CHANNELGROUP_CONFIGURED == STD_OFF) || \
                                           (DIO_DEV_ERROR_DETECT == STD_ON))
  /* Set the return value to 0 */
  LddPortLevel = DIO_LOW_LEVEL_OUTPUT;
  #endif /* ((DIO_CHANNELGROUP_CONFIGURED == STD_OFF) || \
          *  (DIO_DEV_ERROR_DETECT == STD_ON))
          */
  /* Check if at least one ChannelGroup is configured */
  /* Implements DIO_ESDD_UD_009 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*Check whether the Autosar version is R4.0.3*/
  #if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_031 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                         DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_SID, DIO_E_UNINIT);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif /* (DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */
  /* Implements DIO188, SWS_Dio_00065 */
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Implements DIO140, SWS_Dio_00140 */
    /* Implements DIO_ESDD_UD_032 */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                  DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_SID, DIO_E_PARAM_POINTER);
    LddDetErrFlag = E_OK;
  }
  else
  {
    /* Getting the channel group pointer value */
    LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
                    ((uint32)(&Dio_GstChannelGroupData[DIO_LOW_LEVEL_OUTPUT])));
    LusDioChannelGroupId = LusChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT;

    /* Check if the channel group address is wrong or out-of-bound */
    if ((DIO_LOW_LEVEL_OUTPUT != (LusChGrpPtrValue &
               ((uint32)(DIO_SIZE_OF_CHGRP_STRUCT - DIO_HIGH_LEVEL_OUTPUT)))) ||
                      (DIO_NO_OF_CHGRP_PER_CFGSET <= (LusDioChannelGroupId)))
    {
      /* Implements DIO178, SWS_Dio_00065, DIO114, SWS_Dio_00114 */
      /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029 */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
            DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_SID, DIO_E_PARAM_INVALID_GROUP);
      LddDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
    if (E_NOT_OK == LddDetErrFlag)
    {
      LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
      LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
    }
    else
    {
      /* No action required */
    }
  }
  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)
  /*
   * Get the pointer to corresponding index in the array
   * Dio_GstChannelGroupData
   */
  /* MISRA Violation: START Msg(4:0306)-1 */
  LusChGrpPtrValue = (uint16)(((uint32)ChannelGroupIdPtr) -
            ((uint32)(&Dio_GstChannelGroupData[(uint32)DIO_LOW_LEVEL_OUTPUT])));
  /* END Msg(4:0306)-1 */
  LusDioChannelGroupId = LusChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT;
  LusDioTempIndex = Dio_GusChannelGroupsOffset + LusDioChannelGroupId;
  LpChannelGroupPtr = &Dio_GstChannelGroupData[LusDioTempIndex];
  #endif

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO118, SWS_Dio_00118 */
  if (E_NOT_OK == LddDetErrFlag)
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the Port Address in which the Channel is configured */
    LusDioIndex = Dio_GusPortOffset + (uint16)LpChannelGroupPtr->ucPortIndex;
    /* Implements DIO_ESDD_UD_035 */
    LpPortGroup = &Dio_GstPortGroup[LusDioIndex];
    #if((DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG) || \
        (DIO_ANALOG_PORT_CONFIGURED == STD_ON))
    LusDioPortGroupIndex = LpPortGroup->ucPortGroupIndex;
    #endif
    /* Implements DIO083, SWS_Dio_00083 */
    /* Implements DIO084, SWS_Dio_00084 */
    /* Implements DIO014, SWS_Dio_00014 */
    /* Implements EAAR_PN0061_FR_0002 */
    /* Check if the required port is JTAG port */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /*
       * Read the port value from P register of Numeric/Alphabetic Port
       */
      #if(DIO_NUM_OF_PORTREG > DIO_ZERO_PORTREG)
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaPortReg_BaseAddress[LusDioPortGroupIndex]->usP);
      #endif
    }

    #if (DIO_JTAG_PORT_CONFIGURED == STD_ON)
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /*
       * Read the port value from P register of JTAG Port
       */
      LddPortLevel = (Dio_PortLevelType)(Dio_GaaJPortReg_BaseAddress->ucJP);
    }
    #endif

    #if (DIO_ANALOG_PORT_CONFIGURED == STD_ON)
    else if (DIO_ANALOGPORT == LpPortGroup->ucPortType)
    {
      /*
       * Read the port value from AP register of ANALOG Port
       */
      LddPortLevel = (Dio_PortLevelType)
                     (Dio_GaaAPortReg_BaseAddress[LusDioPortGroupIndex]->usAP);
    }
    #endif

    else
    {
      LddPortLevel = (Dio_PortLevelType)DIO_LOW_LEVEL_OUTPUT;
    }
    /* Implements DIO092, SWS_Dio_00092 */
    /*
     * Mask the port value for required ChannelGroup related bit positions
     * and clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpChannelGroupPtr->usMask);
    /* Implements DIO093, SWS_Dio_00093 */
    /* Rotate right to get the corresponding ChannelGroup value */
    LddPortLevel = LddPortLevel >> (LpChannelGroupPtr->ucOffset);
  }

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO140, SWS_Dio_00140, DIO178, SWS_Dio_00065 */
  /* Implements DIO_ESDD_UD_010, DIO_ESDD_UD_029*/
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
            DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_SID, DIO_E_PARAM_INVALID_GROUP);
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */
  /* Implements EAAR_PN0034_FR_0049 */
  /* Return the ChannelGroup Level */
  return (LddPortLevel);
}
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0862)-2 */
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */
#endif /*(DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_API == STD_ON) */
/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
