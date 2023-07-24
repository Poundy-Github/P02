/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.c                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of PORT Driver                                */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
* V1.0.0:  10-Sep-2015  : Initial Version
*
* V1.0.1:  16-Sep-2015  : The following changes are made;
*                         1. Update for fixing, justifying the MISRA warning
*                         after Static Analysis
*                         2. The protected registers write procedure updated
*
* V1.0.2:  30-Dec-2015  : The following changes are made:
*                         1. As a part of JIRA ticket ARDAAGA-79
*                            Function Port_GetVersionInfo() is added and
*                            Det.h file inclusion is removed
*                            Updating sequence of PMCSR is corrected in
*                            API Port_SetToDioOrAltMode() before checking PIPC
*                            availability.
*                         2. As part of JIRA - ARDAAGA-20 LucModeCheck
*                            conditional checking is added in
*                            Port_SearchChangeablePinDetail().
*                         3. As part of JIRA ARDAAGA-128  in
*                            Port_SetToDioOrAltMode API, ucPortType is masked
*                            with PORT_PG_TYPE_MASK macro before checking
*                            if it is JTAG port group.
*                         4. As part of JIRA ARDAAGA-128 in API
*                            Port_SetPinDefaultMode(), while checking the
*                            availability of the PFCE register is corrected.
*                         5. As part of JIRA ARDAAGA-129 in API
*                            Port_SetPinDefaultMode() PMCSR, JPMCSR
*                            register values are updated correctly.
*                         6. As part of JIRA ARDAAGA-129  API
*                            Port_SetPinDirection() is updated for Analog port.
*                         7. As part of JIRA ARDAAGA-133, API Port_InitConfig()
*                            is updated to handle deep stop mode.
*                         8. As a part of JIRA ARDAAGA-8 DnfaReg_BaseAddress is
*                            is corrected to DnfaRegisters_BaseAddress.
*                         9. QAC warnings are fixed and justified.
*                        10. As a part of JIRA ARDAAGA-138 value of LddHigh in
*                            Port_SearchChangeablePinDetail is updated to
*                            get total no. of modifiable PINS even in multiple
*                            configurations.
* V2.0.0:  14-Sep-2016  : As part of FUSA implementation, the following
*                         changes are made:
*                         1. Updated registers write to use the macros for
*                            Write-Verify and RAM Mirror.(ticket ARDAABC-757)
*                         2. Added Dio_CheckHWConsistency public function
*                            which is enabled when RAM Mirror is used.
*                            (ticket ARDAABC-758)
* V2.1.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
*                         changes are made:
*                         1. Changed AUTOSAR lower version to 4.0.3 and
*                            higher version to 4.2.2. Removed Autosar 3.2.2
*                            from implementation.
*                         2. Removed precompile switch in order to include
*                            Port_Debug for both AR4.0.3 and AR4.2.2.
*                         3. Common approach for lower and higher Autosar
*                            version in Port_GetVersionInfo function.
* V2.1.1:  11-Nov-2016  : As part of ARDAABC-867 Jira ticket, the following
*                         changes are made:
*                         1. Alphabetical port registers are removed from
*                            implementation as they are not applicable for F1K.
*                         2. Code related to PINV registers was removed as it is
*                            not applicable for F1K microcontroller.
* V2.1.2:  14-Nov-2016  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made in Port_CheckHWConsistency function:
*                         1. Use the correct register index.
*                         2. Update mask used for JPMSR.
* V2.2.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
*                         changes are made:
*                         1. Include MemMap header file from "Port_Cfg.h".
*                         2. Use precompile switches to select different
*                            memory section names in AR4.0.3 and AR4.2.2.
* V2.2.1:  16-Nov-2016  : As part of ARDAABC-758, updated API IDs that are used
*                         for write-verify safety mechanism.
* V2.2.2:  17-Nov-2016  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made:
*                         1. Use macros with masks to check register writes.
*                         2. Remove ram images for PSR, PMSR, PMCSR, JPSR,
*                            JPMSR, JPMCSR, APSR, APMSR, APMCSR registers.
*                         3. Variable LpDNFAReg is incremented even if
*                            PORT_DNFAEN_REG_AVAILABLE is STD_OFF.
* V2.3.0:  18-Nov-2016  : As part of ARDAABC-621 Jira ticket, the following
*                         changes are made:
*                         1. In function Port_GetVersionInfo, use PORT_E_INIT
*                            for AR4.2.2 and PORT_E_PARAM_CONFIG for AR4.0.3.
* V2.3.1:  18-Nov-2016  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made:
*                         1. Updated name from Port_GaaRamMirrorJPortReg to
*                            Port_GstRamMirrorJPortReg.
*                         2. Code cosmetics and improvements; avoid multiple
*                            dereferencing in Port_CheckHWConsistency function.
* V2.3.2:  20-Nov-2016  : As part of ARDAABC-850, the following changes are
*                         made:
*                         1. Added a delay after clearing IOHOLD.IOHOLD bit.
*                            The delay length is 3xEMCLK and is defined in
*                            "Port_Cfg.h" if IOHOLD is available.
* V2.3.3:  21-Nov-2016  : As part of ARDAABC-758 Jira ticket, the following
*                         changes are made:
*                         1. Added write check for protected registers.
*                         2. Updated masks for PSR, PMSR and PMCSR on numeric,
*                            analog and JTAG port groups.
* V2.3.4:  22-Nov-2016  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made:
*                         1. Return E_NOT_OK if Port_CheckHWConsistency is
*                            called with an invalid check type.
* V2.3.5:  22-Nov-2016  : As part of ARDAABC-538, the following changes are
*                         made:
*                         1. Removed AR3.2.2 traceability tags.
*                         2. Added AR4.2.2 traceability tags.
*                         3. Updated format for traceability comments.
* V2.3.6:  23-Nov-2016  : As part of ARDAABC-914 ticket, the following changes
*                         are made:
*                         1. Added "Det.h" inclusion if development errors are
*                            enabled.
* V2.3.7:  24-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
*                         changes are made:
*                         1. Updated comments for precompile switches.
*                         2. Updated code so E_NOT_OK is returned in
*                            Port_CheckHWConsistency even if development errors
*                            detection is disabled.
*                         3. Removed unnecessary variables and precompile
*                            switches.
* V2.3.8:  25-Nov-2016  : As part of ARDAABC-867 Jira ticket, the following
*                         changes are made:
*                         1. Removed DNFnEDCm and DNFAnCKS as not applicable
*                            for F1K.
* V2.3.9:  25-Nov-2016  : As part of ARDAABC-757 Jira ticket the following
*                         changes are made:
*                         1. Check all portgroups in hardware consistency check
*                            function.
* V2.4.0:  28-Nov-2016  : As part of ARDAABC-934 Jira ticket, the following
*                         changes are made:
*                         1. Improved code by avoiding too many de-references
*                            of 'usPinPositionMask'.
* V2.4.1:  25-Nov-2016  : As part of ARDAABC-757 Jira ticket the following
*                         changes are made:
*                         1. Use correct offset for FCLA registers when
*                            performing Hardware Consistency Check.
*                         2. Check if PIPC, PFCE, PFCAE registers are available
*                            when performing hardware consistency checks on
*                            them.
* V2.4.2:  19-Dec-2016  : As part of ARDAABC-757 Jira ticket the following
*                         changes are made:
*                         1. Updated Hardware Consistency Check function to
*                            work when PORT_DEV_ERROR_DETECT == STD_ON.
* V2.4.3:  20-Dec-2016  : The following changes are made:
*                         1. Added Service ID in Port_CheckHWConsistency
*                            function banner.
* V2.4.4:  16-Jan-2017  : As part of ARDAABC-860, the following changes
*                         are made:
*                         1. Removed PORT_DEM_ERROR_DETECT precompile switch.
* V2.4.5:  19-Jan-2017  : As part of ARDAABC-934 Jira ticket, the following
*                         changes are made:
*                         1. Updated usPinPositionMask usage.
* V2.4.6:  08-Feb-2017  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made in Port_CheckHWConsistency:
*                         1. Removed unnecessary precompile switches.
*                         2. Removed hard-coded magic numbers.
*                         3. Updated critical section usage. Use only if
*                            the module is initialized.
* V2.4.7:  11-Feb-2017  : As part of ARDAABC-629 Jira ticket, the following
*                         changes are made in Port_InitConfig:
*                         1. Use LpAPortReg pointer instead of LpPortReg for
*                            Analog Port Groups.
* V2.4.8:  12-Feb-2017  : As part of ARDAABC-757 Jira ticket, the following
*                         changes are made in Port_CheckHWConsistency:
*                         1. Return a DET error if Port_CheckHWConsistency is
*                            called with a parameter different than
*                            PORT_HW_CONSIST_CHECK_STATIC and
*                            PORT_HW_CONSIST_CHECK_DYNAMIC.
* V2.4.9:  22-Feb-2017  : As part of ARDAABC-867 Jira ticket, the following
*                         changes are made in Port_Port_SetToDioOrAltMode:
*                         1. Use PORT_PG_TYPE_MASK when checking for
*                            PORT_GROUP_ANALOG port group type.
* V2.4.10: 08-Mar-2017  : As part of ARDAABC-970 Jira ticket, the following
*                         changes are made:
*                         1. Add compiler switches to suppress warnings.
* V2.4.11: 09-Mar-2017  : As part of ARDAABC-629 Jira ticket, the following
*                         changes are made:
*                         1. QAC warnings removed.
*                         2. Add QAc comments into code.
* V2.4.12: 10-Mar-2017  : As part of ARDAABC-758 ticket, the following changes
*                         are made:
*                         1. Added PORT_E_INVALID_CHECKTYPE DET error code.
* V2.4.13: 16-Mar-2017  : As part of ARDAABC-633 ticket, the following changes
*                         are made:
*                         1. Port_CheckHWConsistency updated for PFC register.
* V2.4.14: 29-Jun-2017  : As part of ARDAABD-1889, Following changes are made:
*                         1. Support of PISA register is added for Numeric
*                         port group.
*                         2. QAC justifications given for Msg(4:2985)-16,
*                         Msg(4:1891)-11,and Msg(4:0489)-7 messages.
* V2.4.15: 25-Jul-2017  : Following changes are made:
*                         1. As part of ARDAABD-1889, Precompile switch is
*                         added while writing the PISA register.
*                         2. As per JIRA ARDAABD-1520, Critical section usage is
*                         removed from Port_InitConfig API.
*                         3. As per JIRA ARDAABD-2199, ECODE is updated.
* V2.4.16: 09-Oct-2017  : Following changes are made:
*                         1. As part of ARDAABD-2369, PORT_LOOP_TIMEOUT is
*                         renamed as PORT_UNLOCK_SEQUENCE_COUNT.
*                         2. As part of ARDAABD-2379, Naming
*                         convention is updated for the registers.
*                         3. As part of JIRA ARDAABD-1198, Port_Init,
*                         Port_SetPinDirection, Port_SetPinMode,
*                         Port_SetPinDefaultDirection, Port_SetPinDefaultMode
*                         APIs are modified to add NULL_PTR checks.
*                         4. As part of JIRA ARDAABD-2457, Include Section is
*                         updated for adding Iocommon_Defines.h file.
*                         5. As part of JIRA ARDAABD-2437,
*                         Port_CheckHWConsistency API is updated to check the
*                         registers PODC, PDSC, PISA, JPODC and JPDSC.
*                         6. As part of JIRA ARDAABD-2441,
*                         Added critical section in Port_CheckHWConsistency Api
*                         and updated critical section usage in Port_SetPinMode.
*                         7. QAC justifications given for Msg(4:0715)-18
*                         and Msg(4:2982)-14 messages.
* V2.4.17: 07-May-2018  : Following changes are made:
*                         1. As part of ARDAABD-3110, Variable used to wait-loop
*                         shall be declared volatile.
*                         2. As part of ARDAABD-3705, When the hardware error is
*                         detected, the error message is returned and the
*                         subsequent actions are stopped.
* V2.4.18: 22-May-2018 : As part of ARDAABD-3707, Following changes are made:
*                        1.Add RH850_DUMMY_READ_SYNCP(16, ICP0) to fix the fault
*                         synchronization at the timing when control shifts from
*                         MCAL to application
*                        2. Misra warning Tag for Message Msg(4:0303)
*                         has been added.
* V2.4.19: 26-Jul-2018 : Following change is made:
*                        1. As part of ARDAABD-3943,
*                         Changed section name
*                         Port_PORT_SET_PIN_MODE_PROTECTION,
*                         PORT_SET_PIN_DIR_PROTECTION,
*                         PORT_CHECK_HW_CONSISTENCY_PROTECTION,
*                         PORT_SET_TO_DIO_ALT_PROTECTION,
*                         PORT_INIT_CONFIG_PROTECTION,
*                         PORT_REFRESH_PORT_INTERNAL_PROTECTION,
*                         PORT_SET_PIN_DEFAULT_MODE_PROTECTION,
*                         PORT_SET_PIN_DEFAULT_DIR_PROTECTION to
*                         Port_PORT_REGISTER_PROTECTION.
* V2.4.20: 08-Aug-2018 : Following change is made:
*                        1. As part of ARDAABD-1748,
*                        The Port_InitConfig() function is invoked
*                        after invoking the Port_FilterConfig() function in
*                        100ns at least.
* V2.4.21: 10-Aug-2018  : Following changes are made:
*                         1. As part of ARDAABD-3656, Port_InitConfig API is
*                         updated to remove skipping initialization for all
*                         other registers except PSRn.
*                         2. As part of ARDAABD-2125, Port_InitConfig API is
*                         updated to add skipping initialization for JPSR0
*                         register.
*                         3. As part of JIRA ARDAABD-3621, Function banners
*                         of APIs are corrected according to the registers
*                         used.
*                         4. As part of ARDAABD-3844, Requirements and
*                         Design ID's are mapped to the implementation in order
*                         to improve coverage.
* V2.4.22: 05-Oct-2018   : Following changes are done : 
*                         1. As part of ARDAABD-3707, ICP0 usage error
*                         modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to 
*                         RH850_DUMMY_READ_SYNCP(16, &(ICP0))
* V2.4.23: 18-Oct-2018   : Following change is made:
*                         1.As part of ARDAABD-3707
*                         Remove the RH850_DUMMY_READ_SYNCP Marco.
* V2.4.24: 31-Jan-2019   : Following change is made:
*                         1.As part of ARDAABD-2125, Port_InitConfig API is
*                         updated to add skipping initialization of JPSR0
*                         register for ISO PORT groups and all the registers
*                         for AWO port groups.
* V2.4.25: 07-May-2019   : Following changes are made:
*                         1. As part of ARDAABD-4273, add available judgement
*                         for PFC and PMCSR in Port_InitConfig(), and
*                         PMCSR in Port_SetToDioOrAltMode().
*                         2. Update the year of copyright.
* V2.4.26: 17-Oct-2019   : Following changes are made:
*                         1. As part of ARDAABD-3817, add a conditional
*                         statement for the initialization of AWO/ISO when
*                         PORT_PIN_STATUS_BACKUP != STD_ON in function
*                         Port_InitConfig().
*                         2. As part of ARDAABD-4075, the mask of JPMSR used in
*                         PORT_CHECK_WRITE_VERIFY_INIT is changed from
*                         PORT_JPORT_MASK to PORT_JPMSR_MASK.
*                         3. modified Maximum Column Width shall be 80 at line
*                         276--311,line 672,675,676
*/
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Port.h inclusion and macro definitions */
/* Implements EAAR_PN0034_FR_0052, PORT129, SWS_Port_00129 */
/* Implements PORT131, SWS_Port_00131, EAAR_PN0034_FR_0065 */
/* Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0007 */
/* Implements EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020 */
/* Implements EAAR_PN0034_NR_0018, AR_PN0062_FR_0005 */
/* Implements AR_PN0062_NR_0004, AR_PN0062_NR_0003 */
/* Implements AR_PN0062_FR_0003, AR_PN0062_FR_0004 */
/* Implements AR_PN0062_NR_0002, AR_PN0062_NR_0001, EAAR_PN0034_FR_0018 */
/* Implements PORT080, SWS_Port_00080 */
/* Implements PORT207, SWS_Port_00207 */
#include "Port.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
#include "Port_PBTypes.h"
/* Implements EAAR_PN0034_FR_0030 */
/* Implements PORT_ESDD_UD_023 */
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
/* Implements PORT131 */
/* Implements SWS_Port_00131 */
#include "SchM_Port.h"
#endif
/* Implements PORT131, SWS_Port_00131 */
/* Implements PORT107 */
/* Implements PORT_ESDD_UD_014 */
/* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/* Implements PORT115, SWS_BSW_00409 */
/* Implements PORT037, PORT038 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Port_Ram.h"
#include "Port_RegWrite.h"
#include "Iocommon_Defines.h"
#include "Rh850_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_C_AR_RELEASE_MAJOR_VERSION     PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_MINOR_VERSION     PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_REVISION_VERSION \
                                         PORT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */

#define PORT_C_SW_MAJOR_VERSION    2
#define PORT_C_SW_MINOR_VERSION    4
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/* Implements PORT114,EAAR_PN0034_FR_0055,SWS_Port_0014 */

#if (PORT_AR_RELEASE_MAJOR_VERSION != PORT_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port.c : Mismatch in Release Major Version"
#endif
#if (PORT_AR_RELEASE_MINOR_VERSION != PORT_C_AR_RELEASE_MINOR_VERSION)
  #error "Port.c : Mismatch in Release Minor Version"
#endif
#if (PORT_AR_RELEASE_REVISION_VERSION != PORT_C_AR_RELEASE_REVISION_VERSION)
  #error "Port.c : Mismatch in Release Revision Version"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_C_SW_MAJOR_VERSION)
  #error "Port.c : Mismatch in Software Major Version"
#endif
#if (PORT_SW_MINOR_VERSION != PORT_C_SW_MINOR_VERSION)
  #error "Port.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2995)The result of this logical operation is always     */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable 'LddReturnValue' is not necessary always      */
/*                 TRUE.                                                      */
/*                 completed.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-1 and                           */
/*                 END Msg(4:2995)-1  tags in the code.                       */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) [I] Cast between a pointer to object and an       */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-3 and                           */
/*                 END Msg(4:0306)-3 tags in the code.                        */

/******************************************************************************/

/* 4.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4461)This assignment is redundant. The value of this    */
/*                  object is never used before being modified.               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The Warning Occurs only if user configures one HW unit.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4461)-4 and                           */
/*                 END Msg(4:4461)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2962) Apparent: Using value of uninitialized            */
/*                  automatic object.                                         */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2962)-5 and                           */
/*                 END Msg(4:2962)-5 tags in the code.                        */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:0488) Performing Pointer arithmetic.                    */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : This is to get the ID in the data structure in the code.   */
/*Verification   : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/*Reference      : Look for START Msg(4:0488)-6 and                           */
/*                 END Msg(4:0488)-6  tags in the code.                       */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) The integer value 1 is being added or             */
/*                  subtracted from a pointer.                                */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Increment operator is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-7 and                           */
/*                 END Msg(4:0489)-7 tags in the code.                        */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                  result is always '0'.                                     */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-8 and                           */
/*                 END Msg(4:2984)-8 tags in the code.                        */

/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex bitwise*/
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-9 and                           */
/*                 END Msg(4:4397)-9 tags in the code.                        */

/******************************************************************************/

/* 10.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To access registers in an optimized approach.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-10 and                          */
/*                 END Msg(4:0491)-10 tags in the code.                       */

/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:1891) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned short) is being implicitly converted to a   */
/*                 wider unsigned type, 'unsigned long'.                      */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : unsigned type is offset address being added to base address*/
/*                 to calculate register address                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1891)-11 and                          */
/*                 END Msg(4:1891)-11 tags in the code.                       */

/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-12 and                          */
/*                 END Msg(4:3138)-12 tags in the code.                       */

