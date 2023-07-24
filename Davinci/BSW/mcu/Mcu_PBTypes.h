/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
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
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0:  07-Sep-2015 : Initial Version                                       *
*                                                                              *
* V1.0.1:  08-Jan-2016 : The following changes are done                        *
*                        1. As part of the JIRA #ARDAAGA-42,                   *
*                        new macros - REG_CKSC_PPLCLKS_CTL &                   *
*                        REG_CKSC_PPLCLKS_ACT- added for PPL                   *
*                        control registers.                                    *
*                        2. As part of fix for JIRA #ARDAAGA-157,              *
*                        new Macro 'VAL_UNAVAILABLE' has been added.           *
* V2.1.0:  10-Jun-2016 : ARDAABD-398 - MCU_LVILFEIFMSK_MASK and                *
*                        MCU_LVIHFEIFMSK_MASK masks added and MCU_LVIFEIF_MASK *
*                        removed                                               *
* V2.1.1:  14-Jun-2016 : Review points from 2.1.0 Implemented : history updated*
* V2.2.0:  22-Jul-2016 : ARDAABD-419 - MCU_LIN_HSINTOSC_MASK mask added for the*
*                        source clock settings of LIN clock domain in Stop Mode*
* V2.3.0:  05-Aug-2016 : The following changes were performed:                 *
*                        1. ARDAABD-415 - ucPllSelectedSrcClock element added  *
*                        for PLL input clock source                            *
*                        2. ARDAABD-415 - PPLCLKS changed to PPLLCLKS          *
* V2.4.0:  09-Sep-2016 : ARDAABD-398 - History entry for V2.1.0 rephrased to   *
*                        describe the specific changes implemented in the file *
* V2.5.0:  30-Sep-2016 : ARDAABD-711 - Added timeout counter for PLL lock      *
* V2.6.0:  14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore  *
*                        - MCU_AR_HIGHER_VERSION is changed to 4.2.2           *
*                        - MCU_AR_LOWER_VERSION is changed to 4.0.3            *
*                        - Removed code related to AUTOSAR 3.2.2               *
*                        ARDAABD-852 - Updated MCU_ENTER/EXIT_CRITICAL_SECTION *
*                        for AR4.2.2 and AR4.0.3 SchM API compatibility        *
* V2.7.0:  28-Oct-2016 : ARDAABD-720 - Address of PSR register type changed to *
*                        pointer to volatile                                   *
*                        ARDAABD-473 - History numbering changed according to  *
*                        projects requirements                                 *
*                        ARDAABD-764 - Define safety timeouts for MainOsc      *
*                        (MCU_MOSC_STOP_COUNT) and PLL stop                    *
*                        (MCU_PLL_STOP_COUNT)                                  *
* V2.8.0:  11-Nov-2016 : ARDAABD-710 - Define Mask for High Ring Oscillator    *
*                        add new attribute "ulSubOscStabTime" from             *
*                        configuration in Mcu_ClockSetting structure for the   *
*                        SOSC value                                            *
*                        AARDAABD-569 - Mask added for reading the default     *
*                        value of PLLC register for write verify and ram       *
*                        mirroring                                             *
*                        ARDAABD-918 - Memory class for pPortGroupAddress      *
*                        and pTAUJ0ChRegs changed to TYPEDEF                   *
*                        ARDAABD-852 - MCU_ENTER/EXIT_CRITICAL_SECTION updated *
*                        with infix informations also for ASR 4.0.3            *
* V2.9.0:  05-Dec-2016 : ARDAABD-918 - Memory class for pCkscSel and           *
*                        pDigitalInputModeSetting changed to TYPEDEF           *
* V2.10.0: 07-Dec-2016 : ARDAABD-781 - Macros names were updated according to  *
*                        the format <MSN>_<NameOfIdentifier> for               *
*                        REG_CKSC , NOT_USED , VAL_UNAVAILABLE and             *
*                        MCU_MASK_WAKE_UP_FACTOR_REGISTERS macros              *
* V2.10.1: 09-Dec-2016 : ARDAABD-720 - Unused structure type Mcu_PortRegisters *
*                        removed                                               *
* V2.10.2: 16-Dec-2016 : ARDAABD-710 - Use MCU_SAFETY_LOOP_COUNT with value of *
*                        0x03E8U instead of MCU_CLK_SOURCE_SET_COUNT,          *
*                        MCU_CLK_DIV_SET_COUNT, MCU_PLL_LOCK_COUNT,            *
*                        MCU_PLL_STOP_COUNT and  MCU_MOSC_STOP_COUNT           *
* V2.10.3: 28-Dec-2016 : ARDAABD-831 - Change type of Mcu_GaaClockOffset to    *
*                        uint8                                                 *
*                        - Add defines for avoiding additional casts           *
* V2.11.0: 13-Jan-2017 : ARDAABD-415 - Define for MCU_LONG_WORD_TEN added      *
* V2.12.0: 17-Jan-2017 : ARDAABD-569 - Defines for Write Verify masks added    *
* V2.13.0: 31-Jan-2017 : ARDAABD-989 - Included macro MCU_MEMMAP_FILE instead  *
*                        Memmap.h file                                         *
* V2.14.0: 14-Feb-2017 : ARDAABD-594 - MCU_C_SW_MINOR_VERSION changed to "1"   *
*                        because of multiple code changes                      *
* V2.15.0: 17-Feb-2017 : ARDAABD-831 - Type of MCU_CMOR_MSK changed to uint16  *
*                        - Second definition of MCU_LONG_WORD_THREE removed    *
* V2.16.0: 22-Feb-2017 : ARDAABD-831 - Changed integer suffixes to uppercase   *
*                        letters                                               *
* V2.17.0: 10-Mar-2017 : ARDAABD-1210 - Add Traceability                       *
* V2.18.0: 25-May-2017 : ARDAABD-1035 - MCU_MAX_CLK_SET definition moved to    *
*                        Mcu_Cfg.h because exported from configuration         *
* V2.19.0: 16-Jun-2017 : ARDAABD-1949 - MCU_PLL0C_READ_MASK and                *
*                        MCU_PLL0_CLOCK_SELECTED definition added              *
*                        - Atributes ulPLL0ControlValue and                    *
*                        ucPll0SelectedSrcClock added in Mcu_ClockSetting      *
* V2.20.0: 22-Jun-2017 : ARDAABD-1960 - Add ulPowerDownWakeupType1 member      *
*                        in MCU_ModeSetting structure in order to support      *
*                        wake up factor 1.                                     *
* V2.21.0: 20-Jul-2017 : ARDAABD-2083 - Add mask for processing  CLMA3 reset   *
*                        flag.                                                 *
* V2.22.0: 29-Aug-2017 : ARDAABD-2150 -Added QAC/MISRA Warnings justification. *
*                        Corrected QAC/MISRA Warning.                          *
* V2.23.0: 19-Sep-2017 : 1. ARDAABD-2346 - Added specific macros for registers *
*                        2. ARDAABD-2247 - Added macros for SOSCE processing   *
* V2.24.0: 03-Oct-2017 : ARDAABD-1874 - Added Ram Mirror initialization        *
*                        macro values                                          *
* V2.25.0: 16-Oct-2017 : 1. ARDAABD-2594 - Added Ram Mirror initialization     *
*                        2. ARDAABD-2409 - Added Ram mirror initialization     *
*                        macro value for PLL0C                                 *
*                        3. ARDAABD-1874 - Added specific value of             *
*                        MCU_CPUCLKD_INIT_REG_VALUE for F1KM-S4                *
*                        4. ARDAABD-1740 - Size of Mcu_GaaPortGroup array      *
*                        changed to MCU_PORT_INSTANCES + MCU_APORT_INSTANCES.  *
* V2.25.1: 28-Jun-2018 : Following changes are done as part of merging         *
*                        activities ARDAABD-3490,                              *
*                        1. As part of JIRA ARDAABD-908,                       *
*                           a.Changed memory section name from MCU_<START/STOP>*
*                             _SEC_BURAM_VAR_NOINIT_UNSPECIFIED to             *
*                             MCU_<START/STOP>_SEC_BURAM_VAR_NO_INIT_32.       *
*                           b.Added new memory section for Mcu_GaaClockOffset. *
*                        2. As part of JIRA ARDAABD-1293, Added 'blPllActCheck'*
*                           in structure Mcu_ClockSetting                      *
*                        3. As part of ARDAABD-3385, inclusion of Memmap.h     *
*                           added after MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED   *
*                           and MCU_START_SEC_CONFIG_DATA_8.                   *
*                        4. As part of ARDAABD-1853, removed macro definition  *
*                           of MCU_MAX_MODE_SET.                               *
*                        5. As part of ARDAABD-3850, traceability              *
*                           inconsistencies are corrected and requirement      *
*                           mapping is done.                                   *
*                        6. As part of ARDAABD-3695, moved threshold value     *
*                           generation of CLMA0/1/2/3 to Mcu_GstClockSetting.  *
* V2.26.0: 09-Aug-2018 : Following changes are done as part of merging         *
*                        from for_Denso branch                                 *
*                        1. As part of ARDAABD-996,Remove Mcu_ReadBackDiagTest *
*                           Remove refer Macro                                 *
*                        2. As part of ARDAABD-3109, Delete Macro              *
*                           MCU_WAKEUP_FACTOR_CLR                              *
*                        3. As part of ARDAABD-3946,macro MCU_PLL0C_READ_MASK  *
*                          (uint32)0xFFFFFFFFUL => (uint32)0x7F70787FUL modfiy *
* V2.26.1: 27-Jul-2019 : The following changes are done                        *
*                        1. As part of ARDAABD-4061, Added specific value of   *
*                           MCU_CPUCLKD_INIT_REG_VALUE for F1KH-D8             *
*                        2. As part of ARDAABD-4144, Define related macros for *
*                           the new internal private func (Mcu_IsoCkscCheck)  */
/******************************************************************************/

