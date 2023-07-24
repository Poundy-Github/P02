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
 * @file:      uds.c
 * @author:    Nobo
 * @date:      2020-12-7
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-7
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef UDS_SOURCE
#define UDS_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "stdio.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "IPC_SWUM.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Uds.h"
#include "Uds_Service.h"
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
static UDS_PDU uds_pdu = {0};

#include "Uds_Service_Table.c"

static UDS_PCB uds_pcb = {
    0,
    0,
    NULL_PTR,
    NULL_PTR,
    0,
    {0},
    SessionDefault,
    UDS_E_00_POSITIVERESPONSE};

static uint8 UDS_ACK_BUFFER[0x100]={0};
/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#include "Uds_Service.c"

static EStatus _uds_search_service(const struct UDS_SERVICE **uds_service, uint8 sid, uint32 cnt);
static EStatus _uds_search_subfunc(const struct UDS_SUBFUNC **uds_subfunc, uint8 subid, uint32 cnt);
/**********************************************************************************************************************
 *  void Uds_Init(void)
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
void Uds_Init(void)
{
}

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
static EStatus _uds_search_service(const struct UDS_SERVICE **uds_service, uint8 sid, uint32 cnt)
{
    while (cnt--)
    {
        /* code */
        if ((*uds_service)->sid == sid)
        {
            if (((*uds_service)->len & uds_pdu.len) == uds_pdu.len)
            {
                if (((*uds_service)->session & ((uint8)uds_pcb.session)) == ((uint8)uds_pcb.session))
                {
                    uds_pcb.sid = sid;
                    uds_pcb.service = (*uds_service);
                    return Success;
                }
                else
                {
                    uds_pcb.err = UDS_E_7F_SERVICENOTSUPPORTEDINACTIVESESSION;
                    return Success;
                }
            }
            else
            {
                uds_pcb.err = UDS_E_13_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                return Success;
            }
        }
        (*uds_service)++;
    }
    uds_pcb.err = UDS_E_7E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
    return Success;
}

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
static EStatus _uds_search_subfunc(const struct UDS_SUBFUNC **uds_subfunc, uint8 subid, uint32 cnt)
{
    while (cnt--)
    {
        if ((*uds_subfunc)->subid == subid)
        {
            if (((*uds_subfunc)->rxlen & uds_pdu.len) == uds_pdu.len)
            {
                if (((*uds_subfunc)->session & ((uint8)uds_pcb.session)) == ((uint8)uds_pcb.session))
                {
                    uds_pcb.subid = subid;
                    uds_pcb.subfunc = (*uds_subfunc);
                    return Success;
                }
                else
                {
                    uds_pcb.err = UDS_E_7E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
                    return Success;
                }
            }
            else
            {
                uds_pcb.err = UDS_E_13_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                return Success;
            }
        }
        (*uds_subfunc)++;
    }
    uds_pcb.err = UDS_E_12_SUBFUNCTIONNOTSUPPORTED;
    return Success;
}

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
EStatus uds_tick_PerformService(void)
{
    // MISRA C-2012 Rule 2.2
    // uint8 service_size = 0;
    // uint8 i = 0;
    // Uds_Err err = UDS_E_00_POSITIVERESPONSE;

    const struct UDS_SERVICE *uds_service;
    const struct UDS_SUBFUNC *uds_subfunc;

    EStatus rec = Success;
    if (uds_pdu.busy)
    {
        uds_service = uds_service_table;
        rec = _uds_search_service(&uds_service, uds_pdu.sid, sizeof(uds_service_table) / sizeof(struct UDS_SERVICE));

        if (uds_pcb.err == UDS_E_00_POSITIVERESPONSE)
        {
            if (uds_service->service != NULL_PTR)
            {
                uds_service->service(&uds_pdu, uds_service);
            }
            if (uds_service->sub_cnt > 0)
            {
                uds_subfunc = uds_service->sub;
                rec = _uds_search_subfunc(&uds_subfunc, uds_pdu.data[0], uds_service->sub_cnt);
                if (uds_pcb.err == UDS_E_00_POSITIVERESPONSE)
                {
                    if (uds_subfunc->subid == uds_pdu.data[0])
                    {
                        rec = uds_subfunc->subfunc(&uds_pdu, uds_subfunc);
                    }
                }
            }
        }
        uds_pdu.busy = 2;
    }
    return rec;
}

