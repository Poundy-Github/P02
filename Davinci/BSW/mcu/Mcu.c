/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of MCU Driver              */
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
* V1.0.0:  03-Sep-2015 : Initial Version                                       *
* V1.0.1:  08-Jan-2016 : The following changes are done                        *
*                        1. The structure (ClkMntrReg) member access for the   *
*                        global variables   Clma0Reg_BaseAddress,              *
*                        Clma1Reg_BaseAddress & Clma2Reg_BaseAddress           *
*                        is corrected as per IOCommon.h file.                  *
*                        (Ref: JIRA #ARDAAGA-42).                              *
*                        2. As part of fix for ARDAAGA-77,                     *
*                          a. Calling of Mcu_CopyToSection API inside Mcu_Init *
*                             API has been corrected.                          *
*                          b. 'Mcu_GetVersionInfo' API has been added.         *
*                        3. Dem error reporting has been added for core voltage*
*                           monitor.(Ref: ARDAAGA-43)                          *
*                        4. As a part of JIRA ARDAAGA-151, Offset handling of  *
*                           'Mcu_GpCkscSetting' and Luc_CkscSettingOffset'     *
*                           ' has been updated in Mcu_DistributePllClock' API. *
*                        5. As a part of JIRA ARDAAGA-154,                     *
*                           'REG_CKSC_ICANOSCD_CTL' case has been removed from *
*                           switch case in 'Mcu_ShiftClockDomain' API.         *
*                           REG_CKSC_PPLCLKS_CTL' and 'REG_CKSC_ICANOSCD_CTL'  *
*                           cases have been added and default case in switches *
*                           has been updated in 'Mcu_DistributePllClock'. Also *
*                           conditional check for updating of control registers*
*                           has been updated in the same API.                  *
*                        6. MISRA justifications has been added                *
*                           a. For Msg(4:2982) in APIs 'Mcu_MainOscEnable' and *
*                           'Mcu_MainOscDisable'                               *
*                           b. For Msg(4:0306) in API                          *
*                           'Mcu_WakeUpFactor_Preparation'.                    *
*                        7. As a part of JIRA ARDAAGA-153 Assignment of        *
*                           addresses to 'LpVal' is updated correctly          *
*                        8. As a part of JIRA ARDAAGA-152, Addressing of CLMA  *
*                           control register has been updated in '             *
*                           Mcu_MainOscEnable' API, Assignment of              *
*                           'Luc_CkscSettingOffset' has been                   *
*                           updated and 'MCU_CLMA2CTL0' has been changed to    *
*                           'Clma2Reg_BaseAddress->ucCTL0' for                 *
*                           'Mcu_ReadBackDiagTest' call is updated,            *
*                           assignment to 'LulTAUJ0UnitOsRegs' has been        *
*                           updated in 'Mcu_SequencerInit' API.                *
*                           with a ',' to separate the parameters being passed *
*                           in 'Mcu_DistributePllClock' API.                   *
*                        9. As a part of JIRA ARDAAGA-156, Assignment to       *
*                           'LpModeSetting' has been updated in                *
*                           'Mcu_WakeUpFactor_Preparation' API.                *
*                       10. As a part of JIRA ARDAAGA-155, PSR Register        *
*                           assignment to '*LpPortRamArea' in 'Mcu_SetMode' API*
*                           has been updated.                                  *
*                       11. As a part of JIRA ARDAAGA-42 ,The source clock     *
*                           selection for PPLCLK has been implemented in APIs  *
*                           'Mcu_CkscConfigure' and 'Mcu_ShiftClockDomain'     *
* V2.0.0:  10-Jun-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-400, RESFR is checked      *
*                           together with RESF for getting the reset reason    *
*                        2. As part of JIRA ARDAABD-400, The                   *
*                           Mcu_GetResetReason reworked  to return the higher  *
*                           importance reset in case of multiple reasons and   *
*                           the multiple reset reason procedure is enabled     *
*                        3. As part of JIRA ARDAABD-398, Macro                 *
*                           MCU_LVIFEIFMSK_MASK is replaced with               *
*                           MCU_LVILFEIFMSK_MASK | MCU_LVIHFEIFMSK_MASK for    *
*                           masking both LVILFEIF and LVIHFEIF bit             *
*                        4. As part of JIRA ARDAABD-443, After setting         *
*                           STBC0PSC = 0000 0002H, waiting for the             *
*                           transition to the DeepSTOP mode is made with       *
*                           unconditional loop                                 *
* V2.0.1:  14-Jun-2016 : Review points from 1.0.2  Implemented                 *
*                        1. Transition to stop mode unconditional loop removed *
*                        2. History updated                                    *
*                        3. Tabs from code files was removed                   *
*                        4. In function Mcu_GetResetReason use braces for every*
*                        if/else/else if construction                          *
* V2.1.0:  24-Jun-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-416, The STPM information  *
*                           is reloaded into the registers when the CLK domain *
*                           source is changed                                  *
*                        2. As part of JIRA ARDAABD-431, Mcu_GucSelectedMode   *
*                           variable is moved into the retention Ram section   *
* V2.1.1:  01-Jul-2016 : Implement Review points from                          *
*                           F1K_Ver42.00.00_17_TR_Report_MCU_ECODE_2016_07_01  *
* V2.2.0:  05-Jul-2016 : As part of JIRA ARDAABD-537, Enter & Exit mismatch    *
*                           for exclusive area critical section has been       *
*                           corrected in 'Mcu_Rram_Cyclic_Run' API             *
* V2.3.0:  08-Jul-2016 : As part of JIRA ARDAABD-543, Instead of reading the   *
*                           write only registers TAUJ0TS and TAUJ0TT for       *
*                           Mcu_ReadBackDiagTest, the TAUJ0TE is used for      *
*                           checking the correct setting of the TAUJ0 timer    *
* V2.4.0:  13-Jul-2016 : ARDAABD-543 and ARDAABD-537 review  points implemented*
* V2.5.0:  22-Jul-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-460 ,PLL is stopped when   *
*                           entering in Stop Mode and restarted if necessary   *
*                           when exit from stop mode                           *
*                        2. As part of JIRA ARDAABD-460, Created functions     *
*                           Mcu_StopPLL and Mcu_StartPLL for improving code    *
*                           readability and maintenance                        *
*                        3. As part of JIRA ARDAABD-419, When entering in Stop *
*                           mode all clocks domains are shifted to other clock *
*                           sources than PPLLCLK                               *
* V2.6.0:  05-Aug-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-415, Configured PLL source *
*                           clock loaded into CKSC_PLLIS_CTL                   *
*                        2. As part of JIRA ARDAABD-415, Changed identifier    *
*                           from 'REG_CKSC_PPLCLKS_CTL' to                     *
*                           'REG_CKSC_PPLLCLKS_CTL'                            *
* V2.7.0:  09-Sep-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-398, History entry for     *
*                           V1.0.2 rephrased to describe the specific change   *
*                        2. As part of JIRA ARDAABD-455, Duplicate code that   *
*                           updates 'LulResetValue' variable has been removed  *
*                           and else statement added for conditional check of  *
*                           LulRedundantResetValue in the 'Mcu_GetResetReason' *
*                           API                                                *
*                        3. Register PLLS added into Mcu_SetMode banner        *
* V2.8.0:  30-Sep-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-768: Corrected readback for*
*                           BRS, CDR, TPS, TE and CMOR registers in            *
*                           Mcu_Sequencer(Init/Stop).                          *
*                        2. As part of JIRA ARDAABD-782: NULL pointer check is *
*                           added in Mcu_ReloadClockDomainSTPM function.       *
*                        3. As part of JIRA ARDAABD-775: It is assured that    *
*                           EVFR register access is done in 32bit unit.        *
*                        4. As part of JIRA ARDAABD-711: Added timeout counter *
*                           for PLL lock                                       *
*                        5. As part of JIRA ARDAABD-781:                       *
*                           - MCU_CKSC_ARTCAS_CTL, MCU_CKSC_IADCAS_CTL         *
*                           and MCU_CKSC_IIICS_CTL comp switches were removed. *
*                           - CKSC_ICANOSCD_CTL clock domain is shifted to     *
*                           default clock source if MainOSC is disabled.       *
* V2.9.0:  14-Oct-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-473:                       *
*                           - AUTOSAR 3.2.2 is not supported anymore           *
*                           - MCU_AR_HIGHER_VERSION is changed to 4.2.2        *
*                           - MCU_AR_LOWER_VERSION is changed to 4.0.3         *
*                           - Removed code related to AUTOSAR 3.2.2            *
*                        2. As part of JIRA ARDAABD-770 - In Mcu_MainOscDisable*
*                           function, MOSCSTPMSK is set to 0 before write to   *
*                           MOSCDISTRG                                         *
*                        3. As part of JIRA ARDAABD-774 - Corrected critical   *
*                           section name for register access and global        *
*                           variable access.                                   *
*                           - Added missing critical section at write of       *
*                           PROTCMDx, CLMAx, RESFC, RESFCR, WufX, TAUJ, LPS,   *
*                           IMR, EVFR registers.                               *
* V2.10.0: 28-Oct-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-720 - Changed pointers to  *
*                           ports and Ram area to pointer to volatile          *
*                        2. As part of JIRA ARDAABD-769 The PLL Source is      *
*                           changed when the PLL is active if a different      *
*                           clock configuration is loaded                      *
*                        3. As part of JIRA ARDAABD-473 - History numbering    *
*                           changed according to projects requirements         *
*                        4. As part of JIRA ARDAABD-790 - Write sequence to    *
*                           protected registers is changed into a single       *
*                           macro                                              *
*                        5. As part of JIRA ARDAABD-764 - Check that disable   *
*                           of PLL and MainOsc was successfully performed      *
*                           added                                              *
*                           - Implemented shift of CSI source clock to default *
*                           value when MainOsc is stopped                      *
* V2.11.0: 01-Nov-2016 : As part of JIRA ARDAABD-569 - FuSa requirements for   *
*                           ASIL-B implemented                                 *
*                           - Write-Verify and Hardware Consistency Check      *
*                           were introduced  for  registers part  of the       *
*                           McuWriteVerify   and  McuRamMirror groups          *
*                           - New header file Mcu_RegWrite.h included in order *
*                           to use macros for Write verify and RAM Mirror for  *
*                           registers write                                    *
*                           - Mcu_CheckHWConsistency API created as part of    *
*                           the hardware consistency check(HWCC)               *
* V2.12.0: 11-Nov-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-710 - Stabilization waiting*
*                           and check for SubOsc performed, stabilization      *
*                           check for HSIntOsc performed, when setting clock   *
*                           domains source or divider check that the correct   *
*                           setting was performed                              *
*                        2. As part of JIRA ARDAABD-790 - Incorrect parameter  *
*                           passed to function Mcu_ProtectedWrite fixed        *
*                        3. As part of JIRA ARDAABD-569 - New register(SOSCST) *
*                           guarded using FuSa mechanisms and corrections      *
*                           performed to the first FuSa implementation         *
*                        4. As part of JIRA ARDAABD-947 - Acceptance points    *
*                           implementation:                                    *
*                           - File history rephrased and updated               *
*                           - Checking added in Mcu_ShiftClockDomain for       *
*                           CKSC_ICANS_CTL                                     *
*                           - Mcu_GblWakeUpPreparation set was moved out of    *
*                           critical section for register protection           *
*                        5. As part of JIRA ARDAABD-473 - Changed function     *
*                           implementation of Mcu_DistributePllClock for       *
*                           ASR4.2.2                                           *
*                        6. As part of JIRA ARDAABD-416 - The Stop Mask loaded *
*                           before any change in the clock domain setting are  *
*                           performed in functions Mcu_CkscConfigure and       *
*                           Mcu_ShiftClockDomain                               *
* V2.13.0: 18-Nov-2016 : As part of JIRA ARDAABD-569 - FuSa mechanism RAM      *
*                           mirror inserted for write-protected registers      *
*                           - Mcu_CheckHWConsistency API prototype updated     *
*                           by adding CheckType parameter                      *
* V2.14.0: 29-Nov-2016 : As part of JIRA ARDAABD-569 - Execute                 *
*                           MCU_WRITE_MIRROR_ONLY only if MCU_RAM_MIRROR is    *
*                           enabled                                            *
* V2.15.0: 05-Dec-2016 : As part of JIRA ARDAABD-473 - Changed ClockSetting    *
*                           index in Mcu_InitClock for 4.2.2 to start from 0   *
*                           - Changed McuMode index in Mcu_SetMode and         *
*                           Mcu_WakeUpFactor_Preparation for 4.2.2 to start    *
*                           from 0                                             *
* V2.16.0: 07-Dec-2016 : As part of JIRA ARDAABD-781 - Macros names were       *
*                           updated according to the format                    *
*                           <MSN>_<NameOfIdentifier> for REG_CKSC ,            *
*                           NOT_USED , VAL_UNAVAILABLE and                     *
*                           MCU_MASK_WAKE_UP_FACTOR_REGISTERS macros           *
* V2.16.1: 09-Dec-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-720 - LpPortRamArea        *
*                           definition from Mcu_Init updated to volatile uint32*
*                        2. As part of JIRA ARDAABD-775 - MCU_LONG_WORD_ONE    *
*                           used for comparison instead of MCU_ONE  for EVFR   *
*                           register                                           *
* V2.16.2: 16-Dec-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-950 - Set function         *
*                           Mcu_SequencerDiCmpValueSet reentrancy to           *
*                           Non-Reentrant in the function description          *
*                        2. As part of JIRA ARDAABD-710 - MCU_SAFETY_LOOP_COUNT*
*                           is used instead of MCU_CLK_SOURCE_SET_COUNT,       *
*                           MCU_CLK_DIV_SET_COUNT, MCU_PLL_LOCK_COUNT,         *
*                           MCU_PLL_STOP_COUNT and MCU_MOSC_STOP_COUNT         *
* V2.17.0: 19-Dec-2016 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-769 - PLL configuration    *
*                           (PLLC)reloaded if the PLL was On and the source was*
*                           not changed                                        *
*                        2. As part of JIRA ARDAABD-584                        *
*                           - *(LpVal + MCU_LONG_WORD_TWO) pointer             *
*                           was replaced with CKSC_XXXX_ACT register           *
*                        3. As part of JIRA ARDAABD-976 - LucIndex = 0 was     *
*                           replaced  with LucIndex = MCU_ZERO in Function     *
*                           Mcu_Init                                           *
*                        4. As part of JIRA ARDAABD-460 - Main oscillator is   *
*                           started when exiting STOP MODE only if is not      *
*                           already active                                     *
* V2.17.1: 28-Dec-2016 : As part of JIRA ARDAABD-831 - QAC warnings related to *
*                           implicit casts fixed                               *
* V2.17.2: 05-Jan-2017 : As part of JIRA ARDAABD-831 - Correct variable types  *
*                           used for reading the register ID value in          *
*                           Mcu_ShiftClockDomain                               *
* V2.18.0: 13-Jan-2017 : As part of JIRA ARDAABD-415 - ulSubOscStabTime from   *
*                           Mcu_GpClockSetting is used for SubOsc SW           *
*                           stabilization                                      *
* V2.19.0: 17-Jan-2017 : As part of JIRA ARDAABD-569 - Mask parameter added    *
*                           for the MCU_CHECK_WRITE_VERIFY_INIT and            *
*                           MCU_CHECK_WRITE_VERIFY_RUNTIME functions           *
* V2.20.0: 30-Jan-2017 : As part of JIRA ARDAABD-455 - Check for multiple      *
*                           reset reasons changed according to the description *
*                           from R403_MCU_F1K and R422_MCU_F1K files           *
* V2.21.0: 31-Jan-2017 : As part of JIRA ARDAABD-989 - Included macro          *
*                           MCU_MEMMAP_FILE instead Memmap.h file              *
* V2.22.0: 08-Feb-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-569 - MOSCSTPM written     *
*                           register value made consistent for all usage       *
*                        2. As part of JIRA ARDAABD-569 - Changed compiler     *
*                           MCU_RAM_MIRROR range of values to MCU_MIRROR_ENABLE*
*                           and MCU_MIRROR_DISABLE                             *
* V2.23.0: 14-Feb-2017 : As part of JIRA ARDAABD-594 - MCU_C_SW_MINOR_VERSION  *
*                           changed to "1" because of multiple code changes    *
* V2.24.0: 15-Feb-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-559 - Not initialized      *
*                           variable were moved in NOINIT Memory section       *
*                        2. As part of JIRA ARDAABD-831 - Definition of        *
*                           Mcu_CopyToSection removed from Mcu.c file          *
*                        3. As part of JIRA ARDAABD-831 - Definition and       *
*                           declaration of Mcu_ReadBackDiagTest was made       *
*                           consistent                                         *
* V2.24.1: 28-Feb-2017 : As part of JIRA ARDAABD-831 - MCU_DEV_ERROR_DETECT    *
*                           compiler switch moved inside the else branch of the*
*                           MCU_DBTOC_VALUE check                              *
* V2.25.0: 01-Mar-2017 : As part of JIRA ARDAABD-1167 - Mcu_GucClockSetting    *
*                           removed for ASR4.2.2 because ClockSettingId starts *
*                           from 0                                             *
* V2.26.0: 10-Mar-2017 : As part of JIRA ARDAABD-1210 - Traceability           *
*                           was added                                          *
* V2.27.0: 25-May-2017 : As part of JIRA ARDAABD-1035 - ClockSetting Id was    *
*                           limited upper to MCU_MAX_CLK_SET for ASR 4.0.3     *
* V2.28.0: 19-Jun-2017 : As part of JIRA ARDAABD-1949 - Processing for the     *
*                           PLL0 unit for F1KM S4 devices was added with the   *
*                           following functionalities: initialisation, Stop PLL*
*                           unit, Start PLL unit, check PLL lock               *
* V2.29.0: 22-Jun-2017 : As part of JIRA ARDAABD-1960 - Added support for      *
*                           wake up factor 1 processing                        *
* V2.30.0: 26-Jun-2017 : As part of JIRA ARDAABD-1949 - Call of Mcu_StartPLL   *
*                           executed under MCU_PLL_ENABLE check                *
* V2.31.0: 05-Jul-2017 : As part of JIRA ARDAABD-1959 - CLMA 3 registers load  *
*                           added in Mcu_DistributePllClock and registers check*
*                           added in Mcu_CheckHWConsistency                    *
* V2.32.0: 07-Jul-2017 : As part of JIRA ARDAABD-994 - High-Voltage Monitor    *
                            status and Low-Voltage Monitor status should be    *
                            checked with appropriate bit position of CVM       *
                            Detection Enable Register.                         *
* V2.33.0: 20-Jul-2017 : As part of JIRA ARDAABD-2083 - Extend reset reason    *
*                           processing for CLMA3 reset                         *
* V2.34.0: 29-Aug-2017 : As part of JIRA ARDAABD-2150 -Added QAC/MISRA         *
*                            warnings justification.Corrected QAC/MISRA Warning*
* V2.35.0: 29-Aug-2017 : As part of JIRA ARDAABD-2226 -Review points from      *
*                            REE_MCU_ECODE_022.xls implemented                 *
* V2.36.0: 19-Sep-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-2346 - Rename variables    *
*                           and use specific registers macros                  *
*                        2. As part of JIRA ARDAABD-2247 - Suboscillator is    *
*                           stopped when not used in configuration             *
* V2.37.0: 25-Sep-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-2346 - Fixed               *
*                           Mcu_WufReg10RamMirror attribute                    *
*                           Mcu_GddWufReg10RamMirror                           *
*                        2. As part of JIRA ARDAABD-2135 - In Mcu_CopyToSection*
*                           function compiler switch MCU_COPY_TO_SECTION_API   *
*                           added for copying actions                          *
* V2.38.0: 01-Oct-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-1359 - Remove Write verify *
*                           for FEINT register                                 *
*                        2. As part of JIRA ARDAABD-1612 - HW consistency check*
*                           for ROSCS added                                    *
*                        3. As part of JIRA ARDAABD-1874 - Ram Mirror variables*
*                           initialization performed                           *
*                        4. As part of JIRA ARDAABD-2588 - Added changes after *
*                           FuSa checklist                                     *
* V2.39.0: 09-Oct-2017 : As part of JIRA ARDAABD-2588 - Added a missing else,  *
*                            Put the constants to the left in comparisons      *
* V2.39.1: 10-Oct-2017 : As part of JIRA ARDAABD-2346 - LenReturnValue changed *
*                           with LddReturnValue                                *
* V2.39.2: 12-Oct-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-2594 - Changes after QAC   *
*                        2. As part of JIRA ARDAABD-2409 - PLL0 registers added*
*                           to Mcu_CheckHWConsistency                          *
*                        3. As part of JIRA ARDAABD-2531 - Change Macro name   *
*                           Mcu_ProtectedWrite to MCU_PROTECTED_WRITE          *
*                        4. As part of JIRA ARDAABD-2609 - Return Value checked*
*                           for next actions                                   *
* V2.40.0: 18-Oct-2017 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-2609 - Return Value checked*
*                           for next actions in Mcu_SetMode                    *
*                        2. As part of JIRA ARDAABD-2631 - In function         *
*                           Mcu_CheckHWConsistency change from else if         *
*                           processing to if processing                        *
*                        3. As part of JIRA ARDAABD-1740 - Size of             *
*                           Mcu_GaaPortGroup array changed to                  *
*                           MCU_PORT_INSTANCES + MCU_APORT_INSTANCES           *
* V2.40.1: 21-Nov-2017 : As part of JIRA ARDAABD-2770 - LddReturnValue         *
*                           initialized with E_OK.                             *
* V2.41.0: 22-Jan-2018 : The following changes were performed :                *
*                        1. As part of JIRA ARDAABD-2917 - Register used       *
*                           information updated                                *
*                        2. As part of JIRA ARDAABD-2563 - LddPllLockStatus    *
*                           updated in MCU_PLL_LOCKED wait loop.               *
* V2.41.1: 11-July-2018: Following changes are done :                          *
*                        1. As part of merging activity ticket ARDAABD-3490,   *
*                        a. Changed memory section name from MCU_<START/STOP>_ *
*                           SEC_VAR_NOINIT_<8/16/32/UNSPECIFIED> to MCU_       *
*                           <START/STOP>_SEC_VAR_NO_INIT_<8/16/32/UNSPECIFIED>,*
*                           MCU_START_SEC_BURAM_VAR_NO_INIT_UNSPECIFIED*       *
*                           to MCU_START_SEC_BURAM_VAR_NO_INIT_8               *
*                           Ref: ARDAABD-1617.                                 *
*                        b. Exported information blPllActCheck/                *
*                           Mcu_GblPllActCheck for deciding to  compare the    *
*                           CKSC_PPLLCLKS_ACT with zero or with                *
*                           CKSC_PPLLCLKS_CTL value in the functions           *
*                           Ref: ARDAABD-1293.                                 *
*                           Mcu_ShiftClockDomain and Mcu_CkscConfigure.        *
*                        2. As part of JIRA ARDAABD-3746, Critical sections    *
*                           have been removed from Mcu_Init(), Mcu_InitClock(),*
*                           Mcu_DistributePllClock(), Mcu_CkscConfigure()      *
*                           Mcu_GetPllStatus() and                             *
*                           Mcu_ShiftClockDomain_fromSubOsc() APIs             *
*                        3. As part of JIRA ARDAABD-3107, Mcu_SetMode() and    *
*                           Mcu_StandByPrepare() APIs updated to check for     *
*                           PLL ON or OFF against respective PLL module.       *
*                        4. As part of JIRA ARDAABD-1895, Mcu_SetMode(),       *
*                           Mcu_StandByPrepare() and Mcu_ShiftClockDomain()    *
*                           updated to select MainOSC and MainOSC/2 before     *
*                           shifting to STOP mode for C_ISO_CAN and            *
*                           C_ISO_CANOSC registers respectively.               *
*                        5. As part of JIRA ARDAABD-3180, Mcu_InitRamMirror,   *
*                           Mcu_CheckHWConsistency APIs updated to correct the *
*                           TAUJ channel register.                             *
*                        6. As part of JIRA ARDAABD-3622, updated the list of  *
*                           registers used in the function banner of APIs.     *
*                        7. As part of JIRA ARDAABD-3831, Mcu_SequencerStart   *
*                           and Mcu_SequencerStop is updated enable IMR        *
*                           register for INTCWEND after checking of            *
*                           McuINTCWENDEnable.                                 *
*                        8. As part of JIRA ARDAABD-3850, traceability         *
*                           inconsistencies are corrected and requirement      *
*                           mapping is done.                                   *
*                        9. As part of JIRA ARDAABD-3695, moved threshold value*
*                           of CLMA0/1/2/3 from Mcu_GpConfigPtr to             *
*                           Mcu_GstClockSetting.                               *
* V2.42.0: 09-Aug-2018 : Following changes are done as part of merging         *
*                        from for_Denso branch                                 *
*                        1. As part of ARDAABD-996,                            *
*                           remove ReadBack processing since it was replaced   *
*                           by WriteVerify                                     *
*                        2. As part of JIRA ARDAABD-3719,                      *
*                           Variable used to Wait-loop shall be declared       *
*                           volatile.                                          *
*                        3. As part of ARDAABD-3707,                           *
*                           Add RH850_DUMMY_READ_SYNCP(16, ICP0) to fix the    *
*                           fault synchronization at the timing when control   *
*                           shifts from MCAL to application                    *
*                        4. As part of ARDAABD-921,                            *
*                           add SNYCP before enabling or disabling the         *
*                           "ICCWEND" interrup and the sequencer (set of SCTLR)*
*                        5. As part of ARDAABD-3109,                           *
*                           Macro MCU_WAKEUP_FACTOR_CLR is replaced by         *
*                           MCU_WUF_CLR_VALUE/MCU_WUF1_CLR_VALUE               *
*                           MCU_WUFC20_CLR_VALUE/MCU_WUFC_ISO0_CLR_VALUE       *
*                        6. As part of ARDAABD-3111,                           *
*                           Change the order of evacuation saving in the       *
*                           retention RAM in the functions Mcu_SetMode         *
* V2.42.1: 27-Sep-2018 : Following changes are done :                          *
*                        1. As part of ticket ARDAABD-4007 - added mask process*
*                           when check the PLLC register in the function       *
*                           Mcu_InitClock.                                     *
* V2.42.2: 05-Oct-2018 : Following changes are done :                          *
*                        1. As part of ARDAABD-4033 - deleted souce code       *
*                           LpSeqSetting = Mcu_GpSeqSetting; is redundant      *
*                           in Mcu_CheckHWConsistency().                       *
*                        2. As part of ARDAABD-3707 - ICP0 usage error         *
*                           modified RH850_DUMMY_READ_SYNCP(ICP0)  to          *
*                           RH850_DUMMY_READ_SYNCP(&(ICP0))                    *
* V2.42.3:  18-Oct-2018 : As part of ARDAABD-3707                              *
*                        Remove the RH850_DUMMY_READ_SYNCP Marco               *
* V2.42.4:  14-Dec-2018 : As part of ARDAABD-4033                              *
*                         Added the #if (MCU_MAINOSC_ENABLE == STD_ON)         *
*                         Marco switch                                         *
* V2.42.5:  13-Aug-2019 : As part of ARDAABD-4016:                             *
*                         in Mcu_ShiftClockDomain()                            *
*                         and Mcu_ShiftClockDomain_fromSubOsc() API            *
*                         1. Declare a local variable of StdReturnType and     *
*                            initialize it to E_OK.                            *
*                         2. Use the new variable in the MCU_PROTECTED_WRITE   *
*                            operation.                                        *
*                         3. Check the new variable value and if its E_NOT_OK, *
*                            then report MCU_E_WRITE_TIMEOUT_FAILURE DEM and   *
*                            update LddReturnValue to E_NOT_OK                 *
*                         As part of ARDAABD-4022:                             *
*                         1.MCU will Check McuMainOscOperation parameter and   *
*                           McuMainOscSetting Configuration when wakeup from   *
*                           Stop mode,to control the enable of MainOSC         *
*                         As part of ARDAABD-4144:                             *
*                         1.add an internal private function(Mcu_IsoCkscCheck) *
*                           to Check Ios Clock Source which not configured     *
*                           by generator is not PPLLCLK.                       *
*                         2.Before calling the Mcu_CkscConfigure function to   *
*                           handle the CKSC registers configured for Iso0,     *
*                           call the newly appended function                   *
*                           (in Mcu_DistributePllClock and                     *
*                            Mcu_ReinitClockConfiguration)                     *
*                         As part of ARDAABD-4401:                             *
*                         1.in Mcu_WakeUpFactor_Preparation() API,to mask the  *
*                           generation of the flag before clear the wakeup flag*
*                         As part of ARDAABD-2562:                             *
*                         1.In Mcu_SetMode () API, Modify PLL and Pll0         *
*                           stabilization logic without unnecessary delay      *
*                           inside STOP mode                                   *
*                         As part of ARDAABD-4062:                             *
*                         1.Declare Mcu_GucClockSettingValue global variable   *
*                           for storing clock setting index in Retention RAM.  *
*                         2.Mcu_GucClockSettingValue global variable set index *
*                           in Mcu_InitClock() API.                            *
*                         3.Initialize the Mcu_GpClockSetting global variable  *
*                           in Mcu_Init() API.                                */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Implements:  MCU130, SWS_Mcu_00130 */
/* Included for Post-build Time Parameters */
#include "Mcu_PBTypes.h"
/* Included for RAM variable declarations */
#include "Mcu_Ram.h"
#include "Mcu_RegWrite.h"
#include "Iocommon_Defines.h"
/*Implements:  MCU_ESDD_UD_018 */
/*Implements:  MCU100, MCU015 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
/*Implements:  MCU109, MCU111 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/*Implements:  MCU_ESDD_UD_033 */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
/* Included for RAM configuration Parameters */
#include "Mcu_LTTypes.h"
/* Included for Register access */
#include "rh850_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_C_AR_RELEASE_MAJOR_VERSION     MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_MINOR_VERSION     MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_REVISION_VERSION  MCU_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define MCU_C_SW_MAJOR_VERSION     1
#define MCU_C_SW_MINOR_VERSION     2


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu.c : Mismatch in Release Major Version"
#endif /* (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION) */

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu.c : Mismatch in Release Minor Version"
#endif /* (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION) */

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu.c : Mismatch in Release Revision Version"
#endif /* (MCU_AR_RELEASE_REVISION_VERSION != MCU_C_AR_RELEASE_REVISION_VERSION)
          */


#if (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION)
#error "Mcu.c : Mismatch in Software Major Version"
#endif /* (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION) */

#if (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION)
#error "Mcu.c : Mismatch in Software Minor Version"
#endif /* (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION) */
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/* Implements: MCU_ESDD_UD_071                                               */
/* Implements: EAAR_PN0034_NR_0087                                           */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: MCU_ESDD_UD_034 */
#if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)

#if (MCU_MAINOSC_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:2022)-20 */
/* Global for storing selected clock sources of current clock configuration */
STATIC VAR(uint8, MCU_CONFIG_DATA) Mcu_GucClockSetting;
/* END Msg(2:2022)-20 */
#endif
#endif

#if (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF)
#if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
/*Implements: MCU183_Conf, ECUC_Mcu_00183 */
/* QAC Warning: START Msg(2:2022)-20 */
/* Global for storing selected clock sources of current clock configuration */
STATIC VAR(uint8, MCU_CONFIG_DATA) Mcu_GucSelectedSrcClock;
/* END Msg(2:2022)-20 */
#endif /* ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)) */
#endif /* (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF) */

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* QAC Warning: START Msg(2:2022)-20 */
/* Global for storing current CPU clock setting details */
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulCpuClockSetting;
/* END Msg(2:2022)-20 */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#if (MCU_RETENTIONRAM_REQ == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_BURAM_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* QAC Warning: START Msg(2:2022)-20 */
/* Global for storing selected power down mode of current mode configuration */
STATIC VAR(uint8, MCU_CONFIG_DATA) Mcu_GucSelectedMode;
/* END Msg(2:2022)-20 */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_BURAM_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_BURAM_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* QAC Warning: START Msg(2:2022)-20 */
/* Global variable for storing clock setting value of clock */
/* setting configuration */
STATIC VAR(uint8, MCU_CONFIG_DATA) Mcu_GucClockSettingValue;
/* END Msg(2:2022)-20 */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_BURAM_VAR_NO_INIT_8
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#if (MCU_RETENTIONRAM_REQ == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* QAC Warning: START Msg(2:2022)-20 */
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulWakeupfactor0;
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulWakeupfactor1;
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulWakeupfactor2;
#if (MCU_WUF1_ENABLED == STD_ON)
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulWakeupfactor3;
#endif
/* END Msg(2:2022)-20 */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* QAC Warning: START Msg(2:2022)-20 */
STATIC VAR(Mcu_RawResetType, MCU_CONFIG_DATA) Mcu_GulResetValue;
/* END Msg(2:2022)-20 */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_VAR_NO_INIT_32
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
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
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Array indexing shall be the only allowed form of pointer   */
/*                 arithmetic.                                                */
/* Verification  : Increment operator used to get the next address.           */
/*                 However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0489)-2 and                           */
/*                 END Msg(4:0489)-2 tags in the code.                        */
/******************************************************************************/
/* 3.  MISRA C RULE VIOLATION:                                                */
/* Message       : Msg(4:2983) This assignment is redundant. The value of this*/
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value changes according to the number of controllers   */
/*                 configured, value will be used in next iterations when more*/
/*                 than one controllers are configured                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-3 and                           */
/*                 END Msg(4:2983)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-4 and                           */
/*                 END Msg(4:0488)-4 tags in the code.                        */
/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) This assignment is redundant.                     */
/*                  The value of this object is never used before being       */
/*                  modified.                                                 */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Return value of a global variable is assigned with a       */
/*                 default value.                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-5 and                           */
/*                 END Msg(4:2982)-5 tags in the code.                        */
/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316) Cast from a pointer to void to a pointer to       */
/*                  object.                                                   */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Cast is performed between a pointer to void to pointer to  */
/*                 object type to prevent publishing of internal structure.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-6 and                           */
/*                 END Msg(4:0316)-6 tags in the code.                        */
/******************************************************************************/
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : Pointer to the configuration array is used and verified    */
/*                 when accessing the boolean parameter value.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-7 and                           */
/*                 END Msg(4:0491)-7 tags in the code.                        */
/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                  type.                                                     */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-8 and                           */
/*                 END Msg(4:0306)-8 tags in the code.                        */
/******************************************************************************/
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always true since  */
/*                 the variable updating in precompile ON condition.          */
/*                 However, when DET is OFF is configured,                    */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-9 and                           */
/*                 END Msg(4:2995)-9 tags in the code.                        */
/******************************************************************************/
/* 14.  QAC Warning:                                                          */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-14 and              */
/*                 END Msg(2:0832)-14 tags in the code.                       */
/******************************************************************************/
/* 15. QAC Warning:                                                           */
/* Message       : (2:3227) The parameter is never modified and so it could   */
/*                 be declared with the 'const' qualifier.                    */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Parameter is not declared with the 'const' qualifier in    */
/*                 order to respect AUTOSAR SWS and module requirements.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:3227)-15 and              */
/*                 END Msg(2:3227)-15 tags in the code.                       */
/******************************************************************************/
/* 16. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Since e-num type is used it is not possible to provide     */
/*                 out of range value but as per AUTOSAR all the input        */
/*                 parameters of an API have to be verified.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-16 and                          */
/*                 END Msg(4:2996)-16 tags in the code.                       */
/******************************************************************************/
/* 17. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2993) The value of this 'do - while' control expression */
/*                 is always 'false'. The loop will only be executed once.    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one controller is configured.                         */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2993)-17 and                          */
/*                 END Msg(4:2993)-17 tags in the code.                       */
/******************************************************************************/
/* 18. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2991) The value of this 'if' control expression         */
/*                 is always 'true'.                                          */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is always true   */
/*                 since variable updating in pre-compile ON condition.       */
/*                 However, when DET is OFF is configured,                    */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-18 and                          */
/*                 END Msg(4:2991)-18 tags in the code.                       */
/******************************************************************************/
/* 20. QAC Warning:                                                           */
/* Message       : (2:2022) A tentative definition is being used. Is it       */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Global Variable is not initialized because is kept in      */
/*                 No init area. Will be initialized at runtime with user     */
/*                 configuration values                                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:2022)-20 and              */
/*                 END Msg(2:2022)-20 tags in the code.                       */
/******************************************************************************/
/* 21.  MISRA C RULE VIOLATION:                                               */
/* Message       : Msg(4:2984) This operation is redundant. The value of the  */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value changes according to the number of controllers   */
/*                 configured.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-21 and                          */
/*                 END Msg(4:2984)-21 tags in the code.                       */
/******************************************************************************/
/* 22. QAC Warning:                                                           */
/* Message       : (2:3204) The variable  is only set once and                */
/*                 so it could be declared with the 'const' qualifier.        */
/* Rule          : NA                                                         */
/* Justification : This is done to make the Declaration and initialization    */
/*                 of variables on different lines in a function as per       */
/*                 coding guidelines.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3204)-22 and             */
/*                 END Msg(2:3204)-22 tags in the code.                       */
/******************************************************************************/
/* 23. QAC Warning:                                                           */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Pointer is generated by configurator tool, which ensures   */
/*                 that is not a NULL pointer                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2824)-23 and             */
/*                 END Msg(2:2824)-23 tags in the code.                       */
/******************************************************************************/
/* 25. QAC Warning:                                                           */
/* Message       : (2:2740) This loop controlling expression is a constant    */
/*                 expression and its value is 'true'.                        */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Unconditional loop is required for the system to enter in  */
/*                 DEEPSTOP mode                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2740)-25 and             */
/*                 END Msg(2:2740)-25 tags in the code.                       */
/******************************************************************************/
/* 26. QAC Warning:                                                           */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2814)-26 and             */
/*                 END Msg(2:2814)-26 tags in the code.                       */
/******************************************************************************/
/* 27. QAC Warning:                                                           */
/* Message       : (2:1476) Range of possible enum values suggests this test  */
/*                 is always false.                                           */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Check for illegal parameter value passed to user provided  */
/*                 function                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:1476)-27 and             */
/*                 END Msg(2:1476)-27 tags in the code.                       */
/******************************************************************************/
/* 28. QAC Warning:                                                           */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Rule          : NA                                                         */
/* Justification : All the possible values are covered specifically in each   */
/*                 and default case will not be reachable and this is reviewed*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2016)-28 and             */
/*                 END Msg(2:2016)-28 tags in the code.                       */
/******************************************************************************/
/* 29. QAC Warning:                                                           */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : NA                                                         */
/* Justification : General macro which is applied to large number of registers*/
/*                 types                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-29 and             */
/*                 END Msg(2:3892)-29 tags in the code.                       */
/******************************************************************************/
/* 30. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4464) A constant expression of 'essentially unsigned'   */
/*                 type (unsigned long) is being converted to narrower        */
/*                 unsigned type, 'unsigned char' on assignment.              */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : General macro which is applied to large number of registers*/
/*                 sizes                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(4:4464)-30 and             */
/*                 END Msg(4:4464)-30 tags in the code.                       */
/******************************************************************************/
/* 31. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0715) Nesting of control structures (statements) exceeds*/
/*                 15 - program does not conform strictly to ISO:C90.         */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : Nesting level can not be reduced because of implementation */
/*                 requirements, based on prioriies                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(4:0715)-31 and             */
/*                 END Msg(4:0715)-31 tags in the code.                       */
/******************************************************************************/
/* 32. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0310)-32 and                          */
/*                 END Msg(4:0310)-32 tags in the code.                       */
/******************************************************************************/
/* 33. QAC Warning:                                                           */
/* Message       : (3:3305) Pointer cast to stricter alignment.               */
/* Justification : In this instance, it is verified that the address stored in*/
/*                 the global pointer is not a constant value address.        */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(3:3305)-33 and                          */
/*                 END Msg(3:3305)-33 tags in the code.                       */
/******************************************************************************/
/* 34. QAC Warning:                                                           */
/* Message       : (2:2870) Infinite loop construct with constant control     */
/*                 expression.                                                */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Unconditional loop is required for the system to enter in  */
/*                 DEEPSTOP mode                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2870)-34 and             */
/*                 END Msg(2:2870)-34 tags in the code.                       */
/******************************************************************************/
/* 35. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3673)The object addressed by the pointer parameter      */
/*                 is not modified and so the pointer could be of type        */
/*                 'pointer to const'.                                        */
/* Rule          : MISRA-C:2004 Rule 16.7                                     */
/* Justification : pointer variable is used to modify the value at the address*/
/*                 so the pointer cannot be declared as 'pointer to const'    */
/*                 type.                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3673)-35 and END Msg(4:3673)-35 tags  */
/*                 in the code.                                               */
/******************************************************************************/
/* 36. QAC Warning:                                                           */
/* Message       : (2:2906) Definite: Positive integer value truncated by cast*/
/*                 to a smaller unsigned type.                                */
/* Rule          : NA                                                         */
/* Justification : General macro which is applied to large number of registers*/
/*                 types                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2906)-36 and             */
/*                 END Msg(2:2906)-36 tags in the code.                       */
/******************************************************************************/
/* 37. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:4391) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned char) is being cast to a wider              */
/*                 unsigned type, 'unsigned long'.                            */
/* Rule          : MISRA-C:2004 Rule 10.3                                     */
/* Justification : The resultant value obtained because of arithmetic         */
/*                 operation can be wider than operand type.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4491)-37 and                          */
/*                 END Msg(4:4491)-37 tags in the code.                       */
/******************************************************************************/
/* 38. QAC Warning:                                                           */
/* Message       : (2:3416) Logical operation performed on expression         */
/*                   with possible side effects.                              */
/* Rule          : Not Applicable                                             */
/* Justification : Wait-loop which may be deleted by optimization,            */
/*                 The Variable used toWait-loop shall be declared volatile.  */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3416)-38 and             */
/*                 END Msg(2:3416)-38 tags in the code.                       */
/******************************************************************************/
/* 39. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3415) Right hand operand of '&&' or '||' is             */
/*                      an expression with possible side effects.             */
/* Rule          : Not Applicable                                             */
/* Justification : Wait-loop which may be deleted by optimization,            */
/*                 The Variable used toWait-loop shall be declared volatile.  */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for MISRA Violation: START Msg(4:3415)-39 and         */
/*                 END Msg(4:3415)-39 tags in the code.                       */
/******************************************************************************/
/* 40. QAC Warning:                                                           */
/* Message       : Msg(2:3209) 'ASM_HALT()' returns a value which             */
/*                  is always ignored.                                        */
/* Rule          : Not Applicable                                             */
/* Justification : ASM_HALT is __asm macro, except.                           */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for QAC Warning: START Msg(2:3209)-40 and             */
/*                 END Msg(2:3209)-40 tags in the code.                       */
/******************************************************************************/
/* 41. MISRA C RULE VIOLATION:                                                */
/* Message       : Msg(4:3200) 'ASM_HALT' returns a value which is not        */
/*                   being used.                                              */
/* Rule          : Not Applicable                                             */
/* Justification : ASM_HALT is __asm macro, except.                           */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for MISRA Violation: START Msg(4:3200)-41 and         */
/*                 END Msg(4:3200)-41 tags in the code.                       */
/******************************************************************************/
/* 42. MISRA C RULE VIOLATION:                                                */
/* Message       : Msg(4:3335)No function declaration. Implicit declaration   */
/*                   inserted: 'extern int ASM_HALT();.                       */
/* Rule          : Not Applicable                                             */
/* Justification : ASM_HALT is __asm macro, except.                           */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for MISRA Violation: START Msg(4:3335)-42 and         */
/*                 END Msg(4:3335)-42 tags in the code.                       */
/******************************************************************************/
/* 43. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-43 and                          */
/*                 END Msg(4:0303)-43 tags in the code.                       */
/******************************************************************************/
/* 44. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the FUSA macros to    */
/*                 avoid static analysis warning.                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-44 and                          */
/*                 END Msg(4:3138)-44 tags in the code.                       */
/******************************************************************************/
/* 45.QAC Warning:                                                            */
/* Message       : (2:3141) Null statement does not occur on a line by itself.*/
/* Rule          : NA                                                         */
/* Justification : Function is exported from compiler.h                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3141)-45 and                          */
/*                 END Msg(2:3141)-45 tags in the code.                       */
/******************************************************************************/
/**            Internal Function Prototypes                                  **/
/******************************************************************************/

