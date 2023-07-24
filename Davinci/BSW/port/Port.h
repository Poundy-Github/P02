/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.h                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, PORT type definitions, structure data types and */
/* API function prototypes of PORT Driver                                     */
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

/*PORT_H_025: EAAR_PN0034_NR_0045*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 *
 * V1.0.1:  16-Sep-2015  : Update for fixing, justifying the MISRA warning
 *                         after Static Analysis
 * V1.0.2:  30-Dec-2015  : The following changes are done
 *                         1. As a part of JIRA ticket ARDAAGA-79
 *                         Removed definitions of macros
 *                         Port_GetVersionInfo and "Det.h" file is included
 * V2.0.0:  14-Sep-2016  : As part of ARDAABC-757 Jira ticket, the following
 *                         changes are made:
 *                         1. Added Port_CheckHWConsistency public function
 *                            prototype, enabled when RAM Mirror is used.
 * V2.1.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                            higher version to 4.2.2. Removed Autosar 3.2.2
 *                            from implementation.
 *                         2. Removed precompile switch in order to include
 *                            Port_Debug for both AR4.0.3 and AR4.2.2.
 * V2.2.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Include MemMap header file from "Port_Cfg.h".
 *                         2. Use precompile switches to select different
 *                            memory section names in AR4.0.3 and AR4.2.2.
 * V2.2.1:  16-Nov-2016  : As part of ARDAABC-758, new API ID was added for
 *                         function which checks the hardware consistency.
 * V2.2.2:  18-Nov-2016  : As part of ARDAABC-621, the following changes are
 *                         made:
 *                         1. For AR4.2.2, PORT_E_INIT is defined, instead
 *                            of PORT_E_PARAM_CONFIG
 * V2.2.3:  21-Nov-2016  : As part of ARDAABC-763, the following changes are
 *                         made:
 *                         1. Include "Port_Cbk.h" header file.
 * V2.2.4:  22-Nov-2016  : As part of ARDAABC-538, the following changes are
 *                         made:
 *                         1. Removed AR3.2.2 traceability tags.
 *                         2. Added AR4.2.2 traceability tags.
 *                         3. Updated format for traceability comments.
 * V2.2.5:  23-Nov-2016  : As part of ARDAABC-914 ticket, the following changes
 *                         are made:
 *                         1. Removed "Det.h" inclusion.
 *                         2. Removed "Port_Debug.h" inclusion, as it had no
 *                            functionality.
 * V2.2.6:  31-Jan-2017  : As part of ARDAABC-867 ticket, the following changes
 *                         are made:
 *                         1. Removed code related to Alpha port groups.
 * V2.2.7:  07-Feb-2017  : As part of ARDAABC-867 ticket, the following changes
 *                         are made:
 *                         1. Removed EDC registers and corresponding
 *                            precompile switches.
 *                         2. Removed DNFCKS registers and corresponding
 *                            precompile switches.
 * V2.2.8:  10-Mar-2017  : As part of ARDAABC-758 ticket, the following changes
 *                         are made:
 *                         1. Added PORT_E_INVALID_CHECKTYPE DET error code.
 * V2.2.9:  26-Mar-2017  : As part of ARDAABC-629 ticket, the following changes
 *                         are made:
 *                         1. RestoredRegs fields removed from
 *                         STag_Port_ConfigType.
 * V2.2.10: 21-Jun-2018  : As part of ARDAABD-3844 Jira Ticket, the following
 *                         changes are made:
 *                         1. Requirements and Design ID's are mapped to the
 *                         implementation in order to improve coverage.
 */
/******************************************************************************/
/* PORT_H_024: PORT076, SWS_Port_00076 */
/* PORT_H_016: EAAR_PN0034_FR_0001 */
#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define PORT_AR_FOUR_TWO_TWO         422
#define PORT_AR_FOUR_ZERO_THREE      403

