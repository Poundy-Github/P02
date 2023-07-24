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
 * @file:      SOCManager_IPC_Service.c
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

#include <string.h>
#include "VariantCfg.h"

#include "SOCManager_RI.h"
#include "SOCManager_Alg.h"
#include "SOCManager_IPC_Service.h"

#include "Ipc_If.h"
#include "IPC_POWER.h" 
#include "IPC_Dedicated.h"
#ifdef PLATFORM_OF_STB_IPC_USED
#include "Ipc_STB_If.h"
#endif
// IPC_POWER SOCMANAGER SUN ID CFG
enum
{
    eIPC_SOCManager_REQ_Handshake = 0,
    eIPC_SOCManager_REQ_Heath,
    eIPC_SOCManager_REQ_Reset,
    eIPC_SOCManager_REQ_QnxCloseResponse,
    eIPC_SOCManager_REQ_QnxInfo,
    eIPC_SOCManager_REQ_QueryVer,
    eIPC_SOCManager_REQ_SOCPowerOFFReady,
    eIPC_SOCManager_REQ_Healthset,
    eIPC_SOCManager_REQ_Number,
};

#define  cIPC_Service_ReceiveList    \
{\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_ID,NULL_PTR,SOCManager_HandshakeActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEATH_ID,SOCManager_HealthRollingFrame,SOCManager_HeathActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_RESET_ID,SOCManager_ResetFrame,SOCManager_ResetActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXRESPONSEMCUREQUEST_ID,RI_SystemState_QnxCloseResponseFunc,NULL_PTR},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXINFOMCUSYSTEM_ID,SOCManager_QnxInfoMCUSystemFrame,SOCManager_QnxInfoActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXQUERYVERSION_ID,NULL_PTR,SOCManager_QueryVerActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_POWEROFFREADY_ID,NULL_PTR,SOCManager_PowerOFFReadyActivate},\
    {IPC_S2M_POWER_SOCMANAGER_MSGSUB_HEALTHSET_ID,SOCManager_HealthSet_Callback,SOCManager_HealthSet_ActivateCallback},\
}


enum  
{ 
    eIPC_SOCManager_Response_Handshake = 0,
    eIPC_SOCManager_Response_Version = 1,
    eIPC_SOCManager_Response_Heath = 2,
    eIPC_SOCManager_Response_Numner,
};

#define cIPC_Service_ResponseList       \
{\
    {eSOCManager_Response_HandshakeMask, SOCManager_Handshake_Response,},\
    {eSOCManager_Response_VersionMask  , SOCManager_Version_Response,},\
    {eSOCManager_Response_HeathMask  , SOCManager_Heath_Response,},\
}




#ifdef PLATFORM_OF_STB_IPC_USED
enum
{
    eIPC_SOCManager_STB_REQ_Handshake = 0,
    eIPC_SOCManager_STB_REQ_Heath = 1,
    eIPC_SOCManager_STB_REQ_Number,
};
#define  cIPC_Service_STB_ReceiveList    \
{\
    {IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_ID,SOCManager_STB_HandshakeCallback,SOCManager_STB_HandshakeActivate},\
    {IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_ID,NULL_PTR,SOCManager_STB_HeathActivate},\
}
enum  
{ 
    eIPC_SOCManager_STB_Response_Handshake = 0,
    eIPC_SOCManager_STB_Response_Numner,
};

#define cIPC_Service_STB_ResponseList       \
{\
    {eSOCManager_Response_STB_HandshakeMask, SOCManager_STB_Handshake_Response,},\
}
#endif






// privacy data 


// reset request define
#define SOC_REQ_RESET_SOC                   (0u)
#define SOC_REQ_RESET_SOC2MINIOS            (1u)
#define SOC_REQ_RESET_MCU                   (2u)
#define SOC_REQ_RESET_CHECKSOCMINOS         (3u)
#define SOC_REQ_RESET_DOWNLOADMOD           (4u)
#define SOC_REQ_RESET_ERR                   (0xFF)

