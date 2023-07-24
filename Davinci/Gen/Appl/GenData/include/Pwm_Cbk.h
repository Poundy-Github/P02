/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Prototype Declarations for PWM callback                       */
/* Notification Functions                                                     */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  05-Sep-2015 : Initial Version
 * V2.0.0:  29-Sep-2015 : #ARDAABD-494 AUTOSAR 4.2 is supported.
 * V3.0.0:  14-Nov-2016 : #ARDAABD-565 Implement FuSa requirements for ASIL-B.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    2.2.2
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5761450\Generation\Cfg_Gen-1599208913269-0\AutosarFiles_ValGen3763191865339178278\ExtGen_DrvPwm_ECUC_4.2.2_6870692216107392404.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\pwm\generator\R422_PWM_F1x_BSWMDT.arxml
 * GENERATED ON:   4 Sep 2020 - 18:35:51
 */

#ifndef PWM_CBK_H
#define PWM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm_Cfg.h"
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PWM_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define PWM_CBK_AR_RELEASE_MINOR_VERSION  2U
#define PWM_CBK_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PWM_CBK_SW_MAJOR_VERSION  1U
#define PWM_CBK_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#define PWM_START_SEC_APPL_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_APPL_CODE
#include "Pwm_MemMap.h"

#endif /* PWM_CBK_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
