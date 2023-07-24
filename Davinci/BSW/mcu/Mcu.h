/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, MCU type definitions, structure data types and  */
/* API function prototypes of MCU Driver                                      */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0:  07-Sep-2015 : Initial Version                                       *
* V1.0.1:  18-Dec-2015 : 1. Start and end for MISRA Msg(4:3458) has been added *
*                        inside switch 'MCU_DEV_ERROR_DETECT'.                 *
*                        2. As part of fix for #ARDAAGA-77, the service        *
*                        macro id MCU_GET_VERSIONINFO_SID has been removed and *
*                        Mcu_GetVersionInfo has been changed from macro to     *
*                        function                                              *
* V2.0.0:  14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore  *
*                         - MCU_AR_HIGHER_VERSION is changed to 4.2.2          *
*                         - MCU_AR_LOWER_VERSION is changed to 4.0.3           *
*                         - Removed code related to AUTOSAR 3.2.2              *
* V2.0.1:  28-Oct-2016 : ARDAABD-473 - History numbering changed according to  *
*                         projects requirements                                *
*                        ARDAABD-790 - Write sequence to protected registers   *
*                         changed to a macro                                   *
* V2.1.0:  01-Nov-2016 : ARDAABD-569 - FuSa reguirements for ASIL-B implemented*
*                         - Mcu_CheckHWConsistency API created as part of      *
*                         the hardware consistency check(HWCC)                 *
*                        ARDAABD-473 - Changed function definition of          *
*                         Mcu_DistributePllClock for ASR4.2.2                  *
*                         - Include for Mcu_Cfg.h file added                   *
* V2.2.0:  18-Nov-2016 : ARDAABD-569 - Mcu_CheckHWConsistency API prototype    *
*                         updated by adding new parameter to select the        *
*                         the type of HWCC(static or dynamic registers)        *
* V2.3.0:  29-Nov-2016 : ARDAABD-569 - Include for Mcu_Ram.h file added        *
* V2.4.0:  16-Dec-2016 : ARDAABD-806 - MCU_E_INIT_FAILED Det code definition   *
*                         added                                                *
* V2.5.0:  28-Dec-2016 : ARDAABD-831 - QAC warnings related to macro           *
*                         Mcu_ProtectedWrite removed                           *
* V2.6.0:  26-Jan-2017 : ARDAABD-473 - Included file Mcu_Debug.h removed for   *
*                         ASR4.2.2                                             *
* V2.7.0:  31-Jan-2017 : ARDAABD-989 - Included macro MCU_MEMMAP_FILE instead  *
*                         Memmap.h file                                        *
* V2.8.0:  08-Feb-2017 : ARDAABD-569 - Changed the values of compiler switch   *
*                         MCU_RAM_MIRROR to MCU_MIRROR_ENABLE and              *
*                         MCU_MIRROR_DISABLE                                   *
* V2.9.0:  17-Feb-2017 : ARDAABD-831 - Remove explicit casts from the          *
*                         Mcu_ProtectedWrite Macro , for not setting bigger    *
*                         values than register can accept                      *
* V2.10.0: 10-Mar-2017 : ARDAABD-1210 - Add Traceability                       *
* V2.11.0: 29-Aug-2017 : ARDAABD-2150 -Added QAC/MISRA Warnings justification. *
*                        Corrected QAC/MISRA Warning.                          *
* V2.12.0: 25-Sep-2017 : ARDAABD-2135 - Added compiler switch                  *
*                        MCU_RETENTIONRAM_REQ over functions                   *
*                        Mcu_Intvec_CalcRange and Mcu_Code_CalcRange           *
* V2.13.0: 05-Oct-2017 : ARDAABD-2588 - Added changes after FuSa checklist     *
* V2.14.0: 16-Oct-2017 : 1. ARDAABD-2594 - Added changes after QAC             *
*                        2. ARDAABD-2531 - Change Macro name Mcu_ProtectedWrite*
*                        to MCU_PROTECTED_WRITE.                               *
* V2.14.1: 11-Jul-2018 : Following changes are done as part of merging         *
*                        activities ARDAABD-3490,                              *
*                        1.As part of #ARDAABD-908, folllowing changes are done*
*                        Mapped variable under memory section                  *
*                        MCU_<START/STOP>_SEC_DBTOC_DATA_UNSPECIFIED to        *
*                        MCU_<START/STOP>_SEC_CONFIG_DATA_UNSPECIFIED.         *
*                        2.As part of #ARDAABD-3850, traceability              *
*                        inconsistencies are corrected and requirement         *
*                        mapping is done.                                     */
/******************************************************************************/

