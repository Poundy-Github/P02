/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
 *  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *                 File:  IPC_Dedicated.c
 *            Generator:  IPC Code Generator V1.3.0
 *     Description file:  IPC_MCU.c.tem
 *          Description:  IPC group Dedicated source file
 *               Author:  IPC Code Generator V1.3.0
 *********************************************************************************************************************/
#include "VariantCfg.h"
#include "IPC_Dedicated.h"

#ifdef PLATFORM_OF_STB_IPC_USED
#include "Ipc_STB_If.h"
#endif

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/* MCU or SOC Transmit/Reveive/Pack/Parse  interface */
/* Group: Dedicated */
/* Message Major: SocManager */
/* Transmit function of sub message HandshakeResponse */
int32_t IPC_M2S_DedicatedSocManagerHandshakeResponse_Transmit(IPC_M2S_DedicatedSocManagerHandshakeResponse_t *data)
{
    uint8_t payload[IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD];
    int ret = -1;
    if(data != NULL)
    {
        payload[0] = IPC_GROUP_DEDICATED_ID;
        payload[1] = IPC_M2S_DEDICATED_MSGMAJOR_SOCMANAGER_ID;
        payload[2] = IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_ID;
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                payload[3 + arrIndex * 1] = IPC_GET_BYTE(data->u8Reserved[arrIndex], 0);
            }
        }
        /* Send IPC */
#ifdef PLATFORM_OF_STB_IPC_USED
        ret = IPC_STB_DataSendFormHandshake(payload, IPC_M2S_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKERESPONSE_LENGTH + IPC_TRANSPORT_OVERHEAD ,IPC_PRIORITY_HIGH);
#endif
	}
    return ret;
}

/* Receive function of sub message HandshakeRequest */
void IPC_S2M_DedicatedSocManagerHandshakeRequest_Receive(uint8_t *receiveData, IPC_S2M_DedicatedSocManagerHandshakeRequest_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HANDSHAKEREQUEST_LENGTH == payloadLength))
    {
        {
            uint16_t arrIndex;
            for(arrIndex = 0; arrIndex < 4; arrIndex++)
            {
                IPC_GET_BYTE(data->u8Reserved[arrIndex], 0) = receiveData[0 + arrIndex * 1];
            }
        }
    }

}

/* Receive function of sub message Heath */
void IPC_S2M_DedicatedSocManagerHeath_Receive(uint8_t *receiveData, IPC_S2M_DedicatedSocManagerHeath_t *data, uint32_t payloadLength)
{
    if((receiveData != NULL) && (data != NULL) &&
        (IPC_S2M_DEDICATED_SOCMANAGER_MSGSUB_HEATH_LENGTH == payloadLength))
    {
        IPC_GET_BYTE(data->u8Reserved, 0) = receiveData[0];
    }

}

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"

/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