void Uds_FclErrCbk(uint8 err)
{
}
/**********************************************************************************************************************
 *  void Uds_MainFunction(void)
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
void Uds_MainFunction(void)
{
    uds_tick_PerformService();
    Uds_SendUdsData();
}

/**********************************************************************************************************************
 *  void Uds_PushUdsData(uint8* data, uint32 lenght)
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
void Uds_PushUdsData(uint8 *data, uint32 length)
{
    uint32 i = 0;

    if (uds_pdu.busy == 0)
    {
        uds_pdu.sid = *data++;
        uds_pdu.len = length;

        for (i = 0; i < (length - 1); i++)
        {
            uds_pdu.data[i] = *data++;
        }
        uds_pdu.busy = 1;
    }
}

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
static sint32 Uds_IPC_SendMessage(uint8 *buf, uint16 length)
{
    sint32 ret = 0;
    uint8 i = 0;

    IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t sessionRspMsg;
    IPC_M2S_SWUMSWUM_UDSResponse_t tMsg;

    if (buf[0] == 0x50) /*session control positive response*/
    {
        sessionRspMsg.Service = buf[0];
        sessionRspMsg.SessionType = buf[1];
        ret = IPC_M2S_SWUMSWUM_UDSSessionControlResponse_Transmit(&sessionRspMsg);
    }
    else
    {
        tMsg.SID = buf[0];
        tMsg.ResponseLength = length - 1;
        for (i = 0; i < tMsg.ResponseLength; i++)
        {
            tMsg.Response[i] = buf[i + 1];
        }
        IPC_M2S_SWUMSWUM_UDSResponse_Transmit(&tMsg);
    }
    return ret;
}

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */
void Uds_SendUdsData(void)
{
    uint8 *data = UDS_ACK_BUFFER;
    uint16 len = 0;
    uint8 i = 0;

    // MISRA C-2012 Rule 2.2
    // IPC_M2S_SWUMSWUM_UDSSessionControlResponse_t sessionRspMsg;
    // IPC_M2S_SWUMSWUM_UDSResponse_t tMsg;

    if (uds_pdu.busy == 2)
    {
        uds_pdu.busy = 0;

        switch (uds_pcb.err)
        {
        case UDS_E_00_POSITIVERESPONSE:
            len++, *(data++) = uds_pcb.sid | ((uint8)0x40);
            if (uds_pcb.service->sub_cnt)
            {
                len++, *(data++) = uds_pcb.subid;
            }
            memcpy(data, uds_pcb.txData, uds_pcb.txLen);
            len += uds_pcb.txLen;
			if(uds_pcb.sid!=0x36)
			{
            	(void)upgrade_info("SID :%2x Successful \r\n", uds_pcb.sid);
			}
            break;
        case UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING:
            len++, *(data++) = 0x7f;
            len++, *(data++) = uds_pcb.sid;
            len++, *(data++) = (uint8)UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
            uds_pdu.busy = 1;
            break;
        default:
            (void)upgrade_err("SID :%2x ERROR :%2x\r\n", uds_pcb.sid, uds_pcb.err);
            len++, *(data++) = 0x7f;
            len++, *(data++) = uds_pcb.sid;
            len++, *(data++) = (uint8)uds_pcb.err;
            if (uds_pcb.service->sub_cnt)
            {
                len++, *(data++) = uds_pcb.subid;
            }
            for (i = 0; i < uds_pcb.txLen; i++)
            {
                len++, *(data++) = uds_pcb.txData[i];
            }
            break;
        }

        Uds_IPC_SendMessage(UDS_ACK_BUFFER, len);

        uds_pcb.subid = 0;
        uds_pcb.sid = 0;
        uds_pcb.txLen = 0;
        uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Uds.c
 *********************************************************************************************************************/
#endif //UDS_SOURCE

