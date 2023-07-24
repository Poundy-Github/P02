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
 * @file:      Gyro_asm330.c
 * @author:    Nobo
 * @date:      2020-5-7
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-7
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*INCLUDE FILE*/ 
//#include "System.h"
#include "string.h"

#include "Gyro_asm330.h"
#include "Gyro.h"
#include "IIC.h"

/*EXTERN INTERFACE*/
#define Asm330_Notification     Gyro_SetIndication
#define Gyro_I2cReadCmd         IIC_QueueRxReq
#define Gyro_I2cWriteCmd        IIC_QueueTxReq
#define ASM330_DEVICE_ID        eIIC_QueueID_Unit0

/*STATIC VARIABLES*/
Asm330_Attribute_t asm330Attribute;

Asm330_RegData_t asm330RegTable[ASM330_REG_USE_NUM] = ASM330_REG_TABLE;

Asm330_ReadCmd_t asm330ReadCmdTable[ASM330_READ_CMD_NUM] = ASM330_READ_CMD_TABLE;

Asm330_ResetCmd_t asm330ResetCmdTable[ASM330_RESET_CMD_NUM] = ASM330_RESET_CMD_TABLE;

static const Asm330_Sentivity_t asm330SensitivityTable[ASM330_SENSITIVITY_NUM] = ASM330_SENSITIVITY_TABLE;

/*STATIC FUNCTION*/
static uint8 Asm330_GetEvent(void);
static void Asm330_SetOpt(uint8 opt);
static void Asm330_InitHandle(void);
static void Asm330_ReadHandle(void);
static void Asm330_ResetHandle(void);
static void Asm330_DataHandle(uint8 type);
static uint8 Asm330_GetReadCmd(uint8* cmd);
static void Asm330_CalcTimeResolution(uint8 freqfine);
static Asm330_Return_t Asm330_ReadCmd(Asm330_Addr_t addr, uint8 readsize);
static Asm330_Return_t Asm330_WriteCmd(Asm330_Addr_t addr, uint8 value, uint8 size);
static Asm330_Reg_t Asm330_SetRegValue(Asm330_Addr_t addr, Asm330_Reg_t mask, Asm330_Reg_t value);

