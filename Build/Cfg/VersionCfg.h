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
 * @file:      VersionCfg.h
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

#ifndef VERSION_CFG_INCLUDE
#define VERSION_CFG_INCLUDE

/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_B02*********************************************************
 ********************************************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02

	#include "VersionCfg_B02.h"

	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','B', '0', '2','-','V','3','.','0','1','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"B02CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'

/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_B03*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_B03

	#include "VersionCfg_B03.h"
	#define CAN_MATRIX_VERSION  			' ', ' ' ,' ', ' ', ' ', ' ', ' ','B', '3', '0','-','V','4','.','0','4','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"B03CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'

/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_P03*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_P03

	#include "VersionCfg_P03.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','P', '0', '3','-','V','4','.','0','0','.','0','0'
	#define CAN_MATRIX_VERSION_2			' ', ' ' ,' ', ' ', ' ', ' ', ' ','P', '0', '3','-','V','2','.','0','2','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"P03CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'

/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_P05*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_P05

	#include "VersionCfg_P05.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','P', '0', '5','-','V','5','.','0','2','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"P05CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_A07*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_A07

	#include "VersionCfg_A07.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','A', '0', '7','-','V','2','.','0','2','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"A07CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'

/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_A08*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_A08

	#include "VersionCfg_A08.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','A', '0', '8','-','V','3','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"A08CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_ES13*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_ES13

	#include "VersionCfg_ES13.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', 'E','S', '1', '3','-','V','3','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"E13CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_EC24*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_EC24

	#include "VersionCfg_EC24.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', 'E','C', '2', '4','-','V','3','.','0','1','.','0','2'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"E24CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_D01*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_D01

	#include "VersionCfg_D01.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','D', '0', '1','-','V','3','.','0','0','.','0','0'
	#define CAN_MATRIX_VERSION_2			' ', ' ' ,' ', ' ', ' ', ' ', 'D','0', '1', 'D','-','V','3','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"D01CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_D02*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_D02

	#include "VersionCfg_D02.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','D', '0', '1','-','V','3','.','0','0','.','0','0'
	#define CAN_MATRIX_VERSION_2			' ', ' ' ,' ', ' ', ' ', ' ', 'D','0', '1', 'D','-','V','3','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"D02CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_D03*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_D03

	#include "VersionCfg_D03.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','D', '0', '1','-','V','3','.','0','0','.','0','0'
	#define CAN_MATRIX_VERSION_2			' ', ' ' ,' ', ' ', ' ', ' ', 'D','0', '1', 'D','-','V','3','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"D03CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_P01N*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_P01N

	#include "VersionCfg_P01N.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','P', '0', '1','-','V','1','.','0','0','.','0','1'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"P01NCNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_ES24*********************************************************
 ********************************************************************************************************************************/
#elif defined GWM_V35_PROJECT_TYPE_ES24

	#include "VersionCfg_ES24.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', 'E','S', '2', '4','-','V','2','.','2','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"E24CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_P02*********************************************************
 ********************************************************************************************************************************/

#elif defined GWM_V35_PROJECT_TYPE_P02

	#include "VersionCfg_P02.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','P', '0', '2','-','V','1','.','0','5','.','0','0'
	#define CAN_MATRIX_VERSION_2			' ', ' ' ,' ', ' ', ' ', ' ', 'P','0', '2', 'P','-','V','1','.','0','5','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"P02CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_B16*********************************************************
 ********************************************************************************************************************************/

#elif defined GWM_V35_PROJECT_TYPE_B16

	#include "VersionCfg_B16.h"
	#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','B', '1', '6','-','V','1','.','0','0','.','0','0'
	#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"B16CNHD1A113001078"

	#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
	#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
	#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
	#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

	#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
	#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
/********************************************************************************************************************************
 ***********************************************GWM_V35_PROJECT_TYPE_B04*********************************************************
 ********************************************************************************************************************************/

#elif defined GWM_V35_PROJECT_TYPE_B04

#include "VersionCfg_B04.h"
#define CAN_MATRIX_VERSION				' ', ' ' ,' ', ' ', ' ', ' ', ' ','B', '0', '4','-','V','1','.','0','0','.','0','1'
#define SYS_SUPPLIER_ECU_SOFT_VER_NUM	"B04CNHD1A113001078"

#define APP_VERSION_VALUE				VIP_VERSION_STATE, VIP_VERSION_MAJOR, VIP_VERSION_MID, VIP_VERSION_MINOR
#define SYSTEM_SUPPLIER_ID				'C','A','X','S','O'
#define SOFT_WARE_VERSION_VIP			0x0A,0x0A,0x0A,0x0A
#define BOOT_LOADER_VERSION_VIP			0x01,0x00,0x00,0x01

#define GWM_ECU_SOFT_VERSION			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
#define GWM_ECU_CALIB_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
#define GWM_ECU_BOOT_SOFT_VER			'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'
#else
#error project type define error
#endif 

#endif
