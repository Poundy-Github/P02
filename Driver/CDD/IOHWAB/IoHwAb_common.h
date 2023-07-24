/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      IoHwAb_Common.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _IOHWAB_COMMON_H_
#define _IOHWAB_COMMON_H_


#include "Platform_Types.h"
#include "Compiler.h"
#include "std_types.h"
#include "Pwm.h"



/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/

typedef uint32 EFilterKind;


typedef struct SIOFilterHandler
{
    EFilterKind Kind; /* Kind of filter*/
    uint8 CfgIx; /* Index in array with configuarions (read only)*/
    uint8 CxtIx; /* Index in array with contexts (current context)*/
}
SIOFilterHandler;


/* RAM data of the Signal*/
typedef struct CIoHwAb_SignalRAM
{
    uint32 AppValue; /*application value*/
    uint32 HwValue; /* HW value*/
	unsigned char Status;/*the app value is ok to read or not*/
} CIoHwAb_SignalRAM;



/* Definition of Inputs RAM data*/
typedef struct CIoHwAb_InputRAM
{
    Std_ReturnType Status; ///< Status of Input. Init with E_NOT_READY
} CIoHwAb_InputRAM;

/* Definition of Signal types supported.*/

typedef enum EIoHwAb_Signal_Type {
    cIoHwAb_Signal_DigitalInput = 0U,  /* MISRA 10.3 */
    cIoHwAb_Signal_DigitalOutput,
    cIoHwAb_Signal_PwmOutputPeriod,
    cIoHwAb_Signal_PwmOutputDuty,
    cIoHwAb_Signal_AnaInput,
    cIoHwAb_Signal_AnaOutput,
    cIoHwAb_Signal_PwmInputPeriod,
    cIoHwAb_Signal_PwmInputDuty,
    cIoHwAb_Signal_HsLsChipOutput,
    cIoHwAb_Signal_SerialTTFaultDetect
} EIoHwAb_Signal_Type;

typedef enum EIoHwAb_HsLs_Signal_Type {
    cIoHwAb_HsLs_Spi = 0U,  /* MISRA 10.3 */
    cIoHwAb_HsLs_Direct_Pwm,
    cIoHwAb_HsLs_Direct_Dio
} EIoHwAb_HsLs_Signal_Type;

typedef enum EIoHwAb_HsLs_Chip_Type {
    cIoHwAb_HsLs_ChipType0 = 0U, /* MISRA 10.3 */
    cIoHwAb_HsLs_ChipType1,
    cIoHwAb_HsLs_ChipType2,
    cIoHwAb_HsLs_ChipType3,
    cIoHwAb_HsLs_ChipType4,
    cIoHwAb_HsLs_ChipType5,
    cIoHwAb_HsLs_ChipType6,
    cIoHwAb_HsLs_ChipType7,
    cIoHwAb_HsLs_ChipType8
} EIoHwAb_HsLs_Chip_Type;

typedef struct IOHWAB_CFG_STR
{
    uint8 Id; /* Id defined in enum EIOVoltageInId.*/
    CIoHwAb_SignalRAM *pRAM; /* Pinter to RAM data*/
    uint8 FilterId;  /* Filter index to be applied for this Signal*/
	unsigned char IsPeriod;/*if the output the signal periodly or read the signal directly */
    sint32 Offset; /* Offset for conversion from HW to Application value*/
    sint32 ResolutionDivisor; /* Divisor for conversion from HW to Application value*/
    sint32 ResolutionMultiplier; /* Multiplier for conversion from HW to Application value. ApplValue = (HWValue + Offset) * Multiplier / Divisor */
    Pwm_ChannelType HwId; /* HW Id (See Dio, Pwm, Adc and etc. configurations)(for pwm , the Id is master channel Id)*/
    uint8 HwIdEx; /* Extended HW Id (In case of Analog signal - index of channel in group)*/
    EIoHwAb_Signal_Type Type; /* Signal type (Analog input, Digital output and etc.)*/
} IOHWAB_CFG_STR;

typedef struct IOHWAB_HSLS_CFG_STR
{
	IOHWAB_CFG_STR BasicCfg;
    EIoHwAb_HsLs_Signal_Type DirectHwType; /* Hw direct output type , pwm or Dio*/
    uint32 DirectHwId; /* Hw ID for pwm channel or IO chennel for direct output to HS driver (for pwm , the Id is slave channel Id)*/
	uint16 RefreshPeriod;/* update period value , times of 100ms*/
} IOHWAB_HSLS_CFG_STR;



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* ifndef _IOHWAB_ADC_H_ */
