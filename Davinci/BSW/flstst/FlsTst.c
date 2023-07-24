/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst.c                                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of FlsTst Driver Component.         */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  11-Oct-2013    : Initial Version
 *
 * V1.0.1:  03-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. Copyright information is updated.
 *                           2. API FlsTst_StartFgnd is updated for variable
 *                              initialization, stored crc read logic changes.
 *                           3. Critical section protection added while changing
 *                              flstst current execution state.
 *                           4. API FlsTst_MainFunction updated to remove the
 *                              "break" command from for loop and saved crc
 *                              value read and comparison logic updated.
 *
 * V1.0.2:  13-Mar-2014    : As per CR466, CR88 and mantis #17998, 17963
 *                           following changes are made:
 *                           1. 'MISRA C Rule Violations' section is updated
 *                              for the removal of unused QAC warnings.
 *                           2. Function header is updated for
 *                              'Global Variables Used', 'Registers Used'
 *                              sections.
 *                           3. FlsTst_Init, FlsTst_DeInit APIs are updated for
 *                              initialization of registers to default values.
 *                           4. critical section check is added in
 *                              FlsTst_GetCurrentState,
 *                              FlsTst_GetTestResultBgnd,
 *                              FlsTst_GetTestSignatureBgnd,
 *                              FlsTst_MainFunction, FlsTst_TestEcc APIs.
 *                           5. Conditional checking format changed, putting
 *                              constant on the left side of the operand.
 *
 * V1.0.3:  06-Jun-2014    : As per CR524 and mantis #20349, FlsTst_TestEcc API
 *                           is updated as per the ECC circuitry support in the
 *                           device variant.
 *
 * V1.0.4:  17-Sep-2014    : As per CR12, following changes are made:
 *                           1. MISRA C Rule Violations section is updated for
 *                              adding and removing rules.
 *                           2. FlsTst_Suspend and FlsTst_MainFunction API's
 *                              conditional checking are updated to remove QAC
 *                              warnings.
 *                           3. Redundant local variable initialization removed
 *                              from FlsTst_StartFgnd, FlsTst_TestEcc and
 *                              FlsTst_MainFunction API's to avoid QAC warnings.
 *                           4. As per Renesas coding guidelines, constants are
 *                              placed on left hand side of the condition and
 *                              Markers are added for Tracing.
 *                           5. FlsTst_StartFgnd and FlsTst_MainFunction API's
 *                              are updated for CRC 8 bit(2F) and
 *                              CRC 8 bit(SAEJ150) algorithms.
 *
 * V1.0.5: 21-Nov-2014    : As per CR74, Trailing Space are removed and MISRA
 *                          Warning are corrected.
 *
 * V1.0.6: 17-Feb-2015    : As per mantis #26024, file is copied from P1x
 *                          branch and following changes are done:
 *                          1.Precompile switch FLSTST_DEVICE_SPECIFIC is
 *                            added at required places, to exclude 8 bit CRC
 *                            for devices other than P1x.
 *
 * V1.0.6: 01-Apr-2015    : As per mantis #27195,
 *                          1. MISRA C Rule Violations section is added.
 *                          2. MISRA rules violation messages are added.
 *                          3. Copyright information is updated.
 *
 * V1.0.7: 09-Jun-2015    : As part of F1L V4.01.07, following changes were
 *                          made:
 *                          1. Macro DRIVERSTATE_DATA_PROTECTION was changed to
 *                          FLSTST_DRIVERSTATE_DATA_PROTECTION as part of
 *                          fixing mantis tickets #26209 and #26199.
 *
 * V2.0.0: 28-Oct-2016    : Add register write verify and Ram mirror
 *                          functionallity
 * V2.0.1: 04-Oct-2016    : As Part of JIRA ARDAABD-714 : Add suffixes for VCI
 *                          registers
 * V2.0.2: 04-Oct-2016    : As Part of JIRA ARDAABD-713 : Add check for VCI
 *                          registers default values in FlsTst_Init(), if failed
 *                          report Dem event
 *                          Removed Write / Verify for FLSTST_DCRACOUTFGND and
 *                          FLSTST_DCRACOUTBGND registers
 * V2.1.0: 30.01.2017     : 1. As part of JIRA ARDAABD-714 added suffix for
 *                          RENESAS_CF1STERSTR_VCI register
 *                          As part of ARDAABD-566:
 *                          2. Removed Write verify for DCRAnCOUT and DCRAnCIN
 *                          registers
 *                          3. Reported Det error FLSTST_E_PARAM_INVALID if
 *                          HWConsistencyMode is not FLSTST_STATIC or
 *                          FLSTST_DYNAMIC
 *                          4. Corrected alignment
 * V2.1.1: 03-Feb-2017    : As part of JIRA ARDAABD-496:
 *                          1. Removed checks of FLSTST_DCRACINBGND and
 *                          FLSTST_DCRACINFGND registers from
 *                          FlsTst_CheckHWConsistency interface
 *                          2. Updated check of FLSTST_CFECCCTL_VCIL register
 *                          regarding the check of PROT0 and PROT1 bits which
 *                          are always read as 0
 *                          3. Called Det_ReportError inside the
 *                          FlsTst_CheckHWConsistency interface only if
 *                          FLSTST_DEV_ERROR_DETECT is STD_ON
 * V2.1.2: 03-Feb-2017    : As part of JIRA ARDAABD-933:
 *                          1. Updated FLSTST_C_SW_MAJOR_VERSION and
 *                          FLSTST_C_SW_MINOR_VERSION to the correct values
 * V2.1.3: 16-Mar-2017    : 1. Updated mask value for FLSTST_CF1STERSTR_VCILL
 *                          register as part of JIRA ARDAABD-714
 *                          2. Updated check of LucExpectedError and
 *                          LulEccSaveAddress in FlsTst_TestEcc Api as part of
 *                          JIRA ARDAABD-943
 *                          3. Added traceability comments as part of JIRA
 *                          ARDAABD-1211
 *                          4. Updated header of all interfaces by including
 *                          FLSTST_ENTER_CRITICAL_SECTION and
 *                          FLSTST_EXIT_CRITICAL_SECTION as part of JIRA
 *                          ARDAABD-933
 *                          5. Updated header of ReadLoadMemData interface as
 *                          part of JIRA ARDAABD-933
 * V2.1.4: 05-Jul-2017    : Updated Det entry condition for FlsTst_StartFgnd
 *                          Implemented 2-bit test pattern in FlsTst_TestEcc
 *                          Added FlsTst_InitRAMMirror function.
 *                          ARDAABD-1569: Test interval handling improved
 * V2.1.5: 28-Aug-2017    : Added justifications for MISRA Violations and QAC
 *                          Warnings which cannot be removed. Removed tags and
 *                          justification for MISRA Violation message (4:3138).
 * V2.1.6: 29-Sep-2017    : As part of JIRA ARDAABD-1626: Always check for the
 *                          condition first and if DET is ON, report DET
 *                          error when condition fails.
 *                          As part of JIRA ARDAABD-1718 Added traceability
 *                          comments.
 *                          Updated justifications for MISRA Violations and QAC
 *                          Warnings.
 * V2.1.7: 21-Jan-2018    : Fixed register inconsistencies
 * V2.1.8: 12-Jul-2018    : 1. As part of #ARDAABD-3631, Function banner of API
 *                          is updated.
 *                          2. As part of #ARDAABD-3756, Updated Reference tags
 *                          3. As part of #ARDAABD-3842:
 *                             a. Removed duplicate
 *                                Requirement id's and mapped the required
 *                                Requirements for traceability
 *                             b. Added new Id FLSTST_ESDD_UD_102 to
 *                                improve traceability.
 * V2.1.9: 25-Oct-2019    : The following changes are made:
 *                          1.As part of ARDAABD-4639,
 *                            Handled QAC warnings.
 *                          2.Added information for QAC warnings(6:0857).
 */
/******************************************************************************/
/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements: FLSTST_ESDD_UD_051                                             */
/* Implements: EAAR_PN0034_NR_0007, EAAR_PN0034_FR_0052                       */
/* Implements: EAAR_PN0034_FR_0063, EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0020  */
/* Implements: EAAR_PN0034_FR_0066, EAAR_PN0034_NR_0012, EAAR_PN0034_FR_0065  */
/* Implements: EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0020, EAAR_PN0034_NR_0026  */
/* Implements: EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0018, EAAR_PN0034_NR_0018  */
/* Implements: EAAR_PN0034_FR_0060, EAAR_PN0034_NR_0045, EAAR_PN0034_FR_0068  */
/* Implements: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069  */
/* Implements: EAAR_PN0034_FR_0055, EAAR_PN0034_FR_0019, EAAR_PN0034_FR_0024  */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0087, EAAR_PN0034_FR_0067  */
/* Implements: EAAR_PN0034_FSR_0008, EAAR_PN0034_FR_0086                      */
/* Implements: AR_PN0078_NR_0103, AR_PN0078_NR_0110                           */
/* Implements: AR_PN0078_NR_0111, AR_PN0078_NR_0112                           */
/* Implements: FLSTST_ESDD_UD_017, FLSTST_ESDD_UD_063                         */
/* Implements: AR_PN0078_NR_0113                                              */
/* Implements: FlsTst028, FlsTst029                                           */
/* Implements: SWS_FlsTst_00028, SWS_FlsTst_00029                             */

/* Implements: FLSTST_ESDD_UD_018                                             */
/* Implements: FlsTst002, FlsTst003, FlsTst016, FlsTst145, FlsTst136          */
/* Implements: FlsTst134                                                      */
/* Implements: SWS_FlsTst_00003, SWS_FlsTst_00016                             */

/* Implements: FLSTST_ESDD_UD_062                                             */
/* Implements: FlsTst004, FlsTst007, FlsTst013, FlsTst161                     */
/* Implements: FlsTst010, EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0009          */
/* Implements: SWS_FlsTst_00007, SWS_FlsTst_00161                             */

/* Implements: FlsTst020                                                      */
/* Implements: EAAR_PN0034_FR_0030                                            */
/* Implements: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0005                     */
/* Implements: EAAR_PN0034_FSR_0010                                           */
/* Implements: AR_PN0040_FR_0036, SWS_FlsTst_00020                            */
/* Implements: FLSTST_ESDD_UD_014, FLSTST_ESDD_UD_010                         */
/* Implements: AR_PN0078_FR_0041, AR_PN0078_FR_0035                           */
/* Implements: EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0021  */

/* Implements: FLSTST_ESDD_UD_007, FLSTST_ESDD_UD_003                         */
/* Implements: FlsTst079, FlsTst081                                           */
/* Implements: SWS_FlsTst_00081                                               */

/* Implements: ECUC_FlsTst_00092, ECUC_FlsTst_00098, ECUC_FlsTst_00094,       */
/* Implements: ECUC_FlsTst_00150, ECUC_FlsTst_00096, ECUC_FlsTst_00097,       */
/* Implements: ECUC_FlsTst_00087, ECUC_FlsTst_00099, ECUC_FlsTst_00095,       */
/* Implements: ECUC_FlsTst_00170, ECUC_FlsTst_00171, ECUC_FlsTst_00152,       */
/* Implements: ECUC_FlsTst_00122, ECUC_FlsTst_00124, ECUC_FlsTst_00102,       */
/* Implements: ECUC_FlsTst_00103, ECUC_FlsTst_00105, ECUC_FlsTst_00106,       */
/* Implements: ECUC_FlsTst_00151, ECUC_FlsTst_00107, ECUC_FlsTst_00119,       */
/* Implements: ECUC_FlsTst_00123                                              */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for macro definitions and type definitions */
#include "FlsTst.h"
/* Included for RAM variable declarations */
#include "FlsTst_Ram.h"
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Implements: FLSTST_ESDD_UD_059 */
#if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_FlsTst.h"
#endif
/* Implements: FLSTST_ESDD_UD_094, FlsTst086_Conf, SWS_FlsTst_00149           */
/* Implements: SWS_FlsTst_00050                                               */
#if (FLSTST_START_FGND_API == STD_ON)
static FUNC(void, FLSTST_PRIVATE_CODE) ReadLoadMemData (volatile const uint8*
                     LpReadAddress, volatile uint32* DcraAddr, uint32 size);
