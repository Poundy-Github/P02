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
 * @file:      iic_queue.c
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

#include "Rte_IIC.h"
#include "IIC_queue.h"
#include "hal_iic.h"
#include "RingBuffer.h"
#include "IIC_cfg.h"
#include "IIC_RI.h"


#include "SRV_OSAL.h"
#include "logger.h"






typedef uint8 IIC_DrvFlag_t;
#define IIC_DrvFlag_RD_WR           ((IIC_DrvFlag_t)(0x01))         //set 1: Read mode


typedef uint8 IIC_DrvState_t;
#define eIIC_DrvState_UnInit                        (0x00u)
#define eIIC_DrvState_IDLE                          (0x01u)
#define eIIC_DrvState_RD_CMD                        (0x02u)
#define eIIC_DrvState_RD_DATA                       (0x03u)
#define eIIC_DrvState_WR_DATA                       (0x04u)
#define eIIC_DrvState_WR_ERROR_STATE                (0x05u)
#define eIIC_DrvState_RD_ERROR_STATE                (0x06u)



// Message structure
typedef struct
{
    IIC_DrvFlag_t       flag;
    IIC_DeviceID_t      devId;
    uint16              TxSize;
    uint16              RxSize;
    uint8 *             pu8buf;
}
IIC_DrvMsg_t;

//ATTENTION: Applications require less memory, so readability is a priority.

typedef struct
{
    IIC_DrvState_t              eDrvState;
    const IIC_QueueCfg_t *      tConfig_ptr;
    IIC_DrvMsg_t                tMsg;
    uint16                      pu16TimerP;
}
IIC_QueueHandler_t;


extern const IIC_DrvCfg_t tIIC_DeviceCfgTable[eIIC_DeviceID_NUMBER];
extern const IIC_QueueCfg_t tIIC_QueueCfgTable[eIIC_QueueID_NUMBER];



// Associate the queue with a hardware unit
static IIC_QueueHandler_t tQueueHandler[eIIC_QueueID_NUMBER] = {0};

#define Device_GetQueueId(tDeviceID)             (tIIC_DeviceCfgTable[tDeviceID].tQueueID)
#define Device_GetAdderId(tDeviceID)             (tIIC_DeviceCfgTable[tDeviceID].u16adder)
#define Device_GetTxCallBack_ptr(tDeviceID)      (tIIC_DeviceCfgTable[tDeviceID].tx_callback_func)
#define Device_GetRxCallBack_ptr(tDeviceID)      (tIIC_DeviceCfgTable[tDeviceID].rx_callback_func)


#define Queue_GetRB_Id(tQueueID)                 (tQueueHandler[tQueueID].tConfig_ptr->id)
#define Queue_GetHwUnitId(tQueueID)              (tQueueHandler[tQueueID].tConfig_ptr->eUnit)
#define Queue_GetState(tQueueID)                 (tQueueHandler[tQueueID].eDrvState)
#define Queue_GetMsg_Ptr(tQueueID)               (&tQueueHandler[tQueueID].tMsg)
#define Queue_SetState(tQueueID,state)           do{tQueueHandler[tQueueID].eDrvState = state;}while(0)


#define Msg_Ptr_GetDeviceAddr(Msg_Ptr)         (Device_GetAdderId(Msg_Ptr->devId))
#define Msg_Ptr_GetTxCallBack_ptr(Msg_Ptr)     (Device_GetTxCallBack_ptr(Msg_Ptr->devId))
#define Msg_Ptr_GetRxCallBack_ptr(Msg_Ptr)     (Device_GetRxCallBack_ptr(Msg_Ptr->devId))






static void SetIICQueueEventGroup(IIC_QueueID_t tQueueID,uint16 event)
{
    uint16 tMsg;
    tMsg = event;
    if (eIIC_QueueID_Unit0 == tQueueID)
    {
        (void)RI_Send_Rc_IIC0_Notify_Message(tMsg);
    }
    else
    {
        (void)RI_Send_Rc_IIC1_Notify_Message(tMsg);
    }
}


/***********************************************************************
 * @brief       : Initialize the I2C environment
 * @param       : none
 * @retval      : none
 ***********************************************************************/
