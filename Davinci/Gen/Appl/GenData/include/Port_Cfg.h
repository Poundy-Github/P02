/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Cfg.h                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
 *
 * V1.0.1:  30-Dec-2015  : As a part of F1K ver 4.00.01 release following
 *                         changes are made
 *                         1. As a part of ticket ARDAAGA-138
 *                         Macro generation PORT_NUM_OF_NUMERIC_PORTS,
 *                         PORT_NUM_OF_JTAG_PORTS, PORT_NUM_OF_ANALOG_PORTS,
 *                         PORT_NUM_OF_INPUT_PORTS calculation is modified
 *                         in case of multiple configure set.
 *                         2. As a part of JIRA ticket ARDAAGA-133
 *                         Generation of address for PORT_PROTCMD0,
 *                         PORT_IOHOLD, PORT_PROTS0 is added
 * V2.0.0:  27-Oct-2016  : As a part of F1K ver 4.20.00 release following
 *                         changes are made:
 *                         1. As part of ARDAABC-763 Jira ticket, the following
 *                         parameters are added, related to Write-Verify and
 *                         Ram-Mirroring implementation:
 *                            PORT_WRITE_VERIFY
 *                            PORT_USE_WV_ERROR_INTERFACE
 *                            PORT_WV_ERROR_INTERFACE
 *                            PORT_RAM_MIRROR
 *                            PORT_E_REG_WRITE_VERIFY
 * V2.1.0:  14-Nov-2016  : As part of ARDAABC-542 Jira ticket the following
 *                         changes are made:
 *                         1. Added MemMap header name defininition for AR4.0.3
 *                         and AR4.2.2.
 * V2.1.1:  24-Jan-2017  : As part of ARDAABC-867 Jira ticket the following
 *                         changes are made:
 *                         1. Removed PORT_NUM_OF_ALPHA_PORTS precompile option.
 * V2.1.2:  07-Feb-2017  : As part of ARDAABC-867 Jira ticket the following
 *                         changes are made:
 *                         1. Removed EDC and DNFCKS related precompile options.
 * V2.1.3:  29-Jun-2017  : As per the requirement EAAR_PN0034_NR_0018,
 *                         1. Copyright information is updated.
 * V2.1.4:  25-Jul-2017  : As part of ARDAABD-1889, Precompile switch for PISA
 *                         register is generated.
 * V2.1.5:  25-May-2018  : As part of ARDAABD-1580, Comment of the macro
 *                         PORT_NUM_OF_FCLA is updated.
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

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Port MemMap file name */
#define PORT_MEMMAP_FILE "Port_MemMap.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define PORT_CFG_AR_RELEASE_MINOR_VERSION  2U
#define PORT_CFG_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define PORT_CFG_SW_MAJOR_VERSION  2U
#define PORT_CFG_SW_MINOR_VERSION  4U

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define PORT_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define PORT_AR_RELEASE_MINOR_VERSION_VALUE  2U
#define PORT_AR_RELEASE_REVISION_VERSION_VALUE  2U

#define PORT_SW_MAJOR_VERSION_VALUE  2U
#define PORT_SW_MINOR_VERSION_VALUE  4U

#define PORT_SW_PATCH_VERSION_VALUE  16U

#define PORT_VENDOR_ID_VALUE  59U
#define PORT_MODULE_ID_VALUE  124U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the PORT Driver Component */
#define PORT_INSTANCE_ID_VALUE               0U
/* Pre-compile option for Version information */
#define PORT_AR_VERSION                     PORT_AR_HIGHER_VERSION

/* Implements PORT100 */
/* Implements SWS_Port_00100 */
/* Implements PORT101 */
/* Implements SWS_Port_00101 */
/* Implements PORT107 */
/* Implements SWS_Port_00107 */
/* Implements PORT123_Conf */
/* Implements ECUC_Port_00123 */
/* Enables/Disables Development error detect */
#define PORT_DEV_ERROR_DETECT               STD_OFF

/* Implements PORT131_Conf */
/* Implements ECUC_Port_00131 */
/* Enables/Disables Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API          STD_ON

/* Implements PORT132_Conf */
/* Implements ECUC_Port_00132 */
/* Enables/Disables Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API               STD_OFF

/* Implements PORT103 */
/* Implements SWS_Port_00103 */
/* Implements PORT133_Conf */
/* Implements ECUC_Port_133 */
/* Enables/Disables Port_GetVersionInfo API */
#define PORT_VERSION_INFO_API               STD_OFF

/* Enable/Disable the enter/exit critical section functionality */
#define PORT_CRITICAL_SECTION_PROTECTION    STD_ON