#endif
#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
static FUNC(void, FLSTST_PRIVATE_CODE) FlsTst_InitRAMMirror (void);
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLSTST_C_AR_RELEASE_MAJOR_VERSION  FLSTST_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLSTST_C_AR_RELEASE_MINOR_VERSION  FLSTST_AR_RELEASE_MINOR_VERSION_VALUE
#define FLSTST_C_AR_RELEASE_REVISION_VERSION \
                                        FLSTST_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLSTST_C_SW_MAJOR_VERSION      2
#define FLSTST_C_SW_MINOR_VERSION      1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (FLSTST_AR_RELEASE_MAJOR_VERSION != FLSTST_C_AR_RELEASE_MAJOR_VERSION)
  #error "FlsTst.c : Mismatch in Release Major Version"
#endif

#if (FLSTST_AR_RELEASE_MINOR_VERSION != FLSTST_C_AR_RELEASE_MINOR_VERSION)
  #error "FlsTst.c : Mismatch in Release Minor Version"
#endif

#if (FLSTST_AR_RELEASE_REVISION_VERSION != FLSTST_C_AR_RELEASE_REVISION_VERSION)
  #error "FlsTst.c : Mismatch in Release Revision Version"
#endif

#if (FLSTST_SW_MAJOR_VERSION != FLSTST_C_SW_MAJOR_VERSION)
  #error "FlsTst.c : Mismatch in Software Major Version"
#endif

#if (FLSTST_SW_MINOR_VERSION != FLSTST_C_SW_MINOR_VERSION)
  #error "FlsTst.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) Increment or decrement operation                  */
/*                 performed on pointer.                                      */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Array indexing shall be the only allowed form of pointer   */
/*                 arithmetic.                                                */
/* Verification  : Increment operator used to get the next address.           */
/*                 However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0489)-2 and                           */
/*                 END Msg(4:0489)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access only the lower byte of the converted values      */
/*                 from the conversion register.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-3 and                           */
/*                 END Msg(4:0759)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : Since base address plus index is used for accessing the    */
/*                 configured parameter of each test block and maximum index  */
/*                 value is checking for validation.                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-4 and                           */
/*                 END Msg(4:0491)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 10.5                                          */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex        */
/*                 bitwise operations.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-5 and                           */
/*                 END Msg(4:4397)-5 tags in the code.                        */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Values for FLSTST_TEST_INTERVAL_ID_END_VALUE are           */
/*                 configurable. Message is reported for value 1.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-7 and                           */
/*                 END Msg(4:2984)-7 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                              QAC Warnings                                  **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3120) Hard coded 'magic' number, 'x'.                   */
/* Justification : Implementation requirement for initialization of specific  */
/*                 variable or array.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3120)-3 and                           */
/*                 END Msg(2:3120)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter is never modified and so it could   */
/*                 be declared with the 'const' qualifier.                    */
/* Justification : Parameter is not declared with the 'const' qualifier in    */
/*                 order to respect AUTOSAR SWS and module requirements.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-4 and                           */
/*                 END Msg(2:3227)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                  possible side effects.                                    */
/* Justification : There is no expression here, it is only a comparison .     */
/*                 between a MACRO value and a variable. This warning appears */
/*                 because the volatile and this is the desired functionality.*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-5 and                           */
/*                 END Msg(2:3416)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:2743) This 'do - while' loop controlling expression is */
/*                 a constant expression and its value is 'false'. The loop   */
/*                 will only be executed once.                                */
/* Justification : This may be the case for this configuration. For other     */
/*                 configurations this controlling expression will be true    */
/*                 and loop will execute more than once.                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2743)-6 and                           */
/*                 END Msg(2:2743)-6 tags in the code.                        */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Justification : Direct register access by cast of register address to      */
/*                 volatile register type.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-7 and                           */
/*                 END Msg(2:3892)-7 tags in the code.                        */
/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/*                                                                            */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-8 and                           */
/*                 END Msg(2:2824)-8 tags in the code.                        */
/******************************************************************************/

/* 9. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-9 and                           */
/*                 END Msg(2:2814)-9 tags in the code.                        */
/******************************************************************************/

/* 10. QAC Warning:                                                           */
/* Message       : (2:3441) Function call argument is an expression with      */
/*                  possible side effects.                                    */
/* Justification : Function will write a result in a register as input. There */
/*                 is no impact on functionality.                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3441)-10 and                          */
/*                 END Msg(2:3441)-10 tags in the code.                       */
/******************************************************************************/

/* 11. QAC Warning:                                                           */
/* Message       : (2:2204) 'case' is not aligned to match its controlling    */
/*                 'switch' statement.                                        */
/* Justification : Coding guidelines id 3.1.8. Style_Format_008 has           */
/*                 been respected.                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2204)-11 and                          */
/*                 END Msg(2:2204)-11 tags in the code.                       */
/******************************************************************************/

/* 12. QAC Warning:                                                           */
/* Message       : (2:2016) This 'switch' statement 'default' clause is       */
/*                 empty.                                                     */
/* Justification : Code will not be reached since parameter LpFlsTstBlock is  */
/*                 loaded with FlsTst_GpBgndBlkConfig which will have         */
/*                 information  from configuration and will contain           */
/*                 information regarding test algorithm.                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-12 and                          */
/*                 END Msg(2:2016)-12 tags in the code.                       */
/******************************************************************************/

/* 13. QAC Warning:                                                           */
/* Message       : (6:0857) [L] Number of macro definitions exceeds 1024      */
/*                 - program does not conform strictly to ISO:C90.            */
/* Justification : Number of macro definitions is influenced by the generic   */
/*                 files included.                                            */
/*                 The generic files contain a high number of macros.         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-13 and                          */
/*                 END Msg(6:0857)-13 tags in the code.                       */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : FlsTst_InitRAMMirror
**
** Service ID            : NA
**
** Description           : Internal function initialize the default values
**                         of the mirrored registers.
**
** Sync/Async            : NA
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements: FLSTST_ESDD_UD_058                                             */
#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
#define FLSTST_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
static FUNC(void, FLSTST_PRIVATE_CODE) FlsTst_InitRAMMirror (void)
{
  FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX] = (uint32)0;
  FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX] = (uint32)0;
#if(FLSTST_TEST_ECC_API == STD_ON)
  FlsTst_RamMirror[FLSTST_CFECCCTL_VCI_IDX] = (uint32)0;
/* QAC Warning: START Msg(2:3120)-3 */
  FlsTst_RamMirror[FLSTST_CFERRINT_VCI_IDX] = (uint32)3;
/* END Msg(2:3120)-3 */
#endif
}
#define FLSTST_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif

/*******************************************************************************
** Function Name         : FlsTst_Init
**
** Service ID            : 0x00
**
** Description           : This API performs the initialization of the FLSTST
**                         Driver Component.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : FlsTst_GpConfigPtr, FlsTst_GpBgndBlkConfig,
**                         FlsTst_GpFgndBlkConfig, FlsTst_GenOverallBgndResult,
**                         FlsTst_GenLastFgndResult,
**                         FlsTst_GulLastFgndSignature,
**                         FlsTst_GulLastBgndSignature,
**                         FlsTst_GulTestIntervalId, FlsTst_GenExeState,
**                         FlsTst_GVar.FlsTst_GenBgndCheckState,
**                         FlsTst_GVar.FlsTst_GusBgndConfigIndex,
**                         FlsTst_GVar.FlsTst_GulCalculatedCrc,
**                         FlsTst_GVar.FlsTst_GulReadAddress
**
** Function(s) invoked   : Det_ReportError, FlsTst_InitRAMMirror
**
** Registers Used        : DCRAnCIN, DCRAnCOUT, DCRAnCTL, CF1STEADR0_VCI,
**                         CFECCCTL_VCIL, CFERRINT_VCILL, CF1STERSTR_VCILL,
**                         CFSTSTCTL_VCI
*******************************************************************************/
#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Implementation of FlsTst_Init API */
/* Implements:  FLSTST_ESDD_UD_031                                            */
/* Implements:  FlsTst011, FlsTst017, FlsTst020, FlsTst022, FlsTst023         */
/* Implements:  FlsTst025, FlsTst026, FlsTst073, FlsTst028                    */
/* Implements:  SWS_FlsTst_00011, SWS_FlsTst_00017, SWS_FlsTst_00020          */
/* Implements:  SWS_FlsTst_00022, SWS_FlsTst_00025                            */
/* Implements:  SWS_FlsTst_00073, SWS_FlsTst_00028                            */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0081 */
/* Implements:  EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0067                      */
/* Implements:  EAAR_PN0034_FR_0068, EAAR_PN0034_FSR_0001,FlsTst152_Conf      */
/* Implements:  EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0010                    */
/* Implements:  EAAR_PN0034_NR_0020, AR_PN0040_FR_0036                        */

