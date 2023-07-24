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
 * @file:      logger_IPC.c
 * @author:    Nobo
 * @date:      2020-8-4
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-4
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/* Include definitions  */
#include "Rte_Log.h"


#include <string.h>
#include <stdio.h>
#include "IPC_If.h"
#include "IPC_Log.h"
#include "logger.h"



/* Macro definitions */
#define LOGGER_IPC_BUFFER_SUCCESS           (0x00)
#define LOGGER_IPC_BUFFER_FULL              (0x01)
#define LOGGER_IPC_BUFFER_EMPTY             (0x02)
#define LOGGER_IPC_BUFFER_UNKNOWN           (0x03)


#if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

typedef uint8 IpcPackState_t;
#define LOGGER_IPC_PACK_BEGIN       	(0)
#define LOGGER_IPC_PACK_HEADER      	(2)
#define LOGGER_IPC_PACK_LEN_ERR         (3)
#define LOGGER_IPC_PACK_DATA        	(4)
#define LOGGER_IPC_PACK_OK          	(5)
#define LOGGER_IPC_PACK_ILDE        	(6)


typedef uint8 IpcPackRet_t;
#define LOGGER_PACK_RET_OK  (0)
#define LOGGER_PACK_RET_ERR  (1)
#define LOGGER_PACK_RET_ERR0  (2)

#endif

/* type definitions */
typedef struct 
{
    boolean         bSendFlg;
    IPC_M2S_LogDefaultLog_t Message;
} Logger_IPC_TransmitBuffer_t;

static boolean bIpcIsReady = FALSE;
static Logger_IPC_TransmitBuffer_t Logger_IPC_TransmitBuffer;

static void IPC_Log_SetLogLevelCallback(uint8 * param, uint16 param_len);
static uint8 Logger_IPC_Transmit(void);

#if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

static IpcPackRet_t Logger_GetIpcPakage(uint8* data);

#endif



