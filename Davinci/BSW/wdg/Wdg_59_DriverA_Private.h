/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API and database declaration, Service Id and DET error Macros */
/* and Module version information Macros.                                     */
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
 * V1.0.0:  03-Sep-2015   : Initial Version
 * V2.0.0:  25-Aug-2016   : Changed according to #ARDAABD-653
 *                          1. ASR 3.2.2 was removed and 4.2.2 added
 * V2.0.1:  26-Oct-2016   : MemMap was changed according to #ARDAABD-474
 * V2.0.2:  27-Jan-2017   : Readability updated
 * V2.0.3:  14-Feb-2017   : #ARDAABD-568
 *                          1. Defined proper mask values
 * V2.0.4:  20-Feb-2017   : #ARDAABD-568
 *                          1. Removed unused mask macros
 * V2.0.5   06-Jul-2017   : Following changes are made:
 *                           1. As part of ARDAABD-1523 Jira ticket,function
 *                              Wdg_59_DriverA_TriggerFunc is modified.
 *                           2. As per JIRA ARDAABD-1832, external declaration
 *                              for API 'Wdg_59_DriverA_InitDetCheck' is added.
 * V2.0.6   16-Nov-2017   : Following changes are made:
 *                          1. As part of ARDAABD-2734 Jira Ticket,
 *                             variable MEMMAP_FILE is changed to
 *                             WDG_MEMMAP_FILE.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_PRIVATE_H
#define WDG_59_DRIVERA_PRIVATE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION  WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION  WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/* Macro for register masks */
/* WDTAnMD */
#define WDG_59_DRIVERA_MASK_FIRST_7_BITS           (uint8) 0x7F
/* WDTAnWDTE, WDTAnEVAC, WDTAnREF */
#define WDG_59_DRIVERA_MASK_FIRST_8_BITS           (uint8) 0xFF

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

extern FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc
                                             (boolean LblCriticalSectionFlag);


/* Declaration of API "Wdg_59_DriverA_InitDetCheck". */
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_FAST_CODE)
                                       Wdg_59_DriverA_InitDetCheck
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr);

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

#endif /* WDG_59_DRIVERA_PRIVATE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
