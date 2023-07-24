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
 * @file:      VersionCfg_P01N.h
 * @author:    Nobo
 * @date:      2020-5-1
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-1
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _VERSION_CFG_H_
#define _VERSION_CFG_H_

#define SOFTWARE_VERSION        (0x01010101u)

/* For example 2.0.1.1 */
#include "DevConfig.h"

#ifdef DEV_DEBUG_ON
#define VIP_VERSION_STATE       0xF1   /* DEBUG 0xF1  NORMAL:1*/
#else
#define VIP_VERSION_STATE       1   /* DEBUG 0xF1  NORMAL:1*/
#endif
#define VIP_VERSION_MAJOR       3   /* major version */
#define VIP_VERSION_MID         8   /* mid version */
#define VIP_VERSION_MINOR       117   /* minor version */
 
#endif
