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
 * @file:      Misc_IPC_Service.c
 * @author:    Nobo
 * @date:      2020-8-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

// include 
#include "Rte_Misc.h"
#include "Dio.h"

#include "IPC_Misc.h"
#include "logger.h"

// config / info
#define DIO_MAPPING_NUM                     (8u)
#define NUMBER_OF_FILTER                    (10u)


#define TRIGGER_MAS_TUNER_DEBUG             (0)
#define TRIGGER_MAS_CHANNEL_MAX             (1)


// Trigger service type define
typedef struct
{
    const Dio_ChannelType ChannelId;
    boolean bIsInit;       
    boolean bTrigger;           
    Dio_PortLevelType Value;
    uint8 cnt;
}Misc_DioTriggerInfo_t;




#define Misc_START_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 Get_Vconfig_Flag;
extern uint8 Vconfig_Response_Flag;

extern uint8 Get_Cconfig_Flag;
extern uint8 Cconfig_Response_Flag;

extern uint8 Usb_Update_Request_Flag;
extern uint8 Usb_Updata_Data[200];

uint8 Get_OffSet_Flag = (uint8)FALSE;

static Misc_DioTriggerInfo_t Misc_DioTriggerInfo_Table[TRIGGER_MAS_CHANNEL_MAX] = 
{
    {DioConf_DioChannel_Tuner_VIP_debug1,FALSE,FALSE,DIO_LOW_LEVEL_OUTPUT,0},
};

#define Misc_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Misc_START_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


static const Dio_ChannelType DIoMapping[DIO_MAPPING_NUM] = 
{
    DioConf_DioChannel_VIP_ID_EN_ODH,
    DioConf_DioChannel_VIP_CD_EN_ODH,
    DioConf_DioChannel_VIP_PD_EN_ODH,
    DioConf_DioChannel_VIP_469X_RST_3V3,
    DioConf_DioChannel_VIP_47961_RST_3V3,
    DioConf_DioChannel_VIP_479XX_RST_3V3,
    DioConf_DioChannel_VIP_4624_RST_3V3,
    DioConf_DioChannel_VIP_HD_EN_ODH,
};

#define Misc_STOP_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


