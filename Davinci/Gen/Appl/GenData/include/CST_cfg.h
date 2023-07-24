/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CST_cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains global defines of the SW G3K related to CORTST Library  */
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
 * V1.0.0:  27-Nov-2013  : Initial version
 * V1.0.1:  15-Jan-2014  : As per CR 348, for the mantis issue #18244,
 *                         Copyright information is updated.
 * V1.0.2:  30-Jan-2015  : Macros EXECUTE_MAE_TEST, EXECUTE_TRAP0_TEST and
 *                         SAVE_INT_EXC_CALLT_SYS_REG are printed for new tests
 *                         as a part of SWCST Library update.
 * V2.0.0:  07-Sep-2016  : #ARDAABD-492
 *                         1. Updated to ASR 4.2.2
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.5
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen172034617495837798\ExtGen_DrvCorTst_ECUC_4.2.2_8597882667511532847.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\cortst\generator\R422_CORTST_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 14:23:32
 */
#ifndef CST_CFG_H
#define CST_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/* Set RUN_MODE = 0 for normal signature, RUN_MODE = 1 for inverted signature  */
#define RUN_MODE                0UL

/* RAM addresses generating for test purpose  */
#define CST_RAM_ADDRESS_L       0xFEFE8600UL

/* RAM addresses generating for test purpose  */
#define CST_RAM_ADDRESS_A       0xFEFE8000UL

/* RAM addresses generating for test purpose  */
#define CST_RAM_ADDRESS_B       0xFEFE8200UL

/* RAM addresses generating for test purpose  */
#define CST_RAM_ADDRESS_C       0xFEFE8400UL

/* Enable/Disable TRAP0 test  */
#define CST_EXECUTE_TRAP0_TEST  1

/* Enable/Disable TRAP1 test  */
#define CST_EXECUTE_TRAP1_TEST  1

/* Enable/Disable FETRAP test  */
#define CST_EXECUTE_FETRAP_TEST 1

/* Enable/Disable MAE test  */
#define CST_EXECUTE_MAE_TEST    1

/* Enable/Disable automatic enabling of interrupts at end of interrupt-disable sections  */
#define CST_INT_EN              1

/* Pass reference value  */
#define PASSED                  0x55555555UL

/* Fail reference value  */
#define FAILED                  0x7FFF0000UL




/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CST_CFG_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
