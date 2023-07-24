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
 * @file:      Ipc_STB_If.c
 * @author:    Nobo
 * @date:      2020-9-18
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-18
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"
#ifdef PLATFORM_OF_STB_IPC_USED

/*
 *  %header file in this project/library%
 */

#include "string.h"
#include "Std_Types.h"
#include "IPC_STB_If.h"
#include "IPC_STB_Monitor.h"
#include "IPC_STB_Com.h"
#include "logger.h"
#include "Rte_IPC.h"
#include "IPC_STB_LoadTest.h"
#include "SOCManager_IPC_Service.h"

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 


uint8 IPC_STB_TxDataHighPri[IPC_STB_DATA_HIGH_PRI_LENGTH]; /*IPC_STB DMA High priority send data buffer.*/  
uint8 IPC_STB_TxDataLowPri[IPC_STB_DATA_LOW_PRI_LENGTH]; /*IPC_STB DMA High priority send data buffer.*/  

uint16 IPC_STB_TxDataHighPriLen;
uint16 IPC_STB_TxDataLowPriLen;

static e_IPC_STB_StateType_t IPC_STB_StateType = IPC_STB_NONE_INIT;

#if(STD_ON == IPC_STB_BUFFER_FULL_PRITF_EN)
e_IPC_STB_ErrorType_t tIpcStbBuffFullStatus = IPC_STB_ERR_NONE;
#endif


#pragma ghs section bss = default 
#pragma ghs section data = default 

static const s_IPC_STB_CallbackRegister_t IPC_STBCallbackRegisterList[] = IPC_STB_APP_REGISTER_LIST;
static void IPC_STB_MessageDispatch(uint8 *p_msg, uint16 msg_len);

/*******************************************************************************
* Function: IPC_STB_If_Init
* Description: Handle IPC_STB initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_If_Init(void)
{
    memset(IPC_STB_TxDataHighPri, 0x00, IPC_STB_DATA_HIGH_PRI_LENGTH);
    memset(IPC_STB_TxDataLowPri, 0x00, IPC_STB_DATA_LOW_PRI_LENGTH);
    IPC_STB_TxDataHighPriLen = 0;
    IPC_STB_TxDataLowPriLen = 0;

    IPC_STB_Monitor_Init();
    IPC_STB_Com_Init();

    IPC_STB_StateType = IPC_STB_INIT_DONE;
}

/*******************************************************************************
* Function: IPC_STB_DeInit
* Description: Handle IPC_STB deinitial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_DeInit(void)
{
    IPC_STB_StateType = IPC_STB_NONE_INIT;
    IPC_STB_Monitor_DeInit();
    IPC_STB_Com_DeInit();
}

/*******************************************************************************
* Function: IPC_STB_DeInit
* Description: Handle IPC_STB deinitial
* Parameter: void
* Return: void
*******************************************************************************/
static e_IPC_STB_ErrorType_t IPC_STB_AppendDataToBuffer(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_STB_ErrorType_t ret = IPC_STB_ERR_NONE;
    uint8 *p_register;
    uint16 uMsgLength;

    if( (len > IPC_STB_MAX_TX_MSG_PLOAD_LENGTH) || (len <= IPC_TRANSPORT_OVERHEAD))
    {
        ret = IPC_STB_ERR_PLOAD_SIZE;
    }

    if(p_msg == NULL_PTR)
    {
        ret = IPC_STB_ERR_NO_MSG;
    }

    if((priority != IPC_PRIORITY_LOW) && (priority != IPC_PRIORITY_HIGH))
    {
        ret = IPC_STB_ERR_PRIORITY;
    }

    if(ret == IPC_STB_ERR_NONE)
    {
        if(priority == IPC_PRIORITY_HIGH)
        {
            /* High priority message */
            uMsgLength = len + IPC_STB_MSG_LENGTH_LEN;
            
            IPC_STB_ENTER_CRITICAL();
            if((uMsgLength + IPC_STB_TxDataHighPriLen) <= IPC_STB_DATA_HIGH_PRI_LENGTH)
            {
                p_register = &IPC_STB_TxDataHighPri[IPC_STB_TxDataHighPriLen];

                p_register[0] = (uint8)(uMsgLength >> 8);   /*Insert 1st byte msg_len*/
                p_register[1] = (uint8)(uMsgLength & 0xFF);    /*Insert 2st byte msg_len*/
                memcpy(&p_register[2],p_msg,len);

                IPC_STB_TxDataHighPriLen = IPC_STB_TxDataHighPriLen + uMsgLength;   /* Update length  */
                TST_IPC_STB_CheckSendData(p_msg, len);
            }
            else
            {
                ret = IPC_STB_ERR_BUFFER_FULL;
            }
            IPC_STB_EXIT_CRITICAL();
        }
        else
        {
            /* Low priority message */
            uMsgLength = len + IPC_STB_MSG_LENGTH_LEN;
            
            IPC_STB_ENTER_CRITICAL();
            if((uMsgLength + IPC_STB_TxDataLowPriLen) <= IPC_STB_DATA_LOW_PRI_LENGTH)
            {
                p_register = &IPC_STB_TxDataLowPri[IPC_STB_TxDataLowPriLen];

                p_register[0] = (uint8)(uMsgLength >> 8);   /*Insert 1st byte msg_len*/
                p_register[1] = (uint8)(uMsgLength & 0xFF);    /*Insert 2st byte msg_len*/
                memcpy(&p_register[2],p_msg,len );
                IPC_STB_TxDataLowPriLen = IPC_STB_TxDataLowPriLen + uMsgLength;  /* Update length  */
                TST_IPC_STB_CheckSendData(p_msg, len);
            }
            else
            {
                ret = IPC_STB_ERR_BUFFER_FULL;
            }
            IPC_STB_EXIT_CRITICAL();
        }
    }

#if (STD_ON == IPC_STB_BUFFER_FULL_PRITF_EN)
		tIpcStbBuffFullStatus = ret;
#endif

    return (ret);
}

