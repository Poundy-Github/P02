/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_LLDriver.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low Level function implementations of ICU Driver        */
/* Component                                                                  */
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
 * V1.0.0:  16-Sep-2015  : Initial Version.
 * V1.0.1:  12-Nov-2015  : 1.As part of JIRA #ARDAAGA-78,following changes are
 *                         made,
 *                          a.A check is added for the checking of current
 *                            wakeupstatus and notification in Icu_HW_SetMode
 *                            API.
 *                          b.Local variable 'LulWakeupSourceVal' is passed as
 *                            parameter to EcuM_CheckWakeup function in the APIs
 *                            Icu_TimerIsr and Icu_ExternalInterruptIsr.
 *                         2. As part of JIRA #ARDAAGA-87, prefix of module
 *                            name is added to variables to avoid conflict
 *                            between different modules.
 *                         3. As part of JIRA #ARDAAGA-100, wakeup factor
 *                            registers are added and checked for its correct
 *                            generation.
 * V1.0.2:  10-Jun-2016  : JIRA #ARDAABD-426
 *                         1. Wakeup source types updated to
 *                            Ecum_WakeupSourceType;
 *                         2. Removed bit shifting from wakeup sources
 *                            (Autosar 4.0.3 Ecum4040)
 * V1.0.3:  13-Jun-2016  : JIRA #ARDAABD-499
 *                         1. Used uiChannelMeasurementRunning to indicate
 *                            that channel measurement is turned on
 * V1.0.4:  04-Jul-2016  : JIRA #ARDAABD-395
 *                         1. Added ICU_TAUB_UNIT_CONFIG
 * V1.0.5:  15-Jul-2016  : JIRA #ARDAABD-404
 *                         1. Removed output registers from function headers
 *                         2. Replaced TISLTA0m with SELB_TAUD0 in function
 * V1.0.6:  22-Jul-2016  : JIRA #ARDAABD-639
 *                         1. Corrected clearing of the overflow flag in
 *                            Icu_DeInit()
 * V1.0.7:  10-Aug-2016  : JIRA #ARDAABD-583
 *                         1. Removed LpChannelConfig from function parameters
 *                            (Icu_HW_EdgeCountingInit, Icu_HW_TimestampInit)
 *                         2. Added / remove used registers from function
 *                            header comment (Icu_HW_StartCountMeasurement,
 *                            Icu_HW_StopCountMeasurement,
 *                            Icu_HW_EnableEdgeDetection)
 * V1.0.8:  16-Aug-2016  : JIRA #ARDAABD-583
 *                         1. Removed LpChannelConfig from function header
 *                            comments
 *                            (Icu_HW_EdgeCountingInit, Icu_HW_TimestampInit)
 *                         2. Removed SELB_TAUJI0 from comments
 *                            because previous input is not supported for TAUJ
 *                         3. Replaced TISLTAn with SELB_TAUD0 in comments
 * V1.0.9:  12-Sep-2016  : JIRA #ARDAABD-666
 *                         1. Corrected copyright information
 *                         2. Modified macro RH850_SV_MODE_ICR_AND to 16 bit
 *                            access
 * V1.1.0:  12-Sep-2016  : JIRA #ARDAABD-661
 *                         1. Added interrupt disabling for edge detection
 *                            in Icu_HWInit()
 * V2.0.0:  30-Sep-2016  : #ARDAABD-841
 *                         1. Removed ASR 3.2.2
 *                         2. Updated copyright
 *                         3. Updated to 4.2.2
 * V2.0.1:  03-Oct-2016  : #ARDAABD-716
 *                         1. Added check to EcuM wakeup reporting,
 *                            in case no wakeup source is configured, in
 *                            Icu_TimerIsr() and Icu_ExternalInterruptIsr()
 * V2.0.2:  24-Nov-2016  : #ARDAABD-617
 *                         1. Corrected FuSa after functional tests
 * V2.0.3:  25-Nov-2016  : #ARDAABD-404
 *                         1. Correct register list in function headers
 * V2.0.4:  26-Nov-2016  : #ARDAABD-841
 *                         1. Removed function Icu_HW_Clr_Pnd_Intr used in
 *                            ASR3.2.2 implementation
 *                         2. Added volatile keyword to pPreviousInputCntlRegs
 *                         3. Removed Edge Counter measurement for TAUJ
 *                            channels in function Icu_HW_Init()
 * V2.0.5:  06-Dec-2016  : #ARDAABD-583
 *                         1. Replaced LucChannelIdx with LucCnt
 *                         2. Replaced LucSid with ICU_INIT_SID in Icu_HW_Init
 *                         3. CMUR register is set to 0 in Icu_DeInit()
 *                         4. Optimized FCLA write value
 *                         5. Replaced FCLA write method with
 *                            ICU_FCLA_WRITE_REG_AND_MIRROR method
 *                         6. Optimized checking of TE register after TS and
 *                            TT have been written
 *                         7. Removed CDR ram mirror
 *                         8. Replaced ICU_E_PARAM_VALUE with
 *                            DET_ICU_E_PARAM_VALUE for Icu_CheckRamMirror
 * V2.0.6:  12-Dec-2016  : #ARDAABD-583
 *                         1. Replaced ICU_MASK_FIRST_16_BITS with the
 *                            configured channel mask for TE, TT registers
 *                         2. Replaced macros for Mask the bypass bits to have
 *                            the suffix FILTER (ex: ICU_BYPASS_FILTER)
 * V2.0.7:  14-Dec-2016  : #ARDAABD-404
 *                         1. Minor corrections, updated used register list
 * V2.0.8:  19-Jan-2017  : #ARDAABD-570
 *                         1. In Icu_DeInit(), CSC is written before CMOR is
 *                            cleared
 * V2.0.9:  23-Jan-2017  : #ARDAABD-570
 *                         1. In Icu_DeInit(), Icu_Init(), CSC is written or
 *                            cleared only for Signal Measurement mode
 * V2.0.10: 25-Jan-2017  : #ARDAABD-570
 *                         1. In Icu_HWCheckConsistency(), added a check for
 *                            LpTAUUnitConfig->uiConfigurePrescaler, so
 *                            ICU_STATIC check is done only for timer units
 *                            which configure prescaler
 * V2.0.11: 27-Jan-2017  : #ARDAABD-570
 *                         1. In Icu_HWCheckConsistency(), added a check for
 *                            ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType,
 *                            so the BRS register is written only for TAUD
 *                            and not for TAUB since TAUB does not have BRS
 * V2.0.12: 30-Jan-2017  : #ARDAABD-830
 *                         1. Minor QAC fixes
 * V2.0.13: 31-Jan-2017  : #ARDAABD-830
 *                         1. Initialized LenMeasurementMode in Icu_HW_DeInit
 * V2.0.14: 02-Feb-2017  : #ARDAABD-583
 *                         1. Initialzed pBufferPointer to NULL_PTR in
 *                            Icu_HW_TimestamInit()
 * V2.0.15: 16-Mar-2017  : #ARDAABD-1206
 *                         1. Added Tracability
 * V2.0.16: 11-Jul-2017  : 1. As part of Jira #ARDAABD-1373,
 *                            Icu_ExternalInterruptIsr API has been updated to
 *                            add wakeup support for INTP16 to INTP23 and
 *                            TAUJ2 units.
 *                         2. As part of Jira #ARDAABD-1921,
 *                            Icu_TimerIsr is updated to set the flag
 *                            uiResultComplete to ICU_TRUE.
 *                         3. As part of Jira #ARDAABD-1611, use of MemMap.h
 *                            has been replaced with macro ICU_MEMMAP_FILE.
 *                         4. As part of Jira #ARDAABD-1913, Critical section
 *                            usage from the Icu_HW_Init and Icu_HW_DeInit
 *                            API's has been removed.
 * V2.0.17: 19-Sep-2017  : 1. As part of Jira #ARDAABD-2444,
 *                            naming convention for variables and macros
 *                            updated.
 *                         2. As part of Jira #ARDAABD-2419,
 *                            SV mode writable register access with SYNCP has
 *                            been replaced with RH850_SV_CLEAR_ICR_SYNCP
 *                         3. As part of Jira #ARDAABD-2275,
 *                            Icu_HW_StartCountMeasurement has been updated to
 *                            set the value of uiResultComplete as 'FALSE'.
 *                         4. As part of Jira #ARDAABD-2425, QAC WARNING has
 *                            been added.
 *                         5. As part of Jira #ARDAABD-2571, Removed space
 *                            in between unary operators
 * V2.0.18: 04-Jul-2018  : Following changes are made:
 *                         1. As part of merging activity, #ARDAABD-3476
 *                            a. Used ICR access instead of IMR for the enabling
 *                               and disabling of interrupts.Ref:ARDAABD-2158
 *                            b. QAC warnings are added and violations are
 *                               justified.
 *                            c. Copyright information is updated.
 *                         2. Registers Used field in function banners is
 *                            updated for APIs Icu_HW_Init,
 *                            Icu_HW_DisableEdgeDetection,
 *                            Icu_HW_SynchronousStart,Icu_HW_SynchronousStop,
 *                            Icu_HWCheckConsistency. Ref: ARDAABD-3626
 *                         3. Critical section protection is added while
 *                            writing to members of Icu_GpChannelRamData.
 *                            Ref: ARDAABD-3299
 *                         4. QAC warning is justified.
 *                         5. MISRA C rule violation tag for QAC message
 *                            Msg(4:0316) is removed since it is not violated in
 *                            code.
 *                         6. As per JIRA ticket ARDAABD-3843,
 *                            added traceability tags for Reqtify coverage
 *                            improvement.
 * V2.0.19: 12-Aug-2019  : Following changes are made:
 *                         1. Replace the condition check '(ICU_ONE ==
 *                            LpTAUUnitConfig->uiConfigurePrescaler)'
 *                            with '(ICU_TRUE ==
 *                            LpTAUUnitConfig->blConfigurePrescaler)'.
 *                            Ref:ARDAABD-3442
 *                         2. Service ID of Icu_HWCheckConsistency() API in
 *                            comments is changed from 0x0F to None.
 *                            Ref:ARDAABD-4331
 *                         3. Critical sections in follow functions are
 *                            deleted: Icu_TimerIsr, 
 *                            Icu_ServiceSignalMeasurement,
 *                            Icu_ServiceTimestamp and Icu_ExternalInterruptIsr.
 *                            Ref:ARDAABD-4440
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for the macro declaration of supervisor mode(SV) write enabled
* Registers ICxxx
*/
#include "rh850_Types.h"
#include "Iocommon_Defines.h"
/* Included for module version information and other types declarations */
#include "Icu.h"
/* Included for Header file inclusion */
#include "Icu_LLDriver.h"
/* Included for RAM variable declarations */
#include "Icu_Ram.h"
/* Included for ICU_WRITE_VERIFY_ERROR_INTERFACE callback */
/* Implements: SWS_Icu_00250, ICU250 */
#include "Icu_Cbk.h"
/* Included for FuSa */
#include "Icu_RegWrite.h"
/*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0021*/
#if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Icu.h"
#endif


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define ICU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
                                             ICU_AR_RELEASE_MAJOR_VERSION_VALUE
#define ICU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
                                             ICU_AR_RELEASE_MINOR_VERSION_VALUE
#define ICU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
                                          ICU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define ICU_LLDRIVER_C_SW_MAJOR_VERSION    ICU_SW_MAJOR_VERSION_VALUE
#define ICU_LLDRIVER_C_SW_MINOR_VERSION    ICU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ICU_LLDRIVER_AR_RELEASE_MAJOR_VERSION != \
                                        ICU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (ICU_LLDRIVER_AR_RELEASE_MINOR_VERSION != \
                                        ICU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (ICU_LLDRIVER_AR_RELEASE_REVISION_VERSION != \
                                     ICU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (ICU_LLDRIVER_SW_MAJOR_VERSION != ICU_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (ICU_LLDRIVER_SW_MINOR_VERSION != ICU_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Macro for register masks */
#define ICU_MASK_FIRST_16_BITS          (uint16)0xFFFF
#define ICU_MASK_FIRST_2_BITS           (uint8) 0x03
#define ICU_MASK_FIRST_BIT              (uint8) 0x01
#define ICU_MASK_FIRST_32_BITS          (uint32)0xFFFFFFFFUL
#define ICU_MASK_FIRST_3_BITS           (uint8) 0x07
#define ICU_MASK_FIRST_4_BITS           (uint8) 0x0F
#define ICU_MASK_FIRST_8_BITS           (uint8) 0xFF

/* Simplify macro for TAUD and TAUB since they are used togheter */
#if ((ICU_TAUB_UNIT_USED == STD_ON) || (ICU_TAUD_UNIT_USED == STD_ON))
  #define ICU_TAUDB_UNIT_USED STD_ON
#else
  #define ICU_TAUDB_UNIT_USED STD_OFF
#endif

#if ((ICU_TAUDB_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON))
  #define ICU_TAUDBJ_UNIT_USED STD_ON
#else
  #define ICU_TAUDBJ_UNIT_USED STD_OFF
#endif

#if ((ICU_TAUB_UNIT_CONFIG == STD_ON) || (ICU_TAUD_UNIT_CONFIG == STD_ON))
  #define ICU_TAUDB_UNIT_CONFIG STD_ON
#else
  #define ICU_TAUDB_UNIT_CONFIG STD_OFF
#endif

#if ((ICU_TAUDB_UNIT_CONFIG == STD_ON) || (ICU_TAUJ_UNIT_CONFIG == STD_ON))
  #define ICU_TAUDBJ_UNIT_CONFIG STD_ON
#else
  #define ICU_TAUDBJ_UNIT_CONFIG STD_OFF
#endif

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
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To access channel parameters in an optimized approach.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-2 and                           */
/*                 END Msg(4:0488)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Type casting  is used to make simple and avoid             */
/*                 extra variables.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration.                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-4 and                           */
/*                 END Msg(4:0491)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2983) Assignment is redundant. The value of this object */
/*                 is never subsequently used.                                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The object is used under different pre-compile sections.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-5  and                          */
/*                 END Msg(4:2983)-5  tags in the code.                       */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317) [I] Implicit conversion from a pointer to void to */
/*                 a pointer to object type.                                  */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-6 and                           */
/*                 END Msg(4:0317)-6 tags in the code.                        */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2877) [I] This loop will never be executed more than    */
/*                 once.                                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This warning occurs when only one channel is been          */
/*                 configured and the for loop is required when more than     */
/*                 one channel is configured.                                 */
/* Verification  : This part of the code is verified by configuring more than */
/*                 one channel.                                               */
/* Reference     : Look for START Msg(4:2877)-7 and                           */
/*                 END Msg(4:2877)-7 tags in the code.                        */

/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3138)Null statement is located close to other code      */
/*                 or comments                                                */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-8 and                           */
/*                 END Msg(4:3138)-8 tags in the code.                        */

/******************************************************************************/
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       :  (4:4471) Definite: A non-constant expression of           */
/*                  'essentially unsigned' type (unsigned char) is            */
/*                  being passed to a function parameter of wider             */
/*                  unsigned type, 'unsigned long'.                           */
/* Rule          :  MISRA-C:2004 Rule 10.1                                    */
/* Justification :  Variables are passed by pass by value method              */
/* Verification  :  However, part of the code is verified manually  and it is */
/*                  not having any impact.                                    */
/* Reference     :  Look for START Msg(4:4471)-9 and                          */
/*                  END Msg(4:4471)-9 tags in the code.                       */

/******************************************************************************/
/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004                                               */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex bitwise*/
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-10 and                          */
/*                 END Msg(4:4397)-10 tags in the code.                       */

/******************************************************************************/
/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation will never be true    */
/*                 for this configuration because number of timer channels is */
/*                 the same as total number of channels. The error is not     */
/*                 observed for configurations where external interrupt       */
/*                 channels are configured.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-11 and                          */
/*                 END Msg(4:2996)-11 tags in the code.                       */

/******************************************************************************/
/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       :(4:2994) The value of this 'while' or 'for' loop            */
/*                 controlling expression is always 'false'. The loop will    */
/*                 not be entered.                                            */
/* Rule          :                                                            */
/* Justification : The loop will not be entered  for this configuration       */
/*                 because number of timer channels is the same as total      */
/*                 number of channels. The error is not  observed for         */
/*                 configurations where external interrupt channels           */
/*                 are configured.                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2994)-12 and                          */
/*                 END Msg(4:2994)-12 tags in the code.                       */

/******************************************************************************/
/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : The code can be accessed if the logical conditional check  */
/*                 in which this is found is true. Code may or may not be     */
/*                 accessible depending on the pre compile value used in the  */
/*                 logical condition.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-13 and                          */
/*                 END Msg(4:2880)-13 tags in the code.                       */

/******************************************************************************/
/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used in order to typecast to different     */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-14 and                          */
/*                 END Msg(4:0303)-14 tags in the code.                       */

/******************************************************************************/
/* 15.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2991)This assignment is redundant. The value of this    */
/*                  object is never used before being modified.               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The Warning Occurs only if user configures one HW unit.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-15 and                          */
/*                 END Msg(4:2991)-15 tags in the code.                       */

/******************************************************************************/
/* 16.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2995)This assignment is redundant. The value of this    */
/*                  object is never used before being modified.               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The Warning Occurs only if user configures one HW unit.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-16 and                          */
/*                 END Msg(4:2995)-16 tags in the code.                       */

/******************************************************************************/
/* 17.  MISRA C RULE VIOLATION:                                               */
/* Message       : (4:2962)Apparent: Using value of uninitialized automatic   */
/*                  object.                                                   */
/* Rule          : MISRA-C:2004 Rule 9.1                                      */
/* Justification : For Non-TAU unit register it will show uninitialized.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2962)-17 and                          */
/*                 END Msg(4:2962)-17 tags in the code.                       */

/******************************************************************************/
/* 18. QAC Warning:                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : MISRA-C:2004 Message 2814                                  */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-18 and                          */
/*                 END Msg(2:2814)-18 tags in the code.                       */

/******************************************************************************/
/* 19. QAC Warning:                                                           */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                  to another type                                           */
/* Rule          : MISRA-C:2004 Message 3892                                  */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                  the post build configuration                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-19 and                          */
/*                 END Msg(2:3892)-19 tags in the code.                       */

/******************************************************************************/
/* 20. QAC Warning:                                                           */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : MISRA-C:2004 Message 2824                                  */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-20 and                          */
/*                 END Msg(2:2824)-20 tags in the code.                       */

/******************************************************************************/
/* 21. QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include                    */
/*                 preprocessing directive.                                   */
/* Rule          : MISRA-C:2004 Message 0832                                  */
/* Justification : Required for inclusion of ASR version specific,MemMap file */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-21 and                          */
/*                 END Msg(2:0832)-21 tags in the code.                       */

/******************************************************************************/
/* 22. QAC Warning:                                                           */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : MISRA-C:2004 Message 3227                                  */
/* Justification : The function parameters of AUTOSAR  and vendor             */
/*                 specific Api's cannot be modified to be made as constant.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-22 and                          */
/*                 END Msg(2:3227)-22 tags in the code.                       */

/******************************************************************************/
/* 23. QAC Warning:                                                           */
/* Message       : (2:4342) An expression of 'essentially unsigned' type      */
/*                 (unsigned char) is being cast to enum type                 */
/* Rule          : MISRA-C:2004 Message 4342                                  */
/* Justification : This implicit conversion is done to access the global data */
/*                 with different data type to enum type since the size of    */
/*                 variable should be declared  before using it.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:4342)-23 and                          */
/*                 END Msg(2:4342)-23 tags in the code.                       */

/******************************************************************************/
/* 24. QAC Warning:                                                           */
/* Message       : (2:2204) An expression of 'essentially unsigned' type      */
/*                 (unsigned char) is being cast to enum type                 */
/* Rule          : MISRA-C:2004 Message 4342                                  */
/* Justification : This switch case label is not aligned with the controlling */
/*                 switch statement.                                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2204)-24 and                          */
/*                 END Msg(2:2204)-24 tags in the code.                       */

/******************************************************************************/
/* 25. QAC Warning:                                                           */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Rule          : MISRA-C:2004 Message 2016                                  */
/* Justification : The 'default' clause in this 'switch' statement contains   */
/*                 no executable code.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-25 and                          */
/*                 END Msg(2:2016)-25 tags in the code.                       */

/******************************************************************************/
/* 26. QAC Warning:                                                           */
/* Message       : (2:3206) This 'switch' statement 'default' clause is empty.*/
/* Rule          : MISRA-C:2004 Message 3206                                  */
/* Justification : Parameter is not modified, however const qualifier is not  */
/*                 required. This is defined as per ASR API standard.         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-26 and                          */
/*                 END Msg(2:3206)-26 tags in the code.                       */

/******************************************************************************/
/* 27. QAC Warning:                                                           */
/* Message       : (2:2000) This 'switch' statement 'default' clause is empty.*/
/* Rule          : MISRA-C:2004 Message 2000                                  */
/* Justification : No else clause has been encountered in this if statement.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2000)-27 and                          */
/*                 END Msg(2:2000)-27 tags in the code.                       */

/******************************************************************************/
/* 28. QAC Warning:                                                           */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0862)-28 and              */
/*                 END Msg(2:0862)-28 tags in the code.                       */

