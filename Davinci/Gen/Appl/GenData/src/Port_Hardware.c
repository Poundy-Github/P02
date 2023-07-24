/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Hardware.c                                             */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Base Address of Port Groups and Filters configured      */
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
 *  V1.0.0:  09-Sep-2015  : Initial Version
 *
 *  V1.0.1:  16-Sep-2015  : The MISRA justification is added
 *  V2.0.0   14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                          changes are made:
 *                          1. Include MemMap header file from "Port_Cfg.h".
 *                          2. Use precompile switches to select different
 *                          memory section names in AR4.0.3 and AR4.2.2.
 *  V2.0.1   24-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                          changes are made:
 *                          1. Removed PORT_START_SEC_CONFIG_CONST_UNSPECIFIED
 *                          and PORT_STOP_SEC_CONFIG_CONST_UNSPECIFIED and use
 *                          memory sections specific to each Autosar version.
 *  V2.0.2:  24-Jan-2017  : As part of ARDAABC-867 Jira ticket the following
 *                          changes are made:
 *                          1. Removed Port_GstAlphaRegs array.
 *  V2.0.3:  07-Feb-2017  : As part of ARDAABC-867 Jira ticket the following
 *                          changes are made:
 *                          1. Removed EDC and DNFCKS registers addresses.
 *  V2.0.4:  29-Jun-2017  : As per the requirement EAAR_PN0034_NR_0018,
 *                          1. Copyright information is updated.
 *  V2.0.5:  22-Sep-2017  : As part of JIRA ARDAABD-2457, Include Section is
 *                          updated for adding Iocommon_Defines.h file.
*/
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  2.2.6
 */

/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00221986\AppData\Local\Temp\DaVinci\Cfg-5767140\Generation\Cfg_Gen-1634808980785-0\AutosarFiles_ValGen2249394964719263281\ExtGen_DrvPort_ECUC_4.2.2_5118810088505175050.arxml
 *                E:\software\Vector_Package\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\port\generator\R422_PORT_F1x_BSWMDT.arxml
 * GENERATED ON:  21 Oct 2021 - 17:36:45
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Port.h"
#include "Port_Hardware.h"
#include "Iocommon_Defines.h"

/*******************************************************************************
**                       Version Information                                  **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_HARDWARE_C_AR_RELEASE_MAJOR_VERSION  4U
#define PORT_HARDWARE_C_AR_RELEASE_MINOR_VERSION  2U
#define PORT_HARDWARE_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PORT_HARDWARE_C_SW_MAJOR_VERSION  2U
#define PORT_HARDWARE_C_SW_MINOR_VERSION  4U

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and an  */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used in order to typecast to volatile      */
/*                 object structures .                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
 #define PORT_START_SEC_CONST_ASIL_B_UNSPECIFIED
#else
 #define PORT_START_SEC_CONST_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

/* MISRA Violation: START Msg(4:0303)-1 */

/*Port groups registers*/
volatile PortReg* const 
                        Port_GaaPortReg_BaseAddress[PORT_NUM_PORT_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile PortReg *)&PORTREG0,

  /* Index: 1 - 1 */
  (volatile PortReg *)&PORTREG1,

  /* Index: 2 - 2 */
  (volatile PortReg *)&PORTREG2,

  /* Index: 3 - 3 */
  (volatile PortReg *)&PORTREG3,

  /* Index: 4 - 4 */
  (volatile PortReg *)&PORTREG8,

  /* Index: 5 - 5 */
  (volatile PortReg *)&PORTREG9,

  /* Index: 6 - 6 */
  (volatile PortReg *)&PORTREG10,

  /* Index: 7 - 7 */
  (volatile PortReg *)&PORTREG11,

  /* Index: 8 - 8 */
  (volatile PortReg *)&PORTREG12,

  /* Index: 9 - 9 */
  (volatile PortReg *)&PORTREG13,

  /* Index: 10 - 10 */
  (volatile PortReg *)&PORTREG18,

  /* Index: 11 - 11 */
  (volatile PortReg *)&PORTREG19,

  /* Index: 12 - 12 */
  (volatile PortReg *)&PORTREG20
};



/*JTag ports registers*/
/* volatile JPortReg* const 
                        Port_GpJPortReg_BaseAddress; */

/*Input ports*/
/* volatile IPortReg* const 
                        Port_GpIPortReg_BaseAddress; */

/*Analogue port groups registers*/
volatile APortReg* const 
                        Port_GaaAPortReg_BaseAddress[PORT_ANALOG_PORT_INSTANCES] =
{
  /* Index: 0 - 0 */
  (volatile APortReg *) &APORTREG0,

  /* Index: 1 - 1 */
  (volatile APortReg *) &APORTREG1
};



/*Port filters registers*/
/* volatile FCLAReg* const Port_GpFclaReg_BaseAddress */

/*Digital filters registers*/
/* volatile DNFAReg* const 
                        Port_GaaDnfaReg_BaseAddress[PORT_NUM_OF_DNFA_REG]; */

/* END Msg(4:0303)-1 */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
 #define PORT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#else
 #define PORT_STOP_SEC_CONST_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