/* Implements:  FLSTST_ESDD_UD_015,                                           */
/* Implements:  AR_PN0078_FSR_0037, AR_PN0078_FSR_0039                        */
/* Implements:  FlsTst004, FlsTst007, FlsTst016, FlsTst013, FlsTst161         */
/* Implements:  FlsTst010, EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0009         */
/* Implements:  SWS_FlsTst_00007, SWS_FlsTst_00016, SWS_FlsTst_00161          */
/* Implements:  FlsTst006, FlsTst008, FlsTst009, FlsTst012, FlsTst033         */
/* Implements:  FlsTst039, FlsTst072, FlsTst133, FlsTst014                    */
/* Implements:  FlsTst083_Conf, FlsTst171_Conf, FlsTst170_Conf                */
/* Implements:  SWS_FlsTst_00033, SWS_FlsTst_00039, SWS_FlsTst_00072          */
/* Implements:  ECUC_FlsTst_00083, ECUC_FlsTst_00171                          */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_089, FLSTST_ESDD_UD_061    */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(void, FLSTST_PUBLIC_CODE) FlsTst_Init
(P2CONST(FlsTst_ConfigType, AUTOMATIC, FLSTST_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-4 */
{
  /* Local variable to hold the DET status */
  Std_ReturnType LenDetErrFlag;

  /* Initialize error status flag to E_OK */
  LenDetErrFlag = E_OK;

  #if (FLSTST_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the FLSTST Driver is already Initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT != FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst014] */
    /* TRACE [R4, FlsTst025] */
    /* Report Error to DET */
    (void)Det_ReportError(FLSTST_MODULE_ID,
             FLSTST_INSTANCE_ID, FLSTST_INIT_SID, FLSTST_E_ALREADY_INITIALIZED);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  #endif /* End of if (FLSTST_ALREADY_INIT_DET_CHECK == STD_ON) */

  /* Check if the Configuration pointer is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst023] */
    /* TRACE [R4, FlsTst014] */
    /* Report Error to DET */
    (void)Det_ReportError(FLSTST_MODULE_ID,
              FLSTST_INSTANCE_ID, FLSTST_INIT_SID, FLSTST_E_PARAM_CONFIG);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    /* Set the error status flag to E_OK */
    LenDetErrFlag = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any DET was reported */
  if (E_OK == LenDetErrFlag)
  {
    /* MISRA Violation: START Msg(4:0303)-1 */
    if ((FLSTST_CF1STEADR0_VCI != CF1STEADR0_VCI_DEFAULT)  ||
        (FLSTST_CFECCCTL_VCIL  != CFECCCTL_VCI_DEFAULT)    ||
        (FLSTST_CFERRINT_VCILL != CFERRINT_VCI_DEFAULT)    ||
        (FLSTST_CF1STERSTR_VCILL != CF1STERSTR_VCI_DEFAULT)  ||
        (FLSTST_CFSTSTCTL_VCI  != CFSTSTCTL_VCI_DEFAULT))
    /* END Msg(4:0303)-1 */
    {
       Dem_ReportErrorStatus(FLSTST_E_ECC_FAILED, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* Initialize the module only if Database is present */
      /* MISRA Violation: START Msg(4:4397)-5 */
      if (FLSTST_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
      /* END Msg(4:4397)-5 */
      {
        #if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)
        /*Initialization of RAM Mirror before any register is set.*/
        FlsTst_InitRAMMirror();
        #endif
        /* Set the FlsTst global configptr */
        FlsTst_GpConfigPtr = ConfigPtr;
        /* MISRA Violation: START Msg(4:0303)-1 */
        /* QAC Warning: START Msg(2:2743)-6 */
        /* QAC Warning: START Msg(2:3892)-7 */
        /* Initialize the registers to default values */
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACINBGND,
                                    FLSTST_LONG_WORD_ZERO);
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                    FLSTST_DCRACOUT_RESET_VAL^
                                    FLSTST_DCRACOUT_RESET_VAL);
        FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                    FLSTST_ZERO,
                                    FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
        FLSTST_CHECK_WRITE_VERIFY_INIT(FLSTST_DCRACTLBGND,
                                       FLSTST_ZERO,
                                       FLSTST_RAM_DCRACTL_MASK_8BIT,
                                       FLSTST_INIT_SID);
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACINFGND,
                                    FLSTST_LONG_WORD_ZERO);
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                                    FLSTST_DCRACOUT_RESET_VAL^
                                    FLSTST_DCRACOUT_RESET_VAL);
        FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                                    FLSTST_ZERO,
                                    FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
        FLSTST_CHECK_WRITE_VERIFY_INIT(FLSTST_DCRACTLFGND,
                                       FLSTST_ZERO,
                                       FLSTST_RAM_DCRACTL_MASK_8BIT,
                                       FLSTST_INIT_SID);
        /* END Msg(4:0303)-1 */
        /* END Msg(2:2743)-6 */
        /* END Msg(2:3892)-7 */
        /* Load start address of Bgnd config array */
        FlsTst_GpBgndBlkConfig = ConfigPtr->pFlsTstBgndBlkConfig;
        /* Load start address of Fgnd config array */
        FlsTst_GpFgndBlkConfig = ConfigPtr->pFlsTstFgndBlkConfig;
        /* set the bgnd test result as not tested */
        FlsTst_GenOverallBgndResult = FLSTST_RESULT_NOT_TESTED;
        FlsTst_GenLastFgndResult = FLSTST_NOT_TESTED;
        /* QAC Warning: START Msg(2:3892)-7 */
        FlsTst_GulLastFgndSignature = FLSTST_ZERO;
        FlsTst_GulLastBgndSignature = FLSTST_ZERO;
        FlsTst_GulTestIntervalId = FLSTST_ZERO;
        /* END Msg(2:3892)-7 */
        FlsTst_GblTestComplete = FLSTST_FALSE;
        /* Initialize the global variable to default value  */
        /* QAC Warning: START Msg(2:3892)-7 */
        FlsTst_GVar.FlsTst_GusBgndConfigIndex = FLSTST_ZERO;
        FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_ZERO;
        /* set bgnd test block start address as first block base address */
        /* MISRA Violation: START Msg(4:0491)-4 */
        /* QAC Warning: START Msg(2:2824)-8 */
        FlsTst_GVar.FlsTst_GulReadAddress =
                   FlsTst_GpBgndBlkConfig[FLSTST_ZERO].ulFlsTstBlockBaseAddress;
        /* END Msg(4:0491)-4 */
        /* END Msg(2:2824)-8 */
        /* Get Ecc error status */
        FlsTst_GddEccErrorDetail.ucEccStatus = FLSTST_ZERO;
        /* Get the ECC error address */
        FlsTst_GddEccErrorDetail.ulEccFaultAddress = FLSTST_ZERO;
        /* END Msg(2:3892)-7 */
        FlsTst_GVar.FlsTst_GenBgndCheckState = FLSTST_BGND_CHECK_INIT;
        /* Set the driver status to FlsTst init state  */
        FlsTst_GenExeState = FLSTST_INIT;
      }
      else
      {
        #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
        /* TRACE [R4, FlsTst014] */
        /* Implements EAAR_PN0034_FR_0016 */
        /* Report Error to DET */
        (void)Det_ReportError(FLSTST_MODULE_ID,
                FLSTST_INSTANCE_ID, FLSTST_INIT_SID, FLSTST_E_INVALID_DATABASE);
        #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
      }
    }
  } /* End of if (E_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
} /* End of API FlsTst_Init */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : FlsTst_DeInit
**
** Service ID            : 0x01
**
** Description           : This API performs the De-Initialization of the FLSTST
**                         Driver Component.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The FlsTst Driver must be initialized
**
** Global Variables Used : FlsTst_GenOverallBgndResult,
**                         FlsTst_GenLastFgndResult, FlsTst_GulTestIntervalId,
**                         FlsTst_GulLastFgndSignature,
**                         FlsTst_GulLastBgndSignature, FlsTst_GenExeState,
**                         FlsTst_GVar.FlsTst_GusBgndConfigIndex,
**                         FlsTst_GVar.FlsTst_GulCalculatedCrc,
**                         FlsTst_GVar.FlsTst_GulReadAddress,
**                         FlsTst_GVar.FlsTst_GenBgndCheckState
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : DCRAnCIN, DCRAnCOUT, DCRAnCTL
*******************************************************************************/
#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst027] */
/* TRACE [R4, FlsTst028] */
/* Implementation of FlsTst_DeInit API */
/* Implements:  FLSTST_ESDD_UD_032                                            */
/* Implements:  FlsTst011, FlsTst027, FlsTst028, FlsTst029, FlsTst014         */
/* Implements:  SWS_FlsTst_00011, SWS_FlsTst_00027, SWS_FlsTst_00028          */
/* Implements:  SWS_FlsTst_00029                                              */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_052                        */
FUNC(void, FLSTST_PUBLIC_CODE) FlsTst_DeInit(void)
{
  /* Check if the FLSTST Module is not Initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report Error to DET */
    (void)Det_ReportError(FLSTST_MODULE_ID,
            FLSTST_INSTANCE_ID, FLSTST_DEINIT_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* set the job result as Not Tested */
    FlsTst_GenOverallBgndResult = FLSTST_RESULT_NOT_TESTED;
    /* Initialize the global variable to default values */
    FlsTst_GenLastFgndResult = FLSTST_NOT_TESTED;
    /* QAC Warning: START Msg(2:3892)-7 */
    FlsTst_GulTestIntervalId = FLSTST_ZERO;
    FlsTst_GVar.FlsTst_GusBgndConfigIndex = FLSTST_ZERO;
    FlsTst_GulLastFgndSignature = FLSTST_ZERO;
    FlsTst_GulLastBgndSignature = FLSTST_ZERO;
    FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_ZERO;
    /* set test block start address as 0 */
    FlsTst_GVar.FlsTst_GulReadAddress = FLSTST_ZERO;
    /* END Msg(2:3892)-7 */
    FlsTst_GVar.FlsTst_GenBgndCheckState = FLSTST_BGND_CHECK_INIT;
    /* TRACE [R4, FlsTst029] */
    /* Set the driver status to idle */
    FlsTst_GenExeState = FLSTST_UNINIT;
    FlsTst_GblTestComplete = FLSTST_FALSE;
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* QAC Warning: START Msg(2:3892)-7 */
    /* QAC Warning: START Msg(2:2743)-6 */
    /* Initialize the registers to default values */
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                FLSTST_ZERO,
                                FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_DCRACTL_MASK_8BIT,
                                      FLSTST_DEINIT_SID);
    FLSTST_WRITE_REG_ONLY(FLSTST_DCRACINBGND,
                                    FLSTST_LONG_WORD_ZERO);
    FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                FLSTST_DCRACOUT_RESET_VAL);
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                                FLSTST_ZERO,
                                FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLFGND,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_DCRACTL_MASK_8BIT,
                                      FLSTST_DEINIT_SID);
    FLSTST_WRITE_REG_ONLY(FLSTST_DCRACINFGND,
                                FLSTST_LONG_WORD_ZERO);
    FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                                FLSTST_DCRACOUT_RESET_VAL);
    /* END Msg(4:0303)-1 */
    /* END Msg(2:3892)-7 */
    /* END Msg(2:2743)-6 */
  }
} /* End of API FlsTst_DeInit */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : FlsTst_StartFgnd
**
** Service ID            : 0x02
**
** Description           : This API will execute foreground Flash Test.
**
** Sync/Async            : synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : FgndBlockId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType - Returns E_OK if Foreground
**                         test processed else returns E_NOT_OK if Foreground
**                         test has not been accepted.
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GpFgndBlkConfig,
**                         FlsTst_GpConfigPtr, FlsTst_GenLastFgndResult,
**                         FlsTst_GulLastFgndSignature
**
** Function(s) invoked   : Det_ReportError,
**                         ReadLoadMemData,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : DCRAnCIN, DCRAnCOUT, DCRAnCTL
*******************************************************************************/
#if (FLSTST_START_FGND_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* TRACE [R4, FlsTst050] */
/* TRACE [R4, FlsTst149] */
/* Implementation of FlsTst_StartFgnd API */
/* Implements:  FLSTST_ESDD_UD_034                                            */
/* Implements:  FlsTst143, FlsTst149, FlsTst050, FlsTst051, FlsTst033         */
/* Implements:  FlsTst011, FlsTst014, SWS_FlsTst_00143                        */
/* Implements:  FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_064                        */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
/* Implements:  AR_PN0078_FSR_0038                                            */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE) FlsTst_StartFgnd
                                          (FlsTst_BlockIdFgndType FgndBlockId)
