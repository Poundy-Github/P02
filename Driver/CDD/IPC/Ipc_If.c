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
 * @file:      Ipc_If.c
 * @author:    Nobo
 * @date:      2020-5-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file in this project/library%
 */

#include "string.h"
#include "Std_Types.h"
#include "Ipc_If.h"
#include "Ipc_Monitor.h"
#include "Ipc_Com.h"
#include "IPC_CAN.h"
#include "IPC_ClusterApp.h"
#include "logger.h"
#include "Rte_IPC.h"
#include "logger_IPC.h"
#include "SWC_IPC_Interface.h"
#include "Ipc_LoadTest.h"

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 


uint8 ipc_TxDataHighPri[IPC_DATA_HIGH_PRI_LENGTH]; /*IPC DMA High priority send data buffer.*/  
uint8 ipc_TxDataLowPri[IPC_DATA_LOW_PRI_LENGTH]; /*IPC DMA High priority send data buffer.*/  

uint16 ipc_TxDataHighPriLen;
uint16 ipc_TxDataLowPriLen;

static e_IPC_StateType_t ipc_StateType = IPC_NONE_INIT;

#if (STD_ON == IPC_BUFFER_FULL_PRITF_EN)
e_IPC_ErrorType_t tIpcBuffFullMonitorStatus = IPC_ERR_NONE;
#endif

#pragma ghs section bss = default 
#pragma ghs section data = default 
uint8 u8IPC_IF_GroupId = 0xFF;
uint8 u8IPC_IF_MajorId = 0xFF;
uint8 u8IPC_IF_SubId = 0xFF;
uint16 u16IPC_IF_Len = 0xFFFF;


static const s_IPC_CallbackRegister_t ipcCallbackRegisterList[] = IPC_APP_REGISTER_LIST;
static void IPC_MessageDispatch(uint8 *p_msg, uint16 msg_len);

/*******************************************************************************
* Function: IPC_If_Init
* Description: Handle IPC initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_If_Init(void)
{
    memset(ipc_TxDataHighPri, 0x00, IPC_DATA_HIGH_PRI_LENGTH);
    memset(ipc_TxDataLowPri, 0x00, IPC_DATA_LOW_PRI_LENGTH);
    ipc_TxDataHighPriLen = 0;
    ipc_TxDataLowPriLen = 0;

    IPC_Monitor_Init();
    IPC_Com_Init();

    ipc_StateType = IPC_INIT_DONE;
}

/*******************************************************************************
* Function: IPC_DeInit
* Description: Handle IPC deinitial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_DeInit(void)
{
    ipc_StateType = IPC_NONE_INIT;
    IPC_Monitor_DeInit();
    IPC_Com_DeInit();
}

/*******************************************************************************
* Function: IPC_DeInit
* Description: Handle IPC deinitial
* Parameter: void
* Return: void
*******************************************************************************/
static e_IPC_ErrorType_t IPC_AppendDataToBuffer(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_ErrorType_t ret = IPC_ERR_NONE;
    uint8 *p_register;
    uint16 uMsgLength;

    if( (len > IPC_MAX_TX_MSG_PLOAD_LENGTH) || (len <= IPC_TRANSPORT_OVERHEAD))
    {
        ret = IPC_ERR_PLOAD_SIZE;
    }

    if(p_msg == NULL_PTR)
    {
        ret = IPC_ERR_NO_MSG;
    }

    if((priority != IPC_PRIORITY_LOW) && (priority != IPC_PRIORITY_HIGH))
    {
        ret = IPC_ERR_PRIORITY;
    }

    if(ret == IPC_ERR_NONE)
    {
        if(priority == IPC_PRIORITY_HIGH)
        {
            /* High priority message */
            uMsgLength = len + IPC_MSG_LENGTH_LEN;
            
            IPC_ENTER_CRITICAL();
            if((uMsgLength + ipc_TxDataHighPriLen) <= IPC_DATA_HIGH_PRI_LENGTH)
            {
                p_register = &ipc_TxDataHighPri[ipc_TxDataHighPriLen];

                p_register[0] = (uint8)(uMsgLength >> 8);   /*Insert 1st byte msg_len*/
                p_register[1] = (uint8)(uMsgLength & 0xFF);    /*Insert 2st byte msg_len*/
                memcpy(&p_register[2],p_msg,len);

                ipc_TxDataHighPriLen = ipc_TxDataHighPriLen + uMsgLength;   /* Update length  */
                TST_IPC_CheckSendData(p_msg, len);
            }
            else
            {
                ret = IPC_ERR_BUFFER_FULL;
            }
            IPC_EXIT_CRITICAL();
        }
        else
        {
            /* Low priority message */
            uMsgLength = len + IPC_MSG_LENGTH_LEN;
            
            IPC_ENTER_CRITICAL();
            if((uMsgLength + ipc_TxDataLowPriLen) <= IPC_DATA_LOW_PRI_LENGTH)
            {
                p_register = &ipc_TxDataLowPri[ipc_TxDataLowPriLen];

                p_register[0] = (uint8)(uMsgLength >> 8);   /*Insert 1st byte msg_len*/
                p_register[1] = (uint8)(uMsgLength & 0xFF);    /*Insert 2st byte msg_len*/
                memcpy(&p_register[2],p_msg,len );
                ipc_TxDataLowPriLen = ipc_TxDataLowPriLen + uMsgLength;  /* Update length  */
                TST_IPC_CheckSendData(p_msg, len);
            }
            else
            {
                ret = IPC_ERR_BUFFER_FULL;
            }
            IPC_EXIT_CRITICAL();
        }
    }
	
	#if (STD_ON == IPC_BUFFER_FULL_PRITF_EN)
		tIpcBuffFullMonitorStatus = ret;
	#endif
	
    return (ret);
}

