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
 * @file:      hal_iic.c
 * @author:    Nobo
 * @date:      2020-3-16
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-16
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "hal_iic.h"
#include "IIC_Hardware.h"
#include "IIC1_Hardware.h"

typedef uint8 IIC_BusStatusType;
#define eIIC_Bus_Uinit               (0x00)
#define eIIC_Bus_Open                (0x01)
#define eIIC_Bus_Close               (0x02)


IIC_BusStatusType IIC_BusState[eIIC_NUMBER] = {0};


/***********************************************************************
 * @brief       : Init IIC bus 
 * @param       : none
 * @retval      : none
 ***********************************************************************/
void HAL_IIC_Init(void)
{
    uint8 i;
    for (i = 0; i< eIIC_NUMBER; i++)
    {  
        IIC_BusState[i] = eIIC_Bus_Uinit;
    }
}


/***********************************************************************
 * @brief       : Initializes the IIC register.
 * @param       : tUnitx: bus ID
 * @retval      : eIIC_Return_E_PARAM: tUnitx >= eIIC_NUMBER
 ***********************************************************************/
IIC_Return_t HAL_IIC_Open(IIC_Unitx_t tUnitx)
{
    IIC_Return_t ret = eIIC_Return_Error;
    
    if (eIIC_Unit0 == tUnitx)
    {
        IIC_RegInit();
        
        ret = eIIC_Return_Success;
    }
    else if (eIIC_Unit1 == tUnitx)
    {
        IIC1_RegInit();
        ret = eIIC_Return_Success;
    }
    else
    {
         ret = eIIC_Return_E_PARAM;
    }
    if (eIIC_Return_Success == ret)
    {
        IIC_BusState[tUnitx] = eIIC_Bus_Open;
    }
    return ret;
}


/***********************************************************************
 * @brief       : Close IIC 
 * @param       : tUnitx: bus ID
 * @retval      : eIIC_Return_E_PARAM: tUnitx >= eIIC_NUMBER 
 ***********************************************************************/


/***********************************************************************
 * @brief       : Write data to bus
 * @param       : tUnitx: Reference IIC_Unitx_t define
 * @retval      : eIIC_Return_E_UnOpen: bus on open;
 *              : eIIC_Return_Error: bus error;This interface may be 
 *                called when the bus is busy, and you can try to 
 *                re-invoke it.
 ***********************************************************************/
IIC_Return_t HAL_IIC_Write(IIC_Unitx_t tUnitx, uint16 IIC_addr, uint8 *value, uint16 length)
{
    IIC_Return_t ret = eIIC_Return_Error;
    HAL_STATUS writeReturn = HAL_STATUS_OK;
    if (eIIC_Bus_Open !=  IIC_BusState[tUnitx])
    {
        ret = eIIC_Return_E_UnOpen;
    }
    else
    {
        if (eIIC_Unit0 == tUnitx)
        {
            writeReturn = IIC_TransmitData((uint8) IIC_addr,value,(uint8) length);
    
        }
        else if (eIIC_Unit1 == tUnitx)
        {
            writeReturn = IIC1_TransmitData((uint8) IIC_addr,value,(uint8) length);
    
        }
        else
        {
        }
        if (HAL_STATUS_OK == writeReturn)
        {
            ret = eIIC_Return_Success;
        }
    }
    return ret;
}


/***********************************************************************
 * @brief       : Read data from the bus
 * @param       : tUnitx: Reference IIC_Unitx_t define
 * @retval      : eIIC_Return_Error: bus error;This interface may be 
 *                called when the bus is busy, and you can try to 
 *                re-invoke it.
 ***********************************************************************/
IIC_Return_t HAL_IIC_Read(IIC_Unitx_t tUnitx, uint16 IIC_addr, uint8 *value, uint16 length)
{
    IIC_Return_t ret = eIIC_Return_Error;
    HAL_STATUS receptReturn = HAL_STATUS_OK;

    if (eIIC_Bus_Open !=  IIC_BusState[tUnitx])
    {
        ret = eIIC_Return_E_UnOpen;
    }
    else
    {
        if (eIIC_Unit0 == tUnitx)
        {
            receptReturn = IIC_ReceptionData((uint8)IIC_addr,value,(uint8)length);
        }
        else if (eIIC_Unit1 == tUnitx)
        {
            receptReturn = IIC1_ReceptionData((uint8)IIC_addr,value,(uint8)length);
        }
        else
        {
        }
        if (HAL_STATUS_OK == receptReturn)
        {
            ret = eIIC_Return_Success;
        }
    }
    return ret;

}

void HAL_IIC_Reset(IIC_Unitx_t tUnitx)
{
    if (eIIC_Unit0 == tUnitx)
    {
        IIC_RegInit();
    }
    else if (eIIC_Unit1 == tUnitx)
    {
        IIC1_RegInit();
    }
}
