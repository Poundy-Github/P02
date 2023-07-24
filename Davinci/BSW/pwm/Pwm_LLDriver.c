/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_LLDriver.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Low level Driver code of the PWM Driver Component                          */
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
 *                       1. As part of JIRA #ARDAAGA-70, updated
 *                          Pwm_HW_Callback for null pointer check and
 *                          corrected Pwm notifications for proper channel Id.
 *                       2. As part of JIRA #ARDAAGA-87, prefix of
 *                          module name is added to variables to avoid
 *                          conflict between different modules.
 *                       3. As part of JIRA #ARDAAGA-188, Pwm_HW_Init is
 *                          modified for TAUJ units register updation.
 *                       4. As part of the AR_PN0066_FR_0092 and JIRA
 *                          #ARDAAGA-187 PWM_VARIABLE_PERIOD_SHIFTED condition
 *                          checks are added in Pwm_HW_SetDutyCycle and
 *                          Pwm_HW_SetOutputToIdle to check its functionality.
 *                       5. As part of the JIRA #ARDAAGA-185,
 *                          Pwm_HW_SetDutyCycle api is modified for
 *                          synchronous start.
 * V1.0.2:  09-Aug-2016 : As part of F1K V42.00.00 development activity,
 *                        the following changes are made:
 *                        1. As part of JIRA #ARDAABD-441,
 *                           Pwm_GaaChannelIdleStatus was removed. Idle state
 *                           is determined based on Channel Output Register.
 *                        2. As part of JIRA #ARDAABD-408,
 *                           Inconsistent memory map declaration was corrected
 *                           for Pwm_HW_Callback() and Pwm_PWGA_Callback()
 *                           functions.
 *                        3. As part of JIRA #ARDAABD-535,
 *                           Pwm_HW_GetOutputState was update with correct
 *                           algorithm for PWM Diag.
 *                        4. As part of JIRA #ARDAABD-669,
 *                           Initialization of TAUDB Output registers is done
 *                           Pwm_GpChannelConfig before setting TAUDB output
 *                           register in Pwm_HW_Init() function.
 *                        5. As part of JIRA #ARDAABD-675,
 *                           when clock is changed for master, slaves shall be
 *                           stopped synchronously.
 *                        6. As part of JIRA #ARDAABD-428,
 *                           when clock is changed in PWGAnCTL.PWGAnCKS, the
 *                           PWGAn operation shall be stopped. When clock is
 *                           changed for TAU channels, operation shall be
 *                           stopped.
 *                        7. As part of JIRA #ARDAABD-438,
 *                           synchronous start and stop for
 *                           PWM_FIXED_PERIOD_SHIFTED and
 *                           PWM_VARIABLE_PERIOD_SHIFTED channel classes is
 *                           implemented.
 * V2.0.0:  01-Nov-2016 : 1. JIRA #ARDAABD-917 - Update to ASR 4.2.2 and
 *                           ASR 4.0.3.
 *                        2. JIRA #ARDAABD-708 - Illegal pointer access when
 *                           pending interrupts are cleared.
 *                        3. JIRA #ARDAABD-670 - TAUDB and TAUJ initialization
 *                           for IDLE state is not consistent.
 *                        4. JIRA #ARDAABD-740 - Set output state to idle for
 *                           TAUJ channel is not working properly.
 *                        5. JIRA #ARDAABD-766 - Code improvement after UT.
 *                        6. JIRA #ARDAABD-797 - Glitches visible at outputs
 *                           when VARIABLE_PERIOD_SHIFTED channels are
 *                           restarted from IDLE with Pwm_SetPeriodAndDuty().
 *                        7. JIRA #ARDAABD-709 - Set Duty Cycle is not working
 *                           properly when master DC is changed. Synchronous
 *                           channels are not started simultaneously.
 *                        8. JIRA #ARDAABD-839 - Synchronous channels are not
 *                           initialize correct.
 *                        9. JIRA #ARDAABD-778 - SPwm_SynchronousStart() and
 *                           Pwm_SetDutyCycle() APIs are not implemented as per
 *                           internal requirement.
 *                       10. JIRA #ARDAABD-671 - Channels configured for
 *                           complex driver start during Pwm_Init.
 *                       11. JIRA #ARDAABD-882 - Duty cycle values are set
 *                           wrongly for PWM DIAG channel.
 *                       12. JIRA #ARDAABD-926 - Since Config Data is
 *                           allocated in ROM, Config Data might not be allowed
 *                           to have variables whose Storage Specifier
 *                           is AUTOMATIC.
 *                       13. JIRA #ARDAABD-920 - Peripheral Group HW UM
 *                           issue (SYNCP).
 * V3.0.0:  28-Nov-2016 : 1. JIRA #ARDAABD-565 - Implement FuSa requirements
 *                           for ASIL-B.
 *                        2. JIRA #ARDAABD-737 - When the timer is not stopped
 *                           after writing into TAUDn Channel Stop Trigger
 *                           Register, Need to report to DEM.
 * V3.0.1:  08-Dec-2016 : JIRA ARDAABD-479 -  Duplication of same pre-compiler
 *                        switch from lines 496 and 539 resolved
 * V3.0.2:  13-Dec-2016 : JIRA ARDAABD-565 -   Acceptance points implemented:
 *                        1. Remove semicolon for FuSa macro implementation
 *                        2. Replace hard coded values
 *                        3. Remove Ram mirror operation for TE register
 * V3.0.3:  19-Dec-2016 : Ensure acceptance point regarding Coding Requirements
 * V3.0.4:  17-Feb-2017 : 1. JIRA ARDAABD-438 - Acceptance point implemented
 *                        Add else conditions for all if conditions
 *                        2. JIRA ARDAABD-778 - For PWM_VARIABLE_PERIOD_SHIFTED
 *                        PWM_FIXED_PERIOD_SHIFTED channels: Slave channels are
 *                        and set to the configured idle state of each channel
 *                        when Pwm_SetOutputToIdle is called for Master channel
 *                        3. JIRA ARDAABD-737 - Acceptance points implemented :
 *                          - Add "Dem_ReportErrorStatus" in appicable headers
 *                          - Remove DET mention from revision history
 *                        4. JIRA ARDAABD-428 - DEM error PWM_E_TIMER_FAILURE is
 *                        not reported erroneously in Pwm_HW_Init when all the
 *                        slave channels are synchronous
 *                        5. JIRA ARDAABD-599 - DEM error PWM_E_REG_WRITE_VERIFY
 *                        is not reported erroneously in Pwm_HW_SetChannelOutput
 *                        for PWGA channels
 * V3.0.5 : 17-Mar-2017 : Update for ARDAABD-827 Tracebility ticket
 *                        1. Add General Traceability Section
 *                        2. Replace  "TRACE" reference with "Implements" word
 *                        3. Add 4.2.2 requirement for APIs
 * V3.0.6 : 16-Jun-2017 : Following changes are made
 *                        1. Added Msg(4:0491), Msg(4:0715), Msg(4:3138)
 *                           Msg(4:2962), Msg(4:3344) and Msg(4:2792).
 *                        2. Handled QAC warnings.
 * V3.1.0 : 10-Jul-2017 : Following changes are made:
 *                        1. As per JIRA ticket ARDAABD-1390,removed entry and
 *                           exit of critical sections in functions Pwm_HW_Init
 *                           and Pwm_HW_DeInit.
 *                        2. As per JIRA ticket ARDAABD-1726, following changes
 *                           are made:
 *                           a. Period selection registers PWGAPRD and
 *                              PWGAPRDSLk are added in Pwm_HW_Init and
 *                              Pwm_HW_DeInit API.
 *                           b. Pwm_HW_ControlTriggerOutput API is added.
 *                           c. Added definition for global array
 *                              'Pwm_GaaDiagChannelMap'
 *                           d. Pwm_HW_CheckHWConsistency API is updated for
 *                              PWGAnTCR, PWGAPRD, PWGAPRDSL0, PWGAPRDSL1
 *                              and PWGAPRDSL2 registers.
 *                           e. Updated the register 'ulPWGAINTMSK' in
 *                              'Pwm_HW_EnableNotification',
 *                              'Pwm_HW_DisableNotification', Pwm_PWGA_Callback,
 *                               and 'Pwm_HW_SetChannelOutput'.
 *                           f. Implemented check write verify and RAM mirroring
 *                              of PWGAINTMSK register and the API
 *                              Pwm_HW_CheckHWConsistency is updated.
 *                           g. Handled QAC warnings.
 * V3.1.1: 21-Sep-2017  : Following changes are made:
 *                        1. As part of ARDAABD-2476,
 *                           a. Naming of Local variables is corrected
 *                              throughout as per requirement MCAL052.
 *                           b. Meaningful macro definitions are added.
 *                           c. Structure member Type-prefix is corrected based
 *                              on the data type names.
 *                           d. Removed subtraction calculation from the
 *                              argument of or macro function on calling
 *                        2. As per JIRA ticket #ARDAABD-2465, inclusion of
 *                           Iocommon_Defines.h is added
 *                        3. As part of ARDAABD-2425,
 *                           a. Handled QAC level 2 warnings.
 * V3.1.2: 18-Jun-2018  : Following changes are made:
 *                        1. As part of merging activity, #ARDAABD-3454
 *                           a. Pre compile switch PWM_DIAG_GROUPx_ID_SUPPORT
 *                              added in Pwm_HW_GetDiagChannelStatus,
 *                              Pwm_HW_StartDiagChannel and
 *                              Pwm_HW_StopDiagChannel APIs.
 *                              Ref: ARDAABD-883.
 *                           b. The accessing of IMR register is removed and
 *                              interrupt is enabled and disabled by
 *                              ICR register.
 *                              Ref: ARDAABD-2158.
 *                           c. Memory section
 *                              PWM_<START/STOP>_SEC_VAR_NO_INIT_8 is added for
 *                              Pwm_GaaDiagChannelMap global array.
 *                              Ref: ARDAABD-908.
 *                           d. Updated Copyright information
 *                        2. As per JIRA ticket ARDAABD-3620, function banners
 *                           of APIs are corrected according to the registers
 *                           used.:
 *                        3. As per JIRA ticket ARDAABD-1627, pre-compile
 *                           switch PWM_SELB_INTC2_SUPPORT is added in
 *                           Pwm_HW_Init API.
 *                        4. As per JIRA ticket ARDAABD-2659,
 *                           Pwm_HW_SetDutyCycle, Pwm_HW_SetPeriodAndDuty and
 *                           Pwm_HW_SetDuty_PeriodShifted APIs are updated.
 *                        5. As per JIRA ticket ARDAABD-2929, pre-compile
 *                           switches are added for variable LusTempReg in
 *                           Pwm_HW_SelectChannelClk API, LusTempReg in
 *                           Pwm_HW_SynchronousInit API and LucCntlRegs,
 *                           LucUserCntlRegsIndx and LucOsCntlRegsIndx in
 *                           Pwm_HW_CheckHWConsistency API.
 *                        6. As per JIRA ticket ARDAABD-880, Pwm_HW_DeInit API
 *                           is updated for DIAG channels to apply reset
 *                           mechanism for PWGAnCNT and added DEM parameter
 *                           PWM_E_TIMER_FAILURE if the failure occured.
 *                        7. As per JIRA ARDAABD-1091, Pwm_HW_SynchronousStop
 *                           API is updated to set the Synchronous slave
 *                           channels to their idle state.
 *                        8. As per JIRA ARDAABD-2492, Pwm_HW_Init and
 *                           Pwm_HW_SynchronousInit are updated to add a
 *                           check to update the value of CDR register when
 *                           default period is configured as zero.
 *                        9. As per JIRA ARDAABD-3839, updated traceability tags
 *                           for reqtify coverage improvement.
 * V3.1.3: 09-Aug-2018  : Following changes are made:
 *                        As part of ARDAABD-2420, Following changes are made:
 *                        1.Replace the processing in the original code with the
 *                          macro value SetIORegSyncpDummyRead().
 *                        2. Misra warning Tag for Message Msg(4:0303)
 *                          has been added.
 * V3.1.4: 09-Aug-2018  : Following changes are made:
 *                        As part of ARDAABD-3935, Following changes are made:
 *                        1.Delete the check of register BRS if the
 *                          PwmTaUnitSelection is TAUB in the function
 *                          Pwm_HW_CheckHWConsistency.
 * V3.1.5: 09-Aug-2018  : Following changes are made:
 *                        As part of ARDAABD-3940, Following changes are made:
 *                        1.When performing read-modify-write, critical
 *                          section protection is added
 *                        change content as follows:
 *                        Pwm_HW_SetDutyCycle TAUBnTT TAUBnTE TAUBnTS TAUBnTOE
 *                        Pwm_HW_SetPeriodAndDuty  TAUBnTT TAUBnTE TAUBnTS
 *                        TAUBnTOE
 *                        Pwm_HW_DisableNotification PWGAINTMSK
 * V3.1.6: 09-Aug-2018  : As part of ticket #ARDAABD-3901,
 *                        Following changes are made:
 *                        1. CMOR is written before CDR
 * V3.1.7: 09-Aug-2018  : As part of ticket #ARDAABD-3898,
 *                        Following changes are made:
 *                        1. Critical section shall be used while
 *                          read-modify-write SLPWGAk register.
 * V3.1.8: 09-Aug-2018  : As part of ticket #ARDAABD-3937,
 *                        Following changes are made:
 *                        1. Modify for function Pwm_HW_SetChannelOutput
 *                         Clear channel interrupt factor for F1KM/F1KH
 *                         read-modify-write PWGAINTF/PWGAINTFC register.
 * V3.1.9: 14-Sep-2018  : As part of ticket #ARDAABD-3937,
 *                        Following changes are made:
 *                        Modify for LulPwgaIntFValue in function
 *                        Pwm_HW_SetChannelOutput to correct the compile warning
 * V3.1.10: 18-Jan-2019  : As part of ticket #ARDAABD-3937,
 *                        Following changes are made:
 *                        Add dummy write for LulPwgaIntFValue in function
 *                        Pwm_HW_SetChannelOutput to correct the compile warning
 * V3.1.11: 25-Jan-2019  : As part of ticket #ARDAABD-3937,
 *                        Following changes are made:
 *                        Add volatile keyword for declaration of
 *                        LulPwgaIntFValue. in function Pwm_HW_SetChannelOutput
 *                        to correct the compile warning
 * V3.1.12: 12-Apr-2019  : As part of ticket #ARDAABD-4077,
 *                        Following changes are made:
 *                        1. Pwm_HW_CalDiagResetTriggerPoint() API is
 *                         modified. Variable 'LusDiagPeriod' is added.
 *                         calculate LusResetCondition according to 
 *                         the value of LusDiagPeriod.
 *                        2.Pwm_HW_GetDiagChannelPeriod API is added.
 *                         to calculate LusDiagPeriod according to
 *                         the value configured in PwmDiagCounterPeriod
 *                         parameter for channels configured as
 *                         CONFIGURED_BY_PWSAPRD and maximum period(0xfff)
 *                         for channels configured as FREE_RUNNING.
 *                        3.Copyright information is updated.
 * V3.1.13: 08-Oct-2019  :Following changes are made:
 *                        1. As part of ticket #ARDAABD-4347,
 *                        In Pwm_HW_DeInit(),Pwm_HW_SetDutyCycle(),
 *                        Pwm_HW_SelectChannelClk(),Pwm_HW_SetChannelOutput(),
 *                        Pwm_PWGA_Callback() API,before updating to PWGAnCSDR,
 *                        PWGAnCRDR,or PWGAnCTDR registers,simultaneous rewrite
 *                        enabling flag (PWGAnRSF.PWGAnRSF) needs to be verified
 *                        and if simultaneous rewrite is ongoing
 *                        (PWGAnRSF.PWGAnRSF = 1),report
 *                        Dem PWM_E_REWRITE_FAILED.
 *                        2. As part of ticket #ARDAABD-2938,
 *                        The operation '& PWM_CKS_MASK'(& 0x03) is added to
 *                        the assignment operation of LddPrevClockSource of
 *                        Pwm_HW_SelectChannelClk API.
 *                        In the Pwm_HW_SelectChannelClk()API,Fixed the write
 *                        value to the PWGAnCTL register to ensure that the
 *                        non-PWGAnCKS bits on this register are correctly
 *                        written.
 *                        3. As part of ticket #ARDAABD-3901,
 *                        In Pwm_HW_SynchronousInit() API,adjust the CDR/CMOR
 *                        usage order.CMOR is written before CDR.
 *                        4. As part of ticket #ARDAABD-4350,
 *                        Modified the API Pwm_HW_SetDuty_PeriodShifted(),
 *                        delete the following process:
 *                        "LpChannelConfig = LpChannelConfig -
 *                        LpChannelConfig->ucMasterOffset;" to get the slave
 *                        Mask value for RSF check.
 *                        5. As part of ticket #ARDAABD-4014,
 *                        Added the synchronization process in the end of
 *                        Pwm_PWGA_Callback() function.
 *                        6. As part of ticket #ARDAABD-3997,
 *                        The Code set the corresponding bits as per the
 *                        configured Idle state for TAUD/TAUB and TAUD in
 *                        Pwm_HW_Init() Function.
 *                        7. As part of ticket #ARDAABD-3999,
 *                        In the Pwm_HW_SynchronousStart() function,
 *                        usSyncInitMask is used as the mask value for the
 *                        synchronous channel of TAUB TAUD TAUJ, instead of
 *                        usTOEMask.
 *                        8. Corrected the format issue.
 *                        9. As part of ticket #ARDAABD-4639,
 *                        Handled QAC warnings.
 */
/******************************************************************************/

/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements:  EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0018 */
/* Implements:  PWM_ESDD_UD_001, EAAR_PN0066_FR_0017                          */
/* Implements:  EAAR_PN0066_FR_0010, EAAR_PN0066_FR_0059                      */
/* Implements:  EAAR_PN0066_FR_0009                                           */

/* Implements:  PWM_ESDD_UD_177                                               */
/* Implements:  EAAR_PN0066_FR_0001                                           */
/* Implements:  EAAR_PN0066_FR_0071, EAAR_PN0066_FR_0004, EAAR_PN0066_FR_0005 */
/* Implements:  EAAR_PN0034_FSR_0006, EAAR_PN0034_FSR_0007                    */

/* Implements:  PWM_ESDD_UD_005, PWM_ESDD_UD_015, PWM_ESDD_UD_011             */
/* Implements:  PWM_ESDD_UD_031                                               */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "Pwm.h"
/* Included for Header file inclusion */
#include "Pwm_LLDriver.h"
/* Included for RAM variable declarations */
#include "Pwm_Ram.h"
/* Implements:  PWM066a, PWM066b, SWS_Pwm_00104, PWM104, PWM005, PWM066c      */
/* Included for the declaration of Dem_ReportErrorStatus() */
#include "Dem.h"
/* Implements:  PWM_ESDD_UD_133                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)
/* Included for RAM variable declarations */
#include "Pwm_Diagnostic.h"
#endif
/* Implements: PWM_ESDD_UD_042, EAAR_PN0066_FR_0043, EAAR_PN0034_FR_0061      */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0066  */
/* Implements: EAAR_PN0034_FR_0066, PWM079, SWS_Pwm_00079                     */
#if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Pwm.h"
#endif
/* Implements: EAAR_PN0034_FR_0081                                            */
#include "Iocommon_Defines.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* AUTOSAR 4.2 release version information */
#define PWM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
                                              PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
                                              PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION_VALUE

#elif (PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR specification version information */
#define PWM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
                                              PWM_AR_RELEASE_MAJOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
                                              PWM_AR_RELEASE_MINOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
                                           PWM_AR_RELEASE_REVISION_VERSION_VALUE
#endif

/* Module software version information */
#define PWM_LLDRIVER_C_SW_MAJOR_VERSION  PWM_SW_MAJOR_VERSION_VALUE
#define PWM_LLDRIVER_C_SW_MINOR_VERSION  PWM_SW_MINOR_VERSION_VALUE

/* Implements:  EAAR_PN0034_FR_0055                                           */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_LLDRIVER_AR_RELEASE_MAJOR_VERSION != \
                                        PWM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (PWM_LLDRIVER_AR_RELEASE_MINOR_VERSION != \
                                        PWM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (PWM_LLDRIVER_AR_RELEASE_REVISION_VERSION != \
                                    PWM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Release Patch Version"
#endif

#if (PWM_LLDRIVER_SW_MAJOR_VERSION != PWM_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (PWM_LLDRIVER_SW_MINOR_VERSION != PWM_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Software Minor Version"
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
/* Message       : (4:0489) [I] Increment or decrement operation performed on */
/*                 pointer.                                                   */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Increment operator is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-1 and                           */
/*                 END Msg(4:0489)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0311) Dangerous pointer cast results in loss of const   */
/*                 qualification.                                             */
/* Rule          : MISRA-C:2004 Rule 11.5                                     */
/* Justification : This is to achieve throughput in the code.                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0311)-2 and                           */
/*                 END Msg(4:0311)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To access channel parameters in an optimized approach.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-3 and                           */
/*                 END Msg(4:0488)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4491) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned short) is being converted to wider.         */
/*                 unsigned type, 'unsigned long' on assignment.              */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : The resultant value obtained because of arithmetic         */
/*                 operation can be wider than operand type.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4491)-4 and                           */
/*                 END Msg(4:4491)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) [I] A cast should not be performed between a      */
/*                 pointer type and an integral type.                         */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:0303)-5 and                           */
/*                 END Msg(4:0303)-5 tags in the code.                        */

/******************************************************************************/

/* 6.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0310) Casting to different object pointer type.         */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/*                 REFERENCE - ISO-6.3.4                                      */
/* Justification : This is to access the CTL reg of type 8 bit.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-6 and                           */
/*                 END Msg(4:0310)-6 tags in the code.                        */

/******************************************************************************/

/* 7.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0316)Cast from a pointer to void to a pointer to object */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-7 and                           */
/*                 END Msg(4:0316)-7 tags in the code.                        */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 10.5                                          */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex        */
/*                 bitwise operations.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-8 and                           */
/*                 END Msg(4:4397)-8 tags in the code.                        */

/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2877) This loop will only be executed once and so the   */
/*                 loop mechanism is redundant.                               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-9 and                           */
/*                 END Msg(4:2877)-9 tags in the code.                        */

/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983) Assignment is redundant. The value of this object */
/*                 is never subsequently used.                                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The object is used under different pre-compile sections.   */
/*                 However, for different configurations this warning ceases  */
/*                 to exist.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-10 and                          */
/*                 END Msg(4:2983)-10 tags in the code.                       */

/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982) Assignment is redundant. The value of this object */
/*                 is never used before being modified.                       */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The object is used under different pre-compile sections.   */
/*                 However, for different configurations this warning ceases  */
/*                 to exist.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-11 and                          */
/*                 END Msg(4:2982)-11 tags in the code.                       */

/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2991) The value of this 'if' controlling expression is  */
/*                  always 'true'.                                            */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is true because  */
/*                 of the variable updated in pre-compile condition. The      */
/*                 variable can be configured at pre-compile for false value  */
/*                 in If condition                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-12 and                          */
/*                 END Msg(4:2991)-12 tags in the code.                       */

/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'..                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is true because  */
/*                 of the variable updated in pre-compile condition. The      */
/*                 variable can be configured at pre-compile for false value  */
/*                 in If condition                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-13 and                          */
/*                 END Msg(4:2995)-13 tags in the code.                       */

/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : The code can be accessed if the logical conditional check  */
/*                 in which this is found is true. Code may or may not be     */
/*                 accessible depending on the pre compile value used in the  */
/*                 logical condition.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-14 and                          */
/*                 END Msg(4:2880)-14 tags in the code.                       */

/******************************************************************************/

/*15. MISRA C RULE VIOLATION:                                                 */
/*Message       : (4:2985) This operation is redundant. The value of the      */
/*                result is always that of the left-hand operand.             */
/*Rule          : MISRA-C:2004 Rule 21.1                                      */
/*Justification : The value of the local variable accessed changes with       */
/*                configuration.                                              */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:2985)-15 and END Msg(4:2985)-15 tags   */
/*                in the code.                                                */

/******************************************************************************/

/* 16. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0491) An array subscript operator is being used to      */
/*                 subscript an expression which is not of array type.        */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This pointer addresses an array element                    */
/* Verification  : It is verified manually and by generation tool             */
/* Reference     : Look for START Msg(4:0491)-16 and END Msg(4:0491)-16       */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 17. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0715)Nesting of control structures (statements)         */
/*                 exceeds 15 - program is non-conforming.                    */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : It is used to achieve better throughput instead of         */
/*                 invoking a function call.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0715)-17 and                          */
/*                 END Msg(4:0715)-17 tags in the code.                       */

/******************************************************************************/

/* 18. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3138) Null statement is located close to other code     */
/*                  or comments                                               */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical          */
/*                 section macro to avoid static analysis warning             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-18 and                          */
/*                 END Msg(4:3138)-18 tags in the code.                       */
/******************************************************************************/

/* 20. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3344) Controlling expression is not an 'essentially     */
/*                  Boolean' expression.                                      */
/* Rule          : MISRA-C:2004 Rule 13.2                                     */
/* Justification : It checks the value of a bit, that can be 0 or 1           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3344)-20 and                          */
/*                 END Msg(4:3344)-20 tags in the code.                       */
/******************************************************************************/

/* 21. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2792) Apparent: Right hand operand of shift operator is */
/*                  negative or too large.                                    */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Assure in the configuration part, maximmum 32 diagnosis    */
/*                 channel per group                                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2792)-21 and                          */
/*                 END Msg(4:2792)-21 tags in the code.                       */
/******************************************************************************/
/* 22. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4394) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned char) is being cast to a different          */
/*                 type category, 'enum'.                                     */
/* Rule          : MISRA-C:2004 Rule 10.3                                     */
/* Justification : Type of the LddPrevClockSource variable                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4394)-22 and                          */
/*                 END Msg(4:4394)-22 tags in the code.                       */
/******************************************************************************/

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Rule          : NA                                                         */
/* Justification : The result of this cast is implicitly converted            */
/*                 to another type.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-1 and              */
/*                 END Msg(2:3892)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning  START Msg(2:2814)-2 and              */
/*                 END Msg(2:2814)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR  and vendor             */
/*                 specific Api's cannot be modified to be made as constant.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3227)-3 and               */
/*                 END Msg(2:3227)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:2824)-4 and               */
/*                 END Msg(2:2824)-4  tags in the code.                       */
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
/* 7. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Rule          : NA                                                         */
/* Justification : All the possible values are covered specifically in each   */
/*                 and default case will not be reachable and this is reviewed*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2016)-7 and              */
/*                 END Msg(2:2016)-7 tags in the code.                        */
/******************************************************************************/
/* 8. QAC Warning:                                                            */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-8 and              */
/*                 END Msg(2:0890)-8 tags in the code.                        */
/******************************************************************************/
/* 9. QAC Warning:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: QAC Warning: START Msg(2:2022)-9 and */
/*                 END Msg(2:2022)-9 tags in the code.                        */
/******************************************************************************/
/* 10. QAC Warning:                                                           */
/* Message       : (2:1252) Suffixed integer constant implicitly converted to */
/*                 different integer type.                                    */
/* Rule          : NA                                                         */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1252)-10 and                          */
/*                 END Msg(2:1252)-10 tags in the code.                       */
/******************************************************************************/
/* 11. QAC Warning:                                                           */
/* Message       : (2:4342) An expression of 'essentially unsigned' type      */
/*                 (unsigned char) is being cast to enum type                 */
/*                 'ETag_Pwm_ClockSourceType.                                 */
/* Justification : Type of the LddPrevClockSource variable                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:4342)-11 and                          */
/*                 END Msg(2:4342)-11 tags in the code.                       */
/*******************************************************************************
**                      Global array Definitions                              **
*******************************************************************************/
#define PWM_START_SEC_VAR_NO_INIT_8
/* Implements:  EAAR_PN0034_NR_0087                                           */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
/* QAC Warning: START Msg(2:2022)-9 */
/* Global array to store PwmDiagChannelId data */
VAR(uint8, Pwm_NOINIT_DATA)
Pwm_GaaDiagChannelMap[PWM_MAX_DIAG_CHANNELS];
/* END Msg(2:2022)-9 */
#endif /* End of #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON) */