/* END Msg(2:3227)-4 */
{
  /* Local variable to hold the return value of the function */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold the read address */
  volatile uint32 LulReadAddress;
  /* Local variable to hold the block size */
  uint32 LulCurrentTestBlockSize;
  /* Local variable to hold stored crc */
  uint32 LulStoredCrc;
  /* Local variable to hold the signature address */
  uint32 LulSignatureAddress;
  /* Local variable to hold the calculated CRC */
  uint32  LulCalculatedCrc;
  /* Local variable to hold the loop count */
  uint32 LulLoopCount;
  /* Local variable to hold the number of byte to process for signature */
  uint8 LucByteToProcess;
  /* Local Pointer to FlsTstBlockConfigType configuration */
  P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)LpFlsTstBlock;

  /* MISRA Violation: START Msg(4:0759)-3 */
  /* Local union variable to access crc value */
  FlsTst_CrcConvert LddCrcConvert;
  /* END Msg(4:0759)-3 */

  /* Set the default value */
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:3892)-7 */
  LulCalculatedCrc = FLSTST_ZERO;
  LddCrcConvert.ulCrc32Data = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */
  LucByteToProcess = FLSTST_ZERO;
  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that the component is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                                       FLSTST_START_FGND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* QAC Warning: START Msg(2:2814)-9 */
  if (FgndBlockId >= (FlsTst_GpConfigPtr->ulFlsTstMaxFgndBlkNo))
  /* END Msg(2:2814)-9 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst007] */
    /* TRACE [R4, FlsTst014] */
    /* TRACE [R4, FlsTst033] */
    /* Report error to DET that block id is out of range  */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                            FLSTST_START_FGND_SID, FLSTST_E_PARAM_INVALID);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Accept the requested command when no DET errors are reported */
  /* QAC Warning: START Msg(2:3892)-7 */
  if ((E_OK == LenReturnValue) &&
      (FlsTst_GpConfigPtr->ulFlsTstMaxFgndBlkNo > FLSTST_ZERO))
  /* END Msg(2:3892)-7 */
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
    /* Get the corresponding block parameters */
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-8 */
    LpFlsTstBlock = &FlsTst_GpFgndBlkConfig[FgndBlockId];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-8 */
    /* QAC Warning: START Msg(2:2814)-9 */
    LulReadAddress = LpFlsTstBlock->ulFlsTstBlockBaseAddress;
    /* END Msg(2:2814)-9 */
    LulCurrentTestBlockSize = LpFlsTstBlock->ulFlsTstBlockSize;
    LulSignatureAddress = LpFlsTstBlock->ulFlsTstSignatureAddress;
    /* QAC Warning: START Msg(2:3892)-7 */
    LulStoredCrc = FLSTST_ZERO;
    /* Initialize the CRC value for new test */
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* QAC Warning: START Msg(2:2743)-6 */
    if (FLSTST_16BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      /* Select CRC16 and set input data bit width as 8 */
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                              FLSTST_CRC16CNTL,
                              FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLFGND,
                                    FLSTST_CRC16CNTL,
                                    FLSTST_RAM_DCRACTL_MASK_8BIT,
                                    FLSTST_START_FGND_SID);
      /* Load the initial value */
      FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                              FLSTST_CRC16_INITIAL_VALUE);
      /* Number of  byte to be read */
      LucByteToProcess = FLSTST_TWO;
    }
    else if (FLSTST_32BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      /* Select CRC32 and set input data bit width as 8 */
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                              FLSTST_CRC32CNTL,
                              FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLFGND,
                                    FLSTST_CRC32CNTL,
                                    FLSTST_RAM_DCRACTL_MASK_8BIT,
                                    FLSTST_START_FGND_SID);
      /* Load the initial value */
      if (FLSTST_TRUE == LpFlsTstBlock->ucFlsTstAddressDepdntCrc)
      {
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                             (uint32)LpFlsTstBlock->ulFlsTstBlockBaseAddress);
      }
      else
      {
        FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                              FLSTST_CRC32_INITIAL_VALUE);
      }
      /* Number of  byte to be read */
      LucByteToProcess = FLSTST_FOUR;
    }
    #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
    else if (FLSTST_8BIT_CRC_2F == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      /* Load the initial value */
      FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                                  FLSTST_CRC8_INITIAL_VALUE);
      /* Number of byte to be read */
      LucByteToProcess = FLSTST_ONE;
      /* Select CRC8 and set input data bit width as 8 */
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                              FLSTST_CRC8CNTL_2F,
                              FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLFGND,
                                        FLSTST_CRC8CNTL_2F,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_START_FGND_SID);
    }
    else if (FLSTST_8BIT_CRC_SAEJ1850 == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      /* Load the initial value */
      FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTFGND,
                              FLSTST_CRC8_INITIAL_VALUE);
      /* Number of byte to be read */
      LucByteToProcess = FLSTST_ONE;
      /* Select CRC8 and set input data bit width as 8 */
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLFGND,
                              FLSTST_CRC8CNTL_SAEJ1850,
                              FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLFGND,
                                        FLSTST_CRC8CNTL_SAEJ1850,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_START_FGND_SID);

    }
    #endif
    else
    {
      /* No action required */
    }
    /* END Msg(2:2743)-6 */
    /* QAC Warning: START Msg(2:3441)-10 */
    ReadLoadMemData((volatile const uint8*)LulReadAddress,
                     &FLSTST_DCRACINFGND, LulCurrentTestBlockSize);
    /* END Msg(2:3441)-10 */
    /* Read stored crc from signature address  */
    for (LulLoopCount = FLSTST_ZERO; LulLoopCount < LucByteToProcess;
                                 LulLoopCount++)
    {
      /* TRACE [R4, FlsTst069] */
      /* Read stored crc data from memory and store in array */
      /* QAC Warning: START Msg(2:2814)-9 */
      LddCrcConvert.ucCrcData4[(uint8)LulLoopCount]
              = (*((volatile uint8 *)(LulSignatureAddress)));
      /* Increase to next memory location */
      /* END Msg(2:2814)-9 */
      LulSignatureAddress++;
    }
    /* Get the calculated CRC value from DCRA unit
     *  and stored crc value.
     */

    if (FLSTST_16BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      LulCalculatedCrc = (uint16)FLSTST_DCRACOUTFGND;
      LulStoredCrc = LddCrcConvert.usCrc16Data;
    }
    else if (FLSTST_32BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
    {
      LulCalculatedCrc = (uint32)FLSTST_DCRACOUTFGND;
      LulStoredCrc = LddCrcConvert.ulCrc32Data;
    }
    #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
    else if ((FLSTST_8BIT_CRC_2F == LpFlsTstBlock->enFlsTstTestAlgorithm) ||
       (FLSTST_8BIT_CRC_SAEJ1850 == LpFlsTstBlock->enFlsTstTestAlgorithm))
    {
      LulCalculatedCrc = (uint8)FLSTST_DCRACOUTFGND;
      LulStoredCrc = LddCrcConvert.ucCrc8Data;
    }
    #endif
    else
    {
      /* No action required */
    }
    /* END Msg(2:3892)-7 */
    /* END Msg(4:0303)-1 */
    /* Check the calculated crc and stored crc*/
    if (LulCalculatedCrc == LulStoredCrc)
    {
      FlsTst_GenLastFgndResult = FLSTST_OK;
    }
    else
    {
      FlsTst_GenLastFgndResult = FLSTST_NOT_OK;
    }

    FlsTst_GulLastFgndSignature = LulCalculatedCrc;
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif

  } /* End of if (E_OK == LenReturnValue) */
  else
  {
    LenReturnValue = E_NOT_OK;
  }

  return(LenReturnValue);
} /* End of API FlsTst_StartFgnd */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif
/*******************************************************************************
** Function Name         : FlsTst_Abort
**
** Service ID            : 0x03
**
** Description           : This API will abort flash test operation in
**                         background mode and set the state to FLSTST_ABORTED
**
** Sync/Async            : synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst142] */
/* TRACE [R4, FlsTst030] */
/* Implementation of FlsTst_Abort API */
/* Implements:  FLSTST_ESDD_UD_035, FLSTST_ESDD_UD_004                        */
/* Implements:  FlsTst030, FlsTst031, FlsTst032, FlsTst142, FlsTst011         */
/* Implements:  SWS_FlsTst_00030, SWS_FlsTst_00031, SWS_FlsTst_00032          */
/* Implements:  SWS_FlsTst_00142, SWS_FlsTst_00011                            */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
FUNC(void, FLSTST_PUBLIC_CODE) FlsTst_Abort(void)
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;

  LenDetErrFlag = E_OK;
  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                                            FLSTST_ABORT_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenDetErrFlag)
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif

    /* TRACE [R4, FlsTst031] */
    /* Change the execution state */
    FlsTst_GenExeState = FLSTST_ABORTED;

    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
  } /* End of  if (E_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
} /* End of API FlsTst_Abort */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : FlsTst_Suspend
**
** Service ID            : 0x04
**
** Description           : This API suspend the ongoing bgnd flash test if
**                         the flash test state is RUNNING or INIT
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/

#if (FLSTST_SUSPEND_RESUME_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst036] */
/* TRACE [R4, FlsTst034] */
/* Implementation of FlsTst_Suspend API */
/* Implements:  FLSTST_ESDD_UD_036, FLSTST_ESDD_UD_066                        */
/* Implements:  FlsTst034, FlsTst036, FlsTst037, FlsTst088, FlsTst142         */
/* Implements:  FlsTst011, FlsTst014, FlsTst087_Conf                          */
/* Implements:  SWS_FlsTst_00034, SWS_FlsTst_00036, SWS_FlsTst_00037          */
/* Implements:  SWS_FlsTst_00088, SWS_FlsTst_00142, SWS_FlsTst_00011          */
/* Implements:  FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_095                        */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_Suspend(void)
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* Set the default DET return value */
  LenDetErrFlag = E_OK;
  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                                           FLSTST_SUSPEND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenDetErrFlag)
  {
    /* Suspend bgnd check only if it is in RUNNING or INIT state */
    /* Suspend command will process once bgnd atomic sequence completed, */
    /* if it is in running state */
    /* QAC Warning: START Msg(2:3416)-5 */
    if (FLSTST_RUNNING == FlsTst_GenExeState)
        /* END Msg(2:3416)-5 */
    {
      #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
      FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
      #endif

      /* Change status to suspend */
      FlsTst_GenExeState = FLSTST_SUSPENDED;

      #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
      FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
      #endif
    }
    /* QAC Warning: START Msg(2:3416)-5 */
    else if (FLSTST_INIT == FlsTst_GenExeState)
    /* END Msg(2:3416)-5 */
    {
      #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
      FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
      #endif

      /* TRACE [R4, FlsTst037] */
      /* Change status to suspend */
      FlsTst_GenExeState = FLSTST_SUSPENDED;

      #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
      FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
      #endif
    }
    else
    {
      /* No action required */
    }
  } /* End of  if (E_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
} /* End of API FlsTst_Suspend */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* #if (FLSTST_SUSPEND_RESUME_API == STD_ON) */



/*******************************************************************************
** Function Name         : FlsTst_Resume
**
** Service ID            : 0x05
**
** Description           : This API start the suspended bgnd check again .
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState,
**                         FlsTst_GVar.FlsTst_GulCalculatedCrc,
**                         FlsTst_GVar.FlsTst_GusBgndConfigIndex
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : DCRAnCOUT, DCRAnCTL
*******************************************************************************/
#if (FLSTST_SUSPEND_RESUME_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst035] */
/* TRACE [R4, FlsTst162] */
/* Implementation of FlsTst_Resume API */
/* Implements:  FlsTst035, FlsTst038, FlsTst039, FlsTst162, FlsTst089         */
/* Implements:  FlsTst011, FlsTst014, FlsTst087_Conf                          */
/* Implements:  SWS_FlsTst_00035, SWS_FlsTst_00038, SWS_FlsTst_00039          */
/* Implements:  SWS_FlsTst_00162, SWS_FlsTst_00089, SWS_FlsTst_00011          */
/* Implements:  FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_037, FLSTST_ESDD_UD_066    */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_Resume(void)
{
  /* Local pointer variable to hold the individual test block params */
  P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
                                                              LpFlsTstBlock;

  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
   /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                                     FLSTST_RESUME_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  /* Check current FLSTST execution state as SUSPEND otherwise report error */
  /* QAC Warning: START Msg(2:3416)-5 */
  else if (FLSTST_SUSPENDED != FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst007] */
    /* TRACE [R4, FlsTst014] */
    /* TRACE [R4, FlsTst039] */
    /* Report error to DET that module is not in suspend state */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                                     FLSTST_RESUME_SID, FLSTST_E_STATE_FAILURE);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_NOT_OK == LenDetErrFlag)
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
    /* Load the test block parameters based on the index */
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-8 */
    LpFlsTstBlock =
    &FlsTst_GpBgndBlkConfig[FlsTst_GVar.FlsTst_GusBgndConfigIndex];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-8 */
    /* Initialize the DCRA for resume the test */
     /* QAC Warning: START Msg(2:2814)-9 */
    switch (LpFlsTstBlock->enFlsTstTestAlgorithm)
    /* END Msg(2:2814)-9 */
    {
      /* MISRA Violation: START Msg(4:0303)-1 */
      #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
      case FLSTST_8BIT_CRC_2F:
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                  FLSTST_CRC8CNTL_2F,
                                  FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC8CNTL_2F,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_RESUME_SID);
      break;

      case FLSTST_8BIT_CRC_SAEJ1850:
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                  FLSTST_CRC8CNTL_SAEJ1850,
                                  FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC8CNTL_SAEJ1850,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_RESUME_SID);
      break;
      #endif

      /* QAC Warning: START Msg(2:2204)-11 */
      /* QAC Warning: START Msg(2:2743)-6 */
      /* QAC Warning: START Msg(2:3892)-7 */
      case FLSTST_16BIT_CRC:
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                  FLSTST_CRC16CNTL,
                                  FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC16CNTL,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_RESUME_SID);
      break;

      case FLSTST_32BIT_CRC:
      FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                  FLSTST_CRC32CNTL,
                                  FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
      FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC32CNTL,
                                        FLSTST_RAM_DCRACTL_MASK_8BIT,
                                        FLSTST_RESUME_SID);
      break;
      /* QAC Warning: START Msg(2:2016)-12 */
      default:
      break;
    }
    /* END Msg(2:2016)-12 */

    /* Reload previously calculated crc */
    FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                FlsTst_GVar.FlsTst_GulCalculatedCrc);


    /* END Msg(4:0303)-1 */
    /* END Msg(2:2204)-11 */
    /* END Msg(2:2743)-6 */
    /* END Msg(2:3892)-7 */

    /* TRACE [R4, FlsTst038] */
    FlsTst_GenExeState = FLSTST_RUNNING;

    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
  } /* End of  if (E_NOT_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
} /* End of API FlsTst_Resume */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* #if (FLSTST_SUSPEND_RESUME_API == STD_ON) */