// SOC INFO DEFINE
#define SOC_INFO_NORMAL                     (0u)
#define SOC_INFO_MINISYSTEM                 (1u)

// IPC RECEVER HANDLER
typedef struct 
{
    uint8 sub_id;
    void  (* Callback)(uint8 * param, uint16 param_len);
    void  (* ActivateCallback)(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
}sIPC_Service_ReceiveInfo_t;

typedef struct
{
    boolean bActivate;
    uint8   u8Msg;
}sIPC_Service_ReceiverHandler_t;

// IPC TRANSMIT HANDLER
typedef struct 
{
    tSOCManager_EventDef_t   mask;
    boolean (* Callback)(sSOCManagerIO_t *io);
}sIPC_Service_TransmitInfo_t;


typedef struct 
{
    boolean bRetransmit;
    uint8   u8RetransmitCnt;
}sIPC_Service_TransmitHandler_t;


typedef struct
{
    uint32                                  ReceiveMsgNumber;            
    const sIPC_Service_ReceiveInfo_t *      ReceiveConfigPtr;
    sIPC_Service_ReceiverHandler_t *        ReceiveContextPtr;
    uint32                                  TransmitMsgNumber;
    const sIPC_Service_TransmitInfo_t *     TransmitConfigPtr;
    sIPC_Service_TransmitHandler_t *        TransmitContextPtr;
}IPC_Service_Config_t;

#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void IPC_Power_SocManager(uint8 sub_msg_id, uint8 * param, uint16 param_len);
static void IPC_Power_SystemState(uint8 sub_msg_id, uint8 * param, uint16 param_len);
static void SOCManager_HandshakeActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_HeathActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_ResetFrame(uint8 * param, uint16 param_len);
static void SOCManager_HealthRollingFrame(uint8 * param, uint16 param_len);
static void SOCManager_HealthSet_Callback(uint8 * param, uint16 param_len);
static void SOCManager_HealthSet_ActivateCallback(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_QnxInfoMCUSystemFrame(uint8 * param, uint16 param_len);
static void SOCManager_ResetActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_QueryVerActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_QnxInfoActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static boolean SOCManager_Handshake_Response(sSOCManagerIO_t *io);
static boolean SOCManager_Version_Response(sSOCManagerIO_t *io);
static boolean SOCManager_Heath_Response(sSOCManagerIO_t *io);

static void SOCManager_PowerOFFReadyActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_SOCDownloadCmd(void);

#ifdef PLATFORM_OF_STB_IPC_USED
static boolean SOCManager_STB_Handshake_Response(sSOCManagerIO_t *io);
static void SOCManager_STB_HandshakeCallback(uint8 * param, uint16 param_len);
static void SOCManager_STB_HandshakeActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
static void SOCManager_STB_HeathActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg);
#endif


#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SOCManager_START_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static sIPC_Service_ReceiverHandler_t    IPC_Service_ReceiveHandler[eIPC_SOCManager_REQ_Number] = {(boolean)0,(uint8)0};
static sIPC_Service_TransmitHandler_t    IPC_Service_TransmitHandler[eIPC_SOCManager_Response_Numner] = {(boolean)0,(uint8)0};
#ifdef PLATFORM_OF_STB_IPC_USED
static sIPC_Service_ReceiverHandler_t    IPC_Service_STB_ReceiveHandler[eIPC_SOCManager_STB_REQ_Number] = {(boolean)0,(uint8)0};
static sIPC_Service_TransmitHandler_t    IPC_Service_STB_TransmitHandler[eIPC_SOCManager_STB_Response_Numner] = {(boolean)0,(uint8)0};
#endif

#define SOCManager_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SOCManager_START_SEC_CONST_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const sIPC_Service_ReceiveInfo_t  IPC_Service_RecevieInfo[eIPC_SOCManager_REQ_Number] = cIPC_Service_ReceiveList;
static const sIPC_Service_TransmitInfo_t IPC_Service_TransmitInfo[eIPC_SOCManager_Response_Numner] = cIPC_Service_ResponseList;
#ifdef PLATFORM_OF_STB_IPC_USED
static const sIPC_Service_ReceiveInfo_t  IPC_Service_STB_RecevieInfo[eIPC_SOCManager_STB_REQ_Number] = cIPC_Service_STB_ReceiveList;
static const sIPC_Service_TransmitInfo_t IPC_Service_STB_TransmitInfo[eIPC_SOCManager_STB_Response_Numner] = cIPC_Service_STB_ResponseList;
#endif
uint8 SOCM_SocReq_Reason = 0;

static const IPC_Service_Config_t IPC_Service_Handler = 
{
    eIPC_SOCManager_REQ_Number,
    IPC_Service_RecevieInfo,
    IPC_Service_ReceiveHandler,
    eIPC_SOCManager_Response_Numner,
    IPC_Service_TransmitInfo,
    IPC_Service_TransmitHandler,
};

#ifdef PLATFORM_OF_STB_IPC_USED
static const IPC_Service_Config_t IPC_Service_STB_Handler = 
{
    eIPC_SOCManager_STB_REQ_Number,
    IPC_Service_STB_RecevieInfo,
    IPC_Service_STB_ReceiveHandler,
    eIPC_SOCManager_STB_Response_Numner,
    IPC_Service_STB_TransmitInfo,
    IPC_Service_STB_TransmitHandler,
};
#endif

#define SOCManager_STOP_SEC_CONST_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_IPC_Service_Init(void)
{
    memset(IPC_Service_ReceiveHandler,0,sizeof(IPC_Service_ReceiveHandler));
    memset(IPC_Service_TransmitHandler,0,sizeof(IPC_Service_TransmitHandler));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOC_PowerGroupParsing(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    switch(major_msg_id)
    {
        case IPC_S2M_POWER_MSGMAJOR_SOCMANAGER_ID:
            IPC_Power_SocManager(sub_msg_id,param,param_len);
            break;
        case IPC_S2M_POWER_MSGMAJOR_SYSTEMSTATE_ID:
            IPC_Power_SystemState(sub_msg_id,param,param_len);
            break;
        default:
            /*do nothing*/
            break;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void IPC_Power_SocManager(uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    if (sub_msg_id < IPC_Service_Handler.ReceiveMsgNumber)
    {
        
        if (IPC_Service_Handler.ReceiveConfigPtr[sub_msg_id].Callback != NULL_PTR)
        {
            IPC_Service_Handler.ReceiveConfigPtr[sub_msg_id].Callback(param,param_len);
        }
        
        if (NULL_PTR == IPC_Service_Handler.ReceiveConfigPtr[sub_msg_id].ActivateCallback)
        {
            socmanager_warn("ipc power external trigger %d!",sub_msg_id);
        }
        else
        {
            IPC_Service_Handler.ReceiveContextPtr[sub_msg_id].bActivate = TRUE;
        }
    }
    else
    {
        socmanager_warn("ipc power sub id %d is undefine.",sub_msg_id);
    }
    
}

#ifdef PLATFORM_OF_STB_IPC_USED
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void IPC_STB_Deticated_SocManager(uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    if (sub_msg_id < IPC_Service_STB_Handler.ReceiveMsgNumber)
    {
        
        if (IPC_Service_STB_Handler.ReceiveConfigPtr[sub_msg_id].Callback != NULL_PTR)
        {
            IPC_Service_STB_Handler.ReceiveConfigPtr[sub_msg_id].Callback(param,param_len);
        }
        
        if (NULL_PTR == IPC_Service_STB_Handler.ReceiveConfigPtr[sub_msg_id].ActivateCallback)
        {
            socmanager_warn("ipc STB dedicated external trigger %d!",sub_msg_id);
        }
        else
        {
            IPC_Service_STB_Handler.ReceiveContextPtr[sub_msg_id].bActivate = TRUE;
        }
    }
    else
    {
        socmanager_warn("ipc STB dedicated sub id %d is undefine.",sub_msg_id);
    }
    
}


#endif

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void IPC_Power_SystemState(uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    switch(sub_msg_id)
    {
        case IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_ID:
            RI_SystemState_IVINOForceResponseFunc(param,param_len);
            break;
        case IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_FOTASTS_ID:
            RI_SystemState_FOTAStsFunc(param,param_len);
            break;
        case IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_GETSMSTS_ID:
            RI_SystemState_GetFunc(param,param_len);
            break;
        case IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_APP_INFOSM_ID:
			RI_SystemState_APP_INFOSM(param,param_len);
        	break;
        default:
            /*do nothing*/
            break;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_ScanIPCMsg(sSOCManagerIO_t *io)
{
    uint8 i;

    for (i=0;i<IPC_Service_Handler.ReceiveMsgNumber;i++)
    {
        if (TRUE == IPC_Service_Handler.ReceiveContextPtr[i].bActivate)
        {
           socmanager_Verbose("IPC_POWER SOCManager Req (%d) activate.",i);
           if (NULL_PTR != IPC_Service_Handler.ReceiveConfigPtr[i].ActivateCallback) 
           {
               IPC_Service_Handler.ReceiveConfigPtr[i].ActivateCallback(io,i,IPC_Service_Handler.ReceiveContextPtr[i].u8Msg);
           }
           IPC_Service_Handler.ReceiveContextPtr[i].bActivate = FALSE;
           
        }
    }


#ifdef PLATFORM_OF_STB_IPC_USED
    for (i=0;i<IPC_Service_STB_Handler.ReceiveMsgNumber;i++)
    {
        if (TRUE == IPC_Service_STB_Handler.ReceiveContextPtr[i].bActivate)
        {
           socmanager_Verbose("IPC_STB_DEDICATE SOCManager Req (%d) activate.",i);
		   //
           if (NULL_PTR != IPC_Service_STB_Handler.ReceiveConfigPtr[i].ActivateCallback) 
           {
               IPC_Service_STB_Handler.ReceiveConfigPtr[i].ActivateCallback(io,i,IPC_Service_STB_Handler.ReceiveContextPtr[i].u8Msg);
           }
		   //
           IPC_Service_STB_Handler.ReceiveContextPtr[i].bActivate = FALSE;   
        }
    }
#endif
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_HandshakeActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    io->tSocReqMask |= eSOCManager_SocReqDef_HandshakeMask;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_HeathActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    io->tSocReqMask |= eSOCManager_SocReqDef_HeathMask;
    
}


#ifdef PLATFORM_OF_STB_IPC_USED
static boolean bSTBHandshakeTrriger = FALSE;
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_STB_HandshakeCallback(uint8 * param, uint16 param_len)
{
	if(IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH == param_len)
	{
		if((param[0]+param[1]+param[2]+param[3]) == 0)
		{
			bSTBHandshakeTrriger = TRUE;
		}
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_STB_HandshakeActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
	if(TRUE == bSTBHandshakeTrriger)
	{
	    io->tSocSTBReqMask |= eSOCManager_SocReqDef_STB_HandshakeMask;
		socmanager_info("[IPC_STB]:HandshakeActivate\r\n");
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_STB_HeathActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    io->tSocSTBReqMask |= eSOCManager_SocReqDef_STB_HeathMask;
}

#endif

static void SOCManager_HealthRollingFrame(uint8 * param, uint16 param_len)
{
	IPC_S2M_POWERSocManagerHeath_t data = {0};
	RI_POWERSocManagerHeath_Receive(param,&data,param_len);
	IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_Heath].u8Msg = data.u8Reserved;
	
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 * @note        :
 *                  u8Parameter  u8Describe  function 
 *                  0            0           reset mcu
 *                  0            3           reset mcu
 *                  1            0           reset to minisystem
 *                  1            1           reset soc
 *                  1            2           reset to minisystem
 ***********************************************************************/
static void SOCManager_ResetFrame(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSocManagerReset_t data ={0};
    uint8 msg = SOC_REQ_RESET_ERR;

    RI_POWERSocManagerReset_Receive(param,&data,param_len);

    if (data.u8Parameter == 0u)
    {
        msg = SOC_REQ_RESET_MCU;
    }
    else if (data.u8Parameter == 1u)
    {
        if (data.u8Describe == 0u)
        {
            msg = SOC_REQ_RESET_SOC2MINIOS;
        }
        else if (data.u8Describe == 1u)
        {
            msg = SOC_REQ_RESET_SOC;
        }
        else if (data.u8Describe == 2u)
        {
            msg = SOC_REQ_RESET_CHECKSOCMINOS;
        }
        else if (data.u8Describe == 4u)
        {
            msg = SOC_REQ_RESET_DOWNLOADMOD;
        }
    }
      else if(data.u8Describe == 2u)
    {
		msg = SOC_REQ_RESET_SOC;
		SOCM_SocReq_Reason = data.u8Parameter;
    }

    IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_Reset].u8Msg = msg;

    if (msg == SOC_REQ_RESET_ERR)
    {
        socmanager_warn("SOC reset request param error , u8Parameter(%d),u8Describe(%d)!",data.u8Parameter,data.u8Describe);
    }
    else
    {
        socmanager_debug("SOC reset request param : u8Parameter(%d),u8Describe(%d)!",data.u8Parameter,data.u8Describe);
    }
    
}

static void SOCManager_HealthSet_Callback(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSocManagerHealthset_t data ={0};
    uint8 msg = SOC_INFO_HANDSHAKE_TIMEOUT_RESET_OFF;

	RI_POWERSocManagerHealthSet_Receive(param,&data,param_len);

	if(data.u8Reserved == SOC_INFO_HANDSHAKE_TIMEOUT_RESET_ON)
	{
		msg = SOC_INFO_HANDSHAKE_TIMEOUT_RESET_ON;
	}
	
    IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_Healthset].u8Msg = msg;
	
    socmanager_warn("Event , Record , SOC request param : HealthSet = %d ",data.u8Reserved);
}

static void SOCManager_HealthSet_ActivateCallback(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
	io->tSocReqMask |= eSOCManager_SocReqDef_HealthSetMask;
	io->bHandShakeTimeoutRestFlag = Msg;
    socmanager_warn("Event , Mask , io->bHandShakeTimeoutRestFlag = %d ",io->bHandShakeTimeoutRestFlag);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_QnxInfoMCUSystemFrame(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSocManagerQnxInfoMCUSystem_t data ={0};
    uint8 msg = 0;

    RI_QnxInfoMCUSystem_Receive(param,&data,param_len);

    msg = data.u8Parameter;
    IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_QnxInfo].u8Msg = msg;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_ResetActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    switch(Msg)
    {
        case SOC_REQ_RESET_MCU:
            io->tSocReqMask |= eSOCManager_SocReqDef_ResetMCUMask;
            socmanager_warn("SOC req mcu reset.");
            break;
        case SOC_REQ_RESET_SOC2MINIOS:
            io->tSocReqMask |= eSOCManager_SocReqDef_ResetSoc2MiniSysMask;
            socmanager_warn("SOC req mcu reset to minisys.");
            break;
        case SOC_REQ_RESET_SOC:
            io->tSocReqMask |= eSOCManager_SocReqDef_ResetSocMask;
            socmanager_warn("SOC req mcu reset soc.");
            break;
        case SOC_REQ_RESET_CHECKSOCMINOS:
            io->tSocReqMask |= eSOCManager_SocReqDef_ResetCheckSocMiniOSMask;
            break;
        case SOC_REQ_RESET_DOWNLOADMOD:
            io->tSocReqMask |= eSOCManager_SocReqDef_DownloadMask;
            socmanager_warn("SOC req Download mode.");
            break;
        default:
        
            /*do nothing*/
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_QnxInfoActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    if (Msg == SOC_INFO_MINISYSTEM)
    {
        io->tSocReqMask |= eSOCManager_SocReqDef_SystemErrorMask;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_QueryVerActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    io->tSocReqMask |= eSOCManager_SocReqDef_QueryVerMask;
}
/***********************************************************************
 * @brief       : V35-48517
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_PowerOFFReadyActivate(sSOCManagerIO_t *io, uint8 id,uint8 Msg)
{
    io->tSocReqMask |= eSOCManager_SocReqDef_PowerOFFReadyMask;
    socmanager_warn("Power OFF Ready Activate.");
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Handshake_Response(sSOCManagerIO_t *io)
{
    boolean ret = TRUE;
    e_IPC_ErrorType_t ret_ipc = IPC_ERR_NONE;
    uint8_t payload[IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD];

    payload[0] = IPC_GROUP_POWER_ID;
    payload[1] = IPC_M2S_POWER_MSGMAJOR_SOCMANAGER_ID;
    payload[2] = IPC_M2S_POWER_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID;
    payload[3] = 0;
    payload[4] = 0;
    payload[5] = 0;
    payload[6] = 0;

    socmanager_warn("Send Handshake response.");

    ret_ipc = RI_DataSendFormHandshake(payload,
            IPC_S2M_POWER_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH + IPC_TRANSPORT_OVERHEAD, IPC_PRIORITY_HIGH);
    if (IPC_ERR_NONE == ret_ipc)
    {
        RI_SetIPCStateType(IPC_CONN_READY);
    }
    else
    {
        socmanager_warn("Send Handshake response error,because ipc return %d",ret_ipc);
    }
    
    if (IPC_ERR_BUFFER_FULL == ret_ipc)
    {
        ret = FALSE;
    }

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
 
#ifdef PLATFORM_OF_STB_IPC_USED
static boolean SOCManager_STB_Handshake_Response(sSOCManagerIO_t *io)
{
    boolean ret = TRUE;
    e_IPC_STB_ErrorType_t ret_STB_ipc = IPC_STB_ERR_NONE;
    uint8_t para[IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH];

    para[0] = 0;
    para[1] = 0;
    para[2] = 0;
    para[3] = 0;

    socmanager_warn("Send STB Handshake response\r\n");

    ret_STB_ipc = RI_STB_DataSendFormHandshake(para);
    if (IPC_STB_ERR_NONE == ret_STB_ipc)
    {
        RI_STB_SetIPCStateType(IPC_STB_CONN_READY);
		socmanager_info("[IPC_STB]:Ack HandShake Normal\r\n");
    }
    else
    {
        socmanager_err("[IPC_STB]:Ack HandShake Error, %d\r\n",ret_STB_ipc);
    }
    
    if (IPC_STB_ERR_BUFFER_FULL == ret_STB_ipc)
    {
        ret = FALSE;
    }

    return ret;
}
#endif

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/

static boolean SOCManager_Version_Response(sSOCManagerIO_t *io)
{
    boolean ret = TRUE;

    int32_t ret_ipc = (int32_t)IPC_ERR_NONE;
    IPC_M2S_POWERSocManagerVersion_t POWERSocManagerVersion;

    POWERSocManagerVersion.HwVersion = io->u8HwVersion;
    ret_ipc = RI_POWERSocManagerVersion_Transmit(&POWERSocManagerVersion);
    if (IPC_ERR_NONE == ret_ipc)
    {
        socmanager_warn("Send Hw Version(%d) to SOC.",POWERSocManagerVersion.HwVersion);
    }
    else
    {
        socmanager_warn("Send Hw Version to SOC error,because ipc return %d",ret_ipc);
    }

    if (IPC_ERR_BUFFER_FULL == ret_ipc)
    {
        ret = FALSE;
    }
    return ret;
}

uint8 SOCManager_HeathMsg_Get(void)
{
	return IPC_Service_ReceiveHandler[eIPC_SOCManager_REQ_Heath].u8Msg;
}

static boolean SOCManager_Heath_Response(sSOCManagerIO_t *io)
{
    boolean ret = TRUE;

    int32_t ret_ipc = (int32_t)IPC_ERR_NONE;
    IPC_M2S_POWERSocManagerHeathResponse_t POWERSocManagerHeathresp;

    POWERSocManagerHeathresp.u8Reserved = io->u8heathResp;
    ret_ipc = IPC_M2S_POWERSocManagerHeathResponse_Transmit(&POWERSocManagerHeathresp);

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_IPCResponse(sSOCManagerIO_t *io)
{
    uint8 i;
    boolean ret;
    const sIPC_Service_TransmitInfo_t *      ConfigPtr  = IPC_Service_Handler.TransmitConfigPtr;
    sIPC_Service_TransmitHandler_t *         ContextPtr = IPC_Service_Handler.TransmitContextPtr;
    
    for (i=0u; i<IPC_Service_Handler.TransmitMsgNumber; i++)
    {
        if (io->tResponse & ConfigPtr[i].mask)
        {
            ContextPtr[i].bRetransmit = FALSE;
            ContextPtr[i].u8RetransmitCnt = 0u;            
        }
        if ((boolean)(io->tResponse & ConfigPtr[i].mask) || (ContextPtr[i].bRetransmit))
        {
            socmanager_Verbose("Response state star id(%d) retransmit(%d) cnt(%d)",i,ContextPtr[i].bRetransmit,ContextPtr[i].u8RetransmitCnt);
            if (ConfigPtr[i].Callback != NULL_PTR)
            {
                ret = ConfigPtr[i].Callback(io);
                
                if (TRUE != ret)
                {
                    ContextPtr[i].bRetransmit = TRUE;
                    ContextPtr[i].u8RetransmitCnt++;
                }
                else
                {
                    ContextPtr[i].bRetransmit = FALSE;
                    ContextPtr[i].u8RetransmitCnt = 0u; 
                }
            }
            socmanager_Verbose("Response state end id(%d) retransmit(%d) cnt(%d)",i,ContextPtr[i].bRetransmit,ContextPtr[i].u8RetransmitCnt);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_SOCDownloadCmd(void)
{
    IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_Reset].u8Msg = SOC_REQ_RESET_DOWNLOADMOD;
    IPC_Service_Handler.ReceiveContextPtr[eIPC_SOCManager_REQ_Reset].bActivate = TRUE;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
#ifdef PLATFORM_OF_STB_IPC_USED
void SOCManager_STBIPCResponse(sSOCManagerIO_t *io)
{
    uint8 i;
    boolean ret;
    const sIPC_Service_TransmitInfo_t *      ConfigPtr  = IPC_Service_STB_Handler.TransmitConfigPtr;
    sIPC_Service_TransmitHandler_t *         ContextPtr = IPC_Service_STB_Handler.TransmitContextPtr;
    
    for (i=0u; i<IPC_Service_STB_Handler.TransmitMsgNumber; i++)
    {
        if (io->tSTBResponse & ConfigPtr[i].mask)
        {
            ContextPtr[i].bRetransmit = FALSE;
            ContextPtr[i].u8RetransmitCnt = 0u;            
        }
        
        if ((io->tSTBResponse & ConfigPtr[i].mask) || (ContextPtr[i].bRetransmit))
        {
            socmanager_Verbose("Response STB state star id(%d) retransmit(%d) cnt(%d)",i,ContextPtr[i].bRetransmit,ContextPtr[i].u8RetransmitCnt);
            if (ConfigPtr[i].Callback != NULL_PTR)
            {
                ret = ConfigPtr[i].Callback(io);
                
                if (TRUE != ret)
                {
                    ContextPtr[i].bRetransmit = TRUE;
                    ContextPtr[i].u8RetransmitCnt++;
                }
                else
                {
                    ContextPtr[i].bRetransmit = FALSE;
                    ContextPtr[i].u8RetransmitCnt = 0u; 
                }
            }
            socmanager_Verbose("Response STB state end id(%d) retransmit(%d) cnt(%d)",i,ContextPtr[i].bRetransmit,ContextPtr[i].u8RetransmitCnt);
        }
    }
}
#endif
#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


