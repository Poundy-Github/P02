/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  01-Sep-2015 : Initial Version
 * V1.1.0:  31-Jan-2017 : Memmap switch added.(Ref: JIRA ARDAABD-989)
 * V1.2.0:  07-Feb-2017 : Memmap switch replaced by definition export.
 *                        (Ref: JIRA ARDAABD-989)
 * V2.2.1:  05-May-2018 : Implemented generation of Precompile option
 *                        MCU_MAX_MODE_SET (Ref: JIRA ARDAABD-1853).
 * V2.2.2:  23-Jul-2019 : Implemented generation of Precompile option
 *                        MCU_F1KH_D8_DEVICE in Mcu_cfg.h
 *                        (Ref: JIRA ARDAABD-4061)
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.2.3
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\gw00188717\AppData\Local\Temp\DaVinci\Cfg-4917656\Generation\Cfg_Gen-1605096762847-0\AutosarFiles_ValGen7440281106118928693\ExtGen_DrvMcu_ECUC_4.2.2_8187792819286136148.arxml
 *                D:\SVN_Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\mcu\generator\R422_MCU_F1x_BSWMDT.arxml
 * GENERATED ON:  11 Nov 2020 - 20:17:59
 */


#ifndef MCU_CFG_H
#define MCU_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_CFG_AR_RELEASE_MINOR_VERSION  2U
#define MCU_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define MCU_CFG_SW_MAJOR_VERSION  1U
#define MCU_CFG_SW_MINOR_VERSION  2U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define MCU_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define MCU_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define MCU_AR_RELEASE_REVISION_VERSION_VALUE 2U

#define MCU_SW_MAJOR_VERSION_VALUE          1U
#define MCU_SW_MINOR_VERSION_VALUE          2U
#define MCU_SW_PATCH_VERSION_VALUE          4U

#define MCU_VENDOR_ID_VALUE                 59U
#define MCU_MODULE_ID_VALUE                 101U



/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the MCU Driver */
#define MCU_INSTANCE_ID_VALUE               0U

#define MCU_MEMMAP_FILE                     "Mcu_MemMap.h"

/* Pre-compile option for Version information  */
#define MCU_AR_VERSION                      MCU_AR_HIGHER_VERSION

/* Pre-compile option for the development error detection and reporting */
#define MCU_DEV_ERROR_DETECT                STD_ON

/* Pre-compile option for Mcu_GetVersion API */
#define MCU_VERSION_INFO_API                STD_OFF

/* Pre-compile option for Mcu_PerformReset API */
#define MCU_PERFORM_RESET_API               STD_ON

/* Pre-compile option for the critical section functionality */
#define MCU_CRITICAL_SECTION_PROTECTION     STD_OFF

/* Pre-compile option for the store-restore feature of port pin status */
#define MCU_PORTGROUP_STATUS_BACKUP         STD_OFF

/* Pre-compile option for the low power sequencer */
#define MCU_LOW_POWER_SEQUENCER             STD_OFF

/* Pre-compile option for the Digital Input mode selection */
#define MCU_DIGITAL_INPUT_MODE              STD_OFF

/* Pre-compile option for Digital input selection with multiplexer for DPIN select register M */
#define MCU_DPIN_SEL_REG_M                  STD_OFF

/* Pre-compile option for Digital input selection with multiplexer for DPIN select register H  */
#define MCU_DPIN_SEL_REG_H                  STD_OFF

/* Pre-compile option for the MainOsc */
#define MCU_MAINOSC_ENABLE                  STD_ON

/* Pre-compile option for the SubOsc */
#define MCU_SUBOSC_ENABLE                   STD_ON

/* Pre-compile option for the High Speed IntOsc */
#define MCU_HIGHSPEED_RINGOSC_ENABLE        STD_ON

/* Pre-compile option for the PLL */
#define MCU_PLL_ENABLE                      STD_ON

/* Pre-compile option for availability of CLMA0 */
#define MCU_CLMA0_OPERATION                 STD_ON

/* Pre-compile option for availability of CLMA1 */
#define MCU_CLMA1_OPERATION                 STD_ON

/* Pre-compile option for availability of CLMA2 */
#define MCU_CLMA2_OPERATION                 STD_OFF

/* Pre-compile option for availability of CLMA3 */
#define MCU_CLMA3_OPERATION                 STD_OFF

/* Pre-compile option for enable or disable inter-module dependencies */
#define MCU_VERSION_CHECK_EXT_MODULES       STD_OFF

/* Pre-compile option for availability of LVI0 Interrupt */
#define MCU_LVI0_ISR                        STD_OFF