#ifndef MCU_PBTYPES_H
#define MCU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* MCUPBTYPES_H_021:  MCU_ESDD_UD_083                                         */
/* Included for Mcu type declarations */
#include "Mcu_Types.h"
#include "Mcu_Hardware.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_MINOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                     MCU_TYPES_AR_RELEASE_REVISION_VERSION




/* Module Software version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION  1
#define MCU_PBTYPES_SW_MINOR_VERSION  2


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
/*Message       : (4:3412) A function could probably be used instead of this  */
/*                function-like macro.                                        */
/*Rule          : MISRA-C:2004 Rule 19.4                                      */
/*Justification : An additional semi-colon is added to the critical section   */
/*                macro to avoid static analysis warning.                     */
/*Verification  : However, part of the code is verified manually and it is    */
/*                not having any impact.                                      */
/*Reference     : Look for START Msg(4:3412)-2 and END Msg(4:3412)-2 tags in  */
/*                the code.                                                   */
/*                                                                            */
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
/* 4.  QAC Warning:                                                           */
/* Message       : (2:3132)  Hard coded 'magic' number, 'X', used to define   */
/*                 the size of an array.                                      */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Because is Register type definition, the same notation     */
/*                 rules as in Iocommon.h were used                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3132)-4 and               */
/*                 END Msg(2:3132)-4 tags in the code.                        */
/******************************************************************************/


/******************************************************************************
**                      SchM Critical Section Protection Macros              **
******************************************************************************/
/* MCUPBTYPES_H_020:  MCU_ESDD_UD_033                                        */
/* MCUPBTYPES_H_025:  EAAR_PN0034_FR_0061                                    */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)

