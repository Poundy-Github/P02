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
 * @file:      IoHwAb.h
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

#ifndef _IOHWAB_H_
#define _IOHWAB_H_


#include "Platform_Types.h"
#include "Compiler.h"
#include "std_types.h"


/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, IOHWAB_CODE) IoHwAb_Init(void);
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_MainFunction(void);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_GetVoltage (uint8 Id, uint32* Voltage);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) CIoHwAb_SetPin (uint8 Id, boolean Digital);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) CIoHwAb_GetPin (uint8 Id, boolean* Pin);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_SetPeriodAndDuty (uint8 Id, uint16 Period,uint16 Duty);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_SetDuty (uint8 Id, uint16 Duty);
FUNC(Std_ReturnType, IOHWAB_APPL_CODE) IoHwAb_SetHsLsOutput (uint8 Id, uint16 Output);

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ifndef _IOHWAB_H_ */
