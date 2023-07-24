/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverB_Irq.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver B Component                                */
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
 * V2.0.0   06-Sep-2016    : ASR 4.2.2 Release #ARDAABD-653
 * V2.0.1   26-Oct-2016    : Version fix
 * V2.0.2   16-Jan-2017    : Tabs were removed
 * V2.0.3   17-Jan-2017    : WDG_59_DRIVERB_E_MODE_FAILED_REPORTING check added
 * V2.0.4   23-Feb-2017    : #ARDAABD-568
 *                           1. Removed WDG_59_DRIVERB_DEM_TYPE and
 *                           WDG_59_DRIVERB_DEM_TYPE macro definition.
 *                           Macro usage was related to Autosar 3.2.2.
 * V2.0.5   13-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.6   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.7   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.0.8   06-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1523 Jira ticket,function
 *                             'Wdg_59_DriverB_TriggerFunc' is modified.
 *                           2. As part of ARDAABD-1830 Jira Ticket,
 *                              Extended Production errors are implented for
 *                              Fail and Pass Detection Criteria.
 * V2.0.9   05-Oct-2019    : Following changes are made:
 *                           1. As part of ARDAABD-2266 Jira ticket,
 *                              a. Wdg_59_DriverB_GusTiggerCounter is renamed to
 *                                 Wdg_59_DriverB_GusTriggerCounter.
 *                           2. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 *                           3. As part #ARDAABD-3905, traceability
 *                              has been updated by mapping respective
 *                              WDG_ESDD_UD IDs.
 *                           4. Copyright information is updated.
 *                           5. As part of reqtify activity, traceability has
 *                              been modified by mapping repective MRS IDs.
 *                           6. Delete the exist Tab in the comment.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements: WDG_ESDD_UD_048, WDG_ESDD_UD_049, WDG_ESDD_UD_072              */
/* Implements: WDG061, WDG079                                                 */
/* Implements: SWS_Wdg_00061, SWS_Wdg_00079                                   */
/* Implements: BSW00345, BSW159, BSW00381, BSW00412, BSW00346, BSW158         */
/* Implements: BSW00370, BSW00435, BSW00436, BSW00301, BSW00380, BSW00314     */
/* Implements: SRS_BSW_00345, SRS_BSW_00159, SRS_BSW_00381, SRS_BSW_00412     */
/* Implements: SRS_BSW_00346, SRS_BSW_00158, SRS_BSW_00301                    */
/* Implements: BSW12263                                                       */
/* Implements: SRS_BSW_00314, SRS_SPAL_12263*/

/* Included for ISR functions declaration */
#include "Wdg_59_DriverB_Irq.h"
/* Implements: WDG_ESDD_UD_042, WDG_ESDD_UD_004                               */
/* Implements: WDG080                                                         */
/* Implements: SWS_Wdg_00179                                                  */
/* Implements: EAAR_PN0064_FR_0034, EAAR_PN0064_FR_0035, EAAR_PN0064_FR_0050  */
/* Implements: IMP_F1x_V3.03.06_WDG_RS_1, EAAR_PN0034_FR_0067                 */
/* Implements: BSW00409                                                       */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for declaration of the function Wdg_59_DriverB_TriggerFunc() */
#include "Wdg_59_DriverB_Private.h"
#if (WDG_59_DRIVERB_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverB.h"
#endif
/* Included for type definitions and macros */
#include "Wdg_59_DriverB_PBTypes.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERB_IRQ_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERB_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERB_IRQ_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERB_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERB_IRQ_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERB_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define WDG_59_DRIVERB_IRQ_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERB_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERB_IRQ_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERB_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements: WDG087, SWS_Wdg_0086                                           */
/* Implements: BSW004, BSW167, SRS_BSW_00004                                  */
/* Functionality related to R4.0.3 and R4.2.2 */
#if (WDG_59_DRIVERB_IRQ_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERB_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverB_Irq.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERB_IRQ_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERB_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverB_Irq.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERB_IRQ_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERB_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverB_Irq.c : Mismatch in Release Revision Version"
#endif


#if (WDG_59_DRIVERB_IRQ_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERB_IRQ_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverB_Irq.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERB_IRQ_SW_MINOR_VERSION != \
                                         WDG_59_DRIVERB_IRQ_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverB_Irq.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : WDG_59_DRIVERB_TRIGGERFUNCTION_ISR
**
** Service ID            : NA
**
** Description           : This is 75 % Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverB_GusTriggerCounter.
**
** Functions Invoked     : Wdg_59_DriverB_TriggerFunc
**
** Registers Used        : None
*******************************************************************************/
#define WDG_59_DRIVERB_START_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

