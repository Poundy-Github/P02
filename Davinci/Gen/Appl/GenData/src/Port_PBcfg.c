/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_PBcfg.c                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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
 *  V1.0.1:  16-Sep-2015  : The value generation for JPMCSR and APSR are
 *                          corrected
 *
 *  V1.0.2:  30-Dec-2015  : The following changes are made
 *                          1. As a part of ticket ARDAAGA-138
 *                          ucNoOfPortNumRegs, ucNoOfPortAnalogRegs
 *                          ucNoOfPortInputRegs, ucNoOfPortJRegs is updated
 *                          in case of multiple configure set  for
 *                          number of port groups configured in
 *                          Port_GstConfigType structure.
 *                          2. As a part of ticket ARDAAGA-139
 *                          usInitModeJPSRRegVal, usInitModeRegJPUVal
 *                          is corrected to ulInitModeJPSRRegVal,
 *                          usInitModeJPURegVal respectively.
 *                          3. As a part of ticket ARDAAGA-141
 *                          ucPortGroupIndex is updated in
 *                          Port_GstPinChangeableDetailsList for JTAG during
 *                          PortPinModeChangeable.
 *                          and ucPortGroupIndex is updated in
 *                          Port_GstPinChangeableDetailsList for ANALOG
 *                          during PortPinDirectionChangeable.
 *                          5. As part JIRA ARDAAGA-8, Digital_Filter_Group
 *                          and Analog_Filter_Group implementation
 *                          is modified
 *                          6. As part JIRA ARDAAGA-133 new member
 *                          ucDeepStopSupp is implemented and added
 *                          for Port_GstNumRegs and Port_GstAnalogRegs
 *                          structure.
 * V2.0.0:  21-Oct-2016   : As part of ARDAABC-867 Jira ticket, the following
 *                          changes are made:
 *                          1. Generate 32-bit masks values instead of 64-bit
 *                          for PMSR, JPMSR and APMSR.
 * V2.2.0:  14-Nov-2016   : As part of ARDAABC-542 Jira ticket the following
 *                          changes are made:
 *                          1. Include MemMap header file from "Port_Cfg.h".
 *                          2. Use precompile switches to select different
 *                          memory section names in AR4.0.3 and AR4.2.2.
 * V2.2.1:  24-Nov-2016   : As part of ARDAABC-542 Jira ticket the following
 *                          changes are made:
 *                          1. Removed multiple memory sections Start/Stop
 *                          with the same section.
 * V2.2.2:  24-Jan-2017   : As part of ARDAABC-867 Jira ticket the following
 *                          changes are made:
 *                          1. Removed Port_GstAlphaRegs array.
 * V2.2.3:  07-Feb-2017   : As part of ARDAABC-867 Jira ticket the following
 *                          changes are made:
 *                          1. Removed Port_GstEDCRegs and Port_GstDNFCKSRegs
 *                             arrays.
 * V2.2.4:  29-Jun-2017   : As per the requirement EAAR_PN0034_NR_0018,
 *                          1. Copyright information is updated.
 * V2.2.5:  25-May-2018   : 1. As part of JIRA ARDAABD-2125, new member
 *                          ucDeepStopSupp is implemented and added
 *                          for Port_GstJTAGRegs structure.
 *                          2. As part of ARDAABD-1580, Comment of
 *                          the structure Port_GstFCLARegs is updated.
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