/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/*Implements: EAAR_PN0075_FR_0035                                             */
/*Implements: AR_PN0040_FR_0013                                               */
/*Implements: AR_PN0040_FR_0018, AR_PN0040_FR_0026, AR_PN0040_FR_0043         */
/*Implements: AR_PN0040_FR_0046, AR_PN0040_FR_0047, AR_PN0040_NR_0001         */
/*Implements: AR_PN0040_NR_0002, AR_PN0040_NR_0005, AR_PN0040_NR_0006         */
/*Implements: EAAR_PN0034_FR_0001                                             */
/*Implements: EAAR_PN0034_FR_0016, EAAR_PN0034_FR_0018                        */
/*Implements: EAAR_PN0034_FR_0019, EAAR_PN0034_FR_0021                        */
/*Implements: EAAR_PN0034_FR_0023, EAAR_PN0034_FR_0025                        */
/*Implements: EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0055   */
/*Implements: EAAR_PN0034_FR_0063, EAAR_PN0034_FR_0064                        */
/*Implements: EAAR_PN0034_FR_0065, EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002   */
/*Implements: EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0020   */
/*Implements: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0060                        */
/*Implements: EAAR_PN0034_NR_0026, EAAR_PN0034_NR_0069                        */
/*Implements: EAAR_PN0075_FR_0098, EAAR_PN0075_FR_0096                        */
/*                                                                            */
/*Implements: EAAR_PN0034_FR_0058, EAAR_PN0034_NR_0008                        */
/*Implements: EAAR_PN0034_NR_0010, EAAR_PN0034_NR_0012                        */
/*Implements: EAAR_PN0034_NR_0015                                             */
/*                                                                            */
/* Implements: MCU_ESDD_UD_002                                                */
/* Implements: EAAR_PN0075_FR_0017                                            */
/* Implements: MCU_ESDD_UD_172                                                */
/* Implements: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002                     */
/* Implements: EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004                     */
/* Implements: MCU_ESDD_UD_173                                                */
/* Implements: EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006                     */
/* Implements: EAAR_PN0034_FSR_0007                                           */
/*                                                                            */
/* Implements: MCU_ESDD_UD_051, MCU_ESDD_UD_052, MCU_ESDD_UD_053              */
/*                                                                            */
/* Implements: MCU_ESDD_UD_014                                                */
/* Implements: MCU166, MCU101, MCU051, MCU049, MCU226, ECUC_Mcu_00166         */
/* Implements: SWS_Mcu_00166, SWS_Mcu_00017                                   */
/* Implements: MCU_ESDD_UD_034, MCU_ESDD_UD_045,MCU_ESDD_UD_046               */
/* Implements: MCU_ESDD_UD_163,MCU_ESDD_UD_164                                */

#if (MCU_RETENTIONRAM_REQ == STD_ON)
#if (MCU_COPY_TO_SECTION_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

STATIC FUNC(uint32, MCU_PRIVATE_CODE)Mcu_Copy(uint32 LulAddSrc,
uint32 LulAddDest, uint32 LulSize);
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_COPY_TO_SECTION_API == STD_ON) */
#endif /* (MCU_RETENTIONRAM_REQ == STD_ON) */
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_InitRamMirror(void);

#endif

#if (MCU_MAINOSC_ENABLE == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_MainOscDefault(void);

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_MainOscDisable(void);

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_MainOscEnable(void);
#endif

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_ResumeCpuClock(void);

#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_CkscConfigure(uint8 ucCkscRegs, boolean blDomainType,
                                                      boolean blPllActiveCheck);

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_ReinitClockConfiguration(void);

STATIC FUNC(boolean, MCU_PRIVATE_CODE)
Mcu_IsoCkscCheck(uint8 ucCkscRegs, boolean blPllActiveCheck);

#endif /* (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF) */

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_ReloadClockDomainSTPM(uint16
                                         LusStopMaskId, uint8 LucStopMaskValue);
#if (MCU_SUBOSC_ENABLE == STD_ON)

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain_fromSubOsc
(void);

#endif


#if (MCU_PLL0_ENABLE == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain (boolean
LblMainOscOff , boolean LblPll0, boolean LblPll, boolean LblStopModeCheck);

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StandByPrepare (boolean
                             LblPLL0, boolean LblPLL, boolean LblStopModeCheck);
#else
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain (boolean
                                       LblMainOscOff, boolean LblStopModeCheck);

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StandByPrepare(boolean
                                                              LblStopModeCheck);
#endif /* #if (MCU_PLL0_ENABLE == STD_ON) */

