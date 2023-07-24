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
*File Name   : WN_Core.h                                                                                  *
*                                                                                                         *
*Description : Warning module core function head file.                                                    *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
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
#ifndef WN_CORE_H
#define WN_CORE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_WN_Config.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Warning Module Operation Structure																      *
*																								          *
*																								          *
**********************************************************************************************************/
typedef boolean (*ptrMainProcess)(void);
typedef void (*ptrSubProcess)(void);

typedef struct 
{
    ptrMainProcess				boptrProcess;
    WN_CFG_enSYSTEM_STATUS		u32SucceedEnableStatus;
    WN_CFG_enSYSTEM_STATUS		u32FaildEnableStatus;
    ptrSubProcess				vptrAfterSucceedOperation;
    ptrSubProcess				vptrAfterFaildOperation;
    boolean    boContinueWhenFaild;
}WN_tstPROCESS;
/**********************************************************************************************************
*																								          *
*																								          *
*	Warning Module Structure																              *
*																								          *
*																								          *
**********************************************************************************************************/



/**********************************************************************************************************
*																								          *
*																								          *
*	Warning Module Core Function							    									      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : WN_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"

void WN_CORE_vProcessControl(void* stProcessTable,WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vFlagControl(WN_CFG_enFLAG_PROCESS_STAGE enFlagOperationOrder,WN_CFG_tstMAIN_OBJECT* stMainObject);


/**********************************************************************************************************
*Function   : WN_CORE_vSetSystemErrorStatus                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSetSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus,WN_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vClearSystemErrorStatus                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vClearSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus,WN_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_boCheckSystemErrorStatus                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
boolean WN_CORE_boCheckSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus,WN_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
#if (WN_CFG_DEBUG == TRUE)
void WN_CORE_vCheckModuleConfigration(void);
#endif
/**********************************************************************************************************
*Function   : WN_CORE_vDebugModeOperation                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
#if (WN_CFG_DEBUG == TRUE)
void WN_CORE_vDebugModeOperation(WN_CFG_tstMAIN_OBJECT *stMainObject);
#endif
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlEnable                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningExternalControlEnable(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vWarningExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningExternalControlDisable(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vWarningExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
boolean WN_CORE_boGetWarningExternalControlStatus(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vCalculateDelayTimerMaxCount                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vCalculateDelayTimerMaxCount(const WN_CFG_tstWarningAttribute* cstWarningAttribute,WN_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vCalculateFlashStatus                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vCheckResponseDelayStatus(const WN_CFG_tstWarningAttribute* cstWarningAttribute,WN_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vWarningTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSingleLogicProcess(void* vptrWarningLogicOperation,const WN_CFG_tstLogicProcessAttribute *cstLogicProcessAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vWarningTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningTableLogicProcess(WN_CFG_enLogicProcessMode enLogicProcessMode,const WN_CFG_tstLogicProcessAttribute *cstLogicProcessAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vSingleWarningLightControl                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSingleWarningControl(WN_CFG_tstWarningControlStatus *stWarningControlStatus, const WN_CFG_tstWarningAttribute *cstWarningAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
 *Function   : WN__vTimeTaskLoopRollingCount                                                              *
 *                                                                                                        *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (WN_CFG_tstMAIN_OBJECT) *stMainObject														  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void WN__vTimeTaskLoopRollingCount(WN_CFG_tstMAIN_OBJECT *stMainObject);
#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"
/*********************************************************************************************************/
#endif //WN_CORE_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
