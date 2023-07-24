/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Lcfg.c                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2017-2018 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
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
 * V1.0.0:  10-Jul-2017  : Initial Version
 * V1.0.1   18-Apr-2018  : Following changes are made:
 *                         1. As part of Merging activity,ARDAABD-3484  
 *                            a. QAC warning justifiaction
 *                            added for Msg(2:0862).
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.2.5
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5734869\Generation\Cfg_Gen-1607756599923-0\AutosarFiles_ValGen5020245192776930963\ExtGen_DrvDio_ECUC_4.2.2_6230620678829164241.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\dio\generator\R422_DIO_F1x_BSWMDT.arxml
 * GENERATED ON:  12 Dec 2020 - 15:04:55
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dio.h"
#include "Dio_LTTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_LCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_LCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define DIO_LCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define DIO_LCFG_C_SW_MAJOR_VERSION   2U
#define DIO_LCFG_C_SW_MINOR_VERSION   0U


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_LTTYPES_AR_RELEASE_MAJOR_VERSION != \
         DIO_LCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Release Major Version"
#endif

#if (DIO_LTTYPES_AR_RELEASE_MINOR_VERSION != \
         DIO_LCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Release Minor Version"
#endif

#if (DIO_LTTYPES_AR_RELEASE_REVISION_VERSION != \
         DIO_LCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Release Revision Version"
#endif

#if (DIO_LTTYPES_SW_MAJOR_VERSION != DIO_LCFG_C_SW_MAJOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Software Major Version"
#endif

#if (DIO_LTTYPES_SW_MINOR_VERSION != DIO_LCFG_C_SW_MINOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                        QAC Warning                                        **
 ******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC WARNING:                                                            */