IIC_Return_t IIC_QueueInit(void)
{
    uint8 i ;
    IIC_Return_t ret = eIIC_Return_Success;
    IIC_Return_t tHalRet = eIIC_Return_Error;
    RB_Return_t  tRBRet = RB_ERROR;

    HAL_IIC_Init();
    

    for (i=0; i<eIIC_QueueID_NUMBER; i++)
    {
        tQueueHandler[i].tConfig_ptr = &tIIC_QueueCfgTable[i];
        
        tRBRet = RB_Init(Queue_GetRB_Id(i));
        if ((RB_SUCCESS == tRBRet)||(RB_E_INIT == tRBRet))
        {
            tHalRet = HAL_IIC_Open(Queue_GetHwUnitId(i));
            if (eIIC_Return_Success == tHalRet)
            {

                tQueueHandler[i].eDrvState= eIIC_DrvState_IDLE;
                SRV_OSAL_Timer16_Stop(&tQueueHandler[i].pu16TimerP);
                ret = eIIC_Return_Error;
            }
        }
        else
        {
            ret = eIIC_Return_Error;
        }
    }

    return ret;
}


/***********************************************************************
 * @brief       : The request is sent, and the data is queued up to be sent
 * @param       : pu8buf:if tx_size > 0;user tx_buffer; 
 * @retval      : Reference IIC_Return_t;
 ***********************************************************************/
IIC_Return_t IIC_QueueRxReq(IIC_DeviceID_t devId, uint8 *pu8buf, uint16 TxSize, uint16 RxSize)
{
    IIC_Return_t   ret = eIIC_Return_Error;
    RB_Return_t tRBRet = RB_ERROR;
    
    IIC_DrvMsg_t   msg = {0}; 
    IIC_QueueID_t  queueId;
    
    
    queueId = Device_GetQueueId(devId);
    
    if (eIIC_DeviceID_NUMBER <= devId)
    {
        ret = eIIC_Return_E_PARAM;
    }
    else if (NULL_PTR == pu8buf)
    {
        ret = eIIC_Return_E_EMPTY;
    }
    else if (eIIC_DrvState_UnInit == Queue_GetState(queueId))
    {
        ret = eIIC_Return_E_UnOpen;
    }
    else
    {
        
        
        msg.devId = devId;
        msg.flag  = IIC_DrvFlag_RD_WR;
        msg.pu8buf = pu8buf;
        msg.TxSize = TxSize;
        msg.RxSize = RxSize;
        
        tRBRet = RB_Push(Queue_GetRB_Id(queueId),(uint8 *)(&msg),sizeof(IIC_DrvMsg_t));
        if ( 0 > tRBRet )
        {
            ret = eIIC_Return_E_RB;
        }
        else
        {
            SetIICQueueEventGroup(queueId,EVENT_I2C_TX_RX);
            ret = eIIC_Return_Success;
        }
    }
    return ret;
}


/***********************************************************************
 * @brief       : The request is Read.
 * @param       : 
 * @retval      : Reference IIC_Return_t;
 ***********************************************************************/
IIC_Return_t IIC_QueueTxReq(IIC_DeviceID_t devId, uint8 *pu8buf, uint16 TxSize)
{
    IIC_Return_t ret = eIIC_Return_Error;
    RB_Return_t rb_ret = RB_ERROR;
    IIC_DrvMsg_t   msg = {0}; 
    IIC_QueueID_t  queueId;

    queueId = Device_GetQueueId(devId);
    
    if (eIIC_DeviceID_NUMBER <= devId)
    {
        ret = eIIC_Return_E_PARAM;
    }
    else if (NULL_PTR == pu8buf)
    {
        ret = eIIC_Return_E_EMPTY;
    }
    else if (eIIC_DrvState_UnInit == Queue_GetState(queueId))
    {
        ret = eIIC_Return_E_UnOpen;
    }
    else
    {
        msg.devId = devId;
        msg.flag  = 0;
        msg.pu8buf = pu8buf;
        msg.TxSize = TxSize;
        msg.RxSize = 0;

        rb_ret = RB_Push(Queue_GetRB_Id(queueId),(uint8 *)(&msg),sizeof(IIC_DrvMsg_t));
        if ( 0 > rb_ret )
        {
            ret = eIIC_Return_E_RB;
        }
        else
        {
            SetIICQueueEventGroup(queueId,EVENT_I2C_TX_RX);
            ret = eIIC_Return_Success;
        }
        
    }
    return ret;
}

void IIC_QueueResultUpdate(IIC_QueueState_t rcv)
{
   uint16 tMsg ;
   
   if (I2C_QUEUE_SUCCESS == rcv)
   {   
       tMsg = EVENT_I2C_SUCCESS;
   }
   else
   {
       tMsg = EVENT_I2C_ERROR;
   }
   
   (void)RI_Send_Rc_IIC0_Notify_Message(tMsg);

}