/*******************************************************************************
* Function: IPC_DeInit
* Description: Handle IPC deinitial
* Parameter: void
* Return: void
*******************************************************************************/
e_IPC_ErrorType_t IPC_DataSend(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_ErrorType_t ret = IPC_ERR_NONE;
    //uint8 *p_register;
    //uint16 uMsgLength;

    if(ipc_StateType == IPC_NONE_INIT)
    {
        ret = IPC_ERR_NINIT;
    }
    else if (ipc_StateType !=IPC_CONN_READY)
    {
        ret = IPC_ERR_NREADY;
    }
    else
    {
        ret = IPC_AppendDataToBuffer(p_msg,len,priority);
    }

    if(ret == IPC_ERR_NONE)
    {
        //check ipc idle
        if(IPC_GetIpcState()==IPC_STATE_IDLE)
        {
            IPC_TriggerMainfunction(FALSE);
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
e_IPC_ErrorType_t IPC_DataSendFormHandshake(uint8 *p_msg, uint16 len, uint8 priority)
{
    e_IPC_ErrorType_t ret = IPC_ERR_NONE;
    ///uint8 *p_register;
    //uint16 uMsgLength;

    
    if(ipc_StateType == IPC_NONE_INIT)
    {
        ret = IPC_ERR_NINIT;
    }
    else
    {
        ret = IPC_AppendDataToBuffer(p_msg,len,priority);
    }

    if(ret == IPC_ERR_NONE)
    {
        //check ipc idle
        if(IPC_GetIpcState()==IPC_STATE_IDLE)
        {
            /* Trigger IPC_MainFunction */
            IPC_TriggerMainfunction(FALSE);
        }
    }
    return (ret);
}
/*******************************************************************************
* Function: IPC_CheckDataSend
* Description: check whether have data to send
* Parameter: void
* Return: void
*******************************************************************************/
boolean IPC_CheckDataSend(void)
{
    boolean ret = FALSE;

    if((ipc_TxDataHighPriLen >IPC_MSG_HEAD_LEN) || (ipc_TxDataLowPriLen >IPC_MSG_HEAD_LEN))
    {
        /* Data buffer have data ready to send, return true */
        ret = TRUE;
    }
    return ret;
}


/*******************************************************************************
* Function: IPC_SetIPCStateType
* Description: Set IPC state type
* Parameter: IPC_NONE_INIT, IPC_INIT_DONE,IPC_CONN_READY
* Return: void
*******************************************************************************/
void IPC_SetIPCStateType(e_IPC_StateType_t state_type)
{
    ipc_StateType = state_type;
}

/*******************************************************************************
* Function: IPC_GetIPCStateType
* Description: get IPC state type
* Parameter: void
* Return: IPC_NONE_INIT, IPC_INIT_DONE,IPC_CONN_READY
*******************************************************************************/
e_IPC_StateType_t IPC_GetIPCStateType(void)
{
    return (ipc_StateType);
}

/*******************************************************************************
* Function: IPC_RecevieDataDecode
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_RecevieMessageDecode(uint8 *p_frame, uint16 frame_len)
{
    uint16 msg_len;
    
    while(frame_len>0)
    {
        msg_len = (((uint16)p_frame[0]) << 8) + (uint16)p_frame[1];

        if(frame_len >= msg_len)
        {
            /* Message frame: Two Bytes length + message data */
            IPC_MessageDispatch(&p_frame[2], (msg_len-2));
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
 * Function: IPC_MessageDispatch
 * Description: Dispach ipc message to group module
 * Parameter: p_msg: message, msg_len:message length
 * Return: void
 ******************************************************************************/



static void IPC_MessageDispatch(uint8 * p_msg, uint16 msg_len)
{
    uint8 groupid;
    uint8 major_msgid;
    uint8 sub_msgid;
    uint16 GroupListNum;
    uint16 iter;
    s_IPC_CallbackRegister_t * p_callback = NULL_PTR;

    groupid = p_msg[0];
    major_msgid = p_msg[1];
    sub_msgid = p_msg[2];

    p_callback = (s_IPC_CallbackRegister_t *) &ipcCallbackRegisterList[0];
    GroupListNum = sizeof(ipcCallbackRegisterList) / sizeof(ipcCallbackRegisterList[0]);

    if ((msg_len -2) <= IPC_MAX_RX_MSG_PLOAD_LENGTH)
    {
        if (groupid < GroupListNum)
        {
            /* Group id is */
            if (groupid == p_callback[groupid].group_id)
            {

                if (p_callback[groupid].p_fun != NULL_PTR)
                {
                    u8IPC_IF_GroupId = groupid;
                    u8IPC_IF_MajorId = major_msgid;
                    u8IPC_IF_SubId = sub_msgid;
                    u16IPC_IF_Len = msg_len - 3;
                    (*p_callback[groupid].p_fun) (major_msgid, sub_msgid, &p_msg[3], msg_len - 3);
                    u8IPC_IF_GroupId = 0xFF;
                    u8IPC_IF_MajorId = 0xFF;
                    u8IPC_IF_SubId = 0xFF;
                    u16IPC_IF_Len = 0xFFFF;
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
                            u8IPC_IF_GroupId = groupid;
                            u8IPC_IF_MajorId = major_msgid;
                            u8IPC_IF_SubId = sub_msgid;
                            u16IPC_IF_Len = msg_len - 3;
                            (*p_callback->p_fun) (major_msgid, sub_msgid, &p_msg[3], msg_len - 3);
                            u8IPC_IF_GroupId = 0xFF;
                            u8IPC_IF_MajorId = 0xFF;
                            u8IPC_IF_SubId = 0xFF;
                            u16IPC_IF_Len = 0xFFFF;
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
* Function: IPC_TestCallback
* Description: ipc test function: receive master and send receive data to master
* Parameter: major_msg_id, sub_msg_id,* param, param_len
* Return: void
*******************************************************************************/
static uint8 send_msg[2048];

void IPC_TestCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{


    if((param != NULL_PTR)&&(sizeof(send_msg)>param_len))
    {
        send_msg[0] = IPC_GROUP_TEST_ID;
        send_msg[1] = major_msg_id;
        send_msg[2] = sub_msg_id;
        memcpy(&send_msg[3],param,param_len);
    }
    IPC_DataSend(send_msg, (param_len+3),IPC_PRIORITY_LOW);
}

#if 0
void ipc_ServiceReceiveCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{


}
#endif

#if (STD_ON == IPC_BUFFER_FULL_PRITF_EN)
extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void  TM_TimerStartStamp(uint32 * StartStamp);
extern void  TM_Timer1msStartStamp(uint32 * StartStamp);
/*******************************************************************************
* Function: IPC_BufferFull_Monitor
* Description: Handle IPC Buffer Full Pritf
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_BufferFullPritf_Mainfunction(void)
{
	static uint16 u16IpcFullCnt = 0;
	static boolean bIpcFullTriger = FALSE;
	uint32 curOsTimer=0;
	//
	switch(tIpcBuffFullMonitorStatus)
	{
		case IPC_ERR_NONE:
			u16IpcFullCnt = 0 ;
			if(TRUE == bIpcFullTriger)
			{
				bIpcFullTriger = FALSE;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-W]:%d ms,BufFullRelease\r\n",curOsTimer);
			}
			break;
		case IPC_ERR_BUFFER_FULL:
			if(FALSE == bIpcFullTriger)
			{
				bIpcFullTriger = TRUE;
				u16IpcFullCnt = 0 ;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-W]:%d ms,BufFullGenerated\r\n",curOsTimer);
			}else if(u16IpcFullCnt++ >= IPC_BUFFER_FULL_PRINTF_TIME)
			{
				u16IpcFullCnt = 0 ;
				TM_Timer1msStartStamp(&curOsTimer);
				ipc_warn("[IPC-W]:%d ms,BufFullAgain\r\n",curOsTimer);
			}
			break;
		default:
			/* nothing to do */
			break;
	}
}
#endif
