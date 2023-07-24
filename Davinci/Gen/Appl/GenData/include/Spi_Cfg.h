/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019 Renesas Electronics Corporation. All rights reserved.             */
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
/*              Devices:        R7F701651                                     */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:      12-Feb-2019:      Initial Version
 */

/*******************************************************************************
**                      Generation Tool Version                               **
*******************************************************************************/
/*                                                                            */
/* TOOL VERSION:  1.0.0                                                       */
/*                                                                            */

/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5761450\Generation\Cfg_Gen-1599208913269-0\AutosarFiles_ValGen3763191865339178278\ExtGen_DrvSpi_ECUC_4.2.2_8046980392920154194.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\spi\generator\R422_SPI_F1x_BSWMDT.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\common_family\generator\Sample_Application_F1x.trxml
 * GENERATED ON:  04 9月 2020 - 06:37:12
 */

#ifndef SPI_CFG_H
#define SPI_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi_Test.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define SPI_CFG_AR_RELEASE_MAJOR_VERSION                4U
#define SPI_CFG_AR_RELEASE_MINOR_VERSION                2U
#define SPI_CFG_AR_RELEASE_REVISION_VERSION             2U

/* File version information */
#define SPI_CFG_SW_MAJOR_VERSION                        1U
#define SPI_CFG_SW_MINOR_VERSION                        0U

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

#define SPI_AR_RELEASE_MAJOR_VERSION_VALUE              4U

#define SPI_AR_RELEASE_MINOR_VERSION_VALUE              2U

#define SPI_AR_RELEASE_REVISION_VERSION_VALUE           2U

#define SPI_SW_MAJOR_VERSION_VALUE                      1U

#define SPI_SW_MINOR_VERSION_VALUE                      0U

#define SPI_SW_PATCH_VERSION_VALUE                      0U

#define SPI_VENDOR_ID_VALUE                             59U

#define SPI_MODULE_ID_VALUE                             83U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the SPI SpiDriver */
#define SPI_INSTANCE_ID_VALUE                           0U

/* AUTOSAR version information */
#define SPI_AR_VERSION                                  SPI_AR_422_VERSION

/* Attach library Memmap */
#define SPI_MEMMAP_FILE                                 "Spi_MemMap.h"


/* Enables/Disables GetVersionInfo API */
#define SPI_VERSION_INFO_API                            STD_OFF

/* Enables/Disables GetHWUnitStatus API */
#define SPI_HW_STATUS_API                               STD_OFF

/* Enables/Disables Cancel API */
#define SPI_CANCEL_API                                  STD_OFF

/* Enables/Disables Force Cancel API */
#define SPI_FORCE_CANCEL_API                            STD_OFF

/* Enables/Disables Development error detection */
#define SPI_DEV_ERROR_DETECT                            STD_OFF

/* Pre-compile option for enable or disable inter-module dependencies */
#define SPI_VERSION_CHECK_EXT_MODULES                   STD_OFF

/* Switches the Interruptible SpiSequence handling functionality ON or OFF */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED                   STD_ON

/* Enables/Disables configuration of Direct Access Memory mode selection */
#define SPI_DIRECT_ACCESS_MODE                          STD_OFF

/* Enables/Disables configuration of Dual Buffer mode selection */
#define SPI_DUAL_BUFFER_MODE                            STD_OFF

/* Enables/Disables configuration of Tx Only mode selection */
#define SPI_TX_ONLY_MODE                                STD_OFF

/* Enables/Disables configuration of FIFO mode selection */
#define SPI_FIFO_MODE                                   STD_ON

/* Enables/Disables configuration of critical section functionality */
#define SPI_CRITICAL_SECTION_PROTECTION                 STD_ON

/* Specifies whether concurrent Spi_SyncTransmit() calls for different        */
/*   sequences shall be configurable                                          */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT            STD_OFF

/* Specifies whether parallel async transmission is supported */
#define SPI_SUPPORT_CONCURRENT_ASYNC_TRANSMIT           STD_OFF

/* Enables/Disables the SPI_E_ALREADY_INITIALIZED Det error check in          */
/*   Spi_Init API                                                             */
#define SPI_ALREADY_INIT_DET_CHECK                      STD_OFF

/* Enables/Disables the names configured in SpiSeqStartNotification */
#define SPI_SEQ_STARTNOTIFICATION_ENABLED               STD_OFF

/* Enables/Disables the check for the names configured for synchronous        */
/*   transmissions in SpiSeqEndNotification                                   */
#define SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED            STD_OFF

/* Enables/Disables the check when HW configuration is static or dynamic HW */
#define SPI_PERSISTENT_HW_CONFIGURATION_ENABLED         STD_OFF

/* Enables/Disables the extended data length mode */
#define SPI_EXTENDED_DATA_LENGTH                        STD_OFF

/* Enables/Disables configuration of data consistency check */
#define SPI_DATA_CONSISTENCY_CHECK                      STD_OFF

