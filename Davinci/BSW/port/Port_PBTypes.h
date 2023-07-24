/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_PBTypes.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2019 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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

/*PORT_PBTYPES_H_012: EAAR_PN0034_NR_0045*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Sep-2015  : Initial Version
 *
 * V1.0.1:  16-Sep-2015  : The macro SET_PIPC_MAX_MODE is added.
 *
 * V1.0.2:  30-Dec-2015  : The following changes are made
 *                         1. As a part of JIRA ARDAAGA-8 usDNFARegAddrIndex
 *                         member added in Port_DNFARegs structure and
 *                         struct STag_Port_DNFARegs is corrected to match
 *                         structure generated in Port_PBcfg.c
 *                         2. As a part of JIRA ARDAAGA-132
 *                         struct STag_APort_Num_Regs,
 *                         struct STag_JPort_Num_Regs are updated as to match
 *                         structures generated in Port_PBcfg.c
 *                         3. As a part of JIRA ARDAAGA-133 MACROs added
 *                         PORT_MCU_BCKDUP and PORT_ISO_PORTGROUP
 *                         for deepstop mode.
 * V2.0.0:  20-Oct-2016  : As part of ARDAABC-621 Jira ticket, the following
 *                         changes are made:
 *                         1. Changed AUTOSAR lower version to 4.0.3 and
 *                            higher version to 4.2.2. Removed Autosar 3.2.2
 *                            from implementation.
 * V2.1.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Include MemMap header file from "Port_Cfg.h".
 *                         2. Use precompile switches to select different
 *                            memory section names in AR4.0.3 and AR4.2.2.
 * V2.1.1:  25-Nov-2016  : As part of ARDAABC-757 Jira ticket, the following
 *                            changes are made:
 *                         1. Defined new masks to be used for Write Verify
 *                            safety mechanism.
 * V2.1.2:  16-Jan-2017  : As part of ARDAABC-860 Jira ticket, the following
 *                            changes are made:
 *                         1. Removed PORT_DEM_ERROR_DETECT macro.
 * V2.1.3:  31-Jan-2017  : As part of ARDAABC-867 ticket, the following changes
 *                         are made:
 *                         1. Removed code related to Alpha port groups.
 *                         2. Removed code related to PINV registers.
 * V2.1.4:  07-Feb-2017  : As part of ARDAABC-867 ticket, the following changes
 *                         are made:
 *                         1. Removed EDC registers and corresponding
 *                            precompile switches.
 *                         2. Removed DNFCKS registers and corresponding
 *                            precompile switches.
 * V2.2.0:  13-Feb-2017  : Following changes are made:
 *                         1. As part of ARDAABC-978, critical section names
 *                            updated
 * V2.2.1:  08-Mar-2017  : Following changes are made:
 *                         1. As part of ARDAABC-867, added pre-compile switch
 *                            for ucDeepStopSupp
 * V2.2.2:  29-Jun-2017  : As part of ARDAABD-1889, Following changes are made:
 *                         1. Port_JTAGRegs structure is updated to add
 *                         usInitModePISARegVal.
 *                         2. Suffix of ul is changed to UL to avoid
 *                         QAC warning Msg(2:1280).
 *                         3. MISRA C Rule Violations is added for Msg(4:3684).
 * V2.2.3:  18-Sep-2017  : As part of ARDAABD-2379, Naming convention
 *                         is updated for registers.
 * V2.2.4:  21-Jun-2018  : Following changes are made:
 *                         1. As part of ARDAABD-3656, The macro
 *                         PORT_ISO_PORTGROUP is removed.
 *                         2. As part of ARDAABD-2125, The structure
 *                         Port_JTAGRegs is updated to add ucDeepStopSupp.
 *                         3. As part of ARDAABD-3844, Requirements and
 *                         Design ID's are mapped to the implementation in order
 *                         to improve coverage.
 * V2.2.5:  08-Aug-2018  : As part of ARDAABD-1748, MACRO
 *                         PORT_FILTER_DELAY_COUNT was added.
 * V2.2.6:  26-Jul-2019  : 1. As part of ARDAABD-3817, PORT_NO_MCU_BCKDUP is
 *                         defined, and switch(#if (PORT_PIN_STATUS_BACKUP ==
 *                         STD_ON)) for the structure member 'ucDeepStopSupp'
 *                         from Port_AnalogRegs_, Port_JtagRegs_ and
 *                         Port_NumRegs_ structure declaration are removed.
 *                         2.As part of ARDAABD-4075, the macro PORT_JPMSR_MASK 
 *                         was added.
 */
