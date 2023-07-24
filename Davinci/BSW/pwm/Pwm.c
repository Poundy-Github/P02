/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of PWM Driver              */
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
 * V1.0.0:  10-Sep-2015 : Initial Version.
 * V1.0.1:  11-Jan-2016 : As part of F1K V4.00.01 development activity,
 *                        following changes are made,
 *                        1. As part of JIRA #ARDAAGA-70, updated
 *                           Pwm_SetPeriodAndDuty for DET check of
 *                           diagnostic channels.
 *                        2. As part of JIRA #ARDAAGA-70,Pwm_GetVersionInfo
 *                           is added.
 * V2.0.0:  01-Nov-2016 : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                           ASR 4.0.3.
 *                        2. JIRA #ARDAABD-926 - Since Config Data is
 *                           allocated in ROM, Config Data might not be allowed
 *                           to have variables whose Storage Specifier
 *                           is AUTOMATIC.
 * V3.0.0:  23-Nov-2016 : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                           for ASIL-B.
 * V3.0.1:  08-Dec-2016 : JIRA ARDAABD-479 - DET error code PWM_E_INIT_FAILED
 *                        added for AR4.2.2
 * V3.0.2:  22-Dec-2016 : JIRA ARDAABD-565 -   Acceptance points implemented:
 *                        1. Use PWM_E_PARAM_VALUE Det code in
 *                        Pwm_CheckHWConsistency function
 *                        JIRA ARDAABD-804:
 *                        1. SID for Pwm_CheckHWConsistency changed accordingly
 *                        to BSWMDT
 * V3.0.3:  06-Jan-2017 : JIRA ARDAABD-877 - Acceptance points implemented
 * V3.0.4 : 17-Mar-2017 : Update for ARDAABD-827 Traceability ticket
 *                        1. Add General Traceability Section
 *                        2. Replace  "TRACE" reference with "Implements" word
 *                        3. Add 4.2.2 requirement for APIs
 * V3.1.0 : 10-Jul-2017 : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made :
 *                        1. Pwm_ControlTriggerOutput API is added.
 *                        2. Global variables Pwm_GulGroup0, Pwm_GulGroup1 and
 *                           Pwm_GulGroup2 are added.
 *                        3. Handled QAC warnings.
 *                        4. SW minor version updated.
 * V3.1.1 : 25-Sep-2017 : Following changes are made:
 *                        1. As part of ARDAABD-2476,
 *                           a. Naming of Local variables is corrected
 *                              throughout as per requirement MCAL052.
 *                        2. As part of ARDAABD-2425,
 *                           a. Handled QAC level 2 warnings.
 * V3.1.2 : 18-Jun-2018 : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3454
 *                           a. Added DET checking in Pwm_SetOutputToIdle API
 *                              to prevent calling this API for sync enabled
 *                              channels.
 *                              Ref: ARDAABD-1617.
 *                           b. Updated Copyright information.
 *                        2. As per JIRA ticket ARDAABD-1926, DET check for
 *                           invalid period is implemented in
 *                           Pwm_SetPeriodAndDuty API for TAUDB units.
 *                        3. Misra violations are justified.
 *                        4. As per JIRA ticket ARDAABD-1627, pre-compile
 *                           switch PWM_SELB_INTC2_SUPPORT is added in Pwm_Init.
 *                        5. As per JIRA ticket ARDAABD-2929, pre-compile
 *                           switches are added for Pwm_CheckDetErrors API.
 *                        6. As per JIRA ticket ARDAABD-3825, the status of PWM
 *                           driver is set at the beginning of Pwm_DeInit API.
 *                        7. As per JIRA ticket ARDAABD-3839, added traceability
 *                           tags for reqtify coverage improvement.
 * V3.1.3: 8-Aug-2018 : As part of ARDAABD-3707, Following changes are made:
 *                        1.Add RH850_DUMMY_READ_SYNCP(16, ICP0) to fix the
 *                          fault synchronization at the timing when control
 *                          shifts from MCAL to application
 *                        2. Misra warning Tag for Message Msg(4:0303)
 *                           has been added.
 * V3.1.4: 9-Aug-2018 : As part of ARDAABD-3938, Following changes are made:
 *                        1.Add critical section protection before and after the
 *                          Pwm_HW_CheckHWConsistency() function
 * V3.1.5: 05-Oct-2018 : Following changes are done : 
 *                        1. As part of ARDAABD-3707, ICP0 usage error
 *                           modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to
 *                           RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 * V3.1.6: 06-Oct-2019 : As part of ARDAABD-3707, Following changes are made:
 *                       1.Remove the RH850_DUMMY_READ_SYNCP Marco
 *                       2.Corrected the format issue.did not update version.
 */
/******************************************************************************/
/* Implements:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045,EAAR_PN0034_NR_0018  */
/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements:  PWM075a, PWM075b, PWM075c, PWM075f, PWM148, PWM149            */
/* Implements:  SWS_Pwm_10075, SWS_Pwm_40075, SWS_Pwm_60075                   */

/* Implements:  PWM_ESDD_UD_177, PWM_ESDD_UD_026                              */
/* Implements:  PWM_ESDD_UD_163                                               */
/* Implements:  EAAR_PN0066_FR_0001, EAAR_PN0066_FR_0009                      */
/* Implements:  EAAR_PN0066_FR_0071, EAAR_PN0066_FR_0002, EAAR_PN0066_FR_0003 */
/* Implements:  EAAR_PN0034_FSR_0006, EAAR_PN0034_FSR_0007                    */

/* Implements:  PWM_ESDD_UD_003, PWM_ESDD_UD_004                              */
/* Implements:  PWM_ESDD_UD_039, PWM_ESDD_UD_040                              */
/* Implements:  PWM089, EAAR_PN0066_FR_0018                                   */
/* Implements:  SWS_Pwm_00089                                                 */

/* Implements:  EAAR_PN0034_NR_0007, EAAR_PN0034_FR_0052, EAAR_PN0034_NR_0001 */
/* Implements:  EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0023 */
/* Implements:  EAAR_PN0034_NR_0020, EAAR_PN0034_NR_0012                      */
/* Implements:  EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0065 */
/* Implements:  EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0069                      */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information and other types declarations */
/* Implements:  PWM075e                                                       */
/* Implements:  SWS_Pwm_50075                                                 */
#include "Pwm.h"
/* Included for Header file inclusion */
#include "Pwm_LLDriver.h"
/* Included for RAM variable declarations */
#include "Pwm_Ram.h"
#include "Iocommon_Defines.h"
/* Implements:  PWM_ESDD_UD_043, PWM131_Conf, ECUC_Pwm_00131                  */
/* Implements:  PWM079, SWS_Pwm_00079                                         */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
/* Implements:  PWM078, EAAR_PN0034_FR_0064, PWM104, SWS_Pwm_00104            */
/* Implements:  PWM003a, PWM003b, PWM051a, SWS_Pwm_10051                      */
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

#define PWM_START_SEC_PRIVATE_CODE
/* Implements:  EAAR_PN0034_NR_0087                                           */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* Implements:  PWM079, SWS_Pwm_00079                                         */
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_DUTY_CYCLE_API == STD_ON) ||\
(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON)\
||(PWM_GET_OUTPUT_STATE_API == STD_ON)||(PWM_SELECT_CHANNEL_CLK_API == STD_ON)\
||(PWM_SET_TRIGGER_DELAY_API == STD_ON)||(PWM_SET_CHANNEL_OUTPUT_API == STD_ON)\
||((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&(PWM_DIAG_UNIT_USED == STD_ON))\
||(PWM_NOTIFICATION_SUPPORTED == STD_ON)))
STATIC FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_CheckDetErrors
(Pwm_ChannelType ChannelNumber, uint8 Api_SID);
#endif

