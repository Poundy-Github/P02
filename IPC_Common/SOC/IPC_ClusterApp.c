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
 *     Description file:  IPC_SOC.c.tem
 *          Description:  IPC group ClusterApp source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/

#include "IPC_ClusterApp.h"

/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: ClusterApp */
/* Message Major: APP */
/* Pack function of sub message TT_Module */
int32_t IPC_M2S_ClusterAppAPPTT_Module_Pack(IPC_M2S_ClusterAppAPPTT_Module_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 23u; arrIndex++)
            {
                payload[5u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 3u);
                payload[6u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 2u);
                payload[7u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 1u);
                payload[8u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TT_Module */
int32_t IPC_M2S_ClusterAppAPPTT_Module_Parse(IPC_M2S_ClusterAppAPPTT_Module_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 23; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 3u) = receiveBuffer[0u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 2u) = receiveBuffer[1u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 1u) = receiveBuffer[2u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TT_Moduleu32Telltales_status_t.u32Telltales_status[arrIndex], 0u) = receiveBuffer[3u + arrIndex * 4u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WN_Module */
int32_t IPC_M2S_ClusterAppAPPWN_Module_Pack(IPC_M2S_ClusterAppAPPWN_Module_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 150u; arrIndex++)
            {
                payload[5u + arrIndex * 1u] = IPC_GET_BYTE(in_data->u_WN_Moduleu32Warning_status_t.u32Warning_status[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message WN_Module */
int32_t IPC_M2S_ClusterAppAPPWN_Module_Parse(IPC_M2S_ClusterAppAPPWN_Module_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 150; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_WN_Moduleu32Warning_status_t.u32Warning_status[arrIndex], 0u) = receiveBuffer[0u + arrIndex * 1u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Odo */
int32_t IPC_M2S_ClusterAppAPPOdo_Pack(IPC_M2S_ClusterAppAPPOdo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_ID;
        payload[5] = IPC_GET_BYTE(in_data->Value, 3);
        payload[6] = IPC_GET_BYTE(in_data->Value, 2);
        payload[7] = IPC_GET_BYTE(in_data->Value, 1);
        payload[8] = IPC_GET_BYTE(in_data->Value, 0);
        payload[9] = IPC_GET_BYTE(in_data->Uints, 0);
        payload[10] = IPC_GET_BYTE(in_data->Valid, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Odo */
int32_t IPC_M2S_ClusterAppAPPOdo_Parse(IPC_M2S_ClusterAppAPPOdo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Value, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Value, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Value, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Value, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->Uints, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->Valid, 0) = receiveBuffer[5];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SIA */
int32_t IPC_M2S_ClusterAppAPPSIA_Pack(IPC_M2S_ClusterAppAPPSIA_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_ID;
        payload[5] = IPC_GET_BYTE(in_data->Value, 3);
        payload[6] = IPC_GET_BYTE(in_data->Value, 2);
        payload[7] = IPC_GET_BYTE(in_data->Value, 1);
        payload[8] = IPC_GET_BYTE(in_data->Value, 0);
        payload[9] = IPC_GET_BYTE(in_data->Uints, 0);
        payload[10] = IPC_GET_BYTE(in_data->Valid, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message SIA */
int32_t IPC_M2S_ClusterAppAPPSIA_Parse(IPC_M2S_ClusterAppAPPSIA_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Value, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Value, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Value, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Value, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->Uints, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->Valid, 0) = receiveBuffer[5];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TPMS */
int32_t IPC_M2S_ClusterAppAPPTPMS_Pack(IPC_M2S_ClusterAppAPPTPMS_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 4u; arrIndex++)
            {
                payload[5u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 3u);
                payload[6u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 2u);
                payload[7u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 1u);
                payload[8u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TPMS */
int32_t IPC_M2S_ClusterAppAPPTPMS_Parse(IPC_M2S_ClusterAppAPPTPMS_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 3u) = receiveBuffer[0u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 2u) = receiveBuffer[1u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 1u) = receiveBuffer[2u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_TPMSTPMS_Inf_t.TPMS_Inf[arrIndex], 0u) = receiveBuffer[3u + arrIndex * 4u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Chime */
int32_t IPC_M2S_ClusterAppAPPChime_Pack(IPC_M2S_ClusterAppAPPChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_ID;
        payload[5] = IPC_GET_BYTE(in_data->SoundId, 0);
        payload[6] = IPC_GET_BYTE(in_data->Volume, 0);
        payload[7] = IPC_GET_BYTE(in_data->Operation, 0);
        payload[8] = IPC_GET_BYTE(in_data->Toggle, 0);
        payload[9] = IPC_GET_BYTE(in_data->RepeatTime, 3);
        payload[10] = IPC_GET_BYTE(in_data->RepeatTime, 2);
        payload[11] = IPC_GET_BYTE(in_data->RepeatTime, 1);
        payload[12] = IPC_GET_BYTE(in_data->RepeatTime, 0);
        payload[13] = IPC_GET_BYTE(in_data->Soundtrack, 3);
        payload[14] = IPC_GET_BYTE(in_data->Soundtrack, 2);
        payload[15] = IPC_GET_BYTE(in_data->Soundtrack, 1);
        payload[16] = IPC_GET_BYTE(in_data->Soundtrack, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Chime */
int32_t IPC_M2S_ClusterAppAPPChime_Parse(IPC_M2S_ClusterAppAPPChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->SoundId, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Volume, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Operation, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Toggle, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->RepeatTime, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->RepeatTime, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->RepeatTime, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->RepeatTime, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->Soundtrack, 3) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->Soundtrack, 2) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->Soundtrack, 1) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->Soundtrack, 0) = receiveBuffer[11];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TripComputer */
int32_t IPC_M2S_ClusterAppAPPTripComputer_Pack(IPC_M2S_ClusterAppAPPTripComputer_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[5u + arrIndex * 4u] = IPC_GET_BYTE(in_data->Trip[arrIndex], 3u);
                payload[6u + arrIndex * 4u] = IPC_GET_BYTE(in_data->Trip[arrIndex], 2u);
                payload[7u + arrIndex * 4u] = IPC_GET_BYTE(in_data->Trip[arrIndex], 1u);
                payload[8u + arrIndex * 4u] = IPC_GET_BYTE(in_data->Trip[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[13u + arrIndex * 2u] = IPC_GET_BYTE(in_data->AFE[arrIndex], 1u);
                payload[14u + arrIndex * 2u] = IPC_GET_BYTE(in_data->AFE[arrIndex], 0u);
            }
        }
        payload[17] = IPC_GET_BYTE(in_data->IFE, 3);
        payload[18] = IPC_GET_BYTE(in_data->IFE, 2);
        payload[19] = IPC_GET_BYTE(in_data->IFE, 1);
        payload[20] = IPC_GET_BYTE(in_data->IFE, 0);
        payload[21] = IPC_GET_BYTE(in_data->IFE_Unit, 0);
        payload[22] = IPC_GET_BYTE(in_data->DTE, 3);
        payload[23] = IPC_GET_BYTE(in_data->DTE, 2);
        payload[24] = IPC_GET_BYTE(in_data->DTE, 1);
        payload[25] = IPC_GET_BYTE(in_data->DTE, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[26u + arrIndex * 2u] = IPC_GET_BYTE(in_data->AVS[arrIndex], 1u);
                payload[27u + arrIndex * 2u] = IPC_GET_BYTE(in_data->AVS[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[30u + arrIndex * 1u] = IPC_GET_BYTE(in_data->Travel_time_Hour[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[32u + arrIndex * 1u] = IPC_GET_BYTE(in_data->Travel_time_MIN[arrIndex], 0u);
            }
        }
        payload[34] = IPC_GET_BYTE(in_data->DTE_AVS_Uint, 0);
        payload[35] = IPC_GET_BYTE(in_data->AFE_Uint, 0);
        payload[36] = IPC_GET_BYTE(in_data->Phev_Dte_Ipc, 1);
        payload[37] = IPC_GET_BYTE(in_data->Phev_Dte_Ipc, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[38u + arrIndex * 4u] = IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 3u);
                payload[39u + arrIndex * 4u] = IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 2u);
                payload[40u + arrIndex * 4u] = IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 1u);
                payload[41u + arrIndex * 4u] = IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TripComputer */
int32_t IPC_M2S_ClusterAppAPPTripComputer_Parse(IPC_M2S_ClusterAppAPPTripComputer_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->Trip[arrIndex], 3u) = receiveBuffer[0u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->Trip[arrIndex], 2u) = receiveBuffer[1u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->Trip[arrIndex], 1u) = receiveBuffer[2u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->Trip[arrIndex], 0u) = receiveBuffer[3u + arrIndex * 4u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->AFE[arrIndex], 1u) = receiveBuffer[8u + arrIndex * 2u];
                IPC_GET_BYTE(in_data->AFE[arrIndex], 0u) = receiveBuffer[9u + arrIndex * 2u];
            }
        }
        IPC_GET_BYTE(in_data->IFE, 3) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->IFE, 2) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->IFE, 1) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->IFE, 0) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->IFE_Unit, 0) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->DTE, 3) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->DTE, 2) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->DTE, 1) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->DTE, 0) = receiveBuffer[20];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->AVS[arrIndex], 1u) = receiveBuffer[21u + arrIndex * 2u];
                IPC_GET_BYTE(in_data->AVS[arrIndex], 0u) = receiveBuffer[22u + arrIndex * 2u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->Travel_time_Hour[arrIndex], 0u) = receiveBuffer[25u + arrIndex * 1u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->Travel_time_MIN[arrIndex], 0u) = receiveBuffer[27u + arrIndex * 1u];
            }
        }
        IPC_GET_BYTE(in_data->DTE_AVS_Uint, 0) = receiveBuffer[29];
        IPC_GET_BYTE(in_data->AFE_Uint, 0) = receiveBuffer[30];
        IPC_GET_BYTE(in_data->Phev_Dte_Ipc, 1) = receiveBuffer[31];
        IPC_GET_BYTE(in_data->Phev_Dte_Ipc, 0) = receiveBuffer[32];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 3u) = receiveBuffer[33u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 2u) = receiveBuffer[34u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 1u) = receiveBuffer[35u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->DTE_Dual[arrIndex], 0u) = receiveBuffer[36u + arrIndex * 4u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message FUEL */
int32_t IPC_M2S_ClusterAppAPPFUEL_Pack(IPC_M2S_ClusterAppAPPFUEL_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_ID;
        payload[5] = IPC_GET_BYTE(in_data->TankFuelLevelPercent, 1);
        payload[6] = IPC_GET_BYTE(in_data->TankFuelLevelPercent, 0);
        payload[7] = IPC_GET_BYTE(in_data->Tankportposition, 0);
        payload[8] = IPC_GET_BYTE(in_data->Low_fuel_warning, 0);
        payload[9] = IPC_GET_BYTE(in_data->LFW_Trigger_Ipc, 1);
        payload[10] = IPC_GET_BYTE(in_data->LFW_Trigger_Ipc, 0);
        payload[11] = IPC_GET_BYTE(in_data->LFW_Release_Ipc, 1);
        payload[12] = IPC_GET_BYTE(in_data->LFW_Release_Ipc, 0);
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[13u + arrIndex * 2u] = IPC_GET_BYTE(in_data->TankFuelLevelPercent_Dual[arrIndex], 1u);
                payload[14u + arrIndex * 2u] = IPC_GET_BYTE(in_data->TankFuelLevelPercent_Dual[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[17u + arrIndex * 1u] = IPC_GET_BYTE(in_data->Tankportposition_Dual[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[19u + arrIndex * 1u] = IPC_GET_BYTE(in_data->Low_fuel_warning_Dual[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[21u + arrIndex * 2u] = IPC_GET_BYTE(in_data->LFW_Trigger_Ipc_Dual[arrIndex], 1u);
                payload[22u + arrIndex * 2u] = IPC_GET_BYTE(in_data->LFW_Trigger_Ipc_Dual[arrIndex], 0u);
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 2u; arrIndex++)
            {
                payload[25u + arrIndex * 2u] = IPC_GET_BYTE(in_data->LFW_Release_Ipc_Dual[arrIndex], 1u);
                payload[26u + arrIndex * 2u] = IPC_GET_BYTE(in_data->LFW_Release_Ipc_Dual[arrIndex], 0u);
            }
        }
        payload[29] = IPC_GET_BYTE(in_data->OilBoxSplySts_Switch_Dual, 0);
        payload[30] = IPC_GET_BYTE(in_data->Fuel_Tank_System, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message FUEL */
int32_t IPC_M2S_ClusterAppAPPFUEL_Parse(IPC_M2S_ClusterAppAPPFUEL_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->TankFuelLevelPercent, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->TankFuelLevelPercent, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Tankportposition, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Low_fuel_warning, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->LFW_Trigger_Ipc, 1) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->LFW_Trigger_Ipc, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->LFW_Release_Ipc, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->LFW_Release_Ipc, 0) = receiveBuffer[7];
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->TankFuelLevelPercent_Dual[arrIndex], 1u) = receiveBuffer[8u + arrIndex * 2u];
                IPC_GET_BYTE(in_data->TankFuelLevelPercent_Dual[arrIndex], 0u) = receiveBuffer[9u + arrIndex * 2u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->Tankportposition_Dual[arrIndex], 0u) = receiveBuffer[12u + arrIndex * 1u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->Low_fuel_warning_Dual[arrIndex], 0u) = receiveBuffer[14u + arrIndex * 1u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->LFW_Trigger_Ipc_Dual[arrIndex], 1u) = receiveBuffer[16u + arrIndex * 2u];
                IPC_GET_BYTE(in_data->LFW_Trigger_Ipc_Dual[arrIndex], 0u) = receiveBuffer[17u + arrIndex * 2u];
            }
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 2; arrIndex++)
            {
                IPC_GET_BYTE(in_data->LFW_Release_Ipc_Dual[arrIndex], 1u) = receiveBuffer[20u + arrIndex * 2u];
                IPC_GET_BYTE(in_data->LFW_Release_Ipc_Dual[arrIndex], 0u) = receiveBuffer[21u + arrIndex * 2u];
            }
        }
        IPC_GET_BYTE(in_data->OilBoxSplySts_Switch_Dual, 0) = receiveBuffer[24];
        IPC_GET_BYTE(in_data->Fuel_Tank_System, 0) = receiveBuffer[25];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Speedo */
int32_t IPC_M2S_ClusterAppAPPSpeedo_Pack(IPC_M2S_ClusterAppAPPSpeedo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_ID;
        payload[5] = IPC_GET_BYTE(in_data->VehSpdCalculated, 3);
        payload[6] = IPC_GET_BYTE(in_data->VehSpdCalculated, 2);
        payload[7] = IPC_GET_BYTE(in_data->VehSpdCalculated, 1);
        payload[8] = IPC_GET_BYTE(in_data->VehSpdCalculated, 0);
        payload[9] = IPC_GET_BYTE(in_data->VehSpdReal, 3);
        payload[10] = IPC_GET_BYTE(in_data->VehSpdReal, 2);
        payload[11] = IPC_GET_BYTE(in_data->VehSpdReal, 1);
        payload[12] = IPC_GET_BYTE(in_data->VehSpdReal, 0);
        payload[13] = IPC_GET_BYTE(in_data->VehSpdMax, 3);
        payload[14] = IPC_GET_BYTE(in_data->VehSpdMax, 2);
        payload[15] = IPC_GET_BYTE(in_data->VehSpdMax, 1);
        payload[16] = IPC_GET_BYTE(in_data->VehSpdMax, 0);
        payload[17] = IPC_GET_BYTE(in_data->VehSpdUnit, 0);
        payload[18] = IPC_GET_BYTE(in_data->RedDispaly, 0);
        payload[19] = IPC_GET_BYTE(in_data->VehRunningSts, 0);
        payload[20] = IPC_GET_BYTE(in_data->VehSpdAnalog, 3);
        payload[21] = IPC_GET_BYTE(in_data->VehSpdAnalog, 2);
        payload[22] = IPC_GET_BYTE(in_data->VehSpdAnalog, 1);
        payload[23] = IPC_GET_BYTE(in_data->VehSpdAnalog, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Speedo */
int32_t IPC_M2S_ClusterAppAPPSpeedo_Parse(IPC_M2S_ClusterAppAPPSpeedo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->VehSpdCalculated, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->VehSpdCalculated, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->VehSpdCalculated, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->VehSpdCalculated, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->VehSpdReal, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->VehSpdReal, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->VehSpdReal, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->VehSpdReal, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->VehSpdMax, 3) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->VehSpdMax, 2) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->VehSpdMax, 1) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->VehSpdMax, 0) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->VehSpdUnit, 0) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->RedDispaly, 0) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->VehRunningSts, 0) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->VehSpdAnalog, 3) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->VehSpdAnalog, 2) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->VehSpdAnalog, 1) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->VehSpdAnalog, 0) = receiveBuffer[18];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Tacho */
int32_t IPC_M2S_ClusterAppAPPTacho_Pack(IPC_M2S_ClusterAppAPPTacho_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_ID;
        payload[5] = IPC_GET_BYTE(in_data->EngSpdCalculated, 3);
        payload[6] = IPC_GET_BYTE(in_data->EngSpdCalculated, 2);
        payload[7] = IPC_GET_BYTE(in_data->EngSpdCalculated, 1);
        payload[8] = IPC_GET_BYTE(in_data->EngSpdCalculated, 0);
        payload[9] = IPC_GET_BYTE(in_data->EngSpdMax, 3);
        payload[10] = IPC_GET_BYTE(in_data->EngSpdMax, 2);
        payload[11] = IPC_GET_BYTE(in_data->EngSpdMax, 1);
        payload[12] = IPC_GET_BYTE(in_data->EngSpdMax, 0);
        payload[13] = IPC_GET_BYTE(in_data->RedDispaly, 0);
        payload[14] = IPC_GET_BYTE(in_data->EngRunningSts, 0);
        payload[15] = IPC_GET_BYTE(in_data->RedZoneThreshold, 3);
        payload[16] = IPC_GET_BYTE(in_data->RedZoneThreshold, 2);
        payload[17] = IPC_GET_BYTE(in_data->RedZoneThreshold, 1);
        payload[18] = IPC_GET_BYTE(in_data->RedZoneThreshold, 0);
        payload[19] = IPC_GET_BYTE(in_data->EngSpdAnalog, 3);
        payload[20] = IPC_GET_BYTE(in_data->EngSpdAnalog, 2);
        payload[21] = IPC_GET_BYTE(in_data->EngSpdAnalog, 1);
        payload[22] = IPC_GET_BYTE(in_data->EngSpdAnalog, 0);
        payload[23] = IPC_GET_BYTE(in_data->EngSpdReal, 3);
        payload[24] = IPC_GET_BYTE(in_data->EngSpdReal, 2);
        payload[25] = IPC_GET_BYTE(in_data->EngSpdReal, 1);
        payload[26] = IPC_GET_BYTE(in_data->EngSpdReal, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Tacho */
int32_t IPC_M2S_ClusterAppAPPTacho_Parse(IPC_M2S_ClusterAppAPPTacho_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->EngSpdCalculated, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->EngSpdCalculated, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->EngSpdCalculated, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->EngSpdCalculated, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->EngSpdMax, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->EngSpdMax, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->EngSpdMax, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->EngSpdMax, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->RedDispaly, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->EngRunningSts, 0) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 3) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 2) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 1) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 0) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->EngSpdAnalog, 3) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->EngSpdAnalog, 2) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->EngSpdAnalog, 1) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->EngSpdAnalog, 0) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->EngSpdReal, 3) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->EngSpdReal, 2) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->EngSpdReal, 1) = receiveBuffer[20];
        IPC_GET_BYTE(in_data->EngSpdReal, 0) = receiveBuffer[21];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Coolant */