/******************************************************************************/
/* PORT_PBTYPES_H_009: EAAR_PN0034_FR_0001 */
#ifndef PORT_PBTYPES_H
#define PORT_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* PORT_PBTYPES_H_008: PORT080, SWS_Port_00080*/
/* Included for module version information */
#include "Port_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define PORT_PBTYPES_AR_RELEASE_MAJOR_VERSION  PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_MINOR_VERSION  PORT_AR_RELEASE_MINOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                            PORT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define PORT_PBTYPES_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_PBTYPES_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION

/* PORT_PBTYPES_H_013: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026 */

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Macro defines a braced code statement block.      */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3684)-1 and END Msg(4:3684)-1         */
/*                 tags in the code.                                          */

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PORT_PBTYPES_H_010: PORT004, SWS_Port_00004 */
/* PORT_PBTYPES_H_001: PORT_ESDD_UD_136 */
/* PORT_PBTYPES_H_011: PORT_ESDD_UD_016 */
/* General defines */
#define PORT_DBTOC_VALUE        (((uint32)PORT_VENDOR_ID_VALUE << 22) | \
                                ((uint32)PORT_MODULE_ID_VALUE << 14) | \
                                ((uint32)PORT_SW_MAJOR_VERSION_VALUE << 8) | \
                                ((uint32)PORT_SW_MINOR_VERSION_VALUE << 3))
#define PORT_ZERO                      (uint8)0x00
#define PORT_REG_AVAILABLE             (uint8)0x00
#define PORT_RESET_REG_VALUE           (uint8)0x00
#define PORT_PROTECTED_ERR_OCCURRED    (uint8)0x01
#define PORT_MODE_MASK                 (uint8)0x1F
#define PORT_SET_PIPC_MIN_MODE         (uint8)0x82
#define PORT_SET_PIPC_MAX_MODE         ((PORT_MAX_MODE) + (uint8)0x80)
#define PORT_UNINITIALIZED             (boolean)0x00
#define PORT_INITIALIZED               (boolean)0x01
#define PORT_REG_NOTAVAILABLE          (uint8)0xFF
#define PORT_PG_NOTAVAILABLE           (uint8)0xFF
#define PORT_MCU_BCKDUP                (uint8)0x10
#define PORT_NO_MCU_BCKDUP             (uint8)0x00
#define PORT_ISO_PORTGROUP             (uint8)0x01

#define PORT_MODE_DIO                  (Port_PinModeType)0x00


#define PORT_MSB_MASK                  (uint32)0xFFFF0000UL
#define PORT_LSB_MASK                  (uint32)0x0000FFFFUL

#define PORT_BYTE_MASK                 (uint8)0xFF
#define PORT_SHORT_MASK                (uint16)0xFFFF
#define PORT_JPORT_MASK                (uint32)0x000000FFUL
#define PORT_JPMSR_MASK                (uint32)0x0000FFFFUL


#define PORT_IOHOLD_MASK                (uint32)0x00000001UL
#define PORT_IOHOLD_CLEAR               (uint32)0x00000000UL

#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_DIO_OUT                   (Port_PinModeType)0x00
#define PORT_DIO_IN                    (Port_PinModeType)0x01
#endif

#define PORT_BIT_SHIFT_SIXTEEN         (uint8)0x10
#define PORT_MODE_ADJUST               (Port_PinModeType)0x0E

#define PORT_TRUE                      (boolean)0x01
#define PORT_FALSE                     (boolean)0x00


#define PORT_WORD_ZERO                 (uint16)0x0000
#define PORT_LONG_ZERO                 (uint32)0x00000000UL

