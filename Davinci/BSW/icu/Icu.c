/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Icu Driver Component.            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  16-Sep-2015 : Initial Version.
 * V1.0.1:  04-Nov-2015 : 1.As part of JIRA #ARDAAGA-78,following changes are
 *                         made,
 *                         a.Updated the parameter passed in EcuM_CheckWakeup
 *                           function in the API Icu_EnableNotification.
 *                         b.Added new API Icu_GetVersionInfo.
 * V1.0.2:  02-Jun-2016 : #ARDAABD-426
 *                        1. Wakeup source types updated to
 *                           Ecum_WakeupSourceType; Removed bit shifting from
 *                           wakeup sources (Autosar 4.0.3 Ecum4040)
 * V1.0.3:  13-Jun-2016 : #ARDAABD-413
 *                        1. Added a flag to signal that a channel measurements
 *                           is running, removed unused flags and code after
 *                           modification
 * V1.0.4:  29-Jun-2016 : #ARDAABD-529
 *                        1. Added precompile switches for
 *                          ICU_E_ALREADY_DISABLED and ICU_E_ALREADY_ENABLED
 * V1.0.5:  29-Jun-2016 : #ARDAABD-413
 *                        1. Removed precompile switch ICU_EDGE_COUNT_API from
 *                           Icu_SetMode(). uiChannelMeasurementRunning is used
 *                           regardless of the Edge Count enable/disable setting
 * V1.0.6:  04-Jul-2016 : #ARDAABD-395
 *                        1. Added ICU_TAUB_UNIT_CONFIG for TAUB prescaler
 *                           configuration
 * V1.0.7:  10-Aug-2016 : #ARDAABD-583
 *                        1. Increased ICU_C_SW_MINOR_VERSION to 1
 * V1.0.8:  16-Aug-2016 : #ARDAABD-583
 *                        1. In the function Icu_EnableEdgeDetection(...), moved
 *                           LpRamData->uiChannelMeasurementRunning = ICU_TRUE
 *                           after Icu_HW_StartCountMeasurement is called
 *                        2. In the function Icu_StopTimestamp(...) removed
 *                           LucIndex and modified line 2020 to check if
 *                           channel is running using
 *                           uiChannelMeasurementRunning
 * V1.0.9:  17-Aug-2016  : JIRA #ARDAABD-583
 *                         1. Icu_EnableEdgeDetection(...), modified IF...ELSE
 *                            chaining.
 *                         2. Removed critical section protection on flag set
 *                         3. Removed precompile switches around
 *                            Icu_HW_StartCountMeasurement(...) because they
 *                            are already included in the function
 * V1.1.0:  12-Sep-2016  : JIRA #ARDAABD-661
 *                         1. Icu_EnableNotification(...), removed ASR 3.2.2
 *                            implementation
 *                         2. Icu_DisableNotification(...), removed ASR 3.2.2
 *                            implementation
 *                         3. Updated copyright information
 * V1.1.1:  16-Sep-2016  : #ARDAABD-529
 *                         1. Icu_EnableNotification(), replaced macro
 *                            ICU_ALREADY_ENABLED_DET_CHECK with
 *                            ICU_ALREADY_ENABLED_DISABLED_DET_CHECK
 *                         2. Icu_DisableNotification(), replaced macro
 *                            ICU_ALREADY_DISABLED_DET_CHECK with
 *                            ICU_ALREADY_ENABLED_DISABLED_DET_CHECK
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  03-Oct-2016  : #ARDAABD-716
 *                         1. Removed condition sorrounding call to
 *                            Icu_HW_SetMode(), in Icu_SetMode()
 *                         2. Modifed DET reporting ICU_E_BUSY_OPERATION
 *                            DET is reported whenever the channel is running
 *                            and Icu_SetMode() is called
 * V2.0.2:  05-Oct-2016  : #ARDAABD-841
 *                         1. Removed DET codes ICU_E_PARAM_BUFFER_PTR and
 *                            ICU_E_PARAM_CONFIG as per ASR4.2.2
 *                         2. Added DET code ICU_E_PARAM_POINTER
 *                            for null pointer check as per ASR4.2.2
 *                         3. Added DET code ICU_E_INIT_FAILED
 *                            for init failed as per ASR4.2.2
 * V2.0.3:  24-Nov-2016  : #ARDAABD-617
 *                         1. Added ASR4.2.2 and ASR4.0.3 support
 * V2.0.4:  26-Nov-2016  : #ARDAABD-841
 *                         1. Remove ASR3.2.2 from Icu_EnableNotification and
 *                            Icu_DisableNotification
 *                         2. Removed ASR3.2.2 function Icu_HW_Clr_Pnd_Intr
 *                            from Icu_EnableNotification
 *                         3. Changed check NULL_PTR  == LpChannelConfig in
 *                            Icu_GetTAUInCountValue because this was an F1L
 *                            specific implementation. Instead check was
 *                            changed to External Interrupt channels.
 *                         4. Modified condition for reporting
 *                            ICU_E_BUSY_OPERATION in Icu_SetMode()
 * V2.0.5:  06-Dec-2016  : #ARDAABD-583
 *                         1. Removed parameter passing to Icu_HW_Init
 * V2.0.6:  12-Dec-2016  : #ARDAABD-583
 *                         1. Changed DET_ICU_E_PARAM_VALUE to ICU_E_PARAM_VALUE
 * V2.0.7:  14-Dec-2016  : #ARDAABD-404
 *                         1. Minor corrections, updated used register list
 * V2.0.8:  20-Dec-2016  : #ARDAABD-583
 *                         1. Icu_GetTimestampIndex(), replaced channel
 *                            measurement running
 * V2.0.9:  16-Mar-2017  : #ARDAABD-1206
 *                         1. Added Tracability
 * V2.0.10: 11-Jul-2017  : 1. As part of Jira #ARDAABD-1705,
 *                            setting of uiNotificationEnable to TRUE has been
 *                            removed from Icu_EnableEdgeDetection API.
 *                         2. As part of Jira #ARDAABD-1921,
 *                            checking of uiChannelStatus has been replaced
 *                            with a flag uiResultComplete in Icu_GetTimeElapsed
 *                            and Icu_GetDutyCycleValues API's.
 *                         3. As part of Jira #ARDAABD-1611, use of MemMap.h
 *                            has been replaced with macro ICU_MEMMAP_FILE.
 * V2.0.11: 16-Oct-2017  : 1. As part of Jira #ARDAABD-2444,
 *                            naming convention for variables and macros
 *                            updated.
 *                         2. As part of Jira #ARDAABD-2425, QAC WARNING has
 *                            been added.
 *                         3. As part of Jira #ARDAABD-2571, constants are
 *                            placed on the left of equality comparisons and
 *                            for all condition checks, made constants on LHS
 *                            and variables on RHS. Removed space in between
 *                            unary operators
 * V2.0.12: 04-Jul-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. QAC warnings are added and violations are
 *                               justified.
 *                            b. Copyright information is updated.
 *                         2. Critical section protection is added while
 *                            writing to members of Icu_GpChannelRamData.
 *                            Ref: ARDAABD-3299
 *                         3. Status of ICU driver is set to ICU_UNINITIALIZED
 *                            at the beginning of Icu_DeInit API.
 *                            Ref: ARDAABD-3780
 *                         4. MISRA C rule violation tag for QAC message
 *                            Msg(2:2016) is removed since it is not violated in
 *                            code.
 *                         5. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 * V2.0.13: 27-Sep-2018  : Following changes are made:
 *                         1. As part of ARDAABD-3707,Following changes are made:
 *                            Add RH850_DUMMY_READ_SYNCP()to fix the fault
 *                            synchronization at the timing when control shifts
 *                            from MCAL to application.
 *                         2. Add traceability tags in the corresponding place 
 *                             for reqtify improvement
 * V2.0.14: 05-Oct-2018 : Following changes are done :
 *                         1. As part of ARDAABD-3707, ICP0 usage error
 *                            modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to
 *                            RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 * V2.0.15: 18-Oct-2018 : As part of ARDAABD-3707
 *                        Remove the RH850_DUMMY_READ_SYNCP Marco
 * V2.0.16: 13-Aug-2019 : Following changes are done :
 *                         1. As part of ARDAABD-977, add the support for new
 *                            parameter 'IcuBusyOperationDETCheck'
 *                            (ICU_BUSY_OPERATION_DET_CHECK).
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements:  EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0065, EAAR_PN0034_NR_0001*/
/* Implements:  ICU219, EAAR_PN0034_NR_0007, EAAR_PN0034_NR_0012 */
/* Included for module version information and other types declarations */
#include "Icu.h"
/* Included for Header file inclusion */
#include "Icu_LLDriver.h"
/* Included for RAM variable declarations */
#include "Icu_Ram.h"
/* Implements:  ICU026_Conf, ECUC_Icu_00026, ICU213, SWS_Icu_00213 */
/* Implements:  EAAR_PN0034_FR_0021 */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
/* Implements:  EAAR_PN0034_FR_0064*/
#include "Det.h"
#endif
/*Implements:   EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0021*/
#if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Icu.h"
#endif

/* Included for I/O Registers */
#include "Iocommon_Defines.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Implements:  ICU005 */
/* AUTOSAR release version information */
#define ICU_C_AR_RELEASE_MAJOR_VERSION  ICU_AR_RELEASE_MAJOR_VERSION_VALUE
#define ICU_C_AR_RELEASE_MINOR_VERSION  ICU_AR_RELEASE_MINOR_VERSION_VALUE
#define ICU_C_AR_RELEASE_REVISION_VERSION \
                                        ICU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ICU_C_SW_MAJOR_VERSION    1
#define ICU_C_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ICU_AR_RELEASE_MAJOR_VERSION != ICU_C_AR_RELEASE_MAJOR_VERSION)
  #error "Icu.c : Mismatch in Release Major Version"
#endif

#if (ICU_AR_RELEASE_MINOR_VERSION != ICU_C_AR_RELEASE_MINOR_VERSION)
  #error "Icu.c : Mismatch in Release Minor Version"
#endif

#if (ICU_AR_RELEASE_REVISION_VERSION != ICU_C_AR_RELEASE_REVISION_VERSION)
  #error "Icu.c : Mismatch in Release Revision Version"
#endif

#if (ICU_SW_MAJOR_VERSION != ICU_C_SW_MAJOR_VERSION)
  #error "Icu.c : Mismatch in Software Major Version"
#endif

#if (ICU_SW_MINOR_VERSION != ICU_C_SW_MINOR_VERSION)
  #error "Icu.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To access channel parameters in an optimized approach.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317) Implicit conversion from a pointer to void to a   */
