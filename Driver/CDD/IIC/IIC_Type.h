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
/**
 **********************************************************************************************************************
 * @file:      IIC_Type.h
 * @author:    Nobo
 * @date:      2020-4-2
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-2
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _IIC_TYPE_H_
#define _IIC_TYPE_H_



#include "Platform_Types.h"

typedef unsigned char IIC_DeviceID_t;
typedef unsigned char IIC_QueueID_t;


typedef signed char IIC_Return_t;
#define eIIC_Return_Success         (0)
#define eIIC_Return_Error           (-1)
#define eIIC_Return_E_PARAM         (-2)
#define eIIC_Return_E_EMPTY         (-3)
#define eIIC_Return_E_BUSSY         (-4)
// ring buffer error 
#define eIIC_Return_E_RB            (-5)
#define eIIC_Return_E_UnOpen        (-6)


typedef unsigned char IIC_ResultStatus_t;
#define  eIIC_ResultStatus_Success          (0)
#define  eIIC_ResultStatus_Error            (1)


typedef enum
{
    eIIC_Unit0 = 0,
    eIIC_Unit1,
    eIIC_NUMBER
}IIC_Unitx_t;


#endif /* ifndef _IIC_TYPE_H_.2020-4-2 15:06:42 GW00188879 */