#define PWM_STOP_SEC_VAR_NO_INIT_8
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Pwm_HW_Init
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function sets the clock pre-scaler, PWM mode,
**                         Period, Duty cycle and polarity for all configured
**                         channels. This function also disables the interrupts
**                         (Notifications) and resets the interrupt request
**                         pending flags.
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
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDBUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpSynchStartConfig, Pwm_GpChannelConfig,
**                         Pwm_GaaNotifStatus, Pwm_GaaChannelCurrDutyCycle,
**                         Pwm_GpDiagUnitConfig, Pwm_GpDiagChannelConfig,
**                         Pwm_GusIntSelRegMask, Pwm_GaaChannelConstantStatus,
**                         Pwm_GaaChannelConstantState,
**                         Pwm_GaaChannelCRDRRestoreVal,
**                         Pwm_GaaChannelCSDRRestoreVal, Pwm_GaaChannelCTDRVal,
**                         Pwm_GulGroup0, Pwm_GulGroup1, Pwm_GulGroup2
**
** Functions invoked     : Pwm_HW_CalculateDuty, Pwm_HW_StartDiagChannel
**                         Dem_ReportErrorStatus
**
** Registers Used        : TAUDnTPS, TAUBnTPS, TAUDnBRS, TAUDnCDRm, TAUBnCDRm,
**                         TAUDnTE, TAUBnTE, TAUDnCMORm, TAUBnCMORm, TAUDnTT,
**                         TAUBnTT, TAUDnTOE, TAUBnTOE, TAUDnTO, TAUBnTO,
**                         TAUDnTOM, TAUBnTOM, TAUDnTOC, TAUBnTOC, TAUDnTOL,
**                         TAUBnTOL, TAUDnRDE, TAUBnRDE, TAUDnTS, TAUBnTS,
**                         TAUJnTPS, TAUJnBRS, TAUJnCDRm, TAUJnTE, TAUJnCMORm,
**                         TAUJnTT, TAUJnTOE, TAUJnTO, TAUJnTOM, TAUJnTOC,
**                         TAUJnTOL, TAUJnRDE, TAUJnTS, SELB_INTC2,
**                         PWBAnBRS0, PWBAnBRS1, PWBAnBRS2, PWBAnBRS3,
**                         PWGAINTMSK00, PWGAINTMSK01, PWGAINTMSK02, PWGAPRD,
**                         PWGAPRDSL0, PWGAPRDSL1, PWGAPRDSL2, PWGAnCSDR,
**                         PWGAnCRDR, PWGAnCTL, PWGAnTCR, PWBAnTS, PWBAnTE.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_110, EAAR_PN0066_FR_0054                          */
/* Implements:  PWM_ESDD_UD_012, PWM_ESDD_UD_143                              */
#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* QAC Warning: START Msg(2:0890)-8 */
/* Functionality related to R4.0 */
#include "MemMap.h"
/* END Msg(2:0890)-8 */
#endif

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Init(void)
{
  /* Implements:  PWM_ESDD_UD_183                                             */
  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint8 LucCntlRegs;
  uint8 LucOsCntlRegsIndx;
  uint8 LucUserCntlRegsIndx;
  /* Implements: PWM070, SWS_Pwm_00070                                        */
  Pwm_PeriodType LddMasterPeriod;
  Pwm_PeriodType LddSlaveDuty;
  Pwm_PeriodType LddCalculateDuty;
  uint16 LusTempReg;
  uint8 LucVar;
  #endif

  /* Implements:  PWM_ESDD_UD_053, PWM_ESDD_UD_054                            */
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;

  uint8 LucTAUDBMasterChannelReg;
  uint16 LusDefaultPeriodOrDuty;
  uint16 LusTAUDBDefaultPeriod;
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  #endif

  /* Implements:  PWM_ESDD_UD_055                                             */
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;

  uint8 LucTAUJMasterChannelReg;
  uint32 LulDefaultPeriodOrDuty;
  uint32 LulTAUJDefaultPeriod;

  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  uint8 LucDiagGeneratortCntlRegs;
  uint8 LucDiagChannel;
  uint8 LucDiagSaveCount;
  uint16 LusDutyCycle;
  uint16 LusOffset;
  uint16 LusDiagResetTriggerPoint;
  uint16 LusDiagPeriod;
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  uint8 LucPwmShift;
  /* Implements:  PWM_ESDD_UD_222                                             */
  /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA)
                                                       LpDiagSyncStartCntlRegs;
  #endif
  #endif

  uint8_least LucCount;

  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  uint8 LucLoopCount;
  uint8 LucDiagchannelNo;
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelGrpConfig;

  /* Update PWGA Channel pointer to point to first channel in configuration */
  LpDiagChannelGrpConfig = Pwm_GpDiagChannelConfig;
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Update TAUD/TAUB unit config pointer to point to the base TAUDB unit */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update TAUJ unit config pointer to point to the base TAUJ unit */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Update PWGA unit config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;

  /* Update PWGA Channel pointer to point to first channel in configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  /* Implements:  PWM_ESDD_UD_222                                             */
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Point to base address of SLPWGAm register */
  LpDiagSyncStartCntlRegs =
         ((volatile SLPWGAReg *) Pwm_GpDiagUnitConfig->pDiagSyncStartCntlRegs);
  /* END Msg(2:2814)-2 */
  #endif
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Update TAU Channel pointer to point to first channel in configuration */
  LpChannelConfig = Pwm_GpChannelConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Implements: PWM_ESDD_UD_229                                              */
  #if (PWM_SELB_INTC2_SUPPORT == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-5 */
  /* Implements: EAAR_PN0034_FR_0068                                          */
  SetIORegSyncpDummyRead(16,&(PWM_SELB_INTC2),Pwm_GusIntSelRegMask);
  /* END Msg(4:0303)-5 */
  #endif
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* Implements:  PWM_ESDD_UD_123, PWM_ESDD_UD_124, EAAR_PN0066_FR_0015     */
    /* Implements:  EAAR_PN0066_FR_0023                                       */
    #if (PWM_TAUD_PRESCALER == STD_ON) || (PWM_TAUB_PRESCALER == STD_ON)

    /* Check for pre-scaler setting by the PWM module for TAUDn/TAUBn Unit */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (PWM_TRUE == LpTAUDBUnitConfig->blConfigurePrescaler)
    /* END Msg(2:2814)-2 */
    {
      LucOsCntlRegsIndx = LpTAUDBUnitConfig->ucOsCntlRegsIndx;
      /* Load the configured pre-scalar value */
      PWM_WRITE_REG_ONLY(
                       &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS,
                          LpTAUDBUnitConfig->usPrescaler)
      PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                      (&Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS,
                          LpTAUDBUnitConfig->usPrescaler,
                          PWM_TAUDB_MASK_TPS,
                          PWM_INIT_SID)
      /* Implements: PWM_ESDD_UD_123, EAAR_PN0066_FR_0015, EAAR_PN0066_FR_0023*/
      #if (PWM_TAUD_PRESCALER == STD_ON)
      if (PWM_HW_TAUD == LpTAUDBUnitConfig->uiPwmTAUType)
      {
        /* Load the configured baudrate value */
        PWM_WRITE_REG_ONLY(
                       &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS,
                            LpTAUDBUnitConfig->ucBaudRate)
        PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                      (&Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS,
                            LpTAUDBUnitConfig->ucBaudRate,
                            PWM_TAUD_MASK_BRS,
                            PWM_INIT_SID)
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
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2982)-11 */
    /* Increment the pointer to the next TAUD/TAUB Unit */
    LpTAUDBUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2982)-11 */
  }
  /* END Msg(4:2877)-9 */

  #endif

  /* Implements:  PWM_ESDD_UD_125, EAAR_PN0066_FR_0023                        */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Implements:  EAAR_PN0066_FR_0015                                         */
  #if (PWM_TAUJ_PRESCALER == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* Loop to set the configured pre-scaler for the TAUJ units */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* Check for pre-scaler setting by the PWM module for TAUJn Unit */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (PWM_TRUE == LpTAUJUnitConfig->blConfigurePrescaler)
    /* END Msg(2:2814)-2 */
    {
      LucOsCntlRegsIndx = LpTAUJUnitConfig->ucOsCntlRegsIndx;

      /* Load the configured pre-scaler value */
      PWM_WRITE_REG_ONLY(
                      &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS,
                       LpTAUJUnitConfig->usPrescaler)
      PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                      &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS,
                       LpTAUJUnitConfig->usPrescaler,
                       PWM_TAUJ_MASK_TPS,
                       PWM_INIT_SID)

      /* Load the configured baudrate value */
      PWM_WRITE_REG_ONLY(
                      &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS,
                       LpTAUJUnitConfig->ucBaudRate)
      PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                      &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS,
                       LpTAUJUnitConfig->ucBaudRate,
                       PWM_TAUJ_MASK_BRS,
                       PWM_INIT_SID)
    }
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2982)-11 */
    /* Increment the pointer to the next TAUJ Unit */
    LpTAUJUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2982)-11 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)

  /* QAC Warning: START Msg(2:2814)-2 */
  /* Set the configured pre-scalar settings of PWGA unit */
  PWM_WRITE_REG_ONLY(&Pwm_GaaPWBAReg_BaseAddress->usBRS0,
                      LpDiagUnitConfig->usDiagPrescalerCk0)
  /* END Msg(2:2814)-2 */
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaPWBAReg_BaseAddress->usBRS0,
                      LpDiagUnitConfig->usDiagPrescalerCk0,
                      PWM_PWBA_MASK_BRS,
                      PWM_INIT_SID)

  PWM_WRITE_REG_ONLY(&Pwm_GaaPWBAReg_BaseAddress->usBRS1,
                      LpDiagUnitConfig->usDiagPrescalerCk1)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaPWBAReg_BaseAddress->usBRS1,
                      LpDiagUnitConfig->usDiagPrescalerCk1,
                      PWM_PWBA_MASK_BRS,
                      PWM_INIT_SID)

  PWM_WRITE_REG_ONLY(&Pwm_GaaPWBAReg_BaseAddress->usBRS2,
                      LpDiagUnitConfig->usDiagPrescalerCk2)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaPWBAReg_BaseAddress->usBRS2,
                      LpDiagUnitConfig->usDiagPrescalerCk2,
                      PWM_PWBA_MASK_BRS,
                      PWM_INIT_SID)

  PWM_WRITE_REG_ONLY(&Pwm_GaaPWBAReg_BaseAddress->usBRS3,
                      LpDiagUnitConfig->usDiagPrescalerCk3)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaPWBAReg_BaseAddress->usBRS3,
                      LpDiagUnitConfig->usDiagPrescalerCk3,
                      PWM_PWBA_MASK_BRS,
                      PWM_INIT_SID)

  /* Implements:  PWM_ESDD_UD_227                                             */
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  for (LucLoopCount = PWM_ZERO; LucLoopCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG; \
      LucLoopCount++)
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get Pwm Diag channel number*/
    LucDiagchannelNo = LpDiagChannelGrpConfig->ucDiagChannel;
    /* END Msg(2:2814)-2 */

    /* Implements:  PWM_ESDD_UD_175                                           */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* Store Pwm Diag channel ids*/
    Pwm_GaaDiagChannelMap[LucDiagchannelNo] = LucLoopCount + \
                                              PWM_TOTAL_TAU_CHANNELS_CONFIG;
    /* END Msg(4:2985)-15 */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /*Point to next Pwm Diag channel configuration*/
    LpDiagChannelGrpConfig++;
    /* END Msg(4:0489)-1 */

  }
  #if (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE)
  /* QAC Warning: START Msg(2:3892)-1 */
  /* Update mirror values as per registers PWGAINTMSK0k (where k=0,1,2)*/
  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00 =
                       Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK;

  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01 =
                       Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK;

  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02 =
                       Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK;
  /* END Msg(2:3892)-1 */

  #endif
  #endif /*End of #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)*/

  /* Implements:  PWM_ESDD_UD_222                                             */
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Set the configured period selection value to PWGA unit */
  PWM_WRITE_REG_ONLY(&LpDiagSyncStartCntlRegs->ulPWGAPRD,
                      LpDiagUnitConfig->usDiagPeriod)
  /* END Msg(2:2814)-2 */
  /* QAC Warning: START Msg(2:3892)-1 */
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&LpDiagSyncStartCntlRegs->ulPWGAPRD,
                      LpDiagUnitConfig->usDiagPeriod,
                      PWM_DIAG_MAX_COUNT,
                      PWM_INIT_SID)
  /* END Msg(2:3892)-1 */

  /* Set the channels configured for period selection value to PWGA unit */
  PWM_WRITE_REG_ONLY(&LpDiagSyncStartCntlRegs->ulPWGAPRDSL0, Pwm_GulGroup0)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&LpDiagSyncStartCntlRegs->ulPWGAPRDSL0, Pwm_GulGroup0,
                      PWM_SLPWG_MASK_PWGAPRDSL, PWM_INIT_SID)

  PWM_WRITE_REG_ONLY(&LpDiagSyncStartCntlRegs->ulPWGAPRDSL1, Pwm_GulGroup1)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&LpDiagSyncStartCntlRegs->ulPWGAPRDSL1, Pwm_GulGroup1,
                      PWM_SLPWG_MASK_PWGAPRDSL, PWM_INIT_SID)

  PWM_WRITE_REG_ONLY(&LpDiagSyncStartCntlRegs->ulPWGAPRDSL2, Pwm_GulGroup2)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                    (&LpDiagSyncStartCntlRegs->ulPWGAPRDSL2, Pwm_GulGroup2,
                      PWM_SLPWG_MASK_PWGAPRDSL, PWM_INIT_SID)
  #endif /*End of #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)*/

  LucDiagSaveCount = PWM_MIN_DIAG_CHANNELS_CONFIG_ID;

  /* Implements:  PWM_ESDD_UD_181                                             */
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* Initialize default value in global buffer used to store PWGA channel
     CTDR value */
  for (LucCount = PWM_ZERO; LucCount < (uint8)PWM_TOTAL_DIAG_CHANNELS;
                                                                     LucCount++)
  /* END Msg(2:3892)-1 */
  {
    Pwm_GaaChannelCTDRVal[LucCount] = PWM_CTDR_DEFAULT_VALUE;
  }
  /* END Msg(4:2877)-9 */
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Initialize global variables for PWGA channels */
  for (LucCount = PWM_ZERO;
                     LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Set the Notification status as PWM_FALSE */
    Pwm_GaaNotifStatus[LucDiagSaveCount] = PWM_FALSE;
    #endif
    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    /* Initialize the Constant state status of this channel as PWM_FALSE */
    Pwm_GaaChannelConstantStatus[LucDiagSaveCount] = PWM_FALSE;
    #endif

    /* QAC Warning: START Msg(2:3892)-1 */
    /* Initialize the CRDR restore values of this channel with PWM_ZERO */
    Pwm_GaaChannelCRDRRestoreVal[LucCount] = PWM_ZERO;
    /* Initialize the CSDR restore values of this channel with PWM_ZERO */
    Pwm_GaaChannelCSDRRestoreVal[LucCount] = PWM_ZERO;
    /* END Msg(2:3892)-1 */

    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    /* Initialize the Constant state of this channel with PWM_LOW */
    Pwm_GaaChannelConstantState[LucCount] = PWM_LOW;
    #endif
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Initialize global variables to 0 */
    /* QAC Warning: START Msg(2:3892)-1 */
    Pwm_GaaPWGACSDR[LucCount] = PWM_ZERO;
    Pwm_GaaPWGACRDR[LucCount] = PWM_ZERO;

    Pwm_GaaDCBoundaryFlag[LucCount] = PWM_FALSE;

    LucDiagSaveCount++;
    /* END Msg(4:2983)-10 */
    /* END Msg(2:3892)-1 */
  }
  /* END Msg(4:2877)-9 */
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Loop to set the attributes of PWGA channels */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                  LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagGeneratortCntlRegs =
                             LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* END Msg(2:2814)-2 */
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set attributes of PWGA channels which are not to be started
       synchronously */
    if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) &&
                        (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
    #endif
    {
      /* Get the Duty Cycle in to the local variable */
      LusDutyCycle = LpDiagChannelConfig->usDutyCycle;

      /* Get the Set condition value in to the local variable */
      LusOffset = LpDiagChannelConfig->usOffset;

      /* Implements:  PWM_ESDD_UD_162                                         */
      /* Check for PWM polarity configured */
      if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
      {
        /* Load the Set condition value to the CSDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_INIT_SID)
        #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
        LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
        LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
        #else
        LusDiagPeriod = PWM_DIAG_MAX_COUNT;
        #endif
        /* calculate reset trigger point for PWM Diag */
        LusDiagResetTriggerPoint =
                      Pwm_HW_CalDiagResetTriggerPoint (LusDutyCycle, LusOffset,
                      LusDiagPeriod);
        /* Load the Reset condition value to the CRDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusDiagResetTriggerPoint,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusDiagResetTriggerPoint,
                      PWM_PWGA_MASK_CRDR,
                      PWM_INIT_SID)
      }
      else
      {
        if (MIN_DUTY_CYCLE == LusDutyCycle)
        {
          /* Load the Reset condition value with 0x1FFF */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                      PWM_PWGA_MASK_CRDR,
                      PWM_INIT_SID)
          /* END Msg(2:3892)-1 */
          Pwm_GaaChannelCRDRRestoreVal[LucCount] = LusOffset;
        }
        else if (MAX_DUTY_CYCLE == LusDutyCycle)
        {
          /* Load the Set condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_INIT_SID)

          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_INIT_SID)
        }
        else
        {
          /* Load the Set condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_INIT_SID)
          #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
          LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
          LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
          #else
          LusDiagPeriod = PWM_DIAG_MAX_COUNT;
          #endif

          /* calculate set trigger point for PWM Diag */
          LusDiagResetTriggerPoint =
                      Pwm_HW_CalDiagResetTriggerPoint (LusDutyCycle, LusOffset,
                      LusDiagPeriod);
          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusDiagResetTriggerPoint,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT
               (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusDiagResetTriggerPoint,
                      PWM_PWGA_MASK_CSDR,
                      PWM_INIT_SID)
        }
      }

      /* Get the PWGA channel configured in to the local variable */
      LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

      /* Get the A/D Trigger delay value in to the local variable */
      LusOffset = LpDiagChannelConfig->usTriggerDelay;

      /* Load the A/D Trigger delay value to the CTDR global buffer */
      Pwm_GaaChannelCTDRVal[LucDiagChannel] = LusOffset;

      /* Load the Selected count clock from PWBA0 for the pre-scalar settings */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
                  LpDiagChannelConfig->ucDiagClockCtl,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucCTL)
      PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
                  LpDiagChannelConfig->ucDiagClockCtl,
                  PWM_PWGA_MASK_CTL,
                  PWM_INIT_SID)
    }
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    else
    {
      /* No action required */
    }
    #endif

    #if (PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON)
    /* Disable trigger out */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
               &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
               PWM_PWGA_TRGOUT_DISABLE,
               &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucTCR)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
               &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                PWM_PWGA_TRGOUT_DISABLE,
                PWM_PWGA_MASK_TCR,
                PWM_INIT_SID)
    /* END Msg(2:3892)-1 */
    #endif

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Set the Notification status as PWM_FALSE */
    Pwm_GaaNotifStatus[LucCount] = PWM_FALSE;
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }
   /* END Msg(4:2877)-9 */

  /* Start trigger the configured pre-scalar clocks */
  PWM_WRITE_REG_ONLY(
             &Pwm_GaaPWBAReg_BaseAddress->ucTS,
              LpDiagUnitConfig->ucDiagStartTrgPrescaler)
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT
            (&Pwm_GaaPWBAReg_BaseAddress->ucTE,
              LpDiagUnitConfig->ucDiagStartTrgPrescaler,
              PWM_PWBA_MASK_TE,
              PWM_INIT_SID)

  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Loop to set the target channels for start the count trigger */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                    LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Start trigger count for channels which are not to be started
       synchronously */
    if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) &&
                        (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
    #endif
    {
      /* Get the PWGA channel configured in to the local variable */
      LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

      /* Invoke internal function to start a PWM PWGA channel */
      Pwm_HW_StartDiagChannel(LucDiagChannel, PWM_INIT_SID);
    }
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    else
    {
      /* No action required */
    }
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }
  /* END Msg(4:2877)-9 */

  #if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)
  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Initialize duty cycle in global buffer */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                     LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    Pwm_GaaChannelCurrDutyCycle[LucCount] = LpDiagChannelConfig->usDutyCycle;

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)

  /* Loop to set the attributes of TAUD/TAUB/TAUJ channels */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAU_CHANNELS_CONFIG;
                                                                     LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set attributes of TAUD/TAUB/TAUJ channels which are not to be started
       synchronously or set for complex driver usage */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:2814)-2 */
    if ((PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode) ||
        ((PWM_FALSE == LpChannelConfig->blSyncStartReq) &&
                           (PWM_FALSE == LpChannelConfig->blComplexDriverInit)))
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    #endif
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:3892)-1 */
      {
        #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
        (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                            LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        /* Check TAUD/B channel is in stopped state */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* QAC Warning: START Msg(2:2814)-2 */
        if (PWM_TAUDB_CH_STOPPED ==
                    (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE
                                            & LpTAUDBProperties->usChannelMask))
        /* END Msg(2:3892)-1 */
        /* END Msg(2:2814)-2 */
        {
          /* Update CMORm register based on configuration */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                          &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                          &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                         (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                           PWM_TAUDB_MASK_CMOR,
                           PWM_INIT_SID)
        }
        else
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          /* calculate new value for TE register */
          LusTempReg =
                Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                      (~LpTAUDBProperties->usChannelMask);
          /* END Msg(4:4397)-8 */

          /* Stop the count operation */
          PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                         LpTAUDBProperties->usChannelMask)

          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                         LusTempReg,
                         PWM_TAUDB_MASK_TE,
                         PWM_INIT_SID)

          /* Check TAUD/B channel is in stopped state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUDB_CH_STOPPED ==
                    (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE
                                            & LpTAUDBProperties->usChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* Update CMORm register based on configuration */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                          &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                          &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
            PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                         (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                           PWM_TAUDB_MASK_CMOR,
                           PWM_INIT_SID)
          }
          else
          {
            /* Implements: PWM_ESDD_UD_189                                    */
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
        }

        /* Implements:  EAAR_PN0066_FR_0013, EAAR_PN0066_FR_0016              */
        /* Check for channel in the Master Mode */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* QAC Warning: START Msg(2:2814)-2 */
        if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
        {
          /* Implements:  PWM009a, SWS_Pwm_10009 */
          LusTAUDBDefaultPeriod =
                           (uint16)(LpTAUDBProperties->ddDefaultPeriodOrDuty);

          /* Check for the period value of the Master is not zero */
          if (PWM_TAUDB_MIN_PERIOD != LusTAUDBDefaultPeriod)
          {
            /* Implements:  PWM009a, SWS_Pwm_10009 */
            LusDefaultPeriodOrDuty = (uint16)(LusTAUDBDefaultPeriod - PWM_ONE);
          }
          else
          {
            LusDefaultPeriodOrDuty = LusTAUDBDefaultPeriod;
          }

          /* Update CDRm register with default period based on configuration */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                          &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                          LusDefaultPeriodOrDuty,
                          &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     LusDefaultPeriodOrDuty,
                     PWM_TAUDB_MASK_CDR,
                     PWM_INIT_SID)
        }
        /* END Msg(2:2814)-2 */
        /* END Msg(2:3892)-1 */
        /* Channel in Slave Mode */
        else
        {
          /* Master offset from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Pointer to the Master channel registers */
          LucTAUDBMasterChannelReg = (LpChannelConfig - LucVar)->ucCntlRegsIndx;
          /* END Msg(4:0488)-3 */

          /* Get Master's period */
          LddMasterPeriod =
                 Pwm_GaaTAUDBChReg_BaseAddress[LucTAUDBMasterChannelReg]->usCDR;
          /* Get Slave's Duty */
          LddSlaveDuty = LpTAUDBProperties->ddDefaultPeriodOrDuty;
          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          /* calculate duty cycle */
          /* QAC Warning: START Msg(2:3892)-1 */
          LddCalculateDuty =
            (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
          /* END Msg(2:3892)-1 */
          /* Implements:  PWM009a, SWS_Pwm_10009 */
          /* Load the Absolute duty value in to the CDR Register */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                          &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                           (uint16)LddCalculateDuty,
                          &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                         (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                           (uint16)LddCalculateDuty,
                           PWM_TAUDB_MASK_CDR,
                           PWM_INIT_SID)
          /* END Msg(2:3892)-1 */
        }
      #endif
      }

      /* QAC Warning: START Msg(2:3892)-1 */
      else if (PWM_HW_TAUJ == (uint8)LpChannelConfig->uiPwmTAUType)
      /* END Msg(2:3892)-1 */
      {
        #if (PWM_TAUJ_UNIT_USED == STD_ON)
        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        LpTAUJProperties =
            (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                    LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        /* Check TAUJ channel is in stopped state */
        /* QAC Warning: START Msg(2:3892)-1 */
        if (PWM_TAUJ_CH_STOPPED ==
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                               LpTAUJProperties->ucChannelMask))
        /* END Msg(2:3892)-1 */
        {
          /* Update the CMORm register based on the configuration */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LpChannelConfig->usCMORegSettingsMask,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                       &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                        LpChannelConfig->usCMORegSettingsMask,
                        PWM_TAUJ_MASK_CMOR,
                        PWM_INIT_SID)
        }
        else
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          /* MISRA Violation: START Msg(4:4491)-4 */
          /* calculate new value for TE register */
          LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                             (~LpTAUJProperties->ucChannelMask);
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          /* END Msg(4:4397)-8 */
          /* END Msg(4:4491)-4 */
          /* Stop the count operation using WV */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                         LpTAUJProperties->ucChannelMask)

          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                  PWM_INIT_SID)
          /* END Msg(2:3892)-1 */

          /* Check TAUJ channel is in stopped state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUJ_CH_STOPPED ==
                     (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE
                                             & LpTAUJProperties->ucChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* Update the CMORm register based on the configuration */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                         &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                          LpChannelConfig->usCMORegSettingsMask,
                         &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
            PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                         &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                          LpChannelConfig->usCMORegSettingsMask,
                          PWM_TAUJ_MASK_CMOR,
                          PWM_INIT_SID)
          }
          else
          {
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
        }

        /* Check for channel in the Master Mode*/
        /* QAC Warning: START Msg(2:3892)-1 */
        /* QAC Warning: START Msg(2:2814)-2 */
        if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
        {
          /* Implements:  PWM009a, SWS_Pwm_10009 */
          LulTAUJDefaultPeriod =
                            (uint32)(LpTAUJProperties->ddDefaultPeriodOrDuty);

          /* Check for the period value of the Master is not zero */
          if (PWM_TAUJ_MIN_PERIOD != LulTAUJDefaultPeriod)
          {
            /* Implements:  PWM009a, SWS_Pwm_10009 */
            LulDefaultPeriodOrDuty = (uint32)(LulTAUJDefaultPeriod - PWM_ONE);
          }
          else
          {
            LulDefaultPeriodOrDuty = LulTAUJDefaultPeriod;
          }

          /* Update CDRm register with default period based on configuration */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LulDefaultPeriodOrDuty,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LulDefaultPeriodOrDuty,
                         PWM_TAUJ_MASK_CDR,
                         PWM_INIT_SID)
        }
        /* END Msg(2:3892)-1 */
        /* END Msg(2:2814)-2 */
        /* Channel in Slave Mode */
        else
        {
          /* Master offset from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          LucTAUJMasterChannelReg = (LpChannelConfig - LucVar)->ucCntlRegsIndx;
          /* END Msg(4:0488)-3 */

          /* Get Master's period */
          LddMasterPeriod =
                   Pwm_GaaTAUJChReg_BaseAddress[LucTAUJMasterChannelReg]->ulCDR;

          /* Get Slave's Duty */
          LddSlaveDuty = LpTAUJProperties->ddDefaultPeriodOrDuty;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          /* calculate duty cycle */
          LddCalculateDuty =
                    Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
          /* Implements:  PWM009a, SWS_Pwm_10009 */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                         LddCalculateDuty,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                         LddCalculateDuty,
                         PWM_TAUJ_MASK_CDR,
                         PWM_INIT_SID)
        }
        #endif
      }
      else
      {
        /* No action required */
      }
    }
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    else
    {
      /* No action required */
    }
    #endif

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Implements:  PWM052, SWS_Pwm_00052 */
    /* Set the Notification status as PWM_FALSE */
    Pwm_GaaNotifStatus[LucCount] = PWM_FALSE;
    #endif

    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    /* Initialize the Constant state status of this channel as PWM_FALSE */
    Pwm_GaaChannelConstantStatus[LucCount] = PWM_FALSE;
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to the next channel */
    LpChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

  /* Update TAUD/TAUB unit config pointer to point to the base TAUDB unit */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {

    LucUserCntlRegsIndx = LpTAUDBUnitConfig->ucUserCntlRegsIndx;
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* Set the corresponding bits to enable/disable TOm operation */
    LusTempReg = (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                             (~(LpTAUDBUnitConfig->usTOEMask)));
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                 &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOE,
                  PWM_INIT_SID)

    /* END Msg(4:4397)-8 */
    /* Set the corresponding bits as per the configured Idle state */
    LusTempReg = ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                             ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask))) |
                                                   LpTAUDBUnitConfig->usTOMask);
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                  LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                  LusTempReg,
                  PWM_TAUDB_MASK_TO,
                  PWM_INIT_SID)

    LucOsCntlRegsIndx = LpTAUDBUnitConfig->ucOsCntlRegsIndx;
    /* Set the Mode (Synchronous/Independent channel operation mode) */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM |
                                                  LpTAUDBUnitConfig->usTOMMask);
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM,
                  LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOM,
                  PWM_INIT_SID)

    /* Set the corresponding bits to specify the TOm (channel output bit)
       operation mode */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC |
                                                  LpTAUDBUnitConfig->usTOCMask);
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC,
                  LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOC,
                  PWM_INIT_SID)

    /* Set the corresponding bits to enable/disable TOm operation */
    LusTempReg = (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                                                  LpTAUDBUnitConfig->usTOEMask);
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                 &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOE,
                  PWM_INIT_SID)

    /* Set the corresponding bits as per the configured Polarity */
    LusTempReg = (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL |
                                                  LpTAUDBUnitConfig->usTOLMask);
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL,
                  LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOL,
                  PWM_INIT_SID)

    /* Set the corresponding bits to Enable simultaneous rewrite of
       the data register */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE |
                                           LpTAUDBUnitConfig->usTAUChannelMask);
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE,
                  LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE,
                  LusTempReg,
                  PWM_TAUDB_MASK_RDE,
                  PWM_INIT_SID)

    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set the channel bits that are not configured for synchronous start,
       to enable the count operation */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                          (LpTAUDBUnitConfig->usTAUChannelMask ^
                                            (LpTAUDBUnitConfig->usSyncInitMask |
                                         LpTAUDBUnitConfig->usComplexInitMask));
    /* Stop the count operation */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                  (LpTAUDBUnitConfig->usTAUChannelMask ^
                  (LpTAUDBUnitConfig->usSyncInitMask |
                   LpTAUDBUnitConfig->usComplexInitMask)))

    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                   LusTempReg,
                   PWM_TAUDB_MASK_TE,
                   PWM_INIT_SID)
    #else
    /* Set the corresponding channel bit to enable the count operation */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                            LpTAUDBUnitConfig->usTAUChannelMask;
    /* Stop the count operation using WV */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                   LpTAUDBUnitConfig->usTAUChannelMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                   LusTempReg,
                   PWM_TAUDB_MASK_TE,
                   PWM_INIT_SID)
    #endif

    /* check if timer started */
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    if ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                      (LpTAUDBUnitConfig->usTAUChannelMask ^
                                        (LpTAUDBUnitConfig->usSyncInitMask |
                                     LpTAUDBUnitConfig->usComplexInitMask))) !=
        (LpTAUDBUnitConfig->usTAUChannelMask ^
         (LpTAUDBUnitConfig->usSyncInitMask |
          LpTAUDBUnitConfig->usComplexInitMask)))
    #else
    if (PWM_TAUDB_CH_STOPPED ==
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                           LpTAUDBUnitConfig->usTAUChannelMask))
    #endif
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Increment the pointer for the next TAUD/TAUB Unit */
    LpTAUDBUnitConfig++;

    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-10 */
    /* Increment the pointer for the next hannel in configuration */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    LpChannelConfig++;
    /* END Msg(4:2983)-10 */
    /* END Msg(4:0489)-1 */
  }
  /* END Msg(4:2877)-9 */

  #endif

  /* Check for TAUJ Units Used */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)

  /* Update the TAUJ Unit config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    LucOsCntlRegsIndx = LpTAUJUnitConfig->ucOsCntlRegsIndx;
    LucUserCntlRegsIndx = LpTAUJUnitConfig->ucUserCntlRegsIndx;

    /* MISRA Violation: START Msg(4:4397)-8 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Set the corresponding bits to enable/disable TOm operation */
    LusTempReg = (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                              (~(LpTAUJUnitConfig->ucTOEMask)));
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    PWM_TAUJ_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
           (uint8)LusTempReg,
                 &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                  PWM_INIT_SID)
    /* END Msg(4:4397)-8 */
    /* END Msg(4:4491)-4 */
    /* END Msg(2:3892)-1 */

    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits as per the configured Idle state */
    LusTempReg = ((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                               ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask))) |
                                                    LpTAUJUnitConfig->ucTOMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
           (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                  PWM_INIT_SID)
    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the Mode (Synchronous/Independent channel operation mode) */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM |
                                                   LpTAUJUnitConfig->ucTOMMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM,
           (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOM_LOW_NIBBLE,
                  PWM_INIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits to specify the TOm (channel output bit)
       operation mode */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC |
                              ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC,
           (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOC_LOW_NIBBLE,
                  PWM_INIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits to enable/disable TOm operation */
    LusTempReg = (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                                                   LpTAUJUnitConfig->ucTOEMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_TAUJ_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
           (uint8)LusTempReg,
                 &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
           (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                  PWM_INIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits as per the configured Polarity */
    LusTempReg = (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL |
                                                   LpTAUJUnitConfig->ucTOLMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL,
           (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOL_LOW_NIBBLE,
                  PWM_INIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits to Enable simultaneous rewrite of
       the data register */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE |
                                            LpTAUJUnitConfig->ucTAUChannelMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    PWM_WRITE_REG_ONLY(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE,
           (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_RDE_LOW_NIBBLE,
                  PWM_INIT_SID)
    /* END Msg(2:3892)-1 */

    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the channel bits that are not configured for synchronous start,
       to enable the count operation */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                           (LpTAUJUnitConfig->ucTAUChannelMask ^
                                             (LpTAUJUnitConfig->ucSyncInitMask |
                                          LpTAUJUnitConfig->ucComplexInitMask));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(4:4491)-4 */
    /* END Msg(2:3892)-1 */

    /* Stop the count operation */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                  (LpTAUJUnitConfig->ucTAUChannelMask ^
                  (LpTAUJUnitConfig->ucSyncInitMask |
                   LpTAUJUnitConfig->ucComplexInitMask)))

    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                   (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                   PWM_INIT_SID)
    /* END Msg(2:3892)-1 */
    #else

    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding channel bit to enable the count operation */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                             LpTAUJUnitConfig->ucTAUChannelMask;
    /* END Msg(4:4491)-4 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* Stop the count operation */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                   LpTAUJUnitConfig->ucTAUChannelMask)

    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                   (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                   PWM_INIT_SID)
    #endif

    /* check if timer started */
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    if ((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                  (LpTAUJUnitConfig->ucTAUChannelMask ^
                                    (LpTAUJUnitConfig->ucSyncInitMask |
                                     LpTAUJUnitConfig->ucComplexInitMask))) !=
        (LpTAUJUnitConfig->ucTAUChannelMask ^
         (LpTAUJUnitConfig->ucSyncInitMask |
          LpTAUJUnitConfig->ucComplexInitMask)))
    #else
    if (PWM_TAUJ_CH_STOPPED ==
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                            LpTAUJUnitConfig->ucTAUChannelMask))
    #endif
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Increment the pointer for the next TAUJ Unit */
    LpTAUJUnitConfig++;
    /* END Msg(4:2983)-10 */
    /* END Msg(4:0489)-1 */
  }
  /* END Msg(4:2877)-9 */

  #endif
}
#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Pwm_HW_DeInit
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function de-initializes all the PWM channels by
**                        setting to their configured Idle state, disabling the
**                        notifications, resetting all the registers and
**                        stopping the PWM mode of operation of corresponding
**                        timer.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpTAUDBUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpSynchStartConfig, Pwm_GpChannelConfig,
**                        Pwm_GaaNotifStatus, Pwm_GaaChannelCTDRVal
**                        Pwm_GpDiagUnitConfig, Pwm_GpDiagChannelConfig
**                        Pwm_GusIntSelRegMask, Pwm_GaaChannelConstantStatus
**                        Pwm_GaaChannelConstantState,
**                        Pwm_GaaChannelCRDRRestoreVal,
**                        Pwm_GaaChannelCSDRRestoreVal,
**
** Function(s) invoked  : Pwm_HW_StopDiagChannel, Dem_ReportErrorStatus
**
** Registers Used       : TAUDnTE, TAUBnTE, TAUDnTT, TAUBnTT, TAUDnTOE,
**                        TAUBnTOE, TAUDnTO, TAUBnTO, TAUDnTOM, TAUBnTOM,
**                        TAUDnTOC, TAUBnTOC, TAUDnTOL, TAUBnTOL, TAUDnRDE,
**                        TAUBnRDE, TAUDnCMORm, TAUBnCMORm, TAUDnCDRm,
**                        TAUBnCDRm, ICTAUBm, ICTAUDm, ICTAUJm,
**                        TAUJnTE, TAUJnTT, TAUJnTOE, TAUJnTO, TAUJnTOM,
**                        TAUJnTOC, TAUJnTOL, TAUJnRDE, TAUJnCMORm, TAUJnCDRm,
**                        PWBAnTT, PWBAnTE, PWGAINTMSK00, PWGAINTMSK01,
**                        PWGAINTMSK02, ICPWGAm, PWGAnCSDR, PWGAnCRDR, PWGAnRSF,
**                        PWGAnRDT, PWGAnCNT.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_111, PWM_ESDD_UD_045                              */
#if (PWM_DE_INIT_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_DeInit(void)
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint8 LucCntlRegs;
  uint8 LucOsCntlRegsIndx;
  uint8 LucUserCntlRegsIndx;
  uint16 LusTempReg;
  #endif

  uint8_least LucCount;

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;

  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;
  uint8 LucDiagChannel;
  uint8 LucDiagSaveCount;
  uint8 LucDiagGeneratortCntlRegs;
  uint16 LustimeoutValue;
  uint8 LenReturnValue;

  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  uint8 LucLoopCount;
  uint8 LucDiagchannelNo;

  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelGrpConfig;

  /* Update the PWGA Channel pointer to point to the first channel in
  configuration */
  LpDiagChannelGrpConfig = Pwm_GpDiagChannelConfig;
  #endif
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Update the TAUD/TAUB config pointer to point to the current TAU */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  LpChannelConfig = Pwm_GpChannelConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)

  /* Update the PWGA config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;

  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  LenReturnValue = E_OK;

  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Loop to set the target channels to stop the count trigger */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                    LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagGeneratortCntlRegs =
                             LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* END Msg(2:2814)-2 */
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set attributes of PWGA channels which are not to be started
       synchronously or set for complex driver usage */
    if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) &&
        (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
    #endif
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check if RSF register is zero */
      if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
         (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
      /* END Msg(2:3892)-1 */
      {
         /* Load Set Trigger point value to the CSDR Register to achieve
           constant low signal and reset value in CNT*/
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                 PWM_PWGA_RESETCNT_VALUE,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Perform write verify on CSDR register */
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                 PWM_PWGA_RESETCNT_VALUE,
                 PWM_PWGA_MASK_CSDR,
                 PWM_DEINIT_SID)
        /* END Msg(2:3892)-1 */
  
        /* Load Set Trigger point value to the CRDR Register to achieve
           constant low signal reset value in CNT */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                 PWM_PWGA_RESETCNT_VALUE,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                 PWM_PWGA_RESETCNT_VALUE,
                 PWM_PWGA_MASK_CRDR,
                 PWM_DEINIT_SID)
        /* END Msg(2:3892)-1 */

        /* Push the CSDR and CRDR values from data registers to buffer
                                                                 registers */
        PWM_WRITE_REG_ONLY(
                  &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                  PWM_PWGA_SIMUL_REWRITE_TRIGGER)
      }
      else
      {
          /* Report DEM if previous simultaneous rewrite is ongoing or failed */
          Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                             DEM_EVENT_STATUS_FAILED);
      }
    }
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    else
    {
       /* No action required */
    }
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */

  /* Loop to set the target channels to stop the count trigger if
  simultaneous rewrite happens else wait for buffer reloading to maintain low
  */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                    LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    LucDiagGeneratortCntlRegs =
                             LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the PWGA channel selected in to the local variable */
    LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;
    /* END Msg(2:2814)-2 */
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    /* Set attributes of PWGA channels which are not to be started
       synchronously or set for complex driver usage */
    if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) &&
        (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
    #endif
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check if RSF register is zero */
      if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
      /* END Msg(2:3892)-1 */
      {
        /* Invoke internal function to stop a PWM PWGA channel */
        Pwm_HW_StopDiagChannel(LucDiagChannel, PWM_DEINIT_SID);
      }
      else
      {
        /* Implements: PWM_ESDD_UD_135, EAAR_PN0034_FR_0085 */
        /* Implements: EAAR_PN0034_FR_0086 */
        /* Get the usDiagTimeOutValue in to the local variable */
        LustimeoutValue = LpDiagChannelConfig->usDiagTimeOutValue;

        /* QAC Warning: START Msg(2:3892)-1 */
        while ((PWM_ZERO < LustimeoutValue) &&
          (PWM_DIAG_SIMUL_REWRITE_COMPLETED != (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
               (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF))))
        {
          /* Decrement the timeout value */
          LustimeoutValue--;
        }

        if(PWM_ZERO == LustimeoutValue)
        {
          /* Set value to NOT_OK */
          LenReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
        /* END Msg(2:3892)-1 */
        /* Stop the Diag channel even a time out occurs to ensure channel is
        stopped at DeInit Functionality*/
        /* Implements PWM_ESDD_UD_180 */
        /* Invoke internal function to stop a PWM PWGA channel */
        Pwm_HW_StopDiagChannel(LucDiagChannel, PWM_DEINIT_SID);
      }
    }
    #if (PWM_SYNC_START_SUPPORT == STD_ON)
    else
    {
       /* No action required */
    }
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  if (E_OK == LenReturnValue)
  {
    /* Update the PWGA Channel pointer to point to the first channel in
       configuration */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:1252)-10 */

    /* Report NOT_OK if PWGAnCNT not reset */
    for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                    LucCount++)
    /* END Msg(2:1252)-10 */
    /* END Msg(2:3892)-1 */
    {
      #if (PWM_SYNC_START_SUPPORT == STD_ON)
      /* Set attributes of PWGA channels which are not to be started
         synchronously or set for complex driver usage */
      if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) &&
          (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
      #endif
      {
        LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
        /* Check if usPWGAnCNT reached 0xfff */
        if (PWM_PWGA_RESET_VALUE ==
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCNT)
        {
          /* Set value to E_OK */
          LenReturnValue = E_OK;
        }
        else
        {
          /* Implements: PWM_ESDD_UD_135, EAAR_PN0034_FR_0085 */
          /* Implements: EAAR_PN0034_FR_0086 */
          /* Get the usDiagTimeOutValue in to the local variable */
          LustimeoutValue = LpDiagChannelConfig->usDiagTimeOutValue;

          /* QAC Warning: START Msg(2:3892)-1 */
          while ((PWM_ZERO < LustimeoutValue) &&
          (PWM_PWGA_RESET_VALUE !=
               Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCNT))
          {
          /* Decrement the timeout value */
            LustimeoutValue--;
          }

          if (PWM_ZERO ==  LustimeoutValue)
          {
            /* Set value to NOT_OK */
            LenReturnValue = E_NOT_OK;
          }
          else
          {
             /* No action required */
          }
          /* END Msg(2:3892)-1 */
        }

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment to next PWGA channel configuration */
        LpDiagChannelConfig++;
        /* END Msg(4:0489)-1 */
      }
      #if (PWM_SYNC_START_SUPPORT == STD_ON)
      else
      {
        /* No action required */
      }
     #endif
    }
  }
  else
  {
    /* No action required */
  }

  if (E_NOT_OK == LenReturnValue)
  {
    /* Report DEM if PWGAnCNT not reset with insufficient time of buffer
    reloading and SLPWAGA operation completion*/
    /* Implements: PWM_ESDD_UD_193, EAAR_PN0034_FR_0084 */
    Dem_ReportErrorStatus(PWM_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }

  /* QAC Warning: START Msg(2:2814)-2 */
  /* Stop trigger the configured pre-scaler clocks */
  PWM_WRITE_REG_ONLY(
             &Pwm_GaaPWBAReg_BaseAddress->ucTT,
              LpDiagUnitConfig->ucDiagStartTrgPrescaler)
  /* END Msg(2:2814)-2 */
  /* QAC Warning: START Msg(2:3892)-1 */
  PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
             &Pwm_GaaPWBAReg_BaseAddress->ucTE,
              PWM_PWBA_CLEAR_TE ,
              PWM_PWBA_MASK_TE_LOW_NIBBLE ,
              PWM_DEINIT_SID)
  /* END Msg(2:3892)-1 */

  /* Implements:  PWM_ESDD_UD_227                                             */
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucLoopCount = PWM_ZERO; LucLoopCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                       LucLoopCount++)
  /* END Msg(2:3892)-1 */
  /* END Msg(2:1252)-10 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get Pwm Diag channel number*/
    LucDiagchannelNo = LpDiagChannelGrpConfig->ucDiagChannel;
    /* END Msg(2:2814)-2 */

    /* Clear Pwm Diag channel ids*/
    Pwm_GaaDiagChannelMap[LucDiagchannelNo] = PWM_ZERO;

    /* MISRA Violation: START Msg(4:0489)-1 */
    /*Point to next Pwm Diag channel configuration*/
    LpDiagChannelGrpConfig++;
    /* END Msg(4:0489)-1 */
  }

  #if (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE)
  /* QAC Warning: START Msg(2:3892)-1 */
  /* Update mirror values as per registers PWGAINTMSK0k (where k=0,1,2)*/
  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00 =
                      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK;

  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01 =
                      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK;

  Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02 =
                      Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK;
  /* END Msg(2:3892)-1 */

  #endif
  #endif/*End of #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)*/

  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;

  LucDiagSaveCount = PWM_MIN_DIAG_CHANNELS_CONFIG_ID;
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO;
                     LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Implements:  PWM012, SWS_Pwm_00012 */
    /* Notification status of this channel to PWM_FALSE */
    Pwm_GaaNotifStatus[LucDiagSaveCount] = PWM_FALSE;
    #endif

    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    Pwm_GaaChannelConstantStatus[LucDiagSaveCount] = PWM_FALSE;
    #endif

    /* QAC Warning: START Msg(2:3892)-1 */
    Pwm_GaaChannelCRDRRestoreVal[LucCount] = PWM_ZERO;
    Pwm_GaaChannelCSDRRestoreVal[LucCount] = PWM_ZERO;
    /* END Msg(2:3892)-1 */

    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    Pwm_GaaChannelConstantState[LucCount] = PWM_LOW;
    #endif

    /* MISRA Violation: START Msg(4:2983)-10 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Initialize global variables to 0 */
    Pwm_GaaPWGACSDR[LucCount] = PWM_ZERO;
    Pwm_GaaPWGACRDR[LucCount] = PWM_ZERO;

    Pwm_GaaDCBoundaryFlag[LucCount] = PWM_FALSE;
    /* END Msg(2:3892)-1 */

    /* Implements: PWM012, SWS_Pwm_00012, PWM_ESDD_UD_187, EAAR_PN0034_FR_0067*/
    #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
    /* Disabling the Interrupt processing of the current channel */
    RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
    #endif

    LucDiagSaveCount++;
    /* END Msg(4:2983)-10 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  #endif

  /* Check for TAUD/TAUB Units Used*/
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    LucUserCntlRegsIndx = LpTAUDBUnitConfig->ucUserCntlRegsIndx;
    /* END Msg(2:2814)-2 */
    LucOsCntlRegsIndx = LpTAUDBUnitConfig->ucOsCntlRegsIndx;

    /* MISRA Violation: START Msg(4:4397)-8 */
    /* calculate new value for TE register */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                         (~LpTAUDBUnitConfig->usTAUChannelMask);
    /* END Msg(4:4397)-8 */

    /* Set the configured channel bits to disable the count operation */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                                           LpTAUDBUnitConfig->usTAUChannelMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                   LusTempReg,
                   PWM_TAUDB_MASK_TE,
                   PWM_DEINIT_SID)

    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer started */
    if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                           LpTAUDBUnitConfig->usTAUChannelMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    /* END Msg(4:3344)-20 */

    /* calculate new value for TOE register */
    LusTempReg = (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                              ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask)));
    /* Set the corresponding bits to enable/disable TOm operation */
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                   LusTempReg,
                  &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                   LusTempReg,
                   PWM_TAUDB_MASK_TOE,
                   PWM_DEINIT_SID)
    /* Implements:  PWM011, SWS_Pwm_00011 */
    /* calculate new value for TO register */
    LusTempReg = ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                             ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask))) |
                                                   LpTAUDBUnitConfig->usTOMask);
    /* Set the PWM output to its corresponding idle state */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                   LusTempReg,
                   PWM_TAUDB_MASK_TO,
                   PWM_DEINIT_SID)

    /* calculate new value for TOM register */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM &
                              ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask)));
    /* Reset all the configured channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM,
                   LusTempReg,
                   PWM_TAUDB_MASK_TOM,
                   PWM_DEINIT_SID)

    /* calculate new value for TOC register */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC &
                              ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask)));
    /* Reset all the configured channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC,
                   LusTempReg,
                   PWM_TAUDB_MASK_TOC,
                   PWM_DEINIT_SID)

    /* calculate new value for TOL register */
    LusTempReg = (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL &
                              ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask)));
    /* Reset all the configured channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL,
                   LusTempReg,
                   PWM_TAUDB_MASK_TOL,
                   PWM_DEINIT_SID)

    /* calculate new value for RDE register */
    LusTempReg = (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE &
                              ((uint16)~(LpTAUDBUnitConfig->usTAUChannelMask)));
    /* Reset all the configured channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usRDE,
                   LusTempReg,
                   PWM_TAUDB_MASK_RDE,
                   PWM_DEINIT_SID)

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Increment the pointer to the next TAUD/TAUB unit */
    LpTAUDBUnitConfig++;
    /* END Msg(4:2983)-10 */
    /* END Msg(4:0489)-1 */
  }
   /* END Msg(4:2877)-9 */

  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)

  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* Update pointer for the base address of the TAUJ unit registers */
    /* QAC Warning: START Msg(2:2814)-2 */
    LucUserCntlRegsIndx = LpTAUJUnitConfig->ucUserCntlRegsIndx;
    LucOsCntlRegsIndx = LpTAUJUnitConfig->ucOsCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* MISRA Violation: START Msg(4:4397)-8 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TE register */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                          (~LpTAUJUnitConfig->ucTAUChannelMask);
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(4:4397)-8 */
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Set the configured channel bits to disable the count operation */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                   LpTAUJUnitConfig->ucTAUChannelMask)

    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
            (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                   PWM_DEINIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer started */
    if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                             LpTAUJUnitConfig->ucTAUChannelMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    /* END Msg(4:3344)-20 */

    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TOE register */
    LusTempReg = (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Reset TOE channels registers */
    PWM_TAUJ_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                   (uint8)LusTempReg,
                  &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
            (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                   PWM_DEINIT_SID)
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TO register */
    LusTempReg = ((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                               ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask))) |
                                             (uint8)LpTAUJUnitConfig->ucTOMask);
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    /* Reset TO channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                   (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                   PWM_DEINIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TOM register */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM &
                                ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    /* Reset TOM channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM,
                   (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TOM_LOW_NIBBLE,
                   PWM_DEINIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TOC register */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC &
                                ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Reset TOC channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC,
                   (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TOC_LOW_NIBBLE,
                   PWM_DEINIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TOL register */
    LusTempReg = (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL &
                                ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Reset TOL channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL,
                  (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TOL_LOW_NIBBLE,
                   PWM_DEINIT_SID)

    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate new value for TOL register */
    LusTempReg = (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE &
                                ((uint8)~(LpTAUJUnitConfig->ucTAUChannelMask)));
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* Reset TOL channels registers */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE,
                  (uint8)LusTempReg)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                 (&Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucRDE,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_RDE_LOW_NIBBLE,
                   PWM_DEINIT_SID)
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    /* END Msg(4:2877)-9 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Increment the pointer to next TAUJ unit */
    LpTAUJUnitConfig++;
    /* END Msg(4:2983)-10  */
    /* END Msg(4:0489)-1 */
  }

  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)

  /* Loop to reset the attributes of TAUD/TAUB/TAUJ channels */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAU_CHANNELS_CONFIG;
                                                                     LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    if ((PWM_HW_TAUD == LpChannelConfig->uiPwmTAUType) ||
                                 (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType))
    /* END Msg(2:2814)-2 */
    {
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
      LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

      /* Reset the CMORm register of the configured channel */
      PWM_TAUDB_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                     PWM_RESET_CMOR_REG,
                    &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                     PWM_RESET_CMOR_REG,
                     PWM_TAUDB_MASK_CMOR,
                     PWM_DEINIT_SID)
      /* END Msg(2:3892)-1 */

      /* Reset the CDRm register of the configured channel */
      PWM_TAUDB_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     PWM_RESET_TAUDBCDR_REG,
                    &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     PWM_RESET_TAUDBCDR_REG,
                     PWM_TAUDB_MASK_CDR,
                     PWM_DEINIT_SID)
      /* END Msg(2:3892)-1 */
      #endif
    }
    else if (PWM_HW_TAUJ == LpChannelConfig->uiPwmTAUType)
    {
      #if (PWM_TAUJ_UNIT_USED == STD_ON)
      LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

      /* Reset the CMORm register of the configured channel*/
      PWM_TAUJ_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                     PWM_RESET_CMOR_REG,
                    &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                     PWM_RESET_CMOR_REG,
                     PWM_TAUJ_MASK_CMOR_LOW_NIBBLE,
                     PWM_DEINIT_SID)
      /* END Msg(2:3892)-1 */

      /* Reset the CDRm register of the configured channel */
      PWM_TAUJ_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                     PWM_RESET_TAUJCDR_REG,
                    &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
      PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                     PWM_RESET_TAUJCDR_REG,
                     PWM_TAUJ_MASK_CDR,
                     PWM_DEINIT_SID)
      #endif
    }
    else
    {
      /* No action required */
    }

    /* Implements: PWM012, SWS_Pwm_00012, PWM_ESDD_UD_187, EAAR_PN0034_FR_0067*/
    #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
    /* Disabling the Interrupt processing of the current channel */
    RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAddress),
                                                     PWM_INTERRUPT_MASK_DIS);
    #endif

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Notification status of this channel to PWM_FALSE */
    Pwm_GaaNotifStatus[LucCount] = PWM_FALSE;
    #endif

    #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
    Pwm_GaaChannelConstantStatus[LucCount] = PWM_FALSE;
    #endif

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to the next channel */
    LpChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  #endif
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
** Function Name        : Pwm_HW_SetDutyCycle
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the duty cycle counter value in
**                        the hardware registers.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId and LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpTAUDUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**
** Functions invoked    : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION,
**                        Pwm_HW_CalculateDuty,
**                        Pwm_HW_SetDuty_PeriodShifted, Pwm_HW_StartDiagChannel,
**                        Pwm_GaaChannelCurrDutyCycle, Dem_ReportErrorStatus
**
** Registers Used       : TAUDnCDRm, TAUBnCDRm, TAUDnRDT, TAUBnRDT, TAUDnTOE,
**                        TAUBnTOE, TAUDnTE, TAUBnTE, TAUDnTT, TAUBnTT, TAUDnTS,
**                        TAUBnTS, TAUJnCDRm, TAUJnRDT, TAUJnTOE, TAUJnTE,
**                        TAUJnTT, TAUJnTS, PWGAnCSDR, PWGAnCRDR, PWGAnRSF,
**                        PWGAnRDT, TAUBnRSF, TAUJnRSF, TAUDnRSF
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_112, PWM_ESDD_UD_164, EAAR_PN0066_FR_0056         */
/* Implements:  EAAR_PN0066_FR_0054                                           */
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetDutyCycle
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  uint8 LucTAUDBChannelReg;
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;

  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  uint8 LucTAUJChannelReg;
 /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;

  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;

  uint8 LucDiagChannelStatus;
  uint8 LucDiagChannel;
  uint8 LucDiagGeneratortCntlRegs;
  uint16 LusOffset;
  uint16 LusResetTriggerValue;
  uint16 LusDiagPeriod;
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  uint8 LucPwmShift;
  #endif
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  Pwm_PeriodType LddMasterPeriod;
  uint8 LucVar;
  uint8_least LucCount;
  uint8 LucNumSlaveChnls;
  uint8 LucCntlRegs;
  uint8 LucUserCntlRegsIndx;
  uint16 LusMasterChannelMask;
  Pwm_PeriodType LddCalculateDuty;
  uint16 LusTempReg;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* QAC Warning: START Msg(2:3892)-1 */
  LusOffset = PWM_ZERO;
  /* END Msg(2:3892)-1 */
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  /* Check if channel belongs to PWGA or TAU unit */
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Initialize a pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */
    #endif

    #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
    /* Check for the channel Class Type */
    /* QAC Warning: START Msg(2:2814)-2 */
    if ((PWM_FIXED_PERIOD_SHIFTED == LpChannelConfig->ddClassType) ||
        (PWM_VARIABLE_PERIOD_SHIFTED == LpChannelConfig->ddClassType))
    /* END Msg(2:2814)-2 */
    {
      /* Set Duty cycle for the required channel in FixedPeriodShifted
         Class Type */
      Pwm_HW_SetDuty_PeriodShifted(LddChannelId, LusDutyCycle);
    }
    else
    #endif
    {
      #if (PWM_TAU_UNIT_USED == STD_ON)
      /* Check for the channel in Master Mode */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* QAC Warning: START Msg(2:2814)-2 */
      if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
      /* END Msg(2:2814)-2 */
      /* END Msg(2:3892)-1 */
      #endif
      {
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
         (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* Check whether the channel belongs to TAUD/TAUB */
        /* QAC Warning: START Msg(2:3892)-1 */
        if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
        /* END Msg(2:3892)-1 */
        #endif
        {
          #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUD/TAUB channel properties */
          LpTAUDBProperties =
          (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Get the Channel Mask of the Master channel for RDT register */
          /* QAC Warning: START Msg(2:2814)-2 */
          LusMasterChannelMask = LpTAUDBProperties->usChannelMask;
          /* END Msg(2:2814)-2 */

          /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Update the TAUD/TAUB unit config pointer */
          /* QAC Warning: START Msg(2:2824)-4 */
          LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig + LucUserCntlRegsIndx;
          /* END Msg(2:2824)-4 */
          /* END Msg(4:0488)-3 */

          /* Get the master's period */
          LddMasterPeriod =  Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          /* Get the number of slave channels configured for master channel */
          LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the slave channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */

          /* Increment the channel Id*/
          LddChannelId++;

          /* QAC Warning: START Msg(2:3892)-1 */
          for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
          /* END Msg(2:3892)-1 */
          {
            LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enter Protected area */
            PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif

            /* Implements:  PWM016, SWS_Pwm_00016 */
            /* calculate duty cycle */
            /* QAC Warning: START Msg(2:3892)-1 */
            LddCalculateDuty = (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
            /* END Msg(2:3892)-1 */
            /* QAC Warning: START Msg(2:3892)-1 */
            /* Check if the simultaneous rewrite operation is completed  */
            if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusMasterChannelMask &
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
            /* END Msg(2:3892)-1 */
            {
              /* Load the Absolute duty value in to the CDR Register */
              PWM_TAUDB_WRITE_REG_AND_MIRROR(
                         &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                          (uint16)LddCalculateDuty,
                         &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
              /* QAC Warning: START Msg(2:3892)-1 */
              PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                         &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                          (uint16)LddCalculateDuty,
                          PWM_TAUDB_MASK_CDR,
                          PWM_SET_DUTYCYCLE_SID)
            /* END Msg(2:3892)-1 */
            }
            else
            {
              /* Implements: PWM_ESDD_UD_192                                  */
              /* Report DEM if previous simultaneous rewrite is ongoing or
                 failed */
              Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
            }

            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Exit Protected area */
            PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif

            /* Increment the channel Id */
            LddChannelId++;

            /* MISRA Violation: START Msg(4:0489)-1 */
            /* Increment the pointer to the next channel */
            LpChannelConfig++;
            /* END Msg(4:0489)-1 */
          }

          /* Set the corresponding channel Trigger bit to specifies
             the channel for which simultaneous rewrite is executed */
          PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRDT,
                     LusMasterChannelMask)

          /* Check whether the channel is set to its Idle state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUDB_CH_IDLE_STATE ==
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                                          LusMasterChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:4397)-8 */
            /* calculate new value for TE register */
            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enter Protected area */
            PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif
            LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                        (~LusMasterChannelMask);
            /* END Msg(4:4397)-8 */
            /* Stop count operation */
            PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                        LusMasterChannelMask)

            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SET_DUTYCYCLE_SID)

            /* MISRA Violation: START Msg(4:3344)-20 */
            /* check if timer started */
            if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                           LusMasterChannelMask)
            {
              /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              /* No action required */
            }
            /* END Msg(4:3344)-20 */

            /* MISRA Violation: START Msg(4:0491)-16 */
            /* calculate new value for TOE register */
            /* QAC Warning: START Msg(2:2824)-4 */
            LusTempReg =
                  Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                            (LpTAUDBUnitConfig[LucUserCntlRegsIndx].usTOEMask &
                                                          LusMasterChannelMask);
            /* END Msg(2:2824)-4 */
            /* END Msg(4:0491)-16 */
            /* Enable the output of the current channel */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                       PWM_TAUDB_MASK_TOE,
                       PWM_SET_DUTYCYCLE_SID)

            /* calculate new value for TE register */
            LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                           LusMasterChannelMask;
            /* Start the count operation */
            PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                        LusMasterChannelMask)

            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SET_DUTYCYCLE_SID)
            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Exit Protected area */
            PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif
            /* check if timer started */
            /* QAC Warning: START Msg(2:3892)-1 */
            if (PWM_TAUDB_CH_STOPPED ==
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                          LusMasterChannelMask))
            /* END Msg(2:3892)-1 */
            {
               /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
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
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
            (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        else
        #endif
        {
          #if (PWM_TAUJ_UNIT_USED == STD_ON)

          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Get the Channel Mask of the Master channel for RDT register */
          /* QAC Warning: START Msg(2:2814)-2*/
          LusMasterChannelMask = (uint16)LpTAUJProperties->ucChannelMask;
          /* END Msg(2:2814)-2 */

          /* Fetch the pointer to the current TAUJ Unit Registers */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Update the TAUJ unit config pointer */
          /* QAC Warning: START Msg(2:2824)-4 */
          LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig + LucUserCntlRegsIndx;
          /* END Msg(2:2824)-4 */
          /* END Msg(4:0488)-3 */

          /* Get the master's period */
          LddMasterPeriod = Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          /* Get the number of slave channels configured for master channel */
          LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

          /* Increment the channel Id */
          LddChannelId++;

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */

          /* QAC Warning: START Msg(2:3892)-1 */
          for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
          /* END Msg(2:3892)-1 */
          {

            LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enter Protected area */
            PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif

            /* Implements:  PWM016, SWS_Pwm_00016 */
            /* calculate duty cycle */
            LddCalculateDuty = Pwm_HW_CalculateDuty(LddMasterPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
            /* Check if the simultaneous rewrite operation is completed  */
            /* QAC Warning: START Msg(2:3892)-1 */
            if (PWM_TAUJ_SIMUL_REWRITE_COMPLETED == (LusMasterChannelMask &
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRSF)))
            /* END Msg(2:3892)-1 */
            {
              /* Load the Absolute duty value in to the CDR Register */
              PWM_TAUJ_WRITE_REG_AND_MIRROR(
                              &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                               LddCalculateDuty,
                              &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
              PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                              &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                               LddCalculateDuty,
                               PWM_TAUJ_MASK_CDR,
                               PWM_SET_DUTYCYCLE_SID)
            }
            else
            {
              /* Report DEM if previous simultaneous rewrite is ongoing or
                 failed */
              Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                     DEM_EVENT_STATUS_FAILED);
            }

            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Exit Protected area */
            PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif

            /* Increment the channel Id */
            LddChannelId++;

            /* MISRA Violation: START Msg(4:0489)-1 */
            /* Increment the pointer to the next channel */
            LpChannelConfig++;
            /* END Msg(4:0489)-1 */
          }

          /* Set the corresponding channel Trigger bit to specify
             the channel for which simultaneous rewrite is executed */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRDT,
                        (unsigned char)LusMasterChannelMask)

          /* Check whether the channel is set to its Idle state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUJ_CH_IDLE_STATE ==
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                                          LusMasterChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:4397)-8 */
            /* calculate new value for TE register */
            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enter Protected area */
            PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif
            LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                        (~LusMasterChannelMask);
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* END Msg(4:4397)-8 */

            /* Stop count operation */
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                         (unsigned char)LusMasterChannelMask)

            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                    (uint8)LusTempReg,
                    PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                    PWM_SET_DUTYCYCLE_SID)

            /* END Msg(2:3892)-1 */
            /* MISRA Violation: START Msg(4:3344)-20 */
            /* check if timer started */
            if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                           LusMasterChannelMask)
            {
               /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              /* No action required */
            }
            /* END Msg(4:3344)-20 */

            /* calculate new value for TOE register */
            /* QAC Warning: START Msg(2:2814)-2 */
            LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                           (LpTAUJUnitConfig->ucTOEMask & LusMasterChannelMask);
            /* END Msg(2:2814)-2 */
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* Enable the output of the current channel */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                       &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                       (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                        PWM_SET_DUTYCYCLE_SID)
            /* END Msg(2:3892)-1 */

            /* calculate new value for TE register */
            LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                                           LusMasterChannelMask;
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* Start count operation */
            PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                        (unsigned char)LusMasterChannelMask)

            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                        PWM_SET_DUTYCYCLE_SID)
            #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Exit Protected area */
            PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
            #endif
            /* check if timer started */
            if (PWM_TAUJ_CH_STOPPED ==
                (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                          LusMasterChannelMask))
            /* END Msg(2:3892)-1 */
            {
               /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
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
      }
      #if (PWM_TAU_UNIT_USED == STD_ON)
      else
      #endif
      {
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
            (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* Check whether the channel belongs to TAUD/TAUB */
        /* QAC Warning: START Msg(2:3892)-1 */
        if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
        /* END Msg(2:3892)-1 */
        #endif
        {
          #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUD/TAUB channel properties */
          LpTAUDBProperties =
          (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Get the Channel Mask of the Master channel for RDT register */
          LusMasterChannelMask = LpTAUDBProperties->usChannelMask;

          /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

            /* Get the offset of the Master from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Initialize a pointer to the Master's control register
             configuration of TAUD/TAUB */
          LucTAUDBChannelReg = ((LpChannelConfig - LucVar)->ucCntlRegsIndx);
          /* END Msg(4:0488)-3 */

          /* Get the master's period */
          LddMasterPeriod =
                    Pwm_GaaTAUDBChReg_BaseAddress[LucTAUDBChannelReg]->usCDR;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* Check whether the channel is set to its Idle state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if(PWM_TAUDB_CH_IDLE_STATE ==
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                                          LusMasterChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:4397)-8 */
            /* calculate new value for TE register */
            LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                        (~LusMasterChannelMask);
            /* END Msg(4:4397)-8 */

            /* Stop count operation */
            PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                        LusMasterChannelMask)

            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SET_DUTYCYCLE_SID)

            /* MISRA Violation: START Msg(4:3344)-20 */
            /* check if timer started */
            if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                           LusMasterChannelMask)
            {
              /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              /* No action required */
            }
            /* END Msg(4:3344)-20 */

            /* calculate new value for TOE register */
            LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                                                           LusMasterChannelMask;
            /* Enable the output of the current channel */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                       PWM_TAUDB_MASK_TOE,
                       PWM_SET_DUTYCYCLE_SID)

            /* Start count operation */
            #if (PWM_SYNC_START_SUPPORT == STD_ON)
            if(LpChannelConfig->blSyncStartReq == PWM_ONE)
            {
              if(Pwm_GblSyncStartStatus == PWM_SYNC_STARTED)
              {
                /* calculate new value for TE register */
                LusTempReg =
                    Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                           LusMasterChannelMask;
                /* Start the count operation */
                PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                        LusMasterChannelMask)

                /* MISRA Violation: START Msg(4:0715)-17 */
                PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                         LusTempReg,
                         PWM_TAUDB_MASK_TE,
                         PWM_SET_DUTYCYCLE_SID)
                /* END Msg(4:0715)-17 */

                /* MISRA Violation: START Msg(4:0715)-17 */
                /* check if timer started */
                /* QAC Warning: START Msg(2:3892)-1 */
                if (PWM_TAUDB_CH_STOPPED ==
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                          LusMasterChannelMask))
                 /* END Msg(2:3892)-1 */
                {
                  /* Report to DEM */
                  Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                  /* No action required */
                }
                /* END Msg(4:0715)-17 */
              }
              else
              {
                /* No action required */
              }
            }
            else
            #endif
            {
              /* calculate new value for TE register */
              LusTempReg =
                    Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                           LusMasterChannelMask;
              /* Start the count operation */
              PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                        LusMasterChannelMask)

              PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SET_DUTYCYCLE_SID)

              /* check if timer started */
              /* QAC Warning: START Msg(2:3892)-1 */
              if (PWM_TAUDB_CH_STOPPED ==
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                         LusMasterChannelMask))
              /* END Msg(2:3892)-1 */
              {
                 /* Report to DEM */
                Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
              }
              else
              {
                /* No action required */
              }
            }
          }
          else
          {
            /* No action required */
          }
          /* Implements:  PWM016, SWS_Pwm_00016 */
          /* calculate duty cycle */
          /* QAC Warning: START Msg(2:3892)-1 */
          LddCalculateDuty = (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod,
                                        (Pwm_PeriodType)LusDutyCycle, LucVar);
          /* Check if the simultaneous rewrite operation is completed  */
          if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusMasterChannelMask &
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
          {
            /* END Msg(2:3892)-1 */
            /* Load the Absolute duty value in to the CDR Register */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                             &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                              (uint16)LddCalculateDuty,
                             &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                           &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                            (uint16)LddCalculateDuty,
                            PWM_TAUDB_MASK_CDR,
                            PWM_SET_DUTYCYCLE_SID)
            /* END Msg(2:3892)-1 */
          }
          else
          {
            /* Report DEM if previous simultaneous rewrite is ongoing or
               failed */
            Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
          }
          /* MISRA Violation: START Msg(4:3138)-18 */
          /* Set the corresponding channel Trigger bit to specifies the
             channel for which simultaneous rewrite is executed */
          PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRDT,
                       LusMasterChannelMask)
          /* END Msg(4:3138)-18 */

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
             (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* Channel belongs to TAUJ */
        else
        #endif
        {
          #if (PWM_TAUJ_UNIT_USED == STD_ON)

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* QAC Warning: START Msg(2:2814)-2 */
          /* Get the Channel Mask of the Master channel for RDT register */
          LusMasterChannelMask = (uint16)LpTAUJProperties->ucChannelMask;
          /* END Msg(2:2814)-2 */

          /* Fetch the pointer to the current TAUJ Unit Registers */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* Get the offset of the Master from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Initialize a pointer to the Master's control register
             configuration of TAUJ */
          LucTAUJChannelReg = ((LpChannelConfig - LucVar)->ucCntlRegsIndx);
          /* END Msg(4:0488)-3 */

          /* Get the master's period */
          LddMasterPeriod =
                       Pwm_GaaTAUJChReg_BaseAddress[LucTAUJChannelReg]->ulCDR;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;

          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* Check whether the channel is set to its Idle state */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUJ_CH_IDLE_STATE ==
             (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                                          LusMasterChannelMask))
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:4397)-8 */
            /* calculate new value for TE register */
            LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                        (~LusMasterChannelMask);
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* END Msg(4:4397)-8 */

            /* Stop count operation */
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                         (unsigned char)LusMasterChannelMask)

            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                        (uint8)LusTempReg,
                         PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                         PWM_SET_DUTYCYCLE_SID)

            /* END Msg(2:3892)-1 */
            /* MISRA Violation: START Msg(4:3344)-20 */
            /* check if timer started */
            if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                           LusMasterChannelMask)
            {
              /* Report to DEM */
              Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              /* No action required */
            }
            /* END Msg(4:3344)-20 */

            /* calculate new value for TOE register */
            LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                                                           LusMasterChannelMask;
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* Enable the output of the current channel */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                       &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                        PWM_SET_DUTYCYCLE_SID)
             /* END Msg(2:3892)-1 */

            /* Start count operation */
            #if (PWM_SYNC_START_SUPPORT == STD_ON)
            if(LpChannelConfig->blSyncStartReq == PWM_ONE)
            {
              if(Pwm_GblSyncStartStatus == PWM_SYNC_STARTED)
              {
                /* calculate new value for TE register */
                LusTempReg =
                     Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                                           LusMasterChannelMask;
                /* QAC Warning: START Msg(2:3892)-1 */
                LusTempReg &= PWM_MASK_LOW_NIBBLE;
                /* END Msg(2:3892)-1 */
                /* Start count operation */
                PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                         (unsigned char)LusMasterChannelMask)
                /* MISRA Violation: START Msg(4:0715)-17 */
                /* QAC Warning: START Msg(2:3892)-1 */
                PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                         (uint8)LusTempReg,
                         PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                         PWM_SET_DUTYCYCLE_SID)
                /* END Msg(2:3892)-1 */


                /* check if timer started */
                /* QAC Warning: START Msg(2:3892)-1 */
                if (PWM_TAUJ_CH_STOPPED ==
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                          LusMasterChannelMask))
                /* END Msg(2:3892)-1 */
                {
                  /* Report to DEM */
                  Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
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
            /* END Msg(4:0715)-17 */
            else
            #endif
            {
              /* calculate new value for TE register */
              LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                                           LusMasterChannelMask;
              /* QAC Warning: START Msg(2:3892)-1 */
              LusTempReg &= PWM_MASK_LOW_NIBBLE;
              /* END Msg(2:3892)-1 */
              /* Start count operation */
              PWM_WRITE_REG_ONLY(
                     &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                         (unsigned char)LusMasterChannelMask)

              /* QAC Warning: START Msg(2:3892)-1 */
              PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                        (uint8)LusTempReg,
                         PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                         PWM_SET_DUTYCYCLE_SID)
              /* END Msg(2:3892)-1 */

              /* check if timer started */
              /* QAC Warning: START Msg(2:3892)-1 */
              if (PWM_TAUJ_CH_STOPPED ==
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                          LusMasterChannelMask))
              /* END Msg(2:3892)-1 */
              {
                /* Report to DEM */
                Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
              }
              else
              {
                /* No action required */
              }
            }
          }
          else
          {
            /* No action required */
          }
          /* Implements:  PWM016, SWS_Pwm_00016 */
          /* Load the Absolute Duty in to the CDR register */
          /* calculate duty cycle */
          LddCalculateDuty = Pwm_HW_CalculateDuty(LddMasterPeriod,
                                        (Pwm_PeriodType)LusDutyCycle, LucVar);

          /* Check if the simultaneous rewrite operation is completed  */
          /* QAC Warning: START Msg(2:3892)-1 */
          if (PWM_TAUJ_SIMUL_REWRITE_COMPLETED == (LusMasterChannelMask &
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRSF)))
          /* END Msg(2:3892)-1 */
          {
            /* Load the Absolute duty value in to the CDR Register */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                             &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                              LddCalculateDuty,
                             &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                             &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                              LddCalculateDuty,
                            PWM_TAUJ_MASK_CDR,
                            PWM_SET_DUTYCYCLE_SID)
          }
          else
          {
            /* Report DEM if previous simultaneous rewrite is ongoing or
               failed */
            Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                DEM_EVENT_STATUS_FAILED);
          }

          /* Set the corresponding channel Trigger bit to specifies the
             channel for which simultaneous rewrite is executed */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRDT,
                         (unsigned char)LusMasterChannelMask)

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
      }
    }
  }
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  else
  #endif
  {
    #if (PWM_DIAG_UNIT_USED == STD_ON)

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */

    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */
    /* END Msg(4:2985)-15 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    #if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)
    Pwm_GaaChannelCurrDutyCycle[LddChannelId -
                                PWM_MIN_DIAG_CHANNELS_CONFIG_ID] = LusDutyCycle;
    /* END Msg(4:2985)-15 */
    #endif
    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:3892)-1 */
    if (PWM_FALSE ==
         Pwm_GaaDCBoundaryFlag[LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID])
    /* END Msg(4:2985)-15 */
    /* END Msg(2:3892)-1 */
    {
      /* Get the current offset value in to the local variable */
      if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
      {
       LusOffset =
                  Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR;
      }
      else
      {
        if (PWM_DIAG_MAX_RESETTRIGGER_MASK ==
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR)
        {
          /* MISRA Violation: START Msg(4:2985)-15 */
          LusOffset = Pwm_GaaChannelCRDRRestoreVal[LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID];
          /* END Msg(4:2985)-15 */
        }
        else
        {
          LusOffset =
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR;
        }
      }
    }
    else
    {
      /* Implements:  PWM_ESDD_UD_162                                         */
      /* MISRA Violation: START Msg(2:3892)-1 */
      /* Check if RSF register is zero */
      if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
      /* END Msg(2:3892)-1 */
      {
        if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
        {
          /* MISRA Violation: START Msg(4:2985)-15 */
          /* Load calculated offset from global CSDR buffer*/
          LusOffset = Pwm_GaaPWGACSDR
                      [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID];
          /* END Msg(4:2985)-15 */
          /* Write calculated value to CSDR register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_SET_DUTYCYCLE_SID)
        }
        else
        {
          /* Load calculated offset from global CRDR buffer */
          /* MISRA Violation: START Msg(4:2985)-15 */
          LusOffset = Pwm_GaaPWGACRDR
                      [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID];
          /* END Msg(4:2985)-15 */
          /* Write calculated value to CRDR register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SET_DUTYCYCLE_SID)
        }
      }
      else
      {
         /* Report DEM if previous simultaneous rewrite is ongoing or failed */
         Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                 DEM_EVENT_STATUS_FAILED);
      }
      /* QAC Warning: START Msg(4:2985)-15 */
      /* QAC Warning: START Msg(2:3892)-1 */
      Pwm_GaaDCBoundaryFlag[LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID]
                                                                    = PWM_FALSE;
      /* END Msg(2:3892)-1 */
      /* END Msg(4:2985)-15 */
    }

    /* QAC Warning: START Msg(2:3892)-1 */
    /* Check if RSF register is zero */
    if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
    /* END Msg(2:3892)-1 */
    {

      #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
      LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
      LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
      #else
      LusDiagPeriod = PWM_DIAG_MAX_COUNT;
      #endif
      /* calculate diag reset trigger point */
      LusResetTriggerValue =
          Pwm_HW_CalDiagResetTriggerPoint (LusDutyCycle, LusOffset,
              LusDiagPeriod);
      /* Implements:  PWM014, SWS_Pwm_00014 */
      /* Check PWM polarity is PWM_HIGH */
      if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
      {
        /* Load the Reset condition value to the CRDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                 LusResetTriggerValue,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                 LusResetTriggerValue,
                 PWM_PWGA_MASK_CRDR,
                 PWM_SET_DUTYCYCLE_SID)
      }
      /* Implements:  PWM014, SWS_Pwm_00014 */
      /* PWM polarity is PWM_LOW */
      else
      {
        if (LusResetTriggerValue == LusOffset)
        {
          /* Store Reset Trigger point value, only if it is less than 0x1FFF */
          if (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR !=
                                                PWM_DIAG_MAX_RESETTRIGGER_MASK)
          {
            /* MISRA Violation: START Msg(4:2985)-15 */
            Pwm_GaaChannelCRDRRestoreVal
                  [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID] =
                  Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR;
            /* END Msg(4:2985)-15 */
          }
          else
          {
            /* No action required */
          }
  
          /* Load the Reset condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SET_DUTYCYCLE_SID)
          /* END Msg(2:3892)-1 */
        }
        else if (PWM_DIAG_MAX_RESETTRIGGER_MASK == LusResetTriggerValue)
        {
          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_SET_DUTYCYCLE_SID)
  
          /* Load the Set condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SET_DUTYCYCLE_SID)
        }
        else
        {
          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusResetTriggerValue,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusResetTriggerValue,
                      PWM_PWGA_MASK_CSDR,
                      PWM_SET_DUTYCYCLE_SID)
  
          if (PWM_DIAG_MAX_RESETTRIGGER_MASK ==
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR)
          {
            /* MISRA Violation: START Msg(4:2985)-15 */
            /* Load the Reset Trigger point value to the CRDR Register */
            PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                       Pwm_GaaChannelCRDRRestoreVal
                       [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                       &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
            PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                        Pwm_GaaChannelCRDRRestoreVal
                        [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                        PWM_PWGA_MASK_CRDR,
                        PWM_SET_DUTYCYCLE_SID)
            /* END Msg(4:2985)-15 */
          }
          else
          {
            /* No action required */
          }
        }
      }
  
      PWM_WRITE_REG_ONLY(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                  PWM_PWGA_SIMUL_REWRITE_TRIGGER)
    }
    else
    {
      /* Report DEM if previous simultaneous rewrite is ongoing or failed */
      Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                               DEM_EVENT_STATUS_FAILED);
    }
    /* END Msg(2:3892)-1 */

    /* Get the IDLE status for DIAG channel */
    LucDiagChannelStatus = Pwm_HW_GetDiagChannelStatus(LddChannelId);

    /* Check whether the channel is set to its Idle state */
    if (PWM_ZERO == LucDiagChannelStatus)
    {
      /* Get the PWGA channel selected in to the local variable */
      LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;
      #if (PWM_SYNC_START_SUPPORT == STD_ON)
     /* Set attributes of PWGA channels which are not to be started
         synchronously */
      if ((PWM_FALSE == LpDiagChannelConfig->blSyncStartReq) ||
                (PWM_SYNC_STARTED == Pwm_GblSyncStartStatus))
      #endif
        {
          /* Invoke internal function to start a PWM PWGA channel */
          Pwm_HW_StartDiagChannel(LucDiagChannel, PWM_SET_DUTYCYCLE_SID);
        }
      #if (PWM_SYNC_START_SUPPORT == STD_ON)
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

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    #endif
  }
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
** Function Name        : Pwm_HW_SetDuty_PeriodShifted
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the duty cycle for
**                        FixedPeriodShifted ClassType channels of TAUD Units.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId and LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpTAUDUnitConfig, Pwm_GpChannelConfig
**
** Functions invoked    : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION,
**                        Pwm_HW_CalculateDuty, Dem_ReportErrorStatus
**
** Registers Used       : TAUDnTOE, TAUBnTOE, TAUDnCDRm, TAUBnCDRm, TAUDnRDT,
**                        TAUBnRDT, TAUDnTE, TAUBnTE, TAUDnTT, TAUBnTT, TAUDnTS,
**                        TAUBnTS, TAUDnRSF, TAUBnRSF.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_116                                               */
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDuty_PeriodShifted
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle)
/* END Msg(2:3206)-6 */
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON))
  uint8 LucCntlRegs;
  uint8 LucUserCntlRegsIndx;
  uint8 LucTAUDBChannelReg;
  uint8_least LucCount;
  uint8 LucVar;
  uint16 LusChannelMask;
  Pwm_PeriodType LddCalculateDuty;

  uint16 LusTempReg;

  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;

  Pwm_PeriodType LddMasterPeriod;

  /* MISRA Violation: START Msg(4:0488)-3 */
  /* QAC Warning: START Msg(2:2824)-4 */
  /* Initialize a pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0488)-3 */

  /* Update the TAUD/TAUB unit config pointer */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;

  /* QAC Warning: START Msg(2:2814)-2 */
  /* Check whether the channel in Master mode */
  if (PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
  /* END Msg(2:2814)-2 */
  {
    /* MISRA Violation: START Msg(4:0311)-2 */
    /* MISRA Violation: START Msg(4:0316)-7 */
    /* Get the pointer to the TAUD/TAUB channel properties */
    LpTAUDBProperties =
                     (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
    /* END Msg(4:0316)-7 */
    /* END Msg(4:0311)-2 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the channel mask for the particular channel */
    LusChannelMask = LpTAUDBProperties->usChannelMask;
    /* END Msg(2:2814)-2 */

    /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
    LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

    LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
    /* Get the master's period */
    LddMasterPeriod = Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR;

    /* Get the TAU Type in to the local variable */
    LucVar = LpChannelConfig->uiPwmTAUType;

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* QAC Warning: START Msg(2:3892)-1 */
    for (LucCount = PWM_ONE; PWM_THREE >= LucCount; LucCount++)
    /* END Msg(2:3892)-1 */
    {
       /* MISRA Violation: START Msg(4:0489)-1 */
       /* Increment the channel for the next channel */
       LpChannelConfig++;
       /* END Msg(4:0489)-1 */

       LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
       /* calculate duty cycle */
       /* QAC Warning: START Msg(2:3892)-1 */
       LddCalculateDuty = (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
       if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusChannelMask &
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
       {
         /* END Msg(2:3892)-1 */
         /* Load the Absolute duty value in to the CDR Register */
         PWM_TAUDB_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     (uint16)LddCalculateDuty,
                    &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
         /* QAC Warning: START Msg(2:3892)-1 */
         PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     (uint16)LddCalculateDuty,
                     PWM_TAUDB_MASK_CDR,
                     PWM_SET_DUTYCYCLE_SID)
         /* END Msg(2:3892)-1 */
       }
       else
       {
         /* Report DEM if previous simultaneous rewrite is ongoing or
            failed */
            Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
       }
    }

    /* MISRA Violation: START Msg(4:3138)-18 */
    /* Set the corresponding channel Trigger bit to specifies the
       channel for which simultaneous rewrite is executed */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRDT,
                       LusChannelMask)
    /* END Msg(4:3138)-18 */

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
  }/* End of if (PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode) */
  else
  {
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* Initialize a pointer to the Master's control register configuration of
       TAUD/TAUB */
     LucTAUDBChannelReg =
        ((LpChannelConfig - (LpChannelConfig->ucMasterOffset))->ucCntlRegsIndx);
    /* END Msg(4:0488)-3 */

    /* Get the master's period */
    LddMasterPeriod = Pwm_GaaTAUDBChReg_BaseAddress[LucTAUDBChannelReg]->usCDR;

    /* Get the TAU Type in to the local variable */
    LucVar = LpChannelConfig->uiPwmTAUType;

    LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

    /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
    LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

    /* MISRA Violation: START Msg(4:2983)-10 */
    /* Get the masters channel ID*/
    LddChannelId = (LddChannelId - (LpChannelConfig->ucMasterOffset));
    /* END Msg(4:2983)-10 */

    /* MISRA Violation: START Msg(4:0311)-2 */
    /* MISRA Violation: START Msg(4:0316)-7 */
    /* Get the pointer to the TAUD/TAUB channel properties */
    LpTAUDBProperties = (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
    /* END Msg(4:0316)-7 */
    /* END Msg(4:0311)-2 */

    /* Get the channel mask from the channel configuration */
    LusChannelMask = LpTAUDBProperties->usChannelMask;

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* QAC Warning: START Msg(2:3892)-1 */
    /* calculate duty cycle */
    LddCalculateDuty = (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
    /* END Msg(2:3892)-1 */
    /* Check if the simultaneous rewrite operation is completed  */
    /* QAC Warning: START Msg(2:3892)-1 */
    if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusChannelMask &
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
    /* END Msg(2:3892)-1 */
    {
      /* Load the Absolute duty value in to the CDR Register */
      PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                   (uint16)LddCalculateDuty,
                  &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                   (uint16)LddCalculateDuty,
                   PWM_TAUDB_MASK_CDR,
                   PWM_SET_DUTYCYCLE_SID)
      /* END Msg(2:3892)-1 */
    }
    else
    {
      /* Report DEM if previous simultaneous rewrite is ongoing or
         failed */
      Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                          DEM_EVENT_STATUS_FAILED);
    }

    /* MISRA Violation: START Msg(4:3138)-18 */
    /* Set the corresponding channel Trigger bit to specifies the
       channel for which simultaneous rewrite is executed */
    PWM_WRITE_REG_ONLY(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRDT,
                 LusChannelMask)
    /* END Msg(4:3138)-18 */

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
  }

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  /* QAC Warning: START Msg(2:3892)-1 */
  /* Check whether the channels are set to their Idle state */
  if (PWM_TAUDB_CH_IDLE_STATE ==
                (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                                                LusChannelMask))
  /* END Msg(2:3892)-1 */
  {
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* calculate new value for TE register */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                              (~LusChannelMask);
    /* END Msg(4:4397)-8 */

    /* Disable the count operation */
    PWM_WRITE_REG_ONLY(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                 LusChannelMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                 LusTempReg,
                 PWM_TAUDB_MASK_TE,
                 PWM_SET_DUTYCYCLE_SID)

    /* MISRA Violation: START Msg(4:2983)-10 */
    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer stopped */
    if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                               LusChannelMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    /* END Msg(4:2983)-10 */
    /* END Msg(4:3344)-20 */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0491)-16 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* calculate new value for TOE register */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
            (LpTAUDBUnitConfig[LucUserCntlRegsIndx].usTOEMask & LusChannelMask);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-16 */

    /* Enable the output of the current channel */
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                 LusTempReg,
                &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                 LusTempReg,
                 PWM_TAUDB_MASK_TOE,
                 PWM_SET_DUTYCYCLE_SID)

    /* calculate new value for TE register */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                                 LusChannelMask;

    /* Start the count operation */
    PWM_WRITE_REG_ONLY(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                 LusChannelMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                 LusTempReg,
                 PWM_TAUDB_MASK_TE,
                 PWM_SET_DUTYCYCLE_SID)

    /* QAC Warning: START Msg(2:3892)-1 */
    /* check if timer started */
    if (PWM_TAUDB_CH_STOPPED ==
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                                LusChannelMask))
    /* END Msg(2:3892)-1 */
    {
      /* Implements: PWM_ESDD_UD_189                                          */
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
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

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif
  #endif
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
** Function Name        : Pwm_HW_SetPeriodAndDuty
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the Period and Duty cycle
**                        counter value in the hardware registers.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId, LddPeriod and LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpTAUDUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig
**
** Function invoked     : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION,
**                        Pwm_HW_SetDutyCycle, Pwm_HW_CalculateDuty,
**                        Dem_ReportErrorStatus
**
** Registers Used       : TAUDnCDRm, TAUBnCDRm, TAUDnRDT, TAUBnRDT, TAUDnTOE,
**                        TAUBnTOE, TAUDnTE, TAUBnTE, TAUDnTT, TAUBnTT, TAUDnTS,
**                        TAUBnTS, TAUJnCDRm, TAUJnRDT, TAUJnTOE, TAUJnTE,
**                        TAUJnTT, TAUJnTS, TAUBnRSF, TAUJnRSF, TAUDnRSF
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_113, EAAR_PN0066_FR_0092, EAAR_PN0066_FR_0054     */
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetPeriodAndDuty
(Pwm_ChannelType LddChannelId, Pwm_PeriodType LddPeriod, uint16 LusDutyCycle)
/* END Msg(2:3206)-6 */
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;

  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)

  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint16 LusMasterChannelMask;
  uint8 LucVar;
  uint8_least LucCount;
  uint8 LucNumSlaveChnls;
  uint8 LucCntlRegs;
  uint8 LucUserCntlRegsIndx;
  Pwm_PeriodType LddCalculateDuty;
  uint16 LusTempReg;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* MISRA Violation: START Msg(4:0488)-3 */
  /* QAC Warning: START Msg(2:2824)-4 */
  /* Initialize a pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0488)-3 */

  /* Implements:  EAAR_PN0066_FR_0013, EAAR_PN0066_FR_0016                    */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Set the period if the channel is master and set the duty of all the slaves
     of that master */
  if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
  /* END Msg(2:2814)-2 */
  {
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) \
        && (PWM_TAUJ_UNIT_USED == STD_ON))
    /* Check whether the channel belongs to TAUD/TAUB */
    if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
  /* END Msg(2:3892)-1 */
    #endif
    {
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

      LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

      /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
      LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* Update the TAUD/TAUB unit config pointer */
      LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig + LucUserCntlRegsIndx;
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0488)-3 */

      /* MISRA Violation: START Msg(4:0311)-2 */
      /* MISRA Violation: START Msg(4:0316)-7 */
      /* Get the pointer to the TAUD/TAUB channel properties */
      LpTAUDBProperties =
      (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
      /* END Msg(4:0316)-7 */
      /* END Msg(4:0311)-2 */

      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* QAC Warning: START Msg(2:3892)-1 */
      if (PWM_ZERO != LddPeriod)
      /* END Msg(2:3892)-1 */
      {
        /* Decrement the period value */
        LddPeriod--;
      }
      else
      {
        /* No action required */
      }

      /* QAC Warning: START Msg(2:2814)-2 */
      /* Get the Channel Mask of the Master channel for RSF & RDT registers */
      LusMasterChannelMask = LpTAUDBProperties->usChannelMask;
      /* END Msg(2:2814)-2 */

      /* Implements:  PWM019, SWS_Pwm_00019 */
      /* Check if the simultaneous rewrite operation is completed  */
      /* QAC Warning: START Msg(2:3892)-1 */
      if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusMasterChannelMask &
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
      /* END Msg(2:3892)-1 */
      {
        /* Load the period value in to the CDR register of the master channel */
        PWM_TAUDB_WRITE_REG_AND_MIRROR(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     (uint16)LddPeriod,
                     &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                   (uint16)LddPeriod,
                    PWM_TAUDB_MASK_CDR,
                    PWM_SET_PERIODANDDUTY_SID)
      /* END Msg(2:3892)-1 */
      }
      else
      {
         /* Implements: PWM_ESDD_UD_192                                       */
         /* Report DEM if previous simultaneous rewrite is ongoing or failed */
         Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED, DEM_EVENT_STATUS_FAILED);
      }

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* Get the number of slave channels configured for master channel */
      LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

      /* Increment the channel Id */
      LddChannelId++;

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer to the next channel*/
      LpChannelConfig++;
      /* END Msg(4:0489)-1 */

      /* QAC Warning: START Msg(2:3892)-1 */
      for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
      /* END Msg(2:3892)-1 */
      {

        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* MISRA Violation: START Msg(4:2983)-10 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
        (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */
        /* END Msg(4:2983)-10 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:3892)-1 */
        /* Implements:  PWM019, SWS_Pwm_00019 */
        /* calculate duty cycle */
        LddCalculateDuty = (uint16)Pwm_HW_CalculateDuty(LddPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
        /* END Msg(2:3892)-1 */
        /* Check if the simultaneous rewrite operation is completed  */
        /* QAC Warning: START Msg(2:3892)-1 */
        if (PWM_TAUDB_SIMUL_REWRITE_COMPLETE == (LusMasterChannelMask &
               (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRSF)))
        /* END Msg(2:3892)-1 */
        {
          /* Load the Absolute duty value in to the CDR Register */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                       &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                       (uint16)LddCalculateDuty,
                       &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                       &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                       (uint16)LddCalculateDuty,
                        PWM_TAUDB_MASK_CDR,
                        PWM_SET_PERIODANDDUTY_SID)
          /* END Msg(2:3892)-1 */
        }
        else
        {
          /* Report DEM if previous simultaneous rewrite is ongoing or
             failed */
          Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
        }
        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Increment the channel*/
        LddChannelId++;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the next channel*/
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */
      }

      /* Set the corresponding channels Trigger bits to specifies the
         channels for which simultaneous rewrite is executed */
      PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usRDT,
                    LusMasterChannelMask)

      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check whether the channel is set to its Idle state */
      if (PWM_TAUDB_CH_IDLE_STATE ==
              (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                                          LusMasterChannelMask))
      /* END Msg(2:3892)-1 */
      {
        /* MISRA Violation: START Msg(4:4397)-8 */
        /* calculate new value for TE register */
        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif
        LusTempReg =
                    Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                        (~LusMasterChannelMask);
        /* END Msg(4:4397)-8 */
        /* Stop count operation */
        PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                     LusMasterChannelMask)

        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                     LusTempReg,
                     PWM_TAUDB_MASK_TE,
                     PWM_SET_PERIODANDDUTY_SID)

        /* MISRA Violation: START Msg(4:3344)-20 */
        /* check if timer was stopped */
        if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                           LusMasterChannelMask)
        {
          /* Report to DEM */
          Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
        /* END Msg(4:3344)-20 */

        /* QAC Warning: START Msg(2:2814)-2 */
        /* calculate new value for TOE register */
        LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                          (LpTAUDBUnitConfig->usTOEMask & LusMasterChannelMask);
        /* END Msg(2:2814)-2 */
        /* Enable the output of the current channel */
        PWM_TAUDB_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                     LusTempReg,
                    &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                     LusTempReg,
                     PWM_TAUDB_MASK_TOE,
                     PWM_SET_PERIODANDDUTY_SID)

        /* calculate new value for TE register */
        LusTempReg =
                    Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                           LusMasterChannelMask;
        /* Start the count operation */
        PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                     LusMasterChannelMask)

        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                     LusTempReg,
                     PWM_TAUDB_MASK_TE,
                     PWM_SET_PERIODANDDUTY_SID)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:3892)-1 */
        /* check if timer was stopped */
        if (PWM_TAUDB_CH_STOPPED ==
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                         LusMasterChannelMask))
        /* END Msg(2:3892)-1 */
        {
          /* Report to DEM */
          Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
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
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
    /* channel belongs to TAUJ */
    else
    #endif
    {
      #if (PWM_TAUJ_UNIT_USED == STD_ON)

      LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

      /* MISRA Violation: START Msg(4:0311)-2 */
      /* MISRA Violation: START Msg(4:0316)-7 */
      /* Get the pointer to the TAUJ channel properties */
      LpTAUJProperties =
      (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
      /* END Msg(4:0316)-7 */
      /* END Msg(4:0311)-2 */

      /* Fetch the pointer to the current TAUJ Unit Registers */
      LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* Update the TAUD/TAUB unit config pointer */
      LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig + LucUserCntlRegsIndx;
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0488)-3 */

      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* QAC Warning: START Msg(2:3892)-1 */
      if (PWM_ZERO != LddPeriod)
      /* END Msg(2:3892)-1 */
      {
        /* Decrement the period value */
        LddPeriod--;
      }
      else
      {
        /* No action required */
      }

      /* QAC Warning: START Msg(2:2814)-2 */
      /* Get the Channel Mask of the Master channel for RDT & RSF registers */
      LusMasterChannelMask = (uint16)LpTAUJProperties->ucChannelMask;
      /* END Msg(2:2814)-2 */

      /* Implements:  PWM019, SWS_Pwm_00019 */
      /* Check if the simultaneous rewrite operation is completed  */
      /* QAC Warning: START Msg(2:3892)-1 */
      if (PWM_TAUJ_SIMUL_REWRITE_COMPLETED == (LusMasterChannelMask &
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRSF)))
      /* END Msg(2:3892)-1 */
      {
        /* Load the period value in to the CDR register of the master channel */
        PWM_TAUJ_WRITE_REG_AND_MIRROR(
                     &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                      LddPeriod,
                     &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                    LddPeriod,
                    PWM_TAUJ_MASK_CDR,
                    PWM_SET_PERIODANDDUTY_SID)
      }
      else
      {
          /* Report DEM if previous simultaneous rewrite is ongoing or
          failed */
          Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
      }

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* Get the number of slave channels configured for master channel */
      LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

      /* Increment the channel Id */
      LddChannelId++;

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer to the next channel*/
      LpChannelConfig++;
      /* END Msg(4:0489)-1 */

      /* QAC Warning: START Msg(2:3892)-1 */
      for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
      /* END Msg(2:3892)-1 */
      {
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* MISRA Violation: START Msg(4:2983)-10 */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */
        /* END Msg(4:2983)-10 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Implements:  PWM019, SWS_Pwm_00019 */
        /* Load the Absolute duty value in to the CDR Register */
        /* calculate duty cycle */
        LddCalculateDuty = Pwm_HW_CalculateDuty(LddPeriod,
                                          (Pwm_PeriodType)LusDutyCycle, LucVar);
        /* QAC Warning: START Msg(2:3892)-1 */
        if (PWM_TAUJ_SIMUL_REWRITE_COMPLETED == (LusMasterChannelMask &
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRSF)))
        /* END Msg(2:3892)-1 */
        {
          /* Load the Absolute duty value in to the CDR Register */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                       &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LddCalculateDuty,
                       &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                       &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LddCalculateDuty,
                        PWM_TAUJ_MASK_CDR,
                        PWM_SET_PERIODANDDUTY_SID)
        }
        else
        {
          /* Report DEM if previous simultaneous rewrite is ongoing or
          failed */
          Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                  DEM_EVENT_STATUS_FAILED);
        }
        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Increment the channel */
        LddChannelId++;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the next channel*/
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */
      }

      /* MISRA Violation: START Msg(4:3138)-18 */
      /* Set the corresponding channels Trigger bits to specifies the
         channels for which simultaneous rewrite is executed */
      PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucRDT,
             (uint8)LusMasterChannelMask)
      /* END Msg(4:3138)-18 */

      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check whether the channel is set to its Idle state */
      if (PWM_TAUJ_CH_IDLE_STATE ==
         (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                                   (uint8)LusMasterChannelMask))
      /* END Msg(2:3892)-1 */
      {
        /* MISRA Violation: START Msg(4:4397)-8 */
        /* calculate new value for TE register */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        LusTempReg =
                     Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                        (~LusMasterChannelMask);
        /* QAC Warning: START Msg(2:3892)-1 */
        LusTempReg &= PWM_MASK_LOW_NIBBLE;
        /* END Msg(2:3892)-1 */
        /* END Msg(4:4397)-8 */

        /* Stop count operation */
        PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
              (uint8)LusMasterChannelMask)

        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                    (uint8)LusTempReg,
                     PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                     PWM_SET_PERIODANDDUTY_SID)
        /* END Msg(2:3892)-1 */

        /* MISRA Violation: START Msg(4:3344)-20 */
        /* check if timer was stopped */
        if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                           LusMasterChannelMask)
        {
          /* Report to DEM */
          Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
        /* END Msg(4:3344)-20 */

        /* QAC Warning: START Msg(2:2814)-2 */
        /* calculate new value for TOE register */
        LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                       (LpTAUJUnitConfig->ucTOEMask & LusMasterChannelMask);
        /* END Msg(2:2814)-2 */
        /* QAC Warning: START Msg(2:3892)-1 */
        LusTempReg &= PWM_MASK_LOW_NIBBLE;
        /* Enable the output of the current channel */
        PWM_TAUJ_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
              (uint8)LusTempReg,
                    &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                    (uint8)LusTempReg,
                     PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                     PWM_SET_PERIODANDDUTY_SID)

        /* calculate new value for TE register */
        LusTempReg =
                     Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                                           LusMasterChannelMask;
        LusTempReg &= PWM_MASK_LOW_NIBBLE;
        /* Start count operation */
        PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
              (uint8)LusMasterChannelMask)

        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                     (uint8)LusTempReg,
                     PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                     PWM_SET_PERIODANDDUTY_SID)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* check if timer was stopped */
        if (PWM_TAUJ_CH_STOPPED ==
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                        LusMasterChannelMask))
        /* END Msg(2:3892)-1 */
        {
          /* Report to DEM */
          Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
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
  }
  /* Set the Duty cycle of the requested channel if Slave */
  else
  {
    #if (PWM_SET_DUTY_CYCLE_API == STD_ON)
    /* Set the Duty cycle for the slave channel */
    Pwm_HW_SetDutyCycle(LddChannelId, LusDutyCycle);
    #endif
  }
  #endif
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
** Function Name         : Pwm_HW_SetOutputToIdle
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function sets the output of a required channel
**                         to its configured Idle state.
**
**                         This API also sets the output of PWM PWGA
**                         channel to idle state with pin level low.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**
** Functions invoked     : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**                         Pwm_HW_StopDiagChannel
**
** Registers Used        : TAUDnTOE, TAUBnTOE, TAUDnTO, TAUBnTO, TAUJnTOE,
**                         TAUJnTO.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_114                                               */
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetOutputToIdle
(Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
   /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;

  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;

  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;
  uint8 LucDiagChannel;
  #endif /* (PWM_DIAG_UNIT_USED == STD_ON) */

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint8_least LucCount;
  uint8 LucNumSlaveChnls;
  uint8 LucUserCntlRegsIndx;
  uint16 LusTempReg;
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  /* Check if channel belongs to PWGA or TAU unit */
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* Get the pointer to the channel configuration */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */
    #endif

    #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check for the current channel Class Type is in Fixed Period Shifted */
    if ((PWM_FIXED_PERIOD_SHIFTED == LpChannelConfig->ddClassType) ||
        (PWM_VARIABLE_PERIOD_SHIFTED == LpChannelConfig->ddClassType))
    /* END Msg(2:2814)-2 */
    {

      /* MISRA Violation: START Msg(4:2983)-10 */
      /* Get the Master channel ID */
      LddChannelId = LddChannelId - LpChannelConfig->ucMasterOffset;
      /* END Msg(4:2983)-10 */

      /* Get the Timer Unit Index ID */
      LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

      /* MISRA Violation: START Msg(4:0488)-3 */
      /* Get the pointer to the Master channel config */
      LpChannelConfig = LpChannelConfig - LpChannelConfig->ucMasterOffset;
      /* END Msg(4:0488)-3 */

      /* MISRA Violation: START Msg(4:0311)-2 */
      /* MISRA Violation: START Msg(4:0316)-7 */
      /* Get the pointer to the TAUD/TAUB channel properties */
      LpTAUDBProperties =
      (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                      LpChannelConfig->pChannelProp;
      /* END Msg(4:0316)-7 */
      /* END Msg(4:0311)-2 */

      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* Update the TAUD/TAUB unit config pointer */
      LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig + LucUserCntlRegsIndx;
      /* END Msg(2:2824)-4 */

      /* END Msg(4:0488)-3 */
      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* Set the corresponding group channels bits to disable TOm operation */
      /* QAC Warning: START Msg(2:2814)-2 */
      LusTempReg =
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
      /* END Msg(2:2814)-2 */
      PWM_TAUDB_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                    LusTempReg,
                   &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
      PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                    LusTempReg,
                    PWM_TAUDB_MASK_TOE,
                    PWM_SET_OUTPUTTOIDLE_SID)

      /* QAC Warning: START Msg(2:2814)-2 */
      /* Reset the corresponding bit if Idle state */
      LusTempReg =
               ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                    ((uint16)(~LpTAUDBProperties->usChannelMask))) |
              (LpTAUDBProperties->usChannelMask & LpTAUDBUnitConfig->usTOMask));
      /* END Msg(2:2814)-2 */
      PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                    LusTempReg)
      PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                    LusTempReg,
                    PWM_TAUDB_MASK_TO,
                    PWM_SET_OUTPUTTOIDLE_SID)

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif
    }
    /* Implements:  PWM119, SWS_Pwm_00119 */
    /* Is the current channel Class Type is in Fixed / Variable Period */
    else
    #endif
    {
      #if (PWM_TAU_UNIT_USED == STD_ON)
      /* Implements:  EAAR_PN0066_FR_0016                                     */
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Check whether the channel is in Slave Mode */
      if (PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode)
      /* END Msg(2:2814)-2 */
      #endif
      {
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
           (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Check whether the channel belongs to TAUD/TAUB */
        if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
        /* END Msg(2:3892)-1 */
        #endif
        {
          #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUD/TAUB channel properties */
          LpTAUDBProperties =
          (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Get the Timer Unit Index ID */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* Set the corresponding channel bit to disable TOm operation */
          LusTempReg =
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                       PWM_TAUDB_MASK_TOE,
                       PWM_SET_OUTPUTTOIDLE_SID)

          /* QAC Warning: START Msg(2:3892)-1 */
          if ((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
          /* END Msg(2:3892)-1 */
          {
            /* Reset the corresponding bit if Idle state is LOW */
            LusTempReg =
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_OUTPUTTOIDLE_SID)
          }
          else
          {
            /* Set the corresponding bit if Idle state is HIGH */
            LusTempReg =
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO |
                                              LpTAUDBProperties->usChannelMask);
            PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_OUTPUTTOIDLE_SID)
          }

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
             (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* Channel belongs to TAUJ */
        else
        #endif
        {
          #if (PWM_TAUJ_UNIT_USED == STD_ON)

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Get the Timer Unit Index ID */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* MISRA Violation: START Msg(4:4491)-4 */
          /* QAC Warning: START Msg(2:2814)-2 */
          /* Set the corresponding channel bit to disable TOm operation */
          LusTempReg =
                 (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                 ((uint8)~(LpTAUJProperties->ucChannelMask)));
          /* END Msg(2:2814)-2 */
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                        &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                        PWM_SET_OUTPUTTOIDLE_SID)
          /* END Msg(4:4491)-4 */

          if ((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:4491)-4 */
            /* Reset the corresponding bit if Idle state is LOW */
            LusTempReg =
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                                   ((uint8)~(LpTAUJProperties->ucChannelMask)));
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                          (unsigned char)LusTempReg)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                          (uint8)LusTempReg,
                          PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                          PWM_SET_OUTPUTTOIDLE_SID)
            /* END Msg(2:3892)-1 */
            /* END Msg(4:4491)-4 */
          }
          else
          {
            /* MISRA Violation: START Msg(4:4491)-4 */
            /* Set the corresponding bit if Idle state is HIGH */
            LusTempReg =
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO |
                                               LpTAUJProperties->ucChannelMask);
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                          (unsigned char)LusTempReg)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                         (uint8)LusTempReg,
                          PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                          PWM_SET_OUTPUTTOIDLE_SID)
            /* END Msg(2:3892)-1 */
            /* END Msg(4:4491)-4 */
          }
          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
      }/* End of if (PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode) */
      /* Channel in Master Mode*/
      #if (PWM_TAU_UNIT_USED == STD_ON)
      else
      #endif
      {
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))\
          && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Check if channel belongs to TAUD/TAUB */
        if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
        /* END Msg(2:3892)-1 */
        #endif
        {
          #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* Get the Timer Unit Index ID */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* Get the number of slave channels configured for master channel */
          LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUD/TAUB channel properties */
          LpTAUDBProperties =
          (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                      LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* Set corresponding channel bit to disable TOm operation  */
          LusTempReg =
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                       PWM_TAUDB_MASK_TOE,
                       PWM_SET_OUTPUTTOIDLE_SID)

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */

          LddChannelId++;

          /* QAC Warning: START Msg(2:3892)-1 */
          for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
          /* END Msg(2:3892)-1 */
          {

            /* MISRA Violation: START Msg(4:0311)-2 */
            /* MISRA Violation: START Msg(4:0316)-7 */
            /* Get the pointer to the TAUD/TAUB channel properties */
            LpTAUDBProperties =
            (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
            /* END Msg(4:0316)-7 */
            /* END Msg(4:0311)-2 */

            /* QAC Warning: START Msg(2:3892)-1 */
            /* set IDLE value for each slave channel */
            if ((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
            /* END Msg(2:3892)-1 */
            {
              /* Reset the corresponding bit if Idle state is LOW */
              LusTempReg =
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                                ((uint16)~(LpTAUDBProperties->usChannelMask)));
              PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
              PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_OUTPUTTOIDLE_SID)
            }
            else
            {
              /* Set the corresponding bit if Idle state is HIGH */
              LusTempReg =
                   (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO |
                                              LpTAUDBProperties->usChannelMask);
              PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
              PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_OUTPUTTOIDLE_SID)
            }

            /* MISRA Violation: START Msg(4:0489)-1 */
            /* Increment the pointer to the next channel */
            LpChannelConfig++;
            /* END Msg(4:0489)-1 */

            /* Increment the channel Id */
            LddChannelId++;
          }

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))\
          && (PWM_TAUJ_UNIT_USED == STD_ON))
        /* channel belongs to TAUJ*/
        else
        #endif
        {
          #if (PWM_TAUJ_UNIT_USED == STD_ON)

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          /* Get the Timer Unit Index ID */
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

          /* Get the number of slave channels configured for master channel */
          LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */

          /* MISRA Violation: START Msg(4:4491)-4 */
          /* Set the corresponding channel bit to disable TOm operation */
          LusTempReg =
                 (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                 ((uint8)~(LpTAUJProperties->ucChannelMask)));
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                       &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                        PWM_SET_OUTPUTTOIDLE_SID)
          /* END Msg(2:3892)-1 */
          /* END Msg(4:4491)-4 */

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the channel to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */

          /* Increment the channel Id */
          LddChannelId++;

          /* QAC Warning: START Msg(2:3892)-1 */
          for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
          /* END Msg(2:3892)-1 */
          {
            /* MISRA Violation: START Msg(4:0311)-2 */
            /* MISRA Violation: START Msg(4:0316)-7 */
            /* Get the pointer to the TAUJ channel properties */
            LpTAUJProperties =
            (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
            /* END Msg(4:0316)-7 */
            /* END Msg(4:0311)-2 */

            /* QAC Warning: START Msg(2:3892)-1 */
            /* Set IDLE value for each slave channel */
            if ((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
            /* END Msg(2:3892)-1 */
            {
              /* MISRA Violation: START Msg(4:4491)-4 */
              /* Reset the corresponding bit if Idle state is LOW */
              LusTempReg =
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                                   ((uint8)~(LpTAUJProperties->ucChannelMask)));
              /* QAC Warning: START Msg(2:3892)-1 */
              LusTempReg &= PWM_MASK_LOW_NIBBLE;
              /* END Msg(2:3892)-1 */
              PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                         (unsigned char)LusTempReg)
              /* QAC Warning: START Msg(2:3892)-1 */
              PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                         (uint8)LusTempReg,
                         PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                         PWM_SET_OUTPUTTOIDLE_SID)
              /* END Msg(2:3892)-1 */
              /* END Msg(4:4491)-4 */
            }
            else
            {
              /* MISRA Violation: START Msg(4:4491)-4 */
              /* Set the corresponding bit if Idle state is HIGH */
              LusTempReg =
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO |
                                               LpTAUJProperties->ucChannelMask);
              /* QAC Warning: START Msg(2:3892)-1 */
              LusTempReg &= PWM_MASK_LOW_NIBBLE;
              /* END Msg(2:3892)-1 */
              PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                         (unsigned char)LusTempReg)
              /* QAC Warning: START Msg(2:3892)-1 */
              PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                         (uint8)LusTempReg,
                         PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                         PWM_SET_OUTPUTTOIDLE_SID)
              /* END Msg(2:3892)-1 */
              /* END Msg(4:4491)-4 */
            }

            /* MISRA Violation: START Msg(4:0489)-1 */
            /* Increment the pointer to the next channel */
            LpChannelConfig++;
            /* END Msg(4:0489)-1 */

            /* Increment the channel Id */
            LddChannelId++;
          }

          #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
          #endif

          #endif
        }
      }
    }
  }
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  else
  #endif
  {
    #if (PWM_DIAG_UNIT_USED == STD_ON)

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(4:2985)-15 */
    /* END Msg(4:0488)-3 */
    /* END Msg(2:2824)-4 */

    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;
    /* END Msg(2:2814)-2 */

    /* Invoke internal function to stop PWM PWGA channel */
    Pwm_HW_StopDiagChannel(LucDiagChannel, PWM_SET_OUTPUTTOIDLE_SID);

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    #endif
  }
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
** Function Name         : Pwm_HW_GetOutputState
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function gets the output state of a PWM channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LddRetOutputState
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpChannelConfig, Pwm_GpDiagGeneratortCntlRegs
**                         Pwm_GpDiagChannelConfig
**
** Functions invoked     : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**
** Registers Used        : TAUDnTO, TAUBnTO, TAUJnTO, PWGAnCNT, PWGAnCSBR,
**                         PWGAnCRBR.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_115                                               */
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(Pwm_OutputStateType, PWM_PRIVATE_CODE) Pwm_HW_GetOutputState
(Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint8 LucUserCntlRegsIndx;
  #endif

  Pwm_OutputStateType LddRetOutputState;

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;

  uint8 LucDiagChannelStatus;
  uint8 LucDiagGeneratortCntlRegs;

  /* temporary value to keep the Counter value */
  uint16 LusDiagCNT;
  #endif

  /* Default return output state */
  LddRetOutputState = PWM_LOW;

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Initialize a pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */

    /* Implements:  EAAR_PN0066_FR_0016                                       */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check whether the channel is in Slave Mode */
    if (PWM_SLAVE_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    {
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check whether the channel belongs to TAUD/TAUB */
      /* QAC Warning: START Msg(2:3892)-1 */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                        (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:3892)-1 */
      #endif
      {
        #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
        /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
        (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:2814)-2 */
        /* Condition to check current output state of the slave channel */
        if (((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO) &
            (LpTAUDBProperties->usChannelMask)) ==
                                           LpTAUDBProperties->usChannelMask)
        /* END Msg(2:2814)-2 */
        {
          LddRetOutputState = PWM_HIGH;
        }
        else
        {
          /* No action required */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #endif
      }
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if (PWM_TAUJ_UNIT_USED == STD_ON)

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
                   (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:2814)-2 */
        /* Condition to check the current output state of the slave channel */
        if (((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO) &
          (LpTAUJProperties->ucChannelMask)) == LpTAUJProperties->ucChannelMask)
        /* END Msg(2:2814)-2 */
        {
          LddRetOutputState = PWM_HIGH;
        }
        else
        {
          /* No action required */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #endif
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
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:2985)-15 */

    /* Get the IDLE status for DIAG channel */
    LucDiagChannelStatus = Pwm_HW_GetDiagChannelStatus(LddChannelId);

    if ((PWM_ZERO == LucDiagChannelStatus)
        #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
        || (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
        #endif
       )
    {
      #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
      if (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
      {
        /* MISRA Violation: START Msg(4:2985)-15 */
        LddRetOutputState = Pwm_GaaChannelConstantState[LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID];
        /* END Msg(4:2985)-15 */
        /* END Msg(4:0488)-3 */
      }
      else
      {
        /* No action required */
      }
      #endif

      if (PWM_ZERO == LucDiagChannelStatus)
      {
        LddRetOutputState = PWM_LOW;
      }
      else
      {
        /* No action required */
      }
    }
    else
    {
      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      /* QAC Warning: START Msg(2:2814)-2 */
      LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
      /* END Msg(2:2814)-2 */

      if ((Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR ==
           Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSBR) ||
          (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR ==
           PWM_DIAG_MAX_RESETTRIGGER_MASK))
      {
         if (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR ==
             PWM_DIAG_MAX_RESETTRIGGER_MASK)
         {
            LddRetOutputState = PWM_HIGH;
         }
         else
         {
          /* No action required */
         }
      }
      else
      {
         /* store the value of CNT register */
          LusDiagCNT =
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCNT;

         if (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR >
              Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSBR)
         {
            if ((LusDiagCNT >=
              Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSBR) &&
                (LusDiagCNT <
              Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR))
            {
                LddRetOutputState = PWM_HIGH;
            }
            else
            {
                /* No action required */
            }
         }
         else
         {
            if ((LusDiagCNT >=
              Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRBR) &&
                (LusDiagCNT <
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSBR))
            {
             /* No action required */
            }
            else
            {
               LddRetOutputState = PWM_HIGH;
            }
         }
      }

      #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
      #endif

      #if (PWM_SYNC_START_SUPPORT == STD_ON)
      if ((PWM_TRUE == LpDiagChannelConfig->blSyncStartReq) &&
          (PWM_SYNC_NOTSTARTED == Pwm_GblSyncStartStatus))
      {
        LddRetOutputState = PWM_LOW;
      }
      else
      {
        /* No action required */
      }
     #endif
    }
    #endif
  }
  /* Implements:  PWM022, SWS_Pwm_00022 */
  return LddRetOutputState;
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
** Function Name         : Pwm_HW_GetDiagChannelStatus
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function return the status of the corresponding
**                         PWM DIAG channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Channel Status (FALSE if IDLE, TRUE if STARTED)
**
** Pre-conditions        : NA
**
** Global Variables used : None
**
** Functions invoked     : None
**
** Registers Used        : SLPWGA0, SLPWGA1, SLPWGA2.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_203                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(uint8, PWM_PRIVATE_CODE) Pwm_HW_GetDiagChannelStatus
                                                  (Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
   /* Pointer to base address of PWGA Unit Generator control registers */
   P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA)
                                                        LpDiagSyncStartCntlRegs;
   /* Pointer to the channel configuration */
   P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
   uint8 LucDiagChannelStatus;
   Pwm_ChannelType LddDiagChannel;
   uint32 LulDiagMaskValue;

   LucDiagChannelStatus = PWM_FALSE;
   /* QAC Warning: START Msg(2:3892)-1 */
   LulDiagMaskValue = PWM_ZERO;
   /* END Msg(2:3892)-1 */

   /* MISRA Violation: START Msg(4:0488)-3 */
   /* MISRA Violation: START Msg(4:2985)-15 */
   /* QAC Warning: START Msg(2:2824)-4 */
   LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
   /* END Msg(2:2824)-4 */
   /* END Msg(4:2985)-15 */
   /* END Msg(4:0488)-3 */

   /* QAC Warning: START Msg(2:2814)-2 */
   LddDiagChannel = LpDiagChannelConfig->ucDiagChannel;
   /* END Msg(2:2814)-2 */

   /* QAC Warning: START Msg(2:2814)-2 */
   /* Point to base address of SLPWGAm register */
   LpDiagSyncStartCntlRegs =
         ((volatile SLPWGAReg *) Pwm_GpDiagUnitConfig->pDiagSyncStartCntlRegs);

   /* Implements:  PWM_ESDD_UD_228                                            */
   /* Check if PWGA channel belongs to 1st group */
   if (PWM_DIAG_MAX_GROUP1_ID >= LddDiagChannel)
   {
      LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA0;
   }
   /* END Msg(2:2814)-2 */
   else
   {
      /* QAC Warning: START Msg(2:3892)-1 */
      #if (PWM_DIAG_GROUP2_ID_SUPPORT == STD_ON)
      /* Check if PWGA channel belongs to 2nd group */
      if (PWM_DIAG_MAX_GROUP2_ID >= LddDiagChannel)
      {
         /* Subtract the value from 32 to get the actual bit to be set */
         LddDiagChannel = LddDiagChannel - (PWM_DIAG_MAX_GROUP1_ID + PWM_ONE);
         LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA1;
      }
      else
      {
         /* Implements PWM_ESDD_UD_228 */
         #if (PWM_DIAG_GROUP3_ID_SUPPORT == STD_ON)
         /* Check id PWGA channel belongs to 3rd group */
         if (PWM_DIAG_MAX_GROUP3_ID >= LddDiagChannel)
         {
           /* Subtract the value from 64 to get the actual bit to be set */
           LddDiagChannel = LddDiagChannel -
                                            (PWM_DIAG_MAX_GROUP2_ID + PWM_ONE);

           LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA2;
         }
         else
         {
           /* No action required */
         }
         #endif
      }
      #endif
      /* END Msg(2:3892)-1 */
   }
   /* MISRA Violation: START Msg(4:2792)-21 */
   /* QAC Warning: START Msg(2:3892)-1 */
   if (PWM_ZERO == (LulDiagMaskValue & (PWM_DIAG_ONE << LddDiagChannel)))
   {
       /* No action required */
   }
   else
   {
      LucDiagChannelStatus = PWM_TRUE;
   }
   /* END Msg(4:2792)-21 */
   /* END Msg(2:3892)-1 */
   return LucDiagChannelStatus;
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
** Function Name         : Pwm_HW_CalculateDuty
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function Calculates Absolute duty for the
**                         PWM channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddAbsolutePeriod, LddRelativeDuty and LucTAUType
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LddAbsoluteDuty
**
** Pre-conditions        : NA
**
** Global Variables used : None
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_117                                               */
/* Implements:  PWM_ESDD_UD_016                                               */
/* Implements:  PWM058, PWM059                                                */
/* Implements:  SWS_Pwm_00058, SWS_Pwm_00059                                  */
#if (PWM_TAU_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC(Pwm_PeriodType, PWM_PRIVATE_CODE) Pwm_HW_CalculateDuty
(Pwm_PeriodType LddAbsolutePeriod, Pwm_PeriodType LddRelativeDuty,
                                                               uint8 LucTAUType)
/* END Msg(2:3206)-6 */
/* END Msg(2:3227)-3 */
{
  Pwm_PeriodType  LddAbsoluteDuty;
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  Pwm_PeriodType  LddCorrectionPeriod;
  #endif

  /* QAC Warning: START Msg(2:3892)-1 */
  if (MAX_DUTY_CYCLE == LddRelativeDuty)
  /* END Msg(2:3892)-1 */
  {
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
    if ((PWM_HW_TAUD == LucTAUType) || (PWM_HW_TAUB == LucTAUType))
    #endif
    {
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
      /* QAC Warning: START Msg(2:3892)-1 */
      /* If Duty is 100%, Update (CDRm (master channel) setting value + 1)
         value in the CDRm register */
      LddAbsoluteDuty = (Pwm_PeriodType)LddAbsolutePeriod + PWM_ONE;
    /* END Msg(2:3892)-1 */
      #endif
    }
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
    else
    #endif
    {
      #if (PWM_TAUJ_UNIT_USED == STD_ON)
      /* QAC Warning: START Msg(2:3892)-1 */
      /* If Duty is 100%, Update (CDRm (master channel) setting value + 1) value
         in the CDRm register */
      LddAbsoluteDuty =  LddAbsolutePeriod + PWM_ONE;
      /* END Msg(2:3892)-1 */
      #endif
    }
  }

  /* QAC Warning: START Msg(2:3892)-1 */
  /* Implements:  PWM009b, SWS_Pwm_20009 */
  else if (MIN_DUTY_CYCLE == LddRelativeDuty)
  {
    /* If Duty is 0%, Update 0x0000 value in the CDRm register */
    LddAbsoluteDuty = MIN_DUTY_CYCLE;
  /* END Msg(2:3892)-1 */
  }
  else
  {
    /* Increment the period values since the CDR(master) was loaded with
       1 less */
    LddAbsolutePeriod++;
    #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
    if ((PWM_HW_TAUD == LucTAUType) || (PWM_HW_TAUB == LucTAUType))
    #endif
    {
      /* Implements:  PWM009c, SWS_Pwm_30009 */
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

      /* QAC Warning: START Msg(2:3892)-1 */
      /* If Duty is between 0x0000 and 0x8000,
         AbsoluteDutyCycle = (AbsolutePeriodTime * RelativeDutyCycle) >> 15 */
      LddAbsoluteDuty = (uint16)
                   ((LddAbsolutePeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV);
      /* END Msg(2:3892)-1 */
      #endif
    }
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) \
                                              && (PWM_TAUJ_UNIT_USED == STD_ON))
    else
    #endif
    {
      #if (PWM_TAUJ_UNIT_USED == STD_ON)
      /* QAC Warning: START Msg(2:3892)-1 */
      if (LddAbsolutePeriod > PWM_PERIOD_LIMIT)
      /* END Msg(2:3892)-1 */
      {
        /* Implements:  PWM009c, SWS_Pwm_30009 */
        /* Implements:  PWM059, SWS_Pwm_00059 */
        /* If Period > 0xFFFF and Duty is between 0x0000 and 0x8000 */
         LddCorrectionPeriod = LddAbsolutePeriod & PWM_CORRECTION_MASK;

         /* QAC Warning: START Msg(2:3892)-1 */
         LddAbsoluteDuty = (uint32)
         (((LddAbsolutePeriod >> PWM_DUTY_CALC_DIV) * LddRelativeDuty) +
         ((LddCorrectionPeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV));
         /* END Msg(2:3892)-1 */
      }
      else
      {
        /* Implements:  PWM009c, SWS_Pwm_30009 */
        /* Implements:  PWM059, SWS_Pwm_00059 */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* If Duty is between 0x0000 and 0x8000,
           AbsoluteDutyCycle = (AbsolutePeriodTime * RelativeDutyCycle) >> 15 */
        LddAbsoluteDuty =
        ((LddAbsolutePeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV);
        /* END Msg(2:3892)-1 */
      }
      #endif
    }
  }
  return LddAbsoluteDuty;
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
** Function Name         : Pwm_HW_CalDiagResetTriggerPoint
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function Calculates Reset condition of
**                         duty for the PWGA channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LusDutyCycle, LusOffset, LusDiagPeriod
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LusResetCondition
**
** Pre-conditions        : NA
**
** Global Variables used : None
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_139                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
/* QAC Warning: START Msg(2:3227)-3 */
FUNC(uint16, PWM_PRIVATE_CODE) Pwm_HW_CalDiagResetTriggerPoint
(Pwm_DiagPeriodType LusDutyCycle, uint16 LusOffset, uint16 LusDiagPeriod)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0034_FR_0049                                         */
  uint16 LusResetCondition;
  if (MAX_DUTY_CYCLE == LusDutyCycle)
  {
    /* Load the Reset condition value as max ie 0x1FFF */
    LusResetCondition = PWM_DIAG_MAX_RESETTRIGGER_MASK;
  }
  else if (MIN_DUTY_CYCLE == LusDutyCycle)
  {
    /* Load the Reset condition value same as Set condition value */
    LusResetCondition = LusOffset;
  }
  else
  {
    /* Calculation of the Reset condition */
    LusResetCondition = (uint16)
       ((((LusDiagPeriod + PWM_ONE) * LusDutyCycle) >>
       (uint16)PWM_DUTY_CALC_DIV) + LusOffset);

    /* If calculated Reset condition is greater maximum count value then
       the calculated value is subtracted from the maximum count */
    if (LusResetCondition > LusDiagPeriod)
    {
    /* QAC Warning: START Msg(2:3892)-1 */
      LusResetCondition = LusResetCondition - LusDiagPeriod - PWM_ONE;
    /* END Msg(2:3892)-1 */
    }
    else
    {
      /* No action required */
    }
  }
  return LusResetCondition;
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
** Function Name         : Pwm_HW_Callback
**
** Service ID            : NA
**
** Description           : This routine is used to invoke the callback
**                         notification. This routine also supports
**                         PwmSetChannelOutput functionality for TAU channels.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpChannelConfig, Pwm_GaaNotifStatus
**                         Pwm_GaaChannelConstantStatus
**
** Functions invoked     : None
**
** Registers Used        : TAUDnTOE, TAUBnTOE, TAUJnTOE, ICTAUBm, ICTAUDm,
**                         ICTAUJm
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_118                                               */
/* Implements:  PWM025, PWM026, PWM115c, EAAR_PN0034_FR_0060                  */
/* Implements:  SWS_Pwm_00025, SWS_Pwm_00026, SWS_Pwm_30115                   */
/* Implements:  PWM_ESDD_UD_019                                               */
#if (PWM_TAU_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_FAST_CODE) Pwm_HW_Callback(Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_FAST_CONST) LpChannelConfig;
  #endif

  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Variables to store the initial values of Channel Id and Channel Config */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_FAST_CONST) LpChannelCfg;
  uint8 LucChannelId;
  #endif

  #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_FAST_DATA) LpTAUDBProperties;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_FAST_DATA) LpTAUJProperties;
  #endif

  uint8_least LucCount;
  uint8 LucNumSlaveChnls;
  uint8 LucUserCntlRegsIndx;
  uint16 LusTempReg;
  #endif

  #if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || \
                                         (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))

  /* MISRA Violation: START Msg(4:0488)-3 */
  /* QAC Warning: START Msg(2:2824)-4 */
  /* Initialize a pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0488)-3 */
  #endif

  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Initial values of Channel Id and Channel Config are stored */
  LucChannelId = LddChannelId;
  LpChannelCfg = LpChannelConfig;
  #endif

  #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:2814)-2 */
  if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
  /* END Msg(2:2814)-2 */
  /* END Msg(2:3892)-1 */
  {
    if (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
    {
      /* Set the Constant state of the master channel to PWM_FALSE */
      Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_FALSE;

      #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
         (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check whether the channel belongs to TAUD/TAUB */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:3892)-1 */
      #endif
      {
        #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

        /* Initialize a pointer to the Master's control register
           configuration of TAUD/TAUB */


        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
          (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* Disable TAUDB master channel interrupt if Pwm_GaaNotifStatus is
           false */
        if (PWM_FALSE == Pwm_GaaNotifStatus[LddChannelId])
        #endif
        {
          /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                */
          /* Disabling the Interrupt processing of the current channel */
          RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAddress),
                                                      PWM_INTERRUPT_MASK_DIS);
        }
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        else
        {
          /* No action required */
        }
        #endif

        /* Get the number of slave channels configured for master channel */
        LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the slave channel */
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */

        /* Increment the channel Id*/
        LddChannelId++;

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:3892)-1 */
        for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
        /* END Msg(2:3892)-1 */
        {
          /* Check whether the channel is set to Constant state */
          if (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
          {
            /* QAC Warning: START Msg(2:2814)-2 */
            /* calculate new value for TOE register */
            LusTempReg =
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                                              LpTAUDBProperties->usChannelMask);
            /* END Msg(2:2814)-2 */
            /* Enable the output of the current channel */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
            PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                  (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TOE,
                        PWM_TAU_ISR_SID)

            /* Set the Constant state of the channel to PWM_FALSE */
            Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_FALSE;
          }
          else
          {
            /* No action required */
          }

          /* Increment the channel Id */
          LddChannelId++;

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #endif
      }
      #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
            (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if (PWM_TAUJ_UNIT_USED == STD_ON)

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* Disable TAUJ master channel interrupt if Pwm_GaaNotifStatus is
           false */
        if (PWM_FALSE == Pwm_GaaNotifStatus[LddChannelId])
        #endif
        {
          /* Implements:  PWM_ESDD_UD_187,EAAR_PN0034_FR_0067                 */
          /* Disabling the Interrupt processing of the current channel */
          RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAddress),
                                                    PWM_INTERRUPT_MASK_DIS);
        }
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        else
        {
          /* No action required */
        }
        #endif

        /* Get the number of slave channels configured for master channel */
        LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

        /* Increment the channel Id */
        LddChannelId++;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the next channel */
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* QAC Warning: START Msg(2:3892)-1 */
        for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
        /* END Msg(2:3892)-1 */
        {
          /* Check whether the channel is set to Constant state */
          if (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
          {

            /* MISRA Violation: START Msg(4:4491)-4 */
            /* QAC Warning: START Msg(2:2814)-2 */
            /* calculate new value for TOE register */
            LusTempReg =
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                                               LpTAUJProperties->ucChannelMask);
            /* END Msg(2:2814)-2 */
            /* QAC Warning: START Msg(2:3892)-1 */
            LusTempReg &= PWM_MASK_LOW_NIBBLE;
            /* END Msg(2:3892)-1 */
            /* END Msg(4:4491)-4 */

            /* Enable the output of the current channel */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                 (uint8)LusTempReg,
                       &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
            /* QAC Warning: START Msg(2:3892)-1 */
            PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                        PWM_TAU_ISR_SID)
            /* END Msg(2:3892)-1 */

            /* Set the Constant state of the channel to PWM_FALSE */
            Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_FALSE;
          }
          else
          {
            /* No action required */
          }

          /* Increment the channel Id */
          LddChannelId++;

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #endif
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

  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Check if Notification status is enabled for this channel */
  if (PWM_TRUE == Pwm_GaaNotifStatus[LucChannelId])
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Invoke the Notification function */
    if (NULL_PTR != LpChannelCfg->pPwmEdgeNotifPtr)
    /* END Msg(2:2814)-2 */
    {
      LpChannelCfg->pPwmEdgeNotifPtr();
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
** Function Name         : Pwm_HW_EnableNotification
**
** Service ID            : NA
**
** Description           : This routine is used to disable pending interrupts
**                         and enable Interrupt processing.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**
** Functions invoked     : None
**
** Registers Used        : ICTAUBm, ICTAUDm , ICTAUJm, ICPWGAm, PWGAINTMSK00,
**                         PWGAINTMSK01, PWGAINTMSK02.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_119, PWM_ESDD_UD_044                              */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_EnableNotification
                                                  (Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  uint32 LulPwgaIntMskValue;
  #endif
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Initialize a pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */
    #endif
  }
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  else
  #endif
  {
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:2985)-15 */
    /* END Msg(4:0488)-3 */
    #endif
  }

  /* Implements:  PWM_ESDD_UD_067, EAAR_PN0066_FR_0024, EAAR_PN0066_FR_0042   */
  #if (PWM_CLEAR_PENDING_INTERRUPT == STD_ON)

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check if the Interrupt register is present for particular channel */
    if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
    /* END Msg(2:2814)-2 */
    {
      /* Implements:  PWM081, SWS_Pwm_00081, PWM_ESDD_UD_187                  */
      /* MISRA Violation: START Msg(4:0489)-1 */
      /* MISRA Violation: START Msg(4:0310)-6 */
      RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                 (PWM_CLEAR_PENDING_INTR_MASK));
      /* END Msg(4:0310)-6 */
      /* END Msg(4:0489)-1 */
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
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* Check if the Interrupt register is present for particular channel */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (NULL_PTR != LpDiagChannelConfig->pDiagIntrCntlAddress)
    /* END Msg(2:2814)-2 */
    {
      /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                     */
      /* MISRA Violation: START Msg(4:0489)-1 */
      /* MISRA Violation: START Msg(4:0310)-6 */
      RH850_SV_MODE_ICR_AND(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                 (PWM_CLEAR_PENDING_INTR_MASK));
      /* END Msg(4:0310)-6 */
      /* END Msg(4:0489)-1 */
    }
    else
    {
      /* No action required */
    }
    #endif
  }
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check the Notification is configured for the current channel */
    if (NULL_PTR != LpChannelConfig->pPwmEdgeNotifPtr)
    /* END Msg(2:2814)-2 */
    {
      /* Implements:  PWM024, SWS_Pwm_00024, PWM_ESDD_UD_187 */
      /* Enable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                 PWM_INTERRUPT_MASK_EN);
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
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (NULL_PTR != LpDiagChannelConfig->pPwmEdgeNotifPtr)
    {

      /* Implements:  PWM_ESDD_UD_227                                         */
      #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
      /* Check whether channel belongs to group0 */
      if ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP1)
      {

       /* QAC Warning: START Msg(2:3892)-1 */
       /* Unmask channel interrupt in register PWGAINTMSK00 */
       LulPwgaIntMskValue =
                    (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK)
                   & ~((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel));

       PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00
                   )

       PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_ENABLENOTIFICATION_SID)
       }
       /* END Msg(2:3892)-1 */
       /* Check whether channel belongs to group1 */
       else if ((PWM_DIAG_GROUP1 <= (LpDiagChannelConfig->ucDiagChannel)) &&
                       ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP2))
       {
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Unmask channel interrupt in register PWGAINTMSK01 */
        LulPwgaIntMskValue =
                 (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK)
        & ~((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                             PWM_DIAG_GROUP1));

        PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01
                   )

        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_ENABLENOTIFICATION_SID)
       }
       /* END Msg(2:3892)-1 */
       /* Implements:  PWM_ESDD_UD_181                                        */
       /* Check whether channel belongs to group2 */
       else if ((PWM_DIAG_GROUP2 <= (LpDiagChannelConfig->ucDiagChannel)) &&
               ((LpDiagChannelConfig->ucDiagChannel) < PWM_TOTAL_DIAG_CHANNELS))
       {
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Unmask channel interrupt in register PWGAINTMSK02 */
        LulPwgaIntMskValue =
                (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK)
        & ~((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                             PWM_DIAG_GROUP2));

        PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02
                   )

        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_ENABLENOTIFICATION_SID)
        /* END Msg(2:3892)-1 */
       }
       else
       {
        /* No action required */
       }
       #endif

      /* Implements:  PWM024, SWS_Pwm_00024, PWM_ESDD_UD_187 */
      /* Enable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_AND(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                         PWM_INTERRUPT_MASK_EN);
    }
    else
    {
      /* No action required */
    }
    #endif
  }
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
** Function Name         : Pwm_HW_DisableNotification
**
** Service ID            : NA
**
** Description           : This routine is used to enable Interrupt processing.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig
**
** Functions invoked     : None
**
** Registers Used        : ICTAUBm, ICTAUDm , ICTAUJm, ICPWGAm, PWGAINTMSK00,
**                         PWGAINTMSK01, PWGAINTMSK02.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_120, PWM_ESDD_UD_044                              */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_DisableNotification
                                                  (Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  uint32 LulPwgaIntMskValue;
  #endif
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Initialize a pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check the Notification is configured for the current channel */
    if (NULL_PTR != LpChannelConfig->pPwmEdgeNotifPtr)
    /* END Msg(2:2814)-2 */
    {
      /* Implements:  PWM023, SWS_Pwm_00023 */
      /* Implements:  PWM026, SWS_Pwm_00026, EAAR_PN0034_FR_0067 */
      /* Implements:  PWM025, SWS_Pwm_00025, PWM_ESDD_UD_187 */
      /* Disabling the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAddress),
                                                  PWM_INTERRUPT_MASK_DIS);
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
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:2985)-15 */
    /* END Msg(4:0488)-3 */

    /* Check the Notification is configured for the current channel */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (NULL_PTR != LpDiagChannelConfig->pPwmEdgeNotifPtr)
    /* END Msg(2:2814)-2 */
    {
       /* Implements:  PWM_ESDD_UD_227                                        */
       #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
       /* Check whether channel belongs to group0 */
       if ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP1)
       {

        /* QAC Warning: START Msg(2:3892)-1 */
        /* Mask channel interrupt in register PWGAINTMSK00 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        LulPwgaIntMskValue =
            (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK)
                    | ((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel));

        PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00
                   )

        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_DISABLENOTIFICATION_SID)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        if ( Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK ==
                                                          PWM_PWGAINTMSK_RESET)
        /* END Msg(2:3892)-1 */
        {
           /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
           /* Disable the Interrupt processing of the group0 */
           RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
        }
    else
    {
      /*do nothing*/
    }
       }
       /* Check whether channel belongs to group1 */
       else if ((PWM_DIAG_GROUP1 <= (LpDiagChannelConfig->ucDiagChannel)) &&
                       ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP2))
       {
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Mask channel interrupt in register PWGAINTMSK01 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        LulPwgaIntMskValue =
             (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK)
        | ((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                              PWM_DIAG_GROUP1));

        PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01
                   )

        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_DISABLENOTIFICATION_SID)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        if (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK ==
                                                          PWM_PWGAINTMSK_RESET)
        /* END Msg(2:3892)-1 */
        {
           /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
           /* Disable the Interrupt processing of group1 */
           RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
        }
    else
    {
      /*do nothing*/
    }
       }
       /* Implements:  PWM_ESDD_UD_181                                        */
       /* Check whether channel belongs to group2 */
       else if ((PWM_DIAG_GROUP2 <= (LpDiagChannelConfig->ucDiagChannel)) &&
               ((LpDiagChannelConfig->ucDiagChannel) < PWM_TOTAL_DIAG_CHANNELS))
       {
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Mask channel interrupt in register PWGAINTMSK02 */

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        LulPwgaIntMskValue =
            (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK)
            | ((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                              PWM_DIAG_GROUP2));

        PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02
                   )

        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                   LulPwgaIntMskValue,
                   PWM_PWGA_MASK_PWGAINTMSK,
                   PWM_DISABLENOTIFICATION_SID)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        if (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK ==
                                                           PWM_PWGAINTMSK_RESET)
        /* END Msg(2:3892)-1 */
        {
           /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
           /* Disable the Interrupt processing of group2 */
           RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
        }
    else
    {
      /*do nothing*/
    }
       }
      else
      {
          /* No action required */
      }

      #else
      /* Implements:  PWM023, SWS_Pwm_00023, EAAR_PN0034_FR_0067 */
      /* Implements:  PWM026, SWS_Pwm_00026, PWM_ESDD_UD_187 */
      /* Disabling the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                     PWM_INTERRUPT_MASK_DIS);
     #endif

    }
    else
    {
      /* No action required */
    }
    #endif
  }
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
** Function Name        : Pwm_HW_SelectChannelClk
**
** Service ID           : NA
**
** Description          : This function updates the clock source select value in
**                        hardware register.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId
                          LddClockSource
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpDiagChannelConfig, Pwm_GpChannelConfig
**                        Pwm_GpDiagChannelConfig, Pwm_GpDiagGeneratortCntlRegs,
**                        Pwm_GaaChannelCurrDutyCycle
**
** Functions invoked    : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION,
**                        Pwm_HW_StartDiagChannel, Pwm_HW_StopDiagChannel,
**                        Dem_ReportErrorStatus
**
** Registers Used       : TAUDnTE, TAUBnTE, TAUDnTT, TAUBnTT, TAUDnCMORm,
**                        TAUBnCMORm, TAUDnTS, TAUBnTS, TAUJnCMORm, TAUJnTE,
**                        TAUJnTT, TAUJnTS, PWGAnCTL, PWGAnCRDR, PWGAnCSDR,
**                        PWGAnRSF, PWGAnRDT, PWGAnCTDR.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_155, PWM_ESDD_UD_012, PWM_ESDD_UD_018             */
/* Implements:  PWM_ESDD_UD_148, PWM_ESDD_UD_150, EAAR_PN0066_FR_0081         */
/* Implements:  EAAR_PN0066_FR_0055                                           */
#if (PWM_SELECT_CHANNEL_CLK_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SelectChannelClk
              (Pwm_ChannelType LddChannelId, Pwm_ClockSourceType LddClockSource)