/*                 pointer to object type.                                    */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-2 and                           */
/*                 END Msg(4:0317)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3138)Null statement is located close to other code      */
/*                 or comments                                                */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-3 and                           */
/*                 END Msg(4:3138)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2983)This assignment is redundant. The value of this    */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The object is used under different pre-compile sections.   */
/*                 However, for different configurations this warning ceases  */
/*                 to exist.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-4 and                           */
/*                 END Msg(4:2983)-4 tags in the code.                        */
/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (7:0505) Dereferencing pointer value that is apparently    */
/*                 NULL                                                       */
/* Rule          : MISRA-C:2004 Rule 1.2                                      */
/*                 REFERENCE - ISO-6.3.3.2 Semantics                          */
/* Justification : "Config" pointer is checked and verified when DET is       */
/*                 switched STD_ON.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(7:0505)-5 and                           */
/*                 END Msg(7:0505)-5 tags in the code.                        */
/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3356) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Since e-num type is used it is not possible to provide     */
/*                 out of range value but as per AUTOSAR all the input        */
/*                 parameters of an API have to be verified.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3356)-6 and                           */
/*                 END Msg(4:3356)-6 tags in the code.                        */
/******************************************************************************/
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3359) The value of this control expression is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Since e-num type is used it is not possible to provide     */
/*                 out of range value but as per AUTOSAR all the input        */
/*                 parameters of an API have to be verified.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3359)-7 and                           */
/*                 END Msg(4:3359)-7 tags in the code.                        */
/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3201) This statement is unreachable.                    */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : Since e-num type is used it is not possible to provide     */
/*                 out of range value but as per AUTOSAR all the input        */
/*                 parameters of an API have to be verified.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3201)-8 and                           */
/*                 END Msg(4:3201)-8 tags in the code.                        */
/******************************************************************************/
/* 9. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : MISRA-C:2004 Message 2824                                  */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-9 and                           */
/*                 END Msg(2:2824)-9  tags in the code.                       */
/******************************************************************************/
/* 10. QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include                    */
/*                 preprocessing directive.                                   */
/* Rule          : MISRA-C:2004 Message 0832                                  */
/* Justification : Required for inclusion of ASR version specific,MemMap file */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-10 and                          */
/*                 END Msg(2:0832)-10 tags in the code.                       */
/******************************************************************************/
/* 11. QAC Warning:                                                           */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : MISRA-C:2004 Message 3227                                  */
/* Justification : The function parameters of AUTOSAR  and vendor             */
/*                 specific Api's cannot be modified to be made as constant.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-11 and                          */
/*                 END Msg(2:3227)-11 tags in the code.                       */
/******************************************************************************/
/* 12. QAC Warning:                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : MISRA-C:2004 Message 2814                                  */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-12 and                          */
/*                 END Msg(2:2814)-12 tags in the code.                       */
/******************************************************************************/
/* 13. QAC Warning:                                                           */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                  to another type                                           */
/* Rule          : MISRA-C:2004 Message 3892                                  */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                  the post build configuration                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-13 and                          */
/*                 END (2:3892)-13 tags in the code.                          */
/******************************************************************************/
/* 14. QAC Warning:                                                           */
/* Message       : (2:4342) An expression of 'essentially unsigned' type      */
/*                 (unsigned char) is being cast to enum type                 */
/* Rule          : MISRA-C:2004 Message 4342                                  */
/* Justification : This implicit conversion is done to access the global data */
/*                 with different data type to enum type since the size of    */
/*                 variable should be declared  before using it.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:4342)-14 and                          */
/*                 END Msg(2:4342)-14 tags in the code.                       */
/******************************************************************************/
/* 15. QAC Warning:                                                           */
/* Message       : (2:2000) This 'switch' statement 'default' clause is empty.*/
/* Rule          : MISRA-C:2004 Message 2000                                  */
/* Justification : No else clause has been encountered in this if statement.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-15 and                          */
/*                 END Msg(2:2016)-15 tags in the code.                       */
/******************************************************************************/
/* 16. QAC Warning:                                                           */
/* Message       : (2:1476) Range of possible enum values suggests this test  */
/*                 is always false.                                           */
/* Rule          : MISRA-C:2004 Message 1476                                  */
/* Justification : Range of enum values cannot be modified.                   */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(2:1476)-16 and                          */
/*                 END Msg(2:1476)-16 tags in the code.                       */
/******************************************************************************/
/* 17. QAC Warning:                                                           */
/* Message       : (2:3206) Range of possible enum values suggests this test  */
/*                 is always false.                                           */
/* Rule          : MISRA-C:2004 Message 3206                                  */
/* Justification : Parameter is not modified, however const qualifier is not  */
/*                 required. This is defined as per ASR API standard.         */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(2:3206)-17 and                          */
/*                 END Msg(2:3206)-17 tags in the code.                       */
/******************************************************************************/
/* 18. QAC Warning:                                                           */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-18 and              */
/*                 END Msg(2:0862)-18 tags in the code.                       */
/******************************************************************************/
/* 19. QAC Warning:                                                           */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-19 and             */
/*                 END Msg(2:0890)-19 tags in the code.                       */
/******************************************************************************/
/* 20. MISRA C RULE VIOLATION::                                               */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-20 and                          */
/*                 END Msg(4:0303)-20 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Icu_Init
**
** Service ID            : 0x00
**
** Description           : This API performs the initialization of the Icu
**                         Driver Component.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
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
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GpTAUUnitConfig, Icu_GpPreviousInputConfig
**                         Icu_GpChannelRamData, Icu_GpSignalMeasurementData,
**                         Icu_GpTimeStampData, Icu_GpEdgeCountData,
**                         Icu_GblDriverStatus, Icu_GenModuleMode,
**                         Icu_GulWakeupSource, Icu_GpWakeUpFactorRamAddress.
**
** Functions invoked     : Det_ReportError, Icu_HW_Init.
**
** Registers Used        : None
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
/* QAC Warning: START Msg(2:0890)-18 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-18 */
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_088, ICU_ESDD_UD_199, ICU_ESDD_UD_006,            */
/* Implements:  ICU_ESDD_UD_007, ICU_ESDD_UD_008, ICU_ESDD_UD_011,            */
/* Implements:  ICU_ESDD_UD_012, ICU_ESDD_UD_014, ICU_ESDD_UD_015,            */
/* Implements:  ICU_ESDD_UD_046, ICU_ESDD_UD_047, ICU_ESDD_UD_015,            */
/* Implements:  ICU_ESDD_UD_130, ICU_ESDD_UD_010                              */
/* Implements:  ICU006, SWS_Icu_00006, ICU023, SWS_Icu_00023                  */
/* Implements:  ICU040, SWS_Icu_00040, ICU048                                 */
/* Implements:  ICU050, SWS_Icu_00050, ICU051, SWS_Icu_00051                  */
/* Implements:  ICU052, SWS_Icu_00052, ICU053, SWS_Icu_00053                  */
/* Implements:  ICU054, SWS_Icu_00054, ICU060, SWS_Icu_00060                  */
/* Implements:  ICU061, SWS_Icu_00061, ICU121, SWS_Icu_00121                  */
/* Implements:  ICU128, SWS_Icu_00128, ICU129, SWS_Icu_00129                  */
/* Implements:  ICU138, SWS_Icu_00138, ICU148, SWS_Icu_00148                  */
/* Implements:  ICU151, SWS_Icu_00151, ICU191, SWS_Icu_00191                  */
/* Implements:  ICU220, SWS_Icu_00220, ICU298, SWS_Icu_00298                  */
/* Implements:  ICU297, SWS_ICU_00297                                         */

/* Implements:  ICU_ESDD_UD_059,ICU_ESDD_UD_019                               */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_Init
(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-11 */
{
  /* Defining a pointer to the Channel Ram Data */
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;
  /* Local variable to hold the channel number */
  uint8 LucChannelNo;

  /* Implements:    ICU232_Conf,    ECUC_Icu_00232  */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;

  /* Implements:  ICU_ESDD_UD_177, ICU_ESDD_UD_134, ICU_ESDD_UD_133 */
  #if (ICU_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the ICU Driver is already initialized */
  if (ICU_INITIALIZED == Icu_GblDriverStatus)
  {
    /* Implements:  ICU_ESDD_UD_079 */
    /* Report Error to DET */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_INIT_SID, ICU_E_ALREADY_INITIALIZED);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED == Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  #endif /* End of (ICU_ALREADY_INIT_DET_CHECK == STD_ON) */
  /* Implements: ICU_ESDD_UD_185 */
  /* Check if the Configuration pointer is NULL */
  if (NULL_PTR == ConfigPtr)
  {
        /* Implements:  ICU_ESDD_UD_203 */
    #if (ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
        /* Report Error to Det */
        (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_INIT_SID,
          ICU_E_INIT_FAILED);

    #elif (ICU_AR_VERSION == ICU_AR_LOWER_VERSION)
        /* Implements: ICU_ESDD_UD_070 */
        /* Report Error to Det */
        (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_INIT_SID,
          ICU_E_PARAM_CONFIG);
    #endif
    LddReturnValue = E_OK;
  } /* End of NULL_PTR == ConfigPtr */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048, ICU243 */
  /* Check if any DET was reported   */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements:  ICU006, SWS_Icu_00006 */
    /* MISRA Violation: START Msg(7:0505)-5 */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* Check if the database is flashed on the target device */
    if ( ICU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(7:0505)-5 */
    /* END Msg(2:2814)-12 */
    {
      /* MISRA Violation: START Msg(4:0317)-2 */
      /*
       * Update the global pointer with the first channel's configuration
       * database address
       */
      Icu_GpChannelConfig = ConfigPtr->pChannelConfig;
      /* Implements: ICU_ESDD_UD_037 */
      #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
      /* Update the global pointer with the Previous input configuration */
      Icu_GpPreviousInputConfig = ConfigPtr->pPrevInputConfig;
      #endif
      /* Update the global pointer with the first channel's ram address */
      Icu_GpChannelRamData = ConfigPtr->pRamAddress;
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
      (ICU_TAUB_UNIT_USED == STD_ON))
      /*
       * Update the global pointer with the first Timer channel's configuration
       * database address
       */
      Icu_GpTimerChannelConfig = ConfigPtr->pTimerChannelConfig;
      /* Update the global pointer with the ICU Hardware unit configuration */
      Icu_GpTAUUnitConfig = ConfigPtr->pHWUnitConfig;

      /*
       * Update the global pointer with the first channel's address
       * of Signal Measurement mode type channel's RAM data
       */
      Icu_GpSignalMeasurementData = ConfigPtr->pSignalMeasureAddress;
      /*
       * Update the global pointer with the first channel's address
       * of Timestamp mode type channel's RAM data
       */
      Icu_GpTimeStampData = ConfigPtr->pTimeStampAddress;
      /*
       * Update the global pointer with the first channel's address
       * of Edge Count mode type channel's RAM data
       */
      Icu_GpEdgeCountData = ConfigPtr->pEdgeCountRamAddress;
      #endif

      #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
      /*
       * Update the global pointer with the first channel's address
       * of Wake up factor Register's
       */
      Icu_GpWakeUpFactorRamAddress = ConfigPtr->pWakeUpFactorRamAddress;
      #endif
      /* END Msg(4:0317)-2 */

      /* Initialize all the configured Icu Channels */
      for (LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL;
                                                                LucChannelNo++)
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        /* QAC Warning: START Msg(2:2824)-9 */
        /* Load the channel data pointer */
        LpRamData = &Icu_GpChannelRamData[LucChannelNo];
        /* END Msg(4:0491)-1 */
        /* END Msg(2:2824)-9 */
        /* Implements:  ICU040, SWS_Icu_00040 */
        /* Initialize each channel status as idle */
        /* QAC Warning: START Msg(2:2814)-12 */
        /* QAC Warning: START Msg(2:3892)-13 */
        LpRamData->uiChannelStatus = (uinteger)ICU_IDLE;
        /* END Msg(2:2814)-12 */
        /* END Msg(2:3892)-13 */
        /* QAC Warning: START Msg(2:3892)-13 */
        /* Initialize result for completion of interrupts as false*/
        LpRamData->uiResultComplete = ICU_FALSE;
        /* Implements:  ICU121, SWS_Icu_00121 */
        /* Disable each channel wakeup from sleep mode */
        LpRamData->uiWakeupEnable = ICU_FALSE;
        /* Implements:  ICU061, SWS_Icu_00061 */
        /* Disable notification for each channel */
        LpRamData->uiNotificationEnable = ICU_FALSE;

        /* No measurementes are running */
        LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
        /* END Msg(2:3892)-13 */
      } /* End of for loop */

      /* Invoke low level driver for initializing the hardware */
      Icu_HW_Init();
      #if (ICU_DEV_ERROR_DETECT == STD_ON)
      /* Set Icu Driver status as initialized */
      Icu_GblDriverStatus = ICU_INITIALIZED;
      #endif
      /* Implements:    ICU060, SWS_Icu_00060 */
      /* Set Icu Driver Mode as normal  */
      Icu_GenModuleMode = ICU_MODE_NORMAL;
      #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
      /* Set the wakeup source as none */
      Icu_GulWakeupSource = ICU_NOWAKEUP;
      #endif
    } /* End of ICU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc) */

    /*If there is no valid database is present */
    else
    {
      #if (ICU_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      /* Implements: ICU004, EAAR_PN0034_FR_0016 */
      (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_INIT_SID,
                                                       ICU_E_INVALID_DATABASE);
      /* MISRA Violation: START Msg(4:2983)-4 */
      LddReturnValue = E_OK;
      /* END Msg(4:2983)-4 */
      #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
    }
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_Init */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/*******************************************************************************
** Function Name         : Icu_DeInit
**
** Service ID            : 0x01
**
** Description           : This API performs the De-Initialization of the Icu
**                         Driver Component by making all the registers to the
**                         power on reset state.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_DE_INIT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, Icu_HW_DeInit.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_022, ICU234_Conf, ECUC_Icu_00234                   */
#if (ICU_DE_INIT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_AD_089                                               */
/* Implements:  ICU022, SWS_Icu_00022, ICU035, SWS_Icu_00035                  */
/* Implements:  ICU036, SWS_Icu_00036, ICU037, SWS_Icu_00037                  */
/* Implements:  ICU048, ICU050, SWS_Icu_00050                                 */
/* Implements:  ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                  */
/* Implements:  ICU057, SWS_Icu_00057, ICU091, SWS_Icu_00091                  */
/* Implements:  ICU092, SWS_Icu_00092, ICU152, SWS_Icu_00152                  */
/* Implements:  ICU193, SWS_Icu_00193, ICU213, SWS_Icu_00213                  */
/* Implements:  ICU221, SWS_Icu_00221, ICU234, SWS_Icu_00234                  */
/* Implements:  ICU299, SWS_Icu_00299, ICU301, SWS_Icu_00301                  */
/* Implements:  ICU300, SWS_Icu_00300                                         */
FUNC(void, ICU_PUBLIC_CODE) Icu_DeInit(void)
{
  /* Defining a pointer to the Timer registers */
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;

  /* Local variable to hold the channel number */
  uint8 LucChannelNo;

  /* Implements:    ICU022, SWS_Icu_00022 */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_NOT_OK;
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DEINIT_SID,
                                                                 ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* Set Icu Driver status as un-initialized */
    Icu_GblDriverStatus = ICU_UNINITIALIZED;
    #endif
    /* Implements:  ICU_ESDD_UD_035, ICU_ESDD_UD_059                          */
    for (LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL;
                                                               LucChannelNo++)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:2824)-9 */
      /* Load the channel data pointer */
      LpRamData = &Icu_GpChannelRamData[LucChannelNo];
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-9 */
      /* Initialize each channel status as idle */
      /* QAC Warning: START Msg(2:2814)-12 */
      /* QAC Warning: START Msg(2:3892)-13 */
      LpRamData->uiChannelStatus = (uinteger)ICU_IDLE;
      /* END Msg(2:2814)-12 */
      /* END Msg(2:3892)-13 */
      /* QAC Warning: START Msg(2:3892)-13 */
      /* Set result for completion of interrupts as false*/
      LpRamData->uiResultComplete = ICU_FALSE;
      /* Disable each channel wakeup from sleep mode */
      LpRamData->uiWakeupEnable = ICU_FALSE;
      /* Disable notification for each channel */
      LpRamData->uiNotificationEnable = ICU_FALSE;
      /* Disable measurements */
      LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
      /* END Msg(2:3892)-13 */
    } /* End of for loop */

    /* Invoke low level driver for De-Initializing the hardware */
    Icu_HW_DeInit();
  } /* End of (E_NOT_OK == LddReturnValue) */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_DeInit */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_DE_INIT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_SetMode
