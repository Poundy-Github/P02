/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Watchdog Driver A Component                             */
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
 *
 * V1.0.1:  21-Dec-2015    : As per ARDAAGA-82 following changes has been done:
 *                           1. Wdg_59_DriverA_GetVersionInfo is implemented
 *                              as a function.
 * V2.0.0   06-Sep-2016    : ASR 4.2.2 Release #ARDAABD-653
 * V2.1.0   26-Oct-2016    : Fusa added according to #ARDAABD-568
 * V2.1.1   14-Dec-2016    : Fusa added according to #ARDAABD-568 - fix
 * V2.1.2   16-Jan-2017    : Changed after code review
 *                           Wdg_59_DriverA_CheckHWConsistency was updated
 *                           Write-Verify handling was changed
 * V2.1.3   27-Jan-2017    : 1. RAM Mirroring check was updated
 *                           2. WDG_59_DRIVERA_CHECK_WRITE_VERIFY_RUNTIME added
 *                           3. WDG_59_DRIVERA_E_PARAM_CONFIG DEM reported when
 *                           Wdg_59_DriverA_CheckHWConsistency is called with
 *                           invalid parameter
 * V2.1.4   13-Feb-2017    : #ARDAABD-911
 *                           1. Use common approach for macros used for writing
 *                              registers with write-verify and/or
 *                              HW consistency check options
 *                           #ARDAABD-832
 *                           1. Solved QAC 4:3410, enclosed (uiRegWriteValue)
 * V2.1.5   14-Feb-2017    : #ARDAABD-568
 *                           1. Defined proper masks values
 * V2.1.6   20-Feb-2017    : #ARDAABD-568
 *                           1. Updated ucMD register wrtting value
 * V2.1.7   23-Feb-2017    : #ARDAABD-568
 *                           1. Removed WDG_59_DRIVERA_DEM_TYPE and
 *                           WDG_59_DRIVERA_DEM_TYPE macro definition.
 *                           Macro usage was related to Autosar 3.2.2.
 * V2.1.8   01-Mar-2017    : #ARDAABD-832
 *                           1. Removed definition of WDG_59_DRIVERA_INIT_VAL
 * V2.1.9   13-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.1.10  15-Mar-2017    : #ARDAABD-1207
 *                           Traceability update
 * V2.1.11   15-Jun-2017   : As part of ARDAABD-1897 Jira ticket, code was
 *                           updated after QAC analysis
 * V2.1.12   06-Jul-2017   : Following changes are made:
 *                           1. As part of ARDAABD-1523 Jira ticket,
 *                              a. Wdg_59_DriverA_Init API is modified to remove
 *                                 Enter and Exit critical sections from module
 *                                 initialization.
 *                              b. APIs Wdg_59_DriverA_Init,
 *                                 Wdg_59_DriverA_SetMode are modified to
 *                                 adopt changes done in API
 *                                 Wdg_59_DriverA_TriggerFunc.
 *                           2. As part of ARDAABD-1832 Jira ticket,
 *                             'Wdg_59_DriverA_Init' API is updated to add
 *                              DET reporting for the error
 *                              'WDG_59_DRIVERA_E_PARAM_CONFIG'.
 *                           3. As part of ARDAABD-1830 Jira Ticket,
 *                              Extended Production errors are implented for
 *                              Fail and Pass Detection Criteria.
 * V2.1.13   16-Nov-2017   : Following changes are made:
 *                           1. As part of ARDAABD-2266 Jira ticket,
 *                              a. Wdg_59_DriverA_GusTiggerCounter is renamed to
 *                                 Wdg_59_DriverA_GusTriggerCounter.
 *                              b. WDG_59_DriverA_IMR_BaseAddr is renamed to
 *                                 WDG_59_DriverA_GpIMR_BaseAddr.
 *                              c. WDG_59_DriverA_WDTAReg_BaseAddr is renamed to
 *                                 WDG_59_DriverA_GpWDTAReg_BaseAddr.
 *                              d. LenReturnValue is renamed to LddReturnValue
 *                                 as this was an derived datatype.
 *                           2. As part of ARDAABD-2734 Jira Ticket,
 *                              variable MEMMAP_FILE is changed to
 *                              WDG_MEMMAP_FILE.
 * V2.1.14   22-May-2018   : As part of ARDAABD-3707,
 *                           Following changes are made:
 *                           1. Add RH850_DUMMY_READ_SYNCP(16, ICP0) to fix the
 *                              fault synchronization at the timing when control
 *                              shifts from MCAL to application
 * V2.1.15   09-Jul-2018   : Following changes are made:
 *                           1. As part of merging activity, #ARDAABD-3474
 *                           a. 'RH850_SV_MODE_IMR_xxx' macros are removed
 *                              and interrupts are enabled using
 *                              'RH850_SV_MODE_ICR_xxx' macros in
 *                              'Wdg_59_DriverA_Init' API,Ref:ARDAABD-2158.
 *                           b. Register details updated in function banner.
 *                           2. As part #ARDAABD-3905, traceability
 *                              has been updated by mapping respective
 *                              WDG_ESDD_UD IDs.
 *                           3. As part of reqtify activity, traceability has
 *                              been modified by mapping repective MRS IDs.
 * V2.1.16: 05-Oct-2018    : Following changes are done : 
 *                           1. As part of ARDAABD-3707, ICP0 usage error
 *                              modified RH850_DUMMY_READ_SYNCP(16, ICP0)  to 
 *                              RH850_DUMMY_READ_SYNCP(16, &(ICP0))
 * V2.1.17: 19-Oct-2018    : As part of ARDAABD-3707
 *                            Remove the RH850_DUMMY_READ_SYNCP Marco
 * V2.1.18: 05-Oct-2019    : Following changes are done : 
 *                           1. As part of ARDAABD-4060
 *                              In function Wdg_59_DriverA_SetMode changed, 
 *                              So that when DEM_EVENT_STATUS_FAILED
 *                              occurs and LddReturnValue = E_NOT_OK;
 *                              the subsequent series of actions are 
 *                              no longer performed.
 *                           2. Delete the exist Tab in the comment. 
 */