/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (6:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-13 and                          */
/*                 END Msg(6:0857)-13 tags in the code.                       */

/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable that is being assigned is of return type .If  */
/*                 any error occurs it will return the default assigned value.*/
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for MISRA Violation: START Msg(4:2982)-14 and         */
/*                 END Msg(4:2982)-14 tags in the code.                       */

/******************************************************************************/

/* 15. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983) This assignment is redundant. The value of this   */
/*                  object is never subsequently used.                        */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable is used subsequently as part of other         */
/*                 configuration when the corresponding switch is ON.         */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for MISRA Violation: START Msg(4:2983)-15 and         */
/*                 END Msg(4:2983)-15 tags in the code.                       */

/******************************************************************************/

/* 16. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2985) This operation is redundant. The value of the     */
/*                 result is always that of the left-hand operand.            */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value of the local variable accessed changes with      */
/*                 configuration.                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2985)-16 and END Msg(4:2985)-16 tags  */
/*                 in the code.                                               */

/******************************************************************************/

/* 17. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2986) This operation is redundant. The value of the     */
/*                 result is always that of the right-hand operand.           */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value of the local variable accessed changes with      */
/*                 configuration.                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2986)-17 and END Msg(4:2986)-17 tags  */
/*                 in the code.                                               */

/******************************************************************************/

/* 18. MISRA C RULE VIOLATION:                                                */
/* Message       : Msg(4:0715)Nesting of control structures (statements)      */
/*                 exceeds 15 - program is non-conforming.                    */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : It is used to achieve better throughput instead of         */
/*                 invoking a function call.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0715)-18 and END Msg(4:0715)-18 tags  */
/*                 in the code.                                               */
/******************************************************************************/

/* 19. QAC Warning:                                                           */
/* Message       : (2:3416) Logical operation performed on expression         */
/*                        with possible side effects.                         */
/* Rule          : Not Applicable                                             */
/* Justification : Wait-loop which may be deleted by optimization,            */
/*                 The Variable used to Wait-loop shall be declared volatile. */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3416)-19 and             */
/*                 END Msg(2:3416)-19 tags in the code.                       */
/******************************************************************************/




/*******************************************************************************
**                  Function Prototypes                                       **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_InitConfig
                                                 (Port_GroupType LenGroupType);

#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_FilterConfig(void);
#endif

/* Implements AR_PN0062_FR_0043 */
#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || \
     (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON) || \
     (PORT_SET_PIN_MODE_API == STD_ON))
STATIC
FUNC (P2CONST (volatile Port_PinChangeableDetails,
        AUTOMATIC, PORT_CONFIG_CONST), PORT_PRIVATE_CODE)
        Port_SearchChangeablePinDetail(
        Port_PinType LddPinNumber, uint8* pPortRegIndex, uint8 LucModeCheck);
#endif

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                                                 (Port_GroupType LenGroupType);
/* Implements PORT_ESDD_UD_019 */
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
STATIC
FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode (Port_PinType Pin,
                                              boolean LblDioMode);
