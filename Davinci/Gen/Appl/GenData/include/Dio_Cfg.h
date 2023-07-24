/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2015  : Initial Version
 * V2.0.0   25-Oct-2016  : As part of ARDAABC-882 and ARDAABC-626 Jira Ticket,
 *                         the following changes are made:
 *                        1) Removed AR 3.2.2 related functionality and
 *                           added AR 4.2.2 where applicable.
 * V2.0.1   24-Jan-2017  : As part of ARDAABC-882 Jira Ticket,
 *                         the following changes are made:
 *                        1) Updated header comment based on acceptance finding
 * V2.0.2   31-May-2018  : As part of ARDAABD-2990 Jira ticket, the following
 *                         changes are made.
 *                         a.Removed generation of Dio_InitRamMirror.
 *                         b.Copyright information updated.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.2.5
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\GW00188879\AppData\Local\Temp\DaVinci\Cfg-5734869\Generation\Cfg_Gen-1607756599923-0\AutosarFiles_ValGen5020245192776930963\ExtGen_DrvDio_ECUC_4.2.2_6230620678829164241.arxml
 *                D:\Vector\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\dio\generator\R422_DIO_F1x_BSWMDT.arxml
 * GENERATED ON:  12 Dec 2020 - 15:04:55
 */


#ifndef DIO_CFG_H
#define DIO_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_CFG_AR_RELEASE_MINOR_VERSION  2U
#define DIO_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define DIO_CFG_SW_MAJOR_VERSION   2U
#define DIO_CFG_SW_MINOR_VERSION   0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define DIO_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define DIO_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define DIO_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define DIO_SW_MAJOR_VERSION_VALUE  2U
#define DIO_SW_MINOR_VERSION_VALUE  0U
#define DIO_SW_PATCH_VERSION_VALUE  6U

#define DIO_VENDOR_ID_VALUE  59U
#define DIO_MODULE_ID_VALUE  120U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the DIO Driver */
#define DIO_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information */
#define DIO_AR_VERSION                      DIO_AR_HIGHER_VERSION

/* Implements DIO066 */
/* Implements DIO142_Conf */ 
/* Implements DIO124 */ 
/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                STD_OFF

/* Implements DIO143_Conf */
/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                STD_OFF

/* Implements DIO153_Conf */
/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                STD_OFF

/* Pre-compile option for presence ofDio_MaskedWritePort API */
#define DIO_MASKED_WRITE_PORT_API           STD_OFF

/* Pre-compile option for presence ofDioReadChannelOutPutValue API */
#define DIO_READ_CHANNEL_OUTPUT_VALUE_API   STD_OFF

/* Pre-compile option for
        presence ofDioReadChannelGroupOutPutValue API */
#define DIO_READ_CHANNEL_GROUP_OUTPUT_VALUE_API STD_OFF

/* Pre-compile option for presence of Channel */
#define DIO_CHANNEL_CONFIGURED              STD_ON

/* Pre-compile option for presence of Channel Group */
#define DIO_CHANNELGROUP_CONFIGURED         STD_OFF

/* Pre-compile option for enable or disable version check of inter-module
   dependencies */
#define DIO_VERSION_CHECK_EXT_MODULES       STD_OFF

/* Pre-compile option for critical section protection */
#define DIO_CRITICAL_SECTION_PROTECTION     STD_ON

/* Indicates the configuration for Write-Verify safety mechanism
   DIO_WV_DISABLE           0 
   DIO_WV_INIT_ONLY         1
   DIO_WV_INIT_RUNTIME      2 */
#define DIO_WRITE_VERIFY                    DIO_WV_DISABLE

/* Indicates if specific error interface orDEM is used */
#define DIO_USE_WRITE_ERROR_INTERFACE       STD_OFF

/* Specifies if RAM mirror is used
   DIO_RAM_MIRROR_DISABLE   0 
   DIO_RAM_MIRROR_ENABLE    1  */
#define DIO_RAM_MIRROR                      DIO_RAM_MIRROR_DISABLE


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Total number of configured ports */
#define DIO_MAXNOOFPORT                     (Dio_PortType)17

/* Total number of configured channels */
#define DIO_MAXNOOFCHANNEL                  (Dio_ChannelType)102

/* Total number of channel groups configured per configset */
#define DIO_NO_OF_CHGRP_PER_CFGSET          (uint8)0

