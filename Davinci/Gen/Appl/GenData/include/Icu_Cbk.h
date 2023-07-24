/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Icu_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for ICU callback Notification    */
/* Functions.                                                                 */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas.            */
/* Any warranty is expressly disclaimed and excluded by Renesas, either       */
/* expressed or implied, including but not limited to those for               */
/* non-infringement of intellectual property, merchantability                 */
/* and/or fitness for the particular purpose                                  */
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
 * V1.0.0:  21-Sep-2015 : Initial version
 * V1.0.1:  30-Sep-2016 : #ARDAABD-487
 *                        1. Updated copyright
 *                        2. Added MemMap switch
 * V2.0.0:  05-Oct-2016 : #ARDAABD-487
 *                        1. Updated version to 2.0.0, ASR4.2.2
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.0.6
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00190425\AppData\Local\Temp\DaVinci\Cfg-8039795\Generation\Cfg_Gen-1608098491176-0\AutosarFiles_ValGen7429727782302893839\ExtGen_DrvIcu_ECUC_4.2.2_1417467063596517592.arxml
 *                D:\SVN_Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\icu\generator\R422_ICU_F1x_BSWMDT.arxml
 * GENERATED ON:  16 Dec 2020 - 14:02:13
 */

#ifndef ICU_CBK_H
#define ICU_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ICU_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define ICU_CBK_AR_RELEASE_MINOR_VERSION  2U
#define ICU_CBK_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ICU_CBK_SW_MAJOR_VERSION  1U
#define ICU_CBK_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#define ICU_START_SEC_APPL_CODE
#include "Icu_MemMap.h"

/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) IPC_IsrCsDetect (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) IPC_IsrCsDetect_Standby (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) Icu_EOL_CAN3Rx_WakeupNotifactionFunc (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) IPC_IsrSocReqDetect (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) IPC_IsrSocReqDetect2 (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) POWER_IsrLVI_IDL (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) AMP_IsrVIP_8532_DIAG3 (void);
/* TRACE [R4, ICU214] */
/* TRACE [R4, ICU225_Conf] */
extern FUNC(void, ICU_APPL_CODE) AMP_IsrVIP_AMP8532_DIAG3 (void);


#define ICU_STOP_SEC_APPL_CODE
#include "Icu_MemMap.h"

#endif /* ICU_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