/*******************************************************************************
**                       Version Information                                  **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PORT_PBCFG_C_SW_MAJOR_VERSION  2U
#define PORT_PBCFG_C_SW_MINOR_VERSION  4U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
  PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (PORT_PBTYPES_AR_RELEASE_MINOR_VERSION != \
  PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (PORT_PBTYPES_AR_RELEASE_REVISION_VERSION != \
  PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (PORT_PBTYPES_SW_MAJOR_VERSION != \
  PORT_PBCFG_C_SW_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (PORT_PBTYPES_SW_MINOR_VERSION != \
  PORT_PBCFG_C_SW_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

/* The following structure indicates the starting point of database */
CONST(Port_ConfigType, PORT_CONST) 
                          Port_GstConfiguration[PORT_NUM_OF_CONFIGSET] =
{
  /* Index: 0 - PortConfig_Normal */
  {
    /* ulStartOfDbToc */
    0x0EDF0220UL,

    /* pPortNumRegs */
    &Port_GstNumRegs[0],

    /* pPortAnalogRegs */
    &Port_GstAnalogRegs[0],

    /* pPortPinChangeableDetailsList */
    &Port_GstPinChangeableDetailsList[0],

    /* ucNoOfPortNumRegs */
    0x0DU,

    /* ucNoOfPortAnalogRegs */
    0x02U,

    /* ucNoOfPinChangeableDetails */
    0x07U
  },

  /* Index: 1 - PortConfig_Sleep */
  {
    /* ulStartOfDbToc */
    0x0EDF0220UL,

    /* pPortNumRegs */
    &Port_GstNumRegs[13],

    /* pPortAnalogRegs */
    &Port_GstAnalogRegs[2],

    /* pPortPinChangeableDetailsList */
    &Port_GstPinChangeableDetailsList[7],

    /* ucNoOfPortNumRegs */
    0x0DU,

    /* ucNoOfPortAnalogRegs */
    0x02U,

    /* ucNoOfPinChangeableDetails */
    0x09U
  }
};



/*
 * Array of structures of  port group registers.
 */