#define PORT_AR_HIGHER_VERSION     PORT_AR_FOUR_TWO_TWO
#define PORT_AR_LOWER_VERSION      PORT_AR_FOUR_ZERO_THREE

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* PORT_H_026: PORT080, SWS_Port_00080*/
/* PORT_H_011: SWS_Port_00130, PORT130  */
/* To publish the standard types */
#include "Std_Types.h"
/* Included for callback functions */
/* PORT_H_012: SWS_Port_00204, PORT204  */
#include "Port_Cbk.h"
/* To include pre compile values and switches */
/* PORT_H_013: SWS_Port_00208, PORT208  */
#include "Port_Cfg.h"
#include "Port_Hardware.h"
/* To publish the type Port_ConfigType */
#include "Port_PBTypes.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Version identification */
#define PORT_VENDOR_ID              PORT_VENDOR_ID_VALUE
#define PORT_MODULE_ID              PORT_MODULE_ID_VALUE
/* PORT_H_007: PORT_ESDD_UD_013 */
#define PORT_INSTANCE_ID            PORT_INSTANCE_ID_VALUE
/* PORT_H_008: PORT_ESDD_UD_106 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION) /* START of PORT_AR_VERSION */
/* Functionality related to R4.2.2 */

/* PORT_H_001: PORT114, SWS_Port_00114, SWS_BSW_00036 */
/* AUTOSAR release version information */
#define PORT_AR_RELEASE_MAJOR_VERSION    4
#define PORT_AR_RELEASE_MINOR_VERSION    2
#define PORT_AR_RELEASE_REVISION_VERSION 2
/* PORT_H_009: PORT_ESDD_UD_105 */
#elif(PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R4.0.3 */

/* PORT_H_002: PORT114, SWS_BSW_00036 */
/* AUTOSAR release version information */
#define PORT_AR_RELEASE_MAJOR_VERSION    4
#define PORT_AR_RELEASE_MINOR_VERSION    0
#define PORT_AR_RELEASE_REVISION_VERSION 3

#endif

/* Module Software version information */
#define PORT_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE
#define PORT_SW_PATCH_VERSION    PORT_SW_PATCH_VERSION_VALUE
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*PORT_H_027: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3458) Macro defines a braced code statement block.      */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3458)-1 and END Msg(4:3458)-1         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Array declared with unknown size.      */
/*Rule           : MISRA-C:2004 Rule 1.2                                      */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3684)-2 and END Msg(4:3684)-2         */
/*                 tags in the code.                                          */
/******************************************************************************/

/*******************************************************************************
**                      API service ID Macros                                 **
*******************************************************************************/
/* Service ID for PORT Initialization */
#define PORT_INIT_SID                            (uint8)0x00
/* Service ID for setting the Direction of PORT Pin */
#define PORT_SET_PIN_DIR_SID                     (uint8)0x01
/* Service ID for refreshing the Direction of PORT Pin */
#define PORT_REFRESH_PORT_DIR_SID                (uint8)0x02
/* Service ID for PORT getting Version Information */
#define PORT_GET_VERSION_INFO_SID                (uint8)0x03
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_PIN_MODE_SID                    (uint8)0x04
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_DIO_MODE_SID                 (uint8)0x05
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_ALT_MODE_SID                 (uint8)0x06
/* Service ID for setting the Default Mode of PORT Pin */
#define PORT_SET_PIN_DEFAULT_MODE_SID            (uint8)0x07
/* Service ID for setting the Default Direction of PORT Pin */
#define PORT_SET_PIN_DEFAULT_DIR_SID             (uint8)0x08
/* Service ID for checking Hardware Consistency */
#define PORT_CHECK_HW_CONISTENCY_SID             (uint8)0x09


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* Development error values are of type uint8 */

/* PORT_H_003: PORT116, SWS_BSW_00201 */

/* DET error type, values and related error codes */

/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                         (uint8)0x0A

/* Port Pin Direction not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0B

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* API Port_Init service called with wrong parameter. */
  #define PORT_E_INIT_FAILED                     (uint8)0x0C