**
** Service ID            : 0x02
**
** Description           : This API service will set the operation mode of the
**                         Icu Driver.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_SET_MODE_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, Icu_HW_SetMode.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_023, ICU241_Conf, ECUC_Icu_00241                   */
#if (ICU_SET_MODE_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements: ICU_ESDD_UD_090                                                */
/* Implements: ICU194, SWS_Icu_00194, ICU008, SWS_Icu_00008                   */
/* Implements: ICU302, SWS_Icu_00302, ICU095, SWS_Icu_00095                   */
/* Implements: ICU012, SWS_Icu_00012, ICU260, SWS_Icu_00260                   */
/* Implements: ICU261, SWS_Icu_00261, ICU303, SWS_Icu_00303                   */
/* Implements: ICU125, SWS_Icu_00125, ICU048, ICU150, SWS_Icu_00150           */
/* Implements: ICU022, SWS_Icu_00022, ICU133, SWS_Icu_00133                   */
/* Implements: ICU050, SWS_Icu_00050, ICU213, SWS_Icu_00213                   */
/* Implements: ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                   */
/* Implements: ICU057, SWS_Icu_00057, ICU241, SWS_Icu_00241                   */
/* Implements: EAAR_PN0067_FR_0054                                            */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_SetMode(Icu_ModeType Mode)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  #if (ICU_BUSY_OPERATION_DET_CHECK == STD_ON)
  /* Local variable to loop through the channels */
  uint8 LucChannelNo;
  /* Local variable to store the Measurement status */
  uint8 LucMeasurementStatus;
  /* Local variable to store the channel running operation status */
  boolean LblRunningOperation;

  #endif /* End of (ICU_BUSY_OPERATION_DET_CHECK == STD_ON) */

  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                             ICU_SET_MODE_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:3356)-6 */
  /* MISRA Violation: START Msg(4:3359)-7 */
  /* Implements:    ICU125, SWS_Icu_00125 */
  /* Check if mode is neither ICU_MODE_NORMAL nor ICU_MODE_SLEEP */
  if ((ICU_MODE_NORMAL != Mode) && (ICU_MODE_SLEEP != Mode))
  /* END Msg(4:3359)-7 */
  /* END Msg(4:3356)-6 */
  /* MISRA Violation: START Msg(4:3201)-8 */
  {
    /* END Msg(4:3201)-8 */
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                          ICU_SET_MODE_SID, ICU_E_PARAM_MODE);
    LddReturnValue = E_OK;
  } /* End of (ICU_MODE_NORMAL != Mode) && (ICU_MODE_SLEEP != Mode) */
  else
  {
    /* No action required */
  }


  #if (ICU_BUSY_OPERATION_DET_CHECK == STD_ON)
  /* Setting Running Operation as false*/
  LblRunningOperation = ICU_FALSE;

  LucChannelNo = ICU_ZERO;
  
  /* Implements: ICU270 */
  /* Check if the channel is running, if it is, report DET */
  do
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Read the Measurement status */
    LucMeasurementStatus =
              Icu_GpChannelRamData[LucChannelNo].uiChannelMeasurementRunning;
    /* END Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:2000)-15 */
    /* QAC Warning: START Msg(2:3892)-20 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check whether channel is not wakeup capable and running or not */
    if ((ICU_TRUE == LucMeasurementStatus) &&
        (ICU_FALSE == Icu_GpChannelConfig[LucChannelNo].uiIcuWakeupCapability))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:2000)-15 */
    {
      /* Update running operation as TRUE */
      LblRunningOperation = ICU_TRUE;
    }
    else
    {
      /* No action required */
    }


    /* Increment the pointer to point to the next channel */
    LucChannelNo++;

  } while ((LucChannelNo < ICU_MAX_CHANNEL) &&
                                           (ICU_TRUE != LucMeasurementStatus));

  if((ICU_MODE_SLEEP == Mode) && (ICU_TRUE == LblRunningOperation))
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_SET_MODE_SID, ICU_E_BUSY_OPERATION);
    LddReturnValue = E_OK;
  }
  else
  {
      /* No action required */
  }

  #endif /* End of (ICU_BUSY_OPERATION_DET_CHECK == STD_ON) */


  /* Implements:    ICU048 */
  /* Check if any DET was reported   */
  /* QAC Warning: START Msg(2:2000)-15 */
  if (E_OK == LddReturnValue)
  /* END Msg(2:2000)-15 */
  {
    /* Do nothing */
  }
  else
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements:  ICU008 */
    /* Invoke low level set mode function */
    Icu_HW_SetMode(Mode);
  } /* End of E_NOT_OK == LddReturnValue */
} /* End of API Icu_SetMode */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SET_MODE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_DisableWakeup
**
** Service ID           : 0x03
**
** Description          : This API service will disable the wakeup interrupt of
**                        the requested Icu channel. The requested channel must
**                        be wakeup capable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized,
**                        ICU_DISABLE_WAKEUP_API must be STD_ON
**
** Global Variables     : Icu_GblDriverStatus, Icu_GpChannelConfig,
**                        Icu_GpChannelRamData, Icu_GulWakeupSource.
**
** Functions invoked    : Det_ReportError, ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_024,ICU_ESDD_UD_222                               */
/* Implements:  ICU235_Conf, ECUC_Icu_00235                                   */
#if (ICU_DISABLE_WAKEUP_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_091                                               */
/* Implements:  ICU195, SWS_Icu_00195, ICU013, SWS_Icu_00013                  */
/* Implements:  ICU305, SWS_Icu_00305, ICU304, SWS_Icu_00304                  */
/* Implements:  ICU096, SWS_Icu_00096, ICU306, SWS_Icu_00306                  */
/* Implements:  ICU156, SWS_Icu_00156, ICU048                                 */
/* Implements:  ICU022, SWS_Icu_00022, ICU024, SWS_Icu_00024                  */
/* Implements:  ICU059, SWS_Icu_00059, ICU213, SWS_Icu_00213                  */
/* Implements:  ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                  */
/* Implements:  ICU057, SWS_Icu_00057, ICU235, SWS_Icu_00235                  */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_DisableWakeup (Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                        ICU_DISABLE_WAKEUP_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU059, SWS_Icu_00059 */
  /* Implements:    ICU024, SWS_Icu_00024 */
  /* Check if the channel is valid  */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_DISABLE_WAKEUP_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the channel is wakeup capable */
    if (ICU_FALSE == Icu_GpChannelConfig[Channel].uiIcuWakeupCapability)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_DISABLE_WAKEUP_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    } /*
       * End of Icu_GpChannelConfig[Channel].uiIcuWakeupCapability == ICU_FALSE
       */
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    /* Implements:  ICU_ESDD_UD_004, EAAR_PN0034_FR_0030*/
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU012, SWS_Icu_00012 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Store the disabled wakeup status into RAM */
    Icu_GpChannelRamData[Channel].uiWakeupEnable = (uinteger)ICU_FALSE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */

    #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Set the wakeup source information */
    Icu_GulWakeupSource = (Icu_GulWakeupSource &
      (~(Icu_GpChannelConfig[Channel].ddEcuMChannelWakeupInfo)));
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    #endif

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    /* Implements:  ICU_ESDD_UD_004, EAAR_PN0034_FR_0030*/
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Icu_DisableWakeup */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_DISABLE_WAKEUP_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_EnableWakeup
**
** Service ID           : 0x04
**
** Description          : This API service will enable the wakeup interrupt of
**                        the requested Icu channel. The requested channel must
**                        be wakeup capable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized,
**                        ICU_ENABLE_WAKEUP_API must be STD_ON
**
** Global Variables     : Icu_GblDriverStatus, Icu_GpChannelRamData,
**                        Icu_GpChannelConfig, Icu_GulWakeupSource.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION,
**                        and Det_ReportError.
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_025,ICU_ESDD_UD_223                               */
/* Implements:  ICU236_Conf, ECUC_Icu_00236                                   */
#if (ICU_ENABLE_WAKEUP_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_092                                               */
/* Implements:  ICU196, SWS_Icu_00196, ICU307, SWS_Icu_00307                  */
/* Implements:  ICU014, SWS_Icu_00014, ICU097, SWS_Icu_00097                  */
/* Implements:  ICU308, SWS_Icu_00308, ICU155, SWS_Icu_00155                  */
/* Implements:  ICU156, SWS_Icu_00156, ICU048                                 */
/* Implements:  ICU022, SWS_Icu_00022, ICU213, SWS_Icu_00213                  */
/* Implements:  ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                  */
/* Implements:  ICU057, SWS_Icu_00057, ICU236, SWS_Icu_00236                  */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_EnableWakeup(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                          ICU_ENABLE_WAKEUP_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU155, SWS_Icu_00155 */
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                   ICU_ENABLE_WAKEUP_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU156, SWS_Icu_00156 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the channel is wakeup capable */
    if (ICU_FALSE == Icu_GpChannelConfig[Channel].uiIcuWakeupCapability)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                 ICU_ENABLE_WAKEUP_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    } /*
       * End of Icu_GpChannelConfig[Channel].uiIcuWakeupCapability == ICU_FALSE
       */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU014, SWS_Icu_00014 */
    /* Implements:  ICU012, SWS_Icu_00012 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Store the enabled wakeup status into RAM */
    Icu_GpChannelRamData[Channel].uiWakeupEnable = (uinteger)ICU_TRUE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Set the wakeup source information */
    Icu_GulWakeupSource = (Icu_GulWakeupSource |
      (Icu_GpChannelConfig[Channel].ddEcuMChannelWakeupInfo));
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    #endif

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_EnableWakeup */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_ENABLE_WAKEUP_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_CheckWakeup
**
** Service ID            : 0x15
**
** Description           : This API checks the wakeup notification for a
**                         particular channel
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : WakeupSource
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Icu_Init must be called before this function,
**                         ICU_REPORT_WAKEUP_SOURCE must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GulWakeupSource.
**
** Functions invoked     : Det_ReportError, ICU_ENTER_CRITICAL_SECTION,
**                         ICU_EXIT_CRITICAL_SECTION and EcuM_SetWakeupEvent.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_033                                               */
/* Implements:  ICU355_Conf, ECUC_Icu_00355                                   */

/* Implements:  ICU_ESDD_UD_021                                               */
/* Implements:  ICU233_Conf, ECUC_Icu_00233                                   */
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
    (ICU_REPORT_WAKEUP_SOURCE == STD_ON))

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_093                                               */
/* Implements:  ICU358, SWS_Icu_00358, ICU359, SWS_Icu_00359                  */
/* Implements:  ICU360, SWS_Icu_00360, ICU361, SWS_Icu_00361                  */
/* Implements:  ICU362, SWS_Icu_00362, ICU363, SWS_Icu_00363                  */
/* Implements:  EAAR_PN0067_FR_0074                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Implements:    ICU022,SWS_Icu_00022 */
  /* Check if the ICU Driver is initialized properly */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                         ICU_CHECK_WAKEUP_SID, ICU_E_UNINIT);

  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  #endif/* End of ICU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Implements:  ICU359 */
    /* Check if the wakeup source is valid */
    if ((Icu_GulWakeupSource&WakeupSource) == WakeupSource)
    {
      /* Invoke the EcuM Set Wakeup API*/
      EcuM_SetWakeupEvent(WakeupSource);
    } /* End of (Icu_GulWakeupSource&WakeupSource) == WakeupSource */
    else
    {
      /*
       * None of the channels which are wakeup capable are configured with
       * the WakeupSource values requested by this API, hence do nothing.
       */
    }
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
} /* End of API Icu_CheckWakeup */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /*
        * #if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) &&
        *      (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
        */