/* END Msg(2:3227)-3 */
{
  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((((PWM_TAUD_UNIT_USED == STD_ON) || \
         (PWM_TAUB_UNIT_USED == STD_ON)) && \
         (PWM_TAUDB_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)) ||\
         ((PWM_TAUJ_UNIT_USED == STD_ON) &&\
         (PWM_TAUJ_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)))
  uint16 LusTempReg;
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  #endif

  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;
  uint8 LucDiagGeneratortCntlRegs;

  uint32 LulTempVal;

  Pwm_ClockSourceType LddPrevClockSource;

  uint16 LusDutyCycle;
  uint16 LusPrevPrescalerVal;
  uint16 LusCurrPrescalerVal;
  uint16 LusPrevCSDRVal;
  uint16 LusCurrCSDRVal;
  uint16 LusCRDRVal;
  uint16 LusPrevCTDRVal;
  uint16 LusCurrCTDRVal;
  uint8  LucDiagChannelStatus;
  uint8 LucCurrCTLVal;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  uint16 LusCMORVal;
  uint16 LusClockSource;
  uint8_least LucCount;
  uint8 LucNumSlaveChnls;
  uint8 LucUserCntlRegsIndx;
  uint8 LucCntlRegs;
  /* temporary value to store TAU status - enabled or disabled */
  uint16 LusTAUStatusVal;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  uint8 LucDiagChannel;
  uint16 LusDiagPeriod;
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  uint8 LucPwmShift;
  #endif
  #endif
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  /* Check if channel belongs to PWGA or TAU unit */
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */

    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (PWM_MASTER_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    {
      #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
              (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check whether the channel belongs to TAUD/TAUB */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:3892)-1 */
      #endif
      {
        #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
            (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* Save the existing CMOR register value */
        LusCMORVal = ((Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR) &
                                                                 PWM_CMOR_MASK);

        LusClockSource = (uint16)LddClockSource;
        /* QAC Warning: START Msg(2:3892)-1 */
        LusClockSource = LusClockSource << PWM_CKS_BITS_POSITION;
        /* END Msg(2:3892)-1 */

        /* Modify only 14 and 15 bit of variable */
        LusCMORVal = LusCMORVal | LusClockSource;

        /* QAC Warning: START Msg(2:2814)-2 */
        /* store TAUD/B status */
        LusTAUStatusVal =
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                              LpTAUDBProperties->usChannelMask);
        /* END Msg(2:2814)-2 */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Check TAUD/B channel is in stopped state */
        if (LusTAUStatusVal != PWM_TAUDB_CH_STOPPED)
        /* END Msg(2:3892)-1 */
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          #if (PWM_TAUDB_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
          /* calculate new value for TE register */
          LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                            (~LpTAUDBProperties->usChannelMask);
          #endif
          /* END Msg(4:4397)-8 */

          /* Stop the count operation */
          PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                        LpTAUDBProperties->usChannelMask)

          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SELECT_CHANNEL_CLK_SID)

          /* MISRA Violation: START Msg(4:3344)-20 */
          /* check if timer started */
          if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                               LpTAUDBProperties->usChannelMask)
          {
            /* Implements: PWM_ESDD_UD_189                                    */
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
          else
          {
            /* No action required */
          }
          /* END Msg(4:3344)-20 */
        }
        else
        {
          /* No action required */
        }
        /* Implements: PWM_ESDD_UD_028                                        */
        /* Update the CMORm register of Master with new clock source */
        PWM_TAUDB_WRITE_REG_AND_MIRROR(
                      &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                       LusCMORVal,
                      &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                     (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                       LusCMORVal,
                       PWM_TAUDB_MASK_CMOR,
                       PWM_SELECT_CHANNEL_CLK_SID)

        /* Get the number of slave channels configured for master channel */
        LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the slave channel */
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */

        /* QAC Warning: START Msg(2:3892)-1 */
        for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
        /* END Msg(2:3892)-1 */
        {
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* MISRA Violation: START Msg(4:2983)-10 */
          /* Get the pointer to the TAUD/TAUB channel properties */
          LpTAUDBProperties =
            (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */
          /* END Msg(4:2983)-10 */

          /* Save the existing CMOR register value */
          LusCMORVal = ((Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR) &
                                                                 PWM_CMOR_MASK);
          LusClockSource = (uint16)LddClockSource;
          /* QAC Warning: START Msg(2:3892)-1 */
          LusClockSource = (LusClockSource << PWM_CKS_BITS_POSITION);
          /* END Msg(2:3892)-1 */

          /* Modify only 14 and 15 bit of variable */
          LusCMORVal = LusCMORVal | LusClockSource;

          /* Update the CMORm register of Slave with new clock source */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LusCMORVal,
                        &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                       (&Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LusCMORVal,
                         PWM_TAUDB_MASK_CMOR,
                         PWM_SELECT_CHANNEL_CLK_SID)

          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */
        }

        /* QAC Warning: START Msg(2:3892)-1 */
        /* restart TAUD/B channel */
        if (LusTAUStatusVal != PWM_TAUDB_CH_STOPPED)
        /* END Msg(2:3892)-1 */
        {
          #if (PWM_TAUDB_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
          /* calculate new value for TE register */
          LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                                                LusTAUStatusVal;
          #endif
          /* Start the count operation */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                        LusTAUStatusVal)

          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                        LusTempReg,
                        PWM_TAUDB_MASK_TE,
                        PWM_SELECT_CHANNEL_CLK_SID)

           /* QAC Warning: START Msg(2:3892)-1 */
           /* check if timer started */
           if (PWM_TAUDB_CH_STOPPED ==
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                                               LusTAUStatusVal))
           /* END Msg(2:3892)-1 */
           {
             /* Report to DEM */
             Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
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

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

      #endif
      }
      #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
              (PWM_TAUB_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if (PWM_TAUJ_UNIT_USED == STD_ON)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif


        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        LpTAUJProperties =
            (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

        /* Save the existing CMOR register value */
        LusCMORVal = ((Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR) &
                                                                 PWM_CMOR_MASK);

        LusClockSource = (uint16)LddClockSource;
        /* QAC Warning: START Msg(2:3892)-1 */
        LusClockSource = (LusClockSource << PWM_CKS_BITS_POSITION);
        /* END Msg(2:3892)-1 */

        /* Modify only 14 and 15 bit of variable */
        LusCMORVal = LusCMORVal | LusClockSource;

        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        /* MISRA Violation: START Msg(4:4491)-4 */
        /* QAC Warning: START Msg(2:2814)-2 */
        /* store TAUJ status */
        LusTAUStatusVal =
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                              LpTAUJProperties->ucChannelMask);
        /* END Msg(2:2814)-2 */
        /* END Msg(4:4491)-4 */

        /* QAC Warning: START Msg(2:3892)-1 */
        /* Check TAUJ channel is in stopped state */
        if (LusTAUStatusVal  != PWM_TAUJ_CH_STOPPED)
        /* END Msg(2:3892)-1 */
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          /* MISRA Violation: START Msg(4:4491)-4 */
          #if (PWM_TAUJ_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
          /* calculate new value for TE register */
          LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                             (~LpTAUJProperties->ucChannelMask);
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          #endif
          /* END Msg(4:4397)-8 */
          /* END Msg(4:4491)-4 */

          /* Stop the count operation */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                        LpTAUJProperties->ucChannelMask)

          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                    (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                        PWM_SELECT_CHANNEL_CLK_SID)
          /* END Msg(2:3892)-1 */

          /* MISRA Violation: START Msg(4:3344)-20 */
          /* check if timer started */
          if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                LpTAUJProperties->ucChannelMask)
          {
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
          else
          {
            /* No action required */
          }
          /* END Msg(4:3344)-20 */
        }
        else
        {
          /* No action required */
        }
        /* Implements: PWM_ESDD_UD_028                                        */
        /* Update the CMORm register of Master with new clock source */
        PWM_TAUJ_WRITE_REG_AND_MIRROR(
                      &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                       LusCMORVal,
                      &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                     (&Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                       LusCMORVal,
                       PWM_TAUJ_MASK_CMOR,
                       PWM_SELECT_CHANNEL_CLK_SID)

        /* Get the number of slave channels configured for master channel */
        LucNumSlaveChnls = LpChannelConfig->ucNumSlaveChannnel;

        /* MISRA Violation: START Msg(4:0489)-1 */
        /* Increment the pointer to the slave channel */
        LpChannelConfig++;
        /* END Msg(4:0489)-1 */

        /* QAC Warning: START Msg(2:3892)-1 */
        for (LucCount = PWM_ZERO; LucCount < LucNumSlaveChnls; LucCount++)
        /* END Msg(2:3892)-1 */
        {
          LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
          LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
          /* MISRA Violation: START Msg(4:0311)-2 */
          /* MISRA Violation: START Msg(4:0316)-7 */
          /* MISRA Violation: START Msg(4:4491)-4 */
          /* MISRA Violation: START Msg(4:2983)-10 */
          LpTAUJProperties =
            (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
          /* END Msg(4:0316)-7 */
          /* END Msg(4:0311)-2 */
          /* END Msg(4:4491)-4 */
          /* END Msg(4:2983)-10 */

          /* Save the existing CMOR register value */
          LusCMORVal = ((Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR) &
                                                                 PWM_CMOR_MASK);

          LusClockSource = (uint16)LddClockSource;
          /* QAC Warning: START Msg(2:3892)-1 */
          LusClockSource = (LusClockSource << PWM_CKS_BITS_POSITION);
          /* END Msg(2:3892)-1 */

          /* Modify only 14 and 15 bit of variable */
          LusCMORVal = LusCMORVal | LusClockSource;

          /* Update the CMORm register of Slave with new clock source */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LusCMORVal,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                       (&Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LusCMORVal,
                         PWM_TAUJ_MASK_CMOR,
                         PWM_SELECT_CHANNEL_CLK_SID)
          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to the next channel */
          LpChannelConfig++;
          /* END Msg(4:0489)-1 */
        }
        /* End of TAUJ Slave Channels */

        /* QAC Warning: START Msg(2:3892)-1 */
        /* Restart TAUJ channel */
        if (LusTAUStatusVal != PWM_TAUJ_CH_STOPPED)
        /* END Msg(2:3892)-1 */
        {
          #if (PWM_TAUJ_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
          /* calculate new value for TE register */
          LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                                                LusTAUStatusVal;
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          #endif
          /* Start the count operation */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                        (unsigned char)LusTAUStatusVal)

          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                   (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                        PWM_SELECT_CHANNEL_CLK_SID)

          /* check if timer started */
          if (PWM_TAUJ_CH_STOPPED ==
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                                               LusTAUStatusVal))
          /* END Msg(2:3892)-1 */
          {
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
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

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #endif
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
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:2985)-15 */
    /* END Msg(4:0488)-3 */

    /* MISRA Violation: START Msg(4:2985)-15 */
    /* Get the current Duty Cycle in to the local variable */
    LusDutyCycle = Pwm_GaaChannelCurrDutyCycle[LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID];
    /* END Msg(4:2985)-15 */

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* Read and Store previous clock source settings */
    /* QAC Warning: START Msg(2:4342)-11 */
    /* MISRA Violation: START Msg(4:4394)-22 */
    LddPrevClockSource = (Pwm_ClockSourceType)
                  (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL
                                                               &(PWM_CKS_MASK));
    /* END Msg(4:4394)-22 */
    /* END Msg(2:4342)-11 */
    if (LddPrevClockSource != LddClockSource)
    {
      /* Implements:  EAAR_PN0066_FR_0057, EAAR_PN0066_FR_0066                */
      if ((PWM_TRUE == LpDiagChannelConfig->blOffsetDelayAdjust) &&
         ((MIN_DUTY_CYCLE != LusDutyCycle) && (MAX_DUTY_CYCLE != LusDutyCycle)))
      {
        /* Implements:  EAAR_PN0066_FR_0015                                   */
        LusPrevPrescalerVal = Pwm_HW_GetPrescalerValue(LddPrevClockSource);
        LusCurrPrescalerVal = Pwm_HW_GetPrescalerValue(LddClockSource);

        /* Recalculate Set Trigger Point CSDR Value */
        if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
        {
          LusPrevCSDRVal =
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR;
        }
        else
        {
          LusPrevCSDRVal =
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR;
        }

        /* MISRA Violation: START Msg(4:4491)-4 */
        /* Store result in temporary variable */
        LulTempVal = (LusPrevPrescalerVal * LusPrevCSDRVal);
        /* END Msg(4:4491)-4 */

        /* If the denominator is 0, then calculation is skipped */
        /* QAC Warning: START Msg(2:3892)-1 */
        if (LusCurrPrescalerVal > PWM_ZERO)
        {

          /* QAC Warning: START Msg(2:3892)-1 */
          /* Push the CSDR and CRDR values from data registers to buffer
             registers */
          if (PWM_DIAG_SIMUL_REWRITE_COMPLETED ==
               (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
               (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
          /* END Msg(2:3892)-1 */
          {

            LulTempVal = (LulTempVal / LusCurrPrescalerVal);

            /* QAC Warning: START Msg(2:3892)-1 */
            /* If the newly calculated value exceeds maximum value then
               the value is readjusted */
            if (LulTempVal > PWM_DIAG_MAX_COUNT)
            /* END Msg(2:3892)-1 */
            {
              /* QAC Warning: START Msg(2:3892)-1 */
              LusCurrCSDRVal = (uint16)(LulTempVal % PWM_DIAG_MAX_COUNT);
              /* END Msg(2:3892)-1 */
            }
            else
            {
              LusCurrCSDRVal = (uint16)LulTempVal;
            }
            #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
            LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
            LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
            #else
            LusDiagPeriod = PWM_DIAG_MAX_COUNT;
            #endif
            /* Recalculate Reset Trigger Point CRDR Value */
            LusCRDRVal = Pwm_HW_CalDiagResetTriggerPoint(LusDutyCycle,
                                               LusCurrCSDRVal, LusDiagPeriod);
            /* Implements:  PWM_ESDD_UD_162 */
            if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
            {
              /* Load the Set condition value to the CSDR Register */
              PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                        LusCurrCSDRVal,
                       &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
              PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                        LusCurrCSDRVal,
                        PWM_PWGA_MASK_CSDR,
                        PWM_SELECT_CHANNEL_CLK_SID)
  
              /* Load the Reset condition value to the CRDR Register */
              PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                        LusCRDRVal,
                       &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
              PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                        LusCRDRVal,
                        PWM_PWGA_MASK_CRDR,
                        PWM_SELECT_CHANNEL_CLK_SID)
            }
            else
            {
              /* Load the Set condition value to the CRDR Register */
              PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                        LusCurrCSDRVal,
                       &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
              PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                        LusCurrCSDRVal,
                        PWM_PWGA_MASK_CRDR,
                        PWM_SELECT_CHANNEL_CLK_SID)
  
              /* Load the Reset condition value to the CSDR Register */
              PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                        LusCRDRVal,
                       &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
              PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                        LusCRDRVal,
                        PWM_PWGA_MASK_CSDR,
                        PWM_SELECT_CHANNEL_CLK_SID)
            }

            PWM_WRITE_REG_ONLY(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                      PWM_PWGA_SIMUL_REWRITE_TRIGGER)
          }
          else
          {
             /* Report DEM if previous simultaneous rewrite is *
              * ongoing or failed                              */
             Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                      DEM_EVENT_STATUS_FAILED);
          }
        }
        else
        {
          /* No action required */
        }

        /* Recalculate Trigger delay Value */
        LusPrevCTDRVal = Pwm_GaaPWGAReg_BaseAddress
                                            [LucDiagGeneratortCntlRegs]->usCTDR;

        /* MISRA Violation: START Msg(4:4491)-4 */
        /* Store result in temporary variable */
        LulTempVal = (LusPrevPrescalerVal * LusPrevCTDRVal);
        /* END Msg(4:4491)-4 */

        /* QAC Warning: START Msg(2:3892)-1 */
        /* If the denominator is 0, then calculation is skipped */
        if (LusCurrPrescalerVal > PWM_ZERO)
        /* END Msg(2:3892)-1 */
        {
          LulTempVal = (LulTempVal / LusCurrPrescalerVal);

          /* QAC Warning: START Msg(2:3892)-1 */
          /* If the newly calculated value exceeds maximum value then
           the value is readjusted */
          if (LulTempVal > PWM_DIAG_MAX_COUNT)
          {
            LusCurrCTDRVal = (uint16)(LulTempVal % PWM_DIAG_MAX_COUNT);
          }
          /* END Msg(2:3892)-1 */
          else
          {
            LusCurrCTDRVal = (uint16)LulTempVal;
          }

          /* Get the PWGA channel configured in to the local variable */
          LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

          /* Load the A/D Trigger delay value to the CTDR global buffer */
          Pwm_GaaChannelCTDRVal[LucDiagChannel] = LusCurrCTDRVal;
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

      /* Get the PWGA channel configured in to the local variable */
      LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

      /* Get the PWGA channel status */
      LucDiagChannelStatus = Pwm_HW_GetDiagChannelStatus(LddChannelId);
      /* Check whether channel is stated */
      if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
      {
        /* Stop PWGA channel */
        Pwm_HW_StopDiagChannel(LucDiagChannel, PWM_SELECT_CHANNEL_CLK_SID);
      }
      else
      {
        /* No action required */
      }
      /* QAC Warning: START Msg(4:4397)-8 */
      LucCurrCTLVal = 
              ((Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL)
                                 & (~ PWM_CKS_MASK)) | (uint8)LddClockSource;
      /* END Msg(4:4397)-8 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Load the passed clock source to select count clock from PWBA */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
               &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
              (uint8)LucCurrCTLVal,
               &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucCTL)
      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
              (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
               (uint8)LucCurrCTLVal,
                PWM_PWGA_MASK_CTL,
                PWM_SELECT_CHANNEL_CLK_SID)
      /* END Msg(2:3892)-1 */

      /* Check whether channel is started */
      if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
      {
        /* Start PWGA channel */
        Pwm_HW_StartDiagChannel(LucDiagChannel, PWM_SELECT_CHANNEL_CLK_SID);
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

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    #endif
  }
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
** Function Name        : Pwm_HW_SetTriggerDelay
**
** Service ID           : NA
**
** Description          : This function updates A/D conversion trigger
**                        counter value in global buffer.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId
                          LusTriggerDelay
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Pre-conditions       : NA
**
** Global Variable used : Pwm_GpDiagChannelConfig, Pwm_GaaChannelCTDRVal
**
** Functions invoked    : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**
** Registers Used       : PWGAnCTDR
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_154, PWM_ESDD_UD_149, EAAR_PN0066_FR_0081         */
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetTriggerDelay
                          (Pwm_ChannelType LddChannelId, uint16 LusTriggerDelay)
/* END Msg(2:3227)-3 */
{
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;

  uint8 LucDiagGeneratortCntlRegs;
  uint16 LusPrevTriggerDelay;

  uint8 LucDiagChannel;
  #endif /* (PWM_DIAG_UNIT_USED == STD_ON) */

  /* Implements:  EAAR_PN0066_FR_0043                                         */
  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* MISRA Violation: START Msg(4:0488)-3 */
  /* MISRA Violation: START Msg(4:2985)-15 */
  /* QAC Warning: START Msg(2:2824)-4 */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
  /* END Msg(2:2824)-4 */
  /* END Msg(4:2985)-15 */
  /* END Msg(4:0488)-3 */

  /* QAC Warning: START Msg(2:2814)-2 */
  LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
  /* END Msg(2:2814)-2 */

  /* Read and Store previous clock source settings */
  LusPrevTriggerDelay =
                Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCTDR;

  if (LusPrevTriggerDelay != LusTriggerDelay)
  {
    /* Get the PWGA channel configured in to the local variable */
    LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

    /* Load the A/D Trigger delay value to the CTDR global buffer */
    Pwm_GaaChannelCTDRVal[LucDiagChannel] = LusTriggerDelay;
  }
  else
  {
    /* No action required */
  }
  #endif /* (PWM_DIAG_UNIT_USED == STD_ON) */

  /* Implements:  EAAR_PN0066_FR_0043                                         */
  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif
}
#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif /* End of (PWM_SET_TRIGGER_DELAY_API == STD_ON) */

/*******************************************************************************
** Function Name         : Pwm_HW_StartDiagChannel
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function starts a PWM PWGA channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LucDiagChannel, LucSid
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpDiagUnitConfig
**
** Functions invoked     : Dem_ReportErrorStatus
**
** Registers Used        : SLPWGA0, SLPWGA1, SLPWGA2
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_179                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3206)-6 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_StartDiagChannel (uint8 LucDiagChannel,
                                                     Dem_EventStatusType LucSid)
/* END Msg(2:3206)-6 */
{
  /* Implements: PWM094, SWS_Pwm_00094                                        */
  /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStartCntlRegs;

  uint32 LulTempReg;

  /* QAC Warning: START Msg(2:2814)-2 */
  /* Point to base address of SLPWGAm register */
  LpDiagSyncStartCntlRegs =
            (volatile SLPWGAReg *) Pwm_GpDiagUnitConfig->pDiagSyncStartCntlRegs;
  /* END Msg(2:2814)-2 */

  /* Set 1 to start a PMW PWGA channel */
  /* Check if PWGA channel belongs to 1st group */
  if (PWM_DIAG_MAX_GROUP1_ID >= LucDiagChannel)
  {
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* QAC Warning: START Msg(2:2814)-2 */
    /* calculate value for SLPWGA0 */
    LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA0) |
                                               (PWM_DIAG_ONE << LucDiagChannel);
    /* END Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Set corresponding bit in register SLPWGA0 to start PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                        LulTempReg,
                       &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA0)
    /* END Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                        LulTempReg,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer started */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA0 &
      ((LpDiagSyncStartCntlRegs->ulSLPWGA0) | (PWM_DIAG_ONE << LucDiagChannel)))
    {
      /* nothing to do */
    }
    else
    {
      /* Implements: PWM_ESDD_UD_190                                          */
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    /* END Msg(4:3344)-20 */
  }
  else
  {
    /* No action required */
  }

  /* Implements PWM_ESDD_UD_228                                               */
  /* QAC Warning: START Msg(2:3892)-1 */
  #if (PWM_DIAG_GROUP2_ID_SUPPORT == STD_ON)
  /* Check if PWGA channel belongs to 2nd group */
  if ((LucDiagChannel > PWM_DIAG_MAX_GROUP1_ID) &&
                                     (PWM_DIAG_MAX_GROUP2_ID >= LucDiagChannel))
  {
    /* Subtract the value from 32 to get the actual bit to be set */
    LucDiagChannel = LucDiagChannel - (PWM_DIAG_MAX_GROUP1_ID + PWM_ONE);
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* calculate value for SLPWGA1 */
    LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA1) |
                                               (PWM_DIAG_ONE << LucDiagChannel);

    /* Set corresponding bit in register SLPWGA1 to start PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                        LulTempReg,
                       &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA1)

    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                        LulTempReg,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer started */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA1 &
      ((LpDiagSyncStartCntlRegs->ulSLPWGA1) | (PWM_DIAG_ONE << LucDiagChannel)))
    {
      /* nothing to do */
    }
    else
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    /* END Msg(4:3344)-20 */
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END Msg(2:3892)-1 */

  /* QAC Warning: START Msg(2:3892)-1 */
  /* Implements PWM_ESDD_UD_228 */
  #if ((PWM_DIAG_GROUP2_ID_SUPPORT == STD_ON) && \
                                   (PWM_DIAG_GROUP3_ID_SUPPORT == STD_ON))
  /* Check if PWGA channel belongs to 3rd group */
  if ((LucDiagChannel > PWM_DIAG_MAX_GROUP2_ID) &&
                                     (PWM_DIAG_MAX_GROUP3_ID >= LucDiagChannel))
  {
    /* Subtract the value from 64 to get the actual bit to be set */
    LucDiagChannel = LucDiagChannel - (PWM_DIAG_MAX_GROUP2_ID + PWM_ONE);
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* calculate value for SLPWGA2 */
    LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA2) |
                                               (PWM_DIAG_ONE << LucDiagChannel);

    /* Set corresponding bit in register SLPWGA2 to start PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                        LulTempReg,
                       &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA2)

    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                        LulTempReg,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* MISRA Violation: START Msg(4:3344)-20 */
    /* check if timer started */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA2 &
      ((LpDiagSyncStartCntlRegs->ulSLPWGA2) | (PWM_DIAG_ONE << LucDiagChannel)))
    {
      /* nothing to do */
    }
    else
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    /* END Msg(4:3344)-20 */
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END Msg(2:3892)-1 */
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
** Function Name         : Pwm_HW_StopDiagChannel
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function stops a PWM PWGA channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LucDiagChannel, LucSid
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpDiagUnitConfig
**
** Functions invoked     : Dem_ReportErrorStatus
**
** Registers Used        : SLPWGA0, SLPWGA1, SLPWGA2.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_180                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3206)-6 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_StopDiagChannel (uint8 LucDiagChannel,
                                                     Dem_EventStatusType LucSid)