#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* Implements:  SWS_Pwm_50075                                                 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* Implements:  PWM075e                                                       */
#include "MemMap.h"
#endif
#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Pwm.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
/* AUTOSAR release version information */
#define PWM_C_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_C_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_C_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION_VALUE

#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_C_AR_RELEASE_MAJOR_VERSION    PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_C_AR_RELEASE_MINOR_VERSION    PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_C_AR_RELEASE_REVISION_VERSION  PWM_AR_RELEASE_REVISION_VERSION_VALUE
#endif

/* Module software version information */
#define PWM_C_SW_MAJOR_VERSION    1
#define PWM_C_SW_MINOR_VERSION    1

/* Implements:  EAAR_PN0034_FR_0055                                           */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_AR_RELEASE_MAJOR_VERSION != PWM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Pwm.c : Mismatch in Release Major Version"
#endif

#if (PWM_AR_RELEASE_MINOR_VERSION != PWM_C_AR_RELEASE_MINOR_VERSION)
  #error "Pwm.c : Mismatch in Release Minor Version"
#endif

#if (PWM_AR_RELEASE_REVISION_VERSION != PWM_C_AR_RELEASE_REVISION_VERSION)
  #error "Pwm.c : Mismatch in Release Patch Version"
#endif

#if (PWM_SW_MAJOR_VERSION != PWM_C_SW_MAJOR_VERSION)
  #error "Pwm.c : Mismatch in Software Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_C_SW_MINOR_VERSION)
  #error "Pwm.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/* Implements:  EAAR_PN0034_NR_0026                                           */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 10.5                                          */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex        */
/*                 bitwise operations.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-1 and                           */
/*                 END Msg(4:4397)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To access channel parameters in an optimized approach.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-2 and                           */
/*                 END Msg(4:0488)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317) [I] Implicit conversion from a pointer to void to */
/*                 a pointer to object type.                                  */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-3 and                           */
/*                 END Msg(4:0317)-3 tags in the code.                        */

/******************************************************************************/

