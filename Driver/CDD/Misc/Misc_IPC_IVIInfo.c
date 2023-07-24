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
 * @file:      Misc_IPC_IVIInfo.c
 * @author:    Nobo
 * @date:      2020-9-1
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-1
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

//ATTENTION:  安卓侧临时增加需求，具体功能等安卓确认后再做开发。



#include "Rte_Misc.h"
#include "IPC_Misc.h"
#include "logger.h"



static uint8 u8Switch=0;
static IPC_M2S_MiscIVIInfoWriteDrvModeResp_t MiscIVIInfoWriteDrvModeResp = {0};
static IPC_M2S_MiscIVIInfoReadDrvModeResp_t  MiscIVIInfoReadDrvModeResp = {0};

static int32_t MiscIVIInfoWriteDrvModeResp_Ack = 0;
static int32_t MiscIVIInfoReadDrvModeResp_Ack = 0;




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_IPC_IVIInfo_Callback(uint8 sub_msg_id, uint8 * param, uint16 param_len)
{
    switch(sub_msg_id)
    {
        case IPC_S2M_MISC_IVIINFO_MSGSUB_READDRVMODEREQ_ID:
            {
                IPC_S2M_MiscIVIInfoReadDrvModeReq_t data;
                
                IPC_S2M_MiscIVIInfoReadDrvModeReq_Receive(param,&data,param_len);
                MiscIVIInfoReadDrvModeResp.InfoID = data.InfoID;
                MiscIVIInfoReadDrvModeResp.ModuleID = data.ModuleID;
                MiscIVIInfoReadDrvModeResp.Switch = u8Switch;
                
                MiscIVIInfoReadDrvModeResp_Ack = -1;
                
            }
            break;
        case IPC_S2M_MISC_IVIINFO_MSGSUB_WRITEDRVMODEREQ_ID:
            {
                IPC_S2M_MiscIVIInfoWriteDrvModeReq_t data;
                IPC_S2M_MiscIVIInfoWriteDrvModeReq_Receive(param,&data,param_len);
                u8Switch = data.Switch;
                MiscIVIInfoWriteDrvModeResp.InfoID = data.InfoID;
                MiscIVIInfoWriteDrvModeResp.ModuleID = data.ModuleID;
                MiscIVIInfoWriteDrvModeResp.Result = 0;
                MiscIVIInfoWriteDrvModeResp_Ack = -1;
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
void MISC_IPC_IVIInfo_Task(void)
{
    if (MiscIVIInfoWriteDrvModeResp_Ack != 0)
    {
        MiscIVIInfoWriteDrvModeResp_Ack = IPC_M2S_MiscIVIInfoWriteDrvModeResp_Transmit(&MiscIVIInfoWriteDrvModeResp);
        misc_info("IVIInfo.WriteDrv:%d,%d,%d,[%d]",MiscIVIInfoWriteDrvModeResp.ModuleID,MiscIVIInfoWriteDrvModeResp.InfoID,
            MiscIVIInfoWriteDrvModeResp.Result,MiscIVIInfoWriteDrvModeResp_Ack);
    }

    if (MiscIVIInfoReadDrvModeResp_Ack !=0)
    {
        MiscIVIInfoReadDrvModeResp_Ack = IPC_M2S_MiscIVIInfoReadDrvModeResp_Transmit(&MiscIVIInfoReadDrvModeResp);
        misc_info("IVIInfo.ReadDrv:%d,%d,%d,[%d]",MiscIVIInfoReadDrvModeResp.ModuleID,MiscIVIInfoReadDrvModeResp.InfoID,
            MiscIVIInfoReadDrvModeResp.Switch,MiscIVIInfoReadDrvModeResp_Ack);
    }
}