/*******************************************************************************
** Function Name         : Icu_SetActivationCondition
**
** Service ID            : 0x05
**
** Description           : This API service will set the activation edge
**                         according to the Activation parameter for the given
**                         channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel, Activation
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized.
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GblDriverStatus, Icu_GpChannelRamData,
**                         Icu_GpTimeStampData, Icu_GpEdgeCountData.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         Det_ReportError and Icu_HW_SetActivation.
**
** Registers Used        : None
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_094                                               */
/* Implements:  ICU197, SWS_Icu_00197, ICU090, SWS_Icu_00090                  */
/* Implements:  ICU139, SWS_Icu_00139, ICU309, SWS_Icu_00309                  */
/* Implements:  ICU159, SWS_Icu_00159, ICU043, SWS_Icu_00043                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU011, SWS_Icu_00011                                         */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_SetActivationCondition
(Icu_ChannelType Channel, Icu_ActivationType Activation)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }

  /* Implements:    ICU043, SWS_Icu_00043 */
  /* MISRA Violation: START Msg(4:3356)-6 */
  /* MISRA Violation: START Msg(4:3359)-7 */
  /* QAC Warning: START Msg(2:1476)-15 */
  /* Check if the activation edge other than Rising or Falling or Both edges */
  if (ICU_BOTH_EDGES < Activation)
  /* END Msg(4:3359)-7 */
  /* END Msg(4:3356)-6 */
  /* END Msg(2:1476)-15 */
  /* MISRA Violation: START Msg(4:3201)-8 */
  {
    /* END Msg(4:3201)-8 */
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                     ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_ACTIVATION);
    LddReturnValue = E_OK;
  } /* End of Activation > ICU_BOTH_EDGES */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU159, SWS_Icu_00159 */
  /* Check if the channel is valid */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
    /* Implements:  ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT ==
                        Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
    /*  Implements: ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU139, SWS_Icu_00139 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Initialize channel status as idle */
    Icu_GpChannelRamData[Channel].uiChannelStatus = (uinteger)ICU_IDLE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Set the activation edge value */
    Icu_HW_SetActivation (Channel, Activation,
                          ICU_SET_ACTIVATION_CONDITION_SID);
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_SetActivationCondition */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/*******************************************************************************
** Function Name         : Icu_DisableNotification
**
** Service ID            : 0x06
**
** Description           : This API service will disable the Icu signal
**                         notification of the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized.
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_206                                               */
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_095                                               */
/* Implements:  ICU198, SWS_Icu_00198, ICU009, SWS_Icu_00009                  */
/* Implements:  ICU310, SWS_Icu_00310, ICU160, SWS_Icu_00160                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU251, SWS_Icu_00251, ICU187, SWS_Icu_00187                  */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_DisableNotification(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                   ICU_DISABLE_NOTIFICATION_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU160, SWS_Icu_00160   */
  /* Check if the channel is valid  */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
    /* Implements:  ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Time Stamp measurement */
    if (((uinteger)ICU_MODE_SIGNAL_MEASUREMENT ==
         Icu_GpChannelConfig[Channel].uiIcuMeasurementMode) ||
         ((uinteger)ICU_MODE_EDGE_COUNTER ==
                             Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
/* Implements:  ICU_ESDD_UD_164                                               */
    #if (ICU_ALREADY_ENABLED_DISABLED_DET_CHECK == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* Check if any DET was reported */
    if (LddReturnValue == E_NOT_OK)
    {
      /* Check if the notification for the channel is already Disabled */
      /* QAC Warning: START Msg(2:2824)-9 */
      if ((uinteger)ICU_FALSE ==
                            Icu_GpChannelRamData[Channel].uiNotificationEnable)
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-9 */
      {
        /* Report Error to Det */
        (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                          ICU_DISABLE_NOTIFICATION_SID, ICU_E_ALREADY_DISABLED);
        LddReturnValue = E_OK;
      }/*
        * End of Icu_GpChannelRamData[Channel].uiNotificationEnable == ICU_FALSE
        */
      else
      {
        /* No action required */
      }
    } /* End of E_NOT_OK == LddReturnValue */
    else
    {
      /* No action required */
    }
    #endif
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
    /* Implements:  ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU042, SWS_Icu_00042  */
    /* Implements:  ICU217, SWS_Icu_00217 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Store the disabled notification into RAM */
    Icu_GpChannelRamData[Channel].uiNotificationEnable = (uinteger)ICU_FALSE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  } /* End of E_NOT_OK == LddReturnValue */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_DisableNotification */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/*******************************************************************************
** Function Name         : Icu_EnableNotification
**
** Service ID            : 0x07
**
** Description           : This API service will enable the Icu signal
**                         notification of the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized.
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig,
**                         Icu_GpChannelRamData, Icu_GulWakeupSource.
**
** Functions invoked     : Det_ReportError, ICU_EXIT_CRITICAL_SECTION
**                         ICU_ENTER_CRITICAL_SECTION
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_207 */
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_096                                               */
/* Implements:  ICU199, SWS_Icu_00199, ICU010, SWS_Icu_00010                  */
/* Implements:  ICU311, SWS_Icu_00311, ICU161, SWS_Icu_00161                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU127, SWS_Icu_00127, ICU213, SWS_Icu_00213                  */
/* Implements:  ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                  */
/* Implements:  ICU057, SWS_Icu_00057, ICU252, SWS_Icu_00252                  */
/* Implements:  SWS_Icu_00187, EAAR_PN0067_FR_0053                            */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_EnableNotification(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_ENABLE_NOTIFICATION_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU161, SWS_Icu_00161   */
  /* Check if the channel is valid  */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_ENABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Time Stamp measurement */
    if (((uinteger)ICU_MODE_SIGNAL_MEASUREMENT ==
          Icu_GpChannelConfig[Channel].uiIcuMeasurementMode) ||
          ((uinteger)ICU_MODE_EDGE_COUNTER ==
          Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_ENABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
/* Implements:  ICU_ESDD_UD_164                                               */
    #if (ICU_ALREADY_ENABLED_DISABLED_DET_CHECK == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the notification for the channel is already Enabled */
    if ((uinteger)ICU_TRUE ==
                     Icu_GpChannelRamData[Channel].uiNotificationEnable)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_ENABLE_NOTIFICATION_SID, ICU_E_ALREADY_ENABLED);
      LddReturnValue = E_OK;
    } /* End of ICU_TRUE ==Icu_GpChannelRamData[Channel].uiNotificationEnable */
    else
    {
      /* No action required */
    }
    #endif
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:ICU134, SWS_Icu_00134 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Store enabled notification into RAM */
    Icu_GpChannelRamData[Channel].uiNotificationEnable = (uinteger)ICU_TRUE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Check if the channel is wakeup capable */
    if (ICU_TRUE == Icu_GpChannelConfig[Channel].uiIcuWakeupCapability)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    {
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Implements:    ICU_ESDD_UD_138 */
      #if (ICU_NOTIFY_WAKEUP_INTERRUPT == STD_ON)
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:3892)-13 */
      /* Store the enabled wakeup status into RAM */
      Icu_GpChannelRamData[Channel].uiWakeupEnable = (uinteger)ICU_TRUE;
      /* END Msg(4:0491)-1 */
      /* END Msg(2:3892)-13 */
      #endif /* End of (ICU_NOTIFY_WAKEUP_INTERRUPT == STD_ON) */

      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_EnableNotification */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/*******************************************************************************
** Function Name         : Icu_GetInputState
**
** Service ID            : 0x08
**
** Description           : This API service will return the status of the Icu
**                         input.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Icu_InputStateType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_GET_INPUT_STATE_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, ICU_ENTER_CRITICAL_SECTION and
**                         ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_026, ICU_ESDD_UD_097                              */
/* Implements:  ICU238_Conf, ECUC_Icu_00238                                   */
#if (ICU_GET_INPUT_STATE_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_094                                               */
/* Implements:  ICU197, SWS_Icu_00197, ICU090, SWS_Icu_00090                  */
/* Implements:  ICU139, SWS_Icu_00139, ICU309, SWS_Icu_00309                  */
/* Implements:  ICU159, SWS_Icu_00159, ICU043, SWS_Icu_00043                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022, ICU248, SWS_Icu_00248          */
/* Implements:  ICU122, SWS_Icu_00122, ICU315, SWS_Icu_00315                  */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU011, SWS_Icu_00011, ICU312, SWS_Icu_00312                  */
/* Implements:  ICU200, SWS_Icu_00200                                         */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_InputStateType, ICU_PUBLIC_CODE) Icu_GetInputState
                                                      (Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /* Local variable to store the channel status */
  Icu_InputStateType LenChannelState;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif

  /* Implements:    ICU049, SWS_Icu_00049   */
  /* Implements:    ICU033 */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set the initial state to Idle  */
  LenChannelState = ICU_IDLE;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                      ICU_GET_INPUT_STATE_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU162, SWS_Icu_00162   */
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to DET */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_GET_INPUT_STATE_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU162, SWS_Icu_00162   */
  /* Implements:    ICU030, SWS_Icu_00030   */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if (((uinteger)ICU_MODE_SIGNAL_EDGE_DETECT
                       != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode) &&
        ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT
                          != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to DET */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_GET_INPUT_STATE_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU031, SWS_Icu_00031   */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:4342)-14 */
    /* Read the channel input status */
    LenChannelState =
       (Icu_InputStateType)Icu_GpChannelRamData[Channel].uiChannelStatus;
    /* END Msg(2:2824)-9 */
    /* END Msg(2:4342)-14 */
    /* Implements:  ICU313, SWS_Icu_00313  */
    /* Implements:  ICU032, SWS_Icu_00032   */
    /* Store channel status as idle */
    /* QAC Warning: START Msg(2:3892)-13 */
    Icu_GpChannelRamData[Channel].uiChannelStatus = (uinteger)ICU_IDLE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* Implements:    ICU033  */
  return(LenChannelState);

} /* End of API Icu_GetInputState */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_GET_INPUT_STATE_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_StartTimestamp
**
** Service ID            : 0x09
**
** Description           : This API service starts the capturing of timer values
**                         on the edges activated (rising/falling/both) to an
**                         external buffer at the beginning of the buffer.
**
** Sync/Async            : Asynchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel, BufferPtr, BufferSize, NotifyInterval
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_TIMESTAMP_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GblDriverStatus, Icu_GpTimeStampData,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, ICU_EXIT_CRITICAL_SECTION
**                         ICU_ENTER_CRITICAL_SECTION and
**                         Icu_HW_StartCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_027, ICU_ESDD_UD_208                              */
/* Implements:  ICU123_Conf, ECUC_Icu_00123, ICU099, SWS_ICU_00099            */
#if (ICU_TIMESTAMP_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_098                                               */
/* Implements:  ICU201, SWS_Icu_00201, ICU317, SWS_Icu_00317                  */
/* Implements:  ICU063, SWS_Icu_00063, ICU316, SWS_Icu_00316                  */
/* Implements:  ICU064, SWS_Icu_00064, ICU065, SWS_Icu_00065                  */
/* Implements:  ICU134, SWS_Icu_00134, ICU318, SWS_Icu_00318                  */
/* Implements:  ICU319, SWS_Icu_00319, ICU320, SWS_Icu_00320                  */
/* Implements:  ICU098, SWS_Icu_00098, ICU321, SWS_Icu_00321                  */
/* Implements:  ICU163, SWS_Icu_00163, ICU120, SWS_Icu_00120                  */
/* Implements:  ICU108, SWS_Icu_00108, ICU048, ICU218, ICU215, ICU349         */
/* Implements:  ICU022, SWS_Icu_00022, ICU066, SWS_Icu_00066                  */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU123, SWS_Icu_00123, ICU354, SWS_ICU_00354                  */
/* Implements:  SWS_Icu_00218, SWS_Icu_00215, SWS_Icu_00349                   */
/* Implements:  ICU230_Conf,    ECUC_Icu_00230                                */
/* Implements:  EAAR_PN0067_FR_0032                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_StartTimestamp (Icu_ChannelType Channel,
P2VAR (Icu_ValueType, AUTOMATIC, ICU_APPL_DATA)BufferPtr,
uint16 BufferSize, uint16 NotifyInterval)
/* END Msg(2:3227)-11 */
{
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;

  /* Local pointer variable for Timestamps channel data */
  P2VAR(Icu_TimeStampChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                                LpTimeStampData;
  /* Local variable to loop through the channels */
  uint8 LucIndex;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED  != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                       ICU_START_TIMESTAMP_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED  != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                 ICU_START_TIMESTAMP_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU108, SWS_Icu_00108   */
  /* Implements:    ICU120  */
  /* Check if pointer passed is Null */
  if (NULL_PTR == BufferPtr)
  {
#if (ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_START_TIMESTAMP_SID, ICU_E_PARAM_POINTER);
#elif (ICU_AR_VERSION == ICU_AR_LOWER_VERSION)
    /* Report Error to Det */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_START_TIMESTAMP_SID, ICU_E_PARAM_BUFFER_PTR);
#endif
    LddReturnValue = E_OK;
  } /* End of NULL_PTR == BufferPtr */
  else
  {
    /* No action required */
  }
  /* Check if the channel buffer size is zero */
  /* QAC Warning: START Msg(2:3892)-13 */
  if (ICU_ZERO == BufferSize)
  /* END Msg(2:3892)-13 */
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_START_TIMESTAMP_SID, ICU_E_PARAM_BUFFER_SIZE);
    LddReturnValue = E_OK;
  } /* End of BufferSize == ICU_ZERO */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU320, SWS_Icu_00320   */
  /* Implements:    ICU354, SWS_Icu_00354   */
  /* Implements:    ICU319, SWS_Icu_00319   */
  /* Check if the channel notifying interval less than one */
  /* QAC Warning: START Msg(2:3892)-13 */
  if (ICU_NOTIFY_INTERVAL_MIN_VAL > NotifyInterval)
  /* END Msg(2:3892)-13 */
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_START_TIMESTAMP_SID, ICU_E_PARAM_NOTIFY_INTERVAL);
    LddReturnValue = E_OK;
  } /* End of NotifyInterval < ICU_NOTIFY_INTERVAL_MIN_VAL */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU163, SWS_Icu_00163   */
    /* Implements:  ICU066, SWS_Icu_00066   */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if ((uinteger)ICU_MODE_TIMESTAMP !=
                 Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                 ICU_START_TIMESTAMP_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    } /*
       * End of Icu_GpChannelConfig[Channel].uiIcuMeasurementMode !=
       * ICU_MODE_TIMESTAMP
       */
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    LucIndex = Icu_GpTimerChannelConfig[Channel].ucRamDataIndex;

    /* Initialize Timestamp RAM data */
    LpTimeStampData = &Icu_GpTimeStampData[LucIndex];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:2814)-12 */
    LpTimeStampData->pBufferPointer = BufferPtr;
    /* END Msg(2:2814)-12 */
    LpTimeStampData->usBufferSize = BufferSize;
    /* QAC Warning: START Msg(2:3892)-13 */
    LpTimeStampData->usTimestampIndex = ICU_BUFFER_IDX_INIT_VAL;
    LpTimeStampData->usTimestampsCounter = ICU_TIMESTAMP_RESET_CNT_VAL;
    /* END Msg(2:3892)-13 */
    LpTimeStampData->usNotifyInterval = NotifyInterval;

    /* Activate Timestamp capturing */
    Icu_HW_StartCountMeasurement(Channel, ICU_START_TIMESTAMP_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_TIMESTAMP_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation : START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Load the channel data pointer */
    LpRamData = &Icu_GpChannelRamData[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /*Measurement is started */
    LpRamData->uiChannelMeasurementRunning = (uinteger)ICU_TRUE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2814)-12 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_TIMESTAMP_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_StartTimestamp */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_TIMESTAMP_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_StopTimestamp
**
** Service ID            : 0x0A
**
** Description           : This API service stops the timestamp measurement of
**                         the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_TIMESTAMP_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpChannelRamData
**                         Icu_GblDriverStatus.
**
** Functions invoked     : Det_ReportError, ICU_EXIT_CRITICAL_SECTION
**                         ICU_ENTER_CRITICAL_SECTION and
**                         Icu_HW_StopCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_027, ICU_ESDD_UD_209                              */
/* Implements:  ICU123_Conf, ECUC_Icu_00123, ICU099, SWS_ICU_00099            */
#if (ICU_TIMESTAMP_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_099                                               */
/* Implements:  ICU202, SWS_Icu_00202, ICU067, SWS_Icu_00067                  */
/* Implements:  ICU322, SWS_Icu_00322, ICU165, SWS_Icu_00165                  */
/* Implements:  ICU099, SWS_Icu_00099, ICU164, SWS_Icu_00164                  */
/* Implements:  ICU323, SWS_Icu_00323, ICU166, SWS_Icu_00166                  */

/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_StopTimestamp(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED  != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                         ICU_STOP_TIMESTAMP_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_STOP_TIMESTAMP_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU164, SWS_Icu_00164   */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the channel is other than Time Stamp measurement */
    if ((uinteger)ICU_MODE_TIMESTAMP !=
                      Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_STOP_TIMESTAMP_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    } /*
       * Icu_GpChannelConfig[Channel].uiIcuMeasurementMode != ICU_MODE_TIMESTAMP
       */
    else
    {
      /* No action required */
    }
   /* Check if any DET was reported */
    if (E_NOT_OK == LddReturnValue)
    {
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
       /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:2824)-9 */
      /* Load the channel data pointer */
      LpRamData = &Icu_GpChannelRamData[Channel];
      /* END Msg(2:2824)-9 */
      /* Check if the status of timestamping execution */
      /* QAC Warning: START Msg(2:2814)-12 */
      /* QAC Warning: START Msg(2:3892)-13 */
      if (ICU_FALSE == LpRamData->uiChannelMeasurementRunning)
      {
        /* END Msg(4:0491)-1 */
        /* END Msg(2:2814)-12 */
        /* END Msg(2:3892)-13 */
        /* Report Error to Det */
        (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                     ICU_STOP_TIMESTAMP_SID, ICU_E_NOT_STARTED);
        LddReturnValue = E_OK;
      }
      else
      {
        /* No action required */
      }
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    } /* End of LddReturnValue == E_NOT_OK */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Disable Timestamp capturing */
    Icu_HW_StopCountMeasurement(Channel, ICU_STOP_TIMESTAMP_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* MISRA Violation: START Msg(4:0491)-1 */
        /* QAC Warning: START Msg(2:2824)-9 */
        /* Load the channel data pointer */
        LpRamData = &Icu_GpChannelRamData[Channel];
        /* END Msg(4:0491)-1 */
        /* END Msg(2:2824)-9 */

        /* Disable measurements */
        /* QAC Warning: START Msg(2:2814)-12 */
        /* QAC Warning: START Msg(2:3892)-13 */
        LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
        /* END Msg(2:2814)-12 */
        /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_StopTimestamp */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_TIMESTAMP_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_GetTimestampIndex
**
** Service ID            : 0x0B
**
** Description           : This API service reads the timestamp index the next
**                         to be written for the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Icu_IndexType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_TIMESTAMP_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpTimerChannelConfig,
**                         Icu_GpChannelConfig, Icu_GpTimeStampData.
**
** Functions invoked     : Det_ReportError, ICU_ENTER_CRITICAL_SECTION and
**                         ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_027, ICU_ESDD_UD_210                              */
/* Implements:  ICU123_Conf, ECUC_Icu_00123, ICU099, SWS_ICU_00099            */
#if (ICU_TIMESTAMP_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_100                                               */
/* Implements:  ICU203, SWS_Icu_00203, ICU071, SWS_Icu_00071                  */
/* Implements:  ICU324, SWS_Icu_00324, ICU135, SWS_Icu_00135                  */
/* Implements:  ICU170, SWS_Icu_00170, ICU100, SWS_Icu_00100                  */
/* Implements:  ICU325, SWS_Icu_00325, ICU169, SWS_Icu_00169                  */
/* Implements:  ICU107, SWS_Icu_00107, ICU048                                 */
/* Implements:  ICU022, SWS_Icu_00022, ICU213, SWS_Icu_00213                  */
/* Implements:  ICU123, SWS_Icu_00123, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_IndexType, ICU_PUBLIC_CODE) Icu_GetTimestampIndex
(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  uint16 LusTimestampIndex;
  uint8 LucIndex;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif
  /* QAC Warning: START Msg(2:3892)-13 */
  LusTimestampIndex = ICU_BUFFER_IDX_INIT_VAL;
  /* END Msg(2:3892)-13 */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU170, SWS_Icu_00170   */
    /* Implements:  ICU169, SWS_Icu_00169   */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Time Stamp measurement */
    if ((uinteger)ICU_MODE_TIMESTAMP
                         != (Icu_GpChannelConfig[Channel]).uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }

  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU107, SWS_Icu_00107   */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    LucIndex = Icu_GpTimerChannelConfig[Channel].ucRamDataIndex;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_TIMESTAMP_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements:  ICU071, SWS_Icu_00071 */
    /* Implements:  ICU135, SWS_Icu_00135 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* If timestamping is started, then only return timestamp index value */
    if (NULL_PTR != Icu_GpTimeStampData[LucIndex].pBufferPointer)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      LusTimestampIndex = Icu_GpTimeStampData[LucIndex].usTimestampIndex;
      /* END Msg(4:0491)-1 */
    }
    else
    {
      /* No action required */
    }

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_TIMESTAMP_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* Implements:    ICU107, SWS_Icu_00107 */
  return(LusTimestampIndex);

} /* End of API Icu_GetTimestampIndex */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_TIMESTAMP_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_ResetEdgeCount
**
** Service ID            : 0x0C
**
** Description           : This API resets the value of the counted edges.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_COUNT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig.
**
** Functions invoked     : Det_ReportError, Icu_HW_ResetEdgeCount.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_028, ICU_ESDD_UD_211                              */
/* Implements:  ICU124_Conf, ECUC_Icu_00124                                   */
#if (ICU_EDGE_COUNT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_101                                               */
/* Implements:  ICU204, SWS_Icu_00204, ICU072, SWS_Icu_00072                  */
/* Implements:  ICU326, SWS_Icu_00326, ICU101, SWS_Icu_00101                  */
/* Implements:  ICU327, SWS_Icu_00327, ICU171, SWS_Icu_00171                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* QAC Warning: START Msg(2:3227)-11 */
/* QAC Warning: START Msg(2:3206)-16 */
FUNC(void, ICU_PUBLIC_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
/* END Msg(2:3206)-16 */
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                       ICU_RESET_EDGE_COUNT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_RESET_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
    /* Implements:  ICU048  */
    /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU171, SWS_Icu_00171 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Edge counting */
    if (((uinteger)ICU_MODE_EDGE_COUNTER)
                         != (Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_RESET_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the Low Level Driver for resetting the edge count */
    Icu_HW_ResetEdgeCount(Channel);
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  #endif /*
          * End of  ((ICU_TAUD_UNIT_USED == STD_ON) ||
          * (ICU_TAUB_UNIT_USED == STD_ON))
          */

} /* End of API Icu_ResetEdgeCount */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_EnableEdgeCount
**
** Service ID            : 0x0D
**
** Description           : This API service enables the counting of edges of the
**                         requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_COUNT_API must be STD_ON
**
** Global Variables      : Icu_GpChannelRamData, Icu_GpChannelConfig,
**                         Icu_GblDriverStatus.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         Det_ReportError and Icu_HW_StartCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_028, ICU_ESDD_UD_212                              */
/* Implements:  ICU124_Conf, ECUC_Icu_00124                                   */
#if (ICU_EDGE_COUNT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_102                                               */
/* Implements:  ICU205, SWS_Icu_00205, ICU078, SWS_Icu_00078                  */
/* Implements:  ICU073, SWS_Icu_00073, ICU074, SWS_Icu_00074                  */
/* Implements:  ICU328, SWS_Icu_00328, ICU102, SWS_Icu_00102                  */
/* Implements:  ICU329, SWS_Icu_00329, ICU172, SWS_Icu_00172                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  EAAR_PN0067_FR_0033                                           */
/* QAC Warning: START Msg(2:3227)-11 */
/* Implements:  ICU_ESDD_UD_161                                               */
FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /* Defining a pointer to the Timer registers */
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;

  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                     ICU_ENABLE_EDGE_COUNT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_ENABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Implements:  ICU172, SWS_Icu_00172 */
    if ((uinteger)ICU_MODE_EDGE_COUNTER
                          != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_ENABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Start count measurement for the channel */
    Icu_HW_StartCountMeasurement(Channel, ICU_ENABLE_EDGE_COUNT_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Load the channel data pointer */
    LpRamData = &Icu_GpChannelRamData[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* Measurement is running */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* QAC Warning: START Msg(2:3892)-13 */
    LpRamData->uiChannelMeasurementRunning = ICU_TRUE;
    /* END Msg(2:2814)-12 */
    /* END Msg(2:3892)-13 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_EnableEdgeCount */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_DisableEdgeCount
**
** Service ID            : 0x0E
**
** Description           : This API service disables the counting of edges of
**                         the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_COUNT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelRamData,
**                         Icu_GpChannelConfig.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         Det_ReportError and Icu_HW_StopCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_028,ICU_ESDD_UD_213                               */
/* Implements:  ICU124_Conf, ECUC_Icu_00124                                   */
#if (ICU_EDGE_COUNT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_103                                               */
/* Implements:  ICU206, SWS_Icu_00206, ICU079, SWS_Icu_00079                  */
/* Implements:  ICU330, SWS_Icu_00330, ICU103, SWS_Icu_00103                  */
/* Implements:  ICU331, SWS_Icu_00331, ICU173, SWS_Icu_00173                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  EAAR_PN0067_FR_0033                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeCount(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /* Defining a pointer to the Timer registers */
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  #endif
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Implements:    ICU022, SWS_Icu_00022 */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_DISABLE_EDGE_COUNT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Implements:  ICU173, SWS_Icu_00173 */
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if ((uinteger)ICU_MODE_EDGE_COUNTER
                           != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the Low Level Driver for disabling the edge count */
    Icu_HW_StopCountMeasurement(Channel, ICU_DISABLE_EDGE_COUNT_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */

    /* Load the channel data pointer */
    LpRamData = &Icu_GpChannelRamData[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */

    /* Disable measurements */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* QAC Warning: START Msg(2:3892)-13 */
    LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
    /* END Msg(2:2814)-12 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_DisableEdgeCount */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_EnableEdgeDetection
**
** Service ID            : 0x16
**
** Description           : This API service enables the counting of edges of the
**                         requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_DETECT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, Icu_HW_EnableEdgeDetection,
**                         Icu_HW_StartCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_032, ICU_ESDD_UD_214                              */
/* Implements:  ICU356_Conf, ECUC_Icu_00356, EAAR_PN0067_FR_0030              */
#if (ICU_EDGE_DETECT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_104                                               */
/* Implements:  ICU364, SWS_Icu_00364, ICU365, SWS_Icu_00365                  */
/* Implements:  ICU366, SWS_Icu_00366, ICU368, SWS_Icu_00368                  */
/* Implements:  ICU369, SWS_Icu_00369, ICU370, SWS_Icu_00370                  */
/* Implements:  ICU371, SWS_Icu_00371, ICU048                                 */
/* Implements:  ICU022, SWS_Icu_00022, ICU367, SWS_Icu_00367                  */
/* Implements:  EAAR_PN0067_FR_0026, EAAR_PN0067_FR_0030                      */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeDetection(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /* Implements:    ICU111  */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_ENABLE_EDGE_DETECTION_SID, ICU_E_UNINIT);
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
       /* Implements:   ICU048  */
       /* Check if the channel is valid */
  /* MISRA Violation: START Msg(4:0491)-1 */
  /* QAC Warning: START Msg(2:2824)-9 */
  /* Implements:  ICU_ESDD_UD_043   */
  else if ((ICU_MAX_CHANNEL_ID_CONFIGURED < Channel) ||
                      ((uinteger)ICU_MODE_SIGNAL_EDGE_DETECT
                        != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
  /* END Msg(4:0491)-1 */
  /* END Msg(2:2824)-9 */
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                          ICU_ENABLE_EDGE_DETECTION_SID, ICU_E_PARAM_CHANNEL);
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */

  else /* No DET, E_OK */
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */

  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if (ICU_HW_EXT_INTP == Icu_GpChannelConfig[Channel].uiIcuChannelType)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */
    /* END Msg(2:2824)-9 */
    {
      /* Enable the edge Detect for the channel */
      Icu_HW_EnableEdgeDetection(Channel);
    }
    else
    {
        /* Start count measurement for the channel */
        Icu_HW_StartCountMeasurement(Channel, ICU_ENABLE_EDGE_DETECTION_SID);
    } /* End of (ICU_HW_EXT_INTP ==
       * Icu_GpChannelConfig[Channel].uiIcuChannelType)
       */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Measurement is running */
    Icu_GpChannelRamData[Channel].uiChannelMeasurementRunning = ICU_TRUE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
} /* End of API Icu_EnableEdgeDetection */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* #if (ICU_EDGE_DETECT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_DisableEdgeDetection
**
** Service ID            : 0x17
**
** Description           : This API service disables the counting of edges of
**                         the requested channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_DETECT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig.
**
** Functions invoked     : Det_ReportError, Icu_HW_DisableEdgeDetection and
**                         Icu_HW_StopCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_032, ICU_ESDD_UD_215                              */
/* Implements:  ICU356_Conf, ECUC_Icu_00356, EAAR_PN0067_FR_0030              */
#if (ICU_EDGE_DETECT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_105                                               */
/* Implements:  ICU337, SWS_Icu_00337, ICU372, SWS_Icu_00372                  */
/* Implements:  ICU373, SWS_Icu_00373, ICU374, SWS_Icu_00374                  */
/* Implements:  ICU375, SWS_Icu_00375, ICU376, SWS_Icu_00376                  */
/* Implements:  ICU377, SWS_Icu_00377, ICU048                                 */
/* Implements:  ICU022, SWS_Icu_00022, SWS_Icu_00377, EAAR_PN0067_FR_0030     */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeDetection(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                 ICU_DISABLE_EDGE_DETECTION_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                          ICU_DISABLE_EDGE_DETECTION_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU376 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Edge Detection */
    if ((uinteger)ICU_MODE_SIGNAL_EDGE_DETECT
                           != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_DISABLE_EDGE_DETECTION_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }

  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Check if the channel is configured for external interrupt */
    if (ICU_HW_EXT_INTP == Icu_GpChannelConfig[Channel].uiIcuChannelType)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* END Msg(2:3892)-13 */
    {
      /* Disable the edge Detection for the channel */
      Icu_HW_DisableEdgeDetection(Channel);
    }
    else
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Start count measurement for the channel */
      Icu_HW_StopCountMeasurement(Channel, ICU_DISABLE_EDGE_DETECTION_SID);
      #endif /* ((ICU_TAUD_UNIT_USED == STD_ON) ||
              * (ICU_TAUB_UNIT_USED == STD_ON))
              */
    }

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* MISRA Violation: START Msg(4:0491)-1 */
        /* QAC Warning: START Msg(2:2824)-9 */
        /* Load the channel data pointer */
        LpRamData = &Icu_GpChannelRamData[Channel];
        /* END Msg(4:0491)-1 */
        /* END Msg(2:2824)-9 */

        /* Disable measurements */
        /* QAC Warning: START Msg(2:2814)-12 */
        /* QAC Warning: START Msg(2:3892)-13 */
        LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
        /* END Msg(2:2814)-12 */
        /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_DisableEdgeDetection */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* #if (ICU_EDGE_DETECT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_GetEdgeNumbers
**
** Service ID            : 0x0F
**
** Description           : This API service reads the number of counted edges
**                         after the last reset of edges happened.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Icu_EdgeNumberType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_EDGE_COUNT_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus, Icu_GpChannelConfig
**                         Icu_GpTimerChannelConfig, Icu_GpEdgeCountData.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         Det_ReportError and Icu_HW_GetEdgeNumbers.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_028, ICU_ESDD_UD_216                              */
/* Implements:  ICU124_Conf, ECUC_Icu_00124                                   */
#if (ICU_EDGE_COUNT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_106                                               */
/* Implements:  ICU207, SWS_Icu_00207, ICU080, SWS_Icu_00080                  */
/* Implements:  ICU332, SWS_Icu_00332, ICU104, SWS_Icu_00104                  */
/* Implements:  ICU333, SWS_Icu_00333, ICU174, SWS_Icu_00174                  */
/* Implements:  ICU175, SWS_Icu_00175, ICU022, SWS_Icu_00022                  */
/* Implements:  ICU048                                                        */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_EdgeNumberType, ICU_PUBLIC_CODE) Icu_GetEdgeNumbers
(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  Icu_EdgeNumberType LddEdgeCount;
  uint8 LucRamIndex;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
   /* QAC Warning: START Msg(2:3892)-13 */
  LddEdgeCount = ICU_EDGE_CNT_INIT_VAL;
   /* END Msg(2:3892)-13 */
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                      ICU_GET_EDGE_NUMBERS_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GET_EDGE_NUMBERS_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU174, SWS_Icu_00174 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Edge Detection */
    if ((uinteger)ICU_MODE_EDGE_COUNTER
                           != Icu_GpChannelConfig[Channel].uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_GET_EDGE_NUMBERS_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }

  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    Icu_HW_GetEdgeNumbers(Channel);
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Read the channel ram index */
    LucRamIndex = Icu_GpTimerChannelConfig[Channel].ucRamDataIndex;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_EDGECOUNT_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    LddEdgeCount = Icu_GpEdgeCountData[LucRamIndex].usIcuEdgeCount;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_EDGECOUNT_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
 /* Implements: ICU175, SWS_Icu_00175 */
  return(LddEdgeCount);

} /* End of API Icu_GetEdgeNumbers */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_StartSignalMeasurement
**
** Service ID            : 0x13
**
** Description           : This API starts the measurement of signals beginning
**                         with the configured default start edge which occurs
**                         first after the call of this service.
**
** Sync/Async            : Asynchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_SIGNAL_MEASUREMENT_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GblDriverStatus,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         Det_ReportError and Icu_HW_StartCountMeasurement.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_031, ICU_ESDD_UD_218                              */
/* Implements:  ICU242_Conf, ECUC_Icu_00242                                   */
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_107                                               */
/* Implements:  ICU208, SWS_Icu_00208, ICU334, SWS_Icu_00334                  */
/* Implements:  ICU140, SWS_Icu_00140, ICU141, SWS_Icu_00141                  */
/* Implements:  ICU146, SWS_Icu_00146, ICU142, SWS_Icu_00142                  */
/* Implements:  ICU335, SWS_Icu_00335, ICU176, SWS_Icu_00176                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022, ICU214, SWS_Icu_00214          */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU242, SWS_Icu_00242, EAAR_PN0067_FR_0031                    */
/* Implements:  ICU348, SWS_Icu_00348, ICU225_Conf, ECUC_Icu_00225            */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_StartSignalMeasurement(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                      ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU176, SWS_Icu_00176 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Signal measurement */
    if ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT
                        !=  (Icu_GpChannelConfig[Channel]).uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Start count measurement for the channel */
    Icu_HW_StartCountMeasurement(Channel, ICU_START_SIGNAL_MEASUREMENT_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation : START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Load the channel data pointer */
    LpRamData = &Icu_GpChannelRamData[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */

    /* Implements:  ICU146, SWS_Icu_00146 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /* Initialize channel status as idle */
    LpRamData->uiChannelStatus = (uinteger)ICU_IDLE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2814)-12 */
    /* END Msg(2:3892)-13 */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    /*Measurement is started */
    LpRamData->uiChannelMeasurementRunning = (uinteger)ICU_TRUE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_StartSignalMeasurement */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_StopSignalMeasurement
**
** Service ID            : 0x14
**
** Description           : This API stops the measurement of signals of the
**                         given channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_SIGNAL_MEASUREMENT_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GblDriverStatus,
**                         Icu_GpChannelRamData.
**
** Functions invoked     :  Det_ReportError and Icu_HW_StopCountMeasurement.
**
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_031, ICU_ESDD_UD_219                              */
/* Implements:  ICU242_Conf, ECUC_Icu_00242                                   */
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_108                                               */
/* Implements:  ICU209, SWS_Icu_00209, ICU336, SWS_Icu_00336                  */
/* Implements:  ICU143, SWS_Icu_00143, ICU022, SWS_Icu_00022                  */
/* Implements:  ICU144, SWS_Icu_00144, ICU145, SWS_Icu_00145                  */
/* Implements:  ICU337, SWS_Icu_00337, ICU177, SWS_Icu_00177                  */
/* Implements:  ICU048, ICU213, SWS_Icu_00213, ICU225_Conf, ECUC_Icu_00225    */
/* Implements:  ICU055, SWS_Icu_00055, ICU056, SWS_Icu_00056                  */
/* Implements:  ICU057, SWS_Icu_00057, ICU242, SWS_Icu_00242                  */
/* Implements:  EAAR_PN0067_FR_0031                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_StopSignalMeasurement(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                       ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* Implements:  ICU177, SWS_Icu_00177 */
    /* Implements:  ICU144, SWS_Icu_00144 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Signal measurement */
    if ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT
                         != (Icu_GpChannelConfig[Channel].uiIcuMeasurementMode))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Disable Timestamp capturing */
    Icu_HW_StopCountMeasurement(Channel, ICU_STOP_SIGNAL_MEASUREMENT_SID);

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* MISRA Violation: START Msg(4:0491)-1 */
        /* QAC Warning: START Msg(2:2824)-9 */
        /* Load the channel data pointer */
        LpRamData = &Icu_GpChannelRamData[Channel];
        /* END Msg(4:0491)-1 */
        /* END Msg(2:2824)-9 */

        /* Disable measurements */
        /* QAC Warning: START Msg(2:2814)-12 */
        /* QAC Warning: START Msg(2:3892)-13 */
        LpRamData->uiChannelMeasurementRunning = ICU_FALSE;
        /* END Msg(2:2814)-12 */
        /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Icu_StopSignalMeasurement */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_GetTimeElapsed
**
** Service ID            : 0x10
**
** Description           : This API service reads the elapsed signal time (Low
**                         Time, High Time or Period Time) of the requested
**                         channel as configured.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Icu_ValueType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_GET_TIME_ELAPSED_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GblDriverStatus, Icu_GpSignalMeasurementData
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, ICU_ENTER_CRITICAL_SECTION,
**                         and ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_029, ICU_ESDD_UD_217                              */
/* Implements:  ICU239_Conf, ECUC_Icu_00239                                   */
#if (ICU_GET_TIME_ELAPSED_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_109                                               */
/* Implements:  ICU210, SWS_Icu_00210, ICU338, SWS_Icu_00338                  */
/* Implements:  ICU081, SWS_Icu_00081, ICU082, SWS_Icu_00082                  */
/* Implements:  ICU083, SWS_Icu_00083, ICU136, SWS_Icu_00136                  */
/* Implements:  ICU339, SWS_Icu_00339, ICU340, SWS_Icu_00340                  */
/* Implements:  ICU105, SWS_Icu_00105, ICU341, SWS_Icu_00341                  */
/* Implements:  ICU178, SWS_Icu_00178, ICU179, SWS_Icu_00179                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022, ICU249, SWS_Icu_00249          */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU239, SWS_Icu_00239                                         */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_ValueType, ICU_PUBLIC_CODE) Icu_GetTimeElapsed(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /*
   * Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;

  /* Local pointer to the address of Signal Measure RAM data */
  P2VAR(Icu_SignalMeasureChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
  LpSignalMeasurementData;
  Icu_ValueType LddSignalTime;
  uint8 LucMeasureProperty;
  uint8 LucIndex;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif

  LddSignalTime = ICU_SIGNAL_TIME_INIT_VAL;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                      ICU_GET_TIME_ELAPSED_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_GET_TIME_ELAPSED_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Check if the measurement mode is other than Signal measurement */
    if ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT
                        != (Icu_GpChannelConfig[Channel]).uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GET_TIME_ELAPSED_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }

  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements:  ICU083, SWS_Icu_00083   */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Read timer channel configuration pointer */
    LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */

    /* QAC Warning: START Msg(2:2814)-12 */
    LucMeasureProperty = LpTimerChannelConfig->ucChannelProperties;
    /* END Msg(2:2814)-12 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_SIGNALMEASURE_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Get the index of the RAM data */
    LucIndex = LpTimerChannelConfig->ucRamDataIndex;
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    LpSignalMeasurementData = &Icu_GpSignalMeasurementData[LucIndex];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* Implements:  ICU136, SWS_Icu_00136   */
    /* Implements:  ICU081, SWS_Icu_00081   */
    /* Implements:  ICU082, SWS_Icu_00082   */
    /* Check for the status of Channel */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if ((uinteger)ICU_TRUE == Icu_GpChannelRamData[Channel].uiResultComplete)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Check if measurement mode is either low or high */
      /* QAC Warning: START Msg(2:3892)-13 */
      if(((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_HIGH_TIME_MASK) ||
          ((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_LOW_TIME_MASK))
      /* END Msg(2:3892)-13 */
      {
        /* Read the captured Signal Active Time */
        /* QAC Warning: START Msg(2:2814)-12 */
        LddSignalTime = LpSignalMeasurementData->ulSignalActiveTime;
        /* END Msg(2:2814)-12 */
        /* QAC Warning: START Msg(2:3892)-13 */
        LpSignalMeasurementData->ulSignalActiveTime = ICU_ACTIVE_TIME_RESET_VAL;
      } /* End of
       if(((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_HIGH_TIME_MASK) ||
       ((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_LOW_TIME_MASK))  */
      else /* (ICU_PERIOD_TIME == LucMeasureProperty) */
      {
        /* Implements:  ICU340  */
        /* Read the captured Signal Period Time */
        LddSignalTime = LpSignalMeasurementData->ulSignalPeriodTime;
        LpSignalMeasurementData->ulSignalPeriodTime = ICU_PERIOD_TIME_RESET_VAL;
        /* END Msg(2:3892)-13 */
      }

    } /* End of Icu_GpChannelRamData[Channel].uiResultComplete == ICU_TRUE */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    Icu_GpChannelRamData[Channel].uiResultComplete = (uinteger)ICU_FALSE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_SIGNALMEASURE_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

  /* Implements:    ICU179, SWS_Icu_00179   */
  return(LddSignalTime);

} /* End of API Icu_GetTimeElapsed */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_GET_TIME_ELAPSED_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_GetDutyCycleValues
**
** Service ID            : 0x11
**
** Description           : This API service reads the coherent high time and
**                         period time for the requested Icu channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : DutyCycleValues
**
** Return parameter      : None
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_GET_DUTY_CYCLE_VALUES_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GblDriverStatus, Icu_GpSignalMeasurementData
**                         Icu_GpChannelRamData.
**
** Functions invoked     : Det_ReportError, ICU_ENTER_CRITICAL_SECTION,
**                         and ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_030, ICU_ESDD_UD_220                              */
/* Implements:  ICU237_Conf, ECUC_Icu_00237                                   */
#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_110                                               */
/* Implements:  ICU211, SWS_Icu_00211, ICU342, SWS_Icu_00342                  */
/* Implements:  ICU084, SWS_Icu_00084, ICU137, SWS_Icu_00137                  */
/* Implements:  ICU343, SWS_Icu_00343, ICU344, SWS_Icu_00344                  */
/* Implements:  ICU106, SWS_Icu_00106, ICU345, SWS_Icu_00345                  */
/* Implements:  ICU180, SWS_Icu_00180, ICU181, SWS_Icu_00181                  */
/* Implements:  ICU048, ICU022, SWS_Icu_00022                                 */
/* Implements:  ICU213, SWS_Icu_00213, ICU055, SWS_Icu_00055                  */
/* Implements:  ICU056, SWS_Icu_00056, ICU057, SWS_Icu_00057                  */
/* Implements:  ICU237, SWS_Icu_00237                                         */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void, ICU_PUBLIC_CODE) Icu_GetDutyCycleValues(Icu_ChannelType Channel,
P2VAR(Icu_DutyCycleType,  AUTOMATIC, ICU_APPL_DATA) DutyCycleValues)
/* END Msg(2:3227)-11 */
{
  /*
   * Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;

  /* Local pointer to the address of Signal Measure RAM data */
  P2VAR(Icu_SignalMeasureChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                       LpSignalMeasurementData;
  uint8 LucIndex;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;

  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Implements:  ICU180, SWS_Icu_00180   */
    if ((uinteger)ICU_MODE_SIGNAL_MEASUREMENT
                        != (Icu_GpChannelConfig[Channel]).uiIcuMeasurementMode)
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Report Error to Det */
      (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);
      LddReturnValue = E_OK;
    }
    else
    {
      /* No action required */
    }
    /* Implements:  ICU048  */
    if (E_NOT_OK == LddReturnValue)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:2824)-9 */
      /* Read timer channel configuration pointer */
      LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
      /* END Msg(4:0491)-1 */
      /* END Msg(2:2824)-9 */
      /* Check if the channel is configured for duty cycle measurement */
      /* QAC Warning: START Msg(2:3892)-13 */
      /* QAC Warning: START Msg(2:2814)-12 */
      if (ICU_DUTY_PERIOD_ENABLED_MASK
              != (LpTimerChannelConfig->ucChannelProperties &
                                                  ICU_DUTY_PERIOD_ENABLED_MASK))
      /* END Msg(2:2814)-12 */
      /* END Msg(2:3892)-13 */
      {
        /* Report Error to Det */
        (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);
        LddReturnValue = E_OK;
      }
      else
      {
        /* No action required */
      }
    } /* End of E_NOT_OK == LddReturnValue */
    else
    {
      /* No action required */
    }
    /* Implements:  ICU181, SWS_Icu_00181   */
    /* Check if pointer passed is Null */
    if (NULL_PTR == DutyCycleValues)
    {
#if (ICU_AR_VERSION == ICU_AR_HIGHER_VERSION)
      /* Report Error to Det */
      (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                      ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_POINTER);
#elif (ICU_AR_VERSION == ICU_AR_LOWER_VERSION)
      /* Report Error to Det */
      (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                      ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_BUFFER_PTR);
#endif
      LddReturnValue = E_OK;
    } /* End of DutyCycleValues == NULL_PTR */
    else
    {
      /* No action required */
    }

  } /* End of E_NOT_OK == LddReturnValue */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    /* Read timer channel configuration pointer */
    LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* Read channel's RAM Index */
    /* QAC Warning: START Msg(2:2814)-12 */
    LucIndex = LpTimerChannelConfig->ucRamDataIndex;
    /* END Msg(2:2814)-12 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_SIGNALMEASURE_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    LpSignalMeasurementData = &Icu_GpSignalMeasurementData[LucIndex];
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    /* Implements:  ICU084, SWS_Icu_00084   */
    /* Implements:  ICU137, SWS_Icu_00137   */
    /* Implements:  ICU343, SWS_Icu_00343   */
    /* Implements:  ICU344, SWS_Icu_00344   */
    /* MISRA Violation: START Msg(7:0505)-5 */
    /* QAC Warning: START Msg(2:2814)-12 */
    /* QAC Warning: START Msg(2:3892)-13 */
    DutyCycleValues->ActiveTime = ICU_ACTIVE_TIME_RESET_VAL;
    /* END Msg(7:0505)-5 */
    /* END Msg(2:2814)-12 */
    DutyCycleValues->PeriodTime = ICU_PERIOD_TIME_RESET_VAL;
    /* END Msg(2:3892)-13 */
    /* Check for the status of Channel */
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:2824)-9 */
    if (((uinteger)ICU_TRUE == Icu_GpChannelRamData[Channel].uiResultComplete)
       && ((uinteger)ICU_TRUE ==
       Icu_GpChannelRamData[Channel+ICU_ONE].uiResultComplete))
    /* END Msg(4:0491)-1 */
    /* END Msg(2:2824)-9 */
    {
      /* Check if a valid period is finished */
      /* QAC Warning: START Msg(2:2814)-12 */
      /* QAC Warning: START Msg(2:3892)-13 */
      if (ICU_PERIOD_TIME_RESET_VAL <
          LpSignalMeasurementData->ulSignalPeriodTime)
      /* END Msg(2:2814)-12 */
      /* END Msg(2:3892)-13 */
      {
        DutyCycleValues->ActiveTime =
                               LpSignalMeasurementData->ulPrevSignalActiveTime;

        /* Read the captured Signal Period Time */
        DutyCycleValues->PeriodTime =
                               LpSignalMeasurementData->ulSignalPeriodTime;
        /* QAC Warning: START Msg(2:3892)-13 */

        LpSignalMeasurementData->ulSignalPeriodTime = ICU_PERIOD_TIME_RESET_VAL;
        /* END Msg(2:3892)-13 */
      } /* End of LpSignalMeasurementData->ulSignalPeriodTime
           > ICU_PERIOD_TIME_RESET_VAL */
      else
      {
        /* No action required */
      }
    } /* End of checking for the status of Channel */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3892)-13 */
    Icu_GpChannelRamData[Channel].uiResultComplete = (uinteger)ICU_FALSE;
    Icu_GpChannelRamData[Channel+ICU_ONE].uiResultComplete =
                                                     (uinteger)ICU_FALSE;
    /* END Msg(4:0491)-1 */
    /* END Msg(2:3892)-13 */

  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_SIGNALMEASURE_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  } /* End of E_NOT_OK == LddReturnValue */

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Icu_GetDutyCycleValues */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) */
/*******************************************************************************
** Function Name         : Icu_GetInputLevel
**
** Service ID            : 0x18
**
** Description           : This API service returns the state of the input pin
**                         related to the ICU channel
**
** Sync/Async            : NA
**
** Reentrancy            : NA
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Icu_LevelType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_GET_INPUT_LEVEL_API must be STD_ON
**
** Global Variables      : Icu_GblDriverStatus.
**
** Functions invoked     : Det_ReportError, Icu_HW_GetInputLevel.
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_135                                               */
/* Implements:  EAAR_PN0067_FR_0051                                           */
#if (ICU_GET_INPUT_LEVEL_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_136                                               */
/* Implements:  EAAR_PN0067_FR_0051                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_LevelType, ICU_PUBLIC_CODE) Icu_GetInputLevel(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  /*Local variable to store the return level value  */
  Icu_LevelType LenInputLevel;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif

  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  LenInputLevel = ICU_LOW;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                      ICU_GET_INPUT_LEVEL_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Check if the channel is valid */
  /* Implements:  ICU_ESDD_UD_043   */
  if (ICU_MAX_CHANNEL_ID_CONFIGURED < Channel)
  {
    /* Report Error to Det */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GET_INPUT_LEVEL_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048 */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    LenInputLevel = Icu_HW_GetInputLevel(Channel);
  } /* End of E_NOT_OK == LddReturnValue */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  return(LenInputLevel);

} /* End of API Icu_GetInputlevel */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_GET_INPUT_LEVEL_API == STD_ON) */
/*******************************************************************************
** Function Name         : Icu_GetTAUInCountValue
**
** Service ID            : 0x19
**
** Description           : This service reads the TAU Counter value of the
**                         particular channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : LddTAUInCounterValue
**
** Return parameter      : Icu_CounterValueType
**
** Preconditions         : The Icu Driver must be initialized,
**                         ICU_GET_TAU_COUNT_VALUE_API must be STD_ON
**
** Global Variables      : Icu_GpChannelConfig
**
** Functions invoked     : Det_ReportError, Icu_HW_GetTAUInCountValue
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_143                                               */
#if (ICU_GET_TAU_COUNT_VALUE_API == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_142                                               */
/* Implements:  EAAR_PN0067_FR_0062                                           */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Icu_CounterValueType, ICU_PUBLIC_CODE) Icu_GetTAUInCountValue
(Icu_ChannelType Channel)
/* END Msg(2:3227)-11 */
{
  Icu_CounterValueType LddTAUInCounterValue;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Initialize LpChannelConfig  */
  LpChannelConfig = Icu_GpChannelConfig;
  /* Initialize the return value */
  LddTAUInCounterValue = ICU_TAUJ_CDR_RESET_VAL;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_GET_COUNT_VALUE_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  }
  /* QAC Warning: START Msg(2:3892)-13 */
  /* QAC Warning: START Msg(2:2814)-12 */
  /* Implements:  ICU_ESDD_UD_043   */
  else if ((ICU_MAX_CHANNEL_ID_CONFIGURED < Channel) ||
          (ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType))
  /* END Msg(2:3892)-13 */
  /* END Msg(2:2814)-12 */
  {
    /* Report Error to Det */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GET_COUNT_VALUE_SID, ICU_E_PARAM_CHANNEL);
    LddReturnValue = E_OK;
  } /* End of Channel > ICU_MAX_CHANNEL_ID_CONFIGURED */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif
  {
    LddTAUInCounterValue = Icu_HW_GetTAUInCountValue(Channel);
  } /* End of E_NOT_OK == LddReturnValue */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  return(LddTAUInCounterValue);
} /* End of API Icu_GetTAUInCountValue */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif
/*******************************************************************************
** Function Name        : Icu_SynchronousInit
**
** Service ID           : 0x1A
**
** Description          : This API performs the initialization of ICU channels
**                        configured to support synchronous start/stop of
**                        timers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.ICU Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GblDriverStatus and Icu_GblSyncInitStatus
**
** Functions invoked    : Det_ReportError and Icu_HW_SynchronousInit
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_149                                               */
/* Implements:  EAAR_PN0067_FR_0108                                           */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_150                                               */
/* Implements:  EAAR_PN0067_FR_0061                                           */
FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousInit(void)
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module is not initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_SYNCHRONOUS_INIT_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  }
  else
  {
    /* No action required */
  }

  #if (ICU_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Implements:  ICU_ESDD_UD_177,ICU_ESDD_UD_134 */
  /* Check if the ICU Driver is already initialized */
  if (ICU_INITIALIZED == Icu_GblSyncInitStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                      ICU_SYNCHRONOUS_INIT_SID, ICU_E_ALREADY_INITIALIZED);
    LddReturnValue = E_OK;
  } /* End of Icu_GblSyncInitStatus == ICU_INITIALIZED */
  else
  {
    /* No action required */
  }
  #endif /* End of (ICU_ALREADY_INIT_DET_CHECK == STD_ON) */
  /* Implements:    ICU048  */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Initialize all ICU channels configured to support synchronous start/stop
     * of timers, this excludes initialization of channels that will be
     * handled by complex drivers
     */
    Icu_HW_SynchronousInit();
    #if (ICU_DEV_ERROR_DETECT == STD_ON)
    Icu_GblSyncInitStatus = ICU_INITIALIZED;
    #endif
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Icu_SynchronousInit */
#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_SynchronousStart
**
** Service ID           : 0x1B
**
** Description          : This API starts ICU channels configured to support
**                        synchronous start/stop of timers.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.APIs Icu_Init and Icu_SynchronousInit should be
**                          invoked.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GblDriverStatus, Icu_GblSyncInitStatus
**                        and Icu_GblSyncStartStatus.
**
** Functions invoked    : Det_ReportError and Icu_HW_SynchronousStart
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_149                                               */
/* Implements:  EAAR_PN0067_FR_0108                                           */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_144                                               */
/* Implements:  EAAR_PN0067_FR_0061                                           */
FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousStart(void)
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;

  /* Check if the Icu Module or synchronous capture is not initialized */
  if ((ICU_INITIALIZED != Icu_GblDriverStatus) ||
                                   (ICU_INITIALIZED != Icu_GblSyncInitStatus))
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_SYNCHRONOUS_START_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of Icu_GblDriverStatus != ICU_INITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check if the ICU SynchronousStart is already initialized */
  if (ICU_SYNC_STARTED  ==  Icu_GblSyncStartStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                   ICU_SYNCHRONOUS_START_SID, ICU_E_SYNC_ALREADY_STARTED);
    LddReturnValue = E_OK;
  } /* End of Icu_GblSyncInitStatus == ICU_SYNC_STARTED */
  else
  {
    /* No action required */
  }

  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Start all ICU channels configured to support synchronous start/stop
     * of timers, this excludes starting of channels that will be
     * handled by complex drivers
     */
    Icu_HW_SynchronousStart();
    #if (ICU_DEV_ERROR_DETECT == STD_ON)
    Icu_GblSyncStartStatus = ICU_SYNC_STARTED;
    #endif
  } /* End of LddReturnValue == E_NOT_OK */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Icu_SynchronousStart */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_SynchronousStop
