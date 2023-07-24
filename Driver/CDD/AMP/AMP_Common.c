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
 * @file:      AMP_Common.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "AMP_Common.h"
#include "string.h"
#include "Rte_AMP.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMP.h"
#include "AMP_cfg.h"



typedef struct
{
    uint32  TMStart;
    uint32  TMEnd;
}S_Timer_Cfg_Type;

typedef struct
{
    uint8 ResponseRetry;
    uint8 DataRetry;
}s_IICRx_Retry_Type;

#define AMPIICRXRESPONSERCUNT                       (5u)

#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

extern const uint8 AMPPIN_Table[DEVICE_NUM][PIN_8532_Number];

#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h" 

extern const iic_cmd_length_t iic_cmd_length_cfg[AMPIICFlgNum];
extern s_AMP_State_Type AMP_State_Data[DEVICE_NUM];
I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];
static S_Timer_Cfg_Type Timer_Cfg[TIMER_NUM];
static s_IICRx_Retry_Type IICRxRetry[DEVICE_NUM];

#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h" 



#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"



#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

static void amp_iic_request(uint8 dev_id, uint8 iic_flg);
static void AMP_TxCallback(uint8 dev_id,IIC_ResultStatus_t state);
static void AMPIICRXResponseOper(uint8 dev_id);
static void AMPIICRXDataOper(uint8 dev_id);
static void AMPIICStructData(uint8 dev_id, uint8 IICFlg);