/* END Msg(2:3206)-6 */
{
  /* Implements: PWM094, SWS_Pwm_00094                                        */
  /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStartCntlRegs;

  uint32 LulDiagMaskValue;

  /* QAC Warning: START Msg(2:2814)-2 */
  /* Point to base address of SLPWGAm register */
  LpDiagSyncStartCntlRegs =
            (volatile SLPWGAReg *) Pwm_GpDiagUnitConfig->pDiagSyncStartCntlRegs;
  /* END Msg(2:2814)-2 */

  /* Set 0 to stop a PWM PWGA channel */
  /* Check if PWGA channel belongs to 1st group */
  if (PWM_DIAG_MAX_GROUP1_ID >= LucDiagChannel)
  {
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* QAC Warning: START Msg(2:2814)-2 */
    LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA0;
    /* END Msg(2:2814)-2 */
    LulDiagMaskValue =
                       LulDiagMaskValue & (~(PWM_DIAG_ONE << LucDiagChannel));
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Clear corresponding bit in register SLPWGA0 to stop PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                        LulDiagMaskValue,
                       &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA0)
    /* END Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                        LulDiagMaskValue,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* check if timer stopped */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA0 == LulDiagMaskValue)
    {
      /* nothing to do */
    }
    else
    {
      /* Implements: PWM_ESDD_UD_190                                          */
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    /* No action required */
  }

  /* Implements: PWM_ESDD_UD_228                                              */
  /* QAC Warning: START Msg(2:3892)-1 */
  #if (PWM_DIAG_GROUP2_ID_SUPPORT == STD_ON)
  /* Check if PWGA channel belongs to 2nd group */
  if ((LucDiagChannel > PWM_DIAG_MAX_GROUP1_ID) &&
                                     (PWM_DIAG_MAX_GROUP2_ID >= LucDiagChannel))
  {
    /* Subtract the value from 32 to get the actual bit to be set */
    LucDiagChannel = LucDiagChannel - (PWM_DIAG_MAX_GROUP1_ID + PWM_ONE);

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA1;
    LulDiagMaskValue = LulDiagMaskValue & (~(PWM_DIAG_ONE << LucDiagChannel));

    /* Clear corresponding bit in register SLPWGA1 to stop PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                        &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                        LulDiagMaskValue,
                        &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA1)

    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                        LulDiagMaskValue,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* check if timer stopped */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA1 == LulDiagMaskValue)
    {
      /* nothing to do */
    }
    else
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    /* No action required */
  }
  /* END Msg(2:3892)-1 */
  #endif

  /* Implements: PWM_ESDD_UD_228                                              */
  /* QAC Warning: START Msg(2:3892)-1 */
  #if ((PWM_DIAG_GROUP2_ID_SUPPORT == STD_ON) && \
                                   (PWM_DIAG_GROUP3_ID_SUPPORT == STD_ON))
  /* Check id PWGA channel belongs to 3rd group */
  if ((LucDiagChannel > PWM_DIAG_MAX_GROUP2_ID) &&
                             (PWM_DIAG_MAX_GROUP3_ID >= LucDiagChannel))
  {
    /* Subtract the value from 64 to get the actual bit to be set */
    LucDiagChannel = LucDiagChannel - (PWM_DIAG_MAX_GROUP2_ID + PWM_ONE);

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    LulDiagMaskValue = LpDiagSyncStartCntlRegs->ulSLPWGA2;
    LulDiagMaskValue =
                       LulDiagMaskValue & (~(PWM_DIAG_ONE << LucDiagChannel));

    /* Clear corresponding bit in register SLPWGA2 to stop PWGA channel */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                        LulDiagMaskValue,
                       &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA2)

    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                       &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                        LulDiagMaskValue,
                        PWM_PWGA_MASK_SLPWGA,
                        LucSid)
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif
    /* check if timer stopped */
    if (LpDiagSyncStartCntlRegs->ulSLPWGA2 == LulDiagMaskValue)
    {
      /* nothing to do */
    }
    else
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END Msg(2:3892)-1 */
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
** Function Name         : Pwm_HW_SetChannelOutput
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function sets the output of a channel to
**                         constant signal for current period.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**                         LddStateType
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpChannelConfig, Pwm_GaaChannelConstantStatus,
**                         Pwm_GpDiagChannelConfig, Pwm_GaaChannelConstantState,
**                         Pwm_GaaChannelCRDRRestoreVal,
**                         Pwm_GaaChannelCSDRRestoreVal
**
** Functions invoked     : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**
** Registers Used        : TAUDnTOE, TAUBnTOE, TAUDnTO, TAUBnTO, ICTAUDm,
**                         ICTAUBm, ICTAUJm, ICPWGAm, TAUJnTOE, TAUJnTO,
**                         PWGAnCSDR, PWGAnCRDR, PWGAnRSF, PWGAnRDT,
**                         PWGAINTMSK00, PWGAINTMSK01, PWGAINTMSK02.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_161, PWM_ESDD_UD_158                              */
/* Implements:  PWM_ESDD_UD_156                                               */
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetChannelOutput
(Pwm_ChannelType LddChannelId, Pwm_OutputStateType LddState)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
   /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;
  uint8 LucDiagGeneratortCntlRegs;
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  uint32 LulPwgaIntMskValue;
  #endif

  #if (PWM_CLEAR_PENDING_INTERRUPT == STD_ON)
  #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
  volatile uint32 LulPwgaIntFValue;
  #endif
  #endif

  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  uint8 LucVar;
  uint8 LucUserCntlRegsIndx;
  uint16 LusTempReg;
  #endif

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  /* Check if channel belongs to PWGA or TAU unit */
  if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID)
  #endif
  {
    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the channel configuration */
    LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0488)-3 */
    #endif

    #if (PWM_TAU_UNIT_USED == STD_ON)
    /* Implements:  EAAR_PN0066_FR_0016                                       */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check whether the channel is in Slave Mode */
    if (PWM_SLAVE_CHANNEL == (uint8)LpChannelConfig->uiTimerMode)
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    {
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
          && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Check whether the channel belongs to TAUD/TAUB */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:3892)-1 */
      #endif
      {
        #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Get the offset of the Master from the slave channel */
        LucVar = LpChannelConfig->ucMasterOffset;

        /* Set the Constant state status of this channel as PWM_TRUE */
        Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_TRUE;

        /* Set the Constant state status of master channel as PWM_TRUE */
        Pwm_GaaChannelConstantStatus[LddChannelId - LucVar] = PWM_TRUE;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to TAUD/TAUB channel properties */
        LpTAUDBProperties =
        (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                               (LpChannelConfig->pChannelProp);
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* Fetch the pointer to the current TAUD/TAUB Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        /* QAC Warning: START Msg(2:2814)-2 */
        /* calculate TOE value */
        LusTempReg =
                 (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
        /* END Msg(2:2814)-2 */
        /* Set the corresponding channel bit to disable TOE operation */
        PWM_TAUDB_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                      &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
        PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                  (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                       LusTempReg,
                       PWM_TAUDB_MASK_TOE,
                       PWM_SET_CHANNEL_OUTPUT_SID)

        if (PWM_LOW == LddState)
        {
          /* calculate TO value */
          LusTempReg =
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                                 ((uint16)~(LpTAUDBProperties->usChannelMask)));
          /* Reset the corresponding bit if Constant state is LOW */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_CHANNEL_OUTPUT_SID)
        }
        else
        {
          /* calculate TO value */
          LusTempReg =
                  (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO |
                                              LpTAUDBProperties->usChannelMask);
          /* Reset the corresponding bit if Constant state is HIGH */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg)
          PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                        LusTempReg,
                        PWM_TAUDB_MASK_TO,
                        PWM_SET_CHANNEL_OUTPUT_SID)
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Enable TAUDB master channel interrupt only if interrupt disabled */
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        if (PWM_FALSE == Pwm_GaaNotifStatus[LddChannelId - LucVar])
        #endif
        {
          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Get the pointer to the master channel configuration */
          LpChannelConfig = Pwm_GpChannelConfig + (LddChannelId - LucVar);
          /* END Msg(4:0488)-3 */

          /* Implements:  PWM_ESDD_UD_067, EAAR_PN0066_FR_0024                */
          #if (PWM_CLEAR_PENDING_INTERRUPT == STD_ON)
          /* Check if the Interrupt register is present for particular
             channel */
          if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
          {
            /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
            /* MISRA Violation: START Msg(4:0489)-1 */
            /* MISRA Violation: START Msg(4:0310)-6 */
            RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                 (PWM_CLEAR_PENDING_INTR_MASK));
            /* END Msg(4:0310)-6 */
            /* END Msg(4:0489)-1 */
          }
          else
          {
            /* No action required */
          }
          #endif

          if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
          {
            /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
            /* Enable the Interrupt processing of the current channel */
            RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                        PWM_INTERRUPT_MASK_EN);
          }
          else
          {
            /* No action required */
          }
        }
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        else
        {
          /* No action required */
        }
        #endif

        #endif
      }
      #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
          && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if (PWM_TAUJ_UNIT_USED == STD_ON)

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        /* Get the offset of the Master from the slave channel */
        LucVar = LpChannelConfig->ucMasterOffset;

        /* Set the Constant state status of this channel as PWM_TRUE */
        Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_TRUE;

        /* Set the Constant state status of master channel as PWM_TRUE */
        Pwm_GaaChannelConstantStatus[LddChannelId - LucVar] = PWM_TRUE;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                (LpChannelConfig->pChannelProp);
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;

        /* MISRA Violation: START Msg(4:4491)-4 */
        /* QAC Warning: START Msg(2:2814)-2 */
        /* calculate TOE value */
        LusTempReg =
                  (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                   ((uint8)~(LpTAUJProperties->ucChannelMask)));
        /* END Msg(2:2814)-2 */
        /* QAC Warning: START Msg(2:3892)-1 */
        LusTempReg &= PWM_MASK_LOW_NIBBLE;
        /* END Msg(2:3892)-1 */
        /* END Msg(4:4491)-4 */

        /* Set the corresponding channel bit to disable TOm operation */
        PWM_TAUJ_WRITE_REG_AND_MIRROR(
                    &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                    (uint8)LusTempReg,
                    &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                  (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                  (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                  PWM_SET_CHANNEL_OUTPUT_SID)
        /* END Msg(2:3892)-1 */

        if (PWM_LOW == LddState)
        {

          /* MISRA Violation: START Msg(4:4491)-4 */
          /* calculate TO value */
          LusTempReg =
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                                   ((uint8)~(LpTAUJProperties->ucChannelMask)));
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          /* END Msg(4:4491)-4 */

          /* Reset the corresponding bit if Constant state is LOW */
          PWM_WRITE_REG_ONLY(
                     &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                     (uint8)LusTempReg)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                    (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                        PWM_SET_CHANNEL_OUTPUT_SID)
          /* END Msg(2:3892)-1 */
        }
        else
        {
          /* MISRA Violation: START Msg(4:4491)-4 */
          /* calculate TO value */
          LusTempReg =
                    (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO |
                                               LpTAUJProperties->ucChannelMask);
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          /* END Msg(4:4491)-4 */

          /* Reset the corresponding bit if Constant state is HIGH */
          PWM_WRITE_REG_ONLY(
                     &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                 (uint8)LusTempReg)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                    (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                        (uint8)LusTempReg,
                        PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                        PWM_SET_CHANNEL_OUTPUT_SID)
          /* END Msg(2:3892)-1 */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* Enable TAUJ master channel interrupt only if notification disabled */
        if (PWM_FALSE == Pwm_GaaNotifStatus[LddChannelId - LucVar])
        #endif
        {
          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Get the pointer to the master channel configuration */
          LpChannelConfig = Pwm_GpChannelConfig + (LddChannelId - LucVar);
          /* END Msg(4:0488)-3 */

          /* Implements:  PWM_ESDD_UD_067, EAAR_PN0066_FR_0024                */
          #if (PWM_CLEAR_PENDING_INTERRUPT == STD_ON)
          /* Check if the Interrupt register is present for particular
             channel */
          if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
          {
            /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
            /* MISRA Violation: START Msg(4:0489)-1 */
            /* MISRA Violation: START Msg(4:0310)-6 */
            RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                 (PWM_CLEAR_PENDING_INTR_MASK));
            /* END Msg(4:0310)-6 */
            /* END Msg(4:0489)-1 */
          }
          else
          {
            /* No action required */
          }
          #endif

          if (NULL_PTR != LpChannelConfig->pIntrCntlAddress)
          {
            /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
            /* Enable the Interrupt processing of the current channel */
            RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAddress),
                                                      PWM_INTERRUPT_MASK_EN);
          }
          else
          {
            /* No action required */
          }
        }
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        else
        {
          /* No action required */
        }
        #endif

        #endif
      }
    } /* End of if (LpChannelConfig->uiTimerMode == PWM_SLAVE_CHANNEL) */
    /* Channel in Master Mode*/
    else
    {
      /* No action required */
    }
    #endif
  }/* if (LddChannelId < PWM_MIN_DIAG_CHANNELS_CONFIG_ID) */
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && (PWM_TAU_UNIT_USED  == STD_ON))
  else
  #endif
  {
    #if (PWM_DIAG_UNIT_USED == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* QAC Warning: START Msg(2:2824)-4 */
    LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
    /* END Msg(2:2824)-4 */
    /* END Msg(4:2985)-15 */
    /* END Msg(4:0488)-3 */

    /* QAC Warning: START Msg(2:2814)-2 */
    LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* Set the constant signal status of this channel as PWM_TRUE */
    Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_TRUE;

    /* MISRA Violation: START Msg(4:2985)-15 */
    /* Store the current Constant signal state */
    Pwm_GaaChannelConstantState[LddChannelId -
                                    PWM_MIN_DIAG_CHANNELS_CONFIG_ID] = LddState;
    /* END Msg(4:2985)-15 */

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* QAC Warning: START Msg(2:3892)-1 */
    /* Check if RSF register is zero */
    if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
              (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
    /* END Msg(2:3892)-1 */
    {
      if (PWM_LOW == LddState)
      {
        /* MISRA Violation: START Msg(4:2985)-15 */
        /* Store the Reset Trigger point value */
        Pwm_GaaChannelCSDRRestoreVal
              [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID] =
                  Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR;
        /* END Msg(4:2985)-15 */
  
        /* Load Set Trigger point value to the CRDR Register to achieve
           constant low signal */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR &
                PWM_DIAG_MAX_COUNT),
                &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR &
                PWM_DIAG_MAX_COUNT),
                PWM_PWGA_MASK_CSDR,
                PWM_SET_CHANNEL_OUTPUT_SID)
      }
      else
      {
        /* MISRA Violation: START Msg(4:2985)-15 */
        /* Store the Reset Trigger point value */
        Pwm_GaaChannelCRDRRestoreVal
              [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID] =
                 Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR;
        /* END Msg(4:2985)-15 */
  
        /* Load Reset Trigger point with Max value to achieve constant
           high signal */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
               (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SET_CHANNEL_OUTPUT_SID)
        /* END Msg(2:3892)-1 */
      }

      PWM_WRITE_REG_ONLY(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                    PWM_PWGA_SIMUL_REWRITE_TRIGGER)
    }
    else
    {
      /* Report DEM if previous simultaneous rewrite is ongoing or failed */
      Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                 DEM_EVENT_STATUS_FAILED);
    }

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* Implements:  PWM_ESDD_UD_067, EAAR_PN0066_FR_0024, EAAR_PN0066_FR_0042 */
    /* Enable PWGA interrupt */
    #if (PWM_CLEAR_PENDING_INTERRUPT == STD_ON)
    /* Check if the Interrupt register is present for particular channel */
    if (NULL_PTR != LpDiagChannelConfig->pDiagIntrCntlAddress)
    {
      /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067 */
        #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
        /* Clear channel  interrupt factor for F1KM/F1KH */
        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif
        /* Check whether channel belongs to group0 */
        if ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP1)
        {
            /* Clear channel  interrupt factor in register PWGAINTFC00 */
            /* QAC Warning: START Msg(2:3892)-1 */
            LulPwgaIntFValue =
                   (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTF)
                   & ~((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel));
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTFC,
                    ((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel))
                    )
            PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTF,
                    LulPwgaIntFValue,
                    PWM_PWGA_MASK_PWGAINTMSK,
                    PWM_SET_CHANNEL_OUTPUT_SID)
            /* END Msg(2:3892)-1 */
        }
        /* Check whether channel belongs to group1 */
        else if ((PWM_DIAG_GROUP1 <= (LpDiagChannelConfig->ucDiagChannel)) &&
                      ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP2))
        {
             /* Clear channel  interrupt factor in register PWGAINTFC01 */
             /* QAC Warning: START Msg(2:3892)-1 */
             LulPwgaIntFValue =
                  (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTF)
                  & ~((uint32)PWM_ONE
                  << ((LpDiagChannelConfig->ucDiagChannel) - PWM_DIAG_GROUP1));
             PWM_WRITE_REG_ONLY(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTFC,
                    ((uint32)PWM_ONE
                    << ((LpDiagChannelConfig->ucDiagChannel) - PWM_DIAG_GROUP1))
                    )
             PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTF,
                    LulPwgaIntFValue,
                    PWM_PWGA_MASK_PWGAINTMSK,
                    PWM_SET_CHANNEL_OUTPUT_SID)
        }
            /* END Msg(2:3892)-1 */
        /* Check whether channel belongs to group2 */
        else if ((PWM_DIAG_GROUP2 <= (LpDiagChannelConfig->ucDiagChannel)) &&
               ((LpDiagChannelConfig->ucDiagChannel) < PWM_TOTAL_DIAG_CHANNELS))
        {
            /* Clear channel  interrupt factor in register PWGAINTFC02 */
            /* QAC Warning: START Msg(2:3892)-1 */
            LulPwgaIntFValue =
                  (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTF)
                  & ~((uint32)PWM_ONE
                  << ((LpDiagChannelConfig->ucDiagChannel) - PWM_DIAG_GROUP2));
            PWM_WRITE_REG_ONLY(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTFC,
                    ((uint32)PWM_ONE
                    << ((LpDiagChannelConfig->ucDiagChannel) - PWM_DIAG_GROUP2))
                    )
            PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                    &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTF,
                    LulPwgaIntFValue,
                    PWM_PWGA_MASK_PWGAINTMSK,
                    PWM_SET_CHANNEL_OUTPUT_SID)
            /* END Msg(2:3892)-1 */
        }
        else
        {
           /* No action required */
        }

        #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
        #endif

        #else
        /* Clear channel  interrupt factor for F1K */
        /* MISRA Violation: START Msg(4:0489)-1 */
        /* MISRA Violation: START Msg(4:0310)-6 */
        RH850_SV_MODE_ICR_AND(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                               (PWM_CLEAR_PENDING_INTR_MASK));
        /* END Msg(4:0310)-6 */
        /* END Msg(4:0489)-1 */
        #endif
    }
    else
    {
      /* No action required */
    }
    #endif

    /* Implements:  PWM_ESDD_UD_227                                           */
    #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)

    /* Check whether channel belongs to group0 */
    if ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP1)
    {

     /* QAC Warning: START Msg(2:3892)-1 */
     /* Unmask channel interrupt in register PWGAINTMSK00 */
     LulPwgaIntMskValue =
         (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK)
                & ~((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel));

     PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00
                )

     PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                PWM_PWGA_MASK_PWGAINTMSK,
                PWM_SET_CHANNEL_OUTPUT_SID)
    }
    /* END Msg(2:3892)-1 */
    /* Check whether channel belongs to group1 */
    else if ((PWM_DIAG_GROUP1 <= (LpDiagChannelConfig->ucDiagChannel)) &&
                    ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP2))
    {
     /* QAC Warning: START Msg(2:3892)-1 */
     /* Unmask channel interrupt in register PWGAINTMSK01 */
     LulPwgaIntMskValue =
         (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK)
          &  ~((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                           PWM_DIAG_GROUP1));

     PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01
                )

     PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                PWM_PWGA_MASK_PWGAINTMSK,
                PWM_SET_CHANNEL_OUTPUT_SID)
    }
    /* END Msg(2:3892)-1 */
    /* Implements:  PWM_ESDD_UD_181                                           */
    /* Check whether channel belongs to group2 */
    else if ((PWM_DIAG_GROUP2 <= (LpDiagChannelConfig->ucDiagChannel)) &&
            ((LpDiagChannelConfig->ucDiagChannel) < PWM_TOTAL_DIAG_CHANNELS))
    {
     /* QAC Warning: START Msg(2:3892)-1 */
     /* Unmask channel interrupt in register PWGAINTMSK02 */
     LulPwgaIntMskValue =
     (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK)
     &  ~((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                         PWM_DIAG_GROUP2));

     PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02
                )

     PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                LulPwgaIntMskValue,
                PWM_PWGA_MASK_PWGAINTMSK,
                PWM_SET_CHANNEL_OUTPUT_SID)
    }
    /* END Msg(2:3892)-1 */
    else
    {
       /* No action required */
    }
    #endif

    if (NULL_PTR != LpDiagChannelConfig->pDiagIntrCntlAddress)
    {
      /* Implements: PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                     */
      /* Enable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_AND(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                        PWM_INTERRUPT_MASK_EN);
    }
    else
    {
      /* No action required */
    }
    #endif
  }
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
** Function Name         : Pwm_PWGA_Callback
**
** Service ID            : NA
**
** Description           : This routine is used to invoke the callback
**                         notification of PWGA channels.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpDiagChannelConfig, Pwm_GaaChannelCRDRRestoreVal
**                         Pwm_GaaChannelConstantStatus,
**                         Pwm_GaaChannelCSDRRestoreVal,
**                         Pwm_GaaChannelConstantState,Pwm_GaaNotifStatus
**
** Functions invoked     : PWM_ENTER_CRITICAL_SECTION, PWM_EXIT_CRITICAL_SECTION
**
** Registers Used        : PWGAnCSDR, PWGAnCRDR, PWGAnRSF PWGAnRDT, ICPWGAm,
**                         PWGAINTMSK
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_172                                               */
/* Implements:  PWM025, PWM026, PWM115c, EAAR_PN0034_FR_0060                  */
/* Implements:  SWS_Pwm_00025, SWS_Pwm_00026, SWS_Pwm_30115                   */
/* Implements:  PWM_ESDD_UD_019                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(void, PWM_FAST_CODE) Pwm_PWGA_Callback(Pwm_ChannelType LddChannelId)
/* END Msg(2:3227)-3 */
{
  #if ((PWM_SET_CHANNEL_OUTPUT_API == STD_ON) || \
                                         (PWM_NOTIFICATION_SUPPORTED == STD_ON))
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_FAST_CONST)
                                                            LpDiagChannelConfig;
  #endif

  #if ((PWM_SET_CHANNEL_OUTPUT_API == STD_ON) && \
       (PWM_NOTIFICATION_SUPPORTED == STD_ON)&& \
       (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON))
  uint32 LulPwgaIntMskValue;
  #endif

  #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
  uint8 LucDiagGeneratortCntlRegs;
  #endif

  #if ((PWM_SET_CHANNEL_OUTPUT_API == STD_ON) || \
                                         (PWM_NOTIFICATION_SUPPORTED == STD_ON))
  /* MISRA Violation: START Msg(4:0488)-3 */
  /* MISRA Violation: START Msg(4:2985)-15 */
  /* QAC Warning: START Msg(2:2824)-4 */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                               PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
  /* END Msg(4:2985)-15 */
  /* END Msg(4:0488)-3 */
  /* END Msg(2:2824)-4 */
  #endif

  #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
  /* QAC Warning: START Msg(2:2814)-2 */
  LucDiagGeneratortCntlRegs = LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
  /* END Msg(2:2814)-2 */

  if (PWM_TRUE == Pwm_GaaChannelConstantStatus[LddChannelId])
  {
    /* Implements: PWM_ESDD_UD_044                                            */
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

    /* Implements:  PWM_ESDD_UD_227                                           */
    #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
    /* Check whether channel belongs to group0 */
    if ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP1)
    {

      /* QAC Warning: START Msg(2:3892)-1 */
      /* Mask channel interrupt in register PWGAINTMSK00 */
      LulPwgaIntMskValue =
                 (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK)
                 | ((uint32)PWM_ONE << (LpDiagChannelConfig->ucDiagChannel));

      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00
                 )

      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 PWM_PWGA_MASK_PWGAINTMSK,
                 PWM_PWGA_ISR_SID)

      if (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK ==
                                                         PWM_PWGAINTMSK_RESET)
      /* END Msg(2:3892)-1 */
      {
        /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                  */
        /* Disable the Interrupt processing of the group0 */
        RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
      }
      else
      {
        /* No action required */
      }
    }
    /* Check whether channel belongs to group1 */
    else if ((PWM_DIAG_GROUP1 <= (LpDiagChannelConfig->ucDiagChannel)) &&
                    ((LpDiagChannelConfig->ucDiagChannel) < PWM_DIAG_GROUP2))
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Mask channel interrupt in register PWGAINTMSK01 */
      LulPwgaIntMskValue =
      (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK)
      | ((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                           PWM_DIAG_GROUP1));

      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01
                 )

      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 PWM_PWGA_MASK_PWGAINTMSK,
                 PWM_PWGA_ISR_SID)

      if ( Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK ==
                                                         PWM_PWGAINTMSK_RESET)
      /* END Msg(2:3892)-1 */
      {
        /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                  */
        /* Disable the Interrupt processing of group1 */
        RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                      PWM_INTERRUPT_MASK_DIS);
      }
      else
      {
        /* No action required */
      }
    }
    /* Implements:  PWM_ESDD_UD_181                                           */
    /* Check whether channel belongs to group2 */
    else if ((PWM_DIAG_GROUP2 <= (LpDiagChannelConfig->ucDiagChannel)) &&
            ((LpDiagChannelConfig->ucDiagChannel) < PWM_TOTAL_DIAG_CHANNELS))
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Mask channel interrupt in register PWGAINTMSK02 */
      LulPwgaIntMskValue =
      (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK)
      | ((uint32)PWM_ONE << ((LpDiagChannelConfig->ucDiagChannel) -
                                                           PWM_DIAG_GROUP2));

      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 &Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02
                 )

      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK,
                 LulPwgaIntMskValue,
                 PWM_PWGA_MASK_PWGAINTMSK,
                 PWM_PWGA_ISR_SID)
      if (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK ==
                                                         PWM_PWGAINTMSK_RESET)
      /* END Msg(2:3892)-1 */
      {
         /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                 */
         /* Disable the Interrupt processing of group2 */
         RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                       PWM_INTERRUPT_MASK_DIS);
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
    #else
    if (PWM_FALSE == Pwm_GaaNotifStatus[LddChannelId])
    {
      /* Implements:  PWM_ESDD_UD_187, EAAR_PN0034_FR_0067                    */
      /* Disabling the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpDiagChannelConfig->pDiagIntrCntlAddress),
                                                     PWM_INTERRUPT_MASK_DIS);
    }
    else
    {
     /* No action required */
    }
    #endif
    #endif
    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* QAC Warning: START Msg(2:3892)-1 */
    /* Check if RSF register is zero */
    if (PWM_DIAG_SIMUL_REWRITE_COMPLETED == (PWM_PWGA_SIMUL_REWRITE_TRIGGER &
              (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
    /* END Msg(2:3892)-1 */
    {

      /* QAC Warning: START Msg(4:2985)-1 */
      if (PWM_LOW == Pwm_GaaChannelConstantState[LddChannelId -
                                              PWM_MIN_DIAG_CHANNELS_CONFIG_ID])
      /* END Msg(4:2985)-1 */
      {
        /* MISRA Violation: START Msg(4:2985)-15 */
        /* Load the Set Trigger point value to the CSDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                Pwm_GaaChannelCSDRRestoreVal
                [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                Pwm_GaaChannelCSDRRestoreVal
                [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                PWM_PWGA_MASK_CSDR,
                PWM_PWGA_ISR_SID)
        /* END Msg(4:2985)-15 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:2985)-15 */
        /* Load the Reset Trigger point value to the CRDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                 Pwm_GaaChannelCSDRRestoreVal
                 [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
                (&Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                Pwm_GaaChannelCSDRRestoreVal
                [LddChannelId - PWM_MIN_DIAG_CHANNELS_CONFIG_ID],
                PWM_PWGA_MASK_CRDR,
                PWM_PWGA_ISR_SID)
        /* END Msg(4:2985)-15 */
      }

      PWM_WRITE_REG_ONLY(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                 PWM_PWGA_SIMUL_REWRITE_TRIGGER)
    }
    else
    {
      /* Report DEM if previous simultaneous rewrite is ongoing or failed */
      Dem_ReportErrorStatus(PWM_E_REWRITE_FAILED,
                                                 DEM_EVENT_STATUS_FAILED);
    }

    #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
    #endif

    /* Set the constant signal status of this channel as PWM_FALSE */
    Pwm_GaaChannelConstantStatus[LddChannelId] = PWM_FALSE;
  }
  else
  {
    /* No action required */
  }
  #endif

  /* Implements: PWM_ESDD_UD_044 */
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Check if Notification status is enabled for this channel */
  if (PWM_TRUE == Pwm_GaaNotifStatus[LddChannelId])
  {
    /* Invoke the Notification function */
    LpDiagChannelConfig->pPwmEdgeNotifPtr();
  }
  else
  {
    /* No action required */
  }
  #endif

  #if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
  RH850_DUMMY_READ_SYNCP(8, 
            &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT);
  #endif
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
** Function Name         : Pwm_HW_SynchronousInit
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This function sets the Period, Duty cycle of all
**                         PWM channels configured to support synchronous
**                         start/stop of timers.
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
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpChannelConfig, Pwm_GpDiagChannelConfig,
**                         Pwm_GaaChannelCTDRVal
**
** Functions invoked     : PWM_ENTER_CRITICAL_SECTION,
**                         PWM_EXIT_CRITICAL_SECTION, Dem_ReportErrorStatus
**
** Registers Used        : TAUDnCDRm, TAUBnCDRm, TAUDnTE, TAUBnTE, TAUDnCMORm,
**                         TAUBnCMORm, TAUDnTT, TAUBnTT, TAUJnCDRm, TAUJnTE,
**                         TAUJnCMORm, TAUJnTT, PWGAnCSDR, PWGAnCRDR, PWGAnCTL.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_169, PWM_ESDD_UD_013, PWM_ESDD_UD_165             */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousInit(void)
{
  #if (PWM_TAU_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;

  Pwm_PeriodType LddCalculateDuty;

  #if ((((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) && \
         (PWM_TAUDB_WRITE_VERIFY != PWM_WV_DISABLE)) ||\
         ((PWM_TAUJ_UNIT_USED == STD_ON) &&\
         (PWM_TAUJ_WRITE_VERIFY != PWM_WV_DISABLE)))
  uint16 LusTempReg;
  #endif
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  uint8 LucTAUDBMasterChannelReg;
  /* Pointer to the TAUD/TAUB Channel Properties structure */
  P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUDBProperties;
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;

  uint16 LusDefaultPeriodOrDuty;
  uint16 LusTAUDBDefaultPeriod;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  uint8 LucTAUJMasterChannelReg;
  uint32 LulDefaultPeriodOrDuty;
  uint32 LulTAUJDefaultPeriod;
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJProperties;
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpDiagChannelConfig;

  uint8 LucDiagGeneratortCntlRegs;
  uint16 LusDutyCycle;
  uint16 LusOffset;
  uint8 LucDiagChannel;
  uint16 LusDiagResetTriggerPoint;
  uint16 LusDiagPeriod;
  #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
  uint8 LucPwmShift;
  #endif
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  Pwm_PeriodType LddMasterPeriod;
  Pwm_PeriodType LddSlaveDuty;
  uint8 LucVar;
  uint8 LucCntlRegs;
  uint8 LucUserCntlRegsIndx;
  #endif

  uint8_least LucCount;

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  LpChannelConfig = Pwm_GpChannelConfig;
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Loop to set the attributes of PWGA channels */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG;
                                                                  LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    if ((PWM_TRUE == LpDiagChannelConfig->blSyncStartReq) &&
                        (PWM_FALSE == LpDiagChannelConfig->blComplexDriverInit))
    /* END Msg(2:2814)-2 */
    {
      LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;

      /* Get the Duty Cycle in to the local variable */
      LusDutyCycle = LpDiagChannelConfig->usDutyCycle;

      /* Get the Set condition value in to the local variable */
      LusOffset = LpDiagChannelConfig->usOffset;

      /* Implements:  PWM_ESDD_UD_162                                         */
      /* Check PWM polarity is PWM_HIGH */
      if ((uint8)PWM_HIGH == LpDiagChannelConfig->ucPolarity)
      {
        /* Load the Set condition value to the CSDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_SYNCHRONOUS_INIT_SID)

        Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR =
                                                                   LusOffset;
        #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
        LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
        LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
        #else
        LusDiagPeriod = PWM_DIAG_MAX_COUNT;
        #endif
        /* calculate Diag Reset Trigger Point */
        LusDiagResetTriggerPoint =
                      Pwm_HW_CalDiagResetTriggerPoint (LusDutyCycle, LusOffset,
                      LusDiagPeriod);

        /* Load the Reset condition value to the CRDR Register */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusDiagResetTriggerPoint,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
        PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusDiagResetTriggerPoint,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SYNCHRONOUS_INIT_SID)
      }
      /* PWM polarity is PWM_LOW */
      else
      {
        if (MIN_DUTY_CYCLE == LusDutyCycle)
        {
          /* QAC Warning: START Msg(2:3892)-1 */
          /* Load the Reset condition value with 0x1FFF */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      PWM_DIAG_MAX_RESETTRIGGER_MASK,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(2:3892)-1 */
        }
        else if (MAX_DUTY_CYCLE == LusDutyCycle)
        {
          /* Load the Set condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SYNCHRONOUS_INIT_SID)

          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusOffset,
                      PWM_PWGA_MASK_CSDR,
                      PWM_SYNCHRONOUS_INIT_SID)
        }
        else
        {
          /* Load the Set condition value to the CRDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR,
                      LusOffset,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SYNCHRONOUS_INIT_SID)
          #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
          LucPwmShift = LpDiagChannelConfig->ucDiagChannel;
          LusDiagPeriod = Pwm_HW_GetDiagChannelPeriod(LucPwmShift);
          #else
          LusDiagPeriod = PWM_DIAG_MAX_COUNT;
          #endif
          /* calculate Diag Reset Trigger Point */
          LusDiagResetTriggerPoint =
                      Pwm_HW_CalDiagResetTriggerPoint (LusDutyCycle, LusOffset,
                      LusDiagPeriod);

          /* Load the Reset condition value to the CSDR Register */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusDiagResetTriggerPoint,
                     &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR)
          PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR,
                      LusDiagResetTriggerPoint,
                      PWM_PWGA_MASK_CRDR,
                      PWM_SYNCHRONOUS_INIT_SID)
        }
      }

      /* Get the PWGA channel configured in to the local variable */
      LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

      /* Get the A/D Trigger delay value in to the local variable */
      LusOffset = LpDiagChannelConfig->usTriggerDelay;

      /* Load the A/D Trigger delay value to the CTDR global buffer */
      Pwm_GaaChannelCTDRVal[LucDiagChannel] = LusOffset;

      /* Load the Selected count clock from PWBA0 for the pre-scalar settings */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
                  LpDiagChannelConfig->ucDiagClockCtl,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucCTL)
      PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL,
                  LpDiagChannelConfig->ucDiagClockCtl,
                  PWM_PWGA_MASK_CTL,
                  PWM_SYNCHRONOUS_INIT_SID)
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment to next PWGA channel configuration */
    LpDiagChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #endif /* (PWM_DIAG_UNIT_USED == STD_ON) */

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
       (PWM_TAUJ_UNIT_USED == STD_ON))

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Update the TAUD/TAUB unit config pointer */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ Unit config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif

  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* Loop to set the attributes of TAUD/TAUB/TAUJ channels */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAU_CHANNELS_CONFIG;
                                                                     LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:2814)-2 */
    if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    {
    #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
      /* Set attributes of TAUD/TAUB channels which are to be started
         synchronously. Attributes of channels set as complex driver usage
         remain unchanged.*/
      if ((PWM_TRUE == LpChannelConfig->blSyncStartReq) &&
                            (PWM_FALSE == LpChannelConfig->blComplexDriverInit))
      {
        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        /* Get the pointer to the TAUD/TAUB channel properties */
        LpTAUDBProperties =
            (P2VAR(Pwm_TAUDBProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* MISRA Violation: START Msg(4:0488)-3 */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* QAC Warning: START Msg(2:2824)-4 */
        /* Check TAUD/B channel is in stopped state */
        if (PWM_TAUDB_CH_STOPPED ==
                    (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE
                   & (LpTAUDBUnitConfig + LucUserCntlRegsIndx)->usSyncInitMask))
        /* END Msg(2:2824)-4 */
        /* END Msg(2:3892)-1 */
        {
          /* Update CMORm register based on the configuration  */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                      LpChannelConfig->usCMORegSettingsMask,
                     &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                      LpChannelConfig->usCMORegSettingsMask,
                      PWM_TAUDB_MASK_CMOR,
                      PWM_SYNCHRONOUS_INIT_SID)
        }
        /* END Msg(4:0488)-3 */
        else
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          /* MISRA Violation: START Msg(4:0488)-3 */
          #if (PWM_TAUDB_WRITE_VERIFY != PWM_WV_DISABLE)
          /* calculate new value for TE register */
          LusTempReg =
                   Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                   (~(LpTAUDBUnitConfig + LucUserCntlRegsIndx)->usSyncInitMask);
          #endif
          /* END Msg(4:4397)-8 */
          /* END Msg(4:0488)-3 */

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Stop the count operation */
          PWM_WRITE_REG_ONLY(
                    &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                   ((LpTAUDBUnitConfig + LucUserCntlRegsIndx)->usSyncInitMask))

          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
                   (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                     LusTempReg,
                     PWM_TAUDB_MASK_TE,
                     PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(4:0488)-3 */
          /* MISRA Violation: START Msg(4:0488)-3 */
          /* QAC Warning: START Msg(2:3892)-1 */
          /* Check TAUD/B channel is in stopped state */
          if(PWM_TAUDB_CH_STOPPED ==
                    (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE
                   & (LpTAUDBUnitConfig + LucUserCntlRegsIndx)->usSyncInitMask))
          /* END Msg(2:3892)-1 */
          {
            /* Update CMORm register based on the configuration */
            PWM_TAUDB_WRITE_REG_AND_MIRROR(
                       &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                        LpChannelConfig->usCMORegSettingsMask,
                       &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR)
            PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                       &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR,
                        LpChannelConfig->usCMORegSettingsMask,
                        PWM_TAUDB_MASK_CMOR,
                        PWM_SYNCHRONOUS_INIT_SID)
          }
          /* END Msg(4:0488)-3 */
          else
          {
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
        }

        /* Check for channel in the Master Mode */
        if (PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
        {
          /* QAC Warning: START Msg(2:3892)-1 */
          /* QAC Warning: START Msg(2:2814)-2 */
          LusTAUDBDefaultPeriod =
                            (uint16)(LpTAUDBProperties->ddDefaultPeriodOrDuty);

          /* Check for the period value of the Master is not zero */
          if (PWM_TAUDB_MIN_PERIOD != LusTAUDBDefaultPeriod)
          {
            LusDefaultPeriodOrDuty = (uint16)(LusTAUDBDefaultPeriod - PWM_ONE);
          }
          else
          {
            LusDefaultPeriodOrDuty = LusTAUDBDefaultPeriod;
          }

          /* Update the CDRm register with default period based on the
             configuration */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     LusDefaultPeriodOrDuty,
                     &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
          /* END Msg(2:2814)-2 */
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                     LusDefaultPeriodOrDuty,
                     PWM_TAUDB_MASK_CDR,
                     PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(2:3892)-1 */
        }
        /* Channel in Slave Mode */
        else
        {
          /* Master offset from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Pointer to the Master channel registers */
          LucTAUDBMasterChannelReg = (LpChannelConfig - LucVar)->ucCntlRegsIndx;
          /* END Msg(4:0488)-3 */

          /* Get Master's period */
          LddMasterPeriod =
                 Pwm_GaaTAUDBChReg_BaseAddress[LucTAUDBMasterChannelReg]->usCDR;
          /* Get Slave's Duty */
          LddSlaveDuty = LpTAUDBProperties->ddDefaultPeriodOrDuty;
          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;
          /* QAC Warning: START Msg(2:3892)-1 */
          /* calculate duty cycle */
          LddCalculateDuty =
            (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
          /* END Msg(2:3892)-1 */
          /* Load the Absolute duty value in to the CDR Register */
          PWM_TAUDB_WRITE_REG_AND_MIRROR(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                      (uint16)LddCalculateDuty,
                     &Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                     &Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR,
                      (uint16)LddCalculateDuty,
                      PWM_TAUDB_MASK_CDR,
                      PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(2:3892)-1 */
        }

      }
      else
      {
        /* No action required */
      }
    #endif
    }
    /* QAC Warning: START Msg(2:3892)-1 */
    else if (PWM_HW_TAUJ == (uint8)LpChannelConfig->uiPwmTAUType)
    /* END Msg(2:3892)-1 */
    {
      #if (PWM_TAUJ_UNIT_USED == STD_ON)
      /* Set attributes of TAUJ channels which are to be started
         synchronously. Attributes of channels set as complex driver usage
         remain unchanged. */
      if ((PWM_TRUE == LpChannelConfig->blSyncStartReq) &&
                            (PWM_FALSE == LpChannelConfig->blComplexDriverInit))
      {

        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;

        /* MISRA Violation: START Msg(4:0311)-2 */
        /* MISRA Violation: START Msg(4:0316)-7 */
        LpTAUJProperties =
            (P2VAR(Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                                  LpChannelConfig->pChannelProp;
        /* END Msg(4:0316)-7 */
        /* END Msg(4:0311)-2 */

        /* MISRA Violation: START Msg(4:0488)-3 */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* QAC Warning: START Msg(2:2824)-4 */
        /* Check TAUJ channel is in stopped state */
        if (PWM_TAUJ_CH_STOPPED ==
                     (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE
                    & (LpTAUJUnitConfig + LucUserCntlRegsIndx)->ucSyncInitMask))
        /* END Msg(2:2824)-4 */
        /* END Msg(2:3892)-1 */
        {
          /* Update CMORm register based on the configuration */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LpChannelConfig->usCMORegSettingsMask,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                         LpChannelConfig->usCMORegSettingsMask,
                         PWM_TAUJ_MASK_CMOR,
                         PWM_SYNCHRONOUS_INIT_SID)
        }
        /* END Msg(4:0488)-3 */
        else
        {
          /* MISRA Violation: START Msg(4:4397)-8 */
          /* MISRA Violation: START Msg(4:4491)-4 */
          /* MISRA Violation: START Msg(4:0488)-3 */
          #if (PWM_TAUJ_WRITE_VERIFY != PWM_WV_DISABLE)
          /* calculate new value for TE register */
          LusTempReg =
                    Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                  (~((LpTAUJUnitConfig + LucUserCntlRegsIndx)->ucSyncInitMask));
          /* QAC Warning: START Msg(2:3892)-1 */
          LusTempReg &= PWM_MASK_LOW_NIBBLE;
          /* END Msg(2:3892)-1 */
          #endif
          /* END Msg(4:4397)-8 */
          /* END Msg(4:4491)-4 */
          /* END Msg(4:0488)-3 */
          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Stop the count operation */
          PWM_WRITE_REG_ONLY(
                     &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                    ((LpTAUJUnitConfig + LucUserCntlRegsIndx)->ucSyncInitMask))

          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
                    (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                      (uint8)LusTempReg,
                      PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                      PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(4:0488)-3 */

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Check TAUJ channel is in stopped state */
          if (PWM_TAUJ_CH_STOPPED ==
                   (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                      (LpTAUJUnitConfig + LucUserCntlRegsIndx)->ucSyncInitMask))
          /* END Msg(2:3892)-1 */
          {
            /* Update CMORm register based on the configuration */
            PWM_TAUJ_WRITE_REG_AND_MIRROR(
                          &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                          &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR)
            PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                          &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR,
                           LpChannelConfig->usCMORegSettingsMask,
                           PWM_TAUJ_MASK_CMOR,
                           PWM_SYNCHRONOUS_INIT_SID)
          }
          else
          {
            /* Report to DEM */
            Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
          }
          /* END Msg(4:0488)-3 */
        }
      
        /* Check for channel in the Master Mode*/
        if (PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
        {
          /* QAC Warning: START Msg(2:3892)-1 */
          /* QAC Warning: START Msg(2:2814)-2 */
          LulTAUJDefaultPeriod =
                            (uint32)(LpTAUJProperties->ddDefaultPeriodOrDuty);

          /* Check for the period value of the Master is not zero */
          if (PWM_TAUJ_MIN_PERIOD != LulTAUJDefaultPeriod)
          {
            LulDefaultPeriodOrDuty = (uint32)(LulTAUJDefaultPeriod - PWM_ONE);
          }
          else
          {
            LulDefaultPeriodOrDuty = LulTAUJDefaultPeriod;
          }

          /* Update the CDRm register with default period based on the
             configuration */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LulDefaultPeriodOrDuty,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
          /* END Msg(2:2814)-2 */
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                        LulDefaultPeriodOrDuty,
                        PWM_TAUJ_MASK_CDR,
                        PWM_SYNCHRONOUS_INIT_SID)
          /* END Msg(2:3892)-1 */
        }
        /* Channel in Slave Mode */
        else
        {
          /* Master offset from the slave channel */
          LucVar = LpChannelConfig->ucMasterOffset;

          /* MISRA Violation: START Msg(4:0488)-3 */
          /* Pointer to the Master channel registers */
          LucTAUJMasterChannelReg = (LpChannelConfig - LucVar)->ucCntlRegsIndx;
          /* END Msg(4:0488)-3 */

          /* Get Master's period */
          LddMasterPeriod =
                   Pwm_GaaTAUJChReg_BaseAddress[LucTAUJMasterChannelReg]->ulCDR;

          /* Get Slave's Duty */
          LddSlaveDuty = LpTAUJProperties->ddDefaultPeriodOrDuty;

          /* Get the TAU Type in to the local variable */
          LucVar = LpChannelConfig->uiPwmTAUType;
          /* calculate duty cycle */
          LddCalculateDuty =
                    Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
          /* Load the Absolute duty value in to the CDR Register */
          PWM_TAUJ_WRITE_REG_AND_MIRROR(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                         LddCalculateDuty,
                        &Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR)
          PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(
                        &Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->ulCDR,
                         LddCalculateDuty,
                         PWM_TAUJ_MASK_CDR,
                         PWM_SYNCHRONOUS_INIT_SID)
        }

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

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to the next channel */
    LpChannelConfig++;
    /* END Msg(4:0489)-1 */
  }

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #endif
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
** Function Name         : Pwm_HW_SynchronousStart
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This routine starts all PWM channels configured to
**                         support synchronous start/stop of timers.
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
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDBUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpDiagUnitConfig
**
** Functions invoked     : Dem_ReportErrorStatus
**
** Registers Used        : SLPWGA0, SLPWGA1, SLPWGA2, TAUDnTOE, TAUBnTOE,
**                         TAUDnTE, TAUBnTE, TAUDnTS, TAUBnTS, TAUJnTOE,
**                         TAUJnTE, TAUJnTS.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_170, PWM_ESDD_UD_013, PWM_ESDD_UD_165             */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousStart (void)
{
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;
  /* Pointer to base address of PWGA Unit simultaneous start
     configuration */
  P2CONST(uint32, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStart;
  /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStartCntlRegs;
  uint32 LulTempReg;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  uint8_least LucCount;

  #if (PWM_TAU_UNIT_USED == STD_ON)
  uint16 LusTempReg;
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
                                      || (PWM_TAUJ_UNIT_USED == STD_ON))
  uint8 LucUserCntlRegsIndx;
  #endif

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Update the PWGA config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;
  /* Get the pointer to the configured array of sync start values */
  /* QAC Warning: START Msg(2:2814)-2 */
  LpDiagSyncStart = LpDiagUnitConfig->pDiagSyncStart;
  /* END Msg(2:2814)-2 */
  /* Get the pointer to the sync start control registers address */
  LpDiagSyncStartCntlRegs =
                (volatile SLPWGAReg *) LpDiagUnitConfig->pDiagSyncStartCntlRegs;

  /* QAC Warning: START Msg(2:3892)-1 */
  for (LucCount = PWM_ZERO; LucCount < PWM_THREE;  LucCount++)
  /* END Msg(2:3892)-1 */
  {
    switch (LucCount)
    {
    case 0U:
      /* QAC Warning: START Msg(2:2814)-2 */
      /* calculate ulSLPWGA0 value */
      LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA0) | (*LpDiagSyncStart);
      /* END Msg(2:2814)-2 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Set the Simultaneous start feature of the configured channels */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                         &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                          LulTempReg,
                         &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA0)
      /* END Msg(2:3892)-1 */
      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                         &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                          LulTempReg,
                          PWM_PWGA_MASK_SLPWGA,
                          PWM_SYNCHRONOUS_START_SID)

      if (LpDiagSyncStartCntlRegs->ulSLPWGA0 !=
                    ((LpDiagSyncStartCntlRegs->ulSLPWGA0) | (*LpDiagSyncStart)))
      {
        /* Implements: PWM_ESDD_UD_190                                        */
        /* Report to DEM */
        Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* No action required */
      }
      break;
    case 1U:
      /* calculate ulSLPWGA0 value */
      LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA1) | (*LpDiagSyncStart);
      /* Set the Simultaneous start feature of the configured channels */
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                         &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                          LulTempReg,
                         &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA1)
      /* END Msg(2:3892)-1 */
      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                         &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                          LulTempReg,
                          PWM_PWGA_MASK_SLPWGA,
                          PWM_SYNCHRONOUS_START_SID)

      if (LpDiagSyncStartCntlRegs->ulSLPWGA1 !=
              ((LpDiagSyncStartCntlRegs->ulSLPWGA1) | (*LpDiagSyncStart)))
      {
        /* Report to DEM */
        Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* No action required */
      }
      break;
    default:
      /* calculate ulSLPWGA0 value */
      LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA2) | (*LpDiagSyncStart);
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Set the Simultaneous start feature of the configured channels */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                        &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                         LulTempReg,
                        &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA2)
      /* END Msg(2:3892)-1 */
      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                        &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                         LulTempReg,
                         PWM_PWGA_MASK_SLPWGA,
                         PWM_SYNCHRONOUS_START_SID)

      if (LpDiagSyncStartCntlRegs->ulSLPWGA2 !=
                    ((LpDiagSyncStartCntlRegs->ulSLPWGA2) | (*LpDiagSyncStart)))
      {
        /* Report to DEM */
        Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* No action required */
      }
      break;
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to get next configured sync start channels */
    LpDiagSyncStart++;
    /* END Msg(4:0489)-1 */
  }
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Update the TAUD/TAUB unit config pointer */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Update the pointer for the base address of the TAUDB unit registers */
    LucUserCntlRegsIndx = LpTAUDBUnitConfig->ucUserCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* calculate TOE value */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE |
                                            LpTAUDBUnitConfig->usSyncInitMask;
    /* Set the channel bits that are configured for synchronous stop,
       to disable the count operation */
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                   LusTempReg,
                  &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                   LusTempReg,
                   PWM_TAUDB_MASK_TOE,
                   PWM_SYNCHRONOUS_START_SID)

    /* calculate TE value */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE |
                                              LpTAUDBUnitConfig->usSyncInitMask;
    /* Set the channel bits that are configured for synchronous stop,
       to disable the count operation */
    PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTS,
                    LpTAUDBUnitConfig->usSyncInitMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                    LusTempReg,
                    PWM_TAUDB_MASK_TE,
                    PWM_SYNCHRONOUS_START_SID)

    if ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
       LpTAUDBUnitConfig->usSyncInitMask)  != LpTAUDBUnitConfig->usSyncInitMask)
    {
      /* Implements: PWM_ESDD_UD_189                                          */
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:2983)-10 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    LpTAUDBUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-10 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ Unit config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Update the pointer for the base address of the TAUJ unit registers */
    LucUserCntlRegsIndx = LpTAUJUnitConfig->ucUserCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate TOE value */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE |
                                            LpTAUJUnitConfig->ucSyncInitMask;
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Set the channel bits that are configured for synchronous stop,
       to disable the count operation */
    PWM_TAUJ_WRITE_REG_AND_MIRROR(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                   (uint8)LusTempReg,
                   &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                    (uint8)LusTempReg,
                    PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                    PWM_SYNCHRONOUS_START_SID)
    /* END Msg(2:3892)-1 */

    /* MISRA Violation: START Msg(4:4491)-4 */
    /* calculate TE value */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE |
                                               LpTAUJUnitConfig->ucSyncInitMask;
    /* QAC Warning: START Msg(2:3892)-1 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */

    /* Set the channel bits that are configured for synchronous start,
       to disable the count operation */
    PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTS,
                    LpTAUJUnitConfig->ucSyncInitMask)

    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                    (uint8)LusTempReg,
                    PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                    PWM_SYNCHRONOUS_START_SID)
    /* END Msg(2:3892)-1 */

    if ((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
          LpTAUJUnitConfig->ucSyncInitMask) != LpTAUJUnitConfig->ucSyncInitMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    LpTAUJUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-10 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif
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
** Function Name         : Pwm_HW_SynchronousStop
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This routine stops all PWM channels configured to
**                         support synchronous start/stop of timers and set the
**                         corresponding channels to their idle state.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LucDiagChannel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpTAUDBUnitConfig, Pwm_GpTAUJUnitConfig,
**                         Pwm_GpDiagUnitConfig
**
** Functions invoked     : Dem_ReportErrorStatus
**
** Registers Used        : SLPWGA0, SLPWGA1, SLPWGA2, TAUDnTE, TAUBnTE,
**                         TAUDnTT, TAUBnTT, TAUJnTE, TAUJnTT, TAUBnTOE,
**                         TAUBnTO, TAUDnTOE, TAUDnTO, TAUJnTOE, TAUJnTO
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_171, PWM_ESDD_UD_013, PWM_ESDD_UD_165             */
/* Implements:  EAAR_PN0066_FR_0112                                           */
#if (PWM_SYNC_START_SUPPORT == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SynchronousStop (void)
{
  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;
  /* Pointer to base address of PWGA Unit simultaneous start configuration */
  P2CONST(uint32, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStart;
   /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStartCntlRegs;
  uint32 LulTempReg;
  #endif

  /* Implements:  EAAR_PN0066_FR_0006, EAAR_PN0066_FR_0022                    */
  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                              LpTAUDBUnitConfig;

  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;

  #endif

  uint8_least LucCount;

  #if (PWM_TAU_UNIT_USED == STD_ON)
  uint16 LusTempReg;
  #endif

   #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
                                       || (PWM_TAUJ_UNIT_USED == STD_ON))
  uint8 LucUserCntlRegsIndx;
  #endif

  /* Implements:  EAAR_PN0066_FR_0043                                         */
  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  PWM_ENTER_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif

  #if (PWM_DIAG_UNIT_USED == STD_ON)
  /* Update the PWGA config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;
  /* Get the pointer to the configured array of sync start values */
  /* QAC Warning: START Msg(2:2814)-2 */
  LpDiagSyncStart = LpDiagUnitConfig->pDiagSyncStart;
  /* END Msg(2:2814)-2 */
  /* Get the pointer to the sync start control registers address */
  LpDiagSyncStartCntlRegs =
                (volatile SLPWGAReg *) LpDiagUnitConfig->pDiagSyncStartCntlRegs;

  /* QAC Warning: START Msg(2:3892)-1 */
  for (LucCount = PWM_ZERO; LucCount < PWM_THREE;  LucCount++)
  /* END Msg(2:3892)-1 */
  {
  switch (LucCount)
  {
  case 0U:
    /* QAC Warning: START Msg(2:2814)-2 */
    /* calculate ulSLPWGA0 value */
    LulTempReg = (LpDiagSyncStartCntlRegs->ulSLPWGA0)
                                                      & (~(*LpDiagSyncStart));
    /* END Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Set the Simultaneous stop feature of the configured channels */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
               &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                LulTempReg,
               &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA0)
    /* END Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_INIT(
               &LpDiagSyncStartCntlRegs->ulSLPWGA0,
                LulTempReg,
                PWM_PWGA_MASK_SLPWGA,
                PWM_SYNCHRONOUS_STOP_SID)

    if (LpDiagSyncStartCntlRegs->ulSLPWGA0 !=
               ((LpDiagSyncStartCntlRegs->ulSLPWGA0) & (~(*LpDiagSyncStart))))
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    break;
  case 1U:
    /* calculate ulSLPWGA1 value */
    LulTempReg =
                  (LpDiagSyncStartCntlRegs->ulSLPWGA1)& (~(*LpDiagSyncStart));
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Set the Simultaneous stop feature of the configured channels */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                  LulTempReg,
                 &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA1)
    /* END Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &LpDiagSyncStartCntlRegs->ulSLPWGA1,
                  LulTempReg,
                  PWM_PWGA_MASK_SLPWGA,
                  PWM_SYNCHRONOUS_STOP_SID)

    if (LpDiagSyncStartCntlRegs->ulSLPWGA1 !=
               ((LpDiagSyncStartCntlRegs->ulSLPWGA1) & (~(*LpDiagSyncStart))))
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    break;
  default:
    /* calculate ulSLPWGA2 value */
    LulTempReg =
                (LpDiagSyncStartCntlRegs->ulSLPWGA2) & (~(*LpDiagSyncStart));
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Set the Simultaneous stop feature of the configured channels */
    PWM_PWGA_WRITE_REG_AND_MIRROR(
                   &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                    LulTempReg,
                   &Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA2)
    /* END Msg(2:3892)-1 */
    PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                   &LpDiagSyncStartCntlRegs->ulSLPWGA2,
                    LulTempReg,
                    PWM_PWGA_MASK_SLPWGA,
                    PWM_SYNCHRONOUS_STOP_SID)

    if (LpDiagSyncStartCntlRegs->ulSLPWGA2 !=
               ((LpDiagSyncStartCntlRegs->ulSLPWGA2) & (~(*LpDiagSyncStart))))
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    break;
  }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the pointer to get next configured sync start channels */
    LpDiagSyncStart++;
    /* END Msg(4:0489)-1 */
  }
  #endif

  #if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Update the TAUD/TAUB unit config pointer */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  /* QAC Warning: START Msg(2:1252)-10 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Update the pointer for the base address of the TAUDB unit registers */
    LucUserCntlRegsIndx = LpTAUDBUnitConfig->ucUserCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* MISRA Violation: START Msg(4:4397)-8 */
    /* MISRA Violation: START Msg(4:2985)-15 */
    /* calculate TE value */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                           (~LpTAUDBUnitConfig->usSyncInitMask);
    LusTempReg &= PWM_MASK_WORD;
    /* END Msg(4:4397)-8 */
    /* END Msg(4:2985)-15 */

    /* Set the channel bits that are configured for synchronous stop,
       to disable the count operation */
    PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTT,
                    LpTAUDBUnitConfig->usSyncInitMask)

    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                  (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE,
                    LusTempReg,
                    PWM_TAUDB_MASK_TE,
                    PWM_SYNCHRONOUS_STOP_SID)

    /* Set the corresponding bits to disable TOE operation */
    /* Implements: EAAR_PN0066_FR_0112 */
    /* MISRA Violation: START Msg(4:4397)-8 */
    LusTempReg = Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE &
                                         (~LpTAUDBUnitConfig->usSyncInitMask);
    /* END Msg(4:4397)-8 */
    PWM_TAUDB_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                 &Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE)
    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE,
                  LusTempReg,
                  PWM_TAUDB_MASK_TOE,
                  PWM_SYNCHRONOUS_STOP_SID)
    /* MISRA Violation: START Msg(4:4397)-8 */
    LusTempReg = ((Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO &
                                        (~LpTAUDBUnitConfig->usSyncInitMask)) |
        ((LpTAUDBUnitConfig->usSyncInitMask) & (LpTAUDBUnitConfig->usTOMask)));
    /* END Msg(4:4397)-8 */
    /* Set the PWM output to its corresponding idle state */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                   LusTempReg)
    PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
                 (&Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTO,
                   LusTempReg,
                   PWM_TAUDB_MASK_TO,
                   PWM_SYNCHRONOUS_STOP_SID)
    /* MISRA Violation: START Msg(4:3344)-20 */
    if (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTE &
                                              LpTAUDBUnitConfig->usSyncInitMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    /* END Msg(4:3344)-20 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    LpTAUDBUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-10 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  #if (PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ Unit config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  /* MISRA Violation: START Msg(4:2877)-9 */
  /* QAC Warning: START Msg(2:1252)-10 */
  /* QAC Warning: START Msg(2:3892)-1 */
  for (LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  /* END Msg(2:1252)-10 */
  /* END Msg(2:3892)-1 */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Update the pointer for the base address of the TAUJ unit registers */
    LucUserCntlRegsIndx = LpTAUJUnitConfig->ucUserCntlRegsIndx;
    /* END Msg(2:2814)-2 */

    /* MISRA Violation: START Msg(4:4397)-8 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* calculate TE value */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                            (~LpTAUJUnitConfig->ucSyncInitMask);
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(4:4397)-8 */
    /* END Msg(4:4491)-4 */
    /* END Msg(2:3892)-1 */

    /* Set the channel bits that are configured for synchronous stop,
       to disable the count operation */
    PWM_WRITE_REG_ONLY(
                   &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTT,
                    LpTAUJUnitConfig->ucSyncInitMask)

    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                  (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE,
                    (uint8)LusTempReg,
                    PWM_TAUJ_MASK_TE_LOW_NIBBLE,
                    PWM_SYNCHRONOUS_STOP_SID)
    /* END Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* Set the corresponding bits to disable TOE operation */
    /* Implements EAAR_PN0066_FR_0112 */
    LusTempReg = Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE &
                                           (~LpTAUJUnitConfig->ucSyncInitMask);
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4397)-8 */
    /* END Msg(4:4491)-4 */
    PWM_TAUJ_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
           (uint8)LusTempReg,
                 &Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE)
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE,
                 (uint8)LusTempReg,
                  PWM_TAUJ_MASK_TOE_LOW_NIBBLE,
                  PWM_SYNCHRONOUS_STOP_SID)
    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4491)-4 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:4397)-8 */
    /* calculate new value for TO register */
    LusTempReg = ((Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO &
                                        (~LpTAUJUnitConfig->ucSyncInitMask)) |
    ((LpTAUJUnitConfig->ucSyncInitMask) & (uint8)(LpTAUJUnitConfig->ucTOMask)));
    /* END Msg(4:4397)-8 */
    LusTempReg &= PWM_MASK_LOW_NIBBLE;
    /* END Msg(2:3892)-1 */
    /* END Msg(4:4491)-4 */
    /* Set the PWM output to its corresponding idle state */
    /* QAC Warning: START Msg(2:3892)-1 */
    PWM_WRITE_REG_ONLY(
                  &Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                   (uint8)LusTempReg)
    PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
                 (&Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTO,
                  (uint8)LusTempReg,
                   PWM_TAUJ_MASK_TO_LOW_NIBBLE,
                   PWM_SYNCHRONOUS_STOP_SID)
    /* END Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:3344)-20 */
    if (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTE &
                                               LpTAUJUnitConfig->ucSyncInitMask)
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(PWM_E_TIMER_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    /* END Msg(4:3344)-20 */
    /* MISRA Violation: START Msg(4:2983)-10 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    LpTAUJUnitConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(4:2983)-10 */
  }
  /* END Msg(4:2877)-9 */
  #endif

  /* Implements:  EAAR_PN0066_FR_0043                                         */
  #if (PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  PWM_EXIT_CRITICAL_SECTION(PWM_REGISTERS_PROTECTION)
  #endif
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
** Function Name         : Pwm_HW_GetPrescalerValue
**
** Service ID            : NA
**
** Description           : This is PWM Driver Component support function.
**                         This routine returns the pre scalar value configured
**                         for a respective clock source.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddClockSource
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LusRetPrescalarVal
**
** Pre-conditions        : NA
**
** Global Variables used : Pwm_GpDiagUnitConfig
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_185                                               */
#if (PWM_DIAG_UNIT_USED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(uint16, PWM_PRIVATE_CODE) Pwm_HW_GetPrescalerValue
                                            (Pwm_ClockSourceType LddClockSource)
