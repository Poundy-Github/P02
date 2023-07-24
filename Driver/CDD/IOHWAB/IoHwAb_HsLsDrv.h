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
 * @file:      IoHwAb_HsLsDrv.h
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

#ifndef _IOHWAB_HSLSDRV_H_
#define _IOHWAB_HSLSDRV_H_


#include "Platform_Types.h"
#include "Compiler.h"

#include "IoHwAb_common.h"
#include "IoHwAb_HsLsDrv_Cfg.h"

/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern const uint8 CIoHwAb_HsLs_Chip_Count[IoHwAb_HsLs_Chip_Type_Count];

extern const IOHWAB_HSLS_CFG_STR CIoHwAb_HSLS_Cfg[IoHwAb_HsLs_Cfg_Count];
 

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, IOHWAB_APPL_CODE) IoHwAb_HsLsDrv_Init(void);
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_HsLsDrv_MainFunction(void);
void HsLs_Chip_SetOutput(EIoHwAb_HsLs_Chip_Type Chip_type , uint8 Chip_id , uint8 Chip_chn, uint32 Output_value);

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ifndef _IOHWAB_HSLSDRV_H_ */