/*4. MISRA C RULE VIOLATION:                                                  */
/*Message       : (4:2985) This operation is redundant. The value of the      */
/*                result is always that of the left-hand operand.             */
/*Rule          : MISRA-C:2004 Rule 21.1                                      */
/*Justification : The value of the local variable accessed changes with       */
/*                configuration.                                              */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:2985)-4 and END Msg(4:2985)-4 tags     */
/*                in the code.                                                */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:2992) The value of this 'if' controlling expression  */
/*                 is always 'false'.                                         */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value this operation is always 'false' for this        */
/*                 hardware unit, changes according to the hardware unit used */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2992)-5 and                           */
/*                 END Msg(4:2992)-5 tags in the code.                        */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of the local variable changes with configuration */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-6 and                           */
/*                 END Msg(4:2996)-6 tags in the code.                        */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) Assignment is redundant. The value of this object */
/*                 is never used before being modified.                       */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The object is used under different pre-compile sections.   */
/*                 However, for different configurations this warning ceases  */
/*                 to exist.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-7 and                           */
/*                 END Msg(4:2982)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : The code can be accessed if the logical conditional check  */
/*                 in which this is found is true. Code may or may not be     */
/*                 accessible depending on the pre compile value used in the  */
/*                 logical condition.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-8 and                           */
/*                 END Msg(4:2880)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-9 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:2824)-1 and               */
/*                 END Msg(2:2824)-1  tags in the code.                       */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR  and vendor             */
/*                 specific Api's cannot be modified to be made as constant.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3227)-2 and               */
/*                 END Msg(2:3227)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Rule          : NA                                                         */
/* Justification : The result of this cast is implicitly converted            */
/*                 to another type.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-3 and              */
/*                 END Msg(2:3892)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning  START Msg(2:2814)-4 and              */
/*                 END Msg(2:2814)-4 tags in the code.                        */
/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-5 and               */
/*                 END Msg(2:0862)-5 tags in the code.                        */
/******************************************************************************/
/* 6. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter is not used in this function.       */
/* Rule          : NA                                                         */
/* Justification : The parameter is used in this function when                */
/*                 PWM_TAUD_UNIT_USED or PWM_TAUB_UNIT_USED                   */
/*                 switches are enabled.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-6 and                           */
/*                 END Msg(2:3206)-6 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Pwm_Init
**
** Service ID           : 0x00
**
** Description          : This API performs the initialization of PWM Driver
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
** Global Variables     : Pwm_GblDriverStatus, Pwm_GpTAUDBUnitConfig,
**                        Pwm_GpTAUJUnitConfig, Pwm_GpChannelConfig,
**                        Pwm_GpDiagUnitConfig, Pwm_GpDiagChannelConfig,
**                        Pwm_GusIntSelRegMask, Pwm_GulGroup0, Pwm_GulGroup1
**                        Pwm_GulGroup2
**
** Functions invoked    : Det_ReportError and Pwm_HW_Init
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_101, EAAR_PN0034_FR_0063, EAAR_PN0034_FR_0049     */
/* Implements:  PWM095, PWM007, PWM062, PWM009a, PWM051b                      */
/* Implements:  PWM009b, PWM009c, PWM052, PWM116, PWM121, SWS_Pwm_20051       */
/* Implements:  SWS_Pwm_00095, SWS_Pwm_00007, SWS_Pwm_00062, SWS_Pwm_10009    */
/* Implements:  SWS_Pwm_20009, SWS_Pwm_30009, SWS_Pwm_00052                   */
/* Implements:  SWS_Pwm_00116, SWS_Pwm_00121, PWM093, PWM120b, SWS_Pwm_20120  */
/* Implements:  SWS_Pwm_00093, PWM120a, SWS_Pwm_10120, PWM088, SWS_Pwm_00088  */
/* Implements:  EAAR_PN0066_FR_0007, EAAR_PN0066_FR_0064, EAAR_PN0034_FR_0025 */
#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_Init
(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM094, SWS_Pwm_00094, PWM064              */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;

  /* Implements:  PWM_ESDD_UD_144, PWM_ESDD_UD_146, PWM118, SWS_Pwm_00118     */
  #if (PWM_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the PWM Driver is already initialized */
  if (PWM_INITIALIZED == Pwm_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                       PWM_INIT_SID, PWM_E_ALREADY_INITIALIZED);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /* Check if ConfigPtr is NULL_PTR */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET module */
    #if (PWM_AR_VERSION == PWM_AR_HIGHER_VERSION)
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                              PWM_INIT_SID, PWM_E_INIT_FAILED);
    #elif (PWM_AR_VERSION == PWM_AR_LOWER_VERSION)
    /* Implements: PWM046                                                     */
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                              PWM_INIT_SID, PWM_E_PARAM_CONFIG);
    #endif
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_OK == LddReturnValue)
  #endif
  {
    /* Check if the database is present */
    if (PWM_DBTOC_VALUE == ConfigPtr->ulStartOfDbToc)
    {
      /* Implements:  PWM_ESDD_UD_183                                         */
      #if (PWM_TAU_UNIT_USED  == STD_ON)

      /* Implements:  PWM_ESDD_UD_053, PWM_ESDD_UD_054, PWM_ESDD_UD_136       */
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
      /* MISRA Violation: START Msg(4:0317)-3 */
      /* Save the start of TAUD/TAUB Unit Configuration in the global pointer */
      Pwm_GpTAUDBUnitConfig = ConfigPtr->pTAUDBUnitConfig;
      /* END Msg(4:0317)-3 */
      #endif

      /* Implements:  PWM_ESDD_UD_055, PWM_ESDD_UD_136                        */
      #if (PWM_TAUJ_UNIT_USED == STD_ON)
      /* MISRA Violation: START Msg(4:0317)-3 */
      /* Save the start of TAUJ Unit Configuration in the global pointer */
      Pwm_GpTAUJUnitConfig = ConfigPtr->pTAUJUnitConfig;
      #endif

      /* Implements: PWM_ESDD_UD_136                                          */
      /* Save the start of channel Configuration in the global pointer */
      Pwm_GpChannelConfig = ConfigPtr->pChannelConfig;
      /* END Msg(4:0317)-3 */
      #endif

      #if (PWM_DIAG_UNIT_USED  == STD_ON)
      /* Implements: PWM_ESDD_UD_136                                          */
      /* MISRA Violation: START Msg(4:0317)-3 */
      /* Save the start of PWGA Unit Configuration in global pointer */
      Pwm_GpDiagUnitConfig = ConfigPtr->pDiagUnitConfig;

      /* Save the start of PWGA channel Configuration in global pointer */
      Pwm_GpDiagChannelConfig = ConfigPtr->pDiagChannelConfig;
      /* END Msg(4:0317)-3 */
      #endif

      #if (PWM_DIAG_UNIT_USED == STD_ON)
      /* MISRA Violation: START Msg(4:0317)-3 */
      #if (PWM_SELB_INTC2_SUPPORT == STD_ON)
      /* Save mask value of interrupt select register 2 in global variable */
      Pwm_GusIntSelRegMask = ConfigPtr->usIntSelRegMask;
      #endif

      /* Implements:  PWM_ESDD_UD_222                                         */
      #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
      /* Save mask value of channels in each group in global variable */
      Pwm_GulGroup0 = ConfigPtr->ulGroup0;
      Pwm_GulGroup1 = ConfigPtr->ulGroup1;
      Pwm_GulGroup2 = ConfigPtr->ulGroup2;
      #endif
      /* END Msg(4:0317)-3 */
      #endif

      /* Initialize all PWM channels */
      Pwm_HW_Init();

      #if (PWM_DEV_ERROR_DETECT == STD_ON)
      /* Set PWM Driver status to initialized */
      Pwm_GblDriverStatus = PWM_INITIALIZED;
      #endif
    }
    /* If there is no valid database present */
    else
    {
      /* Implements:  PWM_ESDD_UD_043, EAAR_PN0034_FR_0016                    */
      #if (PWM_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID,
                                                        PWM_E_INVALID_DATABASE);
      #endif
    }
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Pwm_DeInit
**
** Service ID           : 0x01
**
** Description          : This service performs de-initialization of the PWM
**                        Driver component.
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
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_DE_INIT_API is STD_ON.
**
** Global Variables     : Pwm_GblDriverStatus, Pwm_GblSyncInitStatus
**                        Pwm_GblSyncStartStatus
**
** Functions invoked    : Det_ReportError and Pwm_HW_DeInit
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_102, SWS_Pwm_00088, PWM051b, SWS_Pwm_20051        */
/* Implements:  PWM096, PWM010, PWM011, PWM012, PWM080a, PWM080b, PWM088      */
/* Implements:  SWS_Pwm_00096, SWS_Pwm_00010, SWS_Pwm_00011, SWS_Pwm_00012    */
/* Implements:  SWS_Pwm_10080, SWS_Pwm_20080, EAAR_PN0034_FR_0049             */
/* Implements:  PWM_ESDD_UD_045                                               */
/* Implements:  PWM141_Conf, ECUC_Pwm_00141, EAAR_PN0034_FR_0058              */
#if (PWM_DE_INIT_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PUBLIC_CODE) Pwm_DeInit(void)
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Check if PWM Driver is initialized */
  if (PWM_INITIALIZED != Pwm_GblDriverStatus)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DEINIT_SID,
                                                      PWM_E_UNINIT);
  }
  else
  #endif
  {
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Set PWM Driver status to uninitialized */
    Pwm_GblDriverStatus = PWM_UNINITIALIZED;

    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set PWM Driver synchronous initialization status to uninitialized */
    Pwm_GblSyncInitStatus = PWM_UNINITIALIZED;
    #endif
    #endif
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set PWM Driver synchronous start status to not started */
    Pwm_GblSyncStartStatus = PWM_SYNC_NOTSTARTED;
    #endif

    /* De-Initialize all PWM channels */
    Pwm_HW_DeInit();
  }

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SetDutyCycle
**
** Service ID           : 0x02
**
** Description          : This API is used to set the required Duty cycle for a
**                        PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber and DutyCycle.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_DUTY_CYCLE_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Det_ReportError, Pwm_HW_SetDutyCycle and
**                        Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_103, PWM_ESDD_UD_030, EAAR_PN0066_FR_0056         */
/* Implements:  PWM097, PWM013, PWM014, PWM016, PWM017, PWM018                */
/* Implements:  PWM082a, PWM082b, PWM086b, PWM088, SWS_Pwm_00088, PWM119      */
/* Implements:  SWS_Pwm_00097, SWS_Pwm_00013, SWS_Pwm_00014, SWS_Pwm_00016    */
/* Implements:  SWS_Pwm_00017, SWS_Pwm_00018, SWS_Pwm_10082                   */
/* Implements:  SWS_Pwm_20082, EAAR_PN0034_FR_0049, SWS_Pwm_20086             */
/* Implements:  PWM_ESDD_UD_046                                               */
/* Implements:  PWM128_Conf, ECUC_Pwm_00128, EAAR_PN0066_FR_0070              */
/* Implements:  SWS_Pwm_00119, PWM051b, SWS_Pwm_20051                         */
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SetDutyCycle
(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber, PWM_SET_DUTYCYCLE_SID);

  /* Check for valid Duty range */
  if (DutyCycle > MAX_DUTY_CYCLE)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                     PWM_SET_DUTYCYCLE_SID, PWM_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Set the Duty cycle for the required channel */
    Pwm_HW_SetDutyCycle(ChannelNumber, DutyCycle);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SetPeriodAndDuty
