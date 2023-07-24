/*============================================================================*/
/* Project      = AUTOSAR Renesas X1X MCAL Components                         */
/* Module       = FlsTst_Types.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 * V1.0.0:  11-Oct-2013    : Initial Version
 *
 * V1.0.1:  05-Feb-2014    : As per CR78 and merge activity and mantis #17998
 *                           following changes are made:
 *                           1. union UTag_FlsTst_CrcConvert is added.
 *                           2. Copyright information is updated.
 *
 * V1.0.2:  17-Sep-2014    : As per CR12, following changes are made:
 *                           1. MISRA C Rule Violations section is added.
 *                           2. MISRA rules violation messages are added.
 *                           3. As per Renesas coding guidelines,
 *                              Markers are added for Tracing.
 *                           4. Enum ETag_FlsTst_TestAlgorithmType is updated
 *                              for addition of CRC 8bit(2F) and
 *                              CRC 8bit(SAEJ1850) algorithm related enum types.
 *
 * V2.0.0: 28-Oct-2016    : Added write verify error notification function.
 * V2.0.1: 04-Nov-2016    : As Part of JIRA ARDAABD-848 : Added macros for ASR
 *                          versions.
 * V2.0.2: 16-Mar-2017    : FlsTst_HWConsistencyModeType added
 *                          Added traceability information as part of JIRA
 *                          ARDAABD-1211.
 * V2.0.3: 21-Aug-2017    : Justification added for QAC warning which cannot
 *                          be removed.
 * V2.0.4: 21-Jun-2018    : 1. As per #ARDAABD-3756, Reference tags are updated.
 *                          2. Copyright(c) is updated.
 *                          3. As part of #ARDAABD-3842, Removed duplicate
 *                             Requirement id's and mapped the required
 *                             Requirements for traceability
 */
/******************************************************************************/
/* FLSTST_TYPES_H_039:  EAAR_PN0034_FR_0001                                   */
#ifndef FLSTST_TYPES_H
#define FLSTST_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for pre-compile options */
#include "FlsTst_Cfg.h"
/* AUTOSAR standard types */
#include "Std_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Release version information */
#define FLSTST_TYPES_AR_RELEASE_MAJOR_VERSION    FLSTST_AR_RELEASE_MAJOR_VERSION
#define FLSTST_TYPES_AR_RELEASE_MINOR_VERSION    FLSTST_AR_RELEASE_MINOR_VERSION
#define FLSTST_TYPES_AR_RELEASE_REVISION_VERSION \
                                              FLSTST_AR_RELEASE_REVISION_VERSION

/* FLSTST_TYPES_H_040: EAAR_PN0034_FR_0055                                    */
/* Module Software version information */
#define FLSTST_TYPES_SW_MAJOR_VERSION   FLSTST_SW_MAJOR_VERSION
#define FLSTST_TYPES_SW_MINOR_VERSION   FLSTST_SW_MINOR_VERSION

#define FLSTST_AR_FOUR_ZERO_THREE 403
#define FLSTST_AR_FOUR_TWO_TWO 422
#define FLSTST_AR_HIGHER_VERSION FLSTST_AR_FOUR_TWO_TWO
#define FLSTST_AR_LOWER_VERSION FLSTST_AR_FOUR_ZERO_THREE

/* FLSTST_TYPES_H_001:  FLSTST_ESDD_UD_001                                    */
/* FLSTST_TYPES_H_002:  EAAR_PN0034_FR_0052                                   */
/* FLSTST_TYPES_H_041:  EAAR_PN0034_NR_0026                                   */
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750)  A union type specifier has been define           */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To store memory byte individually and read/compare the     */
/*                 stored values with 16 and 32 bit CRC values.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-1 and                           */
/*                 END Msg(4:0750)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                             QAC Warnings                                   **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, '4', used to define    */
/*                 the size of an array.                                      */
/* Justification : Use of constants in a header to define types is permitted  */
/*                 due to header level of inclusion.                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-1 and                           */
/*                 END Msg(2:3132)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* TRACE [R4, FlsTst100] */
/* type specifies the identification (ID) for a Flash block to be tested in
 * foreground mode
 */

