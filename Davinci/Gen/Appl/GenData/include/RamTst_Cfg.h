/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Cfg.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 - 2017 Renesas Electronics Corporation                   */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  09-Oct-2013  : Initial Version
 * V1.0.1:  17-Feb-2014  : As per CR 076 for mantis #18116, Tool version
 *                         updated for merge activity.
 * V1.0.2:  14-Apr-2014  : As per CR 463, Macro
 *                         RAMTST_CRITICAL_SECTION_PROTECTION is added.
 * V1.0.3:  08-May-2014  : As per CR 505, Unwanted new line at EOF removed.
 * V1.0.4:  17-Jun-2014  : As per CR 531, Macros RAMTST_READBACK_OPTION
 *                         and RAMTST_E_READBACK_FAILURE are added.
 * V1.0.5:  11-Sep-2014 :  As per CR 009 and mantis #19850, following changes
 *                         are made:
 *                         1. Changes are made at all relevant places
 *                            accordingly to append U or ULafter numeric values.
 *                         2. RAMTST_VERSION_CHECK_EXT_MODULES macro is added
 *                            newly.
 * V1.0.6:  13-Feb-2015 :  As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 * V1.1.0:  19-Oct-2016 :  Module version updated to 1.2.0. (ARDAABC-901)
 * V1.1.1:  24-Oct-2016 :  MISRA violation block added (ARDAABC-917)
 * V2.0.0:  07-Nov-2016 :  As part of ARDAABC-939 the following changes made
 *                         1. Added RAMTST_AR_HIGER/LOWER_VERSION macros
 *                         2. Added RAMTST_MEMMAP_FILE macro
 * V2.0.1:  03-Dec-2016 :  As part of ARDAABC-571 the following changes made
 *                         1. Traceability tags updated according to AR4.2.2
 *                            format
 * V2.0.2:  16-Jun-2017 :  As part of F1KM support implementation,
 *                         RAMTST_GLOBAL_RAM precompile switch has been added
 *                         and macros for Global RAM test control registers.
 * V2.0.3:  26-Sep-2017 :  As part of ARDAABD-2319, the precompile switch
 *                         RAMTST_NON_DESTRUCTIVE_POLICY has been added.
 *                         As part of ARDAABD-2252, callout function for
 *                         Write-Verify handler mechanism is removed. Also
 *                         removed the QAC comment related to WV interface.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.6
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-7459765\Generation\Cfg_Gen-1611131101098-0\AutosarFiles_ValGen173292231004072736\ExtGen_DrvRamTst_ECUC_4.2.2_8146757055081404526.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\ramtst\generator\R422_RAMTST_F1x_BSWMDT.arxml
 * GENERATED ON:  20 Jan 2021 - 19:11:55
 */

#ifndef RAMTST_CFG_H
#define RAMTST_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define RAMTST_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define RAMTST_CFG_AR_RELEASE_MINOR_VERSION  2U
#define RAMTST_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define RAMTST_CFG_SW_MAJOR_VERSION  2U
#define RAMTST_CFG_SW_MINOR_VERSION  1U


/*******************************************************************************
**       To support different AUTOSAR releases in a single package            **
*******************************************************************************/
#define RAMTST_AR_FOUR_ZERO_THREE 403
#define RAMTST_AR_FOUR_TWO_TWO    422

#define RAMTST_AR_HIGHER_VERSION  RAMTST_AR_FOUR_TWO_TWO
#define RAMTST_AR_LOWER_VERSION   RAMTST_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

/* Implements RamTst080 */
/* Implements SWS_RamTst_00080 */
/* Implements RamTst114 */
/* Implements SWS_RamTst_00114 */
#define RAMTST_AR_RELEASE_MAJOR_VERSION_VALUE         4U
#define RAMTST_AR_RELEASE_MINOR_VERSION_VALUE         2U
#define RAMTST_AR_RELEASE_REVISION_VERSION_VALUE      2U

#define RAMTST_SW_MAJOR_VERSION_VALUE                 2U
#define RAMTST_SW_MINOR_VERSION_VALUE                 1U
#define RAMTST_SW_PATCH_VERSION_VALUE                 3U

#define RAMTST_VENDOR_ID_VALUE                        59U
#define RAMTST_MODULE_ID_VALUE                        93U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Instance ID of the RAMTST Driver*/
#define RAMTST_INSTANCE_ID_VALUE                      (uint8)0

/* Pre-compile option for Version information */
#define RAMTST_AR_VERSION                             RAMTST_AR_HIGHER_VERSION

/* Implements RamTst120_Conf */
/* Implements ECUC_RamTst_00120 */
/* Implements SWS_BSW_00183 */
/* Enables/Disables RamTstAllow API */
#define RAMTST_ALLOW_API                              STD_ON