int32_t IPC_M2S_ClusterAppAPPCoolant_Pack(IPC_M2S_ClusterAppAPPCoolant_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_ID;
        payload[5] = IPC_GET_BYTE(in_data->EngCoolantTemp, 3);
        payload[6] = IPC_GET_BYTE(in_data->EngCoolantTemp, 2);
        payload[7] = IPC_GET_BYTE(in_data->EngCoolantTemp, 1);
        payload[8] = IPC_GET_BYTE(in_data->EngCoolantTemp, 0);
        payload[9] = IPC_GET_BYTE(in_data->RedDispaly, 0);
        payload[10] = IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 3);
        payload[11] = IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 2);
        payload[12] = IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 1);
        payload[13] = IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 0);
        payload[14] = IPC_GET_BYTE(in_data->RedZoneThreshold, 3);
        payload[15] = IPC_GET_BYTE(in_data->RedZoneThreshold, 2);
        payload[16] = IPC_GET_BYTE(in_data->RedZoneThreshold, 1);
        payload[17] = IPC_GET_BYTE(in_data->RedZoneThreshold, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message Coolant */
int32_t IPC_M2S_ClusterAppAPPCoolant_Parse(IPC_M2S_ClusterAppAPPCoolant_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->EngCoolantTemp, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->EngCoolantTemp, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->EngCoolantTemp, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->EngCoolantTemp, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->RedDispaly, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 3) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 2) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 1) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->EngCoolantTempPhysValue, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 3) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 2) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 1) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->RedZoneThreshold, 0) = receiveBuffer[12];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MenuSetting */
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Pack(IPC_M2S_ClusterAppAPPMenuSetting_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_ID;
        payload[5] = IPC_GET_BYTE(in_data->Sd_NaviLimitSpeed, 1);
        payload[6] = IPC_GET_BYTE(in_data->Sd_NaviLimitSpeed, 0);
        payload[7] = IPC_GET_BYTE(in_data->Sd_OverSpeedEnable, 0);
        payload[8] = IPC_GET_BYTE(in_data->Sd_Language, 0);
        payload[9] = IPC_GET_BYTE(in_data->Sd_ClusterTheme, 0);
        payload[10] = IPC_GET_BYTE(in_data->Sd_OdometerUnit, 0);
        payload[11] = IPC_GET_BYTE(in_data->Sd_TemperatureUnit, 0);
        payload[12] = IPC_GET_BYTE(in_data->Sd_TirePressureUnit, 0);
        payload[13] = IPC_GET_BYTE(in_data->Sd_TripComputerId, 0);
        payload[14] = IPC_GET_BYTE(in_data->Sd_InteractiveCarId, 0);
        payload[15] = IPC_GET_BYTE(in_data->Sd_DrivingModeMemorySwitch, 0);
        payload[16] = IPC_GET_BYTE(in_data->Sd_TimeUnit, 0);
        payload[17] = IPC_GET_BYTE(in_data->Sd_HighwayAssistSwitch, 0);
        payload[18] = IPC_GET_BYTE(in_data->Sd_LaneChangeAssistSwitch, 0);
        payload[19] = IPC_GET_BYTE(in_data->Sd_SunriseSunset_Mode, 0);
        payload[20] = IPC_GET_BYTE(in_data->Sd_Auto_Mode, 0);
        payload[21] = IPC_GET_BYTE(in_data->Sd_DrvgModeMemReq, 0);
        payload[22] = IPC_GET_BYTE(in_data->Sd_DrvingModReqHUT, 0);
        payload[23] = IPC_GET_BYTE(in_data->Sd_Switch_ThemeLinkage_Sts, 0);
        payload[24] = IPC_GET_BYTE(in_data->Sd_DataSyncFlg, 0);
        payload[25] = IPC_GET_BYTE(in_data->Sd_AtmosphereLampLinkageSwt_Sts, 0);
        payload[26] = IPC_GET_BYTE(in_data->Sd_SimSoundWaveLinkageSwt_Sts, 0);
        payload[27] = IPC_GET_BYTE(in_data->Sd_MaoCallLinkageSwt_Sts, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message MenuSetting */
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Parse(IPC_M2S_ClusterAppAPPMenuSetting_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Sd_NaviLimitSpeed, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Sd_NaviLimitSpeed, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Sd_OverSpeedEnable, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Sd_Language, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->Sd_ClusterTheme, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->Sd_OdometerUnit, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->Sd_TemperatureUnit, 0) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->Sd_TirePressureUnit, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->Sd_TripComputerId, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->Sd_InteractiveCarId, 0) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->Sd_DrivingModeMemorySwitch, 0) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->Sd_TimeUnit, 0) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->Sd_HighwayAssistSwitch, 0) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->Sd_LaneChangeAssistSwitch, 0) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->Sd_SunriseSunset_Mode, 0) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->Sd_Auto_Mode, 0) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->Sd_DrvgModeMemReq, 0) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->Sd_DrvingModReqHUT, 0) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->Sd_Switch_ThemeLinkage_Sts, 0) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->Sd_DataSyncFlg, 0) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->Sd_AtmosphereLampLinkageSwt_Sts, 0) = receiveBuffer[20];
        IPC_GET_BYTE(in_data->Sd_SimSoundWaveLinkageSwt_Sts, 0) = receiveBuffer[21];
        IPC_GET_BYTE(in_data->Sd_MaoCallLinkageSwt_Sts, 0) = receiveBuffer[22];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TCClearResult */
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Pack(IPC_M2S_ClusterAppAPPTCClearResult_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_ID;
        payload[5] = IPC_GET_BYTE(in_data->Result, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message TCClearResult */
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Parse(IPC_M2S_ClusterAppAPPTCClearResult_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Result, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ConfigData */
int32_t IPC_M2S_ClusterAppAPPConfigData_Pack(IPC_M2S_ClusterAppAPPConfigData_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_ID;
        payload[5] = IPC_GET_BYTE(in_data->Fast_Resp, 0);
        payload[6] = IPC_GET_BYTE(in_data->DigitalRPM_Hysteresis, 1);
        payload[7] = IPC_GET_BYTE(in_data->DigitalRPM_Hysteresis, 0);
        payload[8] = IPC_GET_BYTE(in_data->GasolineCoolant_C_point, 0);
        payload[9] = IPC_GET_BYTE(in_data->GasolineCoolant_14_point, 0);
        payload[10] = IPC_GET_BYTE(in_data->GasolineCoolant_12_point1, 0);
        payload[11] = IPC_GET_BYTE(in_data->GasolineCoolant_12_point2, 0);
        payload[12] = IPC_GET_BYTE(in_data->GasolineCoolant_4_point, 0);
        payload[13] = IPC_GET_BYTE(in_data->GasolineCoolant_Redline_point, 0);
        payload[14] = IPC_GET_BYTE(in_data->GasolineCoolant_H_point, 0);
        payload[15] = IPC_GET_BYTE(in_data->DieselCoolant_C_point, 0);
        payload[16] = IPC_GET_BYTE(in_data->DieselCoolant_14_point, 0);
        payload[17] = IPC_GET_BYTE(in_data->DieselCoolant_12_point1, 0);
        payload[18] = IPC_GET_BYTE(in_data->DieselCoolant_12_point2, 0);
        payload[19] = IPC_GET_BYTE(in_data->DieselCoolant_34_point, 0);
        payload[20] = IPC_GET_BYTE(in_data->DieselCoolant_Redline_point, 0);
        payload[21] = IPC_GET_BYTE(in_data->DieselCoolant_H_point, 0);
        payload[22] = IPC_GET_BYTE(in_data->Horizontal_data, 1);
        payload[23] = IPC_GET_BYTE(in_data->Horizontal_data, 0);
        payload[24] = IPC_GET_BYTE(in_data->X, 0);
        payload[25] = IPC_GET_BYTE(in_data->Y, 0);
        payload[26] = IPC_GET_BYTE(in_data->AVSBDisplayEnable, 0);
        payload[27] = IPC_GET_BYTE(in_data->AVSADisplayEnable, 0);
        payload[28] = IPC_GET_BYTE(in_data->TravelTimeADisplayEnable, 0);
        payload[29] = IPC_GET_BYTE(in_data->TravelTimeBDisplayEnable, 0);
        payload[30] = IPC_GET_BYTE(in_data->AFCADisplayEnable, 0);
        payload[31] = IPC_GET_BYTE(in_data->AFCBDisplayEnable, 0);
        payload[32] = IPC_GET_BYTE(in_data->IFCDisplayEnable, 0);
        payload[33] = IPC_GET_BYTE(in_data->DigitalSpeedDisplayEnable, 0);
        payload[34] = IPC_GET_BYTE(in_data->PHEV_HEVDTEDisplayEnable, 0);
        payload[35] = IPC_GET_BYTE(in_data->MaxDisplayPHEVRange, 0);
        payload[36] = IPC_GET_BYTE(in_data->PHEVSOCDisplayEnable, 0);
        payload[37] = IPC_GET_BYTE(in_data->RefreshRatePHEVSOC, 1);
        payload[38] = IPC_GET_BYTE(in_data->RefreshRatePHEVSOC, 0);
        payload[39] = IPC_GET_BYTE(in_data->AvailablePowerDisplayEnable, 0);
        payload[40] = IPC_GET_BYTE(in_data->MaxAvailablePower, 0);
        payload[41] = IPC_GET_BYTE(in_data->RefreshRateAvrgEgyCns, 1);
        payload[42] = IPC_GET_BYTE(in_data->RefreshRateAvrgEgyCns, 0);
        payload[43] = IPC_GET_BYTE(in_data->AvrgEgyCnsDisplayEnable, 0);
        payload[44] = IPC_GET_BYTE(in_data->MaxvalueAvrgEgyCns, 1);
        payload[45] = IPC_GET_BYTE(in_data->MaxvalueAvrgEgyCns, 0);
        payload[46] = IPC_GET_BYTE(in_data->RefreshRatemotorpower, 1);
        payload[47] = IPC_GET_BYTE(in_data->RefreshRatemotorpower, 0);
        payload[48] = IPC_GET_BYTE(in_data->motorpowerDisplayEnable, 0);
        payload[49] = IPC_GET_BYTE(in_data->RefreshRateEVSOC, 1);
        payload[50] = IPC_GET_BYTE(in_data->RefreshRateEVSOC, 0);
        payload[51] = IPC_GET_BYTE(in_data->EVSOCDisplayEnable, 0);
        payload[52] = IPC_GET_BYTE(in_data->RefreshRateEVDTE, 1);
        payload[53] = IPC_GET_BYTE(in_data->RefreshRateEVDTE, 0);
        payload[54] = IPC_GET_BYTE(in_data->EVDTEDisplayEnable, 0);
        payload[55] = IPC_GET_BYTE(in_data->MaxvalueEVDTE, 1);
        payload[56] = IPC_GET_BYTE(in_data->MaxvalueEVDTE, 0);
        payload[57] = IPC_GET_BYTE(in_data->RefreshRateCurrent, 1);
        payload[58] = IPC_GET_BYTE(in_data->RefreshRateCurrent, 0);
        payload[59] = IPC_GET_BYTE(in_data->EVCurrentDisplayEnable, 0);
        payload[60] = IPC_GET_BYTE(in_data->EVDrivDataARestTime, 0);
        payload[61] = IPC_GET_BYTE(in_data->RefreshRateEVAVS, 1);
        payload[62] = IPC_GET_BYTE(in_data->RefreshRateEVAVS, 0);
        payload[63] = IPC_GET_BYTE(in_data->EVAVSMinDistanceThresh, 0);
        payload[64] = IPC_GET_BYTE(in_data->EVAVSADisplayEnable, 0);
        payload[65] = IPC_GET_BYTE(in_data->EVAVSBDisplayEnable, 0);
        payload[66] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 7);
        payload[67] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 6);
        payload[68] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 5);
        payload[69] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 4);
        payload[70] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 3);
        payload[71] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 2);
        payload[72] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 1);
        payload[73] = IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 0);
        payload[74] = IPC_GET_BYTE(in_data->EVTravelTimeADisplayEnable, 0);
        payload[75] = IPC_GET_BYTE(in_data->EVTravelTimeBDisplayEnable, 0);
        payload[76] = IPC_GET_BYTE(in_data->DoortoRed_speedthreshold, 0);
        payload[77] = IPC_GET_BYTE(in_data->Doorallclosed_holdtime, 0);
        payload[78] = IPC_GET_BYTE(in_data->Telltale_interrupt_display_time, 0);
        payload[79] = IPC_GET_BYTE(in_data->Telltale_polling_display_time, 0);
        payload[80] = IPC_GET_BYTE(in_data->TPMSDisplayEnable, 0);
        payload[81] = IPC_GET_BYTE(in_data->FIXEDDISPLAY_1_ODO_ENABLE, 0);
        payload[82] = IPC_GET_BYTE(in_data->FD_003_CLOCK_ENABLE, 0);
        payload[83] = IPC_GET_BYTE(in_data->FD_009_DRIVE_MODE_2WD_ENABLE, 0);
        payload[84] = IPC_GET_BYTE(in_data->DrivDataADisplayEnable, 0);
        payload[85] = IPC_GET_BYTE(in_data->DrivDataBDisplayEnable, 0);
        payload[86] = IPC_GET_BYTE(in_data->Adas_V1, 1);
        payload[87] = IPC_GET_BYTE(in_data->Adas_V1, 0);
        payload[88] = IPC_GET_BYTE(in_data->Adas_V2, 1);
        payload[89] = IPC_GET_BYTE(in_data->Adas_V2, 0);
        payload[90] = IPC_GET_BYTE(in_data->GasolineCoolant_Distime, 0);
        payload[91] = IPC_GET_BYTE(in_data->DieselCoolant_Distime, 0);
        payload[92] = IPC_GET_BYTE(in_data->Fuel_Distime, 0);
        payload[93] = IPC_GET_BYTE(in_data->RefreshRateUrea, 1);
        payload[94] = IPC_GET_BYTE(in_data->RefreshRateUrea, 0);
        payload[95] = IPC_GET_BYTE(in_data->GValue_Hysteresis, 0);
        payload[96] = IPC_GET_BYTE(in_data->GValue_update_frequency, 1);
        payload[97] = IPC_GET_BYTE(in_data->GValue_update_frequency, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ConfigData */
int32_t IPC_M2S_ClusterAppAPPConfigData_Parse(IPC_M2S_ClusterAppAPPConfigData_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Fast_Resp, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->DigitalRPM_Hysteresis, 1) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->DigitalRPM_Hysteresis, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->GasolineCoolant_C_point, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->GasolineCoolant_14_point, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->GasolineCoolant_12_point1, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->GasolineCoolant_12_point2, 0) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->GasolineCoolant_4_point, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->GasolineCoolant_Redline_point, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->GasolineCoolant_H_point, 0) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->DieselCoolant_C_point, 0) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->DieselCoolant_14_point, 0) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->DieselCoolant_12_point1, 0) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->DieselCoolant_12_point2, 0) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->DieselCoolant_34_point, 0) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->DieselCoolant_Redline_point, 0) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->DieselCoolant_H_point, 0) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->Horizontal_data, 1) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->Horizontal_data, 0) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->X, 0) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->Y, 0) = receiveBuffer[20];
        IPC_GET_BYTE(in_data->AVSBDisplayEnable, 0) = receiveBuffer[21];
        IPC_GET_BYTE(in_data->AVSADisplayEnable, 0) = receiveBuffer[22];
        IPC_GET_BYTE(in_data->TravelTimeADisplayEnable, 0) = receiveBuffer[23];
        IPC_GET_BYTE(in_data->TravelTimeBDisplayEnable, 0) = receiveBuffer[24];
        IPC_GET_BYTE(in_data->AFCADisplayEnable, 0) = receiveBuffer[25];
        IPC_GET_BYTE(in_data->AFCBDisplayEnable, 0) = receiveBuffer[26];
        IPC_GET_BYTE(in_data->IFCDisplayEnable, 0) = receiveBuffer[27];
        IPC_GET_BYTE(in_data->DigitalSpeedDisplayEnable, 0) = receiveBuffer[28];
        IPC_GET_BYTE(in_data->PHEV_HEVDTEDisplayEnable, 0) = receiveBuffer[29];
        IPC_GET_BYTE(in_data->MaxDisplayPHEVRange, 0) = receiveBuffer[30];
        IPC_GET_BYTE(in_data->PHEVSOCDisplayEnable, 0) = receiveBuffer[31];
        IPC_GET_BYTE(in_data->RefreshRatePHEVSOC, 1) = receiveBuffer[32];
        IPC_GET_BYTE(in_data->RefreshRatePHEVSOC, 0) = receiveBuffer[33];
        IPC_GET_BYTE(in_data->AvailablePowerDisplayEnable, 0) = receiveBuffer[34];
        IPC_GET_BYTE(in_data->MaxAvailablePower, 0) = receiveBuffer[35];
        IPC_GET_BYTE(in_data->RefreshRateAvrgEgyCns, 1) = receiveBuffer[36];
        IPC_GET_BYTE(in_data->RefreshRateAvrgEgyCns, 0) = receiveBuffer[37];
        IPC_GET_BYTE(in_data->AvrgEgyCnsDisplayEnable, 0) = receiveBuffer[38];
        IPC_GET_BYTE(in_data->MaxvalueAvrgEgyCns, 1) = receiveBuffer[39];
        IPC_GET_BYTE(in_data->MaxvalueAvrgEgyCns, 0) = receiveBuffer[40];
        IPC_GET_BYTE(in_data->RefreshRatemotorpower, 1) = receiveBuffer[41];
        IPC_GET_BYTE(in_data->RefreshRatemotorpower, 0) = receiveBuffer[42];
        IPC_GET_BYTE(in_data->motorpowerDisplayEnable, 0) = receiveBuffer[43];
        IPC_GET_BYTE(in_data->RefreshRateEVSOC, 1) = receiveBuffer[44];
        IPC_GET_BYTE(in_data->RefreshRateEVSOC, 0) = receiveBuffer[45];
        IPC_GET_BYTE(in_data->EVSOCDisplayEnable, 0) = receiveBuffer[46];
        IPC_GET_BYTE(in_data->RefreshRateEVDTE, 1) = receiveBuffer[47];
        IPC_GET_BYTE(in_data->RefreshRateEVDTE, 0) = receiveBuffer[48];
        IPC_GET_BYTE(in_data->EVDTEDisplayEnable, 0) = receiveBuffer[49];
        IPC_GET_BYTE(in_data->MaxvalueEVDTE, 1) = receiveBuffer[50];
        IPC_GET_BYTE(in_data->MaxvalueEVDTE, 0) = receiveBuffer[51];
        IPC_GET_BYTE(in_data->RefreshRateCurrent, 1) = receiveBuffer[52];
        IPC_GET_BYTE(in_data->RefreshRateCurrent, 0) = receiveBuffer[53];
        IPC_GET_BYTE(in_data->EVCurrentDisplayEnable, 0) = receiveBuffer[54];
        IPC_GET_BYTE(in_data->EVDrivDataARestTime, 0) = receiveBuffer[55];
        IPC_GET_BYTE(in_data->RefreshRateEVAVS, 1) = receiveBuffer[56];
        IPC_GET_BYTE(in_data->RefreshRateEVAVS, 0) = receiveBuffer[57];
        IPC_GET_BYTE(in_data->EVAVSMinDistanceThresh, 0) = receiveBuffer[58];
        IPC_GET_BYTE(in_data->EVAVSADisplayEnable, 0) = receiveBuffer[59];
        IPC_GET_BYTE(in_data->EVAVSBDisplayEnable, 0) = receiveBuffer[60];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 7) = receiveBuffer[61];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 6) = receiveBuffer[62];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 5) = receiveBuffer[63];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 4) = receiveBuffer[64];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 3) = receiveBuffer[65];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 2) = receiveBuffer[66];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 1) = receiveBuffer[67];
        IPC_GET_BYTE(in_data->EVTravelTimeDisplayLimited, 0) = receiveBuffer[68];
        IPC_GET_BYTE(in_data->EVTravelTimeADisplayEnable, 0) = receiveBuffer[69];
        IPC_GET_BYTE(in_data->EVTravelTimeBDisplayEnable, 0) = receiveBuffer[70];
        IPC_GET_BYTE(in_data->DoortoRed_speedthreshold, 0) = receiveBuffer[71];
        IPC_GET_BYTE(in_data->Doorallclosed_holdtime, 0) = receiveBuffer[72];
        IPC_GET_BYTE(in_data->Telltale_interrupt_display_time, 0) = receiveBuffer[73];
        IPC_GET_BYTE(in_data->Telltale_polling_display_time, 0) = receiveBuffer[74];
        IPC_GET_BYTE(in_data->TPMSDisplayEnable, 0) = receiveBuffer[75];
        IPC_GET_BYTE(in_data->FIXEDDISPLAY_1_ODO_ENABLE, 0) = receiveBuffer[76];
        IPC_GET_BYTE(in_data->FD_003_CLOCK_ENABLE, 0) = receiveBuffer[77];
        IPC_GET_BYTE(in_data->FD_009_DRIVE_MODE_2WD_ENABLE, 0) = receiveBuffer[78];
        IPC_GET_BYTE(in_data->DrivDataADisplayEnable, 0) = receiveBuffer[79];
        IPC_GET_BYTE(in_data->DrivDataBDisplayEnable, 0) = receiveBuffer[80];
        IPC_GET_BYTE(in_data->Adas_V1, 1) = receiveBuffer[81];
        IPC_GET_BYTE(in_data->Adas_V1, 0) = receiveBuffer[82];
        IPC_GET_BYTE(in_data->Adas_V2, 1) = receiveBuffer[83];
        IPC_GET_BYTE(in_data->Adas_V2, 0) = receiveBuffer[84];
        IPC_GET_BYTE(in_data->GasolineCoolant_Distime, 0) = receiveBuffer[85];
        IPC_GET_BYTE(in_data->DieselCoolant_Distime, 0) = receiveBuffer[86];
        IPC_GET_BYTE(in_data->Fuel_Distime, 0) = receiveBuffer[87];
        IPC_GET_BYTE(in_data->RefreshRateUrea, 1) = receiveBuffer[88];
        IPC_GET_BYTE(in_data->RefreshRateUrea, 0) = receiveBuffer[89];
        IPC_GET_BYTE(in_data->GValue_Hysteresis, 0) = receiveBuffer[90];
        IPC_GET_BYTE(in_data->GValue_update_frequency, 1) = receiveBuffer[91];
        IPC_GET_BYTE(in_data->GValue_update_frequency, 0) = receiveBuffer[92];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message VConfig */
