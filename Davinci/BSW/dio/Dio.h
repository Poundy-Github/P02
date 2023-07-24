/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, DIO type definitions, structure data types and  */
/* API function prototypes of DIO Driver                                      */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version
 * V1.0.1:  03-Dec-2015  : As part of F1K_Ver_4.00.01 activity following
 *                         changes are made:
 *                         1) As per JIRA Ticket ARDAAGA-74, the macro
 *                            definition for Version Info API is removed and
 *                            extern declaration is provided.
 *                         2) As per JIRA Ticket ARDAAGA-14 pre-compiler
 *                            switches are added.
 * V1.0.2:  14-Sep-2016  : As part of ARDAABC-846 Jira Ticket, the following
 *                         changes are made:
 *                         1) Added Dio_CheckHWConsistency public function
 *                            prototype, enabled when RAM Mirror is used.
 * V2.0.0   27-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                            added AR 4.2.2 where applicable.
 * V2.0.1   09-Dec-2015  : As part of ARDAABC-764 the callback functions
 *                         declaration header include has been introduced
 * V2.0.2   04-Jan-2017  : As part of ARDAABC-595 Jira ticket,
 *                         the following changes made:
 *                         1) Updated the traceability tags to the required
 *                            format.
 * V2.0.3   04-Jan-2017  : As part of ARDAABC-919 Jira ticket the following
 *                         changes made:
 *                         1) DIO_CHECK_HW_CONSISTENCY_SID has been added and
 *                            DIO_MASKED_WRITE_PORT_SID removed from the SID
 *                            definitions.
 * V2.0.4   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Removed outdated AUTOSAR version related comments
 *                         2) Updated copyright dates
 * V2.0.5   10-Jan-2017  : As Part of ARDAABC-626 Jira ticket the following
 *                         changes made:
 *                         1) InitRamMirror API has been introduced as extern
 *                            function prototype
 *                         2) Dio_Init API has been classified as 4.0.3 AR
 *                            version related API based on the AUTOSAR
 *                            specification.
 * V2.0.6   11-Jan-2017  : Following changes are made:
 *                         1) As part ARDAABC-324, renamed
 *                            DIO_START_SEC_DBTOC_DATA_UNSPECIFIED
 *                            to DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
 *                            DIO_STOP_SEC_DBTOC_DATA_UNSPECIFIED
 *                            to DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
 * V2.0.7   17-Jan-2017  : Following changes are made as part ARDAABC-707:
 *                         1) Dio_Types.h include added.
 *                         2) New SID added for InitRAMMirror
 *                         3) Compiler abstraction macros usage introduced
 * V2.0.8   20-Jan-2017  : Following changes are made as part ARDAABC-707:
 *                         1) Compiler abstraction macros updated
 * V2.0.9   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.10:  27-Jan-2017  : Following changes are made:
 *                         1. As part ARDAABC-324, DIO related memmap changes
 *                            to support new code section location and to remove
 *                            sections with non conform names
 * V2.0.11:  12-Feb-2017  : Following changes are made:
 *                         1. As part of ARDAABC-626, Dio_Init function added
 *                            for ASR 4.2.2
 *                         2. Formatted code according to guidelines
 * V2.0.12:  19-Feb-2017  : As part of ARDAABC-926 Jira ticket, code was
 *                          updated due to traceability
 * V2.0.13:  17-Jul-2017  : Following changes are made:
 *                          1)As part of ARDAABD-1734, precompile switches
 *                            added in sections,DET error codes, Include
 *                            Section, API Service Id Macros, Global Data
 *                            Types and Function Prototypes.
 * V2.0.14:  07-Aug-2017  : Following changes are made:
 *                          1)As part of ARDAABD-2232, precompile switches
 *                            added for separating R4.0.3 and R4.2.2 codes
 *                            in Dio_InitRamMirror API.
 * V2.0.15:  22-Sep-2017  : Following changes are made:
 *                          1) As per ARDAABD-2156, Dio_MaskedWritePort API
 *                             added.
 *                          2) As per ARDAABD-2273,Dio_ReadChannelOutputValue
 *                             and Dio_ReadChannelGroupOutputValue API's are
 *                             added.
 *                          4) As per ARDAABD-2507,Det Error check for invalid
 *                             database DIO_E_INVALID_DATABASE added.
 * V2.0.16:  24-Jul-2018 : Following changes are made:
 *                          1) As part of Merging activity,ARDAABD-3484
 *                             a.QAC warning justifiaction
 *                               added for Msg(2:0832).
 *                          2) As part of ARDAABD-2990 Jira ticket,
 *                             Dio_InitRamMirror API has been removed.
 *                          3) Updated copyright information.
 *                          4) As part of ARDAABD-3851 to improve traceability,
 *                             a.Removed all the redundant and obsolete
 *                               requirements.
 *                             b.Added missing requirements from requirement
 *                               documents.
 */