/******************************************************************************/

/*******************************************************************************
**                      General Traceability Section                          **
*******************************************************************************/
/* Implements: WDG_ESDD_UD_072, WDG_ESDD_UD_005                               */
/* Implements: WDG061, SWS_Wdg_00061                                          */

/* Implements: WDG_ESDD_UD_001, WDG_ESDD_UD_002, WDG_ESDD_UD_004              */
/* Implements: WDG_ESDD_AD_001 MEMMAP022, WDG_ESDD_AWDG_D_002 COMPILER040     */
/* Implements: EAAR_PN0064_FR_0002, EAAR_PN0064_FR_0008, EAAR_PN0064_FR_0029  */
/* Implements: EAAR_PN0064_FR_0030, EAAR_PN0064_FR_0006, EAAR_PN0064_FR_0007  */
/* Implements: EAAR_PN0064_FR_0060, EAAR_PN0064_FR_0006, EAAR_PN0064_FR_0061  */

/* Implements: EAAR_PN0034_FR_0045, EAAR_PN0034_NR_0007, EAAR_PN0034_FR_0052  */
/* Implements: EAAR_PN0034_NR_0062, EAAR_PN0034_FR_0039, EAAR_PN0034_NR_0066  */
/* Implements: EAAR_PN0034_NR_0042, EAAR_PN0034_NR_0046, EAAR_PN0034_NR_0048  */
/* Implements: EAAR_PN0034_FR_0037, EAAR_PN0034_FR_0063, EAAR_PN0034_NR_0029  */
/* Implements: EAAR_PN0034_FR_0043, EAAR_PN0034_NR_0061, EAAR_PN0034_NR_0001  */
/* Implements: EAAR_PN0034_NR_0044, EAAR_PN0034_NR_0015, EAAR_PN0034_FR_0004  */
/* Implements: EAAR_PN0034_NR_0020, EAAR_PN0034_NR_0073, EAAR_PN0034_NR_0075  */
/* Implements: EAAR_PN0034_FR_0066, EAAR_PN0034_NR_0016, EAAR_PN0034_NR_0025  */
/* Implements: EAAR_PN0034_FR_0046, EAAR_PN0034_NR_0023, EAAR_PN0034_FR_0002  */
/* Implements: EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0020, EAAR_PN0034_FR_0026  */
/* Implements: EAAR_PN0034_NR_0006, EAAR_PN0034_NR_0012, EAAR_PN0034_FR_0041  */
/* Implements: EAAR_PN0034_FR_0080, EAAR_PN0034_NR_0054, EAAR_PN0034_FR_0065  */
/* Implements: EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0006  */
/* Implements: EAAR_PN0034_NR_0063, EAAR_PN0034_FR_0060, EAAR_PN0034_NR_0045  */
/* Implements: EAAR_PN0034_FR_0008, EAAR_PN0034_NR_0043, EAAR_PN0034_NR_0018  */
/* Implements: EAAR_PN0034_NR_0002, EAAR_PN0034_FR_0056, EAAR_PN0034_NR_0019  */
/* Implements: EAAR_PN0034_NR_0069, EAAR_PN0034_FR_0054, EAAR_PN0034_FR_0038  */
/* Implements: EAAR_PN0034_FR_0055, EAAR_PN0034_NR_0036, EAAR_PN0034_NR_0071  */
/* Implements: EAAR_PN0034_FR_0005, EAAR_PN0034_NR_0008, EAAR_PN0034_FR_0023  */
/* Implements: EAAR_PN0034_NR_0056, EAAR_PN0034_FR_0042, EAAR_PN0034_FR_0048  */
/* Implements: EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0010, EAAR_PN0034_FR_0019  */
/* Implements: EAAR_PN0034_NR_0028, EAAR_PN0034_NR_0030, EAAR_PN0034_NR_0037  */
/* Implements: EAAR_PN0034_NR_0024, EAAR_PN0034_FR_0007, EAAR_PN0034_NR_0006  */
/* Implements: EAAR_PN0034_FR_0058, EAAR_PN0034_FR_0024, EAAR_PN0034_NR_0039  */
/* Implements: EAAR_PN0034_NR_0021, EAAR_PN0034_FR_0062, EAAR_PN0034_FR_0083  */
/* Implements: EAAR_PN0034_NR_0026, EAAR_PN0034_FR_0053, EAAR_PN0034_FR_0047  */
/* Implements: EAAR_PN0034_NR_0064, EAAR_PN0034_NR_0022, EAAR_PN0034_NR_0011  */
/* Implements: EAAR_PN0034_FR_0068, EAAR_PN0034_FR_0067                       */

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Implements: WDG_ESDD_UD_051                                                */
/* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009                       */
/* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024                       */
/* Implements: WDG161, WDG106, WDG001, WDG100, WDG101, WDG025                 */
/* Implements: WDG090, WDG019, WDG095, WDG173, WDG089                         */
/* Implements: SWS_Wdg_00161, SWS_Wdg_00106, SWS_Wdg_00001, SWS_Wdg_00100     */
/* Implements: SWS_Wdg_00101, SWS_Wdg_00025, SWS_Wdg_00173, SWS_Wdg_00090     */
/* Implements: SWS_Wdg_00019, SWS_Wdg_00095, SWS_Wdg_00010                    */

