/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_LTTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2017-2018 Renesas Electronics Corporation                     */
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

/*******************************************************************************
 **                      Revision Control History                             **
 ******************************************************************************/
/*
 * V1.0.0:  10-Jul-2017  : Initial Version
 * V1.0.1:  19-Oct-2017  : Following changes are made:
 *                         1.As part of ARDAABD-2380,updated section
 *                           Global Symbols by modifying macros.
 *                         2.As part of ARDAABD-2484,updated section
 *                           Global Symbols by adding macros.
 *                         3.As part of QAC Analysis, added macro
 *                           DIO_LEFT_SHIFT_SIXTEEN.
 * V1.0.2:  24-Jul-2018 :  Following changes are made:
 *                         1. As part of ARDAABD-2990,
 *                            a. DIO_RAM_MIRROR Values has been removed.
 *                            b. DIO_GET_MASK_LOWER_SIXTEEN &
 *                               DIO_GET_MASK_LOWER_EIGHT macros has been
 *                               removed.
 *                         2. Updated copyright information.
 *                         3. As part of ARDAABD-3851 to improve traceability,
 *                            a.Removed all the redundant and obsolete
 *                              requirements.
 *                            b.Added missing requirements from requirement
 *                              documents.
 */
/******************************************************************************/
/* DIO_LTTYPES_H_007: EAAR_PN0034_FR_0001 */
#ifndef DIO_LTTYPES_H
#define DIO_LTTYPES_H

/******************************************************************************/

/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

/*******************************************************************************
 **                      Version Information                                  **
 ******************************************************************************/
/* AUTOSAR release version information */
#define DIO_LTTYPES_AR_RELEASE_MAJOR_VERSION  DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_LTTYPES_AR_RELEASE_MINOR_VERSION  DIO_AR_RELEASE_MINOR_VERSION
#define DIO_LTTYPES_AR_RELEASE_REVISION_VERSION \
                                              DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_LTTYPES_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION
#define DIO_LTTYPES_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION

/*******************************************************************************
 **                      MISRA C Rule Violations                              **
 ******************************************************************************/

/*******************************************************************************
 **                      Global Symbols                                       **
 ******************************************************************************/
/* General defines */
#define DIO_DBTOC_VALUE ((((uint32)DIO_VENDOR_ID) << 22) | \
                         (((uint32)DIO_MODULE_ID) << 14) | \
                         (((uint32)DIO_SW_MAJOR_VERSION) << 8) | \
                         (((uint32)DIO_SW_MINOR_VERSION) << 3))

/* DIO_LTTYPES_H_001: DIO127, SWS_Dio_00127 */
/* DIO_LTTYPES_H_008: DIO_ESDD_UD_002 */
#define DIO_NORMALPORT                      (Dio_PortType)2
#define DIO_JTAGPORT                        (Dio_PortType)1
#define DIO_INPUTPORT                       (Dio_PortType)0
#define DIO_ANALOGPORT                      (Dio_PortType)3

#define DIO_LOW_LEVEL_OUTPUT                 (uint16)0x0000
#define DIO_OUTPUT_MODE_PIN_EXISTENCE_CHECK  (uint16)0x0000
#define DIO_HIGH_LEVEL_OUTPUT                (uint16)0x0001
#define DIO_SHIFT_SIXTEEN                     0x10000UL
#define DIO_LEFT_SHIFT_SIXTEEN                16U
#define DIO_SET_MASK_UPPER_SIXTEEN            0xFFFF0000UL
#define DIO_ZERO_PORTREG                      0U

#define DIO_ZERO_PORTOFFSET                   0x00U
#define DIO_ZERO_CHANNELOFFSET                0x00U
#define DIO_ZERO_CHANNELGROUPOFFSET           0x00U


/*******************************************************************************
 **               SchM Critical Section Protection Macros                     **
 ******************************************************************************/
/* DIO_LTTYPES_H_002: DIO005, SWS_Dio_00005 */
/* DIO_LTTYPES_H_006: DIO_ESDD_UD_017       */
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#define DIO_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                   SchM_Enter_Dio_##Exclusive_Area()
#define DIO_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                   SchM_Exit_Dio_##Exclusive_Area()
#endif
/*******************************************************************************
 **                      Global Data Types                                    **
 ******************************************************************************/
/* DIO_WRITE_VERIFY Values */
/* Macro for Register readback disable */
#define DIO_WV_DISABLE                            0U
/* Macro for Register readback INIT_ONLY */
#define DIO_WV_INIT_ONLY                          1U
/* Macro for Register readback INIT_RUNTIME */
#define DIO_WV_INIT_RUNTIME                       2U

/* DIO_RAM_MIRROR Values */
/* Macro for RAM Mirror Disable */
#define DIO_RAM_MIRROR_DISABLE                    0U
/* Macro for RAM Mirror Enable */
#define DIO_RAM_MIRROR_ENABLE                     1U
#if (DIO_RAM_MIRROR == DIO_RAM_MIRROR_ENABLE)
/* Type of Hardware Consistency check */
typedef enum ETag_Dio_HWConsistencyCheckType
{
  DIO_HW_CONSIST_CHECK_STATIC,
  DIO_HW_CONSIST_CHECK_DYNAMIC
}Dio_HWConsistencyCheckType;
#endif
/* DIO_LTTYPES_H_003: DIO_ESDD_UD_024 */
/* Structure for Dio Port Group */
typedef struct STag_Dio_PortGroup {
  /* Port Group Index */
  uint8 ucPortGroupIndex;
  uint32 ulModeMask;
  /* Type Of the port group,
     0 = Input port,
     1 = Jtag port,
     2 = Numeric/Alphabetic port,
     3 = Analog port */
  uint8 ucPortType;
} Dio_PortGroup;

/* DIO_LTTYPES_H_004: DIO128, SWS_Dio_00128 */
/* DIO_LTTYPES_H_005: DIO_ESDD_UD_026 */
/* Structure for Dio Channel */
typedef struct STag_Dio_PortChannel {
  uint16 usMask;
  /* PortGroup Index in the array Dio_GstPortChannel[] with respect to the
     pointer Dio_GpPortChannel of the corresponding configuration */
  uint8 ucPortIndex;
} Dio_PortChannel;

/*******************************************************************************
 **                       Extern declarations for Global Data                 **
 ******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include DIO_MEMMAP_FILE

/* DIO_LTTYPES_H_009: DIO_ESDD_UD_035 */
extern CONST(Dio_PortGroup, DIO_CONST)
                                    Dio_GstPortGroup[DIO_PORT_GROUP_ARRAY_SIZE];
#if (DIO_CHANNEL_CONFIGURED == STD_ON)

extern CONST(Dio_PortChannel, DIO_CONST)
                                     Dio_GstPortChannel[DIO_CHANNEL_ARRAY_SIZE];
#endif


#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
#include DIO_MEMMAP_FILE

/*******************************************************************************
 **                      Function Prototypes                                  **
 ******************************************************************************/

#endif
/* DIO_LTTYPES_H */

/*******************************************************************************
 **                         End of File                                       **
 ******************************************************************************/