/* MISRA Violation: START Msg(4:3412)-2 */
#define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Mcu_##Exclusive_Area();

#define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Exit_Mcu_##Exclusive_Area();
/* END Msg(4:3412)-2 */


#endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Macros to avoid Magic numbers */
#define MCU_DBTOC_VALUE \
                                      (((uint32)MCU_VENDOR_ID_VALUE << 22) | \
                                       ((uint32)MCU_MODULE_ID_VALUE << 14) | \
                                       ((uint32)MCU_SW_MAJOR_VERSION << 8) | \
                                       ((uint32)MCU_SW_MINOR_VERSION << 3))

#define MCU_ZERO                      (uint8)0x00

#define MCU_LONG_WORD_ZERO            (uint32)0x00000000UL

#define MCU_LONG_WORD_ONE             (uint32)0x00000001UL

#define MCU_LONG_WORD_TWO             (uint32)0x00000002UL

#define MCU_LONG_WORD_THREE           (uint32)0x00000003UL

#define MCU_LONG_WORD_FOUR            (uint32)0x00000004UL

#define MCU_LONG_WORD_FIVE            (uint32)0x00000005UL

#define MCU_LONG_WORD_SIX             (uint32)0x00000006UL

#define MCU_LONG_WORD_EIGHT           (uint32)0x00000008UL

#define MCU_LONG_WORD_TEN             (uint32)0x0000000AUL

#define MCU_LONG_WORD_SIXTEEN         (uint32)0x00000010UL

#define MCU_LONG_WORD_TWENTY_FOUR     (uint32)0x00000018UL

#define MCU_STPM_NOT_AVAILABLE        (uint16)0xFFFF

#define MCU_ONE                       (uint8)0x01

#define MCU_TWO                       (uint8)0x02

#define MCU_THREE                     (uint8)0x03

#define MCU_FOUR                      (uint8)0x04

#define MCU_INVERTED_ONE              (uint8)0xFE

#define MCU_INVERTED_ZERO             (uint8)0xFF

#define MCU_FIVE                      (uint8)0x05

#define MCU_TEN                       (uint8)0x0A

#define MCU_THIRTY_TWO                (uint8)0x20

#define MCU_RESF_CLEAR                (uint32)0x000007FFUL

#define MCU_INITIALIZED               (boolean)0x01

#define MCU_UNINITIALIZED             (boolean)0x00

#define MCU_TRUE                      (boolean)0x01

#define MCU_FALSE                     (boolean)0x00

/* Count for Safety Loop */
#define MCU_SAFETY_LOOP_COUNT         (uint16)0x03E8U

/* Value for selection of clock source as MainOSC */
#define MCU_MAIN_OSC_SELECTED         (uint8)0x01

/* Value for selection of clock source as SubOSC */
#define MCU_SUB_OSC_SELECTED          (uint8)0x02

/* Value for selection of clock source as PLL */
#define MCU_PLL_CLOCK_SELECTED       (uint8)0x08

/* Value for selection of clock source as PLL */
#define MCU_PLL0_CLOCK_SELECTED       (uint8)0x10

/* Definition of uninitialized RESET value */
#define MCU_RESET_UNINIT              (uint32)0xFFFFFFFFUL

/* Definition for Reset source check values */
#define MCU_SWR                       (uint32)0x00000001UL
#define MCU_WDR0                      (uint32)0x00000002UL
#define MCU_WDR1                      (uint32)0x00000004UL
#define MCU_CLM0                      (uint32)0x00000008UL
#define MCU_CLM1                      (uint32)0x00000010UL
#define MCU_CLM2                      (uint32)0x00000020UL
#define MCU_LVI                       (uint32)0x00000040UL
#define MCU_CVM                       (uint32)0x00000080UL
#define MCU_TER                       (uint32)0x00000100UL
#define MCU_PURES                     (uint32)0x00000200UL
#define MCU_ISO                       (uint32)0x00000400UL
#ifdef MCU_WDG2_RESET_ENABLE
#define MCU_WDR2                      (uint32)0x00000800UL
#endif /* MCU_WDG2_RESET_ENABLE */
#define MCU_CLM3                      (uint32)0x00004000UL

/* Definition for Bit check in uint8 */
#define MCU_UINT8_BIT0                (uint8)0x01
#define MCU_UINT8_BIT1                (uint8)0x02
#define MCU_UINT8_BIT2                (uint8)0x04
#define MCU_UINT8_BIT3                (uint8)0x08
#define MCU_UINT8_BIT4                (uint8)0x10
#define MCU_UINT8_BIT5                (uint8)0x20
#define MCU_UINT8_BIT6                (uint8)0x40

/* Data to be written to the protection command register to enable
 * writing to the write protected register
 */
#define MCU_WRITE_DATA                (uint32)0x000000A5

/*
 * Definitions of values to be written to Software reset register
 * to perform reset
 */
#define MCU_RES_CORRECT_VAL           (uint32)0x00000001UL

#define MCU_RES_INVERTED_VAL          (uint32)0xFFFFFFFEUL

#define MCU_LVI_MASK                  (uint32)0x00000004UL

/* Maximum number of Mode setting */

#define MCU_MAIN_OSC_MASKED           (uint8)0x01

#define MCU_RING_OSC_MASKED           (uint8)0x04

#define MCU_MAIN_OSC_ON               (uint32)0x00000004UL

#define MCU_SUB_OSC_ON                (uint32)0x00000004UL

#define MCU_HIGHSPEED_RINGOSC_ON      (uint32)0x00000004UL

#define MCU_PLL_ON                    (uint32)0x00000004UL

#define MCU_FOUT_DISABLE_MASK         (uint32)0x00000000UL

#define MCU_LVIFEIFC_MASK             (uint32)0x00000001UL