#ifndef MCU_H
#define MCU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* To publish the type Mcu_ConfigType */
#include "Mcu_Types.h"
/* MCU_H_041: MCU_ESDD_UD_083                                                */
/* MCU_H_043: MCU211, SWS_Mcu_00211                                          */
/* Included for pre-compile options */
#include "Mcu_Cfg.h"
#if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Mcu_Debug.h"
#endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON)*/
#endif /* #if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION) */
#include "Mcu_Ram.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
#define MCU_VENDOR_ID  MCU_VENDOR_ID_VALUE
#define MCU_MODULE_ID  MCU_MODULE_ID_VALUE
/* MCU_H_037:  MCU_ESDD_UD_019                                                */
#define MCU_INSTANCE_ID  MCU_INSTANCE_ID_VALUE

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)

/* AUTOSAR release version information */
#define MCU_AR_RELEASE_MAJOR_VERSION    4
#define MCU_AR_RELEASE_MINOR_VERSION    2
#define MCU_AR_RELEASE_REVISION_VERSION 2

#elif (MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)

/* AUTOSAR release version information */
#define MCU_AR_RELEASE_MAJOR_VERSION    4
#define MCU_AR_RELEASE_MINOR_VERSION    0
#define MCU_AR_RELEASE_REVISION_VERSION 3

#endif

/* Module Software version information */
#define MCU_SW_MAJOR_VERSION       MCU_SW_MAJOR_VERSION_VALUE
#define MCU_SW_MINOR_VERSION       MCU_SW_MINOR_VERSION_VALUE
#define MCU_SW_PATCH_VERSION       MCU_SW_PATCH_VERSION_VALUE
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */
/******************************************************************************/
/* 3.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-3 and               */
/*                 END Msg(2:0832)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857)Number of macro definitions exceeds 1024 - program */
/*                 does not conform strictly to ISO:C99.                      */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-4 and                           */
/*                 END Msg(4:0857)-4 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/

/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements:  SWS_Mcu_00211, SWS_Mcu_00215,                                 */
/* Implements:  MCU015                                                        */
/*******************************************************************************
**                      Macros Section                                        **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-4 */
/* MISRA Violation: START Msg(4:3458)-2 */
#define MCU_PROTECTED_WRITE(pControlReg, value, pProtCmdReg,\
        pProtStatReg, loopcount, retvalue )\
{\
  do\
  {\
    (*(pProtCmdReg)) = MCU_WRITE_DATA;\
    (*(pControlReg)) = (value);\
    (*(pControlReg)) = (~(value));\
    (*(pControlReg)) = (value);\
    (loopcount)= (loopcount) - MCU_ONE;\
  } while ((MCU_ZERO < (loopcount)) && \
                       (MCU_LONG_WORD_ONE == (*(pProtStatReg))));\
 if (MCU_LONG_WORD_ONE == (*(pProtStatReg)))\
  {\
    (*(retvalue)) = E_NOT_OK;\
  }\
  else\
  {\
    (*(retvalue)) = E_OK;\
  }\
}
/* END Msg(4:3458)-2 */
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Service IDs */
/* Service Id of Mcu_Init API */
#define MCU_INIT_SID                        (uint8)0x00
/* Service Id of Mcu_InitRamSection API */
#define MCU_INITRAMSECTION_SID              (uint8)0x01
/* Service Id of Mcu_InitClock API */
#define MCU_INITCLOCK_SID                   (uint8)0x02
/* Service Id of Mcu_DistributePllClock API */
#define MCU_DISTRIBUTEPLLCLOCK_SID          (uint8)0x03
/* Service Id of Mcu_GetPllStatus API */
#define MCU_GETPLLSTATUS_SID                (uint8)0x04
/* Service Id of Mcu_GetResetReason API */
#define MCU_GETRESETREASON_SID              (uint8)0x05
/* Service Id of Mcu_GetResetRawValue API */
#define MCU_GETRESETRAWVAULE_SID            (uint8)0x06
/* Service Id of Mcu_PerformReset API */
#define MCU_PERFORMRESET_SID                (uint8)0x07
/* Service Id of Mcu_SetMode API */
#define MCU_SETMODE_SID                     (uint8)0x08
/* Service Id of Mcu_GetVersionInfo API */
#define MCU_GETVERSIONINFO_SID              (uint8)0x09

