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
 * @file:      VersionCfg_D02.h
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
#define VIP_VERSION_STATE       0xF1	/* DEBUG 0xF*, Dev:1 ET:2 PT:3 SOP:4 */
#else
#define VIP_VERSION_STATE       0x01	/* NORMAL Dev:1 ET:2 PT:3 SOP:4 */
#endif
#define VIP_VERSION_MAJOR       0x0A	/* Progect number */
#define VIP_VERSION_MID         0x01	/* major version */
#define VIP_VERSION_MINOR       125		/* minor version */
 
#endif