/*******************************************************************************
** Function Name         : FlsTst_GetCurrentState
**
** Service ID            : 0x06
**
** Description           : This API Returns the FLSTST module state.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_StateType
**
** Preconditions         : None
**
** Global Variables Used : FlsTst_GenExeState
**
** Function(s) invoked   : FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_CURRENT_STATE_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst040] */
/* Implementation of FlsTst_GetCurrentState API */
/* Implements:  FLSTST_ESDD_UD_033, FLSTST_ESDD_UD_091                        */
/* Implements:  FlsTst040, FlsTst041, FlsTst091, FlsTst092_Conf               */
/* Implements:  SWS_FlsTst_00040, SWS_FlsTst_00041, SWS_FlsTst_00091          */
/* Implements:  FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_059                        */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014, SWS_FlsTst_00051                                   */

FUNC(FlsTst_StateType, FLSTST_PUBLIC_CODE)FlsTst_GetCurrentState(void)
{
  /* Local variable to store the driver status */
  FlsTst_StateType LenStatus;

  #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
  #endif

  /* Read the current state of the driver */
  LenStatus = FlsTst_GenExeState;

  #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
  #endif
  /* TRACE [R4, FlsTst041] */
  /* return the current state of the driver */
  return(LenStatus);
} /* End of API FlsTst_GetCurrentState */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_CURRENT_STATE_API == STD_ON) */

/*******************************************************************************
** Function Name         : FlsTst_GetTestResultBgnd
**
** Service ID            : 0x07
**
** Description           : This API Returns the FLSTST module bgnd check result
**                         and Test Interval Id of the last background test
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_TestResultBgndType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState,
**                         FlsTst_GulTestIntervalId,
**                         FlsTst_GenOverallBgndResult
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON)
#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst042] */
/* Implementation Of FlsTst_GetTestResultBgnd API */
/* Implements:  FLSTST_ESDD_UD_038, FLSTST_ESDD_UD_068, FLSTST_ESDD_UD_004    */
/* Implements:  FlsTst042, FlsTst043, FlsTst093, FlsTst011, FlsTst094_Conf    */
/* Implements:  SWS_FlsTst_00042, SWS_FlsTst_00043, SWS_FlsTst_00093          */
/* Implements:  SWS_FlsTst_00011                                              */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
/* Implements:  FLSTST_ESDD_UD_096                                            */
FUNC(FlsTst_TestResultBgndType, FLSTST_PUBLIC_CODE)
                                        FlsTst_GetTestResultBgnd(void)
{
  /* Structure variable that contains the result of last bgnd check */
  VAR(FlsTst_TestResultBgndType, FLSTST_NOINIT_DATA) LddTestResultBgnd;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;

  /* Initialize the return value */
  /* QAC Warning: START Msg(2:3892)-7 */
  LddTestResultBgnd.ulTestIntervalId = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */
  LddTestResultBgnd.enTestResultBgnd = FLSTST_RESULT_NOT_TESTED;

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                              FLSTST_GET_TEST_RESULT_BGND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_NOT_OK == LenDetErrFlag)
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif

    /* Get the current test interval id and overall Bgnd test result  */
    LddTestResultBgnd.ulTestIntervalId = FlsTst_GulTestIntervalId;
    LddTestResultBgnd.enTestResultBgnd = FlsTst_GenOverallBgndResult;

    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
  } /* end of if (E_NOT_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }

  /* TRACE [R4, FlsTst043] */
  /* return the result of the last bgnd test */
  return(LddTestResultBgnd);
} /* End of API FlsTst_GetTestResultBgnd */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON) */

/*******************************************************************************
** Function Name         : FlsTst_GetTestResultFgnd
**
** Service ID            : 0x0f
**
** Description           : This API Returns  last fgnd check result.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_TestResultFgndType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GenLastFgndResult
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_TEST_RESULT_FGND_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst112] */
/* Implementation Of FlsTst_GetTestResultFgnd API */
/* Implements:  FLSTST_ESDD_UD_039, FLSTST_ESDD_UD_097                        */
/* Implements:  FlsTst112, FlsTst113, FlsTst114, FlsTst011                    */
/* Implements:  SWS_FlsTst_00112, SWS_FlsTst_00113, SWS_FlsTst_00114          */
/* Implements:  SWS_FlsTst_00011, FlsTst150_Conf                              */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_052                        */
FUNC(FlsTst_TestResultFgndType, FLSTST_PUBLIC_CODE)
                                             FlsTst_GetTestResultFgnd(void)
{
  /* Local variable to store the last Fgnd test result status */
  FlsTst_TestResultFgndType LenReturnValue;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* Initialize the return value */
  LenReturnValue = FLSTST_NOT_TESTED;

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
     /* TRACE [R4, FlsTst011] */
     /* TRACE [R4, FlsTst014] */
     /* Report error to DET that module is not initialized */
     (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                              FLSTST_GET_TEST_RESULT_FGND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* Get the last Fgnd test result of the driver */
    LenReturnValue = FlsTst_GenLastFgndResult;
  } /* end of if (E_NOT_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
  /* TRACE [R4, FlsTst113] */
  /* return the result of the last fgnd test */
  return(LenReturnValue);
} /* End of API FlsTst_GetTestResultFgnd */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_TEST_RESULT_FGND_API == STD_ON) */


/*******************************************************************************
** Function Name         : FlsTst_GetTestSignatureBgnd
**
** Service ID            : 0x09
**
** Description           : This API Returns signature of last bgnd check and
**                         Test Interval Id of the last background test.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_TestSignatureBgndType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GulTestIntervalId,
**                         FlsTst_GulLastBgndSignature,
**                         FlsTst_GenOverallBgndResult
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst054] */
/* Implementation Of FlsTst_GetTestSignatureBgnd API */
/* Implements:  FLSTST_ESDD_UD_041, FLSTST_ESDD_UD_098                        */
/* Implements:  FlsTst054, FlsTst055, FlsTst056, FlsTst115, FlsTst011         */
/* Implements:  SWS_FlsTst_00054, SWS_FlsTst_00055, SWS_FlsTst_00056          */
/* Implements:  SWS_FlsTst_00115, SWS_FlsTst_00011, FlsTst096_Conf            */
/* Implements:  FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_052                        */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014, FlsTst160_Conf                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_054, FLSTST_ESDD_UD_059    */
FUNC(FlsTst_TestSignatureBgndType, FLSTST_PUBLIC_CODE)
     FlsTst_GetTestSignatureBgnd(void)
{
  /* Local variable to store the driver bgnd test result */
  FlsTst_TestSignatureBgndType LddTestResult;

  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;
  /* QAC Warning: START Msg(2:3892)-7 */
  LddTestResult.ulTestIntervalId = FLSTST_ZERO;
  /* TRACE [R4, FlsTst115] */
  LddTestResult.ulSignatureValue = FLSTST_ZERO;
   /* END Msg(2:3892)-7 */

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
     (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                           FLSTST_GET_TEST_SIGNATURE_BGND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */

  if (E_NOT_OK == LenDetErrFlag)
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif

    /* Get the last test interval id */
    LddTestResult.ulTestIntervalId = FlsTst_GulTestIntervalId;
    #if (FLSTST_TEST_RESULT_SIGNATURE == STD_ON)
    /* Load the signature of the last Bgnd check */
    LddTestResult.ulSignatureValue = FlsTst_GulLastBgndSignature;
    #else
    /* Load the signature of the last Bgnd check */
    LddTestResult.ulSignatureValue = (uint32)FlsTst_GenOverallBgndResult;
    #endif

    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
  } /* end of if (E_NOT_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }
  /* TRACE [R4, FlsTst055] */
  /* return the test interval id and signature of the last bgnd test */
  return(LddTestResult);
} /* End of API FlsTst_GetTestSignatureBgnd */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON) */


/*******************************************************************************
** Function Name         : FlsTst_GetTestSignatureFgnd
**
** Service ID            : 0x0a
**
** Description           : This API Returns signature of last fgnd check .
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_TestSignatureFgndType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GulLastFgndSignature
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* TRACE [R4, FlsTst057] */
/* Implementation Of FlsTst_GetTestSignatureFgnd API */
/* Implements:  FLSTST_ESDD_UD_042, FLSTST_ESDD_UD_099, FLSTST_ESDD_UD_004    */
/* Implements:  FlsTst057, FlsTst058, FlsTst059, FlsTst116, FlsTst011         */
/* Implements:  SWS_FlsTst_00057, SWS_FlsTst_00058, SWS_FlsTst_00059          */
/* Implements:  SWS_FlsTst_00116, SWS_FlsTst_00011, FlsTst097_Conf            */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
FUNC(FlsTst_TestSignatureFgndType, FLSTST_PUBLIC_CODE)
     FlsTst_GetTestSignatureFgnd(void)
{
  /* Local variable to store the driver fgnd test result status */
  FlsTst_TestSignatureFgndType LulTestResult;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;
  /* TRACE [R4, FlsTst116] */
  /* QAC Warning: START Msg(2:3892)-7 */
  LulTestResult.ulSignatureValue = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */
  #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
  #endif

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                           FLSTST_GET_TEST_SIGNATURE_FGND_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* Load the signature of the last fgnd check */
    LulTestResult.ulSignatureValue =  FlsTst_GulLastFgndSignature;
  }
  else
  {
    /* No action required */
  }
  #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
  FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
  #endif
  /* TRACE [R4, FlsTst058] */
  /* return the signature of the last Fgnd test */
  return(LulTestResult);
} /* End of API FlsTst_GetTestSignatureFgnd */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON) */

/*******************************************************************************
** Function Name         : FlsTst_GetErrorDetails
**
** Service ID            : 0x0b
**
** Description           : This API Returns the FLSTST module ECC circuitry
**                         test result which include ECC error status
**                         and fault address.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : FlsTst_ErrorDetailsType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GddEccErrorDetail
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#if (FLSTST_GET_ERROR_DETAILS_API == STD_ON)
#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst060] */
/* Implementation Of FlsTst_GetErrorDetails API */
/* Implements:  FLSTST_ESDD_UD_043, FLSTST_ESDD_UD_100                        */
/* Implements:  FlsTst060, FlsTst061, FlsTst062, FlsTst011                    */
/* Implements:  SWS_FlsTst_00060, SWS_FlsTst_00061, SWS_FlsTst_00062          */
/* Implements:  SWS_FlsTst_00011, FlsTst098_Conf                              */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_052                        */
FUNC(FlsTst_ErrorDetailsType, FLSTST_PUBLIC_CODE)
                                        FlsTst_GetErrorDetails(void)
{
  /* Structure variable that contains the result of last bgnd check */
  VAR(FlsTst_ErrorDetailsType, FLSTST_NOINIT_DATA) LddEccTestResult;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* Initialize the return value */
  /* QAC Warning: START Msg(2:3892)-7 */
  LddEccTestResult.ucEccStatus = FLSTST_ZERO;
  LddEccTestResult.ulEccFaultAddress = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */

  /* Set the default DET return values */
  LenDetErrFlag = E_NOT_OK;

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                              FLSTST_GET_ERROR_DETAILS_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* TRACE [R4, FlsTst061] */
    /* Get the current ecc test result */
    LddEccTestResult = FlsTst_GddEccErrorDetail;
  } /* end of if (E_NOT_OK == LenDetErrFlag) */
  else
  {
    /* No action required */
  }

  /* return the result of the last ecc test */
  return(LddEccTestResult);
} /* End of API FlsTst_GetErrorDetails */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_GET_ERROR_DETAILS_API == STD_ON) */