#define PORT_PG_TYPE_MASK                   (uint8)0x0F
#define PORT_PIN_DIR_CHANGABLE              (uint8)0x40
#define PORT_PIN_MODE_CHANGABLE             (uint8)0x20
#define PORT_PIN_DIO_ALT_CHANGABLE          (uint8)0x10

/* PORT_PBTYPES_H_002: EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0061 */
#define PORT_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                   SchM_Enter_Port_##Exclusive_Area()
#define PORT_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                    SchM_Exit_Port_##Exclusive_Area()

#define PORT_FILTER_DELAY_COUNT         (uint8)4
/*******************************************************************************
**  Global symbols used for For verifying the Modes                           **
*******************************************************************************/
#define PORT_BIT4_MASK                 (uint8)0x10   /* For PMC */
#define PORT_BIT3_MASK                 (uint8)0x08   /* For PFCAE */
#define PORT_BIT2_MASK                 (uint8)0x04   /* For PFCE */
#define PORT_BIT1_MASK                 (uint8)0x02   /* For PFC */
#define PORT_BIT0_MASK                 (uint8)0x01   /* For PM */

/*******************************************************************************
**  Global symbols used for For verifying the Numeric Register availability   **
*******************************************************************************/
#define PORT_PSR_AVAILABLE               (uint32)0x00000001UL
#define PORT_PIS_AVAILABLE               (uint32)0x00000002UL
#define PORT_PISE_AVAILABLE              (uint32)0x00000004UL
#define PORT_PISA_AVAILABLE              (uint32)0x00000008UL
#define PORT_PIBC_AVAILABLE              (uint32)0x00000010UL
#define PORT_PIPC_AVAILABLE              (uint32)0x00000020UL
#define PORT_PU_AVAILABLE                (uint32)0x00000040UL
#define PORT_PD_AVAILABLE                (uint32)0x00000080UL
#define PORT_PBDC_AVAILABLE              (uint32)0x00000100UL
#define PORT_PODC_AVAILABLE              (uint32)0x00000200UL
#define PORT_PODCE_AVAILABLE             (uint32)0x00000400UL
#define PORT_PDSC_AVAILABLE              (uint32)0x00000800UL
#define PORT_PUCC_AVAILABLE              (uint32)0x00001000UL
#define PORT_PFCE_AVAILABLE              (uint32)0x00004000UL
#define PORT_PFC_AVAILABLE               (uint32)0x00008000UL
#define PORT_PFCAE_AVAILABLE             (uint32)0x00010000UL
#define PORT_PMCSR_AVAILABLE             (uint32)0x00020000UL
#define PORT_PMSR_AVAILABLE              (uint32)0x00040000UL
#define PORT_PPROTS_AVAILABLE            (uint32)0x00080000UL
#define PORT_PPCMD_AVAILABLE             (uint32)0x00100000UL

/*******************************************************************************
**  Global symbols used for For verifying the Analog Register availability    **
*******************************************************************************/
#define PORT_APSR_AVAILABLE              (uint32)0x00000001UL
#define PORT_APIS_AVAILABLE              (uint32)0x00000002UL
#define PORT_APISE_AVAILABLE             (uint32)0x00000004UL
#define PORT_APISA_AVAILABLE             (uint32)0x00000008UL
#define PORT_APIBC_AVAILABLE             (uint32)0x00000010UL
#define PORT_APIPC_AVAILABLE             (uint32)0x00000020UL
#define PORT_APU_AVAILABLE               (uint32)0x00000040UL
#define PORT_APD_AVAILABLE               (uint32)0x00000080UL
#define PORT_APBDC_AVAILABLE             (uint32)0x00000100UL
#define PORT_APODC_AVAILABLE             (uint32)0x00000200UL
#define PORT_APDSC_AVAILABLE             (uint32)0x00000400UL
#define PORT_APUCC_AVAILABLE             (uint32)0x00000800UL
#define PORT_APFCE_AVAILABLE             (uint32)0x00002000UL
#define PORT_APFC_AVAILABLE              (uint32)0x00004000UL
#define PORT_APFCAE_AVAILABLE            (uint32)0x00008000UL
#define PORT_APMCSR_AVAILABLE            (uint32)0x00004000UL
#define PORT_APMSR_AVAILABLE             (uint32)0x00008000UL