#define MCU_PLL_CLKSTAB_MASK          (uint32)0x00000004UL

#define MCU_LVILFEIFMSK_MASK          (uint32)0x00000001UL

#define MCU_LVIHFEIFMSK_MASK          (uint32)0x00008000UL

#define MCU_LVI_RESET_MASK            (uint32)0x00000004UL

#define MCU_LVI_RESET_MASK_ENABLE     (uint32)0xFFFFFFF3UL

#define MCU_LVI_CNT_MASK              (uint32)0x00000007UL

#define MCU_STBC0DISTRG_MASK          (uint32)0x00000002UL

#define MCU_STBC0STPTRG_MASK          (uint32)0x00000001UL

#define MCU_LVI_DELAY_COUNT           (uint16)0x04FF

#define MCU_CLKDOMAIN_SRCSEL          (uint8)0x01

#define MCU_CLKDOMAIN_DIVSEL          (uint8)0x02

#define MCU_CLKDOMAIN_STPMASK         (uint8)0x04

#define MCU_CYCLIC_RUN_WAKEUP         (uint32)0x0000ffffUL

#define MCU_IOHOLD_MASK               (uint32)0x00000001UL

#define MCU_MSB_MASK                  (uint32)0xFFFF0000UL

#define MCU_DIGITAL_NUMDP_MASK       (uint32)0x00000070UL

#define MCU_TJS_MASK                 (uint32)0x0000000CUL

#define MCU_SEQ_STOP_MASK            (uint32)0x00000003UL

#define MCU_WUTRG_SEQ                (uint32)0x00080000UL

#define MCU_CLOCK_DEFAULT              (uint32)0x00000001UL

#define MCU_LIN_HSINTOSC_MASK        (uint32)0x00000004UL

#define MCU_CPU_CLOCK_ADDRESS          (uint32 *)0xfff8A000UL

#define MCU_CLKBIT_MASK                (uint8)0xCF

#define MCU_CLKBIT_SETMASK             (uint8)0x30

#define MCU_DPDSRH_OFFSET      (uint32) (MCU_DATA_SET_REGISTER + MCU_THIRTY_TWO)

#define MCU_MASK_WAKE_UP_FACTOR_REGISTERS    (uint32) 0xFFFFFFFFUL

#define MCU_VALUE_COMPARISON              (uint32)0xFFFFFFFFUL

#define MCU_VAL_UNAVAILABLE                   (uint32)0xFFFFFFFFUL

#define MCU_PLLC_READ_MASK                (uint32)0x0000183FUL

#define MCU_PLL0C_READ_MASK               (uint32)0x7F70787FUL

#define MCU_IOS_CLK_CHK_COUNT         (uint8)0x07

#define MCU_IOS_CLK_CHK_MASK          (uint8)0x7F

/* Definition for clock control check values */
#define MCU_NOT_USED                (uint8)0
#define MCU_REG_CKSC_AWDTAD_CTL     (uint8)1
#define MCU_REG_CKSC_AWDTAD_ACT     (uint8)2
#define MCU_REG_CKSC_AWDTAD_STPM    (uint8)3
#define MCU_REG_CKSC_ATAUJS_CTL     (uint8)4
#define MCU_REG_CKSC_ATAUJS_ACT     (uint8)5
#define MCU_REG_CKSC_ATAUJD_CTL     (uint8)6
#define MCU_REG_CKSC_ATAUJD_ACT     (uint8)7
#define MCU_REG_CKSC_ATAUJD_STPM    (uint8)8
#define MCU_REG_CKSC_ARTCAS_CTL     (uint8)9
#define MCU_REG_CKSC_ARTCAS_ACT     (uint8)10
#define MCU_REG_CKSC_ARTCAD_CTL     (uint8)11
#define MCU_REG_CKSC_ARTCAD_ACT     (uint8)12
#define MCU_REG_CKSC_ARTCAD_STPM    (uint8)13
#define MCU_REG_CKSC_AADCAS_CTL     (uint8)14
#define MCU_REG_CKSC_AADCAS_ACT     (uint8)15
#define MCU_REG_CKSC_AADCAD_CTL     (uint8)16
#define MCU_REG_CKSC_AADCAD_ACT     (uint8)17
#define MCU_REG_CKSC_AADCAD_STPM    (uint8)18
#define MCU_REG_CKSC_AFOUTS_CTL     (uint8)19
#define MCU_REG_CKSC_AFOUTS_ACT     (uint8)20
#define MCU_REG_CKSC_AFOUTS_STPM    (uint8)21
#define MCU_REG_CKSC_CPUCLKS_CTL    (uint8)22
#define MCU_REG_CKSC_CPUCLKS_ACT    (uint8)23
#define MCU_REG_CKSC_CPUCLKD_CTL    (uint8)24
#define MCU_REG_CKSC_CPUCLKD_ACT    (uint8)25
#define MCU_REG_CKSC_IPERI1S_CTL    (uint8)26
#define MCU_REG_CKSC_IPERI1S_ACT    (uint8)27
#define MCU_REG_CKSC_IPERI2S_CTL    (uint8)28
#define MCU_REG_CKSC_IPERI2S_ACT    (uint8)29
#define MCU_REG_CKSC_ILINS_CTL      (uint8)30
#define MCU_REG_CKSC_ILINS_ACT      (uint8)31
#define MCU_REG_CKSC_IADCAS_CTL     (uint8)32
#define MCU_REG_CKSC_IADCAS_ACT     (uint8)33
#define MCU_REG_CKSC_IADCAD_CTL     (uint8)34
#define MCU_REG_CKSC_IADCAD_ACT     (uint8)35
#define MCU_REG_CKSC_ILIND_CTL      (uint8)36
#define MCU_REG_CKSC_ILIND_ACT      (uint8)37
#define MCU_REG_CKSC_ILIND_STPM     (uint8)38
#define MCU_REG_CKSC_ICANS_CTL      (uint8)39
#define MCU_REG_CKSC_ICANS_ACT      (uint8)40
#define MCU_REG_CKSC_ICANS_STPM     (uint8)41
#define MCU_REG_CKSC_ICANOSCD_CTL   (uint8)42
#define MCU_REG_CKSC_ICANOSCD_ACT   (uint8)43
#define MCU_REG_CKSC_ICANOSCD_STPM  (uint8)44
#define MCU_REG_CKSC_ICSIS_CTL      (uint8)45
#define MCU_REG_CKSC_ICSIS_ACT      (uint8)46
#define MCU_REG_CKSC_IIICS_CTL      (uint8)47
#define MCU_REG_CKSC_IIICS_ACT      (uint8)48
#define MCU_REG_CKSC_PPLLCLKS_CTL    (uint8)49
#define MCU_REG_CKSC_PPLLCLKS_ACT    (uint8)50