#endif

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
/*******************************************************************************
**                  Function Definitions                                      **
*******************************************************************************/
/* Implements PORT140, SWS_Port_00140 */
/* Implements PORT005, SWS_Port_00005 */
/* Implements PORT071, SWS_Port_00071 */
/*******************************************************************************
** Function Name         : Port_Init
**
** Service ID            : 0x00
**
** Description           : This service performs initialization of the PORT
**                         Driver components.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError, Port_InitConfig, Port_FilterConfig,
**                         Dem_ReportError.
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**
** Registers Used        : PROTCMD0, IOHOLD, PROTS0, PSRn, PISn, PISAn, PIBCn,
**                         PIPCn, PUn, PDn, PBDCn, PODCn, PDSCn, PFCEn, PFCn,
**                         PFCAEn, PMCSRn, PMSRn, PPROTSn, PPCMDn, JPSR0, JPIS0,
**                         JPISA0, JPIBC0, JPU0, JPD0, JPBDC0, JPODC0, JPDSC0,
**                         JPFCE0, JPFC0, JPMCSR0, JPMSR0, JPPCMD0, JPPROTS0,
**                         APSRn, APIBCn, APBDCn, APMSRn, IPIBC0, DNFAnCTL,
**                         DNFAnEN, FCLA0CTLm.
*******************************************************************************/
/* Implements PORT131, PORT_ESDD_UD_072 */
/* Implements SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

/* Implements PORT001, SWS_Port_00001 */
/* Implements PORT_ESDD_UD_122 */
/* Initialize the Port Driver module */
/* Implements EAAR_PN0034_FR_0063 */
/* Implements PORT041, PORT078, PORT042, PORT213, PORT003, PORT002, PORT055 */
/* Implements SWS_Port_00041, SWS_Port_00078, SWS_Port_00042, SWS_Port_00213 */
/* Implements SWS_Port_00003, AR_PN0062_FR_0028, EAAR_PN0034_FR_0025 */
/* Implements PORT_ESDD_UD_072, PORT_ESDD_UD_013, PORT_ESDD_UD_018 */
/* Implements PORT_ESDD_UD_020, AR_PN0062_FR_0060, SWS_Port_00001 */
/* Implements PORT138, SWS_Port_00138, SWS_Port_00002, SWS_Port_00003 */
/* Implements SWS_Port_00055 */
FUNC (void, PORT_PUBLIC_CODE) Port_Init
(P2CONST (Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr)
{
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) ||\
        (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) ||\
          (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON) ||\
            (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
  /* Invoking Port_InitConfig() API with Analog Port Group data */
  Std_ReturnType LddReturnValue;
  #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
  #if (PORT_IOHOLD_FUNC_AVAILABLE == STD_ON)
  volatile uint8 LucLoopCount;
  #endif /* (PORT_IOHOLD_FUNC_AVAILABLE == STD_ON) */
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) ||\
        (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) ||\
          (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON) ||\
            (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
  /* Invoking Port_InitConfig() API with Analog Port Group data */  
  /*
  * Initialize the return value
  */
  /* MISRA Violation: START Msg(4:2982)-14 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-14 */
  #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

  /* Report to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /*
     * If DET is enabled, the API parameter checking shall be performed
     * according to the respective functions
     */
    /* Implements PORT051 */
    /* Implements SWS_Port_00051 */
    /* Implements PORT_ESDD_UD_014,PORT101 */
    /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
    /* Implements EAAR_PN0034_FR_0016 */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Implements PORT077, PORT105, PORT121 */
    /* Implements SWS_Port_00077, SWS_Port_00121 */
    /* Implements PORT087, PORT146 */
    /* Implements SWS_Port_00087, SWS_Port_00146 */
    /* Report to DET */
    /* Implements PORT_ESDD_UD_106 */
    #if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
      (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                          PORT_E_INIT_FAILED);
    #else
      (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                          PORT_E_PARAM_CONFIG);
    #endif /* End of PORT_AR_VERSION == PORT_AR_HIGHER_VERSION */

    #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  } /* End of ConfigPtr == NULL_PTR */
  else
  {
    /* MISRA Violation: START Msg(4:4397)-9 */
    if (PORT_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(4:4397)-9 */
    {
      /* Assign the config pointer value to global pointer */
      Port_GpConfigPtr = ConfigPtr;

    /* Check for available Port Group Type(Numeric Port) */
      /* Implements PORT_ESDD_UD_018 */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Numeric Port Group data */
      LddReturnValue = Port_InitConfig (PORT_GROUP_NUMERIC);
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      /* Implements PORT_ESDD_UD_020 */
      /* Check for available Port Group Type(JTag Port) */
      /* Implements AR_PN0062_FR_0023 */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with JTag Port Group data */
      if(E_OK == LddReturnValue){
        LddReturnValue = Port_InitConfig (PORT_GROUP_JTAG);
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Analog Port) */
      /* Implements PORT_ESDD_UD_021 */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Analog Port Group data */
      if(E_OK == LddReturnValue){
        LddReturnValue = Port_InitConfig (PORT_GROUP_ANALOG);
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Input Port) */
      /* Implements PORT_ESDD_UD_022 */
      #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Input Port Group data */
      if(E_OK == LddReturnValue){
        LddReturnValue = Port_InitConfig (PORT_GROUP_INPUT);
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
    
     #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) ||\
            (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) ||\
              (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON) ||\
                (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
      /* Invoking Port_InitConfig() API with Input Port Group data */
      if(E_OK == LddReturnValue){
      #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
      
      /* Implements EAAR_PN0062_FR_0033 */
      #if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
      /* Wait for Pulse Rejection time(100nsec) before Port Filter config.*/
      LucLoopCount = PORT_FILTER_DELAY_COUNT;
      do
      {
        LucLoopCount--;
      /* QAC Warning: START Msg(2:3416)-19 */
      } while (PORT_ZERO < LucLoopCount);
      /* END Msg(2:3416)-19 */
      
      /* Invoking Port_FilterConfig() for configuration of filter registers */
      /* Implements PORT043, AR_PN0062_FR_0032 */
      /* Implements SWS_Port_00043 */
      Port_FilterConfig ();
      #endif /*
              * End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
              * (PORT_FCLA_REG_CONFIG == STD_ON)
              */
      
      /*
       * If DET is enabled, the API parameter checking shall be performed
       * according to the respective functions
       */
      /* Implements PORT051 */
      /* Implements SWS_Port_00051 */
      /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
      /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Set the Port status to initialized */
      Port_GblDriverStatus = PORT_INITIALIZED;
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

      /* Implements AR_PN0062_FR_0029 */
      #if (PORT_IOHOLD_FUNC_AVAILABLE == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
        
      /*
       * An atomic access to Microcontroller registers by the use of an
       * exclusive area
       */

      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      
      if ((PORT_IOHOLD & PORT_IOHOLD_MASK) == PORT_IOHOLD_MASK)
      /* END Msg(4:0303)-2 */
        {
          /* Implements EAAR_PN0034_FSR_0011 */
          /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
          /* Implements PORT_ESDD_UD_140 */
          /* Implements EAAR_PN0034_FR_0084, EAAR_PN0034_FR_0085 */
          /* Implements EAAR_PN0034_FR_0086, EAAR_PN0034_NR_0062 */
          LucLoopCount = PORT_UNLOCK_SEQUENCE_COUNT;
          /* MISRA Violation: START Msg(4:0303)-2 */
          do
          {
            /* Write the write enable register */
            /* Implements PORT_ESDD_UD_124 */
            PORT_WRITE_REG_ONLY (&PORT_PROTCMD0, PORT_WRITE_ERROR_CLEAR_VAL)
            /* Mask the IOHOLD bit */
            PORT_WRITE_REG_ONLY (&PORT_IOHOLD, PORT_IOHOLD_CLEAR)
            PORT_WRITE_REG_ONLY (&PORT_IOHOLD, ~PORT_IOHOLD_CLEAR)
            PORT_WRITE_REG_ONLY (&PORT_IOHOLD, PORT_IOHOLD_CLEAR)
            LucLoopCount--;
           /* QAC Warning: START Msg(2:3416)-19 */  
          } while ((PORT_ZERO < LucLoopCount) &&
                                 (PORT_PROTECTED_ERR_OCCURRED == PORT_PROTS0));
          /* END Msg(2:3416)-19 */
          /* END Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          PORT_CHECK_WRITE_VERIFY_INIT (&PORT_IOHOLD, PORT_IOHOLD_CLEAR,
                                        PORT_IOHOLD_MASK, PORT_INIT_SID)
          /* END Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          if (PORT_PROTS0 == PORT_PROTECTED_ERR_OCCURRED)
          /* END Msg(4:0303)-2 */
          {
            /* Implements PORT037 */
            /* Implements SWS_BSW_00046 */
            /*
             * Writing to write-protected register failed and
             * report production error
             */
            /* Implements PORT146 */
            /* Implements SWS_Port_00146 */
            Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                  (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

          } /* End of PORT_PROTS0 == PORT_PROTECTED_ERR_OCCURRED */
          else
          {
            /* No action required */
          }

          /* Delay at least 3xEMCLK after returning from DeepSleep */
          /* Implements PORT_ESDD_UD_143 */
          LucLoopCount = PORT_IOHOLD_DELAY;
          do
          {
            LucLoopCount--;
          /* QAC Warning: START Msg(2:3416)-19 */
          } while (PORT_ZERO < LucLoopCount);
          /* END Msg(2:3416)-19 */
        }
        else
        {
          /* No action required */
        }
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
        #endif /* End of PORT_IOHOLD_FUNC_AVAILABLE == STD_ON */
        
        
        #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) ||\
              (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) ||\
                (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON) ||\
                  (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
        /* Invoking Port_InitConfig() API with Input Port Group data */
        }
        else
        {
         /* No action required */
        }
        #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
    }
    /*If there is no valid database is present */
    else
    {
      /*
       * If DET is enabled, the API parameter checking shall be performed
       * according to the respective functions
       */
       /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
       /* Implements PORT_ESDD_UD_014 */
       /* Implements EAAR_PN0034_FR_0016 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Implements PORT077, PORT146 */
      /* Implements SWS_Port_00077, SWS_Port_00146, AR_PN0062_FR_0008 */
      /* Report to DET */
      (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                             PORT_E_INVALID_DATABASE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  }
} /* End of API Port_Init */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/* Implements PORT141, SWS_Port_00141, PORT063, SWS_Port_00063 */
/* Implements PORT054, SWS_Port_00054, AR_PN0062_FR_0041 */
/* Implements PORT131_Conf, ECUC_Port_00131 */
/* Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049 */
/* Implements PORT125_Conf, PORT126_Conf, ECUC_Port_00125, ECUC_Port_00126 */
/* Implements PORT006, SWS_Port_00006, AR_PN0062_FR_0004 */
/*******************************************************************************
** Function Name         : Port_SetPinDirection
**
** Service ID            : 0x01
**
** Description           : This service sets the port pin direction during
**                         runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Direction - Port Pin Direction
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_Init().
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**                         Port_SearchChangeablePinDetail
**
** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, JPMSR0, APMSRn.
*******************************************************************************/
/* The function Port_SetPinDirection shall be available if the pre-compile
 * parameter PortSetPinDirectionApi is set to TRUE
 */
/* Implements PORT086 */
/* Implements SWS_Port_00086 */
/* Implements PORT_ESDD_UD_015*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/* Implements PORT131 */
/* Implements SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_073, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDirection
(Port_PinType Pin, Port_PinDirectionType Direction)
{
  P2CONST(volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                             LpChangeablePinDet;
  uint8 LucPortGroupIndex;
  uint8 LucPortType;
  uint8 LucPortRegIndex;
  uint16 LusPinPositionMask;

  uint32 LulSRRegContent;
  uint16 LusCurrentDirection;
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LddReturnValue;

  /* Initialize the return value */
  LddReturnValue = E_OK;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

  /* Initialize the pointer to null pointer */
  /* MISRA Violation: START Msg(4:2982)-14 */
  LpChangeablePinDet = NULL_PTR;
  /* END Msg(4:2982)-14 */
  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
   /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
   /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  /* Implements PORT087 */
  /* Implements SWS_Port_00087 */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Implements PORT087, PORT_ESDD_UD_029 */
    /* Implements SWS_Port_00087 */
    /* Check whether the requested PIN number is invalid */
    if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                             PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN);
      /* Set Return Value as E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  if (E_OK == LddReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchChangeablePinDetail (Pin,
                           &LucPortRegIndex, PORT_PIN_DIR_CHANGABLE);

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR != LpChangeablePinDet)
    {
      LucPortGroupIndex = LpChangeablePinDet->ucPortGroupIndex;
      LucPortType = LpChangeablePinDet->ucPortType;

      LusPinPositionMask = LpChangeablePinDet->usPinPositionMask;
      /* Get the base address of the corresponding Port Type */
      /* Implements PORT_ESDD_UD_018 */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_NUMERIC == (LucPortType & PORT_PG_TYPE_MASK))
      {
        /*
         * An atomic access to Microcontroller registers by the use of an
         * exclusive area
         */
        /* Implements EAAR_PN0034_FR_0030 */
        /* Implements PORT_ESDD_UD_023 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        /*
         * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
         * variable to 1 of the configured pin whose Direction has to be changed
         */
        LulSRRegContent = ((uint32)LusPinPositionMask) <<
                          PORT_BIT_SHIFT_SIXTEEN;
        /* Check if requested direction is OUTPUT and */
        /* current direction is INPUT. */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* MISRA Violation: START Msg(4:0306)-3 */
        LusCurrentDirection = (uint16)
           (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR);
        /* END Msg(4:0306)-3 */
        /* END Msg(4:2962)-5 */
        /* Check if requested direction is OUTPUT */
        if ((PORT_PIN_OUT == Direction) &&
            ((LusCurrentDirection & LusPinPositionMask) ==
             LusPinPositionMask))
        {
          /* AUTOSAR IMPL PORT082 / SWS_Port_00082 RULE VIOLATION: As per
           * requirement AR_PN0062_FR_0048 Level inversion is implemented to
           * invert the output level of a pin when the pin is in output mode
           */

          /* Implements PORT138 */
          /* Implements SWS_Port_00138 */
          /* Write the Lower word contents with configured Pin Level Value */
          LulSRRegContent = LulSRRegContent |
                            LpChangeablePinDet->usChangeableConfigVal;
          /* Write the configured value into the register */
          PORT_WRITE_REG_ONLY (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPSR,
            (LulSRRegContent & (LusPinPositionMask)),
            (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)
          /* Set the requested direction */
          LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                              (uint16)(~LusPinPositionMask);
          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
           * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
           * value for the corresponding pin position
           */
          PORT_WRITE_REG_ONLY (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            (&Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR),
            (PORT_LONG_ZERO),
            ((uint32)LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)
      } /* End of Direction == PORT_PIN_OUT */
      else if (PORT_PIN_IN == Direction)
      {
        /* MISRA Violation: START Msg(4:2985)-16 */
        /* Requested direction is INPUT */
        LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                                                  (uint32)(LusPinPositionMask);
        /* END Msg(4:2985)-16 */
        /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
         * Bit value of Lower 16 bits (15-0) of PMSR register = Configured value
         * for the corresponding pin position
         */
        PORT_WRITE_REG_ONLY (
          &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
          LulSRRegContent)
        PORT_CHECK_WRITE_VERIFY_RUNTIME (
          &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
          (LusPinPositionMask),
          (LusPinPositionMask),
          PORT_SET_PIN_DIR_SID)
      }
      else
      {
          /* No action required */
      }
      /* Exit critical section */
      /* Implements EAAR_PN0034_FR_0030 */
      /* Implements PORT_ESDD_UD_023 */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      /* Implements PORT_ESDD_UD_020 */
      /* Implements AR_PN0062_FR_0023 */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)(PORT_GROUP_JTAG) == (LucPortType &
                                        PORT_PG_TYPE_MASK))
      {
        /*
         * An atomic access to Microcontroller registers by the use of an
         * exclusive area
         */

        /* Implements PORT075 */
        /* Implements SWS_Port_00075 */
        /* Implements EAAR_PN0034_FR_0030 */
        /* Implements PORT_ESDD_UD_023 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        /*
         * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
         * variable to 1 of the configured pin whose Direction has to be changed
         */
        LulSRRegContent = (uint32)LusPinPositionMask
                          << PORT_BIT_SHIFT_SIXTEEN;
        /* Check if requested direction is OUTPUT and current direction is
        INPUT. */
        LusCurrentDirection = (uint16)(Port_GpJPortReg_BaseAddress->ulJPMSR);
        /* Check if requested direction is OUTPUT */
        if (( PORT_PIN_OUT == Direction) &&
          ((LusCurrentDirection & LusPinPositionMask) ==
          LusPinPositionMask))
        {
          /* Implements PORT138 */
          /* Implements SWS_Port_00138 */
          /* Write the Lower word contents with configured Pin Level Value */
          LulSRRegContent = LulSRRegContent |
                            LpChangeablePinDet->usChangeableConfigVal;
          /* Write the configured value into the register */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPSR,
                                                               LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GpJPortReg_BaseAddress->ulJPSR,
            (LulSRRegContent & (LusPinPositionMask)),
            (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)

          /* Set the requested direction */
          LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                            ((uint16)(~LusPinPositionMask));
          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
           * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
           * value for the corresponding pin position
           */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
                                                               LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GpJPortReg_BaseAddress->ulJPMSR,
            PORT_LONG_ZERO, (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)
        } /* End of Direction == PORT_PIN_OUT */
        else if (PORT_PIN_IN == Direction)
        {
          /* Requested direction is INPUT */
          /* MISRA Violation: START Msg(4:2985)-16 */
          LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                            (uint32)(LusPinPositionMask);
          /* END Msg(4:2985)-16 */
          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
           * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
           * value for the corresponding pin position
           */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
                                                               LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GpJPortReg_BaseAddress->ulJPMSR,
            (LusPinPositionMask),
            (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)
        }
        else
        {
            /* No action required */
        }
        /* Implements EAAR_PN0034_FR_0030 */
        /* Implements PORT_ESDD_UD_023 */
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
      /* Implements PORT_ESDD_UD_021 */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (((uint8)PORT_GROUP_ANALOG) == (LucPortType &
                                      PORT_PG_TYPE_MASK))
      {
        /*
        * An atomic access to Microcontroller registers by the use of an
        * exclusive area
        */
        /* Implements EAAR_PN0034_FR_0030 */
        /* Implements PORT_ESDD_UD_023 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        /*
        * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
        * variable to 1 of the configured pin whose Direction has to be changed
        */
        LulSRRegContent = ((uint32)LusPinPositionMask) <<
                          PORT_BIT_SHIFT_SIXTEEN;
        /* Check if requested direction is OUTPUT and */
        /* current direction is INPUT. */
        LusCurrentDirection = (uint16)
         (Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR);
        /* Check if requested direction is OUTPUT */
        if ((PORT_PIN_OUT == Direction) &&
            ((LusCurrentDirection & LusPinPositionMask) ==
             LusPinPositionMask))
        {

          /* Implements PORT138 */
          /* Implements SWS_Port_00138 */
          /* Write the Lower word contents with configured Pin Level Value */
          LulSRRegContent = LulSRRegContent |
          LpChangeablePinDet->usChangeableConfigVal;
          /* Write the configured value into the register */
          PORT_WRITE_REG_ONLY (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPSR,
            (LulSRRegContent & LusPinPositionMask),
            (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)

          /* Set the requested direction */
          LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                            (uint16)(~LusPinPositionMask);
          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
          * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
          * value for the corresponding pin position
          */
          PORT_WRITE_REG_ONLY (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
            PORT_LONG_ZERO,
            (LusPinPositionMask),
            PORT_SET_PIN_DIR_SID)
        } /* End of Direction == PORT_PIN_OUT */
        else if (PORT_PIN_IN == Direction)
        {
          /* MISRA Violation: START Msg(4:2985)-16 */
          /* Requested direction is INPUT */
          LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                                                  (uint32)(LusPinPositionMask);
          /* END Msg(4:2985)-16 */
          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
          * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
          * value for the corresponding pin position
          */
          PORT_WRITE_REG_ONLY (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
            LulSRRegContent)
          /* MISRA Violation: START Msg(4:2986)-17 */
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
            (LulSRRegContent & LusPinPositionMask),
            (LusPinPositionMask), PORT_SET_PIN_DIR_SID)
          /* END Msg(4:2986)-17 */
        }
        else
        {
          /* No action required */
        }
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
    }/*End of NULL_PTR != LpChangeablePinDet*/
    else
    {
      /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
      /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Implements PORT051, PORT087, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00087, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                  PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  } /* End of E_OK == LddReturnValue */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetPinDirection */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/* Implements PORT142 */
/* Implements SWS_Port_00142, EAAR_PN0034_NR_0015 */
/*******************************************************************************
** Function Name         : Port_RefreshPortDirection
**
** Service ID            : 0x02
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
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
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, Port_RefreshPortInternal.
**
** Registers Used        : PMSRn, JPMSR0, APMSRn.
*******************************************************************************/
/* Implements PORT131, SWS_Port_00131, PORT066, SWS_Port_00066 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

/* Implements PORT060 */
/* Implements SWS_Port_00060 */
/* Implements PORT_ESDD_UD_074, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
FUNC (void, PORT_PUBLIC_CODE) Port_RefreshPortDirection (void)
{
  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
   /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
   /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  /* Implements PORT087 */
  /* Implements SWS_Port_00087 */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET  */
    (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
               PORT_REFRESH_PORT_DIR_SID, PORT_E_UNINIT);
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Implements PORT_ESDD_UD_018 */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Numeric Group data */
      Port_RefreshPortInternal (PORT_GROUP_NUMERIC);
    }
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    /* Implements PORT_ESDD_UD_020 */
    /* Implements AR_PN0062_FR_0023 */
    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with JTag Group data */
      Port_RefreshPortInternal (PORT_GROUP_JTAG);
    }
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
    /* Implements PORT_ESDD_UD_021 */
    #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Analog Group data */
      Port_RefreshPortInternal (PORT_GROUP_ANALOG);
    }
    #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
  }
} /* End of API Port_RefreshPortDirection */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/* Implements PORT145 */
/* Implements SWS_Port_00145, AR_PN0062_FR_0041 */
/* Implements AR_PN0062_FR_0010, AR_PN0062_FR_0064 */
/* Implements PORT132_Conf, PORT134_Conf, ECUC_Port_00132, ECUC_Port_00134 */
/* Implements AR_PN0062_FR_0002, AR_PN0062_FR_0013, AR_PN0062_FR_0036 */
/*******************************************************************************
** Function Name         : Port_SetPinMode
**
** Service ID            : 0x04
**
** Description           : This function used to set the mode of a port pin
**                         during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Mode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : PSRn, JPSR0, APSRn, PMSRn, JPMSR0, APMSRn, PFCEn,
**                         JPFCE0, PFCn, JPFC0, PFCAEn, PMCSRn, JPMCSR0, PIPCn.
*******************************************************************************/
/* Implements PORT_ESDD_UD_016 */
#if (PORT_SET_PIN_MODE_API == STD_ON)

/* Implements PORT131, AR_PN0062_FR_0009, PORT125, SWS_Port_00125 */
/* Implements PORT128, SWS_Port_00128, SWS_Port_00223 */
/* Implements SWS_Port_00131, AR_PN0062_FR_0045 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

/* Implements PORT124, AR_PN0062_FR_0039, SWS_Port_00231 */
/* Implements PORT212, SWS_Port_00212 */
/* Implements SWS_Port_00124 */
/* Implements PORT_ESDD_UD_076, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
/* The type Port_PinModeType used with the function call Port_SetPinMode */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
     (Port_PinType Pin, Port_PinModeType Mode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;
  uint32 LulSRRegContent;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint16 LusSRRegContentTemp;
  #endif
  /* Implements PORT_ESDD_UD_020 */
  /* Implements AR_PN0062_FR_0023 */
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  uint8 LucSRRegContentTemp;
  #endif
  uint8 LucPortRegIndex;
  uint16 LusPinPositionMask;
  /* Variable for revised mode */
  Port_PinModeType LddMode;

  uint8 LucPortGroupIndex;
  uint16 LusCurrentDirection;
/* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
/* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LddReturnValue;

  /* Initialize the return value */
  LddReturnValue = E_OK;
  #endif

  /* Initialize the pointer to Null pointer */
  /* MISRA Violation: START Msg(4:2982)-14 */
  LpModeChangeablePin = NULL_PTR;
  /* END Msg(4:2982)-14 */
  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
   /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
   /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  /* Implements PORT087 */
  /* Implements SWS_Port_00087 */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* Implements PORT087 */
    /* Implements SWS_Port_00087 */
    /* Check whether the requested PIN number is invalid */
    if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                             PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
      /* Set Return Value as E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
    else
    {
      /* No action required */
    }

    /* Implements PORT087, PORT_ESDD_UD_121 */
    /* Implements SWS_Port_00087 */
    /* Check whether the requested mode is invalid
       In case of PortIpControl ON user will pass mode value ORed with 0x80,
       so this is to be masked while checking against the max mode */
    if(((PORT_SET_PIPC_MAX_MODE) < Mode) || (((PORT_MAX_MODE) < Mode) &&
    (Mode < (PORT_SET_PIPC_MIN_MODE))))
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
      /* Set Return Value as E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    } /* End of (Mode > PORT_MAX_MODE) */
    else
    {
      /* No action required */
    }
  }

  if (E_OK == LddReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchChangeablePinDetail (Pin,
                          &LucPortRegIndex, PORT_PIN_MODE_CHANGABLE);
    /* Implements PORT087, PORT223 */
    /* Implements SWS_Port_00087, SWS_Port_00223 */
    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpModeChangeablePin)
    {
     /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
     /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    } /* End of LpModeChangeablePin == NULL_PTR */
    else
    {
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      if ((PORT_DIO_IN < Mode) &&
               ((uint8)PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType &
               PORT_PG_TYPE_MASK)))
      {
        /*
         * If the PORT is Analog Port, Mode can be PORT_DIO_OUT or PORT_DIO_IN
         */
        /* Implements PORT051, PORT146 */
        /* Implements SWS_Port_00051, SWS_Port_00146 */
        /* Report to DET */
        (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                      PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
        /* Set Return Value as E_NOT_OK */
        LddReturnValue = E_NOT_OK;
      }/*
        * End of ((PORT_DIO_IN < Mode) &&
        * ((uint8)PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType &
        * PORT_PG_TYPE_MASK)))
        */
      else
      {
        /* No action required */
      }

      if (E_OK == LddReturnValue)
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
      {
        LucPortGroupIndex = LpModeChangeablePin->ucPortGroupIndex;
        LusPinPositionMask = LpModeChangeablePin->usPinPositionMask;
        /*
         * If the Pin group is of Numeric type
         */
        /* Implements PORT_ESDD_UD_018 */
        #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_NUMERIC == (LpModeChangeablePin->ucPortType &
                   PORT_PG_TYPE_MASK))
        {
          /*
           * Write PIPC register.Check for register availability
           */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PIPC_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
           PORT_PIPC_AVAILABLE))
          /* END Msg(4:0491)-10 */
          {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            if (PORT_SET_PIPC_MIN_MODE <= Mode)
            {
              /*
               * If bit needs to be set, OR the register contents
               * with usPinPositionMask
               */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC |
                (uint16)(LusPinPositionMask));
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPIPC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
              Mode = Mode & PORT_MODE_MASK;
            }
            else
            {
              /*
               * If bit needs to be reset, AND  with inverted usPinPositionMask
               */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC &
                (uint16)(~LusPinPositionMask));
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPIPC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
                PORT_WORD_ZERO,
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
          }
          else
          {
            /* No action required */
          }

          /*
           * Check if the value of Mode passed is greater than 1
           */
          if (PORT_DIO_IN < Mode)
          {
            /*
             * Value of Mode passed is greater than 1. Hence add 14 to the value
             */
            LddMode = Mode + PORT_MODE_ADJUST;
          }
          else
          {
            /*
             * Keep the same value of Mode
             */
            LddMode = Mode;
          }

          /*
           * Set the bit position in the upper 16 bits (31-16) of the PSR or
           * PMSR variable to 1 of the configured pin whose Mode has to be
           * changed
           */
          LulSRRegContent = ((uint32)LusPinPositionMask) <<
                            PORT_BIT_SHIFT_SIXTEEN;

          /*
           * An atomic access to Microcontroller registers by the use of an
           * exclusive area
           */
          /* Implements PORT075 */
          /* Implements SWS_Port_00075 */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
         
          LusCurrentDirection =
           (((uint16)(Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR)) &
           LusPinPositionMask);

          if((PORT_MODE_DIO == Mode) && (PORT_MODE_DIO != LusCurrentDirection))
          {
            /* Write PSR register.Check for PSR register availability */
            /* Write Initial mode register value into Lower word of PSR  */
            /* variable */
            /* MISRA Violation: START Msg(4:0491)-10 */
            LulSRRegContent = LulSRRegContent |
            Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulInitModePSRRegVal;
            /* END Msg(4:0491)-10 */
            /* Get the PSR register */
            /*
            * Bit value of Upper 16 bits (31-16) of PSR register is to set 1
            * Bit value of Lower 16 bits (15-0) of PSR register = Initial value
            * for the corresponding pin position
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPSR,
              (LulSRRegContent & (uint32)LusPinPositionMask),
              ((uint32)LusPinPositionMask),
              PORT_SET_PIN_MODE_SID)
          } /* LpSetPinModeGroupStruct->ucPSRRegIndex != PORT_REG_NOTAVAILABLE*/
          else
          {
            /* No action required */
          }
          /* Implements EAAR_PN0034_FR_0030 */
          /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
         
          /* Check whether the corresponding bit is to set or reset. */
          if (PORT_ZERO == (LddMode & PORT_BIT0_MASK))
          {
            /* Write the requested direction into Lower word of PMSR variable
            * by using inverse of OR mask
            */
            LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
              ((uint16)(~LusPinPositionMask));
          } /* End of (Mode & PORT_BIT0_MASK) == PORT_ZERO */
          else
          {
            /* Write the requested direction into Lower word of PMSR variable
            * by using OR mask
            */
            /* MISRA Violation: START Msg(4:2985)-16 */
            LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
              ((uint16)(LusPinPositionMask));
            /* END Msg(4:2985)-16 */
          }
          /*
           * An atomic access to Microcontroller registers by the use of an
           * exclusive area
           */
          /* Implements PORT075 */
          /* Implements SWS_Port_00075 */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
          * Write the contents of Lower word and Upper word of PMSR variable
          * into the PMSR register address
          */
          PORT_WRITE_REG_ONLY (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
            (LulSRRegContent & (uint32)LusPinPositionMask),
            (LusPinPositionMask),
            PORT_SET_PIN_MODE_SID)
          /* Implements EAAR_PN0034_FR_0030 */
          /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
          * Write PFCE register.Check for register availability
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFCE_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
           PORT_PFCE_AVAILABLE))
          /* END Msg(4:0491)-10 */
          {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Check whether the corresponding bit is to set or reset.
            */
            if (PORT_ZERO == (LddMode & PORT_BIT2_MASK))
            {
              /*
              * If bit needs to reset, AND the register contents with
              * Inverse of usPinPositionMask
              */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE) &
                (uint16)(~LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
                PORT_WORD_ZERO,
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            else
            {
              /*
              * If bit needs to be set, OR the register contents with
              * usPinPositionMask
              */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE) |
                ((uint16)(LusPinPositionMask));
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of Write PFCE register */
          else
          {
            /* No action required */
          }

          /*
          * Write PFC register.Check for register availability
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFC_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
           PORT_PFC_AVAILABLE))
          /* END Msg(4:0491)-10 */
          {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Check whether the corresponding bit is to set or reset.
            */
            if (PORT_ZERO == (LddMode & PORT_BIT1_MASK))
            {
              /*
              * If bit needs to be reset, AND the register contents with
              * usPinPositionMask
              */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC) &
                (uint16)(~LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
                PORT_WORD_ZERO, (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            } /* End of (Mode & PORT_BIT1_MASK) == PORT_ZERO */
            else
            {
              /*
              * If bit needs to be set, OR the register contents with
              * usPinPositionMask
              */
              LusSRRegContentTemp =
                (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC) |
                ((uint16)(LusPinPositionMask));
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of Write PFC register */
          else
          {
          /* No action required */
          }

          /*
          * Write PFCAE register.Check for register availability
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFCAE_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
           PORT_PFCAE_AVAILABLE))
          /* END Msg(4:0491)-10 */
          {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Check whether the corresponding bit is to set or reset.
            */
            if (PORT_ZERO == (LddMode & PORT_BIT3_MASK))
            {
              /*
              * If bit needs to be reset, AND the register contents with
              * usPinPositionMask
              */
              LusSRRegContentTemp =
                  (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE) &
                  (uint16)(~LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCAE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
                PORT_WORD_ZERO,
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            } /* End of (Mode & PORT_BIT3_MASK) == PORT_ZERO */
            else
            {
              /*
              * If bit needs to be set, OR the register contents with
              * usPinPositionMask
              */
              LusSRRegContentTemp =
                  (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE) |
                  (uint16)(LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
                LusSRRegContentTemp,
                &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCAE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of Write PFCAE register */
          else
          {
          /* No action required */
          }

          /*
          * Write PMCSR register. Check for register availability
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PMCSR_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
           PORT_PMCSR_AVAILABLE))
          /* END Msg(4:0491)-10 */
          {
            if (PORT_ZERO == (LddMode & PORT_BIT4_MASK))
            {
              /*
              * Write the requested direction into Lower word of PMCSR variable
              * by using inverse of OR mask
              */
              LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                (uint16)(~LusPinPositionMask);
            } /* End of (Mode & PORT_BIT4_MASK) == PORT_ZERO */
            else
            {
              /*
              * Write the requested direction into Lower word of PMCSR variable
              * by using OR mask
              */
              LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                LusPinPositionMask;
            }
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /* Write the corresponding 32 bit value to the PMCSR register */
            PORT_WRITE_REG_ONLY (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
              (LulSRRegContent & ((uint32)LusPinPositionMask)),
              ((uint32)LusPinPositionMask),
              PORT_SET_PIN_MODE_SID)
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of Write PMCSR register */
          else
          {
            /* No action required */
          }
        } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
        else
        #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* Implements PORT_ESDD_UD_020 */
          #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_JTAG == (LpModeChangeablePin->ucPortType &
            PORT_PG_TYPE_MASK))
          {
            /*
            * Check if the value of Mode passed is greater than 1
            */
            if (PORT_DIO_IN < Mode)
            {
              /*
              * Value of Mode passed is greater than 1. Hence add 14
              * to the value
              */
              LddMode = Mode + PORT_MODE_ADJUST;
            }
            else
            {
              /*
              * Keep the same value of Mode
              */
              LddMode = Mode;
            }

            /*
            * Set the bit position in the upper 16 bits (31-16) of the PSR
            * or PMSR variable to 1 of the configured pin whose Mode has to be
            * changed
            */
            LulSRRegContent = ((uint32)LusPinPositionMask) <<
              PORT_BIT_SHIFT_SIXTEEN;

            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

            LusCurrentDirection =
                         (((uint16)(Port_GpJPortReg_BaseAddress->ulJPMSR)) &
                                                            LusPinPositionMask);

            if((PORT_MODE_DIO == Mode) &&
                                        (PORT_MODE_DIO != LusCurrentDirection))
            {
              /*
              * Write Initial mode register value into Lower word of
              * PSR variable
              */
              /* MISRA Violation: START Msg(4:0491)-10 */
              LulSRRegContent = LulSRRegContent |
              Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].
                                                          ulInitModeJPSRRegVal;
              /* END Msg(4:0491)-10 */

              /*
              * Bit value of Upper 16 bits (31-16) of PSR register is to set 1
              * Bit value of Lower 16 bits (15-0) of PSR register = Initial
              * value for the corresponding pin position
              */
              PORT_WRITE_REG_ONLY (
                &Port_GpJPortReg_BaseAddress->ulJPSR,
                LulSRRegContent)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GpJPortReg_BaseAddress->ulJPSR,
                (LulSRRegContent &
                  ((uint32)LusPinPositionMask)),
                ((uint32)LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            } /* LpSetPinModeGroupStruct->ucPSRRegIndex != */
            /* PORT_REG_NOTAVAILABLE */
            else
            {
              /* No action required */
            }
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * Write PMSR register.Check for PMSR register availability
            */
            /* Check whether the corresponding bit is to set or reset. */
            if (PORT_ZERO == (LddMode & PORT_BIT0_MASK))
            {
              /*
              * Write the requested direction into Lower word of PMSR variable
              * by using inverse of OR mask
              */
              LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                ((uint16)(~LusPinPositionMask));
            } /* End of (Mode & PORT_BIT0_MASK) == PORT_ZERO */
            else
            {
              /*
              * Write the requested direction into Lower word of PMSR variable
              * by using OR mask
              */
              /* MISRA Violation: START Msg(4:2985)-16 */
              LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                LusPinPositionMask;
              /* END Msg(4:2985)-16 */
            }
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Write the contents of Lower word and Upper word of PMSR variable
            * into the PMSR register address
            */
            PORT_WRITE_REG_ONLY (
              &Port_GpJPortReg_BaseAddress->ulJPMSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GpJPortReg_BaseAddress->ulJPMSR,
              (LulSRRegContent & ((uint32)LusPinPositionMask)),
              ((uint32)LusPinPositionMask),
              PORT_SET_PIN_MODE_SID)
            
            /* Check whether the corresponding bit is to set or reset. */
            if (PORT_ZERO == (LddMode & PORT_BIT2_MASK))
            {
              /*
              * If bit needs to reset, AND the register contents with
              * Inverse of usPinPositionMask
              */
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GpJPortReg_BaseAddress->ucJPFCE,
                ((Port_GpJPortReg_BaseAddress->ucJPFCE) &
                  (uint8)(~LusPinPositionMask)),
                &Port_GstRamMirrorJPortReg.ucJPFCE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GpJPortReg_BaseAddress->ucJPFCE,
                PORT_RESET_REG_VALUE,
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            else
            {
              /*
              * If bit needs to be set, OR the register contents with
              * usPinPositionMask
              */
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GpJPortReg_BaseAddress->ucJPFCE,
                ((Port_GpJPortReg_BaseAddress->ucJPFCE) |
                (uint8)(LusPinPositionMask)),
                &Port_GstRamMirrorJPortReg.ucJPFCE)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GpJPortReg_BaseAddress->ucJPFCE,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }

            /*
            * Check whether the corresponding bit is to set or reset.
            */
            if (PORT_ZERO == (LddMode & PORT_BIT1_MASK))
            {
              /*
              * If bit needs to be reset, AND the register contents with
              * usPinPositionMask
              */
              LucSRRegContentTemp =
                  (Port_GpJPortReg_BaseAddress->ucJPFC) &
                  (uint8)(~LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GpJPortReg_BaseAddress->ucJPFC,
                LucSRRegContentTemp,
                &Port_GstRamMirrorJPortReg.ucJPFC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GpJPortReg_BaseAddress->ucJPFC,
                PORT_RESET_REG_VALUE, (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            } /* End of (Mode & PORT_BIT1_MASK) == PORT_ZERO */
            else
            {
              /*
              * If bit needs to be set, OR the register contents with
              * usPinPositionMask
              */
              LucSRRegContentTemp =
                  (Port_GpJPortReg_BaseAddress->ucJPFC) |
                  (uint8)(LusPinPositionMask);
              PORT_WRITE_REG_AND_MIRROR (
                &Port_GpJPortReg_BaseAddress->ucJPFC,
                LucSRRegContentTemp,
                &Port_GstRamMirrorJPortReg.ucJPFC)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
                &Port_GpJPortReg_BaseAddress->ucJPFC,
                (LusPinPositionMask),
                (LusPinPositionMask),
                PORT_SET_PIN_MODE_SID)
            }
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            if (PORT_ZERO == (LddMode & PORT_BIT4_MASK))
            {
              /*
              * Write the requested direction into Lower word of PMCSR variable
              * by using inverse of OR mask
              */
              LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                ((uint16)~LusPinPositionMask);
            } /* End of (Mode & PORT_BIT4_MASK) == PORT_ZERO */
            else
            {
              /*
              * Write the requested direction into Lower word of PMCSR variable
              * by using OR mask
              */
              LulSRRegContent= (LulSRRegContent & PORT_MSB_MASK) |
                LusPinPositionMask;
            }
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements PORT075 */
            /* Implements SWS_Port_00075 */
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Write the corresponding 32 bit value to the PMCSR register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GpJPortReg_BaseAddress->ulJPMCSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GpJPortReg_BaseAddress->ulJPMCSR,
              (LulSRRegContent & ((uint32)LusPinPositionMask)),
              ((uint32)LusPinPositionMask),
              PORT_SET_PIN_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG */
          else
          #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
          {
            /* Implements PORT_ESDD_UD_021 */
            #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
            if ((uint8)PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType &
            PORT_PG_TYPE_MASK))
            {
              /*
              * Check if the value of Mode passed is greater than 1
              */
              if (PORT_DIO_IN < Mode)
              {
                /*
                * Value of Mode passed is greater than 1. Hence add 14 to the
                * value
                */
                LddMode = Mode + PORT_MODE_ADJUST;
              }
              else
              {
                /* Keep the same value of Mode */
                LddMode = Mode;
              }

              /*
              * Set the bit position in the upper 16 bits (31-16) of the PSR or
              * PMSR variable to 1 of the configured pin whose Mode has to be
              * changed
              */
              LulSRRegContent = ((uint32)LusPinPositionMask)
                << PORT_BIT_SHIFT_SIXTEEN;

              /*
              * An atomic access to Microcontroller registers by
              * the use of an exclusive area
              */
              /* Implements PORT075 */
              /* Implements SWS_Port_00075 */
              /* Implements EAAR_PN0034_FR_0030 */
              /* Implements PORT_ESDD_UD_023 */
              /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
              /* Enter critical section */
              #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
              PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
              #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

              LusCurrentDirection =
              (((uint16)
              (Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR)) &
                                                           LusPinPositionMask);

              if((PORT_MODE_DIO == Mode) &&
                                        (PORT_MODE_DIO != LusCurrentDirection))
              {
                /*
                * Write Initial mode register value into Lower word of
                * PSR variable
                */
                /* MISRA Violation: START Msg(4:0491)-10 */
                LulSRRegContent = LulSRRegContent |
                  (Port_GpConfigPtr->pPortAnalogRegs[LucPortRegIndex].
                  ulInitModeAPMSRRegVal);
                /* END Msg(4:0491)-10 */

                /* Get the PSR register */
                /*
                * Bit value of Upper 16 bits (31-16) of PSR register is to
                * set 1
                * Bit value of Lower 16 bits (15-0) of PSR register =
                * Initial value
                * for the corresponding pin position
                */
                PORT_WRITE_REG_ONLY (
                  &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPSR,
                  LulSRRegContent)
                /* MISRA Violation: START Msg(4:0715)-18 */
                PORT_CHECK_WRITE_VERIFY_RUNTIME (
                  &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPSR,
                  (LulSRRegContent &
                    ((uint32)LusPinPositionMask)),
                  ((uint32)LusPinPositionMask),
                  PORT_SET_PIN_MODE_SID)
                /* END Msg(4:0715)-18 */
              }
               /* Implements PORT_ESDD_UD_023 */
               /* Implements EAAR_PN0034_FR_0030 */
               /* Exit critical section */
              #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
              PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
              #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
             
              /* Check whether the corresponding bit is to set or reset. */
              if (PORT_ZERO == (LddMode & PORT_BIT0_MASK))
              {
                /*
                * Write the requested direction into Lower word of PMSR variable
                * by using inverse of OR mask
                */
                LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                  ((uint16)(~LusPinPositionMask));
              } /* End of (Mode & PORT_BIT0_MASK) == PORT_ZERO */
              else
              {
                /*
                * Write the requested direction into Lower word of PMSR variable
                * by using OR mask
                */
                /* MISRA Violation: START Msg(4:2985)-16 */
                LulSRRegContent = (LulSRRegContent & PORT_MSB_MASK) |
                  LusPinPositionMask;
                /* END Msg(4:2985)-16 */
              }
             
              /*
              * An atomic access to Microcontroller registers by
              * the use of an exclusive area
              */
              /* Implements PORT075 */
              /* Implements SWS_Port_00075 */
              /* Implements EAAR_PN0034_FR_0030 */
              /* Implements PORT_ESDD_UD_023 */
              /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
              /* Enter critical section */
              #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
              PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
              #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
                
              /*
              * Write the contents of Lower word and Upper word of PMSR variable
              * into the PMSR register address
              */
              PORT_WRITE_REG_ONLY (
                &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
                LulSRRegContent)
              PORT_CHECK_WRITE_VERIFY_RUNTIME (
               &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
               (LulSRRegContent & ((uint32)LusPinPositionMask)),
               ((uint32)LusPinPositionMask),
               PORT_SET_PIN_MODE_SID)
               /* Implements PORT_ESDD_UD_023 */
               /* Implements EAAR_PN0034_FR_0030 */
               /* Exit critical section */
              #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
              PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
              #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            } /* PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType &
            PORT_PG_TYPE_MASK */
            else
            {
              /* No action required */
            }
            #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
          }
        }
      } /* End of E_OK == LddReturnValue */
      /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
      /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  } /* End of E_OK == LddReturnValue */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
  /* No action required */
  }
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
} /* End of API Port_SetPinMode */
/* MISRA Violation: START Msg(6:0857)-13 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
/* END Msg(6:0857)-13 */
#include PORT_MEMMAP_FILE
#endif /* PORT_SET_PIN_MODE_API == STD_ON */

/* Implements AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name         : Port_SetToDioMode
**
** Service ID            : 0x05
**
** Description           : This function used to set the mode of a port pin
**                         to DIO mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : PMCSRn, PIPCn, JPMCSR0
*******************************************************************************/
/* Implements PORT_ESDD_UD_019 */
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* Implements PORT131, AR_PN0062_FR_0068 */
/* Implements SWS_Port_00131, AR_PN0062_FR_0038 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements AR_PN0062_FR_0002 */
/* Implements PORT_ESDD_UD_115 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin)
{
/* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LddReturnValue;

  /* Initialize the return value */
  LddReturnValue = E_OK;

  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                          PORT_SET_TO_DIO_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                          PORT_SET_TO_DIO_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LddReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the internal function to set the requested pin to DIO mode */
    Port_SetToDioOrAltMode(Pin, PORT_TRUE);
  }
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToDioMode */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/* Implements AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name         : Port_SetToAlternateMode
**
** Service ID            : 0x06
**
** Description           : This function used to set the mode of a port pin
**                         to alternate mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : PMCSRn, PIPCn, JPMCSR0.
*******************************************************************************/
/* Implements PORT_ESDD_UD_019 */
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* Implements PORT131, AR_PN0062_FR_0067 */
/* Implements SWS_Port_00131, AR_PN0062_FR_0039 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_116 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin)
{
  /*
   * If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions
   */
   /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
   /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LddReturnValue;

  /* Initialize the return value */
  LddReturnValue = E_OK;

  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_TO_ALT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                          PORT_SET_TO_ALT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LddReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Invoke the internal function to set the requested pin to alternate
     * mode.
     */
    Port_SetToDioOrAltMode (Pin, PORT_FALSE);
  }
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToAlternateMode */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/* Implements AR_PN0062_FR_0004, AR_PN0062_FR_0043 */
/* Implements AR_PN0062_FR_0062 */
/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0004, AR_PN0062_FR_0013*/
/*******************************************************************************
** Function Name         : Port_SetToDioOrAltMode
**
** Service ID            : Not Applicable
**
** Description           : This function used to set the mode of a port pin
**                         during runtime to either DIO or Alternate mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number, boolean - Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**                         Port_SearchDioAltModePin.
**
** Registers Used        : PMCSRn, PIPCn, JPMCSR0.
*******************************************************************************/
/* Implements PORT_ESDD_UD_019 */
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* Implements PORT131, AR_PN0062_FR_0069 */
/* Implements SWS_Port_00131, AR_PN0062_FR_0039 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_117, PORT_ESDD_UD_018 */
STATIC
FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode (Port_PinType Pin,
                                              boolean LblDioMode)
{
  P2CONST (volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                        LpSetPinDioAltMode;
  uint32 LulSRRegContent;
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint16 LusSRRegContentTemp;
  uint8 LucPortGroupIndex;
  #endif
  uint8 LucPortRegIndx;

  uint16 LusPinPositionMask;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_APPL_CONST) LpPortNumRegs;
  #endif
  /* MISRA Violation: START Msg(4:2982)-14 */
  LpSetPinDioAltMode = NULL_PTR;
  /* END Msg(4:2982)-14 */


  /*
   * Check whether the Pin is in Dio or Alternate mode changeable at run time
   */
  LpSetPinDioAltMode = Port_SearchChangeablePinDetail (Pin,
                         &LucPortRegIndx, PORT_PIN_DIO_ALT_CHANGABLE);
  if (NULL_PTR != LpSetPinDioAltMode)
  {
    LusPinPositionMask = LpSetPinDioAltMode->usPinPositionMask;
    /*
     * Get the port group index for accessing the hardware register
     */
    /* Implements PORT_ESDD_UD_018 */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    LucPortGroupIndex = LpSetPinDioAltMode->ucPortGroupIndex;
    #endif
    /*
     * Prepare the upper 16 bit value for PMCSR register
     */
    LulSRRegContent = ((uint32)LusPinPositionMask) <<
                      PORT_BIT_SHIFT_SIXTEEN;

    if (PORT_TRUE == LblDioMode)
    {
      /*
       * Prepare the lower 16 bit value for PMCSR register
       */
      LulSRRegContent = LulSRRegContent +
        (uint16)(~LusPinPositionMask);
    }
    else
    {
      /*
      * Prepare the lower 16 bit value for PMCSR register
      */
      LulSRRegContent = LulSRRegContent +
        (LusPinPositionMask);
    }

    /*
    * If the requested pin is belongs to numeric port group type
    */
    /* Implements PORT_ESDD_UD_018 */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == (LpSetPinDioAltMode->ucPortType &
    PORT_PG_TYPE_MASK))
    {
      /*
      * Get the global numerical register structure for the requested pin
      */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LpPortNumRegs = Port_GpConfigPtr->pPortNumRegs+LucPortRegIndx;
      /* END Msg(4:0488)-6 */
      /* Implements PORT_ESDD_UD_023 */
      /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
      /* Implements EAAR_PN0034_FR_0030 */
      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*
      * Write PMCSR register. Check for register availability
      */
      if (PORT_PMCSR_AVAILABLE == (LpPortNumRegs->ulRegListAvailable &
          PORT_PMCSR_AVAILABLE))
      {

          PORT_WRITE_REG_ONLY (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (\
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
            (LulSRRegContent & ((uint32)LusPinPositionMask)),
            ((uint32)LusPinPositionMask),
            PORT_SET_DIO_ALT_MODE_API_ID)
      }
      else
      {
      /* do nothing*/
      }

      /*
      * Write PIPC register.Check for register availability
      */
      if (PORT_PIPC_AVAILABLE == (LpPortNumRegs->ulRegListAvailable &
          PORT_PIPC_AVAILABLE))
      {
        if (PORT_TRUE == LblDioMode)
        {
          LusSRRegContentTemp =
            (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC) &
            ((uint16)(~LusPinPositionMask));
          PORT_WRITE_REG_AND_MIRROR (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
            LusSRRegContentTemp,
            &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPIPC)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
            PORT_WORD_ZERO,
            (LusPinPositionMask),
            PORT_SET_DIO_ALT_MODE_API_ID)
        }
        else
        {
          LusSRRegContentTemp =
            (Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC &
              (uint16)(~LusPinPositionMask)) |
            ((LpPortNumRegs->usInitModePIPCRegVal) &
              (LusPinPositionMask));
          PORT_WRITE_REG_AND_MIRROR (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
            LusSRRegContentTemp,
            &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPIPC)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
            ((LpPortNumRegs->usInitModePIPCRegVal) &
              (LusPinPositionMask)),
            (LusPinPositionMask),
            PORT_SET_DIO_ALT_MODE_API_ID)
        }
      }
      else
      {
      /* do nothing*/
      }
      /* Implements PORT_ESDD_UD_023 */
      /* Implements EAAR_PN0034_FR_0030 */
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_NUMERIC */
    else
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      {
        /* Implements PORT_ESDD_UD_020 */
        /* Implements AR_PN0062_FR_0023 */
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_JTAG == (LpSetPinDioAltMode->ucPortType
                                                           & PORT_PG_TYPE_MASK))
        {
         /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          /*
          * Write the value to the JPMCSR register
          */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMCSR,
                               LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GpJPortReg_BaseAddress->ulJPMCSR,
            (LulSRRegContent & ((uint32)LusPinPositionMask)),
            ((uint32)LusPinPositionMask),
            PORT_SET_DIO_ALT_MODE_API_ID)

          /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_JTAG */
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* Implements PORT_ESDD_UD_021 */
          #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_ANALOG == (LpSetPinDioAltMode->ucPortType
                                                    & PORT_PG_TYPE_MASK))
          {
          /* Implements PORT_ESDD_UD_014 */
            #if (PORT_DEV_ERROR_DETECT == STD_ON)
            /* Implements PORT051, PORT146 */
            /* Implements SWS_Port_00051, SWS_Port_00146 */
            /* Report to DET */
            (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
            PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
            #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
          }
          else
          #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
          {
            /* Implements PORT_ESDD_UD_022 */
            #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
            if ((uint8)PORT_GROUP_INPUT == LpSetPinDioAltMode->ucPortType)
            {
            /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
            /* Implements PORT_ESDD_UD_014 */
              #if (PORT_DEV_ERROR_DETECT == STD_ON)
              /* Implements PORT051, PORT146 */
              /* Implements SWS_Port_00051, SWS_Port_00146 */
              /* Report to DET */
              (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
              PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
              #endif /* (PORT_DEV_ERROR_DETECT = = STD_ON) */
            }
            else
            #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
            {
              /* No action required */
            }
          }
        }
      }
    }
  }
  else
  {
    /*
    * If DET is enabled, the API parameter checking shall be performed
    * according to the respective functions
    */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Implements PORT077 */
    /* Implements SWS_Port_00077 */
    if (PORT_TRUE == LblDioMode)
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
      PORT_SET_TO_DIO_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
      PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    #endif /* (PORT_DEV_ERROR_DETECT = = STD_ON) */
  }

} /* End of API Port_SetToDioOrAltMode */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/* Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0004 */
/*******************************************************************************
** Function Name         : Port_InitConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         numeric and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : LddReturnValue
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**
** Registers Used        : PSRn, PISn, PISAn, PIBCn, PIPCn, PUn, PDn, PBDCn,
**                         PODCn, PDSCn, PFCEn, PFCn, PFCAEn, PMCSRn, PMSRn,
**                         PPROTSn, PPCMDn, JPSR0, JPIS0, JPISA0, JPIBC0, JPU0,
**                         JPD0, JPBDC0, JPFCE0, JPFC0, JPMCSR0, JPMSR0, JPODC0,
**                         JPPCMD0, JPDSC0, JPPROTS0, APSRn, APIBCn, APBDCn,
**                         APMSRn, IPIBC0.
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

/* The function Port_Init shall initialize all controller registers */
/* Implements PORT_ESDD_UD_078, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
/* Implements SWS_Port_00079, PORT079, SWS_Port_00081, PORT081 */
/* Implements SWS_Port_00082, PORT082 */
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_InitConfig
(Port_GroupType LenGroupType)
{
  Std_ReturnType LddReturnValue;
  uint8 LucLoopCount;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint8 LucLoopTime;
  #endif
  uint8 LucIndex;
  /* Implements PORT_ESDD_UD_021 */
  #if(PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  uint8 LucNoOfPortReg;
  #endif
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint16 LusNoOfPortReg;
  #endif
  /* Implements PORT_ESDD_UD_018, PORT_ESDD_UD_123 */
  #if ((PPCMD_32BIT_REG_AVAILABLE == STD_ON) && \
       (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON))
  uint32 LulProtectRegWrite;
  #endif
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_APPL_CONST) LpPortReg;
  #endif
  /* Implements PORT_ESDD_UD_020 */
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_JTAGRegs, AUTOMATIC, PORT_APPL_CONST) LpJPortReg;
  #endif
  /* Implements PORT_ESDD_UD_021 */
  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_AnalogRegs, AUTOMATIC, PORT_APPL_CONST) LpAPortReg;
  #endif
  /* Implements PORT_ESDD_UD_022 */
  #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_IPortRegs, AUTOMATIC, PORT_APPL_CONST) LpIPortReg;
  #endif

  LddReturnValue = E_OK;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    LucLoopCount = PORT_ZERO;
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    LusNoOfPortReg = Port_GpConfigPtr->ucNoOfPortNumRegs;

    while ((LucLoopCount < LusNoOfPortReg) && (E_OK == LddReturnValue))
    {
      /*
      * Get the pointer to the Numeric Port registers
      */
      LucIndex = LpPortReg->ucPortIndex;
      /* Implements PORT_ESDD_UD_120 */
      #if (PORT_PIN_STATUS_BACKUP == STD_ON)
      
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_MCU_BCKDUP == (LpPortReg->ucDeepStopSupp & PORT_MCU_BCKDUP)))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #else
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_NO_MCU_BCKDUP == LpPortReg->ucDeepStopSupp ))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else 
      #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
      {
        /*
         * An atomic access to Microcontroller registers by the use of an
         * exclusive area
         */

        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
        /*
        * Setting Init value to the PSR register
        */
        PORT_WRITE_REG_ONLY (
          &Port_GaaPortReg_BaseAddress[LucIndex]->ulPSR,
          (LpPortReg->ulInitModePSRRegVal | PORT_MSB_MASK))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->ulPSR,
          (LpPortReg->ulInitModePSRRegVal),
          PORT_LSB_MASK,
          PORT_INIT_CONFIG_API_ID)
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
     

      /* Implements PORT_ESDD_UD_120 */
      #if (PORT_PIN_STATUS_BACKUP == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
       (PORT_ISO_PORTGROUP != (LpPortReg->ucDeepStopSupp & PORT_ISO_PORTGROUP)))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #else
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_NO_MCU_BCKDUP == LpPortReg->ucDeepStopSupp ))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
      {
        /* Implements EAAR_PN0034_FSR_0011, PORT_ESDD_UD_123 */
        /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
      /* Implements PORT_ESDD_UD_140 */
        LucLoopTime = PORT_UNLOCK_SEQUENCE_COUNT;
        #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
        /*
         * An atomic access to Microcontroller registers by the use of an
         * exclusive area
         */

        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
        LulProtectRegWrite = LpPortReg->ulInitModePODCRegVal & (~PORT_MSB_MASK);
        do
        {
          /*
          * Write the fixed value 0000 00A5H to the protection command register.
          */
          /* Implements PORT_ESDD_UD_124, EAAR_PN0062_FR_0006 */
          PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPPCMD,
            PORT_WRITE_ERROR_CLEAR_VAL)
          /*
          * Write the register value to the corresponding register with upper 16
          * bit set to zero
          */
          PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPODC,
            LulProtectRegWrite)
          /*
          * Write the bit wise inverse value to the corresponding register with
          * upper 16 bit set to one
          */
          PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPODC,
            (~LulProtectRegWrite))
          /*
          * Write the register value to the corresponding register with upper 16
          * bit set to zero
          */
          PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPODC,
            LulProtectRegWrite)

          LucLoopTime--;
        }
        /* Implements PORT_ESDD_UD_162, EAAR_PN0034_FSR_0011 */
        /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
        #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
        while (((uint32)PORT_PROTECTED_ERR_OCCURRED ==
          Port_GaaPortReg_BaseAddress[LucIndex]->ulPPROTS)
                                                  && (PORT_ZERO < LucLoopTime));
        #endif
        PORT_CHECK_WRITE_VERIFY_INIT (
                  &Port_GaaPortReg_BaseAddress[LucIndex]->ulPODC,
                  LulProtectRegWrite,
                  PORT_LSB_MASK,
                  PORT_INIT_CONFIG_API_ID)

        /*
        * Check if the loop has exited because of failure
        * of writing to register
        */
        if ((uint32)PORT_PROTECTED_ERR_OCCURRED ==
                               Port_GaaPortReg_BaseAddress[LucIndex]->ulPPROTS)
        {
            /* Implements EAAR_PN0062_FR_0021 */
          Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
            (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
          /*
          * Set the Dem error flag
          */
          LddReturnValue = E_NOT_OK;
        }
        else
        {
          /* No action required */
        }
        /*(PPROTS_8BIT_REG_AVAILABLE and PPCMD_8BIT_REG_AVAILABLE )*/
        
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        #endif
        
        /*
        * Check if the PDSC register is available
        */
        /* Implements EAAR_PN0062_FR_0017 */
        if(PORT_PDSC_AVAILABLE == (LpPortReg->ulRegListAvailable &
          PORT_PDSC_AVAILABLE))
        {
          /* Implements PORT_ESDD_UD_123 */
          #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
          /*
           * An atomic access to Microcontroller registers by the use of an
           * exclusive area
           */

          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
          LulProtectRegWrite = LpPortReg->ulInitModePDSCRegVal &
            (~PORT_MSB_MASK);
          do
          {
            /*
            * Write the fixed value 0000 00A5H to the protection
            * command register
            */
            /* Implements PORT_ESDD_UD_124, EAAR_PN0062_FR_0006 */
            PORT_WRITE_REG_ONLY
            (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPPCMD,
              PORT_WRITE_ERROR_CLEAR_VAL)
            /*
            * Write the register value to the corresponding register with
            * upper 16 bit set to zero
            */
            PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPDSC,
              LulProtectRegWrite)
            /*
            * Write the bit wise inverse value to the corresponding
            * register with upper 16 bit set to one
            */
            PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPDSC,
              (~LulProtectRegWrite))
            /*
            * Write the register value to the corresponding register with
            * upper 16 bit set to zero
            */
            PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPDSC,
              LulProtectRegWrite)

            LucLoopTime--;
          }
          /* Implements PORT_ESDD_UD_162, EAAR_PN0034_FSR_0011 */
          /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
          #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
          while (((uint32)PORT_PROTECTED_ERR_OCCURRED ==
                  Port_GaaPortReg_BaseAddress[LucIndex]->ulPPROTS)&&
                 (PORT_ZERO < LucLoopTime));
          #endif
          PORT_CHECK_WRITE_VERIFY_INIT (
                    &Port_GaaPortReg_BaseAddress[LucIndex]->ulPDSC,
                    LulProtectRegWrite,
                    PORT_LSB_MASK,
                    PORT_INIT_CONFIG_API_ID)

          /*
          * Check if the loop has exited because of failure of
          * writing to register
          */

          if ((uint32)PORT_PROTECTED_ERR_OCCURRED ==
                              Port_GaaPortReg_BaseAddress[LucIndex]->ulPPROTS)
          {
            /* Implements EAAR_PN0062_FR_0021 */
            Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
              (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
            /*
            * Set the Dem error flag
            */
            LddReturnValue = E_NOT_OK;
          }
          else
          {
            /* No action required */
          }
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        #endif
        }
        
        /*
        * Write the Init value to the PU register
        */
        PORT_WRITE_REG_ONLY (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPU,
          (LpPortReg->usInitModePURegVal))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPU,
          (LpPortReg->usInitModePURegVal),
          PORT_SHORT_MASK,
          PORT_INIT_CONFIG_API_ID)

        /*
        * Write the Init value to the PD register
        */
        PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->usPD,
          (LpPortReg->usInitModePDRegVal))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPD,
          (LpPortReg->usInitModePDRegVal),
          PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

        /*
        * Write the Init value to the PIS register
        */
        PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->usPIS,
          (LpPortReg->usInitModePISRegVal))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPIS,
          (LpPortReg->usInitModePISRegVal),
          PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

        /*
        * Write the Init value to the PISA register if it is available
        */
        #if (PORT_PISA_REG_AVAILABLE == STD_ON)
        if(PORT_PISA_AVAILABLE == (LpPortReg->ulRegListAvailable &
            PORT_PISA_AVAILABLE))
        {
          PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->usPISA,
            (LpPortReg->usInitModePISARegVal))
          PORT_CHECK_WRITE_VERIFY_INIT (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPISA,
            (LpPortReg->usInitModePISARegVal),
            PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)
        }
        else
        {
          /* No Action Required*/
        }
        #endif

        /*
        * Write the Init value to the PFC register if it is available
        */
        if(PORT_PFC_AVAILABLE == (LpPortReg->ulRegListAvailable &
            PORT_PFC_AVAILABLE))
        {

            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
    
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * Write the Init value to the PFC register
            */
            PORT_WRITE_REG_AND_MIRROR (
              &Port_GaaPortReg_BaseAddress[LucIndex]->usPFC,
              (LpPortReg->usInitModePFCRegVal),
              &Port_GstRamMirrorPortReg[LucIndex].usPFC)
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaPortReg_BaseAddress[LucIndex]->usPFC,
              (LpPortReg->usInitModePFCRegVal),
              PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
          /* No Action Required*/
        }

        /*
        * Write the Init value to the PFCE register if it is available
        */
        if(PORT_PFCE_AVAILABLE == (LpPortReg->ulRegListAvailable &
            PORT_PFCE_AVAILABLE))
        {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */

            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            PORT_WRITE_REG_AND_MIRROR (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPFCE,
            (LpPortReg->usInitModePFCERegVal),
            &Port_GstRamMirrorPortReg[LucIndex].usPFCE)
          PORT_CHECK_WRITE_VERIFY_INIT (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPFCE,
            (LpPortReg->usInitModePFCERegVal),
            PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)
            
           /* Exit critical section */
           #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
           PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
           #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
          /* No Action Required*/
        }

        /*
        * Write the Init value to the PFCAE register if it is available
        */
        if(PORT_PFCAE_AVAILABLE == (LpPortReg->ulRegListAvailable &
          PORT_PFCAE_AVAILABLE))
        {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */

            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            PORT_WRITE_REG_AND_MIRROR (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPFCAE,
            LpPortReg->usInitModePFCAERegVal,
            &Port_GstRamMirrorPortReg[LucIndex].usPFCAE)
          PORT_CHECK_WRITE_VERIFY_INIT (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPFCAE,
            (LpPortReg->usInitModePFCAERegVal),
            PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)
            
           /* Exit critical section */
           #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
           PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
           #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
        /* No Action Required*/
        }

        /*
        * Write the value to the PIPC register if it is available
        */
        if(PORT_REG_AVAILABLE !=
                         (LpPortReg->ulRegListAvailable & PORT_PIPC_AVAILABLE))
        {
          /*
           * An atomic access to Microcontroller registers by the use of an
           * exclusive area
           */

          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
          PORT_WRITE_REG_AND_MIRROR (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPIPC,
            (LpPortReg->usInitModePIPCRegVal),
            &Port_GstRamMirrorPortReg[LucIndex].usPIPC)
          PORT_CHECK_WRITE_VERIFY_INIT (
            &Port_GaaPortReg_BaseAddress[LucIndex]->usPIPC,
            (LpPortReg->usInitModePIPCRegVal),
            PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)
            
         /* Exit critical section */
         #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
         PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
         #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
        /* No Action Required*/
        }
        
        /*
        * Write the Init value to the PMCSR register if it is available
        */
        if(PORT_PMCSR_AVAILABLE == (LpPortReg->ulRegListAvailable &
            PORT_PMCSR_AVAILABLE))
        {

            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
    
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * Write the Init value to the PMCSR register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaPortReg_BaseAddress[LucIndex]->ulPMCSR,
              (LpPortReg->ulInitModePMCSRRegVal | PORT_MSB_MASK))
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaPortReg_BaseAddress[LucIndex]->ulPMCSR,
              (LpPortReg->ulInitModePMCSRRegVal),
              PORT_LSB_MASK, PORT_INIT_CONFIG_API_ID)
            
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
          /* No Action Required*/
        }

        /*
        * Write the Init value to the PIBC register
        */
        PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->usPIBC,
          (LpPortReg->usInitModePIBCRegVal))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPIBC,
          (LpPortReg->usInitModePIBCRegVal),
          PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

        /*
        * Write the Init value to the PBDC register
        */
        PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->usPBDC,
          (LpPortReg->usInitModePBDCRegVal))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->usPBDC,
          (LpPortReg->usInitModePBDCRegVal),
          PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

        /*
         * An atomic access to Microcontroller registers by the use of an
         * exclusive area
         */

        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
        /* Get  PMSR register  Restored registers pending*/
        PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPMSR,
          (LpPortReg->ulInitModePMSRRegVal | PORT_MSB_MASK))
        PORT_CHECK_WRITE_VERIFY_INIT (
          &Port_GaaPortReg_BaseAddress[LucIndex]->ulPMSR,
          (LpPortReg->ulInitModePMSRRegVal),
          PORT_LSB_MASK, PORT_INIT_CONFIG_API_ID)
        
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      LucLoopCount++;
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortReg++;
      /* END Msg(4:0489)-7 */
    } /* while (LucLoopCount < LpPortReg)*/
  } /* end of(PORT_GROUP_NUMERIC == LenGroupType)*/
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    /* Implements PORT_ESDD_UD_020 */
    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    /* MISRA Violation: START Msg(4:2995)-1 */
    if ((PORT_GROUP_JTAG == LenGroupType) && (E_OK == LddReturnValue))
    /* END Msg(4:2995)-1 */
    {

      LpJPortReg = Port_GpConfigPtr->pPortJRegs;
      
      /* Implements PORT_ESDD_UD_120 */
      #if (PORT_PIN_STATUS_BACKUP == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_MCU_BCKDUP == (LpJPortReg->ucDeepStopSupp & PORT_MCU_BCKDUP)))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #else
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
        (PORT_NO_MCU_BCKDUP == LpJPortReg->ucDeepStopSupp ))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
      {
       /*
        * An atomic access to Microcontroller registers by the use of an
        * exclusive area
        */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        /*
        * Setting Init value to the PSR register
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPSR,
          (LpJPortReg->ulInitModeJPSRRegVal | PORT_MSB_MASK))
        PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ulJPSR,
          (LpJPortReg->ulInitModeJPSRRegVal),
          PORT_LSB_MASK, PORT_INIT_CONFIG_API_ID)
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }

      /* Implements PORT_ESDD_UD_120 */
      #if (PORT_PIN_STATUS_BACKUP == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
      (PORT_ISO_PORTGROUP != (LpJPortReg->ucDeepStopSupp & PORT_ISO_PORTGROUP)))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #else
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
        (PORT_NO_MCU_BCKDUP == LpJPortReg->ucDeepStopSupp ))
      /* END Msg(4:0303)-2 */
      {
        /* No Action Required */
      }
      else
      #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
      {
      /* Implements EAAR_PN0034_FSR_0011, PORT_ESDD_UD_123 */
      /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
      /* Implements PORT_ESDD_UD_140 */
      LucLoopTime = PORT_UNLOCK_SEQUENCE_COUNT;
      #if(PPCMD_32BIT_REG_AVAILABLE == STD_ON)
     /*
      * An atomic access to Microcontroller registers by the use of an
      * exclusive area
      */
     /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      LulProtectRegWrite = LpJPortReg->ulInitModeJPODCRegVal &
                          (~PORT_MSB_MASK);
      do
      {
        /*
        * Write the fixed value 0000 00A5H to the protection
        * command register.
        */
        /* Implements PORT_ESDD_UD_124, AR_PN0062_FR_0006 */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPPCMD,
          PORT_WRITE_ERROR_CLEAR_VAL)
        /*
        * Write the register value to the corresponding register with
        * upper 16 bit set to zero
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPODC,
          LulProtectRegWrite)
        /*
        * Write the bit wise inverse value to the corresponding register with
        * upper 16 bit set to one
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPODC,
          (~LulProtectRegWrite))
        /*
        * Write the register value to the corresponding register with
        * upper 16 bit set to zero
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPODC,
          LulProtectRegWrite)

        LucLoopTime--;
      }
      /* Implements PORT_ESDD_UD_162, EAAR_PN0034_FSR_0011 */
      /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
      #if(PPROTS_32BIT_REG_AVAILABLE == STD_ON)
      while (((uint8)PORT_PROTECTED_ERR_OCCURRED ==
                     Port_GpJPortReg_BaseAddress->ulJPPROTS)
                                                  && (PORT_ZERO < LucLoopTime));
      #endif
      PORT_CHECK_WRITE_VERIFY_INIT (
                &Port_GpJPortReg_BaseAddress->ulJPODC,
                LulProtectRegWrite,
                PORT_LSB_MASK,
                PORT_INIT_CONFIG_API_ID)

      /*
      * Check if the loop has exited because of failure of
      * writing to register
      */
      if ((uint8)PORT_PROTECTED_ERR_OCCURRED ==
                                      Port_GpJPortReg_BaseAddress->ulJPPROTS)
      {
        Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
          (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
        /* MISRA Violation: START Msg(4:2982)-14 */
        /* Set the Dem error flag */
        LddReturnValue = E_NOT_OK;
        /* END Msg(4:2982)-14 */
      }
      else
      {
        /* No action required */
      }
      #endif
      /* Implements PORT_ESDD_UD_123 */
      #if(PPCMD_32BIT_REG_AVAILABLE == STD_ON)
      LulProtectRegWrite = LpJPortReg->ulInitModeJPDSCRegVal &
        (~PORT_MSB_MASK);
      do
      {
        /*
        * Write the fixed value 0000 00A5H to the protection
        * command register.
        */
        /* Implements PORT_ESDD_UD_124, AR_PN0062_FR_0006 */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPPCMD,
          PORT_WRITE_ERROR_CLEAR_VAL)
        /*
        * Write the register value to the corresponding register with
        * upper 16 bit set to zero
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPDSC,
          LulProtectRegWrite)

        /*
        * Write the bit wise inverse value to the corresponding register with
        * upper 16 bit set to one
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPDSC,
          (~LulProtectRegWrite))
        /*
        * Write the register value to the corresponding register with
        * upper 16 bit set to zero
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPDSC,
          LulProtectRegWrite)

        LucLoopTime--;
      }
      /* Implements PORT_ESDD_UD_162, EAAR_PN0034_FSR_0011 */
      /* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_FSR_0013 */
      #if(PPROTS_32BIT_REG_AVAILABLE == STD_ON)
      while (((uint8)PORT_PROTECTED_ERR_OCCURRED ==
                     Port_GpJPortReg_BaseAddress->ulJPPROTS)
                                                && (PORT_ZERO < LucLoopTime));
      #endif
      PORT_CHECK_WRITE_VERIFY_INIT (
                &Port_GpJPortReg_BaseAddress->ulJPDSC,
                LulProtectRegWrite,
                PORT_LSB_MASK,
                PORT_INIT_CONFIG_API_ID)

      /*
      * Check if the loop has exited because of failure of
      * writing to register
      */
      if ((uint8)PORT_PROTECTED_ERR_OCCURRED ==
                                      Port_GpJPortReg_BaseAddress->ulJPPROTS)
      {
        Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
          (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
        /* MISRA Violation: START Msg(4:2983)-15 */
        /* Set the Dem error flag */
        LddReturnValue = E_NOT_OK;
        /* END Msg(4:2983)-15 */
      }
      else
      {
      /* No action required */
      }
      #endif
    
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
     
      /* MISRA Violation: START Msg(4:1891)-11 */
      /*
      * Write the Init value to the PU register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPU,
        (uint8)(LpJPortReg->usInitModeJPURegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPU,
        (LpJPortReg->usInitModeJPURegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)

      /*
      * Write the Init value to the PD register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPD,
        (uint8)(LpJPortReg->usInitModeJPDRegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPD,
        (LpJPortReg->usInitModeJPDRegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)

      /*
      * Write the Init value to the PIS register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPIS,
        (uint8)(LpJPortReg->usInitModeJPISRegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPIS,
        (LpJPortReg->usInitModeJPISRegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)

      /*
      * Write the Init value to the PISA register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPISA,
        (uint8)(LpJPortReg->usInitModeJPISARegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPISA,
        (LpJPortReg->usInitModeJPISARegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)
    
      /*
       * An atomic access to Microcontroller registers by the use of an
       * exclusive area
       */

      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    
      /*
      * Write the Init value to the PFC register
      */
      PORT_WRITE_REG_AND_MIRROR (&Port_GpJPortReg_BaseAddress->ucJPFC,
        ((uint8)(LpJPortReg->usInitModeJPFCRegVal)),
        &Port_GstRamMirrorJPortReg.ucJPFC)
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPFC,
        ((uint8)(LpJPortReg->usInitModeJPFCRegVal)),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)

      /*
      * Write the Init value to the PFCE register
      */
      PORT_WRITE_REG_AND_MIRROR (&Port_GpJPortReg_BaseAddress->ucJPFCE,
        (uint8)(LpJPortReg->usInitModeJPFCERegVal),
        &Port_GstRamMirrorJPortReg.ucJPFCE)
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPFCE,
        (LpJPortReg->usInitModeJPFCERegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)
      /* END Msg(4:1891)-11 */

      /*
      * Write the Init value to the PMCSR register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMCSR,
        (LpJPortReg->ulInitModeJPMCSRRegVal | PORT_MSB_MASK))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ulJPMCSR,
        (LpJPortReg->ulInitModeJPMCSRRegVal),
        PORT_JPORT_MASK, PORT_INIT_CONFIG_API_ID)

      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    
      /*
      * Write the Init value to the PIBC register
      */
      /* MISRA Violation: START Msg(4:1891)-11 */
      /* Implements AR_PN0062_FR_0025*/
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPIBC,
        (uint8)(LpJPortReg->usInitModeJPIBCRegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPIBC,
        (LpJPortReg->usInitModeJPIBCRegVal),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)
      /* END Msg(4:1891)-11 */

      /*
      * Write the Init value to the PBDC register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ucJPBDC,
        (uint8)(LpJPortReg->usInitModeJPBDCRegVal))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ucJPBDC,
        ((uint8)(LpJPortReg->usInitModeJPBDCRegVal)),
        PORT_BYTE_MASK, PORT_INIT_CONFIG_API_ID)

      /*
       * An atomic access to Microcontroller registers by the use of an
       * exclusive area
       */

      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    
      /*
      * Write the Init value to the PMSR register
      */
      PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
        (LpJPortReg->ulInitModeJPMSRRegVal | PORT_MSB_MASK))
      PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpJPortReg_BaseAddress->ulJPMSR,
        (LpJPortReg->ulInitModeJPMSRRegVal),
        PORT_JPMSR_MASK, PORT_INIT_CONFIG_API_ID)
        
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
    }/* end of(PORT_GROUP_JTAG == LenGroupType)*/
    else
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      /* Implements PORT_ESDD_UD_021 */
      #if(PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (PORT_GROUP_ANALOG == LenGroupType)
      {
        LpAPortReg = Port_GpConfigPtr->pPortAnalogRegs;
        LucLoopCount = PORT_ZERO;
        LucNoOfPortReg = Port_GpConfigPtr->ucNoOfPortAnalogRegs;
        while ((LucLoopCount < LucNoOfPortReg) && (E_OK == LddReturnValue))
        {
          LucIndex = LpAPortReg->ucPortIndex;
          /* Implements PORT_ESDD_UD_120 */
          #if (PORT_PIN_STATUS_BACKUP == STD_ON)
          /* MISRA Violation: START Msg(4:0303)-2 */
          if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
              (PORT_MCU_BCKDUP == (LpAPortReg->ucDeepStopSupp
                                                           & PORT_MCU_BCKDUP)))
          /* END Msg(4:0303)-2 */
          {
            /* No Action Required */
          }
          else
          #else
          /* MISRA Violation: START Msg(4:0303)-2 */
          if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_NO_MCU_BCKDUP == LpAPortReg->ucDeepStopSupp ))
          /* END Msg(4:0303)-2 */
          {
            /* No Action Required */
          }
          else
          #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
          {
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */

            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /*
            * Setting Init value to the APSR register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPSR,
              (LpAPortReg->ulInitModeAPSRRegVal | PORT_MSB_MASK))
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPSR,
              (LpAPortReg->ulInitModeAPSRRegVal),
              PORT_LSB_MASK, PORT_INIT_CONFIG_API_ID)
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          }
          /* Implements PORT_ESDD_UD_120 */
          #if (PORT_PIN_STATUS_BACKUP == STD_ON)
          /* MISRA Violation: START Msg(4:0303)-2 */
          if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
              (PORT_ISO_PORTGROUP != (LpAPortReg->ucDeepStopSupp
                                                         & PORT_ISO_PORTGROUP)))
          /* END Msg(4:0303)-2 */
          {
            /* No Action Required */
          }
          else
          #else
          /* MISRA Violation: START Msg(4:0303)-2 */
          if ((PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK)) &&
          (PORT_NO_MCU_BCKDUP == LpAPortReg->ucDeepStopSupp ))
          /* END Msg(4:0303)-2 */
          {
            /* No Action Required */
          }
          else
          #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON*/
          {
            /*
            * Setting Init value to the PIBC register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->usAPIBC,
              (LpAPortReg->usInitModeAPIBCRegVal))
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->usAPIBC,
              (LpAPortReg->usInitModeAPIBCRegVal),
              PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

            /*
            * Setting Init value to the PBDC register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->usAPBDC,
              (LpAPortReg->usInitModeAPBDCRegVal))
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->usAPBDC,
              (LpAPortReg->usInitModeAPBDCRegVal),
              PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */

            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
            /*
            * Setting Init value to the PMSR register
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPMSR,
              (LpAPortReg->ulInitModeAPMSRRegVal | PORT_MSB_MASK))
            PORT_CHECK_WRITE_VERIFY_INIT (
              &Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPMSR,
              (LpAPortReg->ulInitModeAPMSRRegVal),
              PORT_LSB_MASK, PORT_INIT_CONFIG_API_ID)

           /* Exit critical section */
           #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
           PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
           #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          }
          LucLoopCount++;
          /* MISRA Violation: START Msg(4:0489)-7 */
          LpAPortReg++;
          /* END Msg(4:0489)-7 */
        }
      }
      else
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        /* Implements PORT_ESDD_UD_022 */
        #if(PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
        if (PORT_GROUP_INPUT == LenGroupType)
        {
          LpIPortReg = Port_GpConfigPtr->pPortInputRegs;
          /* Get 16Bit IPIBC registers   */
          PORT_WRITE_REG_ONLY (&Port_GpIPortReg_BaseAddress->usIPIBC,
            (LpIPortReg->usInitModeIPIBCRegVal))
          PORT_CHECK_WRITE_VERIFY_INIT (&Port_GpIPortReg_BaseAddress->usIPIBC,
            (LpIPortReg->usInitModeIPIBCRegVal),
            PORT_SHORT_MASK, PORT_INIT_CONFIG_API_ID)

        } /* end of(PORT_GROUP_INPUT == LenGroupType)*/
        else
        #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* No action required */
        }
      }
    }
  }

  return (LddReturnValue);
} /* End of API Port_InitConfig */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/* Implements AR_PN0062_FR_0043, AR_PN0062_FR_0063 */
/*******************************************************************************
** Function Name         : Port_SearchChangeablePinDetail
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin is
**                         Direction/Mode/Dio-Alt changeable.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         pPortRegIndex - Port Group Index
**                         LucModeCheck - Direction/Mode/Dio-Alt Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Direction/Mode/Dio-ALT
**                         Changeable Pin structure - if given pin
**                         number matches. NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || \
     (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON) || \
     (PORT_SET_PIN_MODE_API == STD_ON))

/* Implements PORT131, SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_077, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
/* Implements SWS_Port_00137, PORT137 */
STATIC FUNC (P2CONST (volatile Port_PinChangeableDetails,
AUTOMATIC, PORT_CONFIG_CONST), PORT_PRIVATE_CODE)
Port_SearchChangeablePinDetail(
Port_PinType LddPinNumber, uint8* pPortRegIndex, uint8 LucModeCheck)
{
  P2CONST (volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
    LpSearchPtr;
  P2CONST (volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
    LpRetPtr;
  uint8 LucRetPGIndx;
  uint8 LucLow;
  uint8 LucHigh;
  uint16 LusListSearchId;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_CONFIG_CONST) LpSearchNumRegPtr;
  uint16 LusHigh;
  #endif
  /* Implements PORT_ESDD_UD_021 */
  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_AnalogRegs, AUTOMATIC, PORT_CONFIG_CONST) LpSearchAnalogRegPtr;
  #endif
  /* Initializing Direction Control Registers Pointer to Null pointer */
  LpRetPtr = NULL_PTR;
  LpSearchPtr = Port_GpConfigPtr->pPinChangeableDetails;
  LucHigh = PORT_NUM_OF_PINS_MODIFIABLE;
  LucLow = PORT_ZERO;
  LucRetPGIndx = PORT_PG_NOTAVAILABLE;
  /* Get the lower limit of Search ID */
  /* MISRA Violation: START Msg(4:2982)-14 */
  LusListSearchId = LpSearchPtr->ddPinId;
  /* END Msg(4:2982)-14 */
  *pPortRegIndex = PORT_PG_NOTAVAILABLE;

  while(LucLow < LucHigh)
  {
  /*
  * Get the Search-ID of the mid IDs
  */
  LusListSearchId = LpSearchPtr->ddPinId;
  /*
  * Compare Search-ID with the requested one
  */
    if (LddPinNumber == LusListSearchId)
    {
      /* Checking whether the pin is Mode/Direction/DioAlt Changeable. */
      if (( LpSearchPtr->ucPortType & LucModeCheck ) == LucModeCheck)
      {
        /* Update the return pointer with the pin number structure */
        LpRetPtr = LpSearchPtr;
        LucRetPGIndx = LpRetPtr->ucPortGroupIndex;
        /*
        * Set LucHigh to zero to break the loop
        */
        LucHigh = PORT_ZERO;
      }
      else
      {
        /* Break the loop */
        LucHigh = LucLow;
      }
    } /* End of LusListSearchId == LddPinNumber */
    else
    {
      /*
      * Increment the search index
      */
      LucLow++;
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpSearchPtr++;
      /* END Msg(4:0489)-7 */
    }
  /* MISRA Violation: START Msg(4:3138)-12*/
  };
  /*END Msg(4:3138)-12*/

  if (PORT_PG_NOTAVAILABLE != LucRetPGIndx)
  {
    /* Implements PORT_ESDD_UD_018 */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    /*
    * If the port group type is numeric
    */
    if ((uint8)PORT_GROUP_NUMERIC == (LpRetPtr->ucPortType & PORT_PG_TYPE_MASK))
    {
      LpSearchNumRegPtr = Port_GpConfigPtr->pPortNumRegs;
      LusHigh = (Port_GpConfigPtr->ucNoOfPortNumRegs);
      LucLow = PORT_ZERO;
      while(LucLow < LusHigh)
      {
        /*
        * Get the Search-ID of the mid IDs
        */
        LusListSearchId = (LpSearchNumRegPtr->ucPortIndex);
        /*
        * Compare Search-ID with the requested one
        */
        if (LusListSearchId == LucRetPGIndx)
        {
          /*
          * Update the return port group index with the index of the structure
          */
          *pPortRegIndex = LucLow;
          /*
          * Set LusHigh to zero to break the loop
          */
          LusHigh = PORT_ZERO;
        } /* End of LusListSearchId == LddPinNumber */
        else
        {
          /*
          * Increment the search index
          */
          LucLow++;
          /* MISRA Violation: START Msg(4:0489)-7 */
          LpSearchNumRegPtr++;
          /* END Msg(4:0489)-7 */
        }
          /* MISRA Violation:START Msg(4:3138)-12 */
      };
          /* END Msg(4:3138)-12 */
    }
    else
    #endif
    {
      {
        /* Implements PORT_ESDD_UD_021 */
        #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
        /*
        * If the port group type is analog
        */
        if ((uint8)PORT_GROUP_ANALOG == (LpRetPtr->ucPortType &
        PORT_PG_TYPE_MASK))
        {
        LpSearchAnalogRegPtr = Port_GpConfigPtr->pPortAnalogRegs;
        LucHigh = (Port_GpConfigPtr->ucNoOfPortAnalogRegs);
        LucLow = PORT_ZERO;
        while(LucLow < LucHigh)
        {
          /*
          * Get the Search-ID of the mid IDs
          */
          LusListSearchId = (LpSearchAnalogRegPtr->ucPortIndex);
          /*
          * Compare Search-ID with the requested one
          */
          if (LusListSearchId == LucRetPGIndx)
          {
            /*
            * Update the return port group index with the index of
            * the structure
            */
            *pPortRegIndex = LucLow;
            /*
            * Set LucHigh to zero to break the loop
            */
            LucHigh = PORT_ZERO;
          } /* End of LusListSearchId == LddPinNumber */
          else
          {
            /*
            * Increment the search index
            */
            LucLow++;
            /* MISRA Violation: START Msg(4:0489)-7 */
            LpSearchAnalogRegPtr++;
            /* END Msg(4:0489)-7 */
          }
        /* MISRA Violation: START Msg(4:3138)-12 */
        };
        /* END Msg(4:3138)-12 */
        }
        else
        #endif
        {
          /* Implements PORT_ESDD_UD_020 */
          #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
          /*
          * If the port group type is jtag
          */
          *pPortRegIndex = PORT_ZERO;
          #endif
        }
      }
    }
  }
  else
  {
  /* No action required */
  }
  return (LpRetPtr);
} /* End of API Port_SearchChangeablePinDetail */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* ((PORT_SET_PIN_DIRECTION_API == STD_ON) ||
*(PORT_SET_TO_DIO_ALT_MODE_API == STD_ON) ||
*(PORT_SET_PIN_MODE_API == STD_ON))
*/