**
** Service ID           : 0x03
**
** Description          : This API is used to set the required Period and Duty
**                        cycle for a PWM channel. This API does not support
**                        PWGA channels.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber, Period and DutyCycle.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_PERIOD_AND_DUTY_API is STD_ON.
**
** Global Variables     : Pwm_GpChannelConfig
**
** Functions invoked    : Det_ReportError, Pwm_HW_SetPeriodAndDuty
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  SWS_Pwm_00150                                                 */
/* Implements:  PWM098, PWM019, PWM076, PWM020, PWM041, PWM083a, PWM083b      */
/* Implements:  PWM086a, PWM150, PWM051b, PWM006a, SWS_Pwm_10086              */
/* Implements:  SWS_Pwm_00098, SWS_Pwm_00019, SWS_Pwm_00076, SWS_Pwm_00020    */
/* Implements:  SWS_Pwm_00041, SWS_Pwm_10083, SWS_Pwm_20083, PWM124_Conf      */
/* Implements:  EAAR_PN0066_FR_0054, PWM051b, SWS_Pwm_20051                   */
/* Implements:  PWM_ESDD_UD_047, EAAR_PN0034_FR_0049, ECUC_Pwm_00124          */
/* Implements:  PWM130_Conf, ECUC_Pwm_00130, PWM088, SWS_Pwm_00088            */
/* Implements:  PWM_ESDD_UD_029, PWM_ESDD_UD_087, PWM_ESDD_UD_104             */
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SetPeriodAndDuty
(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
/* END Msg(2:3227)-2 */
/* END Msg(2:3206)-6 */
{
  /* Implements:  PWM_ESDD_UD_183                                             */
  #if (PWM_TAU_UNIT_USED  == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannel;
  /* Variable to store the offset of the Master from the slave channel */
  uint8 LucVar;
  #endif

  /* Implements:  PWM064                                                      */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  #endif

  #if (PWM_TAU_UNIT_USED  == STD_ON)
  /* MISRA Violation: START Msg(4:0488)-2 */
  /* QAC Warning : START Msg(2:2824)-1 */
  LpChannel = Pwm_GpChannelConfig + ChannelNumber;
  /* END Msg(2:2824)-1 */
  /* END Msg(4:0488)-2 */
  #endif

  /* Implements:  PWM_ESDD_UD_043                                             */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)

  /* MISRA Violation: START Msg(4:2982)-7 */
  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber, PWM_SET_PERIODANDDUTY_SID);
  /* END Msg(4:2982)-7 */

  /* Implements:  PWM_ESDD_UD_053, PWM_ESDD_UD_054                            */
  #if (PWM_TAU_UNIT_USED  == STD_ON)
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* QAC Warning: START Msg(2:2814)-2 */
  if ((PWM_HW_TAUD == LpChannel->uiPwmTAUType) ||
                               (PWM_HW_TAUB == LpChannel->uiPwmTAUType))
  /* END Msg(2:2814)-2 */
  {
    /* Check for valid Period range for TAUD and TAUB */
    /* MISRA Violation: START Msg(4:2992)-5 */
    /* MISRA Violation: START Msg(4:2996)-6 */
    /* QAC Warning : START Msg(2:3892)-3 */
    if (PWM_PERIOD_LIMIT < Period)
    /* END Msg(4:2992)-5 */
    /* END Msg(4:2996)-6 */
    /* END Msg(2:3892)-3 */
    {
      /* Report to DET module */
      /* MISRA Violation: START Msg(4:2880)-8 */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_SET_PERIODANDDUTY_SID, PWM_E_PARAM_VALUE);
      LddReturnValue = E_NOT_OK;
      /* END Msg(4:2880)-8 */
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
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  #if (PWM_TAU_UNIT_USED  == STD_ON)
  /* Check whether channel is of type PWGA or TAU */
  if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  {
    /* No action required */
  }
  else
  #endif
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                PWM_SET_PERIODANDDUTY_SID, PWM_E_PARAM_CHANNEL);
    LddReturnValue = E_NOT_OK;
  }
  #endif

  #if (PWM_TAU_UNIT_USED  == STD_ON)

  /* Check for valid Duty range */
  if (DutyCycle > MAX_DUTY_CYCLE)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                     PWM_SET_PERIODANDDUTY_SID, PWM_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /* MISRA Violation: START Msg(4:2992)-5 */
  /* MISRA Violation: START Msg(4:2996)-6 */
  if (E_OK == LddReturnValue)
  /* END Msg(4:2992)-5 */
  /* END Msg(4:2996)-6 */
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* QAC Warning : START Msg(2:2814)-4 */
    /* QAC Warning : START Msg(2:3892)-3 */
    if (PWM_SLAVE_CHANNEL == (uint8) LpChannel->uiTimerMode)
    /* END Msg(2:3892)-3 */
    /* END Msg(2:2814)-4 */
    {
      /* Check if the master channel class of the slave channel is of
       * fixed period or fixed period shifted type
       */

      /* Get the offset of the Master from the slave channel */
      LucVar = LpChannel->ucMasterOffset;
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpChannel = Pwm_GpChannelConfig + (ChannelNumber - LucVar);
      /* END Msg(4:0488)-2 */
    }
    /* Master channel */
    else
    {
      /* No action required */
    }

    /* Implements: PWM136_Conf, ECUC_Pwm_00136                                */
    if (((PWM_FIXED_PERIOD == LpChannel->ddClassType) ||
              (PWM_FIXED_PERIOD_SHIFTED == LpChannel->ddClassType)))
    {
      /* Implements:  PWM_ESDD_UD_043                                         */
      #if (PWM_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET module */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                          PWM_SET_PERIODANDDUTY_SID, PWM_E_PERIOD_UNCHANGEABLE);

      #endif
    }
    else
    {
      /* Set Period and Duty cycle for the required channel */
      Pwm_HW_SetPeriodAndDuty(ChannelNumber, Period, DutyCycle);
    }
    #endif
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SetOutputToIdle
**
** Service ID           : 0x04
**
** Description          : This API is used to set the output of PWM channel to
**                        its configured Idle state.
**
**                        This API also sets the output of PWM PWGA
**                        channel to idle state with pin level low.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_SET_OUTPUT_TO_IDLE_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Pwm_HW_SetOutputToIdle and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_105, PWM_ESDD_UD_048                              */
/* Implements:  PWM099, PWM021, PWM084a, PWM084b, PWM088, SWS_Pwm_00088       */
/* Implements:  SWS_Pwm_00099, SWS_Pwm_00021, SWS_Pwm_10084, SWS_Pwm_20084    */
/* Implements:  PWM051b, SWS_Pwm_20051                                        */
/* Implements:  PWM129_Conf, ECUC_Pwm_00129, EAAR_PN0034_FR_0049              */
/* Implements:  PWM_ESDD_UD_017                                               */
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
/* END Msg(2:3227)-2 */
{
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  #if(PWM_SYNC_START_SUPPORT == STD_ON)
  #if (PWM_TAU_UNIT_USED  == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, PWM_VAR, PWM_CONFIG_CONST) LpChannelConfig;
  #endif
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, PWM_VAR, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  #endif
  #endif
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber, PWM_SET_OUTPUTTOIDLE_SID);

  if (E_OK == LddReturnValue)
  {
    #if(PWM_SYNC_START_SUPPORT == STD_ON)
    /* Check whether channel is of type PWGA or TAU */
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Implements PWM_ESDD_UD_131 */
    if (PWM_MIN_DIAG_CHANNELS_CONFIG_ID > ChannelNumber)
    #endif
    {
      #if (PWM_TAU_UNIT_USED  == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:2985)-4 */
      /* QAC Warning : START Msg(2:2824)-1 */
      LpChannelConfig = Pwm_GpChannelConfig + ChannelNumber;

      /* END Msg(2:2824)-1 */
      /* END Msg(4:2985)-4 */
      /* END Msg(4:0488)-2 */
      /* QAC Warning : START Msg(2:2814)-4 */
      if (PWM_ONE == LpChannelConfig->blSyncStartReq)
      {
         /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                 PWM_SET_OUTPUTTOIDLE_SID, PWM_E_PARAM_CHANNEL);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
       /* No Action Required */
      }
      /* END Msg(2:2814)-4 */
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if (PWM_DIAG_UNIT_USED  == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:2985)-4 */
      /* QAC Warning : START Msg(2:2824)-1 */
      LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (ChannelNumber -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
      /* END Msg(2:2824)-1 */
      /* END Msg(4:2985)-4 */
      /* END Msg(4:0488)-2 */
      /* QAC Warning : START Msg(2:2814)-4 */
      if (PWM_ONE == LpDiagChannelConfig->blSyncStartReq)
      {
        /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                 PWM_SET_OUTPUTTOIDLE_SID, PWM_E_PARAM_CHANNEL);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
       /* No Action Required */
      }
      /* END Msg(2:2814)-4 */
      #endif
    }
    #endif
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Set the output of a channel to its Idle state */
    Pwm_HW_SetOutputToIdle(ChannelNumber);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_GetOutputState
