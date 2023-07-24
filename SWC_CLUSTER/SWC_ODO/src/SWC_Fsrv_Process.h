/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/
/**
**  Name:               SWC_Odo_Interface.c
**
**  Description:        Odo moudle interface file to oher.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/
/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
#ifndef SWC_FSRV_PROCESS_H
#define SWC_FSRV_PROCESS_H

/**********************************************************************************************************
* Internal function declare                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Parament  type                                                                                          *
**********************************************************************************************************/
typedef struct{
	sint32 MaintenceValue_s32;
	uint8 Status_u8;
}s_FsrvMaintenceInfo_t;

#define FSRV_WARNING_SERVICE_SHOLD  						(500u)

#define FSRV_WARNING_STAND_SHOLD							(200u)

#define FSRV_MILESTONE_DEFULT_VALUE      					(5000u)

#define FSRV_MILESTONE_INVALID_VALUE						(0xFFFF)

#define MAINTANCE_SERVICE_NROMAL							(0x00)
#define MAINTANCE_SERVICE_PLEASE							(0x01)
#define MAINTANCE_SERVICE_STAND								(0x02)
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 

/**********************************************************************************************************
*Function   : Fsrv_Api_KSColdInit                                                                         *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSColdInit(void);

/**********************************************************************************************************
*Function   : Fsrv_Api_KSWarmInit                                                                         *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSWarmInit(void);

/**********************************************************************************************************
*Function   : Fsrv_Api_KSWakeup                                                                           *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSWakeup(void);

/**********************************************************************************************************
*Function   : Fsrv_Api_KSRRobinTask                                                                       *
*                                                                                                         *
*Description: system time task call , for judge fsrv warning                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fsrv_Api_KSRRobinTask(void);


/**********************************************************************************************************
*Function   : boolean Fsrv_Api_NewMilestone_Set(uint16 NewValue_u16)                                      *
*                                                                                                         *
*Description: call by other function if need to set new mile stone                                        *
*                                                                                                         *
*Parameter  : uint16  NewValue_u16 ,new mile stone value ,it need to be more than 0                       *
*                                                                                                         *
*Return     : TRUE:set value sucess,FALSE: set value fault                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Fsrv_Api_NewMilestone_Set(sint32 NewValue_s32);

/**********************************************************************************************************
*Function   : boolean Fsrv_Api_DefaultMilestone_Set(uint16 NewValue_u16)                                  *
*                                                                                                         *
*Description: call by other function if need to set new default mile stone ,and reset mile stone          *
*                                                                                                         *
*Parameter  : uint16  NewValue_u16 ,new mile stone value ,it need to be more than 0                       *
*                                                                                                         *
*Return     : TRUE:set value sucess,FALSE: set value fault                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Fsrv_Api_DefaultMilestone_Set(uint16 NewValue_u16);

/**********************************************************************************************************
*Function   : Fsrv_Api_MaintenanceInfo_Get                                                                *
*                                                                                                         *
*Description: Frsv inoformation get                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : Fsrv_MaintenceInfo_s.Status_u8,warning status.MaintenceValue_s32: mile stone value          *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_FsrvMaintenceInfo_t Fsrv_Api_MaintenanceInfo_Get(void);

#define SWC_ODO_STOP_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/07/07     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
#endif