void Logger_IPC_Init(void)
{
    bIpcIsReady = FALSE;
    memset(&Logger_IPC_TransmitBuffer, 0, sizeof(Logger_IPC_TransmitBuffer_t));
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void IPC_Log_Callback(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    if ((major_msg_id == IPC_S2M_LOG_MSGMAJOR_DEFAULT_ID) &&
         (sub_msg_id == IPC_S2M_LOG_DEFAULT_MSGSUB_SETLOGLEVEL_ID))
    {
        bIpcIsReady = TRUE;
        IPC_Log_SetLogLevelCallback(param, param_len);
    }

}





/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void IPC_Log_SetLogLevelCallback(uint8 * param, uint16 param_len)
{
    IPC_S2M_LogDefaultSetLogLevel_t data;
    uint8 mode_id;
    Logger_Return_t ret = LOGGER_ERROR;

    IPC_S2M_LogDefaultSetLogLevel_Receive(param, &data, param_len);

    
    if (strncmp("ALL", data.Id, strlen("ALL")) == 0)
    {
        Logger_LevelSetAll(data.level);
    }
    else 
    {
        mode_id = (uint8) (-1);
        ret = Logger_GetModeId(data.Id, &mode_id);

        if (ret == LOGGER_SUCCESS)
        {
            Logger_LevelSet(mode_id, data.level);
        }

    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Logger_IPC_Task(void)
{

    uint8  cnt=0;


    while (Logger_IPC_Transmit() == LOGGER_IPC_BUFFER_SUCCESS)
    {
        cnt++;
        if (cnt >= 10)
        {
            break;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/


#if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

IpcPackRet_t g_ret = LOGGER_PACK_RET_ERR;
static IpcPackRet_t Logger_GetIpcPakage(uint8* data)
{
    IpcPackRet_t ret = LOGGER_PACK_RET_ERR;
	uint8 temdata = 0;
    uint32 rb_len = 0;
    uint8 len = 0;
    IpcPackState_t pack_state = LOGGER_IPC_PACK_ILDE;

    LOGGER_ENTER_CRITICAL();
	
	while(1)
	{
		rb_len = RB_NumberGet(logger_cfg.rbIpc);
			
        if(rb_len == 0)
        {
            if(LOGGER_IPC_PACK_OK != pack_state)
            {
                ret = LOGGER_PACK_RET_ERR;
                pack_state = LOGGER_IPC_PACK_ILDE; 
            }
            break;
        }

		
 
		switch(pack_state)
		{
            case LOGGER_IPC_PACK_ILDE:
            {
           		 RB_Pop(logger_cfg.rbIpc, &temdata, 1);
                if(0xa5 == temdata)
                {
                    *(data++) = temdata;
                    pack_state = LOGGER_IPC_PACK_HEADER;
                }
                break;
            }
            case LOGGER_IPC_PACK_HEADER:
            {
            	RB_Pop(logger_cfg.rbIpc, &temdata, 1);
                if(0xa5 == temdata)
                {
                    *(data++) = temdata;
                    pack_state = LOGGER_IPC_PACK_BEGIN;
                }
                break;
            }
            case LOGGER_IPC_PACK_BEGIN:
            {
            	RB_Pop(logger_cfg.rbIpc, &temdata, 1);
                *(data++) = temdata;
                len = temdata + 10;
                pack_state = LOGGER_IPC_PACK_DATA;
                break;
            }
            case LOGGER_IPC_PACK_DATA:
            {
            	if(rb_len >= len)
        		{
					RB_Pop(logger_cfg.rbIpc, data, len);
                    ret = LOGGER_PACK_RET_OK;
					pack_state = LOGGER_IPC_PACK_OK;
        		} 
				else
				{
					/* pop remain data */
					RB_Pop(logger_cfg.rbIpc, data, rb_len);
					pack_state = LOGGER_IPC_PACK_LEN_ERR;
                    ret = LOGGER_PACK_RET_ERR;
				}
                
                break;
            }
            default:
            {
                pack_state = LOGGER_IPC_PACK_ILDE;
            }
		}
		
        if(LOGGER_IPC_PACK_OK == pack_state || LOGGER_IPC_PACK_LEN_ERR == pack_state)
        {
            pack_state = LOGGER_IPC_PACK_ILDE;
            break;
        }
	}

    LOGGER_EXIT_CRITICAL();

    return ret;
}
#endif


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 Logger_IPC_Transmit(void)
{
    int32_t ret;
    RB_Return_t rbDataLen;
    #if (LOGGER_IPC_BUFFER_FIT_DATA == 1)
    Ipc_Data_t data;
    #else
    Ipc_Data_t data ={0};
    #endif
    uint8 result = LOGGER_IPC_BUFFER_UNKNOWN;

    if (bIpcIsReady == FALSE)
    {
        ;
    }
    else if (Logger_IPC_TransmitBuffer.bSendFlg == TRUE)
    {
        // send buffer data 
        ret = IPC_M2S_LogDefaultLog_Transmit(&Logger_IPC_TransmitBuffer.Message);
        
        if (IPC_ERR_BUFFER_FULL != ret)
        {
            Logger_IPC_TransmitBuffer.bSendFlg = FALSE;
            result = LOGGER_IPC_BUFFER_SUCCESS;
        }
        else
        {
             result = LOGGER_IPC_BUFFER_FULL;
        }
    }
    else 
    {

#if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

        ret = Logger_GetIpcPakage((uint8 *)&data);

		if(LOGGER_PACK_RET_OK == ret)
        {
            // init send buffer;
            uint64 utc_time = Logger_IPC_TransmitBuffer.Message.timestamp;
            memset(&Logger_IPC_TransmitBuffer, 0, sizeof(Logger_IPC_TransmitBuffer_t));

            Logger_IPC_TransmitBuffer.Message.payloadLength = data.length;

            if (Logger_IPC_TransmitBuffer.Message.payloadLength > LOGGER_DATA_SIZE)
            {
                Logger_IPC_TransmitBuffer.Message.payloadLength = LOGGER_DATA_SIZE;
            }

            memcpy(Logger_IPC_TransmitBuffer.Message.Id, logger_cfg.subNames[data.mdlID],
                 strlen(logger_cfg.subNames[data.mdlID]));
                 
            Logger_IPC_TransmitBuffer.Message.level = data.level;

            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,7) = data.timestamp[0];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,6) = data.timestamp[1];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,5) = data.timestamp[2];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,4) = data.timestamp[3];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,3) = data.timestamp[4];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,2) = data.timestamp[5];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,1) = data.timestamp[6];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,0) = data.timestamp[7];

            memcpy(Logger_IPC_TransmitBuffer.Message.payload, data.buffer,
                 Logger_IPC_TransmitBuffer.Message.payloadLength);

            Logger_IPC_TransmitBuffer.Message.payload[99] = 0;

            ret = IPC_M2S_LogDefaultLog_Transmit(&Logger_IPC_TransmitBuffer.Message);

            if (IPC_ERR_BUFFER_FULL == ret)
            {
                Logger_IPC_TransmitBuffer.bSendFlg = TRUE;
                result = LOGGER_IPC_BUFFER_FULL;
            }
            else
            {
                result = LOGGER_IPC_BUFFER_SUCCESS;
            }
            
        }        
        else
        {
            result = LOGGER_IPC_BUFFER_EMPTY;
        }