#if (MCU_PLL_ENABLE == STD_ON)

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StartPLL(void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StopPLL(void);

#endif /* MCU_PLL_ENABLE == STD_ON */

#if (MCU_PLL0_ENABLE == STD_ON)

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StartPLL0(void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StopPLL0(void);

#endif /* MCU_PLL0_ENABLE == STD_ON */

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/*******************************************************************************
**             Function Definitions                                           **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Mcu_Init
**
** Service ID         : 0x00
**
** Description        : This service performs initialization of the MCU Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigPtr - Pointer to MCU Driver Configuration set
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr,
**                      Mcu_GpClockSetting, Mcu_GucSelectedSrcClock.
**
**
** Function Invoked   : Det_ReportError, Dem_ReportErrorStatus,
**                      Mcu_CopyToSection, Mcu_InitRamMirror,
**                      Mcu_GucClockSettingValue
**
** Registers Used     : FEINTFMSK, PROTCMD0, LVICNT, PROTS0, IOHOLD, WUF0,
**                      DPDSR0, DPDIMR0, DPDSRM, DPDIMR1, DPDIMR2, DPDIMR3,
**                      DPDIMR4, DPDSRH, DPDIMR5, DPDIMR6, DPDIMR7, EVFR, PSRn,
**                      CVMDE, CYCRBASE, SCTLR, CNTVAL, DPSELR0, DPSELRH,
**                      DPSELRM, CLMAnCMPH, CLMAnCMPL, CLMAnCTL0, WUFMSK0,
**                      WUFMSK_ISO0, WUFMSK20, WUFMSK1, SOSCST,MOSCC, FOUTDIV
**                      ROSCSTPM,TAUJ0TPS, TAUJ0BRS,MOSCST, MOSCSTPM
**                      TAUJnCDRm, TAUJnCMOR, FOUTDIV, PLLC, PLL0C
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_087,MCU_ESDD_UD_001                                */
/* Implements: MCU153, MCU013, MCU026, MCU116, MCU100                         */
/* Implements: MCU163, MCU166, MCU152, MCU126, MCU166_Conf, SWS_Mcu_00126     */
/* Implements: SWS_Mcu_00153, SWS_Mcu_00116, SWS_Mcu_00163                    */
/* Implements: SWS_Mcu_00166, SWS_Mcu_00051, SWS_Mcu_00249, ECUC_Mcu_00166    */
/* Implements: SWS_Mcu_00026                                                  */
/* Implements: EAAR_PN0075_FR_0039                                            */
/* Implements: EAAR_PN0075_FR_0029, EAAR_PN0075_FSR_0057                      */
/* Implements: EAAR_PN0075_FSR_0058                                           */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: MCU_ESDD_UD_143                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: MCU_ESDD_UD_140, MCU_ESDD_UD_159, MCU_ESDD_UD_099              */
/* Implements: MCU_ESDD_UD_100                                                */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: EAAR_PN0034_FR_0084                                            */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-15 */
{
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer pointing to the Port registers */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpPortRegisters;
  /* pointer to RAM area */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpPortRamArea;
  #endif /* (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
  volatile uint32 LulLVICnt;
  volatile uint32 LulDelayCount;
  Std_ReturnType LddReturnValue;
  uint8 LucCount;
  uint32 LulResetValue;
  uint32 LulRedundantResetValue;
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  uint8 LucIndex;
  #endif /* (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
  boolean LblDemReported;
  LucCount = MCU_LOOPCOUNT;
  LblDemReported = MCU_FALSE;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the config pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INIT_SID, MCU_E_PARAM_CONFIG);
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* QAC Warning: START Msg(2:2814)-26 */
    /* Check if the database is present */
    if (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(2:2814)-26 */
    {
      /* Assign the global pointer with the config pointer */
      Mcu_GpConfigPtr = ConfigPtr;

      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /*initialize the Ram Mirror variables*/
      Mcu_InitRamMirror();
      #endif
      #if (MCU_CVM_HIGH_VOLTAGE_DETECT == STD_ON)
      /* QAC Warning: START Msg(2:2814)-26 */
      if ( MCU_CVMDE_HIGH_V_MONIT_ENABLE !=
                              (LviReg_BaseAddress->ulCVMDE &
                                      MCU_CVMDE_HIGH_V_MONIT_ENABLE))
      /* END Msg(2:2814)-26 */
      {
        /*
         * Core voltage monitor bit is disabled and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_CVM_SETTING_FAILURE,
                                  DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
      else
      {

      }
      #endif
      #if (MCU_CVM_LOW_VOLTAGE_DETECT == STD_ON)
      if ( MCU_CVMDE_LOW_V_MONIT_ENABLE !=
                              (LviReg_BaseAddress->ulCVMDE &
                                      MCU_CVMDE_LOW_V_MONIT_ENABLE))
      {
        /*
         * Core voltage monitor bit is disabled and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_CVM_SETTING_FAILURE,
                                  DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
      else
      {

      }
      #endif

      /* Get the configured LVI for RESET/INTERRUPT */
      LulLVICnt = ConfigPtr->ulLVIindicationReg;
      /* if LVI detection level is to be configured */
      if (MCU_LVICNT_RESET_VALUE != (LulLVICnt & MCU_LVI_CNT_MASK))
      {
        /* Mask LVI reset by setting LVIRESMK bit */
        LulLVICnt = MCU_LVI_RESET_MASK;
        /* QAC Warning: START Msg(2:2814)-26 */
        MCU_PROTECTED_WRITE(&(LviReg_BaseAddress->ulLVICNT), LulLVICnt,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )
        /* END Msg(2:2814)-26 */
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(&Mcu_GddLviRegRamMirror.ulLVICNT,
                                LulLVICnt)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
           * writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                        DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        if (MCU_FALSE == LblDemReported)
        {
          /* QAC Warning: START Msg(2:2814)-26 */
          /* Mask the LVI Interrupt */
            FEIntMsk_BaseAddress->FMSK = (FEIntMsk_BaseAddress->FMSK |
                                  MCU_LVILFEIFMSK_MASK | MCU_LVIHFEIFMSK_MASK);
          /* END Msg(2:2814)-26 */
          /* Get the configured value for LVI detection level and mask
          * LVIRESMK bit
          */
          LucCount = MCU_LOOPCOUNT;
          LulLVICnt = (MCU_LVI_RESET_MASK | (ConfigPtr->ulLVIindicationReg &
                                                         MCU_LVI_CNT_MASK));
          MCU_PROTECTED_WRITE(&(LviReg_BaseAddress->ulLVICNT), LulLVICnt,
           &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
           &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
           LucCount, &LddReturnValue )
          #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
          /* write the value to the RAM mirror structure */
          MCU_WRITE_MIRROR_ONLY(&Mcu_GddLviRegRamMirror.ulLVICNT,
                                LulLVICnt)
          #endif
          if (E_NOT_OK == LddReturnValue)
          {
            /*
            * writing to write-protected register failed and
            * report production error
            */
            Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                   DEM_EVENT_STATUS_FAILED);
            LblDemReported = MCU_TRUE;
          }
          else
          {
            /* No action required */
          }
          if ( MCU_LVICNT_RESET_VALUE != ((LviReg_BaseAddress->ulLVICNT)
                                                            & MCU_LVI_CNT_MASK))
          {
            LulDelayCount = MCU_LONG_WORD_ZERO;
            do
            {
              /* LVI DELAY 80us */
              LulDelayCount++;
              /* QAC Warning: START Msg(2:3416)-38 */
              }while (((uint32)MCU_LVI_DELAY_COUNT) >= LulDelayCount);
              /* END Msg(2:3416)-38 */
            }
          else
          {
            /* No action required */
          }
          /* Check if LVI mode is to be configured for reset/interrupt */
          if (MCU_LVI_MASK == (ConfigPtr->ulLVIindicationReg & MCU_LVI_MASK))
          {
            /* unmask/enable the LVI Interrupt */
              FEIntMsk_BaseAddress->FMSK = (FEIntMsk_BaseAddress->FMSK &
                              (~(MCU_LVILFEIFMSK_MASK | MCU_LVIHFEIFMSK_MASK)));
          }
          else
          {
            /* Mask LVI reset bit only to perform Reset */
            LulLVICnt =
                  ((LviReg_BaseAddress->ulLVICNT) & MCU_LVI_RESET_MASK_ENABLE);
            LucCount = MCU_LOOPCOUNT;
            MCU_PROTECTED_WRITE(&(LviReg_BaseAddress->ulLVICNT), LulLVICnt,
              &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
              &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
              LucCount, &LddReturnValue )
            #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
            /* write the value to the RAM mirror structure */
            MCU_WRITE_MIRROR_ONLY(&Mcu_GddLviRegRamMirror.ulLVICNT,
                                LulLVICnt)
            #endif
            if (E_NOT_OK == LddReturnValue)
            {
              /*
               * writing to write-protected register failed and
               * report production error
               */
              Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                   DEM_EVENT_STATUS_FAILED);
              LblDemReported = MCU_TRUE;
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
      }
      else
      {
        /* No action required */
      }
      if (MCU_FALSE == LblDemReported)
      {
        /* QAC Warning: START Msg(2:2814)-26 */
        /* Check if the wake-up is from deep-stop mode */
         if (MCU_IOHOLD_MASK == ((uint32)(*Mcu_IoHoldRegister_BaseAddress) &
                                                              MCU_IOHOLD_MASK))
         /* END Msg(2:2814)-26 */
         {
          #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
          /* Restore PORT registers */
          /*
          * Count for the size of array in which the values at Port
          * registers are to be stored for back-up before entering into
          * deep-stop mode
          */
          LucIndex = MCU_ZERO;
          /* Get pointer to RAM area */
          /* QAC Warning: START Msg(2:2814)-26 */
          LpPortRamArea = Mcu_GpConfigPtr->pPortRamArea;
          /* END Msg(2:2814)-26 */
          /* Get pointer to port registers structure */

          do
          {
            LpPortRegisters =  Mcu_GaaPortGroup[LucIndex].pPortGroupAddress;
            /* QAC Warning: START Msg(2:2814)-26 */
            /*
              * Restore the value of PSR register of the configured Port group
              */
            MCU_WRITE_REG_ONLY(LpPortRegisters,
                              (*LpPortRamArea) | MCU_MSB_MASK)
            MCU_CHECK_WRITE_VERIFY_INIT(LpPortRegisters,
                                       (*LpPortRamArea) | MCU_MSB_MASK,
                                        MCU_FULL_MSK,
                                        MCU_INIT_SID)
            /* END Msg(2:2814)-26 */
            /* MISRA Violation: START Msg(4:0489)-2 */
            /* MISRA Violation: START Msg(4:2983)-3 */
            /* Increment the pointer to RAM area */
            LpPortRamArea++;
            /* END Msg(4:2983)-3 */
            /* END Msg(4:0489)-2 */
            /* Decrement the count of Port registers */
            /* MISRA Violation: START Msg(4:2984)-21 */
            LucIndex++;
            /* END Msg(4:2984)-21 */
            /* MISRA Violation: START Msg(4:2996)-16 */
            /* MISRA Violation: START Msg(4:2993)-17 */
          }while ((MCU_PORT_INSTANCES + MCU_APORT_INSTANCES)  > LucIndex);
          /* END Msg(4:2993)-17 */
          /* END Msg(4:2996)-16 */
          #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
        }
        else
        {
          /* No action required */
        }

        #if (MCU_RETENTIONRAM_REQ == STD_ON)
        LucCount = MCU_LOOPCOUNT;

        /* QAC Warning: START Msg(2:2814)-26 */
        MCU_PROTECTED_WRITE(&(Mcu_ResfRegister_BaseAddress->ulCYCRBASE),
          Mcu_GpConfigPtr->ulCyclicRunModeBaseAddress,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )
        /* END Msg(2:2814)-26 */

        if (E_NOT_OK == LddReturnValue)
        {
          /*
           * writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                               DEM_EVENT_STATUS_FAILED);
          /* MISRA Violation: START Msg(4:2983)-3 */
          LblDemReported = MCU_TRUE;
          /* END Msg(4:2983)-3 */
        }
        else
        {
          /* No action required */
        }
        #endif

        #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
        /* Check if wakeup is from sequencer due to change in DPIN's */
        /* QAC Warning: START Msg(2:2814)-26 */
        if ((MCU_WUTRG_SEQ ==(WufReg_BaseAddress->ulWUF0 & MCU_WUTRG_SEQ)) &&
                 (MCU_EVFR_DINEVF_COMPARISON_MISMATCH ==
                            (Mcu_LpsRegisters_BaseAddress->ulEVFR &
                             MCU_EVFR_DINEVF_COMPARISON_MISMATCH)))
        /* END Msg(2:2814)-26 */
        {
          /* Save new DPIN data input value */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                   Mcu_LpsRegisters_BaseAddress->ulDPDIMR0,
                                   &Mcu_GddLpsRegRamMirror.ulDPDSR0)
          MCU_CHECK_WRITE_VERIFY_INIT(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                    Mcu_LpsRegisters_BaseAddress->ulDPDIMR0,
                                    MCU_DPD_MSK,
                                    MCU_INIT_SID)

          /* Save new DPIN data input value */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR1 |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR2
                                                << MCU_LONG_WORD_EIGHT) |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR3
                                              << MCU_LONG_WORD_SIXTEEN) |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR4
                                              << MCU_LONG_WORD_TWENTY_FOUR)),
                                   &Mcu_GddLpsRegRamMirror.ulDPDSRM)
          MCU_CHECK_WRITE_VERIFY_INIT(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR1 |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR2
                                                << MCU_LONG_WORD_EIGHT) |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR3
                                              << MCU_LONG_WORD_SIXTEEN) |
                       ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR4
                                              << MCU_LONG_WORD_TWENTY_FOUR)),
                                    MCU_FULL_MSK,
                                    MCU_INIT_SID)

          /* Save new DPIN data input value */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR5 |
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR6
                                               << MCU_LONG_WORD_EIGHT) |
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR7
                                                << MCU_LONG_WORD_SIXTEEN)),
                                   &Mcu_GddLpsRegRamMirror.ulDPDSRH)
          MCU_CHECK_WRITE_VERIFY_INIT(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR5 |
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR6
                                               << MCU_LONG_WORD_EIGHT) |
                      ((uint32)Mcu_LpsRegisters_BaseAddress->ucDPDIMR7
                                                << MCU_LONG_WORD_SIXTEEN)),
                                    MCU_DPD_MSK,
                                    MCU_INIT_SID)

          /* clear the event flag Indicating Digital Input change during
          * sequencer operation
          */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                   MCU_EVFR_RESET_VALUE,
                                   &Mcu_GddLpsRegRamMirror.ulEVFR)
          MCU_CHECK_WRITE_VERIFY_INIT(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                    MCU_EVFR_RESET_VALUE,
                                    MCU_EVFR_MSK,
                                    MCU_INIT_SID)
        }
        else
        {
          /* No action required */
        }
        #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */
      }
      else
      {
        /* No action required */
      }
      #if (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF)
      #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
      /* Initialize to Zero */
      Mcu_GucSelectedSrcClock = MCU_ZERO;
      #endif /* #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)) */
      #endif /* (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF) */
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* Set the Global Status */
      Mcu_GblDriverStatus = MCU_INITIALIZED;
      Mcu_GblWakeUpPreparation = MCU_ZERO;
      #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

      /* QAC Warning: START Msg(2:2814)-26 */
      LulResetValue = (Mcu_ResfRegister_BaseAddress->ulRESF);
      LulRedundantResetValue = (Mcu_ResfRegister_BaseAddress->ulRESFR);
      /* END Msg(2:2814)-26 */
      /* Reset reason will contain both the information */
      LulResetValue = ((LulResetValue | LulRedundantResetValue) & MCU_ISO);
      if(MCU_ISO != LulResetValue)
      {
        #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
        Mcu_GucClockSettingValue = MCU_ZERO;
        #else
        Mcu_GucClockSettingValue = MCU_ONE;
        #endif
      }
      else
      {
        /* No action required */
      }

      /* QAC Warning: START Msg(2:2814)-26 */
      /* Store the pointer to the configured clock structure  */
      #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
      Mcu_GpClockSetting =
          (P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST))
           &Mcu_GstClockSetting[(Mcu_GpConfigPtr->ucClockSettingOffset) +
                               Mcu_GucClockSettingValue];
      #else
      Mcu_GpClockSetting =
           (P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST))
           &Mcu_GstClockSetting[(Mcu_GpConfigPtr->ucClockSettingOffset) +
                               (Mcu_GucClockSettingValue - MCU_ONE)];
      #endif
      /* END Msg(2:2814)-26 */
    }
    else
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* No database flashed Hence, report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID,
      MCU_E_INVALID_DATABASE);
      #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
  }
  #if (MCU_COPY_TO_SECTION_API == STD_ON)
  /*
     Calling of McuCopyToSection() API internally when
     MCU_COPY_TO_SECTION_API == STD_ON
  */
  (void)Mcu_CopyToSection();
  #endif /* (MCU_COPY_TO_SECTION_API == STD_ON)*/

}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/*******************************************************************************
** Function Name      : Mcu_InitRamSection
**
** Service ID         : 0x01
**
** Description        : This function initializes the RAM section as provided
**                      from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : RamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GstRamSetting
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
**
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_088, MCU_ESDD_UD_036                               */
/* Implements: MCU154, MCU011, MCU013, MCU154, MCU152                         */
/* Implements: MCU163, MCU100, MCU017, MCU166_Conf, ECUC_Mcu_00166            */
/* Implements: SWS_Mcu_00154, SWS_Mcu_00011, SWS_Mcu_000136                   */
/* Implements: SWS_Mcu_00163, SWS_Mcu_00017, SWS_Mcu_00152                    */
/* Implements: SWS_Mcu_00136                                                  */
/* Implements: MCU_ESDD_UD_017, MCU_ESDD_UD_001                               */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: MCU_ESDD_UD_035                                                */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
(Mcu_RamSectionType RamSection)
/* END Msg(2:3227)-15 */
{
  P2CONST(Mcu_RamSetting, AUTOMATIC, MCU_CONFIG_CONST) LpRamSetting;
  P2VAR(uint32, AUTOMATIC, MCU_CONFIG_DATA) LpRamStartAddressFourByte;
  P2VAR(uint16, AUTOMATIC, MCU_CONFIG_DATA) LpRamStartAddressTwoByte;
  P2VAR(uint8, AUTOMATIC, MCU_CONFIG_DATA) LpRamStartAddressOneByte;
  Std_ReturnType LddReturnValue;
  uint32 LulNoOfByte;
  uint8 LucNoOfByteWritten;
  /* Initialize return value with E_OK */
  LddReturnValue = E_OK;
  LpRamStartAddressFourByte = NULL_PTR;
  LpRamStartAddressTwoByte  = NULL_PTR;
  LpRamStartAddressOneByte  = NULL_PTR;
  LucNoOfByteWritten = MCU_ONE;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INITRAMSECTION_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Report to DET, if RamSetting Id is out of range */
  if (MCU_MAX_RAMSETTING <= RamSection)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INITRAMSECTION_SID, MCU_E_PARAM_RAMSECTION);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the pointer to the RAM structure */
    LpRamSetting = &Mcu_GstRamSetting[RamSection];
    /* Get the size of RAM section */
    LulNoOfByte = LpRamSetting->ulRamSectionSize;
    switch (LpRamSetting->enRamWriteSizeSel)
    {
    case MCU_8BIT_SIZE:
      /* Get the start address of the RAM section */
      /* MISRA Violation: START Msg(4:0316)-6 */
      LpRamStartAddressOneByte = (uint8 *) LpRamSetting->pRamStartAddress;
      /* END Msg(4:0316)-6 */
      LucNoOfByteWritten = MCU_ONE;
      if (MCU_LONG_WORD_ONE > LulNoOfByte)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      break;
    case MCU_16BIT_SIZE:
      /* Get the start address of the RAM section */
      /* MISRA Violation: START Msg(4:0316)-6 */
      LpRamStartAddressTwoByte = (uint16 *) LpRamSetting->pRamStartAddress;
      /* END Msg(4:0316)-6 */
      LucNoOfByteWritten = MCU_TWO;
      if ((MCU_LONG_WORD_TWO > LulNoOfByte ) || (MCU_LONG_WORD_ZERO !=
                                           (LulNoOfByte % LucNoOfByteWritten)))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      break;
    case MCU_32BIT_SIZE:
      /* Get the start address of the RAM section */
      /* MISRA Violation: START Msg(4:0316)-6 */
      LpRamStartAddressFourByte = (uint32 *) LpRamSetting->pRamStartAddress;
      /* END Msg(4:0316)-6 */
      LucNoOfByteWritten = MCU_FOUR;
      if ((MCU_LONG_WORD_FOUR > LulNoOfByte ) ||
           (MCU_LONG_WORD_ZERO != (LulNoOfByte % LucNoOfByteWritten)))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      break;
    default: LddReturnValue = E_NOT_OK;
      break;
    }
    /* Check if any development error occurred */
    if (E_OK == LddReturnValue)
    {
      while (MCU_LONG_WORD_ZERO != LulNoOfByte)
      {
        switch (LpRamSetting->enRamWriteSizeSel)
        {
        case MCU_8BIT_SIZE:
          /* Initialize RAM area with the value */
          if ( NULL_PTR  !=  LpRamStartAddressOneByte)
          {
            *LpRamStartAddressOneByte =(uint8) LpRamSetting->ulRamInitValue;
            /* MISRA Violation: START Msg(4:0489)-2 */
            /* Increment the pointer of RAM Section address */
            LpRamStartAddressOneByte++;
          }
          else
          {
            /* No action required */
          }
          /* END Msg(4:0489)-2 */
          break;
        case MCU_16BIT_SIZE:
          /* Initialize RAM area with the value */
          if (NULL_PTR != LpRamStartAddressTwoByte)
          {
            *LpRamStartAddressTwoByte = (uint16) LpRamSetting->ulRamInitValue;
            /* MISRA Violation: START Msg(4:0489)-2 */
            /* Increment the pointer of RAM Section address */
            LpRamStartAddressTwoByte++;
            /* END Msg(4:0489)-2 */
          }
          else
          {
            /* No action required */
          }
          break;
        case MCU_32BIT_SIZE:
          /* Initialize RAM area with the value */
          if (NULL_PTR != LpRamStartAddressFourByte)
          {
            *LpRamStartAddressFourByte = (uint32)LpRamSetting->ulRamInitValue;
            /* MISRA Violation: START Msg(4:0489)-2 */
            /* Increment the pointer of RAM Section address */
            LpRamStartAddressFourByte++;
            /* END Msg(4:0489)-2 */
          }
          else
          {
            /* No action required */
          }
          break;
        /* QAC Warning: START Msg(2:2016)-28 */
        default:
          /* Default case is added to avoid MISRA C warning */
          break;
        }
        /* END Msg(2:2016)-28 */
        /* Decrement the size */
        LulNoOfByte = (uint32)(LulNoOfByte - (uint32)LucNoOfByteWritten);
      }
    }
    else
    {
      /* No action required */
    }
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /*do nothing*/
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  return (LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_InitClock
**
** Service ID         : 0x02
**
** Description        : This service initializes the PLL and other MCU specific
**                      clock options
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr,
**                      Mcu_GpClockSetting, Mcu_GucSelectedSrcClock,
**                      Mcu_GpCkscSetting,Mcu_GucClockSettingValue
**
** Function Invoked   : Det_ReportError, Dem_ReportErrorStatus,
**                      Mcu_StandByPrepare, Mcu_MainOscDisable,
**                      Mcu_CkscConfigure, Mcu_StartPLL, 
**                      Mcu_ShiftClockDomain_fromSubOsc, Mcu_StartPLL0
**
** Registers Used     : FOUTDIV, MOSCE, MOSCS, MOSCST, MOSCC, MOSCSTPM,
**                      PROTCMD0, PROTCMD1, PROTS0, PROTS1, SOSCS, SOSCE,
**                      SOSCST, ROSCS, ROSCSTPM, PLLC/PLL1C, PLLS/PLL1S,
**                      PLL0C, PLL0S, CLMA0CTL0, CLMA0CMPH, CLMA0CMPL,
**                      CLMA0PCMD, CLMA0PS, CLMA1PCMD, CLMA1PS, CLMA1CMPH,
**                      CLMA1CMPL, CLMA1CTL0, CKSC_xxxS_CTL, CKSC_xxxS_ACT,
**                      CKSC_xxxD_CTL, CKSC_xxxD_ACT, PLLE/PLL1E, PLL0E,
**                      CKSC_xxxD_ACT, CKSC_xxxD_STPM, CKSC_xxxS_STPM
******************************************************************************/

#if (MCU_INIT_CLOCK == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_089, MCU_ESDD_UD_001                               */
/* Implements: MCU155, MCU140, MCU141, MCU056, MCU142, MCU248                 */
/* Implements: MCU205, MCU163,MCU053, MCU017, MCU166_Conf, MCU152             */
/* Implements: SWS_Mcu_00155, SWS_Mcu_00137, SWS_Mcu_00138                    */
/* Implements: SWS_Mcu_00139, SWS_Mcu_00163, SWS_Mcu_00210                    */
/* Implements: SWS_Mcu_00248, SWS_Mcu_00051, SWS_Mcu_00226                    */
/* Implements: SWS_Mcu_00017, SWS_Mcu_00152, ECUC_Mcu_00166                   */
/* Implements: MCU_ESDD_UD_017, MCU_ESDD_UD_006                               */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0075_FSR_0057                                           */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: MCU_ESDD_UD_012                                                */
/* Implements: EAAR_PN0075_FSR_0002                                           */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: EAAR_PN0034_FR_0084                                            */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00251, ECUC_Mcu_00124, SWS_Mcu_00258    */
/* Implements: MCU210, MCU188_Conf, MCU124_Conf, ECUC_Mcu_00188  */
/* Implements: MCU_ESDD_UD_024, MCU_ESDD_UD_025, MCU_ESDD_UD_034              */
/* Implements: MCU_ESDD_UD_067, MCU_ESDD_UD_068, MCU_ESDD_UD_051              */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock (Mcu_ClockType ClockSetting)
/* END Msg(2:3227)-15 */
{
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  uint32 LulMainClockStabCount;
  uint32 LulMOSCSTPM;
  #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
  #if (MCU_SUBOSC_ENABLE == STD_ON)
  uint32 LulSubOscClockStabCount;
  uint16 LusSafetyExitCounterSubOsc;
  #endif /* (MCU_SUBOSC_ENABLE == STD_ON) */
  #if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
  uint32 LulROSCSTPM;
  #endif

  Std_ReturnType LddReturnValue;
  uint8 LucNoOfCkscReg;
  boolean blPllActiveCheck;
  #if ((MCU_MAINOSC_ENABLE == STD_ON) ||  (MCU_PLL_ENABLE == STD_ON) ||      \
                  (MCU_SUBOSC_ENABLE == STD_ON) || (MCU_PLL0_ENABLE == STD_ON))
  uint8 LucSelectedSrcClk;
  #endif
  #if ((MCU_MAINOSC_ENABLE == STD_ON)  ||  (MCU_PLL_ENABLE == STD_ON)  ||      \
       (MCU_SUBOSC_ENABLE == STD_ON)   || (MCU_PLL0_ENABLE == STD_ON)) ||      \
       (MCU_CLMA0_OPERATION == STD_ON) || (MCU_CLMA1_OPERATION == STD_ON)
  uint8 LucCount;
  #endif
  #if (MCU_PLL_ENABLE == STD_ON)
  uint32 LulPllSrcClk;
  uint32 LulPllPLLC;
  #endif
  #if (MCU_PLL0_ENABLE == STD_ON)
  uint32 LulPll0SrcClk;
  uint32 LulPll0PLLC;
  #endif
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INITCLOCK_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* Report to DET, if clock setting Id is invalid */
  else
  {
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    if (MCU_MAX_CLK_SET <= ClockSetting)
    #else
    if ((MCU_MIN_CLK_SET == ClockSetting) || (MCU_MAX_CLK_SET < ClockSetting))
    #endif
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_INITCLOCK_SID, MCU_E_PARAM_CLOCK);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Store the pointer to the configured clock structure  */
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    Mcu_GpClockSetting =
        (P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST))
         &Mcu_GstClockSetting[(Mcu_GpConfigPtr->ucClockSettingOffset) +
                                                                 ClockSetting];
    #else
    Mcu_GpClockSetting =
         (P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST))
         &Mcu_GstClockSetting[(Mcu_GpConfigPtr->ucClockSettingOffset) +
                                               (ClockSetting - MCU_ONE)];
    #endif
    #if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
    #if (MCU_MAINOSC_ENABLE == STD_ON)
    Mcu_GucClockSetting = ClockSetting;
    #endif
    #endif

    /* Storing clock setting value of clock setting configuration */
    Mcu_GucClockSettingValue = ClockSetting;

    /* Get the value of the selected source clock */
    #if ((MCU_MAINOSC_ENABLE == STD_ON) ||  (MCU_PLL_ENABLE == STD_ON) ||      \
                  (MCU_SUBOSC_ENABLE == STD_ON) || (MCU_PLL0_ENABLE == STD_ON))
    LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;
    #endif
    #if (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF)
    #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
    /* Store the value */
    Mcu_GucSelectedSrcClock = LucSelectedSrcClk;
    #endif /* ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)) */
    #endif /* (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF) */

    /* Disable the FOUT divider register */
    MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                                   MCU_FOUT_DISABLE_MASK,
                                   &Mcu_GddClkCntlRegRamMirror.ulFOUTDIV)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                                    MCU_FOUT_DISABLE_MASK,
                                    MCU_FOUTDIV_MSK,
                                    MCU_INITCLOCK_SID)

    #if (MCU_MAINOSC_ENABLE == STD_ON)
    /* Check whether the selected clock source is main oscillator */
    if (MCU_MAIN_OSC_SELECTED ==
                             (uint8)(LucSelectedSrcClk & MCU_MAIN_OSC_SELECTED))
    {
      /* Check whether MOSC is OFF */
      if (MCU_MAIN_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
                                                           & MCU_MAIN_OSC_ON))
      {
        /* Load the value of MOSCC register */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCC,
                                ((uint32)(Mcu_GpClockSetting->ucMosccRegValue)
                                | MCU_MOSCC_BIT_TWO),
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCC)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCC,
                                ((uint32)(Mcu_GpClockSetting->ucMosccRegValue)
                                | MCU_MOSCC_BIT_TWO),
                                MCU_MOSCC_MSK,
                                MCU_INITCLOCK_SID)

        /* Set Main Oscillator stabilization time */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCST,
                                Mcu_GpClockSetting->ulMainOscStabTime,
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCST)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCST,
                                   Mcu_GpClockSetting->ulMainOscStabTime,
                                   MCU_MOSCST_MSK,
                                   MCU_INITCLOCK_SID)

        /* Enable the Main Oscillator */

        LucCount = MCU_LOOPCOUNT;
        MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulMOSCE),
          MCU_MOSCE_START_MAIN_OSC_VALUE,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )

        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                   DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
        /* Load the stabilization count value */
        LulMainClockStabCount = Mcu_GpConfigPtr->ulMainClockStabCount;

        while ((MCU_MOSCS_RESET_VALUE == ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
                & MCU_MAIN_OSC_ON)) &&
                                   (MCU_LONG_WORD_ZERO < LulMainClockStabCount))
        {
          LulMainClockStabCount--;
        }
        if (MCU_MAIN_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
                                                         & MCU_MAIN_OSC_ON))
        {
          /* MainOsc failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
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
      /* check for Main Oscillator Stop mask */
      if (MCU_MAIN_OSC_MASKED ==
         (uint8)(Mcu_GpClockSetting->ucSelectedSTPMK & MCU_MAIN_OSC_MASKED))
      {
        LulMOSCSTPM = Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM;
        /* Main Osc continues operation in stand-by mode  */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                 (LulMOSCSTPM | MCU_MOSCSTPM_MOSCSTPMSK_BIT),
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                    (LulMOSCSTPM | MCU_MOSCSTPM_MOSCSTPMSK_BIT),
                                    MCU_STPM_MSK,
                                   MCU_INITCLOCK_SID)
      }
      else
      {
        /* Main Osc stops operation in stand-by mode  */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                MCU_MOSCSTPM_BIT_ONE,
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                    MCU_MOSCSTPM_BIT_ONE,
                                    MCU_STPM_MSK,
                                   MCU_INITCLOCK_SID)

      }
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
    /*
    * Check whether the selected clock source is Sub oscillator and
    * the DEM error has not occurred
    */
    #if (MCU_SUBOSC_ENABLE == STD_ON)
    if ((E_OK == LddReturnValue ) &&
        (MCU_SUB_OSC_SELECTED ==((uint8)(LucSelectedSrcClk &
                                                        MCU_SUB_OSC_SELECTED))))
    {

      /* Check whether SOSC is OFF */
      if (MCU_SUB_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)
                                                        & MCU_SUB_OSC_ON))
      {

        LucCount = MCU_LOOPCOUNT;
        /* Enable the Sub Oscillator */

         /* Set Sub Oscillator stabilization time */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulSOSCST,
                                Mcu_GpClockSetting->ulSubOscStabTime,
                                &Mcu_GddClkCntlRegRamMirror.ulSOSCST)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulSOSCST,
                                   Mcu_GpClockSetting->ulSubOscStabTime,
                                   MCU_SOSCST_MSK,
                                   MCU_INITCLOCK_SID)

        /* Enable the Sub Oscillator */
        MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulSOSCE),
                MCU_SOSCE_START_SUBOSC_BIT,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                   DEM_EVENT_STATUS_FAILED);

        }
        else
        {
          /* No action required */
        }
        /* Load the stabilization count value */
        LulSubOscClockStabCount = Mcu_GpClockSetting->ulSubOscStabTime;
        /*Add 10% tolerance for the SW stabilization counter*/
        /*Value is limited from */
        LulSubOscClockStabCount = LulSubOscClockStabCount +
          (((uint32)LulSubOscClockStabCount/MCU_LONG_WORD_TEN) +
          MCU_LONG_WORD_ONE);

        while ((MCU_SOSCS_RESET_VALUE == ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)
               & MCU_SUB_OSC_ON)) &&
                                 (MCU_LONG_WORD_ZERO < LulSubOscClockStabCount))
        {
          LulSubOscClockStabCount--;
        }
        if (MCU_SUB_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)
                                                         & MCU_SUB_OSC_ON))
        {
          /* Sub Osc Stabilisation failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
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
    }
    else
    {
      /* Check if SubOscillator is active */
      if (MCU_SUB_OSC_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)
                                                             & MCU_SUB_OSC_ON))
      {
        LddReturnValue = Mcu_ShiftClockDomain_fromSubOsc();
        if(E_OK == LddReturnValue)
        {
          LucCount = MCU_LOOPCOUNT;
          /* Disable the Sub Oscillator */

          MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulSOSCE),
            MCU_SOSCE_STOP_SUBOSC_BIT,
            &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
            &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
            LucCount, &LddReturnValue )

          if (E_NOT_OK == LddReturnValue)
          {
            /*
            * writing to write-protected register failed and
            * report production error
            */
            Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                     DEM_EVENT_STATUS_FAILED);

          }
          else
          {
            /* No action required */
          }
          /* Wait for SubOscillator to Stop */
          LusSafetyExitCounterSubOsc = MCU_SAFETY_LOOP_COUNT;
          while ((MCU_SOSCS_RESET_VALUE !=
                  ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)& MCU_SUB_OSC_ON)) &&
                  ((uint16)MCU_ZERO < LusSafetyExitCounterSubOsc))
          {
            LusSafetyExitCounterSubOsc--;
          }
          if (MCU_SOSCS_RESET_VALUE != ((Mcu_ClkCtrlReg_BaseAddress->ulSOSCS)
                & MCU_SUB_OSC_ON))
          {
            Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
              DEM_EVENT_STATUS_FAILED);
          }
          else
          {
            /*Do Nothing*/
          }
        }
        else
        {
          /*Do Nothing*/
        }
      }
      else
      {
        /*Do Nothing*/
      }
    }
    #endif /* (MCU_SUBOSC_ENABLE == STD_ON) */
    /*
    * Check whether the selected clock source is High speed Internal Ring
    * Oscillator and the DEM error has not occurred
    */

    #if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
    if ( E_OK ==  LddReturnValue )
    {
      /* Check whether High speed Internal Ring Oscillator is OFF */
      /* check for High speed Internal Ring Oscillator's Stop mask */
      /* write the value to the RAM mirror structure */
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulROSCS,
                                            Mcu_ClkCtrlReg_BaseAddress->ulROSCS)
     #endif
      /*Check if HSIntOsc is stabilized*/
      if (MCU_HIGHSPEED_RINGOSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulROSCS)
              & MCU_HIGHSPEED_RINGOSC_ON))
      {

          /* HSInt Osc Stabilization failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
          LddReturnValue = E_NOT_OK;
      }
      else
      {
          /*Do nothing*/
      }

      if (MCU_RING_OSC_MASKED ==
         (uint8)(Mcu_GpClockSetting->ucSelectedSTPMK & MCU_RING_OSC_MASKED))
      {
        LulROSCSTPM = Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM;
        /* Highspeed IntOsc continues operation in stand-by mode  */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                ((LulROSCSTPM) | MCU_ROSCSTPM_BIT_ZERO),
                                &Mcu_GddClkCntlRegRamMirror.ulROSCSTPM)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                   ((LulROSCSTPM) | MCU_ROSCSTPM_BIT_ZERO),
                                   MCU_STPM_MSK,
                                   MCU_INITCLOCK_SID)
      }
      else
      {
        /* Highspeed IntOsc stops operation in stand-by mode  */
        MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                MCU_ROSCSTPM_STOP_HS_INT_OSC,
                                &Mcu_GddClkCntlRegRamMirror.ulROSCSTPM)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                   MCU_ROSCSTPM_STOP_HS_INT_OSC,
                                   MCU_STPM_MSK,
                                   MCU_INITCLOCK_SID)
      }
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON) */
    /*
    * Check whether the selected clock source is PLL and
    * the DEM error has not occurred
    */

    #if (MCU_PLL_ENABLE == STD_ON)
    if ((E_OK == LddReturnValue ) &&
       (MCU_PLL_CLOCK_SELECTED ==
       ((uint8)(LucSelectedSrcClk & MCU_PLL_CLOCK_SELECTED))))
    {
      /* Check whether PLL is OFF */
      if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON))
      {
        /* PLL input clock Initialization Routine */
        LucCount = MCU_LOOPCOUNT;
        /* Load Pll source Clock */
        LulPllSrcClk = (uint32) Mcu_GpClockSetting->ucPllSelectedSrcClock;
        MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLLIS_CTL),
          LulPllSrcClk,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
          LucCount, &LddReturnValue )
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulCKSC_PLLIS_CTL,
                                LulPllSrcClk)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);

        }
        else
        {
          LddReturnValue = Mcu_StartPLL();
        }

      }
      else
      {
        /*If the new PLL settings are different from the current ones*/
        LulPllSrcClk = (uint32) Mcu_GpClockSetting->ucPllSelectedSrcClock;
        LulPllPLLC = (uint32) Mcu_GpClockSetting->ulPLLControlValue;
        if ((LulPllSrcClk != (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLLIS_ACT))||
              (LulPllPLLC != (Mcu_ClkCtrlReg_BaseAddress->ulPLLC
                                                 & MCU_PLLC_READ_MASK)))
        {
          #if (MCU_PLL0_ENABLE == STD_ON)
          LddReturnValue = Mcu_StandByPrepare(MCU_FALSE, MCU_TRUE, MCU_FALSE);
          #else
          LddReturnValue = Mcu_StandByPrepare(MCU_FALSE);
          #endif
          if (E_OK == LddReturnValue )
          {
            /* PLL input clock Initialization Routine */
            LucCount = MCU_LOOPCOUNT;
            /* Load Pll source Clock */
            MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLLIS_CTL),
              LulPllSrcClk,
              &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
              &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
              LucCount, &LddReturnValue )
            #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
            /* write the value to the RAM mirror structure */
            MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulCKSC_PLLIS_CTL,
                                LulPllSrcClk)
            #endif
            if (E_NOT_OK == LddReturnValue)
            {
              /*
               * writing to write-protected register failed and
               * report production error
               */
               Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
            }
            else
            {

            }
            /* Check if No Dem error occurred */
            if (E_OK == LddReturnValue )
            {
              /* Enable the PLL again */
              LddReturnValue = Mcu_StartPLL();
            }
            else
            {
              /* Do Nothing */
            }
          }
          else
          {
            /* Do Nothing */
          }
        }
        else
        {
          /*
           * Same PLL source as before*/
        }
      }
    }
    else
    {
      if(E_OK == LddReturnValue)
      {
        if (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON))
        {
          #if (MCU_PLL0_ENABLE == STD_ON)
          LddReturnValue = Mcu_StandByPrepare(MCU_FALSE, MCU_TRUE, MCU_FALSE);
          #else
          LddReturnValue = Mcu_StandByPrepare(MCU_FALSE);
          #endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
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
    #endif /* (MCU_PLL_ENABLE == STD_ON) */
    #if (MCU_PLL0_ENABLE == STD_ON)
    if ((E_OK == LddReturnValue ) &&
       (MCU_PLL0_CLOCK_SELECTED ==
       ((uint8)(LucSelectedSrcClk & MCU_PLL0_CLOCK_SELECTED))))
    {
      /* Check whether PLL is OFF */
      if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_ON))
      {
        /* PLL0 input clock Initialization Routine */
        LucCount = MCU_LOOPCOUNT;
        /* Load Pll0 source Clock */
        LulPll0SrcClk = (uint32) Mcu_GpClockSetting->ucPll0SelectedSrcClock;
        MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLL0IS_CTL),
          LulPll0SrcClk,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
          LucCount, &LddReturnValue )
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulCKSC_PLL0IS_CTL,
                                                                  LulPll0SrcClk)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);

        }
        else
        {
          LddReturnValue = Mcu_StartPLL0();
        }

      }
      else
      {
        /*If the new PLL settings are different from the current ones*/
        LulPll0SrcClk = (uint32) Mcu_GpClockSetting->ucPll0SelectedSrcClock;
        LulPll0PLLC = (uint32) Mcu_GpClockSetting->ulPLL0ControlValue;
        if ((LulPll0SrcClk != (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLL0IS_ACT))||
              (LulPll0PLLC != (Mcu_ClkCtrlReg_BaseAddress->ulPLL0C)))
        {
          LddReturnValue = Mcu_StandByPrepare(MCU_TRUE, MCU_FALSE, MCU_FALSE);
          if (E_OK == LddReturnValue )
          {
            /* PLL input clock Initialization Routine */
            LucCount = MCU_LOOPCOUNT;
            /* Load Pll0 source Clock */
            MCU_PROTECTED_WRITE(
              &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLL0IS_CTL),
              LulPll0SrcClk,
              &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
              &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
              LucCount, &LddReturnValue )
            #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
            /* write the value to the RAM mirror structure */
            MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulCKSC_PLL0IS_CTL,
                                                                  LulPll0SrcClk)
            #endif
            if (E_NOT_OK == LddReturnValue)
            {
              /*
               * writing to write-protected register failed and
               * report production error
               */
               Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
            }
            else
            {

            }
            /* Check if No Dem error occurred */
            if (E_OK == LddReturnValue )
            {
              /* Enable the PLL again */
              LddReturnValue = Mcu_StartPLL0();
            }
            else
            {
              /* Do Nothing */
            }
          }
          else
          {
            /* Do Nothing */
          }
        }
        else
        {
          /*
           * Same PLL source as before*/
        }
      }
    }
    else
    {
      if (E_OK == LddReturnValue)
      {
        if (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_ON))
        {
          LddReturnValue = Mcu_StandByPrepare(MCU_TRUE, MCU_FALSE, MCU_FALSE);
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
    #endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
    #if (MCU_MAINOSC_ENABLE == STD_ON)
    /* Check whether the selected clock source is main oscillator */
    if ((E_OK == LddReturnValue ) && (MCU_MAIN_OSC_SELECTED !=
                            (uint8)(LucSelectedSrcClk & MCU_MAIN_OSC_SELECTED)))
    {
      if (MCU_MAIN_OSC_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
                                                      & MCU_MAIN_OSC_ON))

      {
        LddReturnValue = Mcu_MainOscDisable();
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
    #endif /* MCU_MAINOSC_ENABLE == STD_ON */
    /* MISRA Violation: START Msg(4:0316)-6 */
    /* Get the pointer to cksc setting container */
    Mcu_GpCkscSetting =
    ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
    Mcu_GpClockSetting->pCkscSel);
    /* END Msg(4:0316)-6 */
    /* Load CKSC registers if DEM error has not occurred */
    if (E_OK == LddReturnValue )
    {
      /* Get the number of CKSC registers configured for Iso0 */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIsoCkscReg;
      /* Get the value for PLL ACT check */
      blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
      /* Configure all CKSC registers for Iso0 */
      LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_TRUE,
                                                              blPllActiveCheck);
      if (E_OK == LddReturnValue )
      {
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* Get the pointer to cksc setting container */
       /* MISRA Violation: START Msg(4:0316)-6 */
        Mcu_GpCkscSetting =
        (((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
        Mcu_GpClockSetting->pCkscSel) + Mcu_GpClockSetting->ucNoOfIsoCkscReg);
        /* END Msg(4:0488)-4 */
        /* END Msg(4:0316)-6 */
        /* Get the number of CKSC registers configured in Awo */
        LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfAwoCkscReg;
        /* Get the value for PLL ACT check */
        blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
        /* Configure all CKSC registers for AWO */
        LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_FALSE,
                                                              blPllActiveCheck);
      }
      else
      {
        /* Do Nothing */
      }
    }
    else
    {
      /* Do Nothing */
    }
    if (E_OK == LddReturnValue )
    {
      /* Get the dividing factor value for FOUT */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                              ((uint32)Mcu_GpClockSetting->usFoutDivReg),
                                   &Mcu_GddClkCntlRegRamMirror.ulFOUTDIV)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                                 ((uint32)Mcu_GpClockSetting->usFoutDivReg),
                                 MCU_FOUTDIV_MSK,
                                    MCU_INITCLOCK_SID)

    }
    else
    {
      /* Do Nothing */
    }
    #if (MCU_CLMA0_OPERATION == STD_ON)
    /* Check if No Dem error occurred and Clock monitor CLMA0 is disabled */
    if ((E_OK == LddReturnValue ) && (MCU_CTL0_RESET_VALUE ==
                      (uint8)((uint8)(Clma0Reg_BaseAddress->ucCTL0)
                            & MCU_CLMA_CTL0_ENABLE_VALUE)))
    {
      /*
       * Set the Higher threshold value for frequency limit in
       * the compare register
       */
      MCU_WRITE_REG_AND_MIRROR(&Clma0Reg_BaseAddress->ulCMPH,
                                  Mcu_GpClockSetting->usCLMA0CMPH,
                                  &Mcu_GddClkMntrReg0RamMirror.ulCMPH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Clma0Reg_BaseAddress->ulCMPH,
                                  Mcu_GpClockSetting->usCLMA0CMPH,
                                  MCU_CLMACMP_MSK,
                                  MCU_INITCLOCK_SID)

       /*
        * Set the Lower threshold value for frequency limit in
        * the compare register
        */
        MCU_WRITE_REG_AND_MIRROR(&(Clma0Reg_BaseAddress->ulCMPL),
                                   Mcu_GpClockSetting->usCLMA0CMPL,
                                   &Mcu_GddClkMntrReg0RamMirror.ulCMPL)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma0Reg_BaseAddress->ulCMPL),
                                   Mcu_GpClockSetting->usCLMA0CMPL,
                                   MCU_CLMACMP_MSK,
                                   MCU_INITCLOCK_SID)

      LucCount = MCU_LOOPCOUNT;
      /* QAC Warning: START Msg(2:3892)-29 */
      /* QAC Warning: START Msg(4:4464)-30 */
      MCU_PROTECTED_WRITE(&(Clma0Reg_BaseAddress->ucCTL0),
        MCU_CLMA_CTL0_ENABLE_VALUE,
        &(Clma0Reg_BaseAddress->ucPCMD),
        &(Clma0Reg_BaseAddress->ucPS),
        LucCount, &LddReturnValue )
      /* END Msg(4:4464)-30 */
      /* END Msg(2:3892)-29 */
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkMntrReg0RamMirror.ucCTL0,
              MCU_CLMA_CTL0_ENABLE_VALUE)
      #endif
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
    #endif /* (MCU_CLMA0_OPERATION == STD_ON) */
    #if (MCU_CLMA1_OPERATION == STD_ON)
    /* Check if No Dem error occurred and Clock monitor CLMA1 is disabled */
    if ((E_OK == LddReturnValue ) &&
              (MCU_CTL0_RESET_VALUE == ((uint8)((Clma1Reg_BaseAddress->ucCTL0)
                                                & MCU_CLMA_CTL0_ENABLE_VALUE))))
    {
      /*
      * Set the Higher threshold value for frequency limit in
      * the compare register
      */
      MCU_WRITE_REG_AND_MIRROR(&(Clma1Reg_BaseAddress->ulCMPH),
                                 Mcu_GpClockSetting->usCLMA1CMPH,
                                 &Mcu_GddClkMntrReg1RamMirror.ulCMPH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma1Reg_BaseAddress->ulCMPH),
                                  Mcu_GpClockSetting->usCLMA1CMPH,
                                  MCU_CLMACMP_MSK,
                                  MCU_INITCLOCK_SID)

      /*
      * Set the Lower threshold value for frequency limit in
      * the compare register
      */
      MCU_WRITE_REG_AND_MIRROR(&(Clma1Reg_BaseAddress->ulCMPL),
                                 Mcu_GpClockSetting->usCLMA1CMPL,
                                 &Mcu_GddClkMntrReg1RamMirror.ulCMPL)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma1Reg_BaseAddress->ulCMPL),
                                  Mcu_GpClockSetting->usCLMA1CMPL,
                                  MCU_CLMACMP_MSK,
                                  MCU_INITCLOCK_SID)

      LucCount = MCU_LOOPCOUNT;
      /* QAC Warning: START Msg(2:3892)-29 */
      /* QAC Warning: START Msg(4:4464)-30 */
      MCU_PROTECTED_WRITE(&(Clma1Reg_BaseAddress->ucCTL0),
        MCU_CLMA_CTL0_ENABLE_VALUE,
        &(Clma1Reg_BaseAddress->ucPCMD),
        &(Clma1Reg_BaseAddress->ucPS),
        LucCount, &LddReturnValue )
      /* END Msg(4:4464)-30 */
      /* END Msg(2:3892)-29 */
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkMntrReg1RamMirror.ucCTL0,
              MCU_CLMA_CTL0_ENABLE_VALUE)
      #endif
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
    #endif /* (MCU_CLMA1_OPERATION == STD_ON) */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do Nothing */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

  return (LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* (MCU_INIT_CLOCK == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_DistributePllClock
**
** Service ID         : 0x03
**
** Description        : This service activates the PLL clock to the MCU clock
**                      distribution
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void for ASR 4.0.3
**                      Std_ReturnType (E_OK, E_NOT_OK) for ASR 4.2.2
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr
**                      Mcu_GpClockSetting, Mcu_GpCkscSetting
**
** Function Invoked   : Mcu_GetPllStatus, Det_ReportError,
**                      Dem_ReportErrorStatus, Mcu_CkscConfigure,
**                      Mcu_IsoCkscCheck
**
** Registers Used     : FOUTDIV, PROTCMD0, PROTS0, PROTCMD1, PROTS1, CLMA2CTL0,
**                      CLMA2CMPL, CLMA2CMPH, CLMA2PCMD, CLMA2PS, CLMA3CTL0,
**                      CLMA3CMPL, CLMA3CMPH, CLMA3PCMD, CLMA3PS, CKSC_xxxS_CTL,
**                      CKSC_xxxD_CTL, CKSC_xxxD_ACT, CKSC_xxxS_ACT, PLL0S,
**                      PLLS/PLL1S, CKSC_xxxD_STPM, CKSC_xxxS_STPM
**
******************************************************************************/
/* Implements: MCU180_Conf, ECUC_Mcu_00180                                    */
#if (MCU_NO_PLL == STD_OFF)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_174                                                */
/* Implements: MCU100, MCU156, MCU142, MCU017, MCU166_Conf, ECUC_Mcu_00166    */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141                    */
/* Implements: SWS_Mcu_00017, SWS_Mcu_00152                                   */
/* Implements: SWS_Mcu_00056, SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00122     */
/* Implements: SWS_Mcu_00163, SWS_Mcu_00051, SWS_Mcu_00226, SWS_Mcu_00250     */
/* Implements: MCU_ESDD_UD_017, MCU_ESDD_UD_001                               */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: MCU_ESDD_UD_026                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0075_FSR_0002                                           */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
#if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void)
#else
/* Implements: MCU_ESDD_UD_174                                                */
FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void)
#endif
{
  Std_ReturnType LddReturnValue;
  uint8 LucNoOfCkscReg;
  uint8 LucNoOfIsoCkscReg;
  uint8 LucCkscSettingOffset;
  boolean blPllActiveCheck;
  #if ((MCU_CLMA2_OPERATION == STD_ON)||(MCU_CLMA3_OPERATION == STD_ON))
  uint8 LucCount;
  #endif /* (MCU_CLMA2_OPERATION == STD_ON)||(MCU_CLMA3_OPERATION == STD_ON) */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_PllStatusType LddPllLockStatus;
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #if ((MCU_CLMA2_OPERATION == STD_ON)||(MCU_CLMA3_OPERATION == STD_ON))
  LucCount = MCU_LOOPCOUNT;
  #endif /* (MCU_CLMA2_OPERATION == STD_ON)||(MCU_CLMA3_OPERATION == STD_ON) */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Get the PLL status */
  LddPllLockStatus = Mcu_GetPllStatus();
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_UNINIT);
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    LddReturnValue = E_NOT_OK;
    #endif
  }
  /* Get the PLL status and if PLL status is 'UNLOCKED', report to DET */
  else if (MCU_PLL_UNLOCKED == LddPllLockStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_PLL_NOT_LOCKED);
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    LddReturnValue = E_NOT_OK;
    #endif
  }
  /* If no DET error, continue */
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the pointer to cksc setting container */
    /* QAC Warning: START Msg(2:2814)-26 */
    Mcu_GpCkscSetting =
    ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
    &Mcu_GstCkscSetting[Mcu_GpClockSetting->ucCkscSelOffset
                                  + Mcu_GpClockSetting->ucCkscPllIndexOffset]);
    /* END Msg(2:2814)-26 */
    /* Get the number of PLL CKSC registers configured for Iso0 */
    LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfPllIsoCkscReg;
    /* Get the number of CKSC registers configured for Iso0 */
    LucNoOfIsoCkscReg = Mcu_GpClockSetting->ucNoOfIsoCkscReg;
    /* Get the value for PLL ACT check */
    blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
    /* Check Ios clock which not configured by generator is not PPLLCLK.*/
    blPllActiveCheck = Mcu_IsoCkscCheck(LucNoOfIsoCkscReg, blPllActiveCheck);
    /* Configure all CKSC registers for Iso0 */
    LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_TRUE,
                                                            blPllActiveCheck);
    if (E_OK == LddReturnValue )
    {
      LucCkscSettingOffset = Mcu_GpClockSetting->ucCkscPllIndexOffset
                                 + Mcu_GpClockSetting->ucNoOfPllIsoCkscReg
                                 + Mcu_GpClockSetting->ucCkscSelOffset;
      /* Get the pointer to cksc setting container */
      Mcu_GpCkscSetting =
      ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
      &Mcu_GstCkscSetting[LucCkscSettingOffset]);
      /* Get the number of PLL CKSC registers configured for Awo */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;
      /* Get the value for PLL ACT check */
      blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
      /* Configure all CKSC registers for AWO */
      LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_FALSE,
                                                              blPllActiveCheck);
    }
    else
    {
      /* Do Nothing */
    }
    if (E_OK == LddReturnValue )
    {
      /* Get the dividing factor value for FOUT */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                                   ((uint32)Mcu_GpClockSetting->usFoutDivReg),
                                   &Mcu_GddClkCntlRegRamMirror.ulFOUTDIV)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV,
                                    ((uint32)Mcu_GpClockSetting->usFoutDivReg),
                                    MCU_FOUTDIV_MSK,
                                    MCU_DISTRIBUTEPLLCLOCK_SID)

    }
    else
    {
      /* Do Nothing */
    }
    #if (MCU_CLMA2_OPERATION == STD_ON)
    /* Check if No error occurred and Clock monitor CLMA2 is disabled */
    if ((E_OK == LddReturnValue ) &&
              (MCU_CTL0_RESET_VALUE == ((uint8)((Clma2Reg_BaseAddress->ucCTL0)
                                                & MCU_CLMA_CTL0_ENABLE_VALUE))))
    {
      /*
      * Set the Higher threshold value for frequency limit in
      * the compare register
      */
      MCU_WRITE_REG_AND_MIRROR(&(Clma2Reg_BaseAddress->ulCMPH),
                                   Mcu_GpClockSetting->usCLMA2CMPH,
                                   &Mcu_GddClkMntrReg2RamMirror.ulCMPH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma2Reg_BaseAddress->ulCMPH),
                                    Mcu_GpClockSetting->usCLMA2CMPH,
                                    MCU_CLMACMP_MSK,
                                    MCU_DISTRIBUTEPLLCLOCK_SID)

      /*
      * Set the Lower threshold value for frequency limit in
      * the compare register
      */
      MCU_WRITE_REG_AND_MIRROR(&(Clma2Reg_BaseAddress->ulCMPL),
                                   Mcu_GpClockSetting->usCLMA2CMPL,
                                   &Mcu_GddClkMntrReg2RamMirror.ulCMPL)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma2Reg_BaseAddress->ulCMPL),
                                    Mcu_GpClockSetting->usCLMA2CMPL,
                                    MCU_CLMACMP_MSK,
                                    MCU_DISTRIBUTEPLLCLOCK_SID)

      LucCount = MCU_LOOPCOUNT;
      /* QAC Warning: START Msg(2:3892)-29 */
      /* QAC Warning: START Msg(4:4464)-30 */
      MCU_PROTECTED_WRITE(&(Clma2Reg_BaseAddress->ucCTL0),
       MCU_CLMA_CTL0_ENABLE_VALUE,
        &(Clma2Reg_BaseAddress->ucPCMD),
        &(Clma2Reg_BaseAddress->ucPS),
        LucCount, &LddReturnValue )
      /* END Msg(4:4464)-30 */
      /* END Msg(2:3892)-29 */
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkMntrReg2RamMirror.ucCTL0,
              MCU_CLMA_CTL0_ENABLE_VALUE)
      #endif
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
    #endif /* (MCU_CLMA2_OPERATION == STD_ON) */

    #if (MCU_CLMA3_OPERATION == STD_ON)
    /* Check if No error occurred and Clock monitor CLMA3 is disabled */
    if ((E_OK == LddReturnValue ) &&
          (MCU_CTL0_RESET_VALUE == ((uint8)((Clma3Reg_BaseAddress->ucCTL0)
                                                & MCU_CLMA_CTL0_ENABLE_VALUE))))
    {
      /*
       * Set the Higher threshold value for frequency limit in
       * the compare register
       */
      MCU_WRITE_REG_AND_MIRROR(&(Clma3Reg_BaseAddress->ulCMPH),
                               Mcu_GpClockSetting->usCLMA3CMPH,
                               &Mcu_GddClkMntrReg3RamMirror.ulCMPH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma3Reg_BaseAddress->ulCMPH),
                                Mcu_GpClockSetting->usCLMA3CMPH,
                                MCU_CLMACMP_MSK,
                                MCU_DISTRIBUTEPLLCLOCK_SID)

      /*
      * Set the Lower threshold value for frequency limit in
      * the compare register
      */
      MCU_WRITE_REG_AND_MIRROR(&(Clma3Reg_BaseAddress->ulCMPL),
                               Mcu_GpClockSetting->usCLMA3CMPL,
                               &Mcu_GddClkMntrReg3RamMirror.ulCMPL)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&(Clma3Reg_BaseAddress->ulCMPL),
                                Mcu_GpClockSetting->usCLMA3CMPL,
                                MCU_CLMACMP_MSK,
                                MCU_DISTRIBUTEPLLCLOCK_SID)


      LucCount = MCU_LOOPCOUNT;
      MCU_PROTECTED_WRITE(&(Clma3Reg_BaseAddress->ucCTL0),
                         MCU_ONE,
                         &(Clma3Reg_BaseAddress->ucPCMD),
                         &(Clma3Reg_BaseAddress->ucPS),
                         LucCount, &LddReturnValue )
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkMntrReg3RamMirror.ucCTL0,
              MCU_CLMA_CTL0_ENABLE_VALUE)
      #endif
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
    #endif /* (MCU_CLMA3_OPERATION == STD_ON) */


  }

