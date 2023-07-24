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

/***********************************************************************************************************
**
**  Name         : SWC_IPC_CANMatrix.h
**
**  Description  :        
**
**  Organization :       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_CAN_MATRIX_H
#define SWC_IPC_CAN_MATRIX_H

#include "RTE.h"
#include "SWC_IPC_Config.h"
#include "Std_Types.h"
#include "Rte_Common_GateWay.h"
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

#ifdef SWC_IPC_PROJECT_TYPE_B02 
	#include "SWC_IPC_CANMatrix_B02.h"
#elif defined SWC_IPC_PROJECT_TYPE_B03
	#include "SWC_IPC_CANMatrix_B03.h"
#elif defined SWC_IPC_PROJECT_TYPE_P03
	#include "SWC_IPC_CANMatrix_P03.h"
#elif defined SWC_IPC_PROJECT_TYPE_P05
	#include "SWC_IPC_CANMatrix_P05.h"
#elif defined SWC_IPC_PROJECT_TYPE_A07
	#include "SWC_IPC_CANMatrix_A07.h"
#elif defined SWC_IPC_PROJECT_TYPE_D01
	#include "SWC_IPC_CANMatrix_D01.h"
#elif defined SWC_IPC_PROJECT_TYPE_D02
	#include "SWC_IPC_CANMatrix_D02.h"
#elif defined SWC_IPC_PROJECT_TYPE_D03
	#include "SWC_IPC_CANMatrix_D03.h"
#elif defined SWC_IPC_PROJECT_TYPE_P02
	#include "SWC_IPC_CANMatrix_P02.h"
#elif defined SWC_IPC_PROJECT_TYPE_P01
	#include "SWC_IPC_CANMatrix_P01.h"
#else
	#error project type is invalid !!
#endif

/**********************************************************************************************************
*                                                                               						  *
**********************************************************************************************************/
#endif

/**********************************************************************************************************
**
**  Revision : 2.0  
**
**  Author   : HenryChan
**
**  Date     : 2020/09/03  2.0    Add CAN matrix head file.     HenryChan
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
