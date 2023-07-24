/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *                 File:  IPC_ClusterApp.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group ClusterApp source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_ClusterApp.h"
#include "Ipc_If.h"

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: ClusterApp */
/* Message Major: APP */
/* Transmit function of sub message TT_Module */
int32_t IPC_M2S_ClusterAppAPPTT_Module_Transmit(IPC_M2S_ClusterAppAPPTT_Module_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 23; arrIndex++)
            {
                payload[3 + arrIndex * 4] = IPC_GET_BYTE(data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 3);
                payload[4 + arrIndex * 4] = IPC_GET_BYTE(data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 2);
                payload[5 + arrIndex * 4] = IPC_GET_BYTE(data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 1);
                payload[6 + arrIndex * 4] = IPC_GET_BYTE(data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message WN_Module */
int32_t IPC_M2S_ClusterAppAPPWN_Module_Transmit(IPC_M2S_ClusterAppAPPWN_Module_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 150; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u_WN_Moduleu32Warning_status_t.u32Warning_status[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message Odo */
int32_t IPC_M2S_ClusterAppAPPOdo_Transmit(IPC_M2S_ClusterAppAPPOdo_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_ID;
        payload[3] = IPC_GET_BYTE(data->Value, 3);
        payload[4] = IPC_GET_BYTE(data->Value, 2);
        payload[5] = IPC_GET_BYTE(data->Value, 1);
        payload[6] = IPC_GET_BYTE(data->Value, 0);
        payload[7] = IPC_GET_BYTE(data->Uints, 0);
        payload[8] = IPC_GET_BYTE(data->Valid, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message SIA */
int32_t IPC_M2S_ClusterAppAPPSIA_Transmit(IPC_M2S_ClusterAppAPPSIA_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_ID;
        payload[3] = IPC_GET_BYTE(data->Value, 3);
        payload[4] = IPC_GET_BYTE(data->Value, 2);
        payload[5] = IPC_GET_BYTE(data->Value, 1);
        payload[6] = IPC_GET_BYTE(data->Value, 0);
        payload[7] = IPC_GET_BYTE(data->Uints, 0);
        payload[8] = IPC_GET_BYTE(data->Valid, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message TPMS */
int32_t IPC_M2S_ClusterAppAPPTPMS_Transmit(IPC_M2S_ClusterAppAPPTPMS_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[3 + arrIndex * 4] = IPC_GET_BYTE(data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 3);
                payload[4 + arrIndex * 4] = IPC_GET_BYTE(data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 2);
                payload[5 + arrIndex * 4] = IPC_GET_BYTE(data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 1);
                payload[6 + arrIndex * 4] = IPC_GET_BYTE(data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Chime */
int32_t IPC_M2S_ClusterAppAPPChime_Transmit(IPC_M2S_ClusterAppAPPChime_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_ID;
        payload[3] = IPC_GET_BYTE(data->SoundId, 0);
        payload[4] = IPC_GET_BYTE(data->Volume, 0);
        payload[5] = IPC_GET_BYTE(data->Operation, 0);
        payload[6] = IPC_GET_BYTE(data->Toggle, 0);
        payload[7] = IPC_GET_BYTE(data->RepeatTime, 3);
        payload[8] = IPC_GET_BYTE(data->RepeatTime, 2);
        payload[9] = IPC_GET_BYTE(data->RepeatTime, 1);
        payload[10] = IPC_GET_BYTE(data->RepeatTime, 0);
        payload[11] = IPC_GET_BYTE(data->Soundtrack, 3);
        payload[12] = IPC_GET_BYTE(data->Soundtrack, 2);
        payload[13] = IPC_GET_BYTE(data->Soundtrack, 1);
        payload[14] = IPC_GET_BYTE(data->Soundtrack, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message TripComputer */
int32_t IPC_M2S_ClusterAppAPPTripComputer_Transmit(IPC_M2S_ClusterAppAPPTripComputer_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[3 + arrIndex * 4] = IPC_GET_BYTE(data->Trip[arrIndex], 3);
                payload[4 + arrIndex * 4] = IPC_GET_BYTE(data->Trip[arrIndex], 2);
                payload[5 + arrIndex * 4] = IPC_GET_BYTE(data->Trip[arrIndex], 1);
                payload[6 + arrIndex * 4] = IPC_GET_BYTE(data->Trip[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[11 + arrIndex * 2] = IPC_GET_BYTE(data->AFE[arrIndex], 1);
                payload[12 + arrIndex * 2] = IPC_GET_BYTE(data->AFE[arrIndex], 0);
            }
        }
        payload[15] = IPC_GET_BYTE(data->IFE, 3);
        payload[16] = IPC_GET_BYTE(data->IFE, 2);
        payload[17] = IPC_GET_BYTE(data->IFE, 1);
        payload[18] = IPC_GET_BYTE(data->IFE, 0);
        payload[19] = IPC_GET_BYTE(data->IFE_Unit, 0);
        payload[20] = IPC_GET_BYTE(data->DTE, 3);
        payload[21] = IPC_GET_BYTE(data->DTE, 2);
        payload[22] = IPC_GET_BYTE(data->DTE, 1);
        payload[23] = IPC_GET_BYTE(data->DTE, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[24 + arrIndex * 2] = IPC_GET_BYTE(data->AVS[arrIndex], 1);
                payload[25 + arrIndex * 2] = IPC_GET_BYTE(data->AVS[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[28 + arrIndex * 1] = IPC_GET_BYTE(data->Travel_time_Hour[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[30 + arrIndex * 1] = IPC_GET_BYTE(data->Travel_time_MIN[arrIndex], 0);
            }
        }
        payload[32] = IPC_GET_BYTE(data->DTE_AVS_Uint, 0);
        payload[33] = IPC_GET_BYTE(data->AFE_Uint, 0);
        payload[34] = IPC_GET_BYTE(data->Phev_Dte_Ipc, 1);
        payload[35] = IPC_GET_BYTE(data->Phev_Dte_Ipc, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[36 + arrIndex * 4] = IPC_GET_BYTE(data->DTE_Dual[arrIndex], 3);
                payload[37 + arrIndex * 4] = IPC_GET_BYTE(data->DTE_Dual[arrIndex], 2);
                payload[38 + arrIndex * 4] = IPC_GET_BYTE(data->DTE_Dual[arrIndex], 1);
                payload[39 + arrIndex * 4] = IPC_GET_BYTE(data->DTE_Dual[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message FUEL */
int32_t IPC_M2S_ClusterAppAPPFUEL_Transmit(IPC_M2S_ClusterAppAPPFUEL_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_ID;
        payload[3] = IPC_GET_BYTE(data->TankFuelLevelPercent, 1);
        payload[4] = IPC_GET_BYTE(data->TankFuelLevelPercent, 0);
        payload[5] = IPC_GET_BYTE(data->Tankportposition, 0);
        payload[6] = IPC_GET_BYTE(data->Low_fuel_warning, 0);
        payload[7] = IPC_GET_BYTE(data->LFW_Trigger_Ipc, 1);
        payload[8] = IPC_GET_BYTE(data->LFW_Trigger_Ipc, 0);
        payload[9] = IPC_GET_BYTE(data->LFW_Release_Ipc, 1);
        payload[10] = IPC_GET_BYTE(data->LFW_Release_Ipc, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[11 + arrIndex * 2] = IPC_GET_BYTE(data->TankFuelLevelPercent_Dual[arrIndex], 1);
                payload[12 + arrIndex * 2] = IPC_GET_BYTE(data->TankFuelLevelPercent_Dual[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[15 + arrIndex * 1] = IPC_GET_BYTE(data->Tankportposition_Dual[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[17 + arrIndex * 1] = IPC_GET_BYTE(data->Low_fuel_warning_Dual[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[19 + arrIndex * 2] = IPC_GET_BYTE(data->LFW_Trigger_Ipc_Dual[arrIndex], 1);
                payload[20 + arrIndex * 2] = IPC_GET_BYTE(data->LFW_Trigger_Ipc_Dual[arrIndex], 0);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                payload[23 + arrIndex * 2] = IPC_GET_BYTE(data->LFW_Release_Ipc_Dual[arrIndex], 1);
                payload[24 + arrIndex * 2] = IPC_GET_BYTE(data->LFW_Release_Ipc_Dual[arrIndex], 0);
            }
        }
        payload[27] = IPC_GET_BYTE(data->OilBoxSplySts_Switch_Dual, 0);
        payload[28] = IPC_GET_BYTE(data->Fuel_Tank_System, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Speedo */
int32_t IPC_M2S_ClusterAppAPPSpeedo_Transmit(IPC_M2S_ClusterAppAPPSpeedo_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_ID;
        payload[3] = IPC_GET_BYTE(data->VehSpdCalculated, 3);
        payload[4] = IPC_GET_BYTE(data->VehSpdCalculated, 2);
        payload[5] = IPC_GET_BYTE(data->VehSpdCalculated, 1);
        payload[6] = IPC_GET_BYTE(data->VehSpdCalculated, 0);
        payload[7] = IPC_GET_BYTE(data->VehSpdReal, 3);
        payload[8] = IPC_GET_BYTE(data->VehSpdReal, 2);
        payload[9] = IPC_GET_BYTE(data->VehSpdReal, 1);
        payload[10] = IPC_GET_BYTE(data->VehSpdReal, 0);
        payload[11] = IPC_GET_BYTE(data->VehSpdMax, 3);
        payload[12] = IPC_GET_BYTE(data->VehSpdMax, 2);
        payload[13] = IPC_GET_BYTE(data->VehSpdMax, 1);
        payload[14] = IPC_GET_BYTE(data->VehSpdMax, 0);
        payload[15] = IPC_GET_BYTE(data->VehSpdUnit, 0);
        payload[16] = IPC_GET_BYTE(data->RedDispaly, 0);
        payload[17] = IPC_GET_BYTE(data->VehRunningSts, 0);
        payload[18] = IPC_GET_BYTE(data->VehSpdAnalog, 3);
        payload[19] = IPC_GET_BYTE(data->VehSpdAnalog, 2);
        payload[20] = IPC_GET_BYTE(data->VehSpdAnalog, 1);
        payload[21] = IPC_GET_BYTE(data->VehSpdAnalog, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Tacho */
int32_t IPC_M2S_ClusterAppAPPTacho_Transmit(IPC_M2S_ClusterAppAPPTacho_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_ID;
        payload[3] = IPC_GET_BYTE(data->EngSpdCalculated, 3);
        payload[4] = IPC_GET_BYTE(data->EngSpdCalculated, 2);
        payload[5] = IPC_GET_BYTE(data->EngSpdCalculated, 1);
        payload[6] = IPC_GET_BYTE(data->EngSpdCalculated, 0);
        payload[7] = IPC_GET_BYTE(data->EngSpdMax, 3);
        payload[8] = IPC_GET_BYTE(data->EngSpdMax, 2);
        payload[9] = IPC_GET_BYTE(data->EngSpdMax, 1);
        payload[10] = IPC_GET_BYTE(data->EngSpdMax, 0);
        payload[11] = IPC_GET_BYTE(data->RedDispaly, 0);
        payload[12] = IPC_GET_BYTE(data->EngRunningSts, 0);
        payload[13] = IPC_GET_BYTE(data->RedZoneThreshold, 3);
        payload[14] = IPC_GET_BYTE(data->RedZoneThreshold, 2);
        payload[15] = IPC_GET_BYTE(data->RedZoneThreshold, 1);
        payload[16] = IPC_GET_BYTE(data->RedZoneThreshold, 0);
        payload[17] = IPC_GET_BYTE(data->EngSpdAnalog, 3);
        payload[18] = IPC_GET_BYTE(data->EngSpdAnalog, 2);
        payload[19] = IPC_GET_BYTE(data->EngSpdAnalog, 1);
        payload[20] = IPC_GET_BYTE(data->EngSpdAnalog, 0);
        payload[21] = IPC_GET_BYTE(data->EngSpdReal, 3);
        payload[22] = IPC_GET_BYTE(data->EngSpdReal, 2);
        payload[23] = IPC_GET_BYTE(data->EngSpdReal, 1);
        payload[24] = IPC_GET_BYTE(data->EngSpdReal, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message Coolant */
int32_t IPC_M2S_ClusterAppAPPCoolant_Transmit(IPC_M2S_ClusterAppAPPCoolant_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_ID;
        payload[3] = IPC_GET_BYTE(data->EngCoolantTemp, 3);
        payload[4] = IPC_GET_BYTE(data->EngCoolantTemp, 2);
        payload[5] = IPC_GET_BYTE(data->EngCoolantTemp, 1);
        payload[6] = IPC_GET_BYTE(data->EngCoolantTemp, 0);
        payload[7] = IPC_GET_BYTE(data->RedDispaly, 0);
        payload[8] = IPC_GET_BYTE(data->EngCoolantTempPhysValue, 3);
        payload[9] = IPC_GET_BYTE(data->EngCoolantTempPhysValue, 2);
        payload[10] = IPC_GET_BYTE(data->EngCoolantTempPhysValue, 1);
        payload[11] = IPC_GET_BYTE(data->EngCoolantTempPhysValue, 0);
        payload[12] = IPC_GET_BYTE(data->RedZoneThreshold, 3);
        payload[13] = IPC_GET_BYTE(data->RedZoneThreshold, 2);
        payload[14] = IPC_GET_BYTE(data->RedZoneThreshold, 1);
        payload[15] = IPC_GET_BYTE(data->RedZoneThreshold, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MenuSetting */
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Transmit(IPC_M2S_ClusterAppAPPMenuSetting_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_ID;
        payload[3] = IPC_GET_BYTE(data->Sd_NaviLimitSpeed, 1);
        payload[4] = IPC_GET_BYTE(data->Sd_NaviLimitSpeed, 0);
        payload[5] = IPC_GET_BYTE(data->Sd_OverSpeedEnable, 0);
        payload[6] = IPC_GET_BYTE(data->Sd_Language, 0);
        payload[7] = IPC_GET_BYTE(data->Sd_ClusterTheme, 0);
        payload[8] = IPC_GET_BYTE(data->Sd_OdometerUnit, 0);
        payload[9] = IPC_GET_BYTE(data->Sd_TemperatureUnit, 0);
        payload[10] = IPC_GET_BYTE(data->Sd_TirePressureUnit, 0);
        payload[11] = IPC_GET_BYTE(data->Sd_TripComputerId, 0);
        payload[12] = IPC_GET_BYTE(data->Sd_InteractiveCarId, 0);
        payload[13] = IPC_GET_BYTE(data->Sd_DrivingModeMemorySwitch, 0);
        payload[14] = IPC_GET_BYTE(data->Sd_TimeUnit, 0);
        payload[15] = IPC_GET_BYTE(data->Sd_HighwayAssistSwitch, 0);
        payload[16] = IPC_GET_BYTE(data->Sd_LaneChangeAssistSwitch, 0);
        payload[17] = IPC_GET_BYTE(data->Sd_SunriseSunset_Mode, 0);
        payload[18] = IPC_GET_BYTE(data->Sd_Auto_Mode, 0);
        payload[19] = IPC_GET_BYTE(data->Sd_DrvgModeMemReq, 0);
        payload[20] = IPC_GET_BYTE(data->Sd_DrvingModReqHUT, 0);
        payload[21] = IPC_GET_BYTE(data->Sd_Switch_ThemeLinkage_Sts, 0);
        payload[22] = IPC_GET_BYTE(data->Sd_DataSyncFlg, 0);
        payload[23] = IPC_GET_BYTE(data->Sd_AtmosphereLampLinkageSwt_Sts, 0);
        payload[24] = IPC_GET_BYTE(data->Sd_SimSoundWaveLinkageSwt_Sts, 0);
        payload[25] = IPC_GET_BYTE(data->Sd_MaoCallLinkageSwt_Sts, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message TCClearResult */
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Transmit(IPC_M2S_ClusterAppAPPTCClearResult_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_ID;
        payload[3] = IPC_GET_BYTE(data->Result, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ConfigData */
int32_t IPC_M2S_ClusterAppAPPConfigData_Transmit(IPC_M2S_ClusterAppAPPConfigData_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_ID;
        payload[3] = IPC_GET_BYTE(data->Fast_Resp, 0);
        payload[4] = IPC_GET_BYTE(data->DigitalRPM_Hysteresis, 1);
        payload[5] = IPC_GET_BYTE(data->DigitalRPM_Hysteresis, 0);
        payload[6] = IPC_GET_BYTE(data->GasolineCoolant_C_point, 0);
        payload[7] = IPC_GET_BYTE(data->GasolineCoolant_14_point, 0);
        payload[8] = IPC_GET_BYTE(data->GasolineCoolant_12_point1, 0);
        payload[9] = IPC_GET_BYTE(data->GasolineCoolant_12_point2, 0);
        payload[10] = IPC_GET_BYTE(data->GasolineCoolant_4_point, 0);
        payload[11] = IPC_GET_BYTE(data->GasolineCoolant_Redline_point, 0);
        payload[12] = IPC_GET_BYTE(data->GasolineCoolant_H_point, 0);
        payload[13] = IPC_GET_BYTE(data->DieselCoolant_C_point, 0);
        payload[14] = IPC_GET_BYTE(data->DieselCoolant_14_point, 0);
        payload[15] = IPC_GET_BYTE(data->DieselCoolant_12_point1, 0);
        payload[16] = IPC_GET_BYTE(data->DieselCoolant_12_point2, 0);
        payload[17] = IPC_GET_BYTE(data->DieselCoolant_34_point, 0);
        payload[18] = IPC_GET_BYTE(data->DieselCoolant_Redline_point, 0);
        payload[19] = IPC_GET_BYTE(data->DieselCoolant_H_point, 0);
        payload[20] = IPC_GET_BYTE(data->Horizontal_data, 1);
        payload[21] = IPC_GET_BYTE(data->Horizontal_data, 0);
        payload[22] = IPC_GET_BYTE(data->X, 0);
        payload[23] = IPC_GET_BYTE(data->Y, 0);
        payload[24] = IPC_GET_BYTE(data->AVSBDisplayEnable, 0);
        payload[25] = IPC_GET_BYTE(data->AVSADisplayEnable, 0);
        payload[26] = IPC_GET_BYTE(data->TravelTimeADisplayEnable, 0);
        payload[27] = IPC_GET_BYTE(data->TravelTimeBDisplayEnable, 0);
        payload[28] = IPC_GET_BYTE(data->AFCADisplayEnable, 0);
        payload[29] = IPC_GET_BYTE(data->AFCBDisplayEnable, 0);
        payload[30] = IPC_GET_BYTE(data->IFCDisplayEnable, 0);
        payload[31] = IPC_GET_BYTE(data->DigitalSpeedDisplayEnable, 0);
        payload[32] = IPC_GET_BYTE(data->PHEV_HEVDTEDisplayEnable, 0);
        payload[33] = IPC_GET_BYTE(data->MaxDisplayPHEVRange, 0);
        payload[34] = IPC_GET_BYTE(data->PHEVSOCDisplayEnable, 0);
        payload[35] = IPC_GET_BYTE(data->RefreshRatePHEVSOC, 1);
        payload[36] = IPC_GET_BYTE(data->RefreshRatePHEVSOC, 0);
        payload[37] = IPC_GET_BYTE(data->AvailablePowerDisplayEnable, 0);
        payload[38] = IPC_GET_BYTE(data->MaxAvailablePower, 0);
        payload[39] = IPC_GET_BYTE(data->RefreshRateAvrgEgyCns, 1);
        payload[40] = IPC_GET_BYTE(data->RefreshRateAvrgEgyCns, 0);
        payload[41] = IPC_GET_BYTE(data->AvrgEgyCnsDisplayEnable, 0);
        payload[42] = IPC_GET_BYTE(data->MaxvalueAvrgEgyCns, 1);
        payload[43] = IPC_GET_BYTE(data->MaxvalueAvrgEgyCns, 0);
        payload[44] = IPC_GET_BYTE(data->RefreshRatemotorpower, 1);
        payload[45] = IPC_GET_BYTE(data->RefreshRatemotorpower, 0);
        payload[46] = IPC_GET_BYTE(data->motorpowerDisplayEnable, 0);
        payload[47] = IPC_GET_BYTE(data->RefreshRateEVSOC, 1);
        payload[48] = IPC_GET_BYTE(data->RefreshRateEVSOC, 0);
        payload[49] = IPC_GET_BYTE(data->EVSOCDisplayEnable, 0);
        payload[50] = IPC_GET_BYTE(data->RefreshRateEVDTE, 1);
        payload[51] = IPC_GET_BYTE(data->RefreshRateEVDTE, 0);
        payload[52] = IPC_GET_BYTE(data->EVDTEDisplayEnable, 0);
        payload[53] = IPC_GET_BYTE(data->MaxvalueEVDTE, 1);
        payload[54] = IPC_GET_BYTE(data->MaxvalueEVDTE, 0);
        payload[55] = IPC_GET_BYTE(data->RefreshRateCurrent, 1);
        payload[56] = IPC_GET_BYTE(data->RefreshRateCurrent, 0);
        payload[57] = IPC_GET_BYTE(data->EVCurrentDisplayEnable, 0);
        payload[58] = IPC_GET_BYTE(data->EVDrivDataARestTime, 0);
        payload[59] = IPC_GET_BYTE(data->RefreshRateEVAVS, 1);
        payload[60] = IPC_GET_BYTE(data->RefreshRateEVAVS, 0);
        payload[61] = IPC_GET_BYTE(data->EVAVSMinDistanceThresh, 0);
        payload[62] = IPC_GET_BYTE(data->EVAVSADisplayEnable, 0);
        payload[63] = IPC_GET_BYTE(data->EVAVSBDisplayEnable, 0);
        payload[64] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 7);
        payload[65] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 6);
        payload[66] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 5);
        payload[67] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 4);
        payload[68] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 3);
        payload[69] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 2);
        payload[70] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 1);
        payload[71] = IPC_GET_BYTE(data->EVTravelTimeDisplayLimited, 0);
        payload[72] = IPC_GET_BYTE(data->EVTravelTimeADisplayEnable, 0);
        payload[73] = IPC_GET_BYTE(data->EVTravelTimeBDisplayEnable, 0);
        payload[74] = IPC_GET_BYTE(data->DoortoRed_speedthreshold, 0);
        payload[75] = IPC_GET_BYTE(data->Doorallclosed_holdtime, 0);
        payload[76] = IPC_GET_BYTE(data->Telltale_interrupt_display_time, 0);
        payload[77] = IPC_GET_BYTE(data->Telltale_polling_display_time, 0);
        payload[78] = IPC_GET_BYTE(data->TPMSDisplayEnable, 0);
        payload[79] = IPC_GET_BYTE(data->FIXEDDISPLAY_1_ODO_ENABLE, 0);
        payload[80] = IPC_GET_BYTE(data->FD_003_CLOCK_ENABLE, 0);
        payload[81] = IPC_GET_BYTE(data->FD_009_DRIVE_MODE_2WD_ENABLE, 0);
        payload[82] = IPC_GET_BYTE(data->DrivDataADisplayEnable, 0);
        payload[83] = IPC_GET_BYTE(data->DrivDataBDisplayEnable, 0);
        payload[84] = IPC_GET_BYTE(data->Adas_V1, 1);
        payload[85] = IPC_GET_BYTE(data->Adas_V1, 0);
        payload[86] = IPC_GET_BYTE(data->Adas_V2, 1);
        payload[87] = IPC_GET_BYTE(data->Adas_V2, 0);
        payload[88] = IPC_GET_BYTE(data->GasolineCoolant_Distime, 0);
        payload[89] = IPC_GET_BYTE(data->DieselCoolant_Distime, 0);
        payload[90] = IPC_GET_BYTE(data->Fuel_Distime, 0);
        payload[91] = IPC_GET_BYTE(data->RefreshRateUrea, 1);
        payload[92] = IPC_GET_BYTE(data->RefreshRateUrea, 0);
        payload[93] = IPC_GET_BYTE(data->GValue_Hysteresis, 0);
        payload[94] = IPC_GET_BYTE(data->GValue_update_frequency, 1);
        payload[95] = IPC_GET_BYTE(data->GValue_update_frequency, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message VConfig */
int32_t IPC_M2S_ClusterAppAPPVConfig_Transmit(IPC_M2S_ClusterAppAPPVConfig_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 9; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u_VConfigu8VConfig_data_t.u8VConfig_data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message MenuTheme */
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Transmit(IPC_M2S_ClusterAppAPPMenuTheme_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_ID;
        payload[3] = IPC_GET_BYTE(data->ThemeID, 3);
        payload[4] = IPC_GET_BYTE(data->ThemeID, 2);
        payload[5] = IPC_GET_BYTE(data->ThemeID, 1);
        payload[6] = IPC_GET_BYTE(data->ThemeID, 0);
        payload[7] = IPC_GET_BYTE(data->SkinID, 3);
        payload[8] = IPC_GET_BYTE(data->SkinID, 2);
        payload[9] = IPC_GET_BYTE(data->SkinID, 1);
        payload[10] = IPC_GET_BYTE(data->SkinID, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message DriveMode */
int32_t IPC_M2S_ClusterAppAPPDriveMode_Transmit(IPC_M2S_ClusterAppAPPDriveMode_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 6; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u_DriveModeu8DriveMode_data_t.u8DriveMode_data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message WN_Data */
int32_t IPC_M2S_ClusterAppAPPWN_Data_Transmit(IPC_M2S_ClusterAppAPPWN_Data_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_ID;
        payload[3] = IPC_GET_BYTE(data->WN_TgtCrsSpd, 0);
        payload[4] = IPC_GET_BYTE(data->WN_TgtCrsSpdVldSts, 0);
        payload[5] = IPC_GET_BYTE(data->WN_DrvModeCaseValue, 0);
        payload[6] = IPC_GET_BYTE(data->WN_NOHDist, 1);
        payload[7] = IPC_GET_BYTE(data->WN_NOHDist, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message NewEnergy */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Transmit(IPC_M2S_ClusterAppAPPNewEnergy_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[3 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 3);
                payload[4 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 2);
                payload[5 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 1);
                payload[6 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message NewEnergy_EV */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Transmit(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 6; arrIndex++)
            {
                payload[3 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 3);
                payload[4 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 2);
                payload[5 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 1);
                payload[6 + arrIndex * 4] = IPC_GET_BYTE(data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 0);
            }
        }
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Transmit function of sub message OffroadInfo */
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Transmit(IPC_M2S_ClusterAppAPPOffroadInfo_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_ID;
        payload[3] = IPC_GET_BYTE(data->Sd_BaroPressure, 1);
        payload[4] = IPC_GET_BYTE(data->Sd_BaroPressure, 0);
        payload[5] = IPC_GET_BYTE(data->Sd_Heilvl, 1);
        payload[6] = IPC_GET_BYTE(data->Sd_Heilvl, 0);
        payload[7] = IPC_GET_BYTE(data->Sd_HeilvlSign, 0);
        payload[8] = IPC_GET_BYTE(data->Sd_PitchAngle, 0);
        payload[9] = IPC_GET_BYTE(data->Sd_PitchAngleSign, 0);
        payload[10] = IPC_GET_BYTE(data->Sd_GeoGraphic, 0);
        payload[11] = IPC_GET_BYTE(data->Sd_SteerWheel, 0);
        payload[12] = IPC_GET_BYTE(data->Sd_SteerWheelSign, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_LOW);
    }
    return ret;
}

/* Message Major: System */
/* Transmit function of sub message BootCondition */
int32_t IPC_M2S_ClusterAppSystemBootCondition_Transmit(IPC_M2S_ClusterAppSystemBootCondition_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_ID;
        payload[3] = IPC_GET_BYTE(data->Tach, 1);
        payload[4] = IPC_GET_BYTE(data->Tach, 0);
        payload[5] = IPC_GET_BYTE(data->Speed, 1);
        payload[6] = IPC_GET_BYTE(data->Speed, 0);
        payload[7] = IPC_GET_BYTE(data->Gear, 0);
        payload[8] = IPC_GET_BYTE(data->Handbrake, 0);
        payload[9] = IPC_GET_BYTE(data->EngineSts, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ADASConfig */
int32_t IPC_M2S_ClusterAppSystemADASConfig_Transmit(IPC_M2S_ClusterAppSystemADASConfig_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_ID;
        payload[3] = IPC_GET_BYTE(data->HighwayAssistSwitch, 0);
        payload[4] = IPC_GET_BYTE(data->LaneChangeAssistSwitch, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message CLUSTERPOWER */
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Transmit(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_ID;
        payload[3] = IPC_GET_BYTE(data->ClusterState, 0);
        payload[4] = IPC_GET_BYTE(data->VoltageState, 0);
        payload[5] = IPC_GET_BYTE(data->PowerChangedFlag, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message CommonAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message IPCDebugTest */
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Transmit(IPC_M2S_ClusterAppSystemIPCDebugTest_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message InterfaceAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message GaugeMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_ID;
        payload[3] = IPC_GET_BYTE(data->Status, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Message Major: CANAdapt */
/* Transmit function of sub message CSA3_244 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Transmit(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_ID;
        payload[3] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 3);
        payload[4] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 2);
        payload[5] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 1);
        payload[6] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 0);
        payload[7] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 3);
        payload[8] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 2);
        payload[9] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 1);
        payload[10] = IPC_GET_BYTE(data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message EEM1_2A8 */
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Transmit(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_ID;
        payload[3] = IPC_GET_BYTE(data->u_EEM1_2A8EEM1_2A8_Inf_t.EEM1_2A8_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ESP2_145 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Transmit(IPC_M2S_ClusterAppCANAdaptESP2_145_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_ID;
        payload[3] = IPC_GET_BYTE(data->u_ESP2_145ESP2_145_Inf_t.ESP2_145_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ESP2_137 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Transmit(IPC_M2S_ClusterAppCANAdaptESP2_137_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_ID;
        payload[3] = IPC_GET_BYTE(data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HUD1_325 */
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Transmit(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_ID;
        payload[3] = IPC_GET_BYTE(data->u_HUD1_325HUD1_325_t.HUD1_325, 3);
        payload[4] = IPC_GET_BYTE(data->u_HUD1_325HUD1_325_t.HUD1_325, 2);
        payload[5] = IPC_GET_BYTE(data->u_HUD1_325HUD1_325_t.HUD1_325, 1);
        payload[6] = IPC_GET_BYTE(data->u_HUD1_325HUD1_325_t.HUD1_325, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ECM3_371 */
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Transmit(IPC_M2S_ClusterAppCANAdaptECM3_371_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_ID;
        payload[3] = IPC_GET_BYTE(data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message CSA2_A1 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Transmit(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_ID;
        payload[3] = IPC_GET_BYTE(data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 3);
        payload[4] = IPC_GET_BYTE(data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 2);
        payload[5] = IPC_GET_BYTE(data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 1);
        payload[6] = IPC_GET_BYTE(data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ECM16_2D4 */
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Transmit(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_ID;
        payload[3] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 7);
        payload[4] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 6);
        payload[5] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 5);
        payload[6] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 4);
        payload[7] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 3);
        payload[8] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 2);
        payload[9] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 1);
        payload[10] = IPC_GET_BYTE(data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AC2_385 */
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Transmit(IPC_M2S_ClusterAppCANAdaptAC2_385_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_ID;
        payload[3] = IPC_GET_BYTE(data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ECM_PT6_290 */
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Transmit(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_ID;
        payload[3] = IPC_GET_BYTE(data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 3);
        payload[4] = IPC_GET_BYTE(data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 2);
        payload[5] = IPC_GET_BYTE(data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 1);
        payload[6] = IPC_GET_BYTE(data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ABM2_245 */
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Transmit(IPC_M2S_ClusterAppCANAdaptABM2_245_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_ID;
        payload[3] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 7);
        payload[4] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 6);
        payload[5] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 5);
        payload[6] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 4);
        payload[7] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 3);
        payload[8] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 2);
        payload[9] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 1);
        payload[10] = IPC_GET_BYTE(data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message RSDS_FD1_16F */
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Transmit(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_ID;
        payload[3] = IPC_GET_BYTE(data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message IFC_FD5_19F */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_ID;
        payload[3] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 3);
        payload[4] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 2);
        payload[5] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 1);
        payload[6] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 0);
        payload[7] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 3);
        payload[8] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 2);
        payload[9] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 1);
        payload[10] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 0);
        payload[11] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 3);
        payload[12] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 2);
        payload[13] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 1);
        payload[14] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 0);
        payload[15] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 3);
        payload[16] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 2);
        payload[17] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 1);
        payload[18] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 0);
        payload[19] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 3);
        payload[20] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 2);
        payload[21] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 1);
        payload[22] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 0);
        payload[23] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 3);
        payload[24] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 2);
        payload[25] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 1);
        payload[26] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 0);
        payload[27] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 3);
        payload[28] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 2);
        payload[29] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 1);
        payload[30] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 0);
        payload[31] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 7);
        payload[32] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 6);
        payload[33] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 5);
        payload[34] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 4);
        payload[35] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 3);
        payload[36] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 2);
        payload[37] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 1);
        payload[38] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 0);
        payload[39] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 7);
        payload[40] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 6);
        payload[41] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 5);
        payload[42] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 4);
        payload[43] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 3);
        payload[44] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 2);
        payload[45] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 1);
        payload[46] = IPC_GET_BYTE(data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message IFC_FD6_222 */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_ID;
        payload[3] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 7);
        payload[4] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 6);
        payload[5] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 5);
        payload[6] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 4);
        payload[7] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 3);
        payload[8] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 2);
        payload[9] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 1);
        payload[10] = IPC_GET_BYTE(data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ACC_FD2_2AB */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Transmit(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_ID;
        payload[3] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 3);
        payload[4] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 2);
        payload[5] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 1);
        payload[6] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 0);
        payload[7] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 3);
        payload[8] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 2);
        payload[9] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 1);
        payload[10] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 0);
        payload[11] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 3);
        payload[12] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 2);
        payload[13] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 1);
        payload[14] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 0);
        payload[15] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 3);
        payload[16] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 2);
        payload[17] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 1);
        payload[18] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 0);
        payload[19] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 3);
        payload[20] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 2);
        payload[21] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 1);
        payload[22] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 0);
        payload[23] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 3);
        payload[24] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 2);
        payload[25] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 1);
        payload[26] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 0);
        payload[27] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 3);
        payload[28] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 2);
        payload[29] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 1);
        payload[30] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 0);
        payload[31] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 7);
        payload[32] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 6);
        payload[33] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 5);
        payload[34] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 4);
        payload[35] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 3);
        payload[36] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 2);
        payload[37] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 1);
        payload[38] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 0);
        payload[39] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 7);
        payload[40] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 6);
        payload[41] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 5);
        payload[42] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 4);
        payload[43] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 3);
        payload[44] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 2);
        payload[45] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 1);
        payload[46] = IPC_GET_BYTE(data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message IFC_FD2_23D */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_ID;
        payload[3] = IPC_GET_BYTE(data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message AEB_FD2_227 */
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Transmit(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_ID;
        payload[3] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 3);
        payload[4] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 2);
        payload[5] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 1);
        payload[6] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 0);
        payload[7] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 3);
        payload[8] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 2);
        payload[9] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 1);
        payload[10] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 0);
        payload[11] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 3);
        payload[12] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 2);
        payload[13] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 1);
        payload[14] = IPC_GET_BYTE(data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message CR_FD1_15E */
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Transmit(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_ID;
        payload[3] = IPC_GET_BYTE(data->u_CR_FD1_15ECR_FD1_15E_Inf_t.CR_FD1_15E_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message IFC_FD3_2CF */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_ID;
        payload[3] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 7);
        payload[4] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 6);
        payload[5] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 5);
        payload[6] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 4);
        payload[7] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 3);
        payload[8] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 2);
        payload[9] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 1);
        payload[10] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 0);
        payload[11] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 1);
        payload[12] = IPC_GET_BYTE(data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ACC_FD3_2B4 */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Transmit(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_ID;
        payload[3] = IPC_GET_BYTE(data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message BCM1_319 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Transmit(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_ID;
        payload[3] = IPC_GET_BYTE(data->u_BCM1_319BCM1_319_Inf_t.BCM1_319_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message BCM3_345 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Transmit(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_ID;
        payload[3] = IPC_GET_BYTE(data->u_BCM3_345BCM3_345_Inf_t.BCM3_345_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message T_Box_FD10_2F0 */
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Transmit(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_ID;
        payload[3] = IPC_GET_BYTE(data->u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.T_Box_FD10_2F0_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ECM24_350 */
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Transmit(IPC_M2S_ClusterAppCANAdaptECM24_350_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_ID;
        payload[3] = IPC_GET_BYTE(data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 3);
        payload[4] = IPC_GET_BYTE(data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 2);
        payload[5] = IPC_GET_BYTE(data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 1);
        payload[6] = IPC_GET_BYTE(data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message BCM12_238 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Transmit(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_ID;
        payload[3] = IPC_GET_BYTE(data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message F_PBOX1_19B */
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Transmit(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_ID;
        payload[3] = IPC_GET_BYTE(data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HCM_L2_304 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Transmit(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_ID;
        payload[3] = IPC_GET_BYTE(data->u_HCM_L2_304HCM_L2_304_Inf_t.HCM_L2_304_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message VCU_FD41_2D6 */
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Transmit(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_ID;
        payload[3] = IPC_GET_BYTE(data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 1);
        payload[4] = IPC_GET_BYTE(data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message HCM_R2_330 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Transmit(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_ID;
        payload[3] = IPC_GET_BYTE(data->u_HCM_R2_330HCM_R2_330_Inf_t.HCM_R2_330_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Transmit function of sub message ESP1_149 */
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Transmit(IPC_M2S_ClusterAppCANAdaptESP1_149_t *data)
{
    uint8_t payload[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_CLUSTERAPP_ID;
        payload[1] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[2] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_ID;
        payload[3] = IPC_GET_BYTE(data->u_ESP1_149ESP1_149_Inf_t.ESP1_149_Inf, 0);
        /* Send IPC */
        ret = IPC_DataSend(payload, IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
    }
    return ret;
}

/* Receive function of sub message WrnId */
void IPC_S2M_ClusterAppClusterSocWrnId_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocWrnId_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->General, 1) = receiveBuffer[0];
        IPC_GET_BYTE(data->General, 0) = receiveBuffer[1];
        IPC_GET_BYTE(data->GeneralShied, 1) = receiveBuffer[2];
        IPC_GET_BYTE(data->GeneralShied, 0) = receiveBuffer[3];
        IPC_GET_BYTE(data->GeneralBit, 1) = receiveBuffer[4];
        IPC_GET_BYTE(data->GeneralBit, 0) = receiveBuffer[5];
        IPC_GET_BYTE(data->Adas, 1) = receiveBuffer[6];
        IPC_GET_BYTE(data->Adas, 0) = receiveBuffer[7];
        IPC_GET_BYTE(data->AdasFault, 0) = receiveBuffer[8];
        IPC_GET_BYTE(data->u_WrnIdFirstDisplayFlag_t.FirstDisplayFlag, 0) = receiveBuffer[9];
    }

}

/* Receive function of sub message TTStatus */
void IPC_S2M_ClusterAppClusterSocTTStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTTStatus_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 6; arrIndex++)
            {
                IPC_GET_BYTE(data->u_TTStatusu32Telltales_status_t.u32Telltales_status[arrIndex], 0) = receiveBuffer[0 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message AdasStatus */
void IPC_S2M_ClusterAppClusterSocAdasStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocAdasStatus_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->u_AdasStatusAdasWarn_t.AdasWarn[arrIndex], 0) = receiveBuffer[0 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message BackChime */
void IPC_S2M_ClusterAppClusterSocBackChime_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocBackChime_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->CurId, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->LastRepeat, 0) = receiveBuffer[1];
    }

}

/* Receive function of sub message TCClear */
void IPC_S2M_ClusterAppClusterSocTCClear_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTCClear_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->MenuResrt, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message TtToChime */
void IPC_S2M_ClusterAppClusterSocTtToChime_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTtToChime_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->TtFlash, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->TtFlashTick, 3) = receiveBuffer[1];
        IPC_GET_BYTE(data->TtFlashTick, 2) = receiveBuffer[2];
        IPC_GET_BYTE(data->TtFlashTick, 1) = receiveBuffer[3];
        IPC_GET_BYTE(data->TtFlashTick, 0) = receiveBuffer[4];
    }

}

/* Receive function of sub message CommonAppAlive */
void IPC_S2M_ClusterAppClusterSocCommonAppAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->AliveTick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message MenuSetting */
void IPC_S2M_ClusterAppClusterSocMenuSetting_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMenuSetting_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->ID, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->Value, 1) = receiveBuffer[1];
        IPC_GET_BYTE(data->Value, 0) = receiveBuffer[2];
    }

}

/* Receive function of sub message Gauges */
void IPC_S2M_ClusterAppClusterSocGauges_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocGauges_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->VehicleSpeed, 1) = receiveBuffer[0];
        IPC_GET_BYTE(data->VehicleSpeed, 0) = receiveBuffer[1];
        IPC_GET_BYTE(data->EngineSpeed, 1) = receiveBuffer[2];
        IPC_GET_BYTE(data->EngineSpeed, 0) = receiveBuffer[3];
    }

}

/* Receive function of sub message InterfaceAppAlive */
void IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->AliveTick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message HMIPowerMode */
void IPC_S2M_ClusterAppClusterSocHMIPowerMode_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->PowerStatus, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message GaugesAlive */
void IPC_S2M_ClusterAppClusterSocGaugesAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocGaugesAlive_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->AliveTick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message ChimeClientAlive */
void IPC_S2M_ClusterAppClusterSocChimeClientAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->AliveTick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message MenuTheme */
void IPC_S2M_ClusterAppClusterSocMenuTheme_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMenuTheme_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Rc_ThemeID, 3) = receiveBuffer[0];
        IPC_GET_BYTE(data->Rc_ThemeID, 2) = receiveBuffer[1];
        IPC_GET_BYTE(data->Rc_ThemeID, 1) = receiveBuffer[2];
        IPC_GET_BYTE(data->Rc_ThemeID, 0) = receiveBuffer[3];
        IPC_GET_BYTE(data->Rc_SkinID, 3) = receiveBuffer[4];
        IPC_GET_BYTE(data->Rc_SkinID, 2) = receiveBuffer[5];
        IPC_GET_BYTE(data->Rc_SkinID, 1) = receiveBuffer[6];
        IPC_GET_BYTE(data->Rc_SkinID, 0) = receiveBuffer[7];
    }

}

/* Receive function of sub message HMISafety */
void IPC_S2M_ClusterAppClusterSocHMISafety_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocHMISafety_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->AliveTick, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message MiaoCALL */
void IPC_S2M_ClusterAppClusterSocMiaoCALL_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMiaoCALL_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->MiaoCALLsts, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message OffroadInfo */
void IPC_S2M_ClusterAppClusterSocOffroadInfo_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocOffroadInfo_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->ID, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->Value, 1) = receiveBuffer[1];
        IPC_GET_BYTE(data->Value, 0) = receiveBuffer[2];
    }

}

/* Message Major: QNX */
/* Receive function of sub message BootStatus */
void IPC_S2M_ClusterAppQNXBootStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXBootStatus_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Request, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message ADASConfig */
void IPC_S2M_ClusterAppQNXADASConfig_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXADASConfig_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->Request, 0) = receiveBuffer[0];
    }

}

/* Receive function of sub message SetADASConfig */
void IPC_S2M_ClusterAppQNXSetADASConfig_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXSetADASConfig_t *data, uint32_t payloadLength)
{
    uint8_t receiveBuffer[IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH] = {0};
    uint16_t bufIndex;
    if((receiveData != NULL) && (data != NULL))
    {
        if(payloadLength > IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH)
        {
            payloadLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH;
        }
        for(bufIndex = 0; bufIndex < payloadLength; bufIndex++)
        {
            receiveBuffer[bufIndex] = receiveData[bufIndex];
        }
        IPC_GET_BYTE(data->HighwayAssistSwitch, 0) = receiveBuffer[0];
        IPC_GET_BYTE(data->LaneChangeAssistSwitch, 0) = receiveBuffer[1];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
