/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = RamTst_Types.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, RamTst type definitions, structure data types   */
/* and API function prototypes of RamTst Driver                               */
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
 * V1.0.0:  06-Nov-2013  : Initial Version
 *
 * V1.0.1:  06-Feb-2014  : As per CR 392, following changes are made:
 *                         1. Updated as per coding guidelines.
 *                         2. The Copyright information is updated.
 *
 * V1.0.2:  07-May-2014  : As per CR 505, for mantis #21215:
 *                         Updated to type cast Macro RAMTST_ECC_MASK.
 *
 * V1.1.0:  23-Jun-2014  : As per CR 531, for mantis #21269:
 *                         1. Register read-back is implemented in API's
 *                            "RamTst_Init".
 *                         2. Updated as per coding guidelines.
 *
 * V1.1.1:  18-Sep-2014  : As per CR 09, following change is made:
 *                         1. File is updated to remove unwanted QAC Warning.
 *                         2. File is updated for avoiding the QAC misra
 *                            warning.
 *                         3. File is Updated as per coding guidelines.
 *
 * V1.1.2:  13-Feb-2015 :  As part of merging activity (mantis #26024),
 *                         following changes are made:
 *                         1. P1X file is adapted from P1X branch.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  30-Sep-2016 :  WriteVerify and HWConsistencyCheck related
 *                         functionality added (ARDAABC-722, ARDAABC-724,
 *                         ARDAABC-726)
 *
 * V1.2.1:  19-Oct-2016 :  Static analysis related corrections
 *
 * V1.2.2:  24-Oct-2016 :  As part of activity ARDAABC-917, the following
 *                         constants defined:
 *                         RAMTST_CRC_INIT_VALUE, RAMTST_CRC_TABLE_LENGTH
 *
 * V1.2.3:  28-Oct-2016 :  Traceability tag format changed, missing tags added
 *                         (ARDAABC-900)
 *
 * V2.0.0:  07-Nov-2016 :  As part of ARDAABC-939, following change is made:
 *                         1. SWS_RamTst_01011 traceability tag added
 * V2.0.1:  03-Dec-2016 :  As part of ARDAABC-571 the following changes made
 *                         1. Traceability tags updated according to AR4.2.2
 *                            format
 * V2.0.2:  07-Dec-2016 :  As part of ARDAABC-588 the following changes made
 *                         1. New SWS_BSW_nnnnn traceability tags added.
 * V2.0.3:  16-Jun-2017 :  As part of F1KM support implementation, a register
 *                         mask is added for Global RAM interrupt notfication
 *                         register.
 * V2.0.4:  06-Jul-2018 :  As part of ARDAABD-2319, RamTstTestBuffer is added in
 *                         RamTst_BlockConfigType structure.
 *                         As part of ARDAABD-2252, RamTst1_2BitNotification and
 *                         RamTstErrCorrectionDetection are removed from
 *                         RamTst_ConfigType. Also removed the
 *                         RamTst_HWConsistencyCheckType enum.
 *                         As part of ARDAABD-2101 following changes are made:
 *                         1. Added traceability tags for Reqtify coverage
 *                            improvement.
 *                         2. Updated copyright information
 */
/******************************************************************************/
/* RAMTST_TYPES_H_034: EAAR_PN0034_FR_0001 */
/* RAMTST_TYPES_H_035: EAAR_PN0034_FR_0047 */
/* RAMTST_TYPES_H_036: EAAR_PN0034_FR_0052 */
/* RAMTST_TYPES_H_037: EAAR_PN0034_FR_0018 */
/* RAMTST_TYPES_H_038: EAAR_PN0034_FR_0021 */
/* RAMTST_TYPES_H_039: EAAR_PN0034_FR_0064 */
/* RAMTST_TYPES_H_040: EAAR_PN0034_FR_0065 */
/* RAMTST_TYPES_H_041: EAAR_PN0034_NR_0001 */
/* RAMTST_TYPES_H_042: EAAR_PN0034_NR_0007 */
/* RAMTST_TYPES_H_043: EAAR_PN0034_NR_0056 */
/* RAMTST_TYPES_H_044: EAAR_PN0034_NR_0012 */
/* RAMTST_TYPES_H_045: EAAR_PN0034_NR_0018 */
/* RAMTST_TYPES_H_046: EAAR_PN0034_NR_0020 */
/* RAMTST_TYPES_H_047: EAAR_PN0034_NR_0069 */
/* RAMTST_TYPES_H_048: AR_PN0040_FR_0017 */
/* RAMTST_TYPES_H_050: AR_PN0040_FR_0036 */
/* RAMTST_TYPES_H_051: AR_PN0040_FR_0038 */
/* RAMTST_TYPES_H_052: AR_PN0040_NR_0006 */
#ifndef RAMTST_TYPES_H
#define RAMTST_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* RAMTST_TYPES_H_059: EAAR_PN0034_FR_0055 */
/* RAMTST_TYPES_H_049: AR_PN0040_FR_0020 */
/* RAMTST_TYPES_H_054: RamTst117 */
#define RAMTST_TYPES_AR_RELEASE_MAJOR_VERSION   RAMTST_AR_RELEASE_MAJOR_VERSION
#define RAMTST_TYPES_AR_RELEASE_MINOR_VERSION   RAMTST_AR_RELEASE_MINOR_VERSION
#define RAMTST_TYPES_AR_RELEASE_REVISION_VERSION \
                                            RAMTST_AR_RELEASE_REVISION_VERSION

#define RAMTST_TYPES_SW_MAJOR_VERSION  RAMTST_SW_MAJOR_VERSION
#define RAMTST_TYPES_SW_MINOR_VERSION  RAMTST_SW_MINOR_VERSION

/*******************************************************************************
**                      Macros to avoid direct numbers                        **
*******************************************************************************/
#define RAMTST_ZERO              0u
#define RAMTST_ONE               1u
#define RAMTST_TWO               2u
#define RAMTST_THREE             3u
#define RAMTST_EIGHT             8u
#define RAMTST_WORD_ZERO         (uint16)0x0000
#define RAMTST_CRC_INIT_VALUE    (uint16)0xFFFF
#define RAMTST_CRC_TABLE_LENGTH  256u

/*******************************************************************************
**                      Driver  ECC mask Macros                               **
*******************************************************************************/
/* RAMTST_TYPES_H_033: EAAR_PN0081_FR_0016 */
#define RAMTST_ECC_MASK         (uint32)0x0003u

#if (RAMTST_GLOBAL_RAM == STD_ON)
  #define RAMTST_ERRINT_MASK         (uint32)0x0001u
#endif

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/
/*
*  Defines the Block_TestType.
*/
/* RAMTST_TYPES_H_056: RAMTST_ESDD_UD_124 */
/* RAMTST_TYPES_H_057: EAAR_PN0081_NR_0001 */
/* RAMTST_TYPES_H_053: RamTst061 */
typedef enum
{
  RAMTST_DESTRUCTIVE,
  RAMTST_NON_DESTRUCTIVE
} RamTst_Block_TestType;

/* RAMTST_TYPES_H_001: RamTst189, SWS_RamTst_00189 */
/* RAMTST_TYPES_H_002: RamTst006, SWS_RamTst_00006 */
/* RAMTST_TYPES_H_058: RAMTST_ESDD_UD_118 */
/* RamTst_ExecutionStatusType
** Defines the execution status of the RAM Test.
*/
typedef enum
{
  RAMTST_EXECUTION_UNINIT,
  RAMTST_EXECUTION_STOPPED,
  RAMTST_EXECUTION_RUNNING,
  RAMTST_EXECUTION_SUSPENDED
} RamTst_ExecutionStatusType;

/* RAMTST_TYPES_H_003: RamTst190, SWS_RamTst_00190, SWS_RamTst_01003 */
/* RAMTST_TYPES_H_004: RamTst012, SWS_RamTst_00012, SWS_RamTst_01004 */
/* RAMTST_TYPES_H_060: RAMTST_ESDD_UD_119 */
/* RamTst_TestResultType
** Defines the Test Result status of the RAM Test.
*/
typedef enum
{
  RAMTST_RESULT_NOT_TESTED,
  RAMTST_RESULT_OK,
  RAMTST_RESULT_NOT_OK,
  RAMTST_RESULT_UNDEFINED
} RamTst_TestResultType;

/* RAMTST_TYPES_H_005: RamTst013, SWS_RamTst_00013, SWS_RamTst_00188 */
/* RAMTST_TYPES_H_006: RamTst192, SWS_RamTst_00227 */
/* RAMTST_TYPES_H_007: RamTst058, SWS_RamTst_00058 */
/* RAMTST_TYPES_H_008: RamTst063, SWS_RamTst_00063, SWS_BSW_00146 */
/* RAMTST_TYPES_H_061: RAMTST_ESDD_UD_121 */
/* RamTst_AlgorithmType
** Defines the Algorithm that selected for the RAM Test.
*/
typedef enum
{
  RAMTST_ALGORITHM_UNDEFINED,
  RAMTST_CHECKERBOARD_TEST,
  RAMTST_MARCH_TEST,
  RAMTST_WALK_PATH_TEST,
  RAMTST_GALPAT_TEST,
  RAMTST_TRANSP_GALPAT_TEST,
  RAMTST_ABRAHAM_TEST,
  RAMTST_MARCH_Y_TEST
} RamTst_AlgorithmType;

/* RAMTST_TYPES_H_062: RAMTST_ESDD_UD_120 */
/* RAMTST_TYPES_H_009: RamTst191, SWS_RamTst_00191, SWS_BSW_00146 */
/*  RamTst_AlgParamsIdType
*   Data type used to identify a set of configuration parameters for a test
*   algorithm.
*/
typedef VAR(uint8, AUTOMATIC) RamTst_AlgParamsIdType;

/* RAMTST_TYPES_H_010: RamTst173, SWS_RamTst_00173, SWS_BSW_00146 */
/* Implements RamTst173 */
/* RAMTST_TYPES_H_063: RAMTST_ESDD_UD_122 */
/* RamTst_NumberOfTestedCellsType
** Data type of number of tested RAM cells.
*/
typedef VAR(uint32, AUTOMATIC) RamTst_NumberOfTestedCellsType;

/* RAMTST_TYPES_H_011: RamTst174, SWS_RamTst_00174, SWS_BSW_00146 */
/* RAMTST_TYPES_H_064: RAMTST_ESDD_UD_123 */
/* RamTst_NumberOfBlocksType.
** Data type of number of blocks
*/
typedef VAR(uint16, AUTOMATIC) RamTst_NumberOfBlocksType;

/* RAMTST_TYPES_H_012: SWS_BSW_00146 */
/* RamTst_NotificationType
** Defines the notification function pointer for the group.
*/
/* RAMTST_TYPES_H_065: RAMTST_ESDD_UD_106 */
typedef P2FUNC(void, RAMTST_APPL_CODE, RamTst_NotificationType) (void);

/* VAR type */
/* RAMTST_TYPES_H_013: EAAR_PN0081_FR_0008, SWS_BSW_00146 */
typedef VAR(uint32, AUTOMATIC)  RamTst_TestDataType;

/* RAMTST_TYPES_H_014: SWS_BSW_00146 */
/* RAMTST_TYPES_H_071: SWS_RamTst_00027 */
/* RAMTST_TYPES_H_075: ECUC_RamTst_00091 */
/* RamTst_BlockConfigType
** Data structure containing the set of configuration parameters for
** RAM Test Blocks.
*/
typedef struct
{
  /* RAMTST_TYPES_H_015: RamTst143_Conf, ECUC_RamTst_00143 */
  /* Numeric ID of the Block */
  CONST(RamTst_NumberOfBlocksType, RAMTST_CONST) RamTstBlockId;
  /* RAMTST_TYPES_H_016: RamTst144_Conf, ECUC_RamTst_00144 */
  /* End Address of the Block */
  CONST(uint32, RAMTST_CONST) RamTstEndAddress;
  /* RAMTST_TYPES_H_017: RamTst176_Conf, ECUC_RamTst_00176 */
  /* RAMTST_TYPES_H_057: EAAR_PN0081_NR_0001 */
  /* Pattern to be filled into memory cell after destructive test of block */
  CONST(uint32, RAMTST_CONST) RamTstFillPattern;
  /* RAMTST_TYPES_H_018: RamTst145_Conf, ECUC_RamTst_00145 */
  /* Start Address of the Block */
  CONST(uint32, RAMTST_CONST) RamTstStartAddress;
  /* RAMTST_TYPES_H_019: RamTst177_Conf, ECUC_RamTst_00177 */
  /* RAMTST_TYPES_H_057: EAAR_PN0081_NR_0001 */
  /* RAM Test type of Block (Destructive or non destructive RAM Test) */
  CONST(RamTst_Block_TestType, RAMTST_CONST) RamTstTestPolicy;
  /* Addres of the buffer used for non destructive mode */
  P2VAR(RamTst_TestDataType, AUTOMATIC, RAMTST_CONST) RamTstTestBuffer;
} RamTst_BlockConfigType;

/* RAMTST_TYPES_H_020: RAMTST_ESDD_UD_107 */
/* RAMTST_TYPES_H_073: ECUC_RamTst_00090 */
/* RAMTST_TYPES_H_074: SWS_BSW_00146 */
/** RamTst_AlgConfigType
**  Data structure containing the set of configuration parameters for each RAM
**  Test Algorithm.
*/
typedef struct
{
  /* Pointer to RAMTST Block Configuration */
  CONSTP2CONST(RamTst_BlockConfigType, RAMTST_VAR, RAMTST_CONST)
                                                             RamTst_BlockConfig;
  /* RAMTST_TYPES_H_021: RamTst179_Conf, ECUC_RamTst_00179 */
  /* Identifier for selecting RamTstAlgParams set */
  CONST(RamTst_AlgParamsIdType, RAMTST_CONST) RamTstAlgParamsId;
  /* RAMTST_TYPES_H_022: RamTst065_Conf, ECUC_RamTst_00065, RamTst178_Conf */
  /* RAMTST_TYPES_H_023: ECUC_RamTst_00178, RamTst063, SWS_RamTst_00063 */
  /* RAMTST_TYPES_H_070: SWS_RamTst_00026 */
  /* Numeric ID of the Algorithm */
  CONST(RamTst_AlgorithmType, RAMTST_CONST) RamTstAlgorithm;
  /* RAMTST_TYPES_H_024: RamTst152_Conf, ECUC_RamTst_00152 */
  /* Absolute maximum value for number of cells */
  CONST(RamTst_NumberOfTestedCellsType, RAMTST_CONST)
                                                  RamTstExtNumberOfTestedCells;
  /* RAMTST_TYPES_H_025: RamTst153_Conf, ECUC_RamTst_00153 */
  /* RAMTST_TYPES_H_066: EAAR_PN0081_FR_0007 */
  /*
   *  maximum number of cells that can be tested in one cycle of
   *  background test
   */
  CONST(RamTst_NumberOfTestedCellsType, RAMTST_CONST)
                                                   RamTstMaxNumberOfTestedCells;
  /* RAMTST_TYPES_H_026: RamTst141_Conf, ECUC_RamTst_00141 */
  /* Number of Blocks configured for the Algorithm */
  CONST(RamTst_NumberOfBlocksType, RAMTST_CONST) RamTstNumberOfBlocks;
  /* RAMTST_TYPES_H_027: RamTst142_Conf, ECUC_RamTst_00142 */
  /* Number Tested cells per cyclic call */
  CONST(RamTst_NumberOfTestedCellsType, RAMTST_CONST) RamTstNumberOfTestedCells;
} RamTst_AlgConfigType;

/* RAMTST_TYPES_H_028: SWS_RamTst_01011   */
/* RAMTST_TYPES_H_072: ECUC_RamTst_00066  */
/* RAMTST_TYPES_H_065: RAMTST_ESDD_UD_106 */
/* RAMTST_TYPES_H_067: RAMTST_ESDD_UD_108 */
/** RamTst_ConfigType
**  Data structure containing the set of configuration parameters.
**  required for initializing the RAMTST Module
*/
typedef struct
{
  /* Pointer to RAMTST Algorithm Configuration */
  CONSTP2CONST(RamTst_AlgConfigType, RAMTST_VAR, RAMTST_CONST)
                                                                RamTstAlgConfig;
  /* RAMTST_TYPES_H_029: RamTst181_Conf, ECUC_RamTst_00181 */
  /* Id of Default Algorithm in Configuration */
  CONST(RamTst_AlgParamsIdType, RAMTST_CONST) RamTstDefaultAlgParamsId;
  /* RAMTST_TYPES_H_030: RamTst154_Conf, ECUC_RamTst_00154 */
  /* Minimum no: of tested cells for one cycle of a background test */
  CONST(uint32, RAMTST_CONST) RamTstMinNumberOfTestedCells;
  /* RAMTST_TYPES_H_031: RamTst180_Conf, ECUC_RamTst_00180 */
  /* Number of configured parameter sets for the available test algorithms */
  CONST(RamTst_AlgParamsIdType, RAMTST_CONST) RamTstNumberOfAlgParamSets;
  /* Pointer to test completed notification function */
  /* RAMTST_TYPES_H_068: SWS_RamTst_00045 */
  CONST(RamTst_NotificationType, RAMTST_APPL_CODE) RamTstCompletedNotification;
  /* Pointer to error notification function */
  /* RAMTST_TYPES_H_069: SWS_RamTst_00046 */
  CONST(RamTst_NotificationType, RAMTST_APPL_CODE) RamTstErrorNotification;
} RamTst_ConfigType;

#endif /* RAMTST_TYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
