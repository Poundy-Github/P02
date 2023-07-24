/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Dio Driver                             */
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
 * V1.0.1:  14-Sep-2016  : As part of ARDAABC-846 Jira Ticket, the following
 *                         changes are made:
 *                         1) Added variables definition for RAM Mirroring.
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
 * V2.0.2   06-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Updated copyright dates
 * V2.0.3:  10-Jan-2017  : As part of ARDAABC-324 Jira ticket the following
 *                         changes done:
 *                         1) DIO memory mapping related code sections updated
 * V2.0.4:  17-Jan-2017  : As part of ARDAABC-707 Jira ticket the following
 *                         changes done:
 *                         1) Indentation correction
 * V2.0.5   24-Jan-2017  : As part of ARDAABC-882 Jira ticket the following
 *                         changes made:
 *                         1) Header comment updated due to acceptance team
 *                            comment
 * V2.0.6:  27-Jan-2017  : Following changes are made:
 *                         1) As part ARDAABC-324, DIO related memmap changes
 *                            to support new code section location and to remove
 *                            sections with non conform names
 * V2.0.7:  12-Feb-2017  : Following changes are made:
 *                         1) As part of ARDAABC-626, memory sections updated
 *                            to fulfill ASR requirements
 * V2.0.8:  13-Feb-2017  : Following changes are made:
 *                         1) As part of ARDAABC-630, code was updated after QAC
 *                            analysis
 * V2.0.9:  17-Jul-2017  : Following changes are made:
 *                         1) As part of ARDAABD-1734, precompile switches
 *                            added for separating R4.0.3 and R4.2.2 codes in
 *                            section Global Data Types.
 * V2.0.10: 07-Aug-2017  : Following changes are made:
 *                         1) As part of ARDAABD-2198, Style_Format
 *                           corrected for comments and condition.
 * V2.0.11: 3-Oct-2017   : Following changes are made:
 *                         1)As part of ARDAABD-2484, variables
 *                           Dio_GusPortOffset, Dio_GusChannelOffset and
 *                           Dio_GusChannelGroupsOffset are initialised to zero.
 *                         2)As part of ARDAABD-2556, unwanted MISRA C rule
 *                           message tags have been removed.
 * V2.0.12: 22-June-2018 : Following changes are made:
 *                         1)As part of Merging activity ARDAABD-3484,
 *                           a.QAC warning comment added for Msg(2:0862).
 *                         2)As part of ARDAABD-2990 Jira ticket,
 *                           Dio_InitRamMirror API has been removed.
 *                         3)Updated copyright dates
 *                         4)As part of ARDAABD-3851 to improve traceability,
 *                           added missing requirements from requirement
 *                           documents.
 * V2.0.13: 25-Jul-2019 : Following changes are made:
 *                         1)As part of ARDAABD-4464,
 *                           Moved DIO_START_SEC_VAR_INIT_BOOLEAN and
 *                           DIO_STOP_SEC_VAR_INIT_BOOLEAN section macro in
 *                           DIO_AR_LOWER_VERSION macro.
 */
/******************************************************************************/

/*******************************************************************************
 **                     Include Section                                       **
 ******************************************************************************/
/* Included for module version information and other types declarations */
#include "Dio.h"
/* Included for RAM variable declarations */
/* Implements EAAR_PN0034_FR_0019 */
#include "Dio_Ram.h"

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* AUTOSAR release version information */
#define DIO_RAM_C_AR_RELEASE_MAJOR_VERSION   DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_MINOR_VERSION   DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_REVISION_VERSION \
                                          DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* Module Software version information  */
#define DIO_RAM_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_RAM_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
 **                      Version Check                                        **
 ******************************************************************************/
#if (DIO_RAM_AR_RELEASE_MAJOR_VERSION != DIO_RAM_C_AR_RELEASE_MAJOR_VERSION)
#error "Dio_Ram.c : Mismatch in Release Major Version"
#endif

#if (DIO_RAM_AR_RELEASE_MINOR_VERSION != DIO_RAM_C_AR_RELEASE_MINOR_VERSION)
#error "Dio_Ram.c : Mismatch in Release Minor Version"
#endif

#if (DIO_RAM_AR_RELEASE_REVISION_VERSION != \
                                         DIO_RAM_C_AR_RELEASE_REVISION_VERSION)
