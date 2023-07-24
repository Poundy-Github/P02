/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Internal Watchdog Driver A Component                    */
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
 * V2.0.2   14-Dec-2016    : Fusa added according to #ARDAABD-568
 * V2.0.3   16-Jan-2017    : Updated after code review
 *                           Write-Verify handling was changed
 * V2.0.4   13-Feb-2017    : #ARDAABD-911
 *                           1. Use common approach for macros used for writing
 *                              registers with write-verify and/or
 *                              HW consistency check options
 *                           #ARDAABD-832
 *                           1. Solved QAC 4:3410, enclosed (uiRegWriteValue)
 * V2.0.5   14-Feb-2017    : #ARDAABD-568
 *                           1. Defined proper mask values
 * V2.0.6   20-Feb-2017    : #ARDAABD-568
 *                           1. Updated function banners
 * V2.0.1   01-Mar-2017    : #ARDAABD-832
 *                           1. Removed definition of WDG_59_DRIVERA_INIT_VAL
 * V2.0.2   13-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.3   15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.0.4   15-Jun-2017    : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.0.5   06-Jul-2017    : Following changes are made:
 *                           1. As part of ARDAABD-1523 Jira ticket,function
 *                              Wdg_59_DriverA_TriggerFunc is modified.
 *                           2. As per JIRA ARDAABD-1832, new API
 *                             'Wdg_59_DriverA_InitDetCheck' is added to
 *                              check the errors during WDG initialisation.
 * V2.0.6   16-Nov-2017    : Following changes are made:
 *                           1. As part of ARDAABD-2266 Jira ticket,
 *                              a. WDG_59_DriverA_WDTAReg_BaseAddr is renamed to
 *                                 WDG_59_DriverA_GpWDTAReg_BaseAddr.
 *                              b. LenReturnStatus is renamed to LddReturnStatus
 *                           2. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 * V2.0.7   06-Aug-2018   : Following changes are made:
 *                          1. As part of merging activity, #ARDAABD-3474
 *                             Register details updated in function banner.
 *                             Ref:ARDAABD-2917.
 *                          2. As per JIRA ARDAABD-3728,
 *                             Memory mapping of 'Wdg_59_DriverA_InitDetCheck'
 *                             API is modified to
 *                             WDG_59_DRIVERA_START/STOP_SEC_PRIVATE_CODE.
 *                          3. As part #ARDAABD-3905, traceability
 *                             has been updated by mapping respective
 *                             WDG_ESDD_UD IDs.
 *                          4. As part of reqtify activity, traceability has
 *                              been modified by mapping repective MRS IDs.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements: WDG_ESDD_UD_072, WDG_ESDD_UD_004                               */
/* Implements: WDG061, SWS_Wdg_00061                                          */
/* Included for type definitions and macros */
#include "Wdg_59_DriverA_PBTypes.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Private.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* Implements: WDG_ESDD_UD_042                                                */
/* Implements: WDG080, SWS_Wdg_00179                                          */
/* Implements: EAAR_PN0064_FR_0034, EAAR_PN0064_FR_0035, EAAR_PN0064_FR_0050  */
/* Implements: IMP_F1x_V3.03.06_WDG_RS_1, EAAR_PN0034_FR_0067                 */
/* Implements: BSW00409                                                       */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* Implements: WDG087, SWS_Wdg_0086                                           */
/* Implements: BSW004, BSW167, SRS_BSW_00004                                  */
/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION \
                                           WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION \
                                           WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/* Functionality related to R4.0 and R4.2 */
#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION != \
                                     WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION != \
                                      WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_TriggerFunc
**
** Service ID            : Not Applicable
**
** Description           : This service is used to trigger the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : LblCriticalSectionFlag
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GaaRamMirror,
**                         WDG_59_DriverA_GpWDTAReg_BaseAddr.
**
** Functions Invoked     : WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
**
** Registers Used        : WDTAnEVAC, WDTAnREF, WDTAnWDTE.
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