void IIC1_QueueResultUpdate(IIC_QueueState_t rcv)
{
    uint16 tMsg ;
    
    if (I2C_QUEUE_SUCCESS == rcv)
    {   
        tMsg = EVENT_I2C_SUCCESS;
    }
    else
    {
        tMsg = EVENT_I2C_ERROR;
    }
    
    (void)RI_Send_Rc_IIC1_Notify_Message(tMsg);
}




static void IIC_DrvState_IDLE_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    RB_Return_t len;
    IIC_Return_t ret;

    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    if (event & (EVENT_I2C_TX_RX | EVENT_I2C_SCAN))
    {
        len = RB_Pop(Queue_GetRB_Id(tQueueID),(uint8 *)(msg_ptr),sizeof(IIC_DrvMsg_t));
        if (0 < len)
        {
            if ((msg_ptr->flag & IIC_DrvFlag_RD_WR))
            {
                if (0 != msg_ptr->TxSize)  // send read cmd
                {
                    ret = HAL_IIC_Write(Queue_GetHwUnitId(tQueueID),
                                    Msg_Ptr_GetDeviceAddr(msg_ptr),
                                    msg_ptr->pu8buf,
                                    msg_ptr->TxSize);
                }
                else
                {
                    ret = HAL_IIC_Read(Queue_GetHwUnitId(tQueueID),
                            Msg_Ptr_GetDeviceAddr(msg_ptr),
                            msg_ptr->pu8buf,
                            msg_ptr->RxSize);
                }
                
                if (eIIC_Return_Success != ret)
                {
                    
                    Queue_SetState(tQueueID,eIIC_DrvState_RD_ERROR_STATE);
                    SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
                }
                else
                {
                    SRV_OSAL_Timer16_Start(&tQueueHandler[tQueueID].pu16TimerP);
                    if (0 != msg_ptr->TxSize)
                    {
                        Queue_SetState(tQueueID,eIIC_DrvState_RD_CMD);
                    }
                    else
                    {
                        Queue_SetState(tQueueID,eIIC_DrvState_RD_DATA);
                    }
                }
            }
            else
            {
                ret = HAL_IIC_Write(Queue_GetHwUnitId(tQueueID),
                        Msg_Ptr_GetDeviceAddr(msg_ptr),
                        msg_ptr->pu8buf,
                        msg_ptr->TxSize);
                if (eIIC_Return_Success != ret)
                {
                    
                    Queue_SetState(tQueueID,eIIC_DrvState_WR_ERROR_STATE);
                    SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
                }
                else
                {
                    SRV_OSAL_Timer16_Start(&tQueueHandler[tQueueID].pu16TimerP);
                    Queue_SetState(tQueueID,eIIC_DrvState_WR_DATA);
                }
            }
        }

    }
}


static void IIC_DrvState_RD_CMD_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    IIC_Return_t ret;

    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    
    if (event & EVENT_I2C_SUCCESS)
    {
        ret = HAL_IIC_Read(Queue_GetHwUnitId(tQueueID),
                Msg_Ptr_GetDeviceAddr(msg_ptr),
                msg_ptr->pu8buf,
                msg_ptr->RxSize);
        if (eIIC_Return_Success != ret)
        {
            Queue_SetState(tQueueID,eIIC_DrvState_RD_ERROR_STATE);
            SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
        }
        else
        {
            Queue_SetState(tQueueID,eIIC_DrvState_RD_DATA);
        }
    }
    else if  (event & (EVENT_I2C_ERROR | EVENT_I2C_TIMOUT))
    {
        Queue_SetState(tQueueID,eIIC_DrvState_RD_ERROR_STATE);
        SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
    }
}

static void IIC_DrvState_RD_DATA_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    p_rx_callback_t callback_ptr;

    
    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    callback_ptr = Msg_Ptr_GetRxCallBack_ptr(msg_ptr);
    if (event & EVENT_I2C_SUCCESS)
    {
        
        if (NULL_PTR != callback_ptr)
        {
            callback_ptr(eIIC_ResultStatus_Success,msg_ptr->pu8buf,msg_ptr->RxSize);
        }
        SRV_OSAL_Timer16_Stop(&tQueueHandler[tQueueID].pu16TimerP);
        Queue_SetState(tQueueID,eIIC_DrvState_IDLE);
    } 
    else if (event & (EVENT_I2C_ERROR | EVENT_I2C_TIMOUT))
    {
        Queue_SetState(tQueueID,eIIC_DrvState_RD_ERROR_STATE);
        SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
    }
}