static void MISC_IPC_Service_CheckTrigger(void);
static void MISC_IPC_Service_TriggerOutput(void);
static void MISC_IPC_Service_SetTrigger(uint8 TriggerSource);


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_IPC_Service_Callback(uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    switch (sub_msg_id)
    {
        case IPC_S2M_MISC_SERVICE_MSGSUB_WIRTCHANNEL_ID:
            {
                IPC_S2M_MiscServiceWirtChannel_t data;
                IPC_M2S_MiscServiceReply_t Reply;

                IPC_S2M_MiscServiceWirtChannel_Receive(param, &data, param_len);

                if (data.u8Channel < DIO_MAPPING_NUM)
                {
                    Reply.u8Channel = data.u8Channel;
                    Dio_WriteChannel(DIoMapping[data.u8Channel], data.u8Level);
					misc_warn("SOC Operate Display Enable :ch=%d,st=%d",data.u8Channel,data.u8Level);
					
                    IPC_M2S_MiscServiceReply_Transmit(&Reply);
                }
            }
            break;

        case IPC_S2M_MISC_SERVICE_MSGSUB_GET_VCONFIG_ID:
            {
                uint8 data = FALSE;

                IPC_S2M_MiscServiceGet_Vconfig_Receive(param, &data, param_len);

                if (data == TRUE)
                {
                    Get_Vconfig_Flag = TRUE;
                }
            }
            break;

        case IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_REPONSE_ID:
            {
                uint8 data = FALSE;

                IPC_S2M_MiscServiceVconfig_Reponse_Receive(param, &data, param_len);

                if (data == TRUE)
                {
                    Vconfig_Response_Flag = TRUE;
                }
            }
            break;
        case IPC_S2M_MISC_SERVICE_MSGSUB_CHECKTRIGGERMSG_ID:
            {
                IPC_S2M_MiscServiceCheckTriggerMsg_t data;
                IPC_S2M_MiscServiceCheckTriggerMsg_Receive(param,&data,param_len);
                MISC_IPC_Service_SetTrigger(data.TriggerSource);
            }
            break;
				
		case IPC_S2M_MISC_SERVICE_MSGSUB_CCONFIG_RESPONSE_ID:
            {
                uint8 data = FALSE;

                IPC_S2M_MiscServiceCconfig_Response_Receive(param, &data, param_len);

                if (data == TRUE)
                {
                    Cconfig_Response_Flag = TRUE;
                }
            }
            break;
				
		case IPC_S2M_MISC_SERVICE_MSGSUB_VCONFIG_USB_ID:
            {
				
                IPC_S2M_MiscServiceVconfig_Usb_Receive(param, &Usb_Updata_Data, param_len);
				Usb_Update_Request_Flag = TRUE;
            }
            break;
				
		case IPC_S2M_MISC_SERVICE_MSGSUB_GET_CCONFIG_ID:
            {
				uint8 data = FALSE;

                IPC_S2M_MiscServiceGet_Cconfig_Receive(param, &data, param_len);

                if (data == TRUE)
                {
                    Get_Cconfig_Flag = TRUE;
                }
                
            }
            break;

        case IPC_S2M_MISC_SERVICE_MSGSUB_GET_OFFSET_ID:
            {
				uint8 data = FALSE;

                IPC_S2M_MiscServiceGet_Offset_Receive(param, &data, param_len);

                if (data == TRUE)
                {
                    Get_OffSet_Flag = TRUE;
                }
                
            }
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
void MISC_IPC_Service_Task(void)
{
    MISC_IPC_Service_CheckTrigger();
    MISC_IPC_Service_TriggerOutput();
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MISC_IPC_Service_SetTrigger(uint8 TriggerSource)
{
    if (TriggerSource < TRIGGER_MAS_CHANNEL_MAX)
    {
        Misc_DioTriggerInfo_Table[TriggerSource].bTrigger = TRUE;
    }
    else
    {
        misc_warn("The TriggerSource should be less than %d.",TRIGGER_MAS_CHANNEL_MAX);
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MISC_IPC_Service_CheckTrigger(void)
{
    sint16 i;
    Dio_PortLevelType Value; 
    Misc_DioTriggerInfo_t * pTriggerInfo;

    for (i=0;i<TRIGGER_MAS_CHANNEL_MAX;i++)
    {
        pTriggerInfo = &Misc_DioTriggerInfo_Table[i];
        Value = Dio_ReadChannel(pTriggerInfo->ChannelId);
        

        if (FALSE == pTriggerInfo->bIsInit)
        {
            pTriggerInfo->bIsInit = TRUE;
            pTriggerInfo->Value = Value;
            pTriggerInfo->bTrigger = 0;
            pTriggerInfo->cnt = 0;
        }
        else
        {
            if (pTriggerInfo->Value != Value)
            {
                if (pTriggerInfo->cnt>=NUMBER_OF_FILTER)
                {
                    pTriggerInfo->cnt = 0;
                    pTriggerInfo->Value = Value;
                    pTriggerInfo->bTrigger = TRUE;
                }
                else
                {
                    pTriggerInfo->cnt++;
                }

            }
            else
            {
                pTriggerInfo->cnt = 0;
            }
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MISC_IPC_Service_TriggerOutput(void)
{
    uint8 i;
    //Dio_PortLevelType Value; 
    Misc_DioTriggerInfo_t * pTriggerInfo;
    IPC_M2S_MiscServiceTriggerMsg_t data;
    int32_t ret = -1;

    for (i=0;(i<TRIGGER_MAS_CHANNEL_MAX);i++)
    {
        pTriggerInfo = &Misc_DioTriggerInfo_Table[i];

        if (TRUE==pTriggerInfo->bTrigger)
        {
            
            data.TriggerSource = i;
            data.Value = pTriggerInfo->Value;
            ret = IPC_M2S_MiscServiceTriggerMsg_Transmit(&data);
            if (0 == ret)
            {
                pTriggerInfo->bTrigger = FALSE;
                misc_info("IPC Send Trigger Msg.source:%d, value:%d.",data.TriggerSource,data.Value);
            }
            else
            {
                misc_warn("IPC error:%d ",ret);
                if(4 == ret) // 4:IPC_ERR_NINIT
                {
					pTriggerInfo->bTrigger = FALSE;
					misc_info("clear ipc send trigger, ret state:%d",ret);
                }
            }
        }
    }
    
}







#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