**
** Service ID           : 0x05
**
** Description          : This API is used to get the output state of PWM
**                        channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : LddRetOutputState
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_GET_OUTPUT_STATE_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Pwm_HW_GetOutputState and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_106, PWM_ESDD_UD_182, PWM088, SWS_Pwm_00088       */
/* Implements:  PWM100, PWM022, PWM085a, PWM085b, EAAR_PN0034_FR_0049         */
/* Implements:  SWS_Pwm_00100, SWS_Pwm_00022, SWS_Pwm_10085, SWS_Pwm_20085    */
/* Implements:  PWM_ESDD_UD_049, PWM_ESDD_UD_021, PWM051b, SWS_Pwm_20051      */
/* Implements:  PWM127_Conf, ECUC_Pwm_00127, EAAR_PN0066_FR_0082              */
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(Pwm_OutputStateType, PWM_PUBLIC_CODE) Pwm_GetOutputState
(Pwm_ChannelType ChannelNumber)
/* END Msg(2:3227)-2 */
{
  Pwm_OutputStateType LddRetOutputState;

  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements: PWM051c, SWS_Pwm_30051                                       */
  /* Initialize the return value in case of DET error */
  LddRetOutputState = PWM_LOW;

  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber, PWM_GET_OUTPUTSTATE_SID);

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Get the output state of a PWM channel */
    LddRetOutputState = Pwm_HW_GetOutputState(ChannelNumber);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

  return LddRetOutputState;
}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_DisableNotification
**
** Service ID           : 0x06
**
** Description          : This API is used to disable notification of both
**                        TAU and PWGA channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_NOTIFICATION_SUPPORTED is STD_ON.
**
** Global Variables     : Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**                        and Pwm_GaaNotifStatus
**
** Functions invoked    : Pwm_HW_DisableNotification, Det_ReportError
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_107, PWM_ESDD_UD_044                              */
/* Implements:  PWM101, PWM023, EAAR_PN0034_FR_0049, EAAR_PN0066_FR_0060      */
/* Implements:  SWS_Pwm_00101, SWS_Pwm_00023, PWM051b, SWS_Pwm_20051          */
/* Implements:  EAAR_PN0066_FR_0007, EAAR_PN0066_FR_0020, EAAR_PN0066_FR_0083 */
/* Implements:  PWM112a, PWM112b, PWM115b, PWM133_Conf, PWM088, SWS_Pwm_00088 */
/* Implements:  SWS_Pwm_10112, SWS_Pwm_20112, SWS_Pwm_20115, ECUC_Pwm_00133   */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_DisableNotification
(Pwm_ChannelType ChannelNumber)
/* END Msg(2:3227)-2 */
{
  #if ((PWM_TAU_UNIT_USED  == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
  /* Pointer to channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  #endif

  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;
  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber,
                                                   PWM_DISABLENOTIFICATION_SID);

  if (E_OK == LddReturnValue)
  #endif
  {
    #if (PWM_DEV_ERROR_DETECT == STD_ON)

    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED  == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* QAC Warning : START Msg(2:2824)-1 */
      LpChannelConfig = Pwm_GpChannelConfig + ChannelNumber;
      /* END Msg(2:2824)-1 */
      /* END Msg(4:0488)-2 */
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if (PWM_DIAG_UNIT_USED  == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:2985)-4 */
      /* QAC Warning: START Msg(2:2824)-1 */
      LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (ChannelNumber -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
      /* END Msg(2:2824)-1 */
      /* END Msg(4:0488)-2 */
      /* END Msg(4:2985)-4 */
      #endif
    }

    /* Check the notification is already disabled */
    if (PWM_FALSE == Pwm_GaaNotifStatus[ChannelNumber])
    {
      /* Report to DET module */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_DISABLENOTIFICATION_SID, PWM_E_ALREADY_DISABLED);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }

    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED  == STD_ON)
      /* QAC Warning : START Msg(2:2814)-4 */
      if (NULL_PTR == LpChannelConfig->pPwmEdgeNotifPtr)
      /* END Msg(2:2814)-4 */
      {
        /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                        PWM_DISABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if (PWM_DIAG_UNIT_USED  == STD_ON)
      /* QAC Warning : START Msg(2:2814)-4 */
      if (NULL_PTR == LpDiagChannelConfig->pPwmEdgeNotifPtr)
      /* END Msg(2:2814)-4 */
      {
        /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                        PWM_DISABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      #endif
    }

    if (E_OK == LddReturnValue)
    #endif
    {
      Pwm_HW_DisableNotification(ChannelNumber);
      Pwm_GaaNotifStatus[ChannelNumber] = PWM_FALSE;
    }
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* No action required */
    }
    #endif
  }/* End of if (LddReturnValue == E_OK) */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_EnableNotification
