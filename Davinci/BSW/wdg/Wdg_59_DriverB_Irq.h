/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverB_Irq.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver Component.                                 */
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
 * V1.0.0:  03-Sep-2015    : Initial Version
 * V2.0.0   25-Aug-2016    : Changed according to #ARDAABD-653
 *                           1. ASR 3.2.2 was removed and 4.2.2 added
 * V2.0.1   26-Oct-2016    : MemMap was changed according to #ARDAABD-474
 * V2.0.2   09-Jul-2018    : Following changes are made:
 *                           1. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 *                           2. As part #ARDAABD-3905, traceability
 *                              has been updated by mapping respective
 *                              WDG_ESDD_UD IDs.
 *                           3. As part of JIRA ARDAABD-3881, following changes
 *                              are made:
 *                           a. Copyright information updated.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERB_IRQ_H
#define WDG_59_DRIVERB_IRQ_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/*
 * Included for module version information from Wdg_59_DriverB.h and macro
 * definitions required for Wdg_59_DriverB_Irq.c
 */
#include "Wdg_59_DriverB_PBTypes.h"
/* Included for global variable visibility for Wdg_59_DriverB_Irq.c */
#include "Wdg_59_DriverB_Ram.h"
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERB_IRQ_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERB_IRQ_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERB_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERB_IRQ_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERB_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERB_IRQ_SW_MAJOR_VERSION    WDG_59_DRIVERB_SW_MAJOR_VERSION
#define WDG_59_DRIVERB_IRQ_SW_MINOR_VERSION    WDG_59_DRIVERB_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define WDG_59_DRIVERB_START_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERB_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERB_TRIGGERFUNCTION_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, WDG_59_DRIVERB_FAST_CODE)
                                 WDG_59_DRIVERB_TRIGGERFUNCTION_ISR(void);
#endif

/*Service ID of Trigger Funtion ISR API */
#define WDG_59_DRIVERB_TRIGGER_FUNCTION_ISR_SID   (uint8)0x06


/* WDG_59_DRIVERB_IRQ_H_001: WDG_ESDD_UD_030                               */
#if (WDG_59_DRIVERB_ERR_MODE_SET == WDG_59_DRIVERB_NMI_MODE)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERB_ERROR_CAT2_ISR) || \
                                        defined (WDG_59_DRIVERB_ERROR_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, WDG_59_DRIVERB_FAST_CODE)
                                           WDG_59_DRIVERB_ERROR_ISR(void);
#endif
#endif
#define WDG_59_DRIVERB_STOP_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

#endif /* WDG_59_DRIVERB_IRQ_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