/*******************************************************************************
**  Global symbols used for For verifying the JTAG Register availability      **
*******************************************************************************/
#define PORT_JPSR_AVAILABLE              (uint32)0x00000001UL
#define PORT_JPIS_AVAILABLE              (uint32)0x00000002UL
#define PORT_JPISE_AVAILABLE             (uint32)0x00000004UL
#define PORT_JPISA_AVAILABLE             (uint32)0x00000008UL
#define PORT_JPIBC_AVAILABLE             (uint32)0x00000010UL
#define PORT_JPIPC_AVAILABLE             (uint32)0x00000020UL
#define PORT_JPU_AVAILABLE               (uint32)0x00000040UL
#define PORT_JPD_AVAILABLE               (uint32)0x00000080UL
#define PORT_JPBDC_AVAILABLE             (uint32)0x00000100UL
#define PORT_JPODC_AVAILABLE             (uint32)0x00000200UL
#define PORT_JPODCE_AVAILABLE            (uint32)0x00000400UL
#define PORT_JPDSC_AVAILABLE             (uint32)0x00000800UL
#define PORT_JPUCC_AVAILABLE             (uint32)0x00001000UL
#define PORT_JPFCE_AVAILABLE             (uint32)0x00004000UL
#define PORT_JPFC_AVAILABLE              (uint32)0x00008000UL
#define PORT_JPFCAE_AVAILABLE            (uint32)0x00010000UL
#define PORT_JPMCSR_AVAILABLE            (uint32)0x00020000UL
#define PORT_JPMSR_AVAILABLE             (uint32)0x00040000UL
#define PORT_JPPROTS_AVAILABLE           (uint32)0x00080000UL
#define PORT_JPPCMD_AVAILABLE            (uint32)0x00100000UL

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type definition for Port Group types */
/* PORT_PBTYPES_H_007: PORT108,PORT205,SWS_Port_00205,PORT076,SWS_Port_00076 */
typedef enum ETag_Port_GroupType
{
  PORT_GROUP_NUMERIC,
  PORT_GROUP_JTAG,
  PORT_GROUP_ANALOG,
  PORT_GROUP_INPUT
} Port_GroupType;


/*******************************************************************************
** Structure declaration of port group registers PMSR, PFCE, PFC              **
** and PMCSR.                                                                 **
** This structure will be generated in the following sequence of registers:   **
** PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC, PDSC, PFC, PFCE,     **
** PFCAE, PMSR, PMCSR, PORTGROUPINDEX, PORTREGAVAILABLE                       **
*******************************************************************************/
/* PORT_PBTYPES_H_003: PORT_ESDD_UD_082 */
typedef struct STag_Port_Num_Regs
{
  /*For verifying the Numeric Register's availability*/
  uint32 ulRegListAvailable;

  /* Configured value of the port group PSR registers for initial mode.  */
  uint32 ulInitModePSRRegVal;

  /* Configured value of the port group PMSR registers for initial mode. */
  uint32 ulInitModePMSRRegVal;

  /* Bit value of upper 16 bits (31 - 16) is to set 0 if for pin
  * "PortPinDirectionChangeable" is configured as true
  * Bit value of upper 16 bits (31 - 16) is to set 1 if for pin
  * "PortPinDirectionChangeable" configured as false
  * Bit value of lower 16 bits (15 - 0) = Initial value of the corresponding
  * pin
  */
  uint32 ulMaskConfigPMSRRegVal;

  /* Configured value of the port group PMCSR registers for initial mode. */
  uint32 ulInitModePMCSRRegVal;

  /* Configured value of the port group PODC registers for initial mode. */
  uint32 ulInitModePODCRegVal;

  /* Configured value of the port group PDSC registers for initial mode. */
  uint32 ulInitModePDSCRegVal;

  /* Configured value of the port group PIS registers for initial mode. */
  uint16 usInitModePISRegVal;

  /* Configured value of the port group PISA registers for initial mode. */
  uint16 usInitModePISARegVal;

  /* Configured value of the port group PIBC registers for initial mode. */
  uint16 usInitModePIBCRegVal;

  /* Configured value of the port group PIPC registers for initial mode. */
  uint16 usInitModePIPCRegVal;

  /* Configured value of the port group PU registers for initial mode. */
  uint16 usInitModePURegVal;

  /* Configured value of the port group PD registers for initial mode. */
  uint16 usInitModePDRegVal;

  /* Configured value of the port group PBDC registers for initial mode. */
  uint16 usInitModePBDCRegVal;

  /* Configured value of the port group PFCE registers for initial mode. */
  uint16 usInitModePFCERegVal;

  /* Configured value of the port group PFC registers for initial mode. */
  uint16 usInitModePFCRegVal;

  /* Configured value of the port group PFCAE registers for initial mode. */
  uint16 usInitModePFCAERegVal;

  /* Port Group Index */
  uint8 ucPortIndex;

  /* Port DeepStop*/
  uint8 ucDeepStopSupp;

}Port_NumRegs;