/*******************************************************************************
** Function Name         : FlsTst_TestEcc
**
** Service ID            : 0x0c
**
** Description           : This API Service executes a test of ECC hardware.
**                         This is only applicable in case the hardware
**                         provides such functionality.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GenExeState, FlsTst_GddEccErrorDetail
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : CF1STEADR0_VCI, CFECCCTL_VCIL, CFERRINT_VCILL
**                         CF1STERSTR_VCILL, CFSTCLR_VCILL
*******************************************************************************/
#if (FLSTST_TEST_ECC_API == STD_ON)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst064] */
/* TRACE [R4, FlsTst063] */
/* Implementation of FlsTst_TestEcc API */
/* Implements:  FLSTST_ESDD_UD_044, FLSTST_ESDD_UD_101, FLSTST_ESDD_UD_102    */
/* Implements:  FLSTST_ESDD_UD_004                                            */
/* Implements:  FlsTst063, FlsTst064, FlsTst065, FlsTst011, FlsTst099_Conf    */
/* Implements:  AR_PN0078_FSR_0040                                            */
/* Implements:  SWS_FlsTst_00063, SWS_FlsTst_00064, SWS_FlsTst_00065          */
/* Implements:  SWS_FlsTst_00011                                              */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_052    */
FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE)FlsTst_TestEcc(void)
{
  /* Declare the variable to store the return value */
  Std_ReturnType LenReturnValue;
  uint8 LucPatternNumber;
  uint8 LucExpectedError;
  volatile uint32 *LulEccTestAddress;
  uint32 LulEccSaveAddress;
  uint32 LulCompareData;
  uint32 LulDataWord;
  uint8 LucLoopCount;
  uint8 LucEccDelayCount;

  /* Set the default  return values */
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:3892)-7 */
  LulEccSaveAddress = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */

  /* Check if the module is initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                           FLSTST_TEST_ECC_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  {
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* QAC Warning: START Msg(2:2743)-6 */
    /* QAC Warning: START Msg(2:3892)-7 */
    /* Enable Ecc error detection and SEC */
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_CFECCCTL_VCIL,
                                FLSTST_ECC_SEC_ACTIVATE,
                                FlsTst_RamMirror[FLSTST_CFECCCTL_VCI_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CFECCCTL_VCIL,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_CFECCCTL_MASK_16BIT,
                                      FLSTST_TEST_ECC_SID);
    /* Disable ECC notification */
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_CFERRINT_VCILL,
                                FLSTST_ECC_DISABLE_NOTIFICATION,
                                FlsTst_RamMirror[FLSTST_CFERRINT_VCI_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CFERRINT_VCILL,
                                      FLSTST_ECC_DISABLE_NOTIFICATION,
                                      FLSTST_RAM_CFERRINT_MASK_8BIT,
                                      FLSTST_TEST_ECC_SID);
    /* Clear Ecc status register*/
    FLSTST_WRITE_REG_ONLY(FLSTST_CFSTCLR_VCILL, FLSTST_ONE);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CF1STERSTR_VCILL,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_CF1STERSTR_MASK_8BIT,
                                      FLSTST_TEST_ECC_SID);
    /* END Msg(4:0303)-1 */
    /* END Msg(2:2743)-6 */
    /* END Msg(2:3892)-7 */
    LucPatternNumber = FLSTST_ONE;
    /* QAC Warning: START Msg(2:3892)-7 */
    LulCompareData = FLSTST_ZERO;
    /* END Msg(2:3892)-7 */

    /* MISRA Violation: START Msg(4:0303)-1 */
    LulEccTestAddress = (volatile uint32*)FLSTST_ECC_SELF_TEST_ADDRESS;
    /* END Msg(4:0303)-1 */
    do
    {
      for (LucLoopCount = FLSTST_ZERO; LucLoopCount < FLSTST_FOUR;
                                                               LucLoopCount++)
      {
        /* Small delay for ECC error and address status update */
        for (LucEccDelayCount = FLSTST_ZERO;
                 LucEccDelayCount < FLSTST_ECC_TEST_DELAY; LucEccDelayCount++)
        {
          /* No operation */
          ASM_NOP();
        }

        /* read the data from ECC self test area */
        /* QAC Warning: START Msg(2:2814)-9 */
        LulDataWord = *(LulEccTestAddress);
        /* END Msg(2:2814)-9 */
        if (LulDataWord == (uint32)LulCompareData)
        {
          #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
          if ((FLSTST_ZERO == LucLoopCount) &&
                                    (LucPatternNumber < FLSTST_WALK1_END))
          {
            LucExpectedError = FLSTST_ONE;
            LulEccSaveAddress = (uint32)LulEccTestAddress;
          }
          else
          {
            /* Set the expected error value */
            LucExpectedError = FLSTST_ZERO;
            LulEccSaveAddress = FLSTST_ZERO;
          }
          #else
          if (LucPatternNumber < FLSTST_WALK1_END)
          {
            LucExpectedError = FLSTST_ONE;
            if (FLSTST_ZERO == LucLoopCount)
            {
              /* MISRA Violation: START Msg(4:0303)-1 */
              LulEccSaveAddress = (uint32)LulEccTestAddress;
              /* END Msg(4:0303)-1 */
            }
            else
            {
              /* No action required */
            }
          }
          else if(LucPatternNumber == FLSTST_ECC_END_PATTERN)
          {
            LucExpectedError = FLSTST_TWO;
            if (FLSTST_ZERO == LucLoopCount)
            {
              /* MISRA Violation: START Msg(4:0303)-1 */
              LulEccSaveAddress = (uint32)LulEccTestAddress;
              /* END Msg(4:0303)-1 */
            }
            else if (FLSTST_TWO == LucLoopCount)
            {
              LulCompareData = FLSTST_2BIT_ERROR_VALUE;
            }
            else
            {
              /* No action required */
            }
          }
          else
          {
            /* Set the expected error value and the address value */
            LucExpectedError = FLSTST_ZERO;
            /* QAC Warning: START Msg(2:3892)-7 */
            LulEccSaveAddress = FLSTST_ZERO;
            /* END Msg(2:3892)-7 */
          }
          #endif
          /* Check ECC error flags */
          /* MISRA Violation: START Msg(4:0303)-1 */
          if ((FLSTST_CF1STERSTR_VCILL != LucExpectedError) ||
                                 (FLSTST_CF1STEADR0_VCI != LulEccSaveAddress))
          {
            /* update Test status flag as failed  */
            LenReturnValue = E_NOT_OK;
            /* Get Ecc error status */
            FlsTst_GddEccErrorDetail.ucEccStatus =
                                              (uint8) FLSTST_CF1STERSTR_VCILL;
            /* Get the ECC error address */
            FlsTst_GddEccErrorDetail.ulEccFaultAddress = FLSTST_CF1STEADR0_VCI;
            /* END Msg(4:0303)-1 */
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* update Test status flag as failed  */
          LenReturnValue = E_NOT_OK;
          /* Get Ecc error status */
          /* QAC Warning: START Msg(2:2743)-6 */
          /* QAC Warning: START Msg(2:3892)-7 */
          /* MISRA Violation: START Msg(4:0303)-1 */
          FlsTst_GddEccErrorDetail.ucEccStatus =
                                              (uint8) FLSTST_CF1STERSTR_VCILL;
          /* Get the ECC error address */
          FlsTst_GddEccErrorDetail.ulEccFaultAddress = FLSTST_CF1STEADR0_VCI;
        }
        /* Clear the ECC error */
        FLSTST_WRITE_REG_ONLY(FLSTST_CFSTCLR_VCILL, FLSTST_ONE);
        FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CF1STERSTR_VCILL,
                                          FLSTST_ZERO,
                                          FLSTST_RAM_CF1STERSTR_MASK_8BIT,
                                          FLSTST_TEST_ECC_SID);
        /* END Msg(2:2743)-6 */
        /* END Msg(2:3892)-7 */
        /* END Msg(4:0303)-1 */
        /* Increase the read address */
        /* MISRA Violation: START Msg(4:0489)-2 */
        LulEccTestAddress++;
        /* END Msg(4:0489)-2 */
      }
      /* Increase the pattern number */
      LucPatternNumber++;
      /* Check Pattern number reached end of walk1 test */
      if (FLSTST_WALK1_END == LucPatternNumber)
      {
        /* Set compare value as 0xFFFFFFFF */
        LulCompareData = FLSTST_ALL1_VALUE;
      }
      else if (FLSTST_ALL1_END == LucPatternNumber)
      {
        /* Set compare value as 0x00000000 */
        LulCompareData = FLSTST_LONG_WORD_ZERO;
      }
      else
      {
        /* No action required */
      }

    } while (LucPatternNumber <= FLSTST_ECC_END_PATTERN);
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* QAC Warning: START Msg(2:2743)-6 */
    /* QAC Warning: START Msg(2:3892)-7 */

    /* Enable Ecc error detection and SEC */
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_CFECCCTL_VCIL,
                                FLSTST_ECC_SEC_ACTIVATE,
                                FlsTst_RamMirror[FLSTST_CFECCCTL_VCI_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CFECCCTL_VCIL,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_CFECCCTL_MASK_16BIT,
                                      FLSTST_TEST_ECC_SID);
    /* Enable ECC notification */
    FLSTST_WRITE_REG_AND_MIRROR(FLSTST_CFERRINT_VCILL,
                                FLSTST_ECC_ENABLE_NOTIFICATION,
                                FlsTst_RamMirror[FLSTST_CFERRINT_VCI_IDX]);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CFERRINT_VCILL,
                                      FLSTST_ECC_ENABLE_NOTIFICATION,
                                      FLSTST_RAM_CFERRINT_MASK_8BIT,
                                      FLSTST_TEST_ECC_SID);
    /* Clear Ecc status register*/
    FLSTST_WRITE_REG_ONLY(FLSTST_CFSTCLR_VCILL, FLSTST_ONE);
    FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_CF1STERSTR_VCILL,
                                      FLSTST_ZERO,
                                      FLSTST_RAM_CF1STERSTR_MASK_8BIT,
                                      FLSTST_TEST_ECC_SID);
    /* END Msg(4:0303)-1 */
    /* END Msg(2:2743)-6 */
    /* END Msg(2:3892)-7 */
    #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
    FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
    #endif
  }
  else
  {
    /* No action required */
  }
  /* return the test result */
  return(LenReturnValue);
} /* End of API FlsTst_TestEcc */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* #if (FLSTST_TEST_ECC_API == STD_ON) */
/*******************************************************************************
** Function Name         : FlsTst_MainFunction
**
** Service ID            : 0x0d
**
** Description           : This API performs testing of the defined flash
**                         blocks in background mode and shall set the Flash
**                         Test execution state from INIT to RUNNING when
**                         calling the function the first time after
**                         initialization or after a complete test interval
**
** Sync/Async            : NA
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_GulLastBgndSignature,
**                         FlsTst_GenOverallBgndResult, FlsTst_GenExeState,
**                         FlsTst_GpConfigPtr, FlsTst_GulTestIntervalId,
**                         FlsTst_GpBgndBlkConfig,
**                         FlsTst_GVar.FlsTst_GenBgndCheckState,
**                         FlsTst_GVar.FlsTst_GusBgndConfigIndex
**
** Function(s) invoked   : Det_ReportError,
**                         FLSTST_ENTER_CRITICAL_SECTION,
**                         FLSTST_EXIT_CRITICAL_SECTION
**
** Registers Used        : DCRAnCIN, DCRAnCOUT, DCRAnCTL
*******************************************************************************/