/*******************************************************************************
* Function: IPC_STB_DeInit
* Description: Handle IPC_STB deinitial
* Parameter: void
* Return: void
*******************************************************************************/
e_IPC_STB_ErrorType_t IPC_STB_DataSend(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_STB_ErrorType_t ret = IPC_STB_ERR_NONE;
    uint8 *p_register;
    uint16 uMsgLength;


    if(IPC_STB_StateType == IPC_STB_NONE_INIT)
    {
        ret = IPC_STB_ERR_NINIT;
    }
    else if (IPC_STB_StateType !=IPC_STB_CONN_READY)
    {
        ret = IPC_STB_ERR_NREADY;
    }
    else
    {
        ret = IPC_STB_AppendDataToBuffer(p_msg,len,priority);
    }

    if(ret == IPC_STB_ERR_NONE)
    {
        //check IPC_STB idle
        if(IPC_STB_GetIPC_STBState()==IPC_STB_STATE_IDLE)
        {
            IPC_STB_TriggerMainfunction(FALSE);
        }
    }
    return (ret);
}
/*******************************************************************************
* Function: IPC_DeInit
* Description: Handle IPC deinitial
* Parameter: void
* Return: void
*******************************************************************************/
e_IPC_STB_StateType_t IPC_STB_DataSendFormHandshake(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_STB_ErrorType_t ret = IPC_STB_ERR_NONE;
    uint8 *p_register;
    uint16 uMsgLength;


    if(IPC_STB_StateType == IPC_STB_NONE_INIT)
    {
        ret = IPC_STB_ERR_NINIT;
    }
    else
    {
        ret = IPC_STB_AppendDataToBuffer(p_msg,len,priority);
    }

    if(ret == IPC_STB_ERR_NONE)
    {
        //check IPC_STB idle
        if(IPC_STB_GetIPC_STBState()==IPC_STB_STATE_IDLE)
        {
            IPC_STB_TriggerMainfunction(FALSE);
        }
    }
    return (ret);

}

/*******************************************************************************
* Function: IPC_STB_CheckDataSend
* Description: check whether have data to send
* Parameter: void
* Return: void
*******************************************************************************/
boolean IPC_STB_CheckDataSend(void)
{
    boolean ret = FALSE;

    if((IPC_STB_TxDataHighPriLen >IPC_STB_MSG_HEAD_LEN) || (IPC_STB_TxDataLowPriLen >IPC_STB_MSG_HEAD_LEN))
    {
        /* Data buffer have data ready to send, return true */
        ret = TRUE;
    }
    return ret;
}


/*******************************************************************************
* Function: IPC_STB_SetIPC_STBStateType
* Description: Set IPC_STB state type
* Parameter: IPC_STB_NONE_INIT, IPC_STB_INIT_DONE,IPC_STB_CONN_READY
* Return: void
*******************************************************************************/
void IPC_STB_SetIPC_STBStateType(e_IPC_STB_StateType_t state_type)
{
    IPC_STB_StateType = state_type;
}

/*******************************************************************************
* Function: IPC_STB_GetIPC_STBStateType
* Description: get IPC_STB state type
* Parameter: void
* Return: IPC_STB_NONE_INIT, IPC_STB_INIT_DONE,IPC_STB_CONN_READY
*******************************************************************************/
e_IPC_STB_StateType_t IPC_STB_GetIPC_STBStateType(void)
{
    return (IPC_STB_StateType);
}

/*******************************************************************************
* Function: IPC_STB_RecevieDataDecode
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_RecevieMessageDecode(uint8 *p_frame, uint16 frame_len)
{
    uint16 msg_len;
    
    while(frame_len>0)
    {
        msg_len = (((uint16)p_frame[0]) << 8) + (uint16)p_frame[1];

        if(frame_len >= msg_len)
        {
            /* Message frame: Two Bytes length + message data */
            IPC_STB_MessageDispatch(&p_frame[2], msg_len-2);
            frame_len = frame_len - msg_len; 
            p_frame = &p_frame[msg_len];
        }
        else
        {
            break;
        }
    }

}