#if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
  return (LddReturnValue);
#endif
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_NO_PLL == STD_OFF) */

/******************************************************************************
** Function Name      : Mcu_GetPllStatus
**
** Service ID         : 0x04
**
** Description        : This service provides the lock status of the PLL
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_PllStatusType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GucSelectedSrcClock
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : PLLS/PLL1S, PLL0S
**
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_090, MCU_ESDD_UD_001                               */
/* Implements: MCU157, MCU137, MCU138, MCU013, MCU163                         */
/* Implements: MCU008, MCU132, MCU163, MCU206                                 */
/* Implements: SWS_Mcu_00157, SWS_Mcu_00008, SWS_Mcu_00163                    */
/* Implements: SWS_Mcu_00206, SWS_Mcu_00231, SWS_Mcu_00157, SWS_Mcu_00132     */
/* Implements: EAAR_PN0075_FR_0028                                            */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: MCU180_Conf, ECUC_Mcu_00180                                    */
FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void)
{
  Mcu_PllStatusType LddPllLockStatus;
  /* QAC Warning: START Msg(2:3204)-22 */
  boolean LblPllSelectFlag;
  /* END Msg(2:3204)-22 */
  #if ((MCU_NO_PLL == STD_OFF) && (MCU_INIT_CLOCK == STD_ON))
  #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
  uint8 LucSelectedSrcClk;
  #endif /* ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)) */
  #endif /* (MCU_NO_PLL == STD_OFF) && (MCU_INIT_CLOCK == STD_ON) */
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddPllLockStatus = MCU_PLL_LOCKED;
  /* END Msg(4:2982)-5 */
  LblPllSelectFlag = MCU_FALSE;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_GETPLLSTATUS_SID, MCU_E_UNINIT);
    /* Set PLL status to undefined */
    LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;
    LblPllSelectFlag = MCU_TRUE;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_NO_PLL == STD_ON)
    LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;
    #else
    #if ((MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF))
    #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
    /*
    * Read the value of selected source clock's of the current clock
    * configuration
    */
    LucSelectedSrcClk = Mcu_GucSelectedSrcClock;
    #endif/*(MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)*/
    #if (MCU_PLL_ENABLE == STD_ON)
    /* Check the lock status of PLL */
    if (MCU_PLL_CLOCK_SELECTED ==
                            (uint8)(LucSelectedSrcClk & MCU_PLL_CLOCK_SELECTED))
    {
      LblPllSelectFlag = MCU_TRUE;
      /* QAC Warning: START Msg(2:2814)-26 */
      /* Check CLKSTAB bit */
      if (MCU_PLL_CLKSTAB_MASK !=
                ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_CLKSTAB_MASK))
      /* END Msg(2:2814)-26 */
      {
        /* PLL is not locked */
        LddPllLockStatus = MCU_PLL_UNLOCKED;
      }
      else
      {
        /* PLL is locked */
      }
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_PLL_ENABLE == STD_ON) */
    #if (MCU_PLL0_ENABLE == STD_ON)
    if ((MCU_PLL_LOCKED == LddPllLockStatus) &&
     (MCU_PLL0_CLOCK_SELECTED == (LucSelectedSrcClk & MCU_PLL0_CLOCK_SELECTED)))
    {
      LblPllSelectFlag = MCU_TRUE;
      /* Check CLKSTAB bit */
      if (MCU_PLL_CLKSTAB_MASK !=
               ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_CLKSTAB_MASK))
      {
        /* PLL1 is not locked */
        LddPllLockStatus = MCU_PLL_UNLOCKED;
      }
      else
      {
        /* PLL1 is locked */
      }
    }
    else
    {
      /* No action required */
    }
    #endif /*  #if (MCU_PLL0_ENABLE == STD_ON) */
  }
  /* MISRA Violation: START Msg(4:2991)-18 */
  /* MISRA Violation: START Msg(4:2995)-9 */
  if (MCU_TRUE != LblPllSelectFlag)
  /* END Msg(4:2995)-9 */
  /* END Msg(4:2991)-18 */
  {
    LddPllLockStatus = MCU_PLL_UNLOCKED;
  }
  else
  {
    /* No action required */
  }
    #endif  /* (MCU_INIT_CLOCK == STD_ON) && (MCU_NO_PLL == STD_OFF) */
    #endif  /* (MCU_NO_PLL == STD_OFF) */
  return(LddPllLockStatus);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_GetResetReason
**
** Service ID         : 0x05
**
** Description        : The function reads the reset type from the hardware
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GucResetFlag, Mcu_GulResetValue
**
** Function Invoked   : Det_ReportError,Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : RESF, RESFC, RESFR, RESFRC
**
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_091, MCU_ESDD_UD_053                               */
/* Implements: MCU158, MCU134, MCU005, MCU133, MCU013, MCU052                 */
/* Implements: MCU163                                                         */
/* Implements: SWS_Mcu_00158, SWS_Mcu_00134, SWS_Mcu_00005, SWS_Mcu_00226     */
/* Implements: SWS_Mcu_00133, SWS_Mcu_00052, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00133                                                  */
/* Implements: EAAR_PN0075_FR_0035                                            */
/* Implements: EAAR_PN0075_FR_0036, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0049                                            */
FUNC(Mcu_ResetType, MCU_PUBLIC_CODE)Mcu_GetResetReason (void)
{
  uint32 LulResetValue;
  uint32 LulRedundantResetValue;
  Mcu_ResetType LddResetSource;
  boolean LblTriggerDemError;
  LblTriggerDemError = MCU_FALSE;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_GETRESETREASON_SID, MCU_E_UNINIT);
    /* Set Reset status to undefined */
    LddResetSource = MCU_RESET_UNDEFINED;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (E_NOT_OK == Mcu_GblResetFlag)
    {
      /* QAC Warning: START Msg(2:2814)-26 */
      Mcu_GulResetValue = (Mcu_ResfRegister_BaseAddress->ulRESF);
      Mcu_GblResetFlag = E_OK;
      LulRedundantResetValue = (Mcu_ResfRegister_BaseAddress->ulRESFR);
      /* END Msg(2:2814)-26 */
      if ((uint32)Mcu_GulResetValue != LulRedundantResetValue)
      {
         LblTriggerDemError = MCU_TRUE;
         /* Reset reason will contain both the information */
         Mcu_GulResetValue = (uint32)Mcu_GulResetValue | LulRedundantResetValue;
      }
      else
      {
        /* DO NOTHING */
      }
    }
    else
    {
      /* DO NOTHING */
    }
    LulResetValue = (uint32)Mcu_GulResetValue;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (MCU_TRUE == LblTriggerDemError)
    {
      /* RESF and RESFR are not identical => plausibility fail error */
      Dem_ReportErrorStatus(MCU_E_INCONCISTENCY_RESF_FAILURE,
                                          DEM_EVENT_STATUS_FAILED);

    }
    else
    {
        /*do nothing*/
    }

    switch ( LulResetValue )
    {
    case MCU_PURES :
      /* Reset is due to Power ON */
      LddResetSource = MCU_POWER_ON_RESET;
      break;
    case MCU_SWR :
      /* Software reset */
      LddResetSource = MCU_SW_RESET;
      break;
    case MCU_WDR0 :
      /* Reset is due to overflow of watchdog timer 0 */
      LddResetSource = MCU_WATCHDOG0_RESET;
      break;
    case MCU_WDR1 :
      /* Reset is due to overflow of watchdog timer 1 */
      LddResetSource = MCU_WATCHDOG1_RESET;
      break;
      /* Clock Monitor 0 reset */
    case MCU_CLM0 : LddResetSource = MCU_CLM0_RESET;
      break;
    case MCU_CLM1 :
      /* Clock Monitor 1 reset */
      LddResetSource = MCU_CLM1_RESET;
      break;
    case MCU_CLM2 :
      /* Clock Monitor 2 reset for F1K and F1KM-S4 devices */
      /* Clock Monitor 3 reset for F1KM-S1 devices */
      LddResetSource = MCU_CLM2_RESET;
      break;
    case MCU_LVI :
      /* Low voltage indication reset */
      LddResetSource = MCU_LVI_RESET;
      break;
    case MCU_CVM :
      /* Control voltage monitor reset */
      LddResetSource = MCU_CVM_RESET;
      break;
    case MCU_TER :
      /* Terminal reset */
      LddResetSource = MCU_TERMINAL_RESET;
      break;
    case MCU_ISO :
      /* ISO reset */
      LddResetSource = MCU_ISO_RESET;
      break;
    #ifdef MCU_WDG2_RESET_ENABLE
    case MCU_WDR2 :
      /* Reset is due to overflow of watchdog timer 2 */
      LddResetSource = MCU_WATCHDOG2_RESET;
      break;
    #endif /* MCU_WDG2_RESET_ENABLE */
    #if (MCU_CLM3_RESET_ENABLE == STD_ON)
    case MCU_CLM3 :
      /* Clock Monitor 3 reset */
      LddResetSource = MCU_CLM3_RESET;
      break;
    #endif /* MCU_CLM3_RESET_ENABLE */
      /* Reset is due to multiple or unknown sources */
    default:
      #if (MCU_RESET_REASON_MULTIPLE_RESETS == STD_OFF)
      /* Detect the most prioritary reset reason*/
      /* Order made according to the HW manual priority */
      if (MCU_RESET_UNINIT == LulResetValue)
      {
        LddResetSource = MCU_RESET_UNDEFINED;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_PURES))
      {
        LddResetSource = MCU_POWER_ON_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_TER))
      {
        LddResetSource = MCU_TERMINAL_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_WDR0))
      {
        LddResetSource = MCU_WATCHDOG0_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_WDR1))
      {
        LddResetSource = MCU_WATCHDOG1_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_CLM0))
      {
        LddResetSource = MCU_CLM0_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_CLM1))
      {
        LddResetSource = MCU_CLM1_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_CLM2))
      {
        LddResetSource = MCU_CLM2_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_CVM))
      {
        LddResetSource = MCU_CVM_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_LVI))
      {
        LddResetSource = MCU_LVI_RESET;
      }
      /* MISRA Violation: START Msg(4:0715)-31 */
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_SWR))
      {
        LddResetSource = MCU_SW_RESET;
      }
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_ISO))
      {
        LddResetSource = MCU_ISO_RESET;
      }
      #if (MCU_CLM3_RESET_ENABLE == STD_ON)
      else if (MCU_LONG_WORD_ZERO != (LulResetValue & MCU_CLM3))
      {
        LddResetSource = MCU_CLM3_RESET;
      }
      #endif
      else
      {
        LddResetSource = MCU_RESET_UNKNOWN;
      }
      /* END Msg(4:0715)-31 */
    #else
      LddResetSource = MCU_MULTIPLE_RESETS_OCCURED;
    #endif /*(MCU_RESET_REASON_MULTIPLE_RESETS == STD_ON)*/
      break;
    }
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* Clear Reset factor register RESF*/
    MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFC,
                       MCU_RESF_CLEAR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ResfRegister_BaseAddress->ulRESF,
                                   MCU_RESF_VERIFICATION_VAL,
                                   MCU_RESF_MSK,
                                   MCU_GETRESETREASON_SID)

    /* Clear Reset factor register RESFR*/
    MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFCR,
                       MCU_RESF_CLEAR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ResfRegister_BaseAddress->ulRESFR,
                                   MCU_RESFR_VERIFICATION_VAL,
                                   MCU_RESF_MSK,
                                   MCU_GETRESETREASON_SID)

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  }


  return (LddResetSource);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_GetResetRawValue
**
** Service ID         : 0x06
**
** Description        : The service return reset type value from the hardware
**                      register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GucResetFlag, Mcu_GulResetValue
**
** Function Invoked   : Det_ReportError,Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : RESF, RESFC, RESFR, RESFCR
**
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_092, MCU_ESDD_UD_001                               */
/* Implements: MCU159, MCU135, MCU006, MCU013, MCU163                         */
/* Implements: SWS_Mcu_00159, SWS_Mcu_00135, SWS_Mcu_00006, SWS_Mcu_00163     */
/* Implements: SWS_Mcu_00051, SWS_Mcu_00226, SWS_Mcu_00017, SWS_Mcu_00135     */
/* Implements: EAAR_PN0075_FR_0086                                            */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void)
{
  uint32 LulRedundantResetValue;
  Mcu_RawResetType LddResetValue;
  boolean LblTriggerDemError;
  LblTriggerDemError = MCU_FALSE;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_GETRESETRAWVAULE_SID, MCU_E_UNINIT);
    /* Set RESET status to uninitialized */
    LddResetValue = MCU_RESET_UNINIT;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (E_NOT_OK == Mcu_GblResetFlag)
    {
      /* QAC Warning: START Msg(2:2814)-26 */
      Mcu_GulResetValue = (Mcu_ResfRegister_BaseAddress->ulRESF);
      Mcu_GblResetFlag = E_OK;
      LulRedundantResetValue = (Mcu_ResfRegister_BaseAddress->ulRESFR);
      /* END Msg(2:2814)-26 */
      if ((uint32)Mcu_GulResetValue != LulRedundantResetValue)
      {
        LblTriggerDemError = MCU_TRUE;
        /* Reset reason will contain both the information */
        Mcu_GulResetValue = (uint32)Mcu_GulResetValue | LulRedundantResetValue ;
      }
      else
      {
          /* DO NOTHING */
      }
    }
    else
    {
      /* DO NOTHING */
    }
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (MCU_TRUE == LblTriggerDemError)
    {
      /* RESF and RESFR are not identical => plausibility fail error */
      Dem_ReportErrorStatus(MCU_E_INCONCISTENCY_RESF_FAILURE,
                                          DEM_EVENT_STATUS_FAILED);

    }
    else
    {
        /* DO NOTHING */
    }

    /* Get the reset factor register value */
    LddResetValue = (Mcu_RawResetType) Mcu_GulResetValue;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* Clear Reset factor register */
    MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFC,
                       MCU_RESF_CLEAR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ResfRegister_BaseAddress->ulRESF,
                                   MCU_RESF_VERIFICATION_VAL,
                                   MCU_RESF_MSK,
                                   MCU_GETRESETRAWVAULE_SID)

    /* Clear Reset factor register RESFR*/
    MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFCR,
                       MCU_RESF_CLEAR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ResfRegister_BaseAddress->ulRESFR,
                                   MCU_RESFR_VERIFICATION_VAL,
                                   MCU_RESF_MSK,
                                   MCU_GETRESETRAWVAULE_SID)

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  }

  return(LddResetValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_PerformReset
**
** Service ID         : 0x07
**
** Description        : This service provides microcontroller reset by accessing
**                      the Software reset register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD0, SWRESA, PROTS0
**
******************************************************************************/
/*Implements: MCU_ESDD_UD_021*/
/*Implements: MCU167_Conf */
#if (MCU_PERFORM_RESET_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_094                                                */
/* Implements: MCU160, MCU143, MCU144, MCU145, MCU146, MCU145                 */
/* Implements: MCU055, MCU160, MCU166, MCU163, MCU055, MCU160, MCU143         */
/* Implements: SWS_Mcu_00160, SWS_Mcu_00143, SWS_Mcu_00144, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00145, SWS_Mcu_00146, SWS_Mcu_00055, SWS_Mcu_00160     */
/* Implements: SWS_Mcu_00166, SWS_Mcu_00163, SWS_Mcu_00143, SWS_Mcu_00145     */
/* Implements: ECUC_Mcu_00167                                                 */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0075_FSR_0025, EAAR_PN0075_FSR_0030                     */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
FUNC (void, MCU_PUBLIC_CODE) Mcu_PerformReset (void)
{
  #if (MCU_SW_RESET_CALL_API == STD_OFF)
  uint8 LucSWRESCount;
  Std_ReturnType LddReturnValue;
  LucSWRESCount = MCU_LOOPCOUNT;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #endif /* MCU_SW_RESET_CALL_API == STD_OFF */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_PERFORMRESET_SID,
    MCU_E_UNINIT);
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_SW_RESET_CALL_API == STD_ON)
    MCU_RESET_CALLOUT();
    #else
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* QAC Warning: START Msg(2:2814)-26 */
    MCU_PROTECTED_WRITE(&(Mcu_ResfRegister_BaseAddress->ulSWRESA),
      MCU_RES_CORRECT_VAL,
      &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
      &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
      LucSWRESCount, &LddReturnValue )
    /* END Msg(2:2814)-26 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

    if (E_NOT_OK == LddReturnValue)
    {
      /*
      * Writing to write-protected register failed and
      * report production error
      */
      Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_SW_RESET_CALL_API == STD_ON) */
  }
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* MCU_PERFORMRESET_API == STD_ON */

/******************************************************************************
** Function Name      : Mcu_SetMode
**
** Service ID         : 0x08
**
** Description        : This service activates the MCU power modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : McuMode - Id for power mode setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr, Mcu_GpClockSetting
**                      Mcu_GucSelectedMode
**
** Function Invoked   : Mcu_DeepStopPrepare, Det_ReportError
**                      Dem_ReportErrorStatus, Mcu_StandByPrepare,
**                      Mcu_MainOscDisable, Mcu_MainOscEnable,
**                      Mcu_StartPLL, Mcu_StopPLL, Mcu_ReinitClockConfiguration,
**                      Mcu_StartPLL0, Mcu_StopPLL0, Mcu_ResumeCpuClock,
**                      Mcu_ShiftClockDomain,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : STBC0STPT, STBC0PSC, PROTCMD0, PROTS0, PLLS/PLL1S,
**                      PLL0S, CKSC_xxxS_CTL, CKSC_xxxD_ACT, CKSC_xxxS_ACT,
**                      CKSC_xxxS_CTL, MOSCS, RESF, RESFC, RESFR, RESFCR, EVFR,
**                      PROTCMD1, PROTS1, WUF0, WUF_ISO0, WUF1, MOSCSTPM, MOSCE,
**                      MOSCC, MOSCST, CLMA1CMPH, CLMA1CMPL, CLMA1PS, CLMA1PCMD,
**                      CLMA1CTL0, PLLE/PLL1E, PLL0E, PLLC/PLL1C, PLL0C
**                      WUFMSK0, WUFMSK_ISO0, WUFMSK1, WUFMSK20, CKSC_xxxD_CTL
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_095                                                */
/* Implements: MCU161, MCU147, MCU148, MCU164, MCU013                         */
/* Implements: MCU163, MCU165, SWS_Mcu_00165                                  */
/* Implements: SWS_Mcu_00161, SWS_Mcu_00147, SWS_Mcu_00147, SWS_Mcu_00226     */
/* Implements: SWS_Mcu_00148, SWS_Mcu_00164, SWS_Mcu_00163                    */
/* Implements: EAAR_PN0075_FR_0012, EAAR_PN0075_FR_0013, EAAR_PN0075_FR_0095  */
/* Implements: EAAR_PN0075_FR_0021, EAAR_PN0075_FR_0027                       */
/* Implements: EAAR_PN0075_FR_0045, EAAR_PN0075_FR_0094                       */
/* Implements: MCU_ESDD_UD_052                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: EAAR_PN0034_FR_0084, MCU_ESDD_UD_007                           */
/* Implements: MCU_ESDD_UD_034,MCU_ESDD_UD_045,MCU_ESDD_UD_046                */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode)
/* END Msg(2:3227)-15 */
{
  P2CONST(Mcu_ModeSetting, MCU_VAR, MCU_CONFIG_CONST) LpModeSetting;
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer to array of RAM area */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpPortRamArea;
  #endif /* (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
  uint32 LulPowermode;
  Std_ReturnType LddReturnValue;
  uint8 LucMode;
  uint8 LucCount;
  #if ((MCU_MAINOSC_ENABLE == STD_ON) ||  (MCU_PLL_ENABLE == STD_ON) ||      \
                                                  (MCU_PLL0_ENABLE == STD_ON))
  uint8 LucSelectedSrcClk;
  #endif
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  uint8 LucIndex;
  #endif /* (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  boolean LblMcuMainOscOperation;
  #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
  #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
  uint16 LusSafetyCounterPll;
  /* QAC Warning: START Msg(2:3204)-22 */
  boolean LblPLL0Started;
  boolean LblPLLStarted;
  /* END Msg(2:3204)-22 */
  LblPLL0Started = MCU_FALSE;
  LblPLLStarted = MCU_FALSE;
  #endif
  /* Initialize the count value */
  LucCount = MCU_LOOPCOUNT;
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Initialize Det return value with E_NOT_OK */
  /* Report to DET, if the component is not initialized */
  if ( MCU_ZERO == Mcu_GblWakeUpPreparation )
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SETMODE_SID, MCU_E_INVALID_MODE_SEQUENCE);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SETMODE_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* Report to DET, if Mode Setting Id is out of range */
  else
  {
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    if (MCU_MAX_MODE_SET < McuMode)
    #else
    if ((MCU_ZERO == McuMode) || (MCU_MAX_MODE_SET < McuMode))
    #endif
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_SETMODE_SID, MCU_E_PARAM_MODE);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
    LpModeSetting =
       ((P2CONST(Mcu_ModeSetting, MCU_VAR,MCU_CONFIG_CONST))
       (&Mcu_GstModeSetting[((Mcu_GpConfigPtr->ucModeSettingOffset) +
                                                                    McuMode)]));

    #else
    LpModeSetting =
       ((P2CONST(Mcu_ModeSetting, MCU_VAR,MCU_CONFIG_CONST))
       (&Mcu_GstModeSetting[((Mcu_GpConfigPtr->ucModeSettingOffset) +
                                                     (McuMode - MCU_ONE))]));
    #endif
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    LucMode = LpModeSetting->ucModeType;
    #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (MCU_EVFR_DINEVF_COMPARISON_MISMATCH ==
                              ((Mcu_LpsRegisters_BaseAddress->ulEVFR)
                                         & MCU_EVFR_DINEVF_COMPARISON_MISMATCH))
    {
      /* clear the event flag Indicating Digital Input change during sequencer
       * operation
       */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                   MCU_EVFR_RESET_VALUE,
                                   &Mcu_GddLpsRegRamMirror.ulEVFR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                    MCU_EVFR_RESET_VALUE,
                                    MCU_EVFR_MSK,
                                    MCU_SETMODE_SID)
    }
    else
    {
      /* Do Nothing */
    }
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */
        #if (MCU_MAINOSC_ENABLE == STD_ON)
    LblMcuMainOscOperation = LpModeSetting->blMcuMainOscOperation;
    /* check if main oscillator to be disabled for current power down mode */
    if (MCU_FALSE == LblMcuMainOscOperation)
    {
      if (MCU_MAIN_OSC_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS) &
                                                       MCU_MAIN_OSC_ON))
      {
        LddReturnValue = Mcu_MainOscDisable();
      }
      else
      {
        /* Do Nothing */
      }
    }
    else
    {
      if (MCU_MAIN_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS) &
                                                         MCU_MAIN_OSC_ON))
      {
        LddReturnValue = Mcu_MainOscEnable();
      }
      else
      {
        /* Do Nothing */
      }
    }
    #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
    /* MISRA Violation: START Msg(4:2995)-9 */
    if (E_OK == LddReturnValue )
    {
      switch (LucMode)
      {
      case MCU_HALT_MODE:
        if (MCU_TRUE == LpModeSetting->blModeTransitionReq)
        {
          /* Assembly instruction for HALT */
          /* QAC Warning: START Msg(2:3209)-40 */
          /* MISRA Violation: START Msg(4:3200)-41 */
          /* MISRA Violation: START Msg(4:3335)-42 */
          ASM_HALT();
          /* END Msg(2:3209)-40 */
          /* END Msg(4:3200)-41 */
          /* END Msg(4:3335)-42 */
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
        }
        else
        {
          /* Do nothing if mode transition is disabled in configuration */
        }
        break;
      case MCU_STOP_MODE:
        if (MCU_TRUE == LpModeSetting->blModeTransitionReq)
        {
          #if (MCU_PLL_ENABLE == STD_ON)
          /*Shift clock domains to other sources than PLL if possible*/
          #if (MCU_PLL0_ENABLE == STD_ON)
            LddReturnValue = Mcu_ShiftClockDomain( MCU_FALSE,
                                                 MCU_FALSE, MCU_TRUE, MCU_TRUE);
          #else
            LddReturnValue = Mcu_ShiftClockDomain( MCU_FALSE, MCU_TRUE);
          #endif
          /* Check whether PLL is ON */
          if ((E_OK == LddReturnValue)&&
             (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS)& MCU_PLL_ON)))
          {
            /*Stop the PLL */
              LddReturnValue = Mcu_StopPLL();
          }
          else
          {
            /* Do nothing*/
          }
          #endif /*MCU_PLL_ENABLE == STD_ON*/
          #if (MCU_PLL0_ENABLE == STD_ON)
          if (E_OK == LddReturnValue)
          {
            /*Shift clock domains to other sources than PLL0 if possible*/
            LddReturnValue =
                         Mcu_ShiftClockDomain( MCU_FALSE, MCU_TRUE, MCU_FALSE,
                                                                      MCU_TRUE);
            /* Check whether PLL0 is ON */
            if ((E_OK == LddReturnValue) &&
                    (MCU_PLL_ON ==((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S)
                                                                 & MCU_PLL_ON)))
            {
              /*Stop the PLL */
                LddReturnValue = Mcu_StopPLL0();
            }
            else
            {
              /* Do nothing*/
            }
          }
          else
          {
            /* Do nothing*/
          }
          #endif /*MCU_PLL0_ENABLE == STD_ON*/
          /* MISRA Violation: START Msg(4:2991)-18 */
          if(E_OK == LddReturnValue)
          /* END Msg(4:2991)-18 */
          {
            LucCount = MCU_LOOPCOUNT;
            /* Set STBC0STPTRG bit */
            LulPowermode = MCU_STBC0STPTRG_MASK;
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
            #endif
            MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulSTPT),
              LulPowermode,
              &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
              &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
              LucCount, &LddReturnValue )
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
            #endif
            if (E_NOT_OK == LddReturnValue)
            {
              /*
               * writing to write-protected register failed and
               * report production error
               */
              Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              do
              {
              /*
              * Shifting the Transition to the STOP Mode while
              * Checking STBC0STPT = 01H
              */
              }while (MCU_STBC0STPTRG_MASK ==
              ((Mcu_Stbc0Register_BaseAddress->ulSTPT) & MCU_STBC0STPTRG_MASK));
            }
            #if (MCU_MAINOSC_ENABLE == STD_ON)
            if (E_OK == LddReturnValue)
            {
              LblMcuMainOscOperation = LpModeSetting->blMcuMainOscOperation;
              if (MCU_FALSE == LblMcuMainOscOperation)
              {
                LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;
                if (MCU_MAIN_OSC_SELECTED ==
                           (uint8)(LucSelectedSrcClk & MCU_MAIN_OSC_SELECTED))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  /* check if main oscillator to be disabled for current
                     power down mode */
                  if (MCU_MAIN_OSC_ON !=((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
                                                           & MCU_MAIN_OSC_ON))
                  {
                    /*Start Main Oscilator*/
                    LddReturnValue = Mcu_MainOscEnable();
                  }
                  else
                  {
                      /* Do Nothing */
                  }
                  /* END Msg(4:0715)-31 */
                }
                else
                {
                    /* Do Nothing */
                }
              }
              else
              {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  /* Do Nothing */
                  /* END Msg(4:0715)-31 */
              }
            }
            else
            {
            /*Do nothing*/
            }
            #endif /*MCU_MAINOSC_ENABLE == STD_ON*/
            #if ((MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON))
            if (E_OK == LddReturnValue)
            {
              LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;
              #if (MCU_PLL_ENABLE == STD_ON)
              if (MCU_PLL_CLOCK_SELECTED ==
                          (uint8)(LucSelectedSrcClk & MCU_PLL_CLOCK_SELECTED))
              {
                /* Check whether PLL is OFF */
                /* MISRA Violation: START Msg(4:0715)-31 */
                if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) &
                                      MCU_PLL_ON))
                {
                  /*Start the PLL */
                  LddReturnValue = Mcu_StartPLL();
                  LblPLLStarted = MCU_TRUE;
                }
                else
                {
                  /* Do Nothing */
                }
                /* END Msg(4:0715)-31 */
              }
              else
              {
                /* Do Nothing*/
              }
              #endif/* MCU_PLL_ENABLE == STD_ON */
              #if (MCU_PLL0_ENABLE == STD_ON)
              if ((E_OK == LddReturnValue) && (MCU_PLL0_CLOCK_SELECTED ==
                          (uint8)(LucSelectedSrcClk & MCU_PLL0_CLOCK_SELECTED)))
              {
                /* Check whether PLL is OFF */
                if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) &
                                      MCU_PLL_ON))
                {
                  /*Start the PLL */
                  LddReturnValue = Mcu_StartPLL0();
                  LblPLL0Started = MCU_TRUE;
                }
                else
                {
                  /* Do Nothing */
                }
              }
              else
              {
                /* Do Nothing*/
              }
              #endif /*MCU_PLL0_ENABLE == STD_ON*/
              if ((MCU_TRUE == LblPLLStarted) || (MCU_TRUE == LblPLL0Started))
              {
                #if ((MCU_PLL_ENABLE == STD_ON)&&(MCU_PLL0_ENABLE == STD_ON))
                LusSafetyCounterPll = MCU_SAFETY_LOOP_COUNT;
                while (((MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS)
                                                              & MCU_PLL_ON))
                    || (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S)
                                                             & MCU_PLL_ON)))
                                && ((uint16)MCU_ZERO < LusSafetyCounterPll))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  LusSafetyCounterPll--;
                  /* END Msg(4:0715)-31 */
                }

                if ((MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS)
                                                          & MCU_PLL_ON))
                || (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S)
                                                         & MCU_PLL_ON)))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  /* END Msg(4:0715)-31 */
                }
                else
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  /*Do nothing*/
                  /* END Msg(4:0715)-31 */
                }
                #endif
                #if ((MCU_PLL_ENABLE == STD_ON)&&(MCU_PLL0_ENABLE == STD_OFF))
                LusSafetyCounterPll = MCU_SAFETY_LOOP_COUNT;
                while ((MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS)
                                                             & MCU_PLL_ON))
                               && ((uint16)MCU_ZERO < LusSafetyCounterPll))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  LusSafetyCounterPll--;
                  /* END Msg(4:0715)-31 */
                }

                if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS)
                                                         & MCU_PLL_ON))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  /* END Msg(4:0715)-31 */
                }
                else
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  /*Do nothing*/
                  /* END Msg(4:0715)-31 */
                }
                #endif
                #if ((MCU_PLL_ENABLE == STD_OFF)&&(MCU_PLL0_ENABLE == STD_ON))
                LusSafetyCounterPll = MCU_SAFETY_LOOP_COUNT;
                while ((MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S)
                                                              & MCU_PLL_ON))
                                && ((uint16)MCU_ZERO < LusSafetyCounterPll))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  LusSafetyCounterPll--;
                  /* END Msg(4:0715)-31 */
                }

                if (MCU_PLL_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S)
                                                          & MCU_PLL_ON))
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  /* END Msg(4:0715)-31 */
                }
                else
                {
                  /* MISRA Violation: START Msg(4:0715)-31 */
                  /*Do nothing*/
                  /* END Msg(4:0715)-31 */
                }
                #endif
              }
              else
              {
                /* Do nothing*/
              }
            }
            else
            {
              /* Do nothing*/
            }
            #endif /*(MCU_PLL_ENABLE == STD_ON)||(MCU_PLL0_ENABLE == STD_ON)*/
            if (E_OK == LddReturnValue)
            {
              #if (MCU_NO_PLL == STD_OFF)
              /*Reload clock domains settings*/
              LddReturnValue = Mcu_ReinitClockConfiguration();
              #endif
              if(E_OK == LddReturnValue)
              {
                /* Check if wakeup has occurred from wakeup source 1 or Iso0 */
                LddReturnValue = Mcu_ResumeCpuClock();
              }
              else
              {
                /* Do nothing*/
              }
            }
            else
            {
              /* Do nothing*/
            }
          }
          else
          {
            /* Do nothing*/
          }
        }
        else
        {
           /* Do nothing if mode transition is disabled in configuration */
        }
        break;
      case MCU_DEEPSTOP_MODE:
        #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
        /* Store PORT registers */
           /*
            * Count for the size of array in which the values at Port
            * registers are to be stored for back-up before entering into
            * deep-stop mode
            */
        /* Get the number of Port groups configured */
        LucIndex = MCU_ZERO;
        /* Get pointer to the RAM area */
        LpPortRamArea = Mcu_GpConfigPtr->pPortRamArea;
        /* Get pointer to the Port registers structure */
        do
        {
          /*
          * Store the value of PSR register of the configured
          * Port group in BURAM area
          */
          *LpPortRamArea =
                   *(Mcu_GaaPortGroup[LucIndex].pPortGroupAddress);
          /* MISRA Violation: START Msg(4:0489)-2 */
          LpPortRamArea++;
          /* END Msg(4:0489)-2 */
          LucIndex++;
        }while ((MCU_PORT_INSTANCES + MCU_APORT_INSTANCES) > LucIndex);
        #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
        /* Prepare clocks before Deepstop mode entry Stop PLLs*/
        #if (MCU_PLL0_ENABLE == STD_ON)
        LddReturnValue = Mcu_StandByPrepare( MCU_TRUE, MCU_TRUE, MCU_FALSE);
        #else
        LddReturnValue = Mcu_StandByPrepare(MCU_FALSE);
        #endif /*  #if (MCU_PLL0_ENABLE == STD_ON) */
        if (E_OK == LddReturnValue )
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Clear Reset factor register of RESF */
          MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFC,
                             MCU_RESF_CLEAR)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                 &Mcu_ResfRegister_BaseAddress->ulRESF,
                                 MCU_RESF_VERIFICATION_VAL,
                                 MCU_RESF_MSK,
                                 MCU_SETMODE_SID)
           /* Clear Reset factor register RESFR*/
           MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFCR,
                            MCU_RESF_CLEAR)
           MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                 &Mcu_ResfRegister_BaseAddress->ulRESFR,
                                 MCU_RESFR_VERIFICATION_VAL,
                                 MCU_RESF_MSK,
                                 MCU_SETMODE_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          if (MCU_TRUE == LpModeSetting->blModeTransitionReq)
          {
            LucCount = MCU_LOOPCOUNT;
            /* Set STBC0DISTRG bit */
            LulPowermode = MCU_STBC0DISTRG_MASK;
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
            #endif
            MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulPSC),
              LulPowermode,
              &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
              &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
              LucCount, &LddReturnValue )
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
            #endif
            if (E_NOT_OK == LddReturnValue)
            {
              /*
               * writing to write-protected register failed and
               * report production error
               */
              Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
              DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              do
              {
                /*
                * Waiting for the transition to Deepstop mode after
                * Setting STBC0PSC = 02H
                */
                ASM_NOP();
                ASM_NOP();
                ASM_NOP();
                ASM_NOP();
                ASM_NOP();
              /* QAC Warning: START Msg(2:2740)-25 */
              }while ( MCU_ONE == MCU_ONE );
              /* END Msg(2:2740)-25 */
            }
          }
          else
          {
            /* Do nothing if mode transition is disabled in
            * configuration
            */
          }
        }
        else
        {
          /* No action required */
        }
        break;
      case MCU_CYCLIC_RUN_MODE:
      case MCU_CYCLIC_STOP_MODE:
        #if (MCU_RETENTIONRAM_REQ == STD_ON)
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        Mcu_GucSelectedMode = LucMode;
        /* Load wake-up factor register value */
        Mcu_GulWakeupfactor0 = LpModeSetting->ulPowerDownWakeupType0;
        Mcu_GulWakeupfactor1 = LpModeSetting->ulPowerDownWakeupTypeISO0;
        Mcu_GulWakeupfactor2 = LpModeSetting->ulPowerDownWakeupType2;
        #if (MCU_WUF1_ENABLED == STD_ON)
        Mcu_GulWakeupfactor3 = LpModeSetting->ulPowerDownWakeupType1;
        #endif
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        #endif /* (MCU_RETENTIONRAM_REQ == STD_ON) */
        /* Prepare clocks before Deepstop mode entry */
        #if (MCU_PLL0_ENABLE == STD_ON)
        LddReturnValue = Mcu_StandByPrepare( MCU_TRUE, MCU_TRUE, MCU_FALSE);
        #else
        LddReturnValue = Mcu_StandByPrepare(MCU_FALSE);
        #endif /*  #if (MCU_PLL0_ENABLE == STD_ON) */
        if (E_OK == LddReturnValue)
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Clear Reset factor register of RESF */
          MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFC,
                             MCU_RESF_CLEAR)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                 &Mcu_ResfRegister_BaseAddress->ulRESF,
                                 MCU_RESF_VERIFICATION_VAL,
                                 MCU_RESF_MSK,
                                 MCU_SETMODE_SID)
           /* Clear Reset factor register RESFR*/
          MCU_WRITE_REG_ONLY(&Mcu_ResfRegister_BaseAddress->ulRESFCR,
                             MCU_RESF_CLEAR)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                   &Mcu_ResfRegister_BaseAddress->ulRESFR,
                                   MCU_RESFR_VERIFICATION_VAL,
                                   MCU_RESF_MSK,
                                   MCU_SETMODE_SID)

            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
            #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
            if (MCU_TRUE == LpModeSetting->blModeTransitionReq)
            {
              LucCount = MCU_LOOPCOUNT;
              /* Set STBC0DISTRG bit */
              LulPowermode = MCU_STBC0DISTRG_MASK;
              #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
              MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
              #endif
              MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulPSC),
                 LulPowermode,
                 &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
                 &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
                 LucCount, &LddReturnValue )
              #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
              MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
              #endif
              if (E_NOT_OK == LddReturnValue)
              {
                /*
                    * writing to write-protected register failed and
                    * report production error
                    */
                Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                DEM_EVENT_STATUS_FAILED);
              }
              else
              {
                do
                {
                  /*
                   * Waiting for the transition to Deepstop mode after
                   * Setting STBC0PSC = 02H
                   */
                  ASM_NOP();
                  ASM_NOP();
                  ASM_NOP();
                  ASM_NOP();
                  ASM_NOP();
                  /* QAC Warning: START Msg(2:2740)-25 */
                  }while ( MCU_ONE == MCU_ONE );
                  /* END Msg(2:2740)-25 */
              }
            }
            else
            {
              /* Do nothing if mode transition is disabled in
                  * configuration
                  */
            }
          }
          else
          {
            /* Do Nothing */
          }
        break;
          /* QAC Warning: START Msg(2:2016)-28 */
      default:
        break;
      }
      /* END Msg(2:2016)-28 */
      /* END Msg(4:2995)-9 */
    }
    else
    {
      /* No action required */
    }
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* No action required */
  }

}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */


