/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for ADC callback Notification    */
/* Functions.                                                                 */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  03-Sep-2015  : Initial Version
 * V2.0.1:  01-Nov-2016  : The following changes are made:
 *                         1. As a part of JIRA ticket ARDAABC-788,
 *                         updated the copyright to 2016
 * V2.1.0   25-Nov-2016  : The following changes are made:
 *                         1. As part of JIRA ticket ARDAABC-940
 *                            Updated memory sections usage
 * V2.1.1   19-Jan-2017  : The following changes are made:
 *                         1. As part of JIRA ticket ARDAABC-902
 *                            Include Dem.h moved to Include Section
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.15.3
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5446369\Generation\Cfg_Gen-1602315694632-0\AutosarFiles_ValGen2648245967057569354\ExtGen_DrvAdc_ECUC_4.2.2_178175295851930220.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\adc\generator\R422_ADC_F1x_BSWMDT.arxml
 * GENERATED ON:  10 Oct 2020 - 15:52:13
 */

#ifndef ADC_CBK_H
#define ADC_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc_Cfg.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ADC_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define ADC_CBK_AR_RELEASE_MINOR_VERSION  2U
#define ADC_CBK_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ADC_CBK_SW_MAJOR_VERSION  1U
#define ADC_CBK_SW_MINOR_VERSION  1U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CALLOUT_CODE_ASIL_B
#else
  #define ADC_START_SEC_CALLOUT_CODE
#endif
#include ADC_MEMMAP_FILE

extern FUNC(void, ADC_APPL_CODE) IoHwAb_Adc_Notification_Group0 (void);
extern FUNC(void, ADC_APPL_CODE) IoHwAb_Adc_Notification_Group1 (void);



#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CALLOUT_CODE_ASIL_B
#else
  #define ADC_STOP_SEC_CALLOUT_CODE
#endif
#include ADC_MEMMAP_FILE

#endif /* ADC_CBK_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
