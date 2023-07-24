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
 * @file:      RRam.c
 * @author:    Nobo
 * @date:      2020-8-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "std_types.h"

#pragma ghs section bss=".NVMShadowStart"
uint32 NVM_Mirror_start;
#pragma ghs section bss=default

#pragma ghs section bss=".NVMShadowEnd"
uint32 NVM_Mirror_end;
#pragma ghs section bss=default

#pragma ghs section bss=".NVMShadowChecksum"
uint32 NVM_Mirror_checksum;
#pragma ghs section bss=default

#pragma ghs section bss=".NVMShadowChecksumRev"
uint32 NVM_Mirror_checksum_Rev;
#pragma ghs section bss=default


#define NVM_MIRROR_START_ADDR		((uint32)(&NVM_Mirror_start + 1))

#define NVM_MIRROR_END_ADDR			(&NVM_Mirror_end)


#define MIRROR_NULL_PTR ((void *) 0u)

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void NVM_Mirror_Checksum_Update(void);
boolean NVM_Mirror_Check_Valid(void);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void NVM_Mirror_Checksum_Update(void)
{
	uint32 check_sum = 0;
	uint32 *mirror_point = MIRROR_NULL_PTR;

	for (mirror_point = (uint32 *)NVM_MIRROR_START_ADDR; mirror_point < (uint32 *)NVM_MIRROR_END_ADDR; mirror_point++)
	{
		check_sum += *mirror_point;
	}
	NVM_Mirror_checksum = check_sum;
	NVM_Mirror_checksum_Rev = ~check_sum;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean NVM_Mirror_Check_Valid(void)
{
	boolean ret = FALSE;
	uint32 check_sum = 0;
	uint32 *mirror_point = MIRROR_NULL_PTR;
	
	for(mirror_point = (uint32 *)NVM_MIRROR_START_ADDR;mirror_point<(uint32 *)NVM_MIRROR_END_ADDR;mirror_point++)
	{
		check_sum += *mirror_point;
	}	
	
	if ((NVM_Mirror_checksum == (~NVM_Mirror_checksum_Rev))&&(NVM_Mirror_checksum == check_sum))
	{
		ret = TRUE;
	}
	return ret;
	
}

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