/*******************************************************************************
** Function Name      : Mcu_GetRamState
**
** Service ID         : 0x0A
**
** Description        : This service provides the actual status of the
**                      micro controller RAM area
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RamStateType (MCU_RAMSTATE_INVALID,
**                                        MCU_RAMSTATE_VALID)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Functions Invoked  : Det_ReportError
**
** Registers Used     : None
**
*******************************************************************************/
/* Implements: MCU_ESDD_UD_022 */
/* Implements: MCU181_Conf */
#if (MCU_GET_RAM_STATE_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU207, MCU208, MCU209                                         */
/* Implements: MCU_ESDD_UD_098                                                */
/* Implements: SWS_Mcu_00163, SWS_Mcu_00207, SWS_Mcu_00208, SWS_Mcu_00209     */
/* Implements: ECUC_Mcu_00181                                                 */
/* Implements: MCU_ESDD_UD_017                                                */
/* Implements: EAAR_PN0075_NR_0001, EAAR_PN0075_NR_0002                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void)
{
  Mcu_RamStateType LddRamStatus;
  LddRamStatus = MCU_RAMSTATE_INVALID;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_GETRAMSTATE_SID, MCU_E_UNINIT);
  }
  /* if no development error occurred */
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /*
    * Set the current status of RAM as valid always since hardware does not
    * support functionality for verification of Ram status
    */
    LddRamStatus = MCU_RAMSTATE_VALID;
  }
  return (LddRamStatus);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */



/******************************************************************************
** Function Name      : Mcu_CkscConfigure
**
** Service ID         : None
**
** Description        : This service prepares CKSC clock domains
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ucCkscRegs, blDomainType, blPllActiveCheck
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpCkscSetting, Mcu_GblPllActCheck
**
** Function Invoked   : Dem_ReportErrorStatus,Mcu_ReloadClockDomainSTPM
**
** Registers Used     : PROTCMD0, PROTS0, CKSC_xxxS_CTL, CKSC_xxxD_CTL,
**                      CKSC_xxxD_ACT, CKSC_xxxS_ACT, PROTS1, PROTCMD1,
**                      CKSC_xxxD_STPM, CKSC_xxxS_STPM
**
******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_101                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142, MCU188_Conf            */
/* Implements: SWS_Mcu_0015, SWS_Mcu_00140, SWS_Mcu_00141, ECUC_Mcu_00188     */
/* Implements: SWS_Mcu_00056, SWS_Mcu_00142, SWS_Mcu_00205                    */
/* Implements: SWS_Mcu_00163, SWS_Mcu_00051, SWS_Mcu_00226                    */
/* Implements: SWS_Mcu_00152                                                  */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_183                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030, EAAR_PN0075_FR_0019  */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00258, SWS_Mcu_00152                    */
/* QAC Warning: START Msg(2:3227)-15 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CkscConfigure(uint8 ucCkscRegs,
boolean blDomainType,boolean blPllActiveCheck)
/* END Msg(2:3227)-15 */
{
  /* Pointer variable for MCU CKSC clock Setting configuration */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpVal;
  /* Pointer variable for MCU CKSC clock Setting configuration */
  P2VAR(volatile const uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValAct;
  /* variable for storing clock source value of clock domains */
  uint32 LulCkscSourceRegValue;
  /* variable for storing active clock source value of clock domains */
  uint32 LulActiveRegValue;
  /* variable for storing clock Divider value of clock domains */
  uint32 LulCkscDividerRegValue;
  uint16 LusStopMaskId;
  uint16 LusSafetyCount;
  uint8 LucStopMaskValue;
  /* Variable for storing configured no of clock domains */
  uint8 LucNoOfCkscReg;
  uint8 LucCount;
  Std_ReturnType LddReturnValue;
  #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValMirror;
  LpValMirror = NULL_PTR;
  #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
  LddReturnValue = E_OK;
  LucNoOfCkscReg = ucCkscRegs;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
  /* END Msg(4:2982)-5 */
  while ((MCU_ZERO < LucNoOfCkscReg) && (E_OK == LddReturnValue))
  {
    /* QAC Warning: START Msg(2:2814)-26 */
    /*First reload the Stop Mask of the clock domains*/
    LusStopMaskId = Mcu_GpCkscSetting->ucCkscStpmskSelRegNum;
    LucStopMaskValue = Mcu_GpCkscSetting->ucCkscControlval;
    /* END Msg(2:2814)-26 */
    Mcu_ReloadClockDomainSTPM(LusStopMaskId,LucStopMaskValue);


    /* Get the pointer to the configured CKSC clock domain's
     * source select register address
     */
    switch (Mcu_GpCkscSetting->ucCkscSourceSelRegNum)
    {
    case MCU_REG_CKSC_ATAUJS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ARTCAS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_ACT);
        LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_ACT);
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */

      break;

    case MCU_REG_CKSC_AADCAS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_AFOUTS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_CPUCLKS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_PPLLCLKS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_PPLLCLKS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_IPERI1S_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI1S_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_IPERI2S_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI2S_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ILINS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ILINS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    #if (MCU_ISOADCA_SUPPORTED == STD_ON)
    case MCU_REG_CKSC_IADCAS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    #endif

    case MCU_REG_CKSC_ICANS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ICSIS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ICSIS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_IIICS_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_ACT);

      LulActiveRegValue = (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_ACT);
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_IIICS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    default:
      LulActiveRegValue = MCU_VAL_UNAVAILABLE;
      break;
    }


    /* check for availability of source selection in clock domains */
    if ((MCU_CLKDOMAIN_SRCSEL ==
       ((uint8)(Mcu_GpCkscSetting->ucCkscControlval & MCU_CLKDOMAIN_SRCSEL))) &&
       (MCU_NOT_USED != Mcu_GpCkscSetting->ucCkscSourceSelRegNum) &&
       (MCU_VAL_UNAVAILABLE != LulActiveRegValue))
    {
      LulCkscSourceRegValue =
                             (uint32)Mcu_GpCkscSetting->ucCkscSourceSelRegValue;
      /* MISRA Violation: START Msg(4:0306)-8 */
      if (MCU_CPU_CLOCK_ADDRESS == LpVal)
      /* END Msg(4:0306)-8 */
      {
        Mcu_GulCpuClockSetting = LulCkscSourceRegValue;
      }
      else
      {
        /* No action required */
      }
      LucCount = MCU_LOOPCOUNT;
      /* Check if its for ISO clock domains */
      if (MCU_TRUE == blDomainType)
      {
        /* QAC Warning: START Msg(2:2814)-26 */
        MCU_PROTECTED_WRITE(&(*LpVal),
          LulCkscSourceRegValue,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
          LucCount, &LddReturnValue )
        /* END Msg(2:2814)-26 */
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscSourceRegValue)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* Initialize AWO clock domains */
        MCU_PROTECTED_WRITE(&(*LpVal),
          LulCkscSourceRegValue,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscSourceRegValue)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
           * writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
      }
      LusSafetyCount = MCU_SAFETY_LOOP_COUNT;
      /*check if the value from CKSC_xxxS_ACT is the desired one*/
      /* QAC Warning: START Msg(2:2814)-26 */
      while (((*LpValAct) != LulCkscSourceRegValue)
                                         && ((uint16)MCU_ZERO < LusSafetyCount))
       /* END Msg(2:2814)-26 */
      {
          LusSafetyCount--;
      }
      if((Mcu_GpCkscSetting->ucCkscSourceSelRegNum == MCU_REG_CKSC_PPLLCLKS_CTL)
                                  &&(blPllActiveCheck == MCU_FALSE))
      {
        LulCkscSourceRegValue = MCU_LONG_WORD_ZERO;
        Mcu_GblPllActCheck = MCU_FALSE;
      }
      else
      {
         Mcu_GblPllActCheck = MCU_TRUE;
      }
      /*Check if setting was performed*/
      if ((*LpValAct) != LulCkscSourceRegValue)
      {
        /* Clock domain failed and report production error */
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
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

    /* Get the pointer to the configured CKSC clock domain's Divider select
     * register address
     */

    switch (Mcu_GpCkscSetting->ucCkscDividerSelRegNum)
    {
    case MCU_REG_CKSC_AWDTAD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ATAUJD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ARTCAD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_AADCAD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_CPUCLKD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    #if (MCU_ISOADCA_SUPPORTED == STD_ON)
    case MCU_REG_CKSC_IADCAD_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAD_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    #endif

    case MCU_REG_CKSC_ICANOSCD_CTL:

      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_ACT);

      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ILIND_CTL:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_ACT);
      LulActiveRegValue = Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_ACT;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
         &Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    default:
      LulActiveRegValue = MCU_VAL_UNAVAILABLE;
      break;
    }

    /* check for availability of source selection in clock domains */
    if ((MCU_CLKDOMAIN_DIVSEL ==
       ((uint8)(Mcu_GpCkscSetting->ucCkscControlval & MCU_CLKDOMAIN_DIVSEL))) &&
       (MCU_NOT_USED != Mcu_GpCkscSetting->ucCkscDividerSelRegNum) &&
       (MCU_VAL_UNAVAILABLE != LulActiveRegValue))
    {
      LulCkscDividerRegValue =
      (uint32)Mcu_GpCkscSetting->ucCkscDividerSelRegValue;
      LucCount = MCU_LOOPCOUNT;
      /* Check if the Iso clock domains to be initialized */
      if (MCU_TRUE == blDomainType )
      {
        /* Iso clock domains to be initialized */
        MCU_PROTECTED_WRITE(&(*LpVal),
          LulCkscDividerRegValue,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
          LucCount, &LddReturnValue )
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscDividerRegValue)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* Awo clock domains to be initialized */
        MCU_PROTECTED_WRITE(&(*LpVal),
          LulCkscDividerRegValue,
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
          LucCount, &LddReturnValue )
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscDividerRegValue)
        #endif
        if (E_NOT_OK == LddReturnValue)
        {
          /*
            * writing to write-protected register failed and
            * report production error
            */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          /* No action required */
        }
      }
      LusSafetyCount = MCU_SAFETY_LOOP_COUNT;
     /*check if the value from CKSC_xxxD_ACT is the desired one*/
      while (((*LpValAct) != LulCkscDividerRegValue)
                                         && ((uint16)MCU_ZERO < LusSafetyCount))
      {
          LusSafetyCount--;
      }
      if ((*LpValAct) != LulCkscDividerRegValue)
      {
        /* clock domain division failed and report production error */
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* Do Nothing */
    }

    /* MISRA Violation: START Msg(4:0489)-2 */
    Mcu_GpCkscSetting++;
    /* END Msg(4:0489)-2 */
    /* Decrement number of CKSC registers */
    LucNoOfCkscReg--;
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF) */

/******************************************************************************
** Function Name      : Mcu_Rram_Cyclic_Run
**
** Service ID         : None
**
** Description        : This service runs the Cyclic RUN and Cyclic STOP
**                      code in Retention RAM
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : WUFC0, WUFC_ISO0, WUFC20, WUFC1, WUF0, WUF_ISO0,
**                      WUF1, WUFMSK0, WUFMSK_ISO0, WUFMSK1, STBC0STPT,
**                      STBC0PSC, WUF20, WUFMSK20, PROTCMD0, PROTS0, ROSCSTPM
**
******************************************************************************/
#if (MCU_RETENTIONRAM_REQ == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: SWS_Mcu_00051, SWS_Mcu_00226                                   */
/* Implements: MCU_ESDD_UD_103                                                */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0049,EAAR_PN0034_FR_0084                        */
/* Implements: MCU_ESDD_UD_068, MCU_ESDD_UD_007                               */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
FUNC(void, MCU_PUBLIC_CODE)Mcu_Rram_Cyclic_Run(void)
{
  Std_ReturnType LddReturnValue;
  uint8 LucCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* check if wake up is for Cyclic Run mode */
  /* QAC Warning: START Msg(2:2814)-26 */
  if (MCU_WUF0_RESET_VALUE !=
                 (Wuf20Reg_BaseAddress->ulWUF0 & MCU_CYCLIC_RUN_WAKEUP))
  /* END Msg(2:2814)-26 */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* Clear wakeup factor registers */
    /* QAC Warning: START Msg(2:2814)-26 */
    MCU_WRITE_REG_ONLY(&WufReg_BaseAddress->ulWUFC0,
                       (MCU_WUF_CLR_VALUE))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUF0,
                                    MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
    MCU_WRITE_REG_ONLY(&Wuf20Reg_BaseAddress->ulWUFC0,
                       (MCU_WUFC20_CLR_VALUE))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUF0,
                                        MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
    MCU_WRITE_REG_ONLY(&WufIsoReg_BaseAddress->ulWUFC0,
                       (MCU_WUFC_ISO0_CLR_VALUE))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUF0,
                                        MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
    #if (MCU_WUF1_ENABLED == STD_ON)
    MCU_WRITE_REG_ONLY(&Wuf10Reg_BaseAddress->ulWUFC0,
                       (MCU_WUF1_CLR_VALUE))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUF0,
                                    MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
    #endif
    /* END Msg(2:2814)-26 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (MCU_CYCLIC_RUN_MODE == Mcu_GucSelectedMode)
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* Load wake-up factor register values for wakeup from Deepstop to
      * RUN
      */
      MCU_WRITE_REG_AND_MIRROR(&WufReg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor0,
                       &Mcu_GddWufReg0RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor0,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      MCU_WRITE_REG_AND_MIRROR(&WufIsoReg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor1,
                       &Mcu_GddWufRegIsoRamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor1,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      /* Load wake up factors for wake up from deepstop to cyclic RUN */
      MCU_WRITE_REG_AND_MIRROR(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor2,
                       &Mcu_GddWufReg20RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor2,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      #if (MCU_WUF1_ENABLED == STD_ON)
      MCU_WRITE_REG_AND_MIRROR(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor3,
                       &Mcu_GddWufReg10RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor3,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      #endif
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* Highspeed IntOsc continues operation in stand-by mode  */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* QAC Warning: START Msg(2:2814)-26 */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                ((Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM)
                                | MCU_ROSCSTPM_BIT_ZERO),
                                &Mcu_GddClkCntlRegRamMirror.ulROSCSTPM)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM,
                                 ((Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM)
                                 | MCU_LONG_WORD_ONE),
                                 MCU_STPM_MSK,
                                 MCU_RRAMCYCLICRUN_API_ID)
      /* END Msg(2:2814)-26 */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      LucCount = MCU_LOOPCOUNT;
      /* Set controller to deepstop mode */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* QAC Warning: START Msg(2:2814)-26 */
      MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulPSC),
        MCU_STBC0DISTRG_MASK,
        &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
        &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
        LucCount, &LddReturnValue )
      /* END Msg(2:2814)-26 */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* QAC Warning: START Msg(2:2870)-34 */
        do
        {
          /*
           * Waiting for the transition to Deepstop mode after
           * Setting STBC0PSC = 02H
           */
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
          ASM_NOP();
        /* QAC Warning: START Msg(2:2740)-25 */
        }while ( MCU_ONE == MCU_ONE );
        /* END Msg(2:2740)-25 */
        /* END Msg(2:2870)-34 */
      }
    }
    else if (MCU_CYCLIC_STOP_MODE == Mcu_GucSelectedMode)
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Load wake-up factor register values for wakeup from Deepstop to
      * RUN
      */
      MCU_WRITE_REG_AND_MIRROR(&WufReg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor0,
                       &Mcu_GddWufReg0RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor0,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      MCU_WRITE_REG_AND_MIRROR(&WufIsoReg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor1,
                       &Mcu_GddWufRegIsoRamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor1,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)

      /* Load wake up factors for wake up from deepstop to cyclic RUN */
      MCU_WRITE_REG_AND_MIRROR(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor2,
                       &Mcu_GddWufReg20RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor2,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      #if (MCU_WUF1_ENABLED == STD_ON)
      MCU_WRITE_REG_AND_MIRROR(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                       Mcu_GulWakeupfactor3,
                       &Mcu_GddWufReg10RamMirror.ulWUFMSK0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                                   Mcu_GulWakeupfactor3,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)
      #endif

      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      LucCount = MCU_LOOPCOUNT;
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Write the write enable register */

      MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulSTPT),
        MCU_STBC0STPTRG_MASK,
        &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
        &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
        LucCount, &LddReturnValue )
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
  else
  {
    /* Masking WUF2 when WUF0 is occurred */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    MCU_WRITE_REG_AND_MIRROR(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                       MCU_MASK_WAKE_UP_FACTOR_REGISTERS,
                       &Mcu_GddWufReg20RamMirror.ulWUFMSK0)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                                   MCU_MASK_WAKE_UP_FACTOR_REGISTERS,
                                   MCU_WUF_MSK,
                                   MCU_RRAMCYCLICRUN_API_ID)

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    LucCount = MCU_LOOPCOUNT;
    /* Set controller to deepstop mode */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    MCU_PROTECTED_WRITE(&(Mcu_Stbc0Register_BaseAddress->ulPSC),
        MCU_STBC0DISTRG_MASK,
        &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
        &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
        LucCount, &LddReturnValue )
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_PWR_MODE_PSC_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    if (E_NOT_OK == LddReturnValue)
    {
      /*
      * writing to write-protected register failed and
      * report production error
      */
      Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
      DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* QAC Warning: START Msg(2:2870)-34 */
      do
      {
        /*
        * Waiting for the transition to Deepstop mode after
        * Setting STBC0PSC = 02H
        */
        ASM_NOP();
        ASM_NOP();
        ASM_NOP();
        ASM_NOP();
        ASM_NOP();
      /* QAC Warning: START Msg(2:2740)-25 */
      }while ( MCU_ONE == MCU_ONE );
      /* END Msg(2:2740)-25 */
      /* END Msg(2:2870)-34 */
    }
  }

}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_RRAM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* MCU_RETENTIONRAM_REQ */

/******************************************************************************
** Function Name      : Mcu_SequencerInit
**
** Service ID         : 0x0B
**
** Description        : This service prepares the Sequencer Operation of
**                      Digital and Analog input modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpSeqSetting
**
** Function Invoked   : Det_ReportError,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : SCTLR, DPSELR0, DPSELRH, DPSELRM, DPDSRH,
**                      DPDSRM, DPDSR0, TAUJ0TPS, TAUJ0BRS, CNTVAL,
**                      TAUJ0CDRm, TAUJ0CMOR
**
******************************************************************************/
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_151, MCU_ESDD_UD_117,MCU_ESDD_UD_119               */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0075_FR_0102                                            */
/* Implements: MCU_ESDD_UD_118, MCU_ESDD_UD_122                               */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: MCU_ESDD_UD_123, MCU_ESDD_UD_146, MCU_ESDD_UD_104              */
/* Implements: MCU_ESDD_UD_111                                                */
/* Implements: MCU015                                                         */
/* Implements: SWS_Mcu_00152                                                  */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerInit(Mcu_SeqType
McuSequencer)
/* END Msg(2:3227)-15 */
{
  P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST) LpSeqSetting;
  P2VAR(volatile TAUJChReg, AUTOMATIC, MCU_CONFIG_DATA) LpTaujChReg;
  #if (MCU_DIGITAL_INPUT_MODE == STD_ON)
  P2CONST(Mcu_DigitalInputSetting, MCU_VAR, MCU_CONFIG_CONST)
  LpDigitalInputSetting;
  #endif /* (MCU_DIGITAL_INPUT_MODE == STD_ON) */
  Std_ReturnType LddReturnValue;
  uint32 LulSeqCtlreg;
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SEQUENCERINIT_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* Report to DET, if sequencer Id is invalid */
  else
  {
    if (MCU_MAX_SEQ_SET  <= McuSequencer)
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_SEQUENCERINIT_SID, MCU_E_PARAM_SEQUENCER);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue )
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    Mcu_GpSeqSetting =
    ((P2CONST(Mcu_SequencerSetting, MCU_VAR,MCU_CONFIG_CONST))
                             (&Mcu_GstSequencerSetting[McuSequencer]));
    LpSeqSetting = Mcu_GpSeqSetting;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #if (MCU_DIGITAL_INPUT_MODE == STD_ON)
    /* MISRA Violation: START Msg(4:0316)-6 */
    LpDigitalInputSetting = ((P2CONST(Mcu_DigitalInputSetting, MCU_VAR,
    MCU_CONFIG_CONST))(LpSeqSetting->pDigitalInputModeSetting));
    /* END Msg(4:0316)-6 */
    #endif /* (MCU_DIGITAL_INPUT_MODE == STD_ON) */
    LulSeqCtlreg = LpSeqSetting->ulSequencerCtlReg;
    #if (MCU_TAUJ0_INIT == STD_ON)
    #if (MCU_TAUJ0_PRESCALAR == STD_ON)
    /* QAC Warning: START Msg(2:2814)-26 */
    /* Load the configured prescaler value */
    MCU_WRITE_REG_AND_MIRROR(&Mcu_Tauj0OsReg_BaseAddress->usTPS,
                             LpSeqSetting->usPrescaler,
                             &Mcu_GddTaujOsRegRamMirror.usTPS)
    /* END Msg(2:2814)-26 */
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_Tauj0OsReg_BaseAddress->usTPS,
                                LpSeqSetting->usPrescaler,
                                MCU_FULL_MSK,
                                MCU_SEQUENCERINIT_SID)

    /* Load the configured baudrate value */
    MCU_WRITE_REG_AND_MIRROR(&Mcu_Tauj0OsReg_BaseAddress->ucBRS,
                             LpSeqSetting->ucBaudRate,
                             &Mcu_GddTaujOsRegRamMirror.ucBRS)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_Tauj0OsReg_BaseAddress->ucBRS,
                                LpSeqSetting->ucBaudRate,
                                MCU_FULL_MSK,
                                MCU_SEQUENCERINIT_SID)

    #endif /* (MCU_TAUJ0_PRESCALAR == STD_ON) */
    /* set the Timer channel for continuous conversion mode */
    LpTaujChReg = LpSeqSetting->pTAUJ0ChRegs;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* QAC Warning: START Msg(2:2814)-26 */
    MCU_WRITE_REG_AND_MIRROR(&LpTaujChReg->usCMOR,
                             LpTaujChReg->usCMOR
                           | (uint16)(((uint16)LpSeqSetting->ucChannelMask
                           & MCU_CLKBIT_SETMASK) << MCU_TEN),
                             &Mcu_GddTaujChRegRamMirror.usCMOR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&LpTaujChReg->usCMOR,
                           LpTaujChReg->usCMOR
                           | (uint16)(((uint16)LpSeqSetting->ucChannelMask
                           & MCU_CLKBIT_SETMASK) << MCU_TEN),
                           MCU_CMOR_MSK,
                                MCU_SEQUENCERINIT_SID)
    /* END Msg(2:2814)-26 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

    /* load the count value from the configuration */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    MCU_WRITE_REG_AND_MIRROR(&LpTaujChReg->ulCDR,
                             LpSeqSetting->ulTauj0TimerCntVal,
                             &Mcu_GddTaujChRegRamMirror.ulCDR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&LpTaujChReg->ulCDR,
                               LpSeqSetting->ulTauj0TimerCntVal,
                               MCU_FULL_MSK,
                                MCU_SEQUENCERINIT_SID)

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* TAUJ0 channel interrupt activation trigger of the sequencer */
    /* QAC Warning: START Msg(2:2814)-26 */
    MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   (LulSeqCtlreg & MCU_TJS_MASK),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    (LulSeqCtlreg & MCU_TJS_MASK),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERINIT_SID)
    /* END Msg(2:2814)-26 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    #endif /*(MCU_TAUJ0_INIT == STD_ON)*/
    if ((uint32)MCU_DIGITAL_INPUT == (LulSeqCtlreg & MCU_DIGITAL_INPUT))
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* Load no of times the port is read with or with out multiplexer */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   (Mcu_LpsRegisters_BaseAddress->ulSCTLR |
                                   (LulSeqCtlreg & MCU_DIGITAL_NUMDP_MASK)),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    (Mcu_LpsRegisters_BaseAddress->ulSCTLR |
                                    (LulSeqCtlreg & MCU_DIGITAL_NUMDP_MASK)),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERINIT_SID)

      /* Digital Stabilization time for external sensor */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->usCNTVAL,
                                   LpSeqSetting->usExternalSensorStabTime,
                                   &Mcu_GddLpsRegRamMirror.usCNTVAL)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->usCNTVAL,
                                    LpSeqSetting->usExternalSensorStabTime,
                                    MCU_CNTVAL_MSK,
                                    MCU_SEQUENCERINIT_SID)

      #if (MCU_DIGITAL_INPUT_MODE == STD_ON)
      /* QAC Warning: START Msg(2:2814)-26 */
      /* Load the Supervised channels Initial data */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                              LpDigitalInputSetting->ulDigitalPinDataSetReg0,
                              &Mcu_GddLpsRegRamMirror.ulDPDSR0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                LpDigitalInputSetting->ulDigitalPinDataSetReg0,
                                MCU_DPD_MSK,
                                MCU_SEQUENCERINIT_SID)
      /* END Msg(2:2814)-26 */
      #if (MCU_DPIN_SEL_REG_M == STD_ON)
      /* Load the Supervised channels Initial data */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                              LpDigitalInputSetting->ulDigitalPinDataSetRegM,
                              &Mcu_GddLpsRegRamMirror.ulDPDSRM)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                                LpDigitalInputSetting->ulDigitalPinDataSetRegM,
                                MCU_FULL_MSK,
                                MCU_SEQUENCERINIT_SID)

      #endif /* (MCU_DPIN_SEL_REG_M == STD_ON) */
      #if (MCU_DPIN_SEL_REG_H == STD_ON)
      /* Load the Supervised channels Initial data */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                              LpDigitalInputSetting->ulDigitalPinDataSetRegH,
                              &Mcu_GddLpsRegRamMirror.ulDPDSRH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                                LpDigitalInputSetting->ulDigitalPinDataSetRegH,
                                MCU_DPD_MSK,
                                MCU_SEQUENCERINIT_SID)

      #endif /* (MCU_DPIN_SEL_REG_H == STD_ON) */
      /* Load the channels to be supervised by sequencer for 0th time */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPSELR0,
                              LpDigitalInputSetting->ulDigitalPinSelReg0,
                              &Mcu_GddLpsRegRamMirror.ulDPSELR0)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPSELR0,
                                LpDigitalInputSetting->ulDigitalPinSelReg0,
                                MCU_DPD_MSK,
                                MCU_SEQUENCERINIT_SID)

      #if (MCU_DPIN_SEL_REG_M == STD_ON)
      /* Load the channels to be supervised by sequencer for 1st - 4th time */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPSELRM,
                              LpDigitalInputSetting->ulDigitalPinSelRegM,
                              &Mcu_GddLpsRegRamMirror.ulDPSELRM)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPSELRM,
                                LpDigitalInputSetting->ulDigitalPinSelRegM,
                                MCU_FULL_MSK,
                                MCU_SEQUENCERINIT_SID)

      #endif /* (MCU_DPIN_SEL_REG_M == STD_ON) */
      #if (MCU_DPIN_SEL_REG_H == STD_ON)
      /* Load the channels to be supervised by sequencer for 5th - 7th time */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPSELRH,
                              LpDigitalInputSetting->ulDigitalPinSelRegH,
                              &Mcu_GddLpsRegRamMirror.ulDPSELRH)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulDPSELRH,
                                LpDigitalInputSetting->ulDigitalPinSelRegH,
                                MCU_DPD_MSK,
                                MCU_SEQUENCERINIT_SID)

      #endif /* MCU_DPIN_SEL_REG_H == STD_ON */
      #endif /*(MCU_DIGITAL_INPUT_MODE == STD_ON) */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    }
    else
    {
      /* Do Nothing */
    }
    if ((uint32)MCU_ANALOG_INPUT == (LulSeqCtlreg & MCU_ANALOG_INPUT))
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* Analog Stabilization time for external sensor */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->usCNTVAL,
                                   LpSeqSetting->usExternalSensorStabTime,
                                   &Mcu_GddLpsRegRamMirror.usCNTVAL)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->usCNTVAL,
                                    LpSeqSetting->usExternalSensorStabTime,
                                    MCU_CNTVAL_MSK,
                                    MCU_SEQUENCERINIT_SID)

      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    }
    else
    {
      /* No action required */
    }
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    Mcu_GblSeqDriverStatus = MCU_INITIALIZED ;
    #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do Nothing */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SequencerStart