/* Implements: WDG_ESDD_UD_009, WDG_ESDD_UD_057, WDG_ESDD_UD_058              */
/* Implements: WDG134, WDG135, WDG166                                         */
/* Implements: SWS_Wdg_00134, SWS_Wdg_00135, SWS_Wdg_00166                    */
/* Implements: BSW12019, SRS_Wdg_12019                                        */
/* Implements: AR_PN0064_NR_0018, EAAR_PN0064_FR_0035, EAAR_PN0064_FR_0031    */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERB_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERB_TRIGGERFUNCTION_CAT2_ISR)
ISR(WDG_59_DRIVERB_TRIGGERFUNCTION_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, WDG_59_DRIVERB_FAST_CODE)
                                  WDG_59_DRIVERB_TRIGGERFUNCTION_ISR(void)
#endif
{
  /* Check if the trigger counter has completed the timeout value requested */
  if (Wdg_59_DriverB_GusTriggerCounter > WDG_59_DRIVERB_ZERO)
  {
    /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                           */
    /* Implements: EAAR_PN0034_FR_0030                                        */
    /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040               */
    /* Implements: BSW12019, SRS_Wdg_12019                                    */
    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERB_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERB_ENTER_CRITICAL_SECTION(WDG_59_DRIVERB_TRIGG_PROTECTION);
    #endif

    /* Decrement the trigger counter */
    Wdg_59_DriverB_GusTriggerCounter--;

    /* Check if critical section protection is required */
    /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                           */
    /* Implements: EAAR_PN0034_FR_0030                                        */
    /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040               */
    /* Implements: BSW12019, SRS_Wdg_12019                                    */
    #if (WDG_59_DRIVERB_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERB_EXIT_CRITICAL_SECTION(WDG_59_DRIVERB_TRIGG_PROTECTION);
    #endif

    /* Restart the WDG hardware */
    Wdg_59_DriverB_TriggerFunc(WDG_59_DRIVERB_INCLUDE_CRITICAL_SECTION);
  }
  else
  {
    /* No action required */
  }

}

#define WDG_59_DRIVERB_STOP_SEC_CODE_FAST
#include WDG_MEMMAP_FILE


/*******************************************************************************
** Function Name         : WDG_59_DRIVERB_ERROR_ISR
**
** Service ID            : NA
**
** Description           : This is NMI Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverB_GddCurrentMode.
**
** Functions Invoked     : Dem_ReportErrorStatus.
**
** Registers Used        : None
*******************************************************************************/
/* Implements: WDG_ESDD_UD_030                             */
#if (WDG_59_DRIVERB_ERR_MODE_SET == WDG_59_DRIVERB_NMI_MODE)
#define WDG_59_DRIVERB_START_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERB_ERROR_CAT2_ISR) || \
                                        defined (WDG_59_DRIVERB_ERROR_CAT2_ISR)
ISR(WDG_59_DRIVERB_ERROR_CAT2_ISR)
#else
/* Defines the CAT1 interrupt mapping */
_INTERRUPT_ FUNC(void, WDG_59_DRIVERB_FAST_CODE)
                                            WDG_59_DRIVERB_ERROR_ISR(void)
#endif
{
  if (WDGIF_OFF_MODE != Wdg_59_DriverB_GddCurrentMode)
  {
    /* Report Error to DEM */
    /* Implements: WDG_ESDD_UD_011                                          */  
    Dem_ReportErrorStatus(WDG_59_DRIVERB_E_TRIGGER_TIMEOUT,
                              (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
    #if ((WDG_59_DRIVERB_AR_VERSION == WDG_59_DRIVERB_AR_HIGHER_VERSION)&& \
                      (WDG_59_DRIVERB_E_MODE_FAILED_REPORTING == STD_ON))
    Dem_ReportErrorStatus(WDG_59_DRIVERB_E_MODE_FAILED,
                             (Dem_EventStatusType) DEM_EVENT_STATUS_PASSED);
    #endif
  }
  else
  {

    /* Functionality related to R4.0 and R4.2 */
    /* Report Error to DEM */
    /* Implements: WDG_ESDD_UD_052                                            */
    /* Implements: EAAR_PN0064_FR_0010, EAAR_PN0064_FR_0005                   */
    /* Implements: EAAR_PN0064_FR_0007, EAAR_PN0064_FR_0020                   */
    /* Implements: WDG016, SWS_Wdg_00016                                      */
    /* Implements: BSW12064, SRS_SPAL_12064                                   */

#if ( WDG_59_DRIVERB_E_MODE_FAILED_REPORTING == STD_ON)
    Dem_ReportErrorStatus(WDG_59_DRIVERB_E_MODE_FAILED,
                             (Dem_EventStatusType) DEM_EVENT_STATUS_FAILED);
#endif
  }
}
#define WDG_59_DRIVERB_STOP_SEC_CODE_FAST
#include WDG_MEMMAP_FILE
#endif /* #if (WDG_59_DRIVERB_ERR_MODE_SET == WDG_59_DRIVERB_NMI_MODE) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
