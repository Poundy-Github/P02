
/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* This is an unpublished work of authership, which contains trade secrets, created in 2020.               *
*                                                                                                         *
* NOBO Corporation owns all rights to this work and intends to maintain it in         					  *
* confidence to preserve its trade secret status.                                                         *
*                                                                                                         *
* NOBO Corporation reserves the right, under the copyright laws of China or those of  					  *
* any other country that may have jurisdiction, to protect this work as an unpublished work, in the event *
* of and inadvertent or deliberate unauthorized publication.                                              *
*                                                                                                         *
* NOBO Coporation also reserves its rights under all copyright laws to protect this   					  *
* work as a published work,when appropriate.                                                              *
*                                                                                                         *
* Those having access to this work may not copy it, use it, modify it or disclose the information         *
* contained in it without the written authorization of NOBO Corporation.             					  *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_Config.h                                                                           *
*                                                                                                         *
*Description : Cconfig transmit to soc head file.                                      *
*                                                                                                         *
*Author      : li yafei                                                                    *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_CONFIG_H
#define SWC_CONFIG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/

#include "Std_Types.h"
#include "Platform_Types.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be fol_Lowed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
typedef enum
{
    Fast_Resp,
    DigitalRPM_Hysteresis_Low ,
    DigitalRPM_Hysteresis_High ,
    GasolineCoolant_C_point ,
    GasolineCoolant_14_point ,
    GasolineCoolant_12_point1 ,
    GasolineCoolant_12_point2 ,
    GasolineCoolant_4_point ,
    Gasolinecoolant_Redline_point ,
    GasolineCoolant_H_point ,
    Dieselcoolant_C_point ,
    Dieselcoolant_14_point ,
    DieselCoolant_12_point1 ,
    DieselCoolant_12_point2 ,
    DieselCoolant_34_point ,
    Dieselcoolant_Redline_point ,
    Dieselcoolant_H_point,
    PHEVHEVDTEDisplayEnable ,
    MaxDisplayPHEVRange ,
    PHEVSOCDisplayEnable ,
    RefreshRatePHEVSOC_Low ,
    RefreshRatePHEVSOC_High ,
    AvailablePowerDisplayEnable ,
    MaxAvailablePower ,
    RefreshRateAvrgEgyCns_Low ,
    RefreshRateAvrgEgyCns_High ,
    AvrgEgyCnsDisplayEnable ,
    MaxvalueAvrgEgyCns_Low ,
    MaxvalueAvrgEgyCns_High ,
    RefreshRatemotorpower_Low ,
    RefreshRatemotorpower_High ,
    motorpowerDisplayEnable ,
    RefreshRateEVSOC_Low ,
    RefreshRateEVSOC_High ,
    EVSOCDisplayEnable ,
    RefreshRateEVDTE_Low ,
    RefreshRateEVDTE_High ,
    EVDTEDisplayEnable ,
    MaxvalueEVDTE_Low ,
    MaxvalueEVDTE_High ,
    RefreshRateCurrent_Low ,
    RefreshRateCurrent_High ,
    EVCurrentDisplayEnable ,
    EVDrivDataARestTime ,
    RefreshRateEVAVS_Low ,
    RefreshRateEVAVS_High ,
    EVAVSMinDistanceThresh ,
    EVAVSADisplayEnable ,
    EVAVSBDisplayEnable ,
    EVTravelTimeDisplayLimited_One ,
    EVTravelTimeDisplayLimited_Two ,
    EVTravelTimeDisplayLimited_Three ,
    EVTravelTimeDisplayLimited_Four ,
    EVTravelTimeDisplayLimited_Five ,
    EVTravelTimeADisplayEnable ,
    EVTravelTimeBDisplayEnable ,
    Horizontal_data_Low ,
    Horizontal_data_High ,
    Adas_X ,
    Adas_Y ,
    Telltale_interrupt_display_time ,
    Telltale_polling_display_time ,
    DoorRed_speedthreshold ,
    oorallclosed_holdtime ,

    CONFIG_TOTAL_NUMBER
}CONFIG_enTelltaleID;