/******************************************************************************/
/* DIO_H_001: EAAR_PN0034_FR_0001 */
#ifndef DIO_H
#define DIO_H

/* Suppress the memory mapping related messages because the inclusion of the
 * memory mapping header is necessary.
 */

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
#define DIO_AR_FOUR_TWO_TWO         422
#define DIO_AR_FOUR_ZERO_THREE      403
#define DIO_AR_HIGHER_VERSION       DIO_AR_FOUR_TWO_TWO
#define DIO_AR_LOWER_VERSION        DIO_AR_FOUR_ZERO_THREE

/* DIO_H_002: DIO089, SWS_Dio_00089, DIO169, DIO170, SWS_Dio_00170 */
/* Standard AUTOSAR types */
#include "Std_Types.h"
/* DIO Configuration header file */
/* DIO_H_003: DIO168, DIO169 */
#include "Dio_Cfg.h"
/* Included for callback functions */
#include "Dio_Cbk.h"

#include "Dio_Hardware.h"

/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Included for macro definitions and structure declarations */
#include "Dio_PBTypes.h"
#else
/* Included for macro definitions and structure declarations */
#include "Dio_LTTypes.h"
#endif
/*  End of Autosar version R4.0.3 check*/

#include "Dio_Types.h"
/* Included for RAM variable declarations */
#include "Dio_Ram.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/*
 * Since all the debug variables will be available in Dio_Ram.h it is
 * included.
 */
/* DIO_H_004: DIO161 */
#include "Dio_Debug.h"
#endif

/*******************************************************************************
 **                        Version Information                                **
 ******************************************************************************/

#define DIO_VENDOR_ID    DIO_VENDOR_ID_VALUE
#define DIO_MODULE_ID    DIO_MODULE_ID_VALUE
#define DIO_INSTANCE_ID  DIO_INSTANCE_ID_VALUE

/* DIO_H_022: DIO_ESDD_UD_003 */
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* AUTOSAR release version information */
#define DIO_AR_RELEASE_MAJOR_VERSION    4
#define DIO_AR_RELEASE_MINOR_VERSION    0
#define DIO_AR_RELEASE_REVISION_VERSION 3
#elif (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define DIO_AR_RELEASE_MAJOR_VERSION    4
#define DIO_AR_RELEASE_MINOR_VERSION    2
#define DIO_AR_RELEASE_REVISION_VERSION 2
#endif
/*END of DIO_AR_VERSION */

/* Module Software version information */
#define DIO_SW_MAJOR_VERSION       DIO_SW_MAJOR_VERSION_VALUE
#define DIO_SW_MINOR_VERSION       DIO_SW_MINOR_VERSION_VALUE
#define DIO_SW_PATCH_VERSION       DIO_SW_PATCH_VERSION_VALUE

/******************************************************************************/
/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
/*******************************************************************************
 **                         QAC Warning                                       **
 ******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : None                                                       */
/* Justification : These Macro substitution is required to optimize MemMap    */
/*                 inclusion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
 **                      API Service Id Macros                                **
 ******************************************************************************/