#else
/* API Port_Init service called with wrong parameter. */
  #define PORT_E_PARAM_CONFIG                    (uint8)0x0C
#endif

/* When valid Mode is not available */
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0D

/* When valid Mode is not configured as changeable  */
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0E

/* When PORT APIs are invoked before PORT Module Initialization */
#define PORT_E_UNINIT                            (uint8)0x0F

/* When valid Database is not available */
/* PORT_H_010: EAAR_PN062_FR_0008 */
#define PORT_E_INVALID_DATABASE                  (uint8)0xEF

/* When APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                     (uint8)0x10

/* When Port_CheckHWConsistency API is invoked with invalid check type */
#define PORT_E_INVALID_CHECKTYPE                 (uint8)0xDF

/* Alternative modes for Port_SetPinMode() API */
#define APP_ALT1_OUT                 (Port_PinModeType)0x02
#define APP_ALT1_IN                  (Port_PinModeType)0x03
#define APP_ALT2_OUT                 (Port_PinModeType)0x04
#define APP_ALT2_IN                  (Port_PinModeType)0x05
#define APP_ALT3_OUT                 (Port_PinModeType)0x06
#define APP_ALT3_IN                  (Port_PinModeType)0x07
#define APP_ALT4_OUT                 (Port_PinModeType)0x08
#define APP_ALT4_IN                  (Port_PinModeType)0x09
#define APP_ALT5_OUT                 (Port_PinModeType)0x0A
#define APP_ALT5_IN                  (Port_PinModeType)0x0B
#define APP_ALT6_OUT                 (Port_PinModeType)0x0C
#define APP_ALT6_IN                  (Port_PinModeType)0x0D
#define APP_ALT7_OUT                 (Port_PinModeType)0x0E
#define APP_ALT7_IN                  (Port_PinModeType)0x0F

#define APP_ALT1_OUT_SET_PIPC        (Port_PinModeType)0x82
#define APP_ALT1_IN_SET_PIPC         (Port_PinModeType)0x83
#define APP_ALT2_OUT_SET_PIPC        (Port_PinModeType)0x84
#define APP_ALT2_IN_SET_PIPC         (Port_PinModeType)0x85
#define APP_ALT3_OUT_SET_PIPC        (Port_PinModeType)0x86
#define APP_ALT3_IN_SET_PIPC         (Port_PinModeType)0x87
#define APP_ALT4_OUT_SET_PIPC        (Port_PinModeType)0x88
#define APP_ALT4_IN_SET_PIPC         (Port_PinModeType)0x89
#define APP_ALT5_OUT_SET_PIPC        (Port_PinModeType)0x8A
#define APP_ALT5_IN_SET_PIPC         (Port_PinModeType)0x8B
#define APP_ALT6_OUT_SET_PIPC        (Port_PinModeType)0x8C
#define APP_ALT6_IN_SET_PIPC         (Port_PinModeType)0x8D
#define APP_ALT7_OUT_SET_PIPC        (Port_PinModeType)0x8E
#define APP_ALT7_IN_SET_PIPC         (Port_PinModeType)0x8F
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Structure for Port Init Configuration */
/* PORT_H_004: PORT073, PORT072, SWS_Port_00228, SWS_Port_00073 */
/* PORT_H_005: SWS_Port_00072 */
/* PORT_H_014: PORT_ESDD_UD_067 */
/* PORT_H_015: PORT_ESDD_UD_068 */
/* Overall Module Configuration Data Structure */
typedef struct STag_Port_ConfigType
{
  /* Database start value - 0x0EDF0400 */
  uint32 ulStartOfDbToc;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Numeric Port Group registers in sequence: PSR,
   * PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(Port_NumRegs, AUTOMATIC, PORT_CONFIG_CONST) pPortNumRegs;

  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of JTAG Port Group registers in sequence:
   * PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(Port_JTAGRegs, AUTOMATIC, PORT_CONFIG_CONST) pPortJRegs;

  #endif

  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Analog Port Group registers in sequence: PSR,
   * PIBC and PBDC.
   */
  P2CONST(Port_AnalogRegs, AUTOMATIC, PORT_CONFIG_CONST) pPortAnalogRegs;

  #endif

  #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Input Port Group registers in sequence:PIBC.
   */
  P2CONST(Port_IPortRegs, AUTOMATIC, PORT_CONFIG_CONST) pPortInputRegs;
  #endif

  #if ((PORT_SET_PIN_DIRECTION_API == STD_ON)       || \
       (PORT_SET_PIN_MODE_API == STD_ON)            || \
       (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON))

  /* PORT_H_006: PORT137, SWS_Port_00137 */
  /* Pointer to structure containing details about the pins whose direction
   * can be changed during run time
   */
  P2CONST(Port_PinChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPinChangeableDetails;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about DNFA registers */
  P2CONST(Port_DNFARegs, AUTOMATIC, PORT_CONFIG_CONST) pPortDNFARegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about FCLA registers */
  P2CONST(Port_FCLARegs, AUTOMATIC, PORT_CONFIG_CONST) pPortFCLARegs;
  #endif

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Total number of Numerical port groups configured */
  uint8 ucNoOfPortNumRegs;
  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Total number of JTAG port groups configured */
  uint8 ucNoOfPortJRegs;
  #endif

  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Total number of Analog port groups configured */
  uint8 ucNoOfPortAnalogRegs;
  #endif

  #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Total number of Input port groups configured */
  uint8 ucNoOfPortInputRegs;
  #endif


  #if ((PORT_SET_PIN_DIRECTION_API == STD_ON)       || \
       (PORT_SET_PIN_MODE_API == STD_ON)            || \
       (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON))
  /* Total number of pin mode changeable pins configured */
  uint8 ucNoOfPinChangeableDetails;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* The total number of DNFA noise elimination registers configured */
  uint8 ucNoOfDNFARegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* The total number of FCLA noise elimination registers configured */
  uint8 ucNoOfFCLARegs;
  #endif

} Port_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CODE_ASIL_B
#else
  #define PORT_START_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/* External Declaration for Port Initialization API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_Init
           (P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr);