**
** Service ID           : 0x07
**
** Description          : This API is used to enable notification for both TAU
**                        and PWGA channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber and Notification
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_NOTIFICATION_SUPPORTED is STD_ON.
**
** Global Variables     : Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**                        and Pwm_GaaNotifStatus
**
** Functions invoked    : Pwm_HW_EnableNotification, Det_ReportError
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_108, PWM_ESDD_UD_044                              */
/* Implements:  PWM102, PWM024, PWM081, PWM105, PWM051b, SWS_Pwm_20051        */
/* Implements:  SWS_Pwm_00102, SWS_Pwm_00024, SWS_Pwm_00081                   */
/* Implements:  PWM088, SWS_Pwm_00088, SWS_Pwm_00105                          */
/* Implements:  EAAR_PN0066_FR_0007, EAAR_PN0066_FR_0060                      */
/* Implements:  EAAR_PN0066_FR_0020, EAAR_PN0034_FR_0049                      */
/* Implements:  PWM113a, PWM113b, PWM115a, PWM133_Conf                        */
/* Implements:  SWS_Pwm_10113, SWS_Pwm_20113, SWS_Pwm_10115, ECUC_Pwm_00133   */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_EnableNotification
(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
/* END Msg(2:3227)-2 */
{
  #if (PWM_TAU_UNIT_USED  == STD_ON)
  /* Pointer to channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  #endif

  /* Implements:  PWM_ESDD_UD_043                                             */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  Pwm_ChannelType LddChannelNumber;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber,
                                                    PWM_ENABLENOTIFICATION_SID);

  if (E_OK == LddReturnValue)
  #endif
  {
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED  == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* QAC Warning : START Msg(2:2824)-1 */
      LpChannelConfig = Pwm_GpChannelConfig + ChannelNumber;
      /* END Msg(2:2824)-1 */
      /* END Msg(4:0488)-2 */
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if ((PWM_DIAG_UNIT_USED  == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:2985)-4 */
      /* QAC Warning: START Msg(2:2824)-1 */
      LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (ChannelNumber -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
      /* END Msg(2:2824)-1 */
      /* END Msg(4:0488)-2 */
      /* END Msg(4:2985)-4 */
      #endif
    }

    #if (PWM_DEV_ERROR_DETECT == STD_ON)

    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED == STD_ON)
      if ((PWM_RISING_EDGE == Notification) || (PWM_BOTH_EDGES == Notification))
      {
        /* Get Master's channel ID */
        /* QAC Warning : START Msg(2:2814)-4 */
        LddChannelNumber = (ChannelNumber - (LpChannelConfig->ucMasterOffset));
        /* END Msg(2:2814)-4 */
      }
      else
      {
        LddChannelNumber = ChannelNumber;
      }
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if (PWM_DIAG_UNIT_USED == STD_ON)
      LddChannelNumber = ChannelNumber;
      #endif
    }

    /* Check if notification status is already TRUE */
    if (PWM_TRUE == Pwm_GaaNotifStatus[LddChannelNumber])
    {
      /* Report to DET module */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                             PWM_ENABLENOTIFICATION_SID, PWM_E_ALREADY_ENABLED);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }

    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED == STD_ON)
      if (PWM_BOTH_EDGES == Notification)
      {
        /* Check if notification status is already TRUE for Slave channel */
        if (PWM_TRUE == Pwm_GaaNotifStatus[ChannelNumber])
        {
          /* Report to DET module */
          (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                             PWM_ENABLENOTIFICATION_SID, PWM_E_ALREADY_ENABLED);
          LddReturnValue = E_NOT_OK;
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
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      /* No action required */
    }

    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    /* Check whether channel is of type PWGA or TAU */
    if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
    #endif
    {
      #if (PWM_TAU_UNIT_USED == STD_ON)
      if (PWM_RISING_EDGE == Notification)
      {
        /* Point to Master's channel Properties */
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpChannelConfig = Pwm_GpChannelConfig + LddChannelNumber;
        /* END Msg(4:0488)-2 */

        if (NULL_PTR == LpChannelConfig->pPwmEdgeNotifPtr)
        {
          /* Report to DET module */
          (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_ENABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }

        /* Point to Slave channel Properties */
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpChannelConfig = Pwm_GpChannelConfig + ChannelNumber;
        /* END Msg(4:0488)-2 */
      }
      else if (PWM_BOTH_EDGES == Notification)
      {
        /* Point to Master's channel Properties */
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpChannelConfig = Pwm_GpChannelConfig + LddChannelNumber;
        /* END Msg(4:0488)-2 */

        if (NULL_PTR == LpChannelConfig->pPwmEdgeNotifPtr)
        {
          /* Report to DET module */
          (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_ENABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }

        /* Point to Slave channel Properties */
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpChannelConfig = Pwm_GpChannelConfig + ChannelNumber;
        /* END Msg(4:0488)-2 */

        if (NULL_PTR == LpChannelConfig->pPwmEdgeNotifPtr)
        {
          /* Report to DET module */
          (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_ENABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        if (NULL_PTR == LpChannelConfig->pPwmEdgeNotifPtr)
        {
          /* Report to DET module */
          (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_ENABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
      }
      #endif
    }
    #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
    else
    #endif
    {
      #if (PWM_DIAG_UNIT_USED  == STD_ON)
      /* QAC Warning: START Msg(2:2814)-4 */
      if (NULL_PTR == LpDiagChannelConfig->pPwmEdgeNotifPtr)
      /* END Msg(2:2814)-4 */
      {
        /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                            PWM_ENABLENOTIFICATION_SID, PWM_E_NOTIFY_NOTCONFIG);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* Implements:  EAAR_PN0066_FR_0083                                     */
      if ((PWM_BOTH_EDGES == Notification) || (PWM_RISING_EDGE == Notification))
      {
        /* Report to DET module */
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                PWM_ENABLENOTIFICATION_SID, PWM_E_PARAM_VALUE);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      #endif
    }

    if (E_OK == LddReturnValue)
    #endif
    {
      #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
      /* Check whether channel is of type PWGA or TAU */
      if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
      #endif
      {
        #if (PWM_TAU_UNIT_USED  == STD_ON)
        /* Check for channel in the Slave Mode */
        /* QAC Warning : START Msg(2:3892)-3 */
        if (PWM_MASTER_CHANNEL != (uint8)LpChannelConfig->uiTimerMode)
        /* END Msg(2:3892)-3 */
        {
          if (PWM_BOTH_EDGES == Notification)
          {
            /* Clear Pending Interrupts and Enable Interrupt Processing for
             * Slave
             */
            Pwm_HW_EnableNotification(ChannelNumber);

            /* Set Notification enable status as PWM_TRUE for this channel */
            Pwm_GaaNotifStatus[ChannelNumber] = PWM_TRUE;

            /* Get Master's channel ID */
            ChannelNumber = (ChannelNumber - (LpChannelConfig->ucMasterOffset));

            /* Clear Pending Interrupts and Enable Interrupt Processing for
             * Master
             */
            Pwm_HW_EnableNotification(ChannelNumber);

            /* Set Notification enable status as PWM_TRUE for Master channel */
            Pwm_GaaNotifStatus[ChannelNumber] = PWM_TRUE;
          }
          else if (PWM_RISING_EDGE == Notification)
          {
            /* Get Master's channel ID */
            ChannelNumber = (ChannelNumber - (LpChannelConfig->ucMasterOffset));

            /* Clear Pending Interrupts and Enable Interrupt Processing for
             * Master
             */
            Pwm_HW_EnableNotification(ChannelNumber);

            /* Set Notification enable status as PWM_TRUE for this channel */
            Pwm_GaaNotifStatus[ChannelNumber] = PWM_TRUE;
          }
          /* For FALLING EDGE Notification */
          else
          {
            /* Clear Pending Interrupts and Enable Interrupt Processing for
             * Slave
             */
            Pwm_HW_EnableNotification(ChannelNumber);

            /* Set Notification enable status as PWM_TRUE for this channel */
            Pwm_GaaNotifStatus[ChannelNumber] = PWM_TRUE;
          }
        }
        else
        {
          /* No action required */
        }
        #endif
      }
      #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
      else
      #endif
      {
        #if (PWM_DIAG_UNIT_USED  == STD_ON)
        /* Clear pending interrupts and Enable Interrupt Processing for
         * PWGA channel
         */
        Pwm_HW_EnableNotification(ChannelNumber);

        /* Set Notification enable status as PWM_TRUE for this channel */
        Pwm_GaaNotifStatus[ChannelNumber] = PWM_TRUE;
        #endif
      }
    }
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* No action required */
    }
    #endif
  } /* End of if (LddReturnValue == E_OK) */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_CheckDetErrors
**
** Service ID           : None
**
** Description          : This API is used to report DET for invalid
**                        initialization and invalid ChannelNumber in this file.
**
** Sync/Async           : -
**
** Re-entrancy          : -
**
** Input Parameters     : ChannelNumber, Api_SID
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : LddReturnValue
**
** Preconditions        : NA
**
** Global Variables     : Pwm_GblDriverStatus
**
** Functions invoked    : None
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_130, PWM_ESDD_UD_223, PWM064                      */
/* Implements:  EAAR_PN0066_FR_0028                                           */
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_DUTY_CYCLE_API == STD_ON) ||\
(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON)\
||(PWM_GET_OUTPUT_STATE_API == STD_ON)||(PWM_SELECT_CHANNEL_CLK_API == STD_ON)\
||(PWM_SET_TRIGGER_DELAY_API == STD_ON)||(PWM_SET_CHANNEL_OUTPUT_API == STD_ON)\
||((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&(PWM_DIAG_UNIT_USED == STD_ON))\
||(PWM_NOTIFICATION_SUPPORTED == STD_ON)))

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
STATIC FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_CheckDetErrors
                               (Pwm_ChannelType ChannelNumber, uint8 Api_SID)
/* END Msg(2:3227)-2 */
{
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;


  /* Check if the PWM Driver is initialized properly */
  if (PWM_INITIALIZED != Pwm_GblDriverStatus)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, Api_SID,
                                                      PWM_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Implements:  PWM_ESDD_UD_061                                             */
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, Api_SID,
                                                      PWM_E_PARAM_CHANNEL);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  return(LddReturnValue);
}

#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SelectChannelClk
**
** Service ID           : 0x09
**
** Description          : This API is used to select one of the four clock
**                        sources for both TAU and PWGA channel at run time.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**                        ClockSource
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SELECT_CHANNEL_CLK_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Pwm_HW_SelectChannelClk, Det_ReportError
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_153, PWM_ESDD_UD_150                              */
/* Implements:  EAAR_PN0066_FR_0058, EAAR_PN0034_FR_0049, PWM088              */
/* Implements:  PWM051b, SWS_Pwm_20051                                        */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0066_FR_0039, SWS_Pwm_00088       */
#if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SelectChannelClk
(Pwm_ChannelType ChannelNumber, Pwm_ClockSourceType ClockSource)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;


  LddReturnValue =
                  Pwm_CheckDetErrors(ChannelNumber, PWM_SELECT_CHANNEL_CLK_SID);

  /* Check for valid Clock source */
  if (ClockSource > PWM_CLOCK_SOURCE_3)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                     PWM_SELECT_CHANNEL_CLK_SID, PWM_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Set the Duty cycle for the required channel */
    Pwm_HW_SelectChannelClk(ChannelNumber, ClockSource);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SetTriggerDelay
**
** Service ID           : 0x0A
**
** Description          : This API is used to change the offset of the trigger
**                        point for a PWM PWGA channel during runtime. Trigger
**                        is only updated after the next falling edge on the
**                        output. This API does not support TAU channels.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**                        TriggerDelay
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_TRIGGER_DELAY_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Pwm_HW_SetTriggerDelay, Det_ReportError
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_152, PWM088, SWS_Pwm_00088, SWS_Pwm_20051         */
/* Implements:  EAAR_PN0066_FR_0065, EAAR_PN0034_FR_0049, PWM051b             */
/* Implements:  PWM_ESDD_UD_149                                               */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0066_FR_0063, EAAR_PN0066_FR_0064 */
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SetTriggerDelay
(Pwm_ChannelType ChannelNumber, uint16 TriggerDelay)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;


  LddReturnValue =
                  Pwm_CheckDetErrors(ChannelNumber, PWM_SET_TRIGGER_DELAY_SID);

  /* Check for valid Clock source */
  if (TriggerDelay > PWM_DIAG_MAX_TRIGGER_DELAY)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                     PWM_SET_TRIGGER_DELAY_SID, PWM_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  /* Check whether channel is of type PWGA or TAU */
  if (ChannelNumber < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                PWM_SET_TRIGGER_DELAY_SID, PWM_E_PARAM_CHANNEL);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  #endif

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Set the Duty cycle for the required channel */
    Pwm_HW_SetTriggerDelay(ChannelNumber, TriggerDelay);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SetChannelOutput
**
** Service ID           : 0x0B
**
** Description          : This API is used to set the PWM output to a constant
**                        signal for the duration of the current period.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**                        State
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_CHANNEL_OUTPUT_API is STD_ON.
**
** Global Variables     : None
**
** Functions invoked    : Pwm_HW_SetChannelOutput, Det_ReportError
**                        and Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_160                                               */
/* Implements:  EAAR_PN0066_FR_0053, PWM088, SWS_Pwm_00088, SWS_Pwm_20051     */
/* Implements:  PWM_ESDD_UD_158                                               */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0034_FR_0049, PWM051b             */
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void, PWM_PUBLIC_CODE) Pwm_SetChannelOutput
(Pwm_ChannelType ChannelNumber, Pwm_OutputStateType State)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;


  LddReturnValue =
                  Pwm_CheckDetErrors(ChannelNumber, PWM_SET_CHANNEL_OUTPUT_SID);

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Set the output of a channel to constant signal High or Low for current
     * period
     */
    Pwm_HW_SetChannelOutput(ChannelNumber, State);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SynchronousInit
**
** Service ID           : 0x0C
**
** Description          : This API performs the initialization of PWM channels
**                        configured to support synchronous start/stop of
**                        timers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SYNC_START_SUPPORT is STD_ON.
**
** Global Variables     : Pwm_GblDriverStatus and Pwm_GblSyncInitStatus
**
** Functions invoked    : Det_ReportError and Pwm_HW_SynchronousInit
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_166, PWM_ESDD_UD_013                              */
/* Implements:  EAAR_PN0066_FR_0069, PWM088, SWS_Pwm_00088                    */
/* Implements:  PWM_ESDD_UD_165, PWM051b, SWS_Pwm_20051                       */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0034_FR_0049                      */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousInit (void)
{
  /* Implements:  PWM_ESDD_UD_043                                             */
  /* Check if the PWM Driver is initialized or not */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  if (PWM_INITIALIZED == Pwm_GblDriverStatus)
  #endif
  {
    /* Initialize all PWM channels configured to support synchronous start/stop
     * of timers, this excludes initialization of channels that will be
     * handled by complex drivers
     */
    Pwm_HW_SynchronousInit();

  /* Implements:  PWM_ESDD_UD_043                                             */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Pwm_GblSyncInitStatus = PWM_INITIALIZED;
    #endif
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Report to DET */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                        PWM_SYNCHRONOUS_INIT_SID, PWM_E_UNINIT);
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SynchronousStart
**
** Service ID           : 0x0D
**
** Description          : This API starts PWM channels configured to support
**                        synchronous start/stop of timers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.APIs Pwm_Init and Pwm_SynchronousInit should be
**                          invoked.
**                        2.This API is available only if the pre-compile
**                          option PWM_SYNC_START_SUPPORT is STD_ON.
**
** Global Variables     : Pwm_GblDriverStatus, Pwm_GblSyncInitStatus
**                        Pwm_GblSyncStartStatus
**
** Functions invoked    : Det_ReportError and Pwm_HW_SynchronousStart
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_167, PWM_ESDD_UD_013                              */
/* Implements:  EAAR_PN0066_FR_0069, PWM088, SWS_Pwm_00088                    */
/* Implements:  PWM_ESDD_UD_165, PWM051b, SWS_Pwm_20051                       */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0034_FR_0049                      */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousStart (void)
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
   /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;

  /* Check if the PWM Driver is initialized and API Pwm_SynchronousInit is
   * invoked or not
   */
  if ((PWM_INITIALIZED == Pwm_GblDriverStatus) &&
                                     (PWM_INITIALIZED == Pwm_GblSyncInitStatus))
  {
    /* No action required */
  }
  else
  {
    /* Report to DET */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                      PWM_SYNCHRONOUS_START_SID, PWM_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }

  /* Check if Synchronous initialization is already done */
  if (PWM_SYNC_STARTED == Pwm_GblSyncStartStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                              PWM_SYNCHRONOUS_START_SID, PWM_E_ALREADY_STARTED);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif
  {
    /* Start all PWM channels configured to support synchronous start/stop
     * of timers, this excludes stopping of channels that will be
     * handled by complex drivers
     */
    Pwm_HW_SynchronousStart();

    Pwm_GblSyncStartStatus = PWM_SYNC_STARTED;
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name        : Pwm_SynchronousStop
**
** Service ID           : 0x0E
**
** Description          : This API stops PWM channels configured to support
**                        synchronous start/stop of timers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.APIs Pwm_Init and Pwm_SynchronousInit should be
**                          invoked.
**                        2.This API is available only if the pre-compile
**                          option PWM_SYNC_START_SUPPORT is STD_ON.
**
** Global Variables     : Pwm_GblDriverStatus, Pwm_GblSyncInitStatus
**                        Pwm_GblSyncStartStatus
**
** Functions invoked    : Det_ReportError and Pwm_HW_SynchronousStop
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_168, PWM_ESDD_UD_013                              */
/* Implements:  PWM088, SWS_Pwm_00088                                         */
/* Implements:  PWM_ESDD_UD_165, PWM051b, SWS_Pwm_20051                       */
/* Implements:  EAAR_PN0066_FR_0062, EAAR_PN0034_FR_0049                      */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PUBLIC_CODE) Pwm_SynchronousStop (void)
{
  /* Check if the PWM Driver is initialized and API Pwm_SynchronousInit is
   * invoked or not
   */
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  if ((PWM_INITIALIZED == Pwm_GblDriverStatus) &&
                                     (PWM_INITIALIZED == Pwm_GblSyncInitStatus))
  #endif
  {
    /* Stop all PWM channels configured to support synchronous start/stop
     * of timers, this excludes stopping of channels that will be
     * handled by complex drivers
     */
    Pwm_HW_SynchronousStop();

    Pwm_GblSyncStartStatus = PWM_SYNC_NOTSTARTED;
  }
  /* Implements:  PWM_ESDD_UD_043                                             */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Report to DET */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                        PWM_SYNCHRONOUS_STOP_SID, PWM_E_UNINIT);
  }
  #endif

}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
** Function Name      : Pwm_GetVersionInfo
**
** Service ID         : 0x08
**
** Description        : This service returns the version information of this
**                      module.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Re-entrant
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
** Global Variable(s) : None
**
** Function(s) invoked: Det_ReportError()
**
** Registers Used     : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_109                                               */
/* Implements:  PWM_ESDD_UD_050, PWM088, SWS_Pwm_00088, PWM051b               */
/* Implements:  PWM103, PWM068, PWM069a, PWM069b, PWM094, SWS_Pwm_20051       */
/* Implements:  SWS_Pwm_00103, SWS_Pwm_20069, SWS_Pwm_00094                   */
/* Implements:  PWM135_Conf, ECUC_Pwm_00135, EAAR_PN0034_FR_0092              */
/* Implements:  EAAR_PN0034_FR_0051, EAAR_PN0034_FR_0049, PWM114              */
#if (PWM_VERSION_INFO_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(void,PWM_PUBLIC_CODE) Pwm_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, PWM_APPL_CONST) versioninfo)
/* END Msg(2:3227)-2 */
{
  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if versioninfo pointer is equal to Null */
  if(NULL_PTR == versioninfo)
  {
    /* Implements:  PWM_ESDD_UD_007, PWM151, SWS_Pwm_00201                    */
    /* Report to DET  */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                 PWM_GET_VERSION_INFO_SID, PWM_E_PARAM_POINTER);
  }
  else
  #endif /*#if(PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)PWM_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PWM_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = PWM_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = PWM_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = PWM_SW_PATCH_VERSION;
  }
}
#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif  /*(PWM_VERSION_INFO_API == STD_ON)*/