/******************************************************************************/
/* 29. QAC Warning:                                                           */
/* Message       : (2:0890) This #include #ifdef refers to a macro that has   */
/*                 been #undef'd in a previous #if block.                     */
/* Rule          : NA                                                         */
/* Justification : This is done for proper memory mapping of code and data    */
/*                 for PWM.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:0890)-29 and             */
/*                 END Msg(2:0890)-29 tags in the code.                       */
/******************************************************************************/

/******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Icu_HW_Init
**
** Service ID           : None
**
** Description          : This service initializes the hardware for all the
**                        configured channels based on the measurement mode.
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
** Preconditions        : None
**
** Global Variables     : Icu_GpChannelConfig, Icu_GpTimerChannelConfig
**                        Icu_GpTAUUnitConfig, Icu_GpPreviousInputConfig.
**
** Functions invoked    : Icu_HW_EdgeCountingInit, Icu_HW_TimestampInit,
**                        Icu_HW_SignalMeasurementInit and Icu_HW_SetActivation
**
** Registers Used       : TAUDnCMORm, TAUBnCMORm, TAUJnCMORm, TAUDnCMURm,
**                        TAUBnCMURm, TAUJnCMURm, TAUDnCDRm, TAUBnCDRm,
**                        TAUDnCSRm, TAUBnCSRm, TAUJnCSRm, TAUDnCSCm,
**                        TAUBnCSCm, TAUJnCSCm, TAUDnTPS, TAUBnTPS,
**                        TAUJnTPS, TAUDnBRS, TAUJnBRS,SELB_TAUD0I,
**                        ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_112, ICU_ESDD_UD_001 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:0890)-29 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-29 */
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_088, EAAR_PN0034_FR_0018 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_Init(void)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)\
  || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  #endif
  /* Implements: ICU_ESDD_UD_036 */
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)\
  || (ICU_TAUB_UNIT_USED == STD_ON)) && (ICU_PRESCALER_CONFIGURED == STD_ON))
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
  #endif
  /* Implements: ICU_ESDD_UD_036 */
  #if ((ICU_TAUD_UNIT_CONFIG == STD_ON) || (ICU_TAUB_UNIT_CONFIG == STD_ON) \
      && (ICU_PRESCALER_CONFIGURED == STD_ON))
  /* Pointer pointing to the TAUD/B Unit control registers */
  P2VAR(TAUDBOsReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBUnitOsReg;
  #endif
  /* Implements: ICU_ESDD_UD_036 */
  #if ((ICU_TAUJ_UNIT_CONFIG == STD_ON) && (ICU_PRESCALER_CONFIGURED == STD_ON))
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(TAUJOsReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJUnitOsReg;
  #endif

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/B channel control registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBChannelReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif

  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Defining a pointer to the previous input configuration parameters */
  P2CONST(Icu_PreviousInputUseType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpPreviousInputConfig;
  /* Defining a pointer to the previous input Control Register */
  P2VAR(uint16 volatile, AUTOMATIC, ICU_CONFIG_DATA) LpPrevInputCntrlReg;

  VAR(uint16, AUTOMATIC) LusPrevReg;
  #endif

  #if (ICU_EDGE_DETECT_API == STD_ON)
  /* Local variable to store the default activation edge */
  Icu_ActivationType LenDefaultActivation;
  #endif
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LenMeasurementMode;
  uint8 LucCnt;

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))
  /*
   * Update the Timer channel configuration pointer to point to the current
   * channel
   */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig;
  #endif
  /* Implements: ICU_ESDD_UD_036 */
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON)) && (ICU_PRESCALER_CONFIGURED == STD_ON))
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Icu_GpTAUUnitConfig;
  #endif
  /* Implements: ICU_ESDD_UD_036, ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
   /* MISRA Violation: START Msg(4:2877)-7 */
   /* Implements: ICU_ESDD_UD_042 */
  for (LucCnt = ICU_ZERO; LucCnt < ICU_TOTAL_TAU_UNITS_CONFIGURED; LucCnt++)
  {
    /* END Msg (4:2877)-7 */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)) \
    || (ICU_TAUB_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:2814)-18 */
    if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                           (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
    /* END Msg(2:2814)-18 */
    #endif
    {
    /* Implements: ICU_ESDD_UD_036 */
      #if ((ICU_TAUD_UNIT_CONFIG == STD_ON) || (ICU_TAUB_UNIT_CONFIG == STD_ON))
      #if (ICU_PRESCALER_CONFIGURED == STD_ON)
      /*
       * Set the values of prescaler and baud rate to
       * TPS and BRS registers respectively
       */
       /* QAC Warning: START Msg(2:3892)-19 */
      if (ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
       /* END Msg(2:3892)-19 */
      {
        LpTAUDBUnitOsReg =
            Icu_GaaTAUDBOsReg_BaseAddress[LpTAUUnitConfig->ucTAUOsCntlRegIndx];

        /* Write the configured prescaler value to TPS register */
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->usTPS,
                                                  LpTAUUnitConfig->usPrescaler)
        /* END Msg(2:2814)-18 */
        /* Check if value was written to the TPS register */
        ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->usTPS,
            LpTAUUnitConfig->usPrescaler, ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)

        #if (ICU_TAUD_UNIT_CONFIG == STD_ON)
        if (ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType)
        {
          /* Write the configured baudrate value to BRS register */
          ICU_WRITE_REG_ONLY(&LpTAUDBUnitOsReg->ucBRS,
                                                  LpTAUUnitConfig->ucBaudRate)
          /* Check if the value was written to the BRS register */
          ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBUnitOsReg->ucBRS,
            LpTAUUnitConfig->ucBaudRate, ICU_MASK_FIRST_8_BITS, ICU_INIT_SID)
        } /* End of ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType */

        else
        {
          /* No action required */
        }
        #endif
      } /* End of ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler */
      else
      {
        /* No action required */
      }
      #endif /* End of (ICU_PRESCALER_CONFIGURED == STD_ON) */
      #endif /*
              * End of
              * ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED ==
              * STD_ON))
              */
    } /*
       * End of (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUD) ||
       * (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType)
       */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON))\
                                             || (ICU_TAUB_UNIT_USED == STD_ON))
    else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
    #endif
    {
    /* Implements: ICU_ESDD_UD_036 */
      #if (ICU_TAUJ_UNIT_CONFIG == STD_ON)
      #if (ICU_PRESCALER_CONFIGURED == STD_ON)
      LpTAUJUnitOsReg =
              Icu_GaaTAUJOsReg_BaseAddress[LpTAUUnitConfig->ucTAUOsCntlRegIndx];
      /*
       * Set the values of prescaler and baud rate to
       * TPS and BRS registers respectively
       */
       /* QAC Warning: START Msg(2:3892)-19 */
      if (ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
       /* END Msg(2:3892)-19 */
      {
        /* Write to the TPS register */
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_WRITE_REG_ONLY(&LpTAUJUnitOsReg->usTPS,
                                                 LpTAUUnitConfig->usPrescaler)
        /* END Msg(2:2814)-18 */
        /* Check if value was written to the TPS the register */
        ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->usTPS,
          LpTAUUnitConfig->usPrescaler, ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)

        /* Write to the BRS register */
        ICU_WRITE_REG_ONLY(&LpTAUJUnitOsReg->ucBRS,
                                                  LpTAUUnitConfig->ucBaudRate)
        /* Check if the value was written to the BRS register */
        ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJUnitOsReg->ucBRS,
          LpTAUUnitConfig->ucBaudRate, ICU_MASK_FIRST_8_BITS, ICU_INIT_SID)
      } /* End of ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler */
      else
      {
        /* No action required */
      }
      #endif /* End of #if (ICU_PRESCALER_CONFIGURED == STD_ON) */
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */

    } /* End of (ICU_HW_TAUJ == LpTAUUnitConfig->ucIcuUnitType) */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-5 */
    /* Increment the pointer to point to next TAU unit */
    LpTAUUnitConfig++;
    /* END Msg(4:2983)-5 */
    /* END Msg(4:0489)-1 */

  } /* End of TAU units for loop */
  #endif /* End of (ICU_PRESCALER_CONFIGURED == STD_ON) */
  #endif /* End of (ICU_TIMER_CH_CONFIGURED == STD_ON) */

  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Update the previous input use pointer to point to the current channel */
  LpPreviousInputConfig = Icu_GpPreviousInputConfig;
  /* MISRA Violation: START Msg(4:2877)-7 */
  /* Implements: ICU_ESDD_UD_038 */
  for (LucCnt = ICU_ZERO; LucCnt != ICU_TOTAL_UNITS_FOR_PREVINPUT; LucCnt++)
  {
  /* END Msg (4:2877)-7 */
    /*
     * Read the Previous input mask value and put it into the previous input
     * control register (SELB_TAUD0)
     */
    /* MISRA Violation: START Msg(4:0317)-6*/
    /* QAC Warning: START Msg(2:2814)-18 */
    LpPrevInputCntrlReg =  LpPreviousInputConfig->pPreviousInputCntlRegs;
    /* END Msg(4:0317)-6*/
    LusPrevReg = (*LpPrevInputCntrlReg) |
                   LpPreviousInputConfig->usPreviousInputMask;
    /* Write the value to the SELB register */
    /* END Msg(2:2814)-18 */
    ICU_WRITE_REG_ONLY(LpPrevInputCntrlReg, LusPrevReg)
    /* Check if the value was written to the SELB register */
    ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(LpPrevInputCntrlReg, LusPrevReg,
                                        ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-5 */
    /* Increment the pointer to point to next previous input channel */
    LpPreviousInputConfig++;
    /* END Msg(4:2983)-5 */
    /* END Msg(4:0489)-1 */

  } /* End of Previous input channel for loop */
  #endif /* End of (ICU_PREVIOUS_INPUT_USED == STD_ON) */

  /* Check if configuration contains any timer channels */
  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
   /* MISRA Violation: START Msg(4:2877)-7 */
   /* Implements:  ICU_ESDD_UD_141 */
  for (LucCnt = ICU_ZERO; LucCnt < ICU_MAX_TIMER_CHANNELS_CONFIGURED; LucCnt++)
  {
    /* END Msg (4:2877)-7 */

    /* Read the channel's measurement mode */
    /* QAC Warning: START Msg(2:4342)-23 */
    /* QAC Warning: START Msg(2:2814)-18 */
    LenMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
    /* END Msg(2:4342)-23 */
    /* END Msg(2:2814)-18 */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             || (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
                             (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    #endif
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))

      /*
       * If the measurement mode is edge counter, put the defined
       * count value to CDR Register
       */
      LpTAUDBChannelReg =
                Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];

      /* Set Channel Mode OS Register with the configured value */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->usCMOR,
        LpTimerChannelConfig->usChannelModeOSRegSettings)
      /* END Msg(2:2814)-18 */
      /* Check if the value was written to the Channel Mode OS Register */
      ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->usCMOR,
        LpTimerChannelConfig->usChannelModeOSRegSettings,
        ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)

      /* Set the Channel Mode User Register with the configured value */
      ICU_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelReg->ucCMUR,
        LpTimerChannelConfig->ucChannelModeUserRegSettings,
        &Icu_GaaTAUDBChannelRegMirror[LucCnt].ucMirrorTAUDBnCMURm)
      /* Check if the value was written to the Channel Mode User Register */
      ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->ucCMUR,
        LpTimerChannelConfig->ucChannelModeUserRegSettings,
        ICU_MASK_FIRST_2_BITS, ICU_INIT_SID)

      /* Measurement specific initialisation */
      if (ICU_MODE_EDGE_COUNTER == LenMeasurementMode)
      {
        /* Assign the down count value to CDR register */
        ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->usCDR,
                                                  ICU_TAUDB_START_DWNCNT_VAL)
        /* Check if the value was written to the CDR register */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->usCDR,
            ICU_TAUDB_START_DWNCNT_VAL, ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)
        /* END Msg(2:3892)-19 */
      } /* End of ICU_MODE_EDGE_COUNTER == LenMeasurementMode */
      else if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
      {
        /* Reset Channel Status Clear Trigger Register */
        ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->ucCSC, ICU_TAUDB_CSC_RESET_VAL)
        /* Check if the CSR, OVF bit was cleared (0), CSC has effect in CSR */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->ucCSR,
                    ICU_TAUDB_CSR_RESET_VAL, ICU_MASK_FIRST_BIT, ICU_INIT_SID)
        /* END Msg(2:3892)-19 */
      } /* End of ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode */
      else
      {
        /* CSC registers do not need to be cleared */
        /* see CMOR settings in datasheet for measurement modes */
      }

      /* Disable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAdress),
                          (ICU_INTERRUPT_MASK_DIS));
      #endif /* End of
          ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    } /*
       * End of (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUD) ||
       * (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType)
       */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    else if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
    /* END Msg(2:3892)-19 */
    #endif
    {
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      /*
       * If the measurement mode is edge counter, put the defined
       * count value to CDR Register
       */
      LpTAUJChannelReg =
                Icu_GaaTAUJChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];

      /* Read the value of Channel Mode OS Register configured */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_WRITE_REG_ONLY(&LpTAUJChannelReg->usCMOR,
                            LpTimerChannelConfig->usChannelModeOSRegSettings)
      /* END Msg(2:2814)-18 */
      /* Check if the value was written to the CMOR register */
      ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->usCMOR,
                            LpTimerChannelConfig->usChannelModeOSRegSettings,
                            ICU_MASK_FIRST_16_BITS, ICU_INIT_SID)

      /* Read the value of Channel Mode User Register configured */
      ICU_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ucCMUR,
        LpTimerChannelConfig->ucChannelModeUserRegSettings,
        &Icu_GaaTAUJChannelRegMirror[LucCnt].ucMirrorTAUJnCMURm)
      /* Check if the value was written to the CMUR register */
      ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ucCMUR,
                            LpTimerChannelConfig->ucChannelModeUserRegSettings,
                            ICU_MASK_FIRST_2_BITS, ICU_INIT_SID)

      /* Measurement specific initialisation */
      if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
      {
        /* Reset Channel Status Clear Trigger Register */
        ICU_WRITE_REG_ONLY(&LpTAUJChannelReg->ucCSC, ICU_TAUJ_CSC_RESET_VAL)
        /* Check if the CSR, OVF bit was cleared (0), CSC has effect in CSR */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ucCSR,
                     ICU_TAUJ_CSR_RESET_VAL, ICU_MASK_FIRST_BIT, ICU_INIT_SID)
        /* END Msg(2:3892)-19 */
      }
      else
      {
        /* CSC registers do not need to be cleared */
        /* see CMOR settings in datasheet for measurement modes */
        /* TAUJ does not support edge count/detection mode */
      }

      /* Disable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAdress),
                          (ICU_INTERRUPT_MASK_DIS));
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    } /* End of ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType */

    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif

    /* QAC Warning: START Msg(2:2016)-25 */
    switch (LenMeasurementMode)
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Edge Counter Mode */
      /* QAC Warning: START Msg(2:2204)-24 */
      case ICU_MODE_EDGE_COUNTER:
      {
        /* Configure the channel in Edge Counter Mode */
        Icu_HW_EdgeCountingInit(LpTimerChannelConfig);
        break;
      }
      #endif
      #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                          || (ICU_TAUJ_UNIT_USED == STD_ON))
      /* Timestamp Mode */
      case ICU_MODE_TIMESTAMP:
      {
        /* Configure the channel in Timestamp Mode */
        Icu_HW_TimestampInit(LpTimerChannelConfig);
        break;
      }
      #endif
      #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                          || (ICU_TAUJ_UNIT_USED == STD_ON))
      /* Signal Measurement Mode */
      case ICU_MODE_SIGNAL_MEASUREMENT:
      {
        /* Configure the channel in Signal Measurement Mode */
        Icu_HW_SignalMeasurementInit(LpTimerChannelConfig);
        break;
      }
      #endif
      default:
      /* END Msg(2:2204)-24 */
      {
        /* Execution should never get here */
        break;
      }
    } /* End of switch case */
    /* END Msg(2:2016)-25 */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the channel pointer */
    LpChannelConfig++;
    /* END Msg(4:0489)-1 */

    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
         || (ICU_TAUJ_UNIT_USED == STD_ON))

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-5 */
    /* Increment the timer channel pointer */
    LpTimerChannelConfig++;
    /* END Msg(4:2983)-5 */
    /* END Msg(4:0489)-1 */
    #endif
    /*
     * End of (((ICU_TAUD_UNIT_USED == STD_ON)
     * || (ICU_TAUB_UNIT_USED == STD_ON)) || (ICU_TAUJ_UNIT_USED == STD_ON))
     */
  } /* End of channels for loop */
  #endif /* end of (ICU_TIMER_CH_CONFIGURED == STD_ON) */
  /* MISRA Violation: START Msg(4:2877)-7 */
  /* MISRA Violation: START Msg(4:2996)-11 */
  /* MISRA Violation: START Msg(4:2994)-12 */
  /* Implements:  ICU_ESDD_UD_141 */
  /* Implements:  ICU220_Conf,  ECUC_Icu_00220 */
  for (LucCnt = ICU_MAX_TIMER_CHANNELS_CONFIGURED; LucCnt < ICU_MAX_CHANNEL;
                                                                       LucCnt++)
  /* END Msg(4:2994)-12 */
  /* END Msg(4:2996)-11 */
  /* END Msg (4:2877)-7 */
  {
    /* MISRA Violation: START Msg(4:2880)-13 */
    /* Read the channel's measurement mode */
    /* QAC Warning: START Msg(2:4342)-23 */
    LenMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
    /* END Msg(2:4342)-23 */
    /* END Msg(4:2880)-13 */

    #if (ICU_EDGE_DETECT_API == STD_ON)
    if (ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode)
    {
      /* Implements:    ICU011, SWS_Icu_00011   */
      /* Read the default edge configured for the channel */
      /* QAC Warning: START Msg(2:4342)-23 */
      LenDefaultActivation = (Icu_ActivationType)
        LpChannelConfig->uiIcuDefaultStartEdge;
      /* END Msg(2:4342)-23 */

      /* Disable the Interrupt processing of the current channel */
      RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAdress),
                          (ICU_INTERRUPT_MASK_DIS));

      /* Configure external interrupt for the active edge */
      Icu_HW_SetActivation(LucCnt, LenDefaultActivation, ICU_INIT_SID);
    }
    else
    {
      /* Other measurement mode is used */
    }
    #endif /* End of #if (ICU_EDGE_DETECT_API == STD_ON) */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-5 */
    /* Increment the channel pointer */
    LpChannelConfig++;
    /* END Msg(4:2983)-5 */
    /* END Msg(4:0489)-1 */
  } /* End of channels for loop */
} /* End of Internal function Icu_HW_Init */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_HW_DeInit
**
** Service ID           : None
**
** Description          : This service De-Initializes the hardware for all the
**                        configured channels based on the measurement mode.
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
** Preconditions        : None
**
** Global Variables     : Icu_GpChannelConfig, Icu_GpTimerChannelConfig
**                        Icu_GpPreviousInputConfig.
**
** Functions invoked    : None.
**
** Registers Used       : TAUDnCMORm, TAUBnCMORm, TAUJnCMORm,
**                        TAUDnCMURm, TAUBnCMURm, TAUJnCMURm,
**                        TAUDnCDRm, TAUBnCDRm, TAUJnCDRm,
**                        TAUDnCSRm, TAUBnCSRm, TAUJnCSRm,
**                        TAUDnCSCm, TAUBnCSCm, TAUJnCSCm,
**                        SELB_TAUD0I, FCLAnCTLm, ICTAUDmIn,
**                        ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_113, ICU_ESDD_UD_001 */
#if (ICU_DE_INIT_API == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements: ICU_ESDD_UD_089, EAAR_PN0034_FR_0018*/
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_DeInit(void)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  #endif

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/B channel control registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBChannelReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif

  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;

  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Defining a pointer to the previous input configuration parameters */
  P2CONST(Icu_PreviousInputUseType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpPreviousInputConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16 volatile, AUTOMATIC, ICU_CONFIG_DATA) LpPrevInputCntrlReg;
  VAR(uint16, AUTOMATIC) LusPrevReg;
  #endif
  #if ((ICU_EDGE_DETECT_API == STD_ON) || (ICU_TAUDBJ_UNIT_USED == STD_ON))
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LenMeasurementMode;
  #endif
  uint8 LucCnt;

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)\
  || (ICU_TAUB_UNIT_USED == STD_ON))
  LpTimerChannelConfig = Icu_GpTimerChannelConfig;
  #endif

  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)

  /* Update the previous input use pointer to point to the current channel */
  LpPreviousInputConfig = Icu_GpPreviousInputConfig;
   /* MISRA Violation: START Msg(4:2877)-7 */
   /* Implements: ICU_ESDD_UD_038 */
  for (LucCnt = ICU_ZERO; LucCnt != ICU_TOTAL_UNITS_FOR_PREVINPUT; LucCnt++)
  {
    /* END Msg (4:2877)-7 */
    /* MISRA Violation: START Msg(4:0317)-6*/
    /* QAC Warning: START Msg(2:2814)-18 */
    LpPrevInputCntrlReg = LpPreviousInputConfig->pPreviousInputCntlRegs;
    /* END Msg(4:0317)-6*/
    /* Write the previous input mask value to SELB_TAUD0 register */
    /* MISRA Violation: START Msg(4:4397)-10 */
    LusPrevReg = (*LpPrevInputCntrlReg) &
                 (~LpPreviousInputConfig->usPreviousInputMask);
    /* END Msg(2:2814)-18 */
    /* Write the value to the SELB register */
    ICU_WRITE_REG_ONLY(LpPrevInputCntrlReg, LusPrevReg)
    /* Check if the value was written to the SELB register */
    ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(LpPrevInputCntrlReg, LusPrevReg,
                                        ICU_MASK_FIRST_16_BITS, ICU_DEINIT_SID)
    /* END Msg(4:4397)-10 */
    /* MISRA Violation: START Msg(4:0489)-1 */
    /* MISRA Violation: START Msg(4:2983)-5 */
    LpPreviousInputConfig++;
    /* END Msg(4:2983)-5 */
    /* END Msg(4:0489)-1 */
  } /* End of Previous input for loop */
  #endif /* End of (ICU_PREVIOUS_INPUT_USED == STD_ON) */

  for (LucCnt = ICU_ZERO; LucCnt < ICU_MAX_CHANNEL; LucCnt++)
  {
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    /* QAC Warning: START Msg(2:2814)-18 */
    if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType)
       || (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    /* END Msg(2:2814)-18 */
    #endif
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Read the channel's measurement mode */
      /* QAC Warning: START Msg(2:4342)-23 */
      LenMeasurementMode = (Icu_MeasurementModeType)
        (LpChannelConfig->uiIcuMeasurementMode);
      /* END Msg(2:4342)-23 */

      LpTAUDBChannelReg =
               Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];

      /* Measurement specific de-init */
      if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
      {
        /* Write CSC before CMOR, otherwise it will be ignored */
        /* Reset Channel Status Clear Trigger Register */
        /* Per datasheet, 1 written to CSC, clears the TAUBnOVF flag(overflow)*/
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->ucCSC, ICU_TAUDB_CSC_RESET_VAL)
        /* END Msg(2:2814)-18 */
        /* Check if the CSR, OVF bit was cleared (0), CSC has effect in CSR */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->ucCSR,
                  ICU_TAUDB_CSR_RESET_VAL, ICU_MASK_FIRST_BIT, ICU_DEINIT_SID)
        /* END Msg(2:3892)-19 */
      }
      else
      {
        /* CSC registers do not need to be cleared */
        /* see CMOR settings in datasheet for measurement modes */
      }

      /* Reset the value of Channel Mode OS Register */
      ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->usCMOR, ICU_TAUDB_CMOR_RESET_VAL)
      /* Check if the value was written to the CMOR register */
      /* QAC Warning: START Msg(2:3892)-19 */
      ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->usCMOR,
             ICU_TAUDB_CMOR_RESET_VAL, ICU_MASK_FIRST_16_BITS, ICU_DEINIT_SID)

      /* Reset the value of Channel Data Register */
      ICU_WRITE_REG_ONLY(&LpTAUDBChannelReg->usCDR, ICU_TAUDB_CDR_RESET_VAL)
      /* Check if the value was written to the CDR register */
      ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->usCDR,
            ICU_TAUDB_CDR_RESET_VAL, ICU_MASK_FIRST_16_BITS, ICU_DEINIT_SID)

      /* Reset the value of Channel Mode User Register */
      ICU_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelReg->ucCMUR,
                     ICU_TAUDB_CMUR_RESET_VAL,
                     &Icu_GaaTAUDBChannelRegMirror[LucCnt].ucMirrorTAUDBnCMURm)
      /* Check if the value was written to the CMUR register */
      ICU_TAUDB_CHECK_WRITE_VERIFY_INIT(&LpTAUDBChannelReg->ucCMUR,
               ICU_TAUDB_CMUR_RESET_VAL, ICU_MASK_FIRST_2_BITS, ICU_DEINIT_SID)
      #endif
    } /*
       * End of (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUD) ||
       * (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType)
       */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    else if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
       /* END Msg(2:3892)-19 */
    #endif
    {
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      /* Read the channel's measurement mode */
      /* QAC Warning: START Msg(2:4342)-23 */
      LenMeasurementMode = (Icu_MeasurementModeType)
        (LpChannelConfig->uiIcuMeasurementMode);
      /* END Msg(2:4342)-23 */

      LpTAUJChannelReg = Icu_GaaTAUJChReg_BaseAddress
                                             [LpChannelConfig->ucCntlRegsIndx];
      /* Measurement specific de-init */
      if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
      {
        /* Write CSC before CMOR, otherwise it will be ignored */
        /* Reset Channel Status Clear Trigger Register */
        /* Per datasheet, 1 written to CSC, clears the TAUJnOVF flag
        (overflow)*/
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_WRITE_REG_ONLY(&LpTAUJChannelReg->ucCSC, ICU_TAUJ_CSC_RESET_VAL)
        /* END Msg(2:2814)-18 */
        /* Check if the CSR, OVF bit was cleared (0), CSC has effect in CSR */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ucCSR,
                     ICU_TAUJ_CSR_RESET_VAL, ICU_MASK_FIRST_BIT, ICU_DEINIT_SID)
      }
      else
      {
        /* CSC registers do not need to be cleared */
        /* see CMOR settings in datasheet for measurement modes */
      }

      /* Reset the value of Channel Mode OS Register */
      ICU_WRITE_REG_ONLY(&LpTAUJChannelReg->usCMOR, ICU_TAUJ_CMOR_RESET_VAL)
      /* Check if the value was written to the CMOR register */
      ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->usCMOR,
             ICU_TAUJ_CMOR_RESET_VAL,ICU_MASK_FIRST_16_BITS, ICU_DEINIT_SID)

      /* Reset the value of Channel Data Register */
      ICU_WRITE_REG_ONLY(&LpTAUJChannelReg->ulCDR, ICU_TAUJ_CDR_RESET_VAL)
      /* Check if the value was written to the CDR register */
      ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ulCDR,
               ICU_TAUJ_CDR_RESET_VAL, ICU_MASK_FIRST_32_BITS, ICU_DEINIT_SID)
      /* Reset the value of Channel Mode User Register */
      ICU_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ucCMUR,
                        ICU_TAUJ_CMUR_RESET_VAL,
                        &Icu_GaaTAUJChannelRegMirror[LucCnt].ucMirrorTAUJnCMURm)
      /* Check if the value was written to the CMUR register */
      ICU_TAUJ_CHECK_WRITE_VERIFY_INIT(&LpTAUJChannelReg->ucCMUR,
                 ICU_TAUJ_CMUR_RESET_VAL, ICU_MASK_FIRST_2_BITS, ICU_DEINIT_SID)
      /* END Msg(2:3892)-19 */
      #endif
    } /* End of ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType */

    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* No action required */
    }
    #endif
    /* Disabling the Interrupt processing */
    LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
    /* QAC Warning: START Msg(2:2814)-18 */

    RH850_SV_MODE_ICR_OR(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_DIS));
    /* END Msg(2:2814)-18 */

    /* Check channel connected to Timers based on the measurement mode */
    #if (ICU_EDGE_DETECT_API == STD_ON)
    /* Read the channel's measurement mode */
    /* QAC Warning: START Msg(2:4342)-23 */
    LenMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
    /* END Msg(2:4342)-23 */
    /* Edge Detection Mode */
    if (ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode)
    {
      /* Read the base configuration interrupt address */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_FCLA_WRITE_REG_AND_MIRROR(
      &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
      ICU_FCLA_CTL_RESET_VAL, &Icu_GaaFclaRegsMirror[LucCnt].ucMirrorFCLA0CTLm)
      /* END Msg(2:2814)-18 */
      /* Check if the value was written to the FCLA (INTP) register */
      /* QAC Warning: START Msg(2:3892)-19 */
      ICU_FCLA_CHECK_WRITE_VERIFY_INIT(
      &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
      ICU_FCLA_CTL_RESET_VAL, ICU_MASK_FIRST_3_BITS, ICU_DEINIT_SID)
    } /* End of ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode */
      /* END Msg(2:3892)-19 */

    else
    {
      /* No action required */
    }
    #endif /* End of (ICU_EDGE_DETECT_API == STD_ON) */

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Increment the channel pointer */
    LpChannelConfig++;
    /* END Msg(4:0489)-1 */

    #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)\
    || (ICU_TAUB_UNIT_USED == STD_ON))

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Increment the timer channel pointer */
    LpTimerChannelConfig++;
    /* END Msg(4:0489)-1 */
    /* END Msg(2:2824)-20 */

    #endif
  } /* End of channels for loop */
} /* End of Internal function Icu_HW_DeInit */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_DE_INIT_API == STD_ON) */