**
** Service ID           : 0x1C
**
** Description          : This API stops ICU channels configured to support
**                        synchronous start/stop of timers.
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
** Preconditions        : 1.APIs Icu_Init should be invoked.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GblDriverStatus, Icu_GblSyncInitStatus
**                        and Icu_GblSyncStartStatus.
**
** Functions invoked    : Det_ReportError and Icu_HW_SynchronousStop.
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_149                                               */
/* Implements:  EAAR_PN0067_FR_0108                                           */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_145                                               */
/* Implements:  EAAR_PN0067_FR_0061                                           */
FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousStop(void)
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  /* Set the DET return value */
  LddReturnValue = E_NOT_OK;
  /* Implements:    ICU022, SWS_Icu_00022   */
  /* Check if the Icu Module or synchronous capture is not initialized */
  if ((ICU_INITIALIZED != Icu_GblDriverStatus) ||
                                   (Icu_GblSyncInitStatus != ICU_INITIALIZED))
  {
    /* Report Error to Det */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_SYNCHRONOUS_STOP_SID, ICU_E_UNINIT);
    LddReturnValue = E_OK;
  } /* End of ICU_INITIALIZED != Icu_GblDriverStatus */
  else
  {
    /* No action required */
  }
  /* Implements:    ICU048  */
  /* Check if any DET was reported */
  if (E_NOT_OK == LddReturnValue)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Stop all ICU channels configured to support synchronous start/stop
     * of timers, this excludes stopping of channels that will be
     * handled by complex drivers
     */
    Icu_HW_SynchronousStop();
    #if (ICU_DEV_ERROR_DETECT == STD_ON)
    Icu_GblSyncStartStatus = ICU_SYNC_NOTSTARTED;
    #endif
  } /* End of LddReturnValue == E_NOT_OK */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Icu_SynchronousStop */