/*******************************************************************************
** Function Name        : Pwm_CheckHWConsistency
**
** Service ID           : 0x0F
**
** Description          : This API which compares the control register values
**                        with the RAM mirror/ROM as part of the hardware
**                        consistency check
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
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_TAUDB_RAM_MIRROR or PWMTAUJ_RAM_MIRROR
**                          or PWM_PWGA_RAM_MIRROR is PWM_MIRROR_ENABLE.
**
** Global Variables     : Pwm_GblDriverStatus
**
** Functions invoked    : Det_ReportError, Pwm_HW_CheckHWConsistency,
**                        PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**
** Registers Used       : None
**
*******************************************************************************/

/* Implements:  PWM_ESDD_UD_215, EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006   */
/* Implements:  PWM_ESDD_UD_212,EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0007     */
/* Implements:  EAAR_PN0034_FSR_0006, EAAR_PN0034_FSR_0007, PWM088            */
/* Implements:  SWS_Pwm_00088, SWS_Pwm_20051, PWM051b                         */
/* Implements:  EAAR_PN0066_FR_0062                                           */
#if ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
      (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE ) )

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_CheckHWConsistency
                                   (Pwm_HWConsistencyModeType HWConsistencyMode)
/* END Msg(2:3227)-2 */
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  LddReturnValue = E_OK;
  /* Det Check if PWM Driver is initialized */
  if (PWM_INITIALIZED != Pwm_GblDriverStatus)
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                                    PWM_CHECK_HW_CONSISTENCY_SID, PWM_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* Det Check if Pwm_HW_CheckHWConsistency is called with invalid arguments */
  else if ((PWM_STATIC != HWConsistencyMode) &&
                                             (PWM_DYNAMIC != HWConsistencyMode))
  {
    /* Report to DET module */
    (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                             PWM_CHECK_HW_CONSISTENCY_SID, PWM_E_PARAM_VALUE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  if (E_OK == LddReturnValue)
  #endif  /* End of #if (PWM_DEV_ERROR_DETECT == STD_ON)*/
  {
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON) /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    LddReturnValue = Pwm_HW_CheckHWConsistency(HWConsistencyMode);
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON) /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  return(LddReturnValue);
}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif /* End of ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
                    (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
                    (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE ))*/