/*******************************************************************************
** Function Name         : Icu_HW_EdgeCountingInit
**
** Service ID            : None
**
** Description           : This service initializes the channel configured for
**                         edge counting mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LpTimerChannelConfig
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : Icu_GpEdgeCountData.
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_114, ICU_ESDD_UD_173 */
/* Implements: ICU_ESDD_UD_001 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_114                                               */
/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_EdgeCountingInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig)
/* END Msg(2:3227)-22 */
{
  /* Local variable used to store the Ram index */
  uint8 LucIndex;
  /* QAC Warning: START Msg(2:2814)-18 */

  LucIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:3892)-19 */
  /* Reset the edge count overflow flag */
  Icu_GpEdgeCountData[LucIndex].uiTimerOvfFlag = ICU_FALSE;
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* END Msg(2:3892)-19 */

} /* End of Internal function Icu_HW_EdgeCountingInit */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name         : Icu_HW_TimestampInit
**
** Service ID            : None
**
** Description           : This service is used to initialize the channel
**                         configured for Timestamp Measurement mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LpTimerChannelConfig
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : Icu_GpTimeStampData.
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_001 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_115                                               */
/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_TimestampInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig)
/* END Msg(2:3227)-22 */
{
  /* Local variable used to store the channel index */
  uint8 LucIndex;
  /* Read the Timestamp Channel ram index */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:3892)-19 */
  Icu_GpTimeStampData[LucIndex].usTimestampIndex = ICU_BUFFER_IDX_INIT_VAL;
  /* END Msg(2:2824)-20 */
  /* Set buffer pointer to null, to satisfy ICU135 in Icu_StartTimestamp */
  Icu_GpTimeStampData[LucIndex].pBufferPointer = NULL_PTR;
  /* END Msg(4:0491)-4 */
  /* END Msg(2:3892)-19 */
} /* End of Internal function Icu_HW_TimestampInit */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name         : Icu_HW_SignalMeasurementInit
**
** Service ID            : None
**
** Description           : This service initializes the channel configured in
**                         Signal Measurement Mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LpTimerChannelConfig
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : Icu_GpSignalMeasurementData.
**
** Functions invoked     : None
**
** Registers Used        : None
**
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_116                                               */
/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SignalMeasurementInit
(P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig)
/* END Msg(2:3227)-22 */
{
  /* Local variable used to store the Timer Instance */
  uint8 LucIndex;

  /* Read the Signal Measurement Channel ram index */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:3892)-19 */
  /* Initialize the Signal Active time to zero */
  Icu_GpSignalMeasurementData[LucIndex].ulSignalActiveTime =
                                                     ICU_ACTIVE_TIME_RESET_VAL;
  /* END Msg(2:2824)-20 */
  /* Initialize the Signal Period time to zero */
  Icu_GpSignalMeasurementData[LucIndex].ulSignalPeriodTime =
                                                     ICU_PERIOD_TIME_RESET_VAL;
  /* Initialize the Signal Previous active time to zero */
  Icu_GpSignalMeasurementData[LucIndex].ulPrevSignalActiveTime =
                                                     ICU_ACTIVE_TIME_RESET_VAL;
  /* END Msg(4:0491)-4 */
  /* END Msg(2:3892)-19 */

} /* End of Internal function Icu_HW_SignalMeasurementInit */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_HW_SetActivation
**
** Service ID           : None
**
** Description          : This service configures the hardware to the active
**                        edges of the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel, ActiveEdge
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Global Variables     : Icu_GpChannelConfig, Icu_GpEdgeCountData,
**                        Icu_GpTimerChannelConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : TAUDnCMURm, TAUBnCMURm, TAUJnCMURm, FCLAnCTLm.
**
*******************************************************************************/
/* Implements ICU_ESDD_UD_001 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_117                                               */
/* QAC Warning: START Msg(2:3227)-22 */
/* QAC Warning: START Msg(2:3206)-26 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SetActivation
(Icu_ChannelType Channel, Icu_ActivationType ActiveEdge, uint8 LucSid)
/* END Msg(2:3227)-22 */
/* END Msg(2:3206)-26 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  #if ((ICU_EDGE_DETECT_API == STD_ON) || (ICU_TAUDB_UNIT_USED == STD_ON) || \
       (ICU_TAUJ_UNIT_USED == STD_ON))
  Icu_MeasurementModeType LenMeasurementMode;
  #endif
  #if (ICU_TAUDB_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUD/B channel control registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUDBChannelReg;
  #endif
  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  uint8 LucIndex;
  #endif
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /*
   * Update the timer channel configuration pointer to point to the
   * current channel
   */
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /*
   * Update the Timer channel configuration pointer to point to the current
   * channel
   */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */

  #endif
  #if ((ICU_EDGE_DETECT_API == STD_ON) || (ICU_TAUD_UNIT_USED == STD_ON) || \
  (ICU_TAUB_UNIT_USED == STD_ON) || (ICU_TIMESTAMP_API == STD_ON))
  /* Read measurement mode */
  /* QAC Warning: START Msg(2:4342)-23 */
  /* QAC Warning: START Msg(2:2814)-18 */
  LenMeasurementMode =
               (Icu_MeasurementModeType)(LpChannelConfig->uiIcuMeasurementMode);
  /* END Msg(2:2814)-18 */
  /* END Msg(2:4342)-23 */
  #endif
  #if (ICU_EDGE_DETECT_API == STD_ON)
  if (ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode)
  {
  /* QAC Warning: START Msg(2:3892)-19 */
    if (ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType)
  /* END Msg(2:3892)-19 */
    {
      /* Write value to the FCLA (INTP) register and to the mirror array */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_FCLA_WRITE_REG_AND_MIRROR(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BYPASS_FILTER, &Icu_GaaFclaRegsMirror[Channel].ucMirrorFCLA0CTLm)
      /* END Msg(2:2814)-18 */
      /* Check if the value was written to the FCLA (INTP) register */
      /* QAC Warning: START Msg(2:3892)-19 */
      ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BYPASS_FILTER, ICU_MASK_FIRST_3_BITS, LucSid)

      if (ICU_BOTH_EDGES == ActiveEdge)
      {
        /* Write value to the FCLA (INTP) register and to the mirror array */
        ICU_FCLA_WRITE_REG_AND_MIRROR(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BOTH_EDGES_FILTER,
        &Icu_GaaFclaRegsMirror[Channel].ucMirrorFCLA0CTLm)
        /* Check if the value was written to the FCLA (INTP) register */
        ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BOTH_EDGES_FILTER, ICU_MASK_FIRST_3_BITS, LucSid)
      } /* End of ICU_BOTH_EDGES == ActiveEdge */

      else if (ICU_FALLING_EDGE == ActiveEdge)
      {
        /* Write value to the FCLA (INTP) register and to the mirror array */
        ICU_FCLA_WRITE_REG_AND_MIRROR(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_FALLING_EDGE_FILTER,
        &Icu_GaaFclaRegsMirror[Channel].ucMirrorFCLA0CTLm)
        /* Check if the value was written to the FCLA (INTP) register */
        ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_FALLING_EDGE_FILTER, ICU_MASK_FIRST_3_BITS, LucSid)
      } /* End of ICU_FALLING_EDGE == ActiveEdge */

      else /* (ActiveEdge == ICU_RISING_EDGE) */
      {
        /* Write value to the FCLA (INTP) register and to the mirror array */
        ICU_FCLA_WRITE_REG_AND_MIRROR(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_RISING_EDGE_FILTER,
        &Icu_GaaFclaRegsMirror[Channel].ucMirrorFCLA0CTLm)
        /* Check if the value was written to the FCLA (INTP) register */
        ICU_FCLA_CHECK_WRITE_VERIFY_RUNTIME(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_RISING_EDGE_FILTER, ICU_MASK_FIRST_3_BITS, LucSid)
        /* END Msg(2:3892)-19 */
      } /* End of ActiveEdge == ICU_RISING_EDGE */
    }
    else
    {
      /* Implements:  ICU_ESDD_UD_045, SWS_Icu_00149, ICU149                  */
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      LpTAUDBChannelReg =
                Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];
      /* Set the active edge */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelReg->ucCMUR,
        (uint8)ActiveEdge,
        &Icu_GaaTAUDBChannelRegMirror[Channel].ucMirrorTAUDBnCMURm)
      /* END Msg(2:2814)-18 */

      /* Check if the active edge was written to the CMUR register */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBChannelReg->ucCMUR,
        (uint8)ActiveEdge, ICU_MASK_FIRST_2_BITS, LucSid)
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      #endif
    } /* ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType */
  } /* End of ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode */

  else /* LenMeasurementMode = ICU_MODE_EDGE_COUNTER or ICU_MODE_TIMESTAMP */
  #endif /* End of (ICU_EDGE_DETECT_API == STD_ON) */
  {
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
                           (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    #endif
    {
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_EDGECOUNT_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      LpTAUDBChannelReg =
                Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];
      if (ICU_MODE_EDGE_COUNTER == LenMeasurementMode)
      {
        /* Get the index of edge count RAM variable */
        /* QAC Warning: START Msg(2:2814)-18 */
        LucIndex = LpTimerChannelConfig->ucRamDataIndex;
        /* END Msg(2:2814)-18 */

        /* Enable Edge Counting only if there is no timer overflow */

        /* MISRA Violation: START Msg(4:0491)-4 */
        /* QAC Warning: START Msg(2:3892)-19 */
        /* QAC Warning: START Msg(2:2824)-20 */
        if (ICU_FALSE == Icu_GpEdgeCountData[LucIndex].uiTimerOvfFlag)
        /* END Msg(4:0491)-4 */
        /* END Msg(2:3892)-19 */
        /* END Msg(2:2824)-20 */
        {
          /* Set the active edge */
          ICU_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelReg->ucCMUR,
            (uint8)ActiveEdge,
            &Icu_GaaTAUDBChannelRegMirror[Channel].ucMirrorTAUDBnCMURm)

          /* Check if the active edge was written to the CMUR register */
          ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBChannelReg->ucCMUR,
            (uint8)ActiveEdge, ICU_MASK_FIRST_2_BITS, LucSid)
        } /* End of ICU_FALSE == Icu_GpEdgeCountData[LucIndex].uiTimerOvfFlag */
        else
        {
          /* No action required */
        }
      } /* End of ICU_MODE_EDGE_COUNTER == LenMeasurementMode */

      else /* if (ICU_MODE_TIMESTAMP == LenMeasurementMode) */
      {
        /* Set the active edge */
        ICU_TAUDB_WRITE_REG_AND_MIRROR(&LpTAUDBChannelReg->ucCMUR,
          (uint8)ActiveEdge,
          &Icu_GaaTAUDBChannelRegMirror[Channel].ucMirrorTAUDBnCMURm)
        /* Check if the active edge was written to the CMUR register */
        ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBChannelReg->ucCMUR,
          (uint8)ActiveEdge, ICU_MASK_FIRST_2_BITS, LucSid)
      } /* End of ICU_MODE_TIMESTAMP == LenMeasurementMode */
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_EDGECOUNT_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      #endif
    } /*
       * End of (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUD) ||
       * (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType)
       */
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    else if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
    /* END Msg(2:3892)-19 */
    #endif
    {
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /*
       * TAUJ doesn't support edge counter mode. so, set the active edge
       * for timestamp mode only*/
      LpTAUJChannelReg = Icu_GaaTAUJChReg_BaseAddress
                                        [LpChannelConfig->ucCntlRegsIndx];
      if (ICU_MODE_TIMESTAMP == LenMeasurementMode)
      {
        /* Set the active edge */
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_TAUJ_WRITE_REG_AND_MIRROR(&LpTAUJChannelReg->ucCMUR,
          (uint8)ActiveEdge,
          &Icu_GaaTAUJChannelRegMirror[Channel].ucMirrorTAUJnCMURm)
        /* END Msg(2:2814)-18 */

        /* Check if the active edge was written to the CMUR register */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJChannelReg->ucCMUR,
          (uint8)ActiveEdge, ICU_MASK_FIRST_2_BITS, LucSid)
        /* END Msg(2:3892)-19 */
      }
      else
      {
        /* No action required */
      }
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      #endif
    } /* End of ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType */

    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif

  } /*
     * End of LenMeasurementMode = ICU_MODE_EDGE_COUNTER or ICU_MODE_TIMESTAMP
     */

} /* End of Internal function Icu_HW_SetActivation */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_HW_SetMode
**
** Service ID           : None
**
** Description          : This service sets the operating mode of the ICU
**                        Driver.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non Reentrant
**
** Input Parameters     : Mode
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Icu_GpChannelConfig, Icu_GpChannelRamData
**                        Icu_GenModuleMode.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
#if (ICU_SET_MODE_API == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_118                                               */
/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SetMode(Icu_ModeType Mode)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;
  /* Local variable to store wakeup status */
  uint8 LucWakeupStatus;
  /* Local variable to loop through the channels */
  uint8 LucChannelNo;
  /* Local variable to store notification status */
  uint8 LucNotifStatus;

  for (LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL; LucChannelNo++)
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Update the channel configuration pointer to the current channel */
    LpChannelConfig = &Icu_GpChannelConfig[LucChannelNo];
    /* Read the current channel wakeup status */
    LucWakeupStatus = Icu_GpChannelRamData[LucChannelNo].uiWakeupEnable;
    /* Read the current channel notification status */
    /* END Msg(2:2824)-20 */
    LucNotifStatus = Icu_GpChannelRamData[LucChannelNo].uiNotificationEnable;
    /* END Msg(4:0491)-4 */

    /* Load the interrupt control register */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
    /* END Msg(2:2814)-18 */
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Check for the current wakeup status of the channel */
    if (ICU_FALSE == LucWakeupStatus)
    {
      if (ICU_MODE_SLEEP == Mode)
      {
        /* Disable Interrupt */
        /* QAC Warning: START Msg(2:2814)-18 */
        RH850_SV_MODE_ICR_OR(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_DIS));
        /* END Msg(2:2814)-18 */
      } /* End of Mode = ICU_MODE_SLEEP */

      else /* Mode = ICU_MODE_NORMAL */
      {
        /* Implements:  ICU_ESDD_UD_052                                      */
        #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
        /* Check if the Interrupt register is present for particular channel */
        if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
        {
          /* MISRA Violation: START Msg(4:0488)-2 */
          /* MISRA Violation: START Msg(4:0310)-3 */
          /* Clear the pending interrupts */
          /* Implements:  ICU_ESDD_UD_045                                     */
          #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
          RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                        (ICU_CLEAR_PENDING_INTR_MASK));
          #else
          RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                                  (ICU_CLEAR_PENDING_INTR_MASK));
          #endif
          /* END Msg(4:0488)-2 */
          /* END Msg(4:0310)-3 */
        } /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
        else
        {
          /* No action required */
        }
        #endif
        /* Check for the current wakeup status and notification
                                                    status of the channel */
        if (ICU_TRUE == LucNotifStatus)
        {
          if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
          {
            /* Enable Interrupt */
            RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
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
      } /* End of Mode = ICU_MODE_NORMAL */

    } /* End of LucWakeupStatus == ICU_FALSE */
    else
    {
      /* No action required */
    }
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  } /* End of TAU channel for loop */

  /* Update the ICU Driver Mode */
  Icu_GenModuleMode = Mode;

} /* End of Internal function Icu_HW_SetMode */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_SET_MODE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HW_StartCountMeasurement
**
** Service ID           : None
**
** Description          : This service routine starts the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
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
** Preconditions        : None
**
** Global Variables     : Icu_GpTimerChannelConfig, Icu_GpChannelConfig,
**                        Icu_GpTAUUnitConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : TAUDnTS, TAUBnTS, TAUJnTS,
**                        TAUDnTT, TAUBnTT, TAUJnTT,
**                        TAUDnTE, TAUBnTE, TAUJnTE,
**                        ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_119, ICU_ESDD_UD_001                              */
/* QAC Warning: START Msg(2:3227)-22 */
/* QAC Warning: START Msg(2:3206)-26 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_StartCountMeasurement
(Icu_ChannelType Channel, uint8 LucSid)
/* END Msg(2:3227)-22 */
/* END Msg(2:3206)-26 */
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LenMeasurementMode;

  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16 , AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD/B user registers */
  P2VAR(TAUDBUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBUnitUserReg;
  #endif
  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ user registers */
  P2VAR(TAUJUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJUnitUserReg;
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Read channel configuration pointer */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];

  /* Update the TAU configuration pointer to point to the current TAU */
  /* QAC Warning: START Msg(2:2814)-18 */
  LpTAUUnitConfig =
                  &Icu_GpTAUUnitConfig[LpTimerChannelConfig->ucTimerUnitIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2814)-18 */
  /* END Msg(2:2824)-20 */
  /* Implements:  ICU_ESDD_UD_045                                         */
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Check if the Interrupt register is present for particular channel */
  /* QAC Warning: START Msg(2:2814)-18 */
  if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
  /* END Msg(2:2814)-18 */
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* Implements:  ICU_ESDD_UD_052                                      */
    #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
    /* Clear the pending interrupts */
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                  (ICU_CLEAR_PENDING_INTR_MASK));
    #else
    RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                            (ICU_CLEAR_PENDING_INTR_MASK));
    #endif /* #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON) */
    #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON) */
    /* Enabling the Interrupt processing */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
    RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
    /* END Msg(2:2814)-18 */
    /* END Msg (4:0488)-2 */
    /* END Msg (4:0310)-3 */
  } /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
  else
  {
    /* No action required */
  }
  /* Read the channel's measurement mode */
  /* QAC Warning: START Msg(2:4342)-23 */
  LenMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
  /* END Msg(2:4342)-23 */
  /* Implements:  ICU_ESDD_UD_045                                         */
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
  {
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Disable the status for result of channel */
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* QAC Warning: START Msg(2:3892)-19 */
    Icu_GpChannelRamData[Channel].uiResultComplete = (uinteger)ICU_FALSE;
    /* END Msg(2:3892)-19 */
    /* END Msg(2:2824)-20 */
    /* END Msg(4:0491)-4 */

    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-3 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-3 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /*
     * If the channel is duty cycle channel, then enable interrupt for the
     * next channel also
     */
     /* QAC Warning: START Msg(2:3892)-19 */
    if (ICU_DUTY_PERIOD_ENABLED_MASK ==
    (LpTimerChannelConfig->ucChannelProperties&ICU_DUTY_PERIOD_ENABLED_MASK))
    /* END Msg(2:3892)-19 */
    {
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Read channel configuration pointer */
      LpChannelConfig = &Icu_GpChannelConfig[Channel] + ICU_ONE;
      /* END Msg(4:0488)-2 */

      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

      Icu_GpChannelRamData[Channel + ICU_ONE].uiResultComplete =
                                                           (uinteger)ICU_FALSE;
      /* END Msg(4:0491)-4 */
      /* END Msg(2:3892)-19 */


      /* Check if the Interrupt register is present for particular channel */
      if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* Implements:  ICU_ESDD_UD_052                                      */
        #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
        /* Clear the pending interrupts */
        /* Implements:  ICU_ESDD_UD_045                                       */
        #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
        RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                      (ICU_CLEAR_PENDING_INTR_MASK));
        #else
        RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                                (ICU_CLEAR_PENDING_INTR_MASK));
        #endif /* #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)*/
        #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON) */
        /* Enabling the Interrupt processing */
        LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
        RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
        /* END Msg(4:0488)-2 */
        /* END Msg(4:0310)-3 */
      } /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
      else
      {
        /* No action required */
      }
      /* Implements:  ICU_ESDD_UD_045                                         */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
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
  #endif /* End of ((ICU_TAUD_UNIT_USED == STD_ON)||
  (ICU_TAUJ_UNIT_USED == STD_ON) ||(ICU_TAUB_UNIT_USED == STD_ON) */

  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:2814)-18 */
  if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                             (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
    /* END Msg(2:2814)-18 */
  #endif
  {
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUDBUnitUserReg =
        Icu_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
    /* Set the bit corresponding to the channel no. in TT register */
    ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
                                      LpChannelConfig->usChannelMaskValue)
    /* END Msg(2:2814)-18 */
    /* Check if the value was written to the TE register (TT clears TE) */
    ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
      ICU_TAUDB_TE_RESET_VAL, LpChannelConfig->usChannelMaskValue, LucSid)

    /* Set the bit corresponding to the channel no. in TS register */
    ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS,
                                      LpChannelConfig->usChannelMaskValue)
    /* Check if the value was written to the TE register (TS sets TE) */
    ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
      LpChannelConfig->usChannelMaskValue, LpChannelConfig->usChannelMaskValue,
      LucSid)

    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif /* End of
         ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
  }
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
  #endif
  {
    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_TAUJ_UNIT_USED == STD_ON)
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUJUnitUserReg =
         Icu_GaaTAUJUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
    /* Set the bit corresponding to the channel no. in TT register */
    ICU_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT,
                                (uint8)LpChannelConfig->usChannelMaskValue)
    /* END Msg(2:2814)-18 */
    /* Check if the value was written to the TE register (TT clears TE) */
    /* QAC Warning: START Msg(2:3892)-19 */
    ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJUnitUserReg->ucTE,
      ICU_TAUJ_TE_RESET_VAL, (uint8)LpChannelConfig->usChannelMaskValue, LucSid)
    /* Set the bit corresponding to the channel no. in TS register */
    ICU_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTS,
                                (uint8)LpChannelConfig->usChannelMaskValue)
    /* Check if the value was written to the TE register (TS sets TE) */
    ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJUnitUserReg->ucTE,
      (uint8)LpChannelConfig->usChannelMaskValue,
      (uint8)LpChannelConfig->usChannelMaskValue,
      LucSid)
    /* END Msg(2:3892)-19 */

    /* Implements:  ICU_ESDD_UD_045                                         */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
  }

} /* End of Internal function Icu_HW_StartCountMeasurement */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_HW_StopCountMeasurement
**
** Service ID           : None
**
** Description          : This service routine stops the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
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
** Preconditions        : None
**
** Global Variables     :Icu_GpTimerChannelConfig, Icu_GpChannelConfig,
**                       Icu_GpTAUUnitConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : TAUDnTT, TAUBnTT, TAUJnTT,
**                        TAUDnTE, TAUBnTE, TAUJnTE,
**                        ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU219_Conf */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* Implements:  ICU_ESDD_UD_120, ICU_ESDD_UD_001 */
/* QAC Warning: START Msg(2:3227)-22 */
/* QAC Warning: START Msg(2:3206)-26 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_StopCountMeasurement
(Icu_ChannelType Channel, uint8 LucSid)
/* END Msg(2:3227)-22 */
/* END Msg(2:3206)-26 */
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LenMeasurementMode;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD/B registers */
  P2VAR(TAUDBUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBUnitUserReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(TAUJUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJUnitUserReg;
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON)\
  || (ICU_TAUB_UNIT_USED == STD_ON))

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Read channel configuration pointer */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];

  /* Update the TAU configuration pointer to point to the current TAU */
  /* QAC Warning: START Msg(2:2814)-18 */
  LpTAUUnitConfig =
                  &Icu_GpTAUUnitConfig[LpTimerChannelConfig->ucTimerUnitIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* END Msg(2:2814)-18 */

  /* Implements:  ICU_ESDD_UD_045                                         */
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Disabling the Interrupt processing */
  /* QAC Warning: START Msg(2:2814)-18 */
  LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
  RH850_SV_MODE_ICR_OR(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_DIS));
  /* END Msg(2:2814)-18 */


  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Read the channel's measurement mode */
  /* QAC Warning: START Msg(2:4342)-23 */
  LenMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
  /* END Msg(2:4342)-23 */
  if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
  {
    /*
     * If the channel is duty cycle channel, then disable interrupt for the
     * next channel also
     */
     /* QAC Warning: START Msg(2:3892)-19 */
    if (ICU_DUTY_PERIOD_ENABLED_MASK ==
    (LpTimerChannelConfig->ucChannelProperties&ICU_DUTY_PERIOD_ENABLED_MASK))
    /* END Msg(2:3892)-19 */
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Read channel configuration pointer */
      LpChannelConfig = &Icu_GpChannelConfig[Channel] + ICU_ONE;
      /* END Msg(4:0491)-4 */
      /* END Msg (4:0488)-2 */
      /* END Msg(2:3892)-19 */
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Disabling the Interrupt processing */
      LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;

      RH850_SV_MODE_ICR_OR(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_DIS)) ;

      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
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
  #endif /* End of ((ICU_TAUD_UNIT_USED == STD_ON)||
  (ICU_TAUJ_UNIT_USED == STD_ON) ||(ICU_TAUB_UNIT_USED == STD_ON) */

  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                      && (ICU_TAUJ_UNIT_USED == STD_ON))
  /* QAC Warning: START Msg(2:2814)-18 */
  if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                               (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
  /* END Msg(2:2814)-18 */
  #endif
  {
    #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUDBUnitUserReg =
        Icu_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
    /* Set the bit corresponding to the channel no. in TT register */
    ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
                                    LpChannelConfig->usChannelMaskValue)
    /* END Msg(2:2814)-18 */
    /* Check if the value was written to the TE register (TT clears TE) */
    ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
      ICU_TAUDB_TE_RESET_VAL, LpChannelConfig->usChannelMaskValue, LucSid)

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif
  }
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                      && (ICU_TAUJ_UNIT_USED == STD_ON))
  else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
  #endif
  {
    #if (ICU_TAUJ_UNIT_USED == STD_ON)
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUJUnitUserReg =
         Icu_GaaTAUJUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
    /* Clear the bit corresponding to the channel no. in TT register */
    ICU_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT,
                                    (uint8)LpChannelConfig->usChannelMaskValue)
    /* END Msg(2:2814)-18 */
    /* QAC Warning: START Msg(2:3892)-19 */
    ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJUnitUserReg->ucTE,
      ICU_TAUJ_TE_RESET_VAL, (uint8)LpChannelConfig->usChannelMaskValue, LucSid)
    /* END Msg(2:3892)-19 */

    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif
  }

} /* End of Internal function Icu_HW_StopCountMeasurement */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_HW_GetEdgeNumbers
**
** Service ID           : None
**
** Description          : This service routine counts the number of edges
**                        for the given channel.
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
** Preconditions        : None
**
** Global Variables     :Icu_GpChannelConfig, Icu_GpEdgeCountData,
**                       Icu_GpTimerChannelConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : TAUDnCDRm, TAUBnCDRm, TAUDnCNTm, TAUBnCNTm.
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_121, ICU_ESDD_UD_001 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* QAC Warning: START Msg(2:3227)-22 */
/* QAC Warning: START Msg(2:3206)-26 */
/* Implements: ICU_ESDD_UD_121, ICU_ESDD_UD_001 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_GetEdgeNumbers(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
/* END Msg(2:3206)-26 */
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;

  /* Pointer definition for Signal Measurement RAM data */
  P2VAR(Icu_EdgeCountChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                                LpEdgeCountData;

  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUDBChannelReg;
  uint8 LucRamIndex;

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Read channel configuration pointer */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];

  /* Read the channel ram index */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucRamIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */
  /* Read Edge Count Data pointer */
  LpEdgeCountData = &Icu_GpEdgeCountData[LucRamIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:2814)-18 */
  LpTAUDBChannelReg = Icu_GaaTAUDBChReg_BaseAddress
                                           [LpChannelConfig->ucCntlRegsIndx];
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Storing the Edge count value into RAM */
  LpEdgeCountData->usIcuEdgeCount =
                        LpTAUDBChannelReg->usCDR - LpTAUDBChannelReg->usCNT;
  /* END Msg(2:2814)-18 */

  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif

} /* End of Internal function Icu_HW_GetEdgeNumbers */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name         : Icu_HW_ResetEdgeCount
**
** Service ID            : None
**
** Description           : This service resets the Timer Counter of the channel
**                         which is configured in Edge Counting Mode.
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
** Preconditions         : None
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpEdgeCountData,
**                         Icu_GpTimerChannelConfig, Icu_GpTAUUnitConfig,
**                         Icu_GpChannelRamData.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION and
**                         ICU_EXIT_CRITICAL_SECTION
**
** Registers Used        : TAUDnTS, TAUBnTS, TAUDnTT, TAUBnTT, TAUDnTE, TAUBnTE.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_122 */
#if (ICU_EDGE_COUNT_API == STD_ON)