/* Service Id of Mcu_GetRamState API */
#define MCU_GETRAMSTATE_SID                 (uint8)0x0A

/* Service Id of Mcu_SequencerInit API */
#define MCU_SEQUENCERINIT_SID               (uint8)0x0B

/* Service Id of Mcu_SequencerStart API */
#define MCU_SEQUENCERSTART_SID              (uint8)0x0C

/* Service Id of Mcu_SequencerStop API */
#define MCU_SEQUENCERSTOP_SID                (uint8)0x0D

/* Service Id of Mcu_CopyToSection API */
#define MCU_COPYTOSECTION_SID                (uint8)0x0E

/* Service Id of Mcu_SequencerDiCmpValueSet API */
#define MCU_SEQUENCERDICMPVALUESET_SID       (uint8)0x0F

/* Service Id of Mcu_CheckHWConsistency API */
#define MCU_HWCHECKCONSISTENCY_SID           (uint8)0x10

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* MCU_H_001:  MCU_ESDD_UD_059                                                */
/* MCU_H_002:  MCU018, MCU016, MCU012, MCU112                                 */
/* MCU_H_003:  SWS_Mcu_00018, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_004:  SWS_Mcu_00112                                                  */
/* DET Code to report NULL pointer passed to Mcu_Init API */
#define MCU_E_PARAM_CONFIG            (uint8)0x0A

/* MCU_H_005:  MCU_ESDD_UD_060                                                */
/* MCU_H_006:  MCU019, MCU016, MCU012, MCU112                                 */
/* MCU_H_007:  SWS_Mcu_00019, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_038:  SWS_Mcu_00112                                                  */
/* DET Code for invalid Clock Setting */
#define MCU_E_PARAM_CLOCK             (uint8)0x0B

/* MCU_H_008:  MCU_ESDD_UD_061                                                */
/* MCU_H_010:  MCU020, MCU016, MCU012, MCU112                                 */
/* MCU_H_011:  SWS_Mcu_00020, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_012:  SWS_Mcu_00112                                                  */
/* DET Code for invalid Operation Mode */
#define MCU_E_PARAM_MODE              (uint8)0x0C

/* MCU_H_013:  MCU_ESDD_UD_062                                                */
/* MCU_H_014:  MCU021, MCU016, MCU012, MCU112                                 */
/* MCU_H_015:  SWS_Mcu_00021, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_016:  SWS_Mcu_00112                                                  */
/* DET Code for invalid RAM Section handle */
#define MCU_E_PARAM_RAMSECTION        (uint8)0x0D

/* MCU_H_017:  MCU_ESDD_UD_063                                                */
/* MCU_H_018:  MCU122, MCU016, MCU012, MCU112                                 */
/* MCU_H_019:  SWS_Mcu_00122, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_020:  SWS_Mcu_00112                                                  */
/* DET Code to report that PLL Clock is not locked */
#define MCU_E_PLL_NOT_LOCKED          (uint8)0x0E

/* MCU_H_021:  MCU_ESDD_UD_064                                                */
/* MCU_H_022:  MCU125, MCU016, MCU012, MCU112                                 */
/* MCU_H_023:  SWS_Mcu_00125, SWS_Mcu_00016, SWS_Mcu_00012                    */
/* MCU_H_024:  SWS_Mcu_00112                                                  */
/* DET code to report uninitialized state */
#define MCU_E_UNINIT                  (uint8)0x0F

/* MCU_H_025:  MCU_ESDD_UD_066                                                */
/* MCU_H_026:  SWS_Mcu_00012, SWS_Mcu_000112                                  */
/* DET code to report invalid database */
#define MCU_E_INVALID_DATABASE        (uint8)0xED

/* MCU_H_027:  MCU_ESDD_UD_065                                                */
/* MCU_H_028:  SWS_Mcu_00015, SWS_Mcu_00112                                   */
/* DET code to report invalid mode sequence call */
#define MCU_E_INVALID_MODE_SEQUENCE   (uint8)0xEF