#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_CommonInit(uint8 dev_id)
{
    (void)memset(&I2C_Req_AMPData[dev_id], 0, sizeof(I2C_AMPReq_t));
    I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : uint is 1ms
 ***********************************************************************/
void AMP_TimerStart(const uint8 timer_id)
{
    (void)GetCounterValue(SystemTimer,&Timer_Cfg[timer_id].TMStart);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_TimerEnd(const uint8 timer_id)
{
    Timer_Cfg[timer_id].TMStart = 0u;
    Timer_Cfg[timer_id].TMEnd = 0u;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean AMP_TimerIsStarted(const uint8 timer_id)
{
    if(Timer_Cfg[timer_id].TMStart > 0u)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/***********************************************************************
 * @brief       : For some reason, the unit of judgment is 0.1ms
 * @param       : unit is 0.1ms
 * @retval      : 
 ***********************************************************************/
boolean AMP_TimerIsElasped(const uint8 timer_id,const uint32 TimerMax)
{
    (void)GetCounterValue(SystemTimer,&Timer_Cfg[timer_id].TMEnd);
    if( ((Timer_Cfg[timer_id].TMEnd - Timer_Cfg[timer_id].TMStart) * 10u) >= TimerMax )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_I2C_Req_State_Oper(uint8 dev_id, uint8 IICFlg)
{
    if(I2C_Req_Idle == I2C_Req_AMPData[dev_id].Sts)
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Trigger;
        AMPIICStructData(dev_id,IICFlg);
    }

    switch(I2C_Req_AMPData[dev_id].Sts)
    {
        case I2C_Req_Trigger:
            amp_iic_request(dev_id, IICFlg);
            break;
        case I2C_Req_Wait:
            if(TRUE == AMP_TimerIsStarted(dev_id))
            {
                uint8 I2CFlg = I2C_Req_AMPData[dev_id].Flg;
                if(TRUE == AMP_TimerIsElasped(dev_id,iic_cmd_length_cfg[I2CFlg].ExeTime))
                {
                    AMP_TimerEnd(dev_id);
                    I2C_Req_AMPData[dev_id].Sts = I2C_Req_Success;
                }
            }
            else
            {
                AMP_TimerStart(dev_id);
            }
            break;
        case I2C_Req_RXResponseTrigger:
            AMPIICRXResponseOper(dev_id);
            
            break;
        case I2C_Req_RXDataTrigger:
            AMPIICRXDataOper(dev_id);
            
            break;
        case I2C_Req_PushSucess:
        case I2C_Req_RXResponseWait:
        case I2C_Req_RXDataWait:
            /*wait*/
            break;
        default:
        	/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : Copy Data to I2C_Req_Data
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIICStructData(uint8 dev_id, uint8 IICFlg)
{
   if(((SET_CLOCKSTATE != IICFlg) && (GET_DEVICESTATE != IICFlg)))
   {
       //amp_info("[AMP%d]Requset %s Trigger",dev_id + 1,iic_cmd_length_cfg[IICFlg].LogName);
   }

   if(AMPIIC_READ == iic_cmd_length_cfg[IICFlg].OperType)
   {
       iic_cmd_length_cfg[IICFlg].p_fun(dev_id);
       (void)memset(&I2C_Req_AMPData[dev_id].Data[0],0,AMP_IICFDATAMAXLENGTH);
   }
   else if(AMPIIC_WRITE == iic_cmd_length_cfg[IICFlg].OperType)
   {
       iic_cmd_length_cfg[IICFlg].p_fun(dev_id);
       (void)memset(&I2C_Req_AMPData[dev_id].Rx_Response[0],0,5);
       (void)memset(&I2C_Req_AMPData[dev_id].Rx_Request[0],0,5);
   }
   I2C_Req_AMPData[dev_id].Flg = IICFlg;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIICRXResponseOper(uint8 dev_id)
{
    IIC_Return_t RxRequestRet;
    RxRequestRet = IIC_QueueRxReq(eIIC_DeviceID_AMP1 + dev_id, &I2C_Req_AMPData[dev_id].Rx_Response[0], 0, 3);
    if(eIIC_Return_Success == RxRequestRet)
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_RXResponseWait;
        I2C_Req_AMPData[dev_id].Counter = 0u;
    }
    else
    {
        I2C_Req_AMPData[dev_id].Counter ++;
        if (I2C_Req_AMPData[dev_id].Counter >= I2C_Req_Fail_Counter)
        {
            I2C_Req_AMPData[dev_id].Counter = 0u;
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
        }
        else 
        {
            (void)amp_info("[AMP%d] %s RxResponse ret not Success",dev_id,iic_cmd_length_cfg[I2C_Req_AMPData[dev_id].Flg].LogName);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIICRXDataOper(uint8 dev_id)
{
    IIC_Return_t RxDataRet;
    RxDataRet = IIC_QueueRxReq(eIIC_DeviceID_AMP1 + dev_id, &I2C_Req_AMPData[dev_id].Data[0], 0u,((uint16)I2C_Req_AMPData[dev_id].Rx_Response[2]+3u));
    if(eIIC_Return_Success == RxDataRet)
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_RXDataWait;
        I2C_Req_AMPData[dev_id].Counter = 0u;
    }
    else
    {
        I2C_Req_AMPData[dev_id].Counter ++;
        if (I2C_Req_AMPData[dev_id].Counter >= I2C_Req_Fail_Counter)
        {
            I2C_Req_AMPData[dev_id].Counter = 0u;
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
        }
        else 
        {
            (void)amp_info("[AMP%d] %s RxResponse ret not Success",dev_id,iic_cmd_length_cfg[I2C_Req_AMPData[dev_id].Flg].LogName);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void amp_iic_request(uint8 dev_id, uint8 iic_flg)
{
    IIC_Return_t    req_result = eIIC_Return_Error;
    if (AMPIIC_READ == iic_cmd_length_cfg[iic_flg].OperType)
    {
        (void)memcpy(&I2C_Req_AMPData[dev_id].Rx_Response, &I2C_Req_AMPData[dev_id].Rx_Request, AMP_RX_TX_LENGTH);
        req_result = IIC_QueueRxReq(eIIC_DeviceID_AMP1 + dev_id,&I2C_Req_AMPData[dev_id].Rx_Response[0], AMP_RX_TX_LENGTH, 3u);
        if(((SET_CLOCKSTATE != iic_flg) && (GET_DEVICESTATE != iic_flg)))
        {
            //amp_info("[AMP%d] Rx Request Data:",dev_id + 1);
        }
    }
    else if(AMPIIC_WRITE == iic_cmd_length_cfg[iic_flg].OperType)
    {
        req_result = IIC_QueueTxReq(eIIC_DeviceID_AMP1 + dev_id, &I2C_Req_AMPData[dev_id].Data[0],iic_cmd_length_cfg[iic_flg].Length);
        if(((SET_CLOCKSTATE != iic_flg) && (GET_DEVICESTATE != iic_flg)))
        {
            //amp_info("[AMP%d] Tx Data is",dev_id + 1);
            //AMPArrayPrint(&I2C_Req_Data[dev_id].Data[0],iic_cmd_length_cfg[iic_flg].Length);
        }
    }

    if (eIIC_Return_Success == req_result)
    {
        I2C_Req_AMPData[dev_id].Sts        = I2C_Req_PushSucess;
        I2C_Req_AMPData[dev_id].Counter    = 0u;
    }
    else
    {
        I2C_Req_AMPData[dev_id].Counter ++;
        if (I2C_Req_AMPData[dev_id].Counter >= I2C_Req_Fail_Counter)
        {
            I2C_Req_AMPData[dev_id].Counter = 0u;
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
        }
        else 
        {
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Trigger;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSet_I2C_Req_Data(uint8 dev_id,uint8 *ptr, uint8 Length)
{
    (void)memcpy(&I2C_Req_AMPData[dev_id].Data[0],ptr,Length);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSetRead_I2C_Req_Data(uint8 dev_id,uint8 *ptr, uint8 Length)
{
    (void)memcpy(&I2C_Req_AMPData[dev_id].Rx_Request[0],ptr,Length);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSet_I2C_Req_DataSts(uint8 dev_id,I2C_Req_Sts_t Sts)
{
    I2C_Req_AMPData[dev_id].Sts = Sts;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
I2C_Req_Sts_t AMPGet_I2C_Req_DataSts(uint8 dev_id)
{
    return I2C_Req_AMPData[dev_id].Sts;
}

/***********************************************************************
 * @brief       : 
 * @param       :
 * @retval      : 
 ***********************************************************************/
static void AMP_Rx_Callback(uint8 dev_id,IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
	(void)size;
	(void)(*p_data);
    if (eIIC_ResultStatus_Success == state)
    {
        if(I2C_Req_PushSucess == I2C_Req_AMPData[dev_id].Sts)
        {
            if (0x06u != I2C_Req_AMPData[dev_id].Rx_Response[0])
            {
                I2C_Req_AMPData[dev_id].Sts = I2C_Req_RXResponseTrigger;
            }
            else
            {
                I2C_Req_AMPData[dev_id].Sts = I2C_Req_RXDataTrigger;
                //amp_info("[AMP%d] Change From PushSuccess to Data Trigger",dev_id + 1);
                if(((SET_CLOCKSTATE != I2C_Req_AMPData[dev_id].Flg) && (GET_DEVICESTATE != I2C_Req_AMPData[dev_id].Flg)))
                {
                    (void)amp_info("[AMP%d] Rx ResPonse Data:",dev_id + 1);
                    AMPArrayPrint(&I2C_Req_AMPData[dev_id].Rx_Response[0],3u);
                }
            }
        }
        else if(I2C_Req_RXResponseWait == I2C_Req_AMPData[dev_id].Sts)
        {
            if (0x06u != I2C_Req_AMPData[dev_id].Rx_Response[0])
            {
                IICRxRetry[dev_id].ResponseRetry ++;
                if(IICRxRetry[dev_id].ResponseRetry >=AMPIICRXRESPONSERCUNT)
                {
                    I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
                    IICRxRetry[dev_id].ResponseRetry = 0u;
                }
                else
                {
                    I2C_Req_AMPData[dev_id].Sts         = I2C_Req_RXResponseTrigger;
                }
            }
            else 
            {
                IICRxRetry[dev_id].ResponseRetry     = 0u;
                I2C_Req_AMPData[dev_id].Sts             = I2C_Req_RXDataTrigger;
                if(((SET_CLOCKSTATE != I2C_Req_AMPData[dev_id].Flg) && (GET_DEVICESTATE != I2C_Req_AMPData[dev_id].Flg)))
                {
                    //amp_info("[AMP%d] Rx ResPonse Data:",dev_id + 1);
                    //AMPArrayPrint(&I2C_Req_Data[dev_id].Rx_Response[0],3);
                }
            }
        }
        else if(I2C_Req_RXDataWait == I2C_Req_AMPData[dev_id].Sts)
        {
            if (0x02u != I2C_Req_AMPData[dev_id].Data[0])
            {
                IICRxRetry[dev_id].DataRetry ++;
                if(IICRxRetry[dev_id].DataRetry >=AMPIICRXRESPONSERCUNT)
                {
                    I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
                    IICRxRetry[dev_id].DataRetry = 0u;
                }
                else
                {
                    I2C_Req_AMPData[dev_id].Sts             = I2C_Req_RXDataTrigger;
                }
            }
            else 
            {
                I2C_Req_AMPData[dev_id].Sts = I2C_Req_Success;
                IICRxRetry[dev_id].DataRetry = 0u;
                if((SET_CLOCKSTATE != I2C_Req_AMPData[dev_id].Flg) && (GET_DEVICESTATE != I2C_Req_AMPData[dev_id].Flg))
                {
                    //amp_info("[AMP%d] Rx Data Info:",dev_id + 1);
                    //AMPArrayPrint(&I2C_Req_Data[dev_id].Data[0],I2C_Req_Data[dev_id].Rx_Response[2] +3);
                }
            }
        }
    }
    else 
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
        (void)amp_info("[AMP%d] Rx Callback Return Error !!",dev_id + 1);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP1_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
    AMP_Rx_Callback(DEVICE_AMP1,state,p_data,size);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP2_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
    AMP_Rx_Callback(DEVICE_AMP2,state,p_data,size);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_TxCallback(uint8 dev_id,IIC_ResultStatus_t state)
{
    if (eIIC_ResultStatus_Success == state)
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Wait;
        if(TRUE ==  AMP_TimerIsStarted(dev_id))
        {
            (void)amp_err("AMP Timer Tx%d Callback conflict",dev_id);
        }
        else
        {
            AMP_TimerStart(dev_id);
        }
    }
    else 
    {
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Err;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP1_I2CTx_Callback(IIC_ResultStatus_t state)
{
    //amp_info("Reveive AMP1 Tx CallBack\n");
    AMP_TxCallback(DEVICE_AMP1,state);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP2_I2CTx_Callback(IIC_ResultStatus_t state)
{
    //amp_info("Reveive AMP2 Tx CallBack\n");
    AMP_TxCallback(DEVICE_AMP2,state);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP8532_Set_Pin(uint8 dev_id, AMP_8532_PIN_ID_t pin_id, Dio_LevelType pin_sts)
{
    Dio_WriteChannel((Dio_ChannelType) AMPPIN_Table[dev_id][pin_id], pin_sts);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Dio_LevelType AMP8532_Get_Pin(uint8 dev_id, AMP_8532_PIN_ID_t pin_id)
{
	return( Dio_ReadChannel((Dio_ChannelType) AMPPIN_Table[dev_id][pin_id]) );
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_HWMuteOperate(uint8 dev_id,uint8 MuteType)
{
    if (AMP_HWMUTE == MuteType)
    {
        AMP8532_Set_Pin(dev_id, AMPPIN_MUTE_N, STD_LOW);
    }
    else if (AMP_HWUNMUTE == MuteType)
    {
        AMP8532_Set_Pin(dev_id, AMPPIN_MUTE_N, STD_HIGH);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSet_NextDeviceState(uint8 dev_id,uint8 State)
{
    AMP_State_Data[dev_id].NextState = State;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_StateIICCallback(void *State,uint8 dev_id,uint8 nextstate,uint8 errstate,IICCallback ptr)
{
    if (I2C_Req_Success == I2C_Req_AMPData[dev_id].Sts)
    {
        if(NULL != ptr)
        {
            Std_ReturnType ret = ptr(dev_id);
            if(E_OK == ret)
            {
                //amp_info("[AMP%d] Change From %d to %d",dev_id + 1,*(uint8 *)State,nextstate);
                *(uint8 *)State = nextstate;
                I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
            }
        }
        else
        {
            //amp_info("[AMP%d] Change from %d to %d",dev_id + 1,(*(uint8 *)State),nextstate);
            *(uint8 *)State = nextstate;
            I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
        }
    }
    else if(I2C_Req_Err == I2C_Req_AMPData[dev_id].Sts)
    {
    	(void)amp_info("[AMP%d] Change from %d to ERR",dev_id + 1,(*(uint8 *)State));
        *(uint8 *)State = errstate;
        I2C_Req_AMPData[dev_id].Sts = I2C_Req_Idle;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPArrayPrint(uint8* Array, uint8 Length)
{
    char LogName[90];
    uint8 Index;

    if(Length <= 30u)
    {
        (void)memset(LogName,0,sizeof(LogName));
        for(Index = 0u;Index < Length;Index++)
        {
            LogName[3 * Index]      = HEX_TO_STR((Array[Index] >> 4) & 0xFu);
            LogName[(3 * Index) + 1]  = HEX_TO_STR(Array[Index] & 0xFu);
            LogName[(3 * Index) + 2]  = ' ';
        }
        (void)amp_info("%s",LogName);
    }
}


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