static void IIC_DrvState_WR_DATA_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    p_tx_callback_t callback_ptr;

    
    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    callback_ptr = Msg_Ptr_GetTxCallBack_ptr(msg_ptr);

    if (event & EVENT_I2C_SUCCESS)
    {
        if (NULL_PTR != callback_ptr)
        {
            callback_ptr(eIIC_ResultStatus_Success);
        }
        SRV_OSAL_Timer16_Stop(&tQueueHandler[tQueueID].pu16TimerP);
        Queue_SetState(tQueueID,eIIC_DrvState_IDLE);
    }
    else if (event & (EVENT_I2C_ERROR | EVENT_I2C_TIMOUT))
    {
        Queue_SetState(tQueueID,eIIC_DrvState_WR_ERROR_STATE);
        SetIICQueueEventGroup(tQueueID,EVENT_I2C_ERROR);
    }
}

static void IIC_DrvState_WR_ERROR_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    p_tx_callback_t callback_ptr;

    (void)event;
    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    callback_ptr = Msg_Ptr_GetTxCallBack_ptr(msg_ptr);

    if (NULL_PTR != callback_ptr)
    {
        callback_ptr(eIIC_ResultStatus_Error);
    }
    SRV_OSAL_Timer16_Stop(&tQueueHandler[tQueueID].pu16TimerP);
    Queue_SetState(tQueueID,eIIC_DrvState_IDLE);

}

static void IIC_DrvState_RD_ERROR_Dispose(IIC_QueueID_t tQueueID,uint16 event)
{
    IIC_DrvMsg_t * msg_ptr;
    p_rx_callback_t callback_ptr;

    (void)event;
    msg_ptr = Queue_GetMsg_Ptr(tQueueID);
    callback_ptr = Msg_Ptr_GetRxCallBack_ptr(msg_ptr);

    if (NULL_PTR != callback_ptr)
    {
        callback_ptr(eIIC_ResultStatus_Error,msg_ptr->pu8buf,msg_ptr->RxSize);
    }
    SRV_OSAL_Timer16_Stop(&tQueueHandler[tQueueID].pu16TimerP);
    Queue_SetState(tQueueID,eIIC_DrvState_IDLE);
}

/***********************************************************************
 * @brief       : log handling.
 * @param       : 
 * @retval      : none
 ***********************************************************************/
static void IIC_error_log(IIC_QueueID_t tQueueID)
{
	static uint32 iiclogcounter;
	
	iiclogcounter++;
	if(iiclogcounter<= 50)
	{
		power_err("iic%d timeout",tQueueID);	
	}
	if(iiclogcounter>50)
	{
		if(0 == (iiclogcounter%50))
		{
			power_err("iic%d timeout %d",tQueueID,(50+(iiclogcounter/50)));	
		}
	}
}

/***********************************************************************
 * @brief       : event handling.
 * @param       : 
 * @retval      : none
 ***********************************************************************/
void IIC_StateManage(IIC_QueueID_t tQueueID,uint16 event)
{
    RB_Return_t len;
    boolean bTimeOut = TRUE;
    if (eIIC_DrvState_UnInit != Queue_GetState(tQueueID))
    {
        switch(Queue_GetState(tQueueID))
        {
            case eIIC_DrvState_IDLE:
                IIC_DrvState_IDLE_Dispose(tQueueID,event);
                break;
            case eIIC_DrvState_RD_CMD:
                IIC_DrvState_RD_CMD_Dispose(tQueueID,event);
                break;
            case eIIC_DrvState_RD_DATA:
                IIC_DrvState_RD_DATA_Dispose(tQueueID,event);
                break;
            case eIIC_DrvState_WR_DATA:
                IIC_DrvState_WR_DATA_Dispose(tQueueID,event);
                break;
            case eIIC_DrvState_WR_ERROR_STATE:
                IIC_DrvState_WR_ERROR_Dispose(tQueueID,event);
                break;
            case eIIC_DrvState_RD_ERROR_STATE:
                IIC_DrvState_RD_ERROR_Dispose(tQueueID,event);
                break;
            default:
                Queue_SetState(tQueueID,eIIC_DrvState_IDLE);
                break;
        }
        if (eIIC_DrvState_IDLE == Queue_GetState(tQueueID))
        {
            len = RB_NumberGet(Queue_GetRB_Id(tQueueID));
            if (0 < len)
            {
                SetIICQueueEventGroup(tQueueID,EVENT_I2C_TX_RX);
            }
        }
        else
        {
            bTimeOut = SRV_OSAL_Timer16_IsElapsed(tQueueHandler[tQueueID].pu16TimerP,cIIC_TimeOutMs);
            if (TRUE == bTimeOut)
            {
                HAL_IIC_Reset(Queue_GetHwUnitId(tQueueID));
                SetIICQueueEventGroup(tQueueID,EVENT_I2C_TIMOUT);
				IIC_error_log(tQueueID);
            }
        }
    }
}