/* Implements AR_PN0062_FR_0004, AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name         : Port_RefreshPortInternal
**
** Service ID            : Not Applicable
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port Group Type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Det_ReportError
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION
**
** Registers Used        : PMSRn, JPMSR0, APMSRn.
*******************************************************************************/
/* Implements PORT131 */
/* Implements SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_081, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
/* Implements AR_PN0062_FR_0061 */
/* Implements PORT061, SWS_Port_00061 */
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
(Port_GroupType LenGroupType)
{
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint16 LusNoOfRegs;
  #endif
  /* Implements PORT_ESDD_UD_020, PORT_ESDD_UD_21 */
  #if ((PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) || \
       (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
  uint8 LucNoOfRegs;
  #endif
  uint8 LucIndex;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_APPL_CONST) LpPortNumRegs;
  #endif
  /* Implements PORT_ESDD_UD_020 */
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_JTAGRegs, AUTOMATIC, PORT_APPL_CONST) LpPortJRegs;
  #endif
  /* Implements PORT_ESDD_UD_021 */
  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_AnalogRegs, AUTOMATIC, PORT_APPL_CONST) LpPortAnalogRegs;
  #endif
  /*
  * An atomic access to Microcontroller registers by the use of an exclusive
  * area
  */
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /*
    * Get the count of 32Bit Numeric PMSR registers
    */
    LusNoOfRegs = Port_GpConfigPtr->ucNoOfPortNumRegs;
    LpPortNumRegs = Port_GpConfigPtr->pPortNumRegs;

    /* Implements PORT_ESDD_UD_023 */
    /* Implements EAAR_PN0034_FR_0030 */
    /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    while (PORT_ZERO < LusNoOfRegs)
    {
      /*
      * Write the initial value to the pins which are Directional unchangeable
      * and retain the values of those pins which are Directional changeable
      */
      LucIndex = LpPortNumRegs->ucPortIndex;

      PORT_WRITE_REG_ONLY (&Port_GaaPortReg_BaseAddress[LucIndex]->ulPMSR,
        (LpPortNumRegs->ulMaskConfigPMSRRegVal))
      PORT_CHECK_WRITE_VERIFY_RUNTIME (
        &Port_GaaPortReg_BaseAddress[LucIndex]->ulPMSR,
        ((LpPortNumRegs->ulMaskConfigPMSRRegVal) &
            (LpPortNumRegs->ulMaskConfigPMSRRegVal >> PORT_BIT_SHIFT_SIXTEEN)),
        (LpPortNumRegs->ulMaskConfigPMSRRegVal >> PORT_BIT_SHIFT_SIXTEEN),
        PORT_REFRESH_PORT_INTERNAL_API_ID)

      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortNumRegs++;
      /* END Msg(4:0489)-7 */
      LusNoOfRegs--;
    } /* End of LusNoOfRegs > PORT_ZERO */
    /* Implements PORT_ESDD_UD_023 */
    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    /* Implements PORT_ESDD_UD_020 */
    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    if (PORT_GROUP_JTAG == LenGroupType)
    {
      /* Get the count of 32Bit Jtag PMSR registers */
      LucNoOfRegs = Port_GpConfigPtr->ucNoOfPortJRegs;
      LpPortJRegs = Port_GpConfigPtr->pPortJRegs;
      /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      while (PORT_ZERO < LucNoOfRegs)

      {
        /*
        * Write the initial value to the pins which
        * are Directional unchangeable
        * and retain the values of those pins which
        * are Directional changeable
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
          (LpPortJRegs->ulMaskConfigJPMSRRegVal))
        PORT_CHECK_WRITE_VERIFY_RUNTIME (&Port_GpJPortReg_BaseAddress->ulJPMSR,
          (LpPortJRegs->ulMaskConfigJPMSRRegVal &
              (LpPortJRegs->ulMaskConfigJPMSRRegVal >> PORT_BIT_SHIFT_SIXTEEN)),
          (LpPortJRegs->ulMaskConfigJPMSRRegVal >> PORT_BIT_SHIFT_SIXTEEN),
          PORT_REFRESH_PORT_INTERNAL_API_ID)

        /* MISRA Violation: START Msg(4:0489)-7 */
        LpPortJRegs++;
        /* END Msg(4:0489)-7 */
        LucNoOfRegs--;
      } /* End of LucNoOfRegs > PORT_ZERO */
      /* Implements EAAR_PN0034_FR_0030 */
      /* Implements PORT_ESDD_UD_023 */
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    } /* End of LenGroupType == PORT_GROUP_JTAG */
    else
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      /* Implements PORT_ESDD_UD_021 */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (PORT_GROUP_ANALOG == LenGroupType)
      {
        /* Get the count of 32Bit Analog PMSR registers */
        LucNoOfRegs = Port_GpConfigPtr->ucNoOfPortAnalogRegs;
        LpPortAnalogRegs = Port_GpConfigPtr->pPortAnalogRegs;
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        while (PORT_ZERO < LucNoOfRegs)
        {
          /*
          * Write the initial value to the pins which
          * are Directional unchangeable
          * and retain the values of those pins which
          * are Directional changeable
          */
          LucIndex = LpPortAnalogRegs->ucPortIndex;

          PORT_WRITE_REG_ONLY (&Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPMSR,
            (LpPortAnalogRegs->ulMaskConfigAPMSRRegVal))
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaAPortReg_BaseAddress[LucIndex]->ulAPMSR,
            ((LpPortAnalogRegs->ulMaskConfigAPMSRRegVal) &
              (LpPortAnalogRegs->ulMaskConfigAPMSRRegVal
                                                  >> PORT_BIT_SHIFT_SIXTEEN)),
            (LpPortAnalogRegs->ulMaskConfigAPMSRRegVal
                                                  >> PORT_BIT_SHIFT_SIXTEEN),
            PORT_REFRESH_PORT_INTERNAL_API_ID)
          /* MISRA Violation: START Msg(4:0489)-7 */
          LpPortAnalogRegs++;
          /* END Msg(4:0489)-7 */
          LucNoOfRegs--;
        } /* End of LucNoOfRegs > PORT_ZERO */
        /* Implements PORT_ESDD_UD_023 */
        /* Implements EAAR_PN0034_FR_0030 */
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      } /* End of LenGroupType == PORT_GROUP_ANALOG */
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
    }
  }
} /* End of API Port_RefreshPortInternal */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/* Implements AR_PN0062_FR_0032 AR_PN0062_FR_0033, AR_PN0062_FR_0034 */
/* Implements AR_PN0062_FR_0035 */
/* Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name         : Port_FilterConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         filter configuration.
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
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : None
**
** Registers Used        : DNFAnCTL, DNFAnEN, FCLA0CTLm.
*******************************************************************************/
/* Implements PORT_ESDD_UD_107, PORT_ESDD_UD_108, PORT_ESDD_UD_114 */
#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))