/* FLSTST_TYPES_H_003:  FLSTST_ESDD_UD_076                                    */
/* FLSTST_TYPES_H_004:  FlsTst100, SWS_FlsTst_00100                           */
typedef uint8 FlsTst_BlockIdFgndType;

/* TRACE [R4, FlsTst048] */
/* TRACE [R4, FlsTst049] */
/* Current status of the flstst execution state */
/* FLSTST_TYPES_H_005:  FLSTST_ESDD_UD_026                                    */
/* FLSTST_TYPES_H_006:  FlsTst048, FlsTst049, FlsTst148                       */
/* FLSTST_TYPES_H_007:  SWS_FlsTst_00048, SWS_FlsTst_00049, SWS_FlsTst_00148  */
typedef enum ETag_FlsTst_StateType
{
  FLSTST_UNINIT,
  FLSTST_INIT,
  FLSTST_RUNNING,
  FLSTST_ABORTED,
  FLSTST_SUSPENDED
} FlsTst_StateType;

/* TRACE [R4, FlsTst052] */
/* TRACE [R4, FlsTst053] */
/* FLSTST_TYPES_H_008:  FLSTST_ESDD_UD_074                                    */
/* FLSTST_TYPES_H_009:  FlsTst052, FlsTst053, FlsTst164                       */
/* FLSTST_TYPES_H_010:  SWS_FlsTst_00052, SWS_FlsTst_00053, SWS_FlsTst_00164  */
/* Type for test result status of foreground flash test */
typedef enum ETag_FlsTst_TestResultFgndType
{
  FLSTST_NOT_TESTED,
  FLSTST_OK,
  FLSTST_NOT_OK
} FlsTst_TestResultFgndType;
/* TRACE [R4, FlsTst164] */
/* Type for test result status in background flash test */
/* FLSTST_TYPES_H_011:  FLSTST_ESDD_UD_080                                    */
/* FLSTST_TYPES_H_012:  FlsTst052, FlsTst053, FlsTst164                       */
/* FLSTST_TYPES_H_013:  SWS_FlsTst_00052, SWS_FlsTst_00053, SWS_FlsTst_00164  */
/* FLSTST_TYPES_H_042:  FLSTST_ESDD_UD_071                                    */
typedef enum ETag_FlsTst_TestResultType
{
  FLSTST_RESULT_NOT_TESTED,
  FLSTST_RESULT_OK,
  FLSTST_RESULT_NOT_OK
} FlsTst_TestResultType;

/* Type for algorithm for foreground mode and background mode */
/*FLSTST_TYPES_H_050:  ECUC_FlsTst_00101                                      */
typedef enum ETag_FlsTst_TestAlgorithmType
{
  FLSTST_8BIT_CRC_2F,
  FLSTST_8BIT_CRC_SAEJ1850,
  FLSTST_16BIT_CRC,
  FLSTST_32BIT_CRC,
  FLSTST_CHECKSUM,
  FLSTST_DUPLICATED_MEMORY,
  FLSTST_ECC
} FlsTst_TestAlgorithmType;

/* Enumeration for bgnd check state */
/* FLSTST_TYPES_H_014:  FLSTST_ESDD_UD_084                                    */
typedef enum ETag_FlsTst_BgndCommandType
{
  FLSTST_BGND_CHECK_INIT,
  FLSTST_BGND_CHECK_INPROGRESS,
  FLSTST_BGND_CHECK_COMPLETE
} FlsTst_BgndStateType;

/* Type definition for FlsTst_HWConsistencyModeType */
/* FLSTST_TYPES_H_015:  FLSTST_ESDD_UD_086                                    */
typedef enum ETag_FlsTst_HWConsistencyModeType
{
  FLSTST_STATIC = 0,
  FLSTST_DYNAMIC
}FlsTst_HWConsistencyModeType;