/* Pre-compile option for Mcu_GetRamState API */
#define MCU_GET_RAM_STATE_API               STD_ON

/* Pre-compile option for Mcu_InitClock API */
#define MCU_INIT_CLOCK                      STD_ON

/* Pre-compile option for availability of PLL */
#define MCU_NO_PLL                          STD_OFF

/* Pre-compile option for Cyclic power modes */
#define MCU_RETENTIONRAM_REQ                STD_OFF

/* Pre-compile option for copy to section */
#define MCU_COPY_TO_SECTION_API             STD_ON

/* Pre-compile option for MCU_RESET_CALLOUT API */
#define MCU_SW_RESET_CALL_API               STD_OFF

/*  Pre-compile option for TAUJ0 Prescalar selection as part of sequnecer  */
#define MCU_TAUJ0_PRESCALAR                 STD_OFF

/*  Pre-compile option for TAUJ0 initialization as part ofsequencer  */
#define MCU_TAUJ0_INIT                      STD_OFF

/*  Index for notification function */
#define MCU_NOTIFICATION_INDEX              (uint8)0x00

/* Loop Count Value for the MCULOOPCOUNT */
#define MCU_LOOPCOUNT                       (uint8)5

/* Pre-Compile option for enabling INTCWEND */
#define MCU_INTCWEND_ISR_ENABLE             STD_OFF

/* Pre-Compile option for centralised clearing of all wake-up event  */
#define MCU_WUF_CENTRALISED_CLEARING        STD_ON

/* Pre-Compile option for Wakeup Factor */
#define MCU_WUF_CLEARISR                    STD_ON

/* Address for the McuRetentionRamSourceAddress */
#define MCU_RETENTION_RAM_SOURCE_ADDRESS    (uint32)65536

/* Check for high voltage detection enable bit */
#define MCU_CVM_HIGH_VOLTAGE_DETECT         STD_OFF

/* Check for low voltage detection enable bit */
#define MCU_CVM_LOW_VOLTAGE_DETECT          STD_OFF

/* Check for multiple reset reason enable bit */
#define MCU_RESET_REASON_MULTIPLE_RESETS    STD_ON

/* Enables/Disables registers write verify
   MCU_WV_DISABLE                  0 
   MCU_WV_INIT_ONLY                1 
   MCU_WV_INIT_RUNTIME             2 */
#define MCU_WRITE_VERIFY                    0x00U

/* Enable/Disable RAM Mirror for register */
#define MCU_RAM_MIRROR                      MCU_MIRROR_DISABLE

/* Enable/Disable the usage of write verify error notification */
#define MCU_USE_WV_ERROR_INTERFACE          STD_OFF

/* Maximum number of Clock setting */
#define MCU_MAX_CLK_SET                     0x01U

/* Total count of MCU mode setting configured */
#define MCU_MAX_MODE_SET                    0x02U

/* Precompile option for PLL0 Unit */
#define MCU_PLL0_ENABLE                     STD_ON

/* Enable/Disable wakeup factor 1 register */
#define MCU_WUF1_ENABLED                    STD_ON

/* Enable/Disable availability of support for IsoAdca */
#define MCU_ISOADCA_SUPPORTED               STD_ON

/* Enable/Disable reset factor CLMA3 */
#define MCU_CLM3_RESET_ENABLE               STD_ON

/* Precompile option for F1KM-S4 setting */
#define MCU_F1KM_S4_DEVICE                  STD_ON

/* Precompile option for F1KH-D8 setting */
#define MCU_F1KH_D8_DEVICE                  STD_OFF

/* WUF clear value */
#define MCU_WUF_CLR_VALUE                   (uint32)0xFFFFFFE7UL

/* WUF1 clear value */
#define MCU_WUF1_CLR_VALUE                  (uint32)0x00000FFFUL

/* WUF20 clear value */
#define MCU_WUFC20_CLR_VALUE                (uint32)0x003FFFFFUL

/* WUFISO clear value */
#define MCU_WUFC_ISO0_CLR_VALUE             (uint32)0x00000DFEUL

/* Maximum number of sequencer set */
#define MCU_MAX_SEQ_SET                     (uint8)0x01

/* 
 * The failure in stabilization of Clock sources and failure in 
 * switching of clock sources for clock domains is reported to DEM
 */
#define MCU_E_CLOCK_FAILURE                 \
  DemConf_DemEventParameter_AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE

/* The failure of writing to write-protected register is reported to DEM */
#define MCU_E_WRITE_TIMEOUT_FAILURE         \
  DemConf_DemEventParameter_AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE

/* The failure of LVI, in interrupt mode of operation is reported to DEM */
#define MCU_E_LVI_FAILURE                   \
  DemConf_DemEventParameter_AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE

/* The failure of CVM setting, in core voltage monitor is reported to DEM */
#define MCU_E_CVM_SETTING_FAILURE           \
  DemConf_DemEventParameter_AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE

/* The inconcistency between RESF and RESER is reported to DEM */
#define MCU_E_INCONCISTENCY_RESF_FAILURE    \
  DemConf_DemEventParameter_AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE




/* Macro for wakeup factor */
#define MCU_ICCWEND_WAKEUP_FACTOR_CLR    (uint32)0x80000

/* Macro for LPS */
#define MCU_ICCWEND_ACTIVATION    (uint16)0xFFFEUL

/* Pre-compile option for the PLL1 */
#define MCU_PLL1_ENABLE           STD_OFF



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Maximum number of RAM Settings */
#define MCU_MAX_RAMSETTING                  (Mcu_RamSectionType)1

/* Handles for RAM sector setting */
#define MCU_RAM_SETTING_0                   (Mcu_RamSectionType)0

/* Configuration Set Handles */
#define McuModuleConfiguration              (&Mcu_GstConfiguration[0])

/* Clock Configuration Handles */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig (Mcu_ClockType)0x00

/* Mode Setting Handles */
#define McuConf_McuModeSettingConf_McuModeSettingConf_normal (Mcu_ModeType)0x00
#define McuConf_McuModeSettingConf_McuModeSettingConf_lvi (Mcu_ModeType)0x01

/* Reset Reason Handles */
#define McuConf_McuResetReasonConf_McuResetReasonConfSwRst (Mcu_ResetType)0x01
#define McuConf_McuResetReasonConf_McuResetReasonConfWdta0 (Mcu_ResetType)0x02
#define McuConf_McuResetReasonConf_McuResetReasonConfWdta1 (Mcu_ResetType)0x03
#define McuConf_McuResetReasonConf_McuResetReasonConfWakeup (Mcu_ResetType)0x0B
#define McuConf_McuResetReasonConf_McuResetReasonConfLvi (Mcu_ResetType)0x07
#define McuConf_McuResetReasonConf_McuResetReasonConfPOR (Mcu_ResetType)0x0A
#define McuConf_McuRstRsnConfSwRst_McuRstRsnConfSwRst (Mcu_ResetType)0x01
#define McuConf_McuRstRsnConfWdta0_McuRstRsnConfWdta0 (Mcu_ResetType)0x02
#define McuConf_McuRstRsnConfWdta1_McuRstRsnConfWdta1 (Mcu_ResetType)0x03
#define McuConf_McuRstRsnConfClm0_McuRstRsnConfClm0 (Mcu_ResetType)0x04
#define McuConf_McuRstRsnConfClm1_McuRstRsnConfClm1 (Mcu_ResetType)0x05
#define McuConf_McuRstRsnConfClm2_McuRstRsnConfClm2 (Mcu_ResetType)0x06
#define McuConf_McuRstRsnConfLvi_McuRstRsnConfLvi (Mcu_ResetType)0x07
#define McuConf_McuRstRsnConfCvm_McuRstRsnConfCvm (Mcu_ResetType)0x08
#define McuConf_McuRstRsnConfTer_McuRstRsnConfTer (Mcu_ResetType)0x09
#define McuConf_McuRstRsnConfPOR_McuRstRsnConfPOR (Mcu_ResetType)0x0A
#define McuConf_McuRstRsnConfIso_McuRstRsnConfIso (Mcu_ResetType)0x0B
#define McuConf_McuRstRsnConfResf11_McuRstRsnConfResf11 (Mcu_ResetType)0x0C
#define McuConf_McuRstRsnConfResf12_McuRstRsnConfResf12 (Mcu_ResetType)0x0D
#define McuConf_McuRstRsnConfResf13_McuRstRsnConfResf13 (Mcu_ResetType)0x0E
#define McuConf_McuRstRsnConfClm3_McuRstRsnConfClm3 (Mcu_ResetType)0x0F
#define McuConf_McuRstRsnConfUndef_McuRstRsnConfUndef (Mcu_ResetType)0x10
#define McuConf_McuRstRsnConfMultipleResets_McuRstRsnConfMultipleResets (Mcu_ResetType)0x11
#define McuConf_McuRstRsnConfUnknown_McuRstRsnConfUnknown (Mcu_ResetType)0x12







/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/




/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