/* Implements: WDG_ESDD_UD_054                                                */
/* Implements: WDG144, SWS_Wdg_00144                                          */
/* Implements: WDG093, SWS_Wdg_00093                                          */
/* Implements: BSW12019, SRS_Wdg_12019, SRS_Wdg_00144                         */
FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc
   (boolean LblCriticalSectionFlag)
{
#if (WDG_59_DRIVERA_VAC_ALLOWED == STD_ON)
  uint8 LucEVAC;
#endif
  /* Functionality related to R4.0 and R4.2 */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as busy */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
  #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */

  /* Check if critical section protection is required */
  /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                             */
  /* Implements: EAAR_PN0034_FR_0030                                          */
  /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040                 */
  /* Implements: BSW12019, SRS_Wdg_12019                                      */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  if (LblCriticalSectionFlag != WDG_59_DRIVERA_EXCLUDE_CRITICAL_SECTION)
  {
    WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(WDG_59_DRIVERA_TRIGG_PROTECTION);
  }
  else
  {
    /* Do Nothing */
  }
  #endif

  /* Implements: WDG_ESDD_UD_016, WDG_ESDD_UD_017     */
  /* Check whether Varying Activation Code is enabled */
  #if (WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF)

  /* Initialize the register with preconfigured value */

  WDG_59_DRIVERA_WRITE_REG_AND_MIRROR(
  (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucWDTE),
  (WDG_59_DRIVERA_RESTART),
  (&Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_WDTE_IDX]))

  WDG_59_DRIVERA_CHECK_WRITE_VERIFY_INIT(
  (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucWDTE),
  (WDG_59_DRIVERA_RESTART), WDG_59_DRIVERA_MASK_FIRST_8_BITS,
                                              WDG_59_DRIVERA_TRIGGERFUNC_API_ID)

  #else
  /* WDTAReg_BaseAddr->ucREF changes its value each time the EVAC register is
   * written */
   LucEVAC = WDG_59_DRIVERA_RESTART -WDG_59_DriverA_GpWDTAReg_BaseAddr->ucREF;

   WDG_59_DRIVERA_WRITE_REG_AND_MIRROR(
   (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucEVAC),
   (LucEVAC),
   (&Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_EVAC_IDX]))

   WDG_59_DRIVERA_CHECK_WRITE_VERIFY_INIT(
   (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucEVAC),
   (LucEVAC), WDG_59_DRIVERA_MASK_FIRST_8_BITS,
                                              WDG_59_DRIVERA_TRIGGERFUNC_API_ID)


  #endif /* WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF */

  /* Check if critical section protection is required */
  /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                             */
  /* Implements: EAAR_PN0034_FR_0030                                          */
  /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040                 */
  /* Implements: BSW12019, SRS_Wdg_12019                                      */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  if (LblCriticalSectionFlag != WDG_59_DRIVERA_EXCLUDE_CRITICAL_SECTION)
  {
    WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(WDG_59_DRIVERA_TRIGG_PROTECTION);
  }
  else
  {
    /* Do Nothing */
  }
  #endif

  /* Functionality related to R4.0 and R4.2 */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as idle */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
  #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */

}
#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include WDG_MEMMAP_FILE

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_InitDetCheck
**
** Service ID            : NA
**
** Description           : This function checks errors during WDG
**                         initialisation.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : LddReturnStatus
**
** Preconditions         : DET error detection shall be enabled
**
** Global Variables      : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
#include WDG_MEMMAP_FILE

/* Function to check that the (hardware specific) contents of the
 * given configuration set is within the allowed boundaries.
 */
/* Implements EAAR_PN0034_FR_0064,EAAR_PN0034_FR_0049,WDG_ESDD_UD_062 */
/* Implements: WDG_ESDD_UD_059                                        */
FUNC(Std_ReturnType, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_InitDetCheck
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr)
{
  Std_ReturnType LddReturnStatus ;
  LddReturnStatus = E_OK;

  /* Check if WDG default mode is out of range*/
  if ((WDGIF_OFF_MODE  != ConfigPtr->ddWdtamdDefaultMode ) &&
      (WDGIF_SLOW_MODE  != ConfigPtr->ddWdtamdDefaultMode ) &&
      (WDGIF_FAST_MODE  != ConfigPtr->ddWdtamdDefaultMode ))
  {
    LddReturnStatus = E_NOT_OK;
  }
  /* Check If 75% interrupt (WIE bit-field) is disabled */
  else if ((((uint8)((ConfigPtr->ucWdtamdDefaultValue & WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == WDG_59_DRIVERA_ZERO)
          &&(ConfigPtr->ucWdtamdDefaultValue != (uint8)WDGIF_OFF_MODE))||
          ((uint8)((ConfigPtr->ucWdtamdSlowValue & WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == WDG_59_DRIVERA_ZERO)   ||
          ((uint8)((ConfigPtr->ucWdtamdFastValue & WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == WDG_59_DRIVERA_ZERO))
  {
    LddReturnStatus = E_NOT_OK;
  }

  else
  {
    /* No error */
  }
  return LddReturnStatus;
}
#define WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
#include WDG_MEMMAP_FILE
#endif


/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