/* END Msg(2:3227)-3 */
{
  /* Implements:  EAAR_PN0034_FR_0049                                         */
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;

  uint16 LusRetPrescalarVal;

  /* QAC Warning: START Msg(2:3892)-1 */
  /* Initialize return value to default value */
  LusRetPrescalarVal = PWM_ZERO;
  /* END Msg(2:3892)-1 */

  /* Update the PWGA config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;

  switch (LddClockSource)
  {
  case PWM_CLOCK_SOURCE_0:
    {
    /* QAC Warning: START Msg(2:2814)-2 */
      LusRetPrescalarVal = LpDiagUnitConfig->usDiagPrescalerCk0;
    /* END Msg(2:2814)-2 */
    }
    break;

  case PWM_CLOCK_SOURCE_1:
    {
      LusRetPrescalarVal = LpDiagUnitConfig->usDiagPrescalerCk1;
    }
    break;

  case PWM_CLOCK_SOURCE_2:
    {
      LusRetPrescalarVal = LpDiagUnitConfig->usDiagPrescalerCk2;
    }
    break;

  case PWM_CLOCK_SOURCE_3:
    {
      LusRetPrescalarVal = LpDiagUnitConfig->usDiagPrescalerCk3;
    }
    break;

  /* QAC Warning: START Msg(2:2016)-7 */
  default:
    break;
  }
  /* END Msg(2:2016)-7 */

  return LusRetPrescalarVal;
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
** Function Name        : Pwm_HWCheckConsistency
**
** Service ID           : 0x1D
**
** Description          : This is PWM Driver Component support function.
**                        This API compares the control register values with its
**                        corresponding RAM mirror variable if
**                        PWM_TAUDB_RAM_MIRROR or PWM_TAUJ_RAM_MIRROR or
**                        PWM_PWGA_RAM_MIRROR is PWM_MIRROR_ENABLE.
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
** Preconditions        : This API is available only if the pre-compile
**                        option PWM_TAUDB_RAM_MIRROR or PWM_TAUJ_RAM_MIRROR
**                        or PWM_PWGA_RAM_MIRROR is PWM_MIRROR_ENABLE.
**
** Global Variables     :Pwm_GpChannelConfig, Pwm_GpDiagUnitConfig,
**                       Pwm_GaaTAUDBChannelRegMirror,
**                       Pwm_GaaTAUDBUserRegMirror,
**                       Pwm_GaaTAUJChannelRegMirror,
**                       Pwm_GaaTAUJUserRegMirror,
**                       Pwm_GaaPwgaRegsMirror.
**
** Functions invoked    : None
**
** Registers Used       : TAUDnCDRm, TAUBnCDRm, TAUDnCMORm, TAUBnCMORm,
**                        TAUDnTOE, TAUBnTOE, TAUDnTPS, TAUBnTPS, TAUDnBRS,
**                        TAUDnTOM, TAUBnTOM, TAUDnTOC, TAUBnTOC, TAUDnTOL,
**                        TAUBnTOL, TAUJnCDRm, TAUJnCMORm, TAUJnTOE, TAUJnTPS,
**                        TAUJnBRS, TAUJnTOM, TAUJnTOC, TAUJnTOL, SLPWGA0,
**                        SLPWGA1, SLPWGA2, PWGAnTCR, PWGAnCSDR, PWGAnCRDR,
**                        PWGAnCTL, PWGAINTMSK00, PWGAINTMSK01, PWGAINTMSK02,
**                        PWGAPRDSL0, PWGAPRDSL1, PWGAPRDSL2, PWBAnTE, PWBAnBRSm
**                        PWGAPRD.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_216, PWM_ESDD_UD_212                              */
/* Implements:  PWM094, SWS_Pwm_00094                                         */
#if ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE )    ||  \
      (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE )    ||  \
      (PWM_PWGA_RAM_MIRROR  == PWM_MIRROR_ENABLE ) )

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_HW_CheckHWConsistency
                                   (Pwm_HWConsistencyModeType HWConsistencyMode)