CONST(Port_NumRegs, PORT_CONST) 
                            Port_GstNumRegs[PORT_NUM_OF_NUMERIC_PORTS] =
{
  /* Index: 0 - PortConfigSet_0_Port_Group_0 */
  {
    /* ulRegListAvailable */
    0x001FCBF3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000A8D6UL,

    /* ulMaskConfigPMSRRegVal */
    0xE7FFA8D6UL,

    /* ulInitModePMCSRRegVal */
    0x000079BFUL,

    /* ulInitModePODCRegVal */
    0x00001800UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0840U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x1800U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x000FU,

    /* usInitModePFCAERegVal */
    0x0180U,

    /* ucPortIndex */
    0x00U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 1 - PortConfigSet_0_Port_Group_1 */
  {
    /* ulRegListAvailable */
    0x001FCBD3UL,

    /* ulInitModePSRRegVal */
    0x00004100UL,

    /* ulInitModePMSRRegVal */
    0x000036DFUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF36DFUL,

    /* ulInitModePMCSRRegVal */
    0x0000023BUL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xCFFBU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0400U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0200U,

    /* usInitModePFCRegVal */
    0x0001U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x01U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 2 - PortConfigSet_0_Port_Group_2 */
  {
    /* ulRegListAvailable */
    0x001FCBD3UL,

    /* ulInitModePSRRegVal */
    0x0000C10CUL,

    /* ulInitModePMSRRegVal */
    0x00000003UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF0003UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFCU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x02U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 3 - PortConfigSet_0_Port_Group_3 */
  {
    /* ulRegListAvailable */
    0x001E0BD3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFFEUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFFEUL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x03U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 4 - PortConfigSet_0_Port_Group_8 */
  {
    /* ulRegListAvailable */
    0x001FC3D3UL,

    /* ulInitModePSRRegVal */
    0x00000044UL,

    /* ulInitModePMSRRegVal */
    0x0000FD33UL,

    /* ulMaskConfigPMSRRegVal */
    0xF7FFFD33UL,

    /* ulInitModePMCSRRegVal */
    0x00000323UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x1C30U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0323U,

    /* usInitModePFCRegVal */
    0x0300U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x04U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 5 - PortConfigSet_0_Port_Group_9 */
  {
    /* ulRegListAvailable */
    0x001FC3D3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFE4UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFCFFE4UL,

    /* ulInitModePMCSRRegVal */
    0x0000000BUL,

    /* ulInitModePODCRegVal */
    0x00000003UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0004U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0003U,

    /* usInitModePFCERegVal */
    0x000BU,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0003U,

    /* ucPortIndex */
    0x05U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 6 - PortConfigSet_0_Port_Group_10 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000A3C3UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFA3C3UL,

    /* ulInitModePMCSRRegVal */
    0x000008C7UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFEFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0xA200U,

    /* usInitModePIPCRegVal */
    0x0006U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0800U,

    /* usInitModePFCRegVal */
    0x0800U,

    /* usInitModePFCAERegVal */
    0x0007U,

    /* ucPortIndex */
    0x06U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 7 - PortConfigSet_0_Port_Group_11 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x000062FBUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF62FBUL,

    /* ulInitModePMCSRRegVal */
    0x0000001EUL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFF1FU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0203U,

    /* usInitModePIPCRegVal */
    0x000CU,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0002U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x07U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 8 - PortConfigSet_0_Port_Group_12 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFF8UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFF8UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFC7U,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x08U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 9 - PortConfigSet_0_Port_Group_13 */
  {
    /* ulRegListAvailable */
    0x001E8BDBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FF10UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFF10UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFEFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x09U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 10 - PortConfigSet_0_Port_Group_18 */
  {
    /* ulRegListAvailable */
    0x001ECBDBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x00001CE5UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF1CE5UL,

    /* ulInitModePMCSRRegVal */
    0x0000000AUL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xEF7BU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0C61U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x000AU,

    /* usInitModePFCRegVal */
    0x000AU,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0AU,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 11 - PortConfigSet_0_Port_Group_19 */
  {
    /* ulRegListAvailable */
    0x001C0BD3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFF4UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFF4UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0004U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0BU,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 12 - PortConfigSet_0_Port_Group_20 */
  {
    /* ulRegListAvailable */
    0x001FCBF3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFC1UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFDFFFC1UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0001U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0CU,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 13 - PortConfigSet_1_Port_Group_0 */
  {
    /* ulRegListAvailable */
    0x001FCBF3UL,

    /* ulInitModePSRRegVal */
    0x00000400UL,

    /* ulInitModePMSRRegVal */
    0x0000B8D6UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFB8D6UL,

    /* ulInitModePMCSRRegVal */
    0x0000219FUL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x000FU,

    /* usInitModePFCAERegVal */
    0x0180U,

    /* ucPortIndex */
    0x00U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 14 - PortConfigSet_1_Port_Group_1 */
  {
    /* ulRegListAvailable */
    0x001FCBD3UL,

    /* ulInitModePSRRegVal */
    0x00000810UL,

    /* ulInitModePMSRRegVal */
    0x000036CFUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF36CFUL,

    /* ulInitModePMCSRRegVal */
    0x0000020BUL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xCFFBU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0200U,

    /* usInitModePFCRegVal */
    0x0001U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x01U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 15 - PortConfigSet_1_Port_Group_2 */
  {
    /* ulRegListAvailable */
    0x001FCBD3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x00002003UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF2003UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFCU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x02U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 16 - PortConfigSet_1_Port_Group_3 */
  {
    /* ulRegListAvailable */
    0x001E0BD3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFFEUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFFEUL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x03U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 17 - PortConfigSet_1_Port_Group_8 */
  {
    /* ulRegListAvailable */
    0x001FC3D3UL,

    /* ulInitModePSRRegVal */
    0x00000040UL,

    /* ulInitModePMSRRegVal */
    0x0000FD33UL,

    /* ulMaskConfigPMSRRegVal */
    0xF7FFFD33UL,

    /* ulInitModePMCSRRegVal */
    0x00000103UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0103U,

    /* usInitModePFCRegVal */
    0x0100U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x04U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 18 - PortConfigSet_1_Port_Group_9 */
  {
    /* ulRegListAvailable */
    0x001FC3D3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFFFUL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFFFUL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x05U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 19 - PortConfigSet_1_Port_Group_10 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000BBC7UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFBBC7UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFEFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x06U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 20 - PortConfigSet_1_Port_Group_11 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x000062E3UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF62E3UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFF1FU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x07U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 21 - PortConfigSet_1_Port_Group_12 */
  {
    /* ulRegListAvailable */
    0x001FCBFBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFF8UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFF8UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFC7U,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x08U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 22 - PortConfigSet_1_Port_Group_13 */
  {
    /* ulRegListAvailable */
    0x001E8BDBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FF10UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFF10UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFEFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x09U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 23 - PortConfigSet_1_Port_Group_18 */
  {
    /* ulRegListAvailable */
    0x001ECBDBUL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x00001CE5UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFF1CE5UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xEF7BU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0AU,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 24 - PortConfigSet_1_Port_Group_19 */
  {
    /* ulRegListAvailable */
    0x001C0BD3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFF0UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFFFFFF0UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0BU,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 25 - PortConfigSet_1_Port_Group_20 */
  {
    /* ulRegListAvailable */
    0x001FCBF3UL,

    /* ulInitModePSRRegVal */
    0x00000000UL,

    /* ulInitModePMSRRegVal */
    0x0000FFC1UL,

    /* ulMaskConfigPMSRRegVal */
    0xFFDFFFC1UL,

    /* ulInitModePMCSRRegVal */
    0x00000000UL,

    /* ulInitModePODCRegVal */
    0x00000000UL,

    /* ulInitModePDSCRegVal */
    0x00000000UL,

    /* usInitModePISRegVal */
    0xFFFFU,

    /* usInitModePISARegVal */
    0x0000U,

    /* usInitModePIBCRegVal */
    0x0000U,

    /* usInitModePIPCRegVal */
    0x0000U,

    /* usInitModePURegVal */
    0x0000U,

    /* usInitModePDRegVal */
    0x0000U,

    /* usInitModePBDCRegVal */
    0x0000U,

    /* usInitModePFCERegVal */
    0x0000U,

    /* usInitModePFCRegVal */
    0x0000U,

    /* usInitModePFCAERegVal */
    0x0000U,

    /* ucPortIndex */
    0x0CU,

    /* ucDeepStopSupp */
    0x01U
  }
};



/*
 * Array of structures of  JTAG port group registers.
 */
/* CONST(Port_JTAGRegs, PORT_CONST) 
                            Port_GstJTAGRegs[PORT_NUM_OF_JTAG_PORTS]; */

/*
 * Array of structures of  Analog port group registers.
 */
CONST(Port_AnalogRegs, PORT_CONST) 
                            Port_GstAnalogRegs[PORT_NUM_OF_ANALOG_PORTS] =
{
  /* Index: 0 - PortConfigSet_0_Port_Group_0 */
  {
    /* ulMaskConfigAPMSRRegVal */
    0xFFFFFFFFUL,

    /* ulInitModeAPMSRRegVal */
    0x0000FFFFUL,

    /* ulInitModeAPSRRegVal */
    0x00000000UL,

    /* usInitModeAPIBCRegVal */
    0x0000U,

    /* usInitModeAPBDCRegVal */
    0x0000U,

    /* ucPortIndex */
    0x00U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 1 - PortConfigSet_0_Port_Group_1 */
  {
    /* ulMaskConfigAPMSRRegVal */
    0xFFFFF3FFUL,

    /* ulInitModeAPMSRRegVal */
    0x0000F3FFUL,

    /* ulInitModeAPSRRegVal */
    0x00000000UL,

    /* usInitModeAPIBCRegVal */
    0xF000U,

    /* usInitModeAPBDCRegVal */
    0x0000U,

    /* ucPortIndex */
    0x01U,

    /* ucDeepStopSupp */
    0x01U
  },

  /* Index: 2 - PortConfigSet_1_Port_Group_0 */
  {
    /* ulMaskConfigAPMSRRegVal */
    0xFFFFFFFFUL,

    /* ulInitModeAPMSRRegVal */
    0x0000FFFFUL,

    /* ulInitModeAPSRRegVal */
    0x00000000UL,

    /* usInitModeAPIBCRegVal */
    0x0000U,

    /* usInitModeAPBDCRegVal */
    0x0000U,

    /* ucPortIndex */
    0x00U,

    /* ucDeepStopSupp */
    0x00U
  },

  /* Index: 3 - PortConfigSet_1_Port_Group_1 */
  {
    /* ulMaskConfigAPMSRRegVal */
    0xFFFFFFFFUL,

    /* ulInitModeAPMSRRegVal */
    0x0000FFFFUL,

    /* ulInitModeAPSRRegVal */
    0x00000000UL,

    /* usInitModeAPIBCRegVal */
    0x0000U,

    /* usInitModeAPBDCRegVal */
    0x0000U,

    /* ucPortIndex */
    0x01U,

    /* ucDeepStopSupp */
    0x01U
  }
};



/*
 * Array of structures of  Input port group registers.
 */
/* CONST(Port_IPortRegs, PORT_CONST) Port_GstInputRegs[PORT_NUM_OF_INPUT_PORTS]; */

/*
 * Array provides information of port groups which contain run time
 * changeable port pins.
 */
CONST(Port_PinChangeableDetails, PORT_CONST) 
          Port_GstPinChangeableDetailsList[PORT_NUM_OF_PINS_MODIFIABLE] =
{
  /* Index: 0 - PortGroup0_PortPin11 */
  {
    /* ddPinId */
    0x000BU,

    /* usPinPositionMask */
    0x0800U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x00U,

    /* ucPortType */
    0x40U
  },

  /* Index: 1 - PortGroup0_PortPin12 */
  {
    /* ddPinId */
    0x000CU,

    /* usPinPositionMask */
    0x1000U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x00U,

    /* ucPortType */
    0x40U
  },

  /* Index: 2 - PortGroup8_PortPin9 */
  {
    /* ddPinId */
    0x0032U,

    /* usPinPositionMask */
    0x0200U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x04U,

    /* ucPortType */
    0x10U
  },

  /* Index: 3 - PortGroup8_PortPin11 */
  {
    /* ddPinId */
    0x0034U,

    /* usPinPositionMask */
    0x0800U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x04U,

    /* ucPortType */
    0x40U
  },

  /* Index: 4 - PortGroup9_PortPin0 */
  {
    /* ddPinId */
    0x0036U,

    /* usPinPositionMask */
    0x0001U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x05U,

    /* ucPortType */
    0x40U
  },

  /* Index: 5 - PortGroup9_PortPin1 */
  {
    /* ddPinId */
    0x0037U,

    /* usPinPositionMask */
    0x0002U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x05U,

    /* ucPortType */
    0x40U
  },

  /* Index: 6 - PortGroup20_PortPin5 */
  {
    /* ddPinId */
    0x0075U,

    /* usPinPositionMask */
    0x0020U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x0CU,

    /* ucPortType */
    0x40U
  },

  /* Index: 7 - PortGroup8_PortPin11 */
  {
    /* ddPinId */
    0x0034U,

    /* usPinPositionMask */
    0x0800U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x04U,

    /* ucPortType */
    0x40U
  },

  /* Index: 8 - PortGroup20_PortPin5 */
  {
    /* ddPinId */
    0x0075U,

    /* usPinPositionMask */
    0x0020U,

    /* usChangeableConfigVal */
    0x0000U,

    /* ucPortGroupIndex */
    0x0CU,

    /* ucPortType */
    0x40U
  }
};



/* Array of structures for Digital Filter registers and Delay */
/* CONST(Port_DNFARegs, PORT_CONST) Port_GstDNFARegs[PORT_NUM_OF_DNFA]; */

/* Array for Analog and/or Digital Filter registers */
/* CONST(Port_FCLARegs, PORT_CONST) Port_GstFCLARegs[PORT_NUM_OF_FCLA]; */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