**
** Service ID         : 0x0C
**
** Description        : This service Starts the Sequencer Operation of
**                      Digital and Analog input modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GblSeqDriverStatus, Mcu_GpSeqSetting
**                      Mcu_Tauj0UserReg_BaseAddress
**
** Function Invoked   : Det_ReportError,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : SCTLR, TAUJ0TS, TAUJ0TE, IMR3
**
******************************************************************************/
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_152, MCU_ESDD_UD_160                               */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0103                                            */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
/* Implements: EAAR_PN0034_FR_0067                                            */
/* Implements: MCU015                                                         */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerStart(Mcu_SeqOperationType
McuSeqMode)
/* END Msg(2:3227)-15 */
{
  Std_ReturnType LddReturnValue;
  P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST) LpSeqSetting;
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblSeqDriverStatus)
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_SEQUENCERSTART_SID, MCU_E_UNINIT);
      LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Do Nothing */
  }
  /* QAC Warning: START Msg(2:1476)-27 */
  if ((MCU_DIGITAL_INPUT > McuSeqMode ) || (MCU_MIXED_INPUT < McuSeqMode ))
  /* END Msg(2:1476)-27 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SEQUENCERSTART_SID, MCU_E_PARAM_SEQUENCER);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    LpSeqSetting = Mcu_GpSeqSetting;
    /* QAC Warning: START Msg(2:2814)-26 */
    /* QAC Warning: START Msg(2:3892)-29 */
    /* start the configured Timer channel */
    MCU_WRITE_REG_ONLY(&Mcu_Tauj0UserReg_BaseAddress->ucTS,
                       (MCU_CLKBIT_MASK & LpSeqSetting->ucChannelMask))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_Tauj0UserReg_BaseAddress->ucTE,
                         (uint8)(MCU_CLKBIT_MASK & LpSeqSetting->ucChannelMask),
                         MCU_TAUJTE_MSK,
                         MCU_SEQUENCERSTART_SID)
    /* END Msg(2:3892)-29 */
    /* END Msg(2:2814)-26 */
    /* MISRA Violation: START Msg(4:3138)-44 */
    /* MISRA Violation: START Msg(2:3141)-45 */
    /* SYNCP execution */
    EXECUTE_SYNCP();
    /*END Msg(2:3141)-45 */
    /* END Msg(4:3138)-44 */
    /* Interrupt related to LPS is activated */
    #if (MCU_INTCWEND_ISR_ENABLE == STD_ON)
    if ( Mcu_GpConfigPtr->ucINTCWEND == MCU_TRUE )
    {
    /* QAC Warning: START Msg(2:2814)-26 */
    RH850_SV_MODE_IMR_AND (16 , Mcu_ICCWEND_IMRAddress, MCU_ICCWEND_ACTIVATION);
    /* END Msg(2:2814)-26 */
    }
    else
    {
       /* No Action Required */
    }
    #endif /* ( MCU_INTCWEND_ISR_ENABLE == STD_ON) */
    if (MCU_DIGITAL_INPUT == McuSeqMode)
    {
      /* QAC Warning: START Msg(2:2814)-26 */
      /* Enable the Digital input mode */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                   | MCU_DIGITAL_INPUT),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                    | MCU_DIGITAL_INPUT),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERSTART_SID)
      /* END Msg(2:2814)-26 */
    }
    else
    {
      /* No action required */
    }
    if (MCU_ANALOG_INPUT == McuSeqMode)
    {
      /* Enable the Analog input mode */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                   | MCU_ANALOG_INPUT),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                    | MCU_ANALOG_INPUT),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERSTART_SID)
    }
    else
    {
      /* No action required */
    }
    if (MCU_MIXED_INPUT == McuSeqMode)
    {
      /* Enable the Digital and Analog input mode */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                   | MCU_MIXED_INPUT),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                    | MCU_MIXED_INPUT),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERSTART_SID)
    }
    else
    {
      /* No action required */
    }
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do Nothing */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SequencerStop
**
** Service ID         : 0x0D
**
** Description        : This service Stops the Sequencer Operation for
**                      Digital and Analog input modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variables   : Mcu_GblSeqDriverStatus, Mcu_GpSeqSetting,
**                      Mcu_Tauj0UserReg_BaseAddress
**
** Function Invoked   : Det_ReportError,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : SCTLR, EVFR, TAUJ0TT, TAUJ0TE, IMR3
**
******************************************************************************/
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_153, MCU_ESDD_UD_160                               */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0075_FR_0104                                            */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
FUNC(void, MCU_PUBLIC_CODE)Mcu_SequencerStop(void)
{
  P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST) LpSeqSetting;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LddReturnValue;
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LddReturnValue = E_OK;
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblSeqDriverStatus)
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_SEQUENCERSTOP_SID, MCU_E_UNINIT);
      LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Do Nothing */
  }
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    LpSeqSetting = Mcu_GpSeqSetting;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* QAC Warning: START Msg(2:2814)-26 */
    /* QAC Warning: START Msg(2:3892)-29 */
    /* Stop the configured Timer channel */
    MCU_WRITE_REG_ONLY(&Mcu_Tauj0UserReg_BaseAddress->ucTT,
                       (MCU_CLKBIT_MASK & LpSeqSetting->ucChannelMask))
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_Tauj0UserReg_BaseAddress->ucTE,
                            MCU_TAUJ_STOPED,
                            MCU_TAUJTE_MSK,
                            MCU_SEQUENCERSTOP_SID)
    /* END Msg(2:3892)-29 */
    /* END Msg(2:2814)-26 */
    /* MISRA Violation: START Msg(4:3138)-44 */
    /* MISRA Violation: START Msg(2:3141)-45 */
    /* SYNCP execution */
    EXECUTE_SYNCP();
    /*END Msg(2:3141)-45 */
    /* END Msg(4:3138)-44 */
    /* Disable the Sequencer operation for both Analog and Digital */
    /* QAC Warning: START Msg(2:2814)-26 */
    MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                   ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                   & (~MCU_SEQ_STOP_MASK)),
                                   &Mcu_GddLpsRegRamMirror.ulSCTLR)
    MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulSCTLR,
                                    ((Mcu_LpsRegisters_BaseAddress->ulSCTLR)
                                    & (~MCU_SEQ_STOP_MASK)),
                                    MCU_FULL_MSK,
                                    MCU_SEQUENCERSTOP_SID)
    /* END Msg(2:2814)-26 */
    #if (MCU_INTCWEND_ISR_ENABLE == STD_ON)
    if ( Mcu_GpConfigPtr->ucINTCWEND == MCU_TRUE )
    {
    /* QAC Warning: START Msg(2:2814)-26 */
    RH850_SV_MODE_IMR_OR( 16 , Mcu_ICCWEND_IMRAddress,
                                   ((uint16)~MCU_ICCWEND_ACTIVATION));
    /* END Msg(2:2814)-26 */
    }
    else
    {

    }
    #endif /* (MCU_INTCWEND_ISR_ENABLE == STD_ON) */

    if (MCU_EVFR_DINEVF_COMPARISON_MISMATCH ==
                           ((Mcu_LpsRegisters_BaseAddress->ulEVFR)
                                         & MCU_EVFR_DINEVF_COMPARISON_MISMATCH))
    {
      /* clear the event flag Indicating Digital Input change during sequencer
       * operation
       */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                  MCU_EVFR_RESET_VALUE,
                                   &Mcu_GddLpsRegRamMirror.ulEVFR)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_LpsRegisters_BaseAddress->ulEVFR,
                                    MCU_EVFR_RESET_VALUE,
                                    MCU_EVFR_MSK,
                                    MCU_SEQUENCERSTOP_SID)
    }
    else
    {
      /* Do Nothing */
    }
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do Nothing */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON*/

}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_CopyToSection
**
** Service ID         : 0x0E
**
** Description        : This service Facilitates the code copy to Retention
**                      Ram Area
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_Intvec_CalcRange, Mcu_Code_CalcRange,
**                      Det_ReportError and Mcu_Copy
**
** Registers Used     : None
**
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_116                                                */
/* Implements: MCU017, MCU166_Conf, ECUC_Mcu_00166                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0064, EAAR_PN0034_FR_0049                       */
#if (MCU_COPY_TO_SECTION_API == STD_ON)
FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CopyToSection(void)
#else
/* Implements: MCU_ESDD_UD_116                                                */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_CopyToSection(void)
#endif /* (MCU_COPY_TO_SECTION_API == STD_ON) */
{
  #if ((MCU_RETENTIONRAM_REQ == STD_ON)&&(MCU_COPY_TO_SECTION_API == STD_ON))
  uint32 LulCurSrcAddr;
  uint32 LulNextSrcAddr;
  uint32 LulDestAddr;
  uint32 LulCurSize;
  uint32 LulNextSize;
  #endif /* (MCU_RETENTIONRAM_REQ == STD_ON)&&
                                          (MCU_COPY_TO_SECTION_API == STD_ON) */
  /* QAC Warning: START Msg(2:3204)-22 */
  Std_ReturnType LddReturnValue;
  /* END Msg(2:3204)-22 */
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_COPYTOSECTION_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if ((MCU_RETENTIONRAM_REQ == STD_ON)&&(MCU_COPY_TO_SECTION_API == STD_ON))
    /* QAC Warning: START Msg(2:2814)-26 */
    /* Get the Retention Ram start address as destination */
    LulDestAddr = Mcu_GpConfigPtr->ulRetentionRamAddr;
    /* END Msg(2:2814)-26 */
    /* Initialize the values to Zero */
    LulCurSrcAddr = MCU_LONG_WORD_ZERO;
    LulCurSize = MCU_LONG_WORD_ZERO;
    LulNextSize = MCU_LONG_WORD_ZERO;
    /* Get the source address */
    #if (MCU_COPY_TO_SECTION_API == STD_ON)
      LulNextSrcAddr = MCU_LONG_WORD_ZERO;
    #else
      LulNextSrcAddr = MCU_RETENTION_RAM_SOURCE_ADDRESS;
    #endif /* (MCU_COPY_TO_SECTION_API == STD_ON)*/
    /* Assembler function for calculating Address of Int vect */
    Mcu_Intvec_CalcRange(&LulCurSrcAddr, &LulCurSize );
    if (MCU_LONG_WORD_ZERO < LulCurSize)
    {
      /* Copy the section from calculated Address of Int vect to
        * Retention RAM
        */
      LulDestAddr = Mcu_Copy(LulCurSrcAddr, LulDestAddr, LulCurSize);
    }
    else
    {
      /* Do Nothing */
    }
    /* Assembler function for calculating Address of Code */
    Mcu_Code_CalcRange( &LulNextSrcAddr, &LulNextSize );
    if (MCU_LONG_WORD_ZERO < LulNextSize)
    {
      /* MISRA Violation: START Msg(4:2983)-3 */
      /* copy the section from calculated Address of Code to Retention RAM */
      LulDestAddr = Mcu_Copy(LulNextSrcAddr, LulDestAddr, LulNextSize);
      /* END Msg(4:2983)-3 */
    }
    else
    {
      /* Do Nothing */
    }
    #endif /* (MCU_RETENTIONRAM_REQ == STD_ON)&&
                                          (MCU_COPY_TO_SECTION_API == STD_ON) */
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_Copy
**
** Service ID         : 0x0E
**
** Description        : This service copies the code to Retention Ram Area
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : uint32
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : None
**
******************************************************************************/
#if (MCU_RETENTIONRAM_REQ == STD_ON)
#if (MCU_COPY_TO_SECTION_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_112                                                */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* QAC Warning: START Msg(2:3227)-15 */
STATIC FUNC(uint32, MCU_PRIVATE_CODE)Mcu_Copy(uint32 LulAddSrc,
uint32 LulAddDest, uint32 LulSize)
/* END Msg(2:3227)-15 */
{
  uint32 LulSizeVal;
  /* Calculate the size */
  LulSizeVal = ((LulSize + MCU_LONG_WORD_THREE) >> MCU_LONG_WORD_TWO);
  for ( ; LulSizeVal > MCU_LONG_WORD_ZERO; LulSizeVal-- )
  {
    /* QAC Warning: START Msg(2:2814)-26 */
    /* MISRA Violation: START Msg(4:0306)-8 */
    /* Copy to Destination Address */
    *((uint32 *)LulAddDest) = *((uint32 *)LulAddSrc);
    /* END Msg(4:0306)-8 */
    /* END Msg(2:2814)-26 */
    /* Increment Destination Address */
    LulAddDest = LulAddDest + MCU_LONG_WORD_FOUR;
    /* Increment Source Address */
    LulAddSrc  = LulAddSrc + MCU_LONG_WORD_FOUR;
  }
  return (LulAddDest);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* MCU_COPY_TO_SECTION_API */
#endif /* MCU_RETENTIONRAM_REQ */

/******************************************************************************
** Function Name     : Mcu_StopPLL
**
** Service ID        : None
**
** Description       : This service disables the PLL function
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Non-Reentrant
**
** Input Parameters  : None
**
** InOut Parameters  : None
**
** Output Parameters : None
**
** Return parameter  : Std_ReturnType
**
** Preconditions     : None
**
** Global Variables  : None
**
** Function Invoked  : Dem_ReportErrorStatus,
**                     MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used    : PROTCMD1, PLLE/PLL1E, PLLS/PLL1S, PROTS1
**
******************************************************************************/
#if (MCU_PLL_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_177                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142, MCU053                 */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00226, SWS_Mcu_00152                                   */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_067                                                */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StopPLL(void)
{
  Std_ReturnType LddReturnValue;
  uint16 LusSafetyExitCounterPll;
  uint8 LucCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */

  /* Disable the PLL  */
  LucCount = MCU_LOOPCOUNT;
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* QAC Warning: START Msg(2:2814)-26 */
  /* Disable the PLL clock */
  MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulPLLE),
    MCU_PLLE_STOP,
    &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
    &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
    LucCount, &LddReturnValue )
  /* END Msg(2:2814)-26 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  if (E_NOT_OK == LddReturnValue)

  {
    /*
    * writing to write-protected register failed and
    * report production error
    */
    Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                          DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  LusSafetyExitCounterPll = MCU_SAFETY_LOOP_COUNT;
  while ((MCU_PLLS_RESET != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) &
                MCU_PLL_ON)) &&
                                   ((uint16)MCU_ZERO < LusSafetyExitCounterPll))
  {
    LusSafetyExitCounterPll--;
  }
  if (MCU_PLLS_RESET != ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON))
  {
    Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                              DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /*Do nothing*/
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /*#if (MCU_PLL_ENABLE == STD_ON)*/

/******************************************************************************
** Function Name      : Mcu_StartPLL
**
** Service ID         : None
**
** Description        : This service enables the PLL function
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD1, PLLE/PLL1E, PROTS1, PLLC/PLL1C
**
******************************************************************************/
#if (MCU_PLL_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_176                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142                         */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00226                                                  */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_143                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StartPLL(void)
{
  Std_ReturnType LddReturnValue;
  uint8 LucCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* Load the value of PLL control register PLLC0 */
  /* QAC Warning: START Msg(2:2814)-26 */
  MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulPLLC,
                                  ((Mcu_ClkCtrlReg_BaseAddress->ulPLLC &
                                  (~MCU_PLLC_READ_MASK)) |
                                  Mcu_GpClockSetting->ulPLLControlValue),
                                &Mcu_GddClkCntlRegRamMirror.ulPLLC)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulPLLC,
                                  ((Mcu_ClkCtrlReg_BaseAddress->ulPLLC &
                                  (~MCU_PLLC_READ_MASK)) |
                                  Mcu_GpClockSetting->ulPLLControlValue),
                                  MCU_FULL_MSK,
                                  MCU_STARTPLL_API_ID)

  LucCount = MCU_LOOPCOUNT;
  /* Enable the PLL clock */
  MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulPLLE),
    MCU_PLLE_START,
    &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
    &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
    LucCount, &LddReturnValue )
  /* END Msg(2:2814)-26 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  if (E_NOT_OK == LddReturnValue)
  {
    /*
    * writing to write-protected register failed and
    * report production error
    */
    Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
       DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  return LddReturnValue;
}

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /*#if (MCU_PLL_ENABLE == STD_ON)*/

/******************************************************************************
** Function Name      : Mcu_StopPLL0
**
** Service ID         : None
**
** Description        : This service disables the PLL0 function
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD1, PLL0E, PLL0S, PROTS1
**
******************************************************************************/
#if (MCU_PLL0_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_185                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142                         */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00226, SWS_Mcu_00152                                   */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StopPLL0(void)
{
  Std_ReturnType LddReturnValue;
  uint16 LusSafetyExitCounterPll;
  uint8 LucCount;
  LddReturnValue = E_OK;

  /* Disable the PLL  */
  LucCount = MCU_LOOPCOUNT;
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* Disable the PLL clock */
  MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulPLL0E),
    MCU_PLL0E_STOP_PLL,
    &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
    &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
    LucCount, &LddReturnValue )
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  if (E_NOT_OK == LddReturnValue)

  {
    /*
    * writing to write-protected register failed and
    * report production error
    */
    Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                          DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  LusSafetyExitCounterPll = MCU_SAFETY_LOOP_COUNT;
  while ((MCU_PLL0S_RESET != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) &
                      MCU_PLL_ON)) &&
                                   ((uint16)MCU_ZERO < LusSafetyExitCounterPll))
  {
    LusSafetyExitCounterPll--;
  }
  if (MCU_PLL0S_RESET != ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_ON))
  {
    Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                              DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /*Do nothing*/
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /*#if (MCU_PLL0_ENABLE == STD_ON)*/

/******************************************************************************
** Function Name      : Mcu_StartPLL0
**
** Service ID         : None
**
** Description        : This service enables the PLL0 function
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Dem_ReportErrorStatus,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD1, PLL0E, PROTS1, PLL0C
**
******************************************************************************/
#if (MCU_PLL0_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_184                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142                         */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: SWS_Mcu_00152                                                  */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_143                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StartPLL0(void)
{
  Std_ReturnType LddReturnValue;
  uint8 LucCount;
  LddReturnValue = E_OK;

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* Load the value of PLL0 control register PLL0C */
  MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulPLL0C,
                                  ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0C &
                                  (~MCU_PLL0C_READ_MASK)) |
                                  Mcu_GpClockSetting->ulPLL0ControlValue),
                                &Mcu_GddClkCntlRegRamMirror.ulPLL0C)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulPLL0C,
                                  ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0C &
                                  (~MCU_PLL0C_READ_MASK)) |
                                  Mcu_GpClockSetting->ulPLL0ControlValue),
                                  MCU_FULL_MSK,
                                  MCU_STARTPLL_API_ID)

  LucCount = MCU_LOOPCOUNT;
  /* Enable the PLL clock */
  MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulPLL0E),
    MCU_PLL0E_START_PLL,
    &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
    &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
    LucCount, &LddReturnValue )
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  if (E_NOT_OK == LddReturnValue)
  {
    /*
    * writing to write-protected register failed and
    * report production error
    */
    Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
       DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  return LddReturnValue;
}

/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /*#if (MCU_PLL0_ENABLE == STD_ON)*/


/******************************************************************************
** Function Name      : Mcu_StandByPrepare
**
** Service ID         : None
**
** Description        : This service prepares all the clocks for DeepStop mode
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LblPLL0, LblPLL, LblStopModeCheck
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ShiftClockDomain,Mcu_StopPLL,
**                      Mcu_StopPLL0
**
** Registers Used     : PLL0S, PLLS/PLL1S, PROTCMD0, PROTS0, PROTCMD1, PROTS1,
**                      CKSC_xxxS_CTL, CKSC_xxxD_CTL, CKSC_xxxS_ACT, PLL0E,
**                      CKSC_xxxD_ACT, PLLE/PLL1E, CKSC_xxxD_STPM,
**                      CKSC_xxxS_STPM
**
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_115, MCU_ESDD_UD_007                               */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142                         */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
#if (MCU_PLL0_ENABLE == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StandByPrepare (boolean
                              LblPLL0, boolean LblPLL, boolean LblStopModeCheck)
#else
/* Implements: MCU_ESDD_UD_115                                                */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_StandByPrepare (boolean
                                                               LblStopModeCheck)
#endif  /*  #if (MCU_PLL0_ENABLE == STD_ON) */
{
  Std_ReturnType LddReturnValue;
  #if (MCU_PLL0_ENABLE == STD_ON)
  LddReturnValue = E_OK;
  if (STD_ON == LblPLL0)
  {
    LddReturnValue = Mcu_ShiftClockDomain(MCU_FALSE, MCU_TRUE, MCU_FALSE,
                                                              LblStopModeCheck);
  }
  if ((STD_ON == LblPLL)&&(E_OK == LddReturnValue))
  {
    LddReturnValue = Mcu_ShiftClockDomain(MCU_FALSE, MCU_FALSE, MCU_TRUE,
                                                              LblStopModeCheck);
  }
  #else
  LddReturnValue = Mcu_ShiftClockDomain( MCU_FALSE, LblStopModeCheck);
  #endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
  /* Check whether PLL is ON */
  #if (MCU_PLL0_ENABLE == STD_ON)
  if (STD_ON == LblPLL0)
  {
    if ((E_OK == LddReturnValue ) &&
           (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_ON)))
    {
      LddReturnValue = Mcu_StopPLL0();
    }
    else
    {
      /*No action*/
    }
  }
  else
  {
      /*No action*/
  }
  if (STD_ON == LblPLL)
  #endif/* MCU_PLL0_ENABLE == STD_ON*/
  {
    #if (MCU_PLL_ENABLE == STD_ON)
    if ((E_OK == LddReturnValue ) &&
        (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON)))
    {
      LddReturnValue = Mcu_StopPLL();
    }
    else
    {
      /*No Action*/
    }
    #endif /* MCU_PLL_ENABLE == STD_ON*/
  }
#if (MCU_PLL0_ENABLE == STD_ON)
  else
  {
      /*No action*/
  }
#endif /* MCU_PLL0_ENABLE == STD_ON*/
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_MainOscDisable
**
** Service ID         : None
**
** Description        : This service provide alternative clock for clock domain
**                      which are configured for Main oscillator and disables
**                      main oscillator and its related functionalities
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ShiftClockDomain,Mcu_StopPLL,
**                      Mcu_StopPLL0, MCU_ENTER_CRITICAL_SECTION,
**                      MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PLLS/PLL1S, PLL0S, MOSCSTPM, MOSCE, MOSCS, PROTS0,
**                      PROTCMD0, CKSC_xxxS_CTL, CKSC_xxxS_ACT, PLLE/PLL1E,
**                      PLL0E, CKSC_xxxD_STPM, CKSC_xxxS_STPM, PROTCMD1, PROTS1,
**                      CKSC_xxxD_CTL, CKSC_xxxD_ACT
**
******************************************************************************/
/* Implements: MCU_ESDD_UD_034                                                */
#if (MCU_MAINOSC_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_129                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142, MCU188_Conf            */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163, SWS_Mcu_00051     */
/* Implements: EAAR_PN0075_FR_0048, ECUC_Mcu_00188                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00258                                   */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_MainOscDisable(void)
{
  uint16 LusSafetyExitCounterMainOsc;
  uint8 LucCount;
  Std_ReturnType LddReturnValue;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  #if (MCU_PLL0_ENABLE == STD_ON)
  LddReturnValue = Mcu_ShiftClockDomain( MCU_TRUE, MCU_TRUE, MCU_TRUE,
                                                                     MCU_FALSE);
  #else
  LddReturnValue = Mcu_ShiftClockDomain( MCU_TRUE, MCU_FALSE);
  #endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
  /* END Msg(4:2982)-5 */
  if(E_OK == LddReturnValue)
  {
    /*STOP PLL*/
    #if (MCU_PLL_ENABLE == STD_ON)
    if (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON))
    {
        LddReturnValue = Mcu_StopPLL();
    }
    else
    {
      /*Do Nothing*/
    }
    #endif /* (MCU_PLL_ENABLE == STD_ON)  */
    /*STOP PLL0*/
    #if (MCU_PLL0_ENABLE == STD_ON)
    if(E_OK == LddReturnValue)
    {
      if (MCU_PLL_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0S) & MCU_PLL_ON))
      {
          LddReturnValue = Mcu_StopPLL0();
      }
      else
      {
        /*Do Nothing*/
      }
    }
    else
    {
      /*Do Nothing*/
    }
    #endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
    /* MISRA Violation: START Msg(4:2991)-18 */
    /* MISRA Violation: START Msg(4:2995)-9 */
    if(E_OK == LddReturnValue)
    /* END Msg(4:2995)-9 */
    /* END Msg(4:2991)-18 */
    {
      /* STOP MAIN OSCILLATOR */
      LucCount = MCU_LOOPCOUNT;
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                MCU_MOSCSTPM_BIT_ONE,
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                  MCU_MOSCSTPM_BIT_ONE,
                                  MCU_STPM_MSK,
                                  MCU_MAINOSCDISABLE_API_ID)

      /* Disable the Main Oscillator */
      MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulMOSCE),
        MCU_MOSCE_STOP_OSCILATOR,
        &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
        &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
        LucCount, &LddReturnValue )
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      if (E_NOT_OK == LddReturnValue)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
          DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* No action required */
      }
      LusSafetyExitCounterMainOsc = MCU_SAFETY_LOOP_COUNT;
      while ((MCU_MOSCS_RESET_VALUE != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
            & MCU_MAIN_OSC_ON)) &&
            ((uint16)MCU_ZERO < LusSafetyExitCounterMainOsc))
      {
        LusSafetyExitCounterMainOsc--;
      }
      if (MCU_MOSCS_RESET_VALUE != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS)
          & MCU_MAIN_OSC_ON))
      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
          DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /*Do Nothing*/
      }
    }
    else
    {
      /*Do Nothing*/
    }
  }
  else
  {
    /*Do Nothing*/
  }
  return (LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /*(MCU_MAINOSC_ENABLE == STD_ON)*/

/******************************************************************************
** Function Name      : Mcu_ReloadClockDomainSTPM
**
** Service ID         : None
**
** Description        : This function will load the specified STPM register with
**                      the configured value
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LusStopMaskId, LucStopMaskValue
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : CKSC_xxxD_STPM, CKSC_xxxS_STPM
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_175                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142                         */
/* Implements: SWS_Mcu_00156, SWS_Mcu_00140, SWS_Mcu_00141, SWS_Mcu_00056     */
/* Implements: SWS_Mcu_00142, SWS_Mcu_00205, SWS_Mcu_00163                    */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* QAC Warning: START Msg(2:3227)-15 */
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_ReloadClockDomainSTPM(
                                 uint16 LusStopMaskId, uint8 LucStopMaskValue)
/* END Msg(2:3227)-15 */
{
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpVal;
  #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValMirror;
  LpValMirror = NULL_PTR;
  #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
  LpVal = NULL_PTR;


  /*Reload the Stop Mask Register settings for clock domains*/
  if (MCU_STPM_NOT_AVAILABLE != LusStopMaskId)
  {
    /* Get the pointer to the configured CKSC clock domain's STPMSK sel
     * register address
     */
    /* QAC Warning: START Msg(2:2814)-26 */
    switch (LusStopMaskId)
    {
    case MCU_REG_CKSC_AWDTAD_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ATAUJD_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ARTCAD_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_AADCAD_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_AFOUTS_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ILIND_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ICANS_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;

    case MCU_REG_CKSC_ICANOSCD_STPM:
      LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_STPM;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
          &Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_STPM;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    /* QAC Warning: START Msg(2:2016)-28 */
    default:
      /*No Action*/
      break;
    }
    /* END Msg(2:2016)-28 */
    /* END Msg(2:2814)-26 */
    /* MISRA Violation: START Msg(4:2995)-9 */
    /* check for availability of STPMSK in clock domains */
    #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
    if ((NULL_PTR != LpVal) && (NULL_PTR != LpValMirror))
    #else
    if (NULL_PTR != LpVal)
    #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
    /* END Msg(4:2995)-9 */
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      if (MCU_CLKDOMAIN_STPMASK ==
         (uint8)(LucStopMaskValue & MCU_CLKDOMAIN_STPMASK))
      {
        /* Set the STPMSK bit of the clock domain */
        MCU_WRITE_REG_AND_MIRROR(LpVal,
                                MCU_STPMSK_NOT_STOPED,
                                 LpValMirror)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(LpVal,
                                    MCU_STPMSK_NOT_STOPED,
                                    MCU_FULL_MSK,
                                    MCU_RELOADCLKDISTPM_API_ID)
      }
      else
      {
        /* Reset the STPMSK bit of the clock domain */
        MCU_WRITE_REG_AND_MIRROR(LpVal,
                                 MCU_STPMSK_STOPED,
                                 LpValMirror)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(LpVal,
                                    MCU_STPMSK_STOPED,
                                    MCU_FULL_MSK,
                                    MCU_RELOADCLKDISTPM_API_ID)

      }
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    }
    else
    {
      /* LpVal = NULL_PTR => do nothing*/
    }
  }
  else
  {
    /* Do Nothing */
  }
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/******************************************************************************
** Function Name      : Mcu_ShiftClockDomain
**
** Service ID         : None
**
** Description        : This service will shift the Clockdomain clock to a safe
**                      source clock if driven by Main Oscillator or PLL
**                      depending on parameter passed
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LblMainOscOff, LblPll0, LblPll, LblStopModeCheck
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GpCkscSetting, Mcu_GblPllActCheck
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ReloadClockDomainSTPM,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD0, PROTS0, PROTCMD1, PROTS1, CKSC_xxxS_CTL,
**                      CKSC_xxxD_CTL, CKSC_xxxS_ACT, CKSC_xxxD_ACT,
**                      CKSC_xxxD_STPM, CKSC_xxxS_STPM
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_148                                                */
/* Implements: EAAR_PN0075_FR_0048                                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00051, SWS_Mcu_00226                    */
/* Implements: SWS_Mcu_00258                                                  */
/* Implements: MCU_ESDD_UD_068, MCU_ESDD_UD_183                               */
/* QAC Warning: START Msg(2:3227)-15 */
#if (MCU_PLL0_ENABLE == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain (boolean
      LblMainOscOff , boolean LblPll0, boolean LblPll, boolean LblStopModeCheck)
#else
/* Implements: MCU_ESDD_UD_148                                                */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain (boolean
                                        LblMainOscOff, boolean LblStopModeCheck)