/* Implements: WDG_ESDD_UD_052                                                */
/* Implements: EAAR_PN0064_FR_0010, EAAR_PN0064_FR_0005                       */
/* Implements: EAAR_PN0064_FR_0007, EAAR_PN0064_FR_0020                       */
/* Implements: WDG107, WDG160, WDG051, WDG145, WDG103, WDG016, WDG026, WDG091 */
/* Implements: WDG092, WDG017, WDG018, WDG169                                 */
/* Implements: SWS_Wdg_00107, SWS_Wdg_00107, SWS_Wdg_00051, SWS_Wdg_00160     */
/* Implements: SWS_Wdg_00091, SWS_Wdg_00092, SWS_Wdg_00145, SWS_Wdg_00103     */
/* Implements: SWS_Wdg_00016, SWS_Wdg_00026, SWS_Wdg_00017, SWS_Wdg_00018     */

/* Included for Wdg_59_DriverA.h inclusion and macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Implements: WDG_ESDD_UD_041                                                */
/* Implements: WDG010, WDG063, WDG013, WDG089                                 */
/* Implements: SWS_Wdg_00010                                                  */
/* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                    */
/* Implements: SRS_BSW_00327, SRS_BSW_00331                                   */

/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* Implements: WDG_ESDD_UD_042                                                */
/* Implements: WDG080, WDG062, WDG150_Conf, WDG065, WDG110                    */
/* Implements: SWS_Wdg_00179                                                  */
/* Implements: EAAR_PN0064_FR_0034, EAAR_PN0064_FR_0035, EAAR_PN0064_FR_0050  */
/* Implements: IMP_F1x_V3.03.06_WDG_RS_1, EAAR_PN0034_FR_0067                 */
/* Implements: BSW00409                                                       */

/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
/* Included for declaration of the function Wdg_59_DriverA_TriggerFunc() */
#include "Wdg_59_DriverA_Private.h"
/* Included for declaration of the SV enabled registers write operation */
#include "rh850_Types.h"
#include "Iocommon_Defines.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* Functionality related to R4.0 and R4.2 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define WDG_59_DRIVERA_C_SW_MAJOR_VERSION  1
#define WDG_59_DRIVERA_C_SW_MINOR_VERSION  0
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements: WDG087, SWS_Wdg_0086                                           */
/* Implements: BSW004, BSW167, SRS_BSW_00004                                  */
/* Functionality related to R4.0 and R4.2 */
#if (WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Minor Version"

#endif

#if (WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION != \
                                   WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Revision Version"
#endif


#if (WDG_59_DRIVERA_SW_MAJOR_VERSION != WDG_59_DRIVERA_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_SW_MINOR_VERSION != WDG_59_DRIVERA_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0310)-1 and                           */
/*                 END Msg(4:0310)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION::                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */
/******************************************************************************/
/**                      Function Definitions                                **/
/******************************************************************************/

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_GetVersionInfo
**
** Service ID            : 0x04
**
** Description           : This API returns the version information of Watchdog
**                         driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : versioninfo
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
*******************************************************************************/
#if (WDG_59_DRIVERA_VERSION_INFO_API == STD_ON)
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE
/* Implements: WDG_ESDD_UD_060                                           */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_59_DRIVERA_APPL_DATA)versioninfo)
{

  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Check if parameter passed is equal to Null pointer */
    if (NULL_PTR == versioninfo)
    {
      /* Report to DET  */
      (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID,
                            WDG_59_DRIVERA_INSTANCE_ID,
                            WDG_59_DRIVERA_GETVERSIONINFO_SID,
                            WDG_59_DRIVERA_E_PARAM_POINTER);
    }
    else
  #endif /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Copy the vendor Id */
      (versioninfo)->vendorID = (uint16)WDG_59_DRIVERA_VENDOR_ID;
      /* Copy the module Id */
      (versioninfo)->moduleID = (uint16)WDG_59_DRIVERA_MODULE_ID;
      /* Copy Software Major Version */
      (versioninfo)->sw_major_version = WDG_59_DRIVERA_SW_MAJOR_VERSION;
      /* Copy Software Minor Version */
      (versioninfo)->sw_minor_version = WDG_59_DRIVERA_SW_MINOR_VERSION;
      /* Copy Software Patch Version */
      (versioninfo)->sw_patch_version = WDG_59_DRIVERA_SW_PATCH_VERSION;
    }


}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE
#endif /* (WDG_59_DRIVERA_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_Init
**
** Service ID            : 0x00
**
** Description           : This service initialize the Watchdog driver and
**                         hardware.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr Pointer to the configuration
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GpConfigPtr,
**                         Wdg_59_DriverA_GusTriggerCounter,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GaaRamMirror,
**                         WDG_59_DriverA_GpICR_BaseAddr,
**                         WDG_59_DriverA_GpWDTAReg_BaseAddr.
** Functions Invoked     : Det_ReportError,
**                         Wdg_59_DriverA_TriggerFunc.
**                         Wdg_59_DriverA_InitDetCheck.
**
** Registers Used        : ICxxx, WDTAnMD, WDTAnEVAC, WDTAnREF, WDTAnWDTE.
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/* Implements: WDG_ESDD_UD_051, WDG_ESDD_UD_060, EAAR_PN0034_FSR_0002         */
/* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009, EAAR_PN0034_FSR_0004 */
/* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024, EAAR_PN0034_FSR_0001 */
/* Implements: WDG106, WDG161, WDG001, WDG100, WDG101, WDG025, WDG173         */
/* Implements: WDG090, WDG019, WDG095, EAAR_PN0034_FSR_0003                   */
/* Implements: SWS_Wdg_00106, SWS_Wdg_00161, SWS_Wdg_00001, SWS_Wdg_00100     */
/* Implements: SWS_Wdg_00101, SWS_Wdg_00025, SWS_Wdg_00173, SWS_Wdg_00090     */
/* Implements: SWS_Wdg_00019, SWS_Wdg_00095, SWS_Wdg_00010                    */

FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Init
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr)
{
  uint8 LucMD;

/* Implements: WDG_ESDD_UD_042                                                */
/* Implements: WDG080, WDG062, WDG150_Conf, WDG065, WDG110                    */
/* Implements: SWS_Wdg_00179                                                  */
/* Implements: EAAR_PN0064_FR_0034, EAAR_PN0064_FR_0035, EAAR_PN0064_FR_0050  */
/* Implements: IMP_F1x_V3.03.06_WDG_RS_1, EAAR_PN0034_FR_0067                 */
/* Implements: BSW00409                                                       */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

  /* Implements: WDG_ESDD_UD_051                                              */
  /* Implements: WDG089, SWS_Wdg_00010                                        */
  /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                  */
  /* Implements: SRS_BSW_00327, SRS_BSW_00331                                 */
  /* Report Error to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements: WDG111, SWS_Wdg_00111                                      */
    /* Report Error to DET */
    /* Functionality related to R4.0 */
    /* Implements: WDG_ESDD_UD_008                                            */
    /* Implements: WDG010, WDG064, WDG066                                     */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
    #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
     (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                       WDG_59_DRIVERA_INIT_SID, WDG_59_DRIVERA_E_PARAM_POINTER);

    /* Functionality related to R4.2 */
    /* Implements: WDG_ESDD_UD_043                                            */
    /* Implements: SWS_Wdg_00010                                              */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
    #elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
     (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                       WDG_59_DRIVERA_INIT_SID, WDG_59_DRIVERA_E_INIT_FAILED);
    #endif
  }
  else
  #endif /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    if (WDG_59_DRIVERA_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    {
      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      if (E_NOT_OK == Wdg_59_DriverA_InitDetCheck(ConfigPtr))
      {
          /* Report Error to DET */
        (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID,
                WDG_59_DRIVERA_INSTANCE_ID, WDG_59_DRIVERA_INIT_SID,
                    WDG_59_DRIVERA_E_PARAM_CONFIG);
      }
      else
      #endif
      {
        /* Assign the config pointer value to global pointer */
        Wdg_59_DriverA_GpConfigPtr = ConfigPtr;


        /* Functionality related to R4.0 and R4.2 */
        /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_025, WDG_ESDD_UD_036      */
        /* Implements: EAAR_PN0034_FR_0030                                    */
        /* Implements: WDG040, SWS_Wdg_00040                                  */
        /* Enable the 75 percent interrupt output */
        /* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0032,              */
        /* WDG_ESDD_UD_064                                                    */
        /* MISRA Violation: START Msg(4:0310)-1 */
        RH850_SV_MODE_ICR_AND(16, WDG_59_DriverA_GpICR_BaseAddr,
                                                 WDG_59_DRIVERA_INTWDTICR_MASK);
        /* END Msg(4:0310)-1 */
        /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_025, WDG_ESDD_UD_061      */
        /* Implements: EAAR_PN0034_FR_0030                                    */
        /* Implements: WDG040, SWS_Wdg_00040                                  */
        /* To check whether the default mode is not OFF mode */
        if (WDGIF_OFF_MODE != Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode)

        {
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025    */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                              */
          /* Implements: WDG_ESDD_UD_051                                      */
          /* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009             */
          /* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024             */
          /* Implements: WDG161, WDG106, WDG001, WDG100, WDG101, WDG025       */
          /* Implements: WDG090, WDG019, WDG095, WDG173, WDG089               */
          /* Implements: SWS_Wdg_00161, SWS_Wdg_00106, SWS_Wdg_00001          */
          /* Implements: SWS_Wdg_00100, SWS_Wdg_00101, SWS_Wdg_00025          */
          /* Implements: SWS_Wdg_00173, SWS_Wdg_00090, SWS_Wdg_00019          */
          /* Implements: SWS_Wdg_00095, SWS_Wdg_00010                         */
          /* Set Default mode value to Mode register */
          LucMD = (Wdg_59_DriverA_GpConfigPtr->ucWdtamdDefaultValue) |
          ((WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD) &
          WDG_59_DRIVERA_75INTERRUPT_MASK);

          WDG_59_DRIVERA_WRITE_REG_AND_MIRROR(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),(LucMD),
          (&Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_MD_IDX]))

          /* All MD bits are written by LucMD, so check the whole reg */
          WDG_59_DRIVERA_CHECK_WRITE_VERIFY_INIT(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),
          (LucMD), WDG_59_DRIVERA_MASK_FIRST_7_BITS, WDG_59_DRIVERA_INIT_SID)
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025    */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG040, SWS_Wdg_00040                                */
          /* Functionality related to R4.0 and R4.2 */
          /* Set the Initial trigger counter value */
          Wdg_59_DriverA_GusTriggerCounter =
                       Wdg_59_DriverA_GpConfigPtr->usInitTimerCountValue;

          /* Call the Trigger Function which restarts the Watchdog hardware */
          /* Implements: WDG_ESDD_UD_054                                      */
          /* Implements: WDG144, SWS_Wdg_00144                                */
          Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_EXCLUDE_CRITICAL_SECTION);
        }

        else
        {
          /* No action required */
        }

        /* Set current mode */
        Wdg_59_DriverA_GddCurrentMode =
                                Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode;

        /* Check if WDG_59_DRIVERA_DEV_ERROR_DETECT is enabled */
        #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
        /* Implements: WDG_ESDD_UD_051                                        */
        /* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009               */
        /* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024               */
        /* Implements: WDG161, WDG106, WDG001, WDG100, WDG101, WDG025         */
        /* Implements: WDG090, WDG019, WDG095, WDG173, WDG089                 */
        /* Implements: SWS_Wdg_00161, SWS_Wdg_00106, SWS_Wdg_00001            */
        /* Implements: SWS_Wdg_00100, SWS_Wdg_00101, SWS_Wdg_00025            */
        /* Implements: SWS_Wdg_00173, SWS_Wdg_00090, SWS_Wdg_00019            */
        /* Implements: SWS_Wdg_00095, SWS_Wdg_00010                           */
        /* Set the state of Watchdog as idle */
        Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
        #endif
      }
    } /* end of if (WDG_59_DRIVERA_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))*/
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Implements: WDG_ESDD_UD_051, WDG_ESDD_UD_040                         */
      /* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009                 */
      /* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024                 */
      /* Implements: WDG161, WDG106, WDG001, WDG100, WDG101, WDG025           */
      /* Implements: WDG090, WDG019, WDG095, WDG173, WDG089                   */
      /* Implements: SWS_Wdg_00161, SWS_Wdg_00106, SWS_Wdg_00001              */
      /* Implements: SWS_Wdg_00100, SWS_Wdg_00101, SWS_Wdg_00025              */
      /* Implements: SWS_Wdg_00173, SWS_Wdg_00090, SWS_Wdg_00019              */
      /* Implements: SWS_Wdg_00095, SWS_Wdg_00010                             */
      /* Report Error to DET */
      (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID,
      WDG_59_DRIVERA_INSTANCE_ID, WDG_59_DRIVERA_INIT_SID,
      WDG_59_DRIVERA_E_INVALID_DATABASE);
    } /* End of Check to check database */
    #endif
  }
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetMode
**
** Service ID            : 0x01
**
** Description           : This service change the mode of the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : WdgIf_ModeType  Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK or E_NOT_OK
**
** Preconditions         : Wdg_59_DriverAInit must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GpConfigPtr,
**                         Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GaaRamMirror,
**                         Wdg_59_DriverA_GusTriggerCounter,
**                         WDG_59_DriverA_GpWDTAReg_BaseAddr.
** Functions Invoked     : Det_ReportError,
**                         Dem_ReportErrorStatus,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**                         Wdg_59_DriverA_TriggerFunc.
**
** Registers Used        : WDTAnMD, WDTAnEVAC, WDTAnREF, WDTAnWDTE.
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/* Implements: WDG_ESDD_UD_052, WDG_ESDD_UD_060                               */
/* Implements: EAAR_PN0064_FR_0010, EAAR_PN0064_FR_0005                       */
/* Implements: EAAR_PN0064_FR_0007, EAAR_PN0064_FR_0020                       */
/* Implements: WDG107, WDG160, WDG051, WDG145, WDG103, WDG016, WDG026, WDG091 */
/* Implements: WDG092, WDG017, WDG018, WDG169, WDG031                         */
/* Implements: SWS_Wdg_00107, SWS_Wdg_00051, SWS_Wdg_00160                    */
/* Implements: SWS_Wdg_00091, SWS_Wdg_00092, SWS_Wdg_00145, SWS_Wdg_00103     */
/* Implements: SWS_Wdg_00016, SWS_Wdg_00026, SWS_Wdg_00017, SWS_Wdg_00018     */
/* Implements: SWS_Wdg_00031                                                  */