/* Implements RamTst118_Conf */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstChangeNumOfTestedCells API */
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API      STD_ON

/* Implements RamTst121_Conf */
/* Implements ECUC_RamTst_00121 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable Development Error Detection */
#define RAMTST_DEV_ERROR_DETECT                       STD_ON

/* Pre-compile option for the critical section functionality */
#define RAMTST_CRITICAL_SECTION_PROTECTION            STD_ON

/* Implements RamTst183_Conf */
/* Implements ECUC_RamTst_00183 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstGetAlgParams API */
#define RAMTST_GET_ALG_PARAMS_API                     STD_ON

/* Implements RamTst122_Conf */
/* Implements ECUC_RamTst_00122 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstGetExecutionStatus API */
#define RAMTST_GET_EXECUTION_STATUS_API               STD_ON

/* Implements RamTst123_Conf */
/* Implements ECUC_RamTst_00123 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstGetNumberOfTestedCells API */
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API         STD_ON

/* Implements RamTst124_Conf */
/* Implements ECUC_RamTst_00124 */
/* Implements SWS_BSW_00183 */
/* Enable/disable RamTstGetTestAlgorithm API */
#define RAMTST_GET_TEST_ALGORITHM_API                 STD_ON

/* Implements RamTst125_Conf */
/* Implements ECUC_RamTst_00125 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstGetTestResult API */
#define RAMTST_GET_TEST_RESULT_API                    STD_ON

/* Implements RamTst126_Conf */
/* Implements ECUC_RamTst_00126 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstGetTestResultPerBlock API */
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_API          STD_ON

/* Implements RamTst128_Conf */
/* Implements ECUC_RamTst_00128 */
/* Implements SWS_BSW_00052 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstGetVersionInfo API */
#define RAMTST_GET_VERSION_INFO_API                   STD_ON

/* Implements RamTst155_Conf */
/* Implements ECUC_RamTst_00155 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstResume API */
#define RAMTST_RESUME_API                             STD_ON

/* Implements RamTst184_Conf */
/* Implements ECUC_RamTst_00184 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstRunFullTest API */
#define RAMTST_RUN_FULL_TEST_API                      STD_ON

/* Implements RamTst185_Conf */
/* Implements ECUC_RamTst_00185 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstRunPartialTest API */
#define RAMTST_RUN_PARTIAL_TEST_API                   STD_ON

/* Implements RamTst182_Conf */
/* Implements ECUC_RamTst_00182 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable RamTstSelectAlgParams API */
#define RAMTST_SELECT_ALG_PARAMS_API                  STD_ON

/* Implements RamTst127_Conf */
/* Implements ECUC_RamTst_00127 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstStop API */
#define RAMTST_STOP_API                               STD_ON

/* Implements RamTst156_Conf */
/* Implements ECUC_RamTst_00156 */
/* Implements SWS_BSW_00183 */
/* Enable/Disable the RamTstSuspend API */
#define RAMTST_SUSPEND_API                            STD_ON

/* Implements SWS_BSW_00183 */
/* Pre-compile option for enable or disable version check of inter-module */
/* dependencies */
#define RAMTST_VERSION_CHECK_EXT_MODULES              STD_OFF

/* Disable/Enable read verify ECC registers of RAM */
#define RAMTST_ECC_CHECK                              STD_ON


/* Enable/Disable RAM test algorithms supported */
/* Implements RamTst129_Conf */
/* Implements ECUC_RamTst_00129 */
/* Implements SWS_BSW_00183 */
/* Select Abraham Test Algorithm */
#define RAMTST_ABRAHAM_TEST_SELECTED                  STD_OFF

/* Implements RamTst130_Conf */
/* Implements ECUC_RamTst_00130 */
/* Implements SWS_BSW_00183 */
/* Select Checkerboard Test Algorithm */
#define RAMTST_CHECKERBOARD_TEST_SELECTED             STD_ON

/* Implements RamTst132_Conf */
/* Implements ECUC_RamTst_00132 */
/* Implements SWS_BSW_00183 */
/* Select Galpat Test Algorithm */
#define RAMTST_GALPAT_TEST_SELECTED                   STD_OFF

/* Implements RamTst133_Conf */
/* Implements ECUC_RamTst_00133 */
/* Implements SWS_BSW_00183 */
/* Select March Test Algorithm */
#define RAMTST_MARCH_TEST_SELECTED                    STD_OFF