/*Write verify Masks */
#define MCU_FOUTDIV_MSK             (uint32)0x0000001FUL
#define MCU_MOSCC_MSK               (uint32)0x00000007UL
#define MCU_MOSCST_MSK              (uint32)0x0001FFFFUL
#define MCU_STPM_MSK                (uint32)0x00000003UL
#define MCU_SOSCST_MSK              (uint32)0x3FFFFFFFUL
#define MCU_CLMACMP_MSK             (uint32)0x00000FFFUL
#define MCU_RESF_MSK                (uint32)0x000007FFUL
#define MCU_WUF_MSK                 (uint32)0xFFFFFFFFUL
#define MCU_EVFR_MSK                (uint32)0x00000001UL
#define MCU_FULL_MSK                (uint32)0xFFFFFFFFUL
#define MCU_CMOR_MSK                (uint16)0xC000U
#define MCU_CNTVAL_MSK              (uint32)0x0000FFFFUL
/*DPDSR0, DPDSRH, DPSELR0, DPSELRH */
#define MCU_DPD_MSK                 (uint32)0x00FFFFFFUL
#define MCU_TAUJTE_MSK              (uint8)0x0FUL

#define MCU_CVMDE_HIGH_V_MONIT_ENABLE           (uint32)0x00000002UL
#define MCU_CVMDE_LOW_V_MONIT_ENABLE            (uint32)0x00000001UL
#define MCU_LVICNT_RESET_VALUE                  (uint32)0x00000000UL
#define MCU_EVFR_DINEVF_COMPARISON_MISMATCH     (uint32)0x00000001UL
#define MCU_EVFR_RESET_VALUE                    (uint32)0x00000000UL
#define MCU_MIN_CLK_SET                         (uint8)0x00
#define MCU_MOSCC_BIT_TWO                       (uint32)0x00000004UL
#define MCU_MOSCE_START_MAIN_OSC_VALUE          (uint32)0x00000001UL
#define MCU_MOSCSTPM_MOSCSTPMSK_BIT             (uint32)0x00000001UL
#define MCU_MOSCSTPM_BIT_ONE                    (uint32)0x00000002UL
#define MCU_SOSCE_START_SUBOSC_BIT              (uint32)0x00000001UL
#define MCU_SOSCE_STOP_SUBOSC_BIT               (uint32)0x00000002UL
#define MCU_SOSCS_RESET_VALUE                   (uint32)0x00000000UL
#define MCU_ROSCSTPM_BIT_ZERO                   (uint32)0x00000001UL
#define MCU_ROSCSTPM_STOP_HS_INT_OSC            (uint32)0x00000002UL
#define MCU_CLMA_CTL0_ENABLE_VALUE              (uint8)0x01
#define MCU_CTL0_RESET_VALUE                    (uint8)0x00
#define MCU_RESF_VERIFICATION_VAL               (uint32)0x00000000UL
#define MCU_RESFR_VERIFICATION_VAL              (uint32)0x00000000UL
#define MCU_WUF0_RESET_VALUE                    (uint32)0x00000000UL
#define MCU_PLLE_STOP                           (uint32)0x00000002UL
#define MCU_PLLS_RESET                          (uint32)0x00000000UL
#define MCU_PLLE_START                          (uint32)0x00000001UL
#define MCU_PLL0E_STOP_PLL                      (uint32)0x00000002UL
#define MCU_PLL0S_RESET                         (uint32)0x00000000UL
#define MCU_PLL0E_START_PLL                     (uint32)0x00000001UL
#define MCU_MOSCE_STOP_OSCILATOR                (uint32)0x00000002UL
#define MCU_MOSCS_RESET_VALUE                   (uint32)0x00000000UL
#define MCU_STPMSK_NOT_STOPED                   (uint32)0x00000003UL
#define MCU_STPMSK_STOPED                       (uint32)0x00000002UL
#define MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID     (uint32)0x00000000UL
#define MCU_TAUJ_STOPED                         (uint8)0x00