FUNC(Std_ReturnType,  WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetMode
  (WdgIf_ModeType Mode)
{
  /* Implements: WDG105, SWS_Wdg_00105 */
  /* Variable to store the return value */
  Std_ReturnType LddReturnValue;
  /* Variable to store the set mode */
  uint8 LucMD;
  /* Initialize the return value */
  LddReturnValue = E_OK;

  /* Implements: WDG_ESDD_UD_052                                              */
  /* Implements: EAAR_PN0064_FR_0010, EAAR_PN0064_FR_0005                     */
  /* Implements: EAAR_PN0064_FR_0007, EAAR_PN0064_FR_0020                     */
  /* Implements: WDG107, WDG160, WDG051, WDG145, WDG103, WDG016, WDG026       */
  /* Implements: WDG092, WDG017, WDG018, WDG169, WDG091                       */
  /* Implements: SWS_Wdg_00107, SWS_Wdg_00051, SWS_Wdg_00160                  */
  /* Implements: SWS_Wdg_00091, SWS_Wdg_00092, SWS_Wdg_00145, SWS_Wdg_00103   */
  /* Implements: SWS_Wdg_00016, SWS_Wdg_00026, SWS_Wdg_00017, SWS_Wdg_00018   */
  /* Report Error to DET, if state of Watchdog is not idle */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  if (WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState)
  {
    /* Implements: WDG_ESDD_UD_040, WDG_ESDD_UD_041                           */
    /* Implements: WDG010, WDG063, WDG066, WDG013, WDG089, WDG090, WDG035     */
    /* Implements: SWS_Wdg_00010, SWS_Wdg_00090 , SWS_Wdg_00035               */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether input parameter 'Mode' is within the range */
  if ((Mode > WDGIF_FAST_MODE) || (Mode < WDGIF_OFF_MODE))

  {
    /* Implements: WDG_ESDD_UD_052                                            */
    /* Implements: WDG091, WDG092, WDG010                                     */
    /* Implements: SWS_Wdg_00091, SWS_Wdg_00092, SWS_Wdg_00010                */
    /* Implements: EAAR_PN0064_FR_0010, EAAR_PN0064_FR_0005                   */
    /* Implements: EAAR_PN0064_FR_0007, EAAR_PN0064_FR_0020                   */
    /* Implements: BSW00338, BSW00323, BSW12448                               */
    /* Implements: SRS_BSW_00323, SRS_SPAL_12448                              */
    /* Report Error to DET, if the parameter mode is not within the range */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_PARAM_MODE);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;

  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Implements: WDG_ESDD_UD_052                                            */
    /* Implements: WDG018, SWS_Wdg_00018, WDG052, SWS_Wdg_00052               */
    /* Implements: BSW00338, BSW00335, SRS_BSW_00335                          */
    /* Set the state of Watchdog as busy */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
    #endif

    if (WDGIF_OFF_MODE == Mode)
    {
      /* Implements: WDG_ESDD_UD_051, WDG_ESDD_UD_052, WDG_ESDD_UD_006        */
      /* Implements: WDG025, WDG026                                           */
      /* Implements: SWS_Wdg_00025, SWS_Wdg_00026                             */
      /* Implements: EAAR_PN0034_FR_0016, EAAR_PN0064_FR_0009                 */
      /* Implements: EAAR_PN0064_FR_0031, EAAR_PN0064_FR_0024                 */
      /* Implements: BSW00338, BSW00323, BSW12163, BSW12106                   */
      /* Implements: SRS_BSW_00323, SRS_SPAL_12163, SRS_Wdg_12106             */
      /* Report Error to DEM */
      #if (WDG_59_DRIVERA_E_DISABLE_REJECTED_REPORTING == STD_ON)
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_DISABLE_REJECTED,
                             (Dem_EventStatusType) DEM_EVENT_STATUS_FAILED);
      #endif
      /* Set Return Value as E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    }

    else
    {
      #if ((WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION) && \
                      (WDG_59_DRIVERA_E_DISABLE_REJECTED_REPORTING == STD_ON))
      /* Raise DEM Error PASSED */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_DISABLE_REJECTED,
                             (Dem_EventStatusType) DEM_EVENT_STATUS_PASSED);
      #endif
    

      /* Switching the Watchdog Mode from OFF to SLOW */
      if (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode)
      {

        /* Switching the Watchdog Mode from OFF to SLOW */
        if (WDGIF_SLOW_MODE == Mode)
        {
          /* Check if critical section protection is required */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                     */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                              */
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_ENTER_CRITICAL_SECTION
                                       (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
          #endif

          /* Set configured slow mode value to Mode register */
          LucMD = (Wdg_59_DriverA_GpConfigPtr->ucWdtamdSlowValue) |
                  ((WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD) &
                  WDG_59_DRIVERA_75INTERRUPT_MASK);

          WDG_59_DRIVERA_WRITE_REG_AND_MIRROR(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),
          (LucMD),
          (&Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_MD_IDX]))

          /* All MD bits are written by LucMD, so check the whole reg */
          WDG_59_DRIVERA_CHECK_WRITE_VERIFY_RUNTIME(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),
          (LucMD), WDG_59_DRIVERA_MASK_FIRST_7_BITS, WDG_59_DRIVERA_SETMODE_SID)

          /* Check if critical section protection is required */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025   */
          /* Implements: EAAR_PN0034_FR_0030                                 */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040        */
          /* Implements: BSW12019, SRS_Wdg_12019                             */
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
                                       (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
          #endif

          /* Functionality related to R4.0 and R4.2 */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_145   */
          /* Implements: EAAR_PN0034_FR_0030, WDG_ESDD_UD_025                */
          /* Implements: WDG134, WDG040, WDG145                              */
          /* Implements: SWS_Wdg_00145, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                             */
           #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
           WDG_59_DRIVERA_ENTER_CRITICAL_SECTION
                                     (WDG_59_DRIVERA_TRIGG_PROTECTION);
           #endif

           /* Set the trigger counter value considering the slow mode */
           Wdg_59_DriverA_GusTriggerCounter = WDG_59_DRIVERA_INITIAL_TIMEOUT /
                                 Wdg_59_DriverA_GpConfigPtr->usSlowTimeValue;

           #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
           /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_145  */
           /* Implements: EAAR_PN0034_FR_0030, WDG_ESDD_UD_025               */
           /* Implements: WDG134, WDG040, WDG145                             */
           /* Implements: SWS_Wdg_00145, SWS_Wdg_00134, SWS_Wdg_00040        */
           /* Implements: BSW12019, SRS_Wdg_12019                            */
           WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
                                    (WDG_59_DRIVERA_TRIGG_PROTECTION);
           #endif
        }
        /* Switching the Watchdog Mode from OFF to FAST */
        else
        {
          /* Check if critical section protection is required */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025   */
          /* Implements: EAAR_PN0034_FR_0030                                 */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040        */
          /* Implements: BSW12019, SRS_Wdg_12019                             */
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_ENTER_CRITICAL_SECTION
                                        (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
          #endif

          /* Set configured fast mode value to Mode register */
          LucMD = (Wdg_59_DriverA_GpConfigPtr->ucWdtamdFastValue) |
          ((WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD) &
          WDG_59_DRIVERA_75INTERRUPT_MASK);

          WDG_59_DRIVERA_WRITE_REG_AND_MIRROR(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),
          (LucMD),
          (&Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_MD_IDX]))

          /* All MD bits are written by LucMD, so check the whole reg */
          WDG_59_DRIVERA_CHECK_WRITE_VERIFY_RUNTIME(
          (&WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD),
          (LucMD), WDG_59_DRIVERA_MASK_FIRST_7_BITS, WDG_59_DRIVERA_SETMODE_SID)

          /* Check if critical section protection is required */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025    */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                              */
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
                                        (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
          #endif

          /* Functionality related to R4.0 and R4.2 */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025    */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                              */
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_ENTER_CRITICAL_SECTION
                                          (WDG_59_DRIVERA_TRIGG_PROTECTION);
          #endif
          /* Set the trigger counter value considering the fast mode */
          Wdg_59_DriverA_GusTriggerCounter = WDG_59_DRIVERA_INITIAL_TIMEOUT /
                                   Wdg_59_DriverA_GpConfigPtr->usFastTimeValue;
          #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
          WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(WDG_59_DRIVERA_TRIGG_PROTECTION);
          #endif

        }
          /* Check if critical section protection is required */
          /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009                     */
          /* Implements: EAAR_PN0034_FR_0030                                  */
          /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040         */
          /* Implements: BSW12019, SRS_Wdg_12019                              */
         #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION
                                        (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
         #endif

        /* Set the current mode */
        Wdg_59_DriverA_GddCurrentMode = Mode;

        /* Check if critical section protection is required */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
                                        (WDG_59_DRIVERA_MODE_SWITCH_PROTECTION);
        #endif

        /* Call the Trigger Function which restarts the Watchdog hardware */
        Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_INCLUDE_CRITICAL_SECTION);
      } /* end of else if (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode) */

      else
      {
        /* No action required */
      }

      if (Mode != Wdg_59_DriverA_GddCurrentMode)
      {

        /* Functionality related to R4.0 and R4.2 */
        /* Implements: WDG_ESDD_UD_040, WDG_ESDD_UD_041, WDG_ESDD_UD_044      */
        /* Implements: WDG_ESDD_UD_051                                        */
        /* Implements: WDG013, WDG173, WDG016                                 */
        /* Implements: SWS_Wdg_00010, SWS_Wdg_00090, SWS_Wdg_00173            */
        /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385            */
        /* Implements: SRS_BSW_00327, SRS_BSW_00331, SWS_Wdg_00016            */

        /* Report Error to DEM */
        #if ( WDG_59_DRIVERA_E_MODE_FAILED_REPORTING == STD_ON)
        Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_FAILED,
                               (Dem_EventStatusType) DEM_EVENT_STATUS_FAILED);
        #endif
        /* Set Return Value as E_NOT_OK */
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        #if ((WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)&& \
                        (WDG_59_DRIVERA_E_MODE_FAILED_REPORTING == STD_ON))
        /* Raise DEM Error PASSED */
        Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_FAILED,
                               (Dem_EventStatusType) DEM_EVENT_STATUS_PASSED);
        #endif
      }
    }
    /* Set Watchdog Driver State to IDLE after Mode Switch operation */
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
    #endif  /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  } /* End of if (E_OK == LddReturnValue) */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */

  return(LddReturnValue);
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetTriggerCondition
**
** Service ID            : 0x03
**
** Description           : This service is used to initialize the trigger
**                         counter.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : timeout
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Wdg_59_DriverAInit must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GpConfigPtr,
**                         Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GusTriggerCounter.
**
** Functions Invoked     : Det_ReportError.
**
** Registers Used        : None
*******************************************************************************/