/* END Msg(2:3227)-3 */
{
  #if ((PWM_DIAG_UNIT_USED == STD_ON) && \
       (PWM_PWGA_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;

  /* Pointer to base address of PWGA Unit Generator control registers */
  P2VAR(volatile SLPWGAReg, AUTOMATIC, PWM_CONFIG_DATA) LpDiagSyncStartCntlRegs;

  uint8 LucDiagGeneratortCntlRegs;
  #endif

  #if ((PWM_TAU_UNIT_USED == STD_ON) && \
      ((PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE) || \
       (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE)))
  /* Pointer to the channel configuration */
  P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpChannelConfig;
  #endif

  #if (PWM_TAU_UNIT_USED == STD_ON)
  #if ((((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) && \
      (PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE)) || \
      ((PWM_TAUJ_UNIT_USED == STD_ON) && \
      (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE)))
  uint8 LucCntlRegs;
  uint8 LucUserCntlRegsIndx;
  uint8 LucOsCntlRegsIndx;
  #endif
  #endif

  #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) && \
        (PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* Pointer pointing to the TAUD/TAUB Unit configuration */
  P2CONST(Pwm_TAUDBUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpTAUDBUnitConfig;
  #endif

  #if ((PWM_TAUJ_UNIT_USED == STD_ON) && \
       (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpTAUJUnitConfig;
  #endif

  Std_ReturnType LddRetConsistencyState;
  uint8_least LucCount;

  LddRetConsistencyState = E_OK;

  #if (((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON)) && \
        (PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* Update TAUD/TAUB unit config pointer to point to the base TAUDB unit */
  LpTAUDBUnitConfig = Pwm_GpTAUDBUnitConfig;
  #endif

  #if ((PWM_TAUJ_UNIT_USED == STD_ON) && \
       (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* Update TAUJ unit config pointer to point to the base TAUJ unit */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif

  #if ((PWM_TAU_UNIT_USED == STD_ON) && \
      ((PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE) || \
       (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE)))

  if (PWM_DYNAMIC == HWConsistencyMode)
  {
    LpChannelConfig = Pwm_GpChannelConfig;
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:1252)-10 */
    for (LucCount = PWM_ZERO;
                          LucCount < PWM_TOTAL_TAU_CHANNELS_CONFIG; LucCount++)
    /* END Msg(2:1252)-10 */
    {
      /* QAC Warning: START Msg(2:2814)-2 */
      if ((PWM_HW_TAUD == (uint8)LpChannelConfig->uiPwmTAUType) ||
                          (PWM_HW_TAUB == (uint8)LpChannelConfig->uiPwmTAUType))
      /* END Msg(2:2814)-2 */
      /* END Msg(2:3892)-1 */
      {
        #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
              (PWM_TAUB_UNIT_USED == STD_ON)) &&\
              (PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE))

        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
        if(
          (Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCDR !=
                            Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCDR) ||
          (Pwm_GaaTAUDBChReg_BaseAddress[LucCntlRegs]->usCMOR !=
                            Pwm_GaaTAUDBChannelRegMirror[LucCntlRegs].usCMOR) ||
          (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOE !=
                        Pwm_GaaTAUDBUserRegMirror[LucUserCntlRegsIndx].usTOE))
        {
          LddRetConsistencyState = E_NOT_OK;
        }
        else
        {
          /* do nothing */
        }
        #endif
      }
      /* QAC Warning: START Msg(2:3892)-1 */
      else if (PWM_HW_TAUJ == (uint8)LpChannelConfig->uiPwmTAUType)
      /* END Msg(2:3892)-1 */
      {
        #if ((PWM_TAUJ_UNIT_USED == STD_ON) && \
             (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE))

        LucUserCntlRegsIndx = LpChannelConfig->ucTimerUnitIndex;
        LucCntlRegs = LpChannelConfig->ucCntlRegsIndx;
        if(
          (Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR !=
                              Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].ulCDR) ||
          (Pwm_GaaTAUJChReg_BaseAddress[LucCntlRegs]->usCMOR !=
                             Pwm_GaaTAUJChannelRegMirror[LucCntlRegs].usCMOR) ||
          (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOE !=
                           Pwm_GaaTAUJUserRegMirror[LucUserCntlRegsIndx].ucTOE))
        {
           LddRetConsistencyState = E_NOT_OK;
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
      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment the pointer to the next channel */
      LpChannelConfig++;
      /* END Msg(4:0489)-1 */
    }
  }
  else if (PWM_STATIC == HWConsistencyMode)
  {
    #if (((PWM_TAUD_UNIT_USED == STD_ON) || \
          (PWM_TAUB_UNIT_USED == STD_ON)) &&\
          (PWM_TAUDB_RAM_MIRROR  == PWM_MIRROR_ENABLE))

    /* MISRA Violation: START Msg(4:2877)-9 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:1252)-10 */
    for (LucCount = PWM_ZERO;
                            LucCount < PWM_TOTAL_TAUDB_UNITS_CONFIG; LucCount++)
    /* END Msg(2:1252)-10 */
    /* END Msg(2:3892)-1 */
    {
        /* QAC Warning: START Msg(2:2814)-2 */
        LucOsCntlRegsIndx = LpTAUDBUnitConfig->ucOsCntlRegsIndx;
        /* END Msg(2:2814)-2 */
        LucUserCntlRegsIndx = LpTAUDBUnitConfig->ucUserCntlRegsIndx;
        #if (PWM_TAUB_PRESCALER == STD_ON)
        if (PWM_HW_TAUB == LpTAUDBUnitConfig->uiPwmTAUType)
        {
         if (
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS !=
                                              LpTAUDBUnitConfig->usPrescaler) ||
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM !=
                                              LpTAUDBUnitConfig->usTOMMask) ||
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC !=
                                              LpTAUDBUnitConfig->usTOCMask) ||
            (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL !=
                                             LpTAUDBUnitConfig->usTOLMask))
         {
           LddRetConsistencyState = E_NOT_OK;
         }
         else
         {
           /* do nothing */
         }
        }
        else
        {
          /* do nothing */
        }
        #endif

        #if (PWM_TAUD_PRESCALER == STD_ON)
        if (PWM_HW_TAUD == LpTAUDBUnitConfig->uiPwmTAUType)
        {
         if (
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS !=
                                              LpTAUDBUnitConfig->usPrescaler) ||
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS !=
                                              LpTAUDBUnitConfig->ucBaudRate) ||
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOM !=
                                              LpTAUDBUnitConfig->usTOMMask) ||
            (Pwm_GaaTAUDBOsReg_BaseAddress[LucOsCntlRegsIndx]->usTOC !=
                                              LpTAUDBUnitConfig->usTOCMask) ||
            (Pwm_GaaTAUDBUserReg_BaseAddress[LucUserCntlRegsIndx]->usTOL !=
                                             LpTAUDBUnitConfig->usTOLMask))
         {
           LddRetConsistencyState = E_NOT_OK;
         }
         else
         {
           /* do nothing */
         }
        }
        else
        {
          /* do nothing */
        }
        #endif
        /* MISRA Violation: START Msg(4:0489)-1 */
        /* MISRA Violation: START Msg(4:2982)-11 */
        /* MISRA Violation: START Msg(4:2983)-10 */
        /* Increment the pointer to the next TAUD/TAUB Unit */
        LpTAUDBUnitConfig++;
        /* END Msg(4:0489)-1 */
        /* END Msg(4:2982)-11 */
        /* END Msg(4:2983)-10 */
    }
    /* END Msg(4:2877)-9 */
    #endif

    /* MISRA Violation: START Msg(4:2877)-9 */
    #if ((PWM_TAUJ_UNIT_USED == STD_ON) && \
         (PWM_TAUJ_RAM_MIRROR  == PWM_MIRROR_ENABLE))
    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:1252)-10 */
    for (LucCount = PWM_ZERO;
                             LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
    /* END Msg(2:1252)-10 */
    /* END Msg(2:3892)-1 */
    {
      /* QAC Warning: START Msg(2:2814)-2 */
      LucOsCntlRegsIndx = LpTAUJUnitConfig->ucOsCntlRegsIndx;
      /* END Msg(2:2814)-2 */
      LucUserCntlRegsIndx = LpTAUJUnitConfig->ucUserCntlRegsIndx;

      if(
        /* Implements:  PWM_ESDD_UD_125, EAAR_PN0066_FR_0023                  */
        #if (PWM_TAUJ_PRESCALER == STD_ON)
        (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->usTPS !=
                                             LpTAUJUnitConfig->usPrescaler) ||
        (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucBRS !=
                                             LpTAUJUnitConfig->ucBaudRate) ||
        #endif
        (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOM !=
                                               LpTAUJUnitConfig->ucTOMMask) ||
        (Pwm_GaaTAUJOsReg_BaseAddress[LucOsCntlRegsIndx]->ucTOC !=
                              ((uint8)(~LpTAUJUnitConfig->ucTAUChannelMask) &
                                                       PWM_MASK_LOW_NIBBLE)) ||
        (Pwm_GaaTAUJUserReg_BaseAddress[LucUserCntlRegsIndx]->ucTOL !=
                                             LpTAUJUnitConfig->ucTOLMask))
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* MISRA Violation: START Msg(4:2982)-11 */
      /* MISRA Violation: START Msg(4:4491)-4 */
      /* MISRA Violation: START Msg(4:2983)-10 */
      /* Increment the pointer to the next TAUD/TAUB Unit */
      LpTAUJUnitConfig++;
      /* END Msg(4:0489)-1 */
      /* END Msg(4:2982)-11 */
      /* END Msg(4:4491)-4 */
      /* END Msg(4:2983)-10 */

    }
    #endif
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END Msg(4:2877)-9 */

  #if ((PWM_DIAG_UNIT_USED == STD_ON) && \
       (PWM_PWGA_RAM_MIRROR  == PWM_MIRROR_ENABLE))
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Point to base address of SLPWGAm register */
  LpDiagSyncStartCntlRegs =
            (volatile SLPWGAReg *) Pwm_GpDiagUnitConfig->pDiagSyncStartCntlRegs;
  /* END Msg(2:2814)-2 */
  /* Update the PWGA Channel pointer to point to the first channel in
     configuration */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig;
  /* Update PWGA unit config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;

  if (PWM_DYNAMIC == HWConsistencyMode)
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:3892)-1 */
    /* Check SLPWGA registers */
    if (
        (LpDiagSyncStartCntlRegs->ulSLPWGA0 !=
                                  Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA0) ||
        (LpDiagSyncStartCntlRegs->ulSLPWGA1 !=
                                  Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA1) ||
        (LpDiagSyncStartCntlRegs->ulSLPWGA2 !=
                                  Pwm_GaaPwgaRegsMirror[PWM_ZERO].ulSLPWGA2))
    /* END Msg(2:2814)-2 */
    /* END Msg(2:3892)-1 */
    {
      LddRetConsistencyState = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }

    /* QAC Warning: START Msg(2:3892)-1 */
    /* QAC Warning: START Msg(2:1252)-10 */
    for (LucCount = PWM_ZERO;
                          LucCount < PWM_TOTAL_DIAG_CHANNELS_CONFIG; LucCount++)
    /* END Msg(2:1252)-10 */
    /* END Msg(2:3892)-1 */
    {
      /* QAC Warning: START Msg(2:2814)-2 */
      LucDiagGeneratortCntlRegs =
                              LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
      /* END Msg(2:2814)-2 */

      if (
         #if (PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON)
         (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR !=
                      Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucTCR) ||
        #endif
         (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCSDR !=
                     Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCSDR) ||
         (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->usCRDR !=
                     Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].usCRDR) ||
         (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL !=
                      Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucCTL))
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* MISRA Violation: START Msg(4:0489)-1 */
      /* Increment to next PWGA channel configuration */
      LpDiagChannelConfig++;
      /* END Msg(4:0489)-1 */
    }

    #if (PWM_DIAG_CHANNELGROUP_SUPPORT == STD_ON)
    /* QAC Warning: START Msg(2:3892)-1 */
    if (
        (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ZERO]->ulPWGAINTMSK !=
                      Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK00) ||
        (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_ONE]->ulPWGAINTMSK !=
                      Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK01) ||
        (Pwm_GaaPWGAINTFReg_BaseAddress[PWM_TWO]->ulPWGAINTMSK !=
                      Pwm_GstPwgaINTFMaskMirror.ulPWGAINTMSK02))
    /* END Msg(2:3892)-1 */
    {
        LddRetConsistencyState = E_NOT_OK;
    }
    else
    {
        /* No action required */
    }
    #endif
  }
  else if (PWM_STATIC == HWConsistencyMode)
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    if (
        #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)
        (LpDiagSyncStartCntlRegs->ulPWGAPRD !=
                                      LpDiagUnitConfig->usDiagPeriod) ||
        (LpDiagSyncStartCntlRegs->ulPWGAPRDSL0 != Pwm_GulGroup0) ||
        (LpDiagSyncStartCntlRegs->ulPWGAPRDSL1 != Pwm_GulGroup1) ||
        (LpDiagSyncStartCntlRegs->ulPWGAPRDSL2 != Pwm_GulGroup2) ||
        #endif
        (Pwm_GaaPWBAReg_BaseAddress->ucTE !=
                                   LpDiagUnitConfig->ucDiagStartTrgPrescaler) ||
        (Pwm_GaaPWBAReg_BaseAddress->usBRS0 !=
                                      LpDiagUnitConfig->usDiagPrescalerCk0) ||
        (Pwm_GaaPWBAReg_BaseAddress->usBRS1 !=
                                      LpDiagUnitConfig->usDiagPrescalerCk1) ||
        (Pwm_GaaPWBAReg_BaseAddress->usBRS2 !=
                                      LpDiagUnitConfig->usDiagPrescalerCk2) ||
        (Pwm_GaaPWBAReg_BaseAddress->usBRS3 !=
                                      LpDiagUnitConfig->usDiagPrescalerCk3))
    /* END Msg(2:2814)-2 */
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
    /* do nothing */
  }
  #endif

  return(LddRetConsistencyState);
}