#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */
/* Implements:  ICU_ESDD_UD_122 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_ResetEdgeCount(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the Timer registers */
  P2VAR(Icu_ChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA) LpRamData;
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  uint8 LucIndex;

  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;

  /* Defining a pointer to point to the TAUD/B user registers */
  P2VAR(TAUDBUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUDBUnitUserReg;

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];

  /*
   * Update the Timer channel configuration pointer to point to the current
   * channel
   */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */

  /* Read the RAM index */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:3892)-19 */
  /* Reset the overflow flag */
  Icu_GpEdgeCountData[LucIndex].uiTimerOvfFlag = ICU_FALSE;
  /* END Msg(2:3892)-19 */

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig =
                  &Icu_GpTAUUnitConfig[LpTimerChannelConfig->ucTimerUnitIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */

  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:2814)-18 */
  if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                             (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
  /* END Msg(2:2814)-18 */
  {
    LpTAUDBUnitUserReg =
       Icu_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Load the channel data pointer */
    LpRamData = &Icu_GpChannelRamData[Channel];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* QAC Warning: START Msg(2:2814)-18 */
    if (ICU_TRUE == LpRamData->uiChannelMeasurementRunning)
    /* END Msg(2:3892)-19 */
    {
      /* Set the bit corresponding to the channel no. in TS register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS,
            LpChannelConfig->usChannelMaskValue)
      /* END Msg(2:2814)-18 */
      /* Check if the value was written to the TE register (TS sets TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
            LpChannelConfig->usChannelMaskValue,
            LpChannelConfig->usChannelMaskValue,
            ICU_RESET_EDGE_COUNT_SID)
      /* Set the bit corresponding to the channel no. in TT register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
            LpChannelConfig->usChannelMaskValue)
      /* Check if the value was cleared in TE (TT clears TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
            ICU_TAUDB_TE_RESET_VAL,
            LpChannelConfig->usChannelMaskValue,
            ICU_RESET_EDGE_COUNT_SID)
      /* Set the bit corresponding to the channel no. in TS register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS,
            LpChannelConfig->usChannelMaskValue)
      /* Check if the value was written to the TE register (TS sets TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
            LpChannelConfig->usChannelMaskValue,
            LpChannelConfig->usChannelMaskValue,
            ICU_RESET_EDGE_COUNT_SID)
    }
    else
    {
      /* Set the bit corresponding to the channel no. in TS register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS,
            LpChannelConfig->usChannelMaskValue)
      /* Check if the value was written to the TE register (TS sets TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
            LpChannelConfig->usChannelMaskValue,
            LpChannelConfig->usChannelMaskValue,
            ICU_RESET_EDGE_COUNT_SID)
      /* Set the bit corresponding to the channel no. in TT register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
            LpChannelConfig->usChannelMaskValue)
      /* Check if the value was cleared in TE (TT clears TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
            ICU_TAUDB_TE_RESET_VAL, LpChannelConfig->usChannelMaskValue,
            ICU_RESET_EDGE_COUNT_SID)
    }

  }
  else
  {
    /* No action required */
  }
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if ((ICU_TAUD_UNIT_USED == STD_ON) || \
                               (ICU_TAUB_UNIT_USED == STD_ON)) */
} /* End of Internal function Icu_HW_ResetEdgeCount */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of
           ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HW_EnableEdgeDetection
**
** Service ID           : None
**
** Description          : This service routine starts the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
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
** Preconditions        : None
**
** Global Variables     : Icu_GpChannelConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_123 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */
/* Implements:  ICU_ESDD_UD_123 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_EnableEdgeDetection
(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* Check if the Interrupt register is present for particular channel */
  /* QAC Warning: START Msg(2:2814)-18 */
  if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
  /* END Msg(2:2814)-18 */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Implements:  ICU_ESDD_UD_052                                      */
    #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* Clear the pending interrupts */
    #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                  (ICU_CLEAR_PENDING_INTR_MASK));
    #else
    RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                            (ICU_CLEAR_PENDING_INTR_MASK));
    #endif /* #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON) */
    #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON) */
    /* Enabling the Interrupt processing */
    /* QAC Warning: START Msg(2:2814)-18 */
    LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
    RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
    /* END Msg(2:2814)-18 */
    /* END Msg(4:0488)-2 */
    /* END Msg(4:0310)-3 */
    /* MISRA Violation: START Msg(4:3138)-8 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
  else
  {
    /* No action required */
  }
} /* End of Internal function Icu_HW_EnableEdgeDetection */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/*******************************************************************************
** Function Name        : Icu_HW_DisableEdgeDetection
**
** Service ID           : None
**
** Description          : This service routine stops the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
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
** Preconditions        : None
**
** Global Variables     : Icu_GpChannelConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_132 */
#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */
/* Implements:  ICU_ESDD_UD_132 */
FUNC(void, ICU_PRIVATE_CODE) Icu_HW_DisableEdgeDetection
(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */

{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Disable the Interrupt processing */
  /* QAC Warning: START Msg(2:2814)-18 */
  LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
  RH850_SV_MODE_ICR_OR(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_DIS));
   /* END Msg(2:2814)-18 */
  #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  /* MISRA Violation: START Msg(4:3138)-8 */
  ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
  /* END Msg(4:3138)-8 */
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
} /* End of Internal function Icu_HW_DisableEdgeDetection */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/*******************************************************************************
** Function Name         : Icu_TimerIsr
**
** Service ID            : None
**
** Description           : This service routine invokes the required function
**                         based on the channel configuration for further
**                         calculations.
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
** Preconditions         : None
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                         Icu_GpChannelRamData, Icu_GpEdgeCountData,
**                         Icu_GpWakeUpFactorRamAddress.
**
** Functions invoked     : Icu_ServiceSignalMeasurement, Icu_ServiceTimestamp,
**                         ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                         and EcuM_CheckWakeup.
**
** Registers Used        : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm,
**                         WUF0, WUF1, WUF20, WUFC0, WUFC1 and WUFC20.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_039,ICU_ESDD_UD_040,ICU_ESDD_UD_041*/
/* Implements:  ICU_ESDD_UD_205 */
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) \
    || (ICU_TAUB_UNIT_USED == STD_ON))

