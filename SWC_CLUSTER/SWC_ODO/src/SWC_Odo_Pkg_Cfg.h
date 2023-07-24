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
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_ODO_PKG_CFG_H
#define SWC_ODO_PKG_CFG_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Odo_Adapt.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
/**********************************************************************************************************
* define of parament                                                                                      *
**********************************************************************************************************/
#define ODO_PKG_NUM_TRIP 								(3u)
   
#define ODO_ALLOW_CHANGE

#ifdef ODO_PKG_PROD_SPEC_RB_MAX_TIMES
/* max total roll back   must be in range 1 ... 255	 */ 
#define PROD_SPEC_RB_MAX_UNITS 							(90u)

/* roll back request above this  ,value will not be honored,must be in range 1 ... 255 */
#define PROD_SPEC_RB_CEILING 							(30u)

/* see ODO Programmers Guide	   					*/
#define PROD_SPEC_RB_TYPE 								ODO_PKG_ABSOLUTE

/* see ODO Programmers Guide     					*/
#define PROD_SPEC_RB_FLOOR 								(0u)

/* max roll back amount per each,must be in range 1 ... 255 */
#define PROD_SPEC_RB_MAX_PER 							(30u)   
#endif

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/06/02     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