typedef struct STag_JPort_Num_Regs
{
  /* Bit value of upper 16 bits (31 - 16) is to set 0 if for pin
  * "PortPinDirectionChangeable" is configured as true
  * Bit value of upper 16 bits (31 - 16) is to set 1 if for pin
  * "PortPinDirectionChangeable" configured as false
  * Bit value of lower 16 bits (15 - 0) = Initial value of the corresponding
  * pin
  */
  uint32 ulMaskConfigJPMSRRegVal;

  /* Configured value of the port group JPSR registers for initial mode.  */
  uint32 ulInitModeJPSRRegVal;

  /* Configured value of the port group JPMSR registers for initial mode. */
  uint32 ulInitModeJPMSRRegVal;

  /* Configured value of the port group JPODC registers for initial mode. */
  uint32 ulInitModeJPODCRegVal;

  /* Configured value of the port group JPMCSR registers for initial mode. */
  uint32 ulInitModeJPMCSRRegVal;

  /* Configured value of the port group JPIBC registers for initial mode. */
  uint16 usInitModeJPIBCRegVal;

  /* Configured value of the port group JPDSC registers for initial mode. */
  uint32 ulInitModeJPDSCRegVal;

  /* Configured value of the port group JPU registers for initial mode. */
  uint16 usInitModeJPURegVal;

  /* Configured value of the port group JPBDC registers for initial mode. */
  uint16 usInitModeJPBDCRegVal;

  /* Configured value of the port group JPIS registers for initial mode. */
  uint16 usInitModeJPISRegVal;

  /* Configured value of the port group JPFC registers for initial mode. */
  uint16 usInitModeJPFCRegVal;

  /* Configured value of the port group JPD registers for initial mode. */
  uint16 usInitModeJPDRegVal;

  /* Configured value of the port group JPFCE registers for initial mode. */
  uint16 usInitModeJPFCERegVal;

  /* Configured value of the port group JPISA registers for initial mode. */
  uint16 usInitModeJPISARegVal;

  /* Port Group Index */
  uint8 ucPortIndex;

  /* Port DeepStop*/
  uint8 ucDeepStopSupp;

}Port_JTAGRegs;

typedef struct STag_APort_Num_Regs
{
  /* Bit value of upper 16 bits (31 - 16) is to set 0 if for pin
  * "PortPinDirectionChangeable" is configured as true
  * Bit value of upper 16 bits (31 - 16) is to set 1 if for pin
  * "PortPinDirectionChangeable" configured as false
  * Bit value of lower 16 bits (15 - 0) = Initial value of the corresponding
  * pin
  */
  uint32 ulMaskConfigAPMSRRegVal;

  /* Configured value of the port group APMSR registers for initial mode. */
  uint32 ulInitModeAPMSRRegVal;

  /* Configured value of the port group APSR registers for initial mode.  */
  uint32 ulInitModeAPSRRegVal;

  /* Configured value of the port group APIBC registers for initial mode. */
  uint16 usInitModeAPIBCRegVal;

  /* Configured value of the port group APBDC registers for initial mode. */
  uint16 usInitModeAPBDCRegVal;

  /* Port Group Index */
  uint8 ucPortIndex;

  /* Port DeepStop*/
  uint8 ucDeepStopSupp;

}Port_AnalogRegs;

