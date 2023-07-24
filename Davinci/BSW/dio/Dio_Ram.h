/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Dio Driver are declared.               */
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
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version
 *
 * V1.0.2:  14-Sep-2016  : As part of ARDAABC-846 Jira Ticket, the following
 *                         changes are made:
 *                        1) Added arrays for RAM Mirroring
 *                        2) Added custom types for RAM Mirroring in order to
 *                           reduce RAM usage.
 * V2.0.0:  27-Oct-2016  : As part of ARDAABC-836 Jira Ticket,
 *                         the following changes are made:
 *                         1) Compiler switch introduced to prevent
 *                            compilation errors in case only analog or JTAG
 *                            or input ports had been configured.
 * V2.0.1:  27-Oct-2016  : As part of ARDAABC-626 and ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                         1) Removed AR 3.2.2 related functionality and
 *                            added AR 4.2.2 where applicable.
 *                         2) DIO_NUM_OF_PORTREG compiles switch introduced
 * V2.0.2   06-Jan-2017  : As part of ARDAABC-882 and ARDAABC-626 Jira ticket
 *                         the following changes made:
 *                         1) Updated copyright dates
 * V2.0.3:  10-Jan-2017  : As part of ARDAABC-324 Jira ticket the following
 *                         changes done:
 *                         1) DIO memory mapping related code sections updated
 * V2.0.4   11-Jan-2017  : Following changes are made:
 *                         1) As part ARDAABC-324, code rearrangement
 *                         2) Renaming of structure type definition tags
 * V2.0.5   17-Jan-2017  : Following changes are made:
 *                         1) As part ARDAABC-707, module private type
 *                            definitions moved to Dio_Types.h header
 * V2.0.6   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.7:  27-Jan-2017  : Following changes are made:
 *                         1. As part ARDAABC-324, DIO related memmap changes
 *                            to support new code section location and to remove
 *                            sections with non conform names
 * V2.0.8:  12-Feb-2017  : Following changes are made:
 *                         1. As part of ARDAABC-626, memory sections updated
 *                            to fulfill ASR requirements.
 * V2.0.9:  17-Jul-2017  : Following changes are made:
 *                         1) As part of ARDAABD-1734, precompile switches
 *                            added for separating R4.0.3 and R4.2.2 codes in
 *                            section Extern declarations for Global Data.
 * V2.0.10: 3-Oct-2017   : Following changes are made:
 *                         1)As part of ARDAABD-2484, variables
 *                           Dio_GusPortOffset, Dio_GusChannelOffset and
 *                           Dio_GusChannelGroupsOffset are initialised to zero.
 * V2.0.11: 09-May-2018  : Following changes are made:
 *                         1)As part of Merging activity,ARDAABD-3484
 *                           a.Removed un-used memory section,
 *                             DIO_START_SEC_VAR_INIT_ASIL_B_BOOLEAN and
 *                             DIO_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN:
 *                             Ref:ARDAABD-908.
 *                         2)As part of ARDAABD-2990 Jira ticket,
 *                           Dio_InitRamMirror API has been removed.
 *                         3)Updated copyright dates
 * V2.0.12: 25-Jul-2019 : Following changes are made:
 *                         1)As part of ARDAABD-4464,
 *                           Moved DIO_START_SEC_VAR_INIT_BOOLEAN and
 *                           DIO_STOP_SEC_VAR_INIT_BOOLEAN section macro in
 *                           DIO_AR_LOWER_VERSION macro.
 */
/******************************************************************************/
/* DIO_RAM_H_001: EAAR_PN0034_FR_0001 */
#ifndef DIO_RAM_H
#define DIO_RAM_H

/* Suppress the memory mapping related messages because the inclusion of the
 * memory mapping header is necessary.
 */

/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* AUTOSAR release version information */
#define DIO_RAM_AR_RELEASE_MAJOR_VERSION     DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_RAM_AR_RELEASE_MINOR_VERSION     DIO_AR_RELEASE_MINOR_VERSION
#define DIO_RAM_AR_RELEASE_REVISION_VERSION  DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_RAM_SW_MAJOR_VERSION    DIO_SW_MAJOR_VERSION
#define DIO_RAM_SW_MINOR_VERSION    DIO_SW_MINOR_VERSION

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/

/*******************************************************************************
 **                       Extern declarations for Global Data                 **
 ******************************************************************************/
/*Check whether the Autosar version is R4.0.3*/
#if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                     (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
#define DIO_START_SEC_VAR_INIT_BOOLEAN
#include DIO_MEMMAP_FILE
/* Global variable to store the Dio driver initialization state */
extern VAR(boolean, DIO_VAR) Dio_GblDriverStatus;
#define DIO_STOP_SEC_VAR_INIT_BOOLEAN
#include DIO_MEMMAP_FILE
#endif
/*End of Autosar version R4.0.3 check*/

#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  #define DIO_START_SEC_VAR_NO_INIT_16
#include DIO_MEMMAP_FILE
/*
 * Global variable to indicate the offset of ports starting for the
 * corresponding configuration set in the array Dio_GstPortGroup[].
 */
extern VAR(uint16, DIO_VAR_NOINIT) Dio_GusPortOffset;

#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channels starting for the
 * corresponding configuration set in the array Dio_GstPortChannel[].
 */
extern VAR(uint16, DIO_VAR_NOINIT) Dio_GusChannelOffset;

#endif

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
extern VAR(uint16, DIO_VAR_NOINIT) Dio_GusChannelGroupsOffset;

#endif

#define DIO_STOP_SEC_VAR_NO_INIT_16
#include DIO_MEMMAP_FILE
#else
  #define DIO_START_SEC_VAR_INIT_ASIL_B_16
#include DIO_MEMMAP_FILE
/*
 * Global variable to indicate the offset of ports starting for the
 * corresponding configuration set in the array Dio_GstPortGroup[].
 */
extern VAR(uint16, DIO_VAR_INIT) Dio_GusPortOffset;

#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channels starting for the
 * corresponding configuration set in the array Dio_GstPortChannel[].
 */
extern VAR(uint16, DIO_VAR_INIT) Dio_GusChannelOffset;

#endif

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
extern VAR(uint16, DIO_VAR_INIT) Dio_GusChannelGroupsOffset;

#endif

  #define  DIO_STOP_SEC_VAR_INIT_ASIL_B_16
#include DIO_MEMMAP_FILE
#endif /*(DIO_AR_VERSION == DIO_AR_LOWER_VERSION) */

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  #define DIO_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
  #define DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include DIO_MEMMAP_FILE

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  #define DIO_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
    #define DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include DIO_MEMMAP_FILE

/*******************************************************************************
 **                      Global Function Prototypes                           **
 ******************************************************************************/

#endif
/* DIO_RAM_H */

/*******************************************************************************
 **                          End Of File                                      **
 ******************************************************************************/