/* Implements PORT131, AR_PN0062_FR_0031, AR_PN0062_FR_0033 */
/* Implements SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_FilterConfig(void)
{
  /*
  * Pointer to digital filter DNFA register data structure
  */
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_DNFARegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFAReg;

  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  /*
  * Pointer to analog filter FCLA register data structure
  */
  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_FCLARegs, AUTOMATIC, PORT_CONFIG_DATA) LpFCLAReg;
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

  #if ((PORT_FCLA_REG_CONFIG == STD_ON) || (PORT_DNFA_REG_CONFIG == STD_ON))
  uint8 LucNoOfRegs;
  #endif

  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  /* Implements PORT_ESDD_UD_118 */
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  volatile uint16 LusCount;
  LusCount = PORT_WORD_ZERO;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  #endif

  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  /*
  * Get the pointer to the details of DNFA Noise Elimination Registers
  */
  LpDNFAReg = Port_GpConfigPtr->pPortDNFARegs;

  /*
  * Get the count for total number of DNFA Noise Elimination Registers
  */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /*
    * Write the DNFAnCTL register value to the corresponding register
    */
    PORT_WRITE_REG_ONLY (
      &Port_GaaDnfaReg_BaseAddress[LpDNFAReg->usDNFARegAddrIndex]->ucCTL,
      LpDNFAReg->ucDNFACTL)
    PORT_CHECK_WRITE_VERIFY_INIT (
      &Port_GaaDnfaReg_BaseAddress[LpDNFAReg->usDNFARegAddrIndex]->ucCTL,
      (LpDNFAReg->ucDNFACTL), PORT_BYTE_MASK, PORT_FILTER_CONFIG_API_ID)
    /* Implements PORT_ESDD_UD_118 */
    #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)

    /*
    * Write the DNFAnEN register value to the corresponding register
    */
    PORT_WRITE_REG_ONLY (
      &Port_GaaDnfaReg_BaseAddress[LpDNFAReg->usDNFARegAddrIndex]->usEN,
      (LpDNFAReg->usDNFAEN))
    PORT_CHECK_WRITE_VERIFY_INIT (
      &Port_GaaDnfaReg_BaseAddress[LpDNFAReg->usDNFARegAddrIndex]->usEN,
      (LpDNFAReg->usDNFAEN), PORT_SHORT_MASK, PORT_FILTER_CONFIG_API_ID)

    while(LusCount < (LpDNFAReg->usDELAY))
    {
      ASM_NOP();
      LusCount++;
    }
    LusCount = PORT_WORD_ZERO;
    #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
    /* MISRA Violation: START Msg(4:0489)-7 */
    /*
    * Increment the pointer to get the value of next structure
    */
    LpDNFAReg++;
    /*
    * Decrement the count for total number of DNFA Registers
    */
    /* END Msg(4:0489)-7*/
    LucNoOfRegs--;

  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  /*
  * Get the pointer to the details of FCLA Noise Elimination Registers
  */
  LpFCLAReg = Port_GpConfigPtr->pPortFCLARegs;
  /*
  * Get the count for total number of FCLA Noise Elimination Registers
  */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfFCLARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /*
    * Write the FCLAnCTL register value to the corresponding register
    */
    PORT_WRITE_REG_ONLY (
      &Port_GpFclaReg_BaseAddress->ucCTLn_SIG[LpFCLAReg->usFCLARegOffset],
      LpFCLAReg->ucFCLACTL)
    PORT_CHECK_WRITE_VERIFY_INIT (
      &Port_GpFclaReg_BaseAddress->ucCTLn_SIG[LpFCLAReg->usFCLARegOffset],
      (LpFCLAReg->ucFCLACTL), PORT_BYTE_MASK, PORT_FILTER_CONFIG_API_ID)
    /* MISRA Violation: START Msg(4:0489)-7 */
    /*
    * Increment the pointer to get the value of next structure
    */
    LpFCLAReg++;
    /*
    * Decrement the count for total number of FCLA Registers */
    /* END Msg(4:0489)-7*/
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

} /* End of API Port_FilterConfig */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