/* Array size for the DIO config set structure */
#define DIO_CONFIG_ARRAY_SIZE               0U

/* Array size for the port group structure */
#define DIO_PORT_GROUP_ARRAY_SIZE           17U

/* Array size for the channel structure */
#define DIO_CHANNEL_ARRAY_SIZE              102U

/* Array size for the channel group structure */
#define DIO_CHANNEL_GROUP_ARRAY_SIZE        0U

/* Configuration Set Handles */
#define DioConfig0                          (&Dio_GstConfiguration[0])

/* DIO Port Configuration Handles */
#define DioConf_DioPort_DioPortAnalog0      (Dio_PortType)0
#define DioConf_DioPort_DioPort00           (Dio_PortType)1
#define DioConf_DioPort_DioPort01_8To15     (Dio_PortType)2
#define DioConf_DioPort_DioPort02           (Dio_PortType)3
#define DioConf_DioPort_DioPort03           (Dio_PortType)4
#define DioConf_DioPort_DioPort08           (Dio_PortType)5
#define DioConf_DioPort_DioPort09           (Dio_PortType)6
#define DioConf_DioPort_DioPort10           (Dio_PortType)7
#define DioConf_DioPort_DioPort11           (Dio_PortType)8
#define DioConf_DioPort_DioPort12           (Dio_PortType)9
#define DioConf_DioPort_DioPort13           (Dio_PortType)10
#define DioConf_DioPort_DioPort18           (Dio_PortType)11
#define DioConf_DioPort_DioPort19           (Dio_PortType)12
#define DioConf_DioPort_DioPort20           (Dio_PortType)13
#define DioConf_DioPort_DioPortAnalog1      (Dio_PortType)14
#define DioConf_DioPort_DioPort01_0To5      (Dio_PortType)15
#define DioConf_DioPort_DioPort11_15To15    (Dio_PortType)16

/* The Pointer to Port Group name */