#define MCU_DPDSR0_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_DPDSRM_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_DPDSRH_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_EVFR_INIT_REG_VALUE                 (uint32)0x00000000UL
#define MCU_SCTLR_INIT_REG_VALUE                (uint32)0x00000000UL
#define MCU_CNTVAL_INIT_REG_VALUE               (uint16)0x0000
#define MCU_DPSELR0_INIT_REG_VALUE              (uint32)0x00000000UL
#define MCU_DPSELRM_INIT_REG_VALUE              (uint32)0x00000000UL
#define MCU_DPSELRH_INIT_REG_VALUE              (uint32)0x00000000UL
#define MCU_CLMAnCMPH_INIT_REG_VALUE            (uint16)0x03FF
#define MCU_CLMAnCMPL_INIT_REG_VALUE            (uint16)0x0001
#define MCU_CLMAnCTL0_INIT_REG_VALUE            (uint8)0x00
#define MCU_TAUJnTPS_INIT_REG_VALUE             (uint16)0xFFFF
#define MCU_TAUJnBRS_INIT_REG_VALUE             (uint8)0x00
#define MCU_TAUJnCMOR_INIT_REG_VALUE            (uint16)0x0000
#define MCU_TAUJnCDR_INIT_REG_VALUE             (uint32)0x00000000UL
#define MCU_WUFMSK_INIT_REG_VALUE               (uint32)0xFFFFFFFFUL
#define MCU_FOUTDIV_INIT_REG_VALUE              (uint32)0x00000000UL
#define MCU_MOSCC_INIT_REG_VALUE                (uint32)0x00000004UL
#define MCU_MOSCST_INIT_REG_VALUE               (uint32)0x000044C0UL
#define MCU_MOSCSTPM_INIT_REG_VALUE             (uint32)0x00000002UL
#define MCU_SOSCST_INIT_REG_VALUE               (uint32)0x010C8E00UL
#define MCU_ROSCS_INIT_REG_VALUE                (uint32)0x00000007UL
#define MCU_ROSCSTPM_INIT_REG_VALUE             (uint32)0x00000002UL
#define MCU_PLLC_INIT_REG_VALUE                 (uint32)0x0001133BUL
#define MCU_PLL0C_INIT_REG_VALUE                (uint32)0x6000503BUL
#define MCU_PLLIS_INIT_REG_VALUE                (uint32)0x00000001UL
#define MCU_STPM_INIT_REG_VALUE                 (uint32)0x00000002UL
#define MCU_AWDTAD_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_ATAUJD_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_ARTCAD_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_AADCAD_INIT_REG_VALUE               (uint32)0x00000001UL
#if ((MCU_F1KM_S4_DEVICE == STD_ON) || (MCU_F1KH_D8_DEVICE == STD_ON))
#define MCU_CPUCLKD_INIT_REG_VALUE              (uint32)0x00000029UL
#else
#define MCU_CPUCLKD_INIT_REG_VALUE              (uint32)0x00000001UL
#endif
#define MCU_IADCAD_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_ILIND_INIT_REG_VALUE                (uint32)0x00000001UL
#define MCU_ICANOSCD_INIT_REG_VALUE             (uint32)0x00000000UL
#define MCU_ATAUJS_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_ARTCAS_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_AADCAS_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_AFOUTS_INIT_REG_VALUE               (uint32)0x00000000UL
#define MCU_CPUCLKS_INIT_REG_VALUE              (uint32)0x00000001UL
#define MCU_PPLLCLKS_INIT_REG_VALUE             (uint32)0x00000001UL
#define MCU_IPERI1S_INIT_REG_VALUE              (uint32)0x00000001UL
#define MCU_IPERI2S_INIT_REG_VALUE              (uint32)0x00000001UL
#define MCU_ILINS_INIT_REG_VALUE                (uint32)0x00000001UL
#define MCU_IADCAS_INIT_REG_VALUE               (uint32)0x00000001UL
#define MCU_ICANS_INIT_REG_VALUE                (uint32)0x00000003UL
#define MCU_ICSIS_INIT_REG_VALUE                (uint32)0x00000001UL
#define MCU_IIICS_INIT_REG_VALUE                (uint32)0x00000001UL

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
*                        DEM TYPE CASTING                                      *
*******************************************************************************/
/* Macros for DEM */
#define MCU_DEM_TYPE Dem_EventStatusType

/*******************************************************************************
**                      Clock Setting Data Structure                          **
*******************************************************************************/

/* MCUPBTYPES_H_001:  MCU_ESDD_UD_055, MCU_ESDD_UD_034                        */
/* MCUPBTYPES_H_023:  MCU_ESDD_UD_158                                         */
/* MCUPBTYPES_H_002:  EAAR_PN0075_FR_0008, EAAR_PN0075_FR_0009                */
/* MCUPBTYPES_H_003:  EAAR_PN0075_FR_0014, EAAR_PN0075_FR_0015                */
typedef struct STag_Mcu_ClockSetting
{
  /* Pointer to CKSC register selection structure */
  P2CONST(void, TYPEDEF, MCU_CONFIG_CONST) pCkscSel;
  uint8 ucCkscSelOffset;
  #if (MCU_PLL_ENABLE == STD_ON)
  /* Details of PLL */
  uint32 ulPLLControlValue;
  #endif
  #if (MCU_PLL0_ENABLE == STD_ON)
  /* Details of PLL0 */
  uint32 ulPLL0ControlValue;
  #endif
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  /* Main Oscillator Stabilization Time */
  uint32 ulMainOscStabTime;
  #endif
  #if (MCU_SUBOSC_ENABLE == STD_ON)
  /* SubOscillator Stabilization Time */
  uint32 ulSubOscStabTime;
  #endif
  /* FOUT Clock Divider register */
  uint16 usFoutDivReg;
  /* Details of selected clock sources */
  uint8 ucSelectedSrcClock;
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  /* Value for MOSCC register */
  uint8 ucMosccRegValue;
  #endif
  /* Selection of STPMK bit in all clock sources */
  uint8 ucSelectedSTPMK;
  /* Value of number of clock registers for ISO selected */
  uint8 ucNoOfIsoCkscReg;
  /* Value of number of clock registers for AWO selected */
  uint8 ucNoOfAwoCkscReg;
  /* Value of number of PLL clock registers for ISO selected */
  uint8 ucNoOfPllIsoCkscReg;
  /* Value of number of PLL  clock registers for AWO selected */
  uint8 ucNoOfPllAwoCkscReg;
  /* PLL CKSC Index offset */
  uint8 ucCkscPllIndexOffset;
  #if (MCU_PLL_ENABLE == STD_ON)
  /* Source clock selection of PLLCLKIN */
  uint8 ucPllSelectedSrcClock;
  #endif
  #if (MCU_PLL0_ENABLE == STD_ON)
  /* Source clock selection of PLL0CLKIN */
  uint8 ucPll0SelectedSrcClock;
  #endif
  /* Check for PLL configured */
  boolean blPllActCheck;
  #if (MCU_CLMA0_OPERATION == STD_ON)
  /* Element containing value of CLMA0CMPL register */
  uint16 usCLMA0CMPL;
  /* Element containing value of CLMA0CMPH register */
  uint16 usCLMA0CMPH;
  #endif  /* #if (MCU_CLMA0_OPERATION == STD_ON) */
  #if (MCU_CLMA1_OPERATION == STD_ON)
  /* Element containing value of CLMA1CMPL register */
  uint16 usCLMA1CMPL;
  /* Element containing value of CLMA1CMPH register */
  uint16 usCLMA1CMPH;
  #endif /* #if (MCU_CLMA1_OPERATION == STD_ON) */
  #if (MCU_CLMA2_OPERATION == STD_ON)
  /* Element containing value of CLMA2CMPL register */
  uint16 usCLMA2CMPL;
  /* Element containing value of CLMA2CMPH register */
  uint16 usCLMA2CMPH;
  #endif /* #if (MCU_CLMA2_OPERATION == STD_ON) */
  #if (MCU_CLMA3_OPERATION == STD_ON)
  /* Element containing value of CLMA3CMPL register */
  uint16 usCLMA3CMPL;
  /* Element containing value of CLMA3CMPH register */
  uint16 usCLMA3CMPH;
  #endif /* #if (MCU_CLMA3_OPERATION == STD_ON) */
} Mcu_ClockSetting;