int32_t IPC_M2S_ClusterAppAPPVConfig_Pack(IPC_M2S_ClusterAppAPPVConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 9u; arrIndex++)
            {
                payload[5u + arrIndex * 1u] = IPC_GET_BYTE(in_data->u_VConfigu8VConfig_data_t.u8VConfig_data[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message VConfig */
int32_t IPC_M2S_ClusterAppAPPVConfig_Parse(IPC_M2S_ClusterAppAPPVConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 9; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_VConfigu8VConfig_data_t.u8VConfig_data[arrIndex], 0u) = receiveBuffer[0u + arrIndex * 1u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MenuTheme */
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Pack(IPC_M2S_ClusterAppAPPMenuTheme_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_ID;
        payload[5] = IPC_GET_BYTE(in_data->ThemeID, 3);
        payload[6] = IPC_GET_BYTE(in_data->ThemeID, 2);
        payload[7] = IPC_GET_BYTE(in_data->ThemeID, 1);
        payload[8] = IPC_GET_BYTE(in_data->ThemeID, 0);
        payload[9] = IPC_GET_BYTE(in_data->SkinID, 3);
        payload[10] = IPC_GET_BYTE(in_data->SkinID, 2);
        payload[11] = IPC_GET_BYTE(in_data->SkinID, 1);
        payload[12] = IPC_GET_BYTE(in_data->SkinID, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message MenuTheme */
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Parse(IPC_M2S_ClusterAppAPPMenuTheme_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->ThemeID, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->ThemeID, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->ThemeID, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->ThemeID, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->SkinID, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->SkinID, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->SkinID, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->SkinID, 0) = receiveBuffer[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message DriveMode */
int32_t IPC_M2S_ClusterAppAPPDriveMode_Pack(IPC_M2S_ClusterAppAPPDriveMode_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 6u; arrIndex++)
            {
                payload[5u + arrIndex * 1u] = IPC_GET_BYTE(in_data->u_DriveModeu8DriveMode_data_t.u8DriveMode_data[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message DriveMode */
int32_t IPC_M2S_ClusterAppAPPDriveMode_Parse(IPC_M2S_ClusterAppAPPDriveMode_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 6; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_DriveModeu8DriveMode_data_t.u8DriveMode_data[arrIndex], 0u) = receiveBuffer[0u + arrIndex * 1u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WN_Data */
int32_t IPC_M2S_ClusterAppAPPWN_Data_Pack(IPC_M2S_ClusterAppAPPWN_Data_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_ID;
        payload[5] = IPC_GET_BYTE(in_data->WN_TgtCrsSpd, 0);
        payload[6] = IPC_GET_BYTE(in_data->WN_TgtCrsSpdVldSts, 0);
        payload[7] = IPC_GET_BYTE(in_data->WN_DrvModeCaseValue, 0);
        payload[8] = IPC_GET_BYTE(in_data->WN_NOHDist, 1);
        payload[9] = IPC_GET_BYTE(in_data->WN_NOHDist, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message WN_Data */
int32_t IPC_M2S_ClusterAppAPPWN_Data_Parse(IPC_M2S_ClusterAppAPPWN_Data_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->WN_TgtCrsSpd, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->WN_TgtCrsSpdVldSts, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->WN_DrvModeCaseValue, 0) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->WN_NOHDist, 1) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->WN_NOHDist, 0) = receiveBuffer[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NewEnergy */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Pack(IPC_M2S_ClusterAppAPPNewEnergy_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 4u; arrIndex++)
            {
                payload[5u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 3u);
                payload[6u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 2u);
                payload[7u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 1u);
                payload[8u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message NewEnergy */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Parse(IPC_M2S_ClusterAppAPPNewEnergy_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 3u) = receiveBuffer[0u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 2u) = receiveBuffer[1u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 1u) = receiveBuffer[2u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergyu32NewEnergy_data_t.u32NewEnergy_data[arrIndex], 0u) = receiveBuffer[3u + arrIndex * 4u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message NewEnergy_EV */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Pack(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 6u; arrIndex++)
            {
                payload[5u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 3u);
                payload[6u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 2u);
                payload[7u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 1u);
                payload[8u + arrIndex * 4u] = IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 0u);
            }
        }
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message NewEnergy_EV */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Parse(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 6; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 3u) = receiveBuffer[0u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 2u) = receiveBuffer[1u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 1u) = receiveBuffer[2u + arrIndex * 4u];
                IPC_GET_BYTE(in_data->u_NewEnergy_EVu32NewEnergy_EV_data_t.u32NewEnergy_EV_data[arrIndex], 0u) = receiveBuffer[3u + arrIndex * 4u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message OffroadInfo */
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Pack(IPC_M2S_ClusterAppAPPOffroadInfo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_ID;
        payload[5] = IPC_GET_BYTE(in_data->Sd_BaroPressure, 1);
        payload[6] = IPC_GET_BYTE(in_data->Sd_BaroPressure, 0);
        payload[7] = IPC_GET_BYTE(in_data->Sd_Heilvl, 1);
        payload[8] = IPC_GET_BYTE(in_data->Sd_Heilvl, 0);
        payload[9] = IPC_GET_BYTE(in_data->Sd_HeilvlSign, 0);
        payload[10] = IPC_GET_BYTE(in_data->Sd_PitchAngle, 0);
        payload[11] = IPC_GET_BYTE(in_data->Sd_PitchAngleSign, 0);
        payload[12] = IPC_GET_BYTE(in_data->Sd_GeoGraphic, 0);
        payload[13] = IPC_GET_BYTE(in_data->Sd_SteerWheel, 0);
        payload[14] = IPC_GET_BYTE(in_data->Sd_SteerWheelSign, 0);
        totalLength = IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message OffroadInfo */
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Parse(IPC_M2S_ClusterAppAPPOffroadInfo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Sd_BaroPressure, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Sd_BaroPressure, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Sd_Heilvl, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Sd_Heilvl, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->Sd_HeilvlSign, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->Sd_PitchAngle, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->Sd_PitchAngleSign, 0) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->Sd_GeoGraphic, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->Sd_SteerWheel, 0) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->Sd_SteerWheelSign, 0) = receiveBuffer[9];
        ret = 0;
    }
    return ret;
}
/* Message Major: System */
/* Pack function of sub message BootCondition */
int32_t IPC_M2S_ClusterAppSystemBootCondition_Pack(IPC_M2S_ClusterAppSystemBootCondition_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_ID;
        payload[5] = IPC_GET_BYTE(in_data->Tach, 1);
        payload[6] = IPC_GET_BYTE(in_data->Tach, 0);
        payload[7] = IPC_GET_BYTE(in_data->Speed, 1);
        payload[8] = IPC_GET_BYTE(in_data->Speed, 0);
        payload[9] = IPC_GET_BYTE(in_data->Gear, 0);
        payload[10] = IPC_GET_BYTE(in_data->Handbrake, 0);
        payload[11] = IPC_GET_BYTE(in_data->EngineSts, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message BootCondition */
int32_t IPC_M2S_ClusterAppSystemBootCondition_Parse(IPC_M2S_ClusterAppSystemBootCondition_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Tach, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->Tach, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->Speed, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->Speed, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->Gear, 0) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->Handbrake, 0) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->EngineSts, 0) = receiveBuffer[6];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ADASConfig */
int32_t IPC_M2S_ClusterAppSystemADASConfig_Pack(IPC_M2S_ClusterAppSystemADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_ID;
        payload[5] = IPC_GET_BYTE(in_data->HighwayAssistSwitch, 0);
        payload[6] = IPC_GET_BYTE(in_data->LaneChangeAssistSwitch, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ADASConfig */
int32_t IPC_M2S_ClusterAppSystemADASConfig_Parse(IPC_M2S_ClusterAppSystemADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->HighwayAssistSwitch, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->LaneChangeAssistSwitch, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CLUSTERPOWER */
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Pack(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_ID;
        payload[5] = IPC_GET_BYTE(in_data->ClusterState, 0);
        payload[6] = IPC_GET_BYTE(in_data->VoltageState, 0);
        payload[7] = IPC_GET_BYTE(in_data->PowerChangedFlag, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message CLUSTERPOWER */
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Parse(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->ClusterState, 0) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->VoltageState, 0) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->PowerChangedFlag, 0) = receiveBuffer[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CommonAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Pack(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_ID;
        payload[5] = IPC_GET_BYTE(in_data->Status, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message CommonAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Parse(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Status, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IPCDebugTest */
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Pack(IPC_M2S_ClusterAppSystemIPCDebugTest_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_ID;
        payload[5] = IPC_GET_BYTE(in_data->Status, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IPCDebugTest */
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Parse(IPC_M2S_ClusterAppSystemIPCDebugTest_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Status, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message InterfaceAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Pack(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_ID;
        payload[5] = IPC_GET_BYTE(in_data->Status, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message InterfaceAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Parse(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Status, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message GaugeMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Pack(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_ID;
        payload[5] = IPC_GET_BYTE(in_data->Status, 0);
        totalLength = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message GaugeMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Parse(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->Status, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Message Major: CANAdapt */
/* Pack function of sub message CSA3_244 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Pack(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 0);
        payload[9] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message CSA3_244 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Parse(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_t.CSA3_244_Inf, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_CSA3_244CSA3_244_Inf_1_t.CSA3_244_Inf_1, 0) = receiveBuffer[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message EEM1_2A8 */
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Pack(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_EEM1_2A8EEM1_2A8_Inf_t.EEM1_2A8_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message EEM1_2A8 */
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Parse(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_EEM1_2A8EEM1_2A8_Inf_t.EEM1_2A8_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ESP2_145 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Pack(IPC_M2S_ClusterAppCANAdaptESP2_145_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ESP2_145ESP2_145_Inf_t.ESP2_145_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ESP2_145 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Parse(IPC_M2S_ClusterAppCANAdaptESP2_145_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ESP2_145ESP2_145_Inf_t.ESP2_145_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ESP2_137 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Pack(IPC_M2S_ClusterAppCANAdaptESP2_137_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ESP2_137 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Parse(IPC_M2S_ClusterAppCANAdaptESP2_137_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ESP2_137ESP2_137_Inf_t.ESP2_137_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HUD1_325 */
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Pack(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HUD1_325 */
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Parse(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_HUD1_325HUD1_325_t.HUD1_325, 0) = receiveBuffer[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ECM3_371 */
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Pack(IPC_M2S_ClusterAppCANAdaptECM3_371_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ECM3_371 */
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Parse(IPC_M2S_ClusterAppCANAdaptECM3_371_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ECM3_371ECM3_371_Inf_t.ECM3_371_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CSA2_A1 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Pack(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message CSA2_A1 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Parse(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_CSA2_A1CSA2_A1_Inf_t.CSA2_A1_Inf, 0) = receiveBuffer[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ECM16_2D4 */
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Pack(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 7);
        payload[6] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 6);
        payload[7] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 5);
        payload[8] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 4);
        payload[9] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ECM16_2D4 */
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Parse(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 7) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 6) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 5) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 4) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_ECM16_2D4ECM16_2D4_Inf_t.ECM16_2D4_Inf, 0) = receiveBuffer[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AC2_385 */
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Pack(IPC_M2S_ClusterAppCANAdaptAC2_385_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AC2_385 */
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Parse(IPC_M2S_ClusterAppCANAdaptAC2_385_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_AC2_385AC2_385_Inf_t.AC2_385_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ECM_PT6_290 */
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Pack(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ECM_PT6_290 */
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Parse(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_ECM_PT6_290ECM_PT6_290_Inf_t.ECM_PT6_290_Inf, 0) = receiveBuffer[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ABM2_245 */
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Pack(IPC_M2S_ClusterAppCANAdaptABM2_245_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 7);
        payload[6] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 6);
        payload[7] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 5);
        payload[8] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 4);
        payload[9] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ABM2_245 */
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Parse(IPC_M2S_ClusterAppCANAdaptABM2_245_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 7) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 6) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 5) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 4) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_ABM2_245ABM2_245_Inf_t.ABM2_245_Inf, 0) = receiveBuffer[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message RSDS_FD1_16F */
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Pack(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message RSDS_FD1_16F */
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Parse(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.RSDS_FD1_16F_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IFC_FD5_19F */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 0);
        payload[9] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 0);
        payload[13] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 3);
        payload[14] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 2);
        payload[15] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 1);
        payload[16] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 0);
        payload[17] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 3);
        payload[18] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 2);
        payload[19] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 1);
        payload[20] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 0);
        payload[21] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 3);
        payload[22] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 2);
        payload[23] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 1);
        payload[24] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 0);
        payload[25] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 3);
        payload[26] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 2);
        payload[27] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 1);
        payload[28] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 0);
        payload[29] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 3);
        payload[30] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 2);
        payload[31] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 1);
        payload[32] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 0);
        payload[33] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 7);
        payload[34] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 6);
        payload[35] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 5);
        payload[36] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 4);
        payload[37] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 3);
        payload[38] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 2);
        payload[39] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 1);
        payload[40] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 0);
        payload[41] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 7);
        payload[42] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 6);
        payload[43] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 5);
        payload[44] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 4);
        payload[45] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 3);
        payload[46] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 2);
        payload[47] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 1);
        payload[48] = IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IFC_FD5_19F */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.IFC_FD5_19F_Inf_1, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.IFC_FD5_19F_Inf_2, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 3) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 2) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 1) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.IFC_FD5_19F_Inf_3, 0) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 3) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 2) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 1) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.IFC_FD5_19F_Inf_4, 0) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 3) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 2) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 1) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.IFC_FD5_19F_Inf_5, 0) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 3) = receiveBuffer[20];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 2) = receiveBuffer[21];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 1) = receiveBuffer[22];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.IFC_FD5_19F_Inf_6, 0) = receiveBuffer[23];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 3) = receiveBuffer[24];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 2) = receiveBuffer[25];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 1) = receiveBuffer[26];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.IFC_FD5_19F_Inf_7, 0) = receiveBuffer[27];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 7) = receiveBuffer[28];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 6) = receiveBuffer[29];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 5) = receiveBuffer[30];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 4) = receiveBuffer[31];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 3) = receiveBuffer[32];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 2) = receiveBuffer[33];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 1) = receiveBuffer[34];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.IFC_FD5_19F_Inf_8, 0) = receiveBuffer[35];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 7) = receiveBuffer[36];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 6) = receiveBuffer[37];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 5) = receiveBuffer[38];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 4) = receiveBuffer[39];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 3) = receiveBuffer[40];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 2) = receiveBuffer[41];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 1) = receiveBuffer[42];
        IPC_GET_BYTE(in_data->u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.IFC_FD5_19F_Inf_9, 0) = receiveBuffer[43];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IFC_FD6_222 */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 7);
        payload[6] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 6);
        payload[7] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 5);
        payload[8] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 4);
        payload[9] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IFC_FD6_222 */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 7) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 6) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 5) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 4) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_IFC_FD6_222IFC_FD6_222_Inf_t.IFC_FD6_222_Inf, 0) = receiveBuffer[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ACC_FD2_2AB */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Pack(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 0);
        payload[9] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 0);
        payload[13] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 3);
        payload[14] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 2);
        payload[15] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 1);
        payload[16] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 0);
        payload[17] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 3);
        payload[18] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 2);
        payload[19] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 1);
        payload[20] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 0);
        payload[21] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 3);
        payload[22] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 2);
        payload[23] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 1);
        payload[24] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 0);
        payload[25] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 3);
        payload[26] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 2);
        payload[27] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 1);
        payload[28] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 0);
        payload[29] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 3);
        payload[30] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 2);
        payload[31] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 1);
        payload[32] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 0);
        payload[33] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 7);
        payload[34] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 6);
        payload[35] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 5);
        payload[36] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 4);
        payload[37] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 3);
        payload[38] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 2);
        payload[39] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 1);
        payload[40] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 0);
        payload[41] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 7);
        payload[42] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 6);
        payload[43] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 5);
        payload[44] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 4);
        payload[45] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 3);
        payload[46] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 2);
        payload[47] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 1);
        payload[48] = IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ACC_FD2_2AB */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Parse(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_Inf_1, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.ACC_FD2_2AB_Inf_2, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 3) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 2) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 1) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.ACC_FD2_2AB_Inf_3, 0) = receiveBuffer[11];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 3) = receiveBuffer[12];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 2) = receiveBuffer[13];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 1) = receiveBuffer[14];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.ACC_FD2_2AB_Inf_4, 0) = receiveBuffer[15];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 3) = receiveBuffer[16];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 2) = receiveBuffer[17];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 1) = receiveBuffer[18];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.ACC_FD2_2AB_Inf_5, 0) = receiveBuffer[19];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 3) = receiveBuffer[20];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 2) = receiveBuffer[21];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 1) = receiveBuffer[22];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.ACC_FD2_2AB_Inf_6, 0) = receiveBuffer[23];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 3) = receiveBuffer[24];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 2) = receiveBuffer[25];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 1) = receiveBuffer[26];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.ACC_FD2_2AB_Inf_7, 0) = receiveBuffer[27];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 7) = receiveBuffer[28];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 6) = receiveBuffer[29];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 5) = receiveBuffer[30];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 4) = receiveBuffer[31];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 3) = receiveBuffer[32];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 2) = receiveBuffer[33];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 1) = receiveBuffer[34];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.ACC_FD2_2AB_Inf_8, 0) = receiveBuffer[35];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 7) = receiveBuffer[36];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 6) = receiveBuffer[37];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 5) = receiveBuffer[38];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 4) = receiveBuffer[39];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 3) = receiveBuffer[40];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 2) = receiveBuffer[41];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 1) = receiveBuffer[42];
        IPC_GET_BYTE(in_data->u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.ACC_FD2_2AB_Inf_9, 0) = receiveBuffer[43];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IFC_FD2_23D */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IFC_FD2_23D */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_IFC_FD2_23DIFC_FD2_23D_Inf_t.IFC_FD2_23D_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AEB_FD2_227 */
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Pack(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 0);
        payload[9] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 0);
        payload[13] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 3);
        payload[14] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 2);
        payload[15] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 1);
        payload[16] = IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message AEB_FD2_227 */
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Parse(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_t.AEB_FD2_227_Inf, 0) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_2_t.AEB_FD2_227_Inf_2, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 3) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 2) = receiveBuffer[9];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 1) = receiveBuffer[10];
        IPC_GET_BYTE(in_data->u_AEB_FD2_227AEB_FD2_227_Inf_3_t.AEB_FD2_227_Inf_3, 0) = receiveBuffer[11];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CR_FD1_15E */
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Pack(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_CR_FD1_15ECR_FD1_15E_Inf_t.CR_FD1_15E_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message CR_FD1_15E */
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Parse(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_CR_FD1_15ECR_FD1_15E_Inf_t.CR_FD1_15E_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message IFC_FD3_2CF */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 7);
        payload[6] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 6);
        payload[7] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 5);
        payload[8] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 4);
        payload[9] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 3);
        payload[10] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 2);
        payload[11] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 1);
        payload[12] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 0);
        payload[13] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 1);
        payload[14] = IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message IFC_FD3_2CF */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 7) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 6) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 5) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 4) = receiveBuffer[3];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 3) = receiveBuffer[4];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 2) = receiveBuffer[5];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 1) = receiveBuffer[6];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.IFC_FD3_2CF_Inf, 0) = receiveBuffer[7];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 1) = receiveBuffer[8];
        IPC_GET_BYTE(in_data->u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.IFC_FD3_2CF_Inf_1, 0) = receiveBuffer[9];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ACC_FD3_2B4 */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Pack(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ACC_FD3_2B4 */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Parse(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message BCM1_319 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Pack(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_BCM1_319BCM1_319_Inf_t.BCM1_319_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message BCM1_319 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Parse(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_BCM1_319BCM1_319_Inf_t.BCM1_319_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message BCM3_345 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Pack(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_BCM3_345BCM3_345_Inf_t.BCM3_345_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message BCM3_345 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Parse(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_BCM3_345BCM3_345_Inf_t.BCM3_345_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message T_Box_FD10_2F0 */
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Pack(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.T_Box_FD10_2F0_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message T_Box_FD10_2F0 */
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Parse(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.T_Box_FD10_2F0_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ECM24_350 */
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Pack(IPC_M2S_ClusterAppCANAdaptECM24_350_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 3);
        payload[6] = IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 2);
        payload[7] = IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 1);
        payload[8] = IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ECM24_350 */
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Parse(IPC_M2S_ClusterAppCANAdaptECM24_350_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 3) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 2) = receiveBuffer[1];
        IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 1) = receiveBuffer[2];
        IPC_GET_BYTE(in_data->u_ECM24_350ECM24_350_Inf_t.ECM24_350_Inf, 0) = receiveBuffer[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message BCM12_238 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Pack(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message BCM12_238 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Parse(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_BCM12_238BCM12_238_Inf_t.BCM12_238_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message F_PBOX1_19B */
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Pack(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message F_PBOX1_19B */
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Parse(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_F_PBOX1_19BF_PBOX1_19B_Inf_t.F_PBOX1_19B_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HCM_L2_304 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Pack(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_HCM_L2_304HCM_L2_304_Inf_t.HCM_L2_304_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HCM_L2_304 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Parse(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_HCM_L2_304HCM_L2_304_Inf_t.HCM_L2_304_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message VCU_FD41_2D6 */
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Pack(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 1);
        payload[6] = IPC_GET_BYTE(in_data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message VCU_FD41_2D6 */
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Parse(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 1) = receiveBuffer[0];
        IPC_GET_BYTE(in_data->u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t.VCU_FD41_2D6_Inf, 0) = receiveBuffer[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HCM_R2_330 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Pack(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_HCM_R2_330HCM_R2_330_Inf_t.HCM_R2_330_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message HCM_R2_330 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Parse(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_HCM_R2_330HCM_R2_330_Inf_t.HCM_R2_330_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ESP1_149 */
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Pack(IPC_M2S_ClusterAppCANAdaptESP1_149_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID;
        payload[4] = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_ID;
        payload[5] = IPC_GET_BYTE(in_data->u_ESP1_149ESP1_149_Inf_t.ESP1_149_Inf, 0);
        totalLength = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}

/* Parse function of sub message ESP1_149 */
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Parse(IPC_M2S_ClusterAppCANAdaptESP1_149_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint8_t receiveBuffer[IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH] = {0};
    uint16_t bufIndex;
    if((payload != NULL) && (in_data != NULL))
    {
        if(length > IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH)
        {
            length = IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH;
        }
        for(bufIndex = 0;bufIndex < length;bufIndex ++)
        {
            receiveBuffer[bufIndex] = payload[bufIndex];
        }
        IPC_GET_BYTE(in_data->u_ESP1_149ESP1_149_Inf_t.ESP1_149_Inf, 0) = receiveBuffer[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message WrnId */
int32_t IPC_S2M_ClusterAppClusterSocWrnId_Pack(IPC_S2M_ClusterAppClusterSocWrnId_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_ID;
        payload[5] = IPC_GET_BYTE(in_data->General, 1);
        payload[6] = IPC_GET_BYTE(in_data->General, 0);
        payload[7] = IPC_GET_BYTE(in_data->GeneralShied, 1);
        payload[8] = IPC_GET_BYTE(in_data->GeneralShied, 0);
        payload[9] = IPC_GET_BYTE(in_data->GeneralBit, 1);
        payload[10] = IPC_GET_BYTE(in_data->GeneralBit, 0);
        payload[11] = IPC_GET_BYTE(in_data->Adas, 1);
        payload[12] = IPC_GET_BYTE(in_data->Adas, 0);
        payload[13] = IPC_GET_BYTE(in_data->AdasFault, 0);
        payload[14] = IPC_GET_BYTE(in_data->u_WrnIdFirstDisplayFlag_t.FirstDisplayFlag, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message WrnId */
int32_t IPC_S2M_ClusterAppClusterSocWrnId_Parse(IPC_S2M_ClusterAppClusterSocWrnId_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->General, 1) = payload[0];
        IPC_GET_BYTE(in_data->General, 0) = payload[1];
        IPC_GET_BYTE(in_data->GeneralShied, 1) = payload[2];
        IPC_GET_BYTE(in_data->GeneralShied, 0) = payload[3];
        IPC_GET_BYTE(in_data->GeneralBit, 1) = payload[4];
        IPC_GET_BYTE(in_data->GeneralBit, 0) = payload[5];
        IPC_GET_BYTE(in_data->Adas, 1) = payload[6];
        IPC_GET_BYTE(in_data->Adas, 0) = payload[7];
        IPC_GET_BYTE(in_data->AdasFault, 0) = payload[8];
        IPC_GET_BYTE(in_data->u_WrnIdFirstDisplayFlag_t.FirstDisplayFlag, 0) = payload[9];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TTStatus */
int32_t IPC_S2M_ClusterAppClusterSocTTStatus_Pack(IPC_S2M_ClusterAppClusterSocTTStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 6u; arrIndex++)
            {
                payload[5u + arrIndex * 1u] = IPC_GET_BYTE(in_data->u_TTStatusu32Telltales_status_t.u32Telltales_status[arrIndex], 0u);
            }
        }
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message TTStatus */
int32_t IPC_S2M_ClusterAppClusterSocTTStatus_Parse(IPC_S2M_ClusterAppClusterSocTTStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 6; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_TTStatusu32Telltales_status_t.u32Telltales_status[arrIndex], 0u) = payload[0u + arrIndex * 1u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message AdasStatus */
int32_t IPC_S2M_ClusterAppClusterSocAdasStatus_Pack(IPC_S2M_ClusterAppClusterSocAdasStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 4u; arrIndex++)
            {
                payload[5u + arrIndex * 1u] = IPC_GET_BYTE(in_data->u_AdasStatusAdasWarn_t.AdasWarn[arrIndex], 0u);
            }
        }
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message AdasStatus */
int32_t IPC_S2M_ClusterAppClusterSocAdasStatus_Parse(IPC_S2M_ClusterAppClusterSocAdasStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH == length))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0u; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(in_data->u_AdasStatusAdasWarn_t.AdasWarn[arrIndex], 0u) = payload[0u + arrIndex * 1u];
            }
        }
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message BackChime */
int32_t IPC_S2M_ClusterAppClusterSocBackChime_Pack(IPC_S2M_ClusterAppClusterSocBackChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_ID;
        payload[5] = IPC_GET_BYTE(in_data->CurId, 0);
        payload[6] = IPC_GET_BYTE(in_data->LastRepeat, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message BackChime */
int32_t IPC_S2M_ClusterAppClusterSocBackChime_Parse(IPC_S2M_ClusterAppClusterSocBackChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->CurId, 0) = payload[0];
        IPC_GET_BYTE(in_data->LastRepeat, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TCClear */
int32_t IPC_S2M_ClusterAppClusterSocTCClear_Pack(IPC_S2M_ClusterAppClusterSocTCClear_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_ID;
        payload[5] = IPC_GET_BYTE(in_data->MenuResrt, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message TCClear */
int32_t IPC_S2M_ClusterAppClusterSocTCClear_Parse(IPC_S2M_ClusterAppClusterSocTCClear_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->MenuResrt, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message TtToChime */
int32_t IPC_S2M_ClusterAppClusterSocTtToChime_Pack(IPC_S2M_ClusterAppClusterSocTtToChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_ID;
        payload[5] = IPC_GET_BYTE(in_data->TtFlash, 0);
        payload[6] = IPC_GET_BYTE(in_data->TtFlashTick, 3);
        payload[7] = IPC_GET_BYTE(in_data->TtFlashTick, 2);
        payload[8] = IPC_GET_BYTE(in_data->TtFlashTick, 1);
        payload[9] = IPC_GET_BYTE(in_data->TtFlashTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message TtToChime */
int32_t IPC_S2M_ClusterAppClusterSocTtToChime_Parse(IPC_S2M_ClusterAppClusterSocTtToChime_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->TtFlash, 0) = payload[0];
        IPC_GET_BYTE(in_data->TtFlashTick, 3) = payload[1];
        IPC_GET_BYTE(in_data->TtFlashTick, 2) = payload[2];
        IPC_GET_BYTE(in_data->TtFlashTick, 1) = payload[3];
        IPC_GET_BYTE(in_data->TtFlashTick, 0) = payload[4];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message CommonAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocCommonAppAlive_Pack(IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_ID;
        payload[5] = IPC_GET_BYTE(in_data->AliveTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message CommonAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocCommonAppAlive_Parse(IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MenuSetting */
int32_t IPC_S2M_ClusterAppClusterSocMenuSetting_Pack(IPC_S2M_ClusterAppClusterSocMenuSetting_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_ID;
        payload[5] = IPC_GET_BYTE(in_data->ID, 0);
        payload[6] = IPC_GET_BYTE(in_data->Value, 1);
        payload[7] = IPC_GET_BYTE(in_data->Value, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message MenuSetting */
int32_t IPC_S2M_ClusterAppClusterSocMenuSetting_Parse(IPC_S2M_ClusterAppClusterSocMenuSetting_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->ID, 0) = payload[0];
        IPC_GET_BYTE(in_data->Value, 1) = payload[1];
        IPC_GET_BYTE(in_data->Value, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message Gauges */
int32_t IPC_S2M_ClusterAppClusterSocGauges_Pack(IPC_S2M_ClusterAppClusterSocGauges_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_ID;
        payload[5] = IPC_GET_BYTE(in_data->VehicleSpeed, 1);
        payload[6] = IPC_GET_BYTE(in_data->VehicleSpeed, 0);
        payload[7] = IPC_GET_BYTE(in_data->EngineSpeed, 1);
        payload[8] = IPC_GET_BYTE(in_data->EngineSpeed, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message Gauges */
int32_t IPC_S2M_ClusterAppClusterSocGauges_Parse(IPC_S2M_ClusterAppClusterSocGauges_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->VehicleSpeed, 1) = payload[0];
        IPC_GET_BYTE(in_data->VehicleSpeed, 0) = payload[1];
        IPC_GET_BYTE(in_data->EngineSpeed, 1) = payload[2];
        IPC_GET_BYTE(in_data->EngineSpeed, 0) = payload[3];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message InterfaceAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Pack(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_ID;
        payload[5] = IPC_GET_BYTE(in_data->AliveTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message InterfaceAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Parse(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HMIPowerMode */
int32_t IPC_S2M_ClusterAppClusterSocHMIPowerMode_Pack(IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_ID;
        payload[5] = IPC_GET_BYTE(in_data->PowerStatus, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message HMIPowerMode */
int32_t IPC_S2M_ClusterAppClusterSocHMIPowerMode_Parse(IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->PowerStatus, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message GaugesAlive */
int32_t IPC_S2M_ClusterAppClusterSocGaugesAlive_Pack(IPC_S2M_ClusterAppClusterSocGaugesAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_ID;
        payload[5] = IPC_GET_BYTE(in_data->AliveTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message GaugesAlive */
int32_t IPC_S2M_ClusterAppClusterSocGaugesAlive_Parse(IPC_S2M_ClusterAppClusterSocGaugesAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ChimeClientAlive */
int32_t IPC_S2M_ClusterAppClusterSocChimeClientAlive_Pack(IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_ID;
        payload[5] = IPC_GET_BYTE(in_data->AliveTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ChimeClientAlive */
int32_t IPC_S2M_ClusterAppClusterSocChimeClientAlive_Parse(IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MenuTheme */
int32_t IPC_S2M_ClusterAppClusterSocMenuTheme_Pack(IPC_S2M_ClusterAppClusterSocMenuTheme_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_ID;
        payload[5] = IPC_GET_BYTE(in_data->Rc_ThemeID, 3);
        payload[6] = IPC_GET_BYTE(in_data->Rc_ThemeID, 2);
        payload[7] = IPC_GET_BYTE(in_data->Rc_ThemeID, 1);
        payload[8] = IPC_GET_BYTE(in_data->Rc_ThemeID, 0);
        payload[9] = IPC_GET_BYTE(in_data->Rc_SkinID, 3);
        payload[10] = IPC_GET_BYTE(in_data->Rc_SkinID, 2);
        payload[11] = IPC_GET_BYTE(in_data->Rc_SkinID, 1);
        payload[12] = IPC_GET_BYTE(in_data->Rc_SkinID, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message MenuTheme */
int32_t IPC_S2M_ClusterAppClusterSocMenuTheme_Parse(IPC_S2M_ClusterAppClusterSocMenuTheme_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Rc_ThemeID, 3) = payload[0];
        IPC_GET_BYTE(in_data->Rc_ThemeID, 2) = payload[1];
        IPC_GET_BYTE(in_data->Rc_ThemeID, 1) = payload[2];
        IPC_GET_BYTE(in_data->Rc_ThemeID, 0) = payload[3];
        IPC_GET_BYTE(in_data->Rc_SkinID, 3) = payload[4];
        IPC_GET_BYTE(in_data->Rc_SkinID, 2) = payload[5];
        IPC_GET_BYTE(in_data->Rc_SkinID, 1) = payload[6];
        IPC_GET_BYTE(in_data->Rc_SkinID, 0) = payload[7];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message HMISafety */
int32_t IPC_S2M_ClusterAppClusterSocHMISafety_Pack(IPC_S2M_ClusterAppClusterSocHMISafety_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_ID;
        payload[5] = IPC_GET_BYTE(in_data->AliveTick, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message HMISafety */
int32_t IPC_S2M_ClusterAppClusterSocHMISafety_Parse(IPC_S2M_ClusterAppClusterSocHMISafety_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->AliveTick, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message MiaoCALL */
int32_t IPC_S2M_ClusterAppClusterSocMiaoCALL_Pack(IPC_S2M_ClusterAppClusterSocMiaoCALL_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_ID;
        payload[5] = IPC_GET_BYTE(in_data->MiaoCALLsts, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message MiaoCALL */
int32_t IPC_S2M_ClusterAppClusterSocMiaoCALL_Parse(IPC_S2M_ClusterAppClusterSocMiaoCALL_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->MiaoCALLsts, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message OffroadInfo */
int32_t IPC_S2M_ClusterAppClusterSocOffroadInfo_Pack(IPC_S2M_ClusterAppClusterSocOffroadInfo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_ID;
        payload[5] = IPC_GET_BYTE(in_data->ID, 0);
        payload[6] = IPC_GET_BYTE(in_data->Value, 1);
        payload[7] = IPC_GET_BYTE(in_data->Value, 0);
        totalLength = IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message OffroadInfo */
int32_t IPC_S2M_ClusterAppClusterSocOffroadInfo_Parse(IPC_S2M_ClusterAppClusterSocOffroadInfo_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->ID, 0) = payload[0];
        IPC_GET_BYTE(in_data->Value, 1) = payload[1];
        IPC_GET_BYTE(in_data->Value, 0) = payload[2];
        ret = 0;
    }
    return ret;
}
/* Message Major: QNX */
/* Pack function of sub message BootStatus */
int32_t IPC_S2M_ClusterAppQNXBootStatus_Pack(IPC_S2M_ClusterAppQNXBootStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_ID;
        payload[5] = IPC_GET_BYTE(in_data->Request, 0);
        totalLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message BootStatus */
int32_t IPC_S2M_ClusterAppQNXBootStatus_Parse(IPC_S2M_ClusterAppQNXBootStatus_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message ADASConfig */
int32_t IPC_S2M_ClusterAppQNXADASConfig_Pack(IPC_S2M_ClusterAppQNXADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_ID;
        payload[5] = IPC_GET_BYTE(in_data->Request, 0);
        totalLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message ADASConfig */
int32_t IPC_S2M_ClusterAppQNXADASConfig_Parse(IPC_S2M_ClusterAppQNXADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->Request, 0) = payload[0];
        ret = 0;
    }
    return ret;
}
/* Pack function of sub message SetADASConfig */
int32_t IPC_S2M_ClusterAppQNXSetADASConfig_Pack(IPC_S2M_ClusterAppQNXSetADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    uint16_t totalLength;

    if((in_data != NULL) && (payload != NULL) &&
        (length >= IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH))
    {
        payload[2] = IPC_GROUP_CLUSTERAPP_ID;
        payload[3] = IPC_S2M_CLUSTERAPP_MSGMAJOR_QNX_ID;
        payload[4] = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_ID;
        payload[5] = IPC_GET_BYTE(in_data->HighwayAssistSwitch, 0);
        payload[6] = IPC_GET_BYTE(in_data->LaneChangeAssistSwitch, 0);
        totalLength = IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH + 5u;
        payload[0] = (uint8_t)(totalLength >> 8u);
        payload[1] = (uint8_t)(totalLength);
        ret = (int32_t)totalLength;
    }
    return ret;
}
/* Parse function of sub message SetADASConfig */
int32_t IPC_S2M_ClusterAppQNXSetADASConfig_Parse(IPC_S2M_ClusterAppQNXSetADASConfig_t *in_data, uint8_t *payload, uint16_t length)
{
    int32_t ret = -1;
    if((payload != NULL) && (in_data != NULL) &&
        (IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH == length))
    {
        IPC_GET_BYTE(in_data->HighwayAssistSwitch, 0) = payload[0];
        IPC_GET_BYTE(in_data->LaneChangeAssistSwitch, 0) = payload[1];
        ret = 0;
    }
    return ret;
}