/* Type Declaration to store CRC values */
/* MISRA Violation: START Msg(4:0750)-1 */
/* FLSTST_TYPES_H_016:  FLSTST_ESDD_UD_082, FLSTST_ESDD_UD_061                */
/* FLSTST_TYPES_H_017:  AR_PN0078_FSR_0037, AR_PN0078_FSR_0039                */
/* FLSTST_TYPES_H_043:  FLSTST_ESDD_UD_090                                    */
typedef union UTag_FlsTst_CrcConvert
/* END Msg (4:0750)-1 */
{
  /* To get CRC32 value*/
  uint32 ulCrc32Data;
  /* To get CRC16 value*/
  uint16 usCrc16Data;
  /* To get CRC8 value*/
  uint8 ucCrc8Data;
  /* QAC Warning: START Msg(2:3132)-1 */
  /* To store crc value */
  uint8 ucCrcData4[4];
  /* END Msg(2:3132)-1 */
} FlsTst_CrcConvert;

/* Type Declaration to store values for TestSignatureFgnd */
/* FLSTST_TYPES_H_018:  FLSTST_ESDD_UD_078                                    */
/* FLSTST_TYPES_H_019:  FlsTst109, SWS_FlsTst_00109                           */
/* FLSTST_TYPES_H_044:  FLSTST_ESDD_UD_024                                    */
typedef struct STag_FlsTst_TestSignatureFgndType
{
  /* TRACE [R4, FlsTst109] */
  /* This variable will hold the last foreground test signature value */
  uint32 ulSignatureValue;
}FlsTst_TestSignatureFgndType;

/* TRACE [R4, FlsTst155] */
/* Type Declaration to store values for TestSignatureBgnd */
/* FLSTST_TYPES_H_020:  FLSTST_ESDD_UD_079                                    */
/* FLSTST_TYPES_H_021:  FlsTst155, SWS_FlsTst_00155                           */
/* FLSTST_TYPES_H_045:  FLSTST_ESDD_UD_023                                    */
typedef struct STag_FlsTst_TestSignatureBgndType
{
  /* This variable will hold the last test interval id of the background test */
  uint32 ulTestIntervalId;
  /* This variable will hold the last background test signature value */
  uint32 ulSignatureValue;
}FlsTst_TestSignatureBgndType;

/* Type Declaration to store values for TestResultBgnd */
/* FLSTST_TYPES_H_022:  FLSTST_ESDD_UD_075, FLSTST_ESDD_UD_025                */
/* FLSTST_TYPES_H_023:  FlsTst153, FlsTst154, FlsTst164                       */
/* FLSTST_TYPES_H_024:  SWS_FlsTst_00153, SWS_FlsTst_00154, SWS_FlsTst_00164  */
typedef struct STag_FlsTst_TestResultBgndType
{
  /* TRACE [R4, FlsTst153] */
  /* This variable will hold the last test interval id of the background test */
  uint32 ulTestIntervalId;
  /* This variable will hold the last background test result */
  FlsTst_TestResultType enTestResultBgnd;
}FlsTst_TestResultBgndType;

/* TRACE [R4, FlsTst108] */
/* Type Declaration to store FlsTst_ErrorDetails */
/* FLSTST_TYPES_H_025:  FLSTST_ESDD_UD_028, FLSTST_ESDD_UD_077                */
/* FLSTST_TYPES_H_026:  FlsTst108, SWS_FlsTst_00108                           */
typedef struct STag_FlsTst_ErrorDetailsType
{
  uint8 ucEccStatus;
  uint32 ulEccFaultAddress;
}FlsTst_ErrorDetailsType;