/* DIO Channel Configuration Handles */
#define DioConf_DioChannel_VIP_CAN3_STB     (Dio_ChannelType)0
#define DioConf_DioChannel_VIP_Gyro_INT1    (Dio_ChannelType)1
#define DioConf_DioChannel_VIP_ChargeEN_ODH (Dio_ChannelType)2
#define DioConf_DioChannel_VIP_CAN0_RXD     (Dio_ChannelType)3
#define DioConf_DioChannel_VIP_CAN1_RXD     (Dio_ChannelType)4
#define DioConf_DioChannel_VIP_CAN3_RXD     (Dio_ChannelType)5
#define DioConf_DioChannel_VIP_RLIN31_RXD   (Dio_ChannelType)6
#define DioConf_DioChannel_VIP_RLIN31_TXD   (Dio_ChannelType)7
#define DioConf_DioChannel_VIP_RLIN32_RXD   (Dio_ChannelType)8
#define DioConf_DioChannel_VIP_RLIN32_TXD   (Dio_ChannelType)9
#define DioConf_DioChannel_VIP_CAN1_STB     (Dio_ChannelType)10
#define DioConf_DioChannel_VIP_LVI_IDL      (Dio_ChannelType)11
#define DioConf_DioChannel_VIP_PD_EN_ODH    (Dio_ChannelType)12
#define DioConf_DioChannel_VIP_PWR_VG5V_M_EN (Dio_ChannelType)13
#define DioConf_DioChannel_VIP_RTC_INT      (Dio_ChannelType)14
#define DioConf_DioChannel_VIP_VG3V3_VIP_EN (Dio_ChannelType)15
#define DioConf_DioChannel_VIP_POC_PWREN    (Dio_ChannelType)16
#define DioConf_DioChannel_VIP_RVC_PWREN    (Dio_ChannelType)17
#define DioConf_DioChannel_VIP_GPS_RST      (Dio_ChannelType)18
#define DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3 (Dio_ChannelType)19
#define DioConf_DioChannel_VIP_HD_EN_ODH    (Dio_ChannelType)20
#define DioConf_DioChannel_VIP_ID_EN_ODH    (Dio_ChannelType)21
#define DioConf_DioChannel_VIP_PWR_VG10V_EN (Dio_ChannelType)22
#define DioConf_DioChannel_VIP_PWR_VG3V3_M_EN (Dio_ChannelType)23
#define DioConf_DioChannel_VIP_PWR_VGBOOST_EN (Dio_ChannelType)24
#define DioConf_DioChannel_VIP_RLIN31_SLP   (Dio_ChannelType)25
#define DioConf_DioChannel_VIP_RLIN31_WAKE  (Dio_ChannelType)26
#define DioConf_DioChannel_VIP_RLIN32_SLP   (Dio_ChannelType)27
#define DioConf_DioChannel_VIP_RLIN32_WAKE  (Dio_ChannelType)28
#define DioConf_DioChannel_VIP_VG1V8_M_EN   (Dio_ChannelType)29
#define DioConf_DioChannel_VIP_CD_EN_ODH    (Dio_ChannelType)30
#define DioConf_DioChannel_SOC_VIP_CSIH1_REQ2 (Dio_ChannelType)31
#define DioConf_DioChannel_SOC_VIP_CSIH2_REQ2 (Dio_ChannelType)32
#define DioConf_DioChannel_VIP_WATCHDOG_WDI (Dio_ChannelType)33
#define DioConf_DioChannel_VBATT_VIP_DET_EN_3V3 (Dio_ChannelType)34
#define DioConf_DioChannel_VIP_SOC_EDL_3V3  (Dio_ChannelType)35
#define DioConf_DioChannel_PMIC_VIP_PSHOLD  (Dio_ChannelType)36
#define DioConf_DioChannel_VIP_8532_DIAG3   (Dio_ChannelType)37
#define DioConf_DioChannel_VIP_CAN0_STB     (Dio_ChannelType)38
#define DioConf_DioChannel_VIP_Gyro_INT2    (Dio_ChannelType)39
#define DioConf_DioChannel_VIP_WD_enable    (Dio_ChannelType)40
#define DioConf_DioChannel_VIP_GPS_TXD      (Dio_ChannelType)41
#define DioConf_DioChannel_VIP_ON_IDH       (Dio_ChannelType)42
#define DioConf_DioChannel_SXM_VIP_STBY     (Dio_ChannelType)43
#define DioConf_DioChannel_VIP_SOC3         (Dio_ChannelType)44
#define DioConf_DioChannel_VIP_20098_EN     (Dio_ChannelType)45
#define DioConf_DioChannel_VIP_20098_PG     (Dio_ChannelType)46
#define DioConf_DioChannel_VIP_OPL_IDL      (Dio_ChannelType)47
#define DioConf_DioChannel_VIP_SOC_CSIH1_REQ1 (Dio_ChannelType)48
#define DioConf_DioChannel_VIP_SOC_CSIH2_REQ1 (Dio_ChannelType)49
#define DioConf_DioChannel_VIP_SOC_SHUTDOWN (Dio_ChannelType)50
#define DioConf_DioChannel_VIP_SOC_UPDATA   (Dio_ChannelType)51
#define DioConf_DioChannel_SI479XX_VIP_INT_3V3 (Dio_ChannelType)52
#define DioConf_DioChannel_VIP_MIC_res_key  (Dio_ChannelType)53
#define DioConf_DioChannel_VIP_AMP8532_DIAG3 (Dio_ChannelType)54
#define DioConf_DioChannel_VIP_47961_RST_3V3 (Dio_ChannelType)55
#define DioConf_DioChannel_VIP_BSF_IDL      (Dio_ChannelType)56
#define DioConf_DioChannel_VIP_ETN_1V_PWR_EN (Dio_ChannelType)57
#define DioConf_DioChannel_VIP_MIC_POWER_EN_3V3 (Dio_ChannelType)58
#define DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3 (Dio_ChannelType)59
#define DioConf_DioChannel_SI4624_VIP_INT_3V3 (Dio_ChannelType)60
#define DioConf_DioChannel_VIP_479XX_RST_3V3 (Dio_ChannelType)61
#define DioConf_DioChannel_VIP_4624_RST_3V3 (Dio_ChannelType)62
#define DioConf_DioChannel_VIP_469X_RST_3V3 (Dio_ChannelType)63
#define DioConf_DioChannel_VIP_A2BPWR_EN    (Dio_ChannelType)64
#define DioConf_DioChannel_VIP_PMIC_CBL     (Dio_ChannelType)65
#define DioConf_DioChannel_VIP_PMIC_KPD     (Dio_ChannelType)66
#define DioConf_DioChannel_VIP_PMIC_RST     (Dio_ChannelType)67
#define DioConf_DioChannel_VIP_SDARS_RST_3V3 (Dio_ChannelType)68
#define DioConf_DioChannel_VIP_SDARS_SHDN_3V3 (Dio_ChannelType)69
#define DioConf_DioChannel_VIP_SWITCH_SPI_EN (Dio_ChannelType)70
#define DioConf_DioChannel_SOC_VIP_FAST_BOOT (Dio_ChannelType)71
#define DioConf_DioChannel_VIP_AMP8531_DIAG1 (Dio_ChannelType)72
#define DioConf_DioChannel_VIP_AMP8531_DIAG2 (Dio_ChannelType)73
#define DioConf_DioChannel_VIP_AMP8531_EN   (Dio_ChannelType)74
#define DioConf_DioChannel_VIP_AMP8531_MUTE (Dio_ChannelType)75
#define DioConf_DioChannel_VIP_AMP8532_DIAG1 (Dio_ChannelType)76
#define DioConf_DioChannel_VIP_AMP8532_DIAG2 (Dio_ChannelType)77
#define DioConf_DioChannel_VIP_AMP8532_EN   (Dio_ChannelType)78
#define DioConf_DioChannel_VIP_AMP8532_MUTE (Dio_ChannelType)79
#define DioConf_DioChannel_VIP_DSP_REST_3V3 (Dio_ChannelType)80
#define DioConf_DioChannel_VIP_DSP_SELE     (Dio_ChannelType)81
#define DioConf_DioChannel_VIP_ADC_M_REST   (Dio_ChannelType)82
#define DioConf_DioChannel_VIP_REVERSE_IRQ  (Dio_ChannelType)83
#define DioConf_DioChannel_VIP_RTC_FEN      (Dio_ChannelType)84
#define DioConf_DioChannel_A2B_VIP_INT      (Dio_ChannelType)85
#define DioConf_DioChannel_PMIC_VIP_FAULT   (Dio_ChannelType)86
#define DioConf_DioChannel_VIP_USB1_CTRL2   (Dio_ChannelType)87
#define DioConf_DioChannel_VIP_TM_IDL       (Dio_ChannelType)88
#define DioConf_DioChannel_VIP_USB1_CTRL1   (Dio_ChannelType)89
#define DioConf_DioChannel_VIP_USB1_EN      (Dio_ChannelType)90
#define DioConf_DioChannel_VIP_USB1_FAULT_N (Dio_ChannelType)91
#define DioConf_DioChannel_SXM_VIP_FACT     (Dio_ChannelType)92
#define DioConf_DioChannel_SXM_VIP_CTI      (Dio_ChannelType)93
#define DioConf_DioChannel_Tuner_VIP_debug1 (Dio_ChannelType)94
#define DioConf_DioChannel_Tuner_VIP_debug2 (Dio_ChannelType)95
#define DioConf_DioChannel_VIP_ETN_0_9V_EN  (Dio_ChannelType)96
#define DioConf_DioChannel_VIP_ETN_2_5V_EN  (Dio_ChannelType)97
#define DioConf_DioChannel_VIP_RLIN31_INH   (Dio_ChannelType)98
#define DioConf_DioChannel_VIP_RLIN32_INH   (Dio_ChannelType)99
#define DioConf_DioChannel_VIP_SI_IDH       (Dio_ChannelType)100
#define DioConf_DioChannel_VIP_VG1V2_EN     (Dio_ChannelType)101