/* This parameter enables/disables module wise ISR category.. */
#define SPI_ISR_CATEGORY_2                              STD_ON

/* Enables/Disables configuration of chip select software driven */
#define SPI_CS_VIA_GPIO_CONFIGURED                      STD_OFF

/* Enables/Disables configuration of low power setting for supporting         */
/*   different clock                                                          */
#define SPI_SET_CLOCK_MODE_ENABLED                      STD_OFF

/* Enables/Disables Loop back self test functionality */
#define SPI_LOOPBACK_SELFTEST                           0U

/* Enables/Disables ECC self test functionality */
#define SPI_ECC_SELFTEST                                0U

/* Enables/Disables the register read back functionality for CSIG and CSIH    */
/*   registers                                                                */
#define SPI_CSIX_WRITE_VERIFY                           0U

/* Enables/Disables the register read back functionality for DMA registers */
#define SPI_DMA_WRITE_VERIFY                            0U

/* Enables/Disables user write verify error interface usage */
#define SPI_USE_WRITE_VERIFY_ERROR_INTERFACE            STD_OFF


/* Enables/Disables RAM mirroring for CSIG and CSIH peripherals */
#define SPI_CSIX_RAM_MIRROR                             STD_OFF

/* Enables/Disables RAM mirroring for DMA peripheral */
#define SPI_DMA_RAM_MIRROR                              STD_OFF

/* This parameter enables/disables the interrupt consistency check in the     */
/*   ISRs.                                                                    */
#define SPI_INTERRUPT_CONSISTENCY_CHECK                 STD_OFF

/* Enables/Disables the SpiDma mode */
#define SPI_DMA_CONFIGURED                              STD_OFF

/* Configuration of CSIH hardware unit */
#define SPI_CSIH_CONFIGURED                             STD_ON

/* Configuration of CSIG hardware unit */
#define SPI_CSIG_CONFIGURED                             STD_OFF

/* Select the SPI Handler/SpiDriver level of scalable functionality */
#define SPI_LEVEL_DELIVERED                             2U

/* Select the SPI Handler/SpiDriver Channel Buffers usage allowed */
#define SPI_CHANNEL_BUFFERS_ALLOWED                     2U

/* Number of Tx/Rx IB buffers of channels associated to Direct Access mode,   */
/*   FIFO mode, and Tx mode                                                   */
#define SPI_MAX_CHANNEL_BUFFER_SIZE                     0U

/* Number of Channels configured SpiChannelType as EB */
#define SPI_EBDATA_SIZE                                 1U

/* The maximum value of SpiMaxChannel in all configuration sets */
#define SPI_MAX_CHANNEL                                 (Spi_ChannelType)1

/* The maximum value of SpiMaxJob in all configuration sets */
#define SPI_MAX_JOB                                     (Spi_JobType)1

/* The maximum value of SpiMaxSequence in all configuration sets */
#define SPI_MAX_SEQUENCE                                (Spi_SequenceType)1

/* Gives the maximum queue used */
#define SPI_MAX_QUEUE                                   1U

/* The maximum number of HW units in all configuration sets */
#define SPI_MAX_HWUNIT                                  1U

/* The maximum number of DMA channels in all configuration sets */
#define SPI_MAX_DMA_CHANNELS                            0U

/* Hardware buffer size */
#define SPI_CSIH_HW_BUFFER_SIZE                         128U

/* The internal diagnosis error buffer size */
#define SPI_MAX_ERROR_BUFFER_SIZE                       0U







/* Handles for configured SpiChannel */
#define SpiConf0_SpiChannel_CSIH3                       (Spi_ChannelType)0U

/* Handles for configured SpiJob */
#define SpiConf0_SpiJob_SpiJob1                         (Spi_JobType)0U

/* Handles for configured SpiSequence */
#define SpiConf0_SpiSequence_SpiSequence                (Spi_SequenceType)0U

/* Handles for configured HW unit */
#define SpiConf0_SpiHwUnit_CSIH3                        (Spi_HWUnitType)0

#define SpiConf0_SpiDriver_SpiDriver0                   \
                                                      (&Spi_GaaConfiguration[0])

