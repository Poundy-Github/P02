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

/**********************************************************************************************************
*File Name   : SWC_CA_Interface.h                                                                        *
*                                                                                                         *
*Description : CA module Interface head file.                                      		  *
*                                                                                                         *
*Author      : Chen Tuhe                                                                              *
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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


#ifndef CA_INTERFACE_H
#define CA_INTERFACE_H


#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"

void vCA_Interface_msTask(void);

#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"



#endif




/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