#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_SynchronousDeInit
**
** Service ID           : 0x1D
**
** Description          : This API performs the De-initialization of ICU
**                        channels configured to support synchronous start/stop
**                        of timers.
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
** Preconditions        : 1.ICU Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GblDriverStatus and Icu_GblSyncInitStatus
**
** Functions invoked    : Det_ReportError and Icu_HW_SynchronousDeInit
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_149                                               */
/* Implements:  EAAR_PN0067_FR_0108                                           */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_151                                               */
/* Implements:  EAAR_PN0067_FR_0061                                           */
FUNC(void, ICU_PUBLIC_CODE) Icu_SynchronousDeInit(void)
{
  /* Check if the Icu Module or synchronous capture is initialized or not */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  if ((ICU_INITIALIZED == Icu_GblDriverStatus) &&
                                   (ICU_INITIALIZED == Icu_GblSyncInitStatus))
  #endif
  {
    /* Initialize all ICU channels configured to support synchronous start/stop
     * of timers, this excludes initialization of channels that will be
     * handled by complex drivers
     */
    Icu_HW_SynchronousDeInit();
    #if (ICU_DEV_ERROR_DETECT == STD_ON)
    Icu_GblSyncInitStatus = ICU_UNINITIALIZED;
    #endif
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Report to DET */
    (void)Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_SYNCHRONOUS_DEINIT_SID, ICU_E_UNINIT);
  }
  #endif
} /* End of API Icu_SynchronousDeInit */

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name      : Icu_GetVersionInfo
**
** Service ID         : 0x12
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
** Function(s) invoked: Det_ReportError()
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_020                                               */
/* Implements:  ICU240_Conf, ECUC_Icu_00240                                   */
#if (ICU_GET_VERSION_INFO_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_160, SWS_Icu_00131, ICU131                        */
/* Implements:  ICU050, SWS_Icu_00050, ICU346, SWS_Icu_00346                  */
/* Implements:  ICU347, SWS_Icu_00347, ICU212, SWS_Icu_00212                  */
/* Implements:  ICU356, SWS_Icu_00356, ICU183, ICU094, EAAR_PN0034_FR_0092    */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(void,ICU_PUBLIC_CODE) Icu_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_CONST) versioninfo)
/* END Msg(2:3227)-11 */
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
 /* Report to DET, if versioninfo pointer is equal to Null */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_GET_VERSION_INFO_SID,ICU_E_PARAM_VINFO);
  }
  else
  #endif /*#if(ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    /* QAC Warning: START Msg(2:2814)-12 */
    versioninfo->vendorID = (uint16)ICU_VENDOR_ID;
    /* END Msg(2:2814)-12 */
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)ICU_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = ICU_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = ICU_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = ICU_SW_PATCH_VERSION;
  }
}
#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */
#endif  /*(ICU_GET_VERSION_INFO_API == STD_ON)*/
/*******************************************************************************
** Function Name        : Icu_CheckHWConsistency
**
** Service ID           : 0x1E
**
** Description          :  This API which compares the control register values
**                         with the RAM mirror/ROM as part of the hardware
**                         consistency check
**
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
** Return parameter     : LddReturnValue
**
** Preconditions        : 1.ICU Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option ICU_TAUDB_RAM_MIRROR or ICU_TAUJ_RAM_MIRROR
**                          or ICU_FCLA_RAM_MIRROR is STD_ON.
**
** Global Variables     : Icu_GblDriverStatus(R)
**
** Functions invoked    : Det_ReportError, Icu_HWCheckConsistency
**
** Registers Used       : None
**
*******************************************************************************/
#if ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
      (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ) )

