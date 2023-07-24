/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Types.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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

/* PORT_TYPES_H_014: EAAR_PN0034_NR_0045 */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 *
 * V2.0.0:  07-Sep-2016  : As part of ARDAABC-706 Jira Ticket, the following
 *                         changes are made:
 *                        1. Added define values for configuring RAM Mirror and
 *                           Write-Verify safety features.
 *                        2. Added enum types for Hardware Consistency check.
 * V2.1.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                            higher version to 4.2.2. Versioning for both
 *                            AR4.0.3 and AR4.2.2 comes from Port_Cfg.h now.
 * V2.2.0:  18-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. RAM Mirroring types were added.
 * V2.2.1:  22-Nov-2016  : As part of ARDAABC-538, the following changes are
 *                         made:
 *                         1. Removed AR3.2.2 traceability tags.
 *                         2. Added AR4.2.2 traceability tags.
 *                         3. Updated format for traceability comments.
 * V2.2.2:  24-Nov-2016  : As part of ARDAABC-757 Jira Ticket, the following
 *                         changes are made:
 *                         1. RAM Mirroring array for analog port groups was
 *                         removed.
 *                         2. Fields corresponding to registers with not
 *                         applicable RAM Mirroring functionality were removed
 *                         for numerical and JTAG port groups.
 * V2.2.3:  21-Jun-2018  : As part of ARDAABD-3844 Jira Ticket, the following
 *                         changes are made:
 *                         1. Requirements and Design ID's are mapped to the
 *                         implementation in order to improve coverage.
*/
/******************************************************************************/
/* PORT_TYPES_H_015: EAAR_PN0034_FR_0001 */
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_TYPES_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_TYPES_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_TYPES_AR_RELEASE_REVISION_VERSION \
                                     PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_TYPES_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION
#define PORT_TYPES_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION

/*******************************************************************************
**                      GLOBAL DATA TYPES                                     **
*******************************************************************************/

/* PORT_WRITE_VERIFY Values */
/* Macro for Register readback disable */
#define PORT_WV_DISABLE                           0U
/* Macro for Register readback INIT_ONLY */
#define PORT_WV_INIT_ONLY                  1U
/* Macro for Register readback INIT_RUNTIME */
#define PORT_WV_INIT_RUNTIME               2U

/* PORT_RAM_MIRROR Values */
/* PORT_TYPES_H_009: PORT_ESDD_UD_142 */
/* Macro for RAM Mirror Disable */
#define PORT_RAM_MIRROR_DISABLE                   0U
/* Macro for RAM Mirror Enable */
#define PORT_RAM_MIRROR_ENABLE                    1U

/* PORT_TYPES_H_010: PORT_ESDD_UD_142 */
#if (PORT_RAM_MIRROR == PORT_RAM_MIRROR_ENABLE)
/* PORT_TYPES_H_011: PORT_ESDD_UD_166 */
/* PORT_TYPES_H_012: PORT004, SWS_Port_00004 */
/* Type of Hardware Consistency check */
typedef enum ETag_Port_HWConsistencyCheckType
{
  PORT_HW_CONSIST_CHECK_STATIC,
  PORT_HW_CONSIST_CHECK_DYNAMIC
} Port_HWConsistencyCheckType;

/* Structure containing registers for RAM mirror. Compared to Port register
 * structure, it has the dummy sections removed for lower RAM usage. */
typedef struct Stag_PortRegistersRamMirror
{
    uint16 usPFC;                                  /* PFC              */

    uint16 usPFCE;                                 /* PFCE             */

    uint16 usPFCAE;                                /* PFCAE            */

    uint16 usPIPC;                                 /* PIPC             */
}Port_NumRegRamMirror;

/* Structure containing registers for RAM mirror. Compared to Port register
 * structure, it has the dummy sections removed for lower RAM usage. */
typedef struct Stag_JPortRegistersRamMirror
{
    uint8 ucJPFC;                                  /* JPFC             */

    uint8 ucJPFCE;                                 /* JPFCE            */
}Port_JTAGRegRamMirror;
#endif

/* PORT_TYPES_H_001: PORT201, PORT013, PORT219, SWS_BSW_00141 */
/* PORT_TYPES_H_002: SWS_Port_00229, SWS_Port_00013, SWS_Port_00219 */
/* PORT_TYPES_H_006: PORT_ESDD_UD_091 */
/* Type definition for Port_PinType used by the API Port_SetPinDirection() */
typedef uint16 Port_PinType;

/* Type definition for Port_PinDirectionType used by the API
 * Port_SetPinDirection()
 */
/* PORT_TYPES_H_003: PORT046, SWS_Port_00046, SWS_Port_00230 */
/* PORT_TYPES_H_007: PORT_ESDD_UD_092 */
typedef enum ETag_Port_PinDirectionType
{
  /* The type Port_PinDirectionType shall be of enumeration type */
  /* PORT_TYPES_H_004: PORT220, SWS_Port_00220, SWS_Port_00230 */
  PORT_PIN_OUT,
  PORT_PIN_IN
} Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the API
 * Port_SetPinMode()
 */
/* PORT_TYPES_H_005: PORT124, PORT221, SWS_Port_00124, SWS_Port_00221 */
/* PORT_TYPES_H_013: SWS_Port_00231 */
/* PORT_TYPES_H_008: PORT_ESDD_UD_093 */
typedef uint8 Port_PinModeType;
#endif /* PORT_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