/* Macros for enabling/disabling Hardware units ISRS */
#define SPI_CSIH0_TIC_ISR_API                           STD_OFF
#define SPI_CSIH1_TIC_ISR_API                           STD_OFF
#define SPI_CSIH2_TIC_ISR_API                           STD_OFF
#define SPI_CSIH3_TIC_ISR_API                           STD_OFF
#define SPI_CSIH4_TIC_ISR_API                           STD_OFF
#define SPI_CSIH0_TIR_ISR_API                           STD_OFF
#define SPI_CSIH1_TIR_ISR_API                           STD_OFF
#define SPI_CSIH2_TIR_ISR_API                           STD_OFF
#define SPI_CSIH3_TIR_ISR_API                           STD_ON
#define SPI_CSIH4_TIR_ISR_API                           STD_OFF
#define SPI_CSIG0_TIC_ISR_API                           STD_OFF
#define SPI_CSIG1_TIC_ISR_API                           STD_OFF
#define SPI_CSIG2_TIC_ISR_API                           STD_OFF
#define SPI_CSIG3_TIC_ISR_API                           STD_OFF
#define SPI_CSIG4_TIC_ISR_API                           STD_OFF
#define SPI_CSIG0_TIR_ISR_API                           STD_OFF
#define SPI_CSIG1_TIR_ISR_API                           STD_OFF
#define SPI_CSIG2_TIR_ISR_API                           STD_OFF
#define SPI_CSIG3_TIR_ISR_API                           STD_OFF
#define SPI_CSIG4_TIR_ISR_API                           STD_OFF
#define SPI_DMA00_ISR_API                               STD_OFF
#define SPI_DMA01_ISR_API                               STD_OFF
#define SPI_DMA02_ISR_API                               STD_OFF
#define SPI_DMA03_ISR_API                               STD_OFF
#define SPI_DMA04_ISR_API                               STD_OFF
#define SPI_DMA05_ISR_API                               STD_OFF
#define SPI_DMA06_ISR_API                               STD_OFF
#define SPI_DMA07_ISR_API                               STD_OFF
#define SPI_DMA08_ISR_API                               STD_OFF
#define SPI_DMA09_ISR_API                               STD_OFF
#define SPI_DMA10_ISR_API                               STD_OFF
#define SPI_DMA11_ISR_API                               STD_OFF
#define SPI_DMA12_ISR_API                               STD_OFF
#define SPI_DMA13_ISR_API                               STD_OFF
#define SPI_DMA14_ISR_API                               STD_OFF
#define SPI_DMA15_ISR_API                               STD_OFF
#define SPI_DMA16_ISR_API                               STD_OFF
#define SPI_DMA17_ISR_API                               STD_OFF
#define SPI_DMA18_ISR_API                               STD_OFF
#define SPI_DMA19_ISR_API                               STD_OFF
#define SPI_DMA20_ISR_API                               STD_OFF
#define SPI_DMA21_ISR_API                               STD_OFF
#define SPI_DMA22_ISR_API                               STD_OFF
#define SPI_DMA23_ISR_API                               STD_OFF
#define SPI_DMA24_ISR_API                               STD_OFF
#define SPI_DMA25_ISR_API                               STD_OFF
#define SPI_DMA26_ISR_API                               STD_OFF
#define SPI_DMA27_ISR_API                               STD_OFF
#define SPI_DMA28_ISR_API                               STD_OFF
#define SPI_DMA29_ISR_API                               STD_OFF
#define SPI_DMA30_ISR_API                               STD_OFF
#define SPI_DMA31_ISR_API                               STD_OFF
#define SPI_DMA32_ISR_API                               STD_OFF
#define SPI_DMA33_ISR_API                               STD_OFF
#define SPI_DMA34_ISR_API                               STD_OFF
#define SPI_DMA35_ISR_API                               STD_OFF
#define SPI_DMA36_ISR_API                               STD_OFF
#define SPI_DMA37_ISR_API                               STD_OFF
#define SPI_DMA38_ISR_API                               STD_OFF
#define SPI_DMA39_ISR_API                               STD_OFF
#define SPI_DMA40_ISR_API                               STD_OFF
#define SPI_DMA41_ISR_API                               STD_OFF
#define SPI_DMA42_ISR_API                               STD_OFF
#define SPI_DMA43_ISR_API                               STD_OFF
#define SPI_DMA44_ISR_API                               STD_OFF
#define SPI_DMA45_ISR_API                               STD_OFF
#define SPI_DMA46_ISR_API                               STD_OFF
#define SPI_DMA47_ISR_API                               STD_OFF
#define SPI_DMA48_ISR_API                               STD_OFF
#define SPI_DMA49_ISR_API                               STD_OFF
#define SPI_DMA50_ISR_API                               STD_OFF
#define SPI_DMA51_ISR_API                               STD_OFF
#define SPI_DMA52_ISR_API                               STD_OFF
#define SPI_DMA53_ISR_API                               STD_OFF
#define SPI_DMA54_ISR_API                               STD_OFF
#define SPI_DMA55_ISR_API                               STD_OFF
#define SPI_DMA56_ISR_API                               STD_OFF
#define SPI_DMA57_ISR_API                               STD_OFF
#define SPI_DMA58_ISR_API                               STD_OFF
#define SPI_DMA59_ISR_API                               STD_OFF
#define SPI_DMA60_ISR_API                               STD_OFF
#define SPI_DMA61_ISR_API                               STD_OFF
#define SPI_DMA62_ISR_API                               STD_OFF
#define SPI_DMA63_ISR_API                               STD_OFF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif /* SPI_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