/* Enables/Disables the checking of port pin backup status */
#define PORT_PIN_STATUS_BACKUP              STD_OFF

/* Indicates the number of Alternative Modes  */
#define PORT_MAX_MODE                       (uint8)0x0f

/* Indicates availability of IOHOLD register */
#define PORT_IOHOLD_FUNC_AVAILABLE          STD_ON

/* Indicates the delay required after clearing IOHOLD.IOHOLD bit */
#define PORT_IOHOLD_DELAY                   (uint8)0x88

/*  Indicates availability of PPCMD register  */
#define PPCMD_32BIT_REG_AVAILABLE           STD_ON

/* Indicates the write access of PPCMD register */
#define PORT_WRITE_ERROR_CLEAR_VAL          0xA5U

/* Pre-compile option for enable or disable version check of
                                 inter-module dependencies */
#define PORT_VERSION_CHECK_EXT_MODULES      STD_OFF

/* Enables/Disables Port_SetToDioMode and Port_SetToAlternateMode API */
#define PORT_SET_TO_DIO_ALT_MODE_API        STD_ON

/* User define value for Endless Loop. */
#define PORT_UNLOCK_SEQUENCE_COUNT          (uint8)0x14

/* Enables/Disables Port_SetPinDefaultDirection API */
#define PORT_SET_PIN_DEFAULT_DIRECTION_API  STD_OFF

/* Enables/Disables Port_SetPinDefaultMode API */
#define PORT_SET_PIN_DEFAULT_MODE_API       STD_OFF

/*  Indicates availability of PPCMD register  */
#define PPROTS_32BIT_REG_AVAILABLE          STD_ON

/* Indicates the configuration for Write-Verify safety mechanism
   PORT_WV_DISABLE           0
   PORT_WV_INIT_ONLY         1
   PORT_WV_INIT_RUNTIME      2 */
#define PORT_WRITE_VERIFY                   PORT_WV_DISABLE

/* Idicates if specific error interface or DEM is used */
#define PORT_USE_WV_ERROR_INTERFACE         STD_OFF

/* Specifies if RAM mirror is used
   PORT_RAM_MIRROR_DISABLE   0 
   PORT_RAM_MIRROR_ENABLE    1  */
#define PORT_RAM_MIRROR                     PORT_RAM_MIRROR_DISABLE

/*  Indicates availability of PISA register  */
#define PORT_PISA_REG_AVAILABLE             STD_ON


/* Availability of numeric port groups */
#define PORT_NUM_PORT_GROUPS_AVAILABLE      STD_ON

/* Availability of jtag port groups */
#define PORT_JTAG_PORT_GROUPS_AVAILABLE     STD_OFF

/* Availability of analog port groups */
#define PORT_ANALOG_PORT_GROUPS_AVAILABLE   STD_ON

/* Availability of input port groups */
#define PORT_INPUT_PORT_GROUPS_AVAILABLE    STD_OFF

/* The following constant contains total number of pins configured */
#define PORT_TOTAL_NUMBER_OF_PINS           (uint16)144

/* DEM for Port Driver component */
#define PORT_E_WRITE_TIMEOUT_FAILURE        \
        DemConf_DemEventParameter_AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE


/* Number of mode / dir / dioAlt changeable pins */
#define PORT_NUM_OF_PINS_MODIFIABLE         0x09U
/* Number of config set configured */
#define PORT_NUM_OF_CONFIGSET               0x02U
/* Number of numeric ports configured */
#define PORT_NUM_OF_NUMERIC_PORTS           0x1aU

/* Number of analog ports configured */
#define PORT_NUM_OF_ANALOG_PORTS            0x04U



/* Protection command register 0 */
#define PORT_PROTCMD0                       PROTCMD0

/* Hold state of the I/O buffer */
#define PORT_IOHOLD                         STBC_IOHOLD

/* Protection status register 0 */
#define PORT_PROTS0                         PROTS0


/* Availability of DNFA noise elimination registers. */
#define PORT_DNFA_REG_CONFIG                STD_OFF

/* Availability of FCLA noise elimination registers. */
#define PORT_FCLA_REG_CONFIG                STD_OFF

/* Availability of DNFAnENnoise elimination registers. */
#define PORT_DNFAEN_REG_AVAILABLE           STD_ON


