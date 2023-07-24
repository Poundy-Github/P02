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
*File Name   : TT_Interface.h                                                                             *
*                                                                                                         *
*Description : Telltale module interface function head file.                                              *
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
#ifndef TT_API_H
#define TT_API_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Config.h"
#include "SWC_TT_Core.h"
#include "logger.h"

// TT LOG
#define SWC_TT_LOGOUT_ENBLE TRUE
#define SWC_TT_PRINT_WARN   fuel_warn

/**********************************************************************************************************
* Telltales status                                                                          *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Interface Function For DI Kennel System												      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TT_API_vKSTimeTask                                                                          *
*                                                                                                         *
*Description: The functions is called by DI-kernel at time task list at cycle 20ms.                       *
*			  which is the main handling task of Telltale module .                                        *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h" 
void TT_API_vKSTimeTask(void);

/**********************************************************************************************************
*Function   : TT_API_vKSColdInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at cold init task list,which do global variables        *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSColdInit(void);

/**********************************************************************************************************
*Function   : TT_API_vKSWarmInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at warm init task list,which do global variables        *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSWarmInit(void);

/**********************************************************************************************************
*Function   : TT_API_vKSWakeUp                                                                            *
*                                                                                                         *
*Description: The function is called by DI-kernel at wake up task list,which do global variables          *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
void TT_API_vKSWakeUp(void);
#endif
/**********************************************************************************************************
*Function   : TT_API_vKSSleep                                                                             *
*                                                                                                         *
*Description: The function is called by DI-kernel at sleep task list,which do global variables            *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
void TT_API_vKSSleep(void);
#endif
/**********************************************************************************************************
*Function   : TT_API_vKSEnterAbnormalOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSEnterAbnormalOperation(void);

/**********************************************************************************************************
*Function   : TT_API_vKSExitAbnormalOperation                                                             *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when MCU exits the        *
*             abnormal mode                                                                               *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *                                                                                                                                    *
**********************************************************************************************************/
void TT_API_vKSExitAbnormalOperation(void);

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Application Interface Function 														      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TT_API_vSingleTelltaleControl                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (void) *vptrTelltaleLogicOperation                                                          *
*             (UINT8) u8TelltaleID                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vSingleTelltaleControl(void *vptrTelltaleLogicOperation,TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleStatus                                                                  *
*                                                                                                         *
*Description: The function is used to get current telltale flash status .                                 *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
//TT_CFG_enStatusType TT_API_u8GetTelltaleStatus(TT_CFG_enTelltaleID u8TelltaleID);

/**********************************************************************************************************
*Function   : TT_API_enGetTelltaleCurrentStatus                                                           *
*                                                                                                         *
*Description: The function is used to get current telltale flash status .                                 *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_API_enGetTelltaleCurrentStatus(TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_enGetLampStatus                                                                      *
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
TT_enLampStatus TT_API_enGetLampStatus(TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_boGetLampOnOffStatus                                                                 *
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
boolean TT_API_boGetLampOnOffStatus(TT_CFG_enTelltaleID enTelltaleID);

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
boolean TT_API_boGetTelltaleFlashFinishStatus(TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_vSetTelltaleExternalControlStatus                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*             (TT_CFG_enStatusType) u8LogicStatus                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vSetTelltaleExternalControlStatus(uint8 enTelltaleID,TT_CFG_enStatusType enLogicStatus);

/**********************************************************************************************************
*Function   : TT_API_vReleaseTelltaleExternalControl                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vReleaseTelltaleExternalControl(TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleExternalControlStatus                                                   *
*                                                                                                         *
*Description: The function is used to get current telltale external control status .                      *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_u8GetTelltaleExternalControlStatus(TT_CFG_enTelltaleID enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_enGetFlashTypeStatus                                                                 *
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
TT_enLampStatus TT_API_enGetFlashTypeStatus(TT_CFG_enStatusType enStatusTypeID);

/**********************************************************************************************************
*Function   : TT_API_boGetFlashTypeOnOffStatus                                                            *
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
boolean TT_API_boGetFlashTypeOnOffStatus(TT_CFG_enStatusType enStatusTypeID);

/**********************************************************************************************************
*Function   : TT_API_boGetSingleTelltaleResponseDelayStatus                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetSingleTelltaleResponseDelayStatus(TT_CFG_enStatusType enTelltaleID);

/**********************************************************************************************************
*Function   : TT_API_boGetSingleTelltaleSelfCheckStatus                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetSingleTelltaleSelfCheckStatus(TT_CFG_enTelltaleID enTelltaleID);
/**********************************************************************************************************
*Function   : TT_API_vSwitchAllTelltaleON_Function                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/

void TT_API_vSwitchAllTelltaleON_Function (void);

/**********************************************************************************************************
*Function   : TT_API_vSwitchAllTelltaleOFF_Function                                                       *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/

void TT_API_vSwitchAllTelltaleOFF_Function (void);
void TT_API_Set_PreOffPowerMode_Status(void);
void TT_API_Set_PreOnPowerMode_Status(void);
boolean FTT_API_boGetSelfcheckReportStatus(void);
boolean FTT_boGetSelfcheckReportStatus(void);
boolean FTT_boGetSelfcheckReportStatus2(void);
void FTT_API_GetSelfcheckReportStatus(void);

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h" 
/*********************************************************************************************************/
#endif 
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