#endif /*
* End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
* (PORT_FCLA_REG_CONFIG == STD_ON)
*/
/* Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049 */
/* Implements AR_PN0062_FR_0004, AR_PN0062_FR_0043, AR_PN0062_FR_0064 */
/*******************************************************************************
** Function Name         : Port_SetPinDefaultMode
**
** Service ID            : 0x07
**
** Description           : This function used to set the mode of a port pin
**                         during runtime. The PORT Driver module allows
**                         changing the mode of the pin to default mode set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinMode() should be invoked during runtime.
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : PMCSRn, JPMCSR0, PIPCn, PFCn, JPFC0, PFCEn, JPFCE0,
**                         PMSRn, JPMSR0, APMSRn, PFCAEn,
*******************************************************************************/
/* Implements PORT_ESDD_UD_138 */
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
(PORT_SET_PIN_MODE_API == STD_ON))

/* Implements PORT131, AR_PN0062_FR_0066 */
/* Implements SWS_Port_00131 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_150, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode (Port_PinType Pin)
{
  /*
  * Local pointer to get the setting for the pin mode changeable pins
  */
  P2CONST (volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
  LpModeChangeablePin;
  /*
  * Local variable to handle the register values
  */
  uint32 LulSRRegContent;
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  uint16 LusSRRegContent;
  uint16 LusInitMode;
  uint16 LusPIPCInitMode;
  #endif
  uint8 LucPortGroupIndex;
  uint8 LucPortRegIndex;
  uint16 LusPinPositionMask;

  /*
  * Local variable to identify the requirement of functional registers and PMSR
  */
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*
  * Variable to store the return value and Initialize the return value
  */
  Std_ReturnType LddReturnValue;

  /*
  * Initialize the return value
  */
  LddReturnValue = E_OK;
  #endif
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* MISRA Violation: START Msg(4:2982)-14 */
  LusInitMode = PORT_MODE_DIO;
  /* END Msg(4:2982)-14 */
  LusPIPCInitMode = PORT_MODE_DIO;
  #endif
  /* MISRA Violation: START Msg(4:2982)-14 */
  LpModeChangeablePin = NULL_PTR;
  /* END Msg(4:2982)-14 */
  /*
  * If DET is enabled, the API parameter checking shall be performed according
  * to the respective functions
  */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
    PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
    PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchChangeablePinDetail (Pin,
      &LucPortRegIndex, PORT_PIN_MODE_CHANGABLE);

    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if (NULL_PTR != LpModeChangeablePin)
    {
      /*
      * Identify the port group index from the hardware register structure
      */
      LucPortGroupIndex = LpModeChangeablePin->ucPortGroupIndex;
      LusPinPositionMask = LpModeChangeablePin->usPinPositionMask;

      /* If the Pin group is of Numeric type */
      /* Implements PORT_ESDD_UD_018 */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_NUMERIC == (LpModeChangeablePin->ucPortType &
                                                             PORT_PG_TYPE_MASK))
      {
      /* MISRA Violation: START Msg(4:0491)-10 */
        if (PORT_PMCSR_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
                                                          PORT_PMCSR_AVAILABLE))
      /* END Msg(4:0491)-10 */
        {
          /* MISRA Violation: START Msg(4:0491)-10 */
          /* MISRA Violation: START Msg(4:4461)- 4 */
          LusInitMode =
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].
                         ulInitModePMCSRRegVal) & (uint16)(LusPinPositionMask);
          /* END Msg(4:4461)- 4 */
          /* END Msg(4:0491)-10 */
          /*
          * Set the bit position in the upper 16 bits (31-16) of the PMCSR
          * variable to 1 of the configured pin whose Mode has to be changed
          */
          LulSRRegContent = ((uint32)(LusPinPositionMask)) <<
                                                        PORT_BIT_SHIFT_SIXTEEN;
          /*
          * Write the contents of Lower word of PMCSR variable into the PMCSR
          * register address
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          LulSRRegContent = (LulSRRegContent |
          ((Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].
                              ulInitModePMCSRRegVal) & (LusPinPositionMask)));
            /* END Msg(4:0491)-10 */
          /*
          * An atomic access to Microcontroller registers by the use of an
          * exclusive area
          */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

          /*
          * Write the contents of Lower word and upper word of PMCSR variable
          * into the PMCSR register address
          */
          PORT_WRITE_REG_ONLY (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
            LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMCSR,
            ((LulSRRegContent) &
                            ((uint32)(LusPinPositionMask))),
            ((uint32)(LusPinPositionMask)),
            PORT_SET_PIN_DEFAULT_MODE_SID)
          /* Implements PORT_ESDD_UD_023 */
          /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }
        else
        {
          /* No action required */
        }
        /*
        * Write PIPC register.Check for register availability
        */
        /* MISRA Violation: START Msg(4:0491)-10 */
        if (PORT_PIPC_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
                                                          PORT_PIPC_AVAILABLE))
        {
          /* Initial Mode of PIPC  */
          LusSRRegContent =
           (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].
                                  usInitModePIPCRegVal) & (LusPinPositionMask);
          /* END Msg(4:0491)-10 */
          LusPIPCInitMode = LusSRRegContent;

          /*
          * An atomic access to Microcontroller registers by the use of an
          * exclusive area
          */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
          /*
          * If bit needs to be set, OR the register contents with
          * sPin_Position_Mask
          */
          LusSRRegContent =
              (((Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC) &
              (uint16)(~(LusPinPositionMask))) |
              (LusSRRegContent));
          PORT_WRITE_REG_AND_MIRROR (
           &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
           LusSRRegContent, &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPIPC)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPIPC,
            (LusSRRegContent & (uint16)(LusPinPositionMask)),
            LusPinPositionMask,
            PORT_SET_PIN_DEFAULT_MODE_SID)
          /* Implements PORT_ESDD_UD_023 */
          /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        }   /* End of Write PIPC register */
        else
        {
          /* No action required */
        }
        /*
        * Check initial Mode of PortPin is DIO mode or alternative
        * mode in PMCSR Reg
        */
        if(PORT_MODE_DIO != LusInitMode)
        {
          /* Write PFCE register. Check for register availability */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFCE_AVAILABLE ==
             (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable
                                    & PORT_PFCE_AVAILABLE))
          {
            LusSRRegContent =
            (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].
                                   usInitModePFCERegVal) & (LusPinPositionMask);
            /* END Msg(4:0491)-10 */
            /*
            * If bit needs to be set, OR the register contents with
            * usPinPositionMask
            */
            LusSRRegContent =
                (((Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE) &
                (uint16)(~(LusPinPositionMask))) |
                (LusSRRegContent));
            
             /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
             /* Implements EAAR_PN0034_FR_0030 */
             /* Implements PORT_ESDD_UD_023 */
             /* Enter critical section */
             #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
             PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
             #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            PORT_WRITE_REG_AND_MIRROR (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
              LusSRRegContent,
              &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCE)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCE,
              (LusSRRegContent &
                                (uint16)(LusPinPositionMask)),
              (LusPinPositionMask),
              PORT_SET_PIN_DEFAULT_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
          } /* End of Write PFCE register */
          else
          {
            /* No action required */
          }

          /*
          * Write PFC register.Check for register availability
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFC_AVAILABLE ==
            (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable
                                 & PORT_PFC_AVAILABLE))
          {
            LusSRRegContent =
             (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].
                                  usInitModePFCRegVal) & (LusPinPositionMask);
            /* END Msg(4:0491)-10 */
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * If bit needs to be set, OR the register contents with
            * usPinPositionMask
            */
            LusSRRegContent =
                (((Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC) &
                (uint16)(~(LusPinPositionMask))) |
                (LusSRRegContent));

            PORT_WRITE_REG_AND_MIRROR (
             &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
             LusSRRegContent,
             &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFC)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
             &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFC,
             (LusSRRegContent & (uint16)(LusPinPositionMask)),
             (LusPinPositionMask),
             PORT_SET_PIN_DEFAULT_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          } /* End of Write PFC register */
          else
          {
            /* No action required */
          }

          /* Write PFCAE register.Check for register availability */
          /* MISRA Violation: START Msg(4:0491)-10 */
          if (PORT_PFCAE_AVAILABLE ==
          (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulRegListAvailable &
                                                          PORT_PFCAE_AVAILABLE))
          {
            LusSRRegContent =
              (Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex]
               .usInitModePFCAERegVal) & (LusPinPositionMask);
            /* END Msg(4:0491)-10 */
            
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * If bit needs to be set, OR the register contents with
            * usPinPositionMask
            */
            LusSRRegContent =
                (((Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE) &
                (uint16)(~(LusPinPositionMask))) |
                (LusSRRegContent));

            PORT_WRITE_REG_AND_MIRROR (
             &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
             LusSRRegContent,
             &Port_GstRamMirrorPortReg[LucPortGroupIndex].usPFCAE)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
             &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->usPFCAE,
             (LusSRRegContent & (uint16)(LusPinPositionMask)),
             (LusPinPositionMask),
             PORT_SET_PIN_DEFAULT_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
          } /* End of Write PFCAE register */
          else
          {
            /* No action required */
          }
          /*
          * Check I/O direction of pin direction is controlled by Port module or
          * peripheral function
          */
          if(PORT_MODE_DIO == LusPIPCInitMode)
          {
            /*
            * Set the bit position in the upper 16 bits (31-16) of the PMSR
            * variable to 1 of the configured pin whose Mode has to be changed
            */
            LulSRRegContent =
              ((uint32)(LusPinPositionMask)) << PORT_BIT_SHIFT_SIXTEEN;

            /*
            * Write the contents of Lower word of PMSR variable into the PMSR
            * register address
            */
            /* MISRA Violation: START Msg(4:0491)-10 */
            LulSRRegContent = LulSRRegContent |
              ((Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex]
                .ulInitModePMSRRegVal) & LusPinPositionMask);
            /* END Msg(4:0491)-10 */

            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * Write the contents of Lower word and upper word of PMSR variable
            * into the PMSR register address
            */
            PORT_WRITE_REG_ONLY (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
              (LulSRRegContent &
                ((uint32)(LusPinPositionMask))),
              ((uint32)(LusPinPositionMask)),
              PORT_SET_PIN_DEFAULT_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
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
      } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
      else
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        /* Implements PORT_ESDD_UD_020 */
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_JTAG == (LpModeChangeablePin->ucPortType &
                                                             PORT_PG_TYPE_MASK))
        {
          /*
          * Set the bit position in the upper 16 bits (31-16) of the JPMCSR
          * variable to 1 of the configured pin whose Mode has to be changed
          */
          LulSRRegContent = (uint32)(LusPinPositionMask) <<
                                                         PORT_BIT_SHIFT_SIXTEEN;

          /*
          * Write the contents of Lower word of JPMCSR variable into the JPMCSR
          * register address
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          LulSRRegContent = LulSRRegContent |
           ((Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].
                        ulInitModeJPMCSRRegVal) & (uint16)LusPinPositionMask);
          /* END Msg(4:0491)-10 */
          
          /*
          * An atomic access to Microcontroller registers by the use of an
          * exclusive area
          */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
          /*
          * Write the contents of Lower word and upper word of JPMCSR variable
          * into the JPMCSR register address
          */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMCSR,
                                                             LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GpJPortReg_BaseAddress->ulJPMCSR,
            (LulSRRegContent & (uint32)(LusPinPositionMask)),
            (uint32)(LusPinPositionMask),
            PORT_SET_PIN_DEFAULT_MODE_SID)
           /* Implements PORT_ESDD_UD_023 */
           /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
           /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
          /* MISRA Violation: START Msg(4:0491)-10 */
          /* MISRA Violation: START Msg(4:4461)-4*/
          LusInitMode =
          (Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].ulInitModeJPMCSRRegVal)
                                 & (uint16)LusPinPositionMask;
          /* END Msg(4:4461)-4*/
          /* END Msg(4:0491)-10 */
          /*
          * Check initial Mode of PortPin is DIO mode or alternative
          * mode in JPMCSR Reg
          */
          if(PORT_MODE_DIO != LusInitMode)
          {
            /* MISRA Violation: START Msg(4:0491)-10 */
            LusSRRegContent =
            (Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].
                                 usInitModeJPFCERegVal) & (LusPinPositionMask);
            /* END Msg(4:0491)-10 */
          
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * If bit needs to be set, OR the register contents
            * with usPinPositionMask
            */
            /* Implements AR_PN0062_FR_0025*/
            /* MISRA Violation: START Msg(4:1891)-11 */
            LusSRRegContent = (((Port_GpJPortReg_BaseAddress->ucJPFCE) &
                (uint8)(~(LusPinPositionMask))) |
                (LusSRRegContent));
            /* END Msg(4:1891)-11 */
            PORT_WRITE_REG_AND_MIRROR (&Port_GpJPortReg_BaseAddress->ucJPFCE,
              (uint8)LusSRRegContent, &Port_GstRamMirrorJPortReg.ucJPFCE)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GpJPortReg_BaseAddress->ucJPFCE,
              (LusSRRegContent & (uint8)(LusPinPositionMask)),
              (LusPinPositionMask),
              PORT_SET_PIN_DEFAULT_MODE_SID)

            /* End of Write JPFCE register */
          
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /* MISRA Violation: START Msg(4:0491)-10*/
            LusSRRegContent =
            (Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].usInitModeJPFCRegVal)
                                         & (LusPinPositionMask);
            /* END Msg(4:0491)-10*/
            
            /*
            * An atomic access to Microcontroller registers by the use of an
            * exclusive area
            */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
            * If bit needs to be set, OR the register contents
            * with usPinPositionMask
            */
            /* MISRA Violation: START Msg(4:1891)-11 */
            LusSRRegContent = (((Port_GpJPortReg_BaseAddress->ucJPFC) &
                (uint8)(~(LusPinPositionMask))) |
                (LusSRRegContent));
            /* END Msg(4:1891)-11 */
            PORT_WRITE_REG_AND_MIRROR (&Port_GpJPortReg_BaseAddress->ucJPFC,
              (uint8)LusSRRegContent,
              &Port_GstRamMirrorJPortReg.ucJPFC)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
              &Port_GpJPortReg_BaseAddress->ucJPFC,
              ((uint8)LusSRRegContent &
                (uint8)(LusPinPositionMask)),
              (uint8)(LusPinPositionMask),
              PORT_SET_PIN_DEFAULT_MODE_SID)
            /* End of Write JPFC register */
            
            /* Implements PORT_ESDD_UD_023 */
            /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          }
          else
          {
            /* No action required */
          }

          /*
          * Set the bit position in the upper 16 bits (31-16) of the JPMSR
          * variable to 1 of the configured pin whose Mode has to be changed
          */
          LulSRRegContent =
            ((uint32)(LusPinPositionMask)) << PORT_BIT_SHIFT_SIXTEEN;
          /*
          * Write the contents of Lower word of JPMSR variable into the PMSR
          * register address
          */
          /* MISRA Violation: START Msg(4:0491)-10 */
          LulSRRegContent = LulSRRegContent |
          ((Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].ulInitModeJPMSRRegVal)
                                        & LusPinPositionMask);
          /* END Msg(4:0491)-10 */
            
          /*
          * An atomic access to Microcontroller registers by the use of an
          * exclusive area
          */
          /* Implements EAAR_PN0034_FR_0030 */
          /* Implements PORT_ESDD_UD_023 */
          /* Enter critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
          
          /*
          * Write the contents of Lower word and upper word of JPMSR variable
          * into the PMSR register address
          */
          PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
                                                             LulSRRegContent)
          PORT_CHECK_WRITE_VERIFY_RUNTIME (
           &Port_GpJPortReg_BaseAddress->ulJPMSR,
           (LulSRRegContent & ((uint32)(LusPinPositionMask))),
           ((uint32)(LusPinPositionMask)),
           PORT_SET_PIN_DEFAULT_MODE_SID)
           /* Implements PORT_ESDD_UD_023 */
           /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
           /* Exit critical section */
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG */
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* Implements PORT_ESDD_UD_021 */
          #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType &
                                                             PORT_PG_TYPE_MASK))
          {
            /*
             * Set the bit position in the upper 16 bits (31-16) of the APMSR
             * variable to 1 of the configured pin whose Mode has to be changed
             */
            LulSRRegContent =
                ((uint32)(LusPinPositionMask)) << PORT_BIT_SHIFT_SIXTEEN;
            /*
             * Write the contents of Lower word of APMSR variable into the APMSR
             * register address
             */
            /* MISRA Violation: START Msg(4:0491)-10 */
            LulSRRegContent = LulSRRegContent |
                ((Port_GpConfigPtr->pPortAnalogRegs[LucPortRegIndex].
                     ulInitModeAPMSRRegVal) & LusPinPositionMask);
            /* END Msg(4:0491)-10 */
            
            /*
             * An atomic access to Microcontroller registers by the use of an
             * exclusive area
             */
            /* Implements EAAR_PN0034_FR_0030 */
            /* Implements PORT_ESDD_UD_023 */
            /* Enter critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            
            /*
             * Write the contents of Lower word and upper word of APMSR variable
             * into the APMSR register address
             */
            PORT_WRITE_REG_ONLY (
              &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
              LulSRRegContent)
            PORT_CHECK_WRITE_VERIFY_RUNTIME (
            &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
            (LulSRRegContent & ((uint32)(LusPinPositionMask))),
            ((uint32)(LusPinPositionMask)),
            PORT_SET_PIN_DEFAULT_MODE_SID)
            /* Implements PORT_ESDD_UD_023 */
            /* Exit critical section */
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON */
          } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_ANALOG */
          else
          {
            /* No action required */
          }
          #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
        }
      }
    }/*End of NULL_PTR != LpModeChangeablePin*/
    else
    {
      /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
      /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
        PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  } /* End of LddReturnValue == E_NOT_OK */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Port_SetPinDefaultMode */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
           (PORT_SET_PIN_MODE_API == STD_ON)) */