#define PWM_STOP_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

#endif /* End of ( (PWM_TAUDB_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
                    (PWM_TAUJ_RAM_MIRROR == PWM_MIRROR_ENABLE ) || \
                    (PWM_PWGA_RAM_MIRROR == PWM_MIRROR_ENABLE ) )*/

/*******************************************************************************
** Function Name        : Pwm_HW_ControlTriggerOutput
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function control enable/disable of
**                        ADC trigger output.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannelId, LddCtl
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : LddRetControlStatus
**
** Pre-conditions       : This API is available only if the pre-compile
**                        option PWM_CONTROL_TRIGGER_OUTPUT_API and
**                        PWM_DIAG_UNIT_USED are STD_ON.
**
** Global Variable used : Pwm_GpDiagChannelConfig
**
** Functions invoked    : Pwm_HW_StartDiagChannel, Pwm_HW_StopDiagChannel
**
** Registers Used       : PWGAnTCR, PWGAnCTL, PWGAnRSF, PWGAnRDT.
**
*******************************************************************************/
/* Implements:  PWM_ESDD_UD_225, PWM_ESDD_UD_223                              */
#if ((PWM_CONTROL_TRIGGER_OUTPUT_API == STD_ON) &&  \
                                        (PWM_DIAG_UNIT_USED == STD_ON))

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