/* MCU_H_029:  MCU_ESDD_UD_110                                                */
/* MCU_H_030:  SWS_Mcu_00012, SWS_Mcu_00016, SWS_Mcu_00112                    */
/* DET code to report invalid Sequencer setting */
#define MCU_E_PARAM_SEQUENCER         (uint8)0xFA

/* MCU_H_031:  MCU_ESDD_UD_165                                                */
/* MCU_H_032:  MCU012                                                         */
/* MCU_H_033:  SWS_Mcu_00204                                                  */
/* DET code to report NULL_PTR when passed as a parameter to GetVersionInfo */
#define MCU_E_PARAM_POINTER          (uint8)0x10

#if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
/* DET code to report Initialization Failed */
#define MCU_E_INIT_FAILED            (uint8)0x11
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* MCU_H_042: EAAR_PN0034_NR_0088                                             */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */

extern void MCU_FEINT_ENTRY(void);
extern void MCU_FEINT_LEAVE(void);

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
(Mcu_RamSectionType RamSection);

/* MCU_H_040:  MCU_ESDD_UD_045                                                */
#if (MCU_INIT_CLOCK == STD_ON)

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock
(Mcu_ClockType ClockSetting);

#endif

/* MCU_H_039:  MCU_ESDD_UD_045                                                */
#if (MCU_NO_PLL == STD_OFF)

#if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void);
#else
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void);
#endif

#endif

extern FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void);

extern FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void);

extern FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void);

/* MCU_H_034:  MCU_ESDD_UD_021                                                */
#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset (void);
#endif

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode);
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_WakeUpFactor_Preparation
                                               (Mcu_ModeType McuMode);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* MISRA Violation: START Msg(4:3458)-2 */
#define MCU_DET_REPORTERROR(ApiId, ErrorId)\
{ \
  (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, ApiId, ErrorId); \
}
/* END Msg(4:3458)-2 */
#else
#define MCU_DET_REPORTERROR(ApiId, ErrorId)
#endif
/* MISRA Violation: START Msg(4:3458)-2 */
#if (MCU_VERSION_INFO_API == STD_ON)
extern FUNC(void,MCU_PUBLIC_CODE) Mcu_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_CONST) versioninfo);
/* END Msg(4:3458)-2 */
#endif /* (MCU_VERSION_INFO_API == STD_ON) */


/* MCU_H_035: MCU_ESDD_UD_022                                                 */
#if (MCU_GET_RAM_STATE_API == STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void);
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerInit(Mcu_SeqType
                           McuSequencer);
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerStart(
                 Mcu_SeqOperationType McuSeqMode);
extern FUNC(void, MCU_PUBLIC_CODE)Mcu_SequencerStop(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_SequencerDiCmpValueSet
                                          ( uint8 ucDpinId , boolean blDpinVal);
#endif /* if (MCU_LOW_POWER_SEQUENCER == STD_ON) */

#if (MCU_SW_RESET_CALL_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE)MCU_RESET_CALLOUT(void);
#endif

#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_CheckHWConsistency(
                            const Mcu_HWConsistencyCheckType CheckType);
#endif /* (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */

#if (MCU_RETENTIONRAM_REQ == STD_ON)
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
FUNC(void, MCU_PUBLIC_CODE)Mcu_Rram_Cyclic_Run(void);
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
#endif


/* MCU_H_044:  MCU_ESDD_UD_114                                               */
#if (MCU_COPY_TO_SECTION_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CopyToSection(void);
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
#if (MCU_RETENTIONRAM_REQ == STD_ON)
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
FUNC(void, MCU_PUBLIC_CODE)Mcu_Intvec_CalcRange(uint32 * ulIntVecSecStartAddr,
               uint32 *ulIntVecSize);
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
FUNC(void, MCU_PUBLIC_CODE)Mcu_Code_CalcRange(uint32 * ulCodeSecStartAddr,
               uint32 *ulCodeSize);
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
#endif /*MCU_RETENTIONRAM_REQ == STD_ON*/
#else
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_CopyToSection(void);
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
/* Structure for MCU Init configuration */
/* MCU_H_036:  MCU_ESDD_UD_037                                                */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[];
/* END Msg(4:3684)-1 */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
/* END Msg(4:0857)-4 */
#endif /* MCU_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