/* Implements AR_PN0062_FR_0004, AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name         : Port_SetPinDefaultDirection
**
** Service ID            : 0x08
**
** Description           : This service sets the port pin direction during
**                         runtime. The PORT Driver module allows changing the
**                         direction of the pin to configured direction set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be  initialized by calling Port_Init().
**                         Port_SetPinDirection() should be invoked during
**                         runtime.
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                         SchM_Exit_Port_PORT_REGISTER_PROTECTION,
**                         Port_SearchChangeablePinDetail.
**
** Registers Used        : PMSRn, JPMSR0, APMSRn.
*******************************************************************************/
/* Implements PORT_ESDD_UD_137 */
#if ((PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) && \
(PORT_SET_PIN_DIRECTION_API == STD_ON))

/* Implements PORT131, AR_PN0062_FR_0065 */
/* Implements SWS_Port_00131, PORT077, SWS_Port_00077 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_149, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection (Port_PinType Pin)
{
  P2CONST(volatile Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
  LpChangeablePinDet;
  uint32 LulSRRegContent;
  uint8 LucPortRegIndex;
  uint8 LucPortGroupIndex;
  uint16 LusPinPositionMask;
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LddReturnValue;

  /* Initialize the return value */
  LddReturnValue = E_OK;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  /* MISRA Violation: START Msg(4:2982)-14 */
  LpChangeablePinDet = NULL_PTR;
  /* END Msg(4:2982)-14 */

  /*
  * If DET is enabled, the API parameter checking shall be performed according
  * to the respective functions
  */

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Implements PORT077, SWS_Port_00077 */
  /* Check whether the PORT module is initialized */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */  
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
      PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
      PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LddReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchChangeablePinDetail (Pin,
      &LucPortRegIndex, PORT_PIN_DIR_CHANGABLE);

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR != LpChangeablePinDet)
    {
      LucPortGroupIndex = LpChangeablePinDet->ucPortGroupIndex;
      LusPinPositionMask = LpChangeablePinDet->usPinPositionMask;

      /* Get the base address of the corresponding Port Type */

      /*
      * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
      * variable to 1 of the configured pin whose Direction has to be changed
      */
      LulSRRegContent = ((uint32)(LusPinPositionMask)) <<
                                                         PORT_BIT_SHIFT_SIXTEEN;

      /*
      * Identify the port group index from the hardware register structure
      */
      LucPortRegIndex = LpChangeablePinDet->ucPortGroupIndex;
      /* Implements PORT_ESDD_UD_018 */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_NUMERIC == (LpChangeablePinDet->ucPortType &
                                                             PORT_PG_TYPE_MASK))
      {
        /*
        * An atomic access to Microcontroller registers
        * by the use of an exclusive area
        */
        /* Implements PORT_ESDD_UD_023 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*
        * Write the contents of Lower word of PMSR variable into the PMSR
        * register address
        */
        /* MISRA Violation: START Msg(4:0491)-10 */
        LulSRRegContent = LulSRRegContent |
         ((Port_GpConfigPtr->pPortNumRegs[LucPortRegIndex].ulInitModePMSRRegVal)
          & LusPinPositionMask);
        /* END Msg(4:0491)-10 */
        /*
        * Write the contents of Lower word and upper word of PMSR variable
        * into the PMSR register address
        */
        PORT_WRITE_REG_ONLY (
         &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
                                                                LulSRRegContent)
        PORT_CHECK_WRITE_VERIFY_RUNTIME (
          &Port_GaaPortReg_BaseAddress[LucPortGroupIndex]->ulPMSR,
          (LulSRRegContent & ((uint32)(LusPinPositionMask))),
          ((uint32)(LusPinPositionMask)),
          PORT_SET_PIN_DEFAULT_DIR_SID)
          /* Implements PORT_ESDD_UD_023 */
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      /* Implements PORT_ESDD_UD_020 */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_JTAG == (LpChangeablePinDet->ucPortType &
      PORT_PG_TYPE_MASK))
      {
        /*
        * An atomic access to Microcontroller registers
        * by the use of an exclusive area
        */
        /* Implements PORT_ESDD_UD_023 */
        /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*
        * Write the contents of Lower word of PMSR variable into the PMSR
        * register address
        */
        /* MISRA Violation: START Msg(4:0491)-10 */
        LulSRRegContent = LulSRRegContent |
          ((Port_GpConfigPtr->pPortJRegs[LucPortRegIndex].ulInitModeJPMSRRegVal)
            & LusPinPositionMask);
        /* END Msg(4:0491)-10 */
        /*
        * Write the contents of Lower word and upper word of PMSR variable
        * into the PMSR register address
        */
        PORT_WRITE_REG_ONLY (&Port_GpJPortReg_BaseAddress->ulJPMSR,
                                                              LulSRRegContent)
        PORT_CHECK_WRITE_VERIFY_RUNTIME (
          &Port_GpJPortReg_BaseAddress->ulJPMSR,
          (LulSRRegContent & ((uint32)(LusPinPositionMask))),
          ((uint32)(LusPinPositionMask)),
          PORT_SET_PIN_DEFAULT_DIR_SID)
          /* Implements PORT_ESDD_UD_023 */
          /* Implements EAAR_PN0034_FR_0030 */
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
      /* Implements PORT_ESDD_UD_021 */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_ANALOG == (LpChangeablePinDet->ucPortType &
                                                            PORT_PG_TYPE_MASK))
      {
        /*
        * An atomic access to Microcontroller registers by
        * the use of an exclusive area
        */
        /* Implements PORT_ESDD_UD_023 */
        /* Enter critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*
        * Write the contents of Lower word of PMSR variable into the PMSR
        * register address
        */
        /* MISRA Violation: START Msg(4:0491)-10 */
        LulSRRegContent = LulSRRegContent |
          ((Port_GpConfigPtr->pPortAnalogRegs[LucPortRegIndex].
              ulInitModeAPMSRRegVal) & LusPinPositionMask);
        /* END Msg(4:0491)-10 */
        /*
        * Write the contents of Lower word and upper word of PMSR variable
        * into the PMSR register address
        */
        PORT_WRITE_REG_ONLY (
          &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
          LulSRRegContent)
        PORT_CHECK_WRITE_VERIFY_RUNTIME (
          &Port_GaaAPortReg_BaseAddress[LucPortGroupIndex]->ulAPMSR,
          (LulSRRegContent & ((uint32)(LusPinPositionMask))),
          ((uint32)(LusPinPositionMask)),
          PORT_SET_PIN_DEFAULT_DIR_SID)
          /* Implements EAAR_PN0034_FR_0030 */
        /* Exit critical section */
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
    } /* End of NULL_PTR != LpChangeablePinDet */
    else
    {
     /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
     /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
        PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  } /* End of E_OK == LddReturnValue */

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetPinDefaultDirection */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* #if ((PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) && \
               (PORT_SET_PIN_DIRECTION_API == STD_ON)) */