/* Functionality related to R4.0 and R4.2 */
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/* Implements: WDG_ESDD_UD_063, WDG_ESDD_UD_056, WDG_ESDD_UD_060              */
/* Implements: WDG155, SWS_Wdg_00155                                          */
/* Implements: BSW00343, SRS_BSW_00343                                        */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetTriggerCondition
                                                            (uint16 timeout)
{
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value */
  Std_ReturnType LddReturnValue;
  /* Initialize the return value */
  LddReturnValue = E_OK;
  /* Check whether Watchdog Driver is initialized */
  if ((WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState) ||
                             (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode))
  {
    /* Implements: WDG_ESDD_UD_040, WDG_ESDD_UD_041                           */
    /* Implements: WDG010, WDG063, WDG066, WDG013, WDG089, WDG090             */
    /* Implements: SWS_Wdg_00010, SWS_Wdg_00090                               */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
        WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
   /*
   * Check whether timeout value requested is more than the maximum timeout
   * value configured
   */
    /* Implements: WDG_ESDD_UD_019, WDG_ESDD_UD_031                           */
  if (timeout > WDG_59_DRIVERA_MAXIMUM_TIMEOUT)
  {
    /* Implements: WDG_ESDD_UD_056                                            */
    /* Implements: WDG146, SWS_Wdg_00146                                      */
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
    WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_PARAM_TIMEOUT);
    /* Set Return Value as E_NOT_OK */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif
  {
    /* Check if critical section protection is required */
    /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025          */
    /* Implements: EAAR_PN0034_FR_0030                                        */
    /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040               */
    /* Implements: BSW12019, SRS_Wdg_12019                                    */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(WDG_59_DRIVERA_TRIGG_PROTECTION);
    #endif

    /* Implements: WDG_ESDD_UD_056                                            */
    /* Implements: WDG139, SWS_Wdg_139                                        */
    /* Implements: WDG123_Conf, WDG122_Conf                                   */
    /* Implements: ECUC_Wdg_00123, ECUC_Wdg_00121                             */
    /* Check if the current mode is slow */
    if (WDGIF_SLOW_MODE == Wdg_59_DriverA_GddCurrentMode)
    {
      /* Set the trigger counter value considering the slow mode */
      Wdg_59_DriverA_GusTriggerCounter = timeout /
                Wdg_59_DriverA_GpConfigPtr->usSlowTimeValue;
    }
    else if (WDGIF_FAST_MODE == Wdg_59_DriverA_GddCurrentMode)
    {
      /* Set the trigger counter value considering the fast mode */
      Wdg_59_DriverA_GusTriggerCounter = timeout /
                Wdg_59_DriverA_GpConfigPtr->usFastTimeValue;
    }
    else
    {
      /* The trigger counter need not be set for off mode */
    }

    /* Check if critical section protection is required */
    /* Implements: WDG_ESDD_UD_003, WDG_ESDD_UD_009, WDG_ESDD_UD_025          */
    /* Implements: EAAR_PN0034_FR_0030                                        */
    /* Implements: WDG134, WDG040, SWS_Wdg_00134, SWS_Wdg_00040               */
    /* Implements: BSW12019, SRS_Wdg_12019                                    */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(WDG_59_DRIVERA_TRIGG_PROTECTION);
    #endif
  }
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE

/*******************************************************************************
** Function Name         :  Wdg_59_DriverA_CheckHWConsistency
**
** Service ID            :  0x05
**
** Description           :  This API will execute registers ram mirroring check
**
** Sync/Async            :  synchronous
**
** Reentrancy            :  Non-Reentrant
**
** Input Parameters      :  Wdg_59_DriverA_HWConsistencyModeType
**
** InOut Parameters      :  None
**
** Output Parameters     :  None
**
** Return parameter      :  Std_ReturnType - Returns E_OK if the registers
**                          values corresponds with their ram copy, else
**                          returns E_NOT_OK if there is at least one
**                          difference.
**
** Preconditions         :  Component must be initialized using
**                          Wdg_59_DriverA_Init().
**
** Global Variables Used :  Wdg_59_DriverA_GddDriverState
**                          WDG_59_DriverA_GpWDTAReg_BaseAddr
**                          Wdg_59_DriverA_GaaRamMirror
**
** Function(s) invoked   :  None
**
** Registers Used        :  WDTAnMD, WDTAnEVAC, WDTAnWDTE
*******************************************************************************/
#if (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE)

#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE
/* Implements: EAAR_PN0034_FSR_0006                                           */
/* Implements: WDG_ESDD_UD_040, WDG_ESDD_UD_041                               */
/* Implementation of Wdg_59_DriverA_CheckHWConsistency API */
FUNC(Std_ReturnType, WDG_59_DRIVERA_PUBLIC_CODE)
 Wdg_59_DriverA_CheckHWConsistency
         (Wdg_59_DriverA_HWConsistencyModeType HWConsistencyMode)
{
  /* Local variable to hold the return value of the function */
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_NOT_OK;
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Check if the Wdg_59_DriverA Module is not Initialized */
  if (WDG_59_DRIVERA_UNINIT == Wdg_59_DriverA_GddDriverState)
   {
    /* Implements: WDG010, WDG063, WDG066, WDG013, WDG089, WDG090             */
    /* Implements: SWS_Wdg_00010, SWS_Wdg_00090                               */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
        WDG_59_DRIVERA_CHECK_HW_CONSISTENCY_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
   }
  /* Check if current function is called with invalid arguments */
  else if ( (HWConsistencyMode != WDG_59_DRIVERA_DYNAMIC) &&
       (HWConsistencyMode != WDG_59_DRIVERA_STATIC))
   {
    /* Implements: WDG010, WDG063, WDG066, WDG013, WDG089, WDG090             */
    /* Implements: SWS_Wdg_00010, SWS_Wdg_00090                               */
    /* Implements: SRS_BSW_00337, SRS_BSW_00350, SRS_BSW_00385                */
    /* Implements: SRS_BSW_00327, SRS_BSW_00331                               */
     (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
        WDG_59_DRIVERA_CHECK_HW_CONSISTENCY_SID, WDG_59_DRIVERA_E_PARAM_CONFIG);
   }
  else
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
   {
    if (HWConsistencyMode == WDG_59_DRIVERA_DYNAMIC)
    {
      if (WDG_59_DriverA_GpWDTAReg_BaseAddr->ucMD == \
                     Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_MD_IDX])
      {
        #if (WDG_59_DRIVERA_VAC_ALLOWED == STD_ON)
        if (WDG_59_DriverA_GpWDTAReg_BaseAddr->ucEVAC == \
                   Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_EVAC_IDX])
        #else
        if (WDG_59_DriverA_GpWDTAReg_BaseAddr->ucWDTE == \
                   Wdg_59_DriverA_GaaRamMirror[WDG_59_DRIVERA_WDTAReg_WDTE_IDX])
        #endif
        {
          LddReturnValue = E_OK;
        }
        else
        {
           /* LddReturnValue will remain unchanged  */
        }
      }
      else
      {
        /* LddReturnValue will remain unchanged  */
      }
    }
    else
    {
      /* LddReturnValue will remain unchanged -> No static registers  */
    }
   }
  return(LddReturnValue);
} /* End of API Wdg_59_DriverA_HWCheckConsistency  */

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include WDG_MEMMAP_FILE
#endif /* (WDG_59_DRIVERA_RAM_MIRROR == WDG_59_DRIVERA_MIRROR_ENABLE) */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