/* QAC Warning: START Msg(6:0857)-13 */
#define FLSTST_START_SEC_PUBLIC_CODE
/* END Msg(6:0857)-13 */
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, FlsTst066] */
/* TRACE [R4, FlsTst071] */
/* TRACE [R4, FlsTst117] */
/* implementation of FlsTst_MainFunction API */
/* Implements:  FLSTST_ESDD_UD_045, FLSTST_ESDD_UD_004, FLSTST_ESDD_UD_053    */
/* Implements:  FlsTst066, FlsTst067, FlsTst068, FlsTst069, FlsTst161         */
/* Implements:  FlsTst070, FlsTst071, FlsTst072, FlsTst117, FlsTst121         */
/* Implements:  FlsTst139, FlsTst011, FlsTst156, FlsTst007, FlsTst122_Conf    */
/* Implements:  SWS_FlsTst_00066, SWS_FlsTst_00067, SWS_FlsTst_00068          */
/* Implements:  SWS_FlsTst_00069, SWS_FlsTst_00161, SWS_FlsTst_00070          */
/* Implements:  SWS_FlsTst_00071, SWS_FlsTst_00072, SWS_FlsTst_00117          */
/* Implements:  SWS_FlsTst_00121, SWS_FlsTst_00139, SWS_FlsTst_00011          */
/* Implements:  SWS_FlsTst_00156, SWS_FlsTst_00007, FlsTst124_Conf            */
/* Implements:  EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0013 */
/* Implements:  AR_PN0078_FSR_0037                                            */
/* Implements:  FlsTst137, FlsTst138, SWS_FlsTst_00137, SWS_FlsTst_00138      */
/* Implements:  FlsTst006, FlsTst008, FlsTst009                               */
/* Implements:  FlsTst014, FlsTst012, FlsTst023, FlsTst025, FlsTst033         */
/* Implements:  FlsTst039, FlsTst133, FlsTst073                               */
/* Implements:  FlsTst083_Conf, FlsTst171_Conf, FlsTst170_Conf                */
/* Implements:  SWS_FlsTst_00025, SWS_FlsTst_00167                            */
/* Implements:  SWS_FlsTst_00033, SWS_FlsTst_00039, SWS_FlsTst_00168          */
/* Implements:  SWS_FlsTst_00073, SWS_FlsTst_00140                            */
/* Implements:  ECUC_FlsTst_00083, ECUC_FlsTst_00171                          */
/* Implements:  FlsTst004, FlsTst016, FlsTst013, FlsTst010, FlsTst140         */
/* Implements:  FlsTst120_Conf, FlsTst084_Conf, FlsTst158_Conf                */
/* Implements:  EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0009                    */
/* Implements:  SWS_FlsTst_00016                                              */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_059, FLSTST_ESDD_UD_101    */
/* Implements:  FLSTST_ESDD_UD_051, FLSTST_ESDD_UD_052                        */
FUNC(void, FLSTST_PUBLIC_CODE)FlsTst_MainFunction(void)
{
  /* Local pointer variable to hold the individual test block params */
  P2CONST(FlsTstBlock_ConfigType, FLSTST_VAR, FLSTST_CONFIG_CONST)
          LpFlsTstBlock;
  /* Variable to hold  number of atomic cell count */
  uint32 LulAtomicCellCount;
  /* Variable to hold  number of byte to process in one call  */
  uint32 LulByteToProcess;
  /* Variable to hold stored bgnd crc */
  uint32 LulStoredBgndCrc ;
  /* Variable to hold bgnd signature address */
  uint32 LulBgndSignatureAddress;
  /* Variable to hold  loop count */
  uint32 LulLoopCount;
  /* Variable to hold  data from flash  */
  uint8 Lucdata;
  /* Variable to hold the execution state change */
  uint8 LucSuspendAbortCheck;
  /* MISRA Violation: START Msg(4:0759)-3 */
  /* Local union variable to access crc value */
  FlsTst_CrcConvert LddCrcConvert;
  /* END Msg(4:0759)-3 */

  /* Initialize to zero */
  /* QAC Warning: START Msg(2:3892)-7 */
  LddCrcConvert.ulCrc32Data = FLSTST_ZERO;
  /* END Msg(2:3892)-7 */

  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, FlsTst011] */
    /* TRACE [R4, FlsTst014] */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                           FLSTST_MAIN_FUNCTION_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* QAC Warning: START Msg(2:3416)-5 */
    if (FLSTST_INIT == FlsTst_GenExeState)
    /* END Msg(2:3416)-5 */
    {
      /* TRACE [R4, FlsTst068] */
      FlsTst_GenExeState = FLSTST_RUNNING;
    }
    else
    {
      /* No action required */
    }
    /* QAC Warning: START Msg(2:3416)-5 */
    /* QAC Warning: START Msg(2:2814)-9 */
    /* QAC Warning: START Msg(2:3892)-7 */
    if ((FLSTST_RUNNING == FlsTst_GenExeState) &&
        (FlsTst_GpConfigPtr->ulFlsTstMaxBgndBlkNo > FLSTST_ZERO))
    /* END Msg(2:3416)-5 */
    /* END Msg(2:2814)-9 */
    /* END Msg(2:3892)-7 */
    {
        /* Load the test block parameters based on the index */
        /* MISRA Violation: START Msg(4:0491)-4 */
        /* QAC Warning: START Msg(2:2824)-8 */
        LpFlsTstBlock =
        &FlsTst_GpBgndBlkConfig[FlsTst_GVar.FlsTst_GusBgndConfigIndex];
        /* END Msg(4:0491)-4 */
        /* END Msg(2:2824)-8 */
        /* TRACE [R4, FlsTst121] */
        /* TRACE [R4, FlsTst156] */
        if (FLSTST_TRUE == FlsTst_GblTestComplete)
        {
          /* Background test blocks are tested completely */
          if (FlsTst_GulTestIntervalId >= FLSTST_TEST_INTERVAL_ID_END_VALUE)
          {
            /* QAC Warning: START Msg(2:3892)-7 */
            FlsTst_GulTestIntervalId = FLSTST_ZERO;
            /* END Msg(2:3892)-7 */
          }
          else
          {
            /* MISRA Violation: START Msg(4:2984)-7 */
            FlsTst_GulTestIntervalId++;
            /* END Msg(4:2984)-7 */
          }
          FlsTst_GblTestComplete = FLSTST_FALSE;
        }
        else
        {
          /* No action required */
        }
        if (FLSTST_BGND_CHECK_INIT == FlsTst_GVar.FlsTst_GenBgndCheckState)
        {

          #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
          FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
          #endif

          /* Initialize the CRC value for new test */
          /* QAC Warning: START Msg(2:2814)-9 */
          if (FLSTST_16BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
          /* END Msg(2:2814)-9 */
          {
            /* MISRA Violation: START Msg(4:0303)-1 */
            /* QAC Warning: START Msg(2:2743)-6 */
            /* QAC Warning: START Msg(2:3892)-7 */
            FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC16CNTL,
                                      FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
            FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                              FLSTST_CRC16CNTL,
                                              FLSTST_RAM_DCRACTL_MASK_8BIT,
                                              FLSTST_MAIN_FUNCTION_SID);
            FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_CRC16_INITIAL_VALUE;
            FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                        FLSTST_CRC16_INITIAL_VALUE);

          }
          else if (FLSTST_32BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
          {
            FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC32CNTL,
                                      FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
            FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                              FLSTST_CRC32CNTL,
                                              FLSTST_RAM_DCRACTL_MASK_8BIT,
                                              FLSTST_MAIN_FUNCTION_SID);
            /* Load the initial value */
            if (FLSTST_TRUE == LpFlsTstBlock->ucFlsTstAddressDepdntCrc)
            {
              FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                               (uint32)LpFlsTstBlock->ulFlsTstBlockBaseAddress);

              FlsTst_GVar.FlsTst_GulCalculatedCrc =
                              (uint32)LpFlsTstBlock->ulFlsTstBlockBaseAddress;
            }
            else
            {
              FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                FLSTST_CRC32_INITIAL_VALUE);

              /* END Msg(4:0303)-1 */
              /* END Msg(2:2743)-6 */
              /* END Msg(2:3892)-7 */
              FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_CRC32_INITIAL_VALUE;
            }
          }
          #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
          else if (FLSTST_8BIT_CRC_2F == LpFlsTstBlock->enFlsTstTestAlgorithm)
          {
            FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_CRC8_INITIAL_VALUE;
            FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                     FLSTST_CRC8_INITIAL_VALUE);

            FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                        FLSTST_CRC8CNTL_2F,
                                      FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
            FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                              FLSTST_CRC8CNTL_2F,
                                              FLSTST_RAM_DCRACTL_MASK_8BIT,
                                              FLSTST_MAIN_FUNCTION_SID);
          }
          else if (FLSTST_8BIT_CRC_SAEJ1850 ==
                  LpFlsTstBlock->enFlsTstTestAlgorithm)
          {
            FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_CRC8_INITIAL_VALUE;
            FLSTST_WRITE_REG_ONLY(FLSTST_DCRACOUTBGND,
                                     FLSTST_CRC8_INITIAL_VALUE);

            FLSTST_WRITE_REG_AND_MIRROR(FLSTST_DCRACTLBGND,
                                      FLSTST_CRC8CNTL_SAEJ1850,
                                      FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX]);
            FLSTST_CHECK_WRITE_VERIFY_RUNTIME(FLSTST_DCRACTLBGND,
                                              FLSTST_CRC8CNTL_SAEJ1850,
                                              FLSTST_RAM_DCRACTL_MASK_8BIT,
                                              FLSTST_MAIN_FUNCTION_SID);
          }
          #endif
          else
          {
            /* No action required */
          }

          FlsTst_GVar.FlsTst_GenBgndCheckState = FLSTST_BGND_CHECK_INPROGRESS;
          #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
          FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
          #endif
        }
        else
        {
          /* No action required */
        }
        /* TRACE [R4, FlsTst139] */
        if (FLSTST_BGND_CHECK_INPROGRESS ==
                                           FlsTst_GVar.FlsTst_GenBgndCheckState)
        {
          /* TRACE [R4, FlsTst067] */
          /* Check block size is greater than no of cell to be tested in
           * one scheduled task (FlsTst_MainFunction() call), if yes load
           * maximum value configured for one scheduled task.
           */
          if (((LpFlsTstBlock->ulFlsTstBlockBaseAddress +
                LpFlsTstBlock->ulFlsTstBlockSize) -
                FlsTst_GVar.FlsTst_GulReadAddress)
                                  > LpFlsTstBlock->ulFlsTstNumberOfTestedCells)
          {
            LulByteToProcess = LpFlsTstBlock->ulFlsTstNumberOfTestedCells;
          }
          else
          {
            LulByteToProcess = ((LpFlsTstBlock->ulFlsTstBlockBaseAddress +
                                 LpFlsTstBlock->ulFlsTstBlockSize) -
                                 FlsTst_GVar.FlsTst_GulReadAddress);
          }

          /* Initialize atomic cell count to zero */
          /* QAC Warning: START Msg(2:3892)-7 */
          LulAtomicCellCount = FLSTST_ZERO;
          LucSuspendAbortCheck = FLSTST_ZERO;
          for (LulLoopCount = FLSTST_ZERO; ((LulLoopCount < LulByteToProcess) &&
                        (FLSTST_ZERO == LucSuspendAbortCheck)); LulLoopCount++)
          /* END Msg(2:3892)-7 */
          {
            /* MISRA Violation: START Msg(4:0303)-1 */
            /* QAC Warning: START Msg(2:2814)-9 */
            /* Read the data from memory  */
            Lucdata =
                 (*((volatile uint8 *)(FlsTst_GVar.FlsTst_GulReadAddress)));
            /* END Msg(4:0303)-1 */
            /* END Msg(2:2814)-9 */

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* QAC Warning: START Msg(2:2743)-6 */
            /* Load the data in crc input reg */
            FLSTST_WRITE_REG_ONLY(FLSTST_DCRACINBGND,
                                       (uint32)Lucdata);
            /* END Msg(4:0303)-1 */
            /* END Msg(2:2743)-6 */

            /* Increment the address */
            FlsTst_GVar.FlsTst_GulReadAddress++;
            /* Increment atomic cell count */
            LulAtomicCellCount++;
            if (LulAtomicCellCount > FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC)
            {
              /* Re-initialize to zero */
              /* QAC Warning: START Msg(2:3892)-7 */
              LulAtomicCellCount = FLSTST_ZERO;
              /* END Msg(2:3892)-7 */
              /* QAC Warning: START Msg(2:3416)-5 */
              if (FLSTST_SUSPENDED == FlsTst_GenExeState)
              {
                LucSuspendAbortCheck = FLSTST_ONE;
              }
              else if (FLSTST_ABORTED == FlsTst_GenExeState)
              {
                /* TRACE [R4, FlsTst032] */
                LucSuspendAbortCheck = FLSTST_ONE;
              }
              /* END Msg(2:3416)-5 */
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

          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Save the crc value */
          FlsTst_GVar.FlsTst_GulCalculatedCrc = FLSTST_DCRACOUTBGND;
          /* END Msg(4:0303)-1 */

          if (FlsTst_GVar.FlsTst_GulReadAddress >=
                           (LpFlsTstBlock->ulFlsTstBlockBaseAddress +
                              LpFlsTstBlock->ulFlsTstBlockSize))
          {
            #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
            FLSTST_ENTER_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
            #endif
            /* QAC Warning: START Msg(2:3892)-7 */
            LulStoredBgndCrc = FLSTST_ZERO;
            LulByteToProcess = FLSTST_ZERO;
            LulBgndSignatureAddress = LpFlsTstBlock->ulFlsTstSignatureAddress;

            if (FLSTST_16BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
            {
              LulByteToProcess = FLSTST_TWO;
            }
            else if (FLSTST_32BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
            {
              LulByteToProcess = FLSTST_FOUR;
            }
            #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
            else if ((FLSTST_8BIT_CRC_2F ==
                  LpFlsTstBlock->enFlsTstTestAlgorithm) ||
                (FLSTST_8BIT_CRC_SAEJ1850 ==
                  LpFlsTstBlock->enFlsTstTestAlgorithm))
            {
              LulByteToProcess = FLSTST_ONE;
            }
            #endif
            else
            {
              /* No action required */
            }

            for (LulLoopCount = FLSTST_ZERO; LulLoopCount < LulByteToProcess;
                                        LulLoopCount++)
            {
              /* MISRA Violation: START Msg(4:0303)-1 */
              /* QAC Warning: START Msg(2:2814)-9 */
              /* Read stored crc data from memory and store in array */
              LddCrcConvert.ucCrcData4[(uint8)LulLoopCount]
                       = ( *((volatile uint8 *)(LulBgndSignatureAddress)));
              /* END Msg(4:0303)-1 */
              /* END Msg(2:3892)-7 */
              /* END Msg(2:2814)-9 */

              LulBgndSignatureAddress++;
            }

            if (FLSTST_16BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
            {
              LulStoredBgndCrc = LddCrcConvert.usCrc16Data;
            }
            else if (FLSTST_32BIT_CRC == LpFlsTstBlock->enFlsTstTestAlgorithm)
            {
              LulStoredBgndCrc = LddCrcConvert.ulCrc32Data;
            }
            #if (FLSTST_DEVICE_SPECIFIC == STD_ON)
            else if ((FLSTST_8BIT_CRC_2F ==
                      LpFlsTstBlock->enFlsTstTestAlgorithm) ||
            (FLSTST_8BIT_CRC_SAEJ1850 == LpFlsTstBlock->enFlsTstTestAlgorithm))
            {
              LulStoredBgndCrc = LddCrcConvert.ucCrc8Data;
            }
            #endif
            else
            {
              /* No action required */
            }

            /* Check the whether calculated crc matching with stored crc */
            if (LulStoredBgndCrc == FlsTst_GVar.FlsTst_GulCalculatedCrc)
            {
              FlsTst_GulLastBgndSignature = FlsTst_GVar.FlsTst_GulCalculatedCrc;

            }
            else
            {
              /* Report error  and change overall bgnd result
               * status to not ok
               */
              FlsTst_GenOverallBgndResult = FLSTST_RESULT_NOT_OK;
              /* TRACE [R4, FlsTst013] */
              Dem_ReportErrorStatus
                       (FLSTST_E_FLSTST_FAILURE, DEM_EVENT_STATUS_FAILED);
            }
            /* Increment the test block index */
            /* QAC Warning: START Msg(2:3892)-7 */
            FlsTst_GVar.FlsTst_GusBgndConfigIndex++;
            if (FlsTst_GVar.FlsTst_GusBgndConfigIndex >
                       (FlsTst_GpConfigPtr->ulFlsTstMaxBgndBlkNo - FLSTST_ONE))
            /* END Msg(2:3892)-7 */
            {
              if (FLSTST_RESULT_NOT_OK != FlsTst_GenOverallBgndResult)
              {
                /* TRACE [R4, FlsTst161] */
                FlsTst_GenOverallBgndResult = FLSTST_RESULT_OK;
              }
              else
              {
                /* No action required */
              }

              /* QAC Warning: START Msg(2:3892)-7 */
              FlsTst_GVar.FlsTst_GusBgndConfigIndex = FLSTST_ZERO;
              /* END Msg(2:3892)-7 */
              FlsTst_GenExeState = FLSTST_INIT;
              /* On completion of the one test cycle call-back
               * notification will be invoked
               */
              FlsTst_GblTestComplete = FLSTST_TRUE;
              #if (FLSTST_TEST_COMPLETED_NOTIFICATION_SUPPORTED == STD_ON)
              /* TRACE [R4, FlsTst076] */
              if (NULL_PTR != FlsTst_GpConfigPtr->pTestCompleteNotifyFunc)
              {
                /* TRACE [R4, FlsTst077] */
                /* TRACE [R4, FlsTst078] */
                FlsTst_GpConfigPtr->pTestCompleteNotifyFunc();
              }
              else
              {
                /* No action required */
              }
              #endif/*(FLSTST_TEST_COMPLETED_NOTIFICATION_SUPPORTED == STD_ON)*/
            }
            else
            {
              /* No action required */
            }
            /* Load the test block parameters based on the index */
            /* MISRA Violation: START Msg(4:0491)-4 */
            LpFlsTstBlock =
            &FlsTst_GpBgndBlkConfig[FlsTst_GVar.FlsTst_GusBgndConfigIndex];
            /* END Msg(4:0491)-4 */
            FlsTst_GVar.FlsTst_GulReadAddress =
                                       LpFlsTstBlock->ulFlsTstBlockBaseAddress;
            FlsTst_GVar.FlsTst_GenBgndCheckState = FLSTST_BGND_CHECK_INIT;
            #if (FLSTST_CRITICAL_SECTION_PROTECTION == STD_ON)
            FLSTST_EXIT_CRITICAL_SECTION(FLSTST_DRIVERSTATE_DATA_PROTECTION);
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

    }
    else
    {
      /* No action required */
    }
  }
} /* End of API FlsTst_MainFunction */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : ReadLoadMemData
**
** Service ID            : NA
**
** Description           : Internal function to read the CRC value from the
**                         flash memory.
**
** Sync/Async            : NA
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LpReadAddress, size
**
** InOut Parameters      : None
**
** Output Parameters     : DcraAddr
**
** Return parameter      : None
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : None
**
** Function(s) invoked   : None
**
** Registers Used        : None
*******************************************************************************/
/* Implements:  FLSTST_ESDD_UD_064, FlsTst086_Conf                            */
#if (FLSTST_START_FGND_API == STD_ON)
#define FLSTST_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:3227)-4 */
static FUNC(void, FLSTST_PRIVATE_CODE) ReadLoadMemData (volatile const uint8*
                        LpReadAddress, volatile uint32* DcraAddr, uint32 size)
/* END Msg(2:3227)-4 */
{
  uint8 LucMemData;
  volatile const uint8* lpReadAddr;
  lpReadAddr = LpReadAddress;
  /* QAC Warning: START Msg(2:3892)-7 */
  while (size > FLSTST_ZERO)
  /* END Msg(2:3892)-7 */
  {
    /* QAC Warning: START Msg(2:2743)-6 */
    /* QAC Warning: START Msg(2:2814)-9 */
    LucMemData = *lpReadAddr;
    /* Read data from memory and loading to configured DCRA unit */
    FLSTST_WRITE_REG_ONLY(*DcraAddr,
                                LucMemData);
    /* MISRA Violation: START Msg(4:0489)-2 */
    /* END Msg(2:2814)-9 */
    /* END Msg(2:2743)-6 */
    lpReadAddr++;
    /* END Msg(4:0489)-2 */
    size--;
  }
}
#define FLSTST_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif

/*******************************************************************************
** Function Name         : FlsTst_CheckHWConsistency
**
** Service ID            : 0x10
**
** Description           : This API will execute registers ram mirroring check
**
** Sync/Async            : synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType - Returns E_OK if the registers values
**                         corresponds with their ram copy else returns E_NOT_OK
**                         if there is at least one dofference.
**
** Preconditions         : Component must be initialized using FlsTst_Init().
**
** Global Variables Used : FlsTst_RamMirror
**
** Function(s) invoked   : Det_ReportError
**
** Registers Used        : DCRAnCTL, CFECCCTL_VCIL, CFERRINT_VCILL
*******************************************************************************/
#if (FLSTST_RAM_MIRROR == FLSTST_ENABLE)

#define FLSTST_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* TRACE [R4, EAAR_PN0034_FSR_0006 ] */
/* Implementation of FlsTst_CheckHWConsistency API */
/* Implements:  FLSTST_ESDD_UD_049, FLSTST_ESDD_UD_058                        */
/* Implements:  EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0004                    */
/* Implements:  EAAR_PN0034_FSR_0006, EAAR_PN0034_FSR_0007                    */
/* Implements:  FlsTst014                                                     */
/* Implements:  FLSTST_ESDD_UD_003, FLSTST_ESDD_UD_052                        */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, FLSTST_PUBLIC_CODE) FlsTst_CheckHWConsistency
                                (FlsTst_HWConsistencyModeType HWConsistencyMode)
/* END Msg(2:3227)-4 */
{
  /* Local variable to hold the return value of the function */
  Std_ReturnType LenReturnValue = E_NOT_OK;

  /* Check if the FLSTST Module is not Initialized */
  /* QAC Warning: START Msg(2:3416)-5 */
  if (FLSTST_UNINIT == FlsTst_GenExeState)
  /* END Msg(2:3416)-5 */
  {
    #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,
                          FLSTST_CHECK_HW_CONSISTENCY_SID, FLSTST_E_UNINIT);
    #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    if ((FLSTST_DYNAMIC == HWConsistencyMode)
      || (FLSTST_STATIC == HWConsistencyMode))
    {
      if (FLSTST_DYNAMIC == HWConsistencyMode)
      {
      /* Output registers cannot be mirrored - they are changed while testing */
        /* MISRA Violation: START Msg(4:0303)-1 */
        /* QAC Warning: START Msg(2:3892)-7 */
        if ((FLSTST_DCRACTLBGND == FlsTst_RamMirror[FLSTST_DCRACTLBGND_IDX])
          && (FLSTST_DCRACTLFGND == FlsTst_RamMirror[FLSTST_DCRACTLFGND_IDX])
          #if (FLSTST_TEST_ECC_API == STD_ON)
          && (FLSTST_CFECCCTL_VCIL ==
           (FlsTst_RamMirror[FLSTST_CFECCCTL_VCI_IDX]
           & FLSTST_RAM_CFECCCTL_MASK_16BIT))
         && (FLSTST_CFERRINT_VCILL == FlsTst_RamMirror[FLSTST_CFERRINT_VCI_IDX])
          #endif
          )
          /* END Msg(4:0303)-1 */
          /* END Msg(2:3892)-7 */

        {
          LenReturnValue = E_OK;
        }
        else
        {
          /* Nothing to be done, avoid MISRA */
        }
      }
      else
      {
          LenReturnValue = E_OK;
      }
    }
    else
    {
      #if (FLSTST_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      (void)Det_ReportError(FLSTST_MODULE_ID,
             FLSTST_INSTANCE_ID, FLSTST_INIT_SID, FLSTST_E_PARAM_INVALID);
      #endif /* #if (FLSTST_DEV_ERROR_DETECT == STD_ON) */
      LenReturnValue = E_NOT_OK;
    }
  }
  return(LenReturnValue);
} /* End of API FlsTst_CheckHWConsistency  */

#define FLSTST_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0862)-2 */
#include FLSTST_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif /* (FLSTST_RAM_MIRROR == FLSTST_ENABLE) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
/* END Msg(2:0862)-2 */