/* QAC Warning: START Msg(2:3227)-3 */
FUNC(Std_ReturnType, PWM_PRIVATE_CODE) Pwm_HW_ControlTriggerOutput
                 (Pwm_ChannelType LddChannelId, Pwm_TriggerControlType LddCtl)
/* END Msg(2:3227)-3 */
{
  /* Pointer to the channel configuration */
  P2CONST(Pwm_DiagChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                            LpDiagChannelConfig;
  uint8 LucDiagChannelStatus;
  uint8 LucDiagGeneratortCntlRegs;
  uint8 LucDiagChannel;
  Std_ReturnType LddRetControlStatus;
  /* Loop count containing timeout value */
  uint32 LulTimeOutCount;

  LddRetControlStatus = E_OK;

  /* MISRA Violation: START Msg(4:0488)-3 */
  /* MISRA Violation: START Msg(4:2985)-15 */

  /* QAC Warning: START Msg(2:2824)-4 */
  LpDiagChannelConfig = Pwm_GpDiagChannelConfig + (LddChannelId -
                                             PWM_MIN_DIAG_CHANNELS_CONFIG_ID);
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0488)-3 */
  /* END Msg(4:2985)-15 */

  /* QAC Warning: START Msg(2:2814)-2 */
  LucDiagGeneratortCntlRegs =
                            LpDiagChannelConfig->ucDiagGeneratortCntlRegsIndx;
  /* END Msg(2:2814)-2 */

  LucDiagChannel = LpDiagChannelConfig->ucDiagChannel;

  if (PWM_ENABLE == LddCtl)
  {
    /* Check if TOE bit is disabled */
    if (PWM_PWGA_TRGOUT_DISABLE ==
                   Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR)
    {
      /* QAC Warning: START Msg(2:3892)-1 */
      if((PWM_TCUT_LOW == (PWM_TCUT_LOW &
             (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL))) ||
         (PWM_TCUT_HIGH == (PWM_TCUT_HIGH &
              (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucCTL))))
      /* END Msg(2:3892)-1 */
      {
        /* Get the PWGA channel status */
        LucDiagChannelStatus = Pwm_HW_GetDiagChannelStatus(LddChannelId);
        /* Check whether channel is started */
        if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
        {
          /* Stop PWGA channel */
          Pwm_HW_StopDiagChannel(LucDiagChannel,
                                      PWM_CONTROL_TRIGGER_OUTPUT_SID);
        }
        else
        {
          /* No action required */
        }
        /* load loop count */
        LulTimeOutCount = PWM_TIMEOUT_COUNT;
        /* QAC Warning: START Msg(2:3892)-1 */
        while ((PWM_ZERO != LulTimeOutCount) &&
        (PWM_PWGA_TCBR_REWRITE_COMPLETED != (PWM_PWGA_TCBR_REWRITE_TRIGGER &
               (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF))))
        /* END Msg(2:3892)-1 */
        {
          /* Decrement the loop count */
          LulTimeOutCount--;
        }
        /* QAC Warning: START Msg(2:3892)-1 */
        if (PWM_PWGA_TCBR_REWRITE_COMPLETED == (PWM_PWGA_TCBR_REWRITE_TRIGGER &
                (Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRSF)))
        /* END Msg(2:3892)-1 */
        {
          /* Enable trigger out */
          PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                    PWM_PWGA_TRGOUT_ENABLE,
                    &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucTCR)
          /* QAC Warning: START Msg(2:3892)-1 */
          PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                      PWM_PWGA_TRGOUT_ENABLE,
                      PWM_MASK_FIRST_BIT,
                      PWM_CONTROL_TRIGGER_OUTPUT_SID)
          /* END Msg(2:3892)-1 */
          PWM_WRITE_REG_ONLY(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucRDT,
                     PWM_PWGA_TCBR_REWRITE_TRIGGER)
        }
        else
        {
          /* Implements: PWM_ESDD_UD_190                                      */
          /* In case the register is not updated in the expected time, */
          /* report DEM error */
          Dem_ReportErrorStatus(PWM_E_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
          LddRetControlStatus = E_NOT_OK;
        }
        /* Check whether channel is started */
        if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
        {
          /* Start PWGA channel */
          Pwm_HW_StartDiagChannel(LucDiagChannel,
                                      PWM_CONTROL_TRIGGER_OUTPUT_SID);
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* Get the PWGA channel status */
        LucDiagChannelStatus = Pwm_HW_GetDiagChannelStatus(LddChannelId);
        /* Check whether channel is started */
        if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
        {
          /* Stop PWGA channel */
          Pwm_HW_StopDiagChannel(LucDiagChannel,
                                      PWM_CONTROL_TRIGGER_OUTPUT_SID);
        }
        else
        {
          /* No action required */
        }
        /* Enable trigger out */
        PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                   PWM_PWGA_TRGOUT_ENABLE,
                   &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucTCR)
        /* QAC Warning: START Msg(2:3892)-1 */
        PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                    PWM_PWGA_TRGOUT_ENABLE,
                    PWM_MASK_FIRST_BIT,
                    PWM_CONTROL_TRIGGER_OUTPUT_SID)
        /* END Msg(2:3892)-1 */

        /* Check whether channel is started */
        if (PWM_DIAG_CH_STARTED == LucDiagChannelStatus)
        {
          /* Start PWGA channel */
          Pwm_HW_StartDiagChannel(LucDiagChannel,
                                      PWM_CONTROL_TRIGGER_OUTPUT_SID);
        }
        else
        {
          /* No action required */
        }
      }
    }
    else
    {
      LddRetControlStatus = E_NOT_OK;
    }
  }
  else if (PWM_DISABLE == LddCtl)
  {
    /* Check if TOE bit is enabled */
    if (PWM_PWGA_TRGOUT_ENABLE ==
                   Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR)
    {
      /* Disable trigger out */
      PWM_PWGA_WRITE_REG_AND_MIRROR(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                 PWM_PWGA_TRGOUT_DISABLE,
                 &Pwm_GaaPwgaRegsMirror[LucDiagGeneratortCntlRegs].ucTCR)
      /* QAC Warning: START Msg(2:3892)-1 */
      PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(
                 &Pwm_GaaPWGAReg_BaseAddress[LucDiagGeneratortCntlRegs]->ucTCR,
                  PWM_PWGA_TRGOUT_DISABLE,
                  PWM_MASK_FIRST_BIT,
                  PWM_CONTROL_TRIGGER_OUTPUT_SID)
      /* END Msg(2:3892)-1 */
    }
    else
    {
      LddRetControlStatus = E_NOT_OK;
    }
  }
  else
  {
    /* No action required */
  }

  return(LddRetControlStatus);
}

#define PWM_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0862)-5 */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
#endif
/* END Msg(2:0862)-5 */

/*******************************************************************************
** Function Name        : Pwm_HW_GetDiagChannelPeriod
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function return the LusDiagPeriod of
**                        PWM DIAG channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LucPwmShift
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : LusRetDiagPeriod
**
** Pre-conditions       : This API is available only if the pre-compile
**                        option PWM_PERIOD_SELECTION_SUPPORT is STD_ON.
**
** Global Variable used : Pwm_GpDiagUnitConfig
**
** Functions invoked    : None
**
** Registers Used       : None
**
*******************************************************************************/
#if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"
#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif

FUNC(uint16, PWM_PRIVATE_CODE) Pwm_HW_GetDiagChannelPeriod(uint8 LucPwmShift)
{
  uint16 LusRetDiagPeriod;
  uint8  LucDiagChannelShift;
  /* Pointer pointing to the PWGA Unit configuration */
  P2CONST(Pwm_DiagUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST) LpDiagUnitConfig;
  /* Update PWGA unit config pointer to point to the current PWGA unit */
  LpDiagUnitConfig = Pwm_GpDiagUnitConfig;
  LusRetDiagPeriod = (LpDiagUnitConfig->usDiagPeriod);
  LucDiagChannelShift = LucPwmShift;

  /* Check whether channel belongs to group1 */
  if ((PWM_DIAG_GROUP1 <= LucDiagChannelShift) &&
                      (LucDiagChannelShift < PWM_DIAG_GROUP2))
  {
    LucDiagChannelShift = (LucDiagChannelShift - PWM_DIAG_GROUP1);
    /* Check if the diag channel is configured as FREE RUNNING */
    if (((Pwm_GulGroup1 >> LucDiagChannelShift) & PWM_ONE) != PWM_ONE)
    {
     LusRetDiagPeriod = PWM_DIAG_MAX_COUNT;
    }
    else
    {
    /* No action required */
    }
  }
  /* Check whether channel belongs to group2 */
  else if ((PWM_DIAG_GROUP2 <= LucDiagChannelShift) &&
                    (LucDiagChannelShift < PWM_TOTAL_DIAG_CHANNELS))
  {
    LucDiagChannelShift = (LucDiagChannelShift - PWM_DIAG_GROUP2);
    /* Check if the diag channel is configured as FREE RUNNING */
    if (((Pwm_GulGroup2 >> LucDiagChannelShift) & PWM_ONE) != PWM_ONE)
    {
     LusRetDiagPeriod = PWM_DIAG_MAX_COUNT;
    }
    else
    {
    /* No action required */
    }
  }
  /* Check whether channel belongs to group0 */
  else if (PWM_DIAG_GROUP1 > LucDiagChannelShift)
  {
    /* Check if the diag channel is configured as FREE RUNNING */
    if (((Pwm_GulGroup0 >> LucDiagChannelShift) & PWM_ONE) != PWM_ONE)
    {
     LusRetDiagPeriod = PWM_DIAG_MAX_COUNT;
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
  return(LusRetDiagPeriod);
}

#define PWM_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0862)-5 */
#if (PWM_AR_VERSION  == PWM_AR_HIGHER_VERSION)
/* Functionality related to R4.2 */
#include "Pwm_MemMap.h"

#elif(PWM_AR_VERSION  == PWM_AR_LOWER_VERSION)
/* Functionality related to R4.0 */
#include "MemMap.h"
#endif
/* END Msg(2:0862)-5 */
#endif /* end of #if (PWM_PERIOD_SELECTION_SUPPORT == STD_ON) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