typedef struct STag_IPort_Regs
{
 /* Configured value of the port group IPIBC registers for initial mode. */
  uint16 usInitModeIPIBCRegVal;
  /* Port group Index for the configured group */
  uint8 ucPortIndex;
}Port_IPortRegs;


/*******************************************************************************
** Structure containing information on PINs whose direction can be changed    **
** during run time                                                            **
*******************************************************************************/
#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || \
    (PORT_SET_PIN_MODE_API == STD_ON)\
    || (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON))
typedef struct STag_Port_PinChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;

  /* Mask value to check whether the requested direction and current direction
   * of the PIN are same.
   */
  uint16 usPinPositionMask;

  /* Configured level value for PSR register */
  uint16 usChangeableConfigVal;

  /* Indicates Port group*/
  uint8 ucPortGroupIndex;

  /* Indicates the Port type (Numeric/ JTAG/ Analog)
   * Last Nibble Indicates DIR/MODE/DIO-ALT
   */
  uint8 ucPortType;

}Port_PinChangeableDetails;
#endif
/*******************************************************************************
** Structure contains the declaration for DNFA registers                      **
** This structure will be generated in the following sequence of registers:   **
** DNFAnCTL, DNFAnEN.                                                         **
*******************************************************************************/
/* PORT_PBTYPES_H_004: PORT_ESDD_UD_112 */
typedef struct STag_Port_DNFARegs
{
  uint16 usDNFARegAddrIndex;
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  /* Configured value for DNFA noise elimination enable register */
  uint16 usDNFAEN;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  uint16 usDELAY;
  /* Configured value for DNFA noise elimination control register */
  uint8 ucDNFACTL;
} Port_DNFARegs;

/*******************************************************************************
** Structure contains the declaration for FCLA registers                      **
** This structure will be generated in the following sequence of registers:   **
** FCLAnCTL.                                                                  **
*******************************************************************************/
/* PORT_PBTYPES_H_005: PORT_ESDD_UD_113 */
typedef struct STag_Port_FCLARegs
{
  /* Register Offset */
  uint16 usFCLARegOffset;
  /* Configured value for FCLA noise elimination control register */
  uint8 ucFCLACTL;
} Port_FCLARegs;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
/* PORT_PBTYPES_H_006: PORT_ESDD_UD_135 */
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE
/* MISRA Violation: START Msg(4:3684)-1 */
#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_NumRegs, PORT_CONST)
                                Port_GstNumRegs[PORT_NUM_OF_NUMERIC_PORTS];
#endif

#if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_JTAGRegs, PORT_CONST)
                                  Port_GstJTAGRegs[PORT_NUM_OF_JTAG_PORTS];
#endif

#if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_AnalogRegs, PORT_CONST)
                              Port_GstAnalogRegs[PORT_NUM_OF_ANALOG_PORTS];
#endif

#if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_IPortRegs, PORT_CONST)
                                Port_GstInputRegs[PORT_NUM_OF_INPUT_PORTS];
#endif

#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || \
  (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
extern CONST(Port_PinChangeableDetails, PORT_CONST)
             Port_GstPinChangeableDetailsList[PORT_NUM_OF_PINS_MODIFIABLE];
#endif

#if (PORT_DNFA_REG_CONFIG == STD_ON)
extern CONST(Port_DNFARegs, PORT_CONST) Port_GstDNFARegs[PORT_NUM_OF_DNFA];
#endif

#if (PORT_FCLA_REG_CONFIG == STD_ON)
extern CONST(Port_FCLARegs, PORT_CONST) Port_GstFCLARegs[PORT_NUM_OF_FCLA];
#endif
/* END Msg(4:3684)-1 */

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
  #define PORT_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#else
  #define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#include PORT_MEMMAP_FILE

#define PORT_DEM_TYPE Dem_EventStatusType


#endif /* PORT_PBTYPES_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