/*******************************************************************************
** Function Name        : Pwm_ControlTriggerOutput
**
** Service ID           : 0x10
**
** Description          : This API enables / disables trigger output for
**                        ADC.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId and LddCtl
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : LddReturnValue
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_CONTROL_TRIGGER_OUTPUT_API and
**                          PWM_DIAG_UNIT_USED are STD_ON.
**
** Global Variables     : Pwm_GpDiagChannelConfig
**
** Functions invoked    : Det_ReportError, Pwm_HW_ControlTriggerOutput,
**                        Pwm_CheckDetErrors
**
** Registers Used       : None
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_224, PWM_ESDD_UD_223, EAAR_PN0066_FR_0060, PWM088 */
/* Implements:  EAAR_PN0066_FR_0115, EAAR_PN0034_FR_0049, SWS_Pwm_00088       */
/* Implements:  PWM051b, SWS_Pwm_20051, EAAR_PN0066_FR_0062                   */
#if ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&  \
                                        (PWM_DIAG_UNIT_USED == STD_ON))

#define PWM_START_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-2 */
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_ControlTriggerOutput
                 (Pwm_ChannelType ChannelNumber, Pwm_TriggerControlType Control)
/* END Msg(2:3227)-2 */
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LddReturnValue;

  /* Implements:  PWM_ESDD_UD_043, PWM064                                     */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* MISRA Violation: START Msg(4:2982)-7 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-7 */

  /* Det Check using Pwm_CheckDetErrors API */
  LddReturnValue = Pwm_CheckDetErrors(ChannelNumber,
                                               PWM_CONTROL_TRIGGER_OUTPUT_SID);

  if (E_OK == LddReturnValue)
  {
    /*Det Check if Pwm_HW_ControlTriggerOutput is called with */
    /*invalid arguments*/
    if ((PWM_ENABLE != Control) && (PWM_DISABLE != Control))
    {
      /* Report to DET module */
      (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                             PWM_CONTROL_TRIGGER_OUTPUT_SID, PWM_E_PARAM_VALUE);
      LddReturnValue = E_NOT_OK;
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
  if (E_OK == LddReturnValue)
  #endif  /* End of #if (PWM_DEV_ERROR_DETECT == STD_ON)*/
  {
    LddReturnValue = Pwm_HW_ControlTriggerOutput(ChannelNumber, Control);
  }
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  
  return(LddReturnValue);
}

#define PWM_STOP_SEC_PUBLIC_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* QAC Warning: START Msg(2:0862)-5 */
#include "MemMap.h"
/* END Msg(2:0862)-5 */
#endif

#endif /* End of ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) && \
                  (PWM_DIAG_UNIT_USED == STD_ON))*/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
