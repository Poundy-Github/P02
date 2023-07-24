/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Hardware.h                                             */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains extern Declarations of configured Ports .               */
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
 * V1.0.0:  09-Sep-2015  : Initial version
 * V2.0.0:  14-Nov-2016    As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Include memory map header defined in Port_Cfg.h.
 * V2.0.1:  29-Jun-2017  : As per the requirement EAAR_PN0034_NR_0018,
 *                         1. Copyright information is updated.
 * V2.0.2:  22-Sep-2017  : As part of JIRA ARDAABD-2457, Include Section is
 *                         updated for adding Iocommon_Types.h file.
 */
/******************************************************************************/
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.2.6
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00221986\AppData\Local\Temp\DaVinci\Cfg-5767140\Generation\Cfg_Gen-1634808980785-0\AutosarFiles_ValGen2249394964719263281\ExtGen_DrvPort_ECUC_4.2.2_5118810088505175050.arxml
 *                E:\software\Vector_Package\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\port\generator\R422_PORT_F1x_BSWMDT.arxml
 * GENERATED ON:  21 Oct 2021 - 17:36:45
 */

#ifndef PORT_HARDWARE_H
#define PORT_HARDWARE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Iocommon_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_HARDWARE_H_AR_RELEASE_MAJOR_VERSION  4U
#define PORT_HARDWARE_H_AR_RELEASE_MINOR_VERSION  2U
#define PORT_HARDWARE_H_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PORT_HARDWARE_H_SW_MAJOR_VERSION  2U
#define PORT_HARDWARE_H_SW_MINOR_VERSION  4U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


#define PORT_NUM_PORT_INSTANCES             0x0DU

#define PORT_ANALOG_PORT_INSTANCES          0x02U


/*******************************************************************************
**                      Registers Available                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Declarations                                   **
*******************************************************************************/

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
 #define PORT_START_SEC_CONST_ASIL_B_UNSPECIFIED
#else
 #define PORT_START_SEC_CONST_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

extern volatile  PortReg* const
                 Port_GaaPortReg_BaseAddress[PORT_NUM_PORT_INSTANCES];

/* extern volatile  JPortReg* const Port_GpJPortReg_BaseAddress; */
/*extern volatile  IPortReg* const Port_GpIPortReg_BaseAddress;*/
extern volatile  APortReg* const
                 Port_GaaAPortReg_BaseAddress[PORT_ANALOG_PORT_INSTANCES];

/*extern volatile  DNFAReg* const
                            Port_GaaDnfaReg_BaseAddress[PORT_NUM_OF_DNFA_REG];*/
/*extern volatile  FCLAReg* const Port_GpFclaReg_BaseAddress;*/

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
 #define PORT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#else
 #define PORT_STOP_SEC_CONST_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_HARDWARE_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
