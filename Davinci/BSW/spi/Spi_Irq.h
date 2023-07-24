/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Irq.h                                                   */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Mar-2019                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for prototypes of Interrupt Service Routines.                    */
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
 * V1.0.0:  12-Mar-2019  : Initial Version
 */
/******************************************************************************/

#ifndef SPI_IRQ_H
#define SPI_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
/* Included for interrupt category definitions */
#include "Os.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_IRQ_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_IRQ_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_IRQ_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_IRQ_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_IRQ_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                  directive.                                                */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* EICn */
#define SPI_EIC_EIRF_MASK       (uint16)0x1000U
#define SPI_EIC_EIMK_MASK       (uint16)0x0080U

/* Physical unit number CSIG */
#define SPI_PHYIDX_CSIG0              0U
#define SPI_PHYIDX_CSIG1              1U
#define SPI_PHYIDX_CSIG2              2U
#define SPI_PHYIDX_CSIG3              3U
#define SPI_PHYIDX_CSIG4              4U

/* Physical unit number CSIH */
#define SPI_PHYIDX_CSIH0              0U
#define SPI_PHYIDX_CSIH1              1U
#define SPI_PHYIDX_CSIH2              2U
#define SPI_PHYIDX_CSIH3              3U
#define SPI_PHYIDX_CSIH4              4U

/* Physical unit number DMA CH */
#define SPI_PHYIDX_DMA_00             0U
#define SPI_PHYIDX_DMA_01             1U
#define SPI_PHYIDX_DMA_02             2U
#define SPI_PHYIDX_DMA_03             3U
#define SPI_PHYIDX_DMA_04             4U
#define SPI_PHYIDX_DMA_05             5U
#define SPI_PHYIDX_DMA_06             6U
#define SPI_PHYIDX_DMA_07             7U
#define SPI_PHYIDX_DMA_08             8U
#define SPI_PHYIDX_DMA_09             9U
#define SPI_PHYIDX_DMA_10             10U
#define SPI_PHYIDX_DMA_11             11U
#define SPI_PHYIDX_DMA_12             12U
#define SPI_PHYIDX_DMA_13             13U
#define SPI_PHYIDX_DMA_14             14U
#define SPI_PHYIDX_DMA_15             15U
#define SPI_PHYIDX_DMA_16             16U
#define SPI_PHYIDX_DMA_17             17U
#define SPI_PHYIDX_DMA_18             18U
#define SPI_PHYIDX_DMA_19             19U
#define SPI_PHYIDX_DMA_20             20U
#define SPI_PHYIDX_DMA_21             21U
#define SPI_PHYIDX_DMA_22             22U
#define SPI_PHYIDX_DMA_23             23U
#define SPI_PHYIDX_DMA_24             24U
#define SPI_PHYIDX_DMA_25             25U
#define SPI_PHYIDX_DMA_26             26U
#define SPI_PHYIDX_DMA_27             27U
#define SPI_PHYIDX_DMA_28             28U
#define SPI_PHYIDX_DMA_29             29U
#define SPI_PHYIDX_DMA_30             30U
#define SPI_PHYIDX_DMA_31             31U
#define SPI_PHYIDX_DMA_32             32U
#define SPI_PHYIDX_DMA_33             33U
#define SPI_PHYIDX_DMA_34             34U
#define SPI_PHYIDX_DMA_35             35U
#define SPI_PHYIDX_DMA_36             36U
#define SPI_PHYIDX_DMA_37             37U
#define SPI_PHYIDX_DMA_38             38U
#define SPI_PHYIDX_DMA_39             39U
#define SPI_PHYIDX_DMA_40             40U
#define SPI_PHYIDX_DMA_41             41U
#define SPI_PHYIDX_DMA_42             42U
#define SPI_PHYIDX_DMA_43             43U
#define SPI_PHYIDX_DMA_44             44U
#define SPI_PHYIDX_DMA_45             45U
#define SPI_PHYIDX_DMA_46             46U
#define SPI_PHYIDX_DMA_47             47U
#define SPI_PHYIDX_DMA_48             48U
#define SPI_PHYIDX_DMA_49             49U
#define SPI_PHYIDX_DMA_50             50U
#define SPI_PHYIDX_DMA_51             51U
#define SPI_PHYIDX_DMA_52             52U
#define SPI_PHYIDX_DMA_53             53U
#define SPI_PHYIDX_DMA_54             54U
#define SPI_PHYIDX_DMA_55             55U
#define SPI_PHYIDX_DMA_56             56U
#define SPI_PHYIDX_DMA_57             57U
#define SPI_PHYIDX_DMA_58             58U
#define SPI_PHYIDX_DMA_59             59U
#define SPI_PHYIDX_DMA_60             60U
#define SPI_PHYIDX_DMA_61             61U
#define SPI_PHYIDX_DMA_62             62U
#define SPI_PHYIDX_DMA_63             63U

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG0_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG0_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG0_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG0_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG1_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG1_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG1_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG1_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG2_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG2_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG2_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG2_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG3_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG3_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG3_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG3_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG4_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG4_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIG4_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIG4_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH0_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH0_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH0_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH0_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH1_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH1_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH1_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH1_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH2_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH2_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH2_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH2_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH3_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH3_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH3_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH3_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH4_TIC_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH4_TIC_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_CSIH4_TIR_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_CSIH4_TIR_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA00_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA00_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA01_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA01_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA02_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA02_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA03_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA03_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA04_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA04_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA05_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA05_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA06_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA06_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA07_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA07_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA08_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA08_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA09_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA09_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA10_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA10_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA11_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA11_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA12_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA12_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA13_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA13_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA14_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA14_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA15_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA15_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA16_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA16_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA17_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA17_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA18_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA18_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA19_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA19_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA20_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA20_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA21_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA21_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA22_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA22_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA23_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA23_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA24_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA24_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA25_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA25_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA26_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA26_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA27_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA27_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA28_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA28_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA29_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA29_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA30_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA30_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA31_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA31_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA32_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA32_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA33_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA33_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA34_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA34_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA35_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA35_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA36_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA36_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA37_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA37_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA38_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA38_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA39_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA39_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA40_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA40_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA41_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA41_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA42_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA42_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA43_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA43_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA44_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA44_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA45_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA45_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA46_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA46_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA47_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA47_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA48_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA48_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA49_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA49_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA50_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA50_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA51_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA51_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA52_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA52_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA53_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA53_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA54_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA54_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA55_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA55_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA56_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA56_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA57_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA57_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA58_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA58_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA59_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA59_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA60_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA60_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA61_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA61_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA62_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA62_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined (Os_SPI_DMA63_CAT2_ISR) || (SPI_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, SPI_FAST_CODE) SPI_DMA63_ISR(void);
#endif

#define SPI_STOP_SEC_CODE_FAST
/* QAC Warning: START Msg(2:0832)-1 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif  /* SPI_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