#define ICU_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-10 */

/* Implements:  ICU_ESDD_UD_166                                               */
/* Implements:  EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006                    */
/* Implements:  EAAR_PN0034_FSR_0007                                          */
/* QAC Warning: START Msg(2:3227)-11 */
FUNC(Std_ReturnType, ICU_PUBLIC_CODE) Icu_CheckHWConsistency
                                   (Icu_HWConsistencyModeType HWConsistencyMode)
/* END Msg(2:3227)-11 */
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  LddReturnValue = E_OK;
  /* Det Check if ICU Driver is initialized */
  if (ICU_INITIALIZED != Icu_GblDriverStatus)
  {
    /* Report to DET module */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_CHECK_HW_CONSISTENCY_SID, ICU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* Det Check if Icu_CheckHWConsistency is called with invalid arguments */
  else if ((ICU_STATIC != HWConsistencyMode) &&
                                             (ICU_DYNAMIC != HWConsistencyMode))
  {
    /* Report to DET module */
    (void)Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                     ICU_CHECK_HW_CONSISTENCY_SID, ICU_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_OK == LddReturnValue)
  #endif  /* End of #if (ICU_DEV_ERROR_DETECT == STD_ON)*/
  {
    LddReturnValue = Icu_HWCheckConsistency(HWConsistencyMode);
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  return(LddReturnValue);
}

#define ICU_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-10 */
/* QAC Warning: START Msg(2:0862)-17 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0862)-17 */
/* END Msg(2:0832)-10 */

#endif /* End of ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
                    (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
                    (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ))*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