/* MCUPBTYPES_H_004: MCU_ESDD_UD_056                                         */
/* MCUPBTYPES_H_005: EAAR_PN0075_FR_0009                                     */
typedef struct STag_Mcu_CkscSetting
{
  /* CKSC source clock selection register Number */
  uint8 ucCkscSourceSelRegNum;
  /* CKSC source clock divider register Number */
  uint8 ucCkscDividerSelRegNum;
  /* CKSC source STPMSK  register Number */
  uint16 ucCkscStpmskSelRegNum;
  /* CKSC source clock selection register Value */
  uint8 ucCkscSourceSelRegValue;
  /* CKSC Divider clock selection register Value */
  uint8 ucCkscDividerSelRegValue;
  /* CKSC Selection control for Source, Divider and  STPMSK selection */
  uint8 ucCkscControlval;

} Mcu_CkscSetting;

/*******************************************************************************
**Structure pointing to the Pn register address of each Port group configured **
*******************************************************************************/

/* MCUPBTYPES_H_006: MCU_ESDD_UD_049                                          */
typedef struct STag_Mcu_PortGroupAddress
{
  /* Address of PSR register */
  P2VAR(volatile uint32, TYPEDEF, MCU_CONFIG_DATA) pPortGroupAddress;
} Mcu_PortGroupAddress;

/*******************************************************************************
**                  Power Mode Setting Data Structure                         **
*******************************************************************************/

/* MCUPBTYPES_H_008: MCU_ESDD_UD_057                                         */
/* MCUPBTYPES_H_009: EAAR_PN0075_FR_0010, EAAR_PN0075_FR_0011                */
/* MCUPBTYPES_H_010: EAAR_PN0075_FR_0026                                     */
typedef struct STag_Mcu_ModeSetting
{
  /* Value of Power Down Wakeup source 1 */
  uint32 ulPowerDownWakeupType0;
  /* Value of Power Down Wakeup source for ISO */
  uint32 ulPowerDownWakeupTypeISO0;
  /* Value of Power Down Wakeup source for 2 */
  uint32 ulPowerDownWakeupType2;
  /* Value of Power Down Wakeup source for 1 */
#if (MCU_WUF1_ENABLED == STD_ON)
  uint32 ulPowerDownWakeupType1;
#endif
  /* Power down modes macro types*/
  uint8 ucModeType;
  /* enable/disable the actual transition to the low power modes */
  boolean blModeTransitionReq;
  /* enable/disable the Main oscillator operation in low power modes */
  boolean blMcuMainOscOperation;
} Mcu_ModeSetting;

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/*******************************************************************************
**                  Low power sequencer Data Structure                        **
*******************************************************************************/
/* MCUPBTYPES_H_011: MCU_ESDD_UD_106, MCU_ESDD_UD_117,MCU_ESDD_UD_123        */
/* MCUPBTYPES_H_022: MCU_ESDD_UD_121                                         */
/* MCUPBTYPES_H_012: EAAR_PN0075_FR_0013                                     */
typedef struct STag_Mcu_SequencerSetting
{
  #if (MCU_DIGITAL_INPUT_MODE == STD_ON)
  /* Pointer to Digital Input Selection structure */
  P2CONST(void, TYPEDEF, MCU_CONFIG_CONST) pDigitalInputModeSetting;
  #endif
  #if (MCU_TAUJ0_INIT == STD_ON)
  /* Pointer to TAUJ0 Channel Register */
  P2VAR(volatile TAUJChReg, TYPEDEF, MCU_CONFIG_DATA) pTAUJ0ChRegs;
  #endif
  /* Element for sequencer control register for setting both Digital and
   * Analog mode
   */
  uint32 ulSequencerCtlReg;
  #if (MCU_TAUJ0_INIT == STD_ON)
  /* Value for initializing the Timer TAUJ0 channel with CDRn value */
  uint32 ulTauj0TimerCntVal;
  #endif
  /* Element for setting external sensor stabilization time in digital input
   * and Analog input modes.
   */
  uint16 usExternalSensorStabTime;
  #if (MCU_TAUJ0_INIT == STD_ON)
  #if (MCU_TAUJ0_PRESCALAR == STD_ON)
  /* Prescaler selection for TAUJ0 unit */
  uint16 usPrescaler;
  /* Baud rate selection for TAUJ0 unit */
  uint8 ucBaudRate;
  #endif
  /* Channel mask details of the selected TAUJ0 channel */
  uint8 ucChannelMask;
  #endif
}Mcu_SequencerSetting;