/* Implements RamTst134_Conf */
/* Implements ECUC_RamTst_00134 */
/* Implements SWS_BSW_00183 */
/* Select TranspGalpat Test Algorithm */
#define RAMTST_TRANSP_GALPAT_TEST_SELECTED            STD_OFF

/* Implements RamTst135_Conf */
/* Implements ECUC_RamTst_00135 */
/* Implements SWS_BSW_00183 */
/* Select WalkPath Test Algorithm */
#define RAMTST_WALK_PATH_TEST_SELECTED                STD_OFF

/* Select March Y Test Algorithm */
#define RAMTST_MARCH_Y_TEST_SELECTED                  STD_OFF


/* The total number of Blocks configured */
#define RAMTST_MAX_BLOCK                              0x28U

/* Configure the Maximum possible number of tested
      cells that can be configured for each test algorithm */
#define RAMTST_MAX_TESTED_CELLS                       0x400U


/* Implements RamTst187_Conf */
/* Implements ECUC_RamTst_00187 */
/* The RamTest Cell Divider. */
#define RAMTST_CELL_DIVIDER                           0x05U

/* The RamTest cell type. */
#define RAM_TEST_DATA_TYPE                            (32U)

/*  The Checker value. */
#define RAMTST_CHECKERVALUE                    (RamTst_TestDataType)0xAAAAAAAAU


/* Global RAM section is available. */
#define RAMTST_GLOBAL_RAM                             STD_ON

/* Configure RamTst test policy. */
#define RAMTST_NON_DESTRUCTIVE_POLICY                 STD_ON


/* Implements SWS_RamTst_01002 */
/* Implements SWS_BSW_00200 */
/* The failure of RAM during RamTst_MainFunction is reported to DEM */
#define RAMTST_MAIN_RAM_FAILURE                       \
  DemConf_DemEventParameter_AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE

/* Implements SWS_RamTst_01005 */
/* Implements SWS_BSW_00200 */
/* The failure of RAM during RamTst_RunFullTest is reported to DEM */
#define RAMTST_RUNFL_RAM_FAILURE                      \
  DemConf_DemEventParameter_AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE

/* Implements SWS_RamTst_01008 */
/* Implements SWS_BSW_00200 */
/* The failure of RAM during RamTst_RunPartialTest is reported to DEM */
#define RAMTST_PART_RAM_FAILURE                       \
  DemConf_DemEventParameter_AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE

/* Implements RamTst189_Conf */
/* Implements ECUC_RamTst_00189 */
/* Implements SWS_BSW_00200 */
/* The failure of RAM is reported to DEM */
#define RAMTST_E_RAM_FAILURE                          \
  DemConf_DemEventParameter_AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE

/* Implements EAAR_PN0081_FSR_0002 */
/* Implements SWS_BSW_00200 */
/* The failure of read verify check of ECC registers is reported to DEM */
#define RAMTST_E_ECC_FAILED                           \
  DemConf_DemEventParameter_AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED


/* Local RAM ECC control register */
#define RAMTST_LRECC_CNTL              (*((volatile uint32  *)0xFFC65400UL))

/* Local RAM error information control register */
#define RAMTST_LRERRINT_CNTL           (*((volatile uint32  *)0xFFC65404UL))

/* Local RAM test control register */
#define RAMTST_LRTST_CNTL              (*((volatile uint32  *)0xFFC65004UL))

/* Global RAM Bank A ECC control register */
#define RAMTST_GRECC_BKA_CNTL          (*((volatile uint32  *)0xFFC64000UL))

/* Global RAM Bank A error information control register */
#define RAMTST_GRERRINT_BKA_CNTL       (*((volatile uint32  *)0xFFC64004UL))

/* Global RAM Bank A test control register */
#define RAMTST_GRTST_BKA_CNTL          (*((volatile uint32  *)0xFFC64020UL))

/* Global RAM Bank B control register */
#define RAMTST_GRECC_BKB_CNTL          (*((volatile uint32  *)0xFFC64200UL))

/* Global RAM Bank B error information control register */
#define RAMTST_GRERRINT_BKB_CNTL       (*((volatile uint32  *)0xFFC64204UL))

/* Global RAM Bank B test control register */
#define RAMTST_GRTST_BKB_CNTL          (*((volatile uint32  *)0xFFC64220UL))



/*******************************************************************************
**                    Memory mapping file selector                            **
*******************************************************************************/
/* MemMap file switch */
#if(RAMTST_AR_VERSION == RAMTST_AR_HIGHER_VERSION)
/* ASR 4.2.2 */
#define RAMTST_MEMMAP_FILE "RamTst_MemMap.h"
#else
/* ASR 4.0.3 */
#define RAMTST_MEMMAP_FILE "MemMap.h"
#endif

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* RAMTST_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