/* Message       : (2:0862) This #include MemMap.h directive is               */
/*                  redundant                                                 */
/* Justification : Inclusion of the Det.h and MemMap.h file                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


#define DIO_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Structure of DIO Port Group Configuration */
CONST (Dio_PortGroup, DIO_CONST)
                              Dio_GstPortGroup[DIO_PORT_GROUP_ARRAY_SIZE] =
{
  /* Index: 0 - DioPortAnalog0 */
  {
    /* ucPortGroupIndex */
    0x00U,

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x03U
  },

  /* Index: 1 - DioPort00 */
  {
    /* ucPortGroupIndex */
    0x03U,

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 2 - DioPort01_8To15 */
  {
    /* ucPortGroupIndex */
    0x04U,

    /* ulModeMask */
    0xFFFF00FFUL,

    /* ucPortType */
    0x02U
  },

  /* Index: 3 - DioPort02 */
  {
    /* ucPortGroupIndex */
    0x0AU,

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 4 - DioPort03 */
  {
    /* ucPortGroupIndex */
    0x0CU,

    /* ulModeMask */
    0xFFFFFFFEUL,

    /* ucPortType */
    0x02U
  },

  /* Index: 5 - DioPort08 */
  {
    /* ucPortGroupIndex */
    0x06U,

    /* ulModeMask */
    0xFFFFE000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 6 - DioPort09 */
  {
    /* ucPortGroupIndex */
    0x01U,

    /* ulModeMask */
    0xFFFFFFE0UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 7 - DioPort10 */
  {
    /* ucPortGroupIndex */
    0x09U,

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 8 - DioPort11 */
  {
    /* ucPortGroupIndex */
    0x02U,

    /* ulModeMask */
    0xFFFFE000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 9 - DioPort12 */
  {
    /* ucPortGroupIndex */
    0x0BU,

    /* ulModeMask */
    0xFFFFFFC0UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 10 - DioPort13 */
  {
    /* ucPortGroupIndex */
    0x00U,

    /* ulModeMask */
    0xFFFFFF00UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 11 - DioPort18 */
  {
    /* ucPortGroupIndex */
    0x07U,

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 12 - DioPort19 */
  {
    /* ucPortGroupIndex */
    0x05U,

    /* ulModeMask */
    0xFFFFFFF0UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 13 - DioPort20 */
  {
    /* ucPortGroupIndex */
    0x08U,

    /* ulModeMask */
    0xFFFFFFC0UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 14 - DioPortAnalog1 */
  {
    /* ucPortGroupIndex */
    0x01U,

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x03U
  },

  /* Index: 15 - DioPort01_0To5 */
  {
    /* ucPortGroupIndex */
    0x04U,

    /* ulModeMask */
    0xFFFFFFC0UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 16 - DioPort11_15To15 */
  {
    /* ucPortGroupIndex */
    0x02U,

    /* ulModeMask */
    0xFFFF7FFFUL,

    /* ucPortType */
    0x02U
  }
};


/* Data Structure of DIO Port Channel Configuration */
CONST(Dio_PortChannel, DIO_CONST)
                               Dio_GstPortChannel[DIO_CHANNEL_ARRAY_SIZE] =
{
  /* Index: 0 - VIP_CAN3_STB */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 1 - VIP_Gyro_INT1 */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 2 - VIP_ChargeEN_ODH */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 3 - VIP_CAN0_RXD */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 4 - VIP_CAN1_RXD */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 5 - VIP_CAN3_RXD */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 6 - VIP_RLIN31_RXD */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 7 - VIP_RLIN31_TXD */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 8 - VIP_RLIN32_RXD */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 9 - VIP_RLIN32_TXD */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 10 - VIP_CAN1_STB */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 11 - VIP_LVI_IDL */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 12 - VIP_PD_EN_ODH */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 13 - VIP_PWR_VG5V_M_EN */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 14 - VIP_RTC_INT */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 15 - VIP_VG3V3_VIP_EN */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 16 - VIP_POC_PWREN */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 17 - VIP_RVC_PWREN */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 18 - VIP_GPS_RST */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 19 - VIP_GPSANT_POWER_EN_3V3 */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 20 - VIP_HD_EN_ODH */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 21 - VIP_ID_EN_ODH */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 22 - VIP_PWR_VG10V_EN */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 23 - VIP_PWR_VG3V3_M_EN */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 24 - VIP_PWR_VGBOOST_EN */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 25 - VIP_RLIN31_SLP */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 26 - VIP_RLIN31_WAKE */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 27 - VIP_RLIN32_SLP */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 28 - VIP_RLIN32_WAKE */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 29 - VIP_VG1V8_M_EN */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 30 - VIP_CD_EN_ODH */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 31 - SOC_VIP_CSIH1_REQ2 */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 32 - SOC_VIP_CSIH2_REQ2 */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 33 - VIP_WATCHDOG_WDI */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 34 - VBATT_VIP_DET_EN_3V3 */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 35 - VIP_SOC_EDL_3V3 */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 36 - PMIC_VIP_PSHOLD */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 37 - VIP_8532_DIAG3 */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 38 - VIP_CAN0_STB */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 39 - VIP_Gyro_INT2 */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 40 - VIP_WD_enable */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 41 - VIP_GPS_TXD */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 42 - VIP_ON_IDH */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x05U
  },

  /* Index: 43 - SXM_VIP_STBY */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x06U
  },

  /* Index: 44 - VIP_SOC3 */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x06U
  },

  /* Index: 45 - VIP_20098_EN */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 46 - VIP_20098_PG */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 47 - VIP_OPL_IDL */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 48 - VIP_SOC_CSIH1_REQ1 */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 49 - VIP_SOC_CSIH2_REQ1 */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 50 - VIP_SOC_SHUTDOWN */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 51 - VIP_SOC_UPDATA */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 52 - SI479XX_VIP_INT_3V3 */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 53 - VIP_MIC_res_key */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x07U
  },

  /* Index: 54 - VIP_AMP8532_DIAG3 */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 55 - VIP_47961_RST_3V3 */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 56 - VIP_BSF_IDL */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 57 - VIP_ETN_1V_PWR_EN */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 58 - VIP_MIC_POWER_EN_3V3 */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 59 - VIP_TUNER_ANT_EN_3V3 */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 60 - SI4624_VIP_INT_3V3 */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x08U
  },

  /* Index: 61 - VIP_479XX_RST_3V3 */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x09U
  },

  /* Index: 62 - VIP_4624_RST_3V3 */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x09U
  },

  /* Index: 63 - VIP_469X_RST_3V3 */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x09U
  },

  /* Index: 64 - VIP_A2BPWR_EN */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 65 - VIP_PMIC_CBL */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 66 - VIP_PMIC_KPD */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 67 - VIP_PMIC_RST */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 68 - VIP_SDARS_RST_3V3 */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 69 - VIP_SDARS_SHDN_3V3 */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 70 - VIP_SWITCH_SPI_EN */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x0AU
  },

  /* Index: 71 - SOC_VIP_FAST_BOOT */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 72 - VIP_AMP8531_DIAG1 */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 73 - VIP_AMP8531_DIAG2 */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 74 - VIP_AMP8531_EN */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 75 - VIP_AMP8531_MUTE */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 76 - VIP_AMP8532_DIAG1 */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 77 - VIP_AMP8532_DIAG2 */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 78 - VIP_AMP8532_EN */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 79 - VIP_AMP8532_MUTE */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 80 - VIP_DSP_REST_3V3 */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 81 - VIP_DSP_SELE */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x0BU
  },

  /* Index: 82 - VIP_ADC_M_REST */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x0CU
  },

  /* Index: 83 - VIP_REVERSE_IRQ */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x0CU
  },

  /* Index: 84 - VIP_RTC_FEN */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x0CU
  },

  /* Index: 85 - A2B_VIP_INT */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x0CU
  },

  /* Index: 86 - PMIC_VIP_FAULT */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 87 - VIP_USB1_CTRL2 */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 88 - VIP_TM_IDL */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 89 - VIP_USB1_CTRL1 */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 90 - VIP_USB1_EN */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 91 - VIP_USB1_FAULT_N */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x0DU
  },

  /* Index: 92 - SXM_VIP_FACT */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 93 - SXM_VIP_CTI */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 94 - Tuner_VIP_debug1 */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 95 - Tuner_VIP_debug2 */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 96 - VIP_ETN_0_9V_EN */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 97 - VIP_ETN_2_5V_EN */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x0EU
  },

  /* Index: 98 - VIP_RLIN31_INH */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x0FU
  },

  /* Index: 99 - VIP_RLIN32_INH */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x0FU
  },

  /* Index: 100 - VIP_SI_IDH */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x0FU
  },

  /* Index: 101 - VIP_VG1V2_EN */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x10U
  }
};



/* Data Structure of DIO Port Channel Group Configuration */
/* CONST(Dio_ChannelGroupType, DIO_CONST)
                    Dio_GstChannelGroupData[DIO_CHANNEL_GROUP_ARRAY_SIZE]; */

#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
/* QAC Warning: START Msg((2:0862))-2 */
#include DIO_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