#else

        LOGGER_ENTER_CRITICAL();
        rbDataLen = RB_Pop(logger_cfg.rbIpc, &data, data.length);
        LOGGER_EXIT_CRITICAL();


        if (rbDataLen > 0)
        {
            // init send buffer;
            uint64 utc_time = Logger_IPC_TransmitBuffer.Message.timestamp;
            memset(&Logger_IPC_TransmitBuffer, 0, sizeof(Logger_IPC_TransmitBuffer_t));

            Logger_IPC_TransmitBuffer.Message.payloadLength = strlen(data.buffer);

            if (Logger_IPC_TransmitBuffer.Message.payloadLength > LOGGER_DATA_SIZE)
            {
                Logger_IPC_TransmitBuffer.Message.payloadLength = LOGGER_DATA_SIZE;
            }

            memcpy(Logger_IPC_TransmitBuffer.Message.Id, logger_cfg.subNames[data.mdlID],
                 strlen(logger_cfg.subNames[data.mdlID]));
                 
            Logger_IPC_TransmitBuffer.Message.level = data.level;
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,7) = data.timestamp[0];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,6) = data.timestamp[1];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,5) = data.timestamp[2];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,4) = data.timestamp[3];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,3) = data.timestamp[4];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,2) = data.timestamp[5];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,1) = data.timestamp[6];
            IPC_GET_BYTE(Logger_IPC_TransmitBuffer.Message.timestamp,0) = data.timestamp[7];

            memcpy(Logger_IPC_TransmitBuffer.Message.payload, data.buffer,
                 Logger_IPC_TransmitBuffer.Message.payloadLength);

            Logger_IPC_TransmitBuffer.Message.payload[99] = 0;

            ret = IPC_M2S_LogDefaultLog_Transmit(&Logger_IPC_TransmitBuffer.Message);

            if (IPC_ERR_BUFFER_FULL == ret)
            {
                Logger_IPC_TransmitBuffer.bSendFlg = TRUE;
                result = LOGGER_IPC_BUFFER_FULL;
            }
            else
            {
                result = LOGGER_IPC_BUFFER_SUCCESS;
            }
        }
        else
        {
            result = LOGGER_IPC_BUFFER_EMPTY;
        }
#endif

    }
    return result;
}





/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Logger_IPC_SetReadyStatus(boolean status)
{
    bIpcIsReady = status;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean Logger_IPC_ReadReadyStatus(void)
{
    return bIpcIsReady;
}