/* PORT_H_017: PORT_ESDD_UD_015*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDirection
                     (Port_PinType Pin, Port_PinDirectionType Direction);
#endif
/*PORT_H_018: PORT_ESDD_UD_137*/
#if (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection
                                  (Port_PinType Pin);
#endif
/*PORT_H_019: PORT_ESDD_UD_138*/
#if (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode
                                  (Port_PinType Pin);
#endif

/* External Declaration for Port refresh port direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_RefreshPortDirection(void);

/* PORT_H_020: PORT_ESDD_UD_017 */
#if (PORT_VERSION_INFO_API == STD_ON)
extern FUNC(void,PORT_PUBLIC_CODE) Port_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_CONST) versioninfo);
#endif
/* PORT_H_021: PORT_ESDD_UD_016*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
/* External Declaration for Port set pin mode API. */
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
                                   (Port_PinType Pin, Port_PinModeType Mode);
#endif
/* PORT_H_022: PORT_ESDD_UD_019*/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin);

extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin);
#endif
/* PORT_H_023: PORT_ESDD_UD_142 */
#if (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)
extern FUNC (Std_ReturnType, PORT_PUBLIC_CODE) Port_CheckHWConsistency
                                        (Port_HWConsistencyCheckType CheckType);
#endif

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CODE_ASIL_B
#else
  #define PORT_STOP_SEC_CODE
#endif
#include PORT_MEMMAP_FILE

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE
/* External Declaration for Port database configuration set. */
/* MISRA Violation: START Msg(4:3684)-2 */
/* Structure for PORT Init configuration */
extern CONST(Port_ConfigType, PORT_CONST)
                                   Port_GstConfiguration[PORT_NUM_OF_CONFIGSET];
/* END Msg(4:3684)-2 */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

#endif /* PORT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