#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:0890)-29 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0890)-29 */
/* END Msg(2:0832)-21 */

/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_FAST_CODE) Icu_TimerIsr(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Define a pointer to point to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Defining a pointer to point to the TAUD/B registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBChannelReg;
  #endif
  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif
  #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* Defining a pointer to point to the WUF0 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf0Reg;
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  /* Defining a pointer to point to the WUF1 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf1Reg;
  #endif
  /* Defining a pointer to point to the WUF20 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf20Reg;
  VAR(uint32, AUTOMATIC) LulWufReg;
  #endif
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType LulWakeupSourceVal;
  #endif
  Icu_MeasurementModeType LenMeasurementMode;
  uint32 LulCapturedTimestampVal;
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  uint8 LucIndex;
  #endif

  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel pointer to point to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the timer channel pointer to point to the current channel */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  #endif
  /* Read the channel's measurement property */
  /* QAC Warning: START Msg(2:4342)-23 */
  /* QAC Warning: START Msg(2:2814)-18 */
  LenMeasurementMode =
              (Icu_MeasurementModeType)(LpChannelConfig->uiIcuMeasurementMode);
  /* END Msg(2:4342)-23 */
  /* END Msg(2:2814)-18 */

  /* Check whether the channel is configured for Signal Measurement */
  if (ICU_MODE_SIGNAL_MEASUREMENT == LenMeasurementMode)
  {
    /* Process Signal Measurement */
    Icu_ServiceSignalMeasurement(Channel);


    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* Set channel input status as active */
    Icu_GpChannelRamData[Channel].uiChannelStatus = (uinteger)ICU_ACTIVE;
    /* END Msg(2:2824)-20 */
    Icu_GpChannelRamData[Channel].uiResultComplete = (uinteger)ICU_TRUE;
    /* END Msg(4:0491)-4 */
    /* END Msg(2:3892)-19 */

  }
  /* Check whether the channel is configured for Timestamp */
  else if (ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode)
  {

    #if (ICU_NOTIFICATION_CONFIG == STD_ON)
    /* Implements:  ICU318, SWS_Icu_00318   */
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* Check if notification is enabled */
    if ((uinteger)ICU_TRUE ==
                        (Icu_GpChannelRamData[Channel].uiNotificationEnable))
    /* END Msg(4:0491)-4 */
    {
      /* Check if the function pointer address is present for particular
       * channel
       */
      if (NULL_PTR != LpChannelConfig->pIcuNotificationPointer)
      {
        /* callback notification */
        LpChannelConfig->pIcuNotificationPointer();
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
    #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */

    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* Set channel input status as active */
    Icu_GpChannelRamData[Channel].uiChannelStatus = (uinteger)ICU_ACTIVE;
    /* END Msg(4:0491)-4 */
    /* END Msg(2:3892)-19 */

  }
  /* Check whether the channel is configured for Timestamp */
  else if (ICU_MODE_TIMESTAMP == LenMeasurementMode)
  {
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
                           (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    #endif
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      LpTAUDBChannelReg =
               Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];


      /* Calculate captured value */
      /* QAC Warning: START Msg(2:2814)-18 */
      LulCapturedTimestampVal =
                      ((uint32)(LpTAUDBChannelReg->usCDR)+(uint32)ICU_ONE);
      /* END Msg(2:2814)-18 */


      /* Process Timestamp */
      Icu_ServiceTimestamp(Channel, LulCapturedTimestampVal);

      #endif /* End of
          ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    }
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
    else if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
    /* END Msg(2:3892)-19 */
    #endif
    {
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      LpTAUJChannelReg = Icu_GaaTAUJChReg_BaseAddress
                                            [LpChannelConfig->ucCntlRegsIndx];

      /* Calculate captured value */
      /* QAC Warning: START Msg(2:2814)-18 */
      /* QAC Warning: START Msg(2:3892)-19 */
      LulCapturedTimestampVal = (LpTAUJChannelReg->ulCDR) + ICU_ONE;
      /* END Msg(2:2814)-18 */
      /* END Msg(2:3892)-19 */


      /* Process Timestamp */
      Icu_ServiceTimestamp(Channel, LulCapturedTimestampVal);

      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    }
    #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif
  }
  else /* if (ICU_MODE_TIMESTAMP == LenMeasurementMode) */
  {
    #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* Read the edge count RAM index */
    /* QAC Warning: START Msg(2:2814)-18 */
    LucIndex = LpTimerChannelConfig->ucRamDataIndex;
    /* END Msg(2:2814)-18 */

    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* Set the edge count overflow flag */
    Icu_GpEdgeCountData[LucIndex].uiTimerOvfFlag = ICU_TRUE;
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    /* END Msg(2:3892)-19 */


    #if (ICU_NOTIFICATION_CONFIG == STD_ON)
    /* Check if the function pointer address is present for particular
     * channel
     */
    if (NULL_PTR != LpChannelConfig->pIcuNotificationPointer)
    {
      /* callback notification */
      LpChannelConfig->pIcuNotificationPointer();
    }
    else
    {
      /* No action required */
    }
    #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */
    #endif /*
            * End of
            * ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
            */
  }

  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* Implements:    ICU055, SWS_Icu_00055   */
  /* Implements:    ICU056, SWS_Icu_00056   */
  /* Implements:    ICU057, SWS_Icu_00057   */
  /* Implements:    ICU228, SWS_Icu_00228   */
  /* Implements:    ICU229, SWS_Icu_00229   */
  /* If Module was in SLEEP mode and reporting wakeup is enabled */
  /* QAC Warning: START Msg(2:3892)-19 */
  if ( (ICU_MODE_SLEEP == Icu_GenModuleMode) &&
       (ICU_FALSE == LpChannelConfig->uiIcuDisableEcumWakeupNotification) &&
       (ICU_NOWAKEUP != LpChannelConfig->ddEcuMChannelWakeupInfo) )
  /* END Msg(2:3892)-19 */
  {
    /* MISRA Violation: START Msg(4:4471)-9 */
    /* MISRA Violation: START Msg(4:0491)-4 */
    LulWakeupSourceVal = Icu_GpChannelConfig[Channel].ddEcuMChannelWakeupInfo;
    /* END Msg(4:0491)-4 */
    /* Report Wakeup Event to EcuM */
    EcuM_CheckWakeup(LulWakeupSourceVal);

    /* END Msg(4:4471)-9 */
  }
  else
  {
    /* No action required */
  }

  #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* Set the Wake up Factor Registers to Local Pointer */
  /* MISRA Violation: START Msg(4:0303)-14*/
  /* Implements:  ICU_ESDD_UD_157 */
  LpWuf0Reg  = (volatile WUFReg*)ICU_WAKEUP_FACTOR0_REG;
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  LpWuf1Reg  = (volatile WUFReg*)ICU_WAKEUP_FACTOR1_REG;
  #endif
  LpWuf20Reg = (volatile WUFReg*)ICU_WAKEUP_FACTOR20_REG;
  /* END Msg(4:0303)-14*/
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf0Reg)
  {
  /* END Msg(4:2995)-16 */
  /* END Msg(4:2991)-15 */
    /* Check the WUF Factor flags */
    LulWufReg = LpWuf0Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF0MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf0Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf0Reg->ulWUF0, (~LulWufReg),
                                  ICU_MASK_FIRST_32_BITS, ICU_TIMERISR_LL_ID)
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
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf1Reg)
  {
  /* END Msg(4:2995)-16 */
  /* END Msg(4:2991)-15 */
    /* Check the WUF Factor flags */
    LulWufReg = LpWuf1Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF1MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf1Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf1Reg->ulWUF0, (~LulWufReg),
                                  ICU_MASK_FIRST_32_BITS, ICU_TIMERISR_LL_ID)
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
  #endif /* End of (ICU_WUF1_SUPPORTED == STD_ON) */
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf20Reg)
  {
  /* END Msg(4:2995)-16 */
  /* END Msg(4:2991)-15 */
    /* Check the WUF20 Factor flags */
    LulWufReg = LpWuf20Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF20MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf20Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf20Reg->ulWUF0, (~LulWufReg),
                                  ICU_MASK_FIRST_32_BITS, ICU_TIMERISR_LL_ID)
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
  #endif /* End of (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) */
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
} /* End of Internal function Icu_TimerIsr */

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /*
        * End of
        * ((ICU_TAUD_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)
        * || (ICU_TAUB_UNIT_USED == STD_ON))
        */

/*******************************************************************************
** Function Name        : Icu_ServiceSignalMeasurement
**
** Service ID           : None
**
** Description          : This service routine calculates the channel's Signal
**                        Time (Low, High, Period or Duty) based on its
**                        configuration.
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
** Preconditions        : None
**
** Global Variables     :Icu_GpChannelConfig, Icu_GpSignalMeasurementData,
**                       Icu_GpTimerChannelConfig.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used        : TAUDnCDRm, TAUBnCDRm, TAUJnCDRm.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_125, ICU_ESDD_UD_039, ICU_ESDD_UD_040 */
/* Implements:  ICU_ESDD_UD_041 */
#if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUJ_UNIT_USED == STD_ON) || \
(ICU_TAUB_UNIT_USED == STD_ON))
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */

