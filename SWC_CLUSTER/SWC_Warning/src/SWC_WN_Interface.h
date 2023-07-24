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
*File Name   : WN_Interface.h                                                                             *
*                                                                                                         *
*Description : Warning module application interface head file.                                            *
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
#ifndef WN_API_H
#define WN_API_H

#ifndef WN_API_H
#define EXTERN  extern
#else
#define EXTERN
#endif

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
*Function   : WN_API_vKSSlowRate_Task                                                                     *
*                                                                                                         *
*Description: The functions is called by DI-kernel at slow rate task list at cycle 40ms.                  *
*             which is the main handling task of Warning module at different working mode                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-10-31                                                                                  *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"
#define WN_CFG_OFF               ((boolean)0)
#define WN_CFG_ON                ((boolean)1)


/**********************************************************************************************************
* Warning status                                                                                          *
**********************************************************************************************************/
void WN_API_vKSTimeTask(void);

/**********************************************************************************************************
*Function   : WN_API_vKSRoundRobin_Task                                                                   *
*                                                                                                         *
*Description: The function is called by DI-kernel at round-robin task list. if it used,can fill  it with  *
*             code.                                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSRoundRobinTask(void);

/**********************************************************************************************************
*Function   : WN_API_vKSColdInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at cold init task list,which do global variables        *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSColdInit(void);

/**********************************************************************************************************
*Function   : WN_API_vKSWarmInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at warm init task list,which do global variables        *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSWarmInit(void);

/**********************************************************************************************************
*Function   : WN_API_vKSWakeUp                                                                            *
*                                                                                                         *
*Description: The function is called by DI-kernel at wake up task list,which do global variables          *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-12-20                                                                                  *
**********************************************************************************************************/
void WN_API_vKSWakeUp(void);

/**********************************************************************************************************
*Function   : WN_API_vKSSleep                                                                             *
*                                                                                                         *
*Description: The function is called by DI-kernel at sleep task list,which do global variables            *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-12-20                                                                                  *
**********************************************************************************************************/
void WN_API_vKSSleep(void);

/**********************************************************************************************************
*Function   : WN_API_vKSEnterAbnormalOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSEnterAbnormalOperation(void);

/**********************************************************************************************************
*Function   : WN_API_vKSExitAbnormalOperation                                                             *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when MCU exits the        *
*             abnormal mode                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSExitAbnormalOperation(void);

/**********************************************************************************************************
*Function   : WN_API_vSingleWarningControl                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vSingleWarningControl(void* vptrWarningLogicOperation,uint8 u8WarningID);

/**********************************************************************************************************
*Function   : WN_API_vSingleWarningControl                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vSetWarningStatus(WN_CFG_enWarningID warningID, uint8 warningStatus);

/**********************************************************************************************************
*Function   : WN_API_u8GetWarningStatus                                                                  *
*                                                                                                         *
*Description: The function is used to get current warning flash status                                   *
*                                                                                                         *
*Parameter  : Warning ID                                                                                  *
*                                                                                                         *
*Return     : Flash status type                                                                           *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
uint8 WN_API_u8GetWarningStatus(WN_CFG_enWarningID warningID);

void WN_API_Set_PrePowerMode_Status(void);

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/*********************************************************************************************************/
#endif //WN_API_H
/**********************************************************************************************************
*  End Of File                                                                                            *
**********************************************************************************************************/
