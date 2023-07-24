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
*File Name   : TT_Core.h                                                                                  *
*                                                                                                         *
*Description : Telltale module core function head file.                                                   *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef TT_CORE_H
#define TT_CORE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Config.h"
#include "SWC_TT_Adapt.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Module Operation Structure																      *
*																								          *
*																								          *
**********************************************************************************************************/
typedef boolean (*ptrTTMainProcess)(void);
typedef void (*ptrTTSubProcess)(void);

typedef struct
{
	ptrTTMainProcess        boptrProcess;
	TT_enSystemStatus       u32SucceedEnableStatus;
	TT_enSystemStatus       u32FaildEnableStatus;
	ptrTTSubProcess         vptrAfterSucceedOperation;
	ptrTTSubProcess         vptrAfterFaildOperation;
	boolean                 boContinueWhenFaild;
}TT_tstPROCESS;
/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Module Structure																              *
*																								          *
*																								          *
**********************************************************************************************************/



/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Module Core Function							    									      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TT_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (void) *stProcessTable																	  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"
void TT_CORE_vProcessControl(const TT_tstPROCESS *stProcessTable, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enFlagProcessStage) enFlagOperationOrder												  *
*             (TT_tstMainObject*) stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vFlagControl(TT_enFlagProcessStage enFlagOperationOrder, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vSetSystemStatus                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vClearSystemStatus                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vClearSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_boCheckSystemStatus                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boCheckSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TT_CFG_DEBUG == TRUE) //Check module configration is valid
void TT_CORE_vCheckModuleConfigration(void);
#endif
/**********************************************************************************************************
*Function   : TT_CORE_vDebugModeOperation                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TT_CFG_DEBUG == TRUE)
void TT_CORE_vDebugModeOperation(TT_tstMainObject *stMainObject);
#endif
/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleLogicStatus                                                            *
*                                                                                                         *
*Description: The function is used to get telltale flash status .                                         *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleResultLogicStatus                                                      *
*                                                                                                         *
*Description: The function is used to get result telltale flash status .                                  *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleResultLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleExternaLogiclStatus                                                    *
*                                                                                                         *
*Description: The function is used to get telltale flash status by external control .                     *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleExternalLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_enGetLampStatus                                                                     *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_CORE_enGetLampStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_boGetLampOnOffStatus                                                                *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetLampOnOffStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_enGetFlashTypeStatus                                                                *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_CORE_enGetFlashTypeStatus(TT_CFG_enStatusType enStatusTypeID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_boGetFlashTypeOnOffStatus                                                           *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetFlashTypeOnOffStatus(TT_CFG_enStatusType u8StatusTypeID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleLightCountStatus                                                        *
*                                                                                                         *
*Description: The function is used to get current telltale light count status .                           *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetTelltaleFlashFinishStatus(TT_CFG_enTelltaleID enTelltaleID,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vStopTelltaleSelfCheck                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vStopTelltaleSelfCheck(uint8 enTelltaleID, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vStopAllTelltaleSelfCheck                                                            *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vStopAllTelltaleSelfCheck(TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vRestartTelltaleSelfCheck                                                            *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartTelltaleSelfCheck(uint8 enTelltaleID, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vRestartAllTelltaleSelfCheck                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartAllTelltaleSelfCheck(TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus(TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vSetTelltaleSelfCheckTime                                                            *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (UINT16) u16Time																			  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleSelfCheckTime(TT_CFG_enTelltaleID enTelltaleID, const uint16 u16Time, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function	: TT_CORE_vSetTelltaleExternalControlStatus													  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_CFG_enStatusType) enLogicStatus														  *
*             (TT_tstMainObject) *stMainObject															  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleExternalControlStatus(uint8 enTelltaleID,TT_CFG_enStatusType enLogicStatus,TT_tstMainObject* stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlEnable                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*																										  *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleExternalControlEnable(uint8 enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleExternalControlDisable(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetTelltaleExternalControlStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vCalculateDelayTimerMaxCount                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCalculateDelayTimerMaxCount(const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vCheckResponseDelayStatus                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCheckResponseDelayStatus(const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vResponseDelayStatusTickPlus                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vResponseDelayStatusTickPlus(const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vSetFlashStatusOffset                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetFlashStatusOffset(const TT_tstFlashAttribute *cstFlashAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vCalculateFlashReferenceStatus                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCalculateFlashReferenceStatus(const TT_tstFlashAttribute* cstFlashAttribute,TT_tstMainObject* stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vFlashReferenceTickPlus                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vFlashReferenceTickPlus(const TT_tstFlashAttribute *cstFlashAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (void) *vptrTelltaleLogicOperation														  *
*             (TT_tstLogicProcessAttribute) *cstLogicProcessAttribute									  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSingleLogicProcess(void *vptrTelltaleLogicOperation,const TT_tstLogicProcessAttribute *cstLogicProcessAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_enLogicProcessMode) enLogicProcessMode												  *
*             (TT_tstLogicProcessAttribute) *cstLogicProcessAttribute									  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleTableLogicProcess(TT_enLogicProcessMode enLogicProcessMode,const TT_tstLogicProcessAttribute *cstLogicProcessAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
*Function   : TT_CORE_vSingleTelltaleLightControl                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) stTelltaleControlStatus										  *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSingleTelltaleLightControl(TT_tstTelltaleControlStatus *stTelltaleControlStatus, const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject);

void TT__vCheckPowerModeCondition(TT_tstTelltaleControlStatus *stTelltaleControlStatus, const TT_tstTelltaleAttribute *cstTelltaleAttribute/*, TT_tstMainObject *cstMainObject*/);

/**********************************************************************************************************
*Function   : TT_CORE_vSetTelltaleLightStatus                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (BOOL) boSwitchStatus                                                                       *
*             (TT_tstTelltaleAttribute) cstTelltaleAttribute                                              *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleLightStatus(/*boolean boSwitchStatus,*/const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject);

/**********************************************************************************************************
 *Function   : TT__vTimeTaskLoopRollingCount                                                              *
 *                                                                                                        *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT__vTimeTaskLoopRollingCount(TT_tstMainObject *stMainObject);
#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/*********************************************************************************************************/
#endif //TT_CORE_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