#ifdef ASM330_TEST
static void Asm330_TestTask(void);
static void Asm330_PrintfData(const uint8 * pu8buf, uint16 size);
#endif

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Asm330_Init(void)
{
    memset((uint8*)&asm330Attribute, 0x00U, sizeof(asm330Attribute)); 
    
    asm330Attribute.id = ASM330_INVALID_DEVICE_ID;
//    asm330Attribute.event = ASM330_INIT_EVENT;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Asm330_ManageTask(void)
{
    switch(asm330Attribute.opt)
    {   
        case ASM330_INIT_HANDLE:
            Asm330_InitHandle();
            break;
        case ASM330_IDLE_HANDLE:
            /*do nothing, wait for operation request*/
            break;
        case ASM330_RESET_HANDLE:
            Asm330_ResetHandle();
            break;
        case ASM330_READ_HANDLE:
            Asm330_ReadHandle();
            break;
        default:
			/* nothing to do */
            break;
    }
    
    #ifdef ASM330_TEST
    Asm330_TestTask();
    #endif
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_InitHandle(void)
{
    uint8 event = Asm330_GetEvent(); 

    if(event & ASM330_INIT_EVENT)
    {
        /*read device id*/
        Asm330_ReadCmd(ASM330_WHO_AM_I, ASM330_DEVICE_ID_LENGTH);
    }
    
    if(event & ASM330_READ_SUCCESS)
    {
        asm330Attribute.id = asm330Attribute.readbuff[0];
        Asm330_SetOpt(ASM330_IDLE_HANDLE);
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_ResetHandle(void)
{
    Asm330_Reg_t reg = 0x00U;
    Asm330_ResetCmd_t* cmdptr;
    
    uint8 cmd = asm330Attribute.cmd;
    uint8 event = Asm330_GetEvent(); 
    Asm330_Return_t cmdres = ASM330_RETURN_FAIL;
    
    if(event & ASM330_RESET_EVENT)
    {
        if(event & ASM330_READ_WRITE_SUCCESS)
        {
            /*process the next command*/
            asm330Attribute.cmd++;
            
            /*confirm reset complete*/
            if(cmd == ASM330_RESET_STATE_READ_CMD)
            {
                /*if reset status is ON, continue to read the reset status */
                if(asm330Attribute.readbuff[0] == ASM330_RESET_EN) 
                {
                    asm330Attribute.cmd = ASM330_RESET_STATE_READ_CMD;
                }
            }
            
            /*calculate time resoluton*/
            if(cmd == ASM330_RESET_STATE_READ_CMD)
            {
                Asm330_CalcTimeResolution(asm330Attribute.readbuff[0]);
            }
            
        }

        cmdptr = &asm330ResetCmdTable[asm330Attribute.cmd];

        if(asm330Attribute.cmd < ASM330_RESET_CMD_NUM)
        {
            if(cmdptr->rw == ASM330_WRITE_CMD)
            {
                /*calculate cmd value and reg value*/
                reg = Asm330_SetRegValue(cmdptr->addr, cmdptr->mask, cmdptr->value);
                cmdres = Asm330_WriteCmd(cmdptr->addr, reg, cmdptr->size);
            }
            else
            {
                cmdres = Asm330_ReadCmd(cmdptr->addr, cmdptr->size);
            }
            
            /*failed to read or write, repeat opeartion next period*/
            if(cmdres == ASM330_RETURN_FAIL)
            {
                asm330Attribute.event = ASM330_READ_WRITE_RETRY;
            }
        }
        else
        {
            /*reset operation completed*/
            Asm330_SetOpt(ASM330_IDLE_HANDLE);
            Asm330_Notification(ASM330_RESET_SUCCESS_IND);
            asm330Attribute.busy = FALSE;
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_ReadHandle(void)
{
    uint8 cmd = 0U;
    uint8 cmdst = ASM330_READ_CMD_INVALID;
    uint8 event = Asm330_GetEvent(); 
    Asm330_Return_t cmdres = ASM330_RETURN_FAIL;
    Asm330_ReadCmd_t* cmdptr = &asm330ReadCmdTable[asm330Attribute.cmd];
        
    if(event & ASM330_READ_EVENT)
    {
        if(event & ASM330_READ_SUCCESS)
        {
            Asm330_DataHandle(cmdptr->type);
            cmdptr->req = FALSE;
        }

        /*get the nex cmd to read*/
        cmdst = Asm330_GetReadCmd(&cmd);
        
        if(cmdst == ASM330_READ_CMD_VALID)
        {
            asm330Attribute.cmd = cmd;
            cmdptr = &asm330ReadCmdTable[asm330Attribute.cmd];
            
            cmdres = Asm330_ReadCmd(cmdptr->addr, cmdptr->size);
            
            /*failed to read or write , repeat opeartion in the next period*/
            if(cmdres == ASM330_RETURN_FAIL)
            {
                asm330Attribute.event = ASM330_READ_WRITE_RETRY;
            }
        }
        else
        {
            /*read operation completed*/
            Asm330_SetOpt(ASM330_IDLE_HANDLE);
            Asm330_Notification(ASM330_READ_SUCCESS_IND);
            asm330Attribute.busy = FALSE;
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_DataHandle(uint8 type)
{   
    Asm330_ReadData_t* pdata = asm330Attribute.pdata;
    uint8* databuffer = &asm330Attribute.readbuff[0];
    
    switch(type)
    {
        case ASM330_ACC_DATA_TYPE:
            pdata->acc.x = (sint16)(databuffer[0]+(((uint16)databuffer[1])<<8));
            pdata->acc.y = (sint16)(databuffer[2]+(((uint16)databuffer[3])<<8));
            pdata->acc.z = (sint16)(databuffer[4]+(((uint16)databuffer[5])<<8));
            break;
        case ASM330_GYRO_DATA_TYPE:
            pdata->gyro.x = (sint16)(databuffer[0]+(((uint16)databuffer[1])<<8));
            pdata->gyro.y = (sint16)(databuffer[2]+(((uint16)databuffer[3])<<8));
            pdata->gyro.z = (sint16)(databuffer[4]+(((uint16)databuffer[5])<<8));
            break;
        case ASM330_TIMESTAMP_DATA_TYPE:
            pdata->timestamp = (uint64)(databuffer[0]+(((uint32)databuffer[1])<<8)\
                                       +(((uint32)databuffer[2])<<16)+(((uint32)databuffer[3])<<24))*asm330Attribute.timeres;
            break;
        case ASM330_TEMP_DATA_TYPE:
            /*
             *it is represented as a number of 16 bits in two’s complement format with a sensitivity of 256 LSB/°C.
             *The output zero level corresponds to 25 °C.
             *
             *  Temperature values       OUT_TEMP_H (21h)        OUT_TEMP_L (20h)
             *     0  °C                       E7h                     00h
             *     25 °C                       00h                     00h
             */
            pdata->temp = (float)((sint16)(databuffer[0]+(((uint16)databuffer[1])<<8)))/ 256.0f + 25.0f; /*todo*/
            break;
        default:
			/* nothing to do */
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Asm330_Reg_t Asm330_SetRegValue(Asm330_Addr_t addr, Asm330_Reg_t mask, Asm330_Reg_t value)
{
    uint8 idx = 0U;
    Asm330_Reg_t reg = 0U;
    
    for(idx = 0U; idx < ASM330_REG_USE_NUM; idx++)
    {
        if(asm330RegTable[idx].addr == addr)
        {
            /*clear and set reg value*/
            asm330RegTable[idx].reg &= (~mask);
            asm330RegTable[idx].reg |= value;
            
            reg = asm330RegTable[idx].reg;
        }
    }

    return reg;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 Asm330_GetReadCmd(uint8* cmd)
{
    uint8 req = ASM330_READ_CMD_INVALID;
    uint8 idx;
    
    for(idx = 0; idx < ASM330_READ_CMD_NUM; idx++)
    {
        if(FALSE != asm330ReadCmdTable[idx].req)
        {
            *cmd = idx; 
            req = ASM330_READ_CMD_VALID;
        }
    }

    return req;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_CalcTimeResolution(uint8 freqfine)
{
    /*
    * ODR correction factor: Difference in percentage of the effective 
    *                        ODR (and timestamp rate) with respect
    *                        to the typical.[set]
    *                        Step:  0.15%. 8-bit format, 2's complement.
    * The formula below can be used to calculate a better estimation of
    * the actual timestamp: 
    * TS_Res = 1000000 / (40000 + (0.0015 * INTERNAL_FREQ_FINE * 40000))
    *
    * Timestamp output registers: 1LSB = TS_Res(μs)
    */  
    asm330Attribute.timeres = 1000000 / (40000 + ( 0.0015 * freqfine * 40000) );
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 Asm330_GetEvent(void)
{
    uint8 event = asm330Attribute.event;
    
    asm330Attribute.event = ASM330_NO_EVENT; 

    return event;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Asm330_SetOpt(uint8 opt)
{
    asm330Attribute.opt = opt;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Asm330_Return_t Asm330_WriteCmd(Asm330_Addr_t addr, uint8 value, uint8 size)
{
    uint8 cmdsize = 0;
    Asm330_Return_t ret = ASM330_RETURN_FAIL;
    IIC_Return_t i2cres = eIIC_Return_Error;
    
    asm330Attribute.cmdbuff[0] = addr;
    asm330Attribute.cmdbuff[1] = value;

    cmdsize = size + ASM330_ADDR_SIZE;
    i2cres = Gyro_I2cWriteCmd(eIIC_DeviceID_GYRO, &asm330Attribute.cmdbuff[0], cmdsize);

    if(i2cres == eIIC_Return_Success)
    {
        ret = ASM330_RETURN_SUCCESS;
    }
    else
    {
        ret = ASM330_RETURN_FAIL;
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Asm330_Return_t Asm330_ReadCmd(Asm330_Addr_t addr, uint8 readsize)
{
    Asm330_Return_t ret = ASM330_RETURN_FAIL;
    IIC_Return_t i2cres = eIIC_Return_Error;

    asm330Attribute.cmdbuff[0] = addr;
    
    /*cmd buffer length must > read_size*/   
    i2cres = Gyro_I2cReadCmd(eIIC_DeviceID_GYRO, &asm330Attribute.cmdbuff[0], ASM330_ADDR_SIZE, readsize);

    if(i2cres == eIIC_Return_Success)
    {
        ret = ASM330_RETURN_SUCCESS;
    }
    else
    {
        ret = ASM330_RETURN_FAIL;
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Asm330_Return_t Asm330_ResetReq(Asm330_Config_t* config)
{
    Asm330_Return_t ret = ASM330_RETURN_FAIL;
    
    if(asm330Attribute.busy == FALSE)
    {
        Asm330_Init();

        asm330Attribute.busy = TRUE;
        asm330Attribute.opt = ASM330_RESET_HANDLE;
        asm330Attribute.event = ASM330_RESET_REQ;

        asm330ResetCmdTable[ASM330_RESET_ACC_RATE_CMD].value = config->accrate;
        asm330ResetCmdTable[ASM330_RESET_ACC_SCALE_CMD].value = config->accscale;
        asm330ResetCmdTable[ASM330_RESET_GYRO_RATE_CMD].value = config->gyrorate;
        asm330ResetCmdTable[ASM330_RESET_GYRO_SCALE_CMD].value = config->gyroscale;

        ret = ASM330_RETURN_SUCCESS;
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Asm330_Return_t Asm330_ReadReq(uint8 req, Asm330_ReadData_t* pdata)
{
    uint8 idx;
    Asm330_Return_t ret = ASM330_RETURN_FAIL;
    
    if(asm330Attribute.busy == FALSE)
    {
        asm330Attribute.cmd = 0;
        asm330Attribute.busy = TRUE;
        asm330Attribute.opt = ASM330_READ_HANDLE;
        asm330Attribute.event = ASM330_READ_REQ;
        asm330Attribute.pdata = pdata;

        for(idx = 0U; idx < ASM330_READ_CMD_NUM; idx++)
        {
            if(req & asm330ReadCmdTable[idx].type)
            {
                asm330ReadCmdTable[idx].req = TRUE;            
            }
        }
        
        ret = ASM330_RETURN_SUCCESS;
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
float Asm330_GetSensitivity(uint8 type, uint8 scale)
{
    float sensitivity = 0.0f;
    uint8 idx = 0;
    
    for(idx = 0; idx < 8; idx++)
    {
        if((asm330SensitivityTable[idx].type == type) && ((asm330SensitivityTable[idx].scale == scale)))
        {
            sensitivity = asm330SensitivityTable[idx].sensitivity;         
        }
    }
    
    return sensitivity;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Asm330_Return_t Asm330_GetDeviceId(uint8* id)
{
    Asm330_Return_t res = ASM330_RETURN_FAIL;

    if(asm330Attribute.id != ASM330_INVALID_DEVICE_ID)
    {
        *id = asm330Attribute.id;
        res = ASM330_RETURN_SUCCESS;
    }

    return res;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Asm330_WriteCallback(IIC_ResultStatus_t state)
{
    if(state == eIIC_ResultStatus_Success)
    {
        asm330Attribute.event = ASM330_WRITE_SUCCESS;
        Gyro_SendMessage();

        #ifdef GYRO_TEST
        GYRO_DEBUG("Write Successful");
        #endif
    }
    else
    {
        asm330Attribute.event = ASM330_READ_WRITE_RETRY;
        Gyro_TriggerError(GYRO_IIC_ERROR_TYPE);
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Asm330_ReadCallback(IIC_ResultStatus_t state, const uint8 * pu8buf, uint16 size)
{        

    
    if(state == eIIC_ResultStatus_Success)
    {   
        if((size <= ASM330_READ_DATA_LENGTH) && (pu8buf != NULL_PTR))
        {
            asm330Attribute.event = ASM330_READ_SUCCESS;
            memcpy(&asm330Attribute.readbuff[0], pu8buf, size);
            Gyro_SendMessage();
            
            #ifdef ASM330_TEST
            Asm330_PrintfData(pu8buf, size);
            #endif 
            #ifdef GYRO_TEST
            //GYRO_DEBUG("Read Successful");
            #endif
        }
        else
        {
            GYRO_ERROR("Read Data");
            asm330Attribute.event = ASM330_READ_WRITE_RETRY;
            Gyro_TriggerError(GYRO_IIC_ERROR_TYPE);   
        }
    }
    else
    {
        GYRO_ERROR("Read Data");
        asm330Attribute.event = ASM330_READ_WRITE_RETRY;
        Gyro_TriggerError(GYRO_IIC_ERROR_TYPE);
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
 
#ifdef ASM330_TEST
static void Asm330_TestTask(void)
{
    static uint8 timer = 10;
    timer--;
    if(timer == FALSE)
    {
       timer = 10;
        Asm330_ReadCmd(ASM330_WHO_AM_I, 1);
    }
}
static void Asm330_PrintfData(const uint8 * pu8buf, uint16 size)
{
    uint8 i = 0;
    GYRO_DEBUG("Read Asm330 Data:");
    
    for(i = 0U; i < size; i++)
    {
        GYRO_DEBUG("0x%x ", pu8buf[i]);
    }
}
#endif
