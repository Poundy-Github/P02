/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_Hardware.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
 * V1.0.0:  30-Aug-2015 : Initial Version
 * V1.0.1:  10-Dec-2015 : As part of F1K V4.00.01 development activity,
 *                        following changes are made:
 *                        1. As part of JIRA #ARDAAGA-87, prefix of
 *                           module name is added to variables to avoid
 *                           conflict between different modules.
 * V2.0.0:  29-Sep-2016 : #ARDAABD-494 AUTOSAR 4.2 is supported.
 * V2.1.0:  11-Jul-2017 : As per JIRA ticket #ARDAABD-1726, following changes
 *                        are made:
 *                        1. Added structure 'PwmPWGAINTFReg_BaseAddress'.
 * V2.1.1:  22-Sep-2017 : Following changes are made:
 *                        1. As per JIRA ticket #ARDAABD-2476, structure naming
 *                           is corrected and added macro PWM_PWGA_INTF_REG.
 *                        2. As per JIRA ticket #ARDAABD-2465, inclusion of
 *                           Iocommon_Types.h is added.
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

#ifndef PWM_HARDWARE_H
#define PWM_HARDWARE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Iocommon_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PWM_HW_H_AR_RELEASE_MAJOR_VERSION  4U
#define PWM_HW_H_AR_RELEASE_MINOR_VERSION  2U
#define PWM_HW_H_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PWM_HARDWARE_H_SW_MAJOR_VERSION  1U
#define PWM_HARDWARE_H_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


#define PWM_TOTAL_TAUDB_INSTANCES           0x1U


#define PWM_TOTAL_TAUJ_INSTANCES            0x2U


#define PWM_TOTAL_TAUJ_CHANNELS_INSTANCE    0x6U


#define PWM_TOTAL_TAUDB_CHANNELS_INSTANCE   0x2U


#define PWM_TOTAL_DIAGNOSTIC_INSTANCES      0x0U


#define PWM_PWGA_INTF_REG                   0x3U

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*Structure of TAUDB Os registers*/
extern volatile TAUDBOsReg* const
                     Pwm_GaaTAUDBOsReg_BaseAddress[PWM_TOTAL_TAUDB_INSTANCES];

/*Structure of TAUJ Os registers*/
extern volatile TAUJOsReg* const
                       Pwm_GaaTAUJOsReg_BaseAddress[PWM_TOTAL_TAUJ_INSTANCES];

/*Structure of TAUDB User registers*/
extern volatile TAUDBUserReg* const
                   Pwm_GaaTAUDBUserReg_BaseAddress[PWM_TOTAL_TAUDB_INSTANCES];

/*Structure of TAUJ User registers*/
extern volatile TAUJUserReg* const
                     Pwm_GaaTAUJUserReg_BaseAddress[PWM_TOTAL_TAUJ_INSTANCES];

/*Structure of TAUDB Channel registers*/
extern volatile TAUDBChReg* const
             Pwm_GaaTAUDBChReg_BaseAddress[PWM_TOTAL_TAUDB_CHANNELS_INSTANCE];

/*Structure of TAUJ Channel registers*/
extern volatile TAUJChReg* const
               Pwm_GaaTAUJChReg_BaseAddress[PWM_TOTAL_TAUJ_CHANNELS_INSTANCE];

/*Structure of Diagnostic Channel registers*/
/* extern volatile PWGAReg* const Pwm_GaaPWGAReg_BaseAddress[]; */

/*Structure of Diagnostic unit register*/
/* extern volatile PWBAReg* const Pwm_GaaPWBAReg_BaseAddress; */

/*Structure of Diagnostic unit interrupt registers*/
/* extern volatile PWGAINTFReg* const Pwm_GaaPWGAINTFReg_BaseAddress[]; */

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif /* PWM_HARDWARE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