/* Type declaration for Memory Block */
/* FLSTST_TYPES_H_027:  FLSTST_ESDD_UD_060                                    */
/* FLSTST_TYPES_H_046:  FLSTST_ESDD_UD_013, FLSTST_ESDD_UD_083                */
/* FLSTST_TYPES_H_048:  FlsTst106_Conf, FlsTst151_Conf, FlsTst107_Conf        */
/* FLSTST_TYPES_H_049:  FlsTst119_Conf, FlsTst123_Conf, FlsTst101_Conf        */
typedef struct STag_FlsTstBlock_ConfigType
{
  /* Foreground Test: Index identifies block to be tested by FlsTst_StartFgnd
   * Background Test: The scheduling for background test shall follow an order
   * defined by this index
   */
  uint32 ulFlsTstBlockIndex;
  /* Start Address of the Flash block */
  uint32 ulFlsTstBlockBaseAddress;
  /* Flash test block size */
  uint32 ulFlsTstBlockSize;
  /* TRACE [R4, FlsTst119_Conf] */
  /* Number of cells to be tested in BGND mode during one scheduled task */
  uint32 ulFlsTstNumberOfTestedCells;
  /* Address of the signature reference value of the Flash test block */
  uint32 ulFlsTstSignatureAddress;
  /* Test algorithm for foreground mode and background mode */
  FlsTst_TestAlgorithmType enFlsTstTestAlgorithm;
  /* To indicate address dependent CRC */
  uint8 ucFlsTstAddressDepdntCrc;
}FlsTstBlock_ConfigType;

/* TRACE [R4, FlsTst018] */
/* TRACE [R4, FlsTst019] */
/* Data Structure required for initializing the FLSTST unit */
/* FLSTST_TYPES_H_028: FLSTST_ESDD_UD_047                                     */
/* FLSTST_TYPES_H_029: FlsTst018, FlsTst019, FlsTst084_Conf, FlsTst102_Conf   */
/* FLSTST_TYPES_H_030:  SWS_FlsTst_00018, SWS_FlsTst_00019                    */

/* FLSTST_TYPES_H_031: FLSTST_ESDD_UD_073                                     */
typedef struct STag_FlsTst_ConfigType
{
  /* Database start value - FLSTST_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  #if (FLSTST_TEST_COMPLETED_NOTIFICATION_SUPPORTED == STD_ON)
  /* TRACE [R4, FlsTst075] */
  /* TRACE [R4, FlsTst074] */
  /* Pointer to test complete callback notification */
/* FLSTST_TYPES_H_032:  FLSTST_ESDD_UD_046                                    */
/* FLSTST_TYPES_H_033:  FlsTst072, FlsTst074, FlsTst075, FlsTst076, FlsTst077 */
/* FLSTST_TYPES_H_034:  FlsTst078, FlsTst159                                  */
/* FLSTST_TYPES_H_035:  SWS_FlsTst_00072, SWS_FlsTst_00074, SWS_FlsTst_00075  */
/* FLSTST_TYPES_H_036:  SWS_FlsTst_00076, SWS_FlsTst_00077, SWS_FlsTst_00078  */
/* FLSTST_TYPES_H_037:  SWS_FlsTst_00159                                      */
  P2FUNC(void, FLSTST_APPL_CODE, pTestCompleteNotifyFunc)(void);
  #endif
  /* Pointer to FlsTstBlockBgndConfigType configuration */
  P2CONST(FlsTstBlock_ConfigType, AUTOMATIC, FLSTST_CONFIG_CONST)
                pFlsTstBgndBlkConfig;
  /* Pointer to FlsTstBlockFgndConfigType configuration */
  P2CONST(FlsTstBlock_ConfigType, AUTOMATIC, FLSTST_CONFIG_CONST)
                pFlsTstFgndBlkConfig;
  /* Number of test blocks available for the background test */
  uint32 ulFlsTstMaxBgndBlkNo;
  /* Number of test blocks available for the foreground test */
  uint32 ulFlsTstMaxFgndBlkNo;
} FlsTst_ConfigType;

/* Data Structure required for initializing the FLSTST test Block */
/* FLSTST_TYPES_H_038:  FLSTST_ESDD_UD_085                                    */
/* FLSTST_TYPES_H_047:  FLSTST_ESDD_UD_048                                    */
typedef struct STag_FlsTst_GVarProperties
{
  /* Variable to store the test block start address */
  uint32 FlsTst_GulReadAddress;
  /* Variable to store the calculated CRC value */
  uint32 FlsTst_GulCalculatedCrc;
  /* Variable to store the index of the test block based on priority */
  uint16 FlsTst_GusBgndConfigIndex;
  /* Variable to store the internal background check state */
  FlsTst_BgndStateType FlsTst_GenBgndCheckState;
}FlsTst_GVarProperties;
#endif /* FLSTST_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