/* Implements PORT006 */
/* Implements PORT076 */
/* Implements PORT207 */
/* Implements PORT208 */
/* Implements SWS_Port_00006 */
/* Implements SWS_Port_00076 */
/* Implements SWS_Port_00207 */
/* Implements SWS_Port_00208 */
/* Port Pin Handles */
#define Port_PortGroup00_VIP_CAN0_TXD    (Port_PinType)0
#define Port_PortGroup00_VIP_CAN0_RXD    (Port_PinType)1
#define Port_PortGroup00_VIP_CAN1_RXD    (Port_PinType)2
#define Port_PortGroup00_VIP_CAN1_TXD    (Port_PinType)3
#define Port_PortGroup00_VIP_RLIN31_RXD    (Port_PinType)4
#define Port_PortGroup00_VIP_RLIN31_TXD    (Port_PinType)5
#define Port_PortGroup00_VIP_Gyro_INT1    (Port_PinType)6
#define Port_PortGroup00_VIP_CAN3_RXD    (Port_PinType)7
#define Port_PortGroup00_VIP_CAN3_TXD    (Port_PinType)8
#define Port_PortGroup00_VIP_ChargeEN_ODH    (Port_PinType)9
#define Port_PortGroup00_VIP_CAN3_STB    (Port_PinType)10
#define Port_PortGroup00_VIP_I2C0_SDA    (Port_PinType)11
#define Port_PortGroup00_VIP_I2C0_SCL    (Port_PinType)12
#define Port_PortGroup00_VIP_RLIN32_RXD    (Port_PinType)13
#define Port_PortGroup00_VIP_RLIN32_TXD    (Port_PinType)14
#define Port_PortGroup01_VIP_SI_IDH    (Port_PinType)15
#define Port_PortGroup01_VIP_RLIN31_INH    (Port_PinType)16
#define Port_PortGroup01_VIP_RLIN32_INH    (Port_PinType)17
#define Port_PortGroup01_VIP_UART_RXD    (Port_PinType)18
#define Port_PortGroup01_VIP_UART_TXD    (Port_PinType)19
#define Port_PortGroup01_VIP_PWR_VG5V_M_EN    (Port_PinType)20
#define Port_PortGroup01_VIP_LVI_IDL    (Port_PinType)21
#define Port_PortGroup01_VIP_RTC_INT    (Port_PinType)22
#define Port_PortGroup01_VIP_CAN1_STB    (Port_PinType)23
#define Port_PortGroup01_VIP_VG3V3_VIP_EN    (Port_PinType)24
#define Port_PortGroup01_VIP_PD_EN_ODH    (Port_PinType)25
#define Port_PortGroup02_VIP_PWR_VG10V_EN    (Port_PinType)26
#define Port_PortGroup02_VIP_VG1V8_M_EN    (Port_PinType)27
#define Port_PortGroup02_VIP_ID_EN_ODH    (Port_PinType)28
#define Port_PortGroup02_VIP_HD_EN_ODH    (Port_PinType)29
#define Port_PortGroup02_VIP_POC_PWREN    (Port_PinType)30
#define Port_PortGroup02_VIP_RVC_PWREN    (Port_PinType)31
#define Port_PortGroup02_VIP_GPSANT_POWER_EN_3V3    (Port_PinType)32
#define Port_PortGroup02_VIP_RLIN31_SLP    (Port_PinType)33
#define Port_PortGroup02_VIP_RLIN31_WAKE    (Port_PinType)34
#define Port_PortGroup02_VIP_RLIN32_SLP    (Port_PinType)35
#define Port_PortGroup02_VIP_RLIN32_WAKE    (Port_PinType)36
#define Port_PortGroup02_VIP_GPS_RST    (Port_PinType)37
#define Port_PortGroup02_VIP_PWR_VGBOOST_EN    (Port_PinType)38
#define Port_PortGroup02_VIP_PWR_VG3V3_M_EN    (Port_PinType)39
#define Port_PortGroup03_VIP_CD_EN_ODH    (Port_PinType)40
#define Port_PortGroup08_SOC_VIP_CSIH1_REQ2    (Port_PinType)41
#define Port_PortGroup08_SOC_VIP_CSIH2_REQ2    (Port_PinType)42
#define Port_PortGroup08_VBATT_VIP_DET_EN_3V3    (Port_PinType)43
#define Port_PortGroup08_VIP_SOC_EDL_3V3    (Port_PinType)44
#define Port_PortGroup08_PMIC_VIP_PSHOLD    (Port_PinType)45
#define Port_PortGroup08_VIP_8532_DIAG3    (Port_PinType)46
#define Port_PortGroup08_VIP_CAN0_STB    (Port_PinType)47
#define Port_PortGroup08_VIP_WD_enable    (Port_PinType)48
#define Port_PortGroup08_VIP_GPS_RXD    (Port_PinType)49
#define Port_PortGroup08_VIP_GPS_TXD    (Port_PinType)50
#define Port_PortGroup08_VIP_Gyro_INT2    (Port_PinType)51
#define Port_PortGroup08_VIP_WATCHDOG_WDI    (Port_PinType)52
#define Port_PortGroup08_VIP_ON_IDH    (Port_PinType)53
#define Port_PortGroup09_VIP_I2C1_SDA    (Port_PinType)54
#define Port_PortGroup09_VIP_I2C1_SCL    (Port_PinType)55
#define Port_PortGroup09_SXM_VIP_STBY    (Port_PinType)56
#define Port_PortGroup09_VIP_PWR_VG10V_SYNC    (Port_PinType)57
#define Port_PortGroup09_VIP_SOC3    (Port_PinType)58
#define Port_PortGroup10_SOC_VIP_CSIH1_SI    (Port_PinType)59
#define Port_PortGroup10_SOC_VIP_CSIH1_SC    (Port_PinType)60
#define Port_PortGroup10_SOC_VIP_CSIH1_SO    (Port_PinType)61
#define Port_PortGroup10_VIP_SOC_UPDATA    (Port_PinType)62
#define Port_PortGroup10_VIP_SOC_SHUTDOWN    (Port_PinType)63
#define Port_PortGroup10_VIP_MIC_res_key    (Port_PinType)64
#define Port_PortGroup10_SOC_VIP_CSIH1_CS    (Port_PinType)65
#define Port_PortGroup10_SOC_VIP_CSIH2_CS    (Port_PinType)66
#define Port_PortGroup10_SI479XX_VIP_INT_3V3    (Port_PinType)67
#define Port_PortGroup10_VIP_SOC_CSIH1_REQ1    (Port_PinType)68
#define Port_PortGroup10_VIP_VD3V3_SYNC    (Port_PinType)69
#define Port_PortGroup10_VIP_20098_EN    (Port_PinType)70
#define Port_PortGroup10_VIP_20098_PG    (Port_PinType)71
#define Port_PortGroup10_VIP_SOC_CSIH2_REQ1    (Port_PinType)72
#define Port_PortGroup10_VIP_OPL_IDL    (Port_PinType)73
#define Port_PortGroup11_VIP_BSF_IDL    (Port_PinType)74
#define Port_PortGroup11_VIP_AMP8532_DIAG3    (Port_PinType)75
#define Port_PortGroup11_SOC_VIP_CSIH2_SO    (Port_PinType)76
#define Port_PortGroup11_SOC_VIP_CSIH2_SC    (Port_PinType)77
#define Port_PortGroup11_SOC_VIP_CSIH2_SI    (Port_PinType)78
#define Port_PortGroup11_VIP_47961_RST_3V3    (Port_PinType)79
#define Port_PortGroup11_SI4624_VIP_INT_3V3    (Port_PinType)80
#define Port_PortGroup11_VIP_MIC_POWER_EN_3V3    (Port_PinType)81
#define Port_PortGroup11_VIP_TUNER_ANT_EN_3V3    (Port_PinType)82
#define Port_PortGroup11_VIP_ETN_1V_PWR_EN    (Port_PinType)83
#define Port_PortGroup11_VIP_VG1V2_EN    (Port_PinType)84
#define Port_PortGroup12_VIP_479XX_RST_3V3    (Port_PinType)85
#define Port_PortGroup12_VIP_4624_RST_3V3    (Port_PinType)86
#define Port_PortGroup12_VIP_469X_RST_3V3    (Port_PinType)87
#define Port_PortGroup13_VIP_SDARS_SHDN_3V3    (Port_PinType)88
#define Port_PortGroup13_VIP_SDARS_RST_3V3    (Port_PinType)89
#define Port_PortGroup13_VIP_A2BPWR_EN    (Port_PinType)90
#define Port_PortGroup13_VIP_SWITCH_SPI_EN    (Port_PinType)91
#define Port_PortGroup13_VIP_PMIC_CBL    (Port_PinType)92
#define Port_PortGroup13_VIP_PMIC_KPD    (Port_PinType)93
#define Port_PortGroup13_VIP_PMIC_RST    (Port_PinType)94
#define Port_PortGroup18_SOC_VIP_FAST_BOOT    (Port_PinType)95
#define Port_PortGroup18_VIP_USB1_SYNC    (Port_PinType)96
#define Port_PortGroup18_VIP_ETN_1V_SYNC    (Port_PinType)97
#define Port_PortGroup18_VIP_AMP8531_MUTE    (Port_PinType)98
#define Port_PortGroup18_VIP_AMP8532_DIAG1    (Port_PinType)99
#define Port_PortGroup18_VIP_AMP8532_DIAG2    (Port_PinType)100
#define Port_PortGroup18_VIP_AMP8532_EN    (Port_PinType)101
#define Port_PortGroup18_VIP_AMP8532_MUTE    (Port_PinType)102
#define Port_PortGroup18_VIP_AMP8531_DIAG1    (Port_PinType)103
#define Port_PortGroup18_VIP_AMP8531_DIAG2    (Port_PinType)104
#define Port_PortGroup18_VIP_AMP8531_EN    (Port_PinType)105
#define Port_PortGroup18_VIP_DSP_SELE    (Port_PinType)106
#define Port_PortGroup18_VIP_DSP_REST_3V3    (Port_PinType)107
#define Port_PortGroup19_VIP_ADC_M_REST    (Port_PinType)108
#define Port_PortGroup19_VIP_RTC_FEN    (Port_PinType)109
#define Port_PortGroup19_A2B_VIP_INT    (Port_PinType)110
#define Port_PortGroup19_VIP_REVERSE_IRQ    (Port_PinType)111
#define Port_PortGroup20_PMIC_VIP_FAULT    (Port_PinType)112
#define Port_PortGroup20_VIP_USB1_CTRL2    (Port_PinType)113
#define Port_PortGroup20_VIP_TM_IDL    (Port_PinType)114
#define Port_PortGroup20_VIP_USB1_FAULT_N    (Port_PinType)115
#define Port_PortGroup20_VIP_USB1_EN    (Port_PinType)116
#define Port_PortGroup20_VIP_USB1_CTRL1    (Port_PinType)117
#define Port_PortGroupAnalog0_VBATT_VIP_DET_ADC    (Port_PinType)118
#define Port_PortGroupAnalog0_VIP_A1VREF_IAN    (Port_PinType)119
#define Port_PortGroupAnalog0_VIP_VREF_Fuel_IAN    (Port_PinType)120
#define Port_PortGroupAnalog0_VIP_Fuellevel1_IAN    (Port_PinType)121
#define Port_PortGroupAnalog0_VIP_Fuellevel2_IAN    (Port_PinType)122
#define Port_PortGroupAnalog0_VIP_Version_MON1_IAN    (Port_PinType)123
#define Port_PortGroupAnalog0_VIP_Version_MON2_IAN    (Port_PinType)124
#define Port_PortGroupAnalog0_VIP_BC_IAN    (Port_PinType)125
#define Port_PortGroupAnalog0_VIP_ANT1_P_Diag    (Port_PinType)126
#define Port_PortGroupAnalog0_VIP_ANT2_P_Diag    (Port_PinType)127
#define Port_PortGroupAnalog0_GPSANTpwer_VIP_ADsense    (Port_PinType)128
#define Port_PortGroupAnalog0_VIP_TPS7B7701_IAN    (Port_PinType)129
#define Port_PortGroupAnalog0_VIP_NTC_MON2_IAN    (Port_PinType)130
#define Port_PortGroupAnalog0_VIP_NTC_MON3_IAN    (Port_PinType)131
#define Port_PortGroupAnalog0_VIP_PMIC_0752_IAN    (Port_PinType)132
#define Port_PortGroupAnalog0_VIP_NTC_MON1_IAN    (Port_PinType)133
#define Port_PortGroupAnalog1_MIC_VIP_SENS1    (Port_PinType)134
#define Port_PortGroupAnalog1_MIC_VIP_SENS2    (Port_PinType)135
#define Port_PortGroupAnalog1_MIC_VIP_SENS1_N    (Port_PinType)136
#define Port_PortGroupAnalog1_MIC_VIP_SENS2_N    (Port_PinType)137
#define Port_PortGroupAnalog1_VIP_ETN_0_9V_EN    (Port_PinType)138
#define Port_PortGroupAnalog1_VIP_ETN_2_5V_EN    (Port_PinType)139
#define Port_PortGroupAnalog1_SXM_VIP_CTI    (Port_PinType)140
#define Port_PortGroupAnalog1_SXM_VIP_FACT    (Port_PinType)141
#define Port_PortGroupAnalog1_Tuner_VIP_debug1    (Port_PinType)142
#define Port_PortGroupAnalog1_Tuner_VIP_debug2    (Port_PinType)143

/* Configuration Set Handles */
#define PortConfig_Normal  (&Port_GstConfiguration[0])
#define PortConfig_Sleep  (&Port_GstConfiguration[1])

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