/*******************************************************************************
 * Function: IPC_STB_MessageDispatch
 * Description: Dispach IPC_STB message to group module
 * Parameter: p_msg: message, msg_len:message length
 * Return: void
 ******************************************************************************/



static void IPC_STB_MessageDispatch(uint8 * p_msg, uint16 msg_len)
{
    uint8 groupid;
    uint8 major_msgid;
    uint8 sub_msgid;
    uint16 GroupListNum;
    uint16 iter;
    s_IPC_STB_CallbackRegister_t * p_callback = NULL_PTR;

    groupid = p_msg[0];
    major_msgid = p_msg[1];
    sub_msgid = p_msg[2];

    p_callback = (s_IPC_STB_CallbackRegister_t *) &IPC_STBCallbackRegisterList[0];
    GroupListNum = sizeof(IPC_STBCallbackRegisterList) / sizeof(IPC_STBCallbackRegisterList[0]);

    if ((msg_len -2) <= IPC_STB_MAX_RX_MSG_PLOAD_LENGTH)
    {
        if ((groupid & 0x7f) < GroupListNum)
        {
            /* Group id is */
            if (groupid == p_callback[groupid].group_id)
            {
                if (p_callback[groupid].p_fun != NULL_PTR)
                {
                    (*p_callback[groupid].p_fun) (major_msgid, sub_msgid, &p_msg[3], msg_len - 3);
                }
            }
            else 
            {
                for (iter = 0; iter < GroupListNum; iter++)
                {
                    if (groupid == p_callback->group_id)
                    {
                        if (p_callback->p_fun != NULL_PTR)
                        {
                            (*p_callback->p_fun) (major_msgid, sub_msgid, &p_msg[3], msg_len - 3);
                        }

                        break;
                    }

                    p_callback++;
                }
            }

        }
    }

}




/*******************************************************************************
* Function: IPC_STB_TestCallback
* Description: IPC_STB test function: receive master and send receive data to master
* Parameter: major_msg_id, sub_msg_id,* param, param_len
* Return: void
*******************************************************************************/
static uint8 send_msg[2048];

void IPC_STB_TestCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{


    if((param != NULL_PTR)&&(sizeof(send_msg)>param_len))
    {
        send_msg[0] = IPC_STB_GROUP_TEST_ID;
        send_msg[1] = major_msg_id;
        send_msg[2] = sub_msg_id;
        memcpy(&send_msg[3],param,param_len);
    }
    (void)IPC_STB_DataSend(send_msg, param_len+3,IPC_PRIORITY_LOW);
}


void IPC_STB_ServiceReceiveCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{


}

//#pragma weak SOC_Dedicated_GroupParsing
void SOC_Dedicated_GroupParsing(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
	IPC_S2M_DedicatedSocManagerHandshakeRequest_t dHandShake;
	switch(major_msg_id)
	{
		case IPC_S2M_DEDICATED_MSGMAJOR_SOCMANAGER_ID:
			IPC_STB_Deticated_SocManager(sub_msg_id,param,param_len);
			break;
		default:
			/* nothing to do */
			break;
	}
}


#if (STD_ON == IPC_STB_BUFFER_FULL_PRITF_EN)
extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void  TM_TimerStartStamp(uint32 * StartStamp);
extern void  TM_Timer1msStartStamp(uint32 * StartStamp);
/*******************************************************************************
* Function: IPC_BufferFull_Monitor
* Description: Handle IPC Buffer Full Pritf
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_BufferFullPritf_Mainfunction(void)
{
	static uint16 u16IpcFullCnt = 0;
	static boolean bIpcFullTriger = FALSE;
	uint32 curOsTimer=0;
	//
	switch(tIpcStbBuffFullStatus)
	{
		case IPC_STB_ERR_NONE:
			u16IpcFullCnt = 0 ;
			if(TRUE == bIpcFullTriger)
			{
				bIpcFullTriger = FALSE;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-STB-W]:%d ms,BufFullRelease\r\n",curOsTimer);
			}
			break;
		case IPC_STB_ERR_BUFFER_FULL:
			if(FALSE == bIpcFullTriger)
			{
				bIpcFullTriger = TRUE;
				u16IpcFullCnt = 0 ;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-STB-W]:%d ms,BufFullGenerated\r\n",curOsTimer);
			}else if(u16IpcFullCnt++ >= IPC_STB_BUFFER_FULL_PRINTF_TIME)
			{
				u16IpcFullCnt = 0 ;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-STB-W]:%d ms,BufFullAgain\r\n",curOsTimer);
			}
			break;
		default:
			/* nothing to do */
			break;
	}
}
#endif



#endif
