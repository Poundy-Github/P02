/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Hardware.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the structure pointer for accessing the hardware        */
/* registers of module.                                                       */
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
 * V1.0.0:  03-Sep-2015    : Initial Version
 *
 * V1.0.1:  23-Oct-2015    : The Following variable renamed to include Module
 *                           prefix in the variable name.
 *                           1. DmaReg_BaseAddress to AdcDmaReg_BaseAddress
 *                           2. PWGAReg_BaseAddress to AdcPWGAReg_BaseAddress
 *                           3. PWSAReg_BaseAddress to AdcPWSAReg_BaseAddress
 *                           4. WUFReg_BaseAddress to AdcWUFReg_BaseAddress
 * V1.0.2:  12-Jan-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAAGA-58,
 *                              Added support for global DMA register access.
 *                           2. Include section is updated.
 * V2.0.0:  05-Aug-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-788,
 *                              added FUSA implementation.
 * V2.1.0:  25-Nov-2016    : The following changes are made:
 *                           1. As part of JIRA ticket ARDAABC-940
 *                              Updated memory sections usage.
 * V2.1.1:  06-Dec-2016    : The following changes are made:
 *                           1. As a part of JIRA ticket ARDAABC-913,
 *                              Added <ADC_> prefix to remained macro
 *                              definitions.
  * V2.1.2:  27-Sep-2017     : Following changes are made:
 *                            1. As part of ARDAABD-2387,
 *                             a. Array names are corrected based on the data
 *                                type names as per requirement MCAL052.
 *                             b. Variable names are corrected based on the data
 *                                type names as per requirement MCAL052.
 *                            2. As part of ARDAABD-2468,
 *                               Inclusion for Iocommon_Defines.h is added
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.15.3
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5446369\Generation\Cfg_Gen-1602315694632-0\AutosarFiles_ValGen2648245967057569354\ExtGen_DrvAdc_ECUC_4.2.2_178175295851930220.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\adc\generator\R422_ADC_F1x_BSWMDT.arxml
 * GENERATED ON:  10 Oct 2020 - 15:52:13
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc_Hardware.h"
#include "Adc.h"
#include "Iocommon_Defines.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define ADC_HARDWARE_C_AR_RELEASE_MAJOR_VERSION  4U
#define ADC_HARDWARE_C_AR_RELEASE_MINOR_VERSION  2U
#define ADC_HARDWARE_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define ADC_HARDWARE_C_SW_MAJOR_VERSION   1U
#define ADC_HARDWARE_C_SW_MINOR_VERSION   1U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_START_SEC_CONST_ASIL_B_UNSPECIFIED
#else
  #define ADC_START_SEC_CONST_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/* MISRA Violation: START Msg(4:0303)-1 */

/* Structure of ADC configuration registers */
volatile AdcConfReg* const Adc_GaaConfReg_BaseAddress[ADC_CONFREG_INSTANCES] =
{
  (volatile AdcConfReg *)&ADC0CONFREG,
  (volatile AdcConfReg *)&ADC1CONFREG
};

/* Structure of ADC Virtual channel registers */
volatile AdcVirChReg* const
 Adc_GaaVirChReg_BaseAddress[ADC_VIRCHREG_INSTANCES] =
{
  (volatile AdcVirChReg *)&ADC0VIRCHREG0,
  (volatile AdcVirChReg *)&ADC1VIRCHREG0
};

/* Structure of ADC Scan group registers */
volatile AdcSGReg* const Adc_GaaSGReg_BaseAddress[ADC_SGREG_INSTANCES] =
{
  (volatile AdcSGReg *)&ADC0SG1,
  (volatile AdcSGReg *)&ADC0SG2,
  (volatile AdcSGReg *)&ADC0SG3,
  (volatile AdcSGReg *)&ADC1SG1,
  (volatile AdcSGReg *)&ADC1SG2,
  (volatile AdcSGReg *)&ADC1SG3
};






/* END Msg(4:0303)-1 */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
  #define ADC_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#else
  #define ADC_STOP_SEC_CONST_UNSPECIFIED
#endif
#include ADC_MEMMAP_FILE

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