/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10
#endif
/*End of Autosar version R4.0.3 check*/

 /* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/* Service ID for DIO MaskedWritePort */
#define DIO_MASKED_WRITE_PORT_SID      (uint8)0x17

/* Service ID for DIO ReadChannelOutPutValue */
#define DIO_READ_CHANNEL_OUTPUT_VALUE_SID          (uint8)0x15

/* Service ID for DIO ReadChannelGroupOutputValue */
#define DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_SID    (uint8)0x16

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO Check HW consistency */
#define DIO_CHECK_HW_CONSISTENCY_SID   (uint8)0x13

/*******************************************************************************
 **                      DET Error Codes                                      **
 ******************************************************************************/
/* DIO_H_005: DIO065, SWS_Dio_00065, DIO_ESDD_UD_027, DIO073 */
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* DET code to report Invalid Port */
/* DIO_H_024: DIO_ESDD_UD_028 */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
/* DIO_H_025: DIO_ESDD_UD_029 */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/* DIO_H_006: EAAR_PN0034_FR_0016, DIO_ESDD_UD_033 */
/* DET code to report invalid database */
#define DIO_E_INVALID_DATABASE         (uint8)0xEF

/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

/* Dio_Init API service called with NULL pointer parameter */
/* DIO_H_026: DIO_ESDD_UD_030 */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/*
 * API service used without module initialization is reported using following
 * error code.
 */
 /* DIO_H_027: DIO_ESDD_UD_031 */
#define DIO_E_UNINIT                   (uint8)0xF0

#endif
  /*End of Autosar version R4.0.3 check*/
/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
 /* DIO_H_028: DIO_ESDD_UD_032 */
#define DIO_E_PARAM_POINTER            (uint8)0x20

/* DET code to report Invalid parameter value */
#define DIO_E_PARAM_VALUE              (uint8)0x21

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/
/* DIO_H_007: DIO182, SWS_Dio_00182, DIO017, SWS_Dio_00017 */
/* DIO_H_008: DIO015, SWS_Dio_00015 */
/* DIO_H_021: DIO_ESDD_UD_036 */
/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* DIO_H_009: DIO183, SWS_Dio_00183, DIO103, SWS_Dio_00103 */
/* DIO_H_010: DIO018, SWS_Dio_00018, DIO020, SWS_Dio_00020 */
/* DIO_H_011: DIO_ESDD_UD_037 */
/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* DIO_H_012: DIO023, SWS_Dio_00023, DIO185, SWS_Dio_00185 */
/* DIO_H_013: DIO_ESDD_UD_039 */
/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* DIO_H_014: DIO024, SWS_Dio_00024, DIO186, SWS_Dio_00186 */
/* DIO_H_015: DIO_ESDD_UD_038 */
/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint16 Dio_PortLevelType;

/* DIO_H_016: DIO184, SWS_Dio_00184, DIO021, SWS_Dio_00021 */
/* DIO_H_017: DIO022, SWS_Dio_00022, DIO056, SWS_Dio_00056 */
/* DIO_H_018: DIO053, SWS_Dio_00053 */
/* DIO_H_019: DIO_ESDD_UD_025, DIO_ESDD_UD_040 */
/* Structure for Dio_ChannelGroup */
typedef struct STag_Dio_ChannelGroupType {
  /* Positions of the Channel Group */
  uint16 usMask;
  /* Position from LSB */
  uint8 ucOffset;
  /* PortGroup Index in the array Dio_GstPortGroup[] with respect to the
     pointer Dio_GpPortGroup of the corresponding configuration */
  uint8 ucPortIndex;
} Dio_ChannelGroupType;

/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* DIO_H_020: DIO187, SWS_Dio_00187, DIO164, SWS_Dio_00164 */
/* DIO_H_021: DIO_ESDD_UD_023, DIO_ESDD_UD_041 */
/* Data Structure required for initializing the Dio Driver */
typedef struct STag_Dio_ConfigType {
  /* Database start value - DIO_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  /* Port Offset */
  uint16 usPortOffset;
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Channel Offset */
  uint16 usChannelOffset;
  #endif
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Sum of number of channel groups in the previous configuration */
  uint16 usChannelGroupsOffset;
  #endif
} Dio_ConfigType;
  #endif
  /*End of Autosar version R4.0.3 check*/
