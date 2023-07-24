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
*File Name   : SWC_CA_Adapt.h                                                                        *
*                                                                                                         *
*Description : CA module Adapt head file.                                      		  *
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

#ifndef CA_ADAPT_H
#define CA_ADAPT_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_CA_Config.h"

#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"


void vCA_Adapt_ProIndexCfg(void);
CA_CFG_u8SignalStatus enCA_Adapt_Get_SignalStatus(uint8 u8signalID);
uint8 u8CA_Adapt_GetCANSignalValue(uint32 *u32SigValue, uint8 u8CACfgSignalInd, uint8 u8DataSize);


#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"



#endif




/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

