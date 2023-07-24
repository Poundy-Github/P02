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
**  Name:               SWC_CHIME_INTERFACE_H
**
**  Description:        The main switching logic of the chime module
**
**  Organization:       
**
**********************************************************************************************************/
#ifndef SWC_CHIME_INTERFACE_H
#define SWC_CHIME_INTERFACE_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_App.h"

/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h" 

/**********************************************************************************************************
*Function   : Chime_KSColdInit                                                                            *
*                                                                                                         *
*Description: Chime cold init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_KSColdInit(void);

/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_KSWarmInit(void);

/**********************************************************************************************************
*Function   : Chime_Api_SetVolume_Set                                                                     *
*                                                                                                         *
*Description: Set sound volume                                                                            *
*                                                                                                         *
*Parameter  : volume_u8 : volume 0~100%                                                                   *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_SetVolume_Set(uint8 volume_u8);

/**********************************************************************************************************
*Function   : Chime_SlowRateTask                                                                          *
*                                                                                                         *
*Description: Chime app slow task,call by ruable,The faster call the better                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_SlowRateTask(void);

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/08/10     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