/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CODE_ASIL_B
#else
#define DIO_START_SEC_CODE
#endif
#include DIO_MEMMAP_FILE

/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Function for DIO Initialization API */

extern FUNC(void, DIO_PUBLIC_CODE) Dio_Init(
                CONSTP2CONST(Dio_ConfigType, AUTOMATIC, DIO_CONST) ConfigPtr);

#endif
/*end of #if(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)*/


/* Function for DIO read Channel API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort(
                                      CONST(Dio_PortType, AUTOMATIC) PortId);

/* Function for DIO write Channel API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort(
                             CONST(Dio_PortType,         AUTOMATIC) PortId,
                             CONST(Dio_PortLevelType,    AUTOMATIC) Level);

/* Function for DIO read Port API */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel(
                                CONST(Dio_ChannelType, AUTOMATIC) ChannelId);

/* Function for DIO write Port API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel(
                             CONST(Dio_ChannelType,  AUTOMATIC)  ChannelId,
                             CONST(Dio_LevelType,    AUTOMATIC)  Level);

/* Function for DIO read Channel Group API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup(
  CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr);

/* Function for DIO write Channel Group API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup(
 CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level);

/* DIO_H_029: DIO_ESDD_UD_019 */
#if (DIO_FLIP_CHANNEL_API == STD_ON)

/* Function for DIO flip channel API */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_FlipChannel(
                                CONST(Dio_ChannelType, AUTOMATIC) ChannelId);
#endif

#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
/* Function for DIO Masked Write channel API */

extern FUNC(void, DIO_PUBLIC_CODE) Dio_MaskedWritePort
      (Dio_PortType  PortId, Dio_PortLevelType  Level, Dio_PortLevelType  Mask);

#endif

#if (DIO_READ_CHANNEL_OUTPUT_VALUE_API == STD_ON)

/* Function for DIO ReadChannel Output Value API */
/* DIO_H_030: DIO_ESDD_UD_042 */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannelOutputValue(
                                CONST(Dio_ChannelType, AUTOMATIC) ChannelId );

#endif

#if (DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_API  == STD_ON)

/* Function for DIO ReadChannel Group OutputValue API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroupOutputValue(
   CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr );

#endif

#if (DIO_RAM_MIRROR == DIO_RAM_MIRROR_ENABLE)

/* Function for DIO Check Hardware Consistency */
extern FUNC(Std_ReturnType,DIO_PUBLIC_CODE) Dio_CheckHWConsistency(
                     CONST(Dio_HWConsistencyCheckType, AUTOMATIC) CheckType);

#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
extern FUNC(void, DIO_PUBLIC_CODE) Dio_GetVersionInfo(
            CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DIO_CONST) versioninfo);
#endif
/* STD_ON == DIO_VERSION_INFO_API */

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CODE_ASIL_B
#else
#define DIO_STOP_SEC_CODE
#endif
#include DIO_MEMMAP_FILE

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include DIO_MEMMAP_FILE

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
extern CONST(Dio_ChannelGroupType, DIO_CONST)
                          Dio_GstChannelGroupData[DIO_CHANNEL_GROUP_ARRAY_SIZE];
#endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */

/*Check whether the Autosar version is R4.0.3*/
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* DIO_H_023: DIO_ESDD_UD_018 */
/* Declaration for DIO Database */
extern CONST(Dio_ConfigType, DIO_CONFIG_CONST)
                                    Dio_GstConfiguration[DIO_CONFIG_ARRAY_SIZE];
 #endif
/*  End of Autosar version R4.0.3 check*/
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif
/* DIO_H  */

/*******************************************************************************
 **                      End of File                                          **
 ******************************************************************************/