/* Channel Mapping for DioChannelBitPosition */
#define DioConfig0_VIP_CAN3_STB_bit         (uint8)0x0A
#define DioConfig0_VIP_Gyro_INT1_bit        (uint8)0x06
#define DioConfig0_VIP_ChargeEN_ODH_bit     (uint8)0x09
#define DioConfig0_VIP_CAN0_RXD_bit         (uint8)0x01
#define DioConfig0_VIP_CAN1_RXD_bit         (uint8)0x02
#define DioConfig0_VIP_CAN3_RXD_bit         (uint8)0x07
#define DioConfig0_VIP_RLIN31_RXD_bit       (uint8)0x04
#define DioConfig0_VIP_RLIN31_TXD_bit       (uint8)0x05
#define DioConfig0_VIP_RLIN32_RXD_bit       (uint8)0x0D
#define DioConfig0_VIP_RLIN32_TXD_bit       (uint8)0x0E
#define DioConfig0_VIP_CAN1_STB_bit         (uint8)0x0B
#define DioConfig0_VIP_LVI_IDL_bit          (uint8)0x09
#define DioConfig0_VIP_PD_EN_ODH_bit        (uint8)0x0F
#define DioConfig0_VIP_PWR_VG5V_M_EN_bit    (uint8)0x08
#define DioConfig0_VIP_RTC_INT_bit          (uint8)0x0A
#define DioConfig0_VIP_VG3V3_VIP_EN_bit     (uint8)0x0E
#define DioConfig0_VIP_POC_PWREN_bit        (uint8)0x06
#define DioConfig0_VIP_RVC_PWREN_bit        (uint8)0x07
#define DioConfig0_VIP_GPS_RST_bit          (uint8)0x0D
#define DioConfig0_VIP_GPSANT_POWER_EN_3V3_bit (uint8)0x08
#define DioConfig0_VIP_HD_EN_ODH_bit        (uint8)0x05
#define DioConfig0_VIP_ID_EN_ODH_bit        (uint8)0x04
#define DioConfig0_VIP_PWR_VG10V_EN_bit     (uint8)0x02
#define DioConfig0_VIP_PWR_VG3V3_M_EN_bit   (uint8)0x0F
#define DioConfig0_VIP_PWR_VGBOOST_EN_bit   (uint8)0x0E
#define DioConfig0_VIP_RLIN31_SLP_bit       (uint8)0x09
#define DioConfig0_VIP_RLIN31_WAKE_bit      (uint8)0x0A
#define DioConfig0_VIP_RLIN32_SLP_bit       (uint8)0x0B
#define DioConfig0_VIP_RLIN32_WAKE_bit      (uint8)0x0C
#define DioConfig0_VIP_VG1V8_M_EN_bit       (uint8)0x03
#define DioConfig0_VIP_CD_EN_ODH_bit        (uint8)0x00
#define DioConfig0_SOC_VIP_CSIH1_REQ2_bit   (uint8)0x00
#define DioConfig0_SOC_VIP_CSIH2_REQ2_bit   (uint8)0x01
#define DioConfig0_VIP_WATCHDOG_WDI_bit     (uint8)0x0B
#define DioConfig0_VBATT_VIP_DET_EN_3V3_bit (uint8)0x02
#define DioConfig0_VIP_SOC_EDL_3V3_bit      (uint8)0x03
#define DioConfig0_PMIC_VIP_PSHOLD_bit      (uint8)0x04
#define DioConfig0_VIP_8532_DIAG3_bit       (uint8)0x05
#define DioConfig0_VIP_CAN0_STB_bit         (uint8)0x06
#define DioConfig0_VIP_Gyro_INT2_bit        (uint8)0x0A
#define DioConfig0_VIP_WD_enable_bit        (uint8)0x07
#define DioConfig0_VIP_GPS_TXD_bit          (uint8)0x09
#define DioConfig0_VIP_ON_IDH_bit           (uint8)0x0C
#define DioConfig0_SXM_VIP_STBY_bit         (uint8)0x02
#define DioConfig0_VIP_SOC3_bit             (uint8)0x04
#define DioConfig0_VIP_20098_EN_bit         (uint8)0x0C
#define DioConfig0_VIP_20098_PG_bit         (uint8)0x0D
#define DioConfig0_VIP_OPL_IDL_bit          (uint8)0x0F
#define DioConfig0_VIP_SOC_CSIH1_REQ1_bit   (uint8)0x0A
#define DioConfig0_VIP_SOC_CSIH2_REQ1_bit   (uint8)0x0E
#define DioConfig0_VIP_SOC_SHUTDOWN_bit     (uint8)0x04
#define DioConfig0_VIP_SOC_UPDATA_bit       (uint8)0x03
#define DioConfig0_SI479XX_VIP_INT_3V3_bit  (uint8)0x09
#define DioConfig0_VIP_MIC_res_key_bit      (uint8)0x05
#define DioConfig0_VIP_AMP8532_DIAG3_bit    (uint8)0x01
#define DioConfig0_VIP_47961_RST_3V3_bit    (uint8)0x08
#define DioConfig0_VIP_BSF_IDL_bit          (uint8)0x00
#define DioConfig0_VIP_ETN_1V_PWR_EN_bit    (uint8)0x0C
#define DioConfig0_VIP_MIC_POWER_EN_3V3_bit (uint8)0x0A
#define DioConfig0_VIP_TUNER_ANT_EN_3V3_bit (uint8)0x0B
#define DioConfig0_SI4624_VIP_INT_3V3_bit   (uint8)0x09
#define DioConfig0_VIP_479XX_RST_3V3_bit    (uint8)0x00
#define DioConfig0_VIP_4624_RST_3V3_bit     (uint8)0x01
#define DioConfig0_VIP_469X_RST_3V3_bit     (uint8)0x02
#define DioConfig0_VIP_A2BPWR_EN_bit        (uint8)0x02
#define DioConfig0_VIP_PMIC_CBL_bit         (uint8)0x05
#define DioConfig0_VIP_PMIC_KPD_bit         (uint8)0x06
#define DioConfig0_VIP_PMIC_RST_bit         (uint8)0x07
#define DioConfig0_VIP_SDARS_RST_3V3_bit    (uint8)0x01
#define DioConfig0_VIP_SDARS_SHDN_3V3_bit   (uint8)0x00
#define DioConfig0_VIP_SWITCH_SPI_EN_bit    (uint8)0x03
#define DioConfig0_SOC_VIP_FAST_BOOT_bit    (uint8)0x00
#define DioConfig0_VIP_AMP8531_DIAG1_bit    (uint8)0x0A
#define DioConfig0_VIP_AMP8531_DIAG2_bit    (uint8)0x0B
#define DioConfig0_VIP_AMP8531_EN_bit       (uint8)0x0D
#define DioConfig0_VIP_AMP8531_MUTE_bit     (uint8)0x04
#define DioConfig0_VIP_AMP8532_DIAG1_bit    (uint8)0x05
#define DioConfig0_VIP_AMP8532_DIAG2_bit    (uint8)0x06
#define DioConfig0_VIP_AMP8532_EN_bit       (uint8)0x08
#define DioConfig0_VIP_AMP8532_MUTE_bit     (uint8)0x09
#define DioConfig0_VIP_DSP_REST_3V3_bit     (uint8)0x0F
#define DioConfig0_VIP_DSP_SELE_bit         (uint8)0x0E
#define DioConfig0_VIP_ADC_M_REST_bit       (uint8)0x00
#define DioConfig0_VIP_REVERSE_IRQ_bit      (uint8)0x03
#define DioConfig0_VIP_RTC_FEN_bit          (uint8)0x01
#define DioConfig0_A2B_VIP_INT_bit          (uint8)0x02
#define DioConfig0_PMIC_VIP_FAULT_bit       (uint8)0x00
#define DioConfig0_VIP_USB1_CTRL2_bit       (uint8)0x01
#define DioConfig0_VIP_TM_IDL_bit           (uint8)0x02
#define DioConfig0_VIP_USB1_CTRL1_bit       (uint8)0x05
#define DioConfig0_VIP_USB1_EN_bit          (uint8)0x04
#define DioConfig0_VIP_USB1_FAULT_N_bit     (uint8)0x03
#define DioConfig0_SXM_VIP_FACT_bit         (uint8)0x0D
#define DioConfig0_SXM_VIP_CTI_bit          (uint8)0x0C
#define DioConfig0_Tuner_VIP_debug1_bit     (uint8)0x0E
#define DioConfig0_Tuner_VIP_debug2_bit     (uint8)0x0F
#define DioConfig0_VIP_ETN_0_9V_EN_bit      (uint8)0x0A
#define DioConfig0_VIP_ETN_2_5V_EN_bit      (uint8)0x0B
#define DioConfig0_VIP_RLIN31_INH_bit       (uint8)0x01
#define DioConfig0_VIP_RLIN32_INH_bit       (uint8)0x03
#define DioConfig0_VIP_SI_IDH_bit           (uint8)0x00
#define DioConfig0_VIP_VG1V2_EN_bit         (uint8)0x0F

/* The Pointer to Port Channel name */

/* DIO Channel Group Configuration Handles */


/* Size of the Dio Channel Group Structure */
#define DIO_SIZE_OF_CHGRP_STRUCT 4U

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

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      Memmap include definition macros                      **
*******************************************************************************/
/* Implements SWS_BSW_00006 */
#if(DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* QAC Warning: START Msg(2:0832)-1 */
#define DIO_MEMMAP_FILE "Dio_MemMap.h"

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

#define DIO_MEMMAP_FILE "MemMap.h"
/* END Msg(2:0832)-1 */
#else

#error "AR version not correct"

#endif

#endif /* DIO_CFG_H  */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