#error "Dio_Ram.c : Mismatch in Release Revision Version"
#endif

#if (DIO_RAM_SW_MAJOR_VERSION != DIO_RAM_C_SW_MAJOR_VERSION)
#error "Dio_Ram.c : Mismatch in Software Major Version"
#endif

#if (DIO_RAM_SW_MINOR_VERSION != DIO_RAM_C_SW_MINOR_VERSION)
#error "Dio_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                        QAC Warning                                        **
 ******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC WARNING:                                                            */
/* Message       : (2:0862) This #include "MemMap.h" directive is             */
/*                  redundant                                                 */
/* Justification : Inclusion of the Det.h and MemMap.h file                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/
/* 3.  QAC Warning:                                                           */
/* Message       : (2:2022) The global identifier '%s' is defined here,       */
/*                 but is not used in this translation unit.                  */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : The global identifier '%s'is external for other            */
/*                          translation units.                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-3 and                           */
/*                 END Msg(2:2022)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier 'Dio_GusPortOffset',         */
/*                'Dio_GusChannelOffset','Dio_GusChannelGroupsOffset' are     */
/*                defined here but is not used in this translation unit.      */
/* Rule         : NA                                                          */
/* Justification: As per AUTOSAR, all global variables extern declaration     */
/*                shall be given in Pwm_Ram.h                                 */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-4 and                            */
/*                END Msg(2:3211)-4 tags in the code.                         */
/******************************************************************************/

/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/

/*Check whether the Autosar version is R4.0.3*/
#if  ((DIO_DEV_ERROR_DETECT == STD_ON) && \
                                     (DIO_AR_VERSION == DIO_AR_LOWER_VERSION))
/* QAC Warning: START Msg(2:0832)-1 */
/* Implements EAAR_PN0034_NR_0087 */
#define DIO_START_SEC_VAR_INIT_BOOLEAN
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Global variable to store the Dio driver initialization state */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(boolean, DIO_INIT_DATA) Dio_GblDriverStatus = DIO_UNINITIALIZED;
/* END Msg(2:3211)-4 */
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_VAR_INIT_BOOLEAN
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#endif
/* QAC Warning: START Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
#define DIO_START_SEC_VAR_NO_INIT_16
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/*
 * Global variable to indicate the offset of ports starting for the
 * corresponding configuration set in the array Dio_GstPortGroup[].
 */
/* QAC Warning: START Msg(2:2022)-3 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(uint16, DIO_VAR_NOINIT) Dio_GusPortOffset;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channels starting for the
 * corresponding configuration set in the array Dio_GstPortChannel[].
 */
/* QAC Warning: START Msg(2:2022)-3 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(uint16, DIO_VAR_NOINIT) Dio_GusChannelOffset;
#endif
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
/* QAC Warning: START Msg(2:2022)-3 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(uint16, DIO_VAR_NOINIT) Dio_GusChannelGroupsOffset;
#endif
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_STOP_SEC_VAR_NO_INIT_16
#include DIO_MEMMAP_FILE
#else
#define DIO_START_SEC_VAR_INIT_ASIL_B_16
#include DIO_MEMMAP_FILE
/*
 * Global variable to indicate the offset of ports starting for the
 * corresponding configuration set in the array Dio_GstPortGroup[].
 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(uint16, DIO_VAR_INIT) Dio_GusPortOffset = DIO_ZERO_PORTOFFSET;
/* END Msg(2:3211)-4 */
#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channels starting for the
 * corresponding configuration set in the array Dio_GstPortChannel[].
 */
/* QAC Warning: START Msg(2:3211)-4 */
VAR(uint16, DIO_VAR_INIT) Dio_GusChannelOffset = DIO_ZERO_CHANNELOFFSET;
#endif
/* END Msg(2:3211)-4 */
#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
VAR(uint16, DIO_VAR_INIT) Dio_GusChannelGroupsOffset =
                                                   DIO_ZERO_CHANNELGROUPOFFSET;
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
/* END Msg(2:0832)-1 */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:0862)-2 */
#define DIO_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
#else
#define DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */
/*******************************************************************************
 **                      Function Definitions                                 **
 ******************************************************************************/

/*******************************************************************************
 **                          End of File                                      **
 ******************************************************************************/
