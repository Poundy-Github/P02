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
*File Name   : SWC_TPMS_config.h                                                                          *
*                                                                                                         *
*Description : TPMS module config file.                                                                   *
*                                                                                                         *
*Author      : hai hu                                                                                     *
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
#ifndef TPMS_CFG_H
#define TPMS_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Std_Types.h"
//#include "Platform_Types.h"
//#include "Com.h"
#include "Vconfig.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*																								          *
*	Project Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*	System Configuration																				  *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*	Vehicle Configuration																				  *
*																								          *
**********************************************************************************************************/
//#define Rte_Read_TPMS_CONFIG	(Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(GEAR_VCONFIG_KIND_FUEL))
/**********************************************************************************************************
*																								          *
*	Power Configuration																				  *
*																								          *
**********************************************************************************************************/


/**********************************************************************************************************
*																								          *
*	Network Configuration																				  *
*																								          *
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
#define GWM_V35_PROJECT_TYPE_B02_TPMS
#elif defined GWM_V35_PROJECT_TYPE_B03
#define GWM_V35_PROJECT_TYPE_B03_TPMS
#elif defined GWM_V35_PROJECT_TYPE_P03
#define GWM_V35_PROJECT_TYPE_P03_TPMS
#elif defined GWM_V35_PROJECT_TYPE_P05
#define GWM_V35_PROJECT_TYPE_P05_TPMS
#elif defined GWM_V35_PROJECT_TYPE_A07
#define GWM_V35_PROJECT_TYPE_A07_TPMS
#elif defined GWM_V35_PROJECT_TYPE_D01
#define GWM_V35_PROJECT_TYPE_D01_TPMS
#elif defined GWM_V35_PROJECT_TYPE_D02
#define GWM_V35_PROJECT_TYPE_D02_TPMS
#elif defined GWM_V35_PROJECT_TYPE_D03
#define GWM_V35_PROJECT_TYPE_D03_TPMS
#elif defined GWM_V35_PROJECT_TYPE_P02
#define GWM_V35_PROJECT_TYPE_P02_TPMS
#elif defined GWM_V35_PROJECT_TYPE_P01
#define GWM_V35_PROJECT_TYPE_P01_TPMS
#else
#endif

#ifdef GWM_V35_PROJECT_TYPE_B02_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02_TPMS
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01_TPMS
#include "ComEx_Cfg.h"
#else
#endif

/* CAN */
#ifdef GWM_V35_PROJECT_TYPE_B02_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_B03_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_NEVER_RECEIVED & (status)) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & (status)) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & (status)) == RTE_E_COM_STOPPED))
#elif defined GWM_V35_PROJECT_TYPE_P03_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P05_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_A07_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D01_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D02_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D03_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P02_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P01_TPMS
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#else
#endif
#define Rte_Read_TPMS_CanSignals(x, y)			(Com_ReceiveSignal(x,y))
/* TPMS1 0x341 */
#define GET_CAN_TPMS1_TPMS_MISSING(status) 		(GET_CAN_MESSAGE_MISSING(status))



/* TPMS2 0x395 */
#define GET_CAN_TPMS2_TPMS_MISSING(status) 		(GET_CAN_MESSAGE_MISSING(status))
/**********************************************************************************************************
*	CANFD Msg																				  *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*	Internal Configuration																				  *
*																								          *
**********************************************************************************************************/

/* NVM */

/* HMI */

/*********************************************************************************************************/

#define TPMS_CFG_DEBUG				    (FALSE)

/*********************************************************************************************************/

#define TPMS_CFG_TIME_TASK_CYCLE		    (100u)//ms


/*********************************************************************************************************/
#endif //TPMS_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