#endif /* #if (MCU_PLL0_ENABLE == STD_ON) */
/* END Msg(2:3227)-15 */
{
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpVal;
  P2VAR(volatile const uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValAct;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpProtectRegPtr;
  P2VAR(volatile const uint32, AUTOMATIC, MCU_CONFIG_CONST)
                                                     LpProtectRegStatusPtr;
  /* variable for storing clock source value of clock domains */
  uint32 LulCkscSourceRegValue;
  uint32 LulValue;
  P2CONST(uint8, MCU_VAR, MCU_CONFIG_CONST) LpOffset;
  uint16 LusStopMaskId;
  uint16 LusSafetyCount;
  uint8 LucOffSet;
  uint8 LucStopMaskValue;
  uint8 LucCountClockDomain;
  uint8 LucCount;
  /* Variable for storing configured no of clock domains */
  uint8 LucNoOfCkscReg;
  uint8 LucIndex;
  Std_ReturnType LddReturnValue;
  Std_ReturnType LddRegWriteResult;
  #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValMirror;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LpValMirror = NULL_PTR;
  /* END Msg(4:2982)-5 */
  #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
  /* MISRA Violation: START Msg(4:0316)-6*/
  /* QAC Warning: START Msg(2:2814)-26 */
  LpOffset = (P2CONST(uint8, MCU_VAR, MCU_CONFIG_CONST))
                                         (Mcu_GpConfigPtr->pClockDomainOffset);
  /* END Msg(2:2814)-26 */
  /* MISRA Violation: START Msg(4:2982)-5*/
  LpVal  = NULL_PTR;
  LpProtectRegPtr = NULL_PTR;
  LpProtectRegStatusPtr = NULL_PTR;
  LddReturnValue = E_OK;
  LddRegWriteResult = E_OK;
  /* END Msg(4:2982)-5 */
  /* END Msg(4:0316)-6 */

  /*Reload the STPM values from configuration to clock domain registers*/
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* MISRA Violation: START Msg(4:0316)-6 */
  /* QAC Warning: START Msg(2:2814)-26 */
  /* Get the pointer to cksc setting container */
  Mcu_GpCkscSetting =
  ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
  Mcu_GpClockSetting->pCkscSel);
  /* END Msg(2:2814)-26 */
  /* END Msg(4:0316)-6 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

  /*first reload the Stop Mask for every used clock domain*/
  LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIsoCkscReg +
                   Mcu_GpClockSetting->ucNoOfAwoCkscReg +
                   Mcu_GpClockSetting->ucNoOfPllIsoCkscReg +
                   Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;

  for (LucIndex = MCU_ZERO ;LucIndex < LucNoOfCkscReg; LucIndex++)
  {
    /* QAC Warning: START Msg(2:2814)-26 */
    LusStopMaskId = Mcu_GpCkscSetting->ucCkscStpmskSelRegNum;
    LucStopMaskValue = Mcu_GpCkscSetting->ucCkscControlval;
    /* END Msg(2:2814)-26 */
    Mcu_ReloadClockDomainSTPM(LusStopMaskId,LucStopMaskValue);

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* MISRA Violation: START Msg(4:0489)-2 */
    Mcu_GpCkscSetting++;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* END Msg(4:0489)-2 */
  }

  /* MISRA Violation: START Msg(4:0491)-7*/
  /* QAC Warning: START Msg(2:2824)-23 */
  for (LucCountClockDomain = MCU_ZERO ;
               MCU_LONG_WORD_ZERO != LpOffset[LucCountClockDomain];
                                                          LucCountClockDomain++)
  /* END Msg(2:2824)-23 */
  /* END Msg(4:0491)-7 */
  {

    /* MISRA Violation: START Msg(4:0491)-7*/
    LucOffSet = LpOffset[LucCountClockDomain];
     /* END Msg(4:0491)-7 */

    /*Reassign source clock for the domain*/
    switch (LucOffSet)
    {
    case MCU_REG_CKSC_ATAUJS_CTL :
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        /* QAC Warning: START Msg(2:2814)-26 */
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                         &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_ACT);
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if (((MCU_TRUE == LblMainOscOff) &&
             (MCU_LONG_WORD_TWO == LulValue)) ||
                                         (MCU_LONG_WORD_FOUR == LulValue))
        {
          LulCkscSourceRegValue = (uint32) MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = (uint32) LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
        MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_ARTCAS_CTL :
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                         &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_ACT);
        LulValue = (uint32)(*LpVal);
        if ((MCU_TRUE == LblMainOscOff) && (MCU_LONG_WORD_TWO == LulValue))
        {
          LulCkscSourceRegValue = (uint32)MCU_THREE;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
          MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_AADCAS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                                 ( MCU_LONG_WORD_TWO == LulValue))||
                                            (MCU_LONG_WORD_THREE == LulValue))
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
               MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_AFOUTS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                (MCU_LONG_WORD_ONE == LulValue)) ||
                           (MCU_LONG_WORD_FIVE == LulValue) ||
                                       (MCU_LONG_WORD_SIX == LulValue))
        {
          LulCkscSourceRegValue = MCU_LONG_WORD_TWO;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
                MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_CPUCLKS_CTL:
      LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
      LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
      LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                            &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_ACT);
      LulValue = (uint32)(*LpVal);
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (((MCU_TRUE == LblMainOscOff) &&
                        ( MCU_LONG_WORD_TWO == LulValue))||
                           (LblPll0) && (MCU_LONG_WORD_ZERO == LulValue)||
                              (LblPll) && (MCU_LONG_WORD_THREE == LulValue) )
      #else
      if (((MCU_TRUE == LblMainOscOff) &&
                                  ( MCU_LONG_WORD_TWO == LulValue))||
                                              (MCU_LONG_WORD_THREE == LulValue))
      #endif /* #if (MCU_PLL1_ENABLE == STD_ON) */
      {
        LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
      }
      else
      {
        LulCkscSourceRegValue = LulValue;
      }
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
              MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    case MCU_REG_CKSC_PPLLCLKS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_ACT);
          LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                                   ( MCU_LONG_WORD_TWO == LulValue))
                                           || (MCU_LONG_WORD_THREE == LulValue))
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
              MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_PPLLCLKS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_IPERI1S_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_ACT);
        LulValue = (uint32)(*LpVal);
        if (MCU_LONG_WORD_TWO == LulValue)
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
               MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI1S_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
      /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_IPERI2S_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                             &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_ACT);
        LulValue = (uint32)(*LpVal);
        if (MCU_LONG_WORD_TWO == LulValue)
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
               MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI2S_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
      /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_ILINS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                    ( MCU_LONG_WORD_TWO == LulValue))||
                      (MCU_LONG_WORD_THREE == LulValue)||
                                                (MCU_LONG_WORD_ONE == LulValue))
        {
          LulCkscSourceRegValue = MCU_LIN_HSINTOSC_MASK;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
                 MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ILINS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    #if (MCU_ISOADCA_SUPPORTED == STD_ON)
    case MCU_REG_CKSC_IADCAS_CTL :
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                                   ( MCU_LONG_WORD_TWO == LulValue))||
                                              (MCU_LONG_WORD_THREE == LulValue))
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
                MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    #endif /* #if (MCU_ISOADCA_SUPPORTED == STD_ON) */
    case MCU_REG_CKSC_ICANS_CTL :
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                             (MCU_LONG_WORD_ONE == LulValue))||
                                   (MCU_LONG_WORD_TWO == LulValue)||
                                             (MCU_LONG_WORD_THREE == LulValue))
        {
          LulCkscSourceRegValue = MCU_LONG_WORD_ZERO;
        }
        else if ((MCU_TRUE == LblStopModeCheck) &&
                                                 ((MCU_FALSE) == LblMainOscOff))
        {
          LulCkscSourceRegValue = (uint32) MCU_ONE;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
              MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_ICSIS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_ACT);
        LulValue = (uint32)(*LpVal);
        if (((MCU_TRUE == LblMainOscOff) &&
                              (MCU_LONG_WORD_THREE == LulValue))||
                                                (MCU_LONG_WORD_TWO == LulValue))
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
                 MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ICSIS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_IIICS_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_ACT);
        LulValue = (uint32)(*LpVal);
        if (MCU_LONG_WORD_TWO == LulValue)
        {
          LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
                 MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_IIICS_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
         /* No Action Required*/
      }
      #endif
      break;
    case MCU_REG_CKSC_ICANOSCD_CTL:
      #if (MCU_PLL0_ENABLE == STD_ON)
      if (LblMainOscOff || LblPll)
      {
      #endif
        LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1);
        LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS1);
        LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_CTL;
        LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_ACT);
        LulValue = (uint32)(*LpVal);
        if ((MCU_TRUE == LblMainOscOff) &&(MCU_LONG_WORD_ZERO != LulValue))
        {
          /* Move clock domain to default value (disabled) */
          LulCkscSourceRegValue = MCU_LONG_WORD_ZERO;
        }
        else if ((MCU_TRUE == LblStopModeCheck) &&
                                                 ((MCU_FALSE) == LblMainOscOff))
        {
          LulCkscSourceRegValue = (uint32) MCU_TWO;
        }
        else
        {
          LulCkscSourceRegValue = LulValue;
        }
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
              MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_CTL;
        #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      }
      else
      {
        /* No Action Required*/
      }
      #endif
      break;
    default :
      LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
      LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
      LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                           &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_ACT);
      LulValue = (uint32)(*LpVal);
      LulCkscSourceRegValue = LulValue;
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
          MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    }
    if ((LulCkscSourceRegValue != LulValue) &&
         (NULL_PTR != LpProtectRegStatusPtr) && (NULL_PTR != LpProtectRegPtr))
    {
      LucCount = MCU_LOOPCOUNT;
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      MCU_PROTECTED_WRITE(&(*LpVal),
        LulCkscSourceRegValue,
        &(*LpProtectRegPtr),
        &(*LpProtectRegStatusPtr),
        LucCount, &LddRegWriteResult )
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscSourceRegValue)
      #endif
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      if (E_NOT_OK == LddRegWriteResult)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                  DEM_EVENT_STATUS_FAILED);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      LusSafetyCount = MCU_SAFETY_LOOP_COUNT;
      /* QAC Warning: START Msg(2:2814)-26 */
      /*check if the value from CKSC_xxxS_ACT is the desired one*/
      while (((*LpValAct) != LulCkscSourceRegValue)
                                         && ((uint16)MCU_ZERO < LusSafetyCount))
      /* END Msg(2:2814)-26 */
      {
        LusSafetyCount--;
      }
      if((LucOffSet == MCU_REG_CKSC_PPLLCLKS_CTL) &&
                                              (Mcu_GblPllActCheck == MCU_FALSE))
      {
        LulCkscSourceRegValue = MCU_LONG_WORD_ZERO;
      }
       else
      {
        /* No action required */
      }
      /*Check if setting was performed*/
      if ((*LpValAct) != LulCkscSourceRegValue)
      {
        /* Clock domain failed and report production error */
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
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
  }

  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#if (MCU_SUBOSC_ENABLE == STD_ON)
/******************************************************************************
** Function Name      : Mcu_ShiftClockDomain_fromSubOsc
**
** Service ID         : None
**
** Description        : This service will shift the Clockdomain clock from
**                      SubOscilator to the default clock
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GpCkscSetting
**
** Function Invoked   : Dem_ReportErrorStatus,
**
** Registers Used     : PROTCMD0, PROTS0, CKSC_xxxS_CTL, CKSC_xxxS_ACT
**
******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_188                                                */
/* Implements: MCU188_Conf, ECUC_Mcu_00188                                    */
/* Implements: EAAR_PN0075_FR_0048                                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0084                                            */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00051, SWS_Mcu_00226                    */
/* Implements: SWS_Mcu_00258                                                  */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ShiftClockDomain_fromSubOsc
        (void)
{
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpVal;
  P2VAR(volatile const uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValAct;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpProtectRegPtr;
  P2VAR(volatile const uint32, AUTOMATIC, MCU_CONFIG_CONST)
                                                     LpProtectRegStatusPtr;
  /* variable for storing clock source value of clock domains */
  uint32 LulCkscSourceRegValue;
  uint32 LulValue;
  P2CONST(uint8, MCU_VAR, MCU_CONFIG_CONST) LpOffset;
  uint16 LusSafetyCount;
  uint8 LucOffSet;
  uint8 LucCountClockDomain;
  uint8 LucCount;
  Std_ReturnType LddReturnValue;
  Std_ReturnType LddRegWriteResult;
  #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValMirror;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LpValMirror = NULL_PTR;
  /* END Msg(4:2982)-5 */
  #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
  /* MISRA Violation: START Msg(4:0316)-6*/
  /* QAC Warning: START Msg(2:2814)-26 */
  LpOffset = (P2CONST(uint8, MCU_VAR, MCU_CONFIG_CONST))
                                         (Mcu_GpConfigPtr->pClockDomainOffset);
  /* END Msg(2:2814)-26 */
  /* MISRA Violation: START Msg(4:2982)-5*/
  LpVal  = NULL_PTR;
  LpProtectRegPtr = NULL_PTR;
  LpProtectRegStatusPtr = NULL_PTR;
  LpValAct = NULL_PTR;
  LulCkscSourceRegValue = MCU_CLOCK_DEFAULT;
  LulValue  = MCU_CLOCK_DEFAULT;
  LddReturnValue = E_OK;
  LddRegWriteResult = E_OK;
  /* END Msg(4:2982)-5 */
  /* END Msg(4:0316)-6 */

  /*Reload the STPM values from configuration to clock domain registers*/
  /* MISRA Violation: START Msg(4:0316)-6 */
  /* QAC Warning: START Msg(2:2814)-26 */
  /* Get the pointer to cksc setting container */
  Mcu_GpCkscSetting =
  ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
  Mcu_GpClockSetting->pCkscSel);
  /* END Msg(2:2814)-26 */
  /* END Msg(4:0316)-6 */

  /* MISRA Violation: START Msg(4:0491)-7*/
  /* QAC Warning: START Msg(2:2824)-23 */
  for (LucCountClockDomain = MCU_ZERO ;
               LpOffset[LucCountClockDomain] != MCU_LONG_WORD_ZERO;
                                                          LucCountClockDomain++)
  /* END Msg(2:2824)-23 */
  /* END Msg(4:0491)-7 */
  {

    /* MISRA Violation: START Msg(4:0491)-7*/
    LucOffSet = LpOffset[LucCountClockDomain];
     /* END Msg(4:0491)-7 */

    /*Reassign source clock for the domain*/
    switch (LucOffSet)
    {
    case MCU_REG_CKSC_ARTCAS_CTL :
      /* QAC Warning: START Msg(2:2814)-26 */
      LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
      LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
      LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                     &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_ACT);
      LulValue = (uint32)(*LpVal);
      /* END Msg(2:2814)-26 */
      if ((MCU_LONG_WORD_ONE == LulValue))
      {
        LulCkscSourceRegValue = (uint32)MCU_THREE;
      }
      else
      {
        LulCkscSourceRegValue = LulValue;
      }
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      LpValMirror = (P2VAR(volatile uint32, AUTOMATIC,
      MCU_CONFIG_CONST))&Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    case MCU_REG_CKSC_AFOUTS_CTL:
      LpProtectRegPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0);
      LpProtectRegStatusPtr = &(Mcu_WriteProtReg_BaseAddress->ulPROTS0);
      LpVal =(P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                           &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_CTL;
      LpValAct = &(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_ACT);
      LulValue = (uint32)(*LpVal);
      if (MCU_LONG_WORD_FOUR == LulValue)
      {
        LulCkscSourceRegValue = MCU_LONG_WORD_TWO;
      }
      else
      {
        LulCkscSourceRegValue = LulValue;
      }
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
       LpValMirror = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                                  &Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL;
      #endif /* #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */
      break;
    /* QAC Warning: START Msg(2:2016)-28 */
    default :
      /* No actions */
      break;
    }
    /* END Msg(2:2016)-28 */
    if ((NULL_PTR != LpProtectRegStatusPtr) && (NULL_PTR != LpVal )
          && (NULL_PTR != LpProtectRegPtr)  && (NULL_PTR != LpValAct)
          && (LulCkscSourceRegValue != LulValue)
         #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
          && (NULL_PTR != LpValMirror)
         #endif
       )
    {
      LucCount = MCU_LOOPCOUNT;
      MCU_PROTECTED_WRITE(&(*LpVal),
        LulCkscSourceRegValue,
        &(*LpProtectRegPtr),
        &(*LpProtectRegStatusPtr),
        LucCount, &LddRegWriteResult )
      #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
      /* write the value to the RAM mirror structure */
      MCU_WRITE_MIRROR_ONLY(LpValMirror, LulCkscSourceRegValue)
      #endif
      if (E_NOT_OK == LddRegWriteResult)
      {
        /*
        * writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                                  DEM_EVENT_STATUS_FAILED);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      LusSafetyCount = MCU_SAFETY_LOOP_COUNT;
      /* QAC Warning: START Msg(2:2814)-26 */
      /*check if the value from CKSC_xxxS_ACT is the desired one*/
      while (((*LpValAct) != LulCkscSourceRegValue)
                                         && ((uint16)MCU_ZERO < LusSafetyCount))
      /* END Msg(2:2814)-26 */
      {
        LusSafetyCount--;
      }
      /*Check if setting was performed*/
      if ((*LpValAct) != LulCkscSourceRegValue)
      {
        /* Clock domain failed and report production error */
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
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
  }

  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /*(MCU_SUBOSC_ENABLE == STD_ON)*/


/******************************************************************************
** Function Name      : Mcu_ReinitClockConfiguration
**
** Service ID         : None
**
** Description        : This service will reload the clock domains setting
**                      to the initial configured values
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpCkscSetting, Mcu_GpClockSetting
**
** Function Invoked   : Mcu_CkscConfigure, Mcu_IsoCkscCheck
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD0, PROTS0, CKSC_xxxS_CTL, CKSC_xxxD_CTL,
**                      CKSC_xxxD_ACT, CKSC_xxxS_ACT, PROTS1, PROTCMD1,
**                      CKSC_xxxD_STPM, CKSC_xxxS_STPM
**
******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_178                                                */
/* Implements: MCU161, MCU147, MCU148, MCU164, MCU013, MCU163                 */
/* Implements: SWS_Mcu_00161, SWS_Mcu_00147, SWS_Mcu_00148                    */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ReinitClockConfiguration(void)
{
  Std_ReturnType LddReturnValue;
  uint8 LucNoOfCkscReg;
  uint8 LucNoOfIsoCkscReg;
  uint8 LucCkscSettingOffset;
  boolean blPllActiveCheck;

  LddReturnValue = (Std_ReturnType)E_OK;

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* MISRA Violation: START Msg(4:0316)-6 */
  /* Get the pointer to cksc setting container */
  Mcu_GpCkscSetting =
  ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
  Mcu_GpClockSetting->pCkscSel);
  /* END Msg(4:0316)-6 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

  /* Get the number of CKSC registers configured for Iso0 */
  LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIsoCkscReg;
  /* Get the value for PLL ACT check */
  blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
  /* Configure all CKSC registers for Iso0 */
  LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_TRUE,
                                                              blPllActiveCheck);
  if (E_OK == LddReturnValue )
  {
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* Get the pointer to cksc setting container */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* MISRA Violation: START Msg(4:0316)-6 */
    Mcu_GpCkscSetting =
    (((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
    Mcu_GpClockSetting->pCkscSel) + Mcu_GpClockSetting->ucNoOfIsoCkscReg);
    /* END Msg(4:0488)-4 */
    /* END Msg(4:0316)-6 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* Get the number of CKSC registers configured in Awo */
    LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfAwoCkscReg;
    /* Get the value for PLL ACT check */
    blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
    /* Configure all CKSC registers for AWO */
    LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_FALSE,
                                                             blPllActiveCheck);
    if (E_OK == LddReturnValue )
    {
      /* Get the pointer to cksc setting container */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      Mcu_GpCkscSetting =
      ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
      &Mcu_GstCkscSetting[Mcu_GpClockSetting->ucCkscSelOffset
                                 + Mcu_GpClockSetting->ucCkscPllIndexOffset]);
      /* Get the number of PLL CKSC registers configured for Iso0 */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfPllIsoCkscReg;
      /* Get the number of CKSC registers configured for Iso0 */
      LucNoOfIsoCkscReg = Mcu_GpClockSetting->ucNoOfIsoCkscReg;
      /* Get the value for PLL ACT check */
      blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
      /* Check Ios clock which not configured by generator is not PPLLCLK.*/
      blPllActiveCheck = Mcu_IsoCkscCheck(LucNoOfIsoCkscReg, blPllActiveCheck);
      /* Configure all CKSC registers for Iso0 */
      LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_TRUE,
                                                              blPllActiveCheck);
      if (E_OK == LddReturnValue )
      {
        LucCkscSettingOffset = Mcu_GpClockSetting->ucCkscPllIndexOffset
                              + Mcu_GpClockSetting->ucNoOfPllIsoCkscReg
                              + Mcu_GpClockSetting->ucCkscSelOffset;
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* Get the pointer to cksc setting container */
        Mcu_GpCkscSetting =
        ((P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST))
        &Mcu_GstCkscSetting[LucCkscSettingOffset]);
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* Get the number of PLL CKSC registers configured for Awo */
        LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;
        /* Get the value for PLL ACT check */
        blPllActiveCheck = Mcu_GpClockSetting->blPllActCheck;
        /* Configure all CKSC registers for AWO */
        LddReturnValue = Mcu_CkscConfigure(LucNoOfCkscReg, MCU_FALSE,
                                                             blPllActiveCheck);
      }
      else
      {
        /* Do Nothing */
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    /* Do Nothing */
  }
  return LddReturnValue;
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /*#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)*/
/******************************************************************************
** Function Name      : Mcu_MainOscEnable
**
** Service ID         : None
**
** Description        : This service will turn on the Main Oscillator
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GucClockSetting, Mcu_GpClockSetting
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_MainOscDefault,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : MOSCC, MOSCST, MOSCSTPM, MOSCS, CLMA1CMPH, CLMA1CMPL,
**                      CLMA1PS, CLMA1PCMD, CLMA1CTL0, PROTCMD0, MOSCE, PROTS0
******************************************************************************/
/* Implements: MCU_ESDD_UD_034                                               */
#if (MCU_MAINOSC_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_130                                                */
/* Implements: MCU160, MCU143, MCU144, MCU145, MCU146, MCU055                 */
/* Implements: SWS_Mcu_00160, SWS_Mcu_00143, SWS_Mcu_00144                    */
/* Implements: SWS_Mcu_00145, SWS_Mcu_00146, SWS_Mcu_00055                    */
/* Implements: SWS_Mcu_00166, SWS_Mcu_00163, SWS_Mcu_00051                    */
/* Implements: EAAR_PN0075_FSR_0030, EAAR_PN0075_FSR_0025                     */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00258                                   */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_MainOscEnable(void)
{
  uint8 LucSelectedSrcClk;
  Std_ReturnType LddReturnValue;
  uint32 LulMainClockStabCount;
  uint32 LulMOSCSTPM;
  #if (MCU_CLMA1_OPERATION == STD_ON)
  uint8 LucCount;
  #endif /* (MCU_CLMA1_OPERATION == STD_ON) */
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
#if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
  if (MCU_ZERO != Mcu_GucClockSetting)
  {
#endif
    /* Store the pointer to the configured clock structure  */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* QAC Warning: START Msg(2:2814)-26 */
    LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;
    /* END Msg(2:2814)-26 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
    #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
    /* Check whether the selected clock source is main oscillator */
    if (MCU_MAIN_OSC_SELECTED ==
                             (uint8)(LucSelectedSrcClk & MCU_MAIN_OSC_SELECTED))
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* QAC Warning: START Msg(2:2814)-26 */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCC,
                                ((uint32)(Mcu_GpClockSetting->ucMosccRegValue)
                                | MCU_MOSCC_BIT_TWO),
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCC)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCC,
                                ((uint32)(Mcu_GpClockSetting->ucMosccRegValue)
                                | MCU_MOSCC_BIT_TWO),
                                MCU_MOSCC_MSK,
                                MCU_MAINOSCENABLE_API_ID)

      /* Set Main Oscillator stabilization time */
      MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCST,
                                Mcu_GpClockSetting->ulMainOscStabTime,
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCST)
      MCU_CHECK_WRITE_VERIFY_RUNTIME(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCST,
                                   Mcu_GpClockSetting->ulMainOscStabTime,
                                   MCU_MOSCST_MSK,
                                   MCU_MAINOSCENABLE_API_ID)
      /* END Msg(2:2814)-26 */

      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
      #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
      /* Enable the Main Oscillator */
      LddReturnValue = Mcu_MainOscDefault();
      /* check for Main Oscillator Stop mask */
      if(E_OK == LddReturnValue)
      {
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        if (MCU_MAIN_OSC_MASKED ==
           (uint8)(Mcu_GpClockSetting->ucSelectedSTPMK & MCU_MAIN_OSC_MASKED))
        {
          LulMOSCSTPM = Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM;
          /* Main Osc continues operation in stand-by mode  */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                 (LulMOSCSTPM | MCU_MOSCSTPM_MOSCSTPMSK_BIT),
                                 &Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                  (LulMOSCSTPM | MCU_MOSCSTPM_MOSCSTPMSK_BIT),
                                  MCU_STPM_MSK,
                                  MCU_MAINOSCENABLE_API_ID)
        }
        else
        {
          /* Main Osc stops operation in stand-by mode  */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                MCU_MOSCSTPM_BIT_ONE,
                                &Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM,
                                  MCU_MOSCSTPM_BIT_ONE,
                                  MCU_STPM_MSK,
                                  MCU_MAINOSCENABLE_API_ID)
        }
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* Load the stabilization count value */
        /* QAC Warning: START Msg(2:2814)-26 */
        LulMainClockStabCount = Mcu_GpConfigPtr->ulMainClockStabCount;
        /* END Msg(2:2814)-26 */
        while ((MCU_LONG_WORD_ZERO  ==
          ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS) & MCU_MAIN_OSC_ON)) &&
                                   (MCU_LONG_WORD_ZERO < LulMainClockStabCount))
        {
          LulMainClockStabCount--;
        }
        if (MCU_MAIN_OSC_ON != ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS) &
                                                             MCU_MAIN_OSC_ON))
        {
          /* MainOsc failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                             DEM_EVENT_STATUS_FAILED);
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
      #if (MCU_CLMA1_OPERATION == STD_ON)
      /* QAC Warning: START Msg(2:2814)-26 */
      /* Check if No Dem error occurred and Clock monitor CLMA2 is disabled */
      if ((E_OK == LddReturnValue) &&
          (MCU_ZERO == (uint8)(Clma1Reg_BaseAddress->ucCTL0 & MCU_ONE)))
      /* END Msg(2:2814)-26 */
      {
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /*
         * Set the Higher threshold value for frequency limit in
         * the compare register
         */
        MCU_WRITE_REG_AND_MIRROR(&Clma1Reg_BaseAddress->ulCMPH,
                                   Mcu_GpClockSetting->usCLMA1CMPH,
                                   &Mcu_GddClkMntrReg1RamMirror.ulCMPH)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Clma1Reg_BaseAddress->ulCMPH,
                                    Mcu_GpClockSetting->usCLMA1CMPH,
                                    MCU_CLMACMP_MSK,
                                    MCU_MAINOSCENABLE_API_ID)

        /*
         * Set the Lower threshold value for frequency limit in
         * the compare register
         */
        MCU_WRITE_REG_AND_MIRROR(&Clma1Reg_BaseAddress->ulCMPL,
                                   Mcu_GpClockSetting->usCLMA1CMPL,
                                   &Mcu_GddClkMntrReg1RamMirror.ulCMPL)
        MCU_CHECK_WRITE_VERIFY_RUNTIME(&Clma1Reg_BaseAddress->ulCMPL,
                                    Mcu_GpClockSetting->usCLMA1CMPL,
                                    MCU_CLMACMP_MSK,
                                    MCU_MAINOSCENABLE_API_ID)

        LucCount = MCU_LOOPCOUNT;
        /* QAC Warning: START Msg(2:3892)-29 */
        /* QAC Warning: START Msg(4:4464)-30 */
        MCU_PROTECTED_WRITE(&(Clma1Reg_BaseAddress->ucCTL0), MCU_ONE,
          &(Clma1Reg_BaseAddress->ucPCMD),
          &(Clma1Reg_BaseAddress->ucPS),
          LucCount, &LddReturnValue )
        /* END Msg(4:4464)-30 */
        /* END Msg(2:3892)-29 */
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkMntrReg1RamMirror.ucCTL0,
                                MCU_ONE)
        #endif
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        if (E_NOT_OK == LddReturnValue)
        {
          /*
          * writing to write-protected register failed and
          * report production error
          */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
      #endif /* (MCU_CLMA1_OPERATION == STD_ON) */
    }
    else
    {
      LddReturnValue = Mcu_MainOscDefault();
    }
#if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
  }
  else
  {
    LddReturnValue = Mcu_MainOscDefault();
  }
#endif
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /*(MCU_MAINOSC_ENABLE == STD_ON) */

/*******************************************************************************
** Function Name      : Mcu_ResumeCpuClock
**
** Service ID         : NA
**
** Description        : This API is used after Stop mode to recover the clock
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameter    : None
**
** Output Parameters  : None
**
** Return Value       : Std_ReturnType
**
** Pre-condition      : None
**
** Global Variable(s) : Mcu_GulCpuClockSetting
**
** Function(s) invoked: MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : MOSCS, WUF0, PLLS/PLL1S, PROTCMD1, PROTS1, WUF1,
**                      CKSC_xxxS_CTL, WUF_ISO0
**
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_132                                                */
/* Implements: EAAR_PN0075_FR_0049                                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0086, EAAR_PN0034_FR_0085                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ResumeCpuClock (void)
{
  boolean LblCpuClockFlag;
  uint8 LucCount;
  Std_ReturnType LddReturnValue;
  LblCpuClockFlag = MCU_FALSE;
  LddReturnValue = E_OK;
  /* QAC Warning: START Msg(2:2814)-26 */
  /* Check if wakeup has occurred from wakeup source 1 or Iso0 */
  if ((MCU_WUF0_RESET_VALUE != WufReg_BaseAddress->ulWUF0) ||
    (MCU_WUF0_RESET_VALUE !=  WufIsoReg_BaseAddress->ulWUF0)
#if (MCU_WUF1_ENABLED == STD_ON)
    || (MCU_WUF0_RESET_VALUE != Wuf10Reg_BaseAddress->ulWUF0)
#endif
     )
  /* END Msg(2:2814)-26 */
  {
    /* QAC Warning: START Msg(2:2814)-26 */
    if ((uint32)Mcu_GulCpuClockSetting !=
               (uint32)((Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_CTL)))
    /* END Msg(2:2814)-26 */
    {
      if (MCU_LONG_WORD_TWO == (uint32)Mcu_GulCpuClockSetting)
      {
        /* check if Main oscillator is enabled */
        if (MCU_MAIN_OSC_ON == ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCS) &
                                                             MCU_MAIN_OSC_ON))
        {
          LblCpuClockFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
      }
      else if (MCU_LONG_WORD_THREE == (uint32)Mcu_GulCpuClockSetting)
      {
        /* check if PLL is enabled */
        if (MCU_PLL_ON ==((Mcu_ClkCtrlReg_BaseAddress->ulPLLS) & MCU_PLL_ON))
        {
          LblCpuClockFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        LblCpuClockFlag = MCU_FALSE;
      }
      if (MCU_TRUE == LblCpuClockFlag)
      {
        /* Set the CPU clock to previous clock setting value */
        LucCount = MCU_LOOPCOUNT;
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* QAC Warning: START Msg(2:2814)-26 */
        MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_CTL),
          (uint32)(Mcu_GulCpuClockSetting),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD1),
          &(Mcu_WriteProtReg_BaseAddress->ulPROTS1),
          LucCount, &LddReturnValue )
        /* END Msg(2:2814)-26 */
        #if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
        /* write the value to the RAM mirror structure */
        MCU_WRITE_MIRROR_ONLY(&Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL,
                                (uint32)(Mcu_GulCpuClockSetting))
        #endif
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
        #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        if (E_NOT_OK == LddReturnValue)
        {
          /*
           * writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
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
    else
    {
      /* No action required since CPU clock setting has not
       * changed
       */
    }
  }
  else
  {
    /* Do nothing */
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/*******************************************************************************
** Function Name      : Mcu_MainOscDefault
**
** Service ID         : NA
**
** Description        : This API is used to enable the Main Oscillator
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameter    : None
**
** Output Parameters  : None
**
** Return Value       : Std_ReturnType
**
** Pre-condition      : None
**
** Global Variable(s) : None
**
** Function(s) invoked: MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : PROTCMD0, MOSCE, PROTS0
**
*******************************************************************************/
/* Implements: MCU_ESDD_UD_034                                                */
#if (MCU_MAINOSC_ENABLE == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE

#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: MCU_ESDD_UD_147                                                */
/* Implements: MCU017, MCU166_Conf, ECUC_Mcu_00166                            */
/* Implements: EAAR_PN0075_FR_0046, EAAR_PN0075_FR_0047                       */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_MainOscDefault(void)
{
  uint8 LucCount;
  Std_ReturnType LddReturnValue;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LddReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  LucCount = MCU_LOOPCOUNT;
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* QAC Warning: START Msg(2:2814)-26 */
  MCU_PROTECTED_WRITE(&(Mcu_ClkCtrlReg_BaseAddress->ulMOSCE),
    MCU_LONG_WORD_ONE,
    &(Mcu_WriteProtReg_BaseAddress->ulPROTCMD0),
    &(Mcu_WriteProtReg_BaseAddress->ulPROTS0),
    LucCount, &LddReturnValue )
  /* END Msg(2:2814)-26 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

  if (E_NOT_OK == LddReturnValue)
  {
    /*
    * writing to write-protected register failed and
    * report production error
    */
    Dem_ReportErrorStatus(MCU_E_WRITE_TIMEOUT_FAILURE,
                            DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif

/*******************************************************************************
** Function Name      : Mcu_SequencerDiCmpValueSet
**
** Service ID         : 0x0F
**
** Description        : This API is used dynamic configuration of the
**                      sequencer in runtime
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ucDpinId , blDpinVal
**
** InOut Parameter    : None
**
** Output Parameters  : None
**
** Return Value       : Std_ReturnType
**
** Pre-condition      : None
**
** Global Variable(s) : Mcu_GblSeqDriverStatus
**
** Function(s) invoked: Det_ReportError,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : SOSTR, DPDSRH, DPDSRM, DPDSR0
**
*******************************************************************************/
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_147, MCU_ESDD_UD_154                               */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0075_FR_0105                                            */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* Implements: EAAR_PN0034_FR_0064                                            */
/* Implements: MCU015, MCU017, MCU166_Conf, ECUC_Mcu_00166                    */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_SequencerDiCmpValueSet
                                            ( uint8 ucDpinId, boolean blDpinVal)
/* END Msg(2:3227)-15 */
{
  Std_ReturnType LddReturnValue;
  uint8 LucDpinIdVal;
  LddReturnValue = E_OK;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  if (MCU_UNINITIALIZED == Mcu_GblSeqDriverStatus)
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
      MCU_SEQUENCERDICMPVALUESET_SID, MCU_E_UNINIT);
      LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Do Nothing */
  }
  /* Report to DET, if ucDpinId Id is out of range */
  if ( MCU_SEQUENCER_DPIN_ID < ucDpinId)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SEQUENCERDICMPVALUESET_SID, MCU_E_PARAM_SEQUENCER);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Report to DET, if blDpinVal Id is out of range */
  if ( MCU_ONE < blDpinVal)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_SEQUENCERDICMPVALUESET_SID, MCU_E_PARAM_SEQUENCER);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any development error occurred */
  if (E_OK == LddReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
   /* QAC Warning: START Msg(2:2814)-26 */
    /* Check whether LPS operation is in progress */
  if (MCU_ONE != (uint8)( (Mcu_LpsRegisters_BaseAddress->ucSOSTR) & MCU_ONE ))
  /* END Msg(2:2814)-26 */
    {
      /* LPS operation is Stopped */
      if ( MCU_DATA_SET_REGISTER > ucDpinId )
      {
        LucDpinIdVal = ucDpinId ;
        if ( MCU_ZERO == blDpinVal )
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Reset the bit number LucDpinId of Data Set Register 0 */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSR0) &
                                 (uint32)(~( (uint32)MCU_ONE << LucDpinIdVal))),
                                  &Mcu_GddLpsRegRamMirror.ulDPDSR0)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSR0) &
                                 (uint32)(~( (uint32)MCU_ONE << LucDpinIdVal))),
                                  MCU_DPD_MSK,
                                  MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
        else
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Set the bit number LucDpinId of Data Set Register 0 */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSR0) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  &Mcu_GddLpsRegRamMirror.ulDPDSR0)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_LpsRegisters_BaseAddress->ulDPDSR0,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSR0) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  MCU_DPD_MSK,
                                  MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
      }
      else if ( MCU_DPDSRH_OFFSET > ucDpinId )
      {
        LucDpinIdVal = ( ucDpinId - MCU_DATA_SET_REGISTER) ;
        if ( MCU_ZERO == blDpinVal )
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Reset the bit number LucDpinId of Data Set Register M */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                                ((Mcu_LpsRegisters_BaseAddress->ulDPDSRM) &
                                (uint32) (~( (uint32)MCU_ONE << LucDpinIdVal))),
                                &Mcu_GddLpsRegRamMirror.ulDPDSRM)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                &Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                                ((Mcu_LpsRegisters_BaseAddress->ulDPDSRM) &
                                (uint32) (~( (uint32)MCU_ONE << LucDpinIdVal))),
                                MCU_FULL_MSK,
                                MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
        else
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Set the bit number LucDpinId of Data Set Register M */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSRM) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  &Mcu_GddLpsRegRamMirror.ulDPDSRM)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_LpsRegisters_BaseAddress->ulDPDSRM,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSRM) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  MCU_FULL_MSK,
                                  MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
      }
      else
      {
        LucDpinIdVal =((uint8)(ucDpinId - MCU_DATA_SET_REGISTER)
                                                              - MCU_THIRTY_TWO);
        if ( MCU_ZERO == blDpinVal )
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Reset the bit number LucDpinId of Data Set Register H */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                                ((Mcu_LpsRegisters_BaseAddress->ulDPDSRH) &
                                (uint32) (~((uint32) MCU_ONE << LucDpinIdVal))),
                                &Mcu_GddLpsRegRamMirror.ulDPDSRH)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                &Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                                ((Mcu_LpsRegisters_BaseAddress->ulDPDSRH) &
                                (uint32) (~((uint32) MCU_ONE << LucDpinIdVal))),
                                MCU_DPD_MSK,
                                MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
        else
        {
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
          /* Set the bit number LucDpinId of Data Set Register H */
          MCU_WRITE_REG_AND_MIRROR(&Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSRH) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  &Mcu_GddLpsRegRamMirror.ulDPDSRH)
          MCU_CHECK_WRITE_VERIFY_RUNTIME(
                                  &Mcu_LpsRegisters_BaseAddress->ulDPDSRH,
                                  ((Mcu_LpsRegisters_BaseAddress->ulDPDSRH) |
                                  ( (uint32)MCU_ONE << LucDpinIdVal)),
                                  MCU_DPD_MSK,
                                  MCU_SEQUENCERDICMPVALUESET_SID)

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
          #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
        }
      }
    }
    else
    {
      /* LPS operation is enabled */
      LddReturnValue = E_NOT_OK;
    }
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Do Nothing */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */


/*******************************************************************************
** Function Name      : Mcu_WakeUpFactor_Preparation
**
** Service ID         : NA
**
** Description        : This service is used to clear and set Wakeup factors
**                      for power down mode
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : McuMode
**
** InOut Parameter    : None
**
** Output Parameters  : None
**
** Return Value       : void
**
** Pre-condition      : None
**
** Global Variable(s) : Mcu_GpConfigPtr, Mcu_GblWakeUpPreparation
**
** Function(s) invoked: MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : WUFMSK0, WUFMSK_ISO0, WUFMSK20, WUFMSK1, WUFC0,
**                      WUFC_ISO0, WUFC20, WUFC1, WUF0, WUF_ISO0, WUF20, WUF1
**
*******************************************************************************/
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: MCU_ESDD_UD_161, MCU_ESDD_UD_052                               */
/* Implements: EAAR_PN0075_FR_0094                                            */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030                       */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_WakeUpFactor_Preparation
                                                     (Mcu_ModeType McuMode)
/* END Msg(2:3227)-15 */
{
  P2CONST(Mcu_ModeSetting, MCU_VAR, MCU_CONFIG_CONST) LpModeSetting;
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  #if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
  /* QAC Warning: START Msg(2:2814)-26 */
  LpModeSetting = (P2CONST(Mcu_ModeSetting, MCU_VAR,
           MCU_CONFIG_CONST))&Mcu_GstModeSetting
             [(Mcu_GpConfigPtr->ucModeSettingOffset) + McuMode ];
  /* END Msg(2:2814)-26 */
  #else
  /* QAC Warning: START Msg(2:2814)-26 */
  LpModeSetting = (P2CONST(Mcu_ModeSetting, MCU_VAR,
           MCU_CONFIG_CONST))&Mcu_GstModeSetting
                  [(Mcu_GpConfigPtr->ucModeSettingOffset) +(McuMode - MCU_ONE)];
  /* END Msg(2:2814)-26 */
  #endif
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */
  /* QAC Warning: START Msg(2:2814)-26 */
  /* Mask all wake-up factor flag to avoid being miswritten when clear*/
  MCU_WRITE_REG_AND_MIRROR(&WufReg_BaseAddress->ulWUFMSK0,
                       MCU_WUF_MSK,
                       &Mcu_GddWufReg0RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUFMSK0,
                                   MCU_WUF_MSK,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_AND_MIRROR(&WufIsoReg_BaseAddress->ulWUFMSK0,
                       MCU_WUF_MSK,
                       &Mcu_GddWufRegIsoRamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUFMSK0,
                                   MCU_WUF_MSK,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_AND_MIRROR(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                       MCU_WUF_MSK,
                       &Mcu_GddWufReg20RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                                   MCU_WUF_MSK,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #if (MCU_WUF1_ENABLED == STD_ON)
  MCU_WRITE_REG_AND_MIRROR(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                       MCU_WUF_MSK,
                       &Mcu_GddWufReg10RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                                   MCU_WUF_MSK,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #endif
  #if (MCU_WUF_CENTRALISED_CLEARING == STD_ON)
  /* Clear wakeup factor registers */
  MCU_WRITE_REG_ONLY(&WufReg_BaseAddress->ulWUFC0,
                       (MCU_WUF_CLR_VALUE))
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUF0,
                                   MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_ONLY(&Wuf20Reg_BaseAddress->ulWUFC0,
                       (MCU_WUFC20_CLR_VALUE))
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUF0,
                                  MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_ONLY(&WufIsoReg_BaseAddress->ulWUFC0,
                       (MCU_WUFC_ISO0_CLR_VALUE))
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUF0,
                                   MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #if (MCU_WUF1_ENABLED == STD_ON)
  MCU_WRITE_REG_ONLY(&Wuf10Reg_BaseAddress->ulWUFC0,
                       (MCU_WUF1_CLR_VALUE))
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUF0,
                                   MCU_WUF0_RESET_VALUE,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #endif
  #endif /* (MCU_WUF_CENTRALISED_CLEARING == STD_ON) */
  /* Load wake-up factor register value */
  MCU_WRITE_REG_AND_MIRROR(&WufReg_BaseAddress->ulWUFMSK0,
                       LpModeSetting->ulPowerDownWakeupType0,
                       &Mcu_GddWufReg0RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufReg_BaseAddress->ulWUFMSK0,
                                   LpModeSetting->ulPowerDownWakeupType0,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_AND_MIRROR(&WufIsoReg_BaseAddress->ulWUFMSK0,
                       LpModeSetting->ulPowerDownWakeupTypeISO0,
                       &Mcu_GddWufRegIsoRamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&WufIsoReg_BaseAddress->ulWUFMSK0,
                                   LpModeSetting->ulPowerDownWakeupTypeISO0,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  MCU_WRITE_REG_AND_MIRROR(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                       LpModeSetting->ulPowerDownWakeupType2,
                       &Mcu_GddWufReg20RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf20Reg_BaseAddress->ulWUFMSK0,
                                   LpModeSetting->ulPowerDownWakeupType2,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #if (MCU_WUF1_ENABLED == STD_ON)
  MCU_WRITE_REG_AND_MIRROR(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                       LpModeSetting->ulPowerDownWakeupType1,
                       &Mcu_GddWufReg10RamMirror.ulWUFMSK0)
  MCU_CHECK_WRITE_VERIFY_RUNTIME(&Wuf10Reg_BaseAddress->ulWUFMSK0,
                                   LpModeSetting->ulPowerDownWakeupType1,
                                   MCU_WUF_MSK,
                                   MCU_WAKEUPFACTORPRE_API_ID)
  #endif
  /* END Msg(2:2814)-26 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_GblWakeUpPreparation = MCU_ONE;
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/*******************************************************************************
** Function Name      : Mcu_GetVersionInfo
**
** Service ID         : 0x09
**
** Description        : This service returns the version information of this
**                      module.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
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
** Function(s) invoked: Det_ReportError()
**
** Registers Used     : None

*******************************************************************************/
/* Implements: MCU168_Conf                                                    */
#if (MCU_VERSION_INFO_API == STD_ON)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: MCU_ESDD_UD_093                                                */
/* Implements: SWS_Mcu_00162                                                  */
/* Implements: MCU162, MCU103, MCU104, MCU149, MCU013                         */
/* Implements: MCU110, MCU162, MCU204, MCU152,MCU168_Conf                     */
/* Implements: SWS_Mcu_00103, SWS_Mcu_00104, SWS_Mcu_00110                    */
/* Implements: SWS_Mcu_00163, ECUC_Mcu_00168, SWS_Mcu_00152                   */
/* Implements: EAAR_PN0034_FR_0051                                            */
/* Implements: EAAR_PN0034_FR_0092                                            */
/* Implements: MCU_ESDD_UD_020                                                */
/* Implements: EAAR_PN0034_FR_0064                                            */
/* QAC Warning: START Msg(2:3227)-15 */
FUNC(void,MCU_PUBLIC_CODE) Mcu_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_CONST) versioninfo)
/* END Msg(2:3227)-15 */
{

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
 /* Report to DET, if versioninfo pointer is equal to Null */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                  MCU_GETVERSIONINFO_SID,MCU_E_PARAM_POINTER);
  }
  else
  #endif /*#if (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)MCU_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)MCU_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = MCU_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = MCU_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = MCU_SW_PATCH_VERSION;
  }
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif  /*(MCU_GET_VERSION_INFO_API == STD_ON)*/

/*******************************************************************************
** Function Name      : Mcu_CheckHWConsistency
**
** Service ID         : 0x10
**
** Description        : This API will execute registers ram mirroring check
**
** Sync/Async         : synchronous
**
** Reentrancy         : Non Re-entrant
**
** Input Parameters   : CheckType
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType - Returns E_OK if the registers values
**                      corresponds with their ram copy else returns E_NOT_OK
**                      if there is at least one mismatch.
**
** Preconditions      : Component must be initialized using Mcu_Init().
**
** Global Variable(s) : Ram Mirror Structures for HWCC
**
** Function(s) invoked: MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : DPDSRH, DPDSRM, DPDSR0, EVFR, SCTLR, CNTVAL, DPSELR0,
**                      DPSELRH, DPSELRM, CLMAnCMPH, CLMAnCMPL, CLMAnCTL0,
**                      WUFMSK0, WUFMSK_ISO0, WUFMSK20, WUFMSK1, FOUTDIV,
**                      MOSCST, MOSCC, MOSCSTPM, CKSC_xxxS_CTL, CKSC_xxxD_CTL,
**                      CKSC_xxxD_STPM, CKSC_xxxS_STPM, SOSCST, ROSCSTPM,
**                      PLLC/PLL1C, PLL0C, TAUJ0TPS, TAUJ0BRS, TAUJ0CDRm,
**                      TAUJ0CMOR, CYCRBASE,TAUJ0CDR, CKSC_xxxS_ACT
*******************************************************************************/
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implementation of Mcu_CheckHWConsistency API */

/* Implements: MCU_ESDD_UD_171, MCU_ESDD_UD_045, MCU_ESDD_UD_117              */
/* Implements: EAAR_PN0034_FSR_0007                                           */
/* Implements: EAAR_PN0034_FSR_0005, EAAR_PN0034_FSR_0006                     */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: MCU_ESDD_UD_172, MCU_ESDD_UD_118, MCU_ESDD_UD_119              */
/* Implements: MCU_ESDD_UD_024, MCU_ESDD_UD_026, MCU_ESDD_UD_025              */
/* Implements: MCU_ESDD_UD_122,MCU_ESDD_UD_123, MCU_ESDD_UD_183               */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_CheckHWConsistency(
                      const Mcu_HWConsistencyCheckType CheckType)
{
  /* Local variable to hold the return value of the function */
  Std_ReturnType LddReturnValue = E_OK;
  #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
  P2VAR(volatile TAUJChReg, AUTOMATIC, MCU_CONFIG_DATA) LpTaujChReg;
  P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST) LpSeqSetting;
  LpSeqSetting = Mcu_GpSeqSetting;
  #endif
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION)
  #endif /* #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && (MCU_TAUJ0_INIT == STD_ON))
  /* set the Timer channel for continuous conversion mode */
  LpTaujChReg = LpSeqSetting->pTAUJ0ChRegs;
  #endif
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Check if the MCU Module is not Initialized */
  if (MCU_UNINITIALIZED ==  Mcu_GblDriverStatus)
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                          MCU_HWCHECKCONSISTENCY_SID, MCU_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else
  #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    if (MCU_HW_CONSIST_CHECK_STATIC == CheckType)
    {
      #if (MCU_RETENTIONRAM_REQ == STD_ON)
      /* QAC Warning: START Msg(2:2814)-26 */
      if (Mcu_ResfRegister_BaseAddress->ulCYCRBASE
            != Mcu_GpConfigPtr->ulCyclicRunModeBaseAddress)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* END Msg(2:2814)-26 */
      #endif /* (MCU_RETENTIONRAM_REQ == STD_ON) */
    }
    else if (MCU_HW_CONSIST_CHECK_DYNAMIC == CheckType)
    {
      /* QAC Warning: START Msg(2:2814)-26 */
      #if (MCU_LOW_POWER_SEQUENCER == STD_ON)
      if ((Mcu_LpsRegisters_BaseAddress->ulDPDSR0
              != Mcu_GddLpsRegRamMirror.ulDPDSR0) ||
              (Mcu_LpsRegisters_BaseAddress->ulDPDSRM
              != Mcu_GddLpsRegRamMirror.ulDPDSRM) ||
              (Mcu_LpsRegisters_BaseAddress->ulDPDSRH
              != Mcu_GddLpsRegRamMirror.ulDPDSRH) ||
              (Mcu_LpsRegisters_BaseAddress->ulEVFR
              != Mcu_GddLpsRegRamMirror.ulEVFR) ||
              (Mcu_LpsRegisters_BaseAddress->ulSCTLR
              != Mcu_GddLpsRegRamMirror.ulSCTLR) ||
              (Mcu_LpsRegisters_BaseAddress->usCNTVAL
              != Mcu_GddLpsRegRamMirror.usCNTVAL))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */
      #if (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
      (MCU_DIGITAL_INPUT_MODE == STD_ON)
      if (Mcu_LpsRegisters_BaseAddress->ulDPSELR0
              != Mcu_GddLpsRegRamMirror.ulDPSELR0)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
            (MCU_DIGITAL_INPUT_MODE == STD_ON) */
      #if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
      (MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_M == STD_ON))
      if (Mcu_LpsRegisters_BaseAddress->ulDPSELRM
              != Mcu_GddLpsRegRamMirror.ulDPSELRM)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
      (MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_M == STD_ON)*/
      #if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
      (MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_H == STD_ON))
      if (Mcu_LpsRegisters_BaseAddress->ulDPSELRH
              != Mcu_GddLpsRegRamMirror.ulDPSELRH)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
      (MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_H == STD_ON) */
      #if (MCU_CLMA0_OPERATION == STD_ON)
      if ((Clma0Reg_BaseAddress->ulCMPH
              != Mcu_GddClkMntrReg0RamMirror.ulCMPH) ||
              (Clma0Reg_BaseAddress->ulCMPL
              != Mcu_GddClkMntrReg0RamMirror.ulCMPL) ||
              (Clma0Reg_BaseAddress->ucCTL0
              != Mcu_GddClkMntrReg0RamMirror.ucCTL0))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_CLMA0_OPERATION == STD_ON) */
      #if (MCU_CLMA1_OPERATION == STD_ON)
      if ((Clma1Reg_BaseAddress->ulCMPH
              != Mcu_GddClkMntrReg1RamMirror.ulCMPH) ||
              (Clma1Reg_BaseAddress->ulCMPL
              != Mcu_GddClkMntrReg1RamMirror.ulCMPL) ||
              (Clma1Reg_BaseAddress->ucCTL0
              != Mcu_GddClkMntrReg1RamMirror.ucCTL0))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_CLMA1_OPERATION == STD_ON) */
      #if ((MCU_CLMA2_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF))
      if ((Clma2Reg_BaseAddress->ulCMPH
              != Mcu_GddClkMntrReg2RamMirror.ulCMPH) ||
              (Clma2Reg_BaseAddress->ulCMPL
              != Mcu_GddClkMntrReg2RamMirror.ulCMPL) ||
              (Clma2Reg_BaseAddress->ucCTL0
              != Mcu_GddClkMntrReg2RamMirror.ucCTL0))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* ((MCU_CLMA2_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF)) */
      #if ((MCU_CLMA3_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF))
      if ((Clma3Reg_BaseAddress->ulCMPH
        != Mcu_GddClkMntrReg3RamMirror.ulCMPH) ||
        (Clma3Reg_BaseAddress->ulCMPL
        != Mcu_GddClkMntrReg3RamMirror.ulCMPL) ||
        (Clma3Reg_BaseAddress->ucCTL0
        != Mcu_GddClkMntrReg3RamMirror.ucCTL0))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* ((MCU_CLMA3_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF)) */
      #if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
          (MCU_TAUJ0_INIT == STD_ON) && (MCU_TAUJ0_PRESCALAR == STD_ON))
      if ((Mcu_Tauj0OsReg_BaseAddress->usTPS
              != Mcu_GddTaujOsRegRamMirror.usTPS) ||
              (Mcu_Tauj0OsReg_BaseAddress->ucBRS
              != Mcu_GddTaujOsRegRamMirror.ucBRS))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
          (MCU_TAUJ0_INIT == STD_ON) && (MCU_TAUJ0_PRESCALAR == STD_ON)) */
      #if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && (MCU_TAUJ0_INIT == STD_ON))
      if ((LpTaujChReg->usCMOR != Mcu_GddTaujChRegRamMirror.usCMOR) ||
          (LpTaujChReg->ulCDR != Mcu_GddTaujChRegRamMirror.ulCDR))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
            (MCU_TAUJ0_INIT == STD_ON)) */
      if ((WufReg_BaseAddress->ulWUFMSK0
              != Mcu_GddWufReg0RamMirror.ulWUFMSK0) ||
              (WufIsoReg_BaseAddress->ulWUFMSK0
              != Mcu_GddWufRegIsoRamMirror.ulWUFMSK0) ||
              (Wuf20Reg_BaseAddress->ulWUFMSK0
              != Mcu_GddWufReg20RamMirror.ulWUFMSK0)
      #if (MCU_WUF1_ENABLED == STD_ON)
              || (Wuf10Reg_BaseAddress->ulWUFMSK0
              != Mcu_GddWufReg10RamMirror.ulWUFMSK0)
      #endif
              )
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #if ((MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF))
      if (Mcu_ClkCtrlReg_BaseAddress->ulFOUTDIV
             != Mcu_GddClkCntlRegRamMirror.ulFOUTDIV)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)) */
      #if (MCU_MAINOSC_ENABLE == STD_ON)
      if ((Mcu_ClkCtrlReg_BaseAddress->ulMOSCC
              != Mcu_GddClkCntlRegRamMirror.ulMOSCC) ||
              (Mcu_ClkCtrlReg_BaseAddress->ulMOSCST
              != Mcu_GddClkCntlRegRamMirror.ulMOSCST) ||
              (Mcu_ClkCtrlReg_BaseAddress->ulMOSCSTPM
              != Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
      #if (MCU_SUBOSC_ENABLE == STD_ON)
      if (Mcu_ClkCtrlReg_BaseAddress->ulSOSCST
              != Mcu_GddClkCntlRegRamMirror.ulSOSCST)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_SUBOSC_ENABLE == STD_ON) */

      #if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
      if (Mcu_ClkCtrlReg_BaseAddress->ulROSCS
              != Mcu_GddClkCntlRegRamMirror.ulROSCS)
      {
        LddReturnValue = E_NOT_OK;
      }
      else if (Mcu_ClkCtrlReg_BaseAddress->ulROSCSTPM
              != Mcu_GddClkCntlRegRamMirror.ulROSCSTPM)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON) */
      #if (MCU_PLL_ENABLE == STD_ON)
      if ((Mcu_ClkCtrlReg_BaseAddress->ulPLLC
              != Mcu_GddClkCntlRegRamMirror.ulPLLC) ||
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLLIS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_PLLIS_CTL))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_PLL_ENABLE == STD_ON) */
      #if (MCU_PLL0_ENABLE == STD_ON)
      if ((Mcu_ClkCtrlReg_BaseAddress->ulPLL0C
        != Mcu_GddClkCntlRegRamMirror.ulPLL0C) ||
        (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PLL0IS_CTL
        != Mcu_GddClkCntlRegRamMirror.ulCKSC_PLL0IS_CTL))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /* (MCU_PLL0_ENABLE == STD_ON) */
      #if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)
      if (((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_STPM)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_STPM) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_STPM
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_STPM)))
      {
        LddReturnValue = E_NOT_OK;
      }
      else if (((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AWDTAD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKD_CTL)) ||
              #if (MCU_ISOADCA_SUPPORTED == STD_ON)
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAD_CTL)) ||
              #endif
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILIND_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANOSCD_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_CTL)))
      {
        LddReturnValue = E_NOT_OK;
      }
      else if (((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ATAUJS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ARTCAS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AADCAS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_AFOUTS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_CPUCLKS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_PPLLCLKS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_PPLLCLKS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_PPLLCLKS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI1S_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI1S_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI2S_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI2S_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ILINS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ILINS_CTL)) ||
              #if (MCU_ISOADCA_SUPPORTED == STD_ON)
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAS_CTL)) ||
              #endif
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_ICSIS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_CTL
              != Mcu_GddClkCntlRegRamMirror.ulCKSC_ICSIS_CTL)) ||
              ((MCU_CLK_CNTL_REG_RAM_MIRROR_INVALID !=
              Mcu_GddClkCntlRegRamMirror.ulCKSC_IIICS_CTL) &&
              (Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_CTL
               != Mcu_GddClkCntlRegRamMirror.ulCKSC_IIICS_CTL)))
      {
         LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }
      #endif /*(MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)) */
    /* END Msg(2:2814)-26 */
    }
    else
    {
      /* No action required */
    }
  }
  return(LddReturnValue);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PUBLIC_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */

/*******************************************************************************
** Function Name      : Mcu_InitRamMirror
**
** Service ID         : n/a
**
** Description        : This function will initialize the RAM mirror
**                      variables for the HW concistency check
** Sync/Async         : synchronous
**
** Reentrancy         : Non Re-entrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable(s) : Ram Mirror Structures for HWCC
**
** Function(s) invoked: None
**
** Registers Used     : None
**
*******************************************************************************/
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
/* Implements: MCU_ESDD_UD_187                                                */
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_InitRamMirror(void)
{

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)

Mcu_GddLpsRegRamMirror.ulDPDSR0 = MCU_DPDSR0_INIT_REG_VALUE;
Mcu_GddLpsRegRamMirror.ulDPDSRM = MCU_DPDSRM_INIT_REG_VALUE;
Mcu_GddLpsRegRamMirror.ulDPDSRH = MCU_DPDSRH_INIT_REG_VALUE;
Mcu_GddLpsRegRamMirror.ulEVFR = MCU_EVFR_INIT_REG_VALUE;
Mcu_GddLpsRegRamMirror.ulSCTLR = MCU_SCTLR_INIT_REG_VALUE;
Mcu_GddLpsRegRamMirror.usCNTVAL = MCU_CNTVAL_INIT_REG_VALUE;

#endif
#if (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
(MCU_DIGITAL_INPUT_MODE == STD_ON)

Mcu_GddLpsRegRamMirror.ulDPSELR0 = MCU_DPSELR0_INIT_REG_VALUE;

#endif

#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
(MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_M == STD_ON))

Mcu_GddLpsRegRamMirror.ulDPSELRM = MCU_DPSELRM_INIT_REG_VALUE;

#endif

#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
(MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_H == STD_ON))

Mcu_GddLpsRegRamMirror.ulDPSELRH = MCU_DPSELRH_INIT_REG_VALUE;

#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) && \
(MCU_DIGITAL_INPUT_MODE == STD_ON) && (MCU_DPIN_SEL_REG_H == STD_ON) */
#if (MCU_CLMA0_OPERATION == STD_ON)
Mcu_GddClkMntrReg0RamMirror.ulCMPH = MCU_CLMAnCMPH_INIT_REG_VALUE;
Mcu_GddClkMntrReg0RamMirror.ulCMPL = MCU_CLMAnCMPL_INIT_REG_VALUE;
Mcu_GddClkMntrReg0RamMirror.ucCTL0 = MCU_CLMAnCTL0_INIT_REG_VALUE;
#endif /* (MCU_CLMA0_OPERATION == STD_ON) */
#if (MCU_CLMA1_OPERATION == STD_ON)
Mcu_GddClkMntrReg1RamMirror.ulCMPH = MCU_CLMAnCMPH_INIT_REG_VALUE;
Mcu_GddClkMntrReg1RamMirror.ulCMPL = MCU_CLMAnCMPL_INIT_REG_VALUE;
Mcu_GddClkMntrReg1RamMirror.ucCTL0 = MCU_CLMAnCTL0_INIT_REG_VALUE;
#endif /* (MCU_CLMA1_OPERATION == STD_ON) */
#if ((MCU_CLMA2_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF))
Mcu_GddClkMntrReg2RamMirror.ulCMPH = MCU_CLMAnCMPH_INIT_REG_VALUE;
Mcu_GddClkMntrReg2RamMirror.ulCMPL = MCU_CLMAnCMPL_INIT_REG_VALUE;
Mcu_GddClkMntrReg2RamMirror.ucCTL0 = MCU_CLMAnCTL0_INIT_REG_VALUE;
#endif /* ((MCU_CLMA2_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF)) */
#if ((MCU_CLMA3_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF))
Mcu_GddClkMntrReg3RamMirror.ulCMPH = MCU_CLMAnCMPH_INIT_REG_VALUE;
Mcu_GddClkMntrReg3RamMirror.ulCMPL = MCU_CLMAnCMPL_INIT_REG_VALUE;
Mcu_GddClkMntrReg3RamMirror.ucCTL0 = MCU_CLMAnCTL0_INIT_REG_VALUE;
#endif /* ((MCU_CLMA3_OPERATION == STD_ON) && (MCU_NO_PLL == STD_OFF)) */
#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
         (MCU_TAUJ0_INIT == STD_ON) && (MCU_TAUJ0_PRESCALAR == STD_ON))
Mcu_GddTaujOsRegRamMirror.usTPS = MCU_TAUJnTPS_INIT_REG_VALUE;
Mcu_GddTaujOsRegRamMirror.ucBRS = MCU_TAUJnBRS_INIT_REG_VALUE;
#endif /* ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
          (MCU_TAUJ0_INIT == STD_ON) && (MCU_TAUJ0_PRESCALAR == STD_ON)) */
#if ((MCU_LOW_POWER_SEQUENCER == STD_ON) && (MCU_TAUJ0_INIT == STD_ON))
/* Initialize the variable with index of Mcu_GstSequencerSetting[MCU_ZERO] */
Mcu_GpSeqSetting = ((P2CONST(Mcu_SequencerSetting, MCU_VAR,MCU_CONFIG_CONST))
                             (&Mcu_GstSequencerSetting[MCU_ZERO]));
Mcu_GddTaujChRegRamMirror.usCMOR = MCU_TAUJnCMOR_INIT_REG_VALUE;
Mcu_GddTaujChRegRamMirror.ulCDR = MCU_TAUJnCDR_INIT_REG_VALUE;
#endif /* ((MCU_LOW_POWER_SEQUENCER == STD_ON) && \
            (MCU_TAUJ0_INIT == STD_ON)) */
Mcu_GddWufReg0RamMirror.ulWUFMSK0 = MCU_WUFMSK_INIT_REG_VALUE;
Mcu_GddWufRegIsoRamMirror.ulWUFMSK0 = MCU_WUFMSK_INIT_REG_VALUE;
Mcu_GddWufReg20RamMirror.ulWUFMSK0 = MCU_WUFMSK_INIT_REG_VALUE;
#if (MCU_WUF1_ENABLED == STD_ON)
Mcu_GddWufReg10RamMirror.ulWUFMSK0 = MCU_WUFMSK_INIT_REG_VALUE;
#endif

#if ((MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF))
Mcu_GddClkCntlRegRamMirror.ulFOUTDIV = MCU_FOUTDIV_INIT_REG_VALUE;
#endif /* (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)) */

#if (MCU_MAINOSC_ENABLE == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulMOSCC = MCU_MOSCC_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulMOSCST = MCU_MOSCST_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulMOSCSTPM = MCU_MOSCSTPM_INIT_REG_VALUE;
#endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
#if (MCU_SUBOSC_ENABLE == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulSOSCST = MCU_SOSCST_INIT_REG_VALUE;
#endif /* (MCU_SUBOSC_ENABLE == STD_ON) */

#if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulROSCS = MCU_ROSCS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulROSCSTPM = MCU_ROSCSTPM_INIT_REG_VALUE;
#endif /* (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON) */
#if (MCU_PLL_ENABLE == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulPLLC = MCU_PLLC_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_PLLIS_CTL = MCU_PLLIS_INIT_REG_VALUE;
#endif /* (MCU_PLL_ENABLE == STD_ON) */
#if (MCU_PLL0_ENABLE == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulPLL0C = MCU_PLL0C_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_PLL0IS_CTL = MCU_PLLIS_INIT_REG_VALUE;
#endif /* (MCU_PLL0_ENABLE == STD_ON) */
#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)
Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_STPM = MCU_STPM_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AWDTAD_CTL = MCU_AWDTAD_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJD_CTL = MCU_ATAUJD_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAD_CTL = MCU_ARTCAD_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAD_CTL = MCU_AADCAD_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKD_CTL = MCU_CPUCLKD_INIT_REG_VALUE;
#if (MCU_ISOADCA_SUPPORTED == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAD_CTL = MCU_IADCAD_INIT_REG_VALUE;
#endif
Mcu_GddClkCntlRegRamMirror.ulCKSC_ILIND_CTL = MCU_ILIND_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANOSCD_CTL = MCU_ICANOSCD_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ATAUJS_CTL = MCU_ATAUJS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ARTCAS_CTL = MCU_ARTCAS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AADCAS_CTL = MCU_AADCAS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_AFOUTS_CTL = MCU_AFOUTS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_CPUCLKS_CTL = MCU_CPUCLKS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_PPLLCLKS_CTL = MCU_PPLLCLKS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI1S_CTL = MCU_IPERI1S_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_IPERI2S_CTL = MCU_IPERI2S_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ILINS_CTL = MCU_ILINS_INIT_REG_VALUE;
#if (MCU_ISOADCA_SUPPORTED == STD_ON)
Mcu_GddClkCntlRegRamMirror.ulCKSC_IADCAS_CTL = MCU_IADCAS_INIT_REG_VALUE;
#endif
Mcu_GddClkCntlRegRamMirror.ulCKSC_ICANS_CTL = MCU_ICANS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_ICSIS_CTL = MCU_ICSIS_INIT_REG_VALUE;
Mcu_GddClkCntlRegRamMirror.ulCKSC_IIICS_CTL = MCU_IIICS_INIT_REG_VALUE;
#endif /*(MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)) */
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */
#endif /* (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */



/******************************************************************************
** Function Name      : Mcu_IsoCkscCheck
**
** Service ID         : None
**
** Description        : This service Check whether the default clock source of
**                      ISO clock which not configured from generator is 
**                      PPLLCLK.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ucCkscRegs, blPllActiveCheck
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpCkscSetting
**
** Function Invoked   : None
**
** Registers Used     : CKSC_xxxS_CTL
**
******************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF)
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_START_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

/* Implements: MCU_ESDD_UD_101                                                */
/* Implements: MCU156, MCU140, MCU141, MCU056, MCU142, MCU188_Conf            */
/* Implements: SWS_Mcu_0015, SWS_Mcu_00140, SWS_Mcu_00141, ECUC_Mcu_00188     */
/* Implements: SWS_Mcu_00056, SWS_Mcu_00142, SWS_Mcu_00205                    */
/* Implements: SWS_Mcu_00163, SWS_Mcu_00051, SWS_Mcu_00226                    */
/* Implements: SWS_Mcu_00152                                                  */
/* Implements: EAAR_PN0034_FR_0018, EAAR_PN0075_FR_0016                       */
/* Implements: EAAR_PN0075_FR_0017, EAAR_PN0075_FR_0086                       */
/* Implements: MCU_ESDD_UD_183                                                */
/* Implements: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030, EAAR_PN0075_FR_0019  */
/* Implements: EAAR_PN0034_FR_0049                                            */
/* Implements: SWS_Mcu_00257, SWS_Mcu_00258, SWS_Mcu_00152                    */
/* QAC Warning: START Msg(2:3227)-15 */
STATIC FUNC(boolean, MCU_PRIVATE_CODE)Mcu_IsoCkscCheck(uint8 ucCkscRegs,
boolean blPllActiveCheck)
/* END Msg(2:3227)-15 */
{
  P2CONST(Mcu_CkscSetting, AUTOMATIC, MCU_CONFIG_CONST) LpCkscSetting;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpVal;
  boolean blPllActiveFlag;
  uint8 LucCkscCheckBit;
  uint8 LucCkscCheckVal;
  uint8 LucIndex;
  uint8 LucNoOfCkscReg;
  uint32 LulValue;

  /* MISRA Violation: START Msg(4:2982)-5 */
  LpVal = NULL_PTR;
  /* END Msg(4:2982)-5 */
  blPllActiveFlag = MCU_FALSE;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LucCkscCheckBit = MCU_ZERO;
  /* END Msg(4:2982)-5 */
  LucCkscCheckVal = MCU_IOS_CLK_CHK_MASK;
  LucNoOfCkscReg = ucCkscRegs;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LulValue = MCU_CLOCK_DEFAULT;
  /* END Msg(4:2982)-5 */

  LpCkscSetting = Mcu_GpCkscSetting;

  if (blPllActiveCheck == MCU_FALSE)
  {
    while (MCU_ZERO < LucNoOfCkscReg)
    {
      /* Find ios clock which not configured by generator */
      /* QAC Warning: START Msg(2:2814)-26 */
      switch (LpCkscSetting->ucCkscSourceSelRegNum)
      /* END Msg(2:2814)-26 */
      {
      case MCU_REG_CKSC_IPERI1S_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT0)));
        break;
      case MCU_REG_CKSC_IPERI2S_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT1)));
        break;
      case MCU_REG_CKSC_ILINS_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT2)));
        break;
      case MCU_REG_CKSC_IADCAS_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT3)));
        break;
      case MCU_REG_CKSC_ICANS_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT4)));
        break;
      case MCU_REG_CKSC_ICSIS_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT5)));
        break;
      case MCU_REG_CKSC_IIICS_CTL:
        LucCkscCheckVal = (LucCkscCheckVal & ((uint8)(~MCU_UINT8_BIT6)));
        break;
      /* QAC Warning: START Msg(2:2016)-28 */
      default:
        /*No Action*/
        break;
      }
      /* END Msg(2:2016)-28 */
      /* MISRA Violation: START Msg(4:0489)-2 */
      LpCkscSetting++;
      /* END Msg(4:0489)-2 */
      /* Decrement number of CKSC registers */
      LucNoOfCkscReg--;
    }

    for (LucIndex = MCU_ZERO ;LucIndex < MCU_IOS_CLK_CHK_COUNT; LucIndex++)
    {
      LucCkscCheckBit = LucCkscCheckVal & ((uint8)(MCU_UINT8_BIT0 << LucIndex));
      switch (LucCkscCheckBit)
      {
      case MCU_UINT8_BIT0:
        /* Check the clock source of C_ISO_PERI1 is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI1S_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_ONE) || (LulValue == MCU_LONG_WORD_TWO))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      case MCU_UINT8_BIT1:
        /* Check the clock source of C_ISO_PERI2 is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IPERI2S_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_ONE) || (LulValue == MCU_LONG_WORD_TWO))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      case MCU_UINT8_BIT2:
        /* Check the clock source of C_ISO_LIN is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ILINS_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_ONE) ||
           (LulValue == MCU_LONG_WORD_THREE))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      #if (MCU_ISOADCA_SUPPORTED == STD_ON)
      case MCU_UINT8_BIT3:
        /* Check the clock source of C_ISO_ADCA is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IADCAS_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if (LulValue == MCU_LONG_WORD_THREE)
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      #endif
      case MCU_UINT8_BIT4:
        /* Check the clock source of C_ISO_CAN is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICANS_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_TWO) ||
          (LulValue == MCU_LONG_WORD_THREE))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      case MCU_UINT8_BIT5:
        /* Check the clock source of C_ISO_CSI is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_ICSIS_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_ONE) || (LulValue == MCU_LONG_WORD_TWO))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      case MCU_UINT8_BIT6:
        /* Check the clock source of C_ISO_IIC is not PPLLCLK */
        /* QAC Warning: START Msg(2:2814)-26 */
        LpVal = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
               &Mcu_ClkCtrlReg_BaseAddress->ulCKSC_IIICS_CTL;
        LulValue = (uint32)(*LpVal);
        /* END Msg(2:2814)-26 */
        if ((LulValue == MCU_LONG_WORD_ONE) || (LulValue == MCU_LONG_WORD_TWO))
        {
          blPllActiveFlag = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }
        break;
      /* QAC Warning: START Msg(2:2016)-28 */
      default:
        /*No Action*/
        break;
      }
      /* END Msg(2:2016)-28 */
    }
  }
  else
  {
    blPllActiveFlag = MCU_TRUE;
  }

  return(blPllActiveFlag);
}
/* QAC Warning: START Msg(2:0832)-14 */
#define MCU_STOP_SEC_PRIVATE_CODE
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-14 */

#endif /* (MCU_INIT_CLOCK == STD_ON) || (MCU_NO_PLL == STD_OFF) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