#define SWC_DEFAULT_CCONFIG_TABLE \
{           /* SWC Cconfig Default Data*/ \
    1u,        /* Fast_Resp */ \
    26u,       /* DigitalRPM_Hysteresis */ \
    90u,       /* GasolineCoolant_C_point */ \
    110u,      /* GasolineCoolant_14_point */ \
    125u,      /* GasolineCoolant_12_point1 */ \
    162u,      /* GasolineCoolant_12_point2 */ \
    166u,      /* GasolineCoolant_4_point */ \
    168u,      /* GasolineCoolant_Redline_point */ \
    180u,      /* GasolineCoolant_H_point */ \
    90u,       /* DieselCoolant_C_point */ \
    110u,      /* DieselCoolant_14_point */ \
    125u,      /* DieselCoolant_12_point1 */ \
    158u,      /* DieselCoolant_12_point2 */ \
    163u,      /* DieselCoolant_34_point */ \
    165u,      /* DieselCoolant_Redline_point */ \
    170u,      /* DieselCoolant_H_point */ \
    200u,      /* Horizontal_data */ \
    30u,       /* X */ \
    68u,       /* Y */ \
    1u,        /* AVSBDisplayEnable */ \
    1u,        /* AVSADisplayEnable */ \
    1u,        /* TravelTimeADisplayEnable */ \
    1u,        /* TravelTimeBDisplayEnable */ \
    1u,        /* AFCADisplayEnable */ \
    1u,        /* AFCBDisplayEnable */ \
    1u,        /* IFCDisplayEnable */ \
    1u,        /* DigitalSpeedDisplayEnable */ \
    1u,        /* PHEV_HEVDTEDisplayEnable */ \
    254u,      /* MaxDisplayPHEVRange */ \
    1u,        /* PHEVSOCDisplayEnable */ \
    10u,       /* RefreshRatePHEVSOC */ \
    1u,        /* AvailablePowerDisplayEnable */ \
    80u,       /* MaxAvailablePower */ \
    0u,        /* RefreshRateAvrgEgyCns */ \
    1u,        /* AvrgEgyCnsDisplayEnable */ \
    990u,      /* MaxvalueAvrgEgyCns */ \
    2u,        /* RefreshRatemotorpower */ \
    1u,        /* motorpowerDisplayEnable */ \
    10u,       /* RefreshRateEVSOC */ \
    1u,        /* EVSOCDisplayEnable */ \
    10u,       /* RefreshRateEVDTE */ \
    1u,        /* EVDTEDisplayEnable */ \
    999u,      /* MaxvalueEVDTE */ \
    10u,       /* RefreshRateCurrent */ \
    1u,        /* EVCurrentDisplayEnable */ \
    24u,       /* EVDrivDataARestTime */ \
    100u,      /* RefreshRateEVAVS */ \
    3u,        /* EVAVSMinDistanceThresh */ \
    1u,        /* EVAVSADisplayEnable */ \
    1u,        /* EVAVSBDisplayEnable */ \
    3599990u,  /* EVTravelTimeDisplayLimited */ \
    1u,        /* EVTravelTimeADisplayEnable */ \
    1u,        /* EVTravelTimeBDisplayEnable */ \
    6u,        /* DoortoRed_speedthreshold */ \
    5u,        /* Doorallclosed_holdtime */ \
    2u,        /* Telltale_interrupt_display_time */ \
    4u,        /* Telltale_polling_display_time */ \
    1u,        /* TPMSDisplayEnable */ \
    1u,        /* FIXEDDISPLAY_1_ODO_ENABLE */ \
    1u,        /* FD_003_CLOCK_ENABLE */ \
    1u,        /* FD_009_DRIVE_MODE_2WD_ENABLE */ \
    1u,        /* DrivDataADisplayEnable */ \
    1u,        /* DrivDataBDisplayEnable */ \
    648u,      /* V1 */ \
    3996u,     /* V2 */ \
    20u,       /* GasolineCoolant_Distime */ \
    20u,       /* DieselCoolant_Distime */ \
    20u,       /* Fuel_Distime */ \
    100u,      /* RefreshRateUrea */ \
    2u,        /* GValue_Hysteresis */ \
    10u,       /* GValue_update_frequency */ \
}



/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h"

extern void SWC_Config_Entrance_Task(void);
extern void SWC_Config_Send_IPC_Task(void);

#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h"


#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/