/* Implements  EAAR_PN0034_FR_0051 */
/* Implements PORT133_Conf, ECUC_Port_00133 */
/*******************************************************************************
** Function Name      : Port_GetVersionInfo
**
** Service ID         : 0x03
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
** Output Parameters  : version info
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables Used : None
**
** Functions Invoked     : Det_ReportError.
**
** Registers Used        : None
*******************************************************************************/
/* Implements PORT_ESDD_UD_017 */
#if (PORT_VERSION_INFO_API == STD_ON)
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_075, PORT143, SWS_Port_00143 */
/* Implements PORT225, SWS_Port_00225, PORT102, PORT103, PORT144 */
/* Implements EAAR_PN0034_FR_0092 */
FUNC(void,PORT_PUBLIC_CODE) Port_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_CONST) versioninfo)
{
  if(NULL_PTR == versioninfo)
  {
    /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
    /* Implements PORT_ESDD_UD_014 */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET, if versioninfo pointer is equal to Null */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                               PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER);
    #endif /*#if(PORT_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Copy the vendor Id for AR4.0.3 and AR4.2.2 */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
  }
}
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif /* (PORT_VERSION_INFO_API == STD_ON) */

/* Implements AR_PN0062_FR_0043 */
/*******************************************************************************
** Function Name      : Port_CheckHWConsistency
**
** Service ID         : 0x09
**
** Description        : This service returns the status of hardware
**                      consistency check for Port module.
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
** Preconditions      : The Port Driver must be initialized first by calling
**                      API Port_Init().
**
** Global Variables   : Port_GaaPortReg_BaseAddress, Port_GstRamMirrorPortReg,
**                      Port_GaaAPortReg_BaseAddress, Port_GpConfigPtr,
**                      Port_GpJPortReg_BaseAddress, Port_GaaRamMirrorAPortReg,
**                      Port_GstRamMirrorJPortReg
**
** Functions Invoked  : Det_ReportError,
**                      SchM_Enter_Port_PORT_REGISTER_PROTECTION,
**                      SchM_Exit_Port_PORT_REGISTER_PROTECTION.
**
** Registers Used     : PISn, PIBCn, PIPCn, PUn, PDn, PBDCn, PFCEn, PFCn,
**                      PFCAEn, PODCn, PDSCn, PISAn, JPIS0, JPISA0, JPIBC0,
**                      JPU0, JPD0, JPBDC0, JPFCE0, JPFC0, JPODC0, JPDSC0,
**                      APIBCn, APBDCn, IPIBC0, DNFAnCTL, DNFAnEN, FCLA0CTLm.
*******************************************************************************/
/* Implements PORT_ESDD_UD_142 */
#if (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
/* Implements EAAR_PN0034_NR_0087, EAAR_PN0034_NR_0088 */
#include PORT_MEMMAP_FILE
/* Implements PORT_ESDD_UD_165, PORT_ESDD_UD_018, PORT_ESDD_UD_020 */
/* Implements EAAR_PN0034_FSR_0007 */
FUNC (Std_ReturnType,PORT_PUBLIC_CODE) Port_CheckHWConsistency
(Port_HWConsistencyCheckType CheckType)
{
  uint8 LucLoopCount;
  uint8 LucRegIndex;
  Std_ReturnType LddCheckStatus;
  #if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
  uint8 LucNoOfRegs;
  #endif
  /* Implements PORT_ESDD_UD_018 */
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  P2VAR(volatile PortReg, AUTOMATIC, PORT_APPL_CONST) LpPortRegBase;
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_APPL_CONST) LpPortReg;
  P2VAR(Port_NumRegRamMirror, AUTOMATIC, PORT_APPL_CONST) LpPortRegMirror;
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  /* Implements PORT_ESDD_UD_021 */
  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2VAR(volatile APortReg, AUTOMATIC, PORT_APPL_CONST) LpAPortRegBase;
  P2CONST(Port_AnalogRegs, AUTOMATIC, PORT_APPL_CONST) LpAPortReg;
  #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
  /* Implements PORT_ESDD_UD_020 */
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_JTAGRegs, AUTOMATIC, PORT_APPL_CONST) LpJPortReg;
  #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  /*
  * Pointer to digital filter DNFA register data structure
  */
  P2CONST(volatile Port_DNFARegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFAReg;
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */
  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  /*
  * Pointer to analog filter FCLA register data structure
  */
  P2CONST(volatile Port_FCLARegs, AUTOMATIC, PORT_CONFIG_DATA) LpFCLAReg;
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */
  #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
  P2CONST(Port_IPortRegs, AUTOMATIC, PORT_APPL_CONST) LpIPortReg;
  #endif
  LddCheckStatus = E_OK;
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  LpPortReg = Port_GpConfigPtr->pPortNumRegs;
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  LpAPortReg = Port_GpConfigPtr->pPortAnalogRegs;
  #endif /* End of PPORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  LpJPortReg = Port_GpConfigPtr->pPortJRegs;
  #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
  /* Implements PORT077 */
  /* Implements SWS_Port_00077 */
  /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
  /* Implements PORT_ESDD_UD_014 */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the PORT module is initialized */
  /* QAC Warning: START Msg(2:3416)-19 */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  /* END Msg(2:3416)-19 */
  {
    /* Implements PORT051, PORT146 */
    /* Implements SWS_Port_00051, SWS_Port_00146 */
    /* Report to DET  */
    (void) Det_ReportError (PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_CHECK_HW_CONISTENCY_SID,
                            PORT_E_UNINIT);
    LddCheckStatus = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON*/
  {
    if (PORT_HW_CONSIST_CHECK_STATIC == CheckType)
    {
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Hardware Consistency Check for Numerical Port registers */
      for (LucLoopCount = PORT_ZERO; (E_OK == LddCheckStatus) &&
        (LucLoopCount < Port_GpConfigPtr->ucNoOfPortNumRegs); LucLoopCount++)
      {
        LucRegIndex = LpPortReg->ucPortIndex;
        LpPortRegBase = Port_GaaPortReg_BaseAddress[LucRegIndex];
        if ((LpPortRegBase->usPU != LpPortReg->usInitModePURegVal) ||
            (LpPortRegBase->usPD != LpPortReg->usInitModePDRegVal) ||
            (LpPortRegBase->usPIS != LpPortReg->usInitModePISRegVal) ||
            #if (PORT_PISA_REG_AVAILABLE == STD_ON)
            ((PORT_PISA_AVAILABLE ==
            (LpPortReg->ulRegListAvailable & PORT_PISA_AVAILABLE)) &&
            (LpPortRegBase->usPISA != LpPortReg->usInitModePISARegVal)) ||
            #endif /* End of PORT_PISA_REG_AVAILABLE == STD_ON*/
            (LpPortRegBase->usPIBC != LpPortReg->usInitModePIBCRegVal) ||
            (LpPortRegBase->ulPODC != (LpPortReg->ulInitModePODCRegVal
                                                   & (~PORT_MSB_MASK))) ||
            ((PORT_PDSC_AVAILABLE ==
            (LpPortReg->ulRegListAvailable & PORT_PDSC_AVAILABLE)) &&
            (LpPortRegBase->ulPDSC != (LpPortReg->ulInitModePDSCRegVal &
                                                    (~PORT_MSB_MASK)))) ||
            (LpPortRegBase->usPBDC != LpPortReg->usInitModePBDCRegVal))
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        /* MISRA Violation: START Msg(4:0489)-7 */
        LpPortReg++;
        /* END Msg(4:0489)-7*/
      }
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON*/
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Hardware Consistency Check for Analog Port registers */
      for (LucLoopCount = PORT_ZERO; (E_OK == LddCheckStatus) &&
          (LucLoopCount < Port_GpConfigPtr->ucNoOfPortAnalogRegs);
          LucLoopCount++)
      {
        LucRegIndex = LpAPortReg->ucPortIndex;
        LpAPortRegBase = Port_GaaAPortReg_BaseAddress[LucRegIndex];
        if ((LpAPortRegBase->usAPIBC != LpAPortReg->usInitModeAPIBCRegVal) ||
            (LpAPortRegBase->usAPBDC != LpAPortReg->usInitModeAPBDCRegVal))
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        /* MISRA Violation: START Msg(4:0489)-7 */
        LpAPortReg++;
        /* END Msg(4:0489)-7*/
      }
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON*/
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Hardware Consistency Check for Jtag Port */
      if ((Port_GpJPortReg_BaseAddress->ucJPU !=
              (uint8)LpJPortReg->usInitModeJPURegVal) ||
          (Port_GpJPortReg_BaseAddress->ucJPD !=
              (uint8)LpJPortReg->usInitModeJPDRegVal) ||
          (Port_GpJPortReg_BaseAddress->ucJPIS !=
              (uint8)LpJPortReg->usInitModeJPISRegVal) ||
          (Port_GpJPortReg_BaseAddress->ucJPISA !=
              (uint8)LpJPortReg->usInitModeJPISARegVal) ||
          (Port_GpJPortReg_BaseAddress->ucJPIBC !=
              (uint8)LpJPortReg->usInitModeJPIBCRegVal) ||
          (Port_GpJPortReg_BaseAddress->ulJPODC !=
              (LpJPortReg->ulInitModeJPODCRegVal & (~PORT_MSB_MASK))) ||
          (Port_GpJPortReg_BaseAddress->ulJPDSC !=
              (LpJPortReg->ulInitModeJPDSCRegVal & (~PORT_MSB_MASK))) ||
          (Port_GpJPortReg_BaseAddress->ucJPBDC !=
              (uint8)LpJPortReg->usInitModeJPBDCRegVal))
      {
        LddCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid Misra violation */
      }
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON*/
      #if (PORT_DNFA_REG_CONFIG == STD_ON)
      /*
       * Get the pointer to the details of DNFA Noise Elimination Registers
       */
      LpDNFAReg = Port_GpConfigPtr->pPortDNFARegs;
      for (LucNoOfRegs = PORT_ZERO; (E_OK == LddCheckStatus) &&
          (LucNoOfRegs < Port_GpConfigPtr->ucNoOfDNFARegs); LucNoOfRegs++)
      {
        /* MISRA Violation: START Msg(4:4461)-4 */
        LucRegIndex = LpDNFAReg->usDNFARegAddrIndex;
        /* END Msg(4:4461)-4 */
        if (Port_GaaDnfaReg_BaseAddress[LucRegIndex]->ucCTL !=
                                                          LpDNFAReg->ucDNFACTL)
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        /* Implements PORT_ESDD_UD_118 */
        #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
        if (Port_GaaDnfaReg_BaseAddress[LucRegIndex]->usEN !=
                                                           LpDNFAReg->usDNFAEN)
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON*/
        /* MISRA Violation: START Msg(4:0489)-7 */
        LpDNFAReg++;
        /* END Msg(4:0489)-7*/
      }
      #endif /* End of (PORT_DNFA_REG_CONFIG == STD_ON)*/
      #if (PORT_FCLA_REG_CONFIG == STD_ON)
      /*
      * Get the pointer to the details of FCLA Noise Elimination Registers
      */
      LpFCLAReg = Port_GpConfigPtr->pPortFCLARegs;
      for (LucNoOfRegs = PORT_ZERO; (E_OK == LddCheckStatus) &&
          (LucNoOfRegs < Port_GpConfigPtr->ucNoOfFCLARegs); LucNoOfRegs++)
      {
        /* MISRA Violation: START Msg(4:4461)-4 */
        LucRegIndex = LpFCLAReg->usFCLARegOffset;
        /* END Msg(4:4461)-4 */
        if (Port_GpFclaReg_BaseAddress->ucCTLn_SIG[LucRegIndex] !=
                                                          LpFCLAReg->ucFCLACTL)
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        /* MISRA Violation:START Msg(4:0489)-7 */
        LpFCLAReg++;
        /* END Msg(4:0489)-7*/
      }
      #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON*/
      #if(PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
      LpIPortReg = Port_GpConfigPtr->pPortInputRegs;
      /* Hardware Consistency Check for Input registers */
      if (Port_GpIPortReg_BaseAddress->usIPIBC !=
                                            LpIPortReg->usInitModeIPIBCRegVal)
      {
        LddCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid Misra violation */
      }
      #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
    }
    else if (PORT_HW_CONSIST_CHECK_DYNAMIC == CheckType)
    {
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Implements EAAR_PN0034_FR_0030 */
      /* Implements PORT_ESDD_UD_023 */
      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      /* Hardware Consistency Check for Numerical Port Registers */
      for (LucLoopCount = PORT_ZERO; (E_OK == LddCheckStatus) &&
          (LucLoopCount < Port_GpConfigPtr->ucNoOfPortNumRegs); LucLoopCount++)
      {
        LucRegIndex = LpPortReg->ucPortIndex;
        LpPortRegBase = Port_GaaPortReg_BaseAddress[LucRegIndex];
        LpPortRegMirror = &Port_GstRamMirrorPortReg[LucRegIndex];
        if (((PORT_REG_AVAILABLE !=
                     (LpPortReg->ulRegListAvailable & PORT_PIPC_AVAILABLE)) &&
             (LpPortRegBase->usPIPC != LpPortRegMirror->usPIPC)) ||
            ((PORT_REG_AVAILABLE !=
                     (LpPortReg->ulRegListAvailable & PORT_PFCE_AVAILABLE)) &&
             (LpPortRegBase->usPFCE != LpPortRegMirror->usPFCE)) ||
            ((PORT_REG_AVAILABLE !=
                     (LpPortReg->ulRegListAvailable & PORT_PFC_AVAILABLE)) &&
             (LpPortRegBase->usPFC != LpPortRegMirror->usPFC)) ||
            ((PORT_REG_AVAILABLE !=
                     (LpPortReg->ulRegListAvailable & PORT_PFCAE_AVAILABLE)) &&
             (LpPortRegBase->usPFCAE != LpPortRegMirror->usPFCAE)))
        {
          LddCheckStatus = E_NOT_OK;
        }
        else
        {
          /* To avoid Misra violation */
        }
        /* MISRA Violation: START Msg(4:0489)-7 */
        LpPortReg++;
        /* END Msg(4:0489)-7*/
      }
      /* Implements PORT_ESDD_UD_023 */
      /* Implements EAAR_PN0034_FR_0030 */   
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON*/
      
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Implements EAAR_PN0034_FR_0030 */
      /* Implements PORT_ESDD_UD_023 */
      /* Enter critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
        
        /* Hardware Consistency Check for Jtag Port */
      if ((Port_GpJPortReg_BaseAddress->ucJPFCE !=
       Port_GstRamMirrorJPortReg.ucJPFCE) ||
      (Port_GpJPortReg_BaseAddress->ucJPFC != Port_GstRamMirrorJPortReg.ucJPFC))
      {
        LddCheckStatus = E_NOT_OK;
      }
      else
      {
        /* To avoid Misra violation */
      }
    
      /* Implements PORT_ESDD_UD_023 */
      /* Implements EAAR_PN0034_FR_0030 */
      /* Exit critical section */
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_REGISTER_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON*/

    }
    else
    {
      /* Implements PORT051, PORT146 */
      /* Implements SWS_Port_00051, SWS_Port_00146 */
      /* Report to DET  */
      /* Implements PORT100, PORT211, PORT123_Conf, ECUC_Port_00123 */
      /* Implements PORT_ESDD_UD_014 */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      (void) Det_ReportError(PORT_MODULE_ID,
                             PORT_INSTANCE_ID,
                             PORT_CHECK_HW_CONISTENCY_SID,
                             PORT_E_INVALID_CHECKTYPE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON*/
      LddCheckStatus = E_NOT_OK;
    }
  }
  return LddCheckStatus;
}
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE
#endif  /*(PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)*/
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