/*******************************************************************************
**                  Low power sequencer Digital Input Pins Data Structure     **
*******************************************************************************/
/* MCUPBTYPES_H_013: MCU_ESDD_UD_107                                         */
/* MCUPBTYPES_H_014: EAAR_PN0075_FR_0013                                     */
typedef struct STag_Mcu_DigitalInputSetting
{
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELR0
   * register ie D0EN_0 to D0EN_23.
   */
  uint32 ulDigitalPinSelReg0;
  #if (MCU_DPIN_SEL_REG_M == STD_ON)
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELRM
   * register.
   *    D1EN_0 to D1EN_7
   *    D2EN_0 to D2EN_7
   *    D3EN_0 to D3EN_7
   *    D4EN_0 to D4EN_7
   */
  uint32 ulDigitalPinSelRegM;
  #endif
  #if (MCU_DPIN_SEL_REG_H == STD_ON)
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELH
   * register.
   *    D5EN_0 to D5EN_7
   *    D6EN_0 to D6EN_7
   *    D7EN_0 to D7EN_7
   */
  uint32 ulDigitalPinSelRegH;
  #endif
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   * D0EN_0 to D0EN_23 of DPDSR0 register
   */
  uint32 ulDigitalPinDataSetReg0;
  #if (MCU_DPIN_SEL_REG_M == STD_ON)
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   *  D1EN_0 to D1EN_7
   *  D2EN_0 to D2EN_7
   *  D3EN_0 to D3EN_7
   *  D4EN_0 to D4EN_7 of DPDSRM register
   */
  uint32 ulDigitalPinDataSetRegM;
  #endif

  #if (MCU_DPIN_SEL_REG_H == STD_ON)
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   *  D5EN_0 to D5EN_7
   *  D6EN_0 to D6EN_7
   *  D7EN_0 to D7EN_7 of DPDSRH register
   */
  uint32 ulDigitalPinDataSetRegH;
  #endif

}Mcu_DigitalInputSetting;

#endif
/* MCUPBTYPES_H_015: MCU_ESDD_UD_126                                         */
/* MCUPBTYPES_H_016: EAAR_PN0075_FR_0011, EAAR_PN0075_FR_0012                */
/* MCUPBTYPES_H_024: EAAR_PN0034_FR_0081                                     */
typedef struct STag_Mcu_TAUJUnitUserRegs
{
  uint8  volatile ucTAUJnTS;
/* QAC Warning: START Msg(2:3132)-4 */
  uint8  volatile aaReserved1[3];
/* END Msg(2:3132)-4 */
  uint8  volatile ucTAUJnTT;
} Mcu_TAUJUnitUserRegs;

/* MCUPBTYPES_H_017: MCU_ESDD_UD_127                                         */
/* MCUPBTYPES_H_018: EAAR_PN0075_FR_0011, EAAR_PN0075_FR_0012                */
typedef struct STag_Mcu_TAUJUnitOsRegs
{
  uint16 volatile usTAUJnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUJnBRS;
} Mcu_TAUJUnitOsRegs;

/* MCUPBTYPES_H_007: MCU_ESDD_UD_180                                         */
/* MCUPBTYPES_H_019: EAAR_PN0075_FR_0011, EAAR_PN0075_FR_0012                */
typedef struct STag_Mcu_TAUJUserRegs
{
  uint32 volatile ulTAUJnCDRm;
/* QAC Warning: START Msg(2:3132)-4 */
  uint32 volatile aaReserved1[3];
/* END Msg(2:3132)-4 */
} Mcu_TAUJChannelUserRegs;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
/* MCUPBTYPES_H_026: MCU_ESDD_UD_072                                         */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for the configured CKSC registers */
extern CONST(Mcu_CkscSetting, MCU_CONST)Mcu_GstCkscSetting[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Clock Setting Configuration */
extern CONST(Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Mode Setting Configuration */
extern CONST(Mcu_ModeSetting, MCU_CONST) Mcu_GstModeSetting[];
/* END Msg(4:3684)-1 */
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Low Power Sequencer Setting Configuration */
extern CONST(Mcu_SequencerSetting, MCU_CONST) Mcu_GstSequencerSetting[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Low Power Sequencer Setting of Digital Input
 * Configuration
 */
extern CONST(Mcu_DigitalInputSetting, MCU_CONST)
                                     Mcu_GstDigitalInputModeSetting[];
/* END Msg(4:3684)-1 */
#endif
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array of port registers */
#if MCU_PORTGROUP_STATUS_BACKUP == STD_ON
extern CONST(Mcu_PortGroupAddress, MCU_VAR)
                     Mcu_GaaPortGroup[MCU_PORT_INSTANCES + MCU_APORT_INSTANCES];
#endif
/* END Msg(4:3684)-1 */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include MCU_MEMMAP_FILE

#define MCU_START_SEC_CONFIG_DATA_8
#include MCU_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Clock Setting Configuration */
extern CONST(uint8, MCU_CONST) Mcu_GaaClockOffset[];
/* END Msg(4:3684)-1 */
#define MCU_STOP_SEC_CONFIG_DATA_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_START_SEC_BURAM_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM array for back up of Port group registers */
extern VAR(uint32, MCU_CONFIG_DATA) Mcu_GaaRamPortGroup[];
/* END Msg(4:3684)-1 */
/* QAC Warning: START Msg(2:0832)-3 */
#define MCU_STOP_SEC_BURAM_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-3 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