FUNC(void, ICU_FAST_CODE)Icu_ServiceSignalMeasurement
(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;

  /* Define a pointer to point to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Pointer definition for Signal Measurement RAM data */
  P2VAR(Icu_SignalMeasureChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                          LpSignalMeasureData;
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD/B registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBChannelReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif

  uint8 LucMeasureProperty;
  uint8 LucRamIndex;
  /* Read channel configuration pointer */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
  /* END Msg(2:2824)-20 */

  /* Read the channel ram index */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucRamIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */
  /* Read channel measurement property */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpSignalMeasureData = &Icu_GpSignalMeasurementData[LucRamIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  LucMeasureProperty = LpTimerChannelConfig->ucChannelProperties;

  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  /* QAC Warning: START Msg(2:2814)-18 */
  /* QAC Warning: START Msg(2:3892)-19 */
  if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
                           (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
  /* END Msg(2:2814)-18 */
  /* END Msg(2:3892)-19 */
  #endif
  {
    #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUDBChannelReg = Icu_GaaTAUDBChReg_BaseAddress
                                            [LpChannelConfig->ucCntlRegsIndx];
    /* END Msg(2:2814)-18 */

    /* QAC Warning: START Msg(2:3892)-19 */
    if (((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_HIGH_TIME_MASK) ||
       ((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_LOW_TIME_MASK))
    /* Calculate Active time */
    /* END Msg(2:3892)-19 */
    {
      /* Implements:    ICU314, SWS_Icu_00314   */
      /* QAC Warning: START Msg(2:2814)-18 */
      LpSignalMeasureData->ulSignalActiveTime =
                          ((uint32)(LpTAUDBChannelReg->usCDR)+(uint32)ICU_ONE);
      /* END Msg(2:2814)-18 */

    }
    else /* (LucMeasureProperty == (ICU_PERIOD_TIME)) */
    {
      LpSignalMeasureData->ulPrevSignalActiveTime =
                                       LpSignalMeasureData->ulSignalActiveTime;

      LpSignalMeasureData->ulSignalPeriodTime =
                          ((uint32)(LpTAUDBChannelReg->usCDR)+(uint32)ICU_ONE);

    }


    #endif /* End of
          ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
  }
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */
  else if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
    /* END Msg(2:3892)-19 */
  #endif
  {
    #if (ICU_TAUJ_UNIT_USED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-18 */
    LpTAUJChannelReg = Icu_GaaTAUJChReg_BaseAddress
                                          [LpChannelConfig->ucCntlRegsIndx];
    /* END Msg(2:2814)-18 */

    /* QAC Warning: START Msg(2:3892)-19 */
    if (((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_HIGH_TIME_MASK) ||
          ((LucMeasureProperty&ICU_HIGH_LOW_TIME_MASK) == ICU_LOW_TIME_MASK))
    /* END Msg(2:3892)-19 */
    /* Calculate Active time */
    {
    /* QAC Warning: START Msg(2:2814)-18 */
    /* QAC Warning: START Msg(2:3892)-19 */
      LpSignalMeasureData->ulSignalActiveTime =
                                        ((LpTAUJChannelReg->ulCDR) +ICU_ONE);
    /* END Msg(2:2814)-18 */
    /* END Msg(2:3892)-19 */

    }
    else /* (LucMeasureProperty == (ICU_PERIOD_TIME)) */
    {
      LpSignalMeasureData->ulPrevSignalActiveTime =
                                     LpSignalMeasureData->ulSignalActiveTime;
    /* QAC Warning: START Msg(2:3892)-19 */

      LpSignalMeasureData->ulSignalPeriodTime =
                                        ((LpTAUJChannelReg->ulCDR) + ICU_ONE);
     /* END Msg(2:3892)-19 */

    }

    #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
  }
  #if (((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  else
  {
    /* To avoid MISRA warning */
  }
  #endif

} /* End of Internal function Icu_ServiceSignalMeasurement */

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of
        * ((ICU_TAUD_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) ||
        * (ICU_TAUB_UNIT_USED == STD_ON))
        */

/*******************************************************************************
** Function Name         : Icu_ServiceTimestamp
**
** Service ID            : None
**
** Description           : This service routine captures the channel's Timestamp
**                         data based on its active edge configuration.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Channel, LulCapturedTimestampVal
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      :Icu_GpChannelConfig, Icu_GpTimeStampData,
**                        Icu_GpTimerChannelConfig, Icu_GpChannelRamData.
**
** Functions invoked     : ICU_ENTER_CRITICAL_SECTION and
**                         ICU_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_126 */
#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_FAST_CODE)Icu_ServiceTimestamp
(Icu_ChannelType Channel, uint32 LulCapturedTimestampVal)
/* END Msg(2:3227)-22 */
{
  #if (ICU_NOTIFICATION_CONFIG == STD_ON)
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  #endif  /*if (ICU_NOTIFICATION_CONFIG == STD_ON) */
  /*
   * Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* Defining a pointer to point to the Timestamp data parameters */
  P2VAR(Icu_TimeStampChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                                LpTimestampdata;
  /* Local variable used to store the ram index of the channel */
  uint8 LucRamIndex;
  #if (ICU_NOTIFICATION_CONFIG == STD_ON)
  /* Update the channel pointer to point to the current channel */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(2:2824)-20 */
  /* END Msg(4:0491)-4 */
  /* MISRA Violation: START Msg(4:0491)-4 */
  #endif  /*if (ICU_NOTIFICATION_CONFIG == STD_ON) */
  /* Load timer channel configuration pointer and channel properties */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpTimerChannelConfig = &Icu_GpTimerChannelConfig[Channel];
  /* Read channel ram index */
  /* END Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:2814)-18 */
  LucRamIndex = LpTimerChannelConfig->ucRamDataIndex;
  /* END Msg(2:2814)-18 */

  /* Read the Timestamp channel data pointer */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpTimestampdata = &Icu_GpTimeStampData[LucRamIndex];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* MISRA Violation: START Msg(4:0489)-1 */
  /* QAC Warning: START Msg(2:2814)-18 */
  /* Check if timestamp capturing reached end of the buffer */
  if ((LpTimestampdata->usTimestampIndex) < (LpTimestampdata->usBufferSize))
  /* END Msg(2:2814)-18 */
  {
    /* Update the buffer pointer with current timestamp */
    *(LpTimestampdata->pBufferPointer) = LulCapturedTimestampVal;
    (LpTimestampdata->usTimestampIndex)++;
    (LpTimestampdata->pBufferPointer)++;
    /* END Msg(4:0489)-1 */

    /*
     * Notify if the configured number of timestamps are captured and
     * notification is enabled
     */
    #if (ICU_NOTIFICATION_CONFIG == STD_ON)

    /* QAC Warning: START Msg(2:2824)-20 */
    if ((uinteger)ICU_TRUE ==
                          Icu_GpChannelRamData[Channel].uiNotificationEnable)
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    {
      (LpTimestampdata->usTimestampsCounter)++;
      /* Implements:    ICU065, SWS_Icu_00065   */
      if ((LpTimestampdata->usTimestampsCounter) ==
         (LpTimestampdata->usNotifyInterval))
      {
        /* Reset the number of timestamp captured counter */
        /* QAC Warning: START Msg(2:3892)-19 */
        LpTimestampdata->usTimestampsCounter = ICU_TIMESTAMP_RESET_CNT_VAL;
        /* END Msg(2:3892)-19 */
        /* Check if the function pointer address is present for particular
         * channel
         */
        /* Implements:  ICU378, SWS_Icu_00378   */
        /* QAC Warning: START Msg(2:2814)-18 */
        if (NULL_PTR != LpChannelConfig->pIcuNotificationPointer)
            /* END Msg(2:2814)-18 */
        {
          /* callback notification */
          LpChannelConfig->pIcuNotificationPointer();
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
    } /* if (ICU_TRUE == Icu_GpChannelRamData[Channel].uiNotificationEnable) */
    else
    {
      /* No action required */
    }

    #endif  /*if (ICU_NOTIFICATION_CONFIG == STD_ON) */
    /* Check whether the timestamp index has reached the end of buffer */
    if ((LpTimestampdata->usTimestampIndex) >= (LpTimestampdata->usBufferSize))
    {
      /* Implements:    ICU064, SWS_Icu_00064   */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /*  Check if buffer is configured as circular */
      /* QAC Warning: START Msg(2:3892)-19 */
      if (ICU_TS_CIRCULAR_BUFFER_MASK ==
      (LpTimerChannelConfig->ucChannelProperties&ICU_TS_CIRCULAR_BUFFER_MASK))
      {
        /* Reset buffer pointer and index */
        LpTimestampdata->usTimestampIndex = ICU_BUFFER_IDX_INIT_VAL;
        /* END Msg(2:3892)-19 */
        LpTimestampdata->pBufferPointer =
               LpTimestampdata->pBufferPointer - LpTimestampdata->usBufferSize;
        /* END Msg (4:0488)-2 */
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

} /* End of Internal function Icu_ServiceTimestamp */

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/*******************************************************************************
** Function Name        : Icu_ExternalInterruptIsr
**
** Service ID           : None
**
** Description          : This service routine is invoked from all the external
**                        interrupts which takes care of calling the
**                        notification functions.
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
** Preconditions        : None
**
** Global Variables     :Icu_GpChannelConfig, Icu_GenModuleMode,
**                       Icu_GpWakeUpFactorRamAddress, Icu_GpChannelRamData.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION, ICU_EXIT_CRITICAL_SECTION
**                        and EcuM_CheckWakeup.
**
** Registers Used       : WUF0, WUF1, WUF20, WUFC0, WUFC1 and WUFC20
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_127, ICU_ESDD_UD_032 */
#if (ICU_EDGE_DETECT_API == STD_ON)

#define ICU_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

/* QAC Warning: START Msg(2:3227)-22 */
FUNC(void, ICU_FAST_CODE) Icu_ExternalInterruptIsr (Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to point to the channel configuration parameters */
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) || \
      (ICU_NOTIFICATION_CONFIG == STD_ON)
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) || \
          * (ICU_NOTIFICATION_CONFIG == STD_ON)
          */
  #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* Defining a pointer to point to the WUF0 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf0Reg;
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  /* Defining a pointer to point to the WUF1 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf1Reg;
  #endif
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* Defining a pointer to point to the WUF20 registers */
  P2VAR(volatile WUFReg, AUTOMATIC, ICU_CONFIG_DATA) LpWuf20Reg;
  VAR(uint32, AUTOMATIC) LulWufReg;
  #endif /* End of (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) */
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType LulWakeupSourceVal;
  #endif
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) || \
      (ICU_NOTIFICATION_CONFIG == STD_ON)
  /* Update the channel pointer to point to the current channel */
  /* QAC Warning: START Msg(2:2824)-20 */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(2:2824)-20 */
  /* END Msg(4:0491)-4 */
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) ||
          * (ICU_NOTIFICATION_CONFIG == STD_ON)
          */

  #if (ICU_NOTIFICATION_CONFIG == STD_ON)
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* Check if notification is enabled */
  /* QAC Warning: START Msg(2:2824)-20 */
  if ((uinteger)ICU_TRUE ==
                     (Icu_GpChannelRamData[Channel].uiNotificationEnable))
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  {
    /* Check if the function pointer address is present for particular
     * channel
     */
     /* QAC Warning: START Msg(2:2814)-18 */
    if (NULL_PTR != LpChannelConfig->pIcuNotificationPointer)
     /* END Msg(2:2814)-18 */
    {
      /* callback notification */
      LpChannelConfig->pIcuNotificationPointer();
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
    /* MISRA Violation: START Msg(4:0491)-4 */
  }
  /* END Msg(4:0491)-4 */
  #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */


  /* MISRA Violation: START Msg(4:0491)-4 */
  /* Set channel input status as active */
  /* QAC Warning: START Msg(2:3892)-19 */
  /* QAC Warning: START Msg(2:2824)-20 */
  Icu_GpChannelRamData[Channel].uiChannelStatus = (uinteger)ICU_ACTIVE;
  /* END Msg(4:0491)-4 */
  /* END Msg(2:3892)-19 */
  /* END Msg(2:2824)-20 */


  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* Implements:    ICU244, SWS_Icu_00244 */
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:3892)-19 */
  /* QAC Warning: START Msg(2:2814)-18 */
  /* Implements:    ICU287 */
  /* Implements:    ICU055, SWS_Icu_00055 */
  /* Implements:    ICU056, SWS_Icu_00056 */
  /* Implements:    ICU057, SWS_Icu_00057 */
  /* If Module was in SLEEP mode and reporting wakeup is enabled */
  if ((ICU_MODE_SLEEP == Icu_GenModuleMode) &&
    (ICU_FALSE == LpChannelConfig->uiIcuDisableEcumWakeupNotification) &&
    (ICU_NOWAKEUP != LpChannelConfig->ddEcuMChannelWakeupInfo))
    /* END Msg(2:3892)-19 */
    /* END Msg(2:2814)-18 */
  {
    /* MISRA Violation: START Msg(4:4471)-9 */
    LulWakeupSourceVal = Icu_GpChannelConfig[Channel].ddEcuMChannelWakeupInfo;
    /* END Msg(4:0491)-4 */
    /* Report Wakeup Event to EcuM */
    EcuM_CheckWakeup(LulWakeupSourceVal);

    /* END Msg(4:4471)-9 */
  }
  else
  {
    /* No action required */
  }
  #if (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-14*/
  /* Set the Wake up Factor Registers to Local Pointer */
  /* Implements:    ICU_ESDD_UD_157 */
  LpWuf0Reg  = (volatile WUFReg*)ICU_WAKEUP_FACTOR0_REG;
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  LpWuf1Reg  = (volatile WUFReg*)ICU_WAKEUP_FACTOR1_REG;
  #endif
  LpWuf20Reg  = (volatile WUFReg*)ICU_WAKEUP_FACTOR20_REG;
  /* END Msg(4:0303)-14*/
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf0Reg)
  {
    /* END Msg(4:2995)-16 */
    /* END Msg(4:2991)-15 */
    /* Check the WUF Factor flags */
    LulWufReg = LpWuf0Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF0MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf0Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf0Reg->ulWUF0, (~LulWufReg),
                        ICU_MASK_FIRST_32_BITS, ICU_EXTERNALINTERRUPTISR_LL_ID)
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
  #if (ICU_WUF1_SUPPORTED == STD_ON)
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf1Reg)
  {
    /* END Msg(4:2995)-16 */
    /* END Msg(4:2991)-15 */
    /* Check the WUF Factor flags */
    LulWufReg = LpWuf1Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF1MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf1Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf1Reg->ulWUF0, (~LulWufReg),
                        ICU_MASK_FIRST_32_BITS, ICU_EXTERNALINTERRUPTISR_LL_ID)
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
  #endif /* End of (ICU_WUF1_SUPPORTED == STD_ON) */
  /* MISRA Violation: START Msg(4:2991)-15 */
  /* MISRA Violation: START Msg(4:2995)-16 */
  if (NULL_PTR != LpWuf20Reg)
  {
    /* END Msg(4:2995)-16 */
    /* END Msg(4:2991)-15 */
    /* Check the WUF20 Factor flags */
    LulWufReg = LpWuf20Reg->ulWUF0 &
                Icu_GpWakeUpFactorRamAddress->ulWUF20MaskValue;
    if (LulWufReg != ICU_DOUBLE_ZERO)
    {
      /* Clear the WUF register by writting to WUFC register */
      ICU_WRITE_REG_ONLY(&LpWuf20Reg->ulWUFC0, LulWufReg)
      /* Check is the WUF register was cleared (WUFC clears WUF) */
      ICU_WUF_CHECK_WRITE_VERIFY_RUNTIME(&LpWuf20Reg->ulWUF0, (~LulWufReg),
                        ICU_MASK_FIRST_32_BITS, ICU_EXTERNALINTERRUPTISR_LL_ID)
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
  #endif /* End of (ICU_WAKEUP_FACTOR_CLEAR_ISR == STD_ON) */
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */

} /* End of Internal function Icu_ExternalInterruptIsr */

#define ICU_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* #if (ICU_EDGE_DETECT_API == STD_ON) */


/*******************************************************************************
** Function Name         : Icu_HW_GetInputLevel
**
** Service ID            : NA
**
** Description           : This API service returns the logic voltage level
**                         of the input pin related to the ICU channel
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
** Global Variables      : Icu_GpChannelConfig.
**
** Functions invoked     : None
**
** Registers Used        : PPRn
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_137, ICU_ESDD_UD_135 */
#if (ICU_GET_INPUT_LEVEL_API == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */
/* Implements:  ICU_ESDD_UD_137, ICU_ESDD_UD_135 */
FUNC(Icu_LevelType, ICU_PRIVATE_CODE) Icu_HW_GetInputLevel
(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /*Local variable to store the return level value  */
  Icu_LevelType LenInputLevel;
  LenInputLevel = ICU_LOW;
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */
  /* QAC Warning: START Msg(2:2814)-18 */

  if (NULL_PTR !=  LpChannelConfig->pLevelReadPprAddress)
    /* END Msg(2:2814)-18 */
  {
    /* Check the port type configured */
    if (ICU_NORMAL_PORT == LpChannelConfig->ucIcuPortType)
    {
      /* Access data from 16 bit register and compare with the mask value */
      if ((*(LpChannelConfig->pLevelReadPprAddress) &
           (LpChannelConfig->usPortMaskValue)) ==
           (LpChannelConfig->usPortMaskValue))
      {
        LenInputLevel = ICU_HIGH;
      }
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* Access data from 8 bit register and compare with the mask value */
      /* MISRA Violation: START Msg(4:0310)-3 */
      if ((*(LpChannelConfig->pLevelReadPprAddress) &
           (LpChannelConfig->usPortMaskValue)) ==
           (LpChannelConfig->usPortMaskValue))
      {
        /* END Msg (4:0310)-3 */
        LenInputLevel = ICU_HIGH;
      }
      else
      {
        /* No action required */
      }
    }
  } /* End of NULL_PTR !=  LpChannelConfig->pLevelReadPprAddress */
  else
  {
    /* No action required */
  }

  return(LenInputLevel);

} /* End of Internal function Icu_HW_GetInputlevel */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_GET_INPUT_LEVEL_API == STD_ON) */
/*******************************************************************************
** Function Name         : Icu_HW_GetTAUInCountValue
**
** Service ID            : NA
**
** Description           : This API service returns the counter value of TAU
**                         timer.
**
** Sync/Async            : NA
**
** Reentrancy            : NA
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
** Global Variables      :Icu_GpChannelConfig.
**
** Functions invoked     : None
**
** Registers Used        : TAUDnCNTm, TAUBnCNTm, TAUJnCNTm.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_142, ICU_ESDD_UD_143, ICU_ESDD_UD_148 */
#if (ICU_GET_TAU_COUNT_VALUE_API == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */
/* Implements:  ICU_ESDD_UD_142, ICU_ESDD_UD_143, ICU_ESDD_UD_148 */
FUNC(Icu_CounterValueType, ICU_PRIVATE_CODE) Icu_HW_GetTAUInCountValue
(Icu_ChannelType Channel)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /*Local variable to store the return level value*/
  Icu_CounterValueType LddTAUInCounterValue;

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/B channel control registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBChannelReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)LpTAUJChannelReg;
  #endif
  /* MISRA Violation: START Msg(4:0491)-4 */
  /* QAC Warning: START Msg(2:2824)-20 */
  /* Update the channel configuration pointer to the current channel */
  LpChannelConfig = &Icu_GpChannelConfig[Channel];
  /* END Msg(4:0491)-4 */
  /* END Msg(2:2824)-20 */

  LddTAUInCounterValue = 0u;

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* QAC Warning: START Msg(2:2814)-18 */
  LpTAUJChannelReg =
                Icu_GaaTAUJChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];

  /* END Msg(2:2814)-18 */
  /* QAC Warning: START Msg(2:3892)-19 */
  if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
  /* END Msg(2:3892)-19 */
  {
   /* QAC Warning: START Msg(2:2814)-18 */
    LddTAUInCounterValue = LpTAUJChannelReg-> ulCNT;
   /* END Msg(2:2814)-18 */
  }
  else
  {
    /* No action required */
  }
  #endif
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* QAC Warning: START Msg(2:3892)-19 */

  if ((ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
                           (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
  {
  LpTAUDBChannelReg =
                Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];
    /* Get the TAUIn counter value of particular channel */
    /* QAC Warning: START Msg(2:2814)-18 */
    LddTAUInCounterValue = (uint32)(LpTAUDBChannelReg->usCNT);
    /* END Msg(2:2814)-18 */
  }
  else
  {
    /* No action required */
  }
  #endif

  /* Return the TAUIn counter value of particular channel */
  /* MISRA Violation: START Msg(4:2962)-17 */
  return(LddTAUInCounterValue);
  /* END Msg(4:2962)-17 */
} /* End of Internal function Icu_HW_GetTAUCountValue */

#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_GET_TAU_COUNT_VALUE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HW_SynchronousInit
**
** Service ID           : NA
**
** Description          : This service initializes the hardware for all the
**                        channels configured as synchronous start for signal
**                        measurement mode.
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
** Pre-conditions       : 1.APIs Icu_Init should be invoked.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     :Icu_GpChannelConfig, Icu_GpChannelRamData.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers            : ICTAUDmIn, ICTAUBmIn, ICTAUJmIn, FCLAnCTLm.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_152 */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousInit (void)
{
  #if (ICU_EDGE_DETECT_API == STD_ON)
    /* To store Channel Measurement Mode */
  Icu_MeasurementModeType LenMeasurementMode;
  /* Defining a pointer to point to the External Interrupt registers */
  uint8 LucDefaultEdge;
  #endif /* End of (ICU_EDGE_DETECT_API == STD_ON) */

  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;
  Icu_ChannelType LddChannel;

  for (LddChannel = ICU_ZERO ; LddChannel < ICU_MAX_CHANNEL; LddChannel++)
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Read channel configuration pointer */
    LpChannelConfig = &Icu_GpChannelConfig[LddChannel];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */

    #if (ICU_EDGE_DETECT_API == STD_ON)
    /* Read measurement mode */
    /* QAC Warning: START Msg(2:4342)-23 */
    /* QAC Warning: START Msg(2:2814)-18 */
    LenMeasurementMode =
               (Icu_MeasurementModeType)(LpChannelConfig->uiIcuMeasurementMode);
    /* END Msg(2:4342)-23 */
    /* END Msg(2:2814)-18 */
    LucDefaultEdge = LpChannelConfig->uiIcuDefaultStartEdge;
    if (ICU_MODE_SIGNAL_EDGE_DETECT == LenMeasurementMode)
    {
    /* QAC Warning: START Msg(2:3892)-19 */
      if ((ICU_TRUE == LpChannelConfig->uiIcuSyncStartReq) &&
      (ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType))
      /* END Msg(2:3892)-19 */
      {
        /* Write the value to the FCLA (INTP) register */
        /* QAC Warning: START Msg(2:2814)-18 */
        ICU_FCLA_WRITE_REG_AND_MIRROR(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BYPASS_FILTER, &Icu_GaaFclaRegsMirror[LddChannel].ucMirrorFCLA0CTLm)
        /* END Msg(2:2814)-18 */
        /* Check if the value was written to the FCLA (INTP) register */
        /* QAC Warning: START Msg(2:3892)-19 */
        ICU_FCLA_CHECK_WRITE_VERIFY_INIT(
        &Icu_GpfclaReg_BaseAddress->ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
        ICU_BYPASS_FILTER, ICU_MASK_FIRST_3_BITS, ICU_SYNCHRONOUS_INIT_SID)
        /* QAC Warning: START Msg(2:4342)-23 */
        if (ICU_BOTH_EDGES == (Icu_ActivationType)LucDefaultEdge)
        /* END Msg(2:3892)-19 */
        /* END Msg(2:4342)-23 */
        {
          /* Write the value to the FCLA (INTP) register */
          ICU_FCLA_WRITE_REG_AND_MIRROR(
          &Icu_GpfclaReg_BaseAddress->
                           ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_BOTH_EDGES_FILTER,
          &Icu_GaaFclaRegsMirror[LddChannel].ucMirrorFCLA0CTLm)
          /* Check if the value was written to the FCLA (INTP) register */
          /* QAC Warning: START Msg(2:3892)-19 */
          ICU_FCLA_CHECK_WRITE_VERIFY_INIT(
          &Icu_GpfclaReg_BaseAddress->
                             ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_BOTH_EDGES_FILTER, ICU_MASK_FIRST_3_BITS,
          ICU_SYNCHRONOUS_INIT_SID)
        } /* End of ICU_BOTH_EDGES == LucDefaultEdge */
          /* QAC Warning: START Msg(2:4342)-23 */

        else if (ICU_FALLING_EDGE == (Icu_ActivationType)LucDefaultEdge)
         /* END Msg(2:4342)-23 */
         /* END Msg(2:3892)-19 */
        {
          /* Write the value to the FCLA (INTP) register */
          ICU_FCLA_WRITE_REG_AND_MIRROR(
          &Icu_GpfclaReg_BaseAddress->
                              ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_FALLING_EDGE_FILTER,
          &Icu_GaaFclaRegsMirror[LddChannel].ucMirrorFCLA0CTLm)
          /* Check if the value was written to the FCLA (INTP) register */
          /* QAC Warning: START Msg(2:3892)-19 */
          ICU_FCLA_CHECK_WRITE_VERIFY_INIT(
          &Icu_GpfclaReg_BaseAddress->
                             ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_FALLING_EDGE_FILTER, ICU_MASK_FIRST_3_BITS,
          ICU_SYNCHRONOUS_INIT_SID)
        } /* End of ICU_FALLING_EDGE == LucDefaultEdge */
        else /* (LucDefaultEdge == (Icu_ActivationType)ICU_RISING_EDGE) */
        {
          /* Write the value to the FCLA (INTP) register */
          ICU_FCLA_WRITE_REG_AND_MIRROR(
          &Icu_GpfclaReg_BaseAddress->
                              ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_RISING_EDGE_FILTER,
          &Icu_GaaFclaRegsMirror[LddChannel].ucMirrorFCLA0CTLm)
          /* Check if the value was written to the FCLA (INTP) register */
          ICU_FCLA_CHECK_WRITE_VERIFY_INIT(
          &Icu_GpfclaReg_BaseAddress->
                               ucCTLn_SIG[LpChannelConfig->ucCntlRegsIndx],
          ICU_RISING_EDGE_FILTER, ICU_MASK_FIRST_3_BITS,
          ICU_SYNCHRONOUS_INIT_SID)
          /* END Msg(2:3892)-19 */
        } /* End of LucDefaultEdge == ICU_RISING_EDGE */
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
    /* QAC Warning: START Msg(2:3892)-19 */
    if ((ICU_TRUE == LpChannelConfig->uiIcuSyncStartReq) &&
                      (ICU_HW_EXT_INTP != LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    {
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* QAC Warning: START Msg(2:2824)-20 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Initialize channel status as idle */
      Icu_GpChannelRamData[LddChannel].uiChannelStatus = (uinteger)ICU_IDLE;
      /* END Msg(4:0491)-4 */
      /* END Msg(2:2824)-20 */
      /* END Msg(2:3892)-19 */
      /* Check if the Interrupt register is present for particular channel */
      if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* Implements:  ICU_ESDD_UD_052                                      */
        #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
        /* Clear the pending interrupts */
        #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
        RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                      (ICU_CLEAR_PENDING_INTR_MASK));
        #else
        RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                                (ICU_CLEAR_PENDING_INTR_MASK));
        #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON) */
        #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON) */
        /* Enabling the Interrupt processing */
        LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
        /* QAC Warning: START Msg(2:2814)-18 */
        RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
        /* END Msg(2:2814)-18 */
        /* END Msg(4:0488)-2 */
        /* END Msg(4:0310)-3 */
      } /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
      else
      {
        /* No action required */
      }
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-8 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-8 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
 }
} /* End of Internal function Icu_HW_SynchronousInit */
#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HW_SynchronousStart
**
** Service ID           : NA
**
** Description          : This service routine starts the signal measurement
**                        synchronously of more than one channel.
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
** Preconditions        : 1.APIs Icu_Init and Icu_SynchronousInit should be
**                          invoked.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GpTAUUnitConfig, Icu_GpChannelConfig,
**                        Icu_GpChannelRamData.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION.
**
** Registers Used       : TAUDnTS, TAUBnTS, TAUJnTS,
**                        TAUDnTE, TAUBnTE, TAUJnTE,
**                        ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_146 */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousStart (void)
{
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD/B user registers */
  P2VAR(TAUDBUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBUnitUserReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ user registers */
  P2VAR(TAUJUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJUnitUserReg;
  #endif

  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
  #endif

  #if (ICU_EDGE_DETECT_API == STD_ON)
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(volatile uint16, AUTOMATIC, ICU_CONFIG_DATA) LpIntrCntlReg;
  uint8 LucChannel;
  #endif

  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  uint8 LucCount;
  #endif

  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  for (LucCount = ICU_ZERO;
                    LucCount < ICU_TOTAL_TAU_UNITS_CONFIGURED; LucCount++)
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Update the TAU configuration pointer to point to the current TAU */
    LpTAUUnitConfig = &Icu_GpTAUUnitConfig[LucCount];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */

    if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                               (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      LpTAUDBUnitUserReg =
         Icu_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
      /* Set the bit corresponding to the channel no. in TS register */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTS,
                          LpTAUUnitConfig->usTAUSyncMaskValue)
      /* END Msg(2:2814)-18 */
      /* Check if the value was set in TE register (TS sets TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
        LpTAUUnitConfig->usTAUSyncMaskValue,
        LpTAUUnitConfig->usTAUSyncMaskValue,
        ICU_SYNCHRONOUS_START_SID)
      #endif
      /* End of
           ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    }
    else
    {
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      LpTAUJUnitUserReg =
          Icu_GaaTAUJUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
      /* Set the bit corresponding to the channel no. in TS register */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTS,
                          (uint8)LpTAUUnitConfig->usTAUSyncMaskValue)
      /* END Msg(2:2814)-18 */
      /* Check if the value was set in the TE register (TS sets TE) */
      /* QAC Warning: START Msg(2:3892)-19 */
      ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJUnitUserReg->ucTE,
                        (uint8)LpTAUUnitConfig->usTAUSyncMaskValue,
                        (uint8)LpTAUUnitConfig->usTAUSyncMaskValue,
                        ICU_SYNCHRONOUS_START_SID)
      /* END Msg(2:3892)-19 */
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    }
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  #endif
  #if (ICU_EDGE_DETECT_API == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-7 */
  for (LucChannel = ICU_ZERO; LucChannel < ICU_MAX_CHANNEL; LucChannel++)
  /* END Msg (4:2877)-7 */
  {
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Read channel configuration pointer */
    LpChannelConfig = &Icu_GpChannelConfig[LucChannel];
    /* Initialize channel status as idle */
    /* QAC Warning: START Msg(2:3892)-19 */
    Icu_GpChannelRamData[LucChannel].uiChannelStatus = (uinteger)ICU_IDLE;
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    /* END Msg(2:3892)-19 */
    /* Check if Sync start in enabled */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* QAC Warning: START Msg(2:2814)-18 */
    if (ICU_TRUE == LpChannelConfig->uiIcuSyncStartReq)
    /* END Msg(2:2814)-18 */
    /* END Msg(2:3892)-19 */
    {
      /* Check if channel is of the type INTP */
      /* QAC Warning: START Msg(2:3892)-19 */
      if (ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType)
      /* END Msg(2:3892)-19 */
      {
        /* Check if the Interrupt register is present for particular channel */
        if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
        {
          /* MISRA Violation: START Msg(4:0488)-2 */
          /* MISRA Violation: START Msg(4:0310)-3 */
          /* Implements:  ICU_ESDD_UD_052                                     */
          #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
          /* Clear the pending interrupts */
          #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON)
          RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                                        (ICU_CLEAR_PENDING_INTR_MASK));
          #else
          RH850_SV_CLEAR_ICR_SYNCP(16, (LpChannelConfig->pIntrCntlAdress),
                                  (ICU_CLEAR_PENDING_INTR_MASK));
          #endif /* #if (ICU_CRITICAL_SECTION_PROTECTION != STD_ON) */
          #endif /* #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)*/
          /* Enabling the Interrupt processing */
          LpIntrCntlReg = LpChannelConfig->pIntrCntlAdress;
          /* QAC Warning: START Msg(2:2814)-18 */
          RH850_SV_MODE_ICR_AND(16, (LpIntrCntlReg), (ICU_INTERRUPT_MASK_EN));
          /* END Msg(2:2814)-18 */
          /* END Msg(4:0488)-2 */
          /* END Msg(4:0310)-3 */
        }  /* End of NULL_PTR != LpChannelConfig->pIntrCntlAdress */
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Store enabled notification into RAM */
      Icu_GpChannelRamData[LucChannel].uiNotificationEnable =
                                                           (uinteger)ICU_TRUE;
      /* END Msg(4:0491)-4 */
      /* END Msg(2:3892)-19 */
    }
    else
    {
      /*no action required */
    }
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  #endif
} /* End of Internal function Icu_HW_SynchronousStart */
#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name        : Icu_HW_SynchronousStop
**
** Service ID           : None
**
** Description          : This service routine stops the count measurement
**                        for signal measurement.
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
** Preconditions        : 1.APIs Icu_Init, Icu_SynchronousInit and
**                          Icu_SynchronousStart should be invoked.
**                        2.This API is available only if the pre-compile
**                          option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables     : Icu_GpTAUUnitConfig, Icu_GpChannelConfig,
**                        Icu_GpChannelRamData.
**
** Functions invoked    : ICU_ENTER_CRITICAL_SECTION and
**                        ICU_EXIT_CRITICAL_SECTION
**
** Registers Used       : TAUDnTT, TAUBnTT, TAUJnTT,
**                        TAUDnTE, TAUBnTE, TAUJnTE,
**                        ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_147 */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousStop (void)
{
  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
  uint8 LucCount;
  #endif

  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUD/B user registers */
  P2VAR(TAUDBUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUDBUnitUserReg;
  #endif

  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ user registers */
  P2VAR(TAUJUserReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJUnitUserReg;
  #endif

  #if (ICU_EDGE_DETECT_API == STD_ON)
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  uint8 LucChannel;
  #endif

  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  for (LucCount = ICU_ZERO;
                    LucCount < ICU_TOTAL_TAU_UNITS_CONFIGURED; LucCount++)
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Update the TAU configuration pointer to point to the current TAU */
    LpTAUUnitConfig = &Icu_GpTAUUnitConfig[LucCount];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-18 */

    if ((ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
                               (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType))
    /* END Msg(2:2814)-18 */
    {
      #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      LpTAUDBUnitUserReg =
        Icu_GaaTAUDBUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
      /* Set the bit corresponding to the channel no. in TT register */
      /* QAC Warning: START Msg(2:2814)-18 */
      ICU_WRITE_REG_ONLY(&LpTAUDBUnitUserReg->usTT,
                           LpTAUUnitConfig->usTAUSyncMaskValue)
      /* Check if the TE register bits have been cleared (TT clears TE) */
      ICU_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUDBUnitUserReg->usTE,
        ICU_TAUDB_TE_RESET_VAL, LpTAUUnitConfig->usTAUSyncMaskValue,
        ICU_SYNCHRONOUS_STOP_SID)
      #endif /* End of
           ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    }
    else
    {
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
      LpTAUJUnitUserReg =
         Icu_GaaTAUJUserReg_BaseAddress[LpTAUUnitConfig->ucTAUUserCntlRegIndx];
      /* Set the bit corresponding to the channel no. in TT register */
      ICU_WRITE_REG_ONLY(&LpTAUJUnitUserReg->ucTT,
                         (uint8)LpTAUUnitConfig->usTAUSyncMaskValue)
      /* Check if the TE register bits have been cleared (TT clears TE) */
      /* END Msg(2:2814)-18 */
      /* QAC Warning: START Msg(2:3892)-19 */
      ICU_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(&LpTAUJUnitUserReg->ucTE,
        ICU_TAUJ_TE_RESET_VAL, (uint8)LpTAUUnitConfig->usTAUSyncMaskValue,
        ICU_SYNCHRONOUS_STOP_SID)
       /* END Msg(2:3892)-19 */
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    }
    #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    /* MISRA Violation: START Msg(4:3138)-8 */
    ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
    /* END Msg(4:3138)-8 */
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  #endif

  #if (ICU_EDGE_DETECT_API == STD_ON)
  /* MISRA Violation: START Msg(4:2877)-7 */
  for (LucChannel = ICU_ZERO; LucChannel < ICU_MAX_CHANNEL; LucChannel++)
  /* END Msg (4:2877)-7 */
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Read channel configuration pointer */
    LpChannelConfig = &Icu_GpChannelConfig[LucChannel];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    /* Check if Sync start in enabled */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* QAC Warning: START Msg(2:2814)-18 */
    if (ICU_TRUE == LpChannelConfig->uiIcuSyncStartReq)
    /* END Msg(2:3892)-19 */
    /* END Msg(2:2814)-18 */
    {
      /* Check if channel is of the type INTP */
    /* QAC Warning: START Msg(2:3892)-19 */
      if (ICU_HW_EXT_INTP == LpChannelConfig->uiIcuChannelType)
    /* END Msg(2:3892)-19 */
      {
        #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
        #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* MISRA Violation: START Msg(4:0491)-4 */
        /* Initialize channel status as idle */
        /* QAC Warning: START Msg(2:2824)-20 */
        /* QAC Warning: START Msg(2:3892)-19 */
        Icu_GpChannelRamData[LucChannel].uiChannelStatus = (uinteger)ICU_IDLE;
        /* END Msg(4:0491)-4 */
        /* END Msg(2:3892)-19 */
        /* END Msg(2:2824)-20 */
        /* Check if the Interrupt register is present for particular channel */
        #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Critical Section */
        /* MISRA Violation: START Msg(4:3138)-3 */
        ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
        /* END Msg(4:3138)-3 */
        #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
        {
          /* MISRA Violation: START Msg(4:0488)-2 */
          /* MISRA Violation: START Msg(4:0310)-3 */
          /* Implements:  ICU_ESDD_UD_052                                     */
          #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
          /* Clear the pending interrupts */
          RH850_SV_MODE_ICR_AND(16,(LpChannelConfig->pIntrCntlAdress),
                         (ICU_CLEAR_PENDING_INTR_MASK));

          #endif
          /* Disabling the Interrupt processing */
          RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAdress),
                            (ICU_INTERRUPT_MASK_DIS));
          /* END Msg(4:0488)-2 */
          /* END Msg(4:0310)-3 */
        }   /* End of LpChannelConfig->pIntrCntlAdress != NULL_PTR */
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }

      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_ENTER_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Store enabled notification into RAM */
      Icu_GpChannelRamData[LucChannel].uiNotificationEnable =
                                                          (uinteger)ICU_FALSE;
      #if (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Critical Section */
      /* MISRA Violation: START Msg(4:3138)-3 */
      ICU_EXIT_CRITICAL_SECTION(ICU_CHANNEL_DATA_PROTECTION);
      /* END Msg(4:3138)-3 */
      #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    /* END Msg(4:0491)-4 */
    /* END Msg(2:3892)-19 */
    else
    {
     /* No action required */
    }
  }
  #endif
} /* End of Internal function Icu_HW_SynchronousStop */
#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name         : Icu_HW_SynchronousDeInit
**
** Service ID            : None
**
** Description           : This service De-initializes the hardware for all the
**                         channels configured as synchronous start for signal
**                         measurement mode.
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
** Preconditions         : 1.APIs Icu_Init and Icu_SynchronousInit
**                           should be invoked.
**                         2.This API is available only if the pre-compile
**                           option ICU_SYNC_START_STOP_SUPPORT is STD_ON.
**
** Global Variables      : Icu_GpChannelConfig, Icu_GpChannelRamData.
**
** Functions invoked     : None
**
** Registers Used        : ICTAUDmIn, ICTAUBmIn, ICTAUJmIn.
**
*******************************************************************************/
/* Implements:  ICU_ESDD_UD_153 */
#if (ICU_SYNC_START_STOP_SUPPORT == STD_ON)

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

FUNC(void, ICU_PRIVATE_CODE) Icu_HW_SynchronousDeInit (void)
{
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  Icu_ChannelType LddChannel;
  for (LddChannel = ICU_ZERO ; LddChannel < ICU_MAX_CHANNEL; LddChannel++)
  {
    /* MISRA Violation: START Msg(4:0491)-4 */
    /* QAC Warning: START Msg(2:2824)-20 */
    /* Read channel configuration pointer */
    LpChannelConfig = &Icu_GpChannelConfig[LddChannel];
    /* END Msg(4:0491)-4 */
    /* END Msg(2:2824)-20 */
    /* QAC Warning: START Msg(2:3892)-19 */
    /* QAC Warning: START Msg(2:2814)-18 */

    if ((ICU_TRUE == LpChannelConfig->uiIcuSyncStartReq) &&
                      (ICU_HW_EXT_INTP != LpChannelConfig->uiIcuChannelType))
    /* END Msg(2:3892)-19 */
    /* END Msg(2:2814)-18 */
    {
      /* MISRA Violation: START Msg(4:0491)-4 */
      /* QAC Warning: START Msg(2:2824)-20 */
      /* QAC Warning: START Msg(2:3892)-19 */
      /* Initialize channel status as idle */
      Icu_GpChannelRamData[LddChannel].uiChannelStatus = (uinteger)ICU_IDLE;
      /* END Msg(4:0491)-4 */
      /* END Msg(2:2824)-20 */
      /* END Msg(2:3892)-19 */
      /* Check if the Interrupt register is present for particular channel */
      if (NULL_PTR != LpChannelConfig->pIntrCntlAdress)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        /* MISRA Violation: START Msg(4:0310)-3 */
        /* Implements:  ICU_ESDD_UD_052                                      */
        #if (ICU_CLEAR_PENDING_INTERRUPT == STD_ON)
        /* Clear the pending interrupts */
        RH850_SV_MODE_ICR_AND(16, (LpChannelConfig->pIntrCntlAdress),
                         (ICU_CLEAR_PENDING_INTR_MASK));

        #endif
        /* Disabling the Interrupt processing */
        RH850_SV_MODE_ICR_OR(16, (LpChannelConfig->pIntrCntlAdress),
                          (ICU_INTERRUPT_MASK_DIS));
        /* END Msg(4:0488)-2 */
        /* END Msg(4:0310)-3 */
      } /* End of LpChannelConfig->pIntrCntlAdress != NULL_PTR */
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
} /* End of Internal function Icu_HW_SynchronousDeInit */
#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */

#endif /* End of (ICU_SYNC_START_STOP_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name        : Icu_HWCheckConsistency
**
** Service ID           : None
**
** Description          : This is ICU Driver Component support function.
**                        This API compares the control register values with its
**                        corresponding RAM mirror variable if
**                        ICU_TAUDB_RAM_MIRROR or ICU_TAUJ_RAM_MIRROR or
**                        ICU_FCLA_RAM_MIRROR is ICU_MIRROR_ENABLE.
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
**                        option ICU_TAUDB_RAM_MIRROR or ICU_TAUJ_RAM_MIRROR
**                        or ICU_FCLA_RAM_MIRROR is STD_ON.
**
** Global Variables     :Icu_GpPreviousInputConfig(R), Icu_GpChannelConfig(R)
**                       Icu_GpTAUUnitConfig(R), Icu_GpTimerChannelConfig(R),
**                       Icu_GaaRegMirror_8bit(R), Icu_GaaReg_8bit(R).
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : TAUDnTPS, TAUBnTPS, TAUJnTPS, TAUDnBRS, TAUJnBRS,
**                        TAUDnCDRm, TAUBnCDRm, TAUBnCMORm, TAUDnCMORm,
**                        TAUJnCMORm, SELB_TAUD0I.
**
*******************************************************************************/
/* Implements: ICU_ESDD_UD_167, ICU_ESDD_UD_226 */
#if ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE )    ||  \
      (ICU_TAUJ_RAM_MIRROR  == ICU_MIRROR_ENABLE )    ||  \
      (ICU_FCLA_RAM_MIRROR  == ICU_MIRROR_ENABLE ) )

#define ICU_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:3227)-22 */

FUNC(Std_ReturnType, ICU_PRIVATE_CODE) Icu_HWCheckConsistency
                                   (Icu_HWConsistencyModeType HWConsistencyMode)
/* END Msg(2:3227)-22 */
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannelConfig;
  /* Implements: ICU_ESDD_UD_036 */
  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpTAUUnitConfig;
  #if ((ICU_TAUD_UNIT_CONFIG == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/B Unit control registers */
  P2VAR(TAUDBOsReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUDBUnitOsReg;
  #endif
  #if (ICU_TAUJ_UNIT_CONFIG == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(TAUJOsReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUJUnitOsReg;
  #endif
  #endif /*End of (ICU_PRESCALER_CONFIGURED == STD_ON))*/
  #if ((ICU_TAUD_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUD/B channel control registers */
  P2VAR(TAUDBChReg volatile, AUTOMATIC, ICU_CONFIG_DATA) LpTAUDBChannelReg;
  #endif
  #if (ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(TAUJChReg volatile, AUTOMATIC, ICU_CONFIG_DATA)
  LpTAUJChannelReg;
  #endif
  /* Implements: ICU_ESDD_UD_044 */
  #if (ICU_TIMER_CH_CONFIGURED == STD_ON)
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpTimerChannelConfig;
  #endif
  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Defining a pointer to the previous input configuration parameters */
  P2CONST(Icu_PreviousInputUseType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpPreviousInputConfig;
  /* Defining a pointer to the previous input Control Register */
  P2VAR(uint16 volatile, AUTOMATIC, ICU_CONFIG_DATA) LpPrevInputCntrlReg;
  #endif

  /* Declare the variable to store the DET return value */
  Std_ReturnType LddRetConsistencyState;
  uint8 LucChIdx;

  /* Implements: ICU_ESDD_UD_037 */
  #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Update the previous input use pointer to point to the current channel */
  LpPreviousInputConfig = Icu_GpPreviousInputConfig;
  #endif

  LddRetConsistencyState = E_OK;

  /* check static registers*/
  if (ICU_STATIC == HWConsistencyMode)
  {
    /* Check TPS and BRS regis for TAUDB and TAUJ if prescaler is configured */
    /* Implements: ICU_ESDD_UD_036 */
    #if ( (ICU_PRESCALER_CONFIGURED == STD_ON) && \
          (ICU_TAUDBJ_UNIT_CONFIG == STD_ON) )
      /* Check all TAU UNITS */
      /* Implements: ICU_ESDD_UD_042 */
      for (LucChIdx = ICU_ZERO; LucChIdx < ICU_TOTAL_TAU_UNITS_CONFIGURED;
                                                                    LucChIdx++)
      {
        /* MISRA Violation: START Msg(4:0491)-4 */
        /* QAC Warning: START Msg(2:2824)-20 */
        /* Update the TAU configuration pointer to point to the current TAU */
        LpTAUUnitConfig = &Icu_GpTAUUnitConfig[LucChIdx];
        /* END Msg(4:0491)-4 */
        /* END Msg(2:2824)-20 */

        #if (ICU_TAUDB_UNIT_CONFIG == STD_ON)
          /* Prescaler was configured for either TAUD of TAUB */
          /* Check consistency for TPS, BRS for TAUD and TPS for TAUB */
          /* QAC Warning: START Msg(2:2814)-18 */
          if ( (ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
               (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType) )
          /* END Msg(2:2814)-18 */
          {
            LpTAUDBUnitOsReg =
             Icu_GaaTAUDBOsReg_BaseAddress[LpTAUUnitConfig->ucTAUOsCntlRegIndx];
            /* QAC Warning: START Msg(2:3892)-19 */
            /* QAC Warning: START Msg(2:2814)-18 */
            if ((ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler) &&
                (LpTAUUnitConfig->usPrescaler != LpTAUDBUnitOsReg->usTPS))
            /* END Msg(2:2814)-18 */
            /* END Msg(2:3892)-19 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Consistency check E_OK */
              /* Or not required if timer unit doe not configure prescaler */
            }
            #if (ICU_TAUD_UNIT_CONFIG == STD_ON)
            /* QAC Warning: START Msg(2:3892)-19 */
              if ((ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler) &&
                  (ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType)    &&
                  (LpTAUUnitConfig->ucBaudRate != LpTAUDBUnitOsReg->ucBRS))
            /* END Msg(2:3892)-19 */
              {
                LddRetConsistencyState = E_NOT_OK;
              }
              else
              {
                /* Consistency check E_OK */
                /* Or not required if timer unit doe not configure prescaler */
              }
            #endif
          }
          else
          {
            /* Another timer unit is used by the current channel */
          } /* End  if ( (ICU_HW_TAUD == LpTAUUnitConfig->ucIcuUnitType) ||
             *           (ICU_HW_TAUB == LpTAUUnitConfig->ucIcuUnitType) )
             */
        #endif

        #if (ICU_TAUJ_UNIT_CONFIG == STD_ON)
          /* Prescaler was configured for TAUJ */
          /* Check consistency for TPS and BRS for TAUJ */
          if (ICU_HW_TAUJ == LpTAUUnitConfig->ucIcuUnitType)
          {
            LpTAUJUnitOsReg =
              Icu_GaaTAUJOsReg_BaseAddress[LpTAUUnitConfig->ucTAUOsCntlRegIndx];
             /* QAC Warning: START Msg(2:3892)-19 */
             /* QAC Warning: START Msg(2:2814)-18 */
            if ((ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler) &&
                (LpTAUUnitConfig->usPrescaler != LpTAUJUnitOsReg->usTPS))
            /* END Msg(2:2814)-18 */
            /* END Msg(2:3892)-19 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Consistency check E_OK */
              /* Or not required if timer unit doe not configure prescaler */
            }
            /* QAC Warning: START Msg(2:3892)-19 */
            if ((ICU_TRUE == LpTAUUnitConfig->blConfigurePrescaler) &&
                (LpTAUUnitConfig->ucBaudRate != LpTAUJUnitOsReg->ucBRS))
            /* END Msg(2:3892)-19 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Consistency check E_OK */
              /* Or not required if timer unit doe not configure prescaler */
            }
          }
          else
          {
            /* Another timer unit is used by the current channel */
          } /* End if (ICU_HW_TAUJ == LpTAUUnitConfig->ucIcuUnitType) */
        #endif /* End #if (ICU_TAUJ_UNIT_CONFIG == STD_ON) */
      } /* End TAU UNITS for loop */
    #endif /* End #if ICU_PRESCALER_CONFIGURED */

    /* Check CDR and CMOR for TAUDB and TAUJ */
    /* Implements: ICU_ESDD_UD_044 */
    #if ( (ICU_TIMER_CH_CONFIGURED == STD_ON) && \
          (ICU_TAUDBJ_UNIT_USED == STD_ON) )
      /* Check all TAU UNITS */
      /* Implements:  ICU_ESDD_UD_141 */
      for (LucChIdx = ICU_ZERO; LucChIdx < ICU_MAX_TIMER_CHANNELS_CONFIGURED;
                                                                    LucChIdx++)
      {
        /* MISRA Violation: START Msg(4:0491)-4 */
        /* QAC Warning: START Msg(2:2824)-20 */
        /* Update the channel configuration pointer to point to the
        current channel */
        LpChannelConfig = &Icu_GpChannelConfig[LucChIdx];
        LpTimerChannelConfig = &Icu_GpTimerChannelConfig[LucChIdx];
        /* END Msg(4:0491)-4 */
        /* END Msg(2:2824)-20 */

        #if (ICU_TAUDB_UNIT_USED == STD_ON)
          /* Check consistency for TAUDB, CMOR and CDR regs */
        /* QAC Warning: START Msg(2:3892)-19 */
        /* QAC Warning: START Msg(2:2000)-27 */
        /* QAC Warning: START Msg(2:2814)-18 */
          if ( (ICU_HW_TAUD == LpChannelConfig->uiIcuChannelType) ||
               (ICU_HW_TAUB == LpChannelConfig->uiIcuChannelType) )
        /* END Msg(2:3892)-19 */
        /* END Msg(2:2000)-27 */
        /* END Msg(2:2814)-18 */
          {
            LpTAUDBChannelReg =
              Icu_GaaTAUDBChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];
              /* QAC Warning: START Msg(2:2814)-18 */
            if (LpTimerChannelConfig->usChannelModeOSRegSettings !=
                LpTAUDBChannelReg->usCMOR)
              /* END Msg(2:2814)-18 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Consistency check E_OK */
            }
            /* QAC Warning: START Msg(2:3892)-19 */
            /* QAC Warning: START Msg(2:4342)-23 */

            if ( (ICU_MODE_EDGE_COUNTER == (Icu_MeasurementModeType)
                  LpChannelConfig->uiIcuMeasurementMode) &&
                  (ICU_TAUDB_START_DWNCNT_VAL != LpTAUDBChannelReg->usCDR) )
            /* END Msg(2:4342)-23 */
            /* END Msg(2:3892)-19 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Another measurement mode or ROM Consistency check E_OK */
            }

          }
      #endif
      #if (ICU_TAUJ_UNIT_USED == STD_ON)
          /* Check consistency for TAUJ, CMOR */
          /* CDR not checked because TAUJ does not support edge count */
          /* QAC Warning: START Msg(2:3892)-19 */
          /* QAC Warning: START Msg(2:2000)-27 */
          if (ICU_HW_TAUJ == LpChannelConfig->uiIcuChannelType)
          /* END Msg(2:3892)-19 */
          /* END Msg(2:2000)-27 */
          {
            LpTAUJChannelReg =
              Icu_GaaTAUJChReg_BaseAddress[LpChannelConfig->ucCntlRegsIndx];
            /* QAC Warning: START Msg(2:2814)-18 */
            if (LpTimerChannelConfig->usChannelModeOSRegSettings !=
                LpTAUJChannelReg->usCMOR)
            /* END Msg(2:2814)-18 */
            {
              LddRetConsistencyState = E_NOT_OK;
            }
            else
            {
              /* Consistency check E_OK */
            }
          }
      #endif
      } /* End for all ICU_MAX_TIMER_CHANNELS_CONFIGURED */
    #endif /* End ICU_TIMER_CH_CONFIGURED */

      /* Implements: ICU_ESDD_UD_037 */
    #if (ICU_PREVIOUS_INPUT_USED == STD_ON)
      /* Check consistency for SELB_TAUD0 register */
      /* Implements: ICU_ESDD_UD_038 */
      for (LucChIdx = ICU_ZERO; LucChIdx < ICU_TOTAL_UNITS_FOR_PREVINPUT;
                                                                    LucChIdx++)
      {
        LpPrevInputCntrlReg =
          LpPreviousInputConfig[LucChIdx].pPreviousInputCntlRegs;
        if (*LpPrevInputCntrlReg !=
                    ((*LpPrevInputCntrlReg) |
                     (LpPreviousInputConfig[LucChIdx].usPreviousInputMask)) )
        {
          LddRetConsistencyState = E_NOT_OK;
        }
        else
        {
          /* Consistency check E_OK */
        }
      }
    #endif /* End of (ICU_PREVIOUS_INPUT_USED == STD_ON) */
  } /* End of if (ICU_STATIC == HWConsistencyMode) */
  else if (ICU_DYNAMIC == HWConsistencyMode)
  {
    /* MISRA Violation: START Msg(4:2877)-7 */
    for (LucChIdx = ICU_ZERO; (LucChIdx < ICU_MAX_8BIT_REGISTERS); LucChIdx++)
      /* END Msg(4:2877)-7 */
    {
      if (  (*(Icu_GaaReg_8bit[LucChIdx])) !=
            (*(Icu_GaaRegMirror_8bit[LucChIdx]))  )
      {
        LddRetConsistencyState = E_NOT_OK;
      }
      else
      {
        /* Consistency check E_OK */
      }
    }
  }
  else
  {
    /* invalid input parameter */
  }

  return(LddRetConsistencyState);
}
#define ICU_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-21 */
/* QAC Warning: START Msg(2:0862)-28 */
#include ICU_MEMMAP_FILE
/* END Msg(2:0862)-28 */
/* END Msg(2:0832)-21 */

#endif /* End of ( (ICU_TAUDB_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
                    (ICU_TAUJ_RAM_MIRROR == ICU_MIRROR_ENABLE ) || \
                    (ICU_FCLA_RAM_MIRROR == ICU_MIRROR_ENABLE ) )*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
