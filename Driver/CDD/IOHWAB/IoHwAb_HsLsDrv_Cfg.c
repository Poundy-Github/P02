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
 * @file:      IoHwAb_HsLsDrv_Cfg.c
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

#include "IoHwAb_common.h"
#include "IoHwAb_HsLsDrv.h"
#include "IoHwAb_HsLsDrv_Cfg.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"

#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines RAM data of hsls driver channel*/
static CIoHwAb_SignalRAM Signal_HSLS0_HSLS_RAM = {  0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */   };  
#define IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines ROM data of hsls driver channel
 * @arg Name - Channel name
 * @arg Id - Id 
 * @arg pFilters - Filters to be applied to HW value
 * @arg ResolutionDivisor -  Divisor for conversion from HW to Application value
 * @arg ResolutionMultiplier -  Multiplier for conversion from HW to Application value. ApplValue = (HWValue + Offset) * Multiplier / Divisor
 * @arg HwId - HS/LS chip ID 
 * @arg HwIdEx - Channel index in HS/LS chip 
 * @arg Type -the HsLs driver chip type
 * @arg DirectHwType -the output option : spi ,pwm or dio 
 * @arg DirectHwId -direct output chennel id*/
/******************************************************digital input*****************************************************************/

const uint8 CIoHwAb_HsLs_Chip_Count[IoHwAb_HsLs_Chip_Type_Count] = {
    1,
};

const IOHWAB_HSLS_CFG_STR CIoHwAb_HSLS_Cfg[IoHwAb_HsLs_Cfg_Count] = {
    {
      	{
            0, /* Id =*/
            &Signal_HSLS0_HSLS_RAM, /* pRAM =*/
            68, /* FilterId*/
            FALSE, /* IsPeriod*/
            0, /* Offset =*/
            1, /* ResolutionDivisor =*/
            1, /* ResolutionMultiplier =*/
            0, /* HwId =*/
            0, /* HwIdEx =*/
            cIoHwAb_HsLs_ChipType0 /* Type =*/
    	},
        cIoHwAb_HsLs_Direct_Dio, /* DirectHwType = */
        0, /* DirectHwId = */
        1 /* RefreshPeriod */
    },
};                                                                            


#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

